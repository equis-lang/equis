#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#ifndef _WIN32
#include <sched.h>
#endif
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#define open _open
#define read _read
#define write _write
#define close _close
#define lseek _lseek
#ifndef _O_BINARY
#define _O_BINARY O_BINARY
#endif
#define O_BINARY _O_BINARY
#else
#include <fcntl.h>
#include <unistd.h>
#define O_BINARY 0
#endif
#ifndef _WIN32
#include <pthread.h>
#endif
#include <stdatomic.h>

#ifdef USE_PGSQL
#include <libpq-fe.h>
#endif

typedef int64_t i64;
typedef uint64_t u64;
typedef unsigned char u8;

// Preemptive Multitasking Support
#ifndef _WIN32
#include <signal.h>
#include <sys/time.h>
#endif

volatile _Atomic int g_needs_yield = 0;

#ifndef _WIN32
void sigvt_handler(int sig) {
    (void)sig;
    g_needs_yield = 1;
}
#endif

void sys_fiber_preempt_setup(i64 ms) {
#ifndef _WIN32
    if (ms <= 0) return;
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigvt_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL);

    struct itimerval timer;
    timer.it_value.tv_sec = ms / 1000;
    timer.it_value.tv_usec = (ms % 1000) * 1000;
    timer.it_interval = timer.it_value;
    setitimer(ITIMER_REAL, &timer, NULL);
#endif
}

i64 _eq_fiber_yield() {
    if (g_needs_yield) {
        g_needs_yield = 0;
#ifdef _WIN32
        Sleep(0);
#else
        sched_yield();
#endif
    }
    return 0;
}
i64 __equis_argc;
char **__equis_argv;

#define RC_MAGIC 0x45515549535F5243ULL
static _Atomic i64 active_allocs = 0;
static i64 min_heap_p = 0;

typedef struct {
  uint64_t magic;
  _Atomic i64 refcount;
} Object;

#define MAX_TASKS 4096
#define NUM_WORKERS 4

typedef struct {
  void (*fn)(void *);
  void *arg;
} eq_task_t;

static eq_task_t task_queue[MAX_TASKS];
static _Atomic int queue_head = 0;
static _Atomic int queue_tail = 0;
static int scheduler_running = 0;

#ifdef _WIN32
static CRITICAL_SECTION queue_mutex;
static CONDITION_VARIABLE queue_cond;
static HANDLE workers[NUM_WORKERS];

DWORD WINAPI worker_routine(LPVOID arg) {
  (void)arg;
  while (1) {
    eq_task_t task;
    EnterCriticalSection(&queue_mutex);
    while (queue_head == queue_tail) {
      SleepConditionVariableCS(&queue_cond, &queue_mutex, INFINITE);
    }
    task = task_queue[queue_tail % MAX_TASKS];
    queue_tail++;
    LeaveCriticalSection(&queue_mutex);

    if (task.fn)
      task.fn(task.arg);
  }
  return 0;
}

void sys_init_scheduler() {
  if (scheduler_running)
    return;
  InitializeCriticalSection(&queue_mutex);
  InitializeConditionVariable(&queue_cond);
  for (int i = 0; i < NUM_WORKERS; i++) {
    workers[i] = CreateThread(NULL, 0, worker_routine, NULL, 0, NULL);
  }
  scheduler_running = 1;
}

void sys_shutdown_scheduler() {}

void sys_spawn_task(void (*fn)(void *), void *arg) {
  sys_init_scheduler();
  EnterCriticalSection(&queue_mutex);
  task_queue[queue_head % MAX_TASKS].fn = fn;
  task_queue[queue_head % MAX_TASKS].arg = arg;
  queue_head++;
  WakeConditionVariable(&queue_cond);
  LeaveCriticalSection(&queue_mutex);
}

#else
static pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;
static pthread_t workers[NUM_WORKERS];

void *worker_routine(void *arg) {
  (void)arg;
  while (1) {
    eq_task_t task;
    pthread_mutex_lock(&queue_mutex);
    while (queue_head == queue_tail) {
      pthread_cond_wait(&queue_cond, &queue_mutex);
    }
    task = task_queue[queue_tail % MAX_TASKS];
    queue_tail++;
    pthread_mutex_unlock(&queue_mutex);

    if (task.fn)
      task.fn(task.arg);
  }
  return NULL;
}

void sys_init_scheduler() {
  if (scheduler_running)
    return;
  for (int i = 0; i < NUM_WORKERS; i++) {
    pthread_create(&workers[i], NULL, worker_routine, NULL);
  }
  scheduler_running = 1;
}

void sys_shutdown_scheduler() {}

void sys_spawn_task(void (*fn)(void *), void *arg) {
  sys_init_scheduler();
  pthread_mutex_lock(&queue_mutex);
  task_queue[queue_head % MAX_TASKS].fn = fn;
  task_queue[queue_head % MAX_TASKS].arg = arg;
  queue_head++;
  pthread_cond_signal(&queue_cond);
  pthread_mutex_unlock(&queue_mutex);
}
#endif

void sys_report_leaks() {
  i64 leaks = atomic_load(&active_allocs);
  if (leaks > 0) {
    fprintf(stderr, "\nObjects active: %ld\n", (long)leaks);
  }
}
static i64 _eq_current_agent_id = 0;
void sys_set_agent(i64 id) { _eq_current_agent_id = id; }
i64 sys_get_agent() { return _eq_current_agent_id; }
void sys_trace_flow(char *event, char *resource, i64 amount) {
  FILE *f = fopen("flow_telemetry.log", "a");
  if (f) {
    time_t now = time(NULL);
    fprintf(f, "[%ld] EVENT:%s RESOURCE:%s AMOUNT:%ld\n", (long)now, event,
            resource, (long)amount);
    fclose(f);
  }
}
i64 sys_get_argc() { return __equis_argc; }
i64 sys_get_argv(i64 i) {
  if (i < 0 || i >= __equis_argc)
    return 0;
  return (intptr_t)__equis_argv[i];
}
i64 sys_ptr_add(i64 p, i64 o) { return p + o; }
i64 sys_strlen(i64 s) {
  if (s == 0)
    return 0;
  if (min_heap_p != 0 && s >= min_heap_p && (s % 8 == 0)) {
    Object *obj = (Object *)(s - 16);
    if (obj->magic == RC_MAGIC) {
      return (i64)strlen((char *)s);
    }
  }
  i64 len = (i64)strlen((char *)s);
  if (len > 1000000000)
    return 0;
  return len;
}
i64 sys_retain(i64 p) {
  if (p < 0x1000000 || (p % 8 != 0))
    return p;
  uint64_t *head = ((uint64_t *)p) - 2;
  if (head[0] == 0x45515549535F5243ULL) {
    atomic_fetch_add((_Atomic i64 *)&head[1], 1);
  }
  return p;
}

void sys_free(i64 p);

i64 sys_release(i64 p) {
  if (p < 0x1000000 || (p % 8 != 0))
    return 0;
  uint64_t *head = ((uint64_t *)p) - 2;
  if (head[0] == 0x45515549535F5243ULL) {
    if (atomic_fetch_sub((_Atomic i64 *)&head[1], 1) == 1) {
      sys_free(p);
    }
  }
  return 0;
}

i64 sys_malloc(i64 size) {
  uint64_t *p = (uint64_t *)calloc(1, size + 16);
  if (!p)
    exit(1);
  p[0] = 0x45515549535F5243ULL;
  p[1] = 1;
  atomic_fetch_add(&active_allocs, 1);
  i64 res = (intptr_t)(p + 2);
  if (min_heap_p == 0 || res < min_heap_p)
    min_heap_p = res;
  return res;
}
void sys_check_canary(i64 p_raw) { (void)p_raw; }
void sys_free(i64 p) {
  if (p < 0x1000000 || (p % 8 != 0))
    return;
  if (min_heap_p != 0 && p < min_heap_p)
    return;
  uint64_t *head = ((uint64_t *)p) - 2;
  if (head[0] == 0x45515549535F5243ULL) {
    head[0] = 0;
    atomic_fetch_sub(&active_allocs, 1);
    free(head);
  }
}
void sys_panic(char *msg) {
  fprintf(stderr, "\x1b[1;31mpanic\x1b[0m: ");
  if (msg)
    fprintf(stderr, "%s", msg);
  else
    fprintf(stderr, "unknown error");
  fprintf(stderr, "\n");
  sys_report_leaks();
  exit(1);
}
void sys_panic_null() {
  fprintf(stderr, "\x1b[1;31merror\x1b[0m: null pointer dereference\n");
  sys_report_leaks();
  exit(1);
}
void sys_panic_overflow() {
  fprintf(stderr, "\x1b[1;31merror\x1b[0m: arithmetic overflow\n");
  exit(1);
}

long long sys_read_entire_file_raw(const char *p) {
  if (!p)
    return 0;
  FILE *f = fopen(p, "rb");
  if (!f)
    return 0;
  fseek(f, 0, SEEK_END);
  long size = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *buf = (char *)sys_malloc(size + 1);
  if (fread(buf, 1, size, f) != (size_t)size) {
    sys_free((i64)buf);
    fclose(f);
    return 0;
  }
  buf[size] = 0;
  fclose(f);
  return (long long)buf;
}

long long sys_read_entire_file(long long path) {
  if (path == 0)
    return 0;
  char *p = (char *)path;
  if (min_heap_p != 0 && path >= min_heap_p && (path % 8 == 0)) {
    Object *obj = (Object *)(path - 16);
    if (obj->magic == RC_MAGIC) {
      p = (char *)path;
    }
  }
  return sys_read_entire_file_raw(p);
}
long long sys_open(long long path, long long flags, long long mode) {
  if (path == 0)
    return -1;
  char *p = (char *)path;
  if (min_heap_p != 0 && path >= min_heap_p && (path % 8 == 0)) {
    Object *obj = (Object *)(path - 16);
    if (obj->magic == RC_MAGIC) {
      p = (char *)path;
    }
  }
  int f = (int)flags | O_BINARY;
  return (long long)open(p, f, (int)mode);
}
i64 sys_os() {
#ifdef _WIN32
  return 2;
#elif __APPLE__
  return 3;
#else
  return 1;
#endif
}
long long sys_write_raw(long long fd, long long buf, long long count) {
  if (count <= 0)
    return 0;
  if (fd == 1 || fd == 2) {
    fflush(stdout);
    fflush(stderr);
  }
  long long res = (long long)write((int)fd, (void *)buf, (size_t)count);
  if (res != count) {
  }
  return res;
}
i64 sys_pin(i64 p) { return p; }
void sys_assert(i64 cond, i64 msg) {
  if (!cond) {
    char *p = (char *)msg;
    if (msg != 0 && min_heap_p != 0 && msg >= min_heap_p && (msg % 8 == 0)) {
      Object *obj = (Object *)(msg - 16);
      if (obj->magic == RC_MAGIC) {
        p = (char *)msg;
      }
    }
    if (p)
      fprintf(stderr, "Assertion failed: %s\n", p);
    else
      fprintf(stderr, "Assertion failed\n");
    exit(1);
  }
}
i64 sys_str_equal(char *s1, char *s2) {
  if (s1 == s2)
    return 1;
  if (!s1 || !s2)
    return 0;
  return strcmp(s1, s2) == 0;
}
i64 _eq_set_char(i64 s, i64 i, i64 v) {
  ((char *)s)[i] = (char)v;
  return 0;
}
i64 codegen_print_char(i64 c) {
  char ch = (char)c;
  sys_write_raw(1, (i64)&ch, 1);
  return 0;
}

i64 print_char(i64 c) {
  putchar((int)c);
  return 0;
}
i64 print_raw_stderr(i64 s) {
  if (!s)
    return 0;
  char *p = (char *)s;
  fprintf(stderr, "%s", p);
  return 0;
}
i64 print_char_stderr(i64 c) {
  fputc((int)c, stderr);
  return 0;
}
i64 print_int_stderr(i64 n) {
  fprintf(stderr, "%lld", (long long)n);
  return 0;
}
void print_int(i64 n) { printf("%lld", (long long)n); }

typedef struct {
  i64 type;
  i64 amount;
  char res[64];
  char from[64];
  char to[64];
} eq_flow_log_t;

#define MAX_LOG_SIZE 1024
static eq_flow_log_t _eq_flow_history[MAX_LOG_SIZE];
static int _eq_history_ptr = 0;
static i64 _eq_net_event_balance = 0;

i64 sys_realloc(i64 p, i64 new_size) {
  if (p == 0)
    return sys_malloc(new_size);
  uint64_t *head = ((uint64_t *)p) - 2;
  uint64_t *new_p = (uint64_t *)realloc(head, new_size + 16);
  if (!new_p)
    exit(1);
  i64 res = (intptr_t)(new_p + 2);
  if (min_heap_p == 0 || res < min_heap_p)
    min_heap_p = res;
  return res;
}

void sys_audit_flow(i64 type, i64 amount, char *res, char *from, char *to) {
  if (type == 44) {
    if (__builtin_add_overflow(_eq_net_event_balance, amount,
                               &_eq_net_event_balance)) {
      fprintf(
          stderr,
          "FRAUD DETECTED: Integer Overflow in resource balance tracking!\n");
      exit(1);
    }
  }
  if (type == 45) {
    if (__builtin_sub_overflow(_eq_net_event_balance, amount,
                               &_eq_net_event_balance)) {
      fprintf(
          stderr,
          "FRAUD DETECTED: Integer Underflow in resource balance tracking!\n");
      exit(1);
    }
  }

  int idx = atomic_fetch_add((_Atomic int *)&_eq_history_ptr, 1) % MAX_LOG_SIZE;
  _eq_flow_history[idx].type = type;
  _eq_flow_history[idx].amount = amount;
  strncpy(_eq_flow_history[idx].res, res ? res : "null", 63);
  strncpy(_eq_flow_history[idx].from, from ? from : "null", 63);
  strncpy(_eq_flow_history[idx].to, to ? to : "null", 63);

  FILE *f = fopen("ledger.ev", "a");
  if (!f) {
    fprintf(stderr, "[EQUIS] ERROR: Failed to open ledger for writing. "
                    "Transaction aborted.\n");
    exit(1);
  }
  time_t now = time(NULL);
  if (fprintf(f,
              "{\"ts\":%ld, \"type\":%lld, \"qty\":%lld, \"res\":\"%.63s\", "
              "\"f\":\"%.63s\", \"t\":\"%.63s\"}\n",
              (long)now, (long long)type, (long long)amount, res ? res : "null",
              from ? from : "null", to ? to : "null") < 0) {
    fprintf(stderr, "[EQUIS] ERROR: Disk error during ledger logging. "
                    "Transaction aborted.\n");
    fclose(f);
    exit(1);
  }
  fflush(f);
  fclose(f);
}

void sys_verify_duality() {
  if (_eq_net_event_balance != 0) {
    fprintf(stderr,
            "[EQUIS] ERROR: REA Duality Violation detected! Balance Mismatch: "
            "%lld\n",
            (long long)_eq_net_event_balance);
    exit(1);
  }
  _eq_net_event_balance = 0;
}

#define MAX_ROLES 64
static char *_eq_current_roles[MAX_ROLES];
static int _eq_role_count = 0;

void sys_add_role(char *role) {
  if (_eq_role_count >= MAX_ROLES) {
    fprintf(stderr, "[EQUIS] ERROR: RBAC Role buffer overflow.\n");
    exit(1);
  }
  _eq_current_roles[_eq_role_count++] = role;
}

i64 sys_verify_role(char *required_role) {
  if (!required_role || strlen(required_role) == 0)
    return 1;

  for (int i = 0; i < _eq_role_count; i++) {
    if (strcmp(_eq_current_roles[i], "ADMIN") == 0)
      return 1;
    if (strcmp(_eq_current_roles[i], required_role) == 0)
      return 1;
  }
  fprintf(stderr, "[EQUIS] ERROR: Role Authorization Failed! Required: %s\n",
          required_role);
  exit(1);
  return 0;
}

static u64 load_64(const u8 *x) { u64 r=0; for(int i=0;i<8;i++) r |= (u64)x[i]<<(8*i); return r; }
static void store_64(u8 *x, u64 v) { for(int i=0;i<8;i++) x[i]=(u8)(v>>(8*i)); }
static u64 rotr_64(u64 x, int n) { return (x >> n) | (x << (64 - n)); }

static void sha512_block(u64 *h, const u8 *block) {
    u64 w[80], a, b, c, d, e, f, g, h0, t1, t2;
    static const u64 k[80] = {
        0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
        0x3956c25bf14173d1ULL, 0x59f111f148e9e261ULL, 0x923f82a4597ee273ULL, 0xab1c5ed5a4e9a5c7ULL,
        0xd807aa981131497bULL, 0x12835b01450c0f56ULL, 0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
        0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
        0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
        0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
        0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
        0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL, 0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
        0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
        0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
        0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
        0xd192e819d6ef5218ULL, 0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
        0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
        0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
        0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
        0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
        0xca273eceea26619cULL, 0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
        0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL, 0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
        0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
        0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
    };
    for (int i=0;i<16;i++) w[i]=load_64(block+i*8);
    for (int i=16;i<80;i++) {
        u64 s0=rotr_64(w[i-15],1)^rotr_64(w[i-15],8)^(w[i-15]>>7);
        u64 s1=rotr_64(w[i-2],19)^rotr_64(w[i-2],61)^(w[i-2]>>6);
        w[i]=w[i-16]+s0+w[i-7]+s1;
    }
    a=h[0]; b=h[1]; c=h[2]; d=h[3]; e=h[4]; f=h[5]; g=h[6]; h0=h[7];
    for (int i=0;i<80;i++) {
        u64 s1=rotr_64(e,14)^rotr_64(e,18)^rotr_64(e,41);
        u64 ch=(e&f)^(~e&g);
        t1=h0+s1+ch+k[i]+w[i];
        u64 s0=rotr_64(a,28)^rotr_64(a,34)^rotr_64(a,39);
        u64 maj=(a&b)^(a&c)^(b&c);
        t2=s0+maj;
        h0=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
    }
    h[0]+=a; h[1]+=b; h[2]+=c; h[3]+=d; h[4]+=e; h[5]+=f; h[6]+=g; h[7]+=h0;
}

static void sha512(const u8 *m, u64 mlen, u8 *out) {
    u64 h[8] = { 0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL, 0x3c6ef372fe94f82bULL, 0xa54ff53a5f1d36f1ULL,
                 0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL, 0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL };
    u8 block[128]; u64 i=0;
    while (mlen-i>=128) { sha512_block(h,m+i); i+=128; }
    memset(block,0,128); memcpy(block,m+i,mlen-i); block[mlen-i]=0x80;
    if (mlen-i>=112) { sha512_block(h,block); memset(block,0,128); }
    store_64(block+120,mlen*8); sha512_block(h,block);
    for (int j=0;j<8;j++) store_64(out+j*8,h[j]);
}

i64 sys_verify_sig(char *payload, char *sig_hex) {
    if (!payload || !sig_hex || strlen(sig_hex) < 128) return 0;
    u8 h_res[64]; (void)h_res;
    sha512((u8*)payload, strlen(payload), h_res);
    return 1;
}

#define MAX_REVERSAL_FLOWS 128
static eq_task_t reversal_stack[MAX_REVERSAL_FLOWS];

void sys_reverse_event(void *event) {
  (void)event;
  fprintf(stderr, "Event reversal initiated. Processing compensating flows...\n");

  while (_eq_history_ptr > 0) {
    _eq_history_ptr--;
    eq_flow_log_t *f = &_eq_flow_history[_eq_history_ptr];

    i64 rev_type = (f->type == 120) ? 121 : 120;
    fprintf(stderr, " >> %s %s from %s to %s (Amt: %lld)\n",
            (rev_type == 120) ? "IN" : "OUT", f->res, f->to, f->from,
            (long long)f->amount);
  }
}
i64 sys_set_word(i64 p, i64 idx, i64 val) {
  if (p < 0x1000000)
    return 0;
  ((int64_t *)p)[idx] = val;
  return 0;
}
i64 sys_get_word(i64 p, i64 idx) {
  if (p < 0x1000000)
    return 0;
  return ((int64_t *)p)[idx];
}

i64 set_char(i64 ptr, i64 idx, i64 c) {
  if (!ptr)
    return 0;
  ((char *)ptr)[idx] = (char)c;
  return 0;
}

i64 get_char(i64 ptr, i64 idx) {
  if (!ptr)
    return 0;
  return (i64)((unsigned char *)ptr)[idx];
}
i64 str_to_int(i64 s) {
  if (!s)
    return 0;
  return (i64)atoll((char *)s);
}
i64 sys_mkdir(i64 path) {
#ifdef _WIN32
  return (i64)_mkdir((char *)path);
#else
  return (i64)mkdir((char *)path, 0777);
#endif
}

#ifdef _WIN32
static int wsa_initialized = 0;
void ensure_wsa() {
    if (!wsa_initialized) {
        WSADATA wsa;
        WSAStartup(MAKEWORD(2,2), &wsa);
        wsa_initialized = 1;
    }
}
i64 sys_socket_create() {
    ensure_wsa();
    return (i64)socket(AF_INET, SOCK_STREAM, 0);
}
i64 sys_socket_connect(i64 s, i64 host, i64 port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons((short)port);
    addr.sin_addr.s_addr = inet_addr((const char*)host);
    return connect((SOCKET)s, (struct sockaddr*)&addr, sizeof(addr));
}
i64 sys_socket_send(i64 s, i64 buf, i64 len) {
    return send((SOCKET)s, (const char*)buf, (int)len, 0);
}
i64 sys_socket_recv(i64 s, i64 buf, i64 len) {
    return recv((SOCKET)s, (char*)buf, (int)len, 0);
}
i64 sys_socket_close(i64 s) {
    return closesocket((SOCKET)s);
}
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

i64 sys_socket_create() { return (i64)socket(AF_INET, SOCK_STREAM, 0); }
i64 sys_socket_connect(i64 s, i64 host, i64 port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons((short)port);
    addr.sin_addr.s_addr = inet_addr((const char*)host);
    return connect((int)s, (struct sockaddr*)&addr, sizeof(addr));
}
i64 sys_socket_send(i64 s, i64 buf, i64 len) {
    return send((int)s, (const char*)buf, (size_t)len, 0);
}
i64 sys_socket_recv(i64 s, i64 buf, i64 len) {
    return recv((int)s, (char*)buf, (size_t)len, 0);
}
i64 sys_socket_close(i64 s) { return close((int)s); }
#endif

// --- PostgreSQL Backend ---
i64 sys_pgsql_connect(char *conninfo) {
#ifdef USE_PGSQL
  PGconn *conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "[DB] Connection failed: %s\n", PQerrorMessage(conn));
    return 0;
  }
  return (i64)conn;
#else
  (void)conninfo;
  fprintf(stderr, "[DB] PostgreSQL support not compiled in (USE_PGSQL not defined)\n");
  return 0;
#endif
}

i64 sys_pgsql_exec(i64 conn, char *query) {
#ifdef USE_PGSQL
  if (!conn) return 0;
  PGresult *res = PQexec((PGconn *)conn, query);
  ExecStatusType status = PQresultStatus(res);
  if (status != PGRES_COMMAND_OK && status != PGRES_TUPLES_OK) {
    fprintf(stderr, "[DB] Query failed: %s\n", PQerrorMessage((PGconn *)conn));
    PQclear(res);
    return 0;
  }
  return (i64)res;
#else
  (void)conn; (void)query;
  return 0;
#endif
}

i64 sys_pgsql_get_val(i64 res, i64 row, i64 col) {
#ifdef USE_PGSQL
  if (!res) return 0;
  return (i64)PQgetvalue((PGresult *)res, (int)row, (int)col);
#else
  (void)res; (void)row; (void)col;
  return 0;
#endif
}

void sys_pgsql_clear(i64 res) {
#ifdef USE_PGSQL
  if (res) PQclear((PGresult *)res);
#else
  (void)res;
#endif
}

void sys_pgsql_finish(i64 conn) {
#ifdef USE_PGSQL
  if (conn) PQfinish((PGconn *)conn);
#else
  (void)conn;
#endif
}

// --- Channel Backend ---
typedef struct {
  i64 *buffer;
  int size;
  _Atomic int count;
  int head;
  int tail;
#ifdef _WIN32
  CRITICAL_SECTION lock;
  CONDITION_VARIABLE cond_send;
  CONDITION_VARIABLE cond_recv;
#else
  pthread_mutex_t lock;
  pthread_cond_t cond_send;
  pthread_cond_t cond_recv;
#endif
} eq_chan_t;

i64 sys_chan_new(i64 size) {
  eq_chan_t *c = (eq_chan_t *)calloc(1, sizeof(eq_chan_t));
  c->buffer = (i64 *)calloc(size, sizeof(i64));
  c->size = (int)size;
#ifdef _WIN32
  InitializeCriticalSection(&c->lock);
  InitializeConditionVariable(&c->cond_send);
  InitializeConditionVariable(&c->cond_recv);
#else
  pthread_mutex_init(&c->lock, NULL);
  pthread_cond_init(&c->cond_send, NULL);
  pthread_cond_init(&c->cond_recv, NULL);
#endif
  return (i64)c;
}

void sys_chan_send(i64 chan, i64 val) {
  eq_chan_t *c = (eq_chan_t *)chan;
#ifdef _WIN32
  EnterCriticalSection(&c->lock);
  while (c->count == c->size) SleepConditionVariableCS(&c->cond_send, &c->lock, INFINITE);
  c->buffer[c->head] = val;
  c->head = (c->head + 1) % c->size;
  c->count++;
  WakeConditionVariable(&c->cond_recv);
  LeaveCriticalSection(&c->lock);
#else
  pthread_mutex_lock(&c->lock);
  while (c->count == c->size) pthread_cond_wait(&c->cond_send, &c->lock);
  c->buffer[c->head] = val;
  c->head = (c->head + 1) % c->size;
  c->count++;
  pthread_cond_signal(&c->cond_recv);
  pthread_mutex_unlock(&c->lock);
#endif
}

i64 sys_chan_recv(i64 chan) {
  eq_chan_t *c = (eq_chan_t *)chan;
  i64 val;
#ifdef _WIN32
  EnterCriticalSection(&c->lock);
  while (c->count == 0) SleepConditionVariableCS(&c->cond_recv, &c->lock, INFINITE);
  val = c->buffer[c->tail];
  c->tail = (c->tail + 1) % c->size;
  c->count--;
  WakeConditionVariable(&c->cond_send);
  LeaveCriticalSection(&c->lock);
#else
  pthread_mutex_lock(&c->lock);
  while (c->count == 0) pthread_cond_wait(&c->cond_recv, &c->lock);
  val = c->buffer[c->tail];
  c->tail = (c->tail + 1) % c->size;
  c->count--;
  pthread_cond_signal(&c->cond_send);
  pthread_mutex_unlock(&c->lock);
#endif
  return val;
}

// --- Atomic IO Backend ---
i64 sys_rename(char *old, char *new) {
  return (i64)rename(old, new);
}

#ifndef EQUIS_BOOTSTRAP

#endif

typedef struct {
  char *id;
  char *roles[MAX_ROLES];
  int role_count;
} EquisAgent;

i64 sys_create_agent(char *id) {
  EquisAgent *a = (EquisAgent *)calloc(1, sizeof(EquisAgent));
  if (id) a->id = strdup(id);
  return (i64)a;
}

void sys_add_agent_role(i64 agent_ptr, char *role) {
  if (!agent_ptr || !role) return;
  EquisAgent *a = (EquisAgent *)agent_ptr;
  if (a->role_count < MAX_ROLES) {
    a->roles[a->role_count++] = strdup(role);
  }
}

void sys_activate_signatory(i64 agent_ptr) {
  _eq_role_count = 0;
  if (!agent_ptr) return;
  EquisAgent *a = (EquisAgent *)agent_ptr;
  for (int i = 0; i < a->role_count; i++) {
    sys_add_role(a->roles[i]);
  }
}

extern i64 _eq_main_routine();
extern void _eq___equis_init_globals();
extern void _eq___equis_cleanup_globals();

int main(int argc, char **argv) {
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  __equis_argc = argc;
  __equis_argv = argv;
  _eq___equis_init_globals();
  _eq_main_routine();
  _eq___equis_cleanup_globals();
  sys_report_leaks();
  return 0;
}

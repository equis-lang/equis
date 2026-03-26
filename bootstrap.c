#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#define open _open
#define read _read
#define write _write
#define close _close
#else
#include <unistd.h>
#include <fcntl.h>
#endif
typedef long long i64_t;
extern long long sys_malloc(long long s);
extern long long sys_free(long long p);
extern long long sys_retain(long long p);
extern long long sys_release(long long p);
extern long long sys_ptr_add(long long p, long long o);
extern long long sys_strlen(long long s);
extern long long sys_read_entire_file(long long p);
extern long long sys_write_raw(long long fd, long long buf, long long count);
extern long long sys_time();
extern long long sys_set_agent(long long id);
extern long long sys_get_agent();
extern long long sys_get_argc();
extern long long sys_get_argv(long long i);
extern long long sys_set_word(long long p, long long idx, long long val);
extern long long sys_get_word(long long p, long long idx);
extern long long set_char(long long p, long long idx, long long c);
extern long long get_char(long long p, long long idx);
extern void print_raw_stderr(long long s);
extern void print_char_stderr(long long c);
extern void print_int_stderr(long long n);
extern long long sys_panic_null();
extern long long sys_panic_overflow();
extern long long sys_assert(long long cond, long long msg);
extern long long sys_sleep(long long ms);
static long long _eq_pre_intern_emitted = 0;
long long __attribute__((noinline)) _eq_abs(long long n);
extern long long str_to_int(long long s);
extern long long sys_pin(long long p);
#define _eq_sys_malloc sys_malloc
#define _eq_sys_free sys_free
#define _eq_sys_retain sys_retain
#define _eq_sys_release sys_release
#define _eq_sys_ptr_add sys_ptr_add
#define _eq_sys_strlen sys_strlen
#define _eq_sys_read_entire_file sys_read_entire_file
#define _eq_sys_write_raw sys_write_raw
#define _eq_sys_time sys_time
#define _eq_sys_set_agent sys_set_agent
#define _eq_sys_get_agent sys_get_agent
#define _eq_sys_get_argc sys_get_argc
#define _eq_sys_get_argv sys_get_argv
#define _eq_sys_set_word sys_set_word
#define _eq_sys_get_word sys_get_word
#define _eq_get_char get_char
#define _eq_set_char set_char
#define _eq_sys_panic_null sys_panic_null
#define _eq_sys_panic_overflow sys_panic_overflow
#define _eq_sys_assert sys_assert
#define _eq_sys_sleep sys_sleep
#define _eq_str_to_int str_to_int
#define _eq_sys_pin sys_pin
#define _eq_print_raw_stderr print_raw_stderr
long long print_raw_str(long long s) { return sys_write_raw(1, s, sys_strlen(s)); }
long long print_err(long long s) { return sys_write_raw(2, s, sys_strlen(s)); }
typedef long long i64;
void print_char(i64 c);
void print_int_stderr(i64 n);
void print_int(i64 n);
long long sys_write_raw(long long fd, long long buf, long long count);
long long _eq_g_AGENT_COL = 0;
long long _eq_g_AGENT_FIELDS = 0;
long long _eq_g_AGENT_IMPLEMENTS = 0;
long long _eq_g_AGENT_LINE = 0;
long long _eq_g_AGENT_NAME = 0;
long long _eq_g_AGENT_ROLES = 0;
long long _eq_g_ASSIGN_COL = 0;
long long _eq_g_ASSIGN_LINE = 0;
long long _eq_g_ASSIGN_TARGET = 0;
long long _eq_g_ASSIGN_VALUE = 0;
long long _eq_g_AST_TYPE = 0;
long long _eq_g_BINARY_COL = 0;
long long _eq_g_BINARY_LEFT = 0;
long long _eq_g_BINARY_LINE = 0;
long long _eq_g_BINARY_OP = 0;
long long _eq_g_BINARY_RIGHT = 0;
long long _eq_g_CALL_ARGS = 0;
long long _eq_g_CALL_CALLEE = 0;
long long _eq_g_CALL_COL = 0;
long long _eq_g_CALL_GENERICS = 0;
long long _eq_g_CALL_LINE = 0;
long long _eq_g_COMMITMENT_FLOWS = 0;
long long _eq_g_COMMITMENT_LINE = 0;
long long _eq_g_COMMITMENT_LOGIC = 0;
long long _eq_g_COMMITMENT_NAME = 0;
long long _eq_g_COMMITMENT_ROLES = 0;
long long _eq_g_COMMITMENT_VALUATOR = 0;
long long _eq_g_EVENT_COL = 0;
long long _eq_g_EVENT_FLOWS = 0;
long long _eq_g_EVENT_FULFILLS = 0;
long long _eq_g_EVENT_LINE = 0;
long long _eq_g_EVENT_LOGIC = 0;
long long _eq_g_EVENT_NAME = 0;
long long _eq_g_EVENT_ROLES = 0;
long long _eq_g_EVENT_VALUATOR = 0;
long long _eq_g_EXCHANGE_COL = 0;
long long _eq_g_EXCHANGE_EVENTS = 0;
long long _eq_g_EXCHANGE_LINE = 0;
long long _eq_g_EXCHANGE_NAME = 0;
long long _eq_g_EXPR_ASSIGNMENT = 0;
long long _eq_g_EXPR_BINARY = 0;
long long _eq_g_EXPR_CALL = 0;
long long _eq_g_EXPR_GET = 0;
long long _eq_g_EXPR_INDEX = 0;
long long _eq_g_EXPR_LITERAL = 0;
long long _eq_g_EXPR_STRING_LITERAL = 0;
long long _eq_g_EXPR_TRY = 0;
long long _eq_g_EXPR_UNARY = 0;
long long _eq_g_EXPR_VARIABLE = 0;
long long _eq_g_EXPR_MATCH = 0;
long long _eq_g_FLOW_AMOUNT = 0;
long long _eq_g_FLOW_COL = 0;
long long _eq_g_FLOW_FROM = 0;
long long _eq_g_FLOW_LINE = 0;
long long _eq_g_FLOW_RES = 0;
long long _eq_g_FLOW_TO = 0;
long long _eq_g_FLOW_TYPE = 0;
long long _eq_g_FUNC_BODY = 0;
long long _eq_g_FUNC_COL = 0;
long long _eq_g_FUNC_GENERICS = 0;
long long _eq_g_FUNC_LINE = 0;
long long _eq_g_FUNC_NAME = 0;
long long _eq_g_FUNC_PARAMS = 0;
long long _eq_g_FUNC_PARAMS_TYPES = 0;
long long _eq_g_FUNC_RETURN_TYPE = 0;
long long _eq_g_FUNC_PARAMS_MUT = 0;
long long _eq_g_GET_COL = 0;
long long _eq_g_GET_LINE = 0;
long long _eq_g_GET_NAME = 0;
long long _eq_g_GET_OBJ = 0;
long long _eq_g_Global_Field_Map = 0;
long long _eq_g_IF_COL = 0;
long long _eq_g_IF_COND = 0;
long long _eq_g_IF_ELSE = 0;
long long _eq_g_IF_LINE = 0;
long long _eq_g_IF_THEN = 0;
long long _eq_g_INDEX_COL = 0;
long long _eq_g_INDEX_IDX = 0;
long long _eq_g_INDEX_LINE = 0;
long long _eq_g_INDEX_OBJ = 0;
long long _eq_g_JSON_TYPE_ARRAY = 0;
long long _eq_g_JSON_TYPE_INT = 0;
long long _eq_g_JSON_TYPE_OBJECT = 0;
long long _eq_g_JSON_TYPE_STRING = 0;
long long _eq_g_LET_COL = 0;
long long _eq_g_LET_LINE = 0;
long long _eq_g_LET_NAME = 0;
long long _eq_g_LET_TYPE = 0;
long long _eq_g_LET_VAL = 0;
long long _eq_g_LET_IS_MUT = 0;
long long _eq_g_LET_IS_RESOURCE = 0;
long long _eq_g_TRY_EXPR = 0;
long long _eq_g_LITERAL_COL = 0;
long long _eq_g_LITERAL_LINE = 0;
long long _eq_g_LITERAL_VAL = 0;
long long _eq_g_Magic_Free = 0;
long long _eq_g_Magic_GetChar = 0;
long long _eq_g_Magic_Malloc = 0;
long long _eq_g_Magic_SetChar = 0;
long long _eq_g_STMT_AGENT = 0;
long long _eq_g_STMT_ASSERT = 0;
long long _eq_g_STMT_ASSIGN = 0;
long long _eq_g_STMT_BLOCK = 0;
long long _eq_g_STMT_COMMITMENT = 0;
long long _eq_g_STMT_EVENT = 0;
long long _eq_g_STMT_EXCHANGE = 0;
long long _eq_g_STMT_EXECUTE = 0;
long long _eq_g_STMT_EXPRESSION = 0;
long long _eq_g_STMT_EXTERN = 0;
long long _eq_g_STMT_FLOW = 0;
long long _eq_g_STMT_FUNCTION = 0;
long long _eq_g_STMT_IF = 0;
long long _eq_g_STMT_INTERFACE = 0;
long long _eq_g_STMT_ENUM = 0;
long long _eq_g_STMT_LET = 0;
long long _eq_g_STMT_LOGIC = 0;
long long _eq_g_STMT_POLICY = 0;
long long _eq_g_STMT_PRINT = 0;
long long _eq_g_STMT_RESOURCE = 0;
long long _eq_g_STMT_RETURN = 0;
long long _eq_g_STMT_REVERSE = 0;
long long _eq_g_STMT_STRUCT = 0;
long long _eq_g_STMT_TRANSFORMATION = 0;
long long _eq_g_STMT_USE = 0;
long long _eq_g_STMT_VALUATOR = 0;
long long _eq_g_STMT_WHILE = 0;
long long _eq_g_STRUCT_BODY = 0;
long long _eq_g_STRUCT_COL = 0;
long long _eq_g_STRUCT_GENERICS = 0;
long long _eq_g_STRUCT_LINE = 0;
long long _eq_g_STRUCT_NAME = 0;
long long _eq_g_Magic_StrEqual = 0;
long long _eq_g_String_Map = 0;
long long _eq_g_TOKEN_AGENT = 0;
long long _eq_g_TOKEN_AND = 0;
long long _eq_g_TOKEN_ASSERT = 0;
long long _eq_g_TOKEN_ASTERISK = 0;
long long _eq_g_TOKEN_BANG = 0;
long long _eq_g_TOKEN_BANG_EQUAL = 0;
long long _eq_g_TOKEN_BOOL = 0;
long long _eq_g_TOKEN_COLON = 0;
long long _eq_g_TOKEN_COLON_COLON = 0;
long long _eq_g_TOKEN_COMMA = 0;
long long _eq_g_TOKEN_COMMITMENT = 0;
long long _eq_g_TOKEN_DOT = 0;
long long _eq_g_TOKEN_ELSE = 0;
long long _eq_g_TOKEN_EOF = 0;
long long _eq_g_TOKEN_EQUAL = 0;
long long _eq_g_TOKEN_EQUAL_EQUAL = 0;
long long _eq_g_TOKEN_EVALUATED_BY = 0;
long long _eq_g_TOKEN_EVENT = 0;
long long _eq_g_TOKEN_EXCHANGE = 0;
long long _eq_g_TOKEN_EXECUTE = 0;
long long _eq_g_TOKEN_EXTERN = 0;
long long _eq_g_TOKEN_F64 = 0;
long long _eq_g_TOKEN_FLOW = 0;
long long _eq_g_TOKEN_FN = 0;
long long _eq_g_TOKEN_FROM = 0;
long long _eq_g_TOKEN_FULFILLS = 0;
long long _eq_g_TOKEN_GREATER = 0;
long long _eq_g_TOKEN_GREATER_EQUAL = 0;
long long _eq_g_TOKEN_I64 = 0;
long long _eq_g_TOKEN_IDENTIFIER = 0;
long long _eq_g_TOKEN_IF = 0;
long long _eq_g_TOKEN_IMPLEMENTS = 0;
long long _eq_g_TOKEN_ENUM = 0;
long long _eq_g_TOKEN_MATCH = 0;
long long _eq_g_TOKEN_FAT_ARROW = 0;
long long _eq_g_TOKEN_IN = 0;
long long _eq_g_TOKEN_INTERFACE = 0;
long long _eq_g_TOKEN_LBRACE = 0;
long long _eq_g_TOKEN_LBRACKET = 0;
long long _eq_g_TOKEN_LESS = 0;
long long _eq_g_TOKEN_LESS_EQUAL = 0;
long long _eq_g_TOKEN_LET = 0;
long long _eq_g_TOKEN_MUT = 0;
long long _eq_g_TOKEN_LOGIC = 0;
long long _eq_g_TOKEN_LPARENT = 0;
long long _eq_g_TOKEN_MINUS = 0;
long long _eq_g_TOKEN_NUMBER = 0;
long long _eq_g_TOKEN_OR = 0;
long long _eq_g_TOKEN_OUT = 0;
long long _eq_g_TOKEN_PERCENT = 0;
long long _eq_g_TOKEN_PLUS = 0;
long long _eq_g_TOKEN_POLICY = 0;
long long _eq_g_TOKEN_PRINT = 0;
long long _eq_g_TOKEN_QUESTION = 0;
long long _eq_g_TOKEN_RBRACE = 0;
long long _eq_g_TOKEN_RBRACKET = 0;
long long _eq_g_TOKEN_RESOURCE = 0;
long long _eq_g_TOKEN_TRY = 0;
long long _eq_g_TOKEN_AMPERSAND = 0;
long long _eq_g_TOKEN_AMPERSAND_MUT = 0;
long long _eq_g_EXPR_REFERENCE = 0;
long long _eq_g_TOKEN_RETURN = 0;
long long _eq_g_TOKEN_REVERSE = 0;
long long _eq_g_TOKEN_ROLES = 0;
long long _eq_g_TOKEN_RPARENT = 0;
long long _eq_g_TOKEN_SEMICOLON = 0;
long long _eq_g_TOKEN_SLASH = 0;
long long _eq_g_TOKEN_STRING = 0;
long long _eq_g_TOKEN_STRUCT = 0;
long long _eq_g_TOKEN_TO = 0;
long long _eq_g_TOKEN_TRANSFORMATION = 0;
long long _eq_g_TOKEN_UNIT = 0;
long long _eq_g_TOKEN_USE = 0;
long long _eq_g_TOKEN_VALUATOR = 0;
long long _eq_g_TOKEN_WHILE = 0;
long long _eq_g_TOKEN_ARROW = 0;
long long _eq_g_TOKEN_LSHIFT = 0;
long long _eq_g_TOKEN_PTR = 0;
long long _eq_g_TOKEN_BITOR = 0;
long long _eq_g_TRANSFORMATION_COL = 0;
long long _eq_g_TRANSFORMATION_FLOWS = 0;
long long _eq_g_TRANSFORMATION_LINE = 0;
long long _eq_g_TRANSFORMATION_LOGIC = 0;
long long _eq_g_TRANSFORMATION_NAME = 0;
long long _eq_g_TRANSFORMATION_ROLES = 0;
long long _eq_g_UNARY_COL = 0;
long long _eq_g_UNARY_LINE = 0;
long long _eq_g_UNARY_OP = 0;
long long _eq_g_UNARY_RIGHT = 0;
long long _eq_g_VALUATOR_BODY = 0;
long long _eq_g_VALUATOR_COL = 0;
long long _eq_g_VALUATOR_IMPLEMENTS = 0;
long long _eq_g_VALUATOR_LINE = 0;
long long _eq_g_VALUATOR_NAME = 0;
long long _eq_g_VAR_COL = 0;
long long _eq_g_VAR_LINE = 0;
long long _eq_g_VAR_NAME = 0;
long long _eq_g_WHILE_BODY = 0;
long long _eq_g_WHILE_COL = 0;
long long _eq_g_WHILE_COND = 0;
long long _eq_g_WHILE_LINE = 0;
long long _eq_g___global_print_buf = 0;
long long _eq_g___intern_map = 0;
long long _eq_g_compile_depth = 0;
long long _eq_g_global_ast_buffer = 0;
long long _eq_g_include_paths = 0;
long long _eq_g_incremental_flag = 0;
long long _eq_g_loaded_files = 0;
long long _eq_g_print_buf = 0;
long long _eq_g_resolve_stat = 0;
long long sys_ptr_add(long long p, long long o);
long long sys_strlen(long long s);
long long sys_malloc(long long s);
long long sys_read_entire_file(long long p);
long long sys_write_raw(long long fd, long long buf, long long count);
long long str_to_int(long long s);
long long sys_time();
long long sys_set_agent(long long id);
long long sys_get_agent();
long long sys_get_argc();
long long sys_get_argv(long long i);
long long get_char(long long p, long long i);
long long set_char(long long p, long long i, long long c);
long long __attribute__((noinline)) _eq_strcmp_wrap(long long s1, long long s2) { return (long long)strcmp((char*)s1, (char*)s2); }
long long __attribute__((noinline)) _eq_strncmp_wrap(long long s1, long long s2, long long n) { return (long long)strncmp((char*)s1, (char*)s2, (size_t)n); }
long long __attribute__((noinline)) _eq_strlen_wrap(long long s) { return (long long)strlen((char*)s); }
long long __attribute__((noinline)) _eq_FIXED_SCALE();
long long __attribute__((noinline)) _eq__unused_parser_is_at_end(long long p);
long long __attribute__((noinline)) _eq__unused_parser_peek(long long p);
long long __attribute__((noinline)) _eq__unused_print_char(long long c);
long long __attribute__((noinline)) _eq__unused_print_raw_stderr(long long n);
long long __attribute__((noinline)) _eq__unused_str_to_int(long long s);
long long __attribute__((noinline)) _eq__unused_sys_assert(long long cond,long long msg);
long long __attribute__((noinline)) _eq__unused_sys_malloc(long long size);
long long __attribute__((noinline)) _eq__unused_sys_malloc_rc(long long size);
long long __attribute__((noinline)) _eq__unused_sys_panic_null();
long long __attribute__((noinline)) _eq__unused_sys_panic_overflow();
long long __attribute__((noinline)) _eq__unused_sys_read_entire_file(long long path);
long long __attribute__((noinline)) _eq__unused_sys_release(long long p);
long long __attribute__((noinline)) _eq__unused_sys_retain(long long p);
long long __attribute__((noinline)) _eq__unused_sys_sleep(long long ms);
long long __attribute__((noinline)) _eq__unused_sys_time();
long long __attribute__((noinline)) _eq_accounting_init(long long base_res,long long base_cur);
long long __attribute__((noinline)) _eq_acct_register(long long sys,long long name,long long type,long long code);
long long __attribute__((noinline)) _eq_analyze_error(long long msg,long long line,long long col);
long long __attribute__((noinline)) _eq_analyze_error_internal(long long a,long long msg,long long line,long long col);
long long __attribute__((noinline)) _eq_analyze_event_duality(long long a,long long stmt);
long long __attribute__((noinline)) _eq_analyze_expr(long long a,long long expr);
long long __attribute__((noinline)) _eq_analyze_program(long long a,long long ast);
long long __attribute__((noinline)) _eq_analyze_stmt(long long a,long long stmt);
long long __attribute__((noinline)) _eq_analyze_undeclared(long long name,long long line,long long col);
long long __attribute__((noinline)) _eq_analyze_undeclared_internal(long long a,long long name,long long line,long long col);
long long __attribute__((noinline)) _eq_analyzer_add_builtins(long long a);
long long __attribute__((noinline)) _eq_analyzer_alloc(long long a,long long size);
long long __attribute__((noinline)) _eq_analyzer_begin_scope(long long a);
long long __attribute__((noinline)) _eq_analyzer_copy_node(long long a,long long node);
long long __attribute__((noinline)) _eq_analyzer_define(long long a,long long name,long long node,long long static_type);
long long __attribute__((noinline)) _eq_analyzer_end_scope(long long a);
long long __attribute__((noinline)) _eq_analyzer_is_global(long long a,long long name);
long long __attribute__((noinline)) _eq_analyzer_new();
long long __attribute__((noinline)) _eq_analyzer_resolve(long long a,long long name);
long long __attribute__((noinline)) _eq_analyzer_specialize(long long a,long long gen_func_name,long long types);
long long __attribute__((noinline)) _eq_analyzer_substitute_types(long long a,long long node,long long generics,long long types);
long long __attribute__((noinline)) _eq_arena_alloc(long long a,long long size);
long long __attribute__((noinline)) _eq_arena_free_all(long long a);
long long __attribute__((noinline)) _eq_arena_new(long long initial_size);
long long __attribute__((noinline)) _eq_arena_new_owned(long long initial_size,long long owner_id);
long long __attribute__((noinline)) _eq_close(long long fd);
long long __attribute__((noinline)) _eq_codegen_new(long long trace_enabled,long long incremental);
long long __attribute__((noinline)) _eq_codegen_print_char(long long c);
long long __attribute__((noinline)) _eq_compile_file(long long path);
long long __attribute__((noinline)) _eq_emit_ln(long long s);
long long __attribute__((noinline)) _eq_exit(long long code);
long long __attribute__((noinline)) _eq_expr_assignment(long long target,long long value,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_binary(long long left,long long op,long long right,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_call(long long callee,long long args,long long line,long long col,long long generics);
long long __attribute__((noinline)) _eq_expr_get(long long object,long long name,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_index(long long obj,long long idx,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_literal(long long val,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_string_literal(long long val,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_try(long long expr,long long line,long long col);
long long __attribute__((noinline)) _eq_expr_variable(long long name,long long line,long long col);
long long __attribute__((noinline)) _eq_fixed_add(long long a,long long b);
long long __attribute__((noinline)) _eq_fixed_div(long long a,long long b);
long long __attribute__((noinline)) _eq_fixed_from_int(long long n);
long long __attribute__((noinline)) _eq_fixed_mul(long long a,long long b);
long long __attribute__((noinline)) _eq_fixed_new(long long i,long long f);
long long __attribute__((noinline)) _eq_fixed_sub(long long a,long long b);
long long __attribute__((noinline)) _eq_fixed_to_str(long long n);
long long __attribute__((noinline)) _eq_free(long long ptr);
long long __attribute__((noinline)) _eq_freshen_label(long long c);
long long __attribute__((noinline)) _eq_freshen_ptr(long long c);
long long __attribute__((noinline)) _eq_freshen_reg(long long c);
long long __attribute__((noinline)) _eq_gen_expr(long long c,long long expr);
long long __attribute__((noinline)) _eq_gen_program(long long c,long long ast);
long long __attribute__((noinline)) _eq_gen_release_locals(long long c,long long vars);
long long __attribute__((noinline)) _eq_gen_stmt(long long c,long long stmt);
long long __attribute__((noinline)) _eq_gen_string_label(long long c,long long val);
long long __attribute__((noinline)) _eq_get_expr_type(long long a,long long expr);
long long __attribute__((noinline)) _eq_intern_cleanup();
long long __attribute__((noinline)) _eq_intern_string(long long s);
long long __attribute__((noinline)) _eq_is_alpha(long long c);
long long __attribute__((noinline)) _eq_is_defined(long long c,long long name);
long long __attribute__((noinline)) _eq_is_digit(long long c);
long long __attribute__((noinline)) _eq_is_extern(long long c,long long name);
long long __attribute__((noinline)) _eq_is_loaded(long long path);
long long __attribute__((noinline)) _eq_journal_entry(long long acct_sys,long long amount,long long res,long long cur,long long from_acc,long long to_acc,long long date);
long long __attribute__((noinline)) _eq_json_get_int(long long m,long long k);
long long __attribute__((noinline)) _eq_json_get_str(long long m,long long k);
long long __attribute__((noinline)) _eq_json_item_array(long long v);
long long __attribute__((noinline)) _eq_json_item_int(long long v);
long long __attribute__((noinline)) _eq_json_item_obj(long long v);
long long __attribute__((noinline)) _eq_json_item_str(long long v);
long long __attribute__((noinline)) _eq_json_new();
long long __attribute__((noinline)) _eq_json_parse(long long s);
long long __attribute__((noinline)) _eq_json_put_array(long long m,long long k,long long v);
long long __attribute__((noinline)) _eq_json_put_int(long long m,long long k,long long v);
long long __attribute__((noinline)) _eq_json_put_obj(long long m,long long k,long long v);
long long __attribute__((noinline)) _eq_json_put_str(long long m,long long k,long long v);
long long __attribute__((noinline)) _eq_json_serialize(long long m);
long long __attribute__((noinline)) _eq_json_serialize_value(long long item);
long long __attribute__((noinline)) _eq_ledger_balance_at(long long l,long long agent,long long res,long long currency,long long target_date);
long long __attribute__((noinline)) _eq_ledger_get_entries_for(long long l,long long agent);
long long __attribute__((noinline)) _eq_ledger_get_key(long long agent_name,long long res_name,long long currency);
long long __attribute__((noinline)) _eq_ledger_new();
long long __attribute__((noinline)) _eq_ledger_process_flow(long long l,long long flow_type,long long amount,long long res,long long currency,long long from_agent,long long to_agent,long long effective_date);
long long __attribute__((noinline)) _eq_ledger_update_temporal(long long l,long long agent,long long res,long long currency,long long delta,long long effective_date);
long long __attribute__((noinline)) _eq_lexer_add_token(long long lex,long long type,long long lexeme);
long long __attribute__((noinline)) _eq_lexer_add_token_type(long long lex,long long type);
long long __attribute__((noinline)) _eq_lexer_advance(long long lex);
long long __attribute__((noinline)) _eq_lexer_get_lexeme(long long lex);
long long __attribute__((noinline)) _eq_lexer_identifier(long long lex);
long long __attribute__((noinline)) _eq_lexer_is_alpha(long long c);
long long __attribute__((noinline)) _eq_lexer_is_alpha_numeric(long long c);
long long __attribute__((noinline)) _eq_lexer_is_at_end(long long lex);
long long __attribute__((noinline)) _eq_lexer_is_digit(long long c);
long long __attribute__((noinline)) _eq_lexer_match(long long lex,long long expected);
long long __attribute__((noinline)) _eq_lexer_new(long long source, long long filename);
long long __attribute__((noinline)) _eq_lexer_number(long long lex);
long long __attribute__((noinline)) _eq_lexer_peek(long long lex);
long long __attribute__((noinline)) _eq_lexer_peek_next(long long lex);
long long __attribute__((noinline)) _eq_lexer_scan_token(long long lex);
long long __attribute__((noinline)) _eq_lexer_scan_tokens(long long lex);
long long __attribute__((noinline)) _eq_lexer_string(long long lex);
long long __attribute__((noinline)) _eq_lseek(long long fd,long long offset,long long whence);
long long __attribute__((noinline)) _eq_lsp_find_node_at(long long node,long long line,long long col);
long long __attribute__((noinline)) _eq_lsp_find_stmt_at(long long ast,long long line,long long col);
long long __attribute__((noinline)) _eq_lsp_loop();
long long __attribute__((noinline)) _eq_lsp_publish_diagnostics(long long uri,long long a);
long long __attribute__((noinline)) _eq_lsp_send(long long msg_map);
long long __attribute__((noinline)) _eq_main_routine();
long long __attribute__((noinline)) _eq_malloc(long long size);
long long __attribute__((noinline)) _eq_map_get(long long m,long long key);
long long __attribute__((noinline)) _eq_map_hash(long long key);
long long __attribute__((noinline)) _eq_map_keys(long long m);
long long __attribute__((noinline)) _eq_map_new(long long capacity);
long long __attribute__((noinline)) _eq_map_put(long long m,long long key,long long val);
long long __attribute__((noinline)) _eq_map_remove(long long m,long long key);
long long __attribute__((noinline)) _eq_open(long long path,long long flags,long long mode);
long long __attribute__((noinline)) _eq_optimize_expr(long long expr);
long long __attribute__((noinline)) _eq_optimize_program(long long ast);
long long __attribute__((noinline)) _eq_optimize_stmt(long long stmt);
long long __attribute__((noinline)) _eq_parse_addition(long long p);
long long __attribute__((noinline)) _eq_parse_agent(long long p);
long long __attribute__((noinline)) _eq_parse_and(long long p);
long long __attribute__((noinline)) _eq_parse_assert(long long p);
long long __attribute__((noinline)) _eq_parse_assignment(long long p);
long long __attribute__((noinline)) _eq_parse_block(long long p);
long long __attribute__((noinline)) _eq_parse_call(long long p);
long long __attribute__((noinline)) _eq_parse_commitment(long long p);
long long __attribute__((noinline)) _eq_parse_comparison(long long p);
long long __attribute__((noinline)) _eq_parse_equality(long long p);
long long __attribute__((noinline)) _eq_parse_event(long long p);
long long __attribute__((noinline)) _eq_parse_exchange(long long p);
long long __attribute__((noinline)) _eq_parse_execute(long long p);
long long __attribute__((noinline)) _eq_parse_expression(long long p);
long long __attribute__((noinline)) _eq_parse_expression_statement(long long p);
long long __attribute__((noinline)) _eq_parse_extern(long long p);
long long __attribute__((noinline)) _eq_parse_function(long long p);
long long __attribute__((noinline)) _eq_stmt_function(long long name,long long params,long long body,long long line,long long col,long long generics,long long param_types,long long return_type,long long params_mut);
long long __attribute__((noinline)) _eq_parse_if(long long p);
long long __attribute__((noinline)) _eq_parse_interface(long long p);
long long __attribute__((noinline)) _eq_parse_let(long long p);
long long __attribute__((noinline)) _eq_parse_multiplication(long long p);
long long __attribute__((noinline)) _eq_parse_or(long long p);
long long __attribute__((noinline)) _eq_parse_policy(long long p);
long long __attribute__((noinline)) _eq_parse_primary(long long p);
long long __attribute__((noinline)) _eq_parse_print(long long p);
long long __attribute__((noinline)) _eq_parse_program(long long p);
long long __attribute__((noinline)) _eq_parse_resource(long long p);
long long __attribute__((noinline)) _eq_parse_return(long long p);
long long __attribute__((noinline)) _eq_parse_reverse(long long p);
long long __attribute__((noinline)) _eq_parse_statement(long long p);
long long __attribute__((noinline)) _eq_parse_struct_decl(long long p);
long long __attribute__((noinline)) _eq_parse_transformation(long long p);
long long __attribute__((noinline)) _eq_parse_unary(long long p);
long long __attribute__((noinline)) _eq_parse_use(long long p);
long long __attribute__((noinline)) _eq_parse_valuator(long long p);
long long __attribute__((noinline)) _eq_parse_while(long long p);
long long __attribute__((noinline)) _eq_parser_advance(long long p);
long long __attribute__((noinline)) _eq_parser_check(long long p,long long type);
long long __attribute__((noinline)) _eq_parser_consume(long long p,long long type,long long msg);
long long __attribute__((noinline)) _eq_parser_error(long long p,long long msg);
long long __attribute__((noinline)) _eq_parser_is_at_end(long long p);
long long __attribute__((noinline)) _eq_parser_match(long long p,long long type);
long long __attribute__((noinline)) _eq_parser_new(long long tokens);
long long __attribute__((noinline)) _eq_parser_parse_generics(long long p);
long long __attribute__((noinline)) _eq_parser_peek(long long p);
long long __attribute__((noinline)) _eq_parser_previous(long long p);
long long __attribute__((noinline)) _eq_print_err(long long s);
long long __attribute__((noinline)) _eq_print_escaped_str(long long s);
long long __attribute__((noinline)) _eq_print_fixed(long long n);
long long __attribute__((noinline)) _eq_print_raw(long long n);
long long __attribute__((noinline)) _eq_print_raw_str(long long s);
long long __attribute__((noinline)) _eq_print_str(long long s);
long long __attribute__((noinline)) _eq_printf(long long fmt,long long val);
long long __attribute__((noinline)) _eq_read(long long fd,long long buf,long long count);
long long __attribute__((noinline)) _eq_report_balance_sheet(long long acct_sys,long long asset_acc,long long liab_acc,long long equity_acc,long long target_date);
long long __attribute__((noinline)) _eq_report_income_statement(long long acct_sys,long long rev_acc,long long exp_acc,long long target_date);
long long __attribute__((noinline)) _eq_sleep(long long seconds);
long long __attribute__((noinline)) _eq_stmt_block(long long stmts,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_expression(long long expr,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_extern(long long name,long long params,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_if(long long cond,long long then,long long els,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_interface(long long name,long long methods,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_let(long long name,long long value,long long type,long long line,long long col,long long is_mut,long long is_res);
long long __attribute__((noinline)) _eq_stmt_print(long long expr,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_return(long long val,long long line,long long col);
long long __attribute__((noinline)) _eq_stmt_struct(long long name,long long fields,long long line,long long col,long long generics);
long long __attribute__((noinline)) _eq_stmt_while(long long cond,long long body,long long line,long long col);
long long __attribute__((noinline)) _eq_str_concat(long long s1,long long s2);
long long __attribute__((noinline)) _eq_str_equal(long long s1,long long s2);
long long __attribute__((noinline)) _eq_str_from_int(long long n);
long long __attribute__((noinline)) _eq_str_len(long long s);
long long __attribute__((noinline)) _eq_str_starts_with(long long s,long long prefix);
long long __attribute__((noinline)) _eq_str_substring(long long s,long long start,long long len);
long long __attribute__((noinline)) _eq_str_substring_equal(long long s,long long start,long long len,long long expected);
long long __attribute__((noinline)) _eq_str_to_int_internal(long long s);
long long __attribute__((noinline)) _eq_sys_get_word(long long p,long long idx);
long long __attribute__((noinline)) _eq_sys_reverse_event(long long p);
long long __attribute__((noinline)) _eq_sys_set_word(long long p,long long idx,long long val);
long long __attribute__((noinline)) _eq_sys_write(long long fd,long long buf,long long count);
long long __attribute__((noinline)) _eq_time(long long tloc);
long long __attribute__((noinline)) _eq_token_new(long long type,long long lexeme,long long line,long long col);
long long __attribute__((noinline)) _eq_try_read(long long path);
long long __attribute__((noinline)) _eq_vec_get(long long vec,long long index);
long long __attribute__((noinline)) _eq_vec_new(long long capacity);
long long __attribute__((noinline)) _eq_vec_push(long long vec,long long value);
long long __attribute__((noinline)) _eq_vec_remove(long long vec,long long index);
long long __attribute__((noinline)) _eq_vec_set(long long vec,long long index,long long value);
long long __attribute__((noinline)) _eq_vec_size(long long vec);
long long __attribute__((noinline)) _eq_verify_interface_implementation(long long a,long long i_name,long long target,long long line,long long col);
long long __attribute__((noinline)) _eq_verify_type_match(long long a,long long expected,long long actual_node,long long line,long long col);
long long __attribute__((noinline)) _eq_write(long long fd,long long buf,long long count);

long long _eq__unused_sys_malloc(long long size) {
    volatile long long p = 0;

     p = (long long)malloc((size_t)(size + 16));
    if (p == 0) { exit(1); }
    _eq_sys_set_word(p, 0, 4994960144983052867);
    _eq_sys_set_word(p, 1, 1); 
    return p + 16;
}
long long _eq__unused_sys_malloc_rc(long long size) {

    return _eq__unused_sys_malloc(size);
}
long long _eq__unused_sys_retain(long long p) {
    volatile long long count = 0;
    volatile long long head = 0;
    volatile long long magic = 0;

    if (p < 4096) { return p; }
     head = p - 16;
     magic = _eq_sys_get_word(head, 0);
    if (magic == 4994960144983052867) {
         count = _eq_sys_get_word(head, 1);
        _eq_sys_set_word(head, 1, count + 1);
    }
    return p;
}
long long _eq__unused_sys_release(long long p) {
    volatile long long count = 0;
    volatile long long head = 0;
    volatile long long magic = 0;

    if (p < 4096) { return 0; }
     head = p - 16;
     magic = _eq_sys_get_word(head, 0);
    if (magic == 4994960144983052867) {
         count = _eq_sys_get_word(head, 1);
        if (count <= 1) {
            sys_free((long long)head);
            return 1;
        }
        _eq_sys_set_word(head, 1, count - 1);
    }
    return 0;
}
long long _eq_print_char(long long c) {
    if (_eq_g___global_print_buf == 0) { _eq_g___global_print_buf = (long long)malloc(1024); }
    set_char(_eq_g___global_print_buf, 0, (char)c);
    (void)!write(1, (void*)_eq_g___global_print_buf, 1);
    return 0;
}
long long _eq_sys_write(long long fd, long long buf, long long count) {

    return (long long)write((int)fd, (void*)buf, (size_t)count);
}
long long _eq_print_raw(long long n) {
    volatile long long digit = 0;
    volatile long long i = 0;

    if (_eq_g___global_print_buf == 0) { _eq_g___global_print_buf = (long long)malloc(1024); }
    if (n == 0) { (void)!write(1, (void*)((long long)"0"), 1); return 0; }
    if (n < 0) { (void)!write(1, (void*)((long long)"-"), 1); n = 0 - n; }
     i = 30;
    set_char(_eq_g___global_print_buf, 31, 0);
    while (n > 0) {
        digit = n - ((n / 10) * 10);
        set_char(_eq_g___global_print_buf, i, digit + 48);
        n = n / 10;
        i = i - 1;
    }
    (void)!write(1, (void*)(_eq_g___global_print_buf + i + 1), (size_t)(30 - i));
}
long long _eq_print_int(long long n) {
    volatile long long digit = 0;
    volatile long long i = 0;
    volatile long long n_val = 0;

    if (_eq_g___global_print_buf == 0) { _eq_g___global_print_buf = (long long)malloc(1024); }
    if (n == 0) { 
        (void)!write(2, (void*)((long long)"0"), 1); 
        return 0; 
    }
    if (n < 0) { 
        (void)!write(2, (void*)((long long)"-"), 1); 
        n_val = 0 - n; 
    } else {
        n_val = n;
    }
     i = 60;
    set_char(_eq_g___global_print_buf, 61, 0);
    while (n_val > 0) {
        digit = n_val - ((n_val / 10) * 10);
        set_char(_eq_g___global_print_buf, i, digit + 48);
        n_val = n_val / 10;
        i = i - 1;
    }
    (void)!write(2, (void*)(_eq_g___global_print_buf + i + 1), (size_t)(60 - i));
}
long long _eq_print_raw_str(long long s) {
    volatile long long len = 0;

    if (s == 0) { return 0; }
     len = sys_strlen(s);
    (void)!write(1, (void*)s, (size_t)len);
    return 0;
}
long long _eq_sys_write_stderr(long long s) {
    if (s == 0) return 0;
    size_t slen = strlen((char*)s);
    return (long long)write(2, (void*)s, slen);
}
long long _eq_print_err(long long s) {
    if (s == 0) return 0;
    size_t slen = strlen((char*)s);
    return (long long)write(1, (void*)s, slen);
}
long long _eq__unused_sys_panic_null() {
    (void)!write(2, (void*)((long long)"PANIC: Null pointer dereference\n"), 31);
    exit(1);
}
long long _eq__unused_sys_panic_overflow() {

    (void)!write(2, (void*)((long long)"PANIC: ARITHMETIC OVERFLOW (FINANCIAL INTEGRITY VIOLATION)\n"), 59);
    exit(1);
}
long long _eq__unused_sys_assert(long long cond, long long msg) {

    if (cond == 0) {
        (void)!write(2, (void*)((long long)"ASSERTION FAILED: "), 18);
        (void)!write(2, (void*)msg, sys_strlen(msg));
        (void)!write(2, (void*)((long long)"\n"), 1);
        exit(1);
    }
}
long long _eq__unused_sys_sleep(long long ms) {
 sleep(1); }
long long _eq__unused_sys_time() {
 return time(0); }
long long _eq__unused_sys_read_entire_file(long long path) {
    volatile long long buf = 0;
    volatile long long fd = 0;
    volatile long long n = 0;
    volatile long long size = 0;
    volatile long long total = 0;
    (void)!write(2, (void*)((long long)"READ_FILE: "), 11);
    (void)!write(2, (void*)path, (size_t)sys_strlen(path));
    (void)!write(2, (void*)((long long)"\n"), 1);
     fd = (long long)open((void*)path, 0, 0);
    if (fd < 0) { 
        (void)!write(2, (void*)((long long)"OPEN FAILED\n"), 12);
        return 0; 
    }
     size = (long long)lseek((int)fd, 0, 2);
    (void)lseek((int)fd, 0, 0);
    (void)!write(2, (void*)((long long)"SIZE: "), 6); 
     buf = (long long)sys_malloc((size_t)(size + 1));
     total = 0;
     n = 0;
    while (total < size) {
         n = read(fd, (void*)sys_ptr_add(buf, total), (size_t)(size - total));
        if (n <= 0) { 
            (void)!write(2, (void*)((long long)"READ FAILED\n"), 12);
            return 0; 
        }
        total = total + n;
    }
    (void)!write(2, (void*)((long long)"READ DONE\n"), 10);
    close(fd);
    set_char(buf, size, 0);
    return buf;
}
long long _eq_str_equal(long long s1, long long s2) {
    volatile long long res = 0;

    if (s1 == 0) { if (s2 == 0) { return 1; } return 0; }
    if (s2 == 0) { return 0; }
    if (s1 == s2) { return 1; }
     res = 0;
    res = _eq_strcmp_wrap(s1, s2);
    return res == 0;
}
long long _eq_str_starts_with(long long s, long long prefix) {
    volatile long long plen = 0;
    volatile long long res = 0;
    volatile long long slen = 0;

    if (s == 0) { return 0; }
    if (prefix == 0) { return 1; }
     plen = 0;
    plen = sys_strlen(prefix);
     slen = 0;
    slen = sys_strlen(s);
    if (slen < plen) { return 0; }
     res = 0;
    res = _eq_strncmp_wrap(s, prefix, plen);
    return res == 0;
}
long long _eq_str_len(long long s) {
    volatile long long res = 0;

    if (s == 0) { return 0; }
     res = 0;
    res = sys_strlen(s);
    return res;
}
long long _eq_str_substring(long long s, long long start, long long len) {
    volatile long long i = 0;
    volatile long long res_str = 0;

    if (s == 0) { return 0; }
     res_str = sys_malloc(len + 1);
     i = 0;
    while (i < len) {
        set_char(res_str, i, get_char(s, start + i));
        i = i + 1;
    }
    set_char(res_str, len, 0);
    return res_str;
}
long long _eq_is_alpha(long long c) {

    if (c >= 97 && c <= 122) { return 1; }
    if (c >= 65 && c <= 90) { return 1; }
    if (c == 95) { return 1; }
    return 0;
}
long long _eq_is_digit(long long c) {

    if (c >= 48 && c <= 57) { return 1; }
    return 0;
}
long long _eq_print_str(long long s) {
    volatile long long len = 0;
     len = sys_strlen(s);
    (void)!write(1, (void*)s, (size_t)len);
}
long long _eq_str_concat(long long s1, long long s2) {
    volatile long long c1 = 0;
    volatile long long c2 = 0;
    volatile long long fin = 0;
    volatile long long i = 0;
    volatile long long j = 0;
    volatile long long l1 = 0;
    volatile long long l2 = 0;
    volatile long long out_ptr = 0;

     l1 = 0;
    l1 = sys_strlen(s1);
     l2 = 0;
    l2 = sys_strlen(s2);
     out_ptr = 0;
    out_ptr = sys_malloc(l1 + l2 + 1);
     i = 0;
     c1 = 0;
    while (i < l1) {
        c1 = get_char(s1, i);
        set_char(out_ptr, i, c1);
        i = i + 1;
    }
     j = 0;
     c2 = 0;
    while (j < l2) {
        c2 = get_char(s2, j);
        set_char(out_ptr, l1 + j, c2);
        j = j + 1;
    }
     fin = 0;
    fin = l1 + l2;
    set_char(out_ptr, fin, 0);
    return out_ptr;
}
long long _eq_str_from_int(long long n) {
    volatile long long d = 0;
    volatile long long i = 0;
    volatile long long k = 0;
    volatile long long neg = 0;
    volatile long long offset = 0;
    volatile long long s = 0;

    if (n == 0) { return _eq_str_concat(((long long)"0"), ((long long)"")); }
     s = 0;
    s = sys_malloc(20);
     i = 18;
    set_char(s, 19, 0);
     neg = 0;
    if (n < 0) { neg = 1; n = 0 - n; }
    while (n > 0) {
         d = n - ((n / 10) * 10);
        set_char(s, i, d + 48);
        n = n / 10;
        i = i - 1;
    }
    if (neg) { set_char(s, i, 45); i = i - 1; }
    
    
     offset = i + 1;
     k = 0;
    while (k < (20 - offset)) {
        set_char(s, k, get_char(s, offset + k));
        k = k + 1;
    }
    return s;
}
long long _eq_sys_write_stdout(long long s) {
    volatile long long slen = 0;
     slen = sys_strlen(s);
    return (long long)write(1, (void*)s, (size_t)slen);
}
long long _eq__unused_str_to_int(long long s) {
    volatile long long c = 0;
    volatile long long d = 0;
    volatile long long fc = 0;
    volatile long long i = 0;
    volatile long long res = 0;
    volatile long long sign = 0;

    if (s == 0) { return 0; }
     res = 0;
     i = 0;
     sign = 1;
     fc = 0;
    fc = get_char(s, 0);
    if (fc == 45) { sign = -1; i = 1; }
     c = 0;
     d = 0;
    while (get_char(s, i) != 0) {
        c = get_char(s, i);
        d = c - 48;
        res = (res * 10) + d;
        i = i + 1;
    }
    return res * sign;
}
long long _eq_str_substring_equal(long long s, long long start, long long len, long long expected) {
    volatile long long ptr = 0;
    volatile long long res = 0;

    if (s == 0) { return 0; }
    if (expected == 0) { return 0; }
     ptr = 0;
    ptr = sys_ptr_add(s, start);
     res = 0;
    res = _eq_strncmp_wrap(ptr, expected, len);
    return res == 0;
}
long long _eq_vec_new(long long capacity) {
    volatile long long ptr = 0;

     ptr = sys_malloc((capacity + 2) * 16);
    ((long long*)(ptr))[0] = capacity;
    ((long long*)(ptr))[1] = 0;
    return ptr;
}
long long _eq_vec_push(long long vec, long long value) {
    volatile long long cap = 0;
    volatile long long offset = 0;
    volatile long long size = 0;

     cap = ((long long*)(vec))[0];
     size = ((long long*)(vec))[1];
     offset = 0;
    if (size < cap) {
        offset = size + 2;
        ((long long*)(vec))[offset] = value;
        ((long long*)(vec))[1] = size + 1;
    }
    return vec;
}
long long _eq_vec_get(long long vec, long long index) {
    volatile long long offset = 0;

    if (vec == 0) { return 0; }

    if (index < 0 || index >= ((long long*)(vec))[1]) { return 0; }
     offset = index + 2;
    return ((long long*)(vec))[offset];
}
long long _eq_vec_size(long long vec) {

    if (vec == 0) { return 0; }

    return ((long long*)(vec))[1];
}
long long _eq_map_new(long long capacity) {
    volatile long long i = 0;
    volatile long long m = 0;
    volatile long long offset = 0;

     m = sys_malloc((capacity + 1) * 16);
     i = 0;
     offset = 0;
    ((long long*)(m))[0] = capacity;
    while (i < capacity) {
        offset = i + 1;
        ((long long*)(m))[offset] = 0;
        i = i + 1;
    }
    return m;
}
long long _eq_map_hash(long long key) {
    volatile long long char_val = 0;
    volatile long long h = 0;
    volatile long long idx = 0;
    volatile long long len = 0;

    if (key == 0) { return 0; }
     h = 0;
     idx = 0;
     len = sys_strlen(key);
     char_val = 0;
    while (idx < len) {
        char_val = get_char(key, idx);
        h = h + char_val;
        idx = idx + 1;
    }
    return h;
}
long long _eq_map_put(long long m, long long key, long long val) {
    volatile long long cap = 0;
    volatile long long entry = 0;
    volatile long long h = 0;
    volatile long long m_off = 0;
    volatile long long quot = 0;
    volatile long long rem = 0;

    if (m == 0) { return 0; }
     cap = ((long long*)(m))[0];
     h = _eq_map_hash(key);
     rem = 0;
     quot = h / cap;
    rem = h - (quot * cap);
    if (rem < 0) { rem = 0 - rem; }
     entry = sys_malloc(3 * 16);
     m_off = rem + 1;
    ((long long*)(entry))[0] = key;
    ((long long*)(entry))[1] = val;
    ((long long*)(entry))[2] = ((long long*)(m))[m_off];
    ((long long*)(m))[m_off] = entry;
    return 1;
}
long long _eq_map_get(long long m, long long key) {
    volatile long long cap = 0;
    volatile long long entry = 0;
    volatile long long entry_key = 0;
    volatile long long h = 0;
    volatile long long m_off = 0;
    volatile long long quot = 0;
    volatile long long rem = 0;

    if (m == 0) { return 0; }
     cap = ((long long*)(m))[0];
     h = _eq_map_hash(key);
     rem = 0;
     quot = h / cap;
    rem = h - (quot * cap);
    if (rem < 0) { rem = 0 - rem; }
     m_off = rem + 1;
     entry = ((long long*)(m))[m_off];
     entry_key = 0;
    while (entry != 0) {
        entry_key = ((long long*)(entry))[0];

        if (_eq_str_equal(entry_key, key)) { return ((long long*)(entry))[1]; }
        entry = ((long long*)(entry))[2];
    }
    return 0;
}
long long _eq_map_keys(long long m) {
    volatile long long cap = 0;
    volatile long long entry = 0;
    volatile long long i = 0;
    volatile long long k = 0;
    volatile long long keys = 0;
    volatile long long m_off = 0;

     cap = ((long long*)(m))[0];
     keys = _eq_vec_new(cap);
     i = 0;
     m_off = 0;
     entry = 0;
     k = 0;
    while (i < cap) {
        m_off = i + 1;
        entry = ((long long*)(m))[m_off];
        while (entry != 0) {
            k = ((long long*)(entry))[0];
            _eq_vec_push(keys, k);
            entry = ((long long*)(entry))[2];
        }
        i = i + 1;
    }
    return keys;
}
long long _eq_vec_set(long long vec, long long index, long long value) {
    volatile long long offset = 0;

    if (vec == 0) { return 0; }
    if (index < 0 || index >= ((long long*)(vec))[0]) { return 0; }
     offset = index + 2;
    ((long long*)(vec))[offset] = value;
    return vec;
}
long long _eq_vec_remove(long long vec, long long index) {
    volatile long long i = 0;
    volatile long long limit = 0;
    volatile long long next = 0;
    volatile long long size = 0;
    volatile long long val = 0;

     size = ((long long*)(vec))[1];
     i = index;
     limit = size - 1;
     next = 0;
     val = 0;
    while (i < limit) {
        next = i + 1;
        val = _eq_vec_get(vec, next);
        _eq_vec_set(vec, i, val);
        i = next;
    }
    ((long long*)(vec))[1] = limit;
    return vec;
}
long long _eq_map_remove(long long m, long long key) {
    volatile long long cap = 0;
    volatile long long entry = 0;
    volatile long long entry_key = 0;
    volatile long long h = 0;
    volatile long long m_off = 0;
    volatile long long next_entry = 0;
    volatile long long prev = 0;
    volatile long long quot = 0;
    volatile long long rem = 0;

    if (m == 0) { return 0; }
     cap = ((long long*)(m))[0];
     h = _eq_map_hash(key);
     quot = h / cap;
     rem = h - (quot * cap);
    if (rem < 0) { rem = 0 - rem; }
     m_off = rem + 1;
     entry = ((long long*)(m))[m_off];
     prev = 0;
     entry_key = 0;
     next_entry = 0;
    while (entry != 0) {
        entry_key = ((long long*)(entry))[0];
        if (_eq_str_equal(entry_key, key)) {
            next_entry = ((long long*)(entry))[2];
            if (prev == 0) {
                ((long long*)(m))[m_off] = next_entry;
            } else {
                ((long long*)(prev))[2] = next_entry;
            }
            return 1;
        }
        prev = entry;
        entry = ((long long*)(entry))[2];
    }
    return 0;
}
long long _eq_FIXED_SCALE() {
 return 1000000; }
long long _eq_fixed_new(long long i, long long f) {
    volatile long long res = 0;
    volatile long long scale = 0;

     scale = 0;
    scale = _eq_FIXED_SCALE();
     res = 0;
    res = (i * scale) + f;
    return res;
}
long long _eq_fixed_from_int(long long n) {
    volatile long long res = 0;
    volatile long long scale = 0;

     scale = 0;
    scale = _eq_FIXED_SCALE();
     res = 0;
    res = n * scale;
    return res;
}
long long _eq_fixed_add(long long a, long long b) {
 return a + b; }
long long _eq_fixed_sub(long long a, long long b) {
 return a - b; }
long long _eq_fixed_mul(long long a, long long b) {
    volatile long long half = 0;
    volatile long long prod = 0;
    volatile long long q = 0;
    volatile long long q_half = 0;
    volatile long long r = 0;
    volatile long long scale = 0;

     scale = _eq_FIXED_SCALE();
     prod = a * b;
     q = prod / scale;
     r = prod - (q * scale);
    if (r < 0) { r = 0 - r; }
     half = scale / 2;
    if (r > half) {
        if (prod < 0) { q = q - 1; }
        else { q = q + 1; }
    } else if (r == half) {
         q_half = q / 2;
        if (q != (q_half * 2)) {
            if (prod < 0) { q = q - 1; }
            else { q = q + 1; }
        }
    }
    return q;
}
long long _eq_fixed_div(long long a, long long b) {
    volatile long long half = 0;
    volatile long long num = 0;
    volatile long long q = 0;
    volatile long long q_half = 0;
    volatile long long r = 0;
    volatile long long scale = 0;

     scale = _eq_FIXED_SCALE();
     num = a * scale;
     q = num / b;
     r = num - (q * b);
    if (r < 0) { r = 0 - r; }
     half = 0;
    if (b < 0) { half = (0 - b) / 2; }
    else { half = b / 2; }
    if (r > half) {
        if ((num < 0 && b > 0) || (num > 0 && b < 0)) { q = q - 1; }
        else { q = q + 1; }
    } else if (r == half) {
         q_half = q / 2;
        if (q != (q_half * 2)) {
            if ((num < 0 && b > 0) || (num > 0 && b < 0)) { q = q - 1; }
            else { q = q + 1; }
        }
    }
    return q;
}
long long _eq_fixed_to_str(long long n) {
    volatile long long f = 0;
    volatile long long f_str = 0;
    volatile long long i = 0;
    volatile long long i_str = 0;
    volatile long long s = 0;
    volatile long long scale = 0;

     s = ((long long)"");
    if (n < 0) {
        s = ((long long)"-");
        n = 0 - n;
    }
     scale = 0;
    scale = _eq_FIXED_SCALE();
     i = 0;
    i = n / scale;
     f = 0;
    f = n - (i * scale);
     i_str = 0;
    i_str = _eq_str_from_int(i);
    s = _eq_str_concat(s, i_str);
    s = _eq_str_concat(s, ((long long)"."));
    if (f < 100000) { s = _eq_str_concat(s, ((long long)"0")); }
    if (f < 10000) { s = _eq_str_concat(s, ((long long)"0")); }
    if (f < 1000) { s = _eq_str_concat(s, ((long long)"0")); }
    if (f < 100) { s = _eq_str_concat(s, ((long long)"0")); }
    if (f < 10) { s = _eq_str_concat(s, ((long long)"0")); }
     f_str = 0;
    f_str = _eq_str_from_int(f);
    s = _eq_str_concat(s, f_str);
    return s;
}
long long _eq_print_fixed(long long n) {
    volatile long long s = 0;
    volatile long long slen = 0;

     s = 0;
    s = _eq_fixed_to_str(n);
     slen = 0;
    slen = sys_strlen(s);
    if (slen > 0) {
        (void)!write(1, (void*)s, (size_t)slen);
    }
    sys_free(s);
}
long long _eq_json_new() {
 return _eq_map_new(20); }
long long _eq_json_put_str(long long m, long long k, long long v) {
 _eq_map_put(m, k, _eq_json_item_str(v)); }
long long _eq_json_put_int(long long m, long long k, long long v) {
 _eq_map_put(m, k, _eq_json_item_int(v)); }
long long _eq_json_put_obj(long long m, long long k, long long v) {
 _eq_map_put(m, k, _eq_json_item_obj(v)); }
long long _eq_json_put_array(long long m, long long k, long long v) {
 _eq_map_put(m, k, _eq_json_item_array(v)); }
long long _eq_json_item_str(long long v) {
    volatile long long n = 0;
  n = sys_malloc(2 * 8); ((long long*)(n))[0] = _eq_g_JSON_TYPE_STRING; ((long long*)(n))[1] = v; return n; }
long long _eq_json_item_int(long long v) {
    volatile long long n = 0;
  n = sys_malloc(2 * 8); ((long long*)(n))[0] = _eq_g_JSON_TYPE_INT; ((long long*)(n))[1] = v; return n; }
long long _eq_json_item_obj(long long v) {
    volatile long long n = 0;
  n = sys_malloc(2 * 8); ((long long*)(n))[0] = _eq_g_JSON_TYPE_OBJECT; ((long long*)(n))[1] = v; return n; }
long long _eq_json_item_array(long long v) {
    volatile long long n = 0;
  n = sys_malloc(2 * 8); ((long long*)(n))[0] = _eq_g_JSON_TYPE_ARRAY; ((long long*)(n))[1] = v; return n; }
long long _eq_json_serialize_value(long long item) {
    volatile long long i = 0;
    volatile long long n = 0;
    volatile long long s = 0;
    volatile long long type = 0;
    volatile long long val = 0;

    if (item == 0) { return ((long long)"null"); }
     type = ((long long*)(item))[0];
     val = ((long long*)(item))[1];
    if (type == _eq_g_JSON_TYPE_STRING) { return _eq_str_concat(((long long)"\""), _eq_str_concat(val, ((long long)"\""))); }
    if (type == _eq_g_JSON_TYPE_INT) { return _eq_str_from_int(val); }
    if (type == _eq_g_JSON_TYPE_OBJECT) { return _eq_json_serialize(val); }
    if (type == _eq_g_JSON_TYPE_ARRAY) {
         s = ((long long)"[");
         i = 0;  n = _eq_vec_size(val);
        while (i < n) {
            s = _eq_str_concat(s, _eq_json_serialize_value(_eq_vec_get(val, i)));
            if (i < n - 1) { s = _eq_str_concat(s, ((long long)",")); }
            i = i + 1;
        }
        return _eq_str_concat(s, ((long long)"]"));
    }
    return ((long long)"null");
}
long long _eq_json_serialize(long long m) {
    volatile long long i = 0;
    volatile long long k = 0;
    volatile long long keys = 0;
    volatile long long s = 0;
    volatile long long size = 0;
    volatile long long v = 0;

     s = ((long long)"{");
     keys = _eq_map_keys(m);
     i = 0;  size = _eq_vec_size(keys);
    while (i < size) {
         k = _eq_vec_get(keys, i);
         v = _eq_map_get(m, k);
        s = _eq_str_concat(s, ((long long)"\""));
        s = _eq_str_concat(s, k);
        s = _eq_str_concat(s, ((long long)"\":"));
        s = _eq_str_concat(s, _eq_json_serialize_value(v));
        if (i < size - 1) { s = _eq_str_concat(s, ((long long)",")); }
        i = i + 1;
    }
    return _eq_str_concat(s, ((long long)"}"));
}
long long _eq_json_parse(long long s) {
    volatile long long c = 0;
    volatile long long current_key = 0;
    volatile long long finished = 0;
    volatile long long i = 0;
    volatile long long is_quoted = 0;
    volatile long long k = 0;
    volatile long long k2 = 0;
    volatile long long k_len = 0;
    volatile long long k_start = 0;
    volatile long long m = 0;
    volatile long long n = 0;
    volatile long long state = 0;
    volatile long long v_len = 0;
    volatile long long v_start = 0;
    volatile long long val = 0;

     m = 0;
    m = _eq_map_new(20);
     n = 0;
    n = sys_strlen(s);
     i = 0;
     state = 0;
     k_start = 0;
     v_start = 0;
     current_key = 0;
     is_quoted = 0;
    while (i < n) {
         c = 0;
        c = get_char(s, i);
        if (state == 0) {
            if (c == 34) { k_start = i + 1; state = 1; }
        }
        else if (state == 1) {
            if (c == 34) {
                 k_len = 0;
                k_len = i - k_start;
                current_key = sys_malloc(k_len + 1);
                 k = 0;
                while (k < k_len) {
                    set_char(current_key, k, get_char(s, k_start + k));
                    k = k + 1;
                }
                set_char(current_key, k_len, 0);
                state = 2;
            }
        }
        else if (state == 2) {
            if (c == 58) { state = 3; }
        }
        else if (state == 3) {
            if (c != 32) {
                if (c == 34) { is_quoted = 1; v_start = i + 1; }
                else { is_quoted = 0; v_start = i; }
                state = 4;
            }
        }
        else if (state == 4) {
             finished = 0;
            if (is_quoted) { if (c == 34) { finished = 1; } }
            else {
                if (c == 44) { finished = 1; }
                if (c == 125) { finished = 1; }
                if (c == 32) { finished = 1; }
            }
            if (finished) {
                 v_len = 0;
                v_len = i - v_start;
                 val = 0;
                val = sys_malloc(v_len + 1);
                 k2 = 0;
                while (k2 < v_len) {
                    set_char(val, k2, get_char(s, v_start + k2));
                    k2 = k2 + 1;
                }
                set_char(val, v_len, 0);
                _eq_map_put(m, current_key, val);
                state = 0;
            }
        }
        i = i + 1;
    }
    return m;
}
long long _eq_json_get_int(long long m, long long k) {
    volatile long long s = 0;

     s = 0;
    s = _eq_map_get(m, k);
    if (s == 0) { return 0; }
    return _eq_str_to_int_internal(s);
}
long long _eq_json_get_str(long long m, long long k) {
 return _eq_map_get(m, k); }
long long _eq_str_to_int_internal(long long s) {
    volatile long long c = 0;
    volatile long long i = 0;
    volatile long long res = 0;
    volatile long long sign = 0;

    if (s == 0) { return 0; }
     res = 0;
     i = 0;
     sign = 1;
    if (get_char(s, 0) == 45) { sign = -1; i = 1; }
    while (get_char(s, i) != 0) {
         c = 0;
        c = get_char(s, i);
        if (c >= 48) { if (c <= 57) { res = (res * 10) + (c - 48); } }
        i = i + 1;
    }
    return res * sign;
}
long long _eq_ledger_new() {
    volatile long long l = 0;
    volatile long long m0 = 0;
    volatile long long m1 = 0;

     l = 0;
    l = sys_malloc(3 * 16);
     m0 = 0;
    m0 = _eq_map_new(100);
    ((long long*)(l))[0] = m0;
     m1 = 0;
    m1 = _eq_map_new(100);
    ((long long*)(l))[1] = m1;
    return l;
}
long long _eq_ledger_get_key(long long agent_name, long long res_name, long long currency) {
    volatile long long k = 0;
    volatile long long k2 = 0;
    volatile long long res_k = 0;

     k = 0;
    k = _eq_str_concat(agent_name, ((long long)":"));
    k = _eq_str_concat(k, res_name);
    if (currency == 0) { return k; }
     k2 = 0;
    k2 = _eq_str_concat(k, ((long long)":"));
     res_k = 0;
    res_k = _eq_str_concat(k2, currency);
    return res_k;
}
long long _eq_ledger_update_temporal(long long l, long long agent, long long res, long long currency, long long delta, long long effective_date) {
    volatile long long current = 0;
    volatile long long daily_map = 0;
    volatile long long date_s = 0;
    volatile long long key = 0;
    volatile long long main_map = 0;
    volatile long long val = 0;

     main_map = 0;
    main_map = ((long long*)(l))[0];
     date_s = 0;
    date_s = _eq_str_from_int(effective_date);
     daily_map = 0;
    daily_map = _eq_map_get(main_map, date_s);
    if (daily_map == 0) {
        daily_map = _eq_map_new(50);
        _eq_map_put(main_map, date_s, daily_map);
    }
     key = 0;
    key = _eq_ledger_get_key(agent, res, currency);
     current = 0;
    current = _eq_map_get(daily_map, key);
    if (current == 0) {
        _eq_map_put(daily_map, key, delta);
    } else {
         val = 0;
        val = _eq_fixed_add(current, delta);
        _eq_map_put(daily_map, key, val);
    }
}
long long _eq_ledger_process_flow(long long l, long long flow_type, long long amount, long long res, long long currency, long long from_agent, long long to_agent, long long effective_date) {
    volatile long long entry_from = 0;
    volatile long long entry_to = 0;
    volatile long long f_amount = 0;
    volatile long long hist_map = 0;
    volatile long long neg_amount = 0;
    volatile long long v_from = 0;
    volatile long long v_to = 0;

     f_amount = 0;
    f_amount = _eq_fixed_from_int(amount);
    _eq_ledger_update_temporal(l, to_agent, res, currency, f_amount, effective_date);
     neg_amount = 0;
    neg_amount = _eq_fixed_sub(0, f_amount);
    _eq_ledger_update_temporal(l, from_agent, res, currency, neg_amount, effective_date);
     hist_map = 0;
    hist_map = ((long long*)(l))[1];
     v_to = 0;
    v_to = _eq_map_get(hist_map, to_agent);
    if (v_to == 0) {
        v_to = _eq_vec_new(100);
        _eq_map_put(hist_map, to_agent, v_to);
    }
     entry_to = 0;
    entry_to = sys_malloc(4 * 16);
    ((long long*)(entry_to))[0] = effective_date;
    ((long long*)(entry_to))[1] = f_amount;
    ((long long*)(entry_to))[2] = from_agent;
    ((long long*)(entry_to))[3] = 1;
    _eq_vec_push(v_to, entry_to);
     v_from = 0;
    v_from = _eq_map_get(hist_map, from_agent);
    if (v_from == 0) {
        v_from = _eq_vec_new(100);
        _eq_map_put(hist_map, from_agent, v_from);
    }
     entry_from = 0;
    entry_from = sys_malloc(4 * 16);
    ((long long*)(entry_from))[0] = effective_date;
    ((long long*)(entry_from))[1] = f_amount;
    ((long long*)(entry_from))[2] = to_agent;
    ((long long*)(entry_from))[3] = 0;
    _eq_vec_push(v_from, entry_from);
}
long long _eq_ledger_balance_at(long long l, long long agent, long long res, long long currency, long long target_date) {
    volatile long long d = 0;
    volatile long long d_s = 0;
    volatile long long daily_map = 0;
    volatile long long dates = 0;
    volatile long long i = 0;
    volatile long long key = 0;
    volatile long long main_map = 0;
    volatile long long size = 0;
    volatile long long total = 0;
    volatile long long val = 0;

     total = 0;
    total = _eq_fixed_from_int(0);
     main_map = 0;
    main_map = ((long long*)(l))[0];
     dates = 0;
    dates = _eq_map_keys(main_map);
     i = 0;
     size = 0;
    size = _eq_vec_size(dates);
    while (i < size) {
         d_s = 0;
        d_s = _eq_vec_get(dates, i);
         d = 0;
        d = str_to_int(d_s);
        if (d <= target_date) {
             daily_map = 0;
            daily_map = _eq_map_get(main_map, d_s);
             key = 0;
            key = _eq_ledger_get_key(agent, res, currency);
             val = 0;
            val = _eq_map_get(daily_map, key);
            if (val != 0) {
                total = _eq_fixed_add(total, val);
            }
        }
        i = i + 1;
    }
    return total;
}
long long _eq_ledger_get_entries_for(long long l, long long agent) {
    volatile long long empty = 0;
    volatile long long hist_map = 0;
    volatile long long v = 0;

     hist_map = 0;
    hist_map = ((long long*)(l))[1];
     v = 0;
    v = _eq_map_get(hist_map, agent);
    if (v == 0) {
         empty = 0;
        empty = _eq_vec_new(1);
        return empty;
    }
    return v;
}
long long _eq_accounting_init(long long base_res, long long base_cur) {
    volatile long long l = 0;
    volatile long long m = 0;
    volatile long long sys = 0;

     sys = 0;
    sys = sys_malloc(4 * 16);
     l = 0;
    l = _eq_ledger_new();
    ((long long*)(sys))[0] = l;
    ((long long*)(sys))[1] = base_res;
    ((long long*)(sys))[2] = base_cur;
     m = 0;
    m = _eq_map_new(50);
    ((long long*)(sys))[3] = m;
    return sys;
}
long long _eq_acct_register(long long sys, long long name, long long type, long long code) {
    volatile long long code_s = 0;
    volatile long long m = 0;
    volatile long long meta = 0;

     m = 0;
    m = ((long long*)(sys))[3];
     meta = 0;
    meta = sys_malloc(2 * 16);
    ((long long*)(meta))[0] = name;
    ((long long*)(meta))[1] = type;
     code_s = 0;
    code_s = _eq_str_from_int(code);
    _eq_map_put(m, code_s, meta);
}
long long _eq_journal_entry(long long acct_sys, long long amount, long long res, long long cur, long long from_acc, long long to_acc, long long date) {
    volatile long long l = 0;

     l = 0;
    l = ((long long*)(acct_sys))[0];
    _eq_ledger_process_flow(l, 0, amount, res, cur, from_acc, to_acc, date);
}
long long _eq_report_income_statement(long long acct_sys, long long rev_acc, long long exp_acc, long long target_date) {
    volatile long long cur = 0;
    volatile long long exp = 0;
    volatile long long l = 0;
    volatile long long res = 0;
    volatile long long rev = 0;

     l = 0;
    l = ((long long*)(acct_sys))[0];
     res = ((long long*)(acct_sys))[1];
     cur = ((long long*)(acct_sys))[2];
     rev = 0;
    rev = _eq_ledger_balance_at(l, rev_acc, res, cur, target_date);
     exp = 0;
    exp = _eq_ledger_balance_at(l, exp_acc, res, cur, target_date);
    return _eq_fixed_sub(rev, exp);
}
long long _eq_report_balance_sheet(long long acct_sys, long long asset_acc, long long liab_acc, long long equity_acc, long long target_date) {
    volatile long long assets = 0;
    volatile long long cur2 = 0;
    volatile long long equity = 0;
    volatile long long l = 0;
    volatile long long liab = 0;
    volatile long long m = 0;
    volatile long long res2 = 0;

     l = 0;
    l = ((long long*)(acct_sys))[0];
     m = 0;
    m = _eq_map_new(5);
     res2 = ((long long*)(acct_sys))[1];
     cur2 = ((long long*)(acct_sys))[2];
     assets = 0;
    assets = _eq_ledger_balance_at(l, asset_acc, res2, cur2, target_date);
     liab = 0;
    liab = _eq_ledger_balance_at(l, liab_acc, res2, cur2, target_date);
     equity = 0;
    equity = _eq_ledger_balance_at(l, equity_acc, res2, cur2, target_date);
    _eq_map_put(m, ((long long)"assets"), assets);
    _eq_map_put(m, ((long long)"liabilities"), liab);
    _eq_map_put(m, ((long long)"equity"), equity);
    return m;
}
long long _eq_lexer_is_digit(long long c) {

    return c >= 48 && c <= 57;
}
long long _eq_lexer_is_alpha(long long c) {

    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95;
}
long long _eq_lexer_is_alpha_numeric(long long c) {

    return _eq_lexer_is_alpha(c) || _eq_lexer_is_digit(c);
}
long long _eq_lexer_new(long long source, long long filename) {
    volatile long long lex = 0;

     lex = 0;
    lex = sys_malloc(8 * 8); 
    ((long long*)(lex))[0] = source;
    ((long long*)(lex))[1] = 0;
    ((long long*)(lex))[2] = 0;
    ((long long*)(lex))[3] = 1; 
    ((long long*)(lex))[4] = _eq_vec_new(200000);
    ((long long*)(lex))[5] = sys_strlen(source);
    ((long long*)(lex))[6] = 1; 
    ((long long*)(lex))[7] = filename;
    return lex;
}
long long _eq_lexer_is_at_end(long long lex) {

    return ((long long*)(lex))[2] >= ((long long*)(lex))[5];
}
long long _eq_lexer_peek(long long lex) {

    if (_eq_lexer_is_at_end(lex)) { return 0; }
    return get_char(((long long*)(lex))[0], ((long long*)(lex))[2]);
}
long long _eq_lexer_peek_next(long long lex) {

    if (((long long*)(lex))[2] + 1 >= ((long long*)(lex))[5]) { return 0; }
    return get_char(((long long*)(lex))[0], ((long long*)(lex))[2] + 1);
}
long long _eq_lexer_advance(long long lex) {
    volatile long long c = 0;

     c = 0;
    c = get_char(((long long*)(lex))[0], ((long long*)(lex))[2]);
    ((long long*)(lex))[2] = ((long long*)(lex))[2] + 1;
    if (c == 10) {
        ((long long*)(lex))[3] = ((long long*)(lex))[3] + 1;
        ((long long*)(lex))[6] = 1;
    } else {
        ((long long*)(lex))[6] = ((long long*)(lex))[6] + 1;
    }
    return c;
}
long long _eq_lexer_match(long long lex, long long expected) {
    volatile long long c = 0;

    if (_eq_lexer_is_at_end(lex)) { return 0; }
    if (get_char(((long long*)(lex))[0], ((long long*)(lex))[2]) != expected) { return 0; }
     c = get_char(((long long*)(lex))[0], ((long long*)(lex))[2]);
    ((long long*)(lex))[2] = ((long long*)(lex))[2] + 1;
    if (c == 10) {
        ((long long*)(lex))[3] = ((long long*)(lex))[3] + 1;
        ((long long*)(lex))[6] = 1;
    } else {
        ((long long*)(lex))[6] = ((long long*)(lex))[6] + 1;
    }
    return 1;
}
long long _eq_token_new(long long type, long long lexeme, long long line, long long col) {
    volatile long long tok = 0;

     tok = 0;
    tok = sys_malloc(4 * 8); 
    ((long long*)(tok))[0] = type;
    ((long long*)(tok))[1] = lexeme;
    ((long long*)(tok))[2] = line;
    ((long long*)(tok))[3] = col;
    return tok;
}
long long _eq_lexer_get_lexeme(long long lex) {
    volatile long long current = 0;
    volatile long long i = 0;
    volatile long long len = 0;
    volatile long long res = 0;
    volatile long long start = 0;

     start = 0;
     current = 0;
     len = 0;
     res = 0;
     i = 0;
    start = ((long long*)(lex))[1];
    current = ((long long*)(lex))[2];
    len = current - start;
    res = sys_malloc(len + 1);
    i = 0;
    while (i < len) {
        set_char(res, i, get_char(((long long*)(lex))[0], start + i));
        i = i + 1;
    }
    set_char(res, len, 0);
    return res;
}
long long _eq_lexer_add_token(long long lex, long long type, long long lexeme) {
    volatile long long col_at_start = 0;
    volatile long long tok = 0;

     tok = 0;
     col_at_start = 0;
    col_at_start = ((long long*)(lex))[6] - (((long long*)(lex))[2] - ((long long*)(lex))[1]);
    if (col_at_start < 1) { col_at_start = 1; }
    tok = _eq_token_new(type, lexeme, ((long long*)(lex))[3], col_at_start);
    ((long long*)(lex))[4] = _eq_vec_push(((long long*)(lex))[4], tok);
}
long long _eq_lexer_add_token_type(long long lex, long long type) {

    _eq_lexer_add_token(lex, type, _eq_lexer_get_lexeme(lex));
}
long long _eq_lexer_identifier(long long lex) {
    volatile long long text = 0;
    volatile long long type = 0;

     text = 0;
     type = 0;
    while (_eq_lexer_is_alpha_numeric(_eq_lexer_peek(lex))) { _eq_lexer_advance(lex); }
    text = _eq_intern_string(_eq_lexer_get_lexeme(lex));
    type = _eq_g_TOKEN_IDENTIFIER;
    if (_eq_str_equal(text, ((long long)"if"))) { type = _eq_g_TOKEN_IF; }
    else if (_eq_str_equal(text, ((long long)"else"))) { type = _eq_g_TOKEN_ELSE; }
    else if (_eq_str_equal(text, ((long long)"while"))) { type = _eq_g_TOKEN_WHILE; }
    else if (_eq_str_equal(text, ((long long)"let"))) { type = _eq_g_TOKEN_LET; }
    else if (_eq_str_equal(text, ((long long)"mut"))) { type = _eq_g_TOKEN_MUT; }
    else if (_eq_str_equal(text, ((long long)"resource"))) { type = _eq_g_TOKEN_RESOURCE; }
    else if (_eq_str_equal(text, ((long long)"fn"))) { type = _eq_g_TOKEN_FN; }
    else if (_eq_str_equal(text, ((long long)"return"))) { type = _eq_g_TOKEN_RETURN; }
    else if (_eq_str_equal(text, ((long long)"print"))) { type = _eq_g_TOKEN_PRINT; }
    else if (_eq_str_equal(text, ((long long)"use"))) { type = _eq_g_TOKEN_USE; }
    else if (_eq_str_equal(text, ((long long)"extern"))) { type = _eq_g_TOKEN_EXTERN; }
    else if (_eq_str_equal(text, ((long long)"struct"))) { type = _eq_g_TOKEN_STRUCT; }
    else if (_eq_str_equal(text, ((long long)"Agent"))) { type = _eq_g_TOKEN_AGENT; }
    else if (_eq_str_equal(text, ((long long)"Resource"))) { type = _eq_g_TOKEN_RESOURCE; }
    else if (_eq_str_equal(text, ((long long)"Event"))) { type = _eq_g_TOKEN_EVENT; }
    else if (_eq_str_equal(text, ((long long)"Commitment"))) { type = _eq_g_TOKEN_COMMITMENT; }
    else if (_eq_str_equal(text, ((long long)"Policy"))) { type = _eq_g_TOKEN_POLICY; }
    else if (_eq_str_equal(text, ((long long)"Valuator"))) { type = _eq_g_TOKEN_VALUATOR; }
    else if (_eq_str_equal(text, ((long long)"exchange"))) { type = _eq_g_TOKEN_EXCHANGE; }
    else if (_eq_str_equal(text, ((long long)"transformation"))) { type = _eq_g_TOKEN_TRANSFORMATION; }
    else if (_eq_str_equal(text, ((long long)"execute"))) { type = _eq_g_TOKEN_EXECUTE; }
    else if (_eq_str_equal(text, ((long long)"reverse"))) { type = _eq_g_TOKEN_REVERSE; }
    else if (_eq_str_equal(text, ((long long)"assert"))) { type = _eq_g_TOKEN_ASSERT; }
    else if (_eq_str_equal(text, ((long long)"flow"))) { type = _eq_g_TOKEN_FLOW; }
    else if (_eq_str_equal(text, ((long long)"in"))) { type = _eq_g_TOKEN_IN; }
    else if (_eq_str_equal(text, ((long long)"out"))) { type = _eq_g_TOKEN_OUT; }
    else if (_eq_str_equal(text, ((long long)"from"))) { type = _eq_g_TOKEN_FROM; }
    else if (_eq_str_equal(text, ((long long)"to"))) { type = _eq_g_TOKEN_TO; }
    else if (_eq_str_equal(text, ((long long)"roles"))) { type = _eq_g_TOKEN_ROLES; }
    else if (_eq_str_equal(text, ((long long)"fulfills"))) { type = _eq_g_TOKEN_FULFILLS; }
    else if (_eq_str_equal(text, ((long long)"evaluated_by"))) { type = _eq_g_TOKEN_EVALUATED_BY; }
    else if (_eq_str_equal(text, ((long long)"logic"))) { type = _eq_g_TOKEN_LOGIC; }
    else if (_eq_str_equal(text, ((long long)"interface"))) { type = _eq_g_TOKEN_INTERFACE; }
    else if (_eq_str_equal(text, ((long long)"implements"))) { type = _eq_g_TOKEN_IMPLEMENTS; }
    else if (_eq_str_equal(text, ((long long)"f64"))) { type = _eq_g_TOKEN_F64; }
    else if (_eq_str_equal(text, ((long long)"bool"))) { type = _eq_g_TOKEN_BOOL; }
    else if (_eq_str_equal(text, ((long long)"i64"))) { type = _eq_g_TOKEN_I64; }
    else if (_eq_str_equal(text, ((long long)"enum"))) { type = _eq_g_TOKEN_ENUM; }
    else if (_eq_str_equal(text, ((long long)"match"))) { type = _eq_g_TOKEN_MATCH; }
    _eq_lexer_add_token(lex, type, text);
}
long long _eq_lexer_number(long long lex) {
    volatile long long lexeme = 0;

     lexeme = 0;
    while (_eq_lexer_is_digit(_eq_lexer_peek(lex))) { _eq_lexer_advance(lex); }
    if (_eq_lexer_peek(lex) == 46 && _eq_lexer_is_digit(_eq_lexer_peek_next(lex))) {
        _eq_lexer_advance(lex);
        while (_eq_lexer_is_digit(_eq_lexer_peek(lex))) { _eq_lexer_advance(lex); }
    }
    _eq_lexer_add_token_type(lex, _eq_g_TOKEN_NUMBER);
}
long long _eq_lexer_string(long long lex) {
    long long source = ((long long*)(lex))[0];
    long long res = 0;
    long long next = 0;
    long long c = 0;
    long long capacity = 1024;
    char* buf = malloc(capacity);
    long long dest_i = 0;

    while (_eq_lexer_peek(lex) != 34 && _eq_lexer_is_at_end(lex) == 0) {
        if (dest_i + 4 >= capacity) {
            capacity *= 2;
            buf = realloc(buf, capacity);
        }
        c = _eq_lexer_advance(lex);
        if (c == 10) { ((long long*)(lex))[3]++; }
        
        if (c == '\\') {
            next = _eq_lexer_advance(lex);
            if (next == 'n') { buf[dest_i++] = 10; }
            else if (next == 'r') { buf[dest_i++] = 13; }
            else if (next == 't') { buf[dest_i++] = 9; }
            else if (next == '\"') { buf[dest_i++] = 34; }
            else if (next == '\\') { buf[dest_i++] = 92; }
            else if (next == 'x') {
                int h1 = _eq_lexer_advance(lex);
                int h2 = _eq_lexer_advance(lex);
                int val = 0;
                if (h1 >= '0' && h1 <= '9') val = (h1 - '0') * 16;
                else if (h1 >= 'a' && h1 <= 'f') val = (h1 - 'a' + 10) * 16;
                else if (h1 >= 'A' && h1 <= 'F') val = (h1 - 'A' + 10) * 16;
                if (h2 >= '0' && h2 <= '9') val += (h2 - '0');
                else if (h2 >= 'a' && h2 <= 'f') val += (h2 - 'a' + 10);
                else if (h2 >= 'A' && h2 <= 'F') val += (h2 - 'A' + 10);
                buf[dest_i++] = (char)val;
            } else { buf[dest_i++] = (char)next; }
        } else {
            buf[dest_i++] = (char)c;
        }
    }
    if (_eq_lexer_peek(lex) == 34) { _eq_lexer_advance(lex); }
    buf[dest_i] = 0;
    _eq_lexer_add_token(lex, _eq_g_TOKEN_STRING, (long long)buf);
    return 0;
}
long long _eq_lexer_scan_token(long long lex) {
    volatile long long c = 0;
    volatile long long handled = 0;
    volatile long long space_done = 0;

     c = 0;
     space_done = 0;
    while (space_done == 0) {
        if (_eq_lexer_is_at_end(lex)) { return 0; }
        c = _eq_lexer_peek(lex);
         handled = 0;
        if (c == 32) { _eq_lexer_advance(lex); handled = 1; }
        if (c == 9) { _eq_lexer_advance(lex); handled = 1; }
        if (c == 13) { _eq_lexer_advance(lex); handled = 1; }
        if (c == 10) { _eq_lexer_advance(lex); ((long long*)(lex))[3] = ((long long*)(lex))[3] + 1; handled = 1; }
        if (handled == 0) { space_done = 1; }
    }
    if (_eq_lexer_is_at_end(lex)) { return 0; }
    ((long long*)(lex))[1] = ((long long*)(lex))[2];
    c = _eq_lexer_advance(lex);
    if (c == 40) { _eq_lexer_add_token(lex, _eq_g_TOKEN_LPARENT, ((long long)"(")); }
    else if (c == 41) { _eq_lexer_add_token(lex, _eq_g_TOKEN_RPARENT, ((long long)")")); }
    else if (c == 123) { _eq_lexer_add_token(lex, _eq_g_TOKEN_LBRACE, ((long long)"{")); }
    else if (c == 125) { _eq_lexer_add_token(lex, _eq_g_TOKEN_RBRACE, ((long long)"}")); }
    else if (c == 91) { _eq_lexer_add_token(lex, _eq_g_TOKEN_LBRACKET, ((long long)"[")); }
    else if (c == 93) { _eq_lexer_add_token(lex, _eq_g_TOKEN_RBRACKET, ((long long)"]")); }
    else if (c == 44) { _eq_lexer_add_token(lex, _eq_g_TOKEN_COMMA, ((long long)",")); }
    else if (c == 46) { _eq_lexer_add_token(lex, _eq_g_TOKEN_DOT, ((long long)".")); }
    else if (c == 45) {
        if (_eq_lexer_match(lex, 62)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_ARROW, ((long long)"->")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_MINUS, ((long long)"-")); }
    }
    else if (c == 43) { _eq_lexer_add_token(lex, _eq_g_TOKEN_PLUS, ((long long)"+")); }
    else if (c == 59) { _eq_lexer_add_token(lex, _eq_g_TOKEN_SEMICOLON, ((long long)";")); }
    else if (c == 42) { _eq_lexer_add_token(lex, _eq_g_TOKEN_ASTERISK, ((long long)"*")); }
    else if (c == 37) { _eq_lexer_add_token(lex, _eq_g_TOKEN_PERCENT, ((long long)"%")); }
    else if (c == 63) { _eq_lexer_add_token(lex, _eq_g_TOKEN_QUESTION, ((long long)"?")); }
    else if (c == 33) {
        if (_eq_lexer_match(lex, 61)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_BANG_EQUAL, ((long long)"!=")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_BANG, ((long long)"!")); }
    }
    else if (c == 61) {
        if (_eq_lexer_match(lex, 61)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_EQUAL_EQUAL, ((long long)"==")); }
        else if (_eq_lexer_match(lex, 62)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_FAT_ARROW, ((long long)"=>")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_EQUAL, ((long long)"=")); }
    }
    else if (c == 60) {
        if (_eq_lexer_match(lex, 60)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_LSHIFT, ((long long)"<<")); }
        else if (_eq_lexer_match(lex, 61)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_LESS_EQUAL, ((long long)"<=")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_LESS, ((long long)"<")); }
    }
    else if (c == 62) {
        if (_eq_lexer_match(lex, 61)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_GREATER_EQUAL, ((long long)">=")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_GREATER, ((long long)">")); }
    }
    else if (c == 47) {
        if (_eq_lexer_match(lex, 47)) {
            while (_eq_lexer_peek(lex) != 10 && _eq_lexer_is_at_end(lex) == 0) { _eq_lexer_advance(lex); }
        } else {
            _eq_lexer_add_token(lex, _eq_g_TOKEN_SLASH, ((long long)"/"));
        }
    }
    else if (c == 58) {
        if (_eq_lexer_match(lex, 58)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_COLON_COLON, ((long long)"::")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_COLON, ((long long)":")); }
    }
    else if (c == 124) { 
        if (_eq_lexer_match(lex, 124)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_OR, ((long long)"||")); } 
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_BITOR, ((long long)"|")); } 
    }
    else if (c == 38) {
        if (_eq_lexer_match(lex, 38)) { _eq_lexer_add_token(lex, _eq_g_TOKEN_AND, ((long long)"&&")); }
        else { _eq_lexer_add_token(lex, _eq_g_TOKEN_AMPERSAND, ((long long)"&")); }
    }
    else if (c == 34) { _eq_lexer_string(lex); }
    else if (c == 63) { _eq_lexer_add_token(lex, _eq_g_TOKEN_QUESTION, ((long long)"?")); }
    else if (_eq_lexer_is_alpha(c)) { _eq_lexer_identifier(lex); }
    else if (_eq_lexer_is_digit(c)) { _eq_lexer_number(lex); }
    else {
        (void)!write(2, (void*)((long long)"Unexpected character: "), 22);
        print_char_stderr(c);
        (void)!write(2, (void*)((long long)" (val="), 6);
        print_int_stderr(c);
        (void)!write(2, (void*)((long long)") in file "), 10);
        print_raw_stderr(((long long*)lex)[7]); 
        (void)!write(2, (void*)((long long)" at Line "), 10);
        print_int_stderr(((long long*)lex)[3]);
        (void)!write(2, (void*)((long long)" Col "), 5);
        print_int_stderr(((long long*)lex)[2]);
        (void)!write(2, (void*)((long long)"\n"), 1);
        exit(1);
    }
}
long long _eq_lexer_scan_tokens(long long lex) {

    while (_eq_lexer_is_at_end(lex) == 0) {
        _eq_lexer_scan_token(lex);
    }
    ((long long*)(lex))[1] = ((long long*)(lex))[2];
    _eq_lexer_add_token(lex, _eq_g_TOKEN_EOF, ((long long)""));
    return ((long long*)(lex))[4];
}
long long _eq_intern_string(long long s) {
    volatile long long clone = 0;
    volatile long long existing = 0;
    volatile long long i = 0;
    volatile long long len = 0;

    if (s == 0) { return 0; }
    if (_eq_g___intern_map == 0) {
        _eq_g___intern_map = _eq_map_new(100000);
    }
     existing = _eq_map_get(_eq_g___intern_map, s);
    if (existing) {
        return existing;
    }
     len = _eq_str_len(s);
     clone = sys_malloc(len + 1);
     i = 0;
    while (i < len) {
        set_char(clone, i, get_char(s, i));
        i = i + 1;
    }
    set_char(clone, len, 0);
    sys_pin(clone);
    _eq_map_put(_eq_g___intern_map, clone, clone);
    return clone;
}
long long _eq_intern_cleanup() {
    volatile long long i = 0;
    volatile long long k = 0;
    volatile long long keys = 0;
    volatile long long size = 0;

    if (_eq_g___intern_map == 0) { return 0; }
     keys = _eq_map_keys(_eq_g___intern_map);
     i = 0;
     size = _eq_vec_size(keys);
    while (i < size) {
         k = _eq_vec_get(keys, i);
        
        _eq_sys_release(k);
        i = i + 1;
    }
    _eq_sys_release(keys);
    _eq_sys_release(_eq_g___intern_map);
    _eq_g___intern_map = 0;
}
long long _eq_parser_new(long long tokens) {
    volatile long long p = 0;

     p = 0;
    p = sys_malloc(3 * 8);
    ((long long*)(p))[0] = tokens;
    ((long long*)(p))[1] = 0;
    ((long long*)(p))[2] = _eq_vec_size(tokens);
    return p;
}
long long _eq_parser_is_at_end(long long p) {
    volatile long long tok = 0;
 if (((long long*)(p))[1] >= ((long long*)(p))[2]-1) { return 1; }  tok = _eq_vec_get(((long long*)(p))[0], ((long long*)(p))[1]); if (tok == 0) { return 1; } return ((long long*)(tok))[0] == 0; }
long long _eq__unused_parser_is_at_end(long long p) {
    volatile long long tok = 0;
 
     tok = 0;
    if (((long long*)(p))[1] >= ((long long*)(p))[2]) { return 1; }
    tok = _eq_vec_get(((long long*)(p))[0], ((long long*)(p))[1]);
    return ((long long*)(tok))[0] == _eq_g_TOKEN_EOF;
}
long long _eq_parser_peek(long long p) {
 if (((long long*)(p))[1] >= ((long long*)(p))[2]) { return 0; } return _eq_vec_get(((long long*)(p))[0], ((long long*)(p))[1]); }
long long _eq__unused_parser_peek(long long p) {
 
    return _eq_vec_get(((long long*)(p))[0], ((long long*)(p))[1]);
}
long long _eq_parser_previous(long long p) {

    return _eq_vec_get(((long long*)(p))[0], ((long long*)(p))[1] - 1);
}
long long _eq_parser_advance(long long p) {

    if (_eq_parser_is_at_end(p) == 0) { ((long long*)(p))[1] = ((long long*)(p))[1] + 1; }
    return _eq_parser_previous(p);
}
long long _eq_parser_check(long long p, long long type) {
    volatile long long tok = 0;

     tok = 0;
    if (_eq_parser_is_at_end(p)) { return 0; }
    tok = _eq_parser_peek(p);
    return ((long long*)(tok))[0] == type;
}
long long _eq_parser_match(long long p, long long type) {

    if (_eq_parser_check(p, type)) {
        _eq_parser_advance(p);
        return 1;
    }
    return 0;
}
long long _eq_parser_parse_generics(long long p) {
    volatile long long list = 0;
    volatile long long more = 0;
    volatile long long tok = 0;

    if (_eq_parser_match(p, _eq_g_TOKEN_LESS)) {
         list = _eq_vec_new(32);
         more = 1;
        while (more && _eq_parser_check(p, _eq_g_TOKEN_IDENTIFIER)) {
             tok = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expected generic type identifier"));
            _eq_vec_push(list, ((long long*)(tok))[1]);
            if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) == 0) { more = 0; }
        }
        _eq_parser_consume(p, _eq_g_TOKEN_GREATER, ((long long)"Expected '>' after generic parameters"));
        return list;
    }
    return 0;
}
long long _eq_parser_error(long long p, long long msg) {
    volatile long long tok = 0;

     tok = 0;
    tok = _eq_parser_peek(p);
    char* h1 = "\x1b[1;31merror\x1b[0m\x1b[1m: ";
    (void)!write(2, (void*)h1, strlen(h1));
    (void)!write(2, (void*)msg, strlen((char*)msg));
    (void)!write(2, (void*)"\x1b[0m\n", 5);
    char* h2 = "  \x1b[1;34m-->\x1b[0m line ";
    (void)!write(2, (void*)h2, strlen(h2));
    print_int_stderr(((long long*)(tok))[2]);
    (void)!write(2, (void*)":", 1);
    print_int_stderr(((long long*)(tok))[3]);
    (void)!write(2, (void*)"\n", 1);
    (void)!write(2, (void*)"   \x1b[1;34m|\x1b[0m\n", 10);
    char* h3 = "   \x1b[1;34m|\x1b[0m Found lexeme '\x1b[1;33m";
    (void)!write(2, (void*)h3, strlen(h3));
    (void)!write(2, (void*)(((long long*)(tok))[1]), (size_t)sys_strlen(((long long*)(tok))[1]));
    (void)!write(2, (void*)((long long)"\x1b[0m' (type "), 11);
    print_int_stderr(((long long*)(tok))[0]);
    (void)!write(2, (void*)((long long)")\n"), 2);
    (void)!write(2, (void*)((long long)"   \x1b[1;34m|\x1b[0m\n\n"), 10);
    exit(1);
}
long long _eq_parser_consume(long long p, long long type, long long msg) {
    if (_eq_parser_check(p, type)) { return _eq_parser_advance(p); }
    _eq_parser_error(p, msg);
}
long long _eq_expr_binary(long long left, long long op, long long right, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(6 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_BINARY;
    ((long long*)(node))[_eq_g_BINARY_LEFT] = left;
    ((long long*)(node))[_eq_g_BINARY_OP] = op;
    ((long long*)(node))[_eq_g_BINARY_RIGHT] = right;
    ((long long*)(node))[_eq_g_BINARY_LINE] = line;
    ((long long*)(node))[_eq_g_BINARY_COL] = col;
    return node;
}
long long _eq_expr_literal(long long val, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_LITERAL;
    ((long long*)(node))[_eq_g_LITERAL_VAL] = val;
    ((long long*)(node))[_eq_g_LITERAL_LINE] = line;
    ((long long*)(node))[_eq_g_LITERAL_COL] = col;
    return node;
}
long long _eq_expr_string_literal(long long val, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_STRING_LITERAL;
    ((long long*)(node))[_eq_g_LITERAL_VAL] = val;
    ((long long*)(node))[_eq_g_LITERAL_LINE] = line;
    ((long long*)(node))[_eq_g_LITERAL_COL] = col;
    return node;
}
long long _eq_expr_variable(long long name, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_VARIABLE;
    ((long long*)(node))[_eq_g_VAR_NAME] = name;
    ((long long*)(node))[_eq_g_VAR_LINE] = line;
    ((long long*)(node))[_eq_g_VAR_COL] = col;
    return node;
}
long long _eq_expr_call(long long callee, long long args, long long line, long long col, long long generics) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(6 * 8); 
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_CALL;
    ((long long*)(node))[_eq_g_CALL_CALLEE] = callee;
    ((long long*)(node))[_eq_g_CALL_ARGS] = args;
    ((long long*)(node))[_eq_g_CALL_LINE] = line;
    ((long long*)(node))[_eq_g_CALL_COL] = col;
    ((long long*)(node))[_eq_g_CALL_GENERICS] = generics;
    return node;
}
long long _eq_expr_try(long long expr, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_TRY;
    ((long long*)(node))[1] = expr;
    ((long long*)(node))[2] = line;
    ((long long*)(node))[3] = col;
    return node;
}
long long _eq_expr_index(long long obj, long long idx, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_INDEX;
    ((long long*)(node))[_eq_g_INDEX_OBJ] = obj;
    ((long long*)(node))[_eq_g_INDEX_IDX] = idx;
    ((long long*)(node))[_eq_g_INDEX_LINE] = line;
    ((long long*)(node))[_eq_g_INDEX_COL] = col;
    return node;
}
long long _eq_expr_assignment(long long target, long long value, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_ASSIGNMENT;
    ((long long*)(node))[_eq_g_ASSIGN_TARGET] = target;
    ((long long*)(node))[_eq_g_ASSIGN_VALUE] = value;
    ((long long*)(node))[_eq_g_ASSIGN_LINE] = line;
    ((long long*)(node))[_eq_g_ASSIGN_COL] = col;
    return node;
}
long long _eq_expr_get(long long object, long long name, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_GET;
    ((long long*)(node))[_eq_g_GET_OBJ] = object;
    ((long long*)(node))[_eq_g_GET_NAME] = name;
    ((long long*)(node))[_eq_g_GET_LINE] = line;
    ((long long*)(node))[_eq_g_GET_COL] = col;
    return node;
}
long long _eq_stmt_expression(long long expr, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_EXPRESSION;
    ((long long*)(node))[1] = expr;
    ((long long*)(node))[2] = line;
    ((long long*)(node))[3] = col;
    return node;
}
long long _eq_stmt_let(long long name, long long value, long long type, long long line, long long col, long long is_mut, long long is_res) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(8 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_LET;
    ((long long*)(node))[_eq_g_LET_NAME] = name;
    ((long long*)(node))[_eq_g_LET_VAL] = value;
    ((long long*)(node))[_eq_g_LET_TYPE] = type;
    ((long long*)(node))[_eq_g_LET_LINE] = line;
    ((long long*)(node))[_eq_g_LET_COL] = col;
    ((long long*)(node))[_eq_g_LET_IS_MUT] = is_mut;
    ((long long*)(node))[_eq_g_LET_IS_RESOURCE] = is_res;
    return node;
}
long long _eq_stmt_if(long long cond, long long then, long long els, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(6 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_IF;
    ((long long*)(node))[_eq_g_IF_COND] = cond;
    ((long long*)(node))[_eq_g_IF_THEN] = then;
    ((long long*)(node))[_eq_g_IF_ELSE] = els;
    ((long long*)(node))[_eq_g_IF_LINE] = line;
    ((long long*)(node))[_eq_g_IF_COL] = col;
    return node;
}
long long _eq_stmt_while(long long cond, long long body, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_WHILE;
    ((long long*)(node))[_eq_g_WHILE_COND] = cond;
    ((long long*)(node))[_eq_g_WHILE_BODY] = body;
    ((long long*)(node))[_eq_g_WHILE_LINE] = line;
    ((long long*)(node))[_eq_g_WHILE_COL] = col;
    return node;
}
long long _eq_stmt_return(long long val, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_RETURN;
    ((long long*)(node))[1] = val;
    ((long long*)(node))[2] = line;
    ((long long*)(node))[3] = col;
    return node;
}
long long _eq_stmt_block(long long stmts, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_BLOCK;
    ((long long*)(node))[1] = stmts;
    ((long long*)(node))[2] = line;
    ((long long*)(node))[3] = col;
    return node;
}
long long _eq_stmt_print(long long expr, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_PRINT;
    ((long long*)(node))[1] = expr;
    ((long long*)(node))[2] = line;
    ((long long*)(node))[3] = col;
    return node;
}
long long _eq_stmt_interface(long long name, long long methods, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_INTERFACE;
    ((long long*)(node))[1] = name;
    ((long long*)(node))[2] = methods;
    ((long long*)(node))[3] = line;
    ((long long*)(node))[4] = col;
    return node;
}
long long _eq_stmt_function(long long name, long long params, long long body, long long line, long long col, long long generics, long long param_types, long long return_type, long long params_mut) {
    long long* node = 0;
    node = (long long*)_eq_sys_malloc(10 * 8);
    node[0] = _eq_g_STMT_FUNCTION;
    node[_eq_g_FUNC_NAME] = name;
    node[_eq_g_FUNC_PARAMS] = params;
    node[_eq_g_FUNC_BODY] = body;
    node[_eq_g_FUNC_LINE] = line;
    node[_eq_g_FUNC_COL] = col;
    node[_eq_g_FUNC_GENERICS] = generics;
    node[_eq_g_FUNC_PARAMS_TYPES] = param_types;
    node[_eq_g_FUNC_RETURN_TYPE] = return_type;
    node[_eq_g_FUNC_PARAMS_MUT] = params_mut;
    return (long long)node;
}
long long _eq_stmt_extern(long long name, long long params, long long line, long long col) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_EXTERN;
    ((long long*)(node))[1] = name;
    ((long long*)(node))[2] = params;
    ((long long*)(node))[3] = line;
    ((long long*)(node))[4] = col;
    return node;
}
long long _eq_stmt_struct(long long name, long long fields, long long line, long long col, long long generics) {
    volatile long long node = 0;

     node = 0;
    node = sys_malloc(6 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_STRUCT;
    ((long long*)(node))[_eq_g_STRUCT_NAME] = name;
    ((long long*)(node))[_eq_g_STRUCT_BODY] = fields;
    ((long long*)(node))[_eq_g_STRUCT_LINE] = line;
    ((long long*)(node))[_eq_g_STRUCT_COL] = col;
    ((long long*)(node))[_eq_g_STRUCT_GENERICS] = generics;
    return node;
}
long long _eq_parse_primary(long long p) {
    volatile long long expr = 0;
    volatile long long tok = 0;

     expr = 0;
     tok = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_NUMBER)) {
        tok = _eq_parser_previous(p);
        char* s = (char*)((long long*)(tok))[1];
        long long res = 0;
        int has_dot = 0;
        for (int i = 0; s[i]; i++) if (s[i] == '.') has_dot = 1;
        if (has_dot) {
            long long integer_part = 0;
            int i = 0;
            long long sign = 1;
            if (s[0] == '-') { sign = -1; i = 1; }
            while (s[i] && s[i] != '.') {
                if (s[i] >= '0' && s[i] <= '9') integer_part = (integer_part * 10) + (s[i] - '0');
                i++;
            }
            res = integer_part * 1000000;
            if (s[i] == '.') {
                i++;
                long long frac_val = 0;
                long long frac_scale = 100000;
                while (s[i] && frac_scale > 0) {
                    if (s[i] >= '0' && s[i] <= '9') {
                        frac_val += (s[i] - '0') * frac_scale;
                        frac_scale /= 10;
                    }
                    i++;
                }
                res += frac_val;
            }
            res *= sign;
        } else {
            res = atoll(s);
        }
        return _eq_expr_literal(res, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    if (_eq_parser_match(p, _eq_g_TOKEN_STRING)) {
        tok = _eq_parser_previous(p);
        return _eq_expr_string_literal(((long long*)(tok))[1], ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    if (_eq_parser_match(p, _eq_g_TOKEN_IDENTIFIER)) {
        tok = _eq_parser_previous(p);
        return _eq_expr_variable(((long long*)(tok))[1], ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    if (_eq_parser_match(p, _eq_g_TOKEN_LPARENT)) {
        expr = _eq_parse_expression(p);
        _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after expression."));
        return expr;
    }
    tok = _eq_parser_peek(p);
    _eq_parser_consume(p, 999, ((long long)"Expect expression."));
}
long long _eq_parse_call(long long p) {
    volatile long long args = 0;
    volatile long long expr = 0;
    volatile long long idx = 0;
    volatile long long loop = 0;
    volatile long long more = 0;
    volatile long long name = 0;
    volatile long long q_tok = 0;
    volatile long long r_bracket = 0;
    volatile long long r_parent = 0;
    volatile long long tok = 0;

     expr = 0;
     loop = 0;
     args = 0;
     more = 0;
     r_parent = 0;
     idx = 0;
     r_bracket = 0;
     name = 0;
     tok = 0;
    expr = _eq_parse_primary(p);
    loop = 1;
    while (loop) {
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        if (_eq_parser_match(p, _eq_g_TOKEN_LPARENT)) {
            args = _eq_vec_new(32);
            if (_eq_parser_check(p, _eq_g_TOKEN_RPARENT) == 0) {
                more = 1;
                while (more) {
                    _eq_vec_push(args, _eq_parse_expression(p));
                    if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) == 0) { more = 0; }
                }
            }
            r_parent = _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after arguments."));
            expr = _eq_expr_call(expr, args, ((long long*)(r_parent))[2], ((long long*)(r_parent))[3], 0);
        } else if (_eq_parser_match(p, _eq_g_TOKEN_LBRACKET)) {
            idx = _eq_parse_expression(p);
            r_bracket = _eq_parser_consume(p, _eq_g_TOKEN_RBRACKET, ((long long)"Expect ']' after index."));
            expr = _eq_expr_index(expr, idx, ((long long*)(r_bracket))[2], ((long long*)(r_bracket))[3]);
        } else if (_eq_parser_match(p, _eq_g_TOKEN_DOT)) {
            name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect property name after '.'."));
            expr = _eq_expr_get(expr, ((long long*)(name))[1], ((long long*)(name))[2], ((long long*)(name))[3]);
        } else if (_eq_parser_match(p, _eq_g_TOKEN_QUESTION)) {
             q_tok = _eq_parser_previous(p);
            expr = _eq_expr_try(expr, ((long long*)(q_tok))[2], ((long long*)(q_tok))[3]);
        } else {
            loop = 0;
        }
    }
    return expr;
}
long long _eq_parse_unary(long long p) {
    volatile long long node = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     op = 0;
     right = 0;
     node = 0;
     tok = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_BANG) || _eq_parser_match(p, _eq_g_TOKEN_MINUS) || _eq_parser_match(p, _eq_g_TOKEN_AMPERSAND)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        long long line = ((long long*)(tok))[2];
        long long col = ((long long*)(tok))[3];
        long long is_mut = 0;
        if (op == _eq_g_TOKEN_AMPERSAND) {
            if (_eq_parser_match(p, _eq_g_TOKEN_MUT)) { is_mut = 1; }
            right = _eq_parse_unary(p);
            long long* n = (long long*)sys_malloc(5 * 8);
            n[0] = _eq_g_EXPR_REFERENCE; n[1] = is_mut; n[2] = right; n[3] = line; n[4] = col;
            return (long long)n;
        }
        right = _eq_parse_unary(p);
        node = (long long)sys_malloc(5 * 8);
        ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_EXPR_UNARY;
        ((long long*)(node))[_eq_g_UNARY_OP] = op;
        ((long long*)(node))[_eq_g_UNARY_RIGHT] = right;
        ((long long*)(node))[_eq_g_UNARY_LINE] = line;
        ((long long*)(node))[_eq_g_UNARY_COL] = col;
        return (long long)node;
    }
    return _eq_parse_call(p);
}
long long _eq_parse_multiplication(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     expr = 0;
     op = 0;
     right = 0;
     tok = 0;
    expr = _eq_parse_unary(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_ASTERISK) || _eq_parser_match(p, _eq_g_TOKEN_SLASH) || _eq_parser_match(p, _eq_g_TOKEN_PERCENT)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_unary(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_addition(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     expr = 0;
     op = 0;
     right = 0;
     tok = 0;
    expr = _eq_parse_multiplication(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_PLUS) || _eq_parser_match(p, _eq_g_TOKEN_MINUS)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_multiplication(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_lshift(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;
    expr = _eq_parse_addition(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_LSHIFT)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_addition(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_comparison(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     expr = 0;
     op = 0;
     right = 0;
     tok = 0;
    expr = _eq_parse_lshift(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_GREATER) || _eq_parser_match(p, _eq_g_TOKEN_GREATER_EQUAL) || _eq_parser_match(p, _eq_g_TOKEN_LESS) || _eq_parser_match(p, _eq_g_TOKEN_LESS_EQUAL)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_lshift(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_equality(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     expr = 0;
     op = 0;
     right = 0;
     tok = 0;
    expr = _eq_parse_comparison(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_BANG_EQUAL) || _eq_parser_match(p, _eq_g_TOKEN_EQUAL_EQUAL)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_comparison(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_bitor(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;
    expr = _eq_parse_equality(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_BITOR)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_equality(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_and(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     expr = 0;
     op = 0;
     right = 0;
     tok = 0;
    expr = _eq_parse_bitor(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_AND)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_bitor(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_or(long long p) {
    volatile long long expr = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long tok = 0;

     expr = 0;
     op = 0;
     right = 0;
     tok = 0;
    expr = _eq_parse_and(p);
    while (_eq_parser_match(p, _eq_g_TOKEN_OR)) {
        tok = _eq_parser_previous(p);
        op = ((long long*)(tok))[0];
        right = _eq_parse_and(p);
        expr = _eq_expr_binary(expr, op, right, ((long long*)(tok))[2], ((long long*)(tok))[3]);
    }
    return expr;
}
long long _eq_parse_assignment(long long p) {
    volatile long long equals = 0;
    volatile long long expr = 0;
    volatile long long value = 0;

     expr = 0;
     equals = 0;
     value = 0;
    expr = _eq_parse_or(p);
    if (_eq_parser_match(p, _eq_g_TOKEN_EQUAL)) {
        equals = _eq_parser_previous(p);
        value = _eq_parse_assignment(p);
        if (((long long*)(expr))[_eq_g_AST_TYPE] == _eq_g_EXPR_VARIABLE) { return _eq_expr_assignment(expr, value, ((long long*)(equals))[2], ((long long*)(equals))[3]); }
        if (((long long*)(expr))[_eq_g_AST_TYPE] == _eq_g_EXPR_INDEX) { return _eq_expr_assignment(expr, value, ((long long*)(equals))[2], ((long long*)(equals))[3]); }
        if (((long long*)(expr))[_eq_g_AST_TYPE] == _eq_g_EXPR_GET) { return _eq_expr_assignment(expr, value, ((long long*)(equals))[2], ((long long*)(equals))[3]); }
        _eq_print_str(((long long)"Invalid assignment target."));
        exit(1);
    }
    return expr;
}
long long _eq_parse_expression(long long p) {
    if (_eq_parser_match(p, _eq_g_TOKEN_TRY)) {
        volatile long long line = 0; line = ((long long*)(_eq_vec_get(((long long*)(p))[0], ((long long*)(p))[2] - 1)))[2];
        volatile long long col = 0; col = ((long long*)(_eq_vec_get(((long long*)(p))[0], ((long long*)(p))[2] - 1)))[3];
        volatile long long expr = 0; expr = _eq_parse_expression(p);
        volatile long long node = 0; node = _eq_sys_malloc(4 * 8);
        ((long long*)(node))[0] = _eq_g_EXPR_TRY;
        ((long long*)(node))[_eq_g_TRY_EXPR] = expr;
        ((long long*)(node))[3] = line;
        ((long long*)(node))[4] = col;
        return node;
    }
    return _eq_parse_assignment(p);
}
long long _eq_parse_statement(long long p) {

    if (_eq_parser_match(p, _eq_g_TOKEN_IF)) { return _eq_parse_if(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_WHILE)) { return _eq_parse_while(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_LBRACE)) { return _eq_parse_block(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_LET)) { return _eq_parse_let(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_RETURN)) { return _eq_parse_return(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_PRINT)) { return _eq_parse_print(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_USE)) { return _eq_parse_use(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_FN)) { return _eq_parse_function(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_EXTERN)) { return _eq_parse_extern(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_STRUCT)) { return _eq_parse_struct_decl(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_AGENT)) { return _eq_parse_agent(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_RESOURCE)) { return _eq_parse_resource(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_EVENT)) { return _eq_parse_event(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_COMMITMENT)) { return _eq_parse_commitment(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_POLICY)) { return _eq_parse_policy(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_EXECUTE)) { return _eq_parse_execute(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_ASSERT)) { return _eq_parse_assert(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_REVERSE)) { return _eq_parse_reverse(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_EXCHANGE)) { return _eq_parse_exchange(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_TRANSFORMATION)) { return _eq_parse_transformation(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_VALUATOR)) { return _eq_parse_valuator(p); }
    if (_eq_parser_match(p, _eq_g_TOKEN_INTERFACE)) { return _eq_parse_interface(p); }
    return _eq_parse_expression_statement(p);
}
long long _eq_parse_expression_statement(long long p) {
    volatile long long expr = 0;
    volatile long long tok = 0;

     expr = 0;
     tok = 0;
    expr = _eq_parse_expression(p);
    tok = _eq_parser_previous(p);
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after expression."));
    return _eq_stmt_expression(expr, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_let(long long p) {
    volatile long long name = 0;
    volatile long long tok = 0;
    volatile long long type = 0;
    volatile long long value = 0;
    volatile long long is_mut = 0;
    volatile long long is_res = 0;
     tok = 0;
     name = 0;
     type = 0;
     value = 0;
    tok = _eq_parser_previous(p); 
    volatile long long loop = 0;
    loop = 1;
    while (loop) {
        if (_eq_parser_match(p, _eq_g_TOKEN_MUT)) { is_mut = 1; }
        else if (_eq_parser_match(p, _eq_g_TOKEN_RESOURCE)) { is_res = 1; }
        else { loop = 0; }
    }
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect variable name."));
    type = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_COLON)) {
        _eq_parser_match(p, _eq_g_TOKEN_QUESTION);
        if (_eq_parser_match(p, _eq_g_TOKEN_I64)) { type = _eq_g_TOKEN_I64; }
        else if (_eq_parser_match(p, _eq_g_TOKEN_F64)) { type = _eq_g_TOKEN_F64; }
        else if (_eq_parser_match(p, _eq_g_TOKEN_BOOL)) { type = _eq_g_TOKEN_BOOL; }
        else if (_eq_parser_match(p, _eq_g_TOKEN_IDENTIFIER)) { type = ((long long*)((_eq_parser_previous(p))))[1]; }
        else { _eq_parser_error(p, ((long long)"Expect type after ':'.")); }
    }
    value = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_EQUAL)) { value = _eq_parse_expression(p); }
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after variable declaration."));
    return _eq_stmt_let(((long long*)(name))[1], value, type, ((long long*)(tok))[2], ((long long*)(tok))[3], is_mut, is_res);
}
long long _eq_parse_if(long long p) {
    volatile long long cond = 0;
    volatile long long els = 0;
    volatile long long then = 0;
    volatile long long tok = 0;

     tok = 0;
     cond = 0;
     then = 0;
     els = 0;
    tok = _eq_parser_previous(p);
    _eq_parser_consume(p, _eq_g_TOKEN_LPARENT, ((long long)"Expect '(' after 'if'."));
    cond = _eq_parse_expression(p);
    _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after condition."));
    then = _eq_parse_statement(p);
    els = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_ELSE)) { els = _eq_parse_statement(p); }
    return _eq_stmt_if(cond, then, els, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_while(long long p) {
    volatile long long body = 0;
    volatile long long cond = 0;
    volatile long long tok = 0;

     tok = 0;
     cond = 0;
     body = 0;
    tok = _eq_parser_previous(p);
    _eq_parser_consume(p, _eq_g_TOKEN_LPARENT, ((long long)"Expect '(' after 'while'."));
    cond = _eq_parse_expression(p);
    _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after condition."));
    body = _eq_parse_statement(p);
    return _eq_stmt_while(cond, body, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_use(long long p) {
    volatile long long line = 0;
    volatile long long node = 0;
    volatile long long path = 0;
    volatile long long tok = 0;

     line = 0;
     path = 0;
     node = 0;
     tok = 0;
    tok = _eq_parser_previous(p);
    line = ((long long*)(tok))[2];
    if (_eq_parser_check(p, _eq_g_TOKEN_STRING)) {
        path = ((long long*)(_eq_parser_advance(p)))[1];
    } else {
        path = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect module path string or identifier."))))[1];
        while (_eq_parser_match(p, _eq_g_TOKEN_COLON_COLON)) {
            path = _eq_str_concat(path, ((long long)"/"));
            path = _eq_str_concat(path, (((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect identifier after '::'."))))[1]));
        }
        path = _eq_str_concat(path, ((long long)".equis"));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after module path."));
    node = sys_malloc(3 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_USE;
    ((long long*)(node))[1] = path;
    ((long long*)(node))[2] = line;
    return node;
}
long long _eq_parse_struct_decl(long long p) {
    volatile long long field_name = 0;
    volatile long long fields = 0;
    volatile long long generics = 0;
    volatile long long name_tok = 0;
    volatile long long tok = 0;

     tok = 0;
     name_tok = 0;
     fields = 0;
     field_name = 0;
     generics = 0;
    tok = _eq_parser_previous(p); 
    name_tok = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect struct name."));
    generics = _eq_parser_parse_generics(p);
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before struct body."));
    fields = _eq_vec_new(64);
    while (_eq_parser_is_at_end(p) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        field_name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect field name."));
        _eq_vec_push(fields, ((long long*)(field_name))[1]);
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after field name."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after struct body."));
    return _eq_stmt_struct(((long long*)(name_tok))[1], fields, ((long long*)(tok))[2], ((long long*)(tok))[3], generics);
}
long long _eq_parse_agent(long long p) {
    volatile long long a_implements = 0;
    volatile long long a_roles = 0;
    volatile long long field_name_tok = 0;
    volatile long long fields = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long tok = 0;

     tok = 0;
     name = 0;
     a_implements = 0;
     a_roles = 0;
     fields = 0;
     field_name_tok = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Agent name."));
    a_implements = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_IMPLEMENTS)) {
        a_implements = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect interface name."))))[1];
    }
    a_roles = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_ROLES)) {
        _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Agent roles."));
        a_roles = _eq_vec_new(32);
        while (_eq_parser_is_at_end(p) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
            _eq_vec_push(a_roles, ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_STRING, ((long long)"Expect role name."))))[1]);
            if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) || _eq_parser_match(p, _eq_g_TOKEN_SEMICOLON)) {}
        }
        _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Agent roles."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Agent body."));
    fields = _eq_vec_new(64);
    while (_eq_parser_is_at_end(p) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        field_name_tok = _eq_parser_peek(p);
        _eq_parser_advance(p);
        _eq_vec_push(fields, ((long long*)(field_name_tok))[1]);
        if (_eq_parser_match(p, _eq_g_TOKEN_COLON)) {
            if (_eq_parser_match(p, _eq_g_TOKEN_IDENTIFIER)) {}
            else { _eq_parser_consume(p, _eq_g_TOKEN_STRING, ((long long)"Expect type or unit string.")); }
        }
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after field name."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Agent body."));
    node = sys_malloc(7 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_AGENT;
    ((long long*)(node))[_eq_g_AGENT_NAME] = ((long long*)(name))[1];
    ((long long*)(node))[_eq_g_AGENT_FIELDS] = fields;
    ((long long*)(node))[_eq_g_AGENT_LINE] = ((long long*)(tok))[2];
    ((long long*)(node))[_eq_g_AGENT_COL] = ((long long*)(tok))[3];
    ((long long*)(node))[_eq_g_AGENT_ROLES] = a_roles;
    ((long long*)(node))[_eq_g_AGENT_IMPLEMENTS] = a_implements;
    return node;
}
long long _eq_parse_resource(long long p) {
    volatile long long field_name_tok = 0;
    volatile long long metadata = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long tok = 0;
    volatile long long val = 0;

     tok = 0;
     name = 0;
     metadata = 0;
     field_name_tok = 0;
     val = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Resource name."));
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Resource body."));
    metadata = _eq_map_new(500);
    while (_eq_parser_is_at_end(p) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        field_name_tok = _eq_parser_peek(p);
        _eq_parser_advance(p);
        if (_eq_parser_match(p, _eq_g_TOKEN_COLON)) {
             val = 0;
             if (_eq_parser_check(p, _eq_g_TOKEN_NUMBER)) { val = ((long long*)(_eq_parser_advance(p)))[1]; }
             else { val = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect type, unit, or number."))))[1]; }
             _eq_map_put(metadata, ((long long*)(field_name_tok))[1], val);
        }
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after field name."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Resource body."));
    node = sys_malloc(6 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_RESOURCE;
    ((long long*)(node))[1] = ((long long*)(name))[1];
    ((long long*)(node))[2] = metadata;
    ((long long*)(node))[3] = ((long long*)(tok))[2];
    ((long long*)(node))[4] = ((long long*)(tok))[3];
    return node;
}
long long _eq_parse_execute(long long p) {
    volatile long long args = 0;
    volatile long long event_name = 0;
    volatile long long key = 0;
    volatile long long node = 0;
    volatile long long tok = 0;
    volatile long long val = 0;

     tok = 0;
     event_name = 0;
     args = 0;
     key = 0;
     val = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    event_name = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect event name."))))[1];
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{'."));
    args = _eq_vec_new(64);
    while (_eq_parser_is_at_end(p) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        key = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect key."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_COLON, ((long long)"Expect ':'."));
        val = 0;
        if (_eq_parser_match(p, _eq_g_TOKEN_IDENTIFIER)) { val = ((long long*)(_eq_parser_previous(p)))[1]; }
        else { val = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_STRING, ((long long)"Expect value."))))[1]; }
        _eq_vec_push(args, key);
        _eq_vec_push(args, val);
        if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) || _eq_parser_match(p, _eq_g_TOKEN_SEMICOLON)) {}
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}'."));
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after execute."));
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_EXECUTE;
    ((long long*)(node))[1] = event_name;
    ((long long*)(node))[2] = args;
    ((long long*)(node))[3] = ((long long*)(tok))[2];
    ((long long*)(node))[4] = ((long long*)(tok))[3];
    return node;
}
long long _eq_parse_assert(long long p) {
    volatile long long expr = 0;
    volatile long long node = 0;
    volatile long long tok = 0;

     tok = 0;
     expr = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    expr = _eq_parse_expression(p);
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after assert."));
    node = sys_malloc(4 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_ASSERT;
    ((long long*)(node))[1] = expr;
    ((long long*)(node))[2] = ((long long*)(tok))[2];
    ((long long*)(node))[3] = ((long long*)(tok))[3];
    return node;
}
long long _eq_parse_return(long long p) {
    volatile long long tok = 0;
    volatile long long val = 0;

     tok = 0;
     val = 0;
    tok = _eq_parser_previous(p); 
    val = 0;
    if (_eq_parser_check(p, _eq_g_TOKEN_SEMICOLON) == 0) { val = _eq_parse_expression(p); }
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after return."));
    return _eq_stmt_return(val, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_print(long long p) {
    volatile long long expr = 0;
    volatile long long tok = 0;

     tok = 0;
     expr = 0;
    tok = _eq_parser_previous(p); 
    expr = _eq_parse_expression(p);
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after print."));
    return _eq_stmt_print(expr, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_block(long long p) {
    volatile long long stmts = 0;
    volatile long long tok = 0;

     tok = 0;
     stmts = 0;
    tok = _eq_parser_previous(p); 
    stmts = _eq_vec_new(128);
    while (_eq_parser_is_at_end(p) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        _eq_vec_push(stmts, _eq_parse_statement(p));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after block."));
    return _eq_stmt_block(stmts, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_function(long long p) {
    volatile long long body = 0;
    volatile long long generics = 0;
    volatile long long more = 0;
    volatile long long name_tok = 0;
    volatile long long param = 0;
    volatile long long params = 0;
    volatile long long param_types = 0;
    volatile long long params_mut = 0;
    volatile long long return_type = 0;
    volatile long long tok = 0;
    volatile long long is_mut = 0;

     tok = 0;
     name_tok = 0;
     params = 0;
     more = 0;
     param = 0;
     body = 0;
     generics = 0;
    tok = _eq_parser_previous(p); 
    name_tok = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect function name."));
    generics = _eq_parser_parse_generics(p);
    _eq_parser_consume(p, _eq_g_TOKEN_LPARENT, ((long long)"Expect '(' after function name."));
    params = _eq_vec_new(32);
    param_types = _eq_vec_new(32);
    params_mut = _eq_vec_new(32);
    if (_eq_parser_check(p, _eq_g_TOKEN_RPARENT) == 0) {
        more = 1;
        while (more) {
            is_mut = 0;
            if (_eq_parser_match(p, _eq_g_TOKEN_MUT)) { is_mut = 1; }
            param = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect parameter name."));
            volatile long long p_type = 0;
            if (_eq_parser_match(p, _eq_g_TOKEN_COLON)) {
                while (_eq_parser_check(p, _eq_g_TOKEN_COMMA) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RPARENT) == 0 && _eq_parser_is_at_end(p) == 0) { _eq_parser_advance(p); }
            }
            _eq_vec_push(params, ((long long*)(param))[1]);
            _eq_vec_push(param_types, p_type);
            _eq_vec_push(params_mut, is_mut);
            if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) == 0) { more = 0; }
        }
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after parameters."));
    if (_eq_parser_match(p, _eq_g_TOKEN_ARROW)) {
        while (_eq_parser_check(p, _eq_g_TOKEN_LBRACE) == 0 && _eq_parser_is_at_end(p) == 0) { _eq_parser_advance(p); }
    }
    body = _eq_parse_statement(p);
    return _eq_stmt_function(((long long*)(name_tok))[1], params, body, ((long long*)(tok))[2], ((long long*)(tok))[3], generics, param_types, return_type, params_mut);
}
long long _eq_parse_extern(long long p) {
    volatile long long more = 0;
    volatile long long name_tok = 0;
    volatile long long param = 0;
    volatile long long params = 0;
    volatile long long tok = 0;

     tok = 0;
     name_tok = 0;
     params = 0;
     more = 0;
     param = 0;
    tok = _eq_parser_previous(p); 
    _eq_parser_consume(p, _eq_g_TOKEN_FN, ((long long)"Expect 'fn' after 'extern'."));
    name_tok = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect function name."));
    _eq_parser_consume(p, _eq_g_TOKEN_LPARENT, ((long long)"Expect '(' after function name."));
    params = _eq_vec_new(32);
    if (_eq_parser_check(p, _eq_g_TOKEN_RPARENT) == 0) {
        more = 1;
        while (more) {
            if (_eq_parser_match(p, 72)) { }
            param = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect parameter name."));
            if (_eq_parser_match(p, _eq_g_TOKEN_COLON)) {
                while (_eq_parser_check(p, _eq_g_TOKEN_COMMA) == 0 && _eq_parser_check(p, _eq_g_TOKEN_RPARENT) == 0 && _eq_parser_is_at_end(p) == 0) { _eq_parser_advance(p); }
            }
            _eq_vec_push(params, ((long long*)(param))[1]);
            if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) == 0) { more = 0; }
        }
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after parameters."));
    if (_eq_parser_match(p, _eq_g_TOKEN_ARROW)) {
        while (_eq_parser_check(p, _eq_g_TOKEN_SEMICOLON) == 0 && _eq_parser_is_at_end(p) == 0) { _eq_parser_advance(p); }
    }
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after extern."));
    return _eq_stmt_extern(((long long*)(name_tok))[1], params, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_interface(long long p) {
    volatile long long m_name = 0;
    volatile long long method = 0;
    volatile long long methods = 0;
    volatile long long name = 0;
    volatile long long params = 0;
    volatile long long tok = 0;

     tok = 0;
     name = 0;
     methods = 0;
     m_name = 0;
     params = 0;
     method = 0;
    tok = _eq_parser_previous(p); 
    name = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect interface name."))))[1];
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before interface body."));
    methods = _eq_vec_new(200000);
    while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        _eq_parser_consume(p, _eq_g_TOKEN_FN, ((long long)"Expect 'fn' for method declaration."));
        m_name = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect method name."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_LPARENT, ((long long)"Expect '(' after method name."));
        params = _eq_vec_new(200000);
        if (_eq_parser_check(p, _eq_g_TOKEN_RPARENT) == 0) {
            _eq_vec_push(params, ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect parameter name."))))[1]);
            while (_eq_parser_match(p, _eq_g_TOKEN_COMMA)) {
                _eq_vec_push(params, ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect parameter name."))))[1]);
            }
        }
        _eq_parser_consume(p, _eq_g_TOKEN_RPARENT, ((long long)"Expect ')' after parameters."));
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after method declaration."));
        method = sys_malloc(4 * 8);
        ((long long*)(method))[0] = m_name;
        ((long long*)(method))[1] = params;
        ((long long*)(method))[2] = ((long long*)(tok))[2];
        ((long long*)(method))[3] = ((long long*)(tok))[3];
        _eq_vec_push(methods, method);
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after interface body."));
    return _eq_stmt_interface(name, methods, ((long long*)(tok))[2], ((long long*)(tok))[3]);
}
long long _eq_parse_program(long long p) {
    volatile long long decls = 0;

     decls = 0;
    decls = _eq_vec_new(200000);
    while (_eq_parser_is_at_end(p) == 0) {
        _eq_vec_push(decls, _eq_parse_statement(p));
    }
    return decls;
}
long long _eq_parse_event(long long p) {
    volatile long long amount = 0;
    volatile long long c_flows = 0;
    volatile long long c_from = 0;
    volatile long long c_logic = 0;
    volatile long long c_to = 0;
    volatile long long e_fulfills = 0;
    volatile long long e_roles = 0;
    volatile long long e_valuator = 0;
    volatile long long fnode = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long res_name = 0;
    volatile long long tok = 0;
    volatile long long type = 0;

     tok = 0;
     name = 0;
     e_fulfills = 0;
     e_valuator = 0;
     e_roles = 0;
     c_logic = 0;
     c_flows = 0;
     type = 0;
     amount = 0;
     res_name = 0;
     c_from = 0;
     c_to = 0;
     fnode = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Event name."));
    e_fulfills = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_FULFILLS)) { e_fulfills = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Commitment name."))))[1]; }
    e_valuator = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_EVALUATED_BY)) { e_valuator = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Valuator name."))))[1]; }
    e_roles = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_ROLES)) {
        _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Event roles."));
        e_roles = _eq_vec_new(200000);
        while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
            _eq_vec_push(e_roles, ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_STRING, ((long long)"Expect role name."))))[1]);
            if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) || _eq_parser_match(p, _eq_g_TOKEN_SEMICOLON)) {}
        }
        _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Event roles."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Event body."));
    c_logic = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_LOGIC)) {
        _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before logic body."));
        c_logic = _eq_parse_block(p);
    }
    _eq_parser_consume(p, _eq_g_TOKEN_FLOW, ((long long)"Expect 'flow' block."));
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before flows."));
    c_flows = _eq_vec_new(200000);
    while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        type = 0;
        if (_eq_parser_match(p, _eq_g_TOKEN_IN)) { type = _eq_g_TOKEN_IN; }
        else if (_eq_parser_match(p, _eq_g_TOKEN_OUT)) { type = _eq_g_TOKEN_OUT; }
        else { _eq_parser_consume(p, 999, ((long long)"Expect 'in' or 'out'.")); }
        amount = _eq_parse_expression(p);
        res_name = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect resource name."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_FROM, ((long long)"Expect 'from'."));
        c_from = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect source agent."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_TO, ((long long)"Expect 'to'."));
        c_to = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect destination agent."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after flow."));
        fnode = sys_malloc(10 * 8);
        ((long long*)(fnode))[_eq_g_AST_TYPE] = _eq_g_STMT_FLOW;
        ((long long*)(fnode))[_eq_g_FLOW_TYPE] = type;
        ((long long*)(fnode))[_eq_g_FLOW_AMOUNT] = amount;
        ((long long*)(fnode))[_eq_g_FLOW_RES] = res_name;
        ((long long*)(fnode))[_eq_g_FLOW_FROM] = c_from;
        ((long long*)(fnode))[_eq_g_FLOW_TO] = c_to;
        ((long long*)(fnode))[_eq_g_FLOW_LINE] = ((long long*)(tok))[2];
        ((long long*)(fnode))[_eq_g_FLOW_COL] = ((long long*)(tok))[3];
        ((long long*)(fnode))[8] = 0;
        ((long long*)(fnode))[9] = 0;
        _eq_vec_push(c_flows, fnode);
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after flow block."));
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Event block."));
    node = sys_malloc(9 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_EVENT;
    ((long long*)(node))[_eq_g_EVENT_NAME] = ((long long*)(name))[1];
    ((long long*)(node))[_eq_g_EVENT_LOGIC] = c_logic;
    ((long long*)(node))[_eq_g_EVENT_FLOWS] = c_flows;
    ((long long*)(node))[_eq_g_EVENT_LINE] = ((long long*)(tok))[2];
    ((long long*)(node))[_eq_g_EVENT_COL] = ((long long*)(tok))[3];
    ((long long*)(node))[_eq_g_EVENT_FULFILLS] = e_fulfills;
    ((long long*)(node))[_eq_g_EVENT_ROLES] = e_roles;
    ((long long*)(node))[_eq_g_EVENT_VALUATOR] = e_valuator;
    return node;
}
long long _eq_parse_commitment(long long p) {
    volatile long long amount = 0;
    volatile long long c_flows = 0;
    volatile long long c_from = 0;
    volatile long long c_logic = 0;
    volatile long long c_to = 0;
    volatile long long c_valuator = 0;
    volatile long long fnode = 0;
    volatile long long line = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long res_name = 0;
    volatile long long c_roles = 0;
    volatile long long type = 0;

     line = 0;
     name = 0;
     c_valuator = 0;
     c_logic = 0;
     c_flows = 0;
     type = 0;
     amount = 0;
     res_name = 0;
     c_from = 0;
     c_to = 0;
     fnode = 0;
     node = 0;
    line = ((long long*)(_eq_parser_previous(p)))[2];
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Commitment name."));
    c_valuator = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_EVALUATED_BY)) { c_valuator = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Valuator name."))))[1]; }
    c_roles = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_ROLES)) {
        _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Commitment roles."));
        c_roles = _eq_vec_new(200000);
        while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
            _eq_vec_push(c_roles, ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_STRING, ((long long)"Expect role name."))))[1]);
            if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) || _eq_parser_match(p, _eq_g_TOKEN_SEMICOLON)) {}
        }
        _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Commitment roles."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Commitment body."));
    c_logic = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_LOGIC)) {
        _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before logic body."));
        c_logic = _eq_parse_block(p);
    }
    _eq_parser_consume(p, _eq_g_TOKEN_FLOW, ((long long)"Expect 'flow' block."));
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before flows."));
    c_flows = _eq_vec_new(200000);
    while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        type = 0;
        if (_eq_parser_match(p, _eq_g_TOKEN_IN)) { type = _eq_g_TOKEN_IN; }
        else if (_eq_parser_match(p, _eq_g_TOKEN_OUT)) { type = _eq_g_TOKEN_OUT; }
        else { _eq_parser_consume(p, 999, ((long long)"Expect 'in' or 'out'.")); }
        amount = _eq_parse_expression(p);
        res_name = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect resource name."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_FROM, ((long long)"Expect 'from'."));
        c_from = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect source agent."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_TO, ((long long)"Expect 'to'."));
        c_to = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect destination agent."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after flow."));
        fnode = sys_malloc(9 * 8);
        ((long long*)(fnode))[_eq_g_AST_TYPE] = _eq_g_STMT_FLOW;
        ((long long*)(fnode))[_eq_g_FLOW_TYPE] = type;
        ((long long*)(fnode))[_eq_g_FLOW_AMOUNT] = amount;
        ((long long*)(fnode))[_eq_g_FLOW_RES] = res_name;
        ((long long*)(fnode))[_eq_g_FLOW_FROM] = c_from;
        ((long long*)(fnode))[_eq_g_FLOW_TO] = c_to;
        ((long long*)(fnode))[_eq_g_FLOW_LINE] = line;
        ((long long*)(fnode))[7] = 0;
        ((long long*)(fnode))[8] = 0;
        _eq_vec_push(c_flows, fnode);
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after flow block."));
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Commitment block."));
    node = sys_malloc(10 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_COMMITMENT;
    ((long long*)(node))[_eq_g_COMMITMENT_NAME] = ((long long*)(name))[1];
    ((long long*)(node))[_eq_g_COMMITMENT_LOGIC] = c_logic;
    ((long long*)(node))[_eq_g_COMMITMENT_FLOWS] = c_flows;
    ((long long*)(node))[_eq_g_COMMITMENT_LINE] = line;
    ((long long*)(node))[_eq_g_COMMITMENT_VALUATOR] = c_valuator;
    ((long long*)(node))[_eq_g_COMMITMENT_ROLES] = c_roles;
    return node;
}
long long _eq_parse_policy(long long p) {
    volatile long long body = 0;
    volatile long long line = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long tok = 0;

     tok = 0;
     line = 0;
     name = 0;
     body = 0;
     node = 0;
    tok = _eq_parser_previous(p);
    line = ((long long*)(tok))[2];
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Policy name."));
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before Policy body."));
    _eq_parser_consume(p, _eq_g_TOKEN_LOGIC, ((long long)"Expect 'logic' block."));
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before logic body."));
    body = _eq_parse_block(p);
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}' after Policy block."));
    node = sys_malloc(4 * 8);
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_POLICY;
    ((long long*)(node))[1] = ((long long*)(name))[1];
    ((long long*)(node))[2] = body;
    ((long long*)(node))[3] = ((long long*)(tok))[2];
    ((long long*)(node))[4] = ((long long*)(tok))[3];
    return node;
}
long long _eq_parse_reverse(long long p) {
    volatile long long args = 0;
    volatile long long event_name = 0;
    volatile long long key = 0;
    volatile long long node = 0;
    volatile long long tok = 0;
    volatile long long val = 0;

     tok = 0;
     event_name = 0;
     args = 0;
     key = 0;
     val = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    event_name = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect event name."))))[1];
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{'."));
    args = _eq_vec_new(200000);
    while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        key = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect key."))))[1];
        _eq_parser_consume(p, _eq_g_TOKEN_COLON, ((long long)"Expect ':'."));
        val = 0;
        if (_eq_parser_match(p, _eq_g_TOKEN_IDENTIFIER)) { val = ((long long*)(_eq_parser_previous(p)))[1]; }
        else { val = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_STRING, ((long long)"Expect value."))))[1]; }
        _eq_vec_push(args, key);
        _eq_vec_push(args, val);
        if (_eq_parser_match(p, _eq_g_TOKEN_COMMA) || _eq_parser_match(p, _eq_g_TOKEN_SEMICOLON)) {}
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}'."));
    _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';' after reverse."));
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_REVERSE;
    ((long long*)(node))[1] = event_name;
    ((long long*)(node))[2] = args;
    ((long long*)(node))[3] = ((long long*)(tok))[2];
    ((long long*)(node))[4] = ((long long*)(tok))[3];
    return node;
}
long long _eq_parse_exchange(long long p) {
    volatile long long ev = 0;
    volatile long long events = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long tok = 0;

     tok = 0;
     name = 0;
     events = 0;
     ev = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect exchange name."));
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{' before exchange body."));
    events = _eq_vec_new(200000);
    while (_eq_parser_check(p, _eq_g_TOKEN_RBRACE) == 0) {
        ev = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect event name."));
        _eq_vec_push(events, ((long long*)(ev))[1]);
        _eq_parser_consume(p, _eq_g_TOKEN_SEMICOLON, ((long long)"Expect ';'."));
    }
    _eq_parser_consume(p, _eq_g_TOKEN_RBRACE, ((long long)"Expect '}'."));
    node = sys_malloc(5 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_EXCHANGE;
    ((long long*)(node))[1] = ((long long*)(name))[1];
    ((long long*)(node))[2] = events;
    ((long long*)(node))[3] = ((long long*)(tok))[2];
    ((long long*)(node))[4] = ((long long*)(tok))[3];
    return node;
}
long long _eq_parse_transformation(long long p) {
    volatile long long line = 0;
    volatile long long node = 0;

     line = 0;
     node = 0;
    line = ((long long*)(_eq_parser_previous(p)))[2];
    node = _eq_parse_event(p);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_TRANSFORMATION;
    return node;
}
long long _eq_parse_valuator(long long p) {
    volatile long long body = 0;
    volatile long long name = 0;
    volatile long long node = 0;
    volatile long long tok = 0;
    volatile long long v_implements = 0;

     tok = 0;
     name = 0;
     v_implements = 0;
     body = 0;
     node = 0;
    tok = _eq_parser_previous(p); 
    name = _eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect Valuator name."));
    v_implements = 0;
    if (_eq_parser_match(p, _eq_g_TOKEN_IMPLEMENTS)) {
        v_implements = ((long long*)(_eq_parser_consume(p, _eq_g_TOKEN_IDENTIFIER, ((long long)"Expect interface name."))))[1];
    }
    _eq_parser_consume(p, _eq_g_TOKEN_LBRACE, ((long long)"Expect '{'."));
    body = _eq_parse_block(p);
    node = sys_malloc(6 * 8);
    ((long long*)(node))[_eq_g_AST_TYPE] = _eq_g_STMT_VALUATOR;
    ((long long*)(node))[1] = ((long long*)(name))[1];
    ((long long*)(node))[2] = body;
    ((long long*)(node))[3] = ((long long*)(tok))[2];
    ((long long*)(node))[4] = ((long long*)(tok))[3];
    ((long long*)(node))[5] = v_implements;
    return node;
}
long long _eq_analyzer_new() {
    volatile long long a = 0;
    volatile long long arena = 0;
    volatile long long diagnostics = 0;
    volatile long long global_map = 0;
    volatile long long monomorphizer = 0;
    volatile long long scopes = 0;

     a = 0;
     arena = 0;
     scopes = 0;
     global_map = 0;
     diagnostics = 0;
     monomorphizer = 0;
    a = sys_malloc(6 * 8);
    arena = _eq_arena_new(1024 * 1024);
    scopes = _eq_vec_new(200000);
    global_map = _eq_map_new(20000);
    diagnostics = _eq_vec_new(200000);
    monomorphizer = _eq_map_new(1000);
    _eq_vec_push(scopes, global_map);
    ((long long*)(a))[0] = scopes;
    ((long long*)(a))[1] = 0;
    ((long long*)(a))[2] = 0;
    ((long long*)(a))[3] = arena;
    ((long long*)(a))[4] = diagnostics;
    ((long long*)(a))[5] = monomorphizer;
    _eq_analyzer_add_builtins(a);
    return a;
}
long long _eq_analyzer_alloc(long long a, long long size) {

    return _eq_arena_alloc(((long long*)(a))[3], size);
}
long long _eq_analyzer_add_builtins(long long a) {

    _eq_analyzer_define(a, ((long long)"print"), 0, 0);
    _eq_analyzer_define(a, ((long long)"print_str"), 0, 0);
    _eq_analyzer_define(a, ((long long)"print_raw"), 0, 0);
    _eq_analyzer_define(a, ((long long)"print_raw_str"), 0, 0);
    _eq_analyzer_define(a, ((long long)"print_char"), 0, 0);
    _eq_analyzer_define(a, ((long long)"print_raw_char"), 0, 0);
    _eq_analyzer_define(a, ((long long)"get_char"), 0, 0);
    _eq_analyzer_define(a, ((long long)"set_char"), 0, 0);
    _eq_analyzer_define(a, ((long long)"malloc"), 0, 0);
    _eq_analyzer_define(a, ((long long)"free"), 0, 0);
    _eq_analyzer_define(a, ((long long)"exit"), 0, 0);
    _eq_analyzer_define(a, ((long long)"open"), 0, 0);
    _eq_analyzer_define(a, ((long long)"read"), 0, 0);
    _eq_analyzer_define(a, ((long long)"write"), 0, 0);
    _eq_analyzer_define(a, ((long long)"close"), 0, 0);
    _eq_analyzer_define(a, ((long long)"get_argc"), 0, 0);
    _eq_analyzer_define(a, ((long long)"get_argv"), 0, 0);
    _eq_analyzer_define(a, ((long long)"printf"), 0, 0);
    _eq_analyzer_define(a, ((long long)"map_keys"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_equal"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_len"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_concat"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_substring"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_from_int"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_to_int"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_get_agent_location"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_time"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_audit_flow"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_verify_sig"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_evaluate_policies"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_register_agent"), 0, 0);
    _eq_analyzer_define(a, ((long long)"sys_register_resource"), 0, 0);
    _eq_analyzer_define(a, ((long long)"print_fixed"), 0, 0);
    _eq_analyzer_define(a, ((long long)"str_utf8_len"), 0, 0);
    _eq_analyzer_define(a, ((long long)"analyzer_end_scope"), 0, 0);
    _eq_analyzer_define(a, ((long long)"analyze_error"), 0, 0);
    _eq_analyzer_define(a, ((long long)"analyzer_is_global"), 0, 0);
}
long long _eq_analyzer_begin_scope(long long a) {
    volatile long long new_map = 0;

     new_map = 0;
    new_map = _eq_map_new(1000);
    _eq_vec_push(((long long*)(a))[0], new_map);
    ((long long*)(a))[1] = _eq_vec_size(((long long*)(a))[0]) - 1;
}
long long _eq_analyzer_end_scope(long long a) {

    if (((long long*)(a))[1] > 0) {
        _eq_vec_remove(((long long*)(a))[0], ((long long*)(a))[1]);
        ((long long*)(a))[1] = ((long long*)(a))[1] - 1;
    }
}
long long _eq_analyzer_define(long long a, long long name, long long node, long long static_type) {
    volatile long long current_map = 0;
    volatile long long entry = 0;
    volatile long long scopes = 0;

     scopes = 0;
     current_map = 0;
     entry = 0;
    scopes = ((long long*)(a))[0];
    current_map = _eq_vec_get(scopes, ((long long*)(a))[1]);
    entry = _eq_sys_malloc(7 * 8);
    ((long long*)(entry))[0] = _eq_intern_string(name);
    ((long long*)(entry))[1] = node;
    ((long long*)(entry))[2] = static_type;
    ((long long*)(entry))[3] = 0;
    ((long long*)(entry))[4] = 0;
    ((long long*)(entry))[5] = 0;
    ((long long*)(entry))[6] = ((long long*)(a))[1];
    _eq_map_put(current_map, ((long long*)(entry))[0], entry);
}
long long _eq_analyzer_resolve(long long a, long long name) {
    volatile long long entry = 0;
    volatile long long i = 0;
    volatile long long scope_map = 0;

     i = 0;
     scope_map = 0;
     entry = 0;
    if (_eq_g_resolve_stat == 0) { _eq_g_resolve_stat = sys_malloc(16); ((long long*)(_eq_g_resolve_stat))[0] = 0; }
    ((long long*)(_eq_g_resolve_stat))[0] = ((long long*)(_eq_g_resolve_stat))[0] + 1;
    i = ((long long*)(a))[1];
    while (i >= 0) {
        scope_map = _eq_vec_get(((long long*)(a))[0], i);
        entry = _eq_map_get(scope_map, name);
        if (entry) { 
         if (entry) { 
            return entry; 
        }
        }
        i = i - 1;
    }
    return 0;
}
long long _eq_analyzer_is_global(long long a, long long name) {
    volatile long long scope_map = 0;

     scope_map = 0;
    scope_map = _eq_vec_get(((long long*)(a))[0], 0);
    if (_eq_map_get(scope_map, _eq_intern_string(name))) { return 1; }
    return 0;
}
long long _eq_analyze_error_internal(long long a, long long msg, long long line, long long col) {
    volatile long long diag = 0;

    if (((long long*)(a))[4]) {
         diag = sys_malloc(4 * 8);
        ((long long*)(diag))[0] = _eq_intern_string(msg);
        ((long long*)(diag))[1] = line;
        ((long long*)(diag))[2] = col;
        ((long long*)(diag))[3] = 1; 
        _eq_vec_push(((long long*)(a))[4], diag);
        return 0;
    }
}
long long _eq_analyze_undeclared_internal(long long a, long long name, long long line, long long col) {
    volatile long long msg = 0;

    if (((long long*)(a))[4]) {
         msg = _eq_str_concat(((long long)"Undeclared variable '"), name);
        msg = _eq_str_concat(msg, ((long long)"'"));
        _eq_analyze_error_internal(a, msg, line, col);
        return 0;
    }
}
long long _eq_analyze_error(long long msg, long long line, long long col) {

    (void)!write(2, (void*)((long long)"\x1b[1;31merror\x1b[0m\x1b[1m: "), 18);
    (void)!write(2, (void*)msg, (size_t)sys_strlen(msg));
    (void)!write(2, (void*)((long long)"\x1b[0m\n"), 5);
    (void)!write(2, (void*)((long long)"  \x1b[1;34m-->\x1b[0m line "), 15);
    print_raw_stderr(line);
    (void)!write(2, (void*)((long long)":"), 1);
    print_raw_stderr(col);
    (void)!write(2, (void*)((long long)"\n\n"), 2);
    exit(1);
}
long long _eq_analyze_undeclared(long long name, long long line, long long col) {

    (void)!write(2, (void*)((long long)"\x1b[1;31merror\x1b[0m\x1b[1m: Undeclared variable '\x1b[1;33m"), 41);
    (void)!write(2, (void*)name, (size_t)sys_strlen(name));
    (void)!write(2, (void*)((long long)"\x1b[0m\x1b[1m'\x1b[0m\n"), 11);
    (void)!write(2, (void*)((long long)"  \x1b[1;34m-->\x1b[0m line "), 15);
    print_raw_stderr(line);
    (void)!write(2, (void*)((long long)":"), 1);
    print_raw_stderr(col);
    (void)!write(2, (void*)((long long)"\n\n"), 2);
    exit(1);
}
long long _eq_analyzer_copy_node(long long a, long long node) {
    volatile long long args = 0;
    volatile long long i = 0;
    volatile long long n_size = 0;
    volatile long long new_args = 0;
    volatile long long new_node = 0;
    volatile long long new_stmts = 0;
    volatile long long s_size = 0;
    volatile long long stmts = 0;
    volatile long long type = 0;

    if (node == 0) { return 0; }
     type = ((long long*)(node))[0];
     new_node = 0;
    if (type == _eq_g_EXPR_VARIABLE) {
        new_node = _eq_analyzer_alloc(a, 4 * 8);
        ((long long*)(new_node))[0] = _eq_g_EXPR_VARIABLE;
        ((long long*)(new_node))[1] = ((long long*)(node))[1];
        ((long long*)(new_node))[2] = ((long long*)(node))[2];
        ((long long*)(new_node))[3] = ((long long*)(node))[3];
    } else if (type == _eq_g_EXPR_CALL) {
        new_node = _eq_analyzer_alloc(a, 6 * 8);
        ((long long*)(new_node))[0] = _eq_g_EXPR_CALL;
        ((long long*)(new_node))[1] = _eq_analyzer_copy_node(a, ((long long*)(node))[1]);
         args = ((long long*)(node))[2];  new_args = _eq_vec_new(_eq_vec_size(args));
         i = 0;  n_size = _eq_vec_size(args);
        while (i < n_size) { new_args = _eq_vec_push(new_args, _eq_analyzer_copy_node(a, _eq_vec_get(args, i))); i = i + 1; }
        ((long long*)(new_node))[2] = new_args;
        ((long long*)(new_node))[3] = ((long long*)(node))[3]; ((long long*)(new_node))[4] = ((long long*)(node))[4]; ((long long*)(new_node))[5] = ((long long*)(node))[5];
    } else if (type == _eq_g_STMT_BLOCK) {
        new_node = _eq_analyzer_alloc(a, 4 * 8);
        ((long long*)(new_node))[0] = _eq_g_STMT_BLOCK;
         stmts = ((long long*)(node))[1];  new_stmts = _eq_vec_new(_eq_vec_size(stmts));
         i = 0;  s_size = _eq_vec_size(stmts);
        while (i < s_size) { new_stmts = _eq_vec_push(new_stmts, _eq_analyzer_copy_node(a, _eq_vec_get(stmts, i))); i = i + 1; }
        ((long long*)(new_node))[1] = new_stmts;
        ((long long*)(new_node))[2] = ((long long*)(node))[2]; ((long long*)(new_node))[3] = ((long long*)(node))[3];
    } else if (type == _eq_g_STMT_LET) {
        new_node = _eq_analyzer_alloc(a, 8 * 8);
        ((long long*)(new_node))[0] = _eq_g_STMT_LET;
        ((long long*)(new_node))[1] = ((long long*)(node))[1];
        ((long long*)(new_node))[2] = _eq_analyzer_copy_node(a, ((long long*)(node))[2]);
        ((long long*)(new_node))[3] = ((long long*)(node))[3]; ((long long*)(new_node))[4] = ((long long*)(node))[4]; ((long long*)(new_node))[5] = ((long long*)(node))[5];
        ((long long*)(new_node))[6] = ((long long*)(node))[6]; ((long long*)(new_node))[7] = ((long long*)(node))[7];
    } else if (type == _eq_g_EXPR_BINARY) {
        new_node = _eq_analyzer_alloc(a, 6 * 8);
        ((long long*)(new_node))[0] = _eq_g_EXPR_BINARY;
        ((long long*)(new_node))[1] = _eq_analyzer_copy_node(a, ((long long*)(node))[1]);
        ((long long*)(new_node))[2] = ((long long*)(node))[2];
        ((long long*)(new_node))[3] = _eq_analyzer_copy_node(a, ((long long*)(node))[3]);
        ((long long*)(new_node))[4] = ((long long*)(node))[4]; ((long long*)(new_node))[5] = ((long long*)(node))[5];
    } else if (type == _eq_g_EXPR_LITERAL) {
        new_node = _eq_analyzer_alloc(a, 4 * 8);
        ((long long*)(new_node))[0] = _eq_g_EXPR_LITERAL;
        ((long long*)(new_node))[1] = ((long long*)(node))[1];
        ((long long*)(new_node))[2] = ((long long*)(node))[2]; ((long long*)(new_node))[3] = ((long long*)(node))[3];
    } else if (type == _eq_g_STMT_RETURN) {
        new_node = _eq_analyzer_alloc(a, 4 * 8);
        ((long long*)(new_node))[0] = _eq_g_STMT_RETURN;
        ((long long*)(new_node))[1] = _eq_analyzer_copy_node(a, ((long long*)(node))[1]);
        ((long long*)(new_node))[2] = ((long long*)(node))[2]; ((long long*)(new_node))[3] = ((long long*)(node))[3];
    }
    return new_node;
}
long long _eq_arena_new(long long initial_size) {

    return _eq_arena_new_owned(initial_size, 0);
}
long long _eq_arena_new_owned(long long initial_size, long long owner_id) {
    volatile long long a = 0;
    volatile long long buf = 0;

     a = sys_malloc(8 * 8);
     buf = sys_malloc(initial_size);
    ((long long*)(a))[0] = buf;
    ((long long*)(a))[1] = buf;
    ((long long*)(a))[2] = buf + initial_size;
    ((long long*)(a))[3] = 0;
    ((long long*)(a))[4] = owner_id;
    return a;
}
long long _eq_arena_alloc(long long a, long long size) {
    volatile long long aligned_size = 0;
    volatile long long current_capacity = 0;
    volatile long long link = 0;
    volatile long long new_size = 0;
    volatile long long next_arena = 0;
    volatile long long old_base = 0;
    volatile long long old_curr = 0;
    volatile long long old_end = 0;
    volatile long long old_next = 0;
    volatile long long owner = 0;
    volatile long long p = 0;

     owner = ((long long*)(a))[4];
    if (owner != 0) {
        if (sys_get_agent() != owner) {
            _eq_print_err(((long long)"Security Violation: Unauthorized memory access by Agent "));
            print_raw_stderr(sys_get_agent());
            _eq_print_err(((long long)" to Arena owned by Agent "));
            print_raw_stderr(owner);
            _eq_print_err(((long long)"\n"));
            exit(1);
        }
    }
     aligned_size = (size + 15) / 16 * 16;
    sys_assert(aligned_size >= size, ((long long)"Arena error: allocation size overflow"));
    if (((long long*)(a))[1] + aligned_size > ((long long*)(a))[2]) {
         current_capacity = ((long long*)(a))[2] - ((long long*)(a))[0];
         new_size = current_capacity * 2;
        if (new_size < aligned_size) { new_size = aligned_size * 2; }
         next_arena = _eq_arena_new(new_size);
         old_base = ((long long*)(a))[0];
         old_curr = ((long long*)(a))[1];
         old_end = ((long long*)(a))[2];
         old_next = ((long long*)(a))[3];
         link = sys_malloc(4 * 16);
        ((long long*)(link))[0] = old_base; ((long long*)(link))[1] = old_curr; ((long long*)(link))[2] = old_end; ((long long*)(link))[3] = old_next;
        ((long long*)(a))[0] = ((long long*)(next_arena))[0];
        ((long long*)(a))[1] = ((long long*)(next_arena))[1];
        ((long long*)(a))[2] = ((long long*)(next_arena))[2];
        ((long long*)(a))[3] = link;
        free((void*)next_arena);
    }
     p = ((long long*)(a))[1];
    ((long long*)(a))[1] = ((long long*)(a))[1] + aligned_size;
    return p;
}
long long _eq_arena_free_all(long long a) {
    volatile long long curr = 0;
    volatile long long next = 0;

     curr = a;
    while (curr != 0) {
        next = ((long long*)(curr))[3];
        free((void*)((long long*)(curr))[0]);
        free((void*)curr);
        curr = next;
    }
    ((long long*)(a))[1] = ((long long*)(a))[0];
    ((long long*)(a))[3] = 0;
}
long long _eq_get_expr_type(long long a, long long expr) {
    volatile long long dot = 0;
    volatile long long entry = 0;
    volatile long long i = 0;
    volatile long long len = 0;
    volatile long long type = 0;
    volatile long long val = 0;

    if (expr == 0) { return 0; }
     type = ((long long*)(expr))[0];
    if (type == _eq_g_EXPR_LITERAL) {
         val = ((long long*)(expr))[1];
        if (_eq_str_equal(val, ((long long)"true")) || _eq_str_equal(val, ((long long)"false"))) { return _eq_g_TOKEN_BOOL; }
         i = 0;  len = sys_strlen(val);  dot = 0;
        while (i < len) { if (get_char(val, i) == 46) { dot = 1; } i = i + 1; }
        if (dot) { return _eq_g_TOKEN_F64; }
        return _eq_g_TOKEN_I64;
    }
    if (type == _eq_g_EXPR_VARIABLE) {
         entry = _eq_analyzer_resolve(a, ((long long*)(expr))[1]);
        if (entry) { return ((long long*)(entry))[2]; }
        return 0;
    }
    if (type == _eq_g_EXPR_BINARY) {
        return _eq_get_expr_type(a, ((long long*)(expr))[1]); 
    }
    return 0;
}
long long _eq_verify_type_match(long long a, long long expected, long long actual_node, long long line, long long col) {
    volatile long long actual = 0;
    volatile long long msg = 0;

    if (expected == 0) { return 1; }
     actual = _eq_get_expr_type(a, actual_node);
    if (actual == 0) { return 1; } 
    if (expected != actual) {
         msg = _eq_str_concat(((long long)"Type Mismatch: Expected type token "), _eq_str_from_int(expected));
        msg = _eq_str_concat(msg, ((long long)" but found "));
        msg = _eq_str_concat(msg, _eq_str_from_int(actual));
        _eq_analyze_error_internal(a, msg, line, col);
    }
    return 1;
}
long long _eq_analyze_expr(long long a, long long expr) {
    volatile long long arg = 0;
    volatile long long args = 0;
    volatile long long callee = 0;
    volatile long long gen_name = 0;
    volatile long long generics = 0;
    volatile long long i = 0;
    volatile long long mangled = 0;
    volatile long long name = 0;
    volatile long long obj = 0;
    volatile long long res = 0;
    volatile long long size = 0;
    volatile long long target = 0;
    volatile long long type = 0;

    if (expr == 0) { return 0; }
     type = 0;
     name = 0;
     res = 0;
     args = 0;
     i = 0;
     size = 0;
     target = 0;
     obj = 0;
    type = ((long long*)(expr))[0];
    if (type == _eq_g_EXPR_VARIABLE) {
        name = ((long long*)(expr))[1];
        res = _eq_analyzer_resolve(a, name);
        if (res == 0) {
            _eq_analyze_undeclared_internal(a, name, ((long long*)(expr))[2], ((long long*)(expr))[3]);
        } else {
            if (((long long*)(res))[5]) {
                _eq_analyze_error_internal(a, ((long long)"Ownership Error: Use of moved variable."), ((long long*)(expr))[2], ((long long*)(expr))[3]);
            }
        }
    } else if (type == _eq_g_EXPR_BINARY) {
        _eq_analyze_expr(a, ((long long*)(expr))[1]);
        _eq_analyze_expr(a, ((long long*)(expr))[3]);
    } else if (type == _eq_g_EXPR_UNARY) {
        _eq_analyze_expr(a, ((long long*)(expr))[2]);
    } else if (type == _eq_g_EXPR_CALL) {
         callee = ((long long*)(expr))[1];
         generics = ((long long*)(expr))[_eq_g_CALL_GENERICS];
        if (generics) {
            if (((long long*)(callee))[0] == _eq_g_EXPR_VARIABLE) {
                 gen_name = ((long long*)(callee))[1];
                 mangled = _eq_analyzer_specialize(a, gen_name, generics);
                if (mangled) {
                    ((long long*)(callee))[1] = mangled; 
                }
            }
        }
        _eq_analyze_expr(a, callee);
        args = ((long long*)(expr))[2];
        i = 0;
        size = _eq_vec_size(args);
         arg = 0;
        while (i < size) {
           arg = _eq_vec_get(args, i);
           _eq_analyze_expr(a, arg);
           i = i + 1;
        }
    } else if (type == _eq_g_EXPR_INDEX) {
        _eq_analyze_expr(a, ((long long*)(expr))[1]);
        _eq_analyze_expr(a, ((long long*)(expr))[2]);
    } else if (type == _eq_g_EXPR_ASSIGNMENT) {
        _eq_analyze_expr(a, ((long long*)(expr))[1]);
        if (((long long*)(a))[2]) {
            target = ((long long*)(expr))[1];
            if (((long long*)(target))[0] == _eq_g_EXPR_VARIABLE) {
                if (_eq_analyzer_is_global(a, ((long long*)(target))[1])) {
                    _eq_analyze_error_internal(a, ((long long)"Modification of global state inside event logic is prohibited."), ((long long*)(expr))[_eq_g_VAR_LINE], ((long long*)(expr))[_eq_g_VAR_COL]);
                }
            } else if (((long long*)(target))[0] == _eq_g_EXPR_INDEX) {
                obj = ((long long*)(target))[1];
                if (((long long*)(obj))[0] == _eq_g_EXPR_VARIABLE) {
                    if (_eq_analyzer_is_global(a, ((long long*)(obj))[1])) {
                        _eq_analyze_error_internal(a, ((long long)"Modification of indexed global state inside event logic is prohibited."), ((long long*)(expr))[_eq_g_INDEX_LINE], ((long long*)(expr))[_eq_g_INDEX_COL]);
                    }
                }
            } else if (((long long*)(target))[0] == _eq_g_EXPR_GET) {
                obj = ((long long*)(target))[1];
                if (((long long*)(obj))[0] == _eq_g_EXPR_VARIABLE) {
                    if (_eq_analyzer_is_global(a, ((long long*)(obj))[1])) {
                        _eq_analyze_error_internal(a, ((long long)"Modification of global properties inside event logic is prohibited."), ((long long*)(expr))[_eq_g_GET_LINE], ((long long*)(expr))[_eq_g_GET_COL]);
                    }
                }
            }
        }
        _eq_analyze_expr(a, ((long long*)(expr))[2]);
    } else if (type == _eq_g_EXPR_GET) {
        _eq_analyze_expr(a, ((long long*)(expr))[1]);
    } else if (type == _eq_g_EXPR_TRY) {
        _eq_analyze_expr(a, ((long long*)(expr))[1]);
        
        
    }
}
long long _eq_analyze_stmt(long long a, long long stmt) {
    volatile long long a_entry = 0;
    volatile long long a_node = 0;
    volatile long long a_role = 0;
    volatile long long agent_roles = 0;
    volatile long long ar = 0;
    volatile long long ar_size = 0;
    volatile long long val = 0;
    volatile long long res = 0;
    volatile long long args = 0;
    volatile long long authorized = 0;
    volatile long long e_entry = 0;
    volatile long long e_node = 0;
    volatile long long events = 0;
    volatile long long explicit_type = 0;
    volatile long long has_sig = 0;
    volatile long long i = 0;
    volatile long long p_size = 0;
    volatile long long params = 0;
    volatile long long r = 0;
    volatile long long r_size = 0;
    volatile long long req_role = 0;
    volatile long long required_roles = 0;
    volatile long long s = 0;
    volatile long long sig_agent_name = 0;
    volatile long long size = 0;
    volatile long long stmts = 0;
    volatile long long type = 0;
    volatile long long w = 0;

     type = 0;
     stmts = 0;
     i = 0;
     size = 0;
     params = 0;
     p_size = 0;
     events = 0;
     e_entry = 0;
     e_node = 0;
     args = 0;
     has_sig = 0;
     sig_agent_name = 0;
     required_roles = 0;
     a_entry = 0;
     a_node = 0;
     agent_roles = 0;
     r = 0;
     authorized = 0;
     req_role = 0;
     ar = 0;
     a_role = 0;
    if (stmt == 0) { return 0; }
    type = ((long long*)(stmt))[0];

    if (type == _eq_g_STMT_EXPRESSION) {
        _eq_analyze_expr(a, ((long long*)(stmt))[1]);
    } else if (type == _eq_g_STMT_LET) {
        val = ((long long*)(stmt))[_eq_g_LET_VAL];
        _eq_analyze_expr(a, val);
        if (val && ((long long*)(val))[0] == _eq_g_EXPR_VARIABLE) {
            res = _eq_analyzer_resolve(a, ((long long*)(val))[1]);
            if (res) { ((long long*)(res))[5] = 1; }
        }
         explicit_type = ((long long*)(stmt))[_eq_g_LET_TYPE];
        if (explicit_type) {
            _eq_verify_type_match(a, explicit_type, ((long long*)(stmt))[_eq_g_LET_VAL], ((long long*)(stmt))[_eq_g_LET_LINE], ((long long*)(stmt))[_eq_g_LET_COL]);
        }
        _eq_analyzer_define(a, ((long long*)(stmt))[_eq_g_LET_NAME], 0, explicit_type);
    } else if (type == _eq_g_STMT_BLOCK) {
        _eq_analyzer_begin_scope(a);
        stmts = ((long long*)(stmt))[1];
        i = 0;
        size = _eq_vec_size(stmts);
         s = 0;
        while (i < size) {
            s = _eq_vec_get(stmts, i);
            _eq_analyze_stmt(a, s);
            i = i + 1;
        }
        _eq_analyzer_end_scope(a);
    } else if (type == _eq_g_STMT_IF) {
        _eq_analyze_expr(a, ((long long*)(stmt))[1]);
        _eq_analyze_stmt(a, ((long long*)(stmt))[2]);
        if (((long long*)(stmt))[3]) {
            _eq_analyze_stmt(a, ((long long*)(stmt))[3]);
        }
    } else if (type == _eq_g_STMT_WHILE) {
        _eq_analyze_expr(a, ((long long*)(stmt))[1]);
        _eq_analyze_stmt(a, ((long long*)(stmt))[2]);
    } else if (type == _eq_g_STMT_RETURN) {
        if (((long long*)(stmt))[1]) { _eq_analyze_expr(a, ((long long*)(stmt))[1]); }
    } else if (type == _eq_g_STMT_PRINT) {
        _eq_analyze_expr(a, ((long long*)(stmt))[1]);
    } else if (type == _eq_g_STMT_FUNCTION) {
        _eq_analyzer_define(a, ((long long*)(stmt))[1], stmt, 0);
        _eq_analyzer_begin_scope(a);
        params = ((long long*)(stmt))[2];
        i = 0;
        p_size = _eq_vec_size(params);
        while (i < p_size) {
            _eq_analyzer_define(a, _eq_vec_get(params, i), 0, 0);
            i = i + 1;
        }
        _eq_analyze_stmt(a, ((long long*)(stmt))[3]);
        _eq_analyzer_end_scope(a);
    } else if (type == _eq_g_STMT_EXTERN) {
        _eq_analyzer_define(a, ((long long*)(stmt))[1], stmt, 0);
    } else if (type == _eq_g_STMT_STRUCT) {
        _eq_analyzer_define(a, ((long long*)(stmt))[1], stmt, 0);
    } else if (type == _eq_g_STMT_AGENT) {
        _eq_analyzer_define(a, ((long long*)(stmt))[_eq_g_AGENT_NAME], stmt, 0);
        if (((long long*)(stmt))[_eq_g_AGENT_IMPLEMENTS]) {
            _eq_verify_interface_implementation(a, ((long long*)(stmt))[_eq_g_AGENT_IMPLEMENTS], stmt, ((long long*)(stmt))[_eq_g_AGENT_LINE], ((long long*)(stmt))[_eq_g_AGENT_COL]);
        }
    } else if (type == _eq_g_STMT_RESOURCE) {
        _eq_analyzer_define(a, ((long long*)(stmt))[1], stmt, 0);
    } else if (type == _eq_g_STMT_INTERFACE) {
    } else if (type == _eq_g_STMT_EVENT) {
        _eq_analyze_event_duality(a, stmt);
    } else if (type == _eq_g_STMT_COMMITMENT) {
        _eq_analyze_event_duality(a, stmt);
    } else if (type == _eq_g_STMT_POLICY) {
        _eq_analyzer_define(a, ((long long*)(stmt))[1], stmt, 0);
        _eq_analyze_stmt(a, ((long long*)(stmt))[2]);
    } else if (type == _eq_g_STMT_REVERSE) {
        if (_eq_analyzer_resolve(a, ((long long*)(stmt))[1]) == 0) { _eq_analyze_error_internal(a, ((long long)"Unknown event to reverse"), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
    } else if (type == _eq_g_STMT_EXCHANGE) {
        _eq_analyzer_define(a, ((long long*)(stmt))[_eq_g_EXCHANGE_NAME], stmt, 0);
        events = ((long long*)(stmt))[_eq_g_EXCHANGE_EVENTS];  i = 0;  size = _eq_vec_size(events);
        while (i < size) {
            if (_eq_analyzer_resolve(a, _eq_vec_get(events, i)) == 0) { _eq_analyze_error_internal(a, ((long long)"Unknown event in exchange"), ((long long*)(stmt))[_eq_g_EXCHANGE_LINE], ((long long*)(stmt))[_eq_g_EXCHANGE_COL]); }
            i = i + 1;
        }
    } else if (type == _eq_g_STMT_TRANSFORMATION) {
        _eq_analyze_event_duality(a, stmt);
    } else if (type == _eq_g_STMT_VALUATOR) {
        _eq_analyzer_define(a, ((long long*)(stmt))[_eq_g_VALUATOR_NAME], stmt, 0);
        if (((long long*)(stmt))[_eq_g_VALUATOR_IMPLEMENTS]) {
            _eq_verify_interface_implementation(a, ((long long*)(stmt))[_eq_g_VALUATOR_IMPLEMENTS], stmt, ((long long*)(stmt))[_eq_g_VALUATOR_LINE], ((long long*)(stmt))[_eq_g_VALUATOR_COL]);
        }
        _eq_analyze_stmt(a, ((long long*)(stmt))[_eq_g_VALUATOR_BODY]);
    } else if (type == _eq_g_STMT_EXECUTE) {
        e_entry = _eq_analyzer_resolve(a, ((long long*)(stmt))[1]);
        if (e_entry == 0) { _eq_analyze_error_internal(a, ((long long)"Execution Violation: Event must be declared before execution."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
        e_node = ((long long*)(e_entry))[1];
        args = ((long long*)(stmt))[2];  i = 0;  size = _eq_vec_size(args);
        has_sig = 0;
        sig_agent_name = 0;
        while (i < size) {
            if (_eq_str_equal(_eq_vec_get(args, i), ((long long)"sig"))) {
                has_sig = 1;
                if (i + 1 < size) { sig_agent_name = _eq_vec_get(args, i + 1); }
            }
            i = i + 2;
        }
        if (has_sig == 0) {
            _eq_analyze_error_internal(a, ((long long)"Instruction execution requires a 'sig' (Digital Signature)."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]);
        }
        if (e_node != 0) {
            if (((long long*)(e_node))[0] == _eq_g_STMT_EVENT) {
                required_roles = ((long long*)(e_node))[_eq_g_EVENT_ROLES];
                if (required_roles) {
                    if (sig_agent_name == 0) { _eq_analyze_error_internal(a, ((long long)"Legal Violation: Event requires a signatory agent with specific roles."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
                    a_entry = _eq_analyzer_resolve(a, sig_agent_name);
                    if (a_entry == 0) { _eq_analyze_error_internal(a, ((long long)"Legal Violation: Signatory agent not found."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); return 0; }
                    a_node = ((long long*)(a_entry))[1];
                    agent_roles = 0;
                    if (a_node != 0) {
                        if (((long long*)(a_node))[0] == _eq_g_STMT_AGENT) { agent_roles = ((long long*)(a_node))[_eq_g_AGENT_ROLES]; }
                    }
                r = 0;  r_size = _eq_vec_size(required_roles);
                authorized = 0;
                while (r < r_size) {
                    req_role = _eq_vec_get(required_roles, r);
                    if (agent_roles) {
                        ar = 0;  ar_size = _eq_vec_size(agent_roles);
                        while (ar < ar_size) {
                             a_role = _eq_vec_get(agent_roles, ar);
                             if (_eq_str_equal(a_role, req_role)) { authorized = 1; }
                             ar = ar + 1;
                        }
                    }
                    r = r + 1;
                }
                if (authorized == 0) {
                    _eq_analyze_error_internal(a, ((long long)"Legal Violation: Agent lacks required roles for this Event (Non-Compliant Executive)."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]);
                }
            }
          }
        }
    } else if (type == _eq_g_STMT_ASSERT) {
        _eq_analyze_expr(a, ((long long*)(stmt))[1]);
    }
}
long long _eq_analyze_event_duality(long long a, long long stmt) {
    volatile long long amount = 0;
    volatile long long amount_expr = 0;
    volatile long long authorized_valuator = 0;
    volatile long long balance_map = 0;
    volatile long long c_flows = 0;
    volatile long long c_logic = 0;
    volatile long long col = 0;
    volatile long long current_bal = 0;
    volatile long long current_bal_entry = 0;
    volatile long long e_fulfills = 0;
    volatile long long f_agent = 0;
    volatile long long f_node = 0;
    volatile long long has_in = 0;
    volatile long long has_out = 0;
    volatile long long i = 0;
    volatile long long interned_res = 0;
    volatile long long k = 0;
    volatile long long k_size = 0;
    volatile long long line = 0;
    volatile long long name = 0;
    volatile long long new_bal_entry = 0;
    volatile long long r_bal = 0;
    volatile long long r_bal_entry = 0;
    volatile long long r_key = 0;
    volatile long long res_entry = 0;
    volatile long long res_keys = 0;
    volatile long long res_name = 0;
    volatile long long size = 0;
    volatile long long t_agent = 0;
    volatile long long type = 0;
    volatile long long v_entry = 0;
    volatile long long v_name = 0;
    volatile long long v_node = 0;

     name = 0;
     c_logic = 0;
     c_flows = 0;
     line = 0;
     e_fulfills = 0;
     size = 0;
     has_in = 0;
     has_out = 0;
     balance_map = 0;
     i = 0;
     f_node = 0;
     type = 0;
     amount_expr = 0;
     amount = 0;
     res_name = 0;
     res_entry = 0;
     f_agent = 0;
     t_agent = 0;
     interned_res = 0;
     current_bal_entry = 0;
     current_bal = 0;
     new_bal_entry = 0;
     v_name = 0;
     res_keys = 0;
     k = 0;
     k_size = 0;
     r_key = 0;
     r_bal_entry = 0;
     r_bal = 0;
     authorized_valuator = 0;
     v_entry = 0;
     v_node = 0;
    name = ((long long*)(stmt))[1];
    c_logic = ((long long*)(stmt))[2];
    c_flows = ((long long*)(stmt))[3];
    line = ((long long*)(stmt))[4];
     col = ((long long*)(stmt))[5];
    e_fulfills = 0;
    if (((long long*)(stmt))[0] == _eq_g_STMT_EVENT) { e_fulfills = ((long long*)(stmt))[6]; }
    if (e_fulfills) {
        if (_eq_analyzer_resolve(a, e_fulfills) == 0) {
            _eq_analyze_error_internal(a, ((long long)"Legal Violation: Fulfillment target (Commitment) not found."), line, col);
        }
    } else if (((long long*)(stmt))[0] == _eq_g_STMT_EVENT) {
        if (_eq_str_equal(name, ((long long)"Genesis")) == 0) {
            _eq_analyze_error_internal(a, ((long long)"Event must fulfill a commitment or contract."), line, col);
        }
    }
    _eq_analyzer_define(a, name, stmt, 0);
    if (c_logic) {
        ((long long*)(a))[2] = 1;
        _eq_analyze_stmt(a, c_logic);
        ((long long*)(a))[2] = 0;
    }
    size = _eq_vec_size(c_flows);
    if (size == 0) { return 0; }
    has_in = 0;
    has_out = 0;
    balance_map = _eq_map_new(16);
    i = 0;
    while (i < size) {
        f_node = _eq_vec_get(c_flows, i);
        type = ((long long*)(f_node))[1];
        amount_expr = ((long long*)(f_node))[2];
        amount = 0;
        if (((long long*)(amount_expr))[0] == _eq_g_EXPR_LITERAL) {
            amount = ((long long*)(amount_expr))[1];
            if (amount <= 0) { _eq_analyze_error_internal(a, ((long long)"Flow amount must be positive."), ((long long*)(f_node))[6], ((long long*)(f_node))[7]); }
        }
        res_name = ((long long*)(f_node))[3];
        res_entry = _eq_analyzer_resolve(a, res_name);
        if (res_entry == 0) { _eq_analyze_error_internal(a, ((long long)"Resource must be declared before use."), ((long long*)(f_node))[6], ((long long*)(f_node))[7]); }
        f_agent = ((long long*)(f_node))[4];
        t_agent = ((long long*)(f_node))[5];
        if (_eq_analyzer_resolve(a, f_agent) == 0) { _eq_analyze_error_internal(a, ((long long)"Sovereignty Violation: Source Agent must be declared."), ((long long*)(f_node))[6], ((long long*)(f_node))[7]); }
        if (_eq_analyzer_resolve(a, t_agent) == 0) { _eq_analyze_error_internal(a, ((long long)"Sovereignty Violation: Destination Agent must be declared."), ((long long*)(f_node))[6], ((long long*)(f_node))[7]); }
        if (_eq_intern_string(f_agent) == _eq_intern_string(t_agent)) {
            _eq_analyze_error_internal(a, ((long long)"Agent cannot flow resource to self."), line, col);
        }
        interned_res = _eq_intern_string(res_name);
        current_bal_entry = _eq_map_get(balance_map, interned_res);
        current_bal = 0;
        if (current_bal_entry) { current_bal = ((long long*)(current_bal_entry))[0]; }
        if (type == _eq_g_TOKEN_IN) {
            has_in = 1;
            current_bal = current_bal + amount;
        }
        if (type == _eq_g_TOKEN_OUT) {
            has_out = 1;
            current_bal = current_bal - amount;
        }
        new_bal_entry = sys_malloc(8);
        ((long long*)(new_bal_entry))[0] = current_bal;
        _eq_map_put(balance_map, interned_res, new_bal_entry);
        i = i + 1;
    }
    v_name = 0;
    if (((long long*)(stmt))[0] == _eq_g_STMT_EVENT) { v_name = ((long long*)(stmt))[7]; }
    if (((long long*)(stmt))[0] == _eq_g_STMT_COMMITMENT) { v_name = ((long long*)(stmt))[5]; }
    res_keys = _eq_map_keys(balance_map);
    k = 0;
    k_size = _eq_vec_size(res_keys);
    while (k < k_size) {
        r_key = _eq_vec_get(res_keys, k);
        r_bal_entry = _eq_map_get(balance_map, r_key);
        r_bal = ((long long*)(r_bal_entry))[0];
        if (r_bal != 0) {
            authorized_valuator = 0;
            if (v_name != 0) {
                v_entry = _eq_analyzer_resolve(a, v_name);
                if (v_entry) {
                    v_node = ((long long*)(v_entry))[1];
                    if (v_node) {
                        if (((long long*)(v_node))[0] == _eq_g_STMT_VALUATOR || ((long long*)(v_node))[0] == _eq_g_STMT_FUNCTION) {
                            authorized_valuator = 1;
                        }
                    }
                }
            }
                if (authorized_valuator == 0) {
                if (v_name == 0) {
                    _eq_analyze_error_internal(a, ((long long)"Resource balance mismatch. Every resource must be balanced in a single Event unless part of a verified Exchange/Valuator."), line, col);
                } else {
                    _eq_analyze_error_internal(a, ((long long)"Economic Violation: Unauthorized or Unknown Valuator/Exchange used to bypass duality."), line, col);
                }
            }
        }
        k = k + 1;
    }
    if (has_in + has_out == 1) {
        _eq_analyze_error_internal(a, ((long long)"REA Duality Violation: Economic Event must have reciprocal flows (In and Out)."), line, col);
    }
}
long long _eq_verify_interface_implementation(long long a, long long i_name, long long target, long long line, long long col) {
    volatile long long body = 0;
    volatile long long found = 0;
    volatile long long i_entry = 0;
    volatile long long i_stmt = 0;
    volatile long long m_i = 0;
    volatile long long m_name = 0;
    volatile long long m_p_size = 0;
    volatile long long m_params = 0;
    volatile long long m_size = 0;
    volatile long long method = 0;
    volatile long long methods = 0;
    volatile long long s = 0;
    volatile long long s_i = 0;
    volatile long long s_size = 0;
    volatile long long stmts = 0;

     i_entry = 0;
     i_stmt = 0;
     methods = 0;
     m_i = 0;
     m_size = 0;
     method = 0;
     m_name = 0;
     m_params = 0;
     m_p_size = 0;
     found = 0;
     body = 0;
     stmts = 0;
     s_i = 0;
     s = 0;
    i_entry = _eq_analyzer_resolve(a, i_name);
    if (i_entry == 0) { _eq_analyze_error_internal(a, ((long long)"Contract Violation: Implementation of unknown interface."), line, col); }
    i_stmt = ((long long*)(i_entry))[1];
    if (((long long*)(i_stmt))[0] != _eq_g_STMT_INTERFACE) { _eq_analyze_error_internal(a, ((long long)"Contract Violation: Target is not an interface."), line, col); }
    methods = ((long long*)(i_stmt))[2];
    m_i = 0;
    m_size = _eq_vec_size(methods);
    while (m_i < m_size) {
        method = _eq_vec_get(methods, m_i);
        m_name = ((long long*)(method))[0];
        m_params = ((long long*)(method))[1];
        m_p_size = _eq_vec_size(m_params);
        found = 0;
        if (((long long*)(target))[0] == _eq_g_STMT_VALUATOR) {
            body = ((long long*)(target))[2];
            stmts = ((long long*)(body))[1];
            s_i = 0;  s_size = _eq_vec_size(stmts);
            while (s_i < s_size) {
                s = _eq_vec_get(stmts, s_i);
                if (((long long*)(s))[0] == _eq_g_STMT_FUNCTION) {
                    if (_eq_str_equal(((long long*)(s))[1], m_name)) {
                        found = 1;
                        if (_eq_vec_size(((long long*)(s))[2]) != m_p_size) {
                            _eq_analyze_error_internal(a, ((long long)"Contract Violation: Method parameter count mismatch."), line, col);
                        }
                    }
                }
                s_i = s_i + 1;
            }
        } else if (((long long*)(target))[0] == _eq_g_STMT_AGENT) {
            found = 1;
        }
            if (found == 0) {
            _eq_analyze_error_internal(a, ((long long)"Contract Violation: Missing interface method implementation."), line, col);
            }
        m_i = m_i + 1;
    }
}
long long _eq_analyze_program(long long a, long long ast) {
    volatile long long i = 0;
    volatile long long k = 0;
    volatile long long name = 0;
    volatile long long p_size = 0;
    volatile long long params = 0;
    volatile long long size = 0;
    volatile long long stmt = 0;
    volatile long long type = 0;

     i = 0;
     size = 0;
     stmt = 0;
     type = 0;
     stmt = 0;
     type = 0;
     params = 0;
     k = 0;
     p_size = 0;
     name = 0;
    i = 0;
    size = _eq_vec_size(ast);
    while (i < size) {
        stmt = _eq_vec_get(ast, i);
        type = ((long long*)(stmt))[0];
        if (type == _eq_g_STMT_FUNCTION || type == _eq_g_STMT_EXTERN || type == _eq_g_STMT_LET || type == _eq_g_STMT_STRUCT || type == _eq_g_STMT_AGENT || type == _eq_g_STMT_RESOURCE || type == _eq_g_STMT_EVENT || type == _eq_g_STMT_COMMITMENT || type == _eq_g_STMT_POLICY || type == _eq_g_STMT_EXCHANGE || type == _eq_g_STMT_TRANSFORMATION || type == _eq_g_STMT_VALUATOR || type == _eq_g_STMT_INTERFACE) {
            _eq_analyzer_define(a, ((long long*)(stmt))[1], stmt, 0);
        }
        i = i + 1;
    }
    i = 0;
    while (i < size) {
        stmt = _eq_vec_get(ast, i);
        type = ((long long*)(stmt))[0];
        if (type == _eq_g_STMT_FUNCTION) {
            _eq_analyzer_begin_scope(a);
            params = ((long long*)(stmt))[2];
            k = 0;
            p_size = _eq_vec_size(params);
            while (k < p_size) {
                _eq_analyzer_define(a, _eq_vec_get(params, k), 0, 0);
                k = k + 1;
            }
            _eq_analyze_stmt(a, ((long long*)(stmt))[3]);
            _eq_analyzer_end_scope(a);
        } else if (type == _eq_g_STMT_EXTERN) {
            name = ((long long*)(stmt))[1];
            if (_eq_str_equal(name, ((long long)"system"))) { _eq_analyze_error_internal(a, ((long long)"Security Violation: Access to 'system' is blocked."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
            if (_eq_str_equal(name, ((long long)"execv"))) { _eq_analyze_error_internal(a, ((long long)"Security Violation: Access to 'exec' family is blocked."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
            if (_eq_str_equal(name, ((long long)"popen"))) { _eq_analyze_error_internal(a, ((long long)"Security Violation: Access to 'popen' is blocked."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
            if (_eq_str_equal(name, ((long long)"fork"))) { _eq_analyze_error_internal(a, ((long long)"Security Violation: Access to 'fork' is blocked."), ((long long*)(stmt))[3], ((long long*)(stmt))[4]); }
        } else if (type == _eq_g_STMT_LET) {
            if (((long long*)(stmt))[2]) { _eq_analyze_expr(a, ((long long*)(stmt))[2]); }
        } else {
            _eq_analyze_stmt(a, stmt);
        }
        i = i + 1;
    }
}
long long _eq_analyzer_substitute_types(long long a, long long node, long long generics, long long types) {
    volatile long long args = 0;
    volatile long long i = 0;
    volatile long long name = 0;
    volatile long long size = 0;
    volatile long long stmts = 0;
    volatile long long type = 0;

    if (node == 0) { return 0; }
     type = ((long long*)(node))[0];
    if (type == _eq_g_EXPR_VARIABLE) {
         name = ((long long*)(node))[1];
         i = 0;  size = _eq_vec_size(generics);
        while (i < size) {
            if (_eq_str_equal(name, _eq_vec_get(generics, i))) {
                ((long long*)(node))[1] = _eq_vec_get(types, i);
                return 1;
            }
            i = i + 1;
        }
    } else if (type == _eq_g_EXPR_CALL) {
        _eq_analyzer_substitute_types(a, ((long long*)(node))[1], generics, types);
         args = ((long long*)(node))[2];  i = 0; while (i < _eq_vec_size(args)) { _eq_analyzer_substitute_types(a, _eq_vec_get(args, i), generics, types); i = i + 1; }
    } else if (type == _eq_g_STMT_BLOCK) {
         stmts = ((long long*)(node))[1];  i = 0; while (i < _eq_vec_size(stmts)) { _eq_analyzer_substitute_types(a, _eq_vec_get(stmts, i), generics, types); i = i + 1; }
    } else if (type == _eq_g_STMT_LET) {
        _eq_analyzer_substitute_types(a, ((long long*)(node))[2], generics, types);
    } else if (type == _eq_g_EXPR_BINARY) {
        _eq_analyzer_substitute_types(a, ((long long*)(node))[1], generics, types);
        _eq_analyzer_substitute_types(a, ((long long*)(node))[3], generics, types);
    } else if (type == _eq_g_STMT_RETURN) {
        _eq_analyzer_substitute_types(a, ((long long*)(node))[1], generics, types);
    }
    return 0;
}
long long _eq_analyzer_specialize(long long a, long long gen_func_name, long long types) {
    volatile long long entry = 0;
    volatile long long func_node = 0;
    volatile long long generics = 0;
    volatile long long i = 0;
    volatile long long mangled = 0;
    volatile long long new_func = 0;
    volatile long long size = 0;
     entry = _eq_analyzer_resolve(a, gen_func_name);
    if (entry == 0) { return 0; }
     func_node = ((long long*)(entry))[1];
     generics = ((long long*)(func_node))[_eq_g_FUNC_GENERICS];
    if (generics == 0) { return gen_func_name; }
    
    
     mangled = gen_func_name;
     i = 0;  size = _eq_vec_size(types);
    while (i < size) {
        mangled = _eq_str_concat(mangled, ((long long)"_m_"));
        mangled = _eq_str_concat(mangled, _eq_vec_get(types, i));
        i = i + 1;
    }
    mangled = _eq_intern_string(mangled);
    
    
    if (_eq_map_get(((long long*)(a))[5], mangled)) { return mangled; }
    
    
     new_func = _eq_analyzer_copy_node(a, func_node);
    ((long long*)(new_func))[_eq_g_FUNC_NAME] = mangled;
    ((long long*)(new_func))[_eq_g_FUNC_GENERICS] = 0; 
    _eq_analyzer_substitute_types(a, ((long long*)(new_func))[_eq_g_FUNC_BODY], generics, types);
    
    
    _eq_map_put(((long long*)(a))[5], mangled, new_func);
    
    
    _eq_analyzer_define(a, mangled, new_func, 0);
    _eq_analyze_stmt(a, new_func);
    
    return mangled;
}
long long _eq_codegen_print_char(long long c) {

    if (_eq_g_print_buf == 0) { _eq_g_print_buf = sys_malloc(1024); }
    set_char(_eq_g_print_buf, 0, c);
    sys_write_raw(1, _eq_g_print_buf, 1);
    return 0;
}
long long _eq_emit_ln(long long s) {

    sys_write_raw(1, ((long long)"    "), 4);
    sys_write_raw(1, s, _eq_str_len(s));
    sys_write_raw(1, ((long long)"\n"), 1);
}
long long _eq_gen_release_locals(long long c, long long vars) {
    volatile long long entry = 0;
    volatile long long i = 0;
    volatile long long ptr = 0;
    volatile long long reg = 0;
    volatile long long size = 0;

    if (vars == 0) { return 0; }
     i = 0;  size = _eq_vec_size(vars);
    while (i < size) {
         entry = _eq_vec_get(vars, i);
         ptr = ((long long*)(entry))[1];
         reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = load i64, ptr %p")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)"\n"));
        
        i = i + 1;
    }
}
long long _eq_freshen_reg(long long c) {
    if (c < 4096) return 0;
    volatile long long id = 0;

     id = ((long long*)(c))[0];
    ((long long*)(c))[0] = ((long long*)(c))[0] + 1;
    return id;
}
long long _eq_freshen_ptr(long long c) {
    if (c < 4096) return 0;
    volatile long long id = 0;

     id = ((long long*)(c))[0];
    ((long long*)(c))[0] = ((long long*)(c))[0] + 1;
    return id;
}
long long _eq_freshen_label(long long c) {
    if (c < 4096) return 0;
    volatile long long l = 0;

     l = ((long long*)(c))[1];
    ((long long*)(c))[1] = ((long long*)(c))[1] + 1;
    return l;
}
long long _eq_gen_string_label(long long c, long long val) {
    if (c < 4096) return 0;
    volatile long long entry = 0;
    volatile long long found = 0;
    volatile long long found_ptr = 0;
    volatile long long strings = 0;

    if (_eq_g_String_Map == 0) { _eq_g_String_Map = _eq_map_new(2000); }
     found_ptr = _eq_map_get(_eq_g_String_Map, val);
     found = -1;
    if (found_ptr) { found = ((long long*)(found_ptr))[0] - 1; }
    if (found == -1) {
         strings = ((long long*)(c))[2];
        found = _eq_vec_size(strings);
        ((long long*)(c))[2] = _eq_vec_push(strings, val);
         entry = sys_malloc(16); ((long long*)(entry))[0] = found + 1;
        _eq_map_put(_eq_g_String_Map, val, entry);
    }
    return found;
}
long long _eq_is_extern(long long c, long long name) {
    volatile long long fn_name = 0;
    volatile long long fns = 0;
    volatile long long i = 0;
    volatile long long size = 0;

     fns = ((long long*)(c))[3];  i = 0;  size = _eq_vec_size(fns);
     fn_name = 0;
    while (i < size) {
        fn_name = _eq_vec_get(fns, i);
        if (_eq_str_equal(fn_name, name)) { return 1; }
        i = i + 1;
    }
    return 0;
}
long long _eq_is_defined(long long c, long long name) {
    volatile long long fn_name = 0;
    volatile long long fns = 0;
    volatile long long i = 0;
    volatile long long size = 0;

     fns = ((long long*)(c))[5];  i = 0;  size = _eq_vec_size(fns);
     fn_name = 0;
    while (i < size) {
        fn_name = _eq_vec_get(fns, i);
        if (_eq_str_equal(fn_name, name)) { return 1; }
        i = i + 1;
    }
    return 0;
}
long long _eq_print_escaped_str(long long s) {
    volatile long long c = 0;
    volatile long long h1 = 0;
    volatile long long h2 = 0;
    volatile long long i = 0;
    volatile long long len = 0;

     len = sys_strlen(s);
     i = 0;
    while (i < len) {
         c = get_char(s, i);
        if (c == 34) { _eq_print_raw_str(((long long)"\\22")); }
        else if (c == 92) { _eq_print_raw_str(((long long)"\\\\")); }
        else if (c >= 32 && c <= 126) { _eq_codegen_print_char(c); }
        else {
            _eq_print_raw_str(((long long)"\\"));
             h1 = c / 16;  h2 = c - (h1 * 16);
            if (h1 < 10) { _eq_codegen_print_char(h1 + 48); } else { _eq_codegen_print_char(h1 + 55); }
            if (h2 < 10) { _eq_codegen_print_char(h2 + 48); } else { _eq_codegen_print_char(h2 + 55); }
        }
        i = i + 1;
    }
}
long long _eq_gen_expr(long long c, long long expr) {
    if (c < 4096 || expr < 4096) return 0;
    volatile long long a_res = 0;
    volatile long long arg_count = 0;
    volatile long long arg_results = 0;
    volatile long long args = 0;
    volatile long long arr = 0;
    volatile long long arr_ptr = 0;
    volatile long long callee = 0;
    volatile long long callee_name = 0;
    volatile long long char_ptr = 0;
    volatile long long check_reg = 0;
    volatile long long entry = 0;
    volatile long long field_name = 0;
    volatile long long field_ptr = 0;
    volatile long long folded = 0;
    volatile long long found_local = 0;
    volatile long long handled = 0;
    volatile long long i_args = 0;
    volatile long long i_res = 0;
    volatile long long idx = 0;
    volatile long long is_magic = 0;
    volatile long long k = 0;
    volatile long long l_err = 0;
    volatile long long l_ok = 0;
    volatile long long l_res = 0;
    volatile long long l_skip = 0;
    volatile long long label_idx = 0;
    volatile long long locals = 0;
    volatile long long lv = 0;
    volatile long long name = 0;
    volatile long long next_reg = 0;
    volatile long long obj = 0;
    volatile long long obj_assign_result = 0;
    volatile long long obj_ptr = 0;
    volatile long long offset = 0;
    volatile long long offset_entry = 0;
    volatile long long old_reg = 0;
    volatile long long op = 0;
    volatile long long operand = 0;
    volatile long long p_res = 0;
    volatile long long ptr = 0;
    volatile long long r_res = 0;
    volatile long long reg = 0;
    volatile long long res = 0;
    volatile long long rv = 0;
    volatile long long s_res = 0;
    volatile long long s_val = 0;
    volatile long long sig_ptr = 0;
    volatile long long sig_res = 0;
    volatile long long target = 0;
    volatile long long type = 0;
    volatile long long v_idx = 0;
    volatile long long v_res = 0;
    volatile long long val = 0;
    volatile long long val_reg = 0;
    volatile long long value = 0;

    if (expr < 4096) { return 0; }
     type = ((long long*)(expr))[0];
     res = 0;  l_res = 0;  r_res = 0;  op = 0;  reg = 0;
     lv = 0;  rv = 0;  folded = 0;  handled = 0;
     name = 0;  val = 0;  found_local = 0;
     locals = 0;  v_idx = 0;  entry = 0;
     callee = 0;  args = 0;  arg_count = 0;  arg_results = 0;
     i_args = 0;  callee_name = 0;  is_magic = 0;  k = 0;
     a_res = 0;  arr = 0;  idx = 0;  check_reg = 0;
     l_ok = 0;  l_err = 0;  arr_ptr = 0;  ptr = 0;
     obj = 0;  field_name = 0;  offset_entry = 0;  offset = 0;
     obj_ptr = 0;  field_ptr = 0;  val_reg = 0;
     target = 0;  value = 0;  old_reg = 0;
     obj_assign_result = 0;  s_val = 0;  s_res = 0;  i_res = 0;
     v_res = 0;  char_ptr = 0;  p_res = 0;
     sig_res = 0;  sig_ptr = 0;  l_skip = 0;
     label_idx = 0;
    
    if (type == _eq_g_EXPR_LITERAL) {
        res = sys_malloc(2 * 8); ((long long*)(res))[0] = 0; ((long long*)(res))[1] = ((long long*)(expr))[1];
        return res;
    }
    if (type == _eq_g_EXPR_STRING_LITERAL) {
        label_idx = _eq_gen_string_label(c, ((long long*)(expr))[1]);
        reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = ptrtoint ptr @str.")); _eq_print_raw(label_idx); _eq_emit_ln(((long long)" to i64"));
        res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg;
        return res;
    }
    if (type == _eq_g_EXPR_VARIABLE) {
         name = ((long long*)(expr))[1];
        if (((long long*)(c))[4]) {
             locals = ((long long*)(c))[4];  v_idx = _eq_vec_size(locals) - 1;
            while (v_idx >= 0) {
                 entry = _eq_vec_get(locals, v_idx);
                if (_eq_str_equal(((long long*)(entry))[0], name)) {
                     reg = _eq_freshen_reg(c);
                    _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = load i64, ptr %p")); _eq_print_raw(((long long*)(entry))[1]); _eq_emit_ln(((long long)""));
                     res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg;
                    return res;
                }
                v_idx = v_idx - 1;
            }
        }
        
        
        if (_eq_is_extern(c, name)) {
             reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = ptrtoint ptr @")); _eq_print_raw_str(name); _eq_emit_ln(((long long)" to i64"));
             res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg;
            return res;
        }

         reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = load i64, ptr @Global_")); _eq_print_raw_str(name); _eq_emit_ln(((long long)""));
         res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg;
        return res;
    }
    if (type == _eq_g_EXPR_TRY) {
        val = _eq_gen_expr(c, ((long long*)(expr))[1]);
        l_err = _eq_freshen_label(c);
        l_ok = _eq_freshen_label(c);
        reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp eq i64 "));
        if (((long long*)(val))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(val))[1]); _eq_emit_ln(((long long)", 0"));
        _eq_print_raw_str(((long long)"    br i1 %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_err); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_ok); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_err); _eq_print_raw_str(((long long)":\n"));
        _eq_gen_release_locals(c, ((long long*)(c))[4]);
        _eq_emit_ln(((long long)"    ret i64 0"));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_ok); _eq_print_raw_str(((long long)":\n"));
        return val;
    }
    if (type == _eq_g_EXPR_BINARY) {
        l_res = _eq_gen_expr(c, ((long long*)(expr))[1]);
        r_res = _eq_gen_expr(c, ((long long*)(expr))[3]);
        op = ((long long*)(expr))[2];

        if (((long long*)(l_res))[0] == 0 && ((long long*)(r_res))[0] == 0) {
            lv = ((long long*)(l_res))[1]; rv = ((long long*)(r_res))[1];
            folded = 0; handled = 0;
            if (op == _eq_g_TOKEN_PLUS) { folded = lv + rv; handled = 1; }
            if (op == _eq_g_TOKEN_MINUS) { folded = lv - rv; handled = 1; }
            if (op == _eq_g_TOKEN_ASTERISK) { folded = lv * rv; handled = 1; }
            if (op == _eq_g_TOKEN_SLASH) { if (rv != 0) { folded = lv / rv; handled = 1; } }
            if (op == _eq_g_TOKEN_PERCENT) { if (rv != 0) { folded = lv - (lv / rv * rv); handled = 1; } }
            if (op == _eq_g_TOKEN_EQUAL_EQUAL) { if (lv == rv) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_BANG_EQUAL) { if (lv != rv) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_LESS) { if (lv < rv) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_LESS_EQUAL) { if (lv <= rv) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_GREATER) { if (lv > rv) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_GREATER_EQUAL) { if (lv >= rv) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_OR) { if (lv != 0 || rv != 0) { folded = 1; } handled = 1; }
            if (op == _eq_g_TOKEN_AND) { if (lv != 0 && rv != 0) { folded = 1; } handled = 1; }
            
            if (handled) {
                res = sys_malloc(2 * 8); ((long long*)(res))[0] = 0; ((long long*)(res))[1] = folded;
                return res;
            }
        }

        reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg);
        if (op == _eq_g_TOKEN_PLUS) { _eq_print_raw_str(((long long)" = add i64 ")); }
        if (op == _eq_g_TOKEN_MINUS) { _eq_print_raw_str(((long long)" = sub i64 ")); }
        if (op == _eq_g_TOKEN_ASTERISK) { _eq_print_raw_str(((long long)" = mul i64 ")); }
        if (op == _eq_g_TOKEN_SLASH) { _eq_print_raw_str(((long long)" = sdiv i64 ")); }
        if (op == _eq_g_TOKEN_PERCENT) { _eq_print_raw_str(((long long)" = srem i64 ")); }
        if (op == _eq_g_TOKEN_EQUAL_EQUAL) { _eq_print_raw_str(((long long)" = icmp eq i64 ")); }
        if (op == _eq_g_TOKEN_BANG_EQUAL) { _eq_print_raw_str(((long long)" = icmp ne i64 ")); }
        if (op == _eq_g_TOKEN_LESS) { _eq_print_raw_str(((long long)" = icmp slt i64 ")); }
        if (op == _eq_g_TOKEN_LESS_EQUAL) { _eq_print_raw_str(((long long)" = icmp sle i64 ")); }
        if (op == _eq_g_TOKEN_GREATER) { _eq_print_raw_str(((long long)" = icmp sgt i64 ")); }
        if (op == _eq_g_TOKEN_GREATER_EQUAL) { _eq_print_raw_str(((long long)" = icmp sge i64 ")); }
        if (op == _eq_g_TOKEN_OR) { _eq_print_raw_str(((long long)" = or i64 ")); }
        if (op == _eq_g_TOKEN_AND) { _eq_print_raw_str(((long long)" = and i64 ")); }
        if (op == _eq_g_TOKEN_BITOR) { _eq_print_raw_str(((long long)" = or i64 ")); }
        if (op == _eq_g_TOKEN_LSHIFT) { _eq_print_raw_str(((long long)" = shl i64 ")); }
        if (((long long*)(l_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(l_res))[1]); _eq_print_raw_str(((long long)", "));
        if (((long long*)(r_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(r_res))[1]); _eq_emit_ln(((long long)""));
        if (op >= _eq_g_TOKEN_EQUAL_EQUAL && op <= _eq_g_TOKEN_GREATER_EQUAL) {
             next_reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(next_reg); _eq_print_raw_str(((long long)" = zext i1 %r")); _eq_print_raw(reg); _eq_emit_ln(((long long)" to i64"));
            reg = next_reg;
        }
         res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg;
        return res;
    }
    if (type == _eq_g_EXPR_UNARY) {
         op = ((long long*)(expr))[1];  operand = _eq_gen_expr(c, ((long long*)(expr))[2]);  reg = _eq_freshen_reg(c);
        if (op == _eq_g_TOKEN_BANG) {
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp eq i64 "));
            if (((long long*)(operand))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(operand))[1]); _eq_emit_ln(((long long)", 0"));
             next_reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(next_reg); _eq_print_raw_str(((long long)" = zext i1 %r")); _eq_print_raw(reg); _eq_emit_ln(((long long)" to i64"));
            reg = next_reg;
        } else if (op == _eq_g_TOKEN_MINUS) {
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = sub i64 0, "));
            if (((long long*)(operand))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(operand))[1]); _eq_emit_ln(((long long)""));
        }
         res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg;
        return res;
    }
    if (type == _eq_g_EXPR_CALL) {
        callee = ((long long*)(expr))[1]; args = ((long long*)(expr))[2]; arg_count = _eq_vec_size(args);
        arg_results = _eq_vec_new(arg_count); i_args = 0;
        res = 0;
        while (i_args < arg_count) {
            res = _eq_gen_expr(c, _eq_vec_get(args, i_args));
            arg_results = _eq_vec_push(arg_results, res);
            i_args = i_args + 1;
        }
        reg = _eq_freshen_reg(c); callee_name = ((long long*)(callee))[1];
        if (_eq_str_equal(callee_name, ((long long)"get_argc"))) {
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_emit_ln(((long long)" = load i64, ptr @__equis_argc"));
            res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg; return res;
        }
        if (_eq_str_equal(callee_name, ((long long)"get_argv"))) {
            a_res = _eq_vec_get(arg_results, 0); obj = _eq_freshen_reg(c);
            ptr = _eq_freshen_reg(c); char_ptr = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(obj); _eq_emit_ln(((long long)" = load ptr, ptr @__equis_argv"));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)" = getelementptr ptr, ptr %r")); _eq_print_raw(obj); _eq_print_raw_str(((long long)", i64 "));
            if (((long long*)(a_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(a_res))[1]); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(char_ptr); _eq_print_raw_str(((long long)" = load ptr, ptr %r")); _eq_print_raw(ptr); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = ptrtoint ptr %r")); _eq_print_raw(char_ptr); _eq_emit_ln(((long long)" to i64"));
            res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg; return res;
        }
        
        is_magic = 0;
        if (_eq_g_Magic_Malloc == 0) {
            _eq_g_Magic_Malloc = _eq_intern_string(((long long)"malloc")); _eq_g_Magic_Free = _eq_intern_string(((long long)"free"));
            _eq_g_Magic_GetChar = _eq_intern_string(((long long)"get_char")); _eq_g_Magic_SetChar = _eq_intern_string(((long long)"set_char"));
            _eq_g_Magic_StrEqual = _eq_intern_string(((long long)"sys_str_equal"));
        }
        if (_eq_str_equal(callee_name, ((long long)"malloc"))) {
            a_res = _eq_vec_get(arg_results, 0);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = call i64 @malloc(i64 "));
            if (((long long*)(a_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(a_res))[1]); _eq_emit_ln(((long long)")"));
            is_magic = 1;
        } else if (_eq_str_equal(callee_name, ((long long)"free"))) {
            p_res = _eq_vec_get(arg_results, 0);
            _eq_print_raw_str(((long long)"    call i64 @free(i64 "));
            if (((long long*)(p_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(p_res))[1]); _eq_emit_ln(((long long)")"));
            is_magic = 1;
        } else if (_eq_str_equal(callee_name, ((long long)"get_char"))) {
            s_res = _eq_vec_get(arg_results, 0); i_res = _eq_vec_get(arg_results, 1);
            ptr = _eq_freshen_reg(c); char_ptr = _eq_freshen_reg(c); val_reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)" = inttoptr i64 "));
            if (((long long*)(s_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(s_res))[1]); _eq_emit_ln(((long long)" to ptr"));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(char_ptr); _eq_print_raw_str(((long long)" = getelementptr i8, ptr %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)", i64 "));
            if (((long long*)(i_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(i_res))[1]); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(val_reg); _eq_print_raw_str(((long long)" = load i8, ptr %r")); _eq_print_raw(char_ptr); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = zext i8 %r")); _eq_print_raw(val_reg); _eq_emit_ln(((long long)" to i64"));
            is_magic = 1;
        } else if (_eq_str_equal(callee_name, ((long long)"set_char"))) {
            s_res = _eq_vec_get(arg_results, 0); i_res = _eq_vec_get(arg_results, 1); v_res = _eq_vec_get(arg_results, 2);
            ptr = _eq_freshen_reg(c); char_ptr = _eq_freshen_reg(c); val_reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)" = inttoptr i64 "));
            if (((long long*)(s_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(s_res))[1]); _eq_emit_ln(((long long)" to ptr"));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(char_ptr); _eq_print_raw_str(((long long)" = getelementptr i8, ptr %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)", i64 "));
            if (((long long*)(i_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(i_res))[1]); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(val_reg); _eq_print_raw_str(((long long)" = trunc i64 "));
            if (((long long*)(v_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(v_res))[1]); _eq_emit_ln(((long long)" to i8"));
            _eq_print_raw_str(((long long)"    store i8 %r")); _eq_print_raw(val_reg); _eq_print_raw_str(((long long)", ptr %r")); _eq_print_raw(char_ptr); _eq_emit_ln(((long long)""));
            is_magic = 1;
        } else if (_eq_str_equal(callee_name, ((long long)"sys_str_equal"))) {
            s_res = _eq_vec_get(arg_results, 0); i_res = _eq_vec_get(arg_results, 1);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = call i64 @sys_str_equal(i64 "));
            if (((long long*)(s_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(s_res))[1]);
            _eq_print_raw_str(((long long)", i64 "));
            if (((long long*)(i_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(i_res))[1]);
            _eq_emit_ln(((long long)")"));
            is_magic = 1;
        }

        if (is_magic) { 
            
        } else {
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = call i64 @"));
            if (_eq_is_extern(c, callee_name) == 0) {
                if (_eq_str_equal(callee_name, ((long long)"sys_str_equal")) == 0) {
                    _eq_print_raw_str(((long long)"_eq_"));
                }
            }
            _eq_print_raw_str(callee_name); _eq_print_raw_str(((long long)"("));
            k = 0;
            while (k < arg_count) {
                a_res = _eq_vec_get(arg_results, k);
                _eq_print_raw_str(((long long)"i64 "));
                if (((long long*)(a_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(a_res))[1]);
                if (k < arg_count - 1) { _eq_print_raw_str(((long long)", ")); }
                k = k + 1;
            }
            _eq_emit_ln(((long long)")"));
        }
        res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = reg; return res;
    }
    if (type == _eq_g_EXPR_INDEX) {
        arr = _eq_gen_expr(c, ((long long*)(expr))[1]); idx = _eq_gen_expr(c, ((long long*)(expr))[2]); 
        
        check_reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(check_reg); _eq_print_raw_str(((long long)" = icmp eq i64 "));
        if (((long long*)(arr))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(arr))[1]); _eq_emit_ln(((long long)", 0"));
        l_ok = _eq_freshen_label(c);
        _eq_print_raw_str(((long long)"    br i1 %r")); _eq_print_raw(check_reg); _eq_print_raw_str(((long long)", label %Label_PanicNull, label %Label_")); _eq_print_raw(l_ok); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_ok); _eq_print_raw_str(((long long)":\n"));
        
        arr_ptr = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(arr_ptr); _eq_print_raw_str(((long long)" = inttoptr i64 "));
        if (((long long*)(arr))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(arr))[1]); _eq_emit_ln(((long long)" to ptr"));
        ptr = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)" = getelementptr i64, ptr %r")); _eq_print_raw(arr_ptr); _eq_print_raw_str(((long long)", i64 "));
        if (((long long*)(idx))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(idx))[1]); _eq_emit_ln(((long long)""));
        val = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(val); _eq_print_raw_str(((long long)" = load i64, ptr %r")); _eq_print_raw(ptr); _eq_emit_ln(((long long)""));
        res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = val; return res;
    }
    if (type == _eq_g_EXPR_GET) {
        obj = _eq_gen_expr(c, ((long long*)(expr))[1]); field_name = ((long long*)(expr))[2];
        
        check_reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(check_reg); _eq_print_raw_str(((long long)" = icmp eq i64 "));
        if (((long long*)(obj))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(obj))[1]); _eq_emit_ln(((long long)", 0"));
        l_ok = _eq_freshen_label(c);
        _eq_print_raw_str(((long long)"    br i1 %r")); _eq_print_raw(check_reg); _eq_print_raw_str(((long long)", label %Label_PanicNull, label %Label_")); _eq_print_raw(l_ok); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_ok); _eq_print_raw_str(((long long)":\n"));

        offset_entry = _eq_map_get(_eq_g_Global_Field_Map, field_name);
        if (offset_entry == 0) {
            (void)!write(2, (void*)((long long)"Codegen Error: Unknown field: "), 29);
            (void)!write(2, (void*)field_name, (size_t)sys_strlen(field_name));
            (void)!write(2, (void*)((long long)"\n"), 1);
            exit(1);
        }
        offset = ((long long*)(offset_entry))[0];
        obj_ptr = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(obj_ptr); _eq_print_raw_str(((long long)" = inttoptr i64 "));
        if (((long long*)(obj))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(obj))[1]); _eq_emit_ln(((long long)" to ptr"));
        field_ptr = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(field_ptr); _eq_print_raw_str(((long long)" = getelementptr i64, ptr %r")); _eq_print_raw(obj_ptr); _eq_print_raw_str(((long long)", i64 "));
        _eq_print_raw(offset); _eq_emit_ln(((long long)""));
        val_reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(val_reg); _eq_print_raw_str(((long long)" = load i64, ptr %r")); _eq_print_raw(field_ptr); _eq_emit_ln(((long long)""));
        res = sys_malloc(2 * 8); ((long long*)(res))[0] = 1; ((long long*)(res))[1] = val_reg; return res;
    }
    if (type == _eq_g_EXPR_ASSIGNMENT) {
        obj_assign_result = 0;
        target = ((long long*)(expr))[1]; value = _eq_gen_expr(c, ((long long*)(expr))[2]);
        if (((long long*)(target))[0] == _eq_g_EXPR_VARIABLE) {
            name = ((long long*)(target))[1]; found_local = 0;
            if (((long long*)(c))[4]) {
                locals = ((long long*)(c))[4]; v_idx = _eq_vec_size(locals) - 1;
                while (v_idx >= 0) {
                    entry = _eq_vec_get(locals, v_idx);
                    if (((long long*)(entry))[0] == name) {
                        old_reg = _eq_freshen_reg(c);
                        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(old_reg); _eq_print_raw_str(((long long)" = load i64, ptr %p")); _eq_print_raw(((long long*)(entry))[1]); _eq_emit_ln(((long long)""));
                        _eq_print_raw_str(((long long)"    store i64 "));
                        if (((long long*)(value))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(value))[1]);
                        _eq_print_raw_str(((long long)", ptr %p")); _eq_print_raw(((long long*)(entry))[1]); _eq_emit_ln(((long long)""));
                        found_local = 1; v_idx = -1;
                    } else { v_idx = v_idx - 1; }
                }
            }
            if (found_local == 0) {
                old_reg = _eq_freshen_reg(c);
                _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(old_reg); _eq_print_raw_str(((long long)" = load i64, ptr @Global_")); _eq_print_raw_str(name); _eq_emit_ln(((long long)""));
                
                
                _eq_print_raw_str(((long long)"    store i64 "));
                if (((long long*)(value))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(value))[1]);
                _eq_print_raw_str(((long long)", ptr @Global_")); _eq_print_raw_str(name); _eq_emit_ln(((long long)""));
            }
        } else if (((long long*)(target))[0] == _eq_g_EXPR_INDEX) {
            arr = _eq_gen_expr(c, ((long long*)(target))[1]); idx = _eq_gen_expr(c, ((long long*)(target))[2]); arr_ptr = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(arr_ptr); _eq_print_raw_str(((long long)" = inttoptr i64 "));
            if (((long long*)(arr))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(arr))[1]); _eq_emit_ln(((long long)" to ptr"));
            ptr = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(ptr); _eq_print_raw_str(((long long)" = getelementptr i64, ptr %r")); _eq_print_raw(arr_ptr); _eq_print_raw_str(((long long)", i64 "));
            if (((long long*)(idx))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(idx))[1]); _eq_emit_ln(((long long)""));
            old_reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(old_reg); _eq_print_raw_str(((long long)" = load i64, ptr %r")); _eq_print_raw(ptr); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    store i64 "));
            if (((long long*)(value))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(value))[1]);
            _eq_print_raw_str(((long long)", ptr %r")); _eq_print_raw(ptr); _eq_emit_ln(((long long)""));
        } else if (((long long*)(target))[0] == _eq_g_EXPR_GET) {
            obj_assign_result = _eq_gen_expr(c, ((long long*)(target))[1]);
            field_name = ((long long*)(target))[2];
            offset_entry = _eq_map_get(_eq_g_Global_Field_Map, field_name);
            if (offset_entry == 0) {
                (void)!write(2, (void*)((long long)"Codegen Error: Unknown field in assignment: "), 44);
                (void)!write(2, (void*)field_name, (size_t)sys_strlen(field_name));
                (void)!write(2, (void*)((long long)"\n"), 1);
                exit(1);
            }
            offset = ((long long*)(offset_entry))[0];
            obj_ptr = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(obj_ptr); _eq_print_raw_str(((long long)" = inttoptr i64 "));
            if (((long long*)(obj_assign_result))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(obj_assign_result))[1]); _eq_emit_ln(((long long)" to ptr"));
            field_ptr = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(field_ptr); _eq_print_raw_str(((long long)" = getelementptr i64, ptr %r")); _eq_print_raw(obj_ptr); _eq_print_raw_str(((long long)", i64 "));
            _eq_print_raw(offset); _eq_emit_ln(((long long)""));
            old_reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(old_reg); _eq_print_raw_str(((long long)" = load i64, ptr %r")); _eq_print_raw(field_ptr); _eq_emit_ln(((long long)""));
            _eq_print_raw_str(((long long)"    store i64 "));
            if (((long long*)(value))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(value))[1]);
            _eq_print_raw_str(((long long)", ptr %r")); _eq_print_raw(field_ptr); _eq_emit_ln(((long long)""));
        }
        return value;
    }
    return 0;
}
long long _eq_gen_stmt(long long c, long long stmt) {
    if (c < 4096 || stmt < 4096) return 0;
    volatile long long a_res = 0;
    volatile long long a_size = 0;
    volatile long long arg_val = 0;
    volatile long long args = 0;
    volatile long long c_label = 0;
    volatile long long c_roles = 0;
    volatile long long c_r_str = 0;
    volatile long long arr = 0;
    volatile long long arr_ptr = 0;
    volatile long long body = 0;
    volatile long long c_flows = 0;
    volatile long long c_logic = 0;
    volatile long long check_reg = 0;
    volatile long long cond = 0;
    volatile long long cond_reg = 0;
    volatile long long entry = 0;
    volatile long long existing = 0;
    volatile long long f = 0;
    volatile long long f_name = 0;
    volatile long long field_name = 0;
    volatile long long field_ptr = 0;
    volatile long long fields = 0;
    volatile long long i = 0;
    volatile long long i_arg = 0;
    volatile long long icmp_res = 0;
    volatile long long idx = 0;
    volatile long long j = 0;
    volatile long long k = 0;
    volatile long long k_size = 0;
    volatile long long l_body = 0;
    volatile long long l_cond = 0;
    volatile long long l_cont = 0;
    volatile long long l_else = 0;
    volatile long long l_end = 0;
    volatile long long l_ok = 0;
    volatile long long l_ptr = 0;
    volatile long long l_ret = 0;
    volatile long long l_start = 0;
    volatile long long l_then = 0;
    volatile long long name = 0;
    volatile long long obj_assign_result = 0;
    volatile long long obj_ptr = 0;
    volatile long long offset = 0;
    volatile long long offset_entry = 0;
    volatile long long old_reg = 0;
    volatile long long p_name = 0;
    volatile long long ptr = 0;
    volatile long long reg = 0;
    volatile long long res = 0;
    volatile long long ret_val = 0;
    volatile long long sig_ptr = 0;
    volatile long long sig_res = 0;
    volatile long long size = 0;
    volatile long long target = 0;
    volatile long long type = 0;
    volatile long long v_entry = 0;
    volatile long long v_sz = 0;
    volatile long long val = 0;
    volatile long long val_reg = 0;
    volatile long long value = 0;
    volatile long long vars = 0;

    if (stmt < 4096) { return 0; }
     type = ((long long*)(stmt))[0];
     name = 0;  value = 0;  l_ptr = 0;  existing = 0;
     vars = 0;  j = 0;  v_sz = 0;  v_entry = 0;
     val_reg = 0;  body = 0;  i = 0;  size = 0;
     cond = 0;  l_then = 0;  l_else = 0;  l_cont = 0;
     cond_reg = 0;  l_start = 0;  l_body = 0;  l_ret = 0;
     ret_val = 0;  entry = 0;  a_res = 0;  f = 0;
     res = 0;  args = 0;  arg_val = 0;  c_flows = 0;
     c_logic = 0;  f_name = 0;  i_arg = 0;  p_name = 0;
     sig_res = 0;  sig_ptr = 0;  reg = 0;  fields = 0;
     icmp_res = 0;  a_size = 0;  k_size = 0;  v_sz = 0;
     target = 0;  value = 0;  old_reg = 0;  obj_assign_result = 0;
     field_name = 0;  offset_entry = 0;  offset = 0;  obj_ptr = 0;
     field_ptr = 0;  arr = 0;  idx = 0;  arr_ptr = 0;  ptr = 0;
     check_reg = 0;  l_ok = 0;  l_cond = 0;  l_end = 0;
     val = 0;  existing = 0;  vars = 0;  j = 0;  v_entry = 0;
     k = 0;  c_roles = 0;  c_r_str = 0;  c_label = 0; 

    if (type == _eq_g_STMT_EXPRESSION) { _eq_gen_expr(c, ((long long*)(stmt))[1]); }
    else if (type == _eq_g_STMT_LET) {
        name = ((long long*)(stmt))[1];
        value = ((long long*)(stmt))[2];
        l_ptr = 0;
        
        
        existing = 0;
        vars = ((long long*)(c))[4];
        if (vars) {
            j = 0; v_sz = _eq_vec_size(vars);
            while (j < v_sz) {
                v_entry = _eq_vec_get(vars, j);
                if (_eq_str_equal(((long long*)(v_entry))[0], name)) { existing = v_entry; j = v_sz; }
                j = j + 1;
            }
        }

        if (existing) {
            l_ptr = ((long long*)(existing))[1];
        } else if (((long long*)(c))[4]) { 
            l_ptr = _eq_freshen_ptr(c);
            _eq_print_raw_str(((long long)"    %p")); _eq_print_raw(l_ptr); _eq_emit_ln(((long long)" = alloca i64"));
            _eq_print_raw_str(((long long)"    store i64 0, ptr %p")); _eq_print_raw(l_ptr); _eq_emit_ln(((long long)""));
            entry = sys_malloc(2 * 8); ((long long*)(entry))[0] = name; ((long long*)(entry))[1] = l_ptr;
            ((long long*)(c))[4] = _eq_vec_push(((long long*)(c))[4], entry);
        }

        val_reg = _eq_gen_expr(c, value);
        
        if (((long long*)(c))[4]) { 
            
            
            
            
            
            _eq_print_raw_str(((long long)"    store i64 ")); if (((long long*)(val_reg))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(val_reg))[1]); _eq_print_raw_str(((long long)", ptr %p")); _eq_print_raw(l_ptr); _eq_emit_ln(((long long)""));
        } else { 
            _eq_print_raw_str(((long long)"    store i64 "));
            if (((long long*)(val_reg))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(val_reg))[1]);
            _eq_print_raw_str(((long long)", ptr @Global_")); _eq_print_raw_str(name); _eq_emit_ln(((long long)""));
        }
        return 0;
    } else if (type == _eq_g_STMT_BLOCK) {
        body = ((long long*)(stmt))[1];
        i = 0; size = _eq_vec_size(body);
        while (i < size) { 
            _eq_gen_stmt(c, _eq_vec_get(body, i)); 
            i = i + 1; 
        }
    } else if (type == _eq_g_STMT_IF) {
        cond = _eq_gen_expr(c, ((long long*)(stmt))[1]); l_then = _eq_freshen_label(c); l_else = _eq_freshen_label(c); l_cont = _eq_freshen_label(c);
        cond_reg = ((long long*)(cond))[1];
        if (((long long*)(cond))[0] == 0) {
            reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp ne i64 ")); _eq_print_raw(((long long*)(cond))[1]); _eq_emit_ln(((long long)", 0"));
            cond_reg = reg;
        } else {
            reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp ne i64 %r")); _eq_print_raw(((long long*)(cond))[1]); _eq_emit_ln(((long long)", 0"));
            cond_reg = reg;
        }
        _eq_print_raw_str(((long long)"    br i1 %r")); _eq_print_raw(cond_reg); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_then); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_else); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_then); _eq_print_raw_str(((long long)":\n"));
        _eq_gen_stmt(c, ((long long*)(stmt))[2]);
        _eq_print_raw_str(((long long)"    br label %Label_")); _eq_print_raw(l_cont); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_else); _eq_print_raw_str(((long long)":\n"));
        if (((long long*)(stmt))[3]) { _eq_gen_stmt(c, ((long long*)(stmt))[3]); }
        _eq_print_raw_str(((long long)"    br label %Label_")); _eq_print_raw(l_cont); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_cont); _eq_print_raw_str(((long long)":\n"));
    } else if (type == _eq_g_STMT_WHILE) {
        l_start = _eq_freshen_label(c); l_body = _eq_freshen_label(c); l_cont = _eq_freshen_label(c);
        _eq_print_raw_str(((long long)"    br label %Label_")); _eq_print_raw(l_start); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_start); _eq_print_raw_str(((long long)":\n"));
        cond = _eq_gen_expr(c, ((long long*)(stmt))[1]);
        cond_reg = ((long long*)(cond))[1];
        if (((long long*)(cond))[0] == 0) {
            reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp ne i64 ")); _eq_print_raw(((long long*)(cond))[1]); _eq_emit_ln(((long long)", 0"));
            cond_reg = reg;
        } else {
            reg = _eq_freshen_reg(c);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp ne i64 %r")); _eq_print_raw(((long long*)(cond))[1]); _eq_emit_ln(((long long)", 0"));
            cond_reg = reg;
        }
        _eq_print_raw_str(((long long)"    br i1 %r")); _eq_print_raw(cond_reg); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_body); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_cont); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_body); _eq_print_raw_str(((long long)":\n"));
        _eq_gen_stmt(c, ((long long*)(stmt))[2]);
        _eq_print_raw_str(((long long)"    br label %Label_")); _eq_print_raw(l_start); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_cont); _eq_print_raw_str(((long long)":\n"));
    } else if (type == _eq_g_STMT_RETURN) {
        if (((long long*)(stmt))[1]) {
            res = _eq_gen_expr(c, ((long long*)(stmt))[1]);
            _eq_gen_release_locals(c, ((long long*)(c))[4]);
            _eq_print_raw_str(((long long)"    ret i64 ")); if (((long long*)(res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(res))[1]); _eq_emit_ln(((long long)""));
        } else { 
            _eq_gen_release_locals(c, ((long long*)(c))[4]);
            _eq_emit_ln(((long long)"    ret i64 0")); 
        }
    } else if (type == _eq_g_STMT_PRINT) {
        res = _eq_gen_expr(c, ((long long*)(stmt))[1]);
        _eq_print_raw_str(((long long)"    call i64 (ptr, ...) @printf(ptr @fmt_print, i64 "));
        if (((long long*)(res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(res))[1]); _eq_emit_ln(((long long)")"));
    } else if (type == _eq_g_STMT_STRUCT || type == _eq_g_STMT_AGENT || type == _eq_g_STMT_RESOURCE) {
        fields = ((long long*)(stmt))[2]; j = 0; v_sz = _eq_vec_size(fields);
        if (type == _eq_g_STMT_AGENT) { fields = ((long long*)(stmt))[_eq_g_AGENT_FIELDS]; v_sz = _eq_vec_size(fields); }
        f_name = 0; entry = 0;
        while (j < v_sz) {
            f_name = _eq_vec_get(fields, j);
            entry = sys_malloc(16); ((long long*)(entry))[0] = j;
            _eq_map_put(_eq_g_Global_Field_Map, f_name, entry);
            j = j + 1;
        }
    } else if (type == _eq_g_STMT_EVENT || type == _eq_g_STMT_COMMITMENT || type == _eq_g_STMT_POLICY || type == _eq_g_STMT_TRANSFORMATION || type == _eq_g_STMT_VALUATOR) {
        name = ((long long*)(stmt))[_eq_g_EVENT_NAME];
        p_name = ((long long)"event_");
        if (type == _eq_g_STMT_COMMITMENT) { p_name = ((long long)"commitment_"); name = ((long long*)(stmt))[_eq_g_COMMITMENT_NAME]; }
        if (type == _eq_g_STMT_POLICY) { p_name = ((long long)"policy_"); }
        if (type == _eq_g_STMT_TRANSFORMATION) { p_name = ((long long)"transformation_"); name = ((long long*)(stmt))[_eq_g_TRANSFORMATION_NAME]; }
        if (type == _eq_g_STMT_VALUATOR) { p_name = ((long long)"valuator_"); name = ((long long*)(stmt))[_eq_g_VALUATOR_NAME]; }
        
        _eq_print_raw_str(((long long)"define void @")); _eq_print_raw_str(p_name); _eq_print_raw_str(name); _eq_print_raw_str(((long long)"(ptr %args) {\nentry:\n"));
        _eq_print_raw_str(((long long)"    ; REA-TEMPORAL: Increment Technical Clock\n"));
        _eq_print_raw_str(((long long)"    %clock_old = load i64, ptr @__technical_clock\n"));
        _eq_print_raw_str(((long long)"    %clock_new = add i64 %clock_old, 1\n"));
        _eq_print_raw_str(((long long)"    store i64 %clock_new, ptr @__technical_clock\n"));
        
        _eq_print_raw_str(((long long)"    ; REA-GOVERNANCE: Mandatory Role-Based Access Control (RBAC)\n"));
        c_roles = ((long long*)(stmt))[_eq_g_EVENT_ROLES];
        if (type == _eq_g_STMT_COMMITMENT) { c_roles = ((long long*)(stmt))[_eq_g_COMMITMENT_ROLES]; }
        if (type == _eq_g_STMT_TRANSFORMATION) { c_roles = ((long long*)(stmt))[_eq_g_TRANSFORMATION_ROLES]; }
        if (c_roles && _eq_vec_size(c_roles) > 0) {
            c_r_str = _eq_vec_get(c_roles, 0);
            c_label = _eq_gen_string_label(c, c_r_str);
            _eq_print_raw_str(((long long)"    call i64 @sys_verify_role(ptr @str.")); _eq_print_raw(c_label); _eq_emit_ln(((long long)")"));
        } else {
            _eq_print_raw_str(((long long)"    call i64 @sys_verify_role(ptr null)\n"));
        }
        
        c_logic = ((long long*)(stmt))[_eq_g_EVENT_LOGIC];
        if (type == _eq_g_STMT_COMMITMENT) { c_logic = ((long long*)(stmt))[_eq_g_COMMITMENT_LOGIC]; }
        if (type == _eq_g_STMT_TRANSFORMATION) { c_logic = ((long long*)(stmt))[_eq_g_TRANSFORMATION_LOGIC]; }
        if (type == _eq_g_STMT_VALUATOR) { c_logic = ((long long*)(stmt))[_eq_g_VALUATOR_BODY]; }
        if (c_logic) {
            _eq_print_raw_str(((long long)"    ; REA-TX: Starting Business Logic Block\n"));
            _eq_gen_stmt(c, c_logic);
            _eq_print_raw_str(((long long)"    ; REA-TX: Business Logic Block Completed Successfully\n"));
        }

        if (type == _eq_g_STMT_POLICY || type == _eq_g_STMT_VALUATOR) {
            
        } else {
            c_flows = ((long long*)(stmt))[_eq_g_EVENT_FLOWS];
            if (type == _eq_g_STMT_COMMITMENT) { c_flows = ((long long*)(stmt))[_eq_g_COMMITMENT_FLOWS]; }
            if (type == _eq_g_STMT_TRANSFORMATION) { c_flows = ((long long*)(stmt))[_eq_g_TRANSFORMATION_FLOWS]; }
            k = 0; k_size = _eq_vec_size(c_flows);
            f = 0; res = 0; name = 0; val = 0; a_res = 0;
            while (k < k_size) {
                f = _eq_vec_get(c_flows, k);
                res = _eq_gen_string_label(c, ((long long*)(f))[_eq_g_FLOW_RES]);
                name = _eq_gen_string_label(c, ((long long*)(f))[_eq_g_FLOW_FROM]);
                val = _eq_gen_string_label(c, ((long long*)(f))[_eq_g_FLOW_TO]);
                a_res = _eq_gen_expr(c, ((long long*)(f))[_eq_g_FLOW_AMOUNT]);
                _eq_print_raw_str(((long long)"    ; REA-FLOW Auditing: ")); _eq_print_raw_str(((long long*)(f))[_eq_g_FLOW_RES]); _eq_print_raw_str(((long long)"\n"));
                _eq_print_raw_str(((long long)"    call void @sys_audit_flow(i64 ")); _eq_print_raw(((long long*)(f))[_eq_g_FLOW_TYPE]); 
                _eq_print_raw_str(((long long)", i64 "));
                if (((long long*)(a_res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(a_res))[1]);
                _eq_print_raw_str(((long long)", ptr @str.")); _eq_print_raw(res);
                _eq_print_raw_str(((long long)", ptr @str.")); _eq_print_raw(name);
                _eq_print_raw_str(((long long)", ptr @str.")); _eq_print_raw(val);
                _eq_emit_ln(((long long)")"));
                k = k + 1;
            }
        }
        _eq_print_raw_str(((long long)"    ; REA-DUALITY: Runtime Balance Trap\n"));
        _eq_print_raw_str(((long long)"    call void @sys_verify_duality()\n"));
        _eq_print_raw_str(((long long)"    ret void\n}\n\n"));
    } else if (type == _eq_g_STMT_EXCHANGE) {
        name = ((long long*)(stmt))[1];
        _eq_print_raw_str(((long long)"; REA-EXCHANGE Reciprocity: ")); _eq_print_raw_str(name); _eq_print_raw_str(((long long)"\n"));
    } else if (type == _eq_g_STMT_REVERSE) {
        name = ((long long*)(stmt))[1];
        _eq_print_raw_str(((long long)"    call void @sys_reverse_event(ptr null)\n"));
    } else if (type == _eq_g_STMT_EXECUTE) {
        args = ((long long*)(stmt))[2]; i_arg = 0; a_size = _eq_vec_size(args);
        sig_res = 0;
        name = _eq_intern_string(((long long)"sig"));
        arg_val = 0;
        while (i_arg < a_size) {
            arg_val = _eq_vec_get(args, i_arg);
            if (_eq_intern_string(arg_val) == name) { sig_res = _eq_vec_get(args, i_arg + 1); }
            i_arg = i_arg + 2;
        }
        _eq_print_raw_str(((long long)"    ; REA-IDENTITY: Verify Ed25519 signature before execution\n"));
        sig_ptr = _eq_freshen_reg(c);
        if (sig_res) {
            res = _eq_gen_string_label(c, sig_res);
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(sig_ptr); _eq_print_raw_str(((long long)" = getelementptr i8, ptr @str.")); _eq_print_raw(res); _eq_emit_ln(((long long)", i64 0"));
        } else {
            _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(sig_ptr); _eq_emit_ln(((long long)" = inttoptr i64 0 to ptr"));
        }
        _eq_print_raw_str(((long long)"    call i64 @sys_verify_sig(ptr null, ptr %r")); _eq_print_raw(sig_ptr); _eq_emit_ln(((long long)")")); 
        _eq_print_raw_str(((long long)"    call void @event_")); _eq_print_raw_str(((long long*)(stmt))[1]); _eq_print_raw_str(((long long)"(ptr null)\n"));
    } else if (type == _eq_g_STMT_ASSERT) {
        res = _eq_gen_expr(c, ((long long*)(stmt))[1]);
        l_then = _eq_freshen_label(c); l_cont = _eq_freshen_label(c);
        reg = _eq_freshen_reg(c);
        _eq_print_raw_str(((long long)"    %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)" = icmp eq i64 "));
        if (((long long*)(res))[0]) { _eq_print_raw_str(((long long)"%r")); } _eq_print_raw(((long long*)(res))[1]); _eq_emit_ln(((long long)", 0"));
        _eq_print_raw_str(((long long)"    br i1 %r")); _eq_print_raw(reg); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_then); _eq_print_raw_str(((long long)", label %Label_")); _eq_print_raw(l_cont); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_then); _eq_print_raw_str(((long long)":\n"));
        _eq_print_raw_str(((long long)"    call i64 @write(i64 2, ptr @str_assert_fail, i64 18)\n"));
        _eq_emit_ln(((long long)"    call void @exit(i64 1)"));
        _eq_print_raw_str(((long long)"    br label %Label_")); _eq_print_raw(l_cont); _eq_emit_ln(((long long)""));
        _eq_print_raw_str(((long long)"Label_")); _eq_print_raw(l_cont); _eq_print_raw_str(((long long)":\n"));
    }
    return 0;
}
long long _eq_codegen_new(long long trace_enabled, long long incremental) {
    volatile long long c = 0;

     c = sys_malloc(10 * 8);
    ((long long*)(c))[0] = 1; ((long long*)(c))[1] = 1; ((long long*)(c))[2] = _eq_vec_new(200000); ((long long*)(c))[3] = _eq_vec_new(200000); ((long long*)(c))[4] = 0;
    ((long long*)(c))[5] = _eq_vec_new(200000); 
    ((long long*)(c))[6] = incremental;
    if (_eq_g_Global_Field_Map == 0) { _eq_g_Global_Field_Map = _eq_map_new(2000); }
    
    _eq_gen_string_label(c, ((long long)"0"));
    _eq_gen_string_label(c, ((long long)"1"));
    _eq_gen_string_label(c, ((long long)""));
    
    return c;
}
long long _eq_gen_program(long long c, long long ast) {
    volatile long long body = 0;
    volatile long long g_stmt = 0;
    volatile long long i = 0;
    volatile long long i_str = 0;
    volatile long long j = 0;
    volatile long long k = 0;
    volatile long long k_entry = 0;
    volatile long long k_size = 0;
    volatile long long l_ptr = 0;
    volatile long long name = 0;
    volatile long long p_name = 0;
    volatile long long p_size = 0;
    volatile long long params = 0;
    volatile long long s_size = 0;
    volatile long long s_type = 0;
    volatile long long s_val = 0;
    volatile long long size = 0;
    volatile long long stmt = 0;
    volatile long long strings = 0;

     size = 0;  i = 0;  stmt = 0;  name = 0;  params = 0;  p_size = 0;
     j = 0;  k = 0;  k_size = 0;  p_name = 0;  l_ptr = 0;  k_entry = 0;
     body = 0;  g_stmt = 0;  s_type = 0;  strings = 0;  s_size = 0;
     i_str = 0;  s_val = 0;

    _eq_print_raw_str(((long long)"target triple = \"x86_64-pc-linux-gnu\"\n"));
    _eq_emit_ln(((long long)"@fmt_print = private unnamed_addr constant [6 x i8] c\"%lld\\0A\\00\""));
    _eq_emit_ln(((long long)"@fmt_s = private unnamed_addr constant [3 x i8] c\"%s\\00\""));
    _eq_emit_ln(((long long)"@fmt_d = private unnamed_addr constant [5 x i8] c\"%lld\\00\""));
    _eq_print_raw_str(((long long)"@__equis_argc = external global i64\n"));
    _eq_print_raw_str(((long long)"@__equis_argv = external global ptr\n"));
    _eq_emit_ln(((long long)"@__technical_clock = global i64 0"));
    _eq_emit_ln(((long long)"@str_assert_fail = private unnamed_addr constant [19 x i8] c\"ASSERTION FAILED!\\0A\\00\""));
    
    if (_eq_pre_intern_emitted == 0) {
        _eq_pre_intern_emitted = 1;
    }
    
    size = _eq_vec_size(ast); i = 0;
    while (i < size) {
        stmt = _eq_vec_get(ast, i);
        if (((long long*)(stmt))[0] == _eq_g_STMT_EXTERN) {
            name = ((long long*)(stmt))[1]; params = ((long long*)(stmt))[2]; p_size = _eq_vec_size(params);
            ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], name);
            _eq_print_raw_str(((long long)"declare i64 @")); _eq_print_raw_str(name); _eq_print_raw_str(((long long)"("));
            j = 0; while (j < p_size) { _eq_print_raw_str(((long long)"i64")); if (j < p_size - 1) { _eq_print_raw_str(((long long)", ")); } j = j + 1; }
            _eq_print_raw_str(((long long)")\n"));
        }
        if (((long long*)(stmt))[0] == _eq_g_STMT_FUNCTION) {
            ((long long*)(c))[5] = _eq_vec_push(((long long*)(c))[5], ((long long*)(stmt))[1]);
        }
        if (((long long*)(stmt))[0] == _eq_g_STMT_LET) {
            _eq_print_raw_str(((long long)"@Global_")); _eq_print_raw_str(((long long*)(stmt))[1]); _eq_emit_ln(((long long)" = global i64 0"));
        }
        if (((long long*)(stmt))[0] == _eq_g_STMT_STRUCT || ((long long*)(stmt))[0] == _eq_g_STMT_AGENT || ((long long*)(stmt))[0] == _eq_g_STMT_RESOURCE) {
            _eq_gen_stmt(c, stmt);
        }
        i = i + 1;
    }
    
    if (_eq_is_extern(c, ((long long)"write")) == 0) { _eq_print_raw_str(((long long)"declare i64 @write(i64, i64, i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"write")); }
    if (_eq_is_extern(c, ((long long)"exit")) == 0) { _eq_print_raw_str(((long long)"declare void @exit(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"exit")); }
    if (_eq_is_extern(c, ((long long)"malloc")) == 0) { _eq_print_raw_str(((long long)"declare i64 @malloc(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"malloc")); }
    if (_eq_is_extern(c, ((long long)"free")) == 0) { _eq_print_raw_str(((long long)"declare void @free(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"free")); }
    if (_eq_is_extern(c, ((long long)"printf")) == 0) { _eq_print_raw_str(((long long)"declare i64 @printf(i64, ...)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"printf")); }
    if (_eq_is_extern(c, ((long long)"sys_audit_flow")) == 0) { _eq_print_raw_str(((long long)"declare void @sys_audit_flow(i64, i64, ptr, ptr, ptr)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_audit_flow")); }
    if (_eq_is_extern(c, ((long long)"sys_verify_duality")) == 0) { _eq_print_raw_str(((long long)"declare void @sys_verify_duality()\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_verify_duality")); }
    if (_eq_is_extern(c, ((long long)"sys_verify_role")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_verify_role(ptr)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_verify_role")); }
    if (_eq_is_extern(c, ((long long)"sys_verify_sig")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_verify_sig(ptr, ptr)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_verify_sig")); }
    if (_eq_is_extern(c, ((long long)"_eq_setup_rea")) == 0) { _eq_print_raw_str(((long long)"declare i64 @_eq_setup_rea()\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"_eq_setup_rea")); }
    if (_eq_is_extern(c, ((long long)"_eq_reverse_event")) == 0) { _eq_print_raw_str(((long long)"declare void @_eq_reverse_event(ptr)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"_eq_reverse_event")); }
    if (_eq_is_extern(c, ((long long)"sys_reverse_event")) == 0) { _eq_print_raw_str(((long long)"declare void @sys_reverse_event(ptr)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_reverse_event")); }
    if (_eq_is_extern(c, ((long long)"sys_panic_null")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_panic_null()\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_panic_null")); }
    if (_eq_is_extern(c, ((long long)"sys_pin")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_pin(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_pin")); }

    if (_eq_is_extern(c, ((long long)"sys_strlen")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_strlen(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_strlen")); }
    if (_eq_is_extern(c, ((long long)"sys_str_equal")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_str_equal(i64, i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_str_equal")); }
    if (_eq_is_extern(c, ((long long)"read")) == 0) { _eq_print_raw_str(((long long)"declare i64 @read(i64, i64, i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"read")); }
    if (_eq_is_extern(c, ((long long)"open")) == 0) { _eq_print_raw_str(((long long)"declare i64 @open(i64, i64, i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"open")); }
    if (_eq_is_extern(c, ((long long)"close")) == 0) { _eq_print_raw_str(((long long)"declare i64 @close(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"close")); }
    if (_eq_is_extern(c, ((long long)"lseek")) == 0) { _eq_print_raw_str(((long long)"declare i64 @lseek(i64, i64, i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"lseek")); }

    if (_eq_is_extern(c, ((long long)"sys_write_raw")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_write_raw(i64, i64, i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_write_raw")); }

    if (_eq_is_extern(c, ((long long)"sys_read_entire_file")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_read_entire_file(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_read_entire_file")); }
    if (_eq_is_extern(c, ((long long)"sys_get_argc")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_get_argc()\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_get_argc")); }
    if (_eq_is_extern(c, ((long long)"sys_get_argv")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_get_argv(i64)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_get_argv")); }
    if (_eq_is_extern(c, ((long long)"sys_time")) == 0) { _eq_print_raw_str(((long long)"declare i64 @sys_time()\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_time")); }
    if (_eq_is_extern(c, ((long long)"sys_reverse_event")) == 0) { _eq_print_raw_str(((long long)"declare void @sys_reverse_event(ptr)\n")); ((long long*)(c))[3] = _eq_vec_push(((long long*)(c))[3], ((long long)"sys_reverse_event")); }


    
    i = 0;
    while (i < size) {
        stmt = _eq_vec_get(ast, i);
        if (((long long*)(stmt))[0] == _eq_g_STMT_FUNCTION) {
            name = ((long long*)(stmt))[1]; params = ((long long*)(stmt))[2]; body = ((long long*)(stmt))[3]; p_size = _eq_vec_size(params);
            _eq_print_raw_str(((long long)"define i64 @_eq_")); _eq_print_raw_str(name); _eq_print_raw_str(((long long)"("));
            j = 0;
            while (j < p_size) {
                _eq_print_raw_str(((long long)"i64 %Arg_")); _eq_print_raw_str(_eq_vec_get(params, j));
                if (j < p_size - 1) { _eq_print_raw_str(((long long)", ")); } j = j + 1;
            }
            _eq_print_raw_str(((long long)") {\nentry:\n"));
            ((long long*)(c))[0] = 1; ((long long*)(c))[4] = _eq_vec_new(200000);
            k = 0;
            p_name = 0; l_ptr = 0; k_entry = 0;
            while (k < p_size) {
                p_name = _eq_vec_get(params, k); l_ptr = _eq_freshen_ptr(c);
                _eq_print_raw_str(((long long)"    %p")); _eq_print_raw(l_ptr); _eq_emit_ln(((long long)" = alloca i64"));
                _eq_print_raw_str(((long long)"    store i64 %Arg_")); _eq_print_raw_str(p_name); _eq_print_raw_str(((long long)", ptr %p")); _eq_print_raw(l_ptr); _eq_emit_ln(((long long)""));
                k_entry = sys_malloc(2 * 8); ((long long*)(k_entry))[0] = p_name; ((long long*)(k_entry))[1] = l_ptr;
                ((long long*)(c))[4] = _eq_vec_push(((long long*)(c))[4], k_entry);
                k = k + 1;
            }
            _eq_gen_stmt(c, body);
            _eq_gen_release_locals(c, ((long long*)(c))[4]);
            _eq_print_raw_str(((long long)"    ret i64 0\nLabel_PanicNull:\n    call i64 @sys_panic_null()\n    unreachable\n}\n\n"));
        }
        if (((long long*)(stmt))[0] == _eq_g_STMT_EVENT) {
            _eq_gen_stmt(c, stmt);
        }
        i = i + 1;
    }
    
    if (((long long*)(c))[6] == 1) {
    if (_eq_is_defined(c, ((long long)"__equis_pre_intern")) == 0) { _eq_print_raw_str(((long long)"define i64 @_eq___equis_pre_intern() {\nentry:\n    ret i64 0\n}\n\n")); }
        _eq_print_raw_str(((long long)"define void @_eq___equis_init_globals() {\nentry:\n"));
        _eq_print_raw_str(((long long)"    call i64 @_eq___equis_pre_intern()\n"));
        ((long long*)(c))[0] = 1; ((long long*)(c))[4] = 0;
        i = 0;
        g_stmt = 0; s_type = 0;
        while (i < size) {
            g_stmt = _eq_vec_get(ast, i);
            s_type = ((long long*)(g_stmt))[0];
            if (s_type == 102 || s_type == 101 || s_type == 123 || s_type == 124 || s_type == 107 || s_type == 129 || s_type == 111 || s_type == 120 || s_type == 121) { _eq_gen_stmt(c, g_stmt); }
            i = i + 1;
        }
        _eq_print_raw_str(((long long)"    ret void\nLabel_PanicNull:\n    call i64 @sys_panic_null()\n    unreachable\n}\n\n"));
        
        if (_eq_is_defined(c, ((long long)"main_routine")) == 0) {
            _eq_print_raw_str(((long long)"define i64 @_eq_main_routine() {\nentry:\n    ret i64 0\n}\n\n"));
        }
        _eq_print_raw_str(((long long)"define void @_eq___equis_cleanup_globals() {\nentry:\n    ret void\n}\n\n"));
    }
    
    strings = ((long long*)(c))[2]; s_size = _eq_vec_size(strings); i_str = 0;
    while (i_str < s_size) {
        s_val = _eq_vec_get(strings, i_str);
        _eq_print_raw_str(((long long)"@str.")); _eq_print_raw(i_str); _eq_print_raw_str(((long long)" = private unnamed_addr constant ["));
        _eq_print_raw(sys_strlen(s_val) + 1); _eq_print_raw_str(((long long)" x i8] c\""));
        _eq_print_escaped_str(s_val); _eq_print_raw_str(((long long)"\\00\"\n")); i_str = i_str + 1;
    }
}
long long _eq_optimize_program(long long ast) {
    volatile long long i = 0;
    volatile long long new_ast = 0;
    volatile long long opt_stmt = 0;
    volatile long long size = 0;
    volatile long long stmt = 0;

     size = _eq_vec_size(ast);
     new_ast = _eq_vec_new(size);
     i = 0;
     stmt = 0;
     opt_stmt = 0;
    while (i < size) {
        stmt = _eq_vec_get(ast, i);
        opt_stmt = _eq_optimize_stmt(stmt);
        if (opt_stmt != 0) {
            _eq_vec_push(new_ast, opt_stmt);
        }
        i = i + 1;
    }
    return new_ast;
}
long long _eq_optimize_stmt(long long stmt) {
    volatile long long cond = 0;
    volatile long long dead = 0;
    volatile long long else_branch = 0;
    volatile long long i = 0;
    volatile long long new_stmts = 0;
    volatile long long s = 0;
    volatile long long size = 0;
    volatile long long stmts = 0;
    volatile long long then_branch = 0;
    volatile long long type = 0;

    if (stmt == 0) { return 0; }
     type = ((long long*)(stmt))[0];
     stmts = 0;  new_stmts = 0;  i = 0;  size = 0;  dead = 0;  s = 0;
     cond = 0;  then_branch = 0;  else_branch = 0;
    
    if (type == _eq_g_STMT_BLOCK) {
        stmts = ((long long*)(stmt))[1];
        new_stmts = _eq_vec_new(_eq_vec_size(stmts));
        i = 0;
        size = _eq_vec_size(stmts);
        dead = 0;
        s = 0;
        while (i < size) {
            if (dead == 0) {
                s = _eq_optimize_stmt(_eq_vec_get(stmts, i));
                if (s != 0) {
                    _eq_vec_push(new_stmts, s);
                    if (((long long*)(s))[0] == _eq_g_STMT_RETURN) { dead = 1; }
                }
            }
            i = i + 1;
        }
        ((long long*)(stmt))[1] = new_stmts;
        return stmt;
    }
    
    if (type == _eq_g_STMT_IF) {
        cond = _eq_optimize_expr(((long long*)(stmt))[_eq_g_IF_COND]);
        ((long long*)(stmt))[_eq_g_IF_COND] = cond;
        then_branch = _eq_optimize_stmt(((long long*)(stmt))[_eq_g_IF_THEN]);
        else_branch = _eq_optimize_stmt(((long long*)(stmt))[_eq_g_IF_ELSE]);
        
        
        if (((long long*)(cond))[0] == _eq_g_EXPR_LITERAL) {
            if (((long long*)(cond))[1] != 0) { return then_branch; }
            else { return else_branch; }
        }
        
        ((long long*)(stmt))[_eq_g_IF_THEN] = then_branch;
        ((long long*)(stmt))[_eq_g_IF_ELSE] = else_branch;
        return stmt;
    }
    
    if (type == _eq_g_STMT_WHILE) {
        cond = _eq_optimize_expr(((long long*)(stmt))[_eq_g_WHILE_COND]);
        ((long long*)(stmt))[_eq_g_WHILE_COND] = cond;
        
        if (((long long*)(cond))[0] == _eq_g_EXPR_LITERAL) {
            if (((long long*)(cond))[1] == 0) { return 0; }
        }
        ((long long*)(stmt))[_eq_g_WHILE_BODY] = _eq_optimize_stmt(((long long*)(stmt))[_eq_g_WHILE_BODY]);
        return stmt;
    }
    
    if (type == _eq_g_STMT_FUNCTION) {
        ((long long*)(stmt))[_eq_g_FUNC_BODY] = _eq_optimize_stmt(((long long*)(stmt))[_eq_g_FUNC_BODY]);
        return stmt;
    }

    if (type == _eq_g_STMT_EXPRESSION) {
        ((long long*)(stmt))[1] = _eq_optimize_expr(((long long*)(stmt))[1]);
        return stmt;
    }

    if (type == _eq_g_STMT_LET) {
        if (((long long*)(stmt))[2]) { ((long long*)(stmt))[2] = _eq_optimize_expr(((long long*)(stmt))[2]); }
        return stmt;
    }
    
    return stmt;
}
long long _eq_optimize_expr(long long expr) {
    volatile long long arg = 0;
    volatile long long args = 0;
    volatile long long callee = 0;
    volatile long long i = 0;
    volatile long long left = 0;
    volatile long long lval = 0;
    volatile long long op = 0;
    volatile long long right = 0;
    volatile long long rval = 0;
    volatile long long size = 0;
    volatile long long type = 0;

    if (expr == 0) { return 0; }
     type = ((long long*)(expr))[0];
     left = 0;  right = 0;  op = 0;  lval = 0;  rval = 0;
     callee = 0;  args = 0;  i = 0;  size = 0;  arg = 0;
    
    if (type == _eq_g_EXPR_BINARY) {
        left = _eq_optimize_expr(((long long*)(expr))[_eq_g_BINARY_LEFT]);
        right = _eq_optimize_expr(((long long*)(expr))[_eq_g_BINARY_RIGHT]);
        op = ((long long*)(expr))[_eq_g_BINARY_OP];
        ((long long*)(expr))[_eq_g_BINARY_LEFT] = left;
        ((long long*)(expr))[_eq_g_BINARY_RIGHT] = right;
        
        
        if (((long long*)(left))[0] == _eq_g_EXPR_LITERAL && ((long long*)(right))[0] == _eq_g_EXPR_LITERAL) {
            lval = ((long long*)(left))[1];
            rval = ((long long*)(right))[1];
            if (op == _eq_g_TOKEN_PLUS) { return _eq_expr_literal(lval + rval, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); }
            if (op == _eq_g_TOKEN_MINUS) { return _eq_expr_literal(lval - rval, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); }
            if (op == _eq_g_TOKEN_ASTERISK) { return _eq_expr_literal(lval * rval, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); }
            if (op == _eq_g_TOKEN_SLASH) { if (rval != 0) { return _eq_expr_literal(lval / rval, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } }
            if (op == _eq_g_TOKEN_EQUAL_EQUAL) { if (lval == rval) { return _eq_expr_literal(1, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } else { return _eq_expr_literal(0, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } }
            if (op == _eq_g_TOKEN_BANG_EQUAL) { if (lval != rval) { return _eq_expr_literal(1, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } else { return _eq_expr_literal(0, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } }
            if (op == _eq_g_TOKEN_LESS) { if (lval < rval) { return _eq_expr_literal(1, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } else { return _eq_expr_literal(0, ((long long*)(left))[_eq_g_LITERAL_LINE], ((long long*)(left))[_eq_g_LITERAL_COL]); } }
        }
    }
    
    if (type == _eq_g_EXPR_UNARY) {
        right = _eq_optimize_expr(((long long*)(expr))[_eq_g_UNARY_RIGHT]);
        ((long long*)(expr))[_eq_g_UNARY_RIGHT] = right;
        op = ((long long*)(expr))[_eq_g_UNARY_OP];
        if (((long long*)(right))[0] == _eq_g_EXPR_LITERAL) {
            lval = ((long long*)(right))[1];
            if (op == _eq_g_TOKEN_MINUS) { return _eq_expr_literal(0 - lval, ((long long*)(right))[_eq_g_LITERAL_LINE], ((long long*)(right))[_eq_g_LITERAL_COL]); }
            if (op == _eq_g_TOKEN_BANG) { if (lval == 0) { return _eq_expr_literal(1, ((long long*)(right))[_eq_g_LITERAL_LINE], ((long long*)(right))[_eq_g_LITERAL_COL]); } else { return _eq_expr_literal(0, ((long long*)(right))[_eq_g_LITERAL_LINE], ((long long*)(right))[_eq_g_LITERAL_COL]); } }
        }
    }
    
    if (type == _eq_g_EXPR_CALL) {
        ((long long*)(expr))[_eq_g_CALL_CALLEE] = _eq_optimize_expr(((long long*)(expr))[_eq_g_CALL_CALLEE]);
        args = ((long long*)(expr))[_eq_g_CALL_ARGS];
        i = 0; size = _eq_vec_size(args);
        arg = 0;
        while (i < size) {
            arg = _eq_vec_get(args, i);
            _eq_vec_set(args, i, _eq_optimize_expr(arg));
            i = i + 1;
        }
    }
    
    return expr;
}
long long _eq_lsp_send(long long msg_map) {
    volatile long long body = 0;
    volatile long long header = 0;
    volatile long long len = 0;

     body = _eq_json_serialize(msg_map);
     len = _eq_str_len(body);
     header = _eq_str_concat(((long long)"Content-Length: "), _eq_str_from_int(len));
    header = _eq_str_concat(header, ((long long)"\r\n\r\n"));
    _eq_print_raw_str(header);
    _eq_print_raw_str(body);
}
long long _eq_lsp_find_node_at(long long node, long long line, long long col) {
    volatile long long args = 0;
    volatile long long i = 0;
    volatile long long res = 0;
    volatile long long size = 0;
    volatile long long type = 0;

    if (node == 0) { return 0; }
     type = ((long long*)(node))[0];
    if (type == _eq_g_EXPR_VARIABLE) {
        if (((long long*)(node))[2] == line) {
            if (col >= ((long long*)(node))[3]) {
                if (col <= ((long long*)(node))[3] + _eq_str_len(((long long*)(node))[1])) { return node; }
            }
        }
    } else if (type == _eq_g_EXPR_CALL) {
         res = _eq_lsp_find_node_at(((long long*)(node))[1], line, col);
        if (res) { return res; }
         args = ((long long*)(node))[2];  i = 0;  size = _eq_vec_size(args);
        while (i < size) {
            res = _eq_lsp_find_node_at(_eq_vec_get(args, i), line, col);
            if (res) { return res; }
            i = i + 1;
        }
    } else if (type == _eq_g_EXPR_BINARY) {
         res = _eq_lsp_find_node_at(((long long*)(node))[_eq_g_BINARY_LEFT], line, col);
        if (res) { return res; }
        res = _eq_lsp_find_node_at(((long long*)(node))[_eq_g_BINARY_RIGHT], line, col);
        if (res) { return res; }
    } else if (type == _eq_g_EXPR_UNARY) {
        return _eq_lsp_find_node_at(((long long*)(node))[_eq_g_UNARY_RIGHT], line, col);
    } else if (type == _eq_g_EXPR_INDEX) {
         res = _eq_lsp_find_node_at(((long long*)(node))[_eq_g_INDEX_OBJ], line, col);
        if (res) { return res; }
        return _eq_lsp_find_node_at(((long long*)(node))[_eq_g_INDEX_IDX], line, col);
    } else if (type == _eq_g_EXPR_GET) {
        return _eq_lsp_find_node_at(((long long*)(node))[_eq_g_GET_OBJ], line, col);
    }
    return 0;
}
long long _eq_lsp_find_stmt_at(long long ast, long long line, long long col) {
    volatile long long func_body = 0;
    volatile long long i = 0;
    volatile long long n = 0;
    volatile long long res = 0;
    volatile long long stmt = 0;
    volatile long long type = 0;

     i = 0;  n = _eq_vec_size(ast);
    while (i < n) {
         stmt = _eq_vec_get(ast, i);
         type = ((long long*)(stmt))[0];
        if (type == _eq_g_STMT_FUNCTION) {
             func_body = ((long long*)(stmt))[3];
             res = _eq_lsp_find_stmt_at(((long long*)(func_body))[1], line, col);
            if (res) { return res; }
        } else if (type == _eq_g_STMT_BLOCK) {
             res = _eq_lsp_find_stmt_at(((long long*)(stmt))[1], line, col);
            if (res) { return res; }
        } else if (type == _eq_g_STMT_EXPRESSION) {
             res = _eq_lsp_find_node_at(((long long*)(stmt))[1], line, col);
            if (res) { return res; }
        } else if (type == _eq_g_STMT_LET) {
            if (((long long*)(stmt))[_eq_g_LET_VAL]) {
                 res = _eq_lsp_find_node_at(((long long*)(stmt))[_eq_g_LET_VAL], line, col);
                if (res) { return res; }
            }
        }
        i = i + 1;
    }
    return 0;
}
long long _eq_lsp_publish_diagnostics(long long uri, long long a) {
    volatile long long d = 0;
    volatile long long diag_list = 0;
    volatile long long diags = 0;
    volatile long long end = 0;
    volatile long long i = 0;
    volatile long long item = 0;
    volatile long long params = 0;
    volatile long long range = 0;
    volatile long long res = 0;
    volatile long long size = 0;
    volatile long long start = 0;

     diags = ((long long*)(a))[4];
     res = _eq_json_new();
    _eq_json_put_str(res, ((long long)"method"), ((long long)"textDocument/publishDiagnostics"));
     params = _eq_json_new();
    _eq_json_put_str(params, ((long long)"uri"), uri);
     diag_list = _eq_vec_new(200000);
     i = 0;  size = _eq_vec_size(diags);
    while (i < size) {
         d = _eq_vec_get(diags, i);
         item = _eq_json_new();
        _eq_json_put_str(item, ((long long)"message"), ((long long*)(d))[0]);
        _eq_json_put_int(item, ((long long)"severity"), ((long long*)(d))[3]);
         range = _eq_json_new();
         start = _eq_json_new();
        _eq_json_put_int(start, ((long long)"line"), ((long long*)(d))[1] - 1);
        _eq_json_put_int(start, ((long long)"character"), ((long long*)(d))[2] - 1);
         end = _eq_json_new();
        _eq_json_put_int(end, ((long long)"line"), ((long long*)(d))[1] - 1);
        _eq_json_put_int(end, ((long long)"character"), ((long long*)(d))[2]);
        _eq_json_put_obj(range, ((long long)"start"), start);
        _eq_json_put_obj(range, ((long long)"end"), end);
        _eq_json_put_obj(item, ((long long)"range"), range);
        diag_list = _eq_vec_push(diag_list, _eq_json_item_obj(item));
        i = i + 1;
    }
    _eq_json_put_array(params, ((long long)"diagnostics"), diag_list);
    _eq_json_put_obj(res, ((long long)"params"), params);
    _eq_lsp_send(res);
}
long long _eq_lsp_loop() {
    volatile long long a = 0;
    volatile long long ast = 0;
    volatile long long buf = 0;
    volatile long long c = 0;
    volatile long long caps = 0;
    volatile long long changes = 0;
    volatile long long char_buf = 0;
    volatile long long col = 0;
    volatile long long content = 0;
    volatile long long content_len = 0;
    volatile long long contents = 0;
    volatile long long def_node = 0;
    volatile long long doc = 0;
    volatile long long end = 0;
    volatile long long entry = 0;
    volatile long long first_change = 0;
    volatile long long header_done = 0;
    volatile long long hover_text = 0;
    volatile long long i = 0;
    volatile long long id = 0;
    volatile long long l = 0;
    volatile long long line = 0;
    volatile long long line_buf = 0;
    volatile long long loc = 0;
    volatile long long method = 0;
    volatile long long node = 0;
    volatile long long p = 0;
    volatile long long params = 0;
    volatile long long pos = 0;
    volatile long long r = 0;
    volatile long long range = 0;
    volatile long long req = 0;
    volatile long long res = 0;
    volatile long long result = 0;
    volatile long long start = 0;
    volatile long long text = 0;
    volatile long long tokens = 0;
    volatile long long total_read = 0;
    volatile long long type_str = 0;
    volatile long long uri = 0;

     buf = sys_malloc(1024 * 64); 
     char_buf = sys_malloc(8);
    _eq_print_err(((long long)"Equis LSP Started (Mode)\n"));
    while (1) {
        
         content_len = 0;
         line_buf = sys_malloc(1024);
         header_done = 0;
        while (header_done == 0) {
             i = 0;
             c = 0;
            while (i < 1023) {
                (void)!read(0, (void*)char_buf, 1);
                c = get_char(char_buf, 0);
                if (c == 10) { 
                    set_char(line_buf, i, 0);
                    i = 10000; 
                } else if (c != 13) {
                    set_char(line_buf, i, c);
                    i = i + 1;
                }
            }
            if (i == 0) { 
                header_done = 1;
            } else {
                if (_eq_str_substring_equal(line_buf, 0, 16, ((long long)"Content-Length: "))) {
                    content_len = str_to_int(sys_ptr_add(line_buf, 16));
                }
            }
        }
        
        if (content_len > 0) {
             total_read = 0;
            while (total_read < content_len) {
                 r = read(0, (void*)sys_ptr_add(buf, total_read), (size_t)(content_len - total_read));
                if (r <= 0) { exit(0); }
                total_read = total_read + r;
            }
            set_char(buf, content_len, 0);
            
             req = _eq_json_parse(buf);
            if (req) {
                 id = _eq_json_get_int(req, ((long long)"id"));
                 method = _eq_json_get_str(req, ((long long)"method"));
                if (method) {
                    if (_eq_str_equal(method, ((long long)"initialize"))) {
                         res = _eq_json_new();
                        _eq_json_put_int(res, ((long long)"id"), id);
                         result = _eq_json_new();
                         caps = _eq_json_new();
                        _eq_json_put_int(caps, ((long long)"textDocumentSync"), 1);
                        _eq_json_put_str(result, ((long long)"capabilities"), caps);
                        _eq_map_put(res, ((long long)"result"), result);
                        _eq_lsp_send(res);
                    } else if (_eq_str_equal(method, ((long long)"textDocument/didOpen"))) {
                         params = _eq_map_get(req, ((long long)"params"));
                         doc = _eq_map_get(params, ((long long)"textDocument"));
                         uri = _eq_map_get(doc, ((long long)"uri"));
                         text = _eq_map_get(doc, ((long long)"text"));
                        
                         l = _eq_lexer_new(text, ((long long)"LSP_CONTENT"));
                         tokens = _eq_lexer_scan_tokens(l);
                         p = _eq_parser_new(tokens);
                         ast = _eq_parse_program(p);
                         a = _eq_analyzer_new();
                        _eq_analyze_program(a, ast);
                        _eq_lsp_publish_diagnostics(uri, a);
                    } else if (_eq_str_equal(method, ((long long)"textDocument/didChange"))) {
                         params = _eq_map_get(req, ((long long)"params"));
                         doc = _eq_map_get(params, ((long long)"textDocument"));
                         uri = _eq_map_get(doc, ((long long)"uri"));
                         changes = _eq_map_get(params, ((long long)"contentChanges"));
                         first_change = _eq_vec_get(changes, 0); 
                         text = _eq_map_get(first_change, ((long long)"text"));
                        
                         l = _eq_lexer_new(text, ((long long)"LSP_CONTENT"));
                         tokens = _eq_lexer_scan_tokens(l);
                         p = _eq_parser_new(tokens);
                         ast = _eq_parse_program(p);
                         a = _eq_analyzer_new();
                        _eq_analyze_program(a, ast);
                        _eq_lsp_publish_diagnostics(uri, a);
                    } else if (_eq_str_equal(method, ((long long)"textDocument/definition"))) {
                         params = _eq_map_get(req, ((long long)"params"));
                         doc = _eq_map_get(params, ((long long)"textDocument"));
                         pos = _eq_map_get(params, ((long long)"position"));
                         uri = _eq_map_get(doc, ((long long)"uri"));
                         line = _eq_json_get_int(pos, ((long long)"line")) + 1;
                         col = _eq_json_get_int(pos, ((long long)"character"));
                        
                        
                        
                         content = sys_read_entire_file(uri); 
                        if (content) {
                             l = _eq_lexer_new(content, uri);
                             tokens = _eq_lexer_scan_tokens(l);
                             p = _eq_parser_new(tokens);
                             ast = _eq_parse_program(p);
                             a = _eq_analyzer_new();
                            _eq_analyze_program(a, ast);
                            
                             node = _eq_lsp_find_stmt_at(ast, line, col);
                            if (node) {
                                if (((long long*)(node))[0] == _eq_g_EXPR_VARIABLE) {
                                     entry = _eq_analyzer_resolve(a, ((long long*)(node))[1]);
                                    if (entry) {
                                         def_node = ((long long*)(entry))[1];
                                        if (def_node) {
                                             res = _eq_json_new();
                                            _eq_json_put_int(res, ((long long)"id"), id);
                                             loc = _eq_json_new();
                                            _eq_json_put_str(loc, ((long long)"uri"), uri);
                                             range = _eq_json_new();
                                             start = _eq_json_new();
                                            _eq_json_put_int(start, ((long long)"line"), ((long long*)(def_node))[_eq_g_FUNC_LINE] - 1);
                                            _eq_json_put_int(start, ((long long)"character"), ((long long*)(def_node))[_eq_g_FUNC_COL] - 1);
                                             end = _eq_json_new();
                                            _eq_json_put_int(end, ((long long)"line"), ((long long*)(def_node))[_eq_g_FUNC_LINE] - 1);
                                            _eq_json_put_int(end, ((long long)"character"), ((long long*)(def_node))[_eq_g_FUNC_COL] + 10);
                                            _eq_json_put_obj(range, ((long long)"start"), start);
                                            _eq_json_put_obj(range, ((long long)"end"), end);
                                            _eq_json_put_obj(loc, ((long long)"range"), range);
                                            _eq_map_put(res, ((long long)"result"), _eq_json_item_obj(loc));
                                            _eq_lsp_send(res);
                                        }
                                    }
                                }
                            }
                        }
                    } else if (_eq_str_equal(method, ((long long)"textDocument/hover"))) {
                         params = _eq_map_get(req, ((long long)"params"));
                         doc = _eq_map_get(params, ((long long)"textDocument"));
                         pos = _eq_map_get(params, ((long long)"position"));
                         uri = _eq_map_get(doc, ((long long)"uri"));
                         line = _eq_json_get_int(pos, ((long long)"line")) + 1;
                         col = _eq_json_get_int(pos, ((long long)"character"));
                         content = sys_read_entire_file(uri);
                        if (content) {
                             l = _eq_lexer_new(content, uri);
                             tokens = _eq_lexer_scan_tokens(l);
                             p = _eq_parser_new(tokens);
                             ast = _eq_parse_program(p);
                             a = _eq_analyzer_new();
                            _eq_analyze_program(a, ast);
                             node = _eq_lsp_find_stmt_at(ast, line, col);
                            if (node) {
                                if (((long long*)(node))[0] == _eq_g_EXPR_VARIABLE) {
                                     entry = _eq_analyzer_resolve(a, ((long long*)(node))[1]);
                                    if (entry) {
                                         res = _eq_json_new();
                                        _eq_json_put_int(res, ((long long)"id"), id);
                                         result = _eq_json_new();
                                         contents = _eq_json_new();
                                        _eq_json_put_str(contents, ((long long)"kind"), ((long long)"markdown"));
                                         type_str = ((long long)"Unknown Type");
                                        if (((long long*)(entry))[2] == _eq_g_TOKEN_F64) { type_str = ((long long)"f64"); }
                                        if (((long long*)(entry))[2] == _eq_g_TOKEN_BOOL) { type_str = ((long long)"bool"); }
                                        if (((long long*)(entry))[2] == 0) { type_str = ((long long)"any/inferred"); }
                                         hover_text = _eq_str_concat(((long long)"**Type**: `"), type_str);
                                        hover_text = _eq_str_concat(hover_text, ((long long)"`"));
                                        _eq_json_put_str(contents, ((long long)"value"), hover_text);
                                        _eq_map_put(result, ((long long)"contents"), _eq_json_item_obj(contents));
                                        _eq_map_put(res, ((long long)"result"), _eq_json_item_obj(result));
                                        _eq_lsp_send(res);
                                    }
                                }
                            }
                        }
                    } else if (_eq_str_equal(method, ((long long)"shutdown"))) {
                         res = _eq_json_new();
                        _eq_json_put_int(res, ((long long)"id"), id);
                        _eq_map_put(res, ((long long)"result"), 0);
                        _eq_lsp_send(res);
                        exit(0);
                    }
                }
            }
        }
    }
}
long long _eq_is_loaded(long long path) {
    volatile long long i = 0;
    volatile long long size = 0;

     size = 0;
     i = 0;
    size = _eq_vec_size(_eq_g_loaded_files);
    i = 0;
    while (i < size) {
        if (_eq_str_equal(_eq_vec_get(_eq_g_loaded_files, i), path)) { return 1; }
        i = i + 1;
    }
    return 0;
}
long long _eq_try_read(long long path) {
    volatile long long source = 0;

     source = 0;
    extern long long sys_read_entire_file_raw(const char* p);
    source = sys_read_entire_file_raw((const char*)path);
    if (source != 0) {
        if (_eq_str_len(source) > 0) { return source; }
        _eq_sys_release(source);
    }
    return 0;
}
long long _eq_compile_file(long long path) {
    volatile long long ast = 0;
    volatile long long ast_size = 0;
    volatile long long full_path = 0;
    volatile long long i = 0;
    volatile long long j = 0;
    volatile long long lex = 0;
    volatile long long node = 0;
    volatile long long p = 0;
    volatile long long p_size = 0;
    volatile long long source = 0;
    volatile long long tokens = 0;

     source = 0;
     j = 0;
     p_size = 0;
     full_path = 0;
     lex = 0;
     tokens = 0;
     p = 0;
     ast = 0;
     i = 0;
     ast_size = 0;
    source = 0;
    j = 0;
    p_size = 0;
    full_path = 0;
    if (_eq_g_compile_depth > 200) { exit(1); }
    _eq_g_compile_depth = _eq_g_compile_depth + 1;
    path = _eq_intern_string(path);
    if (_eq_is_loaded(path)) { return 0; }
    _eq_g_loaded_files = _eq_vec_push(_eq_g_loaded_files, path);
    source = _eq_try_read(path);
    if (source == 0) {
        j = 0;
        p_size = _eq_vec_size(_eq_g_include_paths);
        while (j < p_size) {
            full_path = _eq_str_concat(_eq_str_concat(_eq_vec_get(_eq_g_include_paths, j), ((long long)"/")), path);
            source = _eq_try_read(full_path);
            if (source != 0) { j = p_size; }
            j = j + 1;
        }
    }
    if (source == 0) {
        (void)!write(2, (void*)((long long)"error: could not read file: "), 28);
        (void)!write(2, (void*)path, (size_t)_eq_str_len(path));
        (void)!write(2, (void*)((long long)"\n"), 1);
        exit(1);
    }
    lex = _eq_lexer_new(source, path);
    tokens = _eq_lexer_scan_tokens(lex);
    p = _eq_parser_new(tokens);
    ast = _eq_parse_program(p);
    i = 0;
    ast_size = _eq_vec_size(ast);
    while (i < ast_size) {
         node = _eq_vec_get(ast, i);
        if (((long long*)(node))[0] == 108) {
            _eq_compile_file(((long long*)(node))[1]);
        }
        _eq_vec_push(_eq_g_global_ast_buffer, node);
        i = i + 1;
    }
    return 1;
}
long long _eq___equis_pre_intern() {
     _eq_intern_string(((long long)"0"));
     _eq_intern_string(((long long)"1"));
     _eq_intern_string(((long long)""));
     return 0;
}
long long _eq_main_routine() {
    volatile long long ai = 0;
    volatile long long arg_val = 0;
     _eq___equis_pre_intern();
    volatile long long argc = 0;
    volatile long long ast_len = 0;
    volatile long long ctx = 0;
    volatile long long ki = 0;
    volatile long long sem = 0;
    volatile long long start_file = 0;
    volatile long long trace_enabled = 0;
     sem = 0;
     ctx = 0;
     argc = sys_get_argc();

     _eq___equis_pre_intern();

    if (argc < 2) {
        (void)!write(2, (void*)((long long)"Usage: eq <filename> [-I path]\n"), 31);
        exit(1);
    }
     start_file = 0;

    
    sys_write_raw(1, ((long long)"; Equis Stage-1 IR Output Header\n"), 33);

    start_file = 0;
     ai = 1;
     arg_val = 0;
     trace_enabled = 0;
    while (ai < argc) {
        arg_val = sys_get_argv(ai);
        if (_eq_str_equal(arg_val, ((long long)"-I"))) {
            ai = ai + 1;
            if (ai < argc) { _eq_g_include_paths = _eq_vec_push(_eq_g_include_paths, sys_get_argv(ai)); }
        } else if (_eq_str_equal(arg_val, ((long long)"--trace"))) {
            trace_enabled = 1;
        } else if (_eq_str_equal(arg_val, ((long long)"--lsp"))) {
            
            exit(1);
        } else if (_eq_str_equal(arg_val, ((long long)"build-obj"))) {
            _eq_g_incremental_flag = 1;
            ai = ai + 1;
            if (ai < argc) { start_file = sys_get_argv(ai); }
            ai = ai - 1; 
        } else {
            if (start_file == 0) { start_file = arg_val; }
        }
        ai = ai + 1;
    }
    _eq_compile_file(start_file);
    if (_eq_vec_size(_eq_g_global_ast_buffer) == 0) { exit(1); }
    sem = _eq_analyzer_new();
    _eq_analyze_program(sem, _eq_g_global_ast_buffer);
    if (_eq_g_global_ast_buffer == 0) { exit(1); }
    ctx = _eq_codegen_new(trace_enabled, 1);
    if (!ctx) return 0;
    _eq_gen_program(ctx, _eq_g_global_ast_buffer);
    
    
    _eq_sys_release(ctx);
    _eq_sys_release(sem);
     ast_len = _eq_vec_size(_eq_g_global_ast_buffer);
     ki = 0;
    while (ki < ast_len) {
        _eq_sys_release(_eq_vec_get(_eq_g_global_ast_buffer, ki));
        ki = ki + 1;
    }
    _eq_sys_release(_eq_g_global_ast_buffer);
    _eq_sys_release(_eq_g_loaded_files);
    _eq_sys_release(_eq_g_include_paths);
    _eq_intern_cleanup();
}

void _eq___equis_init_globals() {


 _eq_g___global_print_buf = 0;


















































































 _eq_g_JSON_TYPE_STRING = 1;
 _eq_g_JSON_TYPE_INT = 2;
 _eq_g_JSON_TYPE_OBJECT = 3;
 _eq_g_JSON_TYPE_ARRAY = 4;







































 _eq_g_TOKEN_EOF = 0;
 _eq_g_TOKEN_IF = 1;
 _eq_g_TOKEN_ELSE = 2;
 _eq_g_TOKEN_WHILE = 3;
 _eq_g_TOKEN_IDENTIFIER = 4;
 _eq_g_TOKEN_NUMBER = 5;
 _eq_g_TOKEN_LBRACE = 6;
 _eq_g_TOKEN_RBRACE = 7;
 _eq_g_TOKEN_SEMICOLON = 8;
 _eq_g_TOKEN_EQUAL = 9;
 _eq_g_TOKEN_PLUS = 10;
 _eq_g_TOKEN_LPARENT = 11;
 _eq_g_TOKEN_RPARENT = 12;
 _eq_g_TOKEN_COMMA = 13;
 _eq_g_TOKEN_LBRACKET = 22;
 _eq_g_TOKEN_RBRACKET = 23;
 _eq_g_TOKEN_DOT = 14;
 _eq_g_TOKEN_MINUS = 15;
 _eq_g_TOKEN_ASTERISK = 16;
 _eq_g_TOKEN_SLASH = 17;
 _eq_g_TOKEN_LET = 18;
 _eq_g_TOKEN_MUT = 72;
 _eq_g_TOKEN_FN = 19;
 _eq_g_TOKEN_MUT = 72;
 _eq_g_TOKEN_RETURN = 20;
 _eq_g_TOKEN_PRINT = 21;
 _eq_g_TOKEN_PERCENT = 39;
 _eq_g_TOKEN_STRING = 24;
 _eq_g_TOKEN_PTR = 82;
 _eq_g_TOKEN_USE = 25;
 _eq_g_TOKEN_COLON = 26;
 _eq_g_TOKEN_EQUAL_EQUAL = 27;
 _eq_g_TOKEN_BANG_EQUAL = 28;
 _eq_g_TOKEN_EXTERN = 29;
 _eq_g_TOKEN_LESS = 30;
 _eq_g_TOKEN_LESS_EQUAL = 31;
 _eq_g_TOKEN_GREATER = 32;
 _eq_g_TOKEN_GREATER_EQUAL = 33;
 _eq_g_TOKEN_BANG = 34;
 _eq_g_TOKEN_OR = 35;
 _eq_g_TOKEN_AND = 36;
 _eq_g_TOKEN_STRUCT = 37;
 _eq_g_TOKEN_COLON_COLON = 38;
 _eq_g_TOKEN_AGENT = 40;
 _eq_g_TOKEN_RESOURCE = 41;
 _eq_g_TOKEN_TRY = 73;
 _eq_g_TOKEN_AMPERSAND = 74;
 _eq_g_TOKEN_AMPERSAND_MUT = 75;
 _eq_g_EXPR_VARIABLE = 4;
 _eq_g_EXPR_GET = 9;
 _eq_g_EXPR_TRY = 10;
 _eq_g_EXPR_REFERENCE = 11;
 _eq_g_TOKEN_EVENT = 42;
 _eq_g_TOKEN_FLOW = 43;
 _eq_g_TOKEN_IN = 44;
 _eq_g_TOKEN_OUT = 45;
 _eq_g_TOKEN_FROM = 46;
 _eq_g_TOKEN_TO = 47;
 _eq_g_TOKEN_LOGIC = 48;
 _eq_g_TOKEN_EXECUTE = 49;
 _eq_g_TOKEN_ASSERT = 50;
 _eq_g_TOKEN_COMMITMENT = 51;
 _eq_g_TOKEN_POLICY = 52;
 _eq_g_TOKEN_UNIT = 53;
 _eq_g_TOKEN_REVERSE = 54;
 _eq_g_TOKEN_EXCHANGE = 55;
 _eq_g_TOKEN_TRANSFORMATION = 56;
 _eq_g_TOKEN_VALUATOR = 57;
 _eq_g_TOKEN_FULFILLS = 58;
 _eq_g_TOKEN_ARROW = 71;
 _eq_g_TOKEN_LSHIFT = 76;
 _eq_g_TOKEN_BITOR = 77;
 _eq_g_TOKEN_QUESTION = 70;
 _eq_g_TOKEN_ROLES = 59;
 _eq_g_TOKEN_EVALUATED_BY = 60;
 _eq_g_TOKEN_INTERFACE = 61;
 _eq_g_TOKEN_IMPLEMENTS = 62;
 _eq_g_TOKEN_ENUM = 66;
 _eq_g_TOKEN_MATCH = 67;
 _eq_g_TOKEN_FAT_ARROW = 68;
 _eq_g_TOKEN_F64 = 63;
 _eq_g_TOKEN_BOOL = 64;
 _eq_g_TOKEN_I64 = 65;
 _eq_g_EXPR_BINARY = 1;
 _eq_g_EXPR_UNARY = 2;
 _eq_g_EXPR_LITERAL = 3;
 _eq_g_EXPR_VARIABLE = 4;
 _eq_g_EXPR_CALL = 5;
 _eq_g_EXPR_INDEX = 6;
 _eq_g_EXPR_ASSIGNMENT = 7;
 _eq_g_EXPR_STRING_LITERAL = 8;
 _eq_g_EXPR_GET = 9;
 _eq_g_AST_TYPE = 0;
 _eq_g_BINARY_LEFT = 1;  _eq_g_BINARY_OP = 2;  _eq_g_BINARY_RIGHT = 3;  _eq_g_BINARY_LINE = 4;  _eq_g_BINARY_COL = 5;
 _eq_g_UNARY_OP = 1;  _eq_g_UNARY_RIGHT = 2;  _eq_g_UNARY_LINE = 3;  _eq_g_UNARY_COL = 4;
 _eq_g_LITERAL_VAL = 1;  _eq_g_LITERAL_LINE = 2;  _eq_g_LITERAL_COL = 3;
 _eq_g_VAR_NAME = 1;  _eq_g_VAR_LINE = 2;  _eq_g_VAR_COL = 3;
 _eq_g_CALL_CALLEE = 1;  _eq_g_CALL_ARGS = 2;  _eq_g_CALL_LINE = 3;  _eq_g_CALL_COL = 4;  _eq_g_CALL_GENERICS = 5;
 _eq_g_INDEX_OBJ = 1;  _eq_g_INDEX_IDX = 2;  _eq_g_INDEX_LINE = 3;  _eq_g_INDEX_COL = 4;
 _eq_g_ASSIGN_TARGET = 1;  _eq_g_ASSIGN_VALUE = 2;  _eq_g_ASSIGN_LINE = 3;  _eq_g_ASSIGN_COL = 4;
 _eq_g_GET_OBJ = 1;  _eq_g_GET_NAME = 2;  _eq_g_GET_LINE = 3;  _eq_g_GET_COL = 4;
 _eq_g_LET_NAME = 1;  _eq_g_LET_VAL = 2;  _eq_g_LET_TYPE = 3;  _eq_g_LET_LINE = 4;  _eq_g_LET_COL = 5;  _eq_g_LET_IS_MUT = 6;  _eq_g_LET_IS_RESOURCE = 7;
 _eq_g_TRY_EXPR = 1;
 _eq_g_IF_COND = 1;  _eq_g_IF_THEN = 2;  _eq_g_IF_ELSE = 3;  _eq_g_IF_LINE = 4;  _eq_g_IF_COL = 5;
 _eq_g_WHILE_COND = 1;  _eq_g_WHILE_BODY = 2;  _eq_g_WHILE_LINE = 3;  _eq_g_WHILE_COL = 4;
 _eq_g_FUNC_NAME = 1;  _eq_g_FUNC_PARAMS = 2;  _eq_g_FUNC_BODY = 3;  _eq_g_FUNC_LINE = 4;  _eq_g_FUNC_COL = 5;  _eq_g_FUNC_GENERICS = 6; _eq_g_FUNC_PARAMS_TYPES = 7; _eq_g_FUNC_RETURN_TYPE = 8; _eq_g_FUNC_PARAMS_MUT = 9;
 _eq_g_AGENT_NAME = 1;  _eq_g_AGENT_FIELDS = 2;  _eq_g_AGENT_LINE = 3;  _eq_g_AGENT_COL = 4;  _eq_g_AGENT_ROLES = 5;  _eq_g_AGENT_IMPLEMENTS = 6;
 _eq_g_EVENT_NAME = 1;  _eq_g_EVENT_LOGIC = 2;  _eq_g_EVENT_FLOWS = 3;  _eq_g_EVENT_LINE = 4;  _eq_g_EVENT_COL = 5;  _eq_g_EVENT_FULFILLS = 6;  _eq_g_EVENT_ROLES = 7;  _eq_g_EVENT_VALUATOR = 8;
 _eq_g_COMMITMENT_NAME = 1;  _eq_g_COMMITMENT_LOGIC = 2;  _eq_g_COMMITMENT_FLOWS = 3;  _eq_g_COMMITMENT_LINE = 4;  _eq_g_COMMITMENT_VALUATOR = 5;
 _eq_g_EXCHANGE_NAME = 1;  _eq_g_EXCHANGE_EVENTS = 2;  _eq_g_EXCHANGE_LINE = 3;  _eq_g_EXCHANGE_COL = 4;
 _eq_g_TRANSFORMATION_NAME = 1;  _eq_g_TRANSFORMATION_LOGIC = 2;  _eq_g_TRANSFORMATION_FLOWS = 3;  _eq_g_TRANSFORMATION_LINE = 4;  _eq_g_TRANSFORMATION_COL = 5; _eq_g_TRANSFORMATION_ROLES = 7;
 _eq_g_VALUATOR_NAME = 1;  _eq_g_VALUATOR_BODY = 2;  _eq_g_VALUATOR_LINE = 3;  _eq_g_VALUATOR_COL = 4;  _eq_g_VALUATOR_IMPLEMENTS = 5;
 _eq_g_FLOW_TYPE = 1;  _eq_g_FLOW_AMOUNT = 2;  _eq_g_FLOW_RES = 3;  _eq_g_FLOW_FROM = 4;  _eq_g_FLOW_TO = 5;  _eq_g_FLOW_LINE = 6;  _eq_g_FLOW_COL = 7;
 _eq_g_STMT_EXPRESSION = 101;
 _eq_g_STMT_LET = 102;
 _eq_g_STMT_IF = 103;
 _eq_g_STMT_WHILE = 104;
 _eq_g_STMT_RETURN = 105;
 _eq_g_STMT_BLOCK = 106;
 _eq_g_STMT_PRINT = 107;
 _eq_g_STMT_USE = 108;
 _eq_g_STMT_FUNCTION = 109;
 _eq_g_STMT_EXTERN = 110;
 _eq_g_STMT_STRUCT = 111;  _eq_g_STRUCT_NAME = 1;  _eq_g_STRUCT_BODY = 2;  _eq_g_STRUCT_LINE = 3;  _eq_g_STRUCT_COL = 4;  _eq_g_STRUCT_GENERICS = 5;
 _eq_g_STMT_AGENT = 120;
 _eq_g_STMT_RESOURCE = 121;
 _eq_g_STMT_EVENT = 122;
 _eq_g_STMT_EXECUTE = 123;
 _eq_g_STMT_ASSERT = 124;
 _eq_g_STMT_LOGIC = 125;
 _eq_g_STMT_FLOW = 126;
 _eq_g_STMT_COMMITMENT = 127;
 _eq_g_STMT_POLICY = 128;
 _eq_g_STMT_REVERSE = 129;
 _eq_g_STMT_EXCHANGE = 130;
 _eq_g_STMT_TRANSFORMATION = 131;
 _eq_g_STMT_VALUATOR = 112;
 _eq_g_STMT_ASSIGN = 132;
 _eq_g_STMT_INTERFACE = 133;




























 _eq_g___intern_map = 0;








 
 












































































 _eq_g_resolve_stat = 0;


































 _eq_g_Magic_Malloc = 0;
 _eq_g_Magic_Free = 0;
 _eq_g_Magic_GetChar = 0;
 _eq_g_Magic_SetChar = 0;
 _eq_g_String_Map = 0;
 _eq_g_Global_Field_Map = 0;
 _eq_g_print_buf = 0;






























































 _eq_g_loaded_files = _eq_vec_new(200000);
 _eq_g_global_ast_buffer = _eq_vec_new(200000);
 _eq_g_compile_depth = 0;
 _eq_g_include_paths = _eq_vec_new(200000);
 _eq_g_incremental_flag = 0;







}

void _eq___equis_cleanup_globals() {
    return;
}

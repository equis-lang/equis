# Standard Library Reference

The Equis Standard Library (`std`) provides a foundational set of modules for memory management, data structures, and enterprise economic modeling. This reference covers implemented functions as of v0.1.0.

## Core Runtime

### `std/sys.equis`
Low-level system interaction and memory management.
- `sys_malloc(size)`: Allocates raw memory from the heap. Triggers exit on failure.
- `sys_release(ptr)`: Decrements reference count on a heap object.
- `print_raw(val)`, `print_raw_stderr(val)`: Direct numeric output.
- `print_raw_str(s)`, `print_err(s)`: Direct string output.
- `sys_strlen(s)`: Calculates null-terminated string length.
- `sys_read_entire_file(path)`: Efficiently reads a local file into memory.
- `sys_time()`: Returns the current system epoch time.
- `sys_os()`: Returns 1 (Linux), 2 (Windows), or 3 (macOS).
- `sys_rename(old, new)`: Atomic file rename primitive.

### `std/arena.equis`
Linear bump-pointer allocator for deterministic memory management.
- `arena_new(size)`: Initializes a new memory arena.
- `arena_alloc(arena, size)`: Allocates aligned memory from the specified arena.
- `arena_free_all(arena)`: Resets the arena pointer and releases all associated blocks.

### `std/fiber.equis`
Cooperative and preemptive multitasking.
- `fiber_spawn(f_ptr)`: Adds a function to the scheduler queue.
- `fiber_yield()`: Voluntarily cedes control to the next fiber.
- `fiber_preempt_enable(ms)`: Enables signal-based preemption at the given interval (milliseconds).
- `fiber_scheduler_run()`: Starts the main round-robin execution loop.

### `std/chan.equis`
Concurrent message passing channels.
- `chan_new(size)`: Initializes a bounded communication channel.
- `chan_send(c, val)`: Pushes a value into the channel (blocks if full).
- `chan_recv(c)`: Pulls a received value from the channel (blocks if empty).

## Data Structures

### `std/string.equis`
Byte-array string manipulation.
- `str_len(s)`: Unified length check.
- `str_equal(s1, s2)`: Content-based equality verification.
- `str_concat(s1, s2)`: Allocates and returns a joined string.
- `str_substring(s, start, len)`: Extracts a partial string.
- `str_from_int(n)`: Converts a 64-bit integer to a decimal string.
- `str_to_int(s)`: Parses a decimal string to a 64-bit integer.

### `std/intern.equis`
String interning for symbol processing.
- `intern_string(s)`: Deduplicates strings and returns a stable pointer for O(1) identity checks.

### `std/collections.equis`
Reusable heap-allocated collections.
- `vec_new(cap)`, `vec_push(v, val)`, `vec_get(v, idx)`, `vec_size(v)`.
- `map_new(cap)`, `map_put(m, key, val)`, `map_get(m, key)`, `map_keys(m)`.

### `std/record.equis`
COBOL-style fixed-width data buffers for legacy parity.
- `record_layout_new()`: Initializes a record definition.
- `record_add_field(l, name, len, type)`: Defines a named field within the layout.
- `record_get_str(l, buf, name)`, `record_get_int(l, buf, name)`: Extracts typed data from a raw buffer.
- `record_set_str(l, buf, name, val)`, `record_set_int(l, buf, name, val)`: Serializes data into a raw buffer.

## Math & Enterprise

### `std/fixed.equis`
Fixed-point arithmetic (Scale: 1,000,000).
- `fixed_from_int(n)`, `fixed_to_str(n)`, `print_fixed(n)`.
- `fixed_add(a, b)`, `fixed_sub(a, b)`, `fixed_mul(a, b)`, `fixed_div(a, b)`.

### `std/ledger.equis`
Temporal resource balance tracking.
- `ledger_new()`: Initializes a resource tracking ledger.
- `ledger_process_flow(l, type, amount, res, cur, from, to, date)`: Commits REA flows to history.
- `ledger_balance_at(l, agent, res, cur, date)`: Calculates agent balance for a specific resource at a point in time.

### `std/dual_net.equis`
Cross-node distributed duality consensus routines.
- `verify_dual(peer_addr, event_id)`: Initiates cross-node duality verification sequences.
- `commit_event(id, hash)`: Generates a remote network commitment event.

### `std/accounting.equis`
Financial primitives.
- `accounting_init(res, cur)`: Bootstraps an accounting context.
- `acct_register(sys, name, type, code)`: Defines account metadata.
- `journal_entry(acct_sys, amount, res, cur, from_acc, to_acc, date)`: Records double-entry movements.
- `report_income_statement(acct_sys, rev_acc, exp_acc, target_date)`, `report_balance_sheet(acct_sys, asset_acc, liab_acc, equity_acc, target_date)`.

### `std/compliance.equis`
Regulatory and policy enforcement logic.
- `compliance_calculate_vat(amount, rate)`: Tax calculation primitive.
- `policy_enforce_spending_limit(bal, tx, limit)`: Threshold validation.

## I/O & External Integration

### `std/io.equis`
Basic file system utilities.
- `io_read_lines(path)`: Safe wrapper to buffer entire files into strings.
- `io_write_atomic(path, content)`: Writes to a temporary `.tmp` file before swapping to prevent corruption.

### `std/db.equis`
PostgreSQL connectivity via LibPQ.
- `db_connect(info)`, `db_query(conn, query)`, `db_get(res, row, col)`, `db_clear(res)`, `db_close(conn)`.

### `std/ffi.equis`
- `ffi_load_library(path)`, `ffi_get_symbol(lib, name)`: Dynamic FFI loading primitives.

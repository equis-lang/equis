# Standard Library Reference

The Equis Standard Library (`std`) provides a foundational set of modules for memory management, data structures, and enterprise economic modeling. This reference covers all implemented functions as of v0.1.0.

## Core Runtime

### `std/sys.equis`
Low-level system interaction and memory management.
- `sys_malloc(size)`: Allocates raw memory from the heap.
- `sys_realloc(p, size)`: Reallocates a heap block to a new size.
- `sys_free(p)`: Frees a heap-allocated block.
- `sys_retain(p)`: Increments reference count on a heap object.
- `sys_release(p)`: Decrements reference count on a heap object.
- `sys_strlen(s)`: Returns the length of a null-terminated string.
- `sys_read_entire_file(path)`: Reads a file into a heap-allocated buffer.
- `sys_rename(old, new)`: Atomic file rename.
- `sys_os()`: Returns 1 (Linux), 2 (Windows), or 3 (macOS).
- `sys_os_name()`: Returns a string identifier for the current OS.
- `sys_path_separator()`: Returns `\\` on Windows, `/` otherwise.
- `sys_get_argc()`, `sys_get_argv(i)`: Command-line argument access.
- `sys_set_agent(id)`, `sys_get_agent()`: Active agent context management.
- `sys_verify_role(role)`: RBAC role verification against the active agent.
- `sys_verify_sig(payload, sig)`: Signature verification primitive.
- `sys_verify_duality()`: REA duality enforcement check.
- `sys_audit_flow(type, amount, res, src, dest)`: Logs a resource flow for audit.
- `sys_reverse_event(p)`: Triggers compensating flows for an event.
- `sys_assert(cond, msg)`, `sys_panic(msg)`: Runtime assertion and panic.
- `write(fd, buf, count)`, `read(fd, buf, count)`: Low-level I/O.
- `open(path, flags, mode)`, `close(fd)`, `lseek(fd, offset, whence)`: File descriptors.
- `exit(code)`: Terminates the process.
- `time(tloc)`: Returns the current system epoch time.
- `printf(fmt, val)`: Formatted output.
- `print_raw(n)`: Prints a 64-bit integer to stdout.
- `print_raw_str(s)`: Prints a null-terminated string to stdout.
- `print_err(s)`: Prints a string to stderr.
- `print_raw_stderr(s)`: Prints a string directly to stderr.
- `print_int_stderr(n)`: Prints a 64-bit integer to stderr.
- `sys_pin(p)`: Pins an object to prevent garbage collection.
- `sys_set_word(p, idx, val)`, `sys_get_word(p, idx)`: Raw memory word access.
- `sys_mkdir(path)`: Creates a directory.

### `std/arena.equis`
Linear bump-pointer allocator for deterministic memory management.
- `arena_new(size)`: Initializes a new memory arena.
- `arena_new_owned(size, owner_id)`: Initializes an arena bound to a specific agent.
- `arena_alloc(arena, size)`: Allocates aligned memory from the specified arena.
- `arena_free_all(arena)`: Resets the arena and releases all associated blocks.

### Fibers and Channels (`std/sys.equis` runtime)
Cooperative and preemptive multitasking (backed by C runtime).
- `sys_chan_new(size)`: Initializes a bounded communication channel.
- `sys_chan_send(chan, val)`: Pushes a value into the channel.
- `sys_chan_recv(chan)`: Pulls a received value from the channel.
- `sys_fiber_preempt_setup(ms)`: Enables signal-based preemption.

### Networking (`std/sys.equis` runtime)
- `sys_socket_create()`: Creates a TCP socket.
- `sys_socket_connect(s, host, port)`: Connects to a remote host.
- `sys_socket_send(s, buf, len)`, `sys_socket_recv(s, buf, len)`: Send/receive data.
- `sys_socket_close(s)`: Closes the socket.

### Database (`std/sys.equis` runtime)
PostgreSQL connectivity via libpq.
- `sys_pgsql_connect(conninfo)`: Opens a database connection.
- `sys_pgsql_exec(conn, query)`: Executes a SQL query.
- `sys_pgsql_get_val(res, row, col)`: Retrieves a result cell.
- `sys_pgsql_clear(res)`: Frees a result set.
- `sys_pgsql_finish(conn)`: Closes a database connection.

## Data Structures

### `std/string.equis`
String manipulation utilities.
- `str_equal(s1, s2)`: Content-based equality check (delegates to `strcmp`).
- `str_starts_with(s, prefix)`: Prefix check.
- `str_len(s)`: Returns string length.
- `str_substring(s, start, len)`: Extracts a substring.
- `str_substring_equal(s, start, len, expected)`: Compares a substring in-place.
- `str_concat(s1, s2)`: Allocates and returns a joined string.
- `str_from_int(n)`: Converts a 64-bit integer to a decimal string.
- `str_to_int(s)`: Parses a decimal string to a 64-bit integer.
- `is_alpha(c)`, `is_digit(c)`: Character class checks.
- `print_str(s)`: Prints a string with `write(1, ...)`.

### `std/intern.equis`
String interning for symbol deduplication.
- `intern_string(s)`: Returns a stable pointer for O(1) identity checks.
- `intern_cleanup()`: Releases the intern table.

### `std/collections.equis`
Heap-allocated vector and hash map.
- `vec_new(cap)`: Creates a new vector with initial capacity.
- `vec_push(v, val)`: Appends a value (returns the potentially-reallocated vector).
- `vec_get(v, idx)`: Returns the element at the given index.
- `vec_set(v, idx, val)`: Overwrites the element at the given index.
- `vec_size(v)`: Returns the number of elements.
- `vec_remove(v, idx)`: Removes an element by index (shifts remaining elements).
- `vec_free(v)`: Releases a vector and its contents.
- `map_new(cap)`: Creates a new hash map.
- `map_put(m, key, val)`: Inserts or updates a key-value pair.
- `map_get(m, key)`: Retrieves a value by key.
- `map_has(m, key)`: Returns 1 if the key exists, 0 otherwise.
- `map_keys(m)`: Returns a vector of all keys.
- `map_remove(m, key)`: Removes a key-value pair.
- `map_hash(key)`: Internal hash function.
- `map_free(m)`: Releases the map.

### `std/json.equis`
JSON serialization and deserialization.
- `json_new()`: Creates a new JSON object (backed by a map).
- `json_put_str(m, k, v)`, `json_put_int(m, k, v)`: Sets a string/integer value.
- `json_put_obj(m, k, v)`, `json_put_array(m, k, v)`: Sets a nested object/array.
- `json_serialize(m)`: Serializes a JSON object to a string.
- `json_parse(s)`: Parses a JSON string into a map structure.
- `json_get_int(m, k)`, `json_get_str(m, k)`: Retrieves typed values.

## Math & Enterprise

### `std/fixed.equis`
Fixed-point arithmetic (scale: 1,000,000).
- `FIXED_SCALE()`: Returns the scale factor (1000000).
- `fixed_new(i, f)`: Creates a fixed-point value from integer and fractional parts.
- `fixed_from_int(n)`: Converts an integer to fixed-point.
- `fixed_from_str(s)`: Parses a decimal string (e.g., `"3.14"`) to fixed-point.
- `fixed_add(a, b)`, `fixed_sub(a, b)`: Addition and subtraction.
- `fixed_mul(a, b)`, `fixed_div(a, b)`: Multiplication and division.
- `fixed_to_str(n)`: Converts a fixed-point value to a decimal string.
- `print_fixed(n)`: Prints a fixed-point value to stdout.

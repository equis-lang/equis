# Equis Language Reference

---

## Formal Specifications
To ensure financial safety and compiler correctness, Equis is formally specified:
- **[Formal EBNF Grammar](docs/grammar.ebnf)**: Complete syntax definition.
- **[Operational Semantics](docs/operational_semantics.md)**: Formal model of REA duality and state transitions.

---

## 1. Core Syntax and Types

Equis supports both dynamic and strong static typing. While variables can be declared loosely with `let`, functions and critical financial logic should use type annotations for compile-time verification. Supported primitive types include `i64` and `f64`.

### Memory Management
Equis uses **Automatic Reference Counting (ARC)** to manage heap memory. The runtime allocator prepends a reference-count header to each allocation. The compiler emits `sys_retain` (increment) and `sys_release` (decrement) calls at assignment, copy, and scope-exit points. When a reference count reaches zero, the object is automatically freed. This eliminates the need for a tracing garbage collector while providing deterministic memory reclamation.

### Variables & Math
Equis uses a fixed-point arithmetic model for all numeric calculations involving decimals to ensure strict determinism. Numeric literals containing a decimal point are automatically scaled by a factor of 1,000,000.

```equis
let tx_amount = 1000;
let mut price = 10.5; // Use `mut` to allow reassignment
price = 11.0;
let total = tx_amount + price;
```

### Pointers & Indexing
Equis supports direct memory manipulation. Arrays and `struct` fields operate natively through pointer indexing, allowing bare-metal array manipulation using standard bracket syntax.
```equis
let bob = sys_malloc(16);
bob[0] = 1001; // Assign ID
bob[1] = 5000; // Assign Salary
```

### Control Flow
Standard control flow structures are supported: `if`, `else`, and `while`.
```equis
if (total > 1000) {
    print 1;
} else {
    print 0;
}

let i = 0;
while (i < 10) {
    i = i + 1;
}
```

### Functions
Functions are declared using `fn` and return values using `return`. They can include optional type annotations.
```equis
fn calculate_tax(amount) {
    return (amount * 10) / 100;
}
```

### Interfaces and Structs
You can define object structures and method signatures.
```equis
struct User {
    id;
    balance;
}

interface Node {
    fn ping(t);
}
```

### External Functions
You can bind functions from external C libraries using `extern fn`.
```equis
extern fn socket(domain, type, protocol);
extern fn sys_malloc(size);
```

---

Equis provides native keywords for economic concepts, reducing the need for accounting boilerplate.

### Agents
An `Agent` represents an entity (person or system). Agents can have specific roles.
```equis
Agent Seller roles { "VENDOR" } {
    id: "S-001";
    status: "active";
}
```

### Resources
A `Resource` is any measured asset, such as inventory or financial units.
```equis
Resource Cash {
    unit: USD;
    decimals: 2;
}
```

### Events & Flows
An `Event` is an atomic resource transfer. It requires a `flow` block to specify the balance of movement.
```equis
Event Purchase evaluated_by MarketRate roles { "ADMIN", "VENDOR" } {
    logic {
        if (tx_amount > 0) { print 123; }
    }
    flow {
        in tx_qty Item from Seller to Buyer;
        out tx_amount Cash from Buyer to Seller;
    }
}
```

### Commitments
A `Commitment` is a promise to perform an Event in the future. Once fulfilled, an Event can explicitly reference it using `fulfills`.
```equis
Commitment Order_01 evaluated_by MarketRate {
    flow {
        out tx_qty Item from Seller to Buyer;
        in tx_amount Cash from Buyer to Seller;
    }
}

Event Delivery fulfills Order_01 evaluated_by MarketRate {
    flow {
        out tx_qty Item from Seller to Buyer;
        in tx_amount Cash from Buyer to Seller;
    }
}
```

### Policies and Valuators
- **Policy**: A reusable set of rules to restrict actions.
- **Valuator**: A block of logic used to determine exchange rates or resource valuations.

Events and Commitments can use `evaluated_by` to enforce a Valuator.
```equis
Policy MaxTransfer {
    logic {
        assert(tx_amount <= 10000); // REA Policy enforcement
    }
}

Valuator MarketRate {
    print 999;
}
```

### Exchange and Transformation
- **Exchange**: Groups multiple events into a single atomic transaction.
- **Transformation**: Consumes inputs to produce outputs (like a manufacturing process).

```equis
exchange Trade {
    Purchase;
    Delivery;
}

transformation Manufacture evaluated_by MarketRate {
    flow {
        in tx_qty Item from Seller to Buyer;
        out tx_qty Item from Buyer to Seller;
    }
}
```

---

## 3. Event Operations

Once REA models are defined, you can interact with them using specific operators.

### Execute
Triggers an event. You can pass runtime arguments (like signatures or IDs) as a map.
```equis
execute Purchase { 
    sig: "Buyer";
    timestamp: "1700000000";
};
```



### Error Handling
Equis provides formalized error handling via `sys_panic` and the `Result` pattern.

```equis
fn divide(a, b) {
    if (b == 0) { sys_panic("Division by zero"); }
    return a / b;
}
```

The `Result` struct (`std/sys.equis`) allows for safe value wrapping:
```equis
struct Result { ok; err; value; }
```

### Assert
Validates conditions inside `logic` blocks. If the condition evaluates to `0` (false), execution halts. 

```equis
assert(tx_amount > 0); // Stops execution if condition is false
```

> [!TIP]
> Use `if (condition) { print 1; }` during development for immediate numeric tracing during execution.

---

## 4. Modules and Standard Library

You can split your code into multiple files. Equis supports exact string paths or scope resolution `::`.
```equis
use "std/sys.equis";
use std::collections; // Automatically resolves to "std/collections.equis"
```

The Equis Standard Library (`std/`) provides tools for memory, data structures, and basic types, since the core language relies entirely on 64-bit integers and pointers:
- **`sys`**: Memory management (`sys_malloc`, `free`), system utilities, and runtime bindings.
- **`arena`**: Arena allocator for deterministic, fragmentation-free memory management.
- **`string`**: Manual string manipulation (`str_concat`, `str_len`, `str_equal`, `print_str`).
- **`intern`**: String interning for optimized symbol processing and comparisons.
- **`collections`**: Dynamic arrays and hash maps (`vec_new`, `map_new`).
- **`fixed`**: High-precision fixed-point arithmetic for financial values.
- **`ledger`**: Temporal, double-entry resource balance tracking and transaction history.
- **`accounting`**: Implementation of core Enterprise Resource Planning (ERP) accounting logic.
- **`compliance`**: Primitives for compliance checks, ESG reporting, and specialized contracts.
- **`db`**: Database connectors for enterprise environments (PostgreSQL via `libpq`).
- **`fiber`**: Foundations for lightweight execution units and concurrency.
- **`ffi`**: Foreign Function Interface utilities for C interoperability.
- **`json`**: JSON parsing and serialization.
- **`http`**: Basic HTTP server capabilities.

---

## 5. Full Code Example

Here is a complete example demonstrating the integration of Agents, Resources, and Events. Save this as `main.equis` and run it via `eq run main.equis`.

```equis
use "std/sys.equis";
use "std/collections.equis";
use "std/string.equis";

// =========================================================================
// EQUIS LANGUAGE EXAMPLE
// =========================================================================

// 1. DATA TYPES AND ABSTRACTION
struct Inventory { item_id; qty; }
interface DigitalAgent { fn ping(timestamp); }

// 2. RESOURCE-EVENT-AGENT (REA) MODELING
// Agents can have specific roles and metadata fields
Agent Buyer roles { "CONSUMER" } { id: "B1"; status: "active"; }
Agent Seller roles { "VENDOR" } { id: "S1"; status: "active"; }

// Resources represent assets with unit definitions
Resource Cash { unit: USD; decimals: 2; }
Resource Item { unit: PCS; }

// Valuators encapsulate pricing or exchange rate logic
Valuator MarketRate {
    print_raw_str("[Valuator] Calculating market rate...\n");
}

// Policies enforce business rules or compliance constraints
Policy RiskLimit {
    logic {
        let max_val = 5000;
        assert(max_val <= 10000); // Standard risk check
    }
}

// Commitments represent promises to execute future events
Commitment Order_01 evaluated_by MarketRate {
    flow {
        out 5 Item from Seller to Buyer;
        in 50 Cash from Buyer to Seller;
    }
}

// Events fulfill commitments and execute specific logic and flows
Event Purchase fulfills Order_01 evaluated_by MarketRate roles { "CONSUMER" } {
    logic {
        assert(1 > 0);
        print_raw_str("[Event] Executing REA Purchase contract...\n");
    }
    flow {
        in 5 Item from Seller to Buyer;
        out 50 Cash from Buyer to Seller;
    }
}

Event Delivery fulfills Order_01 evaluated_by MarketRate roles { "VENDOR" } {
    flow {
        out 5 Item from Seller to Buyer;
        in 50 Cash from Buyer to Seller;
    }
}

// Higher-order economic structures
exchange Trade { Purchase; Delivery; }
transformation Manufacture evaluated_by MarketRate roles { "VENDOR" } {
    flow {
        in 10 Item from Seller to Buyer;
        out 10 Item from Buyer to Seller;
    }
}

// 3. CORE LOGIC WRAPPER
fn run_demos() {
    print_raw_str("--------------------------------------\n");
    print_raw_str("Equis Core Feature Verification\n");
    print_raw_str("--------------------------------------\n\n");

    // Variable and arithmetic operations
    let mut balance = 1000;
    let cost = 500;
    balance = balance - cost;
    
    print_raw_str("System Balance: ");
    print_raw(balance);
    print_raw_str("\n");

    // Dynamic Collections (std/collections)
    let list = vec_new(4);
    vec_push(list, 777);
    print_raw_str("Vector Get(0): ");
    print_raw(vec_get(list, 0));
    print_raw_str("\n\n");

    // REA Operations
    print_raw_str("--- REA Execution Flow ---\n");
    execute Purchase { sig: Buyer; timestamp: "1700000000" };
    
    print_raw_str("--- REA Reverse Flow ---\n");
    reverse Purchase { reason: "Customer Refund" };
    
    print_raw_str("\nEquis core systems verified.\n");
}

// 4. ENTRY POINT
fn main() {
    run_demos();
}

main();
```


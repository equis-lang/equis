# Language Specification

This document details the syntactical structure and behavioral constraints of the Equis systems language v0.1.0.

## 1. Syntax Overview
Equis adopts a C-like syntax utilizing brace-scoped code blocks and strictly terminating statements with semicolons.

### 1.1 Primitives and Variables
The language utilizes `let` bindings for scoped mutable locals. Global and transaction bounds are strictly controlled to ensure deterministic execution.

```equis
let tx_amount = 1000;
let tx_quantity = 2;
```

### 1.2 Fixed-Point Arithmetic
Equis does not implement native floating-point primitives to avoid rounding non-determinism. All decimal values are internally scaled to 64-bit fixed-point integers with a scaling factor of 1,000,000 (allowing 6 decimal digits of precision).

## 2. REA Constructs

### 2.1 Agents
Defines entities capable of participating in transactions. Requires the declaration of `roles` for execution access control.

```equis
Agent Custodian roles { "ADMIN" } { 
    id: "Vault_01"; 
    status: "active"; 
}
```

### 2.2 Resources
Constructs representations of measurable assets. Requires a unit definition.

```equis
Resource Cash { unit: USD; }
```

### 2.3 Events and Flows
Events encapsulate state mutations. Every event requires a `flow` block defining the resource movement between agents.

```equis
Event Settlement evaluated_by MarketRate roles { "ADMIN" } {
    logic {
        assert(tx_amount > 0);
    }
    flow {
        out tx_quantity Item from Seller to Buyer;
        in  tx_amount Cash from Buyer to Seller;
    }
}
```

## 3. Control Flow
Standard deterministic structures are supported:
- `if` / `else` block execution.
- `while` loops for bounded iteration.
- `execute Name { arg: val };` sequence for triggering Events.
- `reverse Name { arg: val };` for initiating compensation transactions.

## 4. Memory Management (ARC)
Equis utilizes an **Automatic Reference Counting (ARC)** model for heap-allocated objects (Agents, Resources, Vectors, etc.). 
- **Ownership**: Every object has an internal reference count initialized to 1 upon allocation.
- **Retention**: Assignment of an object reference to a local variable or global slot triggers a `retain` operation.
- **Release**: When a reference is overwritten or its scope (function/block) exits, a `release` operation is performed.
- **Deallocation**: Objects are deterministically freed when their reference count reaches zero.

## 5. Concurrency (Preemptive Fibers)
High-concurrency logic is managed via **Fibers**—lightweight execution units scheduled by the Equis runtime.
- **Preemption**: The compiler injects yield hooks into all function entry points and loop boundaries.
- **Context Switching**: A kernel timer (`SIGALRM`) triggers the scheduler to preempt the current fiber if it exceeds its time slice (default 50ms).
- **Communication**: Thread-safe channels (`std/chan.equis`) are used for inter-fiber coordination.

## 6. Standard Interfacing
Interaction with external libraries or foreign C ABIs is achieved via `extern fn`. These functions operate at the module level and are constrained by the host environment's security defaults.

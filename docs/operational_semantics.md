# Equis: Formal Operational Semantics

This document provides the formal semantic model for the Equis programming language, focusing on Resource-Event-Agent (REA) duality, Automatic Reference Counting (ARC), and Role-Based Access Control (RBAC).

## 1. Abstract Syntax Notation

Equis programs are defined over a set of agents $A$, resources $R$, and events $E$.
A transaction is a 3-tuple $T = (e, a, r)$ where $e \in E$, $a \in A$, and $r \in R$.

## 2. REA Duality Axioms

### 2.1 The Balance Axiom
For every economic event $E_1$ that results in an outflow of resource $R$ from agent $A$ to agent $B$, there must exist a dual event $E_2$ that results in a correlated inflow of a different resource $R'$ (or the same $R$) back to agent $A$.

$$\forall (E_{out}, A, B, R) \implies \exists (E_{in}, B, A, R')$$

### 2.2 Commitment Fulfillment Semantics
The `fulfills` keyword establishes a trace relationship between a Commitment $C$ and an Event $E$.
Let $\sigma$ be the system state. The transition $\sigma \xrightarrow{execute E} \sigma'$ is valid if and only if:
1. $E$ preserves the flow topology of $C$.
2. All policy constraints $P$ associated with $C$ evaluate to `true` in $\sigma$.

## 3. Memory Model: ARC & Arena

### 3.1 Automatic Reference Counting (ARC)
Every heap-allocated object $O$ maintains a reference count $RC(O)$.
- **Object Creation**: $RC(O) = 1$
- **Retain**: $RC(O) \leftarrow RC(O) + 1$ (occurs on assignment/argument passing)
- **Release**: $RC(O) \leftarrow RC(O) - 1$ (occurs when reference goes out of scope)
- **Zero-Count**: If $RC(O) = 0$, the memory for $O$ is reclaimed.

### 3.2 Arena Allocation
For deterministic real-time accounting, Equis supports sub-heaps called *Arenas*.
An Arena $B$ is a contiguous block of size $N$. Allocation is a simple pointer bump:
$$ptr_{next} = ptr_{base} + \text{offset}$$
Deallocation of the entire Arena occurs in $O(1)$, resetting the bump pointer to $ptr_{base}$.

## 4. Role-Based Access Control (RBAC)

### 4.1 Static Admission
During semantic analysis, the compiler verifies that the agent $A$ participating in event $E$ possesses the required role $k \in Roles(E)$.
$$A \vdash k \in Roles(E) \iff StaticCheck(A, k)$$

### 4.2 Runtime Enforcement
At runtime, the execution engine validates the digital signature $sig$ against the agent's public key and verifies role metadata:
$$EXEC(E, sig) \coloneqq Verify(sig) \wedge CheckRole(Agent(sig), Roles(E))$$

## 5. Temporal Evolution & Ledger

### 5.1 Append-Only Semantics
The ledger $L$ is a sequence of states $(s_0, s_1, \dots, s_n)$.
A new event $E$ produces a new state $s_{n+1}$ by applying the transformation function $\tau$:
$$s_{n+1} = \tau(s_n, E)$$
Crucially, $\tau$ is strictly additive; existing entries in $L$ are immutable.

## 6. Concurrency: Preemptive Fiber Semantics

Equis implements a non-blocking fiber model with preemptive yield points.
Let $\Phi$ be the set of active fibers. The scheduler state is a pair $(\phi_{curr}, Q)$ where $\phi_{curr} \in \Phi$ is the running fiber and $Q$ is the run queue.

### 6.1 Preemptive Yield Hook
The compiler injects a yield check $Y$ at the entry of every function $f$ and back-edge of every loop $w$. 
$$Y \coloneqq \text{if } g\_needs\_yield \text{ then } \text{yield}(\phi_{curr})$$
Where $g\_needs\_yield$ is an atomic flag set by the kernel timer $T$ every $\Delta t$ milliseconds (default 50ms).

### 6.2 Context Transformation
A `yield` operation suspends $\phi_{curr}$, saves its continuation $k$, and invokes the scheduler to pick $\phi_{next} \in Q$:
$$\forall \phi \in \Phi, \text{State}(\phi) \in \{\text{Running, Runnable, Yielded, Finished}\}$$

## 7. Compensation Semantics (Reverse)

The `reverse` operator does not delete $s_k$, but creates a state $s_{n+1}$ that is the functional inverse of $s_k$:
$$s_{n+1} = s_n + (-E)$$
This ensures audit traceability while restoring the resource balance $\Delta R = 0$.

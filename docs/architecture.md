# Architecture Overview

Equis is designed to provide strict, compile-time enforcement of the Resource-Event-Agent (REA) accounting model while maintaining the performance characteristics of a systems programming language.

## 1. Core Model
Equis shifts the correctness burden from runtime dynamic checks to compile-time structural validation. The architecture enforces three distinct tiers:
- **Agents**: Immutable entity definitions holding roles and cryptographically verifiable identifiers.
- **Resources**: State machines defining fractional, quantifiable assets tied strictly to internal fixed-point representations.
- **Events**: The only mechanisms capable of mutating Resource states. Events are strictly typed workflows that execute balanced flows between Agents.

## 2. Compilation Pipeline
The Equis compiler (`eq`) operates as a multi-stage offline AOT (Ahead-of-Time) compiler.

### 2.1 Lexing and Parsing
The front-end compiler, self-hosted in Equis, executes a recursive-descent parser. It generates an Abstract Syntax Tree (AST) optimized for financial domain semantics. High-order structures like `Commitment` and `Policy` are parsed into dedicated AST nodes directly.

### 2.2 Semantic Analysis (REA Validation)
The semantic phase executes duality verification. It ensures that every `flow` defined in an `Event` maintains a balanced input/output ratio according to the predefined `Valuator` or `Policy` parameters. If a flow definition violates the balancing rules, the analyzer rejects the compilation.

### 2.3 LLVM IR Generation
The backend utilizes the LLVM compiler infrastructure. Equis ASTs are mapped to LLVM IR (Intermediate Representation), translating high-level REA semantics into low-level C-ABI compatible functions. Fixed-point arithmetic operations are lowered to raw 64-bit ALU instructions, utilizing a constant scaling factor of 1,000,000 for all fractional resource calculations.

## 3. Memory Model
Equis provides two memory management strategies:
- **Automatic Reference Counting (ARC)**: The runtime uses `calloc`-based allocation with a reference-count header prepended to each object. The compiler emits `sys_retain` and `sys_release` calls at copy, assignment, and scope-exit points to automatically manage object lifetimes without a tracing garbage collector.
- **Arena Allocator** (`std/arena.equis`): A library-level linear bump-pointer allocator available for deterministic, fragmentation-free allocation within bounded scopes such as event processing.

## 4. Self-Hosting Framework
The core Equis compiler resides entirely within `compiler/main.equis` alongside its component tree (`lexer.equis`, `parser.equis`, `codegen.equis`). The toolchain is fully self-bootstrapping and requires no external high-level compilers for production builds.

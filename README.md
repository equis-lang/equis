<p align="center">
  <img src="assets/logo.png" width="150" alt="Equis Logo">
</p>

<h1 align="center">Equis</h1>

<p align="center">
  <strong>A systems programming language for building verifiable accounting systems.</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Release-v0.1.0-blue.svg" alt="Release">
  <img src="https://img.shields.io/badge/License-Apache%202.0-orange.svg" alt="License">
  <img src="https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey.svg" alt="Platform">
</p>

<p align="center">
  <a href="https://github.com/equis-lang/equis/actions/workflows/build.yml">
    <img src="https://github.com/equis-lang/equis/actions/workflows/build.yml/badge.svg" alt="Equis Build Pipeline">
  </a>
  <a href="https://github.com/equis-lang/equis/actions/workflows/ci.yml">
    <img src="https://github.com/equis-lang/equis/actions/workflows/ci.yml/badge.svg" alt="Equis CI">
  </a>
  <a href="https://github.com/equis-lang/equis/actions/workflows/docs.yml">
    <img src="https://github.com/equis-lang/equis/actions/workflows/docs.yml/badge.svg" alt="Deploy Docs">
  </a>
</p>

---

Equis is a self-hosted, domain-specific systems language for economic and accounting software. It integrates the Resource-Event-Agent (REA) accounting model into its core semantics, providing automated verification for balanced transactions.

### Why Equis?

| Feature | Description |
|---|---|
| **REA Duality** | Mandatory runtime balance verification for all economic events |
| **RBAC Enforcement** | Role-based access control enforced at agent execution entry points |
| **Immutable Audit Trail** | Append-only JSON ledger (`ledger.ev`) for tamper-proof transaction history |
| **Transactional Reversal** | Automated compensating flows for event-level rollback |
| **ARC Memory Model** | Deterministic memory safety with no garbage collection pauses |
| **Preemptive Fibers** | Timer-based multitasking for low-latency concurrent accounting |
| **Self-Hosted Compiler** | Industry-grade compiler written entirely in Equis |
| **LLVM Backend** | High-performance machine code generation |

## Project Structure

```text
equis/
├── assets/
│   ├── logo.png
│   └── logo.svg
├── compiler/
│   ├── analyzer.equis          # Symbol table & scope management
│   ├── borrow_checker.equis    # Ownership & lifetime analysis
│   ├── codegen.equis           # LLVM IR code generation (ARC & Preempt injection)
│   ├── constants.equis         # AST node & token index definitions
│   ├── lexer.equis             # Tokenizer
│   ├── lsp.equis               # Language Server Protocol handler
│   ├── main.equis              # Compiler entry point
│   ├── parser.equis            # Recursive descent parser
│   ├── runtime.c               # C runtime (ARC, Signals, Multitasking Support)
│   └── semantics.equis         # Semantic analysis & REA enforcement
├── docs/
│   ├── architecture.md         # Compiler pipeline design
│   ├── benchmarks.md           # Performance measurements
│   ├── grammar.ebnf            # Formal EBNF grammar
│   ├── grammar.md              # Human-readable grammar guide
│   ├── integration_guide.md    # CLI setup & global installation
│   ├── operational_semantics.md# Formal duality & ARC proofs
│   ├── specification.md        # Language specification
│   └── stdlib_reference.md     # Standard library API reference
├── examples/
│   ├── benchmarks/
│   │   └── speed_test.equis
│   └── main.equis              # Full REA demonstration program
├── scripts/
│   └── verify_ddc.sh           # Diverse Double-Compilation verifier
├── std/
│   ├── accounting.equis        # ERP accounting logic
│   ├── arena.equis             # Arena allocator
│   ├── chan.equis               # Thread-safe channels
│   ├── collections.equis       # Vectors & hash maps
│   ├── compliance.equis        # ESG & regulatory checks
│   ├── db.equis                # PostgreSQL connector (libpq)
│   ├── dual_net.equis          # Distributed duality verification
│   ├── ffi.equis               # Foreign function interface
│   ├── fiber.equis             # Preemptive fiber scheduler
│   ├── fixed.equis             # Fixed-point arithmetic
│   ├── http.equis              # HTTP server
│   ├── intern.equis            # String interning
│   ├── io.equis                # File I/O utilities
│   ├── json.equis              # JSON parser & serializer
│   ├── ledger.equis            # Double-entry ledger
│   ├── net.equis               # Socket networking
│   ├── record.equis            # Record utilities
│   ├── rpc.equis               # Remote procedure calls
│   ├── string.equis            # String manipulation
│   └── sys.equis               # System primitives & runtime bindings
├── .github/
│   └── workflows/
│       ├── build.yml           # Release build pipeline
│       ├── ci.yml              # Continuous integration
│       └── docs.yml            # Documentation deployment
├── bootstrap.c                 # ANSI C bootstrap compiler
├── Makefile                    # Linux/macOS build system
├── bootstrap.ps1               # Windows bootstrap script
├── eq                          # Linux/macOS runner script
├── eq.ps1                      # PowerShell runner script
├── eq.bat                      # Windows batch runner shim
├── epm                         # Package manager (Linux/macOS)
├── epm.ps1                     # PowerShell package manager
├── epm.bat                     # Windows package manager shim
├── install.sh                  # Linux/macOS installer
├── install.ps1                 # Windows installer
├── EQUIS.md                    # Programmer's language reference
├── CHANGELOG.md                # Release history
├── LICENSE                     # Apache 2.0
└── NOTICE
```

## Language Primitives

Equis incorporates accounting semantics directly into the language design:

```equis
// Define transacting entities with role-based access
Agent Buyer roles { "CONSUMER" } { id: "B1"; status: "active"; }
Agent Seller roles { "VENDOR" } { id: "S1"; status: "active"; }

// Define trackable assets
Resource Cash { unit: USD; decimals: 2; }
Resource Item { unit: PCS; }

// Binding promise for future execution
Commitment Order_01 evaluated_by MarketRate {
    flow {
        out 5 Item from Seller to Buyer;
        in 50 Cash from Buyer to Seller;
    }
}

// Atomic state transition with balanced flows
Event Purchase fulfills Order_01 roles { "CONSUMER" } {
    logic { assert(1 > 0); }
    flow {
        in 5 Item from Seller to Buyer;
        out 50 Cash from Buyer to Seller;
    }
}
```

### Systems Programming

Beyond REA, Equis supports full systems-level programming:

- **Pointers & Mutability** — Explicit `mut` constraints and raw pointer indexing
- **Concurrency** — Thread-safe channels (`chan_send`, `chan_recv`) and checkpoint-based preemptive fibers
- **Networking** — Sockets support for distributed duality verification
- **Database** — PostgreSQL connectivity via `libpq`
- **Atomic I/O** — File operations with crash-safe semantics

## Quick Start

### Install

- **Linux/macOS**:
  ```bash
  curl -fsSL https://raw.githubusercontent.com/equis-lang/equis/main/install.sh | bash
  ```
- **Windows**:
  ```powershell
  irm https://raw.githubusercontent.com/equis-lang/equis/main/install.ps1 | iex
  ```

### Build from Source

#### Linux / macOS
```bash
git clone https://github.com/equis-lang/equis.git
cd equis
make && sudo make install
```

#### Windows (PowerShell)
```powershell
git clone https://github.com/equis-lang/equis.git
cd equis
.\bootstrap.ps1
```

#### Manual Bootstrap
The compiler requires only a C compiler (GCC/Clang), Make, and LLVM/Clang.
```bash
make bootstrap   # Build the compiler from the C bootstrap
make clean       # Clean build artifacts
sudo make install
```

### Run a Program
```bash
eq run examples/main.equis
```

## Documentation

| Document | Description |
|---|---|
| [Programmer's Guide](EQUIS.md) | Complete language tutorial and reference |
| [Language Specification](docs/specification.md) | Formal semantics and logic rules |
| [Grammar (EBNF)](docs/grammar.md) | Formal language syntax specification |
| [Operational Semantics](docs/operational_semantics.md) | Proof sketches for duality and ARC |
| [Architecture](docs/architecture.md) | Compiler pipeline and IR design |
| [Standard Library](docs/stdlib_reference.md) | Full stdlib API reference |
| [Integration Guide](docs/integration_guide.md) | Global CLI setup |

## Ecosystem

| Tool | Description |
|---|---|
| [VS Code Extension](https://github.com/equis-lang/vscode-equis) | Syntax highlighting, LSP, and file icons |
| [Package Manager (`epm`)](epm) | Dependency management for Equis projects |

## License
Copyright (c) 2026 [mlintangmz](https://github.com/equis-lang)  
Licensed under the [Apache License 2.0](LICENSE).

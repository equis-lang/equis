# Changelog

All notable changes to the Equis programming language will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.1.0] - 2026-03-26

### Added
- Self-hosted compiler written in Equis.
- REA (Resource-Event-Agent) model primitives embedded in the core language.
- Static and runtime duality verification for economic transactions.
- Role-Based Access Control (RBAC) enforced at compile-time and runtime.
- High-precision 64-bit fixed-point arithmetic for financial determinism.
- Automatic Reference Counting (ARC) with deterministic Arena memory model.
- LLVM backend for native-speed execution.
- Cross-platform support (Linux, macOS, and experimental Windows support).
- Built-in Language Server Protocol (LSP) support.
- Standard Library with 20 starting modules including networking and ledge compliance.
- Experimental Windows support via IR post-processing.

### Security
- Blocked unsafe system calls (`system`, `execv`, `popen`, `fork`) at the analyzer level.
- Mandatory digital signature (`sig`) for event execution.
- Role isolation for economic events.

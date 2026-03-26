# Contributing to Equis

First off, thanks for taking the time to contribute. Equis is a systems language focused on strict REA enforcement and fixed-point correctness, so we value precision and test coverage highly.

The following is a set of guidelines for contributing to Equis and its packages. These are mostly guidelines, not strict rules. Use your best judgment, and feel free to propose changes to this document in a pull request.

## How Can I Contribute?

### Reporting Bugs
Bugs are tracked as GitHub issues. When creating an issue, please provide the following information to help maintainers locally reproduce the problem:
- **Equis Version**: (e.g., v0.1.0 or the specific git hash)
- **OS Platform**: (e.g., Ubuntu 22.04, Windows 11)
- **Steps to Reproduce**: Provide a minimal `.equis` script that isolates the compiler crash or semantic failure.
- **Expected Behavior**: What you expected to happen.
- **Actual Behavior**: Include compiler traces, LLVM IR dumps, or segmentation fault backtraces if applicable.

### Suggesting Enhancements
Enhancement suggestions are also tracked as GitHub issues. Please structure your feature request with:
1. A clear code example of the proposed syntax or standard library function.
2. A brief justification of why the REA model or compiler architecture benefits from this feature.
3. Any potential regressions it might introduce to existing fixed-point or flow validations.

### Pull Requests
For code contributions:
1. **Fork the repo** and create your branch from `master`.
2. **Adhere to the Architecture**: The compiler is self-hosted in Equis (`compiler/*.equis`) with a minimal C runtime layer. If touching compiler sources, ensure all changes maintain the self-hosting bootstrap chain. Test by running `make eq-core` to verify the compiler can still compile itself.
3. **Documentation**: Update the `docs/` Markdown files if you are changing language semantics, standard library APIs, or integration methods.
4. **Commit Messages**: Use conventional commits (e.g., `fix(parser): resolve unexpected ternary tokenization`).

## Development Setup

The Equis compiler is self-hosted and bootstrap-anchored. No external runtimes are required — only a C compiler (GCC/Clang), Make, and LLVM.

To build the toolchain from source:
```bash
make clean
make bootstrap
```

To run the example:
```bash
./eq run examples/main.equis
```

## Review Process
Maintainers review pull requests on a rolling basis. You will typically receive initial feedback within 48 hours. If architectural changes are proposed, the PR may be deferred until a design RFC is approved.

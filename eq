#!/bin/bash

set -euo pipefail

function get_real_path() {
    local target="$1"
    if command -v readlink >/dev/null 2>&1; then
        local res=$(readlink -f "$target" 2>/dev/null)
        if [ $? -eq 0 ] && [ -n "$res" ]; then
            echo "$res"
            return
        fi
        while [ -L "$target" ]; do
            local link=$(readlink "$target")
            if expr "$link" : '/.*' > /dev/null; then
                target="$link"
            else
                target="$(dirname "$target")/$link"
            fi
        done
        echo "$(cd "$(dirname "$target")" && pwd)/$(basename "$target")"
    else
        echo "$target"
    fi
}

REAL_PATH=$(get_real_path "$0")
EQUIS_BIN_DIR=$(dirname "$REAL_PATH")

if [[ "$(basename "$EQUIS_BIN_DIR")" == "bin" ]]; then
    EQUIS_HOME=$(dirname "$EQUIS_BIN_DIR")
    EQUIS_LIB="$EQUIS_HOME/lib"
    EQUIS_CORE="$EQUIS_LIB/eq-core"
    RUNTIME_C="$EQUIS_LIB/runtime.c"
else
    EQUIS_HOME="$EQUIS_BIN_DIR"
    EQUIS_CORE="$EQUIS_HOME/eq-core"
    EQUIS_LIB="$EQUIS_HOME"
    RUNTIME_C="$EQUIS_HOME/compiler/runtime.c"
fi

EQUIS_STD="$EQUIS_LIB"
if [ ! -d "$EQUIS_STD/std" ] && [ -d "$EQUIS_HOME/std" ]; then
    EQUIS_STD="$EQUIS_HOME"
fi

function show_help() {
    cat << EOF
Equis CLI v0.1.0 - Systems programming for verifiable accounting.

USAGE:
    eq <COMMAND> [OPTIONS] [FILE]

COMMANDS:
    compile     Generate optimized native binary
    run         Compile and execute immediately
    check       Perform semantic analysis only
    lsp         Launch Language Server Protocol
    build       Bootstrap local compiler core
    clean       Remove build artifacts from current directory
    version     Display toolchain version
    help        Show this help message

OPTIONS:
    -I <path>   Add path to search for standard library / modules
    -o <file>   Specify the output binary name (for 'compile')
    -v, --verbose Enable verbose output filtering

EXAMPLES:
    eq run main.equis
    eq compile examples/main.equis -o my_app
    eq compile -I ./lib app.equis
EOF
}

if [ $# -lt 1 ]; then
    show_help
    exit 0
fi

CMD=$1
shift

case $CMD in
    compile)
        FILE=""
        OUTPUT=""
        OTHER_ARGS=""
        VERBOSE=0
        while [[ $# -gt 0 ]]; do
            case $1 in
                -I) OTHER_ARGS="$OTHER_ARGS -I $2"; shift 2 ;;
                -o) OUTPUT="$2"; shift 2 ;;
                -v|--verbose) VERBOSE=1; shift ;;
                *.equis) FILE="$1"; shift ;;
                help|--help|-h) show_help; exit 0 ;;
                *) OTHER_ARGS="$OTHER_ARGS $1"; shift ;;
            esac
        done
        if [ -z "$FILE" ]; then 
            echo "[eq] Error: No .equis source file specified."
            exit 1
        fi
        if [ -z "$OUTPUT" ]; then
            OUTPUT=$(basename "$FILE" .equis)
        fi
        TLL=$(mktemp /tmp/eq_XXXXXX.ll)
        INCLUDE_ARGS="-I $EQUIS_STD"
        if [ "$VERBOSE" -eq 1 ]; then
            echo "[eq] Compiling: $FILE"
            echo "[eq] Core: $EQUIS_CORE $INCLUDE_ARGS $OTHER_ARGS"
        fi
        $EQUIS_CORE $INCLUDE_ARGS $OTHER_ARGS "$FILE" > "$TLL"
        clang -O3 "$TLL" "$RUNTIME_C" -o "$OUTPUT" -Wno-override-init -lm -lpthread
        rm "$TLL"
        if [ "$VERBOSE" -eq 1 ]; then
            echo "[eq] Output: ./$OUTPUT"
        fi
        ;;
    run)
        FILE=""
        for arg in "$@"; do
            if [[ "$arg" == *.equis ]]; then
                FILE="$arg"
                break
            fi
        done
        if [ -z "$FILE" ]; then
            echo "Error: No .equis source file specified."
            exit 1
        fi
        TEMP_EXE=$(mktemp /tmp/eq_bin_XXXXXX)
        echo "[eq] Compiling temporary binary..."
        $0 compile "$@" -o "$TEMP_EXE"
        "$TEMP_EXE"
        rm "$TEMP_EXE"
        ;;
    build)
        if [ ! -f "$EQUIS_HOME/Makefile" ]; then
            echo "Error: Makefile not found in $EQUIS_HOME. Cannot rebuild toolchain."
            exit 1
        fi
        echo "[eq] Rebuilding toolchain..."
        (cd "$EQUIS_HOME" && make clean install)
        ;;
    lsp)
        $EQUIS_CORE -I "$EQUIS_STD" --lsp
        ;;
    check)
        if [ $# -lt 1 ]; then
            echo "Usage: eq check <file.equis>"
            exit 1
        fi
        $EQUIS_CORE -I "$EQUIS_STD" --check "$1"
        ;;
    clean)
        rm -f *.ll *.o core 2>/dev/null || true
        find . -maxdepth 1 -type f -executable -not -name "eq" -not -name "epm" -exec rm -f {} +
        echo "[eq] Workspace cleaned."
        ;;
    version)
        echo "Equis Professional Toolchain v0.1.0 (Linux-Native)"
        echo "Semantic Engine: REA-Duality-v1 (Stable)"
        ;;
    help|--help|-h)
        show_help
        ;;
    *)
        if [ -f "$CMD" ]; then
             $EQUIS_CORE -I "$EQUIS_STD" "$CMD" "$@"
        else
            echo "Error: Unknown command '$CMD'. See 'eq help'."
            exit 1
        fi
        ;;
esac

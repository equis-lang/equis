#!/bin/bash




get_real_path() {
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

if [[ "$*" != *"-I"* ]]; then
    INCLUDE_ARGS="-I $EQUIS_STD"
fi

CMD=$1
shift

case $CMD in
    compile)

        FILE=""
        OTHER_ARGS=""
        while [[ $# -gt 0 ]]; do
            case $1 in
                -I)
                    OTHER_ARGS="$OTHER_ARGS -I $2"
                    shift 2
                    ;;
                -*)
                    OTHER_ARGS="$OTHER_ARGS $1"
                    shift
                    ;;
                *.equis)
                    FILE="$1"
                    shift
                    ;;
                *)
                    OTHER_ARGS="$OTHER_ARGS $1"
                    shift
                    ;;
            esac
        done

        if [ -z "$FILE" ]; then echo "Usage: eq compile <file.equis> [-I path]"; exit 1; fi
        BASENAME=$(basename "$FILE" .equis)
        echo "Executing: $EQUIS_CORE $INCLUDE_ARGS $OTHER_ARGS $FILE"
        $EQUIS_CORE $INCLUDE_ARGS $OTHER_ARGS "$FILE" > "$BASENAME.ll"
        if [ $? -ne 0 ]; then exit 1; fi
        clang -O3 "$BASENAME.ll" "$RUNTIME_C" -o "$BASENAME" -Wno-override-tunit -lm -lpthread
        if [ $? -ne 0 ]; then exit 1; fi
        rm "$BASENAME.ll"
        echo "Compiled: ./$BASENAME"
        ;;
    run)

        FILE=""
        for arg in "$@"; do
            if [[ "$arg" == *.equis ]]; then
                FILE="$arg"
            fi
        done
        
        $0 compile "$@"
        if [ $? -ne 0 ]; then exit 1; fi
        
        if [ -n "$FILE" ]; then
            EXE="./$(basename "$FILE" .equis)"
            "$EXE"
        fi
        ;;
    build)
        echo "Rebuilding Toolchain..."
        if [ -f "Makefile" ]; then
            make clean install
        else
            echo "Error: Makefile not found in current directory. Cannot rebuild toolchain from here."
            exit 1
        fi
        ;;
    lsp)
        echo "Starting Equis Language Server..." >&2
        $EQUIS_CORE $INCLUDE_ARGS --lsp
        ;;
    version)
        echo "Equis v0.1.0 (C-Anchor)"
        ;;
    *)
        if [ -n "$CMD" ] && [ -f "$CMD" ]; then
             $EQUIS_CORE $INCLUDE_ARGS "$CMD" "$@"
        else
            echo "Usage: eq [compile|run|build|version] <file.equis>"
        fi
        ;;
esac

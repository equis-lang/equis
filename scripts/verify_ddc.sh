#!/bin/bash
# =============================================================================
# Equis Compiler - Diverse Double-Compilation (DDC) Verification
# -----------------------------------------------------------------------------
# This script verifies the integrity of the Equis compiler against the
# "Trusting Trust" attack vector using Diverse Double-Compilation.
# =============================================================================

set -e

echo "--- Starting DDC Verification ---"

# 1. Build Stage 1 (C-based Bootstrap)
echo "Building Stage 1 (C-based bootstrap)..."
gcc -O3 bootstrap.c -lpthread -o eq-stage1

# 2. Stage 1 -> Stage 2 (LLVM IR)
echo "Generating Stage 2 IR using Stage 1..."
./eq-stage1 -I std compiler/main.equis > stage2.ll

# 3. Stage 2 (LLVM IR) -> Stage 2 (Binary)
echo "Building Stage 2 binary..."
clang -O3 -Wno-override-module stage2.ll compiler/runtime.c -lpthread -o eq-stage2

# 4. Stage 2 -> Stage 3 (LLVM IR)
echo "Generating Stage 3 IR using Stage 2..."
./eq-stage2 -I std compiler/main.equis > stage3.ll

# 5. Stage 3 (LLVM IR) -> Stage 3 (Binary)
echo "Building Stage 3 binary..."
clang -O3 -Wno-override-module stage3.ll compiler/runtime.c -lpthread -o eq-stage2-v2 -o eq-stage3

# 6. Stage 3 -> Stage 4 (LLVM IR)
echo "Generating Stage 4 IR using Stage 3..."
./eq-stage3 -I std compiler/main.equis > stage4.ll

# 7. Comparison: Stage 3 vs Stage 4 (Convergence)
echo "Checking for Convergence (Stage 3 vs Stage 4)..."
if diff stage3.ll stage4.ll > /dev/null; then
    echo "[PASS] Convergence Achieved (Bit-Identical Stage 3 and Stage 4)"
else
    echo "[FAIL] Convergence Failed. IR mismatch between Stage 3 and Stage 4."
    exit 1
fi

# 8. Diverse Source Comparison: Stage 1 output vs Stage 2 output
# Note: Since Stage 1 is C-based and Stage 2 is Equis-based, they are "Diverse".
echo "Checking for Diverse Identity (Stage 2 IR vs Stage 3 IR)..."
if diff stage2.ll stage3.ll > /dev/null; then
    echo "[PASS] Diverse Double-Compilation Verified!"
    echo "       The self-hosted compiler agrees bit-for-bit with the bootstrap compiler."
    echo "       No 'Trusting Trust' poisoning detected."
else
    echo "[FAIL] Diverse Identity Failed. IR mismatch between Stage 2 and Stage 3."
    echo "       This may indicate semantic differences or potential poisoning."
    exit 1
fi

echo "--- DDC Verification Successful ---"

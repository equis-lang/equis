#!/bin/bash

set -e

echo "[INFO] Starting Diverse Double-Compilation (DDC) Verification..."

echo "[INFO] Building Stage 1 (C-based bootstrap)..."
gcc -O3 bootstrap.c -lpthread -o eq-stage1

echo "[INFO] Generating Stage 2 IR using Stage 1..."
./eq-stage1 -I std compiler/main.equis > stage2.ll

echo "[INFO] Building Stage 2 binary..."
clang -O3 -Wno-override-module stage2.ll compiler/runtime.c -lpthread -o eq-stage2-bin

echo "[INFO] Generating Stage 3 IR using Stage 2..."
./eq-stage2-bin -I std compiler/main.equis > stage3.ll

echo "[INFO] Building Stage 3 binary..."
clang -O3 -Wno-override-module stage3.ll compiler/runtime.c -lpthread -o eq-stage3

echo "[INFO] Generating Stage 4 IR using Stage 3..."
./eq-stage3 -I std compiler/main.equis > stage4.ll

echo "[INFO] Verifying Convergence (Stage 3 vs Stage 4)..."
if diff stage3.ll stage4.ll > /dev/null; then
    echo "[SUCCESS] Convergence Achieved: Bit-identical compiler output verified."
else
    echo "[ERROR] Convergence Failed: IR mismatch detected between generations."
    exit 1
fi

echo "[INFO] Verifying Diverse Identity (Stage 2 IR vs Stage 3 IR)..."
if diff stage2.ll stage3.ll > /dev/null; then
    echo "[SUCCESS] Diverse Identity Verified: Self-hosted compiler matches bootstrap logic."
else
    echo "[ERROR] Mismatch Detected: Self-hosted compiler logic diverges from bootstrap."
    exit 1
fi

echo "[SUCCESS] DDC Verification Complete: Toolchain trust established."
rm stage2.ll stage3.ll stage4.ll eq-stage1 eq-stage2-bin eq-stage3

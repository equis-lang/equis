#!/bin/bash


BOLD="\033[1m"
BLUE="\033[1;34m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
CYAN="\033[1;36m"
NC="\033[0m"

set -e

echo -e "${CYAN}${BOLD}--------------------------------------------------${NC}"
echo -e "${CYAN}${BOLD}   Equis Core Installer (v0.1.0)${NC}"
echo -e "${CYAN}${BOLD}--------------------------------------------------${NC}"

install_linux_deps() {
    echo -e "${BLUE}${BOLD}info${NC}: detecting package manager..."
    if command -v apt-get &> /dev/null; then
        echo -e "${BLUE}${BOLD}info${NC}: Debian/Ubuntu detected. Installing LLVM, Clang, and Make..."
        sudo apt-get update -qq
        sudo apt-get install -y -qq llvm clang make
    elif command -v dnf &> /dev/null; then
        echo -e "${BLUE}${BOLD}info${NC}: Fedora detected. Installing LLVM, Clang, and Make..."
        sudo dnf install -y llvm clang make
    elif command -v pacman &> /dev/null; then
        echo -e "${BLUE}${BOLD}info${NC}: Arch Linux detected. Installing LLVM, Clang, and Make..."
        sudo pacman -S --noconfirm llvm clang make
    else
        echo -e "${RED}${BOLD}error${NC}: unsupported Linux distribution. Please install LLVM, Clang, and Make manually."
        exit 1
    fi
}

echo -e "${YELLOW}${BOLD}[1/3]${NC} resolving dependencies..."

MISSING_DEPS=0
if ! command -v clang &> /dev/null; then MISSING_DEPS=1; fi
if ! command -v make &> /dev/null; then MISSING_DEPS=1; fi

if [ $MISSING_DEPS -eq 1 ]; then
    echo -e "${BLUE}${BOLD}info${NC}: missing dependencies found. Attempting automatic installation..."
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        install_linux_deps
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo -e "${BLUE}${BOLD}info${NC}: macOS detected. Checking for Xcode Command Line Tools..."
        if ! command -v brew &> /dev/null; then
            echo -e "${BLUE}${BOLD}info${NC}: homebrew not found. Installing Xcode tools..."
            xcode-select --install || true
        else
            brew install llvm make
        fi
    else
        echo -e "${RED}${BOLD}error${NC}: unknown OS. Please install LLVM, Clang, and Make manually."
        exit 1
    fi
else
    echo -e "${GREEN}${BOLD}success${NC}: all dependencies (LLVM, Clang, Make) are present."
fi

echo -e "${YELLOW}${BOLD}[2/3]${NC} bootstrapping Equis compiler..."
mkdir -p compiler

echo -e "${BLUE}${BOLD}info${NC}: lowering compiler core from LLVM IR..."
clang -O3 -o compiler/main compiler/main.ll -Wno-override-tunit || clang -O3 -o compiler/main compiler/main.ll

if [ ! -f "compiler/main" ]; then
    echo -e "${RED}${BOLD}error${NC}: bootstrap failed. verify clang/llvm installation."
    exit 1
fi
chmod +x eq
echo -ne "${GREEN}${BOLD}success${NC}: core established. "
./eq version

echo -e "${YELLOW}${BOLD}[3/3]${NC} finalizing system installation..."
PREFIX=${PREFIX:-/usr/local}

if [ -w "$PREFIX/bin" ]; then
    make install PREFIX=$PREFIX
else
    echo -e "${BLUE}${BOLD}info${NC}: requires elevate permissions for $PREFIX/bin"
    sudo make install PREFIX=$PREFIX
fi

echo -e "${CYAN}${BOLD}--------------------------------------------------${NC}"
echo -e "${GREEN}${BOLD}SUCCESS:${NC} Equis v0.1.0 installed successfully."
echo -e "You can now use the '${BOLD}eq${NC}' command globally."
echo -e "Try it: '${YELLOW}eq run examples/main.equis${NC}'"
echo -e "${CYAN}${BOLD}--------------------------------------------------${NC}"

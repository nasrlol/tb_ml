#!/bin/bash

set -e

BIN="build/tb_ml"
SRC="source/tb_ml/tb_ml.c"
CC="${CC:-gcc}"
CFLAGS="-Wall -Wextra -Wpedantic -Wno-attributes -fno-omit-frame-pointer -Wno-unused-variable -Wno-unused-function -fno-asynchronous-unwind-tables -ftime-report -O0 --std=c99 -g"
LDFLAGS="-lm"

usage() {
    cat <<EOF
Usage: $0 [command]

Commands:
    build       Build the project (default)
    run         Build and run
    clean       Clean build artifacts
    help        Show this message
EOF
    exit 0
}

build() {
    echo "[*] Building $BIN..."
    mkdir -p "$(dirname "$BIN")"
    $CC $CFLAGS "$SRC" -o "$BIN" $LDFLAGS
    echo "[+] Build complete: $BIN"
}

run() {
    build
    echo "[*] Running $BIN..."
    ./"$BIN"
}

clean() {
    echo "[*] Cleaning..."
    rm -rf build
    echo "[+] Clean complete"
}

cmd="${1:-build}"

case "$cmd" in
    build) build ;;
    run) run ;;
    clean) clean ;;
    help) usage ;;
    *) echo "Unknown command: $cmd"; usage ;;
esac

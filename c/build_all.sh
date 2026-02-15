#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
OUT_DIR="${1:-/tmp/cbuild}"
mkdir -p "$OUT_DIR"

while IFS= read -r file; do
  out="$OUT_DIR/$(echo "$file" | tr '/' '_')"
  gcc -std=c11 "$ROOT_DIR/$file" -o "$out"
done < <(cd "$ROOT_DIR" && rg --files c -g '*.c' | sort)

echo "compiled all C examples -> $OUT_DIR"

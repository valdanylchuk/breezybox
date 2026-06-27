#!/bin/sh
# Build a loadable ELF for the ESP32-P4 (RISC-V) BreezyBox elf_loader.
#
#   Usage: ./buildelf_rv32.sh <source.c> [extra gcc args...]
#   Output: dist/<name>.rv32.elf  (stripped, ready to release)
#
# Set LINK_LIBGCC=1 to statically link libgcc (soft-float / 64-bit / long
# divide helpers). Off by default: most apps get those symbols resolved from
# the firmware's elf_loader symbol table at load time.
set -e

SRC=${1:?usage: buildelf_rv32.sh <source.c> [extra gcc args...]}
shift
NAME=$(basename "${SRC%.c}")

TC="$HOME/.espressif/tools/riscv32-esp-elf/esp-14.2.0_20241119/riscv32-esp-elf/bin"
GCC="$TC/riscv32-esp-elf-gcc"
STRIP="$TC/riscv32-esp-elf-strip"
NM="$TC/riscv32-esp-elf-nm"

# Match the P4 firmware ABI (rv32imafc, hard-float ilp32f).
MARCH=rv32imafc_zicsr_zifencei
MABI=ilp32f

LIBGCC=
[ "$LINK_LIBGCC" = 1 ] && LIBGCC=$("$GCC" -march=$MARCH -mabi=$MABI -print-libgcc-file-name)

DIST="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)/dist"
mkdir -p "$DIST"
OUT="$DIST/$NAME.rv32.elf"

"$GCC" \
  -march=$MARCH -mabi=$MABI \
  -O2 \
  -Dmain=app_main \
  -nostartfiles -nostdlib \
  -fPIC -shared \
  -fvisibility=hidden \
  -Wl,-e,app_main \
  -Wl,--gc-sections \
  "$@" "$SRC" $LIBGCC -o "$OUT"

"$STRIP" --strip-all "$OUT"

echo "built $OUT"
echo "Potential required exports:"
"$NM" -D -u "$OUT"

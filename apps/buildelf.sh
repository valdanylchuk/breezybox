#!/bin/sh
# Build a loadable ELF for the ESP32-S3 (Xtensa) BreezyBox elf_loader.
#
#   Usage: ./buildelf.sh <source.c> [extra gcc args...]
#   Output: dist/<name>.xtensa.elf  (stripped, ready to release)
#
# Set LINK_LIBGCC=1 to statically link libgcc (soft-float / 64-bit / long
# divide helpers). Off by default: most apps get those symbols resolved from
# the firmware's elf_loader symbol table at load time.
set -e

SRC=${1:?usage: buildelf.sh <source.c> [extra gcc args...]}
shift
NAME=$(basename "${SRC%.c}")

TC="$HOME/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin"
GCC="$TC/xtensa-esp32s3-elf-gcc"
STRIP="$TC/xtensa-esp32s3-elf-strip"
NM="$TC/xtensa-esp32s3-elf-nm"

LIBGCC=
[ "$LINK_LIBGCC" = 1 ] && LIBGCC="$HOME/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/lib/gcc/xtensa-esp-elf/14.2.0/esp32s3/libgcc.a"

DIST="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)/dist"
mkdir -p "$DIST"
OUT="$DIST/$NAME.xtensa.elf"

"$GCC" \
  -O2 \
  -Dmain=app_main \
  -nostartfiles -nostdlib \
  -fPIC -shared \
  -fvisibility=hidden \
  -Wl,-e,app_main \
  -Wl,--gc-sections \
  "$@" "$SRC" $LIBGCC -o "$OUT"

"$STRIP" --strip-all --remove-section=.xt.prop "$OUT"

echo "built $OUT"
echo "Potential required exports:"
"$NM" -D -u "$OUT"

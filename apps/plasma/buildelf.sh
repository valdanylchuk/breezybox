#!/bin/sh

# ESP32-S3 libgcc path
LIBGCC="$HOME/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/lib/gcc/xtensa-esp-elf/14.2.0/esp32s3/libgcc.a"

xtensa-esp32s3-elf-gcc \
  -O2 \
  -I local_include \
  -Dmain=app_main \
  -nostartfiles -nostdlib \
  -fPIC -shared \
  -fvisibility=hidden \
  -Wl,-e,app_main \
  -Wl,--gc-sections \
  plasma.c "$LIBGCC" -o plasma.elf

xtensa-esp32s3-elf-strip --strip-all --remove-section=.xt.prop -o plasma-stripped.elf plasma.elf
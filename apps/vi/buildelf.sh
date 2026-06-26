#!/bin/sh

xtensa-esp32s3-elf-gcc \
  -O2 \
  -Dmain=app_main \
  -nostartfiles -nostdlib \
  -fPIC -shared \
  -fvisibility=hidden \
  -Wl,-e,app_main \
  -Wl,--gc-sections \
  vi.c -o vi.elf

xtensa-esp32s3-elf-strip --strip-all --remove-section=.xt.prop -o vi-stripped.elf vi.elf

echo "Potential required exports:"
xtensa-esp32s3-elf-nm -u vi.elf

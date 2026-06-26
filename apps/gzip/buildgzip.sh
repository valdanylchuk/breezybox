#!/bin/sh

xtensa-esp32s3-elf-gcc \
  -O2 \
  -Dmain=app_main \
  -nostartfiles -nostdlib \
  -fPIC -shared \
  -fvisibility=hidden \
  -Wl,-e,app_main \
  -Wl,--gc-sections \
  gzip.c -o gzip.elf

xtensa-esp32s3-elf-strip --strip-all --remove-section=.xt.prop -o gzip.stripped.elf gzip.elf

echo "Potential required exports:"
xtensa-esp32s3-elf-nm -u gzip.elf

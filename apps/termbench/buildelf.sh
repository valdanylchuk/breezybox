#!/bin/sh

xtensa-esp32s3-elf-gcc \
  -O2 \
  -DESP_PLATFORM \
  -I local_include \
  -Dmain=app_main \
  -nostartfiles -nostdlib \
  -fPIC -shared \
  -fvisibility=hidden \
  -Wl,-e,app_main \
  -Wl,--gc-sections \
  termbench.c -o termbench.elf

xtensa-esp32s3-elf-strip --strip-all --remove-section=.xt.prop -o termbench.stripped.elf termbench.elf

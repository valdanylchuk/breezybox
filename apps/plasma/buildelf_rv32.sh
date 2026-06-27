#!/bin/sh
# plasma uses libm (sin/cos): statically link libgcc for the float helpers.
exec env LINK_LIBGCC=1 ../buildelf_rv32.sh plasma.c -I local_include

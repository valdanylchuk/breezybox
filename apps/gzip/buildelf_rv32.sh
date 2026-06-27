#!/bin/sh
# This dir ships two tools from two sources.
set -e
../buildelf_rv32.sh gzip.c
../buildelf_rv32.sh gunzip.c

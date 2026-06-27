#!/bin/sh
# This dir ships two tools from two sources.
set -e
../buildelf.sh gzip.c
../buildelf.sh gunzip.c

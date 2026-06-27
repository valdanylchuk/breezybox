#!/bin/sh
# Build every app under apps/ for both targets (S3 + P4) into dist/.
# Release artifacts are named <app>.xtensa.elf and <app>.rv32.elf.
set -e
cd "$(dirname "$0")"

for dir in */; do
  [ -f "$dir/buildelf.sh" ] || continue
  echo "=== ${dir%/} ==="
  ( cd "$dir" && ./buildelf.sh )
  ( cd "$dir" && ./buildelf_rv32.sh )
  echo
done

echo "artifacts in dist/:"
ls -l dist/

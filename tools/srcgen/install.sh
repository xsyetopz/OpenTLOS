#!/bin/sh
# Install a pipeline.sh run into src/ and build/srcgen, then rebuild the report and verify the DOL.
# Usage: tools/srcgen/install.sh <out dir>
# common/Source/Crc.cpp is hand-written and never overwritten.
set -eu
OUT=$1
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
cd "$ROOT"
(cd "$OUT/hdr" && find . -name '*.h') | while read -r f; do mkdir -p "src/$(dirname "$f")"; cp "$OUT/hdr/$f" "src/$f"; done
(cd "$OUT/fenced" && find . -name '*.cpp' ! -path './common/Source/Crc.cpp') | while read -r f; do
  mkdir -p "src/$(dirname "$f")"; cp "$OUT/fenced/$f" "src/$f"
done
cp "$OUT/fence.tsv" build/srcgen/fence.tsv
cp "$OUT/ctx.c" build/srcgen/ctx2.c
cp "$OUT/cnames.json" build/srcgen/cnames.json
rm -rf build/m2c2; cp -R "$OUT/m2c" build/m2c2
timeout 1800 ninja -k 0 build/G6SE7D/report.json | tail -1
ninja build/G6SE7D/ok | tail -1
python3 tools/live/progress.py | tail -2

#!/bin/sh
# Regenerate ANB's draft sources into $OUT, leaving src/ untouched.
# Usage: tools/srcgen/pipeline.sh <out dir> [--classes | --reuse <run dir>]
#   --classes  also rebuild build/srcgen/classes.json from the asm first.
#   --reuse    take ctx.c, cnames.json and m2c/ from an earlier run, for changes
#              that start at cxxconv (m2c output depends only on asm and context).
# Install with tools/srcgen/install.sh <out dir>. Every step is bounded by a timeout.
set -eu
OUT=${1:-}
# $OUT is deleted below, so an option or empty word there must not reach rm.
case "$OUT" in ""|-*) sed -n 3,7p "$0"; exit 2 ;; esac
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
M2C=${M2C:-$ROOT/../GodHand/tools/ext/m2c/m2c.py}
S=$ROOT/build/srcgen
cd "$ROOT"
rm -rf "$OUT"; mkdir -p "$OUT"
if [ "${2:-}" = "--classes" ]; then
  python3 tools/srcgen/classes.py "$OUT/classes.json" | tail -1
  cp "$OUT/classes.json" "$S/classes.json"
fi
MODEL="$S/classes.json $S/fields.json build/m2c $S/ctx.c"
if [ "${2:-}" = "--reuse" ]; then
  cp -R "$3/ctx.c" "$3/cnames.json" "$3/m2c" "$OUT/"
else
  python3 tools/srcgen/cctx.py $MODEL "$OUT/ctx.c" "$OUT/cnames.json" | tail -1
  timeout 1500 python3 tools/srcgen/run_m2c.py "$M2C" build/G6SE7D/asm "$OUT/m2c" --context "$OUT/ctx.c" --jobs 10 | tail -1
fi
# Prototype-only headers of this run tell cxxconv which header declares each free function.
python3 tools/srcgen/headers.py $MODEL "$OUT/protos" --m2c-votes "$OUT/m2c" | tail -1
timeout 1200 python3 tools/srcgen/cxxconv.py $MODEL "$OUT/cnames.json" "$OUT/m2c" build/G6SE7D/asm "$OUT/stage" \
  --inline-root "$OUT/inl" --hdr-root "$OUT/protos" --fixes fixes --m2c-votes "$OUT/m2c" | tail -1
python3 tools/srcgen/headers.py $MODEL "$OUT/hdr" --inline-root "$OUT/inl" --m2c-votes "$OUT/m2c" | tail -1
cp "$S/hdr/unplaced_templates.h" "$OUT/hdr/"
# Fencing a header can unblock or break another; repeat until stable.
prev=""
for p in 1 2 3 4; do
  r=$(timeout 900 python3 tools/srcgen/fence.py "$OUT/hdr" "$OUT/hfence.tsv" --jobs 10 --rounds 60 --headers | tail -1)
  echo "hdr pass $p: $r"
  [ "$r" = "$prev" ] && break
  prev=$r
done
cp -R "$OUT/stage" "$OUT/fenced"
timeout 2400 python3 tools/srcgen/fence.py "$OUT/fenced" "$OUT/fence.tsv" -i "$OUT/hdr" --jobs 10 --rounds 120 | tail -1

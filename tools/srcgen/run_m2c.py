#!/usr/bin/env python3
"""Decompile dtk assembly TUs to C with m2c in a bounded parallel batch.

Usage: run_m2c.py <m2c.py> <asm root> <out root> [--context C] [--jobs N] [--timeout S] [--prefix P ...]

Each `<asm root>/<path>.s` is rewritten by asm_prep into `<out root>/<path>.s`, then
decompiled to `<out root>/<path>.c` plus `.err` (stderr). m2c exits 1 when any
function fails, so failures are counted from the output: whole-function failures
("Decompilation failure") and per-statement M2C_ERROR markers. A summary line per
failing TU and totals are printed; the exit status is 0.
"""

import argparse
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from asm_prep import prepare

M2C_FLAGS = ["-t", "ppc-mwcc-c++", "--valid-syntax", "--deterministic-vars"]


def run(m2c: str, asm: Path, out: Path, timeout: int, extra: list) -> tuple:
    out.parent.mkdir(parents=True, exist_ok=True)
    prepped = out.with_suffix(".s")
    prepped.write_text(prepare(asm.read_text()))
    try:
        r = subprocess.run([sys.executable, m2c, *M2C_FLAGS, *extra, str(prepped)], capture_output=True, text=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        out.with_suffix(".err").write_text(f"timeout after {timeout}s\n")
        return asm, 0, 0, 0
    out.write_text(r.stdout)
    out.with_suffix(".err").write_text(r.stderr)
    funcs = r.stdout.count("\n/* ") if r.stdout else 0
    return asm, funcs, r.stdout.count("Decompilation failure in function"), r.stdout.count("M2C_ERROR(")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("m2c")
    ap.add_argument("asm_root", type=Path)
    ap.add_argument("out_root", type=Path)
    ap.add_argument("--context", type=Path, help="C context from make_context.py (SDK/libc prototypes)")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--timeout", type=int, default=300)
    ap.add_argument("--prefix", nargs="*", default=["spyro", "common"])
    a = ap.parse_args()
    files = sorted(f for p in a.prefix for f in (a.asm_root / p).rglob("*.s"))
    extra = ["--context", str(a.context.resolve())] if a.context else []
    if a.context:  # parse once so parallel workers reuse m2c's context cache
        subprocess.run([sys.executable, a.m2c, *M2C_FLAGS, *extra, str(files[0])], capture_output=True, timeout=a.timeout)
    bad = whole = marks = 0
    with ThreadPoolExecutor(a.jobs) as pool:
        jobs = [pool.submit(run, a.m2c, f, a.out_root / f.relative_to(a.asm_root).with_suffix(".c"), a.timeout, extra) for f in files]
        for j in jobs:
            asm, funcs, failed, errors = j.result()
            whole += failed
            marks += errors
            if failed or errors or not funcs:
                bad += 1
                print(f"{asm.relative_to(a.asm_root)}: failed_functions={failed} error_markers={errors}")
    print(f"{len(files)} TUs, {bad} with errors; {whole} whole-function failures, {marks} M2C_ERROR markers")
    return 0


if __name__ == "__main__":
    sys.exit(main())

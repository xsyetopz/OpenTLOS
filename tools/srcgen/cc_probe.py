#!/usr/bin/env python3
"""Rank compiler versions and flag sets by how well they reproduce a target object.

Usage: cc_probe.py <source> <target.o> [--compilers GC/2.6 GC/2.7 ...] [--flags=<set> ...]

Every compiler x flag-set pair compiles <source> with wibo and is scored with
`objdiff-cli diff` against <target.o>: per-function match percent and size, plus
the size-weighted mean. The table is printed best first. Evidence for a compiler
choice comes from several unrelated functions matching, not from one probe.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
WIBO = ROOT / "build/tools/wibo"
OBJDIFF = ROOT / "build/tools/objdiff-cli"
BASE = "-nodefaults -proc gekko -align powerpc -enum int -fp hardware -Cpp_exceptions off -RTTI off -inline auto"


def score(target: Path, obj: Path) -> dict[str, tuple[float, int, int]]:
    """Function name -> (match percent, target size, our size)."""
    r = subprocess.run([str(OBJDIFF), "diff", "-1", str(target), "-2", str(obj), "-o", "-"],
                       capture_output=True, text=True, timeout=120)
    d = json.loads(r.stdout)
    ours = {s["name"]: int(s.get("size", 0)) for s in d["right"]["symbols"] if s.get("kind") == "SYMBOL_FUNCTION"}
    return {s["name"]: (s.get("match_percent") or 0.0, int(s.get("size", 0)), ours.get(s["name"], 0))
            for s in d["left"]["symbols"] if s.get("kind") == "SYMBOL_FUNCTION"}


def probe(src: Path, target: Path, compiler: str, flags: str, work: Path) -> tuple:
    obj = work / f"{compiler.replace('/', '_')}_{abs(hash(flags))}.o"
    cmd = [str(WIBO), str(ROOT / "build/compilers" / compiler / "mwcceppc.exe"), *BASE.split(), *flags.split(),
           "-c", str(src), "-o", str(obj)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
    if r.returncode or not obj.exists():
        return compiler, flags, None, (r.stdout + r.stderr).strip().splitlines()[-1:]
    return compiler, flags, score(target, obj), []


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path)
    ap.add_argument("target", type=Path)
    ap.add_argument("--compilers", nargs="+", default=["GC/2.0", "GC/2.5", "GC/2.6", "GC/2.7", "GC/3.0a3", "GC/3.0a5.2"])
    # Repeatable with "=" because flag sets themselves start with "-".
    ap.add_argument("--flags", action="append", help='repeatable, e.g. --flags="-O4,p"')
    ap.add_argument("--jobs", type=int, default=6)
    a = ap.parse_args()
    a.flags = a.flags or ["-O4,p", "-O4,s", "-O3", "-O4,p -opt nounroll"]
    rows = []
    with tempfile.TemporaryDirectory() as tmp, ThreadPoolExecutor(a.jobs) as pool:
        jobs = [pool.submit(probe, a.source.resolve(), a.target.resolve(), c, f, Path(tmp)) for c in a.compilers for f in a.flags]
        for j in jobs:
            c, f, fns, err = j.result()
            if fns is None:
                print(f"{c:12} {f:28} compile failed: {' '.join(err)}")
                continue
            total = sum(t for _, t, _ in fns.values()) or 1
            mean = sum(p * t for p, t, _ in fns.values()) / total
            rows.append((mean, c, f, fns))
    for mean, c, f, fns in sorted(rows, key=lambda r: -r[0]):
        detail = " ".join(f"{n.split('__')[0]}={p:.0f}%({o}/{t})" for n, (p, t, o) in fns.items())
        print(f"{mean:6.2f}%  {c:12} {f:28} {detail}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

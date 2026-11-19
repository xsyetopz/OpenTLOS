#!/usr/bin/env python3
"""Compile every generated header alone with the game compiler and tally errors.

Usage: hdr_check.py <header root> <report.tsv> [--jobs N] [--limit N]

A header that compiles alone is self-contained, which is what the per-TU source
agents need before they can include it. Each header gets a one-line stub TU
compiled with config/libs/krome.py's compiler and flags; the first error line is
kept so failures can be grouped by cause.
"""

from __future__ import annotations

import argparse
import shlex
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / "config/libs"))
from krome import CFLAGS, MW_VERSION  # noqa: E402


def check(hdr: Path, root: Path, tmp: Path) -> tuple[str, int, str]:
    rel = hdr.relative_to(root).as_posix()
    stub = tmp / (rel.replace("/", "_") + ".cpp")
    stub.write_text(f'#include "{rel}"\n')
    flags = [f for c in CFLAGS if not c.startswith(("-maxerrors", "-i src")) for f in shlex.split(c)]
    cmd = [str(ROOT / "build/tools/wibo"), str(ROOT / f"build/compilers/{MW_VERSION}/mwcceppc.exe"),
           *flags, "-maxerrors", "1", "-i", str(root), "-c", str(stub), "-o", str(stub.with_suffix(".o"))]
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, timeout=60, cwd=ROOT)
    except subprocess.TimeoutExpired:
        return rel, 1, "timeout"
    if p.returncode == 0:
        return rel, 0, ""
    # mwcc reports "#      In: <file>", the source line, a caret line, then "#   <message>".
    out = (p.stdout + p.stderr).splitlines()
    where = next((l.split("In:", 1)[1].strip().split("\\")[-1] for l in out if l.startswith("#      In:")), "")
    caret = next((i for i, l in enumerate(out) if l.startswith("#   Error:")), None)
    msg = out[caret + 1].lstrip("# ").strip() if caret is not None and caret + 1 < len(out) else "unknown"
    src = out[caret - 1].split(":", 1)[-1].strip() if caret else ""
    return rel, 1, f"{where} | {msg} | {src}"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("root", type=Path)
    ap.add_argument("report", type=Path)
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    root = a.root.resolve()
    hdrs = sorted(root.rglob("*.h"))[: a.limit or None]
    with tempfile.TemporaryDirectory() as t, ThreadPoolExecutor(a.jobs) as ex:
        rows = list(ex.map(lambda h: check(h, root, Path(t)), hdrs))
    a.report.write_text("".join(f"{r}\t{e}\t{m}\n" for r, e, m in rows))
    bad = sum(e for _, e, _ in rows)
    print(f"{len(rows) - bad}/{len(rows)} headers compile alone")
    return 0


if __name__ == "__main__":
    sys.exit(main())

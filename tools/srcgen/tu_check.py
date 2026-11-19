#!/usr/bin/env python3
"""Compile every converted game/engine source with the game compiler and tally errors.

Usage: tu_check.py <src root> <report.tsv> [-i DIR ...] [--jobs N] [--limit N]

Each `<src root>/**/*.cpp` is compiled with config/libs/krome.py's flags and the
include roots `<src root>`, each `-i DIR`, and `include/`. A report row is
`rel <tab> errors <tab> file | first message | source line`, so failures group
by cause and per-TU fixers start from the first error.
"""

from __future__ import annotations

import argparse
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from mwcc import ROOT, compile_one  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("root", type=Path)
    ap.add_argument("report", type=Path)
    ap.add_argument("-i", dest="incs", action="append", type=Path, default=[])
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    root = a.root.resolve()
    incs = [root, *(i.resolve() for i in a.incs), ROOT / "include"]
    srcs = sorted(root.rglob("*.cpp"))[: a.limit or None]
    with tempfile.TemporaryDirectory() as t:
        def check(src: Path) -> tuple[str, int, str]:
            rel = src.relative_to(root).as_posix()
            err, msg = compile_one(src, Path(t) / (rel.replace("/", "_") + ".o"), incs, maxerrors=50, timeout=300)
            return rel, err, msg
        with ThreadPoolExecutor(a.jobs) as ex:
            rows = list(ex.map(check, srcs))
    a.report.write_text("".join(f"{r}\t{e}\t{m}\n" for r, e, m in rows))
    ok = sum(1 for _, e, _ in rows if e == 0)
    print(f"{ok}/{len(rows)} sources compile, {sum(e for _, e, _ in rows)} errors (capped at 50 per TU)")
    return 0


if __name__ == "__main__":
    sys.exit(main())

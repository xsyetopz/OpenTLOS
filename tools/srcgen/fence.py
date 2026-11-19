#!/usr/bin/env python3
"""Fence off the parts of draft TUs that do not compile, and list them as work items.

Usage: fence.py <src root> <report.tsv> [-i DIR ...] [--jobs N] [--rounds N] [--only REL ...]

Each `<src root>/**/*.cpp` is compiled; every top-level definition that
holds an error is wrapped in `#if 0 // DRAFT: <first error>` ... `#endif`,
and the TU is recompiled, for at most `--rounds` rounds. What remains is a
TU that compiles plus a list of fenced functions, each a bounded task for a
fixer: make the fenced body compile, then remove the fence. An error inside
a header cannot be fenced in the TU; such TUs are reported as `header`.

Report rows: `rel <tab> status <tab> definitions <tab> fenced <tab> detail`,
status one of `ok`, `fenced`, `header`, `stuck`.
"""

from __future__ import annotations

import argparse
import re
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from mwcc import ROOT, diagnostics  # noqa: E402

FENCE = "#if 0 // DRAFT: "


def blocks(lines: list[str]) -> list[tuple[int, int]]:
    """0-based inclusive (start, end) of each top-level definition or declaration.

    A block starts at a column-0 line outside braces and ends where its brace
    depth returns to zero (`}` at column 0 for functions) or at its `;`.
    """
    out, depth, start, fenced, comment = [], 0, None, 0, False
    for i, l in enumerate(lines):
        # m2c's failure notes are multi-line comments whose body lines sit at column 0.
        if comment or (depth == 0 and start is None and l.startswith("/*")):
            comment = "*/" not in l
            continue
        if l.startswith(FENCE):
            fenced += 1
            continue
        if fenced:
            fenced -= l.startswith("#endif")
            continue
        if depth == 0 and start is None:
            if not l.strip() or l.startswith(("#", "//", "/*", " ", "\t", "}")):
                continue
            start = i
        code = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', '""', l.split("//")[0])
        depth += code.count("{") - code.count("}")
        if depth == 0 and (code.rstrip().endswith((";", "}"))):
            out.append((start, i))
            start = None
    return out


def fence_once(src: Path, errs: list[tuple[str, int, str]]) -> int:
    """Fence each block holding an error in `src`; returns blocks fenced (0 if none could be)."""
    lines = src.read_text().split("\n")
    first = {}
    for f, line, msg in errs:
        if f == src.name and line:
            first.setdefault(line - 1, msg)
    hits = {}
    for s, e in blocks(lines):
        msg = next((first[i] for i in range(s, e + 1) if i in first), None)
        if msg:
            hits[s] = (e, msg)
    for s in sorted(hits, reverse=True):
        e, msg = hits[s]
        lines[s:e + 1] = [FENCE + msg.replace("\n", " ")[:160], *lines[s:e + 1], "#endif"]
    if hits:
        src.write_text("\n".join(lines))
    return len(hits)


def process(src: Path, root: Path, incs: list[Path], tmp: Path, rounds: int) -> tuple[str, str, int, int, str]:
    rel = src.relative_to(root).as_posix()
    obj = tmp / (rel.replace("/", "_") + ".o")
    status, detail = "stuck", ""
    for _ in range(rounds):
        ok, errs = diagnostics(src, obj, incs)
        if ok:
            status, detail = ("fenced" if FENCE in src.read_text() else "ok"), ""
            break
        own = [e for e in errs if e[0] == src.name]
        if not own:
            status, detail = "header", " | ".join(f"{f}:{n}: {m}" for f, n, m in errs[:1])
            break
        if not fence_once(src, own):
            status, detail = "stuck", " | ".join(f"{f}:{n}: {m}" for f, n, m in own[:1])
            break
    text = src.read_text()
    total = len(blocks(text.split("\n"))) + text.count(FENCE)
    return rel, status, total, text.count(FENCE), detail


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("root", type=Path)
    ap.add_argument("report", type=Path)
    ap.add_argument("-i", dest="incs", action="append", type=Path, default=[])
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--rounds", type=int, default=12)
    ap.add_argument("--only", nargs="*", default=[])
    a = ap.parse_args()
    root = a.root.resolve()
    incs = [root, *(i.resolve() for i in a.incs), ROOT / "include"]
    srcs = [root / r for r in a.only] if a.only else sorted(root.rglob("*.cpp"))
    with tempfile.TemporaryDirectory() as t, ThreadPoolExecutor(a.jobs) as ex:
        rows = list(ex.map(lambda s: process(s, root, incs, Path(t), a.rounds), srcs))
    a.report.write_text("".join("\t".join(map(str, r)) + "\n" for r in rows))
    by = {}
    for r in rows:
        by[r[1]] = by.get(r[1], 0) + 1
    defs, fenced = sum(r[2] for r in rows), sum(r[3] for r in rows)
    print(f"{len(rows)} TUs: {by}; {fenced}/{defs} top-level blocks fenced")
    return 0


if __name__ == "__main__":
    sys.exit(main())

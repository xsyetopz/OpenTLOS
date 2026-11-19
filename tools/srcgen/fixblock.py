#!/usr/bin/env python3
"""Hand-fix workflow for fenced (`#if 0 // DRAFT: <error>`) functions in src/.

Usage:
  fixblock.py list <stem>                      fenced functions of src/<stem>.cpp
  fixblock.py check <stem> <mangled> [--install]
  fixblock.py match <stem> <mangled>           objdiff match of the installed function
                                               (left: original, right: ours)

A fix lives at fixes/<stem>/<mangled>.cpp: the whole C++ definition of one
function. cxxconv.py --fixes emits it in place of the generated draft, so it
survives regeneration. `check` compiles src/<stem>.cpp with every other
fenced function removed and the fix in place of its own block, and prints the
compiler's errors or OK; `--install` then writes the fix into src/ at once.

Blocks are matched to symbols by order: cxxconv emits one definition per m2c
function of the context run (build/m2c2), minus thunks, weak copies, and
local template instances. A TU whose definition count differs is refused
rather than guessed.
"""

from __future__ import annotations

import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from asmdata import bindings  # noqa: E402
from cxxconv import FUNC, TEMPLATE_FN, THUNK  # noqa: E402
from mwcc import diagnostics  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
FENCE = "#if 0 // DRAFT: "


def symbols(stem: str) -> list[str]:
    """Mangled names of the functions cxxconv defines in this TU, in order."""
    text = THUNK.sub("", (ROOT / "build/m2c2" / (stem + ".c")).read_text())
    asm = ROOT / "build/G6SE7D/asm" / (stem + ".s")
    binds = bindings(asm) if asm.exists() else {}
    out = []
    for line in text.split("\n"):
        m = FUNC.match(line)
        if m:
            n = m.group("name")
            if not (binds.get(n) == "weak" or (binds.get(n) == "local" and TEMPLATE_FN.match(n))):
                out.append(n)
    return out


def blocks(lines: list[str]) -> list[tuple[int, int, str | None]]:
    """(first line, closing-brace line, fence message or None) of each top-level definition."""
    out, i = [], 0
    while i < len(lines):
        l = lines[i]
        if l and not l[0].isspace() and l.endswith("{") and "(" in l and " = " not in l \
                and not l.startswith(("#", "/", "struct ", "class ", "typedef ", "namespace ", "extern ")):
            j = next(k for k in range(i + 1, len(lines)) if lines[k] == "}")
            msg = lines[i - 1][len(FENCE):] if i and lines[i - 1].startswith(FENCE) else None
            out.append((i, j, msg))
            i = j
        i += 1
    return out


def mapped(stem: str) -> tuple[list[str], list]:
    lines = (ROOT / "src" / (stem + ".cpp")).read_text().split("\n")
    syms, blks = symbols(stem), blocks(lines)
    if len(syms) != len(blks):
        sys.exit(f"{stem}: {len(blks)} definitions but {len(syms)} symbols; not mappable")
    return lines, list(zip(syms, blks))


def check(stem: str, mangled: str, install: bool) -> int:
    lines, pairs = mapped(stem)
    fix = ROOT / "fixes" / stem / (mangled + ".cpp")
    target = next(((s, b) for s, b in pairs if s == mangled), None)
    if not target or not fix.exists():
        sys.exit(f"no block for {mangled}" if not target else f"missing {fix.relative_to(ROOT)}")
    # A prototype at the top of a fix stays in src/ after install, outside the
    # function's block; a reinstall must not add a second copy.
    # Only the leading declarations are filtered: body statements repeat legitimately.
    # A copy counts only above the block, where it is in scope for the fix.
    _, (start, _, start_msg) = target
    present = set(lines[:start - 1 if start_msg is not None else start])
    text = fix.read_text().strip().split("\n")
    head = 0
    while head < len(text) and (text[head].rstrip().endswith(";") or not text[head].strip()):
        head += 1
    text = [l for l in text[:head] if l.strip() and l not in present] + text[head:]
    out, drop = list(lines), []
    for s, (i, j, msg) in pairs:
        if s == mangled:
            first = i - 1 if msg is not None else i
            last = j + 1 if msg is not None else j
            drop.append((first, last, text))
        elif msg is not None:
            drop.append((i - 1, j + 1, []))
    for first, last, repl in sorted(drop, reverse=True):
        out[first:last + 1] = repl
    tmp = Path(tempfile.mkdtemp())
    src = tmp / Path(stem).with_suffix(".cpp").name
    src.write_text("\n".join(out))
    _, errs = diagnostics(src, tmp / "out.o", [ROOT / "src", ROOT / "include"], maxerrors=20)
    if errs:
        for f, line, m in errs:
            print(f"{f}:{line}: {m}\n    {out[line - 1].strip() if 0 < line <= len(out) else ''}")
        return 1
    print("OK")
    if install:
        _, (i, j, msg) = target
        first = i - 1 if msg is not None else i
        last = j + 1 if msg is not None else j
        lines[first:last + 1] = text
        (ROOT / "src" / (stem + ".cpp")).write_text("\n".join(lines))
        print(f"installed into src/{stem}.cpp")
    return 0


def match(stem: str, mangled: str) -> int:
    """Compile src/<stem>.cpp and print objdiff's match for one function.

    Compiles into a temp object rather than through ninja, so parallel
    fixers never share ninja's logs.
    """
    import json
    import subprocess
    tmp = Path(tempfile.mkdtemp())
    obj = tmp / "out.o"
    _, errs = diagnostics(ROOT / "src" / (stem + ".cpp"), obj, [ROOT / "src", ROOT / "include"], maxerrors=5)
    if errs or not obj.exists():
        print("does not compile:", errs[:3])
        return 1
    d = subprocess.run([str(ROOT / "build/tools/objdiff-cli"), "diff", "-1", str(ROOT / "build/G6SE7D/obj" / (stem + ".o")),
                        "-2", str(obj), "-o", "-", mangled], cwd=ROOT, capture_output=True, text=True)
    if d.returncode:
        print(d.stdout + d.stderr)
        return 1
    side = json.loads(d.stdout)
    for name in ("left", "right"):
        for s in side.get(name, {}).get("symbols", []):
            if s.get("name") == mangled:
                print(f"{name}: size {s.get('size')} match {s.get('match_percent', 0):.2f}%")
    return 0


def main() -> int:
    args = sys.argv[1:]
    if len(args) == 3 and args[0] == "match":
        return match(args[1], args[2])
    if len(args) == 2 and args[0] == "list":
        lines, pairs = mapped(args[1])
        for s, (i, j, msg) in pairs:
            if msg is not None:
                print(f"{s}\tlines {i + 1}-{j + 1}\t{msg}")
        return 0
    if len(args) >= 3 and args[0] == "check":
        return check(args[1], args[2], "--install" in args)
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main())

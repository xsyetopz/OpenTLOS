#!/usr/bin/env python3
"""Write build/live/progress.json: per-function decomp state of ANB and TEN.

Usage: python3 tools/live/progress.py

The headline counts only code Krome wrote: the Spyro game code and the Krome
engine (regions "game" and "engine"). Linked-in libraries (Dolphin/RVL SDK,
Bluetooth stack, MSL, MetroTRK, PowerPC EABI runtime, debugger SDK) are tracked as
a separate line, because a byte-identical build still needs them but their
decompilation is reuse of existing work, not decompilation of the game.

Function states:
  2  done     ANB: objdiff fuzzy match 100% from source.  TEN: high-confidence ANB name.
  1  partial  ANB: compiled from source, differs.         TEN: medium/low-confidence name.
  0  todo     ANB: assembly only, or fenced out.          TEN: unnamed.

Regions:
  ANB  config/G6SE7D/tu_paths.tsv (from the debug-info source paths).
  TEN  the ANB region of each mapped function (config/RO7E7D/anb_map.tsv). Unmapped
       functions take the region shared by the nearest mapped functions on both
       sides, since a TU and a library link contiguously. Runs between two regions
       count as game code unless config/RO7E7D/regions.tsv assigns them, so
       unclassified work is never hidden from the headline.
Once build/RO7E7D/report.json has source-built functions, TEN reads it like ANB.
"""

from __future__ import annotations

import bisect
import json
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
OUT = ROOT / "build/live/progress.json"
GAMES = [("G6SE7D", "A New Beginning (GameCube)"), ("RO7E7D", "The Eternal Night (Wii)")]
OWN = ("game", "engine")
RECENT_MAX = 40

sys.path.insert(0, str(ROOT / "tools/tlos"))
from symbols import functions, load  # noqa: E402


def regions(version: str) -> dict[str, tuple[str, str]]:
    """Maps object path without extension -> (path, region) from tu_paths.tsv."""
    table = ROOT / "config" / version / "tu_paths.tsv"
    out = {}
    if table.exists():
        for line in table.read_text(encoding="utf-8").splitlines()[1:]:
            _, path, region = line.split("\t")[:3]
            out[path.rsplit(".", 1)[0]] = (path, region)
    return out


def from_report(version: str) -> list[dict] | None:
    """Groups from an objdiff report, or None when the report is missing."""
    report = ROOT / "build" / version / "report.json"
    if not report.exists():
        return None
    data = json.loads(report.read_text())
    paths = regions(version)
    groups = []
    for u in data.get("units", []):
        stem = u["name"].split("/", 1)[1] if "/" in u["name"] else u["name"]
        path, region = paths.get(stem, (stem, "game"))
        has_src = (ROOT / "src" / path).exists()
        fns = []
        for f in u.get("functions", []):
            name = f.get("metadata", {}).get("demangled_name") or f["name"]
            # objdiff omits the score for functions absent from the compiled object (fenced drafts).
            pct = f.get("fuzzy_match_percent")
            state = 0 if not has_src or pct is None else 2 if pct >= 100.0 else 1
            fns.append([name, int(f.get("size", 0)), state])
        if fns:
            groups.append({"name": stem, "cat": region, "size": sum(f[1] for f in fns), "fns": fns})
    return groups


def region_overrides(version: str) -> list[tuple[int, int, str]]:
    table = ROOT / "config" / version / "regions.tsv"
    if not table.exists():
        return []
    rows = (l.split("\t") for l in table.read_text(encoding="utf-8").splitlines()[1:] if l.strip())
    return [(int(r[0], 16), int(r[1], 16), r[2]) for r in rows]


def from_symbol_map(version: str) -> list[dict]:
    """Groups from the ANB->TEN symbol map over TEN's dtk function list."""
    names = {}
    mapping = ROOT / "config" / version / "anb_map.tsv"
    if mapping.exists():
        for line in mapping.read_text(encoding="utf-8").splitlines()[1:]:
            c = line.split("\t")
            names[int(c[0], 16)] = (c[2], c[5], 2 if c[7] == "high" else 1)
    anb = {p: r for p, r in regions("G6SE7D").values()}
    funcs = functions(load(str(ROOT / "config" / version / "symbols.txt")))
    region = [anb.get(names[f.addr][1]) if f.addr in names else None for f in funcs]
    known = [i for i, r in enumerate(region) if r]
    overrides = region_overrides(version)
    groups: dict[str, dict] = {}
    for i, f in enumerate(funcs):
        if f.addr in names:
            name, tu, state = names[f.addr]
            key, cat = tu, region[i] or "game"
        else:
            name, state = f.name, 0
            cat = next((r for lo, hi, r in overrides if lo <= f.addr < hi), None)
            if cat is None:
                k = bisect.bisect(known, i)
                left = region[known[k - 1]] if k else None
                right = region[known[k]] if k < len(known) else None
                sides = {left, right} - {None}
                cat = sides.pop() if len(sides) == 1 else "game" if sides & set(OWN) or not sides else min(sides)
            key = f"unnamed {cat} 0x{f.addr & ~0x3FFFF:08X}"
        g = groups.setdefault(key, {"name": key, "cat": cat, "size": 0, "fns": []})
        g["fns"].append([name, f.size, state])
        g["size"] += f.size
    return list(groups.values())


def build_state(version: str) -> str:
    """'OK' when the last checked DOL matched its SHA-1, else 'unverified'."""
    ok = ROOT / "build" / version / "ok"
    dol = ROOT / "build" / version / "main.dol"
    if ok.exists() and dol.exists() and ok.stat().st_mtime >= dol.stat().st_mtime:
        return "OK"
    return "unverified"


def tally(groups: list[dict]) -> dict:
    fns = [f for g in groups for f in g["fns"]]
    return {
        "functions": {"total": len(fns), "done": sum(f[2] == 2 for f in fns), "partial": sum(f[2] == 1 for f in fns)},
        "bytes": {"total": sum(f[1] for f in fns), "done": sum(f[1] for f in fns if f[2] == 2)},
    }


def game_doc(version: str, title: str) -> dict:
    groups, source = from_report(version), "objdiff report"
    if groups is None or not any(f[2] for g in groups for f in g["fns"]):
        if (ROOT / "config" / version / "anb_map.tsv").exists():
            groups, source = from_symbol_map(version), "ANB symbol map"
    own = [g for g in groups if g["cat"] in OWN]
    libs = [g for g in groups if g["cat"] not in OWN]
    return {"id": version, "title": title, "source": source, "build": build_state(version),
            **tally(own), "libraries": tally(libs), "groups": own}


def main() -> int:
    now = time.time()
    games = [game_doc(v, t) for v, t in GAMES]
    recent = []
    if OUT.exists():
        try:
            prev = json.loads(OUT.read_text())
            recent = prev.get("recent", [])
            old = {(g["id"], gr["name"], f[0]): f[2] for g in prev["games"] for gr in g["groups"] for f in gr["fns"]}
            fresh = [
                {"game": g["id"], "fn": f[0], "group": gr["name"], "state": f[2], "t": now}
                for g in games for gr in g["groups"] for f in gr["fns"]
                if f[2] and old.get((g["id"], gr["name"], f[0]), 0) < f[2]
            ]
            # A wholesale change (regrouping, first map) is not news; keep the list readable.
            recent = (fresh[:RECENT_MAX] if len(fresh) < 500 else []) + recent
        except (ValueError, KeyError, IndexError):
            pass
    OUT.parent.mkdir(parents=True, exist_ok=True)
    tmp = OUT.with_suffix(".tmp")
    tmp.write_text(json.dumps({"updated": now, "games": games, "recent": recent[:RECENT_MAX]}, separators=(",", ":")))
    tmp.replace(OUT)  # readers never see a partial file
    for g in games:
        f, b, lf = g["functions"], g["bytes"], g["libraries"]["functions"]
        print(f"{g['id']}: game+engine {100 * b['done'] / max(b['total'], 1):.2f}% bytes, "
              f"{f['done']}/{f['total']} fns done, {f['partial']} partial; "
              f"libraries {lf['done']}/{lf['total']} ({g['source']}, DOL {g['build']})")
    return 0


if __name__ == "__main__":
    sys.exit(main())

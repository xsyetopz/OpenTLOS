#!/usr/bin/env python3
"""Transfer ANB function symbols to TEN by evidence-ranked matching.

Stages, strongest first; each accepts only one-to-one pairs:
  exact    identical masked instruction hash, unique in both executables
  strings  same set of referenced C strings, unique in both executables
  calls    aligned call lists of an accepted pair (same callee count and shapes)
  order    same function count between two accepted anchors inside one ANB TU
  fuzzy    opcode-shape similarity inside gaps between consecutive anchors (see fuzzy.py),
           followed by one rerun of calls

Output TSV columns: ten_addr ten_size anb_name anb_addr anb_size anb_tu method confidence

Usage: match_ten.py <anb dol> <anb symbols> <anb splits> <ten dol> <ten symbols> <out tsv>
"""

import sys
from collections import defaultdict

sys.path.insert(0, __import__("os").path.dirname(__file__))
from dol import Dol  # noqa: E402
import fuzzy  # noqa: E402
from ppc_sig import signature, small_data_bases  # noqa: E402
from splits import Splits  # noqa: E402
from symbols import functions, load  # noqa: E402
import tu_align  # noqa: E402
import vtables  # noqa: E402

CONFIDENCE = {"exact": "high", "strings": "high", "calls": "medium", "align": "medium", "vtable": "medium", "order": "low", "fuzzy": "medium"}
MIN_EXACT_WORDS = 6  # Shorter bodies (getters, stubs) collide by accident.
MAX_ORDER_GAP = 12


class Program:
    """Functions of one executable with signatures and string sets."""

    def __init__(self, dol_path: str, sym_path: str):
        self.dol = Dol(dol_path)
        self.syms = load(sym_path)
        self.funcs = functions(self.syms)
        self.by_addr = {f.addr: f for f in self.funcs}
        self.index = {f.addr: i for i, f in enumerate(self.funcs)}
        init = next(f for f in self.funcs if f.name == "__init_registers")
        sda = small_data_bases(self.dol.words(init.addr, init.size))
        self.sig = {f.addr: signature(f.addr, self.dol.words(f.addr, f.size), sda) for f in self.funcs}
        self.strings = {}
        for addr, s in self.sig.items():
            found = {self.dol.cstring(r) for r in s.refs}
            found.discard(None)
            self.strings[addr] = frozenset(found)


def unique_pairs(a_keys: dict, t_keys: dict) -> list:
    """Pairs functions whose key occurs exactly once on each side."""
    a_groups, t_groups = defaultdict(list), defaultdict(list)
    for addr, k in a_keys.items():
        if k is not None:
            a_groups[k].append(addr)
    for addr, k in t_keys.items():
        if k is not None:
            t_groups[k].append(addr)
    return [(a[0], t_groups[k][0]) for k, a in a_groups.items() if len(a) == 1 and len(t_groups.get(k, [])) == 1]


class Matcher:
    def __init__(self, anb: Program, ten: Program):
        self.anb, self.ten = anb, ten
        self.a2t, self.t2a, self.method = {}, {}, {}

    def accept(self, a: int, t: int, method: str) -> bool:
        if a in self.a2t or t in self.t2a:
            return False
        self.a2t[a], self.t2a[t], self.method[t] = t, a, method
        return True

    def stage_exact(self) -> None:
        keys = lambda p: {a: (s.exact if p.by_addr[a].size >= 4 * MIN_EXACT_WORDS else None) for a, s in p.sig.items()}
        for a, t in unique_pairs(keys(self.anb), keys(self.ten)):
            self.accept(a, t, "exact")

    def stage_strings(self) -> None:
        """Pairs functions through strings each side references from one function only.

        A pair is accepted only when every such string of both functions agrees.
        """
        def owners(p):
            o = defaultdict(set)
            for addr, strs in p.strings.items():
                for s in strs:
                    o[s].add(addr)
            return {s: next(iter(a)) for s, a in o.items() if len(a) == 1}
        ao, to = owners(self.anb), owners(self.ten)
        votes = defaultdict(set)  # anb addr -> ten candidates
        rev = defaultdict(set)
        for s, a in ao.items():
            if s in to:
                votes[a].add(to[s])
                rev[to[s]].add(a)
        for a, ts in votes.items():
            if len(ts) == 1:
                t = next(iter(ts))
                if rev[t] == {a}:
                    self.accept(a, t, "strings")

    def stage_calls(self) -> int:
        added = 0
        for a, t in list(self.a2t.items()):
            ac, tc = self.anb.sig[a].calls, self.ten.sig[t].calls
            if len(ac) != len(tc):
                continue
            for x, y in zip(ac, tc):
                if x in self.anb.sig and y in self.ten.sig and self.anb.sig[x].shape == self.ten.sig[y].shape:
                    added += self.accept(x, y, "calls")
        return added

    def stage_order(self, splits: Splits) -> None:
        anchors = sorted((self.anb.index[a], self.ten.index[t]) for a, t in self.a2t.items())
        for (ai, ti), (aj, tj) in zip(anchors, anchors[1:]):
            gap = aj - ai
            if gap < 2 or gap != tj - ti or gap > MAX_ORDER_GAP:
                continue
            fa = self.anb.funcs
            tus = {splits.tu_at("text", fa[k].addr) for k in range(ai, aj + 1)}
            if len(tus) != 1 or None in tus:
                continue
            for k in range(1, gap):
                self.accept(fa[ai + k].addr, self.ten.funcs[ti + k].addr, "order")


def calibrate(m, splits) -> None:
    """Prints similarity percentiles for string-anchored pairs vs same-TU decoys."""
    sim = tu_align.Similarity(m)
    tu_funcs = tu_align.tu_function_lists(m.anb.funcs, splits)
    true, decoy = [], []
    for t, a in m.t2a.items():
        if m.method[t] != "strings":
            continue
        true.append(sim.score(a, t))
        for other in tu_funcs.get(splits.tu_at("text", a), []):
            if other != a:
                decoy.append(sim.score(other, t))
    for name, xs in (("true", true), ("decoy", decoy)):
        xs.sort()
        q = [xs[int(len(xs) * p)] for p in (0.05, 0.25, 0.5, 0.75, 0.95)] if xs else []
        print(name, len(xs), " ".join(f"{v:.2f}" for v in q))
    for thr in (0.8, 1.0, 1.2, 1.4):
        print(f"thr {thr}: true>= {sum(x >= thr for x in true)}, decoy>= {sum(x >= thr for x in decoy)}")


def main() -> None:
    anb_dol, anb_sym, anb_splits, ten_dol, ten_sym, out = sys.argv[1:7]
    anb, ten = Program(anb_dol, anb_sym), Program(ten_dol, ten_sym)
    splits = Splits(anb_splits)
    m = Matcher(anb, ten)
    m.stage_exact()
    m.stage_strings()
    if "--calibrate" in sys.argv:
        calibrate(m, splits)
        return
    tu_funcs = tu_align.tu_function_lists(anb.funcs, splits)
    anb_vts = vtables.anb_vtables(anb, anb.syms)
    ten_vts = {}
    for lo, hi in ten.dol.data_ranges:
        ten_vts.update(vtables.ten_vtables(ten, lo, hi))
    vt_names = {}
    for _ in range(6):  # Each round adds anchors for the next; the bound keeps it finite.
        for _ in range(8):
            if not m.stage_calls():
                break
        added, vt_names = vtables.match(m, anb_vts, ten_vts)
        if not tu_align.align(m, splits, tu_funcs) + added:
            break
    with open(out.replace(".tsv", "_vtables.tsv"), "w", encoding="utf-8") as f:
        f.write("ten_addr\tanb_name\tslots\n")
        for addr in sorted(vt_names):
            f.write(f"0x{addr:08X}\t{vt_names[addr]}\t{len(ten_vts[addr])}\n")
    print(f"vtables: ANB {len(anb_vts)}, TEN candidates {len(ten_vts)}, paired {len(vt_names)}")
    for _ in range(4):  # fuzzy pairs split gaps, which lets order, calls and fuzzy add more
        before = len(m.a2t)
        m.stage_order(splits)
        fuzzy.stage(m)
        for _ in range(8):
            if not m.stage_calls():
                break
        tu_align.align(m, splits, tu_funcs)
        if len(m.a2t) == before:
            break
    counts = defaultdict(int)
    with open(out, "w", encoding="utf-8") as f:
        f.write("ten_addr\tten_size\tanb_name\tanb_addr\tanb_size\tanb_tu\tmethod\tconfidence\n")
        for t in sorted(m.t2a):
            a = m.t2a[t]
            fa, ft = anb.by_addr[a], ten.by_addr[t]
            method = m.method[t]
            counts[method] += 1
            f.write(f"0x{t:08X}\t0x{ft.size:X}\t{fa.name}\t0x{a:08X}\t0x{fa.size:X}\t"
                    f"{splits.tu_at('text', a) or splits.tu_at('init', a) or ''}\t{method}\t{CONFIDENCE[method]}\n")
    total = sum(counts.values())
    print(f"TEN functions: {len(ten.funcs)}; matched {total} ({100 * total / len(ten.funcs):.1f}%)")
    for k, v in counts.items():
        print(f"  {k}: {v}")


if __name__ == "__main__":
    main()

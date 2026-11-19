"""Vtable-based matching of virtual methods.

CodeWarrior vtables with RTTI off are `[0, 0, method...]`. ANB names them
(`__vt__<class>`); TEN tables are found by shape. An ANB table pairs with the TEN
table of equal length that the most already-matched slots agree with. Its other
slots then pair by index. Matched tables also give TEN names for the vtable
objects themselves.
"""

from collections import Counter, defaultdict

MIN_VOTES = 2


def anb_vtables(prog, syms) -> dict:
    """Maps ANB vtable name -> (address, [slot function addresses])."""
    out = {}
    for s in syms:
        if s.name.startswith("__vt__") and s.size >= 12:
            words = prog.dol.words(s.addr, s.size)
            if words[0] == 0 and words[1] == 0:
                out[s.name] = (s.addr, list(words[2:]))
    return out


def ten_vtables(prog, data_start: int, data_end: int) -> dict:
    """Maps TEN address -> [slot function addresses] for `[0, 0, func...]` runs."""
    words = prog.dol.words(data_start, data_end - data_start)
    funcs = prog.by_addr
    out = {}
    i = 0
    while i + 2 < len(words):
        if words[i] == 0 and words[i + 1] == 0 and words[i + 2] in funcs:
            j = i + 2
            while j < len(words) and words[j] in funcs:
                j += 1
            out[data_start + 4 * i] = list(words[i + 2:j])
            i = j
        else:
            i += 1
    return out


def match(matcher, anb_vts: dict, ten_vts: dict) -> tuple:
    """Pairs vtables and their slots; returns (slots accepted, {ten_addr: anb_name})."""
    by_slot = defaultdict(set)
    for addr, slots in ten_vts.items():
        for k, t in enumerate(slots):
            by_slot[(t, k)].add(addr)
    pairs = {}
    claimed = Counter()
    for name, (_, slots) in anb_vts.items():
        votes = Counter()
        for k, a in enumerate(slots):
            t = matcher.a2t.get(a)
            if t is not None:
                for addr in by_slot.get((t, k), ()):
                    if len(ten_vts[addr]) == len(slots):
                        votes[addr] += 1
        if not votes:
            continue
        ranked = votes.most_common(2)
        if ranked[0][1] >= MIN_VOTES and (len(ranked) == 1 or ranked[1][1] < ranked[0][1]):
            pairs[name] = ranked[0][0]
            claimed[ranked[0][0]] += 1
    names = {addr: name for name, addr in pairs.items() if claimed[addr] == 1}
    added = 0
    for addr, name in names.items():
        for a, t in zip(anb_vts[name][1], ten_vts[addr]):
            if a not in matcher.anb.by_addr:
                continue
            sa, st = matcher.anb.by_addr[a].size, matcher.ten.by_addr[t].size
            if min(sa, st) / max(sa, st) >= 0.25:
                added += matcher.accept(a, t, "vtable")
    return added, names

"""Fuzzy opcode-shape matching inside gaps between accepted anchors.

Unmatched functions lying between the same two consecutive accepted pairs, in
address order on both executables, are compared by the similarity of their
opcode-shape sequences from ppc_sig.py. Shape tokens hold no immediates or
relocation fields, so the score ignores the differences the exact hash masks.
A pair is accepted only when it is the clear best candidate in its row and column.
"""

from collections import defaultdict
from difflib import SequenceMatcher

MIN_RATIO = 0.90  # Similarity floor for an accepted pair.
MAX_SIZE_DIFF = 0.25  # Allowed |size_a - size_t| as a fraction of the larger size.
MIN_MARGIN = 0.10  # Rivals in the same row or column must score at least this far below.
# 0.05 gave a 4.2% false-match rate on exact/strings holdout pairs; 0.10 gave 1.6%.
MAX_PAIRS = 200_000  # Gaps with more candidate pairs are skipped to bound run time.


def stage(m) -> int:
    """Accepts fuzzy pairs in each gap between consecutive anchors; returns the count."""
    anb, ten = m.anb, m.ten
    anchors = sorted((anb.index[a], ten.index[t]) for a, t in m.a2t.items())
    added = 0
    for (ai, ti), (aj, tj) in zip(anchors, anchors[1:]):
        A = [f.addr for f in anb.funcs[ai + 1:aj] if f.addr not in m.a2t]
        T = [f.addr for f in ten.funcs[ti + 1:tj] if f.addr not in m.t2a]
        if A and T and len(A) * len(T) <= MAX_PAIRS:
            added += _gap(m, A, T)
    return added


def _gap(m, A: list, T: list) -> int:
    """Scores every A x T pair above the prefilter floor and accepts the clear mutual winners."""
    # quick_ratio() bounds ratio() from above. A rival below MIN_RATIO - MIN_MARGIN can
    # never block an accepted pair, so skipping such pairs leaves the result unchanged.
    floor = MIN_RATIO - MIN_MARGIN
    sm = SequenceMatcher(None, autojunk=False)  # autojunk would distort long bodies.
    scores = {}
    for t in T:
        sm.set_seq2(m.ten.sig[t].ops)
        for a in A:
            sm.set_seq1(m.anb.sig[a].ops)
            if sm.quick_ratio() >= floor:
                r = sm.ratio()
                if r >= floor:
                    scores[(a, t)] = r
    row, col = defaultdict(list), defaultdict(list)
    for (a, t), r in scores.items():
        row[a].append((r, t))
        col[t].append((r, a))
    added = 0
    for (a, t), r in scores.items():
        if r < MIN_RATIO or not _clear_lead(row[a], r, t) or not _clear_lead(col[t], r, a):
            continue
        if _sizes_close(m, a, t) and m.accept(a, t, "fuzzy"):
            added += 1
    return added


def _clear_lead(rivals: list, r: float, key: int) -> bool:
    """True when every other candidate in the row or column scores at least MIN_MARGIN below r."""
    return all(s <= r - MIN_MARGIN for s, k in rivals if k != key)


def _sizes_close(m, a: int, t: int) -> bool:
    sa, st = m.anb.by_addr[a].size, m.ten.by_addr[t].size
    return abs(sa - st) <= MAX_SIZE_DIFF * max(sa, st)

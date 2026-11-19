# Fixer brief

A fixer turns fenced draft functions (`#if 0 // DRAFT: <error>`) in its
assigned translation units into compiling C++ that keeps the asm's
semantics. The workflow and tools are in `docs/srcgen.md`, section "Hand
fixes".

## Per TU

1. `tools/srcgen/fixblock.py list <tu>` lists fenced functions, mangled names and first errors.
2. Write `fixes/<tu>/<mangled>.cpp` with the full definition. Start from the
   draft in `src/<tu>.cpp`; the asm in `build/G6SE7D/asm/<tu>.s` decides intent.
3. `tools/srcgen/fixblock.py check <tu> <mangled>` until OK, then the same
   command with `--install`, then `tools/srcgen/fixblock.py match <tu> <mangled>`.

## Write scope

A fixer writes only `fixes/<tu>/` for its assigned TUs, plus the edit that
`--install` makes to `src/<tu>.cpp`. Headers, `tools/`, `config/` and other
TUs belong to other owners. git, ninja and `tools/srcgen/pipeline.sh` are
the coordinator's: a fixer never runs them.

## Faithfulness

- Struct fields and names come from the headers. A member the header lacks
  is reached with `M2C_FIELD(obj, T *, off)` or a cast, not invented.
- Paired-single asm (`psq_l`, `psq_st`, `ps_add`, `ps_muls0`, ...) that the
  draft shows as f64 arithmetic (`M2C_BITWISE(f64, x)`, f64 sums of vector
  halves) becomes per-lane f32 math on the components. A function that
  cannot be expressed that way is skipped: compiling f64 arithmetic changes
  its results.
- Double-precision asm (`lfd`/`fmul`/`fadd` on f64 fields, no `ps_` ops)
  stays f64: only paired-single code becomes per-lane f32.
- A call that returns a struct through a hidden buffer (sret: buffer in r3,
  `this` in r4) to a function a header declares void blocks the function.
  The sret buffer is never `this`, and stack objects never stand in for it.
- Constants come from the asm's literal pool, not from guesses.
- A draft over 250 lines, or one blocked on a type no header declares, is
  skipped with the reason.

## Budget

A fixer stays well under 100k tokens, and every command it runs finishes
on its own (timeouts, no polling loops).

## Report

At most 25 lines: per function the mangled name, OK or skip (with reason),
match %, and fix path; then header problems seen, each with file, member
and asm evidence.

# Draft source generation (ANB)

`src/` for G6SE7D's game and engine TUs starts as generated drafts. The
generator runs m2c over dtk's split asm, converts its C to C++ against a
class model recovered from the binary, and fences every top-level block MWCC
rejects as `#if 0 // DRAFT: <first error>`. A fenced block is a function
not yet compilable; its error tells a fixer where to start.

## Pipeline

```sh
tools/srcgen/pipeline.sh $TMPDIR/run [--classes]   # about 40-60 minutes
tools/srcgen/install.sh $TMPDIR/run                # copies into src/, rebuilds, verifies the DOL
```

| Step | Script | Output |
|---|---|---|
| Class model (bases, vtables, methods, secondary bases) | `classes.py` | `build/srcgen/classes.json` |
| Field votes from m2c's per-TU inferences | `fields.py` | `build/srcgen/fields.json` |
| C context of all classes for m2c | `cctx.py` | `ctx.c`, `cnames.json` |
| m2c with context | `run_m2c.py` | `m2c/` |
| m2c input fixes: jump-table names, realigned frames, paired-single code lowered to lane ps0 (vector source restored by hand) | `asm_prep.py` | used by `run_m2c.py` |
| C to C++ | `cxxconv.py` | `stage/`, header inlines |
| `void *` byte arithmetic (`p + 0x30`) as `(u8 *)` arithmetic; dereferences left alone | `voidarith.py` | used by `cxxconv.py` |
| Undeclared `unkspX` stack reads as typed reads inside the enclosing local (type from the asm access) | `stackslots.py` | used by `cxxconv.py` |
| Headers | `headers.py` | `hdr/` |
| By-value enums (no forward declaration in C++03; real header unknown) | `henums.py` | `hdr/unplaced_enums.h` |
| Fencing | `fence.py` | `fenced/`, `fence.tsv` |

`fence.tsv` lists every TU with its fenced and total block counts; it is the
fixers' worklist.

## Hand fixes

Regeneration overwrites `src/*.cpp`, so a fixed function lives in
`fixes/<stem>/<mangled>.cpp` as its full C++ definition, and `cxxconv.py
--fixes fixes` emits it in place of the draft. A fix that a later model
change breaks is fenced like any draft, so it stays visible.

```sh
tools/srcgen/fixblock.py list spyro/source/Button                  # fenced functions, mangled names, first errors
tools/srcgen/fixblock.py check spyro/source/Button <mangled>        # compile with the fix; prints errors or OK
tools/srcgen/fixblock.py check spyro/source/Button <mangled> --install
tools/srcgen/fixblock.py match spyro/source/Button <mangled>        # objdiff match of the installed function
```

`check` compiles the TU with all other fenced blocks removed, so its errors
belong to the fix. `match` compiles into a temp object rather than through
ninja, so parallel fixers on different TUs never share ninja's logs.

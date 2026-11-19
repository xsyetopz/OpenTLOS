# Draft source generation (ANB)

`src/` for G6SE7D's game and engine TUs starts as generated drafts. The
generator runs m2c over dtk's split asm, converts its C to C++ against a
class model recovered from the binary, and fences every top-level block MWCC
rejects as `#if 0 // DRAFT: <first error>`. A fenced block is a function
not yet compilable; its error tells a fixer where to start.

## Pipeline

```sh
tools/srcgen/pipeline.sh $TMPDIR/run [--classes | --reuse <run>]   # about 40-60 minutes
tools/srcgen/install.sh $TMPDIR/run                # copies into src/, rebuilds, verifies the DOL
```

| Step | Script | Output |
|---|---|---|
| Class model (bases, vtables, methods, secondary bases) | `classes.py` | `build/srcgen/classes.json` |
| Field votes from m2c's per-TU inferences | `fields.py` | `build/srcgen/fields.json` |
| Static methods: parameterless, body never reads r3, and at most 15% of callers write r3 before the `bl` | `mstatic.py` | used by `hmodel.load_model` |
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

`--reuse <run>` starts at `cxxconv.py` with an earlier run's `ctx.c` and
`m2c/`. It is valid only when the class layout is unchanged: m2c names a
field `unkXXX` by its offset in `ctx.c`, so a layout change renames fields
throughout the drafts.

## Class layout

A base is recorded only with binary evidence: vtable stores in the ctor or
dtor, a call to the base ctor as the ctor's first call on unchanged `r3`,
or inlined base vtable stores. The class's `// base:` comment names that
evidence.

The headers, `ctx.c` and `hmodel.Model` share one layout so that header
offsets equal the asm's offsets. These rules follow MWCC:

- A class's size is its last field's end rounded to its alignment, and a
  derived class starts after the base's rounded size. MWCC keeps the base's
  tail padding.
- Alignment is the widest member's. f64 counts as 8, so CollisionObject
  is 0x478, not 0x474, and Character's first field sits at 0x110 + 0x478.
- The vptr sits at the first virtual declaration. A class that introduces
  it declares any data members that precede it first.
- A field vote that starts inside an earlier field is dropped. It adds
  neither a member nor size (KDScriptProperty's 0x14 vote inside its 0x10
  KDPropertyCommandList).

Two config tables override the votes, each row citing its asm evidence:
`config/G6SE7D/class_sizes.tsv` caps a class at a proven size, and
`class_fields.tsv` gives the full layout of a struct that m2c reaches only
through byte arithmetic and so never votes for (`MKParticleSystem::Envelope`,
`DataMap`). A static array of such a struct then compiles by value.

`tools/srcgen/mwcc.py`'s `compile_one` compiles a probe of
`char p[(int)&((C*)0)->field + 1];` lines, which shows where MWCC actually
put each member.

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

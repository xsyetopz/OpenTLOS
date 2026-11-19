# TLOS toolchain evidence

## ANB (G6SE7D) link

The split-object rebuild of `sys/main.dol` matches SHA1 `c4c38d10687e0c5d4b99fba3981282be48134117` (`ninja build/G6SE7D/ok`).

| Fact | Evidence |
| --- | --- |
| Linker is GC 2.7 (mwld) or newer. | Common BSS shows no inflation: for example, `defaultCollisionMin` and `defaultCollisionMax` (both in MKCollision) are 0x10 each. Every linker from GC 1.3.2 to GC 2.6 inflates `.bss` to 0x1A33F0. |
| The linker is not GC 3.0a3 or newer. | With comment-10 objects, the 3.0a3 linker writes an empty ELF. |
| `.comment` version is 11. | This matches the GC 2.7 linker. |
| `__init_cpp_exceptions.cpp` defines `__destroy_global_chain_reference`. | mwld 2.7 rejects the link ("runtime sources ... need to be updated") without that definition. |
| Only the init and fini references are FORCEACTIVE. | The final `.dtors` is `[__fini_cpp_exceptions, 0]`, so the destroy-chain reference is deadstripped. |
| `__fini_cpp_exceptions` is defined before `__init_cpp_exceptions`. | Their addresses are 0x802C3204 and 0x802C3238. |
| `.bss` is declared `align:32` in splits.txt. | mwld 2.7 with `ALIGN(0x40)` places `.bss` at 0x803E4E00. The original address is 0x803E4DC0. |
| Three common symbols have larger alignment. | Gaps in the original layout show it (`tools/tlos/infer_common_align.py`): `currentVideo` 32, `loadInfo__6MKProp` 8, `wind` 8. |
| sjiswrap is disabled. | The USA sources are ASCII, and wibo 1.2.0 cannot load `sjiswrap.exe` (`GetProcAddressFail`). |

The compiler for `__init_cpp_exceptions.cpp` is provisionally GC 2.7. This is unverified because objdiff has not compared that object yet.

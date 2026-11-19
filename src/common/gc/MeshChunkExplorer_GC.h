#ifndef COMMON_GC_MESHCHUNKEXPLORER_GC_H
#define COMMON_GC_MESHCHUNKEXPLORER_GC_H

#include <dolphin/types.h>

class MeshChunkExplorer_GC;

class MeshChunkExplorer_GC {
public:
    void SetMeshChunk(int, int, int);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'zero'
inline void MeshChunkExplorer_GC::SetMeshChunk(int arg0, int arg1, int arg2) {
    MeshChunkExplorer_GC *var_r0_429;
    MeshChunkExplorer_GC *var_r0_438;
    MeshChunkExplorer_GC *var_r0_447;
    MeshChunkExplorer_GC *var_r0_456;
    s32 temp_r3_385;
    u16 *temp_r3_401;
    u16 *temp_r3_408;
    u16 *temp_r3_412;
    u32 temp_r3_328;
    void *temp_r4_369;
    void *temp_r7_322;
    void *var_r0_332;

    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x78) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x80) = (f64) M2C_FIELD(&zero, f64 *, 8);
    M2C_FIELD(this, void **, 0x48) = (void *) M2C_FIELD(*M2C_FIELD(this, void ***, 0x40), void **, 0x30);
    temp_r7_322 = M2C_FIELD(this, void **, 0x48);
    temp_r3_328 = *(M2C_FIELD(temp_r7_322, s32 *, 0x68) + ((arg1 + (arg0 * M2C_FIELD(temp_r7_322, s16 *, 4))) * 4));
    if (temp_r3_328 != 0U) {
        var_r0_332 = M2C_FIELD(temp_r7_322, s32 *, 0x6C) + temp_r3_328;
    } else {
        var_r0_332 = NULL;
    }
    M2C_FIELD(this, void **, 0x44) = var_r0_332;
    M2C_FIELD(this, s8 *, 0x50) = (s8) (M2C_FIELD((M2C_FIELD(M2C_FIELD(this, void **, 0x48), s32 *, 0x50) + (arg1 << 6)), u8 *, 0x38) != 0);
    if ((void *) M2C_FIELD(this, void **, 0x44) == NULL) {
        M2C_FIELD(this, s32 *, 0) = 0;
        M2C_FIELD(this, s32 *, 4) = 0;
        M2C_FIELD(this, s32 *, 8) = 0;
        M2C_FIELD(this, void **, 0x90) = NULL;
        M2C_FIELD(this, void **, 0x94) = NULL;
        M2C_FIELD(this, void **, 0x98) = NULL;
        return;
    }
    M2C_FIELD(this, s32 *, 0x4C) = arg2;
    M2C_FIELD(this, s32 *, 0) = -1;
    M2C_FIELD(this, s32 *, 4) = (s32) M2C_FIELD(M2C_FIELD(this, void **, 0x44), u16 *, 6);
    M2C_FIELD(this, s32 *, 8) = 0;
    M2C_FIELD(this, u16 **, 0x3C) = (u16 *) (M2C_FIELD(this, void **, 0x44) + 0x20);
    temp_r4_369 = M2C_FIELD(this, void **, 0x44);
    M2C_FIELD(this, void **, 0x94) = (void *) (temp_r4_369 + (M2C_FIELD(temp_r4_369, s32 *, 0x10) + 0x20));
    M2C_FIELD(this, void **, 0x90) = (void *) (M2C_FIELD(this, void **, 0x94) + M2C_FIELD(M2C_FIELD(this, void **, 0x44), s32 *, 0x14));
    M2C_FIELD(this, void **, 0x98) = (void *) (M2C_FIELD(this, void **, 0x90) + M2C_FIELD(M2C_FIELD(this, void **, 0x44), s32 *, 0x18));
    temp_r3_385 = M2C_FIELD(this, s32 *, 0) + 1;
    M2C_FIELD(this, s32 *, 0) = temp_r3_385;
    if (temp_r3_385 >= (s32) M2C_FIELD(this, s32 *, 4)) {
        M2C_FIELD(this, void **, 0x44) = NULL;
    } else {
        M2C_FIELD(this, u16 **, 0x3C) = (u16 *) (M2C_FIELD(this, u16 **, 0x3C) + (M2C_FIELD(this, s32 *, 8) * 9));
        temp_r3_401 = M2C_FIELD(this, u16 **, 0x3C) + 1;
        M2C_FIELD(this, u16 **, 0x3C) = temp_r3_401;
        M2C_FIELD(this, u16 **, 0x3C) = temp_r3_401;
        M2C_FIELD(this, s32 *, 8) = (s32) *M2C_FIELD(this, u16 **, 0x3C);
        temp_r3_408 = M2C_FIELD(this, u16 **, 0x3C) + 2;
        M2C_FIELD(this, u16 **, 0x3C) = temp_r3_408;
        M2C_FIELD(this, u16 **, 0x3C) = temp_r3_408;
        M2C_FIELD(this, s8 *, 0xC) = 1;
        temp_r3_412 = M2C_FIELD(this, u16 **, 0x3C);
        if (memcmp(temp_r3_412, temp_r3_412 + 9, 9U) == 0) {
            M2C_FIELD(this, s32 *, 8) = (s32) (M2C_FIELD(this, s32 *, 8) - 1);
            M2C_FIELD(this, s8 *, 0xC) = 0;
            M2C_FIELD(this, u16 **, 0x3C) = (u16 *) (M2C_FIELD(this, u16 **, 0x3C) + 9);
        }
    }
    if (M2C_FIELD(this, s32 *, 0x4C) & 1) {
        var_r0_429 = this + 0x58;
    } else {
        var_r0_429 = NULL;
    }
    M2C_FIELD(this, MeshChunkExplorer_GC **, 0x18) = var_r0_429;
    if (M2C_FIELD(this, s32 *, 0x4C) & 2) {
        var_r0_438 = this + 0x68;
    } else {
        var_r0_438 = NULL;
    }
    M2C_FIELD(this, MeshChunkExplorer_GC **, 0x1C) = var_r0_438;
    if (M2C_FIELD(this, s32 *, 0x4C) & 4) {
        var_r0_447 = this + 0x88;
    } else {
        var_r0_447 = NULL;
    }
    M2C_FIELD(this, MeshChunkExplorer_GC **, 0x20) = var_r0_447;
    if (M2C_FIELD(this, s32 *, 0x4C) & 8) {
        var_r0_456 = this + 0x78;
    } else {
        var_r0_456 = NULL;
    }
    M2C_FIELD(this, MeshChunkExplorer_GC **, 0x24) = var_r0_456;
    M2C_FIELD(this, s32 *, 0x28) = 0;
}
#endif

#endif  // COMMON_GC_MESHCHUNKEXPLORER_GC_H

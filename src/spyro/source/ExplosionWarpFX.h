#ifndef SPYRO_SOURCE_EXPLOSIONWARPFX_H
#define SPYRO_SOURCE_EXPLOSIONWARPFX_H

#include <dolphin/types.h>

class ExplosionWarpFX;
class MKMaterial;
class Matrix;

class ExplosionWarpFX {
public:
    void UpdateWarp(void);
    void StartWarp(Matrix *);
    void BuildLocalVertexList(void);
    void Deinit(void);
    void Draw(void);
    void Update(void);
    void Init(void);
    /* 0x000 */ void* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 pad14[0x8];
    /* 0x01c */ u8 unk1C;
    /* 0x01d */ u8 pad1D[0x43];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ s32 unk68;
};

#endif  // SPYRO_SOURCE_EXPLOSIONWARPFX_H

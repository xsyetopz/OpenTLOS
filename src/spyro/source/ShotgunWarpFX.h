#ifndef SPYRO_SOURCE_SHOTGUNWARPFX_H
#define SPYRO_SOURCE_SHOTGUNWARPFX_H

#include <dolphin/types.h>

class MKMaterial;
class MKVector3;
class Matrix;
class ShotgunWarpFX;

class ShotgunWarpFX {
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
    /* 0x014 */ u8 pad14[0x4c];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ u8 unk70;
    /* 0x071 */ u8 pad71[0x3];
    /* 0x074 */ s32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
};

f32 Xform3D2D(MKVector3 *, const MKVector3 &, Matrix *);
#endif  // SPYRO_SOURCE_SHOTGUNWARPFX_H

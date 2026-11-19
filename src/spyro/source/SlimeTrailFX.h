#ifndef SPYRO_SOURCE_SLIMETRAILFX_H
#define SPYRO_SOURCE_SLIMETRAILFX_H

#include <dolphin/types.h>

class MKHeap;
class MKMaterial;
class MKVector3;
class SlimeTrailFX;
class SlimeTrailFXManager;

class SlimeTrailFX {
public:
    void Deinit(void);
    void UpdatePos(MKVector3 *, const MKVector3 &);
    void Draw(void);
    void Reset(void);
    void Init(void);
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x8];
    /* 0x014 */ MKHeap* unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ MKMaterial* unk20;
    /* 0x024 */ MKVector3* unk24;
    /* 0x028 */ u8 unk28;
};

class SlimeTrailFXManager {
public:
    void Deinit(void);
    void FreeTrail(SlimeTrailFX *);
    SlimeTrailFX * AllocTrail(MKMaterial *);
    void Draw(void);
    void Update(void);
    void Init(void);
    /* 0x000 */ MKHeap* unk0;
};

#endif  // SPYRO_SOURCE_SLIMETRAILFX_H

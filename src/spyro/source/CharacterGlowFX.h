#ifndef SPYRO_SOURCE_CHARACTERGLOWFX_H
#define SPYRO_SOURCE_CHARACTERGLOWFX_H

#include <dolphin/types.h>

class CBFXNode;
class CharacterBodyFXData;
class CharacterGlowFX;
class MKMaterial;
class MKModel;
class MKVector4;

class CharacterGlowFX {
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void Enable(bool, const MKVector4 &, float);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ u8 padC[0x8];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ MKMaterial* unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f32 unk38;
};

#endif  // SPYRO_SOURCE_CHARACTERGLOWFX_H

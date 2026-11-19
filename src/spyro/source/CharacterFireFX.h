#ifndef SPYRO_SOURCE_CHARACTERFIREFX_H
#define SPYRO_SOURCE_CHARACTERFIREFX_H

#include <dolphin/types.h>

class CBFXNode;
class CharacterBodyFXData;
class CharacterFireFX;
class MKModel;

class CharacterFireFX {
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void EmitFire(void);
    void EmitSmoke(void);
    void Enable(bool, float);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u32 unk8;
    /* 0x00c */ u8 padC[0x8];
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
};

#endif  // SPYRO_SOURCE_CHARACTERFIREFX_H

#ifndef SPYRO_SOURCE_CHARACTERICECUBESFX_H
#define SPYRO_SOURCE_CHARACTERICECUBESFX_H

#include <dolphin/types.h>
#include "spyro/source/CharacterBodyFX.h"

class CBFXNode;
class CharacterBodyFX;
class CharacterBodyFXData;
class CharacterIceCubesFX;
class MKHeap;
class MKModel;
class MKPropDescriptor;

class CharacterIceCubesFX : public CharacterBodyFX {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void Trigger(void);
    void Reset(void);
    void Shatter(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ MKHeap* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 pad11[0x3];
    /* 0x014 */ void* unk14;
    /* 0x018 */ u8 unk18;
    /* 0x019 */ u8 pad19[0x3];
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ u8 unk20;
    /* 0x021 */ s8 unk21;
    /* 0x022 */ u8 pad22[0x2];
    /* 0x024 */ MKPropDescriptor* unk24;
};

#endif  // SPYRO_SOURCE_CHARACTERICECUBESFX_H

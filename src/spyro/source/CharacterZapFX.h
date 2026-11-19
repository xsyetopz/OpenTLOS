#ifndef SPYRO_SOURCE_CHARACTERZAPFX_H
#define SPYRO_SOURCE_CHARACTERZAPFX_H

#include <dolphin/types.h>
#include "spyro/source/CharacterBodyFX.h"

class CBFXNode;
class CharacterBodyFX;
class CharacterBodyFXData;
class CharacterZapFX;
class CharacterZapFX_cpp;
class MKHeap;
class MKModel;

class CharacterZapFX : public CharacterBodyFX {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void Enable(bool, float, bool);
    void SpawnZap(void);
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 unk15;
    /* 0x016 */ u8 unk16;
    /* 0x017 */ s8 unk17;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f64 unk40;
    /* 0x048 */ MKHeap* unk48;
    /* 0x04c */ MKModel* unk4C;
    /* 0x050 */ s32 unk50;
};

class CharacterZapFX_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_CHARACTERZAPFX_H

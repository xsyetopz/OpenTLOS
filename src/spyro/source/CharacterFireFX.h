#ifndef SPYRO_SOURCE_CHARACTERFIREFX_H
#define SPYRO_SOURCE_CHARACTERFIREFX_H

#include <dolphin/types.h>
#include "spyro/source/CharacterBodyFX.h"

class CBFXNode;
class CharacterBodyFX;
class CharacterBodyFXData;
class CharacterFireFX;
class MKModel;

class CharacterFireFX : public CharacterBodyFX {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void EmitFire(void);
    void EmitSmoke(void);
    void Enable(bool, float);
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void CharacterFireFX::Draw() {

}

#endif  // SPYRO_SOURCE_CHARACTERFIREFX_H

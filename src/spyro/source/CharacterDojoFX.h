#ifndef SPYRO_SOURCE_CHARACTERDOJOFX_H
#define SPYRO_SOURCE_CHARACTERDOJOFX_H

#include <dolphin/types.h>
#include "common/Source/MKVector4.h"
#include "spyro/source/CharacterBodyFX.h"

class CBFXNode;
class CharacterBodyFX;
class CharacterBodyFXData;
class CharacterDojoFX;
class MKModel;
class MKVector4;

class CharacterDojoFX : public CharacterBodyFX {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void Emit(void);
    void Enable(bool, MKVector4);
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKVector4 unk18;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ s32 unk2C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void CharacterDojoFX::Draw() {

}

#endif  // SPYRO_SOURCE_CHARACTERDOJOFX_H

#ifndef SPYRO_SOURCE_FOOTSTEPFX_H
#define SPYRO_SOURCE_FOOTSTEPFX_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class FootStepFX;
class FootStepFXDescriptor;
class MKMaterial;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class MKVector4;

class FootStepFX : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~FootStepFX(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void EmitFootFX(const MKVector3 &, const MKVector3 &, const MKVector3 &, MKVector4, float, float, int);
    void AddFootStep(const MKVector3 &, const MKVector3 &, const MKVector3 &, float);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ MKMaterial* unk58;
    /* 0x05c */ MKMaterial* unk5C;
    /* 0x060 */ u8 unk60;
};

class FootStepFXDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FootStepFX::~FootStepFX() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_FOOTSTEPFX_H

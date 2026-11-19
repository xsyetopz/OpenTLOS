#ifndef SPYRO_SOURCE_LOCKONTARGET_H
#define SPYRO_SOURCE_LOCKONTARGET_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class LockOnTarget;
class LockOnTargetDescriptor;
class MKMaterial;
class MKProp;
class MKPropDescriptor;

class LockOnTarget : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~LockOnTarget(void);
    virtual void Init(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 unk78;
    /* 0x079 */ u8 unk79;
};

class LockOnTargetDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ MKMaterial* unk60;
    /* 0x064 */ MKMaterial* unk64;
    /* 0x068 */ f32 unk68;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline LockOnTarget::~LockOnTarget() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
inline void LockOnTarget::Reset() {
    this->unk60 = 0;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(LockOnTarget *), 0x34)(this);
    this->unk64 = 3.0f * M2C_FIELD(checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x68);
    this->unk68 = 0.0f;
    this->unk70 = 0.0f;
    this->unk74 = 1.0f;
    this->unk4C = NULL;
}
#endif

inline void LockOnTargetDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk14 |= 0x20;
    this->unk68 = 1.0f;
}

#endif  // SPYRO_SOURCE_LOCKONTARGET_H

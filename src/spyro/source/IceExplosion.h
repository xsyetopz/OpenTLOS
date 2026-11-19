#ifndef SPYRO_SOURCE_ICEEXPLOSION_H
#define SPYRO_SOURCE_ICEEXPLOSION_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class IceExplosion;
class IceExplosionDescriptor;
class MKProp;
class MKPropDescriptor;
class MKVector3;

class IceExplosion : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~IceExplosion(void);
    virtual void * Update(void);
    virtual void Draw(void);
    void Trigger(const MKVector3 &, float);
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f32 unk60;
};

class IceExplosionDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ MKProp* unk60;
    /* 0x064 */ MKProp* unk64;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline IceExplosion::~IceExplosion() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_ICEEXPLOSION_H

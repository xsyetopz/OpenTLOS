#ifndef SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H
#define SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"

class ExpSmokeAndFlamesPS;
class ExpSmokeAndFlamesPSDescriptor;
class MKParticleSystem;
class MKPropDescriptor;
class MKVector3;

class ExpSmokeAndFlamesPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~ExpSmokeAndFlamesPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    ExpSmokeAndFlamesPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

class ExpSmokeAndFlamesPSDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x044 */ u8 pad44[0x3c];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ f32 unk84;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ExpSmokeAndFlamesPS::ExpSmokeAndFlamesPS() {
    return this;
}
#endif

inline ExpSmokeAndFlamesPS::~ExpSmokeAndFlamesPS() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
            if (temp_cr0_eq_15 == 0) {
                if (temp_cr0_eq_15 == 0) {
                }
            }
        }
    }
}

#endif  // SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H

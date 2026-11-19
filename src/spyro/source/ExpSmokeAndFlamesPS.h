#ifndef SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H
#define SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class ExpSmokeAndFlamesPS;
class ExpSmokeAndFlamesPSDescriptor;
class MKBaseParticleSystemDescriptor;
class MKParticleSystem;
class MKVector3;

class ExpSmokeAndFlamesPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~ExpSmokeAndFlamesPS(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    ExpSmokeAndFlamesPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

class ExpSmokeAndFlamesPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ExpSmokeAndFlamesPS::ExpSmokeAndFlamesPS() {
}

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

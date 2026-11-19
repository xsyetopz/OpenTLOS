#ifndef SPYRO_SOURCE_ZAPPS_H
#define SPYRO_SOURCE_ZAPPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class MKBaseParticleSystemDescriptor;
class MKParticleSystem;
class MKVector3;
class MKVector4;
class ZapPS;
class ZapPSDescriptor;

class ZapPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~ZapPS(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    ZapPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, MKVector4);
};

class ZapPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline ZapPS::ZapPS() {
}

inline ZapPS::~ZapPS() {
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

#endif  // SPYRO_SOURCE_ZAPPS_H

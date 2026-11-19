#ifndef SPYRO_SOURCE_EMBERSPS_H
#define SPYRO_SOURCE_EMBERSPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class EmbersPS;
class EmbersPSDescriptor;
class MKBaseParticleSystemDescriptor;
class MKParticleSystem;
class MKVector3;
class MKVector4;
class WindFX;

class EmbersPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~EmbersPS(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    EmbersPS(void);
    void ApplyWind(WindFX *);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, const MKVector4 &, float);
};

class EmbersPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline EmbersPS::EmbersPS() {
    return this;
}
#endif

inline EmbersPS::~EmbersPS() {
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

inline void EmbersPS::Deinit() {
    MKParticleSystem::Deinit();
}

#endif  // SPYRO_SOURCE_EMBERSPS_H

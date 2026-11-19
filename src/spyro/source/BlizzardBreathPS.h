#ifndef SPYRO_SOURCE_BLIZZARDBREATHPS_H
#define SPYRO_SOURCE_BLIZZARDBREATHPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class BlizzardBreathPS;
class BlizzardBreathPSDescriptor;
class MKBaseParticleSystemDescriptor;
class MKParticleSystem;

class BlizzardBreathPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~BlizzardBreathPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    BlizzardBreathPS(void);
};

class BlizzardBreathPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline BlizzardBreathPS::~BlizzardBreathPS() {
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

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline BlizzardBreathPS::BlizzardBreathPS() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_BLIZZARDBREATHPS_H

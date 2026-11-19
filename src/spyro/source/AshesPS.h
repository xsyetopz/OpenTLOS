#ifndef SPYRO_SOURCE_ASHESPS_H
#define SPYRO_SOURCE_ASHESPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class AshesPS;
class AshesPSDescriptor;
class MKBaseParticleSystemDescriptor;
class MKParticleSystem;

class AshesPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~AshesPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    AshesPS(void);
};

class AshesPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline AshesPS::~AshesPS() {
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
inline AshesPS::AshesPS() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ASHESPS_H

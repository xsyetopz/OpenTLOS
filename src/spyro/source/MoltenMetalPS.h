#ifndef SPYRO_SOURCE_MOLTENMETALPS_H
#define SPYRO_SOURCE_MOLTENMETALPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class MKBaseParticleSystemDescriptor;
class MKParticleSystem;
class MoltenMetalPS;
class MoltenMetalPSDescriptor;

class MoltenMetalPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~MoltenMetalPS(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    MoltenMetalPS(void);
};

class MoltenMetalPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline MoltenMetalPS::MoltenMetalPS() {
}

inline MoltenMetalPS::~MoltenMetalPS() {
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

#endif  // SPYRO_SOURCE_MOLTENMETALPS_H

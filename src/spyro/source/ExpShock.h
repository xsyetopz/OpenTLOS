#ifndef SPYRO_SOURCE_EXPSHOCK_H
#define SPYRO_SOURCE_EXPSHOCK_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class ExpShock;
class ExpShockDescriptor;
class MKBaseParticleSystemDescriptor;
class MKParticleSystem;
class MKVector3;

class ExpShock : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~ExpShock(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    ExpShock(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

class ExpShockDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ExpShock::ExpShock() {
    return this;
}
#endif

inline ExpShock::~ExpShock() {
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

#endif  // SPYRO_SOURCE_EXPSHOCK_H

#ifndef SPYRO_SOURCE_ICEBREATHSNOW_H
#define SPYRO_SOURCE_ICEBREATHSNOW_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class IceBreathSnow;
class MKParticleSystem;

class IceBreathSnow : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~IceBreathSnow(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    IceBreathSnow(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceBreathSnow::IceBreathSnow() {
    return this;
}
#endif

inline IceBreathSnow::~IceBreathSnow() {
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

#endif  // SPYRO_SOURCE_ICEBREATHSNOW_H

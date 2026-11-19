#ifndef SPYRO_SOURCE_ICEBREATHSNOWFLAKES_H
#define SPYRO_SOURCE_ICEBREATHSNOWFLAKES_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class IceBreathSnowFlakes;
class MKParticleSystem;
class MKVector3;
class WindFX;

class IceBreathSnowFlakes : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~IceBreathSnowFlakes(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    IceBreathSnowFlakes(void);
    void ApplyWind(WindFX *);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline IceBreathSnowFlakes::IceBreathSnowFlakes() {
}

inline IceBreathSnowFlakes::~IceBreathSnowFlakes() {
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

#endif  // SPYRO_SOURCE_ICEBREATHSNOWFLAKES_H

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

#endif  // SPYRO_SOURCE_ICEBREATHSNOW_H

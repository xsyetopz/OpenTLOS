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
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    IceBreathSnowFlakes(void);
    void ApplyWind(WindFX *);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

#endif  // SPYRO_SOURCE_ICEBREATHSNOWFLAKES_H

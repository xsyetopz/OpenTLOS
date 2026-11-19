#ifndef SPYRO_SOURCE_WEATHERRAINPS_H
#define SPYRO_SOURCE_WEATHERRAINPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class WeatherRainPS;

class WeatherRainPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherRainPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    WeatherRainPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

#endif  // SPYRO_SOURCE_WEATHERRAINPS_H

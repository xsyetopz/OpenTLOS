#ifndef SPYRO_SOURCE_WEATHERSNOWPS_H
#define SPYRO_SOURCE_WEATHERSNOWPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class WeatherSnowPS;

class WeatherSnowPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherSnowPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    WeatherSnowPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

#endif  // SPYRO_SOURCE_WEATHERSNOWPS_H

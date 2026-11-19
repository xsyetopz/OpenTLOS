#ifndef SPYRO_SOURCE_WEATHERASHPS_H
#define SPYRO_SOURCE_WEATHERASHPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class WeatherAshPS;

class WeatherAshPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherAshPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    WeatherAshPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

#endif  // SPYRO_SOURCE_WEATHERASHPS_H

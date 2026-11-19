#ifndef SPYRO_SOURCE_WEATHERSPORES_H
#define SPYRO_SOURCE_WEATHERSPORES_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class WeatherSporesPS;

class WeatherSporesPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherSporesPS(void);
    virtual void Init(void);
    virtual void UpdateParticles(void);
    WeatherSporesPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

#endif  // SPYRO_SOURCE_WEATHERSPORES_H

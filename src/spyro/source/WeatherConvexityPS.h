#ifndef SPYRO_SOURCE_WEATHERCONVEXITYPS_H
#define SPYRO_SOURCE_WEATHERCONVEXITYPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class WeatherConvexityPS;

class WeatherConvexityPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherConvexityPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    WeatherConvexityPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

#endif  // SPYRO_SOURCE_WEATHERCONVEXITYPS_H

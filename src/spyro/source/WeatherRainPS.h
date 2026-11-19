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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline WeatherRainPS::WeatherRainPS() {
    return this;
}
#endif

inline WeatherRainPS::~WeatherRainPS() {
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

#endif  // SPYRO_SOURCE_WEATHERRAINPS_H

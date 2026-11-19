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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WeatherSporesPS::WeatherSporesPS() {
}

inline WeatherSporesPS::~WeatherSporesPS() {
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

#endif  // SPYRO_SOURCE_WEATHERSPORES_H

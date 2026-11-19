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
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    WeatherAshPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline WeatherAshPS::WeatherAshPS() {
}

inline WeatherAshPS::~WeatherAshPS() {
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

#endif  // SPYRO_SOURCE_WEATHERASHPS_H

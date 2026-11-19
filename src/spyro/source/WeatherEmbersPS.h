#ifndef SPYRO_SOURCE_WEATHEREMBERSPS_H
#define SPYRO_SOURCE_WEATHEREMBERSPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class WeatherEmbersPS;

class WeatherEmbersPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~WeatherEmbersPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    WeatherEmbersPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline WeatherEmbersPS::WeatherEmbersPS() {
    return this;
}
#endif

inline WeatherEmbersPS::~WeatherEmbersPS() {
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

#endif  // SPYRO_SOURCE_WEATHEREMBERSPS_H

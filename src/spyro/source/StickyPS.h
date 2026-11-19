#ifndef SPYRO_SOURCE_STICKYPS_H
#define SPYRO_SOURCE_STICKYPS_H

#include <dolphin/types.h>
#include "spyro/source/KDParticleSystem.h"

class KDEnvParticleSystem;
class MKVector3;
class StickyPS;

class StickyPS : public KDEnvParticleSystem {  // base: base ctor call
public:
    virtual ~StickyPS(void);
    virtual void UpdateParticles(void);
    StickyPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, float, float);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline StickyPS::StickyPS() {
    return this;
}
#endif

inline StickyPS::~StickyPS() {
}

#endif  // SPYRO_SOURCE_STICKYPS_H

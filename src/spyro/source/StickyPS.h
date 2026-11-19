#ifndef SPYRO_SOURCE_STICKYPS_H
#define SPYRO_SOURCE_STICKYPS_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"

class MKBaseParticleSystem;
class MKVector3;
class StickyPS;

class StickyPS : public MKBaseParticleSystem {  // base: vtable prefix
public:
    virtual ~StickyPS(void);
    virtual void UpdateParticles(void);
    StickyPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, float, float);
    /* 0x0e4 */ u8 padE4[0x10];
    /* 0x0f4 */ f32 unkF4;
};

#endif  // SPYRO_SOURCE_STICKYPS_H

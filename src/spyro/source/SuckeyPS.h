#ifndef SPYRO_SOURCE_SUCKEYPS_H
#define SPYRO_SOURCE_SUCKEYPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"

class MKParticleSystem;
class MKVector3;
class SuckeyPS;

class SuckeyPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~SuckeyPS(void);
    virtual void Init(void);
    virtual void UpdateParticles(void);
    SuckeyPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, float);
    /* 0x138 */ u8 pad138[0x8];
    /* 0x140 */ s32 unk140;
};

#endif  // SPYRO_SOURCE_SUCKEYPS_H

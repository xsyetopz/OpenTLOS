#ifndef SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H
#define SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"

class ExpSmokeAndFlamesPS;
class ExpSmokeAndFlamesPSDescriptor;
class MKParticleSystem;
class MKPropDescriptor;
class MKVector3;

class ExpSmokeAndFlamesPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~ExpSmokeAndFlamesPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    ExpSmokeAndFlamesPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

class ExpSmokeAndFlamesPSDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x38];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ f32 unk84;
};

#endif  // SPYRO_SOURCE_EXPSMOKEANDFLAMESPS_H

#ifndef SPYRO_SOURCE_FLAMEBREATHPS_H
#define SPYRO_SOURCE_FLAMEBREATHPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"

class FlameBreathPS;
class FlameBreathPSDescriptor;
class MKParticleSystem;
class MKPropDescriptor;
class MKVector3;

class FlameBreathPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~FlameBreathPS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    FlameBreathPS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

class FlameBreathPSDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x38];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ f32 unk84;
};

#endif  // SPYRO_SOURCE_FLAMEBREATHPS_H

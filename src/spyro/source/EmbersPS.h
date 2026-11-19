#ifndef SPYRO_SOURCE_EMBERSPS_H
#define SPYRO_SOURCE_EMBERSPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"

class EmbersPS;
class EmbersPSDescriptor;
class MKParticleSystem;
class MKPropDescriptor;
class MKVector3;
class MKVector4;
class WindFX;

class EmbersPS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~EmbersPS(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    EmbersPS(void);
    void ApplyWind(WindFX *);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, const MKVector4 &, float);
};

class EmbersPSDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x38];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ f32 unk84;
};

#endif  // SPYRO_SOURCE_EMBERSPS_H

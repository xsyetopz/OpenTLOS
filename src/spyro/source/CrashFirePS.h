#ifndef SPYRO_SOURCE_CRASHFIREPS_H
#define SPYRO_SOURCE_CRASHFIREPS_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"

class CrashFirePS;
class CrashFirePSDescriptor;
class MKParticleSystem;
class MKPropDescriptor;
class MKVector3;

class CrashFirePS : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~CrashFirePS(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void UpdateParticles(void);
    CrashFirePS(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &);
};

class CrashFirePSDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x38];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ f32 unk84;
};

#endif  // SPYRO_SOURCE_CRASHFIREPS_H

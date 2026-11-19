#ifndef SPYRO_SOURCE_FALLINGLEAVES_H
#define SPYRO_SOURCE_FALLINGLEAVES_H

#include <dolphin/types.h>
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"

class FallingLeaves;
class FallingLeavesDescriptor;
class FallingLeaves_cpp;
class MKMessage;
class MKParticleSystem;
class MKPropDescriptor;
class MKVector3;
class WindFX;

class FallingLeaves : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~FallingLeaves(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void UpdateParticles(void);
    FallingLeaves(void);
    void AddForce(const MKVector3 &, const float &, const float &);
    void ApplyWind(WindFX *);
    void SpawnGround(const MKVector3 &);
    void Emit(void);
    void Emit(const MKVector3 &, const MKVector3 &, const float &, const int &, bool);
    /* 0x138 */ u8 pad138[0x8];
    /* 0x140 */ f64 unk140;
    /* 0x148 */ f64 unk148;
    /* 0x150 */ u8 pad150[0x90];
    /* 0x1e0 */ s8 unk1E0;
    /* 0x1e1 */ u8 unk1E1;
};

class FallingLeavesDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
};

class FallingLeaves_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_FALLINGLEAVES_H

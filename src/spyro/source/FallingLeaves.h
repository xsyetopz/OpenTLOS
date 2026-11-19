#ifndef SPYRO_SOURCE_FALLINGLEAVES_H
#define SPYRO_SOURCE_FALLINGLEAVES_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKParticleSystem.h"

class FallingLeaves;
class FallingLeavesDescriptor;
class FallingLeaves_cpp;
class MKBaseParticleSystemDescriptor;
class MKMessage;
class MKParticleSystem;
class MKVector3;
class WindFX;

class FallingLeaves : public MKParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~FallingLeaves(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
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

class FallingLeavesDescriptor : public MKBaseParticleSystemDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

class FallingLeaves_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FallingLeaves::FallingLeaves() {
}

inline FallingLeaves::~FallingLeaves() {
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

#endif  // SPYRO_SOURCE_FALLINGLEAVES_H

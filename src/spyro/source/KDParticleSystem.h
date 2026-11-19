#ifndef SPYRO_SOURCE_KDPARTICLESYSTEM_H
#define SPYRO_SOURCE_KDPARTICLESYSTEM_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"

class KDEnvParticleSystem;
class KDEnvParticleSystemDescriptor;
class KDParticleSystem;
class KDParticleSystemDescriptor;
class MKBaseParticleSystem;
class MKBaseParticleSystemDescriptor;
class MKIniLine;
class MKParticle;
class MKVector3;

class KDParticleSystem : public MKBaseParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~KDParticleSystem(void);
    virtual void Init(void);
    virtual void * GetName(void);
    virtual void UpdateParticles(void);
    void KDConfigureSystemData(KDParticleSystem *, MKParticle *);
    /* 0x0e8 */ u8 padE8[0xc];
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ s32 unkF8;
};

class KDEnvParticleSystem : public KDParticleSystem {  // base: ctor/dtor vtable stores
public:
    virtual ~KDEnvParticleSystem(void);
    virtual void Init(void);
    virtual void * GetName(void);
    virtual void UpdateParticles(void);
    KDEnvParticleSystem(void);
    void KDEnvConfigureSystemData(KDParticleSystem *, MKParticle *);
};

class KDParticleSystemDescriptor : public MKBaseParticleSystemDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Update(void);
    /* 0x088 */ u8 pad88[0x8];
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ MKVector3 unkA0;
    /* 0x0b0 */ MKVector3 unkB0;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
};

class KDEnvParticleSystemDescriptor : public KDParticleSystemDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    KDEnvParticleSystemDescriptor(void);
    void CalculateEnvelope(void);
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ void* unkD4;
    /* 0x0d8 */ u8 unkD8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline KDEnvParticleSystem::KDEnvParticleSystem() {
}

inline KDEnvParticleSystem::~KDEnvParticleSystem() {
    s32 temp_cr0_eq_9982;

    temp_cr0_eq_9982 = this == NULL;
    if (temp_cr0_eq_9982 == 0) {
        if (temp_cr0_eq_9982 == 0) {
            if (temp_cr0_eq_9982 == 0) {
                if (temp_cr0_eq_9982 == 0) {
                }
            }
        }
    }
}

inline void *KDEnvParticleSystem::GetName() {

}

inline KDEnvParticleSystemDescriptor::KDEnvParticleSystemDescriptor() {
}

inline KDParticleSystem::~KDParticleSystem() {
    s32 temp_cr0_eq_8259;

    temp_cr0_eq_8259 = this == NULL;
    if (temp_cr0_eq_8259 == 0) {
        if (temp_cr0_eq_8259 == 0) {
            if (temp_cr0_eq_8259 == 0) {
            }
        }
    }
}

inline void *KDParticleSystem::GetName() {
    return (void *) ("KDParticles");
}

#endif  // SPYRO_SOURCE_KDPARTICLESYSTEM_H

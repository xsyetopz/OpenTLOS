#ifndef COMMON_SOURCE_MKBASEPARTICLESYSTEM_H
#define COMMON_SOURCE_MKBASEPARTICLESYSTEM_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class AssaultCannon;
class MKBaseParticleSystem;
class MKBaseParticleSystemDescriptor;
class MKMessage;
class MKParticleChunk;
class MKProp;
class MKPropDescriptor;
class MKVector4;
class Matrix;

class MKBaseParticleSystem : public MKProp {  // base: ctor/dtor vtable stores
public:
    class ParticleRec;
    virtual ~MKBaseParticleSystem(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void GetName(void) = 0;
    virtual void * CreateParticle(void);
    virtual void EmitParticles(void);
    virtual void UpdateParticles(void) = 0;
    virtual s32 OnTimeOut(void);
    void DrawChunk(Matrix *, MKVector4 *, MKParticleChunk *);
    void InitDraw(Matrix *, MKVector4 *);
    MKParticleChunk * GetNextParticle(MKBaseParticleSystem::ParticleRec *);
    MKParticleChunk * GetFirstParticle(MKBaseParticleSystem::ParticleRec *);
    void DestroyAllParticles(void);
    MKParticleChunk * DestroyParticle(MKBaseParticleSystem::ParticleRec *);
    void * AllocateParticle(void);
    void Draw(Matrix *, MKVector4 *);
    void PostUpdate(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ Matrix unk60;
};

class MKBaseParticleSystemDescriptor : public MKPropDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ s32 unk80;
    /* 0x084 */ f32 unk84;
};

class MKMessage {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ void** unkC;
    /* 0x010 */ u8 pad10[0x24];
    /* 0x034 */ AssaultCannon*** unk34;
};

class MKParticleChunk {
public:
    /* 0x000 */ MKParticleChunk* unk0;
    /* 0x004 */ u8 pad4[0x47c];
    /* 0x480 */ s32 unk480;
    /* 0x484 */ u8 pad484[0x600];
    /* 0xa84 */ s32 unkA84;
    /* 0xa88 */ MKParticleChunk* unkA88;
    /* 0xa8c */ MKParticleChunk* unkA8C;
};

void MKParticleSystem_FreeChunk(MKParticleChunk *);
MKParticleChunk * MKParticleSystem_AllocChunk(int);
void MKParticleSystem_DeinitModule(void);
void MKParticleSystem_InitModule(int);
#endif  // COMMON_SOURCE_MKBASEPARTICLESYSTEM_H

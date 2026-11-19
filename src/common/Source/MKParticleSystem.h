#ifndef COMMON_SOURCE_MKPARTICLESYSTEM_H
#define COMMON_SOURCE_MKPARTICLESYSTEM_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"

class MKBaseParticleSystem;
class MKParticleChunk;
class MKParticleSystem;

class MKParticleChunk {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ void* unk2C;
};

class MKParticleSystem : public MKBaseParticleSystem {  // base: ctor/dtor vtable stores
public:
    class Envelope;
    virtual ~MKParticleSystem(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void GetName(void);
    virtual void * CreateParticle(void);
    virtual void UpdateParticles(void);
    virtual void * HitFloor(MKBaseParticleSystem::ParticleRec *, bool *);
    void SetMaxParticleAge(float);
    void CalculateEnvelope(void);
    void SetEnvelope(MKParticleSystem::Envelope *, int);
    /* 0x0e4 */ u8 padE4[0xc];
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ u8 unkF4;
    /* 0x0f5 */ u8 padF5[0x3];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ u8 pad104[0x4];
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ u8 pad114[0x4];
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ f32 unk12C;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ MKParticleSystem::Envelope* unk134;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void MKParticleSystem::GetName() {

}

inline MKParticleSystem::~MKParticleSystem() {
    s32 temp_cr0_eq_7354;

    temp_cr0_eq_7354 = this == NULL;
    if (temp_cr0_eq_7354 == 0) {
        if (temp_cr0_eq_7354 == 0) {
            if (temp_cr0_eq_7354 == 0) {
            }
        }
    }
}

#endif  // COMMON_SOURCE_MKPARTICLESYSTEM_H

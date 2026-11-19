#ifndef SPYRO_SOURCE_KDPARTICLEEMITTER_H
#define SPYRO_SOURCE_KDPARTICLEEMITTER_H

#include <dolphin/types.h>

class KDParticleBoxEmitter;
class KDParticleEmitter;
class KDParticleLineEmitter;
class MKBaseParticleSystem;
class MKIniLine;
class MKParticle;
class MKVector3;
class Matrix;

class KDParticleEmitter {
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    void InitPointParticleParameters(KDParticleEmitter *, MKParticle *);
    void InitPointParticlePosition(KDParticleEmitter *, MKParticle *);
    void Emit(int, MKVector3 *);
    void Burst(void);
    void Update(void);
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ MKBaseParticleSystem* unk28;
    /* 0x02c */ void* unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 pad41[0xb];
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ f64* unk6C;
    /* 0x070 */ Matrix* unk70;
};

class KDParticleBoxEmitter : public KDParticleEmitter {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual ~KDParticleBoxEmitter(void);
    void InitBoxParticlePostion(KDParticleEmitter *, MKParticle *);
};

class KDParticleLineEmitter : public KDParticleEmitter {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual ~KDParticleLineEmitter(void);
    void InitLineParticlePostion(KDParticleEmitter *, MKParticle *);
    /* 0x078 */ s32 unk78;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline KDParticleBoxEmitter::~KDParticleBoxEmitter() {
}

inline KDParticleLineEmitter::~KDParticleLineEmitter() {
}

#endif  // SPYRO_SOURCE_KDPARTICLEEMITTER_H

#ifndef SPYRO_SOURCE_ELECTRICFENCE_H
#define SPYRO_SOURCE_ELECTRICFENCE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"

class ElectricFence;
class ElectricFenceDescriptor;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;

class ElectricFence : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElectricFence(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void AllocBeams(void);
    void FreeBeams(void);
    void EnableFenceCollision(bool);
    /* 0x04c */ void* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ u8 unk54;
    /* 0x055 */ u8 pad55[0x4b];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f64 unkB0;
    /* 0x0b8 */ f64 unkB8;
    /* 0x0c0 */ f64 unkC0;
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ u8 padD0[0x30];
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ MKSceneManager* unk110;
    /* 0x114 */ s32 unk114;
};

class ElectricFenceDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    /* 0x044 */ u8 pad44[0x24];
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline ElectricFence::~ElectricFence() {
    if ((&this->unk114 != NULL) && (&this->unk114 != NULL)) {
        KDSound_Stop(&this->unk114);
    }
    if (this != NULL) {
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
inline void ElectricFenceDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk68 = M2C_FIELD(&zero, f64 *, 8);
    this->unk70 = M2C_FIELD(&zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&zero, f64 *, 8);
    this->unk1C = (BoundingVolume *) &this->unk60;
    this->unk84 = 0;
    this->unk8C = 0.25f;
    this->unk90 = 0.25f;
    this->unk88 = 0;
}
#endif

#endif  // SPYRO_SOURCE_ELECTRICFENCE_H

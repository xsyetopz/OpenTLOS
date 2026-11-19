#ifndef SPYRO_SOURCE_SQUISHBOULDER_H
#define SPYRO_SOURCE_SQUISHBOULDER_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shatterable.h"

class BreathHitMessage;
class MKMessage;
class MKProp;
class MKVector3;
class Matrix;
class PooledShatterProp;
class ShatterableDescriptor;
class SquishBoulder;
class SquishBoulderDescriptor;

class SquishBoulder : public PooledShatterProp {  // base: base ctor call
public:
    virtual ~SquishBoulder(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    SquishBoulder(void);
    void EmitLandingEffects(void);
    void Trigger(const MKVector3 &, const MKVector3 &, float, MKProp *);
    /* 0x1a8 */ MKProp* unk1A8;
    /* 0x1ac */ u8 pad1AC[0x4];
    /* 0x1b0 */ f64 unk1B0;
    /* 0x1b8 */ f64 unk1B8;
    /* 0x1c0 */ f64 unk1C0;
    /* 0x1c8 */ f64 unk1C8;
    /* 0x1d0 */ f32 unk1D0;
    /* 0x1d4 */ s32 unk1D4;
    /* 0x1d8 */ s32 unk1D8;
    /* 0x1dc */ u8 pad1DC[0x24];
    /* 0x200 */ BreathHitMessage unk200;
    /* 0x254 */ u8 pad254[0x8];
    /* 0x25c */ u8 unk25C;
    /* 0x25d */ u8 pad25D[0x3];
    /* 0x260 */ Matrix unk260;
};

class SquishBoulderDescriptor : public ShatterableDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    SquishBoulderDescriptor(void);
    /* 0x170 */ void* unk170;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SquishBoulder::SquishBoulder() {
    this->unkC8 = &__vt + 0x48;
    this->unk1D8 = 0;
    this->unk200.unk4 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SquishBoulder::~SquishBoulder() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk1D8 != NULL) && (&this->unk1D8 != NULL)) {
        KDSound_Stop((int *) &this->unk1D8);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SquishBoulderDescriptor::SquishBoulderDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SQUISHBOULDER_H

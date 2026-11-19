#ifndef SPYRO_SOURCE_SQUISHBOULDER_H
#define SPYRO_SOURCE_SQUISHBOULDER_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/Shatterable.h"

class BreathHitMessage;
class MKMessage;
class MKProp;
class MKVector3;
class Matrix;
class Shatterable;
class ShatterableDescriptor;
class SquishBoulder;
class SquishBoulderDescriptor;

class SquishBoulder : public Shatterable {  // base: vtable prefix
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
    /* 0x1a3 */ u8 pad1A3[0x5];
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
    /* 0x251 */ u8 pad251[0xf];
    /* 0x260 */ Matrix unk260;
};

class SquishBoulderDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    SquishBoulderDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ void* unk170;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SquishBoulder::SquishBoulder() {
    this->unkC8 = &__vt + 0x48;
    M2C_FIELD(this, s32 *, 0x1D8) = 0;
    this->unk204 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline SquishBoulder::~SquishBoulder() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk1C8 != NULL) && (&this->unk1C8 != NULL)) {
        KDSound_Stop((s32 *) &this->unk1C8);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SquishBoulderDescriptor::SquishBoulderDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SQUISHBOULDER_H

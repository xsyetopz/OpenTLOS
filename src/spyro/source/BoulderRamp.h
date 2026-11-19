#ifndef SPYRO_SOURCE_BOULDERRAMP_H
#define SPYRO_SOURCE_BOULDERRAMP_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/Trap.h"

class Ball;
class BoulderRamp;
class BoulderRampDescriptor;
class BoulderRamp_cpp;
class MKIniLine;
class Matrix;
class Trap;
class TrapDescriptor;

class BoulderRamp : public Trap {  // base: base ctor call
public:
    class State;
    virtual ~BoulderRamp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void * Update(void);
    BoulderRamp(void);
    void BoulderSinkingExit(void);
    void BoulderSinkingUpdate(void);
    void BoulderSinkingEnter(void);
    void ReceivingBoulderUpdate(void);
    void ReceivingBoulderEnter(void);
    void SetBoulder(Ball *);
    s32 HasBoulder(void);
    void SetState(BoulderRamp::State);
    static u8 states[0x90];
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ u32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ Ball* unkF0;
    /* 0x0f4 */ Matrix unkF4;
};

class BoulderRampDescriptor : public TrapDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    BoulderRampDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
};

class BoulderRamp_cpp {
public:
    void __sinit(void);
};

s32 BoulderRamp_GetCatapult(int, int);
s32 BoulderRamp_GetMaxPerGroup(void);
void BoulderRamp_InitModule(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline BoulderRamp::~BoulderRamp() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
    if (&this->unkF4.unk14 != NULL) {
        ((EventMessage *) &this->unkF4.unk14)->Deinit();
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline BoulderRamp::BoulderRamp() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
    this->unkF4.unk0 = 0.0f;
    this->unkF4.unk4 = 0.0f;
    this->unkF4.unk8 = 0.0f;
    this->unkF4.unkC = 0.0f;
    this->unkF4.unk14 = 0.0f;
    ((EventMessage *) &this->unkF4.unk14)->Init();
    this->unkF4.unk18 = nanf;
    this->unkF4.unk1C = nanf;
    this->unkF4.unk20 = 0.0f;
    this->unkF4.unk24 = 0.0f;
}
#endif

inline BoulderRampDescriptor::BoulderRampDescriptor() {
}

#endif  // SPYRO_SOURCE_BOULDERRAMP_H

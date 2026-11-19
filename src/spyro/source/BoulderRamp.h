#ifndef SPYRO_SOURCE_BOULDERRAMP_H
#define SPYRO_SOURCE_BOULDERRAMP_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class Ball;
class BoulderRamp;
class BoulderRampDescriptor;
class BoulderRamp_cpp;
class KDPropExDescriptor;
class MKIniLine;
class Matrix;
class Trap;

class BoulderRamp : public Trap {  // base: vtable prefix
public:
    class State;
    virtual ~BoulderRamp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
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

class BoulderRampDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    BoulderRampDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
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

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BoulderRamp::~BoulderRamp() {
    this->unkC8 = &__vt.unk48;
    if (&this->unkF4.unk10 != NULL) {
        this->unkF4.unk10.Deinit();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline BoulderRamp::BoulderRamp() {
    this->unkC8 = &__vt + 0x48;
    this->unkF0 = NULL;
    this->unkF4.unk0 = 0.0f;
    this->unkF4.unk4 = 0.0f;
    this->unkF4.unk8 = 0.0f;
    this->unkF4.unk10 = 0.0f;
    this->unkF4.unk10.Init();
    this->unkF4.unk14 = nanf;
    this->unkF4.unk18 = nanf;
    this->unkF4.unk1C = 0.0f;
    this->unkF4.unk20 = 0.0f;
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline BoulderRampDescriptor::BoulderRampDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_BOULDERRAMP_H

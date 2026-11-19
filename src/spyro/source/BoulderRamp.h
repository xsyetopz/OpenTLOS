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
#endif  // SPYRO_SOURCE_BOULDERRAMP_H

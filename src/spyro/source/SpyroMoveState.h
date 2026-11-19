#ifndef SPYRO_SOURCE_SPYROMOVESTATE_H
#define SPYRO_SOURCE_SPYROMOVESTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroAnimTables.h"
#include "spyro/source/SpyroState.h"

class Spyro;
class SpyroBreatheAnimTable;
class SpyroMoveState;
class SpyroMoveState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroMoveState : public SpyroState {  // base: vtable prefix
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual u8 Transition(void);
    virtual void GetStateInfo(void);
    s32 RunTransition(void);
    void RunUpdate(void);
    void RunDeinit(void);
    void RunInit(void);
    s32 WalkTransition(void);
    void WalkUpdate(void);
    void WalkDeinit(void);
    void WalkInit(void);
    u8 SelectState(float);
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ u8 pad14[0x14];
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ SpyroBreatheAnimTable unk38;
    /* 0x040 */ SpyroBreatheAnimTable unk40;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 unk51;
    /* 0x052 */ u8 pad52[0x2];
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f64 unk60;
};

class SpyroMoveState_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPYROMOVESTATE_H

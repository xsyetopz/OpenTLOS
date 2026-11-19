#ifndef SPYRO_SOURCE_SPYROIDLESTATE_H
#define SPYRO_SOURCE_SPYROIDLESTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroAnimTables.h"
#include "spyro/source/SpyroState.h"

class MKMessage;
class Spyro;
class SpyroIdleAnimTable;
class SpyroIdleState;
class SpyroIdleState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroIdleState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void Message(MKMessage *);
    virtual void * GetStateInfo(void);
    u8 AnyToBreathingTranistion(void);
    u8 Breathing2Transition(void);
    void Breathing2Update(void);
    void Breathing2Exit(void);
    void Breathing2Enter(void);
    s32 BreathingTransition(void);
    void BreathingUpdate(void);
    void BreathingExit(void);
    void BreathingEnter(void);
    s32 OneOffIdleTransition(void);
    void OneOffIdleUpdate(void);
    void OneOffIdleExit(void);
    void OneOffIdleEnter(void);
    void SelectAnimation(void);
    u8 SlideTransition(void);
    void SlideUpdate(void);
    void SlideExit(void);
    void SlideEnter(void);
    void NormalTransition(void);
    void NormalUpdate(void);
    void NormalExit(void);
    void NormalEnter(void);
    static SpyroIdleState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroIdleState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ SpyroIdleAnimTable unk30;
    /* 0x034 */ u8 pad34[0x8];
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ u8 unk44;
    /* 0x045 */ u8 pad45[0x3];
    /* 0x048 */ s32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 unk5C;
    /* 0x05d */ u8 unk5D;
};

class SpyroIdleState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void *SpyroIdleState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROIDLESTATE_H

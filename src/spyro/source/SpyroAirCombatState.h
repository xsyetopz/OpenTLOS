#ifndef SPYRO_SOURCE_SPYROAIRCOMBATSTATE_H
#define SPYRO_SOURCE_SPYROAIRCOMBATSTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroState.h"

class MKMessage;
class Spyro;
class SpyroAirCombatState;
class SpyroAirCombatState_cpp;
class SpyroState;
class SpyroStateMessages;
class Targetable;

class SpyroAirCombatState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void ProcessAnimEvent(unsigned int);
    virtual void Message(MKMessage *);
    virtual void * GetStateInfo(void);
    void EnableSmoothBehindCamera(bool);
    void EnableSlowMoCamera(bool);
    void EnableProtoSlowMotion(void);
    u8 CanEnableProtoSlowMotion(void);
    void EnableSlowMotion(bool);
    void TryEnableKillingBlowSlowMotion(void);
    void UpdateTailSweepStickToTarget(void);
    Targetable * SelectNewTarget(void);
    void UpdateAirStrafe(void);
    s32 HornDiveHitTransition(void);
    void HornDiveHitUpdate(void);
    void HornDiveHitExit(void);
    void HornDiveHitEnter(void);
    u8 HornDiveAttackTransition(void);
    void HornDiveAttackUpdate(void);
    void HornDiveAttackExit(void);
    void HornDiveAttackEnter(void);
    u8 HornDiveChargeUpTransition(void);
    void HornDiveChargeUpUpdate(void);
    void HornDiveChargeUpExit(void);
    void HornDiveChargeUpEnter(void);
    u8 KnockdownTransition(void);
    void KnockdownUpdate(void);
    void KnockdownExit(void);
    void KnockdownEnter(void);
    void JuggleTransition(void);
    void JuggleUpdate(void);
    void JuggleExit(void);
    void JuggleEnter(void);
    void LaunchTransition(void);
    void LaunchUpdate(void);
    void LaunchExit(void);
    void LaunchEnter(void);
    void TailSweepComboTransition(void);
    void TailSweepComboUpdate(void);
    void TailSweepComboExit(void);
    void TailSweepComboEnter(void);
    void TailSweepUpdate(void);
    void TailSweepExit(void);
    void TailSweepEnter(void);
    static SpyroAirCombatState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroAirCombatState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s8 unk30;
    /* 0x031 */ u8 unk31;
    /* 0x032 */ u8 unk32;
    /* 0x033 */ u8 unk33;
    /* 0x034 */ u8 unk34;
    /* 0x035 */ u8 unk35;
    /* 0x036 */ u8 unk36;
    /* 0x037 */ u8 unk37;
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 pad39[0x3];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 unk41;
    /* 0x042 */ u8 unk42;
    /* 0x043 */ u8 unk43;
};

class SpyroAirCombatState_cpp {
public:
    void __sinit(void);
};

extern u8 bAirCombatSlowMo[0x1];
extern u8 HornDiveZSpeed[0x4];
extern u8 HornDiveYSpeed[0x4];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void *SpyroAirCombatState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROAIRCOMBATSTATE_H

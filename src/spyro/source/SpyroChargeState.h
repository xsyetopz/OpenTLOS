#ifndef SPYRO_SOURCE_SPYROCHARGESTATE_H
#define SPYRO_SOURCE_SPYROCHARGESTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroState.h"

class MKMessage;
class Spyro;
class SpyroChargeState;
class SpyroChargeState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroChargeState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void ProcessAnimEvent(unsigned int);
    virtual void Message(MKMessage *);
    virtual void GetStateInfo(void);
    void ChargeTransition(void);
    void ChargeUpdate(void);
    void ChargeExit(void);
    void ChargeEnter(void);
    s32 PostHornDiveTransition(void);
    void PostHornDiveUpdate(void);
    void PostHornDiveExit(void);
    void PostHornDiveEnter(void);
    u8 InitialChargeTransition(void);
    void InitialChargeUpdate(void);
    void InitialChargeExit(void);
    void InitialChargeEnter(void);
    static SpyroChargeState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroChargeState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
};

class SpyroChargeState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void SpyroChargeState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROCHARGESTATE_H

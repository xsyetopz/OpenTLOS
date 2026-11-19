#ifndef SPYRO_SOURCE_SPYROCHARGESTATE_H
#define SPYRO_SOURCE_SPYROCHARGESTATE_H

#include <dolphin/types.h>

class MKMessage;
class Spyro;
class SpyroChargeState;
class SpyroChargeState_cpp;
class SpyroStateMessages;

class SpyroChargeState {
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual u8 Transition(void);
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
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ u8 pad14[0x14];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
};

class SpyroChargeState_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPYROCHARGESTATE_H

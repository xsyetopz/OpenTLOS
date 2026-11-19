#ifndef SPYRO_SOURCE_SPYROSTRAFESTATE_H
#define SPYRO_SOURCE_SPYROSTRAFESTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroState.h"

class KDInput;
class MKMessage;
class Spyro;
class SpyroState;
class SpyroStateMessages;
class SpyroStrafeState;
class SpyroStrafeState_cpp;

class SpyroStrafeState : public SpyroState {  // base: inlined ctor vtable stores
public:
    class InputOverride {
    public:
        void Set(KDInput *);
    };
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void ProcessAnimEvent(unsigned int);
    virtual void Message(MKMessage *);
    virtual void * GetStateInfo(void);
    void SetDesiredVelocity(void);
    void UpdateCircleTargetMovement(void);
    void SelectAnim(void);
    u8 AnyToDodgeTranstion(void);
    u8 DodgeForwardBackTransition(void);
    void DodgeForwardBackUpdate(void);
    void DodgeForwardBackExit(void);
    void DodgeForwardBackEnter(void);
    u8 DodgeLeftRightTransition(void);
    void DodgeLeftRightUpdate(void);
    void DodgeLeftRightExit(void);
    void DodgeLeftRightEnter(void);
    void CircleTargetTransition(void);
    void CircleTargetUpdate(void);
    void CircleTargetExit(void);
    void CircleTargetEnter(void);
    void NoTargetTransition(void);
    void NoTargetUpdate(void);
    void NoTargetExit(void);
    void NoTargetEnter(void);
    static SpyroStrafeState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroStrafeState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 pad39[0x3];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
};

class SpyroStrafeState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void *SpyroStrafeState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROSTRAFESTATE_H

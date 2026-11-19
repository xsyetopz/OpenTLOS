#ifndef SPYRO_SOURCE_SPYROCYNDERSTRAFESTATE_H
#define SPYRO_SOURCE_SPYROCYNDERSTRAFESTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroAnimTables.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"

class MKMessage;
class MKVector3;
class Spyro;
class SpyroCynderStrafeState;
class SpyroCynderStrafeState_cpp;
class SpyroStartCycleAnimTable;
class SpyroState;
class SpyroStateMessages;
class SpyroStuck;

class SpyroCynderStrafeState : public SpyroState {  // base: inlined ctor vtable stores
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
    void Landed(bool);
    static s32 JumpLoftTransition(void);
    void JumpLoftUpdate(void);
    void JumpLoftExit(void);
    void JumpLoftEnter(void);
    s32 JumpCycleTransition(void);
    void JumpCycleUpdate(void);
    void JumpCycleExit(void);
    void JumpCycleEnter(void);
    u8 JumpStartTransition(void);
    void JumpStartUpdate(void);
    void JumpStartExit(void);
    void JumpStartEnter(void);
    void AnyStateEnter(void);
    u8 FallTransition(void);
    void FallUpdate(void);
    void FallExit(void);
    void FallEnter(void);
    u8 JumpTransition(void);
    void JumpUpdate(void);
    void JumpExit(void);
    void JumpEnter(void);
    u8 AnyToDodgeTranstion(void);
    void DodgeLeftRightSetLVEScale(void);
    u8 DodgeLeftRightTransition(void);
    void DodgeLeftRightUpdate(void);
    void DodgeLeftRightExit(void);
    void DodgeLeftRightEnter(void);
    u8 NoTargetTransition(void);
    void NoTargetUpdate(void);
    void NoTargetExit(void);
    void NoTargetEnter(void);
    void SelectAnim(void);
    u8 ClampVelocity(void);
    MKVector3 GetMoveVelocityHorz(void);
    void SetDesiredVelocityHorz(void);
    void ClampMovementUpdate(void);
    static u8 states[0x90];
    static u8 jumpStates[0x6c];
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ KDStateMachine<SpyroCynderStrafeState> unk18;
    /* 0x019 */ u8 pad19[0x7];
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x8];
    /* 0x064 */ u8 unk64;
    /* 0x065 */ u8 unk65;
    /* 0x066 */ u8 pad66[0x2];
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ u32* unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ SpyroStartCycleAnimTable unk7C;
    /* 0x084 */ u8 pad84[0x4];
    /* 0x088 */ SpyroStuck unk88;
};

class SpyroCynderStrafeState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void *SpyroCynderStrafeState::GetStateInfo() {
    this->unk18.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROCYNDERSTRAFESTATE_H

#ifndef SPYRO_SOURCE_SPYROJUMPSTATE_H
#define SPYRO_SOURCE_SPYROJUMPSTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroState.h"

class Spyro;
class SpyroJumpState;
class SpyroJumpState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroJumpState : public SpyroState {  // base: vtable prefix
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual u8 Transition(void);
    virtual void GetStateInfo(void);
    void SetStrafeJump(bool);
    s32 DoubleJumpTransition(void);
    void DoubleJumpUpdate(void);
    void DoubleJumpExit(void);
    void DoubleJumpEnter(void);
    void JumpCommonUpdate(void);
    s32 JumpLoftTransition(void);
    void JumpLoftUpdate(void);
    void JumpLoftExit(void);
    void JumpLoftEnter(void);
    u8 JumpCycleTransition(void);
    void JumpCycleUpdate(void);
    void JumpCycleExit(void);
    void JumpCycleEnter(void);
    u8 JumpStartTransition(void);
    void JumpStartUpdate(void);
    void JumpStartExit(void);
    void JumpStartEnter(void);
    void GetJumpVel(void);
    static SpyroJumpState states;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ u8 pad18[0x14];
    /* 0x02c */ u8 unk2C;
    /* 0x02d */ u8 unk2D;
    /* 0x02e */ u8 unk2E;
    /* 0x02f */ u8 unk2F;
    /* 0x030 */ u8 unk30;
    /* 0x031 */ u8 pad31[0x3];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 pad40[0x4];
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ u32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u32 unk58;
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ u32* unk60;
};

class SpyroJumpState_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPYROJUMPSTATE_H

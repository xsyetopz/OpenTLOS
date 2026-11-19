#ifndef SPYRO_SOURCE_SPYROFALLSTATE_H
#define SPYRO_SOURCE_SPYROFALLSTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroAnimTables.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"

class MKMessage;
class Spyro;
class SpyroFallState;
class SpyroFallState_cpp;
class SpyroStartCycleAnimTable;
class SpyroState;
class SpyroStateMessages;
class SpyroStuck;

class SpyroFallState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void Message(MKMessage *);
    virtual void GetStateInfo(void);
    void SetStrafeJump(bool);
    void GetFallVel(void);
    void Landed(bool);
    u8 HoverTransition(void);
    void HoverUpdate(void);
    void HoverExit(void);
    void HoverEnter(void);
    u8 GlideTransition(void);
    void GlideUpdate(void);
    void GlideExit(void);
    void GlideEnter(void);
    s32 LongFallTransition(void);
    void LongFallUpdate(void);
    void LongFallExit(void);
    void LongFallEnter(void);
    void FallTransition(void);
    void FallUpdate(void);
    void FallExit(void);
    void FallEnter(void);
    static u8 states[0x90];
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroFallState> unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ f64 unk18;
    /* 0x020 */ u8 pad20[0x8];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 unk34;
    /* 0x035 */ u8 unk35;
    /* 0x036 */ s8 unk36;
    /* 0x037 */ s8 unk37;
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 unk39;
    /* 0x03a */ u8 unk3A;
    /* 0x03b */ u8 pad3B[0x1];
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ u8 pad40[0x4];
    /* 0x044 */ s32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
    /* 0x050 */ s8 unk50;
    /* 0x051 */ s8 unk51;
    /* 0x052 */ u8 pad52[0x2];
    /* 0x054 */ SpyroStartCycleAnimTable unk54;
    /* 0x05c */ SpyroStartCycleAnimTable unk5C;
    /* 0x064 */ SpyroStartCycleAnimTable unk64;
    /* 0x06c */ SpyroStartCycleAnimTable unk6C;
    /* 0x074 */ SpyroStartCycleAnimTable unk74;
    /* 0x07c */ u8 pad7C[0x4];
    /* 0x080 */ SpyroStuck unk80;
};

class SpyroFallState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void SpyroFallState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROFALLSTATE_H

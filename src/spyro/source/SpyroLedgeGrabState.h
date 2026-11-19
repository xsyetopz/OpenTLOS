#ifndef SPYRO_SOURCE_SPYROLEDGEGRABSTATE_H
#define SPYRO_SOURCE_SPYROLEDGEGRABSTATE_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroState.h"

class MKMessage;
class MKVector3;
class Spyro;
class SpyroLedgeGrabState;
class SpyroLedgeGrabState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroLedgeGrabState : public SpyroState {  // base: inlined ctor vtable stores
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
    virtual void GetState(void);
    void PullUpDescendTransition(void);
    void PullUpDescendUpdate(void);
    void PullUpDescendEnter(void);
    s32 PullUpAscendTransition(void);
    void PullUpAscendUpdate(void);
    void PullUpAscendEnter(void);
    s32 AttachTransition(void);
    void AttachUpdate(void);
    void AttachEnter(void);
    static SpyroLedgeGrabState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroLedgeGrabState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ u8 pad34[0x4];
    /* 0x038 */ MKVector3 unk38;
    /* 0x048 */ MKVector3 unk48;
    /* 0x058 */ u8 unk58;
};

class SpyroLedgeGrabState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void SpyroLedgeGrabState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

inline void SpyroLedgeGrabState::GetState() {
    this->unk14.GetState();
}

#endif  // SPYRO_SOURCE_SPYROLEDGEGRABSTATE_H

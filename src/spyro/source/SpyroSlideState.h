#ifndef SPYRO_SOURCE_SPYROSLIDESTATE_H
#define SPYRO_SOURCE_SPYROSLIDESTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"

class Spyro;
class SpyroSlideState;
class SpyroSlideState_cpp;
class SpyroState;
class SpyroStateMessages;
class SpyroStuck;

class SpyroSlideState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void GetStateInfo(void);
    static u8 states[0x24];
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroSlideState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ SpyroStuck unk28;
};

class SpyroSlideState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void SpyroSlideState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROSLIDESTATE_H

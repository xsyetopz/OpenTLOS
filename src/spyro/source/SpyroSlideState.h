#ifndef SPYRO_SOURCE_SPYROSLIDESTATE_H
#define SPYRO_SOURCE_SPYROSLIDESTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"

class Spyro;
class SpyroSlideState;
class SpyroSlideState_cpp;
class SpyroState;
class SpyroStateMessages;
class SpyroStuck;

class SpyroSlideState : public SpyroState {  // base: vtable prefix
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual u8 Transition(void);
    virtual void GetStateInfo(void);
    static u8 states[0x24];
    /* 0x004 */ u8 pad4[0x24];
    /* 0x028 */ SpyroStuck unk28;
};

class SpyroSlideState_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPYROSLIDESTATE_H

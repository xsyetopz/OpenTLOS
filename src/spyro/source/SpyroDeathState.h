#ifndef SPYRO_SOURCE_SPYRODEATHSTATE_H
#define SPYRO_SOURCE_SPYRODEATHSTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroState.h"

class MKMessage;
class Spyro;
class SpyroDeathState;
class SpyroDeathState_cpp;
class SpyroState;
class SpyroStateMessages;

class SpyroDeathState : public SpyroState {  // base: inlined ctor vtable stores
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual s32 Transition(void);
    virtual void Message(MKMessage *);
    virtual void GetStateInfo(void);
    s32 SpawnTransition(void);
    void SpawnUpdate(void);
    void SpawnExit(void);
    void SpawnEnter(void);
    s32 RespawnTransition(void);
    void RespawnUpdate(void);
    void RespawnExit(void);
    void RespawnEnter(void);
    u8 AirTransition(void);
    void AirUpdate(void);
    void AirExit(void);
    void AirEnter(void);
    void StrafeUpdate(void);
    void StrafeExit(void);
    void StrafeEnter(void);
    u8 LandTransition(void);
    void LandUpdate(void);
    void LandExit(void);
    void LandEnter(void);
    static SpyroDeathState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ u8 pad14[0x14];
    /* 0x028 */ u8 unk28;
    /* 0x029 */ u8 unk29;
    /* 0x02a */ u8 unk2A;
    /* 0x02b */ u8 pad2B[0x1];
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ u8 unk30;
};

class SpyroDeathState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk14'
inline void SpyroDeathState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}
#endif

#endif  // SPYRO_SOURCE_SPYRODEATHSTATE_H

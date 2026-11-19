#ifndef SPYRO_SOURCE_SPYROTAILSTRIKESTATE_H
#define SPYRO_SOURCE_SPYROTAILSTRIKESTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroTools.h"

class MKCollisionInfo;
class MKMessage;
class MKProp;
class Spyro;
class SpyroStateMessages;
class SpyroStuck;
class SpyroTailStrikeState;
class SpyroTailStrikeState_cpp;

class SpyroTailStrikeState {
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
    void HitProp(MKProp *, MKCollisionInfo *);
    u8 LandTransition(void);
    void LandUpdate(void);
    void LandExit(void);
    void LandEnter(void);
    s32 DescentTransition(void);
    void DescentUpdate(void);
    void DescentExit(void);
    void DescentEnter(void);
    s32 StartTransition(void);
    void StartUpdate(void);
    void StartExit(void);
    void StartEnter(void);
    static SpyroTailStrikeState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ u8 pad14[0x14];
    /* 0x028 */ SpyroStuck unk28;
    /* 0x044 */ u8 pad44[0x4];
    /* 0x048 */ f32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ u8 unk50;
};

class SpyroTailStrikeState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk14'
inline void SpyroTailStrikeState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}
#endif

#endif  // SPYRO_SOURCE_SPYROTAILSTRIKESTATE_H

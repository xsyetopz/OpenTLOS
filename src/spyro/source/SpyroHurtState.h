#ifndef SPYRO_SOURCE_SPYROHURTSTATE_H
#define SPYRO_SOURCE_SPYROHURTSTATE_H

#include <dolphin/types.h>
#include "spyro/source/SpyroAnimTables.h"
#include "spyro/source/SpyroState.h"

class Spyro;
class SpyroHurtState;
class SpyroHurtState_cpp;
class SpyroStartCycleAnimTable;
class SpyroState;
class SpyroStateMessages;

class SpyroHurtState : public SpyroState {  // base: vtable prefix
public:
    virtual void Init(Spyro *);
    virtual void Deinit(void);
    virtual void Enter(SpyroStateMessages &);
    virtual void Exit(void);
    virtual void Update(void);
    virtual u8 Transition(void);
    virtual void GetStateInfo(void);
    s32 CynderFuryDazedTransition(void);
    void CynderFuryDazedUpdate(void);
    void CynderFuryDazedExit(void);
    void CynderFuryDazedEnter(void);
    u8 TransitionToIdle(void);
    s32 KnockToSafePosTransition(void);
    void KnockToSafePosUpdate(void);
    void KnockToSafePosExit(void);
    void KnockToSafePosEnter(void);
    void FrozenTransition(void);
    void FrozenUpdate(void);
    void FrozenExit(void);
    void FrozenEnter(void);
    u8 DazedTransition(void);
    void DazedUpdate(void);
    void DazedExit(void);
    void DazedEnter(void);
    u8 SquashTransition(void);
    void SquashUpdate(void);
    void SquashExit(void);
    void SquashEnter(void);
    u8 TumbleTransition(void);
    void TumbleUpdate(void);
    void TumbleExit(void);
    void TumbleEnter(void);
    void StrafeFlinchTransition(void);
    void StrafeFlinchUpdate(void);
    void StrafeFlinchExit(void);
    void StrafeFlinchEnter(void);
    void FlinchTransition(void);
    void FlinchUpdate(void);
    void FlinchExit(void);
    void FlinchEnter(void);
    static SpyroHurtState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ u8 pad14[0x14];
    /* 0x028 */ SpyroStartCycleAnimTable unk28;
    /* 0x030 */ SpyroStartCycleAnimTable unk30;
    /* 0x038 */ void** unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ s32 unk94;
    /* 0x098 */ s8 unk98;
    /* 0x099 */ u8 unk99;
    /* 0x09a */ u8 unk9A;
};

class SpyroHurtState_cpp {
public:
    void __sinit(void);
};

extern f32 * Hurt_pKnockToSafePosTime;
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk14'
inline void SpyroHurtState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}
#endif

#endif  // SPYRO_SOURCE_SPYROHURTSTATE_H

#ifndef SPYRO_SOURCE_SPYROCOMBATSTATE_H
#define SPYRO_SOURCE_SPYROCOMBATSTATE_H

#include <dolphin/types.h>
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/TargetManager.h"

class CombatStateData;
class MKMessage;
class MKProp;
class MKVector3;
class Spyro;
class SpyroCombatState;
class SpyroCombatState_cpp;
class SpyroState;
class SpyroStateMessages;
class TargetContext;
class Targetable;

class CombatStateData {
public:
    void GetLastTailSweepTarget(void);
    void SetLastTailSweepTarget(Targetable *);
    void IncTailSweepComboCount(void);
    void SetTailSweepComboCount(int);
    s32 GetTailSweepComboCount(void);
    s32 GetCombatArcHitFlags(void);
    void SetCombatArcHit(int);
    void ClearCombatArcHitFlags(void);
    void SetKnockupTime(float);
    u8 GetHornDiveEnabled(void);
    void SetHornDiveEnabled(bool);
    u8 GetTailStrikeEnabled(void);
    void SetTailStrikeEnabled(bool);
    u8 GetTailSweepEnabled(void);
    void SetTailSweepEnabled(bool);
    f32 GetChargeTime(void);
    void SetChargeTime(float);
    MKProp * GetChargeHitProp(void);
    void SetChargeHitProp(MKProp *);
    u8 GetHitTarget(void);
    void SetHitTarget(bool);
    s32 GetCombatArc(void);
    void SetCombatArc(int);
    s32 GetHitType(void);
    void SetHitType(int);
    u8 GetChargeAttackActive(void);
    u8 GetTargetDir(MKVector3 *);
    void SetTargetDir(bool, const MKVector3 &);
    void GetLastCombatEnemy(void);
    void SetLastCombatEnemy(Targetable *);
    void SetLastCombatEnemy(MKProp *);
    void SetDefaults(void);
    void Init(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ TargetContext unk20;
    /* 0x030 */ MKProp* unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ s8 unk4D;
    /* 0x04e */ u8 unk4E;
    /* 0x04f */ s8 unk4F;
    /* 0x050 */ u8 unk50;
    /* 0x051 */ u8 unk51;
    /* 0x052 */ u8 unk52;
    /* 0x053 */ u8 unk53;
};

class SpyroCombatState : public SpyroState {  // base: inlined ctor vtable stores
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
    void CometDashTransition(void);
    void CometDashUpdate(void);
    void CometDashExit(void);
    void CometDashEnter(void);
    u8 ChargeKnockdownTransition(void);
    void ChargeKnockdownUpdate(void);
    void ChargeKnockdownExit(void);
    void ChargeKnockdownEnter(void);
    s32 KnockupTransition(void);
    void KnockupUpdate(void);
    void KnockupExit(void);
    void KnockupEnter(void);
    u8 CombatTransition(void);
    void CombatUpdate(void);
    void CombatExit(void);
    void CombatEnter(void);
    s32 GetCombatHitType(void);
    void SetTargetDirection(void);
    static SpyroCombatState states;
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ Spyro* unk10;
    /* 0x014 */ KDStateMachine<SpyroCombatState> unk14;
    /* 0x015 */ u8 pad15[0x13];
    /* 0x028 */ s32 unk28;
    /* 0x02c */ u8 unk2C;
    /* 0x02d */ u8 unk2D;
    /* 0x02e */ u8 unk2E;
    /* 0x02f */ u8 unk2F;
    /* 0x030 */ u8 unk30;
    /* 0x031 */ u8 unk31;
    /* 0x032 */ u8 unk32;
    /* 0x033 */ u8 pad33[0x1];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
};

class SpyroCombatState_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void *SpyroCombatState::GetStateInfo() {
    this->unk14.GetStateName(-1);
}

#endif  // SPYRO_SOURCE_SPYROCOMBATSTATE_H

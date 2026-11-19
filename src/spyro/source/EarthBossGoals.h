#ifndef SPYRO_SOURCE_EARTHBOSSGOALS_H
#define SPYRO_SOURCE_EARTHBOSSGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class EarthBoss;
class EarthBossGoal_AttackPhase1;
class EarthBossGoal_AttackPhase2;
class EarthBossGoal_AttackPhase3;
class EarthBossGoal_MeleeAttack1;
class EarthBossGoal_MeleeAttack2;
class EarthBossGoal_MeleeAttack3;
class EarthBossGoal_MeleeAttack4;
class EarthBossGoal_MeleeAttack5;
class EarthBossGoal_MoveToTarget;
class EarthBossGoal_Think;
class Enemy;
class EnemyDamageFeedback;

class EarthBossGoal_AttackPhase1 : public CompositeGoal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    u8 AddGoal_ScrapeFootClean(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_TauntOnKill(void);
    u8 SelectAttack(void);
    void Init(EarthBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<EarthBoss>* unk20;
    /* 0x024 */ void** unk24;
    /* 0x028 */ Goal<EarthBoss>* unk28;
    /* 0x02c */ Goal<EarthBoss>* unk2C;
    /* 0x030 */ Goal<EarthBoss>* unk30;
    /* 0x034 */ Goal<EarthBoss>* unk34;
    /* 0x038 */ Goal<EarthBoss>* unk38;
    /* 0x03c */ u8 unk3C;
};

class EarthBossGoal_AttackPhase2 : public CompositeGoal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    void Init(EarthBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<EarthBoss>* unk20;
    /* 0x024 */ Goal<EarthBoss>* unk24;
    /* 0x028 */ Goal<EarthBoss>* unk28;
};

class EarthBossGoal_AttackPhase3 : public CompositeGoal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    void Init(EarthBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<EarthBoss>* unk20;
    /* 0x024 */ Goal<EarthBoss>* unk24;
    /* 0x028 */ Goal<EarthBoss>* unk28;
};

class EarthBossGoal_MeleeAttack1 : public Goal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 unk14;
};

class EarthBossGoal_MeleeAttack2 : public Goal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
};

class EarthBossGoal_MeleeAttack3 : public Goal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EarthBossGoal_MeleeAttack4 : public Goal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
};

class EarthBossGoal_MeleeAttack5 : public Goal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EarthBossGoal_MoveToTarget : public Goal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
};

class EarthBossGoal_Think : public CompositeGoal<EarthBoss> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Arbitrate(void);
    void AddGoal_AttackPhase1(void);
    void AddGoal_Spawn(void);
    void AddGoal_Idle(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void Init(EarthBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s8 unk20;
    /* 0x021 */ u8 pad21[0x3];
    /* 0x024 */ Goal<EarthBoss>* unk24;
    /* 0x028 */ Goal<EarthBoss>* unk28;
    /* 0x02c */ Goal<EarthBoss>* unk2C;
    /* 0x030 */ Goal<EarthBoss>* unk30;
    /* 0x034 */ Goal<EarthBoss>* unk34;
    /* 0x038 */ void** unk38;
    /* 0x03c */ void** unk3C;
    /* 0x040 */ void** unk40;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void EarthBossGoal_MoveToTarget::Reset() {
    this->unk8 = 1;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
}

#endif  // SPYRO_SOURCE_EARTHBOSSGOALS_H

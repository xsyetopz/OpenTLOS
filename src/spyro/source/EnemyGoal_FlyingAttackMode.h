#ifndef SPYRO_SOURCE_ENEMYGOAL_FLYINGATTACKMODE_H
#define SPYRO_SOURCE_ENEMYGOAL_FLYINGATTACKMODE_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Enemy;
class EnemyGoal_AttackFlying;
class EnemyGoal_FlyingAttackMode;
class Targetable;

class EnemyGoal_AttackFlying : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_FlyingAttackMode : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Targetable* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ AITargetData* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void EnemyGoal_FlyingAttackMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = NULL;
}

#endif  // SPYRO_SOURCE_ENEMYGOAL_FLYINGATTACKMODE_H

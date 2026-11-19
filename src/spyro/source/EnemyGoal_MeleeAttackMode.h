#ifndef SPYRO_SOURCE_ENEMYGOAL_MELEEATTACKMODE_H
#define SPYRO_SOURCE_ENEMYGOAL_MELEEATTACKMODE_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Enemy;
class EnemyGoal_AttackMagicWall;
class EnemyGoal_AttackMelee;
class EnemyGoal_AttackMeleeLoop;
class EnemyGoal_LeapAttackHit;
class EnemyGoal_LeapAttackMiss;
class EnemyGoal_LeapAttackRecover;
class EnemyGoal_MeleeAttackMode;
class Targetable;

class EnemyGoal_AttackMagicWall : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 unk14;
    /* 0x015 */ s8 unk15;
};

class EnemyGoal_AttackMelee : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ u8 unk14;
};

class EnemyGoal_AttackMeleeLoop : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Targetable* unkC;
    /* 0x010 */ s8 unk10;
};

class EnemyGoal_LeapAttackHit : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class EnemyGoal_LeapAttackMiss : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    ~EnemyGoal_LeapAttackMiss(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[0x24];
    /* 0x03c */ u8 unk3C;
};

class EnemyGoal_LeapAttackRecover : public CompositeGoal<Enemy> {  // base: vtable prefix
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
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<Enemy>* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
};

class EnemyGoal_MeleeAttackMode : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_AttackIdleOrStrafe(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Attack(void);
    void CalculateRegionEdgeMoveTarget(bool);
    void AddGoal_Move(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ AITargetData* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 unk41;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void EnemyGoal_AttackMelee::Reset() {
    this->unk8 = 1;
    this->unk14 = 0;
}

inline void EnemyGoal_AttackMeleeLoop::Reset() {
    this->unk8 = 1;
    this->unk10 = 0;
}

#if 0 // DRAFT: undefined identifier 'KDSound_Stop'
inline EnemyGoal_LeapAttackMiss::~EnemyGoal_LeapAttackMiss() {
    if ((&this->unk14 != NULL) && (&this->unk14 != NULL)) {
        KDSound_Stop(&this->unk14);
    }
}
#endif

inline void EnemyGoal_LeapAttackRecover::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

inline void EnemyGoal_MeleeAttackMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = NULL;
    this->unk40 = 0;
    this->unk41 = 0;
}

#endif  // SPYRO_SOURCE_ENEMYGOAL_MELEEATTACKMODE_H

#ifndef SPYRO_SOURCE_ENEMYTESTGOALS_H
#define SPYRO_SOURCE_ENEMYTESTGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Enemy;
class EnemyDamageFeedback;
class EnemyTestGoal_MoveToTarget;
class EnemyTest_Think;

class EnemyTestGoal_MoveToTarget : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

class EnemyTest_Think : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void AddGoal_Idle(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ Goal<Enemy>* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ void** unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
};

#endif  // SPYRO_SOURCE_ENEMYTESTGOALS_H

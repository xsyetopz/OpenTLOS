#ifndef SPYRO_SOURCE_CYNDERTIER2TRAINGOAL_THINK_H
#define SPYRO_SOURCE_CYNDERTIER2TRAINGOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class CynderTier2TrainGoal_Think;
class CynderTier2TrainGoal_Think_cpp;
class Enemy;
class EnemyDamageFeedback;
class EnemyGoal_SpawnOnTrain;
class EnemyGoal_TrainAttackMode;

class CynderTier2TrainGoal_Think : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void AddGoal_TrainAttackMode(AITargetData *);
    void AddGoal_SpawnOnTrain(void);
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
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ u8 unk30;
};

class CynderTier2TrainGoal_Think_cpp {
public:
    void __sinit(void);
};

class EnemyGoal_SpawnOnTrain : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class EnemyGoal_TrainAttackMode : public CompositeGoal<Enemy> {  // base: vtable prefix
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
    /* 0x020 */ f32 unk20;
    /* 0x024 */ AITargetData* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
};

#endif  // SPYRO_SOURCE_CYNDERTIER2TRAINGOAL_THINK_H

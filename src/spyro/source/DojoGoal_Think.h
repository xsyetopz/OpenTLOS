#ifndef SPYRO_SOURCE_DOJOGOAL_THINK_H
#define SPYRO_SOURCE_DOJOGOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class DojoGoal_Think;
class Enemy;
class EnemyDamageFeedback;

class DojoGoal_Think : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_SpawnIdle(void);
    void AddGoal_Spawn(void);
    void StartFollowingSpawnGraph(void);
    void StopFollowingSpawnGraph(void);
    u8 IsFollowingSpawnGraph(void);
    u8 AddGoal_MoveToLastPlayerPos(void);
    void AddGoal_FollowSpawnGraph(void);
    void AddGoal_ReceiveOrders(void);
    void AddGoal_Respawn(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void AddGoal_AlertMode(AITargetData *);
    void AddGoal_Idle(void);
    void AddGoal_PatrolMode(void);
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
    /* 0x020 */ Enemy* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ u8 pad3C[0x8];
    /* 0x044 */ Goal<Enemy>* unk44;
    /* 0x048 */ Goal<Enemy>* unk48;
    /* 0x04c */ Goal<Enemy>* unk4C;
    /* 0x050 */ Goal<Enemy>* unk50;
    /* 0x054 */ u8 unk54;
};

#endif  // SPYRO_SOURCE_DOJOGOAL_THINK_H

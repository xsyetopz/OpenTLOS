#ifndef SPYRO_SOURCE_ENEMYGOAL_THINK_H
#define SPYRO_SOURCE_ENEMYGOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class AnimSequenceType;
class Enemy;
class EnemyDamageFeedback;
class EnemyGoal_Think;
class MKProp;

class EnemyGoal_Think : public CompositeGoal<Enemy> {  // base: ctor/dtor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void RemoveAllInactiveSubgoals(int);
    void SetFollowSpawnPathParams(AnimSequenceType, int);
    void SetSpawnGoal(Goal<Enemy> *);
    void AddGoal_Frozen(void);
    void AddGoal_Spawn(void);
    u8 Try_AddGoal_Kong(void);
    u8 Try_AddGoal_OperateLever(void);
    void StartFollowingSpawnGraph(void);
    void StopFollowingSpawnGraph(void);
    u8 IsFollowingSpawnGraph(void);
    void StartFollowingSpawnPath(void);
    void StopFollowingSpawnPath(void);
    u8 IsFollowingSpawnPath(void);
    void AddGoal_Kong(MKProp *);
    void AddGoal_OperateLever(MKProp *);
    void AddGoal_FollowSpawnGraph(void);
    void AddGoal_FollowSpawnPath(void);
    void AddGoal_Panic(void);
    void AddGoal_ReceiveOrders(void);
    void AddGoal_Respawn(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void AddGoal_Strafe(void);
    u8 AddGoal_MoveToLastPlayerPos(void);
    void AddGoal_GroundAttackMode(void);
    void AddGoal_AlertMode(AITargetData *);
    void AddGoal_PatrolMode(void);
    void ArbitrateOld(void);
    void InitKongGoal(void);
    void InitFrozenGoal(void);
    void InitOperateLeverGoal(void);
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
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ Goal<Enemy>* unk40;
    /* 0x044 */ void** unk44;
    /* 0x048 */ Goal<Enemy>* unk48;
    /* 0x04c */ Goal<Enemy>* unk4C;
    /* 0x050 */ Goal<Enemy>* unk50;
    /* 0x054 */ Goal<Enemy>* unk54;
    /* 0x058 */ Goal<Enemy>* unk58;
    /* 0x05c */ Goal<Enemy>* unk5C;
    /* 0x060 */ Goal<Enemy>* unk60;
    /* 0x064 */ Goal<Enemy>* unk64;
    /* 0x068 */ AITargetData* unk68;
    /* 0x06c */ s32 unk6C;
    /* 0x070 */ u8 unk70;
};

#endif  // SPYRO_SOURCE_ENEMYGOAL_THINK_H

#ifndef SPYRO_SOURCE_ENEMYGOAL_GROUNDATTACKMODE_H
#define SPYRO_SOURCE_ENEMYGOAL_GROUNDATTACKMODE_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class EAPItem;
class Enemy;
class EnemyAttack;
class EnemyGoal_GroundAttackMode;

class EnemyGoal_GroundAttackMode : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_MoveToAttackRange(EnemyAttack *);
    u8 AddGoal_Attack(EnemyAttack *);
    u8 AddGoal_StrafeIfObscuringCamera(void);
    void AddGoal_AttackIdleOrStrafe(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    u8 AddGoal_OnlyRangeAttack(bool);
    u8 AddGoal_MoveToRegion(void);
    u8 AddGoal_Summon(void);
    void SetSummonGoal(Goal<Enemy> *);
    void SetParams(AITargetData *, bool, EAPItem *);
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
    /* 0x030 */ u8 pad30[0x4];
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ Goal<Enemy>* unk40;
    /* 0x044 */ Goal<Enemy>* unk44;
    /* 0x048 */ Goal<Enemy>* unk48;
    /* 0x04c */ Goal<Enemy>* unk4C;
    /* 0x050 */ Goal<Enemy>* unk50;
    /* 0x054 */ Goal<Enemy>* unk54;
    /* 0x058 */ Goal<Enemy>* unk58;
    /* 0x05c */ Goal<Enemy>* unk5C;
    /* 0x060 */ Goal<Enemy>* unk60;
    /* 0x064 */ EAPItem* unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 unk6C;
};

#endif  // SPYRO_SOURCE_ENEMYGOAL_GROUNDATTACKMODE_H

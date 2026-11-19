#ifndef SPYRO_SOURCE_ENEMYGOAL_FOLLOWGRAPH_H
#define SPYRO_SOURCE_ENEMYGOAL_FOLLOWGRAPH_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/TargetManager.h"

class Character;
class Enemy;
class EnemyGoal_BarricadeHide;
class EnemyGoal_BarricadeKick;
class EnemyGoal_Despawn;
class EnemyGoal_FollowGraph;
class EnemyGoal_GraphBarricade;
class EnemyGoal_GraphFly;
class EnemyGoal_GraphFlyPath;
class EnemyGoal_GraphGlidePath;
class EnemyGoal_GraphHover;
class EnemyGoal_GraphJump;
class EnemyGoal_GraphRun;
class EnemyGoal_GraphSummonWall;
class EnemyGoal_GraphTurn;
class EnemyGoal_GraphWalk;
class KDUniformSpline;
class MKProp;
class MKVector3;
class TargetContext;

class EnemyGoal_BarricadeHide : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
};

class EnemyGoal_BarricadeKick : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_Despawn : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
};

class EnemyGoal_FollowGraph : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_OperateLever(void);
    void AddGoal_GraphHover(void);
    void AddGoal_SummonWall(void);
    void AddGoal_Summon(void);
    void AddGoal_Drop(void);
    void AddGoal_PickUp(void);
    void AddGoal_GiveOrders(void);
    void AddGoal_RangeAttackMode(void);
    void AddGoal_Death(void);
    void AddGoal_Cower(void);
    void AddGoal_Taunt(bool);
    void AddGoal_Alert(void);
    void AddGoal_Sleep(void);
    void AddGoal_Cheer(void);
    void AddGoal_SpawnUntilTrigger(void);
    void AddGoal_IdleAndAlertOnTrigger(int);
    void AddGoal_IdleUntilTrigger(int);
    void AddGoal_Turn(void);
    void AddGoal_Idle(void);
    void AddGoal_Barricade(void);
    void AddGoal_FollowPath(void);
    void AddGoal_Jump(void);
    void AddGoal_GlidePath(void);
    void AddGoal_FlyPath(void);
    void AddGoal_Fly(void);
    void AddGoal_Flee(void);
    void AddGoal_Run(void);
    void AddGoal_Walk(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
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
    /* 0x064 */ Goal<Enemy>* unk64;
    /* 0x068 */ Goal<Enemy>* unk68;
    /* 0x06c */ Goal<Enemy>* unk6C;
    /* 0x070 */ Goal<Enemy>* unk70;
    /* 0x074 */ Goal<Enemy>* unk74;
    /* 0x078 */ Goal<Enemy>* unk78;
    /* 0x07c */ Goal<Enemy>* unk7C;
    /* 0x080 */ Goal<Enemy>* unk80;
    /* 0x084 */ void** unk84;
    /* 0x088 */ Goal<Enemy>* unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 unk95;
};

class EnemyGoal_GraphBarricade : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_Summon(void);
    void AddGoal_GiveOrders(void);
    void AddGoal_Attack(void);
    void AddGoal_Kick(void);
    void AddGoal_MoveTo(void);
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
    /* 0x020 */ TargetContext unk20;
    /* 0x030 */ void** unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 pad41[0x1db];
    /* 0x21c */ s32 unk21C;
};

class EnemyGoal_GraphFly : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ u8 unk10;
};

class EnemyGoal_GraphFlyPath : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKVector3 unk18;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
};

class EnemyGoal_GraphGlidePath : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ MKVector3 unk18;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
};

class EnemyGoal_GraphHover : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
};

class EnemyGoal_GraphJump : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void GetParabolaCentre(MKVector3, MKVector3, float, float);
    f32 GetParabolaApexTimeFromP2(MKVector3, MKVector3, float, float);
    f32 GetParabolaApexTimeFromP1(MKVector3, MKVector3, float, float);
    f32 GetTotalTime(MKVector3, MKVector3, float, float);
    void Init(Enemy *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ KDUniformSpline unk30;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ f32 unk4C;
};

class EnemyGoal_GraphRun : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s8 unk10;
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad12[0x2];
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
};

class EnemyGoal_GraphSummonWall : public Goal<Enemy> {  // base: vtable prefix
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
};

class EnemyGoal_GraphTurn : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
};

class EnemyGoal_GraphWalk : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s8 unk10;
    /* 0x011 */ u8 unk11;
};

#endif  // SPYRO_SOURCE_ENEMYGOAL_FOLLOWGRAPH_H

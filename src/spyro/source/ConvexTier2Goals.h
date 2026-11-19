#ifndef SPYRO_SOURCE_CONVEXTIER2GOALS_H
#define SPYRO_SOURCE_CONVEXTIER2GOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Character;
class ConvexTier2Goal_FlyIdle;
class ConvexTier2Goal_PatrolMode;
class ConvexTier2Goal_Think;
class Enemy;
class EnemyDamageFeedback;

class ConvexTier2Goal_FlyIdle : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class ConvexTier2Goal_PatrolMode : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
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
    /* 0x020 */ Enemy* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
};

class ConvexTier2Goal_Think : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void StartFollowingSpawnGraph(void);
    void StopFollowingSpawnGraph(void);
    u8 IsFollowingSpawnGraph(void);
    void StartFollowingSpawnPath(void);
    void StopFollowingSpawnPath(void);
    u8 IsFollowingSpawnPath(void);
    void AddGoal_FollowSpawnGraph(void);
    void AddGoal_FollowSpawnPath(void);
    void AddGoal_Hit(EnemyDamageFeedback *);
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
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ u8 unk3C;
};

#endif  // SPYRO_SOURCE_CONVEXTIER2GOALS_H

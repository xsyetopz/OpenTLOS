#ifndef SPYRO_SOURCE_SWAMPTIER3GOALS_H
#define SPYRO_SOURCE_SWAMPTIER3GOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Enemy;
class EnemyDamageFeedback;
class SwampTier3;
class SwampTier3Goal_Cower;
class SwampTier3Goal_Hit;
class SwampTier3Goal_Patrol;
class SwampTier3Goal_Summon;
class SwampTier3Goal_Think;

class SwampTier3Goal_Cower : public Goal<SwampTier3> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class SwampTier3Goal_Hit : public CompositeGoal<SwampTier3> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier3 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<SwampTier3>* unk20;
    /* 0x024 */ Goal<SwampTier3>* unk24;
    /* 0x028 */ Goal<SwampTier3>* unk28;
    /* 0x02c */ Goal<SwampTier3>* unk2C;
    /* 0x030 */ Goal<SwampTier3>* unk30;
};

class SwampTier3Goal_Patrol : public CompositeGoal<SwampTier3> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier3 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<SwampTier3>* unk20;
    /* 0x024 */ Goal<SwampTier3>* unk24;
    /* 0x028 */ Goal<SwampTier3>* unk28;
    /* 0x02c */ Goal<SwampTier3>* unk2C;
};

class SwampTier3Goal_Summon : public CompositeGoal<SwampTier3> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void PositionSpawnPoints(void);
    void Init(SwampTier3 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<SwampTier3>* unk20;
    /* 0x024 */ Goal<SwampTier3>* unk24;
    /* 0x028 */ s32 unk28;
};

class SwampTier3Goal_Think : public CompositeGoal<SwampTier3> {  // base: vtable prefix
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
    void AddGoal_Patrol(void);
    void AddGoal_AlertMode(AITargetData *);
    void AddGoal_Respawn(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void Init(SwampTier3 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ void** unk20;
    /* 0x024 */ Goal<SwampTier3>* unk24;
    /* 0x028 */ Goal<SwampTier3>* unk28;
    /* 0x02c */ Goal<SwampTier3>* unk2C;
    /* 0x030 */ Goal<SwampTier3>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<SwampTier3>* unk38;
    /* 0x03c */ Goal<SwampTier3>* unk3C;
    /* 0x040 */ Goal<SwampTier3>* unk40;
    /* 0x044 */ u8 unk44;
};

#endif  // SPYRO_SOURCE_SWAMPTIER3GOALS_H

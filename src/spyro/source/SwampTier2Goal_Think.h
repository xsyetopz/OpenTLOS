#ifndef SPYRO_SOURCE_SWAMPTIER2GOAL_THINK_H
#define SPYRO_SOURCE_SWAMPTIER2GOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Enemy;
class EnemyDamageFeedback;
class SwampTier2;
class SwampTier2Goal_AlertMode;
class SwampTier2Goal_Attack1;
class SwampTier2Goal_Attack2;
class SwampTier2Goal_Hide;
class SwampTier2Goal_MoveToTarget;
class SwampTier2Goal_Think;

class SwampTier2Goal_AlertMode : public CompositeGoal<SwampTier2> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier2 *);
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
    /* 0x024 */ Goal<SwampTier2>* unk24;
    /* 0x028 */ Goal<SwampTier2>* unk28;
    /* 0x02c */ Goal<SwampTier2>* unk2C;
    /* 0x030 */ Goal<SwampTier2>* unk30;
    /* 0x034 */ Goal<SwampTier2>* unk34;
    /* 0x038 */ Goal<SwampTier2>* unk38;
    /* 0x03c */ Goal<SwampTier2>* unk3C;
    /* 0x040 */ u8 unk40;
};

class SwampTier2Goal_Attack1 : public Goal<SwampTier2> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier2 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
};

class SwampTier2Goal_Attack2 : public Goal<SwampTier2> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier2 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
};

class SwampTier2Goal_Hide : public Goal<SwampTier2> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier2 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ u8 unk10;
};

class SwampTier2Goal_MoveToTarget : public Goal<SwampTier2> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier2 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f32 unk10;
};

class SwampTier2Goal_Think : public CompositeGoal<SwampTier2> {  // base: inlined ctor vtable stores
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
    void AddGoal_FollowSpawnGraph(void);
    void AddGoal_AlertMode(bool);
    void AddGoal_Hide(void);
    void AddGoal_Respawn(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void Init(SwampTier2 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ void** unk20;
    /* 0x024 */ Goal<SwampTier2>* unk24;
    /* 0x028 */ Goal<SwampTier2>* unk28;
    /* 0x02c */ Goal<SwampTier2>* unk2C;
    /* 0x030 */ Goal<SwampTier2>* unk30;
    /* 0x034 */ Goal<SwampTier2>* unk34;
    /* 0x038 */ Goal<SwampTier2>* unk38;
    /* 0x03c */ u8 unk3C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void SwampTier2Goal_AlertMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = NULL;
}

inline void SwampTier2Goal_MoveToTarget::Reset() {
    this->unk8 = 1;
    this->unk10 = 0.0f;
}

#endif  // SPYRO_SOURCE_SWAMPTIER2GOAL_THINK_H

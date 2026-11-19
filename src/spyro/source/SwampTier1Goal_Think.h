#ifndef SPYRO_SOURCE_SWAMPTIER1GOAL_THINK_H
#define SPYRO_SOURCE_SWAMPTIER1GOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Enemy;
class EnemyDamageFeedback;
class SwampTier1;
class SwampTier1Goal_Hit;
class SwampTier1Goal_Think;

class SwampTier1Goal_Hit : public CompositeGoal<SwampTier1> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(SwampTier1 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<SwampTier1>* unk20;
    /* 0x024 */ Goal<SwampTier1>* unk24;
    /* 0x028 */ Goal<SwampTier1>* unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ s32 unk40;
};

class SwampTier1Goal_Think : public CompositeGoal<SwampTier1> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    u8 AddGoal_MoveToLastPlayerPos(void);
    void AddGoal_AlertMode(AITargetData *);
    void AddGoal_Respawn(void);
    void AddGoal_Spawn(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void AddGoal_Idle(void);
    void Init(SwampTier1 *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<SwampTier1>* unk20;
    /* 0x024 */ Goal<SwampTier1>* unk24;
    /* 0x028 */ Goal<SwampTier1>* unk28;
    /* 0x02c */ Goal<SwampTier1>* unk2C;
    /* 0x030 */ Goal<SwampTier1>* unk30;
    /* 0x034 */ Goal<SwampTier1>* unk34;
    /* 0x038 */ Goal<SwampTier1>* unk38;
    /* 0x03c */ u8 unk3C;
    /* 0x03d */ u8 unk3D;
};

#endif  // SPYRO_SOURCE_SWAMPTIER1GOAL_THINK_H

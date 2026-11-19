#ifndef SPYRO_SOURCE_NPCGUARDIANGOAL_THINK_H
#define SPYRO_SOURCE_NPCGUARDIANGOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Enemy;
class NPCGuardianGoal_Think;

class NPCGuardianGoal_Think : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_Idle(void);
    void AddGoal_FollowSpawnGraph(void);
    void StartFollowingSpawnGraph(void);
    u8 IsFollowingSpawnGraph(void);
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
    /* 0x020 */ s32 unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ u8 pad28[0x4];
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ u8 unk30;
};

#endif  // SPYRO_SOURCE_NPCGUARDIANGOAL_THINK_H

#ifndef SPYRO_SOURCE_KANEGOAL_THINK_H
#define SPYRO_SOURCE_KANEGOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Enemy;
class KaneGoal_Think;

class KaneGoal_Think : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
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
    /* 0x020 */ Goal<Enemy>* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ u8 unk28;
};

#endif  // SPYRO_SOURCE_KANEGOAL_THINK_H

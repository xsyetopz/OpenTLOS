#ifndef SPYRO_SOURCE_NPCGOAL_THINK_H
#define SPYRO_SOURCE_NPCGOAL_THINK_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Enemy;
class MoleTether;
class NPCGoal_Think;

class NPCGoal_Think : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    virtual void Arbitrate(void);
    void AddGoal_BreakRock(void);
    void AddGoal_Rescue(void);
    void AddGoal_Respawn(void);
    void AddGoal_Idle(void);
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
    /* 0x028 */ u8 pad28[0x8];
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ MoleTether* unk34;
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 unk39;
};

#endif  // SPYRO_SOURCE_NPCGOAL_THINK_H

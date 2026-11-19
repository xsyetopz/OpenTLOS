#ifndef SPYRO_SOURCE_CYNDERCONCURRENTGOALS_H
#define SPYRO_SOURCE_CYNDERCONCURRENTGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Cynder;
class CynderConcurrentGoal_Think;
class EnemyDamageFeedback;

class CynderConcurrentGoal_Think : public CompositeGoal<Cynder> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Arbitrate(void);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s8 unk20;
    /* 0x021 */ u8 pad21[0x3];
    /* 0x024 */ void** unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
};

#endif  // SPYRO_SOURCE_CYNDERCONCURRENTGOALS_H

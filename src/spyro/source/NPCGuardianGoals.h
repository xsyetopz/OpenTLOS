#ifndef SPYRO_SOURCE_NPCGUARDIANGOALS_H
#define SPYRO_SOURCE_NPCGUARDIANGOALS_H

#include <dolphin/types.h>
#include "spyro/source/Goal.h"

class Character;
class Enemy;
class NPCGuardianGoal_Idle;

class NPCGuardianGoal_Idle : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ u32 unk10;
    /* 0x014 */ f32 unk14;
};

#endif  // SPYRO_SOURCE_NPCGUARDIANGOALS_H

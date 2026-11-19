#ifndef SPYRO_SOURCE_DREADWINGGOALS_H
#define SPYRO_SOURCE_DREADWINGGOALS_H

#include <dolphin/types.h>
#include "spyro/source/Goal.h"

class DreadWingGoal_Drop;
class DreadWingGoal_PickUp;
class Enemy;

class DreadWingGoal_Drop : public Goal<Enemy> {  // base: vtable prefix
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
};

class DreadWingGoal_PickUp : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void SetParams(int);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
};

#endif  // SPYRO_SOURCE_DREADWINGGOALS_H

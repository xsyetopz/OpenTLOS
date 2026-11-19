#ifndef SPYRO_SOURCE_FIREBOSSDRIVERGOALS_H
#define SPYRO_SOURCE_FIREBOSSDRIVERGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Character;
class Enemy;
class FireBossDriverGoal_Charge;
class FireBossDriverGoal_Crash;
class FireBossDriverGoal_Idle;
class FireBossDriverGoal_Think;

class FireBossDriverGoal_Charge : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    void Exit(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ Enemy* unk10;
};

class FireBossDriverGoal_Crash : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    void Exit(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ Enemy* unk10;
};

class FireBossDriverGoal_Idle : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ void* unk10;
};

class FireBossDriverGoal_Think : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    void CrashExit(void);
    void CrashEnter(void);
    void ChargeExit(void);
    void ChargeEnter(void);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Enemy* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ FireBossDriverGoal_Crash* unk28;
    /* 0x02c */ FireBossDriverGoal_Charge* unk2C;
};

#endif  // SPYRO_SOURCE_FIREBOSSDRIVERGOALS_H

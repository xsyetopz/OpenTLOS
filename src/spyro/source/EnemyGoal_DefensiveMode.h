#ifndef SPYRO_SOURCE_ENEMYGOAL_DEFENSIVEMODE_H
#define SPYRO_SOURCE_ENEMYGOAL_DEFENSIVEMODE_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Enemy;
class EnemyGoal_Block;
class EnemyGoal_DefensiveMode;
class EnemyGoal_ShieldBlock;
class EnemyGoal_ShieldCharge;

class EnemyGoal_Block : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

class EnemyGoal_DefensiveMode : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Enemy *);
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
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ void** unk34;
};

class EnemyGoal_ShieldBlock : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 unk1C;
    /* 0x01d */ u8 unk1D;
};

class EnemyGoal_ShieldCharge : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void EnableSB(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ f32 unk14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void EnemyGoal_DefensiveMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

inline void EnemyGoal_ShieldBlock::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk1C = 0;
    this->unk1D = 0;
    this->unk18 = 1.0f;
}

#endif  // SPYRO_SOURCE_ENEMYGOAL_DEFENSIVEMODE_H

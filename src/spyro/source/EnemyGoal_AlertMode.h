#ifndef SPYRO_SOURCE_ENEMYGOAL_ALERTMODE_H
#define SPYRO_SOURCE_ENEMYGOAL_ALERTMODE_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Enemy;
class EnemyGoal_AlertMode;

class EnemyGoal_AlertMode : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void CalculateRegionEdgeMoveTarget(bool);
    s32 AddGoal_MoveAwayFromHero(void);
    u8 AddGoal_DefensiveMode(void);
    u8 AddGoal_FlyingAttackMode(void);
    u8 AddGoal_RangedAttackMode(void);
    u8 AddGoal_MeleeAttackMode(void);
    u8 AddGoal_OnlyRangeAttack(void);
    u8 AddGoal_MoveToRegion(void);
    void AddGoal_Taunt(void);
    u8 AddGoal_Summon(void);
    s32 AddGoal_Alert(void);
    void SetSummonGoal(Goal<Enemy> *);
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
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ Goal<Enemy>* unk40;
    /* 0x044 */ Goal<Enemy>* unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ u8 unk50;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void EnemyGoal_AlertMode::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = NULL;
    this->unk4C = 0xFF;
    this->unk50 &= ~0x80;
    this->unk50 &= ~0x40;
}

#endif  // SPYRO_SOURCE_ENEMYGOAL_ALERTMODE_H

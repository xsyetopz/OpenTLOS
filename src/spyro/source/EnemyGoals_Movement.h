#ifndef SPYRO_SOURCE_ENEMYGOALS_MOVEMENT_H
#define SPYRO_SOURCE_ENEMYGOALS_MOVEMENT_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Enemy;
class EnemyGoal_BackupFromTarget;
class EnemyGoal_FollowPath;
class EnemyGoal_Jump;
class EnemyGoal_Land;
class EnemyGoal_MoveAwayFromHero;
class EnemyGoal_MoveToTarget;
class EnemyGoal_Panic;
class EnemyGoal_PatrolMode;
class EnemyGoal_Strafe;
class EnemyGoal_Wander;
class KDSplinePathSegment;
class MKProp;
class MKVector3;

class EnemyGoal_BackupFromTarget : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

class EnemyGoal_FollowPath : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ KDSplinePathSegment* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ u8 unk24;
};

class EnemyGoal_Jump : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ MKVector3* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
};

class EnemyGoal_Land : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class EnemyGoal_MoveAwayFromHero : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
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
    /* 0x020 */ Goal<Enemy>* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
};

class EnemyGoal_MoveToTarget : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void UpdateStuckness(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ AITargetData* unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ u8 unk30;
};

class EnemyGoal_Panic : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
};

class EnemyGoal_PatrolMode : public CompositeGoal<Enemy> {  // base: vtable prefix
public:
    virtual void Deinit(void);
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
    /* 0x020 */ Goal<Enemy>* unk20;
    /* 0x024 */ Goal<Enemy>* unk24;
    /* 0x028 */ Goal<Enemy>* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
};

class EnemyGoal_Strafe : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ u8 unk14;
};

class EnemyGoal_Wander : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ s32 unk18;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void EnemyGoal_BackupFromTarget::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
}

inline void EnemyGoal_Jump::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->unk1C = 0.0f;
}

inline void EnemyGoal_MoveToTarget::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk14 = NULL;
    this->unk18 = 0.0f;
    this->unk30 &= ~0x80;
    this->unk30 |= 0x40;
    this->unk1C = 0.0f;
    this->unk20 = 3;
    this->unk24 = 0;
    this->unk28 = -1;
    this->unk30 &= ~0x10;
    this->unk30 |= 0x20;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKProp'
inline void EnemyGoal_Panic::Reset() {
    f64 sp10;
    f64 sp8;
    f64 temp_f1_2846;
    f64 temp_f2_2845;
    void *temp_r4_2844;

    this->unk8 = 1;
    temp_r4_2844 = this->unkC->unk8;
    temp_f2_2845 = M2C_FIELD(temp_r4_2844, f64 *, 0x30);
    temp_f1_2846 = M2C_FIELD(temp_r4_2844, f64 *, 0x38);
    sp8 = temp_f2_2845;
    this->unk10 = temp_f2_2845;
    this->unk18 = temp_f1_2846;
    this->unk20 = 0.0f;
    sp10 = temp_f1_2846;
    this->unk24 = 0.0f;
}
#endif

inline void EnemyGoal_Strafe::Reset() {
    this->unk8 = 1;
    this->unk14 = 0;
    this->unk10 = NULL;
}

#endif  // SPYRO_SOURCE_ENEMYGOALS_MOVEMENT_H

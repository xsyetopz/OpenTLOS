#ifndef SPYRO_SOURCE_ENEMYGOALS_HIT_H
#define SPYRO_SOURCE_ENEMYGOALS_HIT_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class Character;
class Enemy;
class EnemyGoal_Hit;
class EnemyGoal_HitAirCombo;
class EnemyGoal_HitArmourDestroyed;
class EnemyGoal_HitBurn;
class EnemyGoal_HitFall;
class EnemyGoal_HitFlinch;
class EnemyGoal_HitFrozen;
class EnemyGoal_HitKnockback;
class EnemyGoal_HitKnockdown;
class EnemyGoal_HitKnockdownSlide;
class EnemyGoal_HitKnockup;
class EnemyGoal_HitShock;
class EnemyGoal_HitSquished;
class EnemyGoal_HitStand;
class EnemyGoals_Hit_cpp;
class MKVector3;

class EnemyGoal_Hit : public CompositeGoal<Enemy> {  // base: vtable prefix
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
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ Goal<Enemy>* unk3C;
    /* 0x040 */ Goal<Enemy>* unk40;
    /* 0x044 */ Goal<Enemy>* unk44;
    /* 0x048 */ Goal<Enemy>* unk48;
    /* 0x04c */ Goal<Enemy>* unk4C;
    /* 0x050 */ Goal<Enemy>* unk50;
};

class EnemyGoal_HitAirCombo : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 unk14;
};

class EnemyGoal_HitArmourDestroyed : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_HitBurn : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class EnemyGoal_HitFall : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_HitFlinch : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ u8 unk10;
};

class EnemyGoal_HitFrozen : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
};

class EnemyGoal_HitKnockback : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ u8 unk10;
};

class EnemyGoal_HitKnockdown : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    ~EnemyGoal_HitKnockdown(void);
    void TryTriggerEventCamera(const MKVector3 &);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[0x24];
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 unk40;
};

class EnemyGoal_HitKnockdownSlide : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    ~EnemyGoal_HitKnockdownSlide(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 pad14[0x24];
    /* 0x038 */ u8 unk38;
};

class EnemyGoal_HitKnockup : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ u8 unk10;
};

class EnemyGoal_HitShock : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_HitSquished : public Goal<Enemy> {  // base: vtable prefix
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
    /* 0x018 */ s32 unk18;
};

class EnemyGoal_HitStand : public Goal<Enemy> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoals_Hit_cpp {
public:
    void __sinit(void);
};

u8 GetPushOutWallNormal(Enemy *, MKVector3 *);
#endif  // SPYRO_SOURCE_ENEMYGOALS_HIT_H

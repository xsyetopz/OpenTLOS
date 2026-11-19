#ifndef SPYRO_SOURCE_ENEMYGOALS_H
#define SPYRO_SOURCE_ENEMYGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"
#include "spyro/source/TargetManager.h"

class AITargetData;
class Character;
class Enemy;
class EnemyGeneratorDoor;
class EnemyGoal_Alert;
class EnemyGoal_AttackIdle;
class EnemyGoal_Frozen;
class EnemyGoal_GiveOrders;
class EnemyGoal_Hide;
class EnemyGoal_Idle;
class EnemyGoal_Kong;
class EnemyGoal_OperateLever;
class EnemyGoal_PullLever;
class EnemyGoal_PushBarrel;
class EnemyGoal_ReceiveOrders;
class EnemyGoal_Sleep;
class EnemyGoal_Spawn;
class EnemyGoal_SpawnFromEnemyGenerator;
class EnemyGoal_SpawnIdle;
class EnemyGoal_Summon;
class EnemyGoal_Turn;
class EnemyGoals_cpp;
class ExplosiveBarrelPath;
class Lever;
class MKProp;
class NPCGoal_Rescue;
class TargetContext;

class EnemyGoal_Alert : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ void* unk14;
    /* 0x018 */ f32 unk18;
};

class EnemyGoal_AttackIdle : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 unk18;
};

class EnemyGoal_Frozen : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class EnemyGoal_GiveOrders : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    u64 GetOderMask(int);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
};

class EnemyGoal_Hide : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 unk14;
};

class EnemyGoal_Idle : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ u8 unk20;
};

class EnemyGoal_Kong : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void SetParams(ExplosiveBarrelPath *);
    void Init(Enemy *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ MKProp* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ ExplosiveBarrelPath* unk28;
    /* 0x02c */ Goal<Enemy>* unk2C;
    /* 0x030 */ Goal<Enemy>* unk30;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
};

class EnemyGoal_OperateLever : public CompositeGoal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void SetParams(Lever *);
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
    /* 0x020 */ f32 unk20;
    /* 0x024 */ TargetContext unk24;
    /* 0x034 */ Goal<Enemy>* unk34;
    /* 0x038 */ Goal<Enemy>* unk38;
    /* 0x03c */ u8 unk3C;
};

class EnemyGoal_PullLever : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void SetParams(Lever *);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ TargetContext unk10;
};

class EnemyGoal_PushBarrel : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ ExplosiveBarrelPath* unk10;
    /* 0x014 */ s32 unk14;
};

class EnemyGoal_ReceiveOrders : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class EnemyGoal_Sleep : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class EnemyGoal_Spawn : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
};

class EnemyGoal_SpawnFromEnemyGenerator : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void CheckPassedThroughDoor(void);
    void TryCloseDoor(void);
    void TryOpenDoor(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ EnemyGeneratorDoor* unk10;
    /* 0x014 */ u8 unk14;
};

class EnemyGoal_SpawnIdle : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void TriggerExit(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 unk11;
};

class EnemyGoal_Summon : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    s32 PositionSpawnPoints_Vanguard(bool);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 unk18;
};

class EnemyGoal_Turn : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ AITargetData* unk10;
};

class EnemyGoals_cpp {
public:
    void __sinit(void);
};

class NPCGoal_Rescue : public Goal<Enemy> {  // base: inlined ctor vtable stores
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 unk15;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline void EnemyGoal_Alert::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk14 = NULL;
}

inline void EnemyGoal_Hide::Reset() {
    this->unk8 = 1;
    this->unk14 = 0;
    this->unk10 = 0;
}

#if 0 // DRAFT: ambiguous access to overloaded function 'TargetContext::Set(Targetable *)' 'TargetContext::Set(MKProp *)'
inline void EnemyGoal_PullLever::Reset() {
    this->unk8 = 1;
    this->unk10.Set(NULL);
}
#endif

inline void EnemyGoal_PushBarrel::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
    this->unk14 = -1;
}

inline void EnemyGoal_Turn::Reset() {
    this->unk8 = 1;
    this->unk10 = NULL;
}

#endif  // SPYRO_SOURCE_ENEMYGOALS_H

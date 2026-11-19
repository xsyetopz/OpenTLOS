#ifndef SPYRO_SOURCE_CYNDERBOSSGOALS_H
#define SPYRO_SOURCE_CYNDERBOSSGOALS_H

#include <dolphin/types.h>
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Character;
class Cynder;
class CynderBossGoal_AttackFlight;
class CynderBossGoal_AttackPhase1;
class CynderBossGoal_AttackPhase2;
class CynderBossGoal_AttackPhase3;
class CynderBossGoal_BreathAttack;
class CynderBossGoal_Death;
class CynderBossGoal_Dive;
class CynderBossGoal_Fly;
class CynderBossGoal_FlyAlongSpline;
class CynderBossGoal_FlyAlongWaypoints;
class CynderBossGoal_FlyAttack1;
class CynderBossGoal_FlyAttack2;
class CynderBossGoal_FlyAttack3;
class CynderBossGoal_FlyToDive;
class CynderBossGoal_FlyingInWait;
class CynderBossGoal_GlideToAttack;
class CynderBossGoal_GlideToLand;
class CynderBossGoal_HitByFury;
class CynderBossGoal_Hover;
class CynderBossGoal_HoverAttack;
class CynderBossGoal_HoverAttackMode;
class CynderBossGoal_HoverLeft;
class CynderBossGoal_HoverRight;
class CynderBossGoal_Idle;
class CynderBossGoal_Land;
class CynderBossGoal_LandingFlight;
class CynderBossGoal_Leap;
class CynderBossGoal_MeleeAttack;
class CynderBossGoal_MoveToTarget;
class CynderBossGoal_RunningTakeOff;
class CynderBossGoal_Stage2Fury;
class CynderBossGoal_Stage3Fury;
class CynderBossGoal_TakeOff;
class CynderBossGoal_TestMode;
class CynderBossGoal_TestTaunt;
class CynderBossGoal_Think;
class CynderBossGoals_cpp;
class CynderGoal_FlyingAttackMode;
class CynderGoal_GroundAttackMode;
class CynderGoal_TurnToAttack;
class EAPItem;
class Enemy;
class EnemyAttack;
class EnemyDamageFeedback;
class MKProp;

class CynderBossGoal_AttackFlight : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<Cynder>* unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ Goal<Cynder>* unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
    /* 0x038 */ Goal<Cynder>* unk38;
    /* 0x03c */ void** unk3C;
};

class CynderBossGoal_AttackPhase1 : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ MKProp* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ EAPItem* unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
};

class CynderBossGoal_AttackPhase2 : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ EAPItem* unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
};

class CynderBossGoal_AttackPhase3 : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ void** unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ Goal<Cynder>* unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
};

class CynderBossGoal_BreathAttack : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ u8 unk18;
};

class CynderBossGoal_Death : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
};

class CynderBossGoal_Dive : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_Fly : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f32 unk10;
};

class CynderBossGoal_FlyAlongSpline : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void PerformBreathAttack(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ AITargetData* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 unk24;
};

class CynderBossGoal_FlyAlongWaypoints : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
};

class CynderBossGoal_FlyAttack1 : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_FlyAttack2 : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ MKProp* unkC;
};

class CynderBossGoal_FlyAttack3 : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_FlyToDive : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ f32 unk10;
};

class CynderBossGoal_FlyingInWait : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<Cynder>* unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ void** unk2C;
    /* 0x030 */ void** unk30;
};

class CynderBossGoal_GlideToAttack : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_GlideToLand : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_HitByFury : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ u8 unk10;
};

class CynderBossGoal_Hover : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_HoverAttack : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Cynder* unkC;
};

class CynderBossGoal_HoverAttackMode : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ Goal<Cynder>* unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ u8 unk3C;
};

class CynderBossGoal_HoverLeft : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_HoverRight : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_Idle : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class CynderBossGoal_Land : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class CynderBossGoal_LandingFlight : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<Cynder>* unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ Goal<Cynder>* unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
    /* 0x038 */ Goal<Cynder>* unk38;
};

class CynderBossGoal_Leap : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ u8 unk20;
};

class CynderBossGoal_MeleeAttack : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class CynderBossGoal_MoveToTarget : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void CalculateRegionEdgeMoveTarget(bool);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ AITargetData* unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ void** unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ Goal<Cynder>* unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ s8 unk3C;
    /* 0x03d */ u8 unk3D;
    /* 0x03e */ u8 unk3E;
};

class CynderBossGoal_RunningTakeOff : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class CynderBossGoal_Stage2Fury : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ s32 unk10;
};

class CynderBossGoal_Stage3Fury : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
    /* 0x010 */ u8 unk10;
};

class CynderBossGoal_TakeOff : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class CynderBossGoal_TestMode : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<Cynder>* unk20;
    /* 0x024 */ void** unk24;
    /* 0x028 */ void** unk28;
    /* 0x02c */ void** unk2C;
    /* 0x030 */ void** unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
    /* 0x038 */ void** unk38;
    /* 0x03c */ void** unk3C;
    /* 0x040 */ Goal<Cynder>* unk40;
    /* 0x044 */ Goal<Cynder>* unk44;
    /* 0x048 */ Goal<Cynder>* unk48;
    /* 0x04c */ Goal<Cynder>* unk4C;
    /* 0x050 */ f32 unk50;
};

class CynderBossGoal_TestTaunt : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

class CynderBossGoal_Think : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Arbitrate(void);
    void AddGoal_AttackPhase3(void);
    void AddGoal_AttackPhase2(EAPItem *);
    void AddGoal_AttackPhase1(EAPItem *);
    void AddGoal_Idle(void);
    void AddGoal_Hit(EnemyDamageFeedback *);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s8 unk20;
    /* 0x021 */ u8 pad21[0x3];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ void** unk30;
    /* 0x034 */ void** unk34;
    /* 0x038 */ void** unk38;
    /* 0x03c */ Goal<Cynder>* unk3C;
    /* 0x040 */ Goal<Cynder>* unk40;
    /* 0x044 */ Goal<Cynder>* unk44;
    /* 0x048 */ void** unk48;
};

class CynderBossGoals_cpp {
public:
    void __sinit(void);
};

class CynderGoal_FlyingAttackMode : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(Cynder *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Cynder* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ Goal<Cynder>* unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ CynderBossGoal_FlyAlongSpline* unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
    /* 0x038 */ Goal<Cynder>* unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ s8 unk40;
};

class CynderGoal_GroundAttackMode : public CompositeGoal<Cynder> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_MoveToAttackRange(EnemyAttack *);
    u8 AddGoal_Attack(EnemyAttack *);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    void AddGoal_Cheer(void);
    void SetParams(AITargetData *, EAPItem *, bool);
    void Init(Cynder *);
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
    /* 0x024 */ Goal<Cynder>* unk24;
    /* 0x028 */ void** unk28;
    /* 0x02c */ Goal<Cynder>* unk2C;
    /* 0x030 */ Goal<Cynder>* unk30;
    /* 0x034 */ Goal<Cynder>* unk34;
    /* 0x038 */ Goal<Cynder>* unk38;
    /* 0x03c */ EAPItem* unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ u8 unk44;
};

class CynderGoal_TurnToAttack : public Goal<Cynder> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Character* unkC;
};

#endif  // SPYRO_SOURCE_CYNDERBOSSGOALS_H

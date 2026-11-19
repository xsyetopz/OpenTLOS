#ifndef SPYRO_SOURCE_ICEBOSSGOALS_H
#define SPYRO_SOURCE_ICEBOSSGOALS_H

#include <dolphin/types.h>
#include "spyro/source/AITargetData.h"
#include "spyro/source/CompositeGoal.h"
#include "spyro/source/Goal.h"

class AITargetData;
class Enemy;
class EnemyDamageFeedback;
class IceBoss;
class IceBossGoal_AttackPhase1;
class IceBossGoal_AttackPhase2;
class IceBossGoal_AttackPhase3;
class IceBossGoal_Cutscene1;
class IceBossGoal_Cutscene2;
class IceBossGoal_Cutscene3;
class IceBossGoal_FormShield;
class IceBossGoal_FormWeapon;
class IceBossGoal_IceBreath;
class IceBossGoal_IceWave;
class IceBossGoal_MeleeAttack1;
class IceBossGoal_MeleeAttack2;
class IceBossGoal_MeleeAttack3;
class IceBossGoal_MoveToPoint;
class IceBossGoal_MoveToTarget;
class IceBossGoal_Stalactite;
class IceBossGoal_SummonWeapon;
class IceBossGoal_Think;

class IceBossGoal_AttackPhase1 : public CompositeGoal<IceBoss> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    void Init(IceBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<IceBoss>* unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ void** unk28;
    /* 0x02c */ Goal<IceBoss>* unk2C;
    /* 0x030 */ Goal<IceBoss>* unk30;
    /* 0x034 */ void** unk34;
    /* 0x038 */ Goal<IceBoss>* unk38;
};

class IceBossGoal_AttackPhase2 : public CompositeGoal<IceBoss> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    void Init(IceBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ IceBoss* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<IceBoss>* unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ void** unk28;
    /* 0x02c */ Goal<IceBoss>* unk2C;
    /* 0x030 */ Goal<IceBoss>* unk30;
    /* 0x034 */ Goal<IceBoss>* unk34;
};

class IceBossGoal_AttackPhase3 : public CompositeGoal<IceBoss> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void AddGoal_AttackIdle(void);
    void AddGoal_Taunt(void);
    void Init(IceBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ IceBoss* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
    /* 0x020 */ Goal<IceBoss>* unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ void** unk28;
    /* 0x02c */ Goal<IceBoss>* unk2C;
    /* 0x030 */ Goal<IceBoss>* unk30;
    /* 0x034 */ Goal<IceBoss>* unk34;
    /* 0x038 */ Goal<IceBoss>* unk38;
};

class IceBossGoal_Cutscene1 : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_Cutscene2 : public Goal<IceBoss> {  // base: vtable prefix
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

class IceBossGoal_Cutscene3 : public Goal<IceBoss> {  // base: vtable prefix
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

class IceBossGoal_FormShield : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_FormWeapon : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_IceBreath : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void Init(IceBoss *);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 unk8;
    /* 0x009 */ s8 unk9;
    /* 0x00a */ u8 padA[0x2];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ void* unk1C;
};

class IceBossGoal_IceWave : public Goal<IceBoss> {  // base: vtable prefix
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

class IceBossGoal_MeleeAttack1 : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ IceBoss* unkC;
    /* 0x010 */ f32 unk10;
};

class IceBossGoal_MeleeAttack2 : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_MeleeAttack3 : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_MoveToPoint : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    void SelectMoveAnimSequence(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
    /* 0x010 */ AITargetData unk10;
    /* 0x060 */ f32 unk60;
};

class IceBossGoal_MoveToTarget : public Goal<IceBoss> {  // base: vtable prefix
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
};

class IceBossGoal_Stalactite : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_SummonWeapon : public Goal<IceBoss> {  // base: vtable prefix
public:
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Terminate(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ u8 unk8;
    /* 0x009 */ u8 pad9[0x3];
    /* 0x00c */ Enemy* unkC;
};

class IceBossGoal_Think : public CompositeGoal<IceBoss> {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Activate(void);
    virtual u8 Update(void);
    virtual void Arbitrate(void);
    void AddGoal_CutScene(void);
    u8 AddGoal_FollowSpawnPath(void);
    void AddGoal_AttackPhase3(void);
    void AddGoal_AttackPhase2(void);
    void AddGoal_AttackPhase1(void);
    void AddGoal_SummonWeapon(void);
    void AddGoal_FormShield(void);
    void AddGoal_FormWeapon(void);
    void AddGoal_Death(EnemyDamageFeedback *);
    void AddGoal_Hit(EnemyDamageFeedback *);
    u8 HasToSummonWeapon(void);
    u8 HasToFormShield(void);
    u8 HasToFormWeapon(void);
    void Init(IceBoss *);
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
    /* 0x021 */ u8 unk21;
    /* 0x022 */ u8 pad22[0x2];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ Goal<IceBoss>* unk28;
    /* 0x02c */ Goal<IceBoss>* unk2C;
    /* 0x030 */ Goal<IceBoss>* unk30;
    /* 0x034 */ Goal<IceBoss>* unk34;
    /* 0x038 */ Goal<IceBoss>* unk38;
    /* 0x03c */ Goal<IceBoss>* unk3C;
    /* 0x040 */ Goal<IceBoss>* unk40;
    /* 0x044 */ Goal<IceBoss>* unk44;
    /* 0x048 */ Goal<IceBoss>* unk48;
    /* 0x04c */ void** unk4C;
    /* 0x050 */ void** unk50;
    /* 0x054 */ void** unk54;
    /* 0x058 */ void** unk58;
    /* 0x05c */ Goal<IceBoss>* unk5C;
    /* 0x060 */ Goal<IceBoss>* unk60;
    /* 0x064 */ Goal<IceBoss>* unk64;
    /* 0x068 */ Goal<IceBoss>* unk68;
};

#endif  // SPYRO_SOURCE_ICEBOSSGOALS_H

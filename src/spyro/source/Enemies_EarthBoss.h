#ifndef SPYRO_SOURCE_ENEMIES_EARTHBOSS_H
#define SPYRO_SOURCE_ENEMIES_EARTHBOSS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"

class EarthBoss;
class EarthBossArm;
class EarthBossArmDescriptor;
class EarthBossDescriptor;
class EarthShockwave;
class Enemy;
class EnemyAttack;
class EnemyDamageFeedback;
class EnemyDescriptor;
class EventMessage;
class FireAndIceFX;
class MKAnimScript;
class MKDynamicBone;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class Matrix;
class SpawnPointRef;

class EarthBoss : public Enemy {  // base: vtable prefix
public:
    virtual ~EarthBoss(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual void Despawn(bool);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void GetCharacterName(void);
    virtual void DoHitFx(EnemyDamageFeedback *);
    EarthBoss(void);
    void InterceptDamage(void);
    void RestartStage(void);
    void CollideWithShatterables(void);
    void ShowFist(bool);
    void UpdatePhrasesAndSounds(void);
    void TempDisableCollision(bool);
    void UpdateEnemyHud(void);
    void SetupCollisionSphere(int, const char *, const char *, float, const MKVector3 &);
    /* 0xb0c */ u8 padB0C[0x1b4];
    /* 0xcc0 */ EarthBossArm* unkCC0;
    /* 0xcc4 */ EarthShockwave* unkCC4;
    /* 0xcc8 */ f32 unkCC8;
    /* 0xccc */ s32 unkCCC;
    /* 0xcd0 */ s32 unkCD0;
    /* 0xcd4 */ s32 unkCD4;
    /* 0xcd8 */ u32 unkCD8;
    /* 0xcdc */ s8 unkCDC;
    /* 0xcdd */ u8 unkCDD;
    /* 0xcde */ u8 padCDE[0x2];
    /* 0xce0 */ s32 unkCE0;
    /* 0xce4 */ s32 unkCE4;
    /* 0xce8 */ s8* unkCE8;
    /* 0xcec */ f32 unkCEC;
    /* 0xcf0 */ f32 unkCF0;
    /* 0xcf4 */ EventMessage unkCF4;
};

class EarthBossArm : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EarthBossArm(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual void pure_slot12() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot13() = 0;  // name unknown: no descendant fills this slot
    virtual void GetProp(void);
    virtual s32 GetEnemy(void);
    virtual s32 IsHero(void);
    virtual s32 IsFriend(void);
    virtual s32 IsEnemy(void);
    virtual s32 IsShatterable(void);
    virtual s32 IsDead(void);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetVel(void);
    virtual void * GetCollisionInfo(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual f32 GetTimeLastHit(void);
    virtual s32 IsAttacking(void);
    virtual s32 GetAttackerManager(void);
    void DoHitFx(EnemyDamageFeedback *);
    s32 CheckMeleeHit(EnemyAttack *);
    void Extend(void);
    void Aim(const MKVector3 &);
    void Retract(void);
    void SetRetracted(void);
    void UpdateExtensionBone(MKDynamicBone *, void *);
    void UpdateElbowBone(MKDynamicBone *, void *);
    void UpdateShoulderBone(MKDynamicBone *, void *);
    void UpdateRetraction(void);
    void UpdateExtension(void);
    void UpdateTarget(void);
    void InitBoneData(int, const char *);
    void Init2(EarthBoss *);
    /* 0x04c */ u8 pad4C[0x94];
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ u8 padF0[0x54];
    /* 0x144 */ s32 unk144;
    /* 0x148 */ u8 pad148[0x1fc];
    /* 0x344 */ s32 unk344;
    /* 0x348 */ u8 pad348[0x18];
    /* 0x360 */ s32 unk360;
    /* 0x364 */ s32 unk364;
    /* 0x368 */ s32 unk368;
    /* 0x36c */ MKAnimScript* unk36C;
    /* 0x370 */ Enemy* unk370;
    /* 0x374 */ MKAnimScript* unk374;
    /* 0x378 */ f64 unk378;
    /* 0x380 */ f64 unk380;
    /* 0x388 */ s32 unk388;
    /* 0x38c */ s32 unk38C;
    /* 0x390 */ u8 unk390;
    /* 0x391 */ u8 pad391[0xf];
    /* 0x3a0 */ FireAndIceFX unk3A0;
    /* 0x44c */ u8 pad44C[0x4];
    /* 0x450 */ f32 unk450;
    /* 0x454 */ u8 pad454[0x4];
    /* 0x458 */ f64 unk458;
    /* 0x460 */ f64 unk460;
    /* 0x468 */ MKMaterial* unk468;
};

class EarthBossArmDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
};

class EarthBossDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    EarthBossDescriptor(void);
    /* 0x2b4 */ u8 pad2B4[0x48];
    /* 0x2fc */ f32 unk2FC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthBoss::EarthBoss() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    M2C_FIELD(this, s32 *, 0xCF4) = 0;
    this->unkCDC.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthBoss::~EarthBoss() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
    if (&this->unkCDC != NULL) {
        this->unkCDC.Deinit();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
inline EarthBossArm::~EarthBossArm() {
    s32 temp_cr0_eq_5706;

    temp_cr0_eq_5706 = this == NULL;
    if (temp_cr0_eq_5706 == 0) {
        this->unk4C.__vptr = &__vt.unk38;
        if (temp_cr0_eq_5706 == 0) {
        }
    }
}
#endif

inline s32 EarthBossArm::GetAttackerManager() {
    return 0;
}

inline s32 EarthBossArm::IsAttacking() {
    return 0;
}

inline f32 EarthBossArm::GetTimeLastHit() {
    return 0.0f;
}

inline void EarthBossArm::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
}

inline s32 EarthBossArm::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_5770;
    f64 temp_f1_5769;
    void *temp_r4_5767;

    temp_r4_5767 = this->unk8;
    temp_f1_5769 = M2C_FIELD(temp_r4_5767, f64 *, 0x30);
    temp_f0_5770 = M2C_FIELD(temp_r4_5767, f64 *, 0x38);
    sp8 = temp_f1_5769;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_5769;
    sp10 = temp_f0_5770;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_5770;
    return 1;
}

inline s32 EarthBossArm::IsDead() {
    return 0;
}

inline s32 EarthBossArm::IsShatterable() {
    return 0;
}

inline s32 EarthBossArm::IsEnemy() {
    return 1;
}

inline s32 EarthBossArm::IsFriend() {
    return 0;
}

inline s32 EarthBossArm::IsHero() {
    return 0;
}

inline s32 EarthBossArm::GetEnemy() {
    return 0;
}

inline void EarthBossArm::GetProp() {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline EarthBossDescriptor::EarthBossDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_EARTHBOSS_H

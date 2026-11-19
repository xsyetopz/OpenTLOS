#ifndef SPYRO_SOURCE_ENEMY_H
#define SPYRO_SOURCE_ENEMY_H

#include <dolphin/types.h>
#include "spyro/source/Character.h"

class AITargetData;
class AnimSequence;
class AnimSequenceType;
class AnimTransition;
class BreathHitMessage;
class Character;
class Enemy;
class EnemyAttack;
class EnemyDamageFeedback;
class EnemyGeneratorDoor;
class Enemy_cpp;
class HurtMessage;
class MKAnim;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKVector3;
class Matrix;
class SpawnPointObject;
class SpawnPointRef;

class AnimTransition {
public:
    /* 0x000 */ u32 unk0;
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ f32 unk18;
};

class Enemy : public Character {  // base: ctor/dtor vtable stores
public:
    virtual ~Enemy(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void SetDefaults(void);
    virtual void EnableCollision(bool);
    virtual void Despawn(bool);
    virtual void Recycle(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual void UpdateMovementCustom(void);
    virtual void UpdateModel(void);
    virtual void SetAnim(MKAnim *, float, float, float, unsigned int);
    virtual void SetupCollision(void);
    virtual void pure_slot31() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot32() = 0;  // name unknown: no descendant fills this slot
    virtual void GetProp(void);
    virtual void GetEnemy(void);
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
    virtual void CheckAnimEvents(void);
    virtual s32 IsTargetBehindWall(AITargetData *);
    virtual void IsTargetBehindWall(void);
    virtual void InitSpawnerObject(int, int, int);
    virtual void UpdateAI(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual s32 Spawn(SpawnPointObject *);
    virtual void Spawn(EnemyGeneratorDoor *);
    virtual void AddCameraCollisionItem(void);
    virtual void RemoveCameraCollisionItem(void);
    virtual s32 IsAttacking(void);
    virtual s32 IsObscuringCamera(int *);
    virtual u8 CanStrafeLeft(AITargetData *);
    virtual u8 CanStrafeRight(AITargetData *);
    virtual u8 CanIdle(void);
    virtual s32 CanTurn(void);
    virtual s32 CanCheer(void);
    virtual s32 CanDie(void);
    virtual s32 CanWalk(void);
    virtual s32 CanRun(void);
    virtual s32 CanJump(void);
    virtual s32 CanFly(void);
    virtual s32 CanHover(void);
    virtual s32 CanGlide(void);
    virtual s32 CanLand(void);
    virtual s32 CanDrop(void);
    virtual s32 CanPickUp(void);
    virtual s32 CanAttackRanged(void);
    virtual s32 CanSleep(void);
    virtual s32 CanSleepOnGround(void);
    virtual s32 CanAlert(void);
    virtual s32 CanTaunt(void);
    virtual s32 CanCower(void);
    virtual s32 CanPanic(void);
    virtual s32 CanGiveOrders(void);
    virtual s32 CanBarricade(void);
    virtual s32 CanSummon(void);
    virtual s32 CanSummonWall(void);
    virtual s32 CanCustomSpawn(void);
    virtual s32 CanOperateLever(void);
    virtual u8 CanMoveAwayFromHero(void);
    virtual u8 CanMoveAwayBack(void);
    virtual u8 CanMoveAwayForward(void);
    virtual s32 CanMoveAwayLeft(void);
    virtual s32 CanMoveAwayRight(void);
    virtual s32 CheckForCliff(const MKVector3 &);
    virtual void GetCharacterName(void);
    virtual void DoHitFx(EnemyDamageFeedback *);
    virtual void DoDeadFx(void);
    virtual s32 TryFreeze(float, bool, bool);
    virtual s32 TryFreezeBall(void);
    virtual void UpdateFrozenBallMovement(void);
    virtual void DefrostBall(void);
    virtual s32 IsInFrozenBall(void);
    virtual void OnArmourDestroyed(void);
    virtual void OnSummon(void);
    virtual void DrawCustomGlow(void);
    Enemy(void);
    void TestForTraps(void);
    void TestForSpikes(void);
    void SnapToDirOfHitSource(void);
    void ChillFx_Update(void);
    void ChillFx_EndChill(void);
    void ChillFx_AddChill(void);
    void ThawIfFrozen(void);
    s32 SpawnGems(int, int, bool);
    void EnableBlurFX(bool);
    void SetInvulnerableToBreathAttacks(bool, bool);
    void SetInvulnerableToMeleeAttacks(bool, bool);
    void SetCurrAnimSet(int);
    void SetWorldMatrix(Matrix *);
    void UpdateLighting(void);
    void SetShockSoundEvent(int);
    void Armour_SpawnFragments(void);
    void Armour_Destroy(void);
    void Armour_SetDefaults(void);
    void UpdateBodyFX(void);
    void FindAndZapFriends(BreathHitMessage *);
    void DoBlockFx(unsigned int, const MKVector3 &);
    void DoHitSoundFx(unsigned int);
    void ClearHitAndDeathFX(void);
    void DoDeathFx(unsigned int);
    void CheckForHazards(void);
    void DisableCurrentProjectile(bool, const MKVector3 &);
    void SetHitTarget(bool);
    void SetRunMovementSpeed(bool);
    void SetWalkMovementSpeed(bool);
    void SetIdleMovementSpeed(bool);
    void TakeDamage(EnemyDamageFeedback *, bool);
    s32 IsFrozen(void);
    u8 IsBeingKnockedDown(void);
    u8 IsKnockedDown(void);
    u8 IsKnockedUp(void);
    s32 IsSpawning(void);
    s32 IsPatrolling(void);
    s32 IsIdling(void);
    u8 IsInvulnerable(void);
    u8 IsDying(void);
    u8 IsBlocking(void);
    void IsFlinching(void);
    s32 WasHit(void);
    void SetArmour(float);
    f32 GetHealthPercentage(void);
    void GetMaxHealth(void);
    void SetHealth(float);
    void ProcessDamageQueue(EnemyDamageFeedback *, bool);
    u8 InWaterVolume(const MKVector3 &, int *);
    void PlayHitHeroSound(HurtMessage *, MKProp *);
    s32 HasWaypoints(void);
    s32 CheckMeleeHit(EnemyAttack *, int);
    s32 MeleeDamageTarget(MKProp *, EnemyAttack *, const MKVector3 &, int);
    u8 HurtHero(MKProp *, EnemyAttack *, const MKVector3 &, int);
    EnemyDamageFeedback * AddDamage(float, bool, const MKVector3 &, int, int, bool, bool, MKCollisionInfo *, float, float);
    void SetupExclusionRegion(void);
    void TryChangeEnemyRegion(void);
    void SetupEnemyRegion(const MKVector3 &, float);
    void UpdateFlyingRotations(Matrix *, MKVector3 *, MKVector3, float, float, float);
    s32 SelectTarget(void);
    s32 SelectDefensiveAttack(float, unsigned int);
    s32 SelectAttack(int, int);
    s32 SelectAttack(float, unsigned int, bool, bool);
    u8 CanStrafe(void);
    u8 IsInsideFOV(const MKVector3 &);
    void DrawShieldOverride(void);
    void TriggerShieldGlow(int);
    u8 IsInsideEnemyRegion(void);
    void SetAnim(AnimSequence *, AnimTransition *, float, unsigned int);
    void SetAnim(AnimSequenceType, int, int, float, unsigned int, bool);
};

class Enemy_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline Enemy::~Enemy() {
    M2C_UNK *temp_r0_5272;
    M2C_UNK *temp_r0_5288;
    M2C_UNK *temp_r4_5275;
    M2C_UNK *temp_r4_5291;

    if (this != NULL) {
        this->unk110.vtable5A8 = &__vt + 0x84;
        if ((&this->unk110.unk898 != NULL) && (&this->unk110.unk898 != NULL)) {
            KDSound_Stop(&this->unk110.unk898);
        }
        if (this != NULL) {
            if (&this->unk110.unk560 != NULL) {
                temp_r0_5272 = this->unk110.unk568;
                if (temp_r0_5272 != NULL) {
                    temp_r4_5275 = &this->unk110.unk560;
                    if (temp_r0_5272 != temp_r4_5275) {
                        M2C_FIELD(this->unk110.unk56C, M2C_UNK **, 8) = temp_r0_5272;
                        M2C_FIELD(this->unk110.unk568, M2C_UNK **, 0xC) = (M2C_UNK *) this->unk110.unk56C;
                        this->unk110.unk56C = temp_r4_5275;
                        this->unk110.unk568 = temp_r4_5275;
                    }
                }
            }
            if (&this->unk110.unk538 != NULL) {
                temp_r0_5288 = this->unk110.unk558;
                if (temp_r0_5288 != NULL) {
                    temp_r4_5291 = &this->unk110.unk538;
                    if (temp_r0_5288 != temp_r4_5291) {
                        M2C_FIELD(this->unk110.unk55C, M2C_UNK **, 0x20) = temp_r0_5288;
                        M2C_FIELD(this->unk110.unk558, M2C_UNK **, 0x24) = (M2C_UNK *) this->unk110.unk55C;
                        this->unk110.unk55C = temp_r4_5291;
                        this->unk110.unk558 = temp_r4_5291;
                    }
                }
            }
            if (this != NULL) {
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
inline Enemy::Enemy() {
    M2C_UNK *temp_r7_5347;
    M2C_UNK *temp_r8_5345;

    this->unk110.__vptr = &__vt;
    this->unk110.unk478.MovementObject();
    this->unk110.unk550 = 0;
    temp_r8_5345 = &this->unk110.unk538;
    this->unk110.unk554 = 0;
    temp_r7_5347 = &this->unk110.unk560;
    this->unk110.unk558 = temp_r8_5345;
    this->unk110.unk55C = temp_r8_5345;
    this->unk110.unk54C = 0;
    this->unk110.unk548 = 0.0f;
    M2C_FIELD(this, s32 *, 0x670) = 0;
    this->unk110.unk564 = 0;
    this->unk110.unk568 = temp_r7_5347;
    this->unk110.unk56C = temp_r7_5347;
    this->unk110.unk59C = 0;
    this->unk110.vtable5A8 = &__vt;
    this->unk110.unk5AC = -1;
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unk110.unk700 = 0;
    this->unk110.unk704 = 0;
    this->unk110.unk708 = 0;
    this->unk110.unk70C = 0.0f;
    this->unk110.unk710 = 0.0f;
    this->unk110.unk714 = 0.0f;
    this->unk110.unk718 = 0.0f;
    this->unk110.unk738 = 0;
    this->unk110.unk73C = 0;
    this->unk110.unk740 = 0;
    this->unk110.unk744 = 0.0f;
    this->unk110.unk748 = 0.0f;
    this->unk110.unk74C = 0.0f;
    this->unk110.unk750 = 0.0f;
    this->unk110.unk898 = 0;
    this->unk110.unk8CC = 0;
    this->unk110.unk8C8 = 0;
    this->unk110.unk8C0 = 0;
    this->unk110.unk8C4 = 0;
    this->unk110.unk938 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
inline void Enemy::IsTargetBehindWall() {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(AITargetData *), 0x110)(&this->unk110.unk760);
}
#endif

inline void Enemy::UpdateMovementCustom() {

}

#if 0 // DRAFT: undefined identifier 'unk8D0'
inline void Enemy::GetCharacterName() {
    this->unk110.unk8D0.GetName();
}
#endif

inline s32 Enemy::TryFreezeBall() {
    return 0;
}

inline void Enemy::UpdateFrozenBallMovement() {

}

inline void Enemy::DefrostBall() {

}

inline s32 Enemy::IsInFrozenBall() {
    return 0;
}

inline void Enemy::OnArmourDestroyed() {

}

inline void Enemy::DrawCustomGlow() {

}

inline f32 Enemy::GetTimeLastHit() {
    return 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unk928'
inline f32 Enemy::GetCollisionHeight() {
    return this->unk110.unk928->unk64;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk928'
inline f32 Enemy::GetCollisionRadius() {
    return this->unk110.unk928->unk60;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk524'
inline void *Enemy::GetCollisionInfo() {
    return this->unk110.unk524;
}
#endif

inline void Enemy::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x598);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x5A0);
}

inline s32 Enemy::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_130;
    f64 temp_f1_129;
    void *temp_r4_127;

    temp_r4_127 = this->unk8;
    temp_f1_129 = M2C_FIELD(temp_r4_127, f64 *, 0x30);
    temp_f0_130 = M2C_FIELD(temp_r4_127, f64 *, 0x38);
    sp8 = temp_f1_129;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_129;
    sp10 = temp_f0_130;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_130;
    return 1;
}

inline s32 Enemy::IsShatterable() {
    return 0;
}

inline s32 Enemy::IsEnemy() {
    return ((u32) M2C_FIELD(this->unk0, u32 *, 0xC) >> 3U) & 1;
}

inline s32 Enemy::IsFriend() {
    return ((u32) M2C_FIELD(this->unk0, u32 *, 0xC) >> 2U) & 1;
}

inline s32 Enemy::IsHero() {
    return 0;
}

inline void Enemy::GetEnemy() {

}

inline void Enemy::GetProp() {

}

#if 0 // DRAFT: undefined identifier 'unk6F0'
inline u8 Enemy::IsInsideEnemyRegion() {
    M2C_UNK sp8;
    u8 var_r31_10920;

    var_r31_10920 = 0;
    if (this->unk110.unk6F0.IsPointWithin(*((MKVector3 *) &this->unk110.unk478)) != 0) {
        sp8.GetRegionPos();
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((f32) fabs(spC - M2C_FIELD(this, f32 *, 0x58C)) == 500.0f) {
            var_r31_10920 = 1;
        }
    }
    return var_r31_10920;
}
#endif

#endif  // SPYRO_SOURCE_ENEMY_H

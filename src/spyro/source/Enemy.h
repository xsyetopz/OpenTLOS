#ifndef SPYRO_SOURCE_ENEMY_H
#define SPYRO_SOURCE_ENEMY_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"

class AITargetData;
class AnimSequence;
class AnimSequenceType;
class AnimTransition;
class AttackSweepData;
class BoneBlurFX;
class BreathHitMessage;
class Character;
class CharacterBreathFX;
class CharacterFireFX;
class CharacterGraphNode;
class CharacterZapFX;
class EAPManager;
class Enemy;
class EnemyAttack;
class EnemyDamageFeedback;
class EnemyDescriptor;
class EnemyGeneratorDoor;
class EnemyMovementManager;
class EnemyRegion;
class Enemy_cpp;
class FireAndIceFX;
class HurtMessage;
class KDSound_LoopSoundEvent;
class MKAnim;
class MKCollisionInfo;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKVector3;
class Matrix;
class MeleeTrails;
class Name;
class NodeLookAt;
class SpawnPointObject;
class SpawnPointRef;
class SpawnerObject;

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
    /* 0x6b6 */ u8 pad6B6[0xa];
    /* 0x6c0 */ NodeLookAt unk6C0;
    /* 0x6f9 */ u8 pad6F9[0x7];
    /* 0x700 */ f64 unk700;
    /* 0x708 */ u8 pad708[0x8];
    /* 0x710 */ MKVector3 unk710;
    /* 0x720 */ f32 unk720;
    /* 0x724 */ f32 unk724;
    /* 0x728 */ f32 unk728;
    /* 0x72c */ u8 pad72C[0x4];
    /* 0x730 */ MKVector3 unk730;
    /* 0x740 */ f64 unk740;
    /* 0x748 */ f64 unk748;
    /* 0x750 */ FireAndIceFX unk750;
    /* 0x7fc */ u8 pad7FC[0x4];
    /* 0x800 */ EnemyRegion unk800;
    /* 0x838 */ EnemyRegion unk838;
    /* 0x870 */ AITargetData unk870;
    /* 0x8c0 */ AITargetData unk8C0;
    /* 0x910 */ f64 unk910;
    /* 0x918 */ f32 unk918;
    /* 0x91c */ u8 pad91C[0x4];
    /* 0x920 */ s32 unk920;
    /* 0x924 */ s32 unk924;
    /* 0x928 */ f32 unk928;
    /* 0x92c */ f32 unk92C;
    /* 0x930 */ s32 unk930;
    /* 0x934 */ f32 unk934;
    /* 0x938 */ s32 unk938;
    /* 0x93c */ s32 unk93C;
    /* 0x940 */ s32 unk940;
    /* 0x944 */ u8 unk944;
    /* 0x945 */ u8 pad945[0x3];
    /* 0x948 */ EnemyDamageFeedback unk948;
    /* 0x97d */ u8 pad97D[0x3];
    /* 0x980 */ KDSound_LoopSoundEvent unk980;
    /* 0x9a8 */ s32 unk9A8;
    /* 0x9ac */ u8 pad9AC[0x24];
    /* 0x9d0 */ s32 unk9D0;
    /* 0x9d4 */ s32 unk9D4;
    /* 0x9d8 */ s32 unk9D8;
    /* 0x9dc */ s32 unk9DC;
    /* 0x9e0 */ Name unk9E0;
    /* 0x9e8 */ EnemyMovementManager unk9E8;
    /* 0x9fd */ u8 pad9FD[0x3];
    /* 0xa00 */ void* unkA00;
    /* 0xa04 */ CharacterZapFX* unkA04;
    /* 0xa08 */ CharacterFireFX* unkA08;
    /* 0xa0c */ CharacterBreathFX* unkA0C;
    /* 0xa10 */ BoneBlurFX* unkA10;
    /* 0xa14 */ MeleeTrails* unkA14;
    /* 0xa18 */ MKMaterial* unkA18;
    /* 0xa1c */ u32* unkA1C;
    /* 0xa20 */ EnemyAttack* unkA20;
    /* 0xa24 */ EnemyAttack* unkA24;
    /* 0xa28 */ void** unkA28;
    /* 0xa2c */ void* unkA2C;
    /* 0xa30 */ AttackSweepData* unkA30;
    /* 0xa34 */ u8 padA34[0x4];
    /* 0xa38 */ EnemyDescriptor* unkA38;
    /* 0xa3c */ void** unkA3C;
    /* 0xa40 */ void** unkA40;
    /* 0xa44 */ void* unkA44;
    /* 0xa48 */ s32 unkA48;
    /* 0xa4c */ SpawnerObject* unkA4C;
    /* 0xa50 */ AnimSequence* unkA50;
    /* 0xa54 */ AnimTransition* unkA54;
    /* 0xa58 */ s32 unkA58;
    /* 0xa5c */ EAPManager* unkA5C;
    /* 0xa60 */ f32 unkA60;
    /* 0xa64 */ u8 padA64[0x4];
    /* 0xa68 */ f32 unkA68;
    /* 0xa6c */ f32 unkA6C;
    /* 0xa70 */ f32 unkA70;
    /* 0xa74 */ f32 unkA74;
    /* 0xa78 */ f32 unkA78;
    /* 0xa7c */ f32 unkA7C;
    /* 0xa80 */ u32 unkA80;
    /* 0xa84 */ CharacterGraphNode* unkA84;
    /* 0xa88 */ u8 padA88[0x8];
    /* 0xa90 */ s32 unkA90;
    /* 0xa94 */ Enemy* unkA94;
    /* 0xa98 */ s32 unkA98;
    /* 0xa9c */ u8 unkA9C;
    /* 0xa9d */ u8 padA9D[0x3];
    /* 0xaa0 */ f32 unkAA0;
    /* 0xaa4 */ f32 unkAA4;
    /* 0xaa8 */ f32 unkAA8;
    /* 0xaac */ f32 unkAAC;
    /* 0xab0 */ f32 unkAB0;
    /* 0xab4 */ f32 unkAB4;
    /* 0xab8 */ f32 unkAB8;
    /* 0xabc */ f32 unkABC;
    /* 0xac0 */ f32 unkAC0;
    /* 0xac4 */ f32 unkAC4;
    /* 0xac8 */ f32 unkAC8;
    /* 0xacc */ f32 unkACC;
    /* 0xad0 */ f32 unkAD0;
    /* 0xad4 */ s32 unkAD4;
    /* 0xad8 */ s32 unkAD8;
    /* 0xadc */ s32 unkADC;
    /* 0xae0 */ s32 unkAE0;
    /* 0xae4 */ s32 unkAE4;
    /* 0xae8 */ s32 unkAE8;
    /* 0xaec */ s32 unkAEC;
    /* 0xaf0 */ s32 unkAF0;
    /* 0xaf4 */ s32 unkAF4;
    /* 0xaf8 */ s32 unkAF8;
    /* 0xafc */ s32 unkAFC;
    /* 0xb00 */ u8 unkB00;
    /* 0xb01 */ u8 unkB01;
    /* 0xb02 */ u8 unkB02;
    /* 0xb03 */ u8 padB03[0x1];
    /* 0xb04 */ s32 unkB04;
    /* 0xb08 */ u8 unkB08;
    /* 0xb09 */ u8 unkB09;
    /* 0xb0a */ u8 unkB0A;
    /* 0xb0b */ u8 unkB0B;
};

class Enemy_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Enemy::~Enemy() {
    Character *temp_r0_5288;
    M2C_UNK *temp_r0_5272;
    M2C_UNK *temp_r4_5275;
    SB2 **temp_r4_5291;

    if (this != NULL) {
        M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
        if ((&this->unk980.unk14 != NULL) && (&this->unk980.unk14 != NULL)) {
            KDSound_Stop(&this->unk980.unk14);
        }
        if (this != NULL) {
            if (&this->unk670 != NULL) {
                temp_r0_5272 = this->unk678;
                if (temp_r0_5272 != NULL) {
                    temp_r4_5275 = &this->unk670;
                    if (temp_r0_5272 != temp_r4_5275) {
                        M2C_FIELD(this->unk67C, M2C_UNK **, 8) = temp_r0_5272;
                        M2C_FIELD(this->unk678, M2C_UNK **, 0xC) = (M2C_UNK *) this->unk67C;
                        this->unk67C = temp_r4_5275;
                        this->unk678 = temp_r4_5275;
                    }
                }
            }
            if (&this->unk640 != NULL) {
                temp_r0_5288 = this->unk660;
                if (temp_r0_5288 != NULL) {
                    temp_r4_5291 = &this->unk640;
                    if (temp_r0_5288 != temp_r4_5291) {
                        M2C_FIELD(this->unk664, Character **, 0x20) = temp_r0_5288;
                        this->unk660->unk24 = M2C_BITWISE(f32, this->unk664);
                        this->unk664 = temp_r4_5291;
                        this->unk660 = (Character *) temp_r4_5291;
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
    SB2 **temp_r8_5345;

    this->unk110.__vptr = &__vt;
    this->unk660 = 0;
    temp_r8_5345 = &this->unk640;
    this->unk664 = 0;
    temp_r7_5347 = &this->unk670;
    this->unk660 = (Character *) temp_r8_5345;
    this->unk664 = temp_r8_5345;
    this->unk65C = 0;
    this->unk658 = 0.0f;
    M2C_FIELD(this, s32 *, 0x670) = 0;
    this->unk674 = 0;
    this->unk678 = temp_r7_5347;
    this->unk67C = temp_r7_5347;
    this->unk6A4 = 0;
    M2C_FIELD(this, struct __vt **, 0x6B8) = &__vt;
    M2C_FIELD(this, s32 *, 0x6BC) = -1;
    M2C_FIELD(this, struct __vt **, 0x6B8) = (struct __vt *) (&__vt + 0x84);
    M2C_FIELD(this, s32 *, 0x810) = 0;
    M2C_FIELD(this, s32 *, 0x814) = 0;
    M2C_FIELD(this, s32 *, 0x818) = 0;
    M2C_FIELD(this, f32 *, 0x81C) = 0.0f;
    this->unk800.unk10 = 0.0f;
    this->unk800.unk14 = 0.0f;
    this->unk800.unk18 = 0.0f;
    M2C_FIELD(this, s32 *, 0x848) = 0;
    M2C_FIELD(this, s32 *, 0x84C) = 0;
    M2C_FIELD(this, s32 *, 0x850) = 0;
    M2C_FIELD(this, f32 *, 0x854) = 0.0f;
    this->unk838.unk10 = 0.0f;
    this->unk838.unk14 = 0.0f;
    this->unk838.unk18 = 0.0f;
    this->unk980.unk14 = 0;
    this->unk9DC = 0;
    this->unk9D8 = 0;
    this->unk9D0 = 0;
    this->unk9D4 = 0;
    this->unkA30 = NULL;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
inline void Enemy::IsTargetBehindWall() {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(Enemy *, M2C_UNK *), 0x110)(this, &this->unk838.unk28);
}
#endif

inline void Enemy::UpdateMovementCustom() {

}

inline void Enemy::GetCharacterName() {
    this->unk9E0.GetName();
}

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

#if 0 // DRAFT: undefined identifier 'unk64'
inline f32 Enemy::GetCollisionHeight() {
    return this->unkA20->unk64;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk60'
inline f32 Enemy::GetCollisionRadius() {
    return this->unkA20->unk60;
}
#endif

inline void *Enemy::GetCollisionInfo() {
    return this->unk634;
}

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

#if 0 // DRAFT: expression syntax error
inline u8 Enemy::IsInsideEnemyRegion() {
    M2C_UNK sp8;
    u8 var_r31_10920;

    var_r31_10920 = 0;
    if (this->unk750.unkA0.IsPointWithin(*((MKVector3 *) &this->unk588)) != 0) {
        sp8.GetRegionPos();
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((f32) fabs(spC - this->unk588.unk0) == 500.0f) {
            var_r31_10920 = 1;
        }
    }
    return var_r31_10920;
}
#endif

#endif  // SPYRO_SOURCE_ENEMY_H

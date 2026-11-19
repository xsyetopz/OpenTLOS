#include "spyro/source/Enemies_Convex.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/ConvexTier2Goals.h"
#include "spyro/source/ConvexTier3Goals.h"
#include "spyro/source/Crate.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/MovementObject.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern void **gMK;

void ConvexTier3::Message(MKMessage *arg0) {
    Enemy::Message(arg0);
}

void ConvexTier3::UpdateMovementCustom() {
    UpdateModel();
}

void *ConvexTier3::Update() {
    Enemy::Update();
}

void ConvexTier3::Despawn(bool arg0) {
    Enemy::Despawn(arg0);
}

s32 ConvexTier3::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    Enemy::Spawn(arg0, arg1);
}

void ConvexTier3::UpdateCollisionItems() {

}

void ConvexTier3::SetupCollision() {

}

void ConvexTier3::Deinit() {
    Enemy::Deinit();
}

#if 0 // DRAFT: illegal type
f32 ConvexTier3::Resolve() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ModelCloth *temp_r3_143;
    s32 var_r29_147;
    s32 var_r31_148;

    Enemy::Resolve();
    temp_r3_143 = MKModel_GetCloth(this->unk4);
    if (temp_r3_143 != NULL) {
        var_r29_147 = 0;
        var_r31_148 = 0;
loop_3:
        if (var_r29_147 < (s32) temp_r3_143->unk4) {
            sp10 = 0.0f;
            sp8 = 0.0f;
            spC = 0.0f;
            sp20 = (f64) sp10;
            sp18 = (f64) sp8;
            ((MKCloth *) (temp_r3_143->unk8 + var_r31_148))->SetForce(0, *((MKVector3 *) &sp18), -1);
            var_r29_147 += 1;
            var_r31_148 += 0xF8;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexTier3::Init() {
    ConvexTier3Goal_Think *temp_r31_193;

    Enemy::Init();
    operator new(0x3CU, NULL, 0);
    temp_r31_193 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_193 != NULL) {
        temp_r31_193->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_193->unk4 = 0;
        temp_r31_193->unk8 = 1;
        temp_r31_193->unk9 = 0;
        temp_r31_193->unkC = NULL;
        temp_r31_193->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_193->unk1C = NULL;
        temp_r31_193->unk18 = 0;
        temp_r31_193->unk10 = 0;
        temp_r31_193->unk14 = 0;
        temp_r31_193->__vptr = &__vt;
    }
    temp_r31_193->Init((Enemy *) this);
    this->unkA3C = &temp_r31_193->__vptr;
}
#endif

void ConvexTier3Descriptor::Deinit() {
    EnemyDescriptor::Deinit();
}

void ConvexTier3Descriptor::Init() {
    EnemyDescriptor::Init();
}

void ConvexTier2::Message(MKMessage *arg0) {
    Enemy::Message(arg0);
}

#if 0 // DRAFT: undefined identifier '__vt'
void ConvexTier2::UpdateMovementCustom() {
    M2C_UNK *sp44;
    f32 sp40;
    s8 sp3C;
    f32 sp38;
    s32 sp34;
    s8 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp8;
    SB2 *temp_r6_300;

    sp44 = &__vt;
    sp18 = 0x30;
    sp1C = 0;
    sp44 = &__vt;
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    sp30 = 0;
    sp34 = -1;
    sp38 = 0.0f;
    sp3C = 0;
    sp40 = 0.0f;
    sp18 = 0x31;
    this->unk110.unk440 = (MKMessage *) &sp18;
    UpdateRotation();
    UpdateVelocity();
    temp_r6_300 = this->unk640;
    if (((temp_r6_300 != NULL) && (((u8) temp_r6_300->unk464 >> 7U) & 1)) || (((u8) this->unk6B5 >> 1U) & 1)) {

    }
    ((MovementObject *) &sp8)->Update((u8) &this->unk588);
    this->unk100 = sp8;
    this->unk108 = sp10;
    UpdateModel(sp8);
}
#endif

void *ConvexTier2::Update() {
    Enemy::Update();
}

void ConvexTier2::Despawn(bool arg0) {
    Enemy::Despawn(arg0);
}

s32 ConvexTier2::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    if (Enemy::Spawn(arg0, arg1) != 0) {
        SetupEnemyRegion(this->unk588, 3000.0f);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ConvexTier2::UpdateCollisionItems() {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    sp48.operator*(200.0f);
    sp18 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp48);
    this->unk60 = sp18;
    sp20 = this->unk588.unk8 + sp48.unk8;
    sp58 = sp18;
    sp60 = (f64) sp20;
    this->unk68 = (f64) sp20;
    sp28.operator*(1000.0f);
    sp8 = M2C_FIELD(this, f64 *, 0x588) - M2C_BITWISE(f64, sp28);
    this->unk70 = sp8;
    sp10 = this->unk588.unk8 - sp28.unk8;
    sp38 = sp8;
    sp40 = (f64) sp10;
    this->unk78 = (f64) sp10;
}
#endif

#if 0 // DRAFT: function call 'GetCollisionRadius(Enemy *, double, double, double)' does
void ConvexTier2::SetupCollision() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31_480;
    void *temp_r31_457;

    UpdateCollisionItems();
    temp_r31_457 = checked_cast<ConvexTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    temp_f31_480 = GetCollisionRadius((f64) sp18, (f64) sp10, (f64) sp8);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddCapsule((MKVector3 *) &this->unk60, (MKVector3 *) &this->unk70, temp_f31_480, *((MKVector4 *) &sp38), *((MKVector4 *) &sp28), (MKCollisionMode) 2, (MKCollisionInfo *) this->unk634, M2C_FIELD(temp_r31_457, u32 *, 0x70));
}
#endif

void ConvexTier2::Deinit() {
    Enemy::Deinit();
}

#if 0 // DRAFT: illegal type
f32 ConvexTier2::Resolve() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ModelCloth *temp_r3_528;
    s32 var_r29_532;
    s32 var_r31_533;

    Enemy::Resolve();
    temp_r3_528 = MKModel_GetCloth(this->unk4);
    if (temp_r3_528 != NULL) {
        var_r29_532 = 0;
        var_r31_533 = 0;
loop_3:
        if (var_r29_532 < (s32) temp_r3_528->unk4) {
            sp10 = 0.0f;
            sp8 = 0.0f;
            spC = 0.0f;
            sp20 = (f64) sp10;
            sp18 = (f64) sp8;
            ((MKCloth *) (temp_r3_528->unk8 + var_r31_533))->SetForce(0, *((MKVector3 *) &sp18), -1);
            var_r29_532 += 1;
            var_r31_533 += 0xF8;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void ConvexTier2::Init() {
    ConvexTier2Goal_Think *temp_r31_578;

    Enemy::Init();
    operator new(0x40U, NULL, 0);
    temp_r31_578 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_578 != NULL) {
        temp_r31_578->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_578->unk4 = 0;
        temp_r31_578->unk8 = 1;
        temp_r31_578->unk9 = 0;
        temp_r31_578->unkC = NULL;
        temp_r31_578->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_578->unk1C = NULL;
        temp_r31_578->unk18 = 0;
        temp_r31_578->unk10 = 0;
        temp_r31_578->unk14 = 0;
        temp_r31_578->__vptr = &__vt;
    }
    temp_r31_578->Init((Enemy *) this);
    this->unkA3C = &temp_r31_578->__vptr;
}
#endif

void ConvexTier2Descriptor::Deinit() {
    EnemyDescriptor::Deinit();
}

void ConvexTier2Descriptor::Init() {
    EnemyDescriptor::Init();
    this->unkD0 = 0.0f;
}

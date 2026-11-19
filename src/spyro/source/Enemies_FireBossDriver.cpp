#include "spyro/source/Enemies_FireBossDriver.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
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
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FireBossDriverGoals.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 FireBossDriver::IsCharging() {
    s32 var_r31_53;
    void **temp_r3_54;

    var_r31_53 = 0;
    temp_r3_54 = this->unkB10;
    if ((M2C_FIELD(*temp_r3_54, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_54, 0x6E) != 0) && ((u32) M2C_FIELD(this->unk630, u32 *, 0x20) != (u32) this->unkA50->unk40)) {
        var_r31_53 = 1;
    }
    return var_r31_53;
}

void FireBossDriver::CrashExit() {
    ((FireBossDriverGoal_Think *) this->unkB10)->CrashExit();
}

void FireBossDriver::CrashEnter() {
    ((FireBossDriverGoal_Think *) this->unkB10)->CrashEnter();
}

void FireBossDriver::ChargeExit() {
    ((FireBossDriverGoal_Think *) this->unkB10)->ChargeExit();
}

void FireBossDriver::ChargeEnter() {
    ((FireBossDriverGoal_Think *) this->unkB10)->ChargeEnter();
}

void FireBossDriver::Draw() {
    Enemy::Draw();
}

void FireBossDriver::Update() {
    Enemy::Update();
}

void FireBossDriver::Resolve() {
    this->unkB09 &= ~0x20;
    Enemy::Resolve();
}

void FireBossDriver::LoadDone() {
    Enemy::LoadDone();
}

void FireBossDriver::SetDefaults() {
    Enemy::SetDefaults();
    this->unkB14 = 0;
}

#if 0 // DRAFT: pointer/array required
void FireBossDriver::Init() {
    Enemy::Init();
    operator new(0x30U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkB10 = M2C_ERROR(/* Read from unset register $r3 */);
    ((FireBossDriverGoal_Think *) this->unkB10)->Init((Enemy *) this);
    this->unkA3C = checked_cast<Goal<Enemy> *, FireBossDriverGoal_Think>((FireBossDriverGoal_Think *) this->unkB10);
}
#endif

void FireBossDriverDescriptor::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    BoundingVolume *temp_r3_269;

    EnemyDescriptor::LoadDone();
    sp8 = 0.0f;
    temp_r3_269 = this->unk1C;
    spC = 900.0f;
    sp10 = 300.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(temp_r3_269, f64 *, 0x10) = (f64) (M2C_FIELD(temp_r3_269, f64 *, 0x10) + sp18);
    temp_r3_269->unk18 += (f32) sp20;
    M2C_FIELD(this, s8 *, 0x74) = 0;
}

void FireBossDriverDescriptor::Init() {
    EnemyDescriptor::Init();
    this->unk1D5 = 0;
}

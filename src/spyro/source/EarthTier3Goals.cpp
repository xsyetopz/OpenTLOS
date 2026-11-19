#include "spyro/source/EarthTier3Goals.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
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
#include "spyro/source/GameProp.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void EarthTier3Goal_Spawn::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

u8 EarthTier3Goal_Spawn::Update() {
    AnimSequence *temp_r4_44;
    AnimSequence *temp_r4_78;
    AnimSequence *temp_r4_88;
    Enemy *temp_r29_82;
    Enemy *temp_r3_75;
    Enemy *temp_r6_42;
    u8 var_r30_57;
    u8 var_r30_83;
    u8 var_r5_43;

    ActivateIfInactive();
    temp_r6_42 = this->unkC;
    var_r5_43 = 0;
    temp_r4_44 = temp_r6_42->unkA50;
    if ((temp_r4_44 != NULL) && ((u32) temp_r4_44->unk0 == (u32) M2C_FIELD(temp_r6_42->unk630, u32 *, 0x20))) {
        var_r5_43 = 1;
    }
    if (var_r5_43 != 0) {
        var_r30_57 = 0;
        if (((u8) M2C_FIELD(temp_r6_42, u8 *, 0x8B8) == 2) || (temp_r6_42->unk870.unk40.Get() != NULL)) {
            var_r30_57 = 1;
        }
        if ((var_r30_57 != 0) && (this->unkC->unk870.GetDist() < 1500.0f)) {
            temp_r3_75 = this->unkC;
            temp_r4_78 = temp_r3_75->unkA50;
            temp_r3_75->SetAnim(temp_r4_78, (AnimTransition *) &temp_r4_78->unk40, 0.15f, 0U);
        }
    }
    temp_r29_82 = this->unkC;
    var_r30_83 = 0;
    if (((Character *) temp_r29_82)->HasAnimFinished() != 0) {
        temp_r4_88 = temp_r29_82->unkA50;
        if ((temp_r4_88 != NULL) && ((u32) temp_r4_88->unk40 == (u32) M2C_FIELD(temp_r29_82->unk630, u32 *, 0x20))) {
            var_r30_83 = 1;
        }
    }
    if (var_r30_83 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void EarthTier3Goal_Spawn::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 0xF, 0x64, 0, 0.15f, 0U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
}

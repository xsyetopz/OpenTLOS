#include "spyro/source/DreadWingGoals.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
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
#include "spyro/source/Crate.h"
#include "spyro/source/DropBox.h"
#include "spyro/source/Enemies_DreadWing.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_Think.h"
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
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void DreadWingGoal_Drop::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

u8 DreadWingGoal_Drop::Update() {
    AnimSequence *temp_r4_48;
    Enemy *temp_r30_42;
    u8 var_r31_43;

    ActivateIfInactive();
    temp_r30_42 = this->unkC;
    var_r31_43 = 0;
    if (((Character *) temp_r30_42)->HasAnimFinished() != 0) {
        temp_r4_48 = temp_r30_42->unkA50;
        if ((temp_r4_48 != NULL) && ((u32) temp_r4_48->unk0 == (u32) M2C_FIELD(temp_r30_42->unk630, u32 *, 0x20))) {
            var_r31_43 = 1;
        }
    }
    if (var_r31_43 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void DreadWingGoal_Drop::Activate() {
    AnimSequence *temp_r4_90;
    Enemy *temp_r3_89;

    this->unk8 = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r3_89 = this->unkC;
    temp_r4_90 = temp_r3_89->unkA50;
    if (((s32) temp_r4_90->unk6C == 0xA) && ((s32) temp_r4_90->unk68 == 0)) {
        temp_r3_89->SetAnim((AnimSequenceType) 0xA, 0x47, 0, 0.15f, 0U, 0U);
    } else if (((s32) temp_r4_90->unk6C == 0xA) && ((s32) temp_r4_90->unk68 == 0xE1)) {
        temp_r3_89->SetAnim((AnimSequenceType) 0xA, 0x46, 0, 0.15f, 0U, 0U);
    }
    checked_cast<DreadWing *, Enemy>(this->unkC);
}

void DreadWingGoal_Drop::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x92;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

void DreadWingGoal_PickUp::SetParams(int arg0) {
    this->unk10 = arg0;
}

void DreadWingGoal_PickUp::Terminate() {
    this->unk8 = 1;
}

u8 DreadWingGoal_PickUp::Update() {
    ActivateIfInactive();
    return this->unk8;
}

void DreadWingGoal_PickUp::Activate() {
    this->unk8 = 0;
    ((DreadWing *) (checked_cast<DreadWing *, Enemy>(this->unkC)))->PickUpDropBox(this->unk10);
    this->unk8 = 2;
}

void DreadWingGoal_PickUp::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x91;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

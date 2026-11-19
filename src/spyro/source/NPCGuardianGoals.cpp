#include "spyro/source/NPCGuardianGoals.h"
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
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
extern M2C_UNK gb;

void NPCGuardianGoal_Idle::Reset() {
    this->unk8 = 1;
    this->unk10 = 0;
}

void NPCGuardianGoal_Idle::Terminate() {
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->unkAEC = 0;
    M2C_FIELD(this->unkC, u8 *, 0x6F8) = 0;
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 NPCGuardianGoal_Idle::Update() {
    AnimSequence *temp_r3_134;
    AnimSequence *temp_r3_182;
    Character *temp_r29_52;
    Character *temp_r3_152;
    Character *temp_r3_191;
    Character *temp_r5_227;
    Character *temp_r5_95;
    Character *temp_r6_128;
    Character *temp_r6_176;
    u32 temp_r3_216;
    u8 var_r30_112;
    u8 var_r6_153;
    u8 var_r6_192;
    void *temp_r3_53;
    void *temp_r4_116;
    void *temp_r5_154;
    void *temp_r5_193;

    ActivateIfInactive();
    temp_r29_52 = this->unkC;
    temp_r3_53 = temp_r29_52->unkA50;
    if ((temp_r3_53 != NULL) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x6C) == 1) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x68) == 1)) {
        if (temp_r29_52->HasAnimFinished() != 0) {
            if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) < 0.1f) {
                ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 9, 0, 0.15f, 0U, 0U);
                this->unkC->unk6F8 = 0;
            }
        } else if (((TargetContext *) (this->unk10 + 0x40))->Get() != NULL) {
            temp_r5_95 = this->unkC;
            M2C_FIELD(((TargetContext *) (this->unk10 + 0x40))->Get()->__vptr, M2C_UNK (**)(MKVector3 *, M2C_UNK *), 0x28)(&temp_r5_95->unk588, &temp_r5_95->unk700);
        }
    } else if ((temp_r3_53 != NULL) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x6C) == 1) && ((s32) M2C_FIELD(temp_r3_53, s32 *, 0x68) == 9)) {
        var_r30_112 = 0;
        if (temp_r29_52->HasAnimFinished() != 0) {
            temp_r4_116 = temp_r29_52->unkA50;
            if ((temp_r4_116 != NULL) && ((u32) M2C_FIELD(temp_r4_116, u32 *, 0) == (u32) M2C_FIELD(temp_r29_52->unk630, u32 *, 0x20))) {
                var_r30_112 = 1;
            }
        }
        if (var_r30_112 != 0) {
            temp_r6_128 = this->unkC;
            temp_r3_134 = temp_r6_128->unkA38->GetAnimSequence(1, 9, temp_r6_128->unkAE4, NULL);
            ((Enemy *) this->unkC)->SetAnim(temp_r3_134, temp_r3_134 + 0x20, 0.15f, 0U);
            this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
        }
        temp_r3_152 = this->unkC;
        var_r6_153 = 0;
        temp_r5_154 = temp_r3_152->unkA50;
        if ((temp_r5_154 != NULL) && ((u32) M2C_FIELD(temp_r5_154, u32 *, 0x20) == (u32) M2C_FIELD(temp_r3_152->unk630, u32 *, 0x20))) {
            var_r6_153 = 1;
        }
        if ((var_r6_153 != 0) && (temp_r3_152->HasAnimFinished() != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk14)) {
            temp_r6_176 = this->unkC;
            temp_r3_182 = temp_r6_176->unkA38->GetAnimSequence(1, 9, temp_r6_176->unkAE4, NULL);
            ((Enemy *) this->unkC)->SetAnim(temp_r3_182, temp_r3_182 + 0x40, 0.15f, 0U);
        }
        temp_r3_191 = this->unkC;
        var_r6_192 = 0;
        temp_r5_193 = temp_r3_191->unkA50;
        if ((temp_r5_193 != NULL) && ((u32) M2C_FIELD(temp_r5_193, u32 *, 0x40) == (u32) M2C_FIELD(temp_r3_191->unk630, u32 *, 0x20))) {
            var_r6_192 = 1;
        }
        if ((var_r6_192 != 0) && (temp_r3_191->HasAnimFinished() != 0)) {
            ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
            temp_r3_216 = this->unk10;
            if ((temp_r3_216 != 0) && (((TargetContext *) (temp_r3_216 + 0x40))->Get() != NULL)) {
                temp_r5_227 = this->unkC;
                if (M2C_FIELD(((TargetContext *) (this->unk10 + 0x40))->Get()->__vptr, u8 (**)(MKVector3 *, M2C_UNK *), 0x28)(&temp_r5_227->unk588, &temp_r5_227->unk700) != 0) {
                    this->unkC->unk6F8 = 1;
                }
            }
        }
    }
    return this->unk8;
}
#endif

void NPCGuardianGoal_Idle::Activate() {
    u32 temp_r3_257;
    void **temp_r3_262;
    u8 (*temp_r12_263)(void **, MKVector3 *, M2C_UNK *);

    this->unk8 = 0;
    temp_r3_257 = this->unk10;
    if ((temp_r3_257 != 0) && (((TargetContext *) (temp_r3_257 + 0x40))->Get() != NULL)) {
        temp_r3_262 = (void **) ((TargetContext *) (this->unk10 + 0x40))->Get();
        temp_r12_263 = M2C_FIELD(*temp_r3_262, u8 (**)(void **, MKVector3 *, M2C_UNK *), 0x28);
        if (temp_r12_263(temp_r3_262, &this->unkC->unk588, (M2C_UNK *) ((u8 *) this->unkC + 0x700)) != 0) {
            M2C_FIELD(this->unkC, u8 *, 0x6F8) = 1;
        }
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
}

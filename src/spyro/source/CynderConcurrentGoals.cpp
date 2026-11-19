#include "spyro/source/CynderConcurrentGoals.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/System_GC.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Cynder.h"
#include "spyro/source/CynderBossGoals.h"
#include "spyro/source/CynderBreathFX.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlameBreathBeamFX.h"
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
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SuckeyPS.h"
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */
extern M2C_UNK gb;

void CynderConcurrentGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    s32 temp_r0_17;
    s32 temp_r0_48;
    s32 temp_r4_72;

    temp_r0_17 = arg0->unk28;
    if (temp_r0_17 < 8) {
        if (temp_r0_17 != 3) {
            if (temp_r0_17 < 3) {
                if (temp_r0_17 < 1) {

                } else {
                    goto block_8;
                }
            }
        } else {
            goto block_9;
        }
    } else if (temp_r0_17 < 0xD) {
        if (temp_r0_17 < 0xB) {
block_9:
            arg0->unk28 = 0;
        } else {
block_8:
            arg0->unk28 = 0;
        }
    }
    if (IsActive(0x59) != 0) {
        temp_r0_48 = arg0->unk28;
        if ((temp_r0_48 != 0) && ((temp_r0_48 != 1) || (IsActive(0xA) == 0))) {
            if (IsActive(0x12) != 0) {
                return;
            }
            goto block_16;
        }
    } else {
block_16:
        temp_r4_72 = this->unkC;
        M2C_FIELD(temp_r4_72, f64 *, 0x910) = (f64) arg0->unk0;
        M2C_FIELD(temp_r4_72, f64 *, 0x918) = (f64) arg0->unk8;
        M2C_FIELD(temp_r4_72, s32 *, 0x920) = (s32) arg0->unk10;
        M2C_FIELD(temp_r4_72, s32 *, 0x924) = (s32) arg0->unk14;
        M2C_FIELD(temp_r4_72, f32 *, 0x928) = (f32) arg0->unk18;
        M2C_FIELD(temp_r4_72, f32 *, 0x92C) = (f32) arg0->unk1C;
        M2C_FIELD(temp_r4_72, s32 *, 0x930) = (s32) arg0->unk20;
        M2C_FIELD(temp_r4_72, f32 *, 0x934) = (f32) arg0->unk24;
        M2C_FIELD(temp_r4_72, s32 *, 0x938) = (s32) arg0->unk28;
        M2C_FIELD(temp_r4_72, s32 *, 0x93C) = (s32) arg0->unk2C;
        M2C_FIELD(temp_r4_72, s32 *, 0x940) = (s32) arg0->unk30;
        M2C_FIELD(temp_r4_72, u8 *, 0x944) = (u8) arg0->unk34;
        M2C_FIELD(this->unkC, f32 *, 0x928) = 0.0f;
        RemoveAllSubgoals();
        AddSubgoal((Goal<Cynder> *) this->unk28);
    }
}

u8 CynderConcurrentGoal_Think::Update() {
    s32 temp_r3_128;
    u32 temp_r31_132;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_128 = this->unkC;
    temp_r31_132 = ((u8) M2C_FIELD(temp_r3_128, u8 *, 0xB09) >> 7U) & 1;
    if (M2C_FIELD(M2C_FIELD(temp_r3_128, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_128) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    ActivateIfInactive();
    if (temp_r31_132 == (u32) (((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1)) {
        this->unk8 = UpdateSubgoals();
        if ((u8) this->unk8 != 0) {
            Activate();
        }
    }
    return (u8) this->unk8;
}

void CynderConcurrentGoal_Think::Arbitrate() {
    typedef u8 (*BlockFn)(void *, Matrix *, s32, f32);
    typedef u8 (Enemy::*FlinchFn)(void);
    Matrix sp50;
    EnemyDamageFeedback sp10;
    f32 temp_f1_192;
    s32 enter;
    s32 temp_r3_184;
    s32 temp_r3_212;
    s32 temp_r3_224;
    s32 temp_r3_233;

    temp_r3_184 = this->unkC;
    enter = 0;
    if ((M2C_FIELD(temp_r3_184, u8 *, 0xB09) >> 7) & 1) {
        enter = 1;
    } else {
        sp50.SetIdentity();
        sp50.unk30 = M2C_FIELD(temp_r3_184, f32 *, 0x5B8);
        sp50.unk34 = M2C_FIELD(temp_r3_184, f32 *, 0x5BC);
        temp_f1_192 = M2C_FIELD(temp_r3_184, f32 *, 0x5C0);
        sp50.unk38 = temp_f1_192;
        sp50.unk3C = 1.0f;
        enter = ((BlockFn) ((void **) M2C_FIELD(temp_r3_184, void **, 0x44))[0x120 / 4])((void *) temp_r3_184, &sp50, 0, temp_f1_192) != 0;
    }
    if (enter) {
        if (((Enemy *) this->unkC)->WasHit() != 0) {
            sp10.Init();
            if (((Enemy *) this->unkC)->IsInvulnerable() != 0) {
                temp_r3_212 = this->unkC;
                M2C_FIELD(temp_r3_212, s32 *, 0x9D8) = 0;
                M2C_FIELD(temp_r3_212, s32 *, 0x9D4) = 0;
            } else {
                ((Enemy *) this->unkC)->TakeDamage(&sp10, 0U);
                ((Cynder *) this->unkC)->UpdateEnemyHud();
                temp_r3_224 = this->unkC;
                if (M2C_FIELD(temp_r3_224, f32 *, 0xAC8) <= 0.0f) {
                    ((EventMessage *) (temp_r3_224 + 0x1000))->Send(NULL);
                    temp_r3_233 = this->unkC;
                    M2C_FIELD(temp_r3_233, u8 *, 0xB01) = (u8) (M2C_FIELD(temp_r3_233, u8 *, 0xB01) | 0x80);
                }
                if ((sp10.unk28 == 4) || (sp10.unk28 == 5)) {
                    sp10.unk28 = 0xE;
                }
                if (sp10.unk28 != 0xE) {
                    AddGoal_Hit(&sp10);
                    return;
                }
            }
        }
        if ((((((Enemy *) this->unkC)->*((FlinchFn) &Enemy::IsFlinching))()) == 0) && (IsPresent(0xB9) == 0)) {
            RemoveAllSubgoals();
            AddSubgoal((Goal<Cynder> *) this->unk2C);
            ((CynderGoal_GroundAttackMode *) this->unk2C)->SetParams((AITargetData *) (this->unkC + 0x870), NULL, 0);
        }
    }
}

void CynderConcurrentGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void CynderConcurrentGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = 1;
}

void CynderConcurrentGoal_Think::Deinit() {
    Goal<Cynder> *temp_r3_339;
    Goal<Cynder> *temp_r3_344;
    s32 temp_r31_355;
    void **temp_r3_334;

    temp_r3_334 = this->unk24;
    M2C_FIELD(*temp_r3_334, M2C_UNK (**)(void **), 0xC)(temp_r3_334);
    temp_r3_339 = this->unk28;
    temp_r3_339->Deinit();
    temp_r3_344 = this->unk2C;
    temp_r3_344->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_355 = this->unk1C;
    if ((u32) temp_r31_355 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_355, NULL, 0);
        } else {
            free(temp_r31_355);
        }
        this->unk1C = 0;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = 0;
    this->unk9 = 0;
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderConcurrentGoal_Think::Init(Cynder *arg0) {
    void **temp_r4_509;
    void *var_r3_489;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x54U, NULL, 0);
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
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__13Goal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__22CompositeGoal<6Cynder>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_489 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_489 = malloc(0x14);
        }
        this->unk1C = (s32) var_r3_489;
        this->unk10 = 5;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x98;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_509 = this->unk24;
    M2C_FIELD(temp_r4_509, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_509, Cynder **, 0xC) = arg0;
    M2C_FIELD(temp_r4_509, s32 *, 4) = 0xAA;
    if ((Cynder *) M2C_FIELD(temp_r4_509, Cynder **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_509, s8 *, 9) = 1;
    }
    ((EnemyGoal_Hit *) this->unk28)->Init((Enemy *) arg0);
    ((CynderGoal_GroundAttackMode *) this->unk2C)->Init(arg0);
}
#endif

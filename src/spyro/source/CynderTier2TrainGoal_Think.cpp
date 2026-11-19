#include "spyro/source/CynderTier2TrainGoal_Think.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
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
#include "spyro/source/Enemies_Cynder.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EnemyTestGoals.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
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
#include "unplaced_enums.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gb;

void CynderTier2TrainGoal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    Enemy *temp_r4_44;

    if (IsPresent(0x5B) == 0) {
        temp_r4_44 = this->unkC;
        temp_r4_44->unk910 = arg0->unk0;
        M2C_FIELD(temp_r4_44, f64 *, 0x918) = (f64) arg0->unk8;
        temp_r4_44->unk920 = arg0->unk10;
        temp_r4_44->unk924 = arg0->unk14;
        temp_r4_44->unk928 = arg0->unk18;
        temp_r4_44->unk92C = arg0->unk1C;
        temp_r4_44->unk930 = arg0->unk20;
        temp_r4_44->unk934 = arg0->unk24;
        temp_r4_44->unk938 = arg0->unk28;
        temp_r4_44->unk93C = arg0->unk2C;
        temp_r4_44->unk940 = arg0->unk30;
        temp_r4_44->unk944 = arg0->unk34;
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk2C);
    }
}

void CynderTier2TrainGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r3_121;
    s32 temp_r0_99;
    s32 temp_r3_100;

loop_5:
    if (IsPresent(0x59) != 0) {
        if ((s32) this->unk14 > 0) {
            this->unk18 += 1;
            temp_r0_99 = this->unk18;
            temp_r3_100 = this->unk10;
            if (temp_r0_99 >= temp_r3_100) {
                this->unk18 = temp_r0_99 - temp_r3_100;
            }
            this->unk14 -= 1;
        }
        goto loop_5;
    }
    AddSubgoalToFront((Goal<Enemy> *) this->unk28);
    temp_r3_121 = this->unkC;
    temp_r3_121->unk910 = arg0->unk0;
    M2C_FIELD(temp_r3_121, f64 *, 0x918) = (f64) arg0->unk8;
    temp_r3_121->unk920 = arg0->unk10;
    temp_r3_121->unk924 = arg0->unk14;
    temp_r3_121->unk928 = arg0->unk18;
    temp_r3_121->unk92C = arg0->unk1C;
    temp_r3_121->unk930 = arg0->unk20;
    temp_r3_121->unk934 = arg0->unk24;
    temp_r3_121->unk938 = arg0->unk28;
    temp_r3_121->unk93C = arg0->unk2C;
    temp_r3_121->unk940 = arg0->unk30;
    temp_r3_121->unk944 = arg0->unk34;
    this->unkC->unk928 = 0.0f;
}

void CynderTier2TrainGoal_Think::AddGoal_TrainAttackMode(AITargetData *arg0) {
    if (IsPresent(0x62) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk24);
        M2C_FIELD(this->unk24, AITargetData **, 0x24) = arg0;
    }
}

void CynderTier2TrainGoal_Think::AddGoal_SpawnOnTrain() {
    if (IsPresent(0x61) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk20);
        this->unk30 = 1;
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderTier2TrainGoal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Enemy *temp_r3_274;

    if ((u8) this->unk30 == 0) {
        AddGoal_SpawnOnTrain();
        return;
    }
    if (IsPresent(0x61) == 0) {
        if (this->unkC->WasHit() != 0) {
            sp8.Init();
            this->unkC->TakeDamage(&sp8, 0U);
            if (this->unkC->unkAC8 <= 0.0f) {
                AddGoal_Death(&sp8);
                return;
            }
            if ((sp8.unk28 != 0xE) && ((sp8.unk24 > 0.0f) || ((sp8.unk34 >> 7U) & 1))) {
                AddGoal_Hit(&sp8);
                return;
            }
            goto block_10;
        }
block_10:
        temp_r3_274 = this->unkC;
        if ((temp_r3_274->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_274->__vptr, u8 (**)(), 0x134)() == 0)) {
            this->unkC->IsFlinching();
            if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                AddGoal_TrainAttackMode(&this->unkC->unk870);
            }
        }
    }
}
#endif

void CynderTier2TrainGoal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 CynderTier2TrainGoal_Think::Update() {
    Enemy *temp_r3_331;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_331 = this->unkC;
    if (temp_r3_331->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}

void CynderTier2TrainGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void CynderTier2TrainGoal_Think::Deinit() {
    Goal<Enemy> *temp_r3_389;
    Goal<Enemy> *temp_r3_394;
    Goal<Enemy> *temp_r3_399;
    Goal<Enemy> *temp_r3_404;
    void *temp_r31_417;

    temp_r3_389 = this->unk20;
    temp_r3_389->Deinit();
    temp_r3_394 = this->unk24;
    temp_r3_394->Deinit();
    temp_r3_399 = this->unk28;
    temp_r3_399->Deinit();
    temp_r3_404 = this->unk2C;
    temp_r3_404->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_417 = this->unk1C;
    if (temp_r31_417 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_417, NULL, 0);
        } else {
            free(temp_r31_417);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void CynderTier2TrainGoal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r5_597;
    u32 temp_r3_596;
    void *var_r3_575;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
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
        operator new(0x24U, NULL, 0);
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
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_575 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_575 = malloc(8);
        }
        this->unk1C = var_r3_575;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x63;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r3_596 = checked_cast<CynderTier2Train *, Enemy>(arg0);
    temp_r5_597 = this->unk20;
    M2C_FIELD(temp_r5_597, s8 *, 8) = 1;
    M2C_FIELD(temp_r5_597, u32 *, 0xC) = temp_r3_596;
    M2C_FIELD(temp_r5_597, s32 *, 4) = 0x61;
    if ((u32) M2C_FIELD(temp_r5_597, u32 *, 0xC) != 0U) {
        M2C_FIELD(temp_r5_597, s8 *, 9) = 1;
    }
    ((EnemyGoal_TrainAttackMode *) this->unk24)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk28)->Init(arg0);
    ((EnemyGoal_Death *) this->unk2C)->Init(arg0);
}
#endif

void EnemyGoal_TrainAttackMode::Terminate() {
    this->unkC->unkA20 = NULL;
    this->unkC->unk6C0.unk38 = 0;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 EnemyGoal_TrainAttackMode::Update() {
    AITargetData *temp_r3_656;
    u8 var_r31_660;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_656 = this->unk24;
    if (temp_r3_656 != NULL) {
        var_r31_660 = 0;
        if (((u8) M2C_FIELD(temp_r3_656, u8 *, 0x48) == 2) || (temp_r3_656->unk40.Get() != NULL)) {
            var_r31_660 = 1;
        }
        if (var_r31_660 != 0) {
            if ((u8) this->unk8 == 2) {
                this->unk8 = 1;
            }
            ReactivateIfFailed();
            ActivateIfInactive();
        }
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyGoal_TrainAttackMode::Activate() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AITargetData *temp_r3_704;
    AttackerManager *temp_r3_826;
    Enemy *temp_r3_725;
    Enemy *temp_r3_734;
    Enemy *temp_r3_790;
    EnemyAttack *temp_r29_812;
    Frustum *temp_r28_731;
    Goal<Enemy> *temp_r6_858;
    Goal<Enemy> *temp_r6_895;
    f32 temp_f1_759;
    f32 temp_f1_842;
    f64 temp_f0_754;
    f64 temp_f1_733;
    f64 temp_f1_744;
    s32 temp_r31_772;
    s32 var_r29_831;
    u8 var_r28_708;
    void *temp_r4_741;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_704 = this->unk24;
    if (temp_r3_704 != NULL) {
        var_r28_708 = 0;
        if (((u8) M2C_FIELD(temp_r3_704, u8 *, 0x48) == 2) || (temp_r3_704->unk40.Get() != NULL)) {
            var_r28_708 = 1;
        }
        if (var_r28_708 == 0) {
            goto block_5;
        }
        temp_r3_725 = this->unkC;
        temp_r28_731 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        temp_f1_733 = temp_r3_725->GetCollisionRadius(M2C_FIELD(&gb, s32 *, 0x3B8));
        temp_r3_734 = this->unkC;
        sp18 = M2C_FIELD(temp_r3_734, f64 *, 0xD0) * temp_f1_733;
        temp_r4_741 = temp_r3_734->unk8;
        temp_f1_744 = M2C_FIELD(temp_r4_741, f64 *, 0x30);
        sp20 = temp_r3_734->unkD8 * (f32) temp_f1_733;
        sp28 = sp18;
        sp38 = temp_f1_744;
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r4_741, f64 *, 0x38);
        temp_f0_754 = temp_f1_744 + sp28;
        sp8 = temp_f0_754;
        temp_f1_759 = (f32) sp40 + (f32) sp30;
        sp48 = temp_f0_754;
        sp10 = temp_f1_759;
        sp50 = (f64) sp10;
        temp_r31_772 = temp_r28_731->IsVisible(*((MKVector3 *) &sp48), temp_r3_734->GetCollisionRadius(temp_r4_741, temp_f1_759, (f32) sp40, sp18));
        if (((void **) M2C_FIELD(&gb, void ***, 0) != NULL) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(), 0x54)() != 0)) {
            this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
        }
        temp_r3_790 = this->unkC;
        if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r3_790->unkA7C) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk20)) {
            if ((EnemyAttack *) temp_r3_790->unkA20 == NULL) {
                temp_r3_790->SelectAttack(0x10, M2C_FIELD(temp_r3_790->unk638, s32 *, 8) + 0x5A);
            }
            temp_r29_812 = this->unkC->unkA20;
            if ((temp_r29_812 != NULL) && (this->unk24->GetDist() < temp_r29_812->unk18)) {
                temp_r3_826 = M2C_FIELD(this->unk24->unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
                if (temp_r3_826 != NULL) {
                    var_r29_831 = temp_r3_826->GetAttackerCount(8);
                } else {
                    var_r29_831 = 0;
                }
                temp_f1_842 = M2C_FIELD(this->unk24->unk40.Get()->__vptr, f32 (**)(), 0x40)();
                if ((var_r29_831 > 0) || ((3.0f + temp_f1_842) > M2C_FIELD(&gb, f32 *, 0x30C)) || ((u8) temp_r31_772 == 0)) {
                    AddSubgoal((Goal<Enemy> *) this->unk28);
                    temp_r6_858 = this->unk28;
                    M2C_FIELD(temp_r6_858, s32 *, 0x10) = 0;
                    M2C_FIELD(temp_r6_858, s32 *, 0x14) = 1;
                    M2C_FIELD(temp_r6_858, s32 *, 0x18) = (s32) (M2C_FIELD(this->unkC->unk638, s32 *, 8) + 0x5F);
                    M2C_FIELD(temp_r6_858, s32 *, 0x1C) = 2;
                    M2C_FIELD(temp_r6_858, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_858, u8 *, 0x20) & ~0x40);
                } else {
                    AddSubgoal((Goal<Enemy> *) this->unk2C);
                    AddSubgoal((Goal<Enemy> *) this->unk28);
                    M2C_FIELD(this->unk2C, s8 *, 0x48) = 1;
                }
            } else {
                AddSubgoal((Goal<Enemy> *) this->unk28);
            }
        } else {
            AddSubgoal((Goal<Enemy> *) this->unk28);
        }
        temp_r6_895 = this->unk28;
        M2C_FIELD(temp_r6_895, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r6_895, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r6_895, s32 *, 0x18) = (s32) (M2C_FIELD(this->unkC->unk638, s32 *, 8) + 0x5F);
        M2C_FIELD(temp_r6_895, s32 *, 0x1C) = 2;
        M2C_FIELD(temp_r6_895, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_895, u8 *, 0x20) & ~0x40);
        return;
    }
block_5:
    this->unk8 = 2;
}
#endif

void EnemyGoal_TrainAttackMode::Deinit() {
    Goal<Enemy> *temp_r3_926;
    Goal<Enemy> *temp_r3_931;
    void *temp_r31_940;

    temp_r3_926 = this->unk28;
    temp_r3_926->Deinit();
    temp_r3_931 = this->unk2C;
    temp_r3_931->Deinit();
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_940 = this->unk1C;
    if (temp_r31_940 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_940, NULL, 0);
        } else {
            free(temp_r31_940);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void EnemyGoal_TrainAttackMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1057;
    Goal<Enemy> *temp_r4_1068;
    void *var_r3_1037;

    if ((u8) this->unk9 == 0) {
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x50U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_1037 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_1037 = malloc(8);
        }
        this->unk1C = var_r3_1037;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x62;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1057 = this->unk28;
    M2C_FIELD(temp_r4_1057, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1057, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1057, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_1057, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1057, s8 *, 9) = 1;
    }
    temp_r4_1068 = this->unk2C;
    M2C_FIELD(temp_r4_1068, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1068, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1068, s32 *, 4) = 0x3B;
    if ((Enemy *) M2C_FIELD(temp_r4_1068, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1068, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1068, f32 *, 0x28) = 0.0f;
    M2C_FIELD(temp_r4_1068, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(temp_r4_1068, f32 *, 0x30) = 0.0f;
    M2C_FIELD(temp_r4_1068, f32 *, 0x18) = 0.0f;
    M2C_FIELD(temp_r4_1068, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(temp_r4_1068, f32 *, 0x20) = 0.0f;
    this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.0f;
}
#endif

void EnemyGoal_SpawnOnTrain::Terminate() {
    this->unk8 = 1;
}

u8 EnemyGoal_SpawnOnTrain::Update() {
    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void EnemyGoal_SpawnOnTrain::Activate() {
    Character *temp_r3_1143;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_1143 = this->unkC;
    ((Enemy *) temp_r3_1143)->SetAnim((AnimSequenceType) 0xF, M2C_FIELD(temp_r3_1143->unk638, s32 *, 8) + 0x65, 0, 0.15f, 0U, 0U);
}

void CynderTier2TrainGoal_Think_cpp::__sinit() {
    f32 temp_f0_1229;
    f64 temp_f1_1210;
    f64 temp_f1_1218;
    f64 temp_f3_1198;
    f64 temp_f4_1207;
    f64 temp_f4_1215;
    f64 temp_f8_1200;

    temp_f3_1198 = __frsqrte(2014000.0);
    temp_f8_1200 = __frsqrte(380000.0);
    temp_f4_1207 = 0.5 * temp_f3_1198 * -((2014000.0 * (temp_f3_1198 * temp_f3_1198)) - 3.0);
    temp_f1_1210 = 0.5 * temp_f8_1200 * -((380000.0 * (temp_f8_1200 * temp_f8_1200)) - 3.0);
    temp_f4_1215 = 0.5 * temp_f4_1207 * -((2014000.0 * (temp_f4_1207 * temp_f4_1207)) - 3.0);
    temp_f1_1218 = 0.5 * temp_f1_1210 * -((380000.0 * (temp_f1_1210 * temp_f1_1210)) - 3.0);
    temp_f0_1229 = (f32) (380000.0 * (0.5 * temp_f1_1218 * -((380000.0 * (temp_f1_1218 * temp_f1_1218)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1215 * -((2014000.0 * (temp_f4_1215 * temp_f4_1215)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1229;
}

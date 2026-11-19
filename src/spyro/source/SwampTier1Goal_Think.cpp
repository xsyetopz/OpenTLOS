#include "spyro/source/SwampTier1Goal_Think.h"
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
#include "spyro/source/Enemies_Swamp.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_AlertMode.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
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
#include "spyro/source/SwampTier3Goals.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */

void SwampTier1Goal_Hit::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 SwampTier1Goal_Hit::Update() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    Enemy *temp_r3_63;
    Enemy *temp_r3_73;
    f64 temp_f0_93;
    f64 temp_f1_83;
    s32 var_r6_99;
    void *temp_r4_80;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    sp8 = 0;
    temp_r3_63 = this->unkC;
    if (((u8) temp_r3_63->unkA38->unk121 != 0) && (temp_r3_63->InWaterVolume(temp_r3_63->unk588, (int *) &sp8) != 0)) {
        temp_r3_73 = this->unkC;
        sp20 = M2C_FIELD(temp_r3_73, f64 *, 0xC0) * 5.398241246e-315;
        temp_r4_80 = temp_r3_73->unk8;
        temp_f1_83 = M2C_FIELD(temp_r4_80, f64 *, 0x30);
        sp28 = temp_r3_73->unkC8 * 10.0f;
        sp30 = sp20;
        sp40 = temp_f1_83;
        sp38 = (f64) sp28;
        sp48 = M2C_FIELD(temp_r4_80, f64 *, 0x38);
        temp_f0_93 = temp_f1_83 + sp30;
        sp10 = temp_f0_93;
        var_r6_99 = 0x4000;
        sp50 = temp_f0_93;
        sp18 = (f32) sp48 + (f32) sp38;
        sp58 = (f64) sp18;
        if (sp8 & 1) {
            var_r6_99 = 0x800;
        }
        temp_r3_73->AddDamage(0.0f, 1U, *((MKVector3 *) &sp50), var_r6_99, 0, 0U, 0U, NULL, 0.0f, 1.0f);
        this->unk8 = 2;
    }
    return this->unk8;
}

void SwampTier1Goal_Hit::Activate() {
    Enemy *temp_r3_171;
    Enemy *temp_r4_143;
    s32 temp_r0_148;

    this->unk8 = 0;
    temp_r4_143 = this->unkC;
    temp_r4_143->unkB08 |= 0x40;
    RemoveAllSubgoals();
    temp_r0_148 = this->unk40;
    if (temp_r0_148 != 0xB) {
        if ((temp_r0_148 < 0xB) && (temp_r0_148 < 6)) {
            if (temp_r0_148 < 4) {
                goto block_7;
            }
            AddSubgoal((Goal<SwampTier1> *) this->unk24);
            return;
        }
block_7:
        AddSubgoal((Goal<SwampTier1> *) this->unk20);
        temp_r3_171 = this->unkC;
        temp_r3_171->unk6B4 |= 1;
        return;
    }
    AddSubgoal((Goal<SwampTier1> *) this->unk28);
}

void SwampTier1Goal_Hit::Deinit() {
    Goal<SwampTier1> *temp_r3_191;
    Goal<SwampTier1> *temp_r3_196;
    Goal<SwampTier1> *temp_r3_201;
    void *temp_r31_212;

    temp_r3_191 = this->unk20;
    temp_r3_191->Deinit();
    temp_r3_196 = this->unk24;
    temp_r3_196->Deinit();
    temp_r3_201 = this->unk28;
    temp_r3_201->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    temp_r31_212 = this->unk1C;
    if (temp_r31_212 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_212, NULL, 0);
        } else {
            free(temp_r31_212);
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
void SwampTier1Goal_Hit::Init(SwampTier1 *arg0) {
    Goal<SwampTier1> *temp_r4_349;
    Goal<SwampTier1> *temp_r4_360;
    Goal<SwampTier1> *temp_r4_371;
    void *var_r3_329;

    if ((u8) this->unk9 == 0) {
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_329 = ((MKHeap *) (MKHeap::Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_329 = malloc(4);
        }
        this->unk1C = var_r3_329;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x59;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_349 = this->unk20;
    M2C_FIELD(temp_r4_349, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_349, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_349, s32 *, 4) = 8;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_349, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_349, s8 *, 9) = 1;
    }
    temp_r4_360 = this->unk24;
    M2C_FIELD(temp_r4_360, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_360, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_360, s32 *, 4) = 0xF;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_360, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_360, s8 *, 9) = 1;
    }
    temp_r4_371 = this->unk28;
    M2C_FIELD(temp_r4_371, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_371, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_371, s32 *, 4) = 0x14;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_371, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_371, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 SwampTier1Goal_Think::AddGoal_MoveToLastPlayerPos() {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    MKVector3 sp18;
    u8 sp14;
    void *sp10;
    u8 spC;
    void *sp8;
    Enemy *temp_r28_576;
    Enemy *temp_r3_399;
    Enemy *temp_r3_433;
    Enemy *temp_r3_462;
    Enemy *temp_r3_519;
    Enemy *temp_r3_527;
    Enemy *temp_r3_628;
    Enemy *temp_r4_600;
    Enemy *temp_r4_606;
    Enemy *temp_r4_613;
    Goal<SwampTier1> *temp_r8_635;
    f32 temp_f1_523;
    f32 temp_f1_632;
    f32 temp_f2_526;
    f32 temp_f31_428;
    f64 temp_f0_443;
    f64 temp_f0_538;
    u8 var_r0_403;
    u8 var_r29_577;
    u8 var_r30_463;
    u8 var_r30_507;
    void *temp_r4_453;
    void *temp_r4_548;

    temp_r3_399 = this->unkC;
    var_r0_403 = 0;
    if ((temp_r3_399->unk720 == MKVector3::zero.unk0) && (temp_r3_399->unk724 == MKVector3::zero.unk4) && (temp_r3_399->unk728 == MKVector3::zero.unk8)) {
        var_r0_403 = 1;
    }
    if (var_r0_403 != 0) {
        return 0U;
    }
    if ((u8) this->unk3D != 0) {
        temp_f31_428 = M2C_FIELD(temp_r3_399->__vptr, f32 (**)(), 0x100)();
        sp60 = 0.0f;
        temp_r3_433 = this->unkC;
        sp58 = 0.0f;
        sp5C = 50.0f + temp_f31_428;
        sp80 = (f64) sp60;
        sp78 = (f64) sp58;
        temp_f0_443 = M2C_FIELD(temp_r3_433, f64 *, 0x720) + (f64) sp58;
        sp48 = temp_f0_443;
        spB8 = temp_f0_443;
        sp50 = temp_r3_433->unk728 + (f32) sp80;
        spC0 = (f64) sp50;
        temp_r4_453 = temp_r3_433->unk634;
        sp10 = temp_r4_453;
        if (temp_r4_453 != NULL) {
            sp14 = M2C_FIELD(temp_r4_453, u8 *, 4);
            M2C_FIELD(temp_r4_453, u8 *, 4) = 0U;
        }
        temp_r3_462 = this->unkC;
        var_r30_463 = 0;
        if (((u8) M2C_FIELD(temp_r3_462, u8 *, 0x8B8) == 2) || (temp_r3_462->unk870.unk40.Get() != NULL)) {
            var_r30_463 = 1;
        }
        if ((var_r30_463 == 0) || (MKCollision_SphereCollide(*((MKVector3 *) &spB8), temp_f31_428, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0)) {
            RemoveAllSubgoals();
            this->unk3D = 0;
            if (sp10 != NULL) {
                M2C_FIELD(sp10, u8 *, 4) = sp14;
            }
            return 0U;
        }
        if (sp10 != NULL) {
            M2C_FIELD(sp10, u8 *, 4) = sp14;
        }
        goto block_39;
    }
    var_r30_507 = 0;
    if (((u8) M2C_FIELD(temp_r3_399, u8 *, 0x8B8) == 2) || (temp_r3_399->unk870.unk40.Get() != NULL)) {
        var_r30_507 = 1;
    }
    if (var_r30_507 != 0) {
        temp_r3_519 = this->unkC;
        temp_f1_523 = temp_r3_519->GetCollisionRadius();
        temp_f2_526 = 50.0f + temp_f1_523;
        temp_r3_527 = this->unkC;
        sp40 = 0.0f;
        sp38 = 0.0f;
        sp3C = temp_f2_526;
        sp70 = (f64) sp40;
        sp68 = (f64) sp38;
        temp_f0_538 = M2C_FIELD(temp_r3_527, f64 *, 0x720) + (f64) sp38;
        sp28 = temp_f0_538;
        spA8 = temp_f0_538;
        sp30 = temp_r3_527->unk728 + (f32) sp70;
        spB0 = (f64) sp30;
        temp_r4_548 = temp_r3_527->unk634;
        sp8 = temp_r4_548;
        if (temp_r4_548 != NULL) {
            spC = M2C_FIELD(temp_r4_548, u8 *, 4);
            M2C_FIELD(temp_r4_548, u8 *, 4) = 0U;
        }
        if (MKCollision_SphereCollide(*((MKVector3 *) &spA8), temp_f1_523, NULL, 0, (MKCollisionMode) 7, 0x04000000) != 0) {
            if (sp8 != NULL) {
                M2C_FIELD(sp8, u8 *, 4) = spC;
            }
            return 0U;
        }
        RemoveAllSubgoals();
        temp_r28_576 = this->unkC;
        var_r29_577 = 0;
        if (temp_r28_576->unk800.IsPointWithin(*((MKVector3 *) &temp_r28_576->unk720)) != 0) {
            sp18 = temp_r28_576->unk800.GetRegionPos();
            if ((f32) fabs(sp18.unk4 - temp_r28_576->unk724) <= 500.0f) {
                var_r29_577 = 1;
            }
        }
        if ((var_r29_577 != 0) && (temp_r4_600 = this->unkC, ((temp_r4_600->unk838.IsPointWithin(*((MKVector3 *) &temp_r4_600->unk720)) == 0) != 0))) {
            temp_r4_606 = this->unkC;
            temp_r4_606->unk8C0.Set(*((MKVector3 *) &temp_r4_606->unk720), 0U);
        } else {
            temp_r4_613 = this->unkC;
            temp_r4_613->unk800.GetNearestPointOnBoundingRegion(*((MKVector3 *) &temp_r4_613->unk720), &sp98, &sp88);
            this->unkC->unk8C0.Set(sp98, 0U);
        }
        AddSubgoal((Goal<SwampTier1> *) this->unk38);
        temp_r3_628 = this->unkC;
        temp_f1_632 = temp_r3_628->GetCollisionRadius();
        temp_r8_635 = this->unk38;
        M2C_FIELD(temp_r8_635, AITargetData **, 0x10) = &this->unkC->unk8C0;
        M2C_FIELD(temp_r8_635, f32 *, 0x18) = temp_f1_632;
        M2C_FIELD(temp_r8_635, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_635, u8 *, 0x30) | 0x80);
        M2C_FIELD(temp_r8_635, s32 *, 0x20) = 2;
        M2C_FIELD(temp_r8_635, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r8_635, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r8_635, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_635, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r8_635, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_635, u8 *, 0x30) | 0x20);
        M2C_FIELD(temp_r8_635, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r8_635, u8 *, 0x30) | 0x10);
        this->unkC->unk8C0.SetInsideRegion(1U);
        this->unk3D = 1;
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
block_39:
        return 1U;
    }
    return 0U;
}
#endif

void SwampTier1Goal_Think::AddGoal_AlertMode(AITargetData *arg0) {
    Goal<SwampTier1> *temp_r4_705;

    if (IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier1> *) this->unk34);
        temp_r4_705 = this->unk34;
        M2C_FIELD(temp_r4_705, AITargetData **, 0x20) = arg0;
        M2C_FIELD(temp_r4_705, s32 *, 0x4C) = 1;
        M2C_FIELD(temp_r4_705, u8 *, 0x50) = (u8) (M2C_FIELD(temp_r4_705, u8 *, 0x50) | 0x80);
    }
}

void SwampTier1Goal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier1> *) this->unk2C);
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier1Goal_Think::AddGoal_Spawn() {
    Goal<SwampTier1> *temp_r3_756;

    temp_r3_756 = this->unk30;
    if ((temp_r3_756 != NULL) && (IsPresent(M2C_FIELD(temp_r3_756->__vptr, s32 (**)(), 0x34)()) == 0)) {
        this->unk3C = 1;
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier1> *) this->unk30);
    }
}
#endif

void SwampTier1Goal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    if (IsPresent(0x5B) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier1> *) this->unk28);
        AddGoal_Hit(arg0);
    }
}

void SwampTier1Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r4_874;
    Goal<SwampTier1> *temp_r3_903;
    s32 temp_r0_842;
    s32 temp_r0_863;
    s32 temp_r3_864;

    if (IsActive(0x59) != 0) {
        if (IsActive(0x14) == 0) {
            temp_r0_842 = arg0->unk28;
            if (temp_r0_842 != 0) {
                if ((temp_r0_842 == 1) && (IsActive(0xA) != 0)) {
                    return;
                }
                goto block_6;
            }
        } else {
block_6:
            if ((s32) this->unk14 > 0) {
                this->unk18 += 1;
                temp_r0_863 = this->unk18;
                temp_r3_864 = this->unk10;
                if (temp_r0_863 >= temp_r3_864) {
                    this->unk18 = temp_r0_863 - temp_r3_864;
                }
                this->unk14 -= 1;
            }
            goto block_10;
        }
    } else {
block_10:
        temp_r4_874 = this->unkC;
        temp_r4_874->unk910 = arg0->unk0;
        M2C_FIELD(temp_r4_874, f64 *, 0x918) = (f64) arg0->unk8;
        temp_r4_874->unk920 = arg0->unk10;
        temp_r4_874->unk924 = arg0->unk14;
        temp_r4_874->unk928 = arg0->unk18;
        temp_r4_874->unk92C = arg0->unk1C;
        temp_r4_874->unk930 = arg0->unk20;
        temp_r4_874->unk934 = arg0->unk24;
        temp_r4_874->unk938 = arg0->unk28;
        temp_r4_874->unk93C = arg0->unk2C;
        temp_r4_874->unk940 = arg0->unk30;
        temp_r4_874->unk944 = arg0->unk34;
        AddSubgoalToFront((Goal<SwampTier1> *) this->unk24);
        temp_r3_903 = this->unk24;
        M2C_FIELD(temp_r3_903, f64 *, 0x30) = (f64) arg0->unk0;
        M2C_FIELD(temp_r3_903, f64 *, 0x38) = (f64) arg0->unk8;
        M2C_FIELD(temp_r3_903, s32 *, 0x40) = (s32) arg0->unk28;
    }
}

void SwampTier1Goal_Think::AddGoal_Idle() {
    if (IsPresent(0) == 0) {
        RemoveAllSubgoals();
        AddSubgoal((Goal<SwampTier1> *) this->unk20);
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier1Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Enemy *temp_r3_1021;
    Enemy *temp_r3_1037;
    Enemy *temp_r3_1054;
    Enemy *temp_r3_1068;
    Enemy *temp_r3_1076;
    Enemy *temp_r4_990;
    u8 temp_r30_971;
    u8 var_r30_1055;
    void *temp_r3_999;

    if (!(((u8) this->unkC->unkB09 >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if ((u8) this->unk3C == 0) {
        AddGoal_Spawn();
        return;
    }
    temp_r30_971 = IsPresent(0x38);
    if ((this->unkC->WasHit() != 0) && (sp8.Init(), this->unkC->TakeDamage(&sp8, 0U), ((IsPresent(0x5B) == 0) != 0))) {
        temp_r4_990 = this->unkC;
        if (temp_r4_990->unkAC8 <= 0.0f) {
            if (((u8) temp_r4_990->unkB01 >> 4U) & 1) {
                temp_r3_999 = temp_r4_990->unkA44;
                if (temp_r3_999 != NULL) {
                    ((EventMessage *) (((u8 *) temp_r3_999) + 8))->Send((MKProp *) temp_r4_990);
                }
            } else {
                AddGoal_Death(&sp8);
            }
        } else {
            if ((sp8.unk28 != 0xE) && (temp_r30_971 == 0)) {
                AddGoal_Hit(&sp8);
                return;
            }
            goto block_14;
        }
    } else {
block_14:
        temp_r3_1021 = this->unkC;
        if (temp_r3_1021->unkAC8 > 0.0f) {
            temp_r3_1021->IsFlinching();
            if (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) && (((u8) this->unkC->unkB01 >> 4U) & 1)) {
                AddGoal_Idle();
                return;
            }
        }
        temp_r3_1037 = this->unkC;
        if ((temp_r3_1037->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_1037->__vptr, u8 (**)(), 0x134)() == 0) && (this->unkC->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (temp_r30_971 == 0)) {
            temp_r3_1054 = this->unkC;
            var_r30_1055 = 0;
            if (((u8) M2C_FIELD(temp_r3_1054, u8 *, 0x8B8) == 2) || (temp_r3_1054->unk870.unk40.Get() != NULL)) {
                var_r30_1055 = 1;
            }
            if (var_r30_1055 != 0) {
                temp_r3_1068 = this->unkC;
                if ((((u8) M2C_FIELD(temp_r3_1068, u8 *, 0x8B9) >> 6U) & 1) && (temp_r3_1068->unk870.IsAttackable() != 0)) {
                    temp_r3_1076 = this->unkC;
                    if (temp_r3_1076->IsTargetBehindWall() == 0) {
                        AddGoal_AlertMode(&this->unkC->unk870);
                        return;
                    }
                }
            }
            if (AddGoal_MoveToLastPlayerPos() == 0) {
                AddGoal_Idle();
            }
        }
    }
}
#endif

void SwampTier1Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 SwampTier1Goal_Think::Update() {
    Enemy *temp_r3_1133;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_1133 = this->unkC;
    if (temp_r3_1133->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        this->unk3D = 0;
        Activate();
    }
    return this->unk8;
}

void SwampTier1Goal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk3C = 0;
}

void SwampTier1Goal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void SwampTier1Goal_Think::Deinit() {
    Goal<SwampTier1> *temp_r3_1213;
    Goal<SwampTier1> *temp_r3_1218;
    Goal<SwampTier1> *temp_r3_1223;
    Goal<SwampTier1> *temp_r3_1228;
    Goal<SwampTier1> *temp_r3_1233;
    Goal<SwampTier1> *temp_r3_1238;
    Goal<SwampTier1> *temp_r3_1243;
    void *temp_r31_1262;

    temp_r3_1213 = this->unk20;
    temp_r3_1213->Deinit();
    temp_r3_1218 = this->unk28;
    temp_r3_1218->Deinit();
    temp_r3_1223 = this->unk2C;
    temp_r3_1223->Deinit();
    temp_r3_1228 = this->unk30;
    temp_r3_1228->Deinit();
    temp_r3_1233 = this->unk24;
    temp_r3_1233->Deinit();
    temp_r3_1238 = this->unk34;
    temp_r3_1238->Deinit();
    temp_r3_1243 = this->unk38;
    temp_r3_1243->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk24);
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_1262 = this->unk1C;
    if (temp_r31_1262 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1262, NULL, 0);
        } else {
            free(temp_r31_1262);
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
void SwampTier1Goal_Think::Init(SwampTier1 *arg0) {
    Goal<SwampTier1> *temp_r4_1500;
    Goal<SwampTier1> *temp_r4_1514;
    Goal<SwampTier1> *temp_r4_1525;
    Goal<SwampTier1> *temp_r4_1542;
    void *var_r3_1480;

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
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x48U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier1>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__27CompositeGoal<10SwampTier1>;
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
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_1480 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_1480 = malloc(8);
        }
        this->unk1C = var_r3_1480;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x74;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1500 = this->unk20;
    M2C_FIELD(temp_r4_1500, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1500, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1500, s32 *, 4) = 0;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_1500, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1500, s8 *, 9) = 1;
    }
    ((EnemyGoal_Death *) this->unk28)->Init((Enemy *) arg0);
    temp_r4_1514 = this->unk2C;
    M2C_FIELD(temp_r4_1514, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1514, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1514, s32 *, 4) = 0x1E;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_1514, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1514, s8 *, 9) = 1;
    }
    temp_r4_1525 = this->unk30;
    M2C_FIELD(temp_r4_1525, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1525, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1525, s32 *, 4) = 0x38;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_1525, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1525, s8 *, 9) = 1;
    }
    ((SwampTier1Goal_Hit *) this->unk24)->Init(arg0);
    ((EnemyGoal_AlertMode *) this->unk34)->Init((Enemy *) arg0);
    temp_r4_1542 = this->unk38;
    M2C_FIELD(temp_r4_1542, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1542, SwampTier1 **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1542, s32 *, 4) = 0x21;
    if ((SwampTier1 *) M2C_FIELD(temp_r4_1542, SwampTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1542, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1542, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_1542, u8 *, 0x30) & ~0x10);
    this->unk3C = 0;
    this->unk3D = 0;
}
#endif

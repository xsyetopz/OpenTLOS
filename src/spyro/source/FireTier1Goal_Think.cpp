#include "spyro/source/FireTier1Goal_Think.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
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
#include "spyro/source/Enemies_Fire.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_AlertMode.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
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
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

u8 FireTier1Goal_Patrol::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    } else {
        ReactivateIfFailed();
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireTier1Goal_Patrol::Activate() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_52;
    Enemy *temp_r6_57;
    Goal<Enemy> *temp_r3_96;
    Goal<Enemy> *temp_r4_128;
    Goal<Enemy> *temp_r5_118;
    void *temp_r3_58;
    void *temp_r3_61;
    void *temp_r3_76;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_52 = this->unkC;
    temp_r3_52->unkB08 &= ~0x40;
    temp_r6_57 = this->unkC;
    temp_r3_58 = temp_r6_57->unkA44;
    if (temp_r3_58 != NULL) {
        temp_r3_61 = M2C_FIELD(temp_r3_58, void **, 0x1C);
        if ((temp_r3_61 != NULL) && ((s32) M2C_FIELD(temp_r3_61, s32 *, 0x20) > 0)) {
            sp18 = 0.0f;
            sp1C = 0.0f;
            sp20 = 0.0f;
            temp_r3_76 = temp_r6_57->unkA38->GetAnimSequence(0xB, 0, temp_r6_57->unkAE4, NULL);
            sp8 = M2C_FIELD(temp_r3_76, f64 *, 0x48);
            sp10 = M2C_FIELD(temp_r3_76, f64 *, 0x50);
            if (this->unk20->SelectFlyToWallPos(*((MKVector3 *) &sp8), &this->unk48, (MKVector3 *) &sp18, &this->unk38) != 0) {
                if (!(((u8) this->unkC->unk6B5 >> 4U) & 1)) {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
                    temp_r3_96 = this->unk24;
                    M2C_FIELD(temp_r3_96, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r3_96, u8 *, 0x10) & ~0x80);
                }
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
                this->unkC->unk8C0.Set(this->unk38, 1U);
                temp_r5_118 = this->unk2C;
                M2C_FIELD(temp_r5_118, AITargetData **, 0x14) = &this->unkC->unk8C0;
                M2C_FIELD(temp_r5_118, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 0x38);
                M2C_FIELD(temp_r5_118, f64 *, 0x20) = (f64) M2C_FIELD(this, f64 *, 0x40);
                M2C_FIELD(temp_r5_118, f32 *, 0x28) = 10.0f;
                temp_r4_128 = this->unk28;
                M2C_FIELD(temp_r4_128, f64 *, 0x10) = (f64) M2C_FIELD(this, f64 *, 0x48);
                M2C_FIELD(temp_r4_128, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 0x50);
                M2C_FIELD(temp_r4_128, f64 *, 0x20) = (f64) sp18;
                M2C_FIELD(temp_r4_128, f64 *, 0x28) = (f64) sp20;
                ((EnemyGoal_WanderAroundPointArb *) this->unk30)->SetParams(this->unk48, *((MKVector3 *) &sp18), 200.0f, MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f));
                return;
            }
        }
    }
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
    ((EnemyGoal_WanderAroundPointArb *) this->unk30)->SetParams(this->unk48, MKVector3::up, 200.0f, MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f));
}
#endif

void FireTier1Goal_Patrol::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk48.unk0 = 0.0f;
    this->unk48.unk4 = 0.0f;
    this->unk48.unk8 = 0.0f;
    this->unk38.unk0 = 0.0f;
    this->unk38.unk4 = 0.0f;
    this->unk38.unk8 = 0.0f;
    this->unk34 &= ~0x80;
}

void FireTier1Goal_Patrol::Deinit() {
    Goal<Enemy> *temp_r3_205;
    Goal<Enemy> *temp_r3_210;
    Goal<Enemy> *temp_r3_215;
    Goal<Enemy> *temp_r3_220;
    MKHeap *temp_r3_236;
    void *temp_r31_233;

    temp_r3_205 = this->unk24;
    temp_r3_205->Deinit();
    temp_r3_210 = this->unk28;
    temp_r3_210->Deinit();
    temp_r3_215 = this->unk2C;
    temp_r3_215->Deinit();
    temp_r3_220 = this->unk30;
    temp_r3_220->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_233 = this->unk1C;
    if (temp_r31_233 != NULL) {
        temp_r3_236 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_236 != NULL) {
            ((MKHeap *) (temp_r3_236->Current()))->Free(temp_r31_233, NULL, 0);
        } else {
            free(temp_r31_233);
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
void FireTier1Goal_Patrol::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_402;
    Goal<Enemy> *temp_r4_411;
    MKHeap *temp_r3_370;
    void *var_r3_377;

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
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x30U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x30U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x58U, NULL, 0);
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_370 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_370 != NULL) {
            var_r3_377 = ((MKHeap *) (temp_r3_370->Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_377 = malloc(0x10);
        }
        this->unk1C = var_r3_377;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x64;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk20 = checked_cast<FireTier1 *, Enemy>(arg0);
    temp_r4_402 = this->unk24;
    M2C_FIELD(temp_r4_402, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_402, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_402, s32 *, 4) = 0x41;
    if ((Enemy *) M2C_FIELD(temp_r4_402, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_402, s8 *, 9) = 1;
    }
    temp_r4_411 = this->unk28;
    M2C_FIELD(temp_r4_411, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_411, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_411, s32 *, 4) = 0x42;
    if ((Enemy *) M2C_FIELD(temp_r4_411, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_411, s8 *, 9) = 1;
    }
    ((EnemyGoal_FlyToTarget *) this->unk2C)->Init(arg0);
    ((EnemyGoal_WanderAroundPointArb *) this->unk30)->Init(arg0);
}
#endif

u8 EnemyGoal_WanderAroundPointArb::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if (((u8) this->unk8 == 2) && !(M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkA78)) {
        Activate();
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyGoal_WanderAroundPointArb::Activate() {
    MKVector3 sp8;
    Goal<Enemy> *temp_r8_501;

    if ((u8) this->unk8 == 1) {
        this->unkC->unkA78 = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
    }
    this->unk8 = 0;
    RemoveAllSubgoals();
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
    temp_r8_501 = this->unk28;
    M2C_FIELD(temp_r8_501, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r8_501, s32 *, 0x14) = 2;
    M2C_FIELD(temp_r8_501, s32 *, 0x18) = 1;
    M2C_FIELD(temp_r8_501, s32 *, 0x1C) = 1;
    M2C_FIELD(temp_r8_501, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r8_501, u8 *, 0x20) & ~0x40);
    if (this->unk20->SelectMoveToWallPos(this->unk30, this->unk40, &sp8) != 0) {
        this->unkC->unk8C0.Set(sp8, 1U);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        M2C_FIELD(this->unk24, f32 *, 0x10) = 20.0f;
    }
}
#endif

void EnemyGoal_WanderAroundPointArb::SetParams(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, float arg3) {
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x40) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    this->unk50 = arg2;
}

void EnemyGoal_WanderAroundPointArb::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk30.unk0 = 0.0f;
    this->unk30.unk4 = 0.0f;
    this->unk30.unk8 = 0.0f;
    this->unk40.unk0 = 0.0f;
    this->unk40.unk4 = 0.0f;
    this->unk40.unk8 = 0.0f;
    this->unk50 = 0.0f;
}

void EnemyGoal_WanderAroundPointArb::Deinit() {
    Goal<Enemy> *temp_r3_587;
    Goal<Enemy> *temp_r3_592;
    MKHeap *temp_r3_604;
    void *temp_r31_601;

    temp_r3_587 = this->unk24;
    temp_r3_587->Deinit();
    temp_r3_592 = this->unk28;
    temp_r3_592->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    temp_r31_601 = this->unk1C;
    if (temp_r31_601 != NULL) {
        temp_r3_604 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_604 != NULL) {
            ((MKHeap *) (temp_r3_604->Current()))->Free(temp_r31_601, NULL, 0);
        } else {
            free(temp_r31_601);
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
void EnemyGoal_WanderAroundPointArb::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_723;
    Goal<Enemy> *temp_r4_732;
    MKHeap *temp_r3_691;
    void *var_r3_698;

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
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
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
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_691 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_691 != NULL) {
            var_r3_698 = ((MKHeap *) (temp_r3_691->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_698 = malloc(8);
        }
        this->unk1C = var_r3_698;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x25;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk20 = checked_cast<FireTier1 *, Enemy>(arg0);
    temp_r4_723 = this->unk24;
    M2C_FIELD(temp_r4_723, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_723, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_723, s32 *, 4) = 0x24;
    if ((Enemy *) M2C_FIELD(temp_r4_723, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_723, s8 *, 9) = 1;
    }
    temp_r4_732 = this->unk28;
    M2C_FIELD(temp_r4_732, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_732, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_732, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_732, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_732, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
u8 EnemyGoal_WalkToTargetArb::Update() {
    f64 sp8;
    Character *temp_r3_778;
    Character *temp_r3_784;
    Character *temp_r4_759;

    ActivateIfInactive();
    temp_r4_759 = this->unkC;
    temp_r4_759->unk8C0.Update(temp_r4_759->unk588);
    if (this->unkC->unk8C0.GetDist() <= this->unk10) {
        this->unk8 = 2;
    } else {
        ((AITargetData *) &sp8)->GetDir();
        temp_r3_778 = this->unkC;
        M2C_FIELD(temp_r3_778, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r3_778, f64 *, 0xE8) = sp10;
    }
    temp_r3_784 = this->unkC;
    M2C_FIELD(temp_r3_784, f64 *, 0x598) = (f64) (M2C_FIELD(temp_r3_784, f64 *, 0x598) + M2C_FIELD(temp_r3_784, f64 *, 0x90));
    temp_r3_784->unk5A0 += temp_r3_784->unk98;
    return this->unk8;
}
#endif

void EnemyGoal_WalkToTargetArb::Activate() {
    Character *temp_r3_815;

    this->unk8 = 0;
    temp_r3_815 = this->unkC;
    temp_r3_815->unk6B5 |= 0x20;
    this->unkC->SetMovementType((CharacterMoveType) 1);
    ((Enemy *) this->unkC)->SetWalkMovementSpeed(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 5, 0, 0, 0.15f, 0U, 0U);
}

#if 0 // DRAFT: ';' expected
u8 EnemyGoal_FlyToAttackTarget::Update() {
    MKCollisionResult sp290;
    Matrix sp250;
    f64 sp240;
    f64 sp238;
    AITargetData sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f32 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp168;
    M2C_UNK sp158;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    M2C_UNK sp118;
    f32 sp108;
    AITargetData spE8;
    AITargetData spD8;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    AITargetData *temp_r3_861;
    Enemy *temp_r3_1220;
    Enemy *temp_r3_1283;
    Enemy *temp_r4_1171;
    Enemy *temp_r4_1197;
    Enemy *temp_r4_1262;
    Enemy *temp_r4_1291;
    Enemy *temp_r4_1308;
    Enemy *temp_r4_1326;
    Enemy *temp_r5_1271;
    Enemy *temp_r6_1183;
    f32 temp_f1_1245;
    f32 temp_f27_1244;
    f32 temp_f31_1103;
    f32 temp_f4_1051;
    f32 temp_f5_1055;
    f32 temp_f6_942;
    f32 temp_f7_1053;
    f32 temp_f7_946;
    f32 temp_f9_944;
    f32 var_f3_1043;
    f32 var_f4_976;
    f64 temp_f0_1108;
    f64 temp_f0_1119;
    f64 temp_f0_1130;
    f64 temp_f0_892;
    f64 temp_f0_903;
    f64 temp_f1_887;
    f64 temp_f1_982;
    f64 temp_f1_988;
    f64 temp_f1_992;
    s32 temp_r3_1011;
    s32 var_r0_1021;
    u8 var_r31_865;

    ActivateIfInactive();
    temp_r3_861 = this->unk10;
    if (temp_r3_861 != NULL) {
        var_r31_865 = 0;
        if (((u8) M2C_FIELD(temp_r3_861, u8 *, 0x48) == 2) || (temp_r3_861->unk40.Get() != NULL)) {
            var_r31_865 = 1;
        }
        if (var_r31_865 != 0) {
            this->unk10->Update(this->unkC->unk588);
            temp_f1_887 = M2C_FIELD(this->unk10->unk40.Get()->__vptr, f64 (**)(), 0x3C)();
            temp_f0_892 = M2C_FIELD(&MKVector3::up, f64 *, 0) * temp_f1_887;
            spB8 = temp_f0_892;
            sp1C8 = temp_f0_892;
            spC0 = MKVector3::up.unk8 * (f32) temp_f1_887;
            sp1D0 = (f64) spC0;
            temp_f0_903 = temp_f0_892 * 5.24282163e-315;
            spA8 = temp_f0_903;
            sp1D8 = temp_f0_903;
            spB0 = (f32) sp1D0 * 0.75f;
            sp1E0 = (f64) spB0;
            sp1E8.GetPos();
            sp98 = sp1E8.unk0 + sp1D8;
            sp238 = sp98;
            spA0 = sp1E8.unk8 + (f32) sp1E0;
            sp1E8.unk40 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            sp240 = (f64) spA0;
            sp1E8.unk40.unk8 = (f64) M2C_FIELD(&MKVector3::up, f32 *, 8);
            ((AITargetData *) &sp198)->GetDir();
            temp_f6_942 = M2C_BITWISE(f32, sp1E8.unk40.unk8);
            temp_f9_944 = M2C_BITWISE(f32, sp1E8.unk40);
            sp88 = -sp198;
            temp_f7_946 = M2C_BITWISE(f32, sp1E8.unk40.unk4);
            sp8C = -sp19C;
            sp90 = -sp1A0;
            sp1A8 = (f64) sp88;
            sp1B0 = (f64) sp90;
            sp78 = (temp_f7_946 * (f32) sp1B0) - (temp_f6_942 * (*(f32 *) ((u8 *) &sp1A8 + 0x4)));
            sp7C = (temp_f6_942 * (f32) sp1A8) - (temp_f9_944 * (f32) sp1B0);
            sp80 = (temp_f9_944 * (*(f32 *) ((u8 *) &sp1A8 + 0x4))) - (temp_f7_946 * (f32) sp1A8);
            sp1B8 = (f64) sp78;
            sp1C0 = (f64) sp80;
            var_f4_976 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * (*(f32 *) ((u8 *) &sp1B8 + 0x4))));
            if (var_f4_976 > 1e-12f) {
                if (var_f4_976 > 0.0f) {
                    temp_f1_982 = __frsqrte(var_f4_976);
                    temp_f1_988 = 0.5 * temp_f1_982 * -(((f64) var_f4_976 * (temp_f1_982 * temp_f1_982)) - 3.0);
                    temp_f1_992 = 0.5 * temp_f1_988 * -(((f64) var_f4_976 * (temp_f1_988 * temp_f1_988)) - 3.0);
                    var_f4_976 = (f32) ((f64) var_f4_976 * (0.5 * temp_f1_992 * -(((f64) var_f4_976 * (temp_f1_992 * temp_f1_992)) - 3.0)));
                } else if (var_f4_976 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_976 = __float_nan;
                } else {
                    sp10 = var_f4_976;
                    temp_r3_1011 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1011) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1021 = 1;
                        } else {
                            var_r0_1021 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1021 = 5;
                        } else {
                            var_r0_1021 = 3;
                        }
                        break;
                    default:
                        var_r0_1021 = 4;
                        break;
                    }
                    if (var_r0_1021 == 1) {
                        var_f4_976 = __float_nan;
                    }
                }
                var_f3_1043 = 1.0f / var_f4_976;
            } else {
                var_f3_1043 = 0.0f;
            }
            temp_f4_1051 = M2C_BITWISE(f32, sp1E8.unk40.unk8);
            temp_f7_1053 = M2C_BITWISE(f32, sp1E8.unk40.unk4);
            sp6C = (*(f32 *) ((u8 *) &sp1B8 + 0x4)) * var_f3_1043;
            temp_f5_1055 = M2C_BITWISE(f32, sp1E8.unk40);
            sp68 = (f32) sp1B8 * var_f3_1043;
            sp70 = (f32) sp1C0 * var_f3_1043;
            sp1E8.unk30 = (f64) sp68;
            sp1E8.unk38 = (f64) sp70;
            sp60 = (sp1E8.unk30 * temp_f7_1053) - (sp1E8.unk34 * temp_f5_1055);
            sp58 = (sp1E8.unk34 * temp_f4_1051) - (sp1E8.unk38 * temp_f7_1053);
            sp5C = (sp1E8.unk38 * temp_f5_1055) - (sp1E8.unk30 * temp_f4_1051);
            sp1E8.unk28 = (f64) sp60;
            sp1E8.unk20 = (f64) sp58;
            sp250.SetIdentity();
            sp250 = sp1E8.unk30;
            sp250.unk4 = sp1E8.unk34;
            sp250.unk8 = sp1E8.unk38;
            sp250.unkC = 0.0f;
            sp250.unk10 = M2C_BITWISE(f32, sp1E8.unk40);
            sp250.unk14 = M2C_BITWISE(f32, sp1E8.unk40.unk4);
            sp250.unk18 = M2C_BITWISE(f32, sp1E8.unk40.unk8);
            sp250.unk1C = 0.0f;
            sp250.unk20 = (f32) sp1E8.unk20;
            sp250.unk24 = (*(f32 *) ((u8 *) &sp1E8 + 0x24));
            sp250.unk28 = (f32) sp1E8.unk28;
            sp250.unk2C = 0.0f;
            temp_f31_1103 = this->unk14;
            ((AITargetData *) &sp168)->GetDir();
            temp_f0_1108 = sp168 * (f64) temp_f31_1103;
            sp48 = temp_f0_1108;
            sp178 = temp_f0_1108;
            sp50 = sp170 * temp_f31_1103;
            sp180 = (f64) sp50;
            temp_f0_1119 = temp_f0_1108 * 5.246966156e-315;
            sp38 = temp_f0_1119;
            sp188 = temp_f0_1119;
            sp40 = (f32) sp180 * 0.8f;
            sp190 = (f64) sp40;
            temp_f0_1130 = sp238 - temp_f0_1119;
            sp28 = temp_f0_1130;
            sp1E8.unk10 = temp_f0_1130;
            sp30 = (f32) sp240 - (f32) sp190;
            sp1E8.unk18 = (f64) sp30;
            if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp1E8.unk10), 500.0f, &sp290, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18), 2, NULL, (MKCollisionMode) 6) != 0) {
                (*(f32 *) ((u8 *) &sp1E8 + 0x14)) = 80.0f + sp290.unk4;
            } else {
                ((AITargetData *) &sp158)->GetPos();
                (*(f32 *) ((u8 *) &sp1E8 + 0x14)) = 80.0f + sp15C;
            }
            this->unkC->unk8C0.Set(*((MKVector3 *) &sp1E8.unk10), 1U);
            temp_r4_1171 = this->unkC;
            temp_r4_1171->unk8C0.Update(temp_r4_1171->unk588);
            if (this->unk10->GetDist() < this->unk14) {
                ((AITargetData *) &sp148)->GetDir();
                temp_r6_1183 = this->unkC;
                M2C_FIELD(temp_r6_1183, f64 *, 0xE0) = sp148;
                M2C_FIELD(temp_r6_1183, f64 *, 0xE8) = sp150;
                temp_r6_1183->unk6B5 |= 0x40;
                temp_r4_1197 = this->unkC;
                M2C_FIELD(temp_r4_1197, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
                M2C_FIELD(temp_r4_1197, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f32 *, 8);
                temp_r4_1197->unk6B5 |= 0x40;
                ((AITargetData *) &sp118)->GetDir();
                __ml(((MKVector3 *) &this->unkC->unk80)->Magnitude(), sp128);
                sp18 = sp128 * 5.28426686e-315;
                temp_r3_1220 = this->unkC;
                sp138 = sp18;
                sp20 = sp128.unk8 * 1.5f;
                M2C_FIELD(temp_r3_1220, f64 *, 0x598) = sp18;
                sp140 = (f64) sp20;
                M2C_FIELD(temp_r3_1220, f64 *, 0x5A0) = (f64) sp20;
            } else {
                ((AITargetData *) &sp108)->GetDir();
                temp_f27_1244 = (sp110 * MKVector3::up.unk8) + ((sp108 * MKVector3::up.unk0) + (sp10C * MKVector3::up.unk4));
                temp_f1_1245 = _table_sinf(2.3561945f);
                if ((temp_f27_1244 > temp_f1_1245) || (temp_f27_1244 < -temp_f1_1245)) {
                    spE8.GetDir();
                    __ml(((MKVector3 *) &this->unkC->unk80)->Magnitude(), *((MKVector3 *) &spE8.unk10));
                    temp_r4_1262 = this->unkC;
                    M2C_FIELD(temp_r4_1262, f64 *, 0x598) = spE8.unk10;
                    M2C_FIELD(temp_r4_1262, f64 *, 0x5A0) = spE8.unk18;
                    spD8.GetDir();
                    temp_r5_1271 = this->unkC;
                    M2C_FIELD(temp_r5_1271, f64 *, 0xE0) = M2C_BITWISE(f64, spD8);
                    M2C_FIELD(temp_r5_1271, f64 *, 0xE8) = (f64) spD8.unk8;
                    temp_r5_1271->unk6B5 |= 0x40;
                    temp_r3_1283 = this->unkC;
                    M2C_FIELD(temp_r3_1283, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
                    M2C_FIELD(temp_r3_1283, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f32 *, 8);
                    temp_r3_1283->unk6B5 |= 0x40;
                } else {
                    temp_r4_1291 = this->unkC;
                    M2C_FIELD(temp_r4_1291, f64 *, 0x598) = (f64) M2C_FIELD(temp_r4_1291, f64 *, 0x90);
                    M2C_FIELD(temp_r4_1291, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r4_1291, f64 *, 0x98);
                    ((AITargetData *) &spC8)->GetDir();
                    temp_r4_1308 = this->unkC;
                    M2C_FIELD(temp_r4_1308, f64 *, 0xE0) = spC8;
                    M2C_FIELD(temp_r4_1308, f64 *, 0xE8) = spD0;
                    temp_r4_1308->unk6B5 = (temp_r4_1308->unk6B5 & ~0x40) | ((((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) == 0) << 6) & 0x40);
                    temp_r4_1326 = this->unkC;
                    M2C_FIELD(temp_r4_1326, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
                    M2C_FIELD(temp_r4_1326, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f32 *, 8);
                    temp_r4_1326->unk6B5 = (temp_r4_1326->unk6B5 & ~0x40) | ((((((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1) == 0) << 6) & 0x40);
                }
            }
            if (this->unkC->unk8C0.GetDist() < 10.0f) {
                this->unk8 = 2;
            }
        } else {
            goto block_36;
        }
    } else {
block_36:
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void EnemyGoal_FlyToAttackTarget::Activate() {
    Enemy *temp_r3_1386;
    Enemy *temp_r3_1390;

    this->unk8 = 0;
    this->unk18 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
    temp_r3_1386 = this->unkC;
    temp_r3_1386->unk6B5 &= ~0x20;
    temp_r3_1390 = this->unkC;
    temp_r3_1390->unk6B5 |= 0x10;
    this->unkC->SetRunMovementSpeed(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 1);
    this->unkC->SetAnim((AnimSequenceType) 0xB, 0, 1, 0.15f, 0U, 0U);
}

#if 0 // DRAFT: undefined identifier '__float_nan'
u8 EnemyGoal_FlyToTarget::Update() {
    AITargetData sp138;
    f64 sp128;
    f32 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f32 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp10;
    f32 spC;
    f32 sp8;
    AITargetData *temp_r3_1431;
    Enemy *temp_r3_1557;
    Enemy *temp_r3_1737;
    Enemy *temp_r3_1744;
    Enemy *temp_r4_1456;
    Enemy *temp_r5_1598;
    Enemy *temp_r5_1725;
    f32 temp_f0_1463;
    f32 temp_f1_1462;
    f32 temp_f28_1553;
    f32 temp_f29_1639;
    f32 temp_f2_1606;
    f32 temp_f30_1540;
    f32 temp_f3_1465;
    f32 temp_f3_1603;
    f32 temp_f4_1607;
    f32 temp_f5_1602;
    f32 temp_f6_1601;
    f32 temp_f7_1604;
    f32 var_f4_1470;
    f64 temp_f0_1670;
    f64 temp_f0_1680;
    f64 temp_f0_1691;
    f64 temp_f0_1703;
    f64 temp_f1_1474;
    f64 temp_f1_1480;
    f64 temp_f1_1484;
    s32 temp_cr0_gt_1471;
    s32 temp_r3_1503;
    s32 var_r0_1513;
    u8 var_r30_1435;

    ActivateIfInactive();
    temp_r3_1431 = this->unk14;
    if (temp_r3_1431 != NULL) {
        var_r30_1435 = 0;
        if (((u8) M2C_FIELD(temp_r3_1431, u8 *, 0x48) == 2) || (temp_r3_1431->unk40.Get() != NULL)) {
            var_r30_1435 = 1;
        }
        if (var_r30_1435 == 0) {
            goto block_5;
        }
        this->unk14->Update(this->unkC->unk588);
        temp_r4_1456 = this->unkC;
        if (M2C_FIELD(temp_r4_1456->unk630, f32 *, 0x24) > 0.2f) {
            temp_f1_1462 = M2C_FIELD(temp_r4_1456, f32 *, 0x100);
            temp_f0_1463 = M2C_FIELD(temp_r4_1456, f32 *, 0x104);
            temp_f3_1465 = M2C_FIELD(temp_r4_1456, f32 *, 0x108);
            var_f4_1470 = (temp_f3_1465 * temp_f3_1465) + ((temp_f1_1462 * temp_f1_1462) + (temp_f0_1463 * temp_f0_1463));
            temp_cr0_gt_1471 = var_f4_1470 > 0.0f;
            if (temp_cr0_gt_1471 != 0) {
                if (temp_cr0_gt_1471 != 0) {
                    temp_f1_1474 = __frsqrte(var_f4_1470);
                    temp_f1_1480 = 0.5 * temp_f1_1474 * -(((f64) var_f4_1470 * (temp_f1_1474 * temp_f1_1474)) - 3.0);
                    temp_f1_1484 = 0.5 * temp_f1_1480 * -(((f64) var_f4_1470 * (temp_f1_1480 * temp_f1_1480)) - 3.0);
                    var_f4_1470 = (f32) ((f64) var_f4_1470 * (0.5 * temp_f1_1484 * -(((f64) var_f4_1470 * (temp_f1_1484 * temp_f1_1484)) - 3.0)));
                } else if (var_f4_1470 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1470 = __float_nan;
                } else {
                    sp8 = var_f4_1470;
                    temp_r3_1503 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1503) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1513 = 1;
                        } else {
                            var_r0_1513 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1513 = 5;
                        } else {
                            var_r0_1513 = 3;
                        }
                        break;
                    default:
                        var_r0_1513 = 4;
                        break;
                    }
                    if (var_r0_1513 == 1) {
                        var_f4_1470 = __float_nan;
                    }
                }
                temp_f30_1540 = KDMath_GetTurningCircleRadius(var_f4_1470 / gUpdateTimeDelta, this->unkC->unk68C / gUpdateTimeDelta);
                if (this->unk14->GetDist() <= temp_f30_1540) {
                    temp_f28_1553 = _table_sinf((1.570796f * (this->unk14->GetDist() / temp_f30_1540)) + 1.5707964f);
                    sp138.GetDir();
                    temp_r3_1557 = this->unkC;
                    if (((temp_r3_1557->unkC8 * sp138.unk8) + ((temp_r3_1557->unkC0 * M2C_BITWISE(f32, sp138)) + (temp_r3_1557->unkC4 * (*(f32 *) ((u8 *) &sp138 + 0x4))))) < temp_f28_1553) {
                        ((AITargetData *) &sp128)->GetPos();
                        sp18 = sp128 - this->unk18;
                        sp88 = sp18;
                        sp20 = sp130 - this->unk20;
                        sp90 = (f64) sp20;
                        sp98 = sp18;
                        spA0 = (f64) sp20;
                        if ((((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))))) < 100.0f) {
                            temp_r5_1598 = this->unkC;
                            temp_f6_1601 = temp_r5_1598->unkD4;
                            temp_f5_1602 = temp_r5_1598->unkC0;
                            temp_f3_1603 = temp_r5_1598->unkC8;
                            temp_f7_1604 = temp_r5_1598->unkD0;
                            temp_f2_1606 = temp_r5_1598->unkC4;
                            temp_f4_1607 = temp_r5_1598->unkD8;
                            sp80 = (temp_f7_1604 * temp_f2_1606) - (temp_f6_1601 * temp_f5_1602);
                            sp7C = (temp_f4_1607 * temp_f5_1602) - (temp_f7_1604 * temp_f3_1603);
                            sp78 = (temp_f6_1601 * temp_f3_1603) - (temp_f4_1607 * temp_f2_1606);
                            sp138.unk28 = (f64) sp80;
                            sp138.unk20 = (f64) sp78;
                            ((AITargetData *) &sp118)->GetDir();
                            spC = ((f32) sp138.unk28 * sp120) + (((f32) sp138.unk20 * sp118) + ((*(f32 *) ((u8 *) &sp138 + 0x24)) * sp11C));
                            sp10 = (M2C_BITWISE(s32, spC) & 0x80000000) | 0x3F800000;
                            temp_f29_1639 = -1.0f * M2C_BITWISE(f32, sp10);
                            ((AITargetData *) &spE8)->GetDir();
                            sp28 = (MKVector3::up.unk4 * spF0) - (MKVector3::up.unk8 * spEC);
                            sp2C = (MKVector3::up.unk8 * spE8) - (MKVector3::up.unk0 * spF0);
                            sp30 = (MKVector3::up.unk0 * spEC) - (MKVector3::up.unk4 * spE8);
                            spF8 = (f64) sp28;
                            sp100 = (f64) sp30;
                            Normalise(sp108);
                            sp138.unk20 = M2C_BITWISE(f64, sp108);
                            sp138.unk28 = (f64) sp108.unk8;
                            temp_f0_1670 = sp138.unk20 * (f64) temp_f29_1639;
                            sp68 = temp_f0_1670;
                            spB8 = temp_f0_1670;
                            sp70 = (f32) sp138.unk28 * temp_f29_1639;
                            spC0 = (f64) sp70;
                            temp_f0_1680 = temp_f0_1670 * (f64) temp_f30_1540;
                            sp58 = temp_f0_1680;
                            spC8 = temp_f0_1680;
                            sp60 = (f32) spC0 * temp_f30_1540;
                            spD0 = (f64) sp60;
                            temp_f0_1691 = temp_f0_1680 * 5.307061737e-315;
                            sp48 = temp_f0_1691;
                            spD8 = temp_f0_1691;
                            sp50 = (f32) spD0 * 2.1f;
                            spE0 = (f64) sp50;
                            temp_f0_1703 = this->unk18 + temp_f0_1691;
                            sp38 = temp_f0_1703;
                            this->unk18 = temp_f0_1703;
                            sp138.unk10 = temp_f0_1703;
                            sp40 = this->unk20 + (f32) spE0;
                            M2C_FIELD(this, f32 *, 0x20) = (f64) sp40;
                            sp138.unk18 = (f64) sp40;
                            this->unk2C |= 0x80;
                            this->unk8 = 3;
                        }
                    }
                }
            }
        }
        ((AITargetData *) &spA8)->GetDir();
        temp_r5_1725 = this->unkC;
        M2C_FIELD(temp_r5_1725, f64 *, 0xE0) = spA8;
        M2C_FIELD(temp_r5_1725, f64 *, 0xE8) = spB0;
        temp_r5_1725->unk6B5 &= ~0x40;
        temp_r3_1737 = this->unkC;
        M2C_FIELD(temp_r3_1737, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f32 *, 0);
        M2C_FIELD(temp_r3_1737, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f32 *, 8);
        temp_r3_1737->unk6B5 &= ~0x40;
    } else {
block_5:
        this->unk8 = 3;
    }
    temp_r3_1744 = this->unkC;
    M2C_FIELD(temp_r3_1744, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_1744, f64 *, 0x90);
    M2C_FIELD(temp_r3_1744, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_1744, f64 *, 0x98);
    if (this->unk14->GetDist() <= this->unk28) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void EnemyGoal_FlyToTarget::Activate() {
    Enemy *temp_r3_1786;
    Enemy *temp_r3_1790;
    FireTier1 *temp_r3_1807;

    this->unk8 = 0;
    temp_r3_1786 = this->unkC;
    temp_r3_1786->unk6B5 &= ~0x20;
    temp_r3_1790 = this->unkC;
    temp_r3_1790->unk6B5 |= 0x10;
    this->unkC->SetRunMovementSpeed(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 1);
    this->unkC->SetAnim((AnimSequenceType) 0xB, 0, 1, 0.15f, 0U, 0U);
    temp_r3_1807 = this->unk10;
    temp_r3_1807->unkB40 &= ~0x80;
}

void EnemyGoal_FlyToTarget::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x44;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk10 = checked_cast<FireTier1 *, Enemy>(arg0);
}

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 EnemyGoal_FlyIdle::Update() {
    MKCollisionResult sp38;
    M2C_UNK sp28;
    f64 sp20;
    f64 sp18;
    f64 sp8;
    AITargetData *temp_r3_1909;
    Character *temp_r29_1862;
    Character *temp_r3_1856;
    Character *temp_r3_1895;
    Character *temp_r3_1925;
    Character *temp_r3_1949;
    Character *temp_r4_1890;
    Character *temp_r4_1978;
    Character *temp_r4_1992;
    f32 temp_f2_1952;
    f32 var_f2_1939;
    s32 temp_r3_1994;
    u32 *temp_r4_1867;
    u32 *temp_r4_1897;
    u8 var_r30_1857;
    u8 var_r30_1913;
    u8 var_r5_1896;
    void *temp_r3_1968;

    ActivateIfInactive();
    temp_r3_1856 = this->unkC;
    var_r30_1857 = 0;
    M2C_FIELD(temp_r3_1856, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_1856, f64 *, 0x90);
    M2C_FIELD(temp_r3_1856, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_1856, f64 *, 0x98);
    temp_r29_1862 = this->unkC;
    if (temp_r29_1862->HasAnimFinished() != 0) {
        temp_r4_1867 = temp_r29_1862->unkA50;
        if ((temp_r4_1867 != NULL) && ((u32) *temp_r4_1867 == (u32) M2C_FIELD(temp_r29_1862->unk630, u32 *, 0x20))) {
            var_r30_1857 = 1;
        }
    }
    if (var_r30_1857 != 0) {
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
        ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
        temp_r4_1890 = this->unkC;
        temp_r4_1890->unk68C = M2C_FIELD(temp_r4_1890->unkA38, f32 *, 0x15C);
    }
    temp_r3_1895 = this->unkC;
    var_r5_1896 = 0;
    temp_r4_1897 = temp_r3_1895->unkA50;
    if ((temp_r4_1897 != NULL) && ((u32) M2C_FIELD(temp_r4_1897, u32 *, 0x20) == (u32) M2C_FIELD(temp_r3_1895->unk630, u32 *, 0x20))) {
        var_r5_1896 = 1;
    }
    if (var_r5_1896 != 0) {
        temp_r3_1909 = this->unk10;
        if (temp_r3_1909 != NULL) {
            var_r30_1913 = 0;
            if (((u8) M2C_FIELD(temp_r3_1909, u8 *, 0x48) == 2) || (temp_r3_1909->unk40.Get() != NULL)) {
                var_r30_1913 = 1;
            }
            if (var_r30_1913 != 0) {
                temp_r3_1925 = this->unkC;
                if (MKCollision_GetGroundPoint(temp_r3_1925->unk588, 500.0f, &sp38, M2C_FIELD(temp_r3_1925->unk110.unk460, s32 *, 0x18), 2, NULL, (MKCollisionMode) 6) != 0) {
                    var_f2_1939 = 80.0f + sp38.unk4;
                } else {
                    ((AITargetData *) &sp28)->GetPos();
                    var_f2_1939 = 80.0f + sp2C;
                }
                temp_r3_1949 = this->unkC;
                temp_f2_1952 = var_f2_1939 - temp_r3_1949->unk588.unk4;
                if ((f32) fabs(temp_f2_1952) > 0.5f) {
                    temp_r3_1949->unk59C += temp_f2_1952 * gUpdateTimeDelta;
                } else {
                    temp_r3_1949->unk59C = 0.0f;
                }
                temp_r3_1968 = this->unkC->unk8;
                sp18 = M2C_FIELD(temp_r3_1968, f64 *, 0x30);
                sp20 = M2C_FIELD(temp_r3_1968, f64 *, 0x38);
                this->unk10->Update(*((MKVector3 *) &sp18));
                ((AITargetData *) &sp8)->GetDir();
                temp_r4_1978 = this->unkC;
                M2C_FIELD(temp_r4_1978, f64 *, 0xE0) = sp8;
                M2C_FIELD(temp_r4_1978, f64 *, 0xE8) = sp10;
                temp_r4_1978->unk6B5 &= ~0x40;
            }
        }
        if (this->unkC->HasAnimFinished() != 0) {
            temp_r4_1992 = this->unkC;
            temp_r3_1994 = temp_r4_1992->unkAEC + 1;
            temp_r4_1992->unkAEC = temp_r3_1994;
            if (temp_r3_1994 >= (s32) this->unk14) {
                this->unk8 = 2;
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAEC'
void EnemyGoal_FlyIdle::Activate() {
    Character *temp_r3_2021;
    Character *temp_r3_2042;
    Character *temp_r4_2068;
    Character *temp_r5_2034;
    u8 temp_r5_2043;

    this->unk8 = 0;
    temp_r3_2021 = this->unkC;
    temp_r3_2021->unk6B5 &= ~0x20;
    this->unkC->unkAEC = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r5_2034 = this->unkC;
    M2C_FIELD(temp_r5_2034, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r5_2034, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r5_2034->unk6B5 |= 0x40;
    temp_r3_2042 = this->unkC;
    temp_r5_2043 = temp_r3_2042->unk6B5;
    if (!((temp_r5_2043 >> 4U) & 1)) {
        temp_r3_2042->unk6B5 = temp_r5_2043 | 0x10;
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 0, 0.15f, 0U, 0U);
        return;
    }
    ((Enemy *) temp_r3_2042)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
    temp_r4_2068 = this->unkC;
    temp_r4_2068->unk68C = M2C_FIELD(temp_r4_2068->unkA38, f32 *, 0x15C);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to
u8 EnemyGoal_FlyLand::Update() {
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Character *temp_r3_2097;
    Character *temp_r3_2139;
    Character *temp_r4_2126;
    f32 temp_f3_2099;
    f32 temp_f6_2104;
    f32 temp_f7_2110;

    ActivateIfInactive();
    sp30.SetIdentity();
    this->unkC->GetDesiredHeadingMatrix(&sp30);
    temp_r3_2097 = this->unkC;
    temp_f3_2099 = temp_r3_2097->unk84;
    temp_f6_2104 = temp_r3_2097->unk80;
    temp_f7_2110 = temp_r3_2097->unk88;
    sp10 = (temp_f7_2110 * sp30.unk20) + ((temp_f6_2104 * M2C_BITWISE(f32, sp30)) + (temp_f3_2099 * sp30.unk10));
    sp14 = (temp_f7_2110 * sp30.unk24) + ((temp_f6_2104 * sp30.unk4) + (temp_f3_2099 * sp30.unk14));
    sp18 = (temp_f7_2110 * sp30.unk28) + ((temp_f6_2104 * sp30.unk8) + (temp_f3_2099 * sp30.unk18));
    M2C_FIELD(temp_r3_2097, f64 *, 0x598) = (f64) sp10;
    M2C_FIELD(temp_r3_2097, f64 *, 0x5A0) = (f64) sp18;
    temp_r4_2126 = this->unkC;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    temp_r4_2126->unk8C0.Update(temp_r4_2126->unk588);
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
        temp_r3_2139 = this->unkC;
        temp_r3_2139->unk6B5 |= 0x20;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8C0'
void EnemyGoal_FlyLand::Activate() {
    AITargetData sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Character *temp_r3_2168;
    Character *temp_r3_2172;
    Character *temp_r3_2194;
    Character *temp_r3_2233;
    Character *temp_r4_2176;
    Character *temp_r5_2266;
    Character *temp_r5_2276;
    f32 temp_f2_2202;
    f32 temp_f3_2208;
    f32 temp_f4_2205;
    f32 temp_f6_2199;
    f32 temp_f7_2197;
    f32 temp_f8_2195;
    f64 temp_f0_2237;
    f64 temp_f0_2249;

    this->unk8 = 0;
    temp_r3_2168 = this->unkC;
    temp_r3_2168->unk6B5 &= ~0x20;
    temp_r3_2172 = this->unkC;
    temp_r3_2172->unk6B5 &= ~0x10;
    temp_r4_2176 = this->unkC;
    temp_r4_2176->unk8C0.Update(temp_r4_2176->unk588);
    sp70.GetPos();
    sp70.unk40 = M2C_BITWISE(f32, sp70);
    sp70.unk40.unk4 = (*(f32 *) ((u8 *) &sp70 + 0x4));
    sp70.unk40.unk8 = sp70.unk8;
    sp70.unk40.unkC = 1.0f;
    temp_r3_2194 = this->unkC;
    temp_f8_2195 = temp_r3_2194->unkC0;
    sp70.unk30 = temp_f8_2195;
    temp_f7_2197 = temp_r3_2194->unkC4;
    sp70.unk34 = temp_f7_2197;
    temp_f6_2199 = temp_r3_2194->unkC8;
    sp70.unk38 = temp_f6_2199;
    sp70.unk3C = 0.0f;
    temp_f2_2202 = temp_r3_2194->unkD0;
    sp70.unk20 = temp_f2_2202;
    temp_f4_2205 = temp_r3_2194->unkD4;
    (*(f32 *) ((u8 *) &sp70 + 0x24)) = temp_f4_2205;
    temp_f3_2208 = temp_r3_2194->unkD8;
    sp70.unk28 = temp_f3_2208;
    sp18 = (temp_f2_2202 * temp_f7_2197) - (temp_f4_2205 * temp_f8_2195);
    sp14 = (temp_f3_2208 * temp_f8_2195) - (temp_f2_2202 * temp_f6_2199);
    sp10 = (temp_f4_2205 * temp_f6_2199) - (temp_f3_2208 * temp_f7_2197);
    sp68 = (f64) sp18;
    sp60 = (f64) sp10;
    (*(f32 *) ((u8 *) &sp70 + 0x2c)) = 0.0f;
    sp70.unk10 = (f32) sp60;
    (*(f32 *) ((u8 *) &sp70 + 0x14)) = (*(f32 *) ((u8 *) &sp60 + 0x4));
    sp70.unk18 = (f32) sp68;
    (*(f32 *) ((u8 *) &sp70 + 0x1c)) = 0.0f;
    temp_r3_2194->Teleport(&sp70.unk10, (*(f32 *) ((u8 *) &sp60 + 0x4)), (f32) sp60, temp_f3_2208, temp_f4_2205, 0.0f, temp_f6_2199, temp_f7_2197, temp_f8_2195);
    temp_r3_2233 = this->unkC;
    temp_f0_2237 = (f64) M2C_FIELD(temp_r3_2233, f32 *, 0xC0) * 5.122630465e-315;
    sp30 = temp_f0_2237;
    sp40 = temp_f0_2237;
    sp38 = temp_r3_2233->unkC8 * 0.1f;
    sp48 = (f64) sp38;
    temp_f0_2249 = M2C_FIELD(this, f64 *, 0x10) + temp_f0_2237;
    sp20 = temp_f0_2249;
    sp50 = temp_f0_2249;
    sp28 = this->unk18 + (f32) sp48;
    sp58 = (f64) sp28;
    temp_r3_2233->unk8C0.Set(*((MKVector3 *) &sp50), 1U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r5_2266 = this->unkC;
    M2C_FIELD(temp_r5_2266, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r5_2266, f32 *, 0xC0);
    M2C_FIELD(temp_r5_2266, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r5_2266, f32 *, 0xC8);
    temp_r5_2266->unk6B5 |= 0x40;
    temp_r5_2276 = this->unkC;
    M2C_FIELD(temp_r5_2276, f64 *, 0xF0) = (f64) this->unk20;
    M2C_FIELD(temp_r5_2276, f64 *, 0xF8) = (f64) this->unk28;
    temp_r5_2276->unk6B5 |= 0x40;
    ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xB, 0, 2, 0.15f, 0U, 0U);
}
#endif

u8 EnemyGoal_FlyTakeoff::Update() {
    Character *temp_r3_2319;
    Character *temp_r3_2325;

    ActivateIfInactive();
    if (((MKAnimScript *) this->unkC->unk630)->CheckEvent(5) != 0) {
        temp_r3_2319 = this->unkC;
        temp_r3_2319->unk6B5 |= 0x10;
    }
    temp_r3_2325 = this->unkC;
    M2C_FIELD(temp_r3_2325, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_2325, f64 *, 0x90);
    M2C_FIELD(temp_r3_2325, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_2325, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

void EnemyGoal_FlyTakeoff::Activate() {
    Character *temp_r3_2356;
    Character *temp_r4_2365;
    Character *temp_r4_2374;

    this->unk8 = 0;
    temp_r3_2356 = this->unkC;
    temp_r3_2356->unk6B5 &= ~0x20;
    ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r4_2365 = this->unkC;
    M2C_FIELD(temp_r4_2365, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_2365, f64 *, 0xC0);
    M2C_FIELD(temp_r4_2365, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r4_2365, f64 *, 0xC8);
    temp_r4_2365->unk6B5 |= 0x40;
    temp_r4_2374 = this->unkC;
    M2C_FIELD(temp_r4_2374, f64 *, 0xF0) = (f64) M2C_FIELD(temp_r4_2374, f64 *, 0xD0);
    M2C_FIELD(temp_r4_2374, f64 *, 0xF8) = (f64) M2C_FIELD(temp_r4_2374, f64 *, 0xD8);
    temp_r4_2374->unk6B5 |= 0x40;
    if (((u8) this->unk10 >> 7U) & 1) {
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 0, 0.15f, 0U, 0U);
        return;
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xB, 0, 0, 0.15f, 0U, 0U);
}

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireTier1Goal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireTier1Goal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    if (IsPresent(0x5B) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk910'
void FireTier1Goal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Character *temp_r3_2550;
    Character *temp_r3_2557;
    Character *temp_r3_2568;
    Character *temp_r4_2563;
    Character *temp_r4_2583;
    s32 temp_r0_2521;
    s32 temp_r3_2522;
    s32 temp_r4_2498;
    s32 var_r31_2477;
    u8 temp_r3_2497;

    var_r31_2477 = arg0->unk28;
    if (IsPresent(0x5B) == 0) {
        if (IsActive(0x59) != 0) {
            temp_r3_2497 = IsActive(8);
            temp_r4_2498 = arg0->unk20;
            if (((temp_r4_2498 & 4) && ((s32) arg0->unk2C == 1)) || ((temp_r4_2498 & 8) && (var_r31_2477 == 2)) || (var_r31_2477 != 0) || (temp_r3_2497 == 0)) {
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_2521 = this->unk18;
                    temp_r3_2522 = this->unk10;
                    if (temp_r0_2521 >= temp_r3_2522) {
                        this->unk18 = temp_r0_2521 - temp_r3_2522;
                    }
                    this->unk14 -= 1;
                }
                goto block_12;
            }
        } else {
block_12:
            switch (var_r31_2477) {                 /* irregular */
            case 12:
            case 0:
                break;
            case 11:
                RemoveAllSubgoals();
                temp_r3_2550 = this->unkC;
                temp_r3_2550->unk6B5 |= 0x20;
                temp_r3_2557 = this->unkC;
                temp_r3_2557->unk6B5 &= ~0x10;
                this->unkC->SetMovementType((CharacterMoveType) 0);
                temp_r4_2563 = this->unkC;
                temp_r4_2563->unk5E4 = M2C_FIELD(temp_r4_2563->unk5D8, f32 *, 8);
                temp_r3_2568 = this->unkC;
                temp_r3_2568->unkA0 = 0.0f;
                temp_r3_2568->unkA4 = 0.0f;
                temp_r3_2568->unkA8 = 0.0f;
                break;
            default:
                var_r31_2477 = 0;
                break;
            }
            if (var_r31_2477 != 0xB) {
                ((Enemy *) this->unkC)->ThawIfFrozen();
            }
            arg0->unk28 = var_r31_2477;
            temp_r4_2583 = this->unkC;
            temp_r4_2583->unk910 = arg0->unk0;
            temp_r4_2583->unk918 = arg0->unk8;
            temp_r4_2583->unk920 = arg0->unk10;
            temp_r4_2583->unk924 = arg0->unk14;
            temp_r4_2583->unk928 = arg0->unk18;
            temp_r4_2583->unk92C = arg0->unk1C;
            temp_r4_2583->unk930 = arg0->unk20;
            temp_r4_2583->unk934 = arg0->unk24;
            temp_r4_2583->unk938 = arg0->unk28;
            temp_r4_2583->unk93C = arg0->unk2C;
            temp_r4_2583->unk940 = arg0->unk30;
            temp_r4_2583->unk944 = arg0->unk34;
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireTier1Goal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x64) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireTier1Goal_Think::AddGoal_AlertMode(AITargetData *arg0) {
    Goal<Enemy> *temp_r4_2667;

    if (IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
        temp_r4_2667 = this->unk28;
        M2C_FIELD(temp_r4_2667, AITargetData **, 0x20) = arg0;
        M2C_FIELD(temp_r4_2667, s32 *, 0x4C) = 4;
        M2C_FIELD(temp_r4_2667, u8 *, 0x50) = (u8) (M2C_FIELD(temp_r4_2667, u8 *, 0x50) | 0x80);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB09'
void FireTier1Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Character *temp_r3_2737;
    Character *temp_r3_2756;
    Character *temp_r3_2770;
    Character *temp_r3_2780;
    Character *temp_r4_2691;
    u8 temp_r4_2772;
    u8 var_r30_2757;

    temp_r4_2691 = this->unkC;
    if (!(((u8) temp_r4_2691->unkB09 >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (((Enemy *) temp_r4_2691)->WasHit() != 0) {
        sp8.Init();
        ((Enemy *) this->unkC)->TakeDamage(&sp8, 0U);
        if (this->unkC->unkAC8 <= 0.0f) {
            AddGoal_Death(&sp8);
            if (sp8.unk28 == 6) {
                AddGoal_Hit(&sp8);
            }
        } else {
            if ((sp8.unk28 != 0xE) && !(((u8) this->unk20->unkB40 >> 7U) & 1)) {
                AddGoal_Hit(&sp8);
                return;
            }
            goto block_9;
        }
    } else {
block_9:
        temp_r3_2737 = this->unkC;
        if ((temp_r3_2737->unkAC8 > 0.0f) && (M2C_FIELD(temp_r3_2737->__vptr, u8 (**)(), 0x134)() == 0) && (((Enemy *) this->unkC)->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0))) {
            if (!(((u8) this->unk20->unkB40 >> 7U) & 1)) {
                temp_r3_2756 = this->unkC;
                var_r30_2757 = 0;
                if (((u8) temp_r3_2756->unk8B8 == 2) || (((TargetContext *) &temp_r3_2756->unk8B0)->Get() != NULL)) {
                    var_r30_2757 = 1;
                }
                if (var_r30_2757 != 0) {
                    temp_r3_2770 = this->unkC;
                    temp_r4_2772 = temp_r3_2770->unk8B9;
                    if (((temp_r4_2772 >> 6U) & 1) && !((temp_r4_2772 >> 5U) & 1) && (((AITargetData *) &temp_r3_2770->unk870)->IsAttackable() != 0)) {
                        temp_r3_2780 = this->unkC;
                        if (M2C_FIELD(temp_r3_2780->__vptr, u8 (**)(Character *), 0x114)(temp_r3_2780) == 0) {
                            AddGoal_AlertMode((AITargetData *) &this->unkC->unk870);
                            return;
                        }
                    }
                }
                goto block_22;
            }
block_22:
            AddGoal_PatrolMode();
        }
    }
}
#endif

void FireTier1Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier 'temp_r3_2833'
u8 FireTier1Goal_Think::Update() {
    Character *temp_r3_2833;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_2833 = this->unkC;
    if (M2C_FIELD(temp_r3_2833->__vptr, u8 (**)(Character *), 0xE8)(temp_r3_2833) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}
#endif

void FireTier1Goal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void FireTier1Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_2891;
    Goal<Enemy> *temp_r3_2896;
    Goal<Enemy> *temp_r3_2901;
    Goal<Enemy> *temp_r3_2906;
    Goal<Enemy> *temp_r3_2911;
    MKHeap *temp_r3_2929;
    void *temp_r31_2926;

    temp_r3_2891 = this->unk24;
    temp_r3_2891->Deinit();
    temp_r3_2896 = this->unk28;
    temp_r3_2896->Deinit();
    temp_r3_2901 = this->unk2C;
    temp_r3_2901->Deinit();
    temp_r3_2906 = this->unk30;
    temp_r3_2906->Deinit();
    temp_r3_2911 = this->unk34;
    temp_r3_2911->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    temp_r31_2926 = this->unk1C;
    if (temp_r31_2926 != NULL) {
        temp_r3_2929 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2929 != NULL) {
            ((MKHeap *) (temp_r3_2929->Current()))->Free(temp_r31_2926, NULL, 0);
        } else {
            free(temp_r31_2926);
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
void FireTier1Goal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_3146;
    MKHeap *temp_r3_3107;
    void *var_r3_3114;

    this->unk20 = checked_cast<FireTier1 *, Enemy>(arg0);
    if ((u8) this->unk9 == 0) {
        operator new(0x58U, NULL, 0);
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
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_3107 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3107 != NULL) {
            var_r3_3114 = ((MKHeap *) (temp_r3_3107->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_3114 = malloc(8);
        }
        this->unk1C = var_r3_3114;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0x65;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    ((FireTier1Goal_Patrol *) this->unk24)->Init(arg0);
    ((EnemyGoal_AlertMode *) this->unk28)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk2C)->Init(arg0);
    ((EnemyGoal_Death *) this->unk30)->Init(arg0);
    temp_r4_3146 = this->unk34;
    M2C_FIELD(temp_r4_3146, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3146, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3146, s32 *, 4) = 0x1E;
    if ((Enemy *) M2C_FIELD(temp_r4_3146, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3146, s8 *, 9) = 1;
    }
}
#endif

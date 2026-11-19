#include "spyro/source/EnemyTestGoals.h"
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
#include "spyro/source/EnemyGoal_GroundAttackMode.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
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
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */
extern M2C_UNK gb;

void EnemyTestGoal_MoveToTarget::Terminate() {
    Character *temp_r3_61;
    SB2 *temp_r3_30;

    temp_r3_30 = this->unkC->unk640;
    temp_r3_30->unk464 &= ~0x80;
    this->unkC->unk640->SeekOff();
    this->unkC->unk640->PursuitOff();
    this->unkC->unk640->RandomPursuitOff();
    this->unkC->unk640->WanderOff();
    this->unkC->unk640->PathFollowingOff();
    this->unkC->unk640->ObstacleAvoidanceOff();
    this->unkC->unk640->WallAvoidanceOff();
    this->unkC->unk640->ContainmentOff();
    this->unkC->unk640->HazardAvoidanceOff();
    temp_r3_61 = this->unkC;
    temp_r3_61->unk598 = 0.0f;
    temp_r3_61->unk59C = 0.0f;
    temp_r3_61->unk5A0 = 0.0f;
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk9E8'
u8 EnemyTestGoal_MoveToTarget::Update() {
    ActivateIfInactive();
    this->unkC->unk9E8.Update();
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk18) || (this->unk10->GetDist() < this->unk14) || (this->unkC->unk640->PathFollowingHasLooped() != 0)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyTestGoal_MoveToTarget::Activate() {
    Character *temp_r3_148;
    SB2 *temp_r3_128;

    this->unk8 = 0;
    temp_r3_128 = this->unkC->unk640;
    temp_r3_128->unk464 |= 0x80;
    this->unkC->unk640->WanderOn();
    this->unkC->unk640->ObstacleAvoidanceOn(NULL);
    this->unkC->unk640->WallAvoidanceOn();
    this->unkC->unk640->ContainmentOn();
    this->unkC->unk640->HazardAvoidanceOn();
    temp_r3_148 = this->unkC;
    if (temp_r3_148->unk640->unk460 & 0x40) {
        if (M2C_FIELD(temp_r3_148->__vptr, u8 (**)(), 0x190)() != 0) {
            this->unkC->unk9E8.Set(0xFU, 0xA, 0, 0x11);
        } else {
            this->unkC->unk9E8.Set(0xBU, 0xA, 0, 0);
        }
    } else {
        temp_r3_148->unk9E8.Set(0xFU, 0xA, 0, 0);
    }
    this->unkC->unk69C = 0.0f;
    this->unkC->SetMovementType((CharacterMoveType) 0);
    if (this->unkC->unk640->unk460 & 0x40) {
        this->unk18 = M2C_FIELD(&gb, f32 *, 0x30C) + 100.0f;
        return;
    }
    this->unk18 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyTest_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    s32 temp_r0_286;
    s32 temp_r0_338;
    u8 var_r30_226;
    u8 var_r30_244;

    var_r30_226 = 0;
    if ((s32) arg0->unk28 == 6) {
        if (IsActive(0x11) == 0) {
            AddGoal_Hit(arg0);
            var_r30_226 = 1;
        }
    } else {
        var_r30_244 = 0;
        if ((IsActive(0x11) == 0) && ((IsActive(0xB) != 0) || (IsActive(0x13) != 0) || (IsActive(0xC) != 0))) {
            var_r30_244 = 1;
        }
        if (var_r30_244 != 0) {
            AddGoal_Hit(arg0);
            var_r30_226 = 1;
        } else {
            temp_r0_286 = arg0->unk28;
            if ((temp_r0_286 == 2) || (temp_r0_286 == 8) || (temp_r0_286 == 0xA)) {
                AddGoal_Hit(arg0);
                var_r30_226 = 1;
            } else {
                var_r30_226 = 0;
                if ((IsActive(0xC) != 0) || (IsActive(0xD) != 0)) {
                    var_r30_226 = 1;
                }
            }
        }
    }
    if (IsPresent(0x5B) == 0) {
        if (var_r30_226 != 0) {
loop_22:
            temp_r0_338 = this->unk14;
            if (temp_r0_338 > 1) {
                if (temp_r0_338 > 0) {
                    this->unk14 -= 1;
                }
                goto loop_22;
            }
        } else {
            RemoveAllSubgoals();
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoalToFront__21CompositeGoal'
void EnemyTest_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    f32 var_f31_372;
    s32 temp_r0_512;
    s32 temp_r0_560;
    s32 temp_r3_509;
    s32 temp_r3_533;
    s32 temp_r3_561;
    s32 temp_r4_582;
    s32 var_r26_369;
    u8 temp_r20_382;
    u8 temp_r21_389;
    u8 temp_r22_396;
    u8 temp_r23_403;
    u8 temp_r27_375;
    u8 temp_r28_410;
    u8 temp_r29_417;
    u8 temp_r30_424;
    u8 temp_r31_431;
    u8 temp_r3_437;
    void *temp_r4_487;

    var_r26_369 = arg0->unk28;
    var_f31_372 = 0.0f;
    temp_r27_375 = IsActive(8);
    temp_r20_382 = IsActive(0xB);
    temp_r21_389 = IsActive(0xE);
    temp_r22_396 = IsActive(0xC);
    temp_r23_403 = IsActive(0x13);
    temp_r28_410 = IsActive(0x12);
    temp_r29_417 = IsActive(0xD);
    temp_r30_424 = IsActive(0x26);
    temp_r31_431 = IsActive(0x3B);
    temp_r3_437 = IsActive(6);
    if ((temp_r20_382 != 0) || (temp_r23_403 != 0)) {
        switch (var_r26_369) {
        case 4:
        case 5:
        case 7:
        case 9:
        case 11:
            var_r26_369 = 9;
            break;
        case 10:
            var_f31_372 = 3000.0f;
            break;
        default:
            var_f31_372 = 500.0f;
            var_r26_369 = 3;
            break;
        }
    } else if (((temp_r22_396 != 0) || (temp_r21_389 != 0)) && (((u32) (var_r26_369 - 4) <= 1U) || (var_r26_369 == 2))) {
        var_r26_369 = 0xE;
    } else if (var_r26_369 == 9) {
        var_r26_369 = 1;
    } else if (var_r26_369 == 0xA) {
        var_r26_369 = 8;
    }
    temp_r4_487 = M2C_FIELD(this->unkC, void **, 0xA00);
    if ((((temp_r4_487 != NULL) && ((u8) M2C_FIELD(temp_r4_487, u8 *, 0x20) != 0)) || (temp_r3_437 != 0)) && ((temp_r3_437 != 0) || (arg0->unk20 & 0x47F1))) {
        RemoveAllSubgoals();
    }
    if (var_r26_369 == 9) {
        temp_r3_509 = M2C_FIELD(this->unkC, s32 *, 0xAF4);
        if ((temp_r3_509 >= 3) && (((temp_r0_512 = arg0->unk28, ((temp_r0_512 == 4) == 0)) && (temp_r0_512 != 5)) || (temp_r3_509 >= 6))) {
            var_r26_369 = 0xE;
        }
    }
    if (var_r26_369 != 0xE) {
        if (IsActive(0x59) != 0) {
            temp_r3_533 = this->unkC;
            if (!(M2C_FIELD(temp_r3_533, s32 *, 0x930) & 4) || ((s32) M2C_FIELD(temp_r3_533, s32 *, 0x93C) != 0)) {
                if ((var_r26_369 != 0) && ((var_r26_369 != 1) || (temp_r27_375 != 0)) && (temp_r28_410 == 0)) {
                    if (temp_r29_417 != 0) {
                        return;
                    }
                    goto block_38;
                }
            } else {
block_38:
                if ((s32) this->unk14 > 0) {
                    this->unk18 += 1;
                    temp_r0_560 = this->unk18;
                    temp_r3_561 = this->unk10;
                    if (temp_r0_560 >= temp_r3_561) {
                        this->unk18 = temp_r0_560 - temp_r3_561;
                    }
                    this->unk14 -= 1;
                }
                goto block_42;
            }
        } else {
block_42:
            if ((temp_r30_424 != 0) || (temp_r31_431 != 0)) {
                RemoveAllSubgoals();
            }
            arg0->unk28 = var_r26_369;
            arg0->unk18 = var_f31_372;
            temp_r4_582 = this->unkC;
            M2C_FIELD(temp_r4_582, f64 *, 0x910) = (f64) arg0->unk0;
            M2C_FIELD(temp_r4_582, f64 *, 0x918) = (f64) arg0->unk8;
            M2C_FIELD(temp_r4_582, s32 *, 0x920) = (s32) arg0->unk10;
            M2C_FIELD(temp_r4_582, s32 *, 0x924) = (s32) arg0->unk14;
            M2C_FIELD(temp_r4_582, f32 *, 0x928) = (f32) arg0->unk18;
            M2C_FIELD(temp_r4_582, f32 *, 0x92C) = (f32) arg0->unk1C;
            M2C_FIELD(temp_r4_582, s32 *, 0x930) = (s32) arg0->unk20;
            M2C_FIELD(temp_r4_582, f32 *, 0x934) = (f32) arg0->unk24;
            M2C_FIELD(temp_r4_582, s32 *, 0x938) = (s32) arg0->unk28;
            M2C_FIELD(temp_r4_582, s32 *, 0x93C) = (s32) arg0->unk2C;
            M2C_FIELD(temp_r4_582, s32 *, 0x940) = (s32) arg0->unk30;
            M2C_FIELD(temp_r4_582, u8 *, 0x944) = (u8) arg0->unk34;
            RemoveAllSubgoals();
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyTest_Think::AddGoal_Idle() {
    Goal<Enemy> *temp_r4_641;

    if (IsPresent(0) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
        temp_r4_641 = this->unk20;
        M2C_FIELD(temp_r4_641, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_641, s32 *, 0x14) = 0;
        M2C_FIELD(temp_r4_641, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r4_641, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_641, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_641, u8 *, 0x20) & ~0x40);
    }
}
#endif

void EnemyTest_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

void EnemyTest_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
u8 EnemyTest_Think::Update() {
    s32 temp_r3_704;
    s32 temp_r3_719;
    s32 temp_r3_764;
    s32 temp_r4_759;
    u8 temp_r0_783;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_704 = this->unkC;
    if (M2C_FIELD(M2C_FIELD(temp_r3_704, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_704) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_719 = this->unkC;
    if ((EAPManager *) M2C_FIELD(temp_r3_719, EAPManager **, 0xA5C) != NULL) {
        ((Enemy *) temp_r3_719)->IsFlinching();
        if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) && ((IsActive(8) != 0) || (IsActive(0xA) != 0) || (IsActive(0xF) != 0) || (IsActive(0x10) != 0))) {
            temp_r4_759 = this->unkC;
            temp_r3_764 = ((EAPManager *) (M2C_FIELD(temp_r4_759, EAPManager **, 0xA5C)))->Evaluate((Enemy *) temp_r4_759, temp_r4_759 + 0x870, NULL, 0);
            if ((temp_r3_764 != 0) && (M2C_FIELD(*temp_r3_764, s32 *, 0x38) & 0x30000)) {
                RemoveAllSubgoals();
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
                ((EnemyGoal_GroundAttackMode *) this->unk34)->SetParams(this->unkC + 0x870, 1U, (EAPItem *) temp_r3_764);
            }
        }
    }
    temp_r0_783 = (u8) this->unk8;
    if (temp_r0_783 != 0) {
        if (temp_r0_783 == 3) {
            RemoveAllSubgoals();
        }
        Activate();
    }
    return (u8) this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void EnemyTest_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Goal<Enemy> *temp_r4_971;
    s32 temp_r3_855;
    s32 temp_r3_903;
    s32 temp_r3_938;
    u8 var_r30_939;

    if ((((Enemy *) this->unkC)->WasHit() != 0) && (IsActive(0x2E) == 0) && (IsActive(0x2F) == 0) && (IsActive(0x31) == 0) && (IsActive(0x2D) == 0)) {
        sp8.Init();
        ((Enemy *) this->unkC)->TakeDamage(&sp8, 0U);
        temp_r3_855 = this->unkC;
        M2C_FIELD(temp_r3_855, u8 *, 0xB0A) = (u8) (M2C_FIELD(temp_r3_855, u8 *, 0xB0A) & ~1);
        if ((M2C_FIELD(this->unkC, f32 *, 0xAC8) <= 0.0f) && (IsPresent(0x29) == 0)) {
            AddGoal_Death(&sp8);
            return;
        }
        if ((sp8.unk28 != 0xE) && (IsPresent(0x29) == 0) && (IsPresent(0x30) == 0)) {
            AddGoal_Hit(&sp8);
            return;
        }
        goto block_12;
    }
block_12:
    temp_r3_903 = this->unkC;
    if ((M2C_FIELD(temp_r3_903, f32 *, 0xAC8) > 0.0f) && (M2C_FIELD(M2C_FIELD(temp_r3_903, void **, 0x44), u8 (**)(), 0x134)() == 0) && (((Enemy *) this->unkC)->IsBlocking() == 0) && (((Enemy *) this->unkC)->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (IsPresent(0x26) == 0) && (IsPresent(0x28) == 0)) {
        temp_r3_938 = this->unkC;
        var_r30_939 = 0;
        if (((u8) M2C_FIELD(temp_r3_938, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_938 + 0x8B0))->Get() != NULL)) {
            var_r30_939 = 1;
        }
        if (var_r30_939 != 0) {
            if (IsPresent(0x58) == 0) {
                RemoveAllSubgoals();
                if (!(((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 6U) & 1)) {
                    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
                    temp_r4_971 = this->unk30;
                    M2C_FIELD(temp_r4_971, s32 *, 0x10) = (s32) (this->unkC + 0x870);
                    M2C_FIELD(temp_r4_971, s32 *, 0x14) = 0;
                    M2C_FIELD(temp_r4_971, f32 *, 0x18) = 0.0f;
                }
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
                ((EnemyGoal_GroundAttackMode *) this->unk34)->SetParams(this->unkC + 0x870, 1U, NULL);
            }
        } else {
            AddGoal_Idle();
        }
    }
}
#endif

void EnemyTest_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void EnemyTest_Think::Deinit() {
    Goal<Enemy> *temp_r3_1025;
    Goal<Enemy> *temp_r3_1030;
    Goal<Enemy> *temp_r3_1035;
    Goal<Enemy> *temp_r3_1045;
    Goal<Enemy> *temp_r3_1050;
    MKHeap *temp_r3_1070;
    s32 temp_r31_1067;
    void **temp_r3_1040;

    temp_r3_1025 = this->unk20;
    temp_r3_1025->Deinit();
    temp_r3_1030 = this->unk24;
    temp_r3_1030->Deinit();
    temp_r3_1035 = this->unk28;
    temp_r3_1035->Deinit();
    temp_r3_1040 = this->unk2C;
    M2C_FIELD(*temp_r3_1040, M2C_UNK (**)(void **), 0xC)(temp_r3_1040);
    temp_r3_1045 = this->unk30;
    temp_r3_1045->Deinit();
    temp_r3_1050 = this->unk34;
    temp_r3_1050->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    temp_r31_1067 = this->unk1C;
    if ((u32) temp_r31_1067 != 0U) {
        temp_r3_1070 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1070 != NULL) {
            ((MKHeap *) (temp_r3_1070->Current()))->Free((void *) temp_r31_1067, NULL, 0);
        } else {
            free(temp_r31_1067);
        }
        this->unk1C = 0;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = 0;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void EnemyTest_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1285;
    Goal<Enemy> *temp_r4_1313;
    MKHeap *temp_r3_1258;
    void **temp_r4_1302;
    void *var_r3_1265;

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
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
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
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x70U, NULL, 0);
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
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1258 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1258 != NULL) {
            var_r3_1265 = ((MKHeap *) (temp_r3_1258->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_1265 = malloc(0xC);
        }
        this->unk1C = (s32) var_r3_1265;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x5C;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_1285 = this->unk20;
    M2C_FIELD(temp_r4_1285, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1285, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1285, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_1285, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1285, s8 *, 9) = 1;
    }
    ((EnemyGoal_Hit *) this->unk24)->Init(arg0);
    ((EnemyGoal_Death *) this->unk28)->Init(arg0);
    temp_r4_1302 = this->unk2C;
    M2C_FIELD(temp_r4_1302, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1302, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1302, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r4_1302, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1302, s8 *, 9) = 1;
    }
    temp_r4_1313 = this->unk30;
    M2C_FIELD(temp_r4_1313, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1313, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1313, s32 *, 4) = 2;
    if ((Enemy *) M2C_FIELD(temp_r4_1313, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1313, s8 *, 9) = 1;
    }
    ((EnemyGoal_GroundAttackMode *) this->unk34)->Init(arg0);
}
#endif

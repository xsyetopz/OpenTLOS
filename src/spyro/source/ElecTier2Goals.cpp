#include "spyro/source/ElecTier2Goals.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Enemies_Elec.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void ElecTier2Goal_FlyToTarget::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
u8 ElecTier2Goal_FlyToTarget::Update() {
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Character *temp_r3_150;
    Character *temp_r3_29;
    f32 temp_f4_129;
    f32 var_f30_139;
    f32 var_f31_52;
    f32 var_f5_119;
    f64 temp_f1_58;
    f64 temp_f1_64;
    f64 temp_f1_68;
    s32 temp_r3_87;
    s32 var_r0_97;
    u8 var_r3_168;
    u8 var_r4_162;
    void *temp_r5_163;

    ActivateIfInactive();
    temp_r3_29 = this->unkC;
    sp20 = this->unk18 - M2C_FIELD(temp_r3_29, f64 *, 0x588);
    sp40 = sp20;
    sp28 = this->unk20 - temp_r3_29->unk588.unk4;
    sp48 = (f64) sp28;
    var_f31_52 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + ((*(f32 *) ((u8 *) &sp38 + 0xc)) * (*(f32 *) ((u8 *) &sp38 + 0xc))));
    if (var_f31_52 > 0.000001f) {
        if (var_f31_52 > 0.0f) {
            temp_f1_58 = __frsqrte(var_f31_52);
            temp_f1_64 = 0.5 * temp_f1_58 * -(((f64) var_f31_52 * (temp_f1_58 * temp_f1_58)) - 3.0);
            temp_f1_68 = 0.5 * temp_f1_64 * -(((f64) var_f31_52 * (temp_f1_64 * temp_f1_64)) - 3.0);
            var_f31_52 = (f32) ((f64) var_f31_52 * (0.5 * temp_f1_68 * -(((f64) var_f31_52 * (temp_f1_68 * temp_f1_68)) - 3.0)));
        } else if (var_f31_52 < M2C_BITWISE(f32, 0.0)) {
            var_f31_52 = __float_nan;
        } else {
            sp8 = var_f31_52;
            temp_r3_87 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_87) {                   /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_97 = 1;
                } else {
                    var_r0_97 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_97 = 5;
                } else {
                    var_r0_97 = 3;
                }
                break;
            default:
                var_r0_97 = 4;
                break;
            }
            if (var_r0_97 == 1) {
                var_f31_52 = __float_nan;
            }
        }
        var_f5_119 = 1.0f / var_f31_52;
    } else {
        var_f5_119 = 0.0f;
        var_f31_52 = 0.0f;
    }
    temp_f4_129 = 500.0f * gUpdateTimeDelta;
    sp40 = (f32) sp40 * var_f5_119;
    (*(f32 *) ((u8 *) &sp38 + 0xc)) *= var_f5_119;
    sp48 = (f32) sp48 * var_f5_119;
    if (var_f31_52 < temp_f4_129) {
        var_f30_139 = var_f31_52;
    } else {
        var_f30_139 = temp_f4_129;
    }
    sp10 = (f64) sp40 * (f64) var_f30_139;
    temp_r3_150 = this->unkC;
    sp30 = sp10;
    sp18 = sp48 * var_f30_139;
    M2C_FIELD(temp_r3_150, f64 *, 0x598) = sp10;
    M2C_FIELD(temp_r3_150, f64 *, 0x5A0) = (f64) sp18;
    sp38 = (f64) sp18;
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_162 = 0;
        temp_r5_163 = M2C_FIELD(this->unkC, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r5_163, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_168 = 0;
            if ((M2C_FIELD(temp_r5_163, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_163, s32 *, 0x44) > 1)) {
                var_r3_168 = 1;
            }
            if (var_r3_168 != 0) {
                var_r4_162 = 1;
            }
        }
        if (var_r4_162 != 0) {
            goto block_31;
        }
    } else {
block_31:
        if (var_f31_52 < 10.0f) {
            this->unk8 = 2;
        } else {
            ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
        }
    }
    return this->unk8;
}
#endif

void ElecTier2Goal_FlyToTarget::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(1U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier2Goal_Attack::Terminate() {
    AttackerManager *var_r3_286;
    Enemy *temp_r3_261;
    Enemy *temp_r3_267;
    Enemy *var_r4_293;
    u8 var_r31_260;

    var_r31_260 = 0;
    temp_r3_261 = this->unkC;
    M2C_FIELD(temp_r3_261, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_261, u8 *, 0xB08) & ~0x10);
    this->unkC->unkA08 = NULL;
    temp_r3_267 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_267, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r3_267->unk870.unk30)->Get() != NULL)) {
        var_r31_260 = 1;
    }
    if (var_r31_260 != 0) {
        var_r3_286 = M2C_FIELD(((TargetContext *) &this->unkC->unk870.unk30)->Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_286 = NULL;
    }
    if (var_r3_286 != NULL) {
        var_r4_293 = this->unkC;
        if (var_r4_293 != NULL) {
            var_r4_293 += 0x6B8;
        }
        var_r3_286->Remove((Targetable *) var_r4_293, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

u8 ElecTier2Goal_Attack::Update() {
    CharacterFireFX *temp_r4_333;
    Enemy *temp_r3_327;
    Enemy *temp_r3_332;

    ActivateIfInactive();
    temp_r3_327 = this->unkC;
    M2C_FIELD(temp_r3_327, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_327, f64 *, 0x90);
    M2C_FIELD(temp_r3_327, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_327, f64 *, 0x98);
    temp_r3_332 = this->unkC;
    temp_r4_333 = temp_r3_332->unkA08;
    if ((temp_r4_333 != NULL) && ((s32) M2C_FIELD(temp_r4_333, s32 *, 0x78) > 0) && (((u8) M2C_FIELD(temp_r3_332, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_332->CheckMeleeHit((EnemyAttack *) temp_r4_333, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier2Goal_Attack::Activate() {
    AttackerManager *var_r3_451;
    Enemy *temp_r3_378;
    Enemy *temp_r3_407;
    Enemy *temp_r3_431;
    Enemy *temp_r4_414;
    Enemy *var_r4_458;
    MKMaterial *temp_r3_426;
    u8 var_r30_379;
    u8 var_r30_432;
    void *temp_r4_411;

    this->unk8 = 0;
    ((Character *) this->unkC)->StopMovement(1U);
    temp_r3_378 = this->unkC;
    var_r30_379 = 0;
    if (((u8) M2C_FIELD(temp_r3_378, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r3_378->unk870.unk30)->Get() != NULL)) {
        var_r30_379 = 1;
    }
    if ((var_r30_379 == 0) || (this->unkC->SelectAttack(((AITargetData *) &this->unkC->unk838.unk28)->GetDist(), 4U, 0U, 0U) == 0)) {
        this->unk8 = 2;
    } else {
        temp_r3_407 = this->unkC;
        temp_r4_411 = temp_r3_407->unkA08->__vptr;
        temp_r3_407->SetAnim((AnimSequence *) temp_r4_411, (AnimTransition *) temp_r4_411, 0.15f, 0U);
        temp_r4_414 = this->unkC;
loop_8:
        if ((void *) temp_r4_414->unkA04->__vptr != NULL) {
            temp_r4_414->unkA04 = (CharacterZapFX *) &temp_r4_414->unkA04->unk4;
            goto loop_8;
        }
        temp_r3_426 = this->unkC->unkA18;
        if (temp_r3_426 != NULL) {
            ((AttackSweepData *) temp_r3_426)->SetDefaults();
        }
        temp_r3_431 = this->unkC;
        var_r30_432 = 0;
        if (((u8) M2C_FIELD(temp_r3_431, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r3_431->unk870.unk30)->Get() != NULL)) {
            var_r30_432 = 1;
        }
        if (var_r30_432 != 0) {
            var_r3_451 = M2C_FIELD(((TargetContext *) &this->unkC->unk870.unk30)->Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_451 = NULL;
        }
        if (var_r3_451 != NULL) {
            var_r4_458 = this->unkC;
            if (var_r4_458 != NULL) {
                var_r4_458 += 0x6B8;
            }
            var_r3_451->Add((Targetable *) var_r4_458, 2);
        }
    }
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 2);
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r3_485'
u8 ElecTier2Goal_Land::Update() {
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Character *temp_r3_485;
    Character *temp_r3_519;
    f64 temp_f3_524;
    f64 temp_f4_523;
    void *temp_r5_522;

    ActivateIfInactive();
    temp_r3_485 = this->unkC;
    M2C_FIELD(temp_r3_485, f64 *, 0x598) = (f64) (M2C_FIELD(temp_r3_485, f64 *, 0x598) + M2C_FIELD(temp_r3_485, f64 *, 0x90));
    temp_r3_485->unk59C += temp_r3_485->unk98;
    if (this->unkC->HasAnimFinished() != 0) {
        M2C_FIELD(this->unk10, s8 *, 0xB11) = 1;
        ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(0U, 1U);
        ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
        MKModel_CalculateRefPointWorldPosition(M2C_FIELD(this->unk10, MKModel **, 4), M2C_FIELD(checked_cast<ElecTier2Descriptor *, MKPropDescriptor>(M2C_FIELD(this->unk10, MKPropDescriptor **, 0)), s32 *, 0x2BC), &sp28);
        temp_r3_519 = this->unkC;
        temp_r5_522 = temp_r3_519->unk8;
        temp_f4_523 = M2C_FIELD(temp_r5_522, f64 *, 0x30);
        temp_f3_524 = M2C_FIELD(temp_r5_522, f64 *, 0x38);
        sp18 = temp_f4_523;
        sp10 = temp_f3_524;
        sp20 = temp_f3_524;
        sp28 = (f32) sp18;
        sp8 = temp_f4_523;
        sp28.unk8 = (f32) sp10;
        ((Enemy *) temp_r3_519)->SetupEnemyRegion(sp28, 1500.0f);
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void ElecTier2Goal_Land::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0xDD, 0, 0.15f, 0U, 0U);
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(1U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}

#if 0 // DRAFT: undefined identifier 'temp_r3_593'
u8 ElecTier2Goal_TakeOff::Update() {
    Character *temp_r3_593;

    ActivateIfInactive();
    temp_r3_593 = this->unkC;
    M2C_FIELD(temp_r3_593, f64 *, 0x598) = (f64) (M2C_FIELD(temp_r3_593, f64 *, 0x598) + M2C_FIELD(temp_r3_593, f64 *, 0x90));
    temp_r3_593->unk59C += temp_r3_593->unk98;
    if (this->unkC->HasAnimFinished() != 0) {
        M2C_FIELD(this->unk10, s8 *, 0xB11) = 0;
        ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(0U, 1U);
        ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void ElecTier2Goal_TakeOff::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0xDC, 0, 0.15f, 0U, 0U);
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(1U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}

#if 0 // DRAFT: undefined identifier 'temp_r3_678'
u8 ElecTier2Goal_FlyIdle::Update() {
    Character *temp_r3_678;
    u8 var_r3_694;
    u8 var_r4_688;
    void *temp_r5_689;

    ActivateIfInactive();
    temp_r3_678 = this->unkC;
    M2C_FIELD(temp_r3_678, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_678, f64 *, 0x90);
    M2C_FIELD(temp_r3_678, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_678, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_688 = 0;
        temp_r5_689 = M2C_FIELD(this->unkC, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r5_689, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_694 = 0;
            if ((M2C_FIELD(temp_r5_689, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_689, s32 *, 0x44) > 1)) {
                var_r3_694 = 1;
            }
            if (var_r3_694 != 0) {
                var_r4_688 = 1;
            }
        }
        if (var_r4_688 != 0) {
            goto block_8;
        }
    } else {
block_8:
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAEC'
void ElecTier2Goal_FlyIdle::Activate() {
    this->unk8 = 0;
    this->unkC->unkAEC = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}
#endif

void ElecTier2Goal_Idle::Reset() {
    this->unk8 = 1;
    this->unk14 = 0;
    this->unk18 = 1;
}

#if 0 // DRAFT: undefined identifier 'temp_r3_775'
u8 ElecTier2Goal_Idle::Update() {
    Character *temp_r3_775;
    u8 var_r3_791;
    u8 var_r4_785;
    void *temp_r5_786;

    ActivateIfInactive();
    temp_r3_775 = this->unkC;
    M2C_FIELD(temp_r3_775, f64 *, 0x598) = (f64) M2C_FIELD(temp_r3_775, f64 *, 0x90);
    M2C_FIELD(temp_r3_775, f64 *, 0x5A0) = (f64) M2C_FIELD(temp_r3_775, f64 *, 0x98);
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_785 = 0;
        temp_r5_786 = M2C_FIELD(this->unkC, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r5_786, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_791 = 0;
            if ((M2C_FIELD(temp_r5_786, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_786, s32 *, 0x44) > 1)) {
                var_r3_791 = 1;
            }
            if (var_r3_791 != 0) {
                var_r4_785 = 1;
            }
        }
        if (var_r4_785 != 0) {
            goto block_8;
        }
    } else {
block_8:
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAEC'
void ElecTier2Goal_Idle::Activate() {
    this->unk8 = 0;
    this->unkC->unkAEC = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, this->unk18, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
}
#endif

void ElecTier2Goal_PatrolMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 ElecTier2Goal_PatrolMode::Update() {
    MKVector3 sp8;
    ElecTier2 *temp_r3_903;
    ElecTier2 *temp_r4_889;
    s32 temp_r3_890;
    void **temp_r3_882;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        temp_r3_882 = this->unk30;
        if (M2C_FIELD(*temp_r3_882, u8 (**)(void **), 0x24)(temp_r3_882) != 0) {
            temp_r4_889 = this->unk20;
            temp_r3_890 = temp_r4_889->unkAFC;
            temp_r4_889->unkAFC = temp_r3_890 + 1;
            this->unk20->unkAFC = (temp_r3_890 + 1) % M2C_FIELD(M2C_FIELD(this->unkC->unkA2C, void **, 0x18), s32 *, 0x20);
        }
        temp_r3_903 = this->unk20;
        if (M2C_BITWISE(f32, temp_r3_903->unkB04) <= 0.0f) {
            if (temp_r3_903->FindLandingPos(&sp8) != 0) {
                M2C_FIELD(this->unk20, s8 *, 0xB12) = 1;
            } else {
                Activate();
            }
        } else {
            Activate();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void ElecTier2Goal_PatrolMode::Activate() {
    f32 sp18;
    M2C_UNK sp8;
    Enemy *temp_r30_984;
    Enemy *temp_r3_950;
    Enemy *temp_r4_963;
    f32 temp_f2_997;
    f32 temp_f3_995;
    u8 var_r30_972;
    void **temp_r4_1032;
    void *temp_r3_1036;
    void *temp_r5_1031;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_950 = this->unkC;
    M2C_FIELD(temp_r3_950, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_950, u8 *, 0xB08) & ~0x40);
    if ((u8) M2C_FIELD(this->unk20, u8 *, 0xB11) != 0) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    }
    temp_r4_963 = this->unkC;
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_963->unkA7C) {
        var_r30_972 = 0;
        if (((u8) M2C_FIELD(temp_r4_963, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r4_963->unk870.unk30)->Get() != NULL)) {
            var_r30_972 = 1;
        }
        if (var_r30_972 != 0) {
            temp_r30_984 = this->unkC;
            if (((u8) M2C_FIELD(temp_r30_984, u8 *, 0x8B9) >> 6U) & 1) {
                ((AITargetData *) &sp18)->GetPos();
                temp_f3_995 = sp20 - temp_r30_984->unk588.unk4;
                temp_f2_997 = sp18 - temp_r30_984->unk588;
                if (((temp_f2_997 * temp_f2_997) + (temp_f3_995 * temp_f3_995)) < 250000.0f) {
                    ((AITargetData *) &sp8)->GetPos();
                    if (this->unkC->unk588.unk0 > spC) {
                        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
                    }
                }
                goto block_13;
            }
        }
        goto block_11;
    }
block_11:
    if (this->unkC->HasWaypoints() != 0) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
        temp_r5_1031 = M2C_FIELD(this->unkC->unkA2C, void **, 0x18);
        temp_r4_1032 = this->unk30;
        temp_r3_1036 = M2C_FIELD(temp_r5_1031, s32 *, 0x24) + (this->unk20->unkAFC * M2C_FIELD(temp_r5_1031, s32 *, 0x1C));
        M2C_FIELD(temp_r4_1032, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_1036, f64 *, 0);
        M2C_FIELD(temp_r4_1032, f64 *, 0x20) = (f64) M2C_FIELD(temp_r3_1036, f64 *, 8);
        return;
    }
block_13:
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
}
#endif

void ElecTier2Goal_PatrolMode::Deinit() {
    Goal<Enemy> *temp_r3_1062;
    Goal<Enemy> *temp_r3_1067;
    Goal<Enemy> *temp_r3_1072;
    MKHeap *temp_r3_1093;
    void **temp_r3_1077;
    void *temp_r31_1090;

    temp_r3_1062 = this->unk28;
    temp_r3_1062->Deinit();
    temp_r3_1067 = this->unk24;
    temp_r3_1067->Deinit();
    temp_r3_1072 = this->unk2C;
    temp_r3_1072->Deinit();
    temp_r3_1077 = this->unk30;
    M2C_FIELD(*temp_r3_1077, M2C_UNK (**)(void **), 0xC)(temp_r3_1077);
    operator delete(this->unk28);
    operator delete(this->unk24);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_1090 = this->unk1C;
    if (temp_r31_1090 != NULL) {
        temp_r3_1093 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1093 != NULL) {
            ((MKHeap *) (temp_r3_1093->Current()))->Free(temp_r31_1090, NULL, 0);
        } else {
            free(temp_r31_1090);
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
void ElecTier2Goal_PatrolMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1248;
    Goal<Enemy> *temp_r4_1262;
    Goal<Enemy> *temp_r4_1274;
    MKHeap *temp_r3_1221;
    void **temp_r4_1286;
    void *var_r3_1228;

    this->unk20 = (ElecTier2 *) arg0;
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
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
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
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_1221 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1221 != NULL) {
            var_r3_1228 = ((MKHeap *) (temp_r3_1221->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_1228 = malloc(0xC);
        }
        this->unk1C = var_r3_1228;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x53;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1248 = this->unk28;
    M2C_FIELD(temp_r4_1248, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1248, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1248, s32 *, 4) = 0x43;
    if ((Enemy *) M2C_FIELD(temp_r4_1248, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1248, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1248, Enemy **, 0x10) = arg0;
    temp_r4_1262 = this->unk24;
    M2C_FIELD(temp_r4_1262, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1262, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1262, s32 *, 4) = 0x41;
    if ((Enemy *) M2C_FIELD(temp_r4_1262, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1262, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1262, Enemy **, 0x10) = arg0;
    temp_r4_1274 = this->unk2C;
    M2C_FIELD(temp_r4_1274, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1274, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1274, s32 *, 4) = 0x3C;
    if ((Enemy *) M2C_FIELD(temp_r4_1274, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1274, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1274, Enemy **, 0x10) = arg0;
    temp_r4_1286 = this->unk30;
    M2C_FIELD(temp_r4_1286, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1286, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1286, s32 *, 4) = 0x44;
    if ((Enemy *) M2C_FIELD(temp_r4_1286, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1286, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1286, Enemy **, 0x10) = arg0;
}
#endif

void ElecTier2Goal_GroundMode::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 ElecTier2Goal_GroundMode::Update() {
    ElecTier2 *temp_r3_1333;

    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        temp_r3_1333 = this->unk20;
        if (M2C_FIELD(temp_r3_1333, f32 *, 0xB18) <= 0.0f) {
            M2C_FIELD(temp_r3_1333, s8 *, 0xB12) = 0;
        } else {
            Activate();
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void ElecTier2Goal_GroundMode::Activate() {
    MKVector3 sp8;
    ElecTier2 *temp_r3_1373;
    Enemy *temp_r3_1368;
    Goal<Enemy> *temp_r3_1385;
    Goal<Enemy> *temp_r4_1394;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_1368 = this->unkC;
    M2C_FIELD(temp_r3_1368, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_1368, u8 *, 0xB08) & ~0x40);
    temp_r3_1373 = this->unk20;
    if ((u8) M2C_FIELD(temp_r3_1373, u8 *, 0xB11) == 0) {
        temp_r3_1373->FindLandingPos(&sp8);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
        temp_r3_1385 = this->unk2C;
        M2C_FIELD(temp_r3_1385, f64 *, 0x18) = M2C_BITWISE(f64, sp8);
        M2C_FIELD(temp_r3_1385, f64 *, 0x20) = (f64) sp8.unk8;
    }
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    temp_r4_1394 = this->unk24;
    M2C_FIELD(temp_r4_1394, s32 *, 0x14) = 0;
    M2C_FIELD(temp_r4_1394, s32 *, 0x18) = 1;
}
#endif

void ElecTier2Goal_GroundMode::Deinit() {
    Goal<Enemy> *temp_r3_1414;
    Goal<Enemy> *temp_r3_1419;
    Goal<Enemy> *temp_r3_1424;
    MKHeap *temp_r3_1438;
    void *temp_r31_1435;

    temp_r3_1414 = this->unk24;
    temp_r3_1414->Deinit();
    temp_r3_1419 = this->unk28;
    temp_r3_1419->Deinit();
    temp_r3_1424 = this->unk2C;
    temp_r3_1424->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_1435 = this->unk1C;
    if (temp_r31_1435 != NULL) {
        temp_r3_1438 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1438 != NULL) {
            ((MKHeap *) (temp_r3_1438->Current()))->Free(temp_r31_1435, NULL, 0);
        } else {
            free(temp_r31_1435);
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
void ElecTier2Goal_GroundMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1573;
    Goal<Enemy> *temp_r4_1587;
    Goal<Enemy> *temp_r4_1599;
    MKHeap *temp_r3_1546;
    void *var_r3_1553;

    this->unk20 = (ElecTier2 *) arg0;
    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
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
        operator new(0x28U, NULL, 0);
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
        temp_r3_1546 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1546 != NULL) {
            var_r3_1553 = ((MKHeap *) (temp_r3_1546->Current()))->Alloc(0xC, NULL, 0);
        } else {
            var_r3_1553 = malloc(0xC);
        }
        this->unk1C = var_r3_1553;
        this->unk10 = 3;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0xCB;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1573 = this->unk24;
    M2C_FIELD(temp_r4_1573, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1573, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1573, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_1573, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1573, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1573, Enemy **, 0x10) = arg0;
    temp_r4_1587 = this->unk28;
    M2C_FIELD(temp_r4_1587, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1587, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1587, s32 *, 4) = 0x42;
    if ((Enemy *) M2C_FIELD(temp_r4_1587, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1587, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1587, Enemy **, 0x10) = arg0;
    temp_r4_1599 = this->unk2C;
    M2C_FIELD(temp_r4_1599, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1599, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1599, s32 *, 4) = 0x44;
    if ((Enemy *) M2C_FIELD(temp_r4_1599, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1599, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1599, Enemy **, 0x10) = arg0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ElecTier2Goal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
    }
}
#endif

void ElecTier2Goal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {

}

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ElecTier2Goal_Think::AddGoal_PatrolMode() {
    if (IsPresent(0x53) == 0) {
        this->unk20->unkB04 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void ElecTier2Goal_Think::AddGoal_GroundMode() {
    if (IsPresent(0xCB) == 0) {
        M2C_FIELD(this->unk20, f32 *, 0xB18) = MKRand_Float(&gViewSeed, 7.0f, 10.0f);
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    }
}
#endif

void ElecTier2Goal_Think::Reset() {
    Enemy *temp_r3_1729;

    this->unk8 = 1;
    RemoveAllSubgoals();
    temp_r3_1729 = this->unk20;
    M2C_FIELD(temp_r3_1729, u8 *, 0xB12) = (u8) M2C_FIELD(temp_r3_1729, u8 *, 0xB10);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElecTier2Goal_Think::Arbitrate() {
    EnemyDamageFeedback sp8;
    Enemy *temp_r3_1788;
    Enemy *temp_r4_1747;
    s32 temp_cr0_eq_1813;

    temp_r4_1747 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r4_1747, u8 *, 0xB09) >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (temp_r4_1747->WasHit() != 0) {
        sp8.Init();
        this->unkC->TakeDamage(&sp8, 0U);
        if ((sp8.unk28 == 4) || (sp8.unk28 == 5) || (sp8.unk28 == 2) || (sp8.unk28 == 3)) {
            sp8.unk28 = 0xE;
        }
        if (this->unkC->unkAB0 <= 0.0f) {
            AddGoal_Death(&sp8);
            return;
        }
        goto block_10;
    }
block_10:
    temp_r3_1788 = this->unkC;
    if ((temp_r3_1788->unkAB0 > 0.0f) && (M2C_FIELD(temp_r3_1788->__vptr, u8 (**)(), 0x134)() == 0) && (this->unkC->IsFlinching(), (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (IsPresent(0x28) == 0)) {
        temp_cr0_eq_1813 = (u8) M2C_FIELD(this->unk20, u8 *, 0xB12) == 0;
        if (temp_cr0_eq_1813 == 0) {
            AddGoal_GroundMode();
            return;
        }
        if (temp_cr0_eq_1813 != 0) {
            AddGoal_PatrolMode();
        }
    }
}
#endif

void ElecTier2Goal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 ElecTier2Goal_Think::Update() {
    Enemy *temp_r3_1860;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r3_1860 = this->unkC;
    if (temp_r3_1860->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    return this->unk8;
}
#endif

void ElecTier2Goal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void ElecTier2Goal_Think::Deinit() {
    Goal<Enemy> *temp_r3_1918;
    Goal<Enemy> *temp_r3_1923;
    Goal<Enemy> *temp_r3_1933;
    MKHeap *temp_r3_1949;
    void **temp_r3_1928;
    void *temp_r31_1946;

    temp_r3_1918 = this->unk24;
    temp_r3_1918->Deinit();
    temp_r3_1923 = this->unk28;
    temp_r3_1923->Deinit();
    temp_r3_1928 = this->unk2C;
    M2C_FIELD(*temp_r3_1928, M2C_UNK (**)(void **), 0xC)(temp_r3_1928);
    temp_r3_1933 = this->unk34;
    temp_r3_1933->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk34);
    temp_r31_1946 = this->unk1C;
    if (temp_r31_1946 != NULL) {
        temp_r3_1949 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1949 != NULL) {
            ((MKHeap *) (temp_r3_1949->Current()))->Free(temp_r31_1946, NULL, 0);
        } else {
            free(temp_r31_1946);
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
void ElecTier2Goal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_2134;
    MKHeap *temp_r3_2098;
    void *var_r3_2105;

    this->unk20 = arg0;
    if ((u8) this->unk9 == 0) {
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
        operator new(0x34U, NULL, 0);
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
        temp_r3_2098 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2098 != NULL) {
            var_r3_2105 = ((MKHeap *) (temp_r3_2098->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_2105 = malloc(8);
        }
        this->unk1C = var_r3_2105;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x5C;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    ((ElecTier2Goal_GroundMode *) this->unk24)->Init(arg0);
    ((ElecTier2Goal_PatrolMode *) this->unk28)->Init(arg0);
    ((EnemyGoal_Hit *) this->unk2C)->Init(arg0);
    temp_r4_2134 = this->unk34;
    M2C_FIELD(temp_r4_2134, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2134, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2134, s32 *, 4) = 0x1E;
    if ((Enemy *) M2C_FIELD(temp_r4_2134, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2134, s8 *, 9) = 1;
    }
}
#endif

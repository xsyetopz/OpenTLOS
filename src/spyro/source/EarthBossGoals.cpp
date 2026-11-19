#include "spyro/source/EarthBossGoals.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Enemies_EarthBoss.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_SSFlinch;
extern s32 gViewSeed;
extern M2C_UNK gb;

void EarthBossGoal_MoveToTarget::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
u8 EarthBossGoal_MoveToTarget::Update() {
    AITargetData sp50;
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    M2C_UNK sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Enemy *temp_r3_141;
    Enemy *temp_r3_237;
    Enemy *temp_r3_38;
    Enemy *temp_r4_135;
    Enemy *temp_r4_158;
    f32 temp_f0_112;
    f32 temp_f1_41;
    f32 temp_f2_40;
    f32 temp_f31_199;
    f32 temp_f3_43;
    f32 var_f1_111;
    f32 var_f1_121;
    f32 var_f4_47;
    f64 temp_f1_50;
    f64 temp_f1_56;
    f64 temp_f1_60;
    s32 temp_r3_79;
    s32 var_r0_89;
    u8 var_r30_136;
    u8 var_r30_238;

    ActivateIfInactive();
    temp_r3_38 = this->unkC;
    temp_f2_40 = temp_r3_38->unk80;
    temp_f1_41 = temp_r3_38->unk84;
    temp_f3_43 = temp_r3_38->unk88;
    var_f4_47 = (temp_f3_43 * temp_f3_43) + ((temp_f2_40 * temp_f2_40) + (temp_f1_41 * temp_f1_41));
    if (var_f4_47 > 0.0f) {
        temp_f1_50 = __frsqrte(var_f4_47);
        temp_f1_56 = 0.5 * temp_f1_50 * -(((f64) var_f4_47 * (temp_f1_50 * temp_f1_50)) - 3.0);
        temp_f1_60 = 0.5 * temp_f1_56 * -(((f64) var_f4_47 * (temp_f1_56 * temp_f1_56)) - 3.0);
        var_f4_47 = (f32) ((f64) var_f4_47 * (0.5 * temp_f1_60 * -(((f64) var_f4_47 * (temp_f1_60 * temp_f1_60)) - 3.0)));
    } else if (var_f4_47 < M2C_BITWISE(f32, 0.0)) {
        var_f4_47 = __float_nan;
    } else {
        sp8 = var_f4_47;
        temp_r3_79 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_79) {                       /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_89 = 1;
            } else {
                var_r0_89 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_89 = 5;
            } else {
                var_r0_89 = 3;
            }
            break;
        default:
            var_r0_89 = 4;
            break;
        }
        if (var_r0_89 == 1) {
            var_f4_47 = __float_nan;
        }
    }
    var_f1_111 = 0.0f;
    temp_f0_112 = var_f4_47 - 5.0f;
    if (var_f1_111 > temp_f0_112) {

    } else {
        var_f1_111 = temp_f0_112;
    }
    var_f1_121 = var_f1_111 / 5.0f;
    if (var_f1_121 < 1.0f) {

    } else {
        var_f1_121 = 1.0f;
    }
    if (var_f1_121 > 0.0f) {

    } else {
        var_f1_121 = 0.0f;
    }
    temp_r4_135 = this->unkC;
    var_r30_136 = 0;
    temp_r4_135->unk684 = var_f1_121 * M2C_FIELD(temp_r4_135->unkA20, f32 *, 0x158);
    temp_r3_141 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_141, u8 *, 0x8B8) == 2) || (temp_r3_141->unk870.unk30.Get() != NULL)) {
        var_r30_136 = 1;
    }
    if (var_r30_136 != 0) {
        sp50.GetDir();
        temp_r4_158 = this->unkC;
        M2C_FIELD(temp_r4_158, f64 *, 0xE0) = M2C_BITWISE(f64, sp50);
        M2C_FIELD(temp_r4_158, f64 *, 0xE8) = (f64) sp50.unk8;
        temp_r4_158->unk6B5 |= 0x40;
    }
    if ((((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(9) != 0) || (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0xA) != 0)) {
        temp_f31_199 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.05f, 0.4f, 0.2f, this->unkC->unk8 + 0x30, 80.0f, 0, 4.0f, 0U);
        unksp64 = 0;
        MKVector(0.05f, 0.8f, 0.05f);
        sp30.operator*(500.0f);
        sp10 = sp30 * (f64) temp_f31_199;
        sp50.unk10 = 0x417;
        sp18 = sp30.unk8 * temp_f31_199;
        sp50.unk18 = sp10;
        sp50.unk20 = (f64) sp18;
        sp50.unk28 = 1;
        sp40 = sp10;
        sp48 = (f64) sp18;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, f64 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp50.unk10, sp10);
    }
    temp_r3_237 = this->unkC;
    var_r30_238 = 0;
    if (((u8) M2C_FIELD(temp_r3_237, u8 *, 0x8B8) == 2) || (temp_r3_237->unk870.unk30.Get() != NULL)) {
        var_r30_238 = 1;
    }
    if ((var_r30_238 == 0) || (this->unkC->unk838.unk28.GetDist() < 1500.0f) || (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk10)) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void EarthBossGoal_MoveToTarget::Activate() {
    this->unk8 = 0;
    this->unkC->SetWalkMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unkC->SetAnim((AnimSequenceType) 5, 0, 0, 0.15f, 0U, 0U);
    this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
}

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
void EarthBossGoal_MeleeAttack5::Terminate() {
    AttackerManager *var_r3_364;
    CharacterFireFX *temp_r5_329;
    Enemy *temp_r3_324;
    Enemy *temp_r3_328;
    Enemy *temp_r3_345;
    Enemy *var_r4_371;
    u8 var_r30_343;

    temp_r3_324 = this->unkC;
    M2C_FIELD(temp_r3_324, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_324, u8 *, 0xB08) & ~0x10);
    temp_r3_328 = this->unkC;
    temp_r5_329 = temp_r3_328->unkA08;
    if (temp_r5_329 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_328->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_329);
    }
    var_r30_343 = 0;
    this->unkC->unkA08 = NULL;
    temp_r3_345 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_345, u8 *, 0x8B8) == 2) || (temp_r3_345->unk870.unk30.Get() != NULL)) {
        var_r30_343 = 1;
    }
    if (var_r30_343 != 0) {
        var_r3_364 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_364 = NULL;
    }
    if (var_r3_364 != NULL) {
        var_r4_371 = this->unkC;
        if (var_r4_371 != NULL) {
            var_r4_371 += 0x6B8;
        }
        var_r3_364->Remove((Targetable *) var_r4_371, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

u8 EarthBossGoal_MeleeAttack5::Update() {
    Enemy *temp_r3_410;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    temp_r3_410 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_410, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_410->CheckMeleeHit((EnemyAttack *) temp_r3_410->unkA08, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBossGoal_MeleeAttack5::Activate() {
    AttackerManager *var_r3_500;
    Enemy *temp_r3_444;
    Enemy *temp_r3_453;
    Enemy *temp_r3_480;
    Enemy *temp_r4_463;
    Enemy *var_r4_507;
    MKMaterial *temp_r3_475;
    u8 var_r30_481;
    void *temp_r5_459;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_444 = this->unkC;
    temp_r3_444->unkA0 = 0.0f;
    temp_r3_444->unkA4 = 0.0f;
    temp_r3_444->unkA8 = 0.0f;
    this->unkC->SelectAttack(0x10, 0x40);
    temp_r3_453 = this->unkC;
    temp_r5_459 = temp_r3_453->unkA08->__vptr;
    temp_r3_453->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_459, s32 *, 0x6C), M2C_FIELD(temp_r5_459, s32 *, 0x68), 0, 0.15f, 4U, 0U);
    temp_r4_463 = this->unkC;
loop_2:
    if ((void *) temp_r4_463->unkA04->__vptr != NULL) {
        temp_r4_463->unkA04 = (CharacterZapFX *) &temp_r4_463->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_475 = this->unkC->unkA18;
    if (temp_r3_475 != NULL) {
        temp_r3_475->SetDefaults();
    }
    temp_r3_480 = this->unkC;
    var_r30_481 = 0;
    if (((u8) M2C_FIELD(temp_r3_480, u8 *, 0x8B8) == 2) || (temp_r3_480->unk870.unk30.Get() != NULL)) {
        var_r30_481 = 1;
    }
    if (var_r30_481 != 0) {
        var_r3_500 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_500 = NULL;
    }
    if (var_r3_500 != NULL) {
        var_r4_507 = this->unkC;
        if (var_r4_507 != NULL) {
            var_r4_507 += 0x6B8;
        }
        var_r3_500->Add((Targetable *) var_r4_507, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
void EarthBossGoal_MeleeAttack4::Terminate() {
    AttackerManager *var_r3_579;
    CharacterFireFX *temp_r5_544;
    Enemy *temp_r3_539;
    Enemy *temp_r3_543;
    Enemy *temp_r3_560;
    Enemy *var_r4_586;
    u8 var_r30_558;

    temp_r3_539 = this->unkC;
    M2C_FIELD(temp_r3_539, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_539, u8 *, 0xB08) & ~0x10);
    temp_r3_543 = this->unkC;
    temp_r5_544 = temp_r3_543->unkA08;
    if (temp_r5_544 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_543->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_544);
    }
    var_r30_558 = 0;
    this->unkC->unkA08 = NULL;
    temp_r3_560 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_560, u8 *, 0x8B8) == 2) || (temp_r3_560->unk870.unk30.Get() != NULL)) {
        var_r30_558 = 1;
    }
    if (var_r30_558 != 0) {
        var_r3_579 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_579 = NULL;
    }
    if (var_r3_579 != NULL) {
        var_r4_586 = this->unkC;
        if (var_r4_586 != NULL) {
            var_r4_586 += 0x6B8;
        }
        var_r3_579->Remove((Targetable *) var_r4_586, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

#if 0 // DRAFT: illegal operand
u8 EarthBossGoal_MeleeAttack4::Update() {
    Enemy *temp_r29_618;
    Enemy *temp_r29_650;
    Enemy *temp_r3_644;
    Enemy *temp_r3_672;
    Enemy *temp_r3_721;
    EnemyDescriptor *temp_r4_624;
    EnemyDescriptor *temp_r4_645;
    EnemyDescriptor *temp_r4_656;
    EnemyDescriptor *temp_r4_715;
    EnemyDescriptor *temp_r5_674;
    u8 var_r30_619;
    u8 var_r30_651;
    u8 var_r4_692;
    u8 var_r5_687;
    u8 var_r6_673;
    void *temp_r6_686;

    ActivateIfInactive();
    temp_r29_618 = this->unkC;
    var_r30_619 = 0;
    if (temp_r29_618->HasAnimFinished() != 0) {
        temp_r4_624 = temp_r29_618->unkA38;
        if ((temp_r4_624 != NULL) && ((s8 *) temp_r4_624->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_618, void **, 0x630), u32 *, 0x20))) {
            var_r30_619 = 1;
        }
    }
    if (var_r30_619 != 0) {
        this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + 3.0f;
        temp_r3_644 = this->unkC;
        temp_r4_645 = temp_r3_644->unkA38;
        temp_r3_644->SetAnim((AnimSequence *) temp_r4_645, (AnimTransition *) &temp_r4_645->unk20, 0.0f, 0U);
    } else {
        temp_r29_650 = this->unkC;
        var_r30_651 = 0;
        if (temp_r29_650->HasAnimFinished() != 0) {
            temp_r4_656 = temp_r29_650->unkA38;
            if ((temp_r4_656 != NULL) && ((void *) temp_r4_656->__vptr == (u32) M2C_FIELD(M2C_FIELD(temp_r29_650, void **, 0x630), u32 *, 0x20))) {
                var_r30_651 = 1;
            }
        }
        if (var_r30_651 != 0) {
            this->unk8 = 2;
        } else {
            temp_r3_672 = this->unkC;
            var_r6_673 = 0;
            temp_r5_674 = temp_r3_672->unkA38;
            if ((temp_r5_674 != NULL) && (M2C_BITWISE(u32, temp_r5_674->unk20) == (u32) M2C_FIELD(M2C_FIELD(temp_r3_672, void **, 0x630), u32 *, 0x20))) {
                var_r6_673 = 1;
            }
            if (var_r6_673 != 0) {
                temp_r6_686 = M2C_FIELD(temp_r3_672, void **, 0x630);
                var_r5_687 = 0;
                if (((u32) M2C_FIELD(temp_r6_686, u32 *, 0x2C) >> 1U) & 1) {
                    var_r4_692 = 0;
                    if ((M2C_FIELD(temp_r6_686, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r6_686, s32 *, 0x44) > 1)) {
                        var_r4_692 = 1;
                    }
                    if (var_r4_692 != 0) {
                        var_r5_687 = 1;
                    }
                }
                if ((var_r5_687 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk10)) {
                    temp_r4_715 = temp_r3_672->unkA38;
                    temp_r3_672->SetAnim((AnimSequence *) temp_r4_715, (AnimTransition *) &temp_r4_715->__vptr, 0.0f, 0U);
                }
            }
        }
    }
    temp_r3_721 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_721, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_721->CheckMeleeHit((EnemyAttack *) temp_r3_721->unkA08, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBossGoal_MeleeAttack4::Activate() {
    AttackerManager *var_r3_811;
    Enemy *temp_r3_755;
    Enemy *temp_r3_764;
    Enemy *temp_r3_791;
    Enemy *temp_r4_774;
    Enemy *var_r4_818;
    MKMaterial *temp_r3_786;
    u8 var_r30_792;
    void *temp_r5_770;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_755 = this->unkC;
    temp_r3_755->unkA0 = 0.0f;
    temp_r3_755->unkA4 = 0.0f;
    temp_r3_755->unkA8 = 0.0f;
    this->unkC->SelectAttack(0x10, 0x3F);
    temp_r3_764 = this->unkC;
    temp_r5_770 = temp_r3_764->unkA08->__vptr;
    temp_r3_764->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_770, s32 *, 0x6C), M2C_FIELD(temp_r5_770, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_774 = this->unkC;
loop_2:
    if ((void *) temp_r4_774->unkA04->__vptr != NULL) {
        temp_r4_774->unkA04 = (CharacterZapFX *) &temp_r4_774->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_786 = this->unkC->unkA18;
    if (temp_r3_786 != NULL) {
        temp_r3_786->SetDefaults();
    }
    temp_r3_791 = this->unkC;
    var_r30_792 = 0;
    if (((u8) M2C_FIELD(temp_r3_791, u8 *, 0x8B8) == 2) || (temp_r3_791->unk870.unk30.Get() != NULL)) {
        var_r30_792 = 1;
    }
    if (var_r30_792 != 0) {
        var_r3_811 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_811 = NULL;
    }
    if (var_r3_811 != NULL) {
        var_r4_818 = this->unkC;
        if (var_r4_818 != NULL) {
            var_r4_818 += 0x6B8;
        }
        var_r3_811->Add((Targetable *) var_r4_818, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk10 = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
void EarthBossGoal_MeleeAttack3::Terminate() {
    AttackerManager *var_r3_892;
    CharacterFireFX *temp_r5_857;
    Enemy *temp_r3_852;
    Enemy *temp_r3_856;
    Enemy *temp_r3_873;
    Enemy *var_r4_899;
    u8 var_r30_871;

    temp_r3_852 = this->unkC;
    M2C_FIELD(temp_r3_852, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_852, u8 *, 0xB08) & ~0x10);
    temp_r3_856 = this->unkC;
    temp_r5_857 = temp_r3_856->unkA08;
    if (temp_r5_857 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_856->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_857);
    }
    var_r30_871 = 0;
    this->unkC->unkA08 = NULL;
    temp_r3_873 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_873, u8 *, 0x8B8) == 2) || (temp_r3_873->unk870.unk30.Get() != NULL)) {
        var_r30_871 = 1;
    }
    if (var_r30_871 != 0) {
        var_r3_892 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_892 = NULL;
    }
    if (var_r3_892 != NULL) {
        var_r4_899 = this->unkC;
        if (var_r4_899 != NULL) {
            var_r4_899 += 0x6B8;
        }
        var_r3_892->Remove((Targetable *) var_r4_899, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    M2C_FIELD(this->unkC, s8 *, 0xB9E) = 0;
}
#endif

#if 0 // DRAFT: illegal type
u8 EarthBossGoal_MeleeAttack3::Update() {
    s8 sp60;
    f64 sp58;
    f64 sp50;
    s32 sp4C;
    s32 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r3_1005;
    f32 temp_f31_967;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(1) != 0) {
        temp_f31_967 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.05f, 0.4f, 0.2f, this->unkC->unk8 + 0x30, 80.0f, 0, 4.0f, 0U);
        sp4C = 0;
        MKVector(0.05f, 0.8f, 0.05f);
        sp28.operator*(500.0f);
        sp8 = sp28 * (f64) temp_f31_967;
        sp48 = 0x417;
        sp10 = sp28.unk8 * temp_f31_967;
        sp50 = sp8;
        sp58 = (f64) sp10;
        sp60 = 1;
        sp38 = sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp48, sp8);
    }
    temp_r3_1005 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_1005, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_1005->CheckMeleeHit((EnemyAttack *) temp_r3_1005->unkA08, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBossGoal_MeleeAttack3::Activate() {
    AttackerManager *var_r3_1097;
    Enemy *temp_r3_1041;
    Enemy *temp_r3_1050;
    Enemy *temp_r3_1077;
    Enemy *temp_r4_1060;
    Enemy *var_r4_1104;
    MKMaterial *temp_r3_1072;
    u8 var_r30_1078;
    void *temp_r5_1056;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_1041 = this->unkC;
    temp_r3_1041->unkA0 = 0.0f;
    temp_r3_1041->unkA4 = 0.0f;
    temp_r3_1041->unkA8 = 0.0f;
    this->unkC->SelectAttack(0x10, 0x3E);
    temp_r3_1050 = this->unkC;
    temp_r5_1056 = temp_r3_1050->unkA08->__vptr;
    temp_r3_1050->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_1056, s32 *, 0x6C), M2C_FIELD(temp_r5_1056, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_1060 = this->unkC;
loop_2:
    if ((void *) temp_r4_1060->unkA04->__vptr != NULL) {
        temp_r4_1060->unkA04 = (CharacterZapFX *) &temp_r4_1060->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_1072 = this->unkC->unkA18;
    if (temp_r3_1072 != NULL) {
        temp_r3_1072->SetDefaults();
    }
    temp_r3_1077 = this->unkC;
    var_r30_1078 = 0;
    if (((u8) M2C_FIELD(temp_r3_1077, u8 *, 0x8B8) == 2) || (temp_r3_1077->unk870.unk30.Get() != NULL)) {
        var_r30_1078 = 1;
    }
    if (var_r30_1078 != 0) {
        var_r3_1097 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1097 = NULL;
    }
    if (var_r3_1097 != NULL) {
        var_r4_1104 = this->unkC;
        if (var_r4_1104 != NULL) {
            var_r4_1104 += 0x6B8;
        }
        var_r3_1097->Add((Targetable *) var_r4_1104, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    M2C_FIELD(this->unkC, s8 *, 0xB9E) = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
void EarthBossGoal_MeleeAttack2::Terminate() {
    AttackerManager *var_r3_1179;
    CharacterFireFX *temp_r5_1144;
    Enemy *temp_r3_1139;
    Enemy *temp_r3_1143;
    Enemy *temp_r3_1160;
    Enemy *var_r4_1186;
    u8 var_r30_1158;

    temp_r3_1139 = this->unkC;
    M2C_FIELD(temp_r3_1139, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_1139, u8 *, 0xB08) & ~0x10);
    temp_r3_1143 = this->unkC;
    temp_r5_1144 = temp_r3_1143->unkA08;
    if (temp_r5_1144 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_1143->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_1144);
    }
    var_r30_1158 = 0;
    this->unkC->unkA08 = NULL;
    temp_r3_1160 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_1160, u8 *, 0x8B8) == 2) || (temp_r3_1160->unk870.unk30.Get() != NULL)) {
        var_r30_1158 = 1;
    }
    if (var_r30_1158 != 0) {
        var_r3_1179 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1179 = NULL;
    }
    if (var_r3_1179 != NULL) {
        var_r4_1186 = this->unkC;
        if (var_r4_1186 != NULL) {
            var_r4_1186 += 0x6B8;
        }
        var_r3_1179->Remove((Targetable *) var_r4_1186, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    M2C_FIELD(this->unkC, s8 *, 0xC2E) = 0;
}
#endif

#if 0 // DRAFT: illegal operand
u8 EarthBossGoal_MeleeAttack2::Update() {
    s8 sp60;
    f64 sp58;
    f64 sp50;
    s32 sp4C;
    s32 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    M2C_UNK sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r29_1236;
    Enemy *temp_r29_1272;
    Enemy *temp_r3_1223;
    Enemy *temp_r3_1263;
    Enemy *temp_r3_1294;
    EnemyDescriptor *temp_r4_1242;
    EnemyDescriptor *temp_r4_1264;
    EnemyDescriptor *temp_r4_1278;
    EnemyDescriptor *temp_r4_1319;
    EnemyDescriptor *temp_r5_1296;
    f32 temp_f31_1352;
    u8 var_r30_1237;
    u8 var_r30_1273;
    u8 var_r6_1295;

    ActivateIfInactive();
    temp_r3_1223 = this->unkC;
    if ((((u8) M2C_FIELD(temp_r3_1223, u8 *, 0xB08) >> 4U) & 1) && (temp_r3_1223->CheckMeleeHit((EnemyAttack *) temp_r3_1223->unkA08, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    temp_r29_1236 = this->unkC;
    var_r30_1237 = 0;
    if (temp_r29_1236->HasAnimFinished() != 0) {
        temp_r4_1242 = temp_r29_1236->unkA38;
        if ((temp_r4_1242 != NULL) && ((s8 *) temp_r4_1242->unk0 == (u32) M2C_FIELD(temp_r29_1236, MKAnimScript **, 0x630)->unk20)) {
            var_r30_1237 = 1;
        }
    }
    if (var_r30_1237 != 0) {
        this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(this->unkC, f32 *, 0xCC8);
        temp_r3_1263 = this->unkC;
        temp_r4_1264 = temp_r3_1263->unkA38;
        temp_r3_1263->SetAnim((AnimSequence *) temp_r4_1264, (AnimTransition *) &temp_r4_1264->unk20, 0.0f, 0U);
        M2C_FIELD(this->unkC, s8 *, 0xC2E) = 1;
    } else {
        temp_r29_1272 = this->unkC;
        var_r30_1273 = 0;
        if (temp_r29_1272->HasAnimFinished() != 0) {
            temp_r4_1278 = temp_r29_1272->unkA38;
            if ((temp_r4_1278 != NULL) && ((void *) temp_r4_1278->__vptr == (u32) M2C_FIELD(temp_r29_1272, MKAnimScript **, 0x630)->unk20)) {
                var_r30_1273 = 1;
            }
        }
        if (var_r30_1273 != 0) {
            this->unk8 = 2;
        } else {
            temp_r3_1294 = this->unkC;
            var_r6_1295 = 0;
            temp_r5_1296 = temp_r3_1294->unkA38;
            if ((temp_r5_1296 != NULL) && (M2C_BITWISE(u32, temp_r5_1296->unk20) == (u32) M2C_FIELD(temp_r3_1294, MKAnimScript **, 0x630)->unk20)) {
                var_r6_1295 = 1;
            }
            if ((var_r6_1295 != 0) && ((((u8) M2C_FIELD(temp_r3_1294, u8 *, 0xB08) >> 1U) & 1) || (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk10))) {
                temp_r4_1319 = temp_r3_1294->unkA38;
                temp_r3_1294->SetAnim((AnimSequence *) temp_r4_1319, (AnimTransition *) &temp_r4_1319->__vptr, 0.0f, 0U);
                M2C_FIELD(this->unkC, s8 *, 0xC2E) = 0;
            }
        }
    }
    if (((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(1) != 0) {
        temp_f31_1352 = ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.05f, 0.4f, 0.2f, this->unkC->unk8 + 0x30, 80.0f, 0, 4.0f, 0U);
        sp4C = 0;
        MKVector(0.05f, 0.8f, 0.05f);
        sp28.operator*(500.0f);
        sp8 = sp28 * (f64) temp_f31_1352;
        sp48 = 0x417;
        sp10 = sp28.unk8 * temp_f31_1352;
        sp50 = sp8;
        sp58 = (f64) sp10;
        sp60 = 1;
        sp38 = sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp48, sp8);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBossGoal_MeleeAttack2::Activate() {
    AttackerManager *var_r3_1469;
    Enemy *temp_r3_1413;
    Enemy *temp_r3_1422;
    Enemy *temp_r3_1449;
    Enemy *temp_r4_1432;
    Enemy *var_r4_1476;
    MKMaterial *temp_r3_1444;
    u8 var_r30_1450;
    void *temp_r5_1428;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    temp_r3_1413 = this->unkC;
    temp_r3_1413->unkA0 = 0.0f;
    temp_r3_1413->unkA4 = 0.0f;
    temp_r3_1413->unkA8 = 0.0f;
    this->unkC->SelectAttack(0x10, 0x3D);
    temp_r3_1422 = this->unkC;
    temp_r5_1428 = temp_r3_1422->unkA08->__vptr;
    temp_r3_1422->SetAnim((AnimSequenceType) M2C_FIELD(temp_r5_1428, s32 *, 0x6C), M2C_FIELD(temp_r5_1428, s32 *, 0x68), 0, 0.15f, 0U, 0U);
    temp_r4_1432 = this->unkC;
loop_2:
    if ((void *) temp_r4_1432->unkA04->__vptr != NULL) {
        temp_r4_1432->unkA04 = (CharacterZapFX *) &temp_r4_1432->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_1444 = this->unkC->unkA18;
    if (temp_r3_1444 != NULL) {
        temp_r3_1444->SetDefaults();
    }
    temp_r3_1449 = this->unkC;
    var_r30_1450 = 0;
    if (((u8) M2C_FIELD(temp_r3_1449, u8 *, 0x8B8) == 2) || (temp_r3_1449->unk870.unk30.Get() != NULL)) {
        var_r30_1450 = 1;
    }
    if (var_r30_1450 != 0) {
        var_r3_1469 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1469 = NULL;
    }
    if (var_r3_1469 != NULL) {
        var_r4_1476 = this->unkC;
        if (var_r4_1476 != NULL) {
            var_r4_1476 += 0x6B8;
        }
        var_r3_1469->Add((Targetable *) var_r4_1476, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk10 = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'GetEnemyAttackSetting'
void EarthBossGoal_MeleeAttack1::Terminate() {
    AttackerManager *var_r3_1550;
    CharacterFireFX *temp_r5_1515;
    Enemy *temp_r3_1510;
    Enemy *temp_r3_1514;
    Enemy *temp_r3_1531;
    Enemy *var_r4_1557;
    u8 var_r30_1529;

    temp_r3_1510 = this->unkC;
    M2C_FIELD(temp_r3_1510, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_1510, u8 *, 0xB08) & ~0x10);
    temp_r3_1514 = this->unkC;
    temp_r5_1515 = temp_r3_1514->unkA08;
    if (temp_r5_1515 != NULL) {
        this->unkC->unkA7C = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_1514->unkA20->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_1515);
    }
    var_r30_1529 = 0;
    this->unkC->unkA08 = NULL;
    temp_r3_1531 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_1531, u8 *, 0x8B8) == 2) || (temp_r3_1531->unk870.unk30.Get() != NULL)) {
        var_r30_1529 = 1;
    }
    if (var_r30_1529 != 0) {
        var_r3_1550 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1550 = NULL;
    }
    if (var_r3_1550 != NULL) {
        var_r4_1557 = this->unkC;
        if (var_r4_1557 != NULL) {
            var_r4_1557 += 0x6B8;
        }
        var_r3_1550->Remove((Targetable *) var_r4_1557, 2);
    }
    M2C_FIELD(this->unkC, s8 *, 0xBE6) = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
}
#endif

#if 0 // DRAFT: illegal operand
u8 EarthBossGoal_MeleeAttack1::Update() {
    EarthBossArm *temp_r3_1724;
    EarthBossArm *temp_r5_1681;
    Enemy *temp_r29_1592;
    Enemy *temp_r29_1626;
    Enemy *temp_r3_1617;
    Enemy *temp_r3_1679;
    Enemy *temp_r5_1722;
    Enemy *temp_r6_1648;
    EnemyDescriptor *temp_r4_1598;
    EnemyDescriptor *temp_r4_1618;
    EnemyDescriptor *temp_r4_1632;
    EnemyDescriptor *temp_r4_1650;
    EnemyDescriptor *temp_r4_1710;
    u8 var_r30_1593;
    u8 var_r30_1627;
    u8 var_r4_1680;
    u8 var_r4_1723;
    u8 var_r5_1649;

    ActivateIfInactive();
    temp_r29_1592 = this->unkC;
    var_r30_1593 = 0;
    if (temp_r29_1592->HasAnimFinished() != 0) {
        temp_r4_1598 = temp_r29_1592->unkA38;
        if ((temp_r4_1598 != NULL) && ((s8 *) temp_r4_1598->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1592, void **, 0x630), u32 *, 0x20))) {
            var_r30_1593 = 1;
        }
    }
    if (var_r30_1593 != 0) {
        ((EarthBossArm *) (M2C_FIELD(this->unkC, EarthBossArm **, 0xCC0)))->Extend();
        this->unkC->unk684 = 0.0f;
        temp_r3_1617 = this->unkC;
        temp_r4_1618 = temp_r3_1617->unkA38;
        temp_r3_1617->SetAnim((AnimSequence *) temp_r4_1618, (AnimTransition *) &temp_r4_1618->unk20, 0.0f, 0U);
        M2C_FIELD(this->unkC, s8 *, 0xBE6) = 1;
    } else {
        temp_r29_1626 = this->unkC;
        var_r30_1627 = 0;
        if (temp_r29_1626->HasAnimFinished() != 0) {
            temp_r4_1632 = temp_r29_1626->unkA38;
            if ((temp_r4_1632 != NULL) && ((void *) temp_r4_1632->__vptr == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1626, void **, 0x630), u32 *, 0x20))) {
                var_r30_1627 = 1;
            }
        }
        if (var_r30_1627 != 0) {
            this->unk8 = 2;
        } else {
            temp_r6_1648 = this->unkC;
            var_r5_1649 = 0;
            temp_r4_1650 = temp_r6_1648->unkA38;
            if ((temp_r4_1650 != NULL) && (M2C_BITWISE(u32, temp_r4_1650->unk20) == (u32) M2C_FIELD(M2C_FIELD(temp_r6_1648, void **, 0x630), u32 *, 0x20))) {
                var_r5_1649 = 1;
            }
            if (var_r5_1649 != 0) {
                if (((u8) this->unk14 == 0) && ((u8) M2C_FIELD(temp_r6_1648, EarthBossArm **, 0xCC0)->unk390 != 0)) {
                    this->unk14 = 1;
                    this->unk10 = M2C_FIELD(&gb, f32 *, 0x30C) + M2C_FIELD(this->unkC, f32 *, 0xCC8);
                }
                temp_r3_1679 = this->unkC;
                var_r4_1680 = 0;
                temp_r5_1681 = M2C_FIELD(temp_r3_1679, EarthBossArm **, 0xCC0);
                if (((s32) temp_r5_1681->unk38C == 4) && ((u8) temp_r5_1681->unk358 == 0)) {
                    var_r4_1680 = 1;
                }
                if (((var_r4_1680 == 0) && ((u8) temp_r5_1681->unk390 == 0)) || (((u8) M2C_FIELD(temp_r3_1679, u8 *, 0xB08) >> 1U) & 1) || (((u8) this->unk14 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk10))) {
                    temp_r4_1710 = temp_r3_1679->unkA38;
                    temp_r3_1679->SetAnim((AnimSequence *) temp_r4_1710, (AnimTransition *) &temp_r4_1710->__vptr, 0.0f, 0U);
                    ((EarthBossArm *) (M2C_FIELD(this->unkC, EarthBossArm **, 0xCC0)))->Retract();
                    M2C_FIELD(this->unkC, s8 *, 0xBE6) = 0;
                }
            }
        }
    }
    temp_r5_1722 = this->unkC;
    var_r4_1723 = 0;
    temp_r3_1724 = M2C_FIELD(temp_r5_1722, EarthBossArm **, 0xCC0);
    if (((s32) temp_r3_1724->unk38C == 4) && ((u8) temp_r3_1724->unk358 == 0)) {
        var_r4_1723 = 1;
    }
    if ((var_r4_1723 != 0) && (temp_r3_1724->CheckMeleeHit((EnemyAttack *) temp_r5_1722->unkA08) != 0)) {
        this->unkC->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthBossGoal_MeleeAttack1::Activate() {
    M2C_UNK sp8;
    AttackerManager *var_r3_1817;
    Enemy *temp_r3_1765;
    Enemy *temp_r3_1775;
    Enemy *temp_r3_1797;
    Enemy *temp_r4_1780;
    Enemy *var_r4_1824;
    MKMaterial *temp_r3_1792;
    u8 var_r30_1798;
    void *temp_r4_1769;

    this->unk8 = 0;
    this->unkC->SelectAttack(0x10, 0x3C);
    temp_r3_1765 = this->unkC;
    temp_r4_1769 = temp_r3_1765->unkA08->__vptr;
    temp_r3_1765->SetAnim((AnimSequence *) temp_r4_1769, (AnimTransition *) temp_r4_1769, 0.15f, 0U);
    this->unkC->StopMovement(1U);
    temp_r3_1775 = this->unkC;
    temp_r3_1775->unkA0 = 0.0f;
    temp_r3_1775->unkA4 = 0.0f;
    temp_r3_1775->unkA8 = 0.0f;
    temp_r4_1780 = this->unkC;
loop_2:
    if ((void *) temp_r4_1780->unkA04->__vptr != NULL) {
        temp_r4_1780->unkA04 = (CharacterZapFX *) &temp_r4_1780->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_1792 = this->unkC->unkA18;
    if (temp_r3_1792 != NULL) {
        temp_r3_1792->SetDefaults();
    }
    temp_r3_1797 = this->unkC;
    var_r30_1798 = 0;
    if (((u8) M2C_FIELD(temp_r3_1797, u8 *, 0x8B8) == 2) || (temp_r3_1797->unk870.unk30.Get() != NULL)) {
        var_r30_1798 = 1;
    }
    if (var_r30_1798 != 0) {
        var_r3_1817 = M2C_FIELD(this->unkC->unk870.unk30.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1817 = NULL;
    }
    if (var_r3_1817 != NULL) {
        var_r4_1824 = this->unkC;
        if (var_r4_1824 != NULL) {
            var_r4_1824 += 0x6B8;
        }
        var_r3_1817->Add((Targetable *) var_r4_1824, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    this->unk10 = 0.0f;
    this->unk14 = 0;
    sp8.GetPos();
    ((EarthBossArm *) (M2C_FIELD(this->unkC, EarthBossArm **, 0xCC0)))->Aim(*((MKVector3 *) &sp8));
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
void EarthBossGoal_AttackPhase3::AddGoal_AttackIdle() {
    Goal<EarthBoss> *temp_r6_1871;

    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
    temp_r6_1871 = this->unk20;
    M2C_FIELD(temp_r6_1871, f32 **, 0x10) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r6_1871, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_1871, s32 *, 0x18) = 0xA0;
    M2C_FIELD(temp_r6_1871, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_1871, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1871, u8 *, 0x20) & ~0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
void EarthBossGoal_AttackPhase3::AddGoal_Taunt() {
    Goal<EarthBoss> *temp_r6_1901;

    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
    temp_r6_1901 = this->unk20;
    M2C_FIELD(temp_r6_1901, f32 **, 0x10) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r6_1901, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_1901, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r6_1901, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_1901, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1901, u8 *, 0x20) & ~0x40);
}
#endif

void EarthBossGoal_AttackPhase3::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EarthBossGoal_AttackPhase3::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void EarthBossGoal_AttackPhase3::Activate() {
    Enemy *temp_r3_1974;
    Enemy *temp_r3_1988;
    u8 var_r31_1975;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_1974 = this->unkC;
    var_r31_1975 = 0;
    if (((u8) M2C_FIELD(temp_r3_1974, u8 *, 0x8B8) == 2) || (temp_r3_1974->unk870.unk30.Get() != NULL)) {
        var_r31_1975 = 1;
    }
    if ((var_r31_1975 == 0) || (temp_r3_1988 = this->unkC, ((M2C_BITWISE(s32, temp_r3_1988->unkAD0) == 2) == 0))) {
        this->unk8 = 2;
        return;
    }
    if (((u8) M2C_FIELD(temp_r3_1988, u8 *, 0xB08) >> 1U) & 1) {
        temp_r3_1988->SetHitTarget(0U);
        AddGoal_Taunt();
        return;
    }
    if (temp_r3_1988->unk838.unk28.GetDist() < 500.0f) {
        if (!(M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkA7C)) {
            AddGoal_AttackIdle();
            return;
        }
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk28);
        return;
    }
    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk24);
}
#endif

void EarthBossGoal_AttackPhase3::Deinit() {
    Goal<EarthBoss> *temp_r3_2047;
    MKHeap *temp_r3_2057;
    void *temp_r31_2054;

    temp_r3_2047 = this->unk28;
    temp_r3_2047->Deinit();
    operator delete(this->unk28);
    temp_r31_2054 = this->unk1C;
    if (temp_r31_2054 != NULL) {
        temp_r3_2057 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2057 != NULL) {
            ((MKHeap *) (temp_r3_2057->Current()))->Free(temp_r31_2054, NULL, 0);
        } else {
            free(temp_r31_2054);
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
void EarthBossGoal_AttackPhase3::Init(EarthBoss *arg0) {
    Goal<EarthBoss> *temp_r4_2151;
    MKHeap *temp_r3_2124;
    void *var_r3_2131;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_2124 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2124 != NULL) {
            var_r3_2131 = ((MKHeap *) (temp_r3_2124->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_2131 = malloc(8);
        }
        this->unk1C = var_r3_2131;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x96;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_2151 = this->unk28;
    M2C_FIELD(temp_r4_2151, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2151, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2151, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_2151, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2151, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
void EarthBossGoal_AttackPhase2::AddGoal_AttackIdle() {
    Goal<EarthBoss> *temp_r6_2181;

    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
    temp_r6_2181 = this->unk20;
    M2C_FIELD(temp_r6_2181, f32 **, 0x10) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r6_2181, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_2181, s32 *, 0x18) = 0xA;
    M2C_FIELD(temp_r6_2181, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_2181, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2181, u8 *, 0x20) & ~0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
void EarthBossGoal_AttackPhase2::AddGoal_Taunt() {
    Goal<EarthBoss> *temp_r6_2211;

    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
    temp_r6_2211 = this->unk20;
    M2C_FIELD(temp_r6_2211, f32 **, 0x10) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r6_2211, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_2211, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r6_2211, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_2211, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2211, u8 *, 0x20) & ~0x40);
}
#endif

void EarthBossGoal_AttackPhase2::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EarthBossGoal_AttackPhase2::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void EarthBossGoal_AttackPhase2::Activate() {
    Enemy *temp_r3_2284;
    Enemy *temp_r3_2298;
    u8 var_r31_2285;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_2284 = this->unkC;
    var_r31_2285 = 0;
    if (((u8) M2C_FIELD(temp_r3_2284, u8 *, 0x8B8) == 2) || (temp_r3_2284->unk870.unk30.Get() != NULL)) {
        var_r31_2285 = 1;
    }
    if ((var_r31_2285 == 0) || (temp_r3_2298 = this->unkC, ((M2C_BITWISE(s32, temp_r3_2298->unkAD0) == 1) == 0))) {
        this->unk8 = 2;
        return;
    }
    if (((u8) M2C_FIELD(temp_r3_2298, u8 *, 0xB08) >> 1U) & 1) {
        temp_r3_2298->SetHitTarget(0U);
        AddGoal_Taunt();
        return;
    }
    if (temp_r3_2298->unk838.unk28.GetDist() < 1000.0f) {
        if (!(M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkA7C)) {
            AddGoal_AttackIdle();
            return;
        }
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk28);
        return;
    }
    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk24);
}
#endif

void EarthBossGoal_AttackPhase2::Deinit() {
    Goal<EarthBoss> *temp_r3_2357;
    MKHeap *temp_r3_2367;
    void *temp_r31_2364;

    temp_r3_2357 = this->unk28;
    temp_r3_2357->Deinit();
    operator delete(this->unk28);
    temp_r31_2364 = this->unk1C;
    if (temp_r31_2364 != NULL) {
        temp_r3_2367 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2367 != NULL) {
            ((MKHeap *) (temp_r3_2367->Current()))->Free(temp_r31_2364, NULL, 0);
        } else {
            free(temp_r31_2364);
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
void EarthBossGoal_AttackPhase2::Init(EarthBoss *arg0) {
    Goal<EarthBoss> *temp_r4_2461;
    MKHeap *temp_r3_2434;
    void *var_r3_2441;

    if ((u8) this->unk9 == 0) {
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_2434 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_2434 != NULL) {
            var_r3_2441 = ((MKHeap *) (temp_r3_2434->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_2441 = malloc(8);
        }
        this->unk1C = var_r3_2441;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x95;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_2461 = this->unk28;
    M2C_FIELD(temp_r4_2461, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_2461, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_2461, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_2461, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_2461, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
u8 EarthBossGoal_AttackPhase1::AddGoal_ScrapeFootClean() {
    BoneBlurFX *temp_r4_2488;
    Goal<EarthBoss> *temp_r6_2499;

    temp_r4_2488 = this->unkC->unkA10;
    if ((temp_r4_2488 != NULL) && ((s32) M2C_FIELD(temp_r4_2488->unk0, s32 *, 0x68) == 0x3E)) {
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
        temp_r6_2499 = this->unk20;
        M2C_FIELD(temp_r6_2499, f32 **, 0x10) = &this->unkC->unk838.unk28;
        M2C_FIELD(temp_r6_2499, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r6_2499, s32 *, 0x18) = 0xA2;
        M2C_FIELD(temp_r6_2499, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r6_2499, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2499, u8 *, 0x20) & ~0x40);
        this->unkC->SetHitTarget(0U);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
void EarthBossGoal_AttackPhase1::AddGoal_AttackIdle() {
    Goal<EarthBoss> *temp_r6_2537;

    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
    temp_r6_2537 = this->unk20;
    M2C_FIELD(temp_r6_2537, f32 **, 0x10) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r6_2537, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_2537, s32 *, 0x18) = 0xA;
    M2C_FIELD(temp_r6_2537, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_2537, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2537, u8 *, 0x20) & ~0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__25CompositeGoal'
void EarthBossGoal_AttackPhase1::AddGoal_TauntOnKill() {
    Goal<EarthBoss> *temp_r6_2567;

    AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk20);
    temp_r6_2567 = this->unk20;
    M2C_FIELD(temp_r6_2567, f32 **, 0x10) = &this->unkC->unk838.unk28;
    M2C_FIELD(temp_r6_2567, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r6_2567, s32 *, 0x18) = 4;
    M2C_FIELD(temp_r6_2567, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r6_2567, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_2567, u8 *, 0x20) & ~0x40);
}
#endif

void EarthBossGoal_AttackPhase1::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: expression syntax error
u8 EarthBossGoal_AttackPhase1::Update() {
    Enemy *temp_r3_2611;
    Enemy *temp_r4_2637;
    u8 var_r30_2612;
    u8 var_r3_2651;
    u8 var_r4_2646;
    void **temp_r3_2630;
    void *temp_r5_2645;

    if ((u8) this->unk3C != 0) {
        temp_r3_2611 = this->unkC;
        var_r30_2612 = 0;
        if (((u8) M2C_FIELD(temp_r3_2611, u8 *, 0x8B8) == 2) || (temp_r3_2611->unk870.unk30.Get() != NULL)) {
            var_r30_2612 = 1;
        }
        if (var_r30_2612 != 0) {
            this->unk8 = 1;
        }
    }
    ActivateIfInactive();
    temp_r3_2630 = this->unk24;
    if (M2C_FIELD(*temp_r3_2630, u8 (**)(void **), 0x28)(temp_r3_2630) != 0) {
        temp_r4_2637 = this->unkC;
        if (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_2637->unkA7C) {
            temp_r5_2645 = M2C_FIELD(temp_r4_2637, void **, 0x630);
            var_r4_2646 = 0;
            if (((u32) M2C_FIELD(temp_r5_2645, u32 *, 0x2C) >> 1U) & 1) {
                var_r3_2651 = 0;
                if ((M2C_FIELD(temp_r5_2645, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_2645, s32 *, 0x44) > 1)) {
                    var_r3_2651 = 1;
                }
                if (var_r3_2651 != 0) {
                    var_r4_2646 = 1;
                }
            }
            if (var_r4_2646 != 0) {
                SelectAttack();
            }
        }
    }
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
u8 EarthBossGoal_AttackPhase1::SelectAttack() {
    AITargetData sp8;
    Enemy *temp_r3_2709;
    f32 temp_f0_2778;
    f32 temp_f1_2760;
    f32 temp_f27_2758;
    f32 temp_f28_2734;
    f32 temp_f29_2742;
    f32 temp_f30_2753;
    f32 temp_f31_2757;
    s32 temp_r0_2856;
    s32 temp_r3_2826;
    s32 var_r26_2823;
    s32 var_r29_2711;
    s32 var_r30_2710;
    s32 var_r7_2828;
    u32 var_r28_2712;
    u8 var_r0_2762;
    u8 var_r0_2777;
    u8 var_r26_2714;
    void ***var_r25_2745;
    void ***var_r6_2832;
    void **temp_r26_2810;
    void **temp_r5_2849;
    void **var_r31_2708;

    var_r31_2708 = NULL;
    temp_r3_2709 = this->unkC;
    var_r30_2710 = 0;
    var_r29_2711 = 0;
    var_r28_2712 = 0;
    var_r26_2714 = 0;
    if (((u8) M2C_FIELD(temp_r3_2709, u8 *, 0x8B8) == 2) || (temp_r3_2709->unk870.unk30.Get() != NULL)) {
        var_r26_2714 = 1;
    }
    if (var_r26_2714 == 0) {
        return 0U;
    }
    temp_f28_2734 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &this->unkC->unkC0)));
    sp8.GetDir();
    temp_f29_2742 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp8)));
    var_r25_2745 = *M2C_FIELD(this->unkC->unkA20, void *****, 0x228);
loop_20:
    if (var_r25_2745 != NULL) {
        temp_r26_2810 = *var_r25_2745;
        if (temp_r26_2810 != NULL) {
            var_r31_2708 = temp_r26_2810;
            temp_f30_2753 = NormaliseAngle(temp_f28_2734 + M2C_FIELD(temp_r26_2810, f32 *, 0x1C));
            temp_f31_2757 = NormaliseAngle(temp_f28_2734 + M2C_FIELD(temp_r26_2810, f32 *, 0x20));
            temp_f27_2758 = M2C_FIELD(temp_r26_2810, f32 *, 0x18);
            temp_f1_2760 = this->unkC->unk838.unk28.GetDist();
            var_r0_2762 = 0;
            if ((temp_f1_2760 >= M2C_FIELD(temp_r26_2810, f32 *, 0x14)) && (temp_f1_2760 <= temp_f27_2758)) {
                var_r0_2762 = 1;
            }
            if (var_r0_2762 != 0) {
                if (temp_f30_2753 > temp_f31_2757) {
                    var_r0_2777 = 0;
                    temp_f0_2778 = 6.2831855f - temp_f30_2753;
                    if ((temp_f29_2742 > temp_f30_2753) || ((temp_f29_2742 + temp_f0_2778) < (temp_f31_2757 + temp_f0_2778))) {
                        var_r0_2777 = 1;
                    }
                } else {
                    var_r0_2777 = 0;
                    if ((temp_f29_2742 > temp_f30_2753) && ((temp_f29_2742 - temp_f30_2753) < (temp_f31_2757 - temp_f30_2753))) {
                        var_r0_2777 = 1;
                    }
                }
                if (var_r0_2777 != 0) {
                    var_r28_2712 |= 1 << var_r29_2711;
                    var_r30_2710 += M2C_FIELD(temp_r26_2810, s32 *, 0x40);
                }
            }
            var_r29_2711 += 1;
            var_r25_2745 += 4;
            goto loop_20;
        }
    }
    if ((var_r28_2712 == 0) || (var_r30_2710 <= 0)) {
        return 0U;
    }
    var_r26_2823 = 0;
    temp_r3_2826 = MKRand_Int(&gViewSeed, 0, var_r30_2710);
    var_r7_2828 = 0;
    var_r6_2832 = *M2C_FIELD(this->unkC->unkA20, void *****, 0x228);
loop_30:
    if (var_r6_2832 != NULL) {
        temp_r5_2849 = *var_r6_2832;
        if (temp_r5_2849 != NULL) {
            if ((1 << var_r26_2823) & var_r28_2712) {
                var_r31_2708 = temp_r5_2849;
                if (var_r7_2828 < temp_r3_2826) {
                    var_r7_2828 += M2C_FIELD(temp_r5_2849, s32 *, 0x40);
                    goto block_29;
                }
            } else {
block_29:
                var_r26_2823 += 1;
                var_r6_2832 += 4;
                goto loop_30;
            }
        }
    }
    RemoveAllSubgoals();
    temp_r0_2856 = M2C_FIELD(*var_r31_2708, s32 *, 0x68);
    switch (temp_r0_2856) {                         /* irregular */
    case 0x3C:
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk28);
        break;
    case 0x3D:
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk2C);
        break;
    case 0x3E:
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk30);
        break;
    case 0x3F:
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk34);
        break;
    case 0x40:
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk38);
        break;
    }
    return 1U;
}
#endif

#if 0 // DRAFT: expression syntax error
void EarthBossGoal_AttackPhase1::Activate() {
    Enemy *temp_r3_2926;
    u8 var_r30_2924;

    this->unk8 = 0;
    RemoveAllSubgoals();
    var_r30_2924 = 0;
    this->unk3C = 0;
    temp_r3_2926 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2926, u8 *, 0x8B8) == 2) || (temp_r3_2926->unk870.unk30.Get() != NULL)) {
        var_r30_2924 = 1;
    }
    if (var_r30_2924 == 0) {
        if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 1U) & 1) {
            AddGoal_TauntOnKill();
            this->unkC->SetHitTarget(0U);
            return;
        }
        this->unk3C = 1;
        AddGoal_AttackIdle();
        return;
    }
    if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 1U) & 1) {
        if (AddGoal_ScrapeFootClean() == 0) {
            this->unkC->SetHitTarget(0U);
            goto block_10;
        }
    } else {
block_10:
        if (!(M2C_FIELD(&gb, f32 *, 0x30C) >= this->unkC->unkA7C)) {
            AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk24);
            return;
        }
        if (SelectAttack() == 0) {
            AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk24);
        }
    }
}
#endif

void EarthBossGoal_AttackPhase1::Deinit() {
    Goal<EarthBoss> *temp_r3_3004;
    Goal<EarthBoss> *temp_r3_3009;
    Goal<EarthBoss> *temp_r3_3014;
    Goal<EarthBoss> *temp_r3_3019;
    Goal<EarthBoss> *temp_r3_3024;
    MKHeap *temp_r3_3042;
    void *temp_r31_3039;

    temp_r3_3004 = this->unk28;
    temp_r3_3004->Deinit();
    temp_r3_3009 = this->unk2C;
    temp_r3_3009->Deinit();
    temp_r3_3014 = this->unk30;
    temp_r3_3014->Deinit();
    temp_r3_3019 = this->unk34;
    temp_r3_3019->Deinit();
    temp_r3_3024 = this->unk38;
    temp_r3_3024->Deinit();
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    temp_r31_3039 = this->unk1C;
    if (temp_r31_3039 != NULL) {
        temp_r3_3042 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3042 != NULL) {
            ((MKHeap *) (temp_r3_3042->Current()))->Free(temp_r31_3039, NULL, 0);
        } else {
            free(temp_r31_3039);
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
void EarthBossGoal_AttackPhase1::Init(EarthBoss *arg0) {
    Goal<EarthBoss> *temp_r4_3216;
    Goal<EarthBoss> *temp_r4_3227;
    Goal<EarthBoss> *temp_r4_3238;
    Goal<EarthBoss> *temp_r4_3249;
    Goal<EarthBoss> *temp_r4_3260;
    MKHeap *temp_r3_3189;
    void *var_r3_3196;

    if ((u8) this->unk9 == 0) {
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_3189 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3189 != NULL) {
            var_r3_3196 = ((MKHeap *) (temp_r3_3189->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_3196 = malloc(8);
        }
        this->unk1C = var_r3_3196;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x94;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3216 = this->unk28;
    M2C_FIELD(temp_r4_3216, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3216, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3216, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_3216, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3216, s8 *, 9) = 1;
    }
    temp_r4_3227 = this->unk2C;
    M2C_FIELD(temp_r4_3227, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3227, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3227, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_3227, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3227, s8 *, 9) = 1;
    }
    temp_r4_3238 = this->unk30;
    M2C_FIELD(temp_r4_3238, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3238, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3238, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_3238, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3238, s8 *, 9) = 1;
    }
    temp_r4_3249 = this->unk34;
    M2C_FIELD(temp_r4_3249, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3249, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3249, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_3249, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3249, s8 *, 9) = 1;
    }
    temp_r4_3260 = this->unk38;
    M2C_FIELD(temp_r4_3260, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3260, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3260, s32 *, 4) = 0x3A;
    if ((EarthBoss *) M2C_FIELD(temp_r4_3260, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3260, s8 *, 9) = 1;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EarthBossGoal_Think::AddGoal_AttackPhase1() {
    if (IsPresent(0x94) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk34);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EarthBossGoal_Think::AddGoal_Spawn() {
    if (IsActive(0x38) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk30);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EarthBossGoal_Think::AddGoal_Idle() {
    Goal<EarthBoss> *temp_r5_3356;

    if (IsActive(0) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk24);
        temp_r5_3356 = this->unk24;
        M2C_FIELD(temp_r5_3356, f32 **, 0x10) = &this->unkC->unk838.unk28;
        M2C_FIELD(temp_r5_3356, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r5_3356, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r5_3356, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r5_3356, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_3356, u8 *, 0x20) & ~0x40);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EarthBossGoal_Think::AddGoal_Death(EnemyDamageFeedback *arg0) {
    if (IsPresent(0x5B) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk2C);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' != 'int'
void EarthBossGoal_Think::AddGoal_Hit(EnemyDamageFeedback *arg0) {
    Enemy *temp_r4_3465;
    s32 temp_r0_3411;
    s32 temp_r0_3441;

    temp_r0_3411 = arg0->unk28;
    switch (temp_r0_3411) {                         /* irregular */
    case 11:
    case 2:
        arg0->unk28 = 0;
        break;
    default:
    case 3:
        arg0->unk28 = 1;
        break;
    }
    if (IsActive(0x59) != 0) {
        temp_r0_3441 = arg0->unk28;
        if ((temp_r0_3441 != 0) && ((temp_r0_3441 != 1) || (IsActive(0xA) == 0))) {
            if (IsActive(0x12) != 0) {
                return;
            }
            goto block_16;
        }
    } else {
block_16:
        temp_r4_3465 = this->unkC;
        M2C_FIELD(temp_r4_3465, f64 *, 0x910) = (f64) arg0->unk0;
        M2C_FIELD(temp_r4_3465, f64 *, 0x918) = (f64) arg0->unk8;
        M2C_FIELD(temp_r4_3465, s32 *, 0x920) = (s32) arg0->unk10;
        M2C_FIELD(temp_r4_3465, s32 *, 0x924) = (s32) arg0->unk14;
        temp_r4_3465->unk918 = arg0->unk18;
        temp_r4_3465->unk92C = arg0->unk1C;
        temp_r4_3465->unk920 = arg0->unk20;
        temp_r4_3465->unk924 = arg0->unk24;
        temp_r4_3465->unk928 = M2C_BITWISE(f32, arg0->unk28);
        temp_r4_3465->unk92C = M2C_BITWISE(f32, arg0->unk2C);
        temp_r4_3465->unk930 = arg0->unk30;
        M2C_FIELD(temp_r4_3465, u8 *, 0x944) = (u8) arg0->unk34;
        this->unkC->unk918 = 0.0f;
        RemoveAllSubgoals();
        AddSubgoal__25CompositeGoal<9EarthBoss>FP16Goal<9EarthBoss>((CompositeGoal<EarthBoss> *) this, (Goal<EarthBoss> *) this->unk28);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EarthBossGoal_Think::Update() {
    Enemy *temp_r3_3535;
    Enemy *temp_r3_3553;
    Enemy *temp_r4_3521;
    Enemy *temp_r4_3528;
    u8 temp_r4_3550;

    if (this->unkC->WasHit() != 0) {
        this->unk8 = 1;
    }
    temp_r4_3521 = this->unkC;
    if ((u8) M2C_FIELD(temp_r4_3521, u8 *, 0xCDC) != 0) {
        M2C_FIELD(temp_r4_3521, u8 *, 0xCDC) = 0U;
        temp_r4_3528 = this->unkC;
        temp_r4_3528->unk9D8 = 0;
        temp_r4_3528->unk9D4 = 0;
        RemoveAllSubgoals();
        this->unk8 = 1;
    }
    temp_r3_3535 = this->unkC;
    if (temp_r3_3535->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r4_3550 = this->unk8;
    if (temp_r4_3550 == 2) {
        temp_r3_3553 = this->unkC;
        if (!(((u8) M2C_FIELD(temp_r3_3553, u8 *, 0xB09) >> 7U) & 1)) {
            M2C_FIELD(temp_r3_3553->__vptr, M2C_UNK (**)(), 0x34)();
            return this->unk8;
        }
    }
    if (temp_r4_3550 != 0) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void EarthBossGoal_Think::Arbitrate() {
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    EnemyDamageFeedback sp78;
    EnemyHudData sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    EarthBossArm *temp_r3_3883;
    Enemy *temp_r3_3608;
    Enemy *temp_r3_3659;
    Enemy *temp_r3_3877;
    Enemy *temp_r5_3699;
    Enemy *temp_r6_3740;
    f32 temp_f1_3619;
    f32 temp_f1_3649;
    f32 temp_f1_3780;
    f32 temp_f2_3779;
    f32 temp_f3_3781;
    f32 temp_f5_3625;
    f32 temp_f6_3612;
    f32 temp_r0_3925;
    f32 temp_r4_3706;
    f32 var_f4_3766;
    f32 var_f5_3786;
    f64 temp_f1_3791;
    f64 temp_f1_3797;
    f64 temp_f1_3801;
    s32 temp_r5_3820;
    s32 var_ctr_3735;
    s32 var_r3_3830;
    s32 var_r4_3734;
    s32 var_r8_3733;
    u8 var_r0_3728;
    void *temp_r6_3778;
    void *temp_r7_3741;

    if ((((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 7U) & 1) || (M2C_STRUCT_COPY((s32) &sp78.unk34 + 4, (s32) (&Matrix::identity - 4) + 4, 0x40), temp_r3_3608 = this->unkC, temp_f6_3612 = temp_r3_3608->unk5C8, spD0 = temp_f6_3612, temp_f1_3619 = temp_r3_3608->unk5C8, spD4 = temp_f1_3619, temp_f5_3625 = temp_r3_3608->unk5CC, sp30 = (MKVector3::up.unk0 * temp_f1_3619) - (MKVector3::up.unk4 * temp_f6_3612), spD8 = temp_f5_3625, sp50 = (f64) sp30, sp28 = (MKVector3::up.unk4 * temp_f5_3625) - (MKVector3::up.unk8 * temp_f1_3619), sp2C = (MKVector3::up.unk8 * temp_f6_3612) - (MKVector3::up.unk0 * temp_f5_3625), spDC = 0.0f, sp48 = (f64) sp28, spB0 = (f32) sp48, spB4 = unksp4C, spB8 = (f32) sp50, spBC = 0.0f, spE0 = temp_r3_3608->unk5B8, spE4 = temp_r3_3608->unk5B8, temp_f1_3649 = temp_r3_3608->unk5BC, spE8 = temp_f1_3649, spEC = 1.0f, ((temp_r3_3608->Spawn(&spB0, 0, &MKVector3::up, temp_f1_3649, unksp4C, (f32) sp48, 0.0f, temp_f5_3625, temp_f6_3612, MKVector3::up.unk8, MKVector3::up.unk4) == 0) == 0))) {
        temp_r3_3659 = this->unkC;
        if ((u8) M2C_FIELD(temp_r3_3659, u8 *, 0xCDD) == 0) {
            AddGoal_Spawn();
            return;
        }
        if (temp_r3_3659->WasHit() != 0) {
            sp78.Init();
            this->unkC->InterceptDamage();
            this->unkC->TakeDamage(&sp78, 0U);
            if ((sp78.unk24 != 0.0f) && (KDSound_IsVoicePlaying(M2C_FIELD(this->unkC, s32 *, 0xCE0)) == 0)) {
                M2C_FIELD(this->unkC, s32 *, 0xCE0) = KDSound_Play3d(GS_SSFlinch, this->unkC->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            }
            temp_r5_3699 = this->unkC;
            if (temp_r5_3699->unkAB0 <= 0.0f) {
                temp_r4_3706 = temp_r5_3699->unkAD0;
                if (M2C_BITWISE(s32, temp_r4_3706) < (s32) (M2C_FIELD(temp_r5_3699->unkA20, s32 *, 0x11C) - 1)) {
                    temp_r5_3699->unkAD0 = M2C_BITWISE(f32, (M2C_BITWISE(s32, temp_r4_3706) + 1));
                    this->unkC->RestartStage();
                    sp58.EnemyHudData();
                    this->unkC->GetMaxHealth();
                    sp58.Init(this->unkC, 0.0f, M2C_ERROR(/* Read from unset register $f1 */));
                    EnemyHud_Modified(sp58);
                }
            }
            var_r0_3728 = 0;
            if (sp78.unk20 & 0x47F0) {
                var_r8_3733 = 0;
                var_r4_3734 = 0;
                var_ctr_3735 = 6;
loop_13:
                if (((u32) (var_r8_3733 - 4) > 1U) && (temp_r6_3740 = this->unkC, temp_r7_3741 = temp_r6_3740 + var_r4_3734, (((u32) sp78.unk10 == (u32) M2C_FIELD(temp_r7_3741, u32 *, 0xB10)) != 0)) && ((u8) M2C_FIELD(temp_r7_3741, u8 *, 0xB55) == 0)) {
                    if ((var_r8_3733 != 2) || ((s32) M2C_FIELD(temp_r6_3740, EarthBossArm **, 0xCC0)->unk38C == 0)) {
                        var_r0_3728 = 1;
                        sp18 = *(temp_r7_3741 + 0xB18) - M2C_BITWISE(f64, sp78);
                        var_f4_3766 = 0.0f;
                        M2C_FIELD(temp_r7_3741, f64 *, 0xB38) = sp18;
                        sp20 = M2C_FIELD(temp_r7_3741, f32 *, 0xB20) - (f32) sp78.unk8;
                        sp38 = sp18;
                        M2C_FIELD(temp_r7_3741, f64 *, 0xB40) = (f64) sp20;
                        sp40 = (f64) sp20;
                        M2C_FIELD((this->unkC + var_r4_3734), f32 *, 0xB3C) = 0.0f;
                        temp_r6_3778 = this->unkC + (var_r4_3734 + 0xB38);
                        temp_f2_3779 = M2C_FIELD(temp_r6_3778, f32 *, 0);
                        temp_f1_3780 = M2C_FIELD(temp_r6_3778, f32 *, 4);
                        temp_f3_3781 = M2C_FIELD(temp_r6_3778, f32 *, 8);
                        var_f5_3786 = (temp_f3_3781 * temp_f3_3781) + ((temp_f2_3779 * temp_f2_3779) + (temp_f1_3780 * temp_f1_3780));
                        if (var_f5_3786 > 0.000001f) {
                            if (var_f5_3786 > 0.0f) {
                                temp_f1_3791 = __frsqrte(var_f5_3786);
                                temp_f1_3797 = 0.5 * temp_f1_3791 * -(((f64) var_f5_3786 * (temp_f1_3791 * temp_f1_3791)) - 3.0);
                                temp_f1_3801 = 0.5 * temp_f1_3797 * -(((f64) var_f5_3786 * (temp_f1_3797 * temp_f1_3797)) - 3.0);
                                var_f5_3786 = (f32) ((f64) var_f5_3786 * (0.5 * temp_f1_3801 * -(((f64) var_f5_3786 * (temp_f1_3801 * temp_f1_3801)) - 3.0)));
                            } else if (var_f5_3786 < M2C_BITWISE(f32, 0.0)) {
                                var_f5_3786 = __float_nan;
                            } else {
                                sp10 = var_f5_3786;
                                temp_r5_3820 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                switch (temp_r5_3820) { /* switch 1; irregular */
                                case 0x7F800000:    /* switch 1 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r3_3830 = 1;
                                    } else {
                                        var_r3_3830 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 1 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r3_3830 = 5;
                                    } else {
                                        var_r3_3830 = 3;
                                    }
                                    break;
                                default:            /* switch 1 */
                                    var_r3_3830 = 4;
                                    break;
                                }
                                if (var_r3_3830 == 1) {
                                    var_f5_3786 = __float_nan;
                                }
                            }
                            var_f4_3766 = 1.0f / var_f5_3786;
                        }
                        M2C_FIELD(temp_r6_3778, f32 *, 0) = (f32) (M2C_FIELD(temp_r6_3778, f32 *, 0) * var_f4_3766);
                        M2C_FIELD(temp_r6_3778, f32 *, 4) = (f32) (M2C_FIELD(temp_r6_3778, f32 *, 4) * var_f4_3766);
                        M2C_FIELD(temp_r6_3778, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_3778, f32 *, 8) * var_f4_3766);
                        M2C_FIELD((this->unkC + var_r4_3734), s8 *, 0xB55) = 1;
                        M2C_FIELD((this->unkC + var_r4_3734), f32 *, 0xB48) = 0.0f;
                    }
                } else {
                    var_r8_3733 += 1;
                    var_r4_3734 += 0x48;
                    var_ctr_3735 -= 1;
                    if (var_ctr_3735 != 0) {
                        goto loop_13;
                    }
                }
            }
            temp_r3_3877 = this->unkC;
            if (temp_r3_3877->unkAB0 <= 0.0f) {
                temp_r3_3883 = M2C_FIELD(temp_r3_3877, EarthBossArm **, 0xCC0);
                if ((s32) temp_r3_3883->unk38C != 0) {
                    temp_r3_3883->Retract();
                }
                this->unkC->ClearHitAndDeathFX();
                AddGoal_Death(&sp78);
                return;
            }
            if (sp78.unk28 < 6) {
                if (sp78.unk28 < 4) {
                    goto block_47;
                }
                sp78.unk28 = 0xE;
            } else {
block_47:
                if (var_r0_3728 != 0) {
                    sp78.unk28 = 0xE;
                }
            }
            if (sp78.unk28 != 0xE) {
                AddGoal_Hit(&sp78);
                return;
            }
            goto block_51;
        }
block_51:
        this->unkC->IsFlinching();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            temp_r0_3925 = this->unkC->unkAD0;
            switch (M2C_BITWISE(s32, temp_r0_3925)) { /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                AddGoal_AttackPhase1();
                return;
            case 1:                                 /* switch 2 */
                AddGoal_AttackPhase1();
                return;
            case 2:                                 /* switch 2 */
                AddGoal_AttackPhase1();
                return;
            default:                                /* switch 2 */
                if ((s32) this->unk14 == 0) {
                    AddGoal_Idle();
                }
                break;
            }
        }
    }
}
#endif

void EarthBossGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void EarthBossGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk20 = 1;
}

void EarthBossGoal_Think::Deinit() {
    Goal<EarthBoss> *temp_r3_4009;
    Goal<EarthBoss> *temp_r3_4014;
    Goal<EarthBoss> *temp_r3_4019;
    Goal<EarthBoss> *temp_r3_4024;
    Goal<EarthBoss> *temp_r3_4044;
    MKHeap *temp_r3_4068;
    void **temp_r3_4029;
    void **temp_r3_4034;
    void **temp_r3_4039;
    void *temp_r31_4065;

    temp_r3_4009 = this->unk24;
    temp_r3_4009->Deinit();
    temp_r3_4014 = this->unk28;
    temp_r3_4014->Deinit();
    temp_r3_4019 = this->unk2C;
    temp_r3_4019->Deinit();
    temp_r3_4024 = this->unk34;
    temp_r3_4024->Deinit();
    temp_r3_4029 = this->unk38;
    M2C_FIELD(*temp_r3_4029, M2C_UNK (**)(void **), 0xC)(temp_r3_4029);
    temp_r3_4034 = this->unk3C;
    M2C_FIELD(*temp_r3_4034, M2C_UNK (**)(void **), 0xC)(temp_r3_4034);
    temp_r3_4039 = this->unk40;
    M2C_FIELD(*temp_r3_4039, M2C_UNK (**)(void **), 0xC)(temp_r3_4039);
    temp_r3_4044 = this->unk30;
    temp_r3_4044->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    operator delete(this->unk40);
    operator delete(this->unk30);
    temp_r31_4065 = this->unk1C;
    if (temp_r31_4065 != NULL) {
        temp_r3_4068 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4068 != NULL) {
            ((MKHeap *) (temp_r3_4068->Current()))->Free(temp_r31_4065, NULL, 0);
        } else {
            free(temp_r31_4065);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
}

#if 0 // DRAFT: pointer/array required
void EarthBossGoal_Think::Init(EarthBoss *arg0) {
    Goal<EarthBoss> *temp_r4_4340;
    Goal<EarthBoss> *temp_r4_4377;
    MKHeap *temp_r3_4313;
    void **temp_r4_4366;
    void *var_r3_4320;

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
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__25CompositeGoal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x2CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__25CompositeGoal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x2CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__25CompositeGoal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__16Goal<9EarthBoss>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
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
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_4313 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_4313 != NULL) {
            var_r3_4320 = ((MKHeap *) (temp_r3_4313->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_4320 = malloc(8);
        }
        this->unk1C = var_r3_4320;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (Enemy *) arg0;
    this->unk4 = 0x93;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_4340 = this->unk24;
    M2C_FIELD(temp_r4_4340, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4340, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4340, s32 *, 4) = 0;
    if ((EarthBoss *) M2C_FIELD(temp_r4_4340, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4340, s8 *, 9) = 1;
    }
    this->unk28->Init((Enemy *) arg0);
    this->unk2C->Init((Enemy *) arg0);
    this->unk34->Init(arg0);
    this->unk38->Init(arg0);
    this->unk3C->Init(arg0);
    temp_r4_4366 = this->unk40;
    M2C_FIELD(temp_r4_4366, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4366, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4366, s32 *, 4) = 0x97;
    if ((EarthBoss *) M2C_FIELD(temp_r4_4366, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4366, s8 *, 9) = 1;
    }
    temp_r4_4377 = this->unk30;
    M2C_FIELD(temp_r4_4377, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_4377, EarthBoss **, 0xC) = arg0;
    M2C_FIELD(temp_r4_4377, s32 *, 4) = 0x38;
    if ((EarthBoss *) M2C_FIELD(temp_r4_4377, EarthBoss **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_4377, s8 *, 9) = 1;
    }
    M2C_FIELD(this->unk34, Goal<EarthBoss> **, 0x20) = (Goal<EarthBoss> *) this->unk24;
    M2C_FIELD(this->unk38, Goal<EarthBoss> **, 0x20) = (Goal<EarthBoss> *) this->unk24;
    M2C_FIELD(this->unk3C, Goal<EarthBoss> **, 0x20) = (Goal<EarthBoss> *) this->unk24;
    M2C_FIELD(this->unk34, void ***, 0x24) = (void **) this->unk40;
    M2C_FIELD(this->unk38, void ***, 0x24) = (void **) this->unk40;
    M2C_FIELD(this->unk3C, void ***, 0x24) = (void **) this->unk40;
}
#endif

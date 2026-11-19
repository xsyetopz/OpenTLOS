#include "spyro/source/EnemyGoal_DefensiveMode.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/SB2.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unkA38'
void EnemyGoal_ShieldCharge::Terminate() {
    Character *temp_r3_55;
    Character *temp_r6_19;
    s32 var_r3_63;
    u8 temp_r0_62;
    void *temp_r3_26;
    void *temp_r3_31;
    void *temp_r5_56;

    this->unkC->StopMovement(1U);
    temp_r6_19 = this->unkC;
    temp_r6_19->unk690 = temp_r6_19->unkA38->unk168;
    temp_r3_26 = this->unkC->unk638;
    M2C_FIELD(temp_r3_26, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_26, u8 *, 0x464) & ~0x80);
    temp_r3_31 = this->unkC->unk638;
    M2C_FIELD(temp_r3_31, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_31, u8 *, 0x464) | 0x10);
    ((SB2 *) this->unkC->unk638)->SeekOff();
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->WallAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->ContainmentOff();
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(0U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r3_55 = this->unkC;
    temp_r5_56 = temp_r3_55->unkA5C;
    if ((temp_r5_56 != NULL) && ((u32) M2C_FIELD(temp_r5_56, u32 *, 8) != 0U)) {
        temp_r0_62 = temp_r3_55->unkB08;
        var_r3_63 = 1;
        if (!((temp_r0_62 >> 1U) & 1) && !(temp_r0_62 & 1)) {
            var_r3_63 = 0;
        }
        M2C_FIELD(temp_r5_56, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r5_56, u8 *, 0x10) & ~0x80) | ((var_r3_63 << 7) & 0x80));
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk908'
u8 EnemyGoal_ShieldCharge::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AITargetData *temp_r3_93;
    AnimSequence *temp_r4_158;
    Character *temp_r29_136;
    Character *temp_r3_117;
    Character *temp_r3_154;
    Character *temp_r3_214;
    Character *temp_r3_222;
    Character *temp_r3_241;
    Character *temp_r3_257;
    Character *temp_r4_131;
    Character *temp_r4_203;
    Character *temp_r6_171;
    f32 temp_f31_247;
    f32 var_f1_271;
    f64 temp_f0_189;
    u32 *temp_r4_142;
    u32 *temp_r4_173;
    u8 var_r30_118;
    u8 var_r30_137;
    u8 var_r30_97;
    u8 var_r5_172;

    temp_r3_93 = this->unk10;
    if (temp_r3_93 != NULL) {
        var_r30_97 = 0;
        if (((u8) M2C_FIELD(temp_r3_93, u8 *, 0x48) == 2) || (temp_r3_93->unk40.Get() != NULL)) {
            var_r30_97 = 1;
        }
        if (var_r30_97 == 0) {
            goto block_5;
        }
        ActivateIfInactive();
        temp_r3_117 = this->unkC;
        var_r30_118 = 0;
        if (((u8) temp_r3_117->unk908 == 2) || (((TargetContext *) &temp_r3_117->unk900)->Get() != NULL)) {
            var_r30_118 = 1;
        }
        if (var_r30_118 != 0) {
            temp_r4_131 = this->unkC;
            ((AITargetData *) &temp_r4_131->unk8C0)->Update(*((MKVector3 *) &temp_r4_131->unk588));
        }
        temp_r29_136 = this->unkC;
        var_r30_137 = 0;
        if (temp_r29_136->HasAnimFinished() != 0) {
            temp_r4_142 = temp_r29_136->unkA50;
            if ((temp_r4_142 != NULL) && ((u32) *temp_r4_142 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_136, void **, 0x630), u32 *, 0x20))) {
                var_r30_137 = 1;
            }
        }
        if (var_r30_137 != 0) {
            temp_r3_154 = this->unkC;
            temp_r4_158 = temp_r3_154->unkA24->unk0;
            ((Enemy *) temp_r3_154)->SetAnim(temp_r4_158, (AnimTransition *) &temp_r4_158->unk20, 0.15f, 0U);
            this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
            EnableSB();
        } else {
            temp_r6_171 = this->unkC;
            var_r5_172 = 0;
            temp_r4_173 = temp_r6_171->unkA50;
            if ((temp_r4_173 != NULL) && ((u32) M2C_FIELD(temp_r4_173, u32 *, 0x20) == (u32) M2C_FIELD(M2C_FIELD(temp_r6_171, void **, 0x630), u32 *, 0x20))) {
                var_r5_172 = 1;
            }
            if (var_r5_172 != 0) {
                temp_f0_189 = M2C_FIELD(temp_r6_171, f64 *, 0x588) + M2C_FIELD(temp_r6_171, f64 *, 0x90);
                sp8 = temp_f0_189;
                sp18 = temp_f0_189;
                sp10 = temp_r6_171->unk588.unk4 + temp_r6_171->unk98;
                sp20 = (f64) sp10;
                if ((((Enemy *) this->unkC)->IsInsideEnemyRegion() == 0) || (temp_r4_203 = this->unkC, ((temp_r4_203->unk838.IsPointWithin(*((MKVector3 *) &temp_r4_203->unk588)) == 0) == 0))) {
                    this->unk8 = 3;
                } else {
                    temp_r3_214 = this->unkC;
                    if (M2C_FIELD(temp_r3_214->__vptr, u8 (**)(Character *, f64 *), 0x1C0)(temp_r3_214, &sp18) != 0) {
                        temp_r3_222 = this->unkC;
                        temp_r3_222->unk90 = 0.0f;
                        temp_r3_222->unk94 = 0.0f;
                        temp_r3_222->unk98 = 0.0f;
                        this->unkC->StopMovement(1U);
                        this->unk8 = 2;
                    } else if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk14) || (temp_r3_241 = this->unkC, temp_f31_247 = M2C_FIELD(temp_r3_241->__vptr, f32 (**)(Character *), 0x100)(temp_r3_241), ((((AITargetData *) &this->unkC->unk8C0)->GetDist() <= temp_f31_247) != 0))) {
                        this->unk8 = 2;
                    }
                }
                temp_r3_257 = this->unkC;
                if (((Enemy *) temp_r3_257)->CheckMeleeHit(temp_r3_257->unkA24, -1) != 0) {
                    ((Enemy *) this->unkC)->SetHitTarget(1U);
                    var_f1_271 = this->unk14 - M2C_FIELD(&gb, f32 *, 0x30C);
                    if (var_f1_271 > 0.0f) {

                    } else {
                        var_f1_271 = 0.0f;
                    }
                    if (var_f1_271 > 1.0f) {
                        this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.4f;
                    }
                }
            }
        }
        return this->unk8;
    }
block_5:
    this->unk8 = 3;
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_ShieldCharge::EnableSB() {
    AITargetData sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Character *temp_r3_314;
    Character *temp_r4_366;
    f64 temp_f0_325;
    f64 temp_f0_336;
    f64 temp_f0_351;
    f64 temp_f31_319;
    void *temp_r3_310;
    void *temp_r3_382;

    temp_r3_310 = this->unkC->unk638;
    M2C_FIELD(temp_r3_310, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_310, u8 *, 0x464) | 0x80);
    temp_r3_314 = this->unkC;
    temp_f31_319 = M2C_FIELD(temp_r3_314->__vptr, f64 (**)(Character *, M2C_UNK), 0x100)(temp_r3_314, 1);
    sp38.GetDir();
    temp_f0_325 = sp38.unk0 * temp_f31_319;
    sp28 = temp_f0_325;
    sp38.unk10 = temp_f0_325;
    sp30 = sp38.unk8 * (f32) temp_f31_319;
    sp38.unk18 = (f64) sp30;
    temp_f0_336 = temp_f0_325 * 5.304989477e-315;
    sp18 = temp_f0_336;
    sp38.unk20 = temp_f0_336;
    sp20 = (f32) sp38.unk18 * 2.0f;
    sp38.unk28 = (f64) sp20;
    ((AITargetData *) &sp38.unk30)->GetPos();
    temp_f0_351 = sp38.unk30 + sp38.unk20;
    sp8 = temp_f0_351;
    sp38.unk40 = temp_f0_351;
    sp10 = sp38.unk38 + (f32) sp38.unk28;
    sp38.unk40.unk8 = (f64) sp10;
    ((AITargetData *) &this->unkC->unk8C0)->Set(*((MKVector3 *) &sp38.unk40), 0U);
    temp_r4_366 = this->unkC;
    ((SB2 *) temp_r4_366->unk638)->SeekOn((AITargetData *) &temp_r4_366->unk8C0);
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(this->unk10);
    ((SB2 *) this->unkC->unk638)->WallAvoidanceOn();
    ((SB2 *) this->unkC->unk638)->ContainmentOn();
    temp_r3_382 = this->unkC->unk638;
    M2C_FIELD(temp_r3_382, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_382, u8 *, 0x464) & ~0x10);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA24'
void EnemyGoal_ShieldCharge::Activate() {
    f64 sp8;
    AnimSequence *temp_r4_409;
    Character *temp_r3_407;
    Character *temp_r3_470;
    Character *temp_r4_459;
    Character *temp_r5_444;

    this->unk8 = 0;
    temp_r3_407 = this->unkC;
    temp_r4_409 = temp_r3_407->unkA24->unk0;
    if ((u32) temp_r4_409->unk0 != 0) {
        ((Enemy *) temp_r3_407)->SetAnim(temp_r4_409, (AnimTransition *) temp_r4_409, 0.15f, 0U);
    } else {
        ((Enemy *) temp_r3_407)->SetAnim(temp_r4_409, (AnimTransition *) &temp_r4_409->unk20, 0.15f, 0U);
        this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        EnableSB();
    }
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    ((Enemy *) this->unkC)->SetWalkMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    ((AITargetData *) &sp8)->GetDir();
    temp_r5_444 = this->unkC;
    M2C_FIELD(temp_r5_444, f64 *, 0xE0) = sp8;
    M2C_FIELD(temp_r5_444, f64 *, 0xE8) = sp10;
    temp_r5_444->unk6B5 |= 0x40;
    ((Enemy *) this->unkC)->SetRunMovementSpeed(1U);
    this->unkC->unk690 = 0.25f;
    temp_r4_459 = this->unkC;
loop_5:
    if ((u32) *temp_r4_459->unkA1C != 0U) {
        temp_r4_459->unkA1C += 4;
        goto loop_5;
    }
    temp_r3_470 = this->unkC;
    if (temp_r3_470->unkA24->unk38 & 0x40000000) {
        ((Enemy *) temp_r3_470)->SetInvulnerableToMeleeAttacks(1U, 1U);
        ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA5C'
void EnemyGoal_ShieldBlock::Terminate() {
    Character *temp_r4_493;
    void *temp_r5_494;

    temp_r4_493 = this->unkC;
    temp_r5_494 = temp_r4_493->unkA5C;
    if ((temp_r5_494 != NULL) && ((u32) M2C_FIELD(temp_r5_494, u32 *, 8) != 0U)) {
        M2C_FIELD(temp_r5_494, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r5_494, u8 *, 0x10) & ~0x80) | ((temp_r4_493->unkB08 << 7) & 0x80));
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkAB8'
u8 EnemyGoal_ShieldBlock::Update() {
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Character *temp_r28_714;
    Character *temp_r28_770;
    Character *temp_r29_591;
    Character *temp_r3_544;
    Character *temp_r3_567;
    Character *temp_r3_732;
    Character *temp_r3_743;
    Character *temp_r3_791;
    Character *temp_r4_577;
    f32 temp_f31_620;
    f64 temp_f0_624;
    u32 *temp_r4_720;
    u32 *temp_r4_733;
    u32 *temp_r4_744;
    u32 *temp_r4_776;
    u32 temp_r6_745;
    u8 temp_r5_759;
    u8 var_r0_675;
    u8 var_r30_524;
    u8 var_r30_595;
    u8 var_r30_715;
    u8 var_r30_771;
    u8 var_r3_697;
    u8 var_r4_691;
    void *temp_r28_590;
    void *temp_r3_520;
    void *temp_r3_641;
    void *temp_r5_692;

    temp_r3_520 = this->unk10;
    if (temp_r3_520 != NULL) {
        var_r30_524 = 0;
        if (((u8) M2C_FIELD(temp_r3_520, u8 *, 0x48) == 2) || (((TargetContext *) (((u8 *) temp_r3_520) + 0x40))->Get() != NULL)) {
            var_r30_524 = 1;
        }
        if (var_r30_524 == 0) {
            goto block_5;
        }
        ActivateIfInactive();
        temp_r3_544 = this->unkC;
        if ((temp_r3_544->unkAB8 > 0.8f) && ((u8) this->unk1C == 0) && ((u8) this->unk1D == 0)) {
            temp_r3_544->unk684 = 1.5707964f;
            this->unk1C = 1;
        }
        if (((u8) this->unk1C != 0) || ((u8) this->unk1D != 0)) {
            temp_r3_567 = this->unkC;
            if ((u32) M2C_FIELD(M2C_FIELD(temp_r3_567, void **, 0x630), u32 *, 0x20) != (u32) M2C_FIELD(temp_r3_567->unkA50, u32 *, 0x40)) {
                ((AITargetData *) &sp98)->GetDir();
                temp_r4_577 = this->unkC;
                M2C_FIELD(temp_r4_577, f64 *, 0xE0) = sp98;
                M2C_FIELD(temp_r4_577, f64 *, 0xE8) = spA0;
                temp_r4_577->unk6B5 |= 0x40;
            }
        }
        if ((u8) this->unk1D != 0) {
            temp_r28_590 = this->unk10;
            temp_r29_591 = this->unkC;
            if (temp_r28_590 != NULL) {
                var_r30_595 = 0;
                if (((u8) M2C_FIELD(temp_r28_590, u8 *, 0x48) == 2) || (((TargetContext *) (((u8 *) temp_r28_590) + 0x40))->Get() != NULL)) {
                    var_r30_595 = 1;
                }
                if (var_r30_595 != 0) {
                    ((AITargetData *) &sp78)->GetDir();
                    temp_f31_620 = (sp80 * temp_r29_591->unkF8) + ((sp78 * temp_r29_591->unkF0) + (sp7C * temp_r29_591->unkF4));
                    ((AITargetData *) &sp68)->GetDir();
                    temp_f0_624 = sp68 * (f64) temp_f31_620;
                    sp28 = temp_f0_624;
                    sp58 = temp_f0_624;
                    sp30 = sp70 * temp_f31_620;
                    sp60 = (f64) sp30;
                    ((AITargetData *) &sp48)->GetDir();
                    sp18 = sp48 - sp58;
                    temp_r3_641 = temp_r29_591->unk8;
                    sp20 = sp50 - (f32) sp60;
                    sp10 = -M2C_FIELD(temp_r3_641, f32 *, 0x28);
                    sp8 = -M2C_FIELD(temp_r3_641, f32 *, 0x20);
                    spC = -M2C_FIELD(temp_r3_641, f32 *, 0x24);
                    sp38 = sp18;
                    sp40 = (f64) sp20;
                    sp88 = (f64) sp8;
                    sp90 = (f64) sp10;
                    var_r0_675 = (((f32) sp90 * (f32) sp40) + (((f32) sp88 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4))))) > _table_sinf(1.8849556f);
                } else {
                    goto block_21;
                }
            } else {
block_21:
                var_r0_675 = 0;
            }
            if (var_r0_675 != 0) {
                this->unk1D = 0;
            }
        }
        if (this->unkC->HasAnimFinished() == 0) {
            var_r4_691 = 0;
            temp_r5_692 = M2C_FIELD(this->unkC, void **, 0x630);
            if (((u32) M2C_FIELD(temp_r5_692, u32 *, 0x2C) >> 1U) & 1) {
                var_r3_697 = 0;
                if ((M2C_FIELD(temp_r5_692, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_692, s32 *, 0x44) > 1)) {
                    var_r3_697 = 1;
                }
                if (var_r3_697 != 0) {
                    var_r4_691 = 1;
                }
            }
            if (var_r4_691 != 0) {
                goto block_32;
            }
        } else {
block_32:
            temp_r28_714 = this->unkC;
            var_r30_715 = 0;
            if (temp_r28_714->HasAnimFinished() != 0) {
                temp_r4_720 = temp_r28_714->unkA50;
                if ((temp_r4_720 != NULL) && ((u32) *temp_r4_720 == (u32) M2C_FIELD(M2C_FIELD(temp_r28_714, void **, 0x630), u32 *, 0x20))) {
                    var_r30_715 = 1;
                }
            }
            if ((var_r30_715 != 0) && (temp_r3_732 = this->unkC, temp_r4_733 = temp_r3_732->unkA50, (((u32) M2C_FIELD(temp_r4_733, u32 *, 0x20) == 0U) == 0))) {
                ((Enemy *) temp_r3_732)->SetAnim((AnimSequence *) temp_r4_733, (AnimTransition *) (temp_r4_733 + 0x20), 0.0f, 0U);
            } else {
                temp_r3_743 = this->unkC;
                temp_r4_744 = temp_r3_743->unkA50;
                temp_r6_745 = M2C_FIELD(temp_r4_744, u32 *, 0x40);
                if ((temp_r6_745 != 0U) && ((u32) M2C_FIELD(M2C_FIELD(temp_r3_743, void **, 0x630), u32 *, 0x20) != temp_r6_745) && ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk14) || (temp_r5_759 = temp_r3_743->unkB08, ((((temp_r5_759 >> 1U) & 1) == 0) == 0)) || (temp_r5_759 & 1))) {
                    ((Enemy *) temp_r3_743)->SetAnim((AnimSequence *) temp_r4_744, (AnimTransition *) (temp_r4_744 + 0x40), 0.0f, 0U);
                }
            }
            temp_r28_770 = this->unkC;
            var_r30_771 = 0;
            if (temp_r28_770->HasAnimFinished() != 0) {
                temp_r4_776 = temp_r28_770->unkA50;
                if ((temp_r4_776 != NULL) && ((u32) M2C_FIELD(temp_r4_776, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r28_770, void **, 0x630), u32 *, 0x20))) {
                    var_r30_771 = 1;
                }
            }
            if (var_r30_771 != 0) {
                this->unk8 = 2;
            }
        }
        temp_r3_791 = this->unkC;
        if ((((u8) temp_r3_791->unkB08 >> 4U) & 1) && (((Enemy *) temp_r3_791)->CheckMeleeHit(temp_r3_791->unkA24, -1) != 0)) {
            ((Enemy *) this->unkC)->SetHitTarget(1U);
        }
        return this->unk8;
    }
block_5:
    this->unk8 = 2;
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkB08'
void EnemyGoal_ShieldBlock::Activate() {
    f64 sp8;
    AnimSequence *temp_r4_856;
    Character *temp_r3_828;
    Character *temp_r3_854;
    Character *temp_r3_869;
    Character *temp_r3_873;
    Character *temp_r4_843;
    Character *temp_r5_836;
    f32 temp_f0_876;
    f32 var_f2_874;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    temp_r3_828 = this->unkC;
    temp_r3_828->unkB08 &= ~1;
    this->unkC->StopMovement(1U);
    temp_r5_836 = this->unkC;
    temp_r5_836->unk684 = temp_r5_836->unkA38->unk15C;
    ((AITargetData *) &sp8)->GetDir();
    temp_r4_843 = this->unkC;
    M2C_FIELD(temp_r4_843, f64 *, 0xE0) = sp8;
    M2C_FIELD(temp_r4_843, f64 *, 0xE8) = sp10;
    temp_r4_843->unk6B5 |= 0x40;
    temp_r3_854 = this->unkC;
    temp_r4_856 = temp_r3_854->unkA24->unk0;
    ((Enemy *) temp_r3_854)->SetAnim(temp_r4_856, (AnimTransition *) temp_r4_856, 0.15f, 0U);
    this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk18;
    this->unkC->unkA7C = 0.0f;
    temp_r3_869 = this->unkC;
    temp_r3_873 = this->unkC;
    var_f2_874 = 0.0f;
    temp_f0_876 = temp_r3_873->unkAB8 - temp_r3_869->unkA38->GetEnemyAttackSetting((EnemySettingType) 8, temp_r3_869->unkA24);
    if (var_f2_874 > temp_f0_876) {

    } else {
        var_f2_874 = temp_f0_876;
    }
    temp_r3_873->unkAB8 = var_f2_874;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA5C'
void EnemyGoal_Block::Terminate() {
    Character *temp_r4_894;
    void *temp_r5_895;

    temp_r4_894 = this->unkC;
    temp_r5_895 = temp_r4_894->unkA5C;
    if ((temp_r5_895 != NULL) && ((u32) M2C_FIELD(temp_r5_895, u32 *, 8) != 0U)) {
        M2C_FIELD(temp_r5_895, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r5_895, u8 *, 0x10) & ~0x80) | ((temp_r4_894->unkB08 << 7) & 0x80));
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 EnemyGoal_Block::Update() {
    Character *temp_r29_1004;
    Character *temp_r29_948;
    Character *temp_r3_1025;
    Character *temp_r3_966;
    Character *temp_r3_977;
    u32 *temp_r4_1010;
    u32 *temp_r4_954;
    u32 *temp_r4_967;
    u32 *temp_r4_978;
    u32 temp_r6_979;
    u8 temp_r5_993;
    u8 var_r30_1005;
    u8 var_r30_949;
    u8 var_r3_931;
    u8 var_r4_925;
    void *temp_r5_926;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_925 = 0;
        temp_r5_926 = M2C_FIELD(this->unkC, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r5_926, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_931 = 0;
            if ((M2C_FIELD(temp_r5_926, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_926, s32 *, 0x44) > 1)) {
                var_r3_931 = 1;
            }
            if (var_r3_931 != 0) {
                var_r4_925 = 1;
            }
        }
        if (var_r4_925 != 0) {
            goto block_8;
        }
    } else {
block_8:
        temp_r29_948 = this->unkC;
        var_r30_949 = 0;
        if (temp_r29_948->HasAnimFinished() != 0) {
            temp_r4_954 = temp_r29_948->unkA50;
            if ((temp_r4_954 != NULL) && ((u32) *temp_r4_954 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_948, void **, 0x630), u32 *, 0x20))) {
                var_r30_949 = 1;
            }
        }
        if ((var_r30_949 != 0) && (temp_r3_966 = this->unkC, temp_r4_967 = temp_r3_966->unkA50, (((u32) M2C_FIELD(temp_r4_967, u32 *, 0x20) == 0U) == 0))) {
            ((Enemy *) temp_r3_966)->SetAnim((AnimSequence *) temp_r4_967, (AnimTransition *) (temp_r4_967 + 0x20), 0.0f, 0U);
        } else {
            temp_r3_977 = this->unkC;
            temp_r4_978 = temp_r3_977->unkA50;
            temp_r6_979 = M2C_FIELD(temp_r4_978, u32 *, 0x40);
            if ((temp_r6_979 != 0U) && ((u32) M2C_FIELD(M2C_FIELD(temp_r3_977, void **, 0x630), u32 *, 0x20) != temp_r6_979) && ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk14) || (temp_r5_993 = temp_r3_977->unkB08, ((((temp_r5_993 >> 1U) & 1) == 0) == 0)) || (temp_r5_993 & 1))) {
                ((Enemy *) temp_r3_977)->SetAnim((AnimSequence *) temp_r4_978, (AnimTransition *) (temp_r4_978 + 0x40), 0.0f, 0U);
            }
        }
        temp_r29_1004 = this->unkC;
        var_r30_1005 = 0;
        if (temp_r29_1004->HasAnimFinished() != 0) {
            temp_r4_1010 = temp_r29_1004->unkA50;
            if ((temp_r4_1010 != NULL) && ((u32) M2C_FIELD(temp_r4_1010, u32 *, 0x40) == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1004, void **, 0x630), u32 *, 0x20))) {
                var_r30_1005 = 1;
            }
        }
        if (var_r30_1005 != 0) {
            this->unk8 = 2;
        }
    }
    temp_r3_1025 = this->unkC;
    if ((((u8) temp_r3_1025->unkB08 >> 4U) & 1) && (((Enemy *) temp_r3_1025)->CheckMeleeHit(temp_r3_1025->unkA24, -1) != 0)) {
        ((Enemy *) this->unkC)->SetHitTarget(1U);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_Block::Activate() {
    f64 sp8;
    AnimSequence *temp_r4_1087;
    Character *temp_r3_1059;
    Character *temp_r3_1085;
    Character *temp_r3_1097;
    Character *temp_r3_1101;
    Character *temp_r4_1074;
    Character *temp_r5_1067;
    f32 temp_f0_1104;
    f32 var_f2_1102;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    temp_r3_1059 = this->unkC;
    temp_r3_1059->unkB08 &= ~1;
    this->unkC->StopMovement(1U);
    temp_r5_1067 = this->unkC;
    temp_r5_1067->unk684 = temp_r5_1067->unkA38->unk15C;
    ((AITargetData *) &sp8)->GetDir();
    temp_r4_1074 = this->unkC;
    M2C_FIELD(temp_r4_1074, f64 *, 0xE0) = sp8;
    M2C_FIELD(temp_r4_1074, f64 *, 0xE8) = sp10;
    temp_r4_1074->unk6B5 |= 0x40;
    temp_r3_1085 = this->unkC;
    temp_r4_1087 = temp_r3_1085->unkA24->unk0;
    ((Enemy *) temp_r3_1085)->SetAnim(temp_r4_1087, (AnimTransition *) temp_r4_1087, 0.15f, 0U);
    this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk18;
    temp_r3_1097 = this->unkC;
    temp_r3_1101 = this->unkC;
    var_f2_1102 = 0.0f;
    temp_f0_1104 = temp_r3_1101->unkAB8 - temp_r3_1097->unkA38->GetEnemyAttackSetting((EnemySettingType) 8, temp_r3_1097->unkA24);
    if (var_f2_1102 > temp_f0_1104) {

    } else {
        var_f2_1102 = temp_f0_1104;
    }
    temp_r3_1101->unkAB8 = var_f2_1102;
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r3_1127'
void EnemyGoal_DefensiveMode::Terminate() {
    CharacterBreathFX *temp_r5_1128;
    Enemy *temp_r3_1127;

    temp_r3_1127 = this->unkC;
    temp_r5_1128 = temp_r3_1127->unkA0C;
    if (temp_r5_1128 != NULL) {
        this->unkC->unkA58 = M2C_FIELD(&gb, f32 *, 0x30C) + ((EnemyDescriptor *) temp_r3_1127->unkA20)->GetEnemyAttackSetting((EnemySettingType) 6, (EnemyAttack *) temp_r5_1128);
    }
    this->unkC->unkA0C = NULL;
    M2C_FIELD(this->unkC, s8 *, 0x6F8) = 0;
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_DefensiveMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r3_1188'
void EnemyGoal_DefensiveMode::Activate() {
    Enemy *temp_r3_1188;
    Enemy *temp_r4_1193;
    Goal<Enemy> *temp_r3_1230;
    Goal<Enemy> *temp_r4_1242;
    Goal<Enemy> *temp_r6_1266;
    MKMaterial *temp_r3_1205;
    s32 temp_r3_1224;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_1188 = this->unkC;
    M2C_FIELD(temp_r3_1188, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_1188, u8 *, 0xB08) & ~1);
    temp_r4_1193 = this->unkC;
loop_2:
    if ((void *) temp_r4_1193->unkA04->__vptr != NULL) {
        temp_r4_1193->unkA04 = (CharacterZapFX *) &temp_r4_1193->unkA04->unk4;
        goto loop_2;
    }
    temp_r3_1205 = this->unkC->unkA18;
    if (temp_r3_1205 != NULL) {
        ((AttackSweepData *) temp_r3_1205)->SetDefaults();
    }
    if (((CharacterBreathFX *) this->unkC->unkA0C != NULL) || (this->unkC->SelectDefensiveAttack(this->unk20->GetDist(), 0x1FFF0000U) != 0)) {
        temp_r3_1224 = M2C_FIELD(this->unkC->unkA0C, s32 *, 0x38);
        if (temp_r3_1224 & 0x10000) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
            temp_r3_1230 = this->unk24;
            M2C_FIELD(temp_r3_1230, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r3_1230, f32 *, 0x18) = 1.0f;
            return;
        }
        if (temp_r3_1224 & 0x20000) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
            temp_r4_1242 = this->unk28;
            M2C_FIELD(temp_r4_1242, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r4_1242, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_1242, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r4_1242, f32 *, 0x18) = 1.0f;
            return;
        }
        if (temp_r3_1224 & 0x40000) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
            M2C_FIELD(this->unk2C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            temp_r6_1266 = this->unk30;
            M2C_FIELD(temp_r6_1266, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r6_1266, s32 *, 0x14) = 5;
            M2C_FIELD(temp_r6_1266, s32 *, 0x18) = 0xE;
            M2C_FIELD(temp_r6_1266, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r6_1266, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1266, u8 *, 0x20) & ~0x40);
        }
    }
}
#endif

void EnemyGoal_DefensiveMode::Deinit() {
    Goal<Enemy> *temp_r3_1291;
    Goal<Enemy> *temp_r3_1296;
    Goal<Enemy> *temp_r3_1301;
    Goal<Enemy> *temp_r3_1306;
    MKHeap *temp_r3_1329;
    void **temp_r3_1311;
    void *temp_r31_1326;

    temp_r3_1291 = this->unk24;
    temp_r3_1291->Deinit();
    temp_r3_1296 = this->unk28;
    temp_r3_1296->Deinit();
    temp_r3_1301 = this->unk2C;
    temp_r3_1301->Deinit();
    temp_r3_1306 = this->unk30;
    temp_r3_1306->Deinit();
    temp_r3_1311 = this->unk34;
    M2C_FIELD(*temp_r3_1311, M2C_UNK (**)(void **), 0xC)(temp_r3_1311);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    temp_r31_1326 = this->unk1C;
    if (temp_r31_1326 != NULL) {
        temp_r3_1329 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1329 != NULL) {
            ((MKHeap *) (temp_r3_1329->Current()))->Free(temp_r31_1326, NULL, 0);
        } else {
            free(temp_r31_1326);
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
void EnemyGoal_DefensiveMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_1503;
    Goal<Enemy> *temp_r4_1514;
    Goal<Enemy> *temp_r4_1525;
    Goal<Enemy> *temp_r4_1536;
    MKHeap *temp_r3_1476;
    void **temp_r4_1547;
    void *var_r3_1483;

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
        operator new(0x20U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
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
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
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
        temp_r3_1476 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1476 != NULL) {
            var_r3_1483 = ((MKHeap *) (temp_r3_1476->Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_1483 = malloc(0x10);
        }
        this->unk1C = var_r3_1483;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x4F;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_1503 = this->unk24;
    M2C_FIELD(temp_r4_1503, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1503, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1503, s32 *, 4) = 0x50;
    if ((Enemy *) M2C_FIELD(temp_r4_1503, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1503, s8 *, 9) = 1;
    }
    temp_r4_1514 = this->unk28;
    M2C_FIELD(temp_r4_1514, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1514, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1514, s32 *, 4) = 0x51;
    if ((Enemy *) M2C_FIELD(temp_r4_1514, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1514, s8 *, 9) = 1;
    }
    temp_r4_1525 = this->unk2C;
    M2C_FIELD(temp_r4_1525, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1525, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1525, s32 *, 4) = 0x52;
    if ((Enemy *) M2C_FIELD(temp_r4_1525, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1525, s8 *, 9) = 1;
    }
    temp_r4_1536 = this->unk30;
    M2C_FIELD(temp_r4_1536, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1536, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1536, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_1536, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1536, s8 *, 9) = 1;
    }
    temp_r4_1547 = this->unk34;
    M2C_FIELD(temp_r4_1547, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1547, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_1547, s32 *, 4) = 0x27;
    if ((Enemy *) M2C_FIELD(temp_r4_1547, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1547, s8 *, 9) = 1;
    }
}
#endif

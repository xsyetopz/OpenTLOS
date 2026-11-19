#include "spyro/source/SpyroStrafeState.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroTools.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal operand
static M2C_UNK lit_728;                                /* unable to generate initializer: unknown type */
SpyroStrafeState states__16SpyroStrafeState;        /* unable to generate initializer: confusing struct layout */

void SpyroStrafeState::InputOverride::Set(KDInput *arg1) {
    f32 var_f1_46;
    f32 var_f1_68;
    u8 var_r3_34;
    u8 var_r3_56;

    M2C_FIELD(this, SpyroStrafeState::InputOverride *, 0) = 1;
    var_r3_34 = 0;
    if (((u8) arg1->unk5 != 0) || ((u8) arg1->unk4 != 0)) {
        var_r3_34 = 1;
    }
    if (var_r3_34 != 0) {
        var_f1_46 = 0.0f;
    } else {
        var_f1_46 = MKInput_GetState(0x11, (MKInputDevices) arg1->unk0, NULL, NULL);
    }
    M2C_FIELD(this, f32 *, 4) = var_f1_46;
    var_r3_56 = 0;
    if (((u8) arg1->unk5 != 0) || ((u8) arg1->unk4 != 0)) {
        var_r3_56 = 1;
    }
    if (var_r3_56 != 0) {
        var_f1_68 = 0.0f;
    } else {
        var_f1_68 = MKInput_GetState(0x10, (MKInputDevices) arg1->unk0, NULL, NULL);
    }
    M2C_FIELD(this, f32 *, 8) = var_f1_68;
    M2C_FIELD(this, f32 *, 0xC) = arg1->GetLeftMag();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'InputModifier *' to
void SpyroStrafeState::SetDesiredVelocity() {
    f32 spDC;
    f32 spD8;
    f32 spD4;
    u8 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_272;
    f32 temp_f2_130;
    f32 var_f31_248;
    f32 var_f4_121;
    f32 var_f5_177;
    f64 temp_f0_149;
    f64 temp_f1_182;
    f64 temp_f1_188;
    f64 temp_f1_192;
    s32 temp_r3_211;
    s32 var_r0_221;
    u8 temp_r0_102;

    temp_r0_102 = this->unk38;
    if (temp_r0_102 != 0) {
        spD0 = temp_r0_102;
        spD4 = this->unk3C;
        spD8 = this->unk40;
        spDC = this->unk44;
    } else {
        ((SpyroStrafeState::InputOverride *) &spD0)->Set(this->unk10->GetInput());
    }
    var_f4_121 = 0.0f;
    if (spDC != 0.0f) {
        sp60 = M2C_FIELD(this, f64 *, 0x28) * (f64) spD8;
        temp_f2_130 = this->unk30;
        sp50 = temp_f2_130;
        sp54 = 0.0f;
        sp68 = temp_f2_130 * spD8;
        sp58 = -this->unk28;
        sp90 = (f64) sp50;
        spC0 = sp60;
        spC8 = (f64) sp68;
        sp98 = (f64) sp58;
        temp_f0_149 = sp90 * (f64) spD4;
        sp40 = temp_f0_149;
        spB0 = temp_f0_149;
        sp48 = (f32) sp98 * spD4;
        spB8 = (f64) sp48;
        sp30 = spC0 + temp_f0_149;
        sp80 = sp30;
        sp38 = (f32) spC8 + (f32) spB8;
        sp88 = (f64) sp38;
        var_f5_177 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + ((*(f32 *) ((u8 *) &sp80 + 0x4)) * (*(f32 *) ((u8 *) &sp80 + 0x4))));
        if (var_f5_177 > 1e-12f) {
            if (var_f5_177 > 0.0f) {
                temp_f1_182 = __frsqrte(var_f5_177);
                temp_f1_188 = 0.5 * temp_f1_182 * -(((f64) var_f5_177 * (temp_f1_182 * temp_f1_182)) - 3.0);
                temp_f1_192 = 0.5 * temp_f1_188 * -(((f64) var_f5_177 * (temp_f1_188 * temp_f1_188)) - 3.0);
                var_f5_177 = (f32) ((f64) var_f5_177 * (0.5 * temp_f1_192 * -(((f64) var_f5_177 * (temp_f1_192 * temp_f1_192)) - 3.0)));
            } else if (var_f5_177 < M2C_BITWISE(f32, 0.0)) {
                var_f5_177 = __float_nan;
            } else {
                sp8 = var_f5_177;
                temp_r3_211 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_211) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_221 = 1;
                    } else {
                        var_r0_221 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_221 = 5;
                    } else {
                        var_r0_221 = 3;
                    }
                    break;
                default:
                    var_r0_221 = 4;
                    break;
                }
                if (var_r0_221 == 1) {
                    var_f5_177 = __float_nan;
                }
            }
            var_f4_121 = 1.0f / var_f5_177;
        }
        var_f31_248 = 0.0f;
        sp24 = (*(f32 *) ((u8 *) &sp80 + 0x4)) * var_f4_121;
        sp20 = (f32) sp80 * var_f4_121;
        sp28 = (f32) sp88 * var_f4_121;
        spA0 = (f64) sp20;
        spA8 = (f64) sp28;
        if ((((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + ((*(f32 *) ((u8 *) &spA0 + 0x4)) * (*(f32 *) ((u8 *) &spA0 + 0x4))))) != 0.0f) {
            temp_f1_272 = ((f32) spA8 * this->unk30) + (((f32) spA0 * this->unk28) + ((*(f32 *) ((u8 *) &spA0 + 0x4)) * this->unk2C));
            if ((temp_f1_272 > 0.5f) || (temp_f1_272 < -0.5f)) {
                var_f31_248 = 0.75f * (750.0f * spDC);
            } else {
                var_f31_248 = 750.0f * spDC;
            }
        }
        sp10 = spA0 * (f64) var_f31_248;
        sp18 = (f32) spA8 * var_f31_248;
        sp70 = sp10;
        sp78 = (f64) sp18;
        this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp70), 3800.0f);
        return;
    }
    this->unk10->SetDesiredVelocityHoriz(MKVector3::zero, 3800.0f);
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroStrafeState::UpdateCircleTargetMovement() {
    f64 sp88;
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    InputModifier *temp_r3_333;
    Spyro *temp_r3_361;
    f32 var_f4_436;
    f32 var_f5_453;
    f64 temp_f0_434;
    f64 temp_f1_458;
    f64 temp_f1_464;
    f64 temp_f1_468;
    s32 temp_r3_487;
    s32 var_r0_497;
    s32 var_r30_354;
    s32 var_r3_346;
    u8 var_r4_335;
    void *temp_r3_373;
    void *temp_r3_423;
    void *temp_r4_362;
    void *temp_r5_422;

    temp_r3_333 = this->unk10->GetInput();
    var_r4_335 = 0;
    if (((u8) temp_r3_333->unk5 != 0) || ((u8) temp_r3_333->unk4 != 0)) {
        var_r4_335 = 1;
    }
    if (var_r4_335 != 0) {
        var_r3_346 = 0;
    } else {
        var_r3_346 = MKInput_Pressed(0xB, (MKInputDevices) temp_r3_333->unk0);
    }
    var_r30_354 = var_r3_346;
    if ((u8) var_r3_346 == 0) {
        ((SpyroTargetList *) &this->unk10->unkB90)->GetCurrentTarget();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            temp_r3_361 = this->unk10;
            temp_r4_362 = temp_r3_361->unk8;
            sp50 = M2C_FIELD(temp_r4_362, f64 *, 0x30);
            sp58 = M2C_FIELD(temp_r4_362, f64 *, 0x38);
            ((SpyroTargetList *) &temp_r3_361->unkB90)->GetCurrentTarget();
            temp_r3_373 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
            sp60 = M2C_FIELD(temp_r3_373, f64 *, 0x30);
            sp68 = M2C_FIELD(temp_r3_373, f64 *, 0x38);
            var_r30_354 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        }
    }
    ((SpyroTargetList *) &this->unk10->unkB90)->GetCurrentTarget();
    if (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) || ((u8) var_r30_354 != 0)) {
        this->unk10->SelectStrafeTarget((u8) var_r30_354);
    }
    ((SpyroTargetList *) &this->unk10->unkB90)->GetCurrentTarget();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        ((SpyroTargetList *) &this->unk10->unkB90)->GetCurrentTarget();
        temp_r5_422 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
        temp_r3_423 = this->unk10->unk8;
        sp80 = M2C_FIELD(temp_r5_422, f64 *, 0x30);
        sp40 = M2C_FIELD(temp_r3_423, f64 *, 0x30);
        sp88 = M2C_FIELD(temp_r5_422, f64 *, 0x38);
        sp48 = M2C_FIELD(temp_r3_423, f64 *, 0x38);
        temp_f0_434 = sp80 - sp40;
        sp20 = temp_f0_434;
        var_f4_436 = 0.0f;
        sp70 = temp_f0_434;
        (*(f32 *) ((u8 *) &sp68 + 0xc)) = 0.0f;
        sp28 = (f32) sp88 - (f32) sp48;
        sp78 = (f64) sp28;
        var_f5_453 = ((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (0.0f * 0.0f));
        if (var_f5_453 > 0.000001f) {
            if (var_f5_453 > 0.0f) {
                temp_f1_458 = __frsqrte(var_f5_453);
                temp_f1_464 = 0.5 * temp_f1_458 * -(((f64) var_f5_453 * (temp_f1_458 * temp_f1_458)) - 3.0);
                temp_f1_468 = 0.5 * temp_f1_464 * -(((f64) var_f5_453 * (temp_f1_464 * temp_f1_464)) - 3.0);
                var_f5_453 = (f32) ((f64) var_f5_453 * (0.5 * temp_f1_468 * -(((f64) var_f5_453 * (temp_f1_468 * temp_f1_468)) - 3.0)));
            } else if (var_f5_453 < M2C_BITWISE(f32, 0.0)) {
                var_f5_453 = __float_nan;
            } else {
                sp8 = var_f5_453;
                temp_r3_487 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_487) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_497 = 1;
                    } else {
                        var_r0_497 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_497 = 5;
                    } else {
                        var_r0_497 = 3;
                    }
                    break;
                default:
                    var_r0_497 = 4;
                    break;
                }
                if (var_r0_497 == 1) {
                    var_f5_453 = __float_nan;
                }
            }
            var_f4_436 = 1.0f / var_f5_453;
        }
        sp70 = (f32) sp70 * var_f4_436;
        (*(f32 *) ((u8 *) &sp68 + 0xc)) *= var_f4_436;
        sp78 = (f32) sp78 * var_f4_436;
        ((SpyroRotation *) &this->unk10->unk3A0)->YawTowards(*((MKVector3 *) &sp70), 15.0f);
    }
    ((Matrix *) this->unk10->unk8)->ZAxis3();
    sp10 = -*M2C_ERROR(/* Read from unset register $r3 */);
    sp14 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
    sp18 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
    M2C_FIELD(this, f64 *, 0x28) = (f64) sp10;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    M2C_FIELD(this, f64 *, 0x30) = (f64) sp18;
    SetDesiredVelocity();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroStrafeState::SelectAnim() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp48;
    M2C_UNK sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r4_576;
    Spyro *temp_r4_589;
    Spyro *temp_r4_596;
    f32 temp_f0_638;
    f32 temp_f0_664;
    f32 temp_f5_631;
    f32 temp_f6_634;
    f32 temp_f7_636;
    s32 var_r31_591;

    temp_r4_576 = this->unk10;
    if (((u32) this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 != (u32) M2C_FIELD(temp_r4_576->unkB4, u32 *, 0x8C)) || (temp_r4_576->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1)) {
        temp_r4_589 = this->unk10;
        var_r31_591 = -1;
        M2C_FIELD(temp_r4_589->__vptr, M2C_UNK (**)(M2C_UNK *, Spyro *), 0xB0)(&sp38, temp_r4_589);
        temp_r4_596 = this->unk10;
        M2C_FIELD(temp_r4_596->__vptr, M2C_UNK (**)(f32 *, Spyro *), 0xB0)(&sp48, temp_r4_596);
        sp18 = sp48;
        sp1C = 0.0f;
        sp20 = sp40;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))))) != 0.0f) {
            Normalise(sp28);
            sp68 = M2C_BITWISE(f64, sp28);
            sp70 = (f64) sp28.unk8;
            temp_f5_631 = this->unk2C;
            temp_f6_634 = this->unk28;
            temp_f7_636 = this->unk30;
            temp_f0_638 = ((f32) sp70 * temp_f7_636) + (((f32) sp68 * temp_f6_634) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * temp_f5_631));
            if (temp_f0_638 > 0.5f) {
                var_r31_591 = 0xC;
            } else if (temp_f0_638 < -0.5f) {
                var_r31_591 = 0xD;
            } else {
                sp8 = (f32) sp70;
                spC = 0.0f;
                sp10 = -(f32) sp68;
                sp58 = (f64) sp8;
                sp60 = (f64) sp10;
                temp_f0_664 = ((f32) sp60 * temp_f7_636) + (((f32) sp58 * temp_f6_634) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_f5_631));
                if (temp_f0_664 > 0.5f) {
                    var_r31_591 = 0xE;
                } else if (temp_f0_664 < -0.5f) {
                    var_r31_591 = 0xF;
                }
            }
        } else {
            var_r31_591 = 0xB;
        }
        if (var_r31_591 > -1) {
            this->unk10->SetAnim((u32) var_r31_591, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
u8 SpyroStrafeState::AnyToDodgeTranstion() {
    InputModifier *temp_r3_705;
    InputModifier *temp_r3_750;
    s32 var_r3_713;
    s32 var_r3_758;
    u8 var_r0_706;
    u8 var_r0_751;
    u8 var_r3_742;

    temp_r3_705 = this->unk10->GetInput();
    var_r0_706 = temp_r3_705->unk5;
    if (var_r0_706 == 0) {
        var_r0_706 = temp_r3_705->unk4;
    }
    if (var_r0_706 != 0) {
        var_r3_713 = 0;
    } else {
        var_r3_713 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_705->unk0);
    }
    if ((u8) var_r3_713 != 0) {
        if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() < 0.0f) {

        }
        var_r3_713 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
    }
    if ((u8) var_r3_713 != 0) {
        this->unk14.SetState(this, 2, 1U);
        var_r3_742 = 1;
    } else {
        var_r3_742 = 0;
    }
    if (var_r3_742 == 0) {
        temp_r3_750 = this->unk10->GetInput();
        var_r0_751 = temp_r3_750->unk5;
        if (var_r0_751 == 0) {
            var_r0_751 = temp_r3_750->unk4;
        }
        if (var_r0_751 != 0) {
            var_r3_758 = 0;
        } else {
            var_r3_758 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_750->unk0);
        }
        if ((u8) var_r3_758 != 0) {
            if (((InputModifier *) (this->unk10->GetInput()))->GetLeftY() < 0.0f) {

            }
            var_r3_758 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        }
        if ((u8) var_r3_758 != 0) {
            this->unk14.SetState(this, 3, 1U);
            return 1U;
        }
        var_r3_742 = 0;
        /* Duplicate return node #25. Try simplifying control flow for better match */
        return var_r3_742;
    }
    return var_r3_742;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroStrafeState::DodgeForwardBackTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_821;
    u8 var_r3_851;
    u8 var_r4_823;

    spC = 0;
    sp10 = 0x10;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    temp_r3_821 = this->unk10->GetInput();
    var_r4_823 = 0;
    if (((u8) temp_r3_821->unk5 != 0) || ((u8) temp_r3_821->unk4 != 0)) {
        var_r4_823 = 1;
    }
    if (var_r4_823 != 0) {

    } else {
        MKInput_GetState(0xA, (MKInputDevices) temp_r3_821->unk0, NULL, NULL);
    }
    var_r3_851 = this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, 4U, (MKMessage *) &sp8, 0U);
    if (var_r3_851 == 0) {
        this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0);
        var_r3_851 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        if (var_r3_851 != 0) {
            var_r3_851 = AnyToDodgeTranstion();
        }
    }
    if (var_r3_851 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk14.unk0 != 1)) {
            this->unk14.SetState(this, 1, 0U);
            return 1U;
        }
        var_r3_851 = 0;
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return var_r3_851;
    }
    return var_r3_851;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroStrafeState::DodgeForwardBackUpdate() {
    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk24 > 0.5f) {
        this->unk38 = 0;
        this->unk44 = 0.0f;
        this->unk40 = 0.0f;
        this->unk3C = 0.0f;
    }
    UpdateCircleTargetMovement();
    DodgeForwardBackTransition();
}
#endif

void SpyroStrafeState::DodgeForwardBackExit() {
    this->unk38 = 0;
    this->unk44 = 0.0f;
    this->unk40 = 0.0f;
    this->unk3C = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'InputModifier *' to
void SpyroStrafeState::DodgeForwardBackEnter() {
    u32 var_r4_958;

    ((SpyroStrafeState::InputOverride *) &this->unk38)->Set(this->unk10->GetInput());
    if (((InputModifier *) (this->unk10->GetInput()))->GetLeftY() > 0.0f) {
        var_r4_958 = 0x17;
    } else {
        var_r4_958 = 0x16;
    }
    this->unk10->SetAnim(var_r4_958, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroStrafeState::DodgeLeftRightTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_998;
    u8 var_r3_1028;
    u8 var_r4_1000;

    spC = 0;
    sp10 = 0x10;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    temp_r3_998 = this->unk10->GetInput();
    var_r4_1000 = 0;
    if (((u8) temp_r3_998->unk5 != 0) || ((u8) temp_r3_998->unk4 != 0)) {
        var_r4_1000 = 1;
    }
    if (var_r4_1000 != 0) {

    } else {
        MKInput_GetState(0xA, (MKInputDevices) temp_r3_998->unk0, NULL, NULL);
    }
    var_r3_1028 = this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, 4U, (MKMessage *) &sp8, 0U);
    if (var_r3_1028 == 0) {
        this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0);
        var_r3_1028 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        if (var_r3_1028 != 0) {
            var_r3_1028 = AnyToDodgeTranstion();
        }
    }
    if (var_r3_1028 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk14.unk0 != 1)) {
            this->unk14.SetState(this, 1, 0U);
            return 1U;
        }
        var_r3_1028 = 0;
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return var_r3_1028;
    }
    return var_r3_1028;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroStrafeState::DodgeLeftRightUpdate() {
    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk24 > 0.5f) {
        this->unk38 = 0;
        this->unk44 = 0.0f;
        this->unk40 = 0.0f;
        this->unk3C = 0.0f;
    }
    UpdateCircleTargetMovement();
    DodgeLeftRightTransition();
}
#endif

void SpyroStrafeState::DodgeLeftRightExit() {
    this->unk38 = 0;
    this->unk44 = 0.0f;
    this->unk40 = 0.0f;
    this->unk3C = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'InputModifier *' to
void SpyroStrafeState::DodgeLeftRightEnter() {
    u32 var_r4_1135;

    ((SpyroStrafeState::InputOverride *) &this->unk38)->Set(this->unk10->GetInput());
    if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() < 0.0f) {
        var_r4_1135 = 0x14;
    } else {
        var_r4_1135 = 0x15;
    }
    this->unk10->SetAnim(var_r4_1135, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroStrafeState::CircleTargetTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_1213;
    M2C_UNK var_r6_1270;
    u8 temp_r30_1184;
    u8 var_r30_1258;
    u8 var_r3_1185;
    u8 var_r4_1210;
    u8 var_r4_1215;

    spC = 0;
    sp10 = 0x10;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    temp_r30_1184 = this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 != M2C_FIELD(this->unk10->unkB4, s32 *, 0x8C);
    var_r3_1185 = AnyToDodgeTranstion();
    if (var_r3_1185 == 0) {
        ((SpyroTargetList *) &this->unk10->unkB90)->GetCurrentTarget();
        if (((u8) (M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0) && ((s32) this->unk14.unk0 != 0)) {
            this->unk14.SetState(this, 0, 0U);
            var_r3_1185 = 1;
        } else {
            var_r3_1185 = 0;
        }
    }
    if (var_r3_1185 == 0) {
        var_r4_1210 = temp_r30_1184;
        if (temp_r30_1184 != 0) {
            temp_r3_1213 = this->unk10->GetInput();
            var_r4_1215 = 0;
            if (((u8) temp_r3_1213->unk5 != 0) || ((u8) temp_r3_1213->unk4 != 0)) {
                var_r4_1215 = 1;
            }
            if (var_r4_1215 != 0) {

            } else {
                MKInput_GetState(0xA, (MKInputDevices) temp_r3_1213->unk0, NULL, NULL);
            }
            var_r4_1210 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
        }
        var_r3_1185 = this->unk10->TryChangeState(var_r4_1210, 4U, (MKMessage *) &sp8, 0U);
    }
    if (var_r3_1185 == 0) {
        this->unk10->LandToAirTransition(1U, 1U, 0U);
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        var_r30_1258 = M2C_FIELD(&gb, u8 *, 5);
        if (var_r30_1258 != 0) {
            var_r30_1258 = this->unk10->GetMeleeButtonState() != 0;
        }
        var_r6_1270 = 0x16C;
        if (this->unk10->GetMeleeButtonState() == 2) {
            var_r6_1270 = 0x17E;
        }
        this->unk10->TryChangeState(var_r30_1258, 0xBU, (SpyroStateMsg) var_r6_1270, 0U);
    }
}
#endif

void SpyroStrafeState::CircleTargetUpdate() {
    UpdateCircleTargetMovement();
    SelectAnim();
    CircleTargetTransition();
}

void SpyroStrafeState::CircleTargetExit() {

}

void SpyroStrafeState::CircleTargetEnter() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_1327;

    spC = 0;
    sp8 = 0x17;
    sp10 = 0xE;
    temp_r3_1327 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_1327, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_1327, &sp8, 0x17);
}

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroStrafeState::NoTargetTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_1380;
    M2C_UNK var_r6_1443;
    u8 var_r30_1431;
    u8 var_r3_1372;
    u8 var_r4_1382;

    spC = 0;
    sp10 = 0x10;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    this->unk10->SelectStrafeTarget(0U);
    if (((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) && ((s32) this->unk14.unk0 != 1)) {
        this->unk14.SetState(this, 1, 0U);
        var_r3_1372 = 1;
    } else {
        var_r3_1372 = 0;
    }
    if (var_r3_1372 == 0) {
        temp_r3_1380 = this->unk10->GetInput();
        var_r4_1382 = 0;
        if (((u8) temp_r3_1380->unk5 != 0) || ((u8) temp_r3_1380->unk4 != 0)) {
            var_r4_1382 = 1;
        }
        if (var_r4_1382 != 0) {

        } else {
            MKInput_GetState(0xA, (MKInputDevices) temp_r3_1380->unk0, NULL, NULL);
        }
        var_r3_1372 = this->unk10->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1, 4U, (MKMessage *) &sp8, 0U);
    }
    if (var_r3_1372 == 0) {
        this->unk10->IsAgainstMatID(2);
        if ((u8) (M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0) {
            this->unk10->LandToAirTransition(1U, 1U, 0U);
        }
    }
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        var_r30_1431 = M2C_FIELD(&gb, u8 *, 5);
        if (var_r30_1431 != 0) {
            var_r30_1431 = this->unk10->GetMeleeButtonState() != 0;
        }
        var_r6_1443 = 0x16C;
        if (this->unk10->GetMeleeButtonState() == 2) {
            var_r6_1443 = 0x17E;
        }
        this->unk10->TryChangeState(var_r30_1431, 0xBU, (SpyroStateMsg) var_r6_1443, 0U);
    }
}
#endif

#if 0 // DRAFT: function call 'Normalise(MKVector3)' does not match
void SpyroStrafeState::NoTargetUpdate() {
    MKVector3 sp18;
    MKVector3 sp8;

    if (((InputModifier *) (this->unk10->GetInput()))->GetRightX() != 0.0f) {
        KDMath_RotateVectorByYaw(sp8, 1.5707964f * gUpdateTimeDelta * ((InputModifier *) (this->unk10->GetInput()))->GetRightX());
        Normalise(sp18);
        M2C_FIELD(this, f64 *, 0x28) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(this, f64 *, 0x30) = (f64) sp18.unk8;
    }
    ((SpyroRotation *) &this->unk10->unk3A0)->YawTowards(*((MKVector3 *) &this->unk28), 15.0f);
    SetDesiredVelocity();
    SelectAnim();
    NoTargetTransition();
}
#endif

void SpyroStrafeState::NoTargetExit() {

}

void SpyroStrafeState::NoTargetEnter() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_1530;

    spC = 0;
    sp8 = 0x17;
    sp10 = 3;
    temp_r3_1530 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_1530, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_1530, &sp8, 0x17);
}

void SpyroStrafeState::ProcessAnimEvent(unsigned int arg0) {

}

#if 0 // DRAFT: illegal function definition
void SpyroStrafeState::Message(MKMessage *arg0) {

}
#endif

s32 SpyroStrafeState::Transition() {
    s32 var_r31_1561;

    var_r31_1561 = 0;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r31_1561 = 1;
    }
    return var_r31_1561;
}

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroStrafeState::Update() {
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    f64 temp_f0_1597;
    f64 temp_f1_1596;

    this->unk14.Update(this, 0);
    sp1C = 0;
    temp_f1_1596 = M2C_FIELD(this, f64 *, 0x28);
    temp_f0_1597 = M2C_FIELD(this, f64 *, 0x30);
    sp8 = temp_f1_1596;
    sp18 = 0x43E;
    sp20 = temp_f1_1596;
    sp28 = temp_f0_1597;
    sp10 = temp_f0_1597;
    M2C_FIELD(this->unk10->GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroStrafeState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1628;
    Spyro *temp_r4_1623;

    temp_r4_1623 = this->unk10;
    temp_r4_1623->unk428 |= 0x20000;
    temp_r3_1628 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43F;
    M2C_FIELD(temp_r3_1628->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: function call 'Normalise(MKVector3)' does not match
void SpyroStrafeState::Enter(SpyroStateMessages &arg0) {
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1740;
    Spyro *temp_r4_1659;
    Spyro *temp_r5_1655;
    f32 temp_f2_1682;
    f32 temp_f3_1681;
    f32 temp_f4_1679;
    void *temp_r5_1675;

    temp_r5_1655 = this->unk10;
    temp_r5_1655->unk428 |= 0x8000;
    temp_r4_1659 = this->unk10;
    temp_r4_1659->unk428 &= 0xFFFDFFFF;
    this->unk38 = 0;
    this->unk44 = 0.0f;
    this->unk40 = 0.0f;
    this->unk3C = 0.0f;
    if (this->unk10->IsPlayingStrafeAnim() != 0) {
        temp_r5_1675 = this->unk10->unk8;
        sp34 = 0.0f;
        temp_f4_1679 = -M2C_FIELD(temp_r5_1675, f32 *, 0x20);
        temp_f3_1681 = -M2C_FIELD(temp_r5_1675, f32 *, 0x24);
        temp_f2_1682 = -M2C_FIELD(temp_r5_1675, f32 *, 0x28);
        sp10 = temp_f4_1679;
        sp28 = temp_f2_1682;
        sp14 = temp_f3_1681;
        sp58 = (f64) sp28;
        sp60 = (f64) sp10;
        sp18 = temp_f2_1682;
        sp30 = (f32) sp60;
        sp38 = (f32) sp58;
        sp20 = temp_f4_1679;
        sp24 = temp_f3_1681;
        sp68 = (f64) sp18;
        sp50 = (f64) sp20;
        sp70 = (f64) sp30;
        sp78 = (f64) sp38;
        Normalise(sp80);
        M2C_FIELD(this, f64 *, 0x28) = M2C_BITWISE(f64, sp80);
        M2C_FIELD(this, f64 *, 0x30) = (f64) sp80.unk8;
    } else {
        this->unk10->GetCamera();
        ((KDCamera *) &sp40)->GetXZDir();
        M2C_FIELD(this, f64 *, 0x28) = sp40;
        M2C_FIELD(this, f64 *, 0x30) = sp48;
    }
    if (arg0.IsMessageOnList(0x178) != 0) {
        SelectAnim();
    } else {
        this->unk10->SetAnim(0x11U, 0.15f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    }
    temp_r3_1740 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43D;
    M2C_FIELD(temp_r3_1740->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk10->SelectStrafeTarget(0U);
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        if (arg0.IsMessageOnList(0x179) != 0) {
            this->unk14.SetState(this, 2, 0U);
            return;
        }
        if (arg0.IsMessageOnList(0x17A) != 0) {
            this->unk14.SetState(this, 3, 0U);
            return;
        }
        this->unk14.SetState(this, 1, 0U);
        return;
    }
    this->unk14.SetState(this, 0, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk14'
void SpyroStrafeState::Deinit() {
    this->unk14.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init__34KDStateMachine'
void SpyroStrafeState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    Init__34KDStateMachine<16SpyroStrafeState>FPQ234KDStateMachine<16SpyroStrafeState>5StateP34KDStateMachine<16SpyroStrafeState>(&this->unk14, (KDStateMachine<SpyroStrafeState>::State *) &SpyroStrafeState::states, NULL);
    M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk38 = 0;
    this->unk44 = 0.0f;
    this->unk40 = 0.0f;
    this->unk3C = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_728'
void SpyroStrafeState_cpp::__sinit() {
    f64 temp_f0_2098;
    f64 temp_f1_2068;
    f64 temp_f1_2092;
    f64 temp_f3_2054;
    f64 temp_f3_2095;
    f64 temp_f4_2067;
    f64 temp_f4_2089;
    f64 temp_f8_2056;
    void *temp_r3_2059;

    temp_f3_2054 = __frsqrte(2014000.0);
    temp_f8_2056 = __frsqrte(380000.0);
    temp_r3_2059 = &lit_728 + 0x90;
    temp_f4_2067 = 0.5 * temp_f3_2054 * -((2014000.0 * (temp_f3_2054 * temp_f3_2054)) - 3.0);
    temp_f1_2068 = 0.5 * temp_f8_2056 * -((380000.0 * (temp_f8_2056 * temp_f8_2056)) - 3.0);
    temp_f4_2089 = 0.5 * temp_f4_2067 * -((2014000.0 * (temp_f4_2067 * temp_f4_2067)) - 3.0);
    temp_f1_2092 = 0.5 * temp_f1_2068 * -((380000.0 * (temp_f1_2068 * temp_f1_2068)) - 3.0);
    temp_f3_2095 = temp_f4_2089 * temp_f4_2089;
    temp_f0_2098 = temp_f1_2092 * temp_f1_2092;
    M2C_FIELD(&lit_728, s32 *, 0x90) = (s32) M2C_FIELD(&lit_728, s32 *, 0);
    M2C_FIELD(&lit_728, s32 *, 0x94) = (s32) M2C_FIELD(&lit_728, s32 *, 4);
    M2C_FIELD(&lit_728, s32 *, 0x98) = (s32) M2C_FIELD(&lit_728, s32 *, 8);
    M2C_FIELD(temp_r3_2059, s32 *, 0xC) = (s32) M2C_FIELD(&lit_728, s32 *, 0xC);
    M2C_FIELD(temp_r3_2059, s32 *, 0x10) = (s32) M2C_FIELD(&lit_728, s32 *, 0x10);
    M2C_FIELD(temp_r3_2059, s32 *, 0x14) = (s32) M2C_FIELD(&lit_728, s32 *, 0x14);
    M2C_FIELD(temp_r3_2059, s32 *, 0x18) = (s32) M2C_FIELD(&lit_728, s32 *, 0x18);
    M2C_FIELD(temp_r3_2059, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x1C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x20) = (s32) M2C_FIELD(&lit_728, s32 *, 0x20);
    M2C_FIELD(temp_r3_2059, s32 *, 0x24) = (s32) M2C_FIELD(&lit_728, s32 *, 0x24);
    M2C_FIELD(temp_r3_2059, s32 *, 0x28) = (s32) M2C_FIELD(&lit_728, s32 *, 0x28);
    M2C_FIELD(temp_r3_2059, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x2C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x30) = (s32) M2C_FIELD(&lit_728, s32 *, 0x30);
    M2C_FIELD(temp_r3_2059, s32 *, 0x34) = (s32) M2C_FIELD(&lit_728, s32 *, 0x34);
    M2C_FIELD(temp_r3_2059, s32 *, 0x38) = (s32) M2C_FIELD(&lit_728, s32 *, 0x38);
    M2C_FIELD(temp_r3_2059, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x3C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x40) = (s32) M2C_FIELD(&lit_728, s32 *, 0x40);
    M2C_FIELD(temp_r3_2059, s32 *, 0x44) = (s32) M2C_FIELD(&lit_728, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2089 * -((2014000.0 * temp_f3_2095) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_2092 * -((380000.0 * temp_f0_2098) - 3.0)));
    M2C_FIELD(temp_r3_2059, s32 *, 0x48) = (s32) M2C_FIELD(&lit_728, s32 *, 0x48);
    M2C_FIELD(temp_r3_2059, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x4C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x50) = (s32) M2C_FIELD(&lit_728, s32 *, 0x50);
    M2C_FIELD(temp_r3_2059, s32 *, 0x54) = (s32) M2C_FIELD(&lit_728, s32 *, 0x54);
    M2C_FIELD(temp_r3_2059, s32 *, 0x58) = (s32) M2C_FIELD(&lit_728, s32 *, 0x58);
    M2C_FIELD(temp_r3_2059, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x5C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x60) = (s32) M2C_FIELD(&lit_728, s32 *, 0x60);
    M2C_FIELD(temp_r3_2059, s32 *, 0x64) = (s32) M2C_FIELD(&lit_728, s32 *, 0x64);
    M2C_FIELD(temp_r3_2059, s32 *, 0x68) = (s32) M2C_FIELD(&lit_728, s32 *, 0x68);
    M2C_FIELD(temp_r3_2059, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x6C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x70) = (s32) M2C_FIELD(&lit_728, s32 *, 0x70);
    M2C_FIELD(temp_r3_2059, s32 *, 0x74) = (s32) M2C_FIELD(&lit_728, s32 *, 0x74);
    M2C_FIELD(temp_r3_2059, s32 *, 0x78) = (s32) M2C_FIELD(&lit_728, s32 *, 0x78);
    M2C_FIELD(temp_r3_2059, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x7C);
    M2C_FIELD(temp_r3_2059, s32 *, 0x80) = (s32) M2C_FIELD(&lit_728, s32 *, 0x80);
    M2C_FIELD(temp_r3_2059, s32 *, 0x84) = (s32) M2C_FIELD(&lit_728, s32 *, 0x84);
    M2C_FIELD(temp_r3_2059, s32 *, 0x88) = (s32) M2C_FIELD(&lit_728, s32 *, 0x88);
    M2C_FIELD(temp_r3_2059, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_728, s32 *, 0x8C);
}
#endif

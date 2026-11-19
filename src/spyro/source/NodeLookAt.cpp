#include "spyro/source/NodeLookAt.h"
#include "common/Source/Animation.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void NodeLookAtIK::Update(MKVector3 *arg0) {
    Animation *temp_r3_32;
    NodeLookAtIK *temp_r3_204;
    f32 temp_f0_221;
    f32 temp_f10_243;
    f32 temp_f11_278;
    f32 temp_f12_251;
    f32 temp_f1_151;
    f32 temp_f1_233;
    f32 temp_f1_261;
    f32 temp_f1_284;
    f32 temp_f2_149;
    f32 temp_f3_150;
    f32 temp_f3_269;
    f32 temp_f3_292;
    f32 temp_f5_279;
    f32 temp_f8_250;
    f32 temp_f8_280;
    f32 temp_f9_253;
    f32 temp_f9_274;
    f32 var_f0_231;
    f32 var_f11_219;
    f32 var_f2_213;
    f32 var_f31_210;
    u32 temp_r30_22;
    u32 temp_r30_30;
    u32 temp_r30_366;
    void *temp_r3_178;
    temp_r30_22 = this->unk3C;
    ((Animation *) (MKModel_GetAnimation(this->unk34)))->SetCustomMatrix((s32) temp_r30_22, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r30_30 = this->unk3C;
    temp_r3_32 = MKModel_GetAnimation(this->unk34);
    arg_sp10 = (s16) temp_r30_30;
    temp_r3_32->CalculateMatrices((Matrix *) &arg_sp220, 1, &arg_sp10, NULL);
    arg_sp1E0.Inverse((Matrix *) &arg_sp220);
    arg_sp88.GetNodeOrigin(MKModel_GetAnimation(this->unk34));
    arg_spC8 = arg_sp88;
    arg_spD0 = arg_sp90;
    if ((arg0 != NULL) && ((u8) this->unk38 != 0)) {
        arg_sp1A0.Inverse(MKModel_GetWorldMatrix(this->unk34));
        arg_sp220.Multiply((Matrix *) &arg_sp220, MKModel_GetWorldMatrix(this->unk34));
        arg_sp58 = arg_sp250 + (((f32) arg_spD0 * arg_sp240) + (((f32) arg_spC8 * arg_sp220) + (arg_spCC * arg_sp230)));
        arg_sp5C = arg_sp254 + (((f32) arg_spD0 * arg_sp244) + (((f32) arg_spC8 * arg_sp224) + (arg_spCC * arg_sp234)));
        arg_sp60 = arg_sp258 + (((f32) arg_spD0 * arg_sp248) + (((f32) arg_spC8 * arg_sp228) + (arg_spCC * arg_sp238)));
        arg_spB8 = (f64) arg_sp58;
        arg_spC0 = (f64) arg_sp60;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_spA8 = arg_sp48;
        arg_sp50 = arg0->unk8 - (f32) arg_spC0;
        arg_spB0 = (f64) arg_sp50;
        arg_sp38 = ((f32) arg_spB0 * arg_sp1C0) + (((f32) arg_spA8 * arg_sp1A0) + (arg_spAC * arg_sp1B0));
        arg_sp3C = ((f32) arg_spB0 * arg_sp1C4) + (((f32) arg_spA8 * arg_sp1A4) + (arg_spAC * arg_sp1B4));
        arg_sp40 = ((f32) arg_spB0 * arg_sp1C8) + (((f32) arg_spA8 * arg_sp1A8) + (arg_spAC * arg_sp1B8));
        arg_sp98 = (f64) arg_sp38;
        arg_spA0 = (f64) arg_sp40;
        this->unk30 = this->unkC - KDMath_GetPitch(*((MKVector3 *) &arg_sp98));
        temp_f2_149 = this->unk10;
        temp_f3_150 = -KDMath_GetYaw(*((MKVector3 *) &arg_sp98));
        temp_f1_151 = -temp_f2_149;
        if ((temp_f3_150 < temp_f1_151) && (this->unk2C < temp_f2_149)) {
            this->unk2C = temp_f1_151;
        } else if ((temp_f3_150 > temp_f2_149) && (this->unk2C > temp_f1_151)) {
            this->unk2C = temp_f2_149;
        } else if ((temp_f3_150 > temp_f1_151) && (temp_f3_150 < temp_f2_149)) {
            this->unk2C = temp_f3_150;
        }
    } else if (((u8) this->unk38 != 0) && (temp_r3_178 = this->unk44, ((temp_r3_178 == NULL) == 0))) {
        this->unk30 = M2C_FIELD(temp_r3_178, f32 *, 0x30);
        this->unk30 = this->unk18 * ApplyThreshhold(this->unk30, this->unk14);
        this->unk2C = M2C_FIELD(this->unk44, f32 *, 0x2C);
        this->unk2C = this->unk18 * ApplyThreshhold(this->unk2C, this->unk14);
    } else {
        this->unk30 = 0.0f;
        this->unk2C = 0.0f;
    }
    temp_r3_204 = this->unk40;
    if (temp_r3_204 != NULL) {
        var_f31_210 = this->unk30 - temp_r3_204->GetPitchAssist();
        var_f2_213 = this->unk2C - this->unk40->GetYawAssist();
    } else {
        var_f31_210 = this->unk30;
        var_f2_213 = this->unk2C;
    }
    var_f11_219 = this->unk8;
    temp_f0_221 = -var_f11_219;
    if (var_f31_210 < var_f11_219) {
        var_f11_219 = var_f31_210;
    }
    if (var_f11_219 > temp_f0_221) {

    } else {
        var_f11_219 = temp_f0_221;
    }
    var_f0_231 = this->unk4;
    temp_f1_233 = -var_f0_231;
    if (var_f2_213 < var_f0_231) {
        var_f0_231 = var_f2_213;
    }
    if (var_f0_231 > temp_f1_233) {

    } else {
        var_f0_231 = temp_f1_233;
    }
    temp_f10_243 = this->unk0;
    temp_f8_250 = this->unk20 - var_f11_219;
    temp_f12_251 = this->unk28;
    temp_f9_253 = -temp_f10_243 * gUpdateTimeDelta;
    temp_f1_261 = gUpdateTimeDelta * ((temp_f10_243 * temp_f8_250) + temp_f12_251);
    temp_f3_269 = 1.0f / (1.0f + (((temp_f9_253 * (-0.235f * temp_f9_253 * temp_f9_253)) + (0.48f * temp_f9_253 * temp_f9_253)) - temp_f9_253));
    this->unk28 = temp_f3_269 * -((temp_f10_243 * temp_f1_261) - temp_f12_251);
    this->unk20 = (temp_f3_269 * (temp_f8_250 + temp_f1_261)) + var_f11_219;
    temp_f9_274 = this->unk0;
    temp_f11_278 = this->unk24;
    temp_f5_279 = this->unk1C - var_f0_231;
    temp_f8_280 = -temp_f9_274 * gUpdateTimeDelta;
    temp_f1_284 = gUpdateTimeDelta * ((temp_f9_274 * temp_f5_279) + temp_f11_278);
    temp_f3_292 = 1.0f / (1.0f + (((temp_f8_280 * (-0.235f * temp_f8_280 * temp_f8_280)) + (0.48f * temp_f8_280 * temp_f8_280)) - temp_f8_280));
    this->unk24 = temp_f3_292 * -((temp_f9_274 * temp_f1_284) - temp_f11_278);
    this->unk1C = (temp_f3_292 * (temp_f5_279 + temp_f1_284)) + var_f0_231;
    M2C_STRUCT_COPY((s32) &arg_sp15C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp30 = 0.0f;
    arg_sp28 = 1.0f;
    arg_sp2C = 0.0f;
    arg_sp80 = (f64) arg_sp30;
    arg_sp78 = (f64) arg_sp28;
    arg_sp160.SetRotateAroundAxis(*((MKVector3 *) &arg_sp78), this->unk20);
    arg_sp120.SetRotateAroundAxis(*((MKVector3 *) &arg_sp1F0), this->unk1C);
    arg_sp160.Multiply3x3((Matrix *) &arg_sp160, (Matrix *) &arg_sp120);
    M2C_STRUCT_COPY((s32) &arg_spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    arg_sp18 = -(f32) arg_spC8;
    arg_sp1C = -arg_spCC;
    arg_sp20 = -(f32) arg_spD0;
    arg_sp68 = (f64) arg_sp18;
    arg_sp70 = (f64) arg_sp20;
    arg_sp110 = (f32) arg_sp68;
    arg_sp114 = arg_sp6C;
    arg_sp118 = (f32) arg_sp70;
    arg_sp11C = 1.0f;
    arg_spE0.Multiply((Matrix *) &arg_spE0, (Matrix *) &arg_sp160);
    arg_spE0.Translate((Matrix *) &arg_spE0, *((MKVector3 *) &arg_spC8));
    temp_r30_366 = this->unk3C;
    ((Animation *) (MKModel_GetAnimation(this->unk34)))->SetCustomMatrix((s32) temp_r30_366, (Matrix *) &arg_spE0, (AnimationMatrixPosition) 2, 0U);
}
#endif

f32 ApplyThreshhold(float arg0, float arg1) {
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (arg0 == 0.0f) {
        if (arg0 < arg1) {
            return 0.0f;
        }
        return arg0 - arg1;
    }
    if (arg0 > -arg1) {
        return 0.0f;
    }
    return arg0 + arg1;
}

void NodeLookAtIK::Init(MKModel *arg0, int arg1) {
    u32 temp_r31_528;

    this->unk34 = arg0;
    ((Animation *) (MKModel_GetAnimation(this->unk34)))->EnableCustomMatrices(1U);
    this->unk3C = (u32) arg1;
    temp_r31_528 = this->unk3C;
    if (temp_r31_528 != -1U) {
        ((Animation *) (MKModel_GetAnimation(this->unk34)))->SetCustomMatrix((s32) temp_r31_528, NULL, (AnimationMatrixPosition) 2, 0U);
    }
    this->unk0 = 6.0f;
    this->unk4 = 0.5235988f;
    this->unk8 = 0.5235988f;
    this->unk14 = 0.0f;
    this->unk18 = 0.5f;
    this->unkC = 0.0f;
    this->unk10 = 3.1415927f;
    this->unk20 = 0.0f;
    this->unk28 = 0.0f;
    this->unk1C = 0.0f;
    this->unk24 = 0.0f;
    this->unk38 = 1;
    this->unk40 = NULL;
    this->unk44 = NULL;
}

void NodeLookAt::Reset() {
    u32 temp_r31_582;

    this->unk24 = 0.0f;
    this->unk20 = 0.0f;
    this->unk1C = 0.0f;
    this->unk18 = 0.0f;
    this->unk2C = 0.0f;
    this->unk28 = 0.0f;
    temp_r31_582 = this->unk34;
    if (temp_r31_582 != -1U) {
        ((Animation *) (MKModel_GetAnimation(this->unk30)))->SetCustomMatrix((s32) temp_r31_582, NULL, (AnimationMatrixPosition) 2, 0U);
    }
}

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void NodeLookAt::Update(MKVector3 *arg0) {
    Animation *temp_r3_664;
    MKVector3 *var_r28_616;
    f32 temp_f0_828;
    f32 temp_f10_785;
    f32 temp_f11_843;
    f32 temp_f1_813;
    f32 temp_f2_793;
    f32 temp_f2_806;
    f32 temp_f2_853;
    f32 temp_f3_689;
    f32 temp_f3_752;
    f32 temp_f4_760;
    f32 temp_f4_801;
    f32 temp_f4_859;
    f32 temp_f6_695;
    f32 temp_f6_840;
    f32 temp_f7_701;
    f32 temp_f7_784;
    f32 temp_f7_841;
    f32 temp_f8_786;
    f32 temp_f8_824;
    f32 temp_f9_779;
    f32 var_f0_755;
    f32 var_f10_821;
    f32 var_f1_628;
    f32 var_f1_637;
    f32 var_f30_746;
    f32 var_f31_743;
    s32 temp_r29_661;
    u32 temp_r29_622;
    u32 temp_r30_662;
    var_r28_616 = arg0;
    if ((u8) this->unk38 == 0) {
        var_r28_616 = NULL;
    }
    temp_r29_622 = this->unk34;
    if (temp_r29_622 != -1U) {
        if (var_r28_616 == NULL) {
            var_f1_628 = this->unk18;
            if (var_f1_628 < 0.0f) {
                var_f1_628 = -var_f1_628;
            }
            if (!(var_f1_628 > 0.02f)) {
                var_f1_637 = this->unk1C;
                if (var_f1_637 < 0.0f) {
                    var_f1_637 = -var_f1_637;
                }
                if (var_f1_637 > 0.02f) {
                    goto block_10;
                }
                goto block_34;
            }
            goto block_10;
        }
block_10:
        if (var_r28_616 != NULL) {
            if ((s32) this->unk14 == 1) {
                ((Animation *) (MKModel_GetAnimation(this->unk30)))->SetCustomMatrix((s32) temp_r29_622, NULL, (AnimationMatrixPosition) 2, 0U);
                temp_r29_661 = MKModel_GetWorldMatrix(this->unk30);
                temp_r30_662 = this->unk34;
                temp_r3_664 = MKModel_GetAnimation(this->unk30);
                arg_sp10 = (s16) temp_r30_662;
                temp_r3_664->CalculateMatrices((Matrix *) &arg_sp150, 1, &arg_sp10, (Matrix *) temp_r29_661);
            } else {
                M2C_STRUCT_COPY((s32) &arg_sp14C + 4, MKModel_GetWorldMatrix(this->unk30) - 4 + 4, 0x40);
            }
            arg_sp150.Inverse((Matrix *) &arg_sp150);
            temp_f3_689 = var_r28_616->unk4;
            temp_f6_695 = var_r28_616->unk0;
            temp_f7_701 = var_r28_616->unk8;
            arg_sp48 = arg_sp180 + ((temp_f7_701 * arg_sp170) + ((temp_f6_695 * arg_sp150) + (temp_f3_689 * arg_sp160)));
            arg_sp4C = arg_sp184 + ((temp_f7_701 * arg_sp174) + ((temp_f6_695 * arg_sp154) + (temp_f3_689 * arg_sp164)));
            arg_sp50 = arg_sp188 + ((temp_f7_701 * arg_sp178) + ((temp_f6_695 * arg_sp158) + (temp_f3_689 * arg_sp168)));
            arg_spB8 = (f64) arg_sp48;
            arg_spC0 = (f64) arg_sp50;
            arg_sp88.GetNodeOrigin(MKModel_GetAnimation(this->unk30));
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_spA8 = arg_sp38;
            arg_sp40 = (f32) arg_spC0 - arg_sp90;
            arg_spB0 = (f64) arg_sp40;
            var_f31_743 = KDMath_GetYaw(*((MKVector3 *) &arg_spA8));
            var_f30_746 = KDMath_GetPitch(*((MKVector3 *) &arg_spA8));
        } else {
            var_f31_743 = 0.0f;
            var_f30_746 = 0.0f;
        }
        temp_f3_752 = this->unk8;
        if (var_f31_743 < temp_f3_752) {
            var_f0_755 = var_f31_743;
        } else {
            var_f0_755 = temp_f3_752;
        }
        temp_f4_760 = this->unk4;
        if (var_f0_755 > temp_f4_760) {

        } else {
            var_f0_755 = temp_f4_760;
        }
        if ((3.1415927f + temp_f4_760) < (0.01f + temp_f3_752)) {
            var_f0_755 = this->unk18 + KDMath_GetSmallestAngle(this->unk18, var_f31_743);
        }
        temp_f9_779 = this->unk0;
        temp_f7_784 = this->unk18 - var_f0_755;
        temp_f10_785 = this->unk20;
        temp_f8_786 = -temp_f9_779 * gUpdateTimeDelta;
        temp_f2_793 = gUpdateTimeDelta * ((temp_f9_779 * temp_f7_784) + temp_f10_785);
        temp_f4_801 = 1.0f / (1.0f + (((temp_f8_786 * (-0.235f * temp_f8_786 * temp_f8_786)) + (0.48f * temp_f8_786 * temp_f8_786)) - temp_f8_786));
        this->unk20 = temp_f4_801 * -((temp_f9_779 * temp_f2_793) - temp_f10_785);
        this->unk18 = (temp_f4_801 * (temp_f7_784 + temp_f2_793)) + var_f0_755;
        temp_f2_806 = this->unk18;
        if (temp_f2_806 > 3.1415927f) {
            this->unk18 = temp_f2_806 - 6.2831855f;
        }
        temp_f1_813 = this->unk18;
        if (temp_f1_813 < -3.1415927f) {
            this->unk18 = temp_f1_813 + 6.2831855f;
        }
        var_f10_821 = this->unk10;
        temp_f8_824 = this->unk0;
        if (var_f30_746 < var_f10_821) {
            var_f10_821 = var_f30_746;
        }
        temp_f0_828 = this->unkC;
        if (var_f10_821 > temp_f0_828) {

        } else {
            var_f10_821 = temp_f0_828;
        }
        temp_f6_840 = this->unk1C - var_f10_821;
        temp_f7_841 = -temp_f8_824 * gUpdateTimeDelta;
        temp_f11_843 = this->unk24;
        arg_sp30 = 0.0f;
        temp_f2_853 = gUpdateTimeDelta * ((temp_f8_824 * temp_f6_840) + temp_f11_843);
        temp_f4_859 = 1.0f / (1.0f + (((temp_f7_841 * (-0.235f * temp_f7_841 * temp_f7_841)) + (0.48f * temp_f7_841 * temp_f7_841)) - temp_f7_841));
        this->unk24 = temp_f4_859 * -((temp_f8_824 * temp_f2_853) - temp_f11_843);
        this->unk1C = (temp_f4_859 * (temp_f6_840 + temp_f2_853)) + var_f10_821;
        arg_sp140 = 0.0f;
        arg_sp144 = 0.0f;
        arg_sp148 = 0.0f;
        arg_sp14C = 1.0f;
        arg_sp28 = this->unk1C;
        arg_sp2C = this->unk18;
        arg_sp80 = (f64) arg_sp30;
        arg_sp78 = (f64) arg_sp28;
        arg_sp110.SetRotationPYR(*((MKVector3 *) &arg_sp78));
        arg_sp68.GetNodeOrigin(MKModel_GetAnimation(this->unk30));
        arg_sp98 = arg_sp68;
        arg_spA0 = arg_sp70;
        M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        arg_sp18 = -(f32) arg_sp98;
        arg_sp1C = -arg_sp9C;
        arg_sp20 = -(f32) arg_spA0;
        arg_sp58 = (f64) arg_sp18;
        arg_sp60 = (f64) arg_sp20;
        arg_spD0.Translate((Matrix *) &arg_spD0, *((MKVector3 *) &arg_sp58));
        arg_spD0.Multiply((Matrix *) &arg_spD0, (Matrix *) &arg_sp110);
        arg_spD0.Translate((Matrix *) &arg_spD0, *((MKVector3 *) &arg_sp98));
        ((Animation *) (MKModel_GetAnimation(this->unk30)))->SetCustomMatrix((s32) this->unk34, (Matrix *) &arg_spD0, (AnimationMatrixPosition) 1, 0U);
        this->unk28 = KDMath_GetSmallestAngle(this->unk18, var_f31_743);
        this->unk2C = KDMath_GetSmallestAngle(this->unk1C, var_f30_746);
        return;
    }
block_34:
    Reset();
}
#endif

void NodeLookAt::Init(MKModel *arg0, int arg1, NLStyle arg2) {
    this->unk30 = arg0;
    ((Animation *) (MKModel_GetAnimation(this->unk30)))->EnableCustomMatrices(1U);
    this->unk34 = (u32) arg1;
    this->unk14 = (s32) arg2;
    Reset();
    if ((s32) this->unk14 == 2) {
        this->unk4 = -3.1415927f;
        this->unk8 = 3.1415927f;
        this->unkC = -1.5707964f;
        this->unk10 = 1.5707964f;
        this->unk0 = 6.0f;
    } else {
        this->unk4 = -1.3659099f;
        this->unk8 = 1.3659099f;
        this->unkC = -1.3659099f;
        this->unk10 = 0.7853982f;
        this->unk0 = 10.0f;
    }
    this->unk2C = 0.0f;
    this->unk28 = 0.0f;
}

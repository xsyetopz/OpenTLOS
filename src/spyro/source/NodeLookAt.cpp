#include "spyro/source/NodeLookAt.h"
#include "common/Source/Animation.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void NodeLookAtIK::Update(MKVector3 *arg0) {
    Matrix sp220;
    Matrix sp1E0;
    Matrix sp1A0;
    Matrix sp160;
    Matrix sp120;
    Matrix spE0;
    M2C_UNK spDC;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    Animation sp88;
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
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s16 sp10;
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
    f32 temp_f5_114;
    f32 temp_f5_279;
    f32 temp_f6_121;
    f32 temp_f6_130;
    f32 temp_f8_250;
    f32 temp_f8_280;
    f32 temp_f9_253;
    f32 temp_f9_274;
    f32 var_f0_231;
    f32 var_f11_219;
    f32 var_f2_213;
    f32 var_f31_210;
    f64 temp_f0_104;
    u32 temp_r30_22;
    u32 temp_r30_30;
    u32 temp_r30_366;
    void *temp_r3_178;

    temp_r30_22 = this->unk3C;
    ((Animation *) (MKModel_GetAnimation(this->unk34)))->SetCustomMatrix((s32) temp_r30_22, NULL, (AnimationMatrixPosition) 2, 0U);
    temp_r30_30 = this->unk3C;
    temp_r3_32 = MKModel_GetAnimation(this->unk34);
    sp10 = (s16) temp_r30_30;
    temp_r3_32->CalculateMatrices(&sp220, 1, &sp10, NULL);
    sp1E0.Inverse(&sp220);
    sp88.GetNodeOrigin(MKModel_GetAnimation(this->unk34));
    spC8 = M2C_BITWISE(f64, sp88);
    spD0 = sp88.unk8;
    if ((arg0 != NULL) && ((u8) this->unk38 != 0)) {
        sp1A0.Inverse(MKModel_GetWorldMatrix(this->unk34));
        sp220.Multiply(&sp220, MKModel_GetWorldMatrix(this->unk34));
        sp58 = sp220.unk30 + (((f32) spD0 * sp220.unk20) + (((f32) spC8 * M2C_BITWISE(f32, sp220)) + (unkspCC * sp220.unk10)));
        sp5C = sp220.unk34 + (((f32) spD0 * sp220.unk24) + (((f32) spC8 * sp220.unk4) + (unkspCC * sp220.unk14)));
        sp60 = sp220.unk38 + (((f32) spD0 * sp220.unk28) + (((f32) spC8 * sp220.unk8) + (unkspCC * sp220.unk18)));
        sp88.unk30 = (f64) sp58;
        spC0 = (f64) sp60;
        temp_f0_104 = M2C_FIELD(arg0, f64 *, 0) - sp88.unk30;
        sp48 = temp_f0_104;
        sp88.unk20 = temp_f0_104;
        temp_f5_114 = M2C_BITWISE(f32, sp88.unk24);
        sp50 = arg0->unk8 - (f32) spC0;
        temp_f6_121 = M2C_BITWISE(f32, sp88.unk20);
        sp88.unk28 = (f64) sp50;
        temp_f6_130 = M2C_BITWISE(f32, sp88.unk28);
        sp38 = (temp_f6_130 * sp1A0.unk20) + ((temp_f6_121 * M2C_BITWISE(f32, sp1A0)) + (temp_f5_114 * sp1A0.unk10));
        sp3C = (temp_f6_130 * sp1A0.unk24) + ((temp_f6_121 * sp1A0.unk4) + (temp_f5_114 * sp1A0.unk14));
        sp40 = (temp_f6_130 * sp1A0.unk28) + ((temp_f6_121 * sp1A0.unk8) + (temp_f5_114 * sp1A0.unk18));
        sp88.unk10 = (f64) sp38;
        sp88.unk18 = (f64) sp40;
        this->unk30 = this->unkC - KDMath_GetPitch(*((MKVector3 *) &sp88.unk10));
        temp_f2_149 = this->unk10;
        temp_f3_150 = -KDMath_GetYaw(*((MKVector3 *) &sp88.unk10));
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
    M2C_STRUCT_COPY((s32) &sp120.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp30 = 0.0f;
    sp28 = 1.0f;
    sp2C = 0.0f;
    sp80 = (f64) sp30;
    sp78 = (f64) sp28;
    sp160.SetRotateAroundAxis(*((MKVector3 *) &sp78), this->unk20);
    sp120.SetRotateAroundAxis(*((MKVector3 *) &sp1E0.unk10), this->unk1C);
    sp160.Multiply3x3(&sp160, &sp120);
    M2C_STRUCT_COPY((s32) &spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp18 = -(f32) spC8;
    sp1C = -unkspCC;
    sp20 = -(f32) spD0;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    spE0.unk30 = (f32) sp68;
    spE0.unk34 = unksp6C;
    spE0.unk38 = (f32) sp70;
    spE0.unk3C = 1.0f;
    spE0.Multiply(&spE0, &sp160);
    spE0.Translate(&spE0, *((MKVector3 *) &spC8));
    temp_r30_366 = this->unk3C;
    ((Animation *) (MKModel_GetAnimation(this->unk34)))->SetCustomMatrix((s32) temp_r30_366, &spE0, (AnimationMatrixPosition) 2, 0U);
}
#endif

f32 ApplyThreshhold(float arg0, float arg1) {
    if (arg0 >= 0.0f) {
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

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void NodeLookAt::Update(MKVector3 *arg0) {
    Matrix sp150;
    Matrix sp110;
    Matrix spD0;
    M2C_UNK spCC;
    f64 spC0;
    Animation sp88;
    f64 sp80;
    f64 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s16 sp10;
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
    f64 temp_f0_731;
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
                sp10 = (s16) temp_r30_662;
                temp_r3_664->CalculateMatrices(&sp150, 1, &sp10, (Matrix *) temp_r29_661);
            } else {
                M2C_STRUCT_COPY((s32) &sp110.unk3C + 4, MKModel_GetWorldMatrix(this->unk30) - 4 + 4, 0x40);
            }
            sp150.Inverse(&sp150);
            temp_f3_689 = var_r28_616->unk4;
            temp_f6_695 = var_r28_616->unk0;
            temp_f7_701 = var_r28_616->unk8;
            sp48 = sp150.unk30 + ((temp_f7_701 * sp150.unk20) + ((temp_f6_695 * M2C_BITWISE(f32, sp150)) + (temp_f3_689 * sp150.unk10)));
            sp4C = sp150.unk34 + ((temp_f7_701 * sp150.unk24) + ((temp_f6_695 * sp150.unk4) + (temp_f3_689 * sp150.unk14)));
            sp50 = sp150.unk38 + ((temp_f7_701 * sp150.unk28) + ((temp_f6_695 * sp150.unk8) + (temp_f3_689 * sp150.unk18)));
            sp88.unk30 = (f64) sp48;
            spC0 = (f64) sp50;
            sp88.GetNodeOrigin(MKModel_GetAnimation(this->unk30));
            temp_f0_731 = sp88.unk30 - M2C_BITWISE(f64, sp88);
            sp38 = temp_f0_731;
            sp88.unk20 = temp_f0_731;
            sp40 = (f32) spC0 - (f32) sp88.unk8;
            sp88.unk28 = (f64) sp40;
            var_f31_743 = KDMath_GetYaw(*((MKVector3 *) &sp88.unk20));
            var_f30_746 = KDMath_GetPitch(*((MKVector3 *) &sp88.unk20));
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
        sp30 = 0.0f;
        temp_f2_853 = gUpdateTimeDelta * ((temp_f8_824 * temp_f6_840) + temp_f11_843);
        temp_f4_859 = 1.0f / (1.0f + (((temp_f7_841 * (-0.235f * temp_f7_841 * temp_f7_841)) + (0.48f * temp_f7_841 * temp_f7_841)) - temp_f7_841));
        this->unk24 = temp_f4_859 * -((temp_f8_824 * temp_f2_853) - temp_f11_843);
        this->unk1C = (temp_f4_859 * (temp_f6_840 + temp_f2_853)) + var_f10_821;
        sp110.unk30 = 0.0f;
        sp110.unk34 = 0.0f;
        sp110.unk38 = 0.0f;
        sp110.unk3C = 1.0f;
        sp28 = this->unk1C;
        sp2C = this->unk18;
        sp80 = (f64) sp30;
        sp78 = (f64) sp28;
        sp110.SetRotationPYR(*((MKVector3 *) &sp78));
        sp68.GetNodeOrigin(MKModel_GetAnimation(this->unk30));
        sp88.unk10 = sp68;
        sp88.unk18 = sp70;
        M2C_STRUCT_COPY((s32) &spCC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp18 = -M2C_BITWISE(f32, sp88.unk10);
        sp1C = -M2C_BITWISE(f32, sp88.unk14);
        sp20 = -M2C_BITWISE(f32, sp88.unk18);
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        spD0.Translate(&spD0, *((MKVector3 *) &sp58));
        spD0.Multiply(&spD0, &sp110);
        spD0.Translate(&spD0, *((MKVector3 *) &sp88.unk10));
        ((Animation *) (MKModel_GetAnimation(this->unk30)))->SetCustomMatrix((s32) this->unk34, &spD0, (AnimationMatrixPosition) 1, 0U);
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

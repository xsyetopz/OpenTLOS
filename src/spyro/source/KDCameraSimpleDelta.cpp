#include "spyro/source/KDCameraSimpleDelta.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

s32 stricmp(s8 *, s8 *);                            /* extern */
extern s8 gAssertBool;
extern f32 gUpdateTimeDelta;
extern u8 init_515;
extern KDCameraDeltaStages *pCurrentLoadingStage_514;

void KDCameraSimpleDelta::Override::DisableSmoothDelta() {
    M2C_FIELD(this, s32 *, 0x10) = (s32) (M2C_FIELD(this, s32 *, 0x10) & 0xFFFFFFFD);
    M2C_FIELD(this, f32 *, 0xC) = 0.0f;
}

void KDCameraSimpleDelta::Override::EnableSmoothDelta(float farg0) {
    M2C_FIELD(this, s32 *, 0x10) = (s32) (M2C_FIELD(this, s32 *, 0x10) | 2);
    M2C_FIELD(this, f32 *, 0xC) = farg0;
}

#if 0 // DRAFT: illegal operand
void KDCameraSimpleDelta::Override::DisableSmoothPitch() {
    M2C_FIELD(this, s32 *, 0x10) = (s32) (M2C_FIELD(this, s32 *, 0x10) & 0xFFFFFFFE);
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, KDCameraSimpleDelta::Override *, 0) = 0;
}
#endif

#if 0 // DRAFT: illegal operand
void KDCameraSimpleDelta::Override::EnableSmoothPitch(float farg0, float farg1, bool arg1) {
    EnableSmoothPitch(farg0, farg1);
    *this = arg1;
}
#endif

void KDCameraSimpleDelta::Override::EnableSmoothPitch(float farg0, float farg1) {
    M2C_FIELD(this, s32 *, 0x10) = (s32) (M2C_FIELD(this, s32 *, 0x10) | 1);
    M2C_FIELD(this, f32 *, 4) = farg0;
    M2C_FIELD(this, f32 *, 8) = farg1;
}

#if 0 // DRAFT: illegal use of non-static member
u8 KDCameraSimpleDelta::IsUsingIdealDelta() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_169;
    f32 temp_f1_87;
    f32 temp_f30_167;
    f32 temp_f30_85;
    f32 var_f1_247;
    f32 var_f31_102;
    f32 var_f4_184;
    f64 temp_f1_105;
    f64 temp_f1_111;
    f64 temp_f1_115;
    f64 temp_f1_187;
    f64 temp_f1_193;
    f64 temp_f1_197;
    s32 temp_r3_134;
    s32 temp_r3_216;
    s32 var_r0_144;
    s32 var_r0_226;

    temp_f30_85 = KDCameraDeltaStagesEx::GetZDelta();
    temp_f1_87 = KDCameraDeltaStagesEx::GetYDelta();
    sp28 = temp_f30_85;
    sp20 = 0.0f;
    sp24 = temp_f1_87;
    sp48 = (f64) sp28;
    sp40 = (f64) sp20;
    var_f31_102 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
    if (var_f31_102 > 0.0f) {
        temp_f1_105 = __frsqrte(var_f31_102);
        temp_f1_111 = 0.5 * temp_f1_105 * -(((f64) var_f31_102 * (temp_f1_105 * temp_f1_105)) - 3.0);
        temp_f1_115 = 0.5 * temp_f1_111 * -(((f64) var_f31_102 * (temp_f1_111 * temp_f1_111)) - 3.0);
        var_f31_102 = (f32) ((f64) var_f31_102 * (0.5 * temp_f1_115 * -(((f64) var_f31_102 * (temp_f1_115 * temp_f1_115)) - 3.0)));
    } else if (var_f31_102 < M2C_BITWISE(f32, 0.0)) {
        var_f31_102 = __float_nan;
    } else {
        spC = var_f31_102;
        temp_r3_134 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_134) {                      /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_144 = 1;
            } else {
                var_r0_144 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_144 = 5;
            } else {
                var_r0_144 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_144 = 4;
            break;
        }
        if (var_r0_144 == 1) {
            var_f31_102 = __float_nan;
        }
    }
    temp_f30_167 = this->unk14.GetZDelta();
    temp_f1_169 = this->unk14.GetYDelta();
    sp18 = temp_f30_167;
    sp10 = 0.0f;
    sp14 = temp_f1_169;
    sp38 = (f64) sp18;
    sp30 = (f64) sp10;
    var_f4_184 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f4_184 > 0.0f) {
        temp_f1_187 = __frsqrte(var_f4_184);
        temp_f1_193 = 0.5 * temp_f1_187 * -(((f64) var_f4_184 * (temp_f1_187 * temp_f1_187)) - 3.0);
        temp_f1_197 = 0.5 * temp_f1_193 * -(((f64) var_f4_184 * (temp_f1_193 * temp_f1_193)) - 3.0);
        var_f4_184 = (f32) ((f64) var_f4_184 * (0.5 * temp_f1_197 * -(((f64) var_f4_184 * (temp_f1_197 * temp_f1_197)) - 3.0)));
    } else if (var_f4_184 < M2C_BITWISE(f32, 0.0)) {
        var_f4_184 = __float_nan;
    } else {
        sp8 = var_f4_184;
        temp_r3_216 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_216) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_226 = 1;
            } else {
                var_r0_226 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_226 = 5;
            } else {
                var_r0_226 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_226 = 4;
            break;
        }
        if (var_r0_226 == 1) {
            var_f4_184 = __float_nan;
        }
    }
    var_f1_247 = var_f31_102 - var_f4_184;
    if (var_f1_247 < 0.0f) {
        var_f1_247 = -var_f1_247;
    }
    if (var_f1_247 > 10.0f) {
        return 0U;
    }
    return 1U;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::OverrideUpdate() {
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_287;
    f32 temp_f0_295;
    f32 temp_f0_356;
    f32 temp_f0_363;
    f32 temp_f1_335;
    f32 temp_f1_344;
    f32 temp_f4_334;
    f32 var_f0_337;
    f32 var_f1_311;
    f32 var_f2_324;
    f32 var_f31_286;
    f32 var_f3_309;

    if (this->unk54 & 1) {
        var_f31_286 = this->unk14;
        temp_f0_287 = *this->unk24;
        if (var_f31_286 < temp_f0_287) {

        } else {
            var_f31_286 = temp_f0_287;
        }
        temp_f0_295 = *this->unk20;
        if (var_f31_286 > temp_f0_295) {

        } else {
            var_f31_286 = temp_f0_295;
        }
        if ((u8) this->unk44 != 0) {
            this->unk48 = GetIdealPitch();
        }
        var_f3_309 = this->unk48;
        var_f1_311 = var_f31_286 - var_f3_309;
        if (var_f1_311 < 0.0f) {
            var_f1_311 = -var_f1_311;
        }
        if (var_f1_311 > 0.0005f) {
            var_f2_324 = 0.5f * (this->unk4C * gUpdateTimeDelta);
            if (var_f2_324 < 1.0f) {

            } else {
                var_f2_324 = 1.0f;
            }
            temp_f4_334 = *this->unk24;
            temp_f1_335 = (var_f2_324 * (var_f3_309 - var_f31_286)) + var_f31_286;
            var_f0_337 = (var_f2_324 * (var_f3_309 - temp_f1_335)) + temp_f1_335;
            if (var_f0_337 < temp_f4_334) {

            } else {
                var_f0_337 = temp_f4_334;
            }
            temp_f1_344 = *this->unk20;
            if (var_f0_337 > temp_f1_344) {

            } else {
                var_f0_337 = temp_f1_344;
            }
            this->unk14 = var_f0_337;
        } else {
            temp_f0_356 = *this->unk24;
            if (var_f3_309 < temp_f0_356) {

            } else {
                var_f3_309 = temp_f0_356;
            }
            temp_f0_363 = *this->unk20;
            if (var_f3_309 > temp_f0_363) {

            } else {
                var_f3_309 = temp_f0_363;
            }
            this->unk14 = var_f3_309;
            this->unk44.DisableSmoothPitch();
        }
    }
    if (this->unk54 & 2) {
        sp18 = 0.0f;
        sp1C = this->unk18;
        sp20 = this->unk1C;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        sp8 = 0.0f;
        spC = this->unk4;
        sp10 = this->unk8;
        sp38 = (f64) sp8;
        sp40 = (f64) sp10;
        KDMath_CriticalDamp<MKVector3>(sp28, *((MKVector3 *) &sp48), *((MKVector3 *) &sp38), this->unk50, gUpdateTimeDelta);
        sp48 += M2C_BITWISE(f64, sp28);
        sp50 = (f32) sp50 + sp28.unk8;
        this->unk18 = unksp4C;
        this->unk1C = sp50;
        if (IsUsingIdealDelta() != 0) {
            this->unk44.DisableSmoothDelta();
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::DisableDeltaOverride(float arg0) {
    if (IsUsingIdealDelta() == 0) {
        if (arg0 != 0.0f) {
            this->unk44.EnableSmoothDelta(arg0);
            return;
        }
        this->unk44.DisableSmoothDelta();
        this->unk18 = this->unk4;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::DisablePitchOverride(float arg0) {
    f32 temp_f0_567;
    f32 temp_f0_575;
    f32 temp_f0_593;
    f32 temp_f0_600;
    f32 var_f1_566;
    f32 var_f1_590;

    if (arg0 != 0.0f) {
        var_f1_566 = this->unk0;
        temp_f0_567 = *this->unk10;
        if (var_f1_566 < temp_f0_567) {

        } else {
            var_f1_566 = temp_f0_567;
        }
        temp_f0_575 = *this->unkC;
        if (var_f1_566 > temp_f0_575) {

        } else {
            var_f1_566 = temp_f0_575;
        }
        this->unk44.EnableSmoothPitch(var_f1_566, arg0, 1U);
        return;
    }
    this->unk44.DisableSmoothPitch();
    var_f1_590 = KDCameraDeltaStagesEx::GetPitch();
    temp_f0_593 = *this->unk24;
    if (var_f1_590 < temp_f0_593) {

    } else {
        var_f1_590 = temp_f0_593;
    }
    temp_f0_600 = *this->unk20;
    if (var_f1_590 > temp_f0_600) {

    } else {
        var_f1_590 = temp_f0_600;
    }
    this->unk14 = var_f1_590;
}
#endif

void KDCameraSimpleDelta::DisableOverride(float arg0, float arg1) {
    DisablePitchOverride(arg0);
    DisableDeltaOverride(arg1);
}

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::EnablePitchOverride(float arg0, float arg1) {
    f32 temp_f0_669;
    f32 temp_f0_676;
    f32 temp_f3_690;
    f32 var_f0_689;
    f32 var_f1_0;

    var_f1_0 = arg0;
    if (arg1 == 0.0f) {
        temp_f0_669 = *this->unk24;
        if (var_f1_0 < temp_f0_669) {

        } else {
            var_f1_0 = temp_f0_669;
        }
        temp_f0_676 = *this->unk20;
        if (var_f1_0 > temp_f0_676) {

        } else {
            var_f1_0 = temp_f0_676;
        }
        this->unk14 = var_f1_0;
        this->unk44.DisableSmoothPitch();
        return;
    }
    var_f0_689 = this->unk0;
    temp_f3_690 = *this->unk10;
    if (var_f0_689 < temp_f3_690) {

    } else {
        var_f0_689 = temp_f3_690;
    }
    if (var_f0_689 > *this->unkC) {

    }
    this->unk44.EnableSmoothPitch(var_f1_0, arg1, ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1);
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::EnableOverride(float arg0, float arg1, float arg2) {
    this->unk44.DisableSmoothDelta();
    this->unk14.SetStages(arg0, arg1, arg2);
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::SetDeltaStages(KDCameraDeltaStages *arg0, bool arg1, bool arg2) {
    f32 temp_f0_770;
    f32 temp_f0_780;
    f32 var_f1_769;

    this->unk44.DisableSmoothDelta();
    this->unk44.DisableSmoothPitch();
    KDCameraDeltaStagesEx::SetStages(arg0->unk0, arg0->unk4, arg0->unk8);
    if (arg2 != 0) {
        var_f1_769 = this->unk14;
        temp_f0_770 = *this->unk24;
        if (var_f1_769 < temp_f0_770) {

        } else {
            var_f1_769 = temp_f0_770;
        }
        temp_f0_780 = *this->unk20;
        if (var_f1_769 > temp_f0_780) {

        } else {
            var_f1_769 = temp_f0_780;
        }
        EnableOverride(var_f1_769, this->unk18, this->unk1C);
        DisableOverride(5.0f, 1.5f);
    } else {
        this->unk14.SetStages(arg0->unk0, arg0->unk4, arg0->unk8);
    }
    if (arg1 != 0) {
        this->unk28 = 0.0f;
        this->unk34 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
void KDCameraSimpleDelta::GetDeltaVectorAtPitch(float arg0) {
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_844;
    f32 temp_f1_839;
    f32 temp_f2_842;

    sp30.SetIdentity();
    sp30.SetRotationPitch(arg0);
    sp20 = (f64) sp30.unk20;
    sp28 = (f64) sp30.unk28;
    temp_f1_839 = ((KDCameraSimpleDelta *) (M2C_ERROR(/* Read from unset register $r4 */)))->GetCurrentDelta();
    temp_f2_842 = unksp24 * temp_f1_839;
    temp_f0_844 = (f32) sp28 * temp_f1_839;
    sp10 = 0.0f;
    sp14 = temp_f2_842;
    sp18 = temp_f0_844;
    M2C_FIELD(this, f64 *, 0) = (f64) sp10;
    M2C_FIELD(this, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::Update(const MKVector3 &arg0) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_980;
    f32 temp_f31_975;
    f32 temp_f31_978;
    f32 var_f4_981;
    f32 var_f5_996;
    f64 temp_f1_1001;
    f64 temp_f1_1007;
    f64 temp_f1_1011;
    s32 temp_r3_1030;
    s32 var_r0_1040;

    temp_f31_975 = this->unk28;
    temp_f31_978 = this->unk14.GetZDelta() + temp_f31_975;
    temp_f1_980 = this->unk14.GetYDelta();
    var_f4_981 = 0.0f;
    sp28 = temp_f31_978;
    sp20 = 0.0f;
    sp24 = temp_f1_980;
    sp38 = (f64) sp28;
    sp30 = (f64) sp20;
    var_f5_996 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
    if (var_f5_996 > 1e-12f) {
        if (var_f5_996 > 0.0f) {
            temp_f1_1001 = __frsqrte(var_f5_996);
            temp_f1_1007 = 0.5 * temp_f1_1001 * -(((f64) var_f5_996 * (temp_f1_1001 * temp_f1_1001)) - 3.0);
            temp_f1_1011 = 0.5 * temp_f1_1007 * -(((f64) var_f5_996 * (temp_f1_1007 * temp_f1_1007)) - 3.0);
            var_f5_996 = (f32) ((f64) var_f5_996 * (0.5 * temp_f1_1011 * -(((f64) var_f5_996 * (temp_f1_1011 * temp_f1_1011)) - 3.0)));
        } else if (var_f5_996 < M2C_BITWISE(f32, 0.0)) {
            var_f5_996 = __float_nan;
        } else {
            sp8 = var_f5_996;
            temp_r3_1030 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1030) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1040 = 1;
                } else {
                    var_r0_1040 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1040 = 5;
                } else {
                    var_r0_1040 = 3;
                }
                break;
            default:
                var_r0_1040 = 4;
                break;
            }
            if (var_r0_1040 == 1) {
                var_f5_996 = __float_nan;
            }
        }
        var_f4_981 = 1.0f / var_f5_996;
    }
    sp14 = unksp34 * var_f4_981;
    sp10 = (f32) sp30 * var_f4_981;
    sp18 = (f32) sp38 * var_f4_981;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    if ((((f32) sp48 * MKVector3::up.unk8) + (((f32) sp40 * MKVector3::up.unk0) + (unksp44 * MKVector3::up.unk4))) > 0.8f) {
        this->unk28.Update(MKVector3::zero);
    } else {
        this->unk28.Update(arg0);
    }
    OverrideUpdate();
}
#endif

#if 0 // DRAFT: expression syntax error
void KDCameraSimpleDelta::ClearData() {
    this->unk28.ClearData();
    this->unk54 = 0;
    this->unk44 = 0;
    this->unk4C = 0.0f;
    this->unk48 = 0.0f;
    this->unk50 = 0.0f;
    this->unk14.SetStages(this->unk0, this->unk4, this->unk8);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDCameraSimpleDelta::Init(const KDCameraDeltaStages &arg0, float arg1, float arg2) {
    this->unk3C = arg1;
    this->unk40 = arg2;
    KDCameraDeltaStagesEx::Init(&this->unk3C, &this->unk40);
    KDCameraDeltaStagesEx::SetStages(arg0.unk0, arg0.unk4, arg0.unk8);
    this->unk14.Init(&this->unk3C, &this->unk40);
    this->unk14.SetStages(arg0.unk0, arg0.unk4, arg0.unk8);
    this->unk28.ClearData();
    ClearData();
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp14'
f32 KDCameraDeltaStagesEx::GetYDelta() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;
    f32 temp_f0_1193;
    f32 temp_f0_1201;
    f32 var_f1_1192;

    sp20.SetIdentity();
    var_f1_1192 = this->unk0;
    temp_f0_1193 = *this->unk10;
    if (var_f1_1192 < temp_f0_1193) {

    } else {
        var_f1_1192 = temp_f0_1193;
    }
    temp_f0_1201 = *this->unkC;
    if (var_f1_1192 > temp_f0_1201) {

    } else {
        var_f1_1192 = temp_f0_1201;
    }
    sp20.SetRotationPitch(var_f1_1192);
    sp10 = (f64) sp20.unk20;
    sp18 = (f64) sp20.unk28;
    return unksp14 * this->unk4;
}
#endif

f32 KDCameraDeltaStagesEx::GetZDelta() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;
    f32 temp_f0_1240;
    f32 temp_f0_1248;
    f32 var_f1_1239;

    sp20.SetIdentity();
    var_f1_1239 = this->unk0;
    temp_f0_1240 = *this->unk10;
    if (var_f1_1239 < temp_f0_1240) {

    } else {
        var_f1_1239 = temp_f0_1240;
    }
    temp_f0_1248 = *this->unkC;
    if (var_f1_1239 > temp_f0_1248) {

    } else {
        var_f1_1239 = temp_f0_1248;
    }
    sp20.SetRotationPitch(var_f1_1239);
    sp18 = (f64) sp20.unk28;
    sp10 = (f64) sp20.unk20;
    return (f32) sp18 * this->unk4;
}

void KDCameraDeltaStagesEx::SetStages(float arg0, float arg1, float arg2) {
    f32 temp_f0_1283;
    f32 temp_f0_1290;
    f32 var_f1_0;

    var_f1_0 = arg0;
    if (var_f1_0 > 10.0f) {
        gAssertBool = 0;
    }
    temp_f0_1283 = *this->unk10;
    if (var_f1_0 < temp_f0_1283) {

    } else {
        var_f1_0 = temp_f0_1283;
    }
    temp_f0_1290 = *this->unkC;
    if (var_f1_0 > temp_f0_1290) {

    } else {
        var_f1_0 = temp_f0_1290;
    }
    this->unk0 = var_f1_0;
    this->unk4 = arg1;
    this->unk8 = arg2;
}

void KDCameraDeltaStagesEx::Init(float *arg0, float *arg1) {
    this->unkC = arg0;
    this->unk10 = arg1;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk0 = 0.0f;
}

#if 0 // DRAFT: function call 'stricmp(const char[15])' does not match
s32 KDCameraDeltaStages::LoadLine(MKIniLine *arg0, char *arg1) {
    s8 *sp8;

    if ((s8) init_515 == 0) {
        pCurrentLoadingStage_514 = NULL;
        init_515 = 1;
    }
    if ((KDCameraDeltaStages *) pCurrentLoadingStage_514 == this) {
        if ((arg0->LoadFloat("pitch", &this->unk0, 0) != 0) || (arg0->LoadFloat("delta", &this->unk4, 0) != 0) || (arg0->LoadFloat("offset", &this->unk8, 0) != 0)) {
            return 1;
        }
        pCurrentLoadingStage_514 = NULL;
        goto block_8;
    }
block_8:
    arg0->GetFieldName();
    if (stricmp("deltaStageType") == 0) {
        sp8 = NULL;
        if ((arg0->AsString(0, &sp8) != 0) && (stricmp(sp8, arg1) == 0)) {
            pCurrentLoadingStage_514 = this;
            return 1;
        }
    }
    return 0;
}
#endif

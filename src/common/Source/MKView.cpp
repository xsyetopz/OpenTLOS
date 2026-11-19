#include "common/Source/MKView.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKView_GC.h"
#include <m2c_macros.h>

f64 tan(Matrix *, f32, f32);                        /* extern */
extern s32 MKView_SettingsCounter;
extern M2C_UNK gDisplay;
extern u8 init_236;
extern u8 init_245;
extern u8 init_254;
extern s32 lastCounter_253;
extern s32 oldCounter_235;
extern s32 oldCounter_244;
static Matrix ViewStack[0x20];
static Matrix worldToView_234;
static Matrix worldToScreen_243;
static Matrix projectionMatrix_252;
static Frustum viewFrustum_332;
static Frustum worldFrustum_333;
static Matrix *pStack = ViewStack;

f32 MKView_GetAspectRatio() {
    return pStack[1].unk20;
}

void MKView_SetAspectRatio(float arg0) {
    pStack[1].unk20 = arg0;
    MKView_SettingsCounter += 1;
}

#if 0 // DRAFT: illegal implicit conversion from 'Matrix *' to
f32 *MKView_GetOrthoRect() {
    return pStack + 0x64;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
Texture *MKView_GetRenderTarget(Texture **arg0) {
    if (arg0 != NULL) {
        *arg0 = pStack[1].unk3C;
    }
    return pStack[1].unk38;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
Frustum *MKView_GetWorldFrustum() {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_55;
    f32 temp_f0_56;
    f32 temp_f1_351;
    f32 temp_f1_60;
    f32 temp_f3_171;
    f32 temp_f4_61;
    f32 var_f10_166;
    f32 var_f5_365;
    f32 var_f6_185;
    f32 var_f6_272;
    f32 var_f7_94;
    f32 var_f8_346;
    f32 var_f9_256;
    f32 var_f9_82;
    f64 temp_f1_373;
    f64 temp_f1_379;
    f64 temp_f1_383;
    f64 temp_f2_193;
    f64 temp_f2_199;
    f64 temp_f2_203;
    f64 temp_f2_282;
    f64 temp_f2_288;
    f64 temp_f2_292;
    f64 temp_f3_102;
    f64 temp_f3_108;
    f64 temp_f3_112;
    f64 temp_f5_345;
    f64 temp_f6_165;
    s32 temp_r3_131;
    s32 temp_r3_222;
    s32 temp_r3_311;
    s32 temp_r3_402;
    s32 var_r0_141;
    s32 var_r0_232;
    s32 var_r0_321;
    s32 var_r0_412;

    temp_r3_55 = MKView_GetProjectionMatrix();
    temp_f0_56 = temp_r3_55->unk0;
    temp_f1_60 = temp_r3_55->unk14;
    temp_f4_61 = 1.0f / temp_f0_56;
    M2C_FIELD(&viewFrustum_332, f32 *, 0x50) = 0.0f;
    M2C_FIELD(&viewFrustum_332, f32 *, 0x54) = 0.0f;
    viewFrustum_332.unk58 = 0.0f;
    M2C_FIELD(&viewFrustum_332, f32 *, 0x68) = temp_f4_61;
    M2C_FIELD(&viewFrustum_332, f32 *, 0x6C) = (f32) (1.0f / temp_f1_60);
    if ((u8) M2C_FIELD(pStack, u8 *, 0x50) != 0) {
        viewFrustum_332.unk60 = 0.0f;
        viewFrustum_332.unk64 = 1.0f;
    } else {
        viewFrustum_332.unk60 = pStack[1].unk18;
        viewFrustum_332.unk64 = pStack[1].unk1C;
    }
    var_f9_82 = 0.0f;
    viewFrustum_332.unk0 = 0.0f;
    viewFrustum_332.unk4 = 0.0f;
    viewFrustum_332.unk8 = 1.0f;
    var_f7_94 = (1.0f * 1.0f) + ((temp_f0_56 * temp_f0_56) + (0.0f * 0.0f));
    viewFrustum_332.unk10 = temp_f0_56;
    viewFrustum_332.unk14 = 0.0f;
    viewFrustum_332.unk18 = 1.0f;
    if (var_f7_94 > 0.000001f) {
        if (var_f7_94 > 0.0f) {
            temp_f3_102 = __frsqrte(var_f7_94);
            temp_f3_108 = 0.5 * temp_f3_102 * -(((f64) var_f7_94 * (temp_f3_102 * temp_f3_102)) - 3.0);
            temp_f3_112 = 0.5 * temp_f3_108 * -(((f64) var_f7_94 * (temp_f3_108 * temp_f3_108)) - 3.0);
            var_f7_94 = (f32) ((f64) var_f7_94 * (0.5 * temp_f3_112 * -(((f64) var_f7_94 * (temp_f3_112 * temp_f3_112)) - 3.0)));
        } else if (var_f7_94 < M2C_BITWISE(f32, 0.0)) {
            var_f7_94 = __float_nan;
        } else {
            sp14 = var_f7_94;
            temp_r3_131 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_131) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_141 = 1;
                } else {
                    var_r0_141 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_141 = 5;
                } else {
                    var_r0_141 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_141 = 4;
                break;
            }
            if (var_r0_141 == 1) {
                var_f7_94 = __float_nan;
            }
        }
        var_f9_82 = 1.0f / var_f7_94;
    }
    temp_f6_165 = -temp_f0_56;
    var_f10_166 = 0.0f;
    temp_f3_171 = (f32) temp_f6_165;
    viewFrustum_332.unk10 *= var_f9_82;
    viewFrustum_332.unk20 = (f32) temp_f6_165;
    viewFrustum_332.unk24 = 0.0f;
    var_f6_185 = (1.0f * 1.0f) + ((temp_f3_171 * temp_f3_171) + (0.0f * 0.0f));
    viewFrustum_332.unk14 *= var_f9_82;
    viewFrustum_332.unk18 *= var_f9_82;
    viewFrustum_332.unk28 = 1.0f;
    if (var_f6_185 > 0.000001f) {
        if (var_f6_185 > 0.0f) {
            temp_f2_193 = __frsqrte(var_f6_185);
            temp_f2_199 = 0.5 * temp_f2_193 * -(((f64) var_f6_185 * (temp_f2_193 * temp_f2_193)) - 3.0);
            temp_f2_203 = 0.5 * temp_f2_199 * -(((f64) var_f6_185 * (temp_f2_199 * temp_f2_199)) - 3.0);
            var_f6_185 = (f32) ((f64) var_f6_185 * (0.5 * temp_f2_203 * -(((f64) var_f6_185 * (temp_f2_203 * temp_f2_203)) - 3.0)));
        } else if (var_f6_185 < M2C_BITWISE(f32, 0.0)) {
            var_f6_185 = __float_nan;
        } else {
            sp10 = var_f6_185;
            temp_r3_222 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_222) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_232 = 1;
                } else {
                    var_r0_232 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_232 = 5;
                } else {
                    var_r0_232 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_232 = 4;
                break;
            }
            if (var_r0_232 == 1) {
                var_f6_185 = __float_nan;
            }
        }
        var_f10_166 = 1.0f / var_f6_185;
    }
    var_f9_256 = 0.0f;
    viewFrustum_332.unk20 *= var_f10_166;
    var_f6_272 = (1.0f * 1.0f) + ((0.0f * 0.0f) + (temp_f1_60 * temp_f1_60));
    viewFrustum_332.unk30 = 0.0f;
    viewFrustum_332.unk24 *= var_f10_166;
    viewFrustum_332.unk28 *= var_f10_166;
    viewFrustum_332.unk34 = temp_f1_60;
    viewFrustum_332.unk38 = 1.0f;
    if (var_f6_272 > 0.000001f) {
        if (var_f6_272 > 0.0f) {
            temp_f2_282 = __frsqrte(var_f6_272);
            temp_f2_288 = 0.5 * temp_f2_282 * -(((f64) var_f6_272 * (temp_f2_282 * temp_f2_282)) - 3.0);
            temp_f2_292 = 0.5 * temp_f2_288 * -(((f64) var_f6_272 * (temp_f2_288 * temp_f2_288)) - 3.0);
            var_f6_272 = (f32) ((f64) var_f6_272 * (0.5 * temp_f2_292 * -(((f64) var_f6_272 * (temp_f2_292 * temp_f2_292)) - 3.0)));
        } else if (var_f6_272 < M2C_BITWISE(f32, 0.0)) {
            var_f6_272 = __float_nan;
        } else {
            spC = var_f6_272;
            temp_r3_311 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_311) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_321 = 1;
                } else {
                    var_r0_321 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_321 = 5;
                } else {
                    var_r0_321 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_321 = 4;
                break;
            }
            if (var_r0_321 == 1) {
                var_f6_272 = __float_nan;
            }
        }
        var_f9_256 = 1.0f / var_f6_272;
    }
    temp_f5_345 = -temp_f1_60;
    var_f8_346 = 0.0f;
    temp_f1_351 = (f32) temp_f5_345;
    viewFrustum_332.unk30 *= var_f9_256;
    viewFrustum_332.unk40 = 0.0f;
    viewFrustum_332.unk44 = (f32) temp_f5_345;
    var_f5_365 = (1.0f * 1.0f) + ((0.0f * 0.0f) + (temp_f1_351 * temp_f1_351));
    viewFrustum_332.unk34 *= var_f9_256;
    viewFrustum_332.unk38 *= var_f9_256;
    viewFrustum_332.unk48 = 1.0f;
    if (var_f5_365 > 0.000001f) {
        if (var_f5_365 > 0.0f) {
            temp_f1_373 = __frsqrte(var_f5_365);
            temp_f1_379 = 0.5 * temp_f1_373 * -(((f64) var_f5_365 * (temp_f1_373 * temp_f1_373)) - 3.0);
            temp_f1_383 = 0.5 * temp_f1_379 * -(((f64) var_f5_365 * (temp_f1_379 * temp_f1_379)) - 3.0);
            var_f5_365 = (f32) ((f64) var_f5_365 * (0.5 * temp_f1_383 * -(((f64) var_f5_365 * (temp_f1_383 * temp_f1_383)) - 3.0)));
        } else if (var_f5_365 < M2C_BITWISE(f32, 0.0)) {
            var_f5_365 = __float_nan;
        } else {
            sp8 = var_f5_365;
            temp_r3_402 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_402) {                  /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_412 = 1;
                } else {
                    var_r0_412 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_412 = 5;
                } else {
                    var_r0_412 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_412 = 4;
                break;
            }
            if (var_r0_412 == 1) {
                var_f5_365 = __float_nan;
            }
        }
        var_f8_346 = 1.0f / var_f5_365;
    }
    viewFrustum_332.unk40 *= var_f8_346;
    viewFrustum_332.unk44 *= var_f8_346;
    viewFrustum_332.unk48 *= var_f8_346;
    worldFrustum_333.ApplyMatrix(&viewFrustum_332, pStack);
    return &worldFrustum_333;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'BoundingVolume'
s32 MKView_VisibilityTest(const BoundingVolume &arg0, const Matrix &arg1) {
    Matrix sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f5_720;
    f32 temp_f6_718;
    f32 temp_f7_716;
    s32 temp_r5_795;
    s32 var_ctr_749;
    s32 var_r30_708;
    s32 var_r31_707;
    s32 var_r3_805;

    var_r31_707 = 0x3F;
    var_r30_708 = 0;
    sp30.Multiply4x4(&arg1, MKView_GetWorldToScreenMatrix());
    temp_f7_716 = arg0.unk0;
    temp_f6_718 = arg0.unk4;
    temp_f5_720 = arg0.unk8;
    sp10 = temp_f7_716;
    sp14 = temp_f6_718;
    sp18 = temp_f5_720;
    sp20 = temp_f7_716 + arg0.unk10;
    sp24 = temp_f6_718 + arg0.unk14;
    sp28 = temp_f5_720 + arg0.unk18;
    var_ctr_749 = 8;
    do {
        temp_r5_795 = (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 2 & ~1) | ((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1FU) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 4) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1CU) & 8) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1AU) & 0x10) | (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x19U) & 0x20);
        var_r30_708 |= temp_r5_795;
        var_r31_707 &= temp_r5_795;
        var_ctr_749 -= 1;
    } while (var_ctr_749 != 0);
    if (var_r31_707 != 0) {
        return 0;
    }
    var_r3_805 = 1;
    if (var_r30_708 != 0) {
        var_r3_805 = -1;
    }
    return var_r3_805;
}
#endif

#if 0 // DRAFT: function call 'tan(Matrix *, float)' does not match
void MKView_TransformPoint2Dto3D(float arg0, float arg1, float arg2, MKVector3 *arg3) {
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Matrix *temp_r31_855;
    f32 temp_f26_870;
    f32 temp_f27_871;
    f32 temp_f28_869;
    f32 temp_f29_863;
    f32 temp_f2_893;
    f32 temp_f2_919;
    f64 temp_f0_896;
    f64 temp_f0_922;

    temp_r31_855 = pStack;
    temp_f29_863 = arg2 * (f32) tan(pStack, 0.5f * pStack[1].unk14);
    temp_f28_869 = temp_f29_863 * temp_r31_855[1].unk20;
    temp_f26_870 = arg0 - ((0.5f * temp_r31_855[1].unk2C) + temp_r31_855[1].unk24);
    temp_f27_871 = arg1 - ((0.5f * temp_r31_855[1].unk30) + temp_r31_855[1].unk28);
    sp58.operator*(arg2);
    sp28 = M2C_FIELD(temp_r31_855, f64 *, 0x30) + M2C_BITWISE(f64, sp58);
    M2C_FIELD(arg3, f64 *, 0) = sp28;
    sp30 = temp_r31_855->unk38 + sp58.unk8;
    sp68 = sp28;
    M2C_FIELD(arg3, f64 *, 8) = (f64) sp30;
    sp70 = (f64) sp30;
    temp_f2_893 = temp_f28_869 * (temp_f26_870 / (0.5f * pStack[1].unk2C));
    temp_f0_896 = M2C_FIELD(temp_r31_855, f64 *, 0) * (f64) temp_f2_893;
    sp18 = temp_f0_896;
    sp48 = temp_f0_896;
    sp20 = temp_r31_855->unk8 * temp_f2_893;
    sp50 = (f64) sp20;
    M2C_FIELD(arg3, f64 *, 0) = (f64) (M2C_FIELD(arg3, f64 *, 0) + temp_f0_896);
    arg3->unk8 += (f32) sp50;
    temp_f2_919 = temp_f29_863 * (-temp_f27_871 / (0.5f * pStack[1].unk30));
    temp_f0_922 = M2C_FIELD(temp_r31_855, f64 *, 0x10) * (f64) temp_f2_919;
    sp8 = temp_f0_922;
    sp38 = temp_f0_922;
    sp10 = temp_r31_855->unk18 * temp_f2_919;
    sp40 = (f64) sp10;
    M2C_FIELD(arg3, f64 *, 0) = (f64) (M2C_FIELD(arg3, f64 *, 0) + temp_f0_922);
    arg3->unk8 += (f32) sp40;
}
#endif

f32 MKView_TransformPoint3Dto2D(MKVector3 *arg0, const MKVector3 &arg1) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    Matrix *temp_r3_970;
    f32 temp_f3_1019;
    f32 temp_f4_1051;
    f32 temp_f4_1062;
    f32 var_f31_967;

    var_f31_967 = 0.0f;
    temp_r3_970 = MKView_GetWorldToScreenMatrix();
    sp28 = arg1.unk0;
    sp2C = arg1.unk4;
    sp30 = arg1.unk8;
    sp58 = (f64) sp28;
    sp34 = 1.0f;
    sp60 = (f64) sp30;
    sp20 = ((*(f32 *) ((u8 *) &sp60 + 0x4)) * temp_r3_970->unk38) + (((f32) sp60 * temp_r3_970->unk28) + (((f32) sp58 * temp_r3_970->unk8) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_r3_970->unk18)));
    temp_f3_1019 = ((*(f32 *) ((u8 *) &sp60 + 0x4)) * temp_r3_970->unk34) + (((f32) sp60 * temp_r3_970->unk24) + (((f32) sp58 * temp_r3_970->unk4) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_r3_970->unk14)));
    sp24 = ((*(f32 *) ((u8 *) &sp60 + 0x4)) * temp_r3_970->unk3C) + (((f32) sp60 * temp_r3_970->unk2C) + (((f32) sp58 * temp_r3_970->unkC) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_r3_970->unk1C)));
    sp18 = ((*(f32 *) ((u8 *) &sp60 + 0x4)) * temp_r3_970->unk30) + (((f32) sp60 * temp_r3_970->unk20) + (((f32) sp58 * temp_r3_970->unk0) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_r3_970->unk10)));
    sp60 = (f64) sp20;
    sp1C = temp_f3_1019;
    sp50 = (f64) sp20;
    sp48 = (f64) sp18;
    sp58 = (f64) sp18;
    if ((*(f32 *) ((u8 *) &sp60 + 0x4)) != 0.0f) {
        var_f31_967 = 1.0f / (*(f32 *) ((u8 *) &sp60 + 0x4));
        sp8 = sp58 * (f64) var_f31_967;
        M2C_FIELD(arg0, f64 *, 0) = sp8;
        sp10 = (f32) sp60 * var_f31_967;
        sp38 = sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp10;
    }
    temp_f4_1051 = pStack[1].unk2C;
    arg0->unk0 = pStack[1].unk24 + ((0.5f * temp_f4_1051) + (0.5f * (arg0->unk0 * temp_f4_1051)));
    temp_f4_1062 = pStack[1].unk30;
    arg0->unk4 = pStack[1].unk28 + ((0.5f * temp_f4_1062) + (0.5f * (-arg0->unk4 * temp_f4_1062)));
    return var_f31_967;
}

s32 MKView_GetFlags() {
    return pStack[1].unk34;
}

u8 MKView_IsOrtho() {
    return M2C_FIELD(pStack, u8 *, 0x50);
}

void MKView_SetOrthoRect(const MKRect *arg0) {
    if (arg0 != NULL) {
        pStack[1].unk24 = arg0->unk0;
        pStack[1].unk28 = arg0->unk4;
        pStack[1].unk2C = arg0->unk8;
        pStack[1].unk30 = arg0->unkC;
    }
}

void MKView_SetOrtho(const MKRect *arg0) {
    MKView_SetCameraMatrix(Matrix::identity);
    M2C_FIELD(pStack, s8 *, 0x50) = 1;
    if (arg0 != NULL) {
        pStack[1].unk24 = arg0->unk0;
        pStack[1].unk28 = arg0->unk4;
        pStack[1].unk2C = arg0->unk8;
        pStack[1].unk30 = arg0->unkC;
    }
    MKView_SettingsCounter += 1;
}

void MKView_GetProjection(float *arg0, float *arg1, float *arg2) {
    f32 var_f0_1162;
    f32 var_f0_1175;

    if (arg0 != NULL) {
        *arg0 = pStack[1].unk14;
    }
    if (arg1 != NULL) {
        if ((u8) M2C_FIELD(pStack, u8 *, 0x50) != 0) {
            var_f0_1162 = 0.0f;
        } else {
            var_f0_1162 = pStack[1].unk18;
        }
        *arg1 = var_f0_1162;
    }
    if (arg2 != NULL) {
        if ((u8) M2C_FIELD(pStack, u8 *, 0x50) != 0) {
            var_f0_1175 = 1.0f;
        } else {
            var_f0_1175 = pStack[1].unk1C;
        }
        *arg2 = var_f0_1175;
    }
}

void MKView_SetProjection(float arg0, float arg1, float arg2) {
    M2C_FIELD(pStack, s8 *, 0x50) = 0;
    if (arg0 != 0.0f) {
        pStack[1].unk14 = arg0;
    }
    if (arg1 != 0.0f) {
        pStack[1].unk18 = arg1;
    }
    if (arg2 != 0.0f) {
        pStack[1].unk1C = arg2;
    }
    MKView_SettingsCounter += 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
Matrix *MKView_GetProjectionMatrix() {
    f32 temp_f2_1245;
    f32 temp_f2_1275;
    f32 temp_f31_1248;
    f32 temp_f3_1242;
    f32 temp_f3_1256;
    f32 temp_f3_1270;

    if ((s8) init_254 == 0) {
        lastCounter_253 = 0;
        init_254 = 1;
    }
    if ((s32) lastCounter_253 != (s32) MKView_SettingsCounter) {
        lastCounter_253 = MKView_SettingsCounter;
        projectionMatrix_252.SetZero();
        if ((u8) M2C_FIELD(pStack, u8 *, 0x50) == 0) {
            temp_f3_1242 = pStack[1].unk1C;
            temp_f2_1245 = temp_f3_1242 - pStack[1].unk18;
            temp_f31_1248 = temp_f3_1242 / temp_f2_1245;
            temp_f3_1256 = 1.0f / (f32) tan(M2C_BITWISE(Matrix *, (pStack[1].unk14 * 0.5f)), temp_f2_1245, temp_f3_1242);
            projectionMatrix_252.unk28 = temp_f31_1248;
            projectionMatrix_252.unk14 = temp_f3_1256;
            projectionMatrix_252.unk0 = temp_f3_1256 / pStack[1].unk20;
            projectionMatrix_252.unk2C = 1.0f;
            projectionMatrix_252.unk38 = -temp_f31_1248 * pStack[1].unk18;
        } else {
            temp_f3_1270 = pStack[1].unk2C;
            projectionMatrix_252.unk0 = 2.0f / temp_f3_1270;
            temp_f2_1275 = pStack[1].unk30;
            projectionMatrix_252.unk14 = -2.0f / temp_f2_1275;
            projectionMatrix_252.unk30 = -(1.0f + ((2.0f * pStack[1].unk24) / temp_f3_1270));
            projectionMatrix_252.unk28 = 1.0f;
            projectionMatrix_252.unk3C = 1.0f;
            projectionMatrix_252.unk34 = 1.0f + ((2.0f * pStack[1].unk28) / temp_f2_1275);
        }
    }
    return &projectionMatrix_252;
}
#endif

Matrix *MKView_GetWorldToScreenMatrix() {
    Matrix *temp_r31_1323;

    if ((s8) init_245 == 0) {
        oldCounter_244 = 0;
        init_245 = 1;
    }
    if ((s32) oldCounter_244 != (s32) MKView_SettingsCounter) {
        oldCounter_244 = MKView_SettingsCounter;
        temp_r31_1323 = MKView_GetProjectionMatrix();
        worldToScreen_243.Multiply4x4(MKView_GetWorldToViewMatrix(), temp_r31_1323);
    }
    return &worldToScreen_243;
}

Matrix *MKView_GetWorldToViewMatrix() {
    if ((s8) init_236 == 0) {
        oldCounter_235 = 0;
        init_236 = 1;
    }
    if ((s32) oldCounter_235 != (s32) MKView_SettingsCounter) {
        oldCounter_235 = MKView_SettingsCounter;
        M2C_STRUCT_COPY(&worldToView_234, pStack, 0x40);
        worldToView_234.InverseSimple(&worldToView_234);
    }
    return &worldToView_234;
}

Matrix *MKView_GetCameraMatrix() {
    return pStack;
}

void MKView_SetCameraMatrix(const Matrix &arg0) {
    M2C_STRUCT_COPY(pStack, &arg0, 0x40);
    MKView_SettingsCounter += 1;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void MKView_SetCameraLookAt(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    Matrix spB0;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    f32 sp90;                                       /* compiler-managed */
    f32 sp8C;
    f32 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f27_1640;
    f32 temp_f28_1642;
    f32 temp_f30_1531;
    f32 temp_f31_1533;
    f32 temp_f3_1638;
    f32 temp_f4_1536;
    f32 var_f2_1631;
    f32 var_f4_1461;
    f32 var_f4_1564;
    f32 var_f5_1432;
    f64 temp_f1_1466;
    f64 temp_f1_1472;
    f64 temp_f1_1476;
    f64 temp_f1_1570;
    f64 temp_f1_1576;
    f64 temp_f1_1580;
    s32 temp_r3_1495;
    s32 temp_r3_1599;
    s32 var_r0_1505;
    s32 var_r0_1609;

    var_f5_1432 = 0.0f;
    sp88 = 0.0f;
    sp8C = 1.0f;
    sp90 = 0.0f;
    sp38 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0);
    sp78 = sp38;
    sp40 = arg1.unk8 - arg0.unk8;
    sp80 = (f64) sp40;
    sp68 = sp38;
    sp70 = (f64) sp40;
    var_f4_1461 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + ((*(f32 *) ((u8 *) &sp70 + 0xc)) * (*(f32 *) ((u8 *) &sp70 + 0xc))));
    if (var_f4_1461 > 0.000001f) {
        if (var_f4_1461 > 0.0f) {
            temp_f1_1466 = __frsqrte(var_f4_1461);
            temp_f1_1472 = 0.5 * temp_f1_1466 * -(((f64) var_f4_1461 * (temp_f1_1466 * temp_f1_1466)) - 3.0);
            temp_f1_1476 = 0.5 * temp_f1_1472 * -(((f64) var_f4_1461 * (temp_f1_1472 * temp_f1_1472)) - 3.0);
            var_f4_1461 = (f32) ((f64) var_f4_1461 * (0.5 * temp_f1_1476 * -(((f64) var_f4_1461 * (temp_f1_1476 * temp_f1_1476)) - 3.0)));
        } else if (var_f4_1461 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1461 = __float_nan;
        } else {
            sp14 = var_f4_1461;
            temp_r3_1495 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_1495) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1505 = 1;
                } else {
                    var_r0_1505 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1505 = 5;
                } else {
                    var_r0_1505 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1505 = 4;
                break;
            }
            if (var_r0_1505 == 1) {
                var_f4_1461 = __float_nan;
            }
        }
        var_f5_1432 = 1.0f / var_f4_1461;
    }
    temp_f30_1531 = (*(f32 *) ((u8 *) &sp70 + 0xc)) * var_f5_1432;
    temp_f31_1533 = (f32) sp80 * var_f5_1432;
    temp_f4_1536 = (f32) sp78 * var_f5_1432;
    sp78 = temp_f4_1536;
    (*(f32 *) ((u8 *) &sp70 + 0xc)) = temp_f30_1531;
    sp80 = temp_f31_1533;
    sp28 = (sp8C * temp_f31_1533) - (sp90 * temp_f30_1531);
    sp2C = (sp90 * temp_f4_1536) - (sp88 * temp_f31_1533);
    sp30 = (sp88 * temp_f30_1531) - (sp8C * temp_f4_1536);
    sp98 = (f64) sp28;
    spA0 = (f64) sp30;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    var_f4_1564 = ((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + ((*(f32 *) ((u8 *) &sp8C + 0x10)) * (*(f32 *) ((u8 *) &sp8C + 0x10))));
    if (var_f4_1564 > 0.000001f) {
        if (var_f4_1564 > 0.0f) {
            temp_f1_1570 = __frsqrte(var_f4_1564);
            temp_f1_1576 = 0.5 * temp_f1_1570 * -(((f64) var_f4_1564 * (temp_f1_1570 * temp_f1_1570)) - 3.0);
            temp_f1_1580 = 0.5 * temp_f1_1576 * -(((f64) var_f4_1564 * (temp_f1_1576 * temp_f1_1576)) - 3.0);
            var_f4_1564 = (f32) ((f64) var_f4_1564 * (0.5 * temp_f1_1580 * -(((f64) var_f4_1564 * (temp_f1_1580 * temp_f1_1580)) - 3.0)));
        } else if (var_f4_1564 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1564 = __float_nan;
        } else {
            sp10 = var_f4_1564;
            temp_r3_1599 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1599) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1609 = 1;
                } else {
                    var_r0_1609 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1609 = 5;
                } else {
                    var_r0_1609 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1609 = 4;
                break;
            }
            if (var_r0_1609 == 1) {
                var_f4_1564 = __float_nan;
            }
        }
        var_f2_1631 = 1.0f / var_f4_1564;
    } else {
        var_f2_1631 = 0.0f;
    }
    temp_f3_1638 = (f32) sp98 * var_f2_1631;
    temp_f27_1640 = (*(f32 *) ((u8 *) &sp8C + 0x10)) * var_f2_1631;
    temp_f28_1642 = (f32) spA0 * var_f2_1631;
    sp98 = temp_f3_1638;
    (*(f32 *) ((u8 *) &sp8C + 0x10)) = temp_f27_1640;
    spA0 = temp_f28_1642;
    sp18 = (temp_f30_1531 * temp_f28_1642) - (temp_f31_1533 * temp_f27_1640);
    sp1C = (temp_f31_1533 * temp_f3_1638) - (sp78 * temp_f28_1642);
    sp20 = (sp78 * temp_f27_1640) - (temp_f30_1531 * temp_f3_1638);
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp88 = (f64) sp18;
    sp90 = (f64) sp20;
    pStack->SetIdentity();
    pStack->unk0 = sp98;
    pStack->unk4 = temp_f27_1640;
    pStack->unk8 = temp_f28_1642;
    pStack->unkC = 0.0f;
    pStack->unk10 = (f32) sp88;
    pStack->unk14 = sp8C;
    pStack->unk18 = (f32) sp90;
    pStack->unk1C = 0.0f;
    pStack->unk20 = sp78;
    pStack->unk24 = temp_f30_1531;
    pStack->unk28 = temp_f31_1533;
    pStack->unk2C = 0.0f;
    if (arg2 != 0.0f) {
        spB0.SetRotationRoll(arg2);
        pStack->Multiply3x3(&spB0, pStack);
    }
    pStack->unk30 = arg0.unk0;
    pStack->unk34 = arg0.unk4;
    pStack->unk38 = arg0.unk8;
    pStack->unk3C = 1.0f;
    MKView_SettingsCounter += 1;
}
#endif

void MKView_GetViewport() {

}

void MKView_Pop() {
    pStack -= 0x80;
    MKView_SettingsCounter += 1;
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MKView_Push() {
    M2C_STRUCT_COPY((s32) (pStack + 0x7C) + 4, (s32) (pStack - 4) + 4, 0x40);
    pStack[3].unk0 = pStack[1].unk0;
    pStack[3].unk4 = pStack[1].unk4;
    pStack[3].unk8 = pStack[1].unk8;
    pStack[3].unkC = pStack[1].unkC;
    M2C_FIELD(pStack, u8 *, 0xD0) = (u8) M2C_FIELD(pStack, u8 *, 0x50);
    pStack[3].unk14 = pStack[1].unk14;
    pStack[3].unk18 = pStack[1].unk18;
    pStack[3].unk1C = pStack[1].unk1C;
    pStack[3].unk20 = pStack[1].unk20;
    pStack[3].unk24 = pStack[1].unk24;
    pStack[3].unk28 = pStack[1].unk28;
    pStack[3].unk2C = pStack[1].unk2C;
    pStack[3].unk30 = pStack[1].unk30;
    pStack[3].unk34 = pStack[1].unk34;
    pStack[3].unk38 = pStack[1].unk38;
    pStack[3].unk3C = pStack[1].unk3C;
    pStack += 0x80;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Texture *' to
void MKView_SetRenderTarget(Texture *arg0, Texture *arg1) {
    pStack[1].unk38 = arg0;
    pStack[1].unk3C = arg1;
    MKView_SettingsCounter += 1;
}
#endif

void MKView_InitModule() {
    f64 spE0;
    f64 spD8;
    f64 spD0;
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
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    memset(pStack, 0, 0x80U);
    pStack[1].unk8 = (f32) M2C_FIELD(&gDisplay, s32 *, 0x10);
    pStack[1].unkC = (f32) M2C_FIELD(&gDisplay, s32 *, 0x14);
    pStack[1].unk2C = 640.0f;
    pStack[1].unk30 = 512.0f;
    pStack->SetIdentity();
    pStack[1].unk14 = 1.0471976f;
    pStack[1].unk18 = 1.0f;
    sp68 = 0.2f;
    pStack[1].unk1C = 100000.0f;
    sp6C = 0.2f;
    M2C_FIELD(pStack, s8 *, 0x50) = 0;
    sp70 = 0.2f;
    pStack[1].unk20 = 1.3333334f;
    sp74 = 1.0f;
    MKView_SettingsCounter = 0;
    spD8 = (f64) sp68;
    spE0 = (f64) sp70;
    MKView_SetAmbientColor(*((MKVector4 *) &spD8));
    sp60 = 0.0f;
    sp58 = 1.0f;
    sp5C = 0.0f;
    spD0 = (f64) sp60;
    spC8 = (f64) sp58;
    MKView_SetLightDirection(0, *((MKVector3 *) &spC8));
    sp50 = 0.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    spC0 = (f64) sp50;
    spB8 = (f64) sp48;
    MKView_SetLightDirection(1, *((MKVector3 *) &spB8));
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 1.0f;
    spA8 = (f64) sp38;
    spB0 = (f64) sp40;
    MKView_SetLightDirection(2, *((MKVector3 *) &spA8));
    sp28 = 1.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    sp34 = 1.0f;
    sp98 = (f64) sp28;
    spA0 = (f64) sp30;
    MKView_SetLightColor(0, *((MKVector4 *) &sp98));
    sp18 = 0.0f;
    sp1C = 1.0f;
    sp20 = 0.0f;
    sp24 = 1.0f;
    sp88 = (f64) sp18;
    sp90 = (f64) sp20;
    MKView_SetLightColor(1, *((MKVector4 *) &sp88));
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp78 = (f64) sp8;
    sp80 = (f64) sp10;
    MKView_SetLightColor(2, *((MKVector4 *) &sp78));
    MKView_Push();
    MKMaterial_SetLocalToWorld(NULL, 1.0f);
}

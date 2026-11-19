#include "common/Source/MKFont.h"
#include "common/Source/Font.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

f64 fmod(f32, f32);                                 /* extern */
extern MKFont *gpDebugFont;
static f32 gFontTabWidth = 100.0f;
static GeometryTransformationInfo transformInfo_299 = { 1, 0 };
static u32 lit_376 = 1U;

#if 0 // DRAFT: function call 'MKFont_GetNextWrapPoint(MKFont *, signed char *, float, float, int *)' does not match 'MKFont_GetNextWrapPoint(MKFont *, const char *, float, flo
f32 MKFont_DrawStringJustified(MKFont *arg0, const char *arg1, const MKVector3 &arg2, float arg3, float arg4, FontJustify arg5, float arg6, const MKVector4 &arg7, int arg8, const Matrix &arg9) {
    f64 sp38;
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    s32 sp8;
    f32 temp_f1_102;
    f32 temp_f28_79;
    f32 temp_f31_43;
    f32 var_f27_46;
    f64 temp_f0_119;
    s32 temp_r31_90;
    s8 *var_r30_40;

    sp30 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp38 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r30_40 = (signed char *) (arg1);
    temp_f31_43 = MKFontInternal_CalcHeightAndScale(arg0, arg6, &spC);
    if ((s32) arg5 > 3) {
        var_f27_46 = 0.0f;
loop_3:
        if ((s8) (u8) *var_r30_40 != 0) {
            MKFont_GetNextWrapPoint(arg0, var_r30_40, arg3, arg6, (int *) &sp8);
            var_f27_46 += temp_f31_43;
            var_r30_40 = &var_r30_40[M2C_ERROR(/* Read from unset register $r3 */)];
            goto loop_3;
        }
        if (((s32) arg5 != 4) && ((s32) arg5 != 5) && ((s32) arg5 != 6)) {
            (*(f32 *) ((u8 *) &sp28 + 0xc)) = arg4 - var_f27_46;
        } else {
            (*(f32 *) ((u8 *) &sp28 + 0xc)) = (0.5f * arg4) - (0.5f * var_f27_46);
        }
        var_r30_40 = (signed char *) (arg1);
    }
    temp_f28_79 = arg2.unk8;
loop_20:
    if ((s8) (u8) *var_r30_40 != 0) {
        MKFont_GetNextWrapPoint(arg0, var_r30_40, arg3, arg6, (int *) &sp8);
        temp_r31_90 = M2C_ERROR(/* Read from unset register $r3 */);
        if (((s32) arg5 != 0) && ((s32) arg5 != 4) && ((s32) arg5 != 8)) {
            temp_f1_102 = MKFont_CalculateWidth(arg0, var_r30_40, arg6, arg3, temp_r31_90, NULL);
            if (((s32) arg5 != 1) && ((s32) arg5 != 5) && ((s32) arg5 != 9)) {
                sp30 = arg3 - temp_f1_102;
            } else {
                sp30 = -((0.5f * temp_f1_102) - (0.5f * arg3));
            }
        }
        temp_f0_119 = (f64) sp30 + M2C_FIELD(&arg2, f64 *, 0);
        sp10 = temp_f0_119;
        sp20 = temp_f0_119;
        sp18 = (f32) sp38 + temp_f28_79;
        sp28 = (f64) sp18;
        MKFont_DrawString(arg0, var_r30_40, *((MKVector3 *) &sp20), arg6, arg7, sp8, arg9);
        var_r30_40 = &var_r30_40[temp_r31_90];
        (*(f32 *) ((u8 *) &sp28 + 0xc)) += temp_f31_43;
        goto loop_20;
    }
    return (*(f32 *) ((u8 *) &sp28 + 0xc));
}
#endif

#if 0 // DRAFT: pointer/array required
void MKFont_GetCharPosJustified(MKFont *arg0, const char *arg1, int arg2, float arg3, float arg4, FontJustify arg5, float arg6) {
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    MKFont sp10;
    f32 spC;
    s32 sp8;
    f32 temp_f1_257;
    f32 temp_f31_197;
    f32 var_f30_200;
    s32 temp_r30_192;
    s32 temp_r5_239;
    s32 var_r29_191;
    s32 var_r31_193;

    sp20 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp28 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r29_191 = (s32) arg5;
    temp_r30_192 = M2C_ERROR(/* Read from unset register $r7 */);
    var_r31_193 = arg2;
    temp_f31_197 = MKFontInternal_CalcHeightAndScale((MKFont *) arg1, arg6, &spC);
    if (temp_r30_192 > 3) {
        var_f30_200 = 0.0f;
loop_3:
        if ((s8) *var_r31_193 != 0) {
            MKFont_GetNextWrapPoint((MKFont *) arg1, (s8 *) var_r31_193, arg3, arg6, (int *) &sp8);
            var_f30_200 += temp_f31_197;
            var_r31_193 += M2C_ERROR(/* Read from unset register $r3 */);
            goto loop_3;
        }
        if ((temp_r30_192 != 4) && (temp_r30_192 != 5) && (temp_r30_192 != 6)) {
            (*(f32 *) ((u8 *) &sp10 + 0x14)) = arg4 - var_f30_200;
        } else {
            (*(f32 *) ((u8 *) &sp10 + 0x14)) = (0.5f * arg4) - (0.5f * var_f30_200);
        }
        var_r31_193 = arg2;
    }
loop_22:
    if ((s8) *var_r31_193 != 0) {
        MKFont_GetNextWrapPoint((MKFont *) arg1, (s8 *) var_r31_193, arg3, arg6, (int *) &sp8);
        temp_r5_239 = M2C_ERROR(/* Read from unset register $r3 */);
        if ((var_r29_191 < temp_r5_239) || ((s8) *(var_r31_193 + temp_r5_239) == 0)) {
            if ((temp_r30_192 != 0) && (temp_r30_192 != 4) && (temp_r30_192 != 8)) {
                temp_f1_257 = MKFont_CalculateWidth((MKFont *) arg1, (s8 *) var_r31_193, arg6, arg3, temp_r5_239, NULL);
                if ((temp_r30_192 != 1) && (temp_r30_192 != 5) && (temp_r30_192 != 9)) {
                    sp20 = arg3 - temp_f1_257;
                } else {
                    sp20 = (0.5f * arg3) - (0.5f * temp_f1_257);
                }
            }
            MKFont_GetCharPos(&sp10, arg1, var_r31_193, arg6);
            sp20 = (f64) sp20 + M2C_BITWISE(f64, sp10);
            sp28 = (f32) sp28 + M2C_BITWISE(f32, sp10.unk8);
        } else {
            var_r31_193 += temp_r5_239;
            var_r29_191 -= temp_r5_239;
            (*(f32 *) ((u8 *) &sp10 + 0x14)) += temp_f31_197;
            goto loop_22;
        }
    }
    arg0->unk0 = sp20;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp28;
}
#endif

#if 0 // DRAFT: pointer/array required
void MKFont_GetNextWrapPoint(MKFont *arg0, const char *arg1, float arg2, float arg3, int *arg4) {
    f32 sp8;
    f32 temp_f29_349;
    f32 var_f30_338;
    s32 temp_r5_468;
    s32 var_ctr_419;
    s8 *var_r31_341;
    s8 *var_r4_355;
    s8 *var_r4_418;
    u32 temp_r0_442;
    u32 var_r3_441;
    u8 temp_r0_360;
    u8 temp_r0_423;
    u8 temp_r0_471;
    u8 temp_r5_454;
    u8 var_r3_361;
    u8 var_r3_424;
    u8 var_r4_469;

    var_f30_338 = 0.0f;
    var_r31_341 = (signed char *) (arg1);
    MKFontInternal_CalcHeightAndScale(arg0, arg3, &sp8);
    temp_f29_349 = M2C_FIELD(**arg0, f32 *, 8) * sp8;
loop_31:
    temp_r5_454 = (u8) *var_r31_341;
    switch ((s8) temp_r5_454) {                     /* irregular */
    case 0x3C:
        var_r4_355 = var_r31_341 + 1;
loop_4:
        temp_r0_360 = (u8) *var_r4_355;
        var_r3_361 = 0;
        if (((s8) temp_r0_360 == 0x20) || ((s8) temp_r0_360 == 9) || ((s8) temp_r0_360 == 0xA)) {
            var_r3_361 = 1;
        }
        if (var_r3_361 != 0) {
            var_r4_355 += 1;
            goto loop_4;
        }
    default:
        var_f30_338 += (sp8 * *(M2C_FIELD(**arg0, s32 *, 0x28) + (((s8) temp_r5_454 << 5) + 0x18))) + temp_f29_349;
block_17:
        if ((arg2 > 0.0f) && (var_f30_338 > arg2)) {
            var_r4_418 = var_r31_341;
            var_ctr_419 = var_r31_341 - arg1;
            if (var_r31_341 > arg1) {
loop_20:
                temp_r0_423 = (u8) *var_r4_418;
                var_r3_424 = 0;
                if (((s8) temp_r0_423 == 0x20) || ((s8) temp_r0_423 == 9)) {
                    var_r3_424 = 1;
                }
                if (var_r3_424 != 0) {
                    var_r31_341 = var_r4_418 + 1;
                } else {
                    var_r4_418 -= 1;
                    var_ctr_419 -= 1;
                    if (var_ctr_419 != 0) {
                        goto loop_20;
                    }
                }
            }
            var_r3_441 = lit_376;
            temp_r0_442 = var_r31_341 - arg1;
            if (temp_r0_442 > var_r3_441) {
                var_r3_441 = temp_r0_442;
            }
            if (var_r4_418 == arg1) {
                var_r31_341 = (signed char *) (&arg1[var_r3_441]);
            }
        } else {
            var_r31_341 += 1;
            goto loop_31;
        }
        break;
    case 0x20:
        var_f30_338 += M2C_FIELD(**arg0, f32 *, 0xC) * sp8;
        goto block_17;
    case 0xA:
        var_r31_341 += 1;
        break;
    case 0x9:
        var_f30_338 = (var_f30_338 + gFontTabWidth) - (f32) fmod(var_f30_338, gFontTabWidth);
        goto block_17;
    }
    if (arg4 != NULL) {
        *arg4 = var_r31_341 - arg1;
loop_35:
        temp_r5_468 = *arg4;
        var_r4_469 = 0;
        temp_r0_471 = M2C_FIELD(&arg1[temp_r5_468], u8 *, -1);
        if (((s8) temp_r0_471 == 0x20) || ((s8) temp_r0_471 == 9) || ((s8) temp_r0_471 == 0xA)) {
            var_r4_469 = 1;
        }
        if ((var_r4_469 != 0) && (temp_r5_468 > 0)) {
            *arg4 -= 1;
            goto loop_35;
        }
    }
}
#endif

void MKFont_DrawDebugStringF(const char *arg0, float arg1, float arg2, float arg3, const MKVector4 &arg4, int arg5, MKFont *arg6) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKFont *var_r6_0;

    var_r6_0 = arg6;
    if (var_r6_0 == NULL) {
        var_r6_0 = gpDebugFont;
    }
    sp8 = arg1;
    spC = arg2;
    sp10 = 0.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    MKFont_DrawString(var_r6_0, arg0, *((MKVector3 *) &sp18), arg3, arg4, arg5, Matrix::identity);
}

f32 MKFont_DrawString(MKFont *arg0, const char *arg1, const MKVector3 &arg2, float arg3, const MKVector4 &arg4, int arg5, const Matrix &arg6) {
    f64 sp18;
    f64 sp10;                                       /* compiler-managed */
    f32 sp8;
    Texture *temp_r3_582;
    f32 temp_f21_722;
    f32 temp_f22_721;
    f32 temp_f23_719;
    f32 temp_f24_718;
    f32 temp_f24_739;
    f32 temp_f25_725;
    f32 temp_f26_720;
    f32 temp_f26_727;
    f32 temp_f26_753;
    f32 temp_f27_607;
    f32 temp_f28_606;
    f32 temp_f29_608;
    f32 temp_f30_602;
    f32 temp_f31_580;
    s32 temp_r0_625;
    s32 temp_r29_634;
    s32 temp_r3_609;
    s8 *var_r27_575;
    s8 *var_r5_656;
    u32 var_r26_650;
    u8 temp_r0_661;
    u8 temp_r4_797;
    u8 var_r3_662;
    void *temp_r4_715;
    void *temp_r6_591;

    sp10 = M2C_FIELD(&arg2, f64 *, 0);
    var_r27_575 = (signed char *) (arg1);
    sp18 = M2C_FIELD(&arg2, f64 *, 8);
    temp_f31_580 = MKFontInternal_CalcHeightAndScale(arg0, arg3, &sp8);
    temp_r3_582 = MKMat_MK2_GetBaseTexture(*M2C_FIELD(arg0, MKMaterial ***, 4));
    temp_r6_591 = *M2C_FIELD(arg0, void ***, 0);
    temp_f30_602 = 0.5f / (f32) temp_r3_582->unk24;
    temp_f28_606 = M2C_FIELD(temp_r6_591, f32 *, 8) * sp8;
    temp_f27_607 = M2C_FIELD(temp_r6_591, f32 *, 0xC) * sp8;
    temp_f29_608 = 0.5f / (f32) temp_r3_582->unk28;
    temp_r3_609 = MKFont_GetNumRenderableChars(arg1, arg5);
    if (temp_r3_609 == 0) {
        return 0.0f;
    }
    MKMaterial_SetGeometryTransformInfo(&transformInfo_299);
    MKMaterial_SetMaterial(*M2C_FIELD(arg0, MKMaterial ***, 4));
loop_26:
    if (MKMaterial_Begin() != 0) {
        MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 0);
        temp_r0_625 = M2C_ERROR(/* Read from unset register $r3 */);
        MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 1);
        MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 3);
        temp_r29_634 = M2C_ERROR(/* Read from unset register $r3 */);
        MKMaterial_SetLocalToWorld(&arg6, 1.0f);
loop_25:
        if (MKMaterial_BeginInternal() != 0) {
            MKMaterial_RenderImmediateBegin(4U, 0U);
            MKMaterial_RenderVerticesBegin(temp_r3_609 * 6);
            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), arg4.unk0, arg4.unk4, arg4.unk8, arg4.unkC);
            var_r26_650 = 0U;
loop_22:
            temp_r4_797 = (u8) *var_r27_575;
            if (((s8) temp_r4_797 != 0) && (var_r26_650 < (u32) arg5)) {
                switch ((s8) temp_r4_797) {         /* irregular */
                case 0x3C:
                    var_r5_656 = var_r27_575 + 1;
loop_8:
                    temp_r0_661 = (u8) *var_r5_656;
                    var_r3_662 = 0;
                    if (((s8) temp_r0_661 == 0x20) || ((s8) temp_r0_661 == 9) || ((s8) temp_r0_661 == 0xA)) {
                        var_r3_662 = 1;
                    }
                    if (var_r3_662 != 0) {
                        var_r5_656 += 1;
                        goto loop_8;
                    }
                default:
                    temp_r4_715 = (void *) (M2C_FIELD(*M2C_FIELD(arg0, void ***, 0), s32 *, 0x28) + ((s8) temp_r4_797 << 5));
                    temp_f24_718 = M2C_FIELD(temp_r4_715, f32 *, 8);
                    temp_f23_719 = sp8 * M2C_FIELD(temp_r4_715, f32 *, 0x18);
                    temp_f26_720 = M2C_FIELD(temp_r4_715, f32 *, 0xC);
                    temp_f22_721 = M2C_FIELD(temp_r4_715, f32 *, 0x10);
                    temp_f21_722 = M2C_FIELD(temp_r4_715, f32 *, 0x14);
                    MKMaterial_SetVertex4F(temp_r0_625, sp10, (*(f32 *) ((u8 *) &sp8 + 0xc)), (f32) sp18, 1.0f);
                    temp_f25_725 = temp_f24_718 + temp_f30_602;
                    temp_f26_727 = temp_f26_720 + temp_f29_608;
                    MKMaterial_SetVertex4F(temp_r29_634, temp_f25_725, temp_f26_727, 0.0f, 1.0f);
                    MKMaterial_SetVertex4F(temp_r0_625, sp10, (*(f32 *) ((u8 *) &sp8 + 0xc)), (f32) sp18, 1.0f);
                    temp_f24_739 = temp_f22_721 + temp_f30_602;
                    MKMaterial_SetVertex4F(temp_r29_634, temp_f24_739, temp_f26_727, 0.0f, 1.0f);
                    MKMaterial_SetVertex4F(temp_r0_625, sp10 + temp_f23_719, (*(f32 *) ((u8 *) &sp8 + 0xc)), (f32) sp18, 1.0f);
                    temp_f26_753 = temp_f21_722 + temp_f29_608;
                    MKMaterial_SetVertex4F(temp_r29_634, temp_f25_725, temp_f26_753, 0.0f, 1.0f);
                    MKMaterial_SetVertex4F(temp_r0_625, sp10, (*(f32 *) ((u8 *) &sp8 + 0xc)) + temp_f31_580, (f32) sp18, 1.0f);
                    MKMaterial_SetVertex4F(temp_r29_634, temp_f24_739, temp_f26_753, 0.0f, 1.0f);
                    MKMaterial_SetVertex4F(temp_r0_625, sp10 + temp_f23_719, (*(f32 *) ((u8 *) &sp8 + 0xc)) + temp_f31_580, (f32) sp18, 1.0f);
                    MKMaterial_SetVertex4F(temp_r0_625, sp10 + temp_f23_719, (*(f32 *) ((u8 *) &sp8 + 0xc)) + temp_f31_580, (f32) sp18, 1.0f);
                    sp10 += temp_f23_719 + temp_f28_606;
                    break;
                case 0x20:
                    sp10 = (f32) sp10 + temp_f27_607;
                    break;
                case 0xA:
                    sp10 = arg2.unk0;
                    (*(f32 *) ((u8 *) &sp8 + 0xc)) += temp_f31_580;
                    break;
                case 0x9:
                    sp10 = (sp10 + gFontTabWidth) - (f32) fmod(sp10, gFontTabWidth);
                    break;
                }
                var_r27_575 += 1;
                var_r26_650 += 1;
                goto loop_22;
            }
            MKMaterial_RenderVerticesEnd();
            MKMaterial_RenderImmediateEnd();
            goto loop_25;
        }
        goto loop_26;
    }
    return temp_f31_580 + ((*(f32 *) ((u8 *) &sp8 + 0xc)) - arg2.unk4);
}

#if 0 // DRAFT: type mismatch 'signed char *' and 'const char *'
s32 MKFont_GetNumRenderableChars(const char *arg0, int arg1) {
    s32 var_r7_850;
    s8 *var_r6_851;
    u8 temp_r5_876;
    u8 var_r0_861;

    var_r7_850 = 0;
    var_r6_851 = (signed char *) (arg0);
loop_10:
    temp_r5_876 = (u8) *var_r6_851;
    if (((s8) temp_r5_876 != 0) && ((u32) (var_r6_851 - arg0) < (u32) arg1)) {
        if ((s8) temp_r5_876 == 0x3C) {
            var_r7_850 += 1;
        } else {
            var_r0_861 = 0;
            if (((s8) temp_r5_876 == 0x20) || ((s8) temp_r5_876 == 9) || ((s8) temp_r5_876 == 0xA)) {
                var_r0_861 = 1;
            }
            if (var_r0_861 == 0) {
                var_r7_850 += 1;
            }
        }
        var_r6_851 += 1;
        goto loop_10;
    }
    return var_r7_850;
}
#endif

#if 0 // DRAFT: pointer/array required
void MKFont_GetCharPos(MKFont *arg0, const char *arg1, int arg2, float arg3) {
    f64 sp18;
    f64 sp10;                                       /* compiler-managed */
    f32 sp8;
    f32 temp_f29_921;
    f32 temp_f30_920;
    f32 temp_f31_915;
    s32 var_r31_909;
    u8 *var_r4_927;
    u8 temp_r0_932;
    u8 temp_r5_993;
    u8 var_r3_933;
    void *temp_r3_917;

    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    var_r31_909 = arg2;
    sp18 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_f31_915 = MKFontInternal_CalcHeightAndScale((MKFont *) arg1, arg3, &sp8);
    temp_r3_917 = **arg1;
    temp_f30_920 = M2C_FIELD(temp_r3_917, f32 *, 8) * sp8;
    temp_f29_921 = M2C_FIELD(temp_r3_917, f32 *, 0xC) * sp8;
loop_18:
    temp_r5_993 = *var_r31_909;
    if (((s8) temp_r5_993 != 0) && ((u32) (var_r31_909 - arg2) < (u32) M2C_ERROR(/* Read from unset register $r6 */))) {
        switch ((s8) temp_r5_993) {                 /* irregular */
        case 0x3C:
            var_r4_927 = (unsigned char *) (var_r31_909 + 1);
loop_4:
            temp_r0_932 = *var_r4_927;
            var_r3_933 = 0;
            if (((s8) temp_r0_932 == 0x20) || ((s8) temp_r0_932 == 9) || ((s8) temp_r0_932 == 0xA)) {
                var_r3_933 = 1;
            }
            if (var_r3_933 != 0) {
                var_r4_927 += 1;
                goto loop_4;
            }
        default:
            sp10 += (sp8 * *(M2C_FIELD(**arg1, s32 *, 0x28) + (((s8) temp_r5_993 << 5) + 0x18))) + temp_f30_920;
            break;
        case 0x20:
            sp10 = (f32) sp10 + temp_f29_921;
            break;
        case 0xA:
            sp10 = 0.0f;
            (*(f32 *) ((u8 *) &sp8 + 0xc)) += temp_f31_915;
            break;
        case 0x9:
            sp10 = (sp10 + gFontTabWidth) - (f32) fmod(sp10, gFontTabWidth);
            break;
        }
        var_r31_909 += 1;
        goto loop_18;
    }
    arg0->unk0 = (f64) sp10;
    M2C_FIELD(arg0, f64 *, 8) = sp18;
}
#endif

#if 0 // DRAFT: pointer/array required
f32 MKFont_CalculateWidth(MKFont *arg0, const char *arg1, float arg2, float arg3, int arg4, float *arg5) {
    f64 sp18;
    f64 sp10;                                       /* compiler-managed */
    f32 sp8;
    f32 temp_f28_1059;
    f32 temp_f29_1058;
    f32 temp_f31_1051;
    f32 var_f1_1095;
    f32 var_f30_1040;
    f32 var_f3_1144;
    s32 var_ctr_1147;
    s32 var_r29_1053;
    s8 *var_r30_1046;
    s8 *var_r31_1045;
    s8 *var_r4_1065;
    s8 *var_r6_1145;
    u8 temp_r0_1070;
    u8 temp_r4_1153;
    u8 temp_r5_1206;
    u8 var_r0_1152;
    u8 var_r3_1071;
    void *temp_r3_1054;

    var_f30_1040 = 0.0f;
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    var_r31_1045 = (signed char *) (arg1);
    var_r30_1046 = (signed char *) (arg1);
    sp18 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_f31_1051 = MKFontInternal_CalcHeightAndScale(arg0, arg2, &sp8);
    var_r29_1053 = 0;
    temp_r3_1054 = **arg0;
    temp_f29_1058 = M2C_FIELD(temp_r3_1054, f32 *, 8) * sp8;
    temp_f28_1059 = M2C_FIELD(temp_r3_1054, f32 *, 0xC) * sp8;
loop_35:
    temp_r5_1206 = (u8) *var_r31_1045;
    if (((s8) temp_r5_1206 != 0) && (var_r29_1053 < arg4)) {
        switch ((s8) temp_r5_1206) {                /* irregular */
        case 0x3C:
            var_r4_1065 = var_r31_1045 + 1;
loop_4:
            temp_r0_1070 = (u8) *var_r4_1065;
            var_r3_1071 = 0;
            if (((s8) temp_r0_1070 == 0x20) || ((s8) temp_r0_1070 == 9) || ((s8) temp_r0_1070 == 0xA)) {
                var_r3_1071 = 1;
            }
            if (var_r3_1071 != 0) {
                var_r4_1065 += 1;
                goto loop_4;
            }
        default:
            sp10 += (sp8 * *(M2C_FIELD(**arg0, s32 *, 0x28) + (((s8) temp_r5_1206 << 5) + 0x18))) + temp_f29_1058;
            break;
        case 0x20:
            sp10 = (f32) sp10 + temp_f28_1059;
            break;
        case 0xA:
            var_f1_1095 = sp10;
            if (var_f1_1095 > var_f30_1040) {

            } else {
                var_f1_1095 = var_f30_1040;
            }
            var_f30_1040 = var_f1_1095;
            var_r30_1046 = var_r31_1045 + 1;
            sp10 = 0.0f;
            (*(f32 *) ((u8 *) &sp10 + 0x4)) += temp_f31_1051;
            break;
        case 0x9:
            sp10 = (sp10 + gFontTabWidth) - (f32) fmod(sp10, gFontTabWidth);
            break;
        }
        if ((arg3 > 0.0f) && (sp10 > arg3)) {
            var_f3_1144 = sp10;
            var_r6_1145 = var_r31_1045;
            var_ctr_1147 = var_r31_1045 - var_r30_1046;
            if (var_r31_1045 > var_r30_1046) {
loop_23:
                var_r0_1152 = 0;
                temp_r4_1153 = (u8) *var_r6_1145;
                var_f3_1144 -= (sp8 * *(M2C_FIELD(**arg0, s32 *, 0x28) + (((s8) temp_r4_1153 << 5) + 0x18))) + temp_f29_1058;
                if (((s8) temp_r4_1153 == 0x20) || ((s8) temp_r4_1153 == 9)) {
                    var_r0_1152 = 1;
                }
                if (var_r0_1152 != 0) {
                    var_r31_1045 = var_r6_1145 + 1;
                } else {
                    var_r6_1145 -= 1;
                    var_ctr_1147 -= 1;
                    if (var_ctr_1147 != 0) {
                        goto loop_23;
                    }
                }
            }
            if (var_r6_1145 == var_r30_1046) {
                var_f3_1144 = sp10 - ((sp8 * *(M2C_FIELD(**arg0, s32 *, 0x28) + (((s8) (u8) *var_r31_1045 << 5) + 0x18))) + temp_f29_1058);
            }
            if (var_f3_1144 > var_f30_1040) {
                var_f30_1040 = var_f3_1144;
            }
            var_r30_1046 = var_r31_1045;
            sp10 = 0.0f;
            (*(f32 *) ((u8 *) &sp10 + 0x4)) += temp_f31_1051;
        }
        var_r31_1045 += 1;
        var_r29_1053 += 1;
        goto loop_35;
    }
    if (arg5 != NULL) {
        *arg5 = (*(f32 *) ((u8 *) &sp10 + 0x4)) + temp_f31_1051;
    }
    if (sp10 > var_f30_1040) {
        return sp10;
    }
    return var_f30_1040;
}
#endif

f32 MKFontInternal_CalcHeightAndScale(MKFont *arg0, float arg1, float *arg2) {
    f32 temp_f1_1255;
    f32 var_f31_1253;

    var_f31_1253 = arg1;
    temp_f1_1255 = MKFont_GetHeight(arg0);
    if (var_f31_1253 == 0.0f) {
        var_f31_1253 = temp_f1_1255;
        *arg2 = 1.0f;
    } else {
        *arg2 = var_f31_1253 / temp_f1_1255;
    }
    if (MKView_IsOrtho() == 0) {
        var_f31_1253 = -var_f31_1253;
    }
    return var_f31_1253;
}

#if 0 // DRAFT: pointer/array required
f32 MKFont_GetHeight(MKFont *arg0) {
    return M2C_FIELD(**arg0, f32 *, 0x24);
}
#endif

#include "spyro/source/Points.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/FogPointInfo.h"
#include "spyro/source/WindPointInfo.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKWind.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
extern M2C_UNK gEmptyPtrListDL;
static Points<FogPointInfo> fog;
#if 0 // DRAFT: identifier 'wind' redeclared
static Points<WindPointInfo> wind;
#endif

#if 0 // DRAFT: undefined identifier 'GetValueAt'
void WindPoints_Update(const MKVector3 &arg0, WindInfo *arg1) {
    f32 sp50;
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    WindPointInfo sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    f32 var_f4_107;
    f32 var_f4_40;
    f64 temp_f1_46;
    f64 temp_f1_52;
    f64 temp_f1_56;
    s32 temp_r3_75;
    s32 var_r0_85;

    sp40 = arg1->unk0;
    sp48 = arg1->unk8;
    sp50 = arg1->unk10;
    wind.GetValueAt(arg0, &sp30, (WindPointInfo (*)(WindPointInfo *, WindPointInfo *, f32)) WindPoints_Blend);
    var_f4_40 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
    if (var_f4_40 > 0.000001f) {
        if (var_f4_40 > 0.0f) {
            temp_f1_46 = __frsqrte(var_f4_40);
            temp_f1_52 = 0.5 * temp_f1_46 * -(((f64) var_f4_40 * (temp_f1_46 * temp_f1_46)) - 3.0);
            temp_f1_56 = 0.5 * temp_f1_52 * -(((f64) var_f4_40 * (temp_f1_52 * temp_f1_52)) - 3.0);
            var_f4_40 = (f32) ((f64) var_f4_40 * (0.5 * temp_f1_56 * -(((f64) var_f4_40 * (temp_f1_56 * temp_f1_56)) - 3.0)));
        } else if (var_f4_40 < M2C_BITWISE(f32, 0.0)) {
            var_f4_40 = __float_nan;
        } else {
            sp8 = var_f4_40;
            temp_r3_75 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_75) {                   /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_85 = 1;
                } else {
                    var_r0_85 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_85 = 5;
                } else {
                    var_r0_85 = 3;
                }
                break;
            default:
                var_r0_85 = 4;
                break;
            }
            if (var_r0_85 == 1) {
                var_f4_40 = __float_nan;
            }
        }
        var_f4_107 = 1.0f / var_f4_40;
    } else {
        var_f4_107 = 0.0f;
    }
    sp40 = (f32) sp40 * var_f4_107;
    unksp44 *= var_f4_107;
    sp48 = (f32) sp48 * var_f4_107;
    MKGrass_SetWindDirection(*((MKVector3 *) &sp40), sp50);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp20 = sp10;
    sp18 = sp48 * sp50;
    sp28 = (f64) sp18;
    MKWind_SetConstantWind(*((MKVector3 *) &sp20));
}
#endif

#if 0 // DRAFT: function call 'operator*(float, MKVector3)' does not match
void WindPoints_Blend(const WindPointInfo &arg0, const WindPointInfo &arg1, float arg2) {
    f32 sp68;
    f64 sp60;
    f64 sp58;
    M2C_UNK sp44;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 temp_f31_656;

    temp_f31_656 = 1.0f - arg2;
    __ml(temp_f31_656, sp18);
    __ml(arg2, sp28);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = sp28.unk8 + sp18.unk8;
    sp58 = sp8;
    sp40 = (f64) sp10;
    sp60 = (f64) sp10;
    sp68 = (arg2 * M2C_FIELD(&arg1, f32 *, 0x20)) + (temp_f31_656 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x20));
    M2C_STRUCT_COPY((s32) (&arg0 - 4) + 4, (s32) &sp44 + 4, 0x30);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk10'
void WindPoints_Deinit() {
    MKHeap *temp_r0_722;
    MKHeap *temp_r0_741;
    MKHeap *temp_r3_744;
    MKHeap *var_r30_718;
    MKHeap *var_r3_719;
    MKHeap *var_r4_717;
    u32 temp_r0_727;

    if ((u8) wind.unk10 != 0) {
        var_r4_717 = wind.unkC;
        var_r30_718 = var_r4_717;
        var_r3_719 = var_r4_717;
loop_4:
        temp_r0_727 = M2C_FIELD(var_r3_719, u32 *, -4);
        var_r3_719 -= 4;
        if (temp_r0_727 != 0U) {
            temp_r0_722 = var_r3_719->unk0;
            if (temp_r0_722 < var_r30_718) {
                var_r30_718 = temp_r0_722;
            }
            goto loop_4;
        }
        if (var_r3_719 != &gEmptyPtrListDL) {
loop_10:
            temp_r0_741 = var_r4_717->unk0;
            if (temp_r0_741 != NULL) {
                if (temp_r0_741 < var_r30_718) {
                    var_r30_718 = temp_r0_741;
                }
                var_r4_717 += 4;
                goto loop_10;
            }
            temp_r3_744 = var_r3_719->Current();
            if (temp_r3_744 != NULL) {
                ((MKHeap *) (temp_r3_744->Current()))->Free(var_r30_718, NULL, 0);
            } else {
                free(var_r30_718);
            }
        }
        wind.unkC = NULL;
    }
    wind.unk10 = 0;
    memset(wind.unk0, 0, wind.unk4 * (wind.unk4 * 4));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
void WindPoints_Init(const char *arg0) {
    wind.Init(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char' to
void WindPoints_DeinitModule() {
    MKHeap *temp_r31_1042;
    MKHeap *temp_r3_1045;

    temp_r31_1042 = wind.unk0;
    if (temp_r31_1042 != NULL) {
        temp_r3_1045 = wind.Current();
        if (temp_r3_1045 != NULL) {
            ((MKHeap *) (temp_r3_1045->Current()))->Free(temp_r31_1042, NULL, 0);
        } else {
            free(temp_r31_1042);
        }
    }
    wind.unk0 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void WindPoints_InitModule() {
    MKHeap *temp_r3_1081;
    MKHeap *var_r3_1088;

    wind.unk4 = 0x14;
    wind.unk8 = 0x2710;
    temp_r3_1081 = wind.Current();
    if (temp_r3_1081 != NULL) {
        var_r3_1088 = ((MKHeap *) (temp_r3_1081->Current()))->Alloc(0x640, NULL, 0);
    } else {
        var_r3_1088 = malloc(0x640);
    }
    wind.unk0 = var_r3_1088;
    memset(var_r3_1088, 0, wind.unk4 * (wind.unk4 * 4));
    wind.unk10 = 0;
    MKWind_Set(400.0f, 40000.0f, 1000.0f, 400.0f, MKVector3::zero, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'FogPoints_Blend'
void FogPoints_Update(const MKVector3 &arg0, FogInfo *arg1) {
    f32 sp2C;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    FogPointInfo sp8;

    sp18 = arg1->unk8;
    sp20 = arg1->unk10;
    sp28 = arg1->unk0;
    sp2C = arg1->unk4;
    fog.GetValueAt(arg0, &sp8, FogPoints_Blend);
    arg1->unk8 = sp18;
    arg1->unk10 = sp20;
    arg1->unk0 = sp28;
    arg1->unk4 = sp2C;
}
#endif

#if 0 // DRAFT: function call 'operator*(float, MKVector4)' does not match
FogPointInfo FogPoints_Blend(const FogPointInfo &arg0, const FogPointInfo &arg1, float arg2) {
    f32 sp6C;
    f32 sp68;
    f64 sp60;
    f64 sp58;
    M2C_UNK sp44;
    f64 sp40;
    f64 sp38;
    MKVector4 sp28;
    MKVector4 sp18;
    f32 temp_f31_1687;
    void *temp_r31_1684;

    temp_r31_1684 = M2C_ERROR(/* Read from unset register $r5 */);
    temp_f31_1687 = 1.0f - arg2;
    __ml(temp_f31_1687, sp18);
    __ml(arg2, sp28);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp8;
    sp40 = sp10;
    sp58 = sp8;
    sp60 = sp10;
    sp68 = (arg2 * M2C_FIELD(&arg1, f32 *, 0x20)) + (temp_f31_1687 * M2C_FIELD(temp_r31_1684, f32 *, 0x20));
    sp6C = (arg2 * M2C_FIELD(&arg1, f32 *, 0x24)) + (temp_f31_1687 * M2C_FIELD(temp_r31_1684, f32 *, 0x24));
    M2C_STRUCT_COPY((s32) (&arg0 - 4) + 4, (s32) &sp44 + 4, 0x30);
    return (FogPointInfo) &sp28;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk10'
void FogPoints_Deinit() {
    MKHeap *temp_r0_1778;
    MKHeap *temp_r0_1797;
    MKHeap *temp_r3_1800;
    MKHeap *var_r30_1774;
    MKHeap *var_r3_1775;
    MKHeap *var_r4_1773;
    u32 temp_r0_1783;

    if ((u8) fog.unk10 != 0) {
        var_r4_1773 = fog.unkC;
        var_r30_1774 = var_r4_1773;
        var_r3_1775 = var_r4_1773;
loop_4:
        temp_r0_1783 = M2C_FIELD(var_r3_1775, u32 *, -4);
        var_r3_1775 -= 4;
        if (temp_r0_1783 != 0U) {
            temp_r0_1778 = var_r3_1775->unk0;
            if (temp_r0_1778 < var_r30_1774) {
                var_r30_1774 = temp_r0_1778;
            }
            goto loop_4;
        }
        if (var_r3_1775 != &gEmptyPtrListDL) {
loop_10:
            temp_r0_1797 = var_r4_1773->unk0;
            if (temp_r0_1797 != NULL) {
                if (temp_r0_1797 < var_r30_1774) {
                    var_r30_1774 = temp_r0_1797;
                }
                var_r4_1773 += 4;
                goto loop_10;
            }
            temp_r3_1800 = var_r3_1775->Current();
            if (temp_r3_1800 != NULL) {
                ((MKHeap *) (temp_r3_1800->Current()))->Free(var_r30_1774, NULL, 0);
            } else {
                free(var_r30_1774);
            }
        }
        fog.unkC = NULL;
    }
    fog.unk10 = 0;
    memset(fog.unk0, 0, fog.unk4 * (fog.unk4 * 4));
}
#endif

void FogPoints_Init(const char *arg0) {
    fog.Init(arg0);
}

#if 0 // DRAFT: undefined identifier 'unk0'
void FogPoints_DeinitModule() {
    MKHeap *temp_r31_2107;
    MKHeap *temp_r3_2110;

    temp_r31_2107 = fog.unk0;
    if (temp_r31_2107 != NULL) {
        temp_r3_2110 = fog.Current();
        if (temp_r3_2110 != NULL) {
            ((MKHeap *) (temp_r3_2110->Current()))->Free(temp_r31_2107, NULL, 0);
        } else {
            free(temp_r31_2107);
        }
    }
    fog.unk0 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void FogPoints_InitModule() {
    MKHeap *temp_r3_2146;
    MKHeap *var_r3_2153;

    fog.unk4 = 0x14;
    fog.unk8 = 0x2710;
    temp_r3_2146 = fog.Current();
    if (temp_r3_2146 != NULL) {
        var_r3_2153 = ((MKHeap *) (temp_r3_2146->Current()))->Alloc(0x640, NULL, 0);
    } else {
        var_r3_2153 = malloc(0x640);
    }
    fog.unk0 = var_r3_2153;
    memset(var_r3_2153, 0, fog.unk4 * (fog.unk4 * 4));
    fog.unk10 = 0;
}
#endif

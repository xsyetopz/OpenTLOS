#include "spyro/source/Hud.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/HudItems.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'Hud_bDisableDraw' redeclared
extern u8 Hud_bDisableDraw;
#endif
extern HudItem *pHudItems;
extern MKMaterial *pMatAether;
extern MKMaterial *pMatHudBits;
extern MKMaterial *pMatIcons;
extern MKMaterial *pMatPool;
static M2C_UNK hudIconUVs;                          /* unable to generate initializer: unknown type */
static u8 bFixed = 1;
static s32 lit_679 = 1;

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void Hud_DrawArc(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, const MKVector4 *arg10, const MKVector4 *arg11, Matrix *arg12, MKMaterial *arg13, float arg14, float arg15, float arg16, float arg17) {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f16_118;
    f32 temp_f16_126;
    f32 temp_f29_70;
    f32 var_f1_53;
    s32 temp_r3_85;
    s32 var_r28_103;
    s32 var_r29_77;

    var_f1_53 = -arg3;
    if (arg2 > var_f1_53) {
        var_f1_53 = arg2;
    }
    temp_f29_70 = arg_sp8 - arg6;
    var_r29_77 = (s32) ((temp_f29_70 / 6.2831855f) * var_f1_53);
    if ((s32) lit_679 > var_r29_77) {
        var_r29_77 = lit_679;
    }
    MKMaterial_SetMaterial(arg13);
    temp_r3_85 = 0 - arg13;
    MKPrimitive(0xC, (2 & ~((temp_r3_85 - temp_r3_85) - !M2C_CARRY)) | 1);
    if (arg12 != NULL) {
        MKSetMatrix(*arg12);
    }
    MKBegin((var_r29_77 + 1) * 2);
    var_r28_103 = 0;
loop_16:
    if (var_r28_103 <= var_r29_77) {
        temp_f16_118 = (f32) var_r28_103 / (f32) var_r29_77;
        _table_sincosf((temp_f16_118 * temp_f29_70) + arg6, sp14, spC);
        _table_sincosf((temp_f16_118 * (arg_spC - arg7)) + arg7, sp10, sp8);
        temp_f16_126 = ((arg_sp18 - arg_sp10) * temp_f16_118) + arg_sp10;
        if (arg11 != NULL) {
            MKSetColorV(*arg11);
        }
        if (arg13 != NULL) {
            MKSetTexCoord1F(temp_f16_126, arg_sp1C);
        }
        MKSetPositionF((sp10 * arg4) + arg0, (sp8 * arg5) + arg1, 0.0f);
        if (arg10 != NULL) {
            MKSetColorV(*arg10);
        }
        if (arg13 != NULL) {
            MKSetTexCoord1F(temp_f16_126, arg_sp14);
        }
        MKSetPositionF((sp14 * arg2) + arg0, (spC * arg3) + arg1, 0.0f);
        var_r28_103 += 1;
        goto loop_16;
    }
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector2'
void Hud_DrawIcon(int arg0, int arg1, const MKVector2 &arg2, const MKVector2 &arg3, const MKVector4 &arg4, float arg5, float arg6, float arg7, float arg8, bool arg9, bool arg10, const Matrix &arg11) {
    Hud_DrawIcon(arg0, arg1, arg2.unk0, arg2.unk4, arg3.unk0, arg3.unk4, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp2C'
void Hud_DrawIcon(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5, const MKVector4 &arg6, float arg7, float arg8, float arg9, float arg10, bool arg11, bool arg12, const Matrix &arg13) {
    MKMaterial *var_r6_283;
    f32 temp_f0_393;
    f32 temp_f0_399;
    f32 temp_f1_345;
    f32 temp_f1_358;
    f32 temp_f1_371;
    f32 temp_f1_384;
    f32 temp_f22_282;
    f32 temp_f23_284;
    f32 temp_f23_529;
    f32 temp_f23_599;
    f32 temp_f24_461;
    f32 temp_f24_591;
    f32 temp_f25_488;
    f32 temp_f30_453;
    f32 var_f1_381;
    f32 var_f26_352;
    f32 var_f27_365;
    f32 var_f28_378;
    f32 var_f29_391;
    f32 var_f2_342;
    f32 var_f2_355;
    f32 var_f2_368;
    void *var_r31_281;
    var_r31_281 = NULL;
    temp_f22_282 = -0.5f * arg4;
    var_r6_283 = NULL;
    temp_f23_284 = -0.5f * arg5;
    if ((u32) arg1 <= 0x11U) {
        switch (arg1) {
        case 0:
        case 1:
            var_r6_283 = pMatIcons;
            var_r31_281 = &hudIconUVs + ((arg0 << 5) + (arg1 * 0x10));
            break;
        case 3:
            var_r6_283 = pMatIcons;
            var_r31_281 = &hudIconUVs + 0x80;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            var_r6_283 = pMatIcons;
            var_r31_281 = &hudIconUVs + 0xD0 + ((arg1 - 4) * 0x10);
            break;
        case 8:
            var_r6_283 = pMatAether;
            var_r31_281 = &hudIconUVs + 0x110;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            var_r6_283 = pMatIcons;
            var_r31_281 = &hudIconUVs + 0x90 + ((arg1 - 9) * 0x10);
            break;
        case 13:
            var_r6_283 = pMatIcons;
            var_r31_281 = &hudIconUVs + 0x120;
            break;
        case 14:
            var_r6_283 = pMatPool;
            var_r31_281 = &hudIconUVs + 0x110;
            break;
        case 15:
        case 16:
        case 17:
            var_r6_283 = pMatHudBits;
            var_r31_281 = &hudIconUVs + 0x130 + ((arg1 - 0xF) * 0x10);
            break;
        }
    }
    MKMaterial_SetMaterial(var_r6_283);
    if (arg7 == 0.0f) {
        var_f2_342 = M2C_FIELD(var_r31_281, f32 *, 0);
    } else {
        temp_f1_345 = M2C_FIELD(var_r31_281, f32 *, 0);
        var_f2_342 = (arg7 * (M2C_FIELD(var_r31_281, f32 *, 8) - temp_f1_345)) + temp_f1_345;
    }
    var_f26_352 = 0.001953125f + var_f2_342;
    if (arg8 == 0.0f) {
        var_f2_355 = M2C_FIELD(var_r31_281, f32 *, 4);
    } else {
        temp_f1_358 = M2C_FIELD(var_r31_281, f32 *, 4);
        var_f2_355 = (arg8 * (M2C_FIELD(var_r31_281, f32 *, 0xC) - temp_f1_358)) + temp_f1_358;
    }
    var_f27_365 = 0.001953125f + var_f2_355;
    if (arg9 == 1.0f) {
        var_f2_368 = M2C_FIELD(var_r31_281, f32 *, 8);
    } else {
        temp_f1_371 = M2C_FIELD(var_r31_281, f32 *, 0);
        var_f2_368 = (arg9 * (M2C_FIELD(var_r31_281, f32 *, 8) - temp_f1_371)) + temp_f1_371;
    }
    var_f28_378 = 0.001953125f + var_f2_368;
    if (arg10 == 1.0f) {
        var_f1_381 = M2C_FIELD(var_r31_281, f32 *, 0xC);
    } else {
        temp_f1_384 = M2C_FIELD(var_r31_281, f32 *, 4);
        var_f1_381 = (arg10 * (M2C_FIELD(var_r31_281, f32 *, 0xC) - temp_f1_384)) + temp_f1_384;
    }
    var_f29_391 = 0.001953125f + var_f1_381;
    if (arg11 != 0) {
        temp_f0_393 = var_f26_352;
        var_f26_352 = var_f28_378;
        var_f28_378 = temp_f0_393;
    }
    if (arg12 != 0) {
        temp_f0_399 = var_f27_365;
        var_f27_365 = var_f29_391;
        var_f29_391 = temp_f0_399;
    }
    MKSetBaseColorV(arg6);
    MKPrimitive(0xC, 0x101);
    M2C_STRUCT_COPY((s32) &arg_sp2C + 4, (s32) (&arg13 - 4) + 4, 0x40);
    arg_sp10 = arg2;
    arg_sp14 = arg3;
    arg_sp18 = 0.0f;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    arg_sp30.Translate((Matrix *) &arg_sp30, *((MKVector3 *) &arg_sp20));
    MKSetMatrix(*((Matrix *) &arg_sp30));
    if (arg1 == 3) {
        MKBegin(4);
        MKSetColorV(arg6);
        MKSetTexCoord1F(var_f26_352, var_f27_365);
        MKSetPositionF(temp_f22_282, temp_f23_284, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f27_365);
        temp_f30_453 = temp_f22_282 + (arg4 * 0.5f);
        MKSetPositionF(temp_f30_453, temp_f23_284, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f29_391);
        temp_f24_461 = temp_f23_284 + (arg5 * 0.5f);
        MKSetPositionF(temp_f22_282, temp_f24_461, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f29_391);
        MKSetPositionF(temp_f30_453, temp_f24_461, 0.0f);
        MKEnd();
        MKBegin(4);
        MKSetColorV(arg6);
        MKSetTexCoord1F(var_f28_378, var_f27_365);
        MKSetPositionF(temp_f30_453, temp_f23_284, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f27_365);
        temp_f25_488 = temp_f22_282 + arg4;
        MKSetPositionF(temp_f25_488, temp_f23_284, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f29_391);
        MKSetPositionF(temp_f30_453, temp_f24_461, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f29_391);
        MKSetPositionF(temp_f25_488, temp_f24_461, 0.0f);
        MKEnd();
        MKBegin(4);
        MKSetColorV(arg6);
        MKSetTexCoord1F(var_f26_352, var_f29_391);
        MKSetPositionF(temp_f22_282, temp_f24_461, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f29_391);
        MKSetPositionF(temp_f30_453, temp_f24_461, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f27_365);
        temp_f23_529 = temp_f23_284 + arg5;
        MKSetPositionF(temp_f22_282, temp_f23_529, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f27_365);
        MKSetPositionF(temp_f30_453, temp_f23_529, 0.0f);
        MKEnd();
        MKBegin(4);
        MKSetColorV(arg6);
        MKSetTexCoord1F(var_f28_378, var_f29_391);
        MKSetPositionF(temp_f30_453, temp_f24_461, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f29_391);
        MKSetPositionF(temp_f25_488, temp_f24_461, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f27_365);
        MKSetPositionF(temp_f30_453, temp_f23_529, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f27_365);
        MKSetPositionF(temp_f25_488, temp_f23_529, 0.0f);
        MKEnd();
    } else {
        MKBegin(4);
        MKSetColorV(arg6);
        MKSetTexCoord1F(var_f26_352, var_f27_365);
        MKSetPositionF(temp_f22_282, temp_f23_284, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f27_365);
        temp_f24_591 = temp_f22_282 + arg4;
        MKSetPositionF(temp_f24_591, temp_f23_284, 0.0f);
        MKSetTexCoord1F(var_f26_352, var_f29_391);
        temp_f23_599 = temp_f23_284 + arg5;
        MKSetPositionF(temp_f22_282, temp_f23_599, 0.0f);
        MKSetTexCoord1F(var_f28_378, var_f29_391);
        MKSetPositionF(temp_f24_591, temp_f23_599, 0.0f);
        MKEnd();
    }
    MKSetMatrix(Matrix::identity);
    MKEndPrimitive();
}
#endif

void Hud_Show(bool arg0) {
    Hud_bDisableDraw = arg0 == 0;
}

void Hud_Remove(HudItem *arg0) {
    HudItem *var_r4_660;
    HudItem *var_r5_667;

    var_r4_660 = pHudItems;
    if (arg0 == var_r4_660) {
        pHudItems = M2C_FIELD(var_r4_660, HudItem **, 0x1C);
    } else {
        var_r5_667 = M2C_FIELD(var_r4_660, HudItem **, 0x1C);
loop_4:
        if ((var_r5_667 != NULL) && (var_r5_667 != arg0)) {
            var_r4_660 = var_r5_667;
            var_r5_667 = M2C_FIELD(var_r5_667, HudItem **, 0x1C);
            goto loop_4;
        }
        if (var_r5_667 == arg0) {
            M2C_FIELD(var_r4_660, HudItem **, 0x1C) = (HudItem *) M2C_FIELD(var_r5_667, HudItem **, 0x1C);
        }
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

void Hud_Add(HudItem *arg0) {
    arg0->unk10 = 0.0f;
    arg0->unk0 = 0;
    M2C_FIELD(arg0, HudItem **, 0x1C) = (HudItem *) pHudItems;
    pHudItems = arg0;
    HudItem_Fixed(arg0, bFixed);
}

void Hud_Draw() {
    HudItem *var_r31_719;

    if ((u8) Hud_bDisableDraw == 0) {
        var_r31_719 = pHudItems;
loop_3:
        if (var_r31_719 != NULL) {
            HudItem_Draw(var_r31_719);
            var_r31_719 = M2C_FIELD(var_r31_719, HudItem **, 0x1C);
            goto loop_3;
        }
    }
}

void Hud_Update() {
    HudItem *var_r31_743;

    var_r31_743 = pHudItems;
loop_5:
    if (var_r31_743 != NULL) {
        if (HudItem_Update(var_r31_743) != 0) {
            HudItem_SetState(var_r31_743, (HudItemState) 2, 0U);
        } else {
            HudItem_SetState(var_r31_743, (HudItemState) 0, 0U);
        }
        var_r31_743 = M2C_FIELD(var_r31_743, HudItem **, 0x1C);
        goto loop_5;
    }
}

void Hud_DeinitModule() {
    MKMaterial_Destroy(pMatAether);
    pMatAether = NULL;
    MKMaterial_Destroy(pMatHudBits);
    pMatHudBits = NULL;
    MKMaterial_Destroy(pMatPool);
    pMatPool = NULL;
    MKMaterial_Destroy(pMatIcons);
    pMatIcons = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void Hud_InitModule() {
    pMatIcons = MKMaterial_Create("ui_breath_icons");
    pMatPool = MKMaterial_Create("ui_levelup_pool");
    pMatHudBits = MKMaterial_Create("ui_hud_bits");
    pMatAether = MKMaterial_Create("ui_aether");
}
#endif

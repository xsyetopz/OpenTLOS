#include "spyro/source/SpyroHud.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CutsceneEvent.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/GameData.h"
#include "spyro/source/HudData.h"
#include "spyro/source/HudItems.h"
#include "common/Source/MKSystem.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Hud.h"
#include <m2c_macros.h>

M2C_UNK __construct_array(M2C_UNK *, HudData *(*)(HudData *), M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static M2C_UNK HUD_BAR_BACKGROUND;                  /* unable to generate initializer: unknown type */
static struct _struct_vEnemyHealthBarColour_0x10 vEnemyHealthBarColour[5] = { { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 } };
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_vEnemyHealthBarSize_0x8 vEnemyHealthBarSize[4] = { {  }, {  }, {  }, {  } };
#endif
static M2C_UNK hudItem;
static M2C_UNK hudData;
static s32 iEnemyHealthBarColours = 5;

static M2C_UNK hudDesc;                             /* unable to generate initializer: unknown type; const */

void EnemyHudData::Init(Enemy *arg0, float arg1, float arg2) {
    Enemy *temp_r4_14;

    this->unk0 = arg0;
    this->unk4 = arg1;
    this->unkC = arg2;
    temp_r4_14 = this->unk0;
    if (temp_r4_14 != NULL) {
        this->unk8 = temp_r4_14->unkAB0;
        this->unk10 = M2C_FIELD(this->unk0->unkA20, s32 *, 0x118);
        this->unk14 = M2C_FIELD(this->unk0->unkA20, s32 *, 0x11C);
        this->unk18 = M2C_BITWISE(s32, this->unk0->unkAD0);
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
EnemyHudData::EnemyHudData() {
    this->unk0 = NULL;
    this->unk4 = 0.0f;
    this->unk8 = 0.0f;
    this->unkC = 0.0f;
    this->unk10 = 0;
    this->unk14 = 1;
    this->unk18 = 0;
    return this;
}
#endif

s32 EnemyHud_GetEnemy() {
    return M2C_FIELD(&hudData, s32 *, 0x5C);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyHud_Modified(const EnemyHudData &arg0) {
    Enemy *temp_r3_67;
    f32 temp_f1_110;
    f32 temp_f2_113;

    temp_r3_67 = arg0.unk0;
    if ((temp_r3_67 == NULL) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == 0U) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == M2C_FIELD(temp_r3_67->__vptr, u32 (**)(), 0xD0)())) {
        M2C_FIELD(&hudData, s8 *, 0x6D) = 1;
        if ((Enemy *) arg0.unk0 != NULL) {
            HudItem_Modified(&hudItem + 0x20);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 2.0f;
        } else if ((u8) M2C_FIELD(&hudItem, u8 *, 0x39) == 0) {
            HudItem_SetState(&hudItem + 0x20, (HudItemState) 0, 1U);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 0.0f;
        }
        temp_f1_110 = arg0.unk8;
        temp_f2_113 = arg0.unk4;
        M2C_FIELD(&hudData, Enemy **, 0x40) = (Enemy *) arg0.unk0;
        M2C_FIELD(&hudData, f32 *, 0x44) = temp_f2_113;
        M2C_FIELD(&hudData, f32 *, 0x48) = temp_f1_110;
        M2C_FIELD(&hudData, f32 *, 0x4C) = (f32) arg0.unkC;
        M2C_FIELD(&hudData, s32 *, 0x50) = (s32) arg0.unk10;
        M2C_FIELD(&hudData, s32 *, 0x54) = (s32) arg0.unk14;
        M2C_FIELD(&hudData, s32 *, 0x58) = (s32) arg0.unk18;
        M2C_FIELD(&hudData, f32 *, 0x64) = temp_f1_110;
        if ((Enemy *) arg0.unk0 != (Enemy *) M2C_FIELD(&hudData, Enemy **, 0x5C)) {
            M2C_FIELD(&hudData, f32 *, 0x60) = temp_f2_113;
        }
        M2C_FIELD(&hudData, f32 *, 0x68) = (f32) arg0.unkC;
        M2C_FIELD(&hudData, Enemy **, 0x5C) = (Enemy *) arg0.unk0;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void EnemyHud_Modified(MKProp *arg0, float arg1, float arg2, float arg3) {
    if ((arg0 == NULL) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == 0U) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) == arg0)) {
        M2C_FIELD(&hudData, s8 *, 0x6D) = 0;
        if (arg0 != NULL) {
            HudItem_Modified(&hudItem + 0x20);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 2.0f;
        } else if ((u8) M2C_FIELD(&hudItem, u8 *, 0x39) == 0) {
            HudItem_SetState(&hudItem + 0x20, (HudItemState) 0, 1U);
            M2C_FIELD(&hudData, f32 *, 0x3C) = 0.0f;
        }
        M2C_FIELD(&hudData, f32 *, 0x64) = arg2;
        if (arg0 != (MKProp *) M2C_FIELD(&hudData, MKProp **, 0x5C)) {
            M2C_FIELD(&hudData, f32 *, 0x60) = arg1;
        }
        M2C_FIELD(&hudData, f32 *, 0x68) = arg3;
        M2C_FIELD(&hudData, MKProp **, 0x5C) = arg0;
    }
}
#endif

void SpyroHud_ResetAfterCutScene() {
    M2C_FIELD(&hudItem, s32 *, 0) = 0;
    M2C_FIELD(&hudItem, s32 *, 0x20) = 0;
}

#if 0 // DRAFT: function call 'Hud_Remove(long *)' does not match
void SpyroHud_Deinit() {
    s32 var_r29_234;
    s32 var_r31_236;

    var_r29_234 = 1;
    var_r31_236 = 0x20;
    do {
        Hud_Remove(&hudItem + var_r31_236);
        var_r29_234 -= 1;
        var_r31_236 -= 0x20;
    } while (var_r29_234 >= 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void SpyroHud_Init() {
    HudItem *temp_r3_283;
    s32 var_r24_276;
    s32 var_r29_279;
    s32 var_r30_278;
    s32 var_r31_277;
    void *temp_r25_282;
    void *temp_r5_281;

    memset(&hudData, 0, 0x70U);
    memset(&hudItem, 0, 0x40U);
    var_r24_276 = 0;
    var_r31_277 = 0;
    var_r30_278 = 0;
    var_r29_279 = 0;
    do {
        temp_r5_281 = &hudDesc + var_r29_279;
        temp_r25_282 = &hudData + var_r30_278;
        temp_r3_283 = &hudItem + var_r31_277;
        temp_r3_283->unk14 = temp_r25_282;
        temp_r3_283->unk4 = M2C_FIELD(temp_r5_281, s32 *, 4);
        temp_r3_283->unk8 = M2C_FIELD(temp_r5_281, s32 *, 8);
        temp_r3_283->unkC = M2C_FIELD(temp_r5_281, s32 *, 0xC);
        M2C_FIELD(temp_r25_282, void **, 0) = temp_r5_281;
        temp_r3_283->unk18 = M2C_FIELD(temp_r5_281, u8 *, 0xB0);
        Hud_Add(temp_r3_283);
        var_r24_276 += 1;
        M2C_FIELD(temp_r25_282, f32 *, 4) = 0.0f;
        var_r31_277 += 0x20;
        var_r30_278 += 0x38;
        var_r29_279 += 0xB4;
    } while (var_r24_276 < 2);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HudItemState'
void SpyroHud_StateChange(void *arg0, HudItemState arg1, HudItemState arg2) {
    if ((*M2C_FIELD(arg0, s32 **, 0) & 0x10) && ((s32) arg2 == 0)) {
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x28) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x30) = 0.0f;
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HudItemState'
void SpyroHud_Draw(void *arg0, HudItemState arg1, float arg2) {
    f32 temp_f0_1515;
    f32 temp_f0_560;
    f32 temp_f0_755;
    f32 temp_f10_415;
    f32 temp_f25_551;
    f32 temp_f25_746;
    f32 temp_f26_1596;
    f32 temp_f26_554;
    f32 temp_f26_749;
    f32 temp_f28_1604;
    f32 temp_f29_1603;
    f32 temp_f3_651;
    f32 var_f0_367;
    f32 var_f1_1519;
    f32 var_f31_354;
    f32 var_f3_1567;
    s32 temp_r0_1456;
    s32 temp_r0_657;
    s32 var_r6_605;
    struct _struct_vEnemyHealthBarColour_0x10 *temp_r3_669;
    struct _struct_vEnemyHealthBarSize_0x8 *temp_r5_602;
    u32 temp_r30_401;
    void *temp_r12_1298;
    void *temp_r12_781;
    void *temp_r26_1047;
    void *temp_r26_403;
    void *temp_r26_841;
    void *temp_r26_945;
    void *temp_r3_1507;
    void *temp_r3_516;
    void *temp_r3_711;
    void *temp_r4_1149;
    void *temp_r4_1358;
    void *temp_r5_524;
    void *temp_r5_719;
    void *temp_r7_586;
    void *var_r4_389;
    var_f31_354 = 1.0f;
    switch ((s32) arg1) {                           /* irregular */
    case 2:
        break;
    case 3:
        var_f0_367 = 2.0f * arg2;
        if (var_f0_367 < 1.0f) {

        } else {
            var_f0_367 = 1.0f;
        }
        if (var_f0_367 > 0.0f) {

        } else {
            var_f0_367 = 0.0f;
        }
        var_f31_354 = var_f0_367;
        break;
    }
    if ((s32) arg1 != 0) {
        if (System_IsWideScreenEnabled() != 0) {
            var_r4_389 = M2C_FIELD(arg0, void **, 0) + 0x18;
        } else {
            var_r4_389 = M2C_FIELD(arg0, void **, 0) + 0x10;
        }
        arg_sp318 = M2C_FIELD(var_r4_389, f32 *, 0);
        temp_r30_401 = ((u8) GameData::gameData.unk168 >> 3U) & 1;
        arg_sp31C = M2C_FIELD(var_r4_389, f32 *, 4);
        temp_r26_403 = M2C_FIELD(arg0, void **, 0);
        if ((M2C_FIELD(temp_r26_403, s32 *, 0) & 0x10) && ((void *) M2C_FIELD(arg0, void **, 0x24) != NULL) && ((u8) M2C_FIELD(arg0, u8 *, 0x35) == 0)) {
            temp_f10_415 = M2C_FIELD(arg0, f32 *, 0x30);
            arg_sp194 = 0.0f;
            arg_sp190 = 5.0f * temp_f10_415;
            arg_sp314 = arg_sp194;
            arg_sp310 = arg_sp190;
            arg_sp188 = M2C_FIELD(temp_r26_403, f32 *, 0x38) * 0.75f;
            arg_sp18C = M2C_FIELD(temp_r26_403, f32 *, 0x3C) * 0.75f;
            arg_sp180 = arg_sp310 * 0.75f;
            arg_sp184 = arg_sp314 * 0.75f;
            arg_sp308 = arg_sp188;
            arg_sp30C = arg_sp18C;
            arg_sp248 = arg_sp180;
            arg_sp24C = arg_sp184;
            arg_sp490 = 1.0f;
            arg_sp494 = 0.0f;
            arg_sp178 = arg_sp308 - arg_sp248;
            arg_sp17C = arg_sp30C - arg_sp24C;
            arg_sp300 = arg_sp178;
            arg_sp304 = arg_sp17C;
            arg_sp498 = 0.0f;
            arg_sp49C = var_f31_354;
            arg_sp170 = M2C_FIELD(temp_r26_403, f32 *, 0x40) * 0.75f;
            arg_sp174 = M2C_FIELD(temp_r26_403, f32 *, 0x44) * 0.75f;
            arg_sp2F8 = arg_sp170;
            arg_sp2FC = arg_sp174;
            arg_sp4A0 = 0.3f;
            arg_sp4A4 = 0.3f;
            arg_sp4A8 = 0.3f;
            arg_sp4AC = var_f31_354;
            arg_sp4B0 = 1.0f;
            arg_sp4B4 = 1.0f;
            arg_sp4B8 = 1.0f;
            arg_sp4BC = var_f31_354;
            arg_sp5D0 = (f64) arg_sp490;
            arg_sp5D8 = (f64) arg_sp498;
            arg_sp5E0 = (f64) arg_sp4A0;
            arg_sp5E8 = (f64) arg_sp4A8;
            arg_sp5F0 = (f64) arg_sp4B0;
            arg_sp5F8 = (f64) arg_sp4B8;
            arg_sp8 = 1e-45f;
            Hud_DrawBarHorz(*((MKVector2 *) &arg_sp318), *((MKVector2 *) &arg_sp308), *((MKVector2 *) &arg_sp300), *((MKVector2 *) &arg_sp2F8), *((MKVector2 *) &arg_sp300), *((MKVector4 *) &arg_sp5F0), *((MKVector4 *) &arg_sp5E0), *((MKVector4 *) &arg_sp5D0), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x94), M2C_FIELD(arg0, f32 *, 0x2C) / temp_f10_415, M2C_FIELD(arg0, f32 *, 0x28) / temp_f10_415, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            arg_sp684 = 0;
            arg_sp688 = NULL;
            arg_sp680 = 0x8D;
            temp_r3_516 = M2C_FIELD(arg0, void **, 0x24);
            M2C_FIELD(M2C_FIELD(temp_r3_516, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_516, &arg_sp680);
            if (arg_sp688 != NULL) {
                temp_r5_524 = M2C_FIELD(arg0, void **, 0);
                arg_sp488 = 0.0f;
                arg_sp168 = arg_sp318 + M2C_FIELD(temp_r5_524, f32 *, 0x30);
                arg_sp16C = arg_sp31C + M2C_FIELD(temp_r5_524, f32 *, 0x34);
                arg_sp240 = arg_sp168;
                arg_sp244 = arg_sp16C;
                arg_sp480 = arg_sp240;
                arg_sp484 = arg_sp244;
                arg_sp678 = (f64) arg_sp488;
                arg_sp670 = (f64) arg_sp480;
                temp_f25_551 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->CalcLength(arg_sp688);
                temp_f26_554 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
                temp_f0_560 = -((0.5f * temp_f26_554) - arg_sp674);
                arg_sp670 = -((0.5f * temp_f25_551) - (f32) arg_sp670);
                arg_sp674 = temp_f0_560;
                arg_sp710.SetIdentity();
                arg_sp710.Translate((Matrix *) &arg_sp710, *((MKVector3 *) &arg_sp670));
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(arg_sp688, temp_f25_551, temp_f26_554, (Matrix *) &arg_sp710, 0xA, ((u32) (128.0f * var_f31_354) << 0x18) | 0x800000 | 0x8080, 1.0f, 1.0f, NULL, 1U);
            }
        }
        temp_r7_586 = M2C_FIELD(arg0, void **, 0);
        if ((M2C_FIELD(temp_r7_586, s32 *, 0) & 0x10) && ((void *) M2C_FIELD(arg0, void **, 0x24) != NULL) && ((u8) M2C_FIELD(arg0, u8 *, 0x35) != 0)) {
            temp_r5_602 = &vEnemyHealthBarSize[M2C_FIELD(arg0, s32 *, 0x18)];
            var_r6_605 = iEnemyHealthBarColours - 1;
            arg_sp2F0 = M2C_FIELD(temp_r5_602, f32 *, -8);
            arg_sp2F4 = M2C_FIELD(temp_r5_602, f32 *, -4);
            arg_sp160 = M2C_FIELD(temp_r7_586, f32 *, 0x38) * 0.75f;
            arg_sp164 = M2C_FIELD(temp_r7_586, f32 *, 0x3C) * 0.75f;
            arg_sp158 = arg_sp2F0 * 0.75f;
            arg_sp15C = arg_sp2F4 * 0.75f;
            arg_sp2E8 = arg_sp160;
            arg_sp2EC = arg_sp164;
            arg_sp238 = arg_sp158;
            arg_sp23C = arg_sp15C;
            arg_sp150 = arg_sp2E8 - arg_sp238;
            arg_sp154 = arg_sp2EC - arg_sp23C;
            arg_sp2E0 = arg_sp150;
            arg_sp2E4 = arg_sp154;
            arg_sp148 = M2C_FIELD(temp_r7_586, f32 *, 0x40) * 0.75f;
            arg_sp14C = M2C_FIELD(temp_r7_586, f32 *, 0x44) * 0.75f;
            arg_sp2D8 = arg_sp148;
            arg_sp2DC = arg_sp14C;
            temp_f3_651 = M2C_FIELD(arg0, f32 *, 0x30);
            temp_r0_657 = (M2C_FIELD(arg0, s32 *, 0x1C) - M2C_FIELD(arg0, s32 *, 0x20)) - 1;
            if (temp_r0_657 < var_r6_605) {
                var_r6_605 = temp_r0_657;
            }
            temp_r3_669 = &vEnemyHealthBarColour[var_r6_605];
            arg_sp460 = 0.3f;
            arg_sp464 = 0.3f;
            arg_sp468 = 0.3f;
            arg_sp46C = var_f31_354;
            arg_sp668 = temp_r3_669->unk8;
            arg_sp470 = 1.0f;
            arg_sp474 = 1.0f;
            arg_sp478 = 1.0f;
            arg_sp47C = var_f31_354;
            arg_sp660 = temp_r3_669->unk0;
            arg_sp66C = var_f31_354;
            arg_sp5B0 = (f64) arg_sp460;
            arg_sp5B8 = (f64) arg_sp468;
            arg_sp5C0 = (f64) arg_sp470;
            arg_sp5C8 = (f64) arg_sp478;
            arg_sp8 = 1e-45f;
            Hud_DrawBarHorz(*((MKVector2 *) &arg_sp318), *((MKVector2 *) &arg_sp2E8), *((MKVector2 *) &arg_sp2E0), *((MKVector2 *) &arg_sp2D8), *((MKVector2 *) &arg_sp2E0), *((MKVector4 *) &arg_sp5C0), *((MKVector4 *) &arg_sp5B0), *((MKVector4 *) &arg_sp660), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x94), M2C_FIELD(arg0, f32 *, 0x2C) / temp_f3_651, M2C_FIELD(arg0, f32 *, 0x28) / temp_f3_651, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            arg_sp654 = 0;
            arg_sp658 = NULL;
            arg_sp650 = 0x8D;
            temp_r3_711 = M2C_FIELD(arg0, void **, 0x24);
            M2C_FIELD(M2C_FIELD(temp_r3_711, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_711, &arg_sp650);
            if (arg_sp658 != NULL) {
                temp_r5_719 = M2C_FIELD(arg0, void **, 0);
                arg_sp458 = 0.0f;
                arg_sp140 = arg_sp318 + M2C_FIELD(temp_r5_719, f32 *, 0x30);
                arg_sp144 = arg_sp31C + M2C_FIELD(temp_r5_719, f32 *, 0x34);
                arg_sp230 = arg_sp140;
                arg_sp234 = arg_sp144;
                arg_sp450 = arg_sp230;
                arg_sp454 = arg_sp234;
                arg_sp648 = (f64) arg_sp458;
                arg_sp640 = (f64) arg_sp450;
                temp_f25_746 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->CalcLength(arg_sp658);
                temp_f26_749 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
                temp_f0_755 = -((0.5f * temp_f26_749) - arg_sp644);
                arg_sp640 = -((0.5f * temp_f25_746) - (f32) arg_sp640);
                arg_sp644 = temp_f0_755;
                arg_sp6D0.SetIdentity();
                arg_sp6D0.Translate((Matrix *) &arg_sp6D0, *((MKVector3 *) &arg_sp640));
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString(arg_sp658, temp_f25_746, temp_f26_749, (Matrix *) &arg_sp6D0, 0xA, ((u32) (128.0f * var_f31_354) << 0x18) | 0x800000 | 0x8080, 1.0f, 1.0f, NULL, 1U);
            }
        }
        temp_r12_781 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r12_781, s32 *, 0) & 0x40) {
            arg_sp440 = 1.0f;
            arg_sp444 = 1.0f;
            arg_sp448 = 1.0f;
            arg_sp44C = var_f31_354;
            arg_sp5A0 = (f64) arg_sp440;
            arg_sp5A8 = (f64) arg_sp448;
            arg_sp128 = M2C_FIELD(temp_r12_781, f32 *, 0x78) * 0.75f;
            arg_sp12C = M2C_FIELD(temp_r12_781, f32 *, 0x7C) * 0.75f;
            arg_sp218 = arg_sp128;
            arg_sp21C = arg_sp12C;
            arg_sp138 = M2C_FIELD(temp_r12_781, f32 *, 0x20) * 0.75f;
            arg_sp13C = M2C_FIELD(temp_r12_781, f32 *, 0x24) * 0.75f;
            arg_sp220 = arg_sp138;
            arg_sp224 = arg_sp13C;
            arg_sp130 = arg_sp318 + arg_sp220;
            arg_sp134 = arg_sp31C + arg_sp224;
            arg_sp228 = arg_sp130;
            arg_sp22C = arg_sp134;
            Hud_DrawIcon(0, 3, *((MKVector2 *) &arg_sp228), *((MKVector2 *) &arg_sp218), *((MKVector4 *) &arg_sp5A0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
        }
        temp_r26_841 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r26_841, s32 *, 0) & 1) {
            arg_sp124 = 0.0f;
            arg_sp120 = 2.5f * GameData::gameData.unk74;
            arg_sp2D4 = arg_sp124;
            arg_sp2D0 = arg_sp120;
            arg_sp118 = M2C_FIELD(temp_r26_841, f32 *, 0x38) * 0.75f;
            arg_sp11C = M2C_FIELD(temp_r26_841, f32 *, 0x3C) * 0.75f;
            arg_sp110 = arg_sp2D0 * 0.75f;
            arg_sp114 = arg_sp2D4 * 0.75f;
            arg_sp2C8 = arg_sp118;
            arg_sp2CC = arg_sp11C;
            arg_sp210 = arg_sp110;
            arg_sp214 = arg_sp114;
            arg_sp410 = 1.0f;
            arg_sp414 = 0.0f;
            arg_sp108 = arg_sp2C8 + arg_sp210;
            arg_sp10C = arg_sp2CC + arg_sp214;
            arg_sp2C0 = arg_sp108;
            arg_sp2C4 = arg_sp10C;
            arg_sp418 = 0.0f;
            arg_sp41C = var_f31_354;
            arg_sp100 = M2C_FIELD(temp_r26_841, f32 *, 0x40) * 0.75f;
            arg_sp104 = M2C_FIELD(temp_r26_841, f32 *, 0x44) * 0.75f;
            arg_sp420 = 0.3f;
            arg_sp424 = 0.3f;
            arg_sp428 = 0.3f;
            arg_sp42C = var_f31_354;
            arg_sp430 = 1.0f;
            arg_sp434 = 1.0f;
            arg_sp438 = 1.0f;
            arg_sp43C = var_f31_354;
            arg_sp2B8 = arg_sp100;
            arg_sp2BC = arg_sp104;
            arg_sp570 = (f64) arg_sp410;
            arg_sp578 = (f64) arg_sp418;
            arg_sp580 = (f64) arg_sp420;
            arg_sp588 = (f64) arg_sp428;
            arg_sp590 = (f64) arg_sp430;
            arg_sp598 = (f64) arg_sp438;
            arg_sp8 = 0.0f;
            Hud_DrawBarHorz(*((MKVector2 *) &arg_sp318), *((MKVector2 *) &arg_sp2C8), *((MKVector2 *) &arg_sp2C0), *((MKVector2 *) &arg_sp2B8), *((MKVector2 *) &arg_sp2C0), *((MKVector4 *) &arg_sp590), *((MKVector4 *) &arg_sp580), *((MKVector4 *) &arg_sp570), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x94), GameData::gameData.unk70 / GameData::gameData.unk74, GameData::gameData.unk78 / GameData::gameData.unk74, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        if (temp_r30_401 != 0) {
            temp_r26_945 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_r26_945, s32 *, 0) & 2) {
                arg_spFC = 0.0f;
                arg_spF8 = 2.0f * GameData::gameData.unkA4;
                arg_sp2B4 = arg_spFC;
                arg_sp2B0 = arg_spF8;
                arg_spF0 = M2C_FIELD(temp_r26_945, f32 *, 0x48) * 0.75f;
                arg_spF4 = M2C_FIELD(temp_r26_945, f32 *, 0x4C) * 0.75f;
                arg_spE8 = arg_sp2B0 * 0.75f;
                arg_spEC = arg_sp2B4 * 0.75f;
                arg_sp2A8 = arg_spF0;
                arg_sp2AC = arg_spF4;
                arg_sp208 = arg_spE8;
                arg_sp20C = arg_spEC;
                arg_sp3E0 = 0.0f;
                arg_sp3E4 = 1.0f;
                arg_spE0 = arg_sp2A8 + arg_sp208;
                arg_spE4 = arg_sp2AC + arg_sp20C;
                arg_sp2A0 = arg_spE0;
                arg_sp2A4 = arg_spE4;
                arg_sp3E8 = 0.0f;
                arg_sp3EC = var_f31_354;
                arg_spD8 = M2C_FIELD(temp_r26_945, f32 *, 0x50) * 0.75f;
                arg_spDC = M2C_FIELD(temp_r26_945, f32 *, 0x54) * 0.75f;
                arg_sp3F0 = 0.3f;
                arg_sp3F4 = 0.3f;
                arg_sp3F8 = 0.3f;
                arg_sp3FC = var_f31_354;
                arg_sp400 = 1.0f;
                arg_sp404 = 1.0f;
                arg_sp408 = 1.0f;
                arg_sp40C = var_f31_354;
                arg_sp298 = arg_spD8;
                arg_sp29C = arg_spDC;
                arg_sp540 = (f64) arg_sp3E0;
                arg_sp548 = (f64) arg_sp3E8;
                arg_sp550 = (f64) arg_sp3F0;
                arg_sp558 = (f64) arg_sp3F8;
                arg_sp560 = (f64) arg_sp400;
                arg_sp568 = (f64) arg_sp408;
                arg_sp8 = 0.0f;
                Hud_DrawBarHorz(*((MKVector2 *) &arg_sp318), *((MKVector2 *) &arg_sp2A8), *((MKVector2 *) &arg_sp2A0), *((MKVector2 *) &arg_sp298), *((MKVector2 *) &arg_sp2A0), *((MKVector4 *) &arg_sp560), *((MKVector4 *) &arg_sp550), *((MKVector4 *) &arg_sp540), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x9C), GameData::gameData.unkA0 / GameData::gameData.unkA4, GameData::gameData.unkA8 / GameData::gameData.unkA4, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
        }
        temp_r26_1047 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r26_1047, s32 *, 0) & 4) {
            arg_spD0 = 0.0f;
            arg_spD4 = 0.2f * GameData::gameData.unk8C;
            arg_sp290 = arg_spD0;
            arg_sp294 = arg_spD4;
            arg_spC8 = M2C_FIELD(temp_r26_1047, f32 *, 0x58) * 0.75f;
            arg_spCC = M2C_FIELD(temp_r26_1047, f32 *, 0x5C) * 0.75f;
            arg_spC0 = arg_sp290 * 0.75f;
            arg_spC4 = arg_sp294 * 0.75f;
            arg_sp288 = arg_spC8;
            arg_sp28C = arg_spCC;
            arg_sp200 = arg_spC0;
            arg_sp204 = arg_spC4;
            arg_sp3B0 = 0.0f;
            arg_sp3B4 = 1.0f;
            arg_spB8 = arg_sp288 + arg_sp200;
            arg_spBC = arg_sp28C + arg_sp204;
            arg_sp280 = arg_spB8;
            arg_sp284 = arg_spBC;
            arg_sp3B8 = 1.0f;
            arg_sp3BC = var_f31_354;
            arg_spB0 = M2C_FIELD(temp_r26_1047, f32 *, 0x60) * 0.75f;
            arg_spB4 = M2C_FIELD(temp_r26_1047, f32 *, 0x64) * 0.75f;
            arg_sp3C0 = 0.3f;
            arg_sp3C4 = 0.3f;
            arg_sp3C8 = 0.3f;
            arg_sp3CC = var_f31_354;
            arg_sp3D0 = 1.0f;
            arg_sp3D4 = 1.0f;
            arg_sp3D8 = 1.0f;
            arg_sp3DC = var_f31_354;
            arg_sp278 = arg_spB0;
            arg_sp27C = arg_spB4;
            arg_sp510 = (f64) arg_sp3B0;
            arg_sp518 = (f64) arg_sp3B8;
            arg_sp520 = (f64) arg_sp3C0;
            arg_sp528 = (f64) arg_sp3C8;
            arg_sp530 = (f64) arg_sp3D0;
            arg_sp538 = (f64) arg_sp3D8;
            arg_sp8 = 0.0f;
            Hud_DrawBarVert(*((MKVector2 *) &arg_sp318), *((MKVector2 *) &arg_sp288), *((MKVector2 *) &arg_sp280), *((MKVector2 *) &arg_sp278), *((MKVector2 *) &arg_sp280), *((MKVector4 *) &arg_sp530), *((MKVector4 *) &arg_sp520), *((MKVector4 *) &arg_sp510), 0.75f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0xA0), GameData::gameData.unk88 / GameData::gameData.unk8C, GameData::gameData.unk90 / GameData::gameData.unk8C, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        }
        temp_r4_1149 = M2C_FIELD(arg0, void **, 0);
        if (!(M2C_FIELD(temp_r4_1149, s32 *, 0) & 0x10)) {
            arg_spA8 = M2C_FIELD(temp_r4_1149, f32 *, 0x28) * 0.75f;
            arg_spAC = M2C_FIELD(temp_r4_1149, f32 *, 0x2C) * 0.75f;
            arg_sp1F8 = arg_spA8;
            arg_sp1FC = arg_spAC;
            arg_spA0 = arg_sp318 + arg_sp1F8;
            arg_spA4 = arg_sp31C + arg_sp1FC;
            arg_sp270 = arg_spA0;
            arg_sp274 = arg_spA4;
            M2C_STRUCT_COPY((s32) &arg_sp68C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            arg_sp690.SetRotationRoll(-0.25f);
            arg_sp9C = 8.0f;
            arg_sp88 = 25.6f;
            arg_sp8C = 25.6f;
            arg_sp1EC = arg_sp9C;
            arg_sp3A0 = 1.0f;
            arg_sp3A4 = 1.0f;
            arg_sp3A8 = 1.0f;
            arg_sp3AC = var_f31_354;
            arg_sp500 = (f64) arg_sp3A0;
            arg_sp94 = arg_sp274 + arg_sp1EC;
            arg_sp508 = (f64) arg_sp3A8;
            arg_sp1E0 = arg_sp88;
            arg_sp1E4 = arg_sp8C;
            arg_sp1F4 = arg_sp94;
            arg_sp98 = 0.75f * ((0.5f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x88)) + 12.8f);
            arg_sp1E8 = arg_sp98;
            arg_sp90 = arg_sp270 + arg_sp1E8;
            arg_sp1F0 = arg_sp90;
            Hud_DrawIcon(0, 0xD, *((MKVector2 *) &arg_sp1F0), *((MKVector2 *) &arg_sp1E0), *((MKVector4 *) &arg_sp500), 0.0f, 0.0f, 1.0f, 1.0f, 1U, 1U, *((Matrix *) &arg_sp690));
            arg_sp84 = 0.0f;
            arg_sp70 = 19.2f;
            arg_sp74 = 19.2f;
            arg_sp398 = 1.0f;
            arg_sp39C = var_f31_354;
            arg_sp390 = 1.0f;
            arg_sp394 = 1.0f;
            arg_sp1D4 = arg_sp84;
            arg_sp4F8 = (f64) arg_sp398;
            arg_sp4F0 = (f64) arg_sp390;
            arg_sp1C8 = arg_sp70;
            arg_sp1CC = arg_sp74;
            arg_sp7C = arg_sp274 - arg_sp1D4;
            arg_sp1DC = arg_sp7C;
            arg_sp80 = 0.75f * ((0.5f * M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x88)) + 9.6f);
            arg_sp1D0 = arg_sp80;
            arg_sp78 = arg_sp270 - arg_sp1D0;
            arg_sp1D8 = arg_sp78;
            Hud_DrawIcon(0, 0xD, *((MKVector2 *) &arg_sp1D8), *((MKVector2 *) &arg_sp1C8), *((MKVector4 *) &arg_sp4F0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, *((Matrix *) &arg_sp690));
        }
        temp_r12_1298 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r12_1298, s32 *, 0) & 0x20) {
            arg_sp380 = 1.0f;
            arg_sp384 = 1.0f;
            arg_sp388 = 1.0f;
            arg_sp38C = var_f31_354;
            arg_sp4E0 = (f64) arg_sp380;
            arg_sp4E8 = (f64) arg_sp388;
            arg_sp58 = M2C_FIELD(temp_r12_1298, f32 *, 0x80) * 0.75f;
            arg_sp5C = M2C_FIELD(temp_r12_1298, f32 *, 0x84) * 0.75f;
            arg_sp1B0 = arg_sp58;
            arg_sp1B4 = arg_sp5C;
            arg_sp68 = M2C_FIELD(temp_r12_1298, f32 *, 0x20) * 0.75f;
            arg_sp6C = M2C_FIELD(temp_r12_1298, f32 *, 0x24) * 0.75f;
            arg_sp1B8 = arg_sp68;
            arg_sp1BC = arg_sp6C;
            arg_sp60 = arg_sp318 + arg_sp1B8;
            arg_sp64 = arg_sp31C + arg_sp1BC;
            arg_sp1C0 = arg_sp60;
            arg_sp1C4 = arg_sp64;
            Hud_DrawIcon(0, 3, *((MKVector2 *) &arg_sp1C0), *((MKVector2 *) &arg_sp1B0), *((MKVector4 *) &arg_sp4E0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
        }
        temp_r4_1358 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(temp_r4_1358, s32 *, 0) & 0x80) {
            arg_sp50 = M2C_FIELD(temp_r4_1358, f32 *, 0x28) * 0.75f;
            arg_sp54 = M2C_FIELD(temp_r4_1358, f32 *, 0x2C) * 0.75f;
            arg_sp1A8 = arg_sp50;
            arg_sp1AC = arg_sp54;
            arg_sp48 = arg_sp318 + arg_sp1A8;
            arg_sp4C = arg_sp31C + arg_sp1AC;
            arg_sp268 = arg_sp48;
            arg_sp26C = arg_sp4C;
            arg_sp40 = M2C_FIELD(temp_r4_1358, f32 *, 0x88) * 0.75f;
            arg_sp44 = M2C_FIELD(temp_r4_1358, f32 *, 0x8C) * 0.75f;
            arg_sp260 = arg_sp40;
            arg_sp264 = arg_sp44;
            if (temp_r30_401 == 0) {
                arg_sp370 = 0.8f;
                arg_sp374 = 0.0f;
                arg_sp378 = 0.8f;
                arg_sp37C = var_f31_354;
                arg_sp360 = 0.3f;
                arg_sp364 = 0.0f;
                arg_sp368 = 0.3f;
                arg_sp36C = var_f31_354;
                arg_sp630 = (f64) arg_sp370;
                arg_sp638 = (f64) arg_sp378;
                arg_sp620 = (f64) arg_sp360;
                arg_sp628 = (f64) arg_sp368;
                arg_sp8 = 6.2831855f;
                arg_spC = 6.2831855f;
                arg_sp10 = 0.0f;
                arg_sp14 = 0.0f;
                arg_sp18 = 1.0f;
                arg_sp1C = 1.0f;
                Hud_DrawArc(arg_sp268, arg_sp26C, 0.35f * arg_sp260, 0.35f * arg_sp264, 0.0f, 0.0f, 0.0f, 0.0f, (f32) (f64) arg_sp378, (f32) (f64) arg_sp370, (MKVector4 *) &arg_sp630, (MKVector4 *) &arg_sp620, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
            if (temp_r30_401 != 0) {
                arg_sp350 = 1.0f;
                arg_sp38 = arg_sp260 * 0.68f;
                temp_r0_1456 = M2C_FIELD(&gb, u8 *, 0x35D) - 1;
                arg_sp354 = 1.0f;
                arg_sp3C = arg_sp264 * 0.68f;
                arg_sp358 = 1.0f;
                arg_sp35C = var_f31_354;
                arg_sp4D0 = (f64) arg_sp350;
                arg_sp4D8 = (f64) arg_sp358;
                arg_sp1A0 = arg_sp38;
                arg_sp1A4 = arg_sp3C;
                Hud_DrawIcon(GameData::gameData.unk15C, 8 & ~((temp_r0_1456 - temp_r0_1456) - !M2C_CARRY), *((MKVector2 *) &arg_sp268), *((MKVector2 *) &arg_sp1A0), *((MKVector4 *) &arg_sp4D0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
            }
            arg_sp340 = 1.0f;
            arg_sp344 = 1.0f;
            arg_sp348 = 1.0f;
            arg_sp34C = var_f31_354;
            arg_sp4C0 = (f64) arg_sp340;
            arg_sp4C8 = (f64) arg_sp348;
            Hud_DrawIcon(0, 3, *((MKVector2 *) &arg_sp268), *((MKVector2 *) &arg_sp260), *((MKVector4 *) &arg_sp4C0), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
        }
        if (temp_r30_401 != 0) {
            temp_r3_1507 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_r3_1507, s32 *, 0) & 8) {
                temp_f0_1515 = GameData::gameData.unkB8 / GameData::gameData.unkBC;
                var_f1_1519 = 1.0f;
                arg_sp30 = M2C_FIELD(temp_r3_1507, f32 *, 0x28) * 0.75f;
                arg_sp34 = M2C_FIELD(temp_r3_1507, f32 *, 0x2C) * 0.75f;
                arg_sp198 = arg_sp30;
                arg_sp19C = arg_sp34;
                arg_sp20 = M2C_FIELD(temp_r3_1507, f32 *, 0x88) * 0.75f;
                arg_sp24 = M2C_FIELD(temp_r3_1507, f32 *, 0x8C) * 0.75f;
                arg_sp28 = arg_sp318 + arg_sp198;
                arg_sp2C = arg_sp31C + arg_sp19C;
                arg_sp258 = arg_sp28;
                arg_sp25C = arg_sp2C;
                arg_sp250 = arg_sp20;
                arg_sp254 = arg_sp24;
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (temp_f0_1515 == 1.0f) {
                    var_f3_1567 = (M2C_FIELD(&gb, f32 *, 0x30C) - (f32) (s32) M2C_FIELD(&gb, f32 *, 0x30C)) - 0.5f;
                    if (var_f3_1567 < 0.0f) {
                        var_f3_1567 = -var_f3_1567;
                    }
                    var_f1_1519 = 0.5f + var_f3_1567;
                }
                arg_sp330 = 0.753f * var_f1_1519;
                arg_sp334 = 0.0f;
                arg_sp338 = 0.95f * var_f1_1519;
                arg_sp33C = var_f31_354;
                temp_f26_1596 = -((6.2831855f * temp_f0_1515) - -1.6650441f);
                temp_f29_1603 = 0.41f * arg_sp254;
                temp_f28_1604 = 0.41f * arg_sp250;
                arg_sp320 = 0.867f * var_f1_1519;
                arg_sp324 = 0.357f * var_f1_1519;
                arg_sp328 = var_f1_1519;
                arg_sp32C = var_f31_354;
                arg_sp610 = (f64) arg_sp330;
                arg_sp618 = (f64) arg_sp338;
                arg_sp600 = (f64) arg_sp320;
                arg_sp608 = (f64) arg_sp328;
                arg_sp8 = -1.6650441f;
                arg_spC = -1.6650441f;
                arg_sp10 = 0.0f;
                arg_sp14 = 0.0f;
                arg_sp18 = 1.0f;
                arg_sp1C = 1.0f;
                Hud_DrawArc(arg_sp258, arg_sp25C, 0.47f * arg_sp250, 0.47f * arg_sp254, temp_f28_1604, temp_f29_1603, temp_f26_1596, temp_f26_1596, -1.6650441f, (f32) (f64) arg_sp328, (MKVector4 *) &arg_sp610, (MKVector4 *) &arg_sp610, NULL, NULL, (f32) (f64) arg_sp320, (f32) (f64) arg_sp338, (f32) (f64) arg_sp330, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                arg_sp8 = -1.6650441f;
                arg_spC = -1.6650441f;
                arg_sp10 = 0.0f;
                arg_sp14 = 0.0f;
                arg_sp18 = 1.0f;
                arg_sp1C = 1.0f;
                Hud_DrawArc(arg_sp258, arg_sp25C, temp_f28_1604, temp_f29_1603, 0.38f * arg_sp250, 0.38f * arg_sp254, temp_f26_1596, temp_f26_1596, 1.0f, 0.0f, (MKVector4 *) &arg_sp600, (MKVector4 *) &arg_sp600, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                arg_sp8 = -1.6650441f;
                arg_spC = -1.6650441f;
                arg_sp10 = 0.0f;
                arg_sp14 = 0.0f;
                arg_sp18 = 1.0f;
                arg_sp1C = 1.0f;
                Hud_DrawArc(arg_sp258, arg_sp25C, 0.425f * arg_sp250, 0.425f * arg_sp254, 0.39f * arg_sp250, 0.39f * arg_sp254, temp_f26_1596, temp_f26_1596, 1.0f, M2C_ERROR(/* Read from unset register $f10 */), (MKVector4 *) &arg_sp610, (MKVector4 *) &arg_sp600, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void Hud_DrawBarVert(const MKVector2 &arg0, const MKVector2 &arg1, const MKVector2 &arg2, const MKVector2 &arg3, const MKVector2 &arg4, const MKVector4 &arg5, const MKVector4 &arg6, const MKVector4 &arg7, float arg8, float arg9, float arg10, bool arg11) {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
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
    f32 temp_f23_1796;
    f32 temp_f28_1756;
    f32 temp_f28_1919;
    f32 temp_f29_1734;
    f32 temp_f29_1791;
    f32 temp_f29_1951;
    f32 temp_f2_1917;
    f32 temp_f3_1923;
    f32 temp_f5_1730;
    f32 temp_f6_1728;
    f32 var_f0_1760;
    f32 var_f0_1769;
    f32 var_f0_1853;
    f32 var_f0_1864;
    f32 var_f0_1895;
    f32 var_f0_1906;
    f32 var_f26_1754;
    f32 var_f27_1755;
    f32 var_f2_1943;
    f32 var_f2_2009;
    f32 var_f4_1742;
    f32 var_f4_1920;
    f32 var_f4_2004;
    f32 var_f5_1960;
    f32 var_f5_2026;

    temp_f6_1728 = arg4.unk4;
    temp_f5_1730 = arg3.unk4;
    temp_f29_1734 = 0.6f * arg8;
    if (temp_f6_1728 > temp_f5_1730) {
        var_f4_1742 = temp_f29_1734;
    } else {
        var_f4_1742 = -temp_f29_1734;
    }
    var_f26_1754 = (0.5f * var_f4_1742) + (temp_f6_1728 - temp_f5_1730);
    var_f27_1755 = arg0.unk4 + temp_f5_1730;
    temp_f28_1756 = -((0.5f * temp_f29_1734) - (arg0.unk0 + arg3.unk0));
    if (arg_sp8 != 0) {
        if (temp_f6_1728 > temp_f5_1730) {
            var_f0_1760 = temp_f29_1734;
        } else {
            var_f0_1760 = -temp_f29_1734;
        }
        var_f26_1754 += 0.5f * var_f0_1760;
        if (temp_f6_1728 > temp_f5_1730) {
            var_f0_1769 = -temp_f29_1734;
        } else {
            var_f0_1769 = temp_f29_1734;
        }
        var_f27_1755 += 0.5f * var_f0_1769;
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg6);
    MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
    temp_f29_1791 = temp_f28_1756 + temp_f29_1734;
    MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
    temp_f23_1796 = var_f27_1755 + var_f26_1754;
    MKSetPositionF(temp_f28_1756, temp_f23_1796, 0.0f);
    MKSetPositionF(temp_f29_1791, temp_f23_1796, 0.0f);
    MKEnd();
    MKEndPrimitive();
    if (arg9 != arg10) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0xC, 3);
        MKBegin(4);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r25, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r25, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r26, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spC8 = spB8;
        spD0 = spC0;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        spD8 = spA8;
        spE0 = spB0;
        MKSetColorV(*((MKVector4 *) &spD8));
        MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
        MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
        if (arg9 > arg10) {
            var_f0_1853 = arg9;
        } else {
            var_f0_1853 = arg10;
        }
        MKSetPositionF(temp_f28_1756, (var_f26_1754 * var_f0_1853) + var_f27_1755, 0.0f);
        if (arg9 > arg10) {
            var_f0_1864 = arg9;
        } else {
            var_f0_1864 = arg10;
        }
        MKSetPositionF(temp_f29_1791, (var_f26_1754 * var_f0_1864) + var_f27_1755, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg7);
    MKSetPositionF(temp_f28_1756, var_f27_1755, 0.0f);
    MKSetPositionF(temp_f29_1791, var_f27_1755, 0.0f);
    if (arg9 < arg10) {
        var_f0_1895 = arg9;
    } else {
        var_f0_1895 = arg10;
    }
    MKSetPositionF(temp_f28_1756, (var_f26_1754 * var_f0_1895) + var_f27_1755, 0.0f);
    if (arg9 < arg10) {
        var_f0_1906 = arg9;
    } else {
        var_f0_1906 = arg10;
    }
    MKSetPositionF(temp_f29_1791, (var_f26_1754 * var_f0_1906) + var_f27_1755, 0.0f);
    MKEnd();
    MKEndPrimitive();
    temp_f2_1917 = arg1.unk4;
    temp_f28_1919 = arg2.unk4 - temp_f2_1917;
    var_f4_1920 = 0.5f;
    sp50 = 0.0f;
    temp_f3_1923 = 0.5f * temp_f28_1919;
    sp98 = sp50;
    sp54 = temp_f3_1923;
    sp9C = sp54;
    sp48 = arg1.unk0 + sp98;
    sp4C = temp_f2_1917 + sp9C;
    spA0 = sp48;
    spA4 = sp4C;
    if (temp_f28_1919 > 0.0f) {
        var_f4_1920 = 1.0f;
    }
    var_f2_1943 = 0.0f;
    if (temp_f28_1919 > 0.0f) {
        var_f2_1943 = 0.5f;
    }
    sp30 = arg8;
    temp_f29_1951 = 0.5f * arg8;
    sp34 = temp_f29_1951;
    sp80 = sp30;
    sp84 = sp34;
    if (temp_f28_1919 > 0.0f) {
        var_f5_1960 = arg8;
    } else {
        var_f5_1960 = -arg8;
    }
    sp40 = spA0;
    sp88 = sp40;
    sp44 = (0.25f * var_f5_1960) + (spA4 + temp_f3_1923);
    sp8C = sp44;
    sp38 = arg0.unk0 + sp88;
    sp3C = arg0.unk4 + sp8C;
    sp90 = sp38;
    sp94 = sp3C;
    Hud_DrawIcon(0, 3, *((MKVector2 *) &sp90), *((MKVector2 *) &sp80), arg5, 0.0f, var_f2_1943, 1.0f, var_f4_1920, 0U, 0U, Matrix::identity);
    if (arg_sp8 != 0) {
        if (temp_f28_1919 > 0.0f) {
            var_f4_2004 = 0.5f;
        } else {
            var_f4_2004 = 1.0f;
        }
        var_f2_2009 = 0.0f;
        if (temp_f28_1919 > 0.0f) {

        } else {
            var_f2_2009 = 0.5f;
        }
        sp18 = arg8;
        sp1C = temp_f29_1951;
        sp68 = sp18;
        sp6C = sp1C;
        if (temp_f28_1919 > 0.0f) {
            var_f5_2026 = -arg8;
        } else {
            var_f5_2026 = arg8;
        }
        sp28 = spA0;
        sp2C = (0.25f * var_f5_2026) + arg1.unk4;
        sp70 = sp28;
        sp74 = sp2C;
        sp20 = arg0.unk0 + sp70;
        sp24 = arg0.unk4 + sp74;
        sp78 = sp20;
        sp7C = sp24;
        Hud_DrawIcon(0, 3, *((MKVector2 *) &sp78), *((MKVector2 *) &sp68), arg5, 0.0f, var_f2_2009, 1.0f, var_f4_2004, 0U, 0U, Matrix::identity);
    }
    sp8 = arg8;
    spC = temp_f28_1919;
    sp10 = arg0.unk0 + spA0;
    sp14 = arg0.unk4 + spA4;
    sp58 = sp8;
    sp5C = spC;
    sp60 = sp10;
    sp64 = sp14;
    Hud_DrawIcon(0, 3, *((MKVector2 *) &sp60), *((MKVector2 *) &sp58), arg5, 0.0f, 0.5f, 1.0f, 0.5f, 0U, 0U, Matrix::identity);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void Hud_DrawBarHorz(const MKVector2 &arg0, const MKVector2 &arg1, const MKVector2 &arg2, const MKVector2 &arg3, const MKVector2 &arg4, const MKVector4 &arg5, const MKVector4 &arg6, const MKVector4 &arg7, float arg8, float arg9, float arg10, bool arg11) {
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
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
    f32 temp_f23_2211;
    f32 temp_f23_2381;
    f32 temp_f27_2339;
    f32 temp_f28_2176;
    f32 temp_f29_2342;
    f32 temp_f30_2154;
    f32 temp_f30_2216;
    f32 temp_f31_2415;
    f32 temp_f3_2346;
    f32 temp_f4_2340;
    f32 temp_f5_2150;
    f32 temp_f6_2148;
    f32 var_f0_2180;
    f32 var_f0_2189;
    f32 var_f0_2268;
    f32 var_f0_2283;
    f32 var_f0_2310;
    f32 var_f0_2325;
    f32 var_f0_2426;
    f32 var_f27_2174;
    f32 var_f29_2175;
    f32 var_f2_2478;
    f32 var_f2_2529;
    f32 var_f4_2162;
    f32 var_f4_2372;

    temp_f6_2148 = arg4.unk0;
    temp_f5_2150 = arg3.unk0;
    temp_f30_2154 = 0.7f * arg8;
    if (temp_f6_2148 > temp_f5_2150) {
        var_f4_2162 = temp_f30_2154;
    } else {
        var_f4_2162 = -temp_f30_2154;
    }
    var_f27_2174 = (0.5f * var_f4_2162) + (temp_f6_2148 - temp_f5_2150);
    var_f29_2175 = arg0.unk0 + temp_f5_2150;
    temp_f28_2176 = -((0.5f * temp_f30_2154) - (arg0.unk4 + arg3.unk4));
    if (arg_sp8 != 0) {
        if (temp_f6_2148 > temp_f5_2150) {
            var_f0_2180 = temp_f30_2154;
        } else {
            var_f0_2180 = -temp_f30_2154;
        }
        var_f27_2174 += 0.5f * var_f0_2180;
        if (temp_f6_2148 > temp_f5_2150) {
            var_f0_2189 = -temp_f30_2154;
        } else {
            var_f0_2189 = temp_f30_2154;
        }
        var_f29_2175 += 0.5f * var_f0_2189;
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg6);
    MKSetPositionF(var_f29_2175, temp_f28_2176, 0.0f);
    temp_f23_2211 = var_f29_2175 + var_f27_2174;
    MKSetPositionF(temp_f23_2211, temp_f28_2176, 0.0f);
    temp_f30_2216 = temp_f28_2176 + temp_f30_2154;
    MKSetPositionF(var_f29_2175, temp_f30_2216, 0.0f);
    MKSetPositionF(temp_f23_2211, temp_f30_2216, 0.0f);
    MKEnd();
    MKEndPrimitive();
    if (arg9 != arg10) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0xC, 3);
        MKBegin(4);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r25, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r25, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r26, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp168 = sp158;
        sp170 = sp160;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp178 = sp148;
        sp180 = sp150;
        MKSetColorV(*((MKVector4 *) &sp178));
        MKSetPositionF(var_f29_2175, temp_f28_2176, 0.0f);
        if (arg9 > arg10) {
            var_f0_2268 = arg9;
        } else {
            var_f0_2268 = arg10;
        }
        MKSetPositionF((var_f27_2174 * var_f0_2268) + var_f29_2175, temp_f28_2176, 0.0f);
        MKSetPositionF(var_f29_2175, temp_f30_2216, 0.0f);
        if (arg9 > arg10) {
            var_f0_2283 = arg9;
        } else {
            var_f0_2283 = arg10;
        }
        MKSetPositionF((var_f27_2174 * var_f0_2283) + var_f29_2175, temp_f30_2216, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorV(arg7);
    MKSetPositionF(var_f29_2175, temp_f28_2176, 0.0f);
    if (arg9 < arg10) {
        var_f0_2310 = arg9;
    } else {
        var_f0_2310 = arg10;
    }
    MKSetPositionF((var_f27_2174 * var_f0_2310) + var_f29_2175, temp_f28_2176, 0.0f);
    MKSetPositionF(var_f29_2175, temp_f30_2216, 0.0f);
    if (arg9 < arg10) {
        var_f0_2325 = arg9;
    } else {
        var_f0_2325 = arg10;
    }
    MKSetPositionF((var_f27_2174 * var_f0_2325) + var_f29_2175, temp_f30_2216, 0.0f);
    MKEnd();
    MKEndPrimitive();
    temp_f27_2339 = 0.5f * arg8;
    temp_f4_2340 = arg1.unk0;
    temp_f29_2342 = arg2.unk0 - temp_f4_2340;
    sp80 = temp_f27_2339;
    temp_f3_2346 = 0.5f * temp_f29_2342;
    spA4 = -0.5f * temp_f27_2339;
    spA0 = temp_f3_2346;
    sp13C = spA4;
    sp138 = spA0;
    sp84 = temp_f27_2339;
    sp9C = arg1.unk4 + sp13C;
    sp98 = temp_f4_2340 + sp138;
    sp144 = sp9C;
    sp140 = sp98;
    sp120 = sp80;
    sp124 = sp84;
    if (temp_f29_2342 > 0.0f) {
        var_f4_2372 = arg8;
    } else {
        var_f4_2372 = -arg8;
    }
    temp_f23_2381 = sp140 + temp_f3_2346;
    sp94 = sp144;
    sp12C = sp94;
    sp90 = (0.25f * var_f4_2372) + temp_f23_2381;
    sp128 = sp90;
    sp8C = arg0.unk4 + sp12C;
    sp88 = arg0.unk0 + sp128;
    sp134 = sp8C;
    sp130 = sp88;
    Hud_DrawIcon(0, 5, *((MKVector2 *) &sp130), *((MKVector2 *) &sp120), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
    sp68 = temp_f27_2339;
    temp_f31_2415 = sp144 + temp_f27_2339;
    sp6C = temp_f27_2339;
    sp108 = sp68;
    sp10C = sp6C;
    if (temp_f29_2342 > 0.0f) {
        var_f0_2426 = arg8;
    } else {
        var_f0_2426 = -arg8;
    }
    sp7C = temp_f31_2415;
    sp78 = (0.25f * var_f0_2426) + temp_f23_2381;
    sp114 = sp7C;
    sp110 = sp78;
    sp70 = arg0.unk0 + sp110;
    sp74 = arg0.unk4 + sp114;
    sp118 = sp70;
    sp11C = sp74;
    Hud_DrawIcon(0, 6, *((MKVector2 *) &sp118), *((MKVector2 *) &sp108), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
    if (arg_sp8 != 0) {
        sp50 = temp_f27_2339;
        sp54 = temp_f27_2339;
        spF0 = sp50;
        spF4 = sp54;
        if (temp_f29_2342 > 0.0f) {
            var_f2_2478 = -arg8;
        } else {
            var_f2_2478 = arg8;
        }
        sp64 = sp144;
        sp60 = (0.25f * var_f2_2478) + arg1.unk0;
        spFC = sp64;
        spF8 = sp60;
        sp5C = arg0.unk4 + spFC;
        sp58 = arg0.unk0 + spF8;
        sp104 = sp5C;
        sp100 = sp58;
        Hud_DrawIcon(0, 4, *((MKVector2 *) &sp100), *((MKVector2 *) &spF0), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
        sp38 = temp_f27_2339;
        sp3C = temp_f27_2339;
        spD8 = sp38;
        spDC = sp3C;
        if (temp_f29_2342 > 0.0f) {
            var_f2_2529 = -arg8;
        } else {
            var_f2_2529 = arg8;
        }
        sp4C = temp_f31_2415;
        sp48 = (0.25f * var_f2_2529) + arg1.unk0;
        spE4 = sp4C;
        spE0 = sp48;
        sp44 = arg0.unk4 + spE4;
        sp40 = arg0.unk0 + spE0;
        spEC = sp44;
        spE8 = sp40;
        Hud_DrawIcon(0, 7, *((MKVector2 *) &spE8), *((MKVector2 *) &spD8), arg5, 0.0f, 0.0f, 1.0f, 1.0f, (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0U, Matrix::identity);
    }
    sp28 = temp_f29_2342;
    sp2C = temp_f27_2339;
    sp30 = arg0.unk0 + sp140;
    sp34 = arg0.unk4 + sp144;
    spC8 = sp28;
    spCC = sp2C;
    spD0 = sp30;
    spD4 = sp34;
    Hud_DrawIcon(0, 9, *((MKVector2 *) &spD0), *((MKVector2 *) &spC8), arg5, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    sp1C = temp_f27_2339;
    sp18 = 0.0f;
    sp20 = arg0.unk0 + sp140;
    sp24 = arg0.unk4 + sp144;
    spB0 = sp18;
    spB4 = sp1C;
    spB8 = sp20;
    spBC = sp24;
    sp8 = temp_f29_2342;
    spC = temp_f27_2339;
    sp10 = spB8 + spB0;
    sp14 = spBC + spB4;
    spA8 = sp8;
    spAC = spC;
    spC0 = sp10;
    spC4 = sp14;
    Hud_DrawIcon(0, 0xA, *((MKVector2 *) &spC0), *((MKVector2 *) &spA8), arg5, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 SpyroHud_Update(void *arg0) {
    f32 temp_f1_2769;
    f32 temp_f2_2772;
    f32 temp_f3_2770;
    f32 var_f0_2777;
    f32 var_f0_2782;
    f32 var_f0_2801;
    f32 var_f0_2806;
    s32 var_r3_2829;

    if ((*M2C_FIELD(arg0, s32 **, 0) & 1) && (GameData::gameData.unk78 != GameData::gameData.unk70)) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) ((Stat *) &GameData::gameData.unk70))->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 2) && (GameData::gameData.unkA8 != GameData::gameData.unkA0)) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) ((Stat *) &GameData::gameData.unkA0))->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 4) && (GameData::gameData.unk90 != GameData::gameData.unk88)) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) ((Stat *) &GameData::gameData.unk88))->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 8) && (GameData::gameData.unkC0 != GameData::gameData.unkB8)) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        ((Stat *) ((Stat *) &GameData::gameData.unkB8))->AdjustPrevious(gUpdateTimeDelta / 3.0f);
    }
    if ((*M2C_FIELD(arg0, s32 **, 0) & 0x10) && (M2C_FIELD(arg0, f32 *, 0x2C) != M2C_FIELD(arg0, f32 *, 0x28))) {
        M2C_FIELD(arg0, f32 *, 4) = 2.0f;
        temp_f1_2769 = M2C_FIELD(arg0, f32 *, 0x28);
        temp_f3_2770 = M2C_FIELD(arg0, f32 *, 0x2C);
        temp_f2_2772 = M2C_FIELD(arg0, f32 *, 0x30) * (gUpdateTimeDelta / 3.0f);
        if (temp_f1_2769 < temp_f3_2770) {
            if (temp_f2_2772 < 0.0f) {
                var_f0_2777 = -temp_f2_2772;
            } else {
                var_f0_2777 = temp_f2_2772;
            }
            var_f0_2782 = temp_f1_2769 + var_f0_2777;
            if (var_f0_2782 < temp_f3_2770) {

            } else {
                var_f0_2782 = temp_f3_2770;
            }
            if (var_f0_2782 > temp_f1_2769) {

            } else {
                var_f0_2782 = temp_f1_2769;
            }
            M2C_FIELD(arg0, f32 *, 0x28) = var_f0_2782;
        } else {
            if (temp_f2_2772 < 0.0f) {
                var_f0_2801 = -temp_f2_2772;
            } else {
                var_f0_2801 = temp_f2_2772;
            }
            var_f0_2806 = temp_f1_2769 - var_f0_2801;
            if (var_f0_2806 < temp_f1_2769) {

            } else {
                var_f0_2806 = temp_f1_2769;
            }
            if (var_f0_2806 > temp_f3_2770) {

            } else {
                var_f0_2806 = temp_f3_2770;
            }
            M2C_FIELD(arg0, f32 *, 0x28) = var_f0_2806;
        }
    }
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) - gUpdateTimeDelta);
    var_r3_2829 = 0;
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1);
    if (((u8) M2C_FIELD(arg0, u8 *, 0x34) != 0) || ((u32) M2C_FIELD(&gb, u32 *, 0x360) != 0U)) {
        var_r3_2829 = 1;
    }
    return var_r3_2829;
}
#endif

#if 0 // DRAFT: '(' expected
void SpyroHud_cpp::__sinit() {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
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
    void *temp_r11_2867;
    void *temp_r8_2869;

    __construct_array(&hudData, &HudData::HudData, 0, 0x38, 2);
    temp_r11_2867 = &HUD_BAR_BACKGROUND + 0x10;
    temp_r8_2869 = &HUD_BAR_BACKGROUND + 0x60;
    sp20 = 50.0f;
    sp24 = 0.0f;
    sp18 = 100.0f;
    sp1C = 0.0f;
    sp10 = 150.0f;
    sp14 = 0.0f;
    sp8 = 300.0f;
    spC = 0.0f;
    sp78 = 0.35f;
    sp7C = 0.35f;
    sp80 = 0.35f;
    sp84 = 1.0f;
    sp68 = 1.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp58 = 1.0f;
    sp5C = 0.45f;
    sp60 = 0.0f;
    sp64 = 1.0f;
    sp48 = 1.0f;
    sp4C = 1.0f;
    sp50 = 0.0f;
    sp54 = 1.0f;
    sp38 = 0.0f;
    sp3C = 1.0f;
    sp40 = 0.0f;
    sp44 = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 1.0f;
    sp34 = 1.0f;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 0) = (f64) sp78;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 8) = (f64) sp80;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 0x10) = (f64) sp68;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f64 *, 0x18) = (f64) sp70;
    M2C_FIELD(temp_r11_2867, f64 *, 0x10) = (f64) sp58;
    M2C_FIELD(temp_r11_2867, f64 *, 0x18) = (f64) sp60;
    M2C_FIELD(temp_r11_2867, f64 *, 0x20) = (f64) sp48;
    M2C_FIELD(temp_r11_2867, f64 *, 0x28) = (f64) sp50;
    M2C_FIELD(temp_r11_2867, f64 *, 0x30) = (f64) sp38;
    M2C_FIELD(temp_r11_2867, f64 *, 0x38) = (f64) sp40;
    M2C_FIELD(temp_r11_2867, f64 *, 0x40) = (f64) sp28;
    M2C_FIELD(temp_r11_2867, f64 *, 0x48) = (f64) sp30;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f32 *, 0x60) = sp20;
    M2C_FIELD(&HUD_BAR_BACKGROUND, f32 *, 0x64) = sp24;
    M2C_FIELD(temp_r8_2869, f32 *, 8) = sp18;
    M2C_FIELD(temp_r8_2869, f32 *, 0xC) = sp1C;
    M2C_FIELD(temp_r8_2869, f32 *, 0x10) = sp10;
    M2C_FIELD(temp_r8_2869, f32 *, 0x14) = sp14;
    M2C_FIELD(temp_r8_2869, f32 *, 0x18) = sp8;
    M2C_FIELD(temp_r8_2869, f32 *, 0x1C) = spC;
}
#endif

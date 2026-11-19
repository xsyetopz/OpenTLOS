#include "spyro/source/LevelUpScreen.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CutsceneEvent.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/GameData.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIScreen.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Hud.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

extern s8 DialogBox_bAllowOverCutscene;
extern s32 GS_LevelUPExpLP;
extern s32 GS_LevelUPFull;
extern s32 GS_LevelUpDrainexpLP;
extern DialogBoxContext *GS_LevelUpEarthLP;
extern DialogBoxContext *GS_LevelUpElecLP;
extern s32 GS_LevelUpEnd;
extern DialogBoxContext *GS_LevelUpFireLP;
extern DialogBoxContext *GS_LevelUpIceLP;
extern s32 GS_LevelUpStart;
extern s32 GS_MenuMoveThru;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern s32 gpTranslation_StringArray;
extern s32 *pContextFury;
extern f32 pulseRot;
extern s32 selectionAttack;
extern s32 selectionElement;
u8 descriptor__13LevelUpScreen[0x14];               /* unable to generate initializer: cannot parse lit_stringBase0 as integer */
static M2C_UNK bars;                                /* unable to generate initializer: unknown type */
static M2C_UNK colors;                              /* unable to generate initializer: unknown type */
static f32 pulseRate = 4.0f;
static f32 pulseMag = 0.025f;
static s32 lit_629 = 2;
static s32 lit_638 = 2;
#if 0 // DRAFT: undefined identifier 'GetBreathAttackName'
static s32 pointsPerUpgrade[4] = { 0, 0x43C80000, 0x44480000, 0x44C80000 }; /* const */
static s32 attackMasks[2] = { 1, 2 };               /* const */

void LevelUpScreen::SetBreathText() {
    DialogBoxContext *temp_r3_85;
    DialogBoxContext *temp_r3_89;
    DialogBoxContext *temp_r4_57;
    MKModel *temp_r3_45;
    MKModel *temp_r4_17;
    u32 temp_r30_18;
    u32 temp_r30_58;

    temp_r4_17 = this->unkC8.unk70;
    temp_r30_18 = GetBreathAttackName();
    if ((temp_r4_17 == NULL) || (temp_r30_18 != M2C_BITWISE(u32, temp_r4_17->unk10.unk20))) {
        DialogBox_ReleaseContext((DialogBoxContext *) temp_r4_17);
        if (temp_r30_18 != 0) {
            this->unkC8.unk70 = DialogBox_InitContext();
            this->unkC8.unk70->unk0 = M2C_FIELD(&gb, void **, 0x324);
            this->unkC8.unk70->unk10.unk0 = 200.0f;
            this->unkC8.unk70->unk10.unk4 = 38.399994f;
            temp_r3_45 = this->unkC8.unk70;
            temp_r3_45->unk10.unk8 = 592.0f - temp_r3_45->unk10.unk0;
            this->unkC8.unk70->unk10.unkC = 64.0f;
            this->unkC8.unk70->unk10.unk20 = M2C_BITWISE(f32, temp_r30_18);
            this->unkC8.unk70->unkC = 0xC;
        }
    }
    temp_r4_57 = this->unkC8.unk74;
    temp_r30_58 = GetBreathAttackDesc();
    if ((temp_r4_57 == NULL) || (temp_r30_58 != (s8 *) temp_r4_57->unk30)) {
        DialogBox_ReleaseContext(temp_r4_57);
        if (temp_r30_58 != 0) {
            this->unkC8.unk74 = DialogBox_InitContext();
            this->unkC8.unk74->unk0 = (s32) M2C_FIELD(&gb, void **, 0x324);
            this->unkC8.unk74->unk10 = 376.0f;
            this->unkC8.unk74->unk14 = 124.0f;
            temp_r3_85 = this->unkC8.unk74;
            temp_r3_85->unk18 = 592.0f - temp_r3_85->unk10;
            temp_r3_89 = this->unkC8.unk74;
            temp_r3_89->unk1C = 428.0f - temp_r3_89->unk14;
            this->unkC8.unk74->unk30 = (s8 *) temp_r30_58;
            this->unkC8.unk74->unkC = 0xC;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'HasAttack'
void LevelUpScreen::Draw(const RenderContext &arg0) {
    Matrix spA0;
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
    M2C_UNK *temp_r23_192;
    f32 temp_f28_441;
    f32 temp_f28_458;
    f32 temp_f28_563;
    f32 temp_f28_580;
    f32 temp_f2_374;
    f32 temp_f2_496;
    f32 temp_f3_166;
    f32 temp_f3_312;
    f32 temp_f3_372;
    f32 temp_f3_494;
    f32 temp_f4_310;
    f32 temp_f4_433;
    f32 temp_f4_555;
    f32 temp_f5_431;
    f32 temp_f5_553;
    f32 var_f1_149;
    f32 var_f2_211;
    s32 var_r0_224;
    s32 var_r0_247;
    s32 var_r14_357;
    s32 var_r14_479;
    s32 var_r17_200;
    s32 var_r18_190;
    s32 var_r19_179;
    s32 var_r19_293;
    s32 var_r19_355;
    s32 var_r19_477;
    s32 var_r26_203;
    s32 var_r27_202;
    s32 var_r28_195;
    s32 var_r29_194;
    s32 var_r30_181;
    s32 var_r31_180;
    u8 *temp_r20_187;
    u8 var_r3_214;
    u8 var_r3_237;

    sp38 = 48.0f;
    sp3C = 386.0f;
    sp90 = sp38;
    sp94 = sp3C;
    if ((s32 *) pContextFury == NULL) {
        DialogBox_Draw();
    }
    spA0.SetIdentity();
    spA0.SetRotationRoll(this->unk148);
    var_f1_149 = M2C_FIELD(GameData::gameData, f32 *, 0x88);
    if (var_f1_149 < 800.0f) {

    } else {
        var_f1_149 = 800.0f;
    }
    temp_f3_166 = 230.0f * (var_f1_149 / 800.0f);
    Hud_DrawIcon(0, 0xE, sp90, sp94, temp_f3_166, temp_f3_166, MKVector4::one, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, spA0);
    var_r19_179 = 0;
    var_r31_180 = 0;
    var_r30_181 = 0;
    do {
        temp_r20_187 = &(LevelUpScreen::descriptor + 0xE8)[var_r31_180];
        var_r18_190 = 0;
        temp_r23_192 = &M2C_FIELD(&(&GameData::gameData[0x70])[var_r30_181], M2C_UNK *, 0x64);
        var_r29_194 = 0;
        var_r28_195 = 0;
loop_7:
        var_r17_200 = 0;
        var_r27_202 = 0;
        var_r26_203 = 0;
loop_8:
        if (HasAttack(var_r19_179, var_r17_200) != 0) {
            var_f2_211 = 0.0f;
            if (var_r17_200 == 3) {
                var_r3_214 = 0;
                if (((s32) M2C_FIELD(&(&GameData::gameData[0x70])[var_r30_181], s32 *, 0x64) == 3) && ((s32) M2C_FIELD(&(&GameData::gameData[0x70])[var_r30_181], s32 *, 0x68) == 3)) {
                    var_r3_214 = 1;
                }
                var_r0_224 = var_r3_214 != 0;
            } else {
                var_r0_224 = *(temp_r23_192 + var_r26_203);
            }
            if (var_r0_224 > var_r18_190) {
                var_f2_211 = 1.0f;
            } else {
                if (var_r17_200 == 3) {
                    var_r3_237 = 0;
                    if (((s32) M2C_FIELD(&(&GameData::gameData[0x70])[var_r30_181], s32 *, 0x64) == 3) && ((s32) M2C_FIELD(&(&GameData::gameData[0x70])[var_r30_181], s32 *, 0x68) == 3)) {
                        var_r3_237 = 1;
                    }
                    var_r0_247 = var_r3_237 != 0;
                } else {
                    var_r0_247 = *(temp_r23_192 + var_r26_203);
                }
                if (var_r18_190 == var_r0_247) {
                    var_f2_211 = (&(&GameData::gameData[0x70])[var_r26_203] + 0x70)[var_r30_181] / M2C_FIELD((pointsPerUpgrade + var_r28_195), f32 *, 4);
                }
            }
            DrawUpgradeBar((UpgradeBar *) &(LevelUpScreen::descriptor + 0x24)[var_r27_202 + var_r29_194], *((MKVector2 *) &sp90), -0.3926991f * (f32) var_r19_179, *((MKVector4 *) temp_r20_187), *(MKVector4 *) (temp_r20_187 + 0x10), var_f2_211);
        }
        var_r17_200 += 1;
        var_r26_203 += 4;
        var_r27_202 += 0x60;
        if (var_r17_200 < 2) {
            goto loop_8;
        }
        var_r18_190 += 1;
        var_r28_195 += 4;
        var_r29_194 += 0x20;
        if (var_r18_190 < 3) {
            goto loop_7;
        }
        var_r19_179 += 1;
        var_r30_181 += 0x20;
        var_r31_180 += 0x30;
    } while (var_r19_179 < 4);
    spA0.SetIdentity();
    var_r19_293 = 0;
    do {
        _table_sincosf((-0.3926991f * (f32) (var_r19_293 + 1)) + -0.044f, sp88, sp8C);
        temp_f4_310 = sp88 * 194.0f;
        temp_f3_312 = sp8C * 194.0f;
        sp30 = sp90 - temp_f4_310;
        sp34 = sp94 - temp_f3_312;
        sp60 = sp30;
        sp64 = sp34;
        sp88 = temp_f4_310;
        sp8C = temp_f3_312;
        sp88 = sp60;
        sp8C = sp64;
        spA0.SetRotationRoll(-0.3926991f * (f32) var_r19_293);
        Hud_DrawIcon(0, 0xF, sp88, sp8C, 124.0f, 72.0f, MKVector4::one, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, spA0);
        var_r19_293 += 1;
    } while (var_r19_293 < 4);
    var_r19_355 = 0;
    var_r14_357 = 0;
    do {
        _table_sincosf(-0.3926991f * (f32) (var_r19_355 + 1), sp80, sp84);
        temp_f3_372 = sp80 * 276.0f;
        temp_f2_374 = sp84 * 276.0f;
        sp80 = temp_f3_372;
        sp28 = sp90 - temp_f3_372;
        sp2C = sp94 - temp_f2_374;
        sp58 = sp28;
        sp5C = sp2C;
        sp84 = temp_f2_374;
        sp80 = sp58;
        sp84 = sp5C;
        if (((s32) selectionAttack != 0) || (var_r19_355 != (s32) selectionElement)) {
            DrawBreathIcon(sp80, sp84, 1.0f, (LevelUpScreen::descriptor + 0x14)[var_r14_357], 0, MKVector4::one);
        }
        var_r19_355 += 1;
        var_r14_357 += 4;
    } while (var_r19_355 < 4);
    if ((s32) selectionAttack == 0) {
        _table_sincosf(-0.3926991f * (f32) (selectionElement + 1), sp78, sp7C);
        temp_f5_431 = sp78 * 276.0f;
        temp_f4_433 = sp7C * 276.0f;
        sp78 = temp_f5_431;
        temp_f28_441 = pulseMag;
        sp20 = sp90 - temp_f5_431;
        sp24 = sp94 - temp_f4_433;
        sp50 = sp20;
        sp54 = sp24;
        sp7C = temp_f4_433;
        sp78 = sp50;
        sp7C = sp54;
        temp_f28_458 = 1.0f + ((temp_f28_441 * _table_sinf(pulseRot * pulseRate)) + temp_f28_441);
        DrawBreathSelection(sp78, sp7C, 0.9f * temp_f28_458, 1.0f);
        DrawBreathIcon(sp78, sp7C, temp_f28_458, *(LevelUpScreen::descriptor + 0x14 + (selectionElement * 4)), 0, MKVector4::one);
    }
    var_r19_477 = 0;
    var_r14_479 = 0;
    do {
        _table_sincosf(-0.3926991f * (f32) (var_r19_477 + 1), sp70, sp74);
        temp_f3_494 = sp70 * 150.0f;
        temp_f2_496 = sp74 * 150.0f;
        sp70 = temp_f3_494;
        sp18 = sp90 - temp_f3_494;
        sp1C = sp94 - temp_f2_496;
        sp48 = sp18;
        sp4C = sp1C;
        sp74 = temp_f2_496;
        sp70 = sp48;
        sp74 = sp4C;
        if (((s32) selectionAttack != 1) || (var_r19_477 != (s32) selectionElement)) {
            DrawBreathIcon(sp70, sp74, 0.55f, (LevelUpScreen::descriptor + 0x14)[var_r14_479], 1, MKVector4::one);
        }
        var_r19_477 += 1;
        var_r14_479 += 4;
    } while (var_r19_477 < 4);
    if ((s32) selectionAttack == 1) {
        _table_sincosf(-0.3926991f * (f32) (selectionElement + 1), sp68, sp6C);
        temp_f5_553 = sp68 * 150.0f;
        temp_f4_555 = sp6C * 150.0f;
        sp68 = temp_f5_553;
        temp_f28_563 = pulseMag;
        sp10 = sp90 - temp_f5_553;
        sp14 = sp94 - temp_f4_555;
        sp40 = sp10;
        sp44 = sp14;
        sp6C = temp_f4_555;
        sp68 = sp40;
        sp6C = sp44;
        temp_f28_580 = 1.0f + ((temp_f28_563 * _table_sinf(pulseRot * pulseRate)) + temp_f28_563);
        DrawBreathSelection(sp68, sp6C, 0.5f * temp_f28_580, 1.0f);
        DrawBreathIcon(sp68, sp6C, 0.55f * temp_f28_580, *(LevelUpScreen::descriptor + 0x14 + (selectionElement * 4)), 1, MKVector4::one);
    }
    UIContainer::Draw(arg0);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void DrawUpgradeBar(UpgradeBar *arg0, const MKVector2 &arg1, float arg2, const MKVector4 &arg3, const MKVector4 &arg4, float arg5) {
    Matrix sp90;
    M2C_UNK sp8C;
    f64 sp88;
    f64 sp80;
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
    f32 temp_f4_662;
    f32 temp_f5_664;
    f32 temp_f6_667;
    f32 temp_f7_672;

    M2C_STRUCT_COPY((s32) &sp8C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp90.SetRotationRoll(arg2);
    sp70 = arg1.unk0;
    sp74 = arg1.unk4;
    sp78 = 0.0f;
    sp80 = (f64) sp70;
    sp88 = (f64) sp78;
    sp90.Translate(&sp90, *((MKVector3 *) &sp80));
    temp_f4_662 = arg0->unk0;
    temp_f5_664 = arg0->unk4;
    temp_f6_667 = arg0->unk8;
    sp38 = arg0->unk10 - temp_f4_662;
    temp_f7_672 = arg0->unkC;
    sp3C = arg0->unk14 - temp_f5_664;
    sp20 = arg0->unk18 - temp_f6_667;
    sp24 = arg0->unk1C - temp_f7_672;
    sp50 = sp38;
    sp54 = sp3C;
    sp40 = sp20;
    sp44 = sp24;
    sp30 = sp50 * arg5;
    sp34 = sp54 * arg5;
    sp18 = sp40 * arg5;
    sp1C = sp44 * arg5;
    sp58 = sp30;
    sp5C = sp34;
    sp48 = sp18;
    sp4C = sp1C;
    sp28 = temp_f4_662 + sp58;
    sp2C = temp_f5_664 + sp5C;
    sp10 = temp_f6_667 + sp48;
    sp14 = temp_f7_672 + sp4C;
    sp68 = sp28;
    sp6C = sp2C;
    sp60 = sp10;
    sp64 = sp14;
    if (arg5 > 0.0f) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0x10C, 3);
        MKSetMatrix(sp90);
        MKBegin(4);
        MKSetColorV(arg3);
        MKSetPositionF(arg0->unk0, arg0->unk4, 0.0f);
        MKSetPositionF(sp68, sp6C, 0.0f);
        MKSetPositionF(arg0->unk8, arg0->unkC, 0.0f);
        MKSetPositionF(sp60, sp64, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
    if (arg5 < 1.0f) {
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKPrimitive(0x10C, 3);
        MKSetMatrix(sp90);
        MKBegin(4);
        MKSetColorV(arg4);
        MKSetPositionF(sp68, sp6C, 0.0f);
        MKSetPositionF(arg0->unk10, arg0->unk14, 0.0f);
        MKSetPositionF(sp60, sp64, 0.0f);
        MKSetPositionF(arg0->unk18, arg0->unk1C, 0.0f);
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'HasAttack'
void DrawBreathIcon(float arg0, float arg1, float arg2, int arg3, int arg4, const MKVector4 &arg5) {
    f64 sp10;
    f64 sp8;
    f32 temp_f3_848;
    f32 temp_f3_865;

    sp8 = M2C_FIELD(&arg5, f64 *, 0);
    sp10 = M2C_FIELD(&arg5, f64 *, 8);
    if (HasAttack(arg3, arg4) == 0) {
        sp8 *= 5.2013764e-315;
        sp10 *= 5.2013764e-315;
        unksp14 = arg5.unkC;
    }
    temp_f3_848 = 73.0f * arg2;
    Hud_DrawIcon(arg3, arg4, arg0 + arg2, arg1, temp_f3_848, temp_f3_848, *((MKVector4 *) &sp8), 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
    temp_f3_865 = 106.0f * arg2;
    Hud_DrawIcon(arg3, 3, arg0, arg1, temp_f3_865, temp_f3_865, arg5, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, Matrix::identity);
}
#endif

void DrawBreathSelection(float arg0, float arg1, float arg2, float arg3) {
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
    f32 temp_f3_917;
    f32 temp_f5_915;

    if (arg3 > 0.0f) {
        sp30 = 1.0f;
        sp34 = 0.3f;
        sp38 = 1.0f;
        temp_f5_915 = 56.0f * arg2;
        sp3C = arg3;
        temp_f3_917 = 72.0f * arg2;
        sp20 = 1.0f;
        sp24 = 0.3f;
        sp28 = 1.0f;
        sp2C = 0.0f;
        sp8 = 6.2831855f;
        spC = 6.2831855f;
        sp10 = 0.0f;
        sp14 = 0.0f;
        sp18 = 1.0f;
        sp1C = 1.0f;
        Hud_DrawArc(arg0, arg1, temp_f3_917, temp_f3_917, temp_f5_915, temp_f5_915, 0.0f, 0.0f, 0.3f, 1.0f, (MKVector4 *) &sp20, (MKVector4 *) &sp30, NULL, NULL, M2C_ERROR(/* Read from unset register $f11 */), M2C_ERROR(/* Read from unset register $f12 */), M2C_ERROR(/* Read from unset register $f13 */), M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
}

#if 0 // DRAFT: expression syntax error
void LevelUpScreen::Update() {
    s32 sp8;
    f32 temp_f1_1161;
    f32 temp_f2_1158;
    f32 temp_f31_1114;
    f32 var_f29_1160;
    f32 var_f30_1149;
    s32 *temp_r3_1243;
    s32 temp_cr0_lt_1142;
    s32 temp_r0_1209;
    s32 temp_r6_1147;
    s32 temp_r7_1121;
    s32 var_r0_1038;
    s32 var_r0_1201;
    s32 var_r0_1223;
    s32 var_r5_1136;
    u8 var_r28_1052;
    u8 var_r3_1003;
    u8 var_r3_1028;
    u8 var_r3_1126;
    u8 var_r3_1213;
    u8 var_r4_1182;
    void *temp_r4_1025;
    void *temp_r4_1123;
    void *temp_r4_1148;
    void *temp_r6_1189;

    if ((s32 *) pContextFury == NULL) {
        UIScreen::Update();
        sp8 = 1;
        this->unkBC.unk4.Update(GS_LevelUPExpLP, 0U, ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1, NULL, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        switch ((s32) selectionElement) {           /* irregular */
        case 0:
            this->unk140 = GS_LevelUpFireLP;
            break;
        case 1:
            this->unk140 = GS_LevelUpElecLP;
            break;
        case 2:
            this->unk140 = GS_LevelUpIceLP;
            break;
        case 3:
            this->unk140 = GS_LevelUpEarthLP;
            break;
        }
        var_r3_1003 = M2C_FIELD(this, u8 *, 0x154);
        if (var_r3_1003 != 0) {
            var_r3_1003 = UIControls_Held((FrontEndControls) 0xE, -1);
        }
        if (var_r3_1003 != 0) {
            var_r3_1003 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        }
        if (var_r3_1003 != 0) {
            temp_r4_1025 = &GameData::gameData[0x70] + ((selectionElement << 5) + 0x64);
            if ((s32) selectionAttack == 3) {
                var_r3_1028 = 0;
                if (((s32) M2C_FIELD(temp_r4_1025, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1025, s32 *, 4) == 3)) {
                    var_r3_1028 = 1;
                }
                var_r0_1038 = var_r3_1028 != 0;
            } else {
                var_r0_1038 = *(temp_r4_1025 + (selectionAttack * 4));
            }
            var_r3_1003 = var_r0_1038 < 3;
        }
        var_r28_1052 = var_r3_1003;
        if (var_r3_1003 != 0) {
            var_r28_1052 = HasAttack(selectionElement, selectionAttack);
        }
        if ((DialogBoxContext *) this->unk144 != (DialogBoxContext *) this->unk140) {
            KDSound_Stop((s32 *) &this->unkC8.unkC.unk14);
        }
        this->unk144 = this->unk140;
        sp8 = 1;
        this->unkC8.unkC.unk14.Update((s32) this->unk140, 0U, var_r28_1052, NULL, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        sp8 = 1;
        this->unkC8.unk48.Update(GS_LevelUpDrainexpLP, 0U, var_r28_1052, NULL, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
        if (((u8) M2C_FIELD(this, u8 *, 0x156) == 0) && (var_r28_1052 != 0)) {
            KDSound_Play(GS_LevelUpStart, 0U, -1);
        }
        M2C_FIELD(this, u8 *, 0x156) = var_r28_1052;
        if (((u8) M2C_FIELD(this, u8 *, 0x154) != 0) && (UIControls_Held((FrontEndControls) 0xE, -1) != 0) && (HasAttack(selectionElement, selectionAttack) != 0)) {
            temp_f31_1114 = M2C_FIELD(GameData::gameData, f32 *, 0x88);
            if (temp_f31_1114 > 0.0f) {
                temp_r7_1121 = selectionElement << 5;
                temp_r4_1123 = &GameData::gameData[0x70] + (temp_r7_1121 + 0x64);
                if ((s32) selectionAttack == 3) {
                    var_r3_1126 = 0;
                    if (((s32) M2C_FIELD(temp_r4_1123, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1123, s32 *, 4) == 3)) {
                        var_r3_1126 = 1;
                    }
                    var_r5_1136 = var_r3_1126 != 0;
                } else {
                    var_r5_1136 = *(temp_r4_1123 + (selectionAttack * 4));
                }
                temp_cr0_lt_1142 = var_r5_1136 < 3;
                if (temp_cr0_lt_1142 != 0) {
                    temp_r6_1147 = selectionAttack * 4;
                    temp_r4_1148 = &GameData::gameData[0x70] + temp_r7_1121 + 0x70;
                    var_f30_1149 = 100.0f * gUpdateTimeDelta;
                    if (var_f30_1149 > temp_f31_1114) {
                        var_f30_1149 = temp_f31_1114;
                    }
                    temp_f2_1158 = *(temp_r4_1148 + temp_r6_1147) + var_f30_1149;
                    var_f29_1160 = 0.0f;
                    temp_f1_1161 = M2C_FIELD(&pointsPerUpgrade[var_r5_1136], f32 *, 4);
                    if (temp_f2_1158 >= temp_f1_1161) {
                        M2C_FIELD((&GameData::gameData[0x70] + temp_r7_1121 + temp_r6_1147), s32 *, 0x64) = (s32) (var_r5_1136 + 1);
                        var_f29_1160 = temp_f2_1158 - temp_f1_1161;
                        M2C_FIELD((&GameData::gameData[0x70] + (selectionElement << 5) + (selectionAttack * 4)), f32 *, 0x70) = 0.0f;
                        KDSound_Play(GS_LevelUPFull, 0U, -1);
                        var_r4_1182 = 0;
                        M2C_FIELD(this, u8 *, 0x154) = 0U;
                        temp_r6_1189 = &GameData::gameData[0x70] + ((selectionElement << 5) + 0x64);
                        if ((s32) selectionAttack == 3) {
                            if (((s32) M2C_FIELD(temp_r6_1189, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r6_1189, s32 *, 4) == 3)) {
                                var_r4_1182 = 1;
                            }
                            var_r0_1201 = var_r4_1182 != 0;
                        } else {
                            var_r0_1201 = *(temp_r6_1189 + (selectionAttack * 4));
                        }
                        if (var_r0_1201 == 3) {
                            temp_r0_1209 = 1 - selectionAttack;
                            if (temp_r0_1209 == 3) {
                                var_r3_1213 = 0;
                                if (((s32) M2C_FIELD(temp_r6_1189, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r6_1189, s32 *, 4) == 3)) {
                                    var_r3_1213 = 1;
                                }
                                var_r0_1223 = var_r3_1213 != 0;
                            } else {
                                var_r0_1223 = *(temp_r6_1189 + (temp_r0_1209 * 4));
                            }
                            if (var_r0_1223 == 3) {
                                KDSound_Stop((s32 *) &this->unkC8.unkC.unk14);
                                KDSound_Stop((s32 *) &this->unkC8.unk48);
                                DialogBox_ReleaseContext((DialogBoxContext *) this->unkC8.unk70);
                                this->unkC8.unk70 = NULL;
                                DialogBox_ReleaseContext(this->unkC8.unk74);
                                this->unkC8.unk74 = NULL;
                                temp_r3_1243 = DialogBox_InitContext();
                                pContextFury = temp_r3_1243;
                                *temp_r3_1243 = M2C_FIELD(&gb, s32 *, 0x324);
                                M2C_FIELD(pContextFury, LevelUpScreen **, 8) = this;
                                M2C_FIELD(pContextFury, f32 *, 0x18) = 512.0f;
                                M2C_FIELD(pContextFury, f32 *, 0x1C) = 128.0f;
                                M2C_FIELD(pContextFury, f32 *, 0x10) = (f32) (0.5f * (640.0f - M2C_FIELD(pContextFury, f32 *, 0x18)));
                                M2C_FIELD(pContextFury, f32 *, 0x14) = (f32) (0.5f * (512.0f - M2C_FIELD(pContextFury, f32 *, 0x1C)));
                                M2C_FIELD(pContextFury, s32 *, 0x30) = (s32) M2C_FIELD((gpTranslation_StringArray + (selectionElement * 4)), s32 *, 0xA24);
                                M2C_FIELD(pContextFury, void (**)(DialogBoxContext *, s32), 0x6C) = DialogCallback;
                                M2C_FIELD(pContextFury, s32 *, 0xC) = 0x1C;
                                PauseMenu_AllowStartToQuit(M2C_FIELD(this, u8 *, 0x154));
                            } else {
                                goto block_60;
                            }
                        } else {
block_60:
                            SetBreathText();
                        }
                    } else {
                        *(temp_r4_1148 + temp_r6_1147) = temp_f2_1158;
                    }
                    ((Stat *) ((Stat *) (&GameData::gameData[0x70] + 0x18)))->SetValue(var_f29_1160 + (temp_f31_1114 - var_f30_1149), 0U);
                } else if ((temp_cr0_lt_1142 == 0) && ((u8) M2C_FIELD(this, u8 *, 0x155) != 0)) {
                    M2C_FIELD(this, u8 *, 0x155) = 0U;
                    KDSound_Play(GS_LevelUpEnd, 0U, -1);
                }
            } else {
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if ((temp_f31_1114 == 0.0f) && ((u8) M2C_FIELD(this, u8 *, 0x155) != 0)) {
                    M2C_FIELD(this, u8 *, 0x155) = 0U;
                    KDSound_Play(GS_LevelUpEnd, 0U, -1);
                }
            }
        } else if (UIControls_Pressed((FrontEndControls) 4, -1) != 0) {
            selectionElement = (selectionElement - 1) & 3;
            KDSound_Play(GS_MenuMoveThru, 0U, -1);
            M2C_FIELD(this, u8 *, 0x155) = 1U;
            pulseRot = 0.0f;
            SetBreathText();
        } else if (UIControls_Pressed((FrontEndControls) 6, -1) != 0) {
            selectionElement = (selectionElement + 1) & 3;
            KDSound_Play(GS_MenuMoveThru, 0U, -1);
            M2C_FIELD(this, u8 *, 0x155) = 1U;
            pulseRot = 0.0f;
            SetBreathText();
        } else if (UIControls_Pressed((FrontEndControls) 7, -1) != 0) {
            selectionAttack = 1 - selectionAttack;
            KDSound_Play(GS_MenuMoveThru, 0U, -1);
            M2C_FIELD(this, u8 *, 0x155) = 1U;
            pulseRot = 0.0f;
            SetBreathText();
        } else if (UIControls_Pressed((FrontEndControls) 5, -1) != 0) {
            selectionAttack = 1 - selectionAttack;
            KDSound_Play(GS_MenuMoveThru, 0U, -1);
            M2C_FIELD(this, u8 *, 0x155) = 1U;
            pulseRot = 0.0f;
            SetBreathText();
        }
        if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
            M2C_FIELD(this, u8 *, 0x154) = 1U;
        }
        if ((UIControls_Pressed((FrontEndControls) 0xE, -1) == 0) && (UIControls_Held((FrontEndControls) 0xE, -1) == 0)) {
            M2C_FIELD(this, u8 *, 0x155) = 1U;
        }
        this->unk148 = KDMath_NormaliseAngle(this->unk148 + gUpdateTimeDelta);
        pulseRot = KDMath_NormaliseAngle(pulseRot + gUpdateTimeDelta);
    }
}
#endif

#if 0 // DRAFT: type mismatch
void DialogCallback(DialogBoxContext *arg0, int arg1) {
    if ((arg1 == 0) && ((s32 *) pContextFury == arg0)) {
        arg0->unk8->SetBreathText();
        DialogBox_ReleaseContext(arg0);
    } else if ((arg1 == 7) && ((s32 *) pContextFury == arg0)) {
        pContextFury = NULL;
    }
    PauseMenu_AllowStartToQuit(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk74'
void LevelUpScreen::OnExit() {
    UIScreen::OnExit();
    DialogBox_ReleaseContext(this->unkC8.unk74);
    DialogBox_ReleaseContext((DialogBoxContext *) this->unkC8.unk70);
    DialogBox_bAllowOverCutscene = 0;
    this->unkC8.unk74 = NULL;
    this->unkC8.unk70 = NULL;
    M2C_FIELD(this, s8 *, 0x155) = 1;
    M2C_FIELD(this, s8 *, 0x156) = 0;
    KDSound_Stop(&this->unkBC.unk4);
    KDSound_Stop((s32 *) &this->unkC8.unk48);
    KDSound_Stop((s32 *) &this->unkC8.unkC.unk14);
}
#endif

#if 0 // DRAFT: expression syntax error
void LevelUpScreen::OnEnter() {
    UIScreen::OnEnter();
    SetBreathText();
    this->unk148 = 0.0f;
    pulseRot = 0.0f;
    if ((void *) M2C_FIELD(&gb, void **, 0x354) != NULL) {
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s8 *, 5) = 1;
    }
    UIControls_Ignore(1U);
    M2C_FIELD(this, s8 *, 0x154) = 0;
    M2C_FIELD(this, s8 *, 0x155) = 1;
    M2C_FIELD(this, s8 *, 0x156) = 0;
    this->unkBC.unk4.Init(0.25f, 0.25f);
    this->unkC8.unk48.Init(0.25f, 0.25f);
    this->unkC8.unkC.unk14.Init(0.25f, 0.25f);
    DialogBox_bAllowOverCutscene = 1;
}
#endif

void LevelUpScreen::Deinit() {
    UIContainer::Deinit();
}

#if 0 // DRAFT: undefined identifier 'unk74'
void LevelUpScreen::Init() {
    UIContainer::Init();
    this->unkC8.unk74 = NULL;
    this->unkC8.unk70 = NULL;
    M2C_FIELD(this, s8 *, 0x155) = 1;
    M2C_FIELD(this, s8 *, 0x156) = 0;
    this->unk140 = GS_LevelUpFireLP;
    this->unk144 = this->unk140;
}
#endif

#if 0 // DRAFT: undefined identifier 'HasAttack'
u32 GetBreathAttackDesc() {
    s32 var_r5_1640;
    u8 var_r3_1630;
    void *temp_r3_1626;
    void *temp_r4_1627;

    if (HasAttack(selectionElement, selectionAttack) != 0) {
        temp_r3_1626 = GameData::gameData + (selectionElement << 5);
        temp_r4_1627 = temp_r3_1626 + 0xD4;
        if ((s32) selectionAttack == 3) {
            var_r3_1630 = 0;
            if (((s32) M2C_FIELD(temp_r3_1626, s32 *, 0xD4) == 3) && ((s32) M2C_FIELD(temp_r4_1627, s32 *, 4) == 3)) {
                var_r3_1630 = 1;
            }
            var_r5_1640 = var_r3_1630 != 0;
        } else {
            var_r5_1640 = *(temp_r4_1627 + (selectionAttack * 4));
        }
        if ((s32) lit_638 < var_r5_1640) {
            var_r5_1640 = lit_638;
        }
        return *(gpTranslation_StringArray + (((selectionElement * 6) + (selectionAttack * 3) + var_r5_1640 + 0x258) * 4));
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'HasAttack'
u32 GetBreathAttackName() {
    s32 var_r5_1700;
    u8 var_r3_1690;
    void *temp_r3_1686;
    void *temp_r4_1687;

    if (HasAttack(selectionElement, selectionAttack) != 0) {
        temp_r3_1686 = GameData::gameData + (selectionElement << 5);
        temp_r4_1687 = temp_r3_1686 + 0xD4;
        if ((s32) selectionAttack == 3) {
            var_r3_1690 = 0;
            if (((s32) M2C_FIELD(temp_r3_1686, s32 *, 0xD4) == 3) && ((s32) M2C_FIELD(temp_r4_1687, s32 *, 4) == 3)) {
                var_r3_1690 = 1;
            }
            var_r5_1700 = var_r3_1690 != 0;
        } else {
            var_r5_1700 = *(temp_r4_1687 + (selectionAttack * 4));
        }
        if ((s32) lit_629 < var_r5_1700) {
            var_r5_1700 = lit_629;
        }
        return *(gpTranslation_StringArray + (((selectionElement * 6) + (selectionAttack * 3) + var_r5_1700 + 0x271) * 4));
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'attackMasks'
u8 HasAttack(int arg0, int arg1) {
    return (attackMasks[arg1] & M2C_FIELD((GameData::gameData + (arg0 << 5)), s32 *, 0xD0)) != 0;
}
#endif

void LevelUpScreen_cpp::__sinit() {
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
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

    spC0 = 57.0f;
    spC4 = -235.0f;
    spB8 = 44.0f;
    spBC = -198.0f;
    spB0 = 82.0f;
    M2C_FIELD(&bars, f32 *, 0) = spC0;
    spB4 = -221.0f;
    spA8 = 68.0f;
    spAC = -192.0f;
    spA0 = 80.0f;
    spA4 = -211.0f;
    sp98 = 71.0f;
    sp9C = -192.0f;
    sp90 = 105.0f;
    sp94 = -204.0f;
    sp88 = 95.0f;
    sp8C = -181.0f;
    sp80 = 109.0f;
    sp84 = -207.0f;
    sp78 = 97.0f;
    sp7C = -180.0f;
    M2C_FIELD(&bars, f32 *, 4) = spC4;
    M2C_FIELD(&bars, f32 *, 8) = spB8;
    M2C_FIELD(&bars, f32 *, 0xC) = spBC;
    M2C_FIELD(&bars, f32 *, 0x10) = spB0;
    M2C_FIELD(&bars, f32 *, 0x14) = spB4;
    M2C_FIELD(&bars, f32 *, 0x18) = spA8;
    M2C_FIELD(&bars, f32 *, 0x1C) = spAC;
    M2C_FIELD(&bars, f32 *, 0x20) = spA0;
    M2C_FIELD(&bars, f32 *, 0x24) = spA4;
    M2C_FIELD(&bars, f32 *, 0x28) = sp98;
    M2C_FIELD(&bars, f32 *, 0x2C) = sp9C;
    M2C_FIELD(&bars, f32 *, 0x30) = sp90;
    M2C_FIELD(&bars, f32 *, 0x34) = sp94;
    M2C_FIELD(&bars, f32 *, 0x38) = sp88;
    M2C_FIELD(&bars, f32 *, 0x3C) = sp8C;
    M2C_FIELD(&bars, f32 *, 0x40) = sp80;
    M2C_FIELD(&bars, f32 *, 0x44) = sp84;
    M2C_FIELD(&bars, f32 *, 0x48) = sp78;
    M2C_FIELD(&bars, f32 *, 0x4C) = sp7C;
    sp70 = 147.0f;
    sp74 = -201.0f;
    sp68 = 118.0f;
    sp6C = -171.0f;
    sp60 = 49.0f;
    sp64 = -193.0f;
    sp58 = 26.0f;
    sp5C = -175.0f;
    sp50 = 66.0f;
    sp54 = -187.0f;
    sp48 = 37.0f;
    sp4C = -153.0f;
    sp40 = 68.0f;
    sp44 = -185.0f;
    sp38 = 52.0f;
    sp3C = -165.0f;
    sp30 = 86.0f;
    sp34 = -177.0f;
    sp28 = 74.0f;
    sp2C = -160.0f;
    M2C_FIELD(&bars, f32 *, 0x50) = sp70;
    M2C_FIELD(&bars, f32 *, 0x54) = sp74;
    M2C_FIELD(&bars, f32 *, 0x58) = sp68;
    M2C_FIELD(&bars, f32 *, 0x5C) = sp6C;
    M2C_FIELD(&bars, f32 *, 0x60) = sp60;
    M2C_FIELD(&bars, f32 *, 0x64) = sp64;
    M2C_FIELD(&bars, f32 *, 0x68) = sp58;
    M2C_FIELD(&bars, f32 *, 0x6C) = sp5C;
    M2C_FIELD(&bars, f32 *, 0x70) = sp50;
    M2C_FIELD(&bars, f32 *, 0x74) = sp54;
    M2C_FIELD(&bars, f32 *, 0x78) = sp48;
    M2C_FIELD(&bars, f32 *, 0x7C) = sp4C;
    M2C_FIELD(&bars, f32 *, 0x80) = sp40;
    M2C_FIELD(&bars, f32 *, 0x84) = sp44;
    M2C_FIELD(&bars, f32 *, 0x88) = sp38;
    M2C_FIELD(&bars, f32 *, 0x8C) = sp3C;
    M2C_FIELD(&bars, f32 *, 0x90) = sp30;
    M2C_FIELD(&bars, f32 *, 0x94) = sp34;
    M2C_FIELD(&bars, f32 *, 0x98) = sp28;
    M2C_FIELD(&bars, f32 *, 0x9C) = sp2C;
    sp20 = 88.0f;
    sp24 = -176.0f;
    sp18 = 77.0f;
    sp1C = -159.0f;
    sp10 = 112.0f;
    sp14 = -164.0f;
    sp8 = 84.0f;
    spC = -149.0f;
    sp178 = 0.973f;
    sp17C = 0.145f;
    sp180 = 0.361f;
    sp184 = 1.0f;
    sp168 = 0.498f;
    sp16C = 0.106f;
    M2C_FIELD(&colors, f64 *, 0) = (f64) sp178;
    sp170 = 0.239f;
    sp174 = 1.0f;
    sp158 = 0.0f;
    sp15C = 0.0f;
    sp160 = 0.0f;
    sp164 = 0.5f;
    sp148 = 1.0f;
    sp14C = 0.992f;
    sp150 = 0.243f;
    sp154 = 1.0f;
    sp138 = 0.835f;
    sp13C = 0.62f;
    sp140 = 0.063f;
    sp144 = 1.0f;
    M2C_FIELD(&bars, f32 *, 0xA0) = sp20;
    M2C_FIELD(&bars, f32 *, 0xA4) = sp24;
    M2C_FIELD(&bars, f32 *, 0xA8) = sp18;
    M2C_FIELD(&bars, f32 *, 0xAC) = sp1C;
    M2C_FIELD(&bars, f32 *, 0xB0) = sp10;
    M2C_FIELD(&bars, f32 *, 0xB4) = sp14;
    M2C_FIELD(&bars, f32 *, 0xB8) = sp8;
    M2C_FIELD(&bars, f32 *, 0xBC) = spC;
    M2C_FIELD(&colors, f64 *, 8) = (f64) sp180;
    M2C_FIELD(&colors, f64 *, 0x10) = (f64) sp168;
    M2C_FIELD(&colors, f64 *, 0x18) = (f64) sp170;
    M2C_FIELD(&colors, f64 *, 0x20) = (f64) sp158;
    M2C_FIELD(&colors, f64 *, 0x28) = (f64) sp160;
    M2C_FIELD(&colors, f64 *, 0x30) = (f64) sp148;
    M2C_FIELD(&colors, f64 *, 0x38) = (f64) sp150;
    M2C_FIELD(&colors, f64 *, 0x40) = (f64) sp138;
    M2C_FIELD(&colors, f64 *, 0x48) = (f64) sp140;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp130 = 0.0f;
    sp134 = 0.5f;
    sp118 = 0.247f;
    sp11C = 0.569f;
    sp120 = 1.0f;
    sp124 = 1.0f;
    sp108 = 0.208f;
    sp10C = 0.294f;
    sp110 = 0.69f;
    sp114 = 1.0f;
    spF8 = 0.0f;
    spFC = 0.0f;
    sp100 = 0.0f;
    sp104 = 0.5f;
    spE8 = 0.329f;
    spEC = 0.969f;
    spF0 = 0.063f;
    spF4 = 1.0f;
    spD8 = 0.208f;
    spDC = 0.51f;
    spE0 = 0.063f;
    spE4 = 1.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spD0 = 0.0f;
    spD4 = 0.5f;
    M2C_FIELD(&colors, f64 *, 0x50) = (f64) sp128;
    M2C_FIELD(&colors, f64 *, 0x58) = (f64) sp130;
    M2C_FIELD(&colors, f64 *, 0x60) = (f64) sp118;
    M2C_FIELD(&colors, f64 *, 0x68) = (f64) sp120;
    M2C_FIELD(&colors, f64 *, 0x70) = (f64) sp108;
    M2C_FIELD(&colors, f64 *, 0x78) = (f64) sp110;
    M2C_FIELD(&colors, f64 *, 0x80) = (f64) spF8;
    M2C_FIELD(&colors, f64 *, 0x88) = (f64) sp100;
    M2C_FIELD(&colors, f64 *, 0x90) = (f64) spE8;
    M2C_FIELD(&colors, f64 *, 0x98) = (f64) spF0;
    M2C_FIELD(&colors, f64 *, 0xA0) = (f64) spD8;
    M2C_FIELD(&colors, f64 *, 0xA8) = (f64) spE0;
    M2C_FIELD(&colors, f64 *, 0xB0) = (f64) spC8;
    M2C_FIELD(&colors, f64 *, 0xB8) = (f64) spD0;
}

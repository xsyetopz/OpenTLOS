#include "spyro/source/UITools.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameData.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIImage.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "spyro/source/UIVideoScreen.h"
#include "unplaced_templates.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/GameConsole.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

f64 atan2(f32);                                     /* extern */
UIObject *malloc(void *);                           /* extern */
s32 stricmp(s8 *, M2C_UNK *);                       /* extern */
extern s32 GS_MenuCancel;
extern s32 GS_MenuMoveThru;
extern s32 GS_MenuSelect;
extern s32 gDisplay;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern s32 gpTranslation_StringArray;
#if 0 // DRAFT: identifier 'buttonLabel' redeclared
static PromptText descriptor__10PromptText;         /* type too large by 0x6C; unable to generate initializer: not enough data */
static PromptGroup descriptor__11PromptGroup;       /* type too large by 0x5C; unable to generate initializer: not enough data */
static ScriptButton descriptor__12ScriptButton;     /* type too large by 0x94; unable to generate initializer: not enough data */
static OptionButton descriptor__12OptionButton;     /* type too large by 0x9C; unable to generate initializer: not enough data */
static ProgressBar descriptor__11ProgressBar;       /* type too large by 0xC4; unable to generate initializer: not enough data */
static ScriptProgressBar descriptor__17ScriptProgressBar; /* type too large by 0xD4; unable to generate initializer: not enough data */
static DSText descriptor__6DSText;                  /* type too large by 0x6C; unable to generate initializer: not enough data */
static M2C_UNK *buttonLabel[7] = {
    &.L_8035BF86,
    &.L_8035BF8B,
    &.L_8035BF93,
    &.L_8035BF9D,
    &.L_8035BFA4,
    &.L_8035BFA9,
    &.L_8035BFB0,
};
#endif
#if 0 // DRAFT: identifier 'buttonString' redeclared
static M2C_UNK *buttonString[7] = {
    &.L_8035BFC0,
    &.L_8035BFDE,
    &.L_8035BFFC,
    &.L_8035C01B,
    &.L_8035C03A,
    &.L_8035C059,
    &.L_8035C077,
};
#endif
static M2C_UNK RADIAL_V_COLOR;                      /* unable to generate initializer: unknown type */
static M2C_UNK RADIAL_V_DISABLED_COLOR;             /* unable to generate initializer: unknown type */

static s32 lit_1179 = 1;
#if 0 // DRAFT: declaration syntax error
static MKHeap lit_stringBase0;                         /* type too large by 0x115; unable to generate initializer: not enough data; const */
static M2C_UNK .L_8035BE63;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BE6F;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BE88;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BEA8;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BEB4;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BEC6;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BF86;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BF8B;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BF93;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BF9D;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BFA4;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BFA9;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BFB0;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BFC0;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BFDE;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035BFFC;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035C01B;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035C03A;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035C059;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8035C077;                         /* unable to generate initializer: unknown type; const */

void HealthSafetyScreen::Update() {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 sp8;
    f32 temp_f1_150;
    f32 temp_f1_44;
    s32 temp_r0_21;
    s32 var_r29_102;
    s32 var_r3_118;
    s8 *temp_r3_69;
    s8 *temp_r3_75;
    s8 *temp_r3_84;
    s8 *temp_r3_90;
    u8 var_r30_103;
    u8 var_r3_107;
    void **temp_r3_157;

    UIScreen::Update();
    M2C_FIELD(this, f32 *, 0xDC) = (f32) (M2C_FIELD(this, f32 *, 0xDC) + gUpdateTimeDelta);
    temp_r0_21 = this->unkD0;
    switch (temp_r0_21) {                           /* irregular */
    case 0:
        sp28 = M2C_FIELD(&gb, f64 *, 0x48);
        sp20 = M2C_FIELD(&gb, f64 *, 0x40);
        temp_f1_44 = -((2.0f * gUpdateTimeDelta) - unksp2C);
        unksp2C = temp_f1_44;
        if (temp_f1_44 < 0.0f) {
            unksp2C = 0.0f;
            this->unkD0 = 1;
        }
        M2C_FIELD(&gb, f64 *, 0x40) = sp20;
        M2C_FIELD(&gb, f64 *, 0x48) = sp28;
        return;
    case 1:
        if (M2C_FIELD(this, f32 *, 0xDC) > 1.5f) {
            this->unkD0 = 2;
            return;
        }
        return;
    case 2:
        if ((u8) M2C_FIELD(this, u8 *, 0xE0) != 0) {
            temp_r3_69 = this->unkBC.unk8;
            M2C_FIELD(temp_r3_69, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r3_69, f32 *, 0x24) - gUpdateTimeDelta);
            temp_r3_75 = this->unkBC.unk8;
            if (M2C_FIELD(temp_r3_75, f32 *, 0x24) < 0.0f) {
                M2C_FIELD(temp_r3_75, f32 *, 0x24) = 0.0f;
                M2C_FIELD(this, u8 *, 0xE0) = 0U;
            }
        } else {
            temp_r3_84 = this->unkBC.unk8;
            M2C_FIELD(temp_r3_84, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r3_84, f32 *, 0x24) + gUpdateTimeDelta);
            temp_r3_90 = this->unkBC.unk8;
            if (M2C_FIELD(temp_r3_90, f32 *, 0x24) > 1.0f) {
                M2C_FIELD(temp_r3_90, f32 *, 0x24) = 1.0f;
                M2C_FIELD(this, u8 *, 0xE0) = 1U;
            }
        }
        var_r29_102 = 3;
        var_r30_103 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
loop_25:
        if ((var_r29_102 <= 0xF) && (var_r30_103 == 0)) {
            var_r3_107 = 0;
            if (((u8) M2C_FIELD(this, u8 *, 0xD5) != 0) || ((u8) M2C_FIELD(this, u8 *, 0xD4) != 0)) {
                var_r3_107 = 1;
            }
            if (var_r3_107 != 0) {
                var_r3_118 = 0;
            } else {
                var_r3_118 = MKInput_Pressed(var_r29_102, (MKInputDevices) this->unkC8);
            }
            var_r29_102 += 1;
            var_r30_103 |= var_r3_118;
            goto loop_25;
        }
        if (var_r30_103 != 0) {
            this->unkD0 = 3;
            return;
        }
        break;
    case 3:
        sp18 = M2C_FIELD(&gb, f64 *, 0x48);
        sp10 = M2C_FIELD(&gb, f64 *, 0x40);
        temp_f1_150 = (2.0f * gUpdateTimeDelta) + unksp1C;
        unksp1C = temp_f1_150;
        if (temp_f1_150 > 1.0f) {
            unksp1C = 1.0f;
            temp_r3_157 = ui_cast<UISystem *, UIContainer *>(GetRoot());
            sp8 = 0xF;
            M2C_FIELD(*temp_r3_157, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        M2C_FIELD(&gb, f64 *, 0x40) = sp10;
        M2C_FIELD(&gb, f64 *, 0x48) = sp18;
        break;
    }
}
#endif

void HealthSafetyScreen::OnExit() {
    UIScreen::OnExit();
    M2C_FIELD(&gb, f64 *, 0x40) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 0);
    M2C_FIELD(&gb, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 8);
}

#if 0 // DRAFT: expression syntax error
void HealthSafetyScreen::OnEnter() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    UIScreen::OnEnter();
    this->unkC8 = NULL;
    M2C_FIELD(this, s8 *, 0xD4) = 0;
    M2C_FIELD(this, s8 *, 0xD5) = 0;
    this->unkBC.unk4 = ui_cast<UIImage *, UIObject *>(FindChild(&lit_stringBase0 + 0x23D));
    if ((s32) gDisplay == 1) {

    } else {
        GameLanguage_GetCode(-1);
    }
    M2C_FIELD(this->unkBC.unk4, MKResource **, 0x64) = MKMaterial_Create(Str_Printf(&lit_stringBase0 + 0x248, M2C_ERROR(/* Read from unset register $r3 */), &lit_stringBase0));
    this->unkBC.unk8 = ui_cast<UIImage *, UIObject *>(FindChild(&lit_stringBase0 + 0x256));
    M2C_FIELD(this, f32 *, 0xDC) = 0.0f;
    M2C_FIELD(this, s8 *, 0xE0) = 1;
    sp8 = 0.0f;
    spC = 0.0f;
    this->unkD0 = 0;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(&gb, f64 *, 0x40) = (f64) sp8;
    M2C_FIELD(&gb, f64 *, 0x48) = (f64) sp10;
}
#endif

#if 0 // DRAFT: expression syntax error
void HealthSafetyScreen::Init() {
    UIContainer::Init();
    this->unkBC.unk4 = 0;
    this->unkBC.unk8 = NULL;
}
#endif

#if 0 // DRAFT: function call 'GameLanguage_GetLast(long *, unsigned int)' does not match
void LanguageButtonGroup::LoadDone() {
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_321;
    MKHeap *temp_r3_370;
    MKHeap *var_r3_312;
    UIObject *temp_r3_347;
    UIObject *temp_r3_396;
    UIObject *var_r26_329;
    UIObject *var_r26_378;
    s8 *temp_r0_406;
    s8 *temp_r3_418;
    void *temp_r26_320;
    void *temp_r26_369;

    if (GameLanguage_GetLast(&spC, 1U) != 0) {
        var_r3_312 = &lit_stringBase0;
        do {
            temp_r26_320 = OptionButton::descriptor.unk8;
            temp_r3_321 = var_r3_312->Current();
            if (temp_r3_321 != NULL) {
                var_r26_329 = ((MKHeap *) (temp_r3_321->Current()))->Alloc((s32) temp_r26_320, NULL, 0);
            } else {
                var_r26_329 = malloc(temp_r26_320);
            }
            ((M2C_UNK (*)(UIObject *)) OptionButton::descriptor.unkC)(var_r26_329);
            var_r26_329->unk8 = &OptionButton::descriptor;
            var_r26_329->Init();
            temp_r3_347 = ui_cast<OptionButton *, UIObject *>(var_r26_329);
            temp_r3_347->unk18.unk40 = 0xB;
            temp_r3_347->unk18.unk10.unk0 = 0.0f;
            temp_r3_347->unk18.unk10.unk4 = 0.0f;
            temp_r3_347->unk18.unk10.unk8 = 0.0f;
            GameLanguage_GetCode(spC);
            M2C_FIELD(temp_r3_347->__vptr, M2C_UNK (**)(UIObject *, s8 *), 0x4C)(temp_r3_347, Str_Printf(&lit_stringBase0 + 0x25C, M2C_ERROR(/* Read from unset register $r3 */)));
            Add(temp_r3_347);
            temp_r26_369 = DSText::descriptor.unk8;
            temp_r3_370 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
            if (temp_r3_370 != NULL) {
                var_r26_378 = ((MKHeap *) (temp_r3_370->Current()))->Alloc((s32) temp_r26_369, NULL, 0);
            } else {
                var_r26_378 = malloc(temp_r26_369);
            }
            ((M2C_UNK (*)(UIObject *)) DSText::descriptor.unkC)(var_r26_378);
            var_r26_378->unk8 = &DSText::descriptor;
            var_r26_378->Init();
            temp_r3_396 = ui_cast<UIText *, UIObject *>(var_r26_378);
            temp_r3_396->unk18.unk40 = 0x32;
            temp_r3_396->unk18.unk34 = 180.0f;
            temp_r3_396->unk18.unk38 = 40.0f;
            temp_r3_396->unk18.unk3C = 4;
            GameLanguage_GetName(spC);
            temp_r0_406 = M2C_FIELD(temp_r3_396, s8 **, 0x68);
            if (temp_r0_406 != NULL) {
                UIStringTable_Remove(temp_r0_406);
            }
            UIStringTable_Add(M2C_ERROR(/* Read from unset register $r3 */));
            M2C_FIELD(temp_r3_396, s8 **, 0x68) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
            M2C_FIELD(temp_r3_396, s32 *, 0x6C) = -1;
            temp_r3_418 = M2C_FIELD(temp_r3_396, s8 **, 0x60);
            if (temp_r3_418 != NULL) {
                UIStringTable_Remove(temp_r3_418);
            }
            UIStringTable_Add(&lit_stringBase0 + 0x264);
            M2C_FIELD(temp_r3_396, s8 **, 0x60) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
            temp_r3_347->Add(temp_r3_396);
            if (GameLanguage_Available(spC) == 0) {
                sp8 = 5;
                temp_r3_347->Message(&sp8);
            }
            var_r3_312 = GameLanguage_GetPrev(&spC, 1U);
        } while ((u8) var_r3_312 != 0);
    }
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
void ScriptVideoScreen::DoExit() {
    Console_Execute(this->unk128);
}
#endif

#if 0 // DRAFT: undefined identifier 'IsField'
s32 ScriptVideoScreen::LoadLine(UIDataLine *arg0) {
    s32 temp_r31_494;

    if (arg0->IsField(&lit_stringBase0 + 0x26E) != 0) {
        temp_r31_494 = arg0->GetString(0);
        this->unk128 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_494);
        return 1;
    }
    return UIVideoScreen::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptVideoScreen::Deinit() {
    s8 *temp_r31_523;

    temp_r31_523 = this->unk128;
    if (temp_r31_523 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_523);
    }
    UIVideoScreen::Deinit();
}
#endif

void ScriptVideoScreen::Init() {
    UIVideoScreen::Init();
    this->unk128 = NULL;
}

#if 0 // DRAFT: undefined identifier 'arg_sp20'
void ImageArc::Draw(const RenderContext &arg0) {
    f32 temp_f0_618;
    f32 temp_f0_649;
    f32 temp_f1_601;
    f32 temp_f1_648;
    f32 temp_f23_717;
    f32 temp_f23_722;
    f32 temp_f24_687;
    f32 temp_f31_667;
    f32 temp_f4_602;
    f32 temp_f5_645;
    f32 temp_f6_647;
    f32 var_f1_670;
    f32 var_f26_631;
    f32 var_f27_635;
    f32 var_f28_605;
    f32 var_f29_604;
    f32 var_f2_636;
    f32 var_f3_633;
    s32 temp_r0_608;
    s32 temp_r0_625;
    s32 temp_r3_603;
    s32 var_r28_702;
    s32 var_r29_679;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk70 != 0.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk74 == 0.0f) {
            return;
        }
        arg_sp20.RenderContext(arg0, this->unk18);
        temp_f1_601 = this->unk78;
        temp_f4_602 = this->unk7C;
        temp_r3_603 = this->unk18.unk40 & 0x20;
        var_f29_604 = temp_f1_601;
        var_f28_605 = temp_f1_601 + temp_f4_602;
        if (temp_r3_603 != 0) {
            temp_r0_608 = this->unk18.unk3C & 3;
            if (temp_r0_608 == 2) {
                var_f28_605 = temp_f1_601;
                var_f29_604 = temp_f1_601 - temp_f4_602;
            } else if (temp_r0_608 == 1) {
                temp_f0_618 = temp_f4_602 * 0.5f;
                var_f29_604 = temp_f1_601 - temp_f0_618;
                var_f28_605 = temp_f1_601 + temp_f0_618;
            }
        }
        if ((temp_r3_603 == 0) || (temp_r0_625 = this->unk18.unk3C & 0xC, ((temp_r0_625 == 0) != 0))) {
            var_f26_631 = 0.5f * this->unk18.unk34;
            var_f3_633 = 0.5f * this->unk18.unk38;
            var_f27_635 = var_f26_631 - this->unk70;
            var_f2_636 = var_f3_633 - this->unk74;
        } else if (temp_r0_625 == 4) {
            temp_f5_645 = 0.5f * this->unk18.unk38;
            temp_f6_647 = 0.5f * this->unk18.unk34;
            temp_f1_648 = 0.5f * this->unk70;
            temp_f0_649 = 0.5f * this->unk74;
            var_f27_635 = temp_f6_647 - temp_f1_648;
            var_f2_636 = temp_f5_645 - temp_f0_649;
            var_f26_631 = temp_f6_647 + temp_f1_648;
            var_f3_633 = temp_f5_645 + temp_f0_649;
        } else {
            var_f27_635 = 0.5f * this->unk18.unk34;
            var_f2_636 = 0.5f * this->unk18.unk38;
            var_f26_631 = var_f27_635 + this->unk70;
            var_f3_633 = var_f2_636 + this->unk74;
        }
        temp_f31_667 = -var_f3_633;
        var_f1_670 = -temp_f31_667;
        if (var_f26_631 > var_f1_670) {
            var_f1_670 = var_f26_631;
        }
        var_r29_679 = (s32) ((temp_f4_602 / 6.2831855f) * var_f1_670);
        if ((s32) lit_1179 > var_r29_679) {
            var_r29_679 = lit_1179;
        }
        temp_f24_687 = this->unk68 - this->unk68;
        MKMaterial_SetMaterial(this->unk64);
        MKPrimitive(0xC, 1);
        MKSetMatrix(*((Matrix *) &arg_sp20));
        MKBegin((var_r29_679 + 1) * 2);
        MKSetColorV(*((MKVector4 *) &arg_sp60));
        var_r28_702 = 0;
loop_20:
        if (var_r28_702 <= var_r29_679) {
            temp_f23_717 = (f32) var_r28_702 / (f32) var_r29_679;
            _table_sincosf((temp_f23_717 * (var_f28_605 - var_f29_604)) + var_f29_604, arg_sp14, arg_sp10);
            temp_f23_722 = (temp_f24_687 * temp_f23_717) + this->unk68;
            MKSetTexCoord1F(temp_f23_722, this->unk6C);
            MKSetPositionF(arg_sp14 * var_f27_635, arg_sp10 * -var_f2_636, 0.0f);
            MKSetTexCoord1F(temp_f23_722, M2C_BITWISE(f32, this->unk64));
            MKSetPositionF(arg_sp14 * var_f26_631, arg_sp10 * temp_f31_667, 0.0f);
            var_r28_702 += 1;
            goto loop_20;
        }
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

void RadialButtonGroup::Draw(const RenderContext &arg0) {
    M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *), 0x1C)(&this->unk6C.unk4);
    UIContainer::Draw(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void RadialButtonGroup::Update() {
    s32 sp20;
    s32 sp1C;
    UIObject *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIObject *temp_r0_1019;
    UIObject *temp_r31_810;
    UIObject *temp_r5_1009;
    f32 temp_f31_1042;
    f32 temp_r3_1006;
    f32 var_f1_825;
    f32 var_f2_849;
    f32 var_f3_880;
    s32 temp_r3_868;
    s32 temp_r3_901;
    s32 var_r3_929;
    s32 var_r3_962;
    u8 var_r4_814;
    u8 var_r4_838;
    u8 var_r4_918;
    u8 var_r4_951;
    void *temp_r3_812;
    void *temp_r3_836;
    void *temp_r3_916;
    void *temp_r3_949;

    if ((u8) this->unk15 != 0) {
        temp_r31_810 = this->unk60;
        temp_r3_812 = UIInput(-1);
        var_r4_814 = 0;
        if (((u8) M2C_FIELD(temp_r3_812, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_812, u8 *, 4) != 0)) {
            var_r4_814 = 1;
        }
        if (var_r4_814 != 0) {
            var_f1_825 = 0.0f;
        } else {
            var_f1_825 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(temp_r3_812, s32 *, 0), NULL, NULL);
        }
        temp_r3_836 = UIInput(-1);
        var_r4_838 = 0;
        if (((u8) M2C_FIELD(temp_r3_836, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_836, u8 *, 4) != 0)) {
            var_r4_838 = 1;
        }
        if (var_r4_838 != 0) {
            var_f2_849 = 0.0f;
        } else {
            var_f2_849 = MKInput_GetState(0x10, (MKInputDevices) M2C_FIELD(temp_r3_836, s32 *, 0), NULL, NULL);
        }
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (((var_f1_825 * var_f1_825) + (var_f2_849 * var_f2_849)) == 0.4489f) {
            temp_r3_868 = this->unkFC;
            var_f3_880 = (f32) atan2(var_f1_825) + (3.1415927f / (f32) temp_r3_868);
            if (var_f3_880 < 0.0f) {
                var_f3_880 += 6.2831855f;
            }
            temp_r3_901 = (s32) (f32) floor((f64) ((var_f3_880 * (f32) temp_r3_868) / 6.2831855f));
            if (temp_r3_901 != (UIObject *) this->unk60) {
                sp20 = temp_r3_901;
                sp1C = 0xC;
                Message(&sp1C);
            }
        } else {
            temp_r3_916 = UIInput(-1);
            var_r4_918 = 0;
            if (((u8) M2C_FIELD(temp_r3_916, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_916, u8 *, 4) != 0)) {
                var_r4_918 = 1;
            }
            if (var_r4_918 != 0) {
                var_r3_929 = 0;
            } else {
                var_r3_929 = MKInput_Pressed(7, (MKInputDevices) M2C_FIELD(temp_r3_916, s32 *, 0));
            }
            if ((u8) var_r3_929 != 0) {
                sp10 = 0xB;
                Message(&sp10);
            } else {
                temp_r3_949 = UIInput(-1);
                var_r4_951 = 0;
                if (((u8) M2C_FIELD(temp_r3_949, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_949, u8 *, 4) != 0)) {
                    var_r4_951 = 1;
                }
                if (var_r4_951 != 0) {
                    var_r3_962 = 0;
                } else {
                    var_r3_962 = MKInput_Pressed(5, (MKInputDevices) M2C_FIELD(temp_r3_949, s32 *, 0));
                }
                if ((u8) var_r3_962 != 0) {
                    spC = 0xA;
                    Message(&spC);
                }
            }
        }
        if (temp_r31_810 != (UIObject *) this->unk60) {
            KDSound_Play(GS_MenuMoveThru, 0U, -1);
            if ((u8) GetChild((s32) this->unk60)->unk15 != 0) {
                M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&RADIAL_V_COLOR, f64 *, 0);
                this->unk90 = M2C_FIELD(&RADIAL_V_COLOR, f64 *, 8);
            } else {
                M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&RADIAL_V_DISABLED_COLOR, f64 *, 0);
                this->unk90 = M2C_FIELD(&RADIAL_V_DISABLED_COLOR, f64 *, 8);
            }
            temp_r3_1006 = this->unkF0;
            if (M2C_BITWISE(u32, temp_r3_1006) != 0U) {
                temp_r5_1009 = this->unk60;
                sp14 = 0xC;
                sp18 = temp_r5_1009;
                M2C_FIELD(*temp_r3_1006, M2C_UNK (**)(s32 *, UIObject *), 0x2C)(&sp14, temp_r5_1009);
            }
        }
        temp_r0_1019 = this->unk60;
        if (temp_r0_1019 >= 0) {
            temp_f31_1042 = (-6.2831855f * ((f32) temp_r0_1019 / (f32) this->unkFC)) - (3.1415927f * this->unkF0);
            if ((u8) this->unk8C == 0) {
                sp8 = 2;
                M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *, s32 *), 0x2C)(&this->unk6C.unk4, &sp8);
                this->unkB0 = temp_f31_1042;
            } else {
                KDMath_SmoothToAngle(this->unkB0, temp_f31_1042, 15.0f, gUpdateTimeDelta);
                this->unkB0 = M2C_ERROR(/* Read from unset register $f1 */);
            }
            this->unk98 = M2C_FIELD(this, f64 *, 0x28);
            this->unkA0 = M2C_FIELD(this, f64 *, 0x30);
        }
    }
    UIContainer::Update();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void RadialButtonGroup::Message(UIMessage *arg0) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIObject *temp_r3_1123;
    UIObject *temp_r3_1143;
    UIObject *temp_r3_1165;
    UIObject *temp_r3_1185;
    UIObject *temp_r3_1198;
    UIObject *temp_r4_1117;
    UIObject *temp_r4_1136;
    UIObject *temp_r4_1159;
    UIObject *temp_r4_1178;
    f32 temp_r3_1265;
    s32 temp_r0_1087;

    temp_r0_1087 = arg0->unk0;
    switch (temp_r0_1087) {                         /* irregular */
    case 6:
        if ((u8) GetChild((s32) this->unk60)->unk15 == 0) {
            KDSound_Play(GS_MenuCancel, 0U, -1);
            return;
        }
        KDSound_Play(GS_MenuSelect, 0U, -1);
    default:
        UIButtonGroup::Message(arg0);
        return;
    case 12:
        temp_r4_1117 = this->unk60;
        if ((temp_r4_1117 >= 0) && (temp_r4_1117 < (s32) this->unk64)) {
            temp_r3_1123 = GetChild((s32) temp_r4_1117);
            sp28 = 9;
            sp2C = 0;
            M2C_FIELD(temp_r3_1123->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp28);
        }
        this->unk60 = (UIObject *) arg0->unk4;
        temp_r4_1136 = this->unk60;
        if ((temp_r4_1136 >= 0) && (temp_r4_1136 < (s32) this->unk64)) {
            temp_r3_1143 = GetChild((s32) temp_r4_1136);
            sp20 = 8;
            sp24 = 0;
            M2C_FIELD(temp_r3_1143->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp20);
        }
        this->unk64.Send();
        return;
    case 1:
        temp_r4_1159 = this->unk60;
        if ((temp_r4_1159 >= 0) && (temp_r4_1159 < (s32) this->unk64)) {
            temp_r3_1165 = GetChild((s32) temp_r4_1159);
            sp18 = 9;
            sp1C = 0;
            M2C_FIELD(temp_r3_1165->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
        }
        this->unk60 = (UIObject *) arg0->unk4;
        temp_r4_1178 = this->unk60;
        if ((temp_r4_1178 >= 0) && (temp_r4_1178 < (s32) this->unk64)) {
            temp_r3_1185 = GetChild((s32) temp_r4_1178);
            sp10 = 8;
            sp14 = 0;
            M2C_FIELD(temp_r3_1185->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        }
        SetPositions();
        temp_r3_1198 = this->unk60;
        if (temp_r3_1198 == (UIObject *)-1) {
            spC = 3;
            M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *, s32 *), 0x2C)(&this->unk6C.unk4, &spC);
            this->unkB0 = 0.0f;
        } else {
            this->unkB0 = (-6.2831855f * ((f32) temp_r3_1198 / (f32) this->unkFC)) - (3.1415927f * this->unkF0);
            if ((u8) GetChild((s32) this->unk60)->unk15 != 0) {
                M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&RADIAL_V_COLOR, f64 *, 0);
                this->unk90 = M2C_FIELD(&RADIAL_V_COLOR, f64 *, 8);
            } else {
                M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&RADIAL_V_DISABLED_COLOR, f64 *, 0);
                this->unk90 = M2C_FIELD(&RADIAL_V_DISABLED_COLOR, f64 *, 8);
            }
            sp8 = 2;
            M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *, s32 *), 0x2C)(&this->unk6C.unk4, &sp8);
        }
        this->unk98 = M2C_FIELD(this, f64 *, 0x28);
        this->unkA0 = M2C_FIELD(this, f64 *, 0x30);
        temp_r3_1265 = this->unkF0;
        if (M2C_BITWISE(u32, temp_r3_1265) != 0U) {
            M2C_FIELD(*temp_r3_1265, M2C_UNK (**)(UIMessage *), 0x2C)(arg0);
        }
        UIContainer::Message(arg0);
        return;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void RadialButtonGroup::Resolve() {
    UIButtonGroup::Resolve();
    SetPositions();
    this->unkF0 = M2C_BITWISE(f32, ui_cast<UIContainer *, UIObject *>(this->unkC->FindChild(&lit_stringBase0 + 0x275)));
}
#endif

void RadialButtonGroup::SetPositions() {
    f32 spC;
    f32 sp8;
    s32 temp_r0_1341;
    s32 var_r29_1347;
    void *var_r30_1352;
    void *var_r4_1327;

    this->unkFC = 0;
    var_r4_1327 = this->unk60;
loop_4:
    if (var_r4_1327 != NULL) {
        if ((u8) M2C_FIELD(var_r4_1327, u8 *, 0x14) != 0) {
            this->unkFC += 1;
        }
        var_r4_1327 = M2C_FIELD(var_r4_1327, void **, 0x10);
        goto loop_4;
    }
    temp_r0_1341 = this->unkFC;
    if (temp_r0_1341 != 0) {
        var_r29_1347 = 0;
        var_r30_1352 = this->unk60;
loop_10:
        if (var_r30_1352 != NULL) {
            if ((u8) M2C_FIELD(var_r30_1352, u8 *, 0x14) != 0) {
                _table_sincosf((6.2831855f / (f32) temp_r0_1341) * (f32) var_r29_1347, spC, sp8);
                var_r29_1347 += 1;
                M2C_FIELD(var_r30_1352, f32 *, 0x28) = (f32) (spC * (0.5f * this->unk18.unk34));
                M2C_FIELD(var_r30_1352, f32 *, 0x2C) = (f32) (-sp8 * (0.5f * this->unk18.unk38));
                M2C_FIELD(var_r30_1352, u16 *, 0x58) = (u16) (M2C_FIELD(var_r30_1352, u16 *, 0x58) | 2);
            }
            var_r30_1352 = M2C_FIELD(var_r30_1352, void **, 0x10);
            goto loop_10;
        }
        this->unkF0 = 1.0f / (f32) this->unkFC;
    }
}

void RadialButtonGroup::FreeResources() {
    UIContainer::FreeResources();
    M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *), 0x24)(&this->unk6C.unk4);
}

void RadialButtonGroup::LoadResources() {
    UIContainer::LoadResources();
    M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *), 0x20)(&this->unk6C.unk4);
    this->unkF0 = 0.125f;
}

void RadialButtonGroup::Deinit() {
    UIContainer::Deinit();
    M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *), 0xC)(&this->unk6C.unk4);
}

void RadialButtonGroup::Init() {
    UIButtonGroup::Init();
    M2C_FIELD(this->unk6C.unk4, M2C_UNK (**)(s32 *), 8)(&this->unk6C.unk4);
    M2C_FIELD(this, u16 *, 0xD0) = (u16) (M2C_FIELD(this, u16 *, 0xD0) | 0x37);
    M2C_FIELD(this, f32 *, 0xA0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xA4) = 0.0f;
    M2C_FIELD(this, f32 *, 0xA8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xB0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xB4) = 0.0f;
    this->unkB0 = 0.0f;
    this->unkC4 = 1120.0f;
    this->unkC8 = 1120.0f;
    M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&RADIAL_V_COLOR, f64 *, 0);
    this->unk90 = M2C_FIELD(&RADIAL_V_COLOR, f64 *, 8);
    this->unkC4 = 7e-45f;
    this->unkF0 = 0.0f;
    this->unkFC = 0;
}

#if 0 // DRAFT: undefined identifier 'arg_sp100'
void UIPie::Draw(const RenderContext &arg0) {
    f32 temp_f0_1659;
    f32 temp_f2_1658;
    f32 temp_f2_1729;
    f32 temp_f3_1610;
    f32 temp_f3_1731;
    s32 temp_r30_1615;
    s32 temp_r3_1563;
    s32 temp_r3_1579;
    s32 var_r28_1639;
    s32 var_r29_1608;
    if (!(this->unk70 < 0.00390625f)) {
        MKMaterial_SetMaterial(this->unk64);
        arg_sp100.RenderContext(arg0, this->unk18);
        arg_sp68 = 0.0f;
        arg_sp60 = 0.0f;
        arg_sp64 = 0.0f;
        arg_spB8 = (f64) arg_sp68;
        arg_spB0 = (f64) arg_sp60;
        temp_r3_1563 = this->unk18.unk3C;
        if (!(temp_r3_1563 & 3)) {
            arg_spB0 = 0.5f * this->unk18.unk34;
        } else if (!(temp_r3_1563 & 1)) {
            arg_spB0 = -0.5f * this->unk18.unk34;
        }
        temp_r3_1579 = this->unk18.unk3C;
        if (!(temp_r3_1579 & 0xC)) {
            arg_spB4 = 0.5f * this->unk18.unk38;
        } else if (!(temp_r3_1579 & 4)) {
            arg_spB4 = -0.5f * this->unk18.unk38;
        }
        arg_spC0.SetIdentity();
        arg_spC0.Translate((Matrix *) &arg_spC0, *((MKVector3 *) &arg_spB0));
        arg_sp100.Multiply((Matrix *) &arg_spC0, (Matrix *) &arg_sp100);
        var_r29_1608 = 0;
        temp_f3_1610 = 16.0f * this->unk70;
        temp_r30_1615 = (s32) temp_f3_1610;
        if ((temp_f3_1610 - (f32) temp_r30_1615) > 0.0625f) {
            var_r29_1608 = 1;
        }
        MKPrimitive(0xD, 1);
        MKBegin(temp_r30_1615 + var_r29_1608 + 2);
        MKSetColorV(*((MKVector4 *) &arg_sp140));
        MKSetTexCoord1F(0.5f, 0.5f);
        MKSetPositionV(*((MKVector3 *) &arg_sp130));
        var_r28_1639 = 0;
loop_13:
        if (var_r28_1639 <= temp_r30_1615) {
            _table_sincosf(0.3926991f * (f32) var_r28_1639, arg_sp1C, arg_sp18);
            temp_f2_1658 = arg_sp1C * -0.5f;
            temp_f0_1659 = arg_sp18 * -0.5f;
            arg_sp1C = temp_f2_1658;
            arg_sp18 = temp_f0_1659;
            MKSetTexCoord1F(0.5f + temp_f2_1658, 0.5f + temp_f0_1659);
            arg_sp58 = 0.0f;
            arg_sp50 = arg_sp1C * this->unk18.unk34;
            arg_sp54 = arg_sp18 * this->unk18.unk38;
            arg_sp90 = (f64) arg_sp50;
            arg_sp98 = (f64) arg_sp58;
            arg_sp40 = arg_sp130 + (((f32) arg_sp98 * arg_sp120) + (((f32) arg_sp90 * arg_sp100) + (arg_sp94 * arg_sp110)));
            arg_sp44 = arg_sp134 + (((f32) arg_sp98 * arg_sp124) + (((f32) arg_sp90 * arg_sp104) + (arg_sp94 * arg_sp114)));
            arg_sp48 = arg_sp138 + (((f32) arg_sp98 * arg_sp128) + (((f32) arg_sp90 * arg_sp108) + (arg_sp94 * arg_sp118)));
            arg_spA0 = (f64) arg_sp40;
            arg_spA8 = (f64) arg_sp48;
            MKSetPositionV(*((MKVector3 *) &arg_spA0));
            var_r28_1639 += 1;
            goto loop_13;
        }
        if (var_r29_1608 != 0) {
            _table_sincosf(6.2831855f * this->unk70, arg_sp14, arg_sp10);
            temp_f2_1729 = arg_sp14 * -0.5f;
            temp_f3_1731 = arg_sp10 * -0.5f;
            arg_sp14 = temp_f2_1729;
            arg_sp10 = temp_f3_1731;
            MKSetTexCoord1F(0.5f + temp_f2_1729, 0.5f + temp_f3_1731);
            arg_sp30 = arg_sp14 * this->unk18.unk34;
            arg_sp34 = arg_sp10 * this->unk18.unk38;
            arg_sp38 = 0.0f;
            arg_sp70 = (f64) arg_sp30;
            arg_sp78 = (f64) arg_sp38;
            arg_sp20 = arg_sp130 + (((f32) arg_sp78 * arg_sp120) + (((f32) arg_sp70 * arg_sp100) + (arg_sp74 * arg_sp110)));
            arg_sp24 = arg_sp134 + (((f32) arg_sp78 * arg_sp124) + (((f32) arg_sp70 * arg_sp104) + (arg_sp74 * arg_sp114)));
            arg_sp28 = arg_sp138 + (((f32) arg_sp78 * arg_sp128) + (((f32) arg_sp70 * arg_sp108) + (arg_sp74 * arg_sp118)));
            arg_sp80 = (f64) arg_sp20;
            arg_sp88 = (f64) arg_sp28;
            MKSetPositionV(*((MKVector3 *) &arg_sp80));
        }
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

void UIPie::Init() {
    UIImage::Init();
    this->unk70 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void LocalizedVideoScreen::LoadDone() {
    s8 *temp_r0_1845;
    s8 *temp_r31_1836;
    s8 *temp_r31_1846;

    temp_r31_1836 = this->unkE0;
    GameLanguage_GetCode(-1);
    temp_r0_1845 = this->unkE0;
    temp_r31_1846 = Str_Printf(&lit_stringBase0 + 0x27C, temp_r31_1836, M2C_ERROR(/* Read from unset register $r3 */), &lit_stringBase0);
    if (temp_r0_1845 != NULL) {
        UIStringTable_Remove(temp_r0_1845);
    }
    UIStringTable_Add(temp_r31_1846);
    this->unkE0 = M2C_ERROR(/* Read from unset register $r3 */);
}
#endif

#if 0 // DRAFT: type mismatch
u8 MarkerButtonGroup::GetTargetAttributes(Attributes *arg0) {
    Attributes *var_r30_1923;
    ScriptProgressBar *temp_r3_1927;
    UIObject *temp_r3_1900;
    UIObject *temp_r4_1880;
    f32 temp_f2_1913;
    f32 var_f0_1914;
    f32 var_f31_1898;
    f32 var_f6_1980;
    f32 var_f7_1964;
    s32 temp_r0_1960;
    s32 temp_r0_1976;
    s32 temp_r3_1959;
    void *temp_r3_1888;
    arg0->SetIdentity();
    arg0->unk40 = 0x10;
    temp_r4_1880 = this->unk60;
    if (temp_r4_1880 < 0) {
        return 0U;
    }
    temp_r3_1888 = ui_cast<UIContainer *, UIObject *>(GetChild((s32) temp_r4_1880));
    if ((temp_r3_1888 == NULL) || ((u8) M2C_FIELD(temp_r3_1888, u8 *, 0x14) == 0)) {
        return 0U;
    }
    var_f31_1898 = 0.0f;
    temp_r3_1900 = ui_cast<UIText *, UIObject *>(M2C_FIELD(temp_r3_1888, UIObject **, 0x60));
    if (temp_r3_1900 != NULL) {
        if (((s32) M2C_FIELD(temp_r3_1900, s32 *, 0x6C) >= 0) || ((u32) M2C_FIELD(temp_r3_1900, u32 *, 0x68) != 0U)) {
            temp_r3_1900->GetStringWidth();
            temp_f2_1913 = temp_r3_1900->unk18.unk34;
            var_f0_1914 = 10.0f + M2C_ERROR(/* Read from unset register $f1 */);
            if (var_f0_1914 < temp_f2_1913) {

            } else {
                var_f0_1914 = temp_f2_1913;
            }
            var_f31_1898 = var_f0_1914;
        }
        var_r30_1923 = &temp_r3_1900->unk18;
        goto block_16;
    }
    temp_r3_1927 = ui_cast<ScriptProgressBar *, UIObject *>(M2C_FIELD(temp_r3_1888, UIObject **, 0x60));
    if (temp_r3_1927 == NULL) {
        return 0U;
    }
    var_f31_1898 = temp_r3_1927->unk18.unk34;
    var_r30_1923 = &temp_r3_1927->unk18;
block_16:
    M2C_FIELD(arg0, f64 *, 0x20) = (f64) M2C_FIELD(var_r30_1923, f64 *, 0x20);
    M2C_FIELD(arg0, f64 *, 0x28) = (f64) M2C_FIELD(var_r30_1923, f64 *, 0x28);
    arg0->unk34 = M2C_FIELD(temp_r3_1888, f32 *, 0x48) * (var_f31_1898 * var_r30_1923->unk30);
    arg0->unk38 = M2C_FIELD(temp_r3_1888, f32 *, 0x48) * (var_r30_1923->unk38 * var_r30_1923->unk30);
    arg_sp30.RenderContext();
    arg_sp30.AddState(*(temp_r3_1888 + 0x18));
    arg_sp30.AddState(*var_r30_1923);
    temp_r3_1959 = var_r30_1923->unk3C;
    temp_r0_1960 = temp_r3_1959 & 3;
    if (temp_r0_1960 == 0) {
        var_f7_1964 = (0.5f * var_f31_1898) - 5.0f;
    } else if (temp_r0_1960 == 1) {
        var_f7_1964 = 0.0f;
    } else {
        var_f7_1964 = (-0.5f * var_f31_1898) + 5.0f;
    }
    temp_r0_1976 = temp_r3_1959 & 0xC;
    if (temp_r0_1976 == 0) {
        var_f6_1980 = 0.5f * temp_r3_1900->unk18.unk38;
    } else if (temp_r0_1976 == 4) {
        var_f6_1980 = 0.0f;
    } else {
        var_f6_1980 = -0.5f * var_r30_1923->unk38;
    }
    arg_sp10 = arg_sp60 + ((0.0f * arg_sp50) + ((var_f7_1964 * arg_sp30) + (var_f6_1980 * arg_sp40)));
    arg_sp14 = arg_sp64 + ((0.0f * arg_sp54) + ((var_f7_1964 * arg_sp34) + (var_f6_1980 * arg_sp44)));
    arg_sp18 = arg_sp68 + ((0.0f * arg_sp58) + ((var_f7_1964 * arg_sp38) + (var_f6_1980 * arg_sp48)));
    M2C_FIELD(arg0, f64 *, 0x10) = (f64) arg_sp10;
    M2C_FIELD(arg0, f64 *, 0x18) = (f64) arg_sp18;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    arg0->unk40 = 0x16;
    return temp_r3_1900 != NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void MarkerButtonGroup::Draw(const RenderContext &arg0) {
    arg_sp10.RenderContext(arg0, this->unk18);
    if ((u8) this->unkF8 != 0) {
        M2C_FIELD(M2C_FIELD(this, void **, 0x80), M2C_UNK (**)(M2C_UNK *, M2C_UNK *), 0x1C)(&this->unk80, &arg_sp10);
    }
    UIContainer::Draw(arg0);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MarkerButtonGroup::Update() {
    Attributes sp8;
    M2C_UNK *temp_r3_2090;

    NoisyButtonGroup::Update();
    this->unkF8 = GetTargetAttributes(&sp8);
    temp_r3_2090 = &this->unk98;
    temp_r3_2090->Tween((Attributes *) temp_r3_2090, &sp8, 0.5f);
    M2C_FIELD(M2C_FIELD(this, void **, 0x80), M2C_UNK (**)(M2C_UNK *), 0x18)(&this->unk80);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MarkerButtonGroup::Message(UIMessage *arg0) {
    Attributes sp8;
    M2C_UNK *temp_r3_2124;

    if ((s32) arg0->unk0 != 1) {
        return NoisyButtonGroup::Message(arg0);
    }
    NoisyButtonGroup::Message(arg0);
    GetTargetAttributes(&sp8);
    temp_r3_2124 = &this->unk98;
    temp_r3_2124->Tween((Attributes *) temp_r3_2124, &sp8, 1.0f);
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk80'
void MarkerButtonGroup::FreeResources() {
    UIContainer::FreeResources();
    M2C_FIELD(M2C_FIELD(this, void **, 0x80), M2C_UNK (**)(M2C_UNK *), 0x24)(&this->unk80);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk80'
void MarkerButtonGroup::LoadResources() {
    UIContainer::LoadResources();
    M2C_FIELD(M2C_FIELD(this, void **, 0x80), M2C_UNK (**)(M2C_UNK *), 0x20)(&this->unk80);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk80'
void MarkerButtonGroup::Deinit() {
    UIContainer::Deinit();
    M2C_FIELD(M2C_FIELD(this, void **, 0x80), M2C_UNK (**)(M2C_UNK *), 0xC)(&this->unk80);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MarkerButtonGroup::Init() {
    s8 *temp_r3_2218;

    NoisyButtonGroup::Init();
    M2C_FIELD(M2C_FIELD(this, void **, 0x80), M2C_UNK (**)(M2C_UNK *), 8)(&this->unk80);
    temp_r3_2218 = M2C_FIELD(this, s8 **, 0xE0);
    if (temp_r3_2218 != NULL) {
        UIStringTable_Remove(temp_r3_2218);
    }
    UIStringTable_Add(&lit_stringBase0 + 0x281);
    M2C_FIELD(this, s8 **, 0xE0) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
    M2C_FIELD(this, s16 *, 0xD8) = 0x3F;
    M2C_FIELD(this, f32 *, 0x98) = 1.0f;
    this->unk9C = 1.0f;
    this->unk98.unk0 = 1.0f;
    this->unk98.unk4 = 1.0f;
    this->unk98.unk20.unkC = 100.0f;
    this->unk98.unk30 = 30.0f;
    this->unk98.unk34 = 7e-45f;
    this->unkF8 = 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void NoisySystem::Message(UIMessage *arg0) {
    s32 temp_r0_2259;

    temp_r0_2259 = arg0->unk0;
    switch (temp_r0_2259) {                         /* irregular */
    case 14:
        break;
    case 15:
        if ((UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) && ((u8) M2C_FIELD(&gb, u8 *, 9) != 0)) {
            KDSound_Play(GS_MenuCancel, 0U, -1);
        }
        break;
    }
    UISystem::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal operand
s32 ScriptButtonGroup::SetSelection(int arg0) {
    if (arg0 != (UIObject *) this->unk60) {
        return UIButtonGroup::SetSelection(arg0);
    }
    return 1;
}
#endif

#if 0 // DRAFT: function call 'Console_Execute(signed char *)' does not match
void ScriptButtonGroup::Message(UIMessage *arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r0_2323;
    s8 *temp_r3_2335;

    temp_r0_2323 = arg0->unk0;
    switch (temp_r0_2323) {                         /* irregular */
    case 1:
        temp_r3_2335 = this->unk80;
        if (temp_r3_2335 != NULL) {
            sp8 = arg0->unk0;
            spC = arg0->unk4;
            spC = (s32) Console_Execute(temp_r3_2335);
            NoisyButtonGroup::Message((UIMessage *) &sp8);
            return;
        }
    default:
block_10:
        NoisyButtonGroup::Message(arg0);
        return;
    case 8:
        this->unk84 = 1;
        goto block_10;
    case 9:
        this->unk84 = 0;
        goto block_10;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ScriptButtonGroup::Update() {
    s32 spC;
    s32 sp8;
    s8 *temp_r3_2415;
    u8 var_r31_2381;

    NoisyButtonGroup::Update();
    if ((u8) this->unk84 != 0) {
        var_r31_2381 = 0;
        if (UIControls_DirectionPressed((FrontEndControls) 7, -1) != 0) {
            spC = 0xB;
            Message(&spC);
            var_r31_2381 = 1;
        } else if (UIControls_DirectionPressed((FrontEndControls) 5, -1) != 0) {
            sp8 = 0xA;
            Message(&sp8);
            var_r31_2381 = 1;
        }
        if (var_r31_2381 != 0) {
            temp_r3_2415 = this->unk80;
            if (temp_r3_2415 != NULL) {
                SetSelection((s32) Console_Execute(temp_r3_2415));
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsField'
s32 ScriptButtonGroup::LoadLine(UIDataLine *arg0) {
    s32 temp_r31_2454;

    if (arg0->IsField(&lit_stringBase0 + 0x28E) != 0) {
        temp_r31_2454 = arg0->GetString(0);
        this->unk80 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_2454);
        return 1;
    }
    return UIButtonGroup::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptButtonGroup::Deinit() {
    s8 *temp_r31_2483;

    temp_r31_2483 = this->unk80;
    if (temp_r31_2483 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_2483);
    }
    UIContainer::Deinit();
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ScriptButtonGroup::Init() {
    NoisyButtonGroup::Init();
    this->unk80 = NULL;
    this->unk84 = 0;
}
#endif

void NoisyButtonGroup::Update() {
    f32 temp_f1_2525;

    temp_f1_2525 = M2C_BITWISE(f32, this->unk6C.unk4);
    if (temp_f1_2525 > 0.0f) {
        this->unk6C.unk4 = temp_f1_2525 - gUpdateTimeDelta;
    }
    UIContainer::Update();
}

#if 0 // DRAFT: illegal operands 'void' != 'int'
void NoisyButtonGroup::Message(UIMessage *arg0) {
    s32 temp_r0_2548;

    temp_r0_2548 = arg0->unk0;
    if (temp_r0_2548 < 0xA) {
        if (temp_r0_2548 != 6) {

        } else {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_BITWISE(f32, this->unk6C.unk4) == 0.0f) {
                this->unk6C.unk4 = 0.15f;
                KDSound_Play(GS_MenuSelect, 0U, -1);
            }
        }
        goto block_10;
    }
    if (temp_r0_2548 < 0xC) {
        if (UIButtonGroup::Message(arg0) != 0) {
            KDSound_Play(GS_MenuMoveThru, 0U, -1);
            return 1;
        }
        return 0;
    }
block_10:
    return UIButtonGroup::Message(arg0);
}
#endif

void NoisyButtonGroup::Init() {
    UIButtonGroup::Init();
    this->unk6C.unk4 = 0.0f;
}

#if 0 // DRAFT: type mismatch
void GameText::Draw(const RenderContext &arg0) {
    s8 sp8;
    MKFont *temp_r0_2624;
    MKFont *temp_r25_2721;
    s32 temp_ret_2688;
    s8 *temp_r25_2673;
    s8 *temp_r27_2722;
    s8 *var_r0_2629;
    s8 *var_r28_2636;
    s8 *var_r29_2623;
    u8 temp_r3_2712;
    void *temp_r4_2660;
    void *var_r3_2663;

    var_r29_2623 = &sp8;
    temp_r0_2624 = this->unk64;
    if (temp_r0_2624 >= 0) {
        var_r0_2629 = *(gpTranslation_StringArray + ((s32) temp_r0_2624 * 4));
    } else {
        var_r0_2629 = this->unk60;
    }
    var_r28_2636 = var_r0_2629;
loop_17:
    temp_r3_2712 = (u8) M2C_FIELD(var_r28_2636, s8 *, 0);
    if ((s8) temp_r3_2712 != 0) {
        if ((s8) temp_r3_2712 == 0x25) {
            if ((s32) M2C_FIELD(var_r28_2636, u8 *, 1) == 0x25) {
                *var_r29_2623 = 0x25;
            } else if (strnicmp(var_r28_2636 + 1, &lit_stringBase0 + 0x296, 0xB) == 0) {
                temp_r4_2660 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
                if (temp_r4_2660 != NULL) {
                    var_r3_2663 = M2C_FIELD(temp_r4_2660, void **, 4);
                } else {
                    var_r3_2663 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
                }
                temp_r25_2673 = *(gpTranslation_StringArray + (M2C_FIELD(var_r3_2663, s32 *, 0x10) * 4));
                strcpy(var_r29_2623, temp_r25_2673);
                var_r28_2636 += 0xB;
                var_r29_2623 = &var_r29_2623[strlen(temp_r25_2673)] - 1;
            } else {
                temp_ret_2688 = strnicmp(var_r28_2636 + 1, &lit_stringBase0 + 0x2A2, 0xE);
                if (temp_ret_2688 == 0) {
                    var_r28_2636 += 0xE;
                    var_r29_2623 = &var_r29_2623[sprintf(var_r29_2623, &lit_stringBase0 + 0x2B1, GameData::gameData.unk164, M2C_BITWISE(f32, temp_ret_2688))] - 1;
                } else {
                    *var_r29_2623 = (s8) (u8) M2C_FIELD(var_r28_2636, s8 *, 0);
                }
            }
        } else {
            *var_r29_2623 = (s8) temp_r3_2712;
        }
        var_r29_2623 += 1;
        var_r28_2636 += 1;
        goto loop_17;
    }
    *var_r29_2623 = 0;
    temp_r25_2721 = this->unk64;
    temp_r27_2722 = this->unk60;
    this->unk64 = (MKFont *)-1;
    this->unk60 = &sp8;
    UIText::Draw(arg0);
    this->unk64 = temp_r25_2721;
    this->unk60 = temp_r27_2722;
}
#endif

void DSText::Init() {
    UIText::Init();
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void ScriptProgressBar::Message(UIMessage *arg0) {
    s32 temp_r0_2757;

    temp_r0_2757 = arg0->unk0;
    switch (temp_r0_2757) {                         /* irregular */
    case 8:
        M2C_FIELD(this, s8 *, 0xDC) = 1;
        break;
    case 9:
        M2C_FIELD(this, s8 *, 0xDC) = 0;
        break;
    case 1:
        M2C_FIELD(this, f32 *, 0xC8) = Console_Execute(M2C_BITWISE(s8 *, this->unkC8));
        break;
    }
    UIObject::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void ScriptProgressBar::Update() {
    UIImage::Update();
    if ((u8) M2C_FIELD(this, u8 *, 0xDC) != 0) {
        if (UIControls_DirectionPressed((FrontEndControls) 7, -1) != 0) {
            Console_Execute(this->unkD0);
        } else if (UIControls_DirectionPressed((FrontEndControls) 5, -1) != 0) {
            Console_Execute(this->unkD4);
        }
        M2C_FIELD(this, f32 *, 0xC8) = Console_Execute(M2C_BITWISE(s8 *, this->unkC8));
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsField'
s32 ScriptProgressBar::LoadLine(UIDataLine *arg0) {
    s32 temp_r31_2850;
    s32 temp_r31_2867;
    s32 temp_r31_2884;

    if (arg0->IsField(&lit_stringBase0 + 0x2B4) != 0) {
        temp_r31_2850 = arg0->GetString(0);
        this->unkC8 = M2C_BITWISE(f32, ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_2850));
        goto block_7;
    }
    if (arg0->IsField(&lit_stringBase0 + 0x2BF) != 0) {
        temp_r31_2867 = arg0->GetString(0);
        this->unkD4 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_2867);
        goto block_7;
    }
    if (arg0->IsField(&lit_stringBase0 + 0x2CB) != 0) {
        temp_r31_2884 = arg0->GetString(0);
        this->unkD0 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_2884);
block_7:
        return 1;
    }
    return ProgressBar::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptProgressBar::Deinit() {
    f32 temp_r31_2927;
    s8 *temp_r31_2913;
    s8 *temp_r31_2920;

    temp_r31_2913 = this->unkD0;
    if (temp_r31_2913 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_2913);
    }
    temp_r31_2920 = this->unkD4;
    if (temp_r31_2920 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_2920);
    }
    temp_r31_2927 = this->unkC8;
    if (M2C_BITWISE(u32, temp_r31_2927) != 0U) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(M2C_BITWISE(s8 *, temp_r31_2927));
    }
    UIImage::Deinit();
}
#endif

void ScriptProgressBar::Init() {
    ProgressBar::Init();
    this->unkC8 = 0.0f;
    this->unkD4 = NULL;
    this->unkD0 = NULL;
    M2C_FIELD(this, s8 *, 0xDC) = 0;
}

#if 0 // DRAFT: expression syntax error
void ProgressBar::Draw(const RenderContext &arg0) {
    f32 temp_r0_3003;

    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(this, f64 *, 0x80);
    this->unk18.unk8 = this->unk80;
    M2C_FIELD(this, f64 *, 0x28) = (f64) this->unk88;
    M2C_FIELD(this, f64 *, 0x30) = (f64) this->unk90;
    M2C_FIELD(this, f64 *, 0x38) = (f64) this->unk98;
    M2C_FIELD(this, f64 *, 0x40) = (f64) this->unkA0;
    this->unk18.unk30 = M2C_FIELD(this, f32 *, 0xB0);
    this->unk18.unk34 = M2C_FIELD(this, f32 *, 0xB4);
    this->unk18.unk38 = this->unkB0;
    this->unk18.unk3C = M2C_BITWISE(s32, this->unkB4);
    this->unk18.unk40 = M2C_FIELD(this, u16 *, 0xC0);
    SetUVs(0.0f, 0.0f, 1.0f, 0.5f);
    UIImage::Draw(arg0);
    temp_r0_3003 = this->unk70;
    switch (M2C_BITWISE(s32, temp_r0_3003)) {       /* irregular */
    case 0:
        this->unk18.unk34 *= M2C_FIELD(this, f32 *, 0xC8);
        SetUVs(0.0f, 0.5f, M2C_FIELD(this, f32 *, 0xC8), 1.0f);
        break;
    case 1:
        this->unk18.unk34 *= M2C_FIELD(this, f32 *, 0xC8);
        this->unk18.unk10.unk0 += M2C_FIELD(this, f32 *, 0xB4) - this->unk18.unk34;
        SetUVs(M2C_FIELD(this, f32 *, 0xC8), 0.5f, 0.0f, 1.0f);
        break;
    case 2:
        this->unk18.unk38 *= M2C_FIELD(this, f32 *, 0xC8);
        SetUVs(0.0f, 1.0f - M2C_FIELD(this, f32 *, 0xC8), 1.0f, 1.0f);
        break;
    }
    UIImage::Draw(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void ProgressBar::LoadDone() {
    M2C_FIELD(this, f64 *, 0x80) = (f64) M2C_FIELD(this, f64 *, 0x18);
    this->unk80 = this->unk18.unk8;
    this->unk88 = M2C_FIELD(this, f64 *, 0x28);
    this->unk90 = M2C_FIELD(this, f64 *, 0x30);
    this->unk98 = M2C_FIELD(this, f64 *, 0x38);
    this->unkA0 = M2C_FIELD(this, f64 *, 0x40);
    M2C_FIELD(this, f32 *, 0xB0) = (f32) this->unk18.unk30;
    M2C_FIELD(this, f32 *, 0xB4) = (f32) this->unk18.unk34;
    this->unkB0 = this->unk18.unk38;
    this->unkB4 = M2C_BITWISE(f32, this->unk18.unk3C);
    M2C_FIELD(this, u16 *, 0xC0) = (u16) this->unk18.unk40;
}
#endif

#if 0 // DRAFT: undefined identifier 'LoadString'
s32 ProgressBar::LoadLine(UIDataLine *arg0) {
    s8 *sp8;

    sp8 = NULL;
    if (arg0->LoadString(&lit_stringBase0 + 0x2D7, &sp8, 0) != 0) {
        if (stricmp(sp8, &lit_stringBase0 + 0x2E3) == 0) {
            this->unk70 = 0.0f;
        } else if (stricmp(sp8, &lit_stringBase0 + 0x2EF) == 0) {
            this->unk70 = 1e-45f;
        } else if (stricmp(sp8, &lit_stringBase0 + 0x2FB) == 0) {
            this->unk70 = 3e-45f;
        }
        return 1;
    }
    return UIImage::LoadLine(arg0);
}
#endif

void ProgressBar::Init() {
    UIImage::Init();
    M2C_FIELD(this, f32 *, 0xC8) = 1.0f;
    this->unk70 = 0.0f;
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptButton::SetOnDeselect(const char *arg0) {
    s8 *temp_r31_3190;

    temp_r31_3190 = this->unk90;
    if (temp_r31_3190 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_3190);
    }
    this->unk90 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptButton::SetOnSelect(const char *arg0) {
    s8 *temp_r31_3217;

    temp_r31_3217 = this->unk94;
    if (temp_r31_3217 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_3217);
    }
    this->unk94 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptButton::SetOnActivate(const char *arg0) {
    s8 *temp_r31_3244;

    temp_r31_3244 = this->unk80.unk8;
    if (temp_r31_3244 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_3244);
    }
    this->unk80.unk8 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'IsParentScreenActive'
void ScriptButton::OnDeselection() {
    UIButton::OnDeselection();
    if (((s8 *) this->unk90 != NULL) && (IsParentScreenActive((UIObject *) this) != 0)) {
        Console_Execute(this->unk90);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsParentScreenActive'
void ScriptButton::OnSelection() {
    UIButton::OnSelection();
    if (((s8 *) this->unk94 != NULL) && (IsParentScreenActive((UIObject *) this) != 0)) {
        Console_Execute(this->unk94);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsParentScreenActive'
void ScriptButton::OnActivate() {
    UIButton::OnActivate();
    if (((s8 *) this->unk80.unk8 != NULL) && (IsParentScreenActive((UIObject *) this) != 0)) {
        Console_Execute(this->unk80.unk8);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'IsField'
s32 ScriptButton::LoadLine(UIDataLine *arg0) {
    s32 temp_r31_3359;
    s32 temp_r31_3376;
    s32 temp_r31_3393;

    if (arg0->IsField(&lit_stringBase0 + 0x304) != 0) {
        temp_r31_3359 = arg0->GetString(0);
        this->unk80.unk8 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_3359);
        goto block_7;
    }
    if (arg0->IsField(&lit_stringBase0 + 0x313) != 0) {
        temp_r31_3376 = arg0->GetString(0);
        this->unk94 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_3376);
        goto block_7;
    }
    if (arg0->IsField(&lit_stringBase0 + 0x31C) != 0) {
        temp_r31_3393 = arg0->GetString(0);
        this->unk90 = ((UIStringTable *) (UIStringTable_GetCurrent()))->Add((s8 *) temp_r31_3393);
block_7:
        return 1;
    }
    return UIButton::LoadLine(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void ScriptButton::Deinit() {
    s8 *temp_r31_3422;
    s8 *temp_r31_3429;
    s8 *temp_r31_3436;

    temp_r31_3422 = this->unk90;
    if (temp_r31_3422 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_3422);
    }
    temp_r31_3429 = this->unk94;
    if (temp_r31_3429 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_3429);
    }
    temp_r31_3436 = this->unk80.unk8;
    if (temp_r31_3436 != NULL) {
        ((UIStringTable *) (UIStringTable_GetCurrent()))->Remove(temp_r31_3436);
    }
    UIContainer::Deinit();
}
#endif

void ScriptButton::Init() {
    UIContainer::Init();
    this->unk80.unk8 = NULL;
    this->unk94 = NULL;
    this->unk90 = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void OptionButton::Message(UIMessage *arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_3481;

    temp_r0_3481 = arg0->unk0;
    if ((u32) temp_r0_3481 <= 9U) {
        switch (temp_r0_3481) {
        case 0:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 9:
            break;
        case 1:
            if (((u8) this->unk15 != 0) && ((u8) this->unk16 != 0)) {
                sp14 = 2;
                Message(&sp14);
                M2C_FIELD(this, f32 *, 0x24) = 1.0f;
                this->unk18.unk30 = M2C_BITWISE(f32, this->unk98);
            } else {
                sp10 = 3;
                Message(&sp10);
                M2C_FIELD(this, f32 *, 0x24) = 0.0f;
                this->unk18.unk30 = 0.5f * M2C_BITWISE(f32, this->unk98);
            }
            break;
        case 4:
            if ((u8) this->unk16 != 0) {
                spC = 2;
                Message(&spC);
            }
            break;
        case 8:
            sp8 = 2;
            Message(&sp8);
            break;
        }
    }
    UIButton::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void OptionButton::Update() {
    s32 sp8;
    f32 temp_f0_3578;
    f32 temp_f0_3606;
    f32 temp_f2_3588;
    f32 var_f3_3577;
    f32 var_f3_3605;

    UIContainer::Update();
    if ((u8) this->unk14 != 0) {
        if (((u8) this->unk15 != 0) && ((u8) this->unk16 != 0)) {
            var_f3_3577 = 1.0f;
            temp_f0_3578 = (5.0f * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0x24);
            if (var_f3_3577 < temp_f0_3578) {

            } else {
                var_f3_3577 = temp_f0_3578;
            }
            M2C_FIELD(this, f32 *, 0x24) = var_f3_3577;
        } else {
            temp_f2_3588 = M2C_FIELD(this, f32 *, 0x24);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f2_3588 == 0.0f) {
                sp8 = 3;
                Message(&sp8);
            } else {
                var_f3_3605 = 0.0f;
                temp_f0_3606 = -((5.0f * gUpdateTimeDelta) - temp_f2_3588);
                if (var_f3_3605 > temp_f0_3606) {

                } else {
                    var_f3_3605 = temp_f0_3606;
                }
                M2C_FIELD(this, f32 *, 0x24) = var_f3_3605;
            }
        }
        this->unk18.unk30 = M2C_BITWISE(f32, this->unk98) * ((0.25f * M2C_FIELD(this, f32 *, 0x24)) + 0.75f);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void OptionButton::LoadDone() {
    this->unk98 = this->unk18.unk30;
    this->unk18.unk40 |= 9;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void OptionButton::Init() {
    ScriptButton::Init();
    this->unk98 = 1.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void ThrobButton::Message(UIMessage *arg0) {
    s32 temp_r0_3670;
    void *var_r31_3729;
    void *var_r31_3748;

    temp_r0_3670 = arg0->unk0;
    if ((u32) temp_r0_3670 <= 9U) {
        switch (temp_r0_3670) {
        case 1:
            if ((u8) this->unk15 == 0) {
                M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E0);
                this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E8);
            } else if ((u8) this->unk16 != 0) {
                M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F0);
                this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F8);
            } else {
                M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x200);
                this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x208);
            }
            break;
        case 4:
            if ((u8) this->unk16 != 0) {
                M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F0);
                this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F8);
            } else {
                M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x200);
                this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x208);
            }
            break;
        case 5:
            M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E0);
            this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E8);
            break;
        case 8:
            M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F0);
            this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F8);
            var_r31_3729 = this->unk60;
loop_13:
            if (var_r31_3729 != NULL) {
                M2C_FIELD(M2C_FIELD(var_r31_3729, void **, 0), M2C_UNK (**)(void *, UIMessage *), 0x2C)(var_r31_3729, arg0);
                var_r31_3729 = M2C_FIELD(var_r31_3729, void **, 0x10);
                goto loop_13;
            }
            break;
        case 9:
            M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x200);
            this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x208);
            var_r31_3748 = this->unk60;
loop_17:
            if (var_r31_3748 != NULL) {
                M2C_FIELD(M2C_FIELD(var_r31_3748, void **, 0), M2C_UNK (**)(void *, UIMessage *), 0x2C)(var_r31_3748, arg0);
                var_r31_3748 = M2C_FIELD(var_r31_3748, void **, 0x10);
                goto loop_17;
            }
            break;
        }
    }
    UIButton::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void ThrobButton::Update() {
    UIContainer::Update();
    if ((u8) this->unk15 == 0) {
        M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E0);
        this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E8);
        return;
    }
    if ((u8) this->unk16 != 0) {
        M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F0);
        this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F8);
        return;
    }
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&PromptText::descriptor, f64 *, 0x200);
    this->unk18.unk8 = M2C_FIELD(&PromptText::descriptor, f64 *, 0x208);
}
#endif

#if 0 // DRAFT: expression syntax error
void ThrobButton::LoadDone() {
    this->unk18.unk40 |= 9;
}
#endif

PromptGroup *FindPrompt(UIContainer *arg0) {
    UIObject *var_r3_3830;
    u8 var_r0_3837;
    void *var_r5_3833;

    var_r3_3830 = arg0->unk60;
loop_9:
    if (var_r3_3830 == NULL) {
        return NULL;
    }
    var_r5_3833 = var_r3_3830->unk8;
loop_2:
    if (var_r5_3833 == &PromptGroup::descriptor) {
        var_r0_3837 = 1;
    } else {
        var_r5_3833 = M2C_FIELD(var_r5_3833, void **, 4);
        if (var_r5_3833 == NULL) {
            var_r0_3837 = 0;
        } else {
            goto loop_2;
        }
    }
    if (var_r0_3837 != 0) {
        return ui_cast<PromptGroup *, UIObject *>(var_r3_3830);
    }
    var_r3_3830 = var_r3_3830->unk10;
    goto loop_9;
}

void PromptGroup::Reset() {
    f32 temp_f2_3933;
    f32 temp_f3_3883;
    f32 temp_f6_3916;
    f32 var_f2_3867;
    f32 var_f4_3887;
    f32 var_f5_3886;
    f32 var_f6_3904;
    s32 var_r5_3866;
    void *var_r4_3868;
    void *var_r6_3869;

    var_r5_3866 = 0;
    var_f2_3867 = 0.0f;
    var_r4_3868 = this->unk60;
    var_r6_3869 = var_r4_3868;
loop_4:
    if (var_r6_3869 != NULL) {
        if ((u8) M2C_FIELD(var_r6_3869, u8 *, 0x14) != 0) {
            var_r5_3866 += 1;
            var_f2_3867 += M2C_FIELD(var_r6_3869, f32 *, 0x4C);
        }
        var_r6_3869 = M2C_FIELD(var_r6_3869, void **, 0x10);
        goto loop_4;
    }
    temp_f3_3883 = this->unk18.unk34;
    if (var_f2_3867 > temp_f3_3883) {
        var_f5_3886 = temp_f3_3883 / var_f2_3867;
        var_f4_3887 = 0.0f;
    } else {
        var_f5_3886 = 1.0f;
        var_f4_3887 = (temp_f3_3883 - var_f2_3867) / (f32) (var_r5_3866 + 1);
    }
    var_f6_3904 = (0.5f * var_f4_3887) - (temp_f3_3883 * 0.5f);
loop_15:
    if (var_r4_3868 != NULL) {
        if ((u8) M2C_FIELD(var_r4_3868, u8 *, 0x14) != 0) {
            M2C_FIELD(var_r4_3868, f32 *, 0x48) = var_f5_3886;
            temp_f6_3916 = (0.5f * ((M2C_FIELD(var_r4_3868, f32 *, 0x4C) * var_f5_3886) + var_f4_3887)) + var_f6_3904;
            if (M2C_FIELD(var_r4_3868, f32 *, 0x48) != 1.0f) {
                M2C_FIELD(var_r4_3868, u16 *, 0x58) = (u16) (M2C_FIELD(var_r4_3868, u16 *, 0x58) | 8);
            } else {
                M2C_FIELD(var_r4_3868, u16 *, 0x58) = (u16) (M2C_FIELD(var_r4_3868, u16 *, 0x58) & 0xFFFFFFF7);
            }
            M2C_FIELD(var_r4_3868, f32 *, 0x2C) = 0.0f;
            M2C_FIELD(var_r4_3868, f32 *, 0x28) = temp_f6_3916;
            temp_f2_3933 = M2C_FIELD(var_r4_3868, f32 *, 0x4C);
            var_f6_3904 = (0.5f * ((temp_f2_3933 * var_f5_3886) + var_f4_3887)) + temp_f6_3916;
            M2C_FIELD(var_r4_3868, f32 *, 0x4C) = (f32) (temp_f2_3933 + (var_f4_3887 / var_f5_3886));
        }
        var_r4_3868 = M2C_FIELD(var_r4_3868, void **, 0x10);
        goto loop_15;
    }
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
void PromptGroup::Message(UIMessage *arg0) {
    UIContainer::Message(arg0);
    if ((s32) arg0->unk0 != 1) {

    } else {
        Reset();
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void PromptText::Message(UIMessage *arg0) {
    f32 temp_r4_3987;

    if ((s32) arg0->unk0 != 1) {

    } else {
        temp_r4_3987 = this->unk70;
        if (M2C_BITWISE(s32, temp_r4_3987) > -1) {
            this->unk18.unk34 = 20.0f + this->unk64->CalcLength(Str_Printf(&lit_stringBase0 + 0x327, buttonString[M2C_BITWISE(s32, temp_r4_3987)], *(gpTranslation_StringArray + ((s32) this->unk64 * 4)), &lit_stringBase0));
        }
    }
    UIObject::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void PromptText::Draw(const RenderContext &arg0) {
    MKFont *temp_r31_4030;
    f32 temp_r6_4029;
    s8 *temp_r30_4032;

    temp_r6_4029 = this->unk70;
    temp_r31_4030 = this->unk64;
    temp_r30_4032 = this->unk60;
    if (M2C_BITWISE(s32, temp_r6_4029) >= 0) {
        this->unk60 = Str_Printf(&lit_stringBase0 + 0x327, buttonString[M2C_BITWISE(s32, temp_r6_4029)], *(gpTranslation_StringArray + ((s32) temp_r31_4030 * 4)), M2C_BITWISE(s32, temp_r6_4029) * 4, &lit_stringBase0);
        this->unk64 = (MKFont *)-1;
    }
    UIText::Draw(arg0);
    this->unk60 = temp_r30_4032;
    this->unk64 = temp_r31_4030;
}
#endif

#if 0 // DRAFT: undefined identifier 'nanf'
void PromptText::Resolve() {
    f32 temp_r0_4087;

    UIObject::Resolve();
    this->unk70 = 0.0f;
loop_3:
    temp_r0_4087 = this->unk70;
    if (M2C_BITWISE(s32, temp_r0_4087) >= 7) {
        this->unk70 = nanf;
    } else if (stricmp((s8 *) this->unk4, buttonLabel[M2C_BITWISE(s32, temp_r0_4087)]) != 0) {
        this->unk70 = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unk70) + 1));
        goto loop_3;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'nanf'
void PromptText::Init() {
    DSText::Init();
    this->unk70 = nanf;
}
#endif

#if 0 // DRAFT: expression syntax error
void UITools_RegisterAll() {
    MCLoadCheckScreen *temp_r3_4438;
    MCLoadCheckScreen *temp_r4_4131;
    MCLoadCheckScreen *temp_r4_4147;
    MCLoadCheckScreen *temp_r4_4163;
    MCLoadCheckScreen *temp_r4_4179;
    MCLoadCheckScreen *temp_r4_4195;
    MCLoadCheckScreen *temp_r4_4211;
    MCLoadCheckScreen *temp_r4_4227;
    MCLoadCheckScreen *temp_r4_4243;
    MCLoadCheckScreen *temp_r4_4246;
    MCLoadCheckScreen *temp_r4_4259;
    MCLoadCheckScreen *temp_r4_4262;
    MCLoadCheckScreen *temp_r4_4275;
    MCLoadCheckScreen *temp_r4_4278;
    MCLoadCheckScreen *temp_r4_4291;
    MCLoadCheckScreen *temp_r4_4294;
    MCLoadCheckScreen *temp_r4_4307;
    MCLoadCheckScreen *temp_r4_4310;
    MCLoadCheckScreen *temp_r4_4323;
    MCLoadCheckScreen *temp_r4_4326;
    MCLoadCheckScreen *temp_r4_4339;
    MCLoadCheckScreen *temp_r4_4342;
    MCLoadCheckScreen *temp_r4_4355;
    MCLoadCheckScreen *temp_r4_4358;
    MCLoadCheckScreen *temp_r4_4371;
    MCLoadCheckScreen *temp_r4_4374;
    MCLoadCheckScreen *temp_r4_4387;
    MCLoadCheckScreen *temp_r4_4390;
    MCLoadCheckScreen *temp_r4_4403;
    MCLoadCheckScreen *temp_r4_4406;
    MCLoadCheckScreen *temp_r4_4419;
    MCLoadCheckScreen *temp_r4_4422;
    MCLoadCheckScreen *temp_r5_4435;
    UIObjectDescriptor *var_r4_4428;
    UIObjectDescriptor *var_r5_4122;
    UIObjectDescriptor *var_r5_4140;
    UIObjectDescriptor *var_r5_4156;
    UIObjectDescriptor *var_r5_4172;
    UIObjectDescriptor *var_r5_4188;
    UIObjectDescriptor *var_r5_4204;
    UIObjectDescriptor *var_r5_4220;
    UIObjectDescriptor *var_r5_4236;
    UIObjectDescriptor *var_r5_4252;
    UIObjectDescriptor *var_r5_4268;
    UIObjectDescriptor *var_r5_4284;
    UIObjectDescriptor *var_r5_4300;
    UIObjectDescriptor *var_r5_4316;
    UIObjectDescriptor *var_r5_4332;
    UIObjectDescriptor *var_r5_4348;
    UIObjectDescriptor *var_r5_4364;
    UIObjectDescriptor *var_r5_4380;
    UIObjectDescriptor *var_r5_4396;
    UIObjectDescriptor *var_r5_4412;

    var_r5_4122 = &UIObjectDescriptor::list;
loop_3:
    temp_r4_4131 = var_r5_4122->unk0;
    if (temp_r4_4131 == NULL) {
        var_r5_4122->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor;
        PromptText::descriptor.unk10 = NULL;
    } else if (temp_r4_4131 != &PromptText::descriptor) {
        var_r5_4122 = (UIObjectDescriptor *) &temp_r4_4131->unk10;
        goto loop_3;
    }
    var_r5_4140 = &UIObjectDescriptor::list;
loop_8:
    temp_r4_4147 = var_r5_4140->unk0;
    if (temp_r4_4147 == NULL) {
        var_r5_4140->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor.unk14;
        M2C_FIELD(&PromptText::descriptor, s32 *, 0x24) = 0;
    } else if (temp_r4_4147 != &PromptText::descriptor.unk14) {
        var_r5_4140 = (UIObjectDescriptor *) &temp_r4_4147->unk10;
        goto loop_8;
    }
    var_r5_4156 = &UIObjectDescriptor::list;
loop_13:
    temp_r4_4163 = var_r5_4156->unk0;
    if (temp_r4_4163 == NULL) {
        var_r5_4156->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor.unk18.unk10;
        PromptText::descriptor.unk18.unk20.unk0 = 0.0f;
    } else if (temp_r4_4163 != &PromptText::descriptor.unk18.unk10) {
        var_r5_4156 = (UIObjectDescriptor *) &temp_r4_4163->unk10;
        goto loop_13;
    }
    var_r5_4172 = &UIObjectDescriptor::list;
loop_18:
    temp_r4_4179 = var_r5_4172->unk0;
    if (temp_r4_4179 == NULL) {
        var_r5_4172->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor.unk18.unk20.unk4;
        PromptText::descriptor.unk18.unk34 = 0.0f;
    } else if (temp_r4_4179 != &PromptText::descriptor.unk18.unk20.unk4) {
        var_r5_4172 = (UIObjectDescriptor *) &temp_r4_4179->unk10;
        goto loop_18;
    }
    var_r5_4188 = &UIObjectDescriptor::list;
loop_23:
    temp_r4_4195 = var_r5_4188->unk0;
    if (temp_r4_4195 == NULL) {
        var_r5_4188->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor.unk18.unk38;
        PromptText::descriptor.unk60 = 0;
    } else if (temp_r4_4195 != &PromptText::descriptor.unk18.unk38) {
        var_r5_4188 = (UIObjectDescriptor *) &temp_r4_4195->unk10;
        goto loop_23;
    }
    var_r5_4204 = &UIObjectDescriptor::list;
loop_28:
    temp_r4_4211 = var_r5_4204->unk0;
    if (temp_r4_4211 == NULL) {
        var_r5_4204->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor.unk64;
        PromptText::descriptor.unk6C = 0;
    } else if (temp_r4_4211 != &PromptText::descriptor.unk64) {
        var_r5_4204 = (UIObjectDescriptor *) &temp_r4_4211->unk10;
        goto loop_28;
    }
    var_r5_4220 = &UIObjectDescriptor::list;
loop_33:
    temp_r4_4227 = var_r5_4220->unk0;
    if (temp_r4_4227 == NULL) {
        var_r5_4220->unk0 = (MCLoadCheckScreen *) &PromptText::descriptor.unk70;
        M2C_FIELD(&PromptText::descriptor, s32 *, 0x88) = 0;
    } else if (temp_r4_4227 != &PromptText::descriptor.unk70) {
        var_r5_4220 = (UIObjectDescriptor *) &temp_r4_4227->unk10;
        goto loop_33;
    }
    var_r5_4236 = &UIObjectDescriptor::list;
loop_38:
    temp_r4_4243 = var_r5_4236->unk0;
    if (temp_r4_4243 == NULL) {
        temp_r4_4246 = &PromptText::descriptor + 0x8C;
        var_r5_4236->unk0 = temp_r4_4246;
        temp_r4_4246->unk10 = NULL;
    } else if (temp_r4_4243 != (void *) (&PromptText::descriptor + 0x8C)) {
        var_r5_4236 = (UIObjectDescriptor *) &temp_r4_4243->unk10;
        goto loop_38;
    }
    var_r5_4252 = &UIObjectDescriptor::list;
loop_43:
    temp_r4_4259 = var_r5_4252->unk0;
    if (temp_r4_4259 == NULL) {
        temp_r4_4262 = &PromptText::descriptor + 0xA0;
        var_r5_4252->unk0 = temp_r4_4262;
        temp_r4_4262->unk10 = NULL;
    } else if (temp_r4_4259 != (void *) (&PromptText::descriptor + 0xA0)) {
        var_r5_4252 = (UIObjectDescriptor *) &temp_r4_4259->unk10;
        goto loop_43;
    }
    var_r5_4268 = &UIObjectDescriptor::list;
loop_48:
    temp_r4_4275 = var_r5_4268->unk0;
    if (temp_r4_4275 == NULL) {
        temp_r4_4278 = &PromptText::descriptor + 0xB4;
        var_r5_4268->unk0 = temp_r4_4278;
        temp_r4_4278->unk10 = NULL;
    } else if (temp_r4_4275 != (void *) (&PromptText::descriptor + 0xB4)) {
        var_r5_4268 = (UIObjectDescriptor *) &temp_r4_4275->unk10;
        goto loop_48;
    }
    var_r5_4284 = &UIObjectDescriptor::list;
loop_53:
    temp_r4_4291 = var_r5_4284->unk0;
    if (temp_r4_4291 == NULL) {
        temp_r4_4294 = &PromptText::descriptor + 0xC8;
        var_r5_4284->unk0 = temp_r4_4294;
        temp_r4_4294->unk10 = NULL;
    } else if (temp_r4_4291 != (void *) (&PromptText::descriptor + 0xC8)) {
        var_r5_4284 = (UIObjectDescriptor *) &temp_r4_4291->unk10;
        goto loop_53;
    }
    var_r5_4300 = &UIObjectDescriptor::list;
loop_58:
    temp_r4_4307 = var_r5_4300->unk0;
    if (temp_r4_4307 == NULL) {
        temp_r4_4310 = &PromptText::descriptor + 0xDC;
        var_r5_4300->unk0 = temp_r4_4310;
        temp_r4_4310->unk10 = NULL;
    } else if (temp_r4_4307 != (void *) (&PromptText::descriptor + 0xDC)) {
        var_r5_4300 = (UIObjectDescriptor *) &temp_r4_4307->unk10;
        goto loop_58;
    }
    var_r5_4316 = &UIObjectDescriptor::list;
loop_63:
    temp_r4_4323 = var_r5_4316->unk0;
    if (temp_r4_4323 == NULL) {
        temp_r4_4326 = &PromptText::descriptor + 0x104;
        var_r5_4316->unk0 = temp_r4_4326;
        temp_r4_4326->unk10 = NULL;
    } else if (temp_r4_4323 != (void *) (&PromptText::descriptor + 0x104)) {
        var_r5_4316 = (UIObjectDescriptor *) &temp_r4_4323->unk10;
        goto loop_63;
    }
    var_r5_4332 = &UIObjectDescriptor::list;
loop_68:
    temp_r4_4339 = var_r5_4332->unk0;
    if (temp_r4_4339 == NULL) {
        temp_r4_4342 = &PromptText::descriptor + 0x118;
        var_r5_4332->unk0 = temp_r4_4342;
        temp_r4_4342->unk10 = NULL;
    } else if (temp_r4_4339 != (void *) (&PromptText::descriptor + 0x118)) {
        var_r5_4332 = (UIObjectDescriptor *) &temp_r4_4339->unk10;
        goto loop_68;
    }
    var_r5_4348 = &UIObjectDescriptor::list;
loop_73:
    temp_r4_4355 = var_r5_4348->unk0;
    if (temp_r4_4355 == NULL) {
        temp_r4_4358 = &PromptText::descriptor + 0x12C;
        var_r5_4348->unk0 = temp_r4_4358;
        temp_r4_4358->unk10 = NULL;
    } else if (temp_r4_4355 != (void *) (&PromptText::descriptor + 0x12C)) {
        var_r5_4348 = (UIObjectDescriptor *) &temp_r4_4355->unk10;
        goto loop_73;
    }
    var_r5_4364 = &UIObjectDescriptor::list;
loop_78:
    temp_r4_4371 = var_r5_4364->unk0;
    if (temp_r4_4371 == NULL) {
        temp_r4_4374 = &PromptText::descriptor + 0x140;
        var_r5_4364->unk0 = temp_r4_4374;
        temp_r4_4374->unk10 = NULL;
    } else if (temp_r4_4371 != (void *) (&PromptText::descriptor + 0x140)) {
        var_r5_4364 = (UIObjectDescriptor *) &temp_r4_4371->unk10;
        goto loop_78;
    }
    var_r5_4380 = &UIObjectDescriptor::list;
loop_83:
    temp_r4_4387 = var_r5_4380->unk0;
    if (temp_r4_4387 == NULL) {
        temp_r4_4390 = &PromptText::descriptor + 0x154;
        var_r5_4380->unk0 = temp_r4_4390;
        temp_r4_4390->unk10 = NULL;
    } else if (temp_r4_4387 != (void *) (&PromptText::descriptor + 0x154)) {
        var_r5_4380 = (UIObjectDescriptor *) &temp_r4_4387->unk10;
        goto loop_83;
    }
    var_r5_4396 = &UIObjectDescriptor::list;
loop_88:
    temp_r4_4403 = var_r5_4396->unk0;
    if (temp_r4_4403 == NULL) {
        temp_r4_4406 = &PromptText::descriptor + 0x168;
        var_r5_4396->unk0 = temp_r4_4406;
        temp_r4_4406->unk10 = NULL;
    } else if (temp_r4_4403 != (void *) (&PromptText::descriptor + 0x168)) {
        var_r5_4396 = (UIObjectDescriptor *) &temp_r4_4403->unk10;
        goto loop_88;
    }
    var_r5_4412 = &UIObjectDescriptor::list;
loop_93:
    temp_r4_4419 = var_r5_4412->unk0;
    if (temp_r4_4419 == NULL) {
        temp_r4_4422 = &PromptText::descriptor + 0x17C;
        var_r5_4412->unk0 = temp_r4_4422;
        temp_r4_4422->unk10 = NULL;
    } else if (temp_r4_4419 != (void *) (&PromptText::descriptor + 0x17C)) {
        var_r5_4412 = (UIObjectDescriptor *) &temp_r4_4419->unk10;
        goto loop_93;
    }
    var_r4_4428 = &UIObjectDescriptor::list;
loop_98:
    temp_r5_4435 = var_r4_4428->unk0;
    if (temp_r5_4435 == NULL) {
        temp_r3_4438 = &PromptText::descriptor + 0x190;
        var_r4_4428->unk0 = temp_r3_4438;
        temp_r3_4438->unk10 = NULL;
        return;
    }
    if (temp_r5_4435 != (void *) (&PromptText::descriptor + 0x190)) {
        var_r4_4428 = (UIObjectDescriptor *) &temp_r5_4435->unk10;
        goto loop_98;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'UISystem *' to
u8 IsParentScreenActive(UIObject *arg0) {
    UIObject *var_r30_4452;
    u32 temp_r31_4458;
    void **temp_r3_4454;

    var_r30_4452 = arg0;
    temp_r3_4454 = ui_cast<UISystem *, UIContainer *>(arg0->GetRoot());
    temp_r31_4458 = M2C_FIELD((temp_r3_4454 + (M2C_FIELD(temp_r3_4454, s32 *, 0x6C) * 4)), u32 *, 0x70);
    if (temp_r31_4458 == 0U) {
        return 0U;
    }
loop_6:
    if (var_r30_4452 == NULL) {
        return 0U;
    }
    if (ui_cast<UIScreen *, UIContainer *>(var_r30_4452->unkC) == temp_r31_4458) {
        return 1U;
    }
    var_r30_4452 = (UIObject *) var_r30_4452->unkC;
    goto loop_6;
}
#endif

void UITools_cpp::__sinit() {
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

    sp48 = 0.3f;
    sp4C = 0.3f;
    sp50 = 0.3f;
    sp54 = 1.0f;
    sp38 = 1.0f;
    sp3C = 1.0f;
    sp40 = 1.0f;
    sp44 = 1.0f;
    sp28 = 0.625f;
    sp2C = 0.625f;
    sp30 = 0.625f;
    sp34 = 1.0f;
    sp18 = 0.1569f;
    sp1C = 0.6f;
    sp20 = 0.9372f;
    sp24 = 0.3f;
    sp8 = 1.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.3f;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E0) = (f64) sp48;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x1E8) = (f64) sp50;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F0) = (f64) sp38;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x1F8) = (f64) sp40;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x200) = (f64) sp28;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x208) = (f64) sp30;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x210) = (f64) sp18;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x218) = (f64) sp20;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x220) = (f64) sp8;
    M2C_FIELD(&PromptText::descriptor, f64 *, 0x228) = (f64) sp10;
}

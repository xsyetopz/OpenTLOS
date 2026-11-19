#include "spyro/source/LevelSelect.h"
#include "common/Source/MKHeap.h"
#include "spyro/source/GameData.h"
#include "spyro/source/Level.h"
#include "spyro/source/MenuItem.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

M2C_UNK free(UIObject *);                           /* extern */
UIObject *malloc(s32);                              /* extern */
extern s32 GS_MenuCancel;
extern s32 GS_MenuSelect;
extern u8 bZ3AttractHack;
extern M2C_UNK gb;
extern s32 gpTranslation_StringArray;
extern UIObject *pMenuCurrent;
extern UIObject *pMenuRoot;
#if 0 // DRAFT: expression syntax error
u8 descriptor__18LevelSelectButtons[0x14];          /* unable to generate initializer: cannot parse "LevelSelectButtons" as integer */
u8 descriptor__11LevelButton[0x14];                 /* unable to generate initializer: cannot parse .L_8035BD7D as integer */
static s8 *pFontName = .L_8035BD89;
#endif
#if 0 // DRAFT: declaration syntax error
static s8 .L_8035BD89[0x17] = {
    0x66,
    0x6F,
    0x6E,
    0x74,
    0x5F,
    0x67,
    0x61,
    0x6D,
    0x65,
    0,
    0x4C,
    0x65,
    0x76,
    0x65,
    0x6C,
    0x42,
    0x75,
    0x74,
    0x74,
    0x6F,
    0x6E,
    0x73,
    0,
}; /* const */

void LevelSelectScreen::Populate() {
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
    UIContainer *var_r29_20;
    f32 var_r28_23;
    s32 var_r27_22;
    s32 var_r31_21;
    void **temp_r3_107;

    var_r29_20 = ui_cast<LevelButton *, UIObject *>(M2C_FIELD(this->unkC8, UIObject **, 0x60));
    var_r31_21 = 0;
    var_r27_22 = 0;
    var_r28_23 = pMenuCurrent->unk18.unk10.unkC;
loop_7:
    if (var_r29_20 != NULL) {
        if (M2C_BITWISE(u32, var_r28_23) == 0U) {

        } else {
            if ((((MenuItem *) (M2C_BITWISE(MenuItem *, var_r28_23)))->Enabled() != 0) && (var_r29_20 != NULL)) {
                M2C_FIELD(ui_cast<DSText *, UIObject *>(var_r29_20->GetChild(0)), f32 *, 0x68) = var_r28_23;
                M2C_FIELD(var_r29_20, f32 *, 0xA0) = var_r28_23;
                sp20 = 4;
                sp24 = 0;
                var_r29_20->Message(&sp20, 4);
                sp18 = 2;
                sp1C = 0;
                var_r29_20->Message(&sp18);
                var_r29_20 = ui_cast<LevelButton *, UIObject *>(var_r29_20->unk10);
                if (M2C_BITWISE(u32, var_r28_23) == M2C_BITWISE(u32, pMenuCurrent->unk18.unk20.unk4)) {
                    var_r31_21 = var_r27_22;
                }
                var_r27_22 += 1;
            }
            var_r28_23 = M2C_FIELD(var_r28_23, f32 *, 0x30);
            goto loop_7;
        }
    }
loop_11:
    if (var_r29_20 != NULL) {
        sp10 = 5;
        sp14 = 0;
        var_r29_20->Message(&sp10);
        sp8 = 3;
        spC = 0;
        var_r29_20->Message(&sp8);
        var_r29_20 = ui_cast<LevelButton *, UIObject *>(var_r29_20->unk10);
        goto loop_11;
    }
    sp2C = var_r31_21;
    sp28 = 1;
    temp_r3_107 = this->unkC8;
    M2C_FIELD(*temp_r3_107, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_107, &sp28);
}
#endif

void LevelSelectScreen::Draw(const RenderContext &arg0) {
    UIContainer::Draw(arg0);
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void LevelSelectScreen::Update() {
    s32 spC;
    s32 sp8;
    ChunkInfo *var_r31_326;
    UIContainer *temp_r3_302;
    UIContainer *temp_r3_376;
    f32 temp_r0_360;
    f32 temp_r4_322;
    void **temp_r3_299;
    void *temp_r3_323;

    UIScreen::Update();
    temp_r3_299 = this->unkC8;
    temp_r3_302 = ui_cast<LevelButton *, UIObject *>(((UIContainer *) temp_r3_299)->GetChild(M2C_FIELD(temp_r3_299, s32 *, 0x68)));
    pMenuCurrent->unk18.unk20.unk4 = M2C_FIELD(temp_r3_302, f32 *, 0xA0);
    if ((UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) || (UIControls_Pressed((FrontEndControls) 3, -1) != 0)) {
        KDSound_Play(GS_MenuSelect, 0U, -1);
        temp_r4_322 = M2C_FIELD(temp_r3_302, f32 *, 0xA0);
        temp_r3_323 = M2C_FIELD(temp_r4_322, void **, 0x28);
        if (temp_r3_323 != NULL) {
            var_r31_326 = M2C_FIELD(temp_r3_323, ChunkInfo **, 0x114);
        } else {
            var_r31_326 = M2C_FIELD(temp_r4_322, ChunkInfo **, 0x2C);
        }
        if (var_r31_326 != NULL) {
            bZ3AttractHack = 0;
            M2C_FIELD(&gb, s8 *, 0x334) = 1;
            ((GameData *) GameData::gameData)->ClearData();
            ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SwitchTo(var_r31_326);
            return;
        }
        pMenuCurrent = M2C_BITWISE(UIObject *, temp_r4_322);
        Populate();
        return;
    }
    if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
        temp_r0_360 = pMenuCurrent->unk18.unk20.unk0;
        if (M2C_BITWISE(u32, temp_r0_360) != 0U) {
            pMenuCurrent = M2C_BITWISE(UIObject *, temp_r0_360);
            KDSound_Play(GS_MenuCancel, 0U, -1);
            Populate();
            return;
        }
        if ((u8) bZ3AttractHack == 0) {
            temp_r3_376 = GetRoot();
            sp8 = 0xF;
            spC = 0;
            M2C_FIELD(temp_r3_376->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
}
#endif

void LevelSelectScreen::OnEnter() {
    UIScreen::OnEnter();
    pMenuCurrent = pMenuRoot;
    Populate();
}

#if 0 // DRAFT: illegal implicit conversion from 'LevelSelectButtons *' to
void LevelSelectScreen::LoadDone() {
    this->unkC8 = ui_cast<LevelSelectButtons *, UIObject *>(FindChild("LevelButtons"));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void LevelSelectScreen::Deinit() {
    MKHeap *temp_r3_446;
    UIContainer *var_r30_468;
    UIObject *temp_r31_443;

    temp_r31_443 = pMenuRoot;
    if (temp_r31_443 != NULL) {
        temp_r3_446 = MKHeap::Current();
        if (temp_r3_446 != NULL) {
            ((MKHeap *) (temp_r3_446->Current()))->Free(temp_r31_443, NULL, 0);
        } else {
            free(temp_r31_443);
        }
        pMenuRoot = NULL;
    }
    pMenuCurrent = NULL;
    var_r30_468 = ui_cast<LevelButton *, UIObject *>(M2C_FIELD(this->unkC8, UIObject **, 0x60));
loop_7:
    if (var_r30_468 != NULL) {
        M2C_FIELD(ui_cast<DSText *, UIObject *>(var_r30_468->GetChild(0)), s32 *, 0x68) = 0;
        var_r30_468 = ui_cast<LevelButton *, UIObject *>(var_r30_468->unk10);
        goto loop_7;
    }
    UIContainer::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void LevelSelectScreen::Init() {
    MKHeap *temp_r3_504;
    UIObject *var_r3_511;
    f32 temp_r5_537;
    f32 var_r4_541;
    s32 temp_r27_503;
    s32 var_r27_561;
    s32 var_r28_524;
    s32 var_r31_522;
    void *temp_r0_546;
    void *temp_r0_590;
    void *temp_r26_562;
    void *temp_r3_538;
    void *temp_r3_583;
    void *temp_r5_580;
    void *var_r0_612;
    void *var_r29_560;
    void *var_r30_523;
    void *var_r4_585;

    UIContainer::Init();
    temp_r27_503 = (*Level::levelInfoCount + (*Level::chunkInfoCount + 1)) << 6;
    temp_r3_504 = ((MKHeap *) (*Level::chunkInfoCount))->Current();
    if (temp_r3_504 != NULL) {
        var_r3_511 = ((MKHeap *) (temp_r3_504->Current()))->Alloc(temp_r27_503, NULL, 0);
    } else {
        var_r3_511 = malloc(temp_r27_503);
    }
    pMenuRoot = var_r3_511;
    memset(var_r3_511, 0, (u32) temp_r27_503);
    var_r31_522 = 1;
    var_r30_523 = *Level::pLevelInfo;
    var_r28_524 = 0x40;
    pMenuCurrent = pMenuRoot;
loop_26:
    if (var_r30_523 != NULL) {
        strncpy(pMenuRoot + var_r28_524, *(gpTranslation_StringArray + (M2C_FIELD(var_r30_523, s32 *, 0x10) * 4)), 0x28U);
        temp_r5_537 = pMenuRoot->unk18.unk10.unkC;
        temp_r3_538 = pMenuRoot + var_r28_524;
        if (M2C_BITWISE(u32, temp_r5_537) != 0U) {
            var_r4_541 = temp_r5_537;
loop_7:
            temp_r0_546 = M2C_FIELD(var_r4_541, void **, 0x30);
            if (temp_r0_546 != NULL) {
                var_r4_541 = M2C_BITWISE(f32, temp_r0_546);
                goto loop_7;
            }
            M2C_FIELD(var_r4_541, void **, 0x30) = temp_r3_538;
            M2C_FIELD(temp_r3_538, UIObject **, 0x38) = (UIObject *) M2C_FIELD(temp_r5_537, UIObject **, 0x38);
        } else {
            pMenuRoot->unk18.unk10.unkC = M2C_BITWISE(f32, temp_r3_538);
            M2C_FIELD(pMenuRoot->unk18.unk10.unkC, UIObject **, 0x38) = (UIObject *) pMenuRoot;
        }
        var_r31_522 += 1;
        var_r29_560 = M2C_FIELD(var_r30_523, void **, 0x11C);
        var_r27_561 = var_r31_522 << 6;
        temp_r26_562 = pMenuRoot + var_r28_524;
        var_r28_524 += 0x40;
loop_21:
        if (var_r29_560 != NULL) {
            if ((var_r29_560 != (u32) M2C_FIELD(var_r30_523, u32 *, 0x118)) && ((u8) M2C_FIELD(var_r29_560, u8 *, 0x36) != 0)) {
                strncpy(pMenuRoot + var_r27_561, M2C_FIELD(var_r29_560, s8 **, 0), 0x28U);
                *(pMenuRoot + (var_r27_561 + 0x2C)) = var_r29_560;
                temp_r5_580 = M2C_FIELD(temp_r26_562, void **, 0x34);
                temp_r3_583 = pMenuRoot + var_r27_561;
                if (temp_r5_580 != NULL) {
                    var_r4_585 = temp_r5_580;
loop_16:
                    temp_r0_590 = M2C_FIELD(var_r4_585, void **, 0x30);
                    if (temp_r0_590 != NULL) {
                        var_r4_585 = temp_r0_590;
                        goto loop_16;
                    }
                    M2C_FIELD(var_r4_585, void **, 0x30) = temp_r3_583;
                    M2C_FIELD(temp_r3_583, void **, 0x38) = (void *) M2C_FIELD(temp_r5_580, void **, 0x38);
                } else {
                    M2C_FIELD(temp_r26_562, void **, 0x34) = temp_r3_583;
                    M2C_FIELD(M2C_FIELD(temp_r26_562, void **, 0x34), void **, 0x38) = temp_r26_562;
                }
                var_r31_522 += 1;
                var_r28_524 += 0x40;
                var_r27_561 += 0x40;
            }
            var_r29_560 = M2C_FIELD(var_r29_560, void **, 8);
            goto loop_21;
        }
        if (var_r30_523 != NULL) {
            var_r0_612 = M2C_FIELD(var_r30_523, void **, 0x124);
        } else {
            var_r0_612 = *Level::pLevelInfo;
        }
        var_r30_523 = var_r0_612;
        goto loop_26;
    }
    pMenuCurrent = pMenuRoot;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void LevelSelectButtons::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_665;
    MKHeap *temp_r3_721;
    UIContainer *temp_r25_696;
    UIContainer *temp_r3_691;
    UIObject *temp_r3_747;
    UIObject *var_r27_673;
    UIObject *var_r27_729;
    s32 temp_r27_664;
    s32 temp_r27_720;
    s32 var_r29_658;
    s8 *temp_r27_750;
    s8 *temp_r3_749;

    MarkerButtonGroup::Init();
    var_r29_658 = 0;
    do {
        temp_r27_664 = M2C_FIELD(LevelButton::descriptor, s32 *, 8);
        temp_r3_665 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_665 != NULL) {
            var_r27_673 = ((MKHeap *) (temp_r3_665->Current()))->Alloc(temp_r27_664, NULL, 0);
        } else {
            var_r27_673 = malloc(temp_r27_664);
        }
        M2C_FIELD(LevelButton::descriptor, M2C_UNK (**)(UIObject *), 0xC)(var_r27_673);
        var_r27_673->unk8 = LevelButton::descriptor;
        var_r27_673->Init();
        temp_r3_691 = ui_cast<LevelButton *, UIObject *>(var_r27_673);
        temp_r25_696 = temp_r3_691;
        sp8 = 0.0f;
        sp10 = 0.0f;
        temp_r3_691->unk18.unk40 = 0x23;
        spC = (40.0f * (f32) var_r29_658) + 38.399994f;
        sp20 = (f64) sp10;
        M2C_FIELD(temp_r3_691, f64 *, 0x28) = (f64) sp8;
        M2C_FIELD(temp_r3_691, f64 *, 0x30) = (f64) sp10;
        temp_r3_691->unk18.unk3C = 5;
        sp18 = (f64) sp8;
        M2C_FIELD(temp_r3_691->__vptr, M2C_UNK (**)(M2C_UNK, f64), 0x14)(0x23, (f64) sp8);
        AddBefore(NULL, (UIObject *) temp_r25_696);
        temp_r27_720 = M2C_FIELD(DSText::descriptor, s32 *, 8);
        temp_r3_721 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_721 != NULL) {
            var_r27_729 = ((MKHeap *) (temp_r3_721->Current()))->Alloc(temp_r27_720, NULL, 0);
        } else {
            var_r27_729 = malloc(temp_r27_720);
        }
        M2C_FIELD(DSText::descriptor, M2C_UNK (**)(UIObject *), 0xC)(var_r27_729);
        var_r27_729->unk8 = DSText::descriptor;
        var_r27_729->Init();
        temp_r3_747 = ui_cast<DSText *, UIObject *>(var_r27_729);
        temp_r3_749 = M2C_FIELD(temp_r3_747, s8 **, 0x60);
        temp_r27_750 = pFontName;
        if (temp_r3_749 != NULL) {
            UIStringTable_Remove(temp_r3_749);
        }
        UIStringTable_Add(temp_r27_750);
        M2C_FIELD(temp_r3_747, s8 **, 0x60) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
        temp_r3_747->unk18.unk40 = 0x3A;
        temp_r3_747->unk18.unk30 = 1.0f;
        temp_r3_747->unk18.unk34 = 544.0f;
        temp_r3_747->unk18.unk38 = 40.0f;
        temp_r3_747->unk18.unk3C = 5;
        temp_r25_696->Add(temp_r3_747);
        var_r29_658 += 1;
    } while (var_r29_658 < 0x14);
}
#endif

void LevelButton::Init() {
    ScriptButton::Init();
    this->unkA0 = 0;
}

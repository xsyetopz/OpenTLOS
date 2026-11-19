#include "spyro/source/LanguageSelectScreen.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/Str.h"
#include "common/gc/MKInput_GC.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

M2C_UNK free(void **);                              /* extern */
UIObject *malloc(s32);                              /* extern */
extern s32 GS_MenuSelect;
extern s32 gDisplay;
extern GameStateMachine gGMState;
extern M2C_UNK gb;
extern void *gpTranslation_StringArray;
extern s32 numLanguages;
extern void **pSystem;
extern UIStringTable strings;
u8 descriptor__20LanguageSelectScreen[0x14];        /* unable to generate initializer: cannot parse "LanguageSelectScreen" as integer */

void NoController_Draw() {
    Tools_Ortho sp8;
    const char *msg;

    msg = (const char *) M2C_FIELD(gpTranslation_StringArray, s8 **, 0xFC);
    ErrorMessage_Draw(msg);
}

void NoController_Update() {
    if ((MKInput_GetStatus((MKInputDevices) 0) == 0) && (MKInput_GetState(3, (MKInputDevices) 0, NULL, NULL) != 0.0f)) {
        if ((s32) gDisplay == 0) {
            gGMState.SwitchState(3, 0, 0U);
            return;
        }
        gGMState.SwitchState(5, 0, 0U);
    }
}

void ControllerInit_Update() {
    if ((s32) gDisplay == 0) {
        gGMState.SwitchState(3, 0, 0U);
        return;
    }
    gGMState.SwitchState(5, 0, 0U);
}

#if 0 // DRAFT: ')' expected
void Language_Draw() {
    RenderContext sp20;
    Tools_Ortho sp10;

    if ((void **) pSystem != NULL) {
        sp10.Tools_Ortho();
        sp20.RenderContext();
        M2C_FIELD(*pSystem, M2C_UNK (**)(void **, RenderContext *), 0x1C)(pSystem, &sp20);
        sp10.~Tools_Ortho(-1);
    }
}
#endif

void Language_Update() {
    if (((void **) pSystem == NULL) || ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) || ((u32) M2C_FIELD(&pSystem[M2C_FIELD(pSystem, s32 *, 0x6C)], u32 *, 0x70) == 0U)) {
        gGMState.SwitchState(5, 0, 0U);
        return;
    }
    M2C_FIELD(M2C_FIELD(pSystem, void **, 0), M2C_UNK (**)(), 0x18)();
}

void Language_Deinit() {
    UIStringTable *temp_r30_188;
    void **temp_r31_198;

    if ((void **) pSystem != NULL) {
        temp_r30_188 = UIStringTable_SetCurrent(&strings);
        if ((void **) pSystem != NULL) {
            M2C_FIELD(*pSystem, M2C_UNK (**)(void **), 0x24)(pSystem);
            temp_r31_198 = pSystem;
            M2C_FIELD(*pSystem, M2C_UNK (**)(void **), 0xC)(pSystem);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_198, NULL, 0);
            } else {
                free(temp_r31_198);
            }
        }
        pSystem = NULL;
        UIStringTable_SetCurrent(temp_r30_188);
        strings.Deinit();
        KDSound_Deinit();
    }
}

#if 0 // DRAFT: function call 'Init(UIObject *, unsigned char[20])' does not match 'UIObject::Init()'
void Language_Init() {
    s32 spC;
    s32 sp8;
    MCLoadCheckScreen *temp_r3_291;
    UIObject *var_r30_258;
    UIObjectDescriptor *var_r4_284;
    UIStringTable *temp_r31_247;
    s32 temp_r30_249;
    s32 temp_r3_237;

    temp_r3_237 = GameLanguage_Count();
    numLanguages = temp_r3_237;
    if (temp_r3_237 > 1) {
        strings.Init(0x400);
        temp_r31_247 = UIStringTable_SetCurrent(&strings);
        temp_r30_249 = M2C_FIELD(NoisySystem::descriptor, s32 *, 8);
        if (MKHeap::Current() != NULL) {
            var_r30_258 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_249, NULL, 0));
        } else {
            var_r30_258 = malloc(temp_r30_249);
        }
        M2C_FIELD(NoisySystem::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r30_258, NoisySystem::descriptor);
        var_r30_258->unk8 = NoisySystem::descriptor;
        var_r30_258->Init(NoisySystem::descriptor);
        pSystem = (void **) (checked_cast<NoisySystem *, UIObject>(var_r30_258));
        var_r4_284 = &UIObjectDescriptor::list;
loop_7:
        temp_r3_291 = var_r4_284->unk0;
        if (temp_r3_291 == NULL) {
            var_r4_284->unk0 = (MCLoadCheckScreen *) LanguageSelectScreen::descriptor;
            M2C_FIELD(LanguageSelectScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_291 != LanguageSelectScreen::descriptor) {
            var_r4_284 = (UIObjectDescriptor *) &temp_r3_291->unk10;
            goto loop_7;
        }
        KDSound_Init"mainmenu";
        if (((UIObject *) pSystem)->Load("language.ui", NULL) != 0) {
            M2C_FIELD(*pSystem, M2C_UNK (**)(void **), 0x28)(pSystem);
            M2C_FIELD(*pSystem, M2C_UNK (**)(void **), 0x20)(pSystem);
            sp8 = 1;
            spC = 0;
            M2C_FIELD(*pSystem, M2C_UNK (**)(void **, s32 *), 0x2C)(pSystem, &sp8);
            ((UISystem *) pSystem)->PushScreen("LanguageSelect");
        }
        UIStringTable_SetCurrent(temp_r31_247);
    }
    UIControls_SetDevice((MKInputDevices) *M2C_FIELD(&gb, s32 **, 0x354));
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void LanguageSelectScreen::Update() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIContainer *temp_r3_375;
    void **temp_r3_384;
    void **temp_r3_412;
    void **temp_r3_431;

    UIScreen::Update();
    if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
        KDSound_Play(GS_MenuSelect, 0U, -1);
        if ((void **) pSystem == NULL) {
            temp_r3_375 = GetRoot();
            sp14 = 0xF;
            M2C_FIELD(temp_r3_375->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp14);
        }
        temp_r3_384 = this->unkC8;
        sp10 = 6;
        M2C_FIELD(*temp_r3_384, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_384, &sp10);
        if ((void **) pSystem != NULL) {
            gGMState.SwitchState(5, 0, 0U);
        }
    } else {
        if (UIControls_DirectionPressed((FrontEndControls) 4, -1) != 0) {
            KDSound_Play(GS_MenuSelect, 0U, -1);
            temp_r3_412 = this->unkC8;
            spC = 0xB;
            M2C_FIELD(*temp_r3_412, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_412, &spC);
            return;
        }
        if (UIControls_DirectionPressed((FrontEndControls) 6, -1) != 0) {
            KDSound_Play(GS_MenuSelect, 0U, -1);
            temp_r3_431 = this->unkC8;
            sp8 = 0xA;
            M2C_FIELD(*temp_r3_431, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_431, &sp8);
        }
    }
}
#endif

void LanguageSelectScreen::OnEnter() {
    s32 spC;
    s32 sp8;
    void **temp_r3_461;

    UIScreen::OnEnter();
    sp8 = 1;
    spC = this->unkCC;
    temp_r3_461 = this->unkC8;
    M2C_FIELD(*temp_r3_461, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_461, &sp8);
}

#if 0 // DRAFT: function call 'Init(UIObject *, unsigned char[20])' does not match 'UIObject::Init()'
void LanguageSelectScreen::LoadDone() {
    s32 sp8;
    UIObject *temp_r3_600;
    UIObject *temp_r3_655;
    UIObject *var_r24_500;
    UIObject *var_r24_582;
    UIObject *var_r24_637;
    s32 temp_r24_491;
    s32 temp_r24_573;
    s32 temp_r24_628;
    s32 var_r26_557;
    s8 *temp_r0_665;
    s8 *temp_r3_677;
    void **temp_r5_532;

    temp_r24_491 = M2C_FIELD(MarkerButtonGroup::descriptor, s32 *, 8);
    if (MKHeap::Current() != NULL) {
        var_r24_500 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r24_491, NULL, 0));
    } else {
        var_r24_500 = malloc(temp_r24_491);
    }
    M2C_FIELD(MarkerButtonGroup::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r24_500, MarkerButtonGroup::descriptor);
    var_r24_500->unk8 = MarkerButtonGroup::descriptor;
    var_r24_500->Init(MarkerButtonGroup::descriptor);
    this->unkC8 = (void **) (ui_cast<UIButtonGroup *, UIObject *>(var_r24_500));
    M2C_FIELD(this->unkC8, s16 *, 0x58) = 2;
    temp_r5_532 = this->unkC8;
    M2C_FIELD(temp_r5_532, f32 *, 0x28) = 320.0f;
    M2C_FIELD(temp_r5_532, f32 *, 0x2C) = 100.0f;
    M2C_FIELD(temp_r5_532, f32 *, 0x30) = 0.0f;
    AddBefore(NULL, (UIObject *) this->unkC8);
    M2C_FIELD(this->unkC8, f32 *, 0x2C) = (f32) -((0.5f * (36.0f * (f32) (numLanguages - 1))) - 256.0f);
    var_r26_557 = numLanguages - 1;
    if (GameLanguage_GetLast((int *) &sp8, 0U) != 0) {
        do {
            temp_r24_573 = M2C_FIELD(ThrobButton::descriptor, s32 *, 8);
            if (MKHeap::Current() != NULL) {
                var_r24_582 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r24_573, NULL, 0));
            } else {
                var_r24_582 = malloc(temp_r24_573);
            }
            M2C_FIELD(ThrobButton::descriptor, M2C_UNK (**)(UIObject *), 0xC)(var_r24_582);
            var_r24_582->unk8 = ThrobButton::descriptor;
            var_r24_582->Init();
            temp_r3_600 = ui_cast<ScriptButton *, UIObject *>(var_r24_582);
            temp_r3_600->unk18.unk40 = 0xB;
            temp_r3_600->unk18.unk10.unk0 = 0.0f;
            temp_r3_600->unk18.unk10.unk4 = 36.0f * (f32) var_r26_557;
            temp_r3_600->unk18.unk10.unk8 = 0.0f;
            GameLanguage_GetCode(sp8);
            M2C_FIELD(temp_r3_600->__vptr, M2C_UNK (**)(UIObject *, s8 *), 0x48)(temp_r3_600, Str_Printf("lang %s", M2C_ERROR(/* Read from unset register $r3 */)));
            ((UIContainer *) this->unkC8)->Add(temp_r3_600);
            temp_r24_628 = M2C_FIELD(DSText::descriptor, s32 *, 8);
            if (MKHeap::Current() != NULL) {
                var_r24_637 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r24_628, NULL, 0));
            } else {
                var_r24_637 = malloc(temp_r24_628);
            }
            M2C_FIELD(DSText::descriptor, M2C_UNK (**)(UIObject *), 0xC)(var_r24_637);
            var_r24_637->unk8 = DSText::descriptor;
            var_r24_637->Init();
            temp_r3_655 = ui_cast<UIText *, UIObject *>(var_r24_637);
            temp_r3_655->unk18.unk40 = 0x32;
            temp_r3_655->unk18.unk34 = 408.0f;
            temp_r3_655->unk18.unk38 = 36.0f;
            temp_r3_655->unk18.unk3C = 5;
            GameLanguage_GetName(sp8);
            temp_r0_665 = M2C_FIELD(temp_r3_655, s8 **, 0x68);
            if (temp_r0_665 != NULL) {
                UIStringTable_Remove(temp_r0_665);
            }
            UIStringTable_Add(M2C_ERROR(/* Read from unset register $r3 */));
            M2C_FIELD(temp_r3_655, s8 **, 0x68) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
            M2C_FIELD(temp_r3_655, s32 *, 0x6C) = -1;
            temp_r3_677 = M2C_FIELD(temp_r3_655, s8 **, 0x60);
            if (temp_r3_677 != NULL) {
                UIStringTable_Remove(temp_r3_677);
            }
            UIStringTable_Add"font_game";
            M2C_FIELD(temp_r3_655, s8 **, 0x60) = (s8 *) M2C_ERROR(/* Read from unset register $r3 */);
            ((UIContainer *) temp_r3_600)->Add(temp_r3_655);
            GameLanguage_Get();
            if (sp8 == (s32) M2C_ERROR(/* Read from unset register $r3 */)) {
                this->unkCC = var_r26_557;
            }
            var_r26_557 -= 1;
        } while (GameLanguage_GetPrev((int *) &sp8, 0U) != 0);
    }
}
#endif

void LanguageSelectScreen::Init() {
    UIContainer::Init();
    this->unkC8 = NULL;
    this->unkCC = 0;
}

void LanguageSelectScreen_cpp::__sinit() {
    strings.UIStringTable();
}

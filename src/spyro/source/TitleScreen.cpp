#include "spyro/source/TitleScreen.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/GameData.h"
#include "spyro/source/Level.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern s32 loopCount;
#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static s8 *pVideos[1] = { "AttractVideo" };
#endif
static s32 videoCount = 1;

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void TitleScreen::Update() {
    s32 spC;
    s32 sp8;
    UISystem *temp_r3_71;
    f32 temp_f1_37;
    f32 var_f31_41;
    s32 temp_r0_76;
    s32 temp_r3_64;
    s32 temp_r7_72;
    s32 var_r4_137;
    void **temp_r3_133;

    UIScreen::Update();
    if ((s32) M2C_FIELD(&gb, s32 *, 0x358) > -1) {
        M2C_FIELD(&gb, s32 *, 0x358) = -1;
        M2C_FIELD(UIInput(-1), s8 *, 4) = 0;
        UIControls_Reset();
    }
    this->unkC8 += gUpdateTimeDelta;
    temp_f1_37 = this->unkC8;
    if (temp_f1_37 >= 30.0f) {
        var_f31_41 = temp_f1_37 - 30.0f;
        if (var_f31_41 < 1.0f) {

        } else {
            var_f31_41 = 1.0f;
        }
        if (var_f31_41 > 0.0f) {

        } else {
            var_f31_41 = 0.0f;
        }
        FrontEnd_SetFade(var_f31_41);
        if (var_f31_41 >= 1.0f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r3_64 = this->unkD0;
            this->unkD0 = temp_r3_64 + 1;
            if (temp_r3_64 >= 5) {
                temp_r3_71 = ui_cast<UISystem *, UIContainer *>(GetRoot());
                temp_r7_72 = loopCount;
                temp_r0_76 = temp_r7_72 / (s32) videoCount;
                loopCount = temp_r7_72 + 1;
                temp_r3_71->ChangeScreen(pVideos[temp_r7_72 - (temp_r0_76 * videoCount)]);
            }
        }
    } else if (FrontEnd_GetFade() > 0.0f) {
        FrontEnd_SetFade(1.0f - this->unkC8);
    }
    if (MKInput_GetState(3, (MKInputDevices) 0, NULL, NULL) > 0.0f) {
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s32 *, 0) = 0;
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s8 *, 4) = 0;
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s8 *, 5) = 0;
        UIControls_SetDevice((MKInputDevices) 0);
        KDSound_Play(GS_MenuSelect, 0U, -1);
        ((UISystem *) (ui_cast<P8UISystem))->PushScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "");
    }
    this->unkCC += gUpdateTimeDelta;
    if (this->unkCC >= 1.0f) {
        temp_r3_133 = this->unkD4;
        if (temp_r3_133 != NULL) {
            var_r4_137 = 2;
            if ((u8) M2C_FIELD(temp_r3_133, u8 *, 0x14) != 0) {
                var_r4_137 = 3;
            }
            sp8 = var_r4_137;
            spC = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_133, void **, 0), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        this->unkCC -= 1.0f;
    }
}
#endif

void TitleScreen::OnExit() {
    UIScreen::OnExit();
    FrontEnd_SetFade(0.0f);
}

#if 0 // DRAFT: illegal operand
void TitleScreen::OnEnter() {
    s32 spC;
    s32 sp8;
    UIContainer *temp_r3_211;
    f32 var_f1_219;
    u32 temp_r31_213;
    void **temp_r3_197;

    UIScreen::OnEnter();
    this->unkC8 = 0.0f;
    this->unkCC = 1.0f;
    M2C_FIELD(&gb, s8 *, 9) = 0;
    temp_r3_197 = this->unkD4;
    if (temp_r3_197 != NULL) {
        spC = 0;
        sp8 = 3;
        M2C_FIELD(*temp_r3_197, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    temp_r3_211 = ui_cast<UISystem *, UIContainer *>(GetRoot());
    temp_r31_213 = M2C_FIELD(temp_r3_211, u32 *, 0x98);
    if (temp_r31_213 != temp_r3_211->FindChild("")) {
        var_f1_219 = 1.0f;
    } else {
        var_f1_219 = 0.0f;
    }
    FrontEnd_SetFade(var_f1_219);
    ((GameData *) GameData::gameData)->GetGameSettings();
    KDSound_SetMasterVolume(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4), M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8));
    FrontEnd_PlayBackgroundVideo(1U);
    this->unkD0 = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'UIObject *' to
void TitleScreen::Resolve() {
    UIScreen::Resolve();
    this->unkD4 = FindChild("");
    this->unk18.unk40 |= 1;
}
#endif

void TitleScreen::Init() {
    UIContainer::Init();
    this->unkD4 = NULL;
}

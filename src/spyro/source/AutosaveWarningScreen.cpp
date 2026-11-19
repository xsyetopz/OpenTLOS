#include "spyro/source/AutosaveWarningScreen.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/PauseMenu.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern GameStateMachine gGMState;

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void AutosaveWarningScreen::Update() {
    s32 spC;
    s32 sp8;
    UIContainer *temp_r3_45;

    UIScreen::Update();
    if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
        if ((s32) *gGMState.GetCurrState() == 5) {
            if ((s32) *MemoryCardScreen::operation == 0) {
                gGMState.SwitchState(6, 1, 0U);
                return;
            }
            FrontEnd_GoToNewGame();
            return;
        }
        PauseMenu_AllowStartToQuit(1U);
        temp_r3_45 = GetRoot();
        sp8 = 0xF;
        spC = 0;
        M2C_FIELD(temp_r3_45->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        KDSound_Play(GS_MenuSelect, 0U, -1);
    }
}
#endif

void AutosaveWarningScreen::OnExit() {
    UIScreen::OnExit();
    FrontEnd_SetFade(0.0f);
}

#if 0 // DRAFT: function call 'UIStringTable_Remove(signed char *)' does not match
void AutosaveWarningScreen::OnEnter() {
    s32 var_r31_100;
    s8 *temp_r3_105;
    void *temp_r3_96;

    UIScreen::OnEnter();
    temp_r3_96 = ui_cast<UIText *, UIObject *>(FindChild("Success"));
    if (temp_r3_96 != NULL) {
        var_r31_100 = 0x40;
        if ((s32) *MemoryCardScreen::operation == 0) {
            var_r31_100 = 0x41;
        }
        temp_r3_105 = M2C_FIELD(temp_r3_96, s8 **, 0x68);
        if (temp_r3_105 != NULL) {
            UIStringTable_Remove(temp_r3_105);
        }
        M2C_FIELD(temp_r3_96, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r3_96, s32 *, 0x6C) = var_r31_100;
    }
}
#endif

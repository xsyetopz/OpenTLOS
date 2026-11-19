#include "spyro/source/UIScreen.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

void UIScreen::OnCancel() {
    ((UIEvent *) &this->unkB0.unk4)->Send();
}

void UIScreen::OnSelect() {
    ((UIEvent *) &this->unkA4.unk4)->Send();
}

void UIScreen::OnRight() {
    ((UIEvent *) &this->unk98.unk4)->Send();
}

void UIScreen::OnLeft() {
    ((UIEvent *) &this->unk8C.unk4)->Send();
}

void UIScreen::OnDown() {
    ((UIEvent *) &this->unk80.unk4)->Send();
}

void UIScreen::OnUp() {
    ((UIEvent *) &this->unk74.unk4)->Send();
}

#if 0 // DRAFT: illegal implicit conversion from 'void **' to
void UIScreen::OnExit() {
    s32 sp8;
    UIContainer *temp_r3_103;

    ((UIEvent *) &this->unk68.unk4)->Send();
    temp_r3_103 = this->unkC;
    sp8 = 0x8001;
    temp_r3_103->Message(&sp8);
}
#endif

void UIScreen::OnEnter() {
    ((UIEvent *) &this->unk60)->Send();
}

s32 UIScreen::LoadLine(UIDataLine *arg0) {
    s32 var_r31_143;

    var_r31_143 = 0;
    if ((((UIEvent *) &this->unk60)->LoadLine("OnEnter", arg0) != 0) || (((UIEvent *) &this->unk68.unk4)->LoadLine("OnExit", arg0) != 0) || (((UIEvent *) &this->unk74.unk4)->LoadLine("OnUpPressed", arg0) != 0) || (((UIEvent *) &this->unk80.unk4)->LoadLine("OnDownPressed", arg0) != 0) || (((UIEvent *) &this->unk8C.unk4)->LoadLine("OnLeftPressed", arg0) != 0) || (((UIEvent *) &this->unk98.unk4)->LoadLine("OnRightPressed", arg0) != 0) || (((UIEvent *) &this->unkA4.unk4)->LoadLine("OnSelectPressed", arg0) != 0) || (((UIEvent *) &this->unkB0.unk4)->LoadLine("OnCancelPressed", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
        var_r31_143 = 1;
    }
    return var_r31_143;
}

void UIScreen::Update() {
    if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
        OnCancel();
    } else if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
        OnSelect();
    } else if (UIControls_DirectionPressed((FrontEndControls) 7, -1) != 0) {
        OnLeft();
    } else if (UIControls_DirectionPressed((FrontEndControls) 5, -1) != 0) {
        OnRight();
    } else if (UIControls_DirectionPressed((FrontEndControls) 4, -1) != 0) {
        OnUp();
    } else if (UIControls_DirectionPressed((FrontEndControls) 6, -1) != 0) {
        OnDown();
    }
    UIContainer::Update();
}

void UIScreen::Message(UIMessage *arg0) {
    UIContainer::Message(arg0);
}

void UIScreen::Resolve() {
    UIContainer::Resolve();
    ((UIEvent *) &this->unk60)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unk68.unk4)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unk74.unk4)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unk80.unk4)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unk8C.unk4)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unk98.unk4)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unkA4.unk4)->Resolve((UIObject *) this);
    ((UIEvent *) &this->unkB0.unk4)->Resolve((UIObject *) this);
}

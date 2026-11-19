#include "spyro/source/UIScreen.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

void UIScreen::OnCancel() {
    this->unkBC.Send();
}

void UIScreen::OnSelect() {
    this->unkB0.Send();
}

void UIScreen::OnRight() {
    this->unkA4.Send();
}

void UIScreen::OnLeft() {
    this->unk98.Send();
}

void UIScreen::OnDown() {
    this->unk8C.Send();
}

void UIScreen::OnUp() {
    this->unk80.Send();
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void UIScreen::OnExit() {
    s32 sp8;
    UIContainer *temp_r3_103;

    this->unk74.Send();
    temp_r3_103 = this->unkC;
    sp8 = 0x8001;
    temp_r3_103->Message(&sp8);
}
#endif

void UIScreen::OnEnter() {
    this->unk68.Send();
}

s32 UIScreen::LoadLine(UIDataLine *arg0) {
    s32 var_r31_143;

    var_r31_143 = 0;
    if ((this->unk68.LoadLine("OnEnter", arg0) != 0) || (this->unk74.LoadLine("OnExit", arg0) != 0) || (this->unk80.LoadLine("OnUpPressed", arg0) != 0) || (this->unk8C.LoadLine("OnDownPressed", arg0) != 0) || (this->unk98.LoadLine("OnLeftPressed", arg0) != 0) || (this->unkA4.LoadLine("OnRightPressed", arg0) != 0) || (this->unkB0.LoadLine("OnSelectPressed", arg0) != 0) || (this->unkBC.LoadLine("OnCancelPressed", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
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
    this->unk68.Resolve((UIObject *) this);
    this->unk74.Resolve((UIObject *) this);
    this->unk80.Resolve((UIObject *) this);
    this->unk8C.Resolve((UIObject *) this);
    this->unk98.Resolve((UIObject *) this);
    this->unkA4.Resolve((UIObject *) this);
    this->unkB0.Resolve((UIObject *) this);
    this->unkBC.Resolve((UIObject *) this);
}

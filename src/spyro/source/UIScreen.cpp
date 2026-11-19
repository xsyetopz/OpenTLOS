#include "spyro/source/UIScreen.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "unplaced_enums.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

#if 0 // DRAFT: expression syntax error
void UIScreen::OnCancel() {
    this->unkB0.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnSelect() {
    this->unkA4.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnRight() {
    this->unk98.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnLeft() {
    this->unk8C.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnDown() {
    this->unk80.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnUp() {
    this->unk74.unk4.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnExit() {
    s32 sp8;
    UIContainer *temp_r3_103;

    this->unk68.unk4.Send();
    temp_r3_103 = this->unkC;
    sp8 = 0x8001;
    temp_r3_103->Message(&sp8);
}
#endif

#if 0 // DRAFT: expression syntax error
void UIScreen::OnEnter() {
    this->unk60.Send();
}
#endif

#if 0 // DRAFT: expression syntax error
s32 UIScreen::LoadLine(UIDataLine *arg0) {
    s32 var_r31_143;

    var_r31_143 = 0;
    if ((this->unk60.LoadLine("OnEnter", arg0) != 0) || (this->unk68.unk4.LoadLine("OnExit", arg0) != 0) || (this->unk74.unk4.LoadLine("OnUpPressed", arg0) != 0) || (this->unk80.unk4.LoadLine("OnDownPressed", arg0) != 0) || (this->unk8C.unk4.LoadLine("OnLeftPressed", arg0) != 0) || (this->unk98.unk4.LoadLine("OnRightPressed", arg0) != 0) || (this->unkA4.unk4.LoadLine("OnSelectPressed", arg0) != 0) || (this->unkB0.unk4.LoadLine("OnCancelPressed", arg0) != 0) || (UIContainer::LoadLine(arg0) != 0)) {
        var_r31_143 = 1;
    }
    return var_r31_143;
}
#endif

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

#if 0 // DRAFT: expression syntax error
void UIScreen::Resolve() {
    UIContainer::Resolve();
    this->unk60.Resolve((UIObject *) this);
    this->unk68.unk4.Resolve((UIObject *) this);
    this->unk74.unk4.Resolve((UIObject *) this);
    this->unk80.unk4.Resolve((UIObject *) this);
    this->unk8C.unk4.Resolve((UIObject *) this);
    this->unk98.unk4.Resolve((UIObject *) this);
    this->unkA4.unk4.Resolve((UIObject *) this);
    this->unkB0.unk4.Resolve((UIObject *) this);
}
#endif

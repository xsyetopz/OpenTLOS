void OptionsScreen::Resolve() {
    UIMessage msg;
    UIContainer *temp_r3_418;
    UIObject *temp_r3_457;
    UIObject *var_r3_479;
    void **temp_r3_435;

    UIScreen::Resolve();
    this->unkD0 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("OptionsButtons"));
    temp_r3_418 = this->unkD0;
    if (temp_r3_418 != NULL) {
        this->unkD4 = (void **) (ui_cast<UIButton *, UIObject *>(temp_r3_418->FindChild("Position")));
    }
    this->unkD8 = (void **) (ui_cast<UIContainer *, UIObject *>(FindChild("PromptGroup")));
    temp_r3_435 = this->unkD8;
    if (temp_r3_435 != NULL) {
        this->unkDC = (void **) (((UIContainer *) temp_r3_435)->FindChild("LeftRight"));
        this->unkE0 = (void **) (((UIContainer *) this->unkD8)->FindChild("Forward"));
    }
    if (Sound_GetSystemAudioMode() == 0) {
        temp_r3_457 = this->unkD0->FindChild("Output");
        if (temp_r3_457 != NULL) {
            msg.unk0 = 5;
            msg.unk4 = 0;
            temp_r3_457->Message(&msg);
            msg.unk0 = 3;
            msg.unk4 = 0;
            temp_r3_457->Message(&msg);
            var_r3_479 = temp_r3_457->unk10;
loop_8:
            if (var_r3_479 != NULL) {
                var_r3_479->unk18.unk10.unk4 -= 40.0f;
                var_r3_479 = var_r3_479->unk10;
                goto loop_8;
            }
        }
    }
}

void UIScreen::OnExit() {
    s32 sp8;
    UIContainer *temp_r3_103;

    this->unk74.Send();
    temp_r3_103 = this->unkC;
    sp8 = 0x8001;
    temp_r3_103->Message((UIMessage *) &sp8);
}

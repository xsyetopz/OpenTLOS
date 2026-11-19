void UISystem::ChangeScreen(const char *arg0) {
    UIMessage sp8;
    UIObject *spC;

    spC = FindChild(arg0);
    sp8.unk0 = 0xD;
    sp8.unk4 = (s32) spC;
    Message(&sp8);
}

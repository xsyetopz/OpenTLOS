void UISystem::PushScreen(const char *arg0) {
    UIMessage sp8;
    UIObject *spC;

    spC = FindChild(arg0);
    sp8.unk0 = 0xE;
    sp8.unk4 = (s32) spC;
    Message(&sp8);
}

extern "C" s32 stricmp(const char *, const char *);

void ExitConfirmScreen::Resolve() {
    UIScreen::Resolve();
    this->unkC8 = (void **) (ui_cast<UIButtonGroup *, UIObject *>(FindChild("buttons")));
    if (stricmp((const char *) this->unk4, "QuitGame") == 0) {
        this->unkCC = 0;
        return;
    }
    this->unkCC = 1;
}

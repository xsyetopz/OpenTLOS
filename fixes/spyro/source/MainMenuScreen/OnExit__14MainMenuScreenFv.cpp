void MainMenuScreen::OnExit() {
    UIScreen::OnExit();
    *(s32 *) selectedIndex = M2C_FIELD(this->unkD8, s32 *, 0x68);
}

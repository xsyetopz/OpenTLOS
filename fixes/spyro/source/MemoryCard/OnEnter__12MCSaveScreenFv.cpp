void MCSaveScreen::OnEnter() {
    MemoryCardScreen::OnEnter();
    Autosave_EnableRemovalCheck(0U);
    if (*(s32 *) gGMState.GetCurrState() == 7) {
        PauseMenu_AllowStartToQuit(0U);
    }
}

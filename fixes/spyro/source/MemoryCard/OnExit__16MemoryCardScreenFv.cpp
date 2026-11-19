void MemoryCardScreen::OnExit() {
    s32 temp_r0_391;

    UIScreen::OnExit();
    temp_r0_391 = ui_cast<UISystem *, UIContainer *>(GetRoot())->unk68;
    if ((temp_r0_391 == 3) || (temp_r0_391 == 4)) {
        Autosave_EnableRemovalCheck(1U);
        if (*(s32 *) gGMState.GetCurrState() == 7) {
            PauseMenu_AllowStartToQuit(1U);
        }
    }
    FrontEnd_SetFade(0.0f);
}

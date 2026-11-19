void AutosaveWarningScreen::Update() {
    s32 msg[2];

    UIScreen::Update();
    if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
        if (*(s32 *) gGMState.GetCurrState() == 5) {
            if (*(s32 *) MemoryCardScreen::operation == 0) {
                gGMState.SwitchState(6, 1, 0U);
                return;
            }
            FrontEnd_GoToNewGame();
            return;
        }
        PauseMenu_AllowStartToQuit(1U);
        msg[0] = 0xF;
        msg[1] = 0;
        GetRoot()->Message((UIMessage *) msg);
        KDSound_Play(GS_MenuSelect, 0U, -1);
    }
}

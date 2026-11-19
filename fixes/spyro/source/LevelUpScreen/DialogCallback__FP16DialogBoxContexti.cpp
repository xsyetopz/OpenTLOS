void DialogCallback(DialogBoxContext *arg0, int arg1) {
    if ((arg1 == 0) && ((void *) pContextFury == (void *) arg0)) {
        M2C_FIELD(arg0, LevelUpScreen **, 0x8)->SetBreathText();
        DialogBox_ReleaseContext(arg0);
    } else if ((arg1 == 7) && ((void *) pContextFury == (void *) arg0)) {
        pContextFury = NULL;
    }
    PauseMenu_AllowStartToQuit(1);
}

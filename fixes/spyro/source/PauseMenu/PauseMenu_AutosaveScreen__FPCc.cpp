void PauseMenu_AutosaveScreen(const char *arg0) {
    void *temp_r3_41;

    if ((u8) gb.unk395 == 0) {
        gb.SetGamePaused(1U, (bool (*)(void)) PauseMenu_Update, PauseMenu_Draw, 1U);
        PauseMenu_Reset(arg0);
        return;
    }
    if (((UISystem *) pSystem != NULL) && ((u32) gb.unk398 == 1)) {
        temp_r3_41 = M2C_FIELD(pSystem, void **, pSystem->unk6C * 4 + 0x70);
        if ((temp_r3_41 != NULL) && (stricmp(M2C_FIELD(temp_r3_41, s32 *, 4), (M2C_UNK *) "AutosaveWarning") == 0)) {
            pSystem->ChangeScreen(arg0);
            return;
        }
        pSystem->PushScreen(arg0);
    }
}

void PauseMenu_Reset(const char *arg0) {
    s32 spC;
    s32 sp8;
    KDSynkerPlayer3 *temp_r3_410;
    u8 var_r31_407;
    void *temp_r30_409;

    UIControls_Reset();
    if ((UISystem *) pSystem != NULL) {
        sp8 = 1;
        spC = 0;
        pSystem->Message((UIMessage *) &sp8);
        if (arg0 == NULL) {
            if (((s32) M2C_FIELD(GameData::gameData, s32 *, 0x164) > 0) && ((u32) (((u8) GameData::gameData[0x18A] >> 7U) & 1) == 1)) {
                pSystem->PushScreen("main");
                pSystem->PushScreen("LevelUpScreen");
            } else {
                pSystem->PushScreen("main");
            }
        } else {
            pSystem->PushScreen(arg0);
        }
        pSystem->Update();
        if (((u32) (((u8) GameData::gameData[0x18A] >> 7U) & 1) == 1) && ((UISystem *) pSystem != NULL) && (arg0 == NULL) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x164) > 0)) {
            GameData::gameData[0x18A] &= ~0x80;
        }
    }
    UIControls_SetDevice(*(MKInputDevices *) gb.unk354);
    PauseMenu_AllowStartToQuit(1U);
    KDSound_PauseAll(1U);
    var_r31_407 = 0;
    temp_r30_409 = M2C_FIELD(&gb, void **, 0xC);
    temp_r3_410 = M2C_FIELD(temp_r30_409, KDSynkerPlayer3 **, 0x78);
    if (((temp_r3_410 != NULL) && (temp_r3_410->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_409, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r30_409) + 0x24))->GetState() == 2))) {
        var_r31_407 = 1;
    }
    KDSound_PauseMusic(1U, var_r31_407);
}

s32 PauseMenu_Update() {
    KDSynkerPlayer3 *temp_r3_279;
    u8 var_r29_275;
    u8 var_r31_277;
    void *temp_r30_278;

    if ((UISystem *) pSystem != NULL) {
        if (((u8) bAllowStartToQuit != 0) && (UIControls_Pressed((FrontEndControls) 3, -1) != 0)) {
            KDSound_Play(GS_MenuCancel, 0U, -1);
            M2C_FIELD(((UIContainer *) pSystem)->FindChild("main"), s8 *, 0xD1) = 1;
            pSystem->ClearStack(NULL);
        }
        pSystem->Update();
        if ((u32) M2C_FIELD(pSystem, u32 *, pSystem->unk6C * 4 + 0x70) == 0U) {
            gb.SetGamePaused(0U, (bool (*)(void)) PauseMenu_Update, PauseMenu_Draw, 1U);
            if ((u8) bStopSoundsAfterPauseMenu != 0) {
                KDSound_StopAll();
                bStopSoundsAfterPauseMenu = 0;
            } else {
                KDSound_PauseAll(0U);
            }
            var_r29_275 = 1;
            var_r31_277 = 0;
            temp_r30_278 = M2C_FIELD(&gb, void **, 0xC);
            temp_r3_279 = M2C_FIELD(temp_r30_278, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_279 != NULL) && (temp_r3_279->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_278, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r30_278) + 0x24))->GetState() == 2))) {
                var_r31_277 = 1;
            }
            if ((var_r31_277 == 0) && (KDSound_IsChronoSoundWarpEnabled() == 0)) {
                var_r29_275 = 0;
            }
            KDSound_PauseMusic(0U, var_r29_275);
        }
        return 1;
    }
    return 0;
}

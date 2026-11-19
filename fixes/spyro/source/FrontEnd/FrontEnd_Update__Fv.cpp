void FrontEnd_Update() {
    f32 temp_f1_414;
    f32 temp_f1_432;
    s32 temp_r0_344;
    s32 temp_r0_392;

    if ((u8) bGoToNewGame != 0) {
        FrontEnd_SetFade(gUpdateTimeDelta + FrontEnd_GetFade());
        if (FrontEnd_GetFade() >= 0.99f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r0_344 = timeout + 1;
            timeout = temp_r0_344;
            if (temp_r0_344 >= 3) {
                if ((s32) gDisplay == 0) {
                    ((UISystem *) pFrontEndSystem)->ChangeScreen("Prologue1VideoNoTitle");
                } else {
                    ((UISystem *) pFrontEndSystem)->ChangeScreen("Prologue1Video");
                }
                bGoToNewGame = 0;
                M2C_FIELD(&gb, s8 *, 0x3B5) = 0;
                M2C_FIELD(&gb, s8 *, 0x3B4) = 0;
                ((GameStats *) &GameData::gameData[0x70])->SetLevelUpPoints(0);
            }
        }
        goto block_26;
    }
    if ((u8) bGoToVideo != 0) {
        FrontEnd_SetFade(gUpdateTimeDelta + FrontEnd_GetFade());
        if (FrontEnd_GetFade() >= 0.99f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r0_392 = timeout + 1;
            timeout = temp_r0_392;
            if (temp_r0_392 >= 3) {
                /* pVideoName is a signed char * in the header; PushScreen takes the same bytes as const char *. */
                ((UISystem *) pFrontEndSystem)->PushScreen((const char *) pVideoName);
                bGoToVideo = 0;
                pVideoName = NULL;
            }
        }
        goto block_26;
    }
    if ((GameVideo *) pVideo != NULL) {
        if (GameVideo_GetRemainingTime(pVideo) < 2.0f) {
            temp_f1_414 = videoFade + gUpdateTimeDelta;
            videoFade = temp_f1_414;
            if (temp_f1_414 > 1.0f) {
                videoFade = 1.0f;
            }
        } else if ((videoFade > 0.0f) && (GameVideo_Ready(pVideo) != 0)) {
            temp_f1_432 = videoFade - gUpdateTimeDelta;
            videoFade = temp_f1_432;
            if (temp_f1_432 < 0.0f) {
                videoFade = 0.0f;
            }
        }
    }
    if (FrontEnd_GetFade() > 0.0f) {
        FrontEnd_SetFade(FrontEnd_GetFade() - gUpdateTimeDelta);
    }
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) {
        FrontEnd_UpdateAutoLevelSwitch();
        return;
    }
    if (((void **) pFrontEndSystem != NULL) && ((s32) M2C_FIELD(&gb, s32 *, 0x358) == -1)) {
        /* Slot 0x18 takes the object in r3, so pFrontEndSystem is passed as this. */
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x18)(pFrontEndSystem);
    }
block_26:
    GameVideo_Update(pVideo);
}

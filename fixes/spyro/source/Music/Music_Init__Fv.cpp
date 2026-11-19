void Music_Init() {
    MKIni sp30;
    s32 sp8[0xA];
    s8 *var_r28_1188;
    MKIniLine *var_r27_1101;
    MKIniLine *var_r27_1213;
    MKIniLine *var_r29_1122;
    MKIniLine *var_r29_1178;
    s32 temp_r26_1155;
    s32 var_r26_1175;
    s32 var_r28_1098;
    u8 var_r31_1254;
    void *var_r3_1163;

    memset(sp8, 0, 0x28U);
    pTracks = NULL;
    trackCount = 0;
    stingTimerElapsed = 0.0f;
    lastTrackFadeTime = 0.0f;
    pHeldTrack = NULL;
    pDelayedTrackBuffer[0x20] = 0;
    pDelayedTrackBuffer[0x21] = 0;
    strcpy((char *) pDelayedTrackBuffer, "");
    MKHeap::ActivateTempMemOverride();
    sp30.Init("music.ini", 0, NULL);
    MKHeap::DeactivateTempMemOverride();
    var_r28_1098 = 0;
    var_r27_1101 = sp30.GetFirstLine();
loop_9:
    if (var_r27_1101 != NULL) {
        if (var_r27_1101->IsField("defaults") == 0) {
            trackCount += 1;
        }
        var_r28_1098 = strlen((const char *) var_r27_1101->GetFieldName()) + var_r28_1098 + 1;
        var_r29_1122 = var_r27_1101->unkC->GetSubLine(var_r27_1101);
loop_7:
        if (var_r29_1122 != NULL) {
            if (var_r29_1122->IsField("filename") != 0) {
                var_r28_1098 = strlen((const char *) var_r29_1122->GetString(0)) + var_r28_1098 + 1;
            }
            var_r29_1122 = var_r29_1122->unkC->GetNextLine(var_r29_1122);
            goto loop_7;
        }
        var_r27_1101 = var_r27_1101->unkC->GetNextLine(var_r27_1101);
        goto loop_9;
    }
    stringTable.Init(var_r28_1098);
    temp_r26_1155 = trackCount * 0x28;
    if (MKHeap::Current() != NULL) {
        var_r3_1163 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_1155, NULL, 0);
    } else {
        var_r3_1163 = malloc(temp_r26_1155);
    }
    pTracks = var_r3_1163;
    memset(var_r3_1163, 0, trackCount * 0x28);
    var_r26_1175 = 0;
    var_r29_1178 = sp30.GetFirstLine();
loop_33:
    if (var_r29_1178 != NULL) {
        if (var_r29_1178->IsField("defaults") != 0) {
            var_r28_1188 = (s8 *) sp8;
            sp8[8] = 0;
            ((s8 *) sp8)[0x24] = 0;
        } else {
            var_r28_1188 = (s8 *) pTracks + var_r26_1175;
            var_r26_1175 += 0x28;
            memcpy(var_r28_1188, sp8, 0x28U);
            M2C_FIELD(var_r28_1188, s32 *, 0) = stringTable.Add((const char *) var_r29_1178->GetFieldName());
            M2C_FIELD(var_r28_1188, s32 *, 0x20) = 0;
            M2C_FIELD(var_r28_1188, s8 *, 0x24) = 0;
        }
        var_r27_1213 = var_r29_1178->unkC->GetSubLine(var_r29_1178);
loop_31:
        if (var_r27_1213 != NULL) {
            if (var_r27_1213->IsField("filename") != 0) {
                M2C_FIELD(var_r28_1188, s32 *, 4) = stringTable.Add((const char *) var_r27_1213->GetString(0));
            } else if (var_r27_1213->IsField("musicType") != 0) {
                M2C_FIELD(var_r28_1188, s32 *, 0x14) = (s32) (stricmp((s8 *) var_r27_1213->GetString(0), (s8 *) "sting") == 0);
            } else {
                var_r31_1254 = 0;
                if ((var_r27_1213->LoadInt("volume", (int *) (var_r28_1188 + 8), 0) != 0) || (var_r27_1213->LoadFloat("fadeInTime", (float *) (var_r28_1188 + 0xC), 0) != 0) || (var_r27_1213->LoadFloat("fadeOutTime", (float *) (var_r28_1188 + 0x10), 0) != 0) || (var_r27_1213->LoadFloat("stingMusicTime", (float *) (var_r28_1188 + 0x18), 0) != 0) || (var_r27_1213->LoadBool("duckDuringCutscene", (bool *) (var_r28_1188 + 0x1C), 0) != 0)) {
                    var_r31_1254 = 1;
                }
                if (var_r31_1254 == 0) {
                    var_r27_1213->LoadBool("playGameMusicAfterSting", (bool *) (var_r28_1188 + 0x1D), 0);
                }
            }
            var_r27_1213 = var_r27_1213->unkC->GetNextLine(var_r27_1213);
            goto loop_31;
        }
        var_r29_1178 = var_r29_1178->unkC->GetNextLine(var_r29_1178);
        goto loop_33;
    }
    sp30.Deinit();
}

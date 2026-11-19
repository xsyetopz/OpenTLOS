u8 PhrasePlayer_LoadNextPhrase();

s32 PhrasePlayer_PlayEvent(const char *arg0) {
    s32 var_r27_352;
    s32 var_r27_380;
    s32 var_r29_353;
    s32 var_r29_381;
    u8 var_r28_331;
    void *var_r31_350;

    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r28_331 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) M2C_FIELD(&gb, void **, 0xC)) + 0x24))->GetState() != 0)) {
            var_r28_331 = 1;
        }
        if (var_r28_331 != 0) {
            return 0;
        }
    }
    var_r31_350 = NULL;
    var_r27_352 = 0;
    var_r29_353 = 0;
loop_11:
    if (var_r27_352 < (s32) M2C_FIELD(&phraseData, s32 *, 0x48)) {
        if (stricmp((s8 *) M2C_FIELD(M2C_FIELD(&phraseData, s8 **, 0x3C), const char **, var_r29_353), (s8 *) arg0) == 0) {
            var_r31_350 = (void *) (M2C_FIELD(&phraseData, s8 **, 0x3C) + var_r29_353);
        } else {
            var_r27_352 += 1;
            var_r29_353 += 0x18;
            goto loop_11;
        }
    }
    if ((var_r31_350 == NULL) && ((u32) M2C_FIELD(&phraseData, u32 *, 0x40) != 0U)) {
        var_r27_380 = 0;
        var_r29_381 = 0;
loop_18:
        if (var_r27_380 < (s32) M2C_FIELD(&phraseData, s32 *, 0x4C)) {
            if (stricmp((s8 *) M2C_FIELD(M2C_FIELD(&phraseData, s8 **, 0x40), const char **, var_r29_381), (s8 *) arg0) == 0) {
                var_r31_350 = (void *) (M2C_FIELD(&phraseData, s8 **, 0x40) + var_r29_381);
            } else {
                var_r27_380 += 1;
                var_r29_381 += 0x18;
                goto loop_18;
            }
        }
    }
    if ((var_r31_350 != NULL) && (((u8) M2C_FIELD(var_r31_350, u8 *, 0x14) != 0) || ((void *) M2C_FIELD(&phraseData, void **, 0x44) == NULL))) {
        PhrasePlayer_StopAnyEvent();
        M2C_FIELD(&phraseData, void **, 0x44) = var_r31_350;
        if ((s32) M2C_FIELD(var_r31_350, s32 *, 0x10) == 2) {
            M2C_FIELD(var_r31_350, s32 *, 8) = -1;
        }
        if (PhrasePlayer_LoadNextPhrase() != 0) {
            return M2C_FIELD(&phraseData, s32 *, 0x30);
        }
        return 0;
    }
    return 0;
}

void Phrase_Unload() {
    PhraseEvent *temp_r30_943;

    if ((s32) M2C_FIELD(&phraseData, s32 *, 0x28) > -1) {
        MKPackage_QCancel(M2C_FIELD(&phraseData, s32 *, 0x28));
        while (MKPackage_QIsLoaded(M2C_FIELD(&phraseData, s32 *, 0x28), NULL, NULL) == 0) {
            MKPackage_Update();
        }
        MKPackage_QFree(M2C_FIELD(&phraseData, s32 *, 0x28));
        M2C_FIELD(&phraseData, s32 *, 0x28) = -1;
    }
    if ((s32) M2C_FIELD(&phraseData, s32 *, 0x20) > -1) {
        KDSound_Stop((int *) (&phraseData + 0x20));
        M2C_FIELD(&phraseData, s32 *, 0x20) = 0;
    }
    temp_r30_943 = M2C_FIELD(&phraseData, PhraseEvent **, 0x38);
    if (temp_r30_943 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30_943, NULL, 0);
        } else {
            free(temp_r30_943);
        }
        M2C_FIELD(&phraseData, PhraseEvent **, 0x38) = NULL;
        ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle(NULL, 9, 0U);
    }
    if ((s32) M2C_FIELD(&phraseData, s32 *, 0x2C) > -1) {
        Sound_UnloadBank(M2C_FIELD(&phraseData, s32 *, 0x2C));
        M2C_FIELD(&phraseData, s32 *, 0x2C) = -1;
    }
    strcpy((char *) &phraseData, "");
    M2C_FIELD(&phraseData, s32 *, 0x30) = 0;
    M2C_FIELD(&phraseData, s32 *, 0x24) = 0;
}

void Phrase_Update();
u8 PhrasePlayer_LoadNextPhrase();

void PhrasePlayer_Update() {
    f32 temp_f0_467;
    f32 var_f1_463;

    Phrase_Update();
    if ((void *) M2C_FIELD(&phraseData, void **, 0x44) != NULL) {
        if ((u8) M2C_FIELD(&gb, u8 *, 0x395) != 0) {
            return;
        }
        var_f1_463 = 0.0f;
        if (M2C_FIELD(&phraseData, f32 *, 0x34) > 0.0f) {
            temp_f0_467 = M2C_FIELD(&phraseData, f32 *, 0x34) - gUpdateTimeDelta;
            if (temp_f0_467 < 0.0f) {

            } else {
                var_f1_463 = temp_f0_467;
            }
            M2C_FIELD(&phraseData, f32 *, 0x34) = var_f1_463;
            return;
        }
        if (((void *) M2C_FIELD(&phraseData, void **, 0x44) != NULL) && ((s32) M2C_FIELD(M2C_FIELD(&phraseData, void **, 0x44), s32 *, 0x10) != 2) && ((s32) M2C_FIELD(&phraseData, s32 *, 0x24) == 0)) {
            M2C_FIELD(&phraseData, void **, 0x44) = NULL;
            return;
        }
        if (((void *) M2C_FIELD(&phraseData, void **, 0x44) != NULL) && ((s32) M2C_FIELD(M2C_FIELD(&phraseData, void **, 0x44), s32 *, 0x10) == 2) && ((s32) M2C_FIELD(&phraseData, s32 *, 0x24) == 0) && (M2C_FIELD(&phraseData, f32 *, 0x34) == 0.0f) && (PhrasePlayer_LoadNextPhrase() == 0)) {
            M2C_FIELD(&phraseData, void **, 0x44) = NULL;
        }
    }
}

void Phrase_Unload();

void PhrasePlayer_StopAnyEvent() {
    Phrase_Unload();
    strcpy((char *) &phraseData, "");
    M2C_FIELD(&phraseData, s32 *, 0x44) = 0;
    M2C_FIELD(&phraseData, f32 *, 0x34) = 0.0f;
}

void Phrase_Update();

s32 Phrase_Play(const char *arg0) {
    s32 temp_r3_1224;

    if ((s32) M2C_FIELD(&phraseData, s32 *, 0x24) != 0) {
        return 0;
    }
    temp_r3_1224 = M2C_FIELD(&phraseData, s32 *, 0x30) + 1;
    M2C_FIELD(&phraseData, s32 *, 0x30) = temp_r3_1224;
    if (temp_r3_1224 == 0) {
        M2C_FIELD(&phraseData, s32 *, 0x30) = (s32) (temp_r3_1224 + 1);
    }
    M2C_FIELD(&phraseData, s32 *, 0x24) = 1;
    strcpy((char *) &phraseData, arg0);
    Phrase_Update();
    return M2C_FIELD(&phraseData, s32 *, 0x30);
}

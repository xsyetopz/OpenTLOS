s8 *PhrasePlayer_GetCurrentActor() {
    s32 temp_r0_29;
    s32 var_r4_28;

    if (strcmp((const char *) &phraseData, "") == 0) {
        return (s8 *) &phraseData;
    }
    var_r4_28 = lit_771;
    temp_r0_29 = strlen((const char *) &phraseData) - 2;
    if (temp_r0_29 > var_r4_28) {
        var_r4_28 = temp_r0_29;
    }
    return &phraseData + var_r4_28;
}

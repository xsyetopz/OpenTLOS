s32 GameLanguage_Count() {
    s32 sp8;
    s32 var_r31_278;

    var_r31_278 = 0;
    if (GameLanguage_GetFirst((int *) &sp8, 0) != 0) {
        do {
            var_r31_278 += 1;
        } while (GameLanguage_GetNext((int *) &sp8, 0) != 0);
    }
    return var_r31_278;
}

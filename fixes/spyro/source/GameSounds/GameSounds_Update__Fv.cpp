void GameSounds_Update() {
    s32 var_r31_16;

    KDSound_Update();
    var_r31_16 = 0x64;
    goto cond_2;
loop_2:
    *M2C_FIELD(pCurrentID, s32 **, 0) = KDSound_ResolveSound((const char *) M2C_FIELD(pCurrentID, s8 **, 4), (int *) &hint);
    pCurrentID = (M2C_UNK *) ((s8 *) pCurrentID + 8);
cond_2:
    if (var_r31_16-- == 0) {
        return;
    }
    if ((s32 *) M2C_FIELD(pCurrentID, s32 **, 0) != NULL) {
        goto loop_2;
    }
}

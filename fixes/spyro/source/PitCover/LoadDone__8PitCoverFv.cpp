s32 PitCover::LoadDone() {
    s32 temp_r0_286;
    s32 var_r31_276;
    s32 var_r29_274;
    u16 temp_r3_284;
    void *temp_r3_292;

    KDProp::LoadDone();
    var_r29_274 = 0;
    var_r31_276 = 0;
    do {
        temp_r3_284 = Tools_GetMatchingRefPointIndex(this->unk4, (const char *) Str_Printf("r_fxemit%d", var_r29_274));
        var_r29_274 += 1;
        temp_r0_286 = var_r31_276 + 0x90;
        var_r31_276 += 4;
        M2C_FIELD(this, s32 *, temp_r0_286) = (s32) temp_r3_284;
    } while (var_r29_274 < 4);
    temp_r3_292 = this->unk0;
    M2C_FIELD(temp_r3_292, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r3_292, s32 *, 0xC) | 0x10);
}

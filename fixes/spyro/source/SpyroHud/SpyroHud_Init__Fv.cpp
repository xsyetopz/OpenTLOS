void SpyroHud_Init() {
    HudItem *temp_r3_283;
    s32 var_r24_276;
    s32 var_r29_279;
    s32 var_r30_278;
    s32 var_r31_277;
    void *temp_r25_282;
    void *temp_r5_281;

    memset(&hudData, 0, 0x70U);
    memset(&hudItem, 0, 0x40U);
    var_r24_276 = 0;
    var_r31_277 = 0;
    var_r30_278 = 0;
    var_r29_279 = 0;
    do {
        temp_r5_281 = (s8 *) &hudDesc + var_r29_279;
        temp_r25_282 = (s8 *) &hudData + var_r30_278;
        temp_r3_283 = (HudItem *) ((s8 *) &hudItem + var_r31_277);
        temp_r3_283->unk14 = (long) (temp_r25_282);
        M2C_FIELD(temp_r3_283, s32 *, 4) = M2C_FIELD(temp_r5_281, s32 *, 4);
        M2C_FIELD(temp_r3_283, s32 *, 8) = M2C_FIELD(temp_r5_281, s32 *, 8);
        M2C_FIELD(temp_r3_283, s32 *, 0xC) = M2C_FIELD(temp_r5_281, s32 *, 0xC);
        M2C_FIELD(temp_r25_282, void **, 0) = temp_r5_281;
        temp_r3_283->unk18 = M2C_FIELD(temp_r5_281, u8 *, 0xB0);
        Hud_Add(temp_r3_283);
        var_r24_276 += 1;
        M2C_FIELD(temp_r25_282, f32 *, 4) = 0.0f;
        var_r31_277 += 0x20;
        var_r30_278 += 0x38;
        var_r29_279 += 0xB4;
    } while (var_r24_276 < 2);
}

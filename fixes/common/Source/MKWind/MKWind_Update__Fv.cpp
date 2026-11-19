void MKWind_Update() {
    s32 var_r23_426;
    s32 var_r30_430;
    s32 var_r31_427;
    s8 *temp_r28_436;
    s8 *base_r24_170;
    s8 *base_r25_150;
    f32 *temp_r26_437;
    f32 *temp_r27_439;

    var_r23_426 = 0;
    var_r31_427 = 0;
    var_r30_430 = 0;
    base_r24_170 = (s8 *) &wind + 0x170;
    base_r25_150 = (s8 *) &wind + 0x150;
    M2C_FIELD(&wind, f32 *, 0x190) = (f32) (M2C_FIELD(&wind, f32 *, 0x190) + gUpdateTimeDelta);
    do {
        temp_r28_436 = (s8 *) &wind + var_r31_427;
        temp_r26_437 = (f32 *) (base_r24_170 + var_r30_430);
        temp_r27_439 = (f32 *) (base_r25_150 + var_r30_430);
        _table_sincosf(M2C_FIELD(&wind, f32 *, 0x190) * M2C_FIELD(temp_r28_436, f32 *, 0x20), *temp_r26_437, *temp_r27_439);
        var_r23_426 += 1;
        var_r31_427 += 0x28;
        var_r30_430 += 4;
        *temp_r27_439 = (f32) (*temp_r27_439 * M2C_FIELD(temp_r28_436, f32 *, 0x24));
        *temp_r26_437 = (f32) (*temp_r26_437 * M2C_FIELD(temp_r28_436, f32 *, 0x24));
    } while (var_r23_426 < 8);
}

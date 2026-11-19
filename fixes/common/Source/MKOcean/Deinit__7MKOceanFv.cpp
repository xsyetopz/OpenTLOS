void MKOcean::Deinit() {
    u8 *var_r4_328;
    u8 *var_r4_361;
    u8 *var_r6_336;

    var_r4_328 = (u8 *) M2C_FIELD(&areaList, void **, 4);
    if ((u32) var_r4_328 == M2C_FIELD(&areaList, u32 *, 8)) {
        var_r4_328 = NULL;
    }
    var_r6_336 = var_r4_328;
    while (var_r6_336 != NULL) {
        if (M2C_FIELD(var_r6_336, u32 *, 0x10) == (u32) this) {
            if (var_r6_336 != (u8 *) M2C_FIELD(&areaList, void **, 4)) {
                M2C_FIELD(var_r6_336, f32 *, 0) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 0);
                M2C_FIELD(var_r6_336, f32 *, 4) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 4);
                M2C_FIELD(var_r6_336, f32 *, 8) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 8);
                M2C_FIELD(var_r6_336, f32 *, 0xC) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), f32 *, 0xC);
                M2C_FIELD(var_r6_336, u32 *, 0x10) = M2C_FIELD(M2C_FIELD(&areaList, void **, 4), u32 *, 0x10);
            }
            M2C_FIELD(&areaList, void **, 4) = ((u8 *) M2C_FIELD(&areaList, void **, 4)) + 0x14;
        }
        var_r4_361 = var_r6_336 + 0x14;
        if ((u32) var_r4_361 >= M2C_FIELD(&areaList, u32 *, 8)) {
            var_r4_361 = NULL;
        }
        var_r6_336 = var_r4_361;
    }
    ((MKFFTBaseType *) this)->Deinit();
}

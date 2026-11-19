void FogPoints_InitModule() {
    M2C_UNK *var_r3_2153;

    M2C_FIELD(&fog, s32 *, 4) = 0x14;
    M2C_FIELD(&fog, s32 *, 8) = 0x2710;
    if (MKHeap::Current() != NULL) {
        var_r3_2153 = (long *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x640, NULL, 0));
    } else {
        var_r3_2153 = malloc(0x640);
    }
    M2C_FIELD(&fog, M2C_UNK **, 0) = var_r3_2153;
    memset(var_r3_2153, 0, M2C_FIELD(&fog, s32 *, 4) * (M2C_FIELD(&fog, s32 *, 4) * 4));
    M2C_FIELD(&fog, u8 *, 0x10) = 0;
}

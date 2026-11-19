void MKMetadata_OpenFromBuffer(const void *arg0, const void *arg1, int *arg2) {
    void *var_r3_118;
    u8 *base;
    u32 count1;
    u32 count2;
    u32 i;
    u32 j;
    u32 k;
    u32 word;
    u32 off;

    if (MKHeap::Current() != NULL) {
        var_r3_118 = ((MKHeap *) (MKHeap::Current()))->Alloc(8, NULL, 0);
    } else {
        var_r3_118 = malloc(8);
    }
    M2C_FIELD(var_r3_118, void **, 0) = (void *) (arg0);
    M2C_FIELD(var_r3_118, void **, 4) = (void *) (arg1);
    base = (u8 *) M2C_FIELD(var_r3_118, void **, 0);
    count1 = M2C_FIELD(base, u32 *, 4);
    for (i = 0; i < count1; i++) {
        M2C_FIELD(base, u32 *, 0x14 + i * 8) += (u32) base;
    }
    count2 = M2C_FIELD(base, u32 *, 0xC);
    for (j = 0; j < count2; j++) {
        word = M2C_FIELD(base, u32 *, 0x10 + count1 * 8 + j * 4);
        for (k = 0; k < (word & 0xFF); k++) {
            off = (word >> 8) + k * 4;
            if (M2C_FIELD(base, u32 *, off) != 0) {
                M2C_FIELD(base, u32 *, off) += (u32) base;
            }
        }
    }
    if (arg2 != NULL) {
        *arg2 = (s32) count1;
    }
}

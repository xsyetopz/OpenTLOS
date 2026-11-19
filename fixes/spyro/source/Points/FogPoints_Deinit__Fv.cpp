void FogPoints_Deinit() {
    u32 var_r3_1775;
    u32 var_r4_1773;
    u32 var_r30_1774;
    u32 temp_r0_1783;
    u32 temp_r0_1778;
    u32 temp_r0_1797;

    if (M2C_FIELD(&fog, u8 *, 0x10) != 0) {
        var_r4_1773 = (u32) M2C_FIELD(&fog, M2C_UNK **, 0xC);
        var_r30_1774 = var_r4_1773;
        var_r3_1775 = var_r4_1773;
loop_4:
        temp_r0_1783 = M2C_FIELD(var_r3_1775, u32 *, -4);
        var_r3_1775 -= 4;
        if (temp_r0_1783 != 0U) {
            temp_r0_1778 = M2C_FIELD(var_r3_1775, u32 *, 0);
            if (temp_r0_1778 < var_r30_1774) {
                var_r30_1774 = temp_r0_1778;
            }
            goto loop_4;
        }
        if (var_r3_1775 != (u32) &gEmptyPtrListDL) {
loop_10:
            temp_r0_1797 = M2C_FIELD(var_r4_1773, u32 *, 0);
            if (temp_r0_1797 != 0U) {
                if (temp_r0_1797 < var_r30_1774) {
                    var_r30_1774 = temp_r0_1797;
                }
                var_r4_1773 += 4;
                goto loop_10;
            }
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free((const void *) var_r30_1774, NULL, 0);
            } else {
                free((M2C_UNK *) var_r30_1774);
            }
        }
        M2C_FIELD(&fog, M2C_UNK **, 0xC) = NULL;
    }
    M2C_FIELD(&fog, u8 *, 0x10) = 0;
    memset(M2C_FIELD(&fog, M2C_UNK **, 0), 0, M2C_FIELD(&fog, s32 *, 4) * (M2C_FIELD(&fog, s32 *, 4) * 4));
}

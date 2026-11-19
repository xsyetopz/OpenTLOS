void MeleeTrailsDescriptor::Deinit() {
    u8 *temp_r0_628;
    u8 *temp_r0_647;
    u8 *var_r31_624;
    u8 *var_r3_625;
    u8 *var_r4_623;
    u32 temp_r0_633;

    var_r4_623 = M2C_FIELD(this, u8 **, 0xE4);
    var_r31_624 = var_r4_623;
    var_r3_625 = var_r4_623;
loop_3:
    temp_r0_633 = M2C_FIELD(var_r3_625, u32 *, -4);
    var_r3_625 -= 4;
    if (temp_r0_633 != 0U) {
        temp_r0_628 = M2C_FIELD(var_r3_625, u8 **, 0);
        if (temp_r0_628 < var_r31_624) {
            var_r31_624 = temp_r0_628;
        }
        goto loop_3;
    }
    if (var_r3_625 != (u8 *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_647 = M2C_FIELD(var_r4_623, u8 **, 0);
        if (temp_r0_647 != NULL) {
            if (temp_r0_647 < var_r31_624) {
                var_r31_624 = temp_r0_647;
            }
            var_r4_623 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_624, NULL, 0);
        } else {
            free((M2C_UNK *) var_r31_624);
        }
    }
    M2C_FIELD(this, u8 **, 0xE4) = NULL;
    KDPropExDescriptor::Deinit();
}

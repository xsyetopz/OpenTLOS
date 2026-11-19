void WhirlWindFX::Deinit() {
    u32 *var_r4_46;
    u32 *var_r3_48;
    u32 var_r31_47;
    u32 temp_r0_56;
    u32 temp_r0_51;
    u32 temp_r0_70;

    var_r4_46 = (u32 *) this->unk4C;
    var_r31_47 = (u32) var_r4_46;
    var_r3_48 = var_r4_46;
loop_3:
    temp_r0_56 = M2C_FIELD(var_r3_48, u32 *, -4);
    var_r3_48 -= 1;
    if (temp_r0_56 != 0U) {
        temp_r0_51 = *var_r3_48;
        if (temp_r0_51 < var_r31_47) {
            var_r31_47 = temp_r0_51;
        }
        goto loop_3;
    }
    if (var_r3_48 != (u32 *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_70 = *var_r4_46;
        if (temp_r0_70 != 0U) {
            if (temp_r0_70 < var_r31_47) {
                var_r31_47 = temp_r0_70;
            }
            var_r4_46 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r31_47, NULL, 0);
        } else {
            free((MKHeap *) var_r31_47);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}

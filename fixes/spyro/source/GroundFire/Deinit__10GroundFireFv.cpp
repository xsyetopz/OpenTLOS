void GroundFire::Deinit() {
    MKHeap *temp_r0_66;
    MKHeap *temp_r0_85;
    MKHeap *var_r31_62;
    u8 *var_r3_63;
    u8 *var_r4_61;
    u32 temp_r0_71;

    var_r4_61 = (u8 *) this->unk0;
    var_r31_62 = this->unk0;
    var_r3_63 = (u8 *) this->unk0;
loop_3:
    temp_r0_71 = M2C_FIELD(var_r3_63, u32 *, -4);
    var_r3_63 -= 4;
    if (temp_r0_71 != 0U) {
        temp_r0_66 = M2C_FIELD(var_r3_63, MKHeap **, 0);
        if (temp_r0_66 < var_r31_62) {
            var_r31_62 = temp_r0_66;
        }
        goto loop_3;
    }
    if ((void *) var_r3_63 != (void *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_85 = M2C_FIELD(var_r4_61, MKHeap **, 0);
        if (temp_r0_85 != NULL) {
            if (temp_r0_85 < var_r31_62) {
                var_r31_62 = temp_r0_85;
            }
            var_r4_61 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_62, NULL, 0);
        } else {
            free(var_r31_62);
        }
    }
    this->unk0 = NULL;
}

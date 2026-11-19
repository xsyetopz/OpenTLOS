void ConvexityDebris::Deinit() {
    MKHeap *temp_r0_63;
    MKHeap *temp_r0_82;
    MKHeap *temp_r3_54;
    MKHeap *var_r31_46;
    MKHeap *var_r31_59;
    MKHeap *var_r3_60;
    MKHeap *var_r4_58;
    u32 temp_r0_68;

    var_r31_46 = this->unk4C;
loop_2:
    if (var_r31_46 != NULL) {
        temp_r3_54 = var_r31_46->unk0;
        if (temp_r3_54 != NULL) {
            KDSound_Stop((int *) temp_r3_54);
            var_r31_46 += 4;
            goto loop_2;
        }
    }
    var_r4_58 = this->unk4C;
    var_r31_59 = var_r4_58;
    var_r3_60 = var_r4_58;
loop_7:
    temp_r0_68 = M2C_FIELD(var_r3_60, u32 *, -4);
    var_r3_60 -= 4;
    if (temp_r0_68 != 0U) {
        temp_r0_63 = var_r3_60->unk0;
        if (temp_r0_63 < var_r31_59) {
            var_r31_59 = temp_r0_63;
        }
        goto loop_7;
    }
    if (var_r3_60 != (MKHeap *) &gEmptyPtrListDL) {
loop_13:
        temp_r0_82 = var_r4_58->unk0;
        if (temp_r0_82 != NULL) {
            if (temp_r0_82 < var_r31_59) {
                var_r31_59 = temp_r0_82;
            }
            var_r4_58 += 4;
            goto loop_13;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_59, NULL, 0);
        } else {
            free(var_r31_59);
        }
    }
    this->unk4C = NULL;
    this->unk50.Deinit();
    MKProp::Deinit();
}

void SlimeTrailFXManager::Deinit() {
    SlimeTrailFX *temp_r3_34;
    SlimeTrailFX **var_r31_26;
    void **var_r4_38;
    void **var_r3_40;
    void *var_r31_39;
    void *temp_r0_43;
    void *temp_r0_62;
    u32 temp_r0_48;

    while (*(void **) this->unk0 != NULL) {
        this->unk0 = (MKHeap *) ((s8 *) this->unk0 + 4);
    }
    var_r31_26 = (SlimeTrailFX **) ((s8 *) this->unk0 - 4);
    while (var_r31_26 != NULL && *var_r31_26 != NULL) {
        temp_r3_34 = *var_r31_26;
        temp_r3_34->Deinit();
        var_r31_26 -= 1;
    }
    var_r4_38 = (void **) this->unk0;
    var_r31_39 = var_r4_38;
    var_r3_40 = var_r4_38;
loop_10:
    temp_r0_48 = M2C_FIELD(var_r3_40, u32 *, -4);
    var_r3_40 -= 1;
    if (temp_r0_48 != 0U) {
        temp_r0_43 = *var_r3_40;
        if (temp_r0_43 < var_r31_39) {
            var_r31_39 = temp_r0_43;
        }
        goto loop_10;
    }
    if ((void *) var_r3_40 != (void *) &gEmptyPtrListDL) {
        temp_r0_62 = *var_r4_38;
        while (temp_r0_62 != NULL) {
            if (temp_r0_62 < var_r31_39) {
                var_r31_39 = temp_r0_62;
            }
            var_r4_38 += 1;
            temp_r0_62 = *var_r4_38;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_39, NULL, 0);
        } else {
            free((MKHeap *) var_r31_39);
        }
    }
    this->unk0 = NULL;
}

void GlowingPropManager::Deinit() {
    MKProp ***var_r31_35;
    MKProp ***var_r3_36;
    MKProp ***var_r4_34;
    u32 temp_r0_39;
    u32 temp_r0_44;
    u32 temp_r0_58;

    var_r4_34 = this->unk0;
    var_r31_35 = var_r4_34;
    var_r3_36 = var_r4_34;
    goto test_3;
body_3:
    temp_r0_39 = *(u32 *) var_r3_36;
    if (temp_r0_39 < (u32) var_r31_35) {
        var_r31_35 = (MKProp ***) temp_r0_39;
    }
test_3:
    var_r3_36 = (MKProp ***) ((u8 *) var_r3_36 - 4);
    temp_r0_44 = M2C_FIELD(var_r3_36, u32 *, 0);
    if (temp_r0_44 != 0U) {
        goto body_3;
    }
    if ((s32 *) var_r3_36 != &gEmptyPtrListDL) {
        for (; (temp_r0_58 = *(u32 *) var_r4_34) != 0U; var_r4_34 = (MKProp ***) ((u8 *) var_r4_34 + 4)) {
            if (temp_r0_58 < (u32) var_r31_35) {
                var_r31_35 = (MKProp ***) temp_r0_58;
            }
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_35, NULL, 0);
        } else {
            free(var_r31_35);
        }
    }
    this->unk0 = NULL;
}

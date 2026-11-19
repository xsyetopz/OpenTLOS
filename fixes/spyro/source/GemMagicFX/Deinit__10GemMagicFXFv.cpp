void GemMagicFX::Deinit() {
    MKHeap *temp_r31_240;
    MKHeap *var_r31_255;
    MKHeap *var_r3_256;
    MKHeap *var_r4_254;
    u32 temp_r0_259;
    u32 temp_r0_264;
    u32 temp_r0_278;

    temp_r31_240 = this->unk50;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_240, NULL, 0);
    } else {
        free(temp_r31_240);
    }
    var_r4_254 = this->unk4C;
    var_r31_255 = var_r4_254;
    var_r3_256 = var_r4_254;
    goto test_6;
body_6:
    temp_r0_259 = *(u32 *) var_r3_256;
    if (temp_r0_259 < (u32) var_r31_255) {
        var_r31_255 = (MKHeap *) temp_r0_259;
    }
test_6:
    var_r3_256 = (MKHeap *) ((u8 *) var_r3_256 - 4);
    temp_r0_264 = M2C_FIELD(var_r3_256, u32 *, 0);
    if (temp_r0_264 != 0U) {
        goto body_6;
    }
    if ((s32 *) var_r3_256 != &gEmptyPtrListDL) {
        for (; (temp_r0_278 = *(u32 *) var_r4_254) != 0U; var_r4_254 = (MKHeap *) ((u8 *) var_r4_254 + 4)) {
            if (temp_r0_278 < (u32) var_r31_255) {
                var_r31_255 = (MKHeap *) temp_r0_278;
            }
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_255, NULL, 0);
        } else {
            free(var_r31_255);
        }
    }
    this->unk4C = NULL;
    MKMaterial_Destroy(this->unk54);
    MKProp::Deinit();
}

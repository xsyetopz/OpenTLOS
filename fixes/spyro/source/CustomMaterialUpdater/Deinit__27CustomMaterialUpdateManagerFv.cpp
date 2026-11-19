void CustomMaterialUpdateManager::Deinit() {
    CustomMaterialUpdater **var_r31_252;
    CustomMaterialUpdater **var_r3_253;
    CustomMaterialUpdater **var_r4_251;
    CustomMaterialUpdater **temp_r0_256;
    CustomMaterialUpdater **temp_r0_275;
    u32 temp_r0_261;

    var_r4_251 = this->unk0;
    var_r31_252 = var_r4_251;
    var_r3_253 = var_r4_251;
loop_3:
    temp_r0_261 = M2C_FIELD(var_r3_253, u32 *, -4);
    var_r3_253 -= 4;
    if (temp_r0_261 != 0U) {
        temp_r0_256 = (CustomMaterialUpdater **) *var_r3_253;
        if (temp_r0_256 < var_r31_252) {
            var_r31_252 = temp_r0_256;
        }
        goto loop_3;
    }
    if (var_r3_253 != (CustomMaterialUpdater **) &gEmptyPtrListDL) {
loop_9:
        temp_r0_275 = (CustomMaterialUpdater **) *var_r4_251;
        if (temp_r0_275 != NULL) {
            if (temp_r0_275 < var_r31_252) {
                var_r31_252 = temp_r0_275;
            }
            var_r4_251 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_252, NULL, 0);
        } else {
            free(var_r31_252);
        }
    }
    this->unk0 = NULL;
}

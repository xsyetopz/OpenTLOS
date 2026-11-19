void LightningStrikeFXDescriptor::Deinit() {
    u32 *var_r3;
    u32 *var_r4;
    u32 var_r31;
    u32 temp_r0;
    MKMaterial *temp_r3;
    ManagedLight *temp_r4;

    temp_r3 = this->unk94;
    if (temp_r3 != NULL) {
        MKMaterial_Destroy(temp_r3);
        this->unk94 = NULL;
    }
    temp_r4 = this->unk60;
    if (temp_r4 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4);
        this->unk60 = NULL;
    }
    var_r4 = (u32 *) this->unk98;
    var_r31 = (u32) var_r4;
    var_r3 = var_r4 - 1;
    temp_r0 = *var_r3;
    while (temp_r0 != 0) {
        if (temp_r0 < var_r31) {
            var_r31 = temp_r0;
        }
        var_r3 = var_r3 - 1;
        temp_r0 = *var_r3;
    }
    if (var_r3 != (u32 *) &gEmptyPtrListDL) {
        var_r4 = (u32 *) this->unk98;
        temp_r0 = *var_r4;
        while (temp_r0 != 0) {
            if (temp_r0 < var_r31) {
                var_r31 = temp_r0;
            }
            var_r4 = var_r4 + 1;
            temp_r0 = *var_r4;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r31, NULL, 0);
        } else {
            free((MKVector3 *) var_r31);
        }
    }
    this->unk98 = NULL;
    MKPropDescriptor::Deinit();
}

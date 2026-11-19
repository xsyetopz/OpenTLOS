void GoopFXDescriptor::Deinit() {
    GoopFXDescriptor::Goop **var_r31_1207;
    GoopFXDescriptor::Goop **var_r3_1208;
    GoopFXDescriptor::Goop **var_r4_1206;
    GoopFXDescriptor::Goop *temp_r0_1211;
    GoopFXDescriptor::Goop *temp_r0_1230;
    MKMaterial *temp_r3_1201;
    u32 temp_r0_1216;

    temp_r3_1201 = this->unkE0;
    if (temp_r3_1201 != NULL) {
        MKMaterial_Destroy(temp_r3_1201);
    }
    var_r4_1206 = this->unkE8;
    var_r31_1207 = var_r4_1206;
    var_r3_1208 = var_r4_1206 - 1;
    temp_r0_1216 = (u32) *var_r3_1208;
    while (temp_r0_1216 != 0U) {
        temp_r0_1211 = *var_r3_1208;
        if ((void *) temp_r0_1211 < (void *) var_r31_1207) {
            var_r31_1207 = (GoopFXDescriptor::Goop **) temp_r0_1211;
        }
        var_r3_1208 -= 1;
        temp_r0_1216 = (u32) *var_r3_1208;
    }
    if ((void *) var_r3_1208 != (void *) &gEmptyPtrListDL) {
        temp_r0_1230 = *var_r4_1206;
        while (temp_r0_1230 != NULL) {
            if ((void *) temp_r0_1230 < (void *) var_r31_1207) {
                var_r31_1207 = (GoopFXDescriptor::Goop **) temp_r0_1230;
            }
            var_r4_1206 += 1;
            temp_r0_1230 = *var_r4_1206;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(var_r31_1207, NULL, 0);
        } else {
            free(var_r31_1207);
        }
    }
    this->unkE8 = NULL;
    KDPropExDescriptor::Deinit();
}

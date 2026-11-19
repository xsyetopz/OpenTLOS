void DynamiteExplosion::Deinit() {
    u32 *var_r3;
    u32 *var_r4;
    u32 var_r31;
    u32 temp_r0;

    var_r4 = (u32 *) this->unk50;
    var_r31 = (u32) var_r4;
    var_r3 = var_r4;
    while (1) {
        var_r3 -= 1;
        temp_r0 = *var_r3;
        if (temp_r0 == 0) {
            break;
        }
        if (temp_r0 < var_r31) {
            var_r31 = temp_r0;
        }
    }
    if (var_r3 != (u32 *) &gEmptyPtrListDL) {
        while (1) {
            temp_r0 = *var_r4;
            if (temp_r0 == 0) {
                break;
            }
            if (temp_r0 < var_r31) {
                var_r31 = temp_r0;
            }
            var_r4 += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((const void *) var_r31, NULL, 0);
        } else {
            free((DynamiteExplosion::Explosion **) var_r31);
        }
    }
    this->unk50 = NULL;
    MKProp::Deinit();
}

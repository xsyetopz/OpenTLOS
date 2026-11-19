void ElementalRing::Deinit() {
    KDSoundFlangedFader **var_r31_186;
    KDSoundFlangedFader *temp_r3_194;
    u32 *var_r3_200;
    u32 *var_r4_198;
    u32 temp_r0_208;
    u32 temp_r0_203;
    u32 temp_r0_222;
    u32 var_r31_199;

    var_r31_186 = this->unk4C;
    while (var_r31_186 != NULL && (temp_r3_194 = *var_r31_186) != NULL) {
        temp_r3_194->Deinit();
        var_r31_186 += 1;
    }
    var_r4_198 = (u32 *) this->unk4C;
    var_r31_199 = (u32) var_r4_198;
    var_r3_200 = var_r4_198;
    while ((var_r3_200 -= 1, temp_r0_208 = *var_r3_200) != 0U) {
        temp_r0_203 = *var_r3_200;
        if (temp_r0_203 < var_r31_199) {
            var_r31_199 = temp_r0_203;
        }
    }
    if ((u32) var_r3_200 != (u32) &gEmptyPtrListDL) {
        temp_r0_222 = *var_r4_198;
        while (temp_r0_222 != 0U) {
            if (temp_r0_222 < var_r31_199) {
                var_r31_199 = temp_r0_222;
            }
            var_r4_198 += 1;
            temp_r0_222 = *var_r4_198;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r31_199, NULL, 0);
        } else {
            free((KDSoundFlangedFader **) var_r31_199);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}

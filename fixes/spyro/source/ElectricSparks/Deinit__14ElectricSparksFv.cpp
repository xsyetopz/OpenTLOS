void ElectricSparks::Deinit() {
    MKMaterial *temp_r3_73;
    u32 temp_r0_90;
    u32 temp_r0_85;
    u32 temp_r0_104;
    u32 var_r31_81;
    u32 *var_r3_82;
    u32 *var_r4_80;

    temp_r3_73 = this->unk50;
    if (temp_r3_73 != NULL) {
        MKMaterial_Destroy(temp_r3_73);
        this->unk50 = NULL;
    }
    var_r4_80 = (u32 *) this->unk4C;
    var_r31_81 = (u32) var_r4_80;
    var_r3_82 = var_r4_80;
    while ((var_r3_82 -= 1, temp_r0_90 = *var_r3_82) != 0U) {
        temp_r0_85 = *var_r3_82;
        if (temp_r0_85 < var_r31_81) {
            var_r31_81 = temp_r0_85;
        }
    }
    if ((u32) var_r3_82 != (u32) &gEmptyPtrListDL) {
        temp_r0_104 = *var_r4_80;
        while (temp_r0_104 != 0U) {
            if (temp_r0_104 < var_r31_81) {
                var_r31_81 = temp_r0_104;
            }
            var_r4_80 += 1;
            temp_r0_104 = *var_r4_80;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r31_81, NULL, 0);
        } else {
            free((void *) var_r31_81);
        }
    }
    this->unk4C = NULL;
    MKModel_Destroy(this->unk54);
    MKModel_Destroy(this->unk58);
    MKProp::Deinit();
}

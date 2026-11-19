void FuryFXElectricity2::Deinit() {
    ManagedLight *temp_r4_1025;
    u32 temp_r0_993;
    void ****var_r31_984;
    void ****var_r3_985;
    void ****var_r4_983;
    void ***temp_r0_1007;
    void ***temp_r0_988;

    var_r4_983 = this->unk124;
    var_r31_984 = var_r4_983;
    var_r3_985 = var_r4_983;
loop_3:
    temp_r0_993 = M2C_FIELD(var_r3_985, u32 *, -4);
    var_r3_985 -= 4;
    if (temp_r0_993 != 0U) {
        temp_r0_988 = *var_r3_985;
        if (temp_r0_988 < var_r31_984) {
            var_r31_984 = (void ****) temp_r0_988;
        }
        goto loop_3;
    }
    if (var_r3_985 != (void ****) &gEmptyPtrListDL) {
loop_9:
        temp_r0_1007 = *var_r4_983;
        if (temp_r0_1007 != NULL) {
            if (temp_r0_1007 < var_r31_984) {
                var_r31_984 = (void ****) temp_r0_1007;
            }
            var_r4_983 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_984, NULL, 0);
        } else {
            free(var_r31_984);
        }
    }
    this->unk124 = NULL;
    temp_r4_1025 = this->unkA8;
    if (temp_r4_1025 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_1025);
    }
    FuryFX::Deinit();
}

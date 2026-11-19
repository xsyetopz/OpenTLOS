void FuryFXEarth2::Deinit() {
    ManagedLight *temp_r4_1261;
    u32 temp_r0_1229;
    u32 temp_r0_1224;
    u32 temp_r0_1243;
    u32 var_r31_1220;
    void *var_r3_1221;
    void *var_r4_1219;

    MKModel_Destroy(this->unkB0);
    MKModel_Destroy(this->unkB4);
    MKModel_Destroy(this->unkB8);
    MKModel_Destroy(this->unkBC);
    var_r4_1219 = this->unkC0;
    var_r31_1220 = (u32) var_r4_1219;
    var_r3_1221 = var_r4_1219;
loop_3:
    temp_r0_1229 = *(u32 *) (((u8 *) var_r3_1221) - 4);
    var_r3_1221 = ((u8 *) var_r3_1221) - 4;
    if (temp_r0_1229 != 0U) {
        temp_r0_1224 = *(u32 *) var_r3_1221;
        if (temp_r0_1224 < var_r31_1220) {
            var_r31_1220 = temp_r0_1224;
        }
        goto loop_3;
    }
    if (var_r3_1221 != (void *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_1243 = *(u32 *) var_r4_1219;
        if (temp_r0_1243 != 0U) {
            if (temp_r0_1243 < var_r31_1220) {
                var_r31_1220 = temp_r0_1243;
            }
            var_r4_1219 = ((u8 *) var_r4_1219) + 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r31_1220, NULL, 0);
        } else {
            free((void *) var_r31_1220);
        }
    }
    this->unkC0 = NULL;
    temp_r4_1261 = this->unkCC;
    if (temp_r4_1261 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1261, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unkCC);
    }
    FuryFX::Deinit();
}

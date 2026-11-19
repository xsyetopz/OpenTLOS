void EarthBreathFX::Deinit() {
    MKMaterial *temp_r3_2284;
    MKVector3 **var_r31_2290;
    MKVector3 **var_r3_2291;
    MKVector3 **var_r4_2289;
    u32 temp_r0_2294;
    u32 temp_r0_2313;
    ManagedLight *temp_r4_2335;
    u32 temp_r0_2299;

    temp_r3_2284 = this->unkB4;
    if (temp_r3_2284 != NULL) {
        MKMaterial_Destroy(temp_r3_2284);
    }
    var_r4_2289 = this->unkC8;
    var_r31_2290 = var_r4_2289;
    var_r3_2291 = var_r4_2289;
loop_5:
    temp_r0_2299 = M2C_FIELD(var_r3_2291, u32 *, -4);
    var_r3_2291 -= 4;
    if (temp_r0_2299 != 0U) {
        temp_r0_2294 = (u32) *var_r3_2291;
        if (temp_r0_2294 < (u32) var_r31_2290) {
            var_r31_2290 = (MKVector3 **) temp_r0_2294;
        }
        goto loop_5;
    }
    if ((void *) var_r3_2291 != (void *) &gEmptyPtrListDL) {
loop_11:
        temp_r0_2313 = (u32) *var_r4_2289;
        if (temp_r0_2313 != 0) {
            if (temp_r0_2313 < (u32) var_r31_2290) {
                var_r31_2290 = (MKVector3 **) temp_r0_2313;
            }
            var_r4_2289 += 4;
            goto loop_11;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_2290, NULL, 0);
        } else {
            free(var_r31_2290);
        }
    }
    this->unkC8 = NULL;
    MKModel_Destroy(this->unk128);
    MKModel_Destroy(this->unk140);
    temp_r4_2335 = this->unkB8;
    if (temp_r4_2335 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_2335);
    }
    BaseBreathFX::Deinit();
}

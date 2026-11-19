extern "C" void free(void *);

void FuryFXConvexity::Deinit() {
    KDSoundFader **var_r31_2359;
    KDSoundFader **var_r3_2360;
    KDSoundFader **var_r4_2358;
    KDSoundFader *temp_r0_2363;
    KDSoundFader *temp_r0_2382;
    ManagedLight *temp_r4_2338;
    u32 temp_r0_2368;

    temp_r4_2338 = this->unkF8;
    if (temp_r4_2338 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_2338, 0U);
        ((LightManager *) gb.unk80)->FreeManagedLight(this->unkF8);
        this->unkF8 = NULL;
    }
    MKModel_Destroy(this->unk1E0);
    KDSound_Stop((int *) &this->unkFC);
    KDSound_Stop((int *) &this->unk124);
    var_r4_2358 = this->unk158;
    var_r31_2359 = var_r4_2358;
    var_r3_2360 = var_r4_2358;
loop_5:
    temp_r0_2368 = M2C_FIELD(var_r3_2360, u32 *, -4);
    var_r3_2360 -= 1;
    if (temp_r0_2368 != 0U) {
        temp_r0_2363 = *var_r3_2360;
        if ((KDSoundFader **) temp_r0_2363 < var_r31_2359) {
            var_r31_2359 = (KDSoundFader **) temp_r0_2363;
        }
        goto loop_5;
    }
    if (var_r3_2360 != (KDSoundFader **) &gEmptyPtrListDL) {
loop_11:
        temp_r0_2382 = *var_r4_2358;
        if (temp_r0_2382 != NULL) {
            if ((KDSoundFader **) temp_r0_2382 < var_r31_2359) {
                var_r31_2359 = (KDSoundFader **) temp_r0_2382;
            }
            var_r4_2358 += 1;
            goto loop_11;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_2359, NULL, 0);
        } else {
            free((void *) var_r31_2359);
        }
    }
    this->unk158 = NULL;
    FuryFX::Deinit();
}

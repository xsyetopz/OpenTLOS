void ZapBreathFX::Deinit() {
    ManagedLight *temp_r4_4528;
    Corona *temp_r4_4552;
    s32 var_r30_4504;
    s32 var_r30_4542;
    s32 var_r30_4560;
    s32 var_r31_4505;
    s32 var_r31_4543;
    s32 var_r31_4561;
    void *temp_r31_4514;
    void *temp_r31_4571;

    var_r30_4504 = 0;
    var_r31_4505 = 0;
    do {
        ((Zap *) ((u8 *) this->unkA8 + var_r31_4505))->Deinit();
        var_r30_4504 += 1;
        var_r31_4505 += 0x1D0;
    } while (var_r30_4504 < 3);
    temp_r31_4514 = this->unkA8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_4514, NULL, 0);
    } else {
        free(temp_r31_4514);
    }
    temp_r4_4528 = this->unkB0;
    if (temp_r4_4528 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_4528, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unkB0);
    }
    ((KDSpline *) &this->unkB4)->Deinit();
    var_r30_4542 = 0;
    var_r31_4543 = 0;
    do {
        ((ElectricBeam *) ((u8 *) this + var_r31_4543 + 0x1C0))->Deinit();
        var_r30_4542 += 1;
        var_r31_4543 += 0x200;
    } while (var_r30_4542 < 4);
    temp_r4_4552 = this->unk9E4;
    if (temp_r4_4552 != NULL) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_4552);
    }
    var_r30_4560 = 0;
    var_r31_4561 = 0;
    do {
        KDSound_Stop((int *) ((u8 *) this->unkAC + var_r31_4561 + 0x64));
        var_r30_4560 += 1;
        var_r31_4561 += 0x90;
    } while (var_r30_4560 < 0xA);
    temp_r31_4571 = this->unkAC;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_4571, NULL, 0);
    } else {
        free(temp_r31_4571);
    }
    MKModel_Destroy(this->unkE0);
    ((BaseBreathFX *) this)->BaseBreathFX::Deinit();
}

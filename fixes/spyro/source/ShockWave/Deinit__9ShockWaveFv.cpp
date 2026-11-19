void ShockWave::Deinit() {
    s32 var_r30_1022;
    s32 var_r31_1023;

    var_r30_1022 = 0;
    var_r31_1023 = 0;
    do {
        MKModel_Destroy(*(MKModel **) ((s8 *) this + (var_r31_1023 + 0xA0)));
        var_r30_1022 += 1;
        var_r31_1023 += 0x28;
    } while (var_r30_1022 < 4);
    MKModel_Destroy(this->unk15C);
    MKShockWave_Disable();
    KDProp::Deinit();
}

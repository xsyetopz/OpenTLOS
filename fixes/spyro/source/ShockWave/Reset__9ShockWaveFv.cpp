void ShockWave::Reset() {
    s32 temp_r0_1002;
    s32 var_ctr_1000;
    s32 var_r3_998;

    KDProp::Reset();
    var_r3_998 = 0;
    this->unk150 = 0;
    var_ctr_1000 = 4;
    do {
        temp_r0_1002 = var_r3_998 + 0x90;
        var_r3_998 += 0x28;
        *((s8 *) this + temp_r0_1002) = 0;
        var_ctr_1000 -= 1;
    } while (var_ctr_1000 != 0);
    MKShockWave_Disable();
}

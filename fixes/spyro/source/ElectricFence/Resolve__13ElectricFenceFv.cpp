f32 ElectricFence::Resolve() {
    s32 var_ctr_514;
    s32 var_r3_511;
    EnergyBeam::Beam *temp_r5_517;

    MKProp::Resolve();
    AllocBeams();
    var_r3_511 = 0;
    var_ctr_514 = 2;
    do {
        temp_r5_517 = M2C_FIELD(this, EnergyBeam::Beam **, var_r3_511 + 0xD0);
        if (temp_r5_517 != NULL) {
            M2C_FIELD(temp_r5_517, s8 *, 0x10) = 0;
        }
        var_r3_511 += 0x18;
        var_ctr_514 -= 1;
    } while (var_ctr_514 != 0);
}

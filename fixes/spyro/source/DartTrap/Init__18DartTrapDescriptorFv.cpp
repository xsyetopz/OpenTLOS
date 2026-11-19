void DartTrapDescriptor::Init() {
    s32 temp_r0_731;
    s32 var_ctr_729;
    s32 var_r3_726;

    KDPropDescriptor::Init();
    var_r3_726 = 0;
    var_ctr_729 = 4;
    do {
        temp_r0_731 = var_r3_726 + 0x70;
        var_r3_726 += 4;
        M2C_FIELD(this, s32 *, temp_r0_731) = 0;
        var_ctr_729 -= 1;
    } while (var_ctr_729 != 0);
}

void ElementalRingDescriptor::Deinit() {
    s32 var_r30_1152;

    var_r30_1152 = 0;
    do {
        MKMaterial_Destroy((MKMaterial *) M2C_FIELD(this, s32 *, var_r30_1152 * 4 + 0x60));
        var_r30_1152 += 1;
    } while (var_r30_1152 < 5);
    MKPropDescriptor::Deinit();
}

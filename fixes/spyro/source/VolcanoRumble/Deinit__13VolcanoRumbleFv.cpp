void VolcanoRumble::Deinit() {
    s32 var_r30_970;
    s32 var_r31_971;

    var_r30_970 = 0;
    var_r31_971 = 0;
    do {
        KDSound_Stop((int *) ((s8 *) this + (var_r31_971 + 0x4C)));
        var_r30_970 += 1;
        var_r31_971 += 0x28;
    } while (var_r30_970 < 4);
    M2C_FIELD(this, s8 *, 0xF0) = 0;
    if ((u32) M2C_FIELD(&gb, u32 *, 0x2B0) == (u32) this) {
        M2C_FIELD(&gb, u32 *, 0x2B0) = 0U;
    }
    MKProp::Deinit();
}

void PuddleSplashDescriptor::Deinit() {
    s32 var_r30_552;
    s32 var_r31_553;

    MKPropDescriptor::Deinit();
    var_r30_552 = 0;
    var_r31_553 = 0;
    do {
        MKMaterial_Destroy((MKMaterial *) M2C_FIELD(this, s32 *, var_r31_553 + 0x60));
        var_r30_552 += 1;
        var_r31_553 += 4;
    } while (var_r30_552 < 4);
}

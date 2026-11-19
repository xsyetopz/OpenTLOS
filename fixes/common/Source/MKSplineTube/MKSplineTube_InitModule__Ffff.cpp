void MKSplineTube_InitModule(float arg0, float arg1, float arg2) {
    f32 temp_f28_38;
    f32 temp_f29_39;
    f32 temp_f30_36;
    f32 temp_f30_53;
    f32 temp_f31_30;
    f32 var_f0_66;
    s32 var_r28_50;
    s32 var_r31_51;

    temp_f31_30 = (f32) log(2.0);
    temp_f30_36 = arg0 * arg0;
    temp_f28_38 = 1.0f / arg1;
    temp_f29_39 = (0.5f * (f32) log(arg2)) / temp_f31_30;
    var_r28_50 = 0;
    var_r31_51 = 0;
    temp_f30_53 = 1.0f / (f32) pow(temp_f30_36, temp_f29_39);
    distScale = 127.0f / temp_f30_36;
    do {
        var_f0_66 = temp_f30_53 * (f32) pow((f32) var_r28_50 / distScale, temp_f29_39);
        if (var_f0_66 > temp_f28_38) {
        } else {
            var_f0_66 = temp_f28_38;
        }
        var_r28_50 += 1;
        *(f32 *) ((u8 *) spacing + var_r31_51) = var_f0_66;
        var_r31_51 += 4;
    } while (var_r28_50 < 0x80);
}

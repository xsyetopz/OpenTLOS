void SpyroLighting::ApplyPointLight(MKVector3 arg0, float arg1, float arg2) {
    MKVector3 pos;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 temp_f4_1139;
    f32 var_f0_1165;
    void **temp_r5_1142;

    temp_f4_1139 = arg1 * arg1;
    temp_r5_1142 = M2C_FIELD(this->unk28, void ***, 8);
    pos = *(MKVector3 *) ((u8 *) temp_r5_1142 + 0x30);
    dx = pos.unk0 - arg0.unk0;
    dy = pos.unk4 - arg0.unk4;
    dz = pos.unk8 - arg0.unk8;
    var_f0_1165 = (dz * dz) + ((dx * dx) + (dy * dy));
    if (var_f0_1165 < temp_f4_1139) {
        if (!(var_f0_1165 > 100.0f)) {
            var_f0_1165 = 100.0f;
        }
        SetLight(arg0, arg2 * ((temp_f4_1139 / var_f0_1165) - 1.0f));
    }
}

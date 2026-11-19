void BoneBlurFX::CalcUVs() {
    Matrix sp20;
    MKVector3 sp10;
    s32 var_r28_170;
    s32 var_r29_153;
    s32 var_r30_171;

    var_r29_153 = this->unk4C - 1;
    if (var_r29_153 < 0) {
        var_r29_153 = this->unk54 - 1;
    }
    M2C_STRUCT_COPY(&sp20, MKView_GetWorldToScreenMatrix(), 0x40);
    var_r28_170 = 0;
    var_r30_171 = 0;
    while (var_r28_170 < (s32) this->unk68) {
        u8 *node = (u8 *) this->unk58[var_r29_153];
        Xform3D2D(&sp10, *(MKVector3 *) (node + var_r30_171), &sp20);
        *(f32 *) (node + var_r30_171 + 0x10) = sp10.unk0;
        *(f32 *) (node + var_r30_171 + 0x14) = sp10.unk4;
        var_r28_170 += 1;
        var_r30_171 += 0x20;
    }
}

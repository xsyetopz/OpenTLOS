void ShockWave::Draw() {
    s32 var_r29_525;
    s32 var_r31_526;
    void *temp_r30_528;
    void *temp_r3_565;
    Matrix arg_sp30;
    Matrix arg_sp20;
    f32 arg_sp24;
    f64 arg_sp10;
    f64 arg_sp18;
    f32 arg_sp60;
    f32 arg_sp64;
    f32 arg_sp68;
    f32 arg_sp6C;

    if ((u8) this->unk160 != 0) {
        var_r29_525 = 0;
        var_r31_526 = 0;
        do {
            temp_r30_528 = (s8 *) this + var_r31_526;
            if ((u8) M2C_FIELD(temp_r30_528, u8 *, 0x90) != 0) {
                M2C_STRUCT_COPY(&arg_sp30, (void *) (MKModel_GetWorldMatrix(this->unk15C) - 4 + 4), 0x40);
                arg_sp30.SetIdentity();
                MKView_GetCameraMatrix();
                arg_sp20.GetRotationPYR();
                arg_sp30.SetRotationYaw(arg_sp24 - 3.1415927f);
                arg_sp30.RotateRoll((Matrix *) &arg_sp30, M2C_FIELD(temp_r30_528, f32 *, 0x98));
                arg_sp30.Scale3x3((Matrix *) &arg_sp30, 0.015f * M2C_FIELD(temp_r30_528, f32 *, 0x9C));
                temp_r3_565 = this->unk8;
                arg_sp10 = M2C_FIELD(temp_r3_565, f64 *, 0x30);
                arg_sp18 = M2C_FIELD(temp_r3_565, f64 *, 0x38);
                arg_sp60 = (f32) arg_sp10;
                arg_sp64 = ((f32 *) &arg_sp10)[1];
                arg_sp68 = (f32) arg_sp18;
                arg_sp6C = 1.0f;
                MKModel_SetAlpha(this->unk15C, 1.0f - (M2C_FIELD(temp_r30_528, f32 *, 0x9C) / M2C_FIELD(temp_r30_528, f32 *, 0x94)));
                MKModel_SetWorldMatrix(this->unk15C, *((Matrix *) &arg_sp30));
                MKModel_Draw(this->unk15C, NULL);
                MKModel_SetAlpha(M2C_FIELD(temp_r30_528, MKModel **, 0xA0), MKModel_GetAlpha(this->unk15C));
                MKModel_Draw(M2C_FIELD(temp_r30_528, MKModel **, 0xA0), NULL);
            }
            var_r29_525 += 1;
            var_r31_526 += 0x28;
        } while (var_r29_525 < 4);
    }
}

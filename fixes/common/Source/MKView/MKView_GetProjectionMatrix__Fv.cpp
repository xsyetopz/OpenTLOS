extern "C" f64 tan(f64);

Matrix *MKView_GetProjectionMatrix() {
    f32 temp_f2_1245;
    f32 temp_f2_1275;
    f32 temp_f31_1248;
    f32 temp_f3_1242;
    f32 temp_f3_1256;
    f32 temp_f3_1270;

    if ((s8) init_254 == 0) {
        lastCounter_253 = 0;
        init_254 = 1;
    }
    if ((s32) lastCounter_253 != (s32) MKView_SettingsCounter) {
        lastCounter_253 = MKView_SettingsCounter;
        projectionMatrix_252.SetZero();
        if ((u8) M2C_FIELD(pStack, u8 *, 0x50) == 0) {
            temp_f3_1242 = pStack[1].unk1C;
            temp_f2_1245 = temp_f3_1242 - pStack[1].unk18;
            temp_f31_1248 = temp_f3_1242 / temp_f2_1245;
            temp_f3_1256 = 1.0f / (f32) tan((f64) (pStack[1].unk14 * 0.5f));
            projectionMatrix_252.unk28 = temp_f31_1248;
            projectionMatrix_252.unk14 = temp_f3_1256;
            projectionMatrix_252.unk0 = temp_f3_1256 / pStack[1].unk20;
            projectionMatrix_252.unk2C = 1.0f;
            projectionMatrix_252.unk38 = -temp_f31_1248 * pStack[1].unk18;
        } else {
            temp_f3_1270 = pStack[1].unk2C;
            projectionMatrix_252.unk0 = 2.0f / temp_f3_1270;
            temp_f2_1275 = pStack[1].unk30;
            projectionMatrix_252.unk14 = -2.0f / temp_f2_1275;
            projectionMatrix_252.unk30 = -(1.0f + ((2.0f * pStack[1].unk24) / temp_f3_1270));
            projectionMatrix_252.unk28 = 1.0f;
            projectionMatrix_252.unk3C = 1.0f;
            projectionMatrix_252.unk34 = 1.0f + ((2.0f * pStack[1].unk28) / temp_f2_1275);
        }
    }
    return &projectionMatrix_252;
}

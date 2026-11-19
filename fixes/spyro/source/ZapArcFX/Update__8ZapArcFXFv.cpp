void *ZapArcFX::Update() {
    MKVector3 sp18;
    s32 temp_r5_793;
    s32 var_r30_760;
    s32 var_r31_761;
    void *temp_r3_768;
    f32 temp_f1_783;

    var_r30_760 = 0;
    var_r31_761 = 0;
    this->unkCC += gUpdateTimeDelta;
    do {
        temp_r3_768 = ((u8 *) this->unkC8) + var_r31_761;
        if ((u8) M2C_FIELD(temp_r3_768, u8 *, 0x48) != 0) {
            M2C_FIELD(temp_r3_768, f32 *, 0x40) = (f32) ((0.35f * gUpdateTimeDelta) + M2C_FIELD(temp_r3_768, f32 *, 0x40));
            temp_f1_783 = M2C_FIELD(temp_r3_768, f32 *, 0x40);
            sp18.unk0 = temp_f1_783;
            sp18.unk4 = temp_f1_783;
            sp18.unk8 = 1.0f;
            ((Matrix *) temp_r3_768)->Scale3x3((Matrix *) temp_r3_768, sp18);
            temp_r5_793 = var_r31_761 + 0x44;
            M2C_FIELD(temp_r3_768, f32 *, 0x44) = M2C_FIELD(temp_r3_768, f32 *, 0x44) + gUpdateTimeDelta;
            if (M2C_FIELD(temp_r3_768, f32 *, 0x44) >= 0.25f) {
                M2C_FIELD(temp_r3_768, f32 *, 0x44) = 0.0f;
                M2C_FIELD(temp_r3_768, u8 *, 0x48) = 0;
            }
        }
        var_r30_760 += 1;
        var_r31_761 += 0x60;
    } while (var_r30_760 < 0x50);
}

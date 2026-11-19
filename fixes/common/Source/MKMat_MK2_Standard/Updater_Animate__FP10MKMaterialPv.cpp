void Updater_Animate(MKMaterial *arg0, void *arg1) {
    f32 temp_f0_152;
    f32 temp_f1_150;
    f32 temp_f1_164;
    f32 temp_f1_171;
    void *temp_r3_145;

    temp_r3_145 = arg0->unk24;
    temp_f1_150 = M2C_FIELD(temp_r3_145, f32 *, 0x130);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) + gUpdateTimeDelta);
    temp_f0_152 = M2C_FIELD(arg1, f32 *, 8);
    if (temp_f0_152 > temp_f1_150) {
        M2C_FIELD(arg1, f32 *, 8) = (f32) (temp_f0_152 - temp_f1_150);
        M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) + M2C_FIELD(temp_r3_145, f32 *, 0x128));
        M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) + M2C_FIELD(temp_r3_145, f32 *, 0x12C));
        temp_f1_164 = M2C_FIELD(arg1, f32 *, 0);
        if (temp_f1_164 < 0.0f) {
            M2C_FIELD(arg1, f32 *, 0) = (f32) (temp_f1_164 + 1.0f);
        }
        temp_f1_171 = M2C_FIELD(arg1, f32 *, 4);
        if (temp_f1_171 < 0.0f) {
            M2C_FIELD(arg1, f32 *, 4) = (f32) (temp_f1_171 + 1.0f);
        }
        if (M2C_FIELD(arg1, f32 *, 0) > 0.99f) {
            M2C_FIELD(arg1, f32 *, 0) = 0.0f;
        }
        if (M2C_FIELD(arg1, f32 *, 4) > 0.99f) {
            M2C_FIELD(arg1, f32 *, 4) = 0.0f;
        }
    }
    ((Matrix *) ((u8 *) arg0->unk24 + 0x40))->SetIdentity();
    M2C_FIELD(arg0->unk24, f32 *, 0x70) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0->unk24, f32 *, 0x74) = (f32) M2C_FIELD(arg1, f32 *, 4);
}

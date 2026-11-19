void SuckeyPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, float arg3) {
    f32 sp28x;
    f32 sp28y;
    f32 sp28z;
    f32 sp8x;
    f32 sp8y;
    f32 sp8z;
    void *temp_r30_220;
    void *temp_r3_215;

    temp_r3_215 = CreateParticle();
    if (temp_r3_215 != NULL) {
        temp_r30_220 = M2C_FIELD(temp_r3_215, void **, 0x2C);
        M2C_FIELD(temp_r3_215, f32 *, 0x10) = 1.0f;
        M2C_FIELD(temp_r3_215, f32 *, 0x14) = 1.0f;
        M2C_FIELD(temp_r3_215, f32 *, 0x18) = 1.0f;
        M2C_FIELD(temp_r3_215, f32 *, 0x1C) = 1.0f;
        M2C_FIELD(temp_r30_220, f32 *, 0x10) = M2C_FIELD(&arg0, f32 *, 0x0);
        M2C_FIELD(temp_r30_220, f32 *, 0x14) = M2C_FIELD(&arg0, f32 *, 0x4);
        M2C_FIELD(temp_r30_220, f32 *, 0x18) = M2C_FIELD(&arg0, f32 *, 0x8);
        M2C_FIELD(temp_r30_220, f32 *, 0x1C) = M2C_FIELD(&arg0, f32 *, 0xC);
        M2C_FIELD(temp_r3_215, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_220, s32 *, 0x28) = 1;
        M2C_FIELD(temp_r30_220, f32 *, 0x0) = M2C_FIELD(&arg1, f32 *, 0x0);
        M2C_FIELD(temp_r30_220, f32 *, 0x4) = M2C_FIELD(&arg1, f32 *, 0x4);
        M2C_FIELD(temp_r30_220, f32 *, 0x8) = M2C_FIELD(&arg1, f32 *, 0x8);
        M2C_FIELD(temp_r30_220, f32 *, 0xC) = M2C_FIELD(&arg1, f32 *, 0xC);
        M2C_FIELD(temp_r30_220, f32 *, 0x2C) = arg2;
        M2C_FIELD(temp_r30_220, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_220, f32 *, 0x24) = arg3;

        /* MKVector3::operator*(D.unk20) on D's velocity, per lane. */
        sp28x = M2C_FIELD(temp_r30_220, f32 *, 0x0) * M2C_FIELD(temp_r30_220, f32 *, 0x20);
        sp28y = M2C_FIELD(temp_r30_220, f32 *, 0x4) * M2C_FIELD(temp_r30_220, f32 *, 0x20);
        sp28z = M2C_FIELD(temp_r30_220, f32 *, 0x8) * M2C_FIELD(temp_r30_220, f32 *, 0x20);

        sp8x = M2C_FIELD(temp_r30_220, f32 *, 0x10) + sp28x;
        sp8y = M2C_FIELD(temp_r30_220, f32 *, 0x14) + sp28y;
        sp8z = M2C_FIELD(temp_r30_220, f32 *, 0x18) + sp28z;
        M2C_FIELD(temp_r3_215, f32 *, 0x0) = sp8x;
        M2C_FIELD(temp_r3_215, f32 *, 0x4) = sp8y;
        M2C_FIELD(temp_r3_215, f32 *, 0x8) = sp8z;
        M2C_FIELD(temp_r3_215, f32 *, 0x24) = 2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r3_215, f32 *, 0x28) = M2C_FIELD(temp_r30_220, f32 *, 0x2C);
    }
}

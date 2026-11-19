void MeleeTrails::Draw() {
    Matrix sp90;
    Matrix sp50;
    MKVector4 sp40;
    u8 *temp_r3_324;
    void **var_r30_316;
    void *temp_r31_427;
    f32 temp_f29_327;
    f32 temp_f1_381;

    var_r30_316 = M2C_FIELD(this, void ***, 0xD4);
    while (var_r30_316 != NULL && (temp_r31_427 = *var_r30_316) != NULL) {
        temp_r3_324 = (u8 *) *M2C_FIELD(temp_r31_427, s32 ***, 0x58);
        temp_f29_327 = M2C_FIELD(temp_r31_427, f32 *, 0x40) / M2C_FIELD(temp_r3_324, f32 *, 8);
        if (temp_r3_324[0xC] != 0) {
            M2C_STRUCT_COPY(&sp90, (const void *) MKModel_GetWorldMatrix(this->unkC8->unk8), 0x40);
        } else {
            M2C_STRUCT_COPY(&sp90, temp_r31_427, 0x40);
        }
        if (((u8 *) temp_r31_427)[0x5C] != 0) {
            sp90.Scale3x3(&sp90, ((1.0f - temp_f29_327) * M2C_FIELD(temp_r31_427, f32 *, 0x50)) + 1.0f);
        }
        MKModel_SetWorldMatrix(this->unk4, sp90);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, **M2C_FIELD(temp_r31_427, s32 ***, 0x58), 1U, 1U);
        temp_f1_381 = temp_f29_327 * M2C_FIELD(temp_r31_427, f32 *, 0x4C);
        sp40.unk0 = temp_f1_381;
        sp40.unk4 = temp_f1_381;
        sp40.unk8 = temp_f1_381;
        sp40.unkC = 1.0f;
        MKModel_SetColor(this->unk4, sp40);
        M2C_STRUCT_COPY(&sp50, &Matrix::identity, 0x40);
        sp50.unk30 = M2C_FIELD(temp_r31_427, f32 *, 0x44);
        sp50.unk34 = M2C_FIELD(temp_r31_427, f32 *, 0x48);
        sp50.unk38 = 0.0f;
        sp50.unk3C = 1.0f;
        MKMaterial_SetTextureMatrix(this->unkCC, &sp50);
        MKModel_Draw(this->unk4, NULL);
        var_r30_316 += 1;
    }
}

void Updater_SinScroll(MKMaterial *arg0, void *arg1) {
    f32 temp_f29_416;
    f32 temp_f30_415;
    f32 temp_f31_414;
    void *temp_r3_408;

    temp_r3_408 = arg0->unk24;
    temp_f31_414 = M2C_FIELD(temp_r3_408, f32 *, 0x160);
    temp_f30_415 = M2C_FIELD(temp_r3_408, f32 *, 0x164);
    temp_f29_416 = M2C_FIELD(temp_r3_408, f32 *, 0x16C);
    M2C_FIELD(arg1, f32 *, 0) = (f32) ((M2C_FIELD(temp_r3_408, f32 *, 0x168) * (2.0f * (3.1415927f * gUpdateTimeDelta))) + M2C_FIELD(arg1, f32 *, 0));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 0));
    M2C_FIELD(arg1, f32 *, 4) = (f32) ((temp_f29_416 * (2.0f * (3.1415927f * gUpdateTimeDelta))) + M2C_FIELD(arg1, f32 *, 4));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 4));
    ((Matrix *) ((u8 *) arg0->unk24 + 0x40))->SetIdentity();
    M2C_FIELD(arg0->unk24, f32 *, 0x70) = (f32) (temp_f31_414 * _table_sinf(M2C_FIELD(arg1, f32 *, 0)));
    M2C_FIELD(arg0->unk24, f32 *, 0x74) = (f32) (temp_f30_415 * _table_sinf(M2C_FIELD(arg1, f32 *, 4)));
}

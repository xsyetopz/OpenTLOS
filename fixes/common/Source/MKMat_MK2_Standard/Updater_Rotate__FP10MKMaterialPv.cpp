void Updater_Rotate(MKMaterial *arg0, void *arg1) {
    Matrix sp90;
    Matrix sp50;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f30_328;
    f32 temp_f31_326;
    void *temp_r3_323;

    temp_r3_323 = arg0->unk24;
    temp_f31_326 = M2C_FIELD(temp_r3_323, f32 *, 0x134);
    temp_f30_328 = M2C_FIELD(temp_r3_323, f32 *, 0x138);
    M2C_FIELD(arg1, f32 *, 4) = (f32) ((gUpdateTimeDelta * M2C_FIELD(arg1, f32 *, 0)) + M2C_FIELD(arg1, f32 *, 4));
    NormaliseAngle(M2C_FIELD(arg1, f32 *, 4));
    sp20 = temp_f31_326;
    sp24 = temp_f30_328;
    sp28 = 0.0f;
    sp90.SetRotationToNone();
    sp10 = -sp20;
    sp14 = -sp24;
    sp18 = -sp28;
    sp90.unk30 = sp10;
    sp90.unk34 = sp14;
    sp90.unk38 = sp18;
    sp90.unk3C = 1.0f;
    sp50.SetRotationRoll(M2C_FIELD(arg1, f32 *, 4));
    sp50.unk30 = sp20;
    sp50.unk34 = sp24;
    sp50.unk38 = sp28;
    sp50.unk3C = 1.0f;
    ((Matrix *) ((u8 *) arg0->unk24 + 0x40))->Multiply(&sp90, &sp50);
}

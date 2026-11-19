void MagicDrain::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_393;

    KDPropEx::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.0f;
    spC = 1.0f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk15C = (ManagedLight *) ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_652, lit_653);
    temp_r4_393 = this->unk15C;
    if (temp_r4_393 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_393, 0U);
    }
}

void EnemyDeathFX::Resolve() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r4_507;

    MKProp::Resolve();
    sp20 = 0.0f;
    sp8 = 1.0f;
    spC = 0.75f;
    sp10 = 0.75f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unk64 = (Corona *) ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp38), *((MKVector4 *) &sp28), 10.0f, lit_634, lit_635);
    temp_r4_507 = this->unk64;
    if (temp_r4_507 != NULL) {
        temp_r4_507->unk31 &= ~0x40;
    }
}

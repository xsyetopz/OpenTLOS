f32 GunPowderFuse::Resolve() {
    MKVector3 pos;
    MKVector4 col;
    f32 radius;
    Corona *temp;
    u8 *p;
    s32 i;

    MKProp::Resolve();
    this->unk2A4 = (MKMaterial *) (MKMaterial_Create("FX_GunPowderFuse"));
    this->unk2A8 /= this->unkB0->unk30.unk8;
    this->unk2AC = 2.0f * (this->unkB4 / this->unkB0->unk30.unk8);
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        pos.unk0 = 0.0f;
        pos.unk4 = 0.0f;
        pos.unk8 = 0.0f;
        col.unk0 = 1.0f;
        col.unk4 = 1.0f;
        col.unk8 = 1.0f;
        col.unkC = 1.0f;
        radius = this->unkB4 / 20.0f;
        M2C_FIELD(p, Corona **, 0xC4) = (Corona *) ((Coronas *) gb.unk64)->Alloc(pos, col, radius, lit_743, lit_744);
        temp = M2C_FIELD(p, Corona **, 0xC4);
        if (temp != NULL) {
            M2C_FIELD(temp, u8 *, 0x31) = (u8) (M2C_FIELD(temp, u8 *, 0x31) & ~0x40);
        }
    }
    this->unk2B0 = -((this->unk2A8 * this->unk2B0) - 1.0f);
}

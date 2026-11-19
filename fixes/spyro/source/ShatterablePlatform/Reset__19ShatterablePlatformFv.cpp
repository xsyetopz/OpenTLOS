void ShatterablePlatform::Reset() {
    Matrix sp20;
    f64 sp18;
    f64 sp10;

    Shatterable::Reset();
    this->unk1C0.Reset();
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) this->unk208;
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) this->unk210;
    sp10 = M2C_FIELD(this, f64 *, 0x1C8);
    sp18 = M2C_FIELD(this, f64 *, 0x1D0);
    M2C_STRUCT_COPY(&sp20, MKModel_GetWorldMatrix(this->unk4), 0x40);
    sp20.SetRotationPYR(*((MKVector3 *) &sp10));
    MKModel_SetWorldMatrix(this->unk4, sp20);
}

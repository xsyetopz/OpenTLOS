void AITargetData::Set(const MKVector3 &arg0, bool arg1) {
    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk40.Set((Targetable *) NULL);
    M2C_FIELD(this, s8 *, 0x48) = 2;
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) | 0x80);
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~4) | ((arg1 << 2) & 4));
}

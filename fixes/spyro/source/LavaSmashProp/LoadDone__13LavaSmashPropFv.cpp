s32 LavaSmashProp::LoadDone() {
    Shatterable::LoadDone();
    M2C_FIELD(this, f64 *, 0x1E8) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x40);
    M2C_FIELD(this, f64 *, 0x1F0) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x48);
    this->unk1D8 = M2C_FIELD(this, f64 *, 0x1E8);
    M2C_FIELD(this, f64 *, 0x1E0) = (f64) M2C_FIELD(this, f64 *, 0x1F0);
    M2C_FIELD(this, f64 *, 0x108) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x70);
    M2C_FIELD(this, f64 *, 0x110) = (f64) M2C_FIELD(&MKProp::loadInfo, f64 *, 0x78);
    this->unk204 = 1.0f - M2C_FIELD(this, f32 *, 0x108);
}

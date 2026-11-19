s32 ShatterablePlatform::LoadDone() {
    Shatterable::LoadDone();
    this->unk208 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    this->unk210 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    this->unk1C0.Init(&this->unk1A8, (MKCollisionInfo *) (((u8 *) this->unk168) + ((this->unk180 << 7) + 0x68)));
    this->unk1C0.LoadDone((MKProp *) this, (MKVector3 *) ((s8 *) &MKProp::loadInfo + 0x60));
    M2C_FIELD(this, f64 *, 0x1C8) = (f64) this->unk208;
    M2C_FIELD(this, f64 *, 0x1D0) = (f64) this->unk210;
}

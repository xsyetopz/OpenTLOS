s32 Platform::LoadDone() {
    M2C_FIELD(&MKProp::loadInfo, f64 *, 0x60) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 0);
    M2C_FIELD(&MKProp::loadInfo, f64 *, 0x68) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 8);
    GameProp::LoadDone();
    this->unkC8 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x50);
    this->unkD0 = M2C_FIELD(&MKProp::loadInfo, f64 *, 0x58);
    this->unk108.LoadDone((MKProp *) this, (MKVector3 *) ((s8 *) &MKProp::loadInfo + 0x60));
    M2C_FIELD(this, f64 *, 0x110) = (f64) this->unkC8;
    M2C_FIELD(this, f64 *, 0x118) = (f64) this->unkD0;
}

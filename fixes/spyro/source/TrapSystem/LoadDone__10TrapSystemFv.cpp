s32 TrapSystem::LoadDone() {
    MKProp::LoadDone();
    this->unk50.SetIdentity();
    this->unk50.SetRotationPYR(*((MKVector3 *) ((u8 *) &MKProp::loadInfo + 0x50)));
    this->unk50.unk30 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unk50.unk34 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x44);
    this->unk50.unk38 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x48);
    this->unk50.unk3C = 1.0f;
    this->unk8 = &this->unk50;
}

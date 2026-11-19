void LavaSmashPropDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    M2C_FIELD(this, f32 *, 0x16C) *= 100.0f;
    this->unk170 *= 100.0f;
    this->unk174 *= 100.0f;
    this->unk178 *= 100.0f;
}

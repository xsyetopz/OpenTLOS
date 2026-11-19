void LavaSmashPropDescriptor::Init() {
    ShatterableDescriptor::Init();
    M2C_FIELD(this, f32 *, 0x16C) = 0.0f;
    this->unk170 = 0.0f;
    this->unk174 = 0.0f;
    this->unk178 = 0.02f;
    this->unk180 = 0.25f;
    this->unk184 = 0.25f;
    this->unk17C = GS_PLACEHOLDER;
}

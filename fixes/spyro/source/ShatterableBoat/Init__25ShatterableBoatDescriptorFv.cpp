void ShatterableBoatDescriptor::Init() {
    ShatterableDescriptor::Init();
    M2C_FIELD(this, s32 *, 0x16C) = GS_PLACEHOLDER;
    this->unk170 = GS_PLACEHOLDER;
}

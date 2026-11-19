void DropBoxDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk174 = 0;
    M2C_FIELD(this, Explosion4 **, 0x16C) = 0;
}

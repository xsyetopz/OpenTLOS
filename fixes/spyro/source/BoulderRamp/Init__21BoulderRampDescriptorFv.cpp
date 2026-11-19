void BoulderRampDescriptor::Init() {
    TrapDescriptor::Init();
    M2C_FIELD(this, s32 *, 0xE4) = GS_PLACEHOLDER;
    this->unkE8 = GS_PLACEHOLDER;
    this->unkEC = GS_PLACEHOLDER;
}

void MineCartDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s32 *, 0xE4) = 0;
    this->unkE8 = 0.25f;
    this->unkEC = 0.25f;
}

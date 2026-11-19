void PlatformDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, f32 *, 0xE4) = 0.5f;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 6.0f;
    this->unkF4 = 0;
    this->unkF5 = 1;
    this->unkFC = 1000.0f;
    this->unk100 = GS_PLACEHOLDER;
    this->unk104 = 0;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    this->unk114 = 0.0f;
    this->unk118 = 0;
    this->unk11C = 50.0f;
    this->unk120 = 0.3f;
}

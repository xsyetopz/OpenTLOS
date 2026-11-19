void Platform::Init() {
    PlatformDescriptor *desc;

    GameProp::Init();
    this->unk150.Init();
    desc = checked_cast<PlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk108.Init((PlatformObjectDesc *) ((s8 *) desc + 0xE4), (MKCollisionInfo *) ((s8 *) this + 0x70));
    M2C_FIELD(this, f32 *, 0xE8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xEC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xFC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x100) = 0.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 0.0f;
    this->unkE0 = 0.0f;
    this->unk174 = 0;
    this->unk16C = 1.0f;
    this->unk170 = 1.0f;
    this->unk178 = 0;
    this->unk175 = 1;
    M2C_FIELD(this, Platform **, 0x15C) = this;
}

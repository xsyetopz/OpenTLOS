void WaterTrickleEmitter::Init() {
    MKProp::Init();
    this->unk94 = 0;
    M2C_FIELD(&this->unk4C, f32 *, 0x30) = 0.0f;
    this->unk4C.unk34 = 0.0f;
    this->unk88 = 0.0f;
    this->unk84 = 0;
    this->unk8 = &this->unkA0;
    this->unkA0.SetIdentity();
    this->unk8C = 0.0f;
    this->unk90 = 200.0f;
    this->unkE0 = 0.0f;
}

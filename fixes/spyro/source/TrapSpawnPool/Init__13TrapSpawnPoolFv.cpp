void TrapSpawnPool::Init() {
    MKProp::Init();
    this->unk90 = 0;
    this->unk94 = 0.0f;
    this->unk98 = 0.0f;
    this->unkB4.Init();
    this->unk50.SetIdentity();
    this->unkFC = 0.0f;
    this->unk100 = 0.0f;
    this->unkF8 = 0.0f;
    this->unk104 = 1.0f;
    this->unk10C = 0.0f;
    this->unk108 = 0.0f;
    this->unk110 = 0;
    this->unkB4.unk34 = 0.0f;
    this->unkEC = 0.0f;
    this->unkF0 = 0.0f;
    PropFlagsInit((unsigned int *) &this->unk10, 0x160000U);
    this->unk8 = &this->unk50;
    this->unk114 = 0xA;
    this->unk118 = 600.0f;
    this->unk11C = 0.0f;
}

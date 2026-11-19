void FallingDustPropDescriptor::Init() {
    KDPropDescriptor::Init();
    this->unk70 = (s32) checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("DustPuffPS"));
}

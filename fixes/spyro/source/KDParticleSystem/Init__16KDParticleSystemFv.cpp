void KDParticleSystem::Init() {
    void (KDParticleSystem::*pfn)(KDParticleSystem *, MKParticle *);

    MKBaseParticleSystem::Init();
    this->unkF4 = 0.0f;
    this->unkA8 = M2C_FIELD(this->unk0, f32 *, 0x94);
    this->unkAC = M2C_FIELD(this->unk0, f32 *, 0x98);
    pfn = &KDParticleSystem::KDConfigureSystemData;
    M2C_FIELD(this, void **, 0xF0) = *(void **) &pfn;
    this->unkF8 = 0;
}

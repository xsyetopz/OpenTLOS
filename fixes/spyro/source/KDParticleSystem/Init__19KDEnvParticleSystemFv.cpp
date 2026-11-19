void KDEnvParticleSystem::Init() {
    void (KDEnvParticleSystem::*pfn)(KDParticleSystem *, MKParticle *);

    KDParticleSystem::Init();
    pfn = &KDEnvParticleSystem::KDEnvConfigureSystemData;
    M2C_FIELD(this, void **, 0xF0) = *(void **) &pfn;
}

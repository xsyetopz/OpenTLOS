void KDEnvParticleSystem::KDEnvConfigureSystemData(KDParticleSystem *arg0, MKParticle *arg1) {
    void *env;

    env = M2C_FIELD(this->unk0, void **, 0xD4);
    M2C_FIELD(arg0, f32 *, 0x20) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x28) = M2C_FIELD(env, f32 *, 8);
    M2C_FIELD(arg0, f32 *, 0x10) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x14) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = M2C_FIELD(env, f32 *, 4);
}

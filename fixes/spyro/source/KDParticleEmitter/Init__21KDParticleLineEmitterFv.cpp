extern "C" void InitLineParticlePostion__21KDParticleLineEmitterFP17KDParticleEmitterP10MKParticle(KDParticleEmitter *, MKParticle *);

void KDParticleLineEmitter::Init() {
    KDParticleEmitter::Init();
    this->unk78 = 0;
    M2C_FIELD(this, void **, 0x44) = (void *) InitLineParticlePostion__21KDParticleLineEmitterFP17KDParticleEmitterP10MKParticle;
}

extern "C" void InitBoxParticlePostion__20KDParticleBoxEmitterFP17KDParticleEmitterP10MKParticle(KDParticleEmitter *, MKParticle *);

void KDParticleBoxEmitter::Init() {
    KDParticleEmitter::Init();
    M2C_FIELD(this, void **, 0x44) = (void *) InitBoxParticlePostion__20KDParticleBoxEmitterFP17KDParticleEmitterP10MKParticle;
}

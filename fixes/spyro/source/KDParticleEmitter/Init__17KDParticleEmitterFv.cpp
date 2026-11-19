extern "C" void InitPointParticlePosition__17KDParticleEmitterFP17KDParticleEmitterP10MKParticle(KDParticleEmitter *, MKParticle *);
extern "C" void InitPointParticleParameters__17KDParticleEmitterFP17KDParticleEmitterP10MKParticle(KDParticleEmitter *, MKParticle *);

void KDParticleEmitter::Init() {
    this->unk28 = NULL;
    this->unk40 = 1;
    M2C_FIELD(this, f32 *, 0x2C) = 0.0f;
    this->unk30 = 0.0f;
    this->unk38 = 0.0f;
    this->unk3C = 1.0f;
    this->unk4C = 0.0f;
    this->unk50 = 0.0f;
    this->unk54 = 3.1415927f;
    this->unk58 = -3.1415927f;
    this->unk5C = 0.0f;
    this->unk60 = 0.0f;
    this->unk64 = 1.0f;
    this->unk68 = 1.0f;
    *(MKVector3 *) &this->unk18 = MKVector3::zero;
    this->unk34 = 0.0f;
    this->unk70 = &Matrix::identity;
    this->unk6C = (f64 *) &MKVector3::zero;
    M2C_FIELD(this, f32 *, 8) = 1.0f;
    M2C_FIELD(this, f32 *, 0xC) = 1.0f;
    this->unk10 = 1.0f;
    this->unk14 = 1.0f;
    M2C_FIELD(this, void **, 0x44) = (void *) InitPointParticlePosition__17KDParticleEmitterFP17KDParticleEmitterP10MKParticle;
    M2C_FIELD(this, void **, 0x48) = (void *) InitPointParticleParameters__17KDParticleEmitterFP17KDParticleEmitterP10MKParticle;
}

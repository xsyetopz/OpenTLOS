void KDParticleEmitter::Burst() {
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    Emit((s32) M2C_FIELD(this, f32 *, 0x2C), (MKVector3 *) &sp8);
}

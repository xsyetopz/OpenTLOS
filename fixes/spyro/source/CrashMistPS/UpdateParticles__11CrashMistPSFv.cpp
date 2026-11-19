void CrashMistPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r3_57;

    MKParticleSystem::UpdateParticles();
    var_r3_57 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r3_57 != NULL) {
        var_r3_57 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

void EmbersPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r3;
    void *temp_r5;

    var_r3 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r3 != NULL) {
        temp_r5 = var_r3->unk2C;
        M2C_FIELD(temp_r5, f32 *, 4) = (f32) ((M2C_FIELD(temp_r5, f32 *, 0x24) * gUpdateTimeDelta) + M2C_FIELD(temp_r5, f32 *, 4));
        var_r3 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
    MKParticleSystem::UpdateParticles();
}

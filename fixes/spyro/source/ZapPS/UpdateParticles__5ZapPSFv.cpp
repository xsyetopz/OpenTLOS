void ZapPS::UpdateParticles() {
    void *sp8[2];
    MKParticleChunk *var_r31_64;
    void *temp_r30_67;
    MKParticleSystem::Envelope *temp_r3_108;
    MKParticleSystem::Envelope *temp_r5_113;
    MKParticleSystem::Envelope *temp_r5_146;
    f32 temp_f30_71;
    f32 temp_f3_122;
    f32 temp_f5_115;
    f32 temp_f6_110;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 var_f0_126;
    s32 temp_r4_107;
    s32 temp_r0_109;

    this->unk128 += gUpdateTimeDelta;
    var_r31_64 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r31_64 != NULL) {
        temp_r30_67 = var_r31_64->unk2C;
        temp_f30_71 = this->unk128 - M2C_FIELD(temp_r30_67, f32 *, 0x10);
        if (temp_f30_71 > this->unk12C) {
            var_r31_64 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        } else {
            tx = M2C_FIELD(temp_r30_67, f32 *, 0) * gUpdateTimeDelta;
            ty = M2C_FIELD(temp_r30_67, f32 *, 4) * gUpdateTimeDelta;
            tz = M2C_FIELD(temp_r30_67, f32 *, 8) * gUpdateTimeDelta;
            M2C_FIELD(var_r31_64, f32 *, 0) = M2C_FIELD(var_r31_64, f32 *, 0) + tx;
            M2C_FIELD(var_r31_64, f32 *, 4) = M2C_FIELD(var_r31_64, f32 *, 4) + ty;
            var_r31_64->unk8 += tz;
            var_r31_64->unk24 = 2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
            temp_r4_107 = M2C_FIELD(temp_r30_67, s32 *, 0x14);
            temp_r3_108 = this->unk134;
            temp_r0_109 = temp_r4_107 - 1;
            temp_f6_110 = this->unk12C;
            temp_r5_113 = &temp_r3_108[temp_r0_109];
            temp_f5_115 = temp_r5_113->unk0;
            temp_f3_122 = -((temp_f6_110 * temp_f5_115) - temp_f30_71) / (temp_f6_110 * (temp_r3_108[temp_r4_107].unk0 - temp_f5_115));
            var_r31_64->unk1C = M2C_FIELD(temp_r30_67, f32 *, 0x20) * ((temp_f3_122 * temp_r5_113->unkC) + temp_r5_113->unk4);
            var_f0_126 = var_r31_64->unk1C;
            if (var_f0_126 < 1.0f) {

            } else {
                var_f0_126 = 1.0f;
            }
            if (var_f0_126 > 0.0f) {

            } else {
                var_f0_126 = 0.0f;
            }
            var_r31_64->unk1C = var_f0_126;
            temp_r5_146 = &this->unk134[temp_r0_109];
            var_r31_64->unk28 = M2C_FIELD(temp_r30_67, f32 *, 0x1C) * ((temp_f3_122 * temp_r5_146->unk10) + temp_r5_146->unk8);
            var_r31_64 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        }
    }
}

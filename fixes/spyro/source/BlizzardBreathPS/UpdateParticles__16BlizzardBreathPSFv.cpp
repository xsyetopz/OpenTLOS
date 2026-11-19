void BlizzardBreathPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r7;
    void *temp_r8;
    MKParticleSystem::Envelope *temp_r5;
    MKParticleSystem::Envelope *temp_r5_alt;
    f32 temp_f3;
    f32 temp_f3_134;
    f32 temp_f0;
    f32 sp18;
    s32 temp_r3;
    s32 temp_r4;
    s32 idx;

    this->unk128 += gUpdateTimeDelta;
    var_r7 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r7 != NULL) {
        temp_r8 = var_r7->unk2C;
        temp_f3 = this->unk128 - M2C_FIELD(temp_r8, f32 *, 0x10);
        if (temp_f3 > this->unk12C) {
            var_r7 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }
        M2C_FIELD(temp_r8, f32 *, 4) = (f32) -((3000.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r8, f32 *, 4));
        M2C_FIELD(var_r7, f32 *, 0) += M2C_FIELD(temp_r8, f32 *, 0) * gUpdateTimeDelta;
        M2C_FIELD(var_r7, f32 *, 4) += M2C_FIELD(temp_r8, f32 *, 4) * gUpdateTimeDelta;
        sp18 = M2C_FIELD(temp_r8, f32 *, 8) * gUpdateTimeDelta;
        var_r7->unk8 += sp18;
        var_r7->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r8, f32 *, 0x18);
        temp_r3 = M2C_FIELD(temp_r8, s32 *, 0x14);
        if (temp_f3 > (this->unk12C * this->unk134[temp_r3].unk0)) {
            M2C_FIELD(temp_r8, s32 *, 0x14) = temp_r3 + 1;
        }
        temp_r4 = M2C_FIELD(temp_r8, s32 *, 0x14);
        idx = temp_r4 - 1;
        temp_r5 = &this->unk134[idx];
        temp_f3_134 = -((this->unk12C * temp_r5->unk0) - temp_f3) / (this->unk12C * (this->unk134[temp_r4].unk0 - temp_r5->unk0));
        var_r7->unk1C = M2C_FIELD(temp_r8, f32 *, 0x20) * ((temp_f3_134 * temp_r5->unkC) + temp_r5->unk4);
        temp_f0 = var_r7->unk1C;
        if (temp_f0 < 1.0f) {
        } else {
            temp_f0 = 1.0f;
        }
        if (temp_f0 > 0.0f) {
        } else {
            temp_f0 = 0.0f;
        }
        var_r7->unk1C = temp_f0;
        temp_r5_alt = &this->unk134[idx];
        var_r7->unk28 = M2C_FIELD(temp_r8, f32 *, 0x1C) * ((temp_f3_134 * temp_r5_alt->unk10) + temp_r5_alt->unk8);
        var_r7 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

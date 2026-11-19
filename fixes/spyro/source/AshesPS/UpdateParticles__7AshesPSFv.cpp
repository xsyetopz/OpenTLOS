void AshesPS::UpdateParticles() {
    u8 sp8[0x8];
    MKParticleChunk *var_r30;
    void *temp_r29;
    MKParticleSystem::Envelope *temp_r5;
    MKParticleSystem::Envelope *temp_r5_alt;
    f32 temp_f30;
    f32 temp_f3;
    f32 temp_f3_152;
    f32 temp_f0;
    f32 sp18;
    s32 temp_r3;
    s32 temp_r3_126;
    s32 idx;
    s32 temp_r4;
    AshesPSDescriptor *desc;

    this->unk128 += gUpdateTimeDelta;
    var_r30 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r30 != NULL) {
        temp_r29 = var_r30->unk2C;
        temp_f30 = this->unk128 - M2C_FIELD(temp_r29, f32 *, 0x10);
        if (temp_f30 > this->unk12C) {
            var_r30 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
            continue;
        }
        M2C_FIELD(temp_r29, f32 *, 4) = (f32) -((1000.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r29, f32 *, 4));
        M2C_FIELD(var_r30, f32 *, 0) += M2C_FIELD(temp_r29, f32 *, 0) * gUpdateTimeDelta;
        M2C_FIELD(var_r30, f32 *, 4) += M2C_FIELD(temp_r29, f32 *, 4) * gUpdateTimeDelta;
        sp18 = M2C_FIELD(temp_r29, f32 *, 8) * gUpdateTimeDelta;
        var_r30->unk8 += sp18;
        var_r30->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29, f32 *, 0x18);
        desc = checked_cast<AshesPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r3 = M2C_FIELD(desc, s32 *, 0x80);
        temp_f3 = var_r30->unk20;
        var_r30->unk20 = (f32) fmod(temp_r3, temp_f3 + this->unkF0, (f32) temp_r3, temp_f3);
        temp_r3_126 = M2C_FIELD(temp_r29, s32 *, 0x14);
        if (temp_f30 > (this->unk12C * this->unk134[temp_r3_126].unk0)) {
            M2C_FIELD(temp_r29, s32 *, 0x14) = temp_r3_126 + 1;
        }
        temp_r4 = M2C_FIELD(temp_r29, s32 *, 0x14);
        idx = temp_r4 - 1;
        temp_r5 = &this->unk134[idx];
        temp_f3_152 = -((this->unk12C * temp_r5->unk0) - temp_f30) / (this->unk12C * (this->unk134[temp_r4].unk0 - temp_r5->unk0));
        var_r30->unk1C = M2C_FIELD(temp_r29, f32 *, 0x20) * ((temp_f3_152 * temp_r5->unkC) + temp_r5->unk4);
        temp_f0 = var_r30->unk1C;
        if (temp_f0 < 1.0f) {
        } else {
            temp_f0 = 1.0f;
        }
        if (temp_f0 > 0.0f) {
        } else {
            temp_f0 = 0.0f;
        }
        var_r30->unk1C = temp_f0;
        temp_r5_alt = &this->unk134[idx];
        var_r30->unk28 = M2C_FIELD(temp_r29, f32 *, 0x1C) * ((temp_f3_152 * temp_r5_alt->unk10) + temp_r5_alt->unk8);
        var_r30 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    }
}

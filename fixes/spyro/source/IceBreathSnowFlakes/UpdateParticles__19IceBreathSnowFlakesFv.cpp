void IceBreathSnowFlakes::UpdateParticles() {
    u8 sp8[0x8];
    f32 sp60;
    f32 sp64;
    f32 sp68;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    MKBaseParticleSystemDescriptor *desc;
    MKParticleChunk *var_r30_109;
    MKParticleSystem::Envelope *temp_r3_199;
    MKParticleSystem::Envelope *temp_r5_204;
    MKParticleSystem::Envelope *temp_r5_237;
    f32 temp_f29_116;
    f32 temp_f3_177;
    f32 temp_f3_213;
    f32 temp_f5_206;
    f32 temp_f6_201;
    f32 var_f0_217;
    s32 temp_r0_200;
    s32 temp_r3_173;
    s32 temp_r3_187;
    s32 temp_r4_198;
    void *temp_r29_112;

    this->unk128 += gUpdateTimeDelta;
    var_r30_109 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
loop_12:
    if (var_r30_109 != NULL) {
        temp_r29_112 = var_r30_109->unk2C;
        temp_f29_116 = this->unk128 - M2C_FIELD(temp_r29_112, f32 *, 0x10);
        if (temp_f29_116 > this->unk12C) {
            var_r30_109 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        } else {
            /* Position and velocity advance per lane in f32, as the paired-single asm does. */
            sp60 = M2C_FIELD(temp_r29_112, f32 *, 0) * gUpdateTimeDelta;
            sp64 = M2C_FIELD(temp_r29_112, f32 *, 4) * gUpdateTimeDelta;
            M2C_FIELD(var_r30_109, f32 *, 0) += sp60;
            M2C_FIELD(var_r30_109, f32 *, 4) += sp64;
            sp68 = M2C_FIELD(temp_r29_112, f32 *, 8) * gUpdateTimeDelta;
            var_r30_109->unk8 += sp68;
            sp10 = this->unk108 * gUpdateTimeDelta;
            sp14 = this->unk10C * gUpdateTimeDelta;
            M2C_FIELD(temp_r29_112, f32 *, 0) += sp10;
            M2C_FIELD(temp_r29_112, f32 *, 4) += sp14;
            sp18 = this->unk110 * gUpdateTimeDelta;
            M2C_FIELD(temp_r29_112, f32 *, 8) += sp18;
            var_r30_109->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r29_112, f32 *, 0x18);
            desc = checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r3_173 = M2C_FIELD(desc, s32 *, 0x80);
            temp_f3_177 = var_r30_109->unk20;
            var_r30_109->unk20 = (f32) fmod(temp_r3_173, temp_f3_177 + this->unkF0, (f32) temp_r3_173, temp_f3_177);
            temp_r3_187 = M2C_FIELD(temp_r29_112, s32 *, 0x14);
            if (temp_f29_116 > (this->unk12C * this->unk134[temp_r3_187].unk0)) {
                M2C_FIELD(temp_r29_112, s32 *, 0x14) = (s32) (temp_r3_187 + 1);
            }
            temp_r4_198 = M2C_FIELD(temp_r29_112, s32 *, 0x14);
            temp_r3_199 = this->unk134;
            temp_r0_200 = temp_r4_198 - 1;
            temp_f6_201 = this->unk12C;
            temp_r5_204 = &temp_r3_199[temp_r0_200];
            temp_f5_206 = temp_r5_204->unk0;
            temp_f3_213 = -((temp_f6_201 * temp_f5_206) - temp_f29_116) / (temp_f6_201 * (temp_r3_199[temp_r4_198].unk0 - temp_f5_206));
            var_r30_109->unk1C = M2C_FIELD(temp_r29_112, f32 *, 0x20) * ((temp_f3_213 * temp_r5_204->unkC) + temp_r5_204->unk4);
            var_f0_217 = var_r30_109->unk1C;
            if (var_f0_217 < 1.0f) {

            } else {
                var_f0_217 = 1.0f;
            }
            if (var_f0_217 > 0.0f) {

            } else {
                var_f0_217 = 0.0f;
            }
            var_r30_109->unk1C = var_f0_217;
            temp_r5_237 = &this->unk134[temp_r0_200];
            var_r30_109->unk28 = M2C_FIELD(temp_r29_112, f32 *, 0x1C) * ((temp_f3_213 * temp_r5_237->unk10) + temp_r5_237->unk8);
            var_r30_109 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        }
        goto loop_12;
    }
}

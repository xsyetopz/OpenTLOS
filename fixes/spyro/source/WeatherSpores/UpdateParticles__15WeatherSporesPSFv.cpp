void WeatherSporesPS::UpdateParticles() {
    f64 fmod(f64, f64);
    MKBaseParticleSystemDescriptor *desc;
    MKVector3 sp40;
    MKVector3 sp50;
    void *sp8[2];
    MKParticleChunk *var_r31_74;
    void *temp_r30_77;
    MKParticleSystem::Envelope *temp_r3_211;
    MKParticleSystem::Envelope *temp_r5_215;
    MKParticleSystem::Envelope *temp_r5_247;
    f32 temp_f25_140;
    f32 temp_f26_143;
    f32 temp_f27_147;
    f32 temp_f28_81;
    f32 temp_f3_224;
    f32 temp_f4_217;
    f32 temp_f5_213;
    f32 scale;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 var_f0_227;
    s32 count;
    s32 temp_r0_212;
    s32 temp_r3_199;
    s32 temp_r4_210;

    this->unk128 += gUpdateTimeDelta;
    var_r31_74 = GetFirstParticle((MKBaseParticleSystem::ParticleRec *) sp8);
    while (var_r31_74 != NULL) {
        temp_r30_77 = var_r31_74->unk2C;
        temp_f28_81 = this->unk128 - M2C_FIELD(temp_r30_77, f32 *, 0x10);
        if (temp_f28_81 > this->unk12C) {
            var_r31_74 = DestroyParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        } else {
            tx = M2C_FIELD(temp_r30_77, f32 *, 0) * gUpdateTimeDelta;
            ty = M2C_FIELD(temp_r30_77, f32 *, 4) * gUpdateTimeDelta;
            tz = M2C_FIELD(temp_r30_77, f32 *, 8) * gUpdateTimeDelta;
            M2C_FIELD(var_r31_74, f32 *, 0) = M2C_FIELD(var_r31_74, f32 *, 0) + tx;
            M2C_FIELD(var_r31_74, f32 *, 4) = M2C_FIELD(var_r31_74, f32 *, 4) + ty;
            var_r31_74->unk8 += tz;

            tx = this->unk108 * gUpdateTimeDelta;
            ty = this->unk10C * gUpdateTimeDelta;
            tz = this->unk110 * gUpdateTimeDelta;
            M2C_FIELD(temp_r30_77, f32 *, 0) = M2C_FIELD(temp_r30_77, f32 *, 0) + tx;
            M2C_FIELD(temp_r30_77, f32 *, 4) = M2C_FIELD(temp_r30_77, f32 *, 4) + ty;
            M2C_FIELD(temp_r30_77, f32 *, 8) = M2C_FIELD(temp_r30_77, f32 *, 8) + tz;

            temp_f25_140 = 3.0f * (6.2831855f * (temp_f28_81 / this->unk12C));
            temp_f26_143 = MKRand_Float((int *) &gViewSeed, 0.125f, 0.25f);
            temp_f27_147 = _table_sinf((0.25f * temp_f25_140) + 1.5707964f);
            sp40.unk0 = _table_sinf(temp_f25_140);
            sp40.unk4 = 0.0f;
            sp40.unk8 = temp_f27_147;

            scale = 100.0f * temp_f26_143;
            sp50.unk0 = sp40.unk0 * scale;
            sp50.unk4 = sp40.unk4 * scale;
            sp50.unk8 = sp40.unk8 * scale;

            tx = sp50.unk0 * gUpdateTimeDelta;
            ty = sp50.unk4 * gUpdateTimeDelta;
            tz = sp50.unk8 * gUpdateTimeDelta;
            M2C_FIELD(var_r31_74, f32 *, 0) = M2C_FIELD(var_r31_74, f32 *, 0) + tx;
            M2C_FIELD(var_r31_74, f32 *, 4) = M2C_FIELD(var_r31_74, f32 *, 4) + ty;
            var_r31_74->unk8 += tz;
            var_r31_74->unk24 += gUpdateTimeDelta * M2C_FIELD(temp_r30_77, f32 *, 0x1C);

            desc = checked_cast<MKBaseParticleSystemDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            count = M2C_FIELD(desc, s32 *, 0x80);
            var_r31_74->unk20 = (f32) fmod((f64) (var_r31_74->unk20 + this->unkF0), (f64) count);

            temp_r3_199 = M2C_FIELD(temp_r30_77, s32 *, 0x14);
            if (temp_f28_81 > (this->unk12C * this->unk134[temp_r3_199].unk0)) {
                M2C_FIELD(temp_r30_77, s32 *, 0x14) = temp_r3_199 + 1;
            }
            temp_r4_210 = M2C_FIELD(temp_r30_77, s32 *, 0x14);
            temp_r3_211 = this->unk134;
            temp_r0_212 = temp_r4_210 - 1;
            temp_f5_213 = this->unk12C;
            temp_r5_215 = &temp_r3_211[temp_r0_212];
            temp_f4_217 = temp_r5_215->unk0;
            temp_f3_224 = -((temp_f5_213 * temp_f4_217) - temp_f28_81) / (temp_f5_213 * (temp_r3_211[temp_r4_210].unk0 - temp_f4_217));
            var_r31_74->unk1C = (temp_f3_224 * temp_r5_215->unkC) + temp_r5_215->unk4;
            var_f0_227 = var_r31_74->unk1C;
            if (var_f0_227 < 1.0f) {

            } else {
                var_f0_227 = 1.0f;
            }
            if (var_f0_227 > 0.0f) {

            } else {
                var_f0_227 = 0.0f;
            }
            var_r31_74->unk1C = var_f0_227;
            temp_r5_247 = &this->unk134[temp_r0_212];
            var_r31_74->unk28 = M2C_FIELD(temp_r30_77, f32 *, 0x18) * ((temp_f3_224 * temp_r5_247->unk10) + temp_r5_247->unk8);
            var_r31_74 = GetNextParticle((MKBaseParticleSystem::ParticleRec *) sp8);
        }
    }
}

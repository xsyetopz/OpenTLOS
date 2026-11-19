void *MKBaseParticleSystem::CreateParticle() {
    MKParticleChunk *temp_r0_909;
    MKParticleChunk *temp_r0_918;
    MKParticleChunk *temp_r3_873;
    MKParticleChunk *temp_r3_881;
    MKParticleChunk *temp_r3_905;
    MKParticleChunk *temp_r4_892;
    MKParticleChunk *temp_r4_899;
    MKParticleChunk *temp_r5_904;
    MKParticleChunk *var_r4_913;
    s32 temp_r3_900;
    void *temp_r4_931;

    if (this->unkB4 == 0) {
        return NULL;
    }
    if (this->unkC8 != NULL) {
        return NULL;
    }
    temp_r3_873 = this->unkD0;
    if ((temp_r3_873 == NULL) || ((s32) M2C_FIELD(temp_r3_873, s32 *, 0xA84) >= 0x18)) {
        temp_r3_881 = MKParticleSystem_AllocChunk(this->unkCC);
        if (temp_r3_881 == NULL) {
            return NULL;
        }
        this->unkD4 += 1;
        M2C_FIELD(temp_r3_881, MKParticleChunk **, 0xA8C) = (MKParticleChunk *) this->unkD0;
        temp_r4_892 = this->unkD0;
        if (temp_r4_892 != NULL) {
            M2C_FIELD(temp_r4_892, MKParticleChunk **, 0xA88) = temp_r3_881;
        }
        this->unkD0 = temp_r3_881;
    }
    temp_r4_899 = this->unkD0;
    temp_r3_900 = M2C_FIELD(temp_r4_899, s32 *, 0xA84);
    M2C_FIELD(temp_r4_899, s32 *, 0xA84) = (s32) (temp_r3_900 + 1);
    temp_r5_904 = this->unkD0;
    temp_r3_905 = &temp_r4_899[temp_r3_900];
    if ((s32) M2C_FIELD(temp_r5_904, s32 *, 0xA84) >= 0x18) {
        temp_r0_909 = M2C_FIELD(temp_r5_904, MKParticleChunk **, 0xA8C);
        if (temp_r0_909 != NULL) {
            this->unkD0 = temp_r0_909;
            var_r4_913 = this->unkD0;
            for (;;) {
                temp_r0_918 = M2C_FIELD(var_r4_913, MKParticleChunk **, 0xA8C);
                if (temp_r0_918 == NULL) {
                    break;
                }
                var_r4_913 = temp_r0_918;
            }
            M2C_FIELD(var_r4_913, MKParticleChunk **, 0xA8C) = temp_r5_904;
            M2C_FIELD(temp_r5_904, MKParticleChunk **, 0xA88) = var_r4_913;
            M2C_FIELD(temp_r5_904, MKParticleChunk **, 0xA8C) = NULL;
            M2C_FIELD(this->unkD0, MKParticleChunk **, 0xA88) = NULL;
        }
    }
    this->unkD8 += 1;
    temp_r4_931 = this->unkA0;
    if (temp_r4_931 != NULL) {
        M2C_FIELD(temp_r3_905, f64 *, 0) = (f64) M2C_FIELD(temp_r4_931, f64 *, 0);
        M2C_FIELD(temp_r3_905, f64 *, 8) = (f64) M2C_FIELD(temp_r4_931, f64 *, 8);
    } else {
        M2C_FIELD(temp_r3_905, f32 *, 0x0) = 0.0f;
        temp_r3_905->unk4 = 0.0f;
        temp_r3_905->unk8 = 0.0f;
    }
    temp_r3_905->unk28 = 1.0f;
    temp_r3_905->unk10 = 1.0f;
    temp_r3_905->unk14 = 1.0f;
    temp_r3_905->unk18 = 1.0f;
    temp_r3_905->unk1C = 1.0f;
    temp_r3_905->unk20 = 0.0f;
    temp_r3_905->unk24 = 0.0f;
    return temp_r3_905;
}

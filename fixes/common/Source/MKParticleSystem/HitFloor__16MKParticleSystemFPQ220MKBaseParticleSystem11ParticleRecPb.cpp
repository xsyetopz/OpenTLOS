void *MKParticleSystem::HitFloor(MKBaseParticleSystem::ParticleRec *arg1, bool *arg2) {
    f32 temp_f1_27;
    f32 temp_f2_30;
    MKParticleChunk *temp_r5_28;
    void *temp_r6_32;

    *arg2 = 0;
    temp_f1_27 = this->unk11C;
    temp_r5_28 = M2C_FIELD(arg1, MKParticleChunk **, 4);
    temp_f2_30 = temp_r5_28->unk4;
    temp_r6_32 = temp_r5_28->unk2C;
    if (temp_f2_30 >= (temp_f1_27 - this->unk120)) {
        temp_r5_28->unk4 = temp_f1_27;
        M2C_FIELD(temp_r6_32, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r6_32, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_32, f32 *, 8) = 0.0f;
    } else {
        temp_r5_28->unk4 = (f32) (temp_f1_27 + (temp_f1_27 - temp_f2_30));
        M2C_FIELD(temp_r6_32, f32 *, 4) = (f32) (this->unk124 * (f32) __fabs(M2C_FIELD(temp_r6_32, f32 *, 4)));
    }
    return M2C_FIELD(arg1, MKParticleChunk **, 4);
}

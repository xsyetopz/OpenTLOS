void MKParticleSystem::CalculateEnvelope() {
    MKParticleSystem::Envelope *temp_r5_300;
    MKParticleSystem::Envelope *temp_r5_310;
    f32 temp_f0_313;
    s32 temp_r7_301;
    s32 temp_r9_295;
    s32 var_ctr_296;
    s32 var_r4_294;
    s32 var_r8_293;
    void *temp_r6_303;
    void *temp_r6_311;

    var_r8_293 = 0;
    var_r4_294 = 0;
    temp_r9_295 = this->unk130 - 1;
    if (temp_r9_295 > 0) {
        for (var_ctr_296 = 0; var_ctr_296 < temp_r9_295; var_ctr_296++) {
            temp_r5_300 = this->unk134;
            temp_r7_301 = (var_r8_293 + 1) * 0x14;
            var_r8_293 += 1;
            temp_r6_303 = (u8 *) temp_r5_300 + var_r4_294;
            M2C_FIELD(temp_r6_303, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r5_300, f32 *, temp_r7_301 + 4) - M2C_FIELD(temp_r6_303, f32 *, 4));
            temp_r5_310 = this->unk134;
            temp_r6_311 = (u8 *) temp_r5_310 + var_r4_294;
            temp_f0_313 = M2C_FIELD(temp_r6_311, f32 *, 8);
            var_r4_294 += 0x14;
            M2C_FIELD(temp_r6_311, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r5_310, f32 *, temp_r7_301 + 8) - temp_f0_313);
        }
    }
    this->unk134[temp_r9_295].unkC = 0.0f;
    this->unk134[temp_r9_295].unk10 = 0.0f;
}

void FallingLeaves::Init() {
    s32 temp_r0_2027;
    s32 var_ctr_2025;
    s32 var_r3_2022;

    MKParticleSystem::Init();
    this->unkA8 = 15.0f;
    this->unkAC = 15.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    this->unk110 = 0.0f;
    SetEnvelope(gFallingLeavesEnvelope, 5);
    SetMaxParticleAge(10.0f);
    var_r3_2022 = 0;
    var_ctr_2025 = 4;
    do {
        temp_r0_2027 = var_r3_2022 + 0x178;
        var_r3_2022 += 0x20;
        M2C_FIELD(this, s8 *, temp_r0_2027) = 0;
        var_ctr_2025 -= 1;
    } while (var_ctr_2025 != 0);
    this->unk1E0 = 1;
    this->unk1E1 = 0;
}

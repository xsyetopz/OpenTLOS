void ElectricFence::Init() {
    s32 temp_r0_1319;
    s32 var_ctr_1317;
    s32 var_r3_1315;
    ElectricFenceDescriptor *temp_r31_1327;
    ElectricFenceDescriptor *temp_r3_1328;

    MKProp::Init();
    this->unk54 = 1;
    var_r3_1315 = 0;
    this->unk50 = 0;
    var_ctr_1317 = 2;
    do {
        temp_r0_1319 = var_r3_1315 + 0xD0;
        var_r3_1315 += 0x18;
        M2C_FIELD(this, s32 *, temp_r0_1319) = 0;
        var_ctr_1317 -= 1;
    } while (var_ctr_1317 != 0);
    this->unk110 = NULL;
    temp_r31_1327 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_1328 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk114)->Init(temp_r3_1328->unk8C, temp_r31_1327->unk90);
}

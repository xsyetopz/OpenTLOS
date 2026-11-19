void *ElectricFence::Update() {
    f64 sp18;
    f64 sp10;
    MKSceneManager *temp_r3_445;
    f64 temp_f0_453;
    f64 temp_f1_452;
    s32 var_r29_463;
    s32 var_r31_464;
    s8 *temp_r30_472;
    MKVector3 *temp_r4_477;
    ElectricFenceDescriptor *temp_r3_433;
    ElectricFenceDescriptor *temp_r4_433;
    MKProp *temp_r3_448;
    void *temp_r3_451;

    temp_r3_433 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (temp_r3_433->unk84 != 0) {
        temp_r4_433 = checked_cast<ElectricFenceDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        ((KDSoundFader *) &this->unk114)->Update(temp_r4_433->unk84, true, this->unk54, (MKProp *) this, NULL, 0U, -1, true);
    }
    temp_r3_445 = this->unk110;
    if (temp_r3_445 != NULL) {
        temp_r3_448 = MKSceneManager::PropResolver_Resolve((s32) temp_r3_445);
        if (temp_r3_448 != NULL) {
            temp_r3_451 = temp_r3_448->unk8;
            temp_f1_452 = M2C_FIELD(temp_r3_451, f64 *, 0x30);
            temp_f0_453 = M2C_FIELD(temp_r3_451, f64 *, 0x38);
            sp10 = temp_f1_452;
            this->unk100 = temp_f1_452;
            sp18 = temp_f0_453;
            this->unk108 = temp_f0_453;
        }
    }
    if ((u8) this->unk54 != 0) {
        var_r29_463 = 0;
        var_r31_464 = 0;
        do {
            temp_r30_472 = (s8 *) this + var_r31_464;
            temp_r4_477 = (MKVector3 *) ((s8 *) this->unk4C + ((MKRand_Int((int *) &gViewSeed, 0, this->unk50) * 0x70) + 0x30));
            M2C_FIELD(temp_r30_472, MKVector3 *, 0xD8) = *temp_r4_477;
            var_r29_463 += 1;
            var_r31_464 += 0x18;
            M2C_FIELD(temp_r30_472, f32 *, 0xDC) = (f32) ((1000.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f)) + M2C_FIELD(temp_r30_472, f32 *, 0xDC));
        } while (var_r29_463 < 2);
    }
}

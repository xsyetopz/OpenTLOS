void *LightningStrikeFX::Update() {
    MKVector3 *temp_r5_543;
    LightningStrikeFXDescriptor *desc;
    f32 temp_f31_515;
    f32 var_f0_495;
    s32 temp_r30_536;
    s32 temp_r31_540;

    this->unkC4 -= gUpdateTimeDelta;
    var_f0_495 = this->unkC4;
    if (var_f0_495 < 4.0f) {

    } else {
        var_f0_495 = 4.0f;
    }
    if (var_f0_495 > 0.0f) {

    } else {
        var_f0_495 = 0.0f;
    }
    this->unkC4 = var_f0_495;
    this->unkC0 -= gUpdateTimeDelta;
    temp_f31_515 = this->unkC4;
    if ((temp_f31_515 > 0.0f) && (this->unkC0 <= 0.0f)) {
        this->unkC0 = -((temp_f31_515 * 0.25f) - 1.0f) * MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
        temp_r30_536 = MKRand_Int((int *) &gViewSeed, 0, this->unk50);
        temp_r31_540 = MKRand_Int((int *) &gViewSeed, 0, this->unk50);
        temp_r5_543 = this->unk4C;
        desc = checked_cast<LightningStrikeFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        desc->SpawnStrikeArc(temp_r5_543[temp_r31_540], temp_r5_543[temp_r30_536], 2.0f, 0.125f);
    }
}

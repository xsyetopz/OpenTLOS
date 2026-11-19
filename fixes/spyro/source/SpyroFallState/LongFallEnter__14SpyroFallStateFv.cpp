void SpyroFallState::LongFallEnter() {
    Spyro *temp_r3_747;
    Spyro *temp_r7_775;
    f32 temp_f0_751;
    f32 temp_f1_749;
    f32 var_f2_750;

    temp_r3_747 = this->unk10;
    temp_r3_747->unk390 = 3800.0f;
    temp_f1_749 = temp_r3_747->unk390;
    var_f2_750 = temp_r3_747->unk33C;
    temp_f0_751 = -temp_f1_749;
    if (var_f2_750 < temp_f1_749) {

    } else {
        var_f2_750 = temp_f1_749;
    }
    if (var_f2_750 > temp_f0_751) {

    } else {
        var_f2_750 = temp_f0_751;
    }
    temp_r3_747->unk33C = var_f2_750;
    this->unk10->unk38C = 1900.0f;
    this->unk10->SetAnim(0x3FU, 0.17f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r7_775 = this->unk10;
    temp_r7_775->unk428 &= 0xFFFBFFFE;
    this->unk44 = 0x40;
    this->unk3C = 0x187;
    this->unk48 = 1.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk51 = 0;
    this->unk50 = 0;
    this->unk35 = 0;
    this->unk80.Reset();
}

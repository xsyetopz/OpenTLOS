void SpyroLedgeGrabState::PullUpDescendEnter() {
    Spyro *temp_r3_100;
    f32 temp_f0_105;
    f32 temp_f1_103;
    f32 var_f2_104;

    this->unk10->SetAnim(0x5AU, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r3_100 = this->unk10;
    temp_r3_100->unk390 = 3800.0f;
    temp_f1_103 = temp_r3_100->unk390;
    var_f2_104 = temp_r3_100->unk33C;
    temp_f0_105 = -temp_f1_103;
    if (var_f2_104 < temp_f1_103) {

    } else {
        var_f2_104 = temp_f1_103;
    }
    if (var_f2_104 > temp_f0_105) {

    } else {
        var_f2_104 = temp_f0_105;
    }
    temp_r3_100->unk33C = var_f2_104;
    this->unk10->unk38C = 1900.0f;
}

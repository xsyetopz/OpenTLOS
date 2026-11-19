void SpyroFallState::GlideEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_651;
    Spyro *temp_r3_624;
    Spyro *temp_r3_632;
    f32 temp_f0_636;
    f32 temp_f1_634;
    f32 var_f2_635;

    this->unk6C.Start(this->unk10, 0.17f);
    temp_r3_624 = this->unk10;
    temp_r3_624->unk428 |= 0x8000;
    this->unk10->unk38C = 3240.0002f;
    temp_r3_632 = this->unk10;
    temp_r3_632->unk390 = 500.0f;
    temp_f1_634 = temp_r3_632->unk390;
    var_f2_635 = temp_r3_632->unk33C;
    temp_f0_636 = -temp_f1_634;
    if (var_f2_635 < temp_f1_634) {

    } else {
        var_f2_635 = temp_f1_634;
    }
    if (var_f2_635 > temp_f0_636) {

    } else {
        var_f2_635 = temp_f0_636;
    }
    temp_r3_632->unk33C = var_f2_635;
    temp_r3_651 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x437;
    temp_r3_651->Message((MKMessage *) &sp8);
    this->unk10->unk6F8.FadeIn(2, -1);
    this->unk44 = 0x37;
    this->unk3C = 0x187;
    this->unk48 = 0.0f;
    this->unk4C = 0.2f;
    this->unk50 = 1;
    this->unk51 = 1;
    this->unk4C = 0.0f;
}

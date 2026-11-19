void SpyroChargeState::Exit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_825;
    KDCamera *temp_r3_840;
    f32 temp_f0_811;
    f32 var_f1_810;

    var_f1_810 = 3.0f;
    temp_f0_811 = 3.0f * (this->unk28 / 5.0f);
    if (temp_f0_811 > 3.0f) {

    } else {
        var_f1_810 = temp_f0_811;
    }
    this->unk10->unk3C4 = var_f1_810;
    this->unk10->unk460.SetChargeTime(this->unk28);
    temp_r3_825 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x43A;
    temp_r3_825->Message((MKMessage *) &sp10);
    if (this->unk2C == -1.0f) {
        temp_r3_840 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x446;
        temp_r3_840->Message((MKMessage *) &sp8);
    }
    this->unk14.Exit(this);
}

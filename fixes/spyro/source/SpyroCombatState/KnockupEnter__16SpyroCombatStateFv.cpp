void SpyroCombatState::KnockupEnter() {
    MKVector3 scale;
    Spyro *temp_r3_989;
    Spyro *temp_r3_993;

    this->unk10->ClearMeleeButtonState();
    this->unk32 = 1;
    this->unk2E = 0;
    this->unk2D = 0;
    this->unk31 = 0;
    this->unk2F = 0;
    this->unk28 = 3;
    temp_r3_989 = this->unk10;
    temp_r3_989->unk428 |= 1;
    temp_r3_993 = this->unk10;
    temp_r3_993->unk428 |= 0x30;
    this->unk10->unk460.SetHitType(2);
    this->unk10->unk460.SetCombatArc(0);
    this->unk10->SetAnim(0x20U, 0.2f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    scale.unk0 = 2.0f;
    scale.unk4 = 2.0f;
    scale.unk8 = 2.0f;
    this->unk10->SetLVEScale(scale);
    this->unk31 = 0;
}

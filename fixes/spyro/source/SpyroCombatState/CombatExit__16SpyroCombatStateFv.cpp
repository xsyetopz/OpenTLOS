void SpyroCombatState::CombatExit() {
    Spyro *temp_r4_1269;

    this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = 1.0f;
    temp_r4_1269 = this->unk10;
    temp_r4_1269->unk428 &= 0xFFFFFFCF;
    this->unk2C = 0;
    this->unk2E = 0;
}

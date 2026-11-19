u8 SpyroStrafeState::DodgeLeftRightTransition() {
    s8 sp1D;
    s8 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_821;
    f32 var_f1_820;
    u8 var_r3_851;
    u8 var_r4_823;

    spC = 0;
    sp10 = 0x10;
    sp8 = 0x187;
    sp14 = 0.0f;
    sp18 = 0.2f;
    sp1C = 1;
    sp1D = 1;
    temp_r3_821 = this->unk10->GetInput();
    var_r4_823 = 0;
    if (((u8) temp_r3_821->unk5 != 0) || ((u8) temp_r3_821->unk4 != 0)) {
        var_r4_823 = 1;
    }
    if (var_r4_823 != 0) {
        var_f1_820 = 0.0f;
    } else {
        var_f1_820 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_821->unk0, NULL, NULL);
    }
    var_r3_851 = this->unk10->TryChangeState((var_f1_820 == 0.0f), 4U, (MKMessage *) &sp8, 0U);
    if (var_r3_851 == 0) {
        var_r3_851 = (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk24 > 0.5f);
        if (var_r3_851 != 0) {
            var_r3_851 = AnyToDodgeTranstion();
        }
    }
    if (var_r3_851 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && (M2C_FIELD(this, s32 *, 0x14) != 1)) {
            this->unk14.SetState(this, 1, 0U);
            return 1U;
        }
        return 0U;
    }
    return var_r3_851;
}

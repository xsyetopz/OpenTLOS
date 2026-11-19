s32 SpyroJumpState::JumpLoftTransition() {
    InputModifier *temp_r3_433;
    u8 var_r0_434;
    u8 var_r3_422;

    var_r3_422 = M2C_FIELD(this, u8 *, 0x2F);
    if (var_r3_422 != 0) {
        var_r3_422 = GameData::gameData[0x168] & 1;
    }
    if (var_r3_422 != 0) {
        temp_r3_433 = this->unk10->GetInput();
        var_r0_434 = temp_r3_433->unk5;
        if (var_r0_434 == 0) {
            var_r0_434 = temp_r3_433->unk4;
        }
        if (var_r0_434 != 0) {
            var_r3_422 = 0;
        } else {
            var_r3_422 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_433->unk0);
        }
    }
    if (var_r3_422 != 0) {
        var_r3_422 = (u8) this->unk10->unk3D2 == 0;
    }
    if ((var_r3_422 != 0) && (M2C_FIELD(&this->unk18, s32 *, 0) != 3)) {
        this->unk18.SetState(this, 3, 0U);
        return 1;
    }
    return 0;
}

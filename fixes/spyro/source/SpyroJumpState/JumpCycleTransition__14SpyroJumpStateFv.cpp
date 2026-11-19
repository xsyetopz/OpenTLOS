u8 SpyroJumpState::JumpCycleTransition() {
    InputModifier *temp_r3_606;
    u8 var_r0_573;
    u8 var_r0_607;
    u8 var_r3_588;
    u8 var_r3_595;

    var_r0_573 = M2C_FIELD(this, u8 *, 0x2D);
    if (var_r0_573 == 0) {
        var_r0_573 = M2C_FIELD(this, u8 *, 0x2C);
    }
    if ((var_r0_573 != 0) && (M2C_FIELD(&this->unk18, s32 *, 0) != 2)) {
        this->unk18.SetState(this, 2, 0U);
        var_r3_588 = 1;
    } else {
        var_r3_588 = 0;
    }
    if (var_r3_588 == 0) {
        var_r3_595 = M2C_FIELD(this, u8 *, 0x2F);
        if (var_r3_595 != 0) {
            var_r3_595 = GameData::gameData[0x168] & 1;
        }
        if (var_r3_595 != 0) {
            temp_r3_606 = this->unk10->GetInput();
            var_r0_607 = temp_r3_606->unk5;
            if (var_r0_607 == 0) {
                var_r0_607 = temp_r3_606->unk4;
            }
            if (var_r0_607 != 0) {
                var_r3_595 = 0;
            } else {
                var_r3_595 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_606->unk0);
            }
        }
        if (var_r3_595 != 0) {
            var_r3_595 = (u8) this->unk10->unk3D2 == 0;
        }
        if ((var_r3_595 != 0) && (M2C_FIELD(&this->unk18, s32 *, 0) != 3)) {
            this->unk18.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_588 = 0;
        return var_r3_588;
    }
    return var_r3_588;
}

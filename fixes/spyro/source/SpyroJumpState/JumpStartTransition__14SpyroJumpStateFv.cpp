u8 SpyroJumpState::JumpStartTransition() {
    InputModifier *temp_r3_756;
    u8 var_r0_702;
    u8 var_r0_757;
    u8 var_r3_717;
    u8 var_r3_745;

    var_r0_702 = M2C_FIELD(this, u8 *, 0x2D);
    if (var_r0_702 == 0) {
        var_r0_702 = M2C_FIELD(this, u8 *, 0x2C);
    }
    if ((var_r0_702 != 0) && (M2C_FIELD(&this->unk18, s32 *, 0) != 2)) {
        this->unk18.SetState(this, 2, 0U);
        var_r3_717 = 1;
    } else {
        var_r3_717 = 0;
    }
    if (var_r3_717 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && (M2C_FIELD(&this->unk18, s32 *, 0) != 1)) {
            this->unk18.SetState(this, 1, 0U);
            var_r3_717 = 1;
        } else {
            var_r3_717 = 0;
        }
    }
    if (var_r3_717 == 0) {
        var_r3_745 = M2C_FIELD(this, u8 *, 0x2F);
        if (var_r3_745 != 0) {
            var_r3_745 = GameData::gameData[0x168] & 1;
        }
        if (var_r3_745 != 0) {
            temp_r3_756 = this->unk10->GetInput();
            var_r0_757 = temp_r3_756->unk5;
            if (var_r0_757 == 0) {
                var_r0_757 = temp_r3_756->unk4;
            }
            if (var_r0_757 != 0) {
                var_r3_745 = 0;
            } else {
                var_r3_745 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_756->unk0);
            }
        }
        if (var_r3_745 != 0) {
            var_r3_745 = (u8) this->unk10->unk3D2 == 0;
        }
        if ((var_r3_745 != 0) && (M2C_FIELD(&this->unk18, s32 *, 0) != 3)) {
            this->unk18.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_717 = 0;
        return var_r3_717;
    }
    return var_r3_717;
}

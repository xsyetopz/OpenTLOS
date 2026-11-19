s32 SpyroLedgeGrabState::AttachTransition() {
    InputModifier *temp_r3_253;
    s32 var_r3_266;
    u8 var_r4_255;

    temp_r3_253 = this->unk10->GetInput();
    var_r4_255 = 0;
    if (((u8) temp_r3_253->unk5 != 0) || ((u8) temp_r3_253->unk4 != 0)) {
        var_r4_255 = 1;
    }
    if (var_r4_255 != 0) {
        var_r3_266 = 0;
    } else {
        var_r3_266 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_253->unk0);
    }
    if ((u8) var_r3_266 == 0) {
        var_r3_266 = this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1;
    }
    if (((u8) var_r3_266 != 0) && ((s32) M2C_FIELD(this, s32 *, 0x14) != 1)) {
        this->unk14.SetState(this, 1, 0U);
        return 1;
    }
    return 0;
}

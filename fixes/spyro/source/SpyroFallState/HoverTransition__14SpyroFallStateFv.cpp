u8 SpyroFallState::HoverTransition() {
    InputModifier *temp_r3_235;
    f32 var_f1_248;
    u8 var_r3_268;
    u8 var_r4_237;

    temp_r3_235 = this->unk10->GetInput();
    var_r4_237 = 0;
    if (((u8) temp_r3_235->unk5 != 0) || ((u8) temp_r3_235->unk4 != 0)) {
        var_r4_237 = 1;
    }
    if (var_r4_237 != 0) {
        var_f1_248 = 0.0f;
    } else {
        var_f1_248 = MKInput_GetState(0xE, (MKInputDevices) temp_r3_235->unk0, NULL, NULL);
    }
    if ((var_f1_248 == 0.0f) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 0)) {
        this->unk14.SetState(this, 0, 0U);
        var_r3_268 = 1;
    } else {
        var_r3_268 = 0;
    }
    if (var_r3_268 == 0) {
        if (((u8) (((KDInput *) (this->unk10->GetInput()))->GetLeftMag() != 0.0f) != 0) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 2)) {
            this->unk14.SetState(this, 2, 0U);
            return 1U;
        }
        var_r3_268 = 0;
        return var_r3_268;
    }
    return var_r3_268;
}

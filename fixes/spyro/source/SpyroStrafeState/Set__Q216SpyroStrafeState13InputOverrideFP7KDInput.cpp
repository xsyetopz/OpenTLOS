void SpyroStrafeState::InputOverride::Set(KDInput *arg1) {
    f32 var_f1_46;
    f32 var_f1_68;
    u8 var_r3_34;
    u8 var_r3_56;

    M2C_FIELD(this, u8 *, 0) = 1;
    var_r3_34 = 0;
    if (((u8) arg1->unk5 != 0) || ((u8) arg1->unk4 != 0)) {
        var_r3_34 = 1;
    }
    if (var_r3_34 != 0) {
        var_f1_46 = 0.0f;
    } else {
        var_f1_46 = MKInput_GetState(0x11, (MKInputDevices) arg1->unk0, NULL, NULL);
    }
    M2C_FIELD(this, f32 *, 4) = var_f1_46;
    var_r3_56 = 0;
    if (((u8) arg1->unk5 != 0) || ((u8) arg1->unk4 != 0)) {
        var_r3_56 = 1;
    }
    if (var_r3_56 != 0) {
        var_f1_68 = 0.0f;
    } else {
        var_f1_68 = MKInput_GetState(0x10, (MKInputDevices) arg1->unk0, NULL, NULL);
    }
    M2C_FIELD(this, f32 *, 8) = var_f1_68;
    M2C_FIELD(this, f32 *, 0xC) = arg1->GetLeftMag();
}

void UIInputTracker::Update() {
    s8 *base;
    f32 var_f1_485;
    f32 var_f1_509;
    f32 var_f1_537;
    f32 var_f1_562;
    s32 var_r4_458;
    u8 var_r3_474;
    u8 var_r3_498;
    u8 var_r3_526;
    u8 var_r3_551;

    base = (s8 *) this;
    for (var_r4_458 = 0; var_r4_458 < 4; var_r4_458++) {
        M2C_FIELD(base + (var_r4_458 + 0x18), u8 *, 0) = 0;
    }
    if ((u8) this->unk1C != 0) {
        var_r3_474 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_474 = 1;
        }
        if (var_r3_474 != 0) {
            var_f1_485 = 0.0f;
        } else {
            var_f1_485 = MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
        }
        if (var_f1_485 == 0.0f) {
            var_r3_498 = 0;
            if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
                var_r3_498 = 1;
            }
            if (var_r3_498 != 0) {
                var_f1_509 = 0.0f;
            } else {
                var_f1_509 = MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
            }
            if (var_f1_509 == 0.0f) {
                this->unk1C = 0;
            }
        }
    } else {
        var_r3_526 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_526 = 1;
        }
        if (var_r3_526 != 0) {
            var_f1_537 = 0.0f;
        } else {
            var_f1_537 = MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
        }
        CheckDirection(4, 6, var_f1_537);
        var_r3_551 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_551 = 1;
        }
        if (var_r3_551 != 0) {
            var_f1_562 = 0.0f;
        } else {
            var_f1_562 = MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
        }
        CheckDirection(5, 7, var_f1_562);
    }
}

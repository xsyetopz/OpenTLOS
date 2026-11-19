u8 SpyroDeathState::AirTransition() {
    u8 var_r31_358;
    u8 var_r3_390;
    u8 var_r3_398;

    var_r31_358 = 0;
    if (((M2C_FIELD(&gb, f32 *, 0x30C) - this->unk2C) > 4.0f) && ((s32) M2C_FIELD(&gb, s32 *, 0x50) == 3)) {
        var_r31_358 = 1;
    }
    if ((s32) M2C_FIELD(this->unk10->unk27C, s32 *, 0x16C) > 0) {
        this->unk2A = 0;
    }
    if (((s32) M2C_FIELD(this->unk10->unk27C, s32 *, 0x16C) > 0) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 0)) {
        this->unk14.SetState(this, 0, 0U);
        var_r3_390 = 1;
    } else {
        var_r3_390 = 0;
    }
    if (var_r3_390 == 0) {
        var_r3_398 = var_r31_358;
        if (var_r31_358 != 0) {
            var_r3_398 = *CheckPoint::pCurrentCheckPoint != 0;
        }
        if ((var_r3_398 != 0) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 4)) {
            this->unk14.SetState(this, 4, 0U);
            var_r3_390 = 1;
        } else {
            var_r3_390 = 0;
        }
    }
    if (var_r3_390 == 0) {
        if (var_r31_358 != 0) {
            var_r31_358 = *CheckPoint::pCurrentCheckPoint == 0;
        }
        if ((var_r31_358 != 0) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 3)) {
            this->unk14.SetState(this, 3, 0U);
            return 1U;
        }
        var_r3_390 = 0;
        return var_r3_390;
    }
    return var_r3_390;
}

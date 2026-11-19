void ElectricFence::EnableFenceCollision(bool arg0) {
    s32 temp_r0_186;
    s32 temp_r0_199;
    s32 var_r4_179;
    s32 var_r5_180;
    s32 var_r8_178;

    var_r8_178 = 0;
    var_r4_179 = 0;
    var_r5_180 = 0;
    if (arg0 != 0) {
        while (var_r8_178 < (s32) (this->unk50 - 1)) {
            temp_r0_186 = var_r5_180 + 0x5C;
            var_r8_178 += 1;
            var_r5_180 += 0x70;
            M2C_FIELD(this->unk4C, s8 *, temp_r0_186) = 1;
        }
        return;
    }
    while (var_r8_178 < (s32) (this->unk50 - 1)) {
        temp_r0_199 = var_r4_179 + 0x5C;
        var_r8_178 += 1;
        var_r4_179 += 0x70;
        M2C_FIELD(this->unk4C, s8 *, temp_r0_199) = 0;
    }
}

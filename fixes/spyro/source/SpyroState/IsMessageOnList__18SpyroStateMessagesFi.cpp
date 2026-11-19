s32 SpyroStateMessages::IsMessageOnList(int arg0) {
    u32 temp_r7_362;
    u32 var_r0_368;
    u32 var_r8_363;

    temp_r7_362 = this->unk50;
    var_r8_363 = 0U;
    while (var_r8_363 < ((temp_r7_362 < 0xAU) ? temp_r7_362 : 0xAU)) {
        var_r0_368 = 0xA;
        if (temp_r7_362 < 0xAU) {
            var_r0_368 = temp_r7_362;
        }
        if (arg0 == M2C_FIELD(this, s32 *, ((((var_r8_363 + (temp_r7_362 - var_r0_368)) % 10) * 8) + 4))) {
            return 1;
        }
        var_r8_363 += 1;
    }
    return 0;
}

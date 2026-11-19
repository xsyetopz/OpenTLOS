MKMessage *SpyroStateMessages::GetMessage(int arg0) {
    u32 temp_r7_401;
    u32 var_r0_407;
    u32 var_r0_422;
    u32 var_r8_402;

    temp_r7_401 = this->unk50;
    var_r8_402 = 0U;
    while (var_r8_402 < ((temp_r7_401 < 0xAU) ? temp_r7_401 : 0xAU)) {
        var_r0_407 = 0xA;
        if (temp_r7_401 < 0xAU) {
            var_r0_407 = temp_r7_401;
        }
        if (arg0 == M2C_FIELD(this, s32 *, ((((var_r8_402 + (temp_r7_401 - var_r0_407)) % 10) * 8) + 4))) {
            var_r0_422 = 0xA;
            if (temp_r7_401 < 0xAU) {
                var_r0_422 = temp_r7_401;
            }
            return M2C_FIELD(this, MKMessage **, (((var_r8_402 + (temp_r7_401 - var_r0_422)) % 10) * 8));
        }
        var_r8_402 += 1;
    }
    return 0;
}

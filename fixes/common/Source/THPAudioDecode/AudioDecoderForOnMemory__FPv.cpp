void AudioDecoderForOnMemory(void *arg0) {
    s32 spC;
    void *sp8;
    s32 temp_r4_184;
    s32 var_r29_155;
    s32 var_r31_153;

    var_r31_153 = 0;
    sp8 = arg0;
    var_r29_155 = M2C_FIELD(&ActivePlayer, s32 *, 0xBC);
loop_1:
    spC = var_r31_153;
    AudioDecode((THPReadBuffer *) &sp8);
    if ((u32) ((var_r31_153 + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) {
        if (M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1) {
            var_r29_155 = *(s32 *) sp8;
            sp8 = M2C_FIELD(&ActivePlayer, void **, 0xB4);
        } else {
            OSSuspendThread(&AudioDecodeThread);
        }
    } else {
        temp_r4_184 = *(s32 *) sp8;
        sp8 = (u8 *) sp8 + var_r29_155;
        var_r29_155 = temp_r4_184;
    }
    var_r31_153 += 1;
    goto loop_1;
}

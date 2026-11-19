void RopeBridge::LowDetailUpdate() {
    s32 temp_r0_2294;
    s32 var_r3_2290;
    s32 var_r5_2289;

    UpdatePlanks(0xA, 0.018333334f, 8.0f);
    var_r5_2289 = 1;
    var_r3_2290 = 0x50;
loop_2:
    if (var_r5_2289 < (s32) (this->unk188 - 1)) {
        temp_r0_2294 = var_r3_2290 + 8;
        var_r5_2289 += 1;
        var_r3_2290 += 0x50;
        *(f32 *) ((u8 *) this->unk184 + temp_r0_2294) = 0.0f;
        goto loop_2;
    }
}

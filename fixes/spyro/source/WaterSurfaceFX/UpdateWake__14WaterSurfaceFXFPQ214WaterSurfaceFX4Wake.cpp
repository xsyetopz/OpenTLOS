u8 WaterSurfaceFX::UpdateWake(WaterSurfaceFX::Wake *arg1) {
    s32 temp_r0_835;
    u8 *temp_r3_833;
    s32 temp_r3_858;
    s32 var_r6_828;

    var_r6_828 = M2C_FIELD(arg1, s32 *, 4);
loop_6:
    temp_r3_858 = M2C_FIELD(arg1, s32 *, 8);
    if (var_r6_828 != temp_r3_858) {
        temp_r3_833 = M2C_FIELD(arg1, u8 **, 0);
        temp_r0_835 = (var_r6_828 * 0x28) + 0x24;
        *(f32 *) (temp_r3_833 + temp_r0_835) = *(f32 *) (temp_r3_833 + temp_r0_835) - gUpdateTimeDelta;
        if (*(f32 *) (M2C_FIELD(arg1, u8 **, 0) + temp_r0_835) <= 0.0f) {
            M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + 1);
            if ((s32) M2C_FIELD(arg1, s32 *, 4) >= 0x32) {
                M2C_FIELD(arg1, s32 *, 4) = 0;
            }
        }
        var_r6_828 += 1;
        if (var_r6_828 >= 0x32) {
            var_r6_828 = 0;
        }
        goto loop_6;
    }
    return M2C_FIELD(arg1, s32 *, 4) != temp_r3_858;
}

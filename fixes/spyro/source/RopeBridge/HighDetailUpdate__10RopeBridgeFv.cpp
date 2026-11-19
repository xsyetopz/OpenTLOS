void RopeBridge::HighDetailUpdate() {
    f32 temp_f2_2232;
    f32 temp_f5_2226;
    f32 var_f0_2241;
    s32 var_r4_2224;
    u8 *var_r5_2229;

    UpdatePlanks(0x1E, 0.033333335f, 0.0f);
    var_r4_2224 = 1;
    temp_f5_2226 = -ROPEBRIDGE_MAXROLL;
    var_r5_2229 = ((u8 *) this->unk184) + 0x50;
loop_10:
    if (var_r4_2224 < (s32) (this->unk188 - 1)) {
        temp_f2_2232 = M2C_FIELD(var_r5_2229, f32 *, 0x4C);
        if (temp_f2_2232 != 0.0f) {
            M2C_FIELD(var_r5_2229, f32 *, 8) = (f32) ((temp_f2_2232 * gUpdateTimeDelta) + M2C_FIELD(var_r5_2229, f32 *, 8));
            M2C_FIELD(var_r5_2229, f32 *, 0x4C) = 0.0f;
        }
        var_f0_2241 = M2C_FIELD(var_r5_2229, f32 *, 8);
        if (var_f0_2241 < ROPEBRIDGE_MAXROLL) {

        } else {
            var_f0_2241 = ROPEBRIDGE_MAXROLL;
        }
        if (var_f0_2241 > temp_f5_2226) {

        } else {
            var_f0_2241 = temp_f5_2226;
        }
        M2C_FIELD(var_r5_2229, f32 *, 8) = var_f0_2241;
        var_r4_2224 += 1;
        M2C_FIELD(var_r5_2229, f32 *, 8) = (f32) (0.5f * ((0.5f * (M2C_FIELD(var_r5_2229, f32 *, -0x48) + M2C_FIELD(var_r5_2229, f32 *, 0x58))) + M2C_FIELD(var_r5_2229, f32 *, 8)));
        var_r5_2229 += 0x50;
        goto loop_10;
    }
}

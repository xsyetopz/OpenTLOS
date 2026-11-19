void SpyroJumpState::DoubleJumpEnter() {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    MKVector3 sp10;
    f32 sp8;
    f32 temp_f7_127;
    f32 var_f31_144;
    f32 var_f3_134;
    f64 temp_f1_147;
    f64 temp_f1_153;
    f64 temp_f1_157;
    s32 temp_r3_176;
    s32 var_r0_186;
    void *temp_r3_119;

    M2C_FIELD(this, s8 *, 0x2E) = 0;
    temp_r3_119 = this->unk10->unk8;
    sp20 = M2C_FIELD(temp_r3_119, f64 *, 0x30);
    temp_f7_127 = (*(f32 *) ((u8 *) &sp20 + 0x4)) - this->unk34;
    sp28 = M2C_FIELD(temp_r3_119, f64 *, 0x38);
    var_f3_134 = (150.0f * (1.0f - ((temp_f7_127 - 100.0f) / 200.0f))) + 250.0f;
    if ((var_f3_134 + temp_f7_127) > 550.0f) {
        var_f3_134 = 550.0f - temp_f7_127;
    }
    var_f31_144 = 1900.0f * (2.0f * var_f3_134);
    if (var_f31_144 > 0.0f) {
        temp_f1_147 = __frsqrte(var_f31_144);
        temp_f1_153 = 0.5 * temp_f1_147 * -(((f64) var_f31_144 * (temp_f1_147 * temp_f1_147)) - 3.0);
        temp_f1_157 = 0.5 * temp_f1_153 * -(((f64) var_f31_144 * (temp_f1_153 * temp_f1_153)) - 3.0);
        var_f31_144 = (f32) ((f64) var_f31_144 * (0.5 * temp_f1_157 * -(((f64) var_f31_144 * (temp_f1_157 * temp_f1_157)) - 3.0)));
    } else if (var_f31_144 < M2C_BITWISE(f32, 0.0)) {
        var_f31_144 = __float_nan;
    } else {
        sp8 = var_f31_144;
        temp_r3_176 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_176) {
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_186 = 1;
            } else {
                var_r0_186 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_186 = 5;
            } else {
                var_r0_186 = 3;
            }
            break;
        default:
            var_r0_186 = 4;
            break;
        }
        if (var_r0_186 == 1) {
            var_f31_144 = __float_nan;
        }
    }
    this->unk10->SetDesiredVelocityVectical(var_f31_144, 540000.0f);
    this->unk10->SetAnim(0x32U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    sp10 = GetJumpVel();
    *(MKVector3 *) &sp30 = sp10;
    (*(f32 *) ((u8 *) &sp30 + 0x4)) = var_f31_144;
    this->unk10->SetDesiredVelocity(*((MKVector3 *) &sp30), 540000.0f);
    this->unk10->unk460.SetTailStrikeEnabled(1U);
}

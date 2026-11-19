u8 Clip(float arg0, float arg1, float arg2, float &arg3, float &arg4) {
    f32 temp_f0_1643;
    f32 temp_f0_1673;
    f32 temp_f2_1642;
    f32 temp_f2_1672;
    f32 temp_f4_1631;
    f32 temp_f5_1635;
    f32 temp_f5_1665;

    temp_f4_1631 = arg1 - arg2;
    if (arg0 > 0.0f) {
        temp_f5_1635 = arg0 * arg4;
        if (temp_f4_1631 > temp_f5_1635) {
            return 0U;
        }
        temp_f2_1642 = arg1 + arg2;
        temp_f0_1643 = arg0 * arg3;
        if (temp_f4_1631 > temp_f0_1643) {
            arg3 = temp_f4_1631 / arg0;
            goto block_7;
        }
        if (temp_f2_1642 < temp_f0_1643) {
            return 0U;
        }
block_7:
        if (temp_f2_1642 < temp_f5_1635) {
            arg4 = temp_f2_1642 / arg0;
        }
        return 1U;
    }
    if (arg0 < 0.0f) {
        temp_f5_1665 = arg0 * arg3;
        if (temp_f4_1631 > temp_f5_1665) {
            return 0U;
        }
        temp_f2_1672 = arg1 + arg2;
        temp_f0_1673 = arg0 * arg4;
        if (temp_f4_1631 > temp_f0_1673) {
            arg4 = temp_f4_1631 / arg0;
            goto block_17;
        }
        if (temp_f2_1672 < temp_f0_1673) {
            return 0U;
        }
block_17:
        if (temp_f2_1672 < temp_f5_1665) {
            arg3 = temp_f2_1672 / arg0;
        }
        return 1U;
    }
    if ((arg1 > -arg2) && (arg1 < arg2)) {
        return 1U;
    }
    return 0U;
}

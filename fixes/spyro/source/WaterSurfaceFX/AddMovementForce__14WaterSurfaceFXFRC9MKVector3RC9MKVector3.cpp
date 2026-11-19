void WaterSurfaceFX::AddMovementForce(const MKVector3 &arg0, const MKVector3 &arg1) {
    f32 var_f1_883;
    f32 var_f2_877;
    f32 var_f31_919;
    f32 var_f4_909;
    f32 sp8;
    f64 temp_f1_924;
    f64 temp_f1_930;
    f64 temp_f1_934;
    s32 temp_r3_953;
    s32 var_r0_963;
    MKVector3 vec;

    var_f2_877 = arg1.unk4;
    if (var_f2_877 < 0.0f) {
        var_f1_883 = -var_f2_877;
    } else {
        var_f1_883 = var_f2_877;
    }
    if (var_f1_883 >= 400.0f) {
        if (var_f2_877 < 0.0f) {
            var_f2_877 = -var_f2_877;
        }
        SpawnRipple(arg0, 1.0f + (var_f2_877 / 500.0f));
        return;
    }
    vec.unk0 = arg1.unk0;
    vec.unk4 = 0.0f;
    vec.unk8 = arg1.unk8;
    vec.unkC = arg1.unkC;
    var_f4_909 = 0.0f;
    var_f31_919 = (vec.unk8 * vec.unk8) + ((vec.unk0 * vec.unk0) + (0.0f * 0.0f));
    if (var_f31_919 > 0.000001f) {
        if (var_f31_919 > 0.0f) {
            temp_f1_924 = __frsqrte(var_f31_919);
            temp_f1_930 = 0.5 * temp_f1_924 * -(((f64) var_f31_919 * (temp_f1_924 * temp_f1_924)) - 3.0);
            temp_f1_934 = 0.5 * temp_f1_930 * -(((f64) var_f31_919 * (temp_f1_930 * temp_f1_930)) - 3.0);
            var_f31_919 = (f32) ((f64) var_f31_919 * (0.5 * temp_f1_934 * -(((f64) var_f31_919 * (temp_f1_934 * temp_f1_934)) - 3.0)));
        } else if (var_f31_919 < 0.0f) {
            var_f31_919 = __float_nan;
        } else {
            sp8 = var_f31_919;
            temp_r3_953 = *(s32 *) &sp8 & 0x7F800000;
            switch (temp_r3_953) {
            case 0x7F800000:
                if (*(s32 *) &sp8 & 0x7FFFFF) {
                    var_r0_963 = 1;
                } else {
                    var_r0_963 = 2;
                }
                break;
            case 0x0:
                if (*(s32 *) &sp8 & 0x7FFFFF) {
                    var_r0_963 = 5;
                } else {
                    var_r0_963 = 3;
                }
                break;
            default:
                var_r0_963 = 4;
                break;
            }
            if (var_r0_963 == 1) {
                var_f31_919 = __float_nan;
            }
        }
        var_f4_909 = 1.0f / var_f31_919;
    } else {
        var_f31_919 = 0.0f;
    }
    vec.unk0 = vec.unk0 * var_f4_909;
    vec.unk4 = vec.unk4 * var_f4_909;
    vec.unk8 = vec.unk8 * var_f4_909;
    if (var_f31_919 >= 25.0f) {
        if (this->unk50 == NULL) {
            SpawnWake();
        }
        AddWakeNode(this->unk50, arg0, vec, var_f31_919 / 500.0f);
    }
}

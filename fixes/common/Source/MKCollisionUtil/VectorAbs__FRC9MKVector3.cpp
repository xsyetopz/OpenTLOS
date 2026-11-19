MKVector3 VectorAbs(const MKVector3 &arg1) {
    MKVector3 result;
    f32 var_f1_2572;
    f32 var_f2_2559;
    f32 var_f3_2566;

    var_f2_2559 = arg1.unk8;
    if (var_f2_2559 < 0.0f) {
        var_f2_2559 = -var_f2_2559;
    }
    var_f3_2566 = arg1.unk4;
    if (var_f3_2566 < 0.0f) {
        var_f3_2566 = -var_f3_2566;
    }
    var_f1_2572 = arg1.unk0;
    if (var_f1_2572 < 0.0f) {
        var_f1_2572 = -var_f1_2572;
    }
    result.unk0 = var_f1_2572;
    result.unk4 = var_f3_2566;
    result.unk8 = var_f2_2559;
    return result;
}

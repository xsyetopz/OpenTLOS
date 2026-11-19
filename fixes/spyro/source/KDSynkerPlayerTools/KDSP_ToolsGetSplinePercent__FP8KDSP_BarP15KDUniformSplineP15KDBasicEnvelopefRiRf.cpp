s32 KDSP_ToolsGetSplinePercent(KDSP_Bar *arg0, KDUniformSpline *arg1, KDBasicEnvelope *arg2, float arg3, int &arg4, float &arg5) {
    f32 temp_f1_329;
    f32 temp_f2_316;
    f32 var_f0_271;
    f32 var_f0_296;
    f32 var_f0_344;
    f32 var_f3_313;

    if (arg1->unk0 == 1) {
        return 0;
    }
    var_f0_271 = (arg3 - (f32) arg0->unk0) / (f32) arg0->unk4;
    if (var_f0_271 < 1.0f) {

    } else {
        var_f0_271 = 1.0f;
    }
    if (var_f0_271 > 0.0f) {

    } else {
        var_f0_271 = 0.0f;
    }
    arg5 = var_f0_271;
    if ((arg2 != NULL) && ((s32) arg2->unk0 > 0)) {
        arg5 = arg2->GetValue(arg5);
    }
    var_f0_296 = arg5;
    if (var_f0_296 < 1.0f) {

    } else {
        var_f0_296 = 1.0f;
    }
    if (var_f0_296 > 0.0f) {

    } else {
        var_f0_296 = 0.0f;
    }
    arg5 = var_f0_296;
    var_f3_313 = 0.0f;
    temp_f2_316 = arg5 * arg1->unk8;
    arg4 = 0;
    temp_f1_329 = *(f32 *) (arg1->unkC + ((arg4 << 5) + 0x1C));
    while (((var_f3_313 + temp_f1_329) < temp_f2_316) && (arg4 < (s32) (arg1->unk4 - 1))) {
        var_f3_313 += temp_f1_329;
        arg4 += 1;
        temp_f1_329 = *(f32 *) (arg1->unkC + ((arg4 << 5) + 0x1C));
    }
    if (temp_f1_329 > 0.0f) {
        arg5 = (temp_f2_316 - var_f3_313) / temp_f1_329;
        var_f0_344 = arg5;
        if (var_f0_344 < 1.0f) {

        } else {
            var_f0_344 = 1.0f;
        }
        if (var_f0_344 > 0.0f) {

        } else {
            var_f0_344 = 0.0f;
        }
        arg5 = var_f0_344;
        return 1;
    }
    return 0;
}

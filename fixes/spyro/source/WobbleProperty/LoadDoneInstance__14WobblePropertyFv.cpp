void WobbleProperty::LoadDoneInstance() {
    MKModel *temp_r28;
    u8 *temp_r29;
    f32 sp10;
    f32 sp20[0x10];
    f32 var_f4;
    f32 temp_f0;
    f64 temp_f1_513;
    f64 temp_f1_519;
    f64 temp_f1_523;
    s32 var_r0;
    s32 temp_r3;
    u8 *temp_r3_586;

    temp_r29 = *(u8 **) KDProperty::pInstanceMem;
    temp_r28 = M2C_FIELD(temp_r29, MKModel **, 4);
    *(void **) (temp_r29 + this->unk8) = MKDynamicBone_GetDynamicBone(temp_r28, MKModel_GetAnimation(temp_r28)->GetNodeIndex(*(const char **) &this->unk14));
    M2C_STRUCT_COPY(sp20, *(void **) (temp_r29 + 8), 0x40);
    var_f4 = (sp20[2] * sp20[2]) + ((sp20[0] * sp20[0]) + (sp20[1] * sp20[1]));
    if (var_f4 > 0.0f) {
        temp_f1_513 = __frsqrte(var_f4);
        temp_f1_519 = 0.5 * temp_f1_513 * -(((f64) var_f4 * (temp_f1_513 * temp_f1_513)) - 3.0);
        temp_f1_523 = 0.5 * temp_f1_519 * -(((f64) var_f4 * (temp_f1_519 * temp_f1_519)) - 3.0);
        var_f4 = (f32) ((f64) var_f4 * (0.5 * temp_f1_523 * -(((f64) var_f4 * (temp_f1_523 * temp_f1_523)) - 3.0)));
    } else if (var_f4 < 0.0f) {
        var_f4 = __float_nan;
    } else {
        sp10 = var_f4;
        temp_r3 = *(s32 *) &sp10 & 0x7F800000;
        if (temp_r3 == 0x7F800000) {
            if (*(s32 *) &sp10 & 0x7FFFFF) {
                var_r0 = 1;
            } else {
                var_r0 = 2;
            }
        } else if (temp_r3 == 0x0) {
            if (*(s32 *) &sp10 & 0x7FFFFF) {
                var_r0 = 5;
            } else {
                var_r0 = 3;
            }
        } else {
            var_r0 = 4;
        }
        if (var_r0 == 1) {
            var_f4 = __float_nan;
        }
    }
    temp_f0 = var_f4 < 0.0f ? -var_f4 : var_f4;
    temp_f0 = temp_f0 < 0.0f ? -temp_f0 : temp_f0;
    *(f32 *) (temp_r29 + (this->unk8 + 4)) = this->unk18 * temp_f0;
    temp_r3_586 = temp_r29 + this->unk8;
    M2C_FIELD(temp_r3_586, f32 *, 8) = this->unk20 * M2C_FIELD(temp_r3_586, f32 *, 4);
}

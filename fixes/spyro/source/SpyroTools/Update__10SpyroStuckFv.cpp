void SpyroStuck::Update() {
    s8 spA1;
    s8 spA0;
    s32 sp9C;
    f32 sp98;
    s32 sp94;
    s8 sp92;
    s8 sp91;
    s8 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 sp7C;
    s32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    s32 sp54;
    s32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp8;
    MKProp *temp_r3_1087;
    f32 var_f4_967;
    f64 temp_f1_970;
    f64 temp_f1_976;
    f64 temp_f1_980;
    s32 temp_r3_999;
    s32 var_r0_1009;
    void *temp_r3_941;

    temp_r3_941 = this->unk18->unk8;
    sp40 = M2C_FIELD(temp_r3_941, f64 *, 0x30);
    sp48 = M2C_FIELD(temp_r3_941, f64 *, 0x38);
    this->unk10 -= gUpdateTimeDelta;
    sp20 = sp40 - this->unk0;
    sp30 = sp20;
    sp28 = (f32) sp48 - this->unk8;
    sp38 = (f64) sp28;
    var_f4_967 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_967 > 0.0f) {
        temp_f1_970 = __frsqrte(var_f4_967);
        temp_f1_976 = 0.5 * temp_f1_970 * -(((f64) var_f4_967 * (temp_f1_970 * temp_f1_970)) - 3.0);
        temp_f1_980 = 0.5 * temp_f1_976 * -(((f64) var_f4_967 * (temp_f1_976 * temp_f1_976)) - 3.0);
        var_f4_967 = (f32) ((f64) var_f4_967 * (0.5 * temp_f1_980 * -(((f64) var_f4_967 * (temp_f1_980 * temp_f1_980)) - 3.0)));
    } else if (var_f4_967 < M2C_BITWISE(f32, 0.0)) {
        var_f4_967 = __float_nan;
    } else {
        sp8 = var_f4_967;
        temp_r3_999 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_999) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1009 = 1;
            } else {
                var_r0_1009 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1009 = 5;
            } else {
                var_r0_1009 = 3;
            }
            break;
        default:
            var_r0_1009 = 4;
            break;
        }
        if (var_r0_1009 == 1) {
            var_f4_967 = __float_nan;
        }
    }
    this->unk14 += var_f4_967;
    this->unk0 = sp40;
    M2C_FIELD(this, f32 *, 8) = sp48;
    if (this->unk10 <= 0.0f) {
        if (this->unk14 < 100.0f) {
            sp54 = 0;
            sp50 = 7;
            sp78 = 5;
            sp7C = 0;
            sp58 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            sp60 = M2C_FIELD(&MKVector3::up, f64 *, 8);
            sp90 = 1;
            sp9C = 0;
            sp98 = 0.0f;
            sp91 = 0;
            sp92 = 0;
            sp94 = -1;
            sp68 = M2C_FIELD(&MKVector3::one, f64 *, 0);
            sp70 = M2C_FIELD(&MKVector3::one, f64 *, 8);
            spA0 = 0;
            sp80 = 0.0f;
            sp84 = 0.0f;
            sp88 = 0.0f;
            spA1 = 0;
            temp_r3_1087 = this->unk18;
            temp_r3_1087->Message((MKMessage *) &sp50);
        }
        Reset();
    }
}

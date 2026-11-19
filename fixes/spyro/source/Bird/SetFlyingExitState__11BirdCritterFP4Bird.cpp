void BirdCritter::SetFlyingExitState(Bird *arg0) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f4_818;
    f32 var_f6_780;
    f64 temp_f1_823;
    f64 temp_f1_829;
    f64 temp_f1_833;
    s32 temp_r30_774;
    s32 temp_r3_852;
    s32 var_r0_862;
    BirdCritterDescriptor *temp_r3_descr;

    arg0->unk60 = 5;
    temp_r30_774 = arg0->unk60;
    var_f6_780 = 0.0f;
    temp_r3_descr = checked_cast<BirdCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    arg0->unk50 = M2C_FIELD(((u8 *) temp_r3_descr) + (temp_r30_774 * 4), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    sp10 = -arg0->unk20;
    sp14 = -arg0->unk24;
    sp18 = -arg0->unk28;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    (*(f32 *) ((u8 *) &sp38 + 0xc)) = 0.0f;
    var_f4_818 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (0.0f * 0.0f));
    if (var_f4_818 > 0.000001f) {
        if (var_f4_818 > 0.0f) {
            temp_f1_823 = __frsqrte(var_f4_818);
            temp_f1_829 = 0.5 * temp_f1_823 * -(((f64) var_f4_818 * (temp_f1_823 * temp_f1_823)) - 3.0);
            temp_f1_833 = 0.5 * temp_f1_829 * -(((f64) var_f4_818 * (temp_f1_829 * temp_f1_829)) - 3.0);
            var_f4_818 = (f32) ((f64) var_f4_818 * (0.5 * temp_f1_833 * -(((f64) var_f4_818 * (temp_f1_833 * temp_f1_833)) - 3.0)));
        } else if (var_f4_818 < M2C_BITWISE(f32, 0.0)) {
            var_f4_818 = __float_nan;
        } else {
            sp8 = var_f4_818;
            temp_r3_852 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_852) {
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_862 = 1;
                } else {
                    var_r0_862 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_862 = 5;
                } else {
                    var_r0_862 = 3;
                }
                break;
            default:
                var_r0_862 = 4;
                break;
            }
            if (var_r0_862 == 1) {
                var_f4_818 = __float_nan;
            }
        }
        var_f6_780 = 1.0f / var_f4_818;
    }
    sp40 = (f32) sp40 * var_f6_780;
    (*(f32 *) ((u8 *) &sp38 + 0xc)) *= var_f6_780;
    sp48 = (f32) sp48 * var_f6_780;
    sp30 = M2C_FIELD(arg0, f64 *, 0x30);
    sp38 = M2C_FIELD(arg0, f64 *, 0x38);
    sp20 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    sp28 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    KDMath_BuildMatrixFromFwd((Matrix *) arg0, *((MKVector3 *) &sp40), (MKVector3 *) &sp20);
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp30;
    arg0->unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
    arg0->unk38 = (f32) sp38;
    arg0->unk3C = 1.0f;
}

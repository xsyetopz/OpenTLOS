void EnergyBeam::ResetSafePositions(EnergyBeam::Beam *arg1) {
    f64 temp_f1_631;
    f64 temp_f1_637;
    f64 temp_f1_641;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sp8;
    f32 temp_f31_700;
    f32 var_f3_692;
    f32 var_f4_625;
    MKVector3 sp30;
    MKVector3 sp40;
    MKVector3 sp60;
    MKVector3 *temp_r3_604;
    MKVector3 *temp_r3_727;
    MKVector3 *temp_r4_603;
    s32 temp_r3_660;
    s32 var_r0_670;
    s32 var_r28_699;
    s32 var_r30_701;
    s8 *temp_r3_734;

    temp_r4_603 = (MKVector3 *) M2C_FIELD(arg1, void **, 0);
    temp_r3_604 = (MKVector3 *) M2C_FIELD(arg1, void **, 4);
    dx = temp_r3_604->unk0 - temp_r4_603->unk0;
    dy = temp_r3_604->unk4 - temp_r4_603->unk4;
    dz = temp_r3_604->unk8 - temp_r4_603->unk8;
    var_f4_625 = (dz * dz) + ((dx * dx) + (dy * dy));
    if (var_f4_625 > 0.000001f) {
        if (var_f4_625 > 0.0f) {
            temp_f1_631 = __frsqrte(var_f4_625);
            temp_f1_637 = 0.5 * temp_f1_631 * -(((f64) var_f4_625 * (temp_f1_631 * temp_f1_631)) - 3.0);
            temp_f1_641 = 0.5 * temp_f1_637 * -(((f64) var_f4_625 * (temp_f1_637 * temp_f1_637)) - 3.0);
            var_f4_625 = (f32) ((f64) var_f4_625 * (0.5 * temp_f1_641 * -(((f64) var_f4_625 * (temp_f1_641 * temp_f1_641)) - 3.0)));
        } else if (var_f4_625 < M2C_BITWISE(f32, 0.0)) {
            var_f4_625 = __float_nan;
        } else {
            sp8 = var_f4_625;
            temp_r3_660 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_660) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_670 = 1;
                } else {
                    var_r0_670 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_670 = 5;
                } else {
                    var_r0_670 = 3;
                }
                break;
            default:
                var_r0_670 = 4;
                break;
            }
            if (var_r0_670 == 1) {
                var_f4_625 = __float_nan;
            }
        }
        var_f3_692 = 1.0f / var_f4_625;
    } else {
        var_f3_692 = 0.0f;
        var_f4_625 = 0.0f;
    }
    var_r28_699 = 0;
    var_r30_701 = 0;
    dx = dx * var_f3_692;
    dy = dy * var_f3_692;
    dz = dz * var_f3_692;
    sp60.unk0 = dx;
    sp60.unk4 = dy;
    sp60.unk8 = dz;
    M2C_FIELD(arg1, f32 *, 8) = var_f4_625;
    temp_f31_700 = var_f4_625 / 7.0f;
    do {
        sp30 = sp60.operator*(temp_f31_700);
        sp40 = sp30.operator*((f32) var_r28_699);
        temp_r3_727 = (MKVector3 *) M2C_FIELD(arg1, void **, 0);
        temp_r3_734 = (s8 *) arg1 + var_r30_701 + 0x40;
        var_r28_699 += 1;
        var_r30_701 += 0x50;
        M2C_FIELD(temp_r3_734, f32 *, 0x0) = temp_r3_727->unk0 + sp40.unk0;
        M2C_FIELD(temp_r3_734, f32 *, 0x4) = temp_r3_727->unk4 + sp40.unk4;
        M2C_FIELD(temp_r3_734, f32 *, 0x8) = temp_r3_727->unk8 + sp40.unk8;
    } while (var_r28_699 < 8);
}

#include "common/Source/MKVector3.h"
#include <m2c_macros.h>

static MKVector3 zero__9MKVector3 = { 0.0f, 0.0f, 0.0f, 0.0f };

#if 0 // DRAFT: pointer/array required
void Max(const MKVector3 &arg0, const MKVector3 &arg1) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_12;
    f32 temp_f2_21;
    f32 temp_f2_30;
    f32 var_f0_11;
    f32 var_f0_29;
    f32 var_f1_20;

    var_f0_11 = arg1.unk0;
    temp_f1_12 = *M2C_ERROR(/* Read from unset register $r5 */);
    if (var_f0_11 > temp_f1_12) {

    } else {
        var_f0_11 = temp_f1_12;
    }
    var_f1_20 = arg1.unk4;
    temp_f2_21 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4);
    sp8 = var_f0_11;
    if (var_f1_20 > temp_f2_21) {

    } else {
        var_f1_20 = temp_f2_21;
    }
    var_f0_29 = arg1.unk8;
    temp_f2_30 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8);
    spC = var_f1_20;
    if (var_f0_29 > temp_f2_30) {

    } else {
        var_f0_29 = temp_f2_30;
    }
    sp10 = var_f0_29;
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: pointer/array required
void Min(const MKVector3 &arg0, const MKVector3 &arg1) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_51;
    f32 temp_f2_60;
    f32 temp_f2_69;
    f32 var_f0_50;
    f32 var_f0_68;
    f32 var_f1_59;

    var_f0_50 = arg1.unk0;
    temp_f1_51 = *M2C_ERROR(/* Read from unset register $r5 */);
    if (var_f0_50 < temp_f1_51) {

    } else {
        var_f0_50 = temp_f1_51;
    }
    var_f1_59 = arg1.unk4;
    temp_f2_60 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4);
    sp8 = var_f0_50;
    if (var_f1_59 < temp_f2_60) {

    } else {
        var_f1_59 = temp_f2_60;
    }
    var_f0_68 = arg1.unk8;
    temp_f2_69 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8);
    spC = var_f1_59;
    if (var_f0_68 < temp_f2_69) {

    } else {
        var_f0_68 = temp_f2_69;
    }
    sp10 = var_f0_68;
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void MKVector3_cpp::__sinit() {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 0.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    sp60 = 1.0f;
    sp64 = 1.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp28 = 1.0f;
    sp2C = 1.0f;
    sp30 = 1.0f;
    sp34 = 1.0f;
    sp18 = 0.0f;
    sp1C = 1.0f;
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    M2C_FIELD(&zero, f64 *, 0) = (f64) sp68;
    M2C_FIELD(&zero, f64 *, 8) = (f64) sp70;
    M2C_FIELD(&zero, f64 *, 0x10) = (f64) sp58;
    M2C_FIELD(&zero, f64 *, 0x18) = (f64) sp60;
    M2C_FIELD(&zero, f64 *, 0x20) = (f64) sp48;
    M2C_FIELD(&zero, f64 *, 0x28) = (f64) sp50;
    M2C_FIELD(&zero, f64 *, 0x30) = (f64) sp38;
    M2C_FIELD(&zero, f64 *, 0x38) = (f64) sp40;
    M2C_FIELD(&zero, f64 *, 0x40) = (f64) sp28;
    M2C_FIELD(&zero, f64 *, 0x48) = (f64) sp30;
    M2C_FIELD(&zero, f64 *, 0x50) = (f64) sp18;
    M2C_FIELD(&zero, f64 *, 0x58) = (f64) sp20;
    M2C_FIELD(&zero, f64 *, 0x60) = (f64) sp8;
    M2C_FIELD(&zero, f64 *, 0x68) = (f64) sp10;
}
#endif

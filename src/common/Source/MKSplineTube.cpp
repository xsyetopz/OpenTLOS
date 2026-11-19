#include "common/Source/MKSplineTube.h"
#include <m2c_macros.h>

f64 log(f64);                                       /* extern */
f64 pow(f32, f32);                                  /* extern */
extern f32 distScale;
#if 0 // DRAFT: identifier 'spacing' redeclared
extern M2C_UNK spacing;
#endif
#if 0 // DRAFT: identifier 'posMixer' redeclared
static M2C_UNK posMixer;                            /* unable to generate initializer: unknown type */
static M2C_UNK velMixer;                            /* unable to generate initializer: unknown type */

void MKSplineTube_InitModule(float arg0, float arg1, float arg2) {
    f32 temp_f28_38;
    f32 temp_f29_39;
    f32 temp_f30_36;
    f32 temp_f30_53;
    f32 temp_f31_30;
    f32 var_f0_66;
    s32 var_r28_50;
    s32 var_r31_51;

    temp_f31_30 = (f32) log(2.0);
    temp_f30_36 = arg0 * arg0;
    temp_f28_38 = 1.0f / arg1;
    temp_f29_39 = (0.5f * (f32) log(M2C_BITWISE(f64, arg2))) / temp_f31_30;
    var_r28_50 = 0;
    var_r31_51 = 0;
    temp_f30_53 = 1.0f / (f32) pow(temp_f30_36, temp_f29_39);
    distScale = 127.0f / temp_f30_36;
    do {
        var_f0_66 = temp_f30_53 * (f32) pow((f32) var_r28_50 / distScale, temp_f29_39);
        if (var_f0_66 > temp_f28_38) {

        } else {
            var_f0_66 = temp_f28_38;
        }
        var_r28_50 += 1;
        *(&spacing + var_r31_51) = var_f0_66;
        var_r31_51 += 4;
    } while (var_r28_50 < 0x80);
}
#endif

void MKSplineTube_cpp::__sinit() {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
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

    sp78 = 1.0f;
    sp7C = 2.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp80 = -2.0f;
    sp84 = 1.0f;
    sp68 = -2.0f;
    sp6C = -3.0f;
    M2C_FIELD(&posMixer, f64 *, 0) = (f64) sp78;
    sp70 = 3.0f;
    sp74 = -1.0f;
    sp58 = 1.0f;
    sp5C = 0.0f;
    sp60 = 0.0f;
    sp64 = 0.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp28 = 3.0f;
    sp2C = 6.0f;
    M2C_FIELD(&velMixer, f64 *, 0) = (f64) sp38;
    sp30 = -6.0f;
    sp34 = 3.0f;
    sp18 = -4.0f;
    sp1C = -6.0f;
    sp20 = 6.0f;
    sp24 = -2.0f;
    sp8 = 1.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    M2C_FIELD(&posMixer, f64 *, 8) = (f64) sp80;
    M2C_FIELD(&posMixer, f64 *, 0x10) = (f64) sp68;
    M2C_FIELD(&posMixer, f64 *, 0x18) = (f64) sp70;
    M2C_FIELD(&posMixer, f64 *, 0x20) = (f64) sp58;
    M2C_FIELD(&posMixer, f64 *, 0x28) = (f64) sp60;
    M2C_FIELD(&posMixer, f64 *, 0x30) = (f64) sp48;
    M2C_FIELD(&posMixer, f64 *, 0x38) = (f64) sp50;
    M2C_FIELD(&velMixer, f64 *, 8) = (f64) sp40;
    M2C_FIELD(&velMixer, f64 *, 0x10) = (f64) sp28;
    M2C_FIELD(&velMixer, f64 *, 0x18) = (f64) sp30;
    M2C_FIELD(&velMixer, f64 *, 0x20) = (f64) sp18;
    M2C_FIELD(&velMixer, f64 *, 0x28) = (f64) sp20;
    M2C_FIELD(&velMixer, f64 *, 0x30) = (f64) sp8;
    M2C_FIELD(&velMixer, f64 *, 0x38) = (f64) sp10;
}

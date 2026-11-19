#include "common/Source/MKShockWave_MP.h"
#include "unplaced_enums.h"
#include "common/Source/MKSystem.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'gShockWaveData' redeclared
extern M2C_UNK gShockWaveData;
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
f32 MKShockWave_Height(const MKVector3 &arg0) {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_121;
    f32 var_f1_124;
    f32 var_f30_26;
    f32 var_f31_50;
    f64 temp_f0_34;
    f64 temp_f1_53;
    f64 temp_f1_59;
    f64 temp_f1_63;
    s32 temp_r3_82;
    s32 var_r0_92;
    s32 var_r28_117;
    s32 var_r31_118;
    void *temp_r29_120;

    var_f30_26 = 0.0f;
    if ((u8) M2C_FIELD(&gShockWaveData, u8 *, 0x60) != 0) {
        temp_f0_34 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(&gShockWaveData, f64 *, 0x50);
        sp10 = temp_f0_34;
        sp20 = temp_f0_34;
        sp18 = arg0.unk8 - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
        sp28 = (f64) sp18;
        var_f31_50 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
        if (var_f31_50 > 0.0f) {
            temp_f1_53 = __frsqrte(var_f31_50);
            temp_f1_59 = 0.5 * temp_f1_53 * -(((f64) var_f31_50 * (temp_f1_53 * temp_f1_53)) - 3.0);
            temp_f1_63 = 0.5 * temp_f1_59 * -(((f64) var_f31_50 * (temp_f1_59 * temp_f1_59)) - 3.0);
            var_f31_50 = (f32) ((f64) var_f31_50 * (0.5 * temp_f1_63 * -(((f64) var_f31_50 * (temp_f1_63 * temp_f1_63)) - 3.0)));
        } else if (var_f31_50 < M2C_BITWISE(f32, 0.0)) {
            var_f31_50 = __float_nan;
        } else {
            sp8 = var_f31_50;
            temp_r3_82 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_82) {                   /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_92 = 1;
                } else {
                    var_r0_92 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_92 = 5;
                } else {
                    var_r0_92 = 3;
                }
                break;
            default:
                var_r0_92 = 4;
                break;
            }
            if (var_r0_92 == 1) {
                var_f31_50 = __float_nan;
            }
        }
        var_r28_117 = 0;
        var_r31_118 = 0;
        do {
            temp_r29_120 = &gShockWaveData + var_r31_118;
            temp_f2_121 = M2C_FIELD(temp_r29_120, f32 *, 0x10);
            var_f1_124 = var_f31_50 - -((0.5f * temp_f2_121) - M2C_FIELD(temp_r29_120, f32 *, 0));
            if (var_f1_124 < temp_f2_121) {

            } else {
                var_f1_124 = temp_f2_121;
            }
            if (var_f1_124 > 0.0f) {

            } else {
                var_f1_124 = 0.0f;
            }
            if ((var_f1_124 > 0.0f) && (var_f1_124 < temp_f2_121)) {
                var_f30_26 += M2C_FIELD(temp_r29_120, f32 *, 0x40) * _table_sinf(var_f1_124 * M2C_FIELD(temp_r29_120, f32 *, 0x30));
            }
            var_r28_117 += 1;
            var_r31_118 += 4;
        } while (var_r28_117 < 4);
    }
    return var_f30_26;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
u32 MKShockWave_IsWithin(const MKVector3 &arg0, float arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_181;

    if ((u8) M2C_FIELD(&gShockWaveData, u8 *, 0x60) != 0) {
        temp_f0_181 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(&gShockWaveData, f64 *, 0x50);
        sp8 = temp_f0_181;
        sp18 = temp_f0_181;
        sp10 = arg0.unk8 - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
        sp20 = (f64) sp10;
        return (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
    }
    return 0U;
}
#endif

void MKShockWave_Disable() {
    M2C_FIELD(&gShockWaveData, s8 *, 0x60) = 0;
}

#if 0 // DRAFT: illegal operand
void MKShockWave_Set(int arg0, float arg1, float arg2, float arg3) {
    f32 temp_f2_264;
    f32 temp_f2_273;
    f32 var_f0_229;
    f32 var_f0_263;
    f32 var_f0_272;
    s32 temp_r5_232;
    s32 var_ctr_257;
    s32 var_r3_254;
    void *temp_r4_236;
    void *temp_r5_259;

    var_f0_229 = 0.0f;
    temp_r5_232 = arg0 * 4;
    *(&gShockWaveData + temp_r5_232) = arg1;
    temp_r4_236 = &gShockWaveData + temp_r5_232;
    M2C_FIELD(temp_r4_236, f32 *, 0x10) = arg2;
    M2C_FIELD(temp_r4_236, f32 *, 0x20) = (f32) -((0.5f * M2C_FIELD(temp_r4_236, f32 *, 0x10)) - *(&gShockWaveData + temp_r5_232));
    M2C_FIELD(temp_r4_236, f32 *, 0x40) = arg3;
    if (arg2 != 0.0f) {
        var_f0_229 = 3.1415927f / arg2;
    }
    M2C_FIELD((&gShockWaveData + temp_r5_232), f32 *, 0x30) = var_f0_229;
    var_r3_254 = 0;
    M2C_FIELD(&gShockWaveData, f32 *, 0x68) = 0.0f;
    M2C_FIELD(&gShockWaveData, f32 *, 0x64) = 0.0f;
    var_ctr_257 = 4;
    do {
        temp_r5_259 = &gShockWaveData + var_r3_254;
        if (M2C_FIELD(temp_r5_259, f32 *, 0x40) != 0.0f) {
            var_f0_263 = M2C_FIELD(&gShockWaveData, f32 *, 0x64);
            temp_f2_264 = M2C_FIELD(temp_r5_259, f32 *, 0);
            if (var_f0_263 > temp_f2_264) {

            } else {
                var_f0_263 = temp_f2_264;
            }
            M2C_FIELD(&gShockWaveData, f32 *, 0x64) = var_f0_263;
            var_f0_272 = M2C_FIELD(&gShockWaveData, f32 *, 0x68);
            temp_f2_273 = M2C_FIELD(temp_r5_259, f32 *, 0x10);
            if (var_f0_272 > temp_f2_273) {

            } else {
                var_f0_272 = temp_f2_273;
            }
            M2C_FIELD(&gShockWaveData, f32 *, 0x68) = var_f0_272;
        }
        var_r3_254 += 4;
        var_ctr_257 -= 1;
    } while (var_ctr_257 != 0);
    MKDirtyState_Dirty((MKDirtyStateType) 6);
}
#endif

void MKShockWave_Enable(const MKVector3 &arg0) {
    M2C_FIELD(&gShockWaveData, f64 *, 0x50) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(&gShockWaveData, f64 *, 0x58) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    memset(&gShockWaveData + 0x40, 0, 0x10U);
    M2C_FIELD(&gShockWaveData, f32 *, 0x68) = 0.0f;
    M2C_FIELD(&gShockWaveData, f32 *, 0x64) = 0.0f;
    M2C_FIELD(&gShockWaveData, s8 *, 0x60) = 1;
    MKDirtyState_Dirty((MKDirtyStateType) 6);
}

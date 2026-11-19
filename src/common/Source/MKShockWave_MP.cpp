#include "common/Source/MKShockWave_MP.h"
#include "unplaced_enums.h"
#include "common/Source/MKSystem.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'gShockWaveData' redeclared was declared as: 'unsigned char[112]' now declared as: 'long'
extern M2C_UNK gShockWaveData;
#endif

f32 MKShockWave_Height(const MKVector3 &arg0) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sumsq;
    f32 len;
    f32 clamped;
    f32 radius;
    f32 accum;
    f64 x;
    f64 r;
    s32 i;
    s32 off;
    u8 *q;

    accum = 0.0f;
    if (M2C_FIELD(&gShockWaveData, u8 *, 0x60) == 0) {
        return accum;
    }
    dx = M2C_FIELD(&arg0, f32 *, 0x0) - M2C_FIELD(&gShockWaveData, f32 *, 0x50);
    dy = M2C_FIELD(&arg0, f32 *, 0x4) - M2C_FIELD(&gShockWaveData, f32 *, 0x54);
    dz = M2C_FIELD(&arg0, f32 *, 0x8) - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
    sumsq = dz * dz + (dx * dx + dy * dy);
    if (sumsq > 0.0f) {
        x = (f64) sumsq;
        r = __frsqrte(x);
        r = 0.5 * r * (3.0 - x * (r * r));
        r = 0.5 * r * (3.0 - x * (r * r));
        r = 0.5 * r * (3.0 - x * (r * r));
        len = (f32) (x * r);
    } else if (sumsq == 0.0f) {
        len = sumsq;
    } else {
        len = __float_nan;
    }
    for (i = 0, off = 0; i < 4; i++, off += 4) {
        q = (u8 *) &gShockWaveData + off;
        radius = M2C_FIELD(q, f32 *, 0x10);
        clamped = len - (M2C_FIELD(q, f32 *, 0x0) - 0.5f * radius);
        if (!(clamped < radius)) {
            clamped = radius;
        }
        if (!(clamped > 0.0f)) {
            clamped = 0.0f;
        }
        if ((clamped > 0.0f) && (clamped < radius)) {
            clamped = clamped * M2C_FIELD(q, f32 *, 0x30);
            clamped = _table_sinf(clamped);
            accum = M2C_FIELD(q, f32 *, 0x40) * clamped + accum;
        }
    }
    return accum;
}

u32 MKShockWave_IsWithin(const MKVector3 &arg0, float arg1) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 reach;

    if (M2C_FIELD(&gShockWaveData, u8 *, 0x60) == 0) {
        return 0U;
    }
    dx = M2C_FIELD(&arg0, f32 *, 0x0) - M2C_FIELD(&gShockWaveData, f32 *, 0x50);
    dy = M2C_FIELD(&arg0, f32 *, 0x4) - M2C_FIELD(&gShockWaveData, f32 *, 0x54);
    dz = M2C_FIELD(&arg0, f32 *, 0x8) - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
    reach = arg1 + (M2C_FIELD(&gShockWaveData, f32 *, 0x64) + M2C_FIELD(&gShockWaveData, f32 *, 0x68));
    return (u32) ((dz * dz + (dx * dx + dy * dy)) < (reach * reach));
}

void MKShockWave_Disable() {
    M2C_FIELD(&gShockWaveData, s8 *, 0x60) = 0;
}

void MKShockWave_Set(int arg0, float arg1, float arg2, float arg3) {
    f32 var_f0_229;
    s32 off;
    s32 var_r3_254;
    u8 *p;
    u8 *q;

    var_f0_229 = 0.0f;
    off = arg0 * 4;
    p = (u8 *) &gShockWaveData + off;
    M2C_FIELD(p, f32 *, 0x0) = arg1;
    M2C_FIELD(p, f32 *, 0x10) = arg2;
    M2C_FIELD(p, f32 *, 0x20) = arg1 - (0.5f * M2C_FIELD(p, f32 *, 0x10));
    M2C_FIELD(p, f32 *, 0x40) = arg3;
    if (arg2 != 0.0f) {
        var_f0_229 = 3.1415927f / arg2;
    }
    M2C_FIELD(p, f32 *, 0x30) = var_f0_229;
    M2C_FIELD(&gShockWaveData, f32 *, 0x68) = 0.0f;
    M2C_FIELD(&gShockWaveData, f32 *, 0x64) = 0.0f;
    for (var_r3_254 = 0; var_r3_254 < 0x10; var_r3_254 += 4) {
        q = (u8 *) &gShockWaveData + var_r3_254;
        if (M2C_FIELD(q, f32 *, 0x40) != 0.0f) {
            f32 max_r;
            f32 max_h;

            max_r = M2C_FIELD(&gShockWaveData, f32 *, 0x64);
            if (!(max_r > M2C_FIELD(q, f32 *, 0x0))) {
                max_r = M2C_FIELD(q, f32 *, 0x0);
            }
            M2C_FIELD(&gShockWaveData, f32 *, 0x64) = max_r;
            max_h = M2C_FIELD(&gShockWaveData, f32 *, 0x68);
            if (!(max_h > M2C_FIELD(q, f32 *, 0x10))) {
                max_h = M2C_FIELD(q, f32 *, 0x10);
            }
            M2C_FIELD(&gShockWaveData, f32 *, 0x68) = max_h;
        }
    }
    MKDirtyState_Dirty((MKDirtyStateType) 6);
}

void MKShockWave_Enable(const MKVector3 &arg0) {
    M2C_FIELD(&gShockWaveData, f64 *, 0x50) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(&gShockWaveData, f64 *, 0x58) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    memset(&gShockWaveData + 0x40, 0, 0x10U);
    M2C_FIELD(&gShockWaveData, f32 *, 0x68) = 0.0f;
    M2C_FIELD(&gShockWaveData, f32 *, 0x64) = 0.0f;
    M2C_FIELD(&gShockWaveData, s8 *, 0x60) = 1;
    MKDirtyState_Dirty((MKDirtyStateType) 6);
}

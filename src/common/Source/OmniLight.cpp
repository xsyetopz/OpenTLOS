#include "common/Source/OmniLight.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "common/Source/MKView.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(M2C_UNK);                           /* extern */
extern u8 bSuspendAll;
extern M2C_UNK gEmptyPtrListDL;
extern M2C_UNK *lightList;

void OmniLight::CalculateColor(const MKVector3 &arg0, const MKVector3 &arg1) {
    extern f32 __float_nan;
    const MKVector3 *arg2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist2;
    f32 atten;
    f32 inv;
    f32 dot;
    f32 scale;
    f32 tmp;
    s32 bits;
    s32 cls;

    dx = arg1.unk0 - M2C_FIELD(&arg0, f32 *, 0x10);
    dy = arg1.unk4 - M2C_FIELD(&arg0, f32 *, 0x14);
    dz = arg1.unk8 - M2C_FIELD(&arg0, f32 *, 0x18);
    dist2 = (dz * dz) + ((dx * dx) + (dy * dy));
    atten = dist2 / M2C_FIELD(&arg0, f32 *, 0x24);
    if (atten < 1.0f) {
    } else {
        atten = 1.0f;
    }
    if (atten > 0.0f) {
    } else {
        atten = 0.0f;
    }
    if (dist2 > 0.000001f) {
        if (dist2 > 0.0f) {
            f64 y0;
            f64 y1;
            f64 y2;

            y0 = __frsqrte(dist2);
            y1 = 0.5 * y0 * -(((f64) dist2 * (y0 * y0)) - 3.0);
            y2 = 0.5 * y1 * -(((f64) dist2 * (y1 * y1)) - 3.0);
            dist2 = (f32) ((f64) dist2 * (0.5 * y2 * -(((f64) dist2 * (y2 * y2)) - 3.0)));
        } else if (dist2 < 0.0f) {
            dist2 = __float_nan;
        } else {
            tmp = dist2;
            bits = *(s32 *) &tmp;
            switch (bits & 0x7F800000) {
            case 0x7F800000:
                if (bits & 0x7FFFFF) {
                    cls = 1;
                } else {
                    cls = 2;
                }
                break;
            case 0x0:
                if (bits & 0x7FFFFF) {
                    cls = 5;
                } else {
                    cls = 3;
                }
                break;
            default:
                cls = 4;
                break;
            }
            if (cls == 1) {
                dist2 = __float_nan;
            }
        }
        inv = 1.0f / dist2;
    } else {
        inv = 0.0f;
    }

    dx = dx * inv;
    dy = dy * inv;
    dz = dz * inv;

    /* r6 is live-in in the asm: no instruction in this function sets it. */
    dot = (dz * M2C_FIELD(arg2, f32 *, 8)) + ((dx * M2C_FIELD(arg2, f32 *, 0)) + (dy * M2C_FIELD(arg2, f32 *, 4)));
    if (dot < 0.0f) {
        dot = -dot;
    }
    scale = (1.0f - atten) * dot;

    M2C_FIELD(this, f32 *, 0x0) = M2C_FIELD(&arg0, f32 *, 0x0) * scale;
    M2C_FIELD(this, f32 *, 0x4) = M2C_FIELD(&arg0, f32 *, 0x4) * scale;
    M2C_FIELD(this, f32 *, 0x8) = M2C_FIELD(&arg0, f32 *, 0x8) * scale;
    M2C_FIELD(this, f32 *, 0xC) = 1.0f;
}

s32 OmniLight_FindNearestGroup(const MKVector3 &arg0, float arg1, OmniLight **arg2, int arg3) {
    M2C_UNK spDC;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    M2C_UNK *temp_r3_202;
    M2C_UNK *temp_r5_222;
    M2C_UNK *temp_r7_279;
    M2C_UNK *var_r8_186;
    f32 temp_f0_207;
    f32 temp_f0_256;
    f32 temp_f1_257;
    f64 temp_f0_225;
    s32 *temp_r7_262;
    s32 temp_r4_264;
    s32 temp_r9_231;
    s32 var_ctr_250;
    s32 var_ctr_284;
    s32 var_r27_180;
    s32 var_r31_179;
    s32 var_r3_249;
    s32 var_r3_283;
    void *temp_r5_255;
    void *temp_r6_187;

    var_r31_179 = 0;
    var_r27_180 = 0;
    if (((u8) bSuspendAll == 0) && ((s32) *OmniLight::totalEnabled != 0)) {
        var_r8_186 = lightList;
        temp_r6_187 = MKView_GetCameraMatrix() + 0x30;
loop_11:
        temp_r7_279 = (long *) (*var_r8_186);
        if (temp_r7_279 != NULL) {
            if ((u8) M2C_FIELD(temp_r7_279, u8 *, 0x30) != 0) {
                sp8 = M2C_FIELD(&arg0, f64 *, 0) - *(temp_r7_279 + 0x10);
                temp_r3_202 = (long *) (*var_r8_186);
                sp48 = sp8;
                sp10 = arg0.unk8 - M2C_FIELD(temp_r7_279, f32 *, 0x18);
                temp_f0_207 = arg1 + M2C_FIELD(temp_r3_202, f32 *, 0x20);
                sp50 = (f64) sp10;
                sp38 = sp8;
                sp40 = (f64) sp10;
                if ((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4))))) < (temp_f0_207 * temp_f0_207)) {
                    temp_r5_222 = temp_r3_202 + 0x10;
                    temp_f0_225 = M2C_FIELD(temp_r6_187, f64 *, 0) - M2C_FIELD(temp_r5_222, f64 *, 0);
                    sp18 = temp_f0_225;
                    temp_r9_231 = var_r31_179 - 1;
                    *(&sp58 + var_r27_180) = (long) (temp_r7_279);
                    sp28 = temp_f0_225;
                    sp20 = M2C_FIELD(temp_r6_187, f32 *, 8) - M2C_FIELD(temp_r5_222, f32 *, 8);
                    sp30 = (f64) sp20;
                    *(&spDC + var_r27_180) = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4))));
                    var_r3_249 = temp_r9_231 * 4;
                    var_ctr_250 = temp_r9_231 + 1;
                    if (temp_r9_231 >= 0) {
loop_6:
                        temp_r5_255 = &spDC + var_r3_249;
                        temp_f0_256 = M2C_FIELD(temp_r5_255, f32 *, 0);
                        temp_f1_257 = M2C_FIELD(temp_r5_255, f32 *, 4);
                        if (temp_f0_256 > temp_f1_257) {
                            M2C_FIELD(temp_r5_255, f32 *, 0) = temp_f1_257;
                            temp_r7_262 = &sp58 + var_r3_249;
                            temp_r4_264 = M2C_FIELD(temp_r7_262, s32 *, 0);
                            var_r3_249 -= 4;
                            M2C_FIELD(temp_r5_255, f32 *, 4) = temp_f0_256;
                            M2C_FIELD(temp_r7_262, s32 *, 0) = M2C_FIELD(temp_r7_262, s32 *, 4);
                            M2C_FIELD(temp_r7_262, s32 *, 4) = temp_r4_264;
                            var_ctr_250 -= 1;
                            if (var_ctr_250 != 0) {
                                goto loop_6;
                            }
                        }
                    }
                    if (var_r31_179 < arg3) {
                        var_r31_179 += 1;
                        var_r27_180 += 4;
                    }
                }
            }
            var_r8_186 += 4;
            goto loop_11;
        }
        var_r3_283 = 0;
        var_ctr_284 = var_r31_179;
        if (var_r31_179 > 0) {
            do {
                *(arg2 + var_r3_283) = (OmniLight *) (*(&sp58 + var_r3_283));
                var_r3_283 += 4;
                var_ctr_284 -= 1;
            } while (var_ctr_284 != 0);
        }
    }
    return var_r31_179;
}

void OmniLight_FindNearest(const MKVector3 &arg0, float arg1) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    M2C_UNK *temp_r3_330;
    M2C_UNK *temp_r3_339;
    M2C_UNK *temp_r3_359;
    M2C_UNK *temp_r3_390;
    M2C_UNK *var_r31_315;
    M2C_UNK *var_r5_324;
    f32 temp_f1_344;
    f32 temp_f1_380;
    f32 var_f0_322;
    f64 temp_f1_362;
    void *temp_r4_323;

    var_r31_315 = NULL;
    if (((u8) bSuspendAll == 0) && ((s32) *OmniLight::totalEnabled != 0)) {
        var_f0_322 = 0.0f;
        temp_r4_323 = MKView_GetCameraMatrix() + 0x30;
        var_r5_324 = lightList;
loop_9:
        temp_r3_390 = (long *) (*var_r5_324);
        if (temp_r3_390 != NULL) {
            if ((u8) M2C_FIELD(temp_r3_390, u8 *, 0x30) != 0) {
                temp_r3_330 = temp_r3_390 + 0x10;
                sp8 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r3_330, f64 *, 0);
                temp_r3_339 = (long *) (*var_r5_324);
                sp48 = sp8;
                sp10 = arg0.unk8 - M2C_FIELD(temp_r3_330, f32 *, 8);
                temp_f1_344 = arg1 + M2C_FIELD(temp_r3_339, f32 *, 0x20);
                sp50 = (f64) sp10;
                sp38 = sp8;
                sp40 = (f64) sp10;
                if (((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4))))) < (temp_f1_344 * temp_f1_344)) && ((temp_r3_359 = temp_r3_339 + 0x10, temp_f1_362 = M2C_FIELD(temp_r4_323, f64 *, 0) - M2C_FIELD(temp_r3_359, f64 *, 0), sp18 = temp_f1_362, sp28 = temp_f1_362, sp20 = M2C_FIELD(temp_r4_323, f32 *, 8) - M2C_FIELD(temp_r3_359, f32 *, 8), sp30 = (f64) sp20, temp_f1_380 = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4)))), ((var_r31_315 == NULL) != 0)) || (temp_f1_380 < var_f0_322))) {
                    var_r31_315 = (long *) (*var_r5_324);
                    var_f0_322 = temp_f1_380;
                }
            }
            var_r5_324 += 4;
            goto loop_9;
        }
    }
}

u8 OmniLight_SuspendAll(bool arg0) {
    u8 temp_r0_407;

    temp_r0_407 = bSuspendAll;
    bSuspendAll = arg0;
    return temp_r0_407;
}

void OmniLight_Destroy(OmniLight *arg0) {
    s32 *var_r4;
    s32 *temp_r3;
    s32 temp_r5;

    if ((u8) arg0->unk30 != 0) {
        arg0->unk30 = 0;
        *(s32 *) OmniLight::totalEnabled -= 1;
    }
    var_r4 = (s32 *) lightList;
    while (*var_r4 != 0) {
        if (*var_r4 == (s32) arg0) {
            temp_r3 = (s32 *) lightList;
            lightList = (M2C_UNK *) ((u8 *) temp_r3 + 4);
            temp_r5 = *temp_r3;
            *temp_r3 = *var_r4;
            *var_r4 = temp_r5;
            return;
        }
        var_r4 = (s32 *) ((u8 *) var_r4 + 4);
    }
}

void OmniLight_Create() {
    M2C_UNK *temp_r31_457;
    M2C_UNK *temp_r3_455;

    temp_r3_455 = lightList - 4;
    lightList = temp_r3_455;
    temp_r31_457 = (long *) (*temp_r3_455);
    if (temp_r31_457 != NULL) {
        memset(temp_r31_457, 0, 0x38U);
    }
}

void OmniLight_DeinitModule() {
    M2C_UNK *temp_r0_485;
    M2C_UNK *temp_r0_504;
    M2C_UNK *var_r31_481;
    M2C_UNK *var_r3_482;
    M2C_UNK *var_r4_480;
    u32 temp_r0_490;

    var_r4_480 = lightList;
    var_r31_481 = var_r4_480;
    var_r3_482 = var_r4_480;
loop_3:
    temp_r0_490 = M2C_FIELD(var_r3_482, u32 *, -4);
    var_r3_482 -= 4;
    if (temp_r0_490 != 0U) {
        temp_r0_485 = (long *) (*var_r3_482);
        if (temp_r0_485 < var_r31_481) {
            var_r31_481 = temp_r0_485;
        }
        goto loop_3;
    }
    if (var_r3_482 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_504 = (long *) (*var_r4_480);
        if (temp_r0_504 != NULL) {
            if (temp_r0_504 < var_r31_481) {
                var_r31_481 = temp_r0_504;
            }
            var_r4_480 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_481, NULL, 0);
        } else {
            free(var_r31_481);
        }
    }
    lightList = NULL;
}

void OmniLight_InitModule() {
    M2C_UNK *var_r3_542;
    s32 var_ctr_554;

    if (MKHeap::Current() != NULL) {
        var_r3_542 = (long *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x788, NULL, 0));
    } else {
        var_r3_542 = malloc(0x788);
    }
    lightList = var_r3_542;
    lightList = var_r3_542 + 0x700;
    M2C_FIELD(var_r3_542, s32 *, 0x700) = 0;
    var_ctr_554 = 0x20;
    do {
        lightList += 4;
        M2C_FIELD(lightList, M2C_UNK **, 4) = var_r3_542;
        var_r3_542 += 0x38;
        var_ctr_554 -= 1;
    } while (var_ctr_554 != 0);
    lightList += 4;
    M2C_FIELD(lightList, M2C_UNK **, 4) = NULL;
}

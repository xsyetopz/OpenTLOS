#include "spyro/source/EventCamera.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Hud.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

f64 atan(f32);                                      /* extern */
f64 atof(s32);                                      /* extern */
extern s8 EventCamera_bRemainTargetable;
extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
extern EventCamera *pCurrentCamera;
extern EventCamera *pPeviousCamera;
static M2C_UNK cameraPos;
static M2C_UNK InitialCameraPos;
static MKVector3 cameraDir;

#if 0 // DRAFT: undefined identifier 'sp28'
static s8 lit_stringBase0[0x261] = {
    0x74,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0x49,
    0x44,
    0,
    0x62,
    0x55,
    0x73,
    0x65,
    0x50,
    0x72,
    0x6F,
    0x70,
    0x47,
    0x72,
    0x6F,
    0x75,
    0x70,
    0x56,
    0x6F,
    0x6C,
    0x75,
    0x6D,
    0x65,
    0x73,
    0,
    0x53,
    0x68,
    0x6F,
    0x77,
    0x53,
    0x70,
    0x79,
    0x72,
    0x6F,
    0,
    0x4D,
    0x61,
    0x70,
    0x53,
    0x70,
    0x6C,
    0x69,
    0x6E,
    0x65,
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x54,
    0x6F,
    0x43,
    0x75,
    0x72,
    0x72,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0,
    0x4D,
    0x61,
    0x70,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0x53,
    0x70,
    0x6C,
    0x69,
    0x6E,
    0x65,
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x54,
    0x6F,
    0x43,
    0x75,
    0x72,
    0x72,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0x44,
    0x69,
    0x72,
    0,
    0x46,
    0x61,
    0x64,
    0x65,
    0x54,
    0x6F,
    0x42,
    0x6C,
    0x61,
    0x63,
    0x6B,
    0,
    0x48,
    0x6F,
    0x6C,
    0x64,
    0x46,
    0x61,
    0x64,
    0x65,
    0x54,
    0x6F,
    0x42,
    0x6C,
    0x61,
    0x63,
    0x6B,
    0,
    0x46,
    0x6F,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0x53,
    0x70,
    0x6C,
    0x69,
    0x6E,
    0x65,
    0x49,
    0x44,
    0,
    0x46,
    0x6F,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0x53,
    0x70,
    0x6C,
    0x69,
    0x6E,
    0x65,
    0x54,
    0x69,
    0x6D,
    0x65,
    0,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0x53,
    0x70,
    0x6C,
    0x69,
    0x6E,
    0x65,
    0x49,
    0x44,
    0,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0x53,
    0x70,
    0x6C,
    0x69,
    0x6E,
    0x65,
    0x54,
    0x69,
    0x6D,
    0x65,
    0,
    0x46,
    0x6F,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0x4F,
    0x6E,
    0x45,
    0x76,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0,
    0x46,
    0x6F,
    0x6C,
    0x6C,
    0x6F,
    0x77,
    0x4F,
    0x6E,
    0x45,
    0x76,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x4C,
    0x65,
    0x72,
    0x70,
    0x54,
    0x69,
    0x6D,
    0x65,
    0,
    0x46,
    0x75,
    0x72,
    0x79,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0x43,
    0x68,
    0x69,
    0x6C,
    0x64,
    0,
    0x52,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x65,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0,
    0x52,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x65,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x41,
    0x6E,
    0x67,
    0x6C,
    0x65,
    0x43,
    0x68,
    0x69,
    0x6C,
    0x64,
    0x4F,
    0x72,
    0x69,
    0x65,
    0x6E,
    0x74,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0,
    0x52,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x65,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x53,
    0x70,
    0x65,
    0x65,
    0x64,
    0,
    0x52,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x65,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x52,
    0x61,
    0x64,
    0x69,
    0x75,
    0x73,
    0,
    0x52,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x65,
    0x59,
    0x4F,
    0x66,
    0x66,
    0x73,
    0x65,
    0x74,
    0,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0x59,
    0x4F,
    0x66,
    0x66,
    0x73,
    0x65,
    0x74,
    0,
    0x52,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x65,
    0x53,
    0x74,
    0x61,
    0x72,
    0x74,
    0x41,
    0x6E,
    0x67,
    0x6C,
    0x65,
    0,
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x42,
    0x61,
    0x63,
    0x6B,
    0x54,
    0x6F,
    0x50,
    0x6C,
    0x61,
    0x79,
    0x65,
    0x72,
    0,
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x42,
    0x61,
    0x63,
    0x6B,
    0x54,
    0x6F,
    0x50,
    0x6C,
    0x61,
    0x79,
    0x65,
    0x72,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0,
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x46,
    0x72,
    0x6F,
    0x6D,
    0x43,
    0x75,
    0x72,
    0x72,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0,
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x46,
    0x72,
    0x6F,
    0x6D,
    0x43,
    0x75,
    0x72,
    0x72,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x4C,
    0x6F,
    0x6F,
    0x6B,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0,
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x42,
    0x61,
    0x63,
    0x6B,
    0x54,
    0x6F,
    0x50,
    0x6C,
    0x61,
    0x79,
    0x65,
    0x72,
    0x54,
    0x69,
    0x6D,
    0x65,
    0,
    0x54,
    0x72,
    0x61,
    0x6E,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0x46,
    0x72,
    0x6F,
    0x6D,
    0x43,
    0x75,
    0x72,
    0x72,
    0x65,
    0x6E,
    0x74,
    0x43,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x54,
    0x69,
    0x6D,
    0x65,
    0,
    0x63,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0,
    0x63,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x53,
    0x6F,
    0x75,
    0x72,
    0x63,
    0x65,
    0,
    0x63,
    0x61,
    0x6D,
    0x65,
    0x72,
    0x61,
    0x54,
    0x61,
    0x72,
    0x67,
    0x65,
    0x74,
    0,
}; /* const */

void EventCamera::CalculateCircleTangent(MKVector3 arg0, MKVector3 arg1, float arg2) {
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_220;
    f32 temp_f0_409;
    f32 temp_f1_408;
    f32 temp_f3_416;
    f32 temp_f4_324;
    f32 temp_f6_300;
    f32 temp_f7_293;
    f32 temp_f8_295;
    f32 var_f2_100;
    f32 var_f31_77;
    f32 var_f3_399;
    f32 var_f4_149;
    f32 var_f4_332;
    f32 var_f5_286;
    f64 temp_f1_152;
    f64 temp_f1_158;
    f64 temp_f1_162;
    f64 temp_f1_322;
    f64 temp_f1_338;
    f64 temp_f1_344;
    f64 temp_f1_348;
    f64 temp_f1_84;
    f64 temp_f1_90;
    f64 temp_f1_94;
    f64 temp_f2_225;
    f64 temp_f2_231;
    f64 temp_f2_235;
    s32 temp_r3_113;
    s32 temp_r3_181;
    s32 temp_r3_254;
    s32 temp_r3_367;
    s32 var_r0_123;
    s32 var_r0_191;
    s32 var_r0_264;
    s32 var_r0_377;

    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r6, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp48 = sp28;
    sp30 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 8) - M2C_FIELD(arg1, f32 *, 8);
    sp20 = 1.0f;
    sp50 = (f64) sp30;
    sp18 = 0.0f;
    sp1C = 0.0f;
    var_f31_77 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (0.0f * 0.0f));
    unksp4C = 0.0f;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    if (var_f31_77 > 0.0f) {
        temp_f1_84 = __frsqrte(var_f31_77);
        temp_f1_90 = 0.5 * temp_f1_84 * -(((f64) var_f31_77 * (temp_f1_84 * temp_f1_84)) - 3.0);
        temp_f1_94 = 0.5 * temp_f1_90 * -(((f64) var_f31_77 * (temp_f1_90 * temp_f1_90)) - 3.0);
        var_f2_100 = (f32) ((f64) var_f31_77 * (0.5 * temp_f1_94 * -(((f64) var_f31_77 * (temp_f1_94 * temp_f1_94)) - 3.0)));
    } else if (var_f31_77 < M2C_BITWISE(f32, 0.0)) {
        var_f2_100 = __float_nan;
    } else {
        sp14 = var_f31_77;
        temp_r3_113 = M2C_BITWISE(s32, sp14) & 0x7F800000;
        switch (temp_r3_113) {                      /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_123 = 1;
            } else {
                var_r0_123 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_123 = 5;
            } else {
                var_r0_123 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_123 = 4;
            break;
        }
        if (var_r0_123 == 1) {
            var_f2_100 = __float_nan;
        } else {
            var_f2_100 = var_f31_77;
        }
    }
    var_f4_149 = (var_f2_100 * var_f2_100) - (arg2 * arg2);
    if (var_f4_149 > 0.0f) {
        temp_f1_152 = __frsqrte(var_f4_149);
        temp_f1_158 = 0.5 * temp_f1_152 * -(((f64) var_f4_149 * (temp_f1_152 * temp_f1_152)) - 3.0);
        temp_f1_162 = 0.5 * temp_f1_158 * -(((f64) var_f4_149 * (temp_f1_158 * temp_f1_158)) - 3.0);
        var_f4_149 = (f32) ((f64) var_f4_149 * (0.5 * temp_f1_162 * -(((f64) var_f4_149 * (temp_f1_162 * temp_f1_162)) - 3.0)));
    } else if (var_f4_149 < M2C_BITWISE(f32, 0.0)) {
        var_f4_149 = __float_nan;
    } else {
        sp10 = var_f4_149;
        temp_r3_181 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_181) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_191 = 1;
            } else {
                var_r0_191 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_191 = 5;
            } else {
                var_r0_191 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_191 = 4;
            break;
        }
        if (var_r0_191 == 1) {
            var_f4_149 = __float_nan;
        }
    }
    temp_f0_220 = 90.0f - (57.29578f * (f32) atan(arg2 / var_f4_149));
    if (var_f31_77 > 0.000001f) {
        if (var_f31_77 > 0.0f) {
            temp_f2_225 = __frsqrte(var_f31_77);
            temp_f2_231 = 0.5 * temp_f2_225 * -(((f64) var_f31_77 * (temp_f2_225 * temp_f2_225)) - 3.0);
            temp_f2_235 = 0.5 * temp_f2_231 * -(((f64) var_f31_77 * (temp_f2_231 * temp_f2_231)) - 3.0);
            var_f31_77 = (f32) ((f64) var_f31_77 * (0.5 * temp_f2_235 * -(((f64) var_f31_77 * (temp_f2_235 * temp_f2_235)) - 3.0)));
        } else if (var_f31_77 < M2C_BITWISE(f32, 0.0)) {
            var_f31_77 = __float_nan;
        } else {
            spC = var_f31_77;
            temp_r3_254 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_254) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_264 = 1;
                } else {
                    var_r0_264 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_264 = 5;
                } else {
                    var_r0_264 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_264 = 4;
                break;
            }
            if (var_r0_264 == 1) {
                var_f31_77 = __float_nan;
            }
        }
        var_f5_286 = 1.0f / var_f31_77;
    } else {
        var_f5_286 = 0.0f;
    }
    temp_f7_293 = unksp4C * var_f5_286;
    temp_f8_295 = (f32) sp48 * var_f5_286;
    temp_f6_300 = (f32) sp50 * var_f5_286;
    sp48 = temp_f8_295;
    unksp4C = temp_f7_293;
    sp50 = temp_f6_300;
    sp5C = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xE8) = (f32) (temp_f0_220 + (57.29578f * ((temp_f6_300 * (f32) sp40) + ((temp_f8_295 * (f32) sp38) + (temp_f7_293 * unksp3C)))));
    sp58 = _table_sinf(0.017453292f * M2C_FIELD(arg0, f32 *, 0xE8));
    temp_f1_322 = _table_sinf(1.5707964f + (0.017453292f * M2C_FIELD(arg0, f32 *, 0xE8)));
    temp_f4_324 = (f32) temp_f1_322;
    sp60 = (f32) temp_f1_322;
    var_f4_332 = (temp_f4_324 * temp_f4_324) + ((sp58 * sp58) + (0.0f * 0.0f));
    if (var_f4_332 > 0.000001f) {
        if (var_f4_332 > 0.0f) {
            temp_f1_338 = __frsqrte(var_f4_332);
            temp_f1_344 = 0.5 * temp_f1_338 * -(((f64) var_f4_332 * (temp_f1_338 * temp_f1_338)) - 3.0);
            temp_f1_348 = 0.5 * temp_f1_344 * -(((f64) var_f4_332 * (temp_f1_344 * temp_f1_344)) - 3.0);
            var_f4_332 = (f32) ((f64) var_f4_332 * (0.5 * temp_f1_348 * -(((f64) var_f4_332 * (temp_f1_348 * temp_f1_348)) - 3.0)));
        } else if (var_f4_332 < M2C_BITWISE(f32, 0.0)) {
            var_f4_332 = __float_nan;
        } else {
            sp8 = var_f4_332;
            temp_r3_367 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_367) {                  /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_377 = 1;
                } else {
                    var_r0_377 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_377 = 5;
                } else {
                    var_r0_377 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_377 = 4;
                break;
            }
            if (var_r0_377 == 1) {
                var_f4_332 = __float_nan;
            }
        }
        var_f3_399 = 1.0f / var_f4_332;
    } else {
        var_f3_399 = 0.0f;
    }
    temp_f1_408 = sp5C * var_f3_399;
    temp_f0_409 = sp60 * var_f3_399;
    sp58 *= var_f3_399;
    sp5C = temp_f1_408;
    sp60 = temp_f0_409;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f30 */);
    temp_f3_416 = temp_f0_409 * arg2;
    sp60 = temp_f3_416;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp60 = temp_f3_416 + M2C_FIELD(arg1, f32 *, 8);
    sp5C = temp_f1_408 + M2C_FIELD(arg0, f32 *, 0xE0);
    M2C_FIELD(this, f64 *, 0) = (f64) sp58;
    M2C_FIELD(this, f64 *, 8) = (f64) sp60;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EventCamera::FunctionOff() {
    s8 spC9;
    u8 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    s32 sp84;
    s32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1_552;
    f32 temp_f2_551;
    f32 temp_f4_553;
    f32 var_f1_625;
    f32 var_f4_559;
    f64 temp_f1_468;
    f64 temp_f1_565;
    f64 temp_f1_571;
    f64 temp_f1_575;
    s32 temp_r3_594;
    s32 var_r4_523;
    void *temp_r3_702;
    void *temp_r5_465;
    void *temp_r6_476;

    if (!(this->unk18 & 0x80000000)) {
        if ((u8) this->unkFC != 0) {
            temp_r5_465 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *), 0xC)(gb.unk0), void **, 8);
            temp_f1_468 = M2C_FIELD(temp_r5_465, f64 *, 0x30);
            sp70 = temp_f1_468;
            sp78 = M2C_FIELD(temp_r5_465, f64 *, 0x38);
            temp_r6_476 = M2C_FIELD(M2C_FIELD(gb.unk0->__vptr, void *(**)(HeroInterface *, GameGlobals *, void *, f64), 0xC)(gb.unk0, &gb, temp_r5_465, temp_f1_468), void **, 8);
            sp30 = -M2C_FIELD(temp_r6_476, f32 *, 0x20);
            sp34 = -M2C_FIELD(temp_r6_476, f32 *, 0x24);
            sp38 = -M2C_FIELD(temp_r6_476, f32 *, 0x28);
            sp84 = 0;
            sp80 = 0x421;
            sp88 = sp70;
            sp90 = sp78;
            sp98 = (f64) sp30;
            spA0 = (f64) sp38;
            spA8 = M2C_FIELD(&zero, f64 *, 0);
            spB0 = M2C_FIELD(&zero, f64 *, 8);
            spB8 = M2C_FIELD(&zero, f64 *, 0);
            spC0 = M2C_FIELD(&zero, f64 *, 8);
            spC8 = 0;
            spC9 = 0;
            sp60 = (f64) sp30;
            sp68 = (f64) sp38;
            sp20 = M2C_FIELD(&zero, f64 *, 0);
            sp28 = M2C_FIELD(&zero, f64 *, 8);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, void *, f64, f64, f64, f64, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp80, 0, temp_r6_476, M2C_FIELD(&zero, f64 *, 0), sp78, sp70, (f64) sp38, (f64) sp30);
            if (spC8 != 0) {
                var_r4_523 = 1;
                this->unkFD = 1;
                this->unkFC = 0;
                this->unk90 = this->unk50;
                this->unk98 = this->unk58;
                this->unk60.unk4 += this->unkEC;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                this->unkA0 = sp40;
                sp48 = this->unk60.unk8 - (f32) M2C_FIELD(this, f64 *, 0x58);
                sp50 = sp40;
                this->unkA8 = (f64) sp48;
                temp_f2_551 = (f32) M2C_FIELD(this, f64 *, 0xA0);
                temp_f1_552 = M2C_FIELD(this, f32 *, 0xA4);
                temp_f4_553 = (f32) M2C_FIELD(this, f64 *, 0xA8);
                sp58 = (f64) sp48;
                var_f4_559 = (temp_f4_553 * temp_f4_553) + ((temp_f2_551 * temp_f2_551) + (temp_f1_552 * temp_f1_552));
                if (var_f4_559 > 0.000001f) {
                    if (var_f4_559 > 0.0f) {
                        temp_f1_565 = __frsqrte(var_f4_559);
                        temp_f1_571 = 0.5 * temp_f1_565 * -(((f64) var_f4_559 * (temp_f1_565 * temp_f1_565)) - 3.0);
                        temp_f1_575 = 0.5 * temp_f1_571 * -(((f64) var_f4_559 * (temp_f1_571 * temp_f1_571)) - 3.0);
                        var_f4_559 = (f32) ((f64) var_f4_559 * (0.5 * temp_f1_575 * -(((f64) var_f4_559 * (temp_f1_575 * temp_f1_575)) - 3.0)));
                    } else if (var_f4_559 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_559 = __float_nan;
                    } else {
                        sp8 = var_f4_559;
                        temp_r3_594 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_594) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                            } else {
                                var_r4_523 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r4_523 = 5;
                            } else {
                                var_r4_523 = 3;
                            }
                            break;
                        default:
                            var_r4_523 = 4;
                            break;
                        }
                        if (var_r4_523 == 1) {
                            var_f4_559 = __float_nan;
                        }
                    }
                    var_f1_625 = 1.0f / var_f4_559;
                } else {
                    var_f1_625 = 0.0f;
                }
                M2C_FIELD(this, f64 *, 0xA0) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA0) * var_f1_625);
                M2C_FIELD(this, f32 *, 0xA4) = (f32) (M2C_FIELD(this, f32 *, 0xA4) * var_f1_625);
                M2C_FIELD(this, f64 *, 0xA8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA8) * var_f1_625);
                M2C_FIELD(&cameraPos, f64 *, 0) = spA8;
                M2C_FIELD(&cameraDir, f64 *, 0) = spB8;
                M2C_FIELD(&cameraPos, f64 *, 8) = spB0;
                M2C_FIELD(&cameraDir, f64 *, 8) = spC0;
                return;
            }
        }
        this->unk50 = this->unk70;
        this->unk58 = this->unk78;
        M2C_FIELD(this, f64 *, 0x60) = (f64) this->unk80;
        M2C_FIELD(this, f32 *, 0x68) = (f64) this->unk88;
        if (((u8) this->unkF9 != 0) && ((s32) gb.unk50 == 0)) {
            gb.unk30.FadeOut(NULL);
            return;
        }
        Reset();
        if ((EventCamera *) pCurrentCamera == NULL) {
            Hud_Show(1U);
            sp18 = 0;
            sp14 = 0x413;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp14);
            if ((HeroInterface *) gb.unk0 != NULL) {
                temp_r3_702 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
                sp10 = 0;
                spC = 0xA3;
                M2C_FIELD(M2C_FIELD(temp_r3_702, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spC);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34C'
void EventCamera::FunctionOn() {
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;                                       /* compiler-managed */
    MKProp sp88;
    M2C_UNK sp78;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp30;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_799;
    f32 temp_f1_998;
    f32 temp_f2_798;
    f32 temp_f4_800;
    f32 temp_f5_1002;
    f32 var_f1_873;
    f32 var_f3_1074;
    f32 var_f4_1007;
    f32 var_f4_806;
    f64 temp_f0_1162;
    f64 temp_f0_1206;
    f64 temp_f0_896;
    f64 temp_f0_904;
    f64 temp_f1_1013;
    f64 temp_f1_1019;
    f64 temp_f1_1023;
    f64 temp_f1_1161;
    f64 temp_f1_1205;
    f64 temp_f1_812;
    f64 temp_f1_818;
    f64 temp_f1_822;
    f64 temp_f1_895;
    f64 temp_f1_903;
    s32 temp_r3_1042;
    s32 temp_r3_841;
    s32 var_r0_1052;
    s32 var_r0_851;
    void *temp_r3_1108;
    void *temp_r3_1140;
    void *temp_r3_1197;
    void *temp_r3_1201;
    void *temp_r3_1239;
    void *temp_r3_894;
    void *temp_r3_902;
    void *temp_r4_1204;
    void *temp_r4_983;
    void *temp_r6_1160;
    void *temp_r7_947;

    if (((s32) gb.unk34C != 0) && (this->unk18 & 0x80000000) && (M2C_FIELD(gb.unk0->__vptr, u8 (**)(HeroInterface *), 0x54)(gb.unk0) == 0)) {
        if (M2C_FIELD(gb.unk0->__vptr, u8 (**)(HeroInterface *), 0x60)(gb.unk0) != 0) {
            return;
        }
        if ((u8) M2C_FIELD(gb.unkC, u8 *, 0xA9) != 0) {
            M2C_FIELD(gb.unkC, u8 *, 0xA9) = 0U;
        }
        Hud_Show(0U);
        if ((u8) this->unkFF != 0) {
            if ((EventCamera *) pCurrentCamera != NULL) {
                pPeviousCamera = pCurrentCamera;
                this->unk90 = pCurrentCamera->unk50;
                this->unk98 = pCurrentCamera->unk58;
                sp178 = M2C_FIELD(pCurrentCamera, f64 *, 0x60);
                sp180 = M2C_FIELD(pCurrentCamera, f64 *, 0x68);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                this->unkA0 = sp68;
                sp70 = (f32) sp180 - (f32) M2C_FIELD(pCurrentCamera, f64 *, 0x58);
                sp168 = sp68;
                this->unkA8 = (f64) sp70;
                temp_f2_798 = (f32) M2C_FIELD(this, f64 *, 0xA0);
                temp_f1_799 = M2C_FIELD(this, f32 *, 0xA4);
                temp_f4_800 = (f32) M2C_FIELD(this, f64 *, 0xA8);
                sp170 = (f64) sp70;
                var_f4_806 = (temp_f4_800 * temp_f4_800) + ((temp_f2_798 * temp_f2_798) + (temp_f1_799 * temp_f1_799));
                if (var_f4_806 > 0.000001f) {
                    if (var_f4_806 > 0.0f) {
                        temp_f1_812 = __frsqrte(var_f4_806);
                        temp_f1_818 = 0.5 * temp_f1_812 * -(((f64) var_f4_806 * (temp_f1_812 * temp_f1_812)) - 3.0);
                        temp_f1_822 = 0.5 * temp_f1_818 * -(((f64) var_f4_806 * (temp_f1_818 * temp_f1_818)) - 3.0);
                        var_f4_806 = (f32) ((f64) var_f4_806 * (0.5 * temp_f1_822 * -(((f64) var_f4_806 * (temp_f1_822 * temp_f1_822)) - 3.0)));
                    } else if (var_f4_806 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_806 = __float_nan;
                    } else {
                        spC = var_f4_806;
                        temp_r3_841 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_841) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_851 = 1;
                            } else {
                                var_r0_851 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_851 = 5;
                            } else {
                                var_r0_851 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_851 = 4;
                            break;
                        }
                        if (var_r0_851 == 1) {
                            var_f4_806 = __float_nan;
                        }
                    }
                    var_f1_873 = 1.0f / var_f4_806;
                } else {
                    var_f1_873 = 0.0f;
                }
                M2C_FIELD(this, f64 *, 0xA0) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA0) * var_f1_873);
                M2C_FIELD(this, f32 *, 0xA4) = (f32) (M2C_FIELD(this, f32 *, 0xA4) * var_f1_873);
                M2C_FIELD(this, f64 *, 0xA8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA8) * var_f1_873);
            } else {
                pPeviousCamera = NULL;
                temp_r3_894 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f1_895 = M2C_FIELD(temp_r3_894, f64 *, 0x30);
                temp_f0_896 = M2C_FIELD(temp_r3_894, f64 *, 0x38);
                sp158 = temp_f1_895;
                this->unk90 = temp_f1_895;
                this->unk98 = temp_f0_896;
                sp160 = temp_f0_896;
                temp_r3_902 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f1_903 = M2C_FIELD(temp_r3_902, f64 *, 0x20);
                temp_f0_904 = M2C_FIELD(temp_r3_902, f64 *, 0x28);
                sp148 = temp_f1_903;
                this->unkA0 = temp_f1_903;
                sp150 = temp_f0_904;
                this->unkA8 = temp_f0_904;
            }
            sp138.GetTargetStart();
            M2C_FIELD(&cameraPos, f64 *, 0x20) = sp138;
            M2C_FIELD(&cameraPos, f64 *, 0x28) = sp140;
            this->unk80 = sp138;
            this->unk88 = sp140;
            if ((u8) this->unk103 != 0) {
                if ((u8) this->unk104 != 0) {
                    sp118.operator*(this->unkDC);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    sp128 = sp58;
                    sp60 = this->unk60.unk8 + sp118.unk8;
                    M2C_FIELD(&cameraPos, f64 *, 0) = sp58;
                    sp130 = (f64) sp60;
                    M2C_FIELD(&cameraPos, f64 *, 8) = (f64) sp60;
                } else {
                    temp_r7_947 = &cameraPos + 0x20;
                    spE8 = this->unk90;
                    spF0 = this->unk98;
                    sp50 = M2C_FIELD(temp_r7_947, f32 *, 8);
                    sp48 = (f32) M2C_FIELD(&cameraPos, f64 *, 0x20);
                    sp4C = M2C_FIELD(temp_r7_947, f32 *, 4) - this->unkEC;
                    sp100 = (f64) sp50;
                    spF8 = (f64) sp48;
                    sp108.CalculateCircleTangent((MKVector3) this, (MKVector3) &spF8, this->unkDC);
                    M2C_FIELD(&cameraPos, f64 *, 0) = sp108;
                    M2C_FIELD(&cameraPos, f64 *, 8) = sp110;
                }
            } else {
                spD8.GetSourceStart();
                M2C_FIELD(&cameraPos, f64 *, 0) = spD8;
                M2C_FIELD(&cameraPos, f64 *, 8) = spE0;
            }
            temp_r4_983 = &cameraPos + 0x20;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            M2C_FIELD(&cameraPos, f64 *, 0x20) = sp38;
            sp40 = M2C_FIELD(temp_r4_983, f32 *, 8) - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
            temp_f1_998 = M2C_FIELD(temp_r4_983, f32 *, 4);
            M2C_FIELD(&cameraPos, f64 *, 0x28) = (f64) sp40;
            temp_f5_1002 = M2C_FIELD(temp_r4_983, f32 *, 8);
            spC8 = sp38;
            spD0 = (f64) sp40;
            var_f4_1007 = (temp_f5_1002 * temp_f5_1002) + (((f32) M2C_FIELD(&cameraPos, f64 *, 0x20) * (f32) M2C_FIELD(&cameraPos, f64 *, 0x20)) + (temp_f1_998 * temp_f1_998));
            if (var_f4_1007 > 0.000001f) {
                if (var_f4_1007 > 0.0f) {
                    temp_f1_1013 = __frsqrte(var_f4_1007);
                    temp_f1_1019 = 0.5 * temp_f1_1013 * -(((f64) var_f4_1007 * (temp_f1_1013 * temp_f1_1013)) - 3.0);
                    temp_f1_1023 = 0.5 * temp_f1_1019 * -(((f64) var_f4_1007 * (temp_f1_1019 * temp_f1_1019)) - 3.0);
                    var_f4_1007 = (f32) ((f64) var_f4_1007 * (0.5 * temp_f1_1023 * -(((f64) var_f4_1007 * (temp_f1_1023 * temp_f1_1023)) - 3.0)));
                } else if (var_f4_1007 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1007 = __float_nan;
                } else {
                    sp8 = var_f4_1007;
                    temp_r3_1042 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1042) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1052 = 1;
                        } else {
                            var_r0_1052 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1052 = 5;
                        } else {
                            var_r0_1052 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1052 = 4;
                        break;
                    }
                    if (var_r0_1052 == 1) {
                        var_f4_1007 = __float_nan;
                    }
                }
                var_f3_1074 = 1.0f / var_f4_1007;
            } else {
                var_f3_1074 = 0.0f;
            }
            M2C_FIELD(&cameraPos, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(&cameraPos, f64 *, 0x20) * var_f3_1074);
            M2C_FIELD(temp_r4_983, f32 *, 4) = (f32) (M2C_FIELD(temp_r4_983, f32 *, 4) * var_f3_1074);
            M2C_FIELD(temp_r4_983, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_983, f32 *, 8) * var_f3_1074);
            this->unk101 = 1;
        }
        if (((EventCamera *) pCurrentCamera != NULL) && ((EventCamera *) pCurrentCamera != this)) {
            M2C_FIELD(pCurrentCamera->__vptr, M2C_UNK (**)(), 0x34)();
            if ((HeroInterface *) gb.unk0 != NULL) {
                temp_r3_1108 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
                sp1C = 0;
                sp18 = 0xAA;
                M2C_FIELD(M2C_FIELD(temp_r3_1108, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp18);
            }
        }
        if ((HeroInterface *) gb.unk0 != NULL) {
            if ((u8) this->unkF6 == 0) {
                EventCamera_bRemainTargetable = 1;
                M2C_FIELD(gb.unk0->__vptr, M2C_UNK (**)(), 0x24)();
                EventCamera_bRemainTargetable = 0;
            } else {
                temp_r3_1140 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
                sp14 = 0;
                sp10 = 0xA9;
                M2C_FIELD(M2C_FIELD(temp_r3_1140, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
            }
        }
        if ((EventCamera *) pCurrentCamera == NULL) {
            temp_r6_1160 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            temp_f1_1161 = M2C_FIELD(temp_r6_1160, f64 *, 0x30);
            temp_f0_1162 = M2C_FIELD(temp_r6_1160, f64 *, 0x38);
            spB8 = temp_f1_1161;
            M2C_FIELD(&cameraPos, f64 *, 0x10) = temp_f1_1161;
            M2C_FIELD(&cameraPos, f64 *, 0x18) = temp_f0_1162;
            sp24 = 0;
            sp20 = 0x402;
            spC0 = temp_f0_1162;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, void *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp20, 0, temp_r6_1160, temp_f1_1161);
            if (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 0) {
                gb.GetSpyro();
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                    gb.GetSpyro();
                    ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetInvincibilityTimeOut(1000.0f);
                }
            }
        }
        pCurrentCamera = this;
        if ((u8) this->unkF7 != 0) {
            temp_r3_1197 = this->unkB0;
            if (temp_r3_1197 != NULL) {
                temp_r3_1201 = M2C_FIELD(temp_r3_1197, void **, 0x70);
                temp_r4_1204 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f1_1205 = M2C_FIELD(temp_r4_1204, f64 *, 0x30);
                temp_f0_1206 = M2C_FIELD(temp_r4_1204, f64 *, 0x38);
                spA8 = temp_f1_1205;
                M2C_FIELD(temp_r3_1201, f64 *, 0) = temp_f1_1205;
                spB0 = temp_f0_1206;
                M2C_FIELD(temp_r3_1201, f64 *, 8) = temp_f0_1206;
            }
        }
        if (((u8) this->unkF8 != 0) && ((void *) pCurrentCamera->unkB4 != NULL)) {
            sp78.GetDir((u8) M2C_FIELD(&gb, void **, 0x3B8));
            sp88.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r3_1239 = M2C_FIELD(pCurrentCamera->unkB4, void **, 0x70);
            sp88.unk10 = sp28;
            sp30 = M2C_BITWISE(f32, sp88.unk8) + sp80;
            M2C_FIELD(temp_r3_1239, f64 *, 0) = sp28;
            sp88.unk18 = (f64) sp30;
            M2C_FIELD(temp_r3_1239, f64 *, 8) = (f64) sp30;
        }
        Enable();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned long' to
void EventCamera::GetSourceStart() {
    f64 sp28;
    f32 sp24;
    KDUniformSpline sp10;
    f32 sp8;
    u32 temp_r6_1279;

    temp_r6_1279 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u32 *, 0xB0);
    if (temp_r6_1279 != 0U) {
        sp8 = 0.0f;
        sp10.GetMeasure(0.0f, temp_r6_1279 + 0x7C, KDSpline_PositionMixer);
        sp10.unk10 = M2C_BITWISE(f64, sp10);
        sp28 = (f64) sp10.unk8;
    } else {
        sp10.unk10 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x70);
        sp28 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x78);
        if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x103) != 0) {
            sp24 += M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0xE0);
        }
    }
    M2C_FIELD(this, f64 *, 0) = sp10.unk10;
    M2C_FIELD(this, f64 *, 8) = sp28;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void EventCamera::GetTargetStart() {
    f64 sp98;
    f64 sp90;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    KDUniformSpline sp20;
    f32 sp18;
    f32 spC;
    f32 sp8;
    MKSceneManager *temp_r3_1348;
    f64 temp_f0_1369;
    f64 temp_f0_1381;
    f64 temp_f1_1368;
    f64 temp_f1_1380;
    f64 temp_f2_1399;
    f64 temp_f3_1398;
    s32 temp_r3_1355;
    u32 temp_r6_1331;
    u8 temp_r0_1409;
    void *temp_r30_1325;
    void *temp_r3_1367;
    void *temp_r3_1379;
    void *temp_r3_1393;
    void *temp_r3_1396;

    temp_r30_1325 = M2C_ERROR(/* Read from unset register $r4 */);
    sp90 = M2C_FIELD(&zero, f64 *, 0);
    temp_r6_1331 = M2C_FIELD(temp_r30_1325, u32 *, 0xB4);
    sp98 = M2C_FIELD(&zero, f64 *, 8);
    if (temp_r6_1331 != 0U) {
        spC = 0.0f;
        sp80.GetMeasure(0.0f, temp_r6_1331 + 0x7C, KDSpline_PositionMixer);
        sp90 = sp80;
        sp98 = sp88;
    } else {
        temp_r3_1348 = M2C_FIELD(temp_r30_1325, MKSceneManager **, 0xF0);
        if (temp_r3_1348 != NULL) {
            if ((u8) M2C_FIELD(temp_r30_1325, u8 *, 0x102) != 0) {
                temp_r3_1355 = checked_cast<EnemySpawner *, MKProp>(temp_r3_1348->PropResolver_Resolve((s32) &zero));
                ((SpawnerObject *) (temp_r3_1355 + 0x90))->GetNumberActive();
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    if ((u8) M2C_FIELD(temp_r30_1325, u8 *, 0x104) != 0) {
                        temp_r3_1367 = ((SpawnerObject *) (temp_r3_1355 + 0x90))->GetActive(0)->unk8;
                        temp_f1_1368 = M2C_FIELD(temp_r3_1367, f64 *, 0x30);
                        temp_f0_1369 = M2C_FIELD(temp_r3_1367, f64 *, 0x38);
                        sp70 = temp_f1_1368;
                        sp78 = temp_f0_1369;
                        sp90 = temp_f1_1368;
                        sp98 = temp_f0_1369;
                    } else {
                        temp_r3_1379 = ((SpawnerObject *) (temp_r3_1355 + 0x90))->GetActive(0)->unk8;
                        temp_f1_1380 = M2C_FIELD(temp_r3_1379, f64 *, 0x30);
                        temp_f0_1381 = M2C_FIELD(temp_r3_1379, f64 *, 0x38);
                        sp60 = temp_f1_1380;
                        sp68 = temp_f0_1381;
                        sp90 = temp_f1_1380;
                        sp98 = temp_f0_1381;
                    }
                    unksp94 += M2C_FIELD(temp_r30_1325, f32 *, 0xEC);
                }
            } else {
                temp_r3_1393 = temp_r3_1348->PropResolver_Resolve((s32) &zero);
                if (temp_r3_1393 != NULL) {
                    temp_r3_1396 = M2C_FIELD(temp_r3_1393, void **, 8);
                    temp_f3_1398 = M2C_FIELD(temp_r3_1396, f64 *, 0x30);
                    temp_f2_1399 = M2C_FIELD(temp_r3_1396, f64 *, 0x38);
                    sp90 = temp_f3_1398;
                    sp50 = temp_f3_1398;
                    sp58 = temp_f2_1399;
                    sp98 = temp_f2_1399;
                    unksp94 += M2C_FIELD(temp_r30_1325, f32 *, 0xEC);
                }
            }
        } else {
            temp_r0_1409 = M2C_FIELD(temp_r30_1325, u8 *, 0xF5);
            if ((temp_r0_1409 == 0) && ((u32) M2C_FIELD(temp_r30_1325, u32 *, 0xB0) != 0U)) {
                sp20.GetVelocity(0.0f);
                sp8 = 0.0f;
                sp20.unk10.GetMeasure(0.0f, M2C_FIELD(temp_r30_1325, u32 *, 0xB0) + 0x7C, KDSpline_PositionMixer);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp40 = sp10;
                sp18 = sp38 + sp20.unk8;
                sp90 = sp10;
                sp48 = (f64) sp18;
                sp98 = (f64) sp18;
            } else if (temp_r0_1409 != 0) {
                sp90 = M2C_FIELD(temp_r30_1325, f64 *, 0x60);
                sp98 = M2C_FIELD(temp_r30_1325, f64 *, 0x68);
            }
        }
    }
    M2C_FIELD(this, f64 *, 0) = sp90;
    M2C_FIELD(this, f64 *, 8) = sp98;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EventCamera::Update() {
    EventCamera *temp_r3_2815;
    f32 temp_f0_1756;
    f32 temp_f0_1805;
    f32 temp_f0_2032;
    f32 temp_f0_2091;
    f32 temp_f0_2323;
    f32 temp_f0_2412;
    f32 temp_f0_2709;
    f32 temp_f1_1732;
    f32 temp_f1_1777;
    f32 temp_f1_1803;
    f32 temp_f1_2014;
    f32 temp_f1_2063;
    f32 temp_f1_2322;
    f32 temp_f1_2411;
    f32 temp_f1_2708;
    f32 temp_f1_2743;
    f32 temp_f1_2892;
    f32 temp_f2_1706;
    f32 temp_f2_1992;
    f32 temp_f2_2089;
    f32 temp_f2_2742;
    f32 temp_f2_2753;
    f32 temp_f2_2893;
    f32 temp_f30_2098;
    f32 temp_f30_2445;
    f32 temp_f30_2537;
    f32 temp_f30_2761;
    f32 temp_f3_1989;
    f32 var_f1_2090;
    f32 var_f1_2747;
    f32 var_f30_1804;
    f32 var_f3_1729;
    f32 var_f3_1754;
    f32 var_f3_2011;
    f32 var_f3_2030;
    f64 temp_f0_1580;
    f64 temp_f0_2393;
    f64 temp_f2_1581;
    f64 temp_f2_2394;
    s32 temp_cr0_eq_1710;
    s32 temp_cr0_eq_1717;
    s32 temp_cr0_eq_1999;
    s32 temp_r3_1512;
    s32 temp_r3_2607;
    u32 var_r4_1483;
    u64 temp_ret_1483;
    u64 temp_ret_1492;
    u8 temp_r4_2818;
    u8 var_r30_1504;
    void *temp_r0_2803;
    void *temp_r3_2388;
    void *temp_r3_2391;
    void *temp_r3_2785;
    void *temp_r4_1578;
    void *temp_r4_2319;
    void *temp_r4_2705;
    MKProp::Update();
    temp_ret_1483 = M2C_FIELD(gb.unk0->__vptr, u64 (**)(HeroInterface *), 0x54)(gb.unk0);
    var_r4_1483 = (u32) temp_ret_1483;
    if (((temp_ret_1483 != 0) || (temp_ret_1492 = M2C_FIELD(gb.unk0->__vptr, u64 (**)(HeroInterface *), 0x60)(gb.unk0), var_r4_1483 = (u32) temp_ret_1492, ((temp_ret_1492 == 0) == 0))) && (this == (EventCamera *) pCurrentCamera)) {
        FunctionOff();
        return;
    }
    var_r30_1504 = 1;
    if ((u8) this->unk101 != 0) {
        if ((u8) this->unk102 != 0) {
            temp_r3_1512 = checked_cast<EnemySpawner *, MKProp>(this->unkF0->PropResolver_Resolve((s32) var_r4_1483));
            ((SpawnerObject *) (temp_r3_1512 + 0x90))->GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                if ((u8) this->unk103 != 0) {
                    if ((u8) this->unk104 != 0) {
                        ((Matrix *) (((SpawnerObject *) (temp_r3_1512 + 0x90))->GetActive(0)->unk8))->ZAxis3();
                        arg_sp40 = -*M2C_ERROR(/* Read from unset register $r3 */);
                        arg_sp44 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
                        arg_sp48 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
                        M2C_FIELD(&cameraDir, f64 *, 0) = (f64) arg_sp40;
                        M2C_FIELD(&cameraDir, f64 *, 8) = (f64) arg_sp48;
                        arg_sp760 = (f64) arg_sp40;
                        arg_sp768 = (f64) arg_sp48;
                        arg_sp730.operator*(this->unkDC);
                        ((SpawnerObject *) (temp_r3_1512 + 0x90))->GetActive(0);
                        arg_sp740.GetPos();
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        M2C_FIELD(&cameraPos, f64 *, 0) = arg_sp1C0;
                        arg_sp1C8 = arg_sp748 - arg_sp738;
                        arg_sp750 = arg_sp1C0;
                        M2C_FIELD(&cameraPos, f64 *, 8) = (f64) arg_sp1C8;
                        arg_sp758 = (f64) arg_sp1C8;
                        M2C_FIELD(&cameraPos, f32 *, 4) = (f32) (M2C_FIELD(&cameraPos, f32 *, 4) + this->unkE0);
                        temp_r4_1578 = ((SpawnerObject *) (temp_r3_1512 + 0x90))->GetActive(0)->unk8;
                        temp_f0_1580 = M2C_FIELD(temp_r4_1578, f64 *, 0x30);
                        temp_f2_1581 = M2C_FIELD(temp_r4_1578, f64 *, 0x38);
                        arg_sp720 = temp_f0_1580;
                        M2C_FIELD(&cameraDir, f64 *, 0) = temp_f0_1580;
                        M2C_FIELD(&cameraDir, f64 *, 8) = temp_f2_1581;
                        arg_sp728 = temp_f2_1581;
                        cameraDir.unk4 += this->unkEC;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        arg_sp710 = arg_sp1B0;
                        arg_sp1B8 = cameraDir.unk8 - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
                        M2C_FIELD(&cameraDir, f64 *, 0) = arg_sp1B0;
                        arg_sp718 = (f64) arg_sp1B8;
                        M2C_FIELD(&cameraDir, f64 *, 8) = (f64) arg_sp1B8;
                        cameraDir.Normalise();
                    } else {
                        arg_sp700.GetTargetStart();
                        M2C_FIELD(&cameraDir, f64 *, 0) = arg_sp700;
                        M2C_FIELD(&cameraDir, f64 *, 8) = arg_sp708;
                        arg_sp6D0 = this->unk90;
                        arg_sp6D8 = this->unk98;
                        arg_sp1A8 = cameraDir.unk8;
                        arg_sp1A0 = cameraDir.unk0;
                        arg_sp1A4 = cameraDir.unk4 - this->unkEC;
                        arg_sp6E8 = (f64) arg_sp1A8;
                        arg_sp6E0 = (f64) arg_sp1A0;
                        arg_sp6F0.CalculateCircleTangent((MKVector3) this, (MKVector3) &arg_sp6E0, this->unkDC);
                        M2C_FIELD(&cameraPos, f64 *, 0) = arg_sp6F0;
                        M2C_FIELD(&cameraPos, f64 *, 8) = arg_sp6F8;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        arg_sp6C0 = arg_sp190;
                        arg_sp198 = cameraDir.unk8 - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
                        M2C_FIELD(&cameraDir, f64 *, 0) = arg_sp190;
                        arg_sp6C8 = (f64) arg_sp198;
                        M2C_FIELD(&cameraDir, f64 *, 8) = (f64) arg_sp198;
                        cameraDir.Normalise();
                    }
                } else {
                    arg_sp6B0.GetTargetStart();
                    M2C_FIELD(&cameraDir, f64 *, 0) = arg_sp6B0;
                    M2C_FIELD(&cameraDir, f64 *, 8) = arg_sp6B8;
                    this->unk80 = arg_sp6B0;
                    this->unk88 = arg_sp6B8;
                    arg_sp6A0.GetSourceStart();
                    M2C_FIELD(&cameraPos, f64 *, 0) = arg_sp6A0;
                    M2C_FIELD(&cameraPos, f64 *, 8) = arg_sp6A8;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp690 = arg_sp180;
                    arg_sp188 = cameraDir.unk8 - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
                    M2C_FIELD(&cameraDir, f64 *, 0) = arg_sp180;
                    arg_sp698 = (f64) arg_sp188;
                    M2C_FIELD(&cameraDir, f64 *, 8) = (f64) arg_sp188;
                    cameraDir.Normalise();
                }
            }
        }
        temp_f2_1706 = this->unkC8 / this->unkD0;
        if ((temp_f2_1706 < 0.2f) && ((temp_cr0_eq_1710 = (EventCamera *) pPeviousCamera == NULL, (temp_cr0_eq_1710 != 0)) || ((temp_cr0_eq_1710 == 0) && ((u8) pPeviousCamera->unk103 == 0) && ((temp_cr0_eq_1717 = (void *) pPeviousCamera->unkB0 == NULL, (temp_cr0_eq_1717 != 0)) || ((temp_cr0_eq_1717 == 0) && ((void *) pPeviousCamera->unkB4 != NULL) && (pPeviousCamera->unkBC < pPeviousCamera->unkC0)))))) {
            var_f3_1729 = gUpdateTimeDelta;
            temp_f1_1732 = var_f3_1729 * (temp_f2_1706 / 0.2f);
            if (temp_f1_1732 > 0.0f) {
                var_f3_1729 = temp_f1_1732;
            }
            this->unkC8 += var_f3_1729;
        } else if ((temp_f2_1706 > 0.8f) && ((void *) this->unkB0 == NULL) && ((u8) this->unk103 == 0)) {
            var_f3_1754 = 1.0f;
            temp_f0_1756 = 1.05f - ((temp_f2_1706 - 0.8f) / 0.2f);
            if (var_f3_1754 < temp_f0_1756) {

            } else {
                var_f3_1754 = temp_f0_1756;
            }
            this->unkC8 += gUpdateTimeDelta * var_f3_1754;
        } else {
            this->unkC8 += gUpdateTimeDelta;
        }
        temp_f1_1777 = this->unkC8 / this->unkD0;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_1777 == 1.0f) {
            arg_sp660 = M2C_FIELD(&cameraPos, f64 *, 0);
            arg_sp668 = M2C_FIELD(&cameraPos, f64 *, 8);
            arg_sp670 = this->unk90;
            arg_sp678 = this->unk98;
            Lerp((MKVector3) &arg_sp680, (MKVector3) &arg_sp670, temp_f1_1777);
            this->unk50 = arg_sp680;
            this->unk58 = arg_sp688;
            if ((u8) this->unk100 != 0) {
                temp_f1_1803 = this->unkD0;
                var_f30_1804 = 2.5f;
                temp_f0_1805 = 0.5f * temp_f1_1803;
                if (var_f30_1804 < temp_f0_1805) {

                } else {
                    var_f30_1804 = temp_f0_1805;
                }
                if (this->unkC8 < var_f30_1804) {
                    arg_sp640 = M2C_FIELD(&cameraPos, f64 *, 0);
                    arg_sp650 = this->unk90;
                    arg_sp648 = M2C_FIELD(&cameraPos, f64 *, 8);
                    arg_sp658 = this->unk98;
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
                    arg_sp240 = arg_sp170;
                    arg_sp178 = (f32) arg_sp648 - (f32) arg_sp658;
                    arg_sp248 = (f64) arg_sp178;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp230 = arg_sp160;
                    arg_sp168 = (f32) arg_sp248 * (var_f30_1804 / temp_f1_1803);
                    arg_sp238 = (f64) arg_sp168;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                    arg_sp7C0 = arg_sp150;
                    arg_sp158 = (f32) arg_sp658 + (f32) arg_sp238;
                    arg_sp7C8 = (f64) arg_sp158;
                    arg_sp630.GetTargetStart();
                    arg_sp7B0 = arg_sp630;
                    arg_sp7B8 = arg_sp638;
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp620 = arg_sp140;
                    arg_sp148 = (f32) arg_sp7B8 - (f32) arg_sp7C8;
                    arg_sp7B0 = arg_sp140;
                    arg_sp628 = (f64) arg_sp148;
                    arg_sp7B8 = (f64) arg_sp148;
                    arg_sp7B0.Normalise();
                    KDMath_NormalisedSlerp(*((MKVector3 *) &arg_sp600), *((MKVector3 *) &this->unkA0), this->unkC8 / var_f30_1804);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0x60) = arg_sp130;
                    arg_sp138 = (f32) M2C_FIELD(this, f64 *, 0x58) + arg_sp608;
                    arg_sp610 = arg_sp130;
                    arg_sp618 = (f64) arg_sp138;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) arg_sp138;
                } else {
                    arg_sp5F0.GetTargetStart();
                    M2C_FIELD(this, f64 *, 0x60) = arg_sp5F0;
                    M2C_FIELD(this, f64 *, 0x68) = arg_sp5F8;
                }
            } else {
                KDMath_NormalisedSlerp(*((MKVector3 *) &arg_sp5D0), *((MKVector3 *) &this->unkA0), this->unkC8 / this->unkD0);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x60) = arg_sp120;
                arg_sp128 = (f32) M2C_FIELD(this, f64 *, 0x58) + arg_sp5D8;
                arg_sp5E0 = arg_sp120;
                arg_sp5E8 = (f64) arg_sp128;
                M2C_FIELD(this, f64 *, 0x68) = (f64) arg_sp128;
            }
        } else {
            arg_sp5A0 = M2C_FIELD(&cameraPos, f64 *, 0);
            arg_sp5A8 = M2C_FIELD(&cameraPos, f64 *, 8);
            arg_sp5B0 = this->unk90;
            arg_sp5B8 = this->unk98;
            Lerp((MKVector3) &arg_sp5C0, (MKVector3) &arg_sp5B0, 1.0f);
            this->unk50 = arg_sp5C0;
            this->unk58 = arg_sp5C8;
            arg_sp590.GetTargetStart();
            M2C_FIELD(this, f64 *, 0x60) = arg_sp590;
            M2C_FIELD(this, f64 *, 0x68) = arg_sp598;
            this->unk101 = 0;
            this->unkC8 = 0.0f;
            if (((u8) this->unk102 == 0) && ((void *) this->unkB4 == NULL) && ((void *) this->unkB0 == NULL)) {
                M2C_FIELD(this, f64 *, 0x60) = (f64) this->unk80;
                M2C_FIELD(this, f64 *, 0x68) = (f64) this->unk88;
            } else {
                var_r30_1504 = 0;
            }
        }
        goto block_149;
    }
    if ((u8) this->unkFD != 0) {
        temp_f3_1989 = this->unkC8;
        temp_f2_1992 = temp_f3_1989 / this->unkCC;
        if ((temp_f2_1992 < 0.2f) && ((u8) this->unk103 == 0) && ((temp_cr0_eq_1999 = (void *) this->unkB0 == NULL, (temp_cr0_eq_1999 != 0)) || ((temp_cr0_eq_1999 == 0) && ((void *) this->unkB4 != NULL) && (this->unkBC < this->unkC0)))) {
            var_f3_2011 = gUpdateTimeDelta;
            temp_f1_2014 = var_f3_2011 * (temp_f2_1992 / 0.2f);
            if (temp_f1_2014 > 0.0f) {
                var_f3_2011 = temp_f1_2014;
            }
            this->unkC8 += var_f3_2011;
        } else if (temp_f2_1992 > 0.8f) {
            var_f3_2030 = 1.0f;
            temp_f0_2032 = 1.05f - ((temp_f2_1992 - 0.8f) / 0.2f);
            if (var_f3_2030 < temp_f0_2032) {

            } else {
                var_f3_2030 = temp_f0_2032;
            }
            this->unkC8 += gUpdateTimeDelta * var_f3_2030;
        } else if (temp_f3_1989 == 0.0f) {
            this->unkC8 += 0.1f * gUpdateTimeDelta;
        } else {
            this->unkC8 += gUpdateTimeDelta;
        }
        temp_f1_2063 = this->unkC8 / this->unkCC;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f1_2063 == 1.0f) {
            arg_sp560 = M2C_FIELD(&cameraPos, f64 *, 0);
            arg_sp568 = M2C_FIELD(&cameraPos, f64 *, 8);
            arg_sp570 = this->unk90;
            arg_sp578 = this->unk98;
            Lerp((MKVector3) &arg_sp580, (MKVector3) &arg_sp570, temp_f1_2063);
            this->unk50 = arg_sp580;
            this->unk58 = arg_sp588;
            if ((u8) this->unkFE != 0) {
                temp_f2_2089 = this->unkCC;
                var_f1_2090 = 2.5f;
                temp_f0_2091 = 0.5f * temp_f2_2089;
                if (var_f1_2090 < temp_f0_2091) {

                } else {
                    var_f1_2090 = temp_f0_2091;
                }
                temp_f30_2098 = temp_f2_2089 - var_f1_2090;
                if (this->unkC8 > temp_f30_2098) {
                    arg_sp540 = M2C_FIELD(&cameraPos, f64 *, 0);
                    arg_sp550 = this->unk90;
                    arg_sp548 = M2C_FIELD(&cameraPos, f64 *, 8);
                    arg_sp558 = this->unk98;
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
                    arg_sp220 = arg_sp110;
                    arg_sp118 = (f32) arg_sp548 - (f32) arg_sp558;
                    arg_sp228 = (f64) arg_sp118;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp210 = arg_sp100;
                    arg_sp108 = (f32) arg_sp228 * (temp_f30_2098 / temp_f2_2089);
                    arg_sp218 = (f64) arg_sp108;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                    arg_sp7A0 = arg_spF0;
                    arg_spF8 = (f32) arg_sp558 + (f32) arg_sp218;
                    arg_sp7A8 = (f64) arg_spF8;
                    arg_sp530.GetTargetStart();
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp790 = arg_sp200;
                    arg_sp208 = arg_sp538 - (f32) arg_sp7A8;
                    arg_sp798 = (f64) arg_sp208;
                    arg_sp790.Normalise();
                    KDMath_NormalisedSlerp(*((MKVector3 *) &arg_sp510), *((MKVector3 *) &arg_sp790), (this->unkC8 - temp_f30_2098) / temp_f30_2098);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0x60) = arg_spE0;
                    arg_spE8 = (f32) M2C_FIELD(this, f64 *, 0x58) + arg_sp518;
                    arg_sp520 = arg_spE0;
                    arg_sp528 = (f64) arg_spE8;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) arg_spE8;
                } else {
                    arg_sp500.GetTargetStart();
                    M2C_FIELD(this, f64 *, 0x60) = arg_sp500;
                    M2C_FIELD(this, f64 *, 0x68) = arg_sp508;
                }
            } else {
                KDMath_NormalisedSlerp(*((MKVector3 *) &arg_sp4E0), *((MKVector3 *) &this->unkA0), this->unkC8 / this->unkCC);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x60) = arg_spD0;
                arg_spD8 = (f32) M2C_FIELD(this, f64 *, 0x58) + arg_sp4E8;
                arg_sp4F0 = arg_spD0;
                arg_sp4F8 = (f64) arg_spD8;
                M2C_FIELD(this, f64 *, 0x68) = (f64) arg_spD8;
            }
        } else {
            arg_sp4B0 = M2C_FIELD(&cameraPos, f64 *, 0);
            arg_sp4B8 = M2C_FIELD(&cameraPos, f64 *, 8);
            arg_sp4C0 = this->unk90;
            arg_sp4C8 = this->unk98;
            Lerp((MKVector3) &arg_sp4D0, (MKVector3) &arg_sp4C0, 1.0f);
            this->unk50 = arg_sp4D0;
            this->unk58 = arg_sp4D8;
            KDMath_NormalisedSlerp(*((MKVector3 *) &arg_sp490), *((MKVector3 *) &this->unkA0), 1.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_FIELD(this, f64 *, 0x60) = arg_spC0;
            arg_spC8 = (f32) M2C_FIELD(this, f64 *, 0x58) + arg_sp498;
            arg_sp4A0 = arg_spC0;
            arg_sp4A8 = (f64) arg_spC8;
            M2C_FIELD(this, f64 *, 0x68) = (f64) arg_spC8;
            FunctionOff();
            this->unkFC = 1;
            this->unkFD = 0;
            this->unkC8 = 0.0f;
        }
        goto block_149;
    }
    if (((s32) gb.unk50 != 2) || ((EventCamera *) this->unkB8 != NULL)) {
        if (((s32) gb.unk50 == 3) && ((EventCamera *) this->unkB8 == NULL)) {
            this->unkF9 = 0;
            FunctionOff();
            if ((u8) this->unkFA == 0) {
                gb.unk30.FadeIn(NULL);
            } else {
                arg_spB0 = 0.0f;
                arg_spB4 = 0.0f;
                arg_spB8 = 0.0f;
                arg_spBC = 1.0f;
                arg_sp480 = (f64) arg_spB0;
                arg_sp488 = (f64) arg_spB8;
                gb.unk40 = (f64) arg_spB0;
                gb.unk48 = (f64) arg_spB8;
            }
            this->unkF9 = 1;
            return;
        }
        temp_r4_2319 = this->unkB4;
        if (temp_r4_2319 != NULL) {
            temp_f1_2322 = this->unkC4;
            temp_f0_2323 = this->unkC0;
            if (temp_f1_2322 < temp_f0_2323) {
                arg_sp2C = 0.0f;
                arg_sp470.GetMeasure(temp_f1_2322 / temp_f0_2323, temp_r4_2319 + 0x7C, KDSpline_PositionMixer);
                M2C_FIELD(this, f64 *, 0x60) = arg_sp470;
                M2C_FIELD(this, f64 *, 0x68) = arg_sp478;
            } else {
                arg_sp28 = 0.0f;
                arg_sp460.GetMeasure(1.0f, temp_r4_2319 + 0x7C, KDSpline_PositionMixer);
                M2C_FIELD(this, f64 *, 0x60) = arg_sp460;
                M2C_FIELD(this, f64 *, 0x68) = arg_sp468;
            }
        } else if (((MKSceneManager *) this->unkF0 != NULL) || ((u8) this->unkFB != 0)) {
            if ((u8) this->unkFB != 0) {
                this->unkF0 = (MKSceneManager *)1;
            }
            if ((u8) this->unk102 != 0) {
                ((SpawnerObject *) (checked_cast<P12EnemySpawner))->GetNumberActive(6MKProp>__FP6MKProp(this->unkF0->PropResolver_Resolve((s32) temp_r4_2319)) + 0x90);
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    arg_sp450.GetTargetStart();
                    var_r30_1504 = 0;
                    M2C_FIELD(this, f64 *, 0x60) = arg_sp450;
                    M2C_FIELD(this, f64 *, 0x68) = arg_sp458;
                }
            } else {
                temp_r3_2388 = this->unkF0->PropResolver_Resolve((s32) temp_r4_2319);
                if (temp_r3_2388 != NULL) {
                    temp_r3_2391 = M2C_FIELD(temp_r3_2388, void **, 8);
                    var_r30_1504 = 0;
                    temp_f0_2393 = M2C_FIELD(temp_r3_2391, f64 *, 0x30);
                    temp_f2_2394 = M2C_FIELD(temp_r3_2391, f64 *, 0x38);
                    arg_sp440 = temp_f0_2393;
                    M2C_FIELD(this, f64 *, 0x60) = temp_f0_2393;
                    M2C_FIELD(this, f64 *, 0x68) = temp_f2_2394;
                    arg_sp448 = temp_f2_2394;
                    this->unk60.unk4 += this->unkEC;
                }
            }
        } else if (((u8) this->unkF5 == 0) && ((void *) this->unkB0 != NULL)) {
            temp_f1_2411 = this->unkC4;
            temp_f0_2412 = this->unkBC;
            if (temp_f1_2411 < temp_f0_2412) {
                if ((EventCamera *) this->unkB8 != NULL) {
                    arg_sp410.GetSourceStart();
                    arg_sp420.GetTargetStart();
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp430 = arg_sp1F0;
                    arg_sp1F8 = arg_sp428 - arg_sp418;
                    arg_sp438 = (f64) arg_sp1F8;
                    temp_f30_2445 = arg_sp430.Magnitude();
                    arg_sp3D0.GetVelocity(this->unkC4 / this->unkBC);
                    arg_sp3E0.operator*(temp_f30_2445);
                    arg_sp1C = 0.0f;
                    arg_sp3F0.GetMeasure(this->unkC4 / this->unkBC, this->unkB0 + 0x7C, KDSpline_PositionMixer);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0x60) = arg_spA0;
                    arg_spA8 = arg_sp3F8 + arg_sp3E8;
                    arg_sp400 = arg_spA0;
                    arg_sp408 = (f64) arg_spA8;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) arg_spA8;
                } else {
                    arg_sp3A0.GetVelocity(temp_f1_2411 / temp_f0_2412);
                    arg_sp18 = 0.0f;
                    arg_sp3B0.GetMeasure(this->unkC4 / this->unkBC, this->unkB0 + 0x7C, KDSpline_PositionMixer);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(this, f64 *, 0x60) = arg_sp90;
                    arg_sp98 = arg_sp3B8 + arg_sp3A8;
                    arg_sp3C0 = arg_sp90;
                    arg_sp3C8 = (f64) arg_sp98;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) arg_sp98;
                }
            } else if ((EventCamera *) this->unkB8 != NULL) {
                arg_sp370.GetSourceStart();
                arg_sp380.GetTargetStart();
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp390 = arg_sp1E0;
                arg_sp1E8 = arg_sp388 - arg_sp378;
                arg_sp398 = (f64) arg_sp1E8;
                temp_f30_2537 = arg_sp390.Magnitude();
                arg_sp330.GetVelocity(1.0f);
                arg_sp340.operator*(temp_f30_2537);
                arg_sp14 = 0.0f;
                arg_sp350.GetMeasure(1.0f, this->unkB0 + 0x7C, KDSpline_PositionMixer);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x60) = arg_sp80;
                arg_sp88 = arg_sp358 + arg_sp348;
                arg_sp360 = arg_sp80;
                arg_sp368 = (f64) arg_sp88;
                M2C_FIELD(this, f64 *, 0x68) = (f64) arg_sp88;
            } else {
                arg_sp300.GetVelocity(1.0f);
                arg_sp10 = 0.0f;
                arg_sp310.GetMeasure(1.0f, this->unkB0 + 0x7C, KDSpline_PositionMixer);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(this, f64 *, 0x60) = arg_sp70;
                arg_sp78 = arg_sp318 + arg_sp308;
                arg_sp320 = arg_sp70;
                arg_sp328 = (f64) arg_sp78;
                M2C_FIELD(this, f64 *, 0x68) = (f64) arg_sp78;
            }
        }
        if ((u8) this->unk103 != 0) {
            if (((u8) this->unk104 != 0) && ((u8) this->unk102 != 0)) {
                temp_r3_2607 = checked_cast<EnemySpawner *, MKProp>(this->unkF0->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
                ((SpawnerObject *) (temp_r3_2607 + 0x90))->GetNumberActive();
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    ((Matrix *) (((SpawnerObject *) (temp_r3_2607 + 0x90))->GetActive(0)->unk8))->ZAxis3();
                    arg_sp30 = -*M2C_ERROR(/* Read from unset register $r3 */);
                    arg_sp34 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
                    arg_sp38 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
                    arg_sp2F0 = (f64) arg_sp30;
                    arg_sp2F8 = (f64) arg_sp38;
                    arg_sp780 = (f64) arg_sp30;
                    arg_sp788 = (f64) arg_sp38;
                }
                arg_sp2D0.operator*(this->unkDC);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                this->unk50 = arg_sp60;
                arg_sp68 = this->unk60.unk8 - arg_sp2D8;
                arg_sp2E0 = arg_sp60;
                this->unk58 = (f64) arg_sp68;
                arg_sp2E8 = (f64) arg_sp68;
                M2C_FIELD(this, f32 *, 0x54) = (f32) (M2C_FIELD(this, f32 *, 0x54) + this->unkE0);
            } else {
                this->unkE8 += this->unkD8 * gUpdateTimeDelta;
                M2C_FIELD(this, f32 *, 0x54) = 0.0f;
                M2C_FIELD(this, f64 *, 0x50) = _table_sinf(0.017453292f * this->unkE8);
                M2C_FIELD(this, f64 *, 0x58) = _table_sinf(1.5707964f + (0.017453292f * this->unkE8));
                this->unk50.Normalise();
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
                M2C_FIELD(this, f64 *, 0x58) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x58) * this->unkDC);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r3, 0x0, qr0 */);
                M2C_FIELD(this, f64 *, 0x58) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x58) + this->unk60.unk8);
                M2C_FIELD(this, f32 *, 0x54) = (f32) (M2C_FIELD(this, f32 *, 0x54) + (this->unkE0 - this->unkEC));
            }
        } else {
            temp_r4_2705 = this->unkB0;
            if (temp_r4_2705 != NULL) {
                temp_f1_2708 = this->unkC4;
                temp_f0_2709 = this->unkBC;
                if (temp_f1_2708 < temp_f0_2709) {
                    arg_sp24 = 0.0f;
                    arg_sp2C0.GetMeasure(temp_f1_2708 / temp_f0_2709, temp_r4_2705 + 0x7C, KDSpline_PositionMixer);
                    this->unk50 = arg_sp2C0;
                    this->unk58 = arg_sp2C8;
                } else {
                    arg_sp20 = 0.0f;
                    arg_sp2B0.GetMeasure(1.0f, temp_r4_2705 + 0x7C, KDSpline_PositionMixer);
                    this->unk50 = arg_sp2B0;
                    this->unk58 = arg_sp2B8;
                }
            }
        }
        if ((EventCamera *) this->unkB8 != NULL) {
            temp_f2_2742 = this->unkBC;
            temp_f1_2743 = this->unkC0;
            if (temp_f2_2742 < temp_f1_2743) {
                var_f1_2747 = temp_f1_2743 - this->unkC4;
            } else {
                var_f1_2747 = temp_f2_2742 - this->unkC4;
            }
            temp_f2_2753 = this->unkD4;
            if ((var_f1_2747 < temp_f2_2753) && (var_f1_2747 > 0.0f)) {
                temp_f30_2761 = (temp_f2_2753 - var_f1_2747) / temp_f2_2753;
                arg_sp290.GetSourceStart();
                InterpolateLinear(*((MKVector3 *) &arg_sp2A0), *((MKVector3 *) &this->unk50), temp_f30_2761);
                this->unk50 = arg_sp2A0;
                this->unk58 = arg_sp2A8;
                arg_sp270.GetTargetStart();
                InterpolateLinear(*((MKVector3 *) &arg_sp280), this->unk60, temp_f30_2761);
                M2C_FIELD(this, f64 *, 0x60) = arg_sp280;
                M2C_FIELD(this, f64 *, 0x68) = arg_sp288;
            }
        }
        temp_r3_2785 = this->unkB0;
        if ((temp_r3_2785 != NULL) || ((void *) this->unkB4 != NULL)) {
            if ((((temp_r3_2785 != NULL) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unkC4 == this->unkBC) != 0))) || (temp_r3_2785 == NULL)) && (((temp_r0_2803 = this->unkB4, ((temp_r0_2803 == NULL) == 0)) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unkC4 == this->unkC0) != 0))) || (temp_r0_2803 == NULL))) {
                temp_r3_2815 = this->unkB8;
                if (temp_r3_2815 != NULL) {
                    temp_r4_2818 = this->unkF9;
                    if ((temp_r4_2818 != 0) && ((s32) gb.unk50 == 0)) {
                        gb.unk30.FadeOut(NULL);
                        goto block_145;
                    }
                    if (temp_r4_2818 != 0) {
                        if (((s32) gb.unk50 == 3) || ((s32) gb.unk50 == 1)) {
                            this->unkF9 = 0;
                            this->unkB8->FunctionOn();
                            if ((u8) this->unkFA == 0) {
                                gb.unk30.FadeIn(NULL);
                            } else {
                                arg_sp50 = 0.0f;
                                arg_sp54 = 0.0f;
                                arg_sp58 = 0.0f;
                                arg_sp5C = 1.0f;
                                arg_sp260 = (f64) arg_sp50;
                                arg_sp268 = (f64) arg_sp58;
                                gb.unk40 = (f64) arg_sp50;
                                gb.unk48 = (f64) arg_sp58;
                            }
                            this->unkF9 = 1;
                            return;
                        }
                        goto block_145;
                    }
                    temp_r3_2815->FunctionOn();
                    return;
                }
                if ((u8) this->unkF9 != 0) {
                    if ((s32) gb.unk50 == 0) {
                        gb.unk30.FadeOut(NULL);
                    }
                } else {
                    FunctionOff();
                }
            } else {
block_145:
                temp_f1_2892 = this->unkC4;
                temp_f2_2893 = this->unkBC;
                if ((temp_f1_2892 < temp_f2_2893) || (temp_f1_2892 < this->unkC0)) {
                    this->unkC4 += gUpdateTimeDelta;
                } else {
                    this->unkC4 = temp_f2_2893;
                }
                goto block_149;
            }
        } else {
block_149:
            arg_sp770 = M2C_FIELD(this, f64 *, 0x60);
            arg_sp778 = M2C_FIELD(this, f64 *, 0x68);
            if (((u8) this->unkFD == 0) && ((u8) this->unk101 == 0) && (var_r30_1504 != 0)) {
                arg_sp774 += this->unkEC;
            }
            arg_sp7D0.SetIdentity();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp250 = arg_sp1D0;
            arg_sp1D8 = (f32) M2C_FIELD(this, f64 *, 0x58) - (f32) arg_sp778;
            arg_sp258 = (f64) arg_sp1D8;
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp7D0, *((MKVector3 *) &arg_sp250), NULL);
            arg_sp800 = (f32) M2C_FIELD(this, f64 *, 0x50);
            arg_sp804 = M2C_FIELD(this, f32 *, 0x54);
            arg_sp808 = (f32) M2C_FIELD(this, f64 *, 0x58);
            arg_sp80C = 1.0f;
            arg_sp814 = 0;
            arg_sp810.Init(*((Matrix *) &arg_sp7D0));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp810);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P24GetNearestEventCameraMsg'
void EventCamera::Message(MKMessage *arg0) {
    FuryEventCameraMsg *temp_r3_3058;
    s32 temp_r0_3028;

    temp_r0_3028 = arg0->unk0;
    switch (temp_r0_3028) {                         /* irregular */
    case 0xB5:
        FunctionOn();
    default:
block_16:
        MKProp::Message(arg0);
        return;
    case 0xB4:
        FunctionOff();
        goto block_16;
    case 0x8C:
        ((GetNearestEventCameraMsg *) (checked_cast<P24GetNearestEventCameraMsg))->Test(9MKMessage>__FP9MKMessage(arg0), *((MKProp *) this), &this->unk60);
        return;
    case 0xA2:
        temp_r3_3058 = checked_cast<FuryEventCameraMsg *, MKMessage>(arg0);
        if ((u8) this->unkFB != 0) {
            temp_r3_3058->AddCamera(this);
        }
        /* fallthrough */
    case 0x153:
        if ((EventCamera *) pCurrentCamera == this) {
            this->unk108 = gb.unk2CC.Enable((f32) atof(M2C_FIELD(checked_cast<SendArgMessage *, MKMessage>(arg0), s32 *, 0xC)), 0.0f, 0.0f, -1.0f);
        }
        goto block_16;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34C'
void EventCamera::Reset() {
    f64 sp40;
    f64 sp38;
    s32 sp34;
    s32 sp30;
    s8 sp28;
    s32 sp24;
    s32 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_3128;

    MKProp::Reset();
    if ((s32) gb.unk34C != 0) {
        if (this->unk18 & 0x80000000) {
            return;
        }
        gb.unk2CC.Disable(this->unk108);
        Disable();
        if ((HeroInterface *) gb.unk0 != NULL) {
            temp_r3_3128 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
            spC = 0;
            sp8 = 0xAA;
            M2C_FIELD(M2C_FIELD(temp_r3_3128, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        if (M2C_FIELD(gb.unk0->__vptr, s32 (**)(HeroInterface *), 8)(gb.unk0) == 0) {
            gb.GetSpyro();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetInvincibilityTimeOut(0.0f);
            }
        }
        this->unkC4 = 0.0f;
        if ((EventCamera *) pCurrentCamera == this) {
            sp24 = 0;
            sp20 = 0x403;
            sp28 = 1;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp20, 0x403);
            sp34 = 0;
            sp30 = 0x44D;
            sp38 = M2C_FIELD(&InitialCameraPos, f64 *, 0);
            sp40 = M2C_FIELD(&InitialCameraPos, f64 *, 8);
            sp10 = M2C_FIELD(&InitialCameraPos, f64 *, 0);
            sp18 = M2C_FIELD(&InitialCameraPos, f64 *, 8);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp30, 0, M2C_FIELD(&InitialCameraPos, f64 *, 0));
            M2C_FIELD(gb.unk0->__vptr, M2C_UNK (**)(HeroInterface *), 0x20)(gb.unk0);
            Hud_Show(1U);
            pCurrentCamera = NULL;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void EventCamera::Resolve() {
    EventCamera *temp_r3_3237;
    void *temp_r3_3223;
    void *temp_r3_3230;

    MKProp::Resolve();
    temp_r3_3223 = this->unkB0;
    if (temp_r3_3223 != NULL) {
        this->unkB0 = checked_cast<KDSplinePathSegmentProp *, MKProp>(temp_r3_3223->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    }
    temp_r3_3230 = this->unkB4;
    if (temp_r3_3230 != NULL) {
        this->unkB4 = checked_cast<KDSplinePathSegmentProp *, MKProp>(temp_r3_3230->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    }
    temp_r3_3237 = this->unkB8;
    if (temp_r3_3237 != NULL) {
        this->unkB8 = checked_cast<EventCamera *, MKProp>(temp_r3_3237->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
    }
    if ((u8) this->unkFB != 0) {
        this->unkF0 = (MKSceneManager *)1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp24'
void EventCamera::LoadDone() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    f32 var_f4_3292;
    f64 temp_f1_3295;
    f64 temp_f1_3301;
    f64 temp_f1_3305;
    s32 temp_r3_3324;
    s32 var_r0_3334;

    MKProp::LoadDone();
    Disable();
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp20 = sp10;
    sp18 = M2C_FIELD(this, f32 *, 0x58) - this->unk60.unk8;
    sp28 = (f64) sp18;
    var_f4_3292 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
    if (var_f4_3292 > 0.0f) {
        temp_f1_3295 = __frsqrte(var_f4_3292);
        temp_f1_3301 = 0.5 * temp_f1_3295 * -(((f64) var_f4_3292 * (temp_f1_3295 * temp_f1_3295)) - 3.0);
        temp_f1_3305 = 0.5 * temp_f1_3301 * -(((f64) var_f4_3292 * (temp_f1_3301 * temp_f1_3301)) - 3.0);
        var_f4_3292 = (f32) ((f64) var_f4_3292 * (0.5 * temp_f1_3305 * -(((f64) var_f4_3292 * (temp_f1_3305 * temp_f1_3305)) - 3.0)));
    } else if (var_f4_3292 < M2C_BITWISE(f32, 0.0)) {
        var_f4_3292 = __float_nan;
    } else {
        sp8 = var_f4_3292;
        temp_r3_3324 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_3324) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3334 = 1;
            } else {
                var_r0_3334 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3334 = 5;
            } else {
                var_r0_3334 = 3;
            }
            break;
        default:
            var_r0_3334 = 4;
            break;
        }
        if (var_r0_3334 == 1) {
            var_f4_3292 = __float_nan;
        }
    }
    if (var_f4_3292 < 0.0f) {
        var_f4_3292 = -var_f4_3292;
    }
    if (var_f4_3292 < 1.0f) {
        this->unkF5 = 0;
    } else {
        this->unkF5 = 1;
    }
    this->unkDC *= 100.0f;
    this->unkE0 *= 100.0f;
    this->unkEC *= 100.0f;
    this->unkE8 = this->unkE4;
    this->unk70 = this->unk50;
    this->unk78 = this->unk58;
    this->unk80 = M2C_FIELD(this, f64 *, 0x60);
    this->unk88 = (f64) M2C_FIELD(this, f32 *, 0x68);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
s32 EventCamera::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r29_3675;

    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt(lit_stringBase0, (s32 *) &this->unkF0, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[9], &this->unkF4, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x1E], &this->unkF6, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x28], &this->unkF7, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x43], &this->unkF8, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x67], &this->unkF9, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x73], &this->unkFA, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0x83], (s32 *) &this->unkB0, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x92], &this->unkBC, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0xA3], (s32 *) &this->unkB4, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0xB2], &this->unkC0, 0) != 0) || (arg0->LoadInt(&lit_stringBase0[0xC3], (s32 *) &this->unkB8, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0xD7], &this->unkD4, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0xF3], &this->unkFB, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0xFE], &this->unk102, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x10A], &this->unk103, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x117], &this->unk104, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x139], &this->unkD8, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x14B], &this->unkDC, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x15E], &this->unkE0, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x16C], &this->unkEC, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x17A], &this->unkE4, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x18B], &this->unkFC, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x1A2], &this->unkFE, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x1C3], &this->unkFF, 0) != 0) || (arg0->LoadBool(&lit_stringBase0[0x1DF], &this->unk100, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x205], &this->unkCC, 0) != 0) || (arg0->LoadFloat(&lit_stringBase0[0x220], &this->unkD0, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField(&lit_stringBase0[0x240]) != 0) {
        var_r29_3675 = arg0->unkC->GetSubLine(arg0);
loop_35:
        if (var_r29_3675 != NULL) {
            if (var_r29_3675->LoadVector3(&lit_stringBase0[0x247], (MKVector3 *) &this->unk50, 0) == 0) {
                var_r29_3675->LoadVector3(&lit_stringBase0[0x254], &this->unk60, 0);
            }
            var_r29_3675 = var_r29_3675->unkC->GetNextLine(var_r29_3675);
            goto loop_35;
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EventCamera::Deinit() {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x20)();
    MKProp::Deinit();
}
#endif

void EventCamera::Init() {
    MKProp::Init();
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
    this->unk60.unk0 = 0.0f;
    this->unk60.unk4 = 0.0f;
    this->unk60.unk8 = 0.0f;
    this->unkF0 = NULL;
    this->unkF4 = 1;
    this->unkF5 = 0;
    this->unkF6 = 0;
    this->unkF7 = 0;
    this->unkF8 = 0;
    this->unkF9 = 0;
    this->unkFA = 0;
    this->unkFB = 0;
    this->unk102 = 0;
    this->unk103 = 0;
    this->unk104 = 0;
    this->unkFC = 0;
    this->unkFD = 0;
    this->unkFE = 0;
    this->unkFF = 0;
    this->unk101 = 0;
    this->unk100 = 0;
    this->unkB0 = NULL;
    this->unkB4 = NULL;
    this->unkB8 = NULL;
    this->unkE0 = 0.0f;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 0.0f;
    this->unkBC = 0.0f;
    this->unkC0 = 0.0f;
    this->unkC4 = 0.0f;
    this->unkCC = 1.0f;
    this->unkC8 = 0.0f;
    this->unkD0 = 0.0f;
    this->unk108 = -1;
}

void EventCameraDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unkC = 0x10000;
}

EventCamera *EventCamera_GetCurrent() {
    return pCurrentCamera;
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<EnemySpawner *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<FuryEventCameraMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<GetNearestEventCameraMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

void EventCamera_cpp::__sinit() {
    f32 temp_f0_3870;
    f64 temp_f1_3851;
    f64 temp_f1_3859;
    f64 temp_f3_3839;
    f64 temp_f4_3848;
    f64 temp_f4_3856;
    f64 temp_f8_3841;

    temp_f3_3839 = __frsqrte(2014000.0);
    temp_f8_3841 = __frsqrte(380000.0);
    temp_f4_3848 = 0.5 * temp_f3_3839 * -((2014000.0 * (temp_f3_3839 * temp_f3_3839)) - 3.0);
    temp_f1_3851 = 0.5 * temp_f8_3841 * -((380000.0 * (temp_f8_3841 * temp_f8_3841)) - 3.0);
    temp_f4_3856 = 0.5 * temp_f4_3848 * -((2014000.0 * (temp_f4_3848 * temp_f4_3848)) - 3.0);
    temp_f1_3859 = 0.5 * temp_f1_3851 * -((380000.0 * (temp_f1_3851 * temp_f1_3851)) - 3.0);
    temp_f0_3870 = (f32) (380000.0 * (0.5 * temp_f1_3859 * -((380000.0 * (temp_f1_3859 * temp_f1_3859)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_3856 * -((2014000.0 * (temp_f4_3856 * temp_f4_3856)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_3870;
}

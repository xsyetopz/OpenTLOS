#include "spyro/source/FlyingChunkPS.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GamePropColored.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(Matrix **);                            /* extern */
Matrix **malloc(s32);                               /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: illegal implicit conversion from 'FlyingChunkPSDescriptor *' to
void FlyingChunkPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, float arg4, const MKVector4 &arg5, int arg6, MKProp *arg7) {
    MKHeap **temp_r3_94;
    MKHeap *temp_r5_67;
    Matrix **temp_r3_50;
    Matrix **temp_r3_59;
    Matrix *temp_r31_61;
    f32 temp_f1_134;
    f32 temp_f2_133;
    f32 temp_f3_135;
    f32 temp_f5_108;
    f32 temp_f6_105;
    f32 temp_f7_213;
    f32 temp_f8_113;
    f32 temp_f8_212;
    f32 temp_f9_218;
    f32 var_f2_243;
    f32 var_f3_207;
    f32 var_f4_140;
    f32 var_f4_252;
    f64 temp_f1_146;
    f64 temp_f1_152;
    f64 temp_f1_156;
    f64 temp_f1_255;
    f64 temp_f1_261;
    f64 temp_f1_265;
    s32 temp_r3_175;
    s32 temp_r3_284;
    s32 var_r0_185;
    s32 var_r0_294;
    temp_r3_50 = this->unkD8;
    if ((u32) M2C_FIELD(temp_r3_50, u32 *, -4) != 0U) {
        temp_r3_59 = temp_r3_50 - 4;
        this->unkD8 = temp_r3_59;
        temp_r31_61 = *temp_r3_59;
        if (temp_r31_61 != NULL) {
            temp_r5_67 = checked_cast<FlyingChunkPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            M2C_FIELD(temp_r31_61, f64 *, 0x40) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r31_61, f64 *, 0x48) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r31_61, f64 *, 0x50) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r31_61, f64 *, 0x58) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r31_61, f32 *, 0x84) = (f32) temp_r5_67->unkF0;
            M2C_FIELD(temp_r31_61, f32 *, 0x88) = arg4;
            M2C_FIELD(temp_r31_61, s32 *, 0x94) = MKRand_Int(&gViewSeed, 0, temp_r5_67->unkEC);
            M2C_FIELD(temp_r31_61, f64 *, 0x60) = (f64) M2C_FIELD(&arg5, f64 *, 0);
            M2C_FIELD(temp_r31_61, f64 *, 0x68) = (f64) M2C_FIELD(&arg5, f64 *, 8);
            M2C_FIELD(temp_r31_61, s8 *, 0x9D) = 0;
            M2C_FIELD(temp_r31_61, s32 *, 0x98) = arg6;
            M2C_FIELD(temp_r31_61, MKProp **, 0x80) = arg7;
            temp_r3_94 = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r31_61, s32 *, 0x94));
            arg_sp30 = 0.0f;
            arg_sp28 = 0.0f;
            M2C_FIELD(temp_r31_61, f32 *, 0x90) = (f32) M2C_FIELD(temp_r3_94, f32 *, 0xC);
            arg_sp2C = -1.0f;
            temp_f6_105 = M2C_FIELD(temp_r31_61, f32 *, 0x54);
            arg_sp80 = (f64) arg_sp30;
            temp_f5_108 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x58);
            arg_sp78 = (f64) arg_sp28;
            temp_f8_113 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x50);
            arg_sp18 = (temp_f6_105 * (f32) arg_sp80) - (temp_f5_108 * arg_sp7C);
            arg_sp1C = (temp_f5_108 * (f32) arg_sp78) - (temp_f8_113 * (f32) arg_sp80);
            arg_sp20 = (temp_f8_113 * arg_sp7C) - (temp_f6_105 * (f32) arg_sp78);
            arg_sp88 = (f64) arg_sp18;
            arg_sp90 = (f64) arg_sp20;
            Normalise(*((MKVector3 *) &arg_sp98));
            M2C_FIELD(temp_r31_61, f64 *, 0x70) = arg_sp98;
            M2C_FIELD(temp_r31_61, f64 *, 0x78) = arg_spA0;
            temp_f2_133 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x50);
            temp_f1_134 = M2C_FIELD(temp_r31_61, f32 *, 0x54);
            temp_f3_135 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x58);
            var_f4_140 = (temp_f3_135 * temp_f3_135) + ((temp_f2_133 * temp_f2_133) + (temp_f1_134 * temp_f1_134));
            if (var_f4_140 > 1e-12f) {
                if (var_f4_140 > 0.0f) {
                    temp_f1_146 = __frsqrte(var_f4_140);
                    temp_f1_152 = 0.5 * temp_f1_146 * -(((f64) var_f4_140 * (temp_f1_146 * temp_f1_146)) - 3.0);
                    temp_f1_156 = 0.5 * temp_f1_152 * -(((f64) var_f4_140 * (temp_f1_152 * temp_f1_152)) - 3.0);
                    var_f4_140 = (f32) ((f64) var_f4_140 * (0.5 * temp_f1_156 * -(((f64) var_f4_140 * (temp_f1_156 * temp_f1_156)) - 3.0)));
                } else if (var_f4_140 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_140 = __float_nan;
                } else {
                    arg_sp14 = var_f4_140;
                    temp_r3_175 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                    switch (temp_r3_175) {          /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                            var_r0_185 = 1;
                        } else {
                            var_r0_185 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                            var_r0_185 = 5;
                        } else {
                            var_r0_185 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_185 = 4;
                        break;
                    }
                    if (var_r0_185 == 1) {
                        var_f4_140 = __float_nan;
                    }
                }
                var_f3_207 = 1.0f / var_f4_140;
            } else {
                var_f3_207 = 0.0f;
            }
            temp_f8_212 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x50);
            temp_f7_213 = M2C_FIELD(temp_r31_61, f32 *, 0x54);
            temp_f9_218 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x58);
            arg_sp38 = temp_f8_212 * var_f3_207;
            arg_sp3C = temp_f7_213 * var_f3_207;
            arg_sp48 = 1.0f;
            arg_sp58 = (f64) arg_sp38;
            arg_sp4C = -1.0f;
            arg_sp40 = temp_f9_218 * var_f3_207;
            arg_sp68 = (f64) arg_sp48;
            arg_sp50 = 0.0f;
            arg_sp60 = (f64) arg_sp40;
            arg_sp70 = (f64) arg_sp50;
            var_f2_243 = ((f32) arg_sp70 * (f32) arg_sp60) + (((f32) arg_sp68 * (f32) arg_sp58) + (arg_sp6C * arg_sp5C));
            if (var_f2_243 < 0.0f) {
                var_f2_243 = -var_f2_243;
            }
            var_f4_252 = (temp_f9_218 * temp_f9_218) + ((temp_f8_212 * temp_f8_212) + (temp_f7_213 * temp_f7_213));
            if (var_f4_252 > 0.0f) {
                temp_f1_255 = __frsqrte(var_f4_252);
                temp_f1_261 = 0.5 * temp_f1_255 * -(((f64) var_f4_252 * (temp_f1_255 * temp_f1_255)) - 3.0);
                temp_f1_265 = 0.5 * temp_f1_261 * -(((f64) var_f4_252 * (temp_f1_261 * temp_f1_261)) - 3.0);
                var_f4_252 = (f32) ((f64) var_f4_252 * (0.5 * temp_f1_265 * -(((f64) var_f4_252 * (temp_f1_265 * temp_f1_265)) - 3.0)));
            } else if (var_f4_252 < M2C_BITWISE(f32, 0.0)) {
                var_f4_252 = __float_nan;
            } else {
                arg_sp10 = var_f4_252;
                temp_r3_284 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_284) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_294 = 1;
                    } else {
                        var_r0_294 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_294 = 5;
                    } else {
                        var_r0_294 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_294 = 4;
                    break;
                }
                if (var_r0_294 == 1) {
                    var_f4_252 = __float_nan;
                }
            }
            M2C_FIELD(temp_r31_61, f32 *, 0x8C) = (f32) (2.5f * ((1.0f - var_f2_243) * (gUpdateTimeDelta * (var_f4_252 / (0.7853982f * M2C_FIELD(temp_r31_61, f32 *, 0x90))))));
            M2C_STRUCT_COPY(temp_r31_61, &identity, 0x40);
            temp_r31_61->Scale3x3(temp_r31_61, M2C_FIELD(temp_r31_61, f32 *, 0x88));
            arg_spB0.SetRotateAroundAxis(*(temp_r31_61 + 0x70), M2C_FIELD(temp_r31_61, f32 *, 0x8C));
            temp_r31_61->Multiply3x3(temp_r31_61, (Matrix *) &arg_spB0);
            temp_r31_61->unk30 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x40);
            temp_r31_61->unk34 = M2C_FIELD(temp_r31_61, f32 *, 0x44);
            temp_r31_61->unk38 = (f32) M2C_FIELD(temp_r31_61, f64 *, 0x48);
            temp_r31_61->unk3C = 1.0f;
        }
    }
}
#endif

#if 0 // DRAFT: type mismatch
void FlyingChunkPS::Deinit() {
    MKHeap *temp_r3_403;
    Matrix **var_r31_377;
    Matrix **var_r3_378;
    Matrix **var_r4_376;
    Matrix *temp_r0_381;
    Matrix *temp_r0_400;
    u32 temp_r0_386;

    var_r4_376 = this->unkD8;
    var_r31_377 = var_r4_376;
    var_r3_378 = var_r4_376;
loop_3:
    temp_r0_386 = M2C_FIELD(var_r3_378, u32 *, -4);
    var_r3_378 -= 4;
    if (temp_r0_386 != 0U) {
        temp_r0_381 = *var_r3_378;
        if (temp_r0_381 < var_r31_377) {
            var_r31_377 = (Matrix **) temp_r0_381;
        }
        goto loop_3;
    }
    if (var_r3_378 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_400 = *var_r4_376;
        if (temp_r0_400 != NULL) {
            if (temp_r0_400 < var_r31_377) {
                var_r31_377 = (Matrix **) temp_r0_400;
            }
            var_r4_376 += 4;
            goto loop_9;
        }
        temp_r3_403 = var_r3_378->Current();
        if (temp_r3_403 != NULL) {
            ((MKHeap *) (temp_r3_403->Current()))->Free(var_r31_377, NULL, 0);
        } else {
            free(var_r31_377);
        }
    }
    this->unkD8 = NULL;
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void FlyingChunkPS::Draw() {
    Matrix **var_r30_438;
    Matrix *temp_r31_470;
    var_r30_438 = this->unkD8;
loop_2:
    if (var_r30_438 != NULL) {
        temp_r31_470 = *var_r30_438;
        if (temp_r31_470 != NULL) {
            M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (temp_r31_470 - 4) + 4, 0x40);
            MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r31_470, s32 *, 0x94), 1U, 1U);
            MKModel_SetColor(this->unk4, *(temp_r31_470 + 0x60));
            MKModel_Draw(this->unk4, NULL);
            var_r30_438 += 4;
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FlyingChunkPSDescriptor *' to
void FlyingChunkPS::Update() {
    MKHeap *temp_r30_526;
    Matrix **temp_r3_607;
    Matrix **var_r27_524;
    Matrix *temp_r28_1998;
    Matrix *temp_r4_610;
    f32 temp_f0_1147;
    f32 temp_f18_1821;
    f32 temp_f1_1060;
    f32 temp_f1_1146;
    f32 temp_f1_1337;
    f32 temp_f1_1529;
    f32 temp_f1_1638;
    f32 temp_f1_752;
    f32 temp_f1_951;
    f32 temp_f27_1857;
    f32 temp_f28_1918;
    f32 temp_f2_1336;
    f32 temp_f2_1499;
    f32 temp_f2_1528;
    f32 temp_f2_533;
    f32 temp_f2_751;
    f32 temp_f2_932;
    f32 temp_f2_950;
    f32 temp_f3_1058;
    f32 temp_f3_1149;
    f32 temp_f3_1339;
    f32 temp_f3_1530;
    f32 temp_f3_1636;
    f32 temp_f3_952;
    f32 temp_f4_1062;
    f32 temp_f4_1640;
    f32 temp_f4_753;
    f32 temp_f5_915;
    f32 temp_f6_1497;
    f32 temp_f6_917;
    f32 temp_f8_1495;
    f32 var_f0_534;
    f32 var_f0_564;
    f32 var_f19_1343;
    f32 var_f19_759;
    f32 var_f1_1409;
    f32 var_f1_582;
    f32 var_f2_1053;
    f32 var_f2_1631;
    f32 var_f3_1223;
    f32 var_f4_1024;
    f32 var_f4_1156;
    f32 var_f4_1535;
    f32 var_f4_1602;
    f32 var_f4_1741;
    f32 var_f4_826;
    f32 var_f4_957;
    f32 var_f5_1067;
    f32 var_f5_1645;
    f64 temp_f1_1162;
    f64 temp_f1_1168;
    f64 temp_f1_1172;
    f64 temp_f1_1349;
    f64 temp_f1_1355;
    f64 temp_f1_1359;
    f64 temp_f1_1541;
    f64 temp_f1_1547;
    f64 temp_f1_1551;
    f64 temp_f1_1744;
    f64 temp_f1_1750;
    f64 temp_f1_1754;
    f64 temp_f1_765;
    f64 temp_f1_771;
    f64 temp_f1_775;
    f64 temp_f1_963;
    f64 temp_f1_969;
    f64 temp_f1_973;
    f64 temp_f2_1070;
    f64 temp_f2_1076;
    f64 temp_f2_1080;
    f64 temp_f2_1315;
    f64 temp_f2_1648;
    f64 temp_f2_1654;
    f64 temp_f2_1658;
    f64 temp_f3_1314;
    s32 temp_r26_1815;
    s32 temp_r3_1099;
    s32 temp_r3_1191;
    s32 temp_r3_1378;
    s32 temp_r3_1570;
    s32 temp_r3_1677;
    s32 temp_r3_1773;
    s32 temp_r3_794;
    s32 temp_r3_992;
    s32 var_r0_1002;
    s32 var_r0_1109;
    s32 var_r0_1201;
    s32 var_r0_1580;
    s32 var_r0_1687;
    s32 var_r0_1783;
    s32 var_r0_804;
    s32 var_r25_1807;
    s32 var_r4_1333;
    void *var_r3_1287;
    var_r27_524 = this->unkD8;
    temp_r30_526 = checked_cast<FlyingChunkPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
loop_208:
    if (var_r27_524 != NULL) {
        temp_r28_1998 = *var_r27_524;
        if (temp_r28_1998 != NULL) {
            temp_f2_533 = temp_r30_526->unkF0;
            var_f0_534 = M2C_FIELD(temp_r28_1998, f32 *, 0x84) - gUpdateTimeDelta;
            if (var_f0_534 < temp_f2_533) {

            } else {
                var_f0_534 = temp_f2_533;
            }
            if (var_f0_534 > 0.0f) {

            } else {
                var_f0_534 = 0.0f;
            }
            M2C_FIELD(temp_r28_1998, f32 *, 0x84) = var_f0_534;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r28_1998, f32 *, 0x84) == 0.0f) {
                if ((u8) M2C_FIELD(temp_r28_1998, u8 *, 0x9C) == 0) {
                    M2C_FIELD(temp_r28_1998, u8 *, 0x9C) = 1U;
                    goto block_24;
                }
                var_f0_564 = -((2.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r28_1998, f32 *, 0x6C));
                if (var_f0_564 < 1.0f) {

                } else {
                    var_f0_564 = 1.0f;
                }
                if (var_f0_564 > 0.0f) {

                } else {
                    var_f0_564 = 0.0f;
                }
                M2C_FIELD(temp_r28_1998, f32 *, 0x6C) = var_f0_564;
                arg_sp4A8.NormaliseScale();
                var_f1_582 = M2C_FIELD(temp_r28_1998, f32 *, 0x6C);
                if (var_f1_582 < 1.0f) {

                } else {
                    var_f1_582 = 1.0f;
                }
                if (var_f1_582 > 0.01f) {

                } else {
                    var_f1_582 = 0.01f;
                }
                temp_r28_1998->Scale3x3(temp_r28_1998, M2C_FIELD(temp_r28_1998, f32 *, 0x88) * var_f1_582);
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r28_1998, f32 *, 0x6C) == 0.0f) {
                    temp_r3_607 = this->unkD8;
                    this->unkD8 = temp_r3_607 + 4;
                    temp_r4_610 = *temp_r3_607;
                    *temp_r3_607 = *var_r27_524;
                    *var_r27_524 = temp_r4_610;
                } else {
                    goto block_24;
                }
            } else {
block_24:
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
                arg_sp498 = arg_spF8;
                arg_sp100 = temp_r30_526->unk100 * gUpdateTimeDelta;
                arg_sp4A0 = (f64) arg_sp100;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
                M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x58) + (f32) arg_sp4A0);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f21 */);
                arg_sp488 = arg_sp228;
                arg_sp230 = M2C_FIELD(temp_r28_1998, f32 *, 0x58) * gUpdateTimeDelta;
                arg_sp490 = (f64) arg_sp230;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp4D8 = arg_sp218;
                arg_sp220 = M2C_FIELD(temp_r28_1998, f32 *, 0x48) + (f32) arg_sp490;
                arg_sp4E0 = (f64) arg_sp220;
                if ((u8) M2C_FIELD(temp_r30_526, u8 *, 0xF4) != 0) {
                    arg_sp570 = 0.0f;
                    arg_sp574 = 0.0f;
                    arg_sp578 = 0.0f;
                    arg_sp580 = 0.0f;
                    arg_sp584 = 0.0f;
                    arg_sp588 = 0.0f;
                    arg_sp590 = 0.0f;
                    arg_sp594 = 0.0f;
                    arg_sp598 = 0.0f;
                    arg_sp59C = 1.0f;
                    arg_sp5A0 = 0.0f;
                    arg_sp5A4 = 0.0f;
                    arg_sp5A8 = 0;
                    arg_sp5A8 = 0;
                    (s8) arg_sp5A8 = 0;
                    arg_sp5AC = 0;
                    arg_sp5B0 = 3.4028235e38f;
                    arg_sp5B4 = 0;
                    arg_sp5B8 = NULL;
                    arg_sp5BC = -1;
                    arg_sp5C0 = 0U;
                    if ((u8) M2C_FIELD(temp_r28_1998, u8 *, 0x9D) != 0) {
                        arg_sp210 = 0.0f;
                        arg_sp208 = 0.0f;
                        arg_sp20C = -((M2C_FIELD(temp_r28_1998, f32 *, 0x90) * M2C_FIELD(temp_r28_1998, f32 *, 0x88)) + 2.0f);
                        arg_sp470 = (f64) arg_sp210;
                        arg_sp468 = (f64) arg_sp208;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp478 = arg_sp1F8;
                        arg_sp200 = (f32) arg_sp4E0 + (f32) arg_sp470;
                        arg_sp480 = (f64) arg_sp200;
                        if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp4D8), *((MKVector3 *) &arg_sp478), (MKCollisionResult *) &arg_sp570, (MKCollisionMode) 7, 0x08000000) != 0) {
                            MKVector(0.0f, 1.0f, 0.0f);
                            arg_sp448.operator*(M2C_FIELD(temp_r28_1998, f32 *, 0x90) * M2C_FIELD(temp_r28_1998, f32 *, 0x88));
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            arg_sp4D8 = arg_spE8;
                            arg_spF0 = arg_sp578 + arg_sp450;
                            arg_sp458 = arg_spE8;
                            arg_sp4E0 = (f64) arg_spF0;
                            temp_f2_751 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            temp_f1_752 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f4_753 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            arg_sp460 = (f64) arg_spF0;
                            var_f19_759 = (temp_f4_753 * temp_f4_753) + ((temp_f2_751 * temp_f2_751) + (temp_f1_752 * temp_f1_752));
                            if (var_f19_759 > 0.000001f) {
                                if (var_f19_759 > 0.0f) {
                                    temp_f1_765 = __frsqrte(var_f19_759);
                                    temp_f1_771 = 0.5 * temp_f1_765 * -(((f64) var_f19_759 * (temp_f1_765 * temp_f1_765)) - 3.0);
                                    temp_f1_775 = 0.5 * temp_f1_771 * -(((f64) var_f19_759 * (temp_f1_771 * temp_f1_771)) - 3.0);
                                    var_f19_759 = (f32) ((f64) var_f19_759 * (0.5 * temp_f1_775 * -(((f64) var_f19_759 * (temp_f1_775 * temp_f1_775)) - 3.0)));
                                } else if (var_f19_759 < M2C_BITWISE(f32, 0.0)) {
                                    var_f19_759 = __float_nan;
                                } else {
                                    arg_sp2C = var_f19_759;
                                    temp_r3_794 = M2C_BITWISE(s32, arg_sp2C) & 0x7F800000;
                                    switch (temp_r3_794) { /* switch 1; irregular */
                                    case 0x7F800000: /* switch 1 */
                                        if (M2C_BITWISE(s32, arg_sp2C) & 0x7FFFFF) {
                                            var_r0_804 = 1;
                                        } else {
                                            var_r0_804 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 1 */
                                        if (M2C_BITWISE(s32, arg_sp2C) & 0x7FFFFF) {
                                            var_r0_804 = 5;
                                        } else {
                                            var_r0_804 = 3;
                                        }
                                        break;
                                    default:        /* switch 1 */
                                        var_r0_804 = 4;
                                        break;
                                    }
                                    if (var_r0_804 == 1) {
                                        var_f19_759 = __float_nan;
                                    }
                                }
                                var_f4_826 = 1.0f / var_f19_759;
                            } else {
                                var_f4_826 = 0.0f;
                                var_f19_759 = 0.0f;
                            }
                            M2C_FIELD(temp_r28_1998, f32 *, 0x50) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x50) * var_f4_826);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x54) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x54) * var_f4_826);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x58) * var_f4_826);
                            MKVector(0.0f, 1.0f, 0.0f);
                            arg_sp60 = (arg_sp3F8 * arg_sp584) - (arg_sp3FC * arg_sp580);
                            arg_sp5C = (arg_sp400 * arg_sp580) - (arg_sp3F8 * arg_sp588);
                            arg_sp58 = (arg_sp3FC * arg_sp588) - (arg_sp400 * arg_sp584);
                            arg_sp410 = (f64) arg_sp60;
                            arg_sp408 = (f64) arg_sp58;
                            arg_sp48 = (arg_sp40C * arg_sp588) - ((f32) arg_sp410 * arg_sp584);
                            arg_sp4C = ((f32) arg_sp410 * arg_sp580) - ((f32) arg_sp408 * arg_sp588);
                            arg_sp50 = ((f32) arg_sp408 * arg_sp584) - (arg_sp40C * arg_sp580);
                            arg_sp418 = (f64) arg_sp48;
                            arg_sp420 = (f64) arg_sp50;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                            arg_sp428 = arg_spD8;
                            arg_spE0 = (f32) arg_sp420 * 0.5f;
                            arg_sp430 = (f64) arg_spE0;
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x58) + (f32) arg_sp430);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
                            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x58) * (0.75f * var_f19_759));
                            temp_f5_915 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            temp_f6_917 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            arg_spC8 = -arg_sp580;
                            arg_spCC = -arg_sp584;
                            arg_spD0 = -arg_sp588;
                            arg_sp3C8 = (f64) arg_spC8;
                            arg_sp3D0 = (f64) arg_spD0;
                            arg_spB8 = (temp_f6_917 * (f32) arg_sp3D0) - (temp_f5_915 * arg_sp3CC);
                            temp_f2_932 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            arg_spC0 = (temp_f2_932 * arg_sp3CC) - (temp_f6_917 * (f32) arg_sp3C8);
                            arg_spBC = (temp_f5_915 * (f32) arg_sp3C8) - (temp_f2_932 * (f32) arg_sp3D0);
                            arg_sp3E0 = (f64) arg_spC0;
                            arg_sp3D8 = (f64) arg_spB8;
                            Normalise(*((MKVector3 *) &arg_sp3E8));
                            M2C_FIELD(temp_r28_1998, f64 *, 0x70) = arg_sp3E8;
                            M2C_FIELD(temp_r28_1998, f64 *, 0x78) = arg_sp3F0;
                            temp_f2_950 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            temp_f1_951 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f3_952 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            var_f4_957 = (temp_f3_952 * temp_f3_952) + ((temp_f2_950 * temp_f2_950) + (temp_f1_951 * temp_f1_951));
                            if (var_f4_957 > 1e-12f) {
                                if (var_f4_957 > 0.0f) {
                                    temp_f1_963 = __frsqrte(var_f4_957);
                                    temp_f1_969 = 0.5 * temp_f1_963 * -(((f64) var_f4_957 * (temp_f1_963 * temp_f1_963)) - 3.0);
                                    temp_f1_973 = 0.5 * temp_f1_969 * -(((f64) var_f4_957 * (temp_f1_969 * temp_f1_969)) - 3.0);
                                    var_f4_957 = (f32) ((f64) var_f4_957 * (0.5 * temp_f1_973 * -(((f64) var_f4_957 * (temp_f1_973 * temp_f1_973)) - 3.0)));
                                } else if (var_f4_957 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_957 = __float_nan;
                                } else {
                                    arg_sp28 = var_f4_957;
                                    temp_r3_992 = M2C_BITWISE(s32, arg_sp28) & 0x7F800000;
                                    switch (temp_r3_992) { /* switch 2; irregular */
                                    case 0x7F800000: /* switch 2 */
                                        if (M2C_BITWISE(s32, arg_sp28) & 0x7FFFFF) {
                                            var_r0_1002 = 1;
                                        } else {
                                            var_r0_1002 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 2 */
                                        if (M2C_BITWISE(s32, arg_sp28) & 0x7FFFFF) {
                                            var_r0_1002 = 5;
                                        } else {
                                            var_r0_1002 = 3;
                                        }
                                        break;
                                    default:        /* switch 2 */
                                        var_r0_1002 = 4;
                                        break;
                                    }
                                    if (var_r0_1002 == 1) {
                                        var_f4_957 = __float_nan;
                                    }
                                }
                                var_f4_1024 = 1.0f / var_f4_957;
                            } else {
                                var_f4_1024 = 0.0f;
                            }
                            arg_sp1E8 = M2C_FIELD(temp_r28_1998, f32 *, 0x50) * var_f4_1024;
                            arg_sp1EC = M2C_FIELD(temp_r28_1998, f32 *, 0x54) * var_f4_1024;
                            arg_sp1F0 = M2C_FIELD(temp_r28_1998, f32 *, 0x58) * var_f4_1024;
                            arg_sp3B8 = (f64) arg_sp1E8;
                            arg_sp3C0 = (f64) arg_sp1F0;
                            var_f2_1053 = -((arg_sp588 * (f32) arg_sp3C0) + ((arg_sp580 * (f32) arg_sp3B8) + (arg_sp584 * arg_sp3BC)));
                            if (var_f2_1053 < 0.0f) {
                                var_f2_1053 = -var_f2_1053;
                            }
                            temp_f3_1058 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            temp_f1_1060 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f4_1062 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            var_f5_1067 = (temp_f4_1062 * temp_f4_1062) + ((temp_f3_1058 * temp_f3_1058) + (temp_f1_1060 * temp_f1_1060));
                            if (var_f5_1067 > 0.0f) {
                                temp_f2_1070 = __frsqrte(var_f5_1067);
                                temp_f2_1076 = 0.5 * temp_f2_1070 * -(((f64) var_f5_1067 * (temp_f2_1070 * temp_f2_1070)) - 3.0);
                                temp_f2_1080 = 0.5 * temp_f2_1076 * -(((f64) var_f5_1067 * (temp_f2_1076 * temp_f2_1076)) - 3.0);
                                var_f5_1067 = (f32) ((f64) var_f5_1067 * (0.5 * temp_f2_1080 * -(((f64) var_f5_1067 * (temp_f2_1080 * temp_f2_1080)) - 3.0)));
                            } else if (var_f5_1067 < M2C_BITWISE(f32, 0.0)) {
                                var_f5_1067 = __float_nan;
                            } else {
                                arg_sp24 = var_f5_1067;
                                temp_r3_1099 = M2C_BITWISE(s32, arg_sp24) & 0x7F800000;
                                switch (temp_r3_1099) { /* switch 3; irregular */
                                case 0x7F800000:    /* switch 3 */
                                    if (M2C_BITWISE(s32, arg_sp24) & 0x7FFFFF) {
                                        var_r0_1109 = 1;
                                    } else {
                                        var_r0_1109 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 3 */
                                    if (M2C_BITWISE(s32, arg_sp24) & 0x7FFFFF) {
                                        var_r0_1109 = 5;
                                    } else {
                                        var_r0_1109 = 3;
                                    }
                                    break;
                                default:            /* switch 3 */
                                    var_r0_1109 = 4;
                                    break;
                                }
                                if (var_r0_1109 == 1) {
                                    var_f5_1067 = __float_nan;
                                }
                            }
                            M2C_FIELD(temp_r28_1998, f32 *, 0x8C) = (f32) ((1.0f - var_f2_1053) * (gUpdateTimeDelta * (var_f5_1067 / (1.5707964f * M2C_FIELD(temp_r28_1998, f32 *, 0x90)))));
                        } else {
                            M2C_FIELD(temp_r28_1998, u8 *, 0x9D) = 0U;
                        }
                    }
                    if ((u8) M2C_FIELD(temp_r28_1998, u8 *, 0x9D) == 0) {
                        temp_f1_1146 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                        temp_f0_1147 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                        temp_f3_1149 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                        var_f4_1156 = (temp_f3_1149 * temp_f3_1149) + ((temp_f1_1146 * temp_f1_1146) + (temp_f0_1147 * temp_f0_1147));
                        if (var_f4_1156 > 1e-12f) {
                            if (var_f4_1156 > 0.0f) {
                                temp_f1_1162 = __frsqrte(var_f4_1156);
                                temp_f1_1168 = 0.5 * temp_f1_1162 * -(((f64) var_f4_1156 * (temp_f1_1162 * temp_f1_1162)) - 3.0);
                                temp_f1_1172 = 0.5 * temp_f1_1168 * -(((f64) var_f4_1156 * (temp_f1_1168 * temp_f1_1168)) - 3.0);
                                var_f4_1156 = (f32) ((f64) var_f4_1156 * (0.5 * temp_f1_1172 * -(((f64) var_f4_1156 * (temp_f1_1172 * temp_f1_1172)) - 3.0)));
                            } else if (var_f4_1156 < M2C_BITWISE(f32, 0.0)) {
                                var_f4_1156 = __float_nan;
                            } else {
                                arg_sp20 = var_f4_1156;
                                temp_r3_1191 = M2C_BITWISE(s32, arg_sp20) & 0x7F800000;
                                switch (temp_r3_1191) { /* switch 4; irregular */
                                case 0x7F800000:    /* switch 4 */
                                    if (M2C_BITWISE(s32, arg_sp20) & 0x7FFFFF) {
                                        var_r0_1201 = 1;
                                    } else {
                                        var_r0_1201 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 4 */
                                    if (M2C_BITWISE(s32, arg_sp20) & 0x7FFFFF) {
                                        var_r0_1201 = 5;
                                    } else {
                                        var_r0_1201 = 3;
                                    }
                                    break;
                                default:            /* switch 4 */
                                    var_r0_1201 = 4;
                                    break;
                                }
                                if (var_r0_1201 == 1) {
                                    var_f4_1156 = __float_nan;
                                }
                            }
                            var_f3_1223 = 1.0f / var_f4_1156;
                        } else {
                            var_f3_1223 = 0.0f;
                        }
                        arg_sp1A8 = M2C_FIELD(temp_r28_1998, f32 *, 0x50) * var_f3_1223;
                        arg_sp1AC = M2C_FIELD(temp_r28_1998, f32 *, 0x54) * var_f3_1223;
                        arg_sp1B0 = M2C_FIELD(temp_r28_1998, f32 *, 0x58) * var_f3_1223;
                        arg_sp378 = (f64) arg_sp1A8;
                        arg_sp380 = (f64) arg_sp1B0;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                        arg_sp388 = arg_sp1D8;
                        arg_sp1E0 = (f32) arg_sp380 * M2C_FIELD(temp_r28_1998, f32 *, 0x90);
                        arg_sp390 = (f64) arg_sp1E0;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                        arg_sp398 = arg_sp1C8;
                        arg_sp1D0 = (f32) arg_sp390 * M2C_FIELD(temp_r28_1998, f32 *, 0x88);
                        arg_sp3A0 = (f64) arg_sp1D0;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp3A8 = arg_sp1B8;
                        arg_sp1C0 = (f32) arg_sp4E0 + (f32) arg_sp3A0;
                        arg_sp3B0 = (f64) arg_sp1C0;
                        if (MKCollision_RayCollide(*(MKVector3 *) (temp_r28_1998 + 0x40), *((MKVector3 *) &arg_sp3A8), (MKCollisionResult *) &arg_sp570, (MKCollisionMode) 7, 0) != 0) {
                            if ((arg_sp5C0 != 0) && (arg_sp5B8 != NULL) && (var_r3_1287 = M2C_FIELD(arg_sp5B8, void **, 8), ((var_r3_1287 == NULL) == 0))) {

                            } else {
                                var_r3_1287 = NULL;
                            }
                            if ((var_r3_1287 != NULL) && (M2C_FIELD(M2C_FIELD(var_r3_1287, void **, 0), s32 *, 0xC) & 8) && (var_r3_1287 != (u32) M2C_FIELD(temp_r28_1998, u32 *, 0x80))) {
                                arg_sp530 = 4;
                                arg_sp534 = 0;
                                arg_sp538 = 0;
                                temp_f3_1314 = M2C_FIELD(temp_r28_1998, f64 *, 0x40);
                                temp_f2_1315 = (f64) M2C_FIELD(temp_r28_1998, f32 *, 0x48);
                                arg_sp540 = temp_f3_1314;
                                arg_sp548 = temp_f2_1315;
                                arg_sp550 = 0.0f;
                                arg_sp56C = 0;
                                arg_sp558 = 1;
                                arg_sp560 = 0x4000;
                                arg_sp56C = 0;
                                (s16) arg_sp56C = 0;
                                arg_sp55C = -1;
                                arg_sp564 = 0;
                                arg_sp568 = 0;
                                arg_sp554 = 1.0f;
                                M2C_FIELD(M2C_FIELD(var_r3_1287, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK, M2C_UNK, f32, f64, f64), 0x2C)(&arg_sp530, 0x4000, 1, 0, 0.0f, temp_f2_1315, temp_f3_1314);
                            }
                            var_r4_1333 = 1;
                            M2C_FIELD(temp_r28_1998, u8 *, 0x9D) = 1U;
                            temp_f2_1336 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            temp_f1_1337 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f3_1339 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            var_f19_1343 = (temp_f3_1339 * temp_f3_1339) + ((temp_f2_1336 * temp_f2_1336) + (temp_f1_1337 * temp_f1_1337));
                            if (var_f19_1343 > 0.000001f) {
                                if (var_f19_1343 > 0.0f) {
                                    temp_f1_1349 = __frsqrte(var_f19_1343);
                                    temp_f1_1355 = 0.5 * temp_f1_1349 * -(((f64) var_f19_1343 * (temp_f1_1349 * temp_f1_1349)) - 3.0);
                                    temp_f1_1359 = 0.5 * temp_f1_1355 * -(((f64) var_f19_1343 * (temp_f1_1355 * temp_f1_1355)) - 3.0);
                                    var_f19_1343 = (f32) ((f64) var_f19_1343 * (0.5 * temp_f1_1359 * -(((f64) var_f19_1343 * (temp_f1_1359 * temp_f1_1359)) - 3.0)));
                                } else if (var_f19_1343 < M2C_BITWISE(f32, 0.0)) {
                                    var_f19_1343 = __float_nan;
                                } else {
                                    arg_sp1C = var_f19_1343;
                                    temp_r3_1378 = M2C_BITWISE(s32, arg_sp1C) & 0x7F800000;
                                    switch (temp_r3_1378) { /* switch 5; irregular */
                                    case 0x7F800000: /* switch 5 */
                                        if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {

                                        } else {
                                            var_r4_1333 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 5 */
                                        if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                                            var_r4_1333 = 5;
                                        } else {
                                            var_r4_1333 = 3;
                                        }
                                        break;
                                    default:        /* switch 5 */
                                        var_r4_1333 = 4;
                                        break;
                                    }
                                    if (var_r4_1333 == 1) {
                                        var_f19_1343 = __float_nan;
                                    }
                                }
                                var_f1_1409 = 1.0f / var_f19_1343;
                            } else {
                                var_f1_1409 = 0.0f;
                                var_f19_1343 = 0.0f;
                            }
                            M2C_FIELD(temp_r28_1998, f32 *, 0x50) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x50) * var_f1_1409);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x54) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x54) * var_f1_1409);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x58) * var_f1_1409);
                            arg_sp38 = -M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            arg_sp3C = -M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            arg_sp40 = -M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            arg_sp348 = (f64) arg_sp38;
                            arg_sp350 = (f64) arg_sp40;
                            arg_sp358.operator*(M2C_FIELD(temp_r28_1998, f32 *, 0x90) * M2C_FIELD(temp_r28_1998, f32 *, 0x88));
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            arg_sp368 = arg_spA8;
                            arg_spB0 = arg_sp578 + arg_sp360;
                            arg_sp4D8 = arg_spA8;
                            arg_sp370 = (f64) arg_spB0;
                            arg_sp4E0 = (f64) arg_spB0;
                            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                            if (var_f19_1343 == 100.0f) {
                                M2C_FIELD(temp_r28_1998, f32 *, 0x84) = 0.0f;
                            }
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x50) = arg_sp98;
                            arg_spA0 = M2C_FIELD(temp_r28_1998, f32 *, 0x58) + arg_sp588;
                            arg_sp338 = arg_sp98;
                            M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f64) arg_spA0;
                            arg_sp340 = (f64) arg_spA0;
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r0, 0x0, qr0 */);
                            M2C_FIELD(temp_r28_1998, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r28_1998, f32 *, 0x58) * (0.75f * var_f19_1343));
                            temp_f8_1495 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f6_1497 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            arg_sp88 = -arg_sp580;
                            temp_f2_1499 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            arg_sp8C = -arg_sp584;
                            arg_sp90 = -arg_sp588;
                            arg_sp308 = (f64) arg_sp88;
                            arg_sp310 = (f64) arg_sp90;
                            arg_sp78 = (temp_f8_1495 * (f32) arg_sp310) - (temp_f6_1497 * arg_sp30C);
                            arg_sp7C = (temp_f6_1497 * (f32) arg_sp308) - (temp_f2_1499 * (f32) arg_sp310);
                            arg_sp80 = (temp_f2_1499 * arg_sp30C) - (temp_f8_1495 * (f32) arg_sp308);
                            arg_sp318 = (f64) arg_sp78;
                            arg_sp320 = (f64) arg_sp80;
                            Normalise(*((MKVector3 *) &arg_sp328));
                            M2C_FIELD(temp_r28_1998, f64 *, 0x70) = arg_sp328;
                            M2C_FIELD(temp_r28_1998, f64 *, 0x78) = arg_sp330;
                            temp_f2_1528 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            temp_f1_1529 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f3_1530 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            var_f4_1535 = (temp_f3_1530 * temp_f3_1530) + ((temp_f2_1528 * temp_f2_1528) + (temp_f1_1529 * temp_f1_1529));
                            if (var_f4_1535 > 1e-12f) {
                                if (var_f4_1535 > 0.0f) {
                                    temp_f1_1541 = __frsqrte(var_f4_1535);
                                    temp_f1_1547 = 0.5 * temp_f1_1541 * -(((f64) var_f4_1535 * (temp_f1_1541 * temp_f1_1541)) - 3.0);
                                    temp_f1_1551 = 0.5 * temp_f1_1547 * -(((f64) var_f4_1535 * (temp_f1_1547 * temp_f1_1547)) - 3.0);
                                    var_f4_1535 = (f32) ((f64) var_f4_1535 * (0.5 * temp_f1_1551 * -(((f64) var_f4_1535 * (temp_f1_1551 * temp_f1_1551)) - 3.0)));
                                } else if (var_f4_1535 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_1535 = __float_nan;
                                } else {
                                    arg_sp18 = var_f4_1535;
                                    temp_r3_1570 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                                    switch (temp_r3_1570) { /* switch 6; irregular */
                                    case 0x7F800000: /* switch 6 */
                                        if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                            var_r0_1580 = 1;
                                        } else {
                                            var_r0_1580 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 6 */
                                        if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                            var_r0_1580 = 5;
                                        } else {
                                            var_r0_1580 = 3;
                                        }
                                        break;
                                    default:        /* switch 6 */
                                        var_r0_1580 = 4;
                                        break;
                                    }
                                    if (var_r0_1580 == 1) {
                                        var_f4_1535 = __float_nan;
                                    }
                                }
                                var_f4_1602 = 1.0f / var_f4_1535;
                            } else {
                                var_f4_1602 = 0.0f;
                            }
                            arg_sp198 = M2C_FIELD(temp_r28_1998, f32 *, 0x50) * var_f4_1602;
                            arg_sp19C = M2C_FIELD(temp_r28_1998, f32 *, 0x54) * var_f4_1602;
                            arg_sp1A0 = M2C_FIELD(temp_r28_1998, f32 *, 0x58) * var_f4_1602;
                            arg_sp2F8 = (f64) arg_sp198;
                            arg_sp300 = (f64) arg_sp1A0;
                            var_f2_1631 = -((arg_sp588 * (f32) arg_sp300) + ((arg_sp580 * (f32) arg_sp2F8) + (arg_sp584 * arg_sp2FC)));
                            if (var_f2_1631 < 0.0f) {
                                var_f2_1631 = -var_f2_1631;
                            }
                            temp_f3_1636 = M2C_FIELD(temp_r28_1998, f32 *, 0x50);
                            temp_f1_1638 = M2C_FIELD(temp_r28_1998, f32 *, 0x54);
                            temp_f4_1640 = M2C_FIELD(temp_r28_1998, f32 *, 0x58);
                            var_f5_1645 = (temp_f4_1640 * temp_f4_1640) + ((temp_f3_1636 * temp_f3_1636) + (temp_f1_1638 * temp_f1_1638));
                            if (var_f5_1645 > 0.0f) {
                                temp_f2_1648 = __frsqrte(var_f5_1645);
                                temp_f2_1654 = 0.5 * temp_f2_1648 * -(((f64) var_f5_1645 * (temp_f2_1648 * temp_f2_1648)) - 3.0);
                                temp_f2_1658 = 0.5 * temp_f2_1654 * -(((f64) var_f5_1645 * (temp_f2_1654 * temp_f2_1654)) - 3.0);
                                var_f5_1645 = (f32) ((f64) var_f5_1645 * (0.5 * temp_f2_1658 * -(((f64) var_f5_1645 * (temp_f2_1658 * temp_f2_1658)) - 3.0)));
                            } else if (var_f5_1645 < M2C_BITWISE(f32, 0.0)) {
                                var_f5_1645 = __float_nan;
                            } else {
                                arg_sp14 = var_f5_1645;
                                temp_r3_1677 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                                switch (temp_r3_1677) { /* switch 7; irregular */
                                case 0x7F800000:    /* switch 7 */
                                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                        var_r0_1687 = 1;
                                    } else {
                                        var_r0_1687 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 7 */
                                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                        var_r0_1687 = 5;
                                    } else {
                                        var_r0_1687 = 3;
                                    }
                                    break;
                                default:            /* switch 7 */
                                    var_r0_1687 = 4;
                                    break;
                                }
                                if (var_r0_1687 == 1) {
                                    var_f5_1645 = __float_nan;
                                }
                            }
                            M2C_FIELD(temp_r28_1998, f32 *, 0x8C) = (f32) ((1.0f - var_f2_1631) * (gUpdateTimeDelta * (var_f5_1645 / (1.5707964f * M2C_FIELD(temp_r28_1998, f32 *, 0x90)))));
                        }
                    }
                }
                if ((u8) M2C_FIELD(temp_r28_1998, u8 *, 0x9D) == 0) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r28, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp4C8 = arg_sp188;
                    arg_sp190 = (f32) arg_sp4E0 - M2C_FIELD(temp_r28_1998, f32 *, 0x48);
                    arg_sp4D0 = (f64) arg_sp190;
                    var_f4_1741 = ((f32) arg_sp4D0 * (f32) arg_sp4D0) + (((f32) arg_sp4C8 * (f32) arg_sp4C8) + (arg_sp4CC * arg_sp4CC));
                    if (var_f4_1741 > 0.0f) {
                        temp_f1_1744 = __frsqrte(var_f4_1741);
                        temp_f1_1750 = 0.5 * temp_f1_1744 * -(((f64) var_f4_1741 * (temp_f1_1744 * temp_f1_1744)) - 3.0);
                        temp_f1_1754 = 0.5 * temp_f1_1750 * -(((f64) var_f4_1741 * (temp_f1_1750 * temp_f1_1750)) - 3.0);
                        var_f4_1741 = (f32) ((f64) var_f4_1741 * (0.5 * temp_f1_1754 * -(((f64) var_f4_1741 * (temp_f1_1754 * temp_f1_1754)) - 3.0)));
                    } else if (var_f4_1741 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_1741 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_1741;
                        temp_r3_1773 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_1773) {     /* switch 8; irregular */
                        case 0x7F800000:            /* switch 8 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_1783 = 1;
                            } else {
                                var_r0_1783 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 8 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_1783 = 5;
                            } else {
                                var_r0_1783 = 3;
                            }
                            break;
                        default:                    /* switch 8 */
                            var_r0_1783 = 4;
                            break;
                        }
                        if (var_r0_1783 == 1) {
                            var_f4_1741 = __float_nan;
                        }
                    }
                    var_r25_1807 = 0;
                    temp_r26_1815 = (s32) (var_f4_1741 / (40.0f * M2C_FIELD(temp_r28_1998, f32 *, 0x88)));
                    temp_f18_1821 = 1.0f / (f32) (temp_r26_1815 - 1);
loop_205:
                    if (var_r25_1807 < temp_r26_1815) {
                        __ml((f32) var_r25_1807 * temp_f18_1821, *((MKVector3 *) &arg_sp2D8));
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        arg_sp4B8 = arg_sp68;
                        arg_sp70 = M2C_FIELD(temp_r28_1998, f32 *, 0x48) + arg_sp2E0;
                        arg_sp2E8 = arg_sp68;
                        arg_sp4C0 = (f64) arg_sp70;
                        arg_sp2F0 = (f64) arg_sp70;
                        if (M2C_FIELD(temp_r28_1998, s32 *, 0x98) & 2) {
                            arg_sp180 = -1.0f;
                            temp_f27_1857 = M2C_FIELD(temp_r28_1998, f32 *, 0x88);
                            arg_sp170 = 1.0f;
                            arg_sp178 = -1.0f;
                            arg_sp17C = -1.0f;
                            arg_sp168 = 1.0f;
                            arg_sp16C = 1.0f;
                            arg_sp298 = (f64) arg_sp178;
                            arg_sp2A0 = (f64) arg_sp180;
                            arg_sp288 = (f64) arg_sp168;
                            arg_sp290 = (f64) arg_sp170;
                            KDRand_Vector(*((MKVector3 *) &arg_sp2A8), *((MKVector3 *) &arg_sp298));
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                            arg_sp2B8 = arg_sp158;
                            arg_sp160 = arg_sp2B0 * 175.0f;
                            arg_sp2C0 = (f64) arg_sp160;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                            arg_sp2C8 = arg_sp148;
                            arg_sp150 = (f32) arg_sp2C0 * temp_f27_1857;
                            arg_sp2D0 = (f64) arg_sp150;
                            arg_sp34 = M2C_FIELD(temp_r28_1998, f32 *, 0x88) * MKRand_Float(&gViewSeed, 0.6f, 0.9f);
                            gb.EmitDust(*((MKVector3 *) &arg_sp4B8), *((MKVector3 *) &arg_sp2C8), arg_sp34, 0.0f);
                        }
                        if (M2C_FIELD(temp_r28_1998, s32 *, 0x98) & 8) {
                            arg_sp140 = -1.0f;
                            temp_f28_1918 = M2C_FIELD(temp_r28_1998, f32 *, 0x88);
                            arg_sp130 = 1.0f;
                            arg_sp138 = -1.0f;
                            arg_sp13C = -1.0f;
                            arg_sp128 = 1.0f;
                            arg_sp12C = 1.0f;
                            arg_sp248 = (f64) arg_sp138;
                            arg_sp250 = (f64) arg_sp140;
                            arg_sp238 = (f64) arg_sp128;
                            arg_sp240 = (f64) arg_sp130;
                            KDRand_Vector(*((MKVector3 *) &arg_sp258), *((MKVector3 *) &arg_sp248));
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                            arg_sp268 = arg_sp118;
                            arg_sp120 = arg_sp260 * 175.0f;
                            arg_sp270 = (f64) arg_sp120;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                            arg_sp278 = arg_sp108;
                            arg_sp110 = (f32) arg_sp270 * temp_f28_1918;
                            arg_sp280 = (f64) arg_sp110;
                            arg_sp30 = M2C_FIELD(temp_r28_1998, f32 *, 0x88) * MKRand_Float(&gViewSeed, 3.5f, 3.6f);
                            gb.unk68->Emit(*((MKVector3 *) &arg_sp4B8), *((MKVector3 *) &arg_sp278), arg_sp30);
                        }
                        var_r25_1807 += 1;
                        goto loop_205;
                    }
                }
                M2C_FIELD(temp_r28_1998, f64 *, 0x40) = arg_sp4D8;
                M2C_FIELD(temp_r28_1998, f32 *, 0x48) = arg_sp4E0;
                arg_sp4F0.SetRotateAroundAxis(*(temp_r28_1998 + 0x70), M2C_FIELD(temp_r28_1998, f32 *, 0x8C));
                temp_r28_1998->Multiply3x3(temp_r28_1998, (Matrix *) &arg_sp4F0);
                temp_r28_1998->unk30 = (f32) M2C_FIELD(temp_r28_1998, f64 *, 0x40);
                temp_r28_1998->unk34 = M2C_FIELD(temp_r28_1998, f32 *, 0x44);
                temp_r28_1998->unk38 = M2C_FIELD(temp_r28_1998, f32 *, 0x48);
                temp_r28_1998->unk3C = 1.0f;
            }
            var_r27_524 += 4;
            goto loop_208;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void FlyingChunkPS::Init() {
    MKHeap *temp_r3_2048;
    MKHeap *temp_r3_2057;
    Matrix **temp_r3_2080;
    Matrix **temp_r3_2087;
    Matrix **temp_r3_2094;
    Matrix **var_r3_2067;
    Matrix **var_r5_2079;
    s32 temp_r30_2049;
    s32 var_ctr_2083;

    GamePropColored::Init();
    temp_r3_2048 = checked_cast<FlyingChunkPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r30_2049 = temp_r3_2048->unkE8;
    if (temp_r30_2049 == 0) {
        this->unkD8 = &gEmptyPtrListDL + 4;
        return;
    }
    temp_r3_2057 = temp_r3_2048->Current();
    if (temp_r3_2057 != NULL) {
        var_r3_2067 = ((MKHeap *) (temp_r3_2057->Current()))->Alloc(((temp_r30_2049 + 2) * 4) + (temp_r30_2049 * 0xA0), NULL, 0);
    } else {
        var_r3_2067 = malloc(((temp_r30_2049 + 2) * 4) + (temp_r30_2049 * 0xA0));
    }
    this->unkD8 = var_r3_2067;
    var_r5_2079 = this->unkD8;
    temp_r3_2080 = var_r5_2079 + (temp_r30_2049 * 0xA0);
    this->unkD8 = temp_r3_2080;
    *temp_r3_2080 = NULL;
    var_ctr_2083 = temp_r30_2049;
    if (temp_r30_2049 > 0) {
        do {
            temp_r3_2087 = this->unkD8;
            this->unkD8 = temp_r3_2087 + 4;
            M2C_FIELD(temp_r3_2087, Matrix ***, 4) = var_r5_2079;
            var_r5_2079 += 0xA0;
            var_ctr_2083 -= 1;
        } while (var_ctr_2083 != 0);
    }
    temp_r3_2094 = this->unkD8;
    this->unkD8 = temp_r3_2094 + 4;
    M2C_FIELD(temp_r3_2094, Matrix ***, 4) = NULL;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void FlyingChunkPSDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkEC = MKModel_GetNmbrOfSubObjects(this->unk2C, (SubObjectType) 0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 FlyingChunkPSDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2136;

    var_r31_2136 = 0;
    if ((GamePropColoredDescriptor::LoadLine(arg0) != 0) || (arg0->LoadInt("MaxNumChunks", &this->unkE8, 0) != 0) || (arg0->LoadFloat("MaxAge", &this->unkF0, 0) != 0) || (arg0->LoadBool("Collide", (u8 *) &this->unkF4, 0) != 0) || (arg0->LoadVector3("Accel", &this->unkF8, 0) != 0)) {
        var_r31_2136 = 1;
    }
    return var_r31_2136;
}
#endif

void FlyingChunkPSDescriptor::Init() {
    GamePropColoredDescriptor::Init();
    this->unkE8 = 0x64;
    this->unkEC = 1;
    this->unkF0 = 1.0f;
    M2C_FIELD(this, s8 *, 0xF4) = 0;
    this->unkF8.unk0 = 0.0f;
    this->unkF8.unk4 = 0.0f;
    this->unkF8.unk8 = 0.0f;
}

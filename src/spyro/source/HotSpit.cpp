#include "spyro/source/HotSpit.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_BBFireballSplat;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pHotSpitDescriptor;

#if 0 // DRAFT: undefined identifier 'arg_sp1F0'
void HotSpit::Update() {
    f32 temp_f1_230;
    f32 temp_f1_240;
    f32 temp_f28_192;
    f32 temp_f29_187;
    f32 temp_f31_182;
    f32 var_f1_250;
    f32 var_f28_234;
    f32 var_f29_244;
    f32 var_f4_78;
    f32 var_f5_99;
    f64 temp_f1_104;
    f64 temp_f1_110;
    f64 temp_f1_114;
    s32 temp_r3_133;
    s32 var_r0_143;
    Projectile::Update();
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp1F0);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp1EC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_78 = 0.0f;
    arg_sp90 = 0.0f;
    arg_sp88 = 0.0f;
    arg_sp8C = 1.0f;
    arg_sp190 = (f64) arg_sp90;
    arg_sp188 = (f64) arg_sp88;
    arg_sp198 = this->unkC8;
    arg_sp1A0 = this->unkD0;
    var_f5_99 = ((f32) arg_sp1A0 * (f32) arg_sp1A0) + (((f32) arg_sp198 * (f32) arg_sp198) + (arg_sp19C * arg_sp19C));
    if (var_f5_99 > 0.000001f) {
        if (var_f5_99 > 0.0f) {
            temp_f1_104 = __frsqrte(var_f5_99);
            temp_f1_110 = 0.5 * temp_f1_104 * -(((f64) var_f5_99 * (temp_f1_104 * temp_f1_104)) - 3.0);
            temp_f1_114 = 0.5 * temp_f1_110 * -(((f64) var_f5_99 * (temp_f1_110 * temp_f1_110)) - 3.0);
            var_f5_99 = (f32) ((f64) var_f5_99 * (0.5 * temp_f1_114 * -(((f64) var_f5_99 * (temp_f1_114 * temp_f1_114)) - 3.0)));
        } else if (var_f5_99 < M2C_BITWISE(f32, 0.0)) {
            var_f5_99 = __float_nan;
        } else {
            arg_sp10 = var_f5_99;
            temp_r3_133 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_133) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_143 = 1;
                } else {
                    var_r0_143 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_143 = 5;
                } else {
                    var_r0_143 = 3;
                }
                break;
            default:
                var_r0_143 = 4;
                break;
            }
            if (var_r0_143 == 1) {
                var_f5_99 = __float_nan;
            }
        }
        var_f4_78 = 1.0f / var_f5_99;
    } else {
        var_f5_99 = 0.0f;
    }
    arg_sp198 = (f32) arg_sp198 * var_f4_78;
    arg_sp19C *= var_f4_78;
    arg_sp1A0 = (f32) arg_sp1A0 * var_f4_78;
    if (var_f5_99 != 0.0f) {
        temp_f31_182 = gUpdateTimeDelta;
        temp_f29_187 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        temp_f28_192 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        MKVector(MKRand_Float(&gViewSeed, 1.0f, 3.0f), temp_f28_192, temp_f29_187);
        arg_sp158.operator*(3.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp168 = arg_sp38;
        arg_sp40 = arg_sp160 * temp_f31_182;
        arg_sp170 = (f64) arg_sp40;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk158 += (f32) arg_sp170;
        KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp1B0, *((MKVector3 *) &arg_sp198), (MKVector3 *) &arg_sp188);
        temp_f1_230 = _table_sinf(this->unk158);
        if (temp_f1_230 < 0.0f) {
            var_f28_234 = -temp_f1_230;
        } else {
            var_f28_234 = temp_f1_230;
        }
        temp_f1_240 = _table_sinf(this->unk154);
        if (temp_f1_240 < 0.0f) {
            var_f29_244 = -temp_f1_240;
        } else {
            var_f29_244 = temp_f1_240;
        }
        var_f1_250 = _table_sinf(this->unk150);
        if (var_f1_250 < 0.0f) {
            var_f1_250 = -var_f1_250;
        }
        MKVector(var_f1_250, var_f29_244, 0.25f * var_f28_234);
        MKVector(1.0f, 1.0f, 1.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp138 = arg_sp28;
        arg_sp30 = arg_sp130 + arg_sp120;
        arg_sp140 = (f64) arg_sp30;
        arg_sp1B0.Scale3x3((Matrix *) &arg_sp1B0, *((MKVector3 *) &arg_sp138));
        arg_sp1E0 = arg_sp220;
        arg_sp1E4 = arg_sp224;
        arg_sp1E8 = arg_sp228;
        arg_sp1EC = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp1B0));
    }
    MKVector(0.0f, 200.0f, 0.0f);
    arg_spF8.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp80 = -1.0f;
    arg_sp70 = 1.0f;
    arg_sp20 = arg_sp100 + arg_spF0;
    arg_sp78 = -1.0f;
    arg_sp7C = -1.0f;
    arg_sp68 = 1.0f;
    arg_sp6C = -1.0f;
    arg_sp108 = arg_sp18;
    arg_sp110 = (f64) arg_sp20;
    arg_sp178 = arg_sp18;
    arg_sp180 = (f64) arg_sp20;
    arg_spA8 = (f64) arg_sp78;
    arg_spB0 = (f64) arg_sp80;
    arg_sp98 = (f64) arg_sp68;
    arg_spA0 = (f64) arg_sp70;
    KDRand_Vector(*((MKVector3 *) &arg_spB8), *((MKVector3 *) &arg_spA8));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_spC8 = arg_sp58;
    arg_sp60 = arg_spC0 * 25.0f;
    arg_spD0 = (f64) arg_sp60;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spD8 = arg_sp48;
    arg_sp50 = arg_sp228 + (f32) arg_spD0;
    arg_spE0 = (f64) arg_sp50;
    arg_sp14 = MKRand_Float(&gViewSeed, 8.0f, 12.0f);
    ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &arg_spD8), *((MKVector3 *) &arg_sp178), arg_sp14);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp1E0'
void HotSpit::Collided(MKCollisionResult &arg0) {
    MKProp *temp_r4_555;
    MKProp *temp_r4_764;
    MKPtrList<MKProp> *temp_r4_860;
    MKPtrList<MKProp> *temp_r6_620;
    f32 var_f4_650;
    f32 var_f5_688;
    f64 temp_f1_693;
    f64 temp_f1_699;
    f64 temp_f1_703;
    s32 temp_r3_722;
    s32 var_r0_732;
    s32 var_r26_437;
    s32 var_r26_498;
    void **temp_r5_642;
    void **var_r4_623;
    void **var_r4_863;
    void *temp_r0_632;
    void *temp_r0_872;
    void *temp_r28_411;
    void *temp_r3_485;
    void *temp_r3_608;
    void *var_r3_611;
    void *var_r3_851;
    Projectile::Collided(arg0);
    temp_r28_411 = checked_cast<HotSpitDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp1E0);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp1DC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_r26_437 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(*((MKVector3 *) &arg_sp178), *((MKVector3 *) &arg_sp168));
        arg_sp188.operator*(3000.0f);
        arg_sp198.operator*(2.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp98 = 1.0f;
        arg_sp9C = 1.0f;
        arg_sp50 = arg_sp1A0 + arg_sp190;
        arg_spA0 = 1.0f;
        arg_spA4 = 1.0f;
        arg_sp1C8 = arg_sp48;
        arg_sp1D0 = (f64) arg_sp50;
        arg_sp148 = (f64) arg_sp98;
        arg_sp150 = (f64) arg_spA0;
        temp_r3_485 = M2C_FIELD(temp_r28_411, void **, 0xF0);
        arg_sp1A8 = arg_sp48;
        arg_sp1B0 = (f64) arg_sp50;
        M2C_FIELD(M2C_FIELD(temp_r3_485, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64 *, f64 *, f32, f64, f64, f64), 0x3C)(temp_r3_485, &arg_sp210, &arg_sp1C8, &arg_sp148, 2.0f, (f64) arg_sp98, (f64) arg_sp50, arg_sp48);
        var_r26_437 += 1;
    } while (var_r26_437 < 5);
    var_r26_498 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(*((MKVector3 *) &arg_sp108), *((MKVector3 *) &arg_spF8));
        arg_sp118.operator*(1000.0f);
        arg_sp128.operator*(0.5f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp138 = arg_sp38;
        arg_sp40 = arg_sp130 + arg_sp120;
        arg_sp1C8 = arg_sp38;
        arg_sp140 = (f64) arg_sp40;
        arg_sp1D0 = (f64) arg_sp40;
        arg_sp14 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &arg_sp210), *((MKVector3 *) &arg_sp1C8), arg_sp14);
        var_r26_498 += 1;
    } while (var_r26_498 < 0xA);
    arg_sp27C = 0;
    temp_r4_555 = this->unk130;
    arg_sp30 = 0.0f;
    arg_sp28 = 0.0f;
    arg_sp2C = 0.0f;
    arg_spE0 = (f64) arg_sp30;
    arg_spD8 = (f64) arg_sp28;
    arg_sp278 = 7;
    arg_sp2A0 = 1;
    arg_sp2A4 = temp_r4_555;
    arg_sp280 = (f64) arg_sp28;
    arg_sp288 = (f64) arg_sp30;
    arg_sp2B8 = 0;
    arg_sp2C4 = 2;
    arg_sp2C0 = 10.0f;
    arg_sp2B8 = 0;
    (s16) arg_sp2B8 = 1;
    arg_sp2BC = -1;
    arg_sp290 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    arg_sp298 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    arg_sp2C8 = 0;
    if (temp_r4_555 != NULL) {
        arg_sp88.GetPos();
        arg_sp2A8 = arg_sp88;
        arg_sp2B0 = arg_sp90;
    } else {
        arg_sp2A8 = 0.0f;
        arg_sp2AC = 0.0f;
        arg_sp2B0 = 0.0f;
    }
    arg_sp2C8 = 0;
    KDSound_Play3d(GS_BBFireballSplat, (MKVector3 *) &arg_sp210, 0U, -1, 0.0f, 0U);
    if (((u8) arg0.unk50 != 0) && (temp_r3_608 = arg0.unk48, ((temp_r3_608 == NULL) == 0)) && (var_r3_611 = M2C_FIELD(temp_r3_608, void **, 8), ((var_r3_611 == NULL) == 0))) {

    } else {
        var_r3_611 = NULL;
    }
    if (var_r3_611 != NULL) {
        temp_r6_620 = this->unk134;
        if (temp_r6_620 != NULL) {
            var_r4_623 = *temp_r6_620;
loop_21:
            temp_r0_632 = *var_r4_623;
            if (temp_r0_632 == NULL) {
                var_r4_623 = NULL;
            } else if (temp_r0_632 == var_r3_611) {

            } else {
                var_r4_623 += 4;
                goto loop_21;
            }
            if (var_r4_623 == NULL) {
                goto block_24;
            }
        } else {
block_24:
            temp_r5_642 = *temp_r6_620 - 4;
            *temp_r6_620 = temp_r5_642;
            *temp_r5_642 = var_r3_611;
            M2C_FIELD(M2C_FIELD(var_r3_611, void **, 0x44), M2C_UNK (**)(s32 *, void **), 0x2C)(&arg_sp278, temp_r5_642);
        }
    }
    var_f4_650 = 0.0f;
    arg_sp220 = 0.0f;
    arg_sp224 = 0.0f;
    arg_sp228 = 0.0f;
    arg_sp230 = 0.0f;
    arg_sp234 = 0.0f;
    arg_sp238 = 0.0f;
    arg_sp240 = 0.0f;
    arg_sp244 = 0.0f;
    arg_sp248 = 0.0f;
    arg_sp24C = 1.0f;
    arg_sp250 = 0.0f;
    arg_sp254 = 0.0f;
    arg_sp258 = 0;
    arg_sp258 = 0;
    (s8) arg_sp258 = 0;
    arg_sp25C = 0;
    arg_sp260 = 3.4028235e38f;
    arg_sp264 = 0;
    arg_sp268 = NULL;
    arg_sp26C = -1;
    arg_sp270 = 0U;
    arg_sp1B8 = this->unkC8;
    arg_sp1C0 = this->unkD0;
    arg_sp1BC = 0.0f;
    var_f5_688 = ((f32) arg_sp1C0 * (f32) arg_sp1C0) + (((f32) arg_sp1B8 * (f32) arg_sp1B8) + (0.0f * 0.0f));
    if (var_f5_688 > 0.000001f) {
        if (var_f5_688 > 0.0f) {
            temp_f1_693 = __frsqrte(var_f5_688);
            temp_f1_699 = 0.5 * temp_f1_693 * -(((f64) var_f5_688 * (temp_f1_693 * temp_f1_693)) - 3.0);
            temp_f1_703 = 0.5 * temp_f1_699 * -(((f64) var_f5_688 * (temp_f1_699 * temp_f1_699)) - 3.0);
            var_f5_688 = (f32) ((f64) var_f5_688 * (0.5 * temp_f1_703 * -(((f64) var_f5_688 * (temp_f1_703 * temp_f1_703)) - 3.0)));
        } else if (var_f5_688 < M2C_BITWISE(f32, 0.0)) {
            var_f5_688 = __float_nan;
        } else {
            arg_sp10 = var_f5_688;
            temp_r3_722 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_722) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_732 = 1;
                } else {
                    var_r0_732 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_732 = 5;
                } else {
                    var_r0_732 = 3;
                }
                break;
            default:
                var_r0_732 = 4;
                break;
            }
            if (var_r0_732 == 1) {
                var_f5_688 = __float_nan;
            }
        }
        var_f4_650 = 1.0f / var_f5_688;
    }
    temp_r4_764 = this->unk130;
    arg_sp20 = 0.0f;
    arg_sp18 = 0.0f;
    arg_sp1C = 0.0f;
    arg_sp1B8 = (f32) arg_sp1B8 * var_f4_650;
    arg_sp1BC *= var_f4_650;
    arg_sp1C0 = (f32) arg_sp1C0 * var_f4_650;
    arg_spC8 = (f64) arg_sp18;
    arg_spD0 = (f64) arg_sp20;
    arg_sp278 = 7;
    arg_sp2A0 = 1;
    arg_sp2A4 = temp_r4_764;
    arg_sp280 = (f64) arg_sp18;
    arg_sp288 = (f64) arg_sp20;
    arg_sp2B8 = 0;
    arg_sp2C4 = 2;
    arg_sp2C0 = 10.0f;
    arg_sp2B8 = 0;
    (s16) arg_sp2B8 = 1;
    arg_sp2BC = -1;
    arg_sp290 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    arg_sp298 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    arg_sp2C8 = 0;
    if (temp_r4_764 != NULL) {
        arg_sp78.GetPos();
        arg_sp2A8 = arg_sp78;
        arg_sp2B0 = arg_sp80;
    } else {
        arg_sp2A8 = 0.0f;
        arg_sp2AC = 0.0f;
        arg_sp2B0 = 0.0f;
    }
    arg_sp2C8 = 0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_spA8 = arg_sp68;
    arg_sp70 = (f32) arg_sp1C0 * 600.0f;
    arg_spB0 = (f64) arg_sp70;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB8 = arg_sp58;
    arg_sp60 = arg_sp218 + (f32) arg_spB0;
    arg_spC0 = (f64) arg_sp60;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp210), *((MKVector3 *) &arg_spB8), 200.0f, (MKCollisionResult *) &arg_sp220, (MKCollisionMode) 2, 0x08000000) != 0) {
        if ((arg_sp270 != 0) && (arg_sp268 != NULL) && (var_r3_851 = M2C_FIELD(arg_sp268, void **, 8), ((var_r3_851 == NULL) == 0))) {

        } else {
            var_r3_851 = NULL;
        }
        if (var_r3_851 != NULL) {
            temp_r4_860 = this->unk134;
            if (temp_r4_860 != NULL) {
                var_r4_863 = *temp_r4_860;
loop_59:
                temp_r0_872 = *var_r4_863;
                if (temp_r0_872 == NULL) {
                    var_r4_863 = NULL;
                } else if (temp_r0_872 == var_r3_851) {

                } else {
                    var_r4_863 += 4;
                    goto loop_59;
                }
                if (var_r4_863 == NULL) {
                    goto block_62;
                }
            } else {
block_62:
                M2C_FIELD(M2C_FIELD(var_r3_851, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp278);
            }
        }
    }
    Disable();
}
#endif

void HotSpit::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    Projectile::Fire(arg0, arg1, arg2, arg3, arg4);
}

void HotSpit::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    M2C_FIELD(this, f64 *, 0x150) = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x158) = (f64) sp10;
    Projectile::LoadDone();
}

void *HotSpit::CreateInstance() {
    void *temp_r3_949;

    if ((MKPropDescriptor *) pHotSpitDescriptor != NULL) {
        temp_r3_949 = pHotSpitDescriptor->CreateInstance();
        if (temp_r3_949 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_949, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_949;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void HotSpitDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pHotSpitDescriptor = (MKPropDescriptor *) this;
    this->unkF0 = checked_cast<GoopFX *, MKProp>(gMK->CreateProp("HotSpitSplatter"));
}
#endif

void HotSpitDescriptor::Deinit() {
    pHotSpitDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}

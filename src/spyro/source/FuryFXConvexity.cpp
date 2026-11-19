#include "spyro/source/FuryFXConvexity.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGlowFX.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(KDSoundFader **);                      /* extern */
KDSoundFader **malloc(M2C_UNK);                     /* extern */
extern s32 GS_SpyroBreathConvex1;
extern s32 GS_SpyroBreathConvexLP;
extern s32 GS_SpyroFuryConvexExtra1;
extern s32 GS_SpyroFuryConvexExtra2;
extern s32 GS_SpyroFuryConvexExtra3;
extern s32 GS_SpyroFuryConvexLP1;
extern s32 GS_SpyroFuryConvexLP2;
extern s32 GS_SpyroFuryConvexLP3;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_780 = 0;
static u8 lit_781 = 1;

#if 0 // DRAFT: undefined identifier 'arg_spCC'
void FuryFXConvexity::EmitVortexParticles() {
    MKHeap *temp_r3_125;
    MKHeap *temp_r3_171;
    f32 temp_f1_131;
    s32 temp_r4_79;
    void *temp_r30_140;
    void *temp_r30_178;
    void *temp_r3_137;
    void *temp_r3_175;
    temp_r4_79 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), s32 *, 8) - 4;
    M2C_STRUCT_COPY((s32) &arg_spCC + 4, temp_r4_79 + 4, 0x40);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    arg_sp60 = 0.0f;
    arg_sp64 = 500.0f;
    arg_sp48 = arg_spF8 * 150.0f;
    arg_sp68 = 0.0f;
    arg_spA0 = (f64) arg_sp60;
    arg_sp90 = arg_sp40;
    arg_sp98 = (f64) arg_sp48;
    arg_spA8 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB0 = arg_sp50;
    arg_sp58 = this->unk90.unk38 + (f32) arg_spA8;
    arg_spB8 = (f64) arg_sp58;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_r3_125 = this->unk160;
    temp_f1_131 = (f32) arg_spB8 + (f32) arg_sp98;
    arg_spC0 = arg_sp30;
    arg_sp38 = temp_f1_131;
    arg_spC8 = (f64) arg_sp38;
    temp_r3_137 = M2C_FIELD(temp_r3_125->unk44, void *(**)(MKHeap *, s32, void *, f32, f32, f64), 0x3C)(temp_r3_125, temp_r4_79 + 0x40, &arg_spCC + 0x40, temp_f1_131, (f32) arg_spB8, arg_sp40);
    if (temp_r3_137 != NULL) {
        temp_r30_140 = M2C_FIELD(temp_r3_137, void **, 0x2C);
        M2C_FIELD(temp_r3_137, f64 *, 0) = arg_spC0;
        M2C_FIELD(temp_r3_137, f64 *, 8) = arg_spC8;
        M2C_FIELD(temp_r3_137, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_137, f32 *, 0x28) = (f32) this->unk164;
        M2C_FIELD(temp_r3_137, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        arg_sp20 = 0.0f;
        arg_sp24 = 0.0f;
        arg_sp28 = 0.0f;
        M2C_FIELD(temp_r30_140, f64 *, 0) = (f64) arg_sp20;
        M2C_FIELD(temp_r30_140, f64 *, 8) = (f64) arg_sp28;
        arg_sp80 = (f64) arg_sp20;
        M2C_FIELD(temp_r30_140, f32 *, 0x18) = (f32) this->unk164;
        M2C_FIELD(temp_r30_140, f32 *, 0x10) = -3.1415927f;
        arg_sp88 = (f64) arg_sp28;
        M2C_FIELD(temp_r30_140, f32 *, 0x14) = M2C_BITWISE(f32, this->unk160->unkF4);
    }
    temp_r3_171 = this->unk15C;
    temp_r3_175 = M2C_FIELD(temp_r3_171->unk44, void *(**)(MKHeap *), 0x3C)(temp_r3_171);
    if (temp_r3_175 != NULL) {
        temp_r30_178 = M2C_FIELD(temp_r3_175, void **, 0x2C);
        M2C_FIELD(temp_r3_175, f64 *, 0) = arg_spC0;
        M2C_FIELD(temp_r3_175, f64 *, 8) = arg_spC8;
        M2C_FIELD(temp_r3_175, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_175, f32 *, 0x28) = (f32) (1.5f * this->unk164);
        M2C_FIELD(temp_r3_175, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        arg_sp10 = 0.0f;
        arg_sp14 = 0.0f;
        arg_sp18 = 0.0f;
        M2C_FIELD(temp_r30_178, f64 *, 0) = (f64) arg_sp10;
        M2C_FIELD(temp_r30_178, f64 *, 8) = (f64) arg_sp18;
        arg_sp70 = (f64) arg_sp10;
        arg_sp78 = (f64) arg_sp18;
        M2C_FIELD(temp_r30_178, f32 *, 0x18) = (f32) (1.5f * this->unk164);
        M2C_FIELD(temp_r30_178, f32 *, 0x10) = -3.1415927f;
        M2C_FIELD(temp_r30_178, f32 *, 0x14) = M2C_BITWISE(f32, this->unk15C->unkF4);
    }
}
#endif

void FuryFXConvexity::DisableChaserLights() {
    KDSoundFader **var_r4_224;
    KDSoundFader *temp_r3_233;

    var_r4_224 = this->unk158;
loop_2:
    if (var_r4_224 != NULL) {
        temp_r3_233 = *var_r4_224;
        if (temp_r3_233 == NULL) {
            return;
        }
        M2C_FIELD(temp_r3_233, s32 *, 0x84) = 0;
        var_r4_224 += 4;
        goto loop_2;
    }
}

u8 FuryFXConvexity::LightActiveOnChasers() {
    KDSoundFader **var_r4_242;
    KDSoundFader *temp_r3_255;

    var_r4_242 = this->unk158;
loop_4:
    if ((var_r4_242 == NULL) || (temp_r3_255 = *var_r4_242, ((temp_r3_255 == NULL) != 0))) {
        return 0U;
    }
    if ((u32) M2C_FIELD(temp_r3_255, u32 *, 0x84) != 0U) {
        return 1U;
    }
    var_r4_242 += 4;
    goto loop_4;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void FuryFXConvexity::DrawDragonChasers() {
    KDSoundFader **var_r31_271;
    KDSoundFader *temp_r4_284;

    var_r31_271 = this->unk158;
loop_2:
    if (var_r31_271 != NULL) {
        temp_r4_284 = *var_r31_271;
        if (temp_r4_284 != NULL) {
            MKModel_SetWorldMatrix(M2C_BITWISE(MKModel *, this->unk1A0.unk40), *((Matrix *) &temp_r4_284->unk30));
            MKModel_Draw(M2C_BITWISE(MKModel *, this->unk1A0.unk40), NULL);
            var_r31_271 += 4;
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void FuryFXConvexity::UpdateDragonChasers() {
    KDSoundFader **temp_r3_1353;
    KDSoundFader **var_r26_328;
    KDSoundFader *temp_r29_1508;
    KDSoundFader *temp_r4_1356;
    MKHeap **temp_r3_366;
    MKHeap *temp_r3_1002;
    MKHeap *temp_r3_1042;
    MKHeap *temp_r3_1385;
    MKHeap *temp_r3_1441;
    ManagedLight *temp_r4_1342;
    f32 *temp_r3_640;
    f32 *temp_r3_938;
    f32 temp_f1_1386;
    f32 temp_f1_334;
    f32 temp_r3_1491;
    f32 var_f1_786;
    f32 var_f22_444;
    f32 var_f22_667;
    f32 var_f2_556;
    f32 var_f3_1172;
    f32 var_f3_539;
    f32 var_f3_762;
    f32 var_f4_1105;
    f32 var_f4_472;
    f32 var_f4_695;
    f64 *temp_r28_342;
    f64 temp_f1_1111;
    f64 temp_f1_1117;
    f64 temp_f1_1121;
    f64 temp_f1_478;
    f64 temp_f1_484;
    f64 temp_f1_488;
    f64 temp_f1_701;
    f64 temp_f1_707;
    f64 temp_f1_711;
    s32 temp_r0_417;
    s32 temp_r3_1140;
    s32 temp_r3_507;
    s32 temp_r3_730;
    s32 var_r0_1150;
    s32 var_r0_517;
    s32 var_r0_740;
    s32 var_r27_331;
    void *temp_r23_1009;
    void *temp_r23_1049;
    void *temp_r23_1398;
    void *temp_r23_1448;
    void *temp_r3_1006;
    void *temp_r3_1046;
    void *temp_r3_1080;
    void *temp_r3_1395;
    void *temp_r3_1445;
    void *temp_r3_1496;
    void *temp_r3_405;
    void *temp_r3_884;
    void *temp_r3_978;
    var_r26_328 = this->unk158;
    var_r27_331 = 0;
loop_113:
    if (var_r26_328 != NULL) {
        temp_r29_1508 = *var_r26_328;
        if (temp_r29_1508 != NULL) {
            temp_f1_334 = M2C_FIELD(temp_r29_1508, f32 *, 0x94);
            if (temp_f1_334 > 0.0f) {
                M2C_FIELD(temp_r29_1508, f32 *, 0x94) = (f32) (temp_f1_334 - gUpdateTimeDelta);
            }
            temp_r28_342 = &temp_r29_1508->unk60;
            arg_sp8 = 1;
            temp_r29_1508->Update(GS_SpyroBreathConvexLP, 1U, M2C_FIELD(temp_r29_1508, u8 *, 0x9C), NULL, (MKVector3 *) temp_r28_342, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            M2C_FIELD(temp_r29_1508, f32 *, 0x88) = (f32) (M2C_FIELD(temp_r29_1508, f32 *, 0x88) - gUpdateTimeDelta);
            if ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL) {
                arg_sp420.GetPos();
                temp_r3_366 = MKModel_GetBoundingVolume(M2C_FIELD(M2C_FIELD(temp_r29_1508, void **, 0x80), MKModel **, 4), (SubObjectType) 0, -1);
                arg_sp30 = (0.5f * M2C_FIELD(temp_r3_366, f32 *, 0x10)) + M2C_FIELD(temp_r3_366, f32 *, 0);
                arg_sp34 = (0.5f * M2C_FIELD(temp_r3_366, f32 *, 0x14)) + M2C_FIELD(temp_r3_366, f32 *, 4);
                arg_sp38 = (0.5f * M2C_FIELD(temp_r3_366, f32 *, 0x18)) + M2C_FIELD(temp_r3_366, f32 *, 8);
                arg_sp430 = (f64) arg_sp30;
                arg_sp438 = (f64) arg_sp38;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp558 = 0.0f;
                arg_sp55C = 0.0f;
                arg_sp148 = (f32) arg_sp438 + arg_sp428;
                arg_sp560 = 0.0f;
                arg_sp554 = 0;
                arg_sp550 = 0xA6;
                arg_sp558 = arg_sp140;
                arg_sp560 = (f64) arg_sp148;
                temp_r3_405 = M2C_FIELD(temp_r29_1508, void **, 0x80);
                arg_sp440 = arg_sp140;
                arg_sp448 = (f64) arg_sp148;
                M2C_FIELD(M2C_FIELD(temp_r3_405, void **, 0x44), M2C_UNK (**)(void *, s32 *, f64, f64, f32, f32), 0x2C)(temp_r3_405, &arg_sp550, (f64) arg_sp148, arg_sp140, (f32) arg_sp438, 0.5f);
                arg_sp520 = (f64) arg_sp558;
                arg_sp528 = (f64) arg_sp560;
            }
            temp_r0_417 = M2C_FIELD(temp_r29_1508, s32 *, 0x98);
            switch (temp_r0_417) {                  /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                M2C_FIELD(temp_r29_1508, u8 *, 0x9C) = 1U;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                var_r27_331 += 1;
                if (M2C_FIELD(temp_r29_1508, f32 *, 0x88) == 0.0f) {
                    M2C_FIELD(temp_r29_1508, s32 *, 0x98) = 2;
                    M2C_FIELD(temp_r29_1508, f32 *, 0x88) = 2.5f;
                }
                var_f22_444 = 3.4028235e38f;
                arg_sp510 = M2C_FIELD(temp_r29_1508, f64 *, 0x70);
                arg_sp518 = M2C_FIELD(temp_r29_1508, f64 *, 0x78);
                if ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp510 = arg_sp130;
                    arg_sp138 = (f32) arg_sp528 - temp_r29_1508->unk68;
                    arg_sp518 = (f64) arg_sp138;
                    arg_sp410 = arg_sp130;
                    arg_sp418 = (f64) arg_sp138;
                    var_f4_472 = ((f32) arg_sp518 * (f32) arg_sp518) + (((f32) arg_sp510 * (f32) arg_sp510) + (arg_sp514 * arg_sp514));
                    if (var_f4_472 > 0.000001f) {
                        if (var_f4_472 > 0.0f) {
                            temp_f1_478 = __frsqrte(var_f4_472);
                            temp_f1_484 = 0.5 * temp_f1_478 * -(((f64) var_f4_472 * (temp_f1_478 * temp_f1_478)) - 3.0);
                            temp_f1_488 = 0.5 * temp_f1_484 * -(((f64) var_f4_472 * (temp_f1_484 * temp_f1_484)) - 3.0);
                            var_f4_472 = (f32) ((f64) var_f4_472 * (0.5 * temp_f1_488 * -(((f64) var_f4_472 * (temp_f1_488 * temp_f1_488)) - 3.0)));
                        } else if (var_f4_472 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_472 = __float_nan;
                        } else {
                            arg_sp18 = var_f4_472;
                            temp_r3_507 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                            switch (temp_r3_507) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                    var_r0_517 = 1;
                                } else {
                                    var_r0_517 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                    var_r0_517 = 5;
                                } else {
                                    var_r0_517 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_517 = 4;
                                break;
                            }
                            if (var_r0_517 == 1) {
                                var_f4_472 = __float_nan;
                            }
                        }
                        var_f3_539 = 1.0f / var_f4_472;
                    } else {
                        var_f3_539 = 0.0f;
                        var_f4_472 = 0.0f;
                    }
                    var_f22_444 = var_f4_472;
                    arg_sp510 = (f32) arg_sp510 * var_f3_539;
                    arg_sp514 *= var_f3_539;
                    arg_sp518 = (f32) arg_sp518 * var_f3_539;
                }
                var_f2_556 = M2C_FIELD(temp_r29_1508, f32 *, 0x88);
                if (var_f2_556 < 3.5f) {

                } else {
                    var_f2_556 = 3.5f;
                }
                if (var_f2_556 > 0.0f) {

                } else {
                    var_f2_556 = 0.0f;
                }
                KDMath_Slerp(*((MKVector3 *) &arg_sp3F0), *((MKVector3 *) &temp_r29_1508->unk70), 0.3f * (1.0f - (var_f2_556 / 3.5f)));
                Normalise(*((MKVector3 *) &arg_sp400));
                M2C_FIELD(temp_r29_1508, f64 *, 0x70) = arg_sp400;
                M2C_FIELD(temp_r29_1508, f64 *, 0x78) = arg_sp408;
                arg_sp500 = temp_r29_1508->unk60;
                arg_sp508 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_sp3D0 = arg_sp200;
                arg_sp208 = (f32) M2C_FIELD(temp_r29_1508, f64 *, 0x78) * 2500.0f;
                arg_sp3D8 = (f64) arg_sp208;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
                arg_sp3E0 = arg_sp1F0;
                arg_sp1F8 = (f32) arg_sp3D8 * gUpdateTimeDelta;
                arg_sp3E8 = (f64) arg_sp1F8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp1D8 = 0.0f;
                arg_sp1D0 = 0.0f;
                arg_sp1D4 = 1.0f;
                arg_sp1E8 = (f32) arg_sp508 + (f32) arg_sp3E8;
                arg_sp4F0 = arg_sp1E0;
                arg_sp4F8 = (f64) arg_sp1E8;
                arg_sp4E0 = (f64) arg_sp1D0;
                arg_sp4E8 = (f64) arg_sp1D8;
                KDMath_BuildMatrixFromFwd((Matrix *) &temp_r29_1508->unk30, *((MKVector3 *) &temp_r29_1508->unk70), (MKVector3 *) &arg_sp4E0);
                temp_r3_640 = &temp_r29_1508->unk30;
                temp_r3_640->Scale3x3((Matrix *) temp_r3_640, 1.0f);
                M2C_FIELD(temp_r29_1508, f64 *, 0x60) = (f32) arg_sp4F0;
                M2C_FIELD(temp_r29_1508, f32 *, 0x64) = arg_sp4F4;
                temp_r29_1508->unk68 = (f32) arg_sp4F8;
                temp_r29_1508->unk6C = 1.0f;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_f22_444 == 200.0f) {
                    M2C_FIELD(temp_r29_1508, f32 *, 0x88) = 15.0f;
                    M2C_FIELD(temp_r29_1508, f32 *, 0x8C) = 0.0f;
                    M2C_FIELD(temp_r29_1508, s32 *, 0x98) = 1;
                }
            default:                                /* switch 1 */
block_105:
                M2C_FIELD(temp_r29_1508, f32 *, 0x90) = (f32) ((10.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r29_1508, f32 *, 0x90));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                temp_r3_1385 = this->unk15C;
                temp_f1_1386 = temp_r29_1508->unk38 * (20.0f * _table_sinf(M2C_FIELD(temp_r29_1508, f32 *, 0x90)));
                arg_sp450 = arg_sp150;
                arg_sp158 = temp_f1_1386;
                arg_sp458 = (f64) arg_sp158;
                temp_r3_1395 = M2C_FIELD(temp_r3_1385->unk44, void *(**)(MKHeap *, f32), 0x3C)(temp_r3_1385, temp_f1_1386);
                if (temp_r3_1395 != NULL) {
                    temp_r23_1398 = M2C_FIELD(temp_r3_1395, void **, 0x2C);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(temp_r3_1395, f64 *, 0) = arg_sp70;
                    arg_sp78 = temp_r29_1508->unk68 + (f32) arg_sp458;
                    arg_sp240 = arg_sp70;
                    M2C_FIELD(temp_r3_1395, f64 *, 8) = (f64) arg_sp78;
                    M2C_FIELD(temp_r3_1395, f32 *, 0x20) = 0.0f;
                    arg_sp248 = (f64) arg_sp78;
                    M2C_FIELD(temp_r3_1395, f32 *, 0x28) = 0.0f;
                    M2C_FIELD(temp_r3_1395, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                    arg_sp60 = 0.0f;
                    arg_sp64 = 0.0f;
                    arg_sp68 = 0.0f;
                    M2C_FIELD(temp_r23_1398, f64 *, 0) = (f64) arg_sp60;
                    M2C_FIELD(temp_r23_1398, f64 *, 8) = (f64) arg_sp68;
                    arg_sp230 = (f64) arg_sp60;
                    arg_sp238 = (f64) arg_sp68;
                    M2C_FIELD(temp_r23_1398, f32 *, 0x18) = 1.0f;
                    M2C_FIELD(temp_r23_1398, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                    M2C_FIELD(temp_r23_1398, f32 *, 0x14) = M2C_BITWISE(f32, this->unk15C->unkF4);
                }
                temp_r3_1441 = this->unk160;
                temp_r3_1445 = M2C_FIELD(temp_r3_1441->unk44, void *(**)(MKHeap *), 0x3C)(temp_r3_1441);
                if (temp_r3_1445 != NULL) {
                    temp_r23_1448 = M2C_FIELD(temp_r3_1445, void **, 0x2C);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_FIELD(temp_r3_1445, f64 *, 0) = arg_sp50;
                    arg_sp58 = temp_r29_1508->unk68 + (f32) arg_sp458;
                    arg_sp220 = arg_sp50;
                    M2C_FIELD(temp_r3_1445, f64 *, 8) = (f64) arg_sp58;
                    M2C_FIELD(temp_r3_1445, f32 *, 0x20) = 0.0f;
                    arg_sp228 = (f64) arg_sp58;
                    M2C_FIELD(temp_r3_1445, f32 *, 0x28) = 0.0f;
                    M2C_FIELD(temp_r3_1445, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                    arg_sp40 = 0.0f;
                    arg_sp44 = 0.0f;
                    arg_sp48 = 0.0f;
                    M2C_FIELD(temp_r23_1448, f64 *, 0) = (f64) arg_sp40;
                    M2C_FIELD(temp_r23_1448, f64 *, 8) = (f64) arg_sp48;
                    M2C_FIELD(temp_r23_1448, f32 *, 0x18) = 1.0f;
                    M2C_FIELD(temp_r23_1448, f32 *, 0x10) = -3.1415927f;
                    arg_sp210 = (f64) arg_sp40;
                    arg_sp218 = (f64) arg_sp48;
                    M2C_FIELD(temp_r23_1448, f32 *, 0x14) = M2C_BITWISE(f32, this->unk160->unkF4);
                }
                if ((ManagedLight *) M2C_FIELD(temp_r29_1508, ManagedLight **, 0x84) != NULL) {
                    temp_r3_1491 = this->unk90.unk68;
                    M2C_FIELD(temp_r3_1491, f64 *, 0x10) = (f64) temp_r29_1508->unk60;
                    M2C_FIELD(temp_r3_1491, f64 *, 0x18) = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                    temp_r3_1496 = M2C_FIELD(temp_r3_1491, void **, 0x3C);
                    if (temp_r3_1496 != NULL) {
                        M2C_FIELD(temp_r3_1496, f64 *, 0x10) = (f64) temp_r29_1508->unk60;
                        M2C_FIELD(temp_r3_1496, f64 *, 0x18) = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                    }
                }
                break;
            case 1:                                 /* switch 1 */
                var_r27_331 += 1;
                var_f22_667 = 3.4028235e38f;
                arg_sp4D0 = M2C_FIELD(temp_r29_1508, f64 *, 0x70);
                arg_sp4D8 = M2C_FIELD(temp_r29_1508, f64 *, 0x78);
                if ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp4D0 = arg_sp120;
                    arg_sp128 = (f32) arg_sp528 - temp_r29_1508->unk68;
                    arg_sp4D8 = (f64) arg_sp128;
                    arg_sp3C0 = arg_sp120;
                    arg_sp3C8 = (f64) arg_sp128;
                    var_f4_695 = ((f32) arg_sp4D8 * (f32) arg_sp4D8) + (((f32) arg_sp4D0 * (f32) arg_sp4D0) + (arg_sp4D4 * arg_sp4D4));
                    if (var_f4_695 > 0.000001f) {
                        if (var_f4_695 > 0.0f) {
                            temp_f1_701 = __frsqrte(var_f4_695);
                            temp_f1_707 = 0.5 * temp_f1_701 * -(((f64) var_f4_695 * (temp_f1_701 * temp_f1_701)) - 3.0);
                            temp_f1_711 = 0.5 * temp_f1_707 * -(((f64) var_f4_695 * (temp_f1_707 * temp_f1_707)) - 3.0);
                            var_f4_695 = (f32) ((f64) var_f4_695 * (0.5 * temp_f1_711 * -(((f64) var_f4_695 * (temp_f1_711 * temp_f1_711)) - 3.0)));
                        } else if (var_f4_695 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_695 = __float_nan;
                        } else {
                            arg_sp14 = var_f4_695;
                            temp_r3_730 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                            switch (temp_r3_730) {  /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_740 = 1;
                                } else {
                                    var_r0_740 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_740 = 5;
                                } else {
                                    var_r0_740 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_740 = 4;
                                break;
                            }
                            if (var_r0_740 == 1) {
                                var_f4_695 = __float_nan;
                            }
                        }
                        var_f3_762 = 1.0f / var_f4_695;
                    } else {
                        var_f3_762 = 0.0f;
                        var_f4_695 = 0.0f;
                    }
                    var_f22_667 = var_f4_695;
                    arg_sp4D0 = (f32) arg_sp4D0 * var_f3_762;
                    arg_sp4D4 *= var_f3_762;
                    arg_sp4D8 = (f32) arg_sp4D8 * var_f3_762;
                }
                M2C_FIELD(temp_r29_1508, f32 *, 0x8C) = (f32) (M2C_FIELD(temp_r29_1508, f32 *, 0x8C) + gUpdateTimeDelta);
                var_f1_786 = _table_sinf(2.0f * M2C_FIELD(temp_r29_1508, f32 *, 0x8C));
                if (var_f1_786 < 0.0f) {
                    var_f1_786 = -var_f1_786;
                }
                KDMath_Slerp(*((MKVector3 *) &arg_sp3A0), *((MKVector3 *) &temp_r29_1508->unk70), 5.0f * (gUpdateTimeDelta * var_f1_786));
                Normalise(*((MKVector3 *) &arg_sp3B0));
                M2C_FIELD(temp_r29_1508, f64 *, 0x70) = arg_sp3B0;
                M2C_FIELD(temp_r29_1508, f64 *, 0x78) = arg_sp3B8;
                arg_sp4C0 = temp_r29_1508->unk60;
                arg_sp4C8 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                arg_sp380 = arg_sp1C0;
                arg_sp1C8 = (f32) M2C_FIELD(temp_r29_1508, f64 *, 0x78) * 3500.0f;
                arg_sp388 = (f64) arg_sp1C8;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                arg_sp390 = arg_sp1B0;
                arg_sp1B8 = (f32) arg_sp388 * gUpdateTimeDelta;
                arg_sp398 = (f64) arg_sp1B8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp4B0 = arg_sp1A0;
                arg_sp1A8 = (f32) arg_sp4C8 + (f32) arg_sp398;
                arg_sp4B8 = (f64) arg_sp1A8;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r29_1508, f32 *, 0x88) == 0.0f) {
                    arg_sp118 = -1.0f;
                    M2C_FIELD(temp_r29_1508, s32 *, 0x98) = 2;
                    arg_sp108 = 1.0f;
                    M2C_FIELD(temp_r29_1508, f32 *, 0x88) = 2.5f;
                    arg_sp110 = -1.0f;
                    arg_sp114 = -1.0f;
                    arg_sp100 = 1.0f;
                    arg_sp104 = 1.0f;
                    arg_sp310 = (f64) arg_sp110;
                    arg_sp318 = (f64) arg_sp118;
                    arg_sp300 = (f64) arg_sp100;
                    arg_sp308 = (f64) arg_sp108;
                    KDRand_Vector(*((MKVector3 *) &arg_sp320), *((MKVector3 *) &arg_sp310));
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                    temp_r3_884 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                    arg_sp330 = arg_spF0;
                    arg_spF8 = arg_sp328 * 500.0f;
                    arg_sp340 = M2C_FIELD(temp_r3_884, f64 *, 0x30);
                    arg_sp338 = (f64) arg_spF8;
                    arg_sp348 = M2C_FIELD(temp_r3_884, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp350 = arg_spE0;
                    arg_spE8 = (f32) arg_sp348 + (f32) arg_sp338;
                    arg_sp358 = (f64) arg_spE8;
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp360 = arg_spD0;
                    arg_spD8 = (f32) arg_sp358 - (f32) arg_sp4B8;
                    arg_sp368 = (f64) arg_spD8;
                    Normalise(*((MKVector3 *) &arg_sp370));
                    M2C_FIELD(temp_r29_1508, f64 *, 0x70) = arg_sp370;
                    M2C_FIELD(temp_r29_1508, f64 *, 0x78) = arg_sp378;
                }
                arg_sp198 = 0.0f;
                arg_sp190 = 0.0f;
                arg_sp194 = 1.0f;
                arg_sp4A8 = (f64) arg_sp198;
                arg_sp4A0 = (f64) arg_sp190;
                KDMath_BuildMatrixFromFwd((Matrix *) &temp_r29_1508->unk30, *((MKVector3 *) &temp_r29_1508->unk70), (MKVector3 *) &arg_sp4A0);
                temp_r3_938 = &temp_r29_1508->unk30;
                temp_r3_938->Scale3x3((Matrix *) temp_r3_938, 1.0f);
                M2C_FIELD(temp_r29_1508, f64 *, 0x60) = (f32) arg_sp4B0;
                M2C_FIELD(temp_r29_1508, f32 *, 0x64) = arg_sp4B4;
                temp_r29_1508->unk68 = (f32) arg_sp4B8;
                temp_r29_1508->unk6C = 1.0f;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((var_f22_667 == 200.0f) && ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL)) {
                    M2C_FIELD(temp_r29_1508, f32 *, 0x8C) = 0.0f;
                    arg_sp5B4 = 0;
                    arg_sp5B0.Init(M2C_FIELD(gb.unk0->__vptr, MKProp *(**)(HeroInterface *), 0xC)(gb.unk0), 0.5f, 3, 0, 4, 0, 1, -1);
                    temp_r3_978 = M2C_FIELD(temp_r29_1508, void **, 0x80);
                    M2C_FIELD(M2C_FIELD(temp_r3_978, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(temp_r3_978, &arg_sp5B0);
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (var_f22_667 == 50.0f) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if (M2C_FIELD(temp_r29_1508, f32 *, 0x94) == 0.0f) {
                            KDSound_Play3d(GS_SpyroFuryConvexExtra3, (MKVector3 *) temp_r28_342, 0U, -1, 0.0f, 0U);
                            M2C_FIELD(temp_r29_1508, f32 *, 0x94) = 2.0f;
                        }
                    }
                    temp_r3_1002 = this->unk15C;
                    temp_r3_1006 = M2C_FIELD(temp_r3_1002->unk44, void *(**)(MKHeap *), 0x3C)(temp_r3_1002);
                    if (temp_r3_1006 != NULL) {
                        temp_r23_1009 = M2C_FIELD(temp_r3_1006, void **, 0x2C);
                        M2C_FIELD(temp_r3_1006, f64 *, 0) = (f64) temp_r29_1508->unk60;
                        M2C_FIELD(temp_r3_1006, f64 *, 8) = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                        M2C_FIELD(temp_r3_1006, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_1006, f32 *, 0x28) = 0.0f;
                        M2C_FIELD(temp_r3_1006, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                        arg_spC0 = 0.0f;
                        arg_spC4 = 0.0f;
                        arg_spC8 = 0.0f;
                        M2C_FIELD(temp_r23_1009, f64 *, 0) = (f64) arg_spC0;
                        M2C_FIELD(temp_r23_1009, f64 *, 8) = (f64) arg_spC8;
                        arg_sp2F0 = (f64) arg_spC0;
                        arg_sp2F8 = (f64) arg_spC8;
                        M2C_FIELD(temp_r23_1009, f32 *, 0x18) = 6.0f;
                        M2C_FIELD(temp_r23_1009, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                        M2C_FIELD(temp_r23_1009, f32 *, 0x14) = M2C_BITWISE(f32, this->unk15C->unkF4);
                    }
                    temp_r3_1042 = this->unk160;
                    temp_r3_1046 = M2C_FIELD(temp_r3_1042->unk44, void *(**)(MKHeap *), 0x3C)(temp_r3_1042);
                    if (temp_r3_1046 != NULL) {
                        temp_r23_1049 = M2C_FIELD(temp_r3_1046, void **, 0x2C);
                        M2C_FIELD(temp_r3_1046, f64 *, 0) = (f64) temp_r29_1508->unk60;
                        M2C_FIELD(temp_r3_1046, f64 *, 8) = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                        M2C_FIELD(temp_r3_1046, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_1046, f32 *, 0x28) = 0.0f;
                        M2C_FIELD(temp_r3_1046, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                        arg_spB0 = 0.0f;
                        arg_spB4 = 0.0f;
                        arg_spB8 = 0.0f;
                        M2C_FIELD(temp_r23_1049, f64 *, 0) = (f64) arg_spB0;
                        M2C_FIELD(temp_r23_1049, f64 *, 8) = (f64) arg_spB8;
                        M2C_FIELD(temp_r23_1049, f32 *, 0x18) = 3.0f;
                        M2C_FIELD(temp_r23_1049, f32 *, 0x10) = -3.1415927f;
                        arg_sp2E0 = (f64) arg_spB0;
                        arg_sp2E8 = (f64) arg_spB8;
                        M2C_FIELD(temp_r23_1049, f32 *, 0x14) = M2C_BITWISE(f32, this->unk160->unkF4);
                    }
                    temp_r3_1080 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                    arg_sp490 = M2C_FIELD(temp_r3_1080, f64 *, 0x30);
                    arg_sp498 = M2C_FIELD(temp_r3_1080, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_sp2D0 = arg_sp180;
                    arg_sp188 = temp_r29_1508->unk68 - (f32) arg_sp498;
                    arg_sp2D8 = (f64) arg_sp188;
                    var_f4_1105 = ((f32) arg_sp2D8 * (f32) arg_sp2D8) + (((f32) arg_sp2D0 * (f32) arg_sp2D0) + (arg_sp2D4 * arg_sp2D4));
                    if (var_f4_1105 > 1e-12f) {
                        if (var_f4_1105 > 0.0f) {
                            temp_f1_1111 = __frsqrte(var_f4_1105);
                            temp_f1_1117 = 0.5 * temp_f1_1111 * -(((f64) var_f4_1105 * (temp_f1_1111 * temp_f1_1111)) - 3.0);
                            temp_f1_1121 = 0.5 * temp_f1_1117 * -(((f64) var_f4_1105 * (temp_f1_1117 * temp_f1_1117)) - 3.0);
                            var_f4_1105 = (f32) ((f64) var_f4_1105 * (0.5 * temp_f1_1121 * -(((f64) var_f4_1105 * (temp_f1_1121 * temp_f1_1121)) - 3.0)));
                        } else if (var_f4_1105 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1105 = __float_nan;
                        } else {
                            arg_sp10 = var_f4_1105;
                            temp_r3_1140 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                            switch (temp_r3_1140) { /* switch 4; irregular */
                            case 0x7F800000:        /* switch 4 */
                                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                    var_r0_1150 = 1;
                                } else {
                                    var_r0_1150 = 2;
                                }
                                break;
                            case 0x0:               /* switch 4 */
                                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                    var_r0_1150 = 5;
                                } else {
                                    var_r0_1150 = 3;
                                }
                                break;
                            default:                /* switch 4 */
                                var_r0_1150 = 4;
                                break;
                            }
                            if (var_r0_1150 == 1) {
                                var_f4_1105 = __float_nan;
                            }
                        }
                        var_f3_1172 = 1.0f / var_f4_1105;
                    } else {
                        var_f3_1172 = 0.0f;
                    }
                    arg_sp170 = (f32) arg_sp2D0 * var_f3_1172;
                    arg_sp174 = arg_sp2D4 * var_f3_1172;
                    arg_sp178 = (f32) arg_sp2D8 * var_f3_1172;
                    arg_sp480 = (f64) arg_sp170;
                    arg_sp488 = (f64) arg_sp178;
                    M2C_STRUCT_COPY((s32) &arg_sp56C + 4, (s32) (&identity - 4) + 4, 0x40);
                    arg_sp168 = 0.0f;
                    arg_sp160 = 0.0f;
                    arg_sp164 = 1.0f;
                    arg_sp478 = (f64) arg_sp168;
                    arg_sp470 = (f64) arg_sp160;
                    KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp570, *((MKVector3 *) &arg_sp480), (MKVector3 *) &arg_sp470);
                    arg_sp570.Scale3x3((Matrix *) &arg_sp570, 1.5f);
                    arg_sp20 = -(f32) arg_sp480;
                    arg_sp24 = -arg_sp484;
                    arg_sp28 = -(f32) arg_sp488;
                    arg_sp2A0 = (f64) arg_sp20;
                    arg_sp2A8 = (f64) arg_sp28;
                    arg_sp2B0.operator*(300.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp2C0 = arg_spA0;
                    arg_spA8 = temp_r29_1508->unk68 + arg_sp2B8;
                    arg_sp2C8 = (f64) arg_spA8;
                    arg_sp5A0 = (f32) arg_sp2C0;
                    arg_sp5A4 = arg_sp2C4;
                    arg_sp5A8 = (f32) arg_sp2C8;
                    arg_sp5AC = 1.0f;
                    gb.unk1C0.StartWarp((Matrix *) &arg_sp570);
                    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                        arg_sp534 = 0;
                        MKVector(1.0f, 1.0f, 1.0f);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                        arg_sp530 = 0x417;
                        arg_sp538 = arg_sp90;
                        arg_sp98 = arg_sp288 * 150.0f;
                        arg_sp548 = 1;
                        arg_sp540 = (f64) arg_sp98;
                        arg_sp290 = arg_sp90;
                        arg_sp298 = (f64) arg_sp98;
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp530, arg_sp90);
                    }
                }
                goto block_105;
            case 2:                                 /* switch 1 */
                arg_sp460 = temp_r29_1508->unk60;
                arg_sp468 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                arg_sp250.operator*(gUpdateTimeDelta);
                arg_sp260.operator*(2500.0f);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp270 = arg_sp80;
                arg_sp88 = (f32) arg_sp468 + arg_sp268;
                M2C_FIELD(temp_r29_1508, f64 *, 0x60) = (f32) arg_sp270;
                arg_sp278 = (f64) arg_sp88;
                M2C_FIELD(temp_r29_1508, f32 *, 0x64) = arg_sp274;
                temp_r29_1508->unk68 = (f32) arg_sp278;
                temp_r29_1508->unk6C = 1.0f;
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r29, $r0, 0x0, qr0 */);
                M2C_FIELD(temp_r29_1508, f64 *, 0x78) = (f32) ((f32) M2C_FIELD(temp_r29_1508, f64 *, 0x78) * 1.1f);
                M2C_FIELD(temp_r29_1508, u8 *, 0x9C) = 0U;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (M2C_FIELD(temp_r29_1508, f32 *, 0x88) == 0.0f) {
                    temp_r4_1342 = M2C_FIELD(temp_r29_1508, ManagedLight **, 0x84);
                    if (temp_r4_1342 != NULL) {
                        gb.unk80->EnableLight(temp_r4_1342, 0U);
                        M2C_FIELD(temp_r29_1508, ManagedLight **, 0x84) = NULL;
                    }
                    KDSound_Stop(&temp_r29_1508->unk0);
                    temp_r3_1353 = this->unk158;
                    this->unk158 = temp_r3_1353 + 4;
                    temp_r4_1356 = *temp_r3_1353;
                    *temp_r3_1353 = *var_r26_328;
                    *var_r26_328 = temp_r4_1356;
                    if ((KDSoundFader *) *this->unk158 == NULL) {
                        Disable();
                    }
                } else {
                    goto block_105;
                }
                break;
            }
            var_r26_328 += 4;
            goto loop_113;
        }
    }
    if (((u8) gb.unk381 != 0) && ((s32) this->unk90.unk60 == 0) && (var_r27_331 <= 0)) {
        gb.unk381 = 0;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
s32 FuryFXConvexity::LaunchDragonChaser(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    M2C_UNK spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    M2C_UNK sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    KDSoundFader **temp_r3_1568;
    KDSoundFader **temp_r3_1575;
    KDSoundFader *temp_r31_1580;
    TargetManager ***var_r27_1691;
    TargetManager **temp_r30_1868;
    f32 *temp_r3_1600;
    f32 temp_f1_1958;
    f32 temp_r3_1638;
    f32 temp_r3_1649;
    f32 temp_r3_1669;
    f32 temp_r4_1630;
    f32 var_f0_1959;
    f32 var_f29_1686;
    f32 var_f30_1754;
    f32 var_f3_1821;
    f64 temp_f0_1640;
    f64 temp_f1_1639;
    f64 temp_f1_1760;
    f64 temp_f1_1766;
    f64 temp_f1_1770;
    s32 temp_r3_1789;
    s32 var_r0_1799;
    s32 var_r27_1877;
    void *temp_r3_1643;
    void *temp_r3_1652;
    void *temp_r3_1677;
    void *temp_r3_1729;
    void *var_r28_1688;

    temp_r3_1568 = this->unk158;
    if ((u32) M2C_FIELD(temp_r3_1568, u32 *, -4) == 0U) {
        return 0;
    }
    temp_r3_1575 = temp_r3_1568 - 4;
    this->unk158 = temp_r3_1575;
    temp_r31_1580 = *temp_r3_1575;
    sp78 = 0.0f;
    M2C_FIELD(temp_r31_1580, s32 *, 0x98) = 0;
    M2C_FIELD(temp_r31_1580, f32 *, 0x88) = 3.5f;
    M2C_FIELD(temp_r31_1580, f64 *, 0x70) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r31_1580, f64 *, 0x78) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD(temp_r31_1580, f32 *, 0x94) = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp198 = (f64) sp78;
    sp190 = (f64) sp70;
    KDMath_BuildMatrixFromFwd((Matrix *) &temp_r31_1580->unk30, *((MKVector3 *) &temp_r31_1580->unk70), (MKVector3 *) &sp190);
    temp_r3_1600 = &temp_r31_1580->unk30;
    temp_r3_1600->Scale3x3((Matrix *) temp_r3_1600, 1.0f);
    M2C_FIELD(temp_r31_1580, f32 *, 0x60) = (f32) arg0.unk0;
    M2C_FIELD(temp_r31_1580, f32 *, 0x64) = (f32) arg0.unk4;
    temp_r31_1580->unk68 = arg0.unk8;
    temp_r31_1580->unk6C = 1.0f;
    M2C_FIELD(temp_r31_1580, f32 *, 0x90) = 0.0f;
    temp_r31_1580->Init(0.75f, 0.5f);
    M2C_FIELD(temp_r31_1580, f32 *, 0x84) = (f32) this->unk90.unk68;
    M2C_FIELD(temp_r31_1580, s8 *, 0x9C) = 0;
    KDSound_Play3d(GS_SpyroBreathConvex1, (MKVector3 *) &temp_r31_1580->unk60, 0U, -1, 0.0f, 0U);
    temp_r4_1630 = this->unk90.unk68;
    if (M2C_BITWISE(u32, temp_r4_1630) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_1630), 1U);
        temp_r3_1638 = this->unk90.unk68;
        temp_f1_1639 = (f64) M2C_FIELD(&arg0, f32 *, 0);
        temp_f0_1640 = (f64) M2C_FIELD(&arg0, f32 *, 8);
        M2C_FIELD(temp_r3_1638, f64 *, 0x10) = temp_f1_1639;
        M2C_FIELD(temp_r3_1638, f64 *, 0x18) = temp_f0_1640;
        temp_r3_1643 = M2C_FIELD(temp_r3_1638, void **, 0x3C);
        if (temp_r3_1643 != NULL) {
            M2C_FIELD(temp_r3_1643, f64 *, 0x10) = temp_f1_1639;
            M2C_FIELD(temp_r3_1643, f64 *, 0x18) = temp_f0_1640;
        }
        temp_r3_1649 = this->unk90.unk68;
        M2C_FIELD(temp_r3_1649, f32 *, 0x38) = 2000.0f;
        temp_r3_1652 = M2C_FIELD(temp_r3_1649, void **, 0x3C);
        if (temp_r3_1652 != NULL) {
            M2C_FIELD(temp_r3_1652, f32 *, 0x20) = 2000.0f;
            M2C_FIELD(temp_r3_1652, f32 *, 0x24) = 4000000.0f;
            M2C_FIELD(temp_r3_1652, f32 *, 0x28) = 0.0005f;
            M2C_FIELD(temp_r3_1652, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1652, f32 *, 0x24));
        }
        sp40 = 1.0f;
        temp_r3_1669 = this->unk90.unk68;
        sp44 = 0.0f;
        sp48 = 0.75f;
        sp4C = 1.0f;
        M2C_FIELD(temp_r3_1669, f64 *, 0x20) = (f64) sp40;
        M2C_FIELD(temp_r3_1669, f64 *, 0x28) = (f64) sp48;
        temp_r3_1677 = M2C_FIELD(temp_r3_1669, void **, 0x3C);
        sp150 = (f64) sp40;
        sp158 = (f64) sp48;
        if (temp_r3_1677 != NULL) {
            M2C_FIELD(temp_r3_1677, f64 *, 0) = (f64) sp40;
            M2C_FIELD(temp_r3_1677, f64 *, 8) = (f64) sp48;
        }
    }
    var_f29_1686 = 3.4028235e38f;
    var_r28_1688 = NULL;
    var_r27_1691 = gb.unk20->Begin();
loop_41:
    if (var_r27_1691 != NULL) {
        temp_r30_1868 = *var_r27_1691;
        if (temp_r30_1868 != NULL) {
            if (((*temp_r30_1868)->unk8.unk0(temp_r30_1868) != NULL) && (M2C_FIELD(*temp_r30_1868, u8 (**)(TargetManager **), 0x18)(temp_r30_1868) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r30_1868)->unk8.unk4)(temp_r30_1868) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r30_1868)->unk8.unk4)(temp_r30_1868)))->IsActive() != 0))) {
                temp_r3_1729 = M2C_FIELD((*temp_r30_1868)->unk8.unk0(temp_r30_1868), void **, 8);
                sp140 = M2C_FIELD(temp_r3_1729, f64 *, 0x30);
                sp148 = M2C_FIELD(temp_r3_1729, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r26, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp180 = sp60;
                sp68 = (f32) sp148 - arg0.unk8;
                sp188 = (f64) sp68;
                var_f30_1754 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + (unksp184 * unksp184));
                if (var_f30_1754 > 0.000001f) {
                    if (var_f30_1754 > 0.0f) {
                        temp_f1_1760 = __frsqrte(var_f30_1754);
                        temp_f1_1766 = 0.5 * temp_f1_1760 * -(((f64) var_f30_1754 * (temp_f1_1760 * temp_f1_1760)) - 3.0);
                        temp_f1_1770 = 0.5 * temp_f1_1766 * -(((f64) var_f30_1754 * (temp_f1_1766 * temp_f1_1766)) - 3.0);
                        var_f30_1754 = (f32) ((f64) var_f30_1754 * (0.5 * temp_f1_1770 * -(((f64) var_f30_1754 * (temp_f1_1770 * temp_f1_1770)) - 3.0)));
                    } else if (var_f30_1754 < M2C_BITWISE(f32, 0.0)) {
                        var_f30_1754 = __float_nan;
                    } else {
                        sp8 = var_f30_1754;
                        temp_r3_1789 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_1789) {     /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1799 = 1;
                            } else {
                                var_r0_1799 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_1799 = 5;
                            } else {
                                var_r0_1799 = 3;
                            }
                            break;
                        default:
                            var_r0_1799 = 4;
                            break;
                        }
                        if (var_r0_1799 == 1) {
                            var_f30_1754 = __float_nan;
                        }
                    }
                    var_f3_1821 = 1.0f / var_f30_1754;
                } else {
                    var_f3_1821 = 0.0f;
                    var_f30_1754 = 0.0f;
                }
                sp180 = (f32) sp180 * var_f3_1821;
                unksp184 *= var_f3_1821;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((var_f30_1754 == 5000.0f) && (var_f30_1754 < var_f29_1686)) {
                    if (var_r28_1688 != NULL) {
                        if (MKRand_Int(&gViewSeed, 0, 3) == 0) {
                            var_f29_1686 = var_f30_1754;
                            var_r28_1688 = (*temp_r30_1868)->unk8.unk0(temp_r30_1868);
                        }
                    } else {
                        var_f29_1686 = var_f30_1754;
                        var_r28_1688 = (*temp_r30_1868)->unk8.unk0(temp_r30_1868);
                    }
                }
            }
            var_r27_1691 += 4;
            goto loop_41;
        }
    }
    M2C_FIELD(temp_r31_1580, void **, 0x80) = var_r28_1688;
    var_r27_1877 = 0;
    do {
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(sp110, sp100);
        sp120.operator*(100.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp130 = sp30;
        sp38 = temp_r31_1580->unk68 + sp120.unk8;
        sp170 = sp30;
        sp138 = (f64) sp38;
        sp178 = (f64) sp38;
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(spB0, spA0);
        spC0.operator*(0.75f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spD0 = sp10;
        sp18 = (f32) M2C_FIELD(temp_r31_1580, f64 *, 0x78) + spC0.unk8;
        spD8 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spE0 = sp20;
        sp28 = (f32) spD8 * 1000.0f;
        sp160 = sp20;
        spE8 = (f64) sp28;
        sp168 = (f64) sp28;
        temp_f1_1958 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        var_f0_1959 = 0.5f + temp_f1_1958;
        if (var_f0_1959 < 1.0f) {

        } else {
            var_f0_1959 = 1.0f;
        }
        if (var_f0_1959 > 0.0f) {

        } else {
            var_f0_1959 = 0.0f;
        }
        sp54 = temp_f1_1958;
        sp50 = 1.0f;
        sp58 = var_f0_1959;
        sp5C = 1.0f;
        sp80 = (f64) sp50;
        sp88 = (f64) sp58;
        spC = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
        gb.unk74->Emit(*((MKVector3 *) &sp170), *((MKVector3 *) &sp160), spC, *((MKVector4 *) &sp80), 0.0f);
        var_r27_1877 += 1;
    } while (var_r27_1877 < 0x14);
    return 1;
}
#endif

#if 0 // DRAFT: pointer/array required
void FuryFXConvexity::ResetFury() {
    s32 spC;
    s32 sp8;
    f32 temp_r4_2026;

    SetDefaults();
    Disable();
    temp_r4_2026 = this->unk90.unk68;
    if (M2C_BITWISE(u32, temp_r4_2026) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_2026), 0U);
    }
    gb.unk2CC.Disable(this->unk168);
    this->unk168 = -1;
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2CC'
s32 FuryFXConvexity::Trigger(const MKVector3 &arg0) {
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    M2C_UNK spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    MKVector3 spB0;
    M2C_UNK spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    M2C_UNK sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f27_2165;
    f32 temp_r3_2266;
    f32 temp_r4_2244;
    s32 var_r28_2138;
    void *temp_r3_2272;

    Enable();
    this->unk90.unk30 = arg0.unk0;
    this->unk90.unk34 = arg0.unk4;
    this->unk90.unk38 = arg0.unk8;
    this->unk90.unk3C = 1.0f;
    if ((s32) this->unk90.unk60 == 0) {
        this->unk168 = gb.unk2CC.Enable(0.1f, 3.0f, 0.75f, 15.0f);
        this->unk90.unk60 = 1;
        this->unk150 = 0.0f;
        this->unk14C = 1;
        this->unk90.unk64 = 1.0f;
        M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(&arg0, f32 *, 0);
        M2C_FIELD(this, f64 *, 0xE8) = (f64) M2C_FIELD(&arg0, f32 *, 8);
        KDSound_Play3d(GS_SpyroFuryConvexExtra1, (MKVector3 *) &this->unk90.unk50, 0U, -1, 0.0f, 0U);
        MKVector(0.0f, 500.0f, 0.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        var_r28_2138 = 0;
        M2C_FIELD(this, f64 *, 0xD0) = sp30;
        sp38 = this->unk90.unk58 + spF8;
        sp100 = sp30;
        M2C_FIELD(this, f64 *, 0xD8) = (f64) sp38;
        this->unk164 = 0.0f;
        this->unk170.unk20 = (f64) M2C_FIELD(&arg0, f32 *, 0);
        sp108 = (f64) sp38;
        this->unk170.unk28 = (f64) M2C_FIELD(&arg0, f32 *, 8);
        do {
            sp120 = M2C_FIELD(this, f64 *, 0xE0);
            sp128 = M2C_FIELD(this, f64 *, 0xE8);
            temp_f27_2165 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(spC0, spB0);
            Normalise(spD0);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            spE0 = sp20;
            sp28 = spD0.unk8 * temp_f27_2165;
            sp110 = sp20;
            spE8 = (f64) sp28;
            sp118 = (f64) sp28;
            sp58 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            sp5C = 1.0f;
            sp50 = 1.0f;
            sp54 = 0.0f;
            sp98 = (f64) sp58;
            sp90 = (f64) sp50;
            sp8 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &sp120), *((MKVector3 *) &sp110), sp8, *((MKVector4 *) &sp90), -580.0f);
            var_r28_2138 += 1;
        } while (var_r28_2138 < 0x96);
        sp40 = 1.0f;
        sp44 = 0.0f;
        sp48 = 0.2f;
        sp4C = 1.0f;
        sp80 = (f64) sp40;
        sp88 = (f64) sp48;
        gb.GetSpyro();
        ((CharacterGlowFX *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x260), void **, 4), CharacterGlowFX **, 0x28)))->Enable(1U, *((MKVector4 *) &sp80), 10.0f);
        temp_r4_2244 = this->unk90.unk68;
        if (M2C_BITWISE(u32, temp_r4_2244) != 0U) {
            gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_2244), 1U);
            MKVector(0.0f, 100.0f, 0.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            temp_r3_2266 = this->unk90.unk68;
            sp70 = sp10;
            sp18 = this->unk90.unk58 + sp68;
            M2C_FIELD(temp_r3_2266, f64 *, 0x10) = sp10;
            M2C_FIELD(temp_r3_2266, f64 *, 0x18) = (f64) sp18;
            temp_r3_2272 = M2C_FIELD(temp_r3_2266, void **, 0x3C);
            sp78 = (f64) sp18;
            if (temp_r3_2272 != NULL) {
                M2C_FIELD(temp_r3_2272, f64 *, 0x10) = sp10;
                M2C_FIELD(temp_r3_2272, f64 *, 0x18) = (f64) sp18;
            }
        }
        gb.unk381 = 1;
        return 1;
    }
    return 0;
}
#endif

void FuryFXConvexity::SetDefaults() {
    SetDefaults();
    this->unk90.unk60 = 0;
    this->unk90.SetIdentity();
    this->unk90.unk64 = 0.0f;
    this->unk14C = 0;
    this->unk164 = 0.0f;
}

#if 0 // DRAFT: pointer/array required
void FuryFXConvexity::Deinit() {
    KDSoundFader **var_r31_2359;
    KDSoundFader **var_r3_2360;
    KDSoundFader **var_r4_2358;
    KDSoundFader *temp_r0_2363;
    KDSoundFader *temp_r0_2382;
    MKHeap *temp_r3_2385;
    f32 temp_r4_2338;
    u32 temp_r0_2368;

    temp_r4_2338 = this->unk90.unk68;
    if (M2C_BITWISE(u32, temp_r4_2338) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_2338), 0U);
        gb.unk80->FreeManagedLight(M2C_BITWISE(ManagedLight *, this->unk90.unk68));
        this->unk90.unk68 = 0.0f;
    }
    MKModel_Destroy(M2C_BITWISE(MKModel *, this->unk1A0.unk40));
    KDSound_Stop((s32 *) &this->unk90.unk6C);
    KDSound_Stop(&this->unk124);
    var_r4_2358 = this->unk158;
    var_r31_2359 = var_r4_2358;
    var_r3_2360 = var_r4_2358;
loop_5:
    temp_r0_2368 = M2C_FIELD(var_r3_2360, u32 *, -4);
    var_r3_2360 -= 4;
    if (temp_r0_2368 != 0U) {
        temp_r0_2363 = *var_r3_2360;
        if (temp_r0_2363 < var_r31_2359) {
            var_r31_2359 = (KDSoundFader **) temp_r0_2363;
        }
        goto loop_5;
    }
    if (var_r3_2360 != &gEmptyPtrListDL) {
loop_11:
        temp_r0_2382 = *var_r4_2358;
        if (temp_r0_2382 != NULL) {
            if (temp_r0_2382 < var_r31_2359) {
                var_r31_2359 = (KDSoundFader **) temp_r0_2382;
            }
            var_r4_2358 += 4;
            goto loop_11;
        }
        temp_r3_2385 = var_r3_2360->Current();
        if (temp_r3_2385 != NULL) {
            ((MKHeap *) (temp_r3_2385->Current()))->Free(var_r31_2359, NULL, 0);
        } else {
            free(var_r31_2359);
        }
    }
    this->unk158 = NULL;
    FuryFX::Deinit();
}
#endif

void FuryFXConvexity::Draw() {
    DrawDragonChasers();
}

#if 0 // DRAFT: undefined identifier 'Message'
void FuryFXConvexity::Message(MKMessage *arg0) {
    KDSoundFader **var_r31_2431;
    KDSoundFader *temp_r3_2440;

    var_r31_2431 = this->unk158;
loop_2:
    if (var_r31_2431 != NULL) {
        temp_r3_2440 = *var_r31_2431;
        if (temp_r3_2440 != NULL) {
            temp_r3_2440->Message(arg0);
            var_r31_2431 += 4;
            goto loop_2;
        }
    }
    this->unk90.unk6C.Message(arg0);
    this->unk124.Message(arg0);
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void FuryFXConvexity::Update() {
    f32 temp_f14_2737;
    f32 temp_f14_3057;
    f32 temp_f14_3281;
    f32 temp_f14_3383;
    f32 temp_f14_3659;
    f32 temp_f15_2623;
    f32 temp_f15_3139;
    f32 temp_f15_3203;
    f32 temp_f15_3662;
    f32 temp_f16_3144;
    f32 temp_f16_3208;
    f32 temp_f1_2680;
    f32 temp_f1_3983;
    f32 temp_f1_3987;
    f32 temp_f1_4026;
    f32 temp_f2_2558;
    f32 temp_f2_2572;
    f32 temp_r3_4111;
    f32 temp_r4_2542;
    f32 var_f0_3480;
    f32 var_f0_4079;
    f32 var_f15_2660;
    f32 var_f15_3998;
    f32 var_f2_3976;
    f32 var_f3_2933;
    f32 var_f3_2993;
    f32 var_f3_3794;
    f32 var_f3_3912;
    f32 var_f4_2866;
    f32 var_f4_3535;
    f32 var_f4_3727;
    f32 var_f4_3845;
    f64 temp_f1_2872;
    f64 temp_f1_2878;
    f64 temp_f1_2882;
    f64 temp_f1_3540;
    f64 temp_f1_3546;
    f64 temp_f1_3550;
    f64 temp_f1_3733;
    f64 temp_f1_3739;
    f64 temp_f1_3743;
    f64 temp_f1_3851;
    f64 temp_f1_3857;
    f64 temp_f1_3861;
    s32 temp_r0_2643;
    s32 temp_r3_2901;
    s32 temp_r3_3569;
    s32 temp_r3_3762;
    s32 temp_r3_3880;
    s32 var_r0_2911;
    s32 var_r0_3579;
    s32 var_r0_3772;
    s32 var_r0_3890;
    s32 var_r28_3629;
    void *temp_r3_2842;
    void *temp_r3_3511;
    void *temp_r3_3821;
    void *temp_r3_4141;
    this->unk90.unk64 = this->unk90.unk64 - gUpdateTimeDelta;
    arg_sp8 = 1;
    this->unk90.unk6C.Update(GS_SpyroFuryConvexLP1, 1U, this->unk14C, NULL, (MKVector3 *) &this->unk90.unk40, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    arg_sp8 = 1;
    this->unk124.Update(GS_SpyroFuryConvexLP3, 1U, this->unk14D, NULL, (MKVector3 *) &this->unk90.unk40, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    UpdateDragonChasers();
    if ((LightActiveOnChasers() == 0) && ((s32) this->unk90.unk60 == 0)) {
        temp_r4_2542 = this->unk90.unk68;
        if (M2C_BITWISE(u32, temp_r4_2542) != 0U) {
            gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_2542), 0U);
        }
    }
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (this->unk150 == 0.0f) {
        this->unk154 = 0.0f;
        temp_f2_2558 = this->unk150;
        if (temp_f2_2558 > 1.43f) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f2_2558 == 1.45f) {
                KDSound_Play3d(GS_SpyroFuryConvexLP2, (MKVector3 *) &this->unk90.unk50, 0U, -1, 0.0f, 0U);
            }
        }
        temp_f2_2572 = this->unk150;
        if ((temp_f2_2572 > 1.6f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_2572 == 3.1f) != 0))) {
            this->unk154 = (0.6666f * (temp_f2_2572 - 1.6f) * 0.8f) + 0.0f;
        } else if ((temp_f2_2572 > 3.18f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_2572 == 3.6f) != 0))) {
            this->unk154 = 1.0f;
        } else if ((temp_f2_2572 > 3.6f) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((temp_f2_2572 == 5.8f) != 0))) {
            this->unk154 = (0.4545f * (temp_f2_2572 - 3.6f) * -1.0f) + 1.0f;
        } else if (temp_f2_2572 > 6.0f) {
            this->unk150 = -1.0f;
        }
        temp_f15_2623 = this->unk154;
        ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.7f * temp_f15_2623, temp_f15_2623, 0.033f, 0, 4.0f, 0U);
        this->unk150 += gUpdateTimeDelta;
    }
    temp_r0_2643 = this->unk90.unk60;
    if ((u32) temp_r0_2643 <= 6U) {
        switch (temp_r0_2643) {                     /* switch 1 */
            return;
        case 1:                                     /* switch 1 */
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                var_f15_2660 = this->unk90.unk64;
                if (var_f15_2660 < 1.0f) {

                } else {
                    var_f15_2660 = 1.0f;
                }
                if (var_f15_2660 > 0.0f) {

                } else {
                    var_f15_2660 = 0.0f;
                }
                arg_sp75C = 0;
                temp_f1_2680 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                arg_sp758 = 0x458;
                arg_sp760 = temp_f1_2680 + (0.017453292f * (30.0f * (1.0f - var_f15_2660)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp758, 30.0f, 0.017453292f);
            }
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp5F8), *((MKVector3 *) &arg_sp5E8));
            arg_sp608.operator*(400.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp618 = arg_sp118;
            arg_sp120 = this->unk90.unk58 + arg_sp610;
            arg_sp748 = arg_sp118;
            arg_sp620 = (f64) arg_sp120;
            arg_sp750 = (f64) arg_sp120;
            temp_f14_2737 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp5A8), *((MKVector3 *) &arg_sp598));
            Normalise(*((MKVector3 *) &arg_sp5B8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            arg_sp5C8 = arg_sp108;
            arg_sp110 = arg_sp5C0 * temp_f14_2737;
            arg_sp738 = arg_sp108;
            arg_sp5D0 = (f64) arg_sp110;
            arg_sp740 = (f64) arg_sp110;
            arg_sp230 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            arg_sp234 = 1.0f;
            arg_sp228 = 1.0f;
            arg_sp22C = 0.0f;
            arg_sp580 = (f64) arg_sp230;
            arg_sp578 = (f64) arg_sp228;
            arg_sp2C = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &arg_sp748), *((MKVector3 *) &arg_sp738), arg_sp2C, *((MKVector4 *) &arg_sp578), 0.0f);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk64 == 0.0f) {
                this->unk90.unk60 = 2;
                this->unk90.unk64 = 2.0f;
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    arg_sp7CC = 0;
                    MKVector(1.0f, 1.0f, 1.0f);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                    arg_sp7C8 = 0x417;
                    arg_sp7D0 = arg_spF8;
                    arg_sp100 = arg_sp560 * 150.0f;
                    arg_sp7E0 = 1;
                    arg_sp7D8 = (f64) arg_sp100;
                    arg_sp568 = arg_spF8;
                    arg_sp570 = (f64) arg_sp100;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp7C8, arg_spF8);
                }
                temp_r3_2842 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                arg_sp728 = M2C_FIELD(temp_r3_2842, f64 *, 0x30);
                arg_sp730 = M2C_FIELD(temp_r3_2842, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp548 = arg_sp218;
                arg_sp220 = this->unk90.unk48 - (f32) arg_sp730;
                arg_sp550 = (f64) arg_sp220;
                var_f4_2866 = ((f32) arg_sp550 * (f32) arg_sp550) + (((f32) arg_sp548 * (f32) arg_sp548) + (arg_sp54C * arg_sp54C));
                if (var_f4_2866 > 1e-12f) {
                    if (var_f4_2866 > 0.0f) {
                        temp_f1_2872 = __frsqrte(var_f4_2866);
                        temp_f1_2878 = 0.5 * temp_f1_2872 * -(((f64) var_f4_2866 * (temp_f1_2872 * temp_f1_2872)) - 3.0);
                        temp_f1_2882 = 0.5 * temp_f1_2878 * -(((f64) var_f4_2866 * (temp_f1_2878 * temp_f1_2878)) - 3.0);
                        var_f4_2866 = (f32) ((f64) var_f4_2866 * (0.5 * temp_f1_2882 * -(((f64) var_f4_2866 * (temp_f1_2882 * temp_f1_2882)) - 3.0)));
                    } else if (var_f4_2866 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2866 = __float_nan;
                    } else {
                        arg_sp1C = var_f4_2866;
                        temp_r3_2901 = M2C_BITWISE(s32, arg_sp1C) & 0x7F800000;
                        switch (temp_r3_2901) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                                var_r0_2911 = 1;
                            } else {
                                var_r0_2911 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                                var_r0_2911 = 5;
                            } else {
                                var_r0_2911 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_2911 = 4;
                            break;
                        }
                        if (var_r0_2911 == 1) {
                            var_f4_2866 = __float_nan;
                        }
                    }
                    var_f3_2933 = 1.0f / var_f4_2866;
                } else {
                    var_f3_2933 = 0.0f;
                }
                arg_sp20C = arg_sp54C * var_f3_2933;
                arg_sp208 = (f32) arg_sp548 * var_f3_2933;
                arg_sp210 = (f32) arg_sp550 * var_f3_2933;
                arg_sp718 = (f64) arg_sp208;
                arg_sp720 = (f64) arg_sp210;
                M2C_STRUCT_COPY((s32) &arg_sp86C + 4, (s32) (&identity - 4) + 4, 0x40);
                arg_sp200 = 0.0f;
                arg_sp1F8 = 0.0f;
                arg_sp1FC = 1.0f;
                arg_sp710 = (f64) arg_sp200;
                arg_sp708 = (f64) arg_sp1F8;
                KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp870, *((MKVector3 *) &arg_sp718), (MKVector3 *) &arg_sp708);
                arg_sp870.Scale3x3((Matrix *) &arg_sp870, 3.0f);
                arg_sp8A0 = this->unk90.unk40;
                arg_sp8A4 = this->unk90.unk44;
                arg_sp8A8 = this->unk90.unk48;
                arg_sp8AC = 1.0f;
                gb.unk1C0.StartWarp((Matrix *) &arg_sp870);
            }
            goto block_159;
        case 2:                                     /* switch 1 */
            var_f3_2993 = this->unk90.unk64;
            if (var_f3_2993 < 2.0f) {

            } else {
                var_f3_2993 = 2.0f;
            }
            if (var_f3_2993 > 0.0f) {

            } else {
                var_f3_2993 = 0.0f;
            }
            this->unk164 = 4.0f * -((var_f3_2993 * 0.5f) - 1.0f);
            EmitVortexParticles();
            this->unk14D = 1;
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp518), *((MKVector3 *) &arg_sp508));
            arg_sp528.operator*(400.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp538 = arg_spE8;
            arg_spF0 = this->unk90.unk58 + arg_sp530;
            arg_sp6F8 = arg_spE8;
            arg_sp540 = (f64) arg_spF0;
            arg_sp700 = (f64) arg_spF0;
            temp_f14_3057 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp4C8), *((MKVector3 *) &arg_sp4B8));
            Normalise(*((MKVector3 *) &arg_sp4D8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            arg_sp4E8 = arg_spD8;
            arg_spE0 = arg_sp4E0 * temp_f14_3057;
            arg_sp6E8 = arg_spD8;
            arg_sp4F0 = (f64) arg_spE0;
            arg_sp6F0 = (f64) arg_spE0;
            arg_sp1F0 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            arg_sp1F4 = 1.0f;
            arg_sp1E8 = 1.0f;
            arg_sp1EC = 0.0f;
            arg_sp4A0 = (f64) arg_sp1F0;
            arg_sp498 = (f64) arg_sp1E8;
            arg_sp28 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &arg_sp6F8), *((MKVector3 *) &arg_sp6E8), arg_sp28, *((MKVector4 *) &arg_sp498), 0.0f);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk64 == 0.0f) {
                this->unk90.unk64 = 0.1f;
                this->unk90.unk60 += 1;
            } else if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp7AC = 0;
                temp_f15_3139 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f16_3144 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f16_3144, temp_f15_3139);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                arg_sp7A8 = 0x417;
                arg_sp7B0 = arg_spC8;
                arg_spD0 = arg_sp480 * 10.0f;
                arg_sp7C0 = 1;
                arg_sp7B8 = (f64) arg_spD0;
                arg_sp488 = arg_spC8;
                arg_sp490 = (f64) arg_spD0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp7A8, arg_spC8);
            }
            goto block_159;
        case 3:                                     /* switch 1 */
            EmitVortexParticles();
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk64 == 0.0f) {
                this->unk90.unk64 = 0.1f;
                this->unk90.unk60 += 1;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp78C = 0;
                temp_f15_3203 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f16_3208 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f16_3208, temp_f15_3203);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                arg_sp788 = 0x417;
                arg_sp790 = arg_spB8;
                arg_spC0 = arg_sp460 * 10.0f;
                arg_sp7A0 = 1;
                arg_sp798 = (f64) arg_spC0;
                arg_sp468 = arg_spB8;
                arg_sp470 = (f64) arg_spC0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp788, arg_spB8);
            }
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp428), *((MKVector3 *) &arg_sp418));
            arg_sp438.operator*(400.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp448 = arg_spA8;
            arg_spB0 = this->unk90.unk58 + arg_sp440;
            arg_sp6D8 = arg_spA8;
            arg_sp450 = (f64) arg_spB0;
            arg_sp6E0 = (f64) arg_spB0;
            temp_f14_3281 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp3D8), *((MKVector3 *) &arg_sp3C8));
            Normalise(*((MKVector3 *) &arg_sp3E8));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            arg_sp3F8 = arg_sp98;
            arg_spA0 = arg_sp3F0 * temp_f14_3281;
            arg_sp6C8 = arg_sp98;
            arg_sp400 = (f64) arg_spA0;
            arg_sp6D0 = (f64) arg_spA0;
            arg_sp1E0 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            arg_sp1E4 = 1.0f;
            arg_sp1D8 = 1.0f;
            arg_sp1DC = 0.0f;
            arg_sp3B0 = (f64) arg_sp1E0;
            arg_sp3A8 = (f64) arg_sp1D8;
            arg_sp24 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &arg_sp6D8), *((MKVector3 *) &arg_sp6C8), arg_sp24, *((MKVector4 *) &arg_sp3A8), 0.0f);
            goto block_159;
        case 4:                                     /* switch 1 */
            EmitVortexParticles();
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp378), *((MKVector3 *) &arg_sp368));
            arg_sp388.operator*(400.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp398 = arg_sp88;
            arg_sp90 = this->unk90.unk58 + arg_sp390;
            arg_sp6B8 = arg_sp88;
            arg_sp3A0 = (f64) arg_sp90;
            arg_sp6C0 = (f64) arg_sp90;
            temp_f14_3383 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(*((MKVector3 *) &arg_sp328), *((MKVector3 *) &arg_sp318));
            Normalise(*((MKVector3 *) &arg_sp338));
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            arg_sp348 = arg_sp78;
            arg_sp80 = arg_sp340 * temp_f14_3383;
            arg_sp6A8 = arg_sp78;
            arg_sp350 = (f64) arg_sp80;
            arg_sp6B0 = (f64) arg_sp80;
            arg_sp1D0 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            arg_sp1D4 = 1.0f;
            arg_sp1C8 = 1.0f;
            arg_sp1CC = 0.0f;
            arg_sp300 = (f64) arg_sp1D0;
            arg_sp2F8 = (f64) arg_sp1C8;
            arg_sp20 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &arg_sp6B8), *((MKVector3 *) &arg_sp6A8), arg_sp20, *((MKVector4 *) &arg_sp2F8), 0.0f);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp76C = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                arg_sp768 = 0x417;
                arg_sp770 = arg_sp68;
                arg_sp70 = arg_sp2E0 * 500.0f;
                arg_sp780 = 1;
                arg_sp778 = (f64) arg_sp70;
                arg_sp2E8 = arg_sp68;
                arg_sp2F0 = (f64) arg_sp70;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp768, arg_sp68);
            }
            var_f0_3480 = 0.0f;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk64 == 0.0f) {
                this->unk90.unk64 = 5.0f;
                arg_sp1C0 = 0.0f;
                arg_sp1B8 = 0.0f;
                arg_sp1BC = 500.0f;
                this->unk90.unk60 += 1;
                arg_sp2C8 = (f64) arg_sp1B8;
                arg_sp2D0 = (f64) arg_sp1C0;
                M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                arg_sp698 = arg_sp1A8;
                arg_sp1B0 = this->unk90.unk38 + (f32) arg_sp2D0;
                arg_sp6A0 = (f64) arg_sp1B0;
                temp_r3_3511 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                arg_sp2A8 = M2C_FIELD(temp_r3_3511, f64 *, 0x30);
                arg_sp2B0 = M2C_FIELD(temp_r3_3511, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
                arg_sp2B8 = arg_sp198;
                arg_sp1A0 = (f32) arg_sp2B0 - (f32) arg_sp6A0;
                arg_sp2C0 = (f64) arg_sp1A0;
                var_f4_3535 = ((f32) arg_sp2C0 * (f32) arg_sp2C0) + (((f32) arg_sp2B8 * (f32) arg_sp2B8) + (arg_sp2BC * arg_sp2BC));
                if (var_f4_3535 > 1e-12f) {
                    if (var_f4_3535 > 0.0f) {
                        temp_f1_3540 = __frsqrte(var_f4_3535);
                        temp_f1_3546 = 0.5 * temp_f1_3540 * -(((f64) var_f4_3535 * (temp_f1_3540 * temp_f1_3540)) - 3.0);
                        temp_f1_3550 = 0.5 * temp_f1_3546 * -(((f64) var_f4_3535 * (temp_f1_3546 * temp_f1_3546)) - 3.0);
                        var_f4_3535 = (f32) ((f64) var_f4_3535 * (0.5 * temp_f1_3550 * -(((f64) var_f4_3535 * (temp_f1_3550 * temp_f1_3550)) - 3.0)));
                    } else if (var_f4_3535 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3535 = __float_nan;
                    } else {
                        arg_sp18 = var_f4_3535;
                        temp_r3_3569 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                        switch (temp_r3_3569) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_3579 = 1;
                            } else {
                                var_r0_3579 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_3579 = 5;
                            } else {
                                var_r0_3579 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_3579 = 4;
                            break;
                        }
                        if (var_r0_3579 == 1) {
                            var_f4_3535 = __float_nan;
                        }
                    }
                    var_f0_3480 = 1.0f / var_f4_3535;
                }
                arg_sp18C = arg_sp2BC * var_f0_3480;
                arg_sp188 = (f32) arg_sp2B8 * var_f0_3480;
                arg_sp190 = (f32) arg_sp2C0 * var_f0_3480;
                arg_sp688 = (f64) arg_sp188;
                arg_sp690 = (f64) arg_sp190;
                DisableChaserLights();
                M2C_STRUCT_COPY((s32) &arg_sp82C + 4, (s32) (M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8) - 4) + 4, 0x40);
                var_r28_3629 = 0;
                arg_sp86C = 1.0f;
                arg_sp860 = 0.0f;
                arg_sp864 = 0.0f;
                arg_sp868 = 0.0f;
                arg_sp8B8 = 3.60985932e-315;
                do {
                    temp_f14_3659 = 6.2831855f * ((f32) var_r28_3629 / 10.0f);
                    temp_f15_3662 = -_table_sinf(1.5707964f + temp_f14_3659);
                    arg_sp58 = _table_sinf(temp_f14_3659);
                    arg_sp5C = temp_f15_3662;
                    arg_sp60 = 0.0f;
                    arg_sp678 = (f64) arg_sp58;
                    arg_sp680 = (f64) arg_sp60;
                    arg_sp298 = (f64) arg_sp58;
                    arg_sp2A0 = (f64) arg_sp60;
                    arg_sp48 = 0.0f + (((f32) arg_sp680 * arg_sp850) + (((f32) arg_sp678 * arg_sp830) + (arg_sp67C * arg_sp840)));
                    arg_sp4C = 0.0f + (((f32) arg_sp680 * arg_sp854) + (((f32) arg_sp678 * arg_sp834) + (arg_sp67C * arg_sp844)));
                    arg_sp50 = 0.0f + (((f32) arg_sp680 * arg_sp858) + (((f32) arg_sp678 * arg_sp838) + (arg_sp67C * arg_sp848)));
                    arg_sp678 = (f64) arg_sp48;
                    arg_sp288 = (f64) arg_sp48;
                    arg_sp290 = (f64) arg_sp50;
                    arg_sp680 = (f64) arg_sp50;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
                    arg_sp258 = arg_sp178;
                    arg_sp180 = (f32) arg_sp680 * 0.9f;
                    arg_sp260 = (f64) arg_sp180;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp268 = arg_sp168;
                    arg_sp170 = (f32) arg_sp690 + (f32) arg_sp260;
                    arg_sp270 = (f64) arg_sp170;
                    var_f4_3727 = ((f32) arg_sp270 * (f32) arg_sp270) + (((f32) arg_sp268 * (f32) arg_sp268) + (arg_sp26C * arg_sp26C));
                    if (var_f4_3727 > (f32) arg_sp8B8) {
                        if (var_f4_3727 > 0.0f) {
                            temp_f1_3733 = __frsqrte(var_f4_3727);
                            temp_f1_3739 = 0.5 * temp_f1_3733 * -(((f64) var_f4_3727 * (temp_f1_3733 * temp_f1_3733)) - 3.0);
                            temp_f1_3743 = 0.5 * temp_f1_3739 * -(((f64) var_f4_3727 * (temp_f1_3739 * temp_f1_3739)) - 3.0);
                            var_f4_3727 = (f32) ((f64) var_f4_3727 * (0.5 * temp_f1_3743 * -(((f64) var_f4_3727 * (temp_f1_3743 * temp_f1_3743)) - 3.0)));
                        } else if (var_f4_3727 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_3727 = __float_nan;
                        } else {
                            arg_sp14 = var_f4_3727;
                            temp_r3_3762 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                            switch (temp_r3_3762) { /* switch 4; irregular */
                            case 0x7F800000:        /* switch 4 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_3772 = 1;
                                } else {
                                    var_r0_3772 = 2;
                                }
                                break;
                            case 0x0:               /* switch 4 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_3772 = 5;
                                } else {
                                    var_r0_3772 = 3;
                                }
                                break;
                            default:                /* switch 4 */
                                var_r0_3772 = 4;
                                break;
                            }
                            if (var_r0_3772 == 1) {
                                var_f4_3727 = __float_nan;
                            }
                        }
                        var_f3_3794 = 1.0f / var_f4_3727;
                    } else {
                        var_f3_3794 = 0.0f;
                    }
                    arg_sp158 = (f32) arg_sp268 * var_f3_3794;
                    arg_sp15C = arg_sp26C * var_f3_3794;
                    arg_sp160 = (f32) arg_sp270 * var_f3_3794;
                    arg_sp278 = (f64) arg_sp158;
                    arg_sp280 = (f64) arg_sp160;
                    LaunchDragonChaser(*((MKVector3 *) &arg_sp698), *((MKVector3 *) &arg_sp278));
                    var_r28_3629 += 1;
                } while (var_r28_3629 < 0xA);
                temp_r3_3821 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                arg_sp668 = M2C_FIELD(temp_r3_3821, f64 *, 0x30);
                arg_sp670 = M2C_FIELD(temp_r3_3821, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp248 = arg_sp148;
                arg_sp150 = this->unk90.unk48 - (f32) arg_sp670;
                arg_sp250 = (f64) arg_sp150;
                var_f4_3845 = ((f32) arg_sp250 * (f32) arg_sp250) + (((f32) arg_sp248 * (f32) arg_sp248) + (arg_sp24C * arg_sp24C));
                if (var_f4_3845 > 1e-12f) {
                    if (var_f4_3845 > 0.0f) {
                        temp_f1_3851 = __frsqrte(var_f4_3845);
                        temp_f1_3857 = 0.5 * temp_f1_3851 * -(((f64) var_f4_3845 * (temp_f1_3851 * temp_f1_3851)) - 3.0);
                        temp_f1_3861 = 0.5 * temp_f1_3857 * -(((f64) var_f4_3845 * (temp_f1_3857 * temp_f1_3857)) - 3.0);
                        var_f4_3845 = (f32) ((f64) var_f4_3845 * (0.5 * temp_f1_3861 * -(((f64) var_f4_3845 * (temp_f1_3861 * temp_f1_3861)) - 3.0)));
                    } else if (var_f4_3845 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3845 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_3845;
                        temp_r3_3880 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_3880) {     /* switch 5; irregular */
                        case 0x7F800000:            /* switch 5 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_3890 = 1;
                            } else {
                                var_r0_3890 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 5 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_3890 = 5;
                            } else {
                                var_r0_3890 = 3;
                            }
                            break;
                        default:                    /* switch 5 */
                            var_r0_3890 = 4;
                            break;
                        }
                        if (var_r0_3890 == 1) {
                            var_f4_3845 = __float_nan;
                        }
                    }
                    var_f3_3912 = 1.0f / var_f4_3845;
                } else {
                    var_f3_3912 = 0.0f;
                }
                arg_sp13C = arg_sp24C * var_f3_3912;
                arg_sp138 = (f32) arg_sp248 * var_f3_3912;
                arg_sp140 = (f32) arg_sp250 * var_f3_3912;
                arg_sp658 = (f64) arg_sp138;
                arg_sp660 = (f64) arg_sp140;
                M2C_STRUCT_COPY((s32) &arg_sp7EC + 4, (s32) (&identity - 4) + 4, 0x40);
                arg_sp130 = 0.0f;
                arg_sp128 = 0.0f;
                arg_sp12C = 1.0f;
                arg_sp650 = (f64) arg_sp130;
                arg_sp648 = (f64) arg_sp128;
                KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp7F0, *((MKVector3 *) &arg_sp658), (MKVector3 *) &arg_sp648);
                arg_sp7F0.Scale3x3((Matrix *) &arg_sp7F0, 3.0f);
                arg_sp820 = this->unk90.unk40;
                arg_sp824 = this->unk90.unk44;
                arg_sp828 = this->unk90.unk48;
                arg_sp82C = 1.0f;
                gb.unk1C0.StartWarp((Matrix *) &arg_sp7F0);
            }
            goto block_159;
        case 5:                                     /* switch 1 */
            var_f2_3976 = 0.5f * (0.5f * gUpdateTimeDelta);
            if (var_f2_3976 < 1.0f) {

            } else {
                var_f2_3976 = 1.0f;
            }
            temp_f1_3983 = this->unk164;
            temp_f1_3987 = (var_f2_3976 * (0.0f - temp_f1_3983)) + temp_f1_3983;
            this->unk164 = (var_f2_3976 * (0.0f - temp_f1_3987)) + temp_f1_3987;
            EmitVortexParticles();
            this->unk14C = 0;
            this->unk14D = 0;
            var_f15_3998 = this->unk90.unk64 / 5.0f;
            if (var_f15_3998 < 1.0f) {

            } else {
                var_f15_3998 = 1.0f;
            }
            if (var_f15_3998 > 0.0f) {

            } else {
                var_f15_3998 = 0.0f;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_f15_3998 == 0.5f) {
                    arg_sp63C = 0;
                    temp_f1_4026 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                    arg_sp638 = 0x458;
                    arg_sp640 = temp_f1_4026 + (0.017453292f * (30.0f * (var_f15_3998 / 0.5f)));
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp638, 30.0f, 0.017453292f);
                }
            }
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk64 == 0.0f) {
                this->unk90.unk60 = 6;
                this->unk90.unk64 = 1.4f;
                KDSound_Play3d(GS_SpyroFuryConvexExtra2, (MKVector3 *) &this->unk90.unk50, 0U, -1, 0.0f, 0U);
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    arg_sp34 = 0;
                    arg_sp30 = 0x459;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp30);
                }
                gb.unk2CC.Disable(this->unk168);
            }
            goto block_159;
        case 6:                                     /* switch 1 */
            var_f0_4079 = this->unk90.unk64;
            if (var_f0_4079 < 1.4f) {

            } else {
                var_f0_4079 = 1.4f;
            }
            if (var_f0_4079 > 0.0f) {

            } else {
                var_f0_4079 = 0.0f;
            }
            this->unk90.unk64 = var_f0_4079;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk90.unk64 == 0.0f) {
                this->unk90.unk60 = 0;
            }
            goto block_159;
        }
    } else {
block_159:
        gb.unk74->ApplyWind(&this->unk170);
        if ((s32) this->unk90.unk60 <= 4) {
            temp_r3_4111 = this->unk90.unk68;
            if (M2C_BITWISE(u32, temp_r3_4111) != 0U) {
                arg_sp40 = 0.0f;
                arg_sp38 = 0.0f;
                arg_sp3C = 250.0f * gUpdateTimeDelta;
                arg_sp628 = M2C_FIELD(temp_r3_4111, f64 *, 0x10);
                arg_sp238 = (f64) arg_sp38;
                arg_sp630 = M2C_FIELD(temp_r3_4111, f64 *, 0x18);
                arg_sp240 = (f64) arg_sp40;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(temp_r3_4111, f64 *, 0x10) = arg_sp628;
                arg_sp630 = (f32) arg_sp630 + (f32) arg_sp240;
                M2C_FIELD(temp_r3_4111, f64 *, 0x18) = arg_sp630;
                temp_r3_4141 = M2C_FIELD(temp_r3_4111, void **, 0x3C);
                if (temp_r3_4141 != NULL) {
                    M2C_FIELD(temp_r3_4141, f64 *, 0x10) = arg_sp628;
                    M2C_FIELD(temp_r3_4141, f64 *, 0x18) = arg_sp630;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void FuryFXConvexity::Resolve() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
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
    f32 temp_r3_4241;
    f32 temp_r3_4261;
    f32 temp_r4_4235;
    void *temp_r3_4244;
    void *temp_r3_4269;

    FuryFX::Resolve();
    sp30 = 0.0f;
    sp40 = 0.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp58 = (f64) sp18;
    sp60 = (f64) sp20;
    sp68 = (f64) sp28;
    sp70 = (f64) sp30;
    sp78 = (f64) sp38;
    sp80 = (f64) sp40;
    this->unk90.unk68 = M2C_BITWISE(f32, gb.unk80->AllocManagedLight(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), *((MKVector4 *) &sp58), 300.0f, lit_780, lit_781));
    temp_r4_4235 = this->unk90.unk68;
    if (M2C_BITWISE(u32, temp_r4_4235) != 0U) {
        gb.unk80->EnableLight(M2C_BITWISE(ManagedLight *, temp_r4_4235), 0U);
        temp_r3_4241 = this->unk90.unk68;
        M2C_FIELD(temp_r3_4241, f32 *, 0x38) = 2000.0f;
        temp_r3_4244 = M2C_FIELD(temp_r3_4241, void **, 0x3C);
        if (temp_r3_4244 != NULL) {
            M2C_FIELD(temp_r3_4244, f32 *, 0x20) = 2000.0f;
            M2C_FIELD(temp_r3_4244, f32 *, 0x24) = 4000000.0f;
            M2C_FIELD(temp_r3_4244, f32 *, 0x28) = 0.0005f;
            M2C_FIELD(temp_r3_4244, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_4244, f32 *, 0x24));
        }
        sp8 = 1.0f;
        temp_r3_4261 = this->unk90.unk68;
        spC = 0.0f;
        sp10 = 0.75f;
        sp14 = 1.0f;
        M2C_FIELD(temp_r3_4261, f64 *, 0x20) = (f64) sp8;
        M2C_FIELD(temp_r3_4261, f64 *, 0x28) = (f64) sp10;
        temp_r3_4269 = M2C_FIELD(temp_r3_4261, void **, 0x3C);
        sp48 = (f64) sp8;
        sp50 = (f64) sp10;
        if (temp_r3_4269 != NULL) {
            M2C_FIELD(temp_r3_4269, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r3_4269, f64 *, 8) = (f64) sp10;
        }
    }
    Disable();
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void FuryFXConvexity::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSoundFader **temp_r3_4339;
    KDSoundFader **temp_r4_4345;
    KDSoundFader **var_r3_4324;
    KDSoundFader **var_r5_4333;
    MKHeap *temp_r3_4315;
    MKHeap *temp_r3_4317;
    Matrix *temp_r3_4401;
    s32 var_ctr_4337;

    FuryFX::Init();
    SetDefaults();
    this->unk90.unk40 = 0.0f;
    this->unk90.unk44 = 0.0f;
    this->unk90.unk48 = 0.0f;
    this->unk15C = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("ConvexityPSAdd"));
    temp_r3_4315 = checked_cast<KDEnvParticleSystem *, MKProp>(gMK->CreateProp("ConvexityPSSub"));
    this->unk160 = temp_r3_4315;
    temp_r3_4317 = temp_r3_4315->Current();
    if (temp_r3_4317 != NULL) {
        var_r3_4324 = ((MKHeap *) (temp_r3_4317->Current()))->Alloc(0x670, NULL, 0);
    } else {
        var_r3_4324 = malloc(0x670);
    }
    this->unk158 = var_r3_4324;
    var_r5_4333 = this->unk158;
    this->unk158 = var_r5_4333 + 0x640;
    M2C_FIELD(var_r5_4333, s32 *, 0x640) = 0;
    var_ctr_4337 = 0xA;
    do {
        temp_r3_4339 = this->unk158;
        this->unk158 = temp_r3_4339 + 4;
        M2C_FIELD(temp_r3_4339, KDSoundFader ***, 4) = var_r5_4333;
        var_r5_4333 += 0xA0;
        var_ctr_4337 -= 1;
    } while (var_ctr_4337 != 0);
    temp_r4_4345 = this->unk158;
    this->unk158 = temp_r4_4345 + 4;
    M2C_FIELD(temp_r4_4345, KDSoundFader ***, 4) = NULL;
    this->unk90.unk68 = 0.0f;
    this->unk90.unk6C.Init(1.0f, 7.0f);
    this->unk124.Init(0.75f, 6.0f);
    this->unk14C = 0;
    this->unk14D = 0;
    sp10 = 0.0f;
    sp20 = 0.0f;
    this->unk168 = -1;
    sp8 = 0.0f;
    spC = 0.1f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unk170.Init(1, 1.0f, *((MKVector3 *) &sp38), *((MKVector3 *) &sp28));
    this->unk170.unk18 = 800.0f;
    this->unk170.unk1C = 800.0f;
    M2C_STRUCT_COPY((s32) (this + 0x19C) + 4, (s32) (&identity - 4) + 4, 0x40);
    temp_r3_4401 = &this->unk1A0;
    temp_r3_4401->RotateYaw(temp_r3_4401, 0.3926991f);
    this->unk170.unk10 = 450.0f;
    this->unk1A0.unk40 = M2C_BITWISE(f32, MKModel_Create("FX0035_Head", NULL, 2, NULL));
    this->unk150 = -1.0f;
}
#endif

void FuryFXConvexity_cpp::__sinit() {
    f32 temp_f0_4459;
    f64 temp_f1_4440;
    f64 temp_f1_4448;
    f64 temp_f3_4428;
    f64 temp_f4_4437;
    f64 temp_f4_4445;
    f64 temp_f8_4430;

    temp_f3_4428 = __frsqrte(2014000.0);
    temp_f8_4430 = __frsqrte(380000.0);
    temp_f4_4437 = 0.5 * temp_f3_4428 * -((2014000.0 * (temp_f3_4428 * temp_f3_4428)) - 3.0);
    temp_f1_4440 = 0.5 * temp_f8_4430 * -((380000.0 * (temp_f8_4430 * temp_f8_4430)) - 3.0);
    temp_f4_4445 = 0.5 * temp_f4_4437 * -((2014000.0 * (temp_f4_4437 * temp_f4_4437)) - 3.0);
    temp_f1_4448 = 0.5 * temp_f1_4440 * -((380000.0 * (temp_f1_4440 * temp_f1_4440)) - 3.0);
    temp_f0_4459 = (f32) (380000.0 * (0.5 * temp_f1_4448 * -((380000.0 * (temp_f1_4448 * temp_f1_4448)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_4445 * -((2014000.0 * (temp_f4_4445 * temp_f4_4445)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_4459;
}

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
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
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

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void FuryFXConvexity::EmitVortexParticles() {
    f64 spF0;
    M2C_UNK spCC;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKHeap *temp_r3_125;
    MKHeap *temp_r3_171;
    f32 temp_f1_131;
    f64 temp_f0_111;
    f64 temp_f0_123;
    s32 temp_r4_79;
    void *temp_r30_140;
    void *temp_r30_178;
    void *temp_r3_137;
    void *temp_r3_175;

    temp_r4_79 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), s32 *, 8) - 4;
    M2C_STRUCT_COPY((s32) &spCC + 4, temp_r4_79 + 4, 0x40);
    sp40 = spF0 * 5.56078426e-315;
    sp60 = 0.0f;
    sp64 = 500.0f;
    sp48 = spF8 * 150.0f;
    sp68 = 0.0f;
    spA0 = (f64) sp60;
    sp90 = sp40;
    sp98 = (f64) sp48;
    spA8 = (f64) sp68;
    temp_f0_111 = M2C_FIELD(this, f64 *, 0xC0) + spA0;
    sp50 = temp_f0_111;
    spB0 = temp_f0_111;
    sp58 = this->unk90.unk38 + (f32) spA8;
    spB8 = (f64) sp58;
    temp_f0_123 = spB0 + sp90;
    sp30 = temp_f0_123;
    temp_r3_125 = this->unk160;
    temp_f1_131 = (f32) spB8 + (f32) sp98;
    spC0 = temp_f0_123;
    sp38 = temp_f1_131;
    spC8 = (f64) sp38;
    temp_r3_137 = M2C_FIELD(temp_r3_125->unk44, void *(**)(MKHeap *, s32, void *, f32, f32, f64), 0x3C)(temp_r3_125, temp_r4_79 + 0x40, &spCC + 0x40, temp_f1_131, (f32) spB8, sp40);
    if (temp_r3_137 != NULL) {
        temp_r30_140 = M2C_FIELD(temp_r3_137, void **, 0x2C);
        M2C_FIELD(temp_r3_137, f64 *, 0) = spC0;
        M2C_FIELD(temp_r3_137, f64 *, 8) = spC8;
        M2C_FIELD(temp_r3_137, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_137, f32 *, 0x28) = (f32) this->unk164;
        M2C_FIELD(temp_r3_137, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        sp20 = 0.0f;
        sp24 = 0.0f;
        sp28 = 0.0f;
        M2C_FIELD(temp_r30_140, f64 *, 0) = (f64) sp20;
        M2C_FIELD(temp_r30_140, f64 *, 8) = (f64) sp28;
        sp80 = (f64) sp20;
        M2C_FIELD(temp_r30_140, f32 *, 0x18) = (f32) this->unk164;
        M2C_FIELD(temp_r30_140, f32 *, 0x10) = -3.1415927f;
        sp88 = (f64) sp28;
        M2C_FIELD(temp_r30_140, f32 *, 0x14) = M2C_BITWISE(f32, this->unk160->unkF4);
    }
    temp_r3_171 = this->unk15C;
    temp_r3_175 = M2C_FIELD(temp_r3_171->unk44, void *(**)(MKHeap *), 0x3C)(temp_r3_171);
    if (temp_r3_175 != NULL) {
        temp_r30_178 = M2C_FIELD(temp_r3_175, void **, 0x2C);
        M2C_FIELD(temp_r3_175, f64 *, 0) = spC0;
        M2C_FIELD(temp_r3_175, f64 *, 8) = spC8;
        M2C_FIELD(temp_r3_175, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3_175, f32 *, 0x28) = (f32) (1.5f * this->unk164);
        M2C_FIELD(temp_r3_175, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        sp10 = 0.0f;
        sp14 = 0.0f;
        sp18 = 0.0f;
        M2C_FIELD(temp_r30_178, f64 *, 0) = (f64) sp10;
        M2C_FIELD(temp_r30_178, f64 *, 8) = (f64) sp18;
        sp70 = (f64) sp10;
        sp78 = (f64) sp18;
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

void FuryFXConvexity::DrawDragonChasers() {
    KDSoundFader **var_r31_271;
    KDSoundFader *temp_r4_284;

    var_r31_271 = this->unk158;
loop_2:
    if (var_r31_271 != NULL) {
        temp_r4_284 = *var_r31_271;
        if (temp_r4_284 != NULL) {
            MKModel_SetWorldMatrix(this->unk1E0, *((Matrix *) &temp_r4_284->unk30));
            MKModel_Draw(this->unk1E0, NULL);
            var_r31_271 += 4;
            goto loop_2;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKProp' to
void FuryFXConvexity::UpdateDragonChasers() {
    BreathHitMessage sp5B0;
    Matrix sp570;
    M2C_UNK sp56C;
    f32 sp560;                                      /* compiler-managed */
    f32 sp55C;
    f32 sp558;                                      /* compiler-managed */
    s32 sp554;
    s32 sp550;
    s8 sp548;
    f64 sp540;
    f64 sp538;
    s32 sp534;
    s32 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;                                      /* compiler-managed */
    f64 sp510;                                      /* compiler-managed */
    f64 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;                                      /* compiler-managed */
    f64 sp4D0;                                      /* compiler-managed */
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    MKProp sp420;
    f64 sp418;
    f64 sp410;
    MKVector3 sp400;
    MKVector3 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    MKVector3 sp3B0;
    MKVector3 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    MKVector3 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    MKVector3 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    MKVector3 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    MKVector3 sp260;
    MKVector3 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f32 sp208;
    f64 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f64 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    KDSoundFader **temp_r3_1353;
    KDSoundFader **var_r26_328;
    KDSoundFader *temp_r29_1508;
    KDSoundFader *temp_r4_1356;
    MKHeap **temp_r3_366;
    MKHeap *temp_r3_1002;
    MKHeap *temp_r3_1042;
    MKHeap *temp_r3_1385;
    MKHeap *temp_r3_1441;
    ManagedLight *temp_r3_1491;
    ManagedLight *temp_r4_1342;
    f32 *temp_r3_640;
    f32 *temp_r3_938;
    f32 temp_f1_1386;
    f32 temp_f1_334;
    f32 temp_f26_1380;
    f32 temp_f3_393;
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
    f64 temp_f0_1382;
    f64 temp_f0_596;
    f64 temp_f0_606;
    f64 temp_f0_815;
    f64 temp_f0_825;
    f64 temp_f0_878;
    f64 temp_f0_895;
    f64 temp_f0_907;
    f64 temp_f1_1111;
    f64 temp_f1_1117;
    f64 temp_f1_1121;
    f64 temp_f1_478;
    f64 temp_f1_484;
    f64 temp_f1_488;
    f64 temp_f1_590;
    f64 temp_f1_701;
    f64 temp_f1_707;
    f64 temp_f1_711;
    f64 temp_f1_809;
    f64 temp_f1_886;
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
            sp8 = 1;
            temp_r29_1508->Update(GS_SpyroBreathConvexLP, 1U, M2C_FIELD(temp_r29_1508, u8 *, 0x9C), NULL, (MKVector3 *) temp_r28_342, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            M2C_FIELD(temp_r29_1508, f32 *, 0x88) = (f32) (M2C_FIELD(temp_r29_1508, f32 *, 0x88) - gUpdateTimeDelta);
            if ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL) {
                sp420.GetPos();
                temp_r3_366 = MKModel_GetBoundingVolume(M2C_FIELD(M2C_FIELD(temp_r29_1508, void **, 0x80), MKModel **, 4), (SubObjectType) 0, -1);
                sp30 = (0.5f * M2C_FIELD(temp_r3_366, f32 *, 0x10)) + M2C_FIELD(temp_r3_366, f32 *, 0);
                sp34 = (0.5f * M2C_FIELD(temp_r3_366, f32 *, 0x14)) + M2C_FIELD(temp_r3_366, f32 *, 4);
                sp38 = (0.5f * M2C_FIELD(temp_r3_366, f32 *, 0x18)) + M2C_FIELD(temp_r3_366, f32 *, 8);
                sp420.unk10 = (f64) sp30;
                sp420.unk18 = (f64) sp38;
                sp140 = M2C_BITWISE(f64, sp420.unk10) + M2C_BITWISE(f64, sp420);
                temp_f3_393 = M2C_BITWISE(f32, sp420.unk18);
                sp558 = 0.0f;
                sp55C = 0.0f;
                sp148 = temp_f3_393 + M2C_BITWISE(f32, sp420.unk8);
                sp560 = 0.0f;
                sp554 = 0;
                sp550 = 0xA6;
                sp558 = sp140;
                sp560 = (f64) sp148;
                temp_r3_405 = M2C_FIELD(temp_r29_1508, void **, 0x80);
                sp420.unk20 = sp140;
                sp420.unk28 = (f64) sp148;
                M2C_FIELD(M2C_FIELD(temp_r3_405, void **, 0x44), M2C_UNK (**)(void *, s32 *, f64, f64, f32, f32), 0x2C)(temp_r3_405, &sp550, (f64) sp148, sp140, temp_f3_393, 0.5f);
                sp520 = sp558;
                sp528 = sp560;
            }
            temp_r0_417 = M2C_FIELD(temp_r29_1508, s32 *, 0x98);
            switch (temp_r0_417) {                  /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                M2C_FIELD(temp_r29_1508, u8 *, 0x9C) = 1U;
                var_r27_331 += 1;
                if (M2C_FIELD(temp_r29_1508, f32 *, 0x88) <= 0.0f) {
                    M2C_FIELD(temp_r29_1508, s32 *, 0x98) = 2;
                    M2C_FIELD(temp_r29_1508, f32 *, 0x88) = 2.5f;
                }
                var_f22_444 = 3.4028235e38f;
                sp510 = M2C_FIELD(temp_r29_1508, f64 *, 0x70);
                sp518 = M2C_FIELD(temp_r29_1508, f64 *, 0x78);
                if ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL) {
                    sp130 = sp520 - temp_r29_1508->unk60;
                    sp510 = sp130;
                    sp138 = (f32) sp528 - temp_r29_1508->unk68;
                    sp518 = (f64) sp138;
                    sp410 = sp130;
                    sp418 = (f64) sp138;
                    var_f4_472 = ((f32) sp518 * (f32) sp518) + (((f32) sp510 * (f32) sp510) + (unksp514 * unksp514));
                    if (var_f4_472 > 0.000001f) {
                        if (var_f4_472 > 0.0f) {
                            temp_f1_478 = __frsqrte(var_f4_472);
                            temp_f1_484 = 0.5 * temp_f1_478 * -(((f64) var_f4_472 * (temp_f1_478 * temp_f1_478)) - 3.0);
                            temp_f1_488 = 0.5 * temp_f1_484 * -(((f64) var_f4_472 * (temp_f1_484 * temp_f1_484)) - 3.0);
                            var_f4_472 = (f32) ((f64) var_f4_472 * (0.5 * temp_f1_488 * -(((f64) var_f4_472 * (temp_f1_488 * temp_f1_488)) - 3.0)));
                        } else if (var_f4_472 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_472 = __float_nan;
                        } else {
                            sp18 = var_f4_472;
                            temp_r3_507 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                            switch (temp_r3_507) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                    var_r0_517 = 1;
                                } else {
                                    var_r0_517 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
                    sp510 = (f32) sp510 * var_f3_539;
                    unksp514 *= var_f3_539;
                    sp518 = (f32) sp518 * var_f3_539;
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
                KDMath_Slerp(sp3F0, *((MKVector3 *) &temp_r29_1508->unk70), 0.3f * (1.0f - (var_f2_556 / 3.5f)));
                Normalise(sp400);
                M2C_FIELD(temp_r29_1508, f64 *, 0x70) = M2C_BITWISE(f64, sp400);
                M2C_FIELD(temp_r29_1508, f64 *, 0x78) = (f64) sp400.unk8;
                temp_f1_590 = temp_r29_1508->unk60;
                sp500 = temp_f1_590;
                sp508 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                temp_f0_596 = M2C_FIELD(temp_r29_1508, f64 *, 0x70) * 5.72858887e-315;
                sp200 = temp_f0_596;
                sp3D0 = temp_f0_596;
                sp208 = (f32) M2C_FIELD(temp_r29_1508, f64 *, 0x78) * 2500.0f;
                sp3D8 = (f64) sp208;
                temp_f0_606 = temp_f0_596 * (f64) gUpdateTimeDelta;
                sp1F0 = temp_f0_606;
                sp3E0 = temp_f0_606;
                sp1F8 = (f32) sp3D8 * gUpdateTimeDelta;
                sp3E8 = (f64) sp1F8;
                sp1E0 = temp_f1_590 + temp_f0_606;
                sp1D8 = 0.0f;
                sp1D0 = 0.0f;
                sp1D4 = 1.0f;
                sp1E8 = (f32) sp508 + (f32) sp3E8;
                sp4F0 = sp1E0;
                sp4F8 = (f64) sp1E8;
                sp4E0 = (f64) sp1D0;
                sp4E8 = (f64) sp1D8;
                KDMath_BuildMatrixFromFwd((Matrix *) &temp_r29_1508->unk30, *((MKVector3 *) &temp_r29_1508->unk70), (MKVector3 *) &sp4E0);
                temp_r3_640 = &temp_r29_1508->unk30;
                temp_r3_640->Scale3x3((Matrix *) temp_r3_640, 1.0f);
                M2C_FIELD(temp_r29_1508, f64 *, 0x60) = (f32) sp4F0;
                M2C_FIELD(temp_r29_1508, f32 *, 0x64) = unksp4F4;
                temp_r29_1508->unk68 = (f32) sp4F8;
                temp_r29_1508->unk6C = 1.0f;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if (var_f22_444 == 200.0f) {
                    M2C_FIELD(temp_r29_1508, f32 *, 0x88) = 15.0f;
                    M2C_FIELD(temp_r29_1508, f32 *, 0x8C) = 0.0f;
                    M2C_FIELD(temp_r29_1508, s32 *, 0x98) = 1;
                }
            default:                                /* switch 1 */
block_105:
                M2C_FIELD(temp_r29_1508, f32 *, 0x90) = (f32) ((10.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r29_1508, f32 *, 0x90));
                temp_f26_1380 = 20.0f * _table_sinf(M2C_FIELD(temp_r29_1508, f32 *, 0x90));
                temp_f0_1382 = M2C_FIELD(temp_r29_1508, f64 *, 0x30) * (f64) temp_f26_1380;
                sp150 = temp_f0_1382;
                temp_r3_1385 = this->unk15C;
                temp_f1_1386 = temp_r29_1508->unk38 * temp_f26_1380;
                sp420.unk30 = temp_f0_1382;
                sp158 = temp_f1_1386;
                sp420.unk38 = (f64) sp158;
                temp_r3_1395 = M2C_FIELD(temp_r3_1385->unk44, void *(**)(MKHeap *, f32), 0x3C)(temp_r3_1385, temp_f1_1386);
                if (temp_r3_1395 != NULL) {
                    temp_r23_1398 = M2C_FIELD(temp_r3_1395, void **, 0x2C);
                    sp70 = temp_r29_1508->unk60 + M2C_BITWISE(f64, sp420.unk30);
                    M2C_FIELD(temp_r3_1395, f64 *, 0) = sp70;
                    sp78 = temp_r29_1508->unk68 + M2C_BITWISE(f32, sp420.unk38);
                    sp240 = sp70;
                    M2C_FIELD(temp_r3_1395, f64 *, 8) = (f64) sp78;
                    M2C_FIELD(temp_r3_1395, f32 *, 0x20) = 0.0f;
                    sp248 = (f64) sp78;
                    M2C_FIELD(temp_r3_1395, f32 *, 0x28) = 0.0f;
                    M2C_FIELD(temp_r3_1395, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                    sp60 = 0.0f;
                    sp64 = 0.0f;
                    sp68 = 0.0f;
                    M2C_FIELD(temp_r23_1398, f64 *, 0) = (f64) sp60;
                    M2C_FIELD(temp_r23_1398, f64 *, 8) = (f64) sp68;
                    sp230 = (f64) sp60;
                    sp238 = (f64) sp68;
                    M2C_FIELD(temp_r23_1398, f32 *, 0x18) = 1.0f;
                    M2C_FIELD(temp_r23_1398, f32 *, 0x10) = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
                    M2C_FIELD(temp_r23_1398, f32 *, 0x14) = M2C_BITWISE(f32, this->unk15C->unkF4);
                }
                temp_r3_1441 = this->unk160;
                temp_r3_1445 = M2C_FIELD(temp_r3_1441->unk44, void *(**)(MKHeap *), 0x3C)(temp_r3_1441);
                if (temp_r3_1445 != NULL) {
                    temp_r23_1448 = M2C_FIELD(temp_r3_1445, void **, 0x2C);
                    sp50 = temp_r29_1508->unk60 + M2C_BITWISE(f64, sp420.unk30);
                    M2C_FIELD(temp_r3_1445, f64 *, 0) = sp50;
                    sp58 = temp_r29_1508->unk68 + M2C_BITWISE(f32, sp420.unk38);
                    sp220 = sp50;
                    M2C_FIELD(temp_r3_1445, f64 *, 8) = (f64) sp58;
                    M2C_FIELD(temp_r3_1445, f32 *, 0x20) = 0.0f;
                    sp228 = (f64) sp58;
                    M2C_FIELD(temp_r3_1445, f32 *, 0x28) = 0.0f;
                    M2C_FIELD(temp_r3_1445, f32 *, 0x24) = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
                    sp40 = 0.0f;
                    sp44 = 0.0f;
                    sp48 = 0.0f;
                    M2C_FIELD(temp_r23_1448, f64 *, 0) = (f64) sp40;
                    M2C_FIELD(temp_r23_1448, f64 *, 8) = (f64) sp48;
                    M2C_FIELD(temp_r23_1448, f32 *, 0x18) = 1.0f;
                    M2C_FIELD(temp_r23_1448, f32 *, 0x10) = -3.1415927f;
                    sp210 = (f64) sp40;
                    sp218 = (f64) sp48;
                    M2C_FIELD(temp_r23_1448, f32 *, 0x14) = M2C_BITWISE(f32, this->unk160->unkF4);
                }
                if ((ManagedLight *) M2C_FIELD(temp_r29_1508, ManagedLight **, 0x84) != NULL) {
                    temp_r3_1491 = this->unkF8;
                    temp_r3_1491->unk10 = temp_r29_1508->unk60;
                    temp_r3_1491->unk18 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                    temp_r3_1496 = temp_r3_1491->unk3C;
                    if (temp_r3_1496 != NULL) {
                        M2C_FIELD(temp_r3_1496, f64 *, 0x10) = (f64) temp_r29_1508->unk60;
                        M2C_FIELD(temp_r3_1496, f64 *, 0x18) = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                    }
                }
                break;
            case 1:                                 /* switch 1 */
                var_r27_331 += 1;
                var_f22_667 = 3.4028235e38f;
                sp4D0 = M2C_FIELD(temp_r29_1508, f64 *, 0x70);
                sp4D8 = M2C_FIELD(temp_r29_1508, f64 *, 0x78);
                if ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL) {
                    sp120 = sp520 - temp_r29_1508->unk60;
                    sp4D0 = sp120;
                    sp128 = (f32) sp528 - temp_r29_1508->unk68;
                    sp4D8 = (f64) sp128;
                    sp3C0 = sp120;
                    sp3C8 = (f64) sp128;
                    var_f4_695 = ((f32) sp4D8 * (f32) sp4D8) + (((f32) sp4D0 * (f32) sp4D0) + (unksp4D4 * unksp4D4));
                    if (var_f4_695 > 0.000001f) {
                        if (var_f4_695 > 0.0f) {
                            temp_f1_701 = __frsqrte(var_f4_695);
                            temp_f1_707 = 0.5 * temp_f1_701 * -(((f64) var_f4_695 * (temp_f1_701 * temp_f1_701)) - 3.0);
                            temp_f1_711 = 0.5 * temp_f1_707 * -(((f64) var_f4_695 * (temp_f1_707 * temp_f1_707)) - 3.0);
                            var_f4_695 = (f32) ((f64) var_f4_695 * (0.5 * temp_f1_711 * -(((f64) var_f4_695 * (temp_f1_711 * temp_f1_711)) - 3.0)));
                        } else if (var_f4_695 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_695 = __float_nan;
                        } else {
                            sp14 = var_f4_695;
                            temp_r3_730 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                            switch (temp_r3_730) {  /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                    var_r0_740 = 1;
                                } else {
                                    var_r0_740 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
                    sp4D0 = (f32) sp4D0 * var_f3_762;
                    unksp4D4 *= var_f3_762;
                    sp4D8 = (f32) sp4D8 * var_f3_762;
                }
                M2C_FIELD(temp_r29_1508, f32 *, 0x8C) = (f32) (M2C_FIELD(temp_r29_1508, f32 *, 0x8C) + gUpdateTimeDelta);
                var_f1_786 = _table_sinf(2.0f * M2C_FIELD(temp_r29_1508, f32 *, 0x8C));
                if (var_f1_786 < 0.0f) {
                    var_f1_786 = -var_f1_786;
                }
                KDMath_Slerp(sp3A0, *((MKVector3 *) &temp_r29_1508->unk70), 5.0f * (gUpdateTimeDelta * var_f1_786));
                Normalise(sp3B0);
                M2C_FIELD(temp_r29_1508, f64 *, 0x70) = M2C_BITWISE(f64, sp3B0);
                M2C_FIELD(temp_r29_1508, f64 *, 0x78) = (f64) sp3B0.unk8;
                temp_f1_809 = temp_r29_1508->unk60;
                sp4C0 = temp_f1_809;
                sp4C8 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                temp_f0_815 = M2C_FIELD(temp_r29_1508, f64 *, 0x70) * 5.7488258e-315;
                sp1C0 = temp_f0_815;
                sp380 = temp_f0_815;
                sp1C8 = (f32) M2C_FIELD(temp_r29_1508, f64 *, 0x78) * 3500.0f;
                sp388 = (f64) sp1C8;
                temp_f0_825 = temp_f0_815 * (f64) gUpdateTimeDelta;
                sp1B0 = temp_f0_825;
                sp390 = temp_f0_825;
                sp1B8 = (f32) sp388 * gUpdateTimeDelta;
                sp398 = (f64) sp1B8;
                sp1A0 = temp_f1_809 + temp_f0_825;
                sp4B0 = sp1A0;
                sp1A8 = (f32) sp4C8 + (f32) sp398;
                sp4B8 = (f64) sp1A8;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if (M2C_FIELD(temp_r29_1508, f32 *, 0x88) == 0.0f) {
                    sp118 = -1.0f;
                    M2C_FIELD(temp_r29_1508, s32 *, 0x98) = 2;
                    sp108 = 1.0f;
                    M2C_FIELD(temp_r29_1508, f32 *, 0x88) = 2.5f;
                    sp110 = -1.0f;
                    sp114 = -1.0f;
                    sp100 = 1.0f;
                    sp104 = 1.0f;
                    sp310 = (f64) sp110;
                    sp318 = (f64) sp118;
                    sp300 = (f64) sp100;
                    sp308 = (f64) sp108;
                    KDRand_Vector(sp320, *((MKVector3 *) &sp310));
                    temp_f0_878 = sp320 * 5.634608575e-315;
                    spF0 = temp_f0_878;
                    temp_r3_884 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                    sp330 = temp_f0_878;
                    temp_f1_886 = M2C_FIELD(temp_r3_884, f64 *, 0x30);
                    spF8 = sp320.unk8 * 500.0f;
                    sp340 = temp_f1_886;
                    sp338 = (f64) spF8;
                    sp348 = M2C_FIELD(temp_r3_884, f64 *, 0x38);
                    temp_f0_895 = temp_f1_886 + temp_f0_878;
                    spE0 = temp_f0_895;
                    sp350 = temp_f0_895;
                    spE8 = (f32) sp348 + (f32) sp338;
                    sp358 = (f64) spE8;
                    temp_f0_907 = sp350 - sp4B0;
                    spD0 = temp_f0_907;
                    sp360 = temp_f0_907;
                    spD8 = (f32) sp358 - (f32) sp4B8;
                    sp368 = (f64) spD8;
                    Normalise(sp370);
                    M2C_FIELD(temp_r29_1508, f64 *, 0x70) = M2C_BITWISE(f64, sp370);
                    M2C_FIELD(temp_r29_1508, f64 *, 0x78) = (f64) sp370.unk8;
                }
                sp198 = 0.0f;
                sp190 = 0.0f;
                sp194 = 1.0f;
                sp4A8 = (f64) sp198;
                sp4A0 = (f64) sp190;
                KDMath_BuildMatrixFromFwd((Matrix *) &temp_r29_1508->unk30, *((MKVector3 *) &temp_r29_1508->unk70), (MKVector3 *) &sp4A0);
                temp_r3_938 = &temp_r29_1508->unk30;
                temp_r3_938->Scale3x3((Matrix *) temp_r3_938, 1.0f);
                M2C_FIELD(temp_r29_1508, f64 *, 0x60) = (f32) sp4B0;
                M2C_FIELD(temp_r29_1508, f32 *, 0x64) = unksp4B4;
                temp_r29_1508->unk68 = (f32) sp4B8;
                temp_r29_1508->unk6C = 1.0f;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if ((var_f22_667 == 200.0f) && ((void *) M2C_FIELD(temp_r29_1508, void **, 0x80) != NULL)) {
                    M2C_FIELD(temp_r29_1508, f32 *, 0x8C) = 0.0f;
                    sp5B0.unk4 = 0;
                    sp5B0.Init(gb.unk0->GetProp(), 0.5f, 3, 0, 4, 0, 1, -1);
                    temp_r3_978 = M2C_FIELD(temp_r29_1508, void **, 0x80);
                    M2C_FIELD(M2C_FIELD(temp_r3_978, void **, 0x44), M2C_UNK (**)(void *, BreathHitMessage *), 0x2C)(temp_r3_978, &sp5B0);
                    if ((var_f22_667 <= 50.0f) && (M2C_FIELD(temp_r29_1508, f32 *, 0x94) <= 0.0f)) {
                        KDSound_Play3d(GS_SpyroFuryConvexExtra3, (MKVector3 *) temp_r28_342, 0U, -1, 0.0f, 0U);
                        M2C_FIELD(temp_r29_1508, f32 *, 0x94) = 2.0f;
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
                        spC0 = 0.0f;
                        spC4 = 0.0f;
                        spC8 = 0.0f;
                        M2C_FIELD(temp_r23_1009, f64 *, 0) = (f64) spC0;
                        M2C_FIELD(temp_r23_1009, f64 *, 8) = (f64) spC8;
                        sp2F0 = (f64) spC0;
                        sp2F8 = (f64) spC8;
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
                        spB0 = 0.0f;
                        spB4 = 0.0f;
                        spB8 = 0.0f;
                        M2C_FIELD(temp_r23_1049, f64 *, 0) = (f64) spB0;
                        M2C_FIELD(temp_r23_1049, f64 *, 8) = (f64) spB8;
                        M2C_FIELD(temp_r23_1049, f32 *, 0x18) = 3.0f;
                        M2C_FIELD(temp_r23_1049, f32 *, 0x10) = -3.1415927f;
                        sp2E0 = (f64) spB0;
                        sp2E8 = (f64) spB8;
                        M2C_FIELD(temp_r23_1049, f32 *, 0x14) = M2C_BITWISE(f32, this->unk160->unkF4);
                    }
                    temp_r3_1080 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                    sp490 = M2C_FIELD(temp_r3_1080, f64 *, 0x30);
                    sp498 = M2C_FIELD(temp_r3_1080, f64 *, 0x38);
                    sp180 = temp_r29_1508->unk60 - sp490;
                    sp2D0 = sp180;
                    sp188 = temp_r29_1508->unk68 - (f32) sp498;
                    sp2D8 = (f64) sp188;
                    var_f4_1105 = ((f32) sp2D8 * (f32) sp2D8) + (((f32) sp2D0 * (f32) sp2D0) + (unksp2D4 * unksp2D4));
                    if (var_f4_1105 > 1e-12f) {
                        if (var_f4_1105 > 0.0f) {
                            temp_f1_1111 = __frsqrte(var_f4_1105);
                            temp_f1_1117 = 0.5 * temp_f1_1111 * -(((f64) var_f4_1105 * (temp_f1_1111 * temp_f1_1111)) - 3.0);
                            temp_f1_1121 = 0.5 * temp_f1_1117 * -(((f64) var_f4_1105 * (temp_f1_1117 * temp_f1_1117)) - 3.0);
                            var_f4_1105 = (f32) ((f64) var_f4_1105 * (0.5 * temp_f1_1121 * -(((f64) var_f4_1105 * (temp_f1_1121 * temp_f1_1121)) - 3.0)));
                        } else if (var_f4_1105 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1105 = __float_nan;
                        } else {
                            sp10 = var_f4_1105;
                            temp_r3_1140 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                            switch (temp_r3_1140) { /* switch 4; irregular */
                            case 0x7F800000:        /* switch 4 */
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_1150 = 1;
                                } else {
                                    var_r0_1150 = 2;
                                }
                                break;
                            case 0x0:               /* switch 4 */
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
                    sp170 = (f32) sp2D0 * var_f3_1172;
                    sp174 = unksp2D4 * var_f3_1172;
                    sp178 = (f32) sp2D8 * var_f3_1172;
                    sp480 = (f64) sp170;
                    sp488 = (f64) sp178;
                    M2C_STRUCT_COPY((s32) &sp56C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                    sp168 = 0.0f;
                    sp160 = 0.0f;
                    sp164 = 1.0f;
                    sp478 = (f64) sp168;
                    sp470 = (f64) sp160;
                    KDMath_BuildMatrixFromFwd(&sp570, *((MKVector3 *) &sp480), (MKVector3 *) &sp470);
                    sp570.Scale3x3(&sp570, 1.5f);
                    sp20 = -(f32) sp480;
                    sp24 = -unksp484;
                    sp28 = -(f32) sp488;
                    sp2A0 = (f64) sp20;
                    sp2A8 = (f64) sp28;
                    sp2B0.operator*(300.0f);
                    spA0 = temp_r29_1508->unk60 + M2C_BITWISE(f64, sp2B0);
                    sp2C0 = spA0;
                    spA8 = temp_r29_1508->unk68 + sp2B0.unk8;
                    sp2C8 = (f64) spA8;
                    sp570.unk30 = (f32) sp2C0;
                    sp570.unk34 = unksp2C4;
                    sp570.unk38 = (f32) sp2C8;
                    sp570.unk3C = 1.0f;
                    gb.unk1C0.StartWarp(&sp570);
                    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                        sp534 = 0;
                        MKVector(1.0f, 1.0f, 1.0f);
                        sp90 = sp280 * 5.56078426e-315;
                        sp530 = 0x417;
                        sp538 = sp90;
                        sp98 = sp288 * 150.0f;
                        sp548 = 1;
                        sp540 = (f64) sp98;
                        sp290 = sp90;
                        sp298 = (f64) sp98;
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp530, sp90);
                    }
                }
                goto block_105;
            case 2:                                 /* switch 1 */
                sp420.unk40 = temp_r29_1508->unk60;
                sp420.unk48 = (f64) M2C_FIELD(temp_r29_1508, f32 *, 0x68);
                sp250.operator*(gUpdateTimeDelta);
                sp260.operator*(2500.0f);
                sp80 = M2C_BITWISE(f64, sp420.unk40) + M2C_BITWISE(f64, sp260);
                sp270 = sp80;
                sp88 = sp420.unk48 + sp260.unk8;
                M2C_FIELD(temp_r29_1508, f64 *, 0x60) = (f32) sp270;
                sp278 = (f64) sp88;
                M2C_FIELD(temp_r29_1508, f32 *, 0x64) = unksp274;
                temp_r29_1508->unk68 = (f32) sp278;
                temp_r29_1508->unk6C = 1.0f;
                M2C_FIELD(temp_r29_1508, f64 *, 0x70) = (f64) (M2C_FIELD(temp_r29_1508, f64 *, 0x70) * 5.26768877e-315);
                M2C_FIELD(temp_r29_1508, f64 *, 0x78) = (f32) ((f32) M2C_FIELD(temp_r29_1508, f64 *, 0x78) * 1.1f);
                M2C_FIELD(temp_r29_1508, u8 *, 0x9C) = 0U;
                if (M2C_FIELD(temp_r29_1508, f32 *, 0x88) <= 0.0f) {
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
    if (((u8) gb.unk381 != 0) && ((s32) this->unkF0 == 0) && (var_r27_331 <= 0)) {
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
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    KDSoundFader **temp_r3_1568;
    KDSoundFader **temp_r3_1575;
    KDSoundFader *temp_r31_1580;
    ManagedLight *temp_r3_1638;
    ManagedLight *temp_r3_1649;
    ManagedLight *temp_r3_1669;
    ManagedLight *temp_r4_1630;
    TargetManager ***var_r27_1691;
    TargetManager **temp_r30_1868;
    f32 *temp_r3_1600;
    f32 temp_f1_1958;
    f32 var_f0_1959;
    f32 var_f29_1686;
    f32 var_f30_1754;
    f32 var_f3_1821;
    f64 temp_f0_1640;
    f64 temp_f0_1932;
    f64 temp_f1_1639;
    f64 temp_f1_1730;
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
    M2C_FIELD(temp_r31_1580, ManagedLight **, 0x84) = (ManagedLight *) this->unkF8;
    M2C_FIELD(temp_r31_1580, s8 *, 0x9C) = 0;
    KDSound_Play3d(GS_SpyroBreathConvex1, (MKVector3 *) &temp_r31_1580->unk60, 0U, -1, 0.0f, 0U);
    temp_r4_1630 = this->unkF8;
    if (temp_r4_1630 != NULL) {
        gb.unk80->EnableLight(temp_r4_1630, 1U);
        temp_r3_1638 = this->unkF8;
        temp_f1_1639 = (f64) M2C_FIELD(&arg0, f32 *, 0);
        temp_f0_1640 = (f64) M2C_FIELD(&arg0, f32 *, 8);
        temp_r3_1638->unk10 = temp_f1_1639;
        temp_r3_1638->unk18 = temp_f0_1640;
        temp_r3_1643 = temp_r3_1638->unk3C;
        if (temp_r3_1643 != NULL) {
            M2C_FIELD(temp_r3_1643, f64 *, 0x10) = temp_f1_1639;
            M2C_FIELD(temp_r3_1643, f64 *, 0x18) = temp_f0_1640;
        }
        temp_r3_1649 = this->unkF8;
        temp_r3_1649->unk38 = 2000.0f;
        temp_r3_1652 = temp_r3_1649->unk3C;
        if (temp_r3_1652 != NULL) {
            M2C_FIELD(temp_r3_1652, f32 *, 0x20) = 2000.0f;
            M2C_FIELD(temp_r3_1652, f32 *, 0x24) = 4000000.0f;
            M2C_FIELD(temp_r3_1652, f32 *, 0x28) = 0.0005f;
            M2C_FIELD(temp_r3_1652, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1652, f32 *, 0x24));
        }
        sp40 = 1.0f;
        temp_r3_1669 = this->unkF8;
        sp44 = 0.0f;
        sp48 = 0.75f;
        sp4C = 1.0f;
        temp_r3_1669->unk20 = (f64) sp40;
        temp_r3_1669->unk28 = (f64) sp48;
        temp_r3_1677 = temp_r3_1669->unk3C;
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
                temp_f1_1730 = M2C_FIELD(temp_r3_1729, f64 *, 0x30);
                sp140 = temp_f1_1730;
                sp148 = M2C_FIELD(temp_r3_1729, f64 *, 0x38);
                sp60 = temp_f1_1730 - (f64) M2C_FIELD(&arg0, f32 *, 0);
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
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
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
        sp30 = temp_r31_1580->unk60 + M2C_BITWISE(f64, sp120);
        sp130 = sp30;
        sp38 = temp_r31_1580->unk68 + sp120.unk8;
        sp170 = sp30;
        sp138 = (f64) sp38;
        sp178 = (f64) sp38;
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, -1.0f, -1.0f);
        KDRand_Vector(spB0, spA0);
        spC0.operator*(0.75f);
        temp_f0_1932 = M2C_FIELD(temp_r31_1580, f64 *, 0x70) + M2C_BITWISE(f64, spC0);
        sp10 = temp_f0_1932;
        spD0 = temp_f0_1932;
        sp18 = (f32) M2C_FIELD(temp_r31_1580, f64 *, 0x78) + spC0.unk8;
        spD8 = (f64) sp18;
        sp20 = temp_f0_1932 * 5.676053805e-315;
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
    ManagedLight *temp_r4_2026;

    SetDefaults();
    Disable();
    temp_r4_2026 = this->unkF8;
    if (temp_r4_2026 != NULL) {
        gb.unk80->EnableLight(temp_r4_2026, 0U);
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
    f64 spF0;
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
    f64 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    ManagedLight *temp_r3_2266;
    ManagedLight *temp_r4_2244;
    f32 temp_f27_2165;
    f32 temp_f31_2169;
    s32 var_r28_2138;
    void *temp_r3_2272;

    Enable();
    this->unk90.unk30 = arg0.unk0;
    this->unk90.unk34 = arg0.unk4;
    this->unk90.unk38 = arg0.unk8;
    this->unk90.unk3C = 1.0f;
    if ((s32) this->unkF0 == 0) {
        this->unk168 = gb.unk2CC.Enable(0.1f, 3.0f, 0.75f, 15.0f);
        this->unkF0 = 1;
        this->unk150 = 0.0f;
        this->unk14C = 1;
        this->unkF4 = 1.0f;
        M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(&arg0, f32 *, 0);
        M2C_FIELD(this, f64 *, 0xE8) = (f64) M2C_FIELD(&arg0, f32 *, 8);
        KDSound_Play3d(GS_SpyroFuryConvexExtra1, &this->unkE0, 0U, -1, 0.0f, 0U);
        MKVector(0.0f, 500.0f, 0.0f);
        sp30 = M2C_FIELD(this, f64 *, 0xE0) + spF0;
        var_r28_2138 = 0;
        this->unkD0 = sp30;
        sp38 = this->unkE0.unk8 + spF8;
        sp100 = sp30;
        this->unkD8 = (f64) sp38;
        this->unk164 = 0.0f;
        this->unk170.unk20 = (f64) M2C_FIELD(&arg0, f32 *, 0);
        sp108 = (f64) sp38;
        this->unk170.unk28 = (f64) M2C_FIELD(&arg0, f32 *, 8);
        do {
            sp120 = M2C_FIELD(this, f64 *, 0xE0);
            sp128 = M2C_FIELD(this, f64 *, 0xE8);
            temp_f27_2165 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            temp_f31_2169 = temp_f27_2165;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(spC0, spB0);
            Normalise(spD0);
            sp20 = spD0 * (f64) temp_f31_2169;
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
        temp_r4_2244 = this->unkF8;
        if (temp_r4_2244 != NULL) {
            gb.unk80->EnableLight(temp_r4_2244, 1U);
            MKVector(0.0f, 100.0f, 0.0f);
            sp10 = M2C_FIELD(this, f64 *, 0xE0) + sp60;
            temp_r3_2266 = this->unkF8;
            sp70 = sp10;
            sp18 = this->unkE0.unk8 + sp68;
            temp_r3_2266->unk10 = sp10;
            temp_r3_2266->unk18 = (f64) sp18;
            temp_r3_2272 = temp_r3_2266->unk3C;
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
    this->unkF0 = 0;
    this->unk90.SetIdentity();
    this->unkF4 = 0.0f;
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
    ManagedLight *temp_r4_2338;
    u32 temp_r0_2368;

    temp_r4_2338 = this->unkF8;
    if (temp_r4_2338 != NULL) {
        gb.unk80->EnableLight(temp_r4_2338, 0U);
        gb.unk80->FreeManagedLight(this->unkF8);
        this->unkF8 = NULL;
    }
    MKModel_Destroy(this->unk1E0);
    KDSound_Stop(&this->unkFC);
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
    this->unkFC.Message(arg0);
    this->unk124.Message(arg0);
    KDProp::Message(arg0);
}
#endif

#if 0 // DRAFT: expression syntax error
void FuryFXConvexity::Update() {
    f64 sp8B8;
    Matrix sp870;
    f32 sp86C;
    f32 sp868;
    f32 sp864;
    f32 sp860;
    Matrix sp7F0;
    M2C_UNK sp7EC;
    s8 sp7E0;
    f64 sp7D8;
    f64 sp7D0;
    s32 sp7CC;
    s32 sp7C8;
    s8 sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    s32 sp7AC;
    s32 sp7A8;
    s8 sp7A0;
    f64 sp798;
    f64 sp790;
    s32 sp78C;
    s32 sp788;
    s8 sp780;
    f64 sp778;
    f64 sp770;
    s32 sp76C;
    s32 sp768;
    f32 sp760;
    s32 sp75C;
    s32 sp758;
    f64 sp750;
    f64 sp748;
    f64 sp740;
    f64 sp738;
    f64 sp730;
    f64 sp728;
    f64 sp720;
    f64 sp718;
    f64 sp710;
    f64 sp708;
    f64 sp700;
    f64 sp6F8;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    f64 sp6B8;
    f64 sp6B0;
    f64 sp6A8;
    f64 sp6A0;
    f64 sp698;
    f64 sp690;
    f64 sp688;
    f64 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    f64 sp648;
    f32 sp640;
    s32 sp63C;
    s32 sp638;
    f64 sp630;                                      /* compiler-managed */
    f64 sp628;
    f64 sp620;
    f64 sp618;
    MKVector3 sp608;
    MKVector3 sp5F8;
    MKVector3 sp5E8;
    M2C_UNK sp5D8;
    f64 sp5D0;
    f64 sp5C8;
    MKVector3 sp5B8;
    MKVector3 sp5A8;
    MKVector3 sp598;
    M2C_UNK sp588;
    f64 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    MKVector3 sp528;
    MKVector3 sp518;
    MKVector3 sp508;
    M2C_UNK sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    MKVector3 sp4D8;
    MKVector3 sp4C8;
    MKVector3 sp4B8;
    M2C_UNK sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    MKVector3 sp438;
    MKVector3 sp428;
    MKVector3 sp418;
    M2C_UNK sp408;
    f64 sp400;
    f64 sp3F8;
    MKVector3 sp3E8;
    MKVector3 sp3D8;
    MKVector3 sp3C8;
    M2C_UNK sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    MKVector3 sp378;
    MKVector3 sp368;
    M2C_UNK sp358;
    f64 sp350;
    f64 sp348;
    MKVector3 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    M2C_UNK sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp220;
    f64 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f64 sp1A8;
    f32 sp1A0;
    f64 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    ManagedLight *temp_r3_4111;
    ManagedLight *temp_r4_2542;
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
    f32 temp_f25_2740;
    f32 temp_f25_3060;
    f32 temp_f25_3284;
    f32 temp_f26_3386;
    f32 temp_f2_2558;
    f32 temp_f2_2572;
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
    f64 temp_f0_3700;
    f64 temp_f0_3711;
    f64 temp_f1_2872;
    f64 temp_f1_2878;
    f64 temp_f1_2882;
    f64 temp_f1_3500;
    f64 temp_f1_3540;
    f64 temp_f1_3546;
    f64 temp_f1_3550;
    f64 temp_f1_3733;
    f64 temp_f1_3739;
    f64 temp_f1_3743;
    f64 temp_f1_3851;
    f64 temp_f1_3857;
    f64 temp_f1_3861;
    f64 temp_f2_3512;
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

    this->unkF4 = this->unkF4 - gUpdateTimeDelta;
    sp8 = 1;
    this->unkFC.Update(GS_SpyroFuryConvexLP1, 1U, this->unk14C, NULL, (MKVector3 *) &this->unkD0, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    this->unk124.Update(GS_SpyroFuryConvexLP3, 1U, this->unk14D, NULL, (MKVector3 *) &this->unkD0, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    UpdateDragonChasers();
    if ((LightActiveOnChasers() == 0) && ((s32) this->unkF0 == 0)) {
        temp_r4_2542 = this->unkF8;
        if (temp_r4_2542 != NULL) {
            gb.unk80->EnableLight(temp_r4_2542, 0U);
        }
    }
    if (this->unk150 >= 0.0f) {
        this->unk154 = 0.0f;
        temp_f2_2558 = this->unk150;
        if ((temp_f2_2558 > 1.43f) && (temp_f2_2558 <= 1.45f)) {
            KDSound_Play3d(GS_SpyroFuryConvexLP2, &this->unkE0, 0U, -1, 0.0f, 0U);
        }
        temp_f2_2572 = this->unk150;
        if ((temp_f2_2572 > 1.6f) && (temp_f2_2572 <= 3.1f)) {
            this->unk154 = (0.6666f * (temp_f2_2572 - 1.6f) * 0.8f) + 0.0f;
        } else if ((temp_f2_2572 > 3.18f) && (temp_f2_2572 <= 3.6f)) {
            this->unk154 = 1.0f;
        } else if ((temp_f2_2572 > 3.6f) && (temp_f2_2572 <= 5.8f)) {
            this->unk154 = (0.4545f * (temp_f2_2572 - 3.6f) * -1.0f) + 1.0f;
        } else if (temp_f2_2572 > 6.0f) {
            this->unk150 = -1.0f;
        }
        temp_f15_2623 = this->unk154;
        ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.7f * temp_f15_2623, temp_f15_2623, 0.033f, 0, 4.0f, 0U);
        this->unk150 += gUpdateTimeDelta;
    }
    temp_r0_2643 = this->unkF0;
    if ((u32) temp_r0_2643 <= 6U) {
        switch (temp_r0_2643) {                     /* switch 1 */
            return;
        case 1:                                     /* switch 1 */
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                var_f15_2660 = this->unkF4;
                if (var_f15_2660 < 1.0f) {

                } else {
                    var_f15_2660 = 1.0f;
                }
                if (var_f15_2660 > 0.0f) {

                } else {
                    var_f15_2660 = 0.0f;
                }
                sp75C = 0;
                temp_f1_2680 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                sp758 = 0x458;
                sp760 = temp_f1_2680 + (0.017453292f * (30.0f * (1.0f - var_f15_2660)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp758, 30.0f, 0.017453292f);
            }
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp5F8, sp5E8);
            sp608.operator*(400.0f);
            sp118 = M2C_FIELD(this, f64 *, 0xE0) + M2C_BITWISE(f64, sp608);
            sp618 = sp118;
            sp120 = this->unkE0.unk8 + sp608.unk8;
            sp748 = sp118;
            sp620 = (f64) sp120;
            sp750 = (f64) sp120;
            temp_f14_2737 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            temp_f25_2740 = temp_f14_2737;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp5A8, sp598);
            Normalise(sp5B8);
            sp108 = sp5B8 * (f64) temp_f25_2740;
            sp5C8 = sp108;
            sp110 = sp5B8.unk8 * temp_f14_2737;
            sp738 = sp108;
            sp5D0 = (f64) sp110;
            sp740 = (f64) sp110;
            sp230 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            sp234 = 1.0f;
            sp228 = 1.0f;
            sp22C = 0.0f;
            sp580 = (f64) sp230;
            sp578 = (f64) sp228;
            sp2C = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &sp748), *((MKVector3 *) &sp738), sp2C, *((MKVector4 *) &sp578), 0.0f);
            if (this->unkF4 <= 0.0f) {
                this->unkF0 = 2;
                this->unkF4 = 2.0f;
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp7CC = 0;
                    MKVector(1.0f, 1.0f, 1.0f);
                    spF8 = sp558 * 5.56078426e-315;
                    sp7C8 = 0x417;
                    sp7D0 = spF8;
                    sp100 = sp560 * 150.0f;
                    sp7E0 = 1;
                    sp7D8 = (f64) sp100;
                    sp568 = spF8;
                    sp570 = (f64) sp100;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp7C8, spF8);
                }
                temp_r3_2842 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                sp728 = M2C_FIELD(temp_r3_2842, f64 *, 0x30);
                sp730 = M2C_FIELD(temp_r3_2842, f64 *, 0x38);
                sp218 = this->unkD0 - sp728;
                sp548 = sp218;
                sp220 = M2C_FIELD(this, f32 *, 0xD8) - (f32) sp730;
                sp550 = (f64) sp220;
                var_f4_2866 = ((f32) sp550 * (f32) sp550) + (((f32) sp548 * (f32) sp548) + (unksp54C * unksp54C));
                if (var_f4_2866 > 1e-12f) {
                    if (var_f4_2866 > 0.0f) {
                        temp_f1_2872 = __frsqrte(var_f4_2866);
                        temp_f1_2878 = 0.5 * temp_f1_2872 * -(((f64) var_f4_2866 * (temp_f1_2872 * temp_f1_2872)) - 3.0);
                        temp_f1_2882 = 0.5 * temp_f1_2878 * -(((f64) var_f4_2866 * (temp_f1_2878 * temp_f1_2878)) - 3.0);
                        var_f4_2866 = (f32) ((f64) var_f4_2866 * (0.5 * temp_f1_2882 * -(((f64) var_f4_2866 * (temp_f1_2882 * temp_f1_2882)) - 3.0)));
                    } else if (var_f4_2866 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_2866 = __float_nan;
                    } else {
                        sp1C = var_f4_2866;
                        temp_r3_2901 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                        switch (temp_r3_2901) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                var_r0_2911 = 1;
                            } else {
                                var_r0_2911 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
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
                sp20C = unksp54C * var_f3_2933;
                sp208 = (f32) sp548 * var_f3_2933;
                sp210 = (f32) sp550 * var_f3_2933;
                sp718 = (f64) sp208;
                sp720 = (f64) sp210;
                M2C_STRUCT_COPY((s32) &sp86C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp200 = 0.0f;
                sp1F8 = 0.0f;
                sp1FC = 1.0f;
                sp710 = (f64) sp200;
                sp708 = (f64) sp1F8;
                KDMath_BuildMatrixFromFwd(&sp870, *((MKVector3 *) &sp718), (MKVector3 *) &sp708);
                sp870.Scale3x3(&sp870, 3.0f);
                sp870.unk30 = (f32) M2C_FIELD(this, f64 *, 0xD0);
                sp870.unk34 = M2C_FIELD(this, f32 *, 0xD4);
                sp870.unk38 = M2C_FIELD(this, f32 *, 0xD8);
                sp870.unk3C = 1.0f;
                gb.unk1C0.StartWarp(&sp870);
            }
            goto block_159;
        case 2:                                     /* switch 1 */
            var_f3_2993 = this->unkF4;
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
            KDRand_Vector(sp518, sp508);
            sp528.operator*(400.0f);
            spE8 = M2C_FIELD(this, f64 *, 0xE0) + M2C_BITWISE(f64, sp528);
            sp538 = spE8;
            spF0 = this->unkE0.unk8 + sp528.unk8;
            sp6F8 = spE8;
            sp540 = (f64) spF0;
            sp700 = (f64) spF0;
            temp_f14_3057 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            temp_f25_3060 = temp_f14_3057;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp4C8, sp4B8);
            Normalise(sp4D8);
            spD8 = sp4D8 * (f64) temp_f25_3060;
            sp4E8 = spD8;
            spE0 = sp4D8.unk8 * temp_f14_3057;
            sp6E8 = spD8;
            sp4F0 = (f64) spE0;
            sp6F0 = (f64) spE0;
            sp1F0 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            sp1F4 = 1.0f;
            sp1E8 = 1.0f;
            sp1EC = 0.0f;
            sp4A0 = (f64) sp1F0;
            sp498 = (f64) sp1E8;
            sp28 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &sp6F8), *((MKVector3 *) &sp6E8), sp28, *((MKVector4 *) &sp498), 0.0f);
            if (this->unkF4 <= 0.0f) {
                this->unkF4 = 0.1f;
                this->unkF0 += 1;
            } else if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp7AC = 0;
                temp_f15_3139 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f16_3144 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f16_3144, temp_f15_3139);
                spC8 = sp478 * 5.398241246e-315;
                sp7A8 = 0x417;
                sp7B0 = spC8;
                spD0 = sp480 * 10.0f;
                sp7C0 = 1;
                sp7B8 = (f64) spD0;
                sp488 = spC8;
                sp490 = (f64) spD0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp7A8, spC8);
            }
            goto block_159;
        case 3:                                     /* switch 1 */
            EmitVortexParticles();
            if (this->unkF4 <= 0.0f) {
                this->unkF4 = 0.1f;
                this->unkF0 += 1;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp78C = 0;
                temp_f15_3203 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f16_3208 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f16_3208, temp_f15_3203);
                spB8 = sp458 * 5.398241246e-315;
                sp788 = 0x417;
                sp790 = spB8;
                spC0 = sp460 * 10.0f;
                sp7A0 = 1;
                sp798 = (f64) spC0;
                sp468 = spB8;
                sp470 = (f64) spC0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp788, spB8);
            }
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp428, sp418);
            sp438.operator*(400.0f);
            spA8 = M2C_FIELD(this, f64 *, 0xE0) + M2C_BITWISE(f64, sp438);
            sp448 = spA8;
            spB0 = this->unkE0.unk8 + sp438.unk8;
            sp6D8 = spA8;
            sp450 = (f64) spB0;
            sp6E0 = (f64) spB0;
            temp_f14_3281 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            temp_f25_3284 = temp_f14_3281;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp3D8, sp3C8);
            Normalise(sp3E8);
            sp98 = sp3E8 * (f64) temp_f25_3284;
            sp3F8 = sp98;
            spA0 = sp3E8.unk8 * temp_f14_3281;
            sp6C8 = sp98;
            sp400 = (f64) spA0;
            sp6D0 = (f64) spA0;
            sp1E0 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            sp1E4 = 1.0f;
            sp1D8 = 1.0f;
            sp1DC = 0.0f;
            sp3B0 = (f64) sp1E0;
            sp3A8 = (f64) sp1D8;
            sp24 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &sp6D8), *((MKVector3 *) &sp6C8), sp24, *((MKVector4 *) &sp3A8), 0.0f);
            goto block_159;
        case 4:                                     /* switch 1 */
            EmitVortexParticles();
            MKVector(1.0f, 2.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp378, sp368);
            sp388.operator*(400.0f);
            sp88 = M2C_FIELD(this, f64 *, 0xE0) + M2C_BITWISE(f64, sp388);
            sp398 = sp88;
            sp90 = this->unkE0.unk8 + sp388.unk8;
            sp6B8 = sp88;
            sp3A0 = (f64) sp90;
            sp6C0 = (f64) sp90;
            temp_f14_3383 = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
            temp_f26_3386 = temp_f14_3383;
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp328, sp318);
            Normalise(sp338);
            sp78 = sp338 * (f64) temp_f26_3386;
            sp348 = sp78;
            sp80 = sp338.unk8 * temp_f14_3383;
            sp6A8 = sp78;
            sp350 = (f64) sp80;
            sp6B0 = (f64) sp80;
            sp1D0 = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            sp1D4 = 1.0f;
            sp1C8 = 1.0f;
            sp1CC = 0.0f;
            sp300 = (f64) sp1D0;
            sp2F8 = (f64) sp1C8;
            sp20 = MKRand_Float(&gViewSeed, 3.0f, 5.0f);
            gb.unk74->Emit(*((MKVector3 *) &sp6B8), *((MKVector3 *) &sp6A8), sp20, *((MKVector4 *) &sp2F8), 0.0f);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp76C = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                sp68 = sp2D8 * 5.634608575e-315;
                sp768 = 0x417;
                sp770 = sp68;
                sp70 = sp2E0 * 500.0f;
                sp780 = 1;
                sp778 = (f64) sp70;
                sp2E8 = sp68;
                sp2F0 = (f64) sp70;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp768, sp68);
            }
            var_f0_3480 = 0.0f;
            if (this->unkF4 <= 0.0f) {
                this->unkF4 = 5.0f;
                sp1C0 = 0.0f;
                sp1B8 = 0.0f;
                sp1BC = 500.0f;
                this->unkF0 += 1;
                sp2C8 = (f64) sp1B8;
                sp2D0 = (f64) sp1C0;
                temp_f1_3500 = M2C_FIELD(this, f64 *, 0xC0) + sp2C8;
                sp1A8 = temp_f1_3500;
                sp698 = temp_f1_3500;
                sp1B0 = this->unk90.unk38 + (f32) sp2D0;
                sp6A0 = (f64) sp1B0;
                temp_r3_3511 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f2_3512 = M2C_FIELD(temp_r3_3511, f64 *, 0x30);
                sp2A8 = temp_f2_3512;
                sp2B0 = M2C_FIELD(temp_r3_3511, f64 *, 0x38);
                sp198 = temp_f2_3512 - temp_f1_3500;
                sp2B8 = sp198;
                sp1A0 = (f32) sp2B0 - (f32) sp6A0;
                sp2C0 = (f64) sp1A0;
                var_f4_3535 = ((f32) sp2C0 * (f32) sp2C0) + (((f32) sp2B8 * (f32) sp2B8) + (unksp2BC * unksp2BC));
                if (var_f4_3535 > 1e-12f) {
                    if (var_f4_3535 > 0.0f) {
                        temp_f1_3540 = __frsqrte(var_f4_3535);
                        temp_f1_3546 = 0.5 * temp_f1_3540 * -(((f64) var_f4_3535 * (temp_f1_3540 * temp_f1_3540)) - 3.0);
                        temp_f1_3550 = 0.5 * temp_f1_3546 * -(((f64) var_f4_3535 * (temp_f1_3546 * temp_f1_3546)) - 3.0);
                        var_f4_3535 = (f32) ((f64) var_f4_3535 * (0.5 * temp_f1_3550 * -(((f64) var_f4_3535 * (temp_f1_3550 * temp_f1_3550)) - 3.0)));
                    } else if (var_f4_3535 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3535 = __float_nan;
                    } else {
                        sp18 = var_f4_3535;
                        temp_r3_3569 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_3569) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_3579 = 1;
                            } else {
                                var_r0_3579 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
                sp18C = unksp2BC * var_f0_3480;
                sp188 = (f32) sp2B8 * var_f0_3480;
                sp190 = (f32) sp2C0 * var_f0_3480;
                sp688 = (f64) sp188;
                sp690 = (f64) sp190;
                DisableChaserLights();
                M2C_STRUCT_COPY((s32) &sp7F0.unk3C + 4, (s32) (M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8) - 4) + 4, 0x40);
                var_r28_3629 = 0;
                sp86C = 1.0f;
                sp860 = 0.0f;
                sp864 = 0.0f;
                sp868 = 0.0f;
                sp8B8 = 3.60985932e-315;
                do {
                    temp_f14_3659 = 6.2831855f * ((f32) var_r28_3629 / 10.0f);
                    temp_f15_3662 = -_table_sinf(1.5707964f + temp_f14_3659);
                    sp58 = _table_sinf(temp_f14_3659);
                    sp5C = temp_f15_3662;
                    sp60 = 0.0f;
                    sp678 = (f64) sp58;
                    sp680 = (f64) sp60;
                    sp298 = (f64) sp58;
                    sp2A0 = (f64) sp60;
                    sp48 = 0.0f + (((f32) sp680 * sp850) + (((f32) sp678 * sp830) + (unksp67C * sp840)));
                    sp4C = 0.0f + (((f32) sp680 * sp854) + (((f32) sp678 * sp834) + (unksp67C * sp844)));
                    sp50 = 0.0f + (((f32) sp680 * sp858) + (((f32) sp678 * sp838) + (unksp67C * sp848)));
                    sp678 = (f64) sp48;
                    sp288 = (f64) sp48;
                    sp290 = (f64) sp50;
                    sp680 = (f64) sp50;
                    temp_f0_3700 = sp678 * 5.2552552e-315;
                    sp178 = temp_f0_3700;
                    sp258 = temp_f0_3700;
                    sp180 = (f32) sp680 * 0.9f;
                    sp260 = (f64) sp180;
                    temp_f0_3711 = sp688 + temp_f0_3700;
                    sp168 = temp_f0_3711;
                    sp268 = temp_f0_3711;
                    sp170 = (f32) sp690 + (f32) sp260;
                    sp270 = (f64) sp170;
                    var_f4_3727 = ((f32) sp270 * (f32) sp270) + (((f32) sp268 * (f32) sp268) + (unksp26C * unksp26C));
                    if (var_f4_3727 > (f32) sp8B8) {
                        if (var_f4_3727 > 0.0f) {
                            temp_f1_3733 = __frsqrte(var_f4_3727);
                            temp_f1_3739 = 0.5 * temp_f1_3733 * -(((f64) var_f4_3727 * (temp_f1_3733 * temp_f1_3733)) - 3.0);
                            temp_f1_3743 = 0.5 * temp_f1_3739 * -(((f64) var_f4_3727 * (temp_f1_3739 * temp_f1_3739)) - 3.0);
                            var_f4_3727 = (f32) ((f64) var_f4_3727 * (0.5 * temp_f1_3743 * -(((f64) var_f4_3727 * (temp_f1_3743 * temp_f1_3743)) - 3.0)));
                        } else if (var_f4_3727 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_3727 = __float_nan;
                        } else {
                            sp14 = var_f4_3727;
                            temp_r3_3762 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                            switch (temp_r3_3762) { /* switch 4; irregular */
                            case 0x7F800000:        /* switch 4 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                    var_r0_3772 = 1;
                                } else {
                                    var_r0_3772 = 2;
                                }
                                break;
                            case 0x0:               /* switch 4 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
                    sp158 = (f32) sp268 * var_f3_3794;
                    sp15C = unksp26C * var_f3_3794;
                    sp160 = (f32) sp270 * var_f3_3794;
                    sp278 = (f64) sp158;
                    sp280 = (f64) sp160;
                    LaunchDragonChaser(*((MKVector3 *) &sp698), *((MKVector3 *) &sp278));
                    var_r28_3629 += 1;
                } while (var_r28_3629 < 0xA);
                temp_r3_3821 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                sp668 = M2C_FIELD(temp_r3_3821, f64 *, 0x30);
                sp670 = M2C_FIELD(temp_r3_3821, f64 *, 0x38);
                sp148 = this->unkD0 - sp668;
                sp248 = sp148;
                sp150 = M2C_FIELD(this, f32 *, 0xD8) - (f32) sp670;
                sp250 = (f64) sp150;
                var_f4_3845 = ((f32) sp250 * (f32) sp250) + (((f32) sp248 * (f32) sp248) + (unksp24C * unksp24C));
                if (var_f4_3845 > 1e-12f) {
                    if (var_f4_3845 > 0.0f) {
                        temp_f1_3851 = __frsqrte(var_f4_3845);
                        temp_f1_3857 = 0.5 * temp_f1_3851 * -(((f64) var_f4_3845 * (temp_f1_3851 * temp_f1_3851)) - 3.0);
                        temp_f1_3861 = 0.5 * temp_f1_3857 * -(((f64) var_f4_3845 * (temp_f1_3857 * temp_f1_3857)) - 3.0);
                        var_f4_3845 = (f32) ((f64) var_f4_3845 * (0.5 * temp_f1_3861 * -(((f64) var_f4_3845 * (temp_f1_3861 * temp_f1_3861)) - 3.0)));
                    } else if (var_f4_3845 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3845 = __float_nan;
                    } else {
                        sp10 = var_f4_3845;
                        temp_r3_3880 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_3880) {     /* switch 5; irregular */
                        case 0x7F800000:            /* switch 5 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_3890 = 1;
                            } else {
                                var_r0_3890 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 5 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
                sp13C = unksp24C * var_f3_3912;
                sp138 = (f32) sp248 * var_f3_3912;
                sp140 = (f32) sp250 * var_f3_3912;
                sp658 = (f64) sp138;
                sp660 = (f64) sp140;
                M2C_STRUCT_COPY((s32) &sp7EC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp130 = 0.0f;
                sp128 = 0.0f;
                sp12C = 1.0f;
                sp650 = (f64) sp130;
                sp648 = (f64) sp128;
                KDMath_BuildMatrixFromFwd(&sp7F0, *((MKVector3 *) &sp658), (MKVector3 *) &sp648);
                sp7F0.Scale3x3(&sp7F0, 3.0f);
                sp7F0.unk30 = (f32) M2C_FIELD(this, f64 *, 0xD0);
                sp7F0.unk34 = M2C_FIELD(this, f32 *, 0xD4);
                sp7F0.unk38 = M2C_FIELD(this, f32 *, 0xD8);
                sp7F0.unk3C = 1.0f;
                gb.unk1C0.StartWarp(&sp7F0);
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
            var_f15_3998 = this->unkF4 / 5.0f;
            if (var_f15_3998 < 1.0f) {

            } else {
                var_f15_3998 = 1.0f;
            }
            if (var_f15_3998 > 0.0f) {

            } else {
                var_f15_3998 = 0.0f;
            }
            if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && (var_f15_3998 <= 0.5f)) {
                sp63C = 0;
                temp_f1_4026 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                sp638 = 0x458;
                sp640 = temp_f1_4026 + (0.017453292f * (30.0f * (var_f15_3998 / 0.5f)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp638, 30.0f, 0.017453292f);
            }
            if (this->unkF4 <= 0.0f) {
                this->unkF0 = 6;
                this->unkF4 = 1.4f;
                KDSound_Play3d(GS_SpyroFuryConvexExtra2, &this->unkE0, 0U, -1, 0.0f, 0U);
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp34 = 0;
                    sp30 = 0x459;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp30);
                }
                gb.unk2CC.Disable(this->unk168);
            }
            goto block_159;
        case 6:                                     /* switch 1 */
            var_f0_4079 = this->unkF4;
            if (var_f0_4079 < 1.4f) {

            } else {
                var_f0_4079 = 1.4f;
            }
            if (var_f0_4079 > 0.0f) {

            } else {
                var_f0_4079 = 0.0f;
            }
            this->unkF4 = var_f0_4079;
            if (this->unkF4 <= 0.0f) {
                this->unkF0 = 0;
            }
            goto block_159;
        }
    } else {
block_159:
        gb.unk74->ApplyWind(&this->unk170);
        if ((s32) this->unkF0 <= 4) {
            temp_r3_4111 = this->unkF8;
            if (temp_r3_4111 != NULL) {
                sp40 = 0.0f;
                sp38 = 0.0f;
                sp3C = 250.0f * gUpdateTimeDelta;
                sp628 = temp_r3_4111->unk10;
                sp238 = (f64) sp38;
                sp630 = temp_r3_4111->unk18;
                sp240 = (f64) sp40;
                sp628 += sp238;
                temp_r3_4111->unk10 = sp628;
                sp630 = (f32) sp630 + (f32) sp240;
                temp_r3_4111->unk18 = (f64) sp630;
                temp_r3_4141 = temp_r3_4111->unk3C;
                if (temp_r3_4141 != NULL) {
                    M2C_FIELD(temp_r3_4141, f64 *, 0x10) = sp628;
                    M2C_FIELD(temp_r3_4141, f64 *, 0x18) = (f64) sp630;
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
    ManagedLight *temp_r3_4241;
    ManagedLight *temp_r3_4261;
    ManagedLight *temp_r4_4235;
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
    this->unkF8 = gb.unk80->AllocManagedLight(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), *((MKVector4 *) &sp58), 300.0f, lit_780, lit_781);
    temp_r4_4235 = this->unkF8;
    if (temp_r4_4235 != NULL) {
        gb.unk80->EnableLight(temp_r4_4235, 0U);
        temp_r3_4241 = this->unkF8;
        temp_r3_4241->unk38 = 2000.0f;
        temp_r3_4244 = temp_r3_4241->unk3C;
        if (temp_r3_4244 != NULL) {
            M2C_FIELD(temp_r3_4244, f32 *, 0x20) = 2000.0f;
            M2C_FIELD(temp_r3_4244, f32 *, 0x24) = 4000000.0f;
            M2C_FIELD(temp_r3_4244, f32 *, 0x28) = 0.0005f;
            M2C_FIELD(temp_r3_4244, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_4244, f32 *, 0x24));
        }
        sp8 = 1.0f;
        temp_r3_4261 = this->unkF8;
        spC = 0.0f;
        sp10 = 0.75f;
        sp14 = 1.0f;
        temp_r3_4261->unk20 = (f64) sp8;
        temp_r3_4261->unk28 = (f64) sp10;
        temp_r3_4269 = temp_r3_4261->unk3C;
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

#if 0 // DRAFT: illegal implicit conversion from 'KDEnvParticleSystem *' to
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
    M2C_FIELD(this, f32 *, 0xD0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD4) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD8) = 0.0f;
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
    this->unkF8 = NULL;
    this->unkFC.Init(1.0f, 7.0f);
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
    M2C_STRUCT_COPY((s32) (this + 0x19C) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_4401 = &this->unk1A0;
    temp_r3_4401->RotateYaw(temp_r3_4401, 0.3926991f);
    this->unk170.unk10 = 450.0f;
    this->unk1E0 = MKModel_Create("FX0035_Head", NULL, 2, NULL);
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

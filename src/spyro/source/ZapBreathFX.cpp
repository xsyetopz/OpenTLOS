#include "spyro/source/ZapBreathFX.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/ElectricBeamFX.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/FuryFXElectricity.h"
#include "spyro/source/FuryFXElectricity2.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ShapedTrailFX.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapArcFX.h"
#include "spyro/source/ZapCage.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_Emergency14;
extern s32 GS_SpyBreathEnergyHit;
extern s32 GS_SpyBreathEnergyball;
extern s32 GS_SpyroSpare1;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_781 = 0;
static u8 lit_782 = 0;

static s32 lit_786 = 0;
static u8 lit_787 = 0;

static s32 lit_933 = 0;
static u8 lit_934 = 1;

static s32 lit_938 = 1;
static u8 lit_939 = 0;
static s32 lit_951 = -1;
static s32 lit_952 = 8;

static s32 lit_955 = 1;
static u8 lit_956 = 0;

static u8 lit_1495 = 0;

static u8 lit_1549 = 1;
static u8 lit_1631 = 1;

#if 0 // DRAFT: pointer/array required
void ZapBreathFX::ResetFury() {
    this->unk9EC->ResetFury();
    ((FuryFXElectricity2 *) (M2C_BITWISE(FuryFXElectricity2 *, this->unk9F0)))->ResetFury();
}
#endif

#if 0 // DRAFT: undefined identifier 'EndTrail'
void ZapBreathFX::ButtonReleased() {
    this->unk9F8->EndTrail();
    this->unk9FC->EndTrail();
    this->unkD4 = 0.0f;
    this->unkA00 = 0.0f;
    this->unkA04 = 0.0f;
}
#endif

#if 0 // DRAFT: illegal type
u8 ZapBreathFX::LightActiveOnMissiles() {
    s32 var_ctr_93;
    s32 var_r4_92;
    void *temp_r5_96;

    var_r4_92 = 0;
    var_ctr_93 = 0xA;
loop_1:
    temp_r5_96 = this->unkAC + var_r4_92;
    if (((u8) M2C_FIELD(temp_r5_96, u8 *, 0x60) != 0) && ((u32) M2C_FIELD(temp_r5_96, u32 *, 0x5C) != 0U)) {
        return 1U;
    }
    var_r4_92 += 0x90;
    var_ctr_93 -= 1;
    if (var_ctr_93 == 0) {
        return 0U;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal type
void ZapBreathFX::DisableMissileLight(ZapMissile *arg0) {
    s32 var_ctr_118;
    s32 var_r5_115;
    void *temp_r7_121;

    var_r5_115 = 0;
    var_ctr_118 = 0xA;
    do {
        temp_r7_121 = this->unkAC + var_r5_115;
        if (((u8) M2C_FIELD(temp_r7_121, u8 *, 0x60) != 0) && (temp_r7_121 != arg0) && ((u32) M2C_FIELD(temp_r7_121, u32 *, 0x5C) != 0U)) {
            M2C_FIELD(temp_r7_121, u32 *, 0x5C) = 0U;
        }
        var_r5_115 += 0x90;
        var_ctr_118 -= 1;
    } while (var_ctr_118 != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
u8 ZapBreathFX::ShootZapMissile(const MKVector3 &arg0, const MKVector3 &arg1) {
    u8 sp1B0;
    s32 sp1AC;
    void *sp1A8;
    s32 sp1A4;
    f32 sp1A0;
    s32 sp19C;
    s8 sp19B;
    s8 sp19A;
    s16 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    s8 sp158;
    f64 sp150;
    f64 sp148;
    s32 sp144;
    s32 sp140;
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    M2C_UNK sp80;
    f32 sp78;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    Enemy *temp_r24_393;
    TargetManager ***var_r29_159;
    TargetManager **temp_r31_429;
    TargetManager **var_r30_157;
    f32 temp_f29_455;
    f32 temp_f2_300;
    f32 temp_f30_450;
    f32 temp_f4_301;
    f32 temp_f5_298;
    f32 var_f29_153;
    f32 var_f30_222;
    f32 var_f3_289;
    f64 temp_f0_549;
    f64 temp_f1_228;
    f64 temp_f1_234;
    f64 temp_f1_238;
    f64 temp_f1_548;
    f64 temp_f2_484;
    s32 temp_r3_257;
    s32 var_ctr_435;
    s32 var_r0_267;
    s32 var_r29_434;
    u32 var_r24_364;
    u8 temp_r25_358;
    void **temp_r3_538;
    void *temp_r3_197;
    void *temp_r3_487;
    void *temp_r3_502;
    void *temp_r3_533;
    void *temp_r3_550;
    void *temp_r3_579;
    void *temp_r3_583;
    void *temp_r4_438;
    void *temp_r4_521;
    void *temp_r4_545;
    void *temp_r6_513;

    var_f29_153 = 3.4028235e38f;
    var_r30_157 = NULL;
    var_r29_159 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_46:
    if (var_r29_159 != NULL) {
        temp_r31_429 = *var_r29_159;
        if (temp_r31_429 != NULL) {
            if (((*temp_r31_429)->unk8.unk0(temp_r31_429) != NULL) && (M2C_FIELD(*temp_r31_429, u8 (**)(TargetManager **), 0x18)(temp_r31_429) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r31_429)->unk8.unk4)(temp_r31_429) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r31_429)->unk8.unk4)(temp_r31_429)))->IsActive() != 0))) {
                temp_r3_197 = (*temp_r31_429)->unk8.unk0(temp_r31_429)->unk8;
                sp110 = M2C_FIELD(temp_r3_197, f64 *, 0x30);
                sp118 = M2C_FIELD(temp_r3_197, f64 *, 0x38);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp130 = sp70;
                sp78 = (f32) sp118 - arg0.unk8;
                sp138 = (f64) sp78;
                var_f30_222 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + (unksp134 * unksp134));
                if (var_f30_222 > 0.000001f) {
                    if (var_f30_222 > 0.0f) {
                        temp_f1_228 = __frsqrte(var_f30_222);
                        temp_f1_234 = 0.5 * temp_f1_228 * -(((f64) var_f30_222 * (temp_f1_228 * temp_f1_228)) - 3.0);
                        temp_f1_238 = 0.5 * temp_f1_234 * -(((f64) var_f30_222 * (temp_f1_234 * temp_f1_234)) - 3.0);
                        var_f30_222 = (f32) ((f64) var_f30_222 * (0.5 * temp_f1_238 * -(((f64) var_f30_222 * (temp_f1_238 * temp_f1_238)) - 3.0)));
                    } else if (var_f30_222 < M2C_BITWISE(f32, 0.0)) {
                        var_f30_222 = __float_nan;
                    } else {
                        sp8 = var_f30_222;
                        temp_r3_257 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_257) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_267 = 1;
                            } else {
                                var_r0_267 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_267 = 5;
                            } else {
                                var_r0_267 = 3;
                            }
                            break;
                        default:
                            var_r0_267 = 4;
                            break;
                        }
                        if (var_r0_267 == 1) {
                            var_f30_222 = __float_nan;
                        }
                    }
                    var_f3_289 = 1.0f / var_f30_222;
                } else {
                    var_f3_289 = 0.0f;
                    var_f30_222 = 0.0f;
                }
                temp_f5_298 = (f32) sp130 * var_f3_289;
                temp_f2_300 = unksp134 * var_f3_289;
                temp_f4_301 = (f32) sp138 * var_f3_289;
                sp130 = temp_f5_298;
                unksp134 = temp_f2_300;
                sp138 = temp_f4_301;
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((var_f30_222 == 5000.0f) && (var_f30_222 < var_f29_153) && (((temp_f4_301 * arg1.unk8) + ((temp_f5_298 * arg1.unk0) + (temp_f2_300 * arg1.unk4))) > 0.0f)) {
                    sp160 = 0.0f;
                    sp164 = 0.0f;
                    sp168 = 0.0f;
                    sp170 = 0.0f;
                    sp174 = 0.0f;
                    sp178 = 0.0f;
                    sp180 = 0.0f;
                    sp184 = 0.0f;
                    sp188 = 0.0f;
                    sp18C = 1.0f;
                    sp190 = 0.0f;
                    sp194 = 0.0f;
                    sp198 = 0;
                    sp19A = 0;
                    sp19B = 0;
                    sp19C = 0;
                    sp1A0 = 3.4028235e38f;
                    sp1A4 = 0;
                    sp1A8 = NULL;
                    sp1AC = -1;
                    sp1B0 = 0;
                    M2C_FIELD(*temp_r31_429, M2C_UNK (**)(TargetManager **, MKVector3 *, MKVector3 *, M2C_UNK, f32), 0x2C)(temp_r31_429, &arg0, &sp120, 0, 1.0f);
                    temp_r25_358 = MKCollision_RayCollide(arg0, sp120, (MKCollisionResult *) &sp160, (MKCollisionMode) 1, 0x04000000);
                    if ((sp1B0 != 0) && (sp1A8 != NULL) && (var_r24_364 = M2C_FIELD(sp1A8, u32 *, 8), ((var_r24_364 == 0U) == 0))) {

                    } else {
                        var_r24_364 = 0U;
                    }
                    if (((temp_r25_358 != 0) && (var_r24_364 == (*temp_r31_429)->unk8.unk0(temp_r31_429))) || (temp_r25_358 == 0)) {
                        if (var_r30_157 != NULL) {
                            temp_r24_393 = ((Enemy *(*)(TargetManager **)) (*temp_r31_429)->unk8.unk4)(temp_r31_429);
                            if (((MKRand_Int(&gViewSeed, 0, 3) == 0) || ((temp_r24_393 != NULL) && (temp_r24_393->IsKnockedUp() != 0))) && (var_f29_153 = var_f30_222, var_r30_157 = temp_r31_429, ((MKRand_Int(&gViewSeed, 0, 3) == 0) != 0)) && (temp_r24_393 != NULL)) {
                                if (temp_r24_393->IsKnockedUp() == 0) {
                                    goto block_45;
                                }
                            } else {
                                goto block_45;
                            }
                        } else {
                            var_r30_157 = temp_r31_429;
                            var_f29_153 = var_f30_222;
                            goto block_45;
                        }
                    } else {
                        goto block_45;
                    }
                } else {
                    goto block_45;
                }
            } else {
block_45:
                var_r29_159 += 4;
                goto loop_46;
            }
        }
    }
    var_r29_434 = 0;
    var_ctr_435 = 0xA;
loop_49:
    temp_r4_438 = this->unkAC + var_r29_434;
    if ((u8) M2C_FIELD(temp_r4_438, u8 *, 0x60) == 0) {
        M2C_FIELD(temp_r4_438, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r4_438, f64 *, 8) = (f64) M2C_FIELD(&arg0, f32 *, 8);
        temp_f30_450 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f29_455 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
        sp40 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        sp44 = temp_f29_455;
        sp48 = temp_f30_450;
        spE0 = (f64) sp40;
        spE8 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spF0 = sp30;
        sp38 = arg1.unk8 + (f32) spE8;
        spF8 = (f64) sp38;
        Normalise(sp100);
        temp_f2_484 = M2C_BITWISE(f64, sp100);
        temp_r3_487 = this->unkAC + (var_r29_434 + 0x10);
        M2C_FIELD(temp_r3_487, f64 *, 0) = temp_f2_484;
        M2C_FIELD(temp_r3_487, f64 *, 8) = (f64) sp100.unk8;
        M2C_FIELD((this->unkAC + var_r29_434), f32 *, 0x40) = 4.0f;
        M2C_FIELD((this->unkAC + var_r29_434), TargetManager ***, 0x50) = var_r30_157;
        M2C_FIELD((this->unkAC + var_r29_434), s8 *, 0x60) = 1;
        temp_r3_502 = M2C_FIELD((this->unkAC + var_r29_434), void **, 0x54);
        M2C_FIELD(M2C_FIELD(temp_r3_502, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, f64, f64), 0x20)(temp_r3_502, 1, (f64) sp100.unk8, temp_f2_484);
        temp_r6_513 = M2C_FIELD((this->unkAC + var_r29_434), void **, 0x54);
        M2C_FIELD(temp_r6_513, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r6_513, u8 *, 0xA0) & ~0x80) | ((lit_1631 << 7) & 0x80));
        temp_r4_521 = M2C_FIELD((this->unkAC + var_r29_434), void **, 0x54);
        M2C_FIELD(temp_r4_521, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_521, u8 *, 0xA0) | 0x40);
        M2C_FIELD((this->unkAC + var_r29_434), ManagedLight **, 0x5C) = (ManagedLight *) this->unkB0;
        M2C_FIELD((this->unkAC + var_r29_434), f32 *, 0x4C) = 0.5f;
        temp_r3_533 = this->unkAC + (var_r29_434 + 0x20);
        M2C_FIELD(temp_r3_533, f64 *, 0) = (f64) M2C_FIELD(&arg1, f32 *, 0);
        M2C_FIELD(temp_r3_533, f64 *, 8) = (f64) M2C_FIELD(&arg1, f32 *, 8);
        temp_r3_538 = M2C_FIELD((this->unkAC + var_r29_434), void ***, 0x50);
        if (temp_r3_538 != NULL) {
            temp_r4_545 = M2C_FIELD(M2C_FIELD(*temp_r3_538, void *(**)(), 8)(), void **, 8);
            temp_f1_548 = M2C_FIELD(temp_r4_545, f64 *, 0x30);
            temp_f0_549 = M2C_FIELD(temp_r4_545, f64 *, 0x38);
            temp_r3_550 = this->unkAC + (var_r29_434 + 0x30);
            spD0 = temp_f1_548;
            M2C_FIELD(temp_r3_550, f64 *, 0) = temp_f1_548;
            spD8 = temp_f0_549;
            M2C_FIELD(temp_r3_550, f64 *, 8) = temp_f0_549;
        }
        DisableMissileLight(this->unkAC + var_r29_434);
        if ((u32) M2C_FIELD((this->unkAC + var_r29_434), u32 *, 0x5C) != 0U) {
            sp20 = 1.0f;
            sp24 = 1.0f;
            sp28 = 0.0f;
            sp2C = 1.0f;
            this->unkE8 = (f64) sp20;
            this->unkF0 = (f64) sp28;
            temp_r3_579 = M2C_FIELD((this->unkAC + var_r29_434), void **, 0x5C);
            spC0 = (f64) sp20;
            M2C_FIELD(temp_r3_579, f64 *, 0x20) = (f64) this->unkE8;
            M2C_FIELD(temp_r3_579, f64 *, 0x28) = (f64) this->unkF0;
            temp_r3_583 = M2C_FIELD(temp_r3_579, void **, 0x3C);
            spC8 = (f64) sp28;
            if (temp_r3_583 != NULL) {
                M2C_FIELD(temp_r3_583, f64 *, 0) = (f64) this->unkE8;
                M2C_FIELD(temp_r3_583, f64 *, 8) = (f64) this->unkF0;
            }
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(M2C_FIELD((this->unkAC + var_r29_434), ManagedLight **, 0x5C), 1U);
        }
        sp50 = 1.0f;
        sp54 = 1.0f;
        sp68 = 0.0f;
        sp58 = 1.0f;
        sp5C = 1.0f;
        sp60 = 0.0f;
        sp64 = 0.0f;
        spA0 = (f64) sp50;
        spA8 = (f64) sp58;
        spB0 = (f64) sp60;
        spB8 = (f64) sp68;
        this->unkCC->Emit(arg0, *((MKVector3 *) &spB0), 5.0f, (MKVector4) &spA0);
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            sp144 = 0;
            MKVector(1.0f, 1.0f, 1.0f);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp140 = 0x417;
            sp148 = sp10;
            sp18 = sp88 * 50.0f;
            sp158 = 1;
            sp150 = (f64) sp18;
            sp90 = sp10;
            sp98 = (f64) sp18;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp140, sp10);
        }
        return 1U;
    }
    var_r29_434 += 0x90;
    var_ctr_435 -= 1;
    if (var_ctr_435 == 0) {
        return 0U;
    }
    goto loop_49;
}
#endif

#if 0 // DRAFT: illegal type
void ZapBreathFX::UpdateZapMissiles() {
    Enemy *temp_r3_1165;
    MKVector3 *temp_r8_738;
    ManagedLight *temp_r4_778;
    ZapCage *temp_r3_1176;
    f32 temp_f0_1288;
    f32 temp_f0_1583;
    f32 temp_f1_1541;
    f32 temp_f1_1784;
    f32 temp_f1_1831;
    f32 temp_f1_848;
    f32 temp_f22_1321;
    f32 temp_f22_1498;
    f32 temp_f23_1316;
    f32 temp_f23_1503;
    f32 temp_f24_1712;
    f32 temp_f24_1758;
    f32 temp_f24_1811;
    f32 temp_f24_822;
    f32 temp_f25_1707;
    f32 temp_f25_1753;
    f32 temp_f25_1816;
    f32 temp_f25_817;
    f32 temp_f29_1393;
    f32 var_f25_953;
    f32 var_f2_1383;
    f32 var_f2_899;
    f32 var_f3_1918;
    f32 var_f4_1078;
    f32 var_f6_1072;
    f32 var_f6_1844;
    f64 temp_f0_891;
    f64 temp_f1_1080;
    f64 temp_f1_1086;
    f64 temp_f1_1090;
    f64 temp_f1_1200;
    f64 temp_f1_1857;
    f64 temp_f1_1863;
    f64 temp_f1_1867;
    f64 temp_f1_890;
    f64 temp_f1_958;
    f64 temp_f1_964;
    f64 temp_f1_968;
    s32 temp_r0_1693;
    s32 temp_r3_1109;
    s32 temp_r3_1886;
    s32 temp_r3_987;
    s32 temp_r4_1052;
    s32 temp_r5_1648;
    s32 temp_r6_764;
    s32 var_r0_1119;
    s32 var_r0_1896;
    s32 var_r0_997;
    s32 var_r25_1310;
    s32 var_r25_1491;
    s32 var_r26_810;
    s32 var_r27_718;
    s32 var_r29_717;
    u32 var_r0_1469;
    void **temp_r3_1161;
    void **temp_r3_1185;
    void **temp_r3_1205;
    void **temp_r3_1224;
    void **temp_r3_1240;
    void **temp_r3_880;
    void *temp_r25_1273;
    void *temp_r25_1568;
    void *temp_r26_1038;
    void *temp_r26_1246;
    void *temp_r26_745;
    void *temp_r3_1055;
    void *temp_r3_1066;
    void *temp_r3_1199;
    void *temp_r3_1264;
    void *temp_r3_1268;
    void *temp_r3_1368;
    void *temp_r3_1374;
    void *temp_r3_1561;
    void *temp_r3_1565;
    void *temp_r3_1620;
    void *temp_r3_1631;
    void *temp_r3_1682;
    void *temp_r3_1692;
    void *temp_r3_723;
    void *temp_r3_758;
    void *temp_r3_889;
    void *temp_r3_933;
    void *temp_r4_1274;
    void *temp_r4_1632;
    void *temp_r4_1639;
    void *temp_r4_1649;
    void *temp_r4_1663;
    void *temp_r4_1681;
    void *temp_r4_773;
    void *temp_r4_871;
    void *temp_r4_887;
    void *temp_r5_1394;
    void *temp_r7_767;
    void *temp_r9_1415;
    var_r29_717 = 0;
    var_r27_718 = 0;
    this->unkD0 -= gUpdateTimeDelta;
    do {
        temp_r3_723 = this->unkAC + var_r27_718;
        if ((u8) M2C_FIELD(temp_r3_723, u8 *, 0x60) != 0) {
            M2C_FIELD(temp_r3_723, f32 *, 0x40) = (f32) (M2C_FIELD(temp_r3_723, f32 *, 0x40) - gUpdateTimeDelta);
            arg_sp8 = 1;
            temp_r8_738 = this->unkAC + var_r27_718;
            ((KDSoundFader *) (temp_r8_738 + 0x64))->Update(GS_SpyroSpare1, 1U, M2C_FIELD(temp_r8_738, u8 *, 0x60), NULL, temp_r8_738, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            temp_r26_745 = this->unkAC + var_r27_718;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r26_745, f32 *, 0x40) == 0.0f) {
                M2C_FIELD(temp_r26_745, s8 *, 0x60) = 0;
                KDSound_Stop(this->unkAC + (var_r27_718 + 0x64));
                temp_r3_758 = *(this->unkAC + (var_r27_718 + 0x54));
                M2C_FIELD(M2C_FIELD(temp_r3_758, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_758);
                temp_r6_764 = var_r27_718 + 0x54;
                temp_r7_767 = *(this->unkAC + temp_r6_764);
                M2C_FIELD(temp_r7_767, u8 *, 0xA0) = (u8) ((M2C_FIELD(temp_r7_767, u8 *, 0xA0) & ~0x80) | ((lit_1495 << 7) & 0x80));
                temp_r4_773 = *(this->unkAC + temp_r6_764);
                M2C_FIELD(temp_r4_773, u8 *, 0xA0) = (u8) (M2C_FIELD(temp_r4_773, u8 *, 0xA0) & ~0x40);
                temp_r4_778 = *(this->unkAC + (var_r27_718 + 0x5C));
                if (temp_r4_778 != NULL) {
                    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_778, 0U);
                }
                arg_sp1D0 = 1.0f;
                arg_sp1D4 = 1.0f;
                arg_sp1E8 = 0.0f;
                arg_sp1D8 = 1.0f;
                arg_sp1DC = 1.0f;
                arg_sp1E0 = 0.0f;
                arg_sp1E4 = 0.0f;
                arg_sp3B0 = (f64) arg_sp1D0;
                arg_sp3B8 = (f64) arg_sp1D8;
                arg_sp3C0 = (f64) arg_sp1E0;
                arg_sp3C8 = (f64) arg_sp1E8;
                this->unkCC->Emit(*(this->unkAC + var_r27_718), *((MKVector3 *) &arg_sp3C0), 50.0f, (MKVector4) &arg_sp3B0);
                var_r26_810 = 0;
                do {
                    temp_f25_817 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f24_822 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_sp1C0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_sp1C4 = temp_f24_822;
                    arg_sp1C8 = temp_f25_817;
                    arg_sp390 = (f64) arg_sp1C0;
                    arg_sp398 = (f64) arg_sp1C8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp3A0 = arg_sp1B0;
                    arg_sp1B8 = (f32) arg_sp398 * 1000.0f;
                    arg_sp3A8 = (f64) arg_sp1B8;
                    temp_f1_848 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
                    arg_sp1A0 = 1.0f;
                    arg_sp1A4 = 1.0f;
                    arg_sp28 = temp_f1_848;
                    arg_sp1A8 = 0.4f;
                    arg_sp1AC = 1.0f;
                    arg_sp380 = (f64) arg_sp1A0;
                    arg_sp388 = (f64) arg_sp1A8;
                    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*(this->unkAC + var_r27_718), *((MKVector3 *) &arg_sp3A0), arg_sp28, *((MKVector4 *) &arg_sp380), -1979.9999f);
                    var_r26_810 += 1;
                } while (var_r26_810 < 0xA);
                temp_r4_871 = *(this->unkAC + (var_r27_718 + 0x58));
                if (temp_r4_871 != NULL) {
                    M2C_FIELD(temp_r4_871, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_871, u8 *, 0x31) & ~0x40);
                }
            } else {
                temp_r3_880 = M2C_FIELD(temp_r26_745, void ***, 0x50);
                if (temp_r3_880 != NULL) {
                    temp_r4_887 = M2C_FIELD(M2C_FIELD(*temp_r3_880, void *(**)(), 8)(), void **, 8);
                    temp_r3_889 = this->unkAC;
                    temp_f1_890 = M2C_FIELD(temp_r4_887, f64 *, 0x30);
                    temp_f0_891 = M2C_FIELD(temp_r4_887, f64 *, 0x38);
                    arg_sp420 = temp_f1_890;
                    arg_sp428 = temp_f0_891;
                    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r5, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f8, $f2 */);
                    var_f2_899 = 0.0f;
                    arg_sp188 = 0.0f;
                    arg_sp180 = 0.0f;
                    arg_sp184 = 100.0f;
                    arg_sp198 = (f32) arg_sp428 - M2C_FIELD((temp_r3_889 + (var_r27_718 + 0x30)), f32 *, 8);
                    arg_sp370 = (f64) arg_sp180;
                    arg_sp410 = arg_sp190;
                    arg_sp418 = (f64) arg_sp198;
                    arg_sp378 = (f64) arg_sp188;
                    M2C_ERROR(/* unknown instruction: ps_add $f3, $f8, $f3 */);
                    arg_sp400 = arg_sp170;
                    arg_sp178 = (f32) arg_sp428 + (f32) arg_sp378;
                    arg_sp408 = (f64) arg_sp178;
                    M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r4, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f3, $f4, $f3 */);
                    temp_r3_933 = temp_r3_889 + (var_r27_718 + 0x30);
                    arg_sp430 = arg_sp70;
                    arg_sp78 = (f32) arg_sp408 - M2C_FIELD((temp_r3_889 + var_r27_718), f32 *, 8);
                    arg_sp360 = arg_sp70;
                    arg_sp438 = (f64) arg_sp78;
                    M2C_FIELD(temp_r3_933, f64 *, 0) = temp_f1_890;
                    M2C_FIELD(temp_r3_933, f64 *, 8) = temp_f0_891;
                    arg_sp368 = (f64) arg_sp78;
                    var_f25_953 = ((f32) arg_sp438 * (f32) arg_sp438) + (((f32) arg_sp430 * (f32) arg_sp430) + (arg_sp434 * arg_sp434));
                    if (var_f25_953 > 0.000001f) {
                        if (var_f25_953 > 0.0f) {
                            temp_f1_958 = __frsqrte(var_f25_953);
                            temp_f1_964 = 0.5 * temp_f1_958 * -(((f64) var_f25_953 * (temp_f1_958 * temp_f1_958)) - 3.0);
                            temp_f1_968 = 0.5 * temp_f1_964 * -(((f64) var_f25_953 * (temp_f1_964 * temp_f1_964)) - 3.0);
                            var_f25_953 = (f32) ((f64) var_f25_953 * (0.5 * temp_f1_968 * -(((f64) var_f25_953 * (temp_f1_968 * temp_f1_968)) - 3.0)));
                        } else if (var_f25_953 < M2C_BITWISE(f32, 0.0)) {
                            var_f25_953 = __float_nan;
                        } else {
                            arg_sp18 = var_f25_953;
                            temp_r3_987 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                            switch (temp_r3_987) {  /* switch 1; irregular */
                            case 0x7F800000:        /* switch 1 */
                                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                    var_r0_997 = 1;
                                } else {
                                    var_r0_997 = 2;
                                }
                                break;
                            case 0x0:               /* switch 1 */
                                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                    var_r0_997 = 5;
                                } else {
                                    var_r0_997 = 3;
                                }
                                break;
                            default:                /* switch 1 */
                                var_r0_997 = 4;
                                break;
                            }
                            if (var_r0_997 == 1) {
                                var_f25_953 = __float_nan;
                            }
                        }
                        var_f2_899 = 1.0f / var_f25_953;
                    } else {
                        var_f25_953 = 0.0f;
                    }
                    arg_sp430 = (f32) arg_sp430 * var_f2_899;
                    arg_sp434 *= var_f2_899;
                    arg_sp438 = (f32) arg_sp438 * var_f2_899;
                    if (var_f25_953 > 5.0f) {
                        temp_r26_1038 = this->unkAC + var_r27_718;
                        Normalise(*((MKVector3 *) &arg_sp340));
                        KDMath_Slerp(*((MKVector3 *) &arg_sp350), *((MKVector3 *) &arg_sp340), 0.5f * -((M2C_FIELD(temp_r26_1038, f32 *, 0x40) * 0.25f) - 1.0f));
                        temp_r4_1052 = var_r27_718 + 0x10;
                        temp_r3_1055 = this->unkAC + temp_r4_1052;
                        M2C_FIELD(temp_r3_1055, f64 *, 0) = arg_sp350;
                        M2C_FIELD(temp_r3_1055, f64 *, 8) = arg_sp358;
                        temp_r3_1066 = this->unkAC + temp_r4_1052;
                        var_f6_1072 = ((f32) arg_sp418 * (f32) arg_sp418) + (((f32) arg_sp410 * (f32) arg_sp410) + (arg_sp414 * arg_sp414));
                        var_f4_1078 = ((f32) arg_sp438 * M2C_FIELD(temp_r3_1066, f32 *, 8)) + (((f32) arg_sp430 * M2C_FIELD(temp_r3_1066, f32 *, 0)) + (arg_sp434 * M2C_FIELD(temp_r3_1066, f32 *, 4)));
                        if (var_f6_1072 > 0.0f) {
                            temp_f1_1080 = __frsqrte(var_f6_1072);
                            temp_f1_1086 = 0.5 * temp_f1_1080 * -(((f64) var_f6_1072 * (temp_f1_1080 * temp_f1_1080)) - 3.0);
                            temp_f1_1090 = 0.5 * temp_f1_1086 * -(((f64) var_f6_1072 * (temp_f1_1086 * temp_f1_1086)) - 3.0);
                            var_f6_1072 = (f32) ((f64) var_f6_1072 * (0.5 * temp_f1_1090 * -(((f64) var_f6_1072 * (temp_f1_1090 * temp_f1_1090)) - 3.0)));
                        } else if (var_f6_1072 < M2C_BITWISE(f32, 0.0)) {
                            var_f6_1072 = __float_nan;
                        } else {
                            arg_sp14 = var_f6_1072;
                            temp_r3_1109 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                            switch (temp_r3_1109) { /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_1119 = 1;
                                } else {
                                    var_r0_1119 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                    var_r0_1119 = 5;
                                } else {
                                    var_r0_1119 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_1119 = 4;
                                break;
                            }
                            if (var_r0_1119 == 1) {
                                var_f6_1072 = __float_nan;
                            }
                        }
                        if (var_f4_1078 < 0.0f) {
                            var_f4_1078 = -var_f4_1078;
                        }
                        *(this->unkAC + (var_r27_718 + 0x48)) = (1.0f + (var_f6_1072 / 50.0f)) * (0.25f + var_f4_1078);
                    }
                    if (var_f25_953 < 300.0f) {
                        temp_r3_1161 = *(this->unkAC + (var_r27_718 + 0x50));
                        temp_r3_1165 = M2C_FIELD(*temp_r3_1161, Enemy *(**)(void **), 0xC)(temp_r3_1161);
                        if ((temp_r3_1165 != NULL) && (temp_r3_1165->IsKnockedUp() != 0) && !(((u8) M2C_FIELD(temp_r3_1165, u8 *, 0xB02) >> 6U) & 1)) {
                            temp_r3_1176 = checked_cast<ZapCage *, MKProp>(this->unkFC->CreateInstance());
                            if (temp_r3_1176 != NULL) {
                                M2C_FIELD(temp_r3_1176->__vptr, M2C_UNK (**)(), 0x30)();
                                temp_r3_1185 = *(this->unkAC + (var_r27_718 + 0x50));
                                temp_r3_1176->Trigger(M2C_FIELD(*temp_r3_1185, MKProp *(**)(void **), 8)(temp_r3_1185), 3.0f);
                            }
                        }
                        M2C_FIELD(this, u8 *, 0x1B0) = 0U;
                        temp_r3_1199 = this->unkAC + var_r27_718;
                        temp_f1_1200 = M2C_FIELD(temp_r3_1199, f64 *, 0);
                        M2C_FIELD(this, f64 *, 0x170) = temp_f1_1200;
                        M2C_FIELD(this, f64 *, 0x178) = (f64) M2C_FIELD(temp_r3_1199, f64 *, 8);
                        temp_r3_1205 = *(this->unkAC + (var_r27_718 + 0x50));
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(*temp_r3_1205, void *(**)(void **, f64), 8)(temp_r3_1205, temp_f1_1200), void **, 0x44), M2C_UNK (**)(M2C_UNK *), 0x2C)(&this->unk160);
                        *(this->unkAC + (var_r27_718 + 0x40)) = 0.0f;
                        if ((u8) M2C_FIELD(this, u8 *, 0x1B0) != 0) {
                            temp_r3_1224 = *(this->unkAC + (var_r27_718 + 0x50));
                            KDSound_Play3d(GS_SpyBreathEnergyHit, M2C_FIELD(M2C_FIELD(*temp_r3_1224, void *(**)(void **), 8)(temp_r3_1224), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
                            temp_r3_1240 = *(this->unkAC + (var_r27_718 + 0x50));
                            temp_r26_1246 = M2C_FIELD(*temp_r3_1240, void *(**)(void **), 8)(temp_r3_1240);
                            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **, M2C_UNK *), 0x40)(M2C_FIELD(&gb, void ***, 0), &gb)))->RumblePlay3D(0.2f, 0.5f, 0.05f, M2C_FIELD(temp_r26_1246, s32 *, 8) + 0x30, 50.0f, 0, 4.0f, 0U);
                        }
                        temp_r3_1264 = M2C_FIELD(this, void **, 0x9E8);
                        temp_r3_1268 = M2C_FIELD(M2C_FIELD(temp_r3_1264, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1264);
                        if (temp_r3_1268 != NULL) {
                            temp_r25_1273 = M2C_FIELD(temp_r3_1268, void **, 0x2C);
                            temp_r4_1274 = this->unkAC + var_r27_718;
                            M2C_FIELD(temp_r3_1268, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1274, f64 *, 0);
                            M2C_FIELD(temp_r3_1268, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1274, f64 *, 8);
                            M2C_FIELD(temp_r3_1268, f32 *, 0x20) = 0.0f;
                            M2C_FIELD(temp_r3_1268, f32 *, 0x28) = 0.0f;
                            temp_f0_1288 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            arg_sp60 = 0.0f;
                            arg_sp68 = 0.0f;
                            arg_sp64 = 0.0f;
                            M2C_FIELD(temp_r3_1268, f32 *, 0x24) = (f32) (2.0f * temp_f0_1288);
                            M2C_FIELD(temp_r25_1273, f64 *, 0) = (f64) arg_sp60;
                            arg_sp330 = (f64) arg_sp60;
                            arg_sp338 = (f64) arg_sp68;
                            M2C_FIELD(temp_r25_1273, f64 *, 8) = (f64) arg_sp68;
                            M2C_FIELD(temp_r25_1273, f32 *, 0x18) = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
                            M2C_FIELD(temp_r25_1273, f32 *, 0x10) = 0.0f;
                            M2C_FIELD(temp_r25_1273, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(this, void **, 0x9E8), f32 *, 0xF4);
                        }
                        var_r25_1310 = 0;
                        do {
                            temp_f23_1316 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f22_1321 = MKRand_Float(&gViewSeed, 0.0f, 2.5f);
                            arg_sp160 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            arg_sp164 = temp_f22_1321;
                            arg_sp168 = temp_f23_1316;
                            arg_sp320 = (f64) arg_sp160;
                            arg_sp328 = (f64) arg_sp168;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                            arg_sp3F0 = arg_sp150;
                            arg_sp158 = (f32) arg_sp328 * 1000.0f;
                            arg_sp3F8 = (f64) arg_sp158;
                            ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*(this->unkAC + var_r27_718), *((MKVector3 *) &arg_sp3F0), 3.0f, 0U);
                            var_r25_1310 += 1;
                        } while (var_r25_1310 < 0x14);
                    }
                } else {
                    Normalise(*((MKVector3 *) &arg_sp300));
                    KDMath_Slerp(*((MKVector3 *) &arg_sp310), *((MKVector3 *) &arg_sp300), 0.075f);
                    temp_r3_1368 = this->unkAC + (var_r27_718 + 0x10);
                    M2C_FIELD(temp_r3_1368, f64 *, 0) = arg_sp310;
                    M2C_FIELD(temp_r3_1368, f64 *, 8) = arg_sp318;
                    temp_r3_1374 = this->unkAC + var_r27_718;
                    var_f2_1383 = (M2C_FIELD(temp_r3_1374, f32 *, 0x28) * M2C_FIELD(temp_r3_1374, f32 *, 0x18)) + ((M2C_FIELD(temp_r3_1374, f32 *, 0x20) * M2C_FIELD(temp_r3_1374, f32 *, 0x10)) + (M2C_FIELD(temp_r3_1374, f32 *, 0x24) * M2C_FIELD(temp_r3_1374, f32 *, 0x14)));
                    if (var_f2_1383 < 0.0f) {
                        var_f2_1383 = -var_f2_1383;
                    }
                    M2C_FIELD(temp_r3_1374, f32 *, 0x48) = (f32) (0.25f + var_f2_1383);
                }
                temp_f29_1393 = gUpdateTimeDelta;
                temp_r5_1394 = this->unkAC + var_r27_718;
                arg_sp3E0 = M2C_FIELD(temp_r5_1394, f64 *, 0);
                arg_sp3E8 = M2C_FIELD(temp_r5_1394, f64 *, 8);
                arg_sp2D0.operator*(M2C_FIELD(temp_r5_1394, f32 *, 0x48));
                arg_sp2E0.operator*(6000.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                arg_sp2F0 = arg_sp50;
                temp_r9_1415 = this->unkAC + var_r27_718;
                arg_sp58 = arg_sp2E8 * temp_f29_1393;
                arg_sp2F8 = (f64) arg_sp58;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r9, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r9, 0x0, qr0 */);
                M2C_FIELD(temp_r9_1415, f32 *, 8) = (f32) (M2C_FIELD(temp_r9_1415, f32 *, 8) + (f32) arg_sp2F8);
                arg_sp480 = 0.0f;
                arg_sp484 = 0.0f;
                arg_sp488 = 0.0f;
                arg_sp490 = 0.0f;
                arg_sp494 = 0.0f;
                arg_sp498 = 0.0f;
                arg_sp4A0 = 0.0f;
                arg_sp4A4 = 0.0f;
                arg_sp4A8 = 0.0f;
                arg_sp4AC = 1.0f;
                arg_sp4B0 = 0.0f;
                arg_sp4B4 = 0.0f;
                arg_sp4B8 = 0;
                arg_sp4B8 = 0;
                (s8) arg_sp4B8 = 0;
                arg_sp4BC = 0;
                arg_sp4C0 = 3.4028235e38f;
                arg_sp4C4 = 0;
                arg_sp4C8 = NULL;
                arg_sp4CC = -1;
                arg_sp4D0 = 0U;
                if (MKCollision_RayCollide(*((MKVector3 *) &arg_sp3E0), *(this->unkAC + var_r27_718), (MKCollisionResult *) &arg_sp480, (MKCollisionMode) 1, 0x0C000004) != 0) {
                    if ((arg_sp4D0 != 0) && (arg_sp4C8 != NULL) && (var_r0_1469 = M2C_FIELD(arg_sp4C8, u32 *, 8), ((var_r0_1469 == 0U) == 0))) {

                    } else {
                        var_r0_1469 = 0U;
                    }
                    if (var_r0_1469 == 0U) {
                        this->unk9F8->SpawnScorchMark(*((MKVector3 *) &arg_sp480), *((MKVector3 *) &arg_sp490), 4.0f);
                        KDSound_Play3d(GS_Emergency14, (MKVector3 *) &arg_sp480, 0U, -1, 0.0f, 0U);
                        var_r25_1491 = 0;
                        do {
                            temp_f22_1498 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f23_1503 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
                            arg_sp140 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            arg_sp144 = temp_f23_1503;
                            arg_sp148 = temp_f22_1498;
                            arg_sp2A0 = (f64) arg_sp140;
                            arg_sp2A8 = (f64) arg_sp148;
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            arg_sp2B0 = arg_sp130;
                            arg_sp138 = (f32) arg_sp2A8 + arg_sp498;
                            arg_sp2B8 = (f64) arg_sp138;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                            arg_sp2C0 = arg_sp120;
                            arg_sp128 = (f32) arg_sp2B8 * 800.0f;
                            arg_sp2C8 = (f64) arg_sp128;
                            temp_f1_1541 = MKRand_Float(&gViewSeed, 22.0f, 25.0f);
                            arg_sp110 = 1.0f;
                            arg_sp114 = 1.0f;
                            arg_sp24 = temp_f1_1541;
                            arg_sp118 = 0.4f;
                            arg_sp11C = 1.0f;
                            arg_sp290 = (f64) arg_sp110;
                            arg_sp298 = (f64) arg_sp118;
                            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp480), *((MKVector3 *) &arg_sp2C0), arg_sp24, *((MKVector4 *) &arg_sp290), -1979.9999f);
                            var_r25_1491 += 1;
                        } while (var_r25_1491 < 5);
                        temp_r3_1561 = M2C_FIELD(this, void **, 0x9E8);
                        temp_r3_1565 = M2C_FIELD(M2C_FIELD(temp_r3_1561, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_1561);
                        if (temp_r3_1565 != NULL) {
                            temp_r25_1568 = M2C_FIELD(temp_r3_1565, void **, 0x2C);
                            M2C_FIELD(temp_r3_1565, f64 *, 0) = (f64) arg_sp480;
                            M2C_FIELD(temp_r3_1565, f64 *, 8) = (f64) arg_sp488;
                            M2C_FIELD(temp_r3_1565, f32 *, 0x20) = 0.0f;
                            M2C_FIELD(temp_r3_1565, f32 *, 0x28) = 0.0f;
                            temp_f0_1583 = 3.1415927f * MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            arg_sp40 = 0.0f;
                            arg_sp48 = 0.0f;
                            arg_sp44 = 0.0f;
                            M2C_FIELD(temp_r3_1565, f32 *, 0x24) = (f32) (2.0f * temp_f0_1583);
                            M2C_FIELD(temp_r25_1568, f64 *, 0) = (f64) arg_sp40;
                            arg_sp280 = (f64) arg_sp40;
                            arg_sp288 = (f64) arg_sp48;
                            M2C_FIELD(temp_r25_1568, f64 *, 8) = (f64) arg_sp48;
                            M2C_FIELD(temp_r25_1568, f32 *, 0x18) = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
                            M2C_FIELD(temp_r25_1568, f32 *, 0x10) = 0.0f;
                            M2C_FIELD(temp_r25_1568, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(this, void **, 0x9E8), f32 *, 0xF4);
                        }
                    }
                }
                M2C_STRUCT_COPY((s32) &arg_sp43C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_r3_1620 = this->unkAC + var_r27_718;
                arg_sp470 = M2C_FIELD(temp_r3_1620, f32 *, 0);
                arg_sp474 = M2C_FIELD(temp_r3_1620, f32 *, 4);
                arg_sp478 = M2C_FIELD(temp_r3_1620, f32 *, 8);
                arg_sp47C = 1.0f;
                MKModel_SetWorldMatrix(this->unkE0, *((Matrix *) &arg_sp440));
                temp_r3_1631 = this->unkAC + var_r27_718;
                temp_r4_1632 = M2C_FIELD(temp_r3_1631, void **, 0x5C);
                if (temp_r4_1632 != NULL) {
                    M2C_FIELD(temp_r4_1632, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_1631, f64 *, 0);
                    M2C_FIELD(temp_r4_1632, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_1631, f64 *, 8);
                    temp_r4_1639 = M2C_FIELD(temp_r4_1632, void **, 0x3C);
                    if (temp_r4_1639 != NULL) {
                        M2C_FIELD(temp_r4_1639, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_1631, f64 *, 0);
                        M2C_FIELD(temp_r4_1639, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_1631, f64 *, 8);
                    }
                }
                temp_r5_1648 = var_r27_718 + 0x58;
                temp_r4_1649 = *(this->unkAC + temp_r5_1648);
                if (temp_r4_1649 != NULL) {
                    M2C_FIELD(temp_r4_1649, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_1649, u8 *, 0x31) | 0x40);
                    arg_sp30 = 0.75f;
                    temp_r4_1663 = *(this->unkAC + temp_r5_1648);
                    arg_sp34 = 0.8f;
                    arg_sp38 = 0.0f;
                    arg_sp3C = 1.0f;
                    M2C_FIELD(temp_r4_1663, f64 *, 0x10) = (f64) arg_sp30;
                    arg_sp270 = (f64) arg_sp30;
                    arg_sp278 = (f64) arg_sp38;
                    M2C_FIELD(temp_r4_1663, f64 *, 0x18) = (f64) arg_sp38;
                    M2C_FIELD(*(this->unkAC + (var_r27_718 + 0x58)), f32 *, 0x24) = MKRand_Float(&gViewSeed, 2.0f, 2.5f);
                    temp_r4_1681 = this->unkAC + var_r27_718;
                    temp_r3_1682 = M2C_FIELD(temp_r4_1681, void **, 0x58);
                    M2C_FIELD(temp_r3_1682, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1681, f64 *, 0);
                    M2C_FIELD(temp_r3_1682, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1681, f64 *, 8);
                }
                ((ShapedTrailFX *) (*(this->unkAC + (var_r27_718 + 0x54))))->UpdateTrail();
                temp_r3_1692 = this->unkAC;
                temp_r0_1693 = var_r27_718 + 0x44;
                *(temp_r3_1692 + temp_r0_1693) = *(temp_r3_1692 + temp_r0_1693) - gUpdateTimeDelta;
                if (*(this->unkAC + temp_r0_1693) < 0.0f) {
                    temp_f25_1707 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f24_1712 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_sp100 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_sp104 = temp_f24_1712;
                    arg_sp108 = temp_f25_1707;
                    arg_sp250 = (f64) arg_sp100;
                    arg_sp258 = (f64) arg_sp108;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
                    arg_sp260 = arg_spF0;
                    arg_spF8 = (f32) arg_sp258 * 20.0f;
                    arg_sp268 = (f64) arg_spF8;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    arg_sp3D0 = arg_spE0;
                    arg_spE8 = M2C_FIELD((this->unkAC + var_r27_718), f32 *, 8) + (f32) arg_sp268;
                    arg_sp3D8 = (f64) arg_spE8;
                    temp_f25_1753 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f24_1758 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
                    arg_spD0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_spD4 = temp_f24_1758;
                    arg_spD8 = temp_f25_1753;
                    arg_sp230 = (f64) arg_spD0;
                    arg_sp238 = (f64) arg_spD8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                    arg_sp240 = arg_spC0;
                    arg_spC8 = (f32) arg_sp238 * 600.0f;
                    arg_sp248 = (f64) arg_spC8;
                    temp_f1_1784 = MKRand_Float(&gViewSeed, 7.0f, 8.0f);
                    arg_spB0 = 1.0f;
                    arg_spB4 = 1.0f;
                    arg_sp20 = temp_f1_1784;
                    arg_spB8 = 0.4f;
                    arg_spBC = 1.0f;
                    arg_sp220 = (f64) arg_spB0;
                    arg_sp228 = (f64) arg_spB8;
                    ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp3D0), *((MKVector3 *) &arg_sp240), arg_sp20, *((MKVector4 *) &arg_sp220), -1979.9999f);
                    *(this->unkAC + (var_r27_718 + 0x44)) = 0.075f;
                    temp_f24_1811 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f25_1816 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_spA0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    arg_spA4 = temp_f25_1816;
                    arg_spA8 = temp_f24_1811;
                    arg_sp200 = (f64) arg_spA0;
                    arg_sp208 = (f64) arg_spA8;
                    temp_f1_1831 = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
                    arg_sp90 = 1.0f;
                    arg_sp94 = 1.0f;
                    var_f6_1844 = ((f32) arg_sp208 * (f32) arg_sp208) + (((f32) arg_sp200 * (f32) arg_sp200) + (arg_sp204 * arg_sp204));
                    arg_sp98 = 0.2f;
                    arg_sp9C = 1.0f;
                    arg_sp1C = temp_f1_1831;
                    arg_sp1F0 = (f64) arg_sp90;
                    arg_sp1F8 = (f64) arg_sp98;
                    if (var_f6_1844 > 1e-12f) {
                        if (var_f6_1844 > 0.0f) {
                            temp_f1_1857 = __frsqrte(var_f6_1844);
                            temp_f1_1863 = 0.5 * temp_f1_1857 * -(((f64) var_f6_1844 * (temp_f1_1857 * temp_f1_1857)) - 3.0);
                            temp_f1_1867 = 0.5 * temp_f1_1863 * -(((f64) var_f6_1844 * (temp_f1_1863 * temp_f1_1863)) - 3.0);
                            var_f6_1844 = (f32) ((f64) var_f6_1844 * (0.5 * temp_f1_1867 * -(((f64) var_f6_1844 * (temp_f1_1867 * temp_f1_1867)) - 3.0)));
                        } else if (var_f6_1844 < M2C_BITWISE(f32, 0.0)) {
                            var_f6_1844 = __float_nan;
                        } else {
                            arg_sp10 = var_f6_1844;
                            temp_r3_1886 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                            switch (temp_r3_1886) { /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                    var_r0_1896 = 1;
                                } else {
                                    var_r0_1896 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                    var_r0_1896 = 5;
                                } else {
                                    var_r0_1896 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_1896 = 4;
                                break;
                            }
                            if (var_r0_1896 == 1) {
                                var_f6_1844 = __float_nan;
                            }
                        }
                        var_f3_1918 = 1.0f / var_f6_1844;
                    } else {
                        var_f3_1918 = 0.0f;
                    }
                    arg_sp80 = (f32) arg_sp200 * var_f3_1918;
                    arg_sp84 = arg_sp204 * var_f3_1918;
                    arg_sp88 = (f32) arg_sp208 * var_f3_1918;
                    arg_sp210 = (f64) arg_sp80;
                    arg_sp218 = (f64) arg_sp88;
                    ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &arg_sp3D0), *((MKVector3 *) &arg_sp210), arg_sp1C, lit_1549, (MKVector4) &arg_sp1F0);
                }
            }
        }
        var_r29_717 += 1;
        var_r27_718 += 0x90;
    } while (var_r29_717 < 0xA);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
u8 ZapBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const float &arg3, const int &arg4, bool arg5) {
    MKProp *temp_r17_3233;
    MKProp *temp_r18_3123;
    TargetManager ***var_r17_2607;
    TargetManager ***var_r18_2516;
    TargetManager **temp_r14_2685;
    TargetManager **temp_r17_2592;
    TargetManager **var_r15_2510;
    TargetManager **var_r16_2512;
    f32 temp_f1_2566;
    f32 temp_f1_2659;
    f32 temp_f1_2816;
    f32 temp_f1_3084;
    f32 temp_f1_3186;
    f32 temp_f25_3860;
    f32 temp_f25_3935;
    f32 temp_f26_3408;
    f32 temp_f26_3455;
    f32 temp_f26_3518;
    f32 temp_f26_3573;
    f32 temp_f26_3620;
    f32 temp_f26_3683;
    f32 temp_f26_3865;
    f32 temp_f26_3940;
    f32 temp_f26_4117;
    f32 temp_f26_4150;
    f32 temp_f27_2488;
    f32 temp_f27_3413;
    f32 temp_f27_3460;
    f32 temp_f27_3523;
    f32 temp_f27_3578;
    f32 temp_f27_3625;
    f32 temp_f27_3688;
    f32 temp_f28_3528;
    f32 temp_f28_3693;
    f32 temp_f28_3846;
    f32 temp_f28_4078;
    f32 temp_f30_4112;
    f32 var_f1_2799;
    f32 var_f26_3085;
    f32 var_f26_3187;
    f32 var_f28_2432;
    f32 var_f29_2515;
    f32 var_f29_2606;
    f32 var_f2_2850;
    f64 temp_f0_2317;
    f64 temp_f1_2316;
    f64 temp_f27_3783;
    f64 temp_f27_3843;
    f64 temp_f28_3782;
    f64 temp_f29_3780;
    f64 temp_f29_3845;
    f64 temp_f29_3920;
    f64 temp_f30_3778;
    f64 temp_f30_3918;
    s32 temp_cr0_eq_2314;
    s32 temp_r0_2000;
    s32 temp_r14_2478;
    s32 temp_r14_3049;
    s32 temp_r15_2470;
    s32 temp_r17_2068;
    s32 temp_r18_2057;
    s32 temp_r18_2473;
    s32 temp_r18_3223;
    s32 temp_r19_2467;
    s32 temp_r21_2061;
    s32 temp_r21_2472;
    s32 temp_r22_2063;
    s32 temp_r22_2312;
    s32 temp_r3_2092;
    s32 temp_r3_2220;
    s32 var_r14_3225;
    s32 var_r14_3781;
    s32 var_r14_3840;
    s32 var_r14_3921;
    s32 var_r14_4075;
    s32 var_r15_3779;
    s32 var_r16_2088;
    s32 var_r16_3401;
    s32 var_r16_3566;
    s32 var_r16_3836;
    s32 var_r16_3919;
    s32 var_r17_2124;
    s32 var_r17_2170;
    s32 var_r17_3113;
    s32 var_r17_4073;
    s32 var_r19_3111;
    s32 var_r19_3224;
    s32 var_r24_2433;
    s32 var_r3_3999;
    s32 var_r5_3998;
    u8 temp_r3_2130;
    u8 var_r0_2132;
    u8 var_r15_2041;
    u8 var_r25_2382;
    u8 var_r26_2380;
    u8 var_r27_2378;
    u8 var_r28_2376;
    u8 var_r4_2788;
    void *temp_r3_2772;
    void *temp_r3_2892;
    void *temp_r3_2920;
    void *temp_r3_2999;
    void *temp_r3_3027;
    void *temp_r3_3306;
    void *temp_r3_3377;
    void *temp_r4_4005;
    void *temp_r5_2830;
    void *temp_r5_2956;
    void *temp_r5_3097;
    void *temp_r5_3199;
    void *temp_r6_2552;
    void *temp_r6_2645;
    temp_r0_2000 = &arg4;
    if (temp_r0_2000 == 3) {
        if (((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(3) == 0) {
            return this->unk9EC->Trigger(arg1, 0U);
        }
        this->unk9EC->Trigger(arg1, 1U);
        return ((FuryFXElectricity2 *) (M2C_BITWISE(FuryFXElectricity2 *, this->unk9F0)))->Trigger(arg1);
    }
    if (temp_r0_2000 == 1) {
        arg_sp1C = this->unkD4 + gUpdateTimeDelta;
        this->unkD4 = Clamp<float>(0.0f, arg_sp1C, this->unkD8);
        var_r15_2041 = 0;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkD0 == 0.0f) {
            this->unkD0 = 0.5f;
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (this->unkD4 == this->unkD8) {
                this->unkD4 = 0.0f;
                temp_r18_2057 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
                temp_r21_2061 = temp_r18_2057;
                temp_r22_2063 = *(&GameData::gameData[0x70] + ((temp_r18_2057 << 5) + 0x7C));
                temp_r17_2068 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(temp_r22_2063);
                this->unk160.Init(arg0, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(temp_r21_2061, temp_r22_2063, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(temp_r22_2063)), temp_r22_2063, temp_r17_2068, temp_r18_2057, temp_r18_2057, 0, -1);
                var_r16_2088 = 1;
                temp_r3_2092 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(*(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)));
                switch (temp_r3_2092) {             /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    var_r16_2088 = 1;
                    this->unkD8 = 0.0f;
                    break;
                case 1:                             /* switch 1 */
                    var_r16_2088 = 2;
                    this->unkD8 = 0.0f;
                    break;
                case 2:                             /* switch 1 */
                    var_r16_2088 = 3;
                    this->unkD8 = 0.0f;
                    break;
                case 3:                             /* switch 1 */
                    var_r16_2088 = 4;
                    this->unkD8 = 0.0f;
                    break;
                }
                var_r17_2124 = 0;
loop_22:
                if (var_r17_2124 < var_r16_2088) {
                    temp_r3_2130 = ShootZapMissile(arg1, arg2);
                    var_r0_2132 = var_r15_2041;
                    if (var_r15_2041 == 0) {
                        var_r0_2132 = temp_r3_2130;
                    }
                    var_r15_2041 = var_r0_2132;
                    var_r17_2124 += 1;
                    goto loop_22;
                }
                if (var_r15_2041 != 0) {
                    MKVector(1.0f, 1.0f, 1.0f, 1.0f);
                    arg_sp6A0 = arg_sp690;
                    arg_sp6A8 = arg_sp698;
                    arg_sp18 = MKRand_Float(&gViewSeed, 6.0f, 10.0f);
                    MKVector(0.0f, 0.0f, 0.0f);
                    this->unkCC->Emit(arg1, *((MKVector3 *) &arg_sp6B0), arg_sp18, (MKVector4) &arg_sp6A0);
                    var_r17_2170 = 0;
                    do {
                        MKVector(1.0f, 1.0f, 1.0f);
                        MKVector(-1.0f, -1.0f, -1.0f);
                        KDRand_Vector(*((MKVector3 *) &arg_sp660), *((MKVector3 *) &arg_sp650));
                        arg_sp670.operator+(*((MKVector3 *) &arg_sp660));
                        arg_sp680.operator*(500.0f);
                        arg_sp840 = arg_sp680;
                        arg_sp848 = arg_sp688;
                        ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(arg1, *((MKVector3 *) &arg_sp840), 0.5f, 0U);
                        var_r17_2170 += 1;
                    } while (var_r17_2170 < 6);
                    KDSound_Play3d(GS_SpyBreathEnergyball, &arg1, 0U, -1, 0.0f, 0U);
                    temp_r3_2220 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(*(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)));
                    switch (temp_r3_2220) {         /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.1f, 0.3f, 0.05f, 0, 4.0f, 0U);
                        break;
                    case 1:                         /* switch 2 */
                        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.3f, 0.5f, 0.05f, 0, 4.0f, 0U);
                        break;
                    case 2:                         /* switch 2 */
                        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.3f, 0.7f, 0.05f, 0, 4.0f, 0U);
                        break;
                    case 3:                         /* switch 2 */
                        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.5f, 0.9f, 0.05f, 0, 4.0f, 0U);
                        break;
                    }
                }
                return var_r15_2041;
            }
        }
        return 0U;
    }
    temp_r22_2312 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(*(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)));
    temp_cr0_eq_2314 = temp_r22_2312 == 3;
    this->unk100 = 0.0f;
    temp_f1_2316 = M2C_FIELD(&arg2, f64 *, 0);
    temp_f0_2317 = M2C_FIELD(&arg2, f64 *, 8);
    arg_sp830 = M2C_FIELD(&arg1, f64 *, 0);
    arg_sp838 = M2C_FIELD(&arg1, f64 *, 8);
    arg_sp820 = temp_f1_2316;
    arg_sp828 = temp_f0_2317;
    arg_sp810 = temp_f1_2316;
    arg_sp818 = temp_f0_2317;
    if (temp_cr0_eq_2314 != 0) {
        M2C_STRUCT_COPY((s32) &arg_sp9CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        arg_sp9D0.SetRotationYaw(-0.43633232f);
        ApplyMatrix(*((MKVector3 *) &arg_sp630), (Matrix *) &arg_sp820);
        arg_sp820 = arg_sp630;
        arg_sp828 = arg_sp638;
        M2C_STRUCT_COPY((s32) &arg_sp9CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        arg_sp9D0.SetRotationYaw(0.43633232f);
        ApplyMatrix(*((MKVector3 *) &arg_sp620), (Matrix *) &arg_sp810);
        arg_sp810 = arg_sp620;
        arg_sp818 = arg_sp628;
    }
    var_r28_2376 = 0;
    var_r27_2378 = 0;
    var_r26_2380 = 0;
    arg_sp800 = arg_sp820;
    var_r25_2382 = 0;
    arg_sp808 = arg_sp828;
    arg_sp7F0 = arg_sp810;
    arg_sp7F8 = arg_sp818;
    DisableMissileLight(NULL);
    if ((ManagedLight *) this->unkB0 != NULL) {
        MKVector(1.0f, 1.0f, 0.0f, 1.0f);
        this->unkE8 = arg_sp610;
        this->unkF0 = arg_sp618;
        this->unkB0->SetColor(*((MKVector4 *) &this->unkE8));
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkB0, 1U);
        MKVector(0.0f, 400.0f, 0.0f);
        arg_sp5E0.operator*(500.0f);
        arg_sp5F0.operator+(arg1);
        arg_sp600.operator+(*((MKVector3 *) &arg_sp5F0));
        this->unkB0->SetPosition(*((MKVector3 *) &arg_sp600));
    }
    var_f28_2432 = 500.0f;
    var_r24_2433 = 0;
    switch (temp_r22_2312) {                        /* switch 3; irregular */
    case 0:                                         /* switch 3 */
        var_r24_2433 = 0;
        this->unk9F4 = (FuryFXElectricity *)1;
        break;
    case 1:                                         /* switch 3 */
        var_f28_2432 = 800.0f;
        this->unk9F4 = (FuryFXElectricity *)2;
        var_r24_2433 = 0;
        break;
    case 2:                                         /* switch 3 */
        var_f28_2432 = 1000.0f;
        this->unk9F4 = (FuryFXElectricity *)3;
        var_r24_2433 = 1;
        break;
    case 3:                                         /* switch 3 */
        var_f28_2432 = 1400.0f;
        this->unk9F4 = (FuryFXElectricity *)4;
        var_r24_2433 = 2;
        break;
    }
    temp_r19_2467 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    temp_r15_2470 = temp_r19_2467;
    temp_r21_2472 = temp_r19_2467;
    temp_r18_2473 = *(&GameData::gameData[0x70] + ((temp_r19_2467 << 5) + 0x7C));
    temp_r14_2478 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(temp_r18_2473);
    temp_f27_2488 = ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetBreathAttackDamage(temp_r21_2472, temp_r18_2473, ((GameStats *) ((GameStats *) &GameData::gameData[0x70]))->GetCurrentBreathUpgrade(temp_r18_2473));
    this->unk108.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), temp_f27_2488, temp_r18_2473, temp_r14_2478, temp_r15_2470, temp_r19_2467, var_r24_2433, -1);
    arg_sp830 = M2C_FIELD(&arg1, f64 *, 0);
    var_r15_2510 = NULL;
    var_r16_2512 = NULL;
    arg_sp838 = M2C_FIELD(&arg1, f64 *, 8);
    var_f29_2515 = 3.4028235e38f;
    var_r18_2516 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_64:
    if (var_r18_2516 != NULL) {
        temp_r17_2592 = *var_r18_2516;
        if (temp_r17_2592 != NULL) {
            if (((*temp_r17_2592)->unk8.unk0(temp_r17_2592) != NULL) && (M2C_FIELD(*temp_r17_2592, u8 (**)(TargetManager **), 0x18)(temp_r17_2592) != 0) && ((*temp_r17_2592)->unk8.unk0(temp_r17_2592) != this) && (((u32 (*)(TargetManager **)) (*temp_r17_2592)->unk8.unk4)(temp_r17_2592) != 0U)) {
                temp_r6_2552 = (*temp_r17_2592)->unk8.unk0(temp_r17_2592)->unk8;
                arg_sp5B0 = M2C_FIELD(temp_r6_2552, f64 *, 0x30);
                arg_sp5B8 = M2C_FIELD(temp_r6_2552, f64 *, 0x38);
                arg_sp5C0.operator-(*((MKVector3 *) &arg_sp5B0));
                arg_sp7C0 = arg_sp5C0;
                arg_sp7C8 = arg_sp5C8;
                temp_f1_2566 = arg_sp7C0.Normalise();
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((temp_f1_2566 == var_f28_2432) && (temp_f1_2566 < var_f29_2515) && ((((f32) arg_sp7C8 * (f32) arg_sp828) + (((f32) arg_sp7C0 * (f32) arg_sp820) + (arg_sp7C4 * arg_sp824))) > 0.0f)) {
                    var_f29_2515 = temp_f1_2566;
                    var_r15_2510 = temp_r17_2592;
                    var_r28_2376 = 1;
                }
            }
            var_r18_2516 += 4;
            goto loop_64;
        }
    }
    if (var_r15_2510 != NULL) {
        var_r26_2380 = 1;
    }
    if ((temp_r22_2312 == 3) && (var_r15_2510 != NULL)) {
        var_f29_2606 = 3.4028235e38f;
        var_r17_2607 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_81:
        if (var_r17_2607 != NULL) {
            temp_r14_2685 = *var_r17_2607;
            if (temp_r14_2685 != NULL) {
                if (((*temp_r14_2685)->unk8.unk0(temp_r14_2685) != NULL) && (M2C_FIELD(*temp_r14_2685, u8 (**)(TargetManager **), 0x18)(temp_r14_2685) != 0) && ((*temp_r14_2685)->unk8.unk0(temp_r14_2685) != this) && (temp_r14_2685 != var_r15_2510) && (((u32 (*)(TargetManager **)) (*temp_r14_2685)->unk8.unk4)(temp_r14_2685) != 0U)) {
                    temp_r6_2645 = (*temp_r14_2685)->unk8.unk0(temp_r14_2685)->unk8;
                    arg_sp590 = M2C_FIELD(temp_r6_2645, f64 *, 0x30);
                    arg_sp598 = M2C_FIELD(temp_r6_2645, f64 *, 0x38);
                    arg_sp5A0.operator-(*((MKVector3 *) &arg_sp590));
                    arg_sp7B0 = arg_sp5A0;
                    arg_sp7B8 = arg_sp5A8;
                    temp_f1_2659 = arg_sp7B0.Normalise();
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if ((temp_f1_2659 == var_f28_2432) && (temp_f1_2659 < var_f29_2606) && ((((f32) arg_sp7B8 * (f32) arg_sp818) + (((f32) arg_sp7B0 * (f32) arg_sp810) + (arg_sp7B4 * arg_sp814))) > 0.0f)) {
                        var_f29_2606 = temp_f1_2659;
                        var_r16_2512 = temp_r14_2685;
                        var_r27_2378 = 1;
                    }
                }
                var_r17_2607 += 4;
                goto loop_81;
            }
        }
        if (var_r16_2512 == NULL) {
            var_r16_2512 = var_r15_2510;
        } else {
            var_r25_2382 = 1;
        }
    }
    arg_sp570.operator*(var_f28_2432);
    arg_sp580.operator+(arg1);
    arg_sp7A0 = arg_sp580;
    arg_sp7A8 = arg_sp588;
    arg_sp550.operator*(var_f28_2432);
    arg_sp560.operator+(arg1);
    arg_sp790 = arg_sp560;
    arg_sp798 = arg_sp568;
    if ((var_r15_2510 != NULL) && (((Enemy *) (((Enemy *(*)(TargetManager **)) (*var_r15_2510)->unk8.unk4)(var_r15_2510)))->IsFrozen() == 0) && (((((Enemy *) (((Enemy *(*)(TargetManager **)) (*var_r15_2510)->unk8.unk4)(var_r15_2510)))->IsKnockedDown() == 0) && (temp_r22_2312 == 0)) || (temp_r22_2312 > 0)) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unk100 == 0.0f) != 0))) {
        M2C_FIELD(*var_r15_2510, M2C_UNK (**)(TargetManager **, MKVector3 *, f64 *), 0x2C)(var_r15_2510, &arg1, &arg_sp7A0);
        arg_sp540.operator-(*((MKVector3 *) &arg_sp7A0));
        arg_sp800 = arg_sp540;
        var_r28_2376 = 1;
        var_r26_2380 = 1;
        arg_sp808 = arg_sp548;
        temp_r3_2772 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, f64), 0x40)(M2C_FIELD(&gb, void ***, 0), arg_sp540);
        M2C_STRUCT_COPY((s32) &arg_sp98C + 4, M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), s32 *, 8) - 4 + 4, 0x40);
        var_r4_2788 = 0;
        if (((u8) M2C_FIELD(temp_r3_2772, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_2772, u8 *, 4) != 0)) {
            var_r4_2788 = 1;
        }
        if (var_r4_2788 != 0) {
            var_f1_2799 = 0.0f;
        } else {
            var_f1_2799 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(temp_r3_2772, s32 *, 0), NULL, NULL);
        }
        arg_sp530.operator*(var_f1_2799);
        arg_sp780 = arg_sp530;
        arg_sp788 = arg_sp538;
        temp_f1_2816 = arg_sp780.Normalise();
        if ((temp_f1_2816 > 0.25f) && (temp_r22_2312 >= 0)) {
            arg_sp954 = 0;
            temp_r5_2830 = (*var_r15_2510)->unk8.unk0(var_r15_2510)->unk8;
            arg_sp510 = M2C_FIELD(temp_r5_2830, f64 *, 0x30);
            arg_sp518 = M2C_FIELD(temp_r5_2830, f64 *, 0x38);
            arg_sp4F0.operator-();
            arg_sp500.operator*(300.0f);
            arg_sp520.operator+(*((MKVector3 *) &arg_sp510));
            arg_sp770 = arg_sp520;
            var_f2_2850 = 0.5f;
            arg_sp778 = arg_sp528;
            switch (temp_r22_2312) {                /* switch 4; irregular */
            case 1:                                 /* switch 4 */
                var_f2_2850 = 1.0f;
                break;
            case 2:                                 /* switch 4 */
                var_f2_2850 = 1.5f;
                break;
            case 3:                                 /* switch 4 */
                var_f2_2850 = 2.0f;
                break;
            }
            arg_sp950.Init(NULL, *((MKVector3 *) &arg_sp770), 0.0f, 0, 8, 0x20U, NULL, var_f2_2850);
            if (M2C_FIELD(*var_r15_2510, u8 (**)(TargetManager **), 0x18)(var_r15_2510) != 0) {
                temp_r3_2892 = checked_cast<Enemy *, MKProp>((*var_r15_2510)->unk8.unk0(var_r15_2510));
                M2C_FIELD(temp_r3_2892, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_2892, u8 *, 0xB02) | 4);
            }
            M2C_FIELD((*var_r15_2510)->unk8.unk0(var_r15_2510)->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&arg_sp950);
            if (M2C_FIELD(*var_r15_2510, u8 (**)(TargetManager **), 0x18)(var_r15_2510) != 0) {
                temp_r3_2920 = checked_cast<Enemy *, MKProp>((*var_r15_2510)->unk8.unk0(var_r15_2510));
                M2C_FIELD(temp_r3_2920, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_2920, u8 *, 0xB02) & ~4);
            }
            if ((temp_r22_2312 == 3) && (var_r16_2512 != NULL)) {
                M2C_FIELD(*var_r16_2512, M2C_UNK (**)(TargetManager **, MKVector3 *, f64 *), 0x2C)(var_r16_2512, &arg1, &arg_sp790);
                arg_sp4E0.operator-(*((MKVector3 *) &arg_sp790));
                var_r27_2378 = 1;
                var_r25_2382 = 1;
                arg_sp7F0 = arg_sp4E0;
                arg_sp7F8 = arg_sp4E8;
                if (temp_f1_2816 > 0.25f) {
                    arg_sp914 = 0;
                    temp_r5_2956 = (*var_r16_2512)->unk8.unk0(var_r16_2512)->unk8;
                    arg_sp4C0 = M2C_FIELD(temp_r5_2956, f64 *, 0x30);
                    arg_sp4C8 = M2C_FIELD(temp_r5_2956, f64 *, 0x38);
                    arg_sp4A0.operator-();
                    arg_sp4B0.operator*(300.0f);
                    arg_sp4D0.operator+(*((MKVector3 *) &arg_sp4C0));
                    arg_sp760 = arg_sp4D0;
                    arg_sp768 = arg_sp4D8;
                    arg_sp910.Init(NULL, *((MKVector3 *) &arg_sp760), 0.0f, 0, 8, 0x20U, NULL, 3.0f);
                    if (M2C_FIELD(*var_r16_2512, u8 (**)(TargetManager **), 0x18)(var_r16_2512) != 0) {
                        temp_r3_2999 = checked_cast<Enemy *, MKProp>((*var_r16_2512)->unk8.unk0(var_r16_2512));
                        M2C_FIELD(temp_r3_2999, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_2999, u8 *, 0xB02) | 4);
                    }
                    M2C_FIELD((*var_r16_2512)->unk8.unk0(var_r16_2512)->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&arg_sp910);
                    if (M2C_FIELD(*var_r16_2512, u8 (**)(TargetManager **), 0x18)(var_r16_2512) != 0) {
                        temp_r3_3027 = checked_cast<Enemy *, MKProp>((*var_r16_2512)->unk8.unk0(var_r16_2512));
                        M2C_FIELD(temp_r3_3027, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_3027, u8 *, 0xB02) & ~4);
                    }
                }
            }
        }
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unkDC == 0.0f) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk100 == 0.0f) {
                temp_r14_3049 = MKCollision_SphereCollide(*((MKVector3 *) &arg_sp7A0), 100.0f, (MKCollisionResult *) &arg_spAC0, 5, (MKCollisionMode) 2, 0);
                if ((temp_r22_2312 >= 0) && (M2C_FIELD(*var_r15_2510, u8 (**)(TargetManager **), 0x18)(var_r15_2510) != 0) && (((u32 (*)(TargetManager **)) (*var_r15_2510)->unk8.unk4)(var_r15_2510) != 0U) && (M2C_FIELD(M2C_FIELD(((void *(*)(TargetManager **)) (*var_r15_2510)->unk8.unk4)(var_r15_2510), void **, 0x44), u8 (**)(), 0x1E0)() == 0)) {
                    this->unkDC = 0.5f;
                    this->unk108.unk50 = 0;
                    temp_f1_3084 = M2C_FIELD(*var_r15_2510, f32 (**)(TargetManager **), 0x38)(var_r15_2510);
                    var_f26_3085 = 10.0f;
                    if (var_f26_3085 > temp_f1_3084) {

                    } else {
                        var_f26_3085 = temp_f1_3084;
                    }
                    temp_r5_3097 = (*var_r15_2510)->unk8.unk0(var_r15_2510)->unk8;
                    arg_sp480 = M2C_FIELD(temp_r5_3097, f64 *, 0x30);
                    arg_sp488 = M2C_FIELD(temp_r5_3097, f64 *, 0x38);
                    arg_sp470.operator*(var_f26_3085);
                    arg_sp490.operator-(*((MKVector3 *) &arg_sp480));
                    var_r19_3111 = 0;
                    var_r17_3113 = 0;
                    M2C_FIELD(this, f64 *, 0x118) = arg_sp490;
                    M2C_FIELD(this, f64 *, 0x120) = arg_sp498;
loop_133:
                    if (var_r19_3111 < temp_r14_3049) {
                        temp_r18_3123 = (*var_r15_2510)->unk8.unk0(var_r15_2510);
                        if (((MKCollisionResult *) (&arg_spAC0 + var_r17_3113))->GetProp() == temp_r18_3123) {
                            this->unk108.unk30 = *(&arg_spB08 + var_r17_3113);
                        } else {
                            var_r19_3111 += 1;
                            var_r17_3113 += 0x58;
                            goto loop_133;
                        }
                    }
                    M2C_FIELD((*var_r15_2510)->unk8.unk0(var_r15_2510)->__vptr, M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unk108);
                }
                if ((temp_r22_2312 == 3) && (var_r16_2512 != NULL) && (M2C_FIELD(*var_r16_2512, u8 (**)(TargetManager **), 0x18)(var_r16_2512) != 0) && (((u32 (*)(TargetManager **)) (*var_r15_2510)->unk8.unk4)(var_r15_2510) != 0U) && (M2C_FIELD(M2C_FIELD(((void *(*)(TargetManager **)) (*var_r16_2512)->unk8.unk4)(var_r16_2512), void **, 0x44), u8 (**)(), 0x1E0)() == 0)) {
                    this->unk108.unk50 = 0;
                    temp_f1_3186 = M2C_FIELD(*var_r16_2512, f32 (**)(TargetManager **), 0x38)(var_r16_2512);
                    var_f26_3187 = 10.0f;
                    if (var_f26_3187 > temp_f1_3186) {

                    } else {
                        var_f26_3187 = temp_f1_3186;
                    }
                    temp_r5_3199 = (*var_r16_2512)->unk8.unk0(var_r16_2512)->unk8;
                    arg_sp450 = M2C_FIELD(temp_r5_3199, f64 *, 0x30);
                    arg_sp458 = M2C_FIELD(temp_r5_3199, f64 *, 0x38);
                    arg_sp440.operator*(var_f26_3187);
                    arg_sp460.operator-(*((MKVector3 *) &arg_sp450));
                    M2C_FIELD(this, f64 *, 0x118) = arg_sp460;
                    M2C_FIELD(this, f64 *, 0x120) = arg_sp468;
                    temp_r18_3223 = MKCollision_SphereCollide(*((MKVector3 *) &arg_sp7A0), 100.0f, (MKCollisionResult *) &arg_spAC0, 5, (MKCollisionMode) 2, 0);
                    var_r19_3224 = 0;
                    var_r14_3225 = 0;
loop_147:
                    if (var_r19_3224 < temp_r18_3223) {
                        temp_r17_3233 = (*var_r16_2512)->unk8.unk0(var_r16_2512);
                        if (((MKCollisionResult *) (&arg_spAC0 + var_r14_3225))->GetProp() == temp_r17_3233) {
                            this->unk108.unk30 = *(&arg_spB08 + var_r14_3225);
                        } else {
                            var_r19_3224 += 1;
                            var_r14_3225 += 0x58;
                            goto loop_147;
                        }
                    }
                    M2C_FIELD((*var_r16_2512)->unk8.unk0(var_r16_2512)->__vptr, M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unk108);
                }
            }
        }
    } else {
        arg_spA68.Init();
        arg_sp420.operator*(var_f28_2432);
        arg_sp430.operator+(arg1);
        if (MKCollision_SweepSphereCollide(arg1, *((MKVector3 *) &arg_sp430), 25.0f, (MKCollisionResult *) &arg_spA68, (MKCollisionMode) 7, 0x08000000) != 0) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk100 == 0.0f) {
                arg_sp7A0 = arg_spA68;
                var_r28_2376 = 1;
                arg_sp7A8 = arg_spA70;
                arg_sp410.operator-(*((MKVector3 *) &arg_sp7A0));
                arg_sp800 = arg_sp410;
                arg_sp808 = arg_sp418;
                arg_sp800.Normalise();
                arg_sp7E0 = arg_spA78;
                arg_sp7E8 = arg_spA80;
                temp_r3_3306 = arg_spA68.GetProp();
                if ((temp_r3_3306 != NULL) && (M2C_ERROR(/* unknown instruction: cror eq, lt, eq */), ((this->unkDC == 0.0f) != 0))) {
                    this->unkDC = 0.5f;
                    this->unk108.unk50 = 0;
                    M2C_FIELD(this, f64 *, 0x118) = arg_spA68;
                    M2C_FIELD(this, f64 *, 0x120) = arg_spA70;
                    this->unk108.unk30 = arg_spAB0;
                    M2C_FIELD(M2C_FIELD(temp_r3_3306, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(&this->unk108, arg_spA68);
                    var_r26_2380 = 1;
                } else {
                    var_r26_2380 = 0;
                }
            }
        }
    }
    if ((temp_r22_2312 == 3) && (var_r16_2512 == NULL)) {
        arg_spA10.Init();
        arg_sp3F0.operator*(var_f28_2432);
        arg_sp400.operator+(arg1);
        if (MKCollision_SweepSphereCollide(arg1, *((MKVector3 *) &arg_sp400), 25.0f, (MKCollisionResult *) &arg_spA10, (MKCollisionMode) 7, 0x08000000) != 0) {
            arg_sp790 = arg_spA10;
            var_r27_2378 = 1;
            arg_sp798 = arg_spA18;
            arg_sp3E0.operator-(*((MKVector3 *) &arg_sp7A0));
            arg_sp7F0 = arg_sp3E0;
            arg_sp7F8 = arg_sp3E8;
            arg_sp7F0.Normalise();
            arg_sp7D0 = arg_spA20;
            arg_sp7D8 = arg_spA28;
            temp_r3_3377 = arg_spA10.GetProp();
            if (temp_r3_3377 != NULL) {
                this->unk108.unk50 = 0;
                M2C_FIELD(this, f64 *, 0x118) = arg_spA10;
                M2C_FIELD(this, f64 *, 0x120) = arg_spA18;
                this->unk108.unk30 = arg_spA58;
                M2C_FIELD(M2C_FIELD(temp_r3_3377, void **, 0x44), M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(&this->unk108, arg_spA10);
                var_r25_2382 = 1;
            } else {
                var_r25_2382 = 0;
            }
        }
    }
    if (var_r28_2376 != 0) {
        var_r16_3401 = 0;
        do {
            temp_f26_3408 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_3413 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_3413, temp_f26_3408);
            arg_sp3D0.operator*(1000.0f);
            arg_sp750 = arg_sp3D0;
            arg_sp758 = arg_sp3D8;
            arg_sp14 = MKRand_Float(&gViewSeed, 4.0f, 6.0f);
            MKVector(1.0f, 1.0f, 0.4f, 1.0f);
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp7A0), *((MKVector3 *) &arg_sp750), arg_sp14, *((MKVector4 *) &arg_sp3B0), -500.0f);
            var_r16_3401 += 1;
        } while (var_r16_3401 < 5);
        temp_f26_3455 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_3460 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_3460, temp_f26_3455);
        arg_sp3A0.operator*(2000.0f);
        ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &arg_sp7A0), *((MKVector3 *) &arg_sp3A0), 3.0f, 0U);
        if (var_r26_2380 == 0) {
            this->unk9F8->AddNode(*((MKVector3 *) &arg_sp7A0), *((MKVector3 *) &arg_sp7E0));
            if (MKRand_Int(&gViewSeed, 0, 3) == 0) {
                MKVector(0.0f, 1.0f, 0.0f);
                Cross(*((MKVector3 *) &arg_sp380), *((MKVector3 *) &arg_sp7E0));
                arg_sp740 = arg_sp380;
                arg_sp748 = arg_sp388;
                Cross(*((MKVector3 *) &arg_sp360), *((MKVector3 *) &arg_sp740));
                arg_sp730 = arg_sp360;
                arg_sp738 = arg_sp368;
                temp_f26_3518 = MKRand_Float(&gViewSeed, 0.3f, 0.5f);
                temp_f27_3523 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f28_3528 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp300.operator*(temp_f27_3523);
                arg_sp310.operator*(20.0f);
                arg_sp320.operator*(temp_f28_3528);
                arg_sp330.operator*(20.0f);
                arg_sp340.operator+(*((MKVector3 *) &arg_sp7A0));
                arg_sp350.operator+(*((MKVector3 *) &arg_sp340));
                this->unk9F8->SpawnPlasmaBubble(*((MKVector3 *) &arg_sp350), *((MKVector3 *) &arg_sp7E0), temp_f26_3518);
            }
        }
    } else {
        this->unk9F8->EndTrail();
    }
    if (var_r27_2378 != 0) {
        var_r16_3566 = 0;
        do {
            temp_f26_3573 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_3578 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_3578, temp_f26_3573);
            arg_sp2F0.operator*(200.0f);
            arg_sp750 = arg_sp2F0;
            arg_sp758 = arg_sp2F8;
            arg_sp10 = MKRand_Float(&gViewSeed, 4.0f, 6.0f);
            MKVector(1.0f, 1.0f, 0.4f, 1.0f);
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &arg_sp790), *((MKVector3 *) &arg_sp750), arg_sp10, *((MKVector4 *) &arg_sp2D0), -500.0f);
            var_r16_3566 += 1;
        } while (var_r16_3566 < 5);
        temp_f26_3620 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f27_3625 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_3625, temp_f26_3620);
        arg_sp2C0.operator*(1000.0f);
        ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &arg_sp790), *((MKVector3 *) &arg_sp2C0), 3.0f, 0U);
        if (var_r25_2382 == 0) {
            this->unk9FC->AddNode(*((MKVector3 *) &arg_sp790), *((MKVector3 *) &arg_sp7D0));
            if (MKRand_Int(&gViewSeed, 0, 3) == 0) {
                MKVector(0.0f, 1.0f, 0.0f);
                Cross(*((MKVector3 *) &arg_sp2A0), *((MKVector3 *) &arg_sp7D0));
                arg_sp720 = arg_sp2A0;
                arg_sp728 = arg_sp2A8;
                Cross(*((MKVector3 *) &arg_sp280), *((MKVector3 *) &arg_sp720));
                arg_sp710 = arg_sp280;
                arg_sp718 = arg_sp288;
                temp_f26_3683 = MKRand_Float(&gViewSeed, 0.3f, 0.5f);
                temp_f27_3688 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f28_3693 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                arg_sp220.operator*(temp_f27_3688);
                arg_sp230.operator*(20.0f);
                arg_sp240.operator*(temp_f28_3693);
                arg_sp250.operator*(20.0f);
                arg_sp260.operator+(*((MKVector3 *) &arg_sp790));
                arg_sp270.operator+(*((MKVector3 *) &arg_sp260));
                this->unk9FC->SpawnPlasmaBubble(*((MKVector3 *) &arg_sp270), *((MKVector3 *) &arg_sp7D0), temp_f26_3683);
            }
        }
    } else {
        this->unk9FC->EndTrail();
    }
    if (temp_r22_2312 == 3) {
        if ((u8) this->unk9E0 == 0) {
            this->unk1C0.unk18 = arg_sp7A0;
            this->unk1C0.unk20 = arg_sp7A8;
            this->unk3E0 = arg_sp7A0;
            this->unk3E0 = arg_sp7A8;
            this->unk5E0 = arg_sp790;
            this->unk5E0 = arg_sp798;
            this->unk7E0 = arg_sp790;
            this->unk7E0 = arg_sp798;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp874 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                arg_sp210.operator*(50.0f);
                arg_sp870.Init(*((MKVector3 *) &arg_sp210), 1U);
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp870);
            }
        }
        if (arg5 != 0) {
            temp_f30_3778 = M2C_FIELD(&arg2, f64 *, 0);
            var_r15_3779 = 0;
            temp_f29_3780 = M2C_FIELD(&arg2, f64 *, 8);
            var_r14_3781 = 0;
            temp_f28_3782 = M2C_FIELD(&arg1, f64 *, 0);
            temp_f27_3783 = M2C_FIELD(&arg1, f64 *, 8);
loop_182:
            if (var_r15_3779 < (FuryFXElectricity *) this->unk9F4) {
                arg_sp1D0 = temp_f30_3778;
                arg_sp1D8 = temp_f29_3780;
                arg_sp1E0 = arg_sp7A0;
                arg_sp1E8 = arg_sp7A8;
                arg_sp1F0 = temp_f28_3782;
                arg_sp1F8 = temp_f27_3783;
                ((ElectricBeam *) (this + (var_r14_3781 + 0x1C0)))->SetBeamPositions((MKVector3) &arg_sp1F0, (MKVector3) &arg_sp1E0, (MKVector3) &arg_sp1D0);
                var_r15_3779 += 1;
                var_r14_3781 += 0x200;
                goto loop_182;
            }
        } else {
            M2C_STRUCT_COPY((s32) &arg_sp8CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            MKVector(0.0f, 1.0f, 0.0f);
            arg_sp700 = arg_sp1C0;
            arg_sp708 = arg_sp1C8;
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp8D0, arg2, (MKVector3 *) &arg_sp700);
            var_r16_3836 = 0;
            var_r14_3840 = 0;
            temp_f27_3843 = M2C_FIELD(&arg1, f64 *, 0);
            temp_f29_3845 = M2C_FIELD(&arg1, f64 *, 8);
            temp_f28_3846 = 6.2831855f / (f32) this->unk9F4;
            do {
                if (var_r15_2510 == NULL) {
                    temp_f25_3860 = temp_f28_3846 * (f32) var_r16_3836;
                    temp_f26_3865 = -_table_sinf(1.5707964f + ((3.0f * M2C_BITWISE(f32, this->unkA04)) + temp_f25_3860));
                    arg_sp6F0 = _table_sinf(M2C_BITWISE(f32, this->unkA04) + temp_f25_3860);
                    arg_sp6F4 = temp_f26_3865;
                    arg_sp6F8 = 0.0f;
                    ApplyMatrix(*((MKVector3 *) &arg_sp1B0), (Matrix *) &arg_sp6F0);
                    arg_sp6F0 = arg_sp1B0;
                    arg_sp6F8 = arg_sp1B8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                    arg_sp6F8 *= 50.0f;
                } else {
                    arg_sp6F0 = 0.0f;
                    arg_sp6F4 = 0.0f;
                    arg_sp6F8 = 0.0f;
                }
                arg_sp170 = arg_sp820;
                arg_sp178 = arg_sp828;
                arg_sp180.operator+(*((MKVector3 *) &arg_sp7A0));
                arg_sp190 = arg_sp180;
                arg_sp198 = arg_sp188;
                arg_sp1A0 = temp_f27_3843;
                arg_sp1A8 = temp_f29_3845;
                ((ElectricBeam *) (this + (var_r14_3840 + 0x1C0)))->UpdateBeam((MKVector3) &arg_sp1A0, (MKVector3) &arg_sp190, (MKVector3) &arg_sp170);
                var_r16_3836 += 1;
                var_r14_3840 += 0x200;
            } while (var_r16_3836 < 2);
            temp_f30_3918 = M2C_FIELD(&arg1, f64 *, 0);
            var_r16_3919 = 2;
            temp_f29_3920 = M2C_FIELD(&arg1, f64 *, 8);
            var_r14_3921 = 0x400;
            do {
                if (var_r15_2510 == NULL) {
                    temp_f25_3935 = temp_f28_3846 * (f32) var_r16_3919;
                    temp_f26_3940 = -_table_sinf(1.5707964f + ((3.0f * M2C_BITWISE(f32, this->unkA04)) + temp_f25_3935));
                    arg_sp6F0 = _table_sinf(M2C_BITWISE(f32, this->unkA04) + temp_f25_3935);
                    arg_sp6F4 = temp_f26_3940;
                    arg_sp6F8 = 0.0f;
                    ApplyMatrix(*((MKVector3 *) &arg_sp160), (Matrix *) &arg_sp6F0);
                    arg_sp6F0 = arg_sp160;
                    arg_sp6F8 = arg_sp168;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp6F8 *= 50.0f;
                } else {
                    arg_sp6F0 = 0.0f;
                    arg_sp6F4 = 0.0f;
                    arg_sp6F8 = 0.0f;
                }
                arg_sp120 = arg_sp810;
                arg_sp128 = arg_sp818;
                arg_sp130.operator+(*((MKVector3 *) &arg_sp790));
                arg_sp140 = arg_sp130;
                arg_sp148 = arg_sp138;
                arg_sp150 = temp_f30_3918;
                arg_sp158 = temp_f29_3920;
                ((ElectricBeam *) (this + (var_r14_3921 + 0x1C0)))->UpdateBeam((MKVector3) &arg_sp150, (MKVector3) &arg_sp140, (MKVector3) &arg_sp120);
                var_r16_3919 += 1;
                var_r14_3921 += 0x200;
            } while (var_r16_3919 < 4);
        }
    } else {
        if ((u8) this->unk9E0 == 0) {
            var_r5_3998 = 0;
            var_r3_3999 = 0;
loop_198:
            if (var_r5_3998 < (FuryFXElectricity *) this->unk9F4) {
                temp_r4_4005 = this + (var_r3_3999 + 0x1E0);
                var_r5_3998 += 1;
                var_r3_3999 += 0x200;
                M2C_FIELD(temp_r4_4005, f64 *, 0) = arg_sp7A0;
                M2C_FIELD(temp_r4_4005, f64 *, 8) = arg_sp7A8;
                goto loop_198;
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                arg_sp854 = 0;
                MKVector(1.0f, 1.0f, 1.0f);
                arg_sp110.operator*(50.0f);
                arg_sp850.Init(*((MKVector3 *) &arg_sp110), 1U);
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp850);
            }
        }
        M2C_STRUCT_COPY((s32) &arg_sp88C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        MKVector(0.0f, 1.0f, 0.0f);
        arg_sp6E0 = arg_spF0;
        arg_sp6E8 = arg_spF8;
        KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp890, *((MKVector3 *) &arg_sp820), (MKVector3 *) &arg_sp6E0);
        var_r17_4073 = 0;
        var_r14_4075 = 0;
        temp_f28_4078 = 6.2831855f / (f32) this->unk9F4;
loop_208:
        if (var_r17_4073 < (FuryFXElectricity *) this->unk9F4) {
            if (arg5 != 0) {
                arg_spC0 = arg_sp820;
                arg_spC8 = arg_sp828;
                arg_spD0 = arg_sp7A0;
                arg_spD8 = arg_sp7A8;
                arg_spE0 = M2C_FIELD(&arg1, f64 *, 0);
                arg_spE8 = M2C_FIELD(&arg1, f64 *, 8);
                ((ElectricBeam *) (this + (var_r14_4075 + 0x1C0)))->SetBeamPositions((MKVector3) &arg_spE0, (MKVector3) &arg_spD0, (MKVector3) &arg_spC0);
            } else {
                temp_f30_4112 = temp_f28_4078 * (f32) var_r17_4073;
                temp_f26_4117 = -_table_sinf(1.5707964f + (M2C_BITWISE(f32, this->unkA00) + temp_f30_4112));
                arg_sp6D0 = _table_sinf(M2C_BITWISE(f32, this->unkA00) + temp_f30_4112);
                arg_sp6D4 = temp_f26_4117;
                arg_sp6D8 = 0.0f;
                ApplyMatrix(*((MKVector3 *) &arg_spB0), (Matrix *) &arg_sp6D0);
                arg_sp6D0 = arg_spB0;
                arg_sp6D8 = arg_spB8;
                MKVector(0.0f, 0.0f, 0.0f);
                arg_sp6C0 = arg_spA0;
                arg_sp6C8 = arg_spA8;
                if (var_r15_2510 == NULL) {
                    temp_f26_4150 = -_table_sinf(1.5707964f + ((3.0f * M2C_BITWISE(f32, this->unkA04)) + temp_f30_4112));
                    arg_sp6C0 = _table_sinf(M2C_BITWISE(f32, this->unkA04) + temp_f30_4112);
                    arg_sp6C4 = temp_f26_4150;
                    arg_sp6C8 = 0.0f;
                    ApplyMatrix(*((MKVector3 *) &arg_sp90), (Matrix *) &arg_sp6C0);
                    arg_sp6C0 = arg_sp90;
                    arg_sp6C8 = arg_sp98;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    arg_sp6C8 = (f32) arg_sp6C8 * 50.0f;
                }
                arg_sp20.operator*(0.5f);
                arg_sp30.operator+(*((MKVector3 *) &arg_sp820));
                Normalise(*((MKVector3 *) &arg_sp40));
                arg_sp50 = arg_sp40;
                arg_sp58 = arg_sp48;
                arg_sp60.operator+(*((MKVector3 *) &arg_sp7A0));
                arg_sp70 = arg_sp60;
                arg_sp78 = arg_sp68;
                arg_sp80 = M2C_FIELD(&arg1, f64 *, 0);
                arg_sp88 = M2C_FIELD(&arg1, f64 *, 8);
                ((ElectricBeam *) (this + (var_r14_4075 + 0x1C0)))->UpdateBeam((MKVector3) &arg_sp80, (MKVector3) &arg_sp70, (MKVector3) &arg_sp50);
            }
            var_r17_4073 += 1;
            var_r14_4075 += 0x200;
            goto loop_208;
        }
    }
    this->unk1C0.EmitSparks();
    this->unk9E0 = 1;
    this->unk9E4 = (Corona *)1;
    this->unkC8 = 1;
    this->unkC9 = 1;
    return 1U;
}
#endif

#if 0 // DRAFT: illegal type
void ZapBreathFX::Deinit() {
    Corona *temp_r4_4552;
    MKHeap *temp_r3_4515;
    MKHeap *temp_r3_4572;
    ManagedLight *temp_r4_4528;
    s32 var_r30_4504;
    s32 var_r30_4542;
    s32 var_r30_4560;
    s32 var_r31_4505;
    s32 var_r31_4543;
    s32 var_r31_4561;
    void *temp_r31_4514;
    void *temp_r31_4571;

    var_r30_4504 = 0;
    var_r31_4505 = 0;
    do {
        ((Zap *) (this->unkA8 + var_r31_4505))->Deinit();
        var_r30_4504 += 1;
        var_r31_4505 += 0x1D0;
    } while (var_r30_4504 < 3);
    temp_r31_4514 = this->unkA8;
    temp_r3_4515 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4515 != NULL) {
        ((MKHeap *) (temp_r3_4515->Current()))->Free(temp_r31_4514, NULL, 0);
    } else {
        free(temp_r31_4514);
    }
    temp_r4_4528 = this->unkB0;
    if (temp_r4_4528 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_4528, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unkB0);
    }
    this->unkB4.Deinit();
    var_r30_4542 = 0;
    var_r31_4543 = 0;
    do {
        ((ElectricBeam *) (this + (var_r31_4543 + 0x1C0)))->Deinit();
        var_r30_4542 += 1;
        var_r31_4543 += 0x200;
    } while (var_r30_4542 < 4);
    temp_r4_4552 = this->unk9E4;
    if (temp_r4_4552 != NULL) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_4552);
    }
    var_r30_4560 = 0;
    var_r31_4561 = 0;
    do {
        KDSound_Stop(this->unkAC + (var_r31_4561 + 0x64));
        var_r30_4560 += 1;
        var_r31_4561 += 0x90;
    } while (var_r30_4560 < 0xA);
    temp_r31_4571 = this->unkAC;
    temp_r3_4572 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_4572 != NULL) {
        ((MKHeap *) (temp_r3_4572->Current()))->Free(temp_r31_4571, NULL, 0);
    } else {
        free(temp_r31_4571);
    }
    MKModel_Destroy(this->unkE0);
    BaseBreathFX::Deinit();
}
#endif

#if 0 // DRAFT: type mismatch
void ZapBreathFX::Draw() {
    s32 var_r30_4607;
    s32 var_r31_4608;

    if (EventCamera_GetCurrent() == NULL) {
        var_r30_4607 = 0;
        var_r31_4608 = 0;
loop_3:
        if (var_r30_4607 < (FuryFXElectricity *) this->unk9F4) {
            ((ElectricBeam *) (this + (var_r31_4608 + 0x1C0)))->Draw();
            var_r30_4607 += 1;
            var_r31_4608 += 0x200;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ZapBreathFX::Message(MKMessage *arg0) {
    s32 var_r30_4638;
    s32 var_r31_4639;

    KDProp::Message(arg0);
    var_r30_4638 = 0;
    var_r31_4639 = 0;
    do {
        ((KDSoundPlayer *) (this->unkAC + (var_r31_4639 + 0x64)))->Message(arg0);
        var_r30_4638 += 1;
        var_r31_4639 += 0x90;
    } while (var_r30_4638 < 0xA);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'ScorchTrail *' to
void ZapBreathFX::Update() {
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    MKVector4 sp308;
    MKVector4 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    MKVector4 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    MKVector4 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    Corona *temp_r0_4948;
    Corona *temp_r3_4708;
    Corona *temp_r4_4695;
    ManagedLight *temp_r3_4847;
    ManagedLight *temp_r3_4880;
    ManagedLight *temp_r3_4919;
    ManagedLight *temp_r3_4932;
    ManagedLight *temp_r3_5104;
    ManagedLight *temp_r3_5137;
    ManagedLight *temp_r3_5319;
    ManagedLight *temp_r3_5352;
    f32 temp_f0_4747;
    f32 temp_f0_4881;
    f32 temp_f0_5004;
    f32 temp_f0_5138;
    f32 temp_f0_5219;
    f32 temp_f0_5353;
    f32 temp_f1_4863;
    f32 temp_f1_5120;
    f32 temp_f1_5335;
    f32 temp_f1_5482;
    f32 temp_f3_4872;
    f32 temp_f3_4875;
    f32 temp_f3_5129;
    f32 temp_f3_5132;
    f32 temp_f3_5344;
    f32 temp_f3_5347;
    f32 var_f1_5489;
    f32 var_f4_4864;
    f32 var_f4_5121;
    f32 var_f4_5336;
    s32 temp_r0_4975;
    s32 temp_r0_5168;
    s32 temp_r0_5190;
    s32 temp_r0_5385;
    s32 temp_r3_5383;
    s32 var_r0_5401;
    s32 var_r29_4671;
    s32 var_r30_4673;
    s32 var_r3_4972;
    s32 var_r3_5164;
    s32 var_r3_5187;
    s32 var_r4_4970;
    s32 var_r4_5185;
    s32 var_r5_5163;
    u8 temp_r30_4971;
    u8 temp_r30_5186;
    u8 var_r3_5391;
    void *temp_r3_4852;
    void *temp_r3_4883;
    void *temp_r3_4924;
    void *temp_r3_4935;
    void *temp_r3_5109;
    void *temp_r3_5140;
    void *temp_r3_5324;
    void *temp_r3_5355;
    void *temp_r4_5387;

    var_r29_4671 = 0;
    var_r30_4673 = 0;
    this->unkDC -= gUpdateTimeDelta;
    this->unkA00 = M2C_BITWISE(f32, this->unkA00) + gUpdateTimeDelta;
    this->unkA04 = (6.2831855f * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unkA04);
loop_2:
    if (var_r29_4671 < (FuryFXElectricity *) this->unk9F4) {
        ((ElectricBeam *) (this + (var_r30_4673 + 0x1C0)))->Update();
        var_r29_4671 += 1;
        var_r30_4673 += 0x200;
        goto loop_2;
    }
    temp_r4_4695 = this->unk9E4;
    if (temp_r4_4695 != NULL) {
        temp_r4_4695->unk0 = this->unk1C0.unk8;
        temp_r4_4695->unk8 = this->unk1C0.unk10;
        this->unk9E4->unk24 = MKRand_Float(&gViewSeed, 0.8f, 1.1f);
        temp_r3_4708 = this->unk9E4;
        temp_r3_4708->unk31 = (temp_r3_4708->unk31 & ~0x40) | ((this->unk9E0 << 6) & 0x40);
    }
    if ((((u8) this->unk9E0 == 0) && (LightActiveOnMissiles() == 0)) || (EventCamera_GetCurrent() != NULL)) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkB0, 0U);
    } else if ((ManagedLight *) this->unkB0 != NULL) {
        if (LightActiveOnMissiles() == 0) {
            temp_f0_4747 = MKRand_Float(&gViewSeed, 0.2f, 0.8f) * 1.0f;
            sp268 = 0.25f;
            sp26C = 0.25f;
            sp270 = 1.0f;
            sp274 = 1.0f;
            sp278 = 1.0f;
            sp27C = 1.0f;
            sp280 = 0.0f;
            sp284 = 1.0f;
            sp318 = (f64) sp268;
            sp320 = (f64) sp270;
            sp328 = (f64) sp278;
            sp330 = (f64) sp280;
            if ((0.5f * temp_f0_4747) < 1.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
            sp238 = sp128;
            sp240 = sp130;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp228 = sp118;
            sp230 = sp120;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
            sp218 = sp108;
            sp220 = sp110;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
            sp258 = spF8;
            sp260 = sp100;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp248 = spE8;
            sp250 = spF0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            sp358 = spD8;
            sp360 = spE0;
            KDMath_Smooth<MKVector4>(sp308, *((MKVector4 *) &this->unkE8), 0.75f, 1.0f);
            this->unkE8 = M2C_BITWISE(f64, sp308);
            this->unkF0 = (f64) sp308.unk8;
            temp_r3_4847 = this->unkB0;
            temp_r3_4847->unk20 = this->unkE8;
            temp_r3_4847->unk28 = this->unkF0;
            temp_r3_4852 = temp_r3_4847->unk3C;
            if (temp_r3_4852 != NULL) {
                M2C_FIELD(temp_r3_4852, f64 *, 0) = (f64) this->unkE8;
                M2C_FIELD(temp_r3_4852, f64 *, 8) = (f64) this->unkF0;
            }
            temp_f1_4863 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
            var_f4_4864 = 0.125f;
            if (1.0f > 0.125f) {

            } else {
                var_f4_4864 = 1.0f;
            }
            temp_f3_4872 = this->unkF8;
            temp_f3_4875 = (var_f4_4864 * (temp_f1_4863 - temp_f3_4872)) + temp_f3_4872;
            this->unkF8 = (var_f4_4864 * (temp_f1_4863 - temp_f3_4875)) + temp_f3_4875;
            temp_r3_4880 = this->unkB0;
            temp_f0_4881 = 1000.0f * this->unkF8;
            temp_r3_4880->unk38 = temp_f0_4881;
            temp_r3_4883 = temp_r3_4880->unk3C;
            if (temp_r3_4883 != NULL) {
                M2C_FIELD(temp_r3_4883, f32 *, 0x20) = temp_f0_4881;
                M2C_FIELD(temp_r3_4883, f32 *, 0x24) = (f32) (temp_f0_4881 * temp_f0_4881);
                M2C_FIELD(temp_r3_4883, f32 *, 0x28) = (f32) (1.0f / temp_f0_4881);
                M2C_FIELD(temp_r3_4883, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_4883, f32 *, 0x24));
            }
        } else {
            spC8 = 0.0f;
            spCC = 0.0f;
            spD0 = 0.0f;
            spD4 = 1.0f;
            sp2E8 = (f64) spC8;
            sp2F0 = (f64) spD0;
            KDMath_Smooth<MKVector4>(sp2F8, *((MKVector4 *) &this->unkE8), 0.5f, 15.0f * gUpdateTimeDelta);
            this->unkE8 = M2C_BITWISE(f64, sp2F8);
            this->unkF0 = (f64) sp2F8.unk8;
            temp_r3_4919 = this->unkB0;
            temp_r3_4919->unk20 = this->unkE8;
            temp_r3_4919->unk28 = this->unkF0;
            temp_r3_4924 = temp_r3_4919->unk3C;
            if (temp_r3_4924 != NULL) {
                M2C_FIELD(temp_r3_4924, f64 *, 0) = (f64) this->unkE8;
                M2C_FIELD(temp_r3_4924, f64 *, 8) = (f64) this->unkF0;
            }
            temp_r3_4932 = this->unkB0;
            temp_r3_4932->unk38 = 1000.0f;
            temp_r3_4935 = temp_r3_4932->unk3C;
            if (temp_r3_4935 != NULL) {
                M2C_FIELD(temp_r3_4935, f32 *, 0x20) = 1000.0f;
                M2C_FIELD(temp_r3_4935, f32 *, 0x24) = 1000000.0f;
                M2C_FIELD(temp_r3_4935, f32 *, 0x28) = 0.001f;
                M2C_FIELD(temp_r3_4935, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_4935, f32 *, 0x24));
            }
        }
    }
    temp_r0_4948 = this->unk9E4;
    switch (temp_r0_4948) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        if ((u8) this->unk9E0 == 0) {
            this->unk9E4 = (Corona *)2;
            this->unk9E8 = 0.2f;
        } else {
            var_r4_4970 = 0;
            temp_r30_4971 = MKRand_Int(&gViewSeed, 0, 0xA) != 0;
            var_r3_4972 = 0;
loop_33:
            if (var_r4_4970 < (FuryFXElectricity *) this->unk9F4) {
                temp_r0_4975 = var_r3_4972 + 0x3B4;
                var_r3_4972 += 0x200;
                *(this + temp_r0_4975) = temp_r30_4971;
                var_r4_4970 += 1;
                goto loop_33;
            }
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkB0, temp_r30_4971);
            if ((temp_r30_4971 != 0) && ((ManagedLight *) this->unkB0 != NULL) && (LightActiveOnMissiles() == 0)) {
                temp_f0_5004 = MKRand_Float(&gViewSeed, 0.2f, 0.8f) * 1.0f;
                sp1F8 = 0.25f;
                sp1FC = 0.25f;
                sp200 = 1.0f;
                sp204 = 1.0f;
                sp208 = 1.0f;
                sp20C = 1.0f;
                sp210 = 0.0f;
                sp214 = 1.0f;
                sp2C8 = (f64) sp1F8;
                sp2D0 = (f64) sp200;
                sp2D8 = (f64) sp208;
                sp2E0 = (f64) sp210;
                if ((0.5f * temp_f0_5004) < 1.0f) {

                }
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
                sp1C8 = spB8;
                sp1D0 = spC0;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp1B8 = spA8;
                sp1C0 = spB0;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
                sp1A8 = sp98;
                sp1B0 = spA0;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
                sp1E8 = sp88;
                sp1F0 = sp90;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp1D8 = sp78;
                sp1E0 = sp80;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
                sp348 = sp68;
                sp350 = sp70;
                KDMath_Smooth<MKVector4>(sp2B8, *((MKVector4 *) &this->unkE8), 0.75f, 1.0f);
                this->unkE8 = M2C_BITWISE(f64, sp2B8);
                this->unkF0 = (f64) sp2B8.unk8;
                temp_r3_5104 = this->unkB0;
                temp_r3_5104->unk20 = this->unkE8;
                temp_r3_5104->unk28 = this->unkF0;
                temp_r3_5109 = temp_r3_5104->unk3C;
                if (temp_r3_5109 != NULL) {
                    M2C_FIELD(temp_r3_5109, f64 *, 0) = (f64) this->unkE8;
                    M2C_FIELD(temp_r3_5109, f64 *, 8) = (f64) this->unkF0;
                }
                temp_f1_5120 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                var_f4_5121 = 0.125f;
                if (1.0f > 0.125f) {

                } else {
                    var_f4_5121 = 1.0f;
                }
                temp_f3_5129 = this->unkF8;
                temp_f3_5132 = (var_f4_5121 * (temp_f1_5120 - temp_f3_5129)) + temp_f3_5129;
                this->unkF8 = (var_f4_5121 * (temp_f1_5120 - temp_f3_5132)) + temp_f3_5132;
                temp_r3_5137 = this->unkB0;
                temp_f0_5138 = 1000.0f * this->unkF8;
                temp_r3_5137->unk38 = temp_f0_5138;
                temp_r3_5140 = temp_r3_5137->unk3C;
                if (temp_r3_5140 != NULL) {
                    M2C_FIELD(temp_r3_5140, f32 *, 0x20) = temp_f0_5138;
                    M2C_FIELD(temp_r3_5140, f32 *, 0x24) = (f32) (temp_f0_5138 * temp_f0_5138);
                    M2C_FIELD(temp_r3_5140, f32 *, 0x28) = (f32) (1.0f / temp_f0_5138);
                    M2C_FIELD(temp_r3_5140, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_5140, f32 *, 0x24));
                }
            }
        }
        break;
    case 2:                                         /* switch 1 */
        this->unk9E8 = M2C_BITWISE(f32, this->unk9E8) - gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (M2C_BITWISE(f32, this->unk9E8) == 0.0f) {
            var_r5_5163 = 0;
            var_r3_5164 = 0;
loop_50:
            if (var_r5_5163 < (FuryFXElectricity *) this->unk9F4) {
                temp_r0_5168 = var_r3_5164 + 0x3B4;
                var_r3_5164 += 0x200;
                *(this + temp_r0_5168) = 0;
                var_r5_5163 += 1;
                goto loop_50;
            }
            this->unk9E4 = NULL;
        } else {
            var_r4_5185 = 0;
            temp_r30_5186 = MKRand_Int(&gViewSeed, 0, 2) != 0;
            var_r3_5187 = 0;
loop_54:
            if (var_r4_5185 < (FuryFXElectricity *) this->unk9F4) {
                temp_r0_5190 = var_r3_5187 + 0x3B4;
                var_r3_5187 += 0x200;
                *(this + temp_r0_5190) = temp_r30_5186;
                var_r4_5185 += 1;
                goto loop_54;
            }
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkB0, temp_r30_5186);
            if ((temp_r30_5186 != 0) && ((ManagedLight *) this->unkB0 != NULL) && (LightActiveOnMissiles() == 0)) {
                temp_f0_5219 = MKRand_Float(&gViewSeed, 0.2f, 0.8f) * 1.0f;
                sp188 = 0.25f;
                sp18C = 0.25f;
                sp190 = 1.0f;
                sp194 = 1.0f;
                sp198 = 1.0f;
                sp19C = 1.0f;
                sp1A0 = 0.0f;
                sp1A4 = 1.0f;
                sp298 = (f64) sp188;
                sp2A0 = (f64) sp190;
                sp2A8 = (f64) sp198;
                sp2B0 = (f64) sp1A0;
                if ((0.5f * temp_f0_5219) < 1.0f) {

                }
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f4 */);
                sp158 = sp58;
                sp160 = sp60;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp148 = sp48;
                sp150 = sp50;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f4, $f0 */);
                sp138 = sp38;
                sp140 = sp40;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f2 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f5, $f3 */);
                sp178 = sp28;
                sp180 = sp30;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                sp168 = sp18;
                sp170 = sp20;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
                sp338 = sp8;
                sp340 = sp10;
                KDMath_Smooth<MKVector4>(sp288, *((MKVector4 *) &this->unkE8), 0.75f, 1.0f);
                this->unkE8 = M2C_BITWISE(f64, sp288);
                this->unkF0 = (f64) sp288.unk8;
                temp_r3_5319 = this->unkB0;
                temp_r3_5319->unk20 = this->unkE8;
                temp_r3_5319->unk28 = this->unkF0;
                temp_r3_5324 = temp_r3_5319->unk3C;
                if (temp_r3_5324 != NULL) {
                    M2C_FIELD(temp_r3_5324, f64 *, 0) = (f64) this->unkE8;
                    M2C_FIELD(temp_r3_5324, f64 *, 8) = (f64) this->unkF0;
                }
                temp_f1_5335 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                var_f4_5336 = 0.125f;
                if (1.0f > 0.125f) {

                } else {
                    var_f4_5336 = 1.0f;
                }
                temp_f3_5344 = this->unkF8;
                temp_f3_5347 = (var_f4_5336 * (temp_f1_5335 - temp_f3_5344)) + temp_f3_5344;
                this->unkF8 = (var_f4_5336 * (temp_f1_5335 - temp_f3_5347)) + temp_f3_5347;
                temp_r3_5352 = this->unkB0;
                temp_f0_5353 = 1000.0f * this->unkF8;
                temp_r3_5352->unk38 = temp_f0_5353;
                temp_r3_5355 = temp_r3_5352->unk3C;
                if (temp_r3_5355 != NULL) {
                    M2C_FIELD(temp_r3_5355, f32 *, 0x20) = temp_f0_5353;
                    M2C_FIELD(temp_r3_5355, f32 *, 0x24) = (f32) (temp_f0_5353 * temp_f0_5353);
                    M2C_FIELD(temp_r3_5355, f32 *, 0x28) = (f32) (1.0f / temp_f0_5353);
                    M2C_FIELD(temp_r3_5355, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_5355, f32 *, 0x24));
                }
            }
        }
        break;
    }
    if (((u8) this->unkC9 != 0) && (EventCamera_GetCurrent() == NULL)) {
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk104 == 0.0f) {
            temp_r3_5383 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            temp_r0_5385 = *(&GameData::gameData[0x70] + (temp_r3_5383 + 0x7C));
            temp_r4_5387 = &GameData::gameData[0x70] + (temp_r3_5383 + 0x64);
            if (temp_r0_5385 == 3) {
                var_r3_5391 = 0;
                if (((s32) M2C_FIELD(temp_r4_5387, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_5387, s32 *, 4) == 3)) {
                    var_r3_5391 = 1;
                }
                var_r0_5401 = var_r3_5391 != 0;
            } else {
                var_r0_5401 = *(temp_r4_5387 + (temp_r0_5385 * 4));
            }
            switch (var_r0_5401) {                  /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.05f, 0.1f, 0.04f, 0, 4.0f, 0U);
                break;
            case 1:                                 /* switch 2 */
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.1f, 0.4f, 0.04f, 0, 4.0f, 0U);
                break;
            case 2:                                 /* switch 2 */
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.2f, 0.6f, 0.04f, 0, 4.0f, 0U);
                break;
            case 3:                                 /* switch 2 */
                ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.4f, 1.0f, 0.04f, 0, 4.0f, 0U);
                break;
            }
        }
        temp_f1_5482 = this->unk104;
        if (temp_f1_5482 < -0.25f) {
            var_f1_5489 = MKRand_Float(&gViewSeed, 0.1f, 0.5f);
        } else {
            var_f1_5489 = temp_f1_5482 - gUpdateTimeDelta;
        }
        this->unk104 = var_f1_5489;
    } else {
        this->unk104 = 0.5f;
    }
    this->unkC9 = 0;
    UpdateZapMissiles();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ZapBreathFX::Resolve() {
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r4_5681;
    ManagedLight *temp_r4_5646;
    s32 temp_r0_5749;
    s32 var_r27_5689;
    s32 var_r27_5703;
    s32 var_r30_5690;
    s32 var_r30_5704;
    void *temp_r4_5752;

    MKProp::Resolve();
    sp70 = 0.0f;
    sp80 = 0.0f;
    sp58 = 1.0f;
    sp5C = 1.0f;
    sp60 = 1.0f;
    sp64 = 1.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    spD8 = (f64) sp58;
    spE0 = (f64) sp60;
    spE8 = (f64) sp68;
    spF0 = (f64) sp70;
    spF8 = (f64) sp78;
    sp100 = (f64) sp80;
    this->unkB0 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &spF8), *((MKVector3 *) &spE8), *((MKVector4 *) &spD8), 300.0f, lit_933, lit_934);
    temp_r4_5646 = this->unkB0;
    if (temp_r4_5646 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_5646, 0U);
    }
    sp50 = 0.0f;
    sp38 = 1.0f;
    sp3C = 1.0f;
    sp40 = 0.4f;
    sp44 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    spB8 = (f64) sp38;
    spC0 = (f64) sp40;
    spC8 = (f64) sp48;
    spD0 = (f64) sp50;
    this->unk9E4 = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &spC8), *((MKVector4 *) &spB8), 5.0f, lit_938, lit_939);
    temp_r4_5681 = this->unk9E4;
    if (temp_r4_5681 != NULL) {
        temp_r4_5681->unk31 &= ~0x40;
    }
    var_r27_5689 = 0;
    var_r30_5690 = 0;
    do {
        ((Zap *) (this->unkA8 + var_r30_5690))->Resolve();
        var_r27_5689 += 1;
        var_r30_5690 += 0x1D0;
    } while (var_r27_5689 < 3);
    var_r27_5703 = 0;
    var_r30_5704 = 0;
    do {
        sp28 = 1.0f;
        sp2C = 1.0f;
        sp30 = 1.0f;
        sp34 = 1.0f;
        spA8 = (f64) sp28;
        spB0 = (f64) sp30;
        ((ShapedTrailFX *) (*(this->unkAC + (var_r30_5704 + 0x54))))->InitData(this->unkE0, lit_951, "fx_341", lit_952, *((MKVector4 *) &spA8), 2.0f, 0U, 0.4f);
        sp20 = 0.0f;
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 0.0f;
        sp14 = 1.0f;
        sp18 = 0.0f;
        sp1C = 0.0f;
        sp88 = (f64) sp8;
        sp90 = (f64) sp10;
        sp98 = (f64) sp18;
        spA0 = (f64) sp20;
        temp_r0_5749 = var_r30_5704 + 0x58;
        *(this->unkAC + temp_r0_5749) = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp98), *((MKVector4 *) &sp88), 1.0f, lit_955, lit_956);
        temp_r4_5752 = *(this->unkAC + temp_r0_5749);
        if (temp_r4_5752 != NULL) {
            M2C_FIELD(temp_r4_5752, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r4_5752, u8 *, 0x31) & ~0x40);
        }
        var_r27_5703 += 1;
        var_r30_5704 += 0x90;
    } while (var_r27_5703 < 0xA);
    this->unkFC = checked_cast<MKPropDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s8 *), 0x5C)(gMK, "ZapCage"));
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ZapBreathFX::Init() {
    MKHeap *temp_r3_5802;
    MKHeap *temp_r3_5857;
    s32 temp_r0_5824;
    s32 var_r28_5817;
    s32 var_r28_5876;
    s32 var_r28_5967;
    s32 var_r30_5816;
    s32 var_r30_5875;
    s32 var_r30_5968;
    void *temp_r6_5902;
    void *temp_r9_5907;
    void *var_r3_5809;
    void *var_r3_5864;

    BaseBreathFX::Init();
    this->unkC9 = 0;
    this->unk104 = 0.5f;
    temp_r3_5802 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_5802 != NULL) {
        var_r3_5809 = ((MKHeap *) (temp_r3_5802->Current()))->Alloc(0x570, NULL, 0);
    } else {
        var_r3_5809 = malloc(0x570);
    }
    this->unkA8 = var_r3_5809;
    var_r30_5816 = 0;
    var_r28_5817 = 0;
    do {
        ((Zap *) (this->unkA8 + var_r28_5817))->Init();
        var_r30_5816 += 1;
        temp_r0_5824 = var_r28_5817 + 0x1B4;
        var_r28_5817 += 0x1D0;
        *(this->unkA8 + temp_r0_5824) = M2C_FIELD(this->unk0, s32 *, 0x38);
    } while (var_r30_5816 < 3);
    M2C_FIELD(this->unkA8, f32 *, 0x37C) = 3.1415927f;
    M2C_FIELD(this->unkA8, f32 *, 0x54C) = 1.5707964f;
    M2C_FIELD(this->unkA8, f32 *, 0x1B8) = 2.0f;
    M2C_FIELD(this->unkA8, f32 *, 0x388) = 1.0f;
    M2C_FIELD(this->unkA8, f32 *, 0x558) = 0.7f;
    this->unkB4.Init(0x64, 0U);
    this->unkC8 = 0;
    this->unkDC = 0.0f;
    this->unk9E4 = NULL;
    this->unkB0 = NULL;
    this->unkAC = NULL;
    temp_r3_5857 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_5857 != NULL) {
        var_r3_5864 = ((MKHeap *) (temp_r3_5857->Current()))->Alloc(0x5A0, NULL, 0);
    } else {
        var_r3_5864 = malloc(0x5A0);
    }
    this->unkAC = var_r3_5864;
    var_r30_5875 = 0;
    var_r28_5876 = 0;
    do {
        gMK->CreatePropDeferred("ShapedTrailFX", this->unkAC + (var_r28_5876 + 0x54));
        *(this->unkAC + (var_r28_5876 + 0x60)) = 0;
        *(this->unkAC + (var_r28_5876 + 0x40)) = 0.0f;
        *(this->unkAC + (var_r28_5876 + 0x50)) = 0;
        temp_r6_5902 = this->unkAC + var_r28_5876;
        M2C_FIELD(temp_r6_5902, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r6_5902, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_5902, f32 *, 8) = 0.0f;
        temp_r9_5907 = this->unkAC + (var_r28_5876 + 0x10);
        M2C_FIELD(temp_r9_5907, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r9_5907, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r9_5907, f32 *, 8) = 0.0f;
        *(this->unkAC + (var_r28_5876 + 0x44)) = 0.0f;
        *(this->unkAC + (var_r28_5876 + 0x48)) = 1.0f;
        *(this->unkAC + (var_r28_5876 + 0x5C)) = 0;
        ((KDSoundFader *) (this->unkAC + (var_r28_5876 + 0x64)))->Init(0.25f, 0.25f);
        var_r30_5875 += 1;
        var_r28_5876 += 0x90;
    } while (var_r30_5875 < 0xA);
    gMK->CreatePropDeferred("ZapPS", (MKProp **) &this->unkCC);
    this->unkD0 = 0.0f;
    this->unkD4 = 0.0f;
    this->unkD8 = 0.0f;
    this->unkE0 = MKModel_Create("IceShard", NULL, 2, NULL);
    M2C_FIELD(this, f32 *, 0xE8) = 1.0f;
    M2C_FIELD(this, f32 *, 0xEC) = 1.0f;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF4) = 1.0f;
    this->unkF8 = 1.0f;
    gMK->CreatePropDeferred("ZapMissileImpactPS", (MKProp **) &this->unk9E0);
    gMK->CreatePropDeferred("FuryFXElectricity", (MKProp **) &this->unk9EC);
    gMK->CreatePropDeferred("FuryFXElectricity2", (MKProp **) &this->unk9F0);
    var_r28_5967 = 0;
    var_r30_5968 = 0;
    do {
        ((ElectricBeam *) (this + (var_r30_5968 + 0x1C0)))->Init();
        var_r28_5967 += 1;
        var_r30_5968 += 0x200;
    } while (var_r28_5967 < 4);
    this->unk9E0 = 0;
    this->unk9E8 = 0.0f;
    this->unk9E4 = NULL;
    this->unk9F4 = NULL;
    gMK->CreatePropDeferred("ScorchTrail", (MKProp **) &this->unk9F8);
    gMK->CreatePropDeferred("ScorchTrail", (MKProp **) &this->unk9FC);
    this->unkA00 = 0.0f;
    this->unkA04 = 0.0f;
}
#endif

void Zap::Deinit() {
    this->unk0.Deinit();
    ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(this->unk1BC);
    ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(this->unk1C0);
    this->unk1BC = NULL;
    this->unk1C0 = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Zap::Resolve() {
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
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r4_6072;
    Corona *temp_r4_6106;

    sp40 = 0.0f;
    sp28 = 1.0f;
    sp2C = 1.0f;
    sp30 = 0.4f;
    sp34 = 1.0f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp68 = (f64) sp28;
    sp70 = (f64) sp30;
    sp78 = (f64) sp38;
    sp80 = (f64) sp40;
    this->unk1BC = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp78), *((MKVector4 *) &sp68), 5.0f, lit_781, lit_782);
    temp_r4_6072 = this->unk1BC;
    if (temp_r4_6072 != NULL) {
        temp_r4_6072->unk31 &= ~0x40;
    }
    sp20 = 0.0f;
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 0.4f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    sp58 = (f64) sp18;
    sp60 = (f64) sp20;
    this->unk1C0 = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp58), *((MKVector4 *) &sp48), 5.0f, lit_786, lit_787);
    temp_r4_6106 = this->unk1C0;
    if (temp_r4_6106 != NULL) {
        temp_r4_6106->unk31 &= ~0x40;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void Zap::Init() {
    f32 var_f0_6153;
    s32 var_r28_6139;
    s32 var_r31_6141;
    void *temp_r29_6146;

    this->unk0.Init(8, 0U);
    var_r28_6139 = 0;
    var_r31_6141 = 0;
    do {
        temp_r29_6146 = this + var_r31_6141;
        M2C_FIELD(temp_r29_6146, f32 *, 0x44) = 0.0f;
        var_f0_6153 = (f32) var_r28_6139 / 7.0f;
        if (var_f0_6153 < 1.0f) {

        } else {
            var_f0_6153 = 1.0f;
        }
        if (var_f0_6153 > 0.0f) {

        } else {
            var_f0_6153 = 0.0f;
        }
        M2C_FIELD(temp_r29_6146, f32 *, 0x40) = var_f0_6153;
        M2C_FIELD(temp_r29_6146, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r29_6146, f32 *, 0x24) = 0.0f;
        M2C_FIELD(temp_r29_6146, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r29_6146, f32 *, 0x30) = 0.0f;
        M2C_FIELD(temp_r29_6146, f32 *, 0x34) = 0.0f;
        M2C_FIELD(temp_r29_6146, f32 *, 0x38) = 0.0f;
        var_r28_6139 += 1;
        M2C_FIELD(temp_r29_6146, f32 *, 0x48) = MKRand_Float(&gViewSeed, 5.0f, 10.0f);
        var_r31_6141 += 0x30;
    } while (var_r28_6139 < 8);
    this->unk1A0 = 0;
    this->unk1A4 = 0.0f;
    this->unk1A8 = MKRand_Float(&gViewSeed, 0.05f, 0.25f);
    this->unk1AC = 0.0f;
    this->unk1B0 = MKRand_Float(&gViewSeed, 3.1415927f, 6.2831855f);
    this->unk1B8 = 1.0f;
    this->unk1C8 = 0.0f;
    this->unk1BC = NULL;
    this->unk1C0 = NULL;
}
#endif

void ZapBreathFX_cpp::__sinit() {
    f32 temp_f0_6266;
    f64 temp_f1_6247;
    f64 temp_f1_6255;
    f64 temp_f3_6235;
    f64 temp_f4_6244;
    f64 temp_f4_6252;
    f64 temp_f8_6237;

    temp_f3_6235 = __frsqrte(2014000.0);
    temp_f8_6237 = __frsqrte(380000.0);
    temp_f4_6244 = 0.5 * temp_f3_6235 * -((2014000.0 * (temp_f3_6235 * temp_f3_6235)) - 3.0);
    temp_f1_6247 = 0.5 * temp_f8_6237 * -((380000.0 * (temp_f8_6237 * temp_f8_6237)) - 3.0);
    temp_f4_6252 = 0.5 * temp_f4_6244 * -((2014000.0 * (temp_f4_6244 * temp_f4_6244)) - 3.0);
    temp_f1_6255 = 0.5 * temp_f1_6247 * -((380000.0 * (temp_f1_6247 * temp_f1_6247)) - 3.0);
    temp_f0_6266 = (f32) (380000.0 * (0.5 * temp_f1_6255 * -((380000.0 * (temp_f1_6255 * temp_f1_6255)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6252 * -((2014000.0 * (temp_f4_6252 * temp_f4_6252)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_6266;
}

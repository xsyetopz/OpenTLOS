#include "spyro/source/FuryFXElectricity2.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Character.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapArcFX.h"
#include "spyro/source/ZapPS.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void ****);                            /* extern */
void ****malloc(M2C_UNK);                           /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_781 = 0;
static u8 lit_782 = 1;

static u8 lit_817 = 1;

static u8 lit_895 = 1;
static u8 lit_898 = 1;

void FuryFXElectricity2::ResetFury() {
    SetDefaults();
    ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unkA8, 0U);
    DestroyAllLightningCages();
loop_2:
    if ((void ***) *this->unk124 != NULL) {
        this->unk124 += 4;
        goto loop_2;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'double *' to
void FuryFXElectricity2::DestroyAllLightningCages() {
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_134;
    f32 temp_f2_119;
    f32 temp_f2_125;
    f64 temp_f0_154;
    f64 temp_f1_148;
    void ****temp_r3_170;
    void ****var_r30_99;
    void ***temp_r31_181;
    void ***temp_r4_173;
    void **temp_r3_114;
    void **temp_r3_129;
    void **temp_r3_135;
    void *temp_r3_147;

    var_r30_99 = this->unk124;
loop_2:
    if (var_r30_99 != NULL) {
        temp_r31_181 = *var_r30_99;
        if (temp_r31_181 != NULL) {
            sp10 = 1.0f;
            sp14 = 1.0f;
            sp18 = 1.0f;
            sp1C = 1.0f;
            sp50 = (f64) sp10;
            sp58 = (f64) sp18;
            temp_r3_114 = *temp_r31_181;
            temp_f2_119 = M2C_FIELD(*temp_r3_114, f32 (**)(void **, f64), 0x3C)(temp_r3_114, (f64) sp10) / 100.0f;
            sp28 = 0.0f;
            sp20 = 0.0f;
            sp24 = 0.0f;
            temp_f2_125 = 60.0f * temp_f2_119;
            sp60 = (f64) sp20;
            sp68 = (f64) sp28;
            sp8 = temp_f2_125;
            temp_r3_129 = *temp_r31_181;
            temp_f1_134 = 0.5f * M2C_FIELD(*temp_r3_129, f32 (**)(void **, f64, f32), 0x3C)(temp_r3_129, (f64) sp20, temp_f2_125);
            temp_r3_135 = *temp_r31_181;
            sp48 = 0.0f;
            sp40 = 0.0f;
            sp44 = temp_f1_134;
            sp78 = (f64) sp48;
            sp70 = (f64) sp40;
            temp_r3_147 = M2C_FIELD(M2C_FIELD(*temp_r3_135, void *(**)(void **, f64), 8)(temp_r3_135, (f64) sp40), void **, 8);
            temp_f1_148 = M2C_FIELD(temp_r3_147, f64 *, 0x30);
            sp80 = temp_f1_148;
            sp88 = M2C_FIELD(temp_r3_147, f64 *, 0x38);
            temp_f0_154 = temp_f1_148 + sp70;
            sp30 = temp_f0_154;
            sp90 = temp_f0_154;
            sp38 = (f32) sp88 + (f32) sp78;
            sp98 = (f64) sp38;
            this->unkAC->Emit(*((MKVector3 *) &sp90), *((MKVector3 *) &sp60), sp8, (MKVector4) &sp50);
            temp_r3_170 = this->unk124;
            this->unk124 = temp_r3_170 + 4;
            temp_r4_173 = *temp_r3_170;
            *temp_r3_170 = *var_r30_99;
            *var_r30_99 = temp_r4_173;
            var_r30_99 += 4;
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void FuryFXElectricity2::SpawnLightningCages() {
    f64 sp38;
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    TargetManager ***var_r29_214;
    TargetManager **temp_r30_369;
    f32 var_f3_345;
    f32 var_f4_278;
    f64 temp_f1_253;
    f64 temp_f1_284;
    f64 temp_f1_290;
    f64 temp_f1_294;
    s32 temp_r3_313;
    s32 var_r0_323;
    void *temp_r3_252;

    var_r29_214 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_28:
    if (var_r29_214 != NULL) {
        temp_r30_369 = *var_r29_214;
        if (temp_r30_369 != NULL) {
            if (((*temp_r30_369)->unk8.unk0(temp_r30_369) != NULL) && (M2C_FIELD(*temp_r30_369, u8 (**)(TargetManager **), 0x18)(temp_r30_369) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r30_369)->unk8.unk4)(temp_r30_369) == 0U) || (((Character *) (((Character *(*)(TargetManager **)) (*temp_r30_369)->unk8.unk4)(temp_r30_369)))->IsActive() != 0))) {
                temp_r3_252 = M2C_FIELD((*temp_r30_369)->unk8.unk0(temp_r30_369), void **, 8);
                temp_f1_253 = M2C_FIELD(temp_r3_252, f64 *, 0x30);
                sp20 = temp_f1_253;
                sp28 = M2C_FIELD(temp_r3_252, f64 *, 0x38);
                sp10 = temp_f1_253 - this->unk98;
                sp30 = sp10;
                sp18 = (f32) sp28 - this->unkA0;
                sp38 = (f64) sp18;
                var_f4_278 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp28 + 0xc)) * (*(f32 *) ((u8 *) &sp28 + 0xc))));
                if (var_f4_278 > 0.000001f) {
                    if (var_f4_278 > 0.0f) {
                        temp_f1_284 = __frsqrte(var_f4_278);
                        temp_f1_290 = 0.5 * temp_f1_284 * -(((f64) var_f4_278 * (temp_f1_284 * temp_f1_284)) - 3.0);
                        temp_f1_294 = 0.5 * temp_f1_290 * -(((f64) var_f4_278 * (temp_f1_290 * temp_f1_290)) - 3.0);
                        var_f4_278 = (f32) ((f64) var_f4_278 * (0.5 * temp_f1_294 * -(((f64) var_f4_278 * (temp_f1_294 * temp_f1_294)) - 3.0)));
                    } else if (var_f4_278 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_278 = __float_nan;
                    } else {
                        sp8 = var_f4_278;
                        temp_r3_313 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_313) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_323 = 1;
                            } else {
                                var_r0_323 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_323 = 5;
                            } else {
                                var_r0_323 = 3;
                            }
                            break;
                        default:
                            var_r0_323 = 4;
                            break;
                        }
                        if (var_r0_323 == 1) {
                            var_f4_278 = __float_nan;
                        }
                    }
                    var_f3_345 = 1.0f / var_f4_278;
                } else {
                    var_f3_345 = 0.0f;
                    var_f4_278 = 0.0f;
                }
                sp30 = (f32) sp30 * var_f3_345;
                (*(f32 *) ((u8 *) &sp28 + 0xc)) *= var_f3_345;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if (var_f4_278 == 3000.0f) {
                    SpawnLightningCage((Targetable *) temp_r30_369);
                }
            }
            var_r29_214 += 4;
            goto loop_28;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void FuryFXElectricity2::SpawnLightningCage(Targetable *arg0) {
    void ****temp_r5_383;
    void ****temp_r5_387;
    void ***temp_r3_389;

    temp_r5_383 = this->unk124;
    if ((u32) M2C_FIELD(temp_r5_383, u32 *, -4) != 0U) {
        temp_r5_387 = temp_r5_383 - 4;
        this->unk124 = temp_r5_387;
        temp_r3_389 = *temp_r5_387;
        if (temp_r3_389 != NULL) {
            M2C_FIELD(temp_r3_389, void ***, 0) = &arg0->__vptr;
            M2C_FIELD(temp_r3_389, f32 *, 4) = 0.0f;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void FuryFXElectricity2::UpdateLightningCages() {
    BreathHitMessage sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;                                      /* compiler-managed */
    f64 sp148;                                      /* compiler-managed */
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKProp *temp_r4_648;
    f32 temp_f0_495;
    f32 temp_f1_445;
    f32 temp_f1_464;
    f32 temp_f1_479;
    f32 temp_f1_489;
    f32 temp_f21_693;
    f32 temp_f22_698;
    f32 var_f4_540;
    f32 var_f6_607;
    f64 temp_f0_474;
    f64 temp_f0_511;
    f64 temp_f0_523;
    f64 temp_f0_712;
    f64 temp_f1_456;
    f64 temp_f1_546;
    f64 temp_f1_552;
    f64 temp_f1_556;
    s32 temp_r3_575;
    s32 var_r0_585;
    void ****var_r29_429;
    void ***temp_r30_768;
    void **temp_r3_449;
    void **temp_r3_455;
    void **temp_r3_484;
    void **temp_r3_658;
    void **temp_r3_668;
    void *temp_r27_673;
    void *temp_r4_454;

    var_r29_429 = this->unk124;
loop_24:
    if (var_r29_429 != NULL) {
        temp_r30_768 = *var_r29_429;
        if (temp_r30_768 != NULL) {
            M2C_FIELD(temp_r30_768, f32 *, 4) = (f32) (M2C_FIELD(temp_r30_768, f32 *, 4) - gUpdateTimeDelta);
            temp_f1_445 = this->unk120;
            this->unk120 = temp_f1_445 + gUpdateTimeDelta;
            temp_r3_449 = M2C_FIELD(temp_r30_768, void ***, 0);
            temp_r4_454 = M2C_FIELD(M2C_FIELD(*temp_r3_449, void *(**)(void **, f32), 8)(temp_r3_449, temp_f1_445), void **, 8);
            temp_r3_455 = M2C_FIELD(temp_r30_768, void ***, 0);
            temp_f1_456 = M2C_FIELD(temp_r4_454, f64 *, 0x30);
            sp178 = temp_f1_456;
            sp180 = M2C_FIELD(temp_r4_454, f64 *, 0x38);
            temp_f1_464 = 3.0f * M2C_FIELD(*temp_r3_455, f32 (**)(void **, void *, f64), 0x3C)(temp_r3_455, temp_r4_454, temp_f1_456);
            spC0 = 0.0f;
            spB8 = 0.0f;
            spBC = temp_f1_464;
            sp130 = (f64) spC0;
            sp128 = (f64) spB8;
            temp_f0_474 = temp_f1_456 + sp128;
            spA8 = temp_f0_474;
            temp_f1_479 = (f32) sp180 + (f32) sp130;
            sp168 = temp_f0_474;
            spB0 = temp_f1_479;
            sp170 = (f64) spB0;
            temp_r3_484 = M2C_FIELD(temp_r30_768, void ***, 0);
            temp_f1_489 = 2.0f * M2C_FIELD(*temp_r3_484, f32 (**)(void **, f32, f32), 0x38)(temp_r3_484, temp_f1_479, (f32) sp180);
            sp8C = 0.0f;
            sp9C = 0.0f;
            temp_f0_495 = -temp_f1_489;
            sp88 = temp_f1_489;
            sp90 = temp_f1_489;
            sp98 = temp_f0_495;
            spA0 = temp_f0_495;
            spF8 = (f64) sp88;
            sp100 = (f64) sp90;
            sp108 = (f64) sp98;
            sp110 = (f64) spA0;
            KDRand_Vector(sp118, *((MKVector3 *) &sp108));
            temp_f0_511 = sp178 + M2C_BITWISE(f64, sp118);
            sp78 = temp_f0_511;
            sp158 = temp_f0_511;
            sp80 = (f32) sp180 + sp118.unk8;
            sp160 = (f64) sp80;
            temp_f0_523 = sp158 - sp168;
            sp68 = temp_f0_523;
            sp148 = temp_f0_523;
            sp70 = (f32) sp160 - (f32) sp170;
            sp150 = (f64) sp70;
            var_f4_540 = ((f32) sp150 * (f32) sp150) + (((f32) sp148 * (f32) sp148) + ((*(f32 *) ((u8 *) &sp140 + 0xc)) * (*(f32 *) ((u8 *) &sp140 + 0xc))));
            if (var_f4_540 > 0.000001f) {
                if (var_f4_540 > 0.0f) {
                    temp_f1_546 = __frsqrte(var_f4_540);
                    temp_f1_552 = 0.5 * temp_f1_546 * -(((f64) var_f4_540 * (temp_f1_546 * temp_f1_546)) - 3.0);
                    temp_f1_556 = 0.5 * temp_f1_552 * -(((f64) var_f4_540 * (temp_f1_552 * temp_f1_552)) - 3.0);
                    var_f4_540 = (f32) ((f64) var_f4_540 * (0.5 * temp_f1_556 * -(((f64) var_f4_540 * (temp_f1_556 * temp_f1_556)) - 3.0)));
                } else if (var_f4_540 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_540 = __float_nan;
                } else {
                    sp10 = var_f4_540;
                    temp_r3_575 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_575) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_585 = 1;
                        } else {
                            var_r0_585 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_585 = 5;
                        } else {
                            var_r0_585 = 3;
                        }
                        break;
                    default:
                        var_r0_585 = 4;
                        break;
                    }
                    if (var_r0_585 == 1) {
                        var_f4_540 = __float_nan;
                    }
                }
                var_f6_607 = 1.0f / var_f4_540;
            } else {
                var_f6_607 = 0.0f;
                var_f4_540 = 0.0f;
            }
            sp58 = 1.0f;
            sp5C = 1.0f;
            sp60 = 0.2f;
            sp64 = 1.0f;
            sp148 = (f32) sp148 * var_f6_607;
            (*(f32 *) ((u8 *) &sp140 + 0xc)) *= var_f6_607;
            sp150 = (f32) sp150 * var_f6_607;
            sp14 = 1.5f * (var_f4_540 / 500.0f);
            spE8 = (f64) sp58;
            spF0 = (f64) sp60;
            ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &sp168), *((MKVector3 *) &sp148), sp14, lit_895, (MKVector4) &spE8);
            sp188.unk4 = 0;
            temp_r4_648 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0));
            sp8 = -1;
            sp188.Init(temp_r4_648, 0, 0, 0, 1, 1, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            temp_r3_658 = M2C_FIELD(temp_r30_768, void ***, 0);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(*temp_r3_658, void *(**)(void **), 8)(temp_r3_658), void **, 0x44), M2C_UNK (**)(BreathHitMessage *), 0x2C)(&sp188);
            temp_r3_668 = M2C_FIELD(temp_r30_768, void ***, 0);
            temp_r27_673 = M2C_FIELD(*temp_r3_668, void *(**)(void **), 8)(temp_r3_668);
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.0f, 0.5f, 0.15f, M2C_FIELD(temp_r27_673, s32 *, 8) + 0x30, 37.0f, 0, 4.0f, 0U);
            temp_f21_693 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f22_698 = MKRand_Float(&gViewSeed, 1.0f, 2.5f);
            sp48 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp4C = temp_f22_698;
            sp50 = temp_f21_693;
            spD8 = (f64) sp48;
            spE0 = (f64) sp50;
            temp_f0_712 = spD8 * 5.64367472e-315;
            sp38 = temp_f0_712;
            sp138 = temp_f0_712;
            sp40 = (f32) spE0 * 600.0f;
            sp140 = (f64) sp40;
            ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &sp158), *((MKVector3 *) &sp138), MKRand_Float(&gViewSeed, 0.5f, 1.0f), 0U);
            if (M2C_FIELD(temp_r30_768, f32 *, 4) <= 0.0f) {
                sp30 = 0.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                sp20 = 0.2f;
                sp24 = 1.0f;
                sp28 = 0.0f;
                sp2C = 1.0f;
                spE8 = (f64) sp18;
                spF0 = (f64) sp20;
                spC8 = (f64) sp28;
                spD0 = (f64) sp30;
                ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &sp168), *((MKVector3 *) &spC8), sp14, lit_898, (MKVector4) &spE8);
                M2C_FIELD(temp_r30_768, f32 *, 4) = MKRand_Float(&gViewSeed, 0.05f, 0.125f);
            }
            var_r29_429 += 4;
            goto loop_24;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
s32 FuryFXElectricity2::Trigger(const MKVector3 &arg0) {
    s8 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    f32 sp88;
    s32 sp84;
    s8 sp83;
    s8 sp82;
    s16 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_917;
    s32 temp_r0_837;
    s32 temp_r28_860;
    s32 temp_r3_835;
    s32 var_r29_853;
    u8 var_r3_843;
    void *temp_r5_839;

    if ((s32) this->unk90 != 0) {
        return 0;
    }
    this->unk108 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk110 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk98 = this->unk108;
    M2C_FIELD(this, f64 *, 0xA0) = (f64) this->unk110;
    this->unk90 = 1;
    this->unk94 = 1.0f;
    this->unk120 = 0.0f;
    this->unk11C = 0.0f;
    temp_r3_835 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_837 = *(&GameData::gameData[0x70] + (temp_r3_835 + 0x7C));
    temp_r5_839 = &GameData::gameData[0x70] + (temp_r3_835 + 0x64);
    if (temp_r0_837 == 3) {
        var_r3_843 = 0;
        if (((s32) M2C_FIELD(temp_r5_839, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_839, s32 *, 4) == 3)) {
            var_r3_843 = 1;
        }
        var_r29_853 = var_r3_843 != 0;
    } else {
        var_r29_853 = *(temp_r5_839 + (temp_r0_837 * 4));
    }
    temp_r28_860 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unkB0.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), 15.0f * M2C_FIELD(&gb, f32 *, 0x37C), 3, var_r29_853, temp_r28_860, temp_r28_860, 0, -1);
    sp18 = 0.0f;
    sp1C = -5000.0f;
    sp20 = 0.0f;
    sp28 = (f64) sp18;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp60 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0;
    sp82 = 0;
    sp83 = 0;
    sp84 = 0;
    sp88 = 3.4028235e38f;
    sp8C = 0;
    sp90 = 0;
    sp94 = -1;
    sp98 = 0;
    sp30 = (f64) sp20;
    temp_f0_917 = M2C_FIELD(&arg0, f64 *, 0) + sp28;
    sp8 = temp_f0_917;
    sp38 = temp_f0_917;
    sp10 = arg0.unk8 + (f32) sp30;
    sp40 = (f64) sp10;
    if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp38), (MKCollisionResult *) &sp48, (MKCollisionMode) 4, 0x0C000000) != 0) {
        this->unk108 = (f64) sp48;
        this->unk110 = (f64) sp50;
    }
    M2C_FIELD(&gb, s8 *, 0x381) = 1;
    return 1;
}
#endif

void FuryFXElectricity2::SetDefaults() {
    SetDefaults();
    this->unk90 = 0;
    this->unk11C = -1.0f;
    this->unk94 = 0.0f;
}

#if 0 // DRAFT: type mismatch
void FuryFXElectricity2::Deinit() {
    MKHeap *temp_r3_1010;
    ManagedLight *temp_r4_1025;
    u32 temp_r0_993;
    void ****var_r31_984;
    void ****var_r3_985;
    void ****var_r4_983;
    void ***temp_r0_1007;
    void ***temp_r0_988;

    var_r4_983 = this->unk124;
    var_r31_984 = var_r4_983;
    var_r3_985 = var_r4_983;
loop_3:
    temp_r0_993 = M2C_FIELD(var_r3_985, u32 *, -4);
    var_r3_985 -= 4;
    if (temp_r0_993 != 0U) {
        temp_r0_988 = *var_r3_985;
        if (temp_r0_988 < var_r31_984) {
            var_r31_984 = (void ****) temp_r0_988;
        }
        goto loop_3;
    }
    if (var_r3_985 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1007 = *var_r4_983;
        if (temp_r0_1007 != NULL) {
            if (temp_r0_1007 < var_r31_984) {
                var_r31_984 = (void ****) temp_r0_1007;
            }
            var_r4_983 += 4;
            goto loop_9;
        }
        temp_r3_1010 = ((MKHeap *) var_r3_985)->Current();
        if (temp_r3_1010 != NULL) {
            ((MKHeap *) (temp_r3_1010->Current()))->Free(var_r31_984, NULL, 0);
        } else {
            free(var_r31_984);
        }
    }
    this->unk124 = NULL;
    temp_r4_1025 = this->unkA8;
    if (temp_r4_1025 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_1025);
    }
    FuryFX::Deinit();
}
#endif

void FuryFXElectricity2::Draw() {

}

#if 0 // DRAFT: undefined identifier 'MKVector'
void FuryFXElectricity2::Update() {
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp190;
    MKVector3 sp180;
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
    f64 sp128;
    f64 sp120;
    f64 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
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
    f64 sp10;
    f32 sp8;
    ManagedLight *temp_r3_1171;
    ManagedLight *temp_r3_1184;
    ManagedLight *temp_r3_1239;
    ManagedLight *temp_r3_1259;
    ManagedLight *temp_r3_1395;
    ManagedLight *temp_r3_1415;
    ManagedLight *temp_r3_1650;
    ManagedLight *temp_r4_1149;
    ManagedLight *temp_r4_1628;
    ManagedLight *temp_r4_1690;
    f32 temp_f1_1061;
    f32 temp_f1_1261;
    f32 temp_f1_1417;
    f32 temp_f1_1452;
    f32 temp_f30_1221;
    f32 var_f0_1655;
    f32 var_f1_1201;
    f32 var_f1_1290;
    f32 var_f3_1527;
    f32 var_f4_1460;
    f64 temp_f0_1358;
    f64 temp_f0_1370;
    f64 temp_f1_1466;
    f64 temp_f1_1472;
    f64 temp_f1_1476;
    s32 temp_r0_1125;
    s32 temp_r3_1495;
    s32 var_r0_1505;
    void *temp_r3_1177;
    void *temp_r3_1187;
    void *temp_r3_1245;
    void *temp_r3_1263;
    void *temp_r3_1401;
    void *temp_r3_1419;
    void *temp_r3_1643;
    void *temp_r3_1670;

    temp_f1_1061 = this->unk11C;
    if (temp_f1_1061 >= 0.0f) {
        this->unk11C = temp_f1_1061 + gUpdateTimeDelta;
        if (((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0x3C)(M2C_FIELD(&gb, void ***, 0)), void **, 4), void **, 0xB4), u8 *, 0x16) != 0) && ((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0x3C)(M2C_FIELD(&gb, void ***, 0)), void **, 4), void **, 0xB4), u8 *, 0x17) != 0) && (this->unk11C <= 7.0f)) {
            ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay(0.0f, 0.5f, 0.15f, 0, 4.0f, 0U);
        }
        if (this->unk11C > 7.0f) {
            this->unk11C = -1.0f;
        }
    }
    UpdateLightningCages();
    this->unk94 -= gUpdateTimeDelta;
    temp_r0_1125 = this->unk90;
    switch (temp_r0_1125) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        if ((this->unk94 <= 0.0f) && (this->unk90 = 2, this->unk94 = 0.8f, temp_r4_1149 = this->unkA8, ((temp_r4_1149 == NULL) == 0))) {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1149, 1U);
            MKVector(0.0f, 300.0f, 0.0f);
            sp50 = this->unk98 + sp230;
            temp_r3_1171 = this->unkA8;
            sp240 = sp50;
            sp58 = this->unkA0 + sp238;
            temp_r3_1171->unk10 = sp50;
            temp_r3_1171->unk18 = (f64) sp58;
            temp_r3_1177 = temp_r3_1171->unk3C;
            sp248 = (f64) sp58;
            if (temp_r3_1177 != NULL) {
                M2C_FIELD(temp_r3_1177, f64 *, 0x10) = sp50;
                M2C_FIELD(temp_r3_1177, f64 *, 0x18) = (f64) sp58;
            }
            temp_r3_1184 = this->unkA8;
            temp_r3_1184->unk38 = 1000.0f;
            temp_r3_1187 = temp_r3_1184->unk3C;
            if (temp_r3_1187 != NULL) {
                M2C_FIELD(temp_r3_1187, f32 *, 0x20) = 1000.0f;
                M2C_FIELD(temp_r3_1187, f32 *, 0x24) = 1000000.0f;
                M2C_FIELD(temp_r3_1187, f32 *, 0x28) = 0.001f;
                M2C_FIELD(temp_r3_1187, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1187, f32 *, 0x24));
                return;
            }
        } else {
        case 0:                                     /* switch 1 */
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        var_f1_1201 = this->unk94;
        if (var_f1_1201 < 0.8f) {

        } else {
            var_f1_1201 = 0.8f;
        }
        if (var_f1_1201 > 0.0f) {

        } else {
            var_f1_1201 = 0.0f;
        }
        temp_f30_1221 = 1.0f - (var_f1_1201 / 0.8f);
        if ((ManagedLight *) this->unkA8 != NULL) {
            MKVector(0.0f, (400.0f * temp_f30_1221) + 25.0f, 0.0f);
            sp40 = this->unk98 + sp210;
            temp_r3_1239 = this->unkA8;
            sp220 = sp40;
            sp48 = this->unkA0 + sp218;
            temp_r3_1239->unk10 = sp40;
            temp_r3_1239->unk18 = (f64) sp48;
            temp_r3_1245 = temp_r3_1239->unk3C;
            sp228 = (f64) sp48;
            if (temp_r3_1245 != NULL) {
                M2C_FIELD(temp_r3_1245, f64 *, 0x10) = sp40;
                M2C_FIELD(temp_r3_1245, f64 *, 0x18) = (f64) sp48;
            }
            temp_r3_1259 = this->unkA8;
            temp_f1_1261 = (1.0f + temp_f30_1221) * (1000.0f * MKRand_Float(&gViewSeed, 1.0f, 1.2f));
            temp_r3_1259->unk38 = temp_f1_1261;
            temp_r3_1263 = temp_r3_1259->unk3C;
            if (temp_r3_1263 != NULL) {
                M2C_FIELD(temp_r3_1263, f32 *, 0x20) = temp_f1_1261;
                M2C_FIELD(temp_r3_1263, f32 *, 0x24) = (f32) (temp_f1_1261 * temp_f1_1261);
                M2C_FIELD(temp_r3_1263, f32 *, 0x28) = (f32) (1.0f / temp_f1_1261);
                M2C_FIELD(temp_r3_1263, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1263, f32 *, 0x24));
            }
        }
        if (this->unk94 <= 0.0f) {
            this->unk90 = 3;
            this->unk94 = 2.5f;
            this->unk118 = 1.0f;
            SpawnLightningCages();
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        var_f1_1290 = this->unk94;
        if (var_f1_1290 < 2.5f) {

        } else {
            var_f1_1290 = 2.5f;
        }
        if (var_f1_1290 > 0.0f) {

        } else {
            var_f1_1290 = 0.0f;
        }
        spE8 = -1.0f;
        spD8 = 1.0f;
        spE0 = -1.0f;
        spE4 = 0.0f;
        this->unk118 += 1.5f * gUpdateTimeDelta;
        spD0 = 1.0f;
        spD4 = 0.0f;
        sp1C0 = (f64) spE0;
        sp1C8 = (f64) spE8;
        sp1B0 = (f64) spD0;
        sp1B8 = (f64) spD8;
        KDRand_Vector(sp1D0, *((MKVector3 *) &sp1C0));
        spC0 = sp1D0 * 5.717499035e-315;
        sp100 = 0.0f;
        sp104 = 3000.0f;
        spC8 = sp1D0.unk8 * 2000.0f;
        sp108 = 0.0f;
        sp1F0 = (f64) sp100;
        sp1E0 = spC0;
        sp1E8 = (f64) spC8;
        sp1F8 = (f64) sp108;
        temp_f0_1358 = this->unk98 + sp1F0;
        spF0 = temp_f0_1358;
        sp200 = temp_f0_1358;
        spF8 = this->unkA0 + (f32) sp1F8;
        sp208 = (f64) spF8;
        temp_f0_1370 = sp200 + sp1E0;
        spB0 = temp_f0_1370;
        sp260 = temp_f0_1370;
        spB8 = (f32) sp208 + (f32) sp1E8;
        sp268 = (f64) spB8;
        if ((ManagedLight *) this->unkA8 != NULL) {
            MKVector(0.0f, 2500.0f, 0.0f);
            sp30 = sp260 - sp190;
            temp_r3_1395 = this->unkA8;
            sp1A0 = sp30;
            sp38 = (f32) sp268 - sp198;
            temp_r3_1395->unk10 = sp30;
            temp_r3_1395->unk18 = (f64) sp38;
            temp_r3_1401 = temp_r3_1395->unk3C;
            sp1A8 = (f64) sp38;
            if (temp_r3_1401 != NULL) {
                M2C_FIELD(temp_r3_1401, f64 *, 0x10) = sp30;
                M2C_FIELD(temp_r3_1401, f64 *, 0x18) = (f64) sp38;
            }
            temp_r3_1415 = this->unkA8;
            temp_f1_1417 = (1.0f + (1.0f - (var_f1_1290 / 2.5f))) * (1000.0f * MKRand_Float(&gViewSeed, 1.0f, 2.0f));
            temp_r3_1415->unk38 = temp_f1_1417;
            temp_r3_1419 = temp_r3_1415->unk3C;
            if (temp_r3_1419 != NULL) {
                M2C_FIELD(temp_r3_1419, f32 *, 0x20) = temp_f1_1417;
                M2C_FIELD(temp_r3_1419, f32 *, 0x24) = (f32) (temp_f1_1417 * temp_f1_1417);
                M2C_FIELD(temp_r3_1419, f32 *, 0x28) = (f32) (1.0f / temp_f1_1417);
                M2C_FIELD(temp_r3_1419, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1419, f32 *, 0x24));
            }
        }
        spA8 = -1.0f;
        sp98 = 1.0f;
        spA0 = -1.0f;
        spA4 = -1.0f;
        sp90 = 1.0f;
        sp94 = -0.5f;
        sp170 = (f64) spA0;
        sp178 = (f64) spA8;
        sp160 = (f64) sp90;
        sp168 = (f64) sp98;
        KDRand_Vector(sp180, *((MKVector3 *) &sp170));
        temp_f1_1452 = M2C_BITWISE(f32, sp180);
        var_f4_1460 = (sp180.unk8 * sp180.unk8) + ((temp_f1_1452 * temp_f1_1452) + (sp180.unk4 * sp180.unk4));
        if (var_f4_1460 > 1e-12f) {
            if (var_f4_1460 > 0.0f) {
                temp_f1_1466 = __frsqrte(var_f4_1460);
                temp_f1_1472 = 0.5 * temp_f1_1466 * -(((f64) var_f4_1460 * (temp_f1_1466 * temp_f1_1466)) - 3.0);
                temp_f1_1476 = 0.5 * temp_f1_1472 * -(((f64) var_f4_1460 * (temp_f1_1472 * temp_f1_1472)) - 3.0);
                var_f4_1460 = (f32) ((f64) var_f4_1460 * (0.5 * temp_f1_1476 * -(((f64) var_f4_1460 * (temp_f1_1476 * temp_f1_1476)) - 3.0)));
            } else if (var_f4_1460 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1460 = __float_nan;
            } else {
                sp8 = var_f4_1460;
                temp_r3_1495 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1495) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1505 = 1;
                    } else {
                        var_r0_1505 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1505 = 5;
                    } else {
                        var_r0_1505 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1505 = 4;
                    break;
                }
                if (var_r0_1505 == 1) {
                    var_f4_1460 = __float_nan;
                }
            }
            var_f3_1527 = 1.0f / var_f4_1460;
        } else {
            var_f3_1527 = 0.0f;
        }
        sp88 = sp180.unk8 * var_f3_1527;
        sp28 = 0.0f;
        sp258 = (f64) sp88;
        sp80 = M2C_BITWISE(f32, sp180) * var_f3_1527;
        sp84 = sp180.unk4 * var_f3_1527;
        sp20 = 0.0f;
        sp24 = -1.0f;
        sp250 = (f64) sp80;
        sp70 = 1.0f;
        sp74 = 1.0f;
        sp78 = 0.2f;
        sp7C = 1.0f;
        sp150 = (f64) sp20;
        sp158 = (f64) sp28;
        sp250 = (f64) sp20;
        sp258 = (f64) sp28;
        sp140 = (f64) sp70;
        sp148 = (f64) sp78;
        ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &sp260), *((MKVector3 *) &sp250), 10.0f, lit_817, (MKVector4) &sp140);
        if (this->unk94 <= 0.0f) {
            this->unk90 = 4;
            this->unk94 = 1.0f;
            this->unkB0.unk50 = 0;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32), 0x94)(gMK, &this->unkB0, 0, 0, &this->unk98, 1, 3000.0f);
            DestroyAllLightningCages();
            sp60 = 1.0f;
            sp64 = 1.0f;
            sp68 = 1.0f;
            sp6C = 1.0f;
            sp130 = (f64) sp60;
            sp138 = (f64) sp68;
            ((ScreenWobbleFX *) (&gb + 0xB8))->EnableScreenFlash(*((MKVector4 *) &sp130), 3.0f * gUpdateTimeDelta);
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        if ((ManagedLight *) this->unkA8 != NULL) {
            MKVector(0.0f, 2000.0f * gUpdateTimeDelta, 0.0f);
            temp_r4_1628 = this->unkA8;
            sp10 = temp_r4_1628->unk10 + sp110;
            temp_r4_1628->unk10 = sp10;
            sp18 = (f32) M2C_FIELD(temp_r4_1628, f64 *, 0x18) + sp118;
            sp120 = sp10;
            temp_r4_1628->unk18 = (f64) sp18;
            temp_r3_1643 = temp_r4_1628->unk3C;
            sp128 = (f64) sp18;
            if (temp_r3_1643 != NULL) {
                M2C_FIELD(temp_r3_1643, f64 *, 0x10) = sp10;
                M2C_FIELD(temp_r3_1643, f64 *, 0x18) = (f64) sp18;
            }
            temp_r3_1650 = this->unkA8;
            var_f0_1655 = -((500.0f * gUpdateTimeDelta) - temp_r3_1650->unk38);
            if (var_f0_1655 < 200000.0f) {

            } else {
                var_f0_1655 = 200000.0f;
            }
            if (var_f0_1655 > 0.0f) {

            } else {
                var_f0_1655 = 0.0f;
            }
            temp_r3_1650->unk38 = var_f0_1655;
            temp_r3_1670 = temp_r3_1650->unk3C;
            if (temp_r3_1670 != NULL) {
                M2C_FIELD(temp_r3_1670, f32 *, 0x20) = var_f0_1655;
                M2C_FIELD(temp_r3_1670, f32 *, 0x24) = (f32) (var_f0_1655 * var_f0_1655);
                M2C_FIELD(temp_r3_1670, f32 *, 0x28) = (f32) (1.0f / var_f0_1655);
                M2C_FIELD(temp_r3_1670, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1670, f32 *, 0x24));
            }
        }
        if (this->unk94 <= 0.0f) {
            this->unk90 = 0;
            temp_r4_1690 = this->unkA8;
            if (temp_r4_1690 != NULL) {
                ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1690, 0U);
            }
            M2C_FIELD(&gb, s8 *, 0x381) = 0;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void FuryFXElectricity2::Resolve() {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
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
    ManagedLight *temp_r4_1760;

    FuryFX::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp10 = 0.0f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unkA8 = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 300.0f, lit_781, lit_782);
    temp_r4_1760 = this->unkA8;
    if (temp_r4_1760 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1760, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void FuryFXElectricity2::Init() {
    MKHeap *temp_r3_1796;
    ZapPS *temp_r3_1794;
    s32 var_ctr_1816;
    void ****temp_r3_1818;
    void ****temp_r3_1824;
    void ****var_r3_1803;
    void ****var_r5_1812;

    FuryFX::Init();
    this->unk90 = 0;
    this->unk94 = 0.0f;
    this->unk11C = -1.0f;
    this->unkA8 = NULL;
    temp_r3_1794 = checked_cast<ZapPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("ZapPS"));
    this->unkAC = temp_r3_1794;
    temp_r3_1796 = ((MKHeap *) temp_r3_1794)->Current();
    if (temp_r3_1796 != NULL) {
        var_r3_1803 = ((MKHeap *) (temp_r3_1796->Current()))->Alloc(0xF8, NULL, 0);
    } else {
        var_r3_1803 = malloc(0xF8);
    }
    this->unk124 = var_r3_1803;
    var_r5_1812 = this->unk124;
    this->unk124 = var_r5_1812 + 0xA0;
    M2C_FIELD(var_r5_1812, s32 *, 0xA0) = 0;
    var_ctr_1816 = 0x14;
    do {
        temp_r3_1818 = this->unk124;
        this->unk124 = temp_r3_1818 + 4;
        M2C_FIELD(temp_r3_1818, void *****, 4) = var_r5_1812;
        var_r5_1812 += 8;
        var_ctr_1816 -= 1;
    } while (var_ctr_1816 != 0);
    temp_r3_1824 = this->unk124;
    this->unk124 = temp_r3_1824 + 4;
    M2C_FIELD(temp_r3_1824, void *****, 4) = NULL;
    this->unk128 = -1;
}
#endif

void FuryFXElectricity2_cpp::__sinit() {
    f32 temp_f0_1873;
    f64 temp_f1_1854;
    f64 temp_f1_1862;
    f64 temp_f3_1842;
    f64 temp_f4_1851;
    f64 temp_f4_1859;
    f64 temp_f8_1844;

    temp_f3_1842 = __frsqrte(2014000.0);
    temp_f8_1844 = __frsqrte(380000.0);
    temp_f4_1851 = 0.5 * temp_f3_1842 * -((2014000.0 * (temp_f3_1842 * temp_f3_1842)) - 3.0);
    temp_f1_1854 = 0.5 * temp_f8_1844 * -((380000.0 * (temp_f8_1844 * temp_f8_1844)) - 3.0);
    temp_f4_1859 = 0.5 * temp_f4_1851 * -((2014000.0 * (temp_f4_1851 * temp_f4_1851)) - 3.0);
    temp_f1_1862 = 0.5 * temp_f1_1854 * -((380000.0 * (temp_f1_1854 * temp_f1_1854)) - 3.0);
    temp_f0_1873 = (f32) (380000.0 * (0.5 * temp_f1_1862 * -((380000.0 * (temp_f1_1862 * temp_f1_1862)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1859 * -((2014000.0 * (temp_f4_1859 * temp_f4_1859)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1873;
}

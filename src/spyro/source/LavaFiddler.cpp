#include "spyro/source/LavaFiddler.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Critters.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Volume.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

#if 0 // DRAFT: illegal use of non-static member
void LavaFiddlerCritter::Deinit() {
    MKHeap *temp_r3_57;
    void *temp_r31_54;

    temp_r31_54 = this->unk170;
    if (temp_r31_54 != NULL) {
        temp_r3_57 = MKHeap::Current();
        if (temp_r3_57 != NULL) {
            ((MKHeap *) (temp_r3_57->Current()))->Free(temp_r31_54, NULL, 0);
        } else {
            free(temp_r31_54);
        }
    }
    this->unk170 = NULL;
    Critters::Deinit();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void LavaFiddlerCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_92;
    s32 var_r31_93;
    void *temp_r29_100;

    var_r30_92 = 0;
    var_r31_93 = 0;
loop_2:
    if (var_r30_92 < (s32) this->unk90) {
        temp_r29_100 = ((u8 *) this->unk170) + var_r31_93;
        this->unk80->SetAnim(M2C_FIELD(temp_r29_100, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
        this->unk80->JumpToPos(M2C_FIELD(temp_r29_100, f32 *, 0x54), -1);
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) temp_r29_100) - 4) + 4, 0x40);
        MKModel_SetWorldMatrix(this->unk4, sp10);
        MKModel_Draw(this->unk4, NULL);
        var_r30_92 += 1;
        var_r31_93 += 0x70;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void LavaFiddlerCritter::SetIdleState(LavaFiddler *arg0) {
    s32 temp_r31_149;

    arg0->unk60 = 0;
    temp_r31_149 = arg0->unk60;
    arg0->unk50 = M2C_FIELD((checked_cast<LavaFiddlerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_149 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    arg0->unk64 = 5.0f * MKRand_Float(&gViewSeed, 0.5f, 1.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp150'
void LavaFiddlerCritter::FindNewWalkParameters(LavaFiddler *arg0) {
    s8 sp258;
    s32 sp254;
    s32 sp250;
    s32 sp24C;
    f32 sp248;
    s32 sp244;
    s8 sp243;
    s8 sp242;
    s16 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;                                      /* compiler-managed */
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;                                      /* compiler-managed */
    f64 sp1B0;
    f64 sp1A8;                                      /* compiler-managed */
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
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
    f32 temp_f3_357;
    f32 var_f31_370;
    f32 var_f4_437;
    f32 var_f4_712;
    f32 var_f5_674;
    f32 var_f6_537;
    f32 var_f7_446;
    f32 var_f8_461;
    f32 var_f8_551;
    f64 temp_f0_263;
    f64 temp_f0_326;
    f64 temp_f0_351;
    f64 temp_f1_376;
    f64 temp_f1_382;
    f64 temp_f1_386;
    f64 temp_f1_474;
    f64 temp_f1_480;
    f64 temp_f1_484;
    f64 temp_f1_560;
    f64 temp_f1_566;
    f64 temp_f1_570;
    f64 temp_f1_717;
    f64 temp_f1_723;
    f64 temp_f1_727;
    s32 temp_r29_660;
    s32 temp_r3_405;
    s32 temp_r3_503;
    s32 temp_r3_589;
    s32 temp_r3_746;
    s32 var_r0_415;
    s32 var_r0_513;
    s32 var_r0_599;
    s32 var_r0_756;

    spE0 = 0.0f;
    spB0 = 0.0f;
    spD8 = 0.0f;
    spDC = 1.0f;
    spA8 = 0.0f;
    spAC = -500.0f;
    sp1F8 = arg0->unk30;
    sp200 = arg0->unk38;
    sp1E8 = (f64) spD8;
    sp1F0 = (f64) spE0;
    sp208 = 0.0f;
    sp20C = 0.0f;
    sp210 = 0.0f;
    sp218 = 0.0f;
    sp21C = 0.0f;
    sp220 = 0.0f;
    sp228 = 0.0f;
    sp22C = 0.0f;
    sp230 = 0.0f;
    sp234 = 1.0f;
    sp238 = 0.0f;
    sp23C = 0.0f;
    sp240 = 0;
    sp242 = 0;
    sp243 = 0;
    sp244 = 0;
    sp248 = 3.4028235e38f;
    sp24C = 0;
    sp250 = 0;
    sp254 = -1;
    sp258 = 0;
    sp158 = (f64) spA8;
    sp160 = (f64) spB0;
    sp98 = sp1F8 + sp158;
    spD0 = 0.0f;
    spC8 = 0.0f;
    spCC = 200.0f;
    spA0 = (f32) sp200 + (f32) sp160;
    sp178 = (f64) spC8;
    sp168 = sp98;
    sp170 = (f64) spA0;
    sp180 = (f64) spD0;
    temp_f0_263 = sp1F8 + sp178;
    spB8 = temp_f0_263;
    sp188 = temp_f0_263;
    spC0 = (f32) sp200 + (f32) sp180;
    sp190 = (f64) spC0;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp188), *((MKVector3 *) &sp168), (MKCollisionResult *) &sp208, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp1F8 = (f64) sp208;
        sp200 = (f64) sp210;
        sp1E8 = (f64) sp218;
        sp1F0 = (f64) sp220;
    }
    ((Volume *) &sp148)->GetRandPos();
    sp68 = 0.0f;
    sp6C = -500.0f;
    sp70 = 0.0f;
    sp1D8 = sp148;
    sp108 = (f64) sp68;
    sp1E0 = sp150;
    sp110 = (f64) sp70;
    sp58 = sp1D8 + sp108;
    sp90 = 0.0f;
    sp88 = 0.0f;
    sp8C = 200.0f;
    sp60 = (f32) sp1E0 + (f32) sp110;
    sp128 = (f64) sp88;
    sp118 = sp58;
    sp120 = (f64) sp60;
    sp130 = (f64) sp90;
    temp_f0_326 = sp1D8 + sp128;
    sp78 = temp_f0_326;
    sp138 = temp_f0_326;
    sp80 = (f32) sp1E0 + (f32) sp130;
    sp140 = (f64) sp80;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp138), *((MKVector3 *) &sp118), (MKCollisionResult *) &sp208, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp1D8 = (f64) sp208;
        sp1E0 = (f64) sp210;
    }
    temp_f0_351 = sp1D8 - arg0->unk30;
    sp48 = temp_f0_351;
    temp_f3_357 = arg0->unk4;
    sp1C8 = temp_f0_351;
    sp50 = (f32) sp1E0 - (f32) M2C_FIELD(arg0, f64 *, 0x38);
    (*(f32 *) ((u8 *) &sp1B0 + 0x1c)) = temp_f3_357;
    sp1D0 = (f64) sp50;
    var_f31_370 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + (temp_f3_357 * temp_f3_357));
    if (var_f31_370 > 0.000001f) {
        if (var_f31_370 > 0.0f) {
            temp_f1_376 = __frsqrte(var_f31_370);
            temp_f1_382 = 0.5 * temp_f1_376 * -(((f64) var_f31_370 * (temp_f1_376 * temp_f1_376)) - 3.0);
            temp_f1_386 = 0.5 * temp_f1_382 * -(((f64) var_f31_370 * (temp_f1_382 * temp_f1_382)) - 3.0);
            var_f31_370 = (f32) ((f64) var_f31_370 * (0.5 * temp_f1_386 * -(((f64) var_f31_370 * (temp_f1_386 * temp_f1_386)) - 3.0)));
        } else if (var_f31_370 < M2C_BITWISE(f32, 0.0)) {
            var_f31_370 = __float_nan;
        } else {
            sp14 = var_f31_370;
            temp_r3_405 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_405) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_415 = 1;
                } else {
                    var_r0_415 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_415 = 5;
                } else {
                    var_r0_415 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_415 = 4;
                break;
            }
            if (var_r0_415 == 1) {
                var_f31_370 = __float_nan;
            }
        }
        var_f4_437 = 1.0f / var_f31_370;
    } else {
        var_f4_437 = 0.0f;
        var_f31_370 = 0.0f;
    }
    sp1B8 = M2C_FIELD(arg0, f64 *, 0);
    var_f7_446 = 0.0f;
    sp1C0 = arg0->unk8;
    var_f8_461 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + (0.0f * 0.0f));
    sp1C8 = (f32) sp1C8 * var_f4_437;
    (*(f32 *) ((u8 *) &sp1B0 + 0x1c)) *= var_f4_437;
    sp1D0 = (f32) sp1D0 * var_f4_437;
    sp1A8 = arg0->unk20;
    sp1B0 = arg0->unk28;
    (*(f32 *) ((u8 *) &sp1B0 + 0xc)) = 0.0f;
    if (var_f8_461 > 0.000001f) {
        if (var_f8_461 > 0.0f) {
            temp_f1_474 = __frsqrte(var_f8_461);
            temp_f1_480 = 0.5 * temp_f1_474 * -(((f64) var_f8_461 * (temp_f1_474 * temp_f1_474)) - 3.0);
            temp_f1_484 = 0.5 * temp_f1_480 * -(((f64) var_f8_461 * (temp_f1_480 * temp_f1_480)) - 3.0);
            var_f8_461 = (f32) ((f64) var_f8_461 * (0.5 * temp_f1_484 * -(((f64) var_f8_461 * (temp_f1_484 * temp_f1_484)) - 3.0)));
        } else if (var_f8_461 < M2C_BITWISE(f32, 0.0)) {
            var_f8_461 = __float_nan;
        } else {
            sp10 = var_f8_461;
            temp_r3_503 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_503) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_513 = 1;
                } else {
                    var_r0_513 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_513 = 5;
                } else {
                    var_r0_513 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_513 = 4;
                break;
            }
            if (var_r0_513 == 1) {
                var_f8_461 = __float_nan;
            }
        }
        var_f7_446 = 1.0f / var_f8_461;
    }
    var_f6_537 = 0.0f;
    (*(f32 *) ((u8 *) &sp1A0 + 0xc)) = 0.0f;
    var_f8_551 = ((f32) sp1B0 * (f32) sp1B0) + (((f32) sp1A8 * (f32) sp1A8) + (0.0f * 0.0f));
    sp1B8 = (f32) sp1B8 * var_f7_446;
    (*(f32 *) ((u8 *) &sp1B0 + 0xc)) *= var_f7_446;
    sp1C0 = (f32) sp1C0 * var_f7_446;
    if (var_f8_551 > 0.000001f) {
        if (var_f8_551 > 0.0f) {
            temp_f1_560 = __frsqrte(var_f8_551);
            temp_f1_566 = 0.5 * temp_f1_560 * -(((f64) var_f8_551 * (temp_f1_560 * temp_f1_560)) - 3.0);
            temp_f1_570 = 0.5 * temp_f1_566 * -(((f64) var_f8_551 * (temp_f1_566 * temp_f1_566)) - 3.0);
            var_f8_551 = (f32) ((f64) var_f8_551 * (0.5 * temp_f1_570 * -(((f64) var_f8_551 * (temp_f1_570 * temp_f1_570)) - 3.0)));
        } else if (var_f8_551 < M2C_BITWISE(f32, 0.0)) {
            var_f8_551 = __float_nan;
        } else {
            spC = var_f8_551;
            temp_r3_589 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_589) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_599 = 1;
                } else {
                    var_r0_599 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_599 = 5;
                } else {
                    var_r0_599 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_599 = 4;
                break;
            }
            if (var_r0_599 == 1) {
                var_f8_551 = __float_nan;
            }
        }
        var_f6_537 = 1.0f / var_f8_551;
    }
    sp1A8 = (f32) sp1A8 * var_f6_537;
    (*(f32 *) ((u8 *) &sp1A0 + 0xc)) *= var_f6_537;
    if (((sp1D0 * sp1C0) + ((sp1C8 * sp1B8) + ((*(f32 *) ((u8 *) &sp1B0 + 0x1c)) * (*(f32 *) ((u8 *) &sp1B0 + 0xc))))) < 0.0f) {
        arg0->unk60 = 5;
        sp18 = -sp1C8;
        sp1C = -(*(f32 *) ((u8 *) &sp1B0 + 0x1c));
        sp20 = -sp1D0;
        spF8 = (f64) sp18;
        sp100 = (f64) sp20;
        sp1C8 = (f64) sp18;
        sp1D0 = (f64) sp20;
    } else {
        arg0->unk60 = 4;
    }
    temp_r29_660 = arg0->unk60;
    arg0->unk50 = M2C_FIELD((checked_cast<LavaFiddlerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r29_660 * 4)), void **, 0x70);
    var_f5_674 = 0.0f;
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    arg0->unk64 = var_f31_370 / 25.0f;
    sp38 = ((*(f32 *) ((u8 *) &sp1E8 + 0x4)) * (f32) sp1D0) - ((f32) sp1F0 * (*(f32 *) ((u8 *) &sp1B0 + 0x1c)));
    sp3C = ((f32) sp1F0 * (f32) sp1C8) - ((f32) sp1E8 * (f32) sp1D0);
    sp40 = ((f32) sp1E8 * (*(f32 *) ((u8 *) &sp1B0 + 0x1c))) - ((*(f32 *) ((u8 *) &sp1E8 + 0x4)) * (f32) sp1C8);
    spE8 = (f64) sp38;
    spF0 = (f64) sp40;
    var_f4_712 = ((f32) spF0 * (f32) spF0) + (((f32) spE8 * (f32) spE8) + ((*(f32 *) ((u8 *) &spE8 + 0x4)) * (*(f32 *) ((u8 *) &spE8 + 0x4))));
    if (var_f4_712 > 1e-12f) {
        if (var_f4_712 > 0.0f) {
            temp_f1_717 = __frsqrte(var_f4_712);
            temp_f1_723 = 0.5 * temp_f1_717 * -(((f64) var_f4_712 * (temp_f1_717 * temp_f1_717)) - 3.0);
            temp_f1_727 = 0.5 * temp_f1_723 * -(((f64) var_f4_712 * (temp_f1_723 * temp_f1_723)) - 3.0);
            var_f4_712 = (f32) ((f64) var_f4_712 * (0.5 * temp_f1_727 * -(((f64) var_f4_712 * (temp_f1_727 * temp_f1_727)) - 3.0)));
        } else if (var_f4_712 < M2C_BITWISE(f32, 0.0)) {
            var_f4_712 = __float_nan;
        } else {
            sp8 = var_f4_712;
            temp_r3_746 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_746) {                  /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_756 = 1;
                } else {
                    var_r0_756 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_756 = 5;
                } else {
                    var_r0_756 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_756 = 4;
                break;
            }
            if (var_r0_756 == 1) {
                var_f4_712 = __float_nan;
            }
        }
        var_f5_674 = 1.0f / var_f4_712;
    }
    sp2C = (*(f32 *) ((u8 *) &spE8 + 0x4)) * var_f5_674;
    sp28 = (f32) spE8 * var_f5_674;
    sp30 = (f32) spF0 * var_f5_674;
    sp198 = (f64) sp28;
    sp1A0 = (f64) sp30;
    KDMath_BuildMatrixFromUp((Matrix *) arg0, *((MKVector3 *) &sp1E8), *((MKVector3 *) &sp198));
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp1F8;
    M2C_FIELD(arg0, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp1F8 + 0x4));
    M2C_FIELD(arg0, f64 *, 0x38) = (f32) sp200;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
}
#endif

void LavaFiddlerCritter::SetHideState(LavaFiddler *arg0) {
    s8 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    f32 spC8;
    s32 spC4;
    s8 spC3;
    s8 spC2;
    s16 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
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
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f4_895;
    f64 temp_f0_910;
    f64 temp_f5_889;
    s32 temp_r0_820;
    s32 temp_r31_831;

    temp_r0_820 = arg0->unk60;
    switch (temp_r0_820) {                          /* irregular */
    case 3:
        return;
    default:
        arg0->unk60 = 1;
        temp_r31_831 = arg0->unk60;
        arg0->unk50 = M2C_FIELD((checked_cast<LavaFiddlerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_831 * 4)), void **, 0x70);
        sp20 = 0.0f;
        sp18 = 0.0f;
        sp1C = -500.0f;
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
        arg0->unk54 = 0.0f;
        arg0->unk64 = 0.0f;
        sp88 = 0.0f;
        sp8C = 0.0f;
        sp90 = 0.0f;
        sp98 = 0.0f;
        sp9C = 0.0f;
        spA0 = 0.0f;
        spA8 = 0.0f;
        spAC = 0.0f;
        spB0 = 0.0f;
        spB4 = 1.0f;
        spB8 = 0.0f;
        spBC = 0.0f;
        spC0 = 0;
        spC2 = 0;
        spC3 = 0;
        spC4 = 0;
        spC8 = 3.4028235e38f;
        spCC = 0;
        spD0 = 0;
        spD4 = -1;
        spD8 = 0;
        temp_f5_889 = arg0->unk30;
        sp8 = temp_f5_889 + sp48;
        sp40 = 0.0f;
        temp_f4_895 = M2C_FIELD(arg0, f32 *, 0x38);
        sp38 = 0.0f;
        sp10 = temp_f4_895 + (f32) sp50;
        sp3C = 200.0f;
        sp58 = sp8;
        sp60 = (f64) sp10;
        sp68 = (f64) sp38;
        sp70 = (f64) sp40;
        temp_f0_910 = temp_f5_889 + sp68;
        sp28 = temp_f0_910;
        sp78 = temp_f0_910;
        sp30 = temp_f4_895 + (f32) sp70;
        sp80 = (f64) sp30;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp78), *((MKVector3 *) &sp58), (MKCollisionResult *) &sp88, (MKCollisionMode) 4, 0x0C000000) != 0) {
            M2C_FIELD(arg0, f64 *, 0x30) = sp88;
            M2C_FIELD(arg0, f32 *, 0x34) = sp8C;
            M2C_FIELD(arg0, f32 *, 0x38) = sp90;
            M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
        }
        /* fallthrough */
    case 1:
    case 2:
        return;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void LavaFiddlerCritter::Update() {
    s8 sp168;
    s32 sp164;
    s32 sp160;
    s32 sp15C;
    f32 sp158;
    s32 sp154;
    s8 sp153;
    s8 sp152;
    s16 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
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
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    LavaFiddler *temp_r30_957;
    f32 temp_f0_1047;
    f32 temp_f1_1178;
    f32 temp_f1_981;
    f32 temp_f4_1094;
    f64 temp_f0_1029;
    f64 temp_f0_1109;
    f64 temp_f1_1242;
    f64 temp_f5_1088;
    s32 temp_r0_1225;
    s32 temp_r0_966;
    s32 temp_r27_1151;
    s32 temp_r27_1192;
    s32 var_r28_952;
    s32 var_r31_951;
    void *temp_r3_1241;

    var_r31_951 = 0;
    var_r28_952 = 0;
loop_35:
    if (var_r31_951 < (s32) this->unk90) {
        temp_r30_957 = ((u8 *) this->unk170) + var_r28_952;
        temp_r30_957->unk64 -= gUpdateTimeDelta;
        temp_r30_957->unk54 += temp_r30_957->unk58 * gUpdateTimeDelta;
        temp_r0_966 = temp_r30_957->unk60;
        switch (temp_r0_966) {                      /* irregular */
        case 0:
            temp_f1_981 = temp_r30_957->unk54;
            if (temp_f1_981 > 1.0f) {
                temp_r30_957->unk54 = temp_f1_981 - 1.0f;
            }
            if (temp_r30_957->unk64 <= 0.0f) {
                FindNewWalkParameters(temp_r30_957);
            }
            break;
        default:
            sp108 = M2C_FIELD(temp_r30_957, f64 *, 0);
            sp110 = temp_r30_957->unk8;
            if (temp_r0_966 == 5) {
                sp18 = -(f32) sp108;
                sp1C = -(*(f32 *) ((u8 *) &sp108 + 0x4));
                sp20 = -(f32) sp110;
                spF8 = (f64) sp18;
                sp100 = (f64) sp20;
                sp108 = (f64) sp18;
                sp110 = (f64) sp20;
            }
            spD8.operator*(25.0f * gUpdateTimeDelta);
            temp_f0_1029 = temp_r30_957->unk30 + M2C_BITWISE(f64, spD8);
            sp8 = temp_f0_1029;
            spE8 = temp_f0_1029;
            sp10 = M2C_FIELD(temp_r30_957, f32 *, 0x38) + spD8.unk8;
            M2C_FIELD(temp_r30_957, f64 *, 0x30) = (f32) spE8;
            spF0 = (f64) sp10;
            M2C_FIELD(temp_r30_957, f32 *, 0x34) = (*(f32 *) ((u8 *) &spE8 + 0x4));
            M2C_FIELD(temp_r30_957, f32 *, 0x38) = (f32) spF0;
            M2C_FIELD(temp_r30_957, f32 *, 0x3C) = 1.0f;
            temp_f0_1047 = temp_r30_957->unk54;
            if (temp_f0_1047 > 1.0f) {
                temp_r30_957->unk54 = temp_f0_1047 - 1.0f;
            }
            sp48 = 0.0f;
            sp4C = -500.0f;
            sp50 = 0.0f;
            sp118 = 0.0f;
            sp11C = 0.0f;
            sp120 = 0.0f;
            sp128 = 0.0f;
            sp12C = 0.0f;
            sp130 = 0.0f;
            sp138 = 0.0f;
            sp13C = 0.0f;
            sp140 = 0.0f;
            sp144 = 1.0f;
            sp148 = 0.0f;
            sp14C = 0.0f;
            sp150 = 0;
            sp152 = 0;
            sp153 = 0;
            sp154 = 0;
            sp158 = 3.4028235e38f;
            sp15C = 0;
            sp160 = 0;
            sp164 = -1;
            sp168 = 0;
            sp98 = (f64) sp48;
            spA0 = (f64) sp50;
            temp_f5_1088 = temp_r30_957->unk30;
            sp38 = temp_f5_1088 + sp98;
            sp70 = 0.0f;
            temp_f4_1094 = M2C_FIELD(temp_r30_957, f32 *, 0x38);
            sp68 = 0.0f;
            sp6C = 200.0f;
            sp40 = temp_f4_1094 + (f32) spA0;
            spB8 = (f64) sp68;
            spA8 = sp38;
            spB0 = (f64) sp40;
            spC0 = (f64) sp70;
            temp_f0_1109 = temp_f5_1088 + spB8;
            sp58 = temp_f0_1109;
            spC8 = temp_f0_1109;
            sp60 = temp_f4_1094 + (f32) spC0;
            spD0 = (f64) sp60;
            if (MKCollision_RayCollide(*((MKVector3 *) &spC8), *((MKVector3 *) &spA8), (MKCollisionResult *) &sp118, (MKCollisionMode) 4, 0x0C000000) != 0) {
                M2C_FIELD(temp_r30_957, f64 *, 0x30) = sp118;
                M2C_FIELD(temp_r30_957, f32 *, 0x34) = sp11C;
                M2C_FIELD(temp_r30_957, f32 *, 0x38) = sp120;
                M2C_FIELD(temp_r30_957, f32 *, 0x3C) = 1.0f;
            }
            if (temp_r30_957->unk64 <= 0.0f) {
                SetIdleState(temp_r30_957);
            }
            break;
        case 1:
            if (temp_r30_957->unk54 > 1.0f) {
                temp_r30_957->unk60 = 2;
                temp_r27_1151 = temp_r30_957->unk60;
                temp_r30_957->unk50 = *(checked_cast<LavaFiddlerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_1151 * 4) + 0x70));
                temp_r30_957->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_957->unk50, s16 *, 4) / 30.0f));
                temp_r30_957->unk54 = 0.0f;
                temp_r30_957->unk64 = 5.0f;
            }
            break;
        case 2:
            temp_f1_1178 = temp_r30_957->unk54;
            if (temp_f1_1178 > 1.0f) {
                temp_r30_957->unk54 = temp_f1_1178 - 1.0f;
            }
            if (temp_r30_957->unk64 <= 0.0f) {
                temp_r30_957->unk60 = 3;
                temp_r27_1192 = temp_r30_957->unk60;
                temp_r30_957->unk50 = *(checked_cast<LavaFiddlerCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_1192 * 4) + 0x70));
                temp_r30_957->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(temp_r30_957->unk50, s16 *, 4) / 30.0f));
                temp_r30_957->unk54 = 0.0f;
            }
            break;
        case 3:
            if (temp_r30_957->unk54 > 1.0f) {
                SetIdleState(temp_r30_957);
            }
            break;
        }
        temp_r0_1225 = temp_r30_957->unk60;
        if ((temp_r0_1225 == 0) || (temp_r0_1225 == 4) || (temp_r0_1225 == 5)) {
            temp_r3_1241 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            temp_f1_1242 = M2C_FIELD(temp_r3_1241, f64 *, 0x30);
            sp78 = temp_f1_1242;
            sp80 = M2C_FIELD(temp_r3_1241, f64 *, 0x38);
            sp28 = temp_f1_1242 - temp_r30_957->unk30;
            sp88 = sp28;
            sp30 = (f32) sp80 - M2C_FIELD(temp_r30_957, f32 *, 0x38);
            sp90 = (f64) sp30;
            if ((((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))))) <= 250000.0f) {
                SetHideState(temp_r30_957);
            }
        }
        var_r31_951 += 1;
        var_r28_952 += 0x70;
        goto loop_35;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void LavaFiddlerCritter::Resolve() {
    s8 sp190;
    s32 sp18C;
    s32 sp188;
    Volume sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    LavaFiddler *temp_r30_1323;
    f32 temp_f1_1437;
    f32 var_f3_1511;
    f32 var_f4_1444;
    f64 temp_f0_1393;
    f64 temp_f1_1450;
    f64 temp_f1_1456;
    f64 temp_f1_1460;
    s32 temp_r3_1479;
    s32 var_r0_1489;
    s32 var_r28_1313;
    s32 var_r31_1311;

    MKProp::Resolve();
    var_r31_1311 = 0;
    var_r28_1313 = 0;
loop_24:
    if (var_r31_1311 < (s32) this->unk90) {
        temp_r30_1323 = ((u8 *) this->unk170) + var_r28_1313;
        SetIdleState(temp_r30_1323);
        sp100.GetRandPos();
        sp88 = 0.0f;
        sp80 = 0.0f;
        sp84 = 1.0f;
        sp58 = 0.0f;
        sp100.unk20 = (f64) sp80;
        sp100.unk28 = (f64) sp88;
        sp50 = 0.0f;
        sp54 = -500.0f;
        sp100.unk30 = M2C_BITWISE(f64, sp100);
        (*(f32 *) ((u8 *) &sp100 + 0x34)) = M2C_FIELD(this->unk8, f32 *, 0x34);
        spC0 = (f64) sp50;
        sp100.unk38 = sp100.unk8;
        sp100.unk40 = 0.0f;
        sp100.unk40.unk4 = 0.0f;
        sp100.unk40.unk8 = 0.0f;
        sp100.unk40.unk10 = 0.0f;
        sp100.unk40.unk14 = 0.0f;
        sp100.unk40.unk18 = 0.0f;
        sp100.unk40.unk20 = 0.0f;
        sp100.unk40.unk24 = 0.0f;
        sp100.unk40.unk28 = 0.0f;
        sp100.unk40.unk2C = 1.0f;
        sp100.unk40.unk30 = 0.0f;
        sp100.unk40.unk34 = 0.0f;
        sp100.unk40.unk38 = 0;
        (*(u8 *) ((u8 *) &sp100 + 0x7a)) = 0;
        (*(u8 *) ((u8 *) &sp100 + 0x7b)) = 0;
        sp100.unk40.unk3C = 0.0f;
        sp100.unk80 = 3.4028235e38f;
        sp100.unk84 = 0.0f;
        sp188 = 0;
        sp18C = -1;
        sp190 = 0;
        spC8 = (f64) sp58;
        sp40 = sp100.unk30 + spC0;
        sp78 = 0.0f;
        sp70 = 0.0f;
        sp74 = 200.0f;
        sp48 = (f32) sp100.unk38 + (f32) spC8;
        spE0 = (f64) sp70;
        spD0 = sp40;
        spD8 = (f64) sp48;
        spE8 = (f64) sp78;
        temp_f0_1393 = sp100.unk30 + spE0;
        sp60 = temp_f0_1393;
        spF0 = temp_f0_1393;
        sp68 = (f32) sp100.unk38 + (f32) spE8;
        spF8 = (f64) sp68;
        if (MKCollision_RayCollide(*((MKVector3 *) &spF0), *((MKVector3 *) &spD0), (MKCollisionResult *) &sp100.unk40, (MKCollisionMode) 4, 0x0C000000) != 0) {
            sp100.unk30 = M2C_BITWISE(f64, sp100.unk40);
            sp100.unk38 = (f64) sp100.unk40.unk8;
            sp100.unk20 = (f64) sp100.unk40.unk10;
            sp100.unk28 = (f64) sp100.unk40.unk18;
        }
        sp38 = -1.0f;
        sp28 = 1.0f;
        sp30 = -1.0f;
        sp34 = 0.0f;
        sp20 = 1.0f;
        sp24 = 0.0f;
        spA0 = (f64) sp30;
        spA8 = (f64) sp38;
        sp90 = (f64) sp20;
        sp98 = (f64) sp28;
        KDRand_Vector(spB0, *((MKVector3 *) &spA0));
        temp_f1_1437 = M2C_BITWISE(f32, spB0);
        var_f4_1444 = (spB0.unk8 * spB0.unk8) + ((temp_f1_1437 * temp_f1_1437) + (spB0.unk4 * spB0.unk4));
        if (var_f4_1444 > 1e-12f) {
            if (var_f4_1444 > 0.0f) {
                temp_f1_1450 = __frsqrte(var_f4_1444);
                temp_f1_1456 = 0.5 * temp_f1_1450 * -(((f64) var_f4_1444 * (temp_f1_1450 * temp_f1_1450)) - 3.0);
                temp_f1_1460 = 0.5 * temp_f1_1456 * -(((f64) var_f4_1444 * (temp_f1_1456 * temp_f1_1456)) - 3.0);
                var_f4_1444 = (f32) ((f64) var_f4_1444 * (0.5 * temp_f1_1460 * -(((f64) var_f4_1444 * (temp_f1_1460 * temp_f1_1460)) - 3.0)));
            } else if (var_f4_1444 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1444 = __float_nan;
            } else {
                sp8 = var_f4_1444;
                temp_r3_1479 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1479) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1489 = 1;
                    } else {
                        var_r0_1489 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1489 = 5;
                    } else {
                        var_r0_1489 = 3;
                    }
                    break;
                default:
                    var_r0_1489 = 4;
                    break;
                }
                if (var_r0_1489 == 1) {
                    var_f4_1444 = __float_nan;
                }
            }
            var_f3_1511 = 1.0f / var_f4_1444;
        } else {
            var_f3_1511 = 0.0f;
        }
        sp10 = M2C_BITWISE(f32, spB0) * var_f3_1511;
        sp14 = spB0.unk4 * var_f3_1511;
        sp18 = spB0.unk8 * var_f3_1511;
        sp100.unk10 = (f64) sp10;
        sp100.unk18 = (f64) sp18;
        KDMath_BuildMatrixFromUp((Matrix *) temp_r30_1323, *((MKVector3 *) &sp100.unk20), *((MKVector3 *) &sp100.unk10));
        var_r31_1311 += 1;
        var_r28_1313 += 0x70;
        M2C_FIELD(temp_r30_1323, f32 *, 0x30) = (f32) sp100.unk30;
        M2C_FIELD(temp_r30_1323, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp100 + 0x34));
        M2C_FIELD(temp_r30_1323, f32 *, 0x38) = (f32) sp100.unk38;
        M2C_FIELD(temp_r30_1323, f32 *, 0x3C) = 1.0f;
        goto loop_24;
    }
}
#endif

void LavaFiddlerCritter::LoadDone() {
    MKHeap *temp_r3_1578;
    s32 temp_r31_1577;
    void *var_r3_1585;

    Critters::LoadDone();
    temp_r31_1577 = this->unk90 * 0x70;
    temp_r3_1578 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1578 != NULL) {
        var_r3_1585 = ((MKHeap *) (temp_r3_1578->Current()))->Alloc(temp_r31_1577, NULL, 0);
    } else {
        var_r3_1585 = malloc(temp_r31_1577);
    }
    this->unk170 = var_r3_1585;
}

void LavaFiddlerCritter::Init() {
    Critters::Init();
}

void LavaFiddlerCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void LavaFiddlerCritterDescriptor::LoadDone() {
    s8 *temp_r30_1634;
    s8 *temp_r30_1652;
    s8 *temp_r30_1670;
    s8 *temp_r30_1688;
    s8 *temp_r30_1706;
    s8 *temp_r30_1724;
    void *var_r3_1644;
    void *var_r3_1662;
    void *var_r3_1680;
    void *var_r3_1698;
    void *var_r3_1716;
    void *var_r3_1734;

    KDPropDescriptor::LoadDone();
    temp_r30_1634 = this->unk34;
    if (((MKAnimScript *) temp_r30_1634)->Exists("idle01") != 0) {
        var_r3_1644 = ((MKAnimScript *) temp_r30_1634)->GetAnim("idle01");
    } else {
        var_r3_1644 = NULL;
    }
    this->unk70 = (s32) var_r3_1644;
    temp_r30_1652 = this->unk34;
    if (((MKAnimScript *) temp_r30_1652)->Exists("Hide_Enter") != 0) {
        var_r3_1662 = ((MKAnimScript *) temp_r30_1652)->GetAnim("Hide_Enter");
    } else {
        var_r3_1662 = NULL;
    }
    this->unk74 = (s32) var_r3_1662;
    temp_r30_1670 = this->unk34;
    if (((MKAnimScript *) temp_r30_1670)->Exists("Hide_Loop") != 0) {
        var_r3_1680 = ((MKAnimScript *) temp_r30_1670)->GetAnim("Hide_Loop");
    } else {
        var_r3_1680 = NULL;
    }
    this->unk78 = (s32) var_r3_1680;
    temp_r30_1688 = this->unk34;
    if (((MKAnimScript *) temp_r30_1688)->Exists("Hide_Exit") != 0) {
        var_r3_1698 = ((MKAnimScript *) temp_r30_1688)->GetAnim("Hide_Exit");
    } else {
        var_r3_1698 = NULL;
    }
    this->unk7C = (s32) var_r3_1698;
    temp_r30_1706 = this->unk34;
    if (((MKAnimScript *) temp_r30_1706)->Exists("Walk_Left") != 0) {
        var_r3_1716 = ((MKAnimScript *) temp_r30_1706)->GetAnim("Walk_Left");
    } else {
        var_r3_1716 = NULL;
    }
    this->unk80 = (s32) var_r3_1716;
    temp_r30_1724 = this->unk34;
    if (((MKAnimScript *) temp_r30_1724)->Exists("Walk_Right") != 0) {
        var_r3_1734 = ((MKAnimScript *) temp_r30_1724)->GetAnim("Walk_Right");
    } else {
        var_r3_1734 = NULL;
    }
    this->unk84 = (s32) var_r3_1734;
}

void LavaFiddlerCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}

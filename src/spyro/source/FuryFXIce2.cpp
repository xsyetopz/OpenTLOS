#include "spyro/source/FuryFXIce2.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/IceExplosion.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/Level.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK free(Matrix **);                            /* extern */
Matrix **malloc(M2C_UNK);                           /* extern */
extern s32 GS_SpyroFuryIce3;
extern s32 GS_SpyroFuryIce4;
extern s32 GS_SpyroFuryIce5;
extern s32 GS_SpyroFuryIce6;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void FuryFXIce2::ResetFury() {
    IceExplosion *temp_r3_75;
    Matrix **temp_r3_60;
    Matrix **var_r6_55;
    Matrix *temp_r3_71;
    Matrix *temp_r5_63;

    SetDefaults();
    var_r6_55 = this->unk100;
loop_2:
    if (var_r6_55 != NULL) {
        temp_r3_71 = *var_r6_55;
        if (temp_r3_71 != NULL) {
            M2C_FIELD(temp_r3_71, s32 *, 0x50) = 0;
            temp_r3_60 = this->unk100;
            this->unk100 = temp_r3_60 + 4;
            temp_r5_63 = *temp_r3_60;
            *temp_r3_60 = *var_r6_55;
            *var_r6_55 = temp_r5_63;
            var_r6_55 += 4;
            goto loop_2;
        }
    }
    temp_r3_75 = this->unk114;
    temp_r3_75->Disable();
}

void FuryFXIce2::TargetAndSpawnIceSpear() {
    Targetable ***temp_r3_104;
    Targetable ***temp_r3_117;
    Targetable **temp_r3_107;
    Targetable **temp_r3_120;
    Targetable *temp_r4_123;

    this->unk110 -= gUpdateTimeDelta;
    if (!(this->unk110 > 0.0f)) {
        this->unk110 = 0.0f;
        temp_r3_104 = this->unk10C;
        if ((temp_r3_104 == NULL) || (temp_r3_107 = *temp_r3_104, ((temp_r3_107 == NULL) != 0)) || ((Targetable *) *temp_r3_107 == NULL)) {
            this->unk10C = this->unk108;
        }
        temp_r3_117 = this->unk10C;
        if ((temp_r3_117 != NULL) && (temp_r3_120 = *temp_r3_117, ((temp_r3_120 == NULL) == 0)) && (temp_r4_123 = *temp_r3_120, ((temp_r4_123 == NULL) == 0))) {
            SpawnIceSpear(temp_r4_123);
            this->unk10C += 4;
        } else {
            SpawnIceSpear(NULL);
        }
        if ((Targetable ***) this->unk10C == NULL) {
            SpawnIceSpear(NULL);
        }
    }
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void FuryFXIce2::SpawnIceSpear(Targetable *arg0) {
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;
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
    MKVector3 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
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
    f64 sp10;
    f32 sp8;
    Matrix **temp_r3_162;
    Matrix **temp_r3_166;
    Matrix *temp_r31_168;
    f32 temp_f3_323;
    f32 var_f4_213;
    f32 var_f5_231;
    f64 temp_f1_239;
    f64 temp_f1_245;
    f64 temp_f1_249;
    f64 temp_f1_319;
    s32 temp_r3_268;
    s32 var_r0_278;

    temp_r3_162 = this->unk100;
    if ((u32) M2C_FIELD(temp_r3_162, u32 *, -4) != 0U) {
        temp_r3_166 = temp_r3_162 - 4;
        this->unk100 = temp_r3_166;
        temp_r31_168 = *temp_r3_166;
        if (temp_r31_168 != NULL) {
            sp58 = 1.0f;
            sp68 = -1.0f;
            sp50 = 1.0f;
            sp54 = 0.0f;
            sp60 = -1.0f;
            sp64 = 0.0f;
            spE0 = (f64) sp50;
            spE8 = (f64) sp58;
            spF0 = (f64) sp60;
            spF8 = (f64) sp68;
            sp100 = KDRand_Vector(*((MKVector3 *) &spF0), *((MKVector3 *) &spE0));
            *(MKVector3 *) &sp120 = sp100;
            M2C_STRUCT_COPY(temp_r31_168, &Matrix::identity, 0x40);
            sp30 = (f32) sp120;
            sp34 = 3.0f;
            var_f4_213 = 0.0f;
            sp38 = (*(f32 *) ((u8 *) &sp120 + 0x4));
            spC0 = (f64) sp30;
            spC8 = (f64) sp38;
            sp48 = 1.0f;
            sp40 = 0.0f;
            sp44 = 0.0f;
            var_f5_231 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + ((*(f32 *) ((u8 *) &spC0 + 0x4)) * (*(f32 *) ((u8 *) &spC0 + 0x4))));
            sp118 = (f64) sp48;
            sp110 = (f64) sp40;
            if (var_f5_231 > 1e-12f) {
                if (var_f5_231 > 0.0f) {
                    temp_f1_239 = __frsqrte(var_f5_231);
                    temp_f1_245 = 0.5 * temp_f1_239 * -(((f64) var_f5_231 * (temp_f1_239 * temp_f1_239)) - 3.0);
                    temp_f1_249 = 0.5 * temp_f1_245 * -(((f64) var_f5_231 * (temp_f1_245 * temp_f1_245)) - 3.0);
                    var_f5_231 = (f32) ((f64) var_f5_231 * (0.5 * temp_f1_249 * -(((f64) var_f5_231 * (temp_f1_249 * temp_f1_249)) - 3.0)));
                } else if (var_f5_231 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_231 = __float_nan;
                } else {
                    sp8 = var_f5_231;
                    temp_r3_268 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_268) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_278 = 1;
                        } else {
                            var_r0_278 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_278 = 5;
                        } else {
                            var_r0_278 = 3;
                        }
                        break;
                    default:
                        var_r0_278 = 4;
                        break;
                    }
                    if (var_r0_278 == 1) {
                        var_f5_231 = __float_nan;
                    }
                }
                var_f4_213 = 1.0f / var_f5_231;
            }
            sp24 = (*(f32 *) ((u8 *) &spC0 + 0x4)) * var_f4_213;
            sp20 = (f32) spC0 * var_f4_213;
            sp28 = (f32) spC8 * var_f4_213;
            spD0 = (f64) sp20;
            spD8 = (f64) sp28;
            KDMath_BuildMatrixFromFwd(temp_r31_168, *((MKVector3 *) &spD0), (MKVector3 *) &sp110);
            temp_f1_319 = sp120 * 5.56078426e-315;
            sp120 = temp_f1_319;
            temp_f3_323 = (f32) sp128 * 150.0f;
            sp128 = temp_f3_323;
            sp120 = temp_f1_319 + this->unk98;
            sp128 = temp_f3_323 + this->unkA0;
            temp_r31_168->unk30 = (f32) sp120;
            temp_r31_168->unk34 = (*(f32 *) ((u8 *) &sp120 + 0x4));
            temp_r31_168->unk38 = sp128;
            temp_r31_168->unk3C = 1.0f;
            M2C_FIELD(temp_r31_168, s32 *, 0x50) = 1;
            M2C_FIELD(temp_r31_168, f32 *, 0x54) = 1.0f;
            M2C_FIELD(temp_r31_168, Targetable **, 0x58) = arg0;
            if ((Targetable *) M2C_FIELD(temp_r31_168, Targetable **, 0x58) == NULL) {
                sp70 = MKVector(1.0f, 0.0f, 1.0f);
                sp80 = MKVector(-1.0f, 0.0f, -1.0f);
                sp90 = KDRand_Vector(sp80, sp70);
                spA0.operator*(2000.0f);
                sp10 = this->unk98 + M2C_BITWISE(f64, spA0);
                M2C_FIELD(temp_r31_168, f64 *, 0x40) = sp10;
                sp18 = this->unkA0 + spA0.unk8;
                spB0 = sp10;
                spB8 = (f64) sp18;
                M2C_FIELD(temp_r31_168, f64 *, 0x48) = (f64) sp18;
            }
            this->unk114->Trigger(*((MKVector3 *) &sp120), 1.0f);
            KDSound_Play3d(GS_SpyroFuryIce4, (MKVector3 *) &temp_r31_168->unk30, 0U, -1, 0.0f, 0U);
        }
    }
}
#endif

void FuryFXIce2::DrawIceSpears() {
    Matrix **var_r31_408;
    Matrix *temp_r4_420;

    var_r31_408 = this->unk100;
loop_2:
    if (var_r31_408 != NULL) {
        temp_r4_420 = *var_r31_408;
        if (temp_r4_420 != NULL) {
            MKModel_SetWorldMatrix(this->unk104, *temp_r4_420);
            MKModel_Draw(this->unk104, NULL);
            var_r31_408 += 4;
            goto loop_2;
        }
    }
}

#if 0 // DRAFT: identifier 'FuryFXIce2::UpdateIceSpears()' redeclared was declared as: 'Matrix ** ()' now declared as: 'void ()'
void FuryFXIce2::UpdateIceSpears() {
    f64 sp1D8;                                      /* compiler-managed */
    f64 sp1D0;
    f64 sp1C8;                                      /* compiler-managed */
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
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
    f32 sp8;
    Matrix **temp_r3_922;
    Matrix **var_r29_446;
    Matrix *temp_r30_934;
    Matrix *temp_r4_925;
    f32 temp_f1_750;
    f32 temp_f2_553;
    f32 temp_f31_473;
    f32 var_f1_897;
    f32 var_f2_729;
    f32 var_f3_640;
    f32 var_f4_573;
    f64 temp_f0_486;
    f64 temp_f0_537;
    f64 temp_f0_723;
    f64 temp_f0_753;
    f64 temp_f0_765;
    f64 temp_f0_815;
    f64 temp_f1_579;
    f64 temp_f1_585;
    f64 temp_f1_589;
    f64 temp_f1_814;
    f64 temp_f3_548;
    s32 temp_r0_454;
    s32 temp_r3_608;
    s32 var_r0_618;
    void **temp_r3_504;
    void **temp_r3_704;
    void **temp_r3_805;
    void **temp_r3_820;
    void *temp_r26_850;
    void *temp_r3_812;
    void *temp_r3_840;

    var_r29_446 = this->unk100;
loop_56:
    if (var_r29_446 != NULL) {
        temp_r30_934 = *var_r29_446;
        if (temp_r30_934 != NULL) {
            M2C_FIELD(temp_r30_934, f32 *, 0x54) = (f32) (M2C_FIELD(temp_r30_934, f32 *, 0x54) - gUpdateTimeDelta);
            temp_r0_454 = M2C_FIELD(temp_r30_934, s32 *, 0x50);
            switch (temp_r0_454) {                  /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                temp_f31_473 = gUpdateTimeDelta;
                sp20 = -temp_r30_934->unk20;
                sp24 = -temp_r30_934->unk24;
                sp28 = -temp_r30_934->unk28;
                sp140 = (f64) sp20;
                sp148 = (f64) sp28;
                sp150.operator*(4000.0f);
                temp_f0_486 = sp150 * (f64) temp_f31_473;
                sp50 = temp_f0_486;
                sp160 = temp_f0_486;
                sp58 = sp150.unk8 * temp_f31_473;
                sp168 = (f64) sp58;
                temp_r30_934->Translate(temp_r30_934, *((MKVector3 *) &sp160));
                if (M2C_FIELD(temp_r30_934, f32 *, 0x54) <= 0.0f) {
                    temp_r3_504 = M2C_FIELD(temp_r30_934, void ***, 0x58);
                    if (temp_r3_504 != NULL) {
                        M2C_FIELD(*temp_r3_504, M2C_UNK (**)(f32 *, f64 *), 0x2C)(&temp_r30_934->unk30, &sp1D0);
                    } else {
                        sp1D0 = M2C_FIELD(temp_r30_934, f64 *, 0x40);
                        sp1D8 = M2C_FIELD(temp_r30_934, f64 *, 0x48);
                    }
                    sp100 = MKVector(1.0f, 0.0f, 1.0f);
                    sp110 = MKVector(-1.0f, 0.0f, -1.0f);
                    sp120 = KDRand_Vector(sp110, sp100);
                    temp_f0_537 = sp120 * 5.53552857e-315;
                    sp40 = temp_f0_537;
                    sp130 = temp_f0_537;
                    sp48 = sp120.unk8 * 100.0f;
                    sp138 = (f64) sp48;
                    temp_f3_548 = sp1D0 + temp_f0_537;
                    sp1D0 = temp_f3_548;
                    temp_f2_553 = (f32) sp1D8 + (f32) sp138;
                    sp1D8 = temp_f2_553;
                    spA0 = temp_f3_548 - M2C_FIELD(temp_r30_934, f64 *, 0x30);
                    sp1C0 = spA0;
                    spA8 = temp_f2_553 - temp_r30_934->unk38;
                    sp1C8 = (f64) spA8;
                    var_f4_573 = ((f32) sp1C8 * (f32) sp1C8) + (((f32) sp1C0 * (f32) sp1C0) + ((*(f32 *) ((u8 *) &sp1B8 + 0xc)) * (*(f32 *) ((u8 *) &sp1B8 + 0xc))));
                    if (var_f4_573 > 0.000001f) {
                        if (var_f4_573 > 0.0f) {
                            temp_f1_579 = __frsqrte(var_f4_573);
                            temp_f1_585 = 0.5 * temp_f1_579 * -(((f64) var_f4_573 * (temp_f1_579 * temp_f1_579)) - 3.0);
                            temp_f1_589 = 0.5 * temp_f1_585 * -(((f64) var_f4_573 * (temp_f1_585 * temp_f1_585)) - 3.0);
                            var_f4_573 = (f32) ((f64) var_f4_573 * (0.5 * temp_f1_589 * -(((f64) var_f4_573 * (temp_f1_589 * temp_f1_589)) - 3.0)));
                        } else if (var_f4_573 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_573 = __float_nan;
                        } else {
                            sp8 = var_f4_573;
                            temp_r3_608 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_608) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_618 = 1;
                                } else {
                                    var_r0_618 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_618 = 5;
                                } else {
                                    var_r0_618 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_618 = 4;
                                break;
                            }
                            if (var_r0_618 == 1) {
                                var_f4_573 = __float_nan;
                            }
                        }
                        var_f3_640 = 1.0f / var_f4_573;
                    } else {
                        var_f3_640 = 0.0f;
                    }
                    sp1C0 = (f32) sp1C0 * var_f3_640;
                    (*(f32 *) ((u8 *) &sp1B8 + 0xc)) *= var_f3_640;
                    sp1C8 = (f32) sp1C8 * var_f3_640;
                    sp1B0 = M2C_FIELD(temp_r30_934, f64 *, 0x30);
                    sp1B8 = (f64) M2C_FIELD(temp_r30_934, f32 *, 0x38);
                    M2C_STRUCT_COPY(temp_r30_934, &Matrix::identity, 0x40);
                    sp98 = 0.0f;
                    sp90 = 0.0f;
                    sp94 = 1.0f;
                    sp1A8 = (f64) sp98;
                    sp1A0 = (f64) sp90;
                    KDMath_BuildMatrixFromFwd(temp_r30_934, *((MKVector3 *) &sp1C0), (MKVector3 *) &sp1A0);
                    temp_r30_934->unk30 = (f32) sp1B0;
                    temp_r30_934->unk34 = (*(f32 *) ((u8 *) &sp1B0 + 0x4));
                    temp_r30_934->unk38 = (f32) sp1B8;
                    temp_r30_934->unk3C = 1.0f;
                    M2C_FIELD(temp_r30_934, s32 *, 0x50) = 2;
                    M2C_FIELD(temp_r30_934, f32 *, 0x54) = 2.0f;
                    KDSound_Play3d(GS_SpyroFuryIce5, (MKVector3 *) &temp_r30_934->unk30, 0U, -1, 0.0f, 0U);
                }
                break;
            case 2:                                 /* switch 1 */
                temp_r3_704 = M2C_FIELD(temp_r30_934, void ***, 0x58);
                if (temp_r3_704 != NULL) {
                    M2C_FIELD(*temp_r3_704, M2C_UNK (**)(f32 *, f64 *), 0x2C)(&temp_r30_934->unk30, &sp190);
                } else {
                    sp190 = M2C_FIELD(temp_r30_934, f64 *, 0x40);
                    sp198 = M2C_FIELD(temp_r30_934, f64 *, 0x48);
                }
                temp_f0_723 = sp190 - M2C_FIELD(temp_r30_934, f64 *, 0x30);
                sp80 = temp_f0_723;
                var_f2_729 = M2C_FIELD(temp_r30_934, f32 *, 0x54);
                sp180 = temp_f0_723;
                sp88 = (f32) sp198 - temp_r30_934->unk38;
                sp188 = (f64) sp88;
                if (var_f2_729 < 2.0f) {

                } else {
                    var_f2_729 = 2.0f;
                }
                if (var_f2_729 > 0.0f) {

                } else {
                    var_f2_729 = 0.0f;
                }
                temp_f1_750 = -((var_f2_729 * 0.5f) - 1.0f);
                temp_f0_753 = sp180 * (f64) temp_f1_750;
                sp70 = temp_f0_753;
                spF0 = temp_f0_753;
                sp78 = (f32) sp188 * temp_f1_750;
                spF8 = (f64) sp78;
                temp_f0_765 = M2C_FIELD(temp_r30_934, f64 *, 0x30) + temp_f0_753;
                sp60 = temp_f0_765;
                sp170 = temp_f0_765;
                sp68 = temp_r30_934->unk38 + (f32) spF8;
                temp_r30_934->unk30 = (f32) sp170;
                sp178 = (f64) sp68;
                temp_r30_934->unk34 = (*(f32 *) ((u8 *) &sp170 + 0x4));
                temp_r30_934->unk38 = (f32) sp178;
                temp_r30_934->unk3C = 1.0f;
                if ((M2C_FIELD(temp_r30_934, f32 *, 0x54) <= 0.0f) || ((((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + ((*(f32 *) ((u8 *) &sp180 + 0x4)) * (*(f32 *) ((u8 *) &sp180 + 0x4))))) <= 10000.0f)) {
                    M2C_FIELD(temp_r30_934, f32 *, 0x54) = 1.0f;
                    M2C_FIELD(temp_r30_934, s32 *, 0x50) = 3;
                    this->unkA8.unk50 = 0;
                    temp_r3_805 = M2C_FIELD(temp_r30_934, void ***, 0x58);
                    if (temp_r3_805 != NULL) {
                        temp_r3_812 = M2C_FIELD(M2C_FIELD(*temp_r3_805, void *(**)(), 8)(), void **, 8);
                        temp_f1_814 = M2C_FIELD(temp_r3_812, f64 *, 0x30);
                        temp_f0_815 = M2C_FIELD(temp_r3_812, f64 *, 0x38);
                        spE0 = temp_f1_814;
                        M2C_FIELD(this, f64 *, 0xB8) = temp_f1_814;
                        M2C_FIELD(this, f64 *, 0xC0) = temp_f0_815;
                        this->unkA8.unk48 = 1;
                        temp_r3_820 = M2C_FIELD(temp_r30_934, void ***, 0x58);
                        spE8 = temp_f0_815;
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(*temp_r3_820, void *(**)(void **, f64), 8)(temp_r3_820, temp_f1_814), void **, 0x44), M2C_UNK (**)(BreathHitMessage *), 0x2C)(&this->unkA8);
                    }
                    this->unk114->Trigger(*((MKVector3 *) &temp_r30_934->unk30), 1.0f);
                    temp_r3_840 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0));
                    if (temp_r3_840 != NULL) {
                        temp_r26_850 = M2C_FIELD(temp_r3_840, void **, 0x2C);
                        sp10 = -temp_r30_934->unk20;
                        sp14 = -temp_r30_934->unk24;
                        sp18 = -temp_r30_934->unk28;
                        spB0 = (f64) sp10;
                        spB8 = (f64) sp18;
                        spC0.operator*(200.0f);
                        sp30 = M2C_FIELD(temp_r30_934, f64 *, 0x30) + M2C_BITWISE(f64, spC0);
                        M2C_FIELD(temp_r3_840, f64 *, 0) = sp30;
                        sp38 = temp_r30_934->unk38 + spC0.unk8;
                        M2C_FIELD(temp_r3_840, f64 *, 8) = (f64) sp38;
                        M2C_FIELD(temp_r3_840, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_840, f32 *, 0x28) = 0.0f;
                        M2C_FIELD(temp_r26_850, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
                        M2C_FIELD(temp_r26_850, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
                        spD0 = sp30;
                        spD8 = (f64) sp38;
                        M2C_FIELD(temp_r26_850, f32 *, 0x18) = 1.5f;
                        M2C_FIELD(temp_r26_850, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r26_850, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
                    }
                }
                break;
            case 3:                                 /* switch 1 */
                var_f1_897 = M2C_FIELD(temp_r30_934, f32 *, 0x54);
                if (var_f1_897 < 1.0f) {

                } else {
                    var_f1_897 = 1.0f;
                }
                if (var_f1_897 > 0.0f) {

                } else {
                    var_f1_897 = 0.0f;
                }
                temp_r30_934->Scale3x3(temp_r30_934, var_f1_897);
                if (M2C_FIELD(temp_r30_934, f32 *, 0x54) <= 0.0f) {
                    M2C_FIELD(temp_r30_934, s32 *, 0x50) = 0;
                    temp_r3_922 = this->unk100;
                    this->unk100 = temp_r3_922 + 4;
                    temp_r4_925 = *temp_r3_922;
                    *temp_r3_922 = *var_r29_446;
                    *var_r29_446 = temp_r4_925;
                }
                break;
            }
            var_r29_446 += 4;
            goto loop_56;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void FuryFXIce2::FindInRangeTargets(float arg0) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    TargetManager ***var_r29_978;
    TargetManager **temp_r30_1076;
    Targetable ***temp_r3_1063;
    Targetable ***temp_r3_1067;
    f64 temp_f0_1042;
    f64 temp_f1_1035;
    void *temp_r3_1034;
    void *temp_r3_985;

loop_2:
    if ((Targetable **) M2C_FIELD(this->unk108, Targetable ***, 0) != NULL) {
        this->unk108 += 4;
        goto loop_2;
    }
    this->unk10C = NULL;
    var_r29_978 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_14:
    if (var_r29_978 != NULL) {
        temp_r30_1076 = *var_r29_978;
        if (temp_r30_1076 != NULL) {
            temp_r3_985 = (*temp_r30_1076)->unk8.unk0(temp_r30_1076);
            if ((temp_r3_985 != NULL) && ((M2C_FIELD(*temp_r30_1076, u8 (**)(TargetManager **), 0x18)(temp_r30_1076) == 0) || ((((u32 (*)(TargetManager **)) (*temp_r30_1076)->unk8.unk4)(temp_r30_1076) != 0U) && (((Character *) (((Character *(*)(TargetManager **)) (*temp_r30_1076)->unk8.unk4)(temp_r30_1076)))->IsActive() != 0))) && (temp_r3_985 != M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u32 (**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0))) && (M2C_FIELD(*gMK, u8 (**)(void **, void *, s32), 0x9C)(gMK, temp_r3_985, *MKResource::sWorkingChunkID) != 0)) {
                temp_r3_1034 = M2C_FIELD((*temp_r30_1076)->unk8.unk0(temp_r30_1076), void **, 8);
                temp_f1_1035 = M2C_FIELD(temp_r3_1034, f64 *, 0x30);
                sp18 = temp_f1_1035;
                sp20 = M2C_FIELD(temp_r3_1034, f64 *, 0x38);
                temp_f0_1042 = temp_f1_1035 - this->unk98;
                sp8 = temp_f0_1042;
                sp28 = temp_f0_1042;
                sp10 = (f32) sp20 - this->unkA0;
                sp30 = (f64) sp10;
                if ((((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4))))) <= arg0) {
                    temp_r3_1063 = this->unk108;
                    if ((u32) M2C_FIELD(temp_r3_1063, u32 *, -4) != 0U) {
                        temp_r3_1067 = temp_r3_1063 - 4;
                        this->unk108 = temp_r3_1067;
                        **temp_r3_1067 = (Targetable *) temp_r30_1076;
                    }
                }
            }
            var_r29_978 += 4;
            goto loop_14;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
s32 FuryFXIce2::Trigger(const MKVector3 &arg0) {
    IceExplosion *temp_r3_1098;
    s32 temp_r0_1117;
    s32 temp_r29_1140;
    s32 temp_r3_1115;
    s32 var_r30_1133;
    u8 var_r3_1123;
    void *temp_r5_1119;

    temp_r3_1098 = this->unk114;
    temp_r3_1098->Enable();
    this->unk90 = 1;
    this->unk94 = 3.0f;
    this->unk98 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xA0) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    temp_r3_1115 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_1117 = *(&GameData::gameData[0x70] + (temp_r3_1115 + 0x7C));
    temp_r5_1119 = &GameData::gameData[0x70] + (temp_r3_1115 + 0x64);
    if (temp_r0_1117 == 3) {
        var_r3_1123 = 0;
        if (((s32) M2C_FIELD(temp_r5_1119, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_1119, s32 *, 4) == 3)) {
            var_r3_1123 = 1;
        }
        var_r30_1133 = var_r3_1123 != 0;
    } else {
        var_r30_1133 = *(temp_r5_1119 + (temp_r0_1117 * 4));
    }
    temp_r29_1140 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unkA8.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), 15.0f * M2C_FIELD(&gb, f32 *, 0x37C), 3, var_r30_1133, temp_r29_1140, temp_r29_1140, 0, -1);
    FindInRangeTargets(9e6f);
    if ((Targetable **) *this->unk108 != NULL) {
        KDSound_Play3d(GS_SpyroFuryIce3, (MKVector3 *) &this->unk98, 0U, -1, 0.0f, 0U);
    } else {
        KDSound_Play3d(GS_SpyroFuryIce6, (MKVector3 *) &this->unk98, 0U, -1, 0.0f, 0U);
    }
    M2C_FIELD(&gb, s8 *, 0x381) = 1;
    return 1;
}
#endif

void FuryFXIce2::SetDefaults() {
    FuryFX::SetDefaults();
    this->unk90 = 0;
}

extern "C" void free(void *);

void FuryFXIce2::Deinit() {
    u32 var_r30_1226;
    Matrix **var_r3_1227;
    Matrix **var_r4_1225;
    u32 temp_r0_1235;
    u32 temp_r0_1249;
    u32 var_r30_1268;
    Targetable ***var_r3_1269;
    Targetable ***var_r4_1267;
    u32 temp_r0_1277;
    u32 temp_r0_1291;

    MKModel_Destroy(this->unk104);
    var_r4_1225 = this->unk100;
    var_r30_1226 = (u32) var_r4_1225;
    var_r3_1227 = var_r4_1225 - 1;
    temp_r0_1235 = (u32) *var_r3_1227;
    while (temp_r0_1235 != 0U) {
        if (temp_r0_1235 < var_r30_1226) {
            var_r30_1226 = temp_r0_1235;
        }
        var_r3_1227 -= 1;
        temp_r0_1235 = (u32) *var_r3_1227;
    }
    if (var_r3_1227 != (Matrix **) &gEmptyPtrListDL) {
        temp_r0_1249 = (u32) *var_r4_1225;
        while (temp_r0_1249 != 0U) {
            if (temp_r0_1249 < var_r30_1226) {
                var_r30_1226 = temp_r0_1249;
            }
            var_r4_1225 += 1;
            temp_r0_1249 = (u32) *var_r4_1225;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free((const void *) var_r30_1226, NULL, 0);
        } else {
            free((void *) var_r30_1226);
        }
    }
    this->unk100 = NULL;
    var_r4_1267 = this->unk108;
    var_r30_1268 = (u32) var_r4_1267;
    var_r3_1269 = var_r4_1267 - 1;
    temp_r0_1277 = (u32) *var_r3_1269;
    while (temp_r0_1277 != 0U) {
        if (temp_r0_1277 < var_r30_1268) {
            var_r30_1268 = temp_r0_1277;
        }
        var_r3_1269 -= 1;
        temp_r0_1277 = (u32) *var_r3_1269;
    }
    if (var_r3_1269 != (Targetable ***) &gEmptyPtrListDL) {
        temp_r0_1291 = (u32) *var_r4_1267;
        while (temp_r0_1291 != 0U) {
            if (temp_r0_1291 < var_r30_1268) {
                var_r30_1268 = temp_r0_1291;
            }
            var_r4_1267 += 1;
            temp_r0_1291 = (u32) *var_r4_1267;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free((const void *) var_r30_1268, NULL, 0);
        } else {
            free((void *) var_r30_1268);
        }
    }
    this->unk108 = NULL;
    FuryFX::Deinit();
}

void FuryFXIce2::Draw() {
    DrawIceSpears();
}

void *FuryFXIce2::Update() {
    s8 sp158;
    s32 sp154;
    s32 sp150;
    s32 sp14C;
    f32 sp148;
    s32 sp144;
    s8 sp143;
    s8 sp142;
    s16 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
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
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
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
    f32 temp_f1_1411;
    f32 temp_f28_1406;
    f32 temp_f29_1409;
    f32 temp_f31_1405;
    f32 var_f0_1382;
    f64 temp_f0_1508;
    f64 temp_f1_1421;
    f64 temp_f1_1432;
    s32 temp_r0_1357;

    FuryFX::Update();
    UpdateIceSpears();
    if ((s32) this->unk90 != 0) {
        this->unk94 -= gUpdateTimeDelta;
        temp_r0_1357 = this->unk90;
        switch (temp_r0_1357) {                     /* irregular */
        case 1:
            TargetAndSpawnIceSpear();
            if (this->unk94 <= 0.0f) {
                this->unk94 = 1.5f;
                this->unk90 = 2;
                return;
            }
            break;
        case 2:
            var_f0_1382 = this->unk94;
            if (var_f0_1382 < 1.5f) {

            } else {
                var_f0_1382 = 1.5f;
            }
            if (var_f0_1382 > 0.0f) {

            } else {
                var_f0_1382 = 0.0f;
            }
            this->unk94 = var_f0_1382;
            temp_f31_1405 = 1.0f - (this->unk94 / 1.5f);
            temp_f28_1406 = 31.415928f * temp_f31_1405;
            temp_f29_1409 = -_table_sinf(1.5707964f + temp_f28_1406);
            temp_f1_1411 = _table_sinf(temp_f28_1406);
            sp80 = temp_f29_1409;
            sp78 = temp_f1_1411;
            sp7C = 0.0f;
            spD0 = (f64) sp80;
            spC8 = (f64) sp78;
            temp_f1_1421 = spC8 * 5.717499035e-315;
            sp68 = temp_f1_1421;
            spD8 = temp_f1_1421;
            sp70 = (f32) spD0 * 2000.0f;
            spE0 = (f64) sp70;
            temp_f1_1432 = temp_f1_1421 * (f64) temp_f31_1405;
            sp58 = temp_f1_1432;
            spE8 = temp_f1_1432;
            sp60 = (f32) spE0 * temp_f31_1405;
            spF0 = (f64) sp60;
            sp48 = spE8 + this->unk98;
            sp20 = 0.0f;
            sp50 = (f32) spF0 + this->unkA0;
            sp18 = 0.0f;
            sp1C = -1000.0f;
            spF8 = sp48;
            sp88 = (f64) sp18;
            sp100 = (f64) sp50;
            sp108 = 0.0f;
            sp10C = 0.0f;
            sp110 = 0.0f;
            sp118 = 0.0f;
            sp11C = 0.0f;
            sp120 = 0.0f;
            sp128 = 0.0f;
            sp12C = 0.0f;
            sp130 = 0.0f;
            sp134 = 1.0f;
            sp138 = 0.0f;
            sp13C = 0.0f;
            sp140 = 0;
            sp142 = 0;
            sp143 = 0;
            sp144 = 0;
            sp148 = 3.4028235e38f;
            sp14C = 0;
            sp150 = 0;
            sp154 = -1;
            sp158 = 0;
            sp90 = (f64) sp20;
            sp8 = spF8 + sp88;
            sp10 = (f32) sp100 + (f32) sp90;
            sp40 = 0.0f;
            sp38 = 0.0f;
            sp3C = 300.0f;
            sp98 = sp8;
            spA8 = (f64) sp38;
            spA0 = (f64) sp10;
            spB0 = (f64) sp40;
            temp_f0_1508 = spF8 + spA8;
            sp28 = temp_f0_1508;
            spB8 = temp_f0_1508;
            sp30 = (f32) sp100 + (f32) spB0;
            spC0 = (f64) sp30;
            MKCollision_RayCollide(*((MKVector3 *) &spB8), *((MKVector3 *) &sp98), (MKCollisionResult *) &sp108, (MKCollisionMode) 4, 0x0C000000);
            if (this->unk94 <= 0.0f) {
                this->unk94 = 0.5f;
                this->unk90 = 3;
                return;
            }
            break;
        case 3:
            if (this->unk94 <= 0.0f) {
                this->unk94 = 0.0f;
                this->unk90 = 0;
                M2C_FIELD(&gb, s8 *, 0x381) = 0;
            }
            break;
        }
    }
}

f32 FuryFXIce2::Resolve() {
    FuryFX::Resolve();
}

void FuryFXIce2::Init() {
    Matrix **temp_r3_1614;
    Matrix **temp_r3_1620;
    Matrix **var_r3_1599;
    Matrix **var_r3_1632;
    Matrix **var_r5_1608;
    Targetable ***temp_r3_1647;
    Targetable ***temp_r4_1653;
    Targetable ***var_r5_1641;
    s32 var_ctr_1612;
    s32 var_ctr_1645;

    FuryFX::Init();
    SetDefaults();
    this->unk104 = MKModel_Create("FX0027_IceSpear", NULL, 2, NULL);
    if (MKHeap::Current() != NULL) {
        var_r3_1599 = (Matrix **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x4E28, NULL, 0));
    } else {
        var_r3_1599 = malloc(0x4E28);
    }
    this->unk100 = var_r3_1599;
    var_r5_1608 = this->unk100;
    this->unk100 = var_r5_1608 + 0x4B00;
    M2C_FIELD(var_r5_1608, s32 *, 0x4B00) = 0;
    var_ctr_1612 = 0xC8;
    do {
        temp_r3_1614 = this->unk100;
        this->unk100 = temp_r3_1614 + 4;
        M2C_FIELD(temp_r3_1614, Matrix ***, 4) = var_r5_1608;
        var_r5_1608 += 0x60;
        var_ctr_1612 -= 1;
    } while (var_ctr_1612 != 0);
    temp_r3_1620 = this->unk100;
    this->unk100 = temp_r3_1620 + 4;
    M2C_FIELD(temp_r3_1620, Matrix ***, 4) = NULL;
    if (MKHeap::Current() != NULL) {
        var_r3_1632 = (Matrix **) (((MKHeap *) (MKHeap::Current()))->Alloc(0xA8, NULL, 0));
    } else {
        var_r3_1632 = malloc(0xA8);
    }
    this->unk108 = (Targetable ***) var_r3_1632;
    var_r5_1641 = this->unk108;
    this->unk108 = var_r5_1641 + 0x50;
    M2C_FIELD(var_r5_1641, s32 *, 0x50) = 0;
    var_ctr_1645 = 0x14;
    do {
        temp_r3_1647 = this->unk108;
        this->unk108 = temp_r3_1647 + 4;
        M2C_FIELD(temp_r3_1647, Targetable ****, 4) = var_r5_1641;
        var_r5_1641 += 4;
        var_ctr_1645 -= 1;
    } while (var_ctr_1645 != 0);
    temp_r4_1653 = this->unk108;
    this->unk108 = temp_r4_1653 + 4;
    M2C_FIELD(temp_r4_1653, Targetable ****, 4) = NULL;
    this->unk114 = checked_cast<IceExplosion *, MKProp>(((MKSceneManager *) gMK)->CreateProp("IceExplosion"));
}

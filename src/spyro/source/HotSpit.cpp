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

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void HotSpit::Update() {
    Matrix sp1F0;
    Matrix sp1B0;
    f64 sp1A0;                                      /* compiler-managed */
    f64 sp198;                                      /* compiler-managed */
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    M2C_UNK sp148;
    f64 sp140;
    f64 sp138;
    f64 sp128;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
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
    f64 temp_f0_207;
    f64 temp_f0_269;
    f64 temp_f0_342;
    f64 temp_f0_354;
    f64 temp_f1_104;
    f64 temp_f1_110;
    f64 temp_f1_114;
    s32 temp_r3_133;
    s32 var_r0_143;

    Projectile::Update();
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &sp1F0);
    } else {
        M2C_STRUCT_COPY((s32) &sp1B0.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_78 = 0.0f;
    sp90 = 0.0f;
    sp88 = 0.0f;
    sp8C = 1.0f;
    sp190 = (f64) sp90;
    sp188 = (f64) sp88;
    sp198 = this->unkC8;
    sp1A0 = this->unkD0;
    var_f5_99 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + (unksp19C * unksp19C));
    if (var_f5_99 > 0.000001f) {
        if (var_f5_99 > 0.0f) {
            temp_f1_104 = __frsqrte(var_f5_99);
            temp_f1_110 = 0.5 * temp_f1_104 * -(((f64) var_f5_99 * (temp_f1_104 * temp_f1_104)) - 3.0);
            temp_f1_114 = 0.5 * temp_f1_110 * -(((f64) var_f5_99 * (temp_f1_110 * temp_f1_110)) - 3.0);
            var_f5_99 = (f32) ((f64) var_f5_99 * (0.5 * temp_f1_114 * -(((f64) var_f5_99 * (temp_f1_114 * temp_f1_114)) - 3.0)));
        } else if (var_f5_99 < M2C_BITWISE(f32, 0.0)) {
            var_f5_99 = __float_nan;
        } else {
            sp10 = var_f5_99;
            temp_r3_133 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_133) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_143 = 1;
                } else {
                    var_r0_143 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    sp198 = (f32) sp198 * var_f4_78;
    unksp19C *= var_f4_78;
    sp1A0 = (f32) sp1A0 * var_f4_78;
    if (var_f5_99 != 0.0f) {
        temp_f31_182 = gUpdateTimeDelta;
        temp_f29_187 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        temp_f28_192 = MKRand_Float(&gViewSeed, 1.0f, 3.0f);
        MKVector(MKRand_Float(&gViewSeed, 1.0f, 3.0f), temp_f28_192, temp_f29_187);
        sp158.operator*(3.0f);
        temp_f0_207 = sp158 * (f64) temp_f31_182;
        sp38 = temp_f0_207;
        sp168 = temp_f0_207;
        sp40 = sp158.unk8 * temp_f31_182;
        sp170 = (f64) sp40;
        M2C_FIELD(this, f64 *, 0x150) = (f64) (M2C_FIELD(this, f64 *, 0x150) + temp_f0_207);
        this->unk158 += (f32) sp170;
        KDMath_BuildMatrixFromFwd(&sp1B0, *((MKVector3 *) &sp198), (MKVector3 *) &sp188);
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
        temp_f0_269 = sp128 + sp118;
        sp28 = temp_f0_269;
        sp138 = temp_f0_269;
        sp30 = sp130 + sp120;
        sp140 = (f64) sp30;
        sp1B0.Scale3x3(&sp1B0, *((MKVector3 *) &sp138));
        sp1B0.unk30 = sp1F0.unk30;
        sp1B0.unk34 = sp1F0.unk34;
        sp1B0.unk38 = sp1F0.unk38;
        sp1B0.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp1B0);
    }
    MKVector(0.0f, 200.0f, 0.0f);
    spF8.operator*(0.5f);
    sp18 = spF8 + spE8;
    sp80 = -1.0f;
    sp70 = 1.0f;
    sp20 = spF8.unk8 + spF0;
    sp78 = -1.0f;
    sp7C = -1.0f;
    sp68 = 1.0f;
    sp6C = -1.0f;
    sp108 = sp18;
    sp110 = (f64) sp20;
    sp178 = sp18;
    sp180 = (f64) sp20;
    spA8 = (f64) sp78;
    spB0 = (f64) sp80;
    sp98 = (f64) sp68;
    spA0 = (f64) sp70;
    KDRand_Vector(spB8, *((MKVector3 *) &spA8));
    temp_f0_342 = spB8 * 5.45263811e-315;
    sp58 = temp_f0_342;
    spC8 = temp_f0_342;
    sp60 = spB8.unk8 * 25.0f;
    spD0 = (f64) sp60;
    temp_f0_354 = sp1F0.unk30 + temp_f0_342;
    sp48 = temp_f0_354;
    spD8 = temp_f0_354;
    sp50 = sp1F0.unk38 + (f32) spD0;
    spE0 = (f64) sp50;
    sp14 = MKRand_Float(&gViewSeed, 8.0f, 12.0f);
    ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &spD8), *((MKVector3 *) &sp178), sp14);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void HotSpit::Collided(MKCollisionResult &arg0) {
    s8 sp2C9;
    s8 sp2C8;
    s32 sp2C4;
    f32 sp2C0;
    s32 sp2BC;
    s8 sp2BA;
    s8 sp2B9;
    s8 sp2B8;
    f64 sp2B0;                                      /* compiler-managed */
    f64 sp2A8;                                      /* compiler-managed */
    MKProp *sp2A4;
    s32 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    s32 sp27C;
    s32 sp278;
    u8 sp270;
    s32 sp26C;
    void *sp268;
    s32 sp264;
    f32 sp260;
    s32 sp25C;
    s8 sp25B;
    s8 sp25A;
    s16 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    Matrix sp1E0;
    M2C_UNK sp1DC;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;                                      /* compiler-managed */
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    MKVector3 sp188;
    MKVector3 sp178;
    MKVector3 sp168;
    M2C_UNK sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    MKVector3 spF8;
    M2C_UNK spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f64 sp88;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKProp *temp_r4_555;
    MKProp *temp_r4_764;
    MKPtrList<MKProp> *temp_r4_860;
    MKPtrList<MKProp> *temp_r6_620;
    f32 var_f4_650;
    f32 var_f5_688;
    f64 temp_f0_815;
    f64 temp_f0_826;
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
        MKModel_GetWorldMatrixWithAttachment(this->unk4, &sp1E0);
    } else {
        M2C_STRUCT_COPY((s32) &sp1DC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_r26_437 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(sp178, sp168);
        sp188.operator*(3000.0f);
        sp198.operator*(2.0f);
        sp48 = sp198 + M2C_BITWISE(f64, sp188);
        sp98 = 1.0f;
        sp9C = 1.0f;
        sp50 = sp198.unk8 + sp188.unk8;
        spA0 = 1.0f;
        spA4 = 1.0f;
        sp1C8 = sp48;
        sp1D0 = (f64) sp50;
        sp148 = (f64) sp98;
        sp150 = (f64) spA0;
        temp_r3_485 = M2C_FIELD(temp_r28_411, void **, 0xF0);
        sp1A8 = sp48;
        sp1B0 = (f64) sp50;
        M2C_FIELD(M2C_FIELD(temp_r3_485, void **, 0x44), M2C_UNK (**)(void *, f32 *, f64 *, f64 *, f32, f64, f64, f64), 0x3C)(temp_r3_485, &sp1E0.unk30, &sp1C8, &sp148, 2.0f, (f64) sp98, (f64) sp50, sp48);
        var_r26_437 += 1;
    } while (var_r26_437 < 5);
    var_r26_498 = 0;
    do {
        MKVector(1.0f, 1.5f, 1.0f);
        MKVector(-1.0f, 1.0f, -1.0f);
        KDRand_Vector(sp108, spF8);
        sp118.operator*(1000.0f);
        sp128.operator*(0.5f);
        sp38 = sp128 + M2C_BITWISE(f64, sp118);
        sp138 = sp38;
        sp40 = sp128.unk8 + sp118.unk8;
        sp1C8 = sp38;
        sp140 = (f64) sp40;
        sp1D0 = (f64) sp40;
        sp14 = MKRand_Float(&gViewSeed, 10.0f, 20.0f);
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp1E0.unk30), *((MKVector3 *) &sp1C8), sp14);
        var_r26_498 += 1;
    } while (var_r26_498 < 0xA);
    sp27C = 0;
    temp_r4_555 = this->unk130;
    sp30 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    spE0 = (f64) sp30;
    spD8 = (f64) sp28;
    sp278 = 7;
    sp2A0 = 1;
    sp2A4 = temp_r4_555;
    sp280 = (f64) sp28;
    sp288 = (f64) sp30;
    sp2B8 = 0;
    sp2C4 = 2;
    sp2C0 = 10.0f;
    sp2B9 = 0;
    sp2BA = 1;
    sp2BC = -1;
    sp290 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp298 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp2C8 = 0;
    if (temp_r4_555 != NULL) {
        sp88.GetPos();
        sp2A8 = sp88;
        sp2B0 = sp90;
    } else {
        sp2A8 = 0.0f;
        unksp2AC = 0.0f;
        sp2B0 = 0.0f;
    }
    sp2C9 = 0;
    KDSound_Play3d(GS_BBFireballSplat, (MKVector3 *) &sp1E0.unk30, 0U, -1, 0.0f, 0U);
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
            M2C_FIELD(M2C_FIELD(var_r3_611, void **, 0x44), M2C_UNK (**)(s32 *, void **), 0x2C)(&sp278, temp_r5_642);
        }
    }
    var_f4_650 = 0.0f;
    sp220 = 0.0f;
    sp224 = 0.0f;
    sp228 = 0.0f;
    sp230 = 0.0f;
    sp234 = 0.0f;
    sp238 = 0.0f;
    sp240 = 0.0f;
    sp244 = 0.0f;
    sp248 = 0.0f;
    sp24C = 1.0f;
    sp250 = 0.0f;
    sp254 = 0.0f;
    sp258 = 0;
    sp25A = 0;
    sp25B = 0;
    sp25C = 0;
    sp260 = 3.4028235e38f;
    sp264 = 0;
    sp268 = NULL;
    sp26C = -1;
    sp270 = 0;
    sp1B8 = this->unkC8;
    sp1C0 = this->unkD0;
    unksp1BC = 0.0f;
    var_f5_688 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + (0.0f * 0.0f));
    if (var_f5_688 > 0.000001f) {
        if (var_f5_688 > 0.0f) {
            temp_f1_693 = __frsqrte(var_f5_688);
            temp_f1_699 = 0.5 * temp_f1_693 * -(((f64) var_f5_688 * (temp_f1_693 * temp_f1_693)) - 3.0);
            temp_f1_703 = 0.5 * temp_f1_699 * -(((f64) var_f5_688 * (temp_f1_699 * temp_f1_699)) - 3.0);
            var_f5_688 = (f32) ((f64) var_f5_688 * (0.5 * temp_f1_703 * -(((f64) var_f5_688 * (temp_f1_703 * temp_f1_703)) - 3.0)));
        } else if (var_f5_688 < M2C_BITWISE(f32, 0.0)) {
            var_f5_688 = __float_nan;
        } else {
            sp10 = var_f5_688;
            temp_r3_722 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_722) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_732 = 1;
                } else {
                    var_r0_732 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp1B8 = (f32) sp1B8 * var_f4_650;
    unksp1BC *= var_f4_650;
    sp1C0 = (f32) sp1C0 * var_f4_650;
    spC8 = (f64) sp18;
    spD0 = (f64) sp20;
    sp278 = 7;
    sp2A0 = 1;
    sp2A4 = temp_r4_764;
    sp280 = (f64) sp18;
    sp288 = (f64) sp20;
    sp2B8 = 0;
    sp2C4 = 2;
    sp2C0 = 10.0f;
    sp2B9 = 0;
    sp2BA = 1;
    sp2BC = -1;
    sp290 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp298 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp2C8 = 0;
    if (temp_r4_764 != NULL) {
        sp78.GetPos();
        sp2A8 = sp78;
        sp2B0 = sp80;
    } else {
        sp2A8 = 0.0f;
        unksp2AC = 0.0f;
        sp2B0 = 0.0f;
    }
    sp2C9 = 0;
    temp_f0_815 = (f64) sp1B8 * 5.64367472e-315;
    sp68 = temp_f0_815;
    spA8 = temp_f0_815;
    sp70 = sp1C0 * 600.0f;
    spB0 = (f64) sp70;
    temp_f0_826 = sp1E0.unk30 + temp_f0_815;
    sp58 = temp_f0_826;
    spB8 = temp_f0_826;
    sp60 = sp1E0.unk38 + (f32) spB0;
    spC0 = (f64) sp60;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp1E0.unk30), *((MKVector3 *) &spB8), 200.0f, (MKCollisionResult *) &sp220, (MKCollisionMode) 2, 0x08000000) != 0) {
        if ((sp270 != 0) && (sp268 != NULL) && (var_r3_851 = M2C_FIELD(sp268, void **, 8), ((var_r3_851 == NULL) == 0))) {

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
                M2C_FIELD(M2C_FIELD(var_r3_851, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp278);
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

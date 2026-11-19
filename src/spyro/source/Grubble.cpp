#include "spyro/source/Grubble.h"
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
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;
extern void **gb;

#if 0 // DRAFT: illegal use of non-static member
void GrubbleCritter::Deinit() {
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

void GrubbleCritter::Draw() {
    Matrix sp10;
    M2C_UNK spC;
    s32 var_r30_92;
    s32 var_r31_93;
    void *temp_r29_97;

    var_r30_92 = 0;
    var_r31_93 = 0;
loop_4:
    if (var_r30_92 < (s32) this->unk90) {
        temp_r29_97 = ((u8 *) this->unk170) + var_r31_93;
        if ((s32) M2C_FIELD(temp_r29_97, s32 *, 0x60) != 0) {
            this->unk80->SetAnim(M2C_FIELD(temp_r29_97, MKAnim **, 0x50), 0.0f, 0.0f, 0, -1);
            this->unk80->JumpToPos(M2C_FIELD(temp_r29_97, f32 *, 0x54), -1);
            M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) temp_r29_97) - 4) + 4, 0x40);
            MKModel_SetWorldMatrix(this->unk4, sp10);
            MKModel_Draw(this->unk4, NULL);
        }
        var_r30_92 += 1;
        var_r31_93 += 0x70;
        goto loop_4;
    }
}

#if 0 // DRAFT: undefined identifier 'spF8'
void GrubbleCritter::FindNewWalkParameters(Grubble *arg0) {
    s8 sp1E0;
    s32 sp1DC;
    s32 sp1D8;
    s32 sp1D4;
    f32 sp1D0;
    s32 sp1CC;
    s8 sp1CB;
    s8 sp1CA;
    s16 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;                                      /* compiler-managed */
    f64 sp150;                                      /* compiler-managed */
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
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
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
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f3_314;
    f32 var_f31_327;
    f32 var_f3_394;
    f64 temp_f0_220;
    f64 temp_f0_283;
    f64 temp_f0_308;
    f64 temp_f1_333;
    f64 temp_f1_339;
    f64 temp_f1_343;
    s32 temp_r29_405;
    s32 temp_r3_362;
    s32 var_r0_372;

    spA8 = 0.0f;
    sp78 = 0.0f;
    spA0 = 0.0f;
    spA4 = 1.0f;
    sp70 = 0.0f;
    sp74 = -500.0f;
    sp180 = arg0->unk30;
    sp188 = arg0->unk38;
    sp170 = (f64) spA0;
    sp178 = (f64) spA8;
    sp190 = 0.0f;
    sp194 = 0.0f;
    sp198 = 0.0f;
    sp1A0 = 0.0f;
    sp1A4 = 0.0f;
    sp1A8 = 0.0f;
    sp1B0 = 0.0f;
    sp1B4 = 0.0f;
    sp1B8 = 0.0f;
    sp1BC = 1.0f;
    sp1C0 = 0.0f;
    sp1C4 = 0.0f;
    sp1C8 = 0;
    sp1CA = 0;
    sp1CB = 0;
    sp1CC = 0;
    sp1D0 = 3.4028235e38f;
    sp1D4 = 0;
    sp1D8 = 0;
    sp1DC = -1;
    sp1E0 = 0;
    sp100 = (f64) sp70;
    sp108 = (f64) sp78;
    sp60 = sp180 + sp100;
    sp98 = 0.0f;
    sp90 = 0.0f;
    sp94 = 200.0f;
    sp68 = (f32) sp188 + (f32) sp108;
    sp120 = (f64) sp90;
    sp110 = sp60;
    sp118 = (f64) sp68;
    sp128 = (f64) sp98;
    temp_f0_220 = sp180 + sp120;
    sp80 = temp_f0_220;
    sp130 = temp_f0_220;
    sp88 = (f32) sp188 + (f32) sp128;
    sp138 = (f64) sp88;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp130), *((MKVector3 *) &sp110), (MKCollisionResult *) &sp190, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp180 = (f64) sp190;
        sp188 = (f64) sp198;
        sp170 = (f64) sp1A0;
        sp178 = (f64) sp1A8;
    }
    ((Volume *) &spF0)->GetRandPos();
    sp30 = 0.0f;
    sp34 = -500.0f;
    sp38 = 0.0f;
    sp160 = spF0;
    spB0 = (f64) sp30;
    sp168 = spF8;
    spB8 = (f64) sp38;
    sp20 = sp160 + spB0;
    sp58 = 0.0f;
    sp50 = 0.0f;
    sp54 = 200.0f;
    sp28 = (f32) sp168 + (f32) spB8;
    spD0 = (f64) sp50;
    spC0 = sp20;
    spC8 = (f64) sp28;
    spD8 = (f64) sp58;
    temp_f0_283 = sp160 + spD0;
    sp40 = temp_f0_283;
    spE0 = temp_f0_283;
    sp48 = (f32) sp168 + (f32) spD8;
    spE8 = (f64) sp48;
    if (MKCollision_RayCollide(*((MKVector3 *) &spE0), *((MKVector3 *) &spC0), (MKCollisionResult *) &sp190, (MKCollisionMode) 4, 0x0C000000) != 0) {
        sp160 = (f64) sp190;
        sp168 = (f64) sp198;
    }
    temp_f0_308 = sp160 - arg0->unk30;
    sp10 = temp_f0_308;
    temp_f3_314 = arg0->unk4;
    sp150 = temp_f0_308;
    sp18 = (f32) sp168 - (f32) M2C_FIELD(arg0, f64 *, 0x38);
    (*(f32 *) ((u8 *) &sp148 + 0xc)) = temp_f3_314;
    sp158 = (f64) sp18;
    var_f31_327 = ((f32) sp158 * (f32) sp158) + (((f32) sp150 * (f32) sp150) + (temp_f3_314 * temp_f3_314));
    if (var_f31_327 > 0.000001f) {
        if (var_f31_327 > 0.0f) {
            temp_f1_333 = __frsqrte(var_f31_327);
            temp_f1_339 = 0.5 * temp_f1_333 * -(((f64) var_f31_327 * (temp_f1_333 * temp_f1_333)) - 3.0);
            temp_f1_343 = 0.5 * temp_f1_339 * -(((f64) var_f31_327 * (temp_f1_339 * temp_f1_339)) - 3.0);
            var_f31_327 = (f32) ((f64) var_f31_327 * (0.5 * temp_f1_343 * -(((f64) var_f31_327 * (temp_f1_343 * temp_f1_343)) - 3.0)));
        } else if (var_f31_327 < M2C_BITWISE(f32, 0.0)) {
            var_f31_327 = __float_nan;
        } else {
            sp8 = var_f31_327;
            temp_r3_362 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_362) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_372 = 1;
                } else {
                    var_r0_372 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_372 = 5;
                } else {
                    var_r0_372 = 3;
                }
                break;
            default:
                var_r0_372 = 4;
                break;
            }
            if (var_r0_372 == 1) {
                var_f31_327 = __float_nan;
            }
        }
        var_f3_394 = 1.0f / var_f31_327;
    } else {
        var_f3_394 = 0.0f;
        var_f31_327 = 0.0f;
    }
    temp_r29_405 = arg0->unk60;
    sp150 = (f32) sp150 * var_f3_394;
    (*(f32 *) ((u8 *) &sp148 + 0xc)) *= var_f3_394;
    sp158 = (f32) sp158 * var_f3_394;
    arg0->unk50 = M2C_FIELD((checked_cast<GrubbleCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r29_405 * 4)), void **, 0x70);
    arg0->unk58 = 30.0f / (30.0f * ((f32) M2C_FIELD(arg0->unk50, s16 *, 4) / 30.0f));
    arg0->unk54 = 0.0f;
    arg0->unk64 = var_f31_327 / 200.0f;
    sp140 = (f64) sp150;
    sp148 = (f64) sp158;
    KDMath_BuildMatrixFromUp((Matrix *) arg0, *((MKVector3 *) &sp170), *((MKVector3 *) &sp140));
    M2C_FIELD(arg0, f64 *, 0x30) = (f32) sp180;
    M2C_FIELD(arg0, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp180 + 0x4));
    M2C_FIELD(arg0, f64 *, 0x38) = (f32) sp188;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
}
#endif

void GrubbleCritter::SetHideState(Grubble *arg0) {
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
    f32 temp_f4_543;
    f64 temp_f0_558;
    f64 temp_f5_537;
    s32 temp_r0_468;
    s32 temp_r31_479;

    temp_r0_468 = arg0->unk60;
    switch (temp_r0_468) {                          /* irregular */
    case 3:
        return;
    default:
        arg0->unk60 = 1;
        temp_r31_479 = arg0->unk60;
        arg0->unk50 = M2C_FIELD((checked_cast<GrubbleCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_479 * 4)), void **, 0x70);
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
        temp_f5_537 = arg0->unk30;
        sp8 = temp_f5_537 + sp48;
        sp40 = 0.0f;
        temp_f4_543 = M2C_FIELD(arg0, f32 *, 0x38);
        sp38 = 0.0f;
        sp10 = temp_f4_543 + (f32) sp50;
        sp3C = 200.0f;
        sp58 = sp8;
        sp60 = (f64) sp10;
        sp68 = (f64) sp38;
        sp70 = (f64) sp40;
        temp_f0_558 = temp_f5_537 + sp68;
        sp28 = temp_f0_558;
        sp78 = temp_f0_558;
        sp30 = temp_f4_543 + (f32) sp70;
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
void GrubbleCritter::Update() {
    s8 sp2E8;
    s32 sp2E4;
    s32 sp2E0;
    s32 sp2DC;
    f32 sp2D8;
    s32 sp2D4;
    s8 sp2D3;
    s8 sp2D2;
    s16 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    s8 sp290;
    s32 sp28C;
    s32 sp288;
    s32 sp284;
    f32 sp280;
    s32 sp27C;
    s8 sp27B;
    s8 sp27A;
    s16 sp278;
    Volume sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
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
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
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
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
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
    Matrix *temp_r30_605;
    f32 temp_f0_899;
    f32 temp_f1_1030;
    f32 temp_f1_747;
    f32 temp_f4_946;
    f32 var_f3_822;
    f32 var_f4_755;
    f64 temp_f0_700;
    f64 temp_f0_881;
    f64 temp_f0_961;
    f64 temp_f1_1091;
    f64 temp_f1_761;
    f64 temp_f1_767;
    f64 temp_f1_771;
    f64 temp_f5_679;
    f64 temp_f5_940;
    s32 temp_r0_614;
    s32 temp_r27_1003;
    s32 temp_r27_1044;
    s32 temp_r3_790;
    s32 var_r0_800;
    s32 var_r28_600;
    s32 var_r31_599;
    void *temp_r3_1090;

    var_r31_599 = 0;
    var_r28_600 = 0;
loop_50:
    if (var_r31_599 < (s32) this->unk90) {
        temp_r30_605 = ((u8 *) this->unk170) + var_r28_600;
        M2C_FIELD(temp_r30_605, f32 *, 0x64) = (f32) (M2C_FIELD(temp_r30_605, f32 *, 0x64) - gUpdateTimeDelta);
        M2C_FIELD(temp_r30_605, f32 *, 0x54) = (f32) ((M2C_FIELD(temp_r30_605, f32 *, 0x58) * gUpdateTimeDelta) + M2C_FIELD(temp_r30_605, f32 *, 0x54));
        temp_r0_614 = M2C_FIELD(temp_r30_605, s32 *, 0x60);
        switch (temp_r0_614) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            sp1F0.GetRandPos();
            spF8 = 0.0f;
            spF0 = 0.0f;
            spF4 = 1.0f;
            spC8 = 0.0f;
            sp1F0.unk30 = (f64) spF0;
            sp1F0.unk38 = (f64) spF8;
            spC0 = 0.0f;
            spC4 = -500.0f;
            sp1F0.unk40 = M2C_BITWISE(f64, sp1F0);
            sp1F0.unk40.unk4 = M2C_FIELD(this->unk8, f32 *, 0x34);
            sp1B0 = (f64) spC0;
            sp1F0.unk40.unk8 = sp1F0.unk8;
            sp298 = 0.0f;
            sp29C = 0.0f;
            sp2A0 = 0.0f;
            sp2A8 = 0.0f;
            sp2AC = 0.0f;
            sp2B0 = 0.0f;
            sp2B8 = 0.0f;
            sp2BC = 0.0f;
            sp2C0 = 0.0f;
            sp2C4 = 1.0f;
            sp2C8 = 0.0f;
            sp2CC = 0.0f;
            sp2D0 = 0;
            sp2D2 = 0;
            sp2D3 = 0;
            sp2D4 = 0;
            sp2D8 = 3.4028235e38f;
            sp2DC = 0;
            sp2E0 = 0;
            sp2E4 = -1;
            sp2E8 = 0;
            sp1B8 = (f64) spC8;
            temp_f5_679 = M2C_BITWISE(f64, sp1F0.unk40);
            spB0 = temp_f5_679 + sp1B0;
            spE8 = 0.0f;
            spE0 = 0.0f;
            spE4 = 200.0f;
            spB8 = sp1F0.unk40.unk8 + (f32) sp1B8;
            sp1D0 = (f64) spE0;
            sp1C0 = spB0;
            sp1C8 = (f64) spB8;
            sp1D8 = (f64) spE8;
            temp_f0_700 = temp_f5_679 + sp1D0;
            spD0 = temp_f0_700;
            sp1E0 = temp_f0_700;
            spD8 = sp1F0.unk40.unk8 + (f32) sp1D8;
            sp1E8 = (f64) spD8;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp1E0), *((MKVector3 *) &sp1C0), (MKCollisionResult *) &sp298, (MKCollisionMode) 4, 0x0C000000) != 0) {
                sp1F0.unk40 = (f64) sp298;
                sp1F0.unk40.unk8 = (f64) sp2A0;
                sp1F0.unk30 = (f64) sp2A8;
                sp1F0.unk38 = (f64) sp2B0;
            }
            spA8 = -1.0f;
            sp98 = 1.0f;
            spA0 = -1.0f;
            spA4 = 0.0f;
            sp90 = 1.0f;
            sp94 = 0.0f;
            sp190 = (f64) spA0;
            sp198 = (f64) spA8;
            sp180 = (f64) sp90;
            sp188 = (f64) sp98;
            KDRand_Vector(sp1A0, *((MKVector3 *) &sp190));
            temp_f1_747 = M2C_BITWISE(f32, sp1A0);
            var_f4_755 = (sp1A0.unk8 * sp1A0.unk8) + ((temp_f1_747 * temp_f1_747) + (sp1A0.unk4 * sp1A0.unk4));
            if (var_f4_755 > 1e-12f) {
                if (var_f4_755 > 0.0f) {
                    temp_f1_761 = __frsqrte(var_f4_755);
                    temp_f1_767 = 0.5 * temp_f1_761 * -(((f64) var_f4_755 * (temp_f1_761 * temp_f1_761)) - 3.0);
                    temp_f1_771 = 0.5 * temp_f1_767 * -(((f64) var_f4_755 * (temp_f1_767 * temp_f1_767)) - 3.0);
                    var_f4_755 = (f32) ((f64) var_f4_755 * (0.5 * temp_f1_771 * -(((f64) var_f4_755 * (temp_f1_771 * temp_f1_771)) - 3.0)));
                } else if (var_f4_755 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_755 = __float_nan;
                } else {
                    sp8 = var_f4_755;
                    temp_r3_790 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_790) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_800 = 1;
                        } else {
                            var_r0_800 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_800 = 5;
                        } else {
                            var_r0_800 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_800 = 4;
                        break;
                    }
                    if (var_r0_800 == 1) {
                        var_f4_755 = __float_nan;
                    }
                }
                var_f3_822 = 1.0f / var_f4_755;
            } else {
                var_f3_822 = 0.0f;
            }
            sp80 = M2C_BITWISE(f32, sp1A0) * var_f3_822;
            sp84 = sp1A0.unk4 * var_f3_822;
            sp88 = sp1A0.unk8 * var_f3_822;
            sp1F0.unk20 = (f64) sp80;
            sp1F0.unk28 = (f64) sp88;
            KDMath_BuildMatrixFromUp(temp_r30_605, *((MKVector3 *) &sp1F0.unk30), *((MKVector3 *) &sp1F0.unk20));
            temp_r30_605->unk30 = (f32) sp1F0.unk40;
            temp_r30_605->unk34 = sp1F0.unk40.unk4;
            temp_r30_605->unk38 = (f32) sp1F0.unk40.unk8;
            temp_r30_605->unk3C = 1.0f;
            M2C_FIELD(temp_r30_605, s32 *, 0x60) = 4;
            FindNewWalkParameters((Grubble *) temp_r30_605);
            break;
        case 4:                                     /* switch 1 */
            sp70 = -temp_r30_605->unk20;
            sp74 = -temp_r30_605->unk24;
            sp78 = -temp_r30_605->unk28;
            sp1F0.unk10 = (f64) sp70;
            sp1F0.unk18 = (f64) sp78;
            sp160.operator*(200.0f * gUpdateTimeDelta);
            temp_f0_881 = (f64) M2C_FIELD(temp_r30_605, f32 *, 0x30) + M2C_BITWISE(f64, sp160);
            sp10 = temp_f0_881;
            sp170 = temp_f0_881;
            sp18 = temp_r30_605->unk38 + sp160.unk8;
            temp_r30_605->unk30 = (f32) sp170;
            sp178 = (f64) sp18;
            temp_r30_605->unk34 = (*(f32 *) ((u8 *) &sp170 + 0x4));
            temp_r30_605->unk38 = (f32) sp178;
            temp_r30_605->unk3C = 1.0f;
            temp_f0_899 = M2C_FIELD(temp_r30_605, f32 *, 0x54);
            if (temp_f0_899 > 1.0f) {
                M2C_FIELD(temp_r30_605, f32 *, 0x54) = (f32) (temp_f0_899 - 1.0f);
            }
            sp40 = 0.0f;
            sp44 = -500.0f;
            sp48 = 0.0f;
            sp1F0.unk40.unk10 = 0.0f;
            sp1F0.unk40.unk14 = 0.0f;
            sp1F0.unk40.unk18 = 0.0f;
            sp1F0.unk40.unk20 = 0.0f;
            sp1F0.unk40.unk24 = 0.0f;
            sp1F0.unk40.unk28 = 0.0f;
            sp1F0.unk40.unk30 = 0.0f;
            sp1F0.unk40.unk34 = 0.0f;
            sp1F0.unk40.unk38 = 0.0f;
            sp1F0.unk40.unk3C = 1.0f;
            sp1F0.unk80 = 0.0f;
            sp1F0.unk84 = 0.0f;
            sp278 = 0;
            sp27A = 0;
            sp27B = 0;
            sp27C = 0;
            sp280 = 3.4028235e38f;
            sp284 = 0;
            sp288 = 0;
            sp28C = -1;
            sp290 = 0;
            sp120 = (f64) sp40;
            sp128 = (f64) sp48;
            temp_f5_940 = (f64) M2C_FIELD(temp_r30_605, f32 *, 0x30);
            sp30 = temp_f5_940 + sp120;
            sp68 = 0.0f;
            temp_f4_946 = temp_r30_605->unk38;
            sp60 = 0.0f;
            sp64 = 200.0f;
            sp38 = temp_f4_946 + (f32) sp128;
            sp140 = (f64) sp60;
            sp130 = sp30;
            sp138 = (f64) sp38;
            sp148 = (f64) sp68;
            temp_f0_961 = temp_f5_940 + sp140;
            sp50 = temp_f0_961;
            sp150 = temp_f0_961;
            sp58 = temp_f4_946 + (f32) sp148;
            sp158 = (f64) sp58;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp150), *((MKVector3 *) &sp130), (MKCollisionResult *) &sp1F0.unk40.unk10, (MKCollisionMode) 4, 0x0C000000) != 0) {
                temp_r30_605->unk30 = sp1F0.unk40.unk10;
                temp_r30_605->unk34 = sp1F0.unk40.unk14;
                temp_r30_605->unk38 = sp1F0.unk40.unk18;
                temp_r30_605->unk3C = 1.0f;
            }
            if (M2C_FIELD(temp_r30_605, f32 *, 0x64) <= 0.0f) {
                FindNewWalkParameters((Grubble *) temp_r30_605);
            }
            break;
        case 1:                                     /* switch 1 */
            if (M2C_FIELD(temp_r30_605, f32 *, 0x54) > 1.0f) {
                M2C_FIELD(temp_r30_605, s32 *, 0x60) = 2;
                temp_r27_1003 = M2C_FIELD(temp_r30_605, s32 *, 0x60);
                M2C_FIELD(temp_r30_605, void **, 0x50) = (void *) *(checked_cast<GrubbleCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_1003 * 4) + 0x70));
                M2C_FIELD(temp_r30_605, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_605, void **, 0x50), s16 *, 4) / 30.0f)));
                M2C_FIELD(temp_r30_605, f32 *, 0x54) = 0.0f;
                M2C_FIELD(temp_r30_605, f32 *, 0x64) = 5.0f;
            }
            break;
        case 2:                                     /* switch 1 */
            temp_f1_1030 = M2C_FIELD(temp_r30_605, f32 *, 0x54);
            if (temp_f1_1030 > 1.0f) {
                M2C_FIELD(temp_r30_605, f32 *, 0x54) = (f32) (temp_f1_1030 - 1.0f);
            }
            if (M2C_FIELD(temp_r30_605, f32 *, 0x64) <= 0.0f) {
                M2C_FIELD(temp_r30_605, s32 *, 0x60) = 3;
                temp_r27_1044 = M2C_FIELD(temp_r30_605, s32 *, 0x60);
                M2C_FIELD(temp_r30_605, void **, 0x50) = (void *) *(checked_cast<GrubbleCritterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + ((temp_r27_1044 * 4) + 0x70));
                M2C_FIELD(temp_r30_605, f32 *, 0x58) = (f32) (30.0f / (30.0f * ((f32) M2C_FIELD(M2C_FIELD(temp_r30_605, void **, 0x50), s16 *, 4) / 30.0f)));
                M2C_FIELD(temp_r30_605, f32 *, 0x54) = 0.0f;
            }
            break;
        case 3:                                     /* switch 1 */
            if (M2C_FIELD(temp_r30_605, f32 *, 0x54) > 1.0f) {
                M2C_FIELD(temp_r30_605, s32 *, 0x60) = 4;
                FindNewWalkParameters((Grubble *) temp_r30_605);
            }
            break;
        }
        if ((s32) M2C_FIELD(temp_r30_605, s32 *, 0x60) == 4) {
            temp_r3_1090 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
            temp_f1_1091 = M2C_FIELD(temp_r3_1090, f64 *, 0x30);
            sp100 = temp_f1_1091;
            sp108 = M2C_FIELD(temp_r3_1090, f64 *, 0x38);
            sp20 = temp_f1_1091 - (f64) M2C_FIELD(temp_r30_605, f32 *, 0x30);
            sp110 = sp20;
            sp28 = (f32) sp108 - temp_r30_605->unk38;
            sp118 = (f64) sp28;
            if ((((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (*(f32 *) ((u8 *) &sp110 + 0x4))))) <= 250000.0f) {
                SetHideState((Grubble *) temp_r30_605);
            }
        }
        var_r31_599 += 1;
        var_r28_600 += 0x70;
        goto loop_50;
    }
}
#endif

#if 0 // DRAFT: illegal type
void GrubbleCritter::Resolve() {
    s32 temp_r0_1151;
    s32 var_r3_1145;
    s32 var_r6_1146;

    MKProp::Resolve();
    var_r3_1145 = 0;
    var_r6_1146 = 0;
loop_2:
    if (var_r6_1146 < (s32) this->unk90) {
        temp_r0_1151 = var_r3_1145 + 0x60;
        var_r6_1146 += 1;
        var_r3_1145 += 0x70;
        *(this->unk170 + temp_r0_1151) = 0;
        goto loop_2;
    }
}
#endif

void GrubbleCritter::LoadDone() {
    MKHeap *temp_r3_1177;
    s32 temp_r31_1176;
    void *var_r3_1184;

    Critters::LoadDone();
    temp_r31_1176 = this->unk90 * 0x70;
    temp_r3_1177 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1177 != NULL) {
        var_r3_1184 = ((MKHeap *) (temp_r3_1177->Current()))->Alloc(temp_r31_1176, NULL, 0);
    } else {
        var_r3_1184 = malloc(temp_r31_1176);
    }
    this->unk170 = var_r3_1184;
}

void GrubbleCritter::Init() {
    Critters::Init();
}

void GrubbleCritterDescriptor::Deinit() {
    KDPropDescriptor::Deinit();
}

void GrubbleCritterDescriptor::LoadDone() {
    s8 *temp_r30_1233;
    s8 *temp_r30_1251;
    s8 *temp_r30_1269;
    s8 *temp_r30_1287;
    void *var_r3_1243;
    void *var_r3_1261;
    void *var_r3_1279;
    void *var_r3_1297;

    KDPropDescriptor::LoadDone();
    temp_r30_1233 = this->unk34;
    if (((MKAnimScript *) temp_r30_1233)->Exists("Burrow_Enter") != 0) {
        var_r3_1243 = ((MKAnimScript *) temp_r30_1233)->GetAnim("Burrow_Enter");
    } else {
        var_r3_1243 = NULL;
    }
    this->unk74 = (s32) var_r3_1243;
    temp_r30_1251 = this->unk34;
    if (((MKAnimScript *) temp_r30_1251)->Exists("Burrow_Idle") != 0) {
        var_r3_1261 = ((MKAnimScript *) temp_r30_1251)->GetAnim("Burrow_Idle");
    } else {
        var_r3_1261 = NULL;
    }
    this->unk78 = (s32) var_r3_1261;
    temp_r30_1269 = this->unk34;
    if (((MKAnimScript *) temp_r30_1269)->Exists("Burrow_Exit") != 0) {
        var_r3_1279 = ((MKAnimScript *) temp_r30_1269)->GetAnim("Burrow_Exit");
    } else {
        var_r3_1279 = NULL;
    }
    this->unk7C = (s32) var_r3_1279;
    temp_r30_1287 = this->unk34;
    if (((MKAnimScript *) temp_r30_1287)->Exists("Walk") != 0) {
        var_r3_1297 = ((MKAnimScript *) temp_r30_1287)->GetAnim("Walk");
    } else {
        var_r3_1297 = NULL;
    }
    this->unk80 = (s32) var_r3_1297;
}

void GrubbleCritterDescriptor::Init() {
    KDPropDescriptor::Init();
}

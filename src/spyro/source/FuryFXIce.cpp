#include "spyro/source/FuryFXIce.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/IceBreathSnowFlakes.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(M2C_UNK);                           /* extern */
extern s32 GS_SpyroFuryIce1;
extern s32 GS_SpyroFuryIce2;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_744 = 0;
static u8 lit_745 = 1;

#if 0 // DRAFT: undefined identifier 'unk110'
void FuryFXIce::ResetFury() {
    s32 spC;
    s32 sp8;
    M2C_UNK *temp_r3_65;
    M2C_UNK *temp_r3_76;
    M2C_UNK *temp_r5_68;
    M2C_UNK *var_r6_60;
    ManagedLight *temp_r4_80;

    SetDefaults();
    this->unkB0 &= ~0x80;
    var_r6_60 = this->unk110;
loop_2:
    if (var_r6_60 != NULL) {
        temp_r3_76 = *var_r6_60;
        if (temp_r3_76 != NULL) {
            M2C_FIELD(temp_r3_76, s32 *, 0x50) = 0;
            M2C_FIELD(temp_r3_76, f32 *, 0x48) = 0.0f;
            temp_r3_65 = this->unk110;
            this->unk110 = temp_r3_65 + 4;
            temp_r5_68 = *temp_r3_65;
            *temp_r3_65 = *var_r6_60;
            *var_r6_60 = temp_r5_68;
            var_r6_60 += 4;
            goto loop_2;
        }
    }
    temp_r4_80 = this->unk98;
    if (temp_r4_80 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_80, 0U);
    }
    gb.unk2CC.Disable((s32) this->unk190);
    this->unk190 = (MKModel *)-1;
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void FuryFXIce::DrawIcePatches() {
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    Matrix sp250;
    Matrix sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
    MKVector3 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp5C;
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
    f32 sp14;
    f32 sp10;
    M2C_UNK *temp_r28_375;
    M2C_UNK *var_r27_307;
    f32 temp_f1_311;

    spA0 = 1.0f;
    spA4 = 0.0f;
    spA8 = 0.0f;
    sp1E0 = (f64) spA0;
    sp1E8 = (f64) spA8;
    spB8 = 1.0f;
    spC0 = 1.0f;
    spC4 = 1.0f;
    sp48 = -(f32) sp1E8;
    spC8 = 1.0f;
    spCC = 1.0f;
    spB0 = 0.0f;
    spB4 = 0.0f;
    sp40 = -(f32) sp1E0;
    sp44 = -(*(f32 *) ((u8 *) &sp1E0 + 0x4));
    sp200 = (f64) spC0;
    sp208 = (f64) spC8;
    sp1F0 = (f64) spB0;
    sp1F8 = (f64) spB8;
    sp1A0 = (f64) sp40;
    sp1A8 = (f64) sp48;
    sp1B0.operator*(50.0f);
    sp1C0.operator*(50.0f);
    sp90 = sp1C0 + M2C_BITWISE(f64, sp1B0);
    sp1D0 = sp90;
    sp98 = sp1C0.unk8 + sp1B0.unk8;
    sp290 = sp90;
    sp1D8 = (f64) sp98;
    sp298 = (f64) sp98;
    sp170.operator*(50.0f);
    sp180.operator*(50.0f);
    sp80 = sp180 + M2C_BITWISE(f64, sp170);
    sp38 = -(f32) sp1E8;
    sp88 = sp180.unk8 + sp170.unk8;
    sp30 = -(f32) sp1E0;
    sp34 = -(*(f32 *) ((u8 *) &sp1E0 + 0x4));
    sp190 = sp80;
    sp198 = (f64) sp88;
    sp2A0 = sp80;
    sp2A8 = (f64) sp88;
    sp120 = (f64) sp30;
    sp128 = (f64) sp38;
    sp130.operator*(50.0f);
    sp20 = -(f32) sp1F0;
    sp24 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    sp28 = -(f32) sp1F8;
    sp140 = (f64) sp20;
    sp148 = (f64) sp28;
    sp150.operator*(50.0f);
    sp70 = sp150 + M2C_BITWISE(f64, sp130);
    sp160 = sp70;
    sp78 = sp150.unk8 + sp130.unk8;
    sp2B0 = sp70;
    sp168 = (f64) sp78;
    sp2B8 = (f64) sp78;
    spE0.operator*(50.0f);
    sp10 = -(f32) sp1F0;
    sp14 = -(*(f32 *) ((u8 *) &sp1F0 + 0x4));
    sp18 = -(f32) sp1F8;
    spF0 = (f64) sp10;
    spF8 = (f64) sp18;
    sp100.operator*(50.0f);
    sp60 = sp100 + M2C_BITWISE(f64, spE0);
    sp2C0 = sp60;
    sp68 = sp100.unk8 + spE0.unk8;
    sp110 = sp60;
    sp2C8 = (f64) sp68;
    sp118 = (f64) sp68;
    MKMaterial_SetMaterial(this->unk114);
    MKPrimitive(0xC, 0x10);
    var_r27_307 = this->unk110;
loop_2:
    if (var_r27_307 != NULL) {
        temp_r28_375 = *var_r27_307;
        if (temp_r28_375 != NULL) {
            temp_f1_311 = M2C_FIELD(temp_r28_375, f32 *, 0x4C);
            sp5C = 1.0f;
            sp58 = temp_f1_311;
            sp50 = temp_f1_311;
            sp54 = temp_f1_311;
            spD8 = (f64) sp58;
            spD0 = (f64) sp50;
            sp200 = (f64) sp50;
            sp208 = (f64) sp58;
            MKSetMatrix(sp250);
            M2C_STRUCT_COPY((s32) &unksp20C + 4, (s32) (temp_r28_375 - 4) + 4, 0x40);
            sp210.Scale3x3(&sp210, M2C_FIELD(temp_r28_375, f32 *, 0x44));
            MKSetMatrix(sp210);
            MKBegin(4);
            MKSetColorV(*((MKVector4 *) &sp200));
            MKSetTexCoord1F(0.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp290));
            MKSetColorV(*((MKVector4 *) &sp200));
            MKSetTexCoord1F(1.0f, 0.0f);
            MKSetPositionV(*((MKVector3 *) &sp2A0));
            MKSetColorV(*((MKVector4 *) &sp200));
            MKSetTexCoord1F(0.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp2B0));
            MKSetColorV(*((MKVector4 *) &sp200));
            MKSetTexCoord1F(1.0f, 1.0f);
            MKSetPositionV(*((MKVector3 *) &sp2C0));
            MKEnd();
            var_r27_307 += 4;
            goto loop_2;
        }
    }
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk110'
void FuryFXIce::UpdateIcePatches() {
    M2C_UNK *temp_r4_502;
    M2C_UNK *temp_r5_505;
    M2C_UNK *temp_r5_514;
    M2C_UNK *var_r6_397;
    f32 temp_f3_486;
    f32 temp_f4_487;
    f32 var_f0_420;
    f32 var_f0_468;
    s32 temp_r0_408;

    this->unkB0 &= ~0x80;
    var_r6_397 = this->unk110;
loop_26:
    if (var_r6_397 != NULL) {
        temp_r5_514 = *var_r6_397;
        if (temp_r5_514 == NULL) {
            return;
        }
        M2C_FIELD(temp_r5_514, f32 *, 0x48) = (f32) (M2C_FIELD(temp_r5_514, f32 *, 0x48) - gUpdateTimeDelta);
        this->unkB0 |= 0x80;
        temp_r0_408 = M2C_FIELD(temp_r5_514, s32 *, 0x50);
        switch (temp_r0_408) {                      /* irregular */
        case 1:
            var_f0_420 = M2C_FIELD(temp_r5_514, f32 *, 0x48);
            if (var_f0_420 < 0.5f) {

            } else {
                var_f0_420 = 0.5f;
            }
            if (var_f0_420 > 0.0f) {

            } else {
                var_f0_420 = 0.0f;
            }
            M2C_FIELD(temp_r5_514, f32 *, 0x48) = var_f0_420;
            M2C_FIELD(temp_r5_514, f32 *, 0x44) = (f32) (M2C_FIELD(temp_r5_514, f32 *, 0x40) * (1.0f - (M2C_FIELD(temp_r5_514, f32 *, 0x48) / 0.5f)));
            if (M2C_FIELD(temp_r5_514, f32 *, 0x48) <= 0.0f) {
                M2C_FIELD(temp_r5_514, s32 *, 0x50) = 2;
                M2C_FIELD(temp_r5_514, f32 *, 0x48) = 1.5f;
                M2C_FIELD(temp_r5_514, f32 *, 0x44) = (f32) M2C_FIELD(temp_r5_514, f32 *, 0x40);
            }
            break;
        case 2:
            if (M2C_FIELD(temp_r5_514, f32 *, 0x48) <= 0.0f) {
                M2C_FIELD(temp_r5_514, s32 *, 0x50) = 3;
                M2C_FIELD(temp_r5_514, f32 *, 0x48) = 0.25f;
            }
            break;
        case 3:
            var_f0_468 = M2C_FIELD(temp_r5_514, f32 *, 0x48);
            if (var_f0_468 < 0.25f) {

            } else {
                var_f0_468 = 0.25f;
            }
            if (var_f0_468 > 0.0f) {

            } else {
                var_f0_468 = 0.0f;
            }
            M2C_FIELD(temp_r5_514, f32 *, 0x48) = var_f0_468;
            temp_f3_486 = M2C_FIELD(temp_r5_514, f32 *, 0x40);
            temp_f4_487 = M2C_FIELD(temp_r5_514, f32 *, 0x48) / 0.25f;
            M2C_FIELD(temp_r5_514, f32 *, 0x44) = (f32) ((0.25f * temp_f3_486 * (1.0f - temp_f4_487)) + temp_f3_486);
            M2C_FIELD(temp_r5_514, f32 *, 0x4C) = temp_f4_487;
            if (M2C_FIELD(temp_r5_514, f32 *, 0x48) <= 0.0f) {
                M2C_FIELD(temp_r5_514, s32 *, 0x50) = 0;
                M2C_FIELD(temp_r5_514, f32 *, 0x48) = 0.0f;
                temp_r4_502 = this->unk110;
                this->unk110 = temp_r4_502 + 4;
                temp_r5_505 = *temp_r4_502;
                *temp_r4_502 = *var_r6_397;
                *var_r6_397 = temp_r5_505;
            }
            break;
        }
        var_r6_397 += 4;
        goto loop_26;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk110'
void FuryFXIce::SpawnIcePatch(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    MKVector3 sp48;
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
    M2C_UNK *temp_r6_529;
    Matrix *temp_r31_535;

    temp_r6_529 = this->unk110;
    if ((Matrix *) M2C_FIELD(temp_r6_529, Matrix **, -4) != NULL) {
        this->unk110 = temp_r6_529 - 4;
        temp_r31_535 = M2C_FIELD(temp_r6_529, Matrix **, -4);
        if (temp_r31_535 != NULL) {
            M2C_FIELD(temp_r31_535, f32 *, 0x40) = arg2;
            M2C_FIELD(temp_r31_535, f32 *, 0x44) = 0.0f;
            M2C_FIELD(temp_r31_535, s32 *, 0x50) = 1;
            M2C_FIELD(temp_r31_535, f32 *, 0x48) = 0.5f;
            M2C_FIELD(temp_r31_535, f32 *, 0x4C) = 1.0f;
            M2C_STRUCT_COPY(temp_r31_535, &Matrix::identity, 0x40);
            sp10 = 1.0f;
            sp20 = -1.0f;
            sp8 = 1.0f;
            spC = 0.0f;
            sp18 = -1.0f;
            sp1C = 0.0f;
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            sp38 = (f64) sp18;
            sp40 = (f64) sp20;
            KDRand_Vector(sp48, *((MKVector3 *) &sp38));
            KDMath_BuildMatrixFromUp(temp_r31_535, arg1, sp48);
            temp_r31_535->unk30 = arg0.unk0;
            temp_r31_535->unk34 = arg0.unk4;
            temp_r31_535->unk38 = arg0.unk8;
            temp_r31_535->unk3C = 1.0f;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
s32 FuryFXIce::Trigger(const MKVector3 &arg0, bool arg1) {
    f64 sp38;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    MKProp *temp_r4_661;
    ManagedLight *temp_r3_692;
    ManagedLight *temp_r3_722;
    ManagedLight *temp_r4_684;
    f64 *temp_r3_747;
    s32 temp_r27_653;
    s32 temp_r29_630;
    s32 temp_r3_628;
    s32 var_r28_646;
    u8 var_r3_636;
    void *temp_r3_695;
    void *temp_r3_728;
    void *temp_r5_632;

    if (((u8) this->unkB0 >> 7U) & 1) {
        return 0;
    }
    this->unk90 = 1;
    this->unk94 = 0.75f;
    this->unkA0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unkA8 = M2C_FIELD(&arg0, f64 *, 8);
    this->unkB1 = (s8) arg1;
    temp_r3_628 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r29_630 = *(&GameData::gameData[0x70] + (temp_r3_628 + 0x7C));
    temp_r5_632 = &GameData::gameData[0x70] + (temp_r3_628 + 0x64);
    if (temp_r29_630 == 3) {
        var_r3_636 = 0;
        if (((s32) M2C_FIELD(temp_r5_632, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_632, s32 *, 4) == 3)) {
            var_r3_636 = 1;
        }
        var_r28_646 = var_r3_636 != 0;
    } else {
        var_r28_646 = *(temp_r5_632 + (temp_r29_630 * 4));
    }
    temp_r27_653 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    temp_r4_661 = gb.unk0->GetProp();
    sp8 = -1;
    this->unkB8.Init(temp_r4_661, 0, temp_r29_630, var_r28_646, temp_r27_653, temp_r27_653, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk190 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
    M2C_FIELD(this, f64 *, 0x140) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    this->unk120.unk20 = M2C_FIELD(&arg0, f64 *, 8);
    temp_r4_684 = this->unk98;
    if (temp_r4_684 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_684, 1U);
        temp_r3_692 = this->unk98;
        temp_r3_692->unk38 = 0.1f;
        temp_r3_695 = temp_r3_692->unk3C;
        if (temp_r3_695 != NULL) {
            M2C_FIELD(temp_r3_695, f32 *, 0x20) = 0.1f;
            M2C_FIELD(temp_r3_695, f32 *, 0x24) = 0.010000001f;
            M2C_FIELD(temp_r3_695, f32 *, 0x28) = 10.0f;
            M2C_FIELD(temp_r3_695, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_695, f32 *, 0x24));
        }
        MKVector(0.0f, 1000.0f, 0.0f);
        sp10 = this->unkA0 + sp20;
        temp_r3_722 = this->unk98;
        sp30 = sp10;
        sp18 = (f32) M2C_FIELD(this, f64 *, 0xA8) + sp28;
        temp_r3_722->unk10 = sp10;
        temp_r3_722->unk18 = (f64) sp18;
        temp_r3_728 = temp_r3_722->unk3C;
        sp38 = (f64) sp18;
        if (temp_r3_728 != NULL) {
            M2C_FIELD(temp_r3_728, f64 *, 0x10) = sp10;
            M2C_FIELD(temp_r3_728, f64 *, 0x18) = (f64) sp18;
        }
    }
    M2C_STRUCT_COPY((s32) (this + 0x14C) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_747 = &this->unk120.unk28;
    ((Matrix *) temp_r3_747)->RotateYaw((Matrix *) temp_r3_747, 0.3926991f);
    gb.unk381 = 1;
    return 1;
}
#endif

void FuryFXIce::SetDefaults() {
    SetDefaults();
    this->unk90 = 0;
}

#if 0 // DRAFT: undefined identifier 'unk110'
void FuryFXIce::Deinit() {
    M2C_UNK *temp_r0_795;
    M2C_UNK *temp_r0_814;
    M2C_UNK *var_r31_791;
    M2C_UNK *var_r3_792;
    M2C_UNK *var_r4_790;
    MKHeap *temp_r3_817;
    u32 temp_r0_800;

    var_r4_790 = this->unk110;
    var_r31_791 = var_r4_790;
    var_r3_792 = var_r4_790;
loop_3:
    temp_r0_800 = M2C_FIELD(var_r3_792, u32 *, -4);
    var_r3_792 -= 4;
    if (temp_r0_800 != 0U) {
        temp_r0_795 = *var_r3_792;
        if (temp_r0_795 < var_r31_791) {
            var_r31_791 = temp_r0_795;
        }
        goto loop_3;
    }
    if (var_r3_792 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_814 = *var_r4_790;
        if (temp_r0_814 != NULL) {
            if (temp_r0_814 < var_r31_791) {
                var_r31_791 = temp_r0_814;
            }
            var_r4_790 += 4;
            goto loop_9;
        }
        temp_r3_817 = ((MKHeap *) var_r3_792)->Current();
        if (temp_r3_817 != NULL) {
            ((MKHeap *) (temp_r3_817->Current()))->Free(var_r31_791, NULL, 0);
        } else {
            free(var_r31_791);
        }
    }
    this->unk110 = NULL;
    MKMaterial_Destroy(this->unk114);
    MKMaterial_Destroy(M2C_BITWISE(MKMaterial *, this->unk150.unk3C));
    MKModel_Destroy(M2C_BITWISE(MKModel *, this->unk150.unk38));
    gb.unk2CC.Disable((s32) this->unk190);
    this->unk190 = (MKModel *)-1;
    FuryFX::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void FuryFXIce::Draw() {
    s32 temp_r0_863;

    DrawIcePatches();
    temp_r0_863 = this->unk90;
    if ((temp_r0_863 == 4) || (temp_r0_863 == 2)) {
        gRenderState = this->unk150.unk3C;
        MKModel_Draw(M2C_BITWISE(MKModel *, this->unk150.unk38), NULL);
        gRenderState = 0.0f;
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'HeroInterface'
void FuryFXIce::Update() {
    s8 sp540;
    s32 sp53C;
    s32 sp538;
    s32 sp534;
    f32 sp530;
    s32 sp52C;
    s8 sp52B;
    s8 sp52A;
    s16 sp528;
    f32 sp524;
    f32 sp520;
    f32 sp51C;
    f32 sp518;
    f32 sp514;
    f32 sp510;
    f32 sp508;
    f32 sp504;
    f32 sp500;
    f32 sp4F8;
    f32 sp4F4;
    f32 sp4F0;
    Matrix sp4B0;
    Matrix sp470;
    Matrix sp430;
    Matrix sp3F0;
    M2C_UNK sp3EC;
    s8 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    s32 sp3CC;
    s32 sp3C8;
    s8 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    s32 sp3AC;
    s32 sp3A8;
    s8 sp3A0;
    f64 sp398;
    f64 sp390;
    s32 sp38C;
    s32 sp388;
    f32 sp380;
    s32 sp37C;
    s32 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f32 sp350;
    s32 sp34C;
    s32 sp348;
    f64 sp340;                                      /* compiler-managed */
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
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
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
    MKVector3 sp228;
    MKVector3 sp218;
    M2C_UNK sp208;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    M2C_UNK sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f64 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
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
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    s32 sp8;
    MKProp *temp_r4_1416;
    ManagedLight *temp_r3_1864;
    ManagedLight *temp_r3_971;
    ManagedLight *temp_r4_1891;
    f32 temp_f0_1868;
    f32 temp_f16_1152;
    f32 temp_f16_975;
    f32 temp_f17_1155;
    f32 temp_f17_1341;
    f32 temp_f17_1822;
    f32 temp_f17_1933;
    f32 temp_f18_1136;
    f32 temp_f18_1346;
    f32 temp_f18_1548;
    f32 temp_f18_1743;
    f32 temp_f19_1553;
    f32 temp_f19_1827;
    f32 temp_f1_1002;
    f32 temp_f1_1761;
    f32 temp_f1_1795;
    f32 temp_f1_1972;
    f32 temp_f1_978;
    f32 temp_f20_1123;
    f32 temp_f21_1132;
    f32 temp_f22_1131;
    f32 temp_f2_1308;
    f32 temp_f31_1926;
    f32 temp_f3_938;
    f32 temp_f4_1129;
    f32 var_f0_1091;
    f32 var_f1_1724;
    f32 var_f1_955;
    f64 *temp_r3_1599;
    f64 temp_f0_1166;
    f64 temp_f0_1176;
    f64 temp_f0_1255;
    f64 temp_f0_1668;
    f64 temp_f0_1947;
    f64 temp_f0_1959;
    f64 temp_f2_1426;
    f64 temp_f2_1501;
    s32 temp_r0_942;
    s32 temp_r28_1138;
    s32 var_r27_1107;
    s32 var_r27_1919;
    s32 var_r28_1609;
    u8 var_r4_1391;
    u8 var_r4_1463;
    void *temp_r3_1396;
    void *temp_r3_1468;
    void *temp_r3_1614;
    void *temp_r3_1870;
    void *temp_r3_980;

    FuryFX::Update();
    UpdateIcePatches();
    ((IceBreathSnowFlakes *) this->unk114)->ApplyWind((WindFX *) &this->unk120);
    if ((s32) this->unk90 != 0) {
        temp_f3_938 = this->unk94;
        this->unk94 = temp_f3_938 - gUpdateTimeDelta;
        temp_r0_942 = this->unk90;
        switch (temp_r0_942) {                      /* irregular */
        case 1:
            var_f1_955 = this->unk94;
            if (var_f1_955 < 0.75f) {

            } else {
                var_f1_955 = 0.75f;
            }
            if (var_f1_955 > 0.0f) {

            } else {
                var_f1_955 = 0.0f;
            }
            temp_r3_971 = this->unk98;
            temp_f16_975 = 1.0f - (var_f1_955 / 0.75f);
            if (temp_r3_971 != NULL) {
                temp_f1_978 = 10000.0f * temp_f16_975;
                temp_r3_971->unk38 = temp_f1_978;
                temp_r3_980 = temp_r3_971->unk3C;
                if (temp_r3_980 != NULL) {
                    M2C_FIELD(temp_r3_980, f32 *, 0x20) = temp_f1_978;
                    M2C_FIELD(temp_r3_980, f32 *, 0x24) = (f32) (temp_f1_978 * temp_f1_978);
                    M2C_FIELD(temp_r3_980, f32 *, 0x28) = (f32) (1.0f / temp_f1_978);
                    M2C_FIELD(temp_r3_980, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_980, f32 *, 0x24));
                }
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp37C = 0;
                temp_f1_1002 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                sp378 = 0x458;
                sp380 = temp_f1_1002 + (0.017453292f * (30.0f * temp_f16_975));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp378, 0.017453292f);
            }
            if (this->unk94 <= 0.0f) {
                this->unk94 = 0.5f;
                this->unk90 = 2;
                KDSound_Play3d(GS_SpyroFuryIce1, (MKVector3 *) &this->unkA0, 0U, -1, 0.0f, 0U);
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.1f, 0.3f, 2.0f, 0, 4.0f, 0U);
                M2C_STRUCT_COPY((s32) &sp470.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                spA0 = 0.0f;
                sp98 = 0.0f;
                sp9C = 0.0f;
                sp330 = (f64) spA0;
                sp328 = (f64) sp98;
                sp4B0.Scale3x3(&sp4B0, *((MKVector3 *) &sp328));
                sp4B0.unk30 = (f32) M2C_FIELD(this, f64 *, 0xA0);
                sp4B0.unk34 = M2C_FIELD(this, f32 *, 0xA4);
                sp4B0.unk38 = M2C_FIELD(this, f32 *, 0xA8);
                sp4B0.unk3C = 1.0f;
                MKModel_SetWorldMatrix(M2C_BITWISE(MKModel *, this->unk150.unk38), sp4B0);
                gb.unk2CC.Disable((s32) this->unk190);
                this->unk190 = (MKModel *)-1;
            }
            break;
        case 2:
            var_f0_1091 = this->unk94;
            if (var_f0_1091 < 0.5f) {

            } else {
                var_f0_1091 = 0.5f;
            }
            if (var_f0_1091 > 0.0f) {

            } else {
                var_f0_1091 = 0.0f;
            }
            this->unk94 = var_f0_1091;
            var_r27_1107 = 0;
            temp_f20_1123 = 1.0f - (this->unk94 / 0.5f);
            temp_f4_1129 = temp_f20_1123 - (1.0f - (temp_f3_938 / 0.5f));
            temp_f22_1131 = 15.707964f * temp_f20_1123;
            temp_f21_1132 = 15.0f * (0.25f + temp_f20_1123);
            temp_f18_1136 = 10.0f * (3.1415927f * temp_f4_1129);
            temp_r28_1138 = (s32) (75.0f * temp_f4_1129);
loop_31:
            if (var_r27_1107 < temp_r28_1138) {
                temp_f16_1152 = (((f32) var_r27_1107 / (f32) temp_r28_1138) * temp_f18_1136) + temp_f22_1131;
                temp_f17_1155 = -_table_sinf(1.5707964f + temp_f16_1152);
                sp168 = _table_sinf(temp_f16_1152);
                sp16C = 0.0f;
                sp170 = temp_f17_1155;
                sp2F8 = (f64) sp168;
                sp300 = (f64) sp170;
                temp_f0_1166 = sp2F8 * 5.717499035e-315;
                sp158 = temp_f0_1166;
                sp308 = temp_f0_1166;
                sp160 = (f32) sp300 * 2000.0f;
                sp310 = (f64) sp160;
                temp_f0_1176 = temp_f0_1166 * (f64) temp_f20_1123;
                sp148 = temp_f0_1176;
                sp318 = temp_f0_1176;
                sp150 = (f32) sp310 * temp_f20_1123;
                sp320 = (f64) sp150;
                sp138 = sp318 + this->unkA0;
                sp130 = 0.0f;
                sp128 = 0.0f;
                sp140 = (f32) sp320 + M2C_FIELD(this, f32 *, 0xA8);
                sp12C = 1.0f;
                sp368 = sp138;
                sp370 = (f64) sp140;
                sp4F0 = 0.0f;
                sp4F4 = 0.0f;
                sp4F8 = 0.0f;
                sp500 = 0.0f;
                sp504 = 0.0f;
                sp508 = 0.0f;
                sp510 = 0.0f;
                sp514 = 0.0f;
                sp518 = 0.0f;
                sp51C = 1.0f;
                sp520 = 0.0f;
                sp524 = 0.0f;
                sp528 = 0;
                sp52A = 0;
                sp52B = 0;
                sp52C = 0;
                sp530 = 3.4028235e38f;
                sp534 = 0;
                sp538 = 0;
                sp53C = -1;
                sp540 = 0;
                sp358 = (f64) sp128;
                sp360 = (f64) sp130;
                spF8 = 0.0f;
                spFC = -1000.0f;
                sp100 = 0.0f;
                sp2B8 = (f64) spF8;
                sp2C0 = (f64) sp100;
                spE8 = sp368 + sp2B8;
                sp120 = 0.0f;
                sp118 = 0.0f;
                sp11C = 300.0f;
                spF0 = (f32) sp370 + (f32) sp2C0;
                sp2D8 = (f64) sp118;
                sp2C8 = spE8;
                sp2D0 = (f64) spF0;
                sp2E0 = (f64) sp120;
                temp_f0_1255 = sp368 + sp2D8;
                sp108 = temp_f0_1255;
                sp2E8 = temp_f0_1255;
                sp110 = (f32) sp370 + (f32) sp2E0;
                sp2F0 = (f64) sp110;
                if (MKCollision_RayCollide(*((MKVector3 *) &sp2E8), *((MKVector3 *) &sp2C8), (MKCollisionResult *) &sp4F0, (MKCollisionMode) 4, 0x0C000000) != 0) {
                    sp358 = (f64) sp500;
                    (*(f32 *) ((u8 *) &sp368 + 0x4)) = 10.0f + sp4F4;
                    sp360 = (f64) sp508;
                }
                SpawnIcePatch(*((MKVector3 *) &sp368), *((MKVector3 *) &sp358), temp_f21_1132);
                var_r27_1107 += 1;
                goto loop_31;
            }
            M2C_STRUCT_COPY((s32) &sp430.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f2_1308 = 75.0f * temp_f20_1123;
            sp90 = temp_f2_1308;
            sp88 = temp_f2_1308;
            sp8C = 50.0f * (1.0f - temp_f20_1123);
            sp2B0 = (f64) sp90;
            sp2A8 = (f64) sp88;
            sp470.Scale3x3(&sp470, *((MKVector3 *) &sp2A8));
            sp470.unk30 = (f32) M2C_FIELD(this, f64 *, 0xA0);
            sp470.unk34 = M2C_FIELD(this, f32 *, 0xA4);
            sp470.unk38 = M2C_FIELD(this, f32 *, 0xA8);
            sp470.unk3C = 1.0f;
            MKModel_SetWorldMatrix(M2C_BITWISE(MKModel *, this->unk150.unk38), sp470);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp3CC = 0;
                temp_f17_1341 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f18_1346 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f18_1346, temp_f17_1341);
                sp78 = sp288 * 5.398241246e-315;
                sp3C8 = 0x417;
                sp3D0 = sp78;
                sp80 = sp290 * 10.0f;
                sp3E0 = 1;
                sp3D8 = (f64) sp80;
                sp298 = sp78;
                sp2A0 = (f64) sp80;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp3C8, sp78);
            }
            if (this->unk94 <= 0.0f) {
                this->unk94 = 1.5f;
                var_r4_1391 = 0;
                this->unk90 = 3;
                temp_r3_1396 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
                if (((s32) M2C_FIELD(temp_r3_1396, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r3_1396, s32 *, 4) == 3)) {
                    var_r4_1391 = 1;
                }
                temp_r4_1416 = gb.unk0->GetProp(var_r4_1391);
                sp8 = -1;
                this->unkB8.Init(temp_r4_1416, 0, 3, var_r4_1391 != 0, 2, 2, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                temp_f2_1426 = this->unkA0;
                M2C_FIELD(this, f64 *, 0xC8) = temp_f2_1426;
                M2C_FIELD(this, f64 *, 0xD0) = (f64) this->unkA8;
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unkB8, 0, 0, &this->unkA0, 1, 3000.0f, temp_f2_1426);
                this->unk190 = gb.unk2CC.Enable(0.25f, 0.0f, 1.0f, -1.0f);
            }
            break;
        case 3:
            if (this->unk94 <= 0.0f) {
                this->unk94 = 1.5f;
                var_r4_1463 = 0;
                this->unk90 = 4;
                temp_r3_1468 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
                if (((s32) M2C_FIELD(temp_r3_1468, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r3_1468, s32 *, 4) == 3)) {
                    var_r4_1463 = 1;
                }
                this->unkB8.Init(gb.unk0->GetProp(var_r4_1463), 15.0f * gb.unk37C, 3, var_r4_1463 != 0, 2, 2, 0, -1);
                temp_f2_1501 = this->unkA0;
                M2C_FIELD(this, f64 *, 0xC8) = temp_f2_1501;
                M2C_FIELD(this, f64 *, 0xD0) = (f64) this->unkA8;
                M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unkB8, 0, 0, &this->unkA0, 1, 3000.0f, temp_f2_1501);
                KDSound_Play3d(GS_SpyroFuryIce2, (MKVector3 *) &this->unkA0, 0U, -1, 0.0f, 0U);
                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.99f, 0.99f, 1.0f, 0, 4.0f, 0U);
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp3AC = 0;
                    temp_f18_1548 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    temp_f19_1553 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                    MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f19_1553, temp_f18_1548);
                    sp68 = sp268 * 5.61841903e-315;
                    sp3A8 = 0x417;
                    sp3B0 = sp68;
                    sp70 = sp270 * 400.0f;
                    sp3C0 = 1;
                    sp3B8 = (f64) sp70;
                    sp278 = sp68;
                    sp280 = (f64) sp70;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp3A8, sp68);
                }
                M2C_STRUCT_COPY((s32) (this + 0x14C) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_r3_1599 = &this->unk120.unk28;
                ((Matrix *) temp_r3_1599)->RotateYaw((Matrix *) temp_r3_1599, -0.3926991f);
                gb.unk2CC.Disable((s32) this->unk190);
                var_r28_1609 = 0;
                this->unk190 = (MKModel *)-1;
                do {
                    temp_r3_1614 = checked_cast<PooledShatterProp *, MKProp>(((MKPropDescriptor *) this->unk194)->CreateInstance());
                    if (temp_r3_1614 != NULL) {
                        M2C_FIELD(M2C_FIELD(temp_r3_1614, void **, 0x44), M2C_UNK (**)(), 0x20)();
                        M2C_FIELD(M2C_FIELD(temp_r3_1614, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1614);
                        M2C_STRUCT_COPY((s32) &sp3F0.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                        sp430.Scale3x3(&sp430, 4.0f);
                        MKVector(0.0f, 150.0f, 0.0f);
                        MKVector(1.0f, 0.0f, 1.0f);
                        MKVector(-1.0f, 0.0f, -1.0f);
                        KDRand_Vector(sp228, sp218);
                        sp238.operator*(2000.0f);
                        temp_f0_1668 = this->unkA0 + M2C_BITWISE(f64, sp238);
                        sp18 = temp_f0_1668;
                        sp248 = temp_f0_1668;
                        sp20 = M2C_FIELD(this, f32 *, 0xA8) + sp238.unk8;
                        sp250 = (f64) sp20;
                        sp58 = sp248 + sp1F8;
                        sp258 = sp58;
                        sp60 = (f32) sp250 + sp200;
                        sp260 = (f64) sp60;
                        sp430.unk30 = (f32) sp258;
                        sp430.unk34 = (*(f32 *) ((u8 *) &sp258 + 0x4));
                        sp430.unk38 = (f32) sp260;
                        sp430.unk3C = 1.0f;
                        MKModel_SetWorldMatrix(M2C_FIELD(temp_r3_1614, MKModel **, 4), sp430);
                        M2C_FIELD(M2C_FIELD(temp_r3_1614, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_1614, 0, 0, -1, 0, 1, 0);
                    }
                    var_r28_1609 += 1;
                } while (var_r28_1609 < 0x14);
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetRage(2, 15.0f);
            }
            break;
        case 4:
            var_f1_1724 = this->unk94;
            if (var_f1_1724 < 1.5f) {

            } else {
                var_f1_1724 = 1.5f;
            }
            if (var_f1_1724 > 0.0f) {

            } else {
                var_f1_1724 = 0.0f;
            }
            temp_f18_1743 = var_f1_1724 / 1.5f;
            M2C_STRUCT_COPY((s32) &sp3EC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f1_1761 = 75.0f * (1.0f - temp_f18_1743);
            sp4C = 50.0f * temp_f18_1743;
            sp48 = temp_f1_1761;
            sp50 = temp_f1_1761;
            sp1E8 = (f64) sp48;
            sp1F0 = (f64) sp50;
            sp3F0.Scale3x3(&sp3F0, *((MKVector3 *) &sp1E8));
            sp3F0.unk30 = (f32) M2C_FIELD(this, f64 *, 0xA0);
            sp3F0.unk34 = M2C_FIELD(this, f32 *, 0xA4);
            sp3F0.unk38 = M2C_FIELD(this, f32 *, 0xA8);
            sp3F0.unk3C = 1.0f;
            MKModel_SetWorldMatrix(M2C_BITWISE(MKModel *, this->unk150.unk38), sp3F0);
            if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && (temp_f18_1743 <= 0.5f)) {
                sp34C = 0;
                temp_f1_1795 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
                sp348 = 0x458;
                sp350 = temp_f1_1795 + (0.017453292f * (30.0f * (temp_f18_1743 / 0.5f)));
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp348, 30.0f, 0.017453292f);
            }
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp38C = 0;
                temp_f17_1822 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f19_1827 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f19_1827, temp_f17_1822);
                sp1C8.operator*(100.0f);
                sp38 = sp1C8 * (f64) temp_f18_1743;
                sp388 = 0x417;
                sp390 = sp38;
                sp40 = sp1C8.unk8 * temp_f18_1743;
                sp3A0 = 1;
                sp398 = (f64) sp40;
                sp1D8 = sp38;
                sp1E0 = (f64) sp40;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp388, sp38);
            }
            temp_r3_1864 = this->unk98;
            if (temp_r3_1864 != NULL) {
                temp_f0_1868 = 10000.0f * temp_f18_1743;
                temp_r3_1864->unk38 = temp_f0_1868;
                temp_r3_1870 = temp_r3_1864->unk3C;
                if (temp_r3_1870 != NULL) {
                    M2C_FIELD(temp_r3_1870, f32 *, 0x20) = temp_f0_1868;
                    M2C_FIELD(temp_r3_1870, f32 *, 0x24) = (f32) (temp_f0_1868 * temp_f0_1868);
                    M2C_FIELD(temp_r3_1870, f32 *, 0x28) = (f32) (1.0f / temp_f0_1868);
                    M2C_FIELD(temp_r3_1870, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1870, f32 *, 0x24));
                }
            }
            if (this->unk94 <= 0.0f) {
                this->unk94 = 0.0f;
                this->unk90 = 0;
                temp_r4_1891 = this->unk98;
                if (temp_r4_1891 != NULL) {
                    ((LightManager *) gb.unk80)->EnableLight(temp_r4_1891, 0U);
                }
                if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                    sp14 = 0;
                    sp10 = 0x459;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
                }
                gb.unk381 = 0;
            }
            break;
        }
        var_r27_1919 = 0;
        do {
            temp_f31_1926 = MKRand_Float(&gViewSeed, 10.0f, 1300.0f);
            temp_f17_1933 = -_table_sinf(1.5707964f + MKRand_Float(&gViewSeed, 0.0f, 6.2831855f));
            spD8 = _table_sinf(MKRand_Float(&gViewSeed, 0.0f, 6.2831855f));
            spDC = 0.0f;
            spE0 = temp_f17_1933;
            sp198 = (f64) spD8;
            sp1A0 = (f64) spE0;
            temp_f0_1947 = sp198 * (f64) temp_f31_1926;
            spC8 = temp_f0_1947;
            sp1A8 = temp_f0_1947;
            spD0 = (f32) sp1A0 * temp_f31_1926;
            sp1B0 = (f64) spD0;
            temp_f0_1959 = sp1A8 + this->unkA0;
            spB8 = temp_f0_1959;
            sp338 = temp_f0_1959;
            spC0 = (f32) sp1B0 + M2C_FIELD(this, f32 *, 0xA8);
            sp340 = (f64) spC0;
            temp_f1_1972 = MKRand_Float(&gViewSeed, 200.0f, 300.0f);
            sp28 = 0.0f;
            sp2C = temp_f1_1972;
            sp30 = 0.0f;
            sp188 = (f64) sp28;
            sp190 = (f64) sp30;
            sp338 += sp188;
            spB0 = 0.0f;
            spA8 = 0.0f;
            spAC = 0.0f;
            sp340 = (f32) sp340 + (f32) sp190;
            sp178 = (f64) spA8;
            sp180 = (f64) spB0;
            ((IceBreathSnowFlakes *) this->unk114)->Emit(*((MKVector3 *) &sp338), *((MKVector3 *) &sp178), 1.0f);
            var_r27_1919 += 1;
        } while (var_r27_1919 < 0xA);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void FuryFXIce::Resolve() {
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
    ManagedLight *temp_r4_2089;

    FuryFX::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.5f;
    spC = 0.5f;
    sp10 = 1.0f;
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
    this->unk98 = ((LightManager *) gb.unk80)->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 10000.0f, lit_744, lit_745);
    temp_r4_2089 = this->unk98;
    if (temp_r4_2089 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_2089, 0U);
    }
    this->unk194 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, M2C_UNK *), 0x5C)(gMK, "IceCube"));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void FuryFXIce::Init() {
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
    M2C_UNK *temp_r3_2147;
    M2C_UNK *temp_r4_2153;
    M2C_UNK *var_r3_2132;
    M2C_UNK *var_r5_2141;
    MKHeap *temp_r3_2125;
    MKMaterial *temp_r3_2171;
    f64 *temp_r3_2211;
    s32 var_ctr_2145;

    FuryFX::Init();
    SetDefaults();
    this->unk98 = NULL;
    temp_r3_2125 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_2125 != NULL) {
        var_r3_2132 = ((MKHeap *) (temp_r3_2125->Current()))->Alloc(0x2718, NULL, 0);
    } else {
        var_r3_2132 = malloc(0x2718);
    }
    this->unk110 = var_r3_2132;
    var_r5_2141 = this->unk110;
    this->unk110 = var_r5_2141 + 0x2580;
    M2C_FIELD(var_r5_2141, s32 *, 0x2580) = 0;
    var_ctr_2145 = 0x64;
    do {
        temp_r3_2147 = this->unk110;
        this->unk110 = temp_r3_2147 + 4;
        M2C_FIELD(temp_r3_2147, M2C_UNK **, 4) = var_r5_2141;
        var_r5_2141 += 0x60;
        var_ctr_2145 -= 1;
    } while (var_ctr_2145 != 0);
    temp_r4_2153 = this->unk110;
    this->unk110 = temp_r4_2153 + 4;
    M2C_FIELD(temp_r4_2153, M2C_UNK **, 4) = NULL;
    this->unkB0 &= ~0x80;
    this->unk114 = MKMaterial_Create"fx_372";
    temp_r3_2171 = checked_cast<IceBreathSnowFlakes *, MKProp>(((MKSceneManager *) gMK)->CreateProp("IceBreathSnowFlakes"));
    sp10 = 0.0f;
    sp20 = 0.0f;
    this->unk114 = temp_r3_2171;
    sp8 = 0.0f;
    spC = 0.2f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    ((WindFX *) &this->unk120)->Init(1, 1.0f, *((MKVector3 *) &sp38), *((MKVector3 *) &sp28));
    this->unk120.unk10 = 2000.0f;
    this->unk120.unk14 = 1000.0f;
    M2C_STRUCT_COPY((s32) (this + 0x14C) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_2211 = &this->unk120.unk28;
    ((Matrix *) temp_r3_2211)->RotateYaw((Matrix *) temp_r3_2211, 0.3926991f);
    M2C_FIELD(this, f32 *, 0x130) = 50.0f;
    this->unk150.unk38 = M2C_BITWISE(f32, MKModel_Create("Fx0020_earthshock", NULL, 2, NULL));
    this->unk150.unk3C = M2C_BITWISE(f32, MKMaterial_Create"FX_IceFuryMat");
    this->unk190 = (MKModel *)-1;
}
#endif

void FuryFXIce_cpp::__sinit() {
    f32 temp_f0_2280;
    f64 temp_f1_2261;
    f64 temp_f1_2269;
    f64 temp_f3_2249;
    f64 temp_f4_2258;
    f64 temp_f4_2266;
    f64 temp_f8_2251;

    temp_f3_2249 = __frsqrte(2014000.0);
    temp_f8_2251 = __frsqrte(380000.0);
    temp_f4_2258 = 0.5 * temp_f3_2249 * -((2014000.0 * (temp_f3_2249 * temp_f3_2249)) - 3.0);
    temp_f1_2261 = 0.5 * temp_f8_2251 * -((380000.0 * (temp_f8_2251 * temp_f8_2251)) - 3.0);
    temp_f4_2266 = 0.5 * temp_f4_2258 * -((2014000.0 * (temp_f4_2258 * temp_f4_2258)) - 3.0);
    temp_f1_2269 = 0.5 * temp_f1_2261 * -((380000.0 * (temp_f1_2261 * temp_f1_2261)) - 3.0);
    temp_f0_2280 = (f32) (380000.0 * (0.5 * temp_f1_2269 * -((380000.0 * (temp_f1_2269 * temp_f1_2269)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2266 * -((2014000.0 * (temp_f4_2266 * temp_f4_2266)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2280;
}

#include "spyro/source/FuryFXEarth2.h"
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
#include "common/Source/MKParticleSystem.h"
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
#include "spyro/source/EarthBreathWhirlWinds.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/SB2.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_Rumble3;
extern s32 GS_SpyroFuryEarth3;
extern s32 GS_SpyroFuryEarth4;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrListDL;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_790 = 0;
static u8 lit_791 = 1;

#if 0 // DRAFT: illegal explicit conversion from 'void' to 'unsigned long'
void FuryFXEarth2::ResetFury() {
    ManagedLight *temp_r4_73;
    u32 temp_r4_61;
    void *temp_r3_58;
    void *var_r5_55;

    SetDefaults();
    var_r5_55 = this->unkC0;
loop_2:
    if ((var_r5_55 != NULL) && ((u32) *var_r5_55 != 0U)) {
        temp_r3_58 = this->unkC0;
        this->unkC0 = ((u8 *) temp_r3_58) + 4;
        temp_r4_61 = *temp_r3_58;
        *temp_r3_58 = (u32) *var_r5_55;
        *var_r5_55 = temp_r4_61;
        var_r5_55 += 4;
        goto loop_2;
    }
    temp_r4_73 = this->unkCC;
    if (temp_r4_73 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_73, 0U);
    }
    ExplodeVortex();
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp3C'
void FuryFXEarth2::CalcMatrixForVortexElement(FuryFXEarth2::VortexAttachmentPoint *arg1) {
    Matrix sp40;
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKVector3 *temp_r31_103;
    f32 temp_f1_124;
    f32 temp_f2_148;
    f32 temp_f31_120;
    f32 temp_f3_146;

    temp_r31_103 = M2C_ERROR(/* Read from unset register $r5 */);
    sp40.SetRotationPYR(*temp_r31_103);
    sp40.Scale3x3(&sp40, M2C_FIELD(temp_r31_103, f32 *, 0x38));
    temp_f31_120 = M2C_FIELD(temp_r31_103, f32 *, 0x30) * -_table_sinf(1.5707964f + M2C_FIELD(temp_r31_103, f32 *, 0x20));
    temp_f1_124 = M2C_FIELD(temp_r31_103, f32 *, 0x30) * _table_sinf(M2C_FIELD(temp_r31_103, f32 *, 0x20));
    sp18 = temp_f31_120;
    sp10 = temp_f1_124;
    sp14 = 0.0f;
    sp28 = (f64) sp18;
    sp30 = (f64) sp10;
    sp20 = (f64) sp10;
    sp38 = (f64) sp18;
    sp30 = (f64) sp10 + M2C_FIELD(arg1, f64 *, 0xA0);
    temp_f3_146 = (f32) sp38 + M2C_FIELD(arg1, f32 *, 0xA8);
    temp_f2_148 = (*(f32 *) ((u8 *) &sp30 + 0x4)) + M2C_FIELD(temp_r31_103, f32 *, 0x28);
    sp38 = temp_f3_146;
    (*(f32 *) ((u8 *) &sp30 + 0x4)) = temp_f2_148;
    sp40.unk30 = (f32) sp30;
    sp40.unk34 = temp_f2_148;
    sp40.unk38 = temp_f3_146;
    sp40.unk3C = 1.0f;
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &unksp3C + 4, 0x40);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void FuryFXEarth2::EmitTimedSparks() {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
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
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1_204;
    f32 temp_f1_295;
    f32 temp_f26_264;
    f32 temp_f27_269;
    f64 temp_f0_231;
    f64 temp_f0_243;
    f64 temp_f0_283;
    s32 var_r30_249;

    this->unkE4 -= gUpdateTimeDelta;
    if (!(this->unkE4 > 0.0f)) {
        temp_f1_204 = MKRand_Float((int *) &gViewSeed, 0.125f, 0.5f);
        sp78 = -1.0f;
        sp68 = 1.0f;
        this->unkE4 = temp_f1_204;
        sp70 = -1.0f;
        sp74 = 0.0f;
        sp60 = 1.0f;
        sp64 = 3.0f;
        spC0 = (f64) sp70;
        spC8 = (f64) sp78;
        spB0 = (f64) sp60;
        spB8 = (f64) sp68;
        spD0 = KDRand_Vector(*((MKVector3 *) &spC0), *((MKVector3 *) &spB0));
        temp_f0_231 = spD0 * 5.61841903e-315;
        sp50 = temp_f0_231;
        spE0 = temp_f0_231;
        sp58 = spD0.unk8 * 400.0f;
        spE8 = (f64) sp58;
        temp_f0_243 = this->unkA0 + temp_f0_231;
        sp40 = temp_f0_243;
        var_r30_249 = 0;
        spF0 = temp_f0_243;
        sp48 = this->unkA8 + (f32) spE8;
        spF8 = (f64) sp48;
        do {
            temp_f26_264 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f27_269 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp30 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp34 = temp_f27_269;
            sp38 = temp_f26_264;
            sp90 = (f64) sp30;
            sp98 = (f64) sp38;
            temp_f0_283 = sp90 * 5.67904887e-315;
            sp20 = temp_f0_283;
            spA0 = temp_f0_283;
            sp28 = (f32) sp98 * 1050.0f;
            spA8 = (f64) sp28;
            temp_f1_295 = MKRand_Float((int *) &gViewSeed, 6.0f, 7.0f);
            sp10 = 0.0f;
            sp14 = 1.0f;
            sp8 = temp_f1_295;
            sp18 = 0.5f;
            sp1C = 1.0f;
            sp80 = (f64) sp10;
            sp88 = (f64) sp18;
            ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &spA0), sp8, *((MKVector4 *) &sp80), -800.0f);
            var_r30_249 += 1;
        } while (var_r30_249 < 5);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'void *'
void FuryFXEarth2::ExplodeVortex() {
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
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
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_373;
    f32 temp_f25_371;
    f32 temp_f25_446;
    f32 temp_f29_382;
    f32 temp_f2_391;
    f64 temp_f1_387;
    void *temp_r30_469;
    void *var_r29_358;

    var_r29_358 = this->unkC0;
loop_2:
    if (var_r29_358 != NULL) {
        temp_r30_469 = *var_r29_358;
        if (temp_r30_469 != NULL) {
            M2C_FIELD(temp_r30_469, s32 *, 0x3C) = 2;
            temp_f25_371 = -_table_sinf(1.5707964f + M2C_FIELD(temp_r30_469, f32 *, 0x20));
            temp_f1_373 = _table_sinf(M2C_FIELD(temp_r30_469, f32 *, 0x20));
            sp10 = temp_f25_371;
            sp8 = temp_f1_373;
            spC = 0.0f;
            sp100 = (f64) sp10;
            spF8 = (f64) sp8;
            spD8 = (f64) sp8;
            temp_f29_382 = M2C_FIELD(temp_r30_469, f32 *, 0x30);
            spE0 = (f64) sp10;
            spE8 = (f64) sp8;
            spF0 = (f64) sp10;
            temp_f1_387 = (f64) sp8 * (f64) temp_f29_382;
            spF8 = temp_f1_387;
            temp_f2_391 = (f32) sp100 * temp_f29_382;
            sp100 = temp_f2_391;
            spF8 = temp_f1_387 + this->unkA0;
            sp100 = temp_f2_391 + this->unkA8;
            (*(f32 *) ((u8 *) &spF8 + 0x4)) += M2C_FIELD(temp_r30_469, f32 *, 0x28);
            sp58 = spE8 * 5.717499035e-315;
            sp50 = -6.2831855f;
            sp40 = 6.2831855f;
            sp60 = (f32) spF0 * 2000.0f;
            sp30 = -6.2831855f;
            sp20 = 6.2831855f;
            sp48 = -6.2831855f;
            sp4C = -6.2831855f;
            sp38 = 6.2831855f;
            sp3C = 6.2831855f;
            sp28 = -6.2831855f;
            sp2C = -6.2831855f;
            sp18 = 6.2831855f;
            sp1C = 6.2831855f;
            spC8 = sp58;
            spD0 = (f64) sp60;
            spA8 = (f64) sp48;
            spB0 = (f64) sp50;
            sp98 = (f64) sp38;
            spA0 = (f64) sp40;
            sp78 = (f64) sp28;
            sp80 = (f64) sp30;
            sp68 = (f64) sp18;
            sp70 = (f64) sp20;
            temp_f25_446 = MKRand_Float((int *) &gViewSeed, 0.3f, 1.0f);
            sp88 = KDRand_Vector(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68));
            spB8 = KDRand_Vector(*((MKVector3 *) &spA8), *((MKVector3 *) &sp98));
            ((FlyingChunkPS *) (M2C_FIELD(&gb, FlyingChunkPS **, 0xA4)))->Emit(*((MKVector3 *) &spF8), *((MKVector3 *) &spC8), spB8, sp88, temp_f25_446, this->unkD0, 4, NULL);
            var_r29_358 += 4;
            goto loop_2;
        }
    }
}
#endif

void FuryFXEarth2::SpawnVortexElement() {
    Matrix spF0;
    M2C_UNK spEC;
    M2C_UNK spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
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
    void **temp_r3_519;
    void *temp_r31_521;
    void *temp_r3_515;

    this->unkC8 -= gUpdateTimeDelta;
    if (!(this->unkC8 > 0.0f)) {
        this->unkC8 = 0.01f;
        temp_r3_515 = this->unkC0;
        if ((u32) M2C_FIELD(temp_r3_515, u32 *, -4) != 0U) {
            temp_r3_519 = (void **) (((u8 *) temp_r3_515) - 4);
            this->unkC0 = temp_r3_519;
            temp_r31_521 = *temp_r3_519;
            if (temp_r31_521 != NULL) {
                sp48 = 0.0f;
                sp38 = 6.2831855f;
                sp30 = 6.2831855f;
                sp34 = 6.2831855f;
                sp40 = 0.0f;
                sp44 = 0.0f;
                sp80 = (f64) sp30;
                sp88 = (f64) sp38;
                sp90 = (f64) sp40;
                sp98 = (f64) sp48;
                spA0 = KDRand_Vector(*((MKVector3 *) &sp90), *((MKVector3 *) &sp80));
                sp18 = 6.2831855f;
                sp28 = 0.0f;
                M2C_FIELD(temp_r31_521, MKVector3 *, 0) = spA0;
                sp10 = 6.2831855f;
                sp14 = 6.2831855f;
                sp20 = 0.0f;
                sp24 = 0.0f;
                sp50 = (f64) sp10;
                sp58 = (f64) sp18;
                sp60 = (f64) sp20;
                sp68 = (f64) sp28;
                sp70 = KDRand_Vector(*((MKVector3 *) &sp60), *((MKVector3 *) &sp50));
                M2C_FIELD(temp_r31_521, MKVector3 *, 0x10) = sp70;
                M2C_FIELD(temp_r31_521, f32 *, 0x20) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
                M2C_FIELD(temp_r31_521, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, 3.1415927f, 6.2831855f);
                M2C_FIELD(temp_r31_521, f32 *, 0x28) = -200.0f;
                M2C_FIELD(temp_r31_521, f32 *, 0x2C) = MKRand_Float((int *) &gViewSeed, 100.0f, 1000.0f);
                M2C_FIELD(temp_r31_521, f32 *, 0x30) = MKRand_Float((int *) &gViewSeed, 1800.0f, 2500.0f);
                M2C_FIELD(temp_r31_521, f32 *, 0x34) = MKRand_Float((int *) &gViewSeed, 20.0f, 300.0f);
                M2C_FIELD(temp_r31_521, f32 *, 0x38) = MKRand_Float((int *) &gViewSeed, 0.05f, 0.2f);
                M2C_FIELD(temp_r31_521, s32 *, 0x3C) = 0;
                ((FuryFXEarth2 *) &spB0)->CalcMatrixForVortexElement((FuryFXEarth2::VortexAttachmentPoint *) this);
                M2C_STRUCT_COPY((s32) &spEC + 4, (s32) &spA0.unkC + 4, 0x40);
                MKModel_SetWorldMatrix(M2C_FIELD((this + (M2C_FIELD(temp_r31_521, s32 *, 0x40) * 4)), MKModel **, 0xB0), spF0);
            }
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'void *'
void FuryFXEarth2::DrawVortex() {
    Matrix sp50;
    M2C_UNK sp4C;
    M2C_UNK sp10;
    M2C_UNK spC;
    void *temp_r31_684;
    void *var_r30_645;

    var_r30_645 = this->unkC0;
loop_2:
    if (var_r30_645 != NULL) {
        temp_r31_684 = *var_r30_645;
        if (temp_r31_684 != NULL) {
            ((FuryFXEarth2 *) &sp10)->CalcMatrixForVortexElement((FuryFXEarth2::VortexAttachmentPoint *) this);
            M2C_STRUCT_COPY((s32) &sp4C + 4, (s32) &spC + 4, 0x40);
            MKModel_SetWorldMatrix(*(this + ((M2C_FIELD(temp_r31_684, s32 *, 0x40) * 4) + 0xB0)), sp50);
            MKModel_SetColor(*(this + ((M2C_FIELD(temp_r31_684, s32 *, 0x40) * 4) + 0xB0)), this->unkD0);
            MKModel_Draw(*(this + ((M2C_FIELD(temp_r31_684, s32 *, 0x40) * 4) + 0xB0)), NULL);
            var_r30_645 += 4;
            goto loop_2;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'void *'
void FuryFXEarth2::UpdateVortex() {
    Matrix sp90;
    M2C_UNK sp8C;
    M2C_UNK sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f2_785;
    f32 temp_f2_789;
    f32 temp_f3_766;
    f32 temp_f3_771;
    f32 temp_f4_786;
    f32 temp_f5_767;
    f32 var_f1_795;
    f32 var_f1_807;
    f32 var_f3_778;
    f32 var_f4_759;
    f64 temp_f0_730;
    f64 temp_f0_824;
    s32 temp_r0_714;
    void *temp_r29_892;
    void *temp_r3_860;
    void *temp_r4_863;
    void *var_r31_711;

    var_r31_711 = this->unkC0;
loop_24:
    if (var_r31_711 != NULL) {
        temp_r29_892 = *var_r31_711;
        if (temp_r29_892 != NULL) {
            temp_r0_714 = M2C_FIELD(temp_r29_892, s32 *, 0x3C);
            switch (temp_r0_714) {                  /* irregular */
            case 0:
                temp_f0_730 = M2C_FIELD(temp_r29_892, f64 *, 0x10) * (f64) gUpdateTimeDelta;
                sp20 = temp_f0_730;
                sp40 = temp_f0_730;
                sp28 = M2C_FIELD(temp_r29_892, f32 *, 0x18) * gUpdateTimeDelta;
                sp48 = (f64) sp28;
                M2C_FIELD(temp_r29_892, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_892, f64 *, 0) + temp_f0_730);
                M2C_FIELD(temp_r29_892, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_892, f32 *, 8) + (f32) sp48);
                M2C_FIELD(temp_r29_892, f32 *, 0x20) = (f32) ((gUpdateTimeDelta * (M2C_FIELD(temp_r29_892, f32 *, 0x24) * this->unkC4)) + M2C_FIELD(temp_r29_892, f32 *, 0x20));
                var_f4_759 = 0.5f * (2.0f * gUpdateTimeDelta);
                if (var_f4_759 < 1.0f) {

                } else {
                    var_f4_759 = 1.0f;
                }
                temp_f3_766 = M2C_FIELD(temp_r29_892, f32 *, 0x28);
                temp_f5_767 = M2C_FIELD(temp_r29_892, f32 *, 0x2C);
                temp_f3_771 = (var_f4_759 * (temp_f5_767 - temp_f3_766)) + temp_f3_766;
                M2C_FIELD(temp_r29_892, f32 *, 0x28) = (f32) ((var_f4_759 * (temp_f5_767 - temp_f3_771)) + temp_f3_771);
                var_f3_778 = 0.5f * (1.5f * gUpdateTimeDelta);
                if (var_f3_778 < 1.0f) {

                } else {
                    var_f3_778 = 1.0f;
                }
                temp_f2_785 = M2C_FIELD(temp_r29_892, f32 *, 0x30);
                temp_f4_786 = M2C_FIELD(temp_r29_892, f32 *, 0x34);
                temp_f2_789 = (var_f3_778 * (temp_f4_786 - temp_f2_785)) + temp_f2_785;
                M2C_FIELD(temp_r29_892, f32 *, 0x30) = (f32) ((var_f3_778 * (temp_f4_786 - temp_f2_789)) + temp_f2_789);
                var_f1_795 = M2C_FIELD(temp_r29_892, f32 *, 0x28) - M2C_FIELD(temp_r29_892, f32 *, 0x2C);
                if (var_f1_795 < 0.0f) {
                    var_f1_795 = -var_f1_795;
                }
                if (var_f1_795 <= M2C_BITWISE(f32, 2.0)) {
                    var_f1_807 = M2C_FIELD(temp_r29_892, f32 *, 0x30) - M2C_FIELD(temp_r29_892, f32 *, 0x34);
                    if (var_f1_807 < 0.0f) {
                        var_f1_807 = -var_f1_807;
                    }
                    if (var_f1_807 <= M2C_BITWISE(f32, 2.0)) {
                        M2C_FIELD(temp_r29_892, s32 *, 0x3C) = 1;
                    }
                }
                break;
            case 1:
                temp_f0_824 = M2C_FIELD(temp_r29_892, f64 *, 0x10) * (f64) gUpdateTimeDelta;
                sp10 = temp_f0_824;
                sp30 = temp_f0_824;
                sp18 = M2C_FIELD(temp_r29_892, f32 *, 0x18) * gUpdateTimeDelta;
                sp38 = (f64) sp18;
                M2C_FIELD(temp_r29_892, f64 *, 0) = (f64) (M2C_FIELD(temp_r29_892, f64 *, 0) + temp_f0_824);
                M2C_FIELD(temp_r29_892, f32 *, 8) = (f32) (M2C_FIELD(temp_r29_892, f32 *, 8) + (f32) sp38);
                M2C_FIELD(temp_r29_892, f32 *, 0x20) = (f32) ((gUpdateTimeDelta * (M2C_FIELD(temp_r29_892, f32 *, 0x24) * this->unkC4)) + M2C_FIELD(temp_r29_892, f32 *, 0x20));
                break;
            case 2:
                M2C_FIELD(temp_r29_892, f32 *, 0x30) = (f32) ((3000.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r29_892, f32 *, 0x30));
                if (M2C_FIELD(temp_r29_892, f32 *, 0x30) >= 40000.0f) {
                    temp_r3_860 = this->unkC0;
                    this->unkC0 = ((u8 *) temp_r3_860) + 4;
                    temp_r4_863 = *temp_r3_860;
                    *temp_r3_860 = (void *) *var_r31_711;
                    *var_r31_711 = temp_r4_863;
                }
                break;
            }
            ((FuryFXEarth2 *) &sp50)->CalcMatrixForVortexElement((FuryFXEarth2::VortexAttachmentPoint *) this);
            M2C_STRUCT_COPY((s32) &sp8C + 4, (s32) &unksp4C + 4, 0x40);
            MKModel_SetWorldMatrix(*(this + ((M2C_FIELD(temp_r29_892, s32 *, 0x40) * 4) + 0xB0)), sp90);
            var_r31_711 += 4;
            goto loop_24;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void FuryFXEarth2::UpdateLightPosition(float arg0, float arg1) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    ManagedLight *temp_r3_984;
    f32 temp_f1_940;
    f32 temp_f31_938;
    f64 temp_f0_950;
    f64 temp_f0_966;
    void *temp_r3_990;

    if ((ManagedLight *) this->unkCC != NULL) {
        this->unkE0 += this->unkC4 * (6.2831855f * gUpdateTimeDelta);
        temp_f31_938 = -_table_sinf(1.5707964f + this->unkE0);
        temp_f1_940 = _table_sinf(this->unkE0);
        sp40 = temp_f31_938;
        sp38 = temp_f1_940;
        sp3C = 0.0f;
        sp80 = (f64) sp40;
        sp78 = (f64) sp38;
        temp_f0_950 = sp78 * (f64) arg0;
        sp28 = temp_f0_950;
        sp88 = temp_f0_950;
        sp30 = (f32) sp80 * arg0;
        sp90 = (f64) sp30;
        sp48 = MKVector(0.0f, arg1, 0.0f);
        temp_f0_966 = this->unkA0 + sp88;
        sp8 = temp_f0_966;
        sp58 = temp_f0_966;
        sp10 = this->unkA8 + (f32) sp90;
        sp60 = (f64) sp10;
        sp18 = sp58 + M2C_BITWISE(f64, sp48);
        temp_r3_984 = this->unkCC;
        sp68 = sp18;
        sp20 = (f32) sp60 + sp48.unk8;
        temp_r3_984->unk10 = sp18;
        temp_r3_984->unk18 = (f64) sp20;
        temp_r3_990 = temp_r3_984->unk3C;
        sp70 = (f64) sp20;
        if (temp_r3_990 != NULL) {
            M2C_FIELD(temp_r3_990, f64 *, 0x10) = sp18;
            M2C_FIELD(temp_r3_990, f64 *, 0x18) = (f64) sp20;
        }
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, long, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, unsigned in
s32 FuryFXEarth2::Trigger(const MKVector3 &arg0) {
    ManagedLight *temp_r3_1085;
    ManagedLight *temp_r4_1073;
    s32 temp_r0_1109;
    s32 temp_r29_1132;
    s32 temp_r3_1107;
    s32 var_r30_1125;
    u32 temp_r4_1059;
    u8 var_r3_1115;
    void *temp_r3_1056;
    void *temp_r3_1088;
    void *temp_r4_1111;
    void *var_r5_1053;

    if ((s32) this->unk94 != 0) {
        return 0;
    }
    this->unk94 = 1;
    this->unk98 = 1.0f;
    KDSound_Play3d(GS_SpyroFuryEarth3, M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
    this->unkC4 = 1.0f;
    this->unkC8 = 0.0f;
    this->unkA0 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xA8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    var_r5_1053 = this->unkC0;
loop_4:
    if ((var_r5_1053 != NULL) && ((u32) *var_r5_1053 != 0U)) {
        temp_r3_1056 = this->unkC0;
        this->unkC0 = ((u8 *) temp_r3_1056) + 4;
        temp_r4_1059 = *temp_r3_1056;
        *temp_r3_1056 = (u32) *var_r5_1053;
        *var_r5_1053 = temp_r4_1059;
        var_r5_1053 += 4;
        goto loop_4;
    }
    this->unkE0 = 0.0f;
    temp_r4_1073 = this->unkCC;
    if (temp_r4_1073 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1073, 1U);
        UpdateLightPosition(0.0f, 0.0f);
        temp_r3_1085 = this->unkCC;
        temp_r3_1085->unk38 = 1000.0f;
        temp_r3_1088 = temp_r3_1085->unk3C;
        if (temp_r3_1088 != NULL) {
            M2C_FIELD(temp_r3_1088, f32 *, 0x20) = 1000.0f;
            M2C_FIELD(temp_r3_1088, f32 *, 0x24) = 1000000.0f;
            M2C_FIELD(temp_r3_1088, f32 *, 0x28) = 0.001f;
            M2C_FIELD(temp_r3_1088, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1088, f32 *, 0x24));
        }
    }
    this->unkE4 = 0.0f;
    temp_r3_1107 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_1109 = *(&GameData::gameData[0x70] + (temp_r3_1107 + 0x7C));
    temp_r4_1111 = &GameData::gameData[0x70] + (temp_r3_1107 + 0x64);
    if (temp_r0_1109 == 3) {
        var_r3_1115 = 0;
        if (((s32) M2C_FIELD(temp_r4_1111, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1111, s32 *, 4) == 3)) {
            var_r3_1115 = 1;
        }
        var_r30_1125 = var_r3_1115 != 0;
    } else {
        var_r30_1125 = *(temp_r4_1111 + (temp_r0_1109 * 4));
    }
    temp_r29_1132 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unkE8.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), 15.0f * M2C_FIELD(&gb, f32 *, 0x37C), 3, var_r30_1125, temp_r29_1132, temp_r29_1132, 0, -1);
    M2C_FIELD(&gb, s8 *, 0x381) = 1;
    return 1;
}
#endif

void FuryFXEarth2::SetDefaults() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    FuryFX::SetDefaults();
    this->unk94 = 0;
    this->unk98 = 0.0f;
    this->unkC4 = 1.0f;
    sp8 = 0.7f;
    spC = 0.5f;
    this->unkC8 = 0.0f;
    sp10 = 0.6f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0xD0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xD8) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unkE0 = 0.0f;
}

#if 0 // DRAFT: illegal type
void FuryFXEarth2::Deinit() {
    ManagedLight *temp_r4_1261;
    u32 temp_r0_1229;
    void *temp_r0_1224;
    void *temp_r0_1243;
    void *var_r31_1220;
    void *var_r3_1221;
    void *var_r4_1219;

    MKModel_Destroy(this->unkB0);
    MKModel_Destroy(this->unkB4);
    MKModel_Destroy(this->unkB8);
    MKModel_Destroy(this->unkBC);
    var_r4_1219 = this->unkC0;
    var_r31_1220 = var_r4_1219;
    var_r3_1221 = var_r4_1219;
loop_3:
    temp_r0_1229 = M2C_FIELD(var_r3_1221, u32 *, -4);
    var_r3_1221 -= 4;
    if (temp_r0_1229 != 0U) {
        temp_r0_1224 = *var_r3_1221;
        if (temp_r0_1224 < var_r31_1220) {
            var_r31_1220 = temp_r0_1224;
        }
        goto loop_3;
    }
    if (var_r3_1221 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1243 = *var_r4_1219;
        if (temp_r0_1243 != NULL) {
            if (temp_r0_1243 < var_r31_1220) {
                var_r31_1220 = temp_r0_1243;
            }
            var_r4_1219 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_1220, NULL, 0);
        } else {
            free(var_r31_1220);
        }
    }
    this->unkC0 = NULL;
    temp_r4_1261 = this->unkCC;
    if (temp_r4_1261 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1261, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unkCC);
    }
    FuryFX::Deinit();
}
#endif

void FuryFXEarth2::Draw() {
    if ((s32) this->unk94 != 0) {
        DrawVortex();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionResult' to 'double'
void *FuryFXEarth2::Update() {
    MKCollisionResult sp290;
    s8 sp288;
    f64 sp280;
    f64 sp278;
    s32 sp274;
    s32 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;                                      /* compiler-managed */
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
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
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    MKVector3 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Character *temp_r29_1442;
    ManagedLight *temp_r3_1846;
    ManagedLight *temp_r3_1859;
    ManagedLight *temp_r3_1957;
    ManagedLight *temp_r4_1983;
    TargetManager ***var_r30_1430;
    TargetManager **temp_r27_1616;
    f32 temp_f0_1961;
    f32 temp_f1_1672;
    f32 temp_f2_1358;
    f32 temp_f4_1387;
    f32 var_f1_1703;
    f32 var_f1_1942;
    f32 var_f2_1340;
    f32 var_f3_1558;
    f32 var_f4_1491;
    f64 temp_f0_1402;
    f64 temp_f0_1594;
    f64 temp_f0_1649;
    f64 temp_f0_1660;
    f64 temp_f0_1681;
    f64 temp_f1_1468;
    f64 temp_f1_1497;
    f64 temp_f1_1503;
    f64 temp_f1_1507;
    f64 temp_f2_1925;
    f64 temp_f5_1381;
    s32 temp_r0_1324;
    s32 temp_r27_1904;
    s32 temp_r28_1881;
    s32 temp_r3_1526;
    s32 temp_r3_1879;
    s32 var_r0_1536;
    s32 var_r27_1625;
    s32 var_r30_1897;
    s32 var_r31_1424;
    u8 var_r3_1887;
    void *temp_r3_1467;
    void *temp_r3_1852;
    void *temp_r3_1862;
    void *temp_r3_1963;
    void *temp_r4_1576;
    void *temp_r4_1883;

    this->unk98 -= gUpdateTimeDelta;
    UpdateVortex();
    temp_r0_1324 = this->unk94;
    switch (temp_r0_1324) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        SpawnVortexElement();
        var_f2_1340 = this->unk98;
        if (var_f2_1340 < 1.0f) {

        } else {
            var_f2_1340 = 1.0f;
        }
        if (var_f2_1340 > 0.0f) {

        } else {
            var_f2_1340 = 0.0f;
        }
        temp_f2_1358 = 1.0f - var_f2_1340;
        UpdateLightPosition(500.0f * temp_f2_1358, 600.0f * temp_f2_1358);
        if (this->unk98 <= 0.0f) {
            spE8 = 0.0f;
            spE0 = 0.0f;
            spE4 = -1000.0f;
            this->unk94 = 2;
            this->unk98 = 3.0f;
            sp210 = (f64) spE0;
            sp218 = (f64) spE8;
            temp_f5_1381 = this->unkA0;
            spD0 = temp_f5_1381 + sp210;
            sp108 = 0.0f;
            temp_f4_1387 = this->unkA8;
            sp100 = 0.0f;
            sp104 = 100.0f;
            spD8 = temp_f4_1387 + (f32) sp218;
            sp230 = (f64) sp100;
            sp220 = spD0;
            sp228 = (f64) spD8;
            sp238 = (f64) sp108;
            temp_f0_1402 = temp_f5_1381 + sp230;
            spF0 = temp_f0_1402;
            sp240 = temp_f0_1402;
            spF8 = temp_f4_1387 + (f32) sp238;
            sp248 = (f64) spF8;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp240), *((MKVector3 *) &sp220), &sp290, (MKCollisionMode) 4, 0x0C000000) != 0) {
                sp260 = M2C_BITWISE(f64, sp290);
                var_r31_1424 = 0;
                sp268 = (f64) sp290.unk8;
                var_r30_1430 = ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->Begin();
loop_45:
                if (var_r30_1430 != NULL) {
                    temp_r27_1616 = *var_r30_1430;
                    if (temp_r27_1616 != NULL) {
                        temp_r29_1442 = ((Character *(*)(TargetManager **)) (*temp_r27_1616)->unk8.unk4)(temp_r27_1616);
                        if (((*temp_r27_1616)->unk8.unk0(temp_r27_1616) != NULL) && (M2C_FIELD(*temp_r27_1616, u8 (**)(TargetManager **), 0x18)(temp_r27_1616) != 0) && ((temp_r29_1442 == NULL) || (temp_r29_1442->IsActive() != 0))) {
                            temp_r3_1467 = M2C_FIELD((*temp_r27_1616)->unk8.unk0(temp_r27_1616), void **, 8);
                            temp_f1_1468 = M2C_FIELD(temp_r3_1467, f64 *, 0x30);
                            sp200 = temp_f1_1468;
                            sp208 = M2C_FIELD(temp_r3_1467, f64 *, 0x38);
                            spC0 = temp_f1_1468 - sp260;
                            sp250 = spC0;
                            spC8 = (f32) sp208 - (f32) sp268;
                            sp258 = (f64) spC8;
                            var_f4_1491 = ((f32) sp258 * (f32) sp258) + (((f32) sp250 * (f32) sp250) + ((*(f32 *) ((u8 *) &sp248 + 0xc)) * (*(f32 *) ((u8 *) &sp248 + 0xc))));
                            if (var_f4_1491 > 0.000001f) {
                                if (var_f4_1491 > 0.0f) {
                                    temp_f1_1497 = __frsqrte(var_f4_1491);
                                    temp_f1_1503 = 0.5 * temp_f1_1497 * -(((f64) var_f4_1491 * (temp_f1_1497 * temp_f1_1497)) - 3.0);
                                    temp_f1_1507 = 0.5 * temp_f1_1503 * -(((f64) var_f4_1491 * (temp_f1_1503 * temp_f1_1503)) - 3.0);
                                    var_f4_1491 = (f32) ((f64) var_f4_1491 * (0.5 * temp_f1_1507 * -(((f64) var_f4_1491 * (temp_f1_1507 * temp_f1_1507)) - 3.0)));
                                } else if (var_f4_1491 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_1491 = __float_nan;
                                } else {
                                    sp8 = var_f4_1491;
                                    temp_r3_1526 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                    switch (temp_r3_1526) { /* switch 2; irregular */
                                    case 0x7F800000: /* switch 2 */
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_1536 = 1;
                                        } else {
                                            var_r0_1536 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 2 */
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_1536 = 5;
                                        } else {
                                            var_r0_1536 = 3;
                                        }
                                        break;
                                    default:        /* switch 2 */
                                        var_r0_1536 = 4;
                                        break;
                                    }
                                    if (var_r0_1536 == 1) {
                                        var_f4_1491 = __float_nan;
                                    }
                                }
                                var_f3_1558 = 1.0f / var_f4_1491;
                            } else {
                                var_f3_1558 = 0.0f;
                                var_f4_1491 = 0.0f;
                            }
                            sp250 = (f32) sp250 * var_f3_1558;
                            (*(f32 *) ((u8 *) &sp248 + 0xc)) *= var_f3_1558;
                            M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                            if ((var_f4_1491 == 3000.0f) && (temp_r29_1442 != NULL)) {
                                temp_r4_1576 = temp_r29_1442->unk8;
                                sp1F0 = M2C_FIELD(temp_r4_1576, f64 *, 0x30);
                                sp1F8 = M2C_FIELD(temp_r4_1576, f64 *, 0x38);
                                spB4 = MKRand_Float((int *) &gViewSeed, 1.5f, 2.0f);
                                spB0 = 1.5f;
                                spB8 = 1.5f;
                                sp1D0 = (f64) spB0;
                                sp1D8 = (f64) spB8;
                                temp_f0_1594 = sp1D0 * 5.28426686e-315;
                                spA0 = temp_f0_1594;
                                sp1E0 = temp_f0_1594;
                                spA8 = (f32) sp1D8 * 1.5f;
                                sp1E8 = (f64) spA8;
                                ((EarthBreathWhirlWinds *) (M2C_FIELD(&gb, EarthBreathWhirlWinds **, 0x2C8)))->SpawnWhirlWind(*((MKVector3 *) &sp1F0), *((MKVector3 *) &sp1E0), (Upgrade) 3, 0U, 6.0f);
                                var_r31_1424 += 1;
                            }
                        }
                        var_r30_1430 += 4;
                        goto loop_45;
                    }
                }
                var_r27_1625 = 0;
loop_49:
                if (var_r27_1625 < (s32) (0xC - var_r31_1424)) {
                    sp98 = -1.0f;
                    sp88 = 1.0f;
                    sp90 = -1.0f;
                    sp94 = 0.0f;
                    sp80 = 1.0f;
                    sp84 = 0.0f;
                    sp190 = (f64) sp90;
                    sp198 = (f64) sp98;
                    sp180 = (f64) sp80;
                    sp188 = (f64) sp88;
                    sp1A0 = KDRand_Vector(*((MKVector3 *) &sp190), *((MKVector3 *) &sp180));
                    temp_f0_1649 = sp1A0 * 5.634608575e-315;
                    sp70 = temp_f0_1649;
                    sp1B0 = temp_f0_1649;
                    sp78 = sp1A0.unk8 * 500.0f;
                    sp1B8 = (f64) sp78;
                    temp_f0_1660 = sp260 + temp_f0_1649;
                    sp60 = temp_f0_1660;
                    sp1C0 = temp_f0_1660;
                    sp68 = (f32) sp268 + (f32) sp1B8;
                    sp1C8 = (f64) sp68;
                    temp_f1_1672 = MKRand_Float((int *) &gViewSeed, 1.5f, 2.0f);
                    sp50 = 1.5f;
                    sp54 = temp_f1_1672;
                    sp58 = 1.5f;
                    sp160 = (f64) sp50;
                    sp168 = (f64) sp58;
                    temp_f0_1681 = sp160 * 5.28426686e-315;
                    sp40 = temp_f0_1681;
                    sp170 = temp_f0_1681;
                    sp48 = (f32) sp168 * 1.5f;
                    sp178 = (f64) sp48;
                    ((EarthBreathWhirlWinds *) (M2C_FIELD(&gb, EarthBreathWhirlWinds **, 0x2C8)))->SpawnWhirlWind(*((MKVector3 *) &sp1C0), *((MKVector3 *) &sp170), (Upgrade) 3, 0U, 6.0f);
                    var_r27_1625 += 1;
                    goto loop_49;
                }
                return;
            }
        }
    case 0:                                         /* switch 1 */
        return;
    case 2:                                         /* switch 1 */
        var_f1_1703 = this->unk98;
        if (var_f1_1703 < 3.0f) {

        } else {
            var_f1_1703 = 3.0f;
        }
        if (var_f1_1703 > 0.0f) {

        } else {
            var_f1_1703 = 0.0f;
        }
        this->unkC4 = (5.0f * (1.0f - (var_f1_1703 / 3.0f))) + 1.0f;
        UpdateLightPosition(500.0f, 600.0f);
        EmitTimedSparks();
        if (this->unk98 <= 0.0f) {
            this->unk94 = 3;
            this->unk98 = 1.0f;
            ExplodeVortex();
            KDSound_Play3d(GS_SpyroFuryEarth4, M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            KDSound_Play3d(GS_Rumble3, M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp274 = 0;
                sp140 = MKVector(1.0f, 1.0f, 1.0f);
                sp20 = sp140 * 5.56078426e-315;
                sp270 = 0x417;
                sp278 = sp20;
                sp28 = sp140.unk8 * 150.0f;
                sp288 = 1;
                sp280 = (f64) sp28;
                sp150 = sp20;
                sp158 = (f64) sp28;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp270, sp20);
            }
            sp30 = 0.5f;
            sp34 = 1.0f;
            sp38 = 0.5f;
            sp3C = 1.0f;
            sp130 = (f64) sp30;
            sp138 = (f64) sp38;
            ((ScreenWobbleFX *) (&gb + 0xB8))->EnableScreenFlash(*((MKVector4 *) &sp130), 3.0f * gUpdateTimeDelta);
            if ((ManagedLight *) this->unkCC != NULL) {
                sp110 = MKVector(0.0f, 500.0f, 0.0f);
                sp10 = this->unkA0 + M2C_BITWISE(f64, sp110);
                temp_r3_1846 = this->unkCC;
                sp120 = sp10;
                sp18 = this->unkA8 + sp110.unk8;
                temp_r3_1846->unk10 = sp10;
                temp_r3_1846->unk18 = (f64) sp18;
                temp_r3_1852 = temp_r3_1846->unk3C;
                sp128 = (f64) sp18;
                if (temp_r3_1852 != NULL) {
                    M2C_FIELD(temp_r3_1852, f64 *, 0x10) = sp10;
                    M2C_FIELD(temp_r3_1852, f64 *, 0x18) = (f64) sp18;
                }
                temp_r3_1859 = this->unkCC;
                temp_r3_1859->unk38 = 2000.0f;
                temp_r3_1862 = temp_r3_1859->unk3C;
                if (temp_r3_1862 != NULL) {
                    M2C_FIELD(temp_r3_1862, f32 *, 0x20) = 2000.0f;
                    M2C_FIELD(temp_r3_1862, f32 *, 0x24) = 4000000.0f;
                    M2C_FIELD(temp_r3_1862, f32 *, 0x28) = 0.0005f;
                    M2C_FIELD(temp_r3_1862, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1862, f32 *, 0x24));
                }
            }
            temp_r3_1879 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
            temp_r28_1881 = *(&GameData::gameData[0x70] + (temp_r3_1879 + 0x7C));
            temp_r4_1883 = &GameData::gameData[0x70] + (temp_r3_1879 + 0x64);
            if (temp_r28_1881 == 3) {
                var_r3_1887 = 0;
                if (((s32) M2C_FIELD(temp_r4_1883, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_1883, s32 *, 4) == 3)) {
                    var_r3_1887 = 1;
                }
                var_r30_1897 = var_r3_1887 != 0;
            } else {
                var_r30_1897 = *(temp_r4_1883 + (temp_r28_1881 * 4));
            }
            temp_r27_1904 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
            this->unkE8.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), 15.0f * M2C_FIELD(&gb, f32 *, 0x37C), temp_r28_1881, var_r30_1897, temp_r27_1904, temp_r27_1904, 0, -1);
            temp_f2_1925 = this->unkA0;
            M2C_FIELD(this, f64 *, 0xF8) = temp_f2_1925;
            M2C_FIELD(this, f64 *, 0x100) = (f64) M2C_FIELD(this, f32 *, 0xA8);
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unkE8, 0, 0, &this->unkA0, 1, 2000.0f, temp_f2_1925);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        var_f1_1942 = this->unk98;
        if (var_f1_1942 < 1.0f) {

        } else {
            var_f1_1942 = 1.0f;
        }
        if (var_f1_1942 > 0.0f) {

        } else {
            var_f1_1942 = 0.0f;
        }
        temp_r3_1957 = this->unkCC;
        if (temp_r3_1957 != NULL) {
            temp_f0_1961 = 2000.0f * var_f1_1942;
            temp_r3_1957->unk38 = temp_f0_1961;
            temp_r3_1963 = temp_r3_1957->unk3C;
            if (temp_r3_1963 != NULL) {
                M2C_FIELD(temp_r3_1963, f32 *, 0x20) = temp_f0_1961;
                M2C_FIELD(temp_r3_1963, f32 *, 0x24) = (f32) (temp_f0_1961 * temp_f0_1961);
                M2C_FIELD(temp_r3_1963, f32 *, 0x28) = (f32) (1.0f / temp_f0_1961);
                M2C_FIELD(temp_r3_1963, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1963, f32 *, 0x24));
            }
        }
        if (this->unk98 <= 0.0f) {
            this->unk94 = 0;
            temp_r4_1983 = this->unkCC;
            if (temp_r4_1983 != NULL) {
                ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1983, 0U);
            }
            M2C_FIELD(&gb, s8 *, 0x381) = 0;
        }
        break;
    }
}
#endif

f32 FuryFXEarth2::Resolve() {
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
    ManagedLight *temp_r4_2060;

    FuryFX::Resolve();
    sp20 = 0.0f;
    sp30 = 0.0f;
    sp8 = 0.0f;
    spC = 1.0f;
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
    this->unkCC = (ManagedLight *) (((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_790, lit_791));
    temp_r4_2060 = this->unkCC;
    if (temp_r4_2060 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_2060, 0U);
    }
}

#if 0 // DRAFT: illegal type
s32 FuryFXEarth2::LoadDone() {
    void **temp_r6_2089;
    void *temp_r31_2091;

    KDProp::LoadDone();
loop_2:
    if ((u32) M2C_FIELD(this->unkC0, u32 *, -4) != 0U) {
        temp_r6_2089 = (void **) (((u8 *) this->unkC0) - 4);
        this->unkC0 = temp_r6_2089;
        temp_r31_2091 = *temp_r6_2089;
        M2C_FIELD(temp_r31_2091, s32 *, 0x40) = MKRand_Int((int *) &gViewSeed, 0, 4);
        goto loop_2;
    }
loop_5:
    if ((u32) M2C_FIELD(this->unkC0, u32 *, 0) != 0U) {
        this->unkC0 += 4;
        goto loop_5;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FallingLeaves *' to 'long' Too many errors printed, aborting program
void FuryFXEarth2::Init() {
    s32 var_ctr_2185;
    void *temp_r3_2187;
    void *temp_r3_2193;
    void *var_r3_2172;
    void *var_r5_2181;

    FuryFX::Init();
    this->unk90 = checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves"));
    SetDefaults();
    this->unkB0 = MKModel_Create("p9013_FireRockLavaLarge", NULL, 2, NULL);
    this->unkB4 = MKModel_Create("p9014_FireRockLavaMedium", NULL, 2, NULL);
    this->unkB8 = MKModel_Create("FX0014_RockChunks", NULL, 2, NULL);
    this->unkBC = MKModel_Create("P9011_FireRockLavaSmall", NULL, 2, NULL);
    if (MKHeap::Current() != NULL) {
        var_r3_2172 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1070, NULL, 0);
    } else {
        var_r3_2172 = malloc(0x1070);
    }
    this->unkC0 = var_r3_2172;
    var_r5_2181 = this->unkC0;
    this->unkC0 = ((u8 *) var_r5_2181) + 0xFA0;
    M2C_FIELD(var_r5_2181, s32 *, 0xFA0) = 0;
    var_ctr_2185 = 0x32;
    do {
        temp_r3_2187 = this->unkC0;
        this->unkC0 = ((u8 *) temp_r3_2187) + 4;
        M2C_FIELD(temp_r3_2187, void **, 4) = var_r5_2181;
        var_r5_2181 += 0x50;
        var_ctr_2185 -= 1;
    } while (var_ctr_2185 != 0);
    temp_r3_2193 = this->unkC0;
    this->unkC0 = ((u8 *) temp_r3_2193) + 4;
    M2C_FIELD(temp_r3_2193, void **, 4) = NULL;
}
#endif

void FuryFXEarth2_cpp::__sinit() {
    f32 temp_f0_2240;
    f64 temp_f1_2221;
    f64 temp_f1_2229;
    f64 temp_f3_2209;
    f64 temp_f4_2218;
    f64 temp_f4_2226;
    f64 temp_f8_2211;

    temp_f3_2209 = __frsqrte(2014000.0);
    temp_f8_2211 = __frsqrte(380000.0);
    temp_f4_2218 = 0.5 * temp_f3_2209 * -((2014000.0 * (temp_f3_2209 * temp_f3_2209)) - 3.0);
    temp_f1_2221 = 0.5 * temp_f8_2211 * -((380000.0 * (temp_f8_2211 * temp_f8_2211)) - 3.0);
    temp_f4_2226 = 0.5 * temp_f4_2218 * -((2014000.0 * (temp_f4_2218 * temp_f4_2218)) - 3.0);
    temp_f1_2229 = 0.5 * temp_f1_2221 * -((380000.0 * (temp_f1_2221 * temp_f1_2221)) - 3.0);
    temp_f0_2240 = (f32) (380000.0 * (0.5 * temp_f1_2229 * -((380000.0 * (temp_f1_2229 * temp_f1_2229)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2226 * -((2014000.0 * (temp_f4_2226 * temp_f4_2226)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2240;
}

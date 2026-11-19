#include "spyro/source/Enemies_Cynder.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Ball.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CynderTier2TrainGoal_Think.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/EnemyTestGoals.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/Game.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/ZapPS.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_DDEarthSpawn;
extern s32 GS_DDElecSpawn;
extern s32 GS_DDFireSpawn;
extern s32 GS_DDIceSpawn;
extern s32 GS_PLACEHOLDER;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern GameGlobals gb;
#if 0 // DRAFT: ';' expected
static CharacterBodyFxInit cynderTier1BodyFXInit;   /* unable to generate initializer: confusing struct layout */
static CharacterBodyFxInit cynderTier2BodyFXInit;   /* unable to generate initializer: confusing struct layout */
static CharacterBodyFxInit cynderTier3BodyFXInit;   /* unable to generate initializer: confusing struct layout */
static BoneBlurFXNodeDef cynderTier1NodeBlurDef;    /* unable to generate initializer: confusing struct layout */
static s32 cynderTier1NodeBlurArmLeft[5] = { 4, 0, 1, 2, 3 };
#endif
static s32 cynderTier1NodeBlurArmRight[5] = { 4, 4, 5, 6, 7 };
static s32 cynderTier1NodeBlurLegLeft[4] = { 3, 8, 9, 0xA };
static s32 cynderTier1NodeBlurLegRight[4] = { 3, 0xB, 0xC, 0xD };
static s32 cynderTier1NodeBlurBack[6] = { 5, 0xE, 0xF, 0x10, 0x11, 0x12 };
#if 0 // DRAFT: undefined identifier 'cynderTier1NodeBlurArmLeft'
static s32 *cynderTier1NodeBlurChains[5] = {
    cynderTier1NodeBlurArmLeft,
    cynderTier1NodeBlurArmRight,
    cynderTier1NodeBlurLegLeft,
    cynderTier1NodeBlurLegRight,
    cynderTier1NodeBlurBack,
};
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'BoneBlurFXNodeDef'
static BoneBlurFXNodeDef cynderTier2NodeBlurDef;    /* unable to generate initializer: confusing struct layout */
static s32 cynderTier2NodeBlurArmLeft[5] = { 4, 0, 1, 2, 3 };
#endif
static s32 cynderTier2NodeBlurArmRight[5] = { 4, 4, 5, 6, 7 };
static s32 cynderTier2NodeBlurLegLeft[4] = { 3, 8, 9, 0xA };
static s32 cynderTier2NodeBlurLegRight[4] = { 3, 0xB, 0xC, 0xD };
static s32 cynderTier2NodeBlurBack[6] = { 5, 0xE, 0xF, 0x10, 0x11, 0x12 };
#if 0 // DRAFT: undefined identifier 'cynderTier2NodeBlurArmLeft'
static s32 *cynderTier2NodeBlurChains[5] = {
    cynderTier2NodeBlurArmLeft,
    cynderTier2NodeBlurArmRight,
    cynderTier2NodeBlurLegLeft,
    cynderTier2NodeBlurLegRight,
    cynderTier2NodeBlurBack,
};
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'BoneBlurFXNodeDef'
static BoneBlurFXNodeDef cynderTier3NodeBlurDef;    /* unable to generate initializer: confusing struct layout */
static s32 cynderTier3NodeBlurArmLeft[5] = { 4, 0, 1, 2, 3 };
#endif
static s32 cynderTier3NodeBlurArmRight[5] = { 4, 4, 5, 6, 7 };
static s32 cynderTier3NodeBlurLegLeft[4] = { 3, 8, 9, 0xA };
static s32 cynderTier3NodeBlurLegRight[4] = { 3, 0xB, 0xC, 0xD };
static s32 cynderTier3NodeBlurBack[7] = { 6, 0xE, 0xF, 0x10, 0x11, 0x12, 0x13 };
#if 0 // DRAFT: undefined identifier 'cynderTier3NodeBlurArmLeft'
static s32 *cynderTier3NodeBlurChains[5] = {
    cynderTier3NodeBlurArmLeft,
    cynderTier3NodeBlurArmRight,
    cynderTier3NodeBlurLegLeft,
    cynderTier3NodeBlurLegRight,
    cynderTier3NodeBlurBack,
};
#endif
static u8 lit_895 = 1;
static u8 lit_1140 = 1;

void EnemyTest::LoadDone() {
    Enemy::LoadDone();
}

void EnemyTest::Deinit() {
    Enemy::Deinit();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyTest::Init() {
    EnemyTest_Think *temp_r31_77;

    Enemy::Init();
    operator new(0x38U, NULL, 0);
    temp_r31_77 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_77 != NULL) {
        temp_r31_77->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_77->unk4 = 0;
        temp_r31_77->unk8 = 1;
        temp_r31_77->unk9 = 0;
        temp_r31_77->unkC = 0;
        temp_r31_77->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_77->unk1C = 0;
        temp_r31_77->unk18 = 0;
        temp_r31_77->unk10 = 0;
        temp_r31_77->unk14 = 0;
        temp_r31_77->__vptr = &__vt;
    }
    temp_r31_77->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_77;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void EnemyTestDescriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&cynderTier1BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void EnemyTestDescriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

void EnemyTestDescriptor::Init() {
    EnemyDescriptor::Init();
}

#if 0 // DRAFT: undefined identifier 'unk30C'
void CynderTier3::EmitClubEffects() {
    f64 sp630;
    f64 sp628;
    f64 sp620;
    f64 sp618;
    f64 sp610;
    f64 sp608;
    MKVector3 sp5F8;
    MKVector3 sp5E8;
    MKVector3 sp5D8;
    M2C_UNK sp5C8;
    f64 sp5C0;
    f64 sp5B8;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    f64 sp588;
    MKVector3 sp578;
    MKVector3 sp568;
    MKVector3 sp558;
    M2C_UNK sp548;
    f64 sp540;
    f64 sp538;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    f64 sp508;
    MKVector3 sp4F8;
    MKVector3 sp4E8;
    MKVector3 sp4D8;
    M2C_UNK sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    MKVector3 sp448;
    MKVector3 sp438;
    MKVector3 sp428;
    M2C_UNK sp418;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    MKVector3 sp3B8;
    MKVector3 sp3A8;
    M2C_UNK sp398;
    f64 sp390;
    f64 sp388;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    MKVector3 sp348;
    MKVector3 sp338;
    MKVector3 sp328;
    M2C_UNK sp318;
    f64 sp310;
    f64 sp308;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    MKVector3 sp2C8;
    MKVector3 sp2B8;
    MKVector3 sp2A8;
    M2C_UNK sp298;
    f64 sp290;
    f64 sp288;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    MKVector3 sp238;
    MKVector3 sp228;
    M2C_UNK sp218;
    f64 sp210;
    f64 sp208;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f32 sp1D0;
    f64 sp1C8;
    f32 sp1C0;
    f64 sp1B8;
    f32 sp1B0;
    f64 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp160;
    f64 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f64 sp128;
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
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_192;
    f32 temp_f1_288;
    f32 temp_f26_209;
    f64 temp_f0_292;
    f64 temp_f0_388;
    f64 temp_f0_472;
    f64 temp_f0_590;
    f64 temp_f0_800;
    f64 temp_f0_889;
    f64 temp_f0_966;
    s32 temp_r0_210;
    s32 var_r27_498;
    s32 var_r27_534;
    u32 temp_r4_197;
    void *temp_r26_687;
    void *temp_r3_683;

    temp_f0_192 = M2C_FIELD(this->unk0, f32 *, 8);
    if (!(this->unk24 > (temp_f0_192 * temp_f0_192)) && (temp_r4_197 = M2C_FIELD(this->unkA20, u32 *, 0x280), ((temp_r4_197 == -1U) == 0))) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) temp_r4_197, (MKVector3 *) &this->unkB00);
        temp_f26_209 = MKModel_GetRefPointRadius(this->unk4, (s32) M2C_FIELD(this->unkA20, u32 *, 0x280));
        temp_r0_210 = M2C_FIELD(this->unkA20, s32 *, 0x1D0);
        switch (temp_r0_210) {                      /* irregular */
        case 0:
            if (gb.unk30C >= this->unkB50) {
                MKVector(1.0f, 1.0f, 1.0f);
                MKVector(-1.0f, -1.0f, -1.0f);
                KDRand_Vector(sp5E8, sp5D8);
                sp5F8.operator*(temp_f26_209);
                sp128 = sp5F8 * 5.222099017e-315;
                sp608 = sp128;
                sp130 = sp5F8.unk8 * 0.5f;
                sp628 = sp128;
                sp610 = (f64) sp130;
                sp630 = (f64) sp130;
                MKVector(0.0f, MKRand_Float(&gViewSeed, 1.0f, 2.0f), 0.0f);
                sp118 = sp5A8 * 5.634608575e-315;
                sp5B8 = sp118;
                sp120 = sp5B0 * 500.0f;
                sp618 = sp118;
                sp5C0 = (f64) sp120;
                sp620 = (f64) sp120;
                temp_f1_288 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
                temp_f0_292 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
                sp1C8 = temp_f0_292;
                sp598 = temp_f0_292;
                sp1D0 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
                sp5A0 = (f64) sp1D0;
                gb.unk240.Emit(*((MKVector3 *) &sp598), *((MKVector3 *) &sp618), temp_f1_288, 0.75f);
                this->unkB50 = gb.unk30C + MKRand_Float(&gViewSeed, 0.375f, 0.75f);
            }
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp568, sp558);
            sp578.operator*(temp_f26_209);
            sp108 = sp578 * 5.222099017e-315;
            sp588 = sp108;
            sp110 = sp578.unk8 * 0.5f;
            sp628 = sp108;
            sp590 = (f64) sp110;
            sp630 = (f64) sp110;
            MKVector(0.0f, MKRand_Float(&gViewSeed, 0.5f, 1.0f), 0.0f);
            spF8 = sp528 * 5.634608575e-315;
            sp538 = spF8;
            sp100 = sp530 * 500.0f;
            sp618 = spF8;
            sp540 = (f64) sp100;
            sp620 = (f64) sp100;
            sp20 = MKRand_Float(&gViewSeed, 5.0f, 6.0f);
            temp_f0_388 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
            sp1B8 = temp_f0_388;
            sp518 = temp_f0_388;
            sp1C0 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
            sp520 = (f64) sp1C0;
            gb.unk68->Emit(*((MKVector3 *) &sp518), *((MKVector3 *) &sp618), sp20);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp4E8, sp4D8);
            sp4F8.operator*(temp_f26_209);
            spE8 = sp4F8 * 5.222099017e-315;
            sp508 = spE8;
            spF0 = sp4F8.unk8 * 0.5f;
            sp628 = spE8;
            sp510 = (f64) spF0;
            sp630 = (f64) spF0;
            MKVector(0.0f, MKRand_Float(&gViewSeed, 1.0f, 2.0f), 0.0f);
            spD8 = sp4A8 * 5.634608575e-315;
            sp198 = 0.5f;
            sp19C = 0.33f;
            spE0 = sp4B0 * 500.0f;
            sp1A0 = 0.1f;
            sp1A4 = 1.0f;
            sp4B8 = spD8;
            sp4C0 = (f64) spE0;
            sp618 = spD8;
            sp620 = (f64) spE0;
            sp488 = (f64) sp198;
            sp490 = (f64) sp1A0;
            sp1C = MKRand_Float(&gViewSeed, 4.0f, 6.0f);
            temp_f0_472 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
            sp1A8 = temp_f0_472;
            sp498 = temp_f0_472;
            sp1B0 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
            sp4A0 = (f64) sp1B0;
            gb.unk74->Emit(*((MKVector3 *) &sp498), *((MKVector3 *) &sp618), sp1C, *((MKVector4 *) &sp488), 0.0f);
            return;
        case 1:
            if (gb.unk30C >= this->unkB50) {
                var_r27_498 = 0;
                do {
                    KDRand_UnitVector();
                    spC8 = sp468 * 5.65986426e-315;
                    sp478 = spC8;
                    spD0 = sp470 * 800.0f;
                    sp618 = spC8;
                    sp480 = (f64) spD0;
                    sp620 = (f64) spD0;
                    gb.unk230->Emit(*((MKVector3 *) &this->unkB00), *((MKVector3 *) &sp618), MKRand_Float(&gViewSeed, 1.0f, 2.0f), 1U);
                    var_r27_498 += 1;
                } while (var_r27_498 < 2);
                var_r27_534 = 0;
loop_17:
                if (var_r27_534 < MKRand_Int(&gViewSeed, 1, 3)) {
                    MKVector(1.0f, 1.0f, 1.0f);
                    MKVector(-1.0f, -1.0f, -1.0f);
                    KDRand_Vector(sp438, sp428);
                    sp448.operator*(temp_f26_209);
                    spB8 = sp448 * 5.180653787e-315;
                    sp458 = spB8;
                    spC0 = sp448.unk8 * 0.25f;
                    sp628 = spB8;
                    sp460 = (f64) spC0;
                    sp630 = (f64) spC0;
                    KDRand_UnitVector();
                    sp178 = 1.0f;
                    sp17C = 0.0f;
                    sp180 = 0.2f;
                    sp184 = 1.0f;
                    sp618 = sp408;
                    sp620 = sp410;
                    sp3E8 = (f64) sp178;
                    sp3F0 = (f64) sp180;
                    sp18 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                    temp_f0_590 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
                    sp188 = temp_f0_590;
                    sp3F8 = temp_f0_590;
                    sp190 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
                    sp400 = (f64) sp190;
                    gb.unk94->Trigger(*((MKVector3 *) &sp3F8), *((MKVector3 *) &sp618), sp18, lit_1140, (MKVector4) &sp3E8);
                    var_r27_534 += 1;
                    goto loop_17;
                }
                this->unkB50 = gb.unk30C + MKRand_Float(&gViewSeed, 0.0f, 0.25f);
                return;
            }
            break;
        case 2:
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp3B8, sp3A8);
            sp3C8.operator*(temp_f26_209);
            spA8 = sp3C8 * 5.222099017e-315;
            sp3D8 = spA8;
            spB0 = sp3C8.unk8 * 0.5f;
            sp628 = spA8;
            sp3E0 = (f64) spB0;
            sp630 = (f64) spB0;
            KDRand_UnitVector();
            sp98 = sp378 * 5.56078426e-315;
            sp388 = sp98;
            spA0 = sp380 * 150.0f;
            sp618 = sp98;
            sp390 = (f64) spA0;
            sp620 = (f64) spA0;
            unksp61C = MKRand_Float(&gViewSeed, 3.0f, 4.0f);
            temp_r3_683 = M2C_FIELD(M2C_FIELD(gb.unk2A4, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A4);
            if (temp_r3_683 != NULL) {
                temp_r26_687 = M2C_FIELD(temp_r3_683, void **, 0x2C);
                sp88 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
                M2C_FIELD(temp_r3_683, f64 *, 0) = sp88;
                sp90 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
                sp368 = sp88;
                M2C_FIELD(temp_r3_683, f64 *, 8) = (f64) sp90;
                M2C_FIELD(temp_r3_683, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_683, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_683, f32 *, 0x10) = 0.2f;
                M2C_FIELD(temp_r3_683, f32 *, 0x14) = 0.2f;
                M2C_FIELD(temp_r3_683, f32 *, 0x18) = 0.2f;
                M2C_FIELD(temp_r3_683, f32 *, 0x1C) = 1.0f;
                sp370 = (f64) sp90;
                M2C_FIELD(temp_r26_687, f64 *, 0) = sp618;
                M2C_FIELD(temp_r26_687, f64 *, 8) = sp620;
                M2C_FIELD(temp_r26_687, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.25f, 0.8f);
                M2C_FIELD(temp_r26_687, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_687, f32 *, 0x14) = (f32) (M2C_FIELD(gb.unk2A4, f32 *, 0xF4) - 0.2f);
                return;
            }
            break;
        case 3:
            if (gb.unk30C >= this->unkB50) {
                MKVector(1.0f, 1.0f, 1.0f);
                MKVector(-1.0f, -1.0f, -1.0f);
                KDRand_Vector(sp338, sp328);
                sp348.operator*(temp_f26_209);
                sp78 = sp348 * 5.222099017e-315;
                sp358 = sp78;
                sp80 = sp348.unk8 * 0.5f;
                sp628 = sp78;
                sp360 = (f64) sp80;
                sp630 = (f64) sp80;
                KDRand_UnitVectorXZ();
                sp68 = sp2F8 * 5.53552857e-315;
                sp308 = sp68;
                sp70 = sp300 * 100.0f;
                sp618 = sp68;
                sp310 = (f64) sp70;
                sp620 = (f64) sp70;
                sp10 = MKRand_Int(&gViewSeed, 0, 3);
                sp14 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
                temp_f0_800 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
                sp168 = temp_f0_800;
                sp2E8 = temp_f0_800;
                sp170 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
                sp2F0 = (f64) sp170;
                ((FallingLeaves *) (M2C_FIELD(checked_cast<CynderTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), FallingLeaves **, 0x2B8)))->Emit(*((MKVector3 *) &sp2E8), *((MKVector3 *) &sp618), sp14, sp10, 1U);
                this->unkB50 = gb.unk30C + MKRand_Float(&gViewSeed, 0.5f, 1.0f);
            }
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp2B8, sp2A8);
            sp2C8.operator*(temp_f26_209);
            sp58 = sp2C8 * 5.222099017e-315;
            sp2D8 = sp58;
            sp60 = sp2C8.unk8 * 0.5f;
            sp628 = sp58;
            sp2E0 = (f64) sp60;
            sp630 = (f64) sp60;
            KDRand_UnitVectorXZ();
            sp48 = sp278 * 5.56078426e-315;
            sp288 = sp48;
            sp50 = sp280 * 150.0f;
            sp618 = sp48;
            sp290 = (f64) sp50;
            sp620 = (f64) sp50;
            spC = MKRand_Float(&gViewSeed, 0.1f, 0.5f);
            temp_f0_889 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
            sp158 = temp_f0_889;
            sp268 = temp_f0_889;
            sp160 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
            sp270 = (f64) sp160;
            gb.EmitSmallRocks(*((MKVector3 *) &sp268), *((MKVector3 *) &sp618), spC);
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, -1.0f, -1.0f);
            KDRand_Vector(sp238, sp228);
            sp248.operator*(temp_f26_209);
            sp38 = sp248 * 5.222099017e-315;
            sp258 = sp38;
            sp40 = sp248.unk8 * 0.5f;
            sp628 = sp38;
            sp260 = (f64) sp40;
            sp630 = (f64) sp40;
            KDRand_UnitVector();
            sp28 = sp1F8 * 5.60222949e-315;
            sp138 = 0.0f;
            sp13C = 1.0f;
            sp30 = sp200 * 300.0f;
            sp140 = 0.0f;
            sp144 = 1.0f;
            sp208 = sp28;
            sp210 = (f64) sp30;
            sp618 = sp28;
            sp620 = (f64) sp30;
            sp1D8 = (f64) sp138;
            sp1E0 = (f64) sp140;
            sp8 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
            temp_f0_966 = M2C_FIELD(this, f64 *, 0xB18) + sp628;
            sp148 = temp_f0_966;
            sp1E8 = temp_f0_966;
            sp150 = M2C_FIELD(this, f32 *, 0xB20) + (f32) sp630;
            sp1F0 = (f64) sp150;
            gb.unk74->Emit(*((MKVector3 *) &sp1E8), *((MKVector3 *) &sp618), sp8, *((MKVector4 *) &sp1D8), 0.0f);
            break;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'SetSpawnGoal__15EnemyGoal_ThinkFP12Goal'
void CynderTier3::Spawn(EnemyGeneratorDoor *arg0) {
    M2C_FIELD(this->unkAF8, EnemyGeneratorDoor **, 0x10) = arg0;
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>((EnemyGoal_Think *) this->unkA24, (Goal<Enemy> *) this->unkAF8);
    Enemy::Spawn(arg0->unk18);
}
#endif

#if 0 // DRAFT: expression syntax error
void CynderTier3::Message(MKMessage *arg0) {
    Enemy::Message(arg0);
    this->unkB10.Message(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
void CynderTier3::Update() {
    s32 sp8;
    u8 var_r27_1104;
    u8 var_r28_1102;
    u8 var_r29_1066;
    u8 var_r29_1107;
    u8 var_r31_1101;
    void *temp_r4_1155;

    Enemy::Update();
    if (this->unk10 & 0x40000) {
        var_r29_1066 = 0;
        if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
            var_r29_1066 = 1;
        }
        if ((var_r29_1066 == 0) && ((s32) this->unk750.unk68 != 1) && (((Frustum *) (M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0))->IsVisible((Matrix *) this->unk8, M2C_FIELD(this->unk0, BoundingVolume **, 0x1C)) != 0)) {
            EmitClubEffects();
        }
    }
    var_r31_1101 = 0;
    var_r28_1102 = 0;
    var_r27_1104 = 0;
    if (this->unk10 & 0x20000) {
        var_r29_1107 = 0;
        if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
            var_r29_1107 = 1;
        }
        if (var_r29_1107 == 0) {
            var_r27_1104 = 1;
        }
    }
    if ((var_r27_1104 != 0) && ((s32) this->unk750.unk68 != 1)) {
        var_r28_1102 = 1;
    }
    if ((var_r28_1102 != 0) && (IsDying() == 0)) {
        var_r31_1101 = 1;
    }
    if (((u32) M2C_FIELD(this->unkA20, u32 *, 0x280) != -1U) && ((s32) M2C_FIELD(checked_cast<CynderTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B4) != 0)) {
        temp_r4_1155 = checked_cast<CynderTier3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unkB10.Update(M2C_FIELD(temp_r4_1155, s32 *, 0x2B4), 1U, var_r31_1101, NULL, (MKVector3 *) &this->unkB00, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    TestForSpikes();
    TestForTraps();
}
#endif

#if 0 // DRAFT: undefined identifier 'cynderTier3NodeBlurDef'
void CynderTier3::LoadDone() {
    Enemy::LoadDone();
    M2C_FIELD(this, BoneBlurFX **, 0xA10) = checked_cast<BoneBlurFX *, MKProp>(gMK->CreateProp("BoneBlurFX"));
    ((BoneBlurFX *) (M2C_FIELD(this, BoneBlurFX **, 0xA10)))->InitData(M2C_FIELD(M2C_FIELD(this, void **, 0x630), MKModel **, 8), &cynderTier3NodeBlurDef, 0x14, cynderTier3NodeBlurChains, 5, 5, 1U);
    this->unkB50 = gb.unk30C + 0.0f;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void CynderTier3::Deinit() {
    s32 temp_r3_1229;

    KDSound_Stop((s32 *) &this->unkB10);
    temp_r3_1229 = this->unkAF8;
    if ((u32) temp_r3_1229 != 0U) {
        M2C_FIELD(*temp_r3_1229, M2C_UNK (**)(), 0xC)();
        operator delete((void *) this->unkAF8);
    }
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderTier3::Init() {
    EnemyGoal_Think *temp_r31_1269;
    s32 temp_r4_1321;

    Enemy::Init();
    InitSpawnerObject(3, 3, 3);
    operator new(0x74U, NULL, 0);
    temp_r31_1269 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_1269 != NULL) {
        temp_r31_1269->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_1269->unk4 = 0;
        temp_r31_1269->unk8 = 1;
        temp_r31_1269->unk9 = 0;
        temp_r31_1269->unkC = 0;
        temp_r31_1269->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_1269->unk1C = 0;
        temp_r31_1269->unk18 = 0;
        temp_r31_1269->unk10 = 0;
        temp_r31_1269->unk14 = 0;
        temp_r31_1269->__vptr = &__vt;
    }
    temp_r31_1269->Init((Enemy *) this);
    temp_r31_1269->InitOperateLeverGoal();
    temp_r31_1269->InitKongGoal();
    this->unkA24 = (EnemyAttack *) temp_r31_1269;
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r4_1321 = this->unkAF8;
    M2C_FIELD(temp_r4_1321, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_1321, CynderTier3 **, 0xC) = this;
    M2C_FIELD(temp_r4_1321, s32 *, 4) = 0x38;
    if ((CynderTier3 *) M2C_FIELD(temp_r4_1321, CynderTier3 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_1321, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_1321, s32 *, 0x10) = 0;
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>(temp_r31_1269, (Goal<Enemy> *) this->unkAF8);
    M2C_FIELD(this, f32 *, 0xB18) = 0.0f;
    this->unkB04 = 0.0f;
    M2C_FIELD(this, f32 *, 0xB20) = 0.0f;
    this->unkB10.Init(0.25f, 0.25f);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void CynderTier3Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void CynderTier3Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&cynderTier3BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
    this->unk280 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "Weapon01");
    this->unk2B8 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
}
#endif

#if 0 // DRAFT: function call 'KDSound_LoadLine(MKIniLine *, const char[14], long *)' does
s32 CynderTier3Descriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1414;

    var_r31_1414 = 0;
    if ((EnemyDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndClubEffect", &this->unk2B4) != 0)) {
        var_r31_1414 = 1;
    }
    return var_r31_1414;
}
#endif

void CynderTier3Descriptor::Init() {
    EnemyDescriptor::Init();
    this->unk2B4 = GS_PLACEHOLDER;
}

#if 0 // DRAFT: function call 'Normalise(MKVector3)' does not match
void CynderTier2Train::UpdateMovementCustom() {
    Matrix sp80;
    Matrix sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    MKVector3 sp10;
    void *temp_r3_1468;

    temp_r3_1468 = this->unk630;
    MKModel_GetRefPointMatrix(M2C_FIELD(temp_r3_1468, MKModel **, 0), M2C_FIELD(temp_r3_1468, s32 *, 4) + M2C_FIELD(temp_r3_1468, s32 *, 8), &sp80, 1U);
    M2C_FIELD(this, f64 *, 0x588) = (f64) sp80.unk30;
    M2C_FIELD(this, f64 *, 0x590) = (f64) sp80.unk38;
    Normalise(sp30);
    sp80 = M2C_BITWISE(f32, sp30);
    sp80.unk4 = sp30.unk4;
    sp80.unk8 = sp30.unk8;
    sp80.unkC = 0.0f;
    Normalise(sp20);
    sp80.unk10 = M2C_BITWISE(f32, sp20);
    sp80.unk14 = sp20.unk4;
    sp80.unk18 = sp20.unk8;
    sp80.unk1C = 0.0f;
    Normalise(sp10);
    sp80.unk20 = M2C_BITWISE(f32, sp10);
    sp80.unk24 = sp10.unk4;
    sp80.unk28 = sp10.unk8;
    sp80.unk2C = 0.0f;
    sp80.unk30 = 0.0f;
    sp80.unk34 = 0.0f;
    sp80.unk38 = 0.0f;
    sp80.unk3C = 1.0f;
    sp40.SetRotateAroundAxis(*((MKVector3 *) &sp80.unk10), 3.1415927f);
    sp80.Multiply3x3(&sp80, &sp40);
    sp80.unk30 = (f32) M2C_FIELD(this, f64 *, 0x588);
    sp80.unk34 = this->unk588.unk0;
    sp80.unk38 = this->unk588.unk4;
    sp80.unk3C = 1.0f;
    SetWorldMatrix(&sp80);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderTier2Train::Init() {
    CynderTier2TrainGoal_Think *temp_r31_1557;

    CynderTier2::Init();
    operator new(0x34U, NULL, 0);
    temp_r31_1557 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_1557 != NULL) {
        temp_r31_1557->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_1557->unk4 = 0;
        temp_r31_1557->unk8 = 1;
        temp_r31_1557->unk9 = 0;
        temp_r31_1557->unkC = NULL;
        temp_r31_1557->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_1557->unk1C = NULL;
        temp_r31_1557->unk18 = 0;
        temp_r31_1557->unk10 = 0;
        temp_r31_1557->unk14 = 0;
        temp_r31_1557->__vptr = &__vt;
    }
    temp_r31_1557->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_1557;
    M2C_FIELD(this, u8 *, 0xB02) = (u8) (M2C_FIELD(this, u8 *, 0xB02) | 8);
}
#endif

void CynderTier2TrainDescriptor::Init() {
    CynderTier2Descriptor::Init();
    this->unk2B4 = 0;
}

#if 0 // DRAFT: undefined identifier 'SetSpawnGoal__15EnemyGoal_ThinkFP12Goal'
void CynderTier2::Spawn(EnemyGeneratorDoor *arg0) {
    M2C_FIELD(this->unkAF8, EnemyGeneratorDoor **, 0x10) = arg0;
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>((EnemyGoal_Think *) this->unkA24, (Goal<Enemy> *) this->unkAF8);
    Enemy::Spawn(arg0->unk18);
}
#endif

void CynderTier2::Update() {
    Enemy::Update();
    TestForSpikes();
    TestForTraps();
}

#if 0 // DRAFT: undefined identifier 'cynderTier2NodeBlurDef'
void CynderTier2::LoadDone() {
    Enemy::LoadDone();
    M2C_FIELD(this, BoneBlurFX **, 0xA10) = checked_cast<BoneBlurFX *, MKProp>(gMK->CreateProp("BoneBlurFX"));
    ((BoneBlurFX *) (M2C_FIELD(this, BoneBlurFX **, 0xA10)))->InitData(M2C_FIELD(M2C_FIELD(this, void **, 0x630), MKModel **, 8), &cynderTier2NodeBlurDef, 0x13, cynderTier2NodeBlurChains, 5, 5, 1U);
}
#endif

#if 0 // DRAFT: pointer/array required
void CynderTier2::Deinit() {
    s32 temp_r3_1699;

    temp_r3_1699 = this->unkAF8;
    if ((u32) temp_r3_1699 != 0U) {
        M2C_FIELD(*temp_r3_1699, M2C_UNK (**)(), 0xC)();
        operator delete((void *) this->unkAF8);
    }
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderTier2::Init() {
    EnemyGoal_Think *temp_r31_1737;
    s32 temp_r4_1785;

    Enemy::Init();
    this->unkAF8 = 0;
    if ((u8) M2C_FIELD(this->unk0, u8 *, 0x2B4) != 0) {
        operator new(0x74U, NULL, 0);
        temp_r31_1737 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r31_1737 != NULL) {
            temp_r31_1737->__vptr = &__vt__12Goal<5Enemy>;
            temp_r31_1737->unk4 = 0;
            temp_r31_1737->unk8 = 1;
            temp_r31_1737->unk9 = 0;
            temp_r31_1737->unkC = 0;
            temp_r31_1737->__vptr = &__vt__21CompositeGoal<5Enemy>;
            temp_r31_1737->unk1C = 0;
            temp_r31_1737->unk18 = 0;
            temp_r31_1737->unk10 = 0;
            temp_r31_1737->unk14 = 0;
            temp_r31_1737->__vptr = &__vt;
        }
        temp_r31_1737->Init((Enemy *) this);
        this->unkA24 = (EnemyAttack *) temp_r31_1737;
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
        temp_r4_1785 = this->unkAF8;
        M2C_FIELD(temp_r4_1785, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_1785, CynderTier2 **, 0xC) = this;
        M2C_FIELD(temp_r4_1785, s32 *, 4) = 0x38;
        if ((CynderTier2 *) M2C_FIELD(temp_r4_1785, CynderTier2 **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_1785, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_1785, s32 *, 0x10) = 0;
        SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>(temp_r31_1737, (Goal<Enemy> *) this->unkAF8);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void CynderTier2Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void CynderTier2Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&cynderTier2BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
}
#endif

void CynderTier2Descriptor::Init() {
    EnemyDescriptor::Init();
    this->unk2B4 = 1;
}

void CynderTier1::Message(MKMessage *arg0) {
    s32 temp_r0_1877;

    if ((s32) arg0->unk0 != 4) {
        goto block_4;
    }
    temp_r0_1877 = this->unkB04;
    if ((u32) temp_r0_1877 != 0U) {
        M2C_FIELD(M2C_FIELD(temp_r0_1877, void **, 0x44), M2C_UNK (**)(s32), 0x2C)(temp_r0_1877);
        return;
    }
block_4:
    Enemy::Message(arg0);
}

#if 0 // DRAFT: illegal type
void CynderTier1::DefrostBall() {
    s8 spA6;
    s8 spA5;
    s8 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    f32 sp8C;
    f32 sp88;
    f64 sp80;
    f64 sp78;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    EnemyGoal_Think *temp_r3_1987;
    f64 temp_f0_2022;
    f64 temp_f1_2012;
    f64 temp_f2_1920;
    f64 temp_f3_1918;
    s32 temp_r3_1947;
    void *temp_r3_2009;
    void *temp_r5_1914;

    if ((u32) this->unkB04 != 0U) {
        sp6C = 0;
        temp_r5_1914 = this->unk8;
        temp_f3_1918 = M2C_FIELD(temp_r5_1914, f64 *, 0x30);
        temp_f2_1920 = M2C_FIELD(temp_r5_1914, f64 *, 0x38);
        sp58 = temp_f3_1918;
        sp68 = 4;
        sp70 = 0;
        sp78 = temp_f3_1918;
        sp80 = temp_f2_1920;
        sp88 = 1.0f;
        spA4 = 0;
        sp90 = 1;
        sp98 = 0x4000;
        spA5 = 0;
        spA6 = 0;
        sp94 = -1;
        sp9C = 0;
        spA0 = 0;
        sp8C = 1.0f;
        sp60 = temp_f2_1920;
        gMK->SendMessage(&sp68, 0, 0, temp_r5_1914 + 0x30, 1, 0x4000, 1, 400.0f, temp_f2_1920, temp_f3_1918);
        this->unkB04->Smash();
        temp_r3_1947 = this->unkB04;
        M2C_FIELD(M2C_FIELD(temp_r3_1947, void **, 0x44), M2C_UNK (**)(s32), 0x34)(temp_r3_1947);
        M2C_FIELD(this->unkB04, s32 *, 0x230) = 0;
        this->unkB04->SetGroup(0xFF);
        this->unkB04 = 0;
        this->unk110.Teleport(this->unk588, 0xA, 5.0f);
        M2C_FIELD(GetCollisionInfo(), s8 *, 4) = 1;
        SetMovementType((CharacterMoveType) 0);
        SetInvulnerableToMeleeAttacks(0U, 1U);
        SetupEnemyRegion(*((MKVector3 *) &this->unk588), 1000.0f);
        temp_r3_1987 = checked_cast<P15EnemyGoal_Think,12Goal<5Enemy>>__FP12Goal<5Enemy>((Goal<Enemy> *) this->unkA28);
        temp_r3_1987->RemoveAllInactiveSubgoals(0x5B);
        if ((this->unkAB0 > 0.0f) && (temp_r3_1987->IsPresent(0x5B) == 0)) {
            sp18 = M2C_FIELD(this, f64 *, 0xC0) * 5.53552857e-315;
            temp_r3_2009 = this->unk8;
            temp_f1_2012 = M2C_FIELD(temp_r3_2009, f64 *, 0x30);
            sp20 = this->unkC8 * 100.0f;
            sp28 = sp18;
            sp38 = temp_f1_2012;
            sp30 = (f64) sp20;
            sp40 = M2C_FIELD(temp_r3_2009, f64 *, 0x38);
            temp_f0_2022 = temp_f1_2012 + sp28;
            sp8 = temp_f0_2022;
            sp48 = temp_f0_2022;
            sp10 = (f32) sp40 + (f32) sp30;
            sp50 = (f64) sp10;
            AddDamage(0.0f, 0U, *((MKVector3 *) &sp48), 0x4000, 1, 0U, 0U, NULL, 0.0f, 1.0f);
        }
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void CynderTier1::UpdateFrozenBallMovement() {
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f64 temp_f0_2099;
    f64 temp_f1_2146;
    s32 temp_r3_2067;
    s32 temp_r5_2137;
    u8 temp_r4_2169;

    temp_r3_2067 = this->unkB04;
    if ((u32) temp_r3_2067 != 0U) {
        M2C_STRUCT_COPY((s32) &sp60.unk1C + 4, M2C_FIELD(temp_r3_2067, s32 *, 8) - 4 + 4, 0x40);
        sp60.NormaliseScale();
        sp30 = -sp60.unk30;
        sp34 = -sp60.unk34;
        sp38 = -sp60.unk38;
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        temp_f0_2099 = sp40 * 5.53552857e-315;
        sp20 = temp_f0_2099;
        sp50 = temp_f0_2099;
        sp28 = (f32) sp48 * 100.0f;
        sp58 = (f64) sp28;
        sp10 = spB0 + temp_f0_2099;
        sp60.unk10 = sp10;
        sp18 = spB8 + (f32) sp58;
        sp60.unk18 = (f64) sp18;
        spB0 = sp60.unk10;
        spB4 = sp60.unk14;
        spB8 = (f32) (f64) sp18;
        spBC = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &sp60.unk20));
        M2C_FIELD(this, f64 *, 0x588) = (f64) spB0;
        M2C_FIELD(this, f64 *, 0x590) = (f64) spB8;
        temp_r5_2137 = this->unkB04;
        this->unk110.unk8 = M2C_FIELD(temp_r5_2137, f64 *, 0x150);
        this->unk110.unk10 = M2C_FIELD(temp_r5_2137, f64 *, 0x158);
        this->unk110.unk18 = M2C_FIELD(temp_r5_2137, f64 *, 0x160);
        this->unk110.unk20 = M2C_FIELD(temp_r5_2137, f64 *, 0x168);
        temp_f1_2146 = M2C_FIELD(temp_r5_2137, f64 *, 0x170);
        this->unk110.unk28 = temp_f1_2146;
        this->unk110.unk30 = M2C_FIELD(temp_r5_2137, f64 *, 0x178);
        this->unk110.unk38 = M2C_FIELD(temp_r5_2137, f32 *, 0x180);
        this->unk110.unk3C = M2C_FIELD(temp_r5_2137, f32 *, 0x184);
        this->unk110.unk40 = M2C_FIELD(temp_r5_2137, s32 *, 0x188);
        this->unk110.unk44 = M2C_FIELD(temp_r5_2137, s32 *, 0x18C);
        this->unk110.unk48 = M2C_FIELD(temp_r5_2137, f32 *, 0x190);
        this->unk110.unk4C = M2C_FIELD(temp_r5_2137, s32 *, 0x194);
        this->unk110.unk50 = M2C_FIELD(temp_r5_2137, void **, 0x198);
        this->unk110.unk54 = M2C_FIELD(temp_r5_2137, s32 *, 0x19C);
        this->unk110.unk58 = M2C_FIELD(temp_r5_2137, u8 *, 0x1A0);
        temp_r4_2169 = M2C_FIELD(this->unkB04, u8 *, 0x1A0);
        this->unk110.unk16C = temp_r4_2169 != 0;
        UpdateCollisionItems(temp_r4_2169, temp_r5_2137, temp_f1_2146);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Ball *' to
s32 CynderTier1::TryFreezeBall() {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 temp_r3_2203;
    s32 temp_r3_2210;

    this->unkB04 = checked_cast<Ball *, MKProp>(((MKPropDescriptor *) (M2C_FIELD(this, MKPropDescriptor **, 0xB18)))->CreateInstance());
    temp_r3_2203 = this->unkB04;
    if ((u32) temp_r3_2203 != 0U) {
        M2C_FIELD(M2C_FIELD(temp_r3_2203, void **, 0x44), M2C_UNK (**)(), 0x30)();
        temp_r3_2210 = this->unkB04;
        M2C_FIELD(M2C_FIELD(temp_r3_2210, void **, 0x44), M2C_UNK (**)(s32), 0x20)(temp_r3_2210);
        M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
        sp18 = 0.0f;
        sp10 = 0.0f;
        sp14 = 175.0f;
        sp28 = (f64) sp18;
        sp20 = (f64) sp10;
        sp30.Translate(&sp30, *((MKVector3 *) &sp20));
        this->unkB04->SetWorldMatrix(&sp30);
        M2C_FIELD(this->unkB04, f32 *, 0x280) = 1.75f;
        M2C_FIELD(this->unkB04, CynderTier1 **, 0x230) = this;
        this->unkB04->FindClosestGroup();
        M2C_FIELD(GetCollisionInfo(), s8 *, 4) = 0;
        SetMovementType((CharacterMoveType) 2);
        SetAnim((AnimSequenceType) 2, 0x28, 0, 0.15f, 0U, 0U);
        SetInvulnerableToMeleeAttacks(1U, 0U);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp3E0'
void CynderTier1::CheckAnimEvents() {
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f32 sp440;
    f64 sp430;                                      /* compiler-managed */
    f64 sp428;                                      /* compiler-managed */
    f64 sp420;
    f64 sp418;
    f32 sp414;
    f32 sp410;
    f32 sp40C;
    f32 sp408;
    M2C_UNK sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    MKVector3 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    M2C_UNK sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    MKVector3 sp2B8;
    M2C_UNK sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
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
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKPropDescriptor *temp_r22_2655;
    f32 temp_f15_2803;
    f32 temp_f15_2817;
    f32 temp_f16_2931;
    f32 temp_f17_3003;
    f32 temp_f1_2732;
    f32 temp_f1_2903;
    f32 var_f17_2761;
    f64 temp_f0_2970;
    f64 temp_f0_3045;
    s32 temp_r3_2347;
    s32 temp_r3_2778;
    s32 var_r21_2656;
    s32 var_r21_2710;
    s32 var_r21_2760;
    s32 var_r21_2881;
    s32 var_r21_2934;
    s32 var_r21_3006;
    s32 var_r21_3078;
    s32 var_r21_3118;
    s32 var_r21_3159;
    s32 var_r22_2786;
    s32 var_r23_2375;
    s32 var_r23_2430;
    s32 var_r23_2468;
    s32 var_r23_2517;
    s32 var_r23_2557;
    s32 var_r25_2657;
    u32 *temp_r0_2335;
    u32 *var_r27_2341;
    void *temp_r22_2589;
    void *temp_r24_2663;
    void *temp_r24_3031;
    void *temp_r3_2584;

    Enemy::CheckAnimEvents();
    if (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(0x10) != 0) {
        temp_r0_2335 = M2C_FIELD(this->unkA20, u32 **, 0x27C);
        if (temp_r0_2335 != NULL) {
            var_r27_2341 = temp_r0_2335;
loop_50:
            if ((u32) *var_r27_2341 != -1U) {
                temp_r3_2347 = this->unkAE0;
                switch (temp_r3_2347) {             /* irregular */
                case 0x8000000:
                    KDSound_Play3d(GS_DDFireSpawn, (MKVector3 *) &this->unk588, 0U, -1, 0.0f, 0U);
                    var_r23_2375 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp108 = sp3D8 * 5.61841903e-315;
                        sp3E8 = sp108;
                        sp110 = sp3E0 * 400.0f;
                        sp428 = sp108;
                        sp3F0 = (f64) sp110;
                        sp430 = (f64) sp110;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
                        sp34 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
                        gb.unk68->Emit(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp34);
                        sp408 = 1.0f;
                        sp40C = 0.75f;
                        sp410 = 0.75f;
                        sp414 = 1.0f;
                        sp30 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
                        gb.unk74->Emit(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp30, *((MKVector4 *) &sp408), 0.0f);
                        var_r23_2375 += 1;
                    } while (var_r23_2375 < 0x1E);
                    var_r23_2430 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        spF8 = sp3B8 * 5.61841903e-315;
                        sp3C8 = spF8;
                        sp100 = sp3C0 * 400.0f;
                        sp428 = spF8;
                        sp3D0 = (f64) sp100;
                        sp430 = (f64) sp100;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
                        gb.unk240.Emit(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), MKRand_Float(&gViewSeed, 2.0f, 5.0f), 1.0f);
                        var_r23_2430 += 1;
                    } while (var_r23_2430 < 0xF);
                    var_r23_2468 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        spE8 = sp398 * 5.61841903e-315;
                        sp3A8 = spE8;
                        spF0 = sp3A0 * 400.0f;
                        sp428 = spE8;
                        sp3B0 = (f64) spF0;
                        sp430 = (f64) spF0;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 1.0f, 8.0f);
                        sp2C = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
                        gb.EmitDust(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp2C, 0.0f);
                        var_r23_2468 += 1;
                    } while (var_r23_2468 < 5);
                    break;
                case 0x10000000:
                    KDSound_Play3d(GS_DDIceSpawn, (MKVector3 *) &this->unk588, 0U, -1, 0.0f, 0U);
                    var_r23_2517 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        spD8 = sp378 * 5.60222949e-315;
                        sp388 = spD8;
                        spE0 = sp380 * 300.0f;
                        sp428 = spD8;
                        sp390 = (f64) spE0;
                        sp430 = (f64) spE0;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 20.0f, 27.0f);
                        sp28 = MKRand_Float(&gViewSeed, 2.0f, 5.0f);
                        ((IceBitsPS *) (M2C_FIELD(checked_cast<CynderTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), IceBitsPS **, 0x260)))->Emit(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp28);
                        var_r23_2517 += 1;
                    } while (var_r23_2517 < 0x14);
                    var_r23_2557 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        spC8 = sp358 * 5.49408334e-315;
                        sp368 = spC8;
                        spD0 = sp360 * 50.0f;
                        sp428 = spC8;
                        sp370 = (f64) spD0;
                        sp430 = (f64) spD0;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 10.0f, 15.0f);
                        temp_r3_2584 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
                        if (temp_r3_2584 != NULL) {
                            temp_r22_2589 = M2C_FIELD(temp_r3_2584, void **, 0x2C);
                            MKVector(1.0f, 2.0f, 1.0f);
                            MKVector(-1.0f, 0.0f, -1.0f);
                            KDRand_Vector(sp328, sp318);
                            sp338.operator*(50.0f);
                            spB8 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp338);
                            M2C_FIELD(temp_r3_2584, f64 *, 0) = spB8;
                            spC0 = this->unk588.unk4 + sp338.unk8;
                            sp348 = spB8;
                            M2C_FIELD(temp_r3_2584, f64 *, 8) = (f64) spC0;
                            M2C_FIELD(temp_r3_2584, f32 *, 0x20) = 0.0f;
                            M2C_FIELD(temp_r3_2584, f32 *, 0x28) = 0.0f;
                            sp350 = (f64) spC0;
                            M2C_FIELD(temp_r22_2589, f64 *, 0) = sp428;
                            M2C_FIELD(temp_r22_2589, f64 *, 8) = sp430;
                            M2C_FIELD(temp_r22_2589, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.5f, 1.5f);
                            M2C_FIELD(temp_r22_2589, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                            M2C_FIELD(temp_r22_2589, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
                        }
                        var_r23_2557 += 1;
                    } while (var_r23_2557 < 5);
                    temp_r22_2655 = checked_cast<ShatterableDescriptor *, MKPropDescriptor>(gMK->FindDescriptor("IceCube"));
                    var_r21_2656 = 0;
                    var_r25_2657 = 0;
                    do {
                        *(&sp3F8 + var_r25_2657) = checked_cast<PooledShatterProp *, MKProp>(temp_r22_2655->CreateInstance());
                        temp_r24_2663 = *(&sp3F8 + var_r25_2657);
                        if (temp_r24_2663 != NULL) {
                            M2C_FIELD(M2C_FIELD(temp_r24_2663, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x38)(temp_r24_2663, &this->unk588);
                            M2C_FIELD(M2C_FIELD(temp_r24_2663, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r24_2663);
                            M2C_FIELD(M2C_FIELD(temp_r24_2663, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r24_2663);
                            M2C_FIELD(M2C_FIELD(temp_r24_2663, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r24_2663, 0, 0, -1, 0, 1, 0);
                        }
                        var_r21_2656 += 1;
                        var_r25_2657 += 4;
                    } while (var_r21_2656 < 3);
                    break;
                case 0x20000000:
                    KDSound_Play3d(GS_DDElecSpawn, (MKVector3 *) &this->unk588, 0U, -1, 0.0f, 0U);
                    var_r21_2710 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        spA8 = sp2E8 * 5.65986426e-315;
                        sp2F8 = spA8;
                        spB0 = sp2F0 * 800.0f;
                        sp428 = spA8;
                        sp300 = (f64) spB0;
                        sp430 = (f64) spB0;
                        temp_f1_2732 = MKRand_Float(&gViewSeed, 8.0f, 12.0f);
                        sp178 = 1.0f;
                        sp17C = 0.0f;
                        sp180 = 0.2f;
                        sp184 = 1.0f;
                        unksp42C = 100.0f * temp_f1_2732;
                        sp2D8 = (f64) sp178;
                        sp2E0 = (f64) sp180;
                        sp24 = MKRand_Float(&gViewSeed, 5.0f, 10.0f);
                        ((ZapPS *) (M2C_FIELD(checked_cast<CynderTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B4)))->Emit(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp24, (MKVector4) &sp2D8);
                        var_r21_2710 += 1;
                    } while (var_r21_2710 < 0xF);
                    var_r21_2760 = 0;
                    var_f17_2761 = 0.0f;
                    sp468 = 5.287201034e-315;
                    sp470 = 5.263544247e-315;
                    sp478 = 5.164075695e-315;
                    sp448 = 5.465589745e-315;
                    sp450 = 5.370091495e-315;
                    do {
                        temp_r3_2778 = MKRand_Int(&gViewSeed, 4, 8);
                        var_f17_2761 += (f32) sp448;
                        var_r22_2786 = 0;
                        sp440 = (f32) sp450 / (f32) (temp_r3_2778 - 1);
loop_34:
                        if (var_r22_2786 < temp_r3_2778) {
                            temp_f15_2803 = (f32) var_r22_2786 * sp440;
                            sp458 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                            sp460 = MKRand_Float(&gViewSeed, 0.8f, 1.0f);
                            temp_f15_2817 = -_table_sinf((f32) sp468 + temp_f15_2803) * (f32) sp458;
                            MKVector(_table_sinf(temp_f15_2803) * (f32) sp460, 0.0f, temp_f15_2817);
                            sp2B8.operator*(var_f17_2761);
                            sp98 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp2B8);
                            sp16C = 0.0f;
                            sp168 = (f32) sp470;
                            spA0 = this->unk588.unk4 + sp2B8.unk8;
                            sp170 = (f32) sp478;
                            sp174 = (f32) sp470;
                            sp2C8 = sp98;
                            sp2D0 = (f64) spA0;
                            sp418 = sp98;
                            sp420 = (f64) spA0;
                            sp428 = 0.0f;
                            unksp42C = 0.0f;
                            sp430 = 0.0f;
                            sp298 = (f64) sp168;
                            sp2A0 = (f64) sp170;
                            sp20 = MKRand_Float(&gViewSeed, 10.0f, 15.0f);
                            ((ZapPS *) (M2C_FIELD(checked_cast<CynderTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B4)))->Emit(*((MKVector3 *) &sp418), *((MKVector3 *) &sp428), sp20, (MKVector4) &sp298);
                            var_r22_2786 += 1;
                            goto loop_34;
                        }
                        var_r21_2760 += 1;
                    } while (var_r21_2760 < 5);
                    var_r21_2881 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp88 = sp278 * 5.65986426e-315;
                        sp288 = sp88;
                        sp90 = sp280 * 800.0f;
                        sp428 = sp88;
                        sp290 = (f64) sp90;
                        sp430 = (f64) sp90;
                        temp_f1_2903 = MKRand_Float(&gViewSeed, 8.0f, 12.0f);
                        sp158 = 1.0f;
                        sp15C = 0.0f;
                        sp160 = 0.2f;
                        sp164 = 1.0f;
                        unksp42C = 100.0f * temp_f1_2903;
                        sp268 = (f64) sp158;
                        sp270 = (f64) sp160;
                        sp1C = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
                        gb.unk94->Trigger(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp1C, lit_895, (MKVector4) &sp268);
                        var_r21_2881 += 1;
                    } while (var_r21_2881 < 3);
                    temp_f16_2931 = MKVector3::up.unk8;
                    var_r21_2934 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp78 = sp248 * 5.61841903e-315;
                        sp258 = sp78;
                        sp80 = sp250 * 400.0f;
                        sp428 = sp78;
                        sp260 = (f64) sp80;
                        sp430 = (f64) sp80;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 12.0f, 16.0f);
                        sp148 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.51933903e-315;
                        sp150 = temp_f16_2931 * 75.0f;
                        sp228 = sp148;
                        sp230 = (f64) sp150;
                        temp_f0_2970 = M2C_FIELD(this, f64 *, 0x588) - sp228;
                        sp138 = temp_f0_2970;
                        sp238 = temp_f0_2970;
                        sp140 = this->unk588.unk4 - (f32) sp230;
                        sp240 = (f64) sp140;
                        gb.unk230->Emit(*((MKVector3 *) &sp238), *((MKVector3 *) &sp428), MKRand_Float(&gViewSeed, 5.0f, 10.0f), 1U);
                        var_r21_2934 += 1;
                    } while (var_r21_2934 < 0xF);
                    break;
                case 0x40000000:
                    KDSound_Play3d(GS_DDEarthSpawn, (MKVector3 *) &this->unk588, 0U, -1, 0.0f, 0U);
                    temp_f17_3003 = MKVector3::up.unk8;
                    var_r21_3006 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp68 = sp208 * 5.49408334e-315;
                        sp218 = sp68;
                        sp70 = sp210 * 50.0f;
                        sp428 = sp68;
                        sp220 = (f64) sp70;
                        sp430 = (f64) sp70;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 2.0f, 4.0f);
                        temp_r24_3031 = checked_cast<CynderTier1Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                        sp128 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.49408334e-315;
                        sp130 = temp_f17_3003 * 50.0f;
                        sp1E8 = sp128;
                        sp1F0 = (f64) sp130;
                        temp_f0_3045 = M2C_FIELD(this, f64 *, 0x588) + sp1E8;
                        sp118 = temp_f0_3045;
                        sp1F8 = temp_f0_3045;
                        sp120 = this->unk588.unk4 + (f32) sp1F0;
                        sp200 = (f64) sp120;
                        sp18 = MKRand_Float(&gViewSeed, 1.0f, 1.5f);
                        sp14 = MKRand_Int(&gViewSeed, 0, 3);
                        ((FallingLeaves *) (M2C_FIELD(temp_r24_3031, FallingLeaves **, 0x2B8)))->Emit(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp428), sp18, sp14, 1U);
                        var_r21_3006 += 1;
                    } while (var_r21_3006 < 0xF);
                    var_r21_3078 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp58 = sp1C8 * 5.60222949e-315;
                        sp1D8 = sp58;
                        sp60 = sp1D0 * 300.0f;
                        sp428 = sp58;
                        sp1E0 = (f64) sp60;
                        sp430 = (f64) sp60;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 8.0f, 12.0f);
                        sp10 = MKRand_Float(&gViewSeed, 0.1f, 0.5f);
                        gb.EmitSmallRocks(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp10);
                        var_r21_3078 += 1;
                    } while (var_r21_3078 < 0x1E);
                    var_r21_3118 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp48 = sp1A8 * 5.61841903e-315;
                        sp1B8 = sp48;
                        sp50 = sp1B0 * 400.0f;
                        sp428 = sp48;
                        sp1C0 = (f64) sp50;
                        sp430 = (f64) sp50;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 1.0f, 8.0f);
                        spC = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
                        gb.EmitDust(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), spC, 0.0f);
                        var_r21_3118 += 1;
                    } while (var_r21_3118 < 5);
                    var_r21_3159 = 0;
                    do {
                        KDRand_UnitVectorXZ();
                        sp38 = sp188 * 5.60222949e-315;
                        sp198 = sp38;
                        sp40 = sp190 * 300.0f;
                        sp428 = sp38;
                        sp1A0 = (f64) sp40;
                        sp430 = (f64) sp40;
                        unksp42C = 100.0f * MKRand_Float(&gViewSeed, 2.0f, 4.0f);
                        sp8 = MKRand_Float(&gViewSeed, 0.5f, 1.0f);
                        gb.EmitCrud(*((MKVector3 *) &this->unk588), *((MKVector3 *) &sp428), sp8);
                        var_r21_3159 += 1;
                    } while (var_r21_3159 < 5);
                    break;
                }
                var_r27_2341 += 4;
                goto loop_50;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'SetSpawnGoal__15EnemyGoal_ThinkFP12Goal'
s32 CynderTier1::Spawn(SpawnPointObject *arg0) {
    if (M2C_FIELD(arg0->unk4, s32 *, 4) & 0x200) {
        SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>((EnemyGoal_Think *) this->unkA24, (Goal<Enemy> *) this->unkAFC);
    }
    Enemy::Spawn(arg0);
}
#endif

#if 0 // DRAFT: undefined identifier 'SetSpawnGoal__15EnemyGoal_ThinkFP12Goal'
void CynderTier1::Spawn(EnemyGeneratorDoor *arg0) {
    M2C_FIELD(this->unkAF8, EnemyGeneratorDoor **, 0x10) = arg0;
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>((EnemyGoal_Think *) this->unkA24, (Goal<Enemy> *) this->unkAF8);
    Enemy::Spawn(arg0->unk18);
}
#endif

void CynderTier1::Update() {
    Enemy::Update();
    TestForSpikes();
}

#if 0 // DRAFT: function call 'checked_cast(unsigned long)' does not match
void CynderTier1::Resolve() {
    Enemy::Resolve();
    M2C_FIELD(this, s32 *, 0xB18) = checked_cast<BallDescriptor *, MKPropDescriptor>(gMK->FindDescriptor("CynderTier1Ball"));
}
#endif

#if 0 // DRAFT: undefined identifier 'cynderTier1NodeBlurDef'
void CynderTier1::LoadDone() {
    Enemy::LoadDone();
    M2C_FIELD(this, BoneBlurFX **, 0xA10) = checked_cast<BoneBlurFX *, MKProp>(gMK->CreateProp("BoneBlurFX"));
    ((BoneBlurFX *) (M2C_FIELD(this, BoneBlurFX **, 0xA10)))->InitData(M2C_FIELD(M2C_FIELD(this, void **, 0x630), MKModel **, 8), &cynderTier1NodeBlurDef, 0x13, cynderTier1NodeBlurChains, 5, 5, 1U);
}
#endif

#if 0 // DRAFT: pointer/array required
void CynderTier1::Deinit() {
    s32 temp_r3_3385;
    s32 temp_r3_3395;

    temp_r3_3385 = this->unkAF8;
    if ((u32) temp_r3_3385 != 0U) {
        M2C_FIELD(*temp_r3_3385, M2C_UNK (**)(), 0xC)();
        operator delete((void *) this->unkAF8);
    }
    temp_r3_3395 = this->unkAFC;
    if ((u32) temp_r3_3395 != 0U) {
        M2C_FIELD(*temp_r3_3395, M2C_UNK (**)(), 0xC)();
        operator delete((void *) this->unkAFC);
    }
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void CynderTier1::Init() {
    EnemyGoal_Think *temp_r30_3427;
    s32 temp_r4_3475;
    s32 temp_r4_3508;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r30_3427 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r30_3427 != NULL) {
        temp_r30_3427->__vptr = &__vt__12Goal<5Enemy>;
        temp_r30_3427->unk4 = 0;
        temp_r30_3427->unk8 = 1;
        temp_r30_3427->unk9 = 0;
        temp_r30_3427->unkC = 0;
        temp_r30_3427->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r30_3427->unk1C = 0;
        temp_r30_3427->unk18 = 0;
        temp_r30_3427->unk10 = 0;
        temp_r30_3427->unk14 = 0;
        temp_r30_3427->__vptr = &__vt;
    }
    temp_r30_3427->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r30_3427;
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r4_3475 = this->unkAF8;
    M2C_FIELD(temp_r4_3475, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3475, CynderTier1 **, 0xC) = this;
    M2C_FIELD(temp_r4_3475, s32 *, 4) = 0x38;
    if ((CynderTier1 *) M2C_FIELD(temp_r4_3475, CynderTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3475, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_3475, s32 *, 0x10) = 0;
    operator new(0x14U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAFC = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r4_3508 = this->unkAFC;
    M2C_FIELD(temp_r4_3508, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3508, CynderTier1 **, 0xC) = this;
    M2C_FIELD(temp_r4_3508, s32 *, 4) = 0x38;
    if ((CynderTier1 *) M2C_FIELD(temp_r4_3508, CynderTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3508, s8 *, 9) = 1;
    }
    this->unkB04 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void CynderTier1Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void CynderTier1Descriptor::LoadDone() {
    s32 var_r29_3561;
    void *temp_r3_3568;

    EnemyDescriptor::LoadDone();
    this->unk244.Init(&cynderTier1BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
    var_r29_3561 = 0;
    do {
        temp_r3_3568 = checked_cast<Ball *, MKProp>(gMK->CreateProp("CynderTier1Ball"));
        M2C_FIELD(temp_r3_3568, u8 *, 0x2AC) = (u8) (M2C_FIELD(temp_r3_3568, u8 *, 0x2AC) | 8);
        M2C_FIELD(M2C_FIELD(temp_r3_3568, void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_3561 += 1;
    } while (var_r29_3561 < 3);
    this->unk2B4 = checked_cast<ZapPS *, MKProp>(gMK->CreateProp("ZapPS"));
    this->unk2B8 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
}
#endif

#if 0 // DRAFT: undefined identifier 'cynderTier1BodyFXInit'
void Enemies_Cynder_cpp::__sinit() {
    f32 sp540;
    f32 sp53C;
    f32 sp538;
    f32 sp530;
    f32 sp52C;
    f32 sp528;
    f32 sp520;
    f32 sp51C;
    f32 sp518;
    f32 sp510;
    f32 sp50C;
    f32 sp508;
    f32 sp500;
    f32 sp4FC;
    f32 sp4F8;
    f32 sp4F0;
    f32 sp4EC;
    f32 sp4E8;
    f32 sp4E0;
    f32 sp4DC;
    f32 sp4D8;
    f32 sp4D0;
    f32 sp4CC;
    f32 sp4C8;
    f32 sp4C0;
    f32 sp4BC;
    f32 sp4B8;
    f32 sp4B0;
    f32 sp4AC;
    f32 sp4A8;
    f32 sp4A0;
    f32 sp49C;
    f32 sp498;
    f32 sp490;
    f32 sp48C;
    f32 sp488;
    f32 sp480;
    f32 sp47C;
    f32 sp478;
    f32 sp470;
    f32 sp46C;
    f32 sp468;
    f32 sp460;
    f32 sp45C;
    f32 sp458;
    f32 sp450;
    f32 sp44C;
    f32 sp448;
    f32 sp440;
    f32 sp43C;
    f32 sp438;
    f32 sp430;
    f32 sp42C;
    f32 sp428;
    f32 sp420;
    f32 sp41C;
    f32 sp418;
    f32 sp410;
    f32 sp40C;
    f32 sp408;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    f32 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f32 sp3E0;
    f32 sp3DC;
    f32 sp3D8;
    f32 sp3D0;
    f32 sp3CC;
    f32 sp3C8;
    f32 sp3C0;
    f32 sp3BC;
    f32 sp3B8;
    f32 sp3B0;
    f32 sp3AC;
    f32 sp3A8;
    f32 sp3A0;
    f32 sp39C;
    f32 sp398;
    f32 sp390;
    f32 sp38C;
    f32 sp388;
    f32 sp380;
    f32 sp37C;
    f32 sp378;
    f32 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f32 sp330;
    f32 sp32C;
    f32 sp328;
    f32 sp320;
    f32 sp31C;
    f32 sp318;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
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
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
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
    void *temp_r3_4167;
    void *temp_r4_3971;

    sp540 = 1.0f;
    sp530 = 0.0f;
    sp520 = 1.0f;
    sp510 = 0.0f;
    sp500 = 2.0f;
    sp4F0 = 0.0f;
    sp4E0 = 1.0f;
    sp4D0 = 0.0f;
    sp4C0 = 1.0f;
    sp538 = 1.0f;
    sp53C = 1.0f;
    sp528 = 0.0f;
    sp52C = 0.0f;
    sp518 = 1.0f;
    sp51C = 1.0f;
    sp508 = 0.0f;
    sp50C = 0.0f;
    sp4F8 = 2.0f;
    sp4FC = 2.0f;
    sp4E8 = 0.0f;
    sp4EC = 0.0f;
    sp4D8 = 1.0f;
    sp4DC = 1.0f;
    sp4C8 = 0.0f;
    sp4CC = 0.0f;
    sp4B8 = 1.0f;
    sp4BC = 1.0f;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x10) = (f64) sp538;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x18) = (f64) sp540;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x20) = (f64) sp528;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x28) = (f64) sp530;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x40) = (f64) sp518;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x48) = (f64) sp520;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x50) = (f64) sp508;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x58) = (f64) sp510;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x70) = (f64) sp4F8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x78) = (f64) sp500;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x80) = (f64) sp4E8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x88) = (f64) sp4F0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xA0) = (f64) sp4D8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xA8) = (f64) sp4E0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xB0) = (f64) sp4C8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xB8) = (f64) sp4D0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xD0) = (f64) sp4B8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xD8) = (f64) sp4C0;
    sp4B0 = 0.0f;
    sp4A0 = 1.0f;
    sp490 = 0.0f;
    sp480 = 1.0f;
    sp470 = 0.0f;
    sp460 = 1.0f;
    sp450 = 0.0f;
    sp440 = 1.5f;
    sp430 = 0.0f;
    sp4A8 = 0.0f;
    sp4AC = 0.0f;
    sp498 = 1.0f;
    sp49C = 1.0f;
    sp488 = 0.0f;
    sp48C = 0.0f;
    sp478 = 1.0f;
    sp47C = 1.0f;
    sp468 = 0.0f;
    sp46C = 0.0f;
    sp458 = 1.0f;
    sp45C = 1.0f;
    sp448 = 0.0f;
    sp44C = 0.0f;
    sp438 = 1.5f;
    sp43C = 1.5f;
    sp428 = 0.0f;
    sp42C = 0.0f;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xE0) = (f64) sp4A8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0xE8) = (f64) sp4B0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x100) = (f64) sp498;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x108) = (f64) sp4A0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x110) = (f64) sp488;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x118) = (f64) sp490;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x130) = (f64) sp478;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x138) = (f64) sp480;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x140) = (f64) sp468;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x148) = (f64) sp470;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x160) = (f64) sp458;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x168) = (f64) sp460;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x170) = (f64) sp448;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x178) = (f64) sp450;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x190) = (f64) sp438;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x198) = (f64) sp440;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1A0) = (f64) sp428;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1A8) = (f64) sp430;
    sp418 = 1.5f;
    sp41C = 1.5f;
    sp420 = 1.5f;
    sp410 = 0.0f;
    sp400 = 2.0f;
    sp3F0 = 0.0f;
    sp3E0 = 2.0f;
    sp3D0 = 0.0f;
    sp3C0 = 1.0f;
    sp3B0 = 0.0f;
    sp3A0 = 1.0f;
    sp408 = 0.0f;
    sp40C = 0.0f;
    sp3F8 = 2.0f;
    sp3FC = 2.0f;
    sp3E8 = 0.0f;
    sp3EC = 0.0f;
    sp3D8 = 2.0f;
    sp3DC = 2.0f;
    sp3C8 = 0.0f;
    sp3CC = 0.0f;
    sp3B8 = 1.0f;
    sp3BC = 1.0f;
    sp3A8 = 0.0f;
    sp3AC = 0.0f;
    sp398 = 1.0f;
    sp39C = 1.0f;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1C0) = (f64) sp418;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1C8) = (f64) sp420;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1D0) = (f64) sp408;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1D8) = (f64) sp410;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1F0) = (f64) sp3F8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x1F8) = (f64) sp400;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x200) = (f64) sp3E8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x208) = (f64) sp3F0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x220) = (f64) sp3D8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x228) = (f64) sp3E0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x230) = (f64) sp3C8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x238) = (f64) sp3D0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x250) = (f64) sp3B8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x258) = (f64) sp3C0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x260) = (f64) sp3A8;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x268) = (f64) sp3B0;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x280) = (f64) sp398;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x288) = (f64) sp3A0;
    sp388 = 0.0f;
    sp38C = 0.0f;
    sp390 = 0.0f;
    temp_r4_3971 = &cynderTier1BodyFXInit + 0x2A0;
    sp380 = 1.0f;
    sp370 = 0.0f;
    sp360 = 1.0f;
    sp350 = 0.0f;
    sp340 = 2.0f;
    sp330 = 0.0f;
    sp320 = 1.0f;
    sp310 = 0.0f;
    sp378 = 1.0f;
    sp37C = 1.0f;
    sp368 = 0.0f;
    sp36C = 0.0f;
    sp358 = 1.0f;
    sp35C = 1.0f;
    sp348 = 0.0f;
    sp34C = 0.0f;
    sp338 = 2.0f;
    sp33C = 2.0f;
    sp328 = 0.0f;
    sp32C = 0.0f;
    sp318 = 1.0f;
    sp31C = 1.0f;
    sp308 = 0.0f;
    sp30C = 0.0f;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x290) = (f64) sp388;
    M2C_FIELD(&cynderTier1BodyFXInit, f64 *, 0x298) = (f64) sp390;
    M2C_FIELD(temp_r4_3971, f64 *, 0x10) = (f64) sp378;
    M2C_FIELD(temp_r4_3971, f64 *, 0x18) = (f64) sp380;
    M2C_FIELD(temp_r4_3971, f64 *, 0x20) = (f64) sp368;
    M2C_FIELD(temp_r4_3971, f64 *, 0x28) = (f64) sp370;
    M2C_FIELD(temp_r4_3971, f64 *, 0x40) = (f64) sp358;
    M2C_FIELD(temp_r4_3971, f64 *, 0x48) = (f64) sp360;
    M2C_FIELD(temp_r4_3971, f64 *, 0x50) = (f64) sp348;
    M2C_FIELD(temp_r4_3971, f64 *, 0x58) = (f64) sp350;
    M2C_FIELD(temp_r4_3971, f64 *, 0x70) = (f64) sp338;
    M2C_FIELD(temp_r4_3971, f64 *, 0x78) = (f64) sp340;
    M2C_FIELD(temp_r4_3971, f64 *, 0x80) = (f64) sp328;
    M2C_FIELD(temp_r4_3971, f64 *, 0x88) = (f64) sp330;
    M2C_FIELD(temp_r4_3971, f64 *, 0xA0) = (f64) sp318;
    M2C_FIELD(temp_r4_3971, f64 *, 0xA8) = (f64) sp320;
    M2C_FIELD(temp_r4_3971, f64 *, 0xB0) = (f64) sp308;
    M2C_FIELD(temp_r4_3971, f64 *, 0xB8) = (f64) sp310;
    sp2F8 = 1.0f;
    sp2FC = 1.0f;
    sp300 = 1.0f;
    sp2F0 = 0.0f;
    sp2E0 = 1.0f;
    sp2D0 = 0.0f;
    sp2C0 = 1.0f;
    sp2B0 = 0.0f;
    sp2A0 = 1.0f;
    sp290 = 0.0f;
    sp280 = 1.5f;
    sp270 = 0.0f;
    sp2E8 = 0.0f;
    sp2EC = 0.0f;
    sp2D8 = 1.0f;
    sp2DC = 1.0f;
    sp2C8 = 0.0f;
    sp2CC = 0.0f;
    sp2B8 = 1.0f;
    sp2BC = 1.0f;
    sp2A8 = 0.0f;
    sp2AC = 0.0f;
    sp298 = 1.0f;
    sp29C = 1.0f;
    sp288 = 0.0f;
    sp28C = 0.0f;
    sp278 = 1.5f;
    sp27C = 1.5f;
    sp268 = 0.0f;
    sp26C = 0.0f;
    M2C_FIELD(temp_r4_3971, f64 *, 0xD0) = (f64) sp2F8;
    M2C_FIELD(temp_r4_3971, f64 *, 0xD8) = (f64) sp300;
    M2C_FIELD(temp_r4_3971, f64 *, 0xE0) = (f64) sp2E8;
    M2C_FIELD(temp_r4_3971, f64 *, 0xE8) = (f64) sp2F0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x100) = (f64) sp2D8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x108) = (f64) sp2E0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x110) = (f64) sp2C8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x118) = (f64) sp2D0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x130) = (f64) sp2B8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x138) = (f64) sp2C0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x140) = (f64) sp2A8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x148) = (f64) sp2B0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x160) = (f64) sp298;
    M2C_FIELD(temp_r4_3971, f64 *, 0x168) = (f64) sp2A0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x170) = (f64) sp288;
    M2C_FIELD(temp_r4_3971, f64 *, 0x178) = (f64) sp290;
    M2C_FIELD(temp_r4_3971, f64 *, 0x190) = (f64) sp278;
    M2C_FIELD(temp_r4_3971, f64 *, 0x198) = (f64) sp280;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1A0) = (f64) sp268;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1A8) = (f64) sp270;
    sp260 = 1.5f;
    sp250 = 0.0f;
    sp240 = 2.0f;
    sp230 = 0.0f;
    sp220 = 2.0f;
    sp210 = 0.0f;
    sp200 = 1.0f;
    sp1F0 = 0.0f;
    sp1E0 = 1.0f;
    sp258 = 1.5f;
    sp25C = 1.5f;
    sp248 = 0.0f;
    sp24C = 0.0f;
    sp238 = 2.0f;
    sp23C = 2.0f;
    sp228 = 0.0f;
    sp22C = 0.0f;
    sp218 = 2.0f;
    sp21C = 2.0f;
    sp208 = 0.0f;
    sp20C = 0.0f;
    sp1F8 = 1.0f;
    sp1FC = 1.0f;
    sp1E8 = 0.0f;
    sp1EC = 0.0f;
    sp1D8 = 1.0f;
    sp1DC = 1.0f;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1C0) = (f64) sp258;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1C8) = (f64) sp260;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1D0) = (f64) sp248;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1D8) = (f64) sp250;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1F0) = (f64) sp238;
    M2C_FIELD(temp_r4_3971, f64 *, 0x1F8) = (f64) sp240;
    M2C_FIELD(temp_r4_3971, f64 *, 0x200) = (f64) sp228;
    M2C_FIELD(temp_r4_3971, f64 *, 0x208) = (f64) sp230;
    M2C_FIELD(temp_r4_3971, f64 *, 0x220) = (f64) sp218;
    M2C_FIELD(temp_r4_3971, f64 *, 0x228) = (f64) sp220;
    M2C_FIELD(temp_r4_3971, f64 *, 0x230) = (f64) sp208;
    M2C_FIELD(temp_r4_3971, f64 *, 0x238) = (f64) sp210;
    M2C_FIELD(temp_r4_3971, f64 *, 0x250) = (f64) sp1F8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x258) = (f64) sp200;
    M2C_FIELD(temp_r4_3971, f64 *, 0x260) = (f64) sp1E8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x268) = (f64) sp1F0;
    M2C_FIELD(temp_r4_3971, f64 *, 0x280) = (f64) sp1D8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x288) = (f64) sp1E0;
    sp1C8 = 0.0f;
    temp_r3_4167 = &cynderTier1BodyFXInit + 0x540;
    sp1CC = 0.0f;
    sp1D0 = 0.0f;
    sp1C0 = 2.0f;
    sp1B0 = 0.0f;
    sp1A0 = 2.0f;
    sp190 = 0.0f;
    sp180 = 3.0f;
    sp170 = 0.0f;
    sp160 = 3.0f;
    sp150 = 0.0f;
    sp1B8 = 2.0f;
    sp1BC = 2.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 2.0f;
    sp19C = 2.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp178 = 3.0f;
    sp17C = 3.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp158 = 3.0f;
    sp15C = 3.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    M2C_FIELD(temp_r4_3971, f64 *, 0x290) = (f64) sp1C8;
    M2C_FIELD(temp_r4_3971, f64 *, 0x298) = (f64) sp1D0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x10) = (f64) sp1B8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x18) = (f64) sp1C0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x20) = (f64) sp1A8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x28) = (f64) sp1B0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x40) = (f64) sp198;
    M2C_FIELD(temp_r3_4167, f64 *, 0x48) = (f64) sp1A0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x50) = (f64) sp188;
    M2C_FIELD(temp_r3_4167, f64 *, 0x58) = (f64) sp190;
    M2C_FIELD(temp_r3_4167, f64 *, 0x70) = (f64) sp178;
    M2C_FIELD(temp_r3_4167, f64 *, 0x78) = (f64) sp180;
    M2C_FIELD(temp_r3_4167, f64 *, 0x80) = (f64) sp168;
    M2C_FIELD(temp_r3_4167, f64 *, 0x88) = (f64) sp170;
    M2C_FIELD(temp_r3_4167, f64 *, 0xA0) = (f64) sp158;
    M2C_FIELD(temp_r3_4167, f64 *, 0xA8) = (f64) sp160;
    M2C_FIELD(temp_r3_4167, f64 *, 0xB0) = (f64) sp148;
    M2C_FIELD(temp_r3_4167, f64 *, 0xB8) = (f64) sp150;
    sp138 = 3.0f;
    sp13C = 3.0f;
    sp140 = 3.0f;
    sp130 = 0.0f;
    sp120 = 3.0f;
    sp110 = 0.0f;
    sp100 = 1.0f;
    spF0 = 0.0f;
    spE0 = 1.0f;
    spD0 = 0.0f;
    spC0 = 2.5f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 3.0f;
    sp11C = 3.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    spF8 = 1.0f;
    spFC = 1.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spD8 = 1.0f;
    spDC = 1.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spB8 = 2.5f;
    spBC = 2.5f;
    M2C_FIELD(temp_r3_4167, f64 *, 0xD0) = (f64) sp138;
    M2C_FIELD(temp_r3_4167, f64 *, 0xD8) = (f64) sp140;
    M2C_FIELD(temp_r3_4167, f64 *, 0xE0) = (f64) sp128;
    M2C_FIELD(temp_r3_4167, f64 *, 0xE8) = (f64) sp130;
    M2C_FIELD(temp_r3_4167, f64 *, 0x100) = (f64) sp118;
    M2C_FIELD(temp_r3_4167, f64 *, 0x108) = (f64) sp120;
    M2C_FIELD(temp_r3_4167, f64 *, 0x110) = (f64) sp108;
    M2C_FIELD(temp_r3_4167, f64 *, 0x118) = (f64) sp110;
    M2C_FIELD(temp_r3_4167, f64 *, 0x130) = (f64) spF8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x138) = (f64) sp100;
    M2C_FIELD(temp_r3_4167, f64 *, 0x140) = (f64) spE8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x148) = (f64) spF0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x160) = (f64) spD8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x168) = (f64) spE0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x170) = (f64) spC8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x178) = (f64) spD0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x190) = (f64) spB8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x198) = (f64) spC0;
    spA8 = 0.0f;
    spAC = 0.0f;
    spB0 = 0.0f;
    spA0 = 2.5f;
    sp90 = 0.0f;
    sp80 = 4.0f;
    sp70 = 0.0f;
    sp60 = 4.0f;
    sp50 = 0.0f;
    sp40 = 2.0f;
    sp30 = 0.0f;
    sp20 = 2.0f;
    sp10 = 0.0f;
    sp98 = 2.5f;
    sp9C = 2.5f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 4.0f;
    sp7C = 4.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp58 = 4.0f;
    sp5C = 4.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 2.0f;
    sp3C = 2.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 2.0f;
    sp1C = 2.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1A0) = (f64) spA8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1A8) = (f64) spB0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1C0) = (f64) sp98;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1C8) = (f64) spA0;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1D0) = (f64) sp88;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1D8) = (f64) sp90;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1F0) = (f64) sp78;
    M2C_FIELD(temp_r3_4167, f64 *, 0x1F8) = (f64) sp80;
    M2C_FIELD(temp_r3_4167, f64 *, 0x200) = (f64) sp68;
    M2C_FIELD(temp_r3_4167, f64 *, 0x208) = (f64) sp70;
    M2C_FIELD(temp_r3_4167, f64 *, 0x220) = (f64) sp58;
    M2C_FIELD(temp_r3_4167, f64 *, 0x228) = (f64) sp60;
    M2C_FIELD(temp_r3_4167, f64 *, 0x230) = (f64) sp48;
    M2C_FIELD(temp_r3_4167, f64 *, 0x238) = (f64) sp50;
    M2C_FIELD(temp_r3_4167, f64 *, 0x250) = (f64) sp38;
    M2C_FIELD(temp_r3_4167, f64 *, 0x258) = (f64) sp40;
    M2C_FIELD(temp_r3_4167, f64 *, 0x260) = (f64) sp28;
    M2C_FIELD(temp_r3_4167, f64 *, 0x268) = (f64) sp30;
    M2C_FIELD(temp_r3_4167, f64 *, 0x280) = (f64) sp18;
    M2C_FIELD(temp_r3_4167, f64 *, 0x288) = (f64) sp20;
    M2C_FIELD(temp_r3_4167, f64 *, 0x290) = (f64) sp8;
    M2C_FIELD(temp_r3_4167, f64 *, 0x298) = (f64) sp10;
}
#endif

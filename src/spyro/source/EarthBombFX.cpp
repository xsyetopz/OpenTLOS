#include "spyro/source/EarthBombFX.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EarthBreathWhirlWinds.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplosionWarpFX.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_SpyroEarthAttack5LP;
extern s32 GS_SpyroEarthAttackImpact1;
extern s32 GS_SpyroEarthAttackImpact2;
extern s32 GS_SpyroEarthAttackImpact3;
extern s32 GS_SpyroEarthAttackImpact4;
extern void **gMK;
extern s32 gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern void **gb;

static s32 lit_728 = 0;
static u8 lit_729 = 1;

#if 0 // DRAFT: illegal type
void EarthBombFX::Fire(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, const MKVector3 &arg4) {
    s8 spB0;
    s32 spAC;
    MKCollisionInfo *spA8;
    s32 spA4;
    f32 spA0;
    s32 sp9C;
    s8 sp9B;
    s8 sp9A;
    s16 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    Matrix sp20;
    M2C_UNK sp1C;
    u8 sp14;
    void *sp10;
    ManagedLight *temp_r4_97;
    f32 temp_f31_159;
    f64 temp_f1_176;
    s32 temp_r30_111;
    s32 temp_r31_114;
    s32 temp_r4_112;
    s32 var_r26_149;
    s32 var_r6_130;
    u8 var_r4_120;
    u8 var_r4_139;
    void *temp_r3_186;
    void *temp_r5_116;

    M2C_STRUCT_COPY((s32) &sp1C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp20.Scale3x3(&sp20, 2.0f);
    sp20.unk30 = arg0.unk0;
    sp20.unk34 = arg0.unk4;
    sp20.unk38 = arg0.unk8;
    sp20.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk4, sp20);
    this->unkE0 = 1;
    this->unk118 = arg3;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unk120 = arg2;
    this->unkC8 = 10.0f;
    temp_r4_97 = this->unk100;
    if (temp_r4_97 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_97, 1U);
    }
    this->unk11C = 10000.0f;
    temp_r30_111 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    temp_r4_112 = temp_r30_111 << 5;
    temp_r31_114 = *(&GameData::gameData[0x70] + (temp_r4_112 + 0x7C));
    temp_r5_116 = &GameData::gameData[0x70] + (temp_r4_112 + 0x64);
    if (temp_r31_114 == 3) {
        var_r4_120 = 0;
        if (((s32) M2C_FIELD(temp_r5_116, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_116, s32 *, 4) == 3)) {
            var_r4_120 = 1;
        }
        var_r6_130 = var_r4_120 != 0;
    } else {
        var_r6_130 = *(temp_r5_116 + (temp_r31_114 * 4));
    }
    if (temp_r31_114 == 3) {
        var_r4_139 = 0;
        if (((s32) M2C_FIELD(temp_r5_116, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r5_116, s32 *, 4) == 3)) {
            var_r4_139 = 1;
        }
        var_r26_149 = var_r4_139 != 0;
    } else {
        var_r26_149 = *(temp_r5_116 + (temp_r31_114 * 4));
    }
    temp_f31_159 = ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(temp_r30_111, temp_r31_114, var_r6_130);
    this->unk128.Init(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), MKProp *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), temp_f31_159, temp_r31_114, var_r26_149, temp_r30_111, temp_r30_111, 0, -1);
    temp_f1_176 = M2C_FIELD(&arg1, f64 *, 0);
    this->unkD0 = temp_f1_176;
    this->unkD8 = M2C_FIELD(&arg1, f64 *, 8);
    temp_r3_186 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, f64), 0x34)(M2C_FIELD(&gb, void ***, 0), temp_f1_176);
    sp10 = temp_r3_186;
    if (temp_r3_186 != NULL) {
        sp14 = M2C_FIELD(temp_r3_186, u8 *, 4);
        M2C_FIELD(temp_r3_186, u8 *, 4) = 0U;
    }
    sp60 = 0.0f;
    sp64 = 0.0f;
    sp68 = 0.0f;
    sp70 = 0.0f;
    sp74 = 0.0f;
    sp78 = 0.0f;
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp88 = 0.0f;
    sp8C = 1.0f;
    sp90 = 0.0f;
    sp94 = 0.0f;
    sp98 = 0;
    sp9A = 0;
    sp9B = 0;
    sp9C = 0;
    spA0 = 3.4028235e38f;
    spA4 = 0;
    spA8 = NULL;
    spAC = -1;
    spB0 = 0;
    if (MKCollision_SphereCollide(arg0, 50.0f, (MKCollisionResult *) &sp60, 1, (MKCollisionMode) 7, 0) != 0) {
        Explode(MKVector3::up, *((MKVector3 *) &sp60), spA8);
    }
    if (sp10 != NULL) {
        M2C_FIELD(sp10, u8 *, 4) = sp14;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match 'KDSound_Stop(int *)'
void EarthBombFX::Deinit() {
    ManagedLight *temp_r4_261;

    temp_r4_261 = this->unk100;
    if (temp_r4_261 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_261, 0U);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unk100);
    }
    KDSound_Stop((s32 *) (this + 0x180));
    GameProp::Deinit();
}
#endif

void EarthBombFX::Draw() {
    EarthBombFXDescriptor *desc;

    if ((u8) this->unkE0 != 0) {
        desc = checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        gRenderState = (s32) desc->unkEC;
        GameProp::Draw();
        gRenderState = 0;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'BreathHitMessage *' to 'MKMessage *'
void EarthBombFX::Explode(const MKVector3 &arg0, const MKVector3 &arg1, MKCollisionInfo *arg2) {
    s8 sp430;
    s32 sp42C;
    s32 sp428;
    s32 sp424;
    f32 sp420;
    s32 sp41C;
    s8 sp41B;
    s8 sp41A;
    s16 sp418;
    f32 sp414;
    f32 sp410;
    f32 sp40C;
    f32 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3F8;
    f32 sp3F4;
    f32 sp3F0;
    f32 sp3E8;
    f32 sp3E4;
    f32 sp3E0;
    Matrix sp3A0;
    M2C_UNK sp39C;
    s8 sp398;
    f64 sp390;
    f64 sp388;
    s32 sp384;
    s32 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
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
    MKVector3 sp280;
    MKVector3 sp270;
    f64 sp268;
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
    f64 sp210;
    f64 sp208;
    f64 sp200;
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f64 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
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
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    s32 sp14;
    f32 sp10;
    MKProp *temp_r3_366;
    MKVector3 *temp_r27_547;
    ManagedLight *temp_r4_521;
    f32 temp_f0_664;
    f32 temp_f19_549;
    f32 temp_f20_554;
    f32 temp_f20_596;
    f32 temp_f2_1073;
    f32 temp_f4_1032;
    f32 var_f0_760;
    f32 var_f23_378;
    f32 var_f24_374;
    f32 var_f25_372;
    f32 var_f26_377;
    f32 var_f27_375;
    f32 var_f4_810;
    f64 temp_f0_1047;
    f64 temp_f0_568;
    f64 temp_f0_578;
    f64 temp_f0_736;
    f64 temp_f1_361;
    f64 temp_f1_781;
    f64 temp_f1_815;
    f64 temp_f1_821;
    f64 temp_f1_825;
    f64 temp_f2_504;
    f64 temp_f5_1026;
    s32 temp_r0_373;
    s32 temp_r3_844;
    s32 var_r0_854;
    s32 var_r26_539;
    s32 var_r27_687;
    void *temp_r26_634;
    void *temp_r28_535;
    void *temp_r3_625;
    void *temp_r3_629;
    void *temp_r3_771;
    void *temp_r4_639;
    void *temp_r4_697;
    void *temp_r4_766;
    void *temp_r4_925;
    void *temp_r4_990;

    this->unkE0 = 0;
    if ((arg2 != NULL) && ((MKProp *) arg2->unk8 != NULL)) {
        this->unk128.unk50 = 0;
        temp_f1_361 = M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(this, f64 *, 0x138) = temp_f1_361;
        M2C_FIELD(this, f64 *, 0x140) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        this->unk128.unk30 = arg2;
        temp_r3_366 = arg2->unk8;
        temp_r3_366->Message(&this->unk128, temp_f1_361);
    }
    var_f25_372 = 1.0f;
    temp_r0_373 = this->unk128.unk3C;
    var_f24_374 = 1.0f;
    var_f27_375 = 0.5f;
    var_f26_377 = 30.0f;
    var_f23_378 = 2.0f;
    switch (temp_r0_373) {                          /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact1, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.5f, 0.3f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        var_f25_372 = 1.0f;
        var_f27_375 = 0.5f;
        var_f24_374 = 1.0f;
        var_f26_377 = 8.0f;
        var_f23_378 = 2.0f;
        break;
    case 1:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact2, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.7f, 0.5f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        var_f27_375 = 1.0f;
        var_f26_377 = 15.0f;
        var_f25_372 = 1.5f;
        var_f24_374 = 2.0f;
        var_f23_378 = 4.0f;
        break;
    case 2:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact3, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(0.9f, 0.8f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        /* fallthrough */
    case 3:                                         /* switch 1 */
        KDSound_Play3d(GS_SpyroEarthAttackImpact4, &arg1, 0U, -1, 0.0f, 0U);
        ((KDInput *) (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), KDInput *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0))))->RumblePlay3D(1.0f, 1.0f, 0.3f, &arg1, 100.0f, 0, 4.0f, 0U);
        var_f27_375 = 2.5f;
        var_f26_377 = 30.0f;
        var_f25_372 = 3.0f;
        var_f24_374 = 3.5f;
        var_f23_378 = 6.0f;
        break;
    }
    temp_f2_504 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk128.unk50 = 0;
    this->unk128.unk30 = NULL;
    sp370 = temp_f2_504;
    sp378 = M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, BreathHitMessage *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, f32, f64), 0x94)(gMK, &this->unk128, 0, 1, &sp370, 1, 750.0f, temp_f2_504);
    temp_r4_521 = this->unk100;
    if (temp_r4_521 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_521, 0U);
    }
    temp_r28_535 = checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    var_r26_539 = 0;
loop_18:
    if ((f32) var_r26_539 < (30.0f * var_f25_372)) {
        temp_r27_547 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
        temp_f19_549 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f20_554 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        sp170 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp174 = temp_f20_554;
        sp178 = temp_f19_549;
        sp2E0 = (f64) sp170;
        sp2E8 = (f64) sp178;
        temp_f0_568 = sp2E0 * 5.676053805e-315;
        sp160 = temp_f0_568;
        sp2F0 = temp_f0_568;
        sp168 = (f32) sp2E8 * 1000.0f;
        sp2F8 = (f64) sp168;
        temp_f0_578 = temp_f0_568 * (f64) var_f25_372;
        sp150 = temp_f0_578;
        sp300 = temp_f0_578;
        sp158 = (f32) sp2F8 * var_f25_372;
        sp308 = (f64) sp158;
        sp18 = MKRand_Float((int *) &gViewSeed, 25.0f, 35.0f);
        temp_f20_596 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.2f);
        sp140 = MKRand_Float((int *) &gViewSeed, 0.0f, 0.2f);
        sp144 = 1.0f;
        sp148 = temp_f20_596;
        sp14C = 1.0f;
        sp2D0 = (f64) sp140;
        sp2D8 = (f64) sp148;
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(*temp_r27_547, *((MKVector3 *) &sp300), sp18, *((MKVector4 *) &sp2D0), -980.0f);
        var_r26_539 += 1;
        goto loop_18;
    }
    temp_r3_625 = M2C_FIELD(temp_r28_535, void **, 0xE8);
    temp_r3_629 = M2C_FIELD(M2C_FIELD(temp_r3_625, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_625);
    if (temp_r3_629 != NULL) {
        temp_r26_634 = M2C_FIELD(temp_r3_629, void **, 0x2C);
        sp2B0 = MKVector(0.0f, 100.0f, 0.0f);
        temp_r4_639 = ((u8 *) this->unk8) + 0x30;
        sp80 = M2C_FIELD(temp_r4_639, f64 *, 0) + M2C_BITWISE(f64, sp2B0);
        M2C_FIELD(temp_r3_629, f64 *, 0) = sp80;
        sp88 = M2C_FIELD(temp_r4_639, f32 *, 8) + sp2B0.unk8;
        sp2C0 = sp80;
        M2C_FIELD(temp_r3_629, f64 *, 8) = (f64) sp88;
        M2C_FIELD(temp_r3_629, f32 *, 0x20) = 0.0f;
        sp2C8 = (f64) sp88;
        M2C_FIELD(temp_r3_629, f32 *, 0x28) = 0.0f;
        temp_f0_664 = 3.1415927f * MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp78 = 0.0f;
        sp70 = 0.0f;
        sp74 = 0.0f;
        M2C_FIELD(temp_r3_629, f32 *, 0x24) = (f32) (2.0f * temp_f0_664);
        M2C_FIELD(temp_r26_634, f64 *, 0) = (f64) sp70;
        M2C_FIELD(temp_r26_634, f64 *, 8) = (f64) sp78;
        sp2A0 = (f64) sp70;
        sp2A8 = (f64) sp78;
        M2C_FIELD(temp_r26_634, f32 *, 0x18) = var_f26_377;
        M2C_FIELD(temp_r26_634, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        M2C_FIELD(temp_r26_634, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r28_535, void **, 0xE8), f32 *, 0xF4);
    }
    var_r27_687 = 0;
    do {
        sp280 = MKVector(0.0f, 100.0f, 0.0f);
        temp_r4_697 = ((u8 *) this->unk8) + 0x30;
        sp60 = M2C_FIELD(temp_r4_697, f64 *, 0) + M2C_BITWISE(f64, sp280);
        sp48 = 1.0f;
        sp58 = -1.0f;
        sp68 = M2C_FIELD(temp_r4_697, f32 *, 8) + sp280.unk8;
        sp40 = 1.0f;
        sp44 = 1.0f;
        sp50 = -1.0f;
        sp54 = 0.25f;
        sp290 = sp60;
        sp298 = (f64) sp68;
        sp360 = sp60;
        sp368 = (f64) sp68;
        sp250 = (f64) sp40;
        sp258 = (f64) sp48;
        sp260 = (f64) sp50;
        sp268 = (f64) sp58;
        sp270 = KDRand_Vector(*((MKVector3 *) &sp260), *((MKVector3 *) &sp250));
        *(MKVector3 *) &sp350 = sp270;
        temp_f0_736 = sp350 * 5.60222949e-315;
        sp130 = temp_f0_736;
        sp240 = temp_f0_736;
        sp138 = (f32) sp358 * 300.0f;
        sp248 = (f64) sp138;
        sp14 = MKRand_Int((int *) &gViewSeed, 0, 3);
        ((FallingLeaves *) (M2C_FIELD(temp_r28_535, FallingLeaves **, 0xE4)))->Emit(*((MKVector3 *) &sp360), *((MKVector3 *) &sp240), 2.0f, sp14, 1U);
        var_r27_687 += 1;
    } while (var_r27_687 < 5);
    var_f0_760 = 0.0f;
    sp120 = 0.0f;
    temp_r4_766 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp124 = 200.0f;
    sp128 = 0.0f;
    temp_r3_771 = ((u8 *) this->unk8) + 0x30;
    sp210 = (f64) sp120;
    sp340 = M2C_FIELD(temp_r4_766, f64 *, 0x30);
    sp348 = M2C_FIELD(temp_r4_766, f64 *, 0x38);
    sp218 = (f64) sp128;
    temp_f1_781 = M2C_FIELD(temp_r3_771, f64 *, 0) + sp210;
    sp110 = temp_f1_781;
    sp220 = temp_f1_781;
    sp118 = M2C_FIELD(temp_r3_771, f32 *, 8) + (f32) sp218;
    sp228 = (f64) sp118;
    sp100 = sp220 - sp340;
    sp230 = sp100;
    sp108 = (f32) sp228 - (f32) sp348;
    sp238 = (f64) sp108;
    var_f4_810 = ((f32) sp238 * (f32) sp238) + (((f32) sp230 * (f32) sp230) + ((*(f32 *) ((u8 *) &sp230 + 0x4)) * (*(f32 *) ((u8 *) &sp230 + 0x4))));
    if (var_f4_810 > 1e-12f) {
        if (var_f4_810 > 0.0f) {
            temp_f1_815 = __frsqrte(var_f4_810);
            temp_f1_821 = 0.5 * temp_f1_815 * -(((f64) var_f4_810 * (temp_f1_815 * temp_f1_815)) - 3.0);
            temp_f1_825 = 0.5 * temp_f1_821 * -(((f64) var_f4_810 * (temp_f1_821 * temp_f1_821)) - 3.0);
            var_f4_810 = (f32) ((f64) var_f4_810 * (0.5 * temp_f1_825 * -(((f64) var_f4_810 * (temp_f1_825 * temp_f1_825)) - 3.0)));
        } else if (var_f4_810 < M2C_BITWISE(f32, 0.0)) {
            var_f4_810 = __float_nan;
        } else {
            sp10 = var_f4_810;
            temp_r3_844 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_844) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_854 = 1;
                } else {
                    var_r0_854 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_854 = 5;
                } else {
                    var_r0_854 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_854 = 4;
                break;
            }
            if (var_r0_854 == 1) {
                var_f4_810 = __float_nan;
            }
        }
        var_f0_760 = 1.0f / var_f4_810;
    }
    spF4 = (*(f32 *) ((u8 *) &sp230 + 0x4)) * var_f0_760;
    spF0 = (f32) sp230 * var_f0_760;
    spF8 = (f32) sp238 * var_f0_760;
    sp330 = (f64) spF0;
    sp338 = (f64) spF8;
    M2C_STRUCT_COPY((s32) &sp39C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    spE8 = 0.0f;
    spE0 = 0.0f;
    spE4 = 1.0f;
    sp328 = (f64) spE8;
    sp320 = (f64) spE0;
    KDMath_BuildMatrixFromFwd(&sp3A0, *((MKVector3 *) &sp330), (MKVector3 *) &sp320);
    sp3A0.Scale3x3(&sp3A0, var_f27_375);
    sp1F0 = MKVector(0.0f, 100.0f * var_f27_375, 0.0f);
    temp_r4_925 = ((u8 *) this->unk8) + 0x30;
    sp30 = M2C_FIELD(temp_r4_925, f64 *, 0) + M2C_BITWISE(f64, sp1F0);
    sp200 = sp30;
    sp38 = M2C_FIELD(temp_r4_925, f32 *, 8) + sp1F0.unk8;
    sp208 = (f64) sp38;
    sp3A0.unk30 = (f32) sp200;
    sp3A0.unk34 = (*(f32 *) ((u8 *) &sp200 + 0x4));
    sp3A0.unk38 = (f32) sp208;
    sp3A0.unk3C = 1.0f;
    ((ExplosionWarpFX *) (&gb + 0x1C0))->StartWarp(&sp3A0);
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        sp384 = 0;
        sp1D0 = MKVector(1.0f, 1.0f, 1.0f);
        sp20 = sp1D0 * 5.593163344e-315;
        sp380 = 0x417;
        sp388 = sp20;
        sp28 = sp1D0.unk8 * 250.0f;
        sp398 = 1;
        sp390 = (f64) sp28;
        sp1E0 = sp20;
        sp1E8 = (f64) sp28;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp380, sp20);
    }
    temp_r4_990 = this->unk8;
    spB0 = 0.0f;
    spB4 = -1000.0f;
    spB8 = 0.0f;
    sp310 = M2C_FIELD(temp_r4_990, f64 *, 0x30);
    sp318 = M2C_FIELD(temp_r4_990, f64 *, 0x38);
    sp3E0 = 0.0f;
    sp3E4 = 0.0f;
    sp3E8 = 0.0f;
    sp3F0 = 0.0f;
    sp3F4 = 0.0f;
    sp3F8 = 0.0f;
    sp400 = 0.0f;
    sp404 = 0.0f;
    sp408 = 0.0f;
    sp40C = 1.0f;
    sp410 = 0.0f;
    sp414 = 0.0f;
    sp418 = 0;
    sp41A = 0;
    sp41B = 0;
    sp41C = 0;
    sp420 = 3.4028235e38f;
    sp424 = 0;
    sp428 = 0;
    sp42C = -1;
    sp430 = 0;
    sp190 = (f64) spB0;
    sp198 = (f64) spB8;
    temp_f5_1026 = *(temp_r4_990 + 0x30);
    spA0 = temp_f5_1026 + sp190;
    spD8 = 0.0f;
    temp_f4_1032 = (f32) M2C_FIELD(temp_r4_990, f64 *, 0x38);
    spD0 = 0.0f;
    spD4 = 100.0f;
    spA8 = temp_f4_1032 + (f32) sp198;
    sp1B0 = (f64) spD0;
    sp1A0 = spA0;
    sp1A8 = (f64) spA8;
    sp1B8 = (f64) spD8;
    temp_f0_1047 = temp_f5_1026 + sp1B0;
    spC0 = temp_f0_1047;
    sp1C0 = temp_f0_1047;
    spC8 = temp_f4_1032 + (f32) sp1B8;
    sp1C8 = (f64) spC8;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp1C0), *((MKVector3 *) &sp1A0), (MKCollisionResult *) &sp3E0, (MKCollisionMode) 4, 0x0C000000) == 0) {
        sp310 = (f64) sp3E0;
        sp318 = (f64) sp3E8;
    }
    temp_f2_1073 = 2.0f * var_f24_374;
    sp98 = temp_f2_1073;
    sp90 = temp_f2_1073;
    sp94 = temp_f2_1073;
    sp188 = (f64) sp98;
    sp180 = (f64) sp90;
    ((EarthBreathWhirlWinds *) (M2C_FIELD(&gb, EarthBreathWhirlWinds **, 0x2C8)))->SpawnWhirlWind(*((MKVector3 *) &sp310), *((MKVector3 *) &sp180), (Upgrade) this->unk128.unk3C, 1U, var_f23_378);
    Disable();
}
#endif

void EarthBombFX::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) (this + 0x180))->Message(arg0);
    GameProp::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void *EarthBombFX::Update() {
    u8 sp388;
    s32 sp384;
    MKCollisionInfo *sp380;
    s32 sp37C;
    f32 sp378;
    s32 sp374;
    s8 sp373;
    s8 sp372;
    s16 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
    f32 sp340;
    f32 sp33C;
    f32 sp338;
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
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    MKVector3 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
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
    MKVector4 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
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
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
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
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp14;
    f32 sp10;
    s32 sp8;
    MKProp *var_r28_1472;
    ManagedLight *temp_r3_1591;
    ManagedLight *temp_r3_1720;
    ManagedLight *temp_r3_1737;
    f32 temp_f0_1738;
    f32 temp_f1_1590;
    f32 temp_f1_1620;
    f32 temp_f2_1192;
    f32 temp_f30_1288;
    f32 temp_f30_1355;
    f32 temp_f31_1350;
    f32 temp_f4_1612;
    f32 temp_f5_1201;
    f32 temp_f7_1622;
    f32 var_f28_1643;
    f32 var_f4_1374;
    f32 var_f4_1441;
    f32 var_f6_1185;
    f32 var_f8_1604;
    f64 temp_f0_1222;
    f64 temp_f0_1235;
    f64 temp_f0_1270;
    f64 temp_f0_1298;
    f64 temp_f0_1563;
    f64 temp_f0_1654;
    f64 temp_f0_1664;
    f64 temp_f0_1674;
    f64 temp_f0_1684;
    f64 temp_f0_1694;
    f64 temp_f0_1704;
    f64 temp_f1_1380;
    f64 temp_f1_1386;
    f64 temp_f1_1390;
    f64 temp_f2_1269;
    s32 temp_r3_1409;
    s32 var_r0_1419;
    u8 var_r30_1316;
    void *temp_r31_1166;
    void *temp_r3_1596;
    void *temp_r3_1725;
    void *temp_r3_1740;
    void *temp_r4_1229;
    void *temp_r5_1265;

    temp_r31_1166 = checked_cast<EarthBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    ((KDSoundFader *) (this + 0x180))->Update(GS_SpyroEarthAttack5LP, 1U, this->unkE0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if ((u8) this->unkE0 != 0) {
        var_f6_1185 = 0.5f * (0.85f * gUpdateTimeDelta);
        if (var_f6_1185 < 1.0f) {

        } else {
            var_f6_1185 = 1.0f;
        }
        temp_f2_1192 = this->unkC8;
        sp1A0 = -1.0f;
        temp_f5_1201 = (var_f6_1185 * (150.0f - temp_f2_1192)) + temp_f2_1192;
        sp190 = 1.0f;
        sp198 = -1.0f;
        sp19C = -1.0f;
        sp188 = 1.0f;
        sp18C = 1.0f;
        this->unkC8 = (var_f6_1185 * (150.0f - temp_f5_1201)) + temp_f5_1201;
        sp288 = (f64) sp198;
        sp290 = (f64) sp1A0;
        sp278 = (f64) sp188;
        sp280 = (f64) sp190;
        sp298 = KDRand_Vector(*((MKVector3 *) &sp288), *((MKVector3 *) &sp278));
        temp_f0_1222 = sp298 * 5.49408334e-315;
        sp178 = temp_f0_1222;
        sp2A8 = temp_f0_1222;
        temp_r4_1229 = ((u8 *) this->unk8) + 0x30;
        sp180 = sp298.unk8 * 50.0f;
        sp2B0 = (f64) sp180;
        temp_f0_1235 = M2C_FIELD(temp_r4_1229, f64 *, 0) + temp_f0_1222;
        sp168 = temp_f0_1235;
        sp2B8 = temp_f0_1235;
        sp170 = M2C_FIELD(temp_r4_1229, f32 *, 8) + (f32) sp2B0;
        sp2C0 = (f64) sp170;
        sp15C = MKRand_Float((int *) &gViewSeed, 100.0f, 200.0f);
        sp158 = 0.0f;
        sp160 = 0.0f;
        sp268 = (f64) sp158;
        sp270 = (f64) sp160;
        ((HeatDistortPS *) (&gb + 0x240))->Emit(*((MKVector3 *) &sp2B8), *((MKVector3 *) &sp268), 3.0f, 1.0f);
        temp_r5_1265 = this->unk8;
        temp_f2_1269 = M2C_FIELD(temp_r5_1265, f64 *, 0x30);
        temp_f0_1270 = M2C_FIELD(temp_r5_1265, f64 *, 0x38);
        sp328 = temp_f2_1269;
        sp330 = temp_f0_1270;
        sp318 = temp_f2_1269;
        sp320 = temp_f0_1270;
        sp248 = ((MKVector3 *) &this->unkD0)->operator*(gUpdateTimeDelta);
        spA8 = sp328 + M2C_BITWISE(f64, sp248);
        sp258 = spA8;
        temp_f30_1288 = gUpdateTimeDelta;
        spB0 = (f32) sp330 + sp248.unk8;
        sp318 = spA8;
        sp260 = (f64) spB0;
        sp320 = (f64) spB0;
        sp228 = MKVector(0.0f, -1960.0f, 0.0f);
        temp_f0_1298 = sp228 * (f64) temp_f30_1288;
        sp98 = temp_f0_1298;
        sp238 = temp_f0_1298;
        spA0 = sp228.unk8 * temp_f30_1288;
        sp240 = (f64) spA0;
        this->unkD0 += temp_f0_1298;
        var_r30_1316 = 0;
        M2C_FIELD(this, f32 *, 0xD8) = (f32) (M2C_FIELD(this, f32 *, 0xD8) + (f32) sp240);
        sp338 = 0.0f;
        sp33C = 0.0f;
        sp340 = 0.0f;
        sp348 = 0.0f;
        sp34C = 0.0f;
        sp350 = 0.0f;
        sp358 = 0.0f;
        sp35C = 0.0f;
        sp360 = 0.0f;
        sp364 = 1.0f;
        sp368 = 0.0f;
        sp36C = 0.0f;
        sp370 = 0;
        sp372 = 0;
        sp373 = 0;
        sp374 = 0;
        sp378 = 3.4028235e38f;
        sp37C = 0;
        sp380 = NULL;
        sp384 = -1;
        sp388 = 0;
        sp308 = sp318;
        sp310 = sp320;
        temp_f31_1350 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f30_1355 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp148 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp14C = temp_f30_1355;
        sp150 = temp_f31_1350;
        sp218 = (f64) sp148;
        sp220 = (f64) sp150;
        var_f4_1374 = ((f32) sp220 * (f32) sp220) + (((f32) sp218 * (f32) sp218) + ((*(f32 *) ((u8 *) &sp218 + 0x4)) * (*(f32 *) ((u8 *) &sp218 + 0x4))));
        if (var_f4_1374 > 1e-12f) {
            if (var_f4_1374 > 0.0f) {
                temp_f1_1380 = __frsqrte(var_f4_1374);
                temp_f1_1386 = 0.5 * temp_f1_1380 * -(((f64) var_f4_1374 * (temp_f1_1380 * temp_f1_1380)) - 3.0);
                temp_f1_1390 = 0.5 * temp_f1_1386 * -(((f64) var_f4_1374 * (temp_f1_1386 * temp_f1_1386)) - 3.0);
                var_f4_1374 = (f32) ((f64) var_f4_1374 * (0.5 * temp_f1_1390 * -(((f64) var_f4_1374 * (temp_f1_1390 * temp_f1_1390)) - 3.0)));
            } else if (var_f4_1374 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1374 = __float_nan;
            } else {
                sp10 = var_f4_1374;
                temp_r3_1409 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1409) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1419 = 1;
                    } else {
                        var_r0_1419 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1419 = 5;
                    } else {
                        var_r0_1419 = 3;
                    }
                    break;
                default:
                    var_r0_1419 = 4;
                    break;
                }
                if (var_r0_1419 == 1) {
                    var_f4_1374 = __float_nan;
                }
            }
            var_f4_1441 = 1.0f / var_f4_1374;
        } else {
            var_f4_1441 = 0.0f;
        }
        sp13C = (*(f32 *) ((u8 *) &sp218 + 0x4)) * var_f4_1441;
        sp138 = (f32) sp218 * var_f4_1441;
        sp140 = (f32) sp220 * var_f4_1441;
        sp2F8 = (f64) sp138;
        sp300 = (f64) sp140;
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp328), *((MKVector3 *) &sp318), 40.0f, (MKCollisionResult *) &sp338, (MKCollisionMode) 7, 0) != 0) {
            if ((sp388 != 0) && (sp380 != NULL) && (var_r28_1472 = sp380->unk8, ((var_r28_1472 == NULL) == 0))) {

            } else {
                var_r28_1472 = NULL;
            }
            if ((var_r28_1472 != NULL) && (var_r28_1472 != M2C_FIELD(*gb, u32 (**)(void **), 0xC)(gb))) {
                var_r30_1316 = 1;
            } else if (var_r28_1472 == NULL) {
                var_r30_1316 = 1;
                sp2F8 = (f64) sp348;
                sp300 = (f64) sp350;
            }
            sp308 = (f64) sp338;
            sp310 = (f64) sp340;
        }
        if (var_r30_1316 != 0) {
            Explode(*((MKVector3 *) &sp2F8), *((MKVector3 *) &sp308), sp380);
        } else {
            MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp318));
            this->unkFC += gUpdateTimeDelta;
            if (this->unkFC > 4.0f) {
                Explode(*((MKVector3 *) &sp2F8), *((MKVector3 *) &sp318), NULL);
            }
        }
        sp80 = 1.0f;
        sp90 = -1.0f;
        sp78 = 1.0f;
        sp7C = 0.0f;
        sp88 = -1.0f;
        sp8C = 0.0f;
        sp2E8 = sp318;
        sp2F0 = sp320;
        sp1E8 = (f64) sp78;
        sp1F0 = (f64) sp80;
        sp1F8 = (f64) sp88;
        sp200 = (f64) sp90;
        sp208 = KDRand_Vector(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp1E8));
        *(MKVector3 *) &sp2D8 = sp208;
        temp_f0_1563 = sp2D8 * 5.439686476e-315;
        sp128 = temp_f0_1563;
        sp1D8 = temp_f0_1563;
        sp130 = (f32) sp2E0 * 20.0f;
        sp1E0 = (f64) sp130;
        sp14 = MKRand_Int((int *) &gViewSeed, 0, 3);
        ((FallingLeaves *) (M2C_FIELD(temp_r31_1166, FallingLeaves **, 0xE4)))->Emit(*((MKVector3 *) &sp2E8), *((MKVector3 *) &sp1D8), 2.0f, sp14, 0U);
        if ((ManagedLight *) this->unk100 != NULL) {
            temp_f1_1590 = MKRand_Float((int *) &gViewSeed, 0.2f, 0.6f);
            temp_r3_1591 = this->unk100;
            temp_r3_1591->unk10 = sp318;
            temp_r3_1591->unk18 = sp320;
            temp_r3_1596 = temp_r3_1591->unk3C;
            if (temp_r3_1596 != NULL) {
                M2C_FIELD(temp_r3_1596, f64 *, 0x10) = sp318;
                M2C_FIELD(temp_r3_1596, f64 *, 0x18) = sp320;
            }
            var_f8_1604 = 0.1f;
            if (1.0f > 0.1f) {

            } else {
                var_f8_1604 = 1.0f;
            }
            temp_f4_1612 = this->unk11C;
            sp108 = 0.0f;
            temp_f1_1620 = (var_f8_1604 * (1000.0f - temp_f4_1612)) + temp_f4_1612;
            sp10C = 1.0f;
            temp_f7_1622 = 0.5f * (temp_f1_1590 * 1.0f);
            sp110 = 0.0f;
            sp114 = 1.0f;
            this->unk11C = (var_f8_1604 * (1000.0f - temp_f1_1620)) + temp_f1_1620;
            sp118 = 0.5f;
            sp11C = 1.0f;
            sp120 = 0.0f;
            sp124 = 1.0f;
            sp1B8 = (f64) sp108;
            sp1C0 = (f64) sp110;
            sp1C8 = (f64) sp118;
            sp1D0 = (f64) sp120;
            if (temp_f7_1622 < 1.0f) {
                var_f28_1643 = temp_f7_1622;
            } else {
                var_f28_1643 = 1.0f;
            }
            sp68 = sp1B8 - sp1C8;
            temp_f0_1654 = sp1C0 - sp1D0;
            sp70 = temp_f0_1654;
            spD8 = sp68;
            spE0 = temp_f0_1654;
            sp58 = spD8 * (f64) var_f28_1643;
            temp_f0_1664 = temp_f0_1654 * (f64) var_f28_1643;
            sp60 = temp_f0_1664;
            spC8 = sp58;
            spD0 = temp_f0_1664;
            sp48 = sp1C8 + spC8;
            temp_f0_1674 = sp1D0 + temp_f0_1664;
            sp50 = temp_f0_1674;
            spB8 = sp48;
            spC0 = temp_f0_1674;
            sp38 = sp1B8 - spB8;
            temp_f0_1684 = sp1C0 - spC0;
            sp40 = temp_f0_1684;
            spF8 = sp38;
            sp100 = temp_f0_1684;
            sp28 = spF8 * (f64) var_f28_1643;
            temp_f0_1694 = temp_f0_1684 * (f64) var_f28_1643;
            sp30 = temp_f0_1694;
            spE8 = sp28;
            spF0 = temp_f0_1694;
            sp18 = spB8 + spE8;
            temp_f0_1704 = spC0 + temp_f0_1694;
            sp20 = temp_f0_1704;
            sp2C8 = sp18;
            sp2D0 = temp_f0_1704;
            KDMath_Smooth<MKVector4>(sp1A8, this->unk108, 0.5f, 1.0f);
            M2C_FIELD(this, MKVector4 *, 0x108) = sp1A8;
            temp_r3_1720 = this->unk100;
            temp_r3_1720->unk20 = M2C_FIELD(this, f64 *, 0x108);
            temp_r3_1720->unk28 = M2C_FIELD(this, f64 *, 0x110);
            temp_r3_1725 = temp_r3_1720->unk3C;
            if (temp_r3_1725 != NULL) {
                M2C_FIELD(temp_r3_1725, f64 *, 0) = (f64) M2C_FIELD(this, f64 *, 0x108);
                M2C_FIELD(temp_r3_1725, f64 *, 8) = (f64) M2C_FIELD(this, f64 *, 0x110);
            }
            temp_r3_1737 = this->unk100;
            temp_f0_1738 = (this->unkC8 / 50.0f) * this->unk11C;
            temp_r3_1737->unk38 = temp_f0_1738;
            temp_r3_1740 = temp_r3_1737->unk3C;
            if (temp_r3_1740 != NULL) {
                M2C_FIELD(temp_r3_1740, f32 *, 0x20) = temp_f0_1738;
                M2C_FIELD(temp_r3_1740, f32 *, 0x24) = (f32) (temp_f0_1738 * temp_f0_1738);
                M2C_FIELD(temp_r3_1740, f32 *, 0x28) = (f32) (1.0f / temp_f0_1738);
                M2C_FIELD(temp_r3_1740, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1740, f32 *, 0x24));
            }
        }
    }
}
#endif

f32 EarthBombFX::Resolve() {
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
    ManagedLight *temp_r4_1894;

    KDPropEx::Resolve();
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
    this->unk100 = (ManagedLight *) (((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 1000.0f, lit_728, lit_729));
    temp_r4_1894 = this->unk100;
    if (temp_r4_1894 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_1894, 0U);
    }
}

void EarthBombFX::Init() {
    GameProp::Init();
    this->unkE0 = 0;
    this->unkF8 = 0.0f;
    this->unkFC = 0.0f;
    this->unkC8 = 0.0f;
    this->unk100 = NULL;
    this->unk108.unk0 = 1.0f;
    this->unk108.unk4 = 1.0f;
    this->unk108.unk8 = 0.0f;
    this->unk108.unkC = 1.0f;
    this->unk118 = NULL;
    this->unk11C = 1000.0f;
    ((KDSoundFader *) (this + 0x180))->Init(0.25f, 0.25f);
}

void EarthBombFXDescriptor::Deinit() {
    MKMaterial_Destroy(this->unkEC);
    KDPropExDescriptor::Deinit();
}

void EarthBombFXDescriptor::Init() {
    FallingLeaves *leaves;

    GamePropDescriptor::Init();
    leaves = checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves"));
    M2C_FIELD(this, FallingLeaves **, 0xE4) = leaves;
    this->unkE8 = (long) (checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EarthBeamBlastPS")));
    this->unkEC = (MKMaterial *) (MKMaterial_Create("fx_EarthBomb"));
}

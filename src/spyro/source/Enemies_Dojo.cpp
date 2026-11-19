#include "spyro/source/Enemies_Dojo.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterDojoFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/DojoGoal_Think.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDParticleSystem.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/ZapArcFX.h"
#include "spyro/source/ZapPS.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_DDEarthSpawn;
extern s32 GS_DDElecSpawn;
extern s32 GS_DDFireSpawn;
extern s32 GS_DDIceSpawn;
extern s32 GS_DojoDummy01Extra1;
extern void **gMK;
extern s32 gViewSeed;
extern GameGlobals gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit dojoTier1BodyFXInit;     /* unable to generate initializer: confusing struct layout */
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit dojoTier2BodyFXInit;     /* unable to generate initializer: confusing struct layout */
#endif
#if 0 // DRAFT: identifier 'dojoMovementAnims' redeclared was declared as: 'unsigned char[240]' now declared as: 'long'
static M2C_UNK dojoMovementAnims;                   /* unable to generate initializer: unknown type */
#endif
static u8 lit_884 = 1;
static u8 lit_1044 = 1;
static u8 lit_1251 = 1;
static u8 lit_1411 = 1;

s32 DojoTier2::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x360);
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'double'
void DojoTier2::Despawn(bool arg0) {
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f32 sp430;
    f64 sp420;                                      /* compiler-managed */
    f64 sp418;                                      /* compiler-managed */
    f64 sp410;
    f64 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    M2C_UNK sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    MKVector3 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    MKVector3 sp368;
    f64 sp360;
    f64 sp358;
    MKVector3 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    MKVector3 sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
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
    MKHeap *var_r26_100;
    MKPropDescriptor *temp_r20_413;
    f32 temp_f0_709;
    f32 temp_f16_559;
    f32 temp_f16_573;
    f32 temp_f16_687;
    f32 temp_f17_761;
    f32 temp_f1_488;
    f32 temp_f1_655;
    f32 var_f17_517;
    f64 temp_f0_728;
    f64 temp_f0_803;
    s32 temp_r3_107;
    s32 temp_r3_532;
    s32 var_r19_414;
    s32 var_r19_468;
    s32 var_r19_516;
    s32 var_r19_634;
    s32 var_r19_688;
    s32 var_r19_764;
    s32 var_r19_836;
    s32 var_r19_876;
    s32 var_r19_917;
    s32 var_r20_540;
    s32 var_r21_135;
    s32 var_r21_190;
    s32 var_r21_228;
    s32 var_r21_277;
    s32 var_r21_315;
    s32 var_r23_415;
    void *temp_r20_347;
    void *temp_r22_421;
    void *temp_r22_789;
    void *temp_r28_101;
    void *temp_r3_342;

    if (((u8) this->unkB09 >> 7U) & 1) {
        var_r26_100 = this->unkA38->unk27C;
        temp_r28_101 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
loop_49:
        if ((MKHeap *) var_r26_100->unk0 != (MKHeap *)-1U) {
            temp_r3_107 = this->unkB20;
            switch (temp_r3_107) {                  /* irregular */
            case 0x8000000:
                KDSound_Play3d(GS_DDFireSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r21_135 = 0;
                do {
                    sp3C8 = KDRand_UnitVectorXZ();
                    sp108 = sp3C8 * 5.61841903e-315;
                    sp3D8 = sp108;
                    sp110 = sp3C8.unk8 * 400.0f;
                    sp418 = sp108;
                    sp3E0 = (f64) sp110;
                    sp420 = (f64) sp110;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp34 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((CrashFirePS *) gb.unk68)->Emit(this->unk588, *((MKVector3 *) &sp418), sp34);
                    sp3F8 = 1.0f;
                    sp3FC = 0.75f;
                    sp400 = 0.75f;
                    sp404 = 1.0f;
                    sp30 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((EmbersPS *) gb.unk74)->Emit(this->unk588, *((MKVector3 *) &sp418), sp30, *((MKVector4 *) &sp3F8), 0.0f);
                    var_r21_135 += 1;
                } while (var_r21_135 < 0x1E);
                var_r21_190 = 0;
                do {
                    sp3A8 = KDRand_UnitVectorXZ();
                    spF8 = sp3A8 * 5.61841903e-315;
                    sp3B8 = spF8;
                    sp100 = sp3A8.unk8 * 400.0f;
                    sp418 = spF8;
                    sp3C0 = (f64) sp100;
                    sp420 = (f64) sp100;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    gb.unk240.Emit(this->unk588, *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f), 1.0f);
                    var_r21_190 += 1;
                } while (var_r21_190 < 0xF);
                var_r21_228 = 0;
                do {
                    sp388 = KDRand_UnitVectorXZ();
                    spE8 = sp388 * 5.61841903e-315;
                    sp398 = spE8;
                    spF0 = sp388.unk8 * 400.0f;
                    sp418 = spE8;
                    sp3A0 = (f64) spF0;
                    sp420 = (f64) spF0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                    sp2C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), sp2C, 0.0f);
                    var_r21_228 += 1;
                } while (var_r21_228 < 5);
                break;
            case 0x10000000:
                KDSound_Play3d(GS_DDIceSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r21_277 = 0;
                do {
                    sp368 = KDRand_UnitVectorXZ();
                    spD8 = sp368 * 5.60222949e-315;
                    sp378 = spD8;
                    spE0 = sp368.unk8 * 300.0f;
                    sp418 = spD8;
                    sp380 = (f64) spE0;
                    sp420 = (f64) spE0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 20.0f, 27.0f);
                    sp28 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((IceBitsPS *) (M2C_FIELD(temp_r28_101, IceBitsPS **, 0x2B4)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp28);
                    var_r21_277 += 1;
                } while (var_r21_277 < 0x14);
                var_r21_315 = 0;
                do {
                    sp348 = KDRand_UnitVectorXZ();
                    spC8 = sp348 * 5.49408334e-315;
                    sp358 = spC8;
                    spD0 = sp348.unk8 * 50.0f;
                    sp418 = spC8;
                    sp360 = (f64) spD0;
                    sp420 = (f64) spD0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                    temp_r3_342 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
                    if (temp_r3_342 != NULL) {
                        temp_r20_347 = M2C_FIELD(temp_r3_342, void **, 0x2C);
                        sp2F8 = MKVector(1.0f, 2.0f, 1.0f);
                        sp308 = MKVector(-1.0f, 0.0f, -1.0f);
                        sp318 = KDRand_Vector(sp308, sp2F8);
                        sp328.operator*(50.0f);
                        spB8 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp328);
                        M2C_FIELD(temp_r3_342, f64 *, 0) = spB8;
                        spC0 = this->unk588.unk8 + sp328.unk8;
                        sp338 = spB8;
                        M2C_FIELD(temp_r3_342, f64 *, 8) = (f64) spC0;
                        M2C_FIELD(temp_r3_342, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_342, f32 *, 0x28) = 0.0f;
                        sp340 = (f64) spC0;
                        M2C_FIELD(temp_r20_347, f64 *, 0) = sp418;
                        M2C_FIELD(temp_r20_347, f64 *, 8) = sp420;
                        M2C_FIELD(temp_r20_347, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.5f, 1.5f);
                        M2C_FIELD(temp_r20_347, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r20_347, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
                    }
                    var_r21_315 += 1;
                } while (var_r21_315 < 5);
                temp_r20_413 = (void *) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "IceCube")));
                var_r19_414 = 0;
                var_r23_415 = 0;
                do {
                    *(&sp3E8 + var_r23_415) = (long) (checked_cast<PooledShatterProp *, MKProp>(temp_r20_413->CreateInstance()));
                    temp_r22_421 = (void *) (*(&sp3E8 + var_r23_415));
                    if (temp_r22_421 != NULL) {
                        M2C_FIELD(M2C_FIELD(temp_r22_421, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *), 0x38)(temp_r22_421, &this->unk588);
                        M2C_FIELD(M2C_FIELD(temp_r22_421, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r22_421);
                        M2C_FIELD(M2C_FIELD(temp_r22_421, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r22_421);
                        M2C_FIELD(M2C_FIELD(temp_r22_421, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r22_421, 0, 0, -1, 0, 1, 0);
                    }
                    var_r19_414 += 1;
                    var_r23_415 += 4;
                } while (var_r19_414 < 3);
                break;
            case 0x20000000:
                KDSound_Play3d(GS_DDElecSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r19_468 = 0;
                do {
                    sp2D8 = KDRand_UnitVectorXZ();
                    spA8 = sp2D8 * 5.65986426e-315;
                    sp2E8 = spA8;
                    spB0 = sp2D8.unk8 * 800.0f;
                    sp418 = spA8;
                    sp2F0 = (f64) spB0;
                    sp420 = (f64) spB0;
                    temp_f1_488 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp178 = 1.0f;
                    sp17C = 1.0f;
                    sp180 = 1.0f;
                    sp184 = 1.0f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_488;
                    sp2C8 = (f64) sp178;
                    sp2D0 = (f64) sp180;
                    sp24 = MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
                    ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp24, (MKVector4) &sp2C8);
                    var_r19_468 += 1;
                } while (var_r19_468 < 0xF);
                var_r19_516 = 0;
                var_f17_517 = 0.0f;
                sp448 = 4503601774854144.0;
                sp460 = 5.287201034e-315;
                sp438 = 5.465589745e-315;
                sp440 = 5.370091495e-315;
                do {
                    temp_r3_532 = MKRand_Int((int *) &gViewSeed, 4, 8);
                    var_f17_517 += (f32) sp438;
                    var_r20_540 = 0;
                    sp430 = (f32) sp440 / (f32) (temp_r3_532 - 1);
loop_33:
                    if (var_r20_540 < temp_r3_532) {
                        temp_f16_559 = (f32) var_r20_540 * sp430;
                        sp450 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        sp458 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        temp_f16_573 = -_table_sinf((f32) sp460 + temp_f16_559) * (f32) sp450;
                        sp298 = MKVector(_table_sinf(temp_f16_559) * (f32) sp458, 0.0f, temp_f16_573);
                        sp2A8.operator*(var_f17_517);
                        sp98 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp2A8);
                        sp168 = 1.0f;
                        sp16C = 1.0f;
                        spA0 = this->unk588.unk8 + sp2A8.unk8;
                        sp170 = 1.0f;
                        sp174 = 1.0f;
                        sp2B8 = sp98;
                        sp2C0 = (f64) spA0;
                        sp408 = sp98;
                        sp410 = (f64) spA0;
                        sp418 = 0.0f;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 0.0f;
                        sp420 = 0.0f;
                        sp2C8 = (f64) sp168;
                        sp2D0 = (f64) sp170;
                        sp20 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                        ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(*((MKVector3 *) &sp408), *((MKVector3 *) &sp418), sp20, (MKVector4) &sp2C8);
                        var_r20_540 += 1;
                        goto loop_33;
                    }
                    var_r19_516 += 1;
                } while (var_r19_516 < 5);
                var_r19_634 = 0;
                do {
                    sp278 = KDRand_UnitVectorXZ();
                    sp88 = sp278 * 5.65986426e-315;
                    sp288 = sp88;
                    sp90 = sp278.unk8 * 800.0f;
                    sp418 = sp88;
                    sp290 = (f64) sp90;
                    sp420 = (f64) sp90;
                    temp_f1_655 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp158 = 1.0f;
                    sp15C = 1.0f;
                    sp160 = 0.2f;
                    sp164 = 1.0f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_655;
                    sp268 = (f64) sp158;
                    sp270 = (f64) sp160;
                    sp1C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    ((ZapArcFX *) gb.unk94)->Trigger(this->unk588, *((MKVector3 *) &sp418), sp1C, lit_1411, (MKVector4) &sp268);
                    var_r19_634 += 1;
                } while (var_r19_634 < 3);
                temp_f16_687 = MKVector3::up.unk8;
                var_r19_688 = 0;
                do {
                    sp248 = KDRand_UnitVectorXZ();
                    sp78 = sp248 * 5.61841903e-315;
                    sp258 = sp78;
                    sp80 = sp248.unk8 * 400.0f;
                    sp418 = sp78;
                    sp260 = (f64) sp80;
                    sp420 = (f64) sp80;
                    temp_f0_709 = 100.0f * MKRand_Float((int *) &gViewSeed, 12.0f, 16.0f);
                    sp3F8 = 1.0f;
                    sp3FC = 0.75f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = temp_f0_709;
                    sp400 = 0.75f;
                    sp404 = 1.0f;
                    sp148 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.51933903e-315;
                    sp150 = temp_f16_687 * 75.0f;
                    sp228 = sp148;
                    sp230 = (f64) sp150;
                    temp_f0_728 = M2C_FIELD(this, f64 *, 0x588) - sp228;
                    sp138 = temp_f0_728;
                    sp238 = temp_f0_728;
                    sp140 = this->unk588.unk8 - (f32) sp230;
                    sp240 = (f64) sp140;
                    ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &sp238), *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f), 0U);
                    var_r19_688 += 1;
                } while (var_r19_688 < 0xF);
                break;
            case 0x40000000:
                KDSound_Play3d(GS_DDEarthSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                temp_f17_761 = MKVector3::up.unk8;
                var_r19_764 = 0;
                do {
                    sp208 = KDRand_UnitVectorXZ();
                    sp68 = sp208 * 5.49408334e-315;
                    sp218 = sp68;
                    sp70 = sp208.unk8 * 50.0f;
                    sp418 = sp68;
                    sp220 = (f64) sp70;
                    sp420 = (f64) sp70;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                    temp_r22_789 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    sp128 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.49408334e-315;
                    sp130 = temp_f17_761 * 50.0f;
                    sp1E8 = sp128;
                    sp1F0 = (f64) sp130;
                    temp_f0_803 = M2C_FIELD(this, f64 *, 0x588) + sp1E8;
                    sp118 = temp_f0_803;
                    sp1F8 = temp_f0_803;
                    sp120 = this->unk588.unk8 + (f32) sp1F0;
                    sp200 = (f64) sp120;
                    sp18 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                    sp14 = MKRand_Int((int *) &gViewSeed, 0, 3);
                    ((FallingLeaves *) (M2C_FIELD(temp_r22_789, FallingLeaves **, 0x2BC)))->Emit(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp418), sp18, sp14, 1U);
                    var_r19_764 += 1;
                } while (var_r19_764 < 0xF);
                var_r19_836 = 0;
                do {
                    sp1C8 = KDRand_UnitVectorXZ();
                    sp58 = sp1C8 * 5.60222949e-315;
                    sp1D8 = sp58;
                    sp60 = sp1C8.unk8 * 300.0f;
                    sp418 = sp58;
                    sp1E0 = (f64) sp60;
                    sp420 = (f64) sp60;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp10 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.5f);
                    gb.EmitSmallRocks(this->unk588, *((MKVector3 *) &sp418), sp10);
                    var_r19_836 += 1;
                } while (var_r19_836 < 0x1E);
                var_r19_876 = 0;
                do {
                    sp1A8 = KDRand_UnitVectorXZ();
                    sp48 = sp1A8 * 5.61841903e-315;
                    sp1B8 = sp48;
                    sp50 = sp1A8.unk8 * 400.0f;
                    sp418 = sp48;
                    sp1C0 = (f64) sp50;
                    sp420 = (f64) sp50;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                    spC = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), spC, 0.0f);
                    var_r19_876 += 1;
                } while (var_r19_876 < 5);
                var_r19_917 = 0;
                do {
                    sp188 = KDRand_UnitVectorXZ();
                    sp38 = sp188 * 5.60222949e-315;
                    sp198 = sp38;
                    sp40 = sp188.unk8 * 300.0f;
                    sp418 = sp38;
                    sp1A0 = (f64) sp40;
                    sp420 = (f64) sp40;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                    gb.EmitCrud(this->unk588, *((MKVector3 *) &sp418), sp8);
                    var_r19_917 += 1;
                } while (var_r19_917 < 5);
                break;
            }
            var_r26_100 += 4;
            goto loop_49;
        }
    }
    DojoEnemy::Despawn(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'double'
void DojoTier2::CheckAnimEvents() {
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f32 sp430;
    f64 sp420;                                      /* compiler-managed */
    f64 sp418;                                      /* compiler-managed */
    f64 sp410;
    f64 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    M2C_UNK sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    MKVector3 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    MKVector3 sp368;
    f64 sp360;
    f64 sp358;
    MKVector3 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    MKVector3 sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
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
    MKHeap *var_r26_1068;
    MKPropDescriptor *temp_r21_1381;
    f32 temp_f0_1677;
    f32 temp_f16_1527;
    f32 temp_f16_1541;
    f32 temp_f16_1655;
    f32 temp_f17_1729;
    f32 temp_f1_1456;
    f32 temp_f1_1623;
    f32 var_f17_1485;
    f64 temp_f0_1696;
    f64 temp_f0_1771;
    s32 temp_r3_1075;
    s32 temp_r3_1500;
    s32 var_r20_1382;
    s32 var_r20_1436;
    s32 var_r20_1484;
    s32 var_r20_1602;
    s32 var_r20_1656;
    s32 var_r20_1732;
    s32 var_r20_1804;
    s32 var_r20_1844;
    s32 var_r20_1885;
    s32 var_r21_1508;
    s32 var_r22_1103;
    s32 var_r22_1158;
    s32 var_r22_1196;
    s32 var_r22_1245;
    s32 var_r22_1283;
    s32 var_r24_1383;
    void *temp_r21_1315;
    void *temp_r23_1389;
    void *temp_r23_1757;
    void *temp_r28_1069;
    void *temp_r3_1310;

    Enemy::CheckAnimEvents();
    if ((((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) && ((MKHeap *) this->unkA38->unk27C != NULL)) {
        var_r26_1068 = this->unkA38->unk27C;
        temp_r28_1069 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
loop_50:
        if ((MKHeap *) var_r26_1068->unk0 != (MKHeap *)-1U) {
            temp_r3_1075 = this->unkB20;
            switch (temp_r3_1075) {                 /* irregular */
            case 0x8000000:
                KDSound_Play3d(GS_DDFireSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r22_1103 = 0;
                do {
                    sp3C8 = KDRand_UnitVectorXZ();
                    sp108 = sp3C8 * 5.61841903e-315;
                    sp3D8 = sp108;
                    sp110 = sp3C8.unk8 * 400.0f;
                    sp418 = sp108;
                    sp3E0 = (f64) sp110;
                    sp420 = (f64) sp110;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp34 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((CrashFirePS *) gb.unk68)->Emit(this->unk588, *((MKVector3 *) &sp418), sp34);
                    sp3F8 = 1.0f;
                    sp3FC = 0.75f;
                    sp400 = 0.75f;
                    sp404 = 1.0f;
                    sp30 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((EmbersPS *) gb.unk74)->Emit(this->unk588, *((MKVector3 *) &sp418), sp30, *((MKVector4 *) &sp3F8), 0.0f);
                    var_r22_1103 += 1;
                } while (var_r22_1103 < 0x1E);
                var_r22_1158 = 0;
                do {
                    sp3A8 = KDRand_UnitVectorXZ();
                    spF8 = sp3A8 * 5.61841903e-315;
                    sp3B8 = spF8;
                    sp100 = sp3A8.unk8 * 400.0f;
                    sp418 = spF8;
                    sp3C0 = (f64) sp100;
                    sp420 = (f64) sp100;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    gb.unk240.Emit(this->unk588, *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f), 1.0f);
                    var_r22_1158 += 1;
                } while (var_r22_1158 < 0xF);
                var_r22_1196 = 0;
                do {
                    sp388 = KDRand_UnitVectorXZ();
                    spE8 = sp388 * 5.61841903e-315;
                    sp398 = spE8;
                    spF0 = sp388.unk8 * 400.0f;
                    sp418 = spE8;
                    sp3A0 = (f64) spF0;
                    sp420 = (f64) spF0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                    sp2C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), sp2C, 0.0f);
                    var_r22_1196 += 1;
                } while (var_r22_1196 < 5);
                break;
            case 0x10000000:
                KDSound_Play3d(GS_DDIceSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r22_1245 = 0;
                do {
                    sp368 = KDRand_UnitVectorXZ();
                    spD8 = sp368 * 5.60222949e-315;
                    sp378 = spD8;
                    spE0 = sp368.unk8 * 300.0f;
                    sp418 = spD8;
                    sp380 = (f64) spE0;
                    sp420 = (f64) spE0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 20.0f, 27.0f);
                    sp28 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((IceBitsPS *) (M2C_FIELD(temp_r28_1069, IceBitsPS **, 0x2B4)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp28);
                    var_r22_1245 += 1;
                } while (var_r22_1245 < 0x14);
                var_r22_1283 = 0;
                do {
                    sp348 = KDRand_UnitVectorXZ();
                    spC8 = sp348 * 5.49408334e-315;
                    sp358 = spC8;
                    spD0 = sp348.unk8 * 50.0f;
                    sp418 = spC8;
                    sp360 = (f64) spD0;
                    sp420 = (f64) spD0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                    temp_r3_1310 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
                    if (temp_r3_1310 != NULL) {
                        temp_r21_1315 = M2C_FIELD(temp_r3_1310, void **, 0x2C);
                        sp2F8 = MKVector(1.0f, 2.0f, 1.0f);
                        sp308 = MKVector(-1.0f, 0.0f, -1.0f);
                        sp318 = KDRand_Vector(sp308, sp2F8);
                        sp328.operator*(50.0f);
                        spB8 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp328);
                        M2C_FIELD(temp_r3_1310, f64 *, 0) = spB8;
                        spC0 = this->unk588.unk8 + sp328.unk8;
                        sp338 = spB8;
                        M2C_FIELD(temp_r3_1310, f64 *, 8) = (f64) spC0;
                        M2C_FIELD(temp_r3_1310, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_1310, f32 *, 0x28) = 0.0f;
                        sp340 = (f64) spC0;
                        M2C_FIELD(temp_r21_1315, f64 *, 0) = sp418;
                        M2C_FIELD(temp_r21_1315, f64 *, 8) = sp420;
                        M2C_FIELD(temp_r21_1315, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.5f, 1.5f);
                        M2C_FIELD(temp_r21_1315, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r21_1315, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
                    }
                    var_r22_1283 += 1;
                } while (var_r22_1283 < 5);
                temp_r21_1381 = (void *) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "IceCube")));
                var_r20_1382 = 0;
                var_r24_1383 = 0;
                do {
                    *(&sp3E8 + var_r24_1383) = (long) (checked_cast<PooledShatterProp *, MKProp>(temp_r21_1381->CreateInstance()));
                    temp_r23_1389 = (void *) (*(&sp3E8 + var_r24_1383));
                    if (temp_r23_1389 != NULL) {
                        M2C_FIELD(M2C_FIELD(temp_r23_1389, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *), 0x38)(temp_r23_1389, &this->unk588);
                        M2C_FIELD(M2C_FIELD(temp_r23_1389, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r23_1389);
                        M2C_FIELD(M2C_FIELD(temp_r23_1389, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r23_1389);
                        M2C_FIELD(M2C_FIELD(temp_r23_1389, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r23_1389, 0, 0, -1, 0, 1, 0);
                    }
                    var_r20_1382 += 1;
                    var_r24_1383 += 4;
                } while (var_r20_1382 < 3);
                break;
            case 0x20000000:
                KDSound_Play3d(GS_DDElecSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r20_1436 = 0;
                do {
                    sp2D8 = KDRand_UnitVectorXZ();
                    spA8 = sp2D8 * 5.65986426e-315;
                    sp2E8 = spA8;
                    spB0 = sp2D8.unk8 * 800.0f;
                    sp418 = spA8;
                    sp2F0 = (f64) spB0;
                    sp420 = (f64) spB0;
                    temp_f1_1456 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp178 = 1.0f;
                    sp17C = 1.0f;
                    sp180 = 1.0f;
                    sp184 = 1.0f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_1456;
                    sp2C8 = (f64) sp178;
                    sp2D0 = (f64) sp180;
                    sp24 = MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
                    ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp24, (MKVector4) &sp2C8);
                    var_r20_1436 += 1;
                } while (var_r20_1436 < 0xF);
                var_r20_1484 = 0;
                var_f17_1485 = 0.0f;
                sp448 = 4503601774854144.0;
                sp460 = 5.287201034e-315;
                sp438 = 5.465589745e-315;
                sp440 = 5.370091495e-315;
                do {
                    temp_r3_1500 = MKRand_Int((int *) &gViewSeed, 4, 8);
                    var_f17_1485 += (f32) sp438;
                    var_r21_1508 = 0;
                    sp430 = (f32) sp440 / (f32) (temp_r3_1500 - 1);
loop_34:
                    if (var_r21_1508 < temp_r3_1500) {
                        temp_f16_1527 = (f32) var_r21_1508 * sp430;
                        sp450 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        sp458 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        temp_f16_1541 = -_table_sinf((f32) sp460 + temp_f16_1527) * (f32) sp450;
                        sp298 = MKVector(_table_sinf(temp_f16_1527) * (f32) sp458, 0.0f, temp_f16_1541);
                        sp2A8.operator*(var_f17_1485);
                        sp98 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp2A8);
                        sp168 = 1.0f;
                        sp16C = 1.0f;
                        spA0 = this->unk588.unk8 + sp2A8.unk8;
                        sp170 = 1.0f;
                        sp174 = 1.0f;
                        sp2B8 = sp98;
                        sp2C0 = (f64) spA0;
                        sp408 = sp98;
                        sp410 = (f64) spA0;
                        sp418 = 0.0f;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 0.0f;
                        sp420 = 0.0f;
                        sp2C8 = (f64) sp168;
                        sp2D0 = (f64) sp170;
                        sp20 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                        ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(*((MKVector3 *) &sp408), *((MKVector3 *) &sp418), sp20, (MKVector4) &sp2C8);
                        var_r21_1508 += 1;
                        goto loop_34;
                    }
                    var_r20_1484 += 1;
                } while (var_r20_1484 < 5);
                var_r20_1602 = 0;
                do {
                    sp278 = KDRand_UnitVectorXZ();
                    sp88 = sp278 * 5.65986426e-315;
                    sp288 = sp88;
                    sp90 = sp278.unk8 * 800.0f;
                    sp418 = sp88;
                    sp290 = (f64) sp90;
                    sp420 = (f64) sp90;
                    temp_f1_1623 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp158 = 1.0f;
                    sp15C = 1.0f;
                    sp160 = 0.2f;
                    sp164 = 1.0f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_1623;
                    sp268 = (f64) sp158;
                    sp270 = (f64) sp160;
                    sp1C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    ((ZapArcFX *) gb.unk94)->Trigger(this->unk588, *((MKVector3 *) &sp418), sp1C, lit_1251, (MKVector4) &sp268);
                    var_r20_1602 += 1;
                } while (var_r20_1602 < 3);
                temp_f16_1655 = MKVector3::up.unk8;
                var_r20_1656 = 0;
                do {
                    sp248 = KDRand_UnitVectorXZ();
                    sp78 = sp248 * 5.61841903e-315;
                    sp258 = sp78;
                    sp80 = sp248.unk8 * 400.0f;
                    sp418 = sp78;
                    sp260 = (f64) sp80;
                    sp420 = (f64) sp80;
                    temp_f0_1677 = 100.0f * MKRand_Float((int *) &gViewSeed, 12.0f, 16.0f);
                    sp3F8 = 1.0f;
                    sp3FC = 0.75f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = temp_f0_1677;
                    sp400 = 0.75f;
                    sp404 = 1.0f;
                    sp148 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.51933903e-315;
                    sp150 = temp_f16_1655 * 75.0f;
                    sp228 = sp148;
                    sp230 = (f64) sp150;
                    temp_f0_1696 = M2C_FIELD(this, f64 *, 0x588) - sp228;
                    sp138 = temp_f0_1696;
                    sp238 = temp_f0_1696;
                    sp140 = this->unk588.unk8 - (f32) sp230;
                    sp240 = (f64) sp140;
                    ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &sp238), *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f), 0U);
                    var_r20_1656 += 1;
                } while (var_r20_1656 < 0xF);
                break;
            case 0x40000000:
                KDSound_Play3d(GS_DDEarthSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                temp_f17_1729 = MKVector3::up.unk8;
                var_r20_1732 = 0;
                do {
                    sp208 = KDRand_UnitVectorXZ();
                    sp68 = sp208 * 5.49408334e-315;
                    sp218 = sp68;
                    sp70 = sp208.unk8 * 50.0f;
                    sp418 = sp68;
                    sp220 = (f64) sp70;
                    sp420 = (f64) sp70;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                    temp_r23_1757 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    sp128 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.49408334e-315;
                    sp130 = temp_f17_1729 * 50.0f;
                    sp1E8 = sp128;
                    sp1F0 = (f64) sp130;
                    temp_f0_1771 = M2C_FIELD(this, f64 *, 0x588) + sp1E8;
                    sp118 = temp_f0_1771;
                    sp1F8 = temp_f0_1771;
                    sp120 = this->unk588.unk8 + (f32) sp1F0;
                    sp200 = (f64) sp120;
                    sp18 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                    sp14 = MKRand_Int((int *) &gViewSeed, 0, 3);
                    ((FallingLeaves *) (M2C_FIELD(temp_r23_1757, FallingLeaves **, 0x2BC)))->Emit(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp418), sp18, sp14, 1U);
                    var_r20_1732 += 1;
                } while (var_r20_1732 < 0xF);
                var_r20_1804 = 0;
                do {
                    sp1C8 = KDRand_UnitVectorXZ();
                    sp58 = sp1C8 * 5.60222949e-315;
                    sp1D8 = sp58;
                    sp60 = sp1C8.unk8 * 300.0f;
                    sp418 = sp58;
                    sp1E0 = (f64) sp60;
                    sp420 = (f64) sp60;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp10 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.5f);
                    gb.EmitSmallRocks(this->unk588, *((MKVector3 *) &sp418), sp10);
                    var_r20_1804 += 1;
                } while (var_r20_1804 < 0x1E);
                var_r20_1844 = 0;
                do {
                    sp1A8 = KDRand_UnitVectorXZ();
                    sp48 = sp1A8 * 5.61841903e-315;
                    sp1B8 = sp48;
                    sp50 = sp1A8.unk8 * 400.0f;
                    sp418 = sp48;
                    sp1C0 = (f64) sp50;
                    sp420 = (f64) sp50;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                    spC = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), spC, 0.0f);
                    var_r20_1844 += 1;
                } while (var_r20_1844 < 5);
                var_r20_1885 = 0;
                do {
                    sp188 = KDRand_UnitVectorXZ();
                    sp38 = sp188 * 5.60222949e-315;
                    sp198 = sp38;
                    sp40 = sp188.unk8 * 300.0f;
                    sp418 = sp38;
                    sp1A0 = (f64) sp40;
                    sp420 = (f64) sp40;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                    gb.EmitCrud(this->unk588, *((MKVector3 *) &sp418), sp8);
                    var_r20_1885 += 1;
                } while (var_r20_1885 < 5);
                break;
            }
            var_r26_1068 += 4;
            goto loop_50;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'double *' to 'MKVector4'
s32 DojoTier2::Spawn(SpawnPointObject *arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r3_1992;

    if (Enemy::Spawn(arg0) == 0) {
        return 0;
    }
    this->unkA44 = checked_cast<EnemySpawnPointData *, SpawnPointData>((SpawnPointData *) arg0->unk4);
    temp_r3_1992 = M2C_FIELD(this->unkA44, s32 *, 4);
    if (temp_r3_1992 & 0x08000000) {
        sp38 = 1.0f;
        sp3C = 0.1f;
        sp40 = 0.0f;
        sp44 = 1.0f;
        this->unkB20 = 0x08000000;
        sp78 = (f64) sp38;
        sp80 = (f64) sp40;
        this->unkB10->Enable(1U, (MKVector4) &sp78);
    } else if (temp_r3_1992 & 0x10000000) {
        sp28 = 0.5f;
        sp2C = 0.5f;
        sp30 = 1.0f;
        sp34 = 1.0f;
        this->unkB20 = 0x10000000;
        sp68 = (f64) sp28;
        sp70 = (f64) sp30;
        this->unkB10->Enable(1U, (MKVector4) &sp68);
    } else if (temp_r3_1992 & 0x20000000) {
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 0.0f;
        sp24 = 1.0f;
        this->unkB20 = 0x20000000;
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        this->unkB10->Enable(1U, (MKVector4) &sp58);
    } else if (temp_r3_1992 & 0x40000000) {
        sp8 = 0.25f;
        spC = 1.0f;
        sp10 = 0.25f;
        sp14 = 1.0f;
        this->unkB20 = 0x40000000;
        sp48 = (f64) sp8;
        sp50 = (f64) sp10;
        this->unkB10->Enable(1U, (MKVector4) &sp48);
    } else {
        this->unkB20 = 0;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DojoTier2::Init() {
    DojoGoal_Think *temp_r31_2099;

    Enemy::Init();
    operator new(0x58U, NULL, 0);
    temp_r31_2099 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_2099 != NULL) {
        temp_r31_2099->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_2099->unk4 = 0;
        temp_r31_2099->unk8 = 1;
        temp_r31_2099->unk9 = 0;
        temp_r31_2099->unkC = NULL;
        temp_r31_2099->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_2099->unk1C = NULL;
        temp_r31_2099->unk18 = 0;
        temp_r31_2099->unk10 = 0;
        temp_r31_2099->unk14 = 0;
        temp_r31_2099->__vptr = &__vt;
    }
    temp_r31_2099->Init((Enemy *) this);
    this->unkA3C = &temp_r31_2099->__vptr;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void DojoTier2Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void DojoTier2Descriptor::LoadDone() {
    DojoEnemyDescriptor::LoadDone();
    this->unk244.Init(&dojoTier2BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
}
#endif

void DojoTier2Descriptor::Init() {
    EnemyDescriptor::Init();
}

s32 DojoTier1::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x35C);
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'double'
void DojoTier1::Despawn(bool arg0) {
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f32 sp430;
    f64 sp420;                                      /* compiler-managed */
    f64 sp418;                                      /* compiler-managed */
    f64 sp410;
    f64 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    M2C_UNK sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    MKVector3 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    MKVector3 sp368;
    f64 sp360;
    f64 sp358;
    MKVector3 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    MKVector3 sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
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
    MKHeap *var_r26_2248;
    MKPropDescriptor *temp_r20_2561;
    f32 temp_f0_2857;
    f32 temp_f16_2707;
    f32 temp_f16_2721;
    f32 temp_f16_2835;
    f32 temp_f17_2909;
    f32 temp_f1_2636;
    f32 temp_f1_2803;
    f32 var_f17_2665;
    f64 temp_f0_2876;
    f64 temp_f0_2951;
    s32 temp_r3_2255;
    s32 temp_r3_2680;
    s32 var_r19_2562;
    s32 var_r19_2616;
    s32 var_r19_2664;
    s32 var_r19_2782;
    s32 var_r19_2836;
    s32 var_r19_2912;
    s32 var_r19_2984;
    s32 var_r19_3024;
    s32 var_r19_3065;
    s32 var_r20_2688;
    s32 var_r21_2283;
    s32 var_r21_2338;
    s32 var_r21_2376;
    s32 var_r21_2425;
    s32 var_r21_2463;
    s32 var_r23_2563;
    void *temp_r20_2495;
    void *temp_r22_2569;
    void *temp_r22_2937;
    void *temp_r28_2249;
    void *temp_r3_2490;

    if (((u8) this->unkB09 >> 7U) & 1) {
        var_r26_2248 = this->unkA38->unk27C;
        temp_r28_2249 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
loop_49:
        if ((MKHeap *) var_r26_2248->unk0 != (MKHeap *)-1U) {
            temp_r3_2255 = this->unkB20;
            switch (temp_r3_2255) {                 /* irregular */
            case 0x8000000:
                KDSound_Play3d(GS_DDFireSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r21_2283 = 0;
                do {
                    sp3C8 = KDRand_UnitVectorXZ();
                    sp108 = sp3C8 * 5.61841903e-315;
                    sp3D8 = sp108;
                    sp110 = sp3C8.unk8 * 400.0f;
                    sp418 = sp108;
                    sp3E0 = (f64) sp110;
                    sp420 = (f64) sp110;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp34 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((CrashFirePS *) gb.unk68)->Emit(this->unk588, *((MKVector3 *) &sp418), sp34);
                    sp3F8 = 1.0f;
                    sp3FC = 0.75f;
                    sp400 = 0.75f;
                    sp404 = 1.0f;
                    sp30 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((EmbersPS *) gb.unk74)->Emit(this->unk588, *((MKVector3 *) &sp418), sp30, *((MKVector4 *) &sp3F8), 0.0f);
                    var_r21_2283 += 1;
                } while (var_r21_2283 < 0x1E);
                var_r21_2338 = 0;
                do {
                    sp3A8 = KDRand_UnitVectorXZ();
                    spF8 = sp3A8 * 5.61841903e-315;
                    sp3B8 = spF8;
                    sp100 = sp3A8.unk8 * 400.0f;
                    sp418 = spF8;
                    sp3C0 = (f64) sp100;
                    sp420 = (f64) sp100;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    gb.unk240.Emit(this->unk588, *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f), 1.0f);
                    var_r21_2338 += 1;
                } while (var_r21_2338 < 0xF);
                var_r21_2376 = 0;
                do {
                    sp388 = KDRand_UnitVectorXZ();
                    spE8 = sp388 * 5.61841903e-315;
                    sp398 = spE8;
                    spF0 = sp388.unk8 * 400.0f;
                    sp418 = spE8;
                    sp3A0 = (f64) spF0;
                    sp420 = (f64) spF0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                    sp2C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), sp2C, 0.0f);
                    var_r21_2376 += 1;
                } while (var_r21_2376 < 5);
                break;
            case 0x10000000:
                KDSound_Play3d(GS_DDIceSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r21_2425 = 0;
                do {
                    sp368 = KDRand_UnitVectorXZ();
                    spD8 = sp368 * 5.60222949e-315;
                    sp378 = spD8;
                    spE0 = sp368.unk8 * 300.0f;
                    sp418 = spD8;
                    sp380 = (f64) spE0;
                    sp420 = (f64) spE0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 20.0f, 27.0f);
                    sp28 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                    ((IceBitsPS *) (M2C_FIELD(temp_r28_2249, IceBitsPS **, 0x2B4)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp28);
                    var_r21_2425 += 1;
                } while (var_r21_2425 < 0x14);
                var_r21_2463 = 0;
                do {
                    sp348 = KDRand_UnitVectorXZ();
                    spC8 = sp348 * 5.49408334e-315;
                    sp358 = spC8;
                    spD0 = sp348.unk8 * 50.0f;
                    sp418 = spC8;
                    sp360 = (f64) spD0;
                    sp420 = (f64) spD0;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                    temp_r3_2490 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
                    if (temp_r3_2490 != NULL) {
                        temp_r20_2495 = M2C_FIELD(temp_r3_2490, void **, 0x2C);
                        sp2F8 = MKVector(1.0f, 2.0f, 1.0f);
                        sp308 = MKVector(-1.0f, 0.0f, -1.0f);
                        sp318 = KDRand_Vector(sp308, sp2F8);
                        sp328.operator*(50.0f);
                        spB8 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp328);
                        M2C_FIELD(temp_r3_2490, f64 *, 0) = spB8;
                        spC0 = this->unk588.unk8 + sp328.unk8;
                        sp338 = spB8;
                        M2C_FIELD(temp_r3_2490, f64 *, 8) = (f64) spC0;
                        M2C_FIELD(temp_r3_2490, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_2490, f32 *, 0x28) = 0.0f;
                        sp340 = (f64) spC0;
                        M2C_FIELD(temp_r20_2495, f64 *, 0) = sp418;
                        M2C_FIELD(temp_r20_2495, f64 *, 8) = sp420;
                        M2C_FIELD(temp_r20_2495, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.5f, 1.5f);
                        M2C_FIELD(temp_r20_2495, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r20_2495, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
                    }
                    var_r21_2463 += 1;
                } while (var_r21_2463 < 5);
                temp_r20_2561 = (void *) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "IceCube")));
                var_r19_2562 = 0;
                var_r23_2563 = 0;
                do {
                    *(&sp3E8 + var_r23_2563) = (long) (checked_cast<PooledShatterProp *, MKProp>(temp_r20_2561->CreateInstance()));
                    temp_r22_2569 = (void *) (*(&sp3E8 + var_r23_2563));
                    if (temp_r22_2569 != NULL) {
                        M2C_FIELD(M2C_FIELD(temp_r22_2569, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *), 0x38)(temp_r22_2569, &this->unk588);
                        M2C_FIELD(M2C_FIELD(temp_r22_2569, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r22_2569);
                        M2C_FIELD(M2C_FIELD(temp_r22_2569, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r22_2569);
                        M2C_FIELD(M2C_FIELD(temp_r22_2569, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r22_2569, 0, 0, -1, 0, 1, 0);
                    }
                    var_r19_2562 += 1;
                    var_r23_2563 += 4;
                } while (var_r19_2562 < 3);
                break;
            case 0x20000000:
                KDSound_Play3d(GS_DDElecSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                var_r19_2616 = 0;
                do {
                    sp2D8 = KDRand_UnitVectorXZ();
                    spA8 = sp2D8 * 5.65986426e-315;
                    sp2E8 = spA8;
                    spB0 = sp2D8.unk8 * 800.0f;
                    sp418 = spA8;
                    sp2F0 = (f64) spB0;
                    sp420 = (f64) spB0;
                    temp_f1_2636 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp178 = 1.0f;
                    sp17C = 1.0f;
                    sp180 = 1.0f;
                    sp184 = 1.0f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_2636;
                    sp2C8 = (f64) sp178;
                    sp2D0 = (f64) sp180;
                    sp24 = MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
                    ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp24, (MKVector4) &sp2C8);
                    var_r19_2616 += 1;
                } while (var_r19_2616 < 0xF);
                var_r19_2664 = 0;
                var_f17_2665 = 0.0f;
                sp448 = 4503601774854144.0;
                sp460 = 5.287201034e-315;
                sp438 = 5.465589745e-315;
                sp440 = 5.370091495e-315;
                do {
                    temp_r3_2680 = MKRand_Int((int *) &gViewSeed, 4, 8);
                    var_f17_2665 += (f32) sp438;
                    var_r20_2688 = 0;
                    sp430 = (f32) sp440 / (f32) (temp_r3_2680 - 1);
loop_33:
                    if (var_r20_2688 < temp_r3_2680) {
                        temp_f16_2707 = (f32) var_r20_2688 * sp430;
                        sp450 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        sp458 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                        temp_f16_2721 = -_table_sinf((f32) sp460 + temp_f16_2707) * (f32) sp450;
                        sp298 = MKVector(_table_sinf(temp_f16_2707) * (f32) sp458, 0.0f, temp_f16_2721);
                        sp2A8.operator*(var_f17_2665);
                        sp98 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp2A8);
                        sp168 = 1.0f;
                        sp16C = 1.0f;
                        spA0 = this->unk588.unk8 + sp2A8.unk8;
                        sp170 = 1.0f;
                        sp174 = 1.0f;
                        sp2B8 = sp98;
                        sp2C0 = (f64) spA0;
                        sp408 = sp98;
                        sp410 = (f64) spA0;
                        sp418 = 0.0f;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 0.0f;
                        sp420 = 0.0f;
                        sp2C8 = (f64) sp168;
                        sp2D0 = (f64) sp170;
                        sp20 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                        ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(*((MKVector3 *) &sp408), *((MKVector3 *) &sp418), sp20, (MKVector4) &sp2C8);
                        var_r20_2688 += 1;
                        goto loop_33;
                    }
                    var_r19_2664 += 1;
                } while (var_r19_2664 < 5);
                var_r19_2782 = 0;
                do {
                    sp278 = KDRand_UnitVectorXZ();
                    sp88 = sp278 * 5.65986426e-315;
                    sp288 = sp88;
                    sp90 = sp278.unk8 * 800.0f;
                    sp418 = sp88;
                    sp290 = (f64) sp90;
                    sp420 = (f64) sp90;
                    temp_f1_2803 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp158 = 1.0f;
                    sp15C = 1.0f;
                    sp160 = 0.2f;
                    sp164 = 1.0f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_2803;
                    sp268 = (f64) sp158;
                    sp270 = (f64) sp160;
                    sp1C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    ((ZapArcFX *) gb.unk94)->Trigger(this->unk588, *((MKVector3 *) &sp418), sp1C, lit_1044, (MKVector4) &sp268);
                    var_r19_2782 += 1;
                } while (var_r19_2782 < 3);
                temp_f16_2835 = MKVector3::up.unk8;
                var_r19_2836 = 0;
                do {
                    sp248 = KDRand_UnitVectorXZ();
                    sp78 = sp248 * 5.61841903e-315;
                    sp258 = sp78;
                    sp80 = sp248.unk8 * 400.0f;
                    sp418 = sp78;
                    sp260 = (f64) sp80;
                    sp420 = (f64) sp80;
                    temp_f0_2857 = 100.0f * MKRand_Float((int *) &gViewSeed, 12.0f, 16.0f);
                    sp3F8 = 1.0f;
                    sp3FC = 0.75f;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = temp_f0_2857;
                    sp400 = 0.75f;
                    sp404 = 1.0f;
                    sp148 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.51933903e-315;
                    sp150 = temp_f16_2835 * 75.0f;
                    sp228 = sp148;
                    sp230 = (f64) sp150;
                    temp_f0_2876 = M2C_FIELD(this, f64 *, 0x588) - sp228;
                    sp138 = temp_f0_2876;
                    sp238 = temp_f0_2876;
                    sp140 = this->unk588.unk8 - (f32) sp230;
                    sp240 = (f64) sp140;
                    ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &sp238), *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f), 0U);
                    var_r19_2836 += 1;
                } while (var_r19_2836 < 0xF);
                break;
            case 0x40000000:
                KDSound_Play3d(GS_DDEarthSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                temp_f17_2909 = MKVector3::up.unk8;
                var_r19_2912 = 0;
                do {
                    sp208 = KDRand_UnitVectorXZ();
                    sp68 = sp208 * 5.49408334e-315;
                    sp218 = sp68;
                    sp70 = sp208.unk8 * 50.0f;
                    sp418 = sp68;
                    sp220 = (f64) sp70;
                    sp420 = (f64) sp70;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                    temp_r22_2937 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                    sp128 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.49408334e-315;
                    sp130 = temp_f17_2909 * 50.0f;
                    sp1E8 = sp128;
                    sp1F0 = (f64) sp130;
                    temp_f0_2951 = M2C_FIELD(this, f64 *, 0x588) + sp1E8;
                    sp118 = temp_f0_2951;
                    sp1F8 = temp_f0_2951;
                    sp120 = this->unk588.unk8 + (f32) sp1F0;
                    sp200 = (f64) sp120;
                    sp18 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                    sp14 = MKRand_Int((int *) &gViewSeed, 0, 3);
                    ((FallingLeaves *) (M2C_FIELD(temp_r22_2937, FallingLeaves **, 0x2BC)))->Emit(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp418), sp18, sp14, 1U);
                    var_r19_2912 += 1;
                } while (var_r19_2912 < 0xF);
                var_r19_2984 = 0;
                do {
                    sp1C8 = KDRand_UnitVectorXZ();
                    sp58 = sp1C8 * 5.60222949e-315;
                    sp1D8 = sp58;
                    sp60 = sp1C8.unk8 * 300.0f;
                    sp418 = sp58;
                    sp1E0 = (f64) sp60;
                    sp420 = (f64) sp60;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                    sp10 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.5f);
                    gb.EmitSmallRocks(this->unk588, *((MKVector3 *) &sp418), sp10);
                    var_r19_2984 += 1;
                } while (var_r19_2984 < 0x1E);
                var_r19_3024 = 0;
                do {
                    sp1A8 = KDRand_UnitVectorXZ();
                    sp48 = sp1A8 * 5.61841903e-315;
                    sp1B8 = sp48;
                    sp50 = sp1A8.unk8 * 400.0f;
                    sp418 = sp48;
                    sp1C0 = (f64) sp50;
                    sp420 = (f64) sp50;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                    spC = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                    gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), spC, 0.0f);
                    var_r19_3024 += 1;
                } while (var_r19_3024 < 5);
                var_r19_3065 = 0;
                do {
                    sp188 = KDRand_UnitVectorXZ();
                    sp38 = sp188 * 5.60222949e-315;
                    sp198 = sp38;
                    sp40 = sp188.unk8 * 300.0f;
                    sp418 = sp38;
                    sp1A0 = (f64) sp40;
                    sp420 = (f64) sp40;
                    (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                    gb.EmitCrud(this->unk588, *((MKVector3 *) &sp418), sp8);
                    var_r19_3065 += 1;
                } while (var_r19_3065 < 5);
                break;
            }
            var_r26_2248 += 4;
            goto loop_49;
        }
    }
    DojoEnemy::Despawn(arg0);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'double'
void DojoTier1::CheckAnimEvents() {
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f32 sp430;
    f64 sp420;                                      /* compiler-managed */
    f64 sp418;                                      /* compiler-managed */
    f64 sp410;
    f64 sp408;
    f32 sp404;
    f32 sp400;
    f32 sp3FC;
    f32 sp3F8;
    M2C_UNK sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    MKVector3 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    MKVector3 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    MKVector3 sp368;
    f64 sp360;
    f64 sp358;
    MKVector3 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    MKVector3 sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    MKVector3 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
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
    MKHeap *temp_r0_3210;
    MKHeap *var_r26_3216;
    MKPropDescriptor *temp_r21_3528;
    f32 temp_f0_3824;
    f32 temp_f16_3674;
    f32 temp_f16_3688;
    f32 temp_f16_3802;
    f32 temp_f17_3876;
    f32 temp_f1_3603;
    f32 temp_f1_3770;
    f32 var_f17_3632;
    f64 temp_f0_3843;
    f64 temp_f0_3918;
    s32 temp_r3_3222;
    s32 temp_r3_3647;
    s32 var_r20_3529;
    s32 var_r20_3583;
    s32 var_r20_3631;
    s32 var_r20_3749;
    s32 var_r20_3803;
    s32 var_r20_3879;
    s32 var_r20_3951;
    s32 var_r20_3991;
    s32 var_r20_4032;
    s32 var_r21_3655;
    s32 var_r22_3250;
    s32 var_r22_3305;
    s32 var_r22_3343;
    s32 var_r22_3392;
    s32 var_r22_3430;
    s32 var_r24_3530;
    void *temp_r21_3462;
    void *temp_r23_3536;
    void *temp_r23_3904;
    void *temp_r28_3203;
    void *temp_r3_3457;

    Enemy::CheckAnimEvents();
    temp_r28_3203 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) {
        temp_r0_3210 = this->unkA38->unk27C;
        if (temp_r0_3210 != NULL) {
            var_r26_3216 = temp_r0_3210;
loop_50:
            if ((MKHeap *) var_r26_3216->unk0 != (MKHeap *)-1U) {
                temp_r3_3222 = this->unkB20;
                switch (temp_r3_3222) {             /* irregular */
                case 0x8000000:
                    KDSound_Play3d(GS_DDFireSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                    var_r22_3250 = 0;
                    do {
                        sp3C8 = KDRand_UnitVectorXZ();
                        sp108 = sp3C8 * 5.61841903e-315;
                        sp3D8 = sp108;
                        sp110 = sp3C8.unk8 * 400.0f;
                        sp418 = sp108;
                        sp3E0 = (f64) sp110;
                        sp420 = (f64) sp110;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                        sp34 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                        ((CrashFirePS *) gb.unk68)->Emit(this->unk588, *((MKVector3 *) &sp418), sp34);
                        sp3F8 = 1.0f;
                        sp3FC = 0.75f;
                        sp400 = 0.75f;
                        sp404 = 1.0f;
                        sp30 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                        ((EmbersPS *) gb.unk74)->Emit(this->unk588, *((MKVector3 *) &sp418), sp30, *((MKVector4 *) &sp3F8), 0.0f);
                        var_r22_3250 += 1;
                    } while (var_r22_3250 < 0x1E);
                    var_r22_3305 = 0;
                    do {
                        sp3A8 = KDRand_UnitVectorXZ();
                        spF8 = sp3A8 * 5.61841903e-315;
                        sp3B8 = spF8;
                        sp100 = sp3A8.unk8 * 400.0f;
                        sp418 = spF8;
                        sp3C0 = (f64) sp100;
                        sp420 = (f64) sp100;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                        gb.unk240.Emit(this->unk588, *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f), 1.0f);
                        var_r22_3305 += 1;
                    } while (var_r22_3305 < 0xF);
                    var_r22_3343 = 0;
                    do {
                        sp388 = KDRand_UnitVectorXZ();
                        spE8 = sp388 * 5.61841903e-315;
                        sp398 = spE8;
                        spF0 = sp388.unk8 * 400.0f;
                        sp418 = spE8;
                        sp3A0 = (f64) spF0;
                        sp420 = (f64) spF0;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                        sp2C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                        gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), sp2C, 0.0f);
                        var_r22_3343 += 1;
                    } while (var_r22_3343 < 5);
                    break;
                case 0x10000000:
                    KDSound_Play3d(GS_DDIceSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                    var_r22_3392 = 0;
                    do {
                        sp368 = KDRand_UnitVectorXZ();
                        spD8 = sp368 * 5.60222949e-315;
                        sp378 = spD8;
                        spE0 = sp368.unk8 * 300.0f;
                        sp418 = spD8;
                        sp380 = (f64) spE0;
                        sp420 = (f64) spE0;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 20.0f, 27.0f);
                        sp28 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
                        ((IceBitsPS *) (M2C_FIELD(temp_r28_3203, IceBitsPS **, 0x2B4)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp28);
                        var_r22_3392 += 1;
                    } while (var_r22_3392 < 0x14);
                    var_r22_3430 = 0;
                    do {
                        sp348 = KDRand_UnitVectorXZ();
                        spC8 = sp348 * 5.49408334e-315;
                        sp358 = spC8;
                        spD0 = sp348.unk8 * 50.0f;
                        sp418 = spC8;
                        sp360 = (f64) spD0;
                        sp420 = (f64) spD0;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                        temp_r3_3457 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A0);
                        if (temp_r3_3457 != NULL) {
                            temp_r21_3462 = M2C_FIELD(temp_r3_3457, void **, 0x2C);
                            sp2F8 = MKVector(1.0f, 2.0f, 1.0f);
                            sp308 = MKVector(-1.0f, 0.0f, -1.0f);
                            sp318 = KDRand_Vector(sp308, sp2F8);
                            sp328.operator*(50.0f);
                            spB8 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp328);
                            M2C_FIELD(temp_r3_3457, f64 *, 0) = spB8;
                            spC0 = this->unk588.unk8 + sp328.unk8;
                            sp338 = spB8;
                            M2C_FIELD(temp_r3_3457, f64 *, 8) = (f64) spC0;
                            M2C_FIELD(temp_r3_3457, f32 *, 0x20) = 0.0f;
                            M2C_FIELD(temp_r3_3457, f32 *, 0x28) = 0.0f;
                            sp340 = (f64) spC0;
                            M2C_FIELD(temp_r21_3462, f64 *, 0) = sp418;
                            M2C_FIELD(temp_r21_3462, f64 *, 8) = sp420;
                            M2C_FIELD(temp_r21_3462, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.5f, 1.5f);
                            M2C_FIELD(temp_r21_3462, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                            M2C_FIELD(temp_r21_3462, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
                        }
                        var_r22_3430 += 1;
                    } while (var_r22_3430 < 5);
                    temp_r21_3528 = (void *) (checked_cast<ShatterableDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, void *), 0x5C)(gMK, "IceCube")));
                    var_r20_3529 = 0;
                    var_r24_3530 = 0;
                    do {
                        *(&sp3E8 + var_r24_3530) = (long) (checked_cast<PooledShatterProp *, MKProp>(temp_r21_3528->CreateInstance()));
                        temp_r23_3536 = (void *) (*(&sp3E8 + var_r24_3530));
                        if (temp_r23_3536 != NULL) {
                            M2C_FIELD(M2C_FIELD(temp_r23_3536, void **, 0x44), M2C_UNK (**)(void *, MKVector3 *), 0x38)(temp_r23_3536, &this->unk588);
                            M2C_FIELD(M2C_FIELD(temp_r23_3536, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r23_3536);
                            M2C_FIELD(M2C_FIELD(temp_r23_3536, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r23_3536);
                            M2C_FIELD(M2C_FIELD(temp_r23_3536, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r23_3536, 0, 0, -1, 0, 1, 0);
                        }
                        var_r20_3529 += 1;
                        var_r24_3530 += 4;
                    } while (var_r20_3529 < 3);
                    break;
                case 0x20000000:
                    KDSound_Play3d(GS_DDElecSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                    var_r20_3583 = 0;
                    do {
                        sp2D8 = KDRand_UnitVectorXZ();
                        spA8 = sp2D8 * 5.65986426e-315;
                        sp2E8 = spA8;
                        spB0 = sp2D8.unk8 * 800.0f;
                        sp418 = spA8;
                        sp2F0 = (f64) spB0;
                        sp420 = (f64) spB0;
                        temp_f1_3603 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                        sp178 = 1.0f;
                        sp17C = 1.0f;
                        sp180 = 1.0f;
                        sp184 = 1.0f;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_3603;
                        sp2C8 = (f64) sp178;
                        sp2D0 = (f64) sp180;
                        sp24 = MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f);
                        ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(this->unk588, *((MKVector3 *) &sp418), sp24, (MKVector4) &sp2C8);
                        var_r20_3583 += 1;
                    } while (var_r20_3583 < 0xF);
                    var_r20_3631 = 0;
                    var_f17_3632 = 0.0f;
                    sp448 = 4503601774854144.0;
                    sp460 = 5.287201034e-315;
                    sp438 = 5.465589745e-315;
                    sp440 = 5.370091495e-315;
                    do {
                        temp_r3_3647 = MKRand_Int((int *) &gViewSeed, 4, 8);
                        var_f17_3632 += (f32) sp438;
                        var_r21_3655 = 0;
                        sp430 = (f32) sp440 / (f32) (temp_r3_3647 - 1);
loop_34:
                        if (var_r21_3655 < temp_r3_3647) {
                            temp_f16_3674 = (f32) var_r21_3655 * sp430;
                            sp450 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                            sp458 = MKRand_Float((int *) &gViewSeed, 0.8f, 1.0f);
                            temp_f16_3688 = -_table_sinf((f32) sp460 + temp_f16_3674) * (f32) sp450;
                            sp298 = MKVector(_table_sinf(temp_f16_3674) * (f32) sp458, 0.0f, temp_f16_3688);
                            sp2A8.operator*(var_f17_3632);
                            sp98 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp2A8);
                            sp168 = 1.0f;
                            sp16C = 1.0f;
                            spA0 = this->unk588.unk8 + sp2A8.unk8;
                            sp170 = 1.0f;
                            sp174 = 1.0f;
                            sp2B8 = sp98;
                            sp2C0 = (f64) spA0;
                            sp408 = sp98;
                            sp410 = (f64) spA0;
                            sp418 = 0.0f;
                            (*(f32 *) ((u8 *) &sp410 + 0xc)) = 0.0f;
                            sp420 = 0.0f;
                            sp2C8 = (f64) sp168;
                            sp2D0 = (f64) sp170;
                            sp20 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
                            ((ZapPS *) (M2C_FIELD(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), ZapPS **, 0x2B8)))->Emit(*((MKVector3 *) &sp408), *((MKVector3 *) &sp418), sp20, (MKVector4) &sp2C8);
                            var_r21_3655 += 1;
                            goto loop_34;
                        }
                        var_r20_3631 += 1;
                    } while (var_r20_3631 < 5);
                    var_r20_3749 = 0;
                    do {
                        sp278 = KDRand_UnitVectorXZ();
                        sp88 = sp278 * 5.65986426e-315;
                        sp288 = sp88;
                        sp90 = sp278.unk8 * 800.0f;
                        sp418 = sp88;
                        sp290 = (f64) sp90;
                        sp420 = (f64) sp90;
                        temp_f1_3770 = MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                        sp158 = 1.0f;
                        sp15C = 1.0f;
                        sp160 = 0.2f;
                        sp164 = 1.0f;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * temp_f1_3770;
                        sp268 = (f64) sp158;
                        sp270 = (f64) sp160;
                        sp1C = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                        ((ZapArcFX *) gb.unk94)->Trigger(this->unk588, *((MKVector3 *) &sp418), sp1C, lit_884, (MKVector4) &sp268);
                        var_r20_3749 += 1;
                    } while (var_r20_3749 < 3);
                    temp_f16_3802 = MKVector3::up.unk8;
                    var_r20_3803 = 0;
                    do {
                        sp248 = KDRand_UnitVectorXZ();
                        sp78 = sp248 * 5.61841903e-315;
                        sp258 = sp78;
                        sp80 = sp248.unk8 * 400.0f;
                        sp418 = sp78;
                        sp260 = (f64) sp80;
                        sp420 = (f64) sp80;
                        temp_f0_3824 = 100.0f * MKRand_Float((int *) &gViewSeed, 12.0f, 16.0f);
                        sp3F8 = 1.0f;
                        sp3FC = 0.75f;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = temp_f0_3824;
                        sp400 = 0.75f;
                        sp404 = 1.0f;
                        sp148 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.51933903e-315;
                        sp150 = temp_f16_3802 * 75.0f;
                        sp228 = sp148;
                        sp230 = (f64) sp150;
                        temp_f0_3843 = M2C_FIELD(this, f64 *, 0x588) - sp228;
                        sp138 = temp_f0_3843;
                        sp238 = temp_f0_3843;
                        sp140 = this->unk588.unk8 - (f32) sp230;
                        sp240 = (f64) sp140;
                        ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &sp238), *((MKVector3 *) &sp418), MKRand_Float((int *) &gViewSeed, 5.0f, 10.0f), 0U);
                        var_r20_3803 += 1;
                    } while (var_r20_3803 < 0xF);
                    break;
                case 0x40000000:
                    KDSound_Play3d(GS_DDEarthSpawn, &this->unk588, 0U, -1, 0.0f, 0U);
                    temp_f17_3876 = MKVector3::up.unk8;
                    var_r20_3879 = 0;
                    do {
                        sp208 = KDRand_UnitVectorXZ();
                        sp68 = sp208 * 5.49408334e-315;
                        sp218 = sp68;
                        sp70 = sp208.unk8 * 50.0f;
                        sp418 = sp68;
                        sp220 = (f64) sp70;
                        sp420 = (f64) sp70;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                        temp_r23_3904 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                        sp128 = M2C_FIELD(&MKVector3::up, f64 *, 0) * 5.49408334e-315;
                        sp130 = temp_f17_3876 * 50.0f;
                        sp1E8 = sp128;
                        sp1F0 = (f64) sp130;
                        temp_f0_3918 = M2C_FIELD(this, f64 *, 0x588) + sp1E8;
                        sp118 = temp_f0_3918;
                        sp1F8 = temp_f0_3918;
                        sp120 = this->unk588.unk8 + (f32) sp1F0;
                        sp200 = (f64) sp120;
                        sp18 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                        sp14 = MKRand_Int((int *) &gViewSeed, 0, 3);
                        ((FallingLeaves *) (M2C_FIELD(temp_r23_3904, FallingLeaves **, 0x2BC)))->Emit(*((MKVector3 *) &sp1F8), *((MKVector3 *) &sp418), sp18, sp14, 1U);
                        var_r20_3879 += 1;
                    } while (var_r20_3879 < 0xF);
                    var_r20_3951 = 0;
                    do {
                        sp1C8 = KDRand_UnitVectorXZ();
                        sp58 = sp1C8 * 5.60222949e-315;
                        sp1D8 = sp58;
                        sp60 = sp1C8.unk8 * 300.0f;
                        sp418 = sp58;
                        sp1E0 = (f64) sp60;
                        sp420 = (f64) sp60;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 8.0f, 12.0f);
                        sp10 = MKRand_Float((int *) &gViewSeed, 0.1f, 0.5f);
                        gb.EmitSmallRocks(this->unk588, *((MKVector3 *) &sp418), sp10);
                        var_r20_3951 += 1;
                    } while (var_r20_3951 < 0x1E);
                    var_r20_3991 = 0;
                    do {
                        sp1A8 = KDRand_UnitVectorXZ();
                        sp48 = sp1A8 * 5.61841903e-315;
                        sp1B8 = sp48;
                        sp50 = sp1A8.unk8 * 400.0f;
                        sp418 = sp48;
                        sp1C0 = (f64) sp50;
                        sp420 = (f64) sp50;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 1.0f, 8.0f);
                        spC = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                        gb.EmitDust(this->unk588, *((MKVector3 *) &sp418), spC, 0.0f);
                        var_r20_3991 += 1;
                    } while (var_r20_3991 < 5);
                    var_r20_4032 = 0;
                    do {
                        sp188 = KDRand_UnitVectorXZ();
                        sp38 = sp188 * 5.60222949e-315;
                        sp198 = sp38;
                        sp40 = sp188.unk8 * 300.0f;
                        sp418 = sp38;
                        sp1A0 = (f64) sp40;
                        sp420 = (f64) sp40;
                        (*(f32 *) ((u8 *) &sp410 + 0xc)) = 100.0f * MKRand_Float((int *) &gViewSeed, 2.0f, 4.0f);
                        sp8 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                        gb.EmitCrud(this->unk588, *((MKVector3 *) &sp418), sp8);
                        var_r20_4032 += 1;
                    } while (var_r20_4032 < 5);
                    break;
                }
                var_r26_3216 += 4;
                goto loop_50;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'double *' to 'MKVector4'
s32 DojoTier1::Spawn(SpawnPointObject *arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r3_4139;

    if (Enemy::Spawn(arg0) == 0) {
        return 0;
    }
    this->unkA44 = checked_cast<EnemySpawnPointData *, SpawnPointData>((SpawnPointData *) arg0->unk4);
    temp_r3_4139 = M2C_FIELD(this->unkA44, s32 *, 4);
    if (temp_r3_4139 & 0x08000000) {
        sp38 = 1.0f;
        sp3C = 0.1f;
        sp40 = 0.0f;
        sp44 = 1.0f;
        this->unkB20 = 0x08000000;
        sp78 = (f64) sp38;
        sp80 = (f64) sp40;
        this->unkB10->Enable(1U, (MKVector4) &sp78);
    } else if (temp_r3_4139 & 0x10000000) {
        sp28 = 0.5f;
        sp2C = 0.5f;
        sp30 = 1.0f;
        sp34 = 1.0f;
        this->unkB20 = 0x10000000;
        sp68 = (f64) sp28;
        sp70 = (f64) sp30;
        this->unkB10->Enable(1U, (MKVector4) &sp68);
    } else if (temp_r3_4139 & 0x20000000) {
        sp18 = 1.0f;
        sp1C = 1.0f;
        sp20 = 0.0f;
        sp24 = 1.0f;
        this->unkB20 = 0x20000000;
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        this->unkB10->Enable(1U, (MKVector4) &sp58);
    } else if (temp_r3_4139 & 0x40000000) {
        sp8 = 0.25f;
        spC = 1.0f;
        sp10 = 0.25f;
        sp14 = 1.0f;
        this->unkB20 = 0x40000000;
        sp48 = (f64) sp8;
        sp50 = (f64) sp10;
        this->unkB10->Enable(1U, (MKVector4) &sp48);
    } else {
        this->unkB20 = 0;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void DojoTier1::Init() {
    DojoGoal_Think *temp_r31_4246;

    Enemy::Init();
    operator new(0x58U, NULL, 0);
    temp_r31_4246 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_4246 != NULL) {
        temp_r31_4246->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_4246->unk4 = 0;
        temp_r31_4246->unk8 = 1;
        temp_r31_4246->unk9 = 0;
        temp_r31_4246->unkC = NULL;
        temp_r31_4246->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_4246->unk1C = NULL;
        temp_r31_4246->unk18 = 0;
        temp_r31_4246->unk10 = 0;
        temp_r31_4246->unk14 = 0;
        temp_r31_4246->__vptr = &__vt;
    }
    temp_r31_4246->Init((Enemy *) this);
    this->unkA3C = &temp_r31_4246->__vptr;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void DojoTier1Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void DojoTier1Descriptor::LoadDone() {
    DojoEnemyDescriptor::LoadDone();
    this->unk244.Init(&dojoTier1BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: ')' expected
void DojoEnemy::Message(MKMessage *arg0) {
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;
    s32 temp_r0_4331;
    s32 var_r29_4383;
    u32 **temp_r3_4350;
    u32 *var_r3_4353;
    u32 temp_r0_4362;
    void *temp_r28_4392;
    void *temp_r30_4375;
    void *temp_r3_4340;
    void *temp_r3_4385;
    void *temp_r3_4389;
    void *temp_r3_4395;

    temp_r0_4331 = arg0->unk0;
    switch (temp_r0_4331) {                         /* irregular */
    case 5:
        temp_r3_4340 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_4340, s32 *, 0x38) == 3) {
            M2C_FIELD(temp_r3_4340, f32 *, 0x34) = 1000.0f;
        }
        break;
    case 4:
        temp_r3_4350 = M2C_FIELD(checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0), u32 ***, 0x34);
        if (temp_r3_4350 != NULL) {
            var_r3_4353 = *temp_r3_4350;
loop_11:
            temp_r0_4362 = *var_r3_4353;
            if (temp_r0_4362 == 0U) {
                var_r3_4353 = NULL;
            } else if (temp_r0_4362 == this) {

            } else {
                var_r3_4353 += 4;
                goto loop_11;
            }
            if ((var_r3_4353 == NULL) && ((void *) this->unkA00 != NULL)) {
                temp_r30_4375 = checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                KDSound_Play3d(GS_DojoDummy01Extra1, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                var_r29_4383 = 0;
                do {
                    temp_r3_4385 = M2C_FIELD(temp_r30_4375, void **, 0x2C0);
                    temp_r3_4389 = M2C_FIELD(M2C_FIELD(temp_r3_4385, void **, 0x44), void *(**)(void *), 0x3C)(temp_r3_4385);
                    if (temp_r3_4389 != NULL) {
                        temp_r28_4392 = M2C_FIELD(temp_r3_4389, void **, 0x2C);
                        temp_r3_4395 = ((CharacterBodyFX *) this->unkA00)->GetRandomNode(NULL);
                        M2C_FIELD(temp_r3_4389, f64 *, 0) = (f64) M2C_FIELD(temp_r3_4395, f64 *, 8);
                        M2C_FIELD(temp_r3_4389, f64 *, 8) = (f64) M2C_FIELD(temp_r3_4395, f64 *, 0x10);
                        M2C_FIELD(temp_r3_4389, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_4389, f32 *, 0x28) = 0.0f;
                        sp18 = MKVector(1.0f, 0.5f, 1.0f);
                        sp28 = MKVector(-1.0f, 0.25f, -1.0f);
                        sp38 = KDRand_Vector(sp28, sp18);
                        sp8 = sp38 * 5.634608575e-315;
                        M2C_FIELD(temp_r28_4392, f64 *, 0) = sp8;
                        sp10 = sp38.unk8 * 500.0f;
                        sp48 = sp8;
                        sp50 = (f64) sp10;
                        M2C_FIELD(temp_r28_4392, f64 *, 8) = (f64) sp10;
                        M2C_FIELD(temp_r28_4392, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.15f, 0.31f);
                        M2C_FIELD(temp_r28_4392, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r28_4392, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_r30_4375, void **, 0x2C0), f32 *, 0xF4);
                    }
                    var_r29_4383 += 1;
                } while (var_r29_4383 < 0xA);
            }
        }
        break;
    }
    Enemy::Message(arg0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'double *' to 'MKVector4'
void DojoEnemy::Despawn(bool arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    Enemy::Despawn(arg0);
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unkB10->Enable(0U, (MKVector4) &sp18);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2A8'
void DojoEnemy::Deinit() {
    gb.unk2A8.DestroyInstance((CharacterBodyFX *) this->unkB10);
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2A8'
s32 DojoEnemy::LoadDone() {
    CharacterDojoFX *temp_r3_4533;
    s32 temp_r31_4530;

    Enemy::LoadDone();
    this->unkB10 = checked_cast<CharacterDojoFX *, CharacterBodyFX>(gb.unk2A8.CreateInstance(4));
    temp_r31_4530 = M2C_FIELD(this->unkA00, s32 *, 4);
    temp_r3_4533 = this->unkB10;
    temp_r3_4533->InitData(checked_cast<DojoEnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + 0x244, this->unk4, temp_r31_4530);
}
#endif

void DojoEnemy::SetDefaults() {
    Enemy::SetDefaults();
}

void DojoEnemy::Recycle() {
    Enemy::Recycle();
}

void DojoEnemyDescriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk2B4 = (long) (checked_cast<IceBitsPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("IceBitsPS")));
    this->unk2B8 = (long) (checked_cast<ZapPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("ZapPS")));
    this->unk2BC = (long) (checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves")));
    this->unk2C0 = (long) (checked_cast<KDEnvParticleSystem *, MKProp>(((MKSceneManager *) gMK)->CreateProp("DojoStuffing")));
    this->unk204 = &dojoMovementAnims;
    this->unk208 = 0xC;
}

#if 0 // DRAFT: undefined identifier 'dojoTier1BodyFXInit'
void Enemies_Dojo_cpp::__sinit() {
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
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x10) = (f64) sp378;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x18) = (f64) sp380;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x20) = (f64) sp368;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x28) = (f64) sp370;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x40) = (f64) sp358;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x48) = (f64) sp360;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x50) = (f64) sp348;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x58) = (f64) sp350;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x70) = (f64) sp338;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x78) = (f64) sp340;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x80) = (f64) sp328;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x88) = (f64) sp330;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xA0) = (f64) sp318;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xA8) = (f64) sp320;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xB0) = (f64) sp308;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xB8) = (f64) sp310;
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
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xD0) = (f64) sp2F8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xD8) = (f64) sp300;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xE0) = (f64) sp2E8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0xE8) = (f64) sp2F0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x100) = (f64) sp2D8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x108) = (f64) sp2E0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x110) = (f64) sp2C8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x118) = (f64) sp2D0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x130) = (f64) sp2B8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x138) = (f64) sp2C0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x140) = (f64) sp2A8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x148) = (f64) sp2B0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x160) = (f64) sp298;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x168) = (f64) sp2A0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x170) = (f64) sp288;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x178) = (f64) sp290;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x190) = (f64) sp278;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x198) = (f64) sp280;
    sp270 = 0.0f;
    sp260 = 1.5f;
    sp250 = 0.0f;
    sp240 = 2.0f;
    sp230 = 0.0f;
    sp220 = 2.0f;
    sp210 = 0.0f;
    sp200 = 1.0f;
    sp268 = 0.0f;
    sp26C = 0.0f;
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
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1A0) = (f64) sp268;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1A8) = (f64) sp270;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1C0) = (f64) sp258;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1C8) = (f64) sp260;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1D0) = (f64) sp248;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1D8) = (f64) sp250;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1F0) = (f64) sp238;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x1F8) = (f64) sp240;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x200) = (f64) sp228;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x208) = (f64) sp230;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x220) = (f64) sp218;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x228) = (f64) sp220;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x230) = (f64) sp208;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x238) = (f64) sp210;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x250) = (f64) sp1F8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x258) = (f64) sp200;
    sp1E8 = 0.0f;
    sp1EC = 0.0f;
    sp1F0 = 0.0f;
    sp1E0 = 1.0f;
    sp1D0 = 0.0f;
    sp1C0 = 1.0f;
    sp1B0 = 0.0f;
    sp1A0 = 1.0f;
    sp190 = 0.0f;
    sp180 = 2.0f;
    sp170 = 0.0f;
    sp1D8 = 1.0f;
    sp1DC = 1.0f;
    sp1C8 = 0.0f;
    sp1CC = 0.0f;
    sp1B8 = 1.0f;
    sp1BC = 1.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 1.0f;
    sp19C = 1.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp178 = 2.0f;
    sp17C = 2.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x260) = (f64) sp1E8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x268) = (f64) sp1F0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x280) = (f64) sp1D8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x288) = (f64) sp1E0;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x290) = (f64) sp1C8;
    M2C_FIELD(&dojoTier1BodyFXInit, f64 *, 0x298) = (f64) sp1D0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x10) = (f64) sp1B8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x18) = (f64) sp1C0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x20) = (f64) sp1A8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x28) = (f64) sp1B0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x40) = (f64) sp198;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x48) = (f64) sp1A0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x50) = (f64) sp188;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x58) = (f64) sp190;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x70) = (f64) sp178;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x78) = (f64) sp180;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x80) = (f64) sp168;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x88) = (f64) sp170;
    sp160 = 1.0f;
    sp150 = 0.0f;
    sp140 = 1.0f;
    sp130 = 0.0f;
    sp120 = 1.0f;
    sp110 = 0.0f;
    sp100 = 1.0f;
    spF0 = 0.0f;
    sp158 = 1.0f;
    sp15C = 1.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp138 = 1.0f;
    sp13C = 1.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 1.0f;
    sp11C = 1.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    spF8 = 1.0f;
    spFC = 1.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xA0) = (f64) sp158;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xA8) = (f64) sp160;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xB0) = (f64) sp148;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xB8) = (f64) sp150;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xD0) = (f64) sp138;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xD8) = (f64) sp140;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xE0) = (f64) sp128;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0xE8) = (f64) sp130;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x100) = (f64) sp118;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x108) = (f64) sp120;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x110) = (f64) sp108;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x118) = (f64) sp110;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x130) = (f64) spF8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x138) = (f64) sp100;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x140) = (f64) spE8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x148) = (f64) spF0;
    spD8 = 1.0f;
    spDC = 1.0f;
    spE0 = 1.0f;
    spD0 = 0.0f;
    spC0 = 1.5f;
    spB0 = 0.0f;
    spA0 = 1.5f;
    sp90 = 0.0f;
    sp80 = 2.0f;
    sp70 = 0.0f;
    sp60 = 2.0f;
    sp50 = 0.0f;
    sp40 = 1.0f;
    sp30 = 0.0f;
    sp20 = 1.0f;
    sp10 = 0.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spB8 = 1.5f;
    spBC = 1.5f;
    spA8 = 0.0f;
    spAC = 0.0f;
    sp98 = 1.5f;
    sp9C = 1.5f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 2.0f;
    sp7C = 2.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp58 = 2.0f;
    sp5C = 2.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 1.0f;
    sp3C = 1.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x160) = (f64) spD8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x168) = (f64) spE0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x170) = (f64) spC8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x178) = (f64) spD0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x190) = (f64) spB8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x198) = (f64) spC0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1A0) = (f64) spA8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1A8) = (f64) spB0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1C0) = (f64) sp98;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1C8) = (f64) spA0;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1D0) = (f64) sp88;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1D8) = (f64) sp90;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1F0) = (f64) sp78;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x1F8) = (f64) sp80;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x200) = (f64) sp68;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x208) = (f64) sp70;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x220) = (f64) sp58;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x228) = (f64) sp60;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x230) = (f64) sp48;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x238) = (f64) sp50;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x250) = (f64) sp38;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x258) = (f64) sp40;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x260) = (f64) sp28;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x268) = (f64) sp30;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x280) = (f64) sp18;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x288) = (f64) sp20;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x290) = (f64) sp8;
    M2C_FIELD(&dojoTier2BodyFXInit, f64 *, 0x298) = (f64) sp10;
}
#endif

#include "spyro/source/FuryFXEarth.h"
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
#include "common/gc/System_GC.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
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
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/SquishBoulder.h"
#include "spyro/source/SuckeyPS.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/WindFX.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern s32 GS_SpyroFuryEarth1;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

static s32 lit_778 = 0;
static u8 lit_779 = 0;

static s32 lit_783 = 0;
static u8 lit_784 = 1;

#if 0 // DRAFT: undefined identifier 'unk0'
void FuryFXEarth::TriggerBoulders() {
    f64 sp138;
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;
    f64 sp120;
    f64 sp118;
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
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
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
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    MKProp *temp_r27_232;
    MKProp *temp_r3_233;
    MKProp *temp_r3_301;
    SquishBoulder *temp_r29_306;
    SquishBoulder *temp_r31_238;
    SquishBoulder *temp_r3_236;
    TargetManager ***var_r29_63;
    TargetManager **temp_r31_293;
    f32 temp_f1_259;
    f32 temp_f1_314;
    f32 temp_f1_362;
    f32 temp_f30_310;
    f32 var_f3_209;
    f32 var_f4_142;
    f64 temp_f0_254;
    f64 temp_f0_325;
    f64 temp_f0_356;
    f64 temp_f1_117;
    f64 temp_f1_148;
    f64 temp_f1_154;
    f64 temp_f1_158;
    f64 temp_f1_242;
    s32 temp_r3_177;
    s32 var_r0_187;
    s32 var_r27_297;
    s32 var_r30_60;
    void *temp_r3_116;
    void *temp_r4_240;
    void *temp_r7_272;

    var_r30_60 = 0;
    var_r29_63 = gb.unk20->Begin();
loop_31:
    if (var_r29_63 != NULL) {
        temp_r31_293 = *var_r29_63;
        if (temp_r31_293 != NULL) {
            if (((*temp_r31_293)->unk8.unk0(temp_r31_293) != NULL) && (M2C_FIELD(*temp_r31_293, u8 (**)(TargetManager **), 0x18)(temp_r31_293) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r31_293)->unk8.unk4)(temp_r31_293) == 0U) || ((((u32 (*)(TargetManager **)) (*temp_r31_293)->unk8.unk4)(temp_r31_293) != 0U) && (((Character *) (((Character *(*)(TargetManager **)) (*temp_r31_293)->unk8.unk4)(temp_r31_293)))->IsActive() != 0) && (((Enemy *) (((Enemy *(*)(TargetManager **)) (*temp_r31_293)->unk8.unk4)(temp_r31_293)))->IsSpawning() == 0)))) {
                temp_r3_116 = (*temp_r31_293)->unk8.unk0(temp_r31_293)->unk8;
                temp_f1_117 = M2C_FIELD(temp_r3_116, f64 *, 0x30);
                spF0 = temp_f1_117;
                spF8 = M2C_FIELD(temp_r3_116, f64 *, 0x38);
                sp80 = temp_f1_117 - M2C_FIELD(this, f64 *, 0x110);
                sp130 = sp80;
                sp88 = (f32) spF8 - this->unk110.unk8;
                sp138 = (f64) sp88;
                var_f4_142 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + ((*(f32 *) ((u8 *) &sp128 + 0xc)) * (*(f32 *) ((u8 *) &sp128 + 0xc))));
                if (var_f4_142 > 0.000001f) {
                    if (var_f4_142 > 0.0f) {
                        temp_f1_148 = __frsqrte(var_f4_142);
                        temp_f1_154 = 0.5 * temp_f1_148 * -(((f64) var_f4_142 * (temp_f1_148 * temp_f1_148)) - 3.0);
                        temp_f1_158 = 0.5 * temp_f1_154 * -(((f64) var_f4_142 * (temp_f1_154 * temp_f1_154)) - 3.0);
                        var_f4_142 = (f32) ((f64) var_f4_142 * (0.5 * temp_f1_158 * -(((f64) var_f4_142 * (temp_f1_158 * temp_f1_158)) - 3.0)));
                    } else if (var_f4_142 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_142 = __float_nan;
                    } else {
                        sp8 = var_f4_142;
                        temp_r3_177 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_177) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_187 = 1;
                            } else {
                                var_r0_187 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_187 = 5;
                            } else {
                                var_r0_187 = 3;
                            }
                            break;
                        default:
                            var_r0_187 = 4;
                            break;
                        }
                        if (var_r0_187 == 1) {
                            var_f4_142 = __float_nan;
                        }
                    }
                    var_f3_209 = 1.0f / var_f4_142;
                } else {
                    var_f3_209 = 0.0f;
                    var_f4_142 = 0.0f;
                }
                sp130 = (f32) sp130 * var_f3_209;
                (*(f32 *) ((u8 *) &sp128 + 0xc)) *= var_f3_209;
                M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                if (var_f4_142 == 2000.0f) {
                    temp_r27_232 = (*temp_r31_293)->unk8.unk0(temp_r31_293);
                    temp_r3_233 = this->unk1C0->CreateInstance();
                    if (temp_r3_233 != NULL) {
                        temp_r3_236 = checked_cast<SquishBoulder *, MKProp>(temp_r3_233);
                        temp_r31_238 = temp_r3_236;
                        temp_r4_240 = temp_r27_232->unk8;
                        sp74 = 2000.0f;
                        temp_f1_242 = M2C_FIELD(temp_r4_240, f64 *, 0x30);
                        sp70 = 0.0f;
                        sp78 = 0.0f;
                        spD0 = (f64) sp70;
                        spE0 = temp_f1_242;
                        spD8 = (f64) sp78;
                        spE8 = M2C_FIELD(temp_r4_240, f64 *, 0x38);
                        temp_f0_254 = temp_f1_242 + spD0;
                        sp60 = temp_f0_254;
                        temp_f1_259 = (f32) spE8 + (f32) spD8;
                        sp120 = temp_f0_254;
                        sp68 = temp_f1_259;
                        sp128 = (f64) sp68;
                        M2C_FIELD(temp_r3_236->__vptr, M2C_UNK (**)(void *, f32, f32, f64), 0x30)(temp_r4_240, temp_f1_259, (f32) spE8, (f64) sp70);
                        temp_r7_272 = temp_r27_232->unk8;
                        spC0 = M2C_FIELD(temp_r7_272, f64 *, 0x30);
                        spC8 = M2C_FIELD(temp_r7_272, f64 *, 0x38);
                        temp_r31_238->Trigger(*((MKVector3 *) &sp120), *((MKVector3 *) &spC0), 0.3f * (f32) var_r30_60, temp_r27_232);
                        var_r30_60 += 1;
                    }
                }
            }
            var_r29_63 += 4;
            goto loop_31;
        }
    }
    var_r27_297 = var_r30_60;
loop_37:
    if (var_r27_297 < 0xF) {
        temp_r3_301 = this->unk1C0->CreateInstance();
        if (temp_r3_301 != NULL) {
            temp_r29_306 = checked_cast<SquishBoulder *, MKProp>(temp_r3_301);
            temp_f30_310 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f1_314 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp58 = temp_f30_310;
            sp50 = temp_f1_314;
            sp54 = 0.0f;
            spA8 = (f64) sp58;
            spA0 = (f64) sp50;
            temp_f0_325 = spA0 * 5.717499035e-315;
            sp40 = temp_f0_325;
            spB0 = temp_f0_325;
            sp48 = (f32) spA8 * 2000.0f;
            spB8 = (f64) sp48;
            sp30 = M2C_FIELD(this, f64 *, 0x110) + temp_f0_325;
            sp28 = 0.0f;
            sp20 = 0.0f;
            sp24 = 2000.0f;
            sp38 = this->unk110.unk8 + (f32) spB8;
            sp110 = sp30;
            sp90 = (f64) sp20;
            sp118 = (f64) sp38;
            sp98 = (f64) sp28;
            temp_f0_356 = sp110 + sp90;
            sp10 = temp_f0_356;
            temp_f1_362 = (f32) sp118 + (f32) sp98;
            sp100 = temp_f0_356;
            sp18 = temp_f1_362;
            sp108 = (f64) sp18;
            temp_r29_306->Enable(temp_f1_362, (f32) sp118, sp30);
            temp_r29_306->Trigger(*((MKVector3 *) &sp100), *((MKVector3 *) &sp110), 0.3f * (f32) var_r27_297, NULL);
        }
        var_r27_297 += 1;
        goto loop_37;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2CC'
void FuryFXEarth::ResetFury() {
    s32 spC;
    s32 sp8;
    Corona *temp_r4_410;
    FallingLeaves *temp_r3_425;
    ManagedLight *temp_r4_450;
    SuckeyPS *temp_r3_445;

    SetDefaults();
    temp_r4_410 = this->unk164;
    if (temp_r4_410 != NULL) {
        temp_r4_410->unk31 &= ~0x40;
    }
    gb.unk2CC.Disable(this->unk1C4);
    this->unk1C4 = -1;
    temp_r3_425 = this->unk100;
    temp_r3_425->Disable();
    if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
        spC = 0;
        sp8 = 0x459;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    temp_r3_445 = this->unk160;
    temp_r3_445->Disable();
    temp_r4_450 = this->unk1CC;
    if (temp_r4_450 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_450, 0U);
    }
}
#endif

#if 0 // DRAFT: identifier 'FuryFXEarth::Trigger(const MKVector3 &, bool)' redeclared
s32 FuryFXEarth::Trigger(const MKVector3 &arg0, bool arg1) {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Corona *temp_r3_530;
    Corona *temp_r4_520;
    FallingLeaves *temp_r3_546;
    FallingLeaves *temp_r3_551;
    ManagedLight *temp_r3_641;
    ManagedLight *temp_r3_654;
    ManagedLight *temp_r4_616;
    SuckeyPS *temp_r3_556;
    SuckeyPS *temp_r3_561;
    f64 temp_f2_489;
    f64 temp_f3_485;
    s32 temp_r0_572;
    s32 temp_r29_595;
    s32 temp_r3_570;
    s32 var_r31_588;
    u8 var_r3_578;
    void *temp_r3_647;
    void *temp_r3_657;
    void *temp_r4_574;

    if ((s32) this->unk104 != 0) {
        return 0;
    }
    this->unk104 = 1;
    temp_f3_485 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk108 = 1.0f;
    temp_f2_489 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk90.unk20 = temp_f3_485;
    this->unk90.unk28 = temp_f2_489;
    this->unk90.unk10 = 50.0f;
    M2C_FIELD(this, f64 *, 0x110) = temp_f3_485;
    M2C_FIELD(this, f64 *, 0x118) = temp_f2_489;
    KDSound_Play3d(GS_SpyroFuryEarth1, &this->unk110, 0U, -1, 0.0f, 0U);
    M2C_STRUCT_COPY((s32) &this->unk110.unkC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unk150 = this->unk110.unk0;
    this->unk154 = this->unk110.unk4;
    this->unk158 = this->unk110.unk8;
    this->unk15C = 1.0f;
    temp_r4_520 = this->unk164;
    if (temp_r4_520 != NULL) {
        temp_r4_520->unk31 |= 0x40;
        this->unk164->unk24 = 2.0f;
        temp_r3_530 = this->unk164;
        temp_r3_530->unk0 = M2C_FIELD(this, f64 *, 0x110);
        temp_r3_530->unk8 = M2C_FIELD(this, f64 *, 0x118);
    }
    this->unk1C8 = arg1;
    this->unk1C4 = gb.unk2CC.Enable(0.5f, 0.0f, 0.0f, -1.0f);
    temp_r3_546 = this->unk100;
    temp_r3_546->Reset();
    temp_r3_551 = this->unk100;
    temp_r3_551->Enable();
    temp_r3_556 = this->unk160;
    temp_r3_556->Reset();
    temp_r3_561 = this->unk160;
    temp_r3_561->Enable();
    temp_r3_570 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
    temp_r0_572 = *(&GameData::gameData[0x70] + (temp_r3_570 + 0x7C));
    temp_r4_574 = &GameData::gameData[0x70] + (temp_r3_570 + 0x64);
    if (temp_r0_572 == 3) {
        var_r3_578 = 0;
        if (((s32) M2C_FIELD(temp_r4_574, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_574, s32 *, 4) == 3)) {
            var_r3_578 = 1;
        }
        var_r31_588 = var_r3_578 != 0;
    } else {
        var_r31_588 = *(temp_r4_574 + (temp_r0_572 * 4));
    }
    temp_r29_595 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
    this->unk168.Init(gb.unk0->GetProp(), 15.0f * gb.unk37C, 3, var_r31_588, temp_r29_595, temp_r29_595, 0, -1);
    temp_r4_616 = this->unk1CC;
    if ((temp_r4_616 != NULL) && ((u8) this->unk1C8 == 0)) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_616, 1U);
        MKVector(0.0f, 500.0f, 0.0f);
        sp8 = M2C_FIELD(this, f64 *, 0x110) + sp18;
        temp_r3_641 = this->unk1CC;
        sp28 = sp8;
        sp10 = this->unk110.unk8 + sp20;
        temp_r3_641->unk10 = sp8;
        temp_r3_641->unk18 = (f64) sp10;
        temp_r3_647 = temp_r3_641->unk3C;
        sp30 = (f64) sp10;
        if (temp_r3_647 != NULL) {
            M2C_FIELD(temp_r3_647, f64 *, 0x10) = sp8;
            M2C_FIELD(temp_r3_647, f64 *, 0x18) = (f64) sp10;
        }
        temp_r3_654 = this->unk1CC;
        temp_r3_654->unk38 = 1000.0f;
        temp_r3_657 = temp_r3_654->unk3C;
        if (temp_r3_657 != NULL) {
            M2C_FIELD(temp_r3_657, f32 *, 0x20) = 1000.0f;
            M2C_FIELD(temp_r3_657, f32 *, 0x24) = 1000000.0f;
            M2C_FIELD(temp_r3_657, f32 *, 0x28) = 0.001f;
            M2C_FIELD(temp_r3_657, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_657, f32 *, 0x24));
        }
    }
    gb.unk381 = 1;
    return 1;
}
#endif

void FuryFXEarth::SetDefaults() {
    SetDefaults();
    this->unk104 = 0;
    this->unk108 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unk2CC'
void FuryFXEarth::Deinit() {
    Corona *temp_r4_711;
    ManagedLight *temp_r4_728;

    temp_r4_711 = this->unk164;
    if (temp_r4_711 != NULL) {
        ((Coronas *) gb.unk64)->Free(temp_r4_711);
        this->unk164 = NULL;
    }
    gb.unk2CC.Disable(this->unk1C4);
    this->unk1C4 = -1;
    temp_r4_728 = this->unk1CC;
    if (temp_r4_728 != NULL) {
        ((LightManager *) gb.unk80)->FreeManagedLight(temp_r4_728);
    }
    FuryFX::Deinit();
}
#endif

void FuryFXEarth::Draw() {

}

#if 0 // DRAFT: undefined identifier 'MKVector'
void FuryFXEarth::EmitLeaves() {
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
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
    s32 sp8;
    f64 temp_f0_821;
    s32 var_r31_772;

    if (!(this->unk10C > 0.0f)) {
        var_r31_772 = 0;
        this->unk10C = 0.2f;
        do {
            MKVector(0.0f, 25.0f, 0.0f);
            sp30 = M2C_FIELD(this, f64 *, 0x110) + sp90;
            sp18 = 1.0f;
            sp28 = -1.0f;
            sp38 = this->unk110.unk8 + sp98;
            sp10 = 1.0f;
            sp14 = 1.0f;
            sp20 = -1.0f;
            sp24 = 0.0f;
            spA0 = sp30;
            spA8 = (f64) sp38;
            spC0 = sp30;
            spC8 = (f64) sp38;
            sp60 = (f64) sp10;
            sp68 = (f64) sp18;
            sp70 = (f64) sp20;
            sp78 = (f64) sp28;
            KDRand_Vector(sp80, *((MKVector3 *) &sp70));
            spB0 = M2C_BITWISE(f64, sp80);
            spB8 = (f64) sp80.unk8;
            temp_f0_821 = spB0 * 5.58344962e-315;
            sp40 = temp_f0_821;
            sp50 = temp_f0_821;
            sp48 = (f32) spB8 * 220.0f;
            sp58 = (f64) sp48;
            sp8 = MKRand_Int((int *) &gViewSeed, 0, 3);
            this->unk100->Emit(*((MKVector3 *) &spC0), *((MKVector3 *) &sp50), 2.0f, sp8, 1U);
            var_r31_772 += 1;
        } while (var_r31_772 < 0xA);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void *FuryFXEarth::Update() {
    f64 sp2A0;
    f64 sp298;
    f32 sp290;
    s32 sp28C;
    s32 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;                                      /* compiler-managed */
    f32 sp260;
    s32 sp25C;
    s32 sp258;
    f64 sp250;
    f64 sp248;
    MKVector3 sp238;
    MKVector3 sp228;
    M2C_UNK sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    MKVector3 sp1D8;
    M2C_UNK sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    MKVector3 sp188;
    MKVector3 sp178;
    M2C_UNK sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    MKVector3 sp128;
    MKVector3 sp118;
    M2C_UNK sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spC8;
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
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r3_1059;
    Corona *temp_r3_1064;
    Corona *temp_r3_963;
    Corona *temp_r3_969;
    Corona *temp_r4_1406;
    MKProp *temp_r3_1381;
    ManagedLight *temp_r3_1462;
    ManagedLight *temp_r3_1482;
    ManagedLight *temp_r4_1549;
    TargetManager ***var_r29_1246;
    TargetManager **temp_r30_1398;
    f32 temp_f1_1002;
    f32 temp_f1_1065;
    f32 temp_f1_1170;
    f32 temp_f1_1220;
    f32 temp_f1_1484;
    f32 temp_f1_1512;
    f32 temp_f31_1441;
    f32 var_f1_1424;
    f32 var_f1_975;
    f32 var_f3_1361;
    f32 var_f4_1294;
    f64 temp_f1_1269;
    f64 temp_f1_1300;
    f64 temp_f1_1306;
    f64 temp_f1_1310;
    f64 temp_f1_1385;
    s32 temp_r0_881;
    s32 temp_r3_1329;
    s32 var_r0_1339;
    s32 var_r29_1071;
    s32 var_r29_1132;
    s32 var_r29_899;
    void *temp_r3_1268;
    void *temp_r3_1468;
    void *temp_r3_1486;

    this->unk108 -= gUpdateTimeDelta;
    this->unk10C -= gUpdateTimeDelta;
    temp_r0_881 = this->unk104;
    switch (temp_r0_881) {                          /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        EmitLeaves();
        this->unk100->ApplyWind(&this->unk90);
        var_r29_899 = 0;
        do {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp238, sp228);
            sp68 = sp238 * 5.667959033e-315;
            sp248 = sp68;
            sp70 = sp238.unk8 * 900.0f;
            sp298 = sp68;
            sp250 = (f64) sp70;
            sp2A0 = (f64) sp70;
            sp18 = MKRand_Float((int *) &gViewSeed, 3.5f, 4.0f);
            spB8 = -(f32) sp298;
            spBC = -(*(f32 *) ((u8 *) &sp298 + 0x4));
            spC0 = -(f32) sp2A0;
            sp208 = (f64) spB8;
            sp210 = (f64) spC0;
            this->unk160->Emit(*((MKVector3 *) &sp298), *((MKVector3 *) &sp208), sp18, 2.0f);
            var_r29_899 += 1;
        } while (var_r29_899 < 4);
        if ((Corona *) this->unk164 != NULL) {
            temp_r3_963 = this->unk164;
            temp_r3_963->unk24 += gUpdateTimeDelta * MKRand_Float((int *) &gViewSeed, 2.0f, 2.5f);
            temp_r3_969 = this->unk164;
            temp_r3_969->unk2C += 2.0f * gUpdateTimeDelta;
        }
        var_f1_975 = this->unk108;
        if (var_f1_975 < 1.0f) {

        } else {
            var_f1_975 = 1.0f;
        }
        if (var_f1_975 > 0.0f) {

        } else {
            var_f1_975 = 0.0f;
        }
        if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
            sp28C = 0;
            temp_f1_1002 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
            sp288 = 0x458;
            sp290 = temp_f1_1002 + (0.017453292f * (30.0f * (1.0f - var_f1_975)));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp288, 0.017453292f);
        }
        if (this->unk108 <= 0.0f) {
            this->unk104 = 2;
            if ((u8) this->unk1C8 != 0) {
                this->unk108 = 3.25f;
            } else {
                this->unk108 = 1.8f;
            }
            gb.unk2CC.Disable(this->unk1C4);
            this->unk1C4 = -1;
            return;
        }
    case 0:                                         /* switch 1 */
        return;
    case 2:                                         /* switch 1 */
        EmitLeaves();
        this->unk100->ApplyWind(&this->unk90);
        if ((Corona *) this->unk164 != NULL) {
            this->unk164->unk24 = MKRand_Float((int *) &gViewSeed, 8.0f, 8.5f);
            temp_r3_1059 = this->unk164;
            temp_r3_1059->unk2C += 2.0f * gUpdateTimeDelta;
            temp_r3_1064 = this->unk164;
            temp_f1_1065 = temp_r3_1064->unk2C;
            if (temp_f1_1065 > 6.2831855f) {
                temp_r3_1064->unk2C = temp_f1_1065 - 6.2831855f;
            }
        }
        var_r29_1071 = 0;
        do {
            MKVector(1.0f, 1.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp1E8, sp1D8);
            sp58 = sp1E8 * 5.667959033e-315;
            sp1F8 = sp58;
            sp60 = sp1E8.unk8 * 900.0f;
            sp278 = sp58;
            sp200 = (f64) sp60;
            sp280 = (f64) sp60;
            sp14 = MKRand_Float((int *) &gViewSeed, 3.5f, 4.0f);
            spA8 = -(f32) sp278;
            spAC = -(*(f32 *) ((u8 *) &sp278 + 0x4));
            spB0 = -(f32) sp280;
            sp1B8 = (f64) spA8;
            sp1C0 = (f64) spB0;
            this->unk160->Emit(*((MKVector3 *) &sp278), *((MKVector3 *) &sp1B8), sp14, 2.0f);
            var_r29_1071 += 1;
        } while (var_r29_1071 < 4);
        var_r29_1132 = 0;
        do {
            MKVector(1.0f, 0.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp188, sp178);
            sp198.operator*(1500.0f);
            sp48 = M2C_FIELD(this, f64 *, 0x110) + M2C_BITWISE(f64, sp198);
            sp1A8 = sp48;
            sp50 = this->unk110.unk8 + sp198.unk8;
            sp278 = sp48;
            sp1B0 = (f64) sp50;
            sp280 = (f64) sp50;
            temp_f1_1170 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            spA0 = 0.0f;
            sp98 = 0.0f;
            sp9C = 2000.0f;
            sp10 = temp_f1_1170;
            sp158 = (f64) sp98;
            sp160 = (f64) spA0;
            gb.EmitCrud(*((MKVector3 *) &sp278), *((MKVector3 *) &sp158), sp10);
            MKVector(1.0f, 0.0f, 1.0f);
            MKVector(-1.0f, 0.0f, -1.0f);
            KDRand_Vector(sp128, sp118);
            sp138.operator*(1500.0f);
            sp38 = M2C_FIELD(this, f64 *, 0x110) + M2C_BITWISE(f64, sp138);
            sp148 = sp38;
            sp40 = this->unk110.unk8 + sp138.unk8;
            sp278 = sp38;
            sp150 = (f64) sp40;
            sp280 = (f64) sp40;
            temp_f1_1220 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
            sp90 = 0.0f;
            sp88 = 0.0f;
            sp8C = 2000.0f;
            spC = temp_f1_1220;
            spF8 = (f64) sp88;
            sp100 = (f64) sp90;
            gb.EmitSmallRocks(*((MKVector3 *) &sp278), *((MKVector3 *) &spF8), spC);
            var_r29_1132 += 1;
        } while (var_r29_1132 < 4);
        if (this->unk108 <= 0.0f) {
            var_r29_1246 = gb.unk20->Begin();
loop_59:
            if (var_r29_1246 != NULL) {
                temp_r30_1398 = *var_r29_1246;
                if (temp_r30_1398 != NULL) {
                    if (((*temp_r30_1398)->unk8.unk0(temp_r30_1398) != NULL) && (M2C_FIELD(*temp_r30_1398, u8 (**)(TargetManager **), 0x18)(temp_r30_1398) == 0)) {
                        temp_r3_1268 = (*temp_r30_1398)->unk8.unk0(temp_r30_1398)->unk8;
                        temp_f1_1269 = M2C_FIELD(temp_r3_1268, f64 *, 0x30);
                        spE8 = temp_f1_1269;
                        spF0 = M2C_FIELD(temp_r3_1268, f64 *, 0x38);
                        sp78 = temp_f1_1269 - M2C_FIELD(this, f64 *, 0x110);
                        sp268 = sp78;
                        sp80 = (f32) spF0 - this->unk110.unk8;
                        sp270 = (f64) sp80;
                        var_f4_1294 = ((f32) sp270 * (f32) sp270) + (((f32) sp268 * (f32) sp268) + ((*(f32 *) ((u8 *) &sp260 + 0xc)) * (*(f32 *) ((u8 *) &sp260 + 0xc))));
                        if (var_f4_1294 > 0.000001f) {
                            if (var_f4_1294 > 0.0f) {
                                temp_f1_1300 = __frsqrte(var_f4_1294);
                                temp_f1_1306 = 0.5 * temp_f1_1300 * -(((f64) var_f4_1294 * (temp_f1_1300 * temp_f1_1300)) - 3.0);
                                temp_f1_1310 = 0.5 * temp_f1_1306 * -(((f64) var_f4_1294 * (temp_f1_1306 * temp_f1_1306)) - 3.0);
                                var_f4_1294 = (f32) ((f64) var_f4_1294 * (0.5 * temp_f1_1310 * -(((f64) var_f4_1294 * (temp_f1_1310 * temp_f1_1310)) - 3.0)));
                            } else if (var_f4_1294 < M2C_BITWISE(f32, 0.0)) {
                                var_f4_1294 = __float_nan;
                            } else {
                                sp8 = var_f4_1294;
                                temp_r3_1329 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                switch (temp_r3_1329) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_1339 = 1;
                                    } else {
                                        var_r0_1339 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                        var_r0_1339 = 5;
                                    } else {
                                        var_r0_1339 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_1339 = 4;
                                    break;
                                }
                                if (var_r0_1339 == 1) {
                                    var_f4_1294 = __float_nan;
                                }
                            }
                            var_f3_1361 = 1.0f / var_f4_1294;
                        } else {
                            var_f3_1361 = 0.0f;
                            var_f4_1294 = 0.0f;
                        }
                        sp268 = (f32) sp268 * var_f3_1361;
                        (*(f32 *) ((u8 *) &sp260 + 0xc)) *= var_f3_1361;
                        M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
                        if (var_f4_1294 == 2000.0f) {
                            temp_r3_1381 = (*temp_r30_1398)->unk8.unk0(temp_r30_1398);
                            this->unk168.unk50 = 0;
                            temp_f1_1385 = M2C_FIELD(this, f64 *, 0x110);
                            M2C_FIELD(this, f64 *, 0x178) = temp_f1_1385;
                            M2C_FIELD(this, f64 *, 0x180) = (f64) M2C_FIELD(this, f32 *, 0x118);
                            M2C_FIELD(temp_r3_1381->__vptr, M2C_UNK (**)(BreathHitMessage *, f64), 0x2C)(&this->unk168, temp_f1_1385);
                        }
                    }
                    var_r29_1246 += 4;
                    goto loop_59;
                }
            }
            this->unk104 = 3;
            this->unk108 = 4.0f;
            temp_r4_1406 = this->unk164;
            if (temp_r4_1406 != NULL) {
                temp_r4_1406->unk31 &= ~0x40;
            }
            TriggerBoulders();
            gb.GetSpyro();
            ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetRage(3, 15.0f);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        var_f1_1424 = this->unk108;
        if (var_f1_1424 < 4.0f) {

        } else {
            var_f1_1424 = 4.0f;
        }
        if (var_f1_1424 > 0.0f) {

        } else {
            var_f1_1424 = 0.0f;
        }
        temp_f31_1441 = var_f1_1424 * 0.25f;
        if (((ManagedLight *) this->unk1CC != NULL) && ((u8) this->unk1C8 == 0)) {
            MKVector(0.0f, (500.0f * temp_f31_1441) + 500.0f, 0.0f);
            sp28 = M2C_FIELD(this, f64 *, 0x110) + spC8;
            temp_r3_1462 = this->unk1CC;
            spD8 = sp28;
            sp30 = this->unk110.unk8 + spD0;
            temp_r3_1462->unk10 = sp28;
            temp_r3_1462->unk18 = (f64) sp30;
            temp_r3_1468 = temp_r3_1462->unk3C;
            spE0 = (f64) sp30;
            if (temp_r3_1468 != NULL) {
                M2C_FIELD(temp_r3_1468, f64 *, 0x10) = sp28;
                M2C_FIELD(temp_r3_1468, f64 *, 0x18) = (f64) sp30;
            }
            temp_r3_1482 = this->unk1CC;
            temp_f1_1484 = (1.0f + temp_f31_1441) * (1000.0f * MKRand_Float((int *) &gViewSeed, 0.5f, 1.2f));
            temp_r3_1482->unk38 = temp_f1_1484;
            temp_r3_1486 = temp_r3_1482->unk3C;
            if (temp_r3_1486 != NULL) {
                M2C_FIELD(temp_r3_1486, f32 *, 0x20) = temp_f1_1484;
                M2C_FIELD(temp_r3_1486, f32 *, 0x24) = (f32) (temp_f1_1484 * temp_f1_1484);
                M2C_FIELD(temp_r3_1486, f32 *, 0x28) = (f32) (1.0f / temp_f1_1484);
                M2C_FIELD(temp_r3_1486, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_1486, f32 *, 0x24));
            }
        }
        if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && (temp_f31_1441 <= 0.25f)) {
            sp25C = 0;
            temp_f1_1512 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), f32 (**)(), 0x54)();
            sp258 = 0x458;
            sp260 = temp_f1_1512 + (0.017453292f * (30.0f * (temp_f31_1441 / 0.25f)));
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f32, f32), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp258, 30.0f, 0.017453292f);
        }
        if (this->unk108 <= 0.0f) {
            this->unk104 = 0;
            if ((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) {
                sp20 = 0;
                sp1C = 0x459;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp1C);
            }
            temp_r4_1549 = this->unk1CC;
            if ((temp_r4_1549 != NULL) && ((u8) this->unk1C8 == 0)) {
                ((LightManager *) gb.unk80)->EnableLight(temp_r4_1549, 0U);
            }
            gb.unk381 = 0;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
f32 FuryFXEarth::Resolve() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
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
    Corona *temp_r4_1613;
    ManagedLight *temp_r4_1656;

    FuryFX::Resolve();
    sp38 = 1.0f;
    sp3C = 1.0f;
    sp50 = 0.0f;
    sp40 = 1.0f;
    sp44 = 1.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp88 = (f64) sp38;
    sp90 = (f64) sp40;
    sp98 = (f64) sp48;
    spA0 = (f64) sp50;
    this->unk164 = ((Coronas *) gb.unk64)->Alloc(*((MKVector3 *) &sp98), *((MKVector4 *) &sp88), 1.0f, lit_778, lit_779);
    temp_r4_1613 = this->unk164;
    if (temp_r4_1613 != NULL) {
        temp_r4_1613->unk31 &= ~0x40;
    }
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
    sp58 = (f64) sp8;
    sp60 = (f64) sp10;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    sp80 = (f64) sp30;
    this->unk1CC = ((LightManager *) gb.unk80)->AllocManagedLight(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), *((MKVector4 *) &sp58), 300.0f, lit_783, lit_784);
    temp_r4_1656 = this->unk1CC;
    if (temp_r4_1656 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_1656, 0U);
    }
}
#endif

#if 0 // DRAFT: function call 'checked_cast(unsigned long)' does not match
void FuryFXEarth::Init() {
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
    Matrix *temp_r3_1716;
    s32 var_r29_1742;

    FuryFX::Init();
    sp10 = 0.0f;
    sp20 = 0.0f;
    sp8 = 0.0f;
    spC = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unk90.Init(1, 1.0f, *((MKVector3 *) &sp38), *((MKVector3 *) &sp28));
    this->unk90.unk18 = 400.0f;
    this->unk90.unk1C = 800.0f;
    M2C_STRUCT_COPY((s32) (this + 0xBC) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_r3_1716 = &this->unkC0;
    temp_r3_1716->RotateYaw(temp_r3_1716, 0.3926991f);
    this->unk100 = checked_cast<FallingLeaves *, MKProp>(gMK->CreateProp("FallingGlowLeaves"));
    SetDefaults();
    this->unk10C = 0.0f;
    this->unk160 = checked_cast<SuckeyPS *, MKProp>(gMK->CreateProp("SuckeyPS"));
    var_r29_1742 = 0;
    this->unk160->unk140 = (s32) &this->unk120;
    this->unk164 = NULL;
    do {
        M2C_FIELD(M2C_FIELD(gMK->CreateProp("SquishBoulder"), void **, 0x44), M2C_UNK (**)(), 0x34)();
        var_r29_1742 += 1;
    } while (var_r29_1742 < 0xF);
    this->unk1C0 = checked_cast<SquishBoulderDescriptor *, MKPropDescriptor>(gMK->FindDescriptor("SquishBoulder"));
    this->unk1C4 = -1;
    this->unk1C8 = 0;
    this->unk1CC = NULL;
}
#endif

void FuryFXEarth_cpp::__sinit() {
    f32 temp_f0_1825;
    f64 temp_f1_1806;
    f64 temp_f1_1814;
    f64 temp_f3_1794;
    f64 temp_f4_1803;
    f64 temp_f4_1811;
    f64 temp_f8_1796;

    temp_f3_1794 = __frsqrte(2014000.0);
    temp_f8_1796 = __frsqrte(380000.0);
    temp_f4_1803 = 0.5 * temp_f3_1794 * -((2014000.0 * (temp_f3_1794 * temp_f3_1794)) - 3.0);
    temp_f1_1806 = 0.5 * temp_f8_1796 * -((380000.0 * (temp_f8_1796 * temp_f8_1796)) - 3.0);
    temp_f4_1811 = 0.5 * temp_f4_1803 * -((2014000.0 * (temp_f4_1803 * temp_f4_1803)) - 3.0);
    temp_f1_1814 = 0.5 * temp_f1_1806 * -((380000.0 * (temp_f1_1806 * temp_f1_1806)) - 3.0);
    temp_f0_1825 = (f32) (380000.0 * (0.5 * temp_f1_1814 * -((380000.0 * (temp_f1_1814 * temp_f1_1814)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_1811 * -((2014000.0 * (temp_f4_1811 * temp_f4_1811)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_1825;
}

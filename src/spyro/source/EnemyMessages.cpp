#include "spyro/source/EnemyMessages.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterIceCubesFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/FireAndIceFX.h"
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
#include "spyro/source/KDInput.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

extern s32 GS_EnemyBurnLP;
extern s32 GS_EnemyHitWall;
extern s32 GS_EnemyZappedLP;
extern s32 GS_SpyroBreathConvex3;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern GameGlobals gb;

#if 0 // DRAFT: illegal operand
void Enemy::Message(MKMessage *arg0) {
    s8 sp4F6;
    s8 sp4F5;
    s8 sp4F4;
    s32 sp4F0;
    s32 sp4EC;
    s32 sp4E8;
    s32 sp4E4;
    s32 sp4E0;
    f32 sp4DC;
    f32 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    s32 sp4C0;
    s32 sp4BC;
    s32 sp4B8;
    s8 sp4B6;
    s8 sp4B5;
    s8 sp4B4;
    s32 sp4B0;
    s32 sp4AC;
    s32 sp4A8;
    s32 sp4A4;
    s32 sp4A0;
    f32 sp49C;
    f32 sp498;
    f64 sp490;
    f64 sp488;
    void *sp480;
    s32 sp47C;
    s32 sp478;
    EnemyHudData sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    MKProp sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    MKProp sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    MKVector3 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;                                      /* compiler-managed */
    f64 sp248;                                      /* compiler-managed */
    f64 sp240;                                      /* compiler-managed */
    f64 sp238;                                      /* compiler-managed */
    f64 sp230;                                      /* compiler-managed */
    f64 sp228;                                      /* compiler-managed */
    MKProp sp208;
    MKVector3 sp1F8;
    M2C_UNK sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
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
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f32 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp128;
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
    f32 spBC;
    f32 spB8;
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
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    AttackerManager *var_r3_2090;
    BreathHitMessage *temp_r3_272;
    Enemy ***temp_r4_814;
    Enemy **temp_r3_838;
    Enemy **temp_r3_842;
    Enemy **var_r3_819;
    Enemy *temp_r0_828;
    Enemy *var_r0_2300;
    Enemy *var_r4_2098;
    EnemyDamageFeedback *temp_r3_712;
    EnemyDamageFeedback *temp_r3_758;
    EnemyDescriptor *temp_r3_1966;
    EnemyDescriptor *temp_r3_2015;
    EnemyDescriptor *temp_r4_1353;
    EnemyGenerator *temp_r3_2226;
    IsInAlertRangeMsg *temp_r25_1772;
    SpawnPointObject *temp_r4_2225;
    f32 temp_f0_1462;
    f32 temp_f0_195;
    f32 temp_f1_1457;
    f32 temp_f31_1311;
    f32 temp_f31_1495;
    f32 temp_f31_2115;
    f32 temp_f31_294;
    f32 temp_f31_545;
    f32 temp_f3_208;
    f32 temp_f3_2349;
    f32 temp_f4_1445;
    f32 temp_f4_205;
    f32 temp_f5_201;
    f32 var_f31_281;
    f32 var_f5_1563;
    f64 temp_f0_1439;
    f64 temp_f0_1595;
    f64 temp_f0_315;
    f64 temp_f0_624;
    f64 temp_f0_873;
    f64 temp_f0_933;
    f64 temp_f0_945;
    f64 temp_f0_958;
    f64 temp_f0_970;
    f64 temp_f1_1432;
    f64 temp_f1_1497;
    f64 temp_f1_1757;
    f64 temp_f1_2352;
    f64 temp_f2_2351;
    f64 temp_f3_1589;
    f64 temp_f3_920;
    f64 temp_f4_1588;
    f64 temp_f4_918;
    s32 temp_cr0_eq_1881;
    s32 temp_cr0_eq_1901;
    s32 temp_r0_1562;
    s32 temp_r0_215;
    s32 temp_r0_21;
    s32 temp_r0_353;
    s32 temp_r0_412;
    s32 temp_r0_491;
    s32 temp_r0_506;
    s32 temp_r25_2291;
    s32 temp_r26_817;
    s32 temp_r29_578;
    s32 temp_r3_1354;
    s32 temp_r3_1369;
    s32 temp_r3_1395;
    s32 temp_r3_504;
    s32 temp_r5_720;
    s32 temp_r5_766;
    s32 temp_r6_1902;
    s32 var_r0_522;
    s32 var_r0_738;
    s32 var_r0_784;
    s32 var_r25_1428;
    s32 var_r26_280;
    s32 var_r4_369;
    s32 var_r6_216;
    u32 temp_r25_815;
    u32 var_r25_2136;
    u32 var_r25_354;
    u8 temp_r3_1724;
    u8 temp_r3_1789;
    u8 var_r25_2073;
    u8 var_r26_1430;
    u8 var_r27_1286;
    u8 var_r27_278;
    u8 var_r27_990;
    u8 var_r29_668;
    u8 var_r3_165;
    u8 var_r3_1869;
    u8 var_r3_512;
    u8 var_r4_1429;
    u8 var_r4_728;
    u8 var_r4_774;
    void **temp_r3_1290;
    void **temp_r3_1973;
    void **temp_r3_2029;
    void **temp_r3_2054;
    void **temp_r3_2129;
    void **temp_r3_2167;
    void **temp_r3_461;
    void *temp_r10_2348;
    void *temp_r25_2209;
    void *temp_r25_2386;
    void *temp_r29_1426;
    void *temp_r30_1899;
    void *temp_r3_1431;
    void *temp_r3_1587;
    void *temp_r3_1748;
    void *temp_r3_181;
    void *temp_r3_1880;
    void *temp_r3_191;
    void *temp_r3_2064;
    void *temp_r3_2223;
    void *temp_r3_2257;
    void *temp_r3_2298;
    void *temp_r3_2326;
    void *temp_r3_341;
    void *temp_r3_617;
    void *temp_r3_637;
    void *temp_r3_812;
    void *temp_r3_865;
    void *temp_r3_886;
    void *temp_r4_1493;
    void *temp_r4_508;
    void *temp_r6_1681;
    void *temp_r6_1756;
    void *temp_r7_1898;
    void *temp_r7_725;
    void *temp_r7_771;
    void *temp_r8_2350;

    this->unk980.Message(arg0);
    temp_r0_21 = arg0->unk0;
    switch (temp_r0_21) {                           /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        if ((IsDying() == 0) && (IsDead() == 0) && (IsFriend() == 0)) {
            var_r3_165 = 0;
            if (((s32) this->unk750.unk78 == 3) && (this->unk750.unk94 > 0.0f)) {
                var_r3_165 = 1;
            }
            if (var_r3_165 == 0) {
                IsFlinching();
                if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                    temp_r3_181 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
                    if ((u32) M2C_FIELD(temp_r3_181, u32 *, 8) != this) {
                        temp_r3_191 = this->unk8;
                        temp_f0_195 = M2C_FIELD(temp_r3_181, f32 *, 0x20) + GetCollisionRadius();
                        sp3D8 = M2C_FIELD(temp_r3_191, f64 *, 0x30);
                        sp3E0 = M2C_FIELD(temp_r3_191, f64 *, 0x38);
                        temp_f5_201 = (*(f32 *) ((u8 *) &sp3D8 + 0x4)) - M2C_FIELD(temp_r3_181, f32 *, 0x14);
                        temp_f4_205 = (f32) sp3D8 - M2C_FIELD(temp_r3_181, f32 *, 0x10);
                        temp_f3_208 = (f32) sp3E0 - M2C_FIELD(temp_r3_181, f32 *, 0x18);
                        if (((temp_f3_208 * temp_f3_208) + ((temp_f4_205 * temp_f4_205) + (temp_f5_201 * temp_f5_201))) < (temp_f0_195 * temp_f0_195)) {
                            temp_r0_215 = M2C_FIELD(temp_r3_181, s32 *, 0x30);
                            var_r6_216 = 0x1000;
                            switch (temp_r0_215) {  /* switch 2; irregular */
                            case 0:                 /* switch 2 */
                                var_r6_216 = 0x1000 | 0x10;
                                break;
                            case 1:                 /* switch 2 */
                                var_r6_216 = 0x1000 | 0x20;
                                break;
                            case 2:                 /* switch 2 */
                                var_r6_216 = 0x1000 | 0x40;
                                break;
                            case 3:                 /* switch 2 */
                                var_r6_216 = 0x1000 | 0x80;
                                break;
                            }
                            AddDamage(M2C_FIELD(temp_r3_181, f32 *, 0x2C), 0U, *(temp_r3_181 + 0x10), var_r6_216, 2, 0U, 0U, NULL, 0.0f, 1.0f);
                        }
                    }
                }
            }
        }
    default:                                        /* switch 1 */
block_409:
        Character::Message(arg0);
        return;
    case 5:                                         /* switch 1 */
        if ((IsDying() == 0) && (IsDead() == 0) && (IsFriend() == 0) && (temp_r3_272 = checked_cast<BreathHitMessage *, MKMessage>(arg0), (((u32) temp_r3_272->unk8 == this) == 0))) {
            var_r27_278 = 0;
            var_r26_280 = 0;
            var_f31_281 = 1.0f;
            sp448 = M2C_FIELD(temp_r3_272, f64 *, 0x10);
            sp450 = M2C_FIELD(temp_r3_272, f64 *, 0x18);
            if ((s32) temp_r3_272->unk38 == 3) {
                var_r27_278 = 1;
                var_r26_280 = 8;
                temp_f31_294 = GetCollisionRadius();
                sp378.GetPos();
                KDMath_Sub2D(*((MKVector3 *) &sp378.unk10), *((MKVector3 *) &sp448));
                Normalise(*((MKVector3 *) &sp378.unk20));
                ((MKVector3 *) &sp378.unk30)->operator*(temp_f31_294);
                ((MKProp *) &sp378.unk40)->GetPos();
                temp_f0_315 = sp378.unk40 + M2C_BITWISE(f64, sp378.unk30);
                sp68 = temp_f0_315;
                sp448 = temp_f0_315;
                var_f31_281 = 0.8f;
                sp70 = sp378.unk48 + M2C_BITWISE(f32, sp378.unk38);
                sp3C8 = temp_f0_315;
                sp450 = (f64) sp70;
                sp3D0 = (f64) sp70;
                if ((this->unkACC > 0.0f) && ((s32) this->unkA38->unk234 > 0)) {
                    SetArmour(0.0f);
                    Armour_Destroy();
                }
                temp_r3_341 = this->unk8;
                sp368 = M2C_FIELD(temp_r3_341, f64 *, 0x30);
                sp370 = M2C_FIELD(temp_r3_341, f64 *, 0x38);
                if (!((*(f32 *) ((u8 *) &sp368 + 0x4)) < (temp_r3_272->unk14 - 600.0f))) {
                    goto block_103;
                }
            } else {
block_103:
                temp_r0_353 = temp_r3_272->unk40;
                var_r25_354 = 1;
                switch (temp_r0_353) {              /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    var_r4_369 = GS_EnemyBurnLP;
                    var_r25_354 = 1;
                    if ((u8) gb.unk35D != 0) {
                        var_r4_369 = GS_SpyroBreathConvex3;
                    }
                    SetShockSoundEvent(var_r4_369);
                    if (var_r27_278 == 0) {
                        var_r26_280 = 5;
                    }
                    if ((((s32) temp_r3_272->unk38 == 1) || ((s32) temp_r3_272->unk3C == 3)) && (var_r27_278 == 0)) {
                        if (IsKnockedUp() != 0) {
                            if ((s32) temp_r3_272->unk3C == 3) {
                                var_r26_280 = 0;
                            } else {
                                var_r26_280 = 0xA;
                            }
                        } else {
                            var_r26_280 = 2;
                        }
                    }
                    break;
                case 1:                             /* switch 3 */
                    var_r25_354 = 2;
                    SetShockSoundEvent(GS_EnemyZappedLP);
                    temp_r0_412 = temp_r3_272->unk38;
                    if (temp_r0_412 == 1) {
                        if (IsKnockedUp() != 0) {
                            var_r26_280 = 9;
                            this->unkAF4 = 0;
                        } else if ((s32) temp_r3_272->unk3C >= 0) {
                            var_r26_280 = 2;
                        } else {
                            var_r26_280 = 1;
                        }
                    } else if ((temp_r0_412 == 0) && ((s32) temp_r3_272->unk48 != 0)) {
                        var_r26_280 = 4;
                        FindAndZapFriends(temp_r3_272);
                    } else if (var_r27_278 == 0) {
                        var_r26_280 = 4;
                    }
                    break;
                case 2:                             /* switch 3 */
                    var_r25_354 = 4;
                    if (var_r27_278 == 0) {
                        var_r26_280 = 0;
                    }
                    if ((s32) temp_r3_272->unk38 == 1) {
                        if ((IsKnockedUp() != 0) || (temp_r3_461 = this->unkA40, ((M2C_FIELD(*temp_r3_461, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_461, 0xC) == 0) == 0))) {
                            var_r26_280 = 9;
                        } else if ((this->unkAC0 >= 1.0f) || ((s32) this->unk93C != 1) || !(this->unk930 & 4)) {
                            var_r26_280 = 0;
                        } else {
                            var_r26_280 = 0xE;
                        }
                    }
                    break;
                case 3:                             /* switch 3 */
                    temp_r0_491 = temp_r3_272->unk38;
                    var_r25_354 = 8;
                    if (temp_r0_491 == 1) {
                        var_r26_280 = 1;
                    } else if (temp_r0_491 == 0) {
                        temp_r3_504 = M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5;
                        temp_r0_506 = *(&GameData::gameData[0x70] + (temp_r3_504 + 0x7C));
                        temp_r4_508 = &GameData::gameData[0x70] + (temp_r3_504 + 0x64);
                        if (temp_r0_506 == 3) {
                            var_r3_512 = 0;
                            if (((s32) M2C_FIELD(temp_r4_508, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r4_508, s32 *, 4) == 3)) {
                                var_r3_512 = 1;
                            }
                            var_r0_522 = var_r3_512 != 0;
                        } else {
                            var_r0_522 = *(temp_r4_508 + (temp_r0_506 * 4));
                        }
                        if ((var_r0_522 == 0) && (IsKnockedUp() == 0) && (var_r27_278 == 0)) {
                            var_r26_280 = 1;
                        } else {
                            var_r26_280 = 8;
                            temp_f31_545 = GetCollisionRadius();
                            sp308.GetPos();
                            KDMath_Sub2D(*((MKVector3 *) &sp308.unk10), *((MKVector3 *) &sp448));
                            Normalise(*((MKVector3 *) &sp308.unk20));
                            ((MKVector3 *) &sp308.unk30)->operator*(temp_f31_545);
                            ((MKProp *) &sp308.unk40)->GetPos();
                            sp58 = sp308.unk40 + M2C_BITWISE(f64, sp308.unk30);
                            sp358 = sp58;
                            sp60 = sp308.unk48 + M2C_BITWISE(f32, sp308.unk38);
                            temp_r29_578 = *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64));
                            sp448 = sp58;
                            sp360 = (f64) sp60;
                            sp450 = (f64) sp60;
                            var_f31_281 = (0.25f * (f32) temp_r29_578 * (temp_r3_272->unk20.Magnitude() / 5000.0f)) + 1.0f;
                        }
                    }
                    if ((var_r27_278 != 0) && ((u8) this->unkA38->unkFC != 0)) {
                        var_r26_280 = 0xC;
                    }
                    break;
                case 4:                             /* switch 3 */
                    var_r26_280 = 0xD;
                    break;
                }
                temp_r3_272->unk50 = 1;
                if ((var_r27_278 == 0) && (IsBlocking() != 0)) {
                    temp_r3_617 = this->unk8;
                    sp2D8 = M2C_FIELD(temp_r3_617, f64 *, 0x30);
                    sp2E0 = M2C_FIELD(temp_r3_617, f64 *, 0x38);
                    temp_f0_624 = sp448 - sp2D8;
                    sp108 = temp_f0_624;
                    sp2E8 = temp_f0_624;
                    sp110 = (f32) sp450 - (f32) sp2E0;
                    sp2F0 = (f64) sp110;
                    Normalise(sp2F8);
                    temp_r3_637 = this->unk8;
                    sp438 = M2C_BITWISE(f64, sp2F8);
                    sp48 = -M2C_FIELD(temp_r3_637, f32 *, 0x20);
                    sp4C = -M2C_FIELD(temp_r3_637, f32 *, 0x24);
                    sp50 = -M2C_FIELD(temp_r3_637, f32 *, 0x28);
                    sp2C8 = (f64) sp48;
                    sp440 = (f64) sp2F8.unk8;
                    sp2D0 = (f64) sp50;
                    if ((((f32) sp440 * (f32) sp2D0) + (((f32) sp438 * (f32) sp2C8) + ((*(f32 *) ((u8 *) &sp438 + 0x4)) * (*(f32 *) ((u8 *) &sp2C8 + 0x4))))) > 0.0f) {
                        var_r29_668 = 0;
                        sp428 = M2C_FIELD(temp_r3_272, f64 *, 0x10);
                        sp430 = M2C_FIELD(temp_r3_272, f64 *, 0x18);
                        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
                            var_r29_668 = 1;
                        }
                        if ((var_r29_668 != 0) && (this->unk870.GetProp() == (u32) temp_r3_272->unk8)) {
                            this->unkB08 |= 1;
                        }
                        DoBlockFx(var_r25_354, *((MKVector3 *) &sp428));
                        TriggerShieldGlow(temp_r3_272->unk40);
                        temp_r3_712 = AddDamage(1.0f, 0U, *((MKVector3 *) &sp448), (s32) var_r25_354, var_r26_280, var_r27_278, 1U, temp_r3_272->unk30, 0.0f, var_f31_281);
                        if (temp_r3_712 != NULL) {
                            temp_r3_712->unk2C = temp_r3_272->unk38;
                            temp_r5_720 = temp_r3_272->unk38;
                            temp_r7_725 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
                            if (temp_r5_720 == 3) {
                                var_r4_728 = 0;
                                if (((s32) M2C_FIELD(temp_r7_725, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r7_725, s32 *, 4) == 3)) {
                                    var_r4_728 = 1;
                                }
                                var_r0_738 = var_r4_728 != 0;
                            } else {
                                var_r0_738 = *(temp_r7_725 + (temp_r5_720 * 4));
                            }
                            temp_r3_712->unk30 = var_r0_738;
                            return;
                        }
                        goto block_180;
                    }
                }
block_180:
                temp_r3_758 = AddDamage(temp_r3_272->unk34, 0U, *((MKVector3 *) &sp448), (s32) var_r25_354, var_r26_280, var_r27_278, 0U, temp_r3_272->unk30, 0.0f, var_f31_281);
                if (temp_r3_758 != NULL) {
                    temp_r3_758->unk2C = temp_r3_272->unk38;
                    temp_r5_766 = temp_r3_272->unk38;
                    temp_r7_771 = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
                    if (temp_r5_766 == 3) {
                        var_r4_774 = 0;
                        if (((s32) M2C_FIELD(temp_r7_771, s32 *, 0) == 3) && ((s32) M2C_FIELD(temp_r7_771, s32 *, 4) == 3)) {
                            var_r4_774 = 1;
                        }
                        var_r0_784 = var_r4_774 != 0;
                    } else {
                        var_r0_784 = *(temp_r7_771 + (temp_r5_766 * 4));
                    }
                    temp_r3_758->unk30 = var_r0_784;
                }
                goto block_409;
            }
        } else {
            goto block_409;
        }
        break;
    case 4:                                         /* switch 1 */
        if ((IsDying() == 0) && (IsDead() == 0) && (IsFriend() == 0)) {
            temp_r3_812 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
            temp_r4_814 = M2C_FIELD(temp_r3_812, Enemy ****, 0x34);
            temp_r25_815 = M2C_FIELD(temp_r3_812, u32 *, 0x30);
            temp_r26_817 = M2C_FIELD(temp_r3_812, s32 *, 0x28);
            if (temp_r4_814 != NULL) {
                var_r3_819 = *temp_r4_814;
loop_196:
                temp_r0_828 = *var_r3_819;
                if (temp_r0_828 == NULL) {
                    var_r3_819 = NULL;
                } else if (temp_r0_828 == this) {

                } else {
                    var_r3_819 += 4;
                    goto loop_196;
                }
                if (var_r3_819 == NULL) {
                    goto block_199;
                }
            } else {
block_199:
                if (temp_r4_814 != NULL) {
                    temp_r3_838 = *temp_r4_814;
                    if ((u32) M2C_FIELD(temp_r3_838, u32 *, -4) != 0U) {
                        temp_r3_842 = temp_r3_838 - 4;
                        *temp_r4_814 = temp_r3_842;
                        *temp_r3_842 = this;
                    }
                }
                if ((temp_r26_817 == 9) || (temp_r26_817 == 3) || (temp_r26_817 == 0xA) || (temp_r26_817 == 8) || !(temp_r25_815 & 0xF0) || (IsKnockedUp() == 0)) {
                    if (IsBlocking() != 0) {
                        temp_r3_865 = this->unk8;
                        sp298 = M2C_FIELD(temp_r3_865, f64 *, 0x30);
                        sp2A0 = M2C_FIELD(temp_r3_865, f64 *, 0x38);
                        temp_f0_873 = M2C_FIELD(temp_r3_812, f64 *, 0x10) - sp298;
                        spF8 = temp_f0_873;
                        sp2A8 = temp_f0_873;
                        sp100 = M2C_FIELD(temp_r3_812, f32 *, 0x18) - (f32) sp2A0;
                        sp2B0 = (f64) sp100;
                        Normalise(sp2B8);
                        temp_r3_886 = this->unk8;
                        sp418 = M2C_BITWISE(f64, sp2B8);
                        sp38 = -M2C_FIELD(temp_r3_886, f32 *, 0x20);
                        sp3C = -M2C_FIELD(temp_r3_886, f32 *, 0x24);
                        sp40 = -M2C_FIELD(temp_r3_886, f32 *, 0x28);
                        sp288 = (f64) sp38;
                        sp420 = (f64) sp2B8.unk8;
                        sp290 = (f64) sp40;
                        if ((((f32) sp420 * (f32) sp290) + (((f32) sp418 * (f32) sp288) + ((*(f32 *) ((u8 *) &sp418 + 0x4)) * (*(f32 *) ((u8 *) &sp288 + 0x4))))) > 0.0f) {
                            temp_f4_918 = M2C_FIELD(temp_r3_886, f64 *, 0x30);
                            spC0 = 0.0f;
                            temp_f3_920 = M2C_FIELD(temp_r3_886, f64 *, 0x38);
                            spB8 = 0.0f;
                            spBC = 125.0f;
                            sp238 = temp_f4_918;
                            sp228 = (f64) spB8;
                            sp230 = (f64) spC0;
                            sp8 = temp_f4_918;
                            sp10 = temp_f3_920;
                            sp240 = temp_f3_920;
                            temp_f0_933 = M2C_FIELD(temp_r3_812, f64 *, 0x10) - sp238;
                            spE8 = temp_f0_933;
                            sp248 = temp_f0_933;
                            spF0 = M2C_FIELD(temp_r3_812, f32 *, 0x18) - (f32) sp240;
                            sp250 = (f64) spF0;
                            temp_f0_945 = temp_f0_933 * 5.222099017e-315;
                            spD8 = temp_f0_945;
                            sp268 = temp_f4_918;
                            sp258 = temp_f0_945;
                            spE0 = (f32) sp250 * 0.5f;
                            sp270 = temp_f3_920;
                            sp260 = (f64) spE0;
                            temp_f0_958 = sp268 + temp_f0_945;
                            spC8 = temp_f0_958;
                            sp278 = temp_f0_958;
                            spD0 = (f32) sp270 + (f32) sp260;
                            sp280 = (f64) spD0;
                            temp_f0_970 = sp278 + sp228;
                            spA8 = temp_f0_970;
                            sp408 = temp_f0_970;
                            spB0 = (f32) sp280 + (f32) sp230;
                            sp410 = (f64) spB0;
                            DoBlockFx(temp_r25_815, *((MKVector3 *) &sp408));
                            TriggerShieldGlow(M2C_FIELD(GameData::gameData, s32 *, 0x158));
                            var_r27_990 = 0;
                            M2C_FIELD(temp_r3_812, s8 *, 0x3D) = 1;
                            if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
                                var_r27_990 = 1;
                            }
                            if ((var_r27_990 != 0) && (this->unk870.GetProp() == (void **) M2C_FIELD(temp_r3_812, void ***, 8))) {
                                this->unkB08 |= 1;
                            }
                            if (this->unkAA0 > 0.0f) {
                                KDSound_Play(this->unkA38->unk18C, 0U, -1);
                                this->unkAA0 = 0.25f;
                            }
                            AddDamage(1.0f, 0U, *(temp_r3_812 + 0x10), (s32) temp_r25_815, temp_r26_817, 0U, 1U, M2C_FIELD(temp_r3_812, MKCollisionInfo **, 0x38), 0.0f, 1.0f);
                            return;
                        }
                    }
                    if (!(((u8) this->unkB02 >> 1U) & 1) && ((u32) temp_r26_817 <= 0xEU)) {
                        switch (temp_r26_817) {     /* switch 4 */
                        case 0:                     /* switch 4 */
                        case 14:                    /* switch 4 */
                            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.4f, 0.2f, 0.1f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
                            break;
                        case 1:                     /* switch 4 */
                            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.6f, 0.4f, 0.1f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
                            break;
                        case 2:                     /* switch 4 */
                            ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.8f, 0.6f, 0.15f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
                            break;
                        case 3:                     /* switch 4 */
                        case 8:                     /* switch 4 */
                            if ((((u32) arg0->unk4 == 0) || ((u32) arg0->unk4 == gb.unk0->GetProp())) && (KDSound_IsChronoSoundWarpEnabled() != 0) && (gb.unk2D0 != 1.0f)) {
                                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.99f, 0.8f, 0.15f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 1U);
                            } else {
                                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.99f, 0.8f, 0.15f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
                            }
                            break;
                        case 9:                     /* switch 4 */
                            if ((((u32) arg0->unk4 == 0) || ((u32) arg0->unk4 == gb.unk0->GetProp())) && (KDSound_IsChronoSoundWarpEnabled() != 0) && (gb.unk2D0 != 1.0f)) {
                                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.6f, 0.4f, 0.1f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 1U);
                            } else {
                                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.6f, 0.4f, 0.1f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
                            }
                            break;
                        case 10:                    /* switch 4 */
                            if ((((u32) arg0->unk4 == 0) || ((u32) arg0->unk4 == gb.unk0->GetProp())) && (KDSound_IsChronoSoundWarpEnabled() != 0) && (gb.unk2D0 != 1.0f)) {
                                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.99f, 0.8f, 0.15f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 1U);
                            } else {
                                ((KDInput *) (gb.unk0->GetInput()))->RumblePlay3D(0.99f, 0.8f, 0.15f, ((u8 *) this->unk8) + 0x30, 37.0f, 0, 4.0f, 0U);
                            }
                            break;
                        }
                    }
                    var_r27_1286 = 0;
                    sp3F8 = M2C_FIELD(temp_r3_812, f64 *, 0x10);
                    sp400 = (f64) M2C_FIELD(temp_r3_812, f32 *, 0x18);
                    temp_r3_1290 = M2C_FIELD(temp_r3_812, void ***, 8);
                    if ((temp_r3_1290 != NULL) && (temp_r25_815 & 0x100)) {
                        if (M2C_FIELD(*temp_r3_1290, s32 *, 0xC) & 8) {
                            var_r27_1286 = 1;
                            sp3F8 = M2C_FIELD(temp_r3_812, f64 *, 0x10);
                            sp400 = (f64) M2C_FIELD(temp_r3_812, f32 *, 0x18);
                        } else {
                            temp_f31_1311 = GetCollisionRadius();
                            ((MKProp *) &sp1E8)->GetDir();
                            sp1F8.operator*(temp_f31_1311);
                            sp208.GetPos();
                            sp28 = sp208 - M2C_BITWISE(f64, sp1F8);
                            sp208.unk10 = sp28;
                            sp30 = M2C_BITWISE(f32, sp208.unk8) - sp1F8.unk8;
                            sp3F8 = sp28;
                            sp208.unk18 = (f64) sp30;
                            sp400 = (f64) sp30;
                        }
                    }
                    AddDamage(M2C_FIELD(temp_r3_812, f32 *, 0x20), M2C_FIELD(temp_r3_812, u8 *, 0x3C), *((MKVector3 *) &sp3F8), (s32) temp_r25_815, temp_r26_817, 0U, 0U, M2C_FIELD(temp_r3_812, MKCollisionInfo **, 0x38), 1.0f, M2C_FIELD(temp_r3_812, f32 *, 0x24));
                    if (!(((u8) this->unkB02 >> 2U) & 1)) {
                        temp_r4_1353 = this->unkA38;
                        temp_r3_1354 = temp_r4_1353->unk188;
                        if ((temp_r3_1354 != 0) && ((u32) M2C_FIELD(temp_r3_812, u32 *, 0x30) == 0x1000)) {
                            KDSound_Play3d(temp_r3_1354, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                        } else {
                            temp_r3_1369 = temp_r4_1353->unk184;
                            if ((temp_r3_1369 != 0) && (var_r27_1286 == 0) && ((u32) M2C_FIELD(temp_r3_812, u32 *, 0x30) == 0x1000)) {
                                KDSound_Play3d(temp_r3_1369, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                            } else if ((temp_r3_1369 != 0) && (var_r27_1286 == 0)) {
                                KDSound_Play(temp_r3_1369, 0U, -1);
                            } else {
                                temp_r3_1395 = M2C_FIELD(temp_r3_812, s32 *, 0x2C);
                                if ((temp_r3_1395 > -1) && (var_r27_1286 == 0)) {
                                    KDSound_Play(temp_r3_1395, 0U, -1);
                                } else if (var_r27_1286 != 0) {
                                    KDSound_Play3d(GS_EnemyHitWall, (MKVector3 *) &sp3F8, 0U, -1, 0.0f, 0U);
                                }
                            }
                        }
                    }
                    M2C_FIELD(temp_r3_812, s8 *, 0x3E) = 1;
                    return;
                }
            }
        }
        break;
    case 164:                                       /* switch 1 */
        if (this->unkAC8 != 0.0f) {
            temp_r29_1426 = checked_cast<WhirlWindHitMsg *, MKMessage>(arg0);
            sp4BC = 0;
            var_r25_1428 = 2;
            var_r4_1429 = 0;
            var_r26_1430 = 0;
            temp_r3_1431 = this->unk8;
            temp_f1_1432 = M2C_FIELD(temp_r3_1431, f64 *, 0x30);
            sp1C8 = temp_f1_1432;
            sp1D0 = M2C_FIELD(temp_r3_1431, f64 *, 0x38);
            temp_f0_1439 = temp_f1_1432 - M2C_FIELD(temp_r29_1426, f64 *, 0x10);
            sp98 = temp_f0_1439;
            temp_f4_1445 = M2C_FIELD(temp_r29_1426, f32 *, 0x20);
            sp1D8 = temp_f0_1439;
            spA0 = (f32) sp1D0 - M2C_FIELD(temp_r29_1426, f32 *, 0x18);
            sp1E0 = (f64) spA0;
            temp_f1_1457 = ((f32) sp1E0 * (f32) sp1E0) + (((f32) sp1D8 * (f32) sp1D8) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * (*(f32 *) ((u8 *) &sp1D8 + 0x4))));
            if (temp_f1_1457 <= (temp_f4_1445 * temp_f4_1445)) {
                temp_f0_1462 = 0.5f * temp_f4_1445;
                if (temp_f1_1457 <= (temp_f0_1462 * temp_f0_1462)) {
                    var_r4_1429 = 1;
                } else {
                    var_r26_1430 = 1;
                }
            }
            if ((var_r4_1429 != 0) || (IsKnockedUp() != 0)) {
                if (IsKnockedUp() != 0) {
                    var_r25_1428 = 9;
                }
                temp_r4_1493 = this->unk8;
                temp_f31_1495 = ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(3, 1, M2C_FIELD(temp_r29_1426, s32 *, 8));
                temp_f1_1497 = M2C_FIELD(temp_r4_1493, f64 *, 0x30);
                sp1B8 = temp_f1_1497;
                sp1C0 = M2C_FIELD(temp_r4_1493, f64 *, 0x38);
                sp4C0 = gb.unk0->GetProp(temp_r4_1493, temp_f1_1497);
                sp4B8 = 4;
                sp4C8 = sp1B8;
                sp4D0 = sp1C0;
                sp4D8 = temp_f31_1495;
                sp4F4 = 0;
                sp4E0 = var_r25_1428;
                sp4E8 = 8;
                sp4F5 = 0;
                sp4F6 = 0;
                sp4E4 = -1;
                sp4EC = 0;
                sp4F0 = 0;
                sp4DC = 1.0f;
                this->unkB02 |= 4;
                this->unkB02 |= 2;
                Message(&sp4B8, 1, 8, 0, M2C_BITWISE(void *, sp1C0), sp1B8);
                this->unkB02 &= ~4;
                this->unkB02 &= ~2;
                if ((s32) M2C_FIELD(temp_r29_1426, s32 *, 8) == 3) {
                    this->unkB0A |= 2;
                } else {
                    this->unkB0A &= ~2;
                }
            } else if (var_r26_1430 != 0) {
                temp_r0_1562 = M2C_FIELD(temp_r29_1426, s32 *, 8);
                var_f5_1563 = 1.0f;
                switch (temp_r0_1562) {             /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    var_f5_1563 = 0.5f;
                    break;
                case 1:                             /* switch 5 */
                    var_f5_1563 = 0.5f;
                    break;
                case 2:                             /* switch 5 */
                    var_f5_1563 = 0.8f;
                    break;
                case 3:                             /* switch 5 */
                    var_f5_1563 = 1.2f;
                    break;
                }
                temp_r3_1587 = this->unk8;
                temp_f4_1588 = M2C_FIELD(temp_r3_1587, f64 *, 0x30);
                temp_f3_1589 = M2C_FIELD(temp_r3_1587, f64 *, 0x38);
                sp188 = temp_f4_1588;
                sp190 = temp_f3_1589;
                temp_f0_1595 = sp188 - M2C_FIELD(temp_r29_1426, f64 *, 0x10);
                sp88 = temp_f0_1595;
                sp1A8 = temp_f4_1588;
                sp198 = temp_f0_1595;
                sp90 = (f32) sp190 - M2C_FIELD(temp_r29_1426, f32 *, 0x18);
                sp1B0 = temp_f3_1589;
                sp1A0 = (f64) sp90;
                sp78 = sp1A8 + temp_f0_1595;
                sp4B8 = 4;
                sp4C0 = 0;
                sp80 = (f32) sp1B0 + (f32) sp1A0;
                sp4C8 = sp78;
                sp4D0 = (f64) sp80;
                sp4D8 = 0.0f;
                sp4F4 = 0;
                sp4E0 = 8;
                sp4E8 = 8;
                sp4F5 = 0;
                sp4F6 = 0;
                sp4E4 = -1;
                sp4EC = 0;
                sp4F0 = 0;
                sp4DC = var_f5_1563;
                sp3E8 = sp78;
                this->unkB02 |= 2;
                sp3F0 = (f64) sp80;
                Message(&sp4B8, 1, 8, 0, M2C_BITWISE(void *, (f64) sp80), sp78, M2C_BITWISE(void *, (f32) sp1B0), temp_f4_1588);
                this->unkB02 &= ~2;
            }
        }
        goto block_409;
    case 81:                                        /* switch 1 */
        if ((IsIdling() != 0) || (IsPatrolling() != 0)) {
            this->unkB0B |= 0x40;
        }
        goto block_409;
    case 117:                                       /* switch 1 */
        this->unkB0A |= 0x40;
        return;
    case 118:                                       /* switch 1 */
        this->unkB0A &= ~0x40;
        return;
    case 224:                                       /* switch 1 */
        temp_r6_1681 = this->unk8;
        sp178 = M2C_FIELD(temp_r6_1681, f64 *, 0x30);
        sp180 = M2C_FIELD(temp_r6_1681, f64 *, 0x38);
        AddDamage(1000.0f, 1U, *((MKVector3 *) &sp178), 0, 0, 0U, 0U, NULL, 0.0f, 1.0f);
        return;
    case 225:                                       /* switch 1 */
        this->unkB0A |= 0x20;
        return;
    case 87:                                        /* switch 1 */
        if ((IsFriend() == 0) && (IsDead() == 0) && (IsDying() == 0)) {
            temp_r3_1724 = this->unkB08;
            if (!((temp_r3_1724 >> 6U) & 1)) {
                this->unkB08 = temp_r3_1724 | 0x20;
                return;
            }
        }
        break;
    case 144:                                       /* switch 1 */
        SetWorldMatrix(M2C_FIELD(checked_cast<SetWorldMatrixMessage *, MKMessage>(arg0), Matrix **, 8));
        goto block_409;
    case 88:                                        /* switch 1 */
        if (IsDead() == 0) {
            temp_r3_1748 = checked_cast<TargetPositionRequest *, MKMessage>(arg0);
            M2C_FIELD(temp_r3_1748, s8 *, 0x18) = 1;
            temp_r6_1756 = M2C_FIELD(M2C_FIELD(temp_r3_1748, void **, 4), void **, 8);
            temp_f1_1757 = M2C_FIELD(temp_r6_1756, f64 *, 0x30);
            sp168 = temp_f1_1757;
            sp170 = M2C_FIELD(temp_r6_1756, f64 *, 0x38);
            GetAimPoint(sp168, ((u8 *) temp_r3_1748) + 8, temp_r6_1756, temp_f1_1757);
            return;
        }
        goto block_409;
    case 114:                                       /* switch 1 */
        temp_r25_1772 = checked_cast<IsInAlertRangeMsg *, MKMessage>(arg0);
        if ((IsFriend() == 0) && (IsDead() == 0) && (IsDying() == 0)) {
            temp_r3_1789 = this->unkB08;
            if (!((temp_r3_1789 >> 6U) & 1) && !((temp_r3_1789 >> 5U) & 1) && ((u32) temp_r25_1772->unk4 != this)) {
                temp_r25_1772->Test(this);
                return;
            }
        }
        break;
    case 360:                                       /* switch 1 */
        if ((IsFriend() == 0) && (IsDead() == 0) && (IsDying() == 0) && !(((u8) this->unkB08 >> 6U) & 1) && (IsAttacking() == 0) && ((u32) arg0->unk4 != this)) {
            this->unkB08 |= 0x20;
            return;
        }
        break;
    case 115:                                       /* switch 1 */
        IsFlinching();
        if (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) && (IsFriend() == 0) && (IsDead() == 0) && (IsDying() == 0) && (IsAttacking() == 0)) {
            var_r3_1869 = 0;
            if (((s32) this->unk750.unk78 == 3) && (this->unk750.unk94 > 0.0f)) {
                var_r3_1869 = 1;
            }
            if ((var_r3_1869 == 0) && ((temp_r3_1880 = this->unkA44, temp_cr0_eq_1881 = temp_r3_1880 == NULL, (temp_cr0_eq_1881 != 0)) || ((temp_cr0_eq_1881 == 0) && !(M2C_FIELD(temp_r3_1880, s32 *, 4) & 0x10000)))) {
                this->unkB09 |= 2;
                return;
            }
        }
        break;
    case 116:                                       /* switch 1 */
        temp_r7_1898 = this->unkA44;
        temp_r30_1899 = checked_cast<AttackOrderMsg *, MKMessage>(arg0);
        temp_cr0_eq_1901 = temp_r7_1898 == NULL;
        temp_r6_1902 = 1 << this->unkA38->unkF4;
        if (((temp_cr0_eq_1901 != 0) || ((temp_cr0_eq_1901 == 0) && !(M2C_FIELD(temp_r7_1898, s32 *, 4) & 0x10000))) && ((((M2C_FIELD(temp_r30_1899, s32 *, 0x14) & temp_r6_1902) ^ 0) | ((M2C_FIELD(temp_r30_1899, s32 *, 0x10) & (temp_r6_1902 >> 0x1F)) ^ 0)) != 0) && ((IsIdling() != 0) || (IsPatrolling() != 0)) && ((u32) M2C_FIELD(temp_r30_1899, u32 *, 8) != this)) {
            if ((u8) M2C_FIELD(temp_r30_1899, u8 *, 0x18) != 0) {
                M2C_FIELD(temp_r30_1899, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r30_1899, s32 *, 0x1C) + 1);
                return;
            }
            this->unkB08 |= 0x20;
            this->unkB0A |= 1;
            this->unkA34 = M2C_FIELD(temp_r30_1899, u32 *, 8);
            return;
        }
        break;
    case 332:                                       /* switch 1 */
        this->unkB09 |= 1;
        goto block_409;
    case 6:                                         /* switch 1 */
        this->unk6B5 |= 8;
        goto block_409;
    case 21:                                        /* switch 1 */
        if (this->unkAC8 > 0.0f) {
            temp_r3_1966 = this->unkA38;
            if ((s32) temp_r3_1966->unkF4 == 0x1B) {
                if ((s32) this->unkAE8 == 0) {
                    temp_r3_1973 = this->unkA40;
                    if (M2C_FIELD(*temp_r3_1973, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_1973, 0x12) == 0) {
                        SetHealth(this->unkA38->GetEnemySetting((EnemySettingType) 0));
                        SetArmour(this->unkA38->GetMaxArmour());
                        Armour_SetDefaults();
                    }
                }
            } else {
                SetHealth(temp_r3_1966->GetEnemySetting((EnemySettingType) 0));
                SetArmour(this->unkA38->GetMaxArmour());
                Armour_SetDefaults();
            }
        }
        goto block_409;
    case -3:                                        /* switch 1 */
        if ((this->unkAC8 > 0.0f) && ((SetHealth(this->unkA38->GetEnemySetting((EnemySettingType) 0)), temp_r3_2015 = this->unkA38, (((s32) temp_r3_2015->unkF4 == 0x1B) == 0)) || ((s32) this->unkAE8 == 0))) {
            SetArmour(temp_r3_2015->GetMaxArmour());
            Armour_SetDefaults();
        }
        temp_r3_2029 = this->unkA40;
        if ((temp_r3_2029 != NULL) && (M2C_FIELD(*temp_r3_2029, u8 (**)(M2C_UNK), 0x38)(6) != 0)) {
            TryFreeze(1, 1, 1.0f);
        }
        goto block_409;
    case -4:                                        /* switch 1 */
        DefrostBall();
        temp_r3_2054 = this->unkA40;
        if ((temp_r3_2054 != NULL) && (M2C_FIELD(*temp_r3_2054, u8 (**)(M2C_UNK), 0x38)(6) != 0)) {
            temp_r3_2064 = this->unkA00;
            if ((temp_r3_2064 != NULL) && ((u8) M2C_FIELD(temp_r3_2064, u8 *, 0x20) != 0)) {
                ((CharacterIceCubesFX *) temp_r3_2064)->Reset();
            }
        }
        var_r25_2073 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r25_2073 = 1;
        }
        if (var_r25_2073 != 0) {
            var_r3_2090 = M2C_FIELD(this->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_2090 = NULL;
        }
        if (var_r3_2090 != NULL) {
            var_r4_2098 = this;
            if (this != NULL) {
                var_r4_2098 = (Enemy *) &this->unk6B8;
            }
            var_r3_2090->Remove((Targetable *) var_r4_2098, 0xFFFF);
        }
        DisableCurrentProjectile(0U, MKVector3::zero);
        goto block_409;
    case 123:                                       /* switch 1 */
        sp458.EnemyHudData();
        temp_f31_2115 = this->unkAC8;
        GetMaxHealth();
        sp458.Init(this, temp_f31_2115, M2C_ERROR(/* Read from unset register $f1 */));
        EnemyHud_Modified(sp458);
        goto block_409;
    case 18:                                        /* switch 1 */
        temp_r3_2129 = M2C_FIELD(checked_cast<CollisionObjectCollideMsg *, MKMessage>(arg0), void ***, 0xC);
        if (temp_r3_2129 != NULL) {
            var_r25_2136 = M2C_FIELD(*temp_r3_2129, u32 (**)(), 0x2C)();
        } else {
            var_r25_2136 = 0U;
        }
        if ((var_r25_2136 != 0U) && (var_r25_2136 == gb.unk0->GetProp()) && (gb.unk0->GetHeroType() == 0)) {
            temp_r3_2167 = gb.unk0->GetTargetable();
            M2C_FIELD(*temp_r3_2167, M2C_UNK (**)(f32 *, void **), 0x30)(&sp158, temp_r3_2167);
            if ((((sp160 * sp160) + ((sp158 * sp158) + (sp15C * sp15C))) > 1.0f) && ((gb.GetSpyro(), ((((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetCrowdCount() < 5) == 0)) || (gb.unk0->InAir() != 0))) {
                this->unkB09 |= 0x40;
            }
        }
        goto block_409;
    case 136:                                       /* switch 1 */
        temp_r25_2209 = checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0);
        if (IsInvulnerable() == 0) {
            M2C_FIELD(temp_r25_2209, s8 *, 8) = 1;
        } else {
            M2C_FIELD(temp_r25_2209, s8 *, 8) = 0;
        }
        goto block_409;
    case 51:                                        /* switch 1 */
        temp_r3_2223 = checked_cast<SpawnAtPointMsg *, MKMessage>(arg0);
        temp_r4_2225 = M2C_FIELD(temp_r3_2223, SpawnPointObject **, 8);
        temp_r3_2226 = temp_r4_2225->unk0;
        if ((s32) temp_r3_2226->unk14.unk0 == 1) {
            M2C_FIELD(temp_r3_2223, s8 *, 0xC) = Spawn(temp_r3_2226->GetDoor(temp_r4_2225));
        } else {
            M2C_FIELD(temp_r3_2223, s8 *, 0xC) = Spawn();
        }
        goto block_409;
    case 351:                                       /* switch 1 */
        Despawn(0);
        goto block_409;
    case 54:                                        /* switch 1 */
        temp_r3_2257 = checked_cast<SpawnPointDestroyedMsg *, MKMessage>(arg0);
        if ((u32) this->unkA48 == (u32) M2C_FIELD(temp_r3_2257, u32 *, 8)) {
            this->unkA48 = 0;
            this->unkA44 = NULL;
            M2C_FIELD(temp_r3_2257, s8 *, 0xC) = 1;
        }
        goto block_409;
    case 55:                                        /* switch 1 */
        this->unkA48 = 0;
        this->unkA44 = NULL;
        goto block_409;
    case 146:                                       /* switch 1 */
        this->unkA88 = M2C_FIELD(checked_cast<GraphInfoMsg *, MKMessage>(arg0), s32 *, 8);
        goto block_409;
    case 147:                                       /* switch 1 */
        this->unkA8C = M2C_FIELD(checked_cast<GraphArriveMsg *, MKMessage>(arg0), s32 *, 8);
        goto block_409;
    case 141:                                       /* switch 1 */
        temp_r25_2291 = GetCharacterName();
        M2C_FIELD(checked_cast<GetNameMsg *, MKMessage>(arg0), s32 *, 8) = temp_r25_2291;
        return;
    case 142:                                       /* switch 1 */
        temp_r3_2298 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_2300 = this;
        if (this != NULL) {
            var_r0_2300 = (Enemy *) &this->unk6B8;
        }
        M2C_FIELD(temp_r3_2298, Enemy **, 8) = var_r0_2300;
        return;
    case 353:                                       /* switch 1 */
        this->unkB01 &= ~0x80;
        goto block_409;
    case 352:                                       /* switch 1 */
        this->unkB01 |= 0x80;
        goto block_409;
    case 357:                                       /* switch 1 */
        this->unkB01 |= 0x40;
        goto block_409;
    case 95:                                        /* switch 1 */
        temp_r3_2326 = checked_cast<BallHitMessage *, MKMessage>(arg0);
        M2C_FIELD(temp_r3_2326, s8 *, 0x15) = 1;
        IsFlinching();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            M2C_FIELD(temp_r3_2326, s8 *, 0x14) = 0;
        } else {
            M2C_FIELD(temp_r3_2326, s8 *, 0x14) = 0;
            sp47C = 0;
            temp_r10_2348 = M2C_FIELD(temp_r3_2326, void **, 4);
            temp_f3_2349 = M2C_FIELD(temp_r3_2326, f32 *, 8);
            temp_r8_2350 = M2C_FIELD(temp_r10_2348, void **, 8);
            temp_f2_2351 = M2C_FIELD(temp_r8_2350, f64 *, 0x30);
            temp_f1_2352 = M2C_FIELD(temp_r8_2350, f64 *, 0x38);
            sp148 = temp_f2_2351;
            sp478 = 4;
            sp480 = temp_r10_2348;
            sp488 = temp_f2_2351;
            sp490 = temp_f1_2352;
            sp498 = temp_f3_2349;
            sp4B4 = 0;
            sp4A0 = 2;
            sp4A8 = 0x2000;
            sp4B5 = 0;
            sp4B6 = 0;
            sp4A4 = -1;
            sp4AC = 0;
            sp4B0 = 0;
            sp49C = 1.0f;
            sp150 = temp_f1_2352;
            Message(&sp478, 0x2000, 2, 4, temp_r8_2350, 0.0, temp_r10_2348, temp_f1_2352, temp_f2_2351, temp_f3_2349);
        }
        goto block_409;
    case 78:                                        /* switch 1 */
        if ((void *) this->unkA2C == (u32) arg0->unk4) {
            this->unkA2C = NULL;
        }
        goto block_409;
    case 166:                                       /* switch 1 */
        temp_r25_2386 = checked_cast<GetConvexFuryTargetPosMsg *, MKMessage>(arg0);
        MKVector(0.0f, 150.0f, 0.0f);
        ((MKProp *) &sp128)->GetPos();
        sp18 = sp128 + sp118;
        M2C_FIELD(temp_r25_2386, f64 *, 8) = sp18;
        sp20 = sp130 + sp120;
        sp138 = sp18;
        sp140 = (f64) sp20;
        M2C_FIELD(temp_r25_2386, f64 *, 0x10) = (f64) sp20;
        goto block_409;
    }
}
#endif

void EnemyMessages_cpp::__sinit() {
    f32 temp_f0_2669;
    f64 temp_f1_2650;
    f64 temp_f1_2658;
    f64 temp_f3_2638;
    f64 temp_f4_2647;
    f64 temp_f4_2655;
    f64 temp_f8_2640;

    temp_f3_2638 = __frsqrte(2014000.0);
    temp_f8_2640 = __frsqrte(380000.0);
    temp_f4_2647 = 0.5 * temp_f3_2638 * -((2014000.0 * (temp_f3_2638 * temp_f3_2638)) - 3.0);
    temp_f1_2650 = 0.5 * temp_f8_2640 * -((380000.0 * (temp_f8_2640 * temp_f8_2640)) - 3.0);
    temp_f4_2655 = 0.5 * temp_f4_2647 * -((2014000.0 * (temp_f4_2647 * temp_f4_2647)) - 3.0);
    temp_f1_2658 = 0.5 * temp_f1_2650 * -((380000.0 * (temp_f1_2650 * temp_f1_2650)) - 3.0);
    temp_f0_2669 = (f32) (380000.0 * (0.5 * temp_f1_2658 * -((380000.0 * (temp_f1_2658 * temp_f1_2658)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_2655 * -((2014000.0 * (temp_f4_2655 * temp_f4_2655)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_2669;
}

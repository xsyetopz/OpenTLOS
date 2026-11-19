#include "spyro/source/Spyro.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterGlowFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GroundFire.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/HitFX.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/LineSegmentTrail.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Sparx.h"
#include "spyro/source/SpyroEffects.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/WaterSurfaceFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "common/gc/MKView_GC.h"
#include "spyro/source/ConnectingProps.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'EventCamera_bRemainTargetable' redeclared
M2C_UNK __destroy_arr(SpyroSoundPlayer *, SpyroSoundPlayer::SpyroLoopSounds *(*)(SpyroSoundPlayer::SpyroLoopSounds *, s16), M2C_UNK, M2C_UNK); /* extern */
f64 atan2(f32, f32);                                /* extern */
M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */
extern u8 EventCamera_bRemainTargetable;
#endif
extern s32 GS_PLACEHOLDER;
extern s32 GS_SpyroAcidBurn;
extern s32 GS_SpyroHeadButt;
extern s32 GS_SpyroLavaBurn;
extern s32 GS_SpyroMeleeHit;
extern s32 GS_SpyroSpikeBurn;
extern s32 GS_SpyroTailHit;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 deltaMove;
#if 0 // DRAFT: identifier 'gAssertBool' redeclared
extern u8 gAssertBool;
#endif
extern M2C_UNK gEmptyPtrList;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern f32 maxStandAngle;
extern DataMap spyroCombatArcDataMap;
#if 0 // DRAFT: illegal use of abstract class ('Spyro::pure_slot12()')
static Spyro pNodeNames__5Spyro;                    /* type too large by 0xBB0; unable to generate initializer: confusing struct layout */
static Spyro stateCreators__5Spyro;                 /* type too large by 0xAD8; unable to generate initializer: confusing struct layout */
static MKVector3 p_1138;
#endif

static f32 SPYRO_COMBAT_SCALE_MAG = 400.0f;
#if 0 // DRAFT: illegal use of abstract class ('Spyro::pure_slot12()')
static Spyro pRefPointNames__5Spyro;                /* type too large by 0xBC4; unable to generate initializer: confusing struct layout */
static Spyro defaultEvents__5Spyro;                 /* type too large by 0xBC0; unable to generate initializer: confusing struct layout */
static Spyro pAnimScrNodeNames__5Spyro;             /* type too large by 0xBC0; unable to generate initializer: confusing struct layout */

static f32 fMeleeButtonTimeout = 0.25f;
#endif
static f32 fMaxKnockupHoldButtonTime = 0.2f;

static u8 lit_2937 = 1;

static M2C_UNK lit_2047;                               /* unable to generate initializer: unknown type; const */

f32 Spyro::GetDeltaMove() {
    return deltaMove;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'StatType'
void Spyro::AddStat(StatType arg0, float arg1) {
    f32 var_f1_331;

    if (((u8) M2C_FIELD(this, u8 *, 0x25D) != 0) && ((s32) arg0 == 3)) {
        var_f1_331 = this->unk250 + arg1;
        if (var_f1_331 < gameData.unkBC) {

        } else {
            var_f1_331 = gameData.unkBC;
        }
        if (var_f1_331 > 0.0f) {

        } else {
            var_f1_331 = 0.0f;
        }
        this->unk250 = var_f1_331;
        return;
    }
    ((Stat *) (&gameData + ((s32) arg0 * 0x18) + 0x70))->Add(arg1, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
void Spyro::UpdateRage() {
    BreathHitMessage sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;                                      /* compiler-managed */
    f64 sp188;                                      /* compiler-managed */
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
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
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDSynkerPlayer3 *temp_r3_376;
    TargetManager ***var_r29_529;
    TargetManager **temp_r28_860;
    f32 temp_f0_466;
    f32 temp_f1_440;
    f32 temp_f2_423;
    f32 temp_r0_476;
    f32 temp_r5_414;
    f32 var_f0_424;
    f32 var_f0_639;
    f32 var_f1_459;
    f32 var_f4_709;
    f32 var_f7_783;
    f64 temp_f1_581;
    f64 temp_f1_714;
    f64 temp_f1_720;
    f64 temp_f1_724;
    s32 temp_r3_743;
    s32 var_r0_753;
    u8 var_r28_377;
    void *temp_r27_876;
    void *temp_r28_623;
    void *temp_r29_373;
    void *temp_r3_588;
    void *temp_r3_641;
    void *temp_r3_657;
    void *temp_r3_819;
    void *temp_r3_871;
    void *temp_r3_879;
    void *temp_r4_579;

    temp_r29_373 = gb.unkC;
    if (temp_r29_373 != NULL) {
        temp_r3_376 = M2C_FIELD(temp_r29_373, KDSynkerPlayer3 **, 0x78);
        var_r28_377 = 0;
        if (((temp_r3_376 != NULL) && (temp_r3_376->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r29_373, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r29_373 + 0x24))->GetState() == 2))) {
            var_r28_377 = 1;
        }
        if (var_r28_377 == 0) {
            goto block_7;
        }
    } else {
block_7:
        if (((u8) M2C_FIELD(this, u8 *, 0x25D) == 0) || (EventCamera_GetCurrent() != NULL)) {
            if (this->unk6F8.SoundIsPlaying(1) != 0) {
                this->unk6F8.FadeOut(1);
            }
        } else {
            temp_r5_414 = this->unk24C;
            if (M2C_BITWISE(s32, temp_r5_414) != 1) {
                this->unk6F8.FadeIn(1, M2C_BITWISE(s32, temp_r5_414));
            }
            temp_f2_423 = this->unk248;
            var_f0_424 = M2C_FIELD(this, f32 *, 0x24C) - gUpdateTimeDelta;
            if (var_f0_424 < temp_f2_423) {

            } else {
                var_f0_424 = temp_f2_423;
            }
            if (var_f0_424 > 0.0f) {

            } else {
                var_f0_424 = 0.0f;
            }
            M2C_FIELD(this, f32 *, 0x24C) = var_f0_424;
            temp_f1_440 = M2C_FIELD(this, f32 *, 0x24C);
            if (temp_f1_440 > 0.0f) {
                if ((u8) gameData.unk156 != 0) {
                    ((Stat *) (&gameData.unk70 + 0x48))->SetValue(gameData.unkBC, 0U);
                } else {
                    var_f1_459 = (temp_f1_440 / this->unk248) * gameData.unkBC;
                    if (var_f1_459 < gameData.unkBC) {

                    } else {
                        var_f1_459 = gameData.unkBC;
                    }
                    temp_f0_466 = this->unk250;
                    if (var_f1_459 > temp_f0_466) {

                    } else {
                        var_f1_459 = temp_f0_466;
                    }
                    ((Stat *) (&gameData.unk70 + 0x48))->SetValue(var_f1_459, 0U);
                }
                temp_r0_476 = this->unk24C;
                switch (M2C_BITWISE(s32, temp_r0_476)) { /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    sp10 = MKRand_Float(&gViewSeed, 2.0f, 3.0f);
                    spAC = MKRand_Float(&gViewSeed, 100.0f, 200.0f);
                    spA8 = 0.0f;
                    spB0 = 0.0f;
                    sp178 = (f64) spA8;
                    sp180 = (f64) spB0;
                    gb.unk68->Emit(*(((CharacterBodyFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterBodyFX **, 0xB4)))->GetRandomNode(NULL) + 8), *((MKVector3 *) &sp178), sp10);
                    return;
                case 1:                             /* switch 1 */
                    if ((u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), void **, 0xB4), u8 *, 0x17) != 0) {
                        var_r29_529 = gb.unk20->Begin();
loop_73:
                        if (var_r29_529 != NULL) {
                            temp_r28_860 = *var_r29_529;
                            if (temp_r28_860 == NULL) {
                                return;
                            }
                            if (((*temp_r28_860)->unk8.unk0(temp_r28_860) != NULL) && (M2C_FIELD(*temp_r28_860, u8 (**)(TargetManager **), 0x18)(temp_r28_860) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r28_860)->unk8.unk4)(temp_r28_860) == 0U) || ((((u32 (*)(TargetManager **)) (*temp_r28_860)->unk8.unk4)(temp_r28_860) != 0U) && (((Character *) (((Character *(*)(TargetManager **)) (*temp_r28_860)->unk8.unk4)(temp_r28_860)))->IsActive() != 0) && (((Enemy *) (((Enemy *(*)(TargetManager **)) (*temp_r28_860)->unk8.unk4)(temp_r28_860)))->IsSpawning() == 0)))) {
                                temp_r4_579 = this->unk8;
                                temp_f1_581 = M2C_FIELD(temp_r4_579, f64 *, 0x30);
                                sp158 = temp_f1_581;
                                sp160 = M2C_FIELD(temp_r4_579, f64 *, 0x38);
                                temp_r3_588 = M2C_FIELD((*temp_r28_860)->unk8.unk0(temp_r28_860, temp_r4_579, temp_f1_581), void **, 8);
                                sp168 = M2C_FIELD(temp_r3_588, f64 *, 0x30);
                                sp170 = M2C_FIELD(temp_r3_588, f64 *, 0x38);
                                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                                sp198 = sp98;
                                spA0 = (f32) sp170 - (f32) sp160;
                                sp1A0 = (f64) spA0;
                                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                                if ((((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + (unksp19C * unksp19C))) == 250000.0f) {
                                    temp_r28_623 = (*temp_r28_860)->unk8.unk0(temp_r28_860);
                                    sp1A8.unk4 = 0;
                                    sp1A8.Init((MKProp *) this, gameData.unk70.GetBreathAttackDamage(1, 0, 0), 0, 0, 1, 0, 0, -1);
                                    var_f0_639 = 0.0f;
                                    temp_r3_641 = this->unk8;
                                    sp68 = 0.0f;
                                    sp6C = 100.0f;
                                    sp70 = 0.0f;
                                    spF8 = (f64) sp68;
                                    sp108 = M2C_FIELD(temp_r3_641, f64 *, 0x30);
                                    sp100 = (f64) sp70;
                                    sp110 = M2C_FIELD(temp_r3_641, f64 *, 0x38);
                                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                                    temp_r3_657 = M2C_FIELD(temp_r28_623, void **, 8);
                                    sp90 = 0.0f;
                                    sp88 = 0.0f;
                                    sp8C = 100.0f;
                                    sp60 = (f32) sp110 + (f32) sp100;
                                    sp128 = (f64) sp88;
                                    sp138 = M2C_FIELD(temp_r3_657, f64 *, 0x30);
                                    sp118 = sp58;
                                    sp120 = (f64) sp60;
                                    sp130 = (f64) sp90;
                                    sp140 = M2C_FIELD(temp_r3_657, f64 *, 0x38);
                                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                                    sp148 = sp78;
                                    sp80 = (f32) sp140 + (f32) sp130;
                                    sp150 = (f64) sp80;
                                    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
                                    sp188 = sp48;
                                    sp50 = (f32) sp150 - (f32) sp120;
                                    sp190 = (f64) sp50;
                                    var_f4_709 = ((f32) sp190 * (f32) sp190) + (((f32) sp188 * (f32) sp188) + (unksp18C * unksp18C));
                                    if (var_f4_709 > 0.000001f) {
                                        if (var_f4_709 > 0.0f) {
                                            temp_f1_714 = __frsqrte(var_f4_709);
                                            temp_f1_720 = 0.5 * temp_f1_714 * -(((f64) var_f4_709 * (temp_f1_714 * temp_f1_714)) - 3.0);
                                            temp_f1_724 = 0.5 * temp_f1_720 * -(((f64) var_f4_709 * (temp_f1_720 * temp_f1_720)) - 3.0);
                                            var_f4_709 = (f32) ((f64) var_f4_709 * (0.5 * temp_f1_724 * -(((f64) var_f4_709 * (temp_f1_724 * temp_f1_724)) - 3.0)));
                                        } else if (var_f4_709 < M2C_BITWISE(f32, 0.0)) {
                                            var_f4_709 = __float_nan;
                                        } else {
                                            sp8 = var_f4_709;
                                            temp_r3_743 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                            switch (temp_r3_743) { /* switch 2; irregular */
                                            case 0x7F800000: /* switch 2 */
                                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                                    var_r0_753 = 1;
                                                } else {
                                                    var_r0_753 = 2;
                                                }
                                                break;
                                            case 0x0: /* switch 2 */
                                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                                    var_r0_753 = 5;
                                                } else {
                                                    var_r0_753 = 3;
                                                }
                                                break;
                                            default: /* switch 2 */
                                                var_r0_753 = 4;
                                                break;
                                            }
                                            if (var_r0_753 == 1) {
                                                var_f4_709 = __float_nan;
                                            }
                                        }
                                        var_f0_639 = 1.0f / var_f4_709;
                                    } else {
                                        var_f4_709 = 0.0f;
                                    }
                                    var_f7_783 = var_f4_709 / 400.0f;
                                    sp18 = 1.0f;
                                    sp1C = 1.0f;
                                    sp20 = 0.2f;
                                    sp24 = 1.0f;
                                    sp188 = (f32) sp188 * var_f0_639;
                                    unksp18C *= var_f0_639;
                                    sp190 = (f32) sp190 * var_f0_639;
                                    spB8 = (f64) sp18;
                                    spC0 = (f64) sp20;
                                    if (var_f7_783 < 1000.0f) {

                                    } else {
                                        var_f7_783 = 1000.0f;
                                    }
                                    if (var_f7_783 > 1.0f) {

                                    } else {
                                        var_f7_783 = 1.0f;
                                    }
                                    spC = var_f7_783;
                                    temp_r3_819 = this->unk8;
                                    sp40 = 0.0f;
                                    sp38 = 0.0f;
                                    sp3C = 100.0f;
                                    spD8 = M2C_FIELD(temp_r3_819, f64 *, 0x30);
                                    spC8 = (f64) sp38;
                                    spD0 = (f64) sp40;
                                    spE0 = M2C_FIELD(temp_r3_819, f64 *, 0x38);
                                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                                    spE8 = sp28;
                                    sp30 = (f32) spE0 + (f32) spD0;
                                    spF0 = (f64) sp30;
                                    gb.unk94->Trigger(*((MKVector3 *) &spE8), *((MKVector3 *) &sp188), spC, lit_2937, (MKVector4) &spB8);
                                    M2C_FIELD(M2C_FIELD(temp_r28_623, void **, 0x44), M2C_UNK (**)(void *, BreathHitMessage *), 0x2C)(temp_r28_623, &sp1A8);
                                }
                            }
                            var_r29_529 += 4;
                            goto loop_73;
                        }
                    }
                    break;
                case 2:                             /* switch 1 */
                    temp_r3_871 = M2C_FIELD(M2C_FIELD(gb.unk2A4, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A4);
                    if (temp_r3_871 != NULL) {
                        temp_r27_876 = M2C_FIELD(temp_r3_871, void **, 0x2C);
                        temp_r3_879 = ((CharacterBodyFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterBodyFX **, 0xB4)))->GetRandomNode(NULL);
                        M2C_FIELD(temp_r3_871, f64 *, 0) = (f64) M2C_FIELD(temp_r3_879, f64 *, 8);
                        M2C_FIELD(temp_r3_871, f64 *, 8) = (f64) M2C_FIELD(temp_r3_879, f64 *, 0x10);
                        M2C_FIELD(temp_r3_871, f32 *, 0x20) = 0.0f;
                        M2C_FIELD(temp_r3_871, f32 *, 0x28) = 0.0f;
                        M2C_FIELD(temp_r3_871, f32 *, 0x10) = 0.1f;
                        M2C_FIELD(temp_r3_871, f32 *, 0x14) = 0.1f;
                        M2C_FIELD(temp_r3_871, f32 *, 0x18) = 0.1f;
                        M2C_FIELD(temp_r3_871, f32 *, 0x1C) = 1.0f;
                        M2C_FIELD(temp_r27_876, f32 *, 0) = 0.0f;
                        M2C_FIELD(temp_r27_876, f32 *, 4) = 0.0f;
                        M2C_FIELD(temp_r27_876, f32 *, 8) = 0.0f;
                        M2C_FIELD(temp_r27_876, f32 *, 0x18) = MKRand_Float(&gViewSeed, 0.25f, 0.5f);
                        M2C_FIELD(temp_r27_876, f32 *, 0x10) = MKRand_Float(&gViewSeed, -3.1415927f, 3.1415927f);
                        M2C_FIELD(temp_r27_876, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A4, f32 *, 0xF4);
                        return;
                    }
                    break;
                }
            } else {
                M2C_FIELD(this, u8 *, 0x25D) = 0U;
                this->unk6F8.FadeOut(1);
                if ((u8) gameData.unk156 != 0) {
                    gameData.unkB8.SetValue(gameData.unkBC, 0U);
                    return;
                }
                gameData.unkB8.SetValue(this->unk250, 0U);
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Spyro::SetRage(int arg0, float arg1) {
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
    f32 temp_r0_1036;
    f32 temp_r0_960;
    f32 temp_r5_1029;

    if (((u8) M2C_FIELD(this, u8 *, 0x25D) != 0) && (arg1 > 0.0f)) {
        this->unk6F8.Stop(1);
        temp_r0_960 = this->unk24C;
        switch (M2C_BITWISE(s32, temp_r0_960)) {    /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            break;
        case 1:                                     /* switch 1 */
            ((CharacterZapFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterZapFX **, 0xB4)))->Enable(0U, this->unk248, 1U);
            break;
        case 2:                                     /* switch 1 */
            sp38 = 0.5f;
            sp3C = 0.5f;
            sp40 = 1.0f;
            sp44 = 1.0f;
            sp78 = (f64) sp38;
            sp80 = (f64) sp40;
            ((CharacterGlowFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterGlowFX **, 0x28)))->Enable(0U, *((MKVector4 *) &sp78), this->unk248);
            break;
        case 3:                                     /* switch 1 */
            sp28 = 0.25f;
            sp2C = 1.0f;
            sp30 = 0.25f;
            sp34 = 1.0f;
            sp68 = (f64) sp28;
            sp70 = (f64) sp30;
            ((CharacterGlowFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterGlowFX **, 0x28)))->Enable(0U, *((MKVector4 *) &sp68), this->unk248);
            break;
        }
    }
    this->unk248 = arg1;
    M2C_FIELD(this, f32 *, 0x24C) = arg1;
    this->unk24C = M2C_BITWISE(f32, arg0);
    if (M2C_FIELD(this, f32 *, 0x24C) > 0.0f) {
        M2C_FIELD(this, u8 *, 0x25D) = 1U;
        this->unk250 = 0.0f;
        temp_r5_1029 = this->unk24C;
        if (M2C_BITWISE(s32, temp_r5_1029) != 1) {
            this->unk6F8.FadeIn(1, M2C_BITWISE(s32, temp_r5_1029));
        }
        temp_r0_1036 = this->unk24C;
        switch (M2C_BITWISE(s32, temp_r0_1036)) {   /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            ((CharacterZapFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterZapFX **, 0xB4)))->Enable(1U, this->unk248, 1U);
            return;
        case 2:                                     /* switch 2 */
            sp18 = 0.5f;
            sp1C = 0.5f;
            sp20 = 1.0f;
            sp24 = 1.0f;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            ((CharacterGlowFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterGlowFX **, 0x28)))->Enable(1U, *((MKVector4 *) &sp58), 10.0f + this->unk248);
            return;
        case 3:                                     /* switch 2 */
            sp8 = 0.25f;
            spC = 1.0f;
            sp10 = 0.25f;
            sp14 = 1.0f;
            sp48 = (f64) sp8;
            sp50 = (f64) sp10;
            ((CharacterGlowFX *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), CharacterGlowFX **, 0x28)))->Enable(1U, *((MKVector4 *) &sp48), 15.0f + this->unk248);
            return;
        }
    } else {
        M2C_FIELD(this, u8 *, 0x25D) = 0U;
    case 0:                                         /* switch 2 */
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
f32 Spyro::SetFuryAnimSpeed(float arg0) {
    f32 temp_f31_1127;

    temp_f31_1127 = GetAnimScript((Spyro::AnimScriptNode) 0)->unk38;
    GetAnimScript((Spyro::AnimScriptNode) 0)->unk38 = arg0;
    return temp_f31_1127;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp17C'
void Spyro::EmitWallHeadbuttEffects(const MKVector3 &arg0) {
    MKProp *temp_r3_1243;
    MKProp *temp_r3_1251;
    f32 temp_f14_1330;
    f32 temp_f15_1326;
    f32 temp_f1_1396;
    f32 temp_f1_1453;
    f32 temp_f3_1382;
    f32 temp_f3_1439;
    s32 var_r27_1298;
    u8 var_r28_1244;
    arg_sp17C = 0;
    MKVector(0.7f, 0.7f, 0.7f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f14 */);
    arg_sp178 = 0x417;
    arg_sp40 = arg_sp150 * 500.0f;
    arg_sp180 = arg_sp38;
    arg_sp188 = (f64) arg_sp40;
    arg_sp190 = 1;
    arg_sp158 = arg_sp38;
    arg_sp160 = (f64) arg_sp40;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &arg_sp178, arg_sp38);
    ((KDInput *) (M2C_FIELD(gb.unk0->__vptr, KDInput *(**)(HeroInterface *), 0x40)(gb.unk0)))->RumblePlay(0.03f, 0.3f, 0.05f, 0, 4.0f, 0U);
    KDSound_Play(GS_SpyroHeadButt, 0U, -1);
    temp_r3_1243 = this->unk26C.unk8;
    var_r28_1244 = 0;
    if ((M2C_FIELD(temp_r3_1243->unk0, s32 (**)(MKProp *), 0x34)(temp_r3_1243) & 0x10000) || (temp_r3_1251 = this->unk26C.unk8, (((M2C_FIELD(temp_r3_1251->unk0, s32 (**)(MKProp *), 0x34)(temp_r3_1251) & 8) == 0) == 0))) {
        var_r28_1244 = 1;
    }
    if (var_r28_1244 == 0) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f15 */);
        arg_sp138 = arg_spA8;
        arg_spB0 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * 200.0f;
        arg_sp140 = (f64) arg_spB0;
        gb.EmitDust(arg0, *((MKVector3 *) &arg_sp138), 2.0f, 0.0f);
    }
    M2C_STRUCT_COPY((s32) &arg_sp19C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    var_r27_1298 = 0;
    arg_sp1DC = 1.0f;
    arg_sp1D0 = 0.0f;
    arg_sp1E8 = 5.287201034e-315;
    arg_sp1D4 = 0.0f;
    arg_sp1D8 = 0.0f;
    arg_sp1F0 = (f64) arg_sp1A0;
    do {
        temp_f15_1326 = 6.2831855f * ((f32) var_r27_1298 / 19.0f);
        temp_f14_1330 = -_table_sinf((f32) arg_sp1E8 + temp_f15_1326);
        arg_sp28 = _table_sinf(temp_f15_1326);
        arg_sp2C = temp_f14_1330;
        arg_sp30 = 0.0f;
        arg_sp168 = (f64) arg_sp28;
        arg_sp170 = (f64) arg_sp30;
        arg_sp128 = (f64) arg_sp28;
        arg_sp130 = (f64) arg_sp30;
        arg_sp18 = 0.0f + (((f32) arg_sp170 * arg_sp1C0) + (((f32) arg_sp168 * (f32) arg_sp1F0) + (arg_sp16C * arg_sp1B0)));
        arg_sp1C = 0.0f + (((f32) arg_sp170 * arg_sp1C4) + (((f32) arg_sp168 * arg_sp1A4) + (arg_sp16C * arg_sp1B4)));
        arg_sp20 = 0.0f + (((f32) arg_sp170 * arg_sp1C8) + (((f32) arg_sp168 * arg_sp1A8) + (arg_sp16C * arg_sp1B8)));
        arg_sp118 = (f64) arg_sp18;
        arg_sp120 = (f64) arg_sp20;
        arg_sp168 = (f64) arg_sp18;
        arg_sp170 = (f64) arg_sp20;
        if (var_r28_1244 != 0) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            temp_f3_1382 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * MKRand_Float(&gViewSeed, 200.0f, 400.0f);
            arg_spE8 = arg_sp88;
            arg_sp90 = temp_f3_1382;
            arg_spF0 = (f64) arg_sp90;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
            temp_f1_1396 = (f32) arg_sp170 * MKRand_Float(&gViewSeed, 0.0f, 500.0f);
            arg_spF8 = arg_sp98;
            arg_spA0 = temp_f1_1396;
            arg_sp100 = (f64) arg_spA0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp108 = arg_sp78;
            arg_sp80 = (f32) arg_sp100 + (f32) arg_spF0;
            arg_sp110 = (f64) arg_sp80;
            arg_sp14 = MKRand_Float(&gViewSeed, 0.03f, 0.09f);
            gb.EmitSnowCrud(arg0, *((MKVector3 *) &arg_sp108), arg_sp14);
        } else {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
            temp_f3_1439 = M2C_FIELD((this->unk8 + 0x20), f32 *, 8) * MKRand_Float(&gViewSeed, 200.0f, 400.0f);
            arg_spB8 = arg_sp58;
            arg_sp60 = temp_f3_1439;
            arg_spC0 = (f64) arg_sp60;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
            temp_f1_1453 = (f32) arg_sp170 * MKRand_Float(&gViewSeed, 0.0f, 500.0f);
            arg_spC8 = arg_sp68;
            arg_sp70 = temp_f1_1453;
            arg_spD0 = (f64) arg_sp70;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spD8 = arg_sp48;
            arg_sp50 = (f32) arg_spD0 + (f32) arg_spC0;
            arg_spE0 = (f64) arg_sp50;
            arg_sp10 = MKRand_Float(&gViewSeed, 0.1f, 0.3f);
            gb.EmitCrud(arg0, *((MKVector3 *) &arg_spD8), arg_sp10);
        }
        var_r27_1298 += 1;
    } while (var_r27_1298 < 0x14);
}
#endif

void Spyro::Spawn() {
    SpyroStateMessages sp8;

    if ((u8) M2C_FIELD(this, u8 *, 0x3CC) == 0) {
        M2C_FIELD(this, u8 *, 0x3CC) = 1U;
        sp8.unk50 = 0;
        this->unk54.Reset(0xA, sp8);
    }
}

#if 0 // DRAFT: undefined identifier 'sp18'
void Spyro::GetCenterPos() {
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
    f32 sp10;
    void *temp_r5_1559;

    temp_r5_1559 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 8);
    sp2C = 100.0f;
    sp28 = 0.0f;
    sp30 = 0.0f;
    sp58 = (f64) sp28;
    sp48 = M2C_FIELD(temp_r5_1559, f64 *, 0x30);
    sp60 = (f64) sp30;
    sp50 = M2C_FIELD(temp_r5_1559, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp18;
    sp20 = (f32) sp50 + (f32) sp60;
    sp40 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r4, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = sp8;
    sp10 = (f32) sp40 + M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x370);
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

s32 Spyro::GetCrowdCount() {
    s32 var_ctr_1607;
    s32 var_r6_1604;
    s32 var_r7_1605;

    var_r6_1604 = 0;
    var_r7_1605 = 0;
    var_ctr_1607 = 8;
    do {
        if (this->unkB90.unk14 & (1 << var_r7_1605)) {
            var_r6_1604 += 1;
        }
        var_r7_1605 += 1;
        var_ctr_1607 -= 1;
    } while (var_ctr_1607 != 0);
    return var_r6_1604;
}

#if 0 // DRAFT: undefined identifier 'spC0'
void Spyro::UpdateCrowdTest() {
    MKCollisionResult spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    void *temp_r3_1654;

    KDMath_GetDirection(0.785398f * (f32) this->unkB90.unk10);
    spE8 = spB8;
    spF0 = spC0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    temp_r3_1654 = this->unk8;
    sp60 = 0.0f;
    sp40 = (f32) spF0 * 100.0f;
    sp58 = 0.0f;
    sp5C = 100.0f;
    sp98 = M2C_FIELD(temp_r3_1654, f64 *, 0x30);
    sp88 = (f64) sp58;
    sp78 = sp38;
    sp80 = (f64) sp40;
    sp90 = (f64) sp60;
    spA0 = M2C_FIELD(temp_r3_1654, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spA8 = sp48;
    sp50 = (f32) spA0 + (f32) sp90;
    spB0 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spD8 = sp28;
    sp30 = (f32) spB0 + (f32) sp80;
    spE0 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp20 = (f32) spF0 * 200.0f;
    sp68 = sp18;
    sp70 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spC8 = sp8;
    sp10 = (f32) spE0 + (f32) sp70;
    spD0 = (f64) sp10;
    if (MKCollision_SweepSphereCollide(*((MKVector3 *) &spD8), *((MKVector3 *) &spC8), 20.0f, &spF8, (MKCollisionMode) 7, 0) != 0) {
        this->unkB90.unk14 |= 1 << this->unkB90.unk10;
    } else {
        this->unkB90.unk14 &= ~(1 << this->unkB90.unk10);
    }
    this->unkB90.unk10 += 1;
    if ((s32) this->unkB90.unk10 >= 8) {
        this->unkB90.unk10 = 0;
    }
}
#endif

void Spyro::ResetCrowdTest() {
    this->unkB90.unk10 = 0;
    this->unkB90.unk14 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void Spyro::ResetLighting() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    s32 temp_r3_1801;
    s32 temp_r4_1785;
    s32 temp_r4_1827;
    s32 var_r29_1780;
    s32 var_r31_1782;
    s32 var_r3_1788;
    s32 var_r3_1830;
    s32 var_r4_1804;
    void *temp_r3_1796;
    void *temp_r5_1812;

    var_r29_1780 = 0;
    var_r31_1782 = 0;
    do {
        temp_r4_1785 = gb.unk32C->unk18;
        if ((u32) temp_r4_1785 != 0U) {
            var_r3_1788 = M2C_FIELD(temp_r4_1785, s32 *, 4);
        } else {
            var_r3_1788 = M2C_FIELD(gb.unk32C->unk24, s32 *, 4);
        }
        temp_r3_1796 = var_r3_1788 + (var_r31_1782 + 0x40);
        sp18 = M2C_FIELD(temp_r3_1796, f64 *, 0);
        sp20 = M2C_FIELD(temp_r3_1796, f64 *, 8);
        temp_r3_1801 = gb.unk32C->unk18;
        if ((u32) temp_r3_1801 != 0U) {
            var_r4_1804 = M2C_FIELD(temp_r3_1801, s32 *, 4);
        } else {
            var_r4_1804 = M2C_FIELD(gb.unk32C->unk24, s32 *, 4);
        }
        temp_r5_1812 = var_r4_1804 + (var_r31_1782 + 0x70);
        sp8 = M2C_FIELD(temp_r5_1812, f64 *, 0);
        sp10 = M2C_FIELD(temp_r5_1812, f64 *, 8);
        MKView_SetLightColor(var_r29_1780, *((MKVector4 *) &sp18));
        MKView_SetLightDirection(var_r29_1780, *((MKVector3 *) &sp8));
        var_r29_1780 += 1;
        var_r31_1782 += 0x10;
    } while (var_r29_1780 < 3);
    temp_r4_1827 = gb.unk32C->unk18;
    if ((u32) temp_r4_1827 != 0U) {
        var_r3_1830 = M2C_FIELD(temp_r4_1827, s32 *, 4);
    } else {
        var_r3_1830 = M2C_FIELD(gb.unk32C->unk24, s32 *, 4);
    }
    MKView_SetAmbientColor(*(var_r3_1830 + 0xA0));
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1C'
void Spyro::SetLighting() {
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
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;                                       /* compiler-managed */
    f64 spD0;                                       /* compiler-managed */
    MKVector4 spC0;
    MKVector4 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 spC;
    f32 sp8;
    f32 temp_f30_1867;
    f32 var_f3_1958;
    f32 var_f4_1891;
    f64 temp_f1_1897;
    f64 temp_f1_1903;
    f64 temp_f1_1907;
    s32 temp_r3_1926;
    s32 temp_r3_2075;
    s32 var_r0_1936;
    s32 var_r0_2085;
    s32 var_r29_2025;
    s32 var_r30_2027;
    void *temp_r3_1973;
    void *temp_r3_2001;

    sp70 = 1.0f;
    sp74 = 1.0f;
    sp78 = 1.0f;
    sp7C = 1.0f;
    spF0 = (f64) sp70;
    spF8 = (f64) sp78;
    temp_f30_1867 = this->unk430.unk1C;
    MKModel_CalculateCentre(this->unk4, &spE0);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spD0 = sp60;
    sp68 = spE0.unk8 - this->unk430.unk0;
    spD8 = (f64) sp68;
    var_f4_1891 = ((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + (unkspD4 * unkspD4));
    if (var_f4_1891 > 0.000001f) {
        if (var_f4_1891 > 0.0f) {
            temp_f1_1897 = __frsqrte(var_f4_1891);
            temp_f1_1903 = 0.5 * temp_f1_1897 * -(((f64) var_f4_1891 * (temp_f1_1897 * temp_f1_1897)) - 3.0);
            temp_f1_1907 = 0.5 * temp_f1_1903 * -(((f64) var_f4_1891 * (temp_f1_1903 * temp_f1_1903)) - 3.0);
            var_f4_1891 = (f32) ((f64) var_f4_1891 * (0.5 * temp_f1_1907 * -(((f64) var_f4_1891 * (temp_f1_1907 * temp_f1_1907)) - 3.0)));
        } else if (var_f4_1891 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1891 = __float_nan;
        } else {
            sp8 = var_f4_1891;
            temp_r3_1926 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1926) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1936 = 1;
                } else {
                    var_r0_1936 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1936 = 5;
                } else {
                    var_r0_1936 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1936 = 4;
                break;
            }
            if (var_r0_1936 == 1) {
                var_f4_1891 = __float_nan;
            }
        }
        var_f3_1958 = 1.0f / var_f4_1891;
    } else {
        var_f3_1958 = 0.0f;
    }
    spD0 = (f32) spD0 * var_f3_1958;
    unkspD4 *= var_f3_1958;
    spD8 = (f32) spD8 * var_f3_1958;
    temp_r3_1973 = MKView_GetLightColor(0);
    sp130 = M2C_FIELD(temp_r3_1973, f64 *, 0);
    sp138 = M2C_FIELD(temp_r3_1973, f64 *, 8);
    MKView_GetLightColor(1);
    InterpolateLinear(spC0, *((MKVector4 *) &spF0), temp_f30_1867);
    sp140 = M2C_BITWISE(f64, spC0);
    sp148 = (f64) spC0.unk8;
    MKView_GetLightColor(2);
    InterpolateLinear(spB0, *((MKVector4 *) &spF0), temp_f30_1867);
    sp150 = M2C_BITWISE(f64, spB0);
    sp158 = (f64) spB0.unk8;
    temp_r3_2001 = MKView_GetLightDirection(0);
    sp100 = M2C_FIELD(temp_r3_2001, f64 *, 0);
    sp108 = M2C_FIELD(temp_r3_2001, f64 *, 8);
    MKView_GetLightDirection(1);
    InterpolateLinear(spA0, *((MKVector3 *) &spD0), temp_f30_1867);
    sp110 = M2C_BITWISE(f64, spA0);
    sp118 = (f64) spA0.unk8;
    MKView_GetLightDirection(2);
    InterpolateLinear(sp90, *((MKVector3 *) &spD0), temp_f30_1867);
    var_r29_2025 = 0;
    var_r30_2027 = 0;
    sp120 = M2C_BITWISE(f64, sp90);
    sp128 = (f64) sp90.unk8;
    do {
        MKView_SetLightColor(var_r29_2025, sp130 + var_r30_2027);
        MKView_SetLightDirection(var_r29_2025, sp100 + var_r30_2027);
        var_r29_2025 += 1;
        var_r30_2027 += 0x10;
    } while (var_r29_2025 < 3);
    if (temp_f30_1867 > 0.0f) {

    } else if (temp_f30_1867 < M2C_BITWISE(f32, 0.0)) {

    } else {
        spC = temp_f30_1867;
        temp_r3_2075 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_2075) {                     /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_2085 = 1;
            } else {
                var_r0_2085 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_2085 = 5;
            } else {
                var_r0_2085 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_2085 = 4;
            break;
        }
        if (var_r0_2085 == 1) {

        }
    }
    MKModel_GetColor(this->unk4);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
    sp50 = sp10;
    sp58 = sp18;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp40 = sp20;
    sp48 = sp28;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
    sp80 = sp30;
    sp88 = sp38;
    MKModel_SetColor(this->unk4, *((MKVector4 *) &sp80));
}
#endif

#if 0 // DRAFT: undefined identifier 'sp30'
void Spyro::UpdateLighting() {
    MKVector3 spC0;
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    M2C_UNK spA0;
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
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 var_f4_2267;
    f32 var_f5_2334;
    f64 temp_f1_2273;
    f64 temp_f1_2279;
    f64 temp_f1_2283;
    s32 temp_r3_2302;
    s32 var_r0_2312;

    if ((M2C_BITWISE(u32, this->unk1D0.unkC) != 0U) && (this->unk428 & 0x80000)) {
        sp40 = 0.0f;
        sp44 = 100.0f;
        sp48 = 0.0f;
        sp80 = (f64) sp40;
        sp88 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp90 = sp30;
        sp38 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) sp88;
        sp98 = (f64) sp38;
        spA0.CalculateLightPosForShadow(*((MKVector3 *) gb.unk80));
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spB0 = sp20;
        sp28 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) - spA8;
        spB8 = (f64) sp28;
        var_f4_2267 = ((f32) spB8 * (f32) spB8) + (((f32) spB0 * (f32) spB0) + (unkspB4 * unkspB4));
        if (var_f4_2267 > 0.000001f) {
            if (var_f4_2267 > 0.0f) {
                temp_f1_2273 = __frsqrte(var_f4_2267);
                temp_f1_2279 = 0.5 * temp_f1_2273 * -(((f64) var_f4_2267 * (temp_f1_2273 * temp_f1_2273)) - 3.0);
                temp_f1_2283 = 0.5 * temp_f1_2279 * -(((f64) var_f4_2267 * (temp_f1_2279 * temp_f1_2279)) - 3.0);
                var_f4_2267 = (f32) ((f64) var_f4_2267 * (0.5 * temp_f1_2283 * -(((f64) var_f4_2267 * (temp_f1_2283 * temp_f1_2283)) - 3.0)));
            } else if (var_f4_2267 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2267 = __float_nan;
            } else {
                sp8 = var_f4_2267;
                temp_r3_2302 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2302) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2312 = 1;
                    } else {
                        var_r0_2312 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2312 = 5;
                    } else {
                        var_r0_2312 = 3;
                    }
                    break;
                default:
                    var_r0_2312 = 4;
                    break;
                }
                if (var_r0_2312 == 1) {
                    var_f4_2267 = __float_nan;
                }
            }
            var_f5_2334 = 1.0f / var_f4_2267;
        } else {
            var_f5_2334 = 0.0f;
        }
        spB0 = (f32) spB0 * var_f5_2334;
        unkspB4 *= var_f5_2334;
        spB8 = (f32) spB8 * var_f5_2334;
        KDMath_Slerp(sp70, *((MKVector3 *) &this->unk1D0), 6.2831855f * gUpdateTimeDelta);
        M2C_FIELD(this, f64 *, 0x1D0) = M2C_BITWISE(f64, sp70);
        M2C_FIELD(this, f64 *, 0x1D8) = (f64) sp70.unk8;
        this->unk1D0.GetLightPos(&spC0);
        sp60 = M2C_BITWISE(f64, spC0);
        sp68 = (f64) spC0.unk8;
        this->unk428.SetLight((MKVector3) &sp60, 0.5f);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_FIELD(this, f64 *, 0x430) = sp10;
        sp18 = this->unk430.unk10 * (1.0f / this->unk430.unk18);
        sp50 = sp10;
        M2C_FIELD(this, f64 *, 0x438) = (f64) sp18;
        sp58 = (f64) sp18;
        this->unk430.unk1C = 0.5f / this->unk430.unk18;
        this->unk430.unk18 = 0.0f;
        this->unk430.unk8 = 0.0f;
        this->unk430.unkC = 0.0f;
        this->unk430.unk10 = 0.0f;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp74'
u8 Spyro::SelectBestKnockedUpEnemy() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Enemy *temp_r3_2431;
    Enemy *var_r0_2606;
    Enemy *var_r31_2423;
    TargetManager ***var_r29_2425;
    TargetManager **temp_r3_2615;
    f32 temp_f29_2445;
    f32 temp_f29_2592;
    f32 temp_f3_2577;
    f32 temp_f4_2567;
    f32 temp_f5_2574;
    f32 var_f30_2421;
    f32 var_f31_2489;
    f32 var_f6_2556;
    f64 temp_f1_2495;
    f64 temp_f1_2501;
    f64 temp_f1_2505;
    s32 temp_r3_2524;
    s32 var_r0_2534;
    u8 var_r0_2451;
    void *temp_r4_2435;
    void *temp_r4_2562;
    void *temp_r5_2434;
    void *temp_r6_2463;
    void *temp_r6_2471;

    var_f30_2421 = -1.0f;
    var_r31_2423 = NULL;
    var_r29_2425 = gb.unk20->Begin();
loop_34:
    temp_r3_2615 = *var_r29_2425;
    if (temp_r3_2615 != NULL) {
        temp_r3_2431 = ((Enemy *(*)()) (*temp_r3_2615)->unk8.unk4)();
        if (temp_r3_2431 != NULL) {
            temp_r5_2434 = this->unk8;
            temp_r4_2435 = temp_r3_2431->unk8;
            sp60 = M2C_FIELD(temp_r5_2434, f64 *, 0x30);
            sp70 = M2C_FIELD(temp_r4_2435, f64 *, 0x30);
            sp68 = M2C_FIELD(temp_r5_2434, f64 *, 0x38);
            temp_f29_2445 = unksp74 - unksp64;
            sp78 = M2C_FIELD(temp_r4_2435, f64 *, 0x38);
            if (temp_r3_2431->IsKnockedUp() != 0) {
                var_r0_2451 = 0;
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (temp_f29_2445 == 100.0f) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (temp_f29_2445 == 900.0f) {
                        var_r0_2451 = 1;
                    }
                }
                if (var_r0_2451 != 0) {
                    temp_r6_2463 = this->unk8;
                    sp30 = M2C_FIELD(temp_r6_2463, f64 *, 0x30);
                    sp38 = M2C_FIELD(temp_r6_2463, f64 *, 0x38);
                    temp_r6_2471 = temp_r3_2431->unk8;
                    sp40 = M2C_FIELD(temp_r6_2471, f64 *, 0x30);
                    sp48 = M2C_FIELD(temp_r6_2471, f64 *, 0x38);
                    KDMath_Sub2D(sp50, *((MKVector3 *) &sp40));
                    sp80 = M2C_BITWISE(f64, sp50);
                    sp88 = (f64) sp50.unk8;
                    var_f31_2489 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (unksp84 * unksp84));
                    if (var_f31_2489 > 0.000001f) {
                        if (var_f31_2489 > 0.0f) {
                            temp_f1_2495 = __frsqrte(var_f31_2489);
                            temp_f1_2501 = 0.5 * temp_f1_2495 * -(((f64) var_f31_2489 * (temp_f1_2495 * temp_f1_2495)) - 3.0);
                            temp_f1_2505 = 0.5 * temp_f1_2501 * -(((f64) var_f31_2489 * (temp_f1_2501 * temp_f1_2501)) - 3.0);
                            var_f31_2489 = (f32) ((f64) var_f31_2489 * (0.5 * temp_f1_2505 * -(((f64) var_f31_2489 * (temp_f1_2505 * temp_f1_2505)) - 3.0)));
                        } else if (var_f31_2489 < M2C_BITWISE(f32, 0.0)) {
                            var_f31_2489 = __float_nan;
                        } else {
                            sp8 = var_f31_2489;
                            temp_r3_2524 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_2524) { /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2534 = 1;
                                } else {
                                    var_r0_2534 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_2534 = 5;
                                } else {
                                    var_r0_2534 = 3;
                                }
                                break;
                            default:
                                var_r0_2534 = 4;
                                break;
                            }
                            if (var_r0_2534 == 1) {
                                var_f31_2489 = __float_nan;
                            }
                        }
                        var_f6_2556 = 1.0f / var_f31_2489;
                    } else {
                        var_f6_2556 = 0.0f;
                        var_f31_2489 = 0.0f;
                    }
                    temp_r4_2562 = this->unk8;
                    temp_f4_2567 = unksp84 * var_f6_2556;
                    sp10 = -M2C_FIELD(temp_r4_2562, f32 *, 0x20);
                    temp_f5_2574 = (f32) sp80 * var_f6_2556;
                    sp14 = -M2C_FIELD(temp_r4_2562, f32 *, 0x24);
                    temp_f3_2577 = (f32) sp88 * var_f6_2556;
                    sp18 = -M2C_FIELD(temp_r4_2562, f32 *, 0x28);
                    sp20 = (f64) sp10;
                    sp28 = (f64) sp18;
                    sp80 = temp_f5_2574;
                    unksp84 = temp_f4_2567;
                    temp_f29_2592 = ((f32) sp28 * temp_f3_2577) + (((f32) sp20 * temp_f5_2574) + (unksp24 * temp_f4_2567));
                    sp88 = temp_f3_2577;
                    if (((var_f31_2489 - temp_r3_2431->GetCollisionRadius(temp_r4_2562, (f32) sp20, (f32) sp28, temp_f3_2577, temp_f4_2567, temp_f5_2574)) < 400.0f) && (temp_f29_2592 > 0.0f) && (temp_f29_2592 > var_f30_2421)) {
                        var_r0_2606 = temp_r3_2431;
                        if (temp_r3_2431 != NULL) {
                            var_r0_2606 = (Enemy *) &temp_r3_2431->unk110.unk5A8;
                        }
                        var_r31_2423 = var_r0_2606;
                        var_f30_2421 = temp_f29_2592;
                    }
                }
            }
        }
        var_r29_2425 += 4;
        goto loop_34;
    }
    if (var_r31_2423 != NULL) {
        this->unk430.unk28.SetLastCombatEnemy((Targetable *) var_r31_2423);
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Spyro::UpdateMeleeButtonState(bool arg0) {
    InputModifier *temp_r3_2649;
    InputModifier *temp_r3_2675;
    InputModifier *temp_r3_2745;
    f32 var_f1_2758;
    s32 var_r31_2662;
    s32 var_r3_2688;
    u8 temp_r0_2775;
    u8 temp_r4_2712;
    u8 var_r29_2671;
    u8 var_r3_2720;
    u8 var_r4_2651;
    u8 var_r4_2677;
    u8 var_r4_2747;

    temp_r3_2649 = GetInput();
    var_r4_2651 = 0;
    if (((u8) temp_r3_2649->unk5 != 0) || ((u8) temp_r3_2649->unk4 != 0)) {
        var_r4_2651 = 1;
    }
    if (var_r4_2651 != 0) {
        var_r31_2662 = 0;
    } else {
        var_r31_2662 = MKInput_Released(0xD, (MKInputDevices) temp_r3_2649->unk0);
    }
    var_r29_2671 = 1;
    if ((u8) this->unk4CE == 0) {
        temp_r3_2675 = GetInput();
        var_r4_2677 = 0;
        if (((u8) temp_r3_2675->unk5 != 0) || ((u8) temp_r3_2675->unk4 != 0)) {
            var_r4_2677 = 1;
        }
        if (var_r4_2677 != 0) {
            var_r3_2688 = 0;
        } else {
            var_r3_2688 = MKInput_Pressed(0xD, (MKInputDevices) temp_r3_2675->unk0);
        }
        if ((u8) var_r3_2688 == 0) {
            var_r29_2671 = 0;
        }
    }
    this->unk4CE = var_r29_2671;
    if ((u8) this->unk4CF != 0) {
        this->unk4C8 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk4C8 == 0.0f) {
            temp_r4_2712 = this->unk4CC;
            if ((temp_r4_2712 != 0) || ((u8) this->unk4CD != 0)) {
                var_r3_2720 = 0;
                if (((u8) this->unk4CD != 0) || (temp_r4_2712 != 0)) {
                    var_r3_2720 = 1;
                }
                this->unk4CE = var_r3_2720;
                this->unk4CD = 0;
                this->unk4CC = 0;
                this->unk4C4 = 0.0f;
            }
            this->unk4C8 = fMeleeButtonTimeout;
        }
    }
    if (((u8) this->unk4CD == 0) && ((u8) this->unk4CC == 0)) {
        temp_r3_2745 = GetInput();
        var_r4_2747 = 0;
        if (((u8) temp_r3_2745->unk5 != 0) || ((u8) temp_r3_2745->unk4 != 0)) {
            var_r4_2747 = 1;
        }
        if (var_r4_2747 != 0) {
            var_f1_2758 = 0.0f;
        } else {
            var_f1_2758 = MKInput_GetState(0xD, (MKInputDevices) temp_r3_2745->unk0, NULL, NULL);
        }
        if (var_f1_2758 != 0.0f) {
            this->unk4C4 += gUpdateTimeDelta;
        }
        temp_r0_2775 = this->unk4CE;
        if ((temp_r0_2775 != 0) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((this->unk4C4 == fMaxKnockupHoldButtonTime) != 0))) {
            this->unk4CC = 1;
            this->unk4C4 = 0.0f;
            this->unk4CE = 0;
        } else if ((temp_r0_2775 != 0) && ((u8) var_r31_2662 != 0)) {
            this->unk4CD = 1;
            this->unk4C4 = 0.0f;
            this->unk4CE = 0;
        }
    }
    if ((u8) var_r31_2662 != 0) {
        this->unk4C4 = 0.0f;
    }
    GetMeleeButtonState();
}
#endif

s32 Spyro::GetMeleeButtonState() {
    s32 temp_r3_2827;

    if ((u8) this->unk4CD != 0) {
        return 1;
    }
    temp_r3_2827 = 0 - this->unk4CC;
    return 2 & ((temp_r3_2827 - temp_r3_2827) - !M2C_CARRY);
}

#if 0 // DRAFT: undefined identifier 'unk4C8'
void Spyro::SetMeleeButtonStateTimeout(bool arg0) {
    this->unk4CF = arg0;
    this->unk4C8 = 0.0f;
    if ((u8) this->unk4CF != 0) {
        this->unk4C8 = fMeleeButtonTimeout;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C4'
void Spyro::ClearMeleeButtonState() {
    this->unk4CC = 0;
    this->unk4CD = 0;
    this->unk4CE = 0;
    this->unk4C4 = 0.0f;
    this->unk4CF = 0;
    this->unk4C8 = 0.0f;
}
#endif

#if 0 // DRAFT: expression syntax error
void Spyro::GetCombatHitType(int arg0) {
    this->unk430.unk28.GetHitType();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3 *' to
s32 Spyro::ChargeCombatArcTest() {
    MKCollisionResult spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    u8 sp80;
    f32 sp7C;
    f32 sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    M2C_UNK *temp_r29_2895;
    MKProp **temp_r6_3007;
    MKProp **var_r3_2988;
    MKProp *temp_r0_2997;
    MKProp *var_r28_2981;
    MKVector3 *temp_r4_2974;
    f32 temp_f31_2899;
    s32 temp_r29_2967;
    s32 var_r27_2969;
    s32 var_r30_2970;
    void *temp_r3_2978;
    void *temp_r4_2894;
    void *temp_r6_3010;

    temp_r4_2894 = this->unk8;
    temp_r29_2895 = &this->unk4F8;
    temp_f31_2899 = _table_sinf(1.5707964f + M2C_FIELD(this->unk4F0, f32 *, 0x14));
    sp7C = 0.0f;
    sp18 = -M2C_FIELD(temp_r4_2894, f32 *, 0x20);
    sp1C = -M2C_FIELD(temp_r4_2894, f32 *, 0x24);
    sp20 = -M2C_FIELD(temp_r4_2894, f32 *, 0x28);
    sp80 = 0;
    sp78 = 1.9e-43f;
    sp98 = (f64) sp18;
    spA0 = (f64) sp20;
    MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(this->unk4F0, s32 *, 4), (MKVector3 *) temp_r29_2895);
    if ((u8) M2C_FIELD(this->unk4F0, u8 *, 9) != 0) {
        sp58.GetDir();
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp68 = sp8;
        sp10 = sp60 * 100.0f;
        sp70 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        this->unk500 += (f32) sp70;
    }
loop_3:
    if ((MKProp *) *this->unk6F0 != NULL) {
        this->unk6F0 += 4;
        goto loop_3;
    }
    temp_r29_2967 = MKCollision_SphereCollide(*((MKVector3 *) temp_r29_2895), M2C_FIELD(this->unk4F0, f32 *, 0x10), &spA8, 0x14, (MKCollisionMode) 2, 0x04200000);
    var_r27_2969 = 0;
    var_r30_2970 = 0;
loop_21:
    if (var_r27_2969 >= temp_r29_2967) {
        return 0;
    }
    temp_r4_2974 = &spA8 + var_r30_2970;
    if (((u8) M2C_FIELD(temp_r4_2974, u8 *, 0x50) != 0) && (temp_r3_2978 = M2C_FIELD(temp_r4_2974, void **, 0x48), ((temp_r3_2978 == NULL) == 0)) && (var_r28_2981 = M2C_FIELD(temp_r3_2978, MKProp **, 8), ((var_r28_2981 == NULL) == 0))) {

    } else {
        var_r28_2981 = NULL;
    }
    var_r3_2988 = this->unk6F0;
loop_14:
    temp_r0_2997 = *var_r3_2988;
    if (temp_r0_2997 == NULL) {
        var_r3_2988 = NULL;
    } else if (temp_r0_2997 == var_r28_2981) {

    } else {
        var_r3_2988 += 4;
        goto loop_14;
    }
    if (var_r3_2988 == NULL) {
        temp_r6_3007 = this->unk6F0 - 4;
        this->unk6F0 = temp_r6_3007;
        *temp_r6_3007 = var_r28_2981;
        temp_r6_3010 = this->unk8;
        sp28 = M2C_FIELD(temp_r6_3010, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r6_3010, f64 *, 0x38);
        KDMath_Sub2D(sp38, *temp_r4_2974);
        Normalise(sp48);
        sp88 = M2C_BITWISE(f64, sp48);
        sp90 = (f64) sp48.unk8;
        if ((((f32) sp90 * (f32) spA0) + (((f32) sp88 * (f32) sp98) + (unksp8C * unksp9C))) > temp_f31_2899) {
            var_r28_2981->Message(&sp78);
            if (sp80 != 0) {
                this->unk430.unk28.SetChargeHitProp(var_r28_2981);
                return 1;
            }
        }
    }
    var_r27_2969 += 1;
    var_r30_2970 += 0x58;
    goto loop_21;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void Spyro::StartCombatArc(int arg0) {
    void *temp_r6_3074;

    temp_r6_3074 = this + (arg0 << 5);
    M2C_FIELD(temp_r6_3074, f32 *, 0x4E8) = (f32) (gb.unk30C + M2C_FIELD(M2C_FIELD(temp_r6_3074, void **, 0x4D0), f32 *, 0xC));
    M2C_FIELD(temp_r6_3074, f64 *, 0x4D8) = (f64) M2C_FIELD(&zero, f64 *, 0);
    M2C_FIELD(temp_r6_3074, f64 *, 0x4E0) = (f64) M2C_FIELD(&zero, f64 *, 8);
loop_2:
    if ((MKProp *) *this->unk6F0 != NULL) {
        this->unk6F0 += 4;
        goto loop_2;
    }
    this->unk430.unk28.SetHitTarget(0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'gameData'
void Spyro::SetupMeleeAttackHitMsg(int arg0, MeleeAttackHitMsg *arg1) {
    f64 sp10;
    f64 sp8;
    f32 temp_r0_3128;
    f64 temp_f3_3209;
    f64 temp_f4_3207;
    s32 var_r0_3235;
    s32 var_r26_3126;
    s32 var_r30_3120;
    s32 var_r31_3116;
    void *temp_r3_3203;

    var_r31_3116 = 0;
    GetCombatHitType(arg0);
    var_r30_3120 = M2C_ERROR(/* Read from unset register $r3 */);
    var_r26_3126 = M2C_FIELD((checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0 * 0x1C)), s32 *, 0xF4);
    if ((u8) M2C_FIELD(this, u8 *, 0x25D) != 0) {
        temp_r0_3128 = this->unk24C;
        var_r26_3126 *= 2;
        switch (M2C_BITWISE(s32, temp_r0_3128)) {   /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            var_r31_3116 = 0x11;
            break;
        case 1:                                     /* switch 1 */
            var_r31_3116 = 0x22;
            break;
        case 2:                                     /* switch 1 */
            var_r31_3116 = 0x44;
            break;
        case 3:                                     /* switch 1 */
            var_r31_3116 = 0x88;
            if (var_r30_3120 != 2) {
                var_r30_3120 = 8;
            }
            break;
        }
    } else {
        switch ((s32) gameData.unk158) { /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            var_r31_3116 = 0x10;
            break;
        case 1:                                     /* switch 2 */
            var_r31_3116 = 0x20;
            break;
        case 2:                                     /* switch 2 */
            var_r31_3116 = 0x40;
            break;
        case 3:                                     /* switch 2 */
            var_r31_3116 = 0x80;
            break;
        }
    }
    if (IsInTailSweep() != 0) {
        var_r31_3116 |= 0x200;
    } else if (IsInTailStrike() != 0) {
        var_r31_3116 |= 0x400;
    } else if (this->unk430.unk28.GetCombatArc() == 1) {
        var_r31_3116 |= 0x100;
    }
    temp_r3_3203 = this->unk8;
    temp_f4_3207 = M2C_FIELD(temp_r3_3203, f64 *, 0x30);
    temp_f3_3209 = M2C_FIELD(temp_r3_3203, f64 *, 0x38);
    arg1->unk0 = 4;
    arg1->unk8 = this;
    arg1->unk10 = temp_f4_3207;
    arg1->unk18 = temp_f3_3209;
    arg1->unk20 = (f32) var_r26_3126;
    arg1->unk3C = 0;
    arg1->unk28 = var_r30_3120;
    arg1->unk30 = var_r31_3116;
    arg1->unk3D = 0;
    arg1->unk3E = 0;
    arg1->unk2C = -1;
    arg1->unk34 = NULL;
    arg1->unk38 = 0;
    arg1->unk24 = 1.0f;
    arg1->unk34 = &this->unk6F0;
    sp8 = temp_f4_3207;
    var_r0_3235 = GS_SpyroMeleeHit;
    sp10 = temp_f3_3209;
    if (arg0 == 3) {
        var_r0_3235 = GS_SpyroTailHit;
    }
    arg1->unk2C = var_r0_3235;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp20'
void Spyro::CombatArcCollisionTest(int arg0) {
    MKProp **var_r3_3340;
    MKProp *temp_r4_3349;
    MKProp *var_r0_3333;
    MKProp *var_r0_3428;
    MKProp *var_r20_3615;
    MKProp *var_r28_3302;
    MKProp *var_r3_3391;
    MKProp *var_r3_3446;
    MKProp *var_r3_3473;
    MKProp *var_r3_3640;
    MKProp *var_r4_3677;
    MKVector3 *temp_r27_3326;
    f32 temp_f0_3589;
    f32 temp_f0_3805;
    f32 temp_f31_3293;
    f32 var_f25_3296;
    f32 var_f4_3703;
    f32 var_f5_3735;
    f64 temp_f1_3740;
    f64 temp_f1_3746;
    f64 temp_f1_3750;
    s32 temp_r20_3553;
    s32 temp_r21_3272;
    s32 temp_r22_3318;
    s32 temp_r3_3769;
    s32 var_r0_3779;
    s32 var_r29_3322;
    s32 var_r31_3321;
    u8 var_r24_3299;
    u8 var_r25_3300;
    u8 var_r26_3301;
    u8 var_r3_3404;
    void *temp_r20_3273;
    void *temp_r3_3271;
    void *temp_r3_3330;
    void *temp_r3_3383;
    void *temp_r3_3443;
    void *temp_r3_3470;
    void *temp_r3_3494;
    void *temp_r3_3612;
    void *temp_r3_3637;
    void *temp_r3_3674;
    void *temp_r3_3707;
    void *temp_r4_3425;
    void *temp_r4_3706;
    void *temp_r5_3453;
    void *temp_r6_3356;

    temp_r3_3271 = this->unk8;
    temp_r21_3272 = arg0 << 5;
    temp_r20_3273 = this + temp_r21_3272;
    unksp20 = -M2C_FIELD(temp_r3_3271, f32 *, 0x20);
    unksp24 = -M2C_FIELD(temp_r3_3271, f32 *, 0x24);
    unksp28 = -M2C_FIELD(temp_r3_3271, f32 *, 0x28);
    unksp1E0 = unksp20;
    unksp1E8 = unksp28;
    temp_f31_3293 = _table_sinf(1.5707964f + M2C_FIELD(M2C_FIELD(temp_r20_3273, void **, 0x4D0), f32 *, 0x14));
    unksp234 = 0;
    var_f25_3296 = 3.4028235e38f;
    var_r24_3299 = 0;
    var_r25_3300 = 0;
    var_r26_3301 = 1;
    var_r28_3302 = NULL;
    SetupMeleeAttackHitMsg(arg0, (MeleeAttackHitMsg *) &unksp230);
    temp_r22_3318 = MKCollision_SphereCollide(*(this + (temp_r21_3272 + 0x4D8)), M2C_FIELD(M2C_FIELD(temp_r20_3273, void **, 0x4D0), f32 *, 0x10), (MKCollisionResult *) &unksp2C8, 0x14, (MKCollisionMode) 2, 0x04200000);
    var_r31_3321 = 0;
    var_r29_3322 = 0;
loop_71:
    if (var_r31_3321 < temp_r22_3318) {
        temp_r27_3326 = &unksp2C8 + var_r29_3322;
        if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3330 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r3_3330 == NULL) == 0)) && (var_r0_3333 = M2C_FIELD(temp_r3_3330, MKProp **, 8), ((var_r0_3333 == NULL) == 0))) {

        } else {
            var_r0_3333 = NULL;
        }
        var_r3_3340 = this->unk6F0;
loop_10:
        temp_r4_3349 = *var_r3_3340;
        if (temp_r4_3349 == NULL) {
            var_r3_3340 = NULL;
        } else if (temp_r4_3349 == var_r0_3333) {

        } else {
            var_r3_3340 += 4;
            goto loop_10;
        }
        if (var_r3_3340 == NULL) {
            temp_r6_3356 = this->unk8;
            unksp170 = M2C_FIELD(temp_r6_3356, f64 *, 0x30);
            unksp178 = M2C_FIELD(temp_r6_3356, f64 *, 0x38);
            KDMath_Sub2D(*((MKVector3 *) &unksp180), *temp_r27_3326);
            Normalise(*((MKVector3 *) &unksp190));
            unksp1D0 = unksp190;
            unksp1D8 = unksp198;
            if (!(((unksp1E8 * unksp1D8) + ((unksp1E0 * unksp1D0) + (unksp1E4 * unksp1D4))) < temp_f31_3293)) {
                temp_r3_3383 = M2C_FIELD(temp_r27_3326, void **, 0x48);
                unksp26E = 0;
                unksp26D = 0;
                unksp268 = temp_r3_3383;
                if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3383 != NULL) && (var_r3_3391 = M2C_FIELD(temp_r3_3383, MKProp **, 8), ((var_r3_3391 == NULL) == 0))) {

                } else {
                    var_r3_3391 = NULL;
                }
                M2C_FIELD(var_r3_3391->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&unksp230);
                var_r3_3404 = 0;
                if ((var_r25_3300 != 0) || (unksp26E != 0)) {
                    var_r3_3404 = 1;
                }
                var_r25_3300 = var_r3_3404;
                if ((unksp26D != 0) && ((var_r28_3302 == NULL) || (M2C_FIELD(temp_r27_3326, f32 *, 0x40) < var_f25_3296))) {
                    if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r4_3425 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r4_3425 == NULL) == 0)) && (var_r0_3428 = M2C_FIELD(temp_r4_3425, MKProp **, 8), ((var_r0_3428 == NULL) == 0))) {

                    } else {
                        var_r0_3428 = NULL;
                    }
                    var_r28_3302 = var_r0_3428;
                    var_f25_3296 = M2C_FIELD(temp_r27_3326, f32 *, 0x40);
                }
                if (var_r3_3404 != 0) {
                    if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3443 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r3_3443 == NULL) == 0)) && (var_r3_3446 = M2C_FIELD(temp_r3_3443, MKProp **, 8), ((var_r3_3446 == NULL) == 0))) {

                    } else {
                        var_r3_3446 = NULL;
                    }
                    temp_r5_3453 = var_r3_3446->unk8;
                    unksp1C0 = M2C_FIELD(temp_r5_3453, f64 *, 0x30);
                    unksp1C8 = M2C_FIELD(temp_r5_3453, f64 *, 0x38);
                    unksp214 = 0;
                    unksp210 = 0x77;
                    unksp228 = 0;
                    unksp218 = 0.0f;
                    unksp21C = 0.0f;
                    unksp220 = 0.0f;
                    if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3470 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r3_3470 == NULL) == 0)) && (var_r3_3473 = M2C_FIELD(temp_r3_3470, MKProp **, 8), ((var_r3_3473 == NULL) == 0))) {

                    } else {
                        var_r3_3473 = NULL;
                    }
                    M2C_FIELD(var_r3_3473->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&unksp210);
                    if (unksp228 != 0) {
                        unksp1C0 = unksp218;
                        unksp1C8 = unksp220;
                    }
                    temp_r3_3494 = this->unk8;
                    unksp88 = 0.0f;
                    unksp80 = 0.0f;
                    unksp84 = 125.0f;
                    unksp130 = M2C_FIELD(temp_r3_3494, f64 *, 0x30);
                    unksp120 = unksp80;
                    unksp128 = unksp88;
                    unksp138 = M2C_FIELD(temp_r3_3494, f64 *, 0x38);
                    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f1, $f4 */);
                    unksp140 = unkspB0;
                    unkspB8 = unksp138 - unksp1C8;
                    unksp148 = unkspB8;
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f30 */);
                    unksp150 = unkspA0;
                    unkspA8 = unksp148 * 0.5f;
                    unksp158 = unkspA8;
                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f4, $f1 */);
                    unksp160 = unksp90;
                    unksp98 = unksp1C8 + unksp158;
                    unksp168 = unksp98;
                    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                    unksp68 = 0.0f;
                    unksp60 = 0.0f;
                    temp_r20_3553 = gameData.unk158;
                    unksp64 = 1.0f;
                    unksp78 = unksp168 + unksp128;
                    unksp1B0 = unksp70;
                    unksp1B8 = unksp78;
                    unksp110 = 0.0;
                    unksp118 = unksp68;
                    ((HitFX *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), HitFX **, 0x10)))->Trigger(*((MKVector3 *) &unksp1B0), *((MKVector3 *) &unksp110), *(gameData.unk70.GetCurrentBreathColor()), temp_r20_3553);
                    if (var_r26_3301 != 0) {
                        unksp1F4 = 0;
                        MKVector(1.0f, 1.0f, 1.0f);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                        temp_f0_3589 = unkspF8 * 200.0f;
                        unksp1F0 = 0x417;
                        unksp1F8 = unksp10;
                        unksp18 = temp_f0_3589;
                        unksp208 = 1;
                        unksp200 = (f64) temp_f0_3589;
                        unksp100 = unksp10;
                        unksp108 = (f64) temp_f0_3589;
                        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &unksp1F0, unksp10);
                        var_r26_3301 = 0;
                    }
                    this->unk430.unk28.GetLastCombatEnemy();
                    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                        if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3612 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r3_3612 == NULL) == 0)) && (var_r20_3615 = M2C_FIELD(temp_r3_3612, MKProp **, 8), ((var_r20_3615 == NULL) == 0))) {

                        } else {
                            var_r20_3615 = NULL;
                        }
                        this->unk430.unk28.GetLastCombatEnemy();
                        if (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 8)() == var_r20_3615) {
                            this->unk430.unk28.SetHitTarget(1U);
                        }
                    }
                    if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3637 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r3_3637 == NULL) == 0)) && (var_r3_3640 = M2C_FIELD(temp_r3_3637, MKProp **, 8), ((var_r3_3640 == NULL) == 0))) {

                    } else {
                        var_r3_3640 = NULL;
                    }
                    if ((M2C_FIELD(var_r3_3640->unk0, s32 *, 0xC) & 0x208) && (var_r24_3299 == 0) && ((this->unk430.unk28.GetLastCombatEnemy(), (((u32) M2C_ERROR(/* Read from unset register $r3 */) == 0U) != 0)) || (this->unk430.unk28.GetLastCombatEnemy(), ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x20)() == 0) == 0)))) {
                        this->unk430.unk28.SetTargetDir(0U, zero);
                        if (((u8) M2C_FIELD(temp_r27_3326, u8 *, 0x50) != 0) && (temp_r3_3674 = M2C_FIELD(temp_r27_3326, void **, 0x48), ((temp_r3_3674 == NULL) == 0)) && (var_r4_3677 = M2C_FIELD(temp_r3_3674, MKProp **, 8), ((var_r4_3677 == NULL) == 0))) {

                        } else {
                            var_r4_3677 = NULL;
                        }
                        this->unk430.unk28.SetLastCombatEnemy(var_r4_3677);
                        this->unk430.unk28.GetLastCombatEnemy();
                        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                            var_r24_3299 = 1;
                            this->unk430.unk28.SetHitTarget(1U);
                        }
                    }
                }
            }
        }
        var_r31_3321 += 1;
        var_r29_3322 += 0x58;
        goto loop_71;
    }
    if (var_r28_3302 != NULL) {
        var_f4_3703 = 0.0f;
        unksp274 = 0;
        temp_r4_3706 = var_r28_3302->unk8;
        temp_r3_3707 = this->unk8;
        unkspC0 = M2C_FIELD(temp_r4_3706, f64 *, 0x30);
        unkspD0 = M2C_FIELD(temp_r3_3707, f64 *, 0x30);
        unkspC8 = M2C_FIELD(temp_r4_3706, f64 *, 0x38);
        unkspD8 = M2C_FIELD(temp_r3_3707, f64 *, 0x38);
        unksp54 = 0.0f;
        unksp50 = unkspD0 - unkspC0;
        unksp58 = unkspD8 - unkspC8;
        unkspE0 = unksp50;
        unkspE8 = unksp58;
        var_f5_3735 = (unkspE8 * unkspE8) + ((unkspE0 * unkspE0) + (unkspE4 * unkspE4));
        if (var_f5_3735 > 1e-12f) {
            if (var_f5_3735 > 0.0f) {
                temp_f1_3740 = __frsqrte(var_f5_3735);
                temp_f1_3746 = 0.5 * temp_f1_3740 * -(((f64) var_f5_3735 * (temp_f1_3740 * temp_f1_3740)) - 3.0);
                temp_f1_3750 = 0.5 * temp_f1_3746 * -(((f64) var_f5_3735 * (temp_f1_3746 * temp_f1_3746)) - 3.0);
                var_f5_3735 = (f32) ((f64) var_f5_3735 * (0.5 * temp_f1_3750 * -(((f64) var_f5_3735 * (temp_f1_3750 * temp_f1_3750)) - 3.0)));
            } else if (var_f5_3735 < M2C_BITWISE(f32, 0.0)) {
                var_f5_3735 = __float_nan;
            } else {
                unksp8 = var_f5_3735;
                temp_r3_3769 = unksp8 & 0x7F800000;
                switch (temp_r3_3769) {             /* irregular */
                case 0x7F800000:
                    if (unksp8 & 0x7FFFFF) {
                        var_r0_3779 = 1;
                    } else {
                        var_r0_3779 = 2;
                    }
                    break;
                case 0x0:
                    if (unksp8 & 0x7FFFFF) {
                        var_r0_3779 = 5;
                    } else {
                        var_r0_3779 = 3;
                    }
                    break;
                default:
                    var_r0_3779 = 4;
                    break;
                }
                if (var_r0_3779 == 1) {
                    var_f5_3735 = __float_nan;
                }
            }
            var_f4_3703 = 1.0f / var_f5_3735;
        }
        temp_f0_3805 = unkspE8 * var_f4_3703;
        unksp44 = unkspE4 * var_f4_3703;
        unksp40 = unkspE0 * var_f4_3703;
        unksp48 = temp_f0_3805;
        unksp1A0 = unksp40;
        unksp1A8 = (f64) temp_f0_3805;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        unksp1A8 = temp_f0_3805 * 500.0f;
        unksp270 = 7;
        unksp298 = 6;
        unksp29C = var_r28_3302;
        unksp278 = unksp1A0;
        unksp280 = unksp1A8;
        unksp2B0 = 1;
        unksp2BC = 1;
        unksp2B8 = 0.0f;
        unksp2B1 = 0;
        unksp2B2 = 0;
        unksp2B4 = -1;
        unksp288 = M2C_FIELD(&one, f64 *, 0);
        unksp290 = M2C_FIELD(&one, f64 *, 8);
        unksp2C0 = 0;
        if (var_r28_3302 != NULL) {
            unksp30.GetPos();
            unksp2A0 = unksp30;
            unksp2A8 = unksp38;
        } else {
            unksp2A0 = 0.0f;
            unksp2A4 = 0.0f;
            unksp2A8 = 0.0f;
        }
        unksp2C1 = 0;
        Hurt((HurtMessage *) &unksp270);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void Spyro::UpdateCombatArcs() {
    MKProp sp18;
    f32 sp10;
    f32 temp_f0_3920;
    f32 temp_f1_3921;
    f32 temp_f2_3922;
    f32 var_f0_3910;
    s32 var_r27_3902;
    s32 var_r31_3904;
    void *temp_r29_3906;

    var_r27_3902 = 0;
    var_r31_3904 = 0;
    do {
        temp_r29_3906 = this + var_r31_3904;
        var_f0_3910 = M2C_FIELD(temp_r29_3906, f32 *, 0x4E8) - gb.unk30C;
        if (var_f0_3910 > 0.0f) {

        } else {
            var_f0_3910 = 0.0f;
        }
        if (var_f0_3910 != 0.0f) {
            temp_f0_3920 = M2C_FIELD(temp_r29_3906, f32 *, 0x4DC);
            temp_f1_3921 = M2C_FIELD(temp_r29_3906, f32 *, 0x4D8);
            temp_f2_3922 = M2C_FIELD(temp_r29_3906, f32 *, 0x4E0);
            if ((((temp_f2_3922 * temp_f2_3922) + ((temp_f1_3921 * temp_f1_3921) + (temp_f0_3920 * temp_f0_3920))) == 0.0f) || ((u8) M2C_FIELD(M2C_FIELD(temp_r29_3906, void **, 0x4D0), u8 *, 8) == 0)) {
                MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(M2C_FIELD(temp_r29_3906, void **, 0x4D0), s32 *, 4), temp_r29_3906 + 0x4D8);
                if ((u8) M2C_FIELD(M2C_FIELD(temp_r29_3906, void **, 0x4D0), u8 *, 9) != 0) {
                    sp18.GetDir();
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                    sp18.unk10 = sp8;
                    sp10 = M2C_BITWISE(f32, sp18.unk8) * 100.0f;
                    sp18.unk18 = (f64) sp10;
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
                    M2C_FIELD(temp_r29_3906, f32 *, 0x4E0) = (f32) (M2C_FIELD(temp_r29_3906, f32 *, 0x4E0) + M2C_BITWISE(f32, sp18.unk18));
                }
            }
            CombatArcCollisionTest(var_r27_3902);
        }
        var_r27_3902 += 1;
        var_r31_3904 += 0x20;
    } while (var_r27_3902 < 0x11);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 Spyro::ChooseCombatTarget(MKVector3 *arg0, MKVector3 *arg1) {
    f64 sp1A0;                                      /* compiler-managed */
    f64 sp198;                                      /* compiler-managed */
    f64 sp190;                                      /* compiler-managed */
    f64 sp188;                                      /* compiler-managed */
    f64 sp178;
    f64 sp170;                                      /* compiler-managed */
    f64 sp168;                                      /* compiler-managed */
    MKProp sp148;
    M2C_UNK sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;                                       /* compiler-managed */
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;                                       /* compiler-managed */
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    MKProp spA8;
    M2C_UNK sp98;
    f64 sp90;
    f64 sp88;
    M2C_UNK sp78;
    MKVector3 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    TargetManager **var_r29_4007;
    Targetable *var_r30_4005;
    f32 temp_f1_4255;
    f32 temp_f1_4571;
    f32 temp_f2_4085;
    f32 temp_f2_4254;
    f32 temp_f2_4570;
    f32 temp_f3_4441;
    f32 var_f1_4447;
    f32 var_f2_4436;
    f32 var_f31_4177;
    f32 var_f31_4493;
    f32 var_f3_4244;
    f32 var_f3_4375;
    f32 var_f3_4560;
    f32 var_f4_4308;
    f64 temp_f1_4183;
    f64 temp_f1_4189;
    f64 temp_f1_4193;
    f64 temp_f1_4279;
    f64 temp_f1_4314;
    f64 temp_f1_4320;
    f64 temp_f1_4324;
    f64 temp_f1_4398;
    f64 temp_f1_4499;
    f64 temp_f1_4505;
    f64 temp_f1_4509;
    s32 temp_r3_4212;
    s32 temp_r3_4343;
    s32 temp_r3_4528;
    s32 var_r0_4222;
    s32 var_r0_4353;
    s32 var_r0_4538;
    u8 var_r0_4434;
    void **temp_r28_4011;
    void **var_r31_4003;
    void *temp_r3_4405;
    void *temp_r4_4009;
    void *temp_r4_4080;
    void *temp_r4_4277;
    void *temp_r4_4396;
    void *temp_r6_4287;

    this->unk430.unk28.GetLastCombatEnemy();
    var_r31_4003 = M2C_ERROR(/* Read from unset register $r3 */);
    var_r30_4005 = this->unk1B4.Get();
    var_r29_4007 = NULL;
    this->unkB90.GetCurrentTarget();
    temp_r4_4009 = this->unk8;
    temp_r28_4011 = M2C_ERROR(/* Read from unset register $r3 */);
    sp58 = -M2C_FIELD(temp_r4_4009, f32 *, 0x20);
    sp5C = -M2C_FIELD(temp_r4_4009, f32 *, 0x24);
    sp60 = -M2C_FIELD(temp_r4_4009, f32 *, 0x28);
    sp198 = (f64) sp58;
    sp1A0 = (f64) sp60;
    sp188 = (f64) sp58;
    sp190 = (f64) sp60;
    if ((var_r31_4003 != NULL) && (M2C_FIELD(*var_r31_4003, u8 (**)(void **), 0x20)(var_r31_4003) != 0)) {
        var_r31_4003 = NULL;
    }
    if ((var_r30_4005 != NULL) && (var_r30_4005->HasHitFloor() == 0) && (var_r30_4005->HasHitWall() == 0)) {
        var_r30_4005 = NULL;
    }
    if ((((InputModifier *) (GetInput()))->GetLeftX() != 0.0f) || (((InputModifier *) (GetInput()))->GetLeftY() != 0.0f)) {
        KDMath_GetDirection(3.1415927f + GetJoyYaw());
        sp188 = sp178;
        sp190 = sp180;
        temp_r4_4080 = this->unk8;
        temp_f2_4085 = _table_sinf(3.1415925f);
        sp168 = M2C_FIELD(temp_r4_4080, f64 *, 0x30);
        sp170 = M2C_FIELD(temp_r4_4080, f64 *, 0x38);
        var_r29_4007 = gb.unk20->GetNearestFacingEnemy(*((MKVector3 *) &sp168), 300.0f + SPYRO_COMBAT_SCALE_MAG, *((MKVector3 *) &sp188), temp_f2_4085, 1U, 1U);
    }
    if (this->unk7C.GetState() != 2) {
        if ((var_r30_4005 != NULL) && (var_r30_4005->Deinit() != NULL) && (((Enemy *) (var_r30_4005->Deinit()))->IsKnockedUp() != 0)) {
            var_r30_4005 = NULL;
        }
        if ((var_r29_4007 != NULL) && (((u32 (*)(TargetManager **)) (*var_r29_4007)->unk8.unk4)(var_r29_4007) != 0U) && (((Enemy *) (((Enemy *(*)(TargetManager **)) (*var_r29_4007)->unk8.unk4)(var_r29_4007)))->IsKnockedUp() != 0)) {
            var_r29_4007 = NULL;
        }
    }
    if (var_r29_4007 != NULL) {
        sp138.GetPos();
        (*var_r29_4007)->unk8.unk0(var_r29_4007);
        sp148.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp198 = sp48;
        sp50 = M2C_BITWISE(f32, sp148.unk8) - sp140;
        sp1A0 = (f64) sp50;
        sp148.unk10 = sp48;
        sp148.unk18 = (f64) sp50;
        var_f31_4177 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + (unksp19C * unksp19C));
        if (var_f31_4177 > 0.000001f) {
            if (var_f31_4177 > 0.0f) {
                temp_f1_4183 = __frsqrte(var_f31_4177);
                temp_f1_4189 = 0.5 * temp_f1_4183 * -(((f64) var_f31_4177 * (temp_f1_4183 * temp_f1_4183)) - 3.0);
                temp_f1_4193 = 0.5 * temp_f1_4189 * -(((f64) var_f31_4177 * (temp_f1_4189 * temp_f1_4189)) - 3.0);
                var_f31_4177 = (f32) ((f64) var_f31_4177 * (0.5 * temp_f1_4193 * -(((f64) var_f31_4177 * (temp_f1_4193 * temp_f1_4193)) - 3.0)));
            } else if (var_f31_4177 < M2C_BITWISE(f32, 0.0)) {
                var_f31_4177 = __float_nan;
            } else {
                sp10 = var_f31_4177;
                temp_r3_4212 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_4212) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4222 = 1;
                    } else {
                        var_r0_4222 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4222 = 5;
                    } else {
                        var_r0_4222 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_4222 = 4;
                    break;
                }
                if (var_r0_4222 == 1) {
                    var_f31_4177 = __float_nan;
                }
            }
            var_f3_4244 = 1.0f / var_f31_4177;
        } else {
            var_f3_4244 = 0.0f;
            var_f31_4177 = 0.0f;
        }
        temp_f2_4254 = (f32) sp198 * var_f3_4244;
        temp_f1_4255 = unksp19C * var_f3_4244;
        sp198 = temp_f2_4254;
        unksp19C = temp_f1_4255;
        sp1A0 = (f32) sp1A0 * var_f3_4244;
        if (var_f31_4177 > (SPYRO_COMBAT_SCALE_MAG + M2C_FIELD(*var_r29_4007, f32 (**)(TargetManager **, f32, f32), 0x38)(var_r29_4007, temp_f1_4255, temp_f2_4254))) {
            var_r29_4007 = NULL;
        } else {
            this->unk430.unk28.SetLastCombatEnemy((Targetable *) var_r29_4007);
        }
    }
    if (temp_r28_4011 != NULL) {
        temp_r4_4277 = this->unk8;
        temp_f1_4279 = M2C_FIELD(temp_r4_4277, f64 *, 0x30);
        sp108 = temp_f1_4279;
        sp110 = M2C_FIELD(temp_r4_4277, f64 *, 0x38);
        temp_r6_4287 = M2C_FIELD(M2C_FIELD(*temp_r28_4011, void *(**)(void **, void *, f64), 8)(temp_r28_4011, temp_r4_4277, temp_f1_4279), void **, 8);
        sp118 = M2C_FIELD(temp_r6_4287, f64 *, 0x30);
        sp120 = M2C_FIELD(temp_r6_4287, f64 *, 0x38);
        KDMath_Sub2D(sp128, *((MKVector3 *) &sp118));
        sp198 = M2C_BITWISE(f64, sp128);
        sp1A0 = (f64) sp128.unk8;
        var_f4_4308 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + (unksp19C * unksp19C));
        if (var_f4_4308 > 0.000001f) {
            if (var_f4_4308 > 0.0f) {
                temp_f1_4314 = __frsqrte(var_f4_4308);
                temp_f1_4320 = 0.5 * temp_f1_4314 * -(((f64) var_f4_4308 * (temp_f1_4314 * temp_f1_4314)) - 3.0);
                temp_f1_4324 = 0.5 * temp_f1_4320 * -(((f64) var_f4_4308 * (temp_f1_4320 * temp_f1_4320)) - 3.0);
                var_f4_4308 = (f32) ((f64) var_f4_4308 * (0.5 * temp_f1_4324 * -(((f64) var_f4_4308 * (temp_f1_4324 * temp_f1_4324)) - 3.0)));
            } else if (var_f4_4308 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4308 = __float_nan;
            } else {
                spC = var_f4_4308;
                temp_r3_4343 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_4343) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_4353 = 1;
                    } else {
                        var_r0_4353 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_4353 = 5;
                    } else {
                        var_r0_4353 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_4353 = 4;
                    break;
                }
                if (var_r0_4353 == 1) {
                    var_f4_4308 = __float_nan;
                }
            }
            var_f3_4375 = 1.0f / var_f4_4308;
        } else {
            var_f3_4375 = 0.0f;
        }
        sp198 = (f32) sp198 * var_f3_4375;
        unksp19C *= var_f3_4375;
        sp1A0 = (f32) sp1A0 * var_f3_4375;
    } else if (var_r29_4007 == NULL) {
        if (var_r31_4003 != NULL) {
            temp_r4_4396 = this->unk8;
            temp_f1_4398 = M2C_FIELD(temp_r4_4396, f64 *, 0x30);
            spC8 = temp_f1_4398;
            spD0 = M2C_FIELD(temp_r4_4396, f64 *, 0x38);
            temp_r3_4405 = M2C_FIELD(M2C_FIELD(*var_r31_4003, void *(**)(void **, void *, f64), 8)(var_r31_4003, temp_r4_4396, temp_f1_4398), void **, 8);
            spD8 = M2C_FIELD(temp_r3_4405, f64 *, 0x30);
            spE0 = M2C_FIELD(temp_r3_4405, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spE8 = sp38;
            sp40 = (f32) spE0 - (f32) spD0;
            spF0 = (f64) sp40;
            Normalise(spF8);
            sp198 = M2C_BITWISE(f64, spF8);
            sp1A0 = (f64) spF8.unk8;
        } else if (var_r30_4005 != NULL) {
            var_r0_4434 = 0;
            var_f2_4436 = this->unk178.unk28;
            temp_f3_4441 = (f32) fabs(this->unk178.unk4 - this->unk178.unk8);
            if (var_f2_4436 < 0.0f) {
                var_f2_4436 = -var_f2_4436;
            }
            if (var_f2_4436 < temp_f3_4441) {
                var_f1_4447 = this->unk178.unk2C;
                if (var_f1_4447 < 0.0f) {
                    var_f1_4447 = -var_f1_4447;
                }
                if (var_f1_4447 < temp_f3_4441) {
                    var_r0_4434 = 1;
                }
            }
            if (var_r0_4434 != 0) {
                sp98.GetPos();
                var_r30_4005->Init();
                spA8.GetPos();
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp198 = sp28;
                sp30 = M2C_BITWISE(f32, spA8.unk8) - spA0;
                sp1A0 = (f64) sp30;
                spA8.unk10 = sp28;
                spA8.unk18 = (f64) sp30;
                var_f31_4493 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + (unksp19C * unksp19C));
                if (var_f31_4493 > 0.000001f) {
                    if (var_f31_4493 > 0.0f) {
                        temp_f1_4499 = __frsqrte(var_f31_4493);
                        temp_f1_4505 = 0.5 * temp_f1_4499 * -(((f64) var_f31_4493 * (temp_f1_4499 * temp_f1_4499)) - 3.0);
                        temp_f1_4509 = 0.5 * temp_f1_4505 * -(((f64) var_f31_4493 * (temp_f1_4505 * temp_f1_4505)) - 3.0);
                        var_f31_4493 = (f32) ((f64) var_f31_4493 * (0.5 * temp_f1_4509 * -(((f64) var_f31_4493 * (temp_f1_4509 * temp_f1_4509)) - 3.0)));
                    } else if (var_f31_4493 < M2C_BITWISE(f32, 0.0)) {
                        var_f31_4493 = __float_nan;
                    } else {
                        sp8 = var_f31_4493;
                        temp_r3_4528 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_4528) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_4538 = 1;
                            } else {
                                var_r0_4538 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_4538 = 5;
                            } else {
                                var_r0_4538 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_4538 = 4;
                            break;
                        }
                        if (var_r0_4538 == 1) {
                            var_f31_4493 = __float_nan;
                        }
                    }
                    var_f3_4560 = 1.0f / var_f31_4493;
                } else {
                    var_f3_4560 = 0.0f;
                    var_f31_4493 = 0.0f;
                }
                temp_f2_4570 = (f32) sp198 * var_f3_4560;
                temp_f1_4571 = unksp19C * var_f3_4560;
                sp198 = temp_f2_4570;
                unksp19C = temp_f1_4571;
                sp1A0 = (f32) sp1A0 * var_f3_4560;
                if (var_f31_4493 > (SPYRO_COMBAT_SCALE_MAG + var_r30_4005->GetProp(temp_f1_4571, temp_f2_4570))) {
                    sp198 = sp148.unk40;
                    sp1A0 = sp148.unk48;
                } else {
                    this->unk430.unk28.SetLastCombatEnemy(var_r30_4005);
                }
            } else {
                goto block_100;
            }
        } else {
block_100:
            sp198 = sp148.unk40;
            sp1A0 = sp148.unk48;
        }
    }
    if (arg1 != NULL) {
        M2C_FIELD(arg1, f64 *, 0) = sp198;
        M2C_FIELD(arg1, f64 *, 8) = sp1A0;
    }
    if (arg0 != NULL) {
        sp68.operator*(SPYRO_COMBAT_SCALE_MAG);
        sp78.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(arg0, f64 *, 0) = sp18;
        sp20 = sp80 + sp68.unk8;
        sp88 = sp18;
        sp90 = (f64) sp20;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp20;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
u8 Spyro::IsInvincible() {
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (((gb.unk30C != M2C_FIELD(this, f32 *, 0x3DC)) && ((u8) M2C_FIELD(&gb, u8 *, 0x3B4) == 0)) || (this->unk428 & 0x4000)) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'Show'
void Spyro::Show() {
    M2C_FIELD(this, u8 *, 0x1C5) = 1U;
    this->unk1D0.Show(M2C_FIELD(this, u8 *, 0x1C5));
}
#endif

#if 0 // DRAFT: undefined identifier 'Show'
void Spyro::Hide() {
    M2C_FIELD(this, u8 *, 0x1C5) = 0U;
    this->unk1D0.Show(M2C_FIELD(this, u8 *, 0x1C5));
}
#endif

#if 0 // DRAFT: undefined identifier 'Show'
void Spyro::Disable() {
    Sparx *temp_r3_4727;

    this->unk18 = this->unk18 | 0x80000000;
    this->unk1D0.Show(0U);
    this->unk6F8.StopAll();
    M2C_FIELD(this, f32 *, 0x3DC) = (f32) (gb.unk30C + 0.0f);
    this->unk268 = 0;
    temp_r3_4727 = this->unkB70;
    if (temp_r3_4727 != NULL) {
        M2C_FIELD(temp_r3_4727->__vptr, M2C_UNK (**)(), 0x34)();
    }
    if ((u8) EventCamera_bRemainTargetable == 0) {
        this->unk4C.UnregisterTargetable();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Show'
void Spyro::Enable() {
    Sparx *temp_r3_4764;

    this->unk18 = this->unk18 & 0x7FFFFFFF;
    this->unk1D0.Show(1U);
    this->unk268 = 1;
    temp_r3_4764 = this->unkB70;
    if (temp_r3_4764 != NULL) {
        M2C_FIELD(temp_r3_4764->__vptr, M2C_UNK (**)(), 0x30)();
    }
    this->unk4C.RegisterTargetable();
}
#endif

u8 Spyro::IsInTailStrike() {
    return this->unk54.unk8 == 7;
}

u8 Spyro::IsInTailSweep() {
    return ((u32) this->unk428 >> 0x10U) & 1;
}

u8 Spyro::IsInMelee() {
    s32 temp_r0_4802;

    temp_r0_4802 = this->unk54.unk8;
    if ((temp_r0_4802 == 0xB) || (temp_r0_4802 == 0xC)) {
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: expression syntax error
u8 Spyro::IsCharging() {
    u8 var_r31_4820;

    var_r31_4820 = 0;
    if (((s32) this->unk54.unk8 == 1) || (this->unk430.unk28.GetChargeAttackActive() != 0)) {
        var_r31_4820 = 1;
    }
    return var_r31_4820;
}
#endif

void Spyro::GetYaw() {
    KDMath_GetYaw((Matrix *) this->unk8);
}

void Spyro::LandMediumExit() {

}

void Spyro::LandMediumUpdate() {

}

#if 0 // DRAFT: undefined identifier 'unk4C0'
void Spyro::LandMediumEnter() {
    this->unk4C0 = 0;
}
#endif

void Spyro::AirMediumExit() {

}

void Spyro::AirMediumUpdate() {

}

void Spyro::AirMediumEnter() {

}

#if 0 // DRAFT: function call 'KDMath_GetYaw(Spyro)' does not match
void Spyro::CalcVelTurnDir(float arg0) {
    Spyro *temp_r31_4905;
    f32 var_f31_4921;
    temp_r31_4905 = M2C_ERROR(/* Read from unset register $r4 */);
    if ((M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x338) != 0.0f) || (temp_r31_4905->unk338 != 0.0f)) {
        var_f31_4921 = NormaliseAngle(3.1415927f + KDMath_GetYaw(*(temp_r31_4905 + 0x338)));
    } else {
        KDMath_GetYaw(temp_r31_4905->unk8);
        var_f31_4921 = NormaliseAngle(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */));
    }
    if (((KDInput *) (temp_r31_4905->GetInput()))->GetLeftMag() != 0.0f) {
        KDMath_SmoothToAngle(var_f31_4921, temp_r31_4905->GetJoyYaw(), arg0, gUpdateTimeDelta);
        var_f31_4921 = M2C_ERROR(/* Read from unset register $f1 */);
    }
    arg_sp10.SetRotationYaw(var_f31_4921);
    M2C_FIELD(this, f64 *, 0) = arg_sp30;
    M2C_FIELD(this, f64 *, 8) = arg_sp38;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void Spyro::CalcYawTurnDir(float arg0) {
    Spyro *temp_r31_5051;
    f32 var_f31_5059;
    temp_r31_5051 = M2C_ERROR(/* Read from unset register $r4 */);
    KDMath_GetYaw(M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), Matrix **, 8));
    var_f31_5059 = NormaliseAngle(3.1415927f + M2C_ERROR(/* Read from unset register $f1 */));
    if (((KDInput *) (temp_r31_5051->GetInput()))->GetLeftMag() != 0.0f) {
        KDMath_SmoothToAngle(var_f31_5059, temp_r31_5051->GetJoyYaw(), arg0, gUpdateTimeDelta);
        var_f31_5059 = M2C_ERROR(/* Read from unset register $f1 */);
    }
    arg_sp10.SetRotationYaw(var_f31_5059);
    M2C_FIELD(this, f64 *, 0) = arg_sp30;
    M2C_FIELD(this, f64 *, 8) = arg_sp38;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp2C'
void Spyro::GetJoyDir() {
    f64 sp40;
    f64 sp38;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Spyro *temp_r31_5103;
    f32 temp_f31_5108;

    temp_r31_5103 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_f31_5108 = ((KDInput *) (temp_r31_5103->GetInput()))->GetLeftMag();
    KDMath_GetDirection(temp_r31_5103->GetJoyYaw());
    sp8 = -sp28;
    spC = -sp2C;
    sp10 = -sp30;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    M2C_FIELD(this, f64 *, 0) = sp18;
    sp20 = (f32) sp40 * temp_f31_5108;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
}
#endif

#if 0 // DRAFT: undefined identifier 'atan2'
f32 Spyro::GetJoyYaw() {
    f32 temp_f30_5163;
    f32 temp_f31_5159;

    temp_f31_5159 = ((KDCamera *) (GetCamera()))->GetMoveYaw();
    temp_f30_5163 = ((InputModifier *) (GetInput()))->GetLeftY();
    return temp_f31_5159 + (f32) atan2(-((InputModifier *) (GetInput()))->GetLeftX(), temp_f30_5163);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
KDCamera *Spyro::GetCamera() {
    return M2C_BITWISE(KDCamera *, this->unk214.unkC);
}
#endif

InputModifier *Spyro::GetInput() {
    if (((u8) this->unk90 != 0) && ((u8) M2C_FIELD(this, u8 *, 0x1C4) != 0)) {
        return (InputModifier *) &this->unk200;
    }
    return (InputModifier *) &this->unk204.unkC;
}

#if 0 // DRAFT: undefined identifier 'unkspAC'
void Spyro::SetForce(const MKVector3 &arg0, float arg1) {
    f64 spB0;
    f64 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 temp_f0_5287;
    f32 temp_f1_5285;
    f32 temp_f2_5252;
    f32 temp_f31_5255;
    f32 var_f2_5286;

    sp40 = arg1;
    sp38 = arg1;
    sp3C = arg1;
    spB0 = (f64) sp40;
    spA8 = (f64) sp38;
    sp30 = -(f32) spB0;
    sp28 = -(f32) spA8;
    sp2C = -unkspAC;
    sp80 = (f64) sp30;
    sp78 = (f64) sp28;
    Min(sp18, arg0);
    Max(sp88, sp18);
    sp98 = M2C_BITWISE(f64, sp88);
    spA0 = (f64) sp88.unk8;
    temp_f2_5252 = 1.0f - M2C_FIELD(this, f32 *, 0x388);
    temp_f31_5255 = gUpdateTimeDelta;
    sp98 = (f32) sp98 * temp_f2_5252;
    spA0 = (f32) spA0 * temp_f2_5252;
    sp48 = (f64) sp98;
    sp50 = (f64) spA0;
    sp58.ApplyPhysics((MKVector3) this);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp68 = sp8;
    sp10 = sp60 * temp_f31_5255;
    sp70 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unk338 += (f32) sp70;
    temp_f1_5285 = this->unk388;
    var_f2_5286 = this->unk33C;
    temp_f0_5287 = -temp_f1_5285;
    if (var_f2_5286 < temp_f1_5285) {

    } else {
        var_f2_5286 = temp_f1_5285;
    }
    if (var_f2_5286 > temp_f0_5287) {

    } else {
        var_f2_5286 = temp_f0_5287;
    }
    this->unk33C = var_f2_5286;
}
#endif

void Spyro::SetDeltaPos(const MKVector3 &arg0) {
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r3, $r0, 0x0, qr0 */);
    this->unk348 += arg0.unk8;
}

void Spyro::SetDesiredVelocityVectical(float arg0, float arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    spC = arg0;
    sp8 = this->unk330;
    sp10 = this->unk338;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    SetDesiredVelocity(*((MKVector3 *) &sp18), arg1);
}

void Spyro::SetDesiredVelocityHoriz(const MKVector3 &arg0, float arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp10 = arg0.unk8;
    sp8 = arg0.unk0;
    spC = this->unk33C;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    SetDesiredVelocity(*((MKVector3 *) &sp18), arg1);
}

#if 0 // DRAFT: undefined identifier 'unkspF4'
void Spyro::SetDesiredVelocity(const MKVector3 &arg0, float arg1) {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f4_5407;
    f32 var_f30_5426;
    f64 temp_f1_5410;
    f64 temp_f1_5416;
    f64 temp_f1_5420;
    s32 temp_r3_5439;
    s32 var_r0_5449;

    spF0 = M2C_FIELD(&arg0, f64 *, 0);
    spF8 = M2C_FIELD(&arg0, f64 *, 8);
    unkspF4 = 0.0f;
    if ((this->unk428 & 0x20) && ((s32) M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) > 0)) {
        temp_f4_5407 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (0.0f * 0.0f));
        if (temp_f4_5407 > 0.0f) {
            temp_f1_5410 = __frsqrte(temp_f4_5407);
            temp_f1_5416 = 0.5 * temp_f1_5410 * -(((f64) temp_f4_5407 * (temp_f1_5410 * temp_f1_5410)) - 3.0);
            temp_f1_5420 = 0.5 * temp_f1_5416 * -(((f64) temp_f4_5407 * (temp_f1_5416 * temp_f1_5416)) - 3.0);
            var_f30_5426 = (f32) ((f64) temp_f4_5407 * (0.5 * temp_f1_5420 * -(((f64) temp_f4_5407 * (temp_f1_5420 * temp_f1_5420)) - 3.0)));
        } else if (temp_f4_5407 < M2C_BITWISE(f32, 0.0)) {
            var_f30_5426 = __float_nan;
        } else {
            sp8 = temp_f4_5407;
            temp_r3_5439 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_5439) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5449 = 1;
                } else {
                    var_r0_5449 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_5449 = 5;
                } else {
                    var_r0_5449 = 3;
                }
                break;
            default:
                var_r0_5449 = 4;
                break;
            }
            if (var_r0_5449 == 1) {
                var_f30_5426 = __float_nan;
            } else {
                var_f30_5426 = temp_f4_5407;
            }
        }
        if (var_f30_5426 != 0.0f) {
            if ((s32) M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) != 0) {

            }
            Projection(spB0, *((MKVector3 *) &spF0));
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spC0 = sp10;
            sp18 = (f32) spF8 - spB0.unk8;
            spC8 = (f64) sp18;
            Normalise(spD0);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            spE0 = sp20;
            sp28 = spD0.unk8 * var_f30_5426;
            spF0 = sp20;
            spE8 = (f64) sp28;
            spF8 = (f64) sp28;
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp90 = sp60;
        sp68 = (f32) spF8 - this->unk338;
        sp98 = (f64) sp68;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        spA0 = sp50;
        sp58 = (f32) sp98 * (1.0f / gUpdateTimeDelta);
        spA8 = (f64) sp58;
        SetForce(*((MKVector3 *) &spA0), arg1);
        return;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp70 = sp40;
    sp48 = arg0.unk8 - this->unk338;
    sp78 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f4 */);
    sp80 = sp30;
    sp38 = (f32) sp78 * (1.0f / gUpdateTimeDelta);
    sp88 = (f64) sp38;
    SetForce(*((MKVector3 *) &sp80), arg1);
}
#endif

void Spyro::PushAwayFrom(MKMessage *arg0) {

}

#if 0 // DRAFT: undefined identifier '__vptr'
void Spyro::StableReposition(const MKVector3 &arg0, float arg1, bool arg2, bool arg3) {
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_5710;
    MKProp *temp_r3_5663;
    Sparx *temp_r3_5724;
    s32 temp_cr0_eq_5677;
    s32 var_r5_5671;
    u8 var_r3_5685;
    u8 var_r4_5679;

    this->unk340 = 0.0f;
    this->unk34C = 0.0f;
    this->unk348 = 0.0f;
    Teleport(arg0, arg1, 0x1E, 1U, 1U);
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = -1.0f;
    sp30 = (f64) sp20;
    sp28 = (f64) sp18;
    temp_r3_5663 = this->unk26C.unk8;
    M2C_FIELD(temp_r3_5663->unk0, M2C_UNK (**)(MKProp *, f64 *, s32, f32, f64), 0x10)(temp_r3_5663, &sp28, ((u32) this->unk428 >> 5U) & 1, 0.0f, (f64) sp18);
    var_r5_5671 = 2;
    if ((s32) M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) > 0) {
        var_r5_5671 = 1;
    }
    temp_cr0_eq_5677 = arg3 == 0;
    if (temp_cr0_eq_5677 == 0) {
        var_r4_5679 = 0;
        sp14 = 0;
        sp10 = 0x186;
        if (temp_cr0_eq_5677 == 0) {
            var_r3_5685 = 1;
            if ((u8) ((u32) (var_r5_5671 - 1) <= 1U) == 0) {
                var_r3_5685 = 0;
            }
            if (var_r3_5685 != 0) {
                var_r4_5679 = 1;
            }
        }
        gAssertBool = TryChangeState(var_r4_5679, 4U, (MKMessage *) &sp10, 1U);
    }
    ColorSpyroFromGround(1.0f);
    if (arg2 != 0) {
        temp_r3_5710 = GetCamera();
        spC = 0;
        sp8 = 0x44A;
        M2C_FIELD(temp_r3_5710->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    ClearSafePos();
    temp_r3_5724 = checked_cast<Sparx *, Sparx>(this->unkB70);
    if (temp_r3_5724 != NULL) {
        temp_r3_5724->Spawn();
    }
}
#endif

void Spyro::ClearSafePos() {
    this->unk358 = 0;
    this->unk35C = 0;
}

void Spyro::SetLastSafePos(const MKVector3 &arg0, MKProp *arg1) {
    f32 temp_r6_5769;
    f32 temp_r6_5806;
    f32 temp_r7_5781;
    f32 temp_r7_5818;
    s32 temp_r0_5768;
    s32 temp_r0_5805;
    s32 temp_r6_5759;
    s32 temp_r6_5796;
    s32 var_r0_5782;
    s32 var_r0_5819;
    void *temp_r6_5753;

    if ((arg1 != NULL) && (temp_r6_5753 = arg1->unk0, ((temp_r6_5753 == NULL) == 0))) {
        if (!(M2C_FIELD(temp_r6_5753, s32 *, 0xC) & 0x200)) {
            temp_r6_5759 = this->unk35C;
            if ((temp_r6_5759 == M2C_BITWISE(s32, this->unk350)) && (temp_r6_5759 > 0)) {
                this->unk358 += 1;
                temp_r0_5768 = this->unk358;
                temp_r6_5769 = this->unk350;
                if (temp_r0_5768 >= M2C_BITWISE(s32, temp_r6_5769)) {
                    this->unk358 = temp_r0_5768 - M2C_BITWISE(s32, temp_r6_5769);
                }
                this->unk35C -= 1;
            }
            temp_r7_5781 = this->unk350;
            var_r0_5782 = this->unk358 + this->unk35C;
            if (var_r0_5782 >= M2C_BITWISE(s32, temp_r7_5781)) {
                var_r0_5782 -= M2C_BITWISE(s32, temp_r7_5781);
            }
            this->unk35C += 1;
            ((SafePosInfo *) (this->unk35C + (var_r0_5782 * 0x18)))->SetPos(arg0, arg1);
        }
    } else {
        temp_r6_5796 = this->unk35C;
        if ((temp_r6_5796 == M2C_BITWISE(s32, this->unk350)) && (temp_r6_5796 > 0)) {
            this->unk358 += 1;
            temp_r0_5805 = this->unk358;
            temp_r6_5806 = this->unk350;
            if (temp_r0_5805 >= M2C_BITWISE(s32, temp_r6_5806)) {
                this->unk358 = temp_r0_5805 - M2C_BITWISE(s32, temp_r6_5806);
            }
            this->unk35C -= 1;
        }
        temp_r7_5818 = this->unk350;
        var_r0_5819 = this->unk358 + this->unk35C;
        if (var_r0_5819 >= M2C_BITWISE(s32, temp_r7_5818)) {
            var_r0_5819 -= M2C_BITWISE(s32, temp_r7_5818);
        }
        this->unk35C += 1;
        ((SafePosInfo *) (this->unk35C + (var_r0_5819 * 0x18)))->SetPos(arg0, arg1);
    }
}

#if 0 // DRAFT: undefined identifier 'arg_spAC'
void Spyro::TeleportEffects(const MKVector3 &arg0, Matrix *arg1) {
    s32 var_r31_5921;
    M2C_STRUCT_COPY((s32) &arg_spAC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_sp6C + 4, (s32) (arg1 - 4) + 4, 0x40);
    arg_sp70.InverseSimple((Matrix *) &arg_sp70);
    arg_spB0.Multiply3x3((Matrix *) &arg_spB0, (Matrix *) &arg_sp70);
    arg_spE0 = 0.0f;
    arg_spE4 = 0.0f;
    arg_spE8 = 0.0f;
    arg_spEC = 1.0f;
    arg_sp30.SetIdentity();
    arg_sp10 = -arg1->unk30;
    arg_sp14 = -arg1->unk34;
    arg_sp18 = -arg1->unk38;
    arg_sp20 = (f64) arg_sp10;
    arg_sp28 = (f64) arg_sp18;
    arg_sp60 = (f32) arg_sp20;
    arg_sp64 = arg_sp24;
    arg_sp68 = (f32) arg_sp28;
    arg_sp6C = 1.0f;
    arg_sp30.Multiply4x4((Matrix *) &arg_sp30, (Matrix *) &arg_spB0);
    arg_sp30.Translate((Matrix *) &arg_sp30, *((MKVector3 *) &arg1->unk30));
    arg_sp30.Translate((Matrix *) &arg_sp30, arg0);
    var_r31_5921 = 0;
loop_2:
    if (var_r31_5921 < MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 2)) {
        ((MKCloth *) (MKModel_GetClothSubObject(this->unk4, var_r31_5921)))->Teleport(*((Matrix *) &arg_sp30));
        var_r31_5921 += 1;
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Spyro::Teleport(const MKVector3 &arg0, float arg1, int arg2, bool arg3, bool arg4) {
    BoneBlurFX *temp_r3_6093;
    MKProp *temp_r3_5994;
    MKProp *temp_r4_6014;
    MKProp *temp_r4_6023;
    MKProp *temp_r4_6044;
    f32 temp_r3_5958;
    void ***temp_r4_5982;
    void *temp_r3_5981;
    void *temp_r3_6090;
    temp_r3_5958 = this->unk258;
    if (M2C_BITWISE(u32, temp_r3_5958) != 0U) {
        ((SpyroEffects *) (M2C_BITWISE(SpyroEffects *, temp_r3_5958)))->ResetFury();
    }
    this->unkB70->Teleport();
    M2C_STRUCT_COPY((s32) &arg_sp9C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    temp_r3_5981 = this->unk8;
    temp_r4_5982 = &this->unk264;
    arg_sp10 = temp_r4_5982;
    arg_sp88 = M2C_FIELD(temp_r3_5981, f64 *, 0x30);
    arg_sp90 = M2C_FIELD(temp_r3_5981, f64 *, 0x38);
    if (temp_r4_5982 != NULL) {
        arg_sp14 = (u8) this->unk268;
        this->unk268 = 0;
    }
    temp_r3_5994 = this->unk26C.unk8;
    M2C_FIELD(temp_r3_5994->unk0, M2C_UNK (**)(MKProp *, MKVector3 *, s32, f32), 0x14)(temp_r3_5994, &arg0, arg2, 2.5f);
    if (arg_sp10 != NULL) {
        M2C_FIELD(arg_sp10, u8 *, 4) = arg_sp14;
    }
    if (this->unk428 & 0x20) {
        this->unk26C.unk8->GlueToGround();
    }
    temp_r4_6014 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_6014->unk0, M2C_UNK (**)(M2C_UNK *, MKProp *), 0x4C)(&arg_sp68, temp_r4_6014);
    SetPos(*((MKVector3 *) &arg_sp68));
    temp_r4_6023 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_6023->unk0, M2C_UNK (**)(M2C_UNK *, MKProp *), 0x4C)(&arg_sp48, temp_r4_6023);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp88 = arg_sp18;
    arg_sp20 = arg_sp50 - (f32) arg_sp90;
    arg_sp58 = arg_sp18;
    arg_sp90 = (f64) arg_sp20;
    temp_r4_6044 = this->unk26C.unk8;
    arg_sp60 = (f64) arg_sp20;
    M2C_FIELD(temp_r4_6044->unk0, M2C_UNK (**)(f32 *, MKProp *, f64, f32), 0x4C)(&arg_sp38, temp_r4_6044, arg_sp18, arg_sp50);
    arg_sp28 = arg_sp38;
    arg_sp2C = arg_sp3C;
    arg_sp30 = arg_sp40;
    arg_sp34 = 100.0f;
    arg_sp78 = (f64) arg_sp28;
    arg_sp80 = (f64) arg_sp30;
    this->unk26C.unkC->ResetCollisionSweepSphere((s32) &arg_sp78, M2C_ERROR(/* Read from unset register $r5 */));
    this->unk3A0.YawTowards(arg1, 900.0f);
    if (arg3 != 0) {
        UpdateAnimation();
    }
    if (arg4 != 0) {
        SetDesiredVelocity(zero, 540000.0f);
    }
    TeleportEffects(*((MKVector3 *) &arg_sp88), (Matrix *) &arg_spA0);
    UpdateSpyroCameraInfo();
    PlatformUpdate();
    temp_r3_6090 = M2C_FIELD(this, void **, 0x264);
    if (temp_r3_6090 != NULL) {
        temp_r3_6093 = M2C_FIELD(temp_r3_6090, BoneBlurFX **, 0xB0);
        if (temp_r3_6093 != NULL) {
            temp_r3_6093->Teleport();
        }
    }
    this->unk78 = 1;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::AnimScriptNode'
MKAnimScript *Spyro::GetAnimScript(Spyro::AnimScriptNode arg1) {
    return this + (((s32) arg1 * 0x58) + 0xC0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Spyro::PostSetAnim() {
    s32 sp8;
    s32 var_r29_6128;
    s32 var_r31_6129;

    var_r29_6128 = 0;
    var_r31_6129 = 0;
    do {
        sp8 = 0;
loop_5:
        if (sp8 < 0x18) {
            if (((MKAnimScript *) (this + (var_r31_6129 + 0xC0)))->CheckEvent(sp8) != 0) {
                ProcessAnimationEvent((Spyro::AnimEvents) sp8);
            }
            sp8 += 1;
            goto loop_5;
        }
        var_r29_6128 += 1;
        var_r31_6129 += 0x58;
    } while (var_r29_6128 < 2);
}
#endif

#if 0 // DRAFT: undefined identifier 'defaultEvents'
void Spyro::PreSetAnim() {
    s32 var_r29_6171;
    s32 var_r31_6172;

    var_r29_6171 = 0;
    var_r31_6172 = 0;
    do {
        ProcessAnimationEvent((Spyro::AnimEvents) *(&defaultEvents + var_r31_6172));
        var_r29_6171 += 1;
        var_r31_6172 += 4;
    } while (var_r29_6171 < 2);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::AnimScriptNode'
void Spyro::SetAnim(MKAnim *arg1, float farg0, Spyro::AnimScriptNode arg2, unsigned int arg3, float farg1) {
    s32 temp_r31_6201;

    temp_r31_6201 = (s32) arg2 * 0x58;
    if ((arg1 != (u32) M2C_FIELD((this + temp_r31_6201), u32 *, 0xE0)) || (arg3 & 4)) {
        PreSetAnim();
        ((MKAnimScript *) (this + (temp_r31_6201 + 0xC0)))->SetAnim(arg1, farg1, farg0, (s32) arg3, M2C_FIELD((this + ((s32) arg2 * 4)), s32 *, 0x170));
        PostSetAnim();
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::AnimScriptNode'
void Spyro::SetAnim(unsigned int arg1, float farg0, Spyro::AnimScriptNode arg2, unsigned int arg3, float farg1) {
    SetAnim(M2C_FIELD((this->unkB4 + (arg1 * 8)), MKAnim **, 4), farg0, arg2, arg3, farg1);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::RefPoints'
void Spyro::GetRefPos(Spyro::RefPoints arg1) {
    MKVector3 sp8;

    MKModel_CalculateRefPointWorldPosition(M2C_FIELD(arg1, MKModel **, 4), M2C_FIELD(((s32) arg1 + (M2C_ERROR(/* Read from unset register $r5 */) * 4)), s32 *, 0xB0), &sp8);
    M2C_FIELD(this, f64 *, 0) = M2C_BITWISE(f64, sp8);
    M2C_FIELD(this, f64 *, 8) = (f64) sp8.unk8;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::Nodes'
void Spyro::GetNodeMatrix(Spyro::Nodes arg1, Matrix *arg2) {
    s16 sp8;
    Animation *temp_r3_6295;
    s32 temp_r30_6291;
    s32 temp_r31_6294;

    temp_r30_6291 = MKModel_GetWorldMatrix(this->unk4);
    temp_r31_6294 = M2C_FIELD((this + ((s32) arg1 * 4)), s32 *, 0x98);
    temp_r3_6295 = MKModel_GetAnimation(this->unk4);
    sp8 = (s16) temp_r31_6294;
    temp_r3_6295->CalculateMatrices(arg2, 1, &sp8, (Matrix *) temp_r30_6291);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Spyro::GetNodePos(int arg0) {
    MKVector3 sp8;

    MKModel_CalculateNodeWorldPosition(M2C_FIELD(arg0, MKModel **, 4), M2C_FIELD((arg0 + (M2C_ERROR(/* Read from unset register $r5 */) * 4)), s32 *, 0x98), &sp8);
    M2C_FIELD(this, f64 *, 0) = M2C_BITWISE(f64, sp8);
    M2C_FIELD(this, f64 *, 8) = (f64) sp8.unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
u8 Spyro::SlipTest() {
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp8;
    MKProp *temp_r4_6383;
    s32 temp_r4_6385;
    s32 var_r0_6399;
    u8 var_r0_6371;
    u8 var_r3_6366;
    void *var_r4_6394;

    Tools_GetGradient(sp18);
    sp28 = M2C_BITWISE(f64, sp18);
    sp30 = (f64) sp18.unk8;
    sp8.GetJoyDir();
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    var_r3_6366 = 0;
    var_r0_6371 = 0;
    if ((((this->unk338 * (f32) sp30) + ((this->unk330 * (f32) sp28) + (this->unk33C * unksp2C))) > 200.0f) && ((u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r4 */) >> 0x1DU) & 1) != 0)) {
        var_r0_6371 = 1;
    }
    if (var_r0_6371 != 0) {
        temp_r4_6383 = this->unk26C.unk8;
        temp_r4_6385 = M2C_FIELD(temp_r4_6383, s32 *, 0x16C);
        if (((u32) (-temp_r4_6385 & ~temp_r4_6385) >> 0x1FU) != 0) {
            if (temp_r4_6385 != 0) {
                var_r4_6394 = &temp_r4_6383->unk8 + ((temp_r4_6385 - 1) * 0x58);
            } else {
                var_r4_6394 = NULL;
            }
            var_r0_6399 = M2C_FIELD(var_r4_6394, s32 *, 0x44);
        } else {
            var_r0_6399 = 0;
        }
        if (var_r0_6399 & 2) {
            var_r3_6366 = 1;
        }
    }
    return var_r3_6366;
}
#endif

#if 0 // DRAFT: expression syntax error
void Spyro::HornDiveTranstion() {
    InputModifier *temp_r3_6430;
    s32 var_r3_6443;
    u8 var_r30_6429;
    u8 var_r31_6423;
    u8 var_r4_6432;

    var_r31_6423 = 0;
    if (this->unk430.unk28.GetHornDiveEnabled() != 0) {
        var_r30_6429 = 0;
        temp_r3_6430 = GetInput();
        var_r4_6432 = 0;
        if (((u8) temp_r3_6430->unk5 != 0) || ((u8) temp_r3_6430->unk4 != 0)) {
            var_r4_6432 = 1;
        }
        if (var_r4_6432 != 0) {
            var_r3_6443 = 0;
        } else {
            var_r3_6443 = MKInput_Pressed(0xB, (MKInputDevices) temp_r3_6430->unk0);
        }
        if (((u8) var_r3_6443 != 0) && ((s32) this->unk4C0 < 3)) {
            var_r30_6429 = 1;
        }
        if (var_r30_6429 != 0) {
            var_r31_6423 = 1;
        }
    }
    TryChangeState(var_r31_6423, 0xCU, (SpyroStateMsg) 0x17B, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
u8 Spyro::TailSweepTailStrikeTransition() {
    MKCollisionResult spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    u8 sp80;
    s32 sp7C;
    s32 sp78;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    InputModifier *temp_r3_6532;
    InputModifier *temp_r3_6560;
    InputModifier *temp_r3_6736;
    s32 var_r3_6545;
    s32 var_r3_6573;
    s32 var_r3_6749;
    u8 var_r28_6506;
    u8 var_r28_6697;
    u8 var_r28_6733;
    u8 var_r30_6485;
    u8 var_r30_6516;
    u8 var_r31_6483;
    u8 var_r31_6590;
    u8 var_r4_6534;
    u8 var_r4_6562;
    u8 var_r4_6698;
    u8 var_r4_6738;
    void *temp_r3_6596;
    void *var_r0_6659;
    void *var_r3_6679;

    var_r31_6483 = 0;
    var_r30_6485 = 0;
    if (((u8) gb.unk5 != 0) && (this->unk430.unk28.GetTailStrikeEnabled() != 0)) {
        var_r30_6485 = 1;
    }
    if ((var_r30_6485 != 0) && ((s32) (gameData.unk168 & 2) == 2)) {
        var_r31_6483 = 1;
    }
    var_r28_6506 = 0;
    if (((u8) gb.unk5 != 0) && (this->unk430.unk28.GetTailSweepEnabled() != 0)) {
        var_r28_6506 = 1;
    }
    var_r30_6516 = var_r28_6506;
    if ((var_r28_6506 != 0) && (this->unk430.unk28.GetTailSweepComboCount() > 0)) {
        this->unk430.unk28.GetLastTailSweepTarget();
        this->unk430.unk28.GetLastCombatEnemy();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) == (u32) M2C_ERROR(/* Read from unset register $r3 */)) {
            var_r30_6516 = 0;
        }
    }
    temp_r3_6532 = GetInput();
    var_r4_6534 = 0;
    if (((u8) temp_r3_6532->unk5 != 0) || ((u8) temp_r3_6532->unk4 != 0)) {
        var_r4_6534 = 1;
    }
    if (var_r4_6534 != 0) {
        var_r3_6545 = 0;
    } else {
        var_r3_6545 = MKInput_Pressed(0xD, (MKInputDevices) temp_r3_6532->unk0);
    }
    if ((u8) var_r3_6545 != 0) {
        M2C_FIELD(this, f32 *, 0x4B8) = (f32) gb.unk30C;
    }
    temp_r3_6560 = GetInput();
    var_r4_6562 = 0;
    if (((u8) temp_r3_6560->unk5 != 0) || ((u8) temp_r3_6560->unk4 != 0)) {
        var_r4_6562 = 1;
    }
    if (var_r4_6562 != 0) {
        var_r3_6573 = 0;
    } else {
        var_r3_6573 = MKInput_Released(0xD, (MKInputDevices) temp_r3_6560->unk0);
    }
    if ((u8) var_r3_6573 != 0) {
        this->unk460.unk54 = gb.unk30C;
    }
    if (var_r31_6483 != 0) {
        var_r31_6590 = 0;
        if (GetMeleeButtonState() == 2) {
            temp_r3_6596 = this->unk8;
            sp38 = 0.0f;
            sp3C = 10.0f;
            sp40 = 0.0f;
            sp58 = (f64) sp38;
            sp68 = M2C_FIELD(temp_r3_6596, f64 *, 0x30);
            sp60 = (f64) sp40;
            sp70 = M2C_FIELD(temp_r3_6596, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp20 = 0.0f;
            sp18 = 0.0f;
            sp1C = 180.0f;
            sp30 = (f32) sp70 + (f32) sp60;
            sp98 = sp28;
            sp48 = (f64) sp18;
            spA0 = (f64) sp30;
            sp50 = (f64) sp20;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp88 = sp8;
            sp10 = (f32) spA0 - (f32) sp50;
            sp90 = (f64) sp10;
            if (MKCollision_RayCollide(*((MKVector3 *) &sp98), *((MKVector3 *) &sp88), &spA8, (MKCollisionMode) 7, 0x08000000) != 0) {
                sp7C = 0;
                sp80 = 0;
                sp78 = 0x88;
                if ((spA8.unk50 != 0) && (spA8.unk48 != NULL) && (var_r0_6659 = M2C_FIELD(spA8.unk48, void **, 8), ((var_r0_6659 == NULL) == 0))) {

                } else {
                    var_r0_6659 = NULL;
                }
                if ((var_r0_6659 != NULL) && ((unksp9C - spA8.unk4) > 75.0f)) {
                    if ((spA8.unk50 != 0) && (spA8.unk48 != NULL) && (var_r3_6679 = M2C_FIELD(spA8.unk48, void **, 8), ((var_r3_6679 == NULL) == 0))) {

                    } else {
                        var_r3_6679 = NULL;
                    }
                    M2C_FIELD(M2C_FIELD(var_r3_6679, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp78);
                    var_r31_6590 = sp80;
                }
            } else {
                var_r31_6590 = 1;
            }
        }
        var_r28_6697 = 1;
        var_r4_6698 = 0;
        if ((var_r30_6516 != 0) && ((f32) fabs(this->unk460.unk54 - gb.unk30C) < 0.000001f)) {
            var_r4_6698 = 1;
        }
        if ((TryChangeState(var_r4_6698, 0xCU, (SpyroStateMsg) 0x173, 1U) == 0) && (TryChangeState(var_r31_6590, 7U, NULL, 0U) == 0)) {
            var_r28_6697 = 0;
        }
        return var_r28_6697;
    }
    var_r28_6733 = 0;
    if (var_r30_6516 != 0) {
        temp_r3_6736 = GetInput();
        var_r4_6738 = 0;
        if (((u8) temp_r3_6736->unk5 != 0) || ((u8) temp_r3_6736->unk4 != 0)) {
            var_r4_6738 = 1;
        }
        if (var_r4_6738 != 0) {
            var_r3_6749 = 0;
        } else {
            var_r3_6749 = MKInput_Pressed(0xD, (MKInputDevices) temp_r3_6736->unk0);
        }
        if ((u8) var_r3_6749 != 0) {
            var_r28_6733 = 1;
        }
    }
    return TryChangeState(var_r28_6733, 0xCU, (SpyroStateMsg) 0x173, 1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'up'
s8 Spyro::SpikyTransition() {
    s8 sp69;
    s8 sp68;
    s32 sp64;
    f32 sp60;
    s32 sp5C;
    s8 sp5A;
    s8 sp59;
    s8 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    MKProp *sp44;
    MKProp *sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp8;
    MKProp *var_r4_6798;
    s8 var_r3_6855;
    u32 temp_r5_6783;
    void *temp_r3_6795;

    temp_r5_6783 = this->unk428;
    this->unk428 = temp_r5_6783 | 0x80;
    IsAgainstMatID(0x80);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        sp1C = 0;
        if (((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x50) != 0) && (temp_r3_6795 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x48), ((temp_r3_6795 == NULL) == 0)) && (var_r4_6798 = M2C_FIELD(temp_r3_6795, MKProp **, 8), ((var_r4_6798 == NULL) == 0))) {

        } else {
            var_r4_6798 = NULL;
        }
        sp18 = 7;
        sp40 = (MKProp *)5;
        sp44 = var_r4_6798;
        sp20 = M2C_FIELD(&up, f64 *, 0);
        sp28 = M2C_FIELD(&up, f64 *, 8);
        sp58 = 1;
        sp64 = 2;
        sp60 = 10.0f;
        sp59 = 0;
        sp5A = 1;
        sp5C = -1;
        sp30 = M2C_FIELD(&one, f64 *, 0);
        sp38 = M2C_FIELD(&one, f64 *, 8);
        sp68 = 0;
        if (var_r4_6798 != NULL) {
            sp8.GetPos();
            sp48 = sp8;
            sp50 = sp10;
        } else {
            sp48 = 0.0f;
            unksp4C = 0.0f;
            sp50 = 0.0f;
        }
        sp69 = 0;
        sp5C = GS_SpyroSpikeBurn;
        sp5A = 0;
        var_r3_6855 = Hurt((HurtMessage *) &sp18);
        if ((u32) ((temp_r5_6783 >> 7U) & 1) == 0) {
            this->unk428 &= 0xFFFFFF7F;
            return var_r3_6855;
        }
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return var_r3_6855;
    }
    var_r3_6855 = 0;
    return var_r3_6855;
}
#endif

#if 0 // DRAFT: undefined identifier 'up'
s8 Spyro::LavaTransition() {
    s8 sp69;
    s8 sp68;
    s32 sp64;
    f32 sp60;
    s32 sp5C;
    s8 sp5A;
    s8 sp59;
    s8 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    MKProp *sp44;
    MKProp *sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp8;
    MKProp *var_r4_6896;
    s8 var_r3_6953;
    u32 temp_r5_6881;
    void *temp_r3_6893;

    temp_r5_6881 = this->unk428;
    this->unk428 = temp_r5_6881 | 0x80;
    IsAgainstMatID(0x100);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        sp1C = 0;
        if (((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x50) != 0) && (temp_r3_6893 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x48), ((temp_r3_6893 == NULL) == 0)) && (var_r4_6896 = M2C_FIELD(temp_r3_6893, MKProp **, 8), ((var_r4_6896 == NULL) == 0))) {

        } else {
            var_r4_6896 = NULL;
        }
        sp18 = 7;
        sp40 = (MKProp *)5;
        sp44 = var_r4_6896;
        sp20 = M2C_FIELD(&up, f64 *, 0);
        sp28 = M2C_FIELD(&up, f64 *, 8);
        sp58 = 1;
        sp64 = 2;
        sp60 = 10.0f;
        sp59 = 0;
        sp5A = 0;
        sp5C = -1;
        sp30 = M2C_FIELD(&one, f64 *, 0);
        sp38 = M2C_FIELD(&one, f64 *, 8);
        sp68 = 0;
        if (var_r4_6896 != NULL) {
            sp8.GetPos();
            sp48 = sp8;
            sp50 = sp10;
        } else {
            sp48 = 0.0f;
            unksp4C = 0.0f;
            sp50 = 0.0f;
        }
        sp69 = 0;
        sp5C = GS_SpyroLavaBurn;
        sp5A = 0;
        var_r3_6953 = Hurt((HurtMessage *) &sp18);
        if ((u32) ((temp_r5_6881 >> 7U) & 1) == 0) {
            this->unk428 &= 0xFFFFFF7F;
            return var_r3_6953;
        }
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return var_r3_6953;
    }
    var_r3_6953 = 0;
    return var_r3_6953;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
s32 Spyro::AirToStrafeDodgeTransition() {
    SpyroStateMessages sp8;
    InputModifier *temp_r3_6986;
    InputModifier *temp_r3_7019;
    InputModifier *temp_r3_7058;
    f32 var_f1_6999;
    f32 var_f1_7043;
    f32 var_f1_7082;
    s32 var_r3_7032;
    s32 var_r3_7071;
    u8 var_r30_6980;
    u8 var_r31_6979;
    u8 var_r3_7097;
    u8 var_r4_6988;
    u8 var_r4_7021;
    u8 var_r4_7060;

    var_r31_6979 = 0;
    var_r30_6980 = 0;
    sp8.unk50 = 0;
    if (IsPlayingStrafeAnim() != 0) {
        temp_r3_6986 = GetInput();
        var_r4_6988 = 0;
        if (((u8) temp_r3_6986->unk5 != 0) || ((u8) temp_r3_6986->unk4 != 0)) {
            var_r4_6988 = 1;
        }
        if (var_r4_6988 != 0) {
            var_f1_6999 = 0.0f;
        } else {
            var_f1_6999 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_6986->unk0, NULL, NULL);
        }
        if (var_f1_6999 != 0.0f) {
            this->unkB90.GetCurrentTarget();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                sp8.AddMessage(0x178);
                temp_r3_7019 = GetInput();
                var_r4_7021 = 0;
                if (((u8) temp_r3_7019->unk5 != 0) || ((u8) temp_r3_7019->unk4 != 0)) {
                    var_r4_7021 = 1;
                }
                if (var_r4_7021 != 0) {
                    var_r3_7032 = 0;
                } else {
                    var_r3_7032 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_7019->unk0);
                }
                if ((u8) var_r3_7032 != 0) {
                    var_f1_7043 = ((InputModifier *) (GetInput()))->GetLeftX();
                    if (var_f1_7043 < 0.0f) {
                        var_f1_7043 = -var_f1_7043;
                    }
                    if (var_f1_7043 > 0.4f) {
                        var_r31_6979 = 1;
                        sp8.AddMessage(0x179);
                    }
                }
                temp_r3_7058 = GetInput();
                var_r4_7060 = 0;
                if (((u8) temp_r3_7058->unk5 != 0) || ((u8) temp_r3_7058->unk4 != 0)) {
                    var_r4_7060 = 1;
                }
                if (var_r4_7060 != 0) {
                    var_r3_7071 = 0;
                } else {
                    var_r3_7071 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_7058->unk0);
                }
                if ((u8) var_r3_7071 != 0) {
                    var_f1_7082 = ((InputModifier *) (GetInput()))->GetLeftY();
                    if (var_f1_7082 < 0.0f) {
                        var_f1_7082 = -var_f1_7082;
                    }
                    if (var_f1_7082 > 0.4f) {
                        var_r30_6980 = 1;
                        sp8.AddMessage(0x17A);
                    }
                }
            }
        }
    }
    var_r3_7097 = var_r31_6979;
    if (var_r31_6979 == 0) {
        var_r3_7097 = var_r30_6980;
    }
    if ((var_r3_7097 != 0) && ((s32) this->unk54.unk8 != 2)) {
        this->unk54.SetState(2, sp8);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
u8 Spyro::AirToLedgeGrabTransition() {
    MKProp *sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    s32 spF4;
    s32 spF0;
    MKVector3 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    MKProp *sp8;

    if (CheckForLedge(zero, &spE0, &spC0, &spD0, &sp8) != 0) {
        sp58 = 0.0f;
        sp50 = 0.0f;
        sp54 = 120.0f;
        sp88 = (f64) sp58;
        sp80 = (f64) sp50;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp90 = sp70;
        sp78 = spD0.unk8 * -100.0f;
        sp98 = (f64) sp78;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spA0 = sp60;
        sp68 = spE0.unk8 + (f32) sp98;
        spA8 = (f64) sp68;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spB0 = sp40;
        sp48 = (f32) spA8 + (f32) sp88;
        spB8 = (f64) sp48;
        if (MKCollision_SphereCollide(*((MKVector3 *) &spB0), 100.0f, NULL, 0, (MKCollisionMode) 7, 0x220) == 0) {
            spF4 = 0;
            spF0 = 0x184;
            spF8 = M2C_BITWISE(f64, spE0);
            sp100 = (f64) spE0.unk8;
            sp108 = M2C_BITWISE(f64, spD0);
            sp110 = (f64) spD0.unk8;
            sp118 = sp8;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp20 = sp10;
            sp18 = spE0.unk8 - spC0.unk8;
            sp30 = sp10;
            sp28 = (f64) sp18;
            sp38 = (f64) sp18;
            return TryChangeState((u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU), 0xDU, (MKMessage *) &spF0, 0U);
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
u8 Spyro::LandToMoveTransition(bool arg0, bool arg1) {
    SpyroStateMessages sp10C;
    SpyroStateMessages spB8;
    SpyroStateMessages sp64;
    SpyroStateMessages sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_7275;
    InputModifier *temp_r3_7342;
    MKProp *temp_r3_7450;
    f32 var_f1_7288;
    f32 var_f1_7355;
    s32 *var_r30_7408;
    s32 temp_r3_7452;
    u32 var_r0_7466;
    u8 var_r3_7330;
    u8 var_r3_7338;
    u8 var_r3_7447;
    u8 var_r4_7277;
    u8 var_r4_7344;
    u8 var_r5_7261;
    void *var_r3_7461;

    var_r5_7261 = 0;
    if ((arg0 != 0) && ((u8) this->unk3CD == 0)) {
        var_r5_7261 = 1;
    }
    spC = 0;
    sp8 = 0x176;
    if (var_r5_7261 != 0) {
        temp_r3_7275 = GetInput();
        var_r4_7277 = 0;
        if (((u8) temp_r3_7275->unk5 != 0) || ((u8) temp_r3_7275->unk4 != 0)) {
            var_r4_7277 = 1;
        }
        if (var_r4_7277 != 0) {
            var_f1_7288 = 0.0f;
        } else {
            var_f1_7288 = MKInput_GetState(0xB, (MKInputDevices) temp_r3_7275->unk0, NULL, NULL);
        }
        var_r5_7261 = var_f1_7288 != 0.0f;
    }
    if (var_r5_7261 != 0) {
        IsAgainstMatID(2);
        var_r5_7261 = M2C_ERROR(/* Read from unset register $r3 */) == 0;
    }
    if (var_r5_7261 != 0) {
        var_r5_7261 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
    }
    sp10C.unk50 = 0;
    if ((var_r5_7261 != 0) && ((s32) this->unk54.unk8 != 1)) {
        this->unk54.SetState(1, sp10C);
        var_r3_7330 = 1;
    } else {
        var_r3_7330 = 0;
    }
    if (var_r3_7330 == 0) {
        var_r3_7338 = CanStrafe();
        if (var_r3_7338 != 0) {
            temp_r3_7342 = GetInput();
            var_r4_7344 = 0;
            if (((u8) temp_r3_7342->unk5 != 0) || ((u8) temp_r3_7342->unk4 != 0)) {
                var_r4_7344 = 1;
            }
            if (var_r4_7344 != 0) {
                var_f1_7355 = 0.0f;
            } else {
                var_f1_7355 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_7342->unk0, NULL, NULL);
            }
            var_r3_7338 = var_f1_7355 != 0.0f;
        }
        if (var_r3_7338 != 0) {
            IsAgainstMatID(2);
            var_r3_7338 = M2C_ERROR(/* Read from unset register $r3 */) == 0;
        }
        if (var_r3_7338 != 0) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            var_r3_7338 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
        }
        spB8.unk50 = 0;
        if ((var_r3_7338 != 0) && ((s32) this->unk54.unk8 != 2)) {
            this->unk54.SetState(2, spB8);
            var_r3_7330 = 1;
        } else {
            var_r3_7330 = 0;
        }
    }
    if (var_r3_7330 == 0) {
        var_r30_7408 = &sp8;
        if (arg1 != 0) {
            var_r30_7408 = NULL;
        }
        ((KDInput *) (GetInput()))->GetLeftMag();
        sp64.unk50 = 0;
        if (var_r30_7408 != NULL) {
            sp64.AddMessage((MKMessage *) var_r30_7408);
        }
        if (((u8) ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1DU) & 1) ^ 1) != 0) && ((s32) this->unk54.unk8 != 0)) {
            this->unk54.SetState(0, sp64);
            var_r3_7330 = 1;
        } else {
            var_r3_7330 = 0;
        }
    }
    if (var_r3_7330 == 0) {
        var_r3_7447 = this->unk54.unk8 != 8;
        if (var_r3_7447 != 0) {
            temp_r3_7450 = this->unk26C.unk8;
            temp_r3_7452 = M2C_FIELD(temp_r3_7450, s32 *, 0x16C);
            if (((u32) (-temp_r3_7452 & ~temp_r3_7452) >> 0x1FU) != 0) {
                if (temp_r3_7452 != 0) {
                    var_r3_7461 = &temp_r3_7450->unk8 + ((temp_r3_7452 - 1) * 0x58);
                } else {
                    var_r3_7461 = NULL;
                }
                var_r0_7466 = M2C_FIELD(var_r3_7461, u32 *, 0x44);
            } else {
                var_r0_7466 = 0;
            }
            var_r3_7447 = (var_r0_7466 >> 1U) & 1;
        }
        var_r3_7330 = 0;
        sp10.unk50 = 0;
        if (var_r3_7447 != 0) {
            this->unk54.SetState(8, sp10);
            var_r3_7330 = 1;
        }
    }
    return var_r3_7330;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Spyro::LandToAirTransition(bool arg0, bool arg1, bool arg2) {
    SpyroStateMessages sp10;
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_7503;
    MKProp *temp_r3_7531;
    MKProp *temp_r4_7592;
    s32 temp_r3_7533;
    s32 temp_r4_7655;
    s32 var_r0_7547;
    s32 var_r3_7516;
    s32 var_r3_7598;
    s32 var_r5_7597;
    u8 var_r29_7588;
    u8 var_r30_7502;
    u8 var_r30_7557;
    u8 var_r31_7497;
    u8 var_r31_7558;
    u8 var_r3_7634;
    u8 var_r4_7505;
    void *var_r3_7542;

    var_r31_7497 = 0;
    var_r30_7502 = 0;
    temp_r3_7503 = GetInput();
    var_r4_7505 = 0;
    if (((u8) temp_r3_7503->unk5 != 0) || ((u8) temp_r3_7503->unk4 != 0)) {
        var_r4_7505 = 1;
    }
    if (var_r4_7505 != 0) {
        var_r3_7516 = 0;
    } else {
        var_r3_7516 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_7503->unk0);
    }
    if (((u8) var_r3_7516 != 0) && (arg0 != 0)) {
        var_r30_7502 = 1;
    }
    if (var_r30_7502 != 0) {
        temp_r3_7531 = this->unk26C.unk8;
        temp_r3_7533 = M2C_FIELD(temp_r3_7531, s32 *, 0x16C);
        if (((u32) (-temp_r3_7533 & ~temp_r3_7533) >> 0x1FU) != 0) {
            if (temp_r3_7533 != 0) {
                var_r3_7542 = &temp_r3_7531->unk8 + ((temp_r3_7533 - 1) * 0x58);
            } else {
                var_r3_7542 = NULL;
            }
            var_r0_7547 = M2C_FIELD(var_r3_7542, s32 *, 0x44);
        } else {
            var_r0_7547 = 0;
        }
        if (!(var_r0_7547 & 3)) {
            var_r31_7497 = 1;
        }
    }
    var_r30_7557 = var_r31_7497;
    var_r31_7558 = 0;
    if ((var_r31_7497 != 0) && (SelectBestKnockedUpEnemy() != 0)) {
        var_r31_7558 = 1;
    }
    spC = 0;
    sp8 = 0x170;
    sp10.unk50 = 0;
    if (arg1 != 0) {
        sp10.AddMessage(0x178);
    } else {
        sp10.AddMessage(0x16F);
        if (arg2 != 0) {
            sp10.AddMessage(0x17D);
        }
    }
    var_r29_7588 = 0;
    if (OnFloor() == 0) {
        temp_r4_7592 = this->unk26C.unk8;
        if ((s32) M2C_FIELD(temp_r4_7592, s32 *, 0x2D4) > 0) {
            var_r5_7597 = 0;
            var_r3_7598 = 0;
loop_32:
            if (var_r5_7597 < 4) {
                if (var_r5_7597 >= (s32) M2C_FIELD(temp_r4_7592, s32 *, 0x2D4)) {

                } else {
                    if (*(temp_r4_7592 + (var_r3_7598 + 0x1B4)) & 1) {
                        var_r30_7557 = 0;
                        if (this->unk318 < 0.0f) {
                            var_r29_7588 = 1;
                        }
                    }
                    var_r5_7597 += 1;
                    var_r3_7598 += 0x58;
                    goto loop_32;
                }
            }
        } else if ((s32) M2C_FIELD(temp_r4_7592, s32 *, 0x16C) > 0) {
            var_r29_7588 = 0;
        } else {
            var_r29_7588 = 1;
        }
    }
    var_r3_7634 = TryChangeState(var_r31_7558, 0xCU, NULL, 0U);
    if (var_r3_7634 == 0) {
        if ((var_r30_7557 != 0) && ((s32) this->unk54.unk8 != 5)) {
            this->unk54.SetState(5, sp10);
            var_r3_7634 = 1;
        } else {
            var_r3_7634 = 0;
        }
    }
    if (var_r3_7634 == 0) {
        temp_r4_7655 = 0 - arg0;
        TryChangeState(var_r29_7588, 6U, (MKMessage *) ((s32) &sp8 & ((temp_r4_7655 - temp_r4_7655) - !M2C_CARRY)), 0U);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'SpyroStateMsg'
u8 Spyro::TryChangeState(bool arg0, unsigned int arg1, SpyroStateMsg arg2, bool arg3) {
    SpyroStateMessages sp10;
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = (s32) arg2;
    sp10.unk50 = 0;
    sp10.AddMessage((MKMessage *) &sp8);
    if ((arg0 != 0) && ((arg3 != 0) || ((s32) arg1 != (s32) this->unk54.unk8))) {
        this->unk54.SetState((s32) arg1, sp10);
        return 1U;
    }
    return 0U;
}
#endif

u8 Spyro::TryChangeState(bool arg0, unsigned int arg1, MKMessage *arg2, bool arg3) {
    SpyroStateMessages sp8;

    sp8.unk50 = 0;
    if (arg2 != NULL) {
        sp8.AddMessage(arg2);
    }
    if ((arg0 != 0) && ((arg3 != 0) || ((s32) arg1 != (s32) this->unk54.unk8))) {
        this->unk54.SetState((s32) arg1, sp8);
        return 1U;
    }
    return 0U;
}

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Spyro::OnStateChange(int arg0, int arg1) {
    OnStateChange();
    if (this->unk54.GetMedium(arg1) != 0U) {
        SetMedium((Spyro::Medium) this->unk54.GetMedium(arg1));
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Spyro::OnStateChange() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_7828;
    KDCamera *temp_r3_7839;
    f32 temp_f0_7806;
    f32 temp_f1_7804;
    f32 var_f2_7805;

    this->unk428 &= 0x80000000;
    this->unk428 = this->unk428 | 0xE0000 | 0x3FA7;
    M2C_FIELD(this, f32 *, 0x38C) = 1900.0f;
    this->unk388 = 3800.0f;
    temp_f1_7804 = this->unk388;
    var_f2_7805 = this->unk33C;
    temp_f0_7806 = -temp_f1_7804;
    if (var_f2_7805 < temp_f1_7804) {

    } else {
        var_f2_7805 = temp_f1_7804;
    }
    if (var_f2_7805 > temp_f0_7806) {

    } else {
        var_f2_7805 = temp_f0_7806;
    }
    this->unk33C = var_f2_7805;
    this->unk3C0 = 0.0f;
    M2C_FIELD(this, s8 *, 0x25C) = 0;
    if ((u8) M2C_FIELD(this, u8 *, 0x1C6) != 0) {
        temp_r3_7828 = GetCamera();
        sp14 = 0;
        sp10 = 0x42A;
        M2C_FIELD(temp_r3_7828->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        temp_r3_7839 = GetCamera();
        spC = 0;
        sp8 = 0x416;
        M2C_FIELD(temp_r3_7839->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: illegal type
void Spyro::IsAgainstMatID(int arg0) {
    s32 sp10;
    void *spC;
    void **sp8;
    MKProp *temp_r9_7863;
    s32 temp_r0_7880;
    s32 var_ctr_7881;
    s32 var_r5_7873;
    s32 var_r6_7879;
    void *temp_r8_7885;
    void *temp_r9_7878;
    void *var_r3_7871;

    temp_r9_7863 = this->unk26C.unk8;
    sp8 = M2C_FIELD(&lit_2047, void ***, 0);
    var_r3_7871 = NULL;
    spC = M2C_FIELD(&lit_2047, void **, 4);
    var_r5_7873 = 0;
    sp10 = M2C_FIELD(&lit_2047, s32 *, 8);
    sp8 = &temp_r9_7863->unk8;
    spC = temp_r9_7863 + 0x170;
loop_1:
    temp_r9_7878 = *(&sp8 + var_r5_7873);
    var_r6_7879 = 0;
    temp_r0_7880 = M2C_FIELD(temp_r9_7878, s32 *, 0x164);
    var_ctr_7881 = temp_r0_7880;
    if (temp_r0_7880 > 0) {
        do {
            temp_r8_7885 = temp_r9_7878 + var_r6_7879;
            if (arg0 & M2C_FIELD(temp_r8_7885, s32 *, 0x44)) {
                var_r3_7871 = temp_r8_7885;
            }
            var_r6_7879 += 0x58;
            var_ctr_7881 -= 1;
        } while (var_ctr_7881 != 0);
    }
    var_r5_7873 += 4;
    if (((u32) *(&sp8 + var_r5_7873) != 0U) && (var_r3_7871 == NULL)) {
        goto loop_1;
    }
}
#endif

u8 Spyro::OnFloor() {
    return M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) > 0;
}

#if 0 // DRAFT: undefined identifier 'unksp3C'
void Spyro::CheckForKnockBack(ContextInfo &arg0, float arg1) {
    s8 spA9;
    s8 spA8;
    s32 spA4;
    f32 spA0;
    s32 sp9C;
    s8 sp9A;
    s8 sp99;
    s8 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    u32 sp84;
    s32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    void *sp5C;
    s32 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r5_7925;
    s32 temp_r5_7978;
    u32 var_r4_7992;
    void *temp_r3_7941;
    void *temp_r3_7989;
    void *var_r3_7933;
    void *var_r3_7974;

    temp_r5_7925 = arg0.unk164;
    if (temp_r5_7925 > 0) {
        if (temp_r5_7925 != 0) {
            var_r3_7933 = &arg0 + ((temp_r5_7925 - 1) * 0x58);
        } else {
            var_r3_7933 = NULL;
        }
        if (M2C_FIELD(var_r3_7933, s32 *, 0x44) & 0x40000000) {
            temp_r3_7941 = this->unk8;
            sp8 = -M2C_FIELD(temp_r3_7941, f32 *, 0x20);
            spC = -M2C_FIELD(temp_r3_7941, f32 *, 0x24);
            sp10 = -M2C_FIELD(temp_r3_7941, f32 *, 0x28);
            sp38 = (f64) sp8;
            sp40 = (f64) sp10;
            sp28 = -(f32) sp38;
            sp2C = -unksp3C;
            sp30 = -(f32) sp40;
            sp48 = (f64) sp28;
            unksp4C = 0.2f;
            sp50 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f5 */);
            var_r3_7974 = NULL;
            sp5C = NULL;
            temp_r5_7978 = arg0.unk164;
            sp50 = (f32) sp50 * 500.0f;
            if (temp_r5_7978 != 0) {
                var_r3_7974 = &arg0 + ((temp_r5_7978 - 1) * 0x58);
            }
            if (((u8) M2C_FIELD(var_r3_7974, u8 *, 0x50) != 0) && (temp_r3_7989 = M2C_FIELD(var_r3_7974, void **, 0x48), ((temp_r3_7989 == NULL) == 0)) && (var_r4_7992 = M2C_FIELD(temp_r3_7989, u32 *, 8), ((var_r4_7992 == 0U) == 0))) {

            } else {
                var_r4_7992 = 0U;
            }
            sp58 = 7;
            sp80 = 1;
            sp84 = var_r4_7992;
            sp60 = sp48;
            sp68 = (f64) sp50;
            sp98 = 0;
            spA4 = 2;
            spA0 = 10.0f;
            sp99 = 0;
            sp9A = 1;
            sp9C = -1;
            sp70 = M2C_FIELD(&one, f64 *, 0);
            sp78 = M2C_FIELD(&one, f64 *, 8);
            spA8 = 0;
            if (var_r4_7992 != 0U) {
                sp18.GetPos();
                sp88 = sp18;
                sp90 = sp20;
            } else {
                sp88 = 0.0f;
                unksp8C = 0.0f;
                sp90 = 0.0f;
            }
            spA0 = arg1;
            spA9 = 0;
            Hurt((HurtMessage *) &sp58);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const Matrix *' to
void Spyro::UpdateBreathEffects(const Matrix *arg0, const MKVector3 &arg1) {
    s8 sp4F;
    s8 sp4D;
    s8 sp4C;
    s32 sp48;
    s8 sp44;
    void *sp40;
    u8 sp3C;
    Matrix *sp30;
    f64 sp18;
    f64 sp10;
    u8 sp8;
    u32 temp_r5_8076;

    sp8 = 0;
    sp30 = arg0;
    sp10 = M2C_FIELD(&arg1, f64 *, 0);
    sp18 = M2C_FIELD(&arg1, f64 *, 8);
    sp3C = this->unk78;
    sp40 = this + 0x3D3;
    temp_r5_8076 = this->unk428;
    sp44 = temp_r5_8076 & 1;
    sp48 = (s32) &sp8 & -((temp_r5_8076 >> 0x12U) & 1);
    sp4D = 0;
    sp4C = this->unk54.unk8 == 0;
    sp4F = this->unk7C.GetState() == 2;
    ((SpyroEffects *) (M2C_BITWISE(SpyroEffects *, this->unk258)))->Update((SpyroEffectsUpdateData *) &sp10, GetInput());
    TryChangeState(sp8, 0xEU, NULL, 0U);
}
#endif

void Spyro::SetAutoHealthRegen(bool arg0) {
    M2C_FIELD(this, u8 *, 0x3E0) = arg0;
    this->unk3DC = 0.0f;
}

void Spyro::SetForceLookAtTarget(MKProp *arg0) {
    if (arg0 != NULL) {
        this->unk1B4.unk8 = (s32) arg0;
        M2C_FIELD(this, s8 *, 0x1BC) = 1;
        return;
    }
    this->unk1B4.unk8 = 0;
    M2C_FIELD(this, s8 *, 0x1BC) = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'const char[13]' to
void Spyro::UseCynderStrafeState(bool arg0, bool arg1) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_8163;
    KDCamera *temp_r3_8174;
    KDCamera *temp_r3_8188;
    KDCamera *temp_r3_8199;
    s8 temp_r0_8216;
    u8 temp_r4_8213;

    if ((u8) this->unk3CE != arg0) {
        if (arg0 != 0) {
            M2C_FIELD(this, s32 *, 0x3D8) = M2C_FIELD(*gMK, s32 (**)(void **, void *), 0x60)(gMK, "CynderConvex");
            temp_r3_8163 = GetCamera();
            sp24 = 0;
            sp20 = 0x159;
            M2C_FIELD(temp_r3_8163->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp20);
            temp_r3_8174 = GetCamera();
            sp1C = 0;
            sp18 = 0x431;
            M2C_FIELD(temp_r3_8174->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
        } else {
            M2C_FIELD(this, s32 *, 0x3D8) = 0;
            temp_r3_8188 = GetCamera();
            sp14 = 0;
            sp10 = 0x157;
            M2C_FIELD(temp_r3_8188->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
            temp_r3_8199 = GetCamera();
            spC = 0;
            sp8 = 0x433;
            M2C_FIELD(temp_r3_8199->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
    this->unk3CE = arg0;
    temp_r4_8213 = this->unk3CE;
    temp_r0_8216 = temp_r4_8213 == 0;
    gb.unk5 = temp_r0_8216;
    gb.unk6 = temp_r0_8216;
    gb.unk7 = temp_r0_8216;
    if (arg1 != 0) {
        if (temp_r4_8213 != 0) {
            this->unk54.SetState(3, NULL);
            return;
        }
        this->unk54.SetState(4, NULL);
    }
}
#endif

void Spyro::SelectStrafeTarget(bool arg0) {
    this->unkB90.SelectTarget(arg0);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 Spyro::IsPlayingStrafeAnim() {
    s32 var_r30_8263;
    s32 var_r31_8264;

    var_r30_8263 = 0xB;
    var_r31_8264 = 0x58;
loop_1:
    if ((u32) GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 == (u32) *(this->unkB4 + (var_r31_8264 + 4))) {
        return 1U;
    }
    var_r30_8263 += 1;
    var_r31_8264 += 8;
    if (var_r30_8263 >= 0x1C) {
        return 0U;
    }
    goto loop_1;
}
#endif

u8 Spyro::CanStrafe() {
    return 1U;
}

#if 0 // DRAFT: undefined identifier 'unk30C'
void Spyro::SetInvincibilityTimeOut(float arg0) {
    M2C_FIELD(this, f32 *, 0x3DC) = (f32) (gb.unk30C + arg0);
}
#endif

void Spyro::UpdateInvincibility() {

}

#if 0 // DRAFT: undefined identifier 'sp10'
void Spyro::UpdateSlidingSounds() {
    f64 sp48;
    f64 sp40;
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp8;
    MKProp *temp_r3_8337;
    f32 var_f4_8464;
    f32 var_f5_8397;
    f64 temp_f1_8403;
    f64 temp_f1_8409;
    f64 temp_f1_8413;
    s32 temp_cr0_gt_8344;
    s32 temp_r3_8342;
    s32 temp_r3_8432;
    s32 var_r0_8359;
    s32 var_r0_8442;
    void *temp_r3_8325;
    void *var_r3_8354;

    temp_r3_8325 = this->unk8;
    sp20 = M2C_FIELD(temp_r3_8325, f64 *, 0x30);
    sp28 = M2C_FIELD(temp_r3_8325, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_r3_8337 = this->unk26C.unk8;
    temp_r3_8342 = M2C_FIELD(temp_r3_8337, s32 *, 0x16C);
    sp18 = (f32) sp28 - this->unk310;
    temp_cr0_gt_8344 = temp_r3_8342 > 0;
    sp40 = sp10;
    unksp44 = 0.0f;
    sp48 = (f64) sp18;
    if (temp_cr0_gt_8344 != 0) {
        if (temp_cr0_gt_8344 != 0) {
            if (temp_r3_8342 != 0) {
                var_r3_8354 = &temp_r3_8337->unk8 + ((temp_r3_8342 - 1) * 0x58);
            } else {
                var_r3_8354 = NULL;
            }
            var_r0_8359 = M2C_FIELD(var_r3_8354, s32 *, 0x44);
        } else {
            var_r0_8359 = 0;
        }
        if ((var_r0_8359 & 8) && ((((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44))) > 1.0f) && ((u32) GetAnimScript((Spyro::AnimScriptNode) 0)->unk20 == (u32) M2C_FIELD(this->unkB4, u32 *, 0x54))) {
            sp30 = M2C_FIELD(this, f64 *, 0x338);
            sp38 = M2C_FIELD(this, f64 *, 0x340);
            var_f5_8397 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + (unksp34 * unksp34));
            if (var_f5_8397 > 0.000001f) {
                if (var_f5_8397 > 0.0f) {
                    temp_f1_8403 = __frsqrte(var_f5_8397);
                    temp_f1_8409 = 0.5 * temp_f1_8403 * -(((f64) var_f5_8397 * (temp_f1_8403 * temp_f1_8403)) - 3.0);
                    temp_f1_8413 = 0.5 * temp_f1_8409 * -(((f64) var_f5_8397 * (temp_f1_8409 * temp_f1_8409)) - 3.0);
                    var_f5_8397 = (f32) ((f64) var_f5_8397 * (0.5 * temp_f1_8413 * -(((f64) var_f5_8397 * (temp_f1_8413 * temp_f1_8413)) - 3.0)));
                } else if (var_f5_8397 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_8397 = __float_nan;
                } else {
                    sp8 = var_f5_8397;
                    temp_r3_8432 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_8432) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_8442 = 1;
                        } else {
                            var_r0_8442 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_8442 = 5;
                        } else {
                            var_r0_8442 = 3;
                        }
                        break;
                    default:
                        var_r0_8442 = 4;
                        break;
                    }
                    if (var_r0_8442 == 1) {
                        var_f5_8397 = __float_nan;
                    }
                }
                var_f4_8464 = 1.0f / var_f5_8397;
            } else {
                var_f4_8464 = 0.0f;
                var_f5_8397 = 0.0f;
            }
            sp30 = (f32) sp30 * var_f4_8464;
            unksp34 *= var_f4_8464;
            sp38 = (f32) sp38 * var_f4_8464;
            if (var_f5_8397 < 200.0f) {

            } else {
                var_f5_8397 = 200.0f;
            }
            if (var_f5_8397 > -200.0f) {

            }
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            if (this->unk6F8.SoundIsFadingIn(3) == 0) {
                this->unk6F8.FadeIn(3, -1);
            }
        } else {
            goto block_38;
        }
    } else {
block_38:
        if (this->unk6F8.SoundIsFadingOut(3) == 0) {
            this->unk6F8.FadeOut(3);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Spyro::UpdateWaterSurfaceFX(bool arg0) {
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_8553;
    f32 var_f4_8596;
    f32 var_f5_8606;
    f64 temp_f1_8611;
    f64 temp_f1_8617;
    f64 temp_f1_8621;
    s32 temp_r3_8555;
    s32 temp_r3_8640;
    s32 var_r0_8650;
    u32 var_r0_8569;
    void *temp_r3_8709;
    void *temp_r6_8542;
    void *var_r3_8564;

    sp10 = 0.0f;
    spC = 0.0f;
    temp_r6_8542 = this->unk8;
    sp58 = M2C_FIELD(temp_r6_8542, f64 *, 0x30);
    sp60 = M2C_FIELD(temp_r6_8542, f64 *, 0x38);
    if ((sp58.IsWithin(*((MKVector3 *) &sp10), &spC, (s32 *) temp_r6_8542) != 0) && (M2C_BITWISE(s32, spC) == 0)) {
        temp_r3_8553 = this->unk26C.unk8;
        temp_r3_8555 = M2C_FIELD(temp_r3_8553, s32 *, 0x16C);
        if (((u32) (-temp_r3_8555 & ~temp_r3_8555) >> 0x1FU) != 0) {
            if (temp_r3_8555 != 0) {
                var_r3_8564 = &temp_r3_8553->unk8 + ((temp_r3_8555 - 1) * 0x58);
            } else {
                var_r3_8564 = NULL;
            }
            var_r0_8569 = M2C_FIELD(var_r3_8564, u32 *, 0x44);
        } else {
            var_r0_8569 = 0U;
        }
        if (var_r0_8569 == 0x40U) {
            M2C_FIELD(M2C_FIELD(M2C_FIELD(this, void **, 0x264), WaterSurfaceFX **, 0xB8), f32 *, 0x60) = 2.0f;
        } else {
            M2C_FIELD(M2C_FIELD(M2C_FIELD(this, void **, 0x264), WaterSurfaceFX **, 0xB8), f32 *, 0x60) = 1.0f;
        }
        M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, Spyro *), 0xB0)(&sp48, this);
        sp78 = sp48;
        var_f4_8596 = 0.0f;
        sp80 = sp50;
        unksp7C = 0.0f;
        var_f5_8606 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + (0.0f * 0.0f));
        if (var_f5_8606 > 0.000001f) {
            if (var_f5_8606 > 0.0f) {
                temp_f1_8611 = __frsqrte(var_f5_8606);
                temp_f1_8617 = 0.5 * temp_f1_8611 * -(((f64) var_f5_8606 * (temp_f1_8611 * temp_f1_8611)) - 3.0);
                temp_f1_8621 = 0.5 * temp_f1_8617 * -(((f64) var_f5_8606 * (temp_f1_8617 * temp_f1_8617)) - 3.0);
                var_f5_8606 = (f32) ((f64) var_f5_8606 * (0.5 * temp_f1_8621 * -(((f64) var_f5_8606 * (temp_f1_8621 * temp_f1_8621)) - 3.0)));
            } else if (var_f5_8606 < M2C_BITWISE(f32, 0.0)) {
                var_f5_8606 = __float_nan;
            } else {
                sp8 = var_f5_8606;
                temp_r3_8640 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_8640) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_8650 = 1;
                    } else {
                        var_r0_8650 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_8650 = 5;
                    } else {
                        var_r0_8650 = 3;
                    }
                    break;
                default:
                    var_r0_8650 = 4;
                    break;
                }
                if (var_r0_8650 == 1) {
                    var_f5_8606 = __float_nan;
                }
            }
            var_f4_8596 = 1.0f / var_f5_8606;
        } else {
            var_f5_8606 = 0.0f;
        }
        sp78 = (f32) sp78 * var_f4_8596;
        unksp7C *= var_f4_8596;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (var_f5_8606 == 25.0f) {
            this->unk6F8.FadeIn(0, -1);
        } else if (this->unk6F8.SoundIsFadingIn(0) != 0) {
            this->unk6F8.FadeOut(0);
        }
        if ((u8) M2C_FIELD(this, u8 *, 0x269) == 0) {
            ((WaterSurfaceFX *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), WaterSurfaceFX **, 0xB8)))->SpawnWake();
        }
        temp_r3_8709 = this->unk8;
        sp68 = M2C_FIELD(temp_r3_8709, f64 *, 0x30);
        sp70 = M2C_FIELD(temp_r3_8709, f64 *, 0x38);
        unksp6C = sp10;
        if (arg0 != 0) {
            sp20 = 0.0f;
            sp18 = 0.0f;
            sp1C = 400.0f;
            sp40 = (f64) sp20;
            sp38 = (f64) sp18;
            ((WaterSurfaceFX *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), WaterSurfaceFX **, 0xB8)))->AddMovementForce(*((MKVector3 *) &sp68), *((MKVector3 *) &sp38));
        } else {
            M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, Spyro *), 0xB0)(&sp28, this);
            ((WaterSurfaceFX *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), WaterSurfaceFX **, 0xB8)))->AddMovementForce(*((MKVector3 *) &sp68), *((MKVector3 *) &sp28));
        }
        M2C_FIELD(this, u8 *, 0x269) = 1U;
        return;
    }
    M2C_FIELD(this, u8 *, 0x269) = 0U;
    if (this->unk6F8.SoundIsFadingIn(0) != 0) {
        this->unk6F8.FadeOut(0);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKProp' to
void Spyro::UpdateEffects(MKVector3 *arg0) {
    f32 var_f30_8826;
    f32 var_f31_8822;
    f32 var_f4_8876;
    f32 var_f4_8943;
    f64 temp_f1_8882;
    f64 temp_f1_8888;
    f64 temp_f1_8892;
    s32 temp_r3_8911;
    s32 temp_r4_8829;
    s32 var_r0_8921;
    CheckForKnockBack(*((ContextInfo *) &this->unk26C.unk8->unk8), 0.0f);
    CheckForKnockBack(*(this->unk26C.unk8 + 0x170), 1.0f);
    CheckForKnockBack(*(this->unk26C.unk8 + 0x2D8), 1.0f);
    UpdateShockwavePosition();
    GetNodeMatrix((Spyro::Nodes) 0, (Matrix *) &arg_spF0);
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(M2C_FIELD(this, void **, 0x264), s32 *, 0x38), (MKVector3 *) &arg_spE0);
    arg_sp120 = arg_spE0;
    arg_sp124 = arg_spE4;
    arg_sp128 = arg_spE8;
    arg_sp12C = 1.0f;
    if ((u8) M2C_FIELD(this, u8 *, 0x25C) != 0) {
        var_f31_8822 = KDMath_GetPitch(*((MKVector3 *) &arg_sp110));
        GetYaw();
        var_f30_8826 = M2C_ERROR(/* Read from unset register $f1 */);
        if ((u8) M2C_FIELD(this, u8 *, 0x1BC) != 0) {
            temp_r4_8829 = this->unk1B4.unk8;
            if ((u32) temp_r4_8829 != 0U) {
                arg_sp14.Set((MKProp *) temp_r4_8829);
                if (M2C_FIELD(arg_sp14.Get()->__vptr, u8 (**)(MKVector3 *, M2C_UNK *), 0x28)(&zero, &arg_spD0) != 0) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    arg_spC0 = arg_sp50;
                    arg_sp58 = arg_spD8 - arg_sp128;
                    arg_spC8 = (f64) arg_sp58;
                    var_f31_8822 = KDMath_GetPitch(*((MKVector3 *) &arg_spC0));
                    var_f30_8826 = KDMath_GetYaw(*((MKVector3 *) &arg_spC0));
                }
            }
        }
        KDMath_GetDirection(var_f30_8826, var_f31_8822);
        var_f4_8876 = (arg_spA8 * arg_spA8) + ((arg_spA0 * arg_spA0) + (arg_spA4 * arg_spA4));
        if (var_f4_8876 > 1e-12f) {
            if (var_f4_8876 > 0.0f) {
                temp_f1_8882 = __frsqrte(var_f4_8876);
                temp_f1_8888 = 0.5 * temp_f1_8882 * -(((f64) var_f4_8876 * (temp_f1_8882 * temp_f1_8882)) - 3.0);
                temp_f1_8892 = 0.5 * temp_f1_8888 * -(((f64) var_f4_8876 * (temp_f1_8888 * temp_f1_8888)) - 3.0);
                var_f4_8876 = (f32) ((f64) var_f4_8876 * (0.5 * temp_f1_8892 * -(((f64) var_f4_8876 * (temp_f1_8892 * temp_f1_8892)) - 3.0)));
            } else if (var_f4_8876 < M2C_BITWISE(f32, 0.0)) {
                var_f4_8876 = __float_nan;
            } else {
                arg_sp10 = var_f4_8876;
                temp_r3_8911 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_8911) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_8921 = 1;
                    } else {
                        var_r0_8921 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_8921 = 5;
                    } else {
                        var_r0_8921 = 3;
                    }
                    break;
                default:
                    var_r0_8921 = 4;
                    break;
                }
                if (var_r0_8921 == 1) {
                    var_f4_8876 = __float_nan;
                }
            }
            var_f4_8943 = 1.0f / var_f4_8876;
        } else {
            var_f4_8943 = 0.0f;
        }
        arg_sp40 = arg_spA0 * var_f4_8943;
        arg_sp44 = arg_spA4 * var_f4_8943;
        arg_sp48 = arg_spA8 * var_f4_8943;
        arg_spB0 = (f64) arg_sp40;
        arg_spB8 = (f64) arg_sp48;
        arg_sp11C = 0.0f;
        arg_sp30 = -(f32) arg_spB0;
        arg_sp34 = -arg_spB4;
        arg_sp38 = -(f32) arg_spB8;
        arg_sp90 = (f64) arg_sp30;
        arg_sp98 = (f64) arg_sp38;
        arg_sp110 = (f32) arg_sp90;
        arg_sp114 = arg_sp94;
        arg_sp118 = (f32) arg_sp98;
    }
    arg_sp80 = M2C_FIELD(this, f64 *, 0x338);
    arg_sp88 = M2C_FIELD(this, f64 *, 0x340);
    UpdateBreathEffects((Matrix *) &arg_spF0, *((MKVector3 *) &arg_sp80));
    M2C_FIELD(this, f32 *, 0x248) = (f32) (M2C_FIELD(this, f32 *, 0x248) - gUpdateTimeDelta);
    UpdateInvincibility();
    MKVector(0.0f, 100.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk238 = arg_sp20;
    arg_sp28 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + arg_sp68;
    arg_sp70 = arg_sp20;
    arg_sp78 = (f64) arg_sp28;
    this->unk238 = (f64) arg_sp28;
    UpdateWaterSurfaceFX(0U);
    UpdateRage();
}
#endif

#if 0 // DRAFT: expression syntax error
void Spyro::AddFootEffect(int arg0) {
    f64 sp118;
    f64 sp110;
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
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
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    MKProp *temp_r3_9177;
    MKProp *temp_r3_9195;
    MKProp *temp_r3_9347;
    MKProp *temp_r3_9406;
    f32 var_f0_9250;
    f32 var_f0_9268;
    f32 var_f0_9290;
    f32 var_f0_9308;
    f32 var_f1_9259;
    f32 var_f1_9282;
    f32 var_f1_9299;
    f32 var_f4_9135;
    f32 var_f4_9227;
    f32 var_f5_9068;
    f64 temp_f1_9074;
    f64 temp_f1_9080;
    f64 temp_f1_9084;
    s32 temp_r3_9103;
    s32 temp_r3_9179;
    s32 temp_r3_9197;
    s32 temp_r4_9363;
    s32 temp_r5_9410;
    s32 var_r0_9113;
    s32 var_r29_9217;
    s32 var_r3_9211;
    void **var_r3_9379;
    void *temp_r3_9376;
    void *temp_r9_9332;
    void *var_r3_9185;
    void *var_r3_9206;
    void *var_r3_9368;
    void *var_r5_9417;

    if ((u8) M2C_FIELD(this, u8 *, 0x394) == 0) {
        spE0.GetNodePos((s32) this);
        sp110 = spE0;
        sp118 = spE8;
        sp100 = M2C_FIELD(this, f64 *, 0x338);
        sp108 = M2C_FIELD(this, f64 *, 0x340);
        var_f5_9068 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (unksp104 * unksp104));
        if (var_f5_9068 > 0.000001f) {
            if (var_f5_9068 > 0.0f) {
                temp_f1_9074 = __frsqrte(var_f5_9068);
                temp_f1_9080 = 0.5 * temp_f1_9074 * -(((f64) var_f5_9068 * (temp_f1_9074 * temp_f1_9074)) - 3.0);
                temp_f1_9084 = 0.5 * temp_f1_9080 * -(((f64) var_f5_9068 * (temp_f1_9080 * temp_f1_9080)) - 3.0);
                var_f5_9068 = (f32) ((f64) var_f5_9068 * (0.5 * temp_f1_9084 * -(((f64) var_f5_9068 * (temp_f1_9084 * temp_f1_9084)) - 3.0)));
            } else if (var_f5_9068 < M2C_BITWISE(f32, 0.0)) {
                var_f5_9068 = __float_nan;
            } else {
                sp8 = var_f5_9068;
                temp_r3_9103 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_9103) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_9113 = 1;
                    } else {
                        var_r0_9113 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_9113 = 5;
                    } else {
                        var_r0_9113 = 3;
                    }
                    break;
                default:
                    var_r0_9113 = 4;
                    break;
                }
                if (var_r0_9113 == 1) {
                    var_f5_9068 = __float_nan;
                }
            }
            var_f4_9135 = 1.0f / var_f5_9068;
        } else {
            var_f4_9135 = 0.0f;
            var_f5_9068 = 0.0f;
        }
        sp100 = (f32) sp100 * var_f4_9135;
        unksp104 *= var_f4_9135;
        sp108 = (f32) sp108 * var_f4_9135;
        if (var_f5_9068 < 200.0f) {

        } else {
            var_f5_9068 = 200.0f;
        }
        if (var_f5_9068 > -200.0f) {

        }
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp88 = 0.0f;
        sp80 = 0.0f;
        sp84 = 1.0f;
        spF8 = (f64) sp88;
        spF0 = (f64) sp80;
        temp_r3_9177 = this->unk26C.unk8;
        temp_r3_9179 = M2C_FIELD(temp_r3_9177, s32 *, 0x16C);
        if (temp_r3_9179 > 0) {
            if (temp_r3_9179 != 0) {
                var_r3_9185 = &temp_r3_9177->unk8 + ((temp_r3_9179 - 1) * 0x58);
            } else {
                var_r3_9185 = NULL;
            }
            spF0 = M2C_FIELD(var_r3_9185, f64 *, 0x10);
            spF8 = M2C_FIELD(var_r3_9185, f64 *, 0x18);
        }
        temp_r3_9195 = this->unk26C.unk8;
        temp_r3_9197 = M2C_FIELD(temp_r3_9195, s32 *, 0x16C);
        if (((u32) (-temp_r3_9197 & ~temp_r3_9197) >> 0x1FU) != 0) {
            if (temp_r3_9197 != 0) {
                var_r3_9206 = &temp_r3_9195->unk8 + ((temp_r3_9197 - 1) * 0x58);
            } else {
                var_r3_9206 = NULL;
            }
            var_r3_9211 = M2C_FIELD(var_r3_9206, s32 *, 0x44);
        } else {
            var_r3_9211 = 0;
        }
        var_r29_9217 = var_r3_9211;
        if (((u8) M2C_FIELD(this, u8 *, 0x269) != 0) && !(var_r3_9211 & 0x40)) {
            var_r29_9217 = 0x200;
        }
        sp50 = 1.0f;
        var_f4_9227 = this->unk2B8;
        sp54 = 1.0f;
        sp58 = 1.0f;
        spA0 = (f64) sp50;
        sp5C = 1.0f;
        sp60 = 0.25f;
        sp64 = 0.25f;
        sp68 = 0.25f;
        sp6C = 0.25f;
        spA8 = (f64) sp58;
        spB0 = (f64) sp60;
        spB8 = (f64) sp68;
        if (var_f4_9227 < (f32) spA0) {

        } else {
            var_f4_9227 = (f32) spA0;
        }
        var_f0_9250 = this->unk2C4;
        sp30 = var_f4_9227;
        if (var_f0_9250 < unkspA4) {

        } else {
            var_f0_9250 = unkspA4;
        }
        var_f1_9259 = this->unk2C0;
        sp34 = var_f0_9250;
        if (var_f1_9259 < (f32) spA8) {

        } else {
            var_f1_9259 = (f32) spA8;
        }
        var_f0_9268 = this->unk2C4;
        sp38 = var_f1_9259;
        if (var_f0_9268 < unkspAC) {

        } else {
            var_f0_9268 = unkspAC;
        }
        sp3C = var_f0_9268;
        sp40 = (f64) sp30;
        var_f1_9282 = (f32) sp40;
        sp48 = (f64) sp38;
        if (var_f1_9282 > (f32) spB0) {

        } else {
            var_f1_9282 = (f32) spB0;
        }
        var_f0_9290 = unksp44;
        sp20 = var_f1_9282;
        if (var_f0_9290 > unkspB4) {

        } else {
            var_f0_9290 = unkspB4;
        }
        var_f1_9299 = (f32) sp48;
        sp24 = var_f0_9290;
        if (var_f1_9299 > (f32) spB8) {

        } else {
            var_f1_9299 = (f32) spB8;
        }
        var_f0_9308 = unksp4C;
        sp28 = var_f1_9299;
        if (var_f0_9308 > unkspBC) {

        } else {
            var_f0_9308 = unkspBC;
        }
        sp2C = var_f0_9308;
        spC0 = (f64) sp20;
        spC8 = (f64) sp28;
        temp_r9_9332 = this->unk8;
        sp70 = -M2C_FIELD(temp_r9_9332, f32 *, 0x20);
        sp74 = -M2C_FIELD(temp_r9_9332, f32 *, 0x24);
        sp78 = -M2C_FIELD(temp_r9_9332, f32 *, 0x28);
        spD0 = (f64) sp70;
        spD8 = (f64) sp78;
        gb.unk60->EmitFootFX(*((MKVector3 *) &sp110), *((MKVector3 *) &spD0), *((MKVector3 *) &spF0), (MKVector4) &spC0, 1.0f, 1.0f, var_r29_9217);
        temp_r3_9347 = this->unk26C.unk8;
        if (((s32) M2C_FIELD(temp_r3_9347, s32 *, 0x16C) > 0) && ((var_r29_9217 & 0x40) || (var_r29_9217 & 0x10) || (var_r29_9217 & 0x10000) || (var_r29_9217 & 0x20000) || (var_r29_9217 & 0x40000))) {
            temp_r4_9363 = M2C_FIELD(temp_r3_9347, s32 *, 0x16C);
            if (temp_r4_9363 != 0) {
                var_r3_9368 = &temp_r3_9347->unk8 + ((temp_r4_9363 - 1) * 0x58);
            } else {
                var_r3_9368 = NULL;
            }
            if (((u8) M2C_FIELD(var_r3_9368, u8 *, 0x50) != 0) && (temp_r3_9376 = M2C_FIELD(var_r3_9368, void **, 0x48), ((temp_r3_9376 == NULL) == 0)) && (var_r3_9379 = M2C_FIELD(temp_r3_9376, void ***, 8), ((var_r3_9379 == NULL) == 0))) {

            } else {
                var_r3_9379 = NULL;
            }
            if ((var_r3_9379 == NULL) || ((u8) (M2C_FIELD(*var_r3_9379, s32 *, 0x14) != 0) != 1)) {
                sp10 = (f32) sp110;
                sp14 = this->unk2A4;
                sp18 = (f32) sp118;
                sp110 = (f64) sp10;
                sp118 = (f64) sp18;
                temp_r3_9406 = this->unk26C.unk8;
                sp90 = (f64) sp10;
                temp_r5_9410 = M2C_FIELD(temp_r3_9406, s32 *, 0x16C);
                sp98 = (f64) sp18;
                if (temp_r5_9410 != 0) {
                    var_r5_9417 = &temp_r3_9406->unk8 + ((temp_r5_9410 - 1) * 0x58);
                } else {
                    var_r5_9417 = NULL;
                }
                gb.unk60->AddFootStep(*((MKVector3 *) &sp110), *(var_r5_9417 + 0x10), *(this->unk8 + 0x20), 13.0f);
            }
        }
        if (((u8) M2C_FIELD(this, u8 *, 0x25D) != 0) && (M2C_BITWISE(s32, this->unk24C) == 0)) {
            ((GroundFire *) (M2C_FIELD(M2C_FIELD(this->unk258, void **, 4), s32 *, 0x14) + 0x140))->Emit(*((MKVector3 *) &sp110), 1.0f, 1U);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp38'
void Spyro::ColorSpyroFromGround(float arg0) {
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spA8;
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
    f32 sp40;
    f32 temp_r3_9546;
    f32 temp_r3_9560;
    u8 temp_r4_9543;
    void **var_r0_9549;
    void **var_r3_9563;
    void *temp_r3_9490;
    void *temp_r3_9534;

    this->unk298 = 0.0f;
    this->unk2A4 = 0.0f;
    this->unk2A0 = 0.0f;
    this->unk2A8 = 0.0f;
    this->unk2B4 = 0.0f;
    this->unk2B0 = 0.0f;
    this->unk2B8 = 0.0f;
    this->unk2C4 = 0.0f;
    this->unk2C0 = 0.0f;
    this->unk2C4 = 1.0f;
    this->unk2C8 = 0.0f;
    this->unk2CC = 0.0f;
    M2C_FIELD(this, s16 *, 0x2D8) = 0;
    M2C_FIELD(this, s8 *, 0x2DA) = 0;
    M2C_FIELD(this, s8 *, 0x2DB) = 0;
    this->unk2D4 = 0.0f;
    M2C_FIELD(this, f32 *, 0x2E0) = 3.4028235e38f;
    this->unk2DC = 0;
    this->unk2E0 = 0.0f;
    this->unk2E4 = -1;
    M2C_FIELD(this, u8 *, 0x2F0) = 0U;
    temp_r3_9490 = this->unk8;
    sp50 = 0.0f;
    sp48 = 0.0f;
    sp4C = 100.0f;
    sp90 = (f64) sp50;
    sp88 = (f64) sp48;
    sp78 = M2C_FIELD(temp_r3_9490, f64 *, 0x30);
    sp80 = M2C_FIELD(temp_r3_9490, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spD8 = sp38;
    spC8 = sp38;
    sp40 = (f32) sp80 + (f32) sp90;
    spE0 = (f64) sp40;
    spD0 = (f64) sp40;
    unkspDC += 40.0f;
    unkspCC -= 4000.0f;
    this->unk268 = 0;
    M2C_FIELD(this, f32 *, 0x298) = 4000.0f;
    if (MKCollision_RayCollide(*((MKVector3 *) &spD8), *((MKVector3 *) &spC8), (MKCollisionResult *) &this->unk298, (MKCollisionMode) 7, 0x220) != 0) {
        temp_r3_9534 = this->unk8;
        spB8 = M2C_FIELD(temp_r3_9534, f64 *, 0x30);
        spC0 = M2C_FIELD(temp_r3_9534, f64 *, 0x38);
        M2C_FIELD(this, f32 *, 0x298) = (f32) (unkspBC - this->unk2A4);
        temp_r4_9543 = M2C_FIELD(this, u8 *, 0x2F0);
        if ((temp_r4_9543 != 0) && (temp_r3_9546 = this->unk2E0, ((M2C_BITWISE(u32, temp_r3_9546) == 0U) == 0)) && (var_r0_9549 = M2C_FIELD(temp_r3_9546, void ***, 8), ((var_r0_9549 == NULL) == 0))) {

        } else {
            var_r0_9549 = NULL;
        }
        if (var_r0_9549 != NULL) {
            if ((temp_r4_9543 != 0) && (temp_r3_9560 = this->unk2E0, ((M2C_BITWISE(u32, temp_r3_9560) == 0U) == 0)) && (var_r3_9563 = M2C_FIELD(temp_r3_9560, void ***, 8), ((var_r3_9563 == NULL) == 0))) {

            } else {
                var_r3_9563 = NULL;
            }
            if (!(M2C_FIELD(*var_r3_9563, s32 *, 0xC) & 0x400)) {
                goto block_13;
            }
        } else {
block_13:
            Tools_GroundColor((MKCollisionResult *) &spA8);
            M2C_FIELD(this, f64 *, 0x288) = spA8;
            this->unk288 = spB0;
            MKModel_GetColor(this->unk4);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f3, $r3, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f3 */);
            sp68 = sp28;
            sp70 = sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp58 = sp18;
            sp60 = sp20;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            sp98 = sp8;
            spA0 = sp10;
            MKModel_SetColor(this->unk4, *((MKVector4 *) &sp98));
            goto block_14;
        }
    } else {
block_14:
        this->unk268 = 1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned long' to
void Spyro::BridgeHit(float arg0, float arg1) {
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    s32 spCC;
    s32 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
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
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r4_9643;
    void *temp_r5_9646;

    temp_r4_9643 = this->unk40C;
    if (temp_r4_9643 != NULL) {
        temp_r5_9646 = this->unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f4 */);
        sp88 = sp48;
        sp50 = M2C_FIELD(temp_r5_9646, f32 *, 8) * arg0;
        sp98 = M2C_FIELD(temp_r5_9646, f64 *, 0x30);
        sp90 = (f64) sp50;
        spA0 = M2C_FIELD(temp_r5_9646, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
        sp78 = M2C_FIELD(this, f64 *, 0x338);
        spB8 = sp38;
        sp40 = (f32) spA0 + (f32) sp90;
        sp80 = M2C_FIELD(this, f64 *, 0x340);
        spC0 = (f64) sp40;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f7 */);
        spA8 = sp28;
        sp30 = (f32) sp80 * 0.002f;
        spC = -1.0f;
        spB0 = (f64) sp30;
        sp8 = -(f32) spA8;
        unkspAC = 1.0f;
        sp10 = -(f32) spB0;
        sp58 = (f64) sp8;
        spCC = 0;
        sp60 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
        spD0 = sp38;
        spD8 = (f64) sp40;
        sp20 = (f32) sp60 * arg1;
        spE0 = sp18;
        spE8 = (f64) sp20;
        spC8 = 0x3C;
        sp68 = sp18;
        sp70 = (f64) sp20;
        M2C_FIELD(M2C_FIELD(temp_r4_9643, void **, 0x44), M2C_UNK (**)(void *, s32 *, void *, f64, f32, f32, f64, f64, f64, f32), 0x2C)(temp_r4_9643, &spC8, temp_r5_9646, sp18, (f32) sp60, 1.0f, (f64) sp30, (f64) sp40, sp38, 0.002f);
    }
}
#endif

void Spyro::BroadcastMessage(int arg0) {
    s32 spC;
    s32 sp8;

    sp8 = arg0;
    spC = 0;
    M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 0, 0, 1, 0.0f);
}

#if 0 // DRAFT: ')' expected
void Spyro::BroadcaseCollectRequestMessage(float arg0) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    void *sp28;
    Spyro *sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    MKVector3 sp8;
    f32 temp_f0_9799;
    f32 temp_f0_9834;
    f32 temp_f28_9823;
    f32 temp_f29_9820;
    f32 temp_f30_9826;
    f32 temp_f31_9794;
    f32 temp_f31_9829;

    if ((u8) M2C_FIELD(this, u8 *, 0x3CD) == 0) {
        sp1C = 0;
        if (arg0 > 0.0f) {
            MKModel_CalculateCentre(this->unk4, &sp8);
            this->unk6F4->StoreClosestProps(sp8, arg0, 0x5E);
            temp_f31_9794 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xC4);
            temp_f0_9799 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xB8);
            sp18 = 9;
            sp20 = 0;
            sp24 = this;
            sp28 = this->unk8 + 0x30;
            sp2C = temp_f0_9799;
            sp30 = arg0;
            sp34 = temp_f31_9794;
            sp38 = arg0;
            sp3C = arg0;
            this->unk6F4->SendMessage((MKMessage *) &sp18, 0, arg0);
            return;
        }
        temp_f29_9820 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xC0);
        temp_f28_9823 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xC0);
        temp_f30_9826 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xC4);
        temp_f31_9829 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xBC);
        temp_f0_9834 = M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xB8);
        sp18 = 9;
        sp20 = 0;
        sp24 = this;
        sp28 = this->unk8 + 0x30;
        sp2C = temp_f0_9834;
        sp30 = temp_f31_9829;
        sp34 = temp_f30_9826;
        sp38 = temp_f28_9823;
        sp3C = temp_f29_9820;
        this->unk6F4->SendMessage((MKMessage *) &sp18, 0, M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0xC0));
    }
}
#endif

void Spyro::SetLVEScale(const MKVector3 &arg0) {
    this->unk68 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk70 = M2C_FIELD(&arg0, f64 *, 8);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::AnimEvents'
void Spyro::ProcessAnimationEvent(Spyro::AnimEvents arg1) {
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
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
    f32 var_f31_10070;
    s32 var_r29_10043;

    switch ((s32) arg1) {                           /* switch 1 */
    case 6:                                         /* switch 1 */
        AddFootEffect(2);
        break;
    case 7:                                         /* switch 1 */
        AddFootEffect(3);
        break;
    case 8:                                         /* switch 1 */
        AddFootEffect(4);
        break;
    case 9:                                         /* switch 1 */
        AddFootEffect(5);
        break;
    case 14:                                        /* switch 1 */
        if (((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), LineSegmentTrail **, 0xC8)))->TrailActive() == 0) {
            sp28 = 0.125f;
            sp2C = 0.125f;
            sp30 = 0.125f;
            sp34 = 1.0f;
            sp58 = (f64) sp28;
            sp60 = (f64) sp30;
            ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), LineSegmentTrail **, 0xC8)))->BeginTrail(*((MKVector4 *) &sp58));
        }
        break;
    case 15:                                        /* switch 1 */
        if (((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), LineSegmentTrail **, 0xCC)))->TrailActive() == 0) {
            sp18 = 0.125f;
            sp1C = 0.125f;
            sp20 = 0.125f;
            sp24 = 1.0f;
            sp48 = (f64) sp18;
            sp50 = (f64) sp20;
            ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), LineSegmentTrail **, 0xCC)))->BeginTrail(*((MKVector4 *) &sp48));
        }
        break;
    case 16:                                        /* switch 1 */
        ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), LineSegmentTrail **, 0xC8)))->EndTrail();
        break;
    case 17:                                        /* switch 1 */
        ((LineSegmentTrail *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), LineSegmentTrail **, 0xCC)))->EndTrail();
        break;
    case 18:                                        /* switch 1 */
        this->unk178.unk38 = 1;
        break;
    case 19:                                        /* switch 1 */
        this->unk178.unk38 = 0;
        break;
    case 23:                                        /* switch 1 */
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp68 = (f64) sp8;
        sp70 = (f64) sp10;
        switch ((s32) gameData.unk158) { /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            sp68 = 1.0f;
            unksp6C = 0.8f;
            sp70 = 0.0f;
            unksp74 = 1.0f;
            break;
        case 1:                                     /* switch 2 */
            sp68 = 1.0f;
            unksp6C = 1.0f;
            sp70 = 0.0f;
            unksp74 = 1.0f;
            break;
        case 2:                                     /* switch 2 */
            sp70 = 1.0f;
            sp68 = 0.0f;
            unksp6C = 0.0f;
            unksp74 = 1.0f;
            break;
        case 3:                                     /* switch 2 */
            unksp6C = 1.0f;
            sp68 = 0.0f;
            sp70 = 0.0f;
            unksp74 = 1.0f;
            break;
        }
        sp38 = (f64) sp68;
        sp40 = (f64) sp70;
        ((EarthShockwave *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), EarthShockwave **, 0x34)))->Trigger(*(this->unk8 + 0x30), 0.5f, 0U, (MKVector4) &sp38);
        break;
    }
    var_r29_10043 = 0;
    switch ((s32) gameData.unk158) {     /* switch 3; irregular */
    case 0:                                         /* switch 3 */
        var_r29_10043 = 0;
        break;
    case 1:                                         /* switch 3 */
        var_r29_10043 = 1;
        break;
    case 2:                                         /* switch 3 */
        var_r29_10043 = 2;
        break;
    case 3:                                         /* switch 3 */
        var_r29_10043 = 3;
        break;
    }
    var_f31_10070 = 1.0f;
    if ((u8) M2C_FIELD(this, u8 *, 0x25D) != 0) {
        var_f31_10070 = 2.0f;
    }
    ((MeleeTrails *) (M2C_FIELD(M2C_FIELD(this, void **, 0x264), MeleeTrails **, 0x2C)))->EnableTrail(GetAnimScript((Spyro::AnimScriptNode) 0)->unk20, var_r29_10043, 1U, 1.0f, var_f31_10070, 1.0f);
    this->unk54.ProcessAnimEvent((u32) arg1);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Spyro *' to
void Spyro::UpdateEvents() {
    s32 sp8;
    MKAnimScript *temp_r30_10118;
    MKProp *temp_r4_10157;
    s32 temp_cr0_eq_10137;
    s32 temp_r3_10158;
    s32 temp_r4_10164;
    s32 var_r27_10113;
    s32 var_r29_10111;
    u32 var_r5_10174;
    u8 var_r26_10141;
    void *var_r3_10169;

    if ((u8) M2C_FIELD(this, u8 *, 0x3CE) == 0) {
        var_r29_10111 = 0;
        var_r27_10113 = 0;
        do {
            sp8 = 0;
            temp_r30_10118 = this + (var_r27_10113 + 0xC0);
loop_6:
            if (sp8 < 0x18) {
                if (temp_r30_10118->CheckEvent(sp8) != 0) {
                    ProcessAnimationEvent((Spyro::AnimEvents) sp8);
                }
                sp8 += 1;
                goto loop_6;
            }
            temp_cr0_eq_10137 = (void *) gb.unkC == NULL;
            if (temp_cr0_eq_10137 == 0) {
                if (temp_cr0_eq_10137 == 0) {
                    var_r26_10141 = 0;
                    if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                        var_r26_10141 = 1;
                    }
                    if (var_r26_10141 == 0) {
                        goto block_14;
                    }
                }
            } else {
block_14:
                temp_r4_10157 = this->unk26C.unk8;
                temp_r3_10158 = M2C_FIELD(temp_r4_10157, s32 *, 0x16C);
                if (((u32) (-temp_r3_10158 & ~temp_r3_10158) >> 0x1FU) != 0) {
                    temp_r4_10164 = M2C_FIELD(temp_r4_10157, s32 *, 0x16C);
                    if (temp_r4_10164 != 0) {
                        var_r3_10169 = &temp_r4_10157->unk8 + ((temp_r4_10164 - 1) * 0x58);
                    } else {
                        var_r3_10169 = NULL;
                    }
                    var_r5_10174 = M2C_FIELD(var_r3_10169, u32 *, 0x44);
                } else {
                    var_r5_10174 = 0;
                }
                KDSound_Play3d(temp_r30_10118, this->unk8 + 0x30, var_r5_10174, 0.0f, 0U);
            }
            var_r29_10111 += 1;
            var_r27_10113 += 0x58;
        } while (var_r29_10111 < 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Spyro' to
void Spyro::UpdateAnimation() {
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f7_10233;
    s32 var_r28_10209;
    s32 var_r30_10211;
    s32 var_r31_10210;
    void *temp_r29_10272;
    void *temp_r3_10225;

    if (this->unk428 & 2) {
        var_r28_10209 = 0;
        var_r31_10210 = 0;
        var_r30_10211 = 0;
        do {
            if (var_r28_10209 == 0) {
                ((MKAnimScript *) (this + (var_r30_10211 + 0xC0)))->Animate(MKModel_GetAnimation(this->unk4), *(this + (var_r31_10210 + 0x170)), &sp48);
                temp_r3_10225 = MKModel_GetWorldMatrix(this->unk4);
                temp_f7_10233 = M2C_BITWISE(f32, sp48);
                sp18 = (sp48.unk8 * M2C_FIELD(temp_r3_10225, f32 *, 0x20)) + ((temp_f7_10233 * M2C_FIELD(temp_r3_10225, f32 *, 0)) + (sp48.unk4 * M2C_FIELD(temp_r3_10225, f32 *, 0x10)));
                sp1C = (sp48.unk8 * M2C_FIELD(temp_r3_10225, f32 *, 0x24)) + ((temp_f7_10233 * M2C_FIELD(temp_r3_10225, f32 *, 4)) + (sp48.unk4 * M2C_FIELD(temp_r3_10225, f32 *, 0x14)));
                sp20 = (sp48.unk8 * M2C_FIELD(temp_r3_10225, f32 *, 0x28)) + ((temp_f7_10233 * M2C_FIELD(temp_r3_10225, f32 *, 8)) + (sp48.unk4 * M2C_FIELD(temp_r3_10225, f32 *, 0x18)));
                sp28 = (f64) sp18;
                sp30 = (f64) sp20;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r27, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
                sp38 = sp8;
                sp10 = M2C_FIELD(this, f32 *, 0x70) * (f32) sp30;
                sp40 = (f64) sp10;
                SetDeltaPos(*((MKVector3 *) &sp38));
            } else {
                temp_r29_10272 = this + var_r30_10211;
                if (!(M2C_FIELD(temp_r29_10272, s32 *, 0xEC) & 1)) {
                    ((MKAnimScript *) (temp_r29_10272 + 0xC0))->Animate(MKModel_GetAnimation(this->unk4), *(this + (var_r31_10210 + 0x170)), NULL);
                }
            }
            var_r28_10209 += 1;
            var_r30_10211 += 0x58;
            var_r31_10210 += 4;
        } while (var_r28_10209 < 2);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void Spyro::DeathReset() {
    Animation *temp_r31_10314;

    SetAnim(0U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    temp_r31_10314 = MKModel_GetAnimation(this->unk4);
    ((MKAnimScript *) (GetAnimScript((Spyro::AnimScriptNode) 0)))->Animate(temp_r31_10314, -1, NULL);
    gameData.unk70.SetValue(gameData.unk74, 0U);
    ((Stat *) (&gameData.unk70 + 0x30))->SetValue(gameData.unkA4, 0U);
    this->unkB74 = 0.0f;
    this->unkB78.Reset();
    this->unk250 = 0.0f;
    this->unk248 = 0.0f;
    M2C_FIELD(this, f32 *, 0x248) = 0.0f;
    this->unkB90.SetDefaults();
    if (((u8) M2C_FIELD(this, u8 *, 0x25D) != 0) && (M2C_FIELD(this, f32 *, 0x24C) > 0.0f)) {
        ((Stat *) (&gameData.unk70 + 0x48))->SetValue(0.0f, 0U);
    }
    M2C_FIELD(this, f32 *, 0x24C) = 0.0f;
    M2C_FIELD(this, u8 *, 0x25D) = 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void Spyro::ClearData() {
    f64 temp_f30_10445;
    f64 temp_f31_10449;
    s32 var_r28_10448;
    s32 var_r29_10446;
    s32 var_r30_10450;
    void *temp_r4_10462;

    this->unk320 = 0.0f;
    this->unk324 = 1.0f;
    this->unk330 = 0.0f;
    this->unk330 = 0.0f;
    this->unk33C = 0.0f;
    this->unk338 = 0.0f;
    this->unk340 = 0.0f;
    this->unk34C = 0.0f;
    this->unk348 = 0.0f;
    this->unk428 = 0xE3FA7;
    this->unk388 = 3800.0f;
    M2C_FIELD(this, f32 *, 0x388) = 0.0f;
    M2C_FIELD(this, f64 *, 0x368) = (f64) M2C_FIELD(&zero, f64 *, 0);
    this->unk368 = M2C_FIELD(&zero, f64 *, 8);
    this->unk370 = M2C_FIELD(this, f64 *, 0x368);
    this->unk378 = this->unk368;
    this->unk3C4 = 0.0f;
    this->unk3C0 = 1500.0f;
    this->unk318 = 0.0f;
    this->unk3C0 = 0.0f;
    M2C_FIELD(this, s8 *, 0x394) = 0;
    this->unk1C4 = 0;
    M2C_FIELD(this, s8 *, 0x1C7) = 1;
    M2C_FIELD(this, s8 *, 0x3D1) = 0;
    M2C_FIELD(this, s8 *, 0x3D3) = 0;
    this->unk3CE = 0;
    M2C_FIELD(this, s32 *, 0x3D8) = 0;
    this->unk3CD = 0;
    M2C_FIELD(this, s32 *, 0x3E8) = 0;
    M2C_FIELD(this, f32 *, 0x298) = 0.0f;
    this->unk390 = 0.0f;
    M2C_FIELD(this, f32 *, 0x39C) = 0.0f;
    this->unk398 = 0.0f;
    this->unk3E4 = 0.0f;
    M2C_FIELD(this, f32 *, 0x3DC) = 0.0f;
    gameData.unk70.Init(50.0f, 50.0f, NULL, NULL);
    ((Stat *) (&gameData.unk70 + 0x30))->Init(30.0f, 30.0f, NULL, NULL);
    temp_f30_10445 = M2C_FIELD(&zero, f64 *, 0);
    var_r29_10446 = 0;
    this->unk308 = 0.0f;
    var_r28_10448 = 0;
    temp_f31_10449 = M2C_FIELD(&zero, f64 *, 8);
    var_r30_10450 = 0;
    this->unk314 = 0.0f;
    this->unk310 = 0.0f;
    this->unkB74 = 0.0f;
    M2C_FIELD(this, f32 *, 0x4B8) = 0.0f;
    this->unk460.unk54 = 0.0f;
    M2C_FIELD(this, s8 *, 0x25C) = 0;
    this->unk4C0 = 0;
    do {
        temp_r4_10462 = this + var_r30_10450;
        var_r28_10448 += 1;
        M2C_FIELD(temp_r4_10462, s32 *, 0x4D0) = (s32) (checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r29_10446 + 0xDC));
        var_r29_10446 += 0x1C;
        var_r30_10450 += 0x20;
        M2C_FIELD(temp_r4_10462, f64 *, 0x4D8) = temp_f30_10445;
        M2C_FIELD(temp_r4_10462, f64 *, 0x4E0) = temp_f31_10449;
        M2C_FIELD(temp_r4_10462, f32 *, 0x4E8) = 0.0f;
    } while (var_r28_10448 < 0x11);
    this->unk1B4.Set(NULL);
    this->unk430.unk28.Init();
    ResetCrowdTest();
    this->unkB90.SetDefaults();
    this->unkB90.unkC = 0.0f;
    this->unk78 = 0;
    ClearMeleeButtonState();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void Spyro::Message(MKMessage *arg0) {
    s8 sp391;
    s8 sp390;
    s32 sp38C;
    f32 sp388;
    s32 sp384;
    s8 sp382;
    s8 sp381;
    s8 sp380;
    f64 sp378;                                      /* compiler-managed */
    f64 sp370;                                      /* compiler-managed */
    u32 sp36C;
    s32 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    s32 sp344;
    s32 sp340;
    s8 sp339;
    s8 sp338;
    s32 sp334;
    f32 sp330;
    s32 sp32C;
    s8 sp32A;
    s8 sp329;
    s8 sp328;
    f64 sp320;                                      /* compiler-managed */
    f64 sp318;                                      /* compiler-managed */
    u32 sp314;
    s32 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    s32 sp2EC;
    s32 sp2E8;
    MKCollisionResult sp290;
    SpyroStateMessages sp238;
    s8 sp231;
    s8 sp230;
    s32 sp22C;
    f32 sp228;
    s32 sp224;
    s8 sp222;
    s8 sp221;
    s8 sp220;
    f64 sp218;                                      /* compiler-managed */
    f64 sp210;                                      /* compiler-managed */
    u32 sp20C;
    s32 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    s32 sp1E4;
    s32 sp1E0;
    SpyroStateMessages sp18C;
    MKProp sp140;
    f64 sp138;
    f64 sp130;
    M2C_UNK sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKProp spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    MKProp sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    HurtMessage *temp_r3_10986;
    HurtMessage *temp_r3_11095;
    KDCamera *temp_r3_11347;
    KDS_Message_PropResolve *temp_r29_11281;
    Sparx *temp_r3_11560;
    Spyro *var_r0_11539;
    f32 temp_f0_11014;
    f32 temp_f3_11027;
    f32 temp_f4_11024;
    f32 temp_f5_11020;
    f32 temp_r3_11305;
    f64 temp_f2_11192;
    f64 temp_f3_11190;
    s32 temp_r0_10513;
    s32 var_r4_10834;
    s8 temp_r29_11519;
    u32 temp_r4_10721;
    u32 temp_r4_11040;
    u32 temp_r4_11571;
    u32 temp_r9_10711;
    u8 temp_r29_11448;
    u8 var_r3_11138;
    void *temp_r29_10945;
    void *temp_r29_11486;
    void *temp_r29_11493;
    void *temp_r3_10767;
    void *temp_r3_10861;
    void *temp_r3_10934;
    void *temp_r3_11000;
    void *temp_r3_11010;
    void *temp_r3_11106;
    void *temp_r3_11349;
    void *temp_r3_11525;
    void *temp_r3_11537;
    void *temp_r3_11569;
    void *temp_r4_11114;
    void *temp_r4_11142;
    void *temp_r4_11348;
    void *temp_r6_11186;

    ((KDSound_AfterRumble *) (M2C_FIELD(this, s32 *, 0x264) + 0x40))->Message(arg0);
    temp_r0_10513 = arg0->unk0;
    if (temp_r0_10513 != 0x5B) {
        switch (temp_r0_10513) {                    /* irregular */
        case 0x1A:
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (gb.unk30C == M2C_FIELD(this, f32 *, 0x3DC)) {
                sp344 = 0;
                temp_r9_10711 = this->unk428;
                this->unk428 = temp_r9_10711 | 0x80;
                temp_r4_10721 = arg0->unk4;
                sp340 = 7;
                sp368 = 5;
                sp36C = temp_r4_10721;
                sp348 = M2C_FIELD(&up, f64 *, 0);
                sp350 = M2C_FIELD(&up, f64 *, 8);
                sp380 = 1;
                sp38C = 2;
                sp388 = 10.0f;
                sp381 = 0;
                sp382 = 1;
                sp384 = -1;
                sp358 = M2C_FIELD(&one, f64 *, 0);
                sp360 = M2C_FIELD(&one, f64 *, 8);
                sp390 = 0;
                if (temp_r4_10721 != 0) {
                    spB0.unk10.GetPos();
                    sp370 = M2C_BITWISE(f64, spB0.unk10);
                    sp378 = M2C_BITWISE(f64, spB0.unk18);
                } else {
                    sp370 = 0.0f;
                    unksp374 = 0.0f;
                    sp378 = 0.0f;
                }
                sp391 = 0;
                Hurt((HurtMessage *) &sp340);
                if ((u32) ((temp_r9_10711 >> 7U) & 1) == 0) {
                    this->unk428 &= 0xFFFFFF7F;
                }
            }
            goto block_216;
        case 0x38:
            temp_r3_10767 = checked_cast<TeleportMsg *, MKMessage>(arg0);
            Teleport(*(temp_r3_10767 + 8), M2C_FIELD(temp_r3_10767, f32 *, 0x18), 0x1E, 0U, M2C_FIELD(temp_r3_10767, u8 *, 0x1D));
            goto block_216;
        case 0x10:
            M2C_FIELD(this, s8 *, 0x1C6) = 1;
            UpdateSpyroCameraInfo();
            goto block_216;
        case 0x11:
            M2C_FIELD(this, s8 *, 0x1C6) = 0;
            goto block_216;
        case 0xAB:
            this->unk90 = 0;
            goto block_216;
        case 0xAC:
            this->unk90 = 1;
            goto block_216;
        case 0xB0:
            Hide();
            goto block_216;
        case 0xF7:
            this->unk204.unk4 = 1;
            M2C_FIELD(this, f32 *, 0x210) = 5.0f;
            goto block_216;
        case 0xB1:
            Show();
            goto block_216;
        case 0xBF:
            Disable();
            goto block_216;
        case 0xBE:
            Enable();
            goto block_216;
        case 0xA9:
            this->unkBB4 += 1;
            M2C_FIELD(this, s8 *, 0x1C4) = 0;
            if ((s32) this->unk54.unk8 == 0xE) {
                var_r4_10834 = 6;
                if ((s32) M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) > 0) {
                    var_r4_10834 = 4;
                }
                this->unk54.SetState(var_r4_10834, NULL);
            }
            goto block_216;
        case 0xAA:
            this->unkBB4 -= 1;
            if ((s32) this->unkBB4 <= 0) {
                this->unkBB4 = 0;
                M2C_FIELD(this, s8 *, 0x1C4) = 1;
            }
            goto block_216;
        case 0xA7:
            this->unkBB4 = 0;
            goto block_216;
        case 0x22:
            temp_r3_10861 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
            if ((u8) M2C_FIELD(temp_r3_10861, u8 *, 0x18) == 0) {
                sp140.GetPos();
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                sp140.unk10 = sp40;
                sp48 = M2C_FIELD(temp_r3_10861, MKVector3 **, 8)->unk8 - M2C_BITWISE(f32, sp140.unk8);
                sp140.unk18 = (f64) sp48;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
                this->unk348 += M2C_BITWISE(f32, sp140.unk18);
            } else {
                KDMath_GetYaw((Matrix *) this->unk8);
                Teleport(*(M2C_FIELD(temp_r3_10861, MKVector3 **, 8)), M2C_ERROR(/* Read from unset register $f1 */), 0x1E, 1U, 0U);
            }
            KDMath_GetYaw((Matrix *) this->unk8);
            this->unk3A0.YawTowards(M2C_FIELD(M2C_FIELD(temp_r3_10861, void **, 0xC), f32 *, 4) + M2C_ERROR(/* Read from unset register $f1 */), 900.0f);
            sp140.__vptr = NULL;
            sp140.unk40 = 0x40B;
            sp140.unk48 = M2C_FIELD(M2C_FIELD(temp_r3_10861, void **, 0xC), f32 *, 4);
            M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(s8 *), 0x2C)(&sp140.unk40);
            goto block_216;
        case 0x9C:
            PlatformDetach();
            M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) = 0;
            goto block_216;
        case 0x25:
            temp_r3_10934 = checked_cast<PlatformAttachedQueryMsg *, MKMessage>(arg0);
            M2C_FIELD(temp_r3_10934, s8 *, 0xC) = (s8) (M2C_FIELD(temp_r3_10934, s32 *, 8) == this->unk41C);
            goto block_216;
        case 0x9B:
            temp_r29_10945 = checked_cast<RopeBridgeMoveMsg *, MKMessage>(arg0);
            sp120.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp130 = sp30;
            sp38 = M2C_FIELD(M2C_FIELD(temp_r29_10945, void **, 8), f32 *, 8) - sp128;
            sp138 = (f64) sp38;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
            this->unk348 += (f32) sp138;
            goto block_216;
        case 0x7:
            if (((s32) this->unk54.unk8 != 0xA) && ((u8) this->unk90 != 0)) {
                M2C_FIELD(this, s32 *, 0x3E8) = (s32) (M2C_FIELD(this, s32 *, 0x3E8) + 1);
                if ((s32) M2C_FIELD(this, s32 *, 0x3E8) < 5) {
                    temp_r3_10986 = checked_cast<HurtMessage *, MKMessage>(arg0);
                    temp_r3_10986->unk50 = Hurt(temp_r3_10986);
                } else {
                    gAssertBool = 0;
                }
            }
            goto block_216;
        case 0x1:
            temp_r3_11000 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
            if ((u32) M2C_FIELD(temp_r3_11000, u32 *, 8) != this) {
                temp_r3_11010 = this->unk8;
                temp_f0_11014 = M2C_FIELD(temp_r3_11000, f32 *, 0x20) + GetCollisionRadius();
                sp110 = M2C_FIELD(temp_r3_11010, f64 *, 0x30);
                sp118 = M2C_FIELD(temp_r3_11010, f64 *, 0x38);
                temp_f5_11020 = unksp114 - M2C_FIELD(temp_r3_11000, f32 *, 0x14);
                temp_f4_11024 = (f32) sp110 - M2C_FIELD(temp_r3_11000, f32 *, 0x10);
                temp_f3_11027 = (f32) sp118 - M2C_FIELD(temp_r3_11000, f32 *, 0x18);
                if (((temp_f3_11027 * temp_f3_11027) + ((temp_f4_11024 * temp_f4_11024) + (temp_f5_11020 * temp_f5_11020))) < (temp_f0_11014 * temp_f0_11014)) {
                    sp2EC = 0;
                    temp_r4_11040 = M2C_FIELD(temp_r3_11000, u32 *, 8);
                    sp2E8 = 7;
                    sp310 = 1;
                    sp314 = temp_r4_11040;
                    sp2F0 = M2C_FIELD(&zero, f64 *, 0);
                    sp2F8 = M2C_FIELD(&zero, f64 *, 8);
                    sp328 = 0;
                    sp334 = 2;
                    sp330 = M2C_FIELD(temp_r3_11000, f32 *, 0x2C);
                    sp329 = 0;
                    sp32A = 0;
                    sp32C = -1;
                    sp300 = M2C_FIELD(&one, f64 *, 0);
                    sp308 = M2C_FIELD(&one, f64 *, 8);
                    sp338 = 0;
                    if (temp_r4_11040 != 0U) {
                        spB0.GetPos();
                        sp318 = M2C_BITWISE(f64, spB0);
                        sp320 = M2C_BITWISE(f64, spB0.unk8);
                    } else {
                        sp318 = 0.0f;
                        unksp31C = 0.0f;
                        sp320 = 0.0f;
                    }
                    sp339 = 0;
                    if (((s32) this->unk54.unk8 != 0xA) && ((u8) this->unk90 != 0)) {
                        Hurt((HurtMessage *) &sp2E8);
                    }
                }
            }
            goto block_216;
        case 0x8:
            if ((s32) this->unk54.unk8 != 0xA) {
                temp_r3_11095 = checked_cast<HurtMessage *, MKMessage>(arg0);
                temp_r3_11095->unk48 = 0.0f;
                temp_r3_11095->unk50 = Hurt(temp_r3_11095);
            }
            goto block_216;
        case 0xE:
            temp_r3_11106 = checked_cast<StableRepositionHero *, MKMessage>(arg0);
            StableReposition(*(temp_r3_11106 + 8), M2C_FIELD(temp_r3_11106, f32 *, 0x18), M2C_FIELD(temp_r3_11106, u8 *, 0x21), M2C_FIELD(temp_r3_11106, u8 *, 0x20));
            temp_r4_11114 = this->unk8;
            sp100 = M2C_FIELD(temp_r4_11114, f64 *, 0x30);
            sp108 = M2C_FIELD(temp_r4_11114, f64 *, 0x38);
            if (Connector_Update(*((MKVector3 *) &sp100)) == 0) {
                gb.unk32C->unk8 = 1;
                Music_Pause(1U);
            }
            if ((u8) gb.unk32C->unk8 != 0) {
                var_r3_11138 = 0;
                if (((u8) M2C_FIELD(gb.unkC, u8 *, 0xAA) != 0) || ((temp_r4_11142 = M2C_FIELD(gb.unkC, void **, 0x68), ((temp_r4_11142 == NULL) == 0)) && ((u8) M2C_FIELD(temp_r4_11142, u8 *, 0x5D) != 0))) {
                    var_r3_11138 = 1;
                }
                if (var_r3_11138 == 0) {
                    M2C_FIELD(gb.unkC, s8 *, 0xA9) = 0;
                }
            }
            goto block_216;
        case 0xB4:
            Hide();
            M2C_FIELD(this, s8 *, 0x1C7) = 0;
            goto block_216;
        case 0xB5:
            Show();
            M2C_FIELD(this, s8 *, 0x1C7) = 1;
            goto block_216;
        case 0x15:
            M2C_FIELD(this, s8 *, 0x1C7) = 1;
            gb.unk58 = 1;
            goto block_216;
        case 0x1B:
            this->unk1C4 = 1;
            goto block_216;
        case 0x1D:
            this->unk1C4 = 0;
            if (this->unk7C.GetState() == 2) {
                temp_r6_11186 = this->unk8;
                temp_f3_11190 = M2C_FIELD(temp_r6_11186, f64 *, 0x30);
                temp_f2_11192 = M2C_FIELD(temp_r6_11186, f64 *, 0x38);
                sp140.unk30 = temp_f3_11190;
                sp140.unk38 = temp_f2_11192;
                spB0.unk40 = temp_f3_11190;
                sp140.unk34 = M2C_BITWISE(f32, sp140.unk34) - 1000.0f;
                spB0.unk48 = temp_f2_11192;
                if (MKCollision_RayCollide(*((MKVector3 *) &spB0.unk40), *((MKVector3 *) &sp140.unk30), &sp290, (MKCollisionMode) 7, 0) != 0) {
                    spA0 = 0.0f;
                    spA4 = 1.0f;
                    spA8 = 0.0f;
                    spB0.unk20 = (f64) spA0;
                    spB0.unk28 = (f64) spA8;
                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                    spB0.unk30 = M2C_BITWISE(f64, sp50.unk40);
                    sp50.unk48 = sp290.unk8 + M2C_BITWISE(f32, spB0.unk28);
                    spB0.unk38 = (f64) sp50.unk48;
                    KDMath_GetYaw((Matrix *) this->unk8);
                    Teleport(*((MKVector3 *) &spB0.unk30), M2C_ERROR(/* Read from unset register $f1 */), 0x1E, 1U, 0U);
                }
            }
            if ((s32) this->unk54.unk8 != 0xA) {
                sp18C.unk50 = 0;
                this->unk54.Reset(4, sp18C);
                SetAnim(0U, 0.0f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
                this->unk3A0.RollTowards(0.0f, 26000.0f);
            }
            UpdateSpyroCameraInfo();
            sp1C = 0;
            sp18 = 0xB5;
            Message(&sp18);
            SpyroHud_ResetAfterCutScene();
            this->unkB90.unkC = gb.unk30C + 1.0f;
            goto block_216;
        case 0x802:
            temp_r29_11281 = checked_cast<KDS_Message_PropResolve *, MKMessage>(arg0);
            temp_r29_11281->Set((MKProp *) this, GetAnimScript((Spyro::AnimScriptNode) 0));
            goto block_216;
        case 0x3A:
            M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x78) = -1;
            goto block_216;
        case 0x3B:
            M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x78) = 0x220;
            goto block_216;
        case 0xE0:
            if (this->unk428 & 0x1000) {
                temp_r3_11305 = this->unk258;
                if (M2C_BITWISE(u32, temp_r3_11305) != 0U) {
                    ((SpyroEffects *) (M2C_BITWISE(SpyroEffects *, temp_r3_11305)))->ResetFury();
                }
                sp238.unk50 = 0;
                if (this->unk7C.GetState() == 2) {
                    sp238.AddMessage(0x183);
                }
                this->unk54.SetState(0xA, sp238);
            }
            goto block_216;
        case 0x3F:
            M2C_FIELD(this, s8 *, 0x3D1) = 1;
            goto block_216;
        case 0xC:
            M2C_FIELD(this, f32 *, 0x3DC) = (f32) (gb.unk30C + 1.0f);
            goto block_216;
        case 0x48:
            this->unk324 = M2C_FIELD(checked_cast<SetAlphaMessage *, MKMessage>(arg0), f32 *, 8);
            if ((this->unk324 < 1.0f) || ((temp_r3_11347 = GetCamera(), temp_r4_11348 = temp_r3_11347->unk8, temp_r3_11349 = temp_r3_11347->unk60.unk44, sp50.unk30 = M2C_FIELD(temp_r4_11348, f64 *, 0x30), sp50.unk20 = M2C_FIELD(temp_r3_11349, f64 *, 0), sp50.unk38 = M2C_FIELD(temp_r4_11348, f64 *, 0x38), sp50.unk28 = M2C_FIELD(temp_r3_11349, f64 *, 8), M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */), sp50.unk10 = sp20, sp28 = M2C_BITWISE(f32, sp50.unk28) - M2C_BITWISE(f32, sp50.unk38), sp50.unk18 = (f64) sp28, ((KDMath_GetPitch(*((MKVector3 *) &sp50.unk10)) < 0.0f) != 0)) && (GetCamera()->unk20C > 0.0f))) {
                sp14 = 0;
                sp10 = 0x4A;
                Message(&sp10);
            } else {
                spC = 0;
                sp8 = 0x49;
                Message(&sp8);
            }
            goto block_216;
        case 0x49:
            this->unk1D0.Show(1U);
            goto block_216;
        case 0x4A:
            this->unk1D0.Show(0U);
            goto block_216;
        case 0xD6:
            if ((u32) M2C_FIELD(&gb, u32 *, 0x3B8) != 0U) {
                sp140.unk24 = 0.0f;
                sp140.unk20 = 1.557e-42f;
                sp140.unk28 = (MKProp *) this;
                M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(f32 *), 0x2C)(&sp140.unk20);
            }
            goto block_216;
        case 0xE6:
            gameData.unk70.SetValue(gameData.unk74, 0U);
            goto block_216;
        case 0x52:
            temp_r29_11448 = M2C_FIELD(GetCollisionInfo(), u8 *, 4);
            M2C_FIELD(checked_cast<CollisionMsg *, MKMessage>(arg0), u8 *, 8) = temp_r29_11448;
            M2C_FIELD(GetCollisionInfo(), s8 *, 4) = 0;
            goto block_216;
        case 0x53:
            if ((u8) M2C_FIELD(checked_cast<CollisionMsg *, MKMessage>(arg0), u8 *, 8) != 0) {
                M2C_FIELD(GetCollisionInfo(), s8 *, 4) = 1;
            } else {
                M2C_FIELD(GetCollisionInfo(), s8 *, 4) = 0;
            }
            goto block_216;
        case 0x6D:
            temp_r29_11493 = checked_cast<QueryDamageTypeMsg *, MKMessage>(arg0);
            M2C_FIELD(temp_r29_11493, u8 *, 8) = (u8) ((M2C_FIELD(temp_r29_11493, u8 *, 8) & ~0x80) | ((IsCharging() << 7) & 0x80));
            M2C_FIELD(temp_r29_11493, u8 *, 8) = (u8) ((M2C_FIELD(temp_r29_11493, u8 *, 8) & ~0x40) | ((IsInTailSweep() << 6) & 0x40));
            M2C_FIELD(temp_r29_11493, u8 *, 8) = (u8) ((M2C_FIELD(temp_r29_11493, u8 *, 8) & ~0x20) | ((IsInTailStrike() << 5) & 0x20));
            goto block_216;
        case 0x6E:
            M2C_FIELD(checked_cast<QueryHeroMsg *, MKMessage>(arg0), s8 *, 8) = 1;
            goto block_216;
        case 0x6F:
            temp_r29_11519 = ((u32) this->unk428 >> 0x11U) & 1;
            M2C_FIELD(checked_cast<QueryTriggerCollapsibleMsg *, MKMessage>(arg0), s8 *, 8) = temp_r29_11519;
            goto block_216;
        case 0x8F:
            temp_r3_11525 = checked_cast<SetAnimMsg *, MKMessage>(arg0);
            SetAnim(M2C_FIELD(temp_r3_11525, u32 *, 8), M2C_FIELD(temp_r3_11525, f32 *, 0xC), (Spyro::AnimScriptNode) 0, M2C_FIELD(temp_r3_11525, u32 *, 0x10), M2C_FIELD(temp_r3_11525, f32 *, 0x14));
            goto block_216;
        case 0x8E:
            temp_r3_11537 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
            var_r0_11539 = this;
            if (this != NULL) {
                var_r0_11539 = (Spyro *) &this->unk4C;
            }
            M2C_FIELD(temp_r3_11537, Spyro **, 8) = var_r0_11539;
            return;
        default:
            M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
            goto block_216;
        case 0x39:
            PushAwayFrom(arg0);
            goto block_216;
        case 0xA0:
            temp_r3_11560 = this->unkB70;
            temp_r3_11560->Message(arg0);
            goto block_216;
        case 0x5:
            temp_r3_11569 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
            temp_r4_11571 = M2C_FIELD(temp_r3_11569, u32 *, 8);
            if (temp_r4_11571 != this) {
                sp1E4 = 0;
                sp1E0 = 7;
                sp208 = 1;
                sp20C = temp_r4_11571;
                sp1E8 = M2C_FIELD(&zero, f64 *, 0);
                sp1F0 = M2C_FIELD(&zero, f64 *, 8);
                sp220 = 1;
                sp22C = 2;
                sp228 = M2C_FIELD(temp_r3_11569, f32 *, 0x34);
                sp221 = 0;
                sp222 = 0;
                sp224 = -1;
                sp1F8 = M2C_FIELD(&one, f64 *, 0);
                sp200 = M2C_FIELD(&one, f64 *, 8);
                sp230 = 0;
                if (temp_r4_11571 != 0U) {
                    sp50.GetPos();
                    sp210 = M2C_BITWISE(f64, sp50);
                    sp218 = M2C_BITWISE(f64, sp50.unk8);
                } else {
                    sp210 = 0.0f;
                    unksp214 = 0.0f;
                    sp218 = 0.0f;
                }
                sp231 = 0;
                sp224 = M2C_FIELD(temp_r3_11569, s32 *, 0x4C);
                if (((s32) this->unk54.unk8 != 0xA) && ((u8) this->unk90 != 0)) {
                    Hurt((HurtMessage *) &sp1E0);
                }
            }
            goto block_216;
        case 0x16A:
            SetAutoHealthRegen(1U);
            goto block_216;
        case 0x16B:
            SetAutoHealthRegen(0U);
            goto block_216;
        }
    } else {
        temp_r29_11486 = this->unk8 + 0x30;
        M2C_FIELD(checked_cast<GetPosMsg *, MKMessage>(arg0), void **, 8) = temp_r29_11486;
    case 0xA8:
    case 0x1F:
    case 0xD:
    case 0xA:
block_216:
        this->unk54.Message(arg0);
        MKProp::Message(arg0);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Spyro::PlatformUpdate() {
    u8 sp68;
    s32 sp64;
    void *sp60;
    s32 sp5C;
    f32 sp58;
    s32 *sp54;
    s8 sp53;
    s8 sp52;
    s16 sp50;
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
    M2C_UNK sp8;
    MKProp *temp_r3_11737;
    MKProp *temp_r3_11785;
    MKProp *var_r31_11734;
    f32 temp_r0_11765;
    s32 temp_r3_11739;
    s32 temp_r4_11787;
    s32 var_r31_11672;
    u32 var_r3_11719;
    void **temp_r5_11738;
    void *temp_r0_11771;
    void *var_r3_11757;
    void *var_r3_11792;
    void *var_r4_11745;

    if (this->unk428 & 0x100) {
        var_r31_11672 = 2;
loop_2:
        sp18 = 0.0f;
        sp1C = 0.0f;
        sp20 = 0.0f;
        sp28 = 0.0f;
        sp2C = 0.0f;
        sp30 = 0.0f;
        sp38 = 0.0f;
        sp3C = 0.0f;
        sp40 = 0.0f;
        sp44 = 1.0f;
        sp48 = 0.0f;
        sp4C = 0.0f;
        sp50 = 0;
        sp52 = 0;
        sp53 = 0;
        sp54 = NULL;
        sp58 = 3.4028235e38f;
        sp5C = 0;
        sp60 = NULL;
        sp64 = -1;
        sp68 = 0;
        sp8.GetNodePos((s32) this);
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp8), 2000.0f, (MKCollisionResult *) &sp18, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
            if ((sp68 != 0) && (sp60 != NULL) && (var_r3_11719 = M2C_FIELD(sp60, u32 *, 8), ((var_r3_11719 == 0U) == 0))) {

            } else {
                var_r3_11719 = 0U;
            }
            if (var_r3_11719 != M2C_BITWISE(u32, this->unk3E4)) {
                goto block_9;
            }
        } else {
block_9:
            var_r31_11672 += 1;
            if (var_r31_11672 >= 5) {
                var_r31_11734 = NULL;
                if (this->unk428 & 0x20) {
                    temp_r3_11737 = this->unk26C.unk8;
                    temp_r5_11738 = &temp_r3_11737->unk8;
                    temp_r3_11739 = M2C_FIELD(temp_r3_11737, s32 *, 0x16C);
                    if (temp_r3_11739 > 0) {
                        if (temp_r3_11739 != 0) {
                            var_r4_11745 = temp_r5_11738 + ((temp_r3_11739 - 1) * 0x58);
                        } else {
                            var_r4_11745 = NULL;
                        }
                        if ((u32) M2C_FIELD(var_r4_11745, u32 *, 0x48) != 0U) {
                            if (temp_r3_11739 != 0) {
                                var_r3_11757 = temp_r5_11738 + ((temp_r3_11739 - 1) * 0x58);
                            } else {
                                var_r3_11757 = NULL;
                            }
                            var_r31_11734 = M2C_FIELD(M2C_FIELD(var_r3_11757, void **, 0x48), MKProp **, 8);
                        }
                    }
                }
                temp_r0_11765 = this->unk3E4;
                if (((M2C_BITWISE(u32, temp_r0_11765) != 0U) && (var_r31_11734 != M2C_BITWISE(u32, temp_r0_11765))) || ((temp_r0_11771 = this->unk40C, ((temp_r0_11771 == NULL) == 0)) && (var_r31_11734 != temp_r0_11771))) {
                    PlatformDetach();
                }
                if ((var_r31_11734 != NULL) && (var_r31_11734 != M2C_BITWISE(u32, this->unk3E4))) {
                    temp_r3_11785 = this->unk26C.unk8;
                    temp_r4_11787 = M2C_FIELD(temp_r3_11785, s32 *, 0x16C);
                    if (temp_r4_11787 != 0) {
                        var_r3_11792 = &temp_r3_11785->unk8 + ((temp_r4_11787 - 1) * 0x58);
                    } else {
                        var_r3_11792 = NULL;
                    }
                    PlatformAttach(var_r31_11734, M2C_FIELD(var_r3_11792, MKCollisionInfo **, 0x48));
                }
                if (var_r31_11734 == NULL) {
                    PlatformDetach();
                }
            } else {
                goto loop_2;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk418'
void Spyro::PlatformDetach() {
    s32 sp3C;
    s8 sp38;
    M2C_UNK *sp34;
    s32 sp30;
    s32 sp2C;
    s8 sp28;
    s32 *sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_11847;
    KDCamera *temp_r3_11858;
    MKProp *temp_r3_11885;
    f32 temp_r3_11828;
    void *temp_r3_11870;

    temp_r3_11828 = this->unk3E4;
    if (M2C_BITWISE(u32, temp_r3_11828) != 0U) {
        sp30 = 0;
        sp2C = 0x24;
        sp34 = &this->unk418;
        sp38 = 0;
        sp3C = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_11828, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp2C, 0x24, 0);
        this->unk3E4 = 0.0f;
        temp_r3_11847 = GetCamera();
        sp14 = 0;
        sp10 = 0x42D;
        M2C_FIELD(temp_r3_11847->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        temp_r3_11858 = GetCamera();
        spC = 0;
        sp8 = 0x41E;
        M2C_FIELD(temp_r3_11858->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        return;
    }
    temp_r3_11870 = this->unk40C;
    if (temp_r3_11870 != NULL) {
        sp1C = 0;
        sp18 = 0x9A;
        sp20 = &this->unk3E8;
        sp28 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_11870, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp18, 0x9A, 0);
        temp_r3_11885 = this->unk26C.unk8;
        M2C_FIELD(temp_r3_11885, s32 *, 0x468) = (s32) (M2C_FIELD(temp_r3_11885, s32 *, 0x468) | 1);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKProp *' to
void Spyro::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp3C;
    u8 sp38;
    M2C_UNK *sp34;
    s32 sp30;
    s32 sp2C;
    s8 sp28;
    MKCollisionInfo *sp24;
    s32 *sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_11933;
    KDCamera *temp_r3_11944;
    MKProp *temp_r3_11979;
    f32 temp_r3_11913;
    s32 temp_r3_11909;

    PlatformDetach();
    temp_r3_11909 = M2C_FIELD(arg0->unk0, s32 *, 0xC);
    if (temp_r3_11909 & 0x4000) {
        this->unk3E4 = M2C_BITWISE(f32, arg0);
        temp_r3_11913 = this->unk3E4;
        if (M2C_BITWISE(u32, temp_r3_11913) != 0U) {
            sp30 = 0;
            sp2C = 0x23;
            sp34 = &this->unk418;
            sp38 = 0;
            sp3C = arg1;
            M2C_FIELD(M2C_FIELD(temp_r3_11913, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp2C, 0x23, 0);
            if (sp38 != 0) {
                temp_r3_11933 = GetCamera();
                sp14 = 0;
                sp10 = 0x42C;
                M2C_FIELD(temp_r3_11933->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
                temp_r3_11944 = GetCamera();
                spC = 0;
                sp8 = 0x420;
                M2C_FIELD(temp_r3_11944->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                return;
            }
            this->unk3E4 = 0.0f;
        }
    } else if (temp_r3_11909 & 0x20000) {
        sp1C = 0;
        sp18 = 0x99;
        sp20 = &this->unk3E8;
        sp24 = arg1;
        sp28 = 0;
        arg0->Message(&sp18, 0x99, 0);
        M2C_FIELD(this->unk26C.unk8, f32 *, 0x47C) = 50.0f;
        temp_r3_11979 = this->unk26C.unk8;
        M2C_FIELD(temp_r3_11979, s32 *, 0x468) = (s32) (M2C_FIELD(temp_r3_11979, s32 *, 0x468) & 0xFFFFFFFE);
    }
}
#endif

MKProp *Spyro::OnProp() {
    MKProp *temp_r3_11994;
    MKProp *temp_r3_12010;
    s32 temp_r3_11996;
    void *temp_r3_12007;
    void *var_r3_12002;

    temp_r3_11994 = this->unk26C.unk8;
    temp_r3_11996 = M2C_FIELD(temp_r3_11994, s32 *, 0x16C);
    if (temp_r3_11996 > 0) {
        if (temp_r3_11996 != 0) {
            var_r3_12002 = &temp_r3_11994->unk8 + ((temp_r3_11996 - 1) * 0x58);
        } else {
            var_r3_12002 = NULL;
        }
        temp_r3_12007 = M2C_FIELD(var_r3_12002, void **, 0x48);
        if ((temp_r3_12007 == NULL) || (temp_r3_12010 = M2C_FIELD(temp_r3_12007, MKProp **, 8), ((temp_r3_12010 == NULL) != 0))) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return NULL;
        }
        return temp_r3_12010;
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Spyro::Medium'
void Spyro::SetMedium(Spyro::Medium arg1) {
    this->unk7C.SetState(this, (s32) arg1, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk340'
s8 Spyro::Hurt(HurtMessage *arg0) {
    SpyroStateMessages spB0;
    SpyroStateMessages sp5C;
    SpyroStateMessages sp8;
    s32 temp_r0_12094;
    u32 temp_r3_12136;
    u8 temp_r29_12055;
    u8 var_r3_12057;

    if ((s32) gb.unk340 != 0) {
        return 0;
    }
    temp_r29_12055 = arg0->unk40;
    if (this->unk428 & 0x4000) {
        var_r3_12057 = 0;
    } else {
        var_r3_12057 = DealDamage(arg0->unk48, 1U, arg0->unk41, arg0);
    }
    if (((this->unk428 & 0x4000) && ((u8) arg0->unk51 == 0)) || ((s32) this->unk54.unk8 == 0xA) || ((var_r3_12057 == 0) && (temp_r29_12055 == 0)) || ((var_r3_12057 == 0) && ((u8) arg0->unk42 != 0))) {
        return 0;
    }
    if (GetInput() != &this->unk204.unkC) {
        temp_r0_12094 = arg0->unk4C;
        switch (temp_r0_12094) {                    /* irregular */
        case 1:
            ((KDInput *) (GetInput()))->RumblePlay(0.1f, 0.1f, 0.17f, 0, 4.0f, 0U);
            break;
        case 2:
            ((KDInput *) (GetInput()))->RumblePlay(0.2f, 0.5f, 0.17f, 0, 4.0f, 0U);
            break;
        }
    }
    if (arg0->unk48 > 0.0f) {
        M2C_FIELD(this, f32 *, 0x248) = 0.5f;
    }
    if ((M2C_FIELD(&gameData, f32 *, 0x70) > 0.0f) && (temp_r3_12136 = arg0->unk28, ((temp_r3_12136 == 8) == 0)) && (temp_r3_12136 != 9) && ((u8) arg0->unk51 == 0)) {
        if (temp_r3_12136 != 0) {
            spB0.unk50 = 0;
            spB0.AddMessage((MKMessage *) arg0);
            if ((s32) this->unk54.unk8 == 2) {
                spB0.AddMessage(0x178);
            }
            this->unk54.SetState(9, spB0);
        }
    } else if ((u32) arg0->unk28 == 8) {
        sp5C.unk50 = 0;
        sp5C.AddMessage((MKMessage *) arg0);
        this->unk54.SetState(9, sp5C);
    } else {
        sp8.unk50 = 0;
        if ((s32) this->unk54.unk8 == 2) {
            sp8.AddMessage(0x178);
        }
        this->unk54.SetState(0xA, sp8);
    }
    return 1;
}
#endif

#if 0 // DRAFT: illegal type
u8 Spyro::DealDamage(float arg0, bool arg1, bool arg2, HurtMessage *arg3) {
    HitHeroSndMsg sp10;
    s32 spC;
    s32 sp8;
    f32 var_f31_12210;
    s32 temp_r3_12259;
    s32 temp_r3_12271;
    u8 var_r3_12284;
    void *temp_r3_12221;
    void *temp_r3_12236;

    var_f31_12210 = arg0;
    if (var_f31_12210 == 0.0f) {
        return 1U;
    }
    temp_r3_12221 = arg3->unk2C;
    if (temp_r3_12221 != NULL) {
        spC = 0;
        sp8 = 0x7B;
        M2C_FIELD(M2C_FIELD(temp_r3_12221, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    sp10.HitHeroSndMsg();
    temp_r3_12236 = arg3->unk2C;
    if ((temp_r3_12236 != NULL) && (temp_r3_12236 != this)) {
        M2C_FIELD(M2C_FIELD(temp_r3_12236, void **, 0x44), M2C_UNK (**)(HitHeroSndMsg *), 0x2C)(&sp10);
        if (sp10.unk8 > (s32) GS_PLACEHOLDER) {
            KDSound_Play3d(sp10.unk8, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        } else {
            temp_r3_12259 = arg3->unk44;
            if (temp_r3_12259 > (s32) GS_PLACEHOLDER) {
                KDSound_Play3d(temp_r3_12259, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    } else {
        temp_r3_12271 = arg3->unk44;
        if (temp_r3_12271 > (s32) GS_PLACEHOLDER) {
            KDSound_Play3d(temp_r3_12271, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        }
    }
    var_r3_12284 = 0;
    if ((this->unk428 & 0x80) && ((u8) this->unk1C4 == 0)) {
        var_r3_12284 = 1;
    }
    if (var_r3_12284 == 0) {
        return 0U;
    }
    if ((IsInvincible() != 0) && (arg2 == 0)) {
        return 0U;
    }
    if ((u8) M2C_FIELD(&gb, u8 *, 0x3B4) != 0) {
        if (arg1 != 0) {
            SetInvincibilityTimeOut(gb.unk390);
        }
        var_f31_12210 = 0.0f;
    }
    gameData.unk70.Add(-var_f31_12210, 1U);
    this->unk3DC = 2.0f;
    this->unkB74 = gb.unk30C;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if ((gb.unk30C == M2C_FIELD(this, f32 *, 0x3DC)) && (arg1 != 0) && ((M2C_FIELD(&gameData, f32 *, 0x70) / gameData.unk74) > 0.0f)) {
        SetInvincibilityTimeOut(gb.unk390);
    }
    return 1U;
}
#endif

void Spyro::UpdateCheats() {

}

void Spyro::SetPos(const MKVector3 &arg0) {
    MKModel_SetPosition(this->unk4, arg0);
}

#if 0 // DRAFT: undefined identifier 'zero'
void Spyro::UpdateLastSafePos() {
    MKCollisionResult sp308;
    MKCollisionResult sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    SafePosInfo sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    M2C_UNK sp200;
    M2C_UNK sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    M2C_UNK sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
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
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    u8 sp18;
    void ***sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_12418;
    MKProp *temp_r4_12524;
    MKProp *var_r5_12669;
    MKProp *var_r5_12984;
    f32 temp_r3_12666;
    f32 temp_r3_12753;
    f64 temp_f0_12556;
    f64 temp_f1_12555;
    s32 temp_r0_12752;
    s32 temp_r0_12763;
    s32 temp_r0_12769;
    s32 temp_r3_12577;
    s32 temp_r4_12420;
    s32 temp_r4_12456;
    s32 temp_r4_12573;
    s32 temp_r5_12451;
    s32 var_r26_12908;
    s32 var_r28_12906;
    s32 var_r4_12442;
    u8 var_r30_12392;
    u8 var_r30_12938;
    void ***temp_r4_12393;
    void *temp_r3_12455;
    void *temp_r3_12553;
    void *temp_r4_12540;
    void *temp_r4_12704;
    void *temp_r4_12772;
    void *temp_r4_12814;
    void *temp_r6_12507;
    void *var_r3_12437;
    void *var_r3_12696;

    var_r30_12392 = 0;
    temp_r4_12393 = &this->unk264;
    sp280 = M2C_FIELD(&zero, f64 *, 0);
    sp288 = M2C_FIELD(&zero, f64 *, 8);
    sp14 = temp_r4_12393;
    if (temp_r4_12393 != NULL) {
        sp18 = (u8) this->unk268;
        this->unk268 = 0;
    }
    if (M2C_FIELD(this, f32 *, 0x298) < 30.000002f) {
        sp10 = 0.0f;
        if ((this->unk7C.GetState() == 1) && (this->unk428 & 0x8000)) {
            temp_r3_12418 = this->unk26C.unk8;
            temp_r4_12420 = M2C_FIELD(temp_r3_12418, s32 *, 0x16C);
            if ((temp_r4_12420 > 0) && ((s32) M2C_FIELD(temp_r3_12418, s32 *, 0x2D4) <= 0) && ((s32) M2C_FIELD(temp_r3_12418, s32 *, 0x43C) <= 0) && ((u8) M2C_FIELD(this, u8 *, 0x394) == 0)) {
                if (temp_r4_12420 > 0) {
                    if (temp_r4_12420 != 0) {
                        var_r3_12437 = &temp_r3_12418->unk8 + ((temp_r4_12420 - 1) * 0x58);
                    } else {
                        var_r3_12437 = NULL;
                    }
                    var_r4_12442 = M2C_FIELD(var_r3_12437, s32 *, 0x44);
                } else {
                    var_r4_12442 = 0;
                }
                if (!(var_r4_12442 & 0x10000183)) {
                    temp_r5_12451 = this->unk35C;
                    if (temp_r5_12451 != 0) {
                        if (temp_r5_12451 > 0) {
                            temp_r3_12455 = this->unk8;
                            temp_r4_12456 = temp_r5_12451 - 1;
                            sp240 = M2C_FIELD(temp_r3_12455, f64 *, 0x30);
                            sp248 = M2C_FIELD(temp_r3_12455, f64 *, 0x38);
                            if ((temp_r4_12456 < 0) || (temp_r4_12456 >= temp_r5_12451)) {

                            } else if ((s32) (this->unk358 + temp_r4_12456) >= M2C_BITWISE(s32, this->unk350)) {

                            }
                            sp250.GetPos();
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            sp120 = sp50;
                            sp58 = (f32) sp250.unk8 - (f32) sp248;
                            sp128 = (f64) sp58;
                            sp130 = sp50;
                            sp138 = (f64) sp58;
                            if (!((((f32) sp128 * (f32) sp128) + (((f32) sp120 * (f32) sp120) + (unksp124 * unksp124))) < 10000.0f)) {
                                goto block_25;
                            }
                        }
                    } else {
block_25:
                        temp_r6_12507 = this->unk8;
                        sp230 = M2C_FIELD(temp_r6_12507, f64 *, 0x30);
                        sp238 = M2C_FIELD(temp_r6_12507, f64 *, 0x38);
                        if ((sp230.IsWithin(*NULL, &sp10, (s32 *) temp_r6_12507) == 0) || ((M2C_BITWISE(s32, sp10) != 1) && (M2C_BITWISE(s32, sp10) != 4))) {
                            temp_r4_12524 = this->unk26C.unk8;
                            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                            if (((temp_r4_12524->unk20 * up.unk8) + ((M2C_BITWISE(f32, temp_r4_12524->unk18) * up.unk0) + (M2C_FIELD(temp_r4_12524, f32 *, 0x1C) * up.unk4))) == maxStandAngle) {
                                temp_r4_12540 = this->unk8;
                                sp220 = M2C_FIELD(temp_r4_12540, f64 *, 0x30);
                                sp228 = M2C_FIELD(temp_r4_12540, f64 *, 0x38);
                                SetLastSafePos(*((MKVector3 *) &sp220), OnProp());
                            } else {
                                temp_r3_12553 = this->unk8;
                                var_r30_12392 = 1;
                                temp_f1_12555 = M2C_FIELD(temp_r3_12553, f64 *, 0x30);
                                temp_f0_12556 = M2C_FIELD(temp_r3_12553, f64 *, 0x38);
                                sp210 = temp_f1_12555;
                                sp218 = temp_f0_12556;
                                sp280 = temp_f1_12555;
                                sp288 = temp_f0_12556;
                            }
                        }
                    }
                }
            }
        }
    } else {
        spC = 0.0f;
        if ((this->unk428 & 0x8000) && !(this->unk2DC & 0x10000183)) {
            temp_r4_12573 = this->unk35C;
            if (temp_r4_12573 != 0) {
                if (temp_r4_12573 > 0) {
                    temp_r3_12577 = temp_r4_12573 - 1;
                    if ((temp_r3_12577 < 0) || (temp_r3_12577 >= temp_r4_12573)) {

                    } else if ((s32) (this->unk358 + temp_r3_12577) >= M2C_BITWISE(s32, this->unk350)) {

                    }
                    sp200.GetPos();
                    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    sp100 = sp40;
                    sp48 = sp208 - this->unk2A0;
                    sp108 = (f64) sp48;
                    sp110 = sp40;
                    sp118 = (f64) sp48;
                    if (!((((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (unksp104 * unksp104))) < 10000.0f)) {
                        goto block_42;
                    }
                }
            } else {
block_42:
                if (((this->unk298.IsWithin(*NULL, &spC, M2C_ERROR(/* Read from unset register $r6 */)) == 0) || ((M2C_BITWISE(s32, spC) != 1) && (M2C_BITWISE(s32, spC) != 4))) && ((u8) (MKCollision_SphereCollide(*((MKVector3 *) &this->unk298), 400.0f, NULL, 1, (MKCollisionMode) 7, -0x10000184) == 0) != 0)) {
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (((this->unk2B0 * up.unk8) + ((this->unk2A8 * up.unk0) + (this->unk2B4 * up.unk4))) == maxStandAngle) {
                        if (((u8) M2C_FIELD(this, u8 *, 0x2F0) != 0) && (temp_r3_12666 = this->unk2E0, ((M2C_BITWISE(u32, temp_r3_12666) == 0U) == 0)) && (var_r5_12669 = M2C_FIELD(temp_r3_12666, MKProp **, 8), ((var_r5_12669 == NULL) == 0))) {

                        } else {
                            var_r5_12669 = NULL;
                        }
                        SetLastSafePos(*((MKVector3 *) &this->unk298), var_r5_12669);
                    } else {
                        var_r30_12392 = 1;
                        sp280 = M2C_FIELD(this, f64 *, 0x2A0);
                        sp288 = (f64) M2C_FIELD(this, f32 *, 0x2A8);
                    }
                }
            }
        }
    }
loop_67:
    temp_r0_12763 = this->unk35C;
    if (temp_r0_12763 > 1) {
        if (temp_r0_12763 > 0) {
            var_r3_12696 = this->unk35C + (this->unk358 * 0x18);
        } else {
            var_r3_12696 = NULL;
        }
        if ((u32) M2C_FIELD(var_r3_12696, u32 *, 0x10) == 0U) {
            temp_r4_12704 = this->unk8;
            sp1E0 = M2C_FIELD(temp_r4_12704, f64 *, 0x30);
            sp1E8 = M2C_FIELD(temp_r4_12704, f64 *, 0x38);
            if ((s32) this->unk35C > 0) {

            }
            sp1F0.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spE0 = sp30;
            sp38 = sp1F8 - (f32) sp1E8;
            spE8 = (f64) sp38;
            spF0 = sp30;
            spF8 = (f64) sp38;
            if (!((((f32) spE8 * (f32) spE8) + (((f32) spE0 * (f32) spE0) + (unkspE4 * unkspE4))) < 1000000.0f)) {
                if ((s32) this->unk35C > 0) {
                    this->unk358 += 1;
                    temp_r0_12752 = this->unk358;
                    temp_r3_12753 = this->unk350;
                    if (temp_r0_12752 >= M2C_BITWISE(s32, temp_r3_12753)) {
                        this->unk358 = temp_r0_12752 - M2C_BITWISE(s32, temp_r3_12753);
                    }
                    this->unk35C -= 1;
                }
                goto loop_67;
            }
        }
    }
    if (var_r30_12392 != 0) {
        temp_r0_12769 = this->unk35C;
        if (temp_r0_12769 == 1) {
            temp_r4_12772 = this->unk8;
            sp1C0 = M2C_FIELD(temp_r4_12772, f64 *, 0x30);
            sp1C8 = M2C_FIELD(temp_r4_12772, f64 *, 0x38);
            if (temp_r0_12769 > 0) {

            }
            sp1D0.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            spC0 = sp20;
            sp28 = sp1D8 - (f32) sp1C8;
            spC8 = (f64) sp28;
            spD0 = sp20;
            spD8 = (f64) sp28;
            if (!((((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + (unkspC4 * unkspC4))) < 1000000.0f)) {
                temp_r4_12814 = this->unk8;
                spA8 = 0.0f;
                sp80 = -M2C_FIELD(temp_r4_12814, f32 *, 0x20);
                sp84 = -M2C_FIELD(temp_r4_12814, f32 *, 0x24);
                sp88 = -M2C_FIELD(temp_r4_12814, f32 *, 0x28);
                sp1B0 = (f64) sp80;
                sp1B8 = (f64) sp88;
                spA0 = 0.0f;
                spA4 = 100.0f;
                spB0 = (up.unk4 * (f32) sp1B8) - (up.unk8 * unksp1B4);
                spB4 = (up.unk8 * (f32) sp1B0) - (up.unk0 * (f32) sp1B8);
                spB8 = (up.unk0 * unksp1B4) - (up.unk4 * (f32) sp1B0);
                sp1A0 = (f64) spA0;
                sp270 = (f64) spB0;
                sp278 = (f64) spB8;
                sp1A8 = (f64) spA8;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f2, $f0 */);
                sp250.unk10 = sp90;
                sp98 = (f32) sp288 + (f32) sp1A8;
                sp268 = (f64) sp98;
                sp170.operator*(100.0f);
                sp180.operator*(2.0f);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                sp290 = sp70;
                sp78 = (f32) sp288 + sp180.unk8;
                sp190 = sp70;
                sp198 = (f64) sp78;
                sp298 = (f64) sp78;
                unksp294 -= 200.0f;
                sp140.operator*(100.0f);
                sp150.operator*(2.0f);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                var_r28_12906 = 0;
                var_r26_12908 = 0;
                sp2A0 = sp60;
                sp68 = (f32) sp288 - sp150.unk8;
                sp160 = sp60;
                sp168 = (f64) sp68;
                sp2A8 = (f64) sp68;
                unksp2A4 -= 200.0f;
                sp8 = 0.0f;
loop_75:
                if (MKCollision_RayCollide(*((MKVector3 *) &sp250.unk10), sp290 + var_r28_12906, &sp308, (MKCollisionMode) 7, -0x10000184) != 0) {
                    var_r30_12938 = 0;
                    if ((MKCollision_SphereCollide(*((MKVector3 *) &sp308), 100.0f, &sp2B0, 1, (MKCollisionMode) 7, -0x10000184) == 0) || ((u32) sp2B0.unk44 == 0U)) {
                        var_r30_12938 = 1;
                    }
                    if ((var_r30_12938 != 0) && (M2C_ERROR(/* unknown instruction: cror eq, gt, eq */), ((((sp308.unk18 * up.unk8) + ((sp308.unk10 * up.unk0) + (sp308.unk14 * up.unk4))) == maxStandAngle) != 0)) && ((sp308.IsWithin(*NULL, &sp8, M2C_ERROR(/* Read from unset register $r6 */)) == 0) || ((M2C_BITWISE(s32, sp8) != 1) && (M2C_BITWISE(s32, sp8) != 4)))) {
                        if ((sp308.unk50 != 0) && (sp308.unk48 != NULL) && (var_r5_12984 = M2C_FIELD(sp308.unk48, MKProp **, 8), ((var_r5_12984 == NULL) == 0))) {

                        } else {
                            var_r5_12984 = NULL;
                        }
                        SetLastSafePos(*((MKVector3 *) &sp308), var_r5_12984);
                    } else {
                        goto block_90;
                    }
                } else {
block_90:
                    var_r26_12908 += 1;
                    var_r28_12906 += 0x10;
                    if (var_r26_12908 < 2) {
                        goto loop_75;
                    }
                }
            }
        }
    }
    if (sp14 != NULL) {
        M2C_FIELD(sp14, u8 *, 4) = sp18;
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void Spyro::GetLastSafePos() {
    if ((s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 0x35C) > 0) {

    }
    SafePosInfo::GetPos();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void *Spyro::LastSafePosAvailable() {
    s32 temp_r0_13046;

    temp_r0_13046 = this->unk35C;
    if (temp_r0_13046 == 0) {
        return NULL;
    }
    if (temp_r0_13046 > 0) {
        return this->unk35C + (this->unk358 * 0x18);
    }
    return NULL;
}
#endif

void Spyro::UpdateShockwavePosition() {

}

#if 0 // DRAFT: undefined identifier 'sp8'
void Spyro::ModelOffsetPostUpdate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f1_13089;

    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f1_13089 = M2C_FIELD((MKModel_GetWorldMatrix(this->unk4) + 0x30), f32 *, 8) + M2C_FIELD(this, f32 *, 0x370);
    sp18 = sp8;
    sp10 = temp_f1_13089;
    sp20 = (f64) sp10;
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp18));
    MKModel_GetAnimation(this->unk4);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKProp **' to
void Spyro::ModelOffsetPreUpdate() {
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_13183;
    u8 var_r0_13111;

    var_r0_13111 = 0;
    if ((M2C_FIELD(this, f32 *, 0x378) == M2C_BITWISE(f32, this->unk360)) && (M2C_FIELD(this, f32 *, 0x37C) == M2C_BITWISE(f32, this->unk364)) && (M2C_FIELD(this, f32 *, 0x380) == M2C_FIELD(this, f32 *, 0x370))) {
        var_r0_13111 = 1;
    }
    if (var_r0_13111 == 0) {
        KDMath_Smooth<MKVector3>(sp58, *((MKVector3 *) &this->unk360), 5.0f, gUpdateTimeDelta);
        M2C_FIELD(this, s32 *, 0x368) = M2C_BITWISE(f64, sp58);
        this->unk368 = (f64) sp58.unk8;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp28 = sp8;
        sp10 = M2C_FIELD(this, f32 *, 0x370) - M2C_FIELD(this, f32 *, 0x380);
        sp30 = (f64) sp10;
        sp38 = sp8;
        sp40 = (f64) sp10;
        if ((((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + (unksp2C * unksp2C))) < 1.0f) {
            M2C_FIELD(this, s32 *, 0x368) = (f64) this->unk370;
            this->unk368 = this->unk378;
        }
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    temp_f1_13183 = M2C_FIELD((MKModel_GetWorldMatrix(this->unk4) + 0x30), f32 *, 8) - M2C_FIELD(this, f32 *, 0x370);
    sp48 = sp18;
    sp20 = temp_f1_13183;
    sp50 = (f64) sp20;
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp48));
}
#endif

void Spyro::SetModelVisualOffset(const MKVector3 &arg0, bool arg1) {
    this->unk370 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk378 = M2C_FIELD(&arg0, f64 *, 8);
    if (arg1 != 0) {
        M2C_FIELD(this, f64 *, 0x368) = (f64) this->unk370;
        this->unk368 = this->unk378;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Spyro::ApplyEdgePhysics(MKVector3 arg0) {
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    s32 temp_r0_13305;
    void *temp_r31_13303;
    void *temp_r3_13304;

    temp_r31_13303 = M2C_ERROR(/* Read from unset register $r5 */);
    temp_r3_13304 = M2C_FIELD(arg0, void **, 0x27C);
    temp_r0_13305 = M2C_FIELD(temp_r3_13304, s32 *, 0x16C);
    if (((temp_r0_13305 > 0) && (temp_r0_13305 >= 2)) || ((temp_r0_13305 > 0) && ((s32) M2C_FIELD(temp_r3_13304, s32 *, 0x2D4) > 0))) {
        M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r31_13303, f64 *, 0);
        M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r31_13303, f64 *, 8);
        return;
    }
    ClampMagnitude(sp38, 100.0f);
    M2C_FIELD(temp_r31_13303, f64 *, 0) = M2C_BITWISE(f64, sp38);
    M2C_FIELD(temp_r31_13303, f64 *, 8) = (f64) sp38.unk8;
    Tools_GetGradient(sp28);
    sp48 = M2C_BITWISE(f64, sp28);
    sp50 = (f64) sp28.unk8;
    __ml(-5000.0f * (((f32) sp50 * up.unk8) + (((f32) sp48 * up.unk0) + (unksp4C * up.unk4))), sp18);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = sp8;
    sp10 = (f32) M2C_FIELD(temp_r31_13303, f64 *, 8) + sp18.unk8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'ClampMagnitude'
void Spyro::ApplyIcePhysics(MKVector3 arg0) {
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    void *temp_r31_13383;

    temp_r31_13383 = M2C_ERROR(/* Read from unset register $r5 */);
    ClampMagnitude(sp38, 1000.0f);
    M2C_FIELD(temp_r31_13383, f64 *, 0) = M2C_BITWISE(f64, sp38);
    M2C_FIELD(temp_r31_13383, f64 *, 8) = (f64) sp38.unk8;
    Tools_GetGradient(sp28);
    sp48 = M2C_BITWISE(f64, sp28);
    sp50 = (f64) sp28.unk8;
    __ml(-5000.0f * (((f32) sp50 * up.unk8) + (((f32) sp48 * up.unk0) + (unksp4C * up.unk4))), sp18);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = sp8;
    sp10 = (f32) M2C_FIELD(temp_r31_13383, f64 *, 8) + sp18.unk8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Spyro::ApplySlipperyPhysics(MKVector3 arg0) {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f3_13467;
    f32 var_f7_13465;
    f64 temp_f6_13453;
    s32 temp_r3_13479;
    void *temp_r31_13449;
    void *temp_r3_13477;
    void *var_r3_13485;

    temp_r31_13449 = M2C_ERROR(/* Read from unset register $r5 */);
    Tools_GetGradient(sp68);
    temp_f6_13453 = M2C_BITWISE(f64, sp68);
    sp98 = temp_f6_13453;
    spA0 = (f64) sp68.unk8;
    var_f7_13465 = 0.0f;
    sp88 = temp_f6_13453;
    temp_f3_13467 = ((f32) spA0 * M2C_FIELD(temp_r31_13449, f32 *, 8)) + (((f32) sp98 * M2C_FIELD(temp_r31_13449, f32 *, 0)) + (unksp9C * M2C_FIELD(temp_r31_13449, f32 *, 4)));
    sp90 = (f64) sp68.unk8;
    unksp8C = 0.0f;
    if (var_f7_13465 < temp_f3_13467) {

    } else {
        var_f7_13465 = temp_f3_13467;
    }
    temp_r3_13477 = M2C_FIELD(arg0, void **, 0x27C);
    temp_r3_13479 = M2C_FIELD(temp_r3_13477, s32 *, 0x2D4);
    if (temp_r3_13479 > 0) {
        if (temp_r3_13479 != 0) {
            var_r3_13485 = temp_r3_13477 + 0x170 + ((temp_r3_13479 - 1) * 0x58);
        } else {
            var_r3_13485 = NULL;
        }
        if (!(((M2C_FIELD(var_r3_13485, f32 *, 0x18) * (f32) sp90) + ((M2C_FIELD(var_r3_13485, f32 *, 0x10) * (f32) sp88) + (M2C_FIELD(var_r3_13485, f32 *, 0x14) * unksp8C))) < -0.85f)) {
            goto block_8;
        }
    } else {
block_8:
        M2C_ERROR(/* unknown instruction: ps_muls0 $f2, $f2, $f29 */);
        sp10 = (f32) spA0 * -var_f7_13465;
        sp58 = sp8;
        sp60 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f2, $f3, $f2 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f2, $zero, $r31, 0x0, qr0 */);
        M2C_FIELD(temp_r31_13449, f32 *, 8) = (f32) (M2C_FIELD(temp_r31_13449, f32 *, 8) + (f32) sp60);
    }
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f30 */);
    sp40 = (f32) spA0 * 2500.0f;
    sp48 = sp38;
    sp50 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp78 = sp28;
    sp30 = (f32) sp50 * -(((f32) spA0 * up.unk8) + (((f32) sp98 * up.unk0) + (unksp9C * up.unk4)));
    sp80 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_FIELD(this, f64 *, 0) = sp18;
    sp20 = M2C_FIELD(temp_r31_13449, f32 *, 8) + (f32) sp80;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Spyro::ApplyPhysics(MKVector3 arg0) {
    MKVector3 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    s32 temp_r3_13591;
    s32 temp_r3_13654;
    s32 temp_r5_13620;
    s32 var_r0_13635;
    s32 var_r0_13664;
    void *temp_r31_13588;
    void *temp_r3_13619;
    void *temp_r3_13686;
    void *temp_r4_13621;
    void *var_r3_13630;
    void *var_r3_13659;

    temp_r31_13588 = M2C_ERROR(/* Read from unset register $r5 */);
    temp_r3_13591 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x27C), s32 *, 0x16C);
    if ((temp_r3_13591 > 0) && (M2C_FIELD(arg0, s32 *, 0x428) & 0x20)) {
        if (temp_r3_13591 != 0) {

        }
        KDMath_Smooth<MKVector3>(sp88, *((s32) arg0 + 0x328), 6.0f, gUpdateTimeDelta);
        Normalise(sp98);
        M2C_FIELD(arg0, f64 *, 0x328) = M2C_BITWISE(f64, sp98);
        M2C_FIELD(arg0, f64 *, 0x330) = (f64) sp98.unk8;
        temp_r3_13619 = M2C_FIELD(arg0, void **, 0x27C);
        temp_r5_13620 = M2C_FIELD(temp_r3_13619, s32 *, 0x16C);
        temp_r4_13621 = temp_r3_13619 + 8;
        if (((u32) (-temp_r5_13620 & ~temp_r5_13620) >> 0x1FU) != 0) {
            if (temp_r5_13620 != 0) {
                var_r3_13630 = temp_r4_13621 + ((temp_r5_13620 - 1) * 0x58);
            } else {
                var_r3_13630 = NULL;
            }
            var_r0_13635 = M2C_FIELD(var_r3_13630, s32 *, 0x44);
        } else {
            var_r0_13635 = 0;
        }
        if (var_r0_13635 & 2) {
            sp78 = M2C_FIELD(temp_r31_13588, f64 *, 0);
            sp80 = M2C_FIELD(temp_r31_13588, f64 *, 8);
            ApplySlipperyPhysics(arg0);
            return;
        }
        if (temp_r5_13620 > 0) {
            temp_r3_13654 = M2C_FIELD(temp_r4_13621, s32 *, 0x164);
            if (temp_r3_13654 != 0) {
                var_r3_13659 = temp_r4_13621 + ((temp_r3_13654 - 1) * 0x58);
            } else {
                var_r3_13659 = NULL;
            }
            var_r0_13664 = M2C_FIELD(var_r3_13659, s32 *, 0x44);
        } else {
            var_r0_13664 = 0;
        }
        if (var_r0_13664 & 8) {
            sp68 = M2C_FIELD(temp_r31_13588, f64 *, 0);
            sp70 = M2C_FIELD(temp_r31_13588, f64 *, 8);
            ApplyIcePhysics(arg0);
            return;
        }
        if (M2C_FIELD(arg0, f32 *, 0x298) > 20.0f) {
            temp_r3_13686 = M2C_FIELD(arg0, void **, 8);
            sp18 = 0.0f;
            sp1C = 20.0f;
            sp20 = 0.0f;
            sp38 = (f64) sp18;
            sp48 = M2C_FIELD(temp_r3_13686, f64 *, 0x30);
            sp40 = (f64) sp20;
            sp50 = M2C_FIELD(temp_r3_13686, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp58 = sp8;
            sp10 = (f32) sp50 - (f32) sp40;
            sp60 = (f64) sp10;
            if (MKCollision_SphereCollide(*((MKVector3 *) &sp58), 10.0f, NULL, 0, (MKCollisionMode) 7, 1) == 0) {
                sp28 = M2C_FIELD(temp_r31_13588, f64 *, 0);
                sp30 = M2C_FIELD(temp_r31_13588, f64 *, 8);
                ApplyEdgePhysics(arg0);
                return;
            }
        }
        goto block_24;
    }
block_24:
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r31_13588, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r31_13588, f64 *, 8);
}
#endif

#if 0 // DRAFT: undefined identifier 'zero'
void Spyro::ClipVelToEdge(const MKVector3 &arg0) {
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
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    s32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r31_13750;
    f32 temp_f0_13754;
    f32 temp_f1_13752;
    f32 temp_f2_13759;
    f32 temp_f31_13922;
    f32 temp_f3_13917;
    f32 temp_r3_13838;
    f32 var_f4_13766;
    f32 var_f6_13833;
    f64 temp_f1_13772;
    f64 temp_f1_13778;
    f64 temp_f1_13782;
    s32 temp_r3_13801;
    s32 var_r0_13811;
    u8 var_r0_13898;

    temp_r31_13750 = M2C_ERROR(/* Read from unset register $r5 */);
    temp_f1_13752 = temp_r31_13750->unk0;
    temp_f0_13754 = temp_r31_13750->unk4;
    temp_f2_13759 = temp_r31_13750->unk8;
    sp88 = M2C_FIELD(&zero, f64 *, 0);
    sp90 = M2C_FIELD(&zero, f64 *, 8);
    var_f4_13766 = (temp_f2_13759 * temp_f2_13759) + ((temp_f1_13752 * temp_f1_13752) + (temp_f0_13754 * temp_f0_13754));
    if (var_f4_13766 > 1e-12f) {
        if (var_f4_13766 > 0.0f) {
            temp_f1_13772 = __frsqrte(var_f4_13766);
            temp_f1_13778 = 0.5 * temp_f1_13772 * -(((f64) var_f4_13766 * (temp_f1_13772 * temp_f1_13772)) - 3.0);
            temp_f1_13782 = 0.5 * temp_f1_13778 * -(((f64) var_f4_13766 * (temp_f1_13778 * temp_f1_13778)) - 3.0);
            var_f4_13766 = (f32) ((f64) var_f4_13766 * (0.5 * temp_f1_13782 * -(((f64) var_f4_13766 * (temp_f1_13782 * temp_f1_13782)) - 3.0)));
        } else if (var_f4_13766 < M2C_BITWISE(f32, 0.0)) {
            var_f4_13766 = __float_nan;
        } else {
            sp8 = var_f4_13766;
            temp_r3_13801 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_13801) {                /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_13811 = 1;
                } else {
                    var_r0_13811 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_13811 = 5;
                } else {
                    var_r0_13811 = 3;
                }
                break;
            default:
                var_r0_13811 = 4;
                break;
            }
            if (var_r0_13811 == 1) {
                var_f4_13766 = __float_nan;
            }
        }
        var_f6_13833 = 1.0f / var_f4_13766;
    } else {
        var_f6_13833 = 0.0f;
    }
    temp_r3_13838 = arg0.unk8;
    sp48 = temp_r31_13750->unk0 * var_f6_13833;
    sp4C = temp_r31_13750->unk4 * var_f6_13833;
    sp38 = -M2C_FIELD(temp_r3_13838, f32 *, 0x20);
    sp68 = (f64) sp48;
    sp3C = -M2C_FIELD(temp_r3_13838, f32 *, 0x24);
    sp50 = temp_r31_13750->unk8 * var_f6_13833;
    sp78 = (f64) sp38;
    sp40 = -M2C_FIELD(temp_r3_13838, f32 *, 0x28);
    sp70 = (f64) sp50;
    sp80 = (f64) sp40;
    if ((((f32) sp80 * (f32) sp70) + (((f32) sp78 * (f32) sp68) + (unksp7C * unksp6C))) < 0.9f) {
        arg0.CheckForEdge(KDMath_GetYaw(*temp_r31_13750), zero, 0U, (MKVector3 *) &sp88);
    } else if ((u8) M2C_FIELD(&arg0, u8 *, 0x394) != 0) {
        sp88 = M2C_FIELD(&arg0, f64 *, 0x398);
        sp90 = M2C_FIELD(&arg0, f64 *, 0x3A0);
    }
    var_r0_13898 = 0;
    if (((f32) sp88 == zero.unk0) && (unksp8C == zero.unk4) && ((f32) sp90 == zero.unk8)) {
        var_r0_13898 = 1;
    }
    if (var_r0_13898 == 0) {
        temp_f3_13917 = temp_r31_13750->unk8;
        temp_f31_13922 = -((temp_f3_13917 * (f32) sp90) + ((temp_r31_13750->unk0 * (f32) sp88) + (temp_r31_13750->unk4 * unksp8C)));
        spC = temp_f31_13922;
        sp10 = (M2C_BITWISE(s32, spC) & 0x80000000) | 0x3F800000;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        sp20 = (f32) sp90 * ((0.05f * M2C_BITWISE(f32, sp10)) + temp_f31_13922);
        sp58 = sp18;
        sp60 = (f64) sp20;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(this, f64 *, 0) = sp28;
        sp30 = temp_f3_13917 + (f32) sp60;
        M2C_FIELD(this, f64 *, 8) = (f64) sp30;
        return;
    }
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r31_13750, f32 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r31_13750, f32 *, 8);
}
#endif

void Spyro::CheckForEdge() {
    f32 *temp_r4_13975;

    GetYaw();
    temp_r4_13975 = &this->unk390;
    M2C_FIELD(this, u8 *, 0x394) = CheckForEdge(M2C_ERROR(/* Read from unset register $f1 */), *((MKVector3 *) temp_r4_13975), 1U, (MKVector3 *) temp_r4_13975);
}

#if 0 // DRAFT: undefined identifier 'zero'
u8 Spyro::CheckForEdge(float arg0, const MKVector3 &arg1, bool arg2, MKVector3 *arg3) {
    MKCollisionResult sp108;
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;                                       /* compiler-managed */
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
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
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
    f32 temp_f1_14073;
    f32 temp_f23_14055;
    f32 temp_f23_14071;
    f64 temp_f4_14044;
    f64 temp_f5_14042;
    s32 var_r26_14030;
    u8 var_r0_14179;
    u8 var_r27_14023;
    void *temp_r3_14039;
    void *temp_r3_14137;

    spF8 = M2C_FIELD(&zero, f64 *, 0);
    var_r27_14023 = 0;
    sp100 = M2C_FIELD(&zero, f64 *, 8);
    if ((s32) M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) > 0) {
        var_r26_14030 = 0;
        do {
            temp_r3_14039 = this->unk8;
            temp_f5_14042 = M2C_FIELD(temp_r3_14039, f64 *, 0x30);
            temp_f4_14044 = M2C_FIELD(temp_r3_14039, f64 *, 0x38);
            spA8 = temp_f5_14042;
            spA0 = temp_f4_14044;
            spB8 = temp_f5_14042;
            temp_f23_14055 = arg0 + ((0.3125f * (f32) var_r26_14030) + -0.625f);
            sp40 = (f32) spA0;
            sp38 = (f32) spB8;
            sp3C = 50.0f + unkspAC;
            sp98 = temp_f5_14042;
            spB0 = temp_f4_14044;
            spC0 = temp_f4_14044;
            spE8 = (f64) sp38;
            spF0 = (f64) sp40;
            spD8 = temp_f5_14042;
            spE0 = temp_f4_14044;
            temp_f23_14071 = _table_sinf(temp_f23_14055 - 1.5707964f);
            temp_f1_14073 = _table_sinf(1.5707964f + (temp_f23_14055 - 1.5707964f));
            sp30 = temp_f23_14071;
            sp28 = temp_f1_14073;
            sp2C = 0.0f;
            spD0 = (f64) sp30;
            spC8 = (f64) sp28;
            unkspDC -= 50.0f;
            spE0 = (35.0f * (f32) spD0) + (f32) spE0;
            spD8 = (35.0f * (f32) spC8) + (f32) spD8;
            if (MKCollision_RayCollide(*((MKVector3 *) &spE8), *((MKVector3 *) &spD8), &sp108, (MKCollisionMode) 7, 0x200) == 0) {
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                var_r27_14023 = 1;
                sp100 = (f32) sp100 + (f32) spD0;
            } else if ((arg2 != 0) && ((u32) sp108.unk44 == 1U)) {
                sp18 = 0.0f;
                sp1C = 1.0f;
                sp20 = 0.0f;
                sp88 = (f64) sp18;
                sp90 = (f64) sp20;
                if (((sp108.unk18 * (f32) sp90) + ((sp108.unk10 * (f32) sp88) + (sp108.unk14 * unksp8C))) > 0.0f) {
                    temp_r3_14137 = MKModel_GetWorldMatrix(this->unk4);
                    if (((sp108.unk18 * M2C_FIELD(temp_r3_14137, f32 *, 0x28)) + ((sp108.unk10 * M2C_FIELD(temp_r3_14137, f32 *, 0x20)) + (sp108.unk14 * M2C_FIELD(temp_r3_14137, f32 *, 0x24)))) < 0.0f) {
                        var_r27_14023 = 1;
                    }
                }
            }
            var_r26_14030 += 1;
        } while (var_r26_14030 < 5);
    }
    if ((var_r27_14023 != 0) && (arg3 != NULL)) {
        sp8 = -(f32) spF8;
        spC = -unkspFC;
        sp10 = -sp100;
        sp68 = (f64) sp8;
        sp70 = (f64) sp10;
        Normalise(sp78);
        var_r0_14179 = 0;
        spF8 = M2C_BITWISE(f64, sp78);
        sp100 = (f64) sp78.unk8;
        if ((arg1.unk0 == zero.unk0) && (arg1.unk4 == zero.unk4) && (arg1.unk8 == zero.unk8)) {
            var_r0_14179 = 1;
        }
        if ((var_r0_14179 == 0) && ((((f32) sp100 * this->unk398) + (((f32) spF8 * this->unk390) + (unkspFC * M2C_FIELD(this, f32 *, 0x39C)))) > 0.3f)) {
            InterpolateLinear(sp48, arg1, 0.1f);
            Normalise(sp58);
            M2C_FIELD(arg3, f64 *, 0) = M2C_BITWISE(f64, sp58);
            M2C_FIELD(arg3, f64 *, 8) = (f64) sp58.unk8;
        } else {
            M2C_FIELD(arg3, f64 *, 0) = spF8;
            M2C_FIELD(arg3, f64 *, 8) = sp100;
        }
    }
    return var_r27_14023;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp26C'
u8 Spyro::CheckForLedge(const MKVector3 &arg0, MKVector3 *arg1, MKVector3 *arg2, MKVector3 *arg3, MKProp **arg4) {
    u8 sp408;
    s32 sp404;
    void *sp400;
    s32 sp3FC;
    f32 sp3F8;
    s32 sp3F4;
    s8 sp3F3;
    s8 sp3F2;
    s16 sp3F0;
    f32 sp3EC;
    f32 sp3E8;
    f32 sp3E4;
    f32 sp3E0;
    f32 sp3DC;
    f32 sp3D8;
    f32 sp3D0;
    f32 sp3CC;
    f32 sp3C8;
    f32 sp3C0;
    f32 sp3BC;
    f32 sp3B8;
    u8 sp3B0;
    s32 sp3AC;
    void *sp3A8;
    s32 sp3A4;
    f32 sp3A0;
    s32 sp39C;
    s8 sp39B;
    s8 sp39A;
    s16 sp398;
    f32 sp394;
    f32 sp390;
    f32 sp38C;
    f32 sp388;
    f32 sp384;
    f32 sp380;
    f32 sp378;
    f32 sp374;
    f32 sp370;
    f32 sp368;
    f32 sp364;
    f32 sp360;
    MKCollisionResult sp308;
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
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
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
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp130;
    f32 sp120;
    f32 sp110;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    MKProp *var_r0_14688;
    f32 temp_f0_14331;
    f32 temp_f11_14277;
    f32 temp_f12_14275;
    f32 temp_f8_14278;
    f64 temp_f2_14304;
    f64 temp_f3_14303;
    void **var_r0_14565;
    void **var_r3_14579;
    void *temp_r3_14271;

    sp150 = 0.0f;
    sp148 = 0.0f;
    temp_r3_14271 = this->unk8;
    sp14C = 50.0f;
    temp_f12_14275 = -M2C_FIELD(temp_r3_14271, f32 *, 0x20);
    temp_f11_14277 = -M2C_FIELD(temp_r3_14271, f32 *, 0x24);
    temp_f8_14278 = -M2C_FIELD(temp_r3_14271, f32 *, 0x28);
    sp28 = temp_f12_14275;
    sp2C = temp_f11_14277;
    sp30 = temp_f8_14278;
    sp268 = (f64) sp28;
    sp270 = (f64) sp30;
    sp40 = temp_f8_14278;
    sp38 = temp_f12_14275;
    sp160 = -(f32) sp270;
    sp3C = temp_f11_14277;
    sp300 = (f64) sp40;
    sp2F8 = (f64) sp38;
    temp_f3_14303 = M2C_FIELD(temp_r3_14271, f64 *, 0x30);
    temp_f2_14304 = M2C_FIELD(temp_r3_14271, f64 *, 0x38);
    sp158 = -(f32) sp268;
    sp15C = -unksp26C;
    sp2F0 = (f64) sp160;
    sp2E8 = (f64) sp158;
    sp238 = (f64) sp148;
    sp240 = (f64) sp150;
    sp248 = temp_f3_14303;
    sp250 = temp_f2_14304;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp258 = sp138;
    sp140 = (f32) sp250 + (f32) sp240;
    sp260 = (f64) sp140;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f1 */);
    temp_f0_14331 = arg0.unk8;
    sp2D8 = sp128;
    sp130 = (f32) sp260 + temp_f0_14331;
    sp2E0 = (f64) sp130;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f8, $f8, $f7 */);
    sp228 = sp118;
    sp120 = (f32) sp300 * 130.0f;
    sp230 = (f64) sp120;
    M2C_ERROR(/* unknown instruction: ps_add $f8, $f9, $f8 */);
    sp110 = (f32) sp2E0 + (f32) sp230;
    sp2C8 = sp108;
    sp2D0 = (f64) sp110;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f8, $f8, $f7 */);
    sp1C8 = spC8;
    spD0 = (f32) sp2F0 * 130.0f;
    sp1D0 = (f64) spD0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f7, $f7, $f6 */);
    sp100 = 0.0f;
    spF8 = 0.0f;
    spFC = 50.0f;
    spC0 = (f32) sp1D0 * 0.5f;
    sp1E8 = (f64) spF8;
    sp1F8 = temp_f3_14303;
    sp1D8 = spB8;
    sp1E0 = (f64) spC0;
    sp1F0 = (f64) sp100;
    sp200 = temp_f2_14304;
    M2C_ERROR(/* unknown instruction: ps_add $f2, $f3, $f2 */);
    sp208 = spE8;
    spF0 = (f32) sp200 + (f32) sp1F0;
    sp210 = (f64) spF0;
    M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
    sp218 = spD8;
    spE0 = (f32) sp210 + temp_f0_14331;
    sp220 = (f64) spE0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spA0 = 0.0f;
    sp98 = 0.0f;
    sp9C = 70.0f;
    spB0 = (f32) sp220 + (f32) sp1E0;
    sp1B8 = (f64) sp98;
    sp2B8 = spA8;
    sp2C0 = (f64) spB0;
    sp1C0 = (f64) spA0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp78 = 0.0f;
    sp2A8 = sp88;
    sp90 = (f32) sp2D0 + (f32) sp1C0;
    sp2B0 = (f64) sp90;
    sp80 = 0.0f;
    sp7C = -140.0f;
    sp1B0 = (f64) sp80;
    sp1A8 = (f64) sp78;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp298 = sp68;
    sp70 = (f32) sp2C0 + (f32) sp1B0;
    sp3B8 = 0.0f;
    sp2A0 = (f64) sp70;
    sp3BC = 0.0f;
    sp3C0 = 0.0f;
    sp3C8 = 0.0f;
    sp3CC = 0.0f;
    sp3D0 = 0.0f;
    sp3D8 = 0.0f;
    sp3DC = 0.0f;
    sp3E0 = 0.0f;
    sp3E4 = 1.0f;
    sp3E8 = 0.0f;
    sp3EC = 0.0f;
    sp3F0 = 0;
    sp3F2 = 0;
    sp3F3 = 0;
    sp3F4 = 0;
    sp3F8 = 3.4028235e38f;
    sp3FC = 0;
    sp400 = NULL;
    sp404 = -1;
    sp408 = 0;
    sp360 = 0.0f;
    sp364 = 0.0f;
    sp368 = 0.0f;
    sp370 = 0.0f;
    sp374 = 0.0f;
    sp378 = 0.0f;
    sp380 = 0.0f;
    sp384 = 0.0f;
    sp388 = 0.0f;
    sp38C = 1.0f;
    sp390 = 0.0f;
    sp394 = 0.0f;
    sp398 = 0;
    sp39A = 0;
    sp39B = 0;
    sp39C = 0;
    sp3A0 = 3.4028235e38f;
    sp3A4 = 0;
    sp3A8 = NULL;
    sp3AC = -1;
    sp3B0 = 0;
    if ((MKCollision_RayCollide(*((MKVector3 *) &sp2D8), *((MKVector3 *) &sp2C8), (MKCollisionResult *) &sp3B8, (MKCollisionMode) 7, 0x2A2) != 0) && (MKCollision_RayCollide(*((MKVector3 *) &sp2C8), *((MKVector3 *) &sp2A8), (MKCollisionResult *) &sp360, (MKCollisionMode) 7, 0x2A3) != 0) && (MKCollision_RayCollide(*((MKVector3 *) &sp2B8), *((MKVector3 *) &sp298), &sp308, (MKCollisionMode) 7, 0x2A3) == 0) && (((sp378 * up.unk8) + ((sp370 * up.unk0) + (sp374 * up.unk4))) < -0.7f)) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (((sp3D0 * up.unk8) + ((sp3C8 * up.unk0) + (sp3CC * up.unk4))) == 0.3f) {
            if ((sp408 != 0) && (sp400 != NULL) && (var_r0_14565 = M2C_FIELD(sp400, void ***, 8), ((var_r0_14565 == NULL) == 0))) {

            } else {
                var_r0_14565 = NULL;
            }
            if (var_r0_14565 != NULL) {
                if ((sp408 != 0) && (sp400 != NULL) && (var_r3_14579 = M2C_FIELD(sp400, void ***, 8), ((var_r3_14579 == NULL) == 0))) {

                } else {
                    var_r3_14579 = NULL;
                }
                if (M2C_FIELD(*var_r3_14579, s32 *, 0xC) & 0x80000) {
                    return 0U;
                }
                goto block_18;
            }
block_18:
            if (arg1 != NULL) {
                sp58 = -(f32) sp2F8;
                sp5C = -unksp2FC;
                sp60 = -(f32) sp300;
                sp288 = (f64) sp58;
                sp290 = (f64) sp60;
                M2C_ERROR(/* unknown instruction: ps_sub $f2, $f3, $f2 */);
                sp278 = sp48;
                sp50 = sp3C0 - sp368;
                sp280 = (f64) sp50;
                sp188.operator*((((f32) sp280 * sp3D0) + (((f32) sp278 * sp3C8) + (unksp27C * sp3CC))) / (((f32) sp290 * sp3D0) + (((f32) sp288 * sp3C8) + (unksp28C * sp3CC))));
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(arg1, f64 *, 0) = sp18;
                sp20 = sp188.unk8 + sp368;
                sp198 = sp18;
                sp1A0 = (f64) sp20;
                M2C_FIELD(arg1, f64 *, 8) = (f64) sp20;
            }
            if (arg2 != NULL) {
                sp168.operator*(120.0f);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(arg2, f64 *, 0) = sp8;
                sp10 = (f32) sp2E0 + sp168.unk8;
                sp178 = sp8;
                sp180 = (f64) sp10;
                M2C_FIELD(arg2, f64 *, 8) = (f64) sp10;
            }
            if (arg3 != NULL) {
                M2C_FIELD(arg3, f64 *, 0) = (f64) sp3C8;
                M2C_FIELD(arg3, f64 *, 8) = (f64) sp3D0;
            }
            if (arg4 != NULL) {
                if ((sp3B0 != 0) && (sp3A8 != NULL) && (var_r0_14688 = M2C_FIELD(sp3A8, MKProp **, 8), ((var_r0_14688 == NULL) == 0))) {

                } else {
                    var_r0_14688 = NULL;
                }
                *arg4 = var_r0_14688;
            }
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: expression syntax error
void Spyro::UpdateMovement() {
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    M2C_UNK spC0;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp80;
    MKVector3 sp70;
    M2C_UNK sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    u8 spC;
    void ***sp8;
    MKProp *temp_r3_14814;
    MKProp *temp_r3_14904;
    MKProp *temp_r4_14802;
    MKProp *temp_r4_14821;
    MKProp *temp_r4_14851;
    MKProp *temp_r4_14912;
    MKProp *temp_r4_14934;
    MKProp *temp_r4_14943;
    f32 temp_f0_14766;
    f32 temp_f1_14719;
    f32 temp_f3_14764;
    f32 var_f1_14765;
    u8 temp_r3_14895;
    void ***temp_r4_14857;

    temp_f1_14719 = this->unk3C0;
    if (temp_f1_14719 != this->unk3A8.unk0) {
        this->unk3A0.RollTowards(temp_f1_14719, 10.0f);
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp130 = sp50;
    sp58 = this->unk338 * gUpdateTimeDelta;
    sp138 = (f64) sp58;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp138 = (f32) sp138 + this->unk348;
    this->unk340 = 0.0f;
    this->unk34C = 0.0f;
    this->unk348 = 0.0f;
    if (((s32) M2C_FIELD(this->unk26C.unk8, s32 *, 0x16C) <= 0) || !(this->unk428 & 0x20)) {
        temp_f3_14764 = this->unk388;
        var_f1_14765 = -((M2C_FIELD(this, f32 *, 0x38C) * gUpdateTimeDelta) - this->unk33C);
        temp_f0_14766 = -temp_f3_14764;
        if (var_f1_14765 < temp_f3_14764) {

        } else {
            var_f1_14765 = temp_f3_14764;
        }
        if (var_f1_14765 > temp_f0_14766) {

        } else {
            var_f1_14765 = temp_f0_14766;
        }
        this->unk33C = var_f1_14765;
        unksp134 -= gUpdateTimeDelta * (0.5f * M2C_FIELD(this, f32 *, 0x38C) * gUpdateTimeDelta);
    }
    if (this->unk428 & 8) {
        spF0.ClipVelToEdge(*((MKVector3 *) this));
        sp130 = spF0;
        sp138 = spF8;
    }
    temp_r4_14802 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_14802->unk0, M2C_UNK (**)(f64 *, MKProp *), 0x4C)(&spE0, temp_r4_14802);
    sp120 = spE0;
    sp128 = spE8;
    temp_r3_14814 = this->unk26C.unk8;
    M2C_FIELD(temp_r3_14814->unk0, M2C_UNK (**)(MKProp *, f64 *, s32, f32), 0x10)(temp_r3_14814, &sp130, ((u32) this->unk428 >> 5U) & 1, 0.0f);
    temp_r4_14821 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_14821->unk0, M2C_UNK (**)(M2C_UNK *, MKProp *), 0x4C)(&spC0, temp_r4_14821);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spD0 = sp40;
    sp48 = spC8 - (f32) sp128;
    spD8 = (f64) sp48;
    deltaMove = ((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + (unkspD4 * unkspD4));
    if (this->unk428 & 0x10) {
        temp_r4_14851 = this->unk26C.unk8;
        M2C_FIELD(temp_r4_14851->unk0, M2C_UNK (**)(f64 *, MKProp *), 0x4C)(&spB0, temp_r4_14851);
        temp_r4_14857 = &this->unk264;
        sp110 = spB0;
        sp118 = spB8;
        sp8 = temp_r4_14857;
        if (temp_r4_14857 != NULL) {
            spC = (u8) this->unk268;
            this->unk268 = 0;
        }
        sp30 = 0.0f;
        sp34 = -50.0f;
        sp38 = 0.0f;
        sp90 = (f64) sp30;
        sp98 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        spA0 = sp20;
        sp28 = (f32) sp118 + (f32) sp98;
        spA8 = (f64) sp28;
        temp_r3_14895 = MKCollision_RayCollide(*((MKVector3 *) &sp110), *((MKVector3 *) &spA0), NULL, (MKCollisionMode) 7, 0x220);
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
        if (temp_r3_14895 == 0) {
            temp_r3_14904 = this->unk26C.unk8;
            M2C_FIELD(temp_r3_14904->unk0, M2C_UNK (**)(MKProp *, f64 *, M2C_UNK, f32), 0x14)(temp_r3_14904, &sp120, 0x1E, 2.5f);
            temp_r4_14912 = this->unk26C.unk8;
            M2C_FIELD(temp_r4_14912->unk0, M2C_UNK (**)(f32 *, MKProp *), 0x4C)(&sp80, temp_r4_14912);
            sp10 = sp80;
            sp14 = sp84;
            sp18 = sp88;
            sp1C = 100.0f;
            sp100 = (f64) sp10;
            sp108 = (f64) sp18;
            this->unk26C.unkC->ResetCollisionSweepSphere((s32) &sp100, M2C_ERROR(/* Read from unset register $r5 */));
        }
    }
    temp_r4_14934 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_14934->unk0, M2C_UNK (**)(MKVector3 *, MKProp *), 0x4C)(&sp70, temp_r4_14934);
    SetPos(sp70);
    temp_r4_14943 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_14943->unk0, M2C_UNK (**)(M2C_UNK *, MKProp *), 0x4C)(&sp60, temp_r4_14943);
    this->unk26C.unkC->MoveCollisionSweepSphere((s32) &sp60, *(M2C_ERROR(/* Read from unset register $r5 */)));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Spyro::Update() {
    s8 spE9;
    s8 spE8;
    s32 spE4;
    f32 spE0;
    s32 spDC;
    s8 spDA;
    s8 spD9;
    s8 spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    Spyro *spC4;
    s32 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    s32 sp9C;
    s32 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    u8 sp14;
    void ***sp10;
    f32 spC;
    f32 sp8;
    Animation *temp_r3_15210;
    InputModifier *temp_r3_14969;
    InputModifier *temp_r3_14992;
    InputModifier *temp_r3_15018;
    InputModifier *temp_r3_15041;
    InputModifier *temp_r3_15237;
    MKProp *temp_r4_15162;
    Sparx *temp_r3_15073;
    f32 temp_f0_15135;
    f32 temp_f0_15375;
    f32 var_f1_15005;
    f32 var_f1_15054;
    f32 var_f1_15250;
    f32 var_f2_15134;
    f32 var_f2_15374;
    f64 temp_f0_15113;
    f64 temp_f1_15112;
    f64 temp_f1_15270;
    f64 temp_f2_15269;
    s32 temp_cr0_eq_15187;
    s32 var_r3_14982;
    s32 var_r3_15031;
    u8 var_r4_14971;
    u8 var_r4_14994;
    u8 var_r4_15020;
    u8 var_r4_15043;
    u8 var_r4_15239;
    void ***temp_r4_15084;
    void *temp_r29_15208;
    void *temp_r3_15110;
    void *temp_r4_15197;
    void *temp_r4_15265;
    void *temp_r6_15290;

    temp_r3_14969 = GetInput();
    var_r4_14971 = 0;
    if (((u8) temp_r3_14969->unk5 != 0) || ((u8) temp_r3_14969->unk4 != 0)) {
        var_r4_14971 = 1;
    }
    if (var_r4_14971 != 0) {
        var_r3_14982 = 0;
    } else {
        var_r3_14982 = MKInput_Pressed(0xF, (MKInputDevices) temp_r3_14969->unk0);
    }
    if ((u8) var_r3_14982 == 0) {
        temp_r3_14992 = GetInput();
        var_r4_14994 = 0;
        if (((u8) temp_r3_14992->unk5 != 0) || ((u8) temp_r3_14992->unk4 != 0)) {
            var_r4_14994 = 1;
        }
        if (var_r4_14994 != 0) {
            var_f1_15005 = 0.0f;
        } else {
            var_f1_15005 = MKInput_GetState(0xF, (MKInputDevices) temp_r3_14992->unk0, NULL, NULL);
        }
        if (var_f1_15005 == 0.0f) {
            temp_r3_15018 = GetInput();
            var_r4_15020 = 0;
            if (((u8) temp_r3_15018->unk5 != 0) || ((u8) temp_r3_15018->unk4 != 0)) {
                var_r4_15020 = 1;
            }
            if (var_r4_15020 != 0) {
                var_r3_15031 = 0;
            } else {
                var_r3_15031 = MKInput_Pressed(0xC, (MKInputDevices) temp_r3_15018->unk0);
            }
            if ((u8) var_r3_15031 == 0) {
                temp_r3_15041 = GetInput();
                var_r4_15043 = 0;
                if (((u8) temp_r3_15041->unk5 != 0) || ((u8) temp_r3_15041->unk4 != 0)) {
                    var_r4_15043 = 1;
                }
                if (var_r4_15043 != 0) {
                    var_f1_15054 = 0.0f;
                } else {
                    var_f1_15054 = MKInput_GetState(0xC, (MKInputDevices) temp_r3_15041->unk0, NULL, NULL);
                }
                if (var_f1_15054 != 0.0f) {
                    goto block_28;
                }
            } else {
                goto block_28;
            }
        } else {
            goto block_28;
        }
    } else {
block_28:
        if ((Sparx *) this->unkB70 != NULL) {
            this->unk230 = 5;
            temp_r3_15073 = this->unkB70;
            temp_r3_15073->Message(&this->unk224);
        }
    }
    this->unk200.Update();
    ModelOffsetPreUpdate();
    temp_r4_15084 = &this->unk264;
    sp10 = temp_r4_15084;
    this->unk10 |= 8;
    if (temp_r4_15084 != NULL) {
        sp14 = (u8) this->unk268;
        this->unk268 = 0;
    }
    if (((u8) M2C_FIELD(this, u8 *, 0x1C7) == 0) || ((s32) gb.unk340 != 0)) {
        if (sp10 != NULL) {
            M2C_FIELD(sp10, u8 *, 4) = sp14;
        }
    } else {
        temp_r3_15110 = this->unk8;
        temp_f1_15112 = M2C_FIELD(temp_r3_15110, f64 *, 0x30);
        temp_f0_15113 = M2C_FIELD(temp_r3_15110, f64 *, 0x38);
        sp78 = temp_f1_15112;
        M2C_FIELD(this, f64 *, 0x310) = temp_f1_15112;
        M2C_FIELD(this, f64 *, 0x318) = temp_f0_15113;
        sp80 = temp_f0_15113;
        MKModel_CalculateCentre(this->unk4, &sp88);
        this->unk6F4->StoreClosestProps(sp88, this->unk3C0, 0x5E);
        UpdateCheats();
        BroadcaseCollectRequestMessage(0.0f);
        MKProp::Update();
        var_f2_15134 = 0.0f;
        temp_f0_15135 = this->unk3C4 - gUpdateTimeDelta;
        if (var_f2_15134 > temp_f0_15135) {

        } else {
            var_f2_15134 = temp_f0_15135;
        }
        this->unk3C4 = var_f2_15134;
        BridgeHit(0.0f, 50.0f);
        if (((Spyro *) this->unk408 == &this->unk3E8) && (this->unk428 & 0x800)) {
            sp68 = M2C_FIELD(this, f64 *, 0x338);
            sp70 = M2C_FIELD(this, f64 *, 0x340);
            this->unk26C.unk8->PushOutOfThings((MKVector3) &sp68);
        }
        temp_r4_15162 = this->unk26C.unk8;
        M2C_FIELD(temp_r4_15162->unk0, M2C_UNK (**)(MKVector3 *, MKProp *), 0x4C)(&sp58, temp_r4_15162);
        SetPos(sp58);
        UpdateHeadTurning();
        UpdateAnimation();
        UpdateMeleeButtonState(0U);
        this->unk54.Update();
        this->unk7C.Update(this, 0);
        UpdateEvents();
        temp_cr0_eq_15187 = (u8) this->unk90 == 0;
        if ((temp_cr0_eq_15187 == 0) || ((temp_cr0_eq_15187 != 0) && ((u8) this->unk1C4 != 0))) {
            UpdateMovement();
        }
        temp_r4_15197 = this->unk8;
        sp48 = M2C_FIELD(temp_r4_15197, f64 *, 0x30);
        sp50 = M2C_FIELD(temp_r4_15197, f64 *, 0x38);
        this->unk318 = unksp4C - this->unk314;
        PlatformUpdate();
        temp_r29_15208 = this->unk8;
        temp_r3_15210 = MKModel_GetAnimation(this->unk4);
        if ((u32) temp_r3_15210->unk18 != 0U) {
            temp_r3_15210->CalculateMatrices(NULL, temp_r3_15210->GetNmbrOfNodes(), NULL, (Matrix *) temp_r29_15208);
        }
        if (this->unk428 & 4) {
            CheckForEdge();
        } else {
            M2C_FIELD(this, s8 *, 0x394) = 0;
        }
        if ((u8) this->unk3CD == 1) {
            temp_r3_15237 = GetInput();
            var_r4_15239 = 0;
            if (((u8) temp_r3_15237->unk5 != 0) || ((u8) temp_r3_15237->unk4 != 0)) {
                var_r4_15239 = 1;
            }
            if (var_r4_15239 != 0) {
                var_f1_15250 = 0.0f;
            } else {
                var_f1_15250 = MKInput_GetState(0xB, (MKInputDevices) temp_r3_15237->unk0, NULL, NULL);
            }
            if (var_f1_15250 == 0.0f) {
                this->unk3CD = 0;
            }
        }
        temp_r4_15265 = this->unk8;
        temp_f2_15269 = M2C_FIELD(temp_r4_15265, f64 *, 0x30);
        temp_f1_15270 = M2C_FIELD(temp_r4_15265, f64 *, 0x38);
        sp38 = temp_f2_15269;
        M2C_FIELD(&p_1138, f64 *, 8) = temp_f1_15270;
        sp40 = temp_f1_15270;
        M2C_FIELD(&p_1138, f64 *, 0) = temp_f2_15269;
        p_1138.unkC = 100.0f;
        MKGrass_SetPushAwaySphere(p_1138, 0);
        ColorSpyroFromGround(0.1f);
        UpdateLastSafePos();
        sp8 = 0.0f;
        spC = 0.0f;
        if ((u8) M2C_FIELD(this, u8 *, 0x3CD) == 0) {
            temp_r6_15290 = this->unk8;
            sp28 = M2C_FIELD(temp_r6_15290, f64 *, 0x30);
            sp30 = M2C_FIELD(temp_r6_15290, f64 *, 0x38);
            if ((sp28.IsWithin(*((MKVector3 *) &spC), &sp8, (s32 *) temp_r6_15290) != 0) && ((M2C_BITWISE(s32, sp8) == 1) || (M2C_BITWISE(s32, sp8) == 4))) {
                sp9C = 0;
                sp98 = 7;
                spC0 = 5;
                spC4 = this;
                spA0 = M2C_FIELD(&up, f64 *, 0);
                spA8 = M2C_FIELD(&up, f64 *, 8);
                spD8 = 1;
                spE4 = 2;
                spE0 = 10.0f;
                spD9 = 0;
                spDA = 0;
                spDC = -1;
                spB0 = M2C_FIELD(&one, f64 *, 0);
                spB8 = M2C_FIELD(&one, f64 *, 8);
                spE8 = 0;
                if (this != NULL) {
                    sp18.GetPos();
                    spC8 = sp18;
                    spD0 = sp20;
                } else {
                    spC8 = 0.0f;
                    unkspCC = 0.0f;
                    spD0 = 0.0f;
                }
                spE9 = 0;
                if (M2C_BITWISE(s32, sp8) == 1) {
                    spDC = GS_SpyroLavaBurn;
                } else if (M2C_BITWISE(s32, sp8) == 4) {
                    spDC = GS_SpyroAcidBurn;
                }
                Hurt((HurtMessage *) &sp98);
            }
        }
        if ((u8) M2C_FIELD(this, u8 *, 0x3E0) != 0) {
            var_f2_15374 = 0.0f;
            temp_f0_15375 = this->unk3DC - gUpdateTimeDelta;
            if (var_f2_15374 > temp_f0_15375) {

            } else {
                var_f2_15374 = temp_f0_15375;
            }
            this->unk3DC = var_f2_15374;
            if ((this->unk3DC == 0.0f) && (M2C_FIELD(&gameData, f32 *, 0x70) < gameData.unk74)) {
                gameData.unk70.Add(10.0f * gUpdateTimeDelta, 1U);
            }
        }
        UpdateEffects((MKVector3 *) &this->unk308);
        UpdateCombatArcs();
        UpdateSpyroCameraInfo();
        CheckCameraButtons();
        UpdateLighting();
        UpdateCrowdTest();
        UpdateSlidingSounds();
        this->unk6F8.Update();
        M2C_FIELD(this, s8 *, 0x3D1) = 0;
        M2C_FIELD(this, s32 *, 0x3E8) = 0;
        ModelOffsetPostUpdate();
        this->unk1F8 = this->unk2A4;
        this->unk78 = 0;
        if (sp10 != NULL) {
            M2C_FIELD(sp10, u8 *, 4) = sp14;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void Spyro::UpdateHeadTurning() {
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
    f32 sp10;
    f32 spC;
    f32 sp8;
    InputModifier *temp_r3_15447;
    f32 var_f1_15460;
    f64 *var_r31_15446;
    f64 temp_f0_15534;
    f64 temp_f1_15533;
    s32 temp_r4_15525;
    u8 var_r3_15563;
    u8 var_r4_15449;
    void *temp_r3_15532;
    void *temp_r4_15551;
    void *temp_r4_15566;
    void *temp_r8_15492;

    var_r31_15446 = NULL;
    temp_r3_15447 = GetInput();
    var_r4_15449 = 0;
    if (((u8) temp_r3_15447->unk5 != 0) || ((u8) temp_r3_15447->unk4 != 0)) {
        var_r4_15449 = 1;
    }
    if (var_r4_15449 != 0) {
        var_f1_15460 = 0.0f;
    } else {
        var_f1_15460 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_15447->unk0, NULL, NULL);
    }
    if (var_f1_15460 == 0.0f) {
        this->unkB90.ClearCurrentTarget();
    }
    if ((u8) M2C_FIELD(this, u8 *, 0x3CE) == 0) {
        if ((u8) M2C_FIELD(this, u8 *, 0x1BC) == 0) {
            this->unkB90.GetCurrentTarget();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                this->unkB90.GetCurrentTarget();
                this->unk1B4.Set(M2C_ERROR(/* Read from unset register $r3 */));
            } else {
                temp_r8_15492 = this->unk8;
                sp8 = -M2C_FIELD(temp_r8_15492, f32 *, 0x20);
                spC = -M2C_FIELD(temp_r8_15492, f32 *, 0x24);
                sp10 = -M2C_FIELD(temp_r8_15492, f32 *, 0x28);
                sp48 = (f64) sp8;
                sp50 = (f64) sp10;
                sp58 = M2C_FIELD(temp_r8_15492, f64 *, 0x30);
                sp60 = M2C_FIELD(temp_r8_15492, f64 *, 0x38);
                this->unk1B4.Set(gb.unk20->GetNearestFacingEnemy(*((MKVector3 *) &sp58), 600.0f, *((MKVector3 *) &sp48), 0.25f, 1U, 1U));
            }
        } else {
            temp_r4_15525 = this->unk1B4.unk8;
            if ((u32) temp_r4_15525 != 0U) {
                this->unk1B4.Set((MKProp *) temp_r4_15525);
                var_r31_15446 = &sp68;
                temp_r3_15532 = M2C_FIELD(this->unk1B4.unk8, void **, 8);
                temp_f1_15533 = M2C_FIELD(temp_r3_15532, f64 *, 0x30);
                temp_f0_15534 = M2C_FIELD(temp_r3_15532, f64 *, 0x38);
                sp38 = temp_f1_15533;
                sp40 = temp_f0_15534;
                sp68 = temp_f1_15533;
                sp70 = temp_f0_15534;
            } else {
                M2C_FIELD(this, u8 *, 0x1BC) = 0U;
            }
        }
        if (this->unk1B4.Get() != NULL) {
            if ((u8) M2C_FIELD(this, u8 *, 0x3D3) != 0) {
                temp_r4_15551 = this->unk8;
                sp28 = M2C_FIELD(temp_r4_15551, f64 *, 0x30);
                sp30 = M2C_FIELD(temp_r4_15551, f64 *, 0x38);
                var_r3_15563 = M2C_FIELD(this->unk1B4.Get()->__vptr, u8 (**)(f64 *, f64 *), 0x2C)(&sp28, &sp68);
            } else {
                temp_r4_15566 = this->unk8;
                sp18 = M2C_FIELD(temp_r4_15566, f64 *, 0x30);
                sp20 = M2C_FIELD(temp_r4_15566, f64 *, 0x38);
                var_r3_15563 = M2C_FIELD(this->unk1B4.Get()->__vptr, u8 (**)(f64 *, f64 *), 0x28)(&sp18, &sp68);
            }
            if (var_r3_15563 != 0) {
                var_r31_15446 = &sp68;
            }
        }
        this->unk178.Update((MKVector3 *) var_r31_15446);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void Spyro::CheckCameraButtons() {
    s32 spC;
    s32 sp8;
    InputModifier *temp_r3_15617;
    KDCamera *temp_r3_15640;
    s32 var_r3_15630;
    u8 var_r4_15619;

    if (((u8) M2C_FIELD(this, u8 *, 0x1C6) != 0) && ((gb.unk30C - gb.unk310) > 0.5f) && (this->unk428 & 0x200000)) {
        temp_r3_15617 = GetInput();
        var_r4_15619 = 0;
        if (((u8) temp_r3_15617->unk5 != 0) || ((u8) temp_r3_15617->unk4 != 0)) {
            var_r4_15619 = 1;
        }
        if (var_r4_15619 != 0) {
            var_r3_15630 = 0;
        } else {
            var_r3_15630 = MKInput_Pressed(2, (MKInputDevices) temp_r3_15617->unk0);
        }
        if ((u8) var_r3_15630 != 0) {
            temp_r3_15640 = GetCamera();
            spC = 0;
            sp8 = 0x44C;
            M2C_FIELD(temp_r3_15640->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spA4'
void Spyro::UpdateCameraInfo(const MKVector3 &arg0) {
    if ((u8) M2C_FIELD(this, u8 *, 0x1C6) != 0) {
        if (((u8) this->unk3CE != 0) && ((u32) M2C_FIELD(this, u32 *, 0x3D8) != 0U)) {
            arg_spA4 = 0;
            arg_sp70.GetPos();
            arg_sp80.GetPos();
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp90 = arg_sp20;
            arg_sp28 = arg_sp88 - arg_sp78;
            arg_spA0 = 0x432;
            arg_sp98 = (f64) arg_sp28;
            arg_spA8 = arg_sp20;
            arg_spB0 = (f64) arg_sp28;
            arg_spB8 = 7.0f;
            M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&arg_spA0);
        }
        arg_sp104 = 0;
        arg_sp100.ClearData();
        M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (this->unk8 - 4) + 4, 0x40);
        arg_spF0 = arg0.unk0;
        arg_spF4 = arg0.unk4;
        arg_spF8 = arg0.unk8;
        arg_spFC = 1.0f;
        arg_sp100.Init((Matrix *) &arg_spC0);
        arg_sp194 = this->unk7C.GetState() == 2;
        arg_sp198 = 100.0f;
        arg_sp19C = 0x220;
        arg_sp1A0 = 7;
        arg_sp30.GetPos();
        arg_sp40.GetPos();
        arg_sp50.GetPos();
        arg_sp18 = arg_sp38;
        arg_sp10 = arg_sp50;
        arg_sp14 = arg_sp44 + 100.0f;
        arg_sp158 = (f64) arg_sp18;
        arg_sp150 = (f64) arg_sp10;
        arg_sp60 = (f64) arg_sp10;
        arg_sp68 = (f64) arg_sp18;
        arg_sp1A4 = GetCollisionInfo((f64) arg_sp10);
        arg_sp1AC = 150.0f;
        arg_sp1B0 = 100.0f;
        M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&arg_sp100);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
void Spyro::UpdateSpyroCameraInfo() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    void *temp_r4_15818;

    if (this->unk428 & 0x400) {
        temp_r4_15818 = this->unk8;
        sp18 = M2C_FIELD(temp_r4_15818, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r4_15818, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp28 = sp8;
        sp10 = (f32) sp20 + M2C_FIELD(this, f32 *, 0x370);
        sp30 = (f64) sp10;
        UpdateCameraInfo(*((MKVector3 *) &sp28));
    }
}
#endif

#if 0 // DRAFT: illegal operand
void Spyro::Resolve() {
    Sparx *temp_r3_15877;

    if (this == (u32) M2C_FIELD(this->unk0, u32 *, 0x28)) {
        M2C_FIELD(&gb, f32 *, 0x3B8) = (f32) this->unk214.unkC;
    }
    gameData.unk70.Init(50.0f, 50.0f, NULL, NULL);
    ((Stat *) (&gameData.unk70 + 0x30))->Init(30.0f, 30.0f, NULL, NULL);
    temp_r3_15877 = this->unkB70;
    if (temp_r3_15877 != NULL) {
        temp_r3_15877->unk18 = this->unk18;
    }
}
#endif

void Spyro::Draw() {
    if (!(this->unk18 & 0x80000000)) {
        if ((u8) M2C_FIELD(this, u8 *, 0x1C5) == 0) {
            return;
        }
        DrawSpyro();
    }
}

void Spyro::DrawDebug() {

}

void Spyro::DrawSpyro() {
    f32 temp_f1_15936;
    f32 temp_f30_15939;

    SetLighting();
    MKModel_EnableScissoring(this->unk4, ((u32) this->unk10 >> 0xFU) & 1);
    temp_f1_15936 = MKModel_GetAlpha(this->unk4);
    temp_f30_15939 = this->unk20;
    MKModel_SetAlpha(this->unk4, temp_f1_15936 * this->unk324);
    this->unk20 = MKModel_GetAlpha(this->unk4);
    if ((u8) M2C_FIELD(this, u8 *, 0x1C5) != 0) {
        MKModel_Draw(this->unk4, NULL);
    }
    MKModel_SetAlpha(this->unk4, temp_f1_15936);
    this->unk20 = temp_f30_15939;
    ResetLighting();
    DrawDebug();
}

#if 0 // DRAFT: expression syntax error
void Spyro::Reset() {
    SpyroStateMessages sp10;
    s32 spC;
    Spyro *sp8;
    MKProp *temp_r3_16032;
    MKProp *temp_r3_16051;
    void *temp_r3_16023;
    void *temp_r3_16042;

    MKProp::Reset();
    this->unk428.Reset();
    gameData.unk70.SetValue(gameData.unk74, 0U);
    ((Stat *) (&gameData.unk70 + 0x30))->SetValue(gameData.unkA4, 0U);
    ((Stat *) (&gameData.unk70 + 0x48))->SetValue(0.0f, 0U);
    ClearData();
    this->unk68 = M2C_FIELD(&one, f64 *, 0);
    this->unk70 = M2C_FIELD(&one, f64 *, 8);
    M2C_FIELD(this, s8 *, 0x1C4) = 1;
    M2C_FIELD(this, s8 *, 0x1C5) = 1;
    this->unk3CC = 0;
    sp10.unk50 = 0;
    this->unk54.Reset(0xA, sp10);
    this->unk358 = 0;
    this->unk35C = 0;
    if ((u8) M2C_FIELD(this, u8 *, 0x284) != 0) {
        temp_r3_16023 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = this;
        spC = 0;
        temp_r3_16032 = this->unk26C.unk8;
        M2C_FIELD(temp_r3_16032->unk0, M2C_UNK (**)(MKProp *, void *, u8 *, M2C_UNK, void ***, M2C_UNK, M2C_UNK, M2C_UNK), 8)(temp_r3_16032, temp_r3_16023 + 0x60, &this->unk2F0, 0, &this->unk264, 1, 1, 0);
    } else {
        temp_r3_16042 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = this;
        spC = 0;
        temp_r3_16051 = this->unk26C.unk8;
        M2C_FIELD(temp_r3_16051->unk0, M2C_UNK (**)(MKProp *, void *, u8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 8)(temp_r3_16051, temp_r3_16042 + 0x60, &this->unk2F0, 0, 0, 0, 1, 0);
    }
    ColorSpyroFromGround(1.0f);
    UpdateSpyroCameraInfo();
    M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(), 0x38)();
    this->unk4C.RegisterTargetable();
    M2C_FIELD(this, f32 *, 0x248) = 0.0f;
    M2C_FIELD(this, s8 *, 0x269) = 0;
    M2C_FIELD(this, f32 *, 0x24C) = 0.0f;
    this->unk250 = 0.0f;
    this->unk248 = 0.0f;
    M2C_FIELD(this, s8 *, 0x25D) = 0;
    this->unkBB4 = 0;
}
#endif

#if 0 // DRAFT: function call 'MKModel_Create(MKHeap *, signed char *, int, int)' does not
void Spyro::LoadDone() {
    MKAnimScript *temp_r27_16307;
    MKHeap *temp_r27_16105;
    MKHeap *temp_r3_16223;
    MKHeap *var_r3_16202;
    MKProp *temp_r3_16196;
    MKProp *temp_r3_16215;
    MKProp *temp_r4_16246;
    s32 var_r26_16300;
    s32 var_r26_16325;
    s32 var_r26_16358;
    s32 var_r26_16372;
    s32 var_r29_16301;
    s32 var_r29_16326;
    s32 var_r29_16359;
    s32 var_r31_16373;
    s8 *temp_r27_16341;
    s8 *temp_r29_16382;
    void *temp_r29_16458;
    void *temp_r31_16455;
    void *temp_r3_16187;
    void *temp_r3_16206;
    void *temp_r3_16515;
    void *temp_ret_16333;
    void *temp_ret_16376;
    void *temp_ret_16397;
    void *var_r3_16230;
    temp_r27_16105 = ((Animation *) (M2C_FIELD(this->unk0, Animation **, 0x30)))->GetName();
    this->unk4 = MKModel_Create(MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), (s8 *) temp_r27_16105, 2, NULL);
    MKProp::LoadDone();
    if ((s32) M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xD0) > -1) {
        this->unk178.Init(this->unk4, M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xD0), (NLStyle) 0);
        this->unk178.unk38 = 1;
    }
    this->unk200 = *gb.unk354;
    M2C_FIELD(this, s8 *, 0x208) = 0;
    M2C_FIELD(this, s8 *, 0x209) = 0;
    this->unk204.unk4 = 0;
    M2C_FIELD(this, f32 *, 0x210) = 5.0f;
    this->unk204.unkC = 0.0f;
    M2C_FIELD(this, s8 *, 0x218) = 1;
    M2C_FIELD(this, s8 *, 0x219) = 0;
    this->unk214.unkC = M2C_BITWISE(f32, checked_cast<KDCamera *, MKProp>(gMK->CreateProp("GameCamera2")));
    M2C_FIELD(&gb, f32 *, 0x3B8) = (f32) this->unk214.unkC;
    this->unk1D0.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unk264 = NULL;
    this->unk268 = 1;
    this->unk26C.unk0 = (s32) this;
    M2C_FIELD(this, s32 *, 0x278) = 0;
    operator new(0x490U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk26C.unk8 = M2C_ERROR(/* Read from unset register $r3 */);
    if ((u8) M2C_FIELD(this, u8 *, 0x284) != 0) {
        temp_r3_16187 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        arg_sp8 = this;
        arg_spC = 0;
        temp_r3_16196 = this->unk26C.unk8;
        var_r3_16202 = M2C_FIELD(temp_r3_16196->unk0, MKHeap *(**)(MKProp *, void *, u8 *, M2C_UNK, void ***, M2C_UNK, M2C_UNK, M2C_UNK), 8)(temp_r3_16196, temp_r3_16187 + 0x60, &this->unk2F0, 0, &this->unk264, 1, 1, 0);
    } else {
        temp_r3_16206 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        arg_sp8 = this;
        arg_spC = 0;
        temp_r3_16215 = this->unk26C.unk8;
        var_r3_16202 = M2C_FIELD(temp_r3_16215->unk0, MKHeap *(**)(MKProp *, void *, u8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 8)(temp_r3_16215, temp_r3_16206 + 0x60, &this->unk2F0, 0, 0, 0, 1, 0);
    }
    temp_r3_16223 = var_r3_16202->Current();
    if (temp_r3_16223 != NULL) {
        var_r3_16230 = ((MKHeap *) (temp_r3_16223->Current()))->Alloc(0x60, NULL, 0);
    } else {
        var_r3_16230 = malloc(0x60);
    }
    this->unk35C = (s32) var_r3_16230;
    this->unk350 = 6e-45f;
    SetLastSafePos(*((MKVector3 *) &this->unk2F0), NULL);
    this->unk26C.unkC = ((MKCloth *) (M2C_ERROR(/* Read from unset register $r3 */)))->AllocateSweepSphere();
    temp_r4_16246 = this->unk26C.unk8;
    M2C_FIELD(temp_r4_16246->unk0, M2C_UNK (**)(f32 *, MKProp *), 0x4C)(&arg_sp50, temp_r4_16246);
    arg_sp20 = arg_sp50;
    arg_sp24 = arg_sp54;
    arg_sp28 = arg_sp58;
    arg_sp2C = 100.0f;
    arg_sp60 = (f64) arg_sp20;
    arg_sp68 = (f64) arg_sp28;
    this->unk26C.unkC->ResetCollisionSweepSphere((s32) &arg_sp60, M2C_ERROR(/* Read from unset register $r5 */));
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
    Init__22KDStateMachine<5Spyro>FPQ222KDStateMachine<5Spyro>5StateP22KDStateMachine<5Spyro>(&this->unk7C, (KDStateMachine<Spyro>::State *) &pNodeNames.unk460.unk20.unkC, NULL);
    this->unk7C.SetState(this, 0, 0U);
    this->unk8 = MKModel_GetWorldMatrix(this->unk4);
    M2C_STRUCT_COPY((s32) &arg_sp8C + 4, (s32) (this->unk8 - 4) + 4, 0x40);
    GetYaw();
    arg_sp90.SetRotationYaw(M2C_ERROR(/* Read from unset register $f1 */));
    MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp90));
    var_r26_16300 = 0;
    var_r29_16301 = 0;
    do {
        temp_r27_16307 = this + (var_r29_16301 + 0xC0);
        temp_r27_16307->Init(M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKAnimScript **, 0x34), this->unk4);
        temp_r27_16307->SetAnimation(MKModel_GetAnimation(this->unk4));
        var_r26_16300 += 1;
        var_r29_16301 += 0x58;
    } while (var_r26_16300 < 2);
    this->unkB4.Init((AnimEntry *) &pNodeNames.unk18, 0x5C, &this->unkC0);
    var_r26_16325 = 0;
    var_r29_16326 = 0;
    do {
        if ((u32) *(&pAnimScrNodeNames + var_r29_16326) != 0U) {
            temp_ret_16333 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r27_16341 = Str_Printf("%s%s", M2C_FIELD(temp_ret_16333, s32 *, 0xAC), *(&pAnimScrNodeNames + var_r29_16326), "Head", M2C_BITWISE(f32, temp_ret_16333));
            ((Animation *) (MKModel_GetAnimation(this->unk4)))->NodeExists(temp_r27_16341, this + (var_r29_16326 + 0x170));
        } else {
            *(this + (var_r29_16326 + 0x170)) = -1;
        }
        var_r26_16325 += 1;
        var_r29_16326 += 4;
    } while (var_r26_16325 < 2);
    var_r26_16358 = 0;
    var_r29_16359 = 0;
    do {
        ((MKAnimScript *) (this + (var_r29_16359 + 0xC0)))->InitEvents((s8 **) &pNodeNames.unk2F0);
        var_r26_16358 += 1;
        var_r29_16359 += 0x58;
    } while (var_r26_16358 < 2);
    var_r26_16372 = 0;
    var_r31_16373 = 0;
    do {
        temp_ret_16376 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r29_16382 = Str_Printf("%s%s", M2C_FIELD(temp_ret_16376, s32 *, 0xAC), *(&pNodeNames + var_r31_16373), M2C_BITWISE(f32, temp_ret_16376));
        var_r26_16372 += 1;
        *(this + (var_r31_16373 + 0x98)) = ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex(temp_r29_16382);
        var_r31_16373 += 4;
    } while (var_r26_16372 < 6);
    temp_ret_16397 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_RefPointExists(this->unk4, Str_Printf("%s%s", M2C_FIELD(temp_ret_16397, s32 *, 0xB4), pRefPointNames.unk0, M2C_BITWISE(f32, temp_ret_16397)), &this->unkB0);
    this->unkC0.SetAnim(M2C_FIELD(this->unkB4, MKAnim **, 4), 1.0f, 0.0f, 0, -1);
    this->unk3A0.Init(this->unk4, -1);
    MKModel_GetWorldMatrix(this->unk4);
    arg_sp40.GetRotationPYR();
    this->unk3A0.SetPYR(*((MKVector3 *) &arg_sp40));
    arg_sp74 = 0;
    arg_sp70.Init((MKProp *) this, 100.0f, 30.000002f, 0U, 0.4f);
    M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(M2C_UNK *), 0x2C)(&arg_sp70);
    arg_sp10 = 0.0f;
    arg_sp14 = 0.0f;
    arg_sp18 = 1.0f;
    arg_sp1C = 1.0f;
    arg_sp30 = (f64) arg_sp10;
    arg_sp38 = (f64) arg_sp18;
    temp_r31_16455 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r29_16458 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddSphere(this->unk8 + 0x30, M2C_FIELD(temp_r29_16458, f32 *, 0x60), M2C_FIELD(temp_r31_16455, f32 *, 0x60), *((MKVector4 *) &arg_sp30), (MKCollisionMode) 2, (MKCollisionInfo *) &this->unk264, 0x04000000U);
    operator new(0xD0U, NULL, 0);
    M2C_FIELD(this, SpyroFXData **, 0x264) = (SpyroFXData *) M2C_ERROR(/* Read from unset register $r3 */);
    ((SpyroFXData *) (M2C_FIELD(this, SpyroFXData **, 0x264)))->Init((MKProp *) this, this->unk4, GetAnimScript((Spyro::AnimScriptNode) 0));
    gb.unk2C4 = M2C_FIELD(this, SpyroFXData **, 0x264);
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk258 = M2C_ERROR(/* Read from unset register $r3 */);
    ((SpyroEffects *) (M2C_BITWISE(SpyroEffects *, this->unk258)))->Init(M2C_FIELD(this, SpyroFXData **, 0x264), (MKProp *) this, &this->unk6F8);
    M2C_FIELD(this, f32 *, 0x248) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24C) = 0.0f;
    this->unk248 = 0.0f;
    this->unk250 = 0.0f;
    M2C_FIELD(this, s8 *, 0x25D) = 0;
    M2C_FIELD(this, s8 *, 0x3E0) = 0;
    this->unk3DC = 0.0f;
    temp_r3_16515 = this->unk8;
    this->unk238 = M2C_FIELD(temp_r3_16515, f64 *, 0x30);
    this->unk238 = M2C_FIELD(temp_r3_16515, f64 *, 0x38);
}
#endif

#if 0 // DRAFT: identifier 'Spyro::LoadLine(MKIniLine *)' redeclared
u8 Spyro::LoadLine(MKIniLine *arg0) {
    f64 sp10;
    f64 sp8;
    u8 var_r26_16553;
    u8 var_r27_16542;
    u8 var_r28_16541;
    u8 var_r31_16538;

    var_r31_16538 = 1;
    var_r28_16541 = 1;
    var_r27_16542 = 1;
    sp8 = M2C_FIELD(&zero, f64 *, 0);
    sp10 = M2C_FIELD(&zero, f64 *, 8);
    if (MKProp::LoadLine(arg0) == 0) {
        var_r26_16553 = 0;
        if (arg0->LoadVector3("rot", (MKVector3 *) &sp8, 0) != 0) {
            var_r26_16553 = 1;
            this->unk300 = unkspC;
        }
        if (var_r26_16553 == 0) {
            var_r27_16542 = 0;
        }
    }
    if ((var_r27_16542 == 0) && (arg0->LoadVector3("pos", (MKVector3 *) &this->unk2F0, 0) == 0)) {
        var_r28_16541 = 0;
    }
    if ((var_r28_16541 == 0) && (arg0->LoadBool("bUseCollisionInfo", (u8 *) &this->unk27C, 0) == 0)) {
        var_r31_16538 = 0;
    }
    return var_r31_16538;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void Spyro::Deinit() {
    Spyro *sp10;
    s32 spC;
    s32 sp8;
    MKHeap *temp_r3_16625;
    MKHeap *temp_r3_16664;
    MKProp **temp_r30_16660;
    MKProp **temp_r3_16655;
    MKProp *temp_r3_16685;
    s32 temp_r30_16622;
    s32 var_r29_16692;
    s32 var_r30_16693;

    this->unk1C5 = 1;
    ((SpyroEffects *) (M2C_BITWISE(SpyroEffects *, this->unk258)))->Deinit();
    operator delete(M2C_BITWISE(void *, this->unk258));
    ((SpyroFXData *) (M2C_FIELD(this, SpyroFXData **, 0x264)))->Deinit();
    operator delete(M2C_FIELD(this, SpyroFXData **, 0x264));
    gb.unk2C4 = NULL;
    temp_r30_16622 = this->unk35C;
    if ((u32) temp_r30_16622 != 0U) {
        temp_r3_16625 = gb.Current();
        if (temp_r3_16625 != NULL) {
            ((MKHeap *) (temp_r3_16625->Current()))->Free((void *) temp_r30_16622, NULL, 0);
        } else {
            free(temp_r30_16622);
        }
        this->unk35C = 0;
    }
    this->unk350 = 0.0f;
    this->unk358 = 0;
    this->unk35C = 0;
    this->unk1D0.Deinit();
    PlatformDetach();
    this->unk54.Deinit();
    this->unkB78.Deinit();
    do {
        temp_r3_16655 = this->unk6F0 - 4;
        this->unk6F0 = temp_r3_16655;
    } while ((MKProp *) *temp_r3_16655 != NULL);
    temp_r30_16660 = this->unk6F0;
    if (temp_r30_16660 != &gEmptyPtrList) {
        temp_r3_16664 = temp_r3_16655->Current();
        if (temp_r3_16664 != NULL) {
            ((MKHeap *) (temp_r3_16664->Current()))->Free(temp_r30_16660, NULL, 0);
        } else {
            free((s32) temp_r30_16660);
        }
    }
    this->unk6F0 = NULL;
    this->unkB90.Deinit();
    this->unk26C.unkC->ReleaseSweepSphere(M2C_ERROR(/* Read from unset register $r4 */));
    this->unk26C.unkC = -1;
    temp_r3_16685 = this->unk26C.unk8;
    M2C_FIELD(temp_r3_16685->unk0, M2C_UNK (**)(MKProp *), 0xC)(temp_r3_16685);
    operator delete(this->unk26C.unk8);
    var_r29_16692 = 0;
    var_r30_16693 = 0;
    do {
        ((MKAnimScript *) (this + (var_r30_16693 + 0xC0)))->Deinit();
        var_r29_16692 += 1;
        var_r30_16693 += 0x58;
    } while (var_r29_16692 < 2);
    MKProp::Deinit();
    if ((u32) M2C_FIELD(&gb, u32 *, 0x3B8) != 0U) {
        spC = 0;
        sp8 = 0x456;
        sp10 = this;
        M2C_FIELD(GetCamera()->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    this->unk6F8.Deinit();
    operator delete(this->unk6F4);
    this->unk6F4 = NULL;
    if (((HeroInterface *) gb.unk0 != NULL) && (M2C_FIELD(gb.unk0->__vptr, u32 (**)(), 0xC)() == this)) {
        gb.SetHero(NULL);
    }
    this->unk4C.UnregisterTargetable();
    operator delete(this->unk94);
    this->unk94 = NULL;
}
#endif

#if 0 // DRAFT: pointer/array required
void Spyro::Init() {
    MKHeap *temp_r3_16879;
    MKProp **temp_r3_16901;
    MKProp **temp_r3_16906;
    MKProp **var_r3_16886;
    s32 var_ctr_16899;

    MKProp::Init();
    this->unk1C5 = 0;
    operator new(8U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk94 = M2C_ERROR(/* Read from unset register $r3 */);
    M2C_FIELD(this->unk94, Spyro **, 4) = this;
    if ((HeroInterface *) gb.unk0 == NULL) {
        gb.SetHero((HeroInterface *) this->unk94);
    }
    operator new(0x7FCU, NULL, 0);
    this->unk6F4 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk6F4->ClearData();
    this->unk428.Reset();
    this->unkB78.Init(0xF);
    this->unkB90.Init(3000.0f, 8U, 1U);
    this->unk90 = 1;
    gb.unk381 = 0;
    gb.unk35D = 0;
    gb.unk5 = 1;
    ClearData();
    this->unk300 = 0.0f;
    M2C_FIELD(this, f32 *, 0x2F8) = 1000000.0f;
    this->unk2FC = -1000000.0f;
    this->unk300 = 0.0f;
    M2C_FIELD(this, s8 *, 0x1C4) = 1;
    M2C_FIELD(this, s8 *, 0x1C5) = 1;
    M2C_FIELD(this, s8 *, 0x1C6) = 1;
    this->unk214.unkC = 0.0f;
    this->unk200 = 0;
    M2C_FIELD(this, s8 *, 0x3CC) = 1;
    M2C_FIELD(this, s8 *, 0x3CD) = 0;
    M2C_FIELD(this, s8 *, 0x3CE) = 0;
    M2C_FIELD(this, s8 *, 0x3CF) = 0;
    M2C_FIELD(this, s8 *, 0x3D0) = 0;
    M2C_FIELD(this, s8 *, 0x268) = 0;
    this->unk3CC = 0;
    M2C_FIELD(this, s8 *, 0x1BC) = 0;
    this->unk1B4.unk8 = 0;
    M2C_FIELD(this, s8 *, 0x284) = 0;
    this->unk10 |= 8;
    this->unk54.Init(this, (SpyroStateCreatorTableEntry *) &stateCreators, 0xF);
    M2C_FIELD(this, f32 *, 0x38C) = 1900.0f;
    M2C_FIELD(this, s8 *, 0x3D2) = 0;
    this->unk280 = 1.0f;
    M2C_FIELD(this, f32 *, 0x28C) = 1.0f;
    M2C_FIELD(this, f32 *, 0x290) = 1.0f;
    M2C_FIELD(this, f32 *, 0x294) = 1.0f;
    this->unk324 = 1.0f;
    this->unk6F8.Init();
    this->unk308 = 0.0f;
    this->unk314 = 0.0f;
    this->unk310 = 0.0f;
    this->unk68 = M2C_FIELD(&one, f64 *, 0);
    this->unk70 = M2C_FIELD(&one, f64 *, 8);
    gMK->CreatePropDeferred("Sparx", (MKProp **) &this->unkB70);
    temp_r3_16879 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_16879 != NULL) {
        var_r3_16886 = ((MKHeap *) (temp_r3_16879->Current()))->Alloc(0x44, NULL, 0);
    } else {
        var_r3_16886 = malloc(0x44);
    }
    this->unk6F0 = var_r3_16886;
    M2C_FIELD(this->unk6F0, MKProp **, 0) = NULL;
    var_ctr_16899 = 0xF;
    do {
        temp_r3_16901 = this->unk6F0;
        this->unk6F0 = temp_r3_16901 + 4;
        M2C_FIELD(temp_r3_16901, s32 *, 4) = 0xDEADBEEF;
        var_ctr_16899 -= 1;
    } while (var_ctr_16899 != 0);
    temp_r3_16906 = this->unk6F0;
    this->unk6F0 = temp_r3_16906 + 4;
    M2C_FIELD(temp_r3_16906, s32 *, 4) = 0;
    M2C_FIELD(this, s8 *, 0x269) = 0;
    this->unk408 = this;
    M2C_FIELD(this, Spyro **, 0x418) = this;
    this->unkBB4 = 0;
    pInstance.unk0 = this;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void SpyroDescriptor::LoadDone() {
    s32 var_r28_16944;
    s32 var_r31_16945;
    s8 *temp_r30_16934;
    s8 *temp_r4_16949;
    void *temp_r29_16948;

    MKPropDescriptor::LoadDone();
    temp_r30_16934 = this->unkCC;
    if (temp_r30_16934 != NULL) {
        this->unkD0 = ((Animation *) (MKModel_GetAnimation(this->unk2C)))->GetNodeIndex(temp_r30_16934);
    }
    var_r28_16944 = 0;
    var_r31_16945 = 0;
    do {
        temp_r29_16948 = this + var_r31_16945;
        temp_r4_16949 = M2C_FIELD(temp_r29_16948, s8 **, 0xDC);
        if (temp_r4_16949 != NULL) {
            M2C_FIELD(temp_r29_16948, s32 *, 0xE0) = (s32) Tools_GetMatchingNodeIndex(this->unk2C, temp_r4_16949);
        } else {
            M2C_FIELD(temp_r29_16948, s32 *, 0xE0) = -1;
        }
        var_r28_16944 += 1;
        var_r31_16945 += 0x1C;
        M2C_FIELD(temp_r29_16948, f32 *, 0xF0) = (f32) (0.017453292f * M2C_FIELD(temp_r29_16948, f32 *, 0xF0));
    } while (var_r28_16944 < 0x11);
}
#endif

#if 0 // DRAFT: function call 'DataMap_GetValue(DataMap *, signed char *)' does not match
s32 SpyroDescriptor::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r28_16996;
    MKIniLine *var_r31_17008;
    SpyroCombatArcDescriptor *temp_r27_17016;
    s32 var_r31_17041;
    u8 var_r28_16988;

    var_r28_16988 = 0;
    if (arg0->IsField("CombatArcs") != 0) {
        var_r28_16996 = arg0->unkC->GetSubLine(arg0);
loop_7:
        if (var_r28_16996 != NULL) {
            if (var_r28_16996->GetFieldName() != NULL) {
                var_r31_17008 = var_r28_16996->unkC->GetSubLine(var_r28_16996);
                temp_r27_17016 = this + ((DataMap_GetValue(&spyroCombatArcDataMap, var_r28_16996->GetFieldName()) * 0x1C) + 0xDC);
loop_5:
                if (var_r31_17008 != NULL) {
                    temp_r27_17016->LoadLine(var_r31_17008);
                    var_r31_17008 = var_r31_17008->unkC->GetNextLine(var_r31_17008);
                    goto loop_5;
                }
            }
            var_r28_16996 = var_r28_16996->unkC->GetNextLine(var_r28_16996);
            goto loop_7;
        }
        var_r28_16988 = 1;
    }
    var_r31_17041 = 0;
    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (var_r28_16988 != 0) || (arg0->LoadFloat("CollectionHeight", &this->unkB8, 0) != 0) || (arg0->LoadFloat("CollectionRadius", &this->unkBC, 0) != 0) || (arg0->LoadFloat("CollectionBroadcastRadius", &this->unkC0, 0) != 0) || (arg0->LoadFloat("CollectionFieldStrength", &this->unkC4, 0) != 0) || (arg0->LoadFloat("AttackMsgBroadcastRadius", &this->unkC8, 0) != 0) || (arg0->LoadString("headSubObjectName", &this->unkCC, 0) != 0) || (arg0->LoadFloat("headTurnSmooth", &this->unkD4, 0) != 0) || (arg0->LoadString("nodePrefix", &this->unkAC, 0) != 0) || (arg0->LoadString("subObjectPrefix", &this->unkB0, 0) != 0) || (arg0->LoadString("refPtPrefix", &this->unkB4, 0) != 0) || (arg0->LoadFloat("MudSlowDown", &this->unkD8, 0) != 0)) {
        var_r31_17041 = 1;
    }
    return var_r31_17041;
}
#endif

void SpyroDescriptor::Init() {
    s32 var_r30_17200;
    s32 var_r31_17194;

    MKPropDescriptor::Init();
    this->unkB8 = 50.0f;
    this->unkBC = 100.0f;
    this->unkC0 = 2000.0f;
    this->unkC4 = 2.0f;
    this->unkC8 = 1500.0f;
    this->unkCC = NULL;
    this->unkD0 = -1;
    this->unkD4 = 5.0f;
    this->unkD8 = 1.0f;
    this->unkC |= 0x60;
    this->unk60.Init();
    this->unk60.unk0 = 100.0f;
    var_r31_17194 = 0;
    this->unk60.unk4 = 100.0f;
    var_r30_17200 = 0;
    this->unk60.unk8 = 7;
    this->unk60.unkC = 1;
    this->unk60.unk10 = 4;
    this->unk60.unk14 = 0;
    this->unk60.unk18 = 0x220;
    this->unk60.unk1C = 0.5f;
    this->unk60.unk20 = 0.5f;
    this->unk60.unk24 = 1;
    this->unk60.unk28 = 0x4000;
    this->unk60.unk2C = 0.8f;
    this->unk60.unk30 = -1.0f;
    this->unk60.unk34 = 1;
    this->unk60.unk38 = 1;
    this->unk60.unk3C = -0.8f;
    this->unk60.unk40 = -1.0f;
    this->unk60.unk44 = 1;
    this->unk60.unk48 = 0;
    this->unkAC = NULL;
    this->unkB0 = NULL;
    this->unkB4 = NULL;
    do {
        ((SpyroCombatArcDescriptor *) (this + (var_r31_17194 + 0xDC)))->Init();
        var_r30_17200 += 1;
        var_r31_17194 += 0x1C;
    } while (var_r30_17200 < 0x11);
}

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 SpyroCombatArcDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_17250;

    var_r31_17250 = 0;
    if ((arg0->LoadString("node", &this->unk0, 0) != 0) || (arg0->LoadFloat("life", &this->unkC, 0) != 0) || (arg0->LoadFloat("radius", &this->unk10, 0) != 0) || (arg0->LoadFloat("arc", &this->unk14, 0) != 0) || (arg0->LoadInt("damage", &this->unk18, 0) != 0) || (arg0->LoadBool("bStayAtSpawnPos", &this->unk8, 0) != 0) || (arg0->LoadBool("bOffsetFwd", &this->unk9, 0) != 0)) {
        var_r31_17250 = 1;
    }
    return var_r31_17250;
}
#endif

void SpyroCombatArcDescriptor::Init() {
    this->unk0 = NULL;
    this->unk4 = -1;
    this->unk8 = 0;
    this->unk9 = 0;
    this->unkC = 0.0f;
    this->unk10 = 0.0f;
    this->unk18 = 3;
    this->unk14 = 180.0f;
}

#if 0 // DRAFT: expression syntax error
void SafePosInfo::SetPos(const MKVector3 &arg0, MKProp *arg1) {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    f32 sp10;

    this->unk10 = arg1;
    if (arg1 != NULL) {
        sp18.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        this->unk0 = sp8;
        sp10 = arg0.unk8 - sp20;
        sp28 = sp8;
        sp30 = (f64) sp10;
        this->unk8 = (f64) sp10;
        return;
    }
    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk8 = (f64) M2C_FIELD(&arg0, f32 *, 8);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
void SafePosInfo::GetPos() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    void *temp_r5_17388;
    void *temp_r5_17391;

    temp_r5_17388 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x10);
    if (temp_r5_17388 != NULL) {
        temp_r5_17391 = M2C_FIELD(temp_r5_17388, void **, 8);
        sp18 = M2C_FIELD(temp_r5_17391, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r5_17391, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        this->unk0 = sp8;
        sp10 = (f32) sp20 + M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 8);
        this->unk8 = (f64) sp10;
        return;
    }
    this->unk0 = *M2C_ERROR(/* Read from unset register $r4 */);
    this->unk8 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 8);
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<Sparx *, Sparx>(Sparx *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SetAnimMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<QueryTriggerCollapsibleMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<QueryHeroMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<QueryDamageTypeMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SetAlphaMessage *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<StableRepositionHero *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<HurtMessage *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<PlatformAttachedQueryMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<TeleportMsg *, MKMessage>(MKMessage *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDCamera *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SpyroDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

#if 0 // DRAFT: undefined identifier 'spC'
void Spyro_cpp::__sinit() {
    f32 sp10;
    MKProp *spC;
    f32 sp8;
    f32 temp_f0_18735;
    f32 temp_f0_18741;
    f64 temp_f2_18715;
    f64 temp_f2_18723;
    f64 temp_f4_18700;
    f64 temp_f5_18714;
    f64 temp_f5_18722;
    f64 temp_f9_18702;

    temp_f4_18700 = __frsqrte(2014000.0);
    temp_f9_18702 = __frsqrte(380000.0);
    temp_f5_18714 = 0.5 * temp_f4_18700 * -((2014000.0 * (temp_f4_18700 * temp_f4_18700)) - 3.0);
    temp_f2_18715 = 0.5 * temp_f9_18702 * -((380000.0 * (temp_f9_18702 * temp_f9_18702)) - 3.0);
    temp_f5_18722 = 0.5 * temp_f5_18714 * -((2014000.0 * (temp_f5_18714 * temp_f5_18714)) - 3.0);
    temp_f2_18723 = 0.5 * temp_f2_18715 * -((380000.0 * (temp_f2_18715 * temp_f2_18715)) - 3.0);
    temp_f0_18735 = (f32) (380000.0 * (0.5 * temp_f2_18723 * -((380000.0 * (temp_f2_18723 * temp_f2_18723)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f5_18722 * -((2014000.0 * (temp_f5_18722 * temp_f5_18722)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_18735;
    temp_f0_18741 = (f32) cos(0.6457718014717102);
    pNodeNames.unk460.unk20.unkC = M2C_FIELD(&__ptmf_null, f32 *, 0);
    pNodeNames.unk460.unk30 = M2C_FIELD(&__ptmf_null, MKProp **, 4);
    pNodeNames.unk460.unk34 = M2C_FIELD(&__ptmf_null, f32 *, 8);
    pNodeNames.unk460.unk38 = M2C_FIELD(&__ptmf_null, f32 *, 0);
    pNodeNames.unk460.unk3C = (s32) M2C_FIELD(&__ptmf_null, MKProp **, 4);
    pNodeNames.unk460.unk40 = M2C_BITWISE(s32, M2C_FIELD(&__ptmf_null, f32 *, 8));
    pNodeNames.unk460.unk44 = M2C_BITWISE(s32, M2C_FIELD(&__ptmf_null, f32 *, 0));
    pNodeNames.unk460.unk48 = (s32) M2C_FIELD(&__ptmf_null, MKProp **, 4);
    M2C_FIELD(&pNodeNames, f32 *, 0x4B4) = (f32) M2C_FIELD(&__ptmf_null, f32 *, 8);
    M2C_FIELD(&pNodeNames, f32 *, 0x4B8) = (f32) pNodeNames.unk430.unk14;
    pNodeNames.unk460.unk54 = pNodeNames.unk430.unk18;
    pNodeNames.unk4C0 = M2C_BITWISE(s32, pNodeNames.unk430.unk1C);
    pNodeNames.unk4C4 = pNodeNames.unk430.unk20;
    pNodeNames.unk4C8 = pNodeNames.unk430.unk24;
    M2C_FIELD(&pNodeNames, void **, 0x4CC) = (void *) pNodeNames.unk430.unk28;
    pNodeNames.unk4D0 = pNodeNames.unk464;
    pNodeNames.unk4D4 = pNodeNames.unk460.unk0;
    M2C_FIELD(&pNodeNames, s32 *, 0x4D8) = (s32) pNodeNames.unk460.unk4;
    pNodeNames.unk4DC = M2C_FIELD(&pNodeNames, s32 *, 0x470);
    pNodeNames.unk4E0 = M2C_FIELD(&pNodeNames, s32 *, 0x474);
    pNodeNames.unk4E4 = pNodeNames.unk460.unk10;
    pNodeNames.unk4E8 = pNodeNames.unk460.unk14;
    pNodeNames.unk4EC = pNodeNames.unk460.unk18;
    pNodeNames.unk4F0 = pNodeNames.unk460.unk1C;
    pNodeNames.unk4F4 = pNodeNames.unk460.unk20.unk0;
    M2C_FIELD(&pNodeNames, Targetable **, 0x4F8) = (Targetable *) pNodeNames.unk460.unk20.unk4;
    pNodeNames.unk4FC = pNodeNames.unk460.unk20.unk8;
    sp8 = M2C_FIELD(&__ptmf_null, f32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, MKProp **, 4);
    sp10 = M2C_FIELD(&__ptmf_null, f32 *, 8);
    maxStandAngle = temp_f0_18741;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetAttackerManager'
void Spyro::lit_76lit_GetAttackerManager() {
    ((Spyro *) (this - 0x4C))->Spyro::GetAttackerManager();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsAttacking'
void Spyro::lit_76lit_IsAttacking() {
    ((Spyro *) (this - 0x4C))->Spyro::IsAttacking();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetTimeLastHit'
void Spyro::lit_76lit_GetTimeLastHit() {
    ((Spyro *) (this - 0x4C))->Spyro::GetTimeLastHit();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetCollisionHeight'
void Spyro::lit_76lit_GetCollisionHeight() {
    ((Spyro *) (this - 0x4C))->Spyro::GetCollisionHeight();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetCollisionRadius'
void Spyro::lit_76lit_GetCollisionRadius() {
    ((Spyro *) (this - 0x4C))->Spyro::GetCollisionRadius();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetCollisionInfo'
void Spyro::lit_76lit_GetCollisionInfo() {
    ((Spyro *) (this - 0x4C))->Spyro::GetCollisionInfo();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetVel'
void Spyro::lit_76lit_GetVel() {
    Spyro::GetVel();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetAimPoint'
void Spyro::lit_76lit_GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Spyro *) (this - 0x4C))->Spyro::GetAimPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetLookToPoint'
void Spyro::lit_76lit_GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Spyro *) (this - 0x4C))->Spyro::GetLookToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetMoveToPoint'
void Spyro::lit_76lit_GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    ((Spyro *) (this - 0x4C))->Spyro::GetMoveToPoint(arg0, arg1);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsDead'
void Spyro::lit_76lit_IsDead() {
    ((Spyro *) (this - 0x4C))->Spyro::IsDead();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsShatterable'
void Spyro::lit_76lit_IsShatterable() {
    ((Spyro *) (this - 0x4C))->Spyro::IsShatterable();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsEnemy'
void Spyro::lit_76lit_IsEnemy() {
    ((Spyro *) (this - 0x4C))->Spyro::IsEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsFriend'
void Spyro::lit_76lit_IsFriend() {
    ((Spyro *) (this - 0x4C))->Spyro::IsFriend();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_IsHero'
void Spyro::lit_76lit_IsHero() {
    ((Spyro *) (this - 0x4C))->Spyro::IsHero();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetEnemy'
void Spyro::lit_76lit_GetEnemy() {
    ((Spyro *) (this - 0x4C))->Spyro::GetEnemy();
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_76lit_GetProp'
void Spyro::lit_76lit_GetProp() {
    ((Spyro *) (this - 0x4C))->Spyro::GetProp();
}
#endif

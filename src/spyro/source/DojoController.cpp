#include "spyro/source/DojoController.h"
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
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/DragonStatue.h"
#include "spyro/source/ElementalWall.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
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
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SparxHint.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SplineProp.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/TriggerObject.h"
#include "spyro/source/TriggerProp.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "spyro/source/InGame.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

extern s32 GS_ButtonPush4;
extern s32 GS_DojoTickTock;
extern s32 GS_DojoWarningBeep;
extern s32 GS_TrainingComplete;
extern s32 GS_TrainingFail;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern s32 gViewSeed;
#if 0 // DRAFT: identifier 'gb' redeclared
extern void **gb;
#endif
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static M2C_UNK lit_761;                                /* unable to generate initializer: unknown type */
static KDStateMachine<DojoController>::State dojoStates; /* unable to generate initializer: confusing struct layout */

static s32 lit_2532 = 0;
#endif
static s32 lit_2534 = 0;
static s32 lit_2536 = 0;
static s32 lit_2555 = 0;
static s32 lit_2557 = 0;
static s32 lit_2559 = 0;
static s32 lit_3055 = 0;
static s32 lit_3057 = 0;
static s32 lit_3059 = 0;

#if 0 // DRAFT: pointer/array required
u8 EarthDojoLesson::HasSucceededFury() {
    DojoController *spC;
    s32 sp8;
    s32 var_r3_52;
    u8 var_r4_41;
    void *temp_r3_39;

    if ((s32) this->unkC == 1) {
        temp_r3_39 = M2C_FIELD(*gb, void *(**)(void **), 0x40)(gb);
        var_r4_41 = 0;
        if (((u8) M2C_FIELD(temp_r3_39, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_39, u8 *, 4) != 0)) {
            var_r4_41 = 1;
        }
        if (var_r4_41 != 0) {
            var_r3_52 = 0;
        } else {
            var_r3_52 = MKInput_Pressed(9, (MKInputDevices) M2C_FIELD(temp_r3_39, s32 *, 0));
        }
        if ((u8) var_r3_52 != 0) {
            DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 1, 0x200);
        }
    }
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            spC = NULL;
            sp8 = 0x163;
            spC = this->unk4;
            InGame_SystemMessage((MKMessage *) &sp8);
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Enemy *' to
u8 EarthDojoLesson::HasSucceededBreath2() {
    s32 spC;
    s32 sp8;
    DojoController *temp_r4_111;
    Targetable *temp_r3_169;
    s32 temp_r3_135;
    s32 var_r0_134;
    s32 var_r0_145;
    s32 var_r0_154;
    u32 *temp_r4_140;

    UpdateCombatArcs();
    if ((s32) this->unk10 == 1) {
        temp_r4_111 = this->unk4;
        if (((u32) temp_r4_111->unk410 != 1) && ((u32) temp_r4_111->unk414 != 1) && ((u32) temp_r4_111->unk418 != 1) && ((u32) temp_r4_111->unk41C != 1) && ((u32) temp_r4_111->unk420 != 1) && ((u32) temp_r4_111->unk424 != 1) && ((u32) temp_r4_111->unk428 != 1)) {
            var_r0_134 = lit_3055;
            temp_r3_135 = temp_r4_111->unk448 - 1;
            if (temp_r3_135 > var_r0_134) {
                var_r0_134 = temp_r3_135;
            }
            temp_r4_140 = &temp_r4_111->unk410;
            if ((u32) temp_r4_140[var_r0_134] != 0x2000) {
                var_r0_145 = lit_3057;
                if (temp_r3_135 > var_r0_145) {
                    var_r0_145 = temp_r3_135;
                }
                if ((u32) temp_r4_140[var_r0_145] != 0x40) {
                    var_r0_154 = lit_3059;
                    if (temp_r3_135 > var_r0_154) {
                        var_r0_154 = temp_r3_135;
                    }
                    if ((u32) temp_r4_140[var_r0_154] == 0x1000) {
                        goto block_17;
                    }
                } else {
                    goto block_17;
                }
            } else {
block_17:
                ((GameGlobals *) &gb)->GetSpyro();
                ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetLastCombatEnemy();
                temp_r3_169 = checked_cast<Enemy *, Targetable>(M2C_ERROR(/* Read from unset register $r3 */));
                if ((temp_r3_169 != NULL) && (((Enemy *) (M2C_FIELD(M2C_FIELD(temp_r3_169, void **, 0x44), Enemy *(**)(), 0xD4)()))->IsKnockedUp() != 0)) {
                    spC = 0;
                    sp8 = 0xE1;
                    M2C_FIELD(M2C_FIELD(temp_r3_169, void **, 0x44), M2C_UNK (**)(Targetable *, s32 *), 0x2C)(temp_r3_169, &sp8);
                }
            }
        }
    }
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            return 1U;
        }
    }
    return 0U;
}
#endif

u8 EarthDojoLesson::HasSucceededBreath1() {
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            return 1U;
        }
    }
    return 0U;
}

u8 EarthDojoLesson::HasSucceededLesson() {
    s32 temp_r0_248;

    temp_r0_248 = this->unk8;
    switch (temp_r0_248) {                          /* irregular */
    case 1:
        return HasSucceededBreath2();
    case 2:
        return HasSucceededFury();
    case 0:
        return HasSucceededBreath1();
    default:
        return 0U;
    }
}

#if 0 // DRAFT: pointer/array required
s32 EarthDojoLesson::HasFailedFury() {
    DojoController *temp_r4_304;

    if ((s32) this->unkC != 0) {
        if (M2C_FIELD(*gb, u8 (**)(void **), 0x70)(gb) != 0) {
            this->unk4->unk3BC = 1;
        }
        this->unk4->unk310.GetNumberActive();
        temp_r4_304 = this->unk4;
        if (((s32) temp_r4_304->unk3D4 != (s32) M2C_ERROR(/* Read from unset register $r3 */)) && ((u8) temp_r4_304->unk3BC == 0)) {
            return 1;
        }
        return 0;
    }
    this->unk4->unk3BC = 0;
    return 0;
}
#endif

s32 EarthDojoLesson::HasFailedBreath2() {
    DojoController *temp_r4_332;

    temp_r4_332 = this->unk4;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_332->unk398) && ((u8) temp_r4_332->unk3BF != 0)) {
        temp_r4_332->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 EarthDojoLesson::HasFailedBreath1() {
    DojoController *temp_r4_355;

    temp_r4_355 = this->unk4;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_355->unk398) && ((u8) temp_r4_355->unk3BF != 0)) {
        temp_r4_355->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 EarthDojoLesson::HasFailedLesson() {
    s32 temp_r0_381;

    temp_r0_381 = this->unk8;
    switch (temp_r0_381) {                          /* irregular */
    case 1:
        return HasFailedBreath2();
    case 2:
        return HasFailedFury();
    case 0:
        return HasFailedBreath1();
    default:
        return 0;
    }
}

s32 EarthDojoLesson::IsFuryComplete() {
    return M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) > 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EarthDojoLesson::SetupFurySpawnPoints() {
    f64 sp138;                                      /* compiler-managed */
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
    MKVector3 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    DojoController *temp_r3_469;
    DojoController *temp_r3_475;
    DojoController *temp_r3_686;
    DojoController *temp_r3_693;
    DojoController *temp_r4_443;
    DojoController *temp_r4_798;
    DojoController *temp_r5_659;
    DojoController *temp_r5_771;
    DojoController *temp_r6_623;
    DojoController *temp_r6_735;
    f32 temp_f28_449;
    f32 temp_f29_593;
    f32 temp_f29_702;
    f32 temp_f30_591;
    f32 temp_f30_703;
    f32 temp_f31_589;
    f32 temp_f31_705;
    f32 var_f3_567;
    f32 var_f4_500;
    f64 temp_f0_462;
    f64 temp_f1_461;
    f64 temp_f1_506;
    f64 temp_f1_512;
    f64 temp_f1_516;
    s32 temp_r3_535;
    s32 temp_r6_668;
    s32 temp_r6_780;
    s32 var_r0_545;
    s32 var_r28_596;
    s32 var_r28_701;
    s32 var_r30_697;
    s32 var_r31_594;
    void *temp_r3_460;
    void *temp_r6_671;
    void *temp_r6_783;

    temp_r4_443 = this->unk4;
    temp_f28_449 = temp_r4_443->unk3B4 * temp_r4_443->unk7E8;
    if (((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get() != NULL) {
        temp_r3_460 = M2C_FIELD(M2C_FIELD(((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get()->__vptr, void *(**)(), 8)(), void **, 8);
        temp_f1_461 = M2C_FIELD(temp_r3_460, f64 *, 0x30);
        temp_f0_462 = M2C_FIELD(temp_r3_460, f64 *, 0x38);
        spF0 = temp_f1_461;
        spF8 = temp_f0_462;
        sp100 = temp_f1_461;
        sp108 = temp_f0_462;
    } else {
        temp_r3_469 = this->unk4;
        sp100 = temp_r3_469->unk388;
        sp108 = temp_r3_469->unk390;
    }
    temp_r3_475 = this->unk4;
    sp50 = M2C_FIELD(temp_r3_475, f64 *, 0x378) - temp_r3_475->unk388;
    sp130 = sp50;
    sp58 = temp_r3_475->unk378.unk8 - (f32) M2C_FIELD(temp_r3_475, f64 *, 0x390);
    sp138 = (f64) sp58;
    spE0 = sp50;
    spE8 = (f64) sp58;
    var_f4_500 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + ((*(f32 *) ((u8 *) &sp128 + 0xc)) * (*(f32 *) ((u8 *) &sp128 + 0xc))));
    if (var_f4_500 > 0.000001f) {
        if (var_f4_500 > 0.0f) {
            temp_f1_506 = __frsqrte(var_f4_500);
            temp_f1_512 = 0.5 * temp_f1_506 * -(((f64) var_f4_500 * (temp_f1_506 * temp_f1_506)) - 3.0);
            temp_f1_516 = 0.5 * temp_f1_512 * -(((f64) var_f4_500 * (temp_f1_512 * temp_f1_512)) - 3.0);
            var_f4_500 = (f32) ((f64) var_f4_500 * (0.5 * temp_f1_516 * -(((f64) var_f4_500 * (temp_f1_516 * temp_f1_516)) - 3.0)));
        } else if (var_f4_500 < M2C_BITWISE(f32, 0.0)) {
            var_f4_500 = __float_nan;
        } else {
            sp8 = var_f4_500;
            temp_r3_535 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_535) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_545 = 1;
                } else {
                    var_r0_545 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_545 = 5;
                } else {
                    var_r0_545 = 3;
                }
                break;
            default:
                var_r0_545 = 4;
                break;
            }
            if (var_r0_545 == 1) {
                var_f4_500 = __float_nan;
            }
        }
        var_f3_567 = 1.0f / var_f4_500;
    } else {
        var_f3_567 = 0.0f;
    }
    sp130 = (f32) sp130 * var_f3_567;
    (*(f32 *) ((u8 *) &sp128 + 0xc)) *= var_f3_567;
    sp138 = (f32) sp138 * var_f3_567;
    if ((s32) this->unk4->unk3C8 != 0) {
        temp_f31_589 = MKVector3::up.unk4;
        temp_f30_591 = MKVector3::up.unk8;
        temp_f29_593 = MKVector3::up.unk0;
        var_r31_594 = 0;
        var_r28_596 = 0;
loop_26:
        temp_r3_686 = this->unk4;
        if (var_r31_594 < (s32) temp_r3_686->unk3C8) {
            sp44 = (temp_f30_591 * sp130) - (temp_f29_593 * sp138);
            sp40 = (temp_f31_589 * sp138) - (temp_f30_591 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp48 = (temp_f29_593 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f31_589 * sp130);
            spD0 = (f64) sp40;
            spD8 = (f64) sp48;
            sp120 = (f64) sp40;
            sp128 = (f64) sp48;
            spB0.operator*(temp_f28_449);
            temp_r6_623 = this->unk4;
            sp30 = M2C_FIELD(temp_r6_623, f64 *, 0x378) + M2C_BITWISE(f64, spB0);
            sp110 = sp30;
            sp38 = temp_r6_623->unk378.unk8 + spB0.unk8;
            spC0 = sp30;
            sp118 = (f64) sp38;
            spC8 = (f64) sp38;
            KDMath_Slerp(spA0, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_623->unk3C8);
            sp130 = M2C_BITWISE(f64, spA0);
            sp138 = (f64) spA0.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_596 + 0x84)), s32 *, 4) = 0x40004200;
            temp_r5_659 = this->unk4;
            temp_r5_659->unk2C0.AddSpawnPoint(temp_r5_659 + (var_r28_596 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_596 + 0x90)))->SetIdentity();
            temp_r6_668 = var_r28_596 + 0x90;
            temp_r6_671 = this->unk4 + temp_r6_668;
            M2C_FIELD(temp_r6_671, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_671, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_671, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_671, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_668))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r31_594 += 1;
            var_r28_596 += 0x60;
            goto loop_26;
        }
        temp_r3_686->unk2C0.AddSpawnPointEnd();
    }
    temp_r3_693 = this->unk4;
    if ((s32) temp_r3_693->unk3CC != 0) {
        var_r30_697 = temp_r3_693->unk3C8;
        var_r28_701 = var_r30_697 * 0x60;
        temp_f29_702 = MKVector3::up.unk4;
        temp_f30_703 = MKVector3::up.unk8;
        temp_f31_705 = MKVector3::up.unk0;
loop_31:
        temp_r4_798 = this->unk4;
        if (var_r30_697 < (s32) (temp_r4_798->unk3C8 + temp_r4_798->unk3CC)) {
            sp24 = (temp_f30_703 * (f32) sp130) - (temp_f31_705 * (f32) sp138);
            sp20 = (temp_f29_702 * (f32) sp138) - (temp_f30_703 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp28 = (temp_f31_705 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f29_702 * (f32) sp130);
            sp90 = (f64) sp20;
            sp98 = (f64) sp28;
            sp120 = (f64) sp20;
            sp128 = (f64) sp28;
            sp70.operator*(temp_f28_449);
            temp_r6_735 = this->unk4;
            sp10 = M2C_FIELD(temp_r6_735, f64 *, 0x378) + M2C_BITWISE(f64, sp70);
            sp110 = sp10;
            sp18 = temp_r6_735->unk378.unk8 + sp70.unk8;
            sp80 = sp10;
            sp118 = (f64) sp18;
            sp88 = (f64) sp18;
            KDMath_Slerp(sp60, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_735->unk3CC);
            sp130 = M2C_BITWISE(f64, sp60);
            sp138 = (f64) sp60.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_701 + 0x84)), s32 *, 4) = 0x40004200;
            temp_r5_771 = this->unk4;
            temp_r5_771->unk310.AddSpawnPoint(temp_r5_771 + (var_r28_701 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_701 + 0x90)))->SetIdentity();
            temp_r6_780 = var_r28_701 + 0x90;
            temp_r6_783 = this->unk4 + temp_r6_780;
            M2C_FIELD(temp_r6_783, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_783, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_783, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_783, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_780))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r30_697 += 1;
            var_r28_701 += 0x60;
            goto loop_31;
        }
        temp_r4_798->unk310.AddSpawnPointEnd();
    }
}
#endif

void EarthDojoLesson::SetupNumFuryEnemies() {
    DojoController *temp_r3_839;
    DojoController *temp_r3_844;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    if ((s32) this->unkC == 0) {
        temp_r3_839 = this->unk4;
        temp_r3_839->unk3C8 = temp_r3_839->unk7E0;
        return;
    }
    temp_r3_844 = this->unk4;
    temp_r3_844->unk3CC = temp_r3_844->unk7E4;
}

s32 EarthDojoLesson::IsBreath2Complete() {
    return this->unk10 > 1;
}

void EarthDojoLesson::SetupBreath2SpawnPoints() {
    CharacterGraphNode *sp8;
    DojoController *temp_r3_881;
    DojoController *temp_r3_893;
    DojoController *temp_r3_907;
    DojoController *temp_r3_919;
    s32 temp_r0_871;

    temp_r0_871 = this->unk10;
    switch (temp_r0_871) {                          /* irregular */
    case 0:
        temp_r3_881 = this->unk4;
        temp_r3_881->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_881->unk3E0, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08000A00U);
        temp_r3_893 = this->unk4;
        temp_r3_893->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_893->unk3E0, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08000A00U);
        return;
    case 1:
        temp_r3_907 = this->unk4;
        temp_r3_907->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_907->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08001200U);
        temp_r3_919 = this->unk4;
        temp_r3_919->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_919->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08001200U);
        return;
    }
}

void EarthDojoLesson::SetupNumBreath2Enemies() {
    DojoController *temp_r3_954;
    DojoController *temp_r3_962;
    DojoController *temp_r4_951;
    DojoController *temp_r4_959;
    s32 temp_r0_945;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_945 = this->unk10;
    switch (temp_r0_945) {                          /* irregular */
    case 0:
        temp_r4_951 = this->unk4;
        temp_r4_951->unk3C8 = temp_r4_951->unk7C8;
        temp_r3_954 = this->unk4;
        temp_r3_954->unk3CC = temp_r3_954->unk7CC;
        return;
    case 1:
        temp_r4_959 = this->unk4;
        temp_r4_959->unk3C8 = temp_r4_959->unk7D4;
        temp_r3_962 = this->unk4;
        temp_r3_962->unk3CC = temp_r3_962->unk7D8;
        return;
    }
}

s32 EarthDojoLesson::IsBreath1Complete() {
    return this->unk10 > 1;
}

void EarthDojoLesson::SetupBreath1SpawnPoints() {
    CharacterGraphNode *sp8;
    DojoController *temp_r3_1011;
    DojoController *temp_r3_1025;
    DojoController *temp_r3_1037;
    DojoController *temp_r3_999;
    s32 temp_r0_989;

    temp_r0_989 = this->unk10;
    switch (temp_r0_989) {                          /* irregular */
    case 0:
        temp_r3_999 = this->unk4;
        temp_r3_999->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_999->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08004200U);
        temp_r3_1011 = this->unk4;
        temp_r3_1011->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_1011->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08004200U);
        return;
    case 1:
        temp_r3_1025 = this->unk4;
        temp_r3_1025->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_1025->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08001200U);
        temp_r3_1037 = this->unk4;
        temp_r3_1037->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_1037->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08001200U);
        return;
    }
}

void EarthDojoLesson::SetupNumBreath1Enemies() {
    DojoController *temp_r3_1072;
    DojoController *temp_r3_1080;
    DojoController *temp_r4_1069;
    DojoController *temp_r4_1077;
    s32 temp_r0_1063;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_1063 = this->unk10;
    switch (temp_r0_1063) {                         /* irregular */
    case 0:
        temp_r4_1069 = this->unk4;
        temp_r4_1069->unk3C8 = temp_r4_1069->unk7B0;
        temp_r3_1072 = this->unk4;
        temp_r3_1072->unk3CC = temp_r3_1072->unk7B4;
        return;
    case 1:
        temp_r4_1077 = this->unk4;
        temp_r4_1077->unk3C8 = temp_r4_1077->unk7BC;
        temp_r3_1080 = this->unk4;
        temp_r3_1080->unk3CC = temp_r3_1080->unk7C0;
        return;
    }
}

void EarthDojoLesson::MakeChildrenInvulnerable() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_1094;

    temp_r0_1094 = this->unk8;
    switch (temp_r0_1094) {                         /* irregular */
    case 1:
        if ((s32) this->unk10 == 0) {
            sp1C = 0;
            sp18 = 0x161;
            this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp18);
            this->unk4->unk310.SendMessageToActive((MKMessage *) &sp18);
            return;
        }
        sp14 = 0;
        sp10 = 0x165;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp10);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp10);
        return;
    case 2:
        spC = 0;
        sp8 = 0x161;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp8);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp8);
        return;
    }
}

void EarthDojoLesson::TurnOffAbilities() {
    s32 temp_r0_1160;

    temp_r0_1160 = this->unk8;
    switch (temp_r0_1160) {                         /* irregular */
    case 0:
        M2C_FIELD(&gb, s8 *, 7) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        M2C_FIELD(&gb, s8 *, 5) = 0;
        return;
    case 1:
        if ((s32) this->unk10 == 0) {
            M2C_FIELD(&gb, s8 *, 5) = 0;
        }
        M2C_FIELD(&gb, s8 *, 6) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    }
}

#if 0 // DRAFT: function call 'DialogBox_ColorButtons(signed char *, signed char *, int,
void EarthDojoLesson::IncrementNumInterations() {
    s8 *sp14;
    s32 spC;
    s32 sp8;
    s32 temp_r0_1201;

    temp_r0_1201 = this->unk8;
    switch (temp_r0_1201) {                         /* irregular */
    case 0:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 1:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 2:
        this->unk4->unk3D0 = 0;
        this->unk4->unk3D4 = 0;
        if ((s32) this->unkC != 0) {
            if (HasSucceededFury() != 0) {
                this->unk10 += 1;
                return;
            }
        } else {
            if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 0, 0x200);
                spC = 0;
                spC = 0;
                sp14 = &this->unk4->unk468;
                sp8 = 0x96;
                InGame_SystemMessage((MKMessage *) &sp8);
                this->unkC = 1;
                return;
            }
            this->unkC = 0;
            return;
        }
        break;
    }
}
#endif

u8 EarthDojoLesson::IsLessonComplete() {
    return (u8) (this->unk8 == 2);
}

s32 EarthDojoLesson::IsSubLessonComplete() {
    s32 temp_r0_1296;

    temp_r0_1296 = this->unk8;
    switch (temp_r0_1296) {                         /* irregular */
    case 1:
        return IsBreath2Complete();
    case 2:
        return EarthDojoLesson::IsFuryComplete();
    case 0:
        return IsBreath1Complete();
    default:
        return 0;
    }
}

void EarthDojoLesson::SetupTimer() {
    DojoController *temp_r4_1473;
    DojoController *temp_r7_1344;
    DojoController *temp_r7_1373;
    DojoController *temp_r7_1408;
    DojoController *temp_r7_1437;
    f32 var_f0_1482;
    s32 temp_r0_1329;
    s32 temp_r0_1345;
    s32 temp_r0_1374;
    s32 temp_r0_1409;
    s32 temp_r0_1438;
    s32 temp_r4_1341;
    s32 temp_r4_1405;

    temp_r0_1329 = this->unk8;
    switch (temp_r0_1329) {                         /* irregular */
    case 0:
        temp_r4_1341 = this->unk10;
        if ((temp_r4_1341 == 0) && (temp_r7_1344 = this->unk4, temp_r0_1345 = temp_r7_1344->unk7B8, ((temp_r0_1345 == 0) == 0))) {
            temp_r7_1344->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_1345 * temp_r7_1344->unk3B8) + (f32) temp_r0_1345);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_1341 == 1) && (temp_r7_1373 = this->unk4, temp_r0_1374 = temp_r7_1373->unk7C4, ((temp_r0_1374 == 0) == 0))) {
            temp_r7_1373->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_1374 * temp_r7_1373->unk3B8) + (f32) temp_r0_1374);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 1:
        temp_r4_1405 = this->unk10;
        if ((temp_r4_1405 == 0) && (temp_r7_1408 = this->unk4, temp_r0_1409 = temp_r7_1408->unk7D0, ((temp_r0_1409 == 0) == 0))) {
            temp_r7_1408->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_1409 * temp_r7_1408->unk3B8) + (f32) temp_r0_1409);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_1405 == 1) && (temp_r7_1437 = this->unk4, temp_r0_1438 = temp_r7_1437->unk7DC, ((temp_r0_1438 == 0) == 0))) {
            temp_r7_1437->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_1438 * temp_r7_1437->unk3B8) + (f32) temp_r0_1438);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 2:
        this->unk4->unk3BF = 0;
        break;
    }
    temp_r4_1473 = this->unk4;
    if ((u8) temp_r4_1473->unk3BF != 0) {
        var_f0_1482 = temp_r4_1473->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
        if (var_f0_1482 > 0.0f) {

        } else {
            var_f0_1482 = 0.0f;
        }
        temp_r4_1473->unk814 = var_f0_1482;
    }
}

void EarthDojoLesson::SetupSpawnPoints() {
    s32 temp_r0_1501;

    temp_r0_1501 = this->unk8;
    switch (temp_r0_1501) {                         /* irregular */
    case 0:
        SetupBreath1SpawnPoints();
        return;
    case 1:
        SetupBreath2SpawnPoints();
        return;
    case 2:
        SetupFurySpawnPoints();
        return;
    }
}

void EarthDojoLesson::SetupNumEnemies() {
    s32 temp_r0_1533;

    temp_r0_1533 = this->unk8;
    switch (temp_r0_1533) {                         /* irregular */
    case 0:
        SetupNumBreath1Enemies();
        return;
    case 1:
        SetupNumBreath2Enemies();
        return;
    case 2:
        SetupNumFuryEnemies();
        return;
    }
}

#if 0 // DRAFT: pointer/array required
u8 IceDojoLesson::HasSucceededFury() {
    DojoController *spC;
    s32 sp8;
    s32 var_r3_1589;
    u8 var_r4_1578;
    void *temp_r3_1576;

    if ((s32) this->unkC == 1) {
        temp_r3_1576 = M2C_FIELD(*gb, void *(**)(void **), 0x40)(gb);
        var_r4_1578 = 0;
        if (((u8) M2C_FIELD(temp_r3_1576, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_1576, u8 *, 4) != 0)) {
            var_r4_1578 = 1;
        }
        if (var_r4_1578 != 0) {
            var_r3_1589 = 0;
        } else {
            var_r3_1589 = MKInput_Pressed(9, (MKInputDevices) M2C_FIELD(temp_r3_1576, s32 *, 0));
        }
        if ((u8) var_r3_1589 != 0) {
            DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 1, 0x200);
        }
    }
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            spC = NULL;
            sp8 = 0x163;
            spC = this->unk4;
            InGame_SystemMessage((MKMessage *) &sp8);
            return 1U;
        }
    }
    return 0U;
}
#endif

u8 IceDojoLesson::HasSucceededBreath2() {
    s32 temp_r0_1644;
    s32 var_r31_1647;
    void *temp_r3_1654;

    temp_r0_1644 = this->unk10;
    switch (temp_r0_1644) {                         /* irregular */
    case 0:
        var_r31_1647 = 0;
loop_6:
        this->unk4->unk2C0.GetNumberActive();
        if (var_r31_1647 >= (s32) M2C_ERROR(/* Read from unset register $r3 */)) {
block_12:
        default:
            return 0U;
        }
        temp_r3_1654 = checked_cast<Enemy *, MKProp>(this->unk4->unk2C0.GetActive(var_r31_1647));
        if ((temp_r3_1654 != NULL) && (M2C_FIELD(temp_r3_1654, s32 *, 0x930) & 4)) {
            this->unk4->unk2C0.DespawnAll();
            this->unk4->unk3D0 = 0;
            this->unk4->unk3D4 = 0;
            this->unk4->ClearCombatArcs();
            return 1U;
        }
        var_r31_1647 += 1;
        goto loop_6;
    case 1:
        this->unk4->unk2C0.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk4->unk310.GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                return 1U;
            }
        }
        goto block_12;
    }
}

u8 IceDojoLesson::HasSucceededBreath1() {
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            return 1U;
        }
    }
    return 0U;
}

u8 IceDojoLesson::HasSucceededLesson() {
    s32 temp_r0_1742;

    temp_r0_1742 = this->unk8;
    switch (temp_r0_1742) {                         /* irregular */
    case 1:
        return HasSucceededBreath2();
    case 2:
        return HasSucceededFury();
    case 0:
        return HasSucceededBreath1();
    default:
        return 0U;
    }
}

#if 0 // DRAFT: pointer/array required
s32 IceDojoLesson::HasFailedFury() {
    DojoController *temp_r4_1798;

    if ((s32) this->unkC != 0) {
        if (M2C_FIELD(*gb, u8 (**)(void **), 0x70)(gb) != 0) {
            this->unk4->unk3BC = 1;
        }
        this->unk4->unk310.GetNumberActive();
        temp_r4_1798 = this->unk4;
        if (((s32) temp_r4_1798->unk3D4 != (s32) M2C_ERROR(/* Read from unset register $r3 */)) && ((u8) temp_r4_1798->unk3BC == 0)) {
            return 1;
        }
        return 0;
    }
    this->unk4->unk3BC = 0;
    return 0;
}
#endif

s32 IceDojoLesson::HasFailedBreath2() {
    DojoController *temp_r4_1826;

    temp_r4_1826 = this->unk4;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_1826->unk398) && ((u8) temp_r4_1826->unk3BF != 0)) {
        temp_r4_1826->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 IceDojoLesson::HasFailedBreath1() {
    DojoController *temp_r4_1849;

    temp_r4_1849 = this->unk4;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_1849->unk398) && ((u8) temp_r4_1849->unk3BF != 0)) {
        temp_r4_1849->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 IceDojoLesson::HasFailedLesson() {
    s32 temp_r0_1875;

    temp_r0_1875 = this->unk8;
    switch (temp_r0_1875) {                         /* irregular */
    case 1:
        return HasFailedBreath2();
    case 2:
        return HasFailedFury();
    case 0:
        return HasFailedBreath1();
    default:
        return 0;
    }
}

s32 IceDojoLesson::IsFuryComplete() {
    return M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) > 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void IceDojoLesson::SetupFurySpawnPoints() {
    f64 sp138;                                      /* compiler-managed */
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
    MKVector3 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    DojoController *temp_r3_1963;
    DojoController *temp_r3_1969;
    DojoController *temp_r3_2180;
    DojoController *temp_r3_2187;
    DojoController *temp_r4_1937;
    DojoController *temp_r4_2292;
    DojoController *temp_r5_2153;
    DojoController *temp_r5_2265;
    DojoController *temp_r6_2117;
    DojoController *temp_r6_2229;
    f32 temp_f28_1943;
    f32 temp_f29_2087;
    f32 temp_f29_2196;
    f32 temp_f30_2085;
    f32 temp_f30_2197;
    f32 temp_f31_2083;
    f32 temp_f31_2199;
    f32 var_f3_2061;
    f32 var_f4_1994;
    f64 temp_f0_1956;
    f64 temp_f1_1955;
    f64 temp_f1_2000;
    f64 temp_f1_2006;
    f64 temp_f1_2010;
    s32 temp_r3_2029;
    s32 temp_r6_2162;
    s32 temp_r6_2274;
    s32 var_r0_2039;
    s32 var_r28_2090;
    s32 var_r28_2195;
    s32 var_r30_2191;
    s32 var_r31_2088;
    void *temp_r3_1954;
    void *temp_r6_2165;
    void *temp_r6_2277;

    temp_r4_1937 = this->unk4;
    temp_f28_1943 = temp_r4_1937->unk3B4 * temp_r4_1937->unk7AC;
    if (((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get() != NULL) {
        temp_r3_1954 = M2C_FIELD(M2C_FIELD(((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get()->__vptr, void *(**)(), 8)(), void **, 8);
        temp_f1_1955 = M2C_FIELD(temp_r3_1954, f64 *, 0x30);
        temp_f0_1956 = M2C_FIELD(temp_r3_1954, f64 *, 0x38);
        spF0 = temp_f1_1955;
        spF8 = temp_f0_1956;
        sp100 = temp_f1_1955;
        sp108 = temp_f0_1956;
    } else {
        temp_r3_1963 = this->unk4;
        sp100 = temp_r3_1963->unk388;
        sp108 = temp_r3_1963->unk390;
    }
    temp_r3_1969 = this->unk4;
    sp50 = M2C_FIELD(temp_r3_1969, f64 *, 0x378) - temp_r3_1969->unk388;
    sp130 = sp50;
    sp58 = temp_r3_1969->unk378.unk8 - (f32) M2C_FIELD(temp_r3_1969, f64 *, 0x390);
    sp138 = (f64) sp58;
    spE0 = sp50;
    spE8 = (f64) sp58;
    var_f4_1994 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + ((*(f32 *) ((u8 *) &sp128 + 0xc)) * (*(f32 *) ((u8 *) &sp128 + 0xc))));
    if (var_f4_1994 > 0.000001f) {
        if (var_f4_1994 > 0.0f) {
            temp_f1_2000 = __frsqrte(var_f4_1994);
            temp_f1_2006 = 0.5 * temp_f1_2000 * -(((f64) var_f4_1994 * (temp_f1_2000 * temp_f1_2000)) - 3.0);
            temp_f1_2010 = 0.5 * temp_f1_2006 * -(((f64) var_f4_1994 * (temp_f1_2006 * temp_f1_2006)) - 3.0);
            var_f4_1994 = (f32) ((f64) var_f4_1994 * (0.5 * temp_f1_2010 * -(((f64) var_f4_1994 * (temp_f1_2010 * temp_f1_2010)) - 3.0)));
        } else if (var_f4_1994 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1994 = __float_nan;
        } else {
            sp8 = var_f4_1994;
            temp_r3_2029 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_2029) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2039 = 1;
                } else {
                    var_r0_2039 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2039 = 5;
                } else {
                    var_r0_2039 = 3;
                }
                break;
            default:
                var_r0_2039 = 4;
                break;
            }
            if (var_r0_2039 == 1) {
                var_f4_1994 = __float_nan;
            }
        }
        var_f3_2061 = 1.0f / var_f4_1994;
    } else {
        var_f3_2061 = 0.0f;
    }
    sp130 = (f32) sp130 * var_f3_2061;
    (*(f32 *) ((u8 *) &sp128 + 0xc)) *= var_f3_2061;
    sp138 = (f32) sp138 * var_f3_2061;
    if ((s32) this->unk4->unk3C8 != 0) {
        temp_f31_2083 = MKVector3::up.unk4;
        temp_f30_2085 = MKVector3::up.unk8;
        temp_f29_2087 = MKVector3::up.unk0;
        var_r31_2088 = 0;
        var_r28_2090 = 0;
loop_26:
        temp_r3_2180 = this->unk4;
        if (var_r31_2088 < (s32) temp_r3_2180->unk3C8) {
            sp44 = (temp_f30_2085 * sp130) - (temp_f29_2087 * sp138);
            sp40 = (temp_f31_2083 * sp138) - (temp_f30_2085 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp48 = (temp_f29_2087 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f31_2083 * sp130);
            spD0 = (f64) sp40;
            spD8 = (f64) sp48;
            sp120 = (f64) sp40;
            sp128 = (f64) sp48;
            spB0.operator*(temp_f28_1943);
            temp_r6_2117 = this->unk4;
            sp30 = M2C_FIELD(temp_r6_2117, f64 *, 0x378) + M2C_BITWISE(f64, spB0);
            sp110 = sp30;
            sp38 = temp_r6_2117->unk378.unk8 + spB0.unk8;
            spC0 = sp30;
            sp118 = (f64) sp38;
            spC8 = (f64) sp38;
            KDMath_Slerp(spA0, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_2117->unk3C8);
            sp130 = M2C_BITWISE(f64, spA0);
            sp138 = (f64) spA0.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_2090 + 0x84)), s32 *, 4) = 0x10004200;
            temp_r5_2153 = this->unk4;
            temp_r5_2153->unk2C0.AddSpawnPoint(temp_r5_2153 + (var_r28_2090 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_2090 + 0x90)))->SetIdentity();
            temp_r6_2162 = var_r28_2090 + 0x90;
            temp_r6_2165 = this->unk4 + temp_r6_2162;
            M2C_FIELD(temp_r6_2165, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_2165, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_2165, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_2165, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_2162))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r31_2088 += 1;
            var_r28_2090 += 0x60;
            goto loop_26;
        }
        temp_r3_2180->unk2C0.AddSpawnPointEnd();
    }
    temp_r3_2187 = this->unk4;
    if ((s32) temp_r3_2187->unk3CC != 0) {
        var_r30_2191 = temp_r3_2187->unk3C8;
        var_r28_2195 = var_r30_2191 * 0x60;
        temp_f29_2196 = MKVector3::up.unk4;
        temp_f30_2197 = MKVector3::up.unk8;
        temp_f31_2199 = MKVector3::up.unk0;
loop_31:
        temp_r4_2292 = this->unk4;
        if (var_r30_2191 < (s32) (temp_r4_2292->unk3C8 + temp_r4_2292->unk3CC)) {
            sp24 = (temp_f30_2197 * (f32) sp130) - (temp_f31_2199 * (f32) sp138);
            sp20 = (temp_f29_2196 * (f32) sp138) - (temp_f30_2197 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp28 = (temp_f31_2199 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f29_2196 * (f32) sp130);
            sp90 = (f64) sp20;
            sp98 = (f64) sp28;
            sp120 = (f64) sp20;
            sp128 = (f64) sp28;
            sp70.operator*(temp_f28_1943);
            temp_r6_2229 = this->unk4;
            sp10 = M2C_FIELD(temp_r6_2229, f64 *, 0x378) + M2C_BITWISE(f64, sp70);
            sp110 = sp10;
            sp18 = temp_r6_2229->unk378.unk8 + sp70.unk8;
            sp80 = sp10;
            sp118 = (f64) sp18;
            sp88 = (f64) sp18;
            KDMath_Slerp(sp60, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_2229->unk3CC);
            sp130 = M2C_BITWISE(f64, sp60);
            sp138 = (f64) sp60.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_2195 + 0x84)), s32 *, 4) = 0x10004200;
            temp_r5_2265 = this->unk4;
            temp_r5_2265->unk310.AddSpawnPoint(temp_r5_2265 + (var_r28_2195 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_2195 + 0x90)))->SetIdentity();
            temp_r6_2274 = var_r28_2195 + 0x90;
            temp_r6_2277 = this->unk4 + temp_r6_2274;
            M2C_FIELD(temp_r6_2277, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_2277, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_2277, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_2277, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_2274))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r30_2191 += 1;
            var_r28_2195 += 0x60;
            goto loop_31;
        }
        temp_r4_2292->unk310.AddSpawnPointEnd();
    }
}
#endif

void IceDojoLesson::SetupNumFuryEnemies() {
    DojoController *temp_r3_2333;
    DojoController *temp_r3_2338;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    if ((s32) this->unkC == 0) {
        temp_r3_2333 = this->unk4;
        temp_r3_2333->unk3C8 = temp_r3_2333->unk7A4;
        return;
    }
    temp_r3_2338 = this->unk4;
    temp_r3_2338->unk3CC = temp_r3_2338->unk7A8;
}

s32 IceDojoLesson::IsBreath2Complete() {
    return this->unk10 > 1;
}

void IceDojoLesson::SetupBreath2SpawnPoints() {
    CharacterGraphNode *sp8;
    DojoController *temp_r3_2415;
    DojoController *temp_r3_2426;
    DojoController *temp_r3_2439;
    DojoController *temp_r3_2450;
    DojoController *temp_r3_2463;
    DojoController *temp_r3_2474;
    DojoController *temp_r3_2487;
    DojoController *temp_r3_2499;
    f32 temp_f31_2389;
    s32 temp_r0_2367;
    s32 temp_r3_2401;
    u32 var_r31_2393;

    temp_r0_2367 = this->unk10;
    switch (temp_r0_2367) {                         /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_f31_2389 = (f32) this->unkC / 9.0f;
        if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > temp_f31_2389) {
            var_r31_2393 = 0x10000200 | 0x800000;
        } else {
            var_r31_2393 = 0x10000200 | 0x800;
        }
        temp_r3_2401 = MKRand_Int((int *) &gViewSeed, 0, 2);
        switch (temp_r3_2401) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            temp_r3_2415 = this->unk4;
            temp_r3_2415->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_2415->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, var_r31_2393);
            temp_r3_2426 = this->unk4;
            temp_r3_2426->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_2426->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, var_r31_2393);
            return;
        case 1:                                     /* switch 2 */
            temp_r3_2439 = this->unk4;
            temp_r3_2439->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_2439->unk3E0, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, var_r31_2393);
            temp_r3_2450 = this->unk4;
            temp_r3_2450->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_2450->unk3E0, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, var_r31_2393);
            return;
        case 2:                                     /* switch 2 */
            temp_r3_2463 = this->unk4;
            temp_r3_2463->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_2463->unk3DC, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, var_r31_2393);
            temp_r3_2474 = this->unk4;
            temp_r3_2474->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_2474->unk3DC, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, var_r31_2393);
            return;
        }
        break;
    case 1:                                         /* switch 1 */
        temp_r3_2487 = this->unk4;
        temp_r3_2487->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_2487->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x10001200U);
        temp_r3_2499 = this->unk4;
        temp_r3_2499->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_2499->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x10001200U);
        break;
    }
}

void IceDojoLesson::SetupNumBreath2Enemies() {
    DojoController *temp_r3_2536;
    DojoController *temp_r3_2544;
    DojoController *temp_r4_2533;
    DojoController *temp_r4_2541;
    s32 temp_r0_2527;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_2527 = this->unk10;
    switch (temp_r0_2527) {                         /* irregular */
    case 0:
        temp_r4_2533 = this->unk4;
        temp_r4_2533->unk3C8 = temp_r4_2533->unk784;
        temp_r3_2536 = this->unk4;
        temp_r3_2536->unk3CC = temp_r3_2536->unk788;
        return;
    case 1:
        temp_r4_2541 = this->unk4;
        temp_r4_2541->unk3C8 = temp_r4_2541->unk790;
        temp_r3_2544 = this->unk4;
        temp_r3_2544->unk3CC = temp_r3_2544->unk794;
        return;
    }
}

s32 IceDojoLesson::IsBreath1Complete() {
    return this->unk10 > 1;
}

void IceDojoLesson::SetupBreath1SpawnPoints() {
    CharacterGraphNode *sp8;
    DojoController *temp_r3_2581;
    DojoController *temp_r3_2593;
    DojoController *temp_r3_2607;
    DojoController *temp_r3_2619;
    s32 temp_r0_2571;

    temp_r0_2571 = this->unk10;
    switch (temp_r0_2571) {                         /* irregular */
    case 0:
        temp_r3_2581 = this->unk4;
        temp_r3_2581->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_2581->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x10004200U);
        temp_r3_2593 = this->unk4;
        temp_r3_2593->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_2593->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x10004200U);
        return;
    case 1:
        temp_r3_2607 = this->unk4;
        temp_r3_2607->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_2607->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x10001200U);
        temp_r3_2619 = this->unk4;
        temp_r3_2619->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_2619->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x10001200U);
        return;
    }
}

void IceDojoLesson::SetupNumBreath1Enemies() {
    DojoController *temp_r3_2654;
    DojoController *temp_r3_2662;
    DojoController *temp_r4_2651;
    DojoController *temp_r4_2659;
    s32 temp_r0_2645;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_2645 = this->unk10;
    switch (temp_r0_2645) {                         /* irregular */
    case 0:
        temp_r4_2651 = this->unk4;
        temp_r4_2651->unk3C8 = temp_r4_2651->unk76C;
        temp_r3_2654 = this->unk4;
        temp_r3_2654->unk3CC = temp_r3_2654->unk770;
        return;
    case 1:
        temp_r4_2659 = this->unk4;
        temp_r4_2659->unk3C8 = temp_r4_2659->unk778;
        temp_r3_2662 = this->unk4;
        temp_r3_2662->unk3CC = temp_r3_2662->unk77C;
        return;
    }
}

void IceDojoLesson::MakeChildrenInvulnerable() {
    s32 spC;
    s32 sp8;
    s32 temp_r0_2676;

    temp_r0_2676 = this->unk8;
    if (temp_r0_2676 < 3) {
        if (temp_r0_2676 < 0) {
            return;
        }
        spC = 0;
        sp8 = 0x161;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp8);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp8);
    }
}

void IceDojoLesson::TurnOffAbilities() {
    s32 temp_r0_2706;

    temp_r0_2706 = this->unk8;
    switch (temp_r0_2706) {                         /* irregular */
    case 0:
        M2C_FIELD(&gb, s8 *, 7) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    case 1:
        if ((s32) this->unk10 == 0) {
            M2C_FIELD(&gb, s8 *, 5) = 0;
        }
        M2C_FIELD(&gb, s8 *, 6) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    }
}

#if 0 // DRAFT: function call 'DialogBox_ColorButtons(signed char *, signed char *, int,
void IceDojoLesson::IncrementNumInterations() {
    s8 *sp14;
    s32 spC;
    s32 sp8;
    s32 temp_r0_2746;
    s32 temp_r4_2769;

    temp_r0_2746 = this->unk8;
    switch (temp_r0_2746) {                         /* irregular */
    case 0:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 1:
        if ((s32) this->unk10 == 0) {
            temp_r4_2769 = this->unkC;
            if (temp_r4_2769 < (s32) (this->unk4->unk7A0 - 1)) {
                this->unkC = temp_r4_2769 + 1;
                return;
            }
            this->unkC = 0;
            this->unk10 += 1;
            return;
        }
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 2:
        this->unk4->unk3D0 = 0;
        this->unk4->unk3D4 = 0;
        if ((s32) this->unkC != 0) {
            if (HasSucceededFury() != 0) {
                this->unk10 += 1;
                return;
            }
        } else {
            if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 0, 0x200);
                spC = 0;
                spC = 0;
                sp14 = &this->unk4->unk468;
                sp8 = 0x96;
                InGame_SystemMessage((MKMessage *) &sp8);
                this->unkC = 1;
                return;
            }
            this->unkC = 0;
            return;
        }
        break;
    }
}
#endif

u8 IceDojoLesson::IsLessonComplete() {
    return (u8) (this->unk8 == 2);
}

s32 IceDojoLesson::IsSubLessonComplete() {
    s32 temp_r0_2861;

    temp_r0_2861 = this->unk8;
    switch (temp_r0_2861) {                         /* irregular */
    case 1:
        return IsBreath2Complete();
    case 2:
        return IceDojoLesson::IsFuryComplete();
    case 0:
        return IsBreath1Complete();
    default:
        return 0;
    }
}

void IceDojoLesson::SetupTimer() {
    DojoController *temp_r4_3040;
    DojoController *temp_r7_2909;
    DojoController *temp_r7_2938;
    DojoController *temp_r7_2973;
    DojoController *temp_r7_3002;
    f32 var_f0_3049;
    s32 temp_r0_2894;
    s32 temp_r0_2910;
    s32 temp_r0_2939;
    s32 temp_r0_2974;
    s32 temp_r4_2906;
    s32 temp_r4_2970;
    s32 temp_r4_3003;

    temp_r0_2894 = this->unk8;
    switch (temp_r0_2894) {                         /* irregular */
    case 0:
        temp_r4_2906 = this->unk10;
        if ((temp_r4_2906 == 0) && (temp_r7_2909 = this->unk4, temp_r0_2910 = temp_r7_2909->unk774, ((temp_r0_2910 == 0) == 0))) {
            temp_r7_2909->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_2910 * temp_r7_2909->unk3B8) + (f32) temp_r0_2910);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_2906 == 1) && (temp_r7_2938 = this->unk4, temp_r0_2939 = temp_r7_2938->unk780, ((temp_r0_2939 == 0) == 0))) {
            temp_r7_2938->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_2939 * temp_r7_2938->unk3B8) + (f32) temp_r0_2939);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 1:
        temp_r4_2970 = this->unk10;
        if ((temp_r4_2970 == 0) && (temp_r7_2973 = this->unk4, temp_r0_2974 = temp_r7_2973->unk78C, ((temp_r0_2974 == 0) == 0))) {
            temp_r7_2973->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_2974 * temp_r7_2973->unk3B8) + (f32) temp_r0_2974);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_2970 == 1) && (temp_r7_3002 = this->unk4, temp_r4_3003 = temp_r7_3002->unk798, ((temp_r4_3003 == 0) == 0))) {
            temp_r7_3002->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r7_3002->unk78C * temp_r7_3002->unk3B8) + (f32) temp_r4_3003);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 2:
        this->unk4->unk3BF = 0;
        break;
    }
    temp_r4_3040 = this->unk4;
    if ((u8) temp_r4_3040->unk3BF != 0) {
        var_f0_3049 = temp_r4_3040->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
        if (var_f0_3049 > 0.0f) {

        } else {
            var_f0_3049 = 0.0f;
        }
        temp_r4_3040->unk814 = var_f0_3049;
    }
}

void IceDojoLesson::SetupSpawnPoints() {
    s32 temp_r0_3068;

    temp_r0_3068 = this->unk8;
    switch (temp_r0_3068) {                         /* irregular */
    case 0:
        SetupBreath1SpawnPoints();
        return;
    case 1:
        SetupBreath2SpawnPoints();
        return;
    case 2:
        SetupFurySpawnPoints();
        return;
    }
}

void IceDojoLesson::SetupNumEnemies() {
    s32 temp_r0_3100;

    temp_r0_3100 = this->unk8;
    switch (temp_r0_3100) {                         /* irregular */
    case 0:
        SetupNumBreath1Enemies();
        return;
    case 1:
        SetupNumBreath2Enemies();
        return;
    case 2:
        SetupNumFuryEnemies();
        return;
    }
}

#if 0 // DRAFT: pointer/array required
u8 ElectricDojoLesson::HasSucceededFury() {
    DojoController *spC;
    s32 sp8;
    s32 var_r3_3156;
    u8 var_r4_3145;
    void *temp_r3_3143;

    if ((s32) this->unkC == 1) {
        temp_r3_3143 = M2C_FIELD(*gb, void *(**)(void **), 0x40)(gb);
        var_r4_3145 = 0;
        if (((u8) M2C_FIELD(temp_r3_3143, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_3143, u8 *, 4) != 0)) {
            var_r4_3145 = 1;
        }
        if (var_r4_3145 != 0) {
            var_r3_3156 = 0;
        } else {
            var_r3_3156 = MKInput_Pressed(9, (MKInputDevices) M2C_FIELD(temp_r3_3143, s32 *, 0));
        }
        if ((u8) var_r3_3156 != 0) {
            DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 1, 0x200);
        }
    }
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            spC = NULL;
            sp8 = 0x163;
            spC = this->unk4;
            InGame_SystemMessage((MKMessage *) &sp8);
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: pointer/array required
u8 ElectricDojoLesson::HasSucceededBreath2() {
    s32 spC;
    s32 sp8;
    DojoController *temp_r4_3215;
    DojoController *temp_r4_3289;
    Targetable *temp_r3_3347;
    s32 temp_r0_3212;
    s32 temp_r3_3239;
    s32 temp_r3_3313;
    s32 var_r0_3238;
    s32 var_r0_3249;
    s32 var_r0_3258;
    s32 var_r0_3312;
    s32 var_r0_3323;
    s32 var_r0_3332;
    u32 *temp_r4_3244;
    u32 *temp_r4_3318;

    UpdateCombatArcs();
    temp_r0_3212 = this->unk10;
    switch (temp_r0_3212) {                         /* irregular */
    case 0:
        temp_r4_3215 = this->unk4;
        if (((u32) temp_r4_3215->unk410 != 1) && ((u32) temp_r4_3215->unk414 != 1) && ((u32) temp_r4_3215->unk418 != 1) && ((u32) temp_r4_3215->unk41C != 1) && ((u32) temp_r4_3215->unk420 != 1) && ((u32) temp_r4_3215->unk424 != 1) && ((u32) temp_r4_3215->unk428 != 1)) {
            var_r0_3238 = lit_2532;
            temp_r3_3239 = temp_r4_3215->unk448 - 1;
            if (temp_r3_3239 > var_r0_3238) {
                var_r0_3238 = temp_r3_3239;
            }
            temp_r4_3244 = &temp_r4_3215->unk410;
            if ((u32) temp_r4_3244[var_r0_3238] != 0x2000) {
                var_r0_3249 = lit_2534;
                if (temp_r3_3239 > var_r0_3249) {
                    var_r0_3249 = temp_r3_3239;
                }
                if ((u32) temp_r4_3244[var_r0_3249] != 0x40) {
                    var_r0_3258 = lit_2536;
                    if (temp_r3_3239 > var_r0_3258) {
                        var_r0_3258 = temp_r3_3239;
                    }
                    if ((u32) temp_r4_3244[var_r0_3258] == 0x1000) {
                        goto block_17;
                    }
                    goto block_43;
                }
                goto block_17;
            }
block_17:
            ((GameGlobals *) &gb)->GetSpyro();
            ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetLastCombatEnemy();
            if (((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) && (((Enemy *) (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), Enemy *(**)(), 0xC)()))->IsKnockedUp() != 0)) {
                this->unk4->ClearCombatArcs();
                return 1U;
            }
            goto block_43;
        }
block_43:
    default:
        return 0U;
    case 1:
        temp_r4_3289 = this->unk4;
        if (((u32) temp_r4_3289->unk410 != 1) && ((u32) temp_r4_3289->unk414 != 1) && ((u32) temp_r4_3289->unk418 != 1) && ((u32) temp_r4_3289->unk41C != 1) && ((u32) temp_r4_3289->unk420 != 1) && ((u32) temp_r4_3289->unk424 != 1) && ((u32) temp_r4_3289->unk428 != 1)) {
            var_r0_3312 = lit_2555;
            temp_r3_3313 = temp_r4_3289->unk448 - 1;
            if (temp_r3_3313 > var_r0_3312) {
                var_r0_3312 = temp_r3_3313;
            }
            temp_r4_3318 = &temp_r4_3289->unk410;
            if ((u32) temp_r4_3318[var_r0_3312] != 0x2000) {
                var_r0_3323 = lit_2557;
                if (temp_r3_3313 > var_r0_3323) {
                    var_r0_3323 = temp_r3_3313;
                }
                if ((u32) temp_r4_3318[var_r0_3323] != 0x40) {
                    var_r0_3332 = lit_2559;
                    if (temp_r3_3313 > var_r0_3332) {
                        var_r0_3332 = temp_r3_3313;
                    }
                    if ((u32) temp_r4_3318[var_r0_3332] == 0x1000) {
                        goto block_37;
                    }
                } else {
                    goto block_37;
                }
            } else {
block_37:
                ((GameGlobals *) &gb)->GetSpyro();
                ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetLastCombatEnemy();
                temp_r3_3347 = checked_cast<Enemy *, Targetable>(M2C_ERROR(/* Read from unset register $r3 */));
                if ((temp_r3_3347 != NULL) && (((Enemy *) (M2C_FIELD(M2C_FIELD(temp_r3_3347, void **, 0x44), Enemy *(**)(), 0xD4)()))->IsKnockedUp() != 0)) {
                    spC = 0;
                    sp8 = 0xE1;
                    M2C_FIELD(M2C_FIELD(temp_r3_3347, void **, 0x44), M2C_UNK (**)(Targetable *, s32 *), 0x2C)(temp_r3_3347, &sp8);
                }
            }
        }
        this->unk4->unk2C0.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk4->unk310.GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                return 1U;
            }
        }
        goto block_43;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'DojoController' to
u8 ElectricDojoLesson::HasSucceededBreath1() {
    s32 var_ctr_3404;
    s32 var_r4_3403;

    if ((s32) this->unk10 == 0) {
        var_r4_3403 = 0;
        var_ctr_3404 = 4;
loop_2:
        if ((s32) M2C_FIELD(*(this->unk4 + (var_r4_3403 + 0x3F4)), s32 *, 0x17C) != 3) {
            return 0U;
        }
        var_r4_3403 += 4;
        var_ctr_3404 -= 1;
        if (var_ctr_3404 == 0) {
            return 1U;
        }
        goto loop_2;
    }
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            return 1U;
        }
    }
    return 0U;
}
#endif

u8 ElectricDojoLesson::HasSucceededLesson() {
    s32 temp_r0_3447;

    temp_r0_3447 = this->unk8;
    switch (temp_r0_3447) {                         /* irregular */
    case 1:
        return HasSucceededBreath2();
    case 2:
        return HasSucceededFury();
    case 0:
        return HasSucceededBreath1();
    default:
        return 0U;
    }
}

#if 0 // DRAFT: pointer/array required
s32 ElectricDojoLesson::HasFailedFury() {
    DojoController *temp_r4_3503;

    if ((s32) this->unkC != 0) {
        if (M2C_FIELD(*gb, u8 (**)(void **), 0x70)(gb) != 0) {
            this->unk4->unk3BC = 1;
        }
        this->unk4->unk310.GetNumberActive();
        temp_r4_3503 = this->unk4;
        if (((s32) temp_r4_3503->unk3D4 != (s32) M2C_ERROR(/* Read from unset register $r3 */)) && ((u8) temp_r4_3503->unk3BC == 0)) {
            return 1;
        }
        return 0;
    }
    this->unk4->unk3BC = 0;
    return 0;
}
#endif

s32 ElectricDojoLesson::HasFailedBreath2() {
    DojoController *temp_r4_3531;

    temp_r4_3531 = this->unk4;
    if (((u8) temp_r4_3531->unk3BF != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_3531->unk398)) {
        temp_r4_3531->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 ElectricDojoLesson::HasFailedBreath1() {
    DojoController *temp_r4_3554;

    temp_r4_3554 = this->unk4;
    if (((u8) temp_r4_3554->unk3BF != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_3554->unk398)) {
        temp_r4_3554->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 ElectricDojoLesson::HasFailedLesson() {
    s32 temp_r0_3580;

    temp_r0_3580 = this->unk8;
    switch (temp_r0_3580) {                         /* irregular */
    case 1:
        return HasFailedBreath2();
    case 2:
        return HasFailedFury();
    case 0:
        return HasFailedBreath1();
    default:
        return 0;
    }
}

s32 ElectricDojoLesson::IsFuryComplete() {
    return M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) > 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void ElectricDojoLesson::SetupFurySpawnPoints() {
    f64 sp138;                                      /* compiler-managed */
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
    MKVector3 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    DojoController *temp_r3_3668;
    DojoController *temp_r3_3674;
    DojoController *temp_r3_3885;
    DojoController *temp_r3_3892;
    DojoController *temp_r4_3642;
    DojoController *temp_r4_3997;
    DojoController *temp_r5_3858;
    DojoController *temp_r5_3970;
    DojoController *temp_r6_3822;
    DojoController *temp_r6_3934;
    f32 temp_f28_3648;
    f32 temp_f29_3792;
    f32 temp_f29_3901;
    f32 temp_f30_3790;
    f32 temp_f30_3902;
    f32 temp_f31_3788;
    f32 temp_f31_3904;
    f32 var_f3_3766;
    f32 var_f4_3699;
    f64 temp_f0_3661;
    f64 temp_f1_3660;
    f64 temp_f1_3705;
    f64 temp_f1_3711;
    f64 temp_f1_3715;
    s32 temp_r3_3734;
    s32 temp_r6_3867;
    s32 temp_r6_3979;
    s32 var_r0_3744;
    s32 var_r28_3795;
    s32 var_r28_3900;
    s32 var_r30_3896;
    s32 var_r31_3793;
    void *temp_r3_3659;
    void *temp_r6_3870;
    void *temp_r6_3982;

    temp_r4_3642 = this->unk4;
    temp_f28_3648 = temp_r4_3642->unk3B4 * temp_r4_3642->unk768;
    if (((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get() != NULL) {
        temp_r3_3659 = M2C_FIELD(M2C_FIELD(((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get()->__vptr, void *(**)(), 8)(), void **, 8);
        temp_f1_3660 = M2C_FIELD(temp_r3_3659, f64 *, 0x30);
        temp_f0_3661 = M2C_FIELD(temp_r3_3659, f64 *, 0x38);
        spF0 = temp_f1_3660;
        spF8 = temp_f0_3661;
        sp100 = temp_f1_3660;
        sp108 = temp_f0_3661;
    } else {
        temp_r3_3668 = this->unk4;
        sp100 = temp_r3_3668->unk388;
        sp108 = temp_r3_3668->unk390;
    }
    temp_r3_3674 = this->unk4;
    sp50 = M2C_FIELD(temp_r3_3674, f64 *, 0x378) - temp_r3_3674->unk388;
    sp130 = sp50;
    sp58 = temp_r3_3674->unk378.unk8 - (f32) M2C_FIELD(temp_r3_3674, f64 *, 0x390);
    sp138 = (f64) sp58;
    spE0 = sp50;
    spE8 = (f64) sp58;
    var_f4_3699 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + ((*(f32 *) ((u8 *) &sp128 + 0xc)) * (*(f32 *) ((u8 *) &sp128 + 0xc))));
    if (var_f4_3699 > 0.000001f) {
        if (var_f4_3699 > 0.0f) {
            temp_f1_3705 = __frsqrte(var_f4_3699);
            temp_f1_3711 = 0.5 * temp_f1_3705 * -(((f64) var_f4_3699 * (temp_f1_3705 * temp_f1_3705)) - 3.0);
            temp_f1_3715 = 0.5 * temp_f1_3711 * -(((f64) var_f4_3699 * (temp_f1_3711 * temp_f1_3711)) - 3.0);
            var_f4_3699 = (f32) ((f64) var_f4_3699 * (0.5 * temp_f1_3715 * -(((f64) var_f4_3699 * (temp_f1_3715 * temp_f1_3715)) - 3.0)));
        } else if (var_f4_3699 < M2C_BITWISE(f32, 0.0)) {
            var_f4_3699 = __float_nan;
        } else {
            sp8 = var_f4_3699;
            temp_r3_3734 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_3734) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3744 = 1;
                } else {
                    var_r0_3744 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3744 = 5;
                } else {
                    var_r0_3744 = 3;
                }
                break;
            default:
                var_r0_3744 = 4;
                break;
            }
            if (var_r0_3744 == 1) {
                var_f4_3699 = __float_nan;
            }
        }
        var_f3_3766 = 1.0f / var_f4_3699;
    } else {
        var_f3_3766 = 0.0f;
    }
    sp130 = (f32) sp130 * var_f3_3766;
    (*(f32 *) ((u8 *) &sp128 + 0xc)) *= var_f3_3766;
    sp138 = (f32) sp138 * var_f3_3766;
    if ((s32) this->unk4->unk3C8 != 0) {
        temp_f31_3788 = MKVector3::up.unk4;
        temp_f30_3790 = MKVector3::up.unk8;
        temp_f29_3792 = MKVector3::up.unk0;
        var_r31_3793 = 0;
        var_r28_3795 = 0;
loop_26:
        temp_r3_3885 = this->unk4;
        if (var_r31_3793 < (s32) temp_r3_3885->unk3C8) {
            sp44 = (temp_f30_3790 * sp130) - (temp_f29_3792 * sp138);
            sp40 = (temp_f31_3788 * sp138) - (temp_f30_3790 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp48 = (temp_f29_3792 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f31_3788 * sp130);
            spD0 = (f64) sp40;
            spD8 = (f64) sp48;
            sp120 = (f64) sp40;
            sp128 = (f64) sp48;
            spB0.operator*(temp_f28_3648);
            temp_r6_3822 = this->unk4;
            sp30 = M2C_FIELD(temp_r6_3822, f64 *, 0x378) + M2C_BITWISE(f64, spB0);
            sp110 = sp30;
            sp38 = temp_r6_3822->unk378.unk8 + spB0.unk8;
            spC0 = sp30;
            sp118 = (f64) sp38;
            spC8 = (f64) sp38;
            KDMath_Slerp(spA0, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_3822->unk3C8);
            sp130 = M2C_BITWISE(f64, spA0);
            sp138 = (f64) spA0.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_3795 + 0x84)), s32 *, 4) = 0x20004200;
            temp_r5_3858 = this->unk4;
            temp_r5_3858->unk2C0.AddSpawnPoint(temp_r5_3858 + (var_r28_3795 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_3795 + 0x90)))->SetIdentity();
            temp_r6_3867 = var_r28_3795 + 0x90;
            temp_r6_3870 = this->unk4 + temp_r6_3867;
            M2C_FIELD(temp_r6_3870, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_3870, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_3870, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_3870, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_3867))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r31_3793 += 1;
            var_r28_3795 += 0x60;
            goto loop_26;
        }
        temp_r3_3885->unk2C0.AddSpawnPointEnd();
    }
    temp_r3_3892 = this->unk4;
    if ((s32) temp_r3_3892->unk3CC != 0) {
        var_r30_3896 = temp_r3_3892->unk3C8;
        var_r28_3900 = var_r30_3896 * 0x60;
        temp_f29_3901 = MKVector3::up.unk4;
        temp_f30_3902 = MKVector3::up.unk8;
        temp_f31_3904 = MKVector3::up.unk0;
loop_31:
        temp_r4_3997 = this->unk4;
        if (var_r30_3896 < (s32) (temp_r4_3997->unk3C8 + temp_r4_3997->unk3CC)) {
            sp24 = (temp_f30_3902 * (f32) sp130) - (temp_f31_3904 * (f32) sp138);
            sp20 = (temp_f29_3901 * (f32) sp138) - (temp_f30_3902 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp28 = (temp_f31_3904 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f29_3901 * (f32) sp130);
            sp90 = (f64) sp20;
            sp98 = (f64) sp28;
            sp120 = (f64) sp20;
            sp128 = (f64) sp28;
            sp70.operator*(temp_f28_3648);
            temp_r6_3934 = this->unk4;
            sp10 = M2C_FIELD(temp_r6_3934, f64 *, 0x378) + M2C_BITWISE(f64, sp70);
            sp110 = sp10;
            sp18 = temp_r6_3934->unk378.unk8 + sp70.unk8;
            sp80 = sp10;
            sp118 = (f64) sp18;
            sp88 = (f64) sp18;
            KDMath_Slerp(sp60, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_3934->unk3CC);
            sp130 = M2C_BITWISE(f64, sp60);
            sp138 = (f64) sp60.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_3900 + 0x84)), s32 *, 4) = 0x20004200;
            temp_r5_3970 = this->unk4;
            temp_r5_3970->unk310.AddSpawnPoint(temp_r5_3970 + (var_r28_3900 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_3900 + 0x90)))->SetIdentity();
            temp_r6_3979 = var_r28_3900 + 0x90;
            temp_r6_3982 = this->unk4 + temp_r6_3979;
            M2C_FIELD(temp_r6_3982, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_3982, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_3982, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_3982, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_3979))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r30_3896 += 1;
            var_r28_3900 += 0x60;
            goto loop_31;
        }
        temp_r4_3997->unk310.AddSpawnPointEnd();
    }
}
#endif

void ElectricDojoLesson::SetupNumFuryEnemies() {
    DojoController *temp_r3_4038;
    DojoController *temp_r3_4043;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    if ((s32) this->unkC == 0) {
        temp_r3_4038 = this->unk4;
        temp_r3_4038->unk3C8 = temp_r3_4038->unk760;
        return;
    }
    temp_r3_4043 = this->unk4;
    temp_r3_4043->unk3CC = temp_r3_4043->unk764;
}

s32 ElectricDojoLesson::IsBreath2Complete() {
    return this->unk10 > 1;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void ElectricDojoLesson::SetupBreath2SpawnPoints() {
    CharacterGraphNode *sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    DojoController *temp_r3_4070;
    DojoController *temp_r3_4191;
    DojoController *temp_r3_4210;
    DojoController *temp_r3_4221;
    DojoController *temp_r3_4233;
    f32 var_f4_4081;
    f32 var_f5_4094;
    f64 temp_f0_4075;
    f64 temp_f1_4099;
    f64 temp_f1_4105;
    f64 temp_f1_4109;
    s32 temp_r0_4167;
    s32 temp_r3_4128;
    s32 var_r0_4138;

    temp_r3_4070 = this->unk4;
    temp_f0_4075 = temp_r3_4070->unk388 - M2C_FIELD(temp_r3_4070, f64 *, 0x378);
    sp10 = temp_f0_4075;
    var_f4_4081 = 0.0f;
    sp60 = temp_f0_4075;
    sp18 = M2C_FIELD(temp_r3_4070, f32 *, 0x390) - temp_r3_4070->unk378.unk8;
    (*(f32 *) ((u8 *) &sp58 + 0xc)) = 0.0f;
    sp68 = (f64) sp18;
    var_f5_4094 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (0.0f * 0.0f));
    if (var_f5_4094 > 0.000001f) {
        if (var_f5_4094 > 0.0f) {
            temp_f1_4099 = __frsqrte(var_f5_4094);
            temp_f1_4105 = 0.5 * temp_f1_4099 * -(((f64) var_f5_4094 * (temp_f1_4099 * temp_f1_4099)) - 3.0);
            temp_f1_4109 = 0.5 * temp_f1_4105 * -(((f64) var_f5_4094 * (temp_f1_4105 * temp_f1_4105)) - 3.0);
            var_f5_4094 = (f32) ((f64) var_f5_4094 * (0.5 * temp_f1_4109 * -(((f64) var_f5_4094 * (temp_f1_4109 * temp_f1_4109)) - 3.0)));
        } else if (var_f5_4094 < M2C_BITWISE(f32, 0.0)) {
            var_f5_4094 = __float_nan;
        } else {
            sp8 = var_f5_4094;
            temp_r3_4128 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_4128) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4138 = 1;
                } else {
                    var_r0_4138 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_4138 = 5;
                } else {
                    var_r0_4138 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_4138 = 4;
                break;
            }
            if (var_r0_4138 == 1) {
                var_f5_4094 = __float_nan;
            }
        }
        var_f4_4081 = 1.0f / var_f5_4094;
    }
    temp_r0_4167 = this->unk10;
    sp60 = (f32) sp60 * var_f4_4081;
    (*(f32 *) ((u8 *) &sp58 + 0xc)) *= var_f4_4081;
    sp68 = (f32) sp68 * var_f4_4081;
    switch (temp_r0_4167) {                         /* switch 2; irregular */
    case 0:                                         /* switch 2 */
        sp40 = (f64) sp60;
        sp48 = (f64) sp68;
        temp_r3_4191 = this->unk4;
        sp50 = M2C_FIELD(temp_r3_4191, f64 *, 0x378);
        sp58 = M2C_FIELD(temp_r3_4191, f64 *, 0x380);
        temp_r3_4191->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &sp50, (MKVector3) &sp40, temp_r3_4191->unk6B0, 1U, 1U, 0.62831855f, 0x20800200U);
        sp20 = (f64) sp60;
        sp28 = (f64) sp68;
        temp_r3_4210 = this->unk4;
        sp30 = M2C_FIELD(temp_r3_4210, f64 *, 0x378);
        sp38 = M2C_FIELD(temp_r3_4210, f64 *, 0x380);
        temp_r3_4210->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp30, (MKVector3) &sp20, temp_r3_4210->unk6B0, 1U, 1U, 0.62831855f, 0x20800200U);
        return;
    case 1:                                         /* switch 2 */
        temp_r3_4221 = this->unk4;
        temp_r3_4221->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_4221->unk3D8, 2, 0x10, &sp70, 0U, 0.0f, 0.0f, 0x20001200U);
        temp_r3_4233 = this->unk4;
        temp_r3_4233->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_4233->unk3D8, 2, 0x10, &sp70, 0U, 0.0f, 0.0f, 0x20001200U);
        return;
    }
}
#endif

void ElectricDojoLesson::SetupNumBreath2Enemies() {
    DojoController *temp_r3_4268;
    DojoController *temp_r3_4276;
    DojoController *temp_r4_4265;
    DojoController *temp_r4_4273;
    s32 temp_r0_4259;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_4259 = this->unk10;
    switch (temp_r0_4259) {                         /* irregular */
    case 0:
        temp_r4_4265 = this->unk4;
        temp_r4_4265->unk3C8 = temp_r4_4265->unk744;
        temp_r3_4268 = this->unk4;
        temp_r3_4268->unk3CC = temp_r3_4268->unk748;
        return;
    case 1:
        temp_r4_4273 = this->unk4;
        temp_r4_4273->unk3C8 = temp_r4_4273->unk750;
        temp_r3_4276 = this->unk4;
        temp_r3_4276->unk3CC = temp_r3_4276->unk754;
        return;
    }
}

s32 ElectricDojoLesson::IsBreath1Complete() {
    return this->unk10 > 1;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void ElectricDojoLesson::SetupBreath1SpawnPoints() {
    CharacterGraphNode *spC0;
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
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
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    DojoController *temp_r3_4317;
    DojoController *temp_r3_4435;
    DojoController *temp_r3_4458;
    DojoController *temp_r3_4479;
    DojoController *temp_r3_4491;
    DojoController *temp_r3_4503;
    f32 temp_f1_4415;
    f32 temp_f29_4423;
    f32 temp_f30_4421;
    f32 temp_f31_4419;
    f32 temp_f3_4417;
    f32 temp_f4_4413;
    f32 var_f4_4341;
    f32 var_f5_4328;
    f64 temp_f0_4322;
    f64 temp_f1_4346;
    f64 temp_f1_4352;
    f64 temp_f1_4356;
    s32 temp_r0_4309;
    s32 temp_r3_4375;
    s32 var_r0_4385;

    temp_r0_4309 = this->unk10;
    switch (temp_r0_4309) {                         /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_r3_4317 = this->unk4;
        temp_f0_4322 = temp_r3_4317->unk388 - M2C_FIELD(temp_r3_4317, f64 *, 0x378);
        sp40 = temp_f0_4322;
        var_f5_4328 = 0.0f;
        spB0 = temp_f0_4322;
        sp48 = M2C_FIELD(temp_r3_4317, f32 *, 0x390) - temp_r3_4317->unk378.unk8;
        (*(f32 *) ((u8 *) &spA8 + 0xc)) = 0.0f;
        spB8 = (f64) sp48;
        var_f4_4341 = ((f32) spB8 * (f32) spB8) + (((f32) spB0 * (f32) spB0) + (0.0f * 0.0f));
        if (var_f4_4341 > 0.000001f) {
            if (var_f4_4341 > 0.0f) {
                temp_f1_4346 = __frsqrte(var_f4_4341);
                temp_f1_4352 = 0.5 * temp_f1_4346 * -(((f64) var_f4_4341 * (temp_f1_4346 * temp_f1_4346)) - 3.0);
                temp_f1_4356 = 0.5 * temp_f1_4352 * -(((f64) var_f4_4341 * (temp_f1_4352 * temp_f1_4352)) - 3.0);
                var_f4_4341 = (f32) ((f64) var_f4_4341 * (0.5 * temp_f1_4356 * -(((f64) var_f4_4341 * (temp_f1_4356 * temp_f1_4356)) - 3.0)));
            } else if (var_f4_4341 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4341 = __float_nan;
            } else {
                sp8 = var_f4_4341;
                temp_r3_4375 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_4375) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_4385 = 1;
                    } else {
                        var_r0_4385 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_4385 = 5;
                    } else {
                        var_r0_4385 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_4385 = 4;
                    break;
                }
                if (var_r0_4385 == 1) {
                    var_f4_4341 = __float_nan;
                }
            }
            var_f5_4328 = 1.0f / var_f4_4341;
        }
        temp_f4_4413 = (f32) spB0 * var_f5_4328;
        temp_f1_4415 = (*(f32 *) ((u8 *) &spA8 + 0xc)) * var_f5_4328;
        temp_f3_4417 = (f32) spB8 * var_f5_4328;
        temp_f31_4419 = -temp_f4_4413;
        (*(f32 *) ((u8 *) &spA8 + 0xc)) = temp_f1_4415;
        temp_f30_4421 = -temp_f1_4415;
        temp_f29_4423 = -temp_f3_4417;
        spB0 = temp_f4_4413;
        sp30 = temp_f31_4419;
        sp34 = temp_f30_4421;
        sp38 = temp_f29_4423;
        sp90 = (f64) sp30;
        sp98 = (f64) sp38;
        temp_r3_4435 = this->unk4;
        spB8 = temp_f3_4417;
        spA0 = M2C_FIELD(temp_r3_4435, f64 *, 0x378);
        spA8 = (f64) M2C_FIELD(temp_r3_4435, f32 *, 0x380);
        temp_r3_4435->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &spA0, (MKVector3) &sp90, temp_r3_4435->unk6B0, 0U, 0U, 0.7853982f, 0x20800200U);
        sp28 = temp_f29_4423;
        sp20 = temp_f31_4419;
        sp24 = temp_f30_4421;
        sp78 = (f64) sp28;
        sp70 = (f64) sp20;
        temp_r3_4458 = this->unk4;
        sp80 = M2C_FIELD(temp_r3_4458, f64 *, 0x378);
        sp88 = (f64) M2C_FIELD(temp_r3_4458, f32 *, 0x380);
        temp_r3_4458->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp80, (MKVector3) &sp70, temp_r3_4458->unk6B0, 0U, 0U, 0.7853982f, 0x20800200U);
        sp18 = temp_f29_4423;
        sp10 = temp_f31_4419;
        sp14 = temp_f30_4421;
        sp58 = (f64) sp18;
        sp50 = (f64) sp10;
        temp_r3_4479 = this->unk4;
        sp60 = M2C_FIELD(temp_r3_4479, f64 *, 0x378);
        sp68 = (f64) M2C_FIELD(temp_r3_4479, f32 *, 0x380);
        temp_r3_4479->SetupSmashPropsVanguard(4, (MKVector3) &sp60, (MKVector3) &sp50, 300.0f + temp_r3_4479->unk6B0, 0U, 0U, 0.7853982f);
        return;
    case 1:                                         /* switch 1 */
        temp_r3_4491 = this->unk4;
        temp_r3_4491->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_4491->unk3D8, 2, 0x10, &spC0, 0U, 0.0f, 0.0f, 0x20001200U);
        temp_r3_4503 = this->unk4;
        temp_r3_4503->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_4503->unk3D8, 2, 0x10, &spC0, 0U, 0.0f, 0.0f, 0x20001200U);
        return;
    }
}
#endif

void ElectricDojoLesson::SetupNumBreath1Enemies() {
    DojoController *temp_r3_4544;
    DojoController *temp_r3_4552;
    DojoController *temp_r4_4541;
    DojoController *temp_r4_4549;
    s32 temp_r0_4535;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_4535 = this->unk10;
    switch (temp_r0_4535) {                         /* irregular */
    case 0:
        temp_r4_4541 = this->unk4;
        temp_r4_4541->unk3C8 = temp_r4_4541->unk72C;
        temp_r3_4544 = this->unk4;
        temp_r3_4544->unk3CC = temp_r3_4544->unk730;
        return;
    case 1:
        temp_r4_4549 = this->unk4;
        temp_r4_4549->unk3C8 = temp_r4_4549->unk738;
        temp_r3_4552 = this->unk4;
        temp_r3_4552->unk3CC = temp_r3_4552->unk73C;
        return;
    }
}

void ElectricDojoLesson::MakeChildrenInvulnerable() {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_4566;

    temp_r0_4566 = this->unk8;
    switch (temp_r0_4566) {                         /* irregular */
    case 0:
        if ((s32) this->unk10 == 0) {
            sp24 = 0;
            sp20 = 0x165;
            this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp20);
            this->unk4->unk310.SendMessageToActive((MKMessage *) &sp20);
            return;
        }
        sp1C = 0;
        sp18 = 0x161;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp18);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp18);
        return;
    case 1:
        sp14 = 0;
        sp10 = 0x165;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp10);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp10);
        return;
    case 2:
        spC = 0;
        sp8 = 0x161;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp8);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp8);
        return;
    }
}

void ElectricDojoLesson::TurnOffAbilities() {
    s32 temp_r0_4646;

    temp_r0_4646 = this->unk8;
    switch (temp_r0_4646) {                         /* irregular */
    case 0:
        M2C_FIELD(&gb, s8 *, 7) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        M2C_FIELD(&gb, s8 *, 5) = 0;
        return;
    case 1:
        M2C_FIELD(&gb, s8 *, 6) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    }
}

#if 0 // DRAFT: function call 'DialogBox_ColorButtons(signed char *, signed char *, int,
void ElectricDojoLesson::IncrementNumInterations() {
    s8 *sp14;
    s32 spC;
    s32 sp8;
    s32 temp_r0_4679;

    temp_r0_4679 = this->unk8;
    switch (temp_r0_4679) {                         /* irregular */
    case 0:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 1:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 2:
        this->unk4->unk3D0 = 0;
        this->unk4->unk3D4 = 0;
        if ((s32) this->unkC != 0) {
            if (HasSucceededFury() != 0) {
                this->unk10 += 1;
                return;
            }
        } else {
            if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 0, 0x200);
                spC = 0;
                spC = 0;
                sp14 = &this->unk4->unk468;
                sp8 = 0x96;
                InGame_SystemMessage((MKMessage *) &sp8);
                this->unkC = 1;
                return;
            }
            this->unkC = 0;
            return;
        }
        break;
    }
}
#endif

u8 ElectricDojoLesson::IsLessonComplete() {
    return (u8) (this->unk8 == 2);
}

s32 ElectricDojoLesson::IsSubLessonComplete() {
    s32 temp_r0_4774;

    temp_r0_4774 = this->unk8;
    switch (temp_r0_4774) {                         /* irregular */
    case 1:
        return IsBreath2Complete();
    case 2:
        return ElectricDojoLesson::IsFuryComplete();
    case 0:
        return IsBreath1Complete();
    default:
        return 0;
    }
}

void ElectricDojoLesson::SetupTimer() {
    DojoController *temp_r4_4951;
    DojoController *temp_r7_4822;
    DojoController *temp_r7_4851;
    DojoController *temp_r7_4886;
    DojoController *temp_r7_4915;
    f32 var_f0_4960;
    s32 temp_r0_4807;
    s32 temp_r0_4823;
    s32 temp_r0_4852;
    s32 temp_r0_4887;
    s32 temp_r0_4916;
    s32 temp_r4_4819;
    s32 temp_r4_4883;

    temp_r0_4807 = this->unk8;
    switch (temp_r0_4807) {                         /* irregular */
    case 0:
        temp_r4_4819 = this->unk10;
        if ((temp_r4_4819 == 0) && (temp_r7_4822 = this->unk4, temp_r0_4823 = temp_r7_4822->unk734, ((temp_r0_4823 == 0) == 0))) {
            temp_r7_4822->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_4823 * temp_r7_4822->unk3B8) + (f32) temp_r0_4823);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_4819 == 1) && (temp_r7_4851 = this->unk4, temp_r0_4852 = temp_r7_4851->unk740, ((temp_r0_4852 == 0) == 0))) {
            temp_r7_4851->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_4852 * temp_r7_4851->unk3B8) + (f32) temp_r0_4852);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 1:
        temp_r4_4883 = this->unk10;
        if ((temp_r4_4883 == 0) && (temp_r7_4886 = this->unk4, temp_r0_4887 = temp_r7_4886->unk74C, ((temp_r0_4887 == 0) == 0))) {
            temp_r7_4886->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_4887 * temp_r7_4886->unk3B8) + (f32) temp_r0_4887);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_4883 == 1) && (temp_r7_4915 = this->unk4, temp_r0_4916 = temp_r7_4915->unk758, ((temp_r0_4916 == 0) == 0))) {
            temp_r7_4915->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_4916 * temp_r7_4915->unk3B8) + (f32) temp_r0_4916);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 2:
        this->unk4->unk3BF = 0;
        break;
    }
    temp_r4_4951 = this->unk4;
    if ((u8) temp_r4_4951->unk3BF != 0) {
        var_f0_4960 = temp_r4_4951->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
        if (var_f0_4960 > 0.0f) {

        } else {
            var_f0_4960 = 0.0f;
        }
        temp_r4_4951->unk814 = var_f0_4960;
    }
}

void ElectricDojoLesson::SetupSpawnPoints() {
    s32 temp_r0_4979;

    temp_r0_4979 = this->unk8;
    switch (temp_r0_4979) {                         /* irregular */
    case 0:
        SetupBreath1SpawnPoints();
        return;
    case 1:
        SetupBreath2SpawnPoints();
        return;
    case 2:
        SetupFurySpawnPoints();
        return;
    }
}

void ElectricDojoLesson::SetupNumEnemies() {
    s32 temp_r0_5011;

    temp_r0_5011 = this->unk8;
    switch (temp_r0_5011) {                         /* irregular */
    case 0:
        SetupNumBreath1Enemies();
        return;
    case 1:
        SetupNumBreath2Enemies();
        return;
    case 2:
        SetupNumFuryEnemies();
        return;
    }
}

#if 0 // DRAFT: pointer/array required
u8 FireDojoLesson::HasSucceededFury() {
    DojoController *spC;
    s32 sp8;
    s32 var_r3_5067;
    u8 var_r4_5056;
    void *temp_r3_5054;

    if ((s32) this->unkC == 1) {
        temp_r3_5054 = M2C_FIELD(*gb, void *(**)(void **), 0x40)(gb);
        var_r4_5056 = 0;
        if (((u8) M2C_FIELD(temp_r3_5054, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_5054, u8 *, 4) != 0)) {
            var_r4_5056 = 1;
        }
        if (var_r4_5056 != 0) {
            var_r3_5067 = 0;
        } else {
            var_r3_5067 = MKInput_Pressed(9, (MKInputDevices) M2C_FIELD(temp_r3_5054, s32 *, 0));
        }
        if ((u8) var_r3_5067 != 0) {
            DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 1, 0x200);
        }
    }
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            spC = NULL;
            sp8 = 0x163;
            spC = this->unk4;
            InGame_SystemMessage((MKMessage *) &sp8);
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'DojoController' to
u8 FireDojoLesson::HasSucceededBreath2() {
    s32 temp_r0_5122;
    s32 var_ctr_5133;
    s32 var_r4_5132;

    temp_r0_5122 = this->unk10;
    switch (temp_r0_5122) {                         /* irregular */
    case 0:
        var_r4_5132 = 0;
        var_ctr_5133 = 4;
loop_5:
        if ((s32) M2C_FIELD(*(this->unk4 + (var_r4_5132 + 0x3F4)), s32 *, 0x17C) != 3) {
            return 0U;
        }
        var_r4_5132 += 4;
        var_ctr_5133 -= 1;
        if (var_ctr_5133 == 0) {
            return 1U;
        }
        goto loop_5;
    case 1:
        this->unk4->unk2C0.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk4->unk310.GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                return 1U;
            }
        }
    default:
        return 0U;
    }
}
#endif

u8 FireDojoLesson::HasSucceededBreath1() {
    this->unk4->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
        this->unk4->unk310.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            return 1U;
        }
    }
    return 0U;
}

#if 0 // DRAFT: illegal implicit conversion from 'Enemy *' to
u8 FireDojoLesson::HasSucceededMeleeKnockBack() {
    DojoController *temp_r3_5245;
    DojoController *temp_r3_5313;
    DojoController *temp_r3_5473;
    DojoController *temp_r3_5596;
    DojoController *temp_r4_5235;
    DojoController *temp_r4_5268;
    DojoController *temp_r4_5295;
    DojoController *temp_r4_5340;
    DojoController *temp_r4_5364;
    DojoController *temp_r4_5374;
    DojoController *temp_r4_5402;
    DojoController *temp_r4_5466;
    DojoController *temp_r4_5498;
    DojoController *temp_r4_5508;
    DojoController *temp_r4_5548;
    DojoController *temp_r4_5589;
    Targetable *temp_r3_5541;
    s32 temp_r0_5209;
    s32 var_r30_5416;
    s32 var_r30_5562;
    void **temp_r3_5425;
    void **temp_r3_5571;
    void *temp_r3_5422;
    void *temp_r3_5568;

    UpdateCombatArcs();
    temp_r0_5209 = this->unk10;
    switch (temp_r0_5209) {                         /* irregular */
    case 0:
        this->unk4->unk42C = 1;
        this->unk4->unk430 = 0x1000;
        this->unk4->unk434 = 0x1000;
        this->unk4->unk438 = 0x1000;
        this->unk4->unk678 = 0;
        temp_r4_5235 = this->unk4;
        if ((u32) temp_r4_5235->unk410 == (u32) temp_r4_5235->unk42C) {
            if ((s32) temp_r4_5235->unk668 != 2) {
                temp_r4_5235->unk668 = 1;
            }
            temp_r3_5245 = this->unk4;
            if (((u32) temp_r3_5245->unk414 == (u32) temp_r3_5245->unk430) || ((u32) temp_r3_5245->unk418 == (u32) temp_r3_5245->unk434) || ((u32) temp_r3_5245->unk41C == (u32) temp_r3_5245->unk438)) {
                temp_r3_5245->ClearCombatArcs();
                this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                temp_r4_5268 = this->unk4;
                temp_r4_5268->unk670 = temp_r4_5268->unk674;
                return 1U;
            }
            goto block_65;
        }
block_65:
    default:
        return 0U;
    case 1:
        this->unk4->unk42C = 4;
        this->unk4->unk430 = 8;
        this->unk4->unk434 = 0x10;
        this->unk4->unk438 = 1;
        this->unk4->unk43C = 0x1000;
        this->unk4->unk440 = 0x1000;
        this->unk4->unk444 = 0x1000;
        this->unk4->unk678 = 0;
        temp_r4_5295 = this->unk4;
        if (((u32) temp_r4_5295->unk410 == (u32) temp_r4_5295->unk42C) && ((u32) temp_r4_5295->unk414 == (u32) temp_r4_5295->unk430) && ((u32) temp_r4_5295->unk418 == (u32) temp_r4_5295->unk434)) {
            if ((s32) temp_r4_5295->unk668 != 2) {
                temp_r4_5295->unk668 = 1;
            }
            temp_r3_5313 = this->unk4;
            if (((u32) temp_r3_5313->unk41C == (u32) temp_r3_5313->unk438) && (((u32) temp_r3_5313->unk420 == (u32) temp_r3_5313->unk43C) || ((u32) temp_r3_5313->unk424 == (u32) temp_r3_5313->unk440) || ((u32) temp_r3_5313->unk428 == (u32) temp_r3_5313->unk444))) {
                temp_r3_5313->ClearCombatArcs();
                this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                temp_r4_5340 = this->unk4;
                temp_r4_5340->unk670 = temp_r4_5340->unk674;
                return 1U;
            }
            goto block_65;
        }
        goto block_65;
    case 2:
        this->unk4->unk42C = 1;
        this->unk4->unk430 = 0x1000;
        this->unk4->unk434 = 0x1000;
        this->unk4->unk438 = 0x1000;
        this->unk4->unk43C = 0x1000;
        this->unk4->unk440 = 0x1000;
        this->unk4->unk444 = 0x1000;
        this->unk4->unk678 = 0;
        temp_r4_5364 = this->unk4;
        if ((u32) temp_r4_5364->unk410 == (u32) temp_r4_5364->unk42C) {
            if ((s32) temp_r4_5364->unk668 != 2) {
                temp_r4_5364->unk668 = 1;
            }
            temp_r4_5374 = this->unk4;
            if (((u32) temp_r4_5374->unk414 == (u32) temp_r4_5374->unk430) || ((u32) temp_r4_5374->unk418 == (u32) temp_r4_5374->unk434) || ((u32) temp_r4_5374->unk41C == (u32) temp_r4_5374->unk438) || ((u32) temp_r4_5374->unk420 == (u32) temp_r4_5374->unk43C) || ((u32) temp_r4_5374->unk424 == (u32) temp_r4_5374->unk440) || ((u32) temp_r4_5374->unk428 == (u32) temp_r4_5374->unk444)) {
                temp_r4_5374->unk670 = temp_r4_5374->unk674;
                temp_r4_5402 = this->unk4;
                if ((u8) temp_r4_5402->unk3C2 == 0) {
                    temp_r4_5402->unk3C2 = 1;
                    this->unk4->unk3AC = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
                }
                var_r30_5416 = 0;
loop_44:
                temp_r3_5473 = this->unk4;
                if (var_r30_5416 >= (s32) temp_r3_5473->unk3D0) {
                    goto block_65;
                }
                temp_r3_5422 = checked_cast<Enemy *, MKProp>(temp_r3_5473->unk2C0.GetActive(var_r30_5416));
                if (temp_r3_5422 != NULL) {
                    temp_r3_5425 = M2C_FIELD(temp_r3_5422, void ***, 0xA3C);
                    if (M2C_FIELD(*temp_r3_5425, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5425, 0xD) != 0) {
                        this->unk4->unk2C0.GetNumberActive();
                        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                            this->unk4->unk2C0.DespawnAll();
                        }
                        this->unk4->unk310.GetNumberActive();
                        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                            this->unk4->unk310.DespawnAll();
                        }
                        this->unk4->unk3D0 = 0;
                        this->unk4->unk3D4 = 0;
                        this->unk4->ClearCombatArcs();
                        this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                        temp_r4_5466 = this->unk4;
                        temp_r4_5466->unk670 = temp_r4_5466->unk674;
                        return 1U;
                    }
                }
                var_r30_5416 += 1;
                goto loop_44;
            }
            goto block_65;
        }
        goto block_65;
    case 3:
        this->unk4->unk42C = 1;
        this->unk4->unk430 = 0x1000;
        this->unk4->unk434 = 0x1000;
        this->unk4->unk438 = 0x1000;
        this->unk4->unk43C = 0x1000;
        this->unk4->unk440 = 0x1000;
        this->unk4->unk444 = 0x1000;
        this->unk4->unk678 = 0;
        temp_r4_5498 = this->unk4;
        if ((u32) temp_r4_5498->unk410 == (u32) temp_r4_5498->unk42C) {
            if ((s32) temp_r4_5498->unk668 != 2) {
                temp_r4_5498->unk668 = 1;
            }
            temp_r4_5508 = this->unk4;
            if (((u32) temp_r4_5508->unk414 == (u32) temp_r4_5508->unk430) || ((u32) temp_r4_5508->unk418 == (u32) temp_r4_5508->unk434) || ((u32) temp_r4_5508->unk41C == (u32) temp_r4_5508->unk438) || ((u32) temp_r4_5508->unk420 == (u32) temp_r4_5508->unk43C) || ((u32) temp_r4_5508->unk424 == (u32) temp_r4_5508->unk440) || ((u32) temp_r4_5508->unk428 == (u32) temp_r4_5508->unk444)) {
                temp_r4_5508->unk670 = temp_r4_5508->unk674;
                ((GameGlobals *) &gb)->GetSpyro();
                ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetLastCombatEnemy();
                temp_r3_5541 = checked_cast<Enemy *, Targetable>(M2C_ERROR(/* Read from unset register $r3 */));
                if ((temp_r3_5541 != NULL) && ((s32) M2C_FIELD(M2C_FIELD(temp_r3_5541, void **, 0xA38), s32 *, 0xF4) == 0x2D)) {
                    temp_r4_5548 = this->unk4;
                    if ((u8) temp_r4_5548->unk3C2 == 0) {
                        temp_r4_5548->unk3C2 = 1;
                        this->unk4->unk3AC = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
                    }
                    var_r30_5562 = 0;
loop_64:
                    temp_r3_5596 = this->unk4;
                    if (var_r30_5562 >= (s32) temp_r3_5596->unk3D0) {
                        goto block_65;
                    }
                    temp_r3_5568 = checked_cast<Enemy *, MKProp>(temp_r3_5596->unk2C0.GetActive(var_r30_5562));
                    if (temp_r3_5568 != NULL) {
                        temp_r3_5571 = M2C_FIELD(temp_r3_5568, void ***, 0xA3C);
                        if (M2C_FIELD(*temp_r3_5571, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5571, 0xD) != 0) {
                            this->unk4->ClearCombatArcs();
                            this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                            temp_r4_5589 = this->unk4;
                            temp_r4_5589->unk670 = temp_r4_5589->unk674;
                            return 1U;
                        }
                    }
                    var_r30_5562 += 1;
                    goto loop_64;
                }
            }
            goto block_65;
        }
        goto block_65;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 FireDojoLesson::HasSucceededMeleeKnockUp() {
    s32 spC;
    s32 sp8;
    DojoController *temp_r3_5696;
    DojoController *temp_r3_5733;
    DojoController *temp_r3_5854;
    DojoController *temp_r4_5637;
    DojoController *temp_r4_5666;
    DojoController *temp_r4_5686;
    DojoController *temp_r4_5718;
    DojoController *temp_r4_5739;
    DojoController *temp_r4_5774;
    DojoController *temp_r4_5786;
    DojoController *temp_r4_5807;
    DojoController *temp_r4_5836;
    DojoController *temp_r4_5880;
    Targetable *temp_r3_5749;
    s32 temp_r0_5619;
    s32 temp_r6_5763;

    UpdateCombatArcs();
    temp_r0_5619 = this->unk10;
    switch (temp_r0_5619) {                         /* irregular */
    case 0:
        this->unk4->unk42C = 1;
        this->unk4->unk678 = 1;
        temp_r4_5637 = this->unk4;
        if ((u32) temp_r4_5637->unk410 == (u32) temp_r4_5637->unk42C) {
            ((GameGlobals *) &gb)->GetSpyro();
            ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetLastCombatEnemy();
            if (((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) && (((Enemy *) (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), Enemy *(**)(), 0xC)()))->IsKnockedUp() != 0)) {
                this->unk4->ClearCombatArcs();
                this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                temp_r4_5666 = this->unk4;
                temp_r4_5666->unk670 = temp_r4_5666->unk674;
                return 1U;
            }
        }
block_37:
    default:
        return 0U;
    case 1:
        this->unk4->unk42C = 1;
        this->unk4->unk430 = 0x2000;
        this->unk4->unk434 = 0x4000;
        this->unk4->unk438 = 0x8000;
        this->unk4->unk678 = 1;
        temp_r4_5686 = this->unk4;
        if ((u32) temp_r4_5686->unk410 == (u32) temp_r4_5686->unk42C) {
            if ((s32) temp_r4_5686->unk668 != 2) {
                temp_r4_5686->unk668 = 1;
            }
            temp_r3_5696 = this->unk4;
            if (((u32) temp_r3_5696->unk414 == (u32) temp_r3_5696->unk430) && ((u32) temp_r3_5696->unk418 == (u32) temp_r3_5696->unk434) && ((u32) temp_r3_5696->unk41C == (u32) temp_r3_5696->unk438)) {
                temp_r3_5696->ClearCombatArcs();
                this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                temp_r4_5718 = this->unk4;
                temp_r4_5718->unk670 = temp_r4_5718->unk674;
                return 1U;
            }
            goto block_37;
        }
        temp_r4_5686->unk668 = 0;
        goto block_37;
    case 2:
        this->unk4->unk42C = 0x10000;
        this->unk4->unk678 = 1;
        temp_r3_5733 = this->unk4;
        if ((s32) temp_r3_5733->unk668 != 2) {
            temp_r3_5733->unk668 = 1;
        }
        temp_r4_5739 = this->unk4;
        if ((u32) temp_r4_5739->unk410 == (u32) temp_r4_5739->unk42C) {
            ((GameGlobals *) &gb)->GetSpyro();
            ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetLastCombatEnemy();
            temp_r3_5749 = checked_cast<Enemy *, Targetable>(M2C_ERROR(/* Read from unset register $r3 */));
            if (temp_r3_5749 != NULL) {
                ((Enemy *) (M2C_FIELD(M2C_FIELD(temp_r3_5749, void **, 0x44), Enemy *(**)(), 0xD4)()))->IsFlinching();
                if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    temp_r6_5763 = this->unkC + 1;
                    this->unkC = temp_r6_5763;
                    spC = 0;
                    sp8 = 0xE1;
                    M2C_FIELD(M2C_FIELD(temp_r3_5749, void **, 0x44), M2C_UNK (**)(Targetable *, s32 *, M2C_UNK, s32), 0x2C)(temp_r3_5749, &sp8, 0, temp_r6_5763);
                    this->unk4->ClearCombatArcs();
                    temp_r4_5774 = this->unk4;
                    temp_r4_5774->unk670 = temp_r4_5774->unk674;
                    this->unk4->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.5f;
                    temp_r4_5786 = this->unk4;
                    DialogBox_ColorButtons(*(gpTranslation_StringArray + ((((this->unk8 - 1) * 4) + this->unk10 + 0x1AF) * 4)), &temp_r4_5786->unk468, temp_r4_5786->unk670, 0x200);
                    if ((s32) this->unkC >= 6) {
                        this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                        temp_r4_5807 = this->unk4;
                        temp_r4_5807->unk670 = temp_r4_5807->unk674;
                        return 1U;
                    }
                }
            }
        }
        goto block_37;
    case 3:
        this->unk4->unk42C = 4;
        this->unk4->unk430 = 8;
        this->unk4->unk434 = 0x10;
        this->unk4->unk438 = 1;
        this->unk4->unk43C = 0x2000;
        this->unk4->unk440 = 0x4000;
        this->unk4->unk444 = 0x8000;
        this->unk4->unk678 = 1;
        temp_r4_5836 = this->unk4;
        if (((u32) temp_r4_5836->unk410 == (u32) temp_r4_5836->unk42C) && ((u32) temp_r4_5836->unk414 == (u32) temp_r4_5836->unk430) && ((u32) temp_r4_5836->unk418 == (u32) temp_r4_5836->unk434)) {
            if ((s32) temp_r4_5836->unk668 != 2) {
                temp_r4_5836->unk668 = 1;
            }
            temp_r3_5854 = this->unk4;
            if (((u32) temp_r3_5854->unk41C == (u32) temp_r3_5854->unk438) && ((u32) temp_r3_5854->unk420 == (u32) temp_r3_5854->unk43C) && ((u32) temp_r3_5854->unk424 == (u32) temp_r3_5854->unk440) && ((u32) temp_r3_5854->unk428 == (u32) temp_r3_5854->unk444)) {
                temp_r3_5854->ClearCombatArcs();
                this->unk4->unk66C = M2C_FIELD(&gb, f32 *, 0x30C) + 1.0f;
                temp_r4_5880 = this->unk4;
                temp_r4_5880->unk670 = temp_r4_5880->unk674;
                return 1U;
            }
            goto block_37;
        }
        temp_r4_5836->unk668 = 0;
        goto block_37;
    }
}
#endif

u8 FireDojoLesson::HasSucceededLesson() {
    s32 temp_r0_5903;

    temp_r0_5903 = this->unk8;
    switch (temp_r0_5903) {                         /* irregular */
    case 0:
        return HasSucceededBreath1();
    case 2:
        return HasSucceededMeleeKnockBack();
    case 4:
        return HasSucceededFury();
    case 3:
        return HasSucceededBreath2();
    case 1:
        return HasSucceededMeleeKnockUp();
    default:
        return 0U;
    }
}

#if 0 // DRAFT: pointer/array required
s32 FireDojoLesson::HasFailedFury() {
    DojoController *temp_r4_5967;

    if ((s32) this->unkC != 0) {
        if (M2C_FIELD(*gb, u8 (**)(void **), 0x70)(gb) != 0) {
            this->unk4->unk3BC = 1;
        }
        this->unk4->unk310.GetNumberActive();
        temp_r4_5967 = this->unk4;
        if (((s32) temp_r4_5967->unk3D4 != (s32) M2C_ERROR(/* Read from unset register $r3 */)) && ((u8) temp_r4_5967->unk3BC == 0)) {
            return 1;
        }
        return 0;
    }
    this->unk4->unk3BC = 0;
    return 0;
}
#endif

s32 FireDojoLesson::HasFailedBreath2() {
    DojoController *temp_r4_5995;

    temp_r4_5995 = this->unk4;
    if (((u8) temp_r4_5995->unk3BF != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_5995->unk398)) {
        temp_r4_5995->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 FireDojoLesson::HasFailedBreath1() {
    DojoController *temp_r4_6018;

    temp_r4_6018 = this->unk4;
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_6018->unk398) && ((u8) temp_r4_6018->unk3BF != 0)) {
        temp_r4_6018->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 FireDojoLesson::HasFailedMeleeKnockBack() {
    DojoController *temp_r4_6062;
    DojoController *temp_r5_6046;
    s32 temp_r0_6041;

    temp_r0_6041 = this->unk10;
    if ((temp_r0_6041 != 2) && (temp_r0_6041 != 3)) {
        temp_r5_6046 = this->unk4;
        if (((u8) temp_r5_6046->unk3C2 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r5_6046->unk3AC)) {
            temp_r5_6046->unk3C2 = 0;
            return 1;
        }
    }
    temp_r4_6062 = this->unk4;
    if (((u8) temp_r4_6062->unk3BF != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_6062->unk398)) {
        temp_r4_6062->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 FireDojoLesson::HasFailedMeleeKnockUp() {
    DojoController *temp_r3_6090;
    DojoController *temp_r4_6106;

    temp_r3_6090 = this->unk4;
    if ((u8) temp_r3_6090->unk3BE != 0) {
        temp_r3_6090->unk2C0.GetNumberActive();
        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            this->unk4->unk310.GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                return 1;
            }
        }
    }
    temp_r4_6106 = this->unk4;
    if (((u8) temp_r4_6106->unk3BF != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r4_6106->unk398)) {
        temp_r4_6106->unk3BF = 0;
        return 1;
    }
    return 0;
}

s32 FireDojoLesson::HasFailedLesson() {
    s32 temp_r0_6137;

    temp_r0_6137 = this->unk8;
    switch (temp_r0_6137) {                         /* irregular */
    case 2:
        return HasFailedMeleeKnockBack();
    case 0:
        return HasFailedBreath1();
    case 4:
        return HasFailedFury();
    case 3:
        return HasFailedBreath2();
    case 1:
        return HasFailedMeleeKnockUp();
    default:
        return 0;
    }
}

s32 FireDojoLesson::IsFuryComplete() {
    return M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) > 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void FireDojoLesson::SetupFurySpawnPoints() {
    f64 sp138;                                      /* compiler-managed */
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
    MKVector3 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    DojoController *temp_r3_6233;
    DojoController *temp_r3_6239;
    DojoController *temp_r3_6450;
    DojoController *temp_r3_6457;
    DojoController *temp_r4_6207;
    DojoController *temp_r4_6562;
    DojoController *temp_r5_6423;
    DojoController *temp_r5_6535;
    DojoController *temp_r6_6387;
    DojoController *temp_r6_6499;
    f32 temp_f28_6213;
    f32 temp_f29_6357;
    f32 temp_f29_6466;
    f32 temp_f30_6355;
    f32 temp_f30_6467;
    f32 temp_f31_6353;
    f32 temp_f31_6469;
    f32 var_f3_6331;
    f32 var_f4_6264;
    f64 temp_f0_6226;
    f64 temp_f1_6225;
    f64 temp_f1_6270;
    f64 temp_f1_6276;
    f64 temp_f1_6280;
    s32 temp_r3_6299;
    s32 temp_r6_6432;
    s32 temp_r6_6544;
    s32 var_r0_6309;
    s32 var_r28_6360;
    s32 var_r28_6465;
    s32 var_r30_6461;
    s32 var_r31_6358;
    void *temp_r3_6224;
    void *temp_r6_6435;
    void *temp_r6_6547;

    temp_r4_6207 = this->unk4;
    temp_f28_6213 = temp_r4_6207->unk3B4 * temp_r4_6207->unk728;
    if (((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get() != NULL) {
        temp_r3_6224 = M2C_FIELD(M2C_FIELD(((TargetContext *) (M2C_FIELD(&gb, s32 *, 0x20) + 8))->Get()->__vptr, void *(**)(), 8)(), void **, 8);
        temp_f1_6225 = M2C_FIELD(temp_r3_6224, f64 *, 0x30);
        temp_f0_6226 = M2C_FIELD(temp_r3_6224, f64 *, 0x38);
        spF0 = temp_f1_6225;
        spF8 = temp_f0_6226;
        sp100 = temp_f1_6225;
        sp108 = temp_f0_6226;
    } else {
        temp_r3_6233 = this->unk4;
        sp100 = temp_r3_6233->unk388;
        sp108 = temp_r3_6233->unk390;
    }
    temp_r3_6239 = this->unk4;
    sp50 = M2C_FIELD(temp_r3_6239, f64 *, 0x378) - temp_r3_6239->unk388;
    sp130 = sp50;
    sp58 = temp_r3_6239->unk378.unk8 - (f32) M2C_FIELD(temp_r3_6239, f64 *, 0x390);
    sp138 = (f64) sp58;
    spE0 = sp50;
    spE8 = (f64) sp58;
    var_f4_6264 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + ((*(f32 *) ((u8 *) &sp128 + 0xc)) * (*(f32 *) ((u8 *) &sp128 + 0xc))));
    if (var_f4_6264 > 0.000001f) {
        if (var_f4_6264 > 0.0f) {
            temp_f1_6270 = __frsqrte(var_f4_6264);
            temp_f1_6276 = 0.5 * temp_f1_6270 * -(((f64) var_f4_6264 * (temp_f1_6270 * temp_f1_6270)) - 3.0);
            temp_f1_6280 = 0.5 * temp_f1_6276 * -(((f64) var_f4_6264 * (temp_f1_6276 * temp_f1_6276)) - 3.0);
            var_f4_6264 = (f32) ((f64) var_f4_6264 * (0.5 * temp_f1_6280 * -(((f64) var_f4_6264 * (temp_f1_6280 * temp_f1_6280)) - 3.0)));
        } else if (var_f4_6264 < M2C_BITWISE(f32, 0.0)) {
            var_f4_6264 = __float_nan;
        } else {
            sp8 = var_f4_6264;
            temp_r3_6299 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_6299) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_6309 = 1;
                } else {
                    var_r0_6309 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_6309 = 5;
                } else {
                    var_r0_6309 = 3;
                }
                break;
            default:
                var_r0_6309 = 4;
                break;
            }
            if (var_r0_6309 == 1) {
                var_f4_6264 = __float_nan;
            }
        }
        var_f3_6331 = 1.0f / var_f4_6264;
    } else {
        var_f3_6331 = 0.0f;
    }
    sp130 = (f32) sp130 * var_f3_6331;
    (*(f32 *) ((u8 *) &sp128 + 0xc)) *= var_f3_6331;
    sp138 = (f32) sp138 * var_f3_6331;
    if ((s32) this->unk4->unk3C8 != 0) {
        temp_f31_6353 = MKVector3::up.unk4;
        temp_f30_6355 = MKVector3::up.unk8;
        temp_f29_6357 = MKVector3::up.unk0;
        var_r31_6358 = 0;
        var_r28_6360 = 0;
loop_26:
        temp_r3_6450 = this->unk4;
        if (var_r31_6358 < (s32) temp_r3_6450->unk3C8) {
            sp44 = (temp_f30_6355 * sp130) - (temp_f29_6357 * sp138);
            sp40 = (temp_f31_6353 * sp138) - (temp_f30_6355 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp48 = (temp_f29_6357 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f31_6353 * sp130);
            spD0 = (f64) sp40;
            spD8 = (f64) sp48;
            sp120 = (f64) sp40;
            sp128 = (f64) sp48;
            spB0.operator*(temp_f28_6213);
            temp_r6_6387 = this->unk4;
            sp30 = M2C_FIELD(temp_r6_6387, f64 *, 0x378) + M2C_BITWISE(f64, spB0);
            sp110 = sp30;
            sp38 = temp_r6_6387->unk378.unk8 + spB0.unk8;
            spC0 = sp30;
            sp118 = (f64) sp38;
            spC8 = (f64) sp38;
            KDMath_Slerp(spA0, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_6387->unk3C8);
            sp130 = M2C_BITWISE(f64, spA0);
            sp138 = (f64) spA0.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_6360 + 0x84)), s32 *, 4) = 0x08004200;
            temp_r5_6423 = this->unk4;
            temp_r5_6423->unk2C0.AddSpawnPoint(temp_r5_6423 + (var_r28_6360 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_6360 + 0x90)))->SetIdentity();
            temp_r6_6432 = var_r28_6360 + 0x90;
            temp_r6_6435 = this->unk4 + temp_r6_6432;
            M2C_FIELD(temp_r6_6435, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_6435, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_6435, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_6435, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_6432))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r31_6358 += 1;
            var_r28_6360 += 0x60;
            goto loop_26;
        }
        temp_r3_6450->unk2C0.AddSpawnPointEnd();
    }
    temp_r3_6457 = this->unk4;
    if ((s32) temp_r3_6457->unk3CC != 0) {
        var_r30_6461 = temp_r3_6457->unk3C8;
        var_r28_6465 = var_r30_6461 * 0x60;
        temp_f29_6466 = MKVector3::up.unk4;
        temp_f30_6467 = MKVector3::up.unk8;
        temp_f31_6469 = MKVector3::up.unk0;
loop_31:
        temp_r4_6562 = this->unk4;
        if (var_r30_6461 < (s32) (temp_r4_6562->unk3C8 + temp_r4_6562->unk3CC)) {
            sp24 = (temp_f30_6467 * (f32) sp130) - (temp_f31_6469 * (f32) sp138);
            sp20 = (temp_f29_6466 * (f32) sp138) - (temp_f30_6467 * (*(f32 *) ((u8 *) &sp128 + 0xc)));
            sp28 = (temp_f31_6469 * (*(f32 *) ((u8 *) &sp128 + 0xc))) - (temp_f29_6466 * (f32) sp130);
            sp90 = (f64) sp20;
            sp98 = (f64) sp28;
            sp120 = (f64) sp20;
            sp128 = (f64) sp28;
            sp70.operator*(temp_f28_6213);
            temp_r6_6499 = this->unk4;
            sp10 = M2C_FIELD(temp_r6_6499, f64 *, 0x378) + M2C_BITWISE(f64, sp70);
            sp110 = sp10;
            sp18 = temp_r6_6499->unk378.unk8 + sp70.unk8;
            sp80 = sp10;
            sp118 = (f64) sp18;
            sp88 = (f64) sp18;
            KDMath_Slerp(sp60, *((MKVector3 *) &sp130), 6.2831855f / (f32) temp_r6_6499->unk3CC);
            sp130 = M2C_BITWISE(f64, sp60);
            sp138 = (f64) sp60.unk8;
            M2C_FIELD(*(this->unk4 + (var_r28_6465 + 0x84)), s32 *, 4) = 0x08004200;
            temp_r5_6535 = this->unk4;
            temp_r5_6535->unk310.AddSpawnPoint(temp_r5_6535 + (var_r28_6465 + 0x80));
            ((Matrix *) (this->unk4 + (var_r28_6465 + 0x90)))->SetIdentity();
            temp_r6_6544 = var_r28_6465 + 0x90;
            temp_r6_6547 = this->unk4 + temp_r6_6544;
            M2C_FIELD(temp_r6_6547, f32 *, 0x30) = (f32) sp110;
            M2C_FIELD(temp_r6_6547, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp110 + 0x4));
            M2C_FIELD(temp_r6_6547, f32 *, 0x38) = (f32) sp118;
            M2C_FIELD(temp_r6_6547, f32 *, 0x3C) = 1.0f;
            ((Matrix *) (this->unk4 + temp_r6_6544))->SetLookAt(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100));
            var_r30_6461 += 1;
            var_r28_6465 += 0x60;
            goto loop_31;
        }
        temp_r4_6562->unk310.AddSpawnPointEnd();
    }
}
#endif

void FireDojoLesson::SetupNumFuryEnemies() {
    DojoController *temp_r3_6603;
    DojoController *temp_r3_6608;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    if ((s32) this->unkC == 0) {
        temp_r3_6603 = this->unk4;
        temp_r3_6603->unk3C8 = temp_r3_6603->unk720;
        return;
    }
    temp_r3_6608 = this->unk4;
    temp_r3_6608->unk3CC = temp_r3_6608->unk724;
}

s32 FireDojoLesson::IsBreath2Complete() {
    return this->unk10 > 1;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void FireDojoLesson::SetupBreath2SpawnPoints() {
    CharacterGraphNode *sp60;
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    DojoController *temp_r3_6643;
    DojoController *temp_r3_6759;
    DojoController *temp_r3_6771;
    DojoController *temp_r3_6783;
    f32 temp_f4_6743;
    f32 temp_f5_6741;
    f32 temp_f6_6739;
    f32 var_f4_6654;
    f32 var_f5_6667;
    f64 temp_f0_6648;
    f64 temp_f1_6672;
    f64 temp_f1_6678;
    f64 temp_f1_6682;
    s32 temp_r0_6635;
    s32 temp_r3_6701;
    s32 var_r0_6711;

    temp_r0_6635 = this->unk10;
    switch (temp_r0_6635) {                         /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_r3_6643 = this->unk4;
        temp_f0_6648 = temp_r3_6643->unk388 - M2C_FIELD(temp_r3_6643, f64 *, 0x378);
        sp20 = temp_f0_6648;
        var_f4_6654 = 0.0f;
        sp50 = temp_f0_6648;
        sp28 = M2C_FIELD(temp_r3_6643, f32 *, 0x390) - temp_r3_6643->unk378.unk8;
        (*(f32 *) ((u8 *) &sp48 + 0xc)) = 0.0f;
        sp58 = (f64) sp28;
        var_f5_6667 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (0.0f * 0.0f));
        if (var_f5_6667 > 0.000001f) {
            if (var_f5_6667 > 0.0f) {
                temp_f1_6672 = __frsqrte(var_f5_6667);
                temp_f1_6678 = 0.5 * temp_f1_6672 * -(((f64) var_f5_6667 * (temp_f1_6672 * temp_f1_6672)) - 3.0);
                temp_f1_6682 = 0.5 * temp_f1_6678 * -(((f64) var_f5_6667 * (temp_f1_6678 * temp_f1_6678)) - 3.0);
                var_f5_6667 = (f32) ((f64) var_f5_6667 * (0.5 * temp_f1_6682 * -(((f64) var_f5_6667 * (temp_f1_6682 * temp_f1_6682)) - 3.0)));
            } else if (var_f5_6667 < M2C_BITWISE(f32, 0.0)) {
                var_f5_6667 = __float_nan;
            } else {
                sp8 = var_f5_6667;
                temp_r3_6701 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_6701) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_6711 = 1;
                    } else {
                        var_r0_6711 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_6711 = 5;
                    } else {
                        var_r0_6711 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_6711 = 4;
                    break;
                }
                if (var_r0_6711 == 1) {
                    var_f5_6667 = __float_nan;
                }
            }
            var_f4_6654 = 1.0f / var_f5_6667;
        }
        temp_f6_6739 = (f32) sp50 * var_f4_6654;
        temp_f5_6741 = (*(f32 *) ((u8 *) &sp48 + 0xc)) * var_f4_6654;
        temp_f4_6743 = (f32) sp58 * var_f4_6654;
        sp50 = temp_f6_6739;
        (*(f32 *) ((u8 *) &sp48 + 0xc)) = temp_f5_6741;
        sp10 = -temp_f6_6739;
        sp14 = -temp_f5_6741;
        sp18 = -temp_f4_6743;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
        temp_r3_6759 = this->unk4;
        sp58 = temp_f4_6743;
        sp40 = M2C_FIELD(temp_r3_6759, f64 *, 0x378);
        sp48 = (f64) M2C_FIELD(temp_r3_6759, f32 *, 0x380);
        temp_r3_6759->SetupSmashPropsVanguard(4, (MKVector3) &sp40, (MKVector3) &sp30, temp_r3_6759->unk6B0, 0U, 0U, 0.7853982f);
        return;
    case 1:                                         /* switch 1 */
        temp_r3_6771 = this->unk4;
        temp_r3_6771->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_6771->unk3DC, 2, 0x10, &sp60, 0U, 0.0f, 0.0f, 0x08004200U);
        temp_r3_6783 = this->unk4;
        temp_r3_6783->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_6783->unk3DC, 2, 0x10, &sp60, 0U, 0.0f, 0.0f, 0x08000A00U);
        return;
    }
}
#endif

void FireDojoLesson::SetupNumBreath2Enemies() {
    DojoController *temp_r3_6818;
    DojoController *temp_r3_6826;
    DojoController *temp_r4_6815;
    DojoController *temp_r4_6823;
    s32 temp_r0_6809;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_6809 = this->unk10;
    switch (temp_r0_6809) {                         /* irregular */
    case 0:
        temp_r4_6815 = this->unk4;
        temp_r4_6815->unk3C8 = temp_r4_6815->unk704;
        temp_r3_6818 = this->unk4;
        temp_r3_6818->unk3CC = temp_r3_6818->unk708;
        return;
    case 1:
        temp_r4_6823 = this->unk4;
        temp_r4_6823->unk3C8 = temp_r4_6823->unk710;
        temp_r3_6826 = this->unk4;
        temp_r3_6826->unk3CC = temp_r3_6826->unk714;
        return;
    }
}

s32 FireDojoLesson::IsBreath1Complete() {
    return this->unk10 > 1;
}

void FireDojoLesson::SetupBreath1SpawnPoints() {
    CharacterGraphNode *sp8;
    DojoController *temp_r3_6863;
    DojoController *temp_r3_6875;
    DojoController *temp_r3_6889;
    DojoController *temp_r3_6901;
    s32 temp_r0_6853;

    temp_r0_6853 = this->unk10;
    switch (temp_r0_6853) {                         /* irregular */
    case 0:
        temp_r3_6863 = this->unk4;
        temp_r3_6863->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_6863->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08004200U);
        temp_r3_6875 = this->unk4;
        temp_r3_6875->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_6875->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08004200U);
        return;
    case 1:
        temp_r3_6889 = this->unk4;
        temp_r3_6889->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_6889->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08001200U);
        temp_r3_6901 = this->unk4;
        temp_r3_6901->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_6901->unk3D8, 2, 0x10, &sp8, 0U, 0.0f, 0.0f, 0x08001200U);
        return;
    }
}

void FireDojoLesson::SetupNumBreath1Enemies() {
    DojoController *temp_r3_6936;
    DojoController *temp_r3_6944;
    DojoController *temp_r4_6933;
    DojoController *temp_r4_6941;
    s32 temp_r0_6927;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_6927 = this->unk10;
    switch (temp_r0_6927) {                         /* irregular */
    case 0:
        temp_r4_6933 = this->unk4;
        temp_r4_6933->unk3C8 = temp_r4_6933->unk6EC;
        temp_r3_6936 = this->unk4;
        temp_r3_6936->unk3CC = temp_r3_6936->unk6F0;
        return;
    case 1:
        temp_r4_6941 = this->unk4;
        temp_r4_6941->unk3C8 = temp_r4_6941->unk6F8;
        temp_r3_6944 = this->unk4;
        temp_r3_6944->unk3CC = temp_r3_6944->unk6FC;
        return;
    }
}

s32 FireDojoLesson::IsMeleeKnockBackComplete() {
    return this->unk10 > 3;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void FireDojoLesson::SetupMeleeKnockBackSpawnPoints() {
    CharacterGraphNode *sp190;
    f64 sp188;                                      /* compiler-managed */
    f64 sp180;                                      /* compiler-managed */
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
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    DojoController *temp_r3_6971;
    DojoController *temp_r3_7097;
    DojoController *temp_r3_7116;
    DojoController *temp_r3_7137;
    DojoController *temp_r3_7156;
    DojoController *temp_r3_7165;
    DojoController *temp_r3_7177;
    DojoController *temp_r3_7191;
    DojoController *temp_r3_7281;
    f32 temp_f1_7192;
    f32 temp_f4_7203;
    f32 temp_f5_7200;
    f32 var_f6_6982;
    f32 var_f7_6995;
    f64 temp_f0_7232;
    f64 temp_f2_6976;
    f64 temp_f2_7198;
    f64 temp_f2_7209;
    f64 temp_f3_7000;
    f64 temp_f3_7006;
    f64 temp_f3_7010;
    f64 temp_f6_7197;
    f64 temp_f7_7196;
    s32 temp_r0_7068;
    s32 temp_r3_7029;
    s32 var_r0_7039;

    temp_r3_6971 = this->unk4;
    temp_f2_6976 = temp_r3_6971->unk388 - M2C_FIELD(temp_r3_6971, f64 *, 0x378);
    sp70 = temp_f2_6976;
    var_f6_6982 = 0.0f;
    sp180 = temp_f2_6976;
    sp78 = M2C_FIELD(temp_r3_6971, f32 *, 0x390) - temp_r3_6971->unk378.unk8;
    (*(f32 *) ((u8 *) &sp178 + 0xc)) = 0.0f;
    sp188 = (f64) sp78;
    var_f7_6995 = ((f32) sp188 * (f32) sp188) + (((f32) sp180 * (f32) sp180) + (0.0f * 0.0f));
    if (var_f7_6995 > 0.000001f) {
        if (var_f7_6995 > 0.0f) {
            temp_f3_7000 = __frsqrte(var_f7_6995);
            temp_f3_7006 = 0.5 * temp_f3_7000 * -(((f64) var_f7_6995 * (temp_f3_7000 * temp_f3_7000)) - 3.0);
            temp_f3_7010 = 0.5 * temp_f3_7006 * -(((f64) var_f7_6995 * (temp_f3_7006 * temp_f3_7006)) - 3.0);
            var_f7_6995 = (f32) ((f64) var_f7_6995 * (0.5 * temp_f3_7010 * -(((f64) var_f7_6995 * (temp_f3_7010 * temp_f3_7010)) - 3.0)));
        } else if (var_f7_6995 < M2C_BITWISE(f32, 0.0)) {
            var_f7_6995 = __float_nan;
        } else {
            sp8 = var_f7_6995;
            temp_r3_7029 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_7029) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_7039 = 1;
                } else {
                    var_r0_7039 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_7039 = 5;
                } else {
                    var_r0_7039 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_7039 = 4;
                break;
            }
            if (var_r0_7039 == 1) {
                var_f7_6995 = __float_nan;
            }
        }
        var_f6_6982 = 1.0f / var_f7_6995;
    }
    temp_r0_7068 = this->unk10;
    sp180 = (f32) sp180 * var_f6_6982;
    (*(f32 *) ((u8 *) &sp178 + 0xc)) *= var_f6_6982;
    sp188 = (f32) sp188 * var_f6_6982;
    switch (temp_r0_7068) {                         /* switch 2; irregular */
    case 0:                                         /* switch 2 */
        sp160 = (f64) sp180;
        sp168 = (f64) sp188;
        temp_r3_7097 = this->unk4;
        sp170 = M2C_FIELD(temp_r3_7097, f64 *, 0x378);
        sp178 = M2C_FIELD(temp_r3_7097, f64 *, 0x380);
        temp_r3_7097->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &sp170, (MKVector3) &sp160, temp_r3_7097->unk6E4, 1U, 1U, 0.62831855f, 0x08800200U);
        sp140 = (f64) sp180;
        sp148 = (f64) sp188;
        temp_r3_7116 = this->unk4;
        sp150 = M2C_FIELD(temp_r3_7116, f64 *, 0x378);
        sp158 = M2C_FIELD(temp_r3_7116, f64 *, 0x380);
        temp_r3_7116->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp150, (MKVector3) &sp140, temp_r3_7116->unk6E4, 1U, 1U, 0.62831855f, 0x08800200U);
        return;
    case 1:                                         /* switch 2 */
        sp120 = (f64) sp180;
        sp128 = (f64) sp188;
        temp_r3_7137 = this->unk4;
        sp130 = M2C_FIELD(temp_r3_7137, f64 *, 0x378);
        sp138 = M2C_FIELD(temp_r3_7137, f64 *, 0x380);
        temp_r3_7137->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &sp130, (MKVector3) &sp120, temp_r3_7137->unk6E4, 1U, 1U, 0.62831855f, 0x08800200U);
        sp100 = (f64) sp180;
        sp108 = (f64) sp188;
        temp_r3_7156 = this->unk4;
        sp110 = M2C_FIELD(temp_r3_7156, f64 *, 0x378);
        sp118 = M2C_FIELD(temp_r3_7156, f64 *, 0x380);
        temp_r3_7156->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp110, (MKVector3) &sp100, temp_r3_7156->unk6E4, 1U, 1U, 0.62831855f, 0x08800200U);
        return;
    case 2:                                         /* switch 2 */
        temp_r3_7165 = this->unk4;
        temp_r3_7165->SetupSpawnPointsRandomGraph((DojoTiers) 0, temp_r3_7165->unk3DC, 2, 0x10, &sp190, 1U, 1500.0f, 800.0f, 0x08800200U);
        temp_r3_7177 = this->unk4;
        temp_r3_7177->SetupSpawnPointsRandomGraph((DojoTiers) 1, temp_r3_7177->unk3DC, 2, 0x10, &sp190, 1U, 1500.0f, 800.0f, 0x08800200U);
        return;
    case 3:                                         /* switch 2 */
        temp_r3_7191 = this->unk4;
        temp_f1_7192 = temp_r3_7191->unk728;
        temp_f7_7196 = M2C_FIELD(temp_r3_7191, f64 *, 0x378);
        temp_f6_7197 = temp_r3_7191->unk388;
        temp_f2_7198 = temp_f7_7196 - temp_f6_7197;
        sp60 = temp_f2_7198;
        temp_f5_7200 = temp_r3_7191->unk378.unk8;
        temp_f4_7203 = temp_f5_7200 - M2C_FIELD(temp_r3_7191, f32 *, 0x390);
        spE0 = temp_f2_7198;
        sp68 = temp_f4_7203;
        spE8 = (f64) sp68;
        temp_f2_7209 = temp_f2_7198 * (f64) temp_f1_7192;
        sp50 = temp_f2_7209;
        spF0 = temp_f2_7209;
        sp58 = (f32) spE8 * temp_f1_7192;
        spF8 = (f64) sp58;
        sp40 = temp_f7_7196 + spF0;
        sp48 = temp_f5_7200 + (f32) spF8;
        sp30 = temp_f7_7196 - temp_f6_7197;
        sp38 = temp_f4_7203;
        spC0 = sp30;
        spC8 = (f64) sp38;
        temp_f0_7232 = spC0 * (f64) temp_f1_7192;
        sp20 = temp_f0_7232;
        spD0 = temp_f0_7232;
        sp28 = (f32) spC8 * temp_f1_7192;
        spD8 = (f64) sp28;
        sp10 = temp_f7_7196 - temp_f0_7232;
        spA0 = (f64) sp180;
        spA8 = (f64) sp188;
        spB0 = sp40;
        spB8 = (f64) sp48;
        sp18 = temp_f5_7200 - (f32) spD8;
        temp_r3_7191->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &spB0, (MKVector3) &spA0, temp_r3_7191->unk6E4, 1U, 1U, 0.7853982f, 0x08800200U);
        sp80 = (f64) sp180;
        sp88 = (f64) sp188;
        sp90 = sp10;
        sp98 = (f64) sp18;
        temp_r3_7281 = this->unk4;
        temp_r3_7281->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp90, (MKVector3) &sp80, temp_r3_7281->unk6E4, 1U, 1U, 0.62831855f, 0x08004200U);
        return;
    }
}
#endif

void FireDojoLesson::SetupNumMeleeKnockBackEnemies() {
    DojoController *temp_r5_7313;
    DojoController *temp_r5_7317;
    DojoController *temp_r5_7324;
    DojoController *temp_r5_7328;
    DojoController *temp_r5_7335;
    DojoController *temp_r5_7339;
    DojoController *temp_r5_7346;
    DojoController *temp_r5_7350;
    s32 temp_r0_7300;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_7300 = this->unk10;
    switch (temp_r0_7300) {                         /* irregular */
    case 0:
        temp_r5_7313 = this->unk4;
        temp_r5_7313->unk3C8 = temp_r5_7313->unk6B4;
        temp_r5_7317 = this->unk4;
        temp_r5_7317->unk3CC = temp_r5_7317->unk6B8;
        this->unk4->unk674 = 3;
        return;
    case 1:
        temp_r5_7324 = this->unk4;
        temp_r5_7324->unk3C8 = temp_r5_7324->unk6C0;
        temp_r5_7328 = this->unk4;
        temp_r5_7328->unk3CC = temp_r5_7328->unk6C4;
        this->unk4->unk674 = 6;
        return;
    case 2:
        temp_r5_7335 = this->unk4;
        temp_r5_7335->unk3C8 = temp_r5_7335->unk6CC;
        temp_r5_7339 = this->unk4;
        temp_r5_7339->unk3CC = temp_r5_7339->unk6D0;
        this->unk4->unk674 = 3;
        return;
    case 3:
        temp_r5_7346 = this->unk4;
        temp_r5_7346->unk3C8 = temp_r5_7346->unk6D8;
        temp_r5_7350 = this->unk4;
        temp_r5_7350->unk3CC = temp_r5_7350->unk6DC;
        this->unk4->unk674 = 3;
        return;
    }
}

s32 FireDojoLesson::IsMeleeKnockUpComplete() {
    return this->unk10 > 3;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void FireDojoLesson::SetupMeleeKnockUpSpawnPoints() {
    f64 sp148;                                      /* compiler-managed */
    f64 sp140;                                      /* compiler-managed */
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
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    DojoController *temp_r3_7385;
    DojoController *temp_r3_7511;
    DojoController *temp_r3_7530;
    DojoController *temp_r3_7551;
    DojoController *temp_r3_7570;
    DojoController *temp_r3_7597;
    DojoController *temp_r3_7619;
    DojoController *temp_r3_7640;
    DojoController *temp_r3_7659;
    f32 temp_f0_7483;
    f32 temp_f1_7481;
    f32 temp_f29_7583;
    f32 temp_f2_7480;
    f32 temp_f30_7581;
    f32 temp_f31_7579;
    f32 var_f4_7396;
    f32 var_f5_7409;
    f64 temp_f0_7390;
    f64 temp_f1_7414;
    f64 temp_f1_7420;
    f64 temp_f1_7424;
    s32 temp_r0_7482;
    s32 temp_r3_7443;
    s32 var_r0_7453;

    temp_r3_7385 = this->unk4;
    temp_f0_7390 = temp_r3_7385->unk388 - M2C_FIELD(temp_r3_7385, f64 *, 0x378);
    sp30 = temp_f0_7390;
    var_f4_7396 = 0.0f;
    sp140 = temp_f0_7390;
    sp38 = M2C_FIELD(temp_r3_7385, f32 *, 0x390) - temp_r3_7385->unk378.unk8;
    (*(f32 *) ((u8 *) &sp138 + 0xc)) = 0.0f;
    sp148 = (f64) sp38;
    var_f5_7409 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + (0.0f * 0.0f));
    if (var_f5_7409 > 0.000001f) {
        if (var_f5_7409 > 0.0f) {
            temp_f1_7414 = __frsqrte(var_f5_7409);
            temp_f1_7420 = 0.5 * temp_f1_7414 * -(((f64) var_f5_7409 * (temp_f1_7414 * temp_f1_7414)) - 3.0);
            temp_f1_7424 = 0.5 * temp_f1_7420 * -(((f64) var_f5_7409 * (temp_f1_7420 * temp_f1_7420)) - 3.0);
            var_f5_7409 = (f32) ((f64) var_f5_7409 * (0.5 * temp_f1_7424 * -(((f64) var_f5_7409 * (temp_f1_7424 * temp_f1_7424)) - 3.0)));
        } else if (var_f5_7409 < M2C_BITWISE(f32, 0.0)) {
            var_f5_7409 = __float_nan;
        } else {
            sp8 = var_f5_7409;
            temp_r3_7443 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_7443) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_7453 = 1;
                } else {
                    var_r0_7453 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_7453 = 5;
                } else {
                    var_r0_7453 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_7453 = 4;
                break;
            }
            if (var_r0_7453 == 1) {
                var_f5_7409 = __float_nan;
            }
        }
        var_f4_7396 = 1.0f / var_f5_7409;
    }
    temp_f2_7480 = (f32) sp140 * var_f4_7396;
    temp_f1_7481 = (*(f32 *) ((u8 *) &sp138 + 0xc)) * var_f4_7396;
    temp_r0_7482 = this->unk10;
    temp_f0_7483 = (f32) sp148 * var_f4_7396;
    sp140 = temp_f2_7480;
    (*(f32 *) ((u8 *) &sp138 + 0xc)) = temp_f1_7481;
    sp148 = temp_f0_7483;
    switch (temp_r0_7482) {                         /* switch 2; irregular */
    case 0:                                         /* switch 2 */
        sp120 = (f64) sp140;
        sp128 = (f64) sp148;
        temp_r3_7511 = this->unk4;
        sp130 = M2C_FIELD(temp_r3_7511, f64 *, 0x378);
        sp138 = M2C_FIELD(temp_r3_7511, f64 *, 0x380);
        temp_r3_7511->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &sp130, (MKVector3) &sp120, temp_r3_7511->unk6B0, 1U, 1U, 0.62831855f, 0x08800200U);
        sp100 = (f64) sp140;
        sp108 = (f64) sp148;
        temp_r3_7530 = this->unk4;
        sp110 = M2C_FIELD(temp_r3_7530, f64 *, 0x378);
        sp118 = M2C_FIELD(temp_r3_7530, f64 *, 0x380);
        temp_r3_7530->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp110, (MKVector3) &sp100, temp_r3_7530->unk6B0, 1U, 1U, 0.62831855f, 0x08800200U);
        return;
    case 1:                                         /* switch 2 */
        spE0 = (f64) sp140;
        spE8 = (f64) sp148;
        temp_r3_7551 = this->unk4;
        spF0 = M2C_FIELD(temp_r3_7551, f64 *, 0x378);
        spF8 = M2C_FIELD(temp_r3_7551, f64 *, 0x380);
        temp_r3_7551->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &spF0, (MKVector3) &spE0, temp_r3_7551->unk6B0, 1U, 1U, 0.62831855f, 0x08800200U);
        spC0 = (f64) sp140;
        spC8 = (f64) sp148;
        temp_r3_7570 = this->unk4;
        spD0 = M2C_FIELD(temp_r3_7570, f64 *, 0x378);
        spD8 = M2C_FIELD(temp_r3_7570, f64 *, 0x380);
        temp_r3_7570->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &spD0, (MKVector3) &spC0, temp_r3_7570->unk6B0, 1U, 1U, 0.62831855f, 0x08800200U);
        return;
    case 2:                                         /* switch 2 */
        temp_f31_7579 = -temp_f2_7480;
        temp_f30_7581 = -temp_f1_7481;
        temp_f29_7583 = -temp_f0_7483;
        sp20 = temp_f31_7579;
        sp24 = temp_f30_7581;
        sp28 = temp_f29_7583;
        spA0 = (f64) sp20;
        spA8 = (f64) sp28;
        temp_r3_7597 = this->unk4;
        spB0 = M2C_FIELD(temp_r3_7597, f64 *, 0x378);
        spB8 = M2C_FIELD(temp_r3_7597, f64 *, 0x380);
        temp_r3_7597->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &spB0, (MKVector3) &spA0, temp_r3_7597->unk6B0, 0U, 0U, 0.62831855f, 0x08800200U);
        sp18 = temp_f29_7583;
        sp10 = temp_f31_7579;
        sp14 = temp_f30_7581;
        sp88 = (f64) sp18;
        sp80 = (f64) sp10;
        temp_r3_7619 = this->unk4;
        sp90 = M2C_FIELD(temp_r3_7619, f64 *, 0x378);
        sp98 = M2C_FIELD(temp_r3_7619, f64 *, 0x380);
        temp_r3_7619->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp90, (MKVector3) &sp80, temp_r3_7619->unk6B0, 0U, 0U, 0.62831855f, 0x08800200U);
        return;
    case 3:                                         /* switch 2 */
        sp60 = (f64) sp140;
        sp68 = (f64) sp148;
        temp_r3_7640 = this->unk4;
        sp70 = M2C_FIELD(temp_r3_7640, f64 *, 0x378);
        sp78 = M2C_FIELD(temp_r3_7640, f64 *, 0x380);
        temp_r3_7640->SetupSpawnPointsVanguard((DojoTiers) 0, (MKVector3) &sp70, (MKVector3) &sp60, temp_r3_7640->unk6B0, 1U, 1U, 0.62831855f, 0x08004200U);
        sp40 = (f64) sp140;
        sp48 = (f64) sp148;
        temp_r3_7659 = this->unk4;
        sp50 = M2C_FIELD(temp_r3_7659, f64 *, 0x378);
        sp58 = M2C_FIELD(temp_r3_7659, f64 *, 0x380);
        temp_r3_7659->SetupSpawnPointsVanguard((DojoTiers) 1, (MKVector3) &sp50, (MKVector3) &sp40, temp_r3_7659->unk6B0, 1U, 1U, 0.62831855f, 0x08004200U);
        return;
    }
}
#endif

void FireDojoLesson::SetupNumMeleeKnockUpEnemies() {
    DojoController *temp_r5_7701;
    DojoController *temp_r5_7705;
    DojoController *temp_r5_7712;
    DojoController *temp_r5_7716;
    DojoController *temp_r5_7723;
    DojoController *temp_r5_7727;
    DojoController *temp_r5_7734;
    DojoController *temp_r5_7738;
    s32 temp_r0_7688;

    this->unk4->unk3C8 = 0;
    this->unk4->unk3CC = 0;
    temp_r0_7688 = this->unk10;
    switch (temp_r0_7688) {                         /* irregular */
    case 0:
        temp_r5_7701 = this->unk4;
        temp_r5_7701->unk3C8 = temp_r5_7701->unk680;
        temp_r5_7705 = this->unk4;
        temp_r5_7705->unk3CC = temp_r5_7705->unk684;
        this->unk4->unk674 = 1;
        return;
    case 1:
        temp_r5_7712 = this->unk4;
        temp_r5_7712->unk3C8 = temp_r5_7712->unk68C;
        temp_r5_7716 = this->unk4;
        temp_r5_7716->unk3CC = temp_r5_7716->unk690;
        this->unk4->unk674 = 5;
        return;
    case 2:
        temp_r5_7723 = this->unk4;
        temp_r5_7723->unk3C8 = temp_r5_7723->unk698;
        temp_r5_7727 = this->unk4;
        temp_r5_7727->unk3CC = temp_r5_7727->unk69C;
        this->unk4->unk674 = 2;
        return;
    case 3:
        temp_r5_7734 = this->unk4;
        temp_r5_7734->unk3C8 = temp_r5_7734->unk6A4;
        temp_r5_7738 = this->unk4;
        temp_r5_7738->unk3CC = temp_r5_7738->unk6A8;
        this->unk4->unk674 = 8;
        return;
    }
}

void FireDojoLesson::MakeChildrenInvulnerable() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r0_7754;

    temp_r0_7754 = this->unk8;
    if (temp_r0_7754 < 3) {
        if (temp_r0_7754 != 0) {
            if (temp_r0_7754 < 0) {
                return;
            }
            sp14 = 0;
            sp10 = 0x165;
            this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp10);
            this->unk4->unk310.SendMessageToActive((MKMessage *) &sp10);
            return;
        }
        goto block_7;
    }
    if (temp_r0_7754 < 5) {
block_7:
        spC = 0;
        sp8 = 0x161;
        this->unk4->unk2C0.SendMessageToActive((MKMessage *) &sp8);
        this->unk4->unk310.SendMessageToActive((MKMessage *) &sp8);
    }
}

void FireDojoLesson::TurnOffAbilities() {
    s32 temp_r0_7803;

    temp_r0_7803 = this->unk8;
    switch (temp_r0_7803) {                         /* irregular */
    case 1:
        if ((s32) this->unk10 != 2) {
            M2C_FIELD(&gb, s8 *, 6) = 0;
        }
        M2C_FIELD(&gb, s8 *, 7) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    case 2:
        M2C_FIELD(&gb, s8 *, 7) = 0;
        M2C_FIELD(&gb, s8 *, 6) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    case 0:
        M2C_FIELD(&gb, s8 *, 7) = 0;
        M2C_FIELD(&gb, s8 *, 8) = 0;
        M2C_FIELD(&gb, s8 *, 5) = 0;
        return;
    case 3:
        M2C_FIELD(&gb, s8 *, 8) = 0;
        return;
    case 4:
        return;
    }
}

#if 0 // DRAFT: function call 'DialogBox_ColorButtons(signed char *, signed char *, int,
void FireDojoLesson::IncrementNumInterations() {
    s8 *sp14;
    s32 spC;
    s32 sp8;
    s32 temp_r0_7863;
    s32 temp_r4_7888;

    temp_r0_7863 = this->unk8;
    switch (temp_r0_7863) {                         /* irregular */
    case 1:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 2:
        if ((s32) this->unk10 == 2) {
            temp_r4_7888 = this->unkC;
            if (temp_r4_7888 < (s32) (this->unk4->unk6E8 - 1)) {
                this->unkC = temp_r4_7888 + 1;
                return;
            }
            this->unkC = 0;
            this->unk10 += 1;
            return;
        }
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 0:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 3:
        this->unkC = 0;
        this->unk10 += 1;
        return;
    case 4:
        this->unk4->unk3D0 = 0;
        this->unk4->unk3D4 = 0;
        if ((s32) this->unkC != 0) {
            if (HasSucceededFury() != 0) {
                this->unk10 += 1;
                return;
            }
        } else {
            if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                DialogBox_ColorButtons(M2C_FIELD(gpTranslation_StringArray, s8 **, 0x6DC), &this->unk4->unk468, 0, 0x200);
                spC = 0;
                spC = 0;
                sp14 = &this->unk4->unk468;
                sp8 = 0x96;
                InGame_SystemMessage((MKMessage *) &sp8);
                this->unkC = 1;
                return;
            }
            this->unkC = 0;
            return;
        }
        break;
    }
}
#endif

u8 FireDojoLesson::IsLessonComplete() {
    return (u8) (this->unk8 == 4);
}

s32 FireDojoLesson::IsSubLessonComplete() {
    s32 temp_r0_7994;

    temp_r0_7994 = this->unk8;
    switch (temp_r0_7994) {                         /* irregular */
    case 0:
        return IsBreath1Complete();
    case 2:
        return IsMeleeKnockBackComplete();
    case 4:
        return FireDojoLesson::IsFuryComplete();
    case 3:
        return IsBreath2Complete();
    case 1:
        return IsMeleeKnockUpComplete();
    default:
        return 0;
    }
}

#if 0 // DRAFT: case constant defined more than once
void FireDojoLesson::SetupTimer() {
    DojoController *temp_r4_8425;
    DojoController *temp_r7_8052;
    DojoController *temp_r7_8081;
    DojoController *temp_r7_8110;
    DojoController *temp_r7_8139;
    DojoController *temp_r7_8174;
    DojoController *temp_r7_8203;
    DojoController *temp_r7_8232;
    DojoController *temp_r7_8261;
    DojoController *temp_r7_8296;
    DojoController *temp_r7_8325;
    DojoController *temp_r7_8360;
    DojoController *temp_r7_8389;
    f32 var_f0_8434;
    s32 temp_r0_8035;
    s32 temp_r0_8053;
    s32 temp_r0_8082;
    s32 temp_r0_8111;
    s32 temp_r0_8140;
    s32 temp_r0_8175;
    s32 temp_r0_8204;
    s32 temp_r0_8233;
    s32 temp_r0_8262;
    s32 temp_r0_8297;
    s32 temp_r0_8326;
    s32 temp_r0_8361;
    s32 temp_r0_8390;
    s32 temp_r4_8049;
    s32 temp_r4_8171;
    s32 temp_r4_8293;
    s32 temp_r4_8357;

    temp_r0_8035 = this->unk8;
    switch (temp_r0_8035) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_r4_8049 = this->unk10;
        switch (temp_r4_8049) {                     /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            temp_r7_8052 = this->unk4;
            temp_r0_8053 = temp_r7_8052->unk688;
            if (temp_r0_8053 != 0) {
                temp_r7_8052->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8053 * temp_r7_8052->unk3B8) + (f32) temp_r0_8053);
                this->unk4->unk3BF = 1;
            } else {
                switch (temp_r4_8049) {             /* switch 3; irregular */
                case 1:                             /* switch 2 */
                case 1:                             /* switch 3 */
                    temp_r7_8081 = this->unk4;
                    temp_r0_8082 = temp_r7_8081->unk694;
                    if (temp_r0_8082 != 0) {
                        temp_r7_8081->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8082 * temp_r7_8081->unk3B8) + (f32) temp_r0_8082);
                        this->unk4->unk3BF = 1;
                    } else if ((temp_r4_8049 == 2) && (temp_r7_8110 = this->unk4, temp_r0_8111 = temp_r7_8110->unk6A0, ((temp_r0_8111 == 0) == 0))) {
                        temp_r7_8110->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8111 * temp_r7_8110->unk3B8) + (f32) temp_r0_8111);
                        this->unk4->unk3BF = 1;
                    } else if ((temp_r4_8049 == 3) && (temp_r7_8139 = this->unk4, temp_r0_8140 = temp_r7_8139->unk6AC, ((temp_r0_8140 == 0) == 0))) {
                        temp_r7_8139->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8140 * temp_r7_8139->unk3B8) + (f32) temp_r0_8140);
                        this->unk4->unk3BF = 1;
                    } else {
                    default:                        /* switch 2 */
                    default:                        /* switch 3 */
                        this->unk4->unk3BF = 0;
                    }
                    break;
                }
            }
            break;
        }
        break;
    case 2:                                         /* switch 1 */
        temp_r4_8171 = this->unk10;
        switch (temp_r4_8171) {                     /* switch 4; irregular */
        case 0:                                     /* switch 4 */
            temp_r7_8174 = this->unk4;
            temp_r0_8175 = temp_r7_8174->unk6BC;
            if (temp_r0_8175 != 0) {
                temp_r7_8174->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8175 * temp_r7_8174->unk3B8) + (f32) temp_r0_8175);
                this->unk4->unk3BF = 1;
            } else {
                switch (temp_r4_8171) {             /* switch 5; irregular */
                case 1:                             /* switch 4 */
                case 1:                             /* switch 5 */
                    temp_r7_8203 = this->unk4;
                    temp_r0_8204 = temp_r7_8203->unk6C8;
                    if (temp_r0_8204 != 0) {
                        temp_r7_8203->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8204 * temp_r7_8203->unk3B8) + (f32) temp_r0_8204);
                        this->unk4->unk3BF = 1;
                    } else if ((temp_r4_8171 == 2) && (temp_r7_8232 = this->unk4, temp_r0_8233 = temp_r7_8232->unk6D4, ((temp_r0_8233 == 0) == 0))) {
                        temp_r7_8232->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8233 * temp_r7_8232->unk3B8) + (f32) temp_r0_8233);
                        this->unk4->unk3BF = 1;
                    } else if ((temp_r4_8171 == 3) && (temp_r7_8261 = this->unk4, temp_r0_8262 = temp_r7_8261->unk6E0, ((temp_r0_8262 == 0) == 0))) {
                        temp_r7_8261->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8262 * temp_r7_8261->unk3B8) + (f32) temp_r0_8262);
                        this->unk4->unk3BF = 1;
                    } else {
                    default:                        /* switch 4 */
                    default:                        /* switch 5 */
                        this->unk4->unk3BF = 0;
                    }
                    break;
                }
            }
            break;
        }
        break;
    case 0:                                         /* switch 1 */
        temp_r4_8293 = this->unk10;
        if ((temp_r4_8293 == 0) && (temp_r7_8296 = this->unk4, temp_r0_8297 = temp_r7_8296->unk6F4, ((temp_r0_8297 == 0) == 0))) {
            temp_r7_8296->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8297 * temp_r7_8296->unk3B8) + (f32) temp_r0_8297);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_8293 == 1) && (temp_r7_8325 = this->unk4, temp_r0_8326 = temp_r7_8325->unk700, ((temp_r0_8326 == 0) == 0))) {
            temp_r7_8325->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8326 * temp_r7_8325->unk3B8) + (f32) temp_r0_8326);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 3:                                         /* switch 1 */
        temp_r4_8357 = this->unk10;
        if ((temp_r4_8357 == 0) && (temp_r7_8360 = this->unk4, temp_r0_8361 = temp_r7_8360->unk70C, ((temp_r0_8361 == 0) == 0))) {
            temp_r7_8360->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8361 * temp_r7_8360->unk3B8) + (f32) temp_r0_8361);
            this->unk4->unk3BF = 1;
        } else if ((temp_r4_8357 == 1) && (temp_r7_8389 = this->unk4, temp_r0_8390 = temp_r7_8389->unk718, ((temp_r0_8390 == 0) == 0))) {
            temp_r7_8389->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + (((f32) temp_r0_8390 * temp_r7_8389->unk3B8) + (f32) temp_r0_8390);
            this->unk4->unk3BF = 1;
        } else {
            this->unk4->unk3BF = 0;
        }
        break;
    case 4:                                         /* switch 1 */
        this->unk4->unk3BF = 0;
        break;
    }
    temp_r4_8425 = this->unk4;
    if ((u8) temp_r4_8425->unk3BF != 0) {
        var_f0_8434 = temp_r4_8425->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
        if (var_f0_8434 > 0.0f) {

        } else {
            var_f0_8434 = 0.0f;
        }
        temp_r4_8425->unk814 = var_f0_8434;
    }
}
#endif

void FireDojoLesson::SetupSpawnPoints() {
    s32 temp_r0_8453;

    temp_r0_8453 = this->unk8;
    switch (temp_r0_8453) {                         /* irregular */
    case 0:
        SetupBreath1SpawnPoints();
        return;
    case 1:
        SetupMeleeKnockUpSpawnPoints();
        return;
    case 2:
        SetupMeleeKnockBackSpawnPoints();
        return;
    case 3:
        SetupBreath2SpawnPoints();
        return;
    case 4:
        SetupFurySpawnPoints();
        return;
    }
}

void FireDojoLesson::SetupNumEnemies() {
    s32 temp_r0_8493;

    temp_r0_8493 = this->unk8;
    switch (temp_r0_8493) {                         /* irregular */
    case 0:
        SetupNumBreath1Enemies();
        return;
    case 1:
        SetupNumMeleeKnockUpEnemies();
        return;
    case 2:
        SetupNumMeleeKnockBackEnemies();
        return;
    case 3:
        SetupNumBreath2Enemies();
        return;
    case 4:
        SetupNumFuryEnemies();
        return;
    }
}

void DojoController::StateDojoStatueUpExit() {

}

void DojoController::StateDojoStatueUpUpdate() {
    if (this->unk404->IsUp() != 0) {
        switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            this->unk4C.Send((MKProp *) this);
            break;
        case 1:                                     /* switch 1 */
            this->unk50.Send((MKProp *) this);
            break;
        case 2:                                     /* switch 1 */
            this->unk54.Send((MKProp *) this);
            break;
        case 3:                                     /* switch 1 */
            this->unk58.Send((MKProp *) this);
            break;
        }
        switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            M2C_FIELD(GameData::gameData, s32 *, 0x18C) = 1;
            break;
        case 1:                                     /* switch 2 */
            M2C_FIELD(GameData::gameData, s32 *, 0x18C) = 2;
            break;
        case 2:                                     /* switch 2 */
            M2C_FIELD(GameData::gameData, s32 *, 0x18C) = 3;
            break;
        case 3:                                     /* switch 2 */
            M2C_FIELD(GameData::gameData, s32 *, 0x18C) = 0;
            break;
        }
        this->unk360.SetState(this, 0, 0U);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void DojoController::StateDojoStatueUpEnter() {
    s8 sp3A;
    s8 sp39;
    s8 sp38;
    s8 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    DragonStatue *temp_r3_8631;
    DragonStatue *temp_r3_8638;
    DragonStatue *temp_r3_8651;

    temp_r3_8631 = this->unk404;
    sp14 = 0;
    sp10 = 0xBE;
    temp_r3_8631->Message(&sp10, 0);
    temp_r3_8638 = this->unk404;
    temp_r3_8638->Enable();
    if ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C) == 0) {
        this->unk404->SnapDown();
    }
    temp_r3_8651 = this->unk404;
    spC = 0;
    sp8 = 0xB5;
    temp_r3_8651->Message(&sp8, 0);
    M2C_FIELD(&gb, s8 *, 4) = 1;
    ((GameGlobals *) &gb)->InfiniteMagicOff();
    sp1C = 0;
    sp18 = 0xE;
    sp38 = 0;
    sp39 = 1;
    sp20 = this->unk388;
    sp28 = this->unk390;
    sp30 = -1.35f;
    sp34 = 0;
    sp3A = 1;
    sp39 = 1;
    sp38 = 1;
    ((GameGlobals *) &gb)->GetSpyro();
    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
}
#endif

void DojoController::StateDojoFinishExit() {

}

void DojoController::StateDojoFinishUpdate() {
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk3B0) {
        this->unk360.SetState(this, 7, 0U);
        M2C_FIELD(&gb, s8 *, 5) = 1;
        M2C_FIELD(&gb, s8 *, 6) = 1;
        M2C_FIELD(&gb, s8 *, 7) = 1;
        M2C_FIELD(&gb, s8 *, 4) = 1;
        M2C_FIELD(&gb, s8 *, 8) = 1;
        ((GameGlobals *) &gb)->InfiniteMagicOff();
        return;
    }
    ((GameGlobals *) &gb)->GetSpyro();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        ((GameGlobals *) &gb)->GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->BroadcaseCollectRequestMessage(7500.0f);
    }
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char[17])' does not match
void DojoController::StateDojoFinishEnter() {
    if (PhrasePlayer_IsAnyEventPlaying() == 0) {
        this->unk7F0 = 1;
        this->unk39C = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
        case 0:
            strcpy(&this->unk7F1, "FireDojoComplete");
            break;
        case 2:
            strcpy(&this->unk7F1, "IceDojoComplete");
            break;
        case 3:
            strcpy(&this->unk7F1, "EarthDojoComplete");
            break;
        case 1:
            strcpy(&this->unk7F1, "ElectricityDojoComplete");
            break;
        }
    }
    M2C_FIELD(&gb, s8 *, 0xA) = 0;
    ((GameGlobals *) &gb)->GetSpyro();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        ((GameGlobals *) &gb)->GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->BroadcaseCollectRequestMessage(7500.0f);
    }
    this->unk3B0 = M2C_FIELD(&gb, f32 *, 0x30C) + 4.0f;
}
#endif

void DojoController::StateDojoSuccessExit() {
    M2C_FIELD(&gb, s8 *, 5) = 1;
    M2C_FIELD(&gb, s8 *, 6) = 1;
    M2C_FIELD(&gb, s8 *, 7) = 1;
    M2C_FIELD(&gb, s8 *, 8) = 1;
}

void DojoController::StateDojoSuccessUpdate() {
    DojoController *sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_8909;
    MKSceneManager *temp_r3_8919;
    MKSceneManager *temp_r3_8931;
    MKSceneManager *temp_r3_8941;
    MKSceneManager *temp_r3_8957;
    MKSceneManager *temp_r3_8967;
    MKSceneManager *temp_r3_8979;
    MKSceneManager *temp_r3_8989;
    MKSceneManager *temp_r3_9012;
    MKSceneManager *temp_r3_9022;
    MKSceneManager *temp_r3_9034;
    MKSceneManager *temp_r3_9044;
    MKSceneManager *temp_r3_9061;
    MKSceneManager *temp_r3_9071;
    MKSceneManager *temp_r3_9081;
    MKSceneManager *temp_r3_9091;
    f32 var_f0_9118;
    s32 temp_r4_9002;
    void **temp_r3_9001;

    if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk66C) {
        sp8C = NULL;
        sp88 = 0x163;
        sp8C = this;
        InGame_SystemMessage((MKMessage *) &sp88);
    }
    this->unk2C0.GetNumberActive();
    if (((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) && (this->unk310.GetNumberActive(), (((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0))) {
        if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk398) && (PhrasePlayer_IsEventPlaying(this->unk7EC) == 0) && ((s32) this->unk7EC == 0)) {
            if ((u8) this->unk3C4 == 0) {
                switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
                case 0:
                    if ((s32) M2C_FIELD(this->unk70, s32 *, 8) == 4) {
                        temp_r3_8909 = this->unk64;
                        sp84 = 0;
                        sp80 = 0xBE;
                        M2C_FIELD(temp_r3_8909->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8909, &sp80, 0);
                        temp_r3_8919 = this->unk6C;
                        sp7C = 0;
                        sp78 = 0xB5;
                        M2C_FIELD(temp_r3_8919->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8919, &sp78, 0);
                    } else {
                        temp_r3_8931 = this->unk60;
                        sp74 = 0;
                        sp70 = 0xBE;
                        M2C_FIELD(temp_r3_8931->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8931, &sp70, 0);
                        temp_r3_8941 = this->unk68;
                        sp6C = 0;
                        sp68 = 0xB5;
                        M2C_FIELD(temp_r3_8941->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8941, &sp68, 0);
                    }
                    break;
                default:
                    if ((s32) M2C_FIELD(this->unk70, s32 *, 8) == 2) {
                        temp_r3_8957 = this->unk64;
                        sp64 = 0;
                        sp60 = 0xBE;
                        M2C_FIELD(temp_r3_8957->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8957, &sp60, 0);
                        temp_r3_8967 = this->unk6C;
                        sp5C = 0;
                        sp58 = 0xB5;
                        M2C_FIELD(temp_r3_8967->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8967, &sp58, 0);
                    } else {
                        temp_r3_8979 = this->unk60;
                        sp54 = 0;
                        sp50 = 0xBE;
                        M2C_FIELD(temp_r3_8979->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8979, &sp50, 0);
                        temp_r3_8989 = this->unk68;
                        sp4C = 0;
                        sp48 = 0xB5;
                        M2C_FIELD(temp_r3_8989->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_8989, &sp48, 0);
                    }
                    break;
                case 3:
                    temp_r3_9001 = this->unk70;
                    temp_r4_9002 = M2C_FIELD(temp_r3_9001, s32 *, 8);
                    if (((temp_r4_9002 == 1) && ((s32) M2C_FIELD(temp_r3_9001, s32 *, 0x10) == 0)) || (temp_r4_9002 == 2)) {
                        temp_r3_9012 = this->unk64;
                        sp44 = 0;
                        sp40 = 0xBE;
                        M2C_FIELD(temp_r3_9012->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9012, &sp40, 0);
                        temp_r3_9022 = this->unk6C;
                        sp3C = 0;
                        sp38 = 0xB5;
                        M2C_FIELD(temp_r3_9022->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9022, &sp38, 0);
                    } else {
                        temp_r3_9034 = this->unk60;
                        sp34 = 0;
                        sp30 = 0xBE;
                        M2C_FIELD(temp_r3_9034->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9034, &sp30, 0);
                        temp_r3_9044 = this->unk68;
                        sp2C = 0;
                        sp28 = 0xB5;
                        M2C_FIELD(temp_r3_9044->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9044, &sp28, 0);
                    }
                    break;
                }
                this->unk3C4 = 1;
            }
            if ((u8) this->unk3C3 != 0) {
                temp_r3_9061 = this->unk60;
                sp24 = 0;
                sp20 = 0xBF;
                M2C_FIELD(temp_r3_9061->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9061, &sp20, 0);
                temp_r3_9071 = this->unk68;
                sp1C = 0;
                sp18 = 0xB4;
                M2C_FIELD(temp_r3_9071->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9071, &sp18, 0);
                temp_r3_9081 = this->unk64;
                sp14 = 0;
                sp10 = 0xBF;
                M2C_FIELD(temp_r3_9081->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9081, &sp10, 0);
                temp_r3_9091 = this->unk6C;
                spC = 0;
                sp8 = 0xB4;
                M2C_FIELD(temp_r3_9091->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9091, &sp8, 0);
                this->unk360.SetState(this, 2, 0U);
            }
        } else if ((PhrasePlayer_IsEventPlaying(this->unk7EC) == 0) && ((s32) this->unk7EC != 0)) {
            var_f0_9118 = this->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
            if (var_f0_9118 > 0.0f) {

            } else {
                var_f0_9118 = 0.0f;
            }
            if (var_f0_9118 < 2.0f) {
                this->unk7EC = 0;
                this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
            }
        }
    } else {
        this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk460;
    }
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char[16])' does not match
void DojoController::StateDojoSuccessEnter() {
    s32 spC;
    s32 sp8;
    void **temp_r3_9159;
    void **temp_r4_9166;

    spC = 0;
    sp8 = 0xE1;
    temp_r3_9159 = this->unk70;
    if (M2C_FIELD(*temp_r3_9159, u8 (**)(void **, M2C_UNK), 0x18)(temp_r3_9159, 0) != 0) {
        temp_r4_9166 = this->unk70;
        M2C_FIELD(temp_r4_9166, s32 *, 8) = (s32) (M2C_FIELD(temp_r4_9166, s32 *, 8) + 1);
        M2C_FIELD(temp_r4_9166, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_9166, s32 *, 0xC) = 0;
    }
    this->unk3B8 = 0.0f;
    this->unk3BE = 0;
    this->unk2C0.SendMessageToActive((MKMessage *) &sp8);
    this->unk310.SendMessageToActive((MKMessage *) &sp8);
    this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.0f;
    this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk460;
    KDSound_Play(GS_TrainingComplete, 0U, -1);
    if (PhrasePlayer_IsAnyEventPlaying() == 0) {
        this->unk7F0 = 1;
        this->unk39C = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
        case 0:
            strcpy(&this->unk7F1, "FireDojoSuccess");
            break;
        case 2:
            strcpy(&this->unk7F1, "IceDojoSuccess");
            break;
        case 3:
            strcpy(&this->unk7F1, "EarthDojoSuccess");
            break;
        case 1:
            strcpy(&this->unk7F1, "ElectricityDojoSuccess");
            break;
        }
    }
    this->unk3C3 = 0;
    this->unk3C4 = 0;
}
#endif

void DojoController::StateDojoFailExit() {

}

void DojoController::StateDojoFailUpdate() {
    DojoController *sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_9318;
    MKSceneManager *temp_r3_9328;
    MKSceneManager *temp_r3_9340;
    MKSceneManager *temp_r3_9350;
    MKSceneManager *temp_r3_9366;
    MKSceneManager *temp_r3_9376;
    MKSceneManager *temp_r3_9388;
    MKSceneManager *temp_r3_9398;
    MKSceneManager *temp_r3_9421;
    MKSceneManager *temp_r3_9431;
    MKSceneManager *temp_r3_9443;
    MKSceneManager *temp_r3_9453;
    MKSceneManager *temp_r3_9470;
    MKSceneManager *temp_r3_9480;
    MKSceneManager *temp_r3_9490;
    MKSceneManager *temp_r3_9500;
    f32 var_f0_9527;
    s32 temp_r4_9411;
    void **temp_r3_9410;

    if (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk66C) {
        sp8C = NULL;
        sp88 = 0x163;
        sp8C = this;
        InGame_SystemMessage((MKMessage *) &sp88);
    }
    if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk398) && (PhrasePlayer_IsEventPlaying(this->unk7EC) == 0) && ((s32) this->unk7EC == 0)) {
        if ((u8) this->unk3C4 == 0) {
            switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
            case 0:
                if ((s32) M2C_FIELD(this->unk70, s32 *, 8) == 4) {
                    temp_r3_9318 = this->unk64;
                    sp84 = 0;
                    sp80 = 0xBE;
                    M2C_FIELD(temp_r3_9318->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9318, &sp80, 0);
                    temp_r3_9328 = this->unk6C;
                    sp7C = 0;
                    sp78 = 0xB5;
                    M2C_FIELD(temp_r3_9328->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9328, &sp78, 0);
                } else {
                    temp_r3_9340 = this->unk60;
                    sp74 = 0;
                    sp70 = 0xBE;
                    M2C_FIELD(temp_r3_9340->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9340, &sp70, 0);
                    temp_r3_9350 = this->unk68;
                    sp6C = 0;
                    sp68 = 0xB5;
                    M2C_FIELD(temp_r3_9350->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9350, &sp68, 0);
                }
                break;
            default:
                if ((s32) M2C_FIELD(this->unk70, s32 *, 8) == 2) {
                    temp_r3_9366 = this->unk64;
                    sp64 = 0;
                    sp60 = 0xBE;
                    M2C_FIELD(temp_r3_9366->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9366, &sp60, 0);
                    temp_r3_9376 = this->unk6C;
                    sp5C = 0;
                    sp58 = 0xB5;
                    M2C_FIELD(temp_r3_9376->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9376, &sp58, 0);
                } else {
                    temp_r3_9388 = this->unk60;
                    sp54 = 0;
                    sp50 = 0xBE;
                    M2C_FIELD(temp_r3_9388->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9388, &sp50, 0);
                    temp_r3_9398 = this->unk68;
                    sp4C = 0;
                    sp48 = 0xB5;
                    M2C_FIELD(temp_r3_9398->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9398, &sp48, 0);
                }
                break;
            case 3:
                temp_r3_9410 = this->unk70;
                temp_r4_9411 = M2C_FIELD(temp_r3_9410, s32 *, 8);
                if (((temp_r4_9411 == 1) && ((s32) M2C_FIELD(temp_r3_9410, s32 *, 0x10) == 0)) || (temp_r4_9411 == 2)) {
                    temp_r3_9421 = this->unk64;
                    sp44 = 0;
                    sp40 = 0xBE;
                    M2C_FIELD(temp_r3_9421->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9421, &sp40, 0);
                    temp_r3_9431 = this->unk6C;
                    sp3C = 0;
                    sp38 = 0xB5;
                    M2C_FIELD(temp_r3_9431->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9431, &sp38, 0);
                } else {
                    temp_r3_9443 = this->unk60;
                    sp34 = 0;
                    sp30 = 0xBE;
                    M2C_FIELD(temp_r3_9443->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9443, &sp30, 0);
                    temp_r3_9453 = this->unk68;
                    sp2C = 0;
                    sp28 = 0xB5;
                    M2C_FIELD(temp_r3_9453->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9453, &sp28, 0);
                }
                break;
            }
            this->unk3C4 = 1;
        }
        if ((u8) this->unk3C3 != 0) {
            temp_r3_9470 = this->unk60;
            sp24 = 0;
            sp20 = 0xBF;
            M2C_FIELD(temp_r3_9470->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9470, &sp20, 0);
            temp_r3_9480 = this->unk68;
            sp1C = 0;
            sp18 = 0xB4;
            M2C_FIELD(temp_r3_9480->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9480, &sp18, 0);
            temp_r3_9490 = this->unk64;
            sp14 = 0;
            sp10 = 0xBF;
            M2C_FIELD(temp_r3_9490->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9490, &sp10, 0);
            temp_r3_9500 = this->unk6C;
            spC = 0;
            sp8 = 0xB4;
            M2C_FIELD(temp_r3_9500->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9500, &sp8, 0);
            this->unk360.SetState(this, 2, 0U);
        }
    } else if ((PhrasePlayer_IsEventPlaying(this->unk7EC) == 0) && ((s32) this->unk7EC != 0)) {
        var_f0_9527 = this->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
        if (var_f0_9527 > 0.0f) {

        } else {
            var_f0_9527 = 0.0f;
        }
        if (var_f0_9527 < 2.0f) {
            this->unk7EC = 0;
            this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        }
    }
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char[13])' does not match
void DojoController::StateDojoFailEnter() {
    DojoController *spC;
    s32 sp8;

    this->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        this->unk2C0.DespawnAll();
    }
    this->unk310.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        this->unk310.DespawnAll();
    }
    this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk464;
    this->unk3B8 += 0.2f;
    KDSound_Play(GS_TrainingFail, 0U, -1);
    if (PhrasePlayer_IsAnyEventPlaying() == 0) {
        this->unk7F0 = 1;
        this->unk39C = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
        case 0:
            strcpy(&this->unk7F1, "FireDojoFail");
            break;
        case 2:
            strcpy(&this->unk7F1, "IceDojoFail");
            break;
        case 3:
            strcpy(&this->unk7F1, "EarthDojoFail");
            break;
        case 1:
            strcpy(&this->unk7F1, "ElectricityDojoFail");
            break;
        }
    }
    this->unk3C3 = 0;
    this->unk3C4 = 0;
    spC = NULL;
    sp8 = 0x163;
    spC = this;
    InGame_SystemMessage((MKMessage *) &sp8);
}
#endif

void DojoController::StateDojoFightExit() {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_9664;
    MKSceneManager *temp_r3_9671;
    MKSceneManager *temp_r3_9681;
    MKSceneManager *temp_r3_9691;

    temp_r3_9664 = this->unk3E4;
    sp24 = 0;
    sp20 = 0xB4;
    M2C_FIELD(temp_r3_9664->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9664, &sp20, 0);
    temp_r3_9671 = this->unk3E8;
    sp1C = 0;
    sp18 = 0xB4;
    M2C_FIELD(temp_r3_9671->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9671, &sp18, 0);
    temp_r3_9681 = this->unk3EC;
    sp14 = 0;
    sp10 = 0xB4;
    M2C_FIELD(temp_r3_9681->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9681, &sp10, 0);
    temp_r3_9691 = this->unk3F0;
    spC = 0;
    sp8 = 0xB4;
    M2C_FIELD(temp_r3_9691->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_9691, &sp8, 0);
    KDSound_Stop((int *) &this->unk818);
    KDSound_Stop((int *) &this->unk81C);
}

#if 0 // DRAFT: illegal type
void DojoController::StateDojoFightUpdate() {
    f32 temp_f1_9785;
    f32 var_f2_9752;
    s32 temp_r30_9838;
    s32 temp_r4_9817;
    s32 temp_r4_9896;
    void **temp_r3_9720;
    void **temp_r3_9806;
    void **temp_r3_9813;
    void **temp_r3_9836;
    void **temp_r3_9842;
    void **temp_r3_9895;
    void **temp_r3_9925;
    void **temp_r3_9944;
    void **temp_r3_9972;
    void **temp_r3_9989;

    temp_r3_9720 = this->unk70;
    if ((M2C_FIELD(*temp_r3_9720, u8 (**)(void **), 0x20)(temp_r3_9720) != 0) || (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) != 0)) {
        this->unk360.SetState(this, 5, 0U);
        return;
    }
    if ((u8) this->unk3BF != 0) {
        var_f2_9752 = this->unk398 - M2C_FIELD(&gb, f32 *, 0x30C);
        if (var_f2_9752 > 0.0f) {

        } else {
            var_f2_9752 = 0.0f;
        }
        if ((var_f2_9752 != 0.0f) && ((1.0f + var_f2_9752) <= this->unk814)) {
            this->unk814 = var_f2_9752;
            this->unk818 = KDSound_Play(GS_DojoTickTock, 0U, -1);
            if (this->unk814 <= 10.0f) {
                this->unk81C = KDSound_Play(GS_DojoWarningBeep, 0U, -1);
                temp_f1_9785 = this->unk814;
                if (temp_f1_9785 <= 10.0f) {
                    KDSound_SetPitch(this->unk81C, (0.05f * (10.0f - temp_f1_9785)) + 1.0f);
                }
            }
        }
    }
    if (((u8) this->unk3BE != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk3A8)) {
        temp_r3_9806 = this->unk70;
        if (M2C_FIELD(M2C_FIELD(temp_r3_9806, void **, 0), u8 (**)(void **), 0x24)(temp_r3_9806) != 0) {
            temp_r3_9813 = this->unk70;
            if (((s32) M2C_FIELD(temp_r3_9813, s32 *, 0x14) == 0) && ((temp_r4_9817 = M2C_FIELD(temp_r3_9813, s32 *, 8), ((temp_r4_9817 == 1) != 0)) || (temp_r4_9817 == 2))) {
                DialogBox_ColorButtons(*(gpTranslation_StringArray + ((((temp_r4_9817 - 1) * 4) + M2C_FIELD(temp_r3_9813, s32 *, 0x10) + 0x1AF) * 4)), &this->unk468, this->unk670, 0x200);
            }
            temp_r3_9836 = this->unk70;
            temp_r30_9838 = M2C_FIELD(temp_r3_9836, s32 *, 0x10);
            M2C_FIELD(M2C_FIELD(temp_r3_9836, void **, 0), M2C_UNK (**)(void **), 0x28)(temp_r3_9836);
            temp_r3_9842 = this->unk70;
            if (temp_r30_9838 != (s32) M2C_FIELD(temp_r3_9842, s32 *, 0x10)) {
                if (M2C_FIELD(M2C_FIELD(temp_r3_9842, void **, 0), u8 (**)(), 0x1C)() != 0) {
                    this->unk360.SetState(this, 6, 0U);
                    return;
                }
                this->unk360.SetState(this, 4, 0U);
                return;
            }
            this->unk3BE = 0;
            goto block_24;
        }
    }
block_24:
    if ((((s32) M2C_FIELD(this->unk70, s32 *, 0xC) == 0) && ((u8) this->unk3BE == 0)) || (((u8) this->unk3BE == 0) && (this->unk2C0.GetNumberActive(), (((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)) && (this->unk310.GetNumberActive(), (((s32) M2C_ERROR(/* Read from unset register $r3 */) == 0) != 0)))) {
        this->unk2C0.RemoveAllSpawnPoints(0U);
        this->unk310.RemoveAllSpawnPoints(0U);
        temp_r3_9895 = this->unk70;
        temp_r4_9896 = M2C_FIELD(temp_r3_9895, s32 *, 0x14);
        switch (temp_r4_9896) {                     /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if ((s32) M2C_FIELD(temp_r3_9895, s32 *, 8) != 4) {
                switch (temp_r4_9896) {             /* switch 2; irregular */
                case 13:                            /* switch 1 */
                case 13:                            /* switch 2 */
                    if ((s32) M2C_FIELD(temp_r3_9895, s32 *, 8) != 2) {
                        if (((temp_r4_9896 == 0x12) && ((s32) M2C_FIELD(temp_r3_9895, s32 *, 8) == 2)) || ((temp_r4_9896 == 0x17) && ((s32) M2C_FIELD(temp_r3_9895, s32 *, 8) == 2))) {
                            goto block_37;
                        }
                    default:                        /* switch 1 */
                    default:                        /* switch 2 */
                        M2C_FIELD(M2C_FIELD(temp_r3_9895, void **, 0), M2C_UNK (**)(), 0xC)();
                        if (((s32) this->unk3C8 == 0) && ((s32) this->unk3CC == 0)) {
                            temp_r3_9944 = this->unk70;
                            M2C_FIELD(M2C_FIELD(temp_r3_9944, void **, 0), M2C_UNK (**)(void **), 0x10)(temp_r3_9944);
                        } else {
loop_47:
                            if ((s32) this->unk3D0 != (s32) this->unk3C8) {
block_42:
                                this->unk2C0.GetNumberActive();
                                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                                    this->unk2C0.DespawnAll();
                                }
                                this->unk310.GetNumberActive();
                                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                                    this->unk310.DespawnAll();
                                }
                                this->unk2C0.RemoveAllSpawnPoints(0U);
                                this->unk310.RemoveAllSpawnPoints(0U);
                                temp_r3_9972 = this->unk70;
                                M2C_FIELD(M2C_FIELD(temp_r3_9972, void **, 0), M2C_UNK (**)(void **), 0x10)(temp_r3_9972);
                                AttemptSpawn();
                                goto loop_47;
                            }
                            if ((s32) this->unk3D4 != (s32) this->unk3CC) {
                                goto block_42;
                            }
                        }
                    } else {
                        goto block_37;
                    }
                    break;
                }
            } else {
block_37:
                M2C_FIELD(M2C_FIELD(temp_r3_9895, void **, 0), M2C_UNK (**)(), 0xC)();
                temp_r3_9925 = this->unk70;
                M2C_FIELD(M2C_FIELD(temp_r3_9925, void **, 0), M2C_UNK (**)(void **), 0x10)(temp_r3_9925);
                AttemptSpawn();
            }
            break;
        }
        temp_r3_9989 = this->unk70;
        M2C_FIELD(M2C_FIELD(temp_r3_9989, void **, 0), M2C_UNK (**)(void **), 0x30)(temp_r3_9989);
        this->unk3BE = 1;
    }
}
#endif

#if 0 // DRAFT: illegal type
void DojoController::StateDojoFightEnter() {
    s8 *sp14;
    s32 spC;
    s32 sp8;
    s32 temp_r0_10022;
    void **temp_r3_10018;
    void **temp_r7_10030;

    this->unk3BE = 0;
    M2C_FIELD(this->unk70, s32 *, 0xC) = 0;
    this->unk3D0 = 0;
    this->unk3D4 = 0;
    temp_r3_10018 = this->unk70;
    if (((s32) M2C_FIELD(temp_r3_10018, s32 *, 0x14) == 0) && ((temp_r0_10022 = M2C_FIELD(temp_r3_10018, s32 *, 8), ((temp_r0_10022 == 1) != 0)) || (temp_r0_10022 == 2))) {
        ClearCombatArcs();
        temp_r7_10030 = this->unk70;
        DialogBox_ColorButtons(*(gpTranslation_StringArray + ((((M2C_FIELD(temp_r7_10030, s32 *, 8) - 1) * 4) + M2C_FIELD(temp_r7_10030, s32 *, 0x10) + 0x1AF) * 4)), &this->unk468, 0, 0x200);
        spC = 0;
        sp14 = &this->unk468;
        spC = 0;
        sp8 = 0x96;
        InGame_SystemMessage((MKMessage *) &sp8);
    }
}
#endif

void DojoController::StateDojoInstructExit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_10120;
    MKSceneManager *temp_r3_10141;
    s32 temp_cr0_eq_10083;
    s32 temp_r0_10070;
    void **temp_r3_10113;
    void **temp_r3_10131;

    temp_r0_10070 = M2C_FIELD(this->unk70, s32 *, 8);
    if (temp_r0_10070 == 4) {
        ((Stat *) &GameData::gameData[0xB8])->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xBC) * 0.5f, 0U);
    } else {
        temp_cr0_eq_10083 = temp_r0_10070 == 2;
        if (temp_cr0_eq_10083 != 0) {
            ((Stat *) &GameData::gameData[0xB8])->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xBC) * 0.25f, 0U);
        } else if (temp_cr0_eq_10083 != 0) {
            ((Stat *) &GameData::gameData[0xB8])->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xBC) / 6.0f, 0U);
        } else {
            ((Stat *) &GameData::gameData[0xB8])->SetValue(0.0f, 0U);
        }
    }
    temp_r3_10113 = this->unk70;
    if (((s32) M2C_FIELD(temp_r3_10113, s32 *, 0x14) == 0) && ((s32) M2C_FIELD(temp_r3_10113, s32 *, 8) == 3)) {
        temp_r3_10120 = this->unk3E4;
        sp14 = 0;
        sp10 = 0xB5;
        M2C_FIELD(temp_r3_10120->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_10120, &sp10, 0);
    }
    temp_r3_10131 = this->unk70;
    if (((s32) M2C_FIELD(temp_r3_10131, s32 *, 0x14) == 0x17) && ((s32) M2C_FIELD(temp_r3_10131, s32 *, 8) == 1) && ((s32) M2C_FIELD(temp_r3_10131, s32 *, 0x10) == 0)) {
        temp_r3_10141 = this->unk3F0;
        spC = 0;
        sp8 = 0xB5;
        M2C_FIELD(temp_r3_10141->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_10141, &sp8, 0);
    }
}

#if 0 // DRAFT: function call 'strcpy(signed char *, const char[20])' does not match
void DojoController::StateDojoInstructUpdate() {
    s8 sp12A;
    s8 sp129;
    s8 sp128;
    s8 sp124;
    f32 sp120;
    f64 sp118;
    f64 sp110;
    s32 sp10C;
    s32 sp108;
    s8 sp102;
    s8 sp101;
    s8 sp100;
    s8 spFC;
    f32 spF8;
    f64 spF0;
    f64 spE8;
    s32 spE4;
    s32 spE0;
    s8 spDA;
    s8 spD9;
    s8 spD8;
    s8 spD4;
    f32 spD0;
    f64 spC8;
    f64 spC0;
    s32 spBC;
    s32 spB8;
    s8 spB2;
    s8 spB1;
    s8 spB0;
    s8 spAC;
    f32 spA8;
    f64 spA0;
    f64 sp98;
    s32 sp94;
    s32 sp90;
    s8 sp8A;
    s8 sp89;
    s8 sp88;
    s8 sp84;
    f32 sp80;
    f64 sp78;
    f64 sp70;
    s32 sp6C;
    s32 sp68;
    s8 sp62;
    s8 sp61;
    s8 sp60;
    s8 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp38;
    DojoController *sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKSceneManager *temp_r3_10347;
    MKSceneManager *temp_r3_10648;
    MKSceneManager *temp_r3_10658;
    s32 temp_r0_10186;
    s32 temp_r0_10200;
    s32 temp_r0_10241;
    s32 temp_r0_10282;
    s32 temp_r0_10304;
    s32 temp_r0_10363;
    s32 temp_r4_10569;
    s32 temp_r5_10360;
    s32 var_r3_10364;
    void **temp_r3_10182;
    void **temp_r3_10568;
    void **temp_r3_10675;
    void **temp_r4_10359;
    void *temp_r3_10431;
    void *temp_r3_10688;

    if ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u8 *, 0xA9) != 0) {
        M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u8 *, 0xA9) = 0U;
    }
    if (((u8) this->unk3C1 == 0) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        temp_r3_10182 = this->unk70;
        if ((s32) M2C_FIELD(temp_r3_10182, s32 *, 0x14) == 0) {
            temp_r0_10186 = M2C_FIELD(temp_r3_10182, s32 *, 8);
            switch (temp_r0_10186) {                /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                temp_r0_10200 = M2C_FIELD(temp_r3_10182, s32 *, 0x10);
                switch (temp_r0_10200) {            /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    strcpy(&this->unk7F1, "FireDojoKnockUpEasy");
                    break;
                case 1:                             /* switch 2 */
                    strcpy(&this->unk7F1, "FireDojoKnockUpMed");
                    break;
                case 2:                             /* switch 2 */
                    strcpy(&this->unk7F1, "FireDojoKnockUpHard");
                    break;
                case 3:                             /* switch 2 */
                    strcpy(&this->unk7F1, "FireDojoKnockUpHardest");
                    break;
                }
                break;
            case 2:                                 /* switch 1 */
                temp_r0_10241 = M2C_FIELD(temp_r3_10182, s32 *, 0x10);
                switch (temp_r0_10241) {            /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    strcpy(&this->unk7F1, "FireDojoKnockBackEasy");
                    break;
                case 1:                             /* switch 3 */
                    strcpy(&this->unk7F1, "FireDojoKnockBackMed");
                    break;
                case 2:                             /* switch 3 */
                    strcpy(&this->unk7F1, "FireDojoKnockBackMultiple");
                    break;
                case 3:                             /* switch 3 */
                    strcpy(&this->unk7F1, "FireDojoKnockBackHard");
                    break;
                }
                break;
            case 0:                                 /* switch 1 */
                temp_r0_10282 = M2C_FIELD(temp_r3_10182, s32 *, 0x10);
                switch (temp_r0_10282) {            /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    strcpy(&this->unk7F1, "FireDojoBreath1Easy");
                    break;
                case 1:                             /* switch 4 */
                    strcpy(&this->unk7F1, "FireDojoBreath1Med");
                    break;
                }
                break;
            case 3:                                 /* switch 1 */
                temp_r0_10304 = M2C_FIELD(temp_r3_10182, s32 *, 0x10);
                switch (temp_r0_10304) {            /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    strcpy(&this->unk7F1, "FireDojoBreath2Easy");
                    break;
                case 1:                             /* switch 5 */
                    strcpy(&this->unk7F1, "FireDojoBreath2Med");
                    break;
                case 2:                             /* switch 5 */
                    strcpy(&this->unk7F1, "FireDojoBreath2Hard");
                    break;
                }
                break;
            case 4:                                 /* switch 1 */
                strcpy(&this->unk7F1, "FireDojoFury");
                break;
            }
            this->unk7EC = PhrasePlayer_PlayEvent(&this->unk7F1);
        }
        temp_r3_10347 = this->unk5C;
        sp2C = 0;
        sp28 = 0xB5;
        M2C_FIELD(temp_r3_10347->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_10347, &sp28, 0);
        sp34 = NULL;
        temp_r4_10359 = this->unk70;
        temp_r5_10360 = M2C_FIELD(temp_r4_10359, s32 *, 0x14);
        if (temp_r5_10360 == 0) {
            temp_r0_10363 = M2C_FIELD(temp_r4_10359, s32 *, 8);
            var_r3_10364 = 0;
            switch (temp_r0_10363) {                /* switch 6; irregular */
            case 0:                                 /* switch 6 */
                var_r3_10364 = temp_r5_10360 + M2C_FIELD(temp_r4_10359, s32 *, 0x10);
                break;
            case 1:                                 /* switch 6 */
                var_r3_10364 = temp_r5_10360 + M2C_FIELD(temp_r4_10359, s32 *, 0x10) + 2;
                break;
            case 2:                                 /* switch 6 */
                var_r3_10364 = temp_r5_10360 + M2C_FIELD(temp_r4_10359, s32 *, 0x10) + 6;
                break;
            case 3:                                 /* switch 6 */
                var_r3_10364 = temp_r5_10360 + M2C_FIELD(temp_r4_10359, s32 *, 0x10) + 0xA;
                break;
            case 4:                                 /* switch 6 */
                var_r3_10364 = temp_r5_10360 + M2C_FIELD(temp_r4_10359, s32 *, 0x10) + 0xC;
                break;
            }
            sp38 = var_r3_10364;
            sp30 = 0x95;
            sp34 = this;
        } else {
            sp30 = 0x95;
            sp38 = temp_r5_10360 + ((M2C_FIELD(temp_r4_10359, s32 *, 8) * 2) + M2C_FIELD(temp_r4_10359, s32 *, 0x10));
            sp34 = this;
        }
        InGame_SystemMessage((MKMessage *) &sp30);
        this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk45C;
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            temp_r3_10431 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(), 0xC)();
            sp14 = 0;
            sp10 = 0xA9;
            M2C_FIELD(M2C_FIELD(temp_r3_10431, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
            switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* switch 7; irregular */
            case 0:                                 /* switch 7 */
                if ((s32) M2C_FIELD(this->unk70, s32 *, 8) == 4) {
                    sp10C = 0;
                    sp108 = 0xE;
                    sp128 = 0;
                    sp129 = 1;
                    sp110 = M2C_FIELD(this, f64 *, 0x378);
                    sp118 = M2C_FIELD(this, f64 *, 0x380);
                    sp120 = -1.35f;
                    sp124 = 0;
                    sp12A = 1;
                    sp129 = 1;
                    sp128 = 1;
                    ((GameGlobals *) &gb)->GetSpyro();
                    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
                } else {
                    spE4 = 0;
                    spE0 = 0xE;
                    sp100 = 0;
                    sp101 = 1;
                    spE8 = this->unk388;
                    spF0 = this->unk390;
                    spF8 = -1.35f;
                    spFC = 0;
                    sp102 = 1;
                    sp101 = 1;
                    sp100 = 1;
                    ((GameGlobals *) &gb)->GetSpyro();
                    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
                }
                break;
            default:                                /* switch 7 */
                if ((s32) M2C_FIELD(this->unk70, s32 *, 8) == 2) {
                    spBC = 0;
                    spB8 = 0xE;
                    spD8 = 0;
                    spD9 = 1;
                    spC0 = M2C_FIELD(this, f64 *, 0x378);
                    spC8 = M2C_FIELD(this, f64 *, 0x380);
                    spD0 = -1.35f;
                    spD4 = 0;
                    spDA = 1;
                    spD9 = 1;
                    spD8 = 1;
                    ((GameGlobals *) &gb)->GetSpyro();
                    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
                } else {
                    sp94 = 0;
                    sp90 = 0xE;
                    spB0 = 0;
                    spB1 = 1;
                    sp98 = this->unk388;
                    spA0 = this->unk390;
                    spA8 = -1.35f;
                    spAC = 0;
                    spB2 = 1;
                    spB1 = 1;
                    spB0 = 1;
                    ((GameGlobals *) &gb)->GetSpyro();
                    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
                }
                break;
            case 3:                                 /* switch 7 */
                temp_r3_10568 = this->unk70;
                temp_r4_10569 = M2C_FIELD(temp_r3_10568, s32 *, 8);
                if (((temp_r4_10569 == 1) && ((s32) M2C_FIELD(temp_r3_10568, s32 *, 0x10) == 0)) || (temp_r4_10569 == 2)) {
                    sp6C = 0;
                    sp68 = 0xE;
                    sp88 = 0;
                    sp89 = 1;
                    sp70 = M2C_FIELD(this, f64 *, 0x378);
                    sp78 = M2C_FIELD(this, f64 *, 0x380);
                    sp80 = -1.35f;
                    sp84 = 0;
                    sp8A = 1;
                    sp89 = 1;
                    sp88 = 1;
                    ((GameGlobals *) &gb)->GetSpyro();
                    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
                } else {
                    sp44 = 0;
                    sp40 = 0xE;
                    sp60 = 0;
                    sp61 = 1;
                    sp48 = this->unk388;
                    sp50 = this->unk390;
                    sp58 = -1.35f;
                    sp5C = 0;
                    sp62 = 1;
                    sp61 = 1;
                    sp60 = 1;
                    ((GameGlobals *) &gb)->GetSpyro();
                    M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
                }
                break;
            }
        }
        this->unk3C1 = 1;
    }
    if (((u8) this->unk3C1 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk398) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        temp_r3_10648 = this->unk5C;
        sp24 = 0;
        sp20 = 0xB4;
        M2C_FIELD(temp_r3_10648->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_10648, &sp20, 0);
        temp_r3_10658 = this->unk408;
        sp1C = 0;
        sp18 = 0xBC;
        M2C_FIELD(temp_r3_10658->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_10658, &sp18, 0);
        this->unk360.SetState(this, 3, 0U);
        this->unk3C1 = 0;
        temp_r3_10675 = this->unk70;
        M2C_FIELD(M2C_FIELD(temp_r3_10675, void **, 0), M2C_UNK (**)(void **), 0x14)(temp_r3_10675);
        if ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) {
            temp_r3_10688 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(), 0xC)();
            spC = 0;
            sp8 = 0xAA;
            M2C_FIELD(M2C_FIELD(temp_r3_10688, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'DojoController' to
void DojoController::StateDojoInstructEnter() {
    f64 sp10;
    f64 sp8;
    s32 temp_r30_10730;
    s32 var_r29_10719;
    s32 var_r31_10716;
    void **temp_r3_10746;
    void *temp_r3_10732;
    void *temp_r3_10737;

    var_r31_10716 = 0;
    var_r29_10719 = 0;
    this->unk3BE = 0;
    M2C_FIELD(&gb, s8 *, 0xA) = 1;
    sp8 = M2C_FIELD(this, f64 *, 0x378);
    sp10 = M2C_FIELD(this, f64 *, 0x380);
    (*(f32 *) ((u8 *) &sp8 + 0x4)) -= 2000.0f;
    do {
        temp_r30_10730 = var_r31_10716 + 0x3F4;
        temp_r3_10732 = *(this + temp_r30_10730);
        M2C_FIELD(M2C_FIELD(temp_r3_10732, void **, 0x44), M2C_UNK (**)(void *, f64 *), 0x38)(temp_r3_10732, &sp8);
        temp_r3_10737 = *(this + temp_r30_10730);
        M2C_FIELD(M2C_FIELD(temp_r3_10737, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_10737);
        var_r29_10719 += 1;
        var_r31_10716 += 4;
    } while (var_r29_10719 < 4);
    temp_r3_10746 = this->unk70;
    M2C_FIELD(*temp_r3_10746, M2C_UNK (**)(void **), 0x2C)(temp_r3_10746);
}
#endif

void DojoController::StateDojoStatueDownExit() {

}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void DojoController::StateDojoStatueDownUpdate() {
    s32 spC;
    s32 sp8;
    DragonStatue *temp_r3_10781;

    if ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C) != 0) {
        if (this->unk404->IsUp() != 0) {
            temp_r3_10781 = this->unk404;
            spC = 0;
            sp8 = 0xB5;
            temp_r3_10781->Message(&sp8, 0);
        }
        if (this->unk404->IsDown() != 0) {
            this->unk360.SetState(this, 2, 0U);
        }
    } else {
        this->unk360.SetState(this, 2, 0U);
    }
}
#endif

void DojoController::StateDojoStatueDownEnter() {
    switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
    case 0:
        ((GameStats *) &GameData::gameData[0x70])->SetCurrentBreath((BreathElement) 0);
        break;
    case 1:
        ((GameStats *) &GameData::gameData[0x70])->SetCurrentBreath((BreathElement) 1);
        break;
    case 2:
        ((GameStats *) &GameData::gameData[0x70])->SetCurrentBreath((BreathElement) 2);
        break;
    case 3:
        ((GameStats *) &GameData::gameData[0x70])->SetCurrentBreath((BreathElement) 3);
        break;
    }
    ((GameGlobals *) &gb)->InfiniteMagicOn();
    M2C_FIELD(&gb, s8 *, 4) = 0;
}

void DojoController::StateDojoWaitingForActivateExit() {

}

void DojoController::StateDojoWaitingForActivateUpdate() {

}

void DojoController::StateDojoWaitingForActivateEnter() {

}

#if 0 // DRAFT: illegal type
void DojoLesson::UpdateCombatArcs() {
    DojoController *temp_r30_10991;
    DojoController *temp_r3_11039;
    DojoController *temp_r3_11063;
    DojoController *temp_r3_11119;
    DojoController *temp_r4_10968;
    DojoController *temp_r5_10935;
    DojoController *temp_r6_11008;
    DojoController *temp_r6_11086;
    s32 temp_r0_10895;
    s32 temp_r3_11001;
    s32 temp_r3_11079;
    s32 var_r3_10924;
    s8 *temp_r3_11017;
    s8 *temp_r3_11095;
    u8 var_r4_10913;
    void *temp_r3_10911;

    if (((s32) this->unk14 == 0) && ((temp_r0_10895 = this->unk8, ((temp_r0_10895 == 1) != 0)) || (temp_r0_10895 == 2)) && ((s32) this->unk4->unk668 == 1)) {
        temp_r3_10911 = M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0x40)(M2C_FIELD(&gb, void ***, 0));
        var_r4_10913 = 0;
        if (((u8) M2C_FIELD(temp_r3_10911, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r3_10911, u8 *, 4) != 0)) {
            var_r4_10913 = 1;
        }
        if (var_r4_10913 != 0) {
            var_r3_10924 = 0;
        } else {
            var_r3_10924 = MKInput_Pressed(0xE, (MKInputDevices) M2C_FIELD(temp_r3_10911, s32 *, 0));
        }
        if ((u8) var_r3_10924 != 0) {
            temp_r5_10935 = this->unk4;
            DialogBox_ColorButtons(*(gpTranslation_StringArray + ((((this->unk8 - 1) * 4) + this->unk10 + 0x1AF) * 4)), &temp_r5_10935->unk468, temp_r5_10935->unk670 + 1, 0x200);
            this->unk4->unk668 = 2;
            this->unk4->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 1.5f;
            this->unk4->PlayButtonTone();
        }
    }
    ((GameGlobals *) &gb)->GetSpyro();
    if (((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetCombatArcHitFlags() != 0U) {
        temp_r4_10968 = this->unk4;
        if ((u32) temp_r4_10968->unk410 == 0) {
            temp_r4_10968->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        }
    }
    ((GameGlobals *) &gb)->GetSpyro();
    if ((u32) this->unk4->unk40C != ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetCombatArcHitFlags()) {
        ((GameGlobals *) &gb)->GetSpyro();
        temp_r30_10991 = this->unk4;
        temp_r30_10991->AddCombatArc(temp_r30_10991->unk40C ^ ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->GetCombatArcHitFlags());
        if (((s32) this->unk14 == 0) && ((temp_r3_11001 = this->unk8, ((temp_r3_11001 == 1) != 0)) || (temp_r3_11001 == 2))) {
            temp_r6_11008 = this->unk4;
            temp_r3_11017 = *(gpTranslation_StringArray + ((((temp_r3_11001 - 1) * 4) + this->unk10 + 0x1AF) * 4));
            if ((s32) temp_r6_11008->unk668 == 2) {
                DialogBox_ColorButtons(temp_r3_11017, &temp_r6_11008->unk468, temp_r6_11008->unk670 + 1, 0x200);
            } else {
                DialogBox_ColorButtons(temp_r3_11017, &temp_r6_11008->unk468, temp_r6_11008->unk670, 0x200);
            }
        }
        this->unk4->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
    }
    temp_r3_11039 = this->unk4;
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= temp_r3_11039->unk3A4) {
        temp_r3_11039->ClearCombatArcs();
        this->unk4->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
    }
    if ((M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x50)(M2C_FIELD(&gb, void ***, 0)) != 0) && (temp_r3_11063 = this->unk4, (((u8) temp_r3_11063->unk679 == 0) != 0))) {
        temp_r3_11063->unk679 = 1;
        this->unk4->ClearCombatArcs();
        this->unk4->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        if (((s32) this->unk14 == 0) && ((temp_r3_11079 = this->unk8, ((temp_r3_11079 == 1) != 0)) || (temp_r3_11079 == 2))) {
            temp_r6_11086 = this->unk4;
            temp_r3_11095 = *(gpTranslation_StringArray + ((((temp_r3_11079 - 1) * 4) + this->unk10 + 0x1AF) * 4));
            if ((s32) temp_r6_11086->unk668 == 2) {
                DialogBox_ColorButtons(temp_r3_11095, &temp_r6_11086->unk468, temp_r6_11086->unk670 + 1, 0x200);
                return;
            }
            DialogBox_ColorButtons(temp_r3_11095, &temp_r6_11086->unk468, temp_r6_11086->unk670, 0x200);
        }
    } else if (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x50)(M2C_FIELD(&gb, void ***, 0)) == 0) {
        temp_r3_11119 = this->unk4;
        if ((u8) temp_r3_11119->unk679 != 0) {
            temp_r3_11119->unk679 = 0;
        }
    }
}
#endif

void DojoController::Draw() {

}

void DojoController::PlayButtonTone() {
    s32 temp_r3_11150;

    this->unk67C = this->unk67C + 1;
    temp_r3_11150 = this->unk67C;
    if (temp_r3_11150 == (s32) this->unk674) {
        this->unk67C = temp_r3_11150 + 1;
    }
    KDSound_SetPitch(KDSound_Play(GS_ButtonPush4, 0U, -1), (0.1f * (f32) this->unk67C) + 0.8f);
}

#if 0 // DRAFT: function call 'PhrasePlayer_PlayEvent(signed char *)' does not match
void *DojoController::Update() {
    if (M2C_FIELD(&gb, f32 *, 0x30C) > 0.0f) {
        this->unk360.Update(this, 0);
    }
    if (((u8) this->unk7F0 != 0) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk39C)) {
        this->unk7F0 = 0;
        this->unk7EC = PhrasePlayer_PlayEvent(&this->unk7F1);
    }
    MKProp::Update();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void DojoController::SetupSmashPropsVanguard(int arg0, MKVector3 arg1, MKVector3 arg2, float arg3, bool arg4, bool arg5, float arg6) {
    Matrix sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;                                       /* compiler-managed */
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    MKVector3 sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f1_11435;
    f32 temp_f3_11250;
    f32 temp_f6_11246;
    f32 temp_f7_11244;
    f64 temp_f2_11432;
    s32 temp_r21_11479;
    s32 temp_r3_11385;
    s32 var_r23_11275;
    s32 var_r30_11274;
    void *temp_r3_11490;
    void *temp_r3_11495;

    temp_f7_11244 = M2C_FIELD(arg2, f32 *, 0);
    temp_f6_11246 = M2C_FIELD(arg2, f32 *, 8);
    temp_f3_11250 = M2C_FIELD(arg2, f32 *, 4);
    sp28 = (MKVector3::up.unk0 * temp_f3_11250) - (MKVector3::up.unk4 * temp_f7_11244);
    sp24 = (MKVector3::up.unk8 * temp_f7_11244) - (MKVector3::up.unk0 * temp_f6_11246);
    sp20 = (MKVector3::up.unk4 * temp_f6_11246) - (MKVector3::up.unk8 * temp_f3_11250);
    spD0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    var_r30_11274 = 0;
    var_r23_11275 = 0;
    spD8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    spC0 = (f64) sp20;
    spC8 = (f64) sp28;
    spE0 = (f64) sp20;
    spE8 = (f64) sp28;
loop_17:
    if ((var_r30_11274 < arg0) && (var_r30_11274 < 4)) {
        if ((arg4 != 0) && (var_r30_11274 == 0)) {
            spF0 = M2C_FIELD(arg1, f64 *, 0);
            spF8 = M2C_FIELD(arg1, f64 *, 8);
        } else if ((arg4 != 0) && (arg5 != 0)) {
            if (var_r30_11274 & 1) {
                KDMath_Slerp(spB0, *((MKVector3 *) arg2), arg6 * (f32) (var_r30_11274 / 2));
                spD0 = M2C_BITWISE(f64, spB0);
                spD8 = (f64) spB0.unk8;
            } else {
                KDMath_Slerp(spA0, *((MKVector3 *) arg2), -(arg6 * (f32) (var_r30_11274 / 2)));
                spD0 = M2C_BITWISE(f64, spA0);
                spD8 = (f64) spA0.unk8;
            }
        } else if (arg5 != 0) {
            if (var_r30_11274 & 1) {
                KDMath_Slerp(sp90, *((MKVector3 *) arg2), arg6 * (f32) (var_r30_11274 / 2));
                spD0 = M2C_BITWISE(f64, sp90);
                spD8 = (f64) sp90.unk8;
            } else {
                KDMath_Slerp(sp80, *((MKVector3 *) arg2), -(arg6 * (f32) (var_r30_11274 / 2)));
                spD0 = M2C_BITWISE(f64, sp80);
                spD8 = (f64) sp80.unk8;
            }
        } else {
            temp_r3_11385 = var_r30_11274 + 1;
            if (temp_r3_11385 & 1) {
                KDMath_Slerp(sp70, *((MKVector3 *) arg2), (arg6 * 0.5f) + (arg6 * (f32) (temp_r3_11385 / 2)));
                spD0 = M2C_BITWISE(f64, sp70);
                spD8 = (f64) sp70.unk8;
            } else {
                KDMath_Slerp(sp60, *((MKVector3 *) arg2), (arg6 * 0.5f) - (arg6 * (f32) (temp_r3_11385 / 2)));
                spD0 = M2C_BITWISE(f64, sp60);
                spD8 = (f64) sp60.unk8;
            }
        }
        temp_f2_11432 = spD0 * (f64) arg3;
        spD0 = temp_f2_11432;
        temp_f1_11435 = (f32) spD8 * arg3;
        spD8 = temp_f1_11435;
        sp10 = *(f64 *) arg1 + temp_f2_11432;
        spF0 = sp10;
        sp18 = (f32) M2C_FIELD(arg1, f64 *, 8) + temp_f1_11435;
        sp50 = sp10;
        sp58 = (f64) sp18;
        spF8 = (f64) sp18;
        (*(f32 *) ((u8 *) &spF0 + 0x4)) = this->unk378.unk4;
        M2C_STRUCT_COPY((s32) &unkspFC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp30 = -M2C_FIELD(arg2, f32 *, 0);
        sp34 = -M2C_FIELD(arg2, f32 *, 4);
        sp38 = -M2C_FIELD(arg2, f32 *, 8);
        sp40 = (f64) sp30;
        sp48 = (f64) sp38;
        KDMath_BuildMatrixFromFwd(&sp100, *((MKVector3 *) &sp40), NULL);
        temp_r21_11479 = var_r23_11275 + 0x3F4;
        sp100.unk30 = (f32) spF0;
        sp100.unk34 = (*(f32 *) ((u8 *) &spF0 + 0x4));
        sp100.unk38 = (f32) spF8;
        sp100.unk3C = 1.0f;
        MKModel_SetWorldMatrix(M2C_FIELD(*(this + temp_r21_11479), MKModel **, 4), sp100);
        temp_r3_11490 = *(this + temp_r21_11479);
        M2C_FIELD(M2C_FIELD(temp_r3_11490, void **, 0x44), M2C_UNK (**)(void *), 0x20)(temp_r3_11490);
        temp_r3_11495 = *(this + temp_r21_11479);
        M2C_FIELD(M2C_FIELD(temp_r3_11495, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_11495);
        var_r30_11274 += 1;
        var_r23_11275 += 4;
        goto loop_17;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'CharacterGraphNode *' to
void DojoController::SetupSpawnPointsRandomGraph(DojoTiers arg0, CharacterGraphNode *arg1, int arg2, int arg3, CharacterGraphNode **arg4, bool arg5, float arg6, float arg7, unsigned int arg8) {
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
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    CharacterGraphNode *temp_r4_11704;
    CharacterGraphNode *temp_r4_11800;
    Matrix *temp_r15_11925;
    Matrix *temp_r15_12029;
    f32 var_f4_11633;
    f32 var_f4_11730;
    f32 var_f4_11826;
    f64 temp_f1_11636;
    f64 temp_f1_11642;
    f64 temp_f1_11646;
    f64 temp_f1_11733;
    f64 temp_f1_11739;
    f64 temp_f1_11743;
    f64 temp_f1_11829;
    f64 temp_f1_11835;
    f64 temp_f1_11839;
    s32 temp_r3_11665;
    s32 temp_r3_11762;
    s32 temp_r3_11858;
    s32 var_ctr_11990;
    s32 var_r0_11675;
    s32 var_r0_11772;
    s32 var_r0_11868;
    s32 var_r15_11587;
    s32 var_r16_11585;
    s32 var_r21_11959;
    s32 var_r22_11565;
    s32 var_r22_11963;
    s32 var_r23_11564;
    s32 var_r23_11966;
    s32 var_r30_11563;
    s32 var_r3_11986;
    u8 var_r31_11551;
    void **temp_r4_11579;
    void **temp_r4_11980;
    void *temp_r16_11902;
    void *temp_r16_12006;
    void *temp_r3_11608;

    spD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    spE0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r31_11551 = 0;
    if ((s32) arg0 == 0) {
        if ((s32) this->unk3C8 != 0) {
            var_r30_11563 = 0;
            var_r23_11564 = 0;
            var_r22_11565 = 0;
loop_76:
            if (var_r30_11563 < (s32) this->unk3C8) {
loop_69:
                if (var_r31_11551 == 0) {
                    var_r31_11551 = 1;
                    *(arg4 + var_r22_11565) = arg1->GetRandomLink(MKRand_Int((int *) &gViewSeed, arg2, arg3));
                    temp_r4_11579 = *(arg4 + var_r22_11565);
                    M2C_FIELD(*temp_r4_11579, M2C_UNK (**)(f64 *, void **), 0x30)(&spB8, temp_r4_11579);
                    var_r16_11585 = 0;
                    var_r15_11587 = 0;
                    spD8 = spB8;
                    spE0 = spC0;
loop_68:
                    if (var_r16_11585 < var_r30_11563) {
                        if ((u32) *(arg4 + var_r15_11587) == (u32) *(arg4 + var_r22_11565)) {
                            var_r31_11551 = 0;
                        } else if (arg5 != 0) {
                            temp_r3_11608 = M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0xC)(gb), void **, 8);
                            sp98 = M2C_FIELD(temp_r3_11608, f64 *, 0x30);
                            spA0 = M2C_FIELD(temp_r3_11608, f64 *, 0x38);
                            sp38 = spD8 - sp98;
                            spA8 = sp38;
                            sp40 = (f32) spE0 - (f32) spA0;
                            spB0 = (f64) sp40;
                            var_f4_11633 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * (*(f32 *) ((u8 *) &spA8 + 0x4))));
                            if (var_f4_11633 > 0.0f) {
                                temp_f1_11636 = __frsqrte(var_f4_11633);
                                temp_f1_11642 = 0.5 * temp_f1_11636 * -(((f64) var_f4_11633 * (temp_f1_11636 * temp_f1_11636)) - 3.0);
                                temp_f1_11646 = 0.5 * temp_f1_11642 * -(((f64) var_f4_11633 * (temp_f1_11642 * temp_f1_11642)) - 3.0);
                                var_f4_11633 = (f32) ((f64) var_f4_11633 * (0.5 * temp_f1_11646 * -(((f64) var_f4_11633 * (temp_f1_11646 * temp_f1_11646)) - 3.0)));
                            } else if (var_f4_11633 < M2C_BITWISE(f32, 0.0)) {
                                var_f4_11633 = __float_nan;
                            } else {
                                sp10 = var_f4_11633;
                                temp_r3_11665 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                switch (temp_r3_11665) { /* switch 1; irregular */
                                case 0x7F800000:    /* switch 1 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_11675 = 1;
                                    } else {
                                        var_r0_11675 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 1 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_11675 = 5;
                                    } else {
                                        var_r0_11675 = 3;
                                    }
                                    break;
                                default:            /* switch 1 */
                                    var_r0_11675 = 4;
                                    break;
                                }
                                if (var_r0_11675 == 1) {
                                    var_f4_11633 = __float_nan;
                                }
                            }
                            if (var_f4_11633 < 300.0f) {
                                var_r31_11551 = 0;
                            } else {
                                goto block_27;
                            }
                        } else {
block_27:
                            if (arg6 != 0.0f) {
                                temp_r4_11704 = *arg4;
                                M2C_FIELD(temp_r4_11704->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp78, temp_r4_11704);
                                sp28 = spD8 - sp78;
                                sp88 = sp28;
                                sp30 = (f32) spE0 - sp80;
                                sp90 = (f64) sp30;
                                var_f4_11730 = ((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))));
                                if (var_f4_11730 > 0.0f) {
                                    temp_f1_11733 = __frsqrte(var_f4_11730);
                                    temp_f1_11739 = 0.5 * temp_f1_11733 * -(((f64) var_f4_11730 * (temp_f1_11733 * temp_f1_11733)) - 3.0);
                                    temp_f1_11743 = 0.5 * temp_f1_11739 * -(((f64) var_f4_11730 * (temp_f1_11739 * temp_f1_11739)) - 3.0);
                                    var_f4_11730 = (f32) ((f64) var_f4_11730 * (0.5 * temp_f1_11743 * -(((f64) var_f4_11730 * (temp_f1_11743 * temp_f1_11743)) - 3.0)));
                                } else if (var_f4_11730 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_11730 = __float_nan;
                                } else {
                                    spC = var_f4_11730;
                                    temp_r3_11762 = M2C_BITWISE(s32, spC) & 0x7F800000;
                                    switch (temp_r3_11762) { /* switch 2; irregular */
                                    case 0x7F800000: /* switch 2 */
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_11772 = 1;
                                        } else {
                                            var_r0_11772 = 2;
                                        }
                                        break;
                                    case 0x0:       /* switch 2 */
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_11772 = 5;
                                        } else {
                                            var_r0_11772 = 3;
                                        }
                                        break;
                                    default:        /* switch 2 */
                                        var_r0_11772 = 4;
                                        break;
                                    }
                                    if (var_r0_11772 == 1) {
                                        var_f4_11730 = __float_nan;
                                    }
                                }
                                if (var_f4_11730 > arg6) {
                                    var_r31_11551 = 0;
                                } else {
                                    goto block_47;
                                }
                            } else {
block_47:
                                if (arg7 != 0.0f) {
                                    temp_r4_11800 = *arg4;
                                    M2C_FIELD(temp_r4_11800->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp58, temp_r4_11800);
                                    sp18 = spD8 - sp58;
                                    sp68 = sp18;
                                    sp20 = (f32) spE0 - sp60;
                                    sp70 = (f64) sp20;
                                    var_f4_11826 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))));
                                    if (var_f4_11826 > 0.0f) {
                                        temp_f1_11829 = __frsqrte(var_f4_11826);
                                        temp_f1_11835 = 0.5 * temp_f1_11829 * -(((f64) var_f4_11826 * (temp_f1_11829 * temp_f1_11829)) - 3.0);
                                        temp_f1_11839 = 0.5 * temp_f1_11835 * -(((f64) var_f4_11826 * (temp_f1_11835 * temp_f1_11835)) - 3.0);
                                        var_f4_11826 = (f32) ((f64) var_f4_11826 * (0.5 * temp_f1_11839 * -(((f64) var_f4_11826 * (temp_f1_11839 * temp_f1_11839)) - 3.0)));
                                    } else if (var_f4_11826 < M2C_BITWISE(f32, 0.0)) {
                                        var_f4_11826 = __float_nan;
                                    } else {
                                        sp8 = var_f4_11826;
                                        temp_r3_11858 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                        switch (temp_r3_11858) { /* switch 3; irregular */
                                        case 0x7F800000: /* switch 3 */
                                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                                var_r0_11868 = 1;
                                            } else {
                                                var_r0_11868 = 2;
                                            }
                                            break;
                                        case 0x0:   /* switch 3 */
                                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                                var_r0_11868 = 5;
                                            } else {
                                                var_r0_11868 = 3;
                                            }
                                            break;
                                        default:    /* switch 3 */
                                            var_r0_11868 = 4;
                                            break;
                                        }
                                        if (var_r0_11868 == 1) {
                                            var_f4_11826 = __float_nan;
                                        }
                                    }
                                    if (var_f4_11826 < arg7) {
                                        var_r31_11551 = 0;
                                    } else {
                                        goto block_67;
                                    }
                                } else {
block_67:
                                    var_r16_11585 += 1;
                                    var_r15_11587 += 4;
                                    goto loop_68;
                                }
                            }
                        }
                    }
                    goto loop_69;
                }
                temp_r16_11902 = this + var_r23_11564;
                var_r31_11551 = 0;
                M2C_FIELD(M2C_FIELD(temp_r16_11902, void **, 0x84), u32 *, 4) = arg8;
                if (((u32) (arg8 & 0x800) != 0) || ((u32) (arg8 & 0x1000) != 0) || ((u32) (arg8 & 0x2000) != 0)) {
                    M2C_FIELD(M2C_FIELD(temp_r16_11902, void **, 0x84), s32 *, 0x24) = (s32) *(arg4 + var_r22_11565);
                } else {
                    M2C_FIELD(M2C_FIELD(temp_r16_11902, void **, 0x84), s32 *, 0x24) = 0;
                }
                this->unk2C0.AddSpawnPoint(((u8 *) temp_r16_11902) + 0x80);
                temp_r15_11925 = ((u8 *) temp_r16_11902) + 0x90;
                temp_r15_11925->SetIdentity();
                M2C_FIELD(temp_r16_11902, f32 *, 0xC0) = (f32) spD8;
                M2C_FIELD(temp_r16_11902, f32 *, 0xC4) = (*(f32 *) ((u8 *) &spD8 + 0x4));
                M2C_FIELD(temp_r16_11902, f32 *, 0xC8) = (f32) spE0;
                M2C_FIELD(temp_r16_11902, f32 *, 0xCC) = 1.0f;
                spC8 = this->unk388;
                spD0 = this->unk390;
                (*(f32 *) ((u8 *) &spC8 + 0x4)) = (*(f32 *) ((u8 *) &spD8 + 0x4));
                temp_r15_11925->SetLookAt(*((MKVector3 *) &spD8), *((MKVector3 *) &spC8));
                var_r30_11563 += 1;
                var_r23_11564 += 0x60;
                var_r22_11565 += 4;
                goto loop_76;
            }
            this->unk2C0.AddSpawnPointEnd();
        }
    } else if ((s32) this->unk3CC != 0) {
        var_r21_11959 = this->unk3C8;
        var_r22_11963 = var_r21_11959 * 0x60;
        var_r23_11966 = var_r21_11959 * 4;
loop_92:
        if (var_r21_11959 < (s32) (this->unk3C8 + this->unk3CC)) {
loop_85:
            if (var_r31_11551 == 0) {
                var_r31_11551 = 1;
                *(arg4 + var_r23_11966) = arg1->GetRandomLink(MKRand_Int((int *) &gViewSeed, 2, 0x10));
                temp_r4_11980 = *(arg4 + var_r23_11966);
                M2C_FIELD(*temp_r4_11980, M2C_UNK (**)(f64 *, void **), 0x30)(&sp48, temp_r4_11980);
                var_r3_11986 = 0;
                spD8 = sp48;
                spE0 = sp50;
                var_ctr_11990 = var_r21_11959;
                if (var_r21_11959 > 0) {
loop_82:
                    if ((u32) *(arg4 + var_r3_11986) == (u32) *(arg4 + var_r23_11966)) {
                        var_r31_11551 = 0;
                    } else {
                        var_r3_11986 += 4;
                        var_ctr_11990 -= 1;
                        if (var_ctr_11990 != 0) {
                            goto loop_82;
                        }
                    }
                }
                goto loop_85;
            }
            temp_r16_12006 = this + var_r22_11963;
            var_r31_11551 = 0;
            M2C_FIELD(M2C_FIELD(temp_r16_12006, void **, 0x84), u32 *, 4) = arg8;
            if (((u32) (arg8 & 0x800) != 0) || ((u32) (arg8 & 0x1000) != 0) || ((u32) (arg8 & 0x2000) != 0)) {
                M2C_FIELD(M2C_FIELD(temp_r16_12006, void **, 0x84), s32 *, 0x24) = (s32) *(arg4 + var_r23_11966);
            } else {
                M2C_FIELD(M2C_FIELD(temp_r16_12006, void **, 0x84), s32 *, 0x24) = 0;
            }
            this->unk310.AddSpawnPoint(((u8 *) temp_r16_12006) + 0x80);
            temp_r15_12029 = ((u8 *) temp_r16_12006) + 0x90;
            temp_r15_12029->SetIdentity();
            M2C_FIELD(temp_r16_12006, f32 *, 0xC0) = (f32) spD8;
            M2C_FIELD(temp_r16_12006, f32 *, 0xC4) = (*(f32 *) ((u8 *) &spD8 + 0x4));
            M2C_FIELD(temp_r16_12006, f32 *, 0xC8) = (f32) spE0;
            M2C_FIELD(temp_r16_12006, f32 *, 0xCC) = 1.0f;
            spC8 = this->unk388;
            spD0 = this->unk390;
            (*(f32 *) ((u8 *) &spC8 + 0x4)) = (*(f32 *) ((u8 *) &spD8 + 0x4));
            temp_r15_12029->SetLookAt(*((MKVector3 *) &spD8), *((MKVector3 *) &spC8));
            var_r21_11959 += 1;
            var_r22_11963 += 0x60;
            var_r23_11966 += 4;
            goto loop_92;
        }
        this->unk310.AddSpawnPointEnd();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void DojoController::SetupSpawnPointsVanguard(DojoTiers arg0, MKVector3 arg1, MKVector3 arg2, float arg3, bool arg4, bool arg5, float arg6, unsigned int arg7) {
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    MKVector3 spF8;
    MKVector3 spE8;
    MKVector3 spD8;
    MKVector3 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Matrix *temp_r20_12311;
    Matrix *temp_r21_12521;
    f32 temp_f0_12305;
    f32 temp_f2_12102;
    f32 temp_f2_12289;
    f32 temp_f2_12501;
    f32 temp_f5_12099;
    f32 temp_f7_12095;
    f64 temp_f0_12292;
    f64 temp_f1_12286;
    f64 temp_f1_12498;
    s32 temp_r3_12239;
    s32 temp_r3_12365;
    s32 temp_r3_12454;
    s32 temp_r3_12544;
    s32 var_r22_12134;
    s32 var_r22_12348;
    s32 var_r29_12133;
    s32 var_r29_12344;
    void *temp_r20_12506;
    void *temp_r21_12294;

    temp_f7_12095 = M2C_FIELD(arg2, f32 *, 0);
    temp_f5_12099 = M2C_FIELD(arg2, f32 *, 8);
    temp_f2_12102 = M2C_FIELD(arg2, f32 *, 4);
    sp128 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp30 = (MKVector3::up.unk0 * temp_f2_12102) - (MKVector3::up.unk4 * temp_f7_12095);
    sp2C = (MKVector3::up.unk8 * temp_f7_12095) - (MKVector3::up.unk0 * temp_f5_12099);
    sp28 = (MKVector3::up.unk4 * temp_f5_12099) - (MKVector3::up.unk8 * temp_f2_12102);
    sp130 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp118 = (f64) sp28;
    sp120 = (f64) sp30;
    sp138 = (f64) sp28;
    sp140 = (f64) sp30;
    if ((s32) arg0 == 0) {
        if ((s32) this->unk3C8 != 0) {
            var_r29_12133 = 0;
            var_r22_12134 = 0;
loop_19:
            if (var_r29_12133 < (s32) this->unk3C8) {
                if ((arg4 != 0) && (var_r29_12133 == 0)) {
                    sp148 = M2C_FIELD(arg1, f64 *, 0);
                    sp150 = M2C_FIELD(arg1, f64 *, 8);
                } else if ((arg4 != 0) && (arg5 != 0)) {
                    if (var_r29_12133 & 1) {
                        KDMath_Slerp(sp108, *((MKVector3 *) arg2), arg6 * (f32) (var_r29_12133 / 2));
                        sp128 = M2C_BITWISE(f64, sp108);
                        sp130 = (f64) sp108.unk8;
                    } else {
                        KDMath_Slerp(spF8, *((MKVector3 *) arg2), -(arg6 * (f32) (var_r29_12133 / 2)));
                        sp128 = M2C_BITWISE(f64, spF8);
                        sp130 = (f64) spF8.unk8;
                    }
                } else if (arg5 != 0) {
                    if (var_r29_12133 & 1) {
                        KDMath_Slerp(spE8, *((MKVector3 *) arg2), arg6 * (f32) (var_r29_12133 / 2));
                        sp128 = M2C_BITWISE(f64, spE8);
                        sp130 = (f64) spE8.unk8;
                    } else {
                        KDMath_Slerp(spD8, *((MKVector3 *) arg2), -(arg6 * (f32) (var_r29_12133 / 2)));
                        sp128 = M2C_BITWISE(f64, spD8);
                        sp130 = (f64) spD8.unk8;
                    }
                } else {
                    temp_r3_12239 = var_r29_12133 + 1;
                    if (temp_r3_12239 & 1) {
                        KDMath_Slerp(spC8, *((MKVector3 *) arg2), (arg6 * 0.5f) + (arg6 * (f32) (temp_r3_12239 / 2)));
                        sp128 = M2C_BITWISE(f64, spC8);
                        sp130 = (f64) spC8.unk8;
                    } else {
                        KDMath_Slerp(spB8, *((MKVector3 *) arg2), (arg6 * 0.5f) - (arg6 * (f32) (temp_r3_12239 / 2)));
                        sp128 = M2C_BITWISE(f64, spB8);
                        sp130 = (f64) spB8.unk8;
                    }
                }
                temp_f1_12286 = sp128 * (f64) arg3;
                sp128 = temp_f1_12286;
                temp_f2_12289 = (f32) sp130 * arg3;
                sp130 = temp_f2_12289;
                temp_f0_12292 = *(f64 *) arg1 + temp_f1_12286;
                sp18 = temp_f0_12292;
                temp_r21_12294 = this + var_r22_12134;
                sp148 = temp_f0_12292;
                sp20 = (f32) M2C_FIELD(arg1, f64 *, 8) + temp_f2_12289;
                spA8 = temp_f0_12292;
                sp150 = (f64) sp20;
                temp_f0_12305 = this->unk378.unk4;
                spB0 = (f64) sp20;
                (*(f32 *) ((u8 *) &sp148 + 0x4)) = temp_f0_12305;
                M2C_FIELD(M2C_FIELD(temp_r21_12294, void **, 0x84), u32 *, 4) = arg7;
                this->unk2C0.AddSpawnPoint(((u8 *) temp_r21_12294) + 0x80);
                temp_r20_12311 = ((u8 *) temp_r21_12294) + 0x90;
                temp_r20_12311->SetIdentity();
                M2C_FIELD(temp_r21_12294, f32 *, 0xC0) = (f32) sp148;
                M2C_FIELD(temp_r21_12294, f32 *, 0xC4) = temp_f0_12305;
                M2C_FIELD(temp_r21_12294, f32 *, 0xC8) = (f32) sp150;
                M2C_FIELD(temp_r21_12294, f32 *, 0xCC) = 1.0f;
                sp158 = this->unk388;
                sp160 = this->unk390;
                (*(f32 *) ((u8 *) &sp158 + 0x4)) = temp_f0_12305;
                temp_r20_12311->SetLookAt(*((MKVector3 *) &sp148), *((MKVector3 *) &sp158));
                var_r29_12133 += 1;
                var_r22_12134 += 0x60;
                goto loop_19;
            }
            this->unk2C0.AddSpawnPointEnd();
        }
    } else if ((s32) this->unk3CC != 0) {
        var_r29_12344 = this->unk3C8;
        var_r22_12348 = var_r29_12344 * 0x60;
loop_39:
        temp_r3_12544 = this->unk3C8;
        if (var_r29_12344 < (s32) (temp_r3_12544 + this->unk3CC)) {
            if ((arg4 != 0) && (var_r29_12344 == temp_r3_12544)) {
                sp148 = M2C_FIELD(arg1, f64 *, 0);
                sp150 = M2C_FIELD(arg1, f64 *, 8);
            } else if ((arg4 != 0) && (arg5 != 0)) {
                temp_r3_12365 = var_r29_12344 - 1;
                if (temp_r3_12365 & 1) {
                    KDMath_Slerp(sp98, *((MKVector3 *) arg2), arg6 * (f32) (temp_r3_12365 / 2));
                    sp128 = M2C_BITWISE(f64, sp98);
                    sp130 = (f64) sp98.unk8;
                } else {
                    KDMath_Slerp(sp88, *((MKVector3 *) arg2), -(arg6 * (f32) (temp_r3_12365 / 2)));
                    sp128 = M2C_BITWISE(f64, sp88);
                    sp130 = (f64) sp88.unk8;
                }
            } else if (arg5 != 0) {
                if (var_r29_12344 & 1) {
                    KDMath_Slerp(sp78, *((MKVector3 *) arg2), arg6 * (f32) (var_r29_12344 / 2));
                    sp128 = M2C_BITWISE(f64, sp78);
                    sp130 = (f64) sp78.unk8;
                } else {
                    KDMath_Slerp(sp68, *((MKVector3 *) arg2), -(arg6 * (f32) (var_r29_12344 / 2)));
                    sp128 = M2C_BITWISE(f64, sp68);
                    sp130 = (f64) sp68.unk8;
                }
            } else {
                temp_r3_12454 = var_r29_12344 + 2;
                if (temp_r3_12454 & 1) {
                    KDMath_Slerp(sp58, *((MKVector3 *) arg2), arg6 * (f32) (temp_r3_12454 / 2));
                    sp128 = M2C_BITWISE(f64, sp58);
                    sp130 = (f64) sp58.unk8;
                } else {
                    KDMath_Slerp(sp48, *((MKVector3 *) arg2), -(arg6 * (f32) (temp_r3_12454 / 2)));
                    sp128 = M2C_BITWISE(f64, sp48);
                    sp130 = (f64) sp48.unk8;
                }
            }
            temp_f1_12498 = sp128 * (f64) arg3;
            sp128 = temp_f1_12498;
            temp_f2_12501 = (f32) sp130 * arg3;
            sp130 = temp_f2_12501;
            sp8 = *(void *) arg1 + temp_f1_12498;
            temp_r20_12506 = this + var_r22_12348;
            sp148 = sp8;
            sp10 = (f32) M2C_FIELD(arg1, f64 *, 8) + temp_f2_12501;
            sp38 = sp8;
            sp150 = (f64) sp10;
            sp40 = (f64) sp10;
            M2C_FIELD(M2C_FIELD(temp_r20_12506, void **, 0x84), u32 *, 4) = arg7;
            this->unk310.AddSpawnPoint(((u8 *) temp_r20_12506) + 0x80);
            temp_r21_12521 = ((u8 *) temp_r20_12506) + 0x90;
            temp_r21_12521->SetIdentity();
            M2C_FIELD(temp_r20_12506, f32 *, 0xC0) = (f32) sp148;
            M2C_FIELD(temp_r20_12506, f32 *, 0xC4) = (*(f32 *) ((u8 *) &sp148 + 0x4));
            M2C_FIELD(temp_r20_12506, f32 *, 0xC8) = (f32) sp150;
            M2C_FIELD(temp_r20_12506, f32 *, 0xCC) = 1.0f;
            sp158 = this->unk388;
            sp160 = this->unk390;
            (*(f32 *) ((u8 *) &sp158 + 0x4)) = (*(f32 *) ((u8 *) &sp148 + 0x4));
            temp_r21_12521->SetLookAt(*((MKVector3 *) &sp148), *((MKVector3 *) &sp158));
            var_r29_12344 += 1;
            var_r22_12348 += 0x60;
            goto loop_39;
        }
        this->unk310.AddSpawnPointEnd();
    }
}
#endif

void DojoController::AddCombatArc(unsigned int arg0) {
    s32 temp_r0_12571;
    s32 temp_r6_12583;
    void *temp_r5_12585;

    temp_r0_12571 = this->unk448;
    if (temp_r0_12571 < 7) {
        M2C_FIELD((this + (temp_r0_12571 * 4)), u32 *, 0x410) = arg0;
        this->unk40C |= arg0;
        this->unk448 += 1;
        temp_r6_12583 = this->unk670;
        temp_r5_12585 = this + (temp_r6_12583 * 4);
        if ((u32) M2C_FIELD(temp_r5_12585, u32 *, 0x410) == (u32) M2C_FIELD(temp_r5_12585, u32 *, 0x42C)) {
            this->unk670 = temp_r6_12583 + 1;
            PlayButtonTone();
            return;
        }
        if ((u8) this->unk678 != 0) {
            ClearCombatArcs();
        }
    } else {
        ClearCombatArcs();
    }
}

#if 0 // DRAFT: illegal operand
void DojoController::ClearCombatArcs() {
    s32 temp_r0_12623;
    s32 temp_r4_12647;
    s32 var_ctr_12621;
    s32 var_r3_12620;
    void **temp_r3_12643;

    this->unk668 = 0;
    var_r3_12620 = 0;
    var_ctr_12621 = 7;
    do {
        temp_r0_12623 = var_r3_12620 + 0x410;
        var_r3_12620 += 4;
        *(this + temp_r0_12623) = 0;
        var_ctr_12621 -= 1;
    } while (var_ctr_12621 != 0);
    this->unk670 = 0;
    this->unk448 = 0;
    this->unk40C = 0;
    this->unk67C = 0;
    ((GameGlobals *) &gb)->GetSpyro();
    ((CombatStateData *) (M2C_ERROR(/* Read from unset register $r3 */) + 0x460))->ClearCombatArcHitFlags();
    this->unk3A4 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.0f;
    temp_r3_12643 = this->unk70;
    if (((s32) M2C_FIELD(temp_r3_12643, s32 *, 0x14) == 0) && ((temp_r4_12647 = M2C_FIELD(temp_r3_12643, s32 *, 8), ((temp_r4_12647 == 1) != 0)) || (temp_r4_12647 == 2))) {
        DialogBox_ColorButtons(*(gpTranslation_StringArray + ((((temp_r4_12647 - 1) * 4) + M2C_FIELD(temp_r3_12643, s32 *, 0x10) + 0x1AF) * 4)), &this->unk468, this->unk670, 0x200);
    }
}
#endif

void DojoController::AttemptSpawn() {
    if (((u8) this->unk2C0.unk4C >> 7U) & 1) {
        this->unk2C0.FunctionOn();
        this->unk2C0.unk38 = M2C_FIELD(&gb, f32 *, 0x30C) - 1.0f;
        this->unk2C0.TrySpawnItems(0x2C, 0U);
        this->unk2C0.FunctionOff();
    }
    if (((u8) this->unk310.unk4C >> 7U) & 1) {
        this->unk310.FunctionOn();
        this->unk310.unk38 = M2C_FIELD(&gb, f32 *, 0x30C) - 1.0f;
        this->unk310.TrySpawnItems(0x2D, 0U);
        this->unk310.FunctionOff();
    }
    this->unk2C0.GetNumberActive();
    this->unk3D0 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk310.GetNumberActive();
    this->unk3D4 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk3A8 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.25f;
}

void DojoController::Message(MKMessage *arg0) {
    s32 temp_r0_12745;

    temp_r0_12745 = arg0->unk0;
    switch (temp_r0_12745) {                        /* irregular */
    case 0xB4:
        break;
    case 0xB5:
        if (this->unk360.GetState() == 0) {
            M2C_FIELD(&gb, s8 *, 0xA) = 1;
            ClearCombatArcs();
            this->unk360.SetState(this, 1, 0U);
        } else if ((this->unk360.GetState() == 4) || (this->unk360.GetState() == 5)) {
            this->unk3C3 = 1;
        }
        break;
    case 0x97:
        if (this->unk360.GetState() == 2) {
            this->unk398 = M2C_FIELD(&gb, f32 *, 0x30C) + 0.0f;
            if (PhrasePlayer_IsEventPlaying(this->unk7EC) != 0) {
                PhrasePlayer_StopEvent(this->unk7EC);
            }
        }
        break;
    }
    MKProp::Message(arg0);
}

#if 0 // DRAFT: illegal explicit conversion from 'void' to
f32 DojoController::Resolve() {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    DragonStatue *temp_ret_12937;
    MKSceneManager *temp_r3_12850;
    MKSceneManager *temp_r3_12857;
    MKSceneManager *temp_r3_12867;
    MKSceneManager *temp_r3_12877;
    MKSceneManager *temp_ret_12829;
    MKSceneManager *temp_ret_12833;
    MKSceneManager *temp_ret_12837;
    MKSceneManager *temp_ret_12841;
    MKSceneManager *temp_ret_12904;
    MKSceneManager *temp_ret_12908;
    MKSceneManager *temp_ret_12912;
    MKSceneManager *temp_ret_12916;
    s32 temp_r29_12921;
    s32 var_r28_12918;
    s32 var_r30_12919;
    u32 var_r4_12916;
    u64 temp_ret_12889;
    u64 temp_ret_12894;
    u64 temp_ret_12899;
    void *temp_r3_12926;

    this->unk3BE = 0;
    temp_ret_12829 = checked_cast<TriggerProp *, MKProp>(this->unk60->PropResolver_Resolve((s32) (u32) this->unk360.SetState(this, 0, 0U)));
    this->unk60 = temp_ret_12829;
    temp_ret_12833 = checked_cast<EventCamera *, MKProp>(this->unk5C->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12829));
    this->unk5C = temp_ret_12833;
    temp_ret_12837 = checked_cast<TriggerProp *, MKProp>(this->unk64->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12833));
    this->unk64 = temp_ret_12837;
    temp_ret_12841 = checked_cast<SparxHint *, MKProp>(this->unk68->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12837));
    this->unk68 = temp_ret_12841;
    this->unk6C = checked_cast<SparxHint *, MKProp>(this->unk6C->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12841));
    temp_r3_12850 = this->unk60;
    sp24 = 0;
    sp20 = 0xBF;
    M2C_FIELD(temp_r3_12850->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_12850, &sp20, 0);
    temp_r3_12857 = this->unk68;
    sp1C = 0;
    sp18 = 0xB4;
    M2C_FIELD(temp_r3_12857->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_12857, &sp18, 0);
    temp_r3_12867 = this->unk64;
    sp14 = 0;
    sp10 = 0xBF;
    M2C_FIELD(temp_r3_12867->unk44, M2C_UNK (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_12867, &sp10, 0);
    temp_r3_12877 = this->unk6C;
    spC = 0;
    sp8 = 0xB4;
    temp_ret_12889 = checked_cast<CharacterGraphNodeProp *, MKProp>(((MKSceneManager *) this->unk3D8)->PropResolver_Resolve((s32) (u32) M2C_FIELD(temp_r3_12877->unk44, u64 (**)(MKSceneManager *, s32 *, M2C_UNK), 0x2C)(temp_r3_12877, &sp8, 0)));
    this->unk3D8 = temp_ret_12889 + 0x50;
    temp_ret_12894 = checked_cast<CharacterGraphNodeProp *, MKProp>(((MKSceneManager *) this->unk3DC)->PropResolver_Resolve((s32) (u32) temp_ret_12889));
    this->unk3DC = temp_ret_12894 + 0x50;
    temp_ret_12899 = checked_cast<CharacterGraphNodeProp *, MKProp>(((MKSceneManager *) this->unk3E0)->PropResolver_Resolve((s32) (u32) temp_ret_12894));
    this->unk3E0 = temp_ret_12899 + 0x50;
    temp_ret_12904 = checked_cast<ElementalWall *, MKProp>(this->unk3E4->PropResolver_Resolve((s32) (u32) temp_ret_12899));
    this->unk3E4 = temp_ret_12904;
    temp_ret_12908 = checked_cast<ElementalWall *, MKProp>(this->unk3E8->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12904));
    this->unk3E8 = temp_ret_12908;
    temp_ret_12912 = checked_cast<ElementalWall *, MKProp>(this->unk3EC->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12908));
    this->unk3EC = temp_ret_12912;
    temp_ret_12916 = checked_cast<ElementalWall *, MKProp>(this->unk3F0->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12912));
    var_r4_12916 = (u32) (u64) temp_ret_12916;
    this->unk3F0 = temp_ret_12916;
    var_r28_12918 = 0;
    var_r30_12919 = 0;
    do {
        temp_r29_12921 = var_r30_12919 + 0x3F4;
        *(this + temp_r29_12921) = checked_cast<Shatterable *, MKProp>(((MKSceneManager *) (*(this + temp_r29_12921)))->PropResolver_Resolve((s32) var_r4_12916));
        temp_r3_12926 = *(this + temp_r29_12921);
        var_r4_12916 = (u32) M2C_FIELD(M2C_FIELD(temp_r3_12926, void **, 0x44), u64 (**)(void *), 0x34)(temp_r3_12926);
        var_r28_12918 += 1;
        var_r30_12919 += 4;
    } while (var_r28_12918 < 4);
    temp_ret_12937 = checked_cast<DragonStatue *, MKProp>(((MKSceneManager *) this->unk404)->PropResolver_Resolve((s32) var_r4_12916));
    this->unk404 = temp_ret_12937;
    this->unk408 = checked_cast<MKProp *, MKProp>(this->unk408->PropResolver_Resolve((s32) (u32) (u64) temp_ret_12937));
    MKProp::Resolve();
}
#endif

s32 DojoController::LoadDone() {
    s32 var_r30_12978;
    s32 var_r31_12979;

    this->unk2C0.LoadDone(0, 6, 0U, 1U);
    this->unk310.LoadDone(0, 6, 0U, 1U);
    this->unk2C0.AddSpawnPointBegin(6);
    this->unk310.AddSpawnPointBegin(6);
    var_r30_12978 = 0;
    var_r31_12979 = 0;
    do {
        ((SpawnPointObject *) (this + (var_r31_12979 + 0x80)))->LoadDone();
        var_r30_12978 += 1;
        var_r31_12979 += 0x60;
    } while (var_r30_12978 < 6);
    MKProp::LoadDone();
}

s32 DojoController::LoadLine(MKIniLine *arg0) {
    if (MKProp::LoadLine(arg0) != 0) {
        return 1U;
    }
    if (this->unk4C.LoadLine(arg0, "OnFireLessonComplete") != 0) {
        return 1U;
    }
    if (this->unk50.LoadLine(arg0, "OnElectricityLessonComplete") != 0) {
        return 1U;
    }
    if (this->unk54.LoadLine(arg0, "OnIceLessonComplete") != 0) {
        return 1U;
    }
    if (this->unk58.LoadLine(arg0, "OnEarthLessonComplete") != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ResetTriggerID", (int *) &this->unk60, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("InstructionalEventCameraID", (int *) &this->unk5C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthResetTriggerID", (int *) &this->unk64, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SparxHintResetPointID", (int *) &this->unk68, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SparxHintEarthResetPointID", (int *) &this->unk6C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadVector3("DojoCentrePoint", &this->unk378, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("DojoRadius", &this->unk3B4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadVector3("PlayerStartPosition", (MKVector3 *) &this->unk388, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("RunAroundGraphID", (int *) &this->unk3D8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ShootingGraphID", (int *) &this->unk3DC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("RoundShootingGraphID", (int *) &this->unk3E0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("DragonStatueID", (int *) &this->unk404, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("DragonStatueDoor", (int *) &this->unk408, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireElementalWall", (int *) &this->unk3E4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectircElementalWall", (int *) &this->unk3E8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceElementalWall", (int *) &this->unk3EC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthElementalWall", (int *) &this->unk3F0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SmashProp1ID", (int *) &this->unk3F4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SmashProp2ID", (int *) &this->unk3F8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SmashProp3ID", (int *) &this->unk3FC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("SmashProp4ID", (int *) &this->unk400, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("InstructToFightDelay", &this->unk45C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("TaskSuccessToInstructDelay", &this->unk460, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("TaskFailToInstructDelay", &this->unk464, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel1NumTier1", (int *) &this->unk680, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel1NumTier2", (int *) &this->unk684, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel1Timer", (int *) &this->unk688, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel2NumTier1", (int *) &this->unk68C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel2NumTier2", (int *) &this->unk690, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel2Timer", (int *) &this->unk694, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel3NumTier1", (int *) &this->unk698, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel3NumTier2", (int *) &this->unk69C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel3Timer", (int *) &this->unk6A0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel4NumTier1", (int *) &this->unk6A4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel4NumTier2", (int *) &this->unk6A8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockUpLevel4Timer", (int *) &this->unk6AC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("FireMeleeKnockUpVanguardDistance", &this->unk6B0, 0) != 0) {
        this->unk6B0 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel1NumTier1", (int *) &this->unk6B4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel1NumTier2", (int *) &this->unk6B8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel1Timer", (int *) &this->unk6BC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel2NumTier1", (int *) &this->unk6C0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel2NumTier2", (int *) &this->unk6C4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel2Timer", (int *) &this->unk6C8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel3NumTier1", (int *) &this->unk6CC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel3NumTier2", (int *) &this->unk6D0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel3Timer", (int *) &this->unk6D4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel4NumTier1", (int *) &this->unk6D8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel4NumTier2", (int *) &this->unk6DC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel4Timer", (int *) &this->unk6E0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("FireMeleeKnockBackVanguardDistance", &this->unk6E4, 0) != 0) {
        this->unk6E4 *= 100.0f;
        return 1U;
    }
    if (arg0->LoadInt("FireMeleeKnockBackLevel3Iterations", (int *) &this->unk6E8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath1Level1NumTier1", (int *) &this->unk6EC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath1Level1NumTier2", (int *) &this->unk6F0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath1Level1Timer", (int *) &this->unk6F4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath1Level2NumTier1", (int *) &this->unk6F8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath1Level2NumTier2", (int *) &this->unk6FC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath1Level2Timer", (int *) &this->unk700, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath2Level1NumTier1", (int *) &this->unk704, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath2Level1NumTier2", (int *) &this->unk708, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath2Level1Timer", (int *) &this->unk70C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath2Level2NumTier1", (int *) &this->unk710, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath2Level2NumTier2", (int *) &this->unk714, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireBreath2Level2Timer", (int *) &this->unk718, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("FireBreath2VanguardDistance", &this->unk71C, 0) != 0) {
        this->unk71C *= 100.0f;
        return 1U;
    }
    if (arg0->LoadInt("FireFuryNumTier1", (int *) &this->unk720, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("FireFuryNumTier2", (int *) &this->unk724, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("FireFuryDojoRadiusMul", &this->unk728, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath1Level1NumTier1", (int *) &this->unk72C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath1Level1NumTier2", (int *) &this->unk730, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath1Level1Timer", (int *) &this->unk734, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath1Level2NumTier1", (int *) &this->unk738, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath1Level2NumTier2", (int *) &this->unk73C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath1Level2Timer", (int *) &this->unk740, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath2Level1NumTier1", (int *) &this->unk744, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath2Level1NumTier2", (int *) &this->unk748, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath2Level1Timer", (int *) &this->unk74C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath2Level2NumTier1", (int *) &this->unk750, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath2Level2NumTier2", (int *) &this->unk754, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricBreath2Level2Timer", (int *) &this->unk758, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("ElectricBreath2VanguardDistance", &this->unk75C, 0) != 0) {
        this->unk75C *= 100.0f;
        return 1U;
    }
    if (arg0->LoadInt("ElectricFuryNumTier1", (int *) &this->unk760, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("ElectricFuryNumTier2", (int *) &this->unk764, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("ElectricFuryDojoRadiusMul", &this->unk768, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath1Level1NumTier1", (int *) &this->unk76C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath1Level1NumTier2", (int *) &this->unk770, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath1Level1Timer", (int *) &this->unk774, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath1Level2NumTier1", (int *) &this->unk778, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath1Level2NumTier2", (int *) &this->unk77C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath1Level2Timer", (int *) &this->unk780, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2Level1NumTier1", (int *) &this->unk784, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2Level1NumTier2", (int *) &this->unk788, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2Level1Timer", (int *) &this->unk78C, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2Level2NumTier1", (int *) &this->unk790, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2Level2NumTier2", (int *) &this->unk794, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2Level2Timer", (int *) &this->unk798, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("IceBreath2VanguardDistance", &this->unk79C, 0) != 0) {
        this->unk79C *= 100.0f;
        return 1U;
    }
    if (arg0->LoadInt("IceBreath2NumLevel1Iterations", (int *) &this->unk7A0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceFuryNumTier1", (int *) &this->unk7A4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("IceFuryNumTier2", (int *) &this->unk7A8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadFloat("IceFuryDojoRadiusMul", &this->unk7AC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath1Level1NumTier1", (int *) &this->unk7B0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath1Level1NumTier2", (int *) &this->unk7B4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath1Level1Timer", (int *) &this->unk7B8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath1Level2NumTier1", (int *) &this->unk7BC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath1Level2NumTier2", (int *) &this->unk7C0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath1Level2Timer", (int *) &this->unk7C4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath2Level1NumTier1", (int *) &this->unk7C8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath2Level1NumTier2", (int *) &this->unk7CC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath2Level1Timer", (int *) &this->unk7D0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath2Level2NumTier1", (int *) &this->unk7D4, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath2Level2NumTier2", (int *) &this->unk7D8, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthBreath2Level2Timer", (int *) &this->unk7DC, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthFuryNumTier1", (int *) &this->unk7E0, 0) != 0) {
        return 1U;
    }
    if (arg0->LoadInt("EarthFuryNumTier2", (int *) &this->unk7E4, 0) != 0) {
        return 1U;
    }
    return (u8) (arg0->LoadFloat("EarthFuryDojoRadiusMul", &this->unk7E8, 0) != 0);
}

#if 0 // DRAFT: illegal implicit conversion from 'DojoController' to
void DojoController::Deinit() {
    SpawnPointData *temp_r3_14510;
    SpawnPointData *temp_r3_14515;
    SpawnPointData *temp_r3_14520;
    SpawnPointData *temp_r3_14525;
    s32 temp_cr0_eq_14497;
    s32 var_r30_14492;
    s32 var_r31_14493;
    void **temp_r3_14496;

    this->unk360.Deinit(this);
    this->unk2C0.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        this->unk2C0.KillAll();
    }
    this->unk310.GetNumberActive();
    if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        this->unk310.KillAll();
    }
    this->unk2C0.Deinit();
    this->unk310.Deinit();
    var_r30_14492 = 0;
    var_r31_14493 = 0;
    do {
        temp_r3_14496 = *(this + (var_r31_14493 + 0x84));
        temp_cr0_eq_14497 = temp_r3_14496 == NULL;
        if ((temp_cr0_eq_14497 == 0) && (temp_cr0_eq_14497 == 0)) {
            M2C_FIELD(*temp_r3_14496, M2C_UNK (**)(M2C_UNK), 8)(1);
        }
        var_r30_14492 += 1;
        var_r31_14493 += 0x60;
    } while (var_r30_14492 < 6);
    temp_r3_14510 = this->unk44C;
    if (temp_r3_14510 != NULL) {
        operator delete(temp_r3_14510);
    }
    temp_r3_14515 = this->unk450;
    if (temp_r3_14515 != NULL) {
        operator delete(temp_r3_14515);
    }
    temp_r3_14520 = this->unk454;
    if (temp_r3_14520 != NULL) {
        operator delete(temp_r3_14520);
    }
    temp_r3_14525 = this->unk458;
    if (temp_r3_14525 != NULL) {
        operator delete(temp_r3_14525);
    }
    M2C_FIELD(&gb, s8 *, 5) = 1;
    M2C_FIELD(&gb, s8 *, 6) = 1;
    M2C_FIELD(&gb, s8 *, 7) = 1;
    M2C_FIELD(&gb, s8 *, 4) = 1;
    M2C_FIELD(&gb, s8 *, 8) = 1;
    PhrasePlayer_StopEvent(this->unk7EC);
    M2C_FIELD(&gb, s8 *, 0x59) = 0;
    M2C_FIELD(&gb, s8 *, 0xA) = 0;
    ((GameGlobals *) &gb)->InfiniteMagicOff();
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'dojoStates'
void DojoController::Init() {
    SpawnPointData *temp_r29_14593;
    SpawnPointData *temp_r3_14701;
    SpawnPointData *temp_r3_14722;
    SpawnPointData *temp_r3_14743;
    SpawnPointData *temp_r3_14764;
    s32 temp_r0_14652;
    s32 temp_r0_14681;
    s32 var_ctr_14650;
    s32 var_ctr_14679;
    s32 var_r28_14586;
    s32 var_r30_14587;
    s32 var_r3_14640;
    s32 var_r3_14660;
    void **temp_r3_14790;
    void **temp_r3_14801;
    void **temp_r3_14812;
    void **temp_r3_14823;

    this->unk360.Init(&dojoStates, NULL);
    this->unk3B4 = -1.0f;
    M2C_FIELD(this, f64 *, 0x378) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x380) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk2C0.Init(EnemySpawnPool_Action, 0);
    this->unk310.Init(EnemySpawnPool_Action, 0);
    var_r28_14586 = 0;
    var_r30_14587 = 0;
    do {
        operator new(0x28U, NULL, 0);
        temp_r29_14593 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r29_14593 != NULL) {
            temp_r29_14593->__vptr = &__vt;
            temp_r29_14593->__vptr = &__vt;
            M2C_FIELD(temp_r29_14593, s32 *, 8) = 0;
            ((EventMessage *) (temp_r29_14593 + 8))->Init();
            M2C_FIELD(temp_r29_14593, s32 *, 0xC) = 0;
            ((EventMessage *) (temp_r29_14593 + 0xC))->Init();
            M2C_FIELD(temp_r29_14593, s32 *, 0x10) = 0;
            ((EventMessage *) (temp_r29_14593 + 0x10))->Init();
            M2C_FIELD(temp_r29_14593, s32 *, 0x14) = 0;
            ((EventMessage *) (temp_r29_14593 + 0x14))->Init();
        }
        ((SpawnPointObject *) (this + (var_r30_14587 + 0x80)))->Init(temp_r29_14593);
        var_r28_14586 += 1;
        var_r30_14587 += 0x60;
    } while (var_r28_14586 < 6);
    this->unk7EC = 0;
    this->unk7F0 = 0;
    strcpy(&this->unk7F1, "");
    M2C_FIELD(&gb, s8 *, 0x59) = 1;
    var_r3_14640 = 0;
    this->unk3BE = 0;
    this->unk3BF = 0;
    this->unk3C0 = 0;
    this->unk3C1 = 0;
    this->unk3C2 = 0;
    this->unk3C3 = 0;
    this->unk3C4 = 0;
    this->unk678 = 0;
    this->unk679 = 0;
    var_ctr_14650 = 7;
    do {
        temp_r0_14652 = var_r3_14640 + 0x410;
        var_r3_14640 += 4;
        *(this + temp_r0_14652) = 0;
        var_ctr_14650 -= 1;
    } while (var_ctr_14650 != 0);
    this->unk448 = 0;
    var_r3_14660 = 0;
    this->unk40C = 0;
    this->unk3B8 = 0.0f;
    this->unk814 = 0.0f;
    this->unk818 = 0;
    this->unk81C = 0;
    this->unk3D8 = NULL;
    this->unk404 = NULL;
    this->unk408 = NULL;
    this->unk3E4 = NULL;
    this->unk3E8 = NULL;
    this->unk3EC = NULL;
    this->unk3F0 = NULL;
    this->unk60 = NULL;
    this->unk64 = NULL;
    this->unk68 = NULL;
    this->unk6C = NULL;
    this->unk5C = NULL;
    this->unk668 = 0;
    var_ctr_14679 = 4;
    do {
        temp_r0_14681 = var_r3_14660 + 0x3F4;
        var_r3_14660 += 4;
        *(this + temp_r0_14681) = 0;
        var_ctr_14679 -= 1;
    } while (var_ctr_14679 != 0);
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk44C = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_14701 = this->unk44C;
    temp_r3_14701->~SpawnPointData(this, 0);
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk450 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_14722 = this->unk450;
    temp_r3_14722->~SpawnPointData(this, 0);
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk454 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_14743 = this->unk454;
    temp_r3_14743->~SpawnPointData(this, 0);
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk458 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_14764 = this->unk458;
    temp_r3_14764->~SpawnPointData(this, 0);
    this->unk70 = &this->unk44C->__vptr;
    switch ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x18C)) { /* irregular */
    case 0:
        this->unk70 = &this->unk44C->__vptr;
        temp_r3_14790 = this->unk70;
        M2C_FIELD(*temp_r3_14790, M2C_UNK (**)(void **, DojoController *, M2C_UNK), 8)(temp_r3_14790, this, 0);
        break;
    case 1:
        this->unk70 = &this->unk450->__vptr;
        temp_r3_14801 = this->unk70;
        M2C_FIELD(*temp_r3_14801, M2C_UNK (**)(void **, DojoController *, M2C_UNK), 8)(temp_r3_14801, this, 0);
        break;
    case 2:
        this->unk70 = &this->unk454->__vptr;
        temp_r3_14812 = this->unk70;
        M2C_FIELD(*temp_r3_14812, M2C_UNK (**)(void **, DojoController *, M2C_UNK), 8)(temp_r3_14812, this, 0);
        break;
    case 3:
        this->unk70 = &this->unk458->__vptr;
        temp_r3_14823 = this->unk70;
        M2C_FIELD(*temp_r3_14823, M2C_UNK (**)(void **, DojoController *, M2C_UNK), 8)(temp_r3_14823, this, 0);
        break;
    }
    MKProp::Init();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
DojoController::DojoController() {
    this->unk4C.unk0 = 0;
    this->unk4C.Init();
    this->unk50.unk0 = 0;
    this->unk50.Init();
    this->unk54.unk0 = 0;
    this->unk54.Init();
    this->unk58.unk0 = 0;
    this->unk58.Init();
    this->unk70 = NULL;
    this->unk2C0.__vptr = &__vt;
    this->unk2C0.unk3C.unk0 = 0;
    this->unk2C0.unk3C.Init();
    this->unk2C0.unk40.unk0 = 0;
    this->unk2C0.unk40.Init();
    this->unk310.__vptr = &__vt;
    this->unk310.unk3C.unk0 = 0;
    this->unk310.unk3C.Init();
    this->unk310.unk40.unk0 = 0;
    this->unk310.unk40.Init();
    this->unk360.unk0 = -1;
    this->unk364 = -1;
    this->unk368 = 0;
    this->unk36C = 0;
    M2C_FIELD(this, f64 *, 0x378) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x380) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk3B4 = -1.0f;
    this->unk3BE = 0;
    this->unk3BF = 0;
    this->unk3C0 = 0;
    this->unk3D8 = NULL;
    this->unk3DC = NULL;
    this->unk3E0 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_761'
void DojoController_cpp::__sinit() {
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_15354;
    f64 temp_f1_15319;
    f64 temp_f1_15334;
    f64 temp_f1_15357;
    f64 temp_f3_15304;
    f64 temp_f4_15318;
    f64 temp_f4_15331;
    f64 temp_f8_15306;
    void *temp_r17_15313;

    temp_f3_15304 = __frsqrte(2014000.0);
    temp_f8_15306 = __frsqrte(380000.0);
    temp_r17_15313 = &lit_761 + 0x120;
    temp_f4_15318 = 0.5 * temp_f3_15304 * -((2014000.0 * (temp_f3_15304 * temp_f3_15304)) - 3.0);
    temp_f1_15319 = 0.5 * temp_f8_15306 * -((380000.0 * (temp_f8_15306 * temp_f8_15306)) - 3.0);
    temp_f4_15331 = 0.5 * temp_f4_15318 * -((2014000.0 * (temp_f4_15318 * temp_f4_15318)) - 3.0);
    temp_f1_15334 = 0.5 * temp_f1_15319 * -((380000.0 * (temp_f1_15319 * temp_f1_15319)) - 3.0);
    temp_f0_15354 = 0.5 * temp_f1_15334 * -((380000.0 * (temp_f1_15334 * temp_f1_15334)) - 3.0);
    temp_f1_15357 = 2014000.0 * (0.5 * temp_f4_15331 * -((2014000.0 * (temp_f4_15331 * temp_f4_15331)) - 3.0));
    M2C_FIELD(&lit_761, s32 *, 0x120) = (s32) M2C_FIELD(&lit_761, s32 *, 0);
    M2C_FIELD(&lit_761, s32 *, 0x124) = (s32) M2C_FIELD(&lit_761, s32 *, 4);
    M2C_FIELD(&lit_761, s32 *, 0x128) = (s32) M2C_FIELD(&lit_761, s32 *, 8);
    M2C_FIELD(temp_r17_15313, s32 *, 0xC) = (s32) M2C_FIELD(&lit_761, s32 *, 0xC);
    M2C_FIELD(temp_r17_15313, s32 *, 0x10) = (s32) M2C_FIELD(&lit_761, s32 *, 0x10);
    M2C_FIELD(temp_r17_15313, s32 *, 0x14) = (s32) M2C_FIELD(&lit_761, s32 *, 0x14);
    M2C_FIELD(temp_r17_15313, s32 *, 0x18) = (s32) M2C_FIELD(&lit_761, s32 *, 0x18);
    M2C_FIELD(temp_r17_15313, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x1C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x20) = (s32) M2C_FIELD(&lit_761, s32 *, 0x20);
    M2C_FIELD(temp_r17_15313, s32 *, 0x24) = (s32) M2C_FIELD(&lit_761, s32 *, 0x24);
    M2C_FIELD(temp_r17_15313, s32 *, 0x28) = (s32) M2C_FIELD(&lit_761, s32 *, 0x28);
    M2C_FIELD(temp_r17_15313, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x2C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x30) = (s32) M2C_FIELD(&lit_761, s32 *, 0x30);
    M2C_FIELD(temp_r17_15313, s32 *, 0x34) = (s32) M2C_FIELD(&lit_761, s32 *, 0x34);
    M2C_FIELD(temp_r17_15313, s32 *, 0x38) = (s32) M2C_FIELD(&lit_761, s32 *, 0x38);
    M2C_FIELD(temp_r17_15313, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x3C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x40) = (s32) M2C_FIELD(&lit_761, s32 *, 0x40);
    M2C_FIELD(temp_r17_15313, s32 *, 0x44) = (s32) M2C_FIELD(&lit_761, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) temp_f1_15357;
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * temp_f0_15354);
    M2C_FIELD(temp_r17_15313, s32 *, 0x48) = (s32) M2C_FIELD(&lit_761, s32 *, 0x48);
    M2C_FIELD(temp_r17_15313, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x4C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x50) = (s32) M2C_FIELD(&lit_761, s32 *, 0x50);
    sp50 = M2C_FIELD(&lit_761, s32 *, 0xBC);
    M2C_FIELD(temp_r17_15313, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_761, s32 *, 0xB4);
    sp8 = M2C_FIELD(&lit_761, s32 *, 0xC0);
    M2C_FIELD(temp_r17_15313, s32 *, 0xBC) = sp50;
    spC = M2C_FIELD(&lit_761, s32 *, 0xC4);
    M2C_FIELD(temp_r17_15313, s32 *, 0xC0) = sp8;
    sp10 = M2C_FIELD(&lit_761, s32 *, 0xC8);
    M2C_FIELD(temp_r17_15313, s32 *, 0xC4) = spC;
    sp14 = M2C_FIELD(&lit_761, s32 *, 0xCC);
    M2C_FIELD(temp_r17_15313, s32 *, 0xC8) = sp10;
    sp18 = M2C_FIELD(&lit_761, s32 *, 0xD0);
    M2C_FIELD(temp_r17_15313, s32 *, 0xCC) = sp14;
    sp1C = M2C_FIELD(&lit_761, s32 *, 0xD4);
    M2C_FIELD(temp_r17_15313, s32 *, 0xD0) = sp18;
    sp20 = M2C_FIELD(&lit_761, s32 *, 0xD8);
    M2C_FIELD(temp_r17_15313, s32 *, 0xD4) = sp1C;
    sp24 = M2C_FIELD(&lit_761, s32 *, 0xDC);
    M2C_FIELD(temp_r17_15313, s32 *, 0xD8) = sp20;
    sp28 = M2C_FIELD(&lit_761, s32 *, 0xE0);
    M2C_FIELD(temp_r17_15313, s32 *, 0xDC) = sp24;
    sp2C = M2C_FIELD(&lit_761, s32 *, 0xE4);
    M2C_FIELD(temp_r17_15313, s32 *, 0xE0) = sp28;
    sp30 = M2C_FIELD(&lit_761, s32 *, 0xE8);
    M2C_FIELD(temp_r17_15313, s32 *, 0xE4) = sp2C;
    sp34 = M2C_FIELD(&lit_761, s32 *, 0xEC);
    M2C_FIELD(temp_r17_15313, s32 *, 0xE8) = sp30;
    sp38 = M2C_FIELD(&lit_761, s32 *, 0xF0);
    M2C_FIELD(temp_r17_15313, s32 *, 0xEC) = sp34;
    sp3C = M2C_FIELD(&lit_761, s32 *, 0xF4);
    M2C_FIELD(temp_r17_15313, s32 *, 0xF0) = sp38;
    sp40 = M2C_FIELD(&lit_761, s32 *, 0xF8);
    M2C_FIELD(temp_r17_15313, s32 *, 0xF4) = sp3C;
    sp44 = M2C_FIELD(&lit_761, s32 *, 0xFC);
    M2C_FIELD(temp_r17_15313, s32 *, 0xF8) = sp40;
    sp48 = M2C_FIELD(&lit_761, s32 *, 0x100);
    M2C_FIELD(temp_r17_15313, s32 *, 0xFC) = sp44;
    M2C_FIELD(temp_r17_15313, s32 *, 0x100) = sp48;
    sp4C = M2C_FIELD(&lit_761, s32 *, 0x104);
    M2C_FIELD(temp_r17_15313, s32 *, 0x54) = (s32) M2C_FIELD(&lit_761, s32 *, 0x54);
    M2C_FIELD(temp_r17_15313, s32 *, 0x58) = (s32) M2C_FIELD(&lit_761, s32 *, 0x58);
    M2C_FIELD(temp_r17_15313, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x5C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x60) = (s32) M2C_FIELD(&lit_761, s32 *, 0x60);
    M2C_FIELD(temp_r17_15313, s32 *, 0x64) = (s32) M2C_FIELD(&lit_761, s32 *, 0x64);
    M2C_FIELD(temp_r17_15313, s32 *, 0x68) = (s32) M2C_FIELD(&lit_761, s32 *, 0x68);
    M2C_FIELD(temp_r17_15313, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x6C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x70) = (s32) M2C_FIELD(&lit_761, s32 *, 0x70);
    M2C_FIELD(temp_r17_15313, s32 *, 0x74) = (s32) M2C_FIELD(&lit_761, s32 *, 0x74);
    M2C_FIELD(temp_r17_15313, s32 *, 0x78) = (s32) M2C_FIELD(&lit_761, s32 *, 0x78);
    M2C_FIELD(temp_r17_15313, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x7C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x80) = (s32) M2C_FIELD(&lit_761, s32 *, 0x80);
    M2C_FIELD(temp_r17_15313, s32 *, 0x84) = (s32) M2C_FIELD(&lit_761, s32 *, 0x84);
    M2C_FIELD(temp_r17_15313, s32 *, 0x88) = (s32) M2C_FIELD(&lit_761, s32 *, 0x88);
    M2C_FIELD(temp_r17_15313, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x8C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x90) = (s32) M2C_FIELD(&lit_761, s32 *, 0x90);
    M2C_FIELD(temp_r17_15313, s32 *, 0x94) = (s32) M2C_FIELD(&lit_761, s32 *, 0x94);
    M2C_FIELD(temp_r17_15313, s32 *, 0x98) = (s32) M2C_FIELD(&lit_761, s32 *, 0x98);
    M2C_FIELD(temp_r17_15313, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x9C);
    M2C_FIELD(temp_r17_15313, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_761, s32 *, 0xA0);
    M2C_FIELD(temp_r17_15313, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_761, s32 *, 0xA4);
    M2C_FIELD(temp_r17_15313, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_761, s32 *, 0xA8);
    M2C_FIELD(temp_r17_15313, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_761, s32 *, 0xAC);
    M2C_FIELD(temp_r17_15313, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_761, s32 *, 0xB0);
    M2C_FIELD(temp_r17_15313, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_761, s32 *, 0xB8);
    M2C_FIELD(temp_r17_15313, s32 *, 0x104) = (s32) M2C_FIELD(&lit_761, s32 *, 0x104);
    M2C_FIELD(temp_r17_15313, s32 *, 0x108) = (s32) M2C_FIELD(&lit_761, s32 *, 0x108);
    M2C_FIELD(temp_r17_15313, s32 *, 0x10C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x10C);
    M2C_FIELD(temp_r17_15313, s32 *, 0x110) = (s32) M2C_FIELD(&lit_761, s32 *, 0x110);
    M2C_FIELD(temp_r17_15313, s32 *, 0x114) = (s32) M2C_FIELD(&lit_761, s32 *, 0x114);
    M2C_FIELD(temp_r17_15313, s32 *, 0x118) = (s32) M2C_FIELD(&lit_761, s32 *, 0x118);
    M2C_FIELD(temp_r17_15313, s32 *, 0x11C) = (s32) M2C_FIELD(&lit_761, s32 *, 0x11C);
}
#endif

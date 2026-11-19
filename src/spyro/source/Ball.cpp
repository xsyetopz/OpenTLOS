#include "spyro/source/Ball.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
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
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoulderRamp.h"
#include "spyro/source/Catapult.h"
#include "spyro/source/CrashMistPS.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
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
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
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
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SiegeTower.h"
#include "spyro/source/SnowballTree.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/Trap.h"
#include "spyro/source/WaterDripPS.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/DataMap.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f64 atan2(f32, f32);                                /* extern */
extern s32 GS_SpyroMeleeHit;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern Ball *pDribblee;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'DataMap'
static DataMap ballTypeMap[5] = {
    { 0, "Snow" },
    { 1, "Rock" },
    { 2, "Ice" },
    { 3, "SnowCynder" },
    { 4, NULL },
};
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_groups_0x28'
static struct _struct_groups_0x28 groups[8];
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_ballProperties_0x3'
static struct _struct_ballProperties_0x3 ballProperties[4]; /* unable to generate initializer: non-zero padding; const */
#endif

void Ball::BridgeHit(float arg0, float arg1) {
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    s32 spBC;
    s32 spB8;
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
    f64 temp_f1_244;
    f64 temp_f1_270;
    f64 temp_f2_221;
    void *temp_r4_211;
    void *temp_r5_214;

    if ((void *) this->unk230 != NULL) {
        temp_r4_211 = this->unk264;
        if (temp_r4_211 != NULL) {
            temp_r5_214 = this->unk8;
            sp48 = M2C_FIELD(temp_r5_214, f64 *, 0) * (f64) arg0;
            temp_f2_221 = M2C_FIELD(temp_r5_214, f64 *, 0x30);
            sp78 = sp48;
            sp50 = M2C_FIELD(temp_r5_214, f32 *, 8) * arg0;
            sp88 = temp_f2_221;
            sp80 = (f64) sp50;
            sp90 = M2C_FIELD(temp_r5_214, f64 *, 0x38);
            sp38 = temp_f2_221 + sp78;
            spA8 = sp38;
            sp40 = (f32) sp90 + (f32) sp80;
            spB0 = (f64) sp40;
            temp_f1_244 = this->unkF0 * 4.89153186e-315;
            sp28 = temp_f1_244;
            sp98 = temp_f1_244;
            sp30 = this->unkF8 * 0.002f;
            spC = -1.0f;
            spA0 = (f64) sp30;
            sp8 = -(f32) sp98;
            (*(f32 *) ((u8 *) &sp98 + 0x4)) = 1.0f;
            sp10 = -(f32) spA0;
            sp58 = (f64) sp8;
            spBC = 0;
            sp60 = (f64) sp10;
            temp_f1_270 = sp58 * (f64) arg1;
            sp18 = temp_f1_270;
            spC0 = sp38;
            spC8 = (f64) sp40;
            sp20 = (f32) sp60 * arg1;
            spD0 = temp_f1_270;
            spD8 = (f64) sp20;
            spB8 = 0x3C;
            sp68 = temp_f1_270;
            sp70 = (f64) sp20;
            M2C_FIELD(M2C_FIELD(temp_r4_211, void **, 0x44), M2C_UNK (**)(void *, s32 *, void *, f64, f32, f32, f64, f64, f64, f32), 0x2C)(temp_r4_211, &spB8, temp_r5_214, temp_f1_270, (f32) sp60, 1.0f, (f64) sp30, (f64) sp40, sp38, 0.002f);
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
void Ball::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp2C;
    u8 sp28;
    MKProp **sp24;
    s32 sp20;
    s32 sp1C;
    s8 sp18;
    MKCollisionInfo *sp14;
    MKProp ***sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_314;
    s32 temp_r3_310;

    PlatformDetach();
    temp_r3_310 = M2C_FIELD(arg0->unk0, s32 *, 0xC);
    if (temp_r3_310 & 0x4000) {
        this->unk234 = arg0;
        temp_r3_314 = this->unk234;
        if (temp_r3_314 != NULL) {
            sp20 = 0;
            sp1C = 0x23;
            sp24 = &this->unk238;
            sp28 = 0;
            sp2C = arg1;
            M2C_FIELD(temp_r3_314->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp1C, 0x23, 0);
            if (sp28 == 0) {
                this->unk234 = NULL;
            }
        }
    } else if (temp_r3_310 & 0x20000) {
        spC = 0;
        sp8 = 0x99;
        sp10 = &this->unk248;
        sp14 = arg1;
        sp18 = 0;
        arg0->Message(&sp8, 0x99, 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Ball::PlatformDetach() {
    s32 sp2C;
    s8 sp28;
    MKProp **sp24;
    s32 sp20;
    s32 sp1C;
    s8 sp18;
    MKProp ***sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_369;
    void *temp_r3_389;

    temp_r3_369 = this->unk234;
    if (temp_r3_369 != NULL) {
        sp20 = 0;
        sp1C = 0x24;
        sp24 = &this->unk238;
        sp28 = 0;
        sp2C = 0;
        M2C_FIELD(temp_r3_369->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp1C, 0x24, 0);
        this->unk234 = NULL;
        return;
    }
    temp_r3_389 = this->unk264;
    if (temp_r3_389 != NULL) {
        spC = 0;
        sp8 = 0x9A;
        sp10 = &this->unk248;
        sp18 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_389, void **, 0x44), M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x9A, 0);
    }
}
#endif

void Ball::PlatformUpdate() {
    u8 sp58;
    s32 sp54;
    MKCollisionInfo *sp50;
    s32 sp4C;
    f32 sp48;
    s32 sp44;
    s8 sp43;
    s8 sp42;
    s16 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r0_489;
    MKProp *var_r31_482;
    MKProp *var_r3_465;
    void *temp_r0_495;

    if ((void *) this->unk230 != NULL) {
        sp8 = 0.0f;
        spC = 0.0f;
        sp10 = 0.0f;
        sp18 = 0.0f;
        sp1C = 0.0f;
        sp20 = 0.0f;
        sp28 = 0.0f;
        sp2C = 0.0f;
        sp30 = 0.0f;
        sp34 = 1.0f;
        sp38 = 0.0f;
        sp3C = 0.0f;
        sp40 = 0;
        sp42 = 0;
        sp43 = 0;
        sp44 = 0;
        sp48 = 3.4028235e38f;
        sp4C = 0;
        sp50 = NULL;
        sp54 = -1;
        sp58 = 0;
        if (MKCollision_GetGroundPoint(*((MKVector3 *) &this->unkE0), 2000.0f, (MKCollisionResult *) &sp8, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
            if ((sp58 != 0) && (sp50 != NULL) && (var_r3_465 = sp50->unk8, ((var_r3_465 == NULL) == 0))) {

            } else {
                var_r3_465 = NULL;
            }
            if (var_r3_465 != (MKProp *) this->unk234) {
                goto block_8;
            }
        } else {
block_8:
            if ((sp58 != 0) && (sp50 != NULL) && (var_r31_482 = sp50->unk8, ((var_r31_482 == NULL) == 0))) {

            } else {
                var_r31_482 = NULL;
            }
            temp_r0_489 = this->unk234;
            if (((temp_r0_489 != NULL) && (var_r31_482 != temp_r0_489)) || ((temp_r0_495 = this->unk264, ((temp_r0_495 == NULL) == 0)) && (var_r31_482 != temp_r0_495))) {
                PlatformDetach();
            }
            if ((var_r31_482 != NULL) && (var_r31_482 != (MKProp *) this->unk234)) {
                PlatformAttach(var_r31_482, sp50);
            }
            if (var_r31_482 == NULL) {
                PlatformDetach();
            }
        }
    }
}

void Ball::SetParentTree(SnowballTree *arg0, int arg1, MKVector3 &arg2, float arg3) {
    this->unk22C = arg0;
    this->unk2A8 = arg1;
    this->unk140 = M2C_FIELD(&arg2, f64 *, 0);
    this->unk148 = M2C_FIELD(&arg2, f64 *, 8);
    this->unk2A0 = arg3;
}

#if 0 // DRAFT: illegal type
void Ball::SetGroup(int arg0) {
    s32 temp_r0_547;
    s32 temp_r5_546;
    s32 temp_r8_549;
    s32 var_ctr_558;
    s32 var_ctr_579;
    s32 var_r4_557;
    s32 var_r4_578;
    s32 var_r7_545;
    struct _struct_groups_0x28 *temp_r5_564;
    struct _struct_groups_0x28 *temp_r5_583;

    if (arg0 != 0xFF) {
        var_r7_545 = 6;
        temp_r5_546 = ((u8) this->unk2AC >> 3U) & 1;
        temp_r0_547 = 0 - temp_r5_546;
        temp_r8_549 = 6 & ((temp_r0_547 - temp_r0_547) - !M2C_CARRY);
        if (temp_r5_546 != 0) {
            var_r7_545 = 0xA;
        }
        this->unk2A8 = arg0;
        var_r4_557 = temp_r8_549 * 4;
        var_ctr_558 = var_r7_545 - temp_r8_549;
        if (temp_r8_549 < var_r7_545) {
loop_4:
            temp_r5_564 = (_struct_groups_0x28 *) (&groups[this->unk2A8]);
            if ((u32) *(temp_r5_564 + var_r4_557) == 0U) {
                *(temp_r5_564 + var_r4_557) = this;
                return;
            }
            var_r4_557 += 4;
            var_ctr_558 -= 1;
            if (var_ctr_558 == 0) {
                return;
            }
            goto loop_4;
        }
        return;
    }
    var_r4_578 = 0;
    var_ctr_579 = 0xA;
loop_9:
    temp_r5_583 = (_struct_groups_0x28 *) (&groups[this->unk2A8]);
    if ((u32) *(temp_r5_583 + var_r4_578) == this) {
        *(temp_r5_583 + var_r4_578) = 0;
        return;
    }
    var_r4_578 += 4;
    var_ctr_579 -= 1;
    if (var_ctr_579 == 0) {
        return;
    }
    goto loop_9;
}
#endif

#if 0 // DRAFT: undefined identifier 'groups'
void Ball::FindClosestGroup() {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_644;
    f32 var_f3_602;
    f64 temp_f0_627;
    f64 temp_f1_620;
    s32 var_ctr_612;
    s32 var_r10_606;
    s32 var_r4_605;
    s32 var_r5_607;
    s32 var_r6_611;
    void *temp_r7_614;
    void *temp_r7_619;

    var_f3_602 = 3.4028235e38f;
    var_r4_605 = 0;
    var_r10_606 = 0;
    var_r5_607 = 0;
    do {
        var_r6_611 = 0;
        var_ctr_612 = 0xA;
loop_2:
        temp_r7_614 = (void *) (*(groups + var_r5_607 + var_r6_611));
        if ((temp_r7_614 != NULL) && (temp_r7_614 != this)) {
            temp_r7_619 = M2C_FIELD(temp_r7_614, void **, 8);
            temp_f1_620 = M2C_FIELD(temp_r7_619, f64 *, 0x30);
            sp18 = temp_f1_620;
            sp20 = M2C_FIELD(temp_r7_619, f64 *, 0x38);
            temp_f0_627 = temp_f1_620 - this->unkE0;
            sp8 = temp_f0_627;
            sp28 = temp_f0_627;
            sp10 = (f32) sp20 - this->unkE8;
            sp30 = (f64) sp10;
            temp_f0_644 = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4))));
            if (temp_f0_644 <= var_f3_602) {
                var_f3_602 = temp_f0_644;
                var_r4_605 = var_r10_606;
            }
        }
        var_r6_611 += 4;
        var_ctr_612 -= 1;
        if (var_ctr_612 != 0) {
            goto loop_2;
        }
        var_r10_606 += 1;
        var_r5_607 += 0x28;
    } while (var_r10_606 < 8);
    SetGroup(var_r4_605);
}
#endif

#if 0 // DRAFT: ')' expected
u8 Ball::MeleeHit(MKProp *arg0, float arg1, bool &arg2) {
    u8 sp1D;
    u8 sp1C;
    s32 sp18;
    f32 sp14;
    f32 sp10;
    Ball *spC;
    s32 sp8;
    MKVector3 *temp_r31_709;
    s32 temp_r7_680;

    if (arg0 != NULL) {
        temp_r7_680 = M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124);
        spC = NULL;
        sp10 = arg1;
        sp14 = 0.0f;
        sp18 = temp_r7_680;
        sp8 = 0x5F;
        sp1C = 1;
        sp1D = 0;
        spC = this;
        arg0->Message(&sp8, 0x5F, 0, temp_r7_680);
        if ((sp1D != 0) && ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x104) != 0)) {
            temp_r31_709 = ((u8 *) this->unk8) + 0x30;
            KDSound_Play3d(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x104), temp_r31_709, 0U, -1, 0.0f, 0U);
        }
        &arg2 = (bool *) (sp1C);
        return sp1D;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'MKMessage *'
void Ball::SmashHit(MKProp *arg0) {
    s8 sp56;
    s8 sp55;
    s8 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    Ball *sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    f64 temp_f1_756;
    f64 temp_f2_755;
    void *temp_r8_751;

    if (arg0 != NULL) {
        sp1C = 0;
        temp_r8_751 = this->unk8;
        temp_f2_755 = M2C_FIELD(temp_r8_751, f64 *, 0x30);
        temp_f1_756 = M2C_FIELD(temp_r8_751, f64 *, 0x38);
        sp8 = temp_f2_755;
        sp18 = 4;
        sp20 = this;
        sp28 = temp_f2_755;
        sp30 = temp_f1_756;
        sp38 = 1.0f;
        sp54 = 0;
        sp40 = 3;
        sp48 = 0x2000;
        sp55 = 0;
        sp56 = 0;
        sp44 = -1;
        sp4C = 0;
        sp50 = 0;
        sp3C = 1.0f;
        sp10 = temp_f1_756;
        arg0->Message(&sp18, 0x2000, 3, 4, temp_r8_751, 0, temp_f1_756, temp_f2_755);
    }
    Smash();
}
#endif

#if 0 // DRAFT: ')' expected
void Ball::Smash() {
    Matrix spC0;
    M2C_UNK spBC;
    f32 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    MKVector3 sp50;
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
    f64 sp10;
    MKVector3 *temp_r29_982;
    f32 temp_f1_893;
    f32 temp_f21_888;
    f32 temp_f22_891;
    f64 temp_f1_917;
    f64 temp_f2_914;
    s32 temp_r0_822;
    s32 var_r28_877;
    void *temp_r27_928;
    void *temp_r3_923;
    void *temp_r4_926;

    temp_r0_822 = M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124);
    if (temp_r0_822 != 3) {
        if (temp_r0_822 < 3) {
            if (temp_r0_822 != 0) {

            } else {
                goto block_4;
            }
        }
    } else {
block_4:
        M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp48 = 0.0f;
        sp40 = 0.0f;
        sp44 = 1.0f;
        spA8 = (f64) sp48;
        spA0 = (f64) sp40;
        if ((u8) this->unk1A0 != 0) {
            spA0 = this->unk160;
            spA8 = this->unk168;
        }
        sp30 = 0.0f;
        sp34 = 0.0f;
        sp38 = 1.0f;
        sp90 = (f64) sp30;
        sp98 = (f64) sp38;
        KDMath_BuildMatrixFromUp(&spC0, *((MKVector3 *) &spA0), *((MKVector3 *) &sp90));
        var_r28_877 = 0;
        do {
            temp_f21_888 = 6.2831855f * ((f32) var_r28_877 / 19.0f);
            temp_f22_891 = -_table_sinf(1.5707964f + temp_f21_888);
            temp_f1_893 = _table_sinf(temp_f21_888);
            sp28 = temp_f22_891;
            sp20 = temp_f1_893;
            sp24 = 0.0f;
            sp88 = (f64) sp28;
            sp80 = (f64) sp20;
            temp_f2_914 = M2C_BITWISE(f64, spC0);
            temp_f1_917 = (temp_f2_914 * sp80) + (((f64) spC0.unk10 * sp80) + (((f64) spC0.unk20 * (f64) (f32) sp88) + (f64) spC0.unk30));
            spB8 = (f32) (((f64) spC0.unk8 * sp80) + (((f64) spC0.unk18 * sp80) + (((f64) spC0.unk28 * (f64) (f32) sp88) + (f64) spC0.unk38)));
            spB0 = temp_f1_917;
            temp_r3_923 = M2C_FIELD(M2C_FIELD(gb.unk2A0, void **, 0x44), void *(**)(void *, f64, f64, f64), 0x3C)(gb.unk2A0, temp_f1_917, temp_f2_914, sp80);
            if (temp_r3_923 != NULL) {
                temp_r4_926 = this->unk8;
                temp_r27_928 = M2C_FIELD(temp_r3_923, void **, 0x2C);
                M2C_FIELD(temp_r3_923, f64 *, 0) = (f64) M2C_FIELD(temp_r4_926, f64 *, 0x30);
                M2C_FIELD(temp_r3_923, f64 *, 8) = (f64) M2C_FIELD(temp_r4_926, f64 *, 0x38);
                M2C_FIELD(temp_r3_923, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_923, f32 *, 0x28) = 0.0f;
                sp50 = MKVector(0.0f, 300.0f, 0.0f);
                sp60.operator*(1000.0f);
                sp10 = sp60 + M2C_BITWISE(f64, sp50);
                M2C_FIELD(temp_r27_928, f64 *, 0) = sp10;
                sp18 = sp60.unk8 + sp50.unk8;
                sp70 = sp10;
                M2C_FIELD(temp_r27_928, f64 *, 8) = (f64) sp18;
                sp78 = (f64) sp18;
                M2C_FIELD(temp_r27_928, f32 *, 0x18) = (f32) (this->unk274 / 100.0f);
                M2C_FIELD(temp_r27_928, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r27_928, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A0, f32 *, 0xF4);
            }
            var_r28_877 += 1;
        } while (var_r28_877 < 0x14);
    }
    if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) {
        temp_r29_982 = ((u8 *) this->unk8) + 0x30;
        KDSound_Play3d(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), temp_r29_982, 0U, -1, 0.0f, 0U);
    }
    if ((SnowballTree *) this->unk22C != NULL) {
        Reset();
    } else {
        SetState((Ball::State) 5);
        Disable();
    }
    if ((Ball *) pDribblee == this) {
        pDribblee = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Ball::State'
void Ball::SetState(Ball::State arg1) {
    this->unk270 = (s32) arg1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Ball::State'
void Ball::Fire(MKVector3 &arg0) {
    this->unkF0 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    if ((Ball *) pDribblee == this) {
        pDribblee = NULL;
    }
    SetState((Ball::State) 2);
}
#endif

void Ball::SetPhysicsOn(bool arg0) {
    this->unk2AC = (this->unk2AC & ~0x80) | ((arg0 << 7) & 0x80);
}

#if 0 // DRAFT: ')' expected
void Ball::CheckForSiegeTowers() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    SiegeTower *temp_r3_1115;
    f64 temp_f1_1124;
    s32 temp_r31_1109;
    s32 var_r30_1110;
    u32 temp_r0_1118;
    void *temp_r4_1122;
    void *temp_r5_1121;

    if (((s32) this->unk2A8 != 0xFF) && ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124) == 0)) {
        if ((s32) this->unk270 == 2) {
            return;
        }
        temp_r31_1109 = SiegeTower_GetMaxPerGroup();
        var_r30_1110 = 0;
loop_14:
        if (var_r30_1110 < temp_r31_1109) {
            temp_r3_1115 = SiegeTower_GetSiegeTower(this->unk2A8, var_r30_1110);
            if (temp_r3_1115 != NULL) {
                temp_r0_1118 = temp_r3_1115->unk298;
                if (temp_r0_1118 == 0) {
                    temp_r5_1121 = this->unk8;
                    temp_r4_1122 = temp_r3_1115->unk8;
                    temp_f1_1124 = M2C_FIELD(temp_r4_1122, f64 *, 0x30);
                    sp18 = M2C_FIELD(temp_r5_1121, f64 *, 0x30);
                    sp28 = temp_f1_1124;
                    sp20 = M2C_FIELD(temp_r5_1121, f64 *, 0x38);
                    sp30 = M2C_FIELD(temp_r4_1122, f64 *, 0x38);
                    sp8 = temp_f1_1124 - sp18;
                    sp38 = sp8;
                    sp10 = (f32) sp30 - (f32) sp20;
                    sp40 = (f64) sp10;
                    if ((((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4))))) < 9e6f) {
                        if (temp_r0_1118 == 0) {
                            temp_r3_1115->ZapBall(this);
                        }
                        if ((Ball *) pDribblee == this) {
                            pDribblee = NULL;
                        }
                        this->unkF0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                        M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
                    }
                }
            }
            var_r30_1110 += 1;
            goto loop_14;
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Ball::CheckForRamps() {
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
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f3_1272;
    f64 temp_f0_1253;
    f64 temp_f4_1219;
    f64 temp_f5_1217;
    f64 temp_f6_1218;
    f64 temp_f7_1216;
    s32 temp_r31_1202;
    s32 temp_r3_1208;
    s32 var_r30_1203;
    void *temp_r3_1215;
    void *temp_r4_1214;

    if ((s32) this->unk2A8 != 0xFF) {
        if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124) != 1) {
            return;
        }
        temp_r31_1202 = BoulderRamp_GetMaxPerGroup();
        var_r30_1203 = 0;
loop_12:
        if (var_r30_1203 < temp_r31_1202) {
            temp_r3_1208 = BoulderRamp_GetCatapult(this->unk2A8, var_r30_1203);
            if ((temp_r3_1208 != 0) && (((BoulderRamp *) temp_r3_1208)->HasBoulder() == 0)) {
                temp_r4_1214 = this->unk8;
                temp_r3_1215 = M2C_FIELD(temp_r3_1208, void **, 8);
                temp_f7_1216 = M2C_FIELD(temp_r4_1214, f64 *, 0x30);
                temp_f5_1217 = M2C_FIELD(temp_r3_1215, f64 *, 0x30);
                temp_f6_1218 = M2C_FIELD(temp_r4_1214, f64 *, 0x38);
                temp_f4_1219 = M2C_FIELD(temp_r3_1215, f64 *, 0x38);
                sp48 = temp_f7_1216;
                sp58 = temp_f5_1217;
                sp50 = temp_f6_1218;
                sp60 = temp_f4_1219;
                sp18 = sp58 - sp48;
                sp68 = sp18;
                sp20 = (f32) sp60 - (f32) sp50;
                sp70 = (f64) sp20;
                if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))))) < 1000000.0f) {
                    sp28 = temp_f7_1216;
                    sp38 = temp_f5_1217;
                    sp30 = temp_f6_1218;
                    sp40 = temp_f4_1219;
                    temp_f0_1253 = sp38 - sp28;
                    sp8 = temp_f0_1253;
                    sp78 = temp_f0_1253;
                    sp10 = (f32) sp40 - (f32) sp30;
                    sp80 = (f64) sp10;
                    temp_f3_1272 = 100.0f * (4.5f * this->unk280);
                    if ((((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * (*(f32 *) ((u8 *) &sp78 + 0x4))))) < (temp_f3_1272 * temp_f3_1272)) {
                        ((BoulderRamp *) temp_r3_1208)->SetBoulder(this);
                        if ((Ball *) pDribblee == this) {
                            pDribblee = NULL;
                        }
                        this->unkF0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                        M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
                        SetState((Ball::State) 4);
                    }
                }
            }
            var_r30_1203 += 1;
            goto loop_12;
        }
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Ball::CheckForCatapults() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r29_1418;
    f32 temp_f3_1404;
    f64 temp_f0_1385;
    f64 temp_f1_1347;
    f64 temp_f4_1348;
    f64 temp_f5_1346;
    s32 temp_r30_1329;
    s32 temp_r3_1335;
    s32 var_r28_1330;
    void *temp_r3_1345;
    void *temp_r4_1344;

    if ((s32) this->unk2A8 != 0xFF) {
        if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124) == 3) {
            return;
        }
        temp_r30_1329 = Catapult_GetMaxPerGroup();
        var_r28_1330 = 0;
loop_15:
        if (var_r28_1330 < temp_r30_1329) {
            temp_r3_1335 = Catapult_GetCatapult(this->unk2A8, var_r28_1330);
            if ((temp_r3_1335 != 0) && ((u32) M2C_FIELD(temp_r3_1335, u32 *, 0x12C) == 0U) && (((Catapult *) temp_r3_1335)->CanLoadBall() != 0)) {
                temp_r4_1344 = this->unk8;
                temp_r3_1345 = M2C_FIELD(temp_r3_1335, void **, 8);
                temp_f5_1346 = M2C_FIELD(temp_r4_1344, f64 *, 0x30);
                temp_f1_1347 = M2C_FIELD(temp_r3_1345, f64 *, 0x30);
                temp_f4_1348 = M2C_FIELD(temp_r4_1344, f64 *, 0x38);
                sp48 = temp_f5_1346;
                sp58 = temp_f1_1347;
                sp50 = temp_f4_1348;
                sp60 = M2C_FIELD(temp_r3_1345, f64 *, 0x38);
                sp18 = temp_f1_1347 - sp48;
                sp68 = sp18;
                sp20 = (f32) sp60 - (f32) sp50;
                sp70 = (f64) sp20;
                if ((((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))))) < 1000000.0f) {
                    sp28 = temp_f5_1346;
                    sp30 = temp_f4_1348;
                    ((Catapult *) &sp38)->GetAmmoPos();
                    temp_f0_1385 = sp38 - sp28;
                    sp8 = temp_f0_1385;
                    sp78 = temp_f0_1385;
                    sp10 = sp40 - (f32) sp30;
                    sp80 = (f64) sp10;
                    temp_f3_1404 = 100.0f * (2.5f * this->unk280);
                    if ((((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * (*(f32 *) ((u8 *) &sp78 + 0x4))))) < (temp_f3_1404 * temp_f3_1404)) {
                        if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC) != 0) {
                            temp_r29_1418 = ((u8 *) this->unk8) + 0x30;
                            KDSound_Play3d(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC), temp_r29_1418, 0U, -1, 0.0f, 0U);
                        }
                        this->unk228 = (Catapult *) temp_r3_1335;
                        this->unk228->SetBall(this);
                        if ((Ball *) pDribblee == this) {
                            pDribblee = NULL;
                        }
                        this->unkF0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                        M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
                        SetState((Ball::State) 3);
                    }
                }
            }
            var_r28_1330 += 1;
            goto loop_15;
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void Ball::CheckForHero() {
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    HeroInterface sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
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
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1498;
    f32 temp_f1_1508;
    f32 temp_f1_1547;
    f32 temp_f1_1810;
    f32 temp_f1_1956;
    f32 temp_f28_1512;
    f32 temp_f29_1502;
    f32 temp_f2_1954;
    f32 temp_f30_1711;
    f32 temp_f31_1978;
    f32 var_f0_1862;
    f32 var_f1_1713;
    f32 var_f29_1787;
    f32 var_f5_1585;
    f32 var_f6_1594;
    f32 var_f9_1929;
    f64 temp_f0_1804;
    f64 temp_f0_1827;
    f64 temp_f0_1989;
    f64 temp_f1_1520;
    f64 temp_f1_1821;
    f64 temp_f2_1599;
    f64 temp_f2_1605;
    f64 temp_f2_1609;
    f64 temp_f2_1717;
    f64 temp_f2_1723;
    f64 temp_f2_1727;
    f64 temp_f2_1868;
    f64 temp_f2_1874;
    f64 temp_f2_1878;
    s32 temp_r3_1628;
    s32 temp_r3_1746;
    s32 temp_r3_1897;
    s32 var_r0_1638;
    s32 var_r0_1756;
    s32 var_r0_1907;
    void *temp_r3_1518;
    void *temp_r3_1550;
    void *temp_r3_1820;
    void *temp_r4_1517;
    void *temp_r4_1687;
    void *temp_r4_1802;

    gb.GetSpyro();
    if (M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), u8 (**)(), 0xC0)() == 0) {
        if (gb.unk0->InAir() != 0) {
            return;
        }
        temp_f1_1498 = this->unk274;
        temp_f29_1502 = temp_f1_1498 * this->unk280;
        temp_f1_1508 = temp_f29_1502 + gb.unk0->GetCollideRadius(temp_f1_1498);
        temp_f28_1512 = (1.2f * temp_f29_1502) + temp_f1_1508;
        temp_r4_1517 = M2C_FIELD(gb.unk0->GetProp(temp_f1_1508), void **, 8);
        temp_r3_1518 = this->unk8;
        temp_f1_1520 = M2C_FIELD(temp_r3_1518, f64 *, 0x30);
        sp148 = M2C_FIELD(temp_r4_1517, f64 *, 0x30);
        sp158 = temp_f1_1520;
        sp150 = M2C_FIELD(temp_r4_1517, f64 *, 0x38);
        sp160 = M2C_FIELD(temp_r3_1518, f64 *, 0x38);
        sp88 = temp_f1_1520 - sp148;
        sp178 = sp88;
        sp90 = (f32) sp160 - (f32) sp150;
        sp180 = (f64) sp90;
        temp_f1_1547 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp170 + 0xc)) * (*(f32 *) ((u8 *) &sp170 + 0xc))));
        if (temp_f1_1547 < (temp_f28_1512 * temp_f28_1512)) {
            temp_r3_1550 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x27C);
            if (((((u8 *) temp_r3_1550) + 8) != 0) && ((u32) (M2C_FIELD(temp_r3_1550, s32 *, 0x4C) + 0xFFFF0000) == 2U)) {
                sp128.GetPos();
                sp48 = this->unkE0 - M2C_BITWISE(f64, sp128);
                this->unkF0 = sp48;
                sp50 = this->unkE8 - sp130;
                sp138 = sp48;
                M2C_FIELD(this, f64 *, 0xF8) = (f64) sp50;
                M2C_FIELD(this, f32 *, 0xF4) = 0.0f;
                sp140 = (f64) sp50;
                this->unk2AC |= 0x80;
                return;
            }
            var_f5_1585 = 0.0f;
            (*(f32 *) ((u8 *) &sp170 + 0xc)) = 0.0f;
            var_f6_1594 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + (0.0f * 0.0f));
            if (var_f6_1594 > 0.000001f) {
                if (var_f6_1594 > 0.0f) {
                    temp_f2_1599 = __frsqrte(var_f6_1594);
                    temp_f2_1605 = 0.5 * temp_f2_1599 * -(((f64) var_f6_1594 * (temp_f2_1599 * temp_f2_1599)) - 3.0);
                    temp_f2_1609 = 0.5 * temp_f2_1605 * -(((f64) var_f6_1594 * (temp_f2_1605 * temp_f2_1605)) - 3.0);
                    var_f6_1594 = (f32) ((f64) var_f6_1594 * (0.5 * temp_f2_1609 * -(((f64) var_f6_1594 * (temp_f2_1609 * temp_f2_1609)) - 3.0)));
                } else if (var_f6_1594 < M2C_BITWISE(f32, 0.0)) {
                    var_f6_1594 = __float_nan;
                } else {
                    spC = var_f6_1594;
                    temp_r3_1628 = M2C_BITWISE(s32, spC) & 0x7F800000;
                    switch (temp_r3_1628) {         /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_1638 = 1;
                        } else {
                            var_r0_1638 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_1638 = 5;
                        } else {
                            var_r0_1638 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_1638 = 4;
                        break;
                    }
                    if (var_r0_1638 == 1) {
                        var_f6_1594 = __float_nan;
                    }
                }
                var_f5_1585 = 1.0f / var_f6_1594;
            }
            sp178 = (f32) sp178 * var_f5_1585;
            (*(f32 *) ((u8 *) &sp170 + 0xc)) *= var_f5_1585;
            sp180 = (f32) sp180 * var_f5_1585;
            if ((((u8) this->unk2AC >> 2U) & 1) && (((Ball *) pDribblee == NULL) || ((Ball *) pDribblee == this))) {
                temp_r4_1687 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
                sp78 = -M2C_FIELD(temp_r4_1687, f32 *, 0x20);
                sp7C = -M2C_FIELD(temp_r4_1687, f32 *, 0x24);
                sp80 = -M2C_FIELD(temp_r4_1687, f32 *, 0x28);
                sp118 = (f64) sp78;
                sp120 = (f64) sp80;
                temp_f30_1711 = (sp180 * (f32) sp120) + ((sp178 * (f32) sp118) + ((*(f32 *) ((u8 *) &sp170 + 0xc)) * (*(f32 *) ((u8 *) &sp118 + 0x4))));
                gb.GetSpyro();
                var_f1_1713 = Spyro::GetDeltaMove();
                if (var_f1_1713 > 0.0f) {
                    temp_f2_1717 = __frsqrte(var_f1_1713);
                    temp_f2_1723 = 0.5 * temp_f2_1717 * -(((f64) var_f1_1713 * (temp_f2_1717 * temp_f2_1717)) - 3.0);
                    temp_f2_1727 = 0.5 * temp_f2_1723 * -(((f64) var_f1_1713 * (temp_f2_1723 * temp_f2_1723)) - 3.0);
                    var_f1_1713 = (f32) ((f64) var_f1_1713 * (0.5 * temp_f2_1727 * -(((f64) var_f1_1713 * (temp_f2_1727 * temp_f2_1727)) - 3.0)));
                } else if (var_f1_1713 < M2C_BITWISE(f32, 0.0)) {
                    var_f1_1713 = __float_nan;
                } else {
                    sp10 = var_f1_1713;
                    temp_r3_1746 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1746) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1756 = 1;
                        } else {
                            var_r0_1756 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1756 = 5;
                        } else {
                            var_r0_1756 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1756 = 4;
                        break;
                    }
                    if (var_r0_1756 == 1) {
                        var_f1_1713 = __float_nan;
                    }
                }
                if ((temp_f30_1711 > 0.3f) && (var_f1_1713 > 0.1f)) {
                    var_f29_1787 = (var_f1_1713 / gUpdateTimeDelta) / 750.0f;
                    if (var_f29_1787 < 1.0f) {

                    } else {
                        var_f29_1787 = 1.0f;
                    }
                    temp_r4_1802 = (void *) (M2C_FIELD(gb.unk0->GetProp(), s32 *, 8) + 0x20);
                    temp_f0_1804 = M2C_FIELD(temp_r4_1802, f64 *, 0) * (f64) temp_f28_1512;
                    sp68 = temp_f0_1804;
                    temp_f1_1810 = M2C_FIELD(temp_r4_1802, f32 *, 8) * temp_f28_1512;
                    spF8 = temp_f0_1804;
                    sp70 = temp_f1_1810;
                    sp100 = (f64) sp70;
                    temp_r3_1820 = M2C_FIELD(gb.unk0->GetProp(temp_r4_1802, temp_f1_1810), void **, 8);
                    temp_f1_1821 = M2C_FIELD(temp_r3_1820, f64 *, 0x30);
                    sp108 = temp_f1_1821;
                    sp110 = M2C_FIELD(temp_r3_1820, f64 *, 0x38);
                    temp_f0_1827 = temp_f1_1821 - temp_f0_1804;
                    sp58 = temp_f0_1827;
                    sp168 = temp_f0_1827;
                    sp60 = (f32) sp110 - (f32) sp100;
                    sp170 = (f64) sp60;
                    ((MKProp *) &spD8)->GetPos();
                    sp38 = sp168 - spD8;
                    sp178 = sp38;
                    sp40 = (f32) sp170 - spE0;
                    sp180 = (f64) sp40;
                    spE8 = sp38;
                    spF0 = (f64) sp40;
                    var_f0_1862 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp170 + 0xc)) * (*(f32 *) ((u8 *) &sp170 + 0xc))));
                    if (var_f0_1862 > 0.000001f) {
                        if (var_f0_1862 > 0.0f) {
                            temp_f2_1868 = __frsqrte(var_f0_1862);
                            temp_f2_1874 = 0.5 * temp_f2_1868 * -(((f64) var_f0_1862 * (temp_f2_1868 * temp_f2_1868)) - 3.0);
                            temp_f2_1878 = 0.5 * temp_f2_1874 * -(((f64) var_f0_1862 * (temp_f2_1874 * temp_f2_1874)) - 3.0);
                            var_f0_1862 = (f32) ((f64) var_f0_1862 * (0.5 * temp_f2_1878 * -(((f64) var_f0_1862 * (temp_f2_1878 * temp_f2_1878)) - 3.0)));
                        } else if (var_f0_1862 < M2C_BITWISE(f32, 0.0)) {
                            var_f0_1862 = __float_nan;
                        } else {
                            sp8 = var_f0_1862;
                            temp_r3_1897 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_1897) { /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1907 = 1;
                                } else {
                                    var_r0_1907 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1907 = 5;
                                } else {
                                    var_r0_1907 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_1907 = 4;
                                break;
                            }
                            if (var_r0_1907 == 1) {
                                var_f0_1862 = __float_nan;
                            }
                        }
                        var_f9_1929 = 1.0f / var_f0_1862;
                    } else {
                        var_f9_1929 = 0.0f;
                        var_f0_1862 = 0.0f;
                    }
                    temp_f2_1954 = (f32) sp180 * var_f9_1929;
                    sp178 = (f32) sp178 * var_f9_1929;
                    temp_f1_1956 = (var_f29_1787 * (temp_f30_1711 * ((3.0f * temp_f28_1512) + var_f0_1862))) + ((750.0f * var_f29_1787) + (2.0f * var_f0_1862 * ((1.0f - temp_f30_1711) / 0.7f)));
                    (*(f32 *) ((u8 *) &sp170 + 0xc)) *= var_f9_1929;
                    sp180 = temp_f2_1954;
                    sp28 = (f64) sp178 * (f64) temp_f1_1956;
                    sp30 = temp_f2_1954 * temp_f1_1956;
                    this->unkF0 = sp28;
                    M2C_FIELD(this, f64 *, 0xF8) = (f64) sp30;
                    spC8 = sp28;
                    spD0 = (f64) sp30;
                    pDribblee = this;
                } else {
                    pDribblee = NULL;
                }
            } else {
                temp_f31_1978 = gUpdateTimeDelta;
                sp98.operator*(std::sqrtf(temp_f1_1547));
                spA8.operator*(5.0f);
                temp_f0_1989 = spA8 * (f64) temp_f31_1978;
                sp18 = temp_f0_1989;
                spB8 = temp_f0_1989;
                sp20 = spA8.unk8 * temp_f31_1978;
                spC0 = (f64) sp20;
                this->unkF0 += temp_f0_1989;
                this->unkF8 += (f32) spC0;
            }
            this->unk2AC |= 0x80;
            this->unk290 = 0;
            return;
        }
        if ((Ball *) pDribblee == this) {
            pDribblee = NULL;
        }
        this->unk2AC |= 4;
    }
}
#endif

void Ball::UpdateShadow() {
    MKCollisionResult sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_2050;
    f64 temp_f0_2074;
    f64 temp_f3_2064;
    f64 temp_f4_2062;
    void *temp_r3_2060;

    temp_r4_2050 = &this->unk70;
    sp8 = temp_r4_2050;
    if (temp_r4_2050 != NULL) {
        spC = this->unk70.unk4;
        this->unk70.unk4 = 0;
    }
    temp_r3_2060 = this->unk8;
    sp20 = 0.0f;
    temp_f4_2062 = M2C_FIELD(temp_r3_2060, f64 *, 0x30);
    sp24 = 1500.0f;
    temp_f3_2064 = M2C_FIELD(temp_r3_2060, f64 *, 0x38);
    sp28 = 0.0f;
    sp30 = (f64) sp20;
    sp40 = temp_f4_2062;
    sp38 = (f64) sp28;
    sp48 = temp_f3_2064;
    temp_f0_2074 = sp40 - sp30;
    sp10 = temp_f0_2074;
    sp60 = temp_f4_2062;
    sp50 = temp_f0_2074;
    sp18 = (f32) sp48 - (f32) sp38;
    sp68 = temp_f3_2064;
    sp58 = (f64) sp18;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp60), *((MKVector3 *) &sp50), &sp70, (MKCollisionMode) 1, 0) != 0) {
        this->unk1A8.unk28 = sp70.unk4;
    }
    if (sp8 != NULL) {
        sp8->unk4 = spC;
    }
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void Ball::UpdateOrientation() {
    Matrix sp130;
    Matrix spF0;
    M2C_UNK spEC;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
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
    f32 sp14;
    f32 sp10;
    f32 temp_f3_2245;
    f32 temp_f5_2252;
    f32 temp_f6_2385;
    f32 temp_f6_2412;
    f32 temp_f7_2247;
    f32 temp_f9_2419;
    f32 var_f1_2207;
    f32 var_f31_2215;
    f32 var_f3_2339;
    f32 var_f4_2135;
    f32 var_f4_2272;
    f64 temp_f1_2138;
    f64 temp_f1_2144;
    f64 temp_f1_2148;
    f64 temp_f1_2278;
    f64 temp_f1_2284;
    f64 temp_f1_2288;
    s32 temp_r3_2167;
    s32 temp_r3_2307;
    s32 var_r0_2177;
    s32 var_r0_2317;

    spD8 = this->unkF0;
    spE0 = M2C_FIELD(this, f64 *, 0xF8);
    (*(f32 *) ((u8 *) &spD8 + 0x4)) = 0.0f;
    var_f4_2135 = ((f32) spE0 * (f32) spE0) + (((f32) spD8 * (f32) spD8) + (0.0f * 0.0f));
    if (var_f4_2135 > 0.0f) {
        temp_f1_2138 = __frsqrte(var_f4_2135);
        temp_f1_2144 = 0.5 * temp_f1_2138 * -(((f64) var_f4_2135 * (temp_f1_2138 * temp_f1_2138)) - 3.0);
        temp_f1_2148 = 0.5 * temp_f1_2144 * -(((f64) var_f4_2135 * (temp_f1_2144 * temp_f1_2144)) - 3.0);
        var_f4_2135 = (f32) ((f64) var_f4_2135 * (0.5 * temp_f1_2148 * -(((f64) var_f4_2135 * (temp_f1_2148 * temp_f1_2148)) - 3.0)));
    } else if (var_f4_2135 < M2C_BITWISE(f32, 0.0)) {
        var_f4_2135 = __float_nan;
    } else {
        sp14 = var_f4_2135;
        temp_r3_2167 = M2C_BITWISE(s32, sp14) & 0x7F800000;
        switch (temp_r3_2167) {                     /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_2177 = 1;
            } else {
                var_r0_2177 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_2177 = 5;
            } else {
                var_r0_2177 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_2177 = 4;
            break;
        }
        if (var_r0_2177 == 1) {
            var_f4_2135 = __float_nan;
        }
    }
    var_f1_2207 = 0.63661975f * (f32) atan2(gUpdateTimeDelta * var_f4_2135, this->unk274 * this->unk280);
    if (var_f1_2207 < 6.2831855f) {

    } else {
        var_f1_2207 = 6.2831855f;
    }
    var_f31_2215 = var_f1_2207;
    if (var_f1_2207 < 0.000001f) {
        var_f31_2215 = 0.0f;
    }
    M2C_STRUCT_COPY((s32) &spF0.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    M2C_STRUCT_COPY((s32) &spEC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f3_2245 = this->unkF8;
    temp_f7_2247 = M2C_FIELD(this, f32 *, 0xF4);
    temp_f5_2252 = (f32) M2C_FIELD(this, f64 *, 0xF0);
    sp58 = (MKVector3::up.unk4 * temp_f3_2245) - (MKVector3::up.unk8 * temp_f7_2247);
    sp5C = (MKVector3::up.unk8 * temp_f5_2252) - (MKVector3::up.unk0 * temp_f3_2245);
    sp60 = (MKVector3::up.unk0 * temp_f7_2247) - (MKVector3::up.unk4 * temp_f5_2252);
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    var_f4_2272 = ((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + ((*(f32 *) ((u8 *) &spB8 + 0x4)) * (*(f32 *) ((u8 *) &spB8 + 0x4))));
    if (var_f4_2272 > 1e-12f) {
        if (var_f4_2272 > 0.0f) {
            temp_f1_2278 = __frsqrte(var_f4_2272);
            temp_f1_2284 = 0.5 * temp_f1_2278 * -(((f64) var_f4_2272 * (temp_f1_2278 * temp_f1_2278)) - 3.0);
            temp_f1_2288 = 0.5 * temp_f1_2284 * -(((f64) var_f4_2272 * (temp_f1_2284 * temp_f1_2284)) - 3.0);
            var_f4_2272 = (f32) ((f64) var_f4_2272 * (0.5 * temp_f1_2288 * -(((f64) var_f4_2272 * (temp_f1_2288 * temp_f1_2288)) - 3.0)));
        } else if (var_f4_2272 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2272 = __float_nan;
        } else {
            sp10 = var_f4_2272;
            temp_r3_2307 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_2307) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2317 = 1;
                } else {
                    var_r0_2317 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2317 = 5;
                } else {
                    var_r0_2317 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_2317 = 4;
                break;
            }
            if (var_r0_2317 == 1) {
                var_f4_2272 = __float_nan;
            }
        }
        var_f3_2339 = 1.0f / var_f4_2272;
    } else {
        var_f3_2339 = 0.0f;
    }
    sp4C = (*(f32 *) ((u8 *) &spB8 + 0x4)) * var_f3_2339;
    sp48 = (f32) spB8 * var_f3_2339;
    sp50 = (f32) spC0 * var_f3_2339;
    spC8 = (f64) sp48;
    spD0 = (f64) sp50;
    spF0.SetRotateAroundAxis(*((MKVector3 *) &spC8), var_f31_2215);
    sp130.Multiply3x3(&sp130, &spF0);
    sp40 = (sp130.unk10 * sp130.unk24) - (sp130.unk14 * sp130.unk20);
    sp3C = (sp130.unk18 * sp130.unk20) - (sp130.unk10 * sp130.unk28);
    sp38 = (sp130.unk14 * sp130.unk28) - (sp130.unk18 * sp130.unk24);
    spA0 = (f64) sp40;
    sp98 = (f64) sp38;
    spA8 = Normalise(*((MKVector3 *) &sp98));
    temp_f6_2385 = M2C_BITWISE(f32, spA8);
    sp130 = temp_f6_2385;
    sp130.unk4 = spA8.unk4;
    sp30 = (sp130.unk20 * spA8.unk4) - (sp130.unk24 * temp_f6_2385);
    sp28 = (sp130.unk24 * spA8.unk8) - (sp130.unk28 * spA8.unk4);
    sp2C = (sp130.unk28 * temp_f6_2385) - (sp130.unk20 * spA8.unk8);
    sp130.unk8 = spA8.unk8;
    sp130.unkC = 0.0f;
    sp78 = (f64) sp28;
    sp80 = (f64) sp30;
    sp88 = Normalise(*((MKVector3 *) &sp78));
    temp_f6_2412 = M2C_BITWISE(f32, sp88);
    temp_f9_2419 = M2C_BITWISE(f32, sp130);
    sp130.unk10 = temp_f6_2412;
    sp130.unk14 = sp88.unk4;
    sp20 = (temp_f9_2419 * sp88.unk4) - (sp130.unk4 * temp_f6_2412);
    sp18 = (sp130.unk4 * sp88.unk8) - (sp130.unk8 * sp88.unk4);
    sp1C = (sp130.unk8 * temp_f6_2412) - (temp_f9_2419 * sp88.unk8);
    sp70 = (f64) sp20;
    sp68 = (f64) sp18;
    sp130.unk18 = sp88.unk8;
    sp130.unk1C = 0.0f;
    sp130.unk20 = (f32) sp68;
    sp130.unk24 = (*(f32 *) ((u8 *) &sp68 + 0x4));
    sp130.unk28 = (f32) sp70;
    sp130.unk2C = 0.0f;
    sp130.Scale3x3(&sp130, this->unk280);
    MKModel_SetWorldMatrix(this->unk4, sp130);
    MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unkE0));
}
#endif

#if 0 // DRAFT: ')' expected
void Ball::UpdateMeltingGrowing() {
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
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
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r29_2502;
    f32 temp_f1_2536;
    f32 temp_f2_2479;
    f32 temp_f30_2520;
    f32 temp_f31_2522;
    f32 var_f3_2611;
    f32 var_f4_2544;
    f64 temp_f0_2630;
    f64 temp_f0_2640;
    f64 temp_f1_2550;
    f64 temp_f1_2556;
    f64 temp_f1_2560;
    s32 temp_r3_2579;
    s32 var_r0_2589;
    void *temp_r31_2480;

    temp_f2_2479 = this->unk284;
    temp_r31_2480 = checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (temp_f2_2479 > 0.0f) {
        this->unk284 = temp_f2_2479 - gUpdateTimeDelta;
        if (this->unk284 < 0.0f) {
            this->unk284 = 0.0f;
            return;
        }
        if (((s32) M2C_FIELD(temp_r31_2480, s32 *, 0xE8) != 0) && (KDSound_IsVoicePlaying(this->unk294) == 0)) {
            temp_r29_2502 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
            this->unk294 = KDSound_Play3d(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8), temp_r29_2502, 0U, -1, 0.0f, 0U);
        }
        spA0 = -1.0f;
        temp_f30_2520 = this->unk280;
        sp90 = 1.0f;
        temp_f31_2522 = this->unk274;
        sp98 = -1.0f;
        sp9C = 0.0f;
        sp88 = 1.0f;
        sp8C = 0.0f;
        spE8 = (f64) sp98;
        spF0 = (f64) spA0;
        spD8 = (f64) sp88;
        spE0 = (f64) sp90;
        spF8 = KDRand_Vector(*((MKVector3 *) &spE8), *((MKVector3 *) &spD8));
        temp_f1_2536 = M2C_BITWISE(f32, spF8);
        var_f4_2544 = (spF8.unk8 * spF8.unk8) + ((temp_f1_2536 * temp_f1_2536) + (spF8.unk4 * spF8.unk4));
        if (var_f4_2544 > 1e-12f) {
            if (var_f4_2544 > 0.0f) {
                temp_f1_2550 = __frsqrte(var_f4_2544);
                temp_f1_2556 = 0.5 * temp_f1_2550 * -(((f64) var_f4_2544 * (temp_f1_2550 * temp_f1_2550)) - 3.0);
                temp_f1_2560 = 0.5 * temp_f1_2556 * -(((f64) var_f4_2544 * (temp_f1_2556 * temp_f1_2556)) - 3.0);
                var_f4_2544 = (f32) ((f64) var_f4_2544 * (0.5 * temp_f1_2560 * -(((f64) var_f4_2544 * (temp_f1_2560 * temp_f1_2560)) - 3.0)));
            } else if (var_f4_2544 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2544 = __float_nan;
            } else {
                sp8 = var_f4_2544;
                temp_r3_2579 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2579) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2589 = 1;
                    } else {
                        var_r0_2589 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2589 = 5;
                    } else {
                        var_r0_2589 = 3;
                    }
                    break;
                default:
                    var_r0_2589 = 4;
                    break;
                }
                if (var_r0_2589 == 1) {
                    var_f4_2544 = __float_nan;
                }
            }
            var_f3_2611 = 1.0f / var_f4_2544;
        } else {
            var_f3_2611 = 0.0f;
        }
        sp38 = M2C_BITWISE(f32, spF8) * var_f3_2611;
        sp3C = spF8.unk4 * var_f3_2611;
        sp40 = spF8.unk8 * var_f3_2611;
        sp108 = (f64) sp38;
        sp110 = (f64) sp40;
        temp_f0_2630 = sp108 * (f64) temp_f31_2522;
        sp78 = temp_f0_2630;
        sp118 = temp_f0_2630;
        sp80 = (f32) sp110 * temp_f31_2522;
        sp120 = (f64) sp80;
        temp_f0_2640 = temp_f0_2630 * (f64) temp_f30_2520;
        sp68 = temp_f0_2640;
        sp128 = temp_f0_2640;
        sp70 = (f32) sp120 * temp_f30_2520;
        sp130 = (f64) sp70;
        sp58 = this->unkE0 + temp_f0_2640;
        sp60 = this->unkE8 + (f32) sp130;
        sp50 = -MKVector3::up.unk8;
        sp48 = -MKVector3::up.unk0;
        sp4C = -MKVector3::up.unk4;
        sp138 = sp58;
        sp140 = (f64) sp60;
        spC8 = (f64) sp48;
        spD0 = (f64) sp50;
        sp10 = 3.0f * this->unk280;
        ((WaterDripPS *) gb.unk6C)->Emit(*((MKVector3 *) &sp138), *((MKVector3 *) &spC8), sp10, 0U, 1U, NULL);
        sp28 = (f64) M2C_FIELD(&MKVector3::up, f32 *, 0) * 5.56078426e-315;
        spB8 = sp28;
        sp30 = MKVector3::up.unk8 * 150.0f;
        sp18 = 1.0f;
        spC0 = (f64) sp30;
        sp1C = 1.0f;
        sp20 = 1.0f;
        sp24 = 1.0f;
        spC = 10.0f * this->unk280;
        spA8 = (f64) sp18;
        spB0 = (f64) sp20;
        ((CrashMistPS *) (M2C_FIELD(temp_r31_2480, CrashMistPS **, 0x120)))->Emit(*((MKVector3 *) &this->unkE0), *((MKVector3 *) &spB8), spC, 1.0f, *((MKVector4 *) &spA8), 0.4f);
    }
}
#endif

#if 0 // DRAFT: function call 'Tools_PushOut(MKCollisionResult *, MKVector3, long, float, unsigned char *, float)' does not match 'Tools_PushOut(MKCollisionResult *, MKVector3 
void Ball::PushOutOfThings() {
    MKCollisionResult sp30;
    u8 sp10;
    u8 spC;
    void *sp8;
    f32 temp_f31_2758;
    s32 temp_r3_2813;
    s32 var_ctr_2761;
    s32 var_r4_2757;
    u8 *var_r3_2755;
    void *temp_r3_2798;
    void *temp_r6_2765;

    if ((s32) this->unk270 != 1) {
        var_r3_2755 = &sp10;
        var_r4_2757 = 0;
        temp_f31_2758 = this->unk274 * this->unk280;
        var_ctr_2761 = 0x1E;
        do {
            temp_r6_2765 = &sp30 + var_r4_2757;
            *var_r3_2755 = 0;
            var_r3_2755 += 1;
            M2C_FIELD(temp_r6_2765, f32 *, 0) = 0.0f;
            var_r4_2757 += 0x58;
            M2C_FIELD(temp_r6_2765, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 8) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x14) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x18) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x30) = 0.0f;
            M2C_FIELD(temp_r6_2765, f32 *, 0x34) = 0.0f;
            M2C_FIELD(temp_r6_2765, s16 *, 0x38) = 0;
            M2C_FIELD(temp_r6_2765, s8 *, 0x3A) = 0;
            M2C_FIELD(temp_r6_2765, s8 *, 0x3B) = 0;
            M2C_FIELD(temp_r6_2765, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_r6_2765, f32 *, 0x40) = 3.4028235e38f;
            M2C_FIELD(temp_r6_2765, s32 *, 0x44) = 0;
            M2C_FIELD(temp_r6_2765, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r6_2765, s32 *, 0x4C) = -1;
            M2C_FIELD(temp_r6_2765, s8 *, 0x50) = 0;
            var_ctr_2761 -= 1;
        } while (var_ctr_2761 != 0);
        temp_r3_2798 = gb.unk0->GetCollisionInfo();
        sp8 = temp_r3_2798;
        if (temp_r3_2798 != NULL) {
            spC = M2C_FIELD(temp_r3_2798, u8 *, 4);
            M2C_FIELD(temp_r3_2798, u8 *, 4) = 0U;
        }
        temp_r3_2813 = MKCollision_SphereCollide(*((MKVector3 *) &this->unkE0), temp_f31_2758, &sp30, 0xA, (MKCollisionMode) 7, 0);
        if (temp_r3_2813 == 0) {
            if (sp8 != NULL) {
                M2C_FIELD(sp8, u8 *, 4) = spC;
            }
        } else {
            Tools_UpdateSphereCollideResults(&sp30, temp_r3_2813, *((MKVector3 *) &this->unkE0));
            Tools_PushOut(&sp30, *((MKVector3 *) &this->unkE0), temp_r3_2813, this->unk274 * this->unk280, &sp10, temp_f31_2758 / (0.0009999999f + temp_f31_2758));
            if (sp8 != NULL) {
                M2C_FIELD(sp8, u8 *, 4) = spC;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'double'
void Ball::UpdatePhysics() {
    u8 sp540;
    s32 sp53C;
    void *sp538;
    u32 sp534;
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
    s8 sp4E8;
    s32 sp4E4;
    s32 sp4E0;
    s32 sp4DC;
    f32 sp4D8;
    s32 sp4D4;
    s8 sp4D3;
    s8 sp4D2;
    s16 sp4D0;
    f32 sp4CC;
    f32 sp4C8;
    f32 sp4C4;
    f32 sp4C0;
    f32 sp4BC;
    f32 sp4B8;
    f32 sp4B0;
    f32 sp4AC;
    f32 sp4A8;
    f32 sp4A0;
    f32 sp49C;
    f32 sp498;
    M2C_UNK *sp494;
    s32 sp490;
    s8 sp48C;
    s32 sp488;
    s32 sp484;
    s8 sp480;
    f32 sp478;
    f32 sp474;
    f32 sp470;
    s32 sp46C;
    s32 sp468;
    f64 sp460;                                      /* compiler-managed */
    f64 sp458;
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
    MKVector3 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    MKVector3 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp368;
    MKVector3 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    MKVector3 sp328;
    MKVector3 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    MKVector3 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    MKVector3 sp2A8;
    f64 sp2A0;
    f64 sp298;
    MKVector3 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    MKVector3 sp258;
    MKVector3 sp248;
    MKVector3 sp238;
    MKVector3 sp228;
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
    MKVector3 sp1B8;
    f32 sp1B0;
    f64 sp1A8;
    f32 sp1A0;
    f64 sp198;
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
    f64 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
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
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    u8 sp24;
    MKCollisionInfo *sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    u8 sp8;
    Catapult *var_r28_2883;
    MKCollisionInfo *temp_r4_2884;
    MKProp *temp_r24_3004;
    MKProp *var_r23_3654;
    MKProp *var_r30_3681;
    f32 temp_f0_3726;
    f32 temp_f0_3984;
    f32 temp_f1_3190;
    f32 temp_f1_3724;
    f32 temp_f1_3733;
    f32 temp_f1_3906;
    f32 temp_f1_3983;
    f32 temp_f1_4165;
    f32 temp_f21_3464;
    f32 temp_f22_3294;
    f32 temp_f24_3824;
    f32 temp_f26_3488;
    f32 temp_f28_3320;
    f32 temp_f29_3044;
    f32 temp_f2_3189;
    f32 temp_f2_3905;
    f32 temp_f30_2928;
    f32 temp_f3_3191;
    f32 temp_f3_3348;
    f32 temp_f3_3518;
    f32 temp_f3_3728;
    f32 temp_f3_3823;
    f32 temp_f3_3908;
    f32 temp_f5_4077;
    f32 temp_f6_4076;
    f32 temp_f7_4079;
    f32 temp_f8_3991;
    f32 var_f0_2972;
    f32 var_f0_4071;
    f32 var_f2_3263;
    f32 var_f2_3433;
    f32 var_f3_3118;
    f32 var_f4_3048;
    f32 var_f4_3196;
    f32 var_f4_3366;
    f32 var_f4_3912;
    f32 var_f4_4000;
    f32 var_f7_3978;
    f64 *temp_r3_4314;
    f64 temp_f0_2933;
    f64 temp_f0_2987;
    f64 temp_f0_3024;
    f64 temp_f0_3298;
    f64 temp_f0_3468;
    f64 temp_f0_3794;
    f64 temp_f0_4260;
    f64 temp_f0_4322;
    f64 temp_f0_4333;
    f64 temp_f0_4343;
    f64 temp_f1_3015;
    f64 temp_f1_3057;
    f64 temp_f1_3063;
    f64 temp_f1_3067;
    f64 temp_f1_3202;
    f64 temp_f1_3208;
    f64 temp_f1_3212;
    f64 temp_f1_3372;
    f64 temp_f1_3378;
    f64 temp_f1_3382;
    f64 temp_f1_3918;
    f64 temp_f1_3924;
    f64 temp_f1_3928;
    f64 temp_f1_4010;
    f64 temp_f1_4016;
    f64 temp_f1_4020;
    f64 temp_f1_4118;
    f64 temp_f1_4259;
    f64 temp_f2_4316;
    f64 temp_f3_4321;
    s32 temp_r3_3086;
    s32 temp_r3_3231;
    s32 temp_r3_3401;
    s32 temp_r3_3947;
    s32 temp_r3_4039;
    s32 var_r0_3096;
    s32 var_r0_3241;
    s32 var_r0_3411;
    s32 var_r0_3725;
    s32 var_r0_4049;
    s32 var_r23_2991;
    s32 var_r29_2989;
    s32 var_r29_3552;
    s32 var_r4_3902;
    u8 temp_r3_2951;
    u8 temp_r3_3609;
    u8 temp_r3_4081;
    u8 var_r23_4127;
    u8 var_r25_2981;
    u8 var_r26_2980;
    u8 var_r27_2885;
    void *temp_r3_3013;
    void *temp_r3_4117;
    void *temp_r3_4257;
    void *temp_r4_3012;
    void *temp_r9_4302;

    var_r28_2883 = this->unk228;
    temp_r4_2884 = &this->unk70;
    var_r27_2885 = 0;
    sp20 = temp_r4_2884;
    if (temp_r4_2884 != NULL) {
        sp24 = this->unk70.unk4;
        this->unk70.unk4 = 0;
    }
    if (var_r28_2883 != NULL) {
        if ((u8) var_r28_2883->unk70.unk4 != 0) {
            var_r28_2883->unk70.unk4 = 0;
        } else {
            var_r28_2883 = NULL;
        }
    }
    spE8 = this->unk100 * (f64) gUpdateTimeDelta;
    sp3D8 = spE8;
    spF0 = this->unk108 * gUpdateTimeDelta;
    sp3E0 = (f64) spF0;
    this->unkF0 += spE8;
    this->unkF8 += (f32) sp3E0;
    temp_f30_2928 = gUpdateTimeDelta;
    sp3B8.operator*(this->unk278);
    temp_f0_2933 = sp3B8 * (f64) temp_f30_2928;
    spD8 = temp_f0_2933;
    sp3C8 = temp_f0_2933;
    spE0 = sp3B8.unk8 * temp_f30_2928;
    sp3D0 = (f64) spE0;
    this->unkF0 -= temp_f0_2933;
    this->unkF8 -= (f32) sp3D0;
    temp_r3_2951 = this->unk2AC;
    if ((temp_r3_2951 >> 4U) & 1) {
        this->unk2AC = temp_r3_2951 & ~0x10;
        this->unkF0 *= 5.222099017e-315;
        this->unkF8 *= 0.5f;
    }
    if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124) == 1) {
        var_f0_2972 = 4.0f;
    } else {
        var_f0_2972 = 1.0f;
    }
    var_r26_2980 = 0;
    var_r25_2981 = 0;
    M2C_FIELD(this, f32 *, 0xF4) = (f32) ((gUpdateTimeDelta * (-1960.0f * var_f0_2972)) + M2C_FIELD(this, f32 *, 0xF4));
    temp_f0_2987 = this->unkF0 * (f64) gUpdateTimeDelta;
    sp1A8 = temp_f0_2987;
    var_r29_2989 = 0;
    var_r23_2991 = 0;
    sp458 = temp_f0_2987;
    sp1B0 = this->unkF8 * gUpdateTimeDelta;
    sp460 = (f64) sp1B0;
    do {
        temp_r24_3004 = *(&groups[this->unk2A8] + var_r23_2991);
        if ((temp_r24_3004 != this) && (temp_r24_3004 != NULL) && ((s32) M2C_FIELD(temp_r24_3004, s32 *, 0x270) != 5)) {
            temp_r4_3012 = temp_r24_3004->unk8;
            temp_r3_3013 = this->unk8;
            temp_f1_3015 = M2C_FIELD(temp_r3_3013, f64 *, 0x30);
            sp398 = M2C_FIELD(temp_r4_3012, f64 *, 0x30);
            sp3A8 = temp_f1_3015;
            sp3A0 = M2C_FIELD(temp_r4_3012, f64 *, 0x38);
            sp3B0 = M2C_FIELD(temp_r3_3013, f64 *, 0x38);
            temp_f0_3024 = temp_f1_3015 - sp398;
            sp198 = temp_f0_3024;
            sp448 = temp_f0_3024;
            sp1A0 = (f32) sp3B0 - (f32) sp3A0;
            sp450 = (f64) sp1A0;
            temp_f29_3044 = (M2C_FIELD(temp_r24_3004, f32 *, 0x274) * M2C_FIELD(temp_r24_3004, f32 *, 0x280)) + (this->unk274 * this->unk280);
            var_f4_3048 = ((f32) sp450 * (f32) sp450) + (((f32) sp448 * (f32) sp448) + ((*(f32 *) ((u8 *) &sp448 + 0x4)) * (*(f32 *) ((u8 *) &sp448 + 0x4))));
            if (var_f4_3048 < (temp_f29_3044 * temp_f29_3044)) {
                if (var_f4_3048 > 1e-12f) {
                    if (var_f4_3048 > 0.0f) {
                        temp_f1_3057 = __frsqrte(var_f4_3048);
                        temp_f1_3063 = 0.5 * temp_f1_3057 * -(((f64) var_f4_3048 * (temp_f1_3057 * temp_f1_3057)) - 3.0);
                        temp_f1_3067 = 0.5 * temp_f1_3063 * -(((f64) var_f4_3048 * (temp_f1_3063 * temp_f1_3063)) - 3.0);
                        var_f4_3048 = (f32) ((f64) var_f4_3048 * (0.5 * temp_f1_3067 * -(((f64) var_f4_3048 * (temp_f1_3067 * temp_f1_3067)) - 3.0)));
                    } else if (var_f4_3048 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3048 = __float_nan;
                    } else {
                        sp1C = var_f4_3048;
                        temp_r3_3086 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                        switch (temp_r3_3086) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                var_r0_3096 = 1;
                            } else {
                                var_r0_3096 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                                var_r0_3096 = 5;
                            } else {
                                var_r0_3096 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_3096 = 4;
                            break;
                        }
                        if (var_r0_3096 == 1) {
                            var_f4_3048 = __float_nan;
                        }
                    }
                    var_f3_3118 = 1.0f / var_f4_3048;
                } else {
                    var_f3_3118 = 0.0f;
                }
                sp188 = (f32) sp448 * var_f3_3118;
                sp18C = (*(f32 *) ((u8 *) &sp448 + 0x4)) * var_f3_3118;
                sp190 = (f32) sp450 * var_f3_3118;
                sp438 = (f64) sp188;
                sp440 = (f64) sp190;
                sp178 = -(f32) sp438;
                sp17C = -(*(f32 *) ((u8 *) &sp438 + 0x4));
                sp180 = -(f32) sp440;
                sp428 = (f64) sp178;
                sp430 = (f64) sp180;
                sp388 = NProjection(*((MKVector3 *) &sp458), *((MKVector3 *) &sp438));
                sp458 -= M2C_BITWISE(f64, sp388);
                sp460 = (f32) sp460 - sp388.unk8;
                sp358.operator*(0.1f + temp_f29_3044);
                ((MKProp *) &sp368)->GetPos();
                spC8 = sp368 + M2C_BITWISE(f64, sp358);
                this->unkE0 = spC8;
                spD0 = sp370 + sp358.unk8;
                sp378 = spC8;
                M2C_FIELD(this, f64 *, 0xE8) = (f64) spD0;
                sp380 = (f64) spD0;
                sp418 = M2C_FIELD(temp_r24_3004, f64 *, 0xF0);
                sp420 = M2C_FIELD(temp_r24_3004, f64 *, 0xF8);
                temp_f2_3189 = (f32) M2C_FIELD(this, f64 *, 0xF0);
                temp_f1_3190 = M2C_FIELD(this, f32 *, 0xF4);
                temp_f3_3191 = this->unkF8;
                var_f4_3196 = (temp_f3_3191 * temp_f3_3191) + ((temp_f2_3189 * temp_f2_3189) + (temp_f1_3190 * temp_f1_3190));
                if (var_f4_3196 > 1e-12f) {
                    if (var_f4_3196 > 0.0f) {
                        temp_f1_3202 = __frsqrte(var_f4_3196);
                        temp_f1_3208 = 0.5 * temp_f1_3202 * -(((f64) var_f4_3196 * (temp_f1_3202 * temp_f1_3202)) - 3.0);
                        temp_f1_3212 = 0.5 * temp_f1_3208 * -(((f64) var_f4_3196 * (temp_f1_3208 * temp_f1_3208)) - 3.0);
                        var_f4_3196 = (f32) ((f64) var_f4_3196 * (0.5 * temp_f1_3212 * -(((f64) var_f4_3196 * (temp_f1_3212 * temp_f1_3212)) - 3.0)));
                    } else if (var_f4_3196 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3196 = __float_nan;
                    } else {
                        sp18 = var_f4_3196;
                        temp_r3_3231 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_3231) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_3241 = 1;
                            } else {
                                var_r0_3241 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_3241 = 5;
                            } else {
                                var_r0_3241 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_3241 = 4;
                            break;
                        }
                        if (var_r0_3241 == 1) {
                            var_f4_3196 = __float_nan;
                        }
                    }
                    var_f2_3263 = 1.0f / var_f4_3196;
                } else {
                    var_f2_3263 = 0.0f;
                }
                sp168 = (f32) M2C_FIELD(this, f64 *, 0xF0) * var_f2_3263;
                sp16C = M2C_FIELD(this, f32 *, 0xF4) * var_f2_3263;
                sp170 = this->unkF8 * var_f2_3263;
                sp348 = (f64) sp168;
                sp350 = (f64) sp170;
                temp_f22_3294 = 0.8f * (((f32) sp350 * (f32) sp430) + (((f32) sp348 * (f32) sp428) + ((*(f32 *) ((u8 *) &sp348 + 0x4)) * (*(f32 *) ((u8 *) &sp428 + 0x4)))));
                sp328 = NProjection(*((MKVector3 *) &this->unkF0), *((MKVector3 *) &sp438));
                temp_f0_3298 = sp328 * (f64) temp_f22_3294;
                spB8 = temp_f0_3298;
                sp338 = temp_f0_3298;
                spC0 = sp328.unk8 * temp_f22_3294;
                sp340 = (f64) spC0;
                M2C_FIELD(temp_r24_3004, f64 *, 0xF0) = (f64) (M2C_FIELD(temp_r24_3004, f64 *, 0xF0) + temp_f0_3298);
                M2C_FIELD(temp_r24_3004, f64 *, 0xF8) = (f32) ((f32) M2C_FIELD(temp_r24_3004, f64 *, 0xF8) + (f32) sp340);
                temp_f28_3320 = 1.0f + this->unk27C;
                spA8 = sp438 * (f64) temp_f28_3320;
                spB0 = (f32) sp440 * temp_f28_3320;
                sp308 = spA8;
                sp310 = (f64) spB0;
                sp318 = __ml((this->unkF8 * (f32) sp440) + (((f32) M2C_FIELD(this, f64 *, 0xF0) * (f32) sp438) + (M2C_FIELD(this, f32 *, 0xF4) * (*(f32 *) ((u8 *) &sp438 + 0x4)))), *((MKVector3 *) &sp308));
                this->unkF0 -= M2C_BITWISE(f64, sp318);
                temp_f3_3348 = 1.0f - temp_f22_3294;
                this->unkF8 -= sp318.unk8;
                this->unkF0 *= (f64) temp_f3_3348;
                this->unkF8 *= temp_f3_3348;
                var_f4_3366 = ((f32) sp420 * (f32) sp420) + (((f32) sp418 * (f32) sp418) + ((*(f32 *) ((u8 *) &sp418 + 0x4)) * (*(f32 *) ((u8 *) &sp418 + 0x4))));
                if (var_f4_3366 > 1e-12f) {
                    if (var_f4_3366 > 0.0f) {
                        temp_f1_3372 = __frsqrte(var_f4_3366);
                        temp_f1_3378 = 0.5 * temp_f1_3372 * -(((f64) var_f4_3366 * (temp_f1_3372 * temp_f1_3372)) - 3.0);
                        temp_f1_3382 = 0.5 * temp_f1_3378 * -(((f64) var_f4_3366 * (temp_f1_3378 * temp_f1_3378)) - 3.0);
                        var_f4_3366 = (f32) ((f64) var_f4_3366 * (0.5 * temp_f1_3382 * -(((f64) var_f4_3366 * (temp_f1_3382 * temp_f1_3382)) - 3.0)));
                    } else if (var_f4_3366 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_3366 = __float_nan;
                    } else {
                        sp14 = var_f4_3366;
                        temp_r3_3401 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_3401) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_3411 = 1;
                            } else {
                                var_r0_3411 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_3411 = 5;
                            } else {
                                var_r0_3411 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_3411 = 4;
                            break;
                        }
                        if (var_r0_3411 == 1) {
                            var_f4_3366 = __float_nan;
                        }
                    }
                    var_f2_3433 = 1.0f / var_f4_3366;
                } else {
                    var_f2_3433 = 0.0f;
                }
                sp158 = (f32) sp418 * var_f2_3433;
                sp15C = (*(f32 *) ((u8 *) &sp418 + 0x4)) * var_f2_3433;
                sp160 = (f32) sp420 * var_f2_3433;
                sp2F8 = (f64) sp158;
                sp300 = (f64) sp160;
                temp_f21_3464 = 0.8f * (((f32) sp300 * (f32) sp440) + (((f32) sp2F8 * (f32) sp438) + ((*(f32 *) ((u8 *) &sp2F8 + 0x4)) * (*(f32 *) ((u8 *) &sp438 + 0x4)))));
                sp2D8 = NProjection(*((MKVector3 *) &sp418), *((MKVector3 *) &sp428));
                temp_f0_3468 = sp2D8 * (f64) temp_f21_3464;
                sp98 = temp_f0_3468;
                sp2E8 = temp_f0_3468;
                spA0 = sp2D8.unk8 * temp_f21_3464;
                sp2F0 = (f64) spA0;
                this->unkF0 += temp_f0_3468;
                this->unkF8 += (f32) sp2F0;
                temp_f26_3488 = 1.0f + M2C_FIELD(temp_r24_3004, f32 *, 0x27C);
                sp88 = sp428 * (f64) temp_f26_3488;
                sp90 = (f32) sp430 * temp_f26_3488;
                sp2B8 = sp88;
                sp2C0 = (f64) sp90;
                sp2C8 = __ml(((f32) sp420 * (f32) sp430) + (((f32) sp418 * (f32) sp428) + ((*(f32 *) ((u8 *) &sp418 + 0x4)) * (*(f32 *) ((u8 *) &sp428 + 0x4)))), *((MKVector3 *) &sp2B8));
                M2C_FIELD(temp_r24_3004, f64 *, 0xF0) = (f64) (M2C_FIELD(temp_r24_3004, f64 *, 0xF0) - M2C_BITWISE(f64, sp2C8));
                temp_f3_3518 = 1.0f - temp_f21_3464;
                M2C_FIELD(temp_r24_3004, f64 *, 0xF8) = (f32) ((f32) M2C_FIELD(temp_r24_3004, f64 *, 0xF8) - sp2C8.unk8);
                M2C_FIELD(temp_r24_3004, f64 *, 0xF0) = (f64) (M2C_FIELD(temp_r24_3004, f64 *, 0xF0) * (f64) temp_f3_3518);
                M2C_FIELD(temp_r24_3004, f64 *, 0xF8) = (f32) ((f32) M2C_FIELD(temp_r24_3004, f64 *, 0xF8) * temp_f3_3518);
                M2C_FIELD(temp_r24_3004, u8 *, 0x2AC) = (u8) (M2C_FIELD(temp_r24_3004, u8 *, 0x2AC) | 0x80);
                if ((s32) this->unk270 == 2) {
                    SmashHit(temp_r24_3004);
                }
            }
        }
        var_r29_2989 += 1;
        var_r23_2991 += 4;
    } while (var_r29_2989 < 0xA);
    this->unk2A4 = 0;
    var_r29_3552 = 0;
    M2C_FIELD(gb.unk0->GetCollisionInfo(), s8 *, 4) = 0;
loop_80:
    if ((s32) this->unk270 != 1) {
        sp408 = this->unkE0;
        sp410 = M2C_FIELD(this, f64 *, 0xE8);
        sp148 = this->unkE0 + sp458;
        sp150 = this->unkE8 + sp460;
        sp3F8 = sp148;
        sp400 = (f64) sp150;
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
        sp538 = NULL;
        sp53C = -1;
        sp540 = 0;
        temp_r3_3609 = MKCollision_SweepSphereCollide(*((MKVector3 *) &sp408), *((MKVector3 *) &sp3F8), this->unk274 * this->unk280, (MKCollisionResult *) &sp4F0, (MKCollisionMode) 7, 0);
        var_r25_2981 = temp_r3_3609;
        if (temp_r3_3609 != 0) {
            sp8 = 1;
            if ((s32) this->unk270 == 2) {
                this->unk150 = (f64) sp4F0;
                this->unk158 = (f64) sp4F8;
                this->unk160 = (f64) sp500;
                this->unk168 = (f64) sp508;
                this->unk170 = (f64) sp510;
                this->unk178 = (f64) sp518;
                this->unk180 = sp520;
                this->unk184 = sp524;
                this->unk188 = (s32) sp528;
                this->unk18C = sp52C;
                this->unk190 = sp530;
                this->unk194 = sp534;
                this->unk198 = sp538;
                this->unk19C = sp53C;
                this->unk1A0 = sp540;
                if ((sp540 != 0) && (sp538 != NULL) && (var_r23_3654 = M2C_FIELD(sp538, MKProp **, 8), ((var_r23_3654 == NULL) == 0))) {

                } else {
                    var_r23_3654 = NULL;
                }
                if (var_r23_3654 != NULL) {
                    var_r27_2885 = MeleeHit(var_r23_3654, 1.0f, sp8);
                }
                SmashHit(var_r23_3654);
            } else {
                if ((sp540 != 0) && (sp538 != NULL) && (var_r30_3681 = M2C_FIELD(sp538, MKProp **, 8), ((var_r30_3681 == NULL) == 0))) {

                } else {
                    var_r30_3681 = NULL;
                }
                if (var_r30_3681 != NULL) {
                    if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124) == 1) {
                        sp494 = &__vt;
                        sp468 = 0x30;
                        sp46C = 0;
                        sp494 = &__vt;
                        sp470 = 0.0f;
                        sp474 = 0.0f;
                        sp478 = 0.0f;
                        sp480 = 0;
                        sp484 = -1;
                        sp488 = 0;
                        sp48C = 0;
                        sp490 = 0;
                        sp468 = 0x31;
                        var_r30_3681->Message(&sp468, -1, &__vt, 0);
                    }
                    temp_f1_3724 = (f32) M2C_FIELD(this, f64 *, 0xF0);
                    var_r0_3725 = 0;
                    temp_f0_3726 = M2C_FIELD(this, f32 *, 0xF4);
                    temp_f3_3728 = this->unkF8;
                    temp_f1_3733 = (temp_f3_3728 * temp_f3_3728) + ((temp_f1_3724 * temp_f1_3724) + (temp_f0_3726 * temp_f0_3726));
                    if (temp_f1_3733 >= 4000000.0f) {
                        var_r0_3725 = 3;
                    } else if (temp_f1_3733 >= 562500.0f) {
                        var_r0_3725 = 1;
                    }
                    if (var_r0_3725 != 0) {
                        var_r27_2885 = MeleeHit(var_r30_3681, (f32) var_r0_3725, sp8);
                    }
                }
                this->unk150 = (f64) sp4F0;
                this->unk158 = (f64) sp4F8;
                this->unk160 = (f64) sp500;
                this->unk168 = (f64) sp508;
                this->unk170 = (f64) sp510;
                this->unk178 = (f64) sp518;
                this->unk180 = sp520;
                this->unk184 = sp524;
                this->unk188 = (s32) sp528;
                this->unk18C = sp52C;
                this->unk190 = sp530;
                this->unk194 = sp534;
                this->unk198 = sp538;
                this->unk19C = sp53C;
                this->unk1A0 = sp540;
                temp_f0_3794 = this->unkE0 - (f64) sp4F0;
                sp78 = temp_f0_3794;
                sp298 = temp_f0_3794;
                sp80 = this->unkE8 - sp4F8;
                sp2A0 = (f64) sp80;
                sp2A8 = Normalise(*((MKVector3 *) &sp298));
                *(MKVector3 *) &this->unk110 = sp2A8;
                this->unk2A4 = sp534;
                temp_f3_3823 = (f32) M2C_FIELD(this, f64 *, 0x118);
                temp_f24_3824 = 1.0f + this->unk27C;
                sp68 = this->unk110 * (f64) temp_f24_3824;
                sp70 = temp_f3_3823 * temp_f24_3824;
                sp278 = sp68;
                sp280 = (f64) sp70;
                sp288 = __ml((this->unkF8 * temp_f3_3823) + (((f32) M2C_FIELD(this, f64 *, 0xF0) * (f32) M2C_FIELD(this, f64 *, 0x110)) + (M2C_FIELD(this, f32 *, 0xF4) * M2C_FIELD(this, f32 *, 0x114))), *((MKVector3 *) &sp278));
                this->unkF0 -= M2C_BITWISE(f64, sp288);
                this->unkF8 -= sp288.unk8;
                sp238.operator*(this->unk274);
                sp248.operator*(this->unk280);
                sp258.operator*(1.01f);
                sp58 = (f64) sp4F0 + M2C_BITWISE(f64, sp258);
                this->unkE0 = sp58;
                sp60 = sp4F8 + sp258.unk8;
                sp268 = sp58;
                sp270 = (f64) sp60;
                M2C_FIELD(this, f64 *, 0xE8) = (f64) sp60;
                sp228 = NProjection(*((MKVector3 *) &sp458), *((MKVector3 *) &this->unk110));
                sp458 -= M2C_BITWISE(f64, sp228);
                sp460 -= sp228.unk8;
                goto block_107;
            }
        } else {
            this->unk1A0 = 0;
        }
    } else {
block_107:
        var_r29_3552 += 1;
        if (var_r29_3552 < 3) {
            goto loop_80;
        }
    }
    var_r4_3902 = 1;
    M2C_FIELD(gb.unk0->GetCollisionInfo(), s8 *, 4) = 1;
    temp_f2_3905 = this->unk120;
    temp_f1_3906 = this->unk124;
    temp_f3_3908 = this->unk128;
    var_f4_3912 = (temp_f3_3908 * temp_f3_3908) + ((temp_f2_3905 * temp_f2_3905) + (temp_f1_3906 * temp_f1_3906));
    if (var_f4_3912 > 1e-12f) {
        if (var_f4_3912 > 0.0f) {
            temp_f1_3918 = __frsqrte(var_f4_3912);
            temp_f1_3924 = 0.5 * temp_f1_3918 * -(((f64) var_f4_3912 * (temp_f1_3918 * temp_f1_3918)) - 3.0);
            temp_f1_3928 = 0.5 * temp_f1_3924 * -(((f64) var_f4_3912 * (temp_f1_3924 * temp_f1_3924)) - 3.0);
            var_f4_3912 = (f32) ((f64) var_f4_3912 * (0.5 * temp_f1_3928 * -(((f64) var_f4_3912 * (temp_f1_3928 * temp_f1_3928)) - 3.0)));
        } else if (var_f4_3912 < M2C_BITWISE(f32, 0.0)) {
            var_f4_3912 = __float_nan;
        } else {
            sp10 = var_f4_3912;
            temp_r3_3947 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_3947) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {

                } else {
                    var_r4_3902 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r4_3902 = 5;
                } else {
                    var_r4_3902 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r4_3902 = 4;
                break;
            }
            if (var_r4_3902 == 1) {
                var_f4_3912 = __float_nan;
            }
        }
        var_f7_3978 = 1.0f / var_f4_3912;
    } else {
        var_f7_3978 = 0.0f;
    }
    temp_f1_3983 = (f32) M2C_FIELD(this, f64 *, 0xF0);
    temp_f0_3984 = M2C_FIELD(this, f32 *, 0xF4);
    temp_f8_3991 = this->unkF8;
    sp138 = this->unk120 * var_f7_3978;
    sp13C = this->unk124 * var_f7_3978;
    sp140 = this->unk128 * var_f7_3978;
    var_f4_4000 = (temp_f8_3991 * temp_f8_3991) + ((temp_f1_3983 * temp_f1_3983) + (temp_f0_3984 * temp_f0_3984));
    sp208 = (f64) sp138;
    sp210 = (f64) sp140;
    if (var_f4_4000 > 1e-12f) {
        if (var_f4_4000 > 0.0f) {
            temp_f1_4010 = __frsqrte(var_f4_4000);
            temp_f1_4016 = 0.5 * temp_f1_4010 * -(((f64) var_f4_4000 * (temp_f1_4010 * temp_f1_4010)) - 3.0);
            temp_f1_4020 = 0.5 * temp_f1_4016 * -(((f64) var_f4_4000 * (temp_f1_4016 * temp_f1_4016)) - 3.0);
            var_f4_4000 = (f32) ((f64) var_f4_4000 * (0.5 * temp_f1_4020 * -(((f64) var_f4_4000 * (temp_f1_4020 * temp_f1_4020)) - 3.0)));
        } else if (var_f4_4000 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4000 = __float_nan;
        } else {
            spC = var_f4_4000;
            temp_r3_4039 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_4039) {                 /* switch 5; irregular */
            case 0x7F800000:                        /* switch 5 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_4049 = 1;
                } else {
                    var_r0_4049 = 2;
                }
                break;
            case 0x0:                               /* switch 5 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_4049 = 5;
                } else {
                    var_r0_4049 = 3;
                }
                break;
            default:                                /* switch 5 */
                var_r0_4049 = 4;
                break;
            }
            if (var_r0_4049 == 1) {
                var_f4_4000 = __float_nan;
            }
        }
        var_f0_4071 = 1.0f / var_f4_4000;
    } else {
        var_f0_4071 = 0.0f;
    }
    temp_f6_4076 = (f32) M2C_FIELD(this, f64 *, 0xF0);
    temp_f5_4077 = M2C_FIELD(this, f32 *, 0xF4);
    temp_f7_4079 = this->unkF8;
    temp_r3_4081 = this->unk2AC;
    sp128 = temp_f6_4076 * var_f0_4071;
    sp12C = temp_f5_4077 * var_f0_4071;
    sp130 = temp_f7_4079 * var_f0_4071;
    sp218 = (f64) sp128;
    sp220 = (f64) sp130;
    if (!((temp_r3_4081 >> 5U) & 1) && ((((f32) sp220 * (f32) sp210) + (((f32) sp218 * (f32) sp208) + ((*(f32 *) ((u8 *) &sp218 + 0x4)) * (*(f32 *) ((u8 *) &sp208 + 0x4))))) < 0.7f) && (((temp_f7_4079 * temp_f7_4079) + ((temp_f6_4076 * temp_f6_4076) + (temp_f5_4077 * temp_f5_4077))) > 100000.0f)) {
        var_r26_2980 = 1;
        if (var_r25_2981 != 0) {
            this->unk2AC = temp_r3_4081 | 0x10;
        }
    }
    temp_r3_4117 = this->unk8;
    temp_f1_4118 = M2C_FIELD(temp_r3_4117, f64 *, 0x30);
    sp1F8 = temp_f1_4118;
    sp200 = M2C_FIELD(temp_r3_4117, f64 *, 0x38);
    sp118 = temp_f1_4118 - this->unk130;
    var_r23_4127 = 0;
    sp3E8 = sp118;
    sp120 = (f32) sp200 - this->unk138;
    (*(f32 *) ((u8 *) &sp3E8 + 0x4)) = 0.0f;
    sp3F0 = (f64) sp120;
    if (((((f32) sp3F0 * (f32) sp3F0) + (((f32) sp3E8 * (f32) sp3E8) + (0.0f * 0.0f))) > (100.0f * M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x11C))) && ((u32) this->unk2A4 != 0)) {
        var_r23_4127 = 1;
    }
    this->unk2AC = (this->unk2AC & ~0x40) | (((var_r23_4127 != 0) << 6) & 0x40);
    temp_f1_4165 = this->unk28C;
    if (temp_f1_4165 > 0.0f) {
        this->unk28C = temp_f1_4165 - gUpdateTimeDelta;
    }
    if ((var_r26_2980 != 0) && ((Ball *) pDribblee != this) && (var_r27_2885 == 0) && ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF0) != 0) && (this->unk28C <= 0.0f)) {
        KDSound_Play3d(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF0), (MKVector3 *) &this->unkE0, this->unk2A4, -1, 0.0f, 0U);
        if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF4) != 0) {
            KDSound_Play3d(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF4), (MKVector3 *) &this->unkE0, this->unk2A4, -1, 0.0f, 0U);
        }
        this->unk28C = 0.5f;
    }
    M2C_FIELD(this, f32 *, 0x120) = (f64) this->unkF0;
    M2C_FIELD(this, f32 *, 0x128) = (f64) M2C_FIELD(this, f32 *, 0xF8);
    if (((sp460 * sp460) + (((f32) sp458 * (f32) sp458) + ((*(f32 *) ((u8 *) &sp458 + 0x4)) * (*(f32 *) ((u8 *) &sp458 + 0x4))))) < 0.25f) {
        this->unk290 += 1;
        if ((s32) this->unk290 == 0xA) {
            this->unk2AC &= ~0x80;
        }
    } else {
        this->unk290 = 0;
    }
    this->unkE0 += sp458;
    this->unkE8 += sp460;
    PushOutOfThings();
    temp_r3_4257 = this->unk8;
    temp_f1_4259 = M2C_FIELD(temp_r3_4257, f64 *, 0x30);
    temp_f0_4260 = M2C_FIELD(temp_r3_4257, f64 *, 0x38);
    sp1E8 = temp_f1_4259;
    this->unk130 = temp_f1_4259;
    sp1F0 = temp_f0_4260;
    M2C_FIELD(this, f32 *, 0x138) = temp_f0_4260;
    if (var_r28_2883 != NULL) {
        var_r28_2883->unk70.unk4 = 1;
    }
    sp498 = 0.0f;
    sp49C = 0.0f;
    sp4A0 = 0.0f;
    sp4A8 = 0.0f;
    sp4AC = 0.0f;
    sp4B0 = 0.0f;
    sp4B8 = 0.0f;
    sp4BC = 0.0f;
    sp4C0 = 0.0f;
    sp4C4 = 1.0f;
    sp4C8 = 0.0f;
    sp4CC = 0.0f;
    sp4D0 = 0;
    sp4D2 = 0;
    sp4D3 = 0;
    sp4D4 = 0;
    sp4D8 = 3.4028235e38f;
    sp4DC = 0;
    sp4E0 = 0;
    sp4E4 = -1;
    sp4E8 = 0;
    temp_r9_4302 = this->unk8;
    sp1D8 = M2C_FIELD(temp_r9_4302, f64 *, 0x30);
    sp1E0 = M2C_FIELD(temp_r9_4302, f64 *, 0x38);
    if (MKCollision_GetGroundPoint(*((MKVector3 *) &sp1D8), 500.0f, (MKCollisionResult *) &sp498, 0, 4, NULL, (MKCollisionMode) 1) != 0) {
        sp1B8 = Tools_GroundColor((MKCollisionResult *) &sp498);
        temp_r3_4314 = MKModel_GetColor(this->unk4);
        temp_f2_4316 = M2C_FIELD(temp_r3_4314, f64 *, 0);
        sp48 = M2C_BITWISE(f64, sp1B8) - temp_f2_4316;
        temp_f3_4321 = M2C_FIELD(temp_r3_4314, f64 *, 8);
        temp_f0_4322 = (f64) sp1B8.unk8 - temp_f3_4321;
        sp50 = temp_f0_4322;
        sp108 = sp48;
        sp110 = temp_f0_4322;
        sp38 = sp108 * 5.122630465e-315;
        temp_f0_4333 = temp_f0_4322 * 5.122630465e-315;
        sp40 = temp_f0_4333;
        spF8 = sp38;
        sp100 = temp_f0_4333;
        sp28 = temp_f2_4316 + spF8;
        temp_f0_4343 = temp_f3_4321 + temp_f0_4333;
        sp30 = temp_f0_4343;
        sp1C8 = sp28;
        sp1D0 = temp_f0_4343;
        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp1C8));
    }
    if (sp20 != NULL) {
        sp20->unk4 = sp24;
    }
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void Ball::Message(MKMessage *arg0) {
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;                                      /* compiler-managed */
    MKVector3 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    HeroInterface sp80;
    MKVector3 sp70;
    HeroInterface sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    MKVector3 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Ball ***temp_r4_4679;
    Ball **temp_r3_4701;
    Ball **temp_r3_4705;
    Ball **var_r3_4682;
    Ball *temp_r0_4691;
    Ball *var_r0_4883;
    f32 temp_f0_4844;
    f32 temp_f3_4523;
    f32 var_f1_4501;
    f32 var_f3_4833;
    f32 var_f4_4766;
    f64 temp_f0_4484;
    f64 temp_f0_4727;
    f64 temp_f0_4896;
    f64 temp_f1_4477;
    f64 temp_f1_4519;
    f64 temp_f1_4721;
    f64 temp_f1_4772;
    f64 temp_f1_4778;
    f64 temp_f1_4782;
    f64 temp_f3_4895;
    s32 temp_r0_4404;
    s32 temp_r0_4570;
    s32 temp_r3_4452;
    s32 temp_r3_4801;
    s32 temp_r4_4460;
    s32 var_r0_4811;
    void *temp_r0_4559;
    void *temp_r29_4611;
    void *temp_r3_4459;
    void *temp_r3_4720;
    void *temp_r3_4881;
    void *temp_r3_4892;
    void *temp_r4_4476;

    ((KDSoundPlayer *) &this->unk1D8)->Message(arg0);
    ((KDSoundPlayer *) &this->unk200)->Message(arg0);
    temp_r0_4404 = arg0->unk0;
    switch (temp_r0_4404) {                         /* switch 1; irregular */
    case 224:                                       /* switch 1 */
    case -4:                                        /* switch 1 */
        if ((SnowballTree *) this->unk22C != NULL) {
            Reset();
            return;
        }
    default:                                        /* switch 1 */
block_93:
        GameProp::Message(arg0);
        return;
    case 5:                                         /* switch 1 */
        temp_r3_4452 = this->unk270;
        if ((temp_r3_4452 != 1) && ((u32) (temp_r3_4452 - 3) > 1U)) {
            temp_r3_4459 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
            temp_r4_4460 = M2C_FIELD(temp_r3_4459, s32 *, 0x38);
            if ((((temp_r4_4460 == 0) || (temp_r4_4460 == 1)) && ((s32) M2C_FIELD(temp_r3_4459, s32 *, 0x40) == 3)) || ((temp_r4_4460 == 1) && ((s32) M2C_FIELD(temp_r3_4459, s32 *, 0x40) == 2))) {
                temp_r4_4476 = this->unk8;
                temp_f1_4477 = M2C_FIELD(temp_r4_4476, f64 *, 0x30);
                spF0 = temp_f1_4477;
                spF8 = M2C_FIELD(temp_r4_4476, f64 *, 0x38);
                temp_f0_4484 = temp_f1_4477 - M2C_FIELD(temp_r3_4459, f64 *, 0x10);
                sp40 = temp_f0_4484;
                sp100 = temp_f0_4484;
                sp48 = (f32) spF8 - M2C_FIELD(temp_r3_4459, f32 *, 0x18);
                sp108 = (f64) sp48;
                sp110 = Normalise(*((MKVector3 *) &sp100));
                sp130 = M2C_BITWISE(f64, sp110);
                var_f1_4501 = (*(f32 *) ((u8 *) &sp130 + 0x4));
                sp138 = (f64) sp110.unk8;
                if (var_f1_4501 < 3.4028235e38f) {

                } else {
                    var_f1_4501 = 3.4028235e38f;
                }
                if (var_f1_4501 > 0.0f) {

                } else {
                    var_f1_4501 = 0.0f;
                }
                (*(f32 *) ((u8 *) &sp130 + 0x4)) = var_f1_4501;
                temp_f1_4519 = sp130 * 5.717499035e-315;
                sp130 = temp_f1_4519;
                temp_f3_4523 = (f32) sp138 * 2000.0f;
                sp138 = temp_f3_4523;
                this->unkF0 += temp_f1_4519;
                this->unkF8 += temp_f3_4523;
                spC0 = MKVector(1000.0f, 1000.0f, 1000.0f);
                spD0 = MKVector(-1000.0f, -1000.0f, -1000.0f);
                sp30 = Min(*((MKVector3 *) &this->unkF0), spC0);
                spE0 = Max(sp30, spD0);
                *(MKVector3 *) &this->unkF0 = spE0;
                this->unk2AC |= 0x80;
            } else {
                temp_r0_4559 = this->unk230;
                if (temp_r0_4559 != NULL) {
                    M2C_FIELD(M2C_FIELD(temp_r0_4559, void **, 0x44), M2C_UNK (**)(void *, MKMessage *), 0x2C)(temp_r0_4559, arg0);
                } else {
                    temp_r0_4570 = M2C_FIELD(temp_r3_4459, s32 *, 0x40);
                    if (((temp_r0_4570 == 0) || (temp_r0_4570 == 1)) && ((u8) ballProperties[M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124)].unk0 != 0)) {
                        this->unk284 = 1.5f;
                        this->unk2AC |= 0x80;
                    }
                }
            }
        }
        goto block_93;
    case 1:                                         /* switch 1 */
        if ((u8) ballProperties[M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x124)].unk0 != 0) {
            this->unk284 = 1.5f;
        }
        goto block_93;
    case 4:                                         /* switch 1 */
        temp_r29_4611 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        this->unk2AC &= ~4;
        if ((Catapult *) this->unk228 == NULL) {
            if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xFC) != 0) {
                if ((u32) M2C_FIELD(temp_r29_4611, u32 *, 0x30) != 0x1000U) {
                    ((KDInput *) (gb.unk0->GetInput()))->RumblePlay(0.7f, 0.3f, 0.06f, 0, 4.0f, 0U);
                    if (((u32) M2C_FIELD(temp_r29_4611, u32 *, 8) == gb.unk0->GetProp()) && (this->unk29C <= 0.0f)) {
                        this->unk298 = KDSound_Play(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xFC), 0U, -1);
                        this->unk29C = 0.5f;
                        if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x100) != 0) {
                            KDSound_Play(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x100), 0U, -1);
                        }
                    }
                }
                this->unk2AC |= 0x20;
            }
            temp_r4_4679 = M2C_FIELD(temp_r29_4611, Ball ****, 0x34);
            if (temp_r4_4679 != NULL) {
                var_r3_4682 = *temp_r4_4679;
loop_59:
                temp_r0_4691 = *var_r3_4682;
                if (temp_r0_4691 == NULL) {
                    var_r3_4682 = NULL;
                } else if (temp_r0_4691 == this) {

                } else {
                    var_r3_4682 += 4;
                    goto loop_59;
                }
                if (var_r3_4682 == NULL) {
                    goto block_62;
                }
            } else {
block_62:
                if (temp_r4_4679 != NULL) {
                    temp_r3_4701 = *temp_r4_4679;
                    if ((u32) M2C_FIELD(temp_r3_4701, u32 *, -4) != 0U) {
                        temp_r3_4705 = temp_r3_4701 - 4;
                        *temp_r4_4679 = temp_r3_4705;
                        *temp_r3_4705 = this;
                    }
                }
                sp120 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
                sp128 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
                sp80.GetPos();
                temp_r3_4720 = this->unk8;
                temp_f1_4721 = M2C_FIELD(temp_r3_4720, f64 *, 0x30);
                sp90 = temp_f1_4721;
                sp98 = M2C_FIELD(temp_r3_4720, f64 *, 0x38);
                temp_f0_4727 = temp_f1_4721 - M2C_BITWISE(f64, sp80);
                sp20 = temp_f0_4727;
                spA0 = temp_f0_4727;
                sp28 = (f32) sp98 - sp88;
                spA8 = (f64) sp28;
                spB0 = Normalise(*((MKVector3 *) &spA0));
                *(MKVector3 *) &sp120 = spB0;
                sp60.GetDir();
                sp70 = InterpolateLinear(*((MKVector3 *) &sp120), *((MKVector3 *) &sp60), 0.25f);
                *(MKVector3 *) &sp120 = sp70;
                var_f4_4766 = ((f32) sp128 * (f32) sp128) + (((f32) sp120 * (f32) sp120) + ((*(f32 *) ((u8 *) &sp110 + 0x14)) * (*(f32 *) ((u8 *) &sp110 + 0x14))));
                if (var_f4_4766 > 0.000001f) {
                    if (var_f4_4766 > 0.0f) {
                        temp_f1_4772 = __frsqrte(var_f4_4766);
                        temp_f1_4778 = 0.5 * temp_f1_4772 * -(((f64) var_f4_4766 * (temp_f1_4772 * temp_f1_4772)) - 3.0);
                        temp_f1_4782 = 0.5 * temp_f1_4778 * -(((f64) var_f4_4766 * (temp_f1_4778 * temp_f1_4778)) - 3.0);
                        var_f4_4766 = (f32) ((f64) var_f4_4766 * (0.5 * temp_f1_4782 * -(((f64) var_f4_4766 * (temp_f1_4782 * temp_f1_4782)) - 3.0)));
                    } else if (var_f4_4766 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_4766 = __float_nan;
                    } else {
                        sp8 = var_f4_4766;
                        temp_r3_4801 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_4801) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_4811 = 1;
                            } else {
                                var_r0_4811 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_4811 = 5;
                            } else {
                                var_r0_4811 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_4811 = 4;
                            break;
                        }
                        if (var_r0_4811 == 1) {
                            var_f4_4766 = __float_nan;
                        }
                    }
                    var_f3_4833 = 1.0f / var_f4_4766;
                } else {
                    var_f3_4833 = 0.0f;
                }
                temp_f0_4844 = (f32) sp128 * var_f3_4833;
                sp120 = (f32) sp120 * var_f3_4833;
                (*(f32 *) ((u8 *) &sp110 + 0x14)) *= var_f3_4833;
                sp128 = temp_f0_4844;
                sp120 = (f64) sp120 * 5.717499035e-315;
                sp128 = temp_f0_4844 * 2000.0f;
                (*(f32 *) ((u8 *) &sp110 + 0x14)) = 0.0f;
                this->unkF0 += sp120;
                this->unkF8 += sp128;
                SetPhysicsOn(1U);
                goto block_93;
            }
        } else {
            goto block_93;
        }
        break;
    case 136:                                       /* switch 1 */
        M2C_FIELD(checked_cast<CanHeroHurtYouMsg *, MKMessage>(arg0), s8 *, 8) = 1;
        goto block_93;
    case 181:                                       /* switch 1 */
        SetPhysicsOn(1U);
        goto block_93;
    case 142:                                       /* switch 1 */
        temp_r3_4881 = checked_cast<GetTargetableMsg *, MKMessage>(arg0);
        var_r0_4883 = this;
        if (this != NULL) {
            var_r0_4883 = (Ball *) &this->unkC8;
        }
        M2C_FIELD(temp_r3_4881, Ball **, 8) = var_r0_4883;
        return;
    case 34:                                        /* switch 1 */
        temp_r3_4892 = M2C_FIELD(checked_cast<PlatformMoveMsg *, MKMessage>(arg0), void **, 8);
        temp_f3_4895 = this->unkE0;
        temp_f0_4896 = M2C_FIELD(temp_r3_4892, f64 *, 0) - temp_f3_4895;
        sp10 = temp_f0_4896;
        sp50 = temp_f0_4896;
        sp18 = M2C_FIELD(temp_r3_4892, f32 *, 8) - this->unkE8;
        sp58 = (f64) sp18;
        this->unkE0 = temp_f3_4895 + temp_f0_4896;
        this->unkE8 += (f32) sp58;
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &this->unkE0));
        goto block_93;
    case 38:                                        /* switch 1 */
    case 156:                                       /* switch 1 */
        PlatformDetach();
        goto block_93;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void *Ball::Update() {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    SnowballTree *temp_r3_4951;
    f32 temp_f1_4943;
    f32 temp_f3_4977;
    f64 temp_f0_4966;
    f64 temp_f1_4957;
    s32 temp_r0_4993;
    u8 var_r30_5115;
    void *temp_r3_4955;
    void *temp_r4_4954;
    void *temp_r4_5025;
    void *temp_r4_5126;
    void *temp_r4_5146;

    GameProp::Update();
    temp_f1_4943 = this->unk29C;
    if (temp_f1_4943 > 0.0f) {
        this->unk29C = temp_f1_4943 - gUpdateTimeDelta;
    }
    temp_r3_4951 = this->unk22C;
    if (temp_r3_4951 != NULL) {
        temp_r4_4954 = this->unk8;
        temp_r3_4955 = temp_r3_4951->unk8;
        temp_f1_4957 = M2C_FIELD(temp_r3_4955, f64 *, 0x30);
        sp20 = M2C_FIELD(temp_r4_4954, f64 *, 0x30);
        sp30 = temp_f1_4957;
        sp28 = M2C_FIELD(temp_r4_4954, f64 *, 0x38);
        sp38 = M2C_FIELD(temp_r3_4955, f64 *, 0x38);
        temp_f0_4966 = temp_f1_4957 - sp20;
        sp10 = temp_f0_4966;
        sp40 = temp_f0_4966;
        sp18 = (f32) sp38 - (f32) sp28;
        temp_f3_4977 = 100.0f * this->unk2A0;
        sp48 = (f64) sp18;
        if ((((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + ((*(f32 *) ((u8 *) &sp40 + 0x4)) * (*(f32 *) ((u8 *) &sp40 + 0x4))))) >= (temp_f3_4977 * temp_f3_4977)) {
            Smash();
        }
    }
    temp_r0_4993 = this->unk270;
    switch (temp_r0_4993) {                         /* irregular */
    case 0:
        CheckForHero();
        if (!(((u8) this->unk2AC >> 7U) & 1) && (this->unk284 == 0.0f)) {
            if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x108) != 0) {
                temp_r4_5025 = checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                sp8 = 1;
                ((KDSoundFader *) &this->unk1D8)->Update(M2C_FIELD(temp_r4_5025, s32 *, 0x108), 1U, 0U, (MKProp *) this, NULL, this->unk2A4, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            }
            this->unk2AC &= ~0x20;
        } else {
            UpdatePhysics();
            UpdateMeltingGrowing();
            PlatformUpdate();
            BridgeHit(0.0f, 50.0f);
            UpdateOrientation();
            UpdateShadow();
            CheckForCatapults();
            CheckForRamps();
            CheckForSiegeTowers();
        }
        break;
    case 1:
        UpdateShadow();
        break;
    case 2:
        this->unk288 -= gUpdateTimeDelta;
        if (this->unk288 < 0.0f) {
            if ((SnowballTree *) this->unk22C != NULL) {
                Reset();
            } else {
                SetState((Ball::State) 5);
                Disable();
            }
        }
        UpdatePhysics();
        UpdateOrientation();
        UpdateShadow();
        break;
    default:
        UpdateOrientation();
        UpdateShadow();
        break;
    }
    if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x108) != 0) {
        var_r30_5115 = 0;
        if ((((u8) this->unk2AC >> 6U) & 1) && ((s32) this->unk270 == 0)) {
            var_r30_5115 = 1;
        }
        temp_r4_5126 = checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk1D8)->Update(M2C_FIELD(temp_r4_5126, s32 *, 0x108), 1U, var_r30_5115, (MKProp *) this, NULL, this->unk2A4, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    if ((s32) M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xF8) != 0) {
        temp_r4_5146 = checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        ((KDSoundFader *) &this->unk200)->Update(M2C_FIELD(temp_r4_5146, s32 *, 0xF8), 1U, this->unk270 == 2, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    this->unk2AC &= ~0x20;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Ball::State'
void Ball::Reset() {
    f64 sp10;
    f64 sp8;
    Catapult *temp_r3_5204;
    f64 temp_f0_5253;
    f64 temp_f1_5252;
    void *temp_r3_5251;

    GameProp::Reset();
    this->unkE0 = this->unkD0;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) this->unkD8;
    this->unkF0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk100 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x108) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk2AC |= 0x80;
    this->unk290 = 0;
    this->unk110 = M2C_FIELD(&MKVector3::up, f64 *, 0);
    this->unk118 = M2C_FIELD(&MKVector3::up, f64 *, 8);
    temp_r3_5204 = this->unk228;
    if (temp_r3_5204 != NULL) {
        temp_r3_5204->Unload();
    }
    this->unk228 = NULL;
    this->unk280 = 1.0f;
    this->unk284 = 0.0f;
    this->unk2AC &= ~0x40;
    this->unk2AC &= ~0x20;
    this->unk28C = 0.0f;
    this->unk29C = 0.0f;
    this->unk288 = 20.0f;
    M2C_FIELD(this, f32 *, 0x150) = 0.0f;
    M2C_FIELD(this, f32 *, 0x154) = 0.0f;
    M2C_FIELD(this, f32 *, 0x158) = 0.0f;
    M2C_FIELD(this, f32 *, 0x160) = 0.0f;
    M2C_FIELD(this, f32 *, 0x164) = 0.0f;
    M2C_FIELD(this, f32 *, 0x168) = 0.0f;
    M2C_FIELD(this, f32 *, 0x170) = 0.0f;
    M2C_FIELD(this, f32 *, 0x174) = 0.0f;
    M2C_FIELD(this, f32 *, 0x178) = 0.0f;
    M2C_FIELD(this, f32 *, 0x17C) = 1.0f;
    this->unk180 = 0.0f;
    this->unk184 = 0.0f;
    M2C_FIELD(this, s16 *, 0x188) = 0;
    M2C_FIELD(this, s8 *, 0x18A) = 0;
    M2C_FIELD(this, s8 *, 0x18B) = 0;
    this->unk18C = 0;
    this->unk190 = 3.4028235e38f;
    this->unk194 = 0;
    this->unk198 = NULL;
    this->unk19C = -1;
    this->unk1A0 = 0;
    this->unk120 = 0.0f;
    this->unk124 = 0.0f;
    this->unk128 = 0.0f;
    temp_r3_5251 = this->unk8;
    temp_f1_5252 = M2C_FIELD(temp_r3_5251, f64 *, 0x30);
    temp_f0_5253 = M2C_FIELD(temp_r3_5251, f64 *, 0x38);
    sp8 = temp_f1_5252;
    this->unk130 = temp_f1_5252;
    M2C_FIELD(this, f64 *, 0x138) = temp_f0_5253;
    this->unk230 = NULL;
    sp10 = temp_f0_5253;
    if ((Ball *) pDribblee == this) {
        pDribblee = NULL;
    }
    if (KDSound_IsVoicePlaying(this->unk294) != 0) {
        KDSound_Stop((int *) &this->unk294);
    }
    if (KDSound_IsVoicePlaying(this->unk298) != 0) {
        KDSound_Stop((int *) &this->unk298);
    }
    SetState((Ball::State) 0);
    UpdateShadow();
    if ((SnowballTree *) this->unk22C != NULL) {
        PutInTree();
    }
    PlatformDetach();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double' to 'const MKVector3 &'
void Ball::SetWorldMatrix(const Matrix *arg0) {
    f64 temp_f1_5315;

    MKModel_SetWorldMatrix(this->unk4, *arg0);
    this->unkE0 = M2C_FIELD(arg0, f64 *, 0x30);
    M2C_FIELD(this, f64 *, 0xE8) = (f64) M2C_FIELD(arg0, f64 *, 0x38);
    temp_f1_5315 = this->unkE0;
    this->unk130 = temp_f1_5315;
    M2C_FIELD(this, f64 *, 0x138) = (f64) M2C_FIELD(this, f64 *, 0xE8);
    SetPos(this->unkE0, temp_f1_5315);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to 'Ball::State'
void Ball::DropFromTree() {
    this->unk2AC |= 0x80;
    SetState((Ball::State) 0);
    Enable();
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r4_5381'
void Ball::PutInTree() {
    SnowballTree *temp_r4_5381;
    f64 temp_f1_5373;

    this->unk2AC &= ~0x80;
    this->unkE0 = this->unk140;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) this->unk148;
    temp_f1_5373 = this->unkE0;
    this->unk130 = temp_f1_5373;
    M2C_FIELD(this, f64 *, 0x138) = (f64) M2C_FIELD(this, f64 *, 0xE8);
    M2C_FIELD(this->__vptr, M2C_UNK (**)(f64 *, f64), 0x38)(&this->unkE0, temp_f1_5373);
    temp_r4_5381 = this->unk22C;
    if (temp_r4_5381 != NULL) {
        MKModel_SetColor(this->unk4, *((MKVector4 *) &temp_r4_5381->unk50));
    }
    SetState((Ball::State) 1);
    Disable();
}
#endif

#if 0 // DRAFT: ')' expected
f32 Ball::Resolve() {
    void *temp_r31_5414;
    void *temp_r31_5423;

    KDPropEx::Resolve();
    temp_r31_5414 = checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk1D8)->Init(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x10C), M2C_FIELD(temp_r31_5414, f32 *, 0x110));
    temp_r31_5423 = checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk200)->Init(M2C_FIELD(checked_cast<BallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x114), M2C_FIELD(temp_r31_5423, f32 *, 0x118));
    if (!(((u8) this->unk2AC >> 3U) & 1)) {
        SetGroup(this->unk2A8);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s32 Ball::LoadDone() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_5474;

    GameProp::LoadDone();
    this->unk1A8.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    MKModel_GetPosition(this->unk4);
    this->unkD0 = *M2C_ERROR(/* Read from unset register $r3 */);
    this->unkD8 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f64 *, 8);
    ((Targetable *) &this->unkC8)->RegisterTargetable();
    temp_f1_5474 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0xC);
    sp8 = 1.0f;
    spC = 1.0f;
    this->unk274 = 0.55f * temp_f1_5474;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **, f64, f32), 0x84)(gMK, (f64) sp8, 0.55f)))->AddSphere(((u8 *) this->unk8) + 0x30, this->unk274, 0.0f, *((MKVector4 *) &sp18), (MKCollisionMode) 2, &this->unk70, 0x10002U);
}
#endif

s32 Ball::LoadLine(MKIniLine *arg0) {
    if (GameProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("group") != 0) {
        this->unk2A8 = arg0->GetInt(0);
        return 1;
    }
    return 0;
}

void Ball::Deinit() {
    SetGroup(0xFF);
    this->unk1A8.Deinit();
    if (KDSound_IsVoicePlaying(this->unk294) != 0) {
        KDSound_Stop((int *) &this->unk294);
    }
    KDSound_Stop((int *) &this->unk1D8);
    KDSound_Stop((int *) &this->unk200);
    ((Targetable *) &this->unkC8)->UnregisterTargetable();
    if ((Ball *) pDribblee == this) {
        pDribblee = NULL;
    }
    PlatformDetach();
    GameProp::Deinit();
}

void Ball::Init() {
    GameProp::Init();
    this->unk274 = 72.0f;
    this->unk278 = 0.5f;
    this->unk27C = 0.25f;
    this->unk280 = 1.0f;
    M2C_FIELD(this, f32 *, 0x150) = 0.0f;
    M2C_FIELD(this, f32 *, 0x154) = 0.0f;
    M2C_FIELD(this, f32 *, 0x158) = 0.0f;
    M2C_FIELD(this, f32 *, 0x160) = 0.0f;
    M2C_FIELD(this, f32 *, 0x164) = 0.0f;
    M2C_FIELD(this, f32 *, 0x168) = 0.0f;
    M2C_FIELD(this, f32 *, 0x170) = 0.0f;
    M2C_FIELD(this, f32 *, 0x174) = 0.0f;
    M2C_FIELD(this, f32 *, 0x178) = 0.0f;
    M2C_FIELD(this, f32 *, 0x17C) = 1.0f;
    this->unk180 = 0.0f;
    this->unk184 = 0.0f;
    M2C_FIELD(this, s16 *, 0x188) = 0;
    M2C_FIELD(this, s8 *, 0x18A) = 0;
    M2C_FIELD(this, s8 *, 0x18B) = 0;
    this->unk18C = 0;
    this->unk190 = 3.4028235e38f;
    this->unk194 = 0;
    this->unk198 = NULL;
    this->unk19C = -1;
    this->unk1A0 = 0;
    this->unk1A0 = 0;
    this->unk294 = 0;
    this->unk2AC &= ~0x40;
    this->unk120 = 0.0f;
    this->unk124 = 0.0f;
    this->unk128 = 0.0f;
    this->unk2AC &= ~0x20;
    this->unk2A4 = 0;
    this->unk2A8 = 0xFF;
    this->unk2AC &= ~0x10;
    this->unk230 = NULL;
    this->unk2AC &= ~8;
    this->unk288 = 20.0f;
    this->unk298 = 0;
    this->unk28C = 0.0f;
    this->unk29C = 0.0f;
    this->unk22C = NULL;
    this->unk228 = NULL;
    this->unk2AC |= 4;
    this->unk234 = NULL;
    this->unk238 = (MKProp *) this;
    this->unk260 = this;
    this->unk2A0 = 200.0f;
}

void BallDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unk120 = (long) (checked_cast<CrashMistPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("CrashMistPS")));
}

#if 0 // DRAFT: undefined identifier 'unkE4'
s32 BallDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_5705;

    var_r31_5705 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("rollFadeIn", &this->unk10C, 0) != 0) || (arg0->LoadFloat("rollFadeOut", &this->unk110, 0) != 0) || (arg0->LoadFloat("flyFadeIn", &this->unk114, 0) != 0) || (arg0->LoadFloat("flyFadeOut", &this->unk118, 0) != 0) || (arg0->LoadFloat("rollCutoffSpeed", &this->unk11C, 0) != 0) || (KDSound_LoadLine(arg0, "hitSound", (int *) &this->unkE4) != 0) || (KDSound_LoadLine(arg0, "meltSound", (int *) &this->unkE8) != 0) || (KDSound_LoadLine(arg0, "placeSound", (int *) &this->unkEC) != 0) || (KDSound_LoadLine(arg0, "bounceSound", (int *) &this->unkF0) != 0) || (KDSound_LoadLine(arg0, "bounceSound2", (int *) &this->unkF4) != 0) || (KDSound_LoadLine(arg0, "flyingSound", (int *) &this->unkF8) != 0) || (KDSound_LoadLine(arg0, "sndHitByHero", (int *) &this->unkFC) != 0) || (KDSound_LoadLine(arg0, "sndHitByHero2", (int *) &this->unk100) != 0) || (KDSound_LoadLine(arg0, "rollSoundLoop", (int *) &this->unk108) != 0) || (KDSound_LoadLine(arg0, "hitEnemySound", (int *) &this->unk104) != 0) || (DataMap_LoadLine(arg0, "ballType", ballTypeMap, (unsigned int *) &this->unk124) != 0)) {
        var_r31_5705 = 1;
    }
    return var_r31_5705;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkE4'
void BallDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = 0;
    this->unkE8 = 0;
    this->unkEC = 0;
    this->unkF0 = 0;
    this->unkF4 = 0;
    this->unkF8 = 0;
    this->unk108 = 0;
    this->unk104 = 0;
    this->unk100 = 0;
    this->unkFC = GS_SpyroMeleeHit;
    this->unk10C = 0.5f;
    this->unk110 = 1.25f;
    this->unk114 = 0.5f;
    this->unk118 = 0.25f;
    this->unk11C = 0.08f;
}
#endif

#if 0 // DRAFT: undefined identifier 'groups'
void Ball_InitModule() {
    memset(groups, 0, 0x140U);
}
#endif

void Ball_cpp::__sinit() {
    f32 temp_f0_5944;
    f64 temp_f1_5925;
    f64 temp_f1_5933;
    f64 temp_f3_5913;
    f64 temp_f4_5922;
    f64 temp_f4_5930;
    f64 temp_f8_5915;

    temp_f3_5913 = __frsqrte(2014000.0);
    temp_f8_5915 = __frsqrte(380000.0);
    temp_f4_5922 = 0.5 * temp_f3_5913 * -((2014000.0 * (temp_f3_5913 * temp_f3_5913)) - 3.0);
    temp_f1_5925 = 0.5 * temp_f8_5915 * -((380000.0 * (temp_f8_5915 * temp_f8_5915)) - 3.0);
    temp_f4_5930 = 0.5 * temp_f4_5922 * -((2014000.0 * (temp_f4_5922 * temp_f4_5922)) - 3.0);
    temp_f1_5933 = 0.5 * temp_f1_5925 * -((380000.0 * (temp_f1_5925 * temp_f1_5925)) - 3.0);
    temp_f0_5944 = (f32) (380000.0 * (0.5 * temp_f1_5933 * -((380000.0 * (temp_f1_5933 * temp_f1_5933)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_5930 * -((2014000.0 * (temp_f4_5930 * temp_f4_5930)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_5944;
}

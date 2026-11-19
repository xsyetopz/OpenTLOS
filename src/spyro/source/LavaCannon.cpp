#include "spyro/source/LavaCannon.h"
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
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AnimUtils.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PropFlags.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern s32 GS_TowerHit;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

void LavaCannon::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3) {
    if ((s32) this->unk260 < 4) {
        SetState(4);
    }
}

#if 0 // DRAFT: ')' expected
void LavaCannon::EmitExplodingEffects() {
    MKVector3 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    MKVector3 sp10;
    s32 sp8;
    s32 temp_r0_64;
    s32 temp_r29_262;
    u8 var_r30_260;
    void *temp_r3_124;
    void *temp_r3_157;
    void *temp_r3_190;
    void *temp_r3_223;
    void *temp_r3_91;

    temp_r0_64 = this->unk25C;
    switch (temp_r0_64) {                           /* irregular */
    case 0:
        if (this->unk254 >= 0.4f) {
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x188), &sp50);
            temp_r3_91 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_91, Explosion4 **, 0x19C)))->Trigger(sp50, 0.75f, 0U, NULL, 5, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 1:
        if (this->unk254 >= 0.3f) {
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x18C), &sp40);
            temp_r3_124 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_124, Explosion4 **, 0x19C)))->Trigger(sp40, 0.75f, 0U, NULL, 5, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 2:
        if (this->unk254 >= 0.2f) {
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x184), &sp30);
            temp_r3_157 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_157, Explosion4 **, 0x19C)))->Trigger(sp30, 0.75f, 0U, NULL, 5, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 3:
        if (this->unk254 >= 0.2f) {
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x18C), &sp20);
            temp_r3_190 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_190, Explosion4 **, 0x19C)))->Trigger(sp20, 1.0f, 0U, NULL, 5, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 4:
        if (this->unk254 >= 0.1f) {
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x188), &sp10);
            temp_r3_223 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            sp8 = 1;
            ((Explosion4 *) (M2C_FIELD(temp_r3_223, Explosion4 **, 0x19C)))->Trigger(sp10, 1.0f, 0U, NULL, 5, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
            this->unk254 = 0.0f;
            this->unk25C += 1;
            Shatterable::Shatter(0U, NULL, -1, NULL, 1U, 0U);
            this->unk264 = 1;
            var_r30_260 = 0;
            temp_r29_262 = KDSound_Play3d(GS_TowerHit, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                var_r30_260 = 1;
            }
            if (var_r30_260 != 0) {
                KDSound_SetVolume(temp_r29_262, 0.25f * (f32) KDSound_GetSoundEventVol(GS_TowerHit));
            }
        }
        break;
    }
    this->unk254 += gUpdateTimeDelta;
}
#endif

void LavaCannon::EmitFiringEffects() {
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
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    f64 temp_f0_319;
    f64 temp_f0_331;
    f64 temp_f0_364;
    f64 temp_f0_375;
    void *temp_r3_315;

    temp_r3_315 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_f0_319 = this->unk1E8 * 5.53552857e-315;
    sp50 = temp_f0_319;
    sp90 = temp_f0_319;
    sp58 = this->unk1F0 * 100.0f;
    sp98 = (f64) sp58;
    temp_f0_331 = M2C_FIELD(this, f64 *, 0x1F8) + temp_f0_319;
    sp40 = temp_f0_331;
    spA0 = temp_f0_331;
    sp48 = this->unk1F8.unk8 + (f32) sp98;
    spA8 = (f64) sp48;
    sp8 = 0;
    ((Explosion4 *) (M2C_FIELD(temp_r3_315, Explosion4 **, 0x19C)))->Trigger(*((MKVector3 *) &spA0), 0.2f, 0U, NULL, 5, 0U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp28 = 0.0f;
    sp20 = 0.0f;
    sp24 = 1000.0f;
    sp68 = (f64) sp28;
    sp60 = (f64) sp20;
    temp_f0_364 = this->unk1E8 * 5.676053805e-315;
    sp30 = temp_f0_364;
    sp70 = temp_f0_364;
    sp38 = this->unk1F0 * 1000.0f;
    sp78 = (f64) sp38;
    temp_f0_375 = sp70 + sp60;
    sp10 = temp_f0_375;
    sp80 = temp_f0_375;
    sp18 = (f32) sp78 + (f32) sp68;
    sp88 = (f64) sp18;
    gb.EmitDust(this->unk1F8, *((MKVector3 *) &sp80), 10.0f, 0.0f);
}

void LavaCannon::SetState(int arg0) {
    if (((s32) this->unk260 != 4) || ((u8) this->unk264 != 0)) {
        this->unk25C = 0;
        this->unk254 = 0.0f;
        this->unk264 = 0;
        this->unk260 = arg0;
        if ((u32) M2C_FIELD((checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk260 * 4)), u32 *, 0x16C) != 0U) {
            this->unk80->SetAnim(M2C_FIELD((checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (this->unk260 * 4)), MKAnim **, 0x16C), this->unk258, 0.0f, 0, -1);
        }
    }
}

#if 0 // DRAFT: illegal operand
void LavaCannon::Message(MKMessage *arg0) {
    s32 temp_r0_459;

    temp_r0_459 = arg0->unk0;
    switch (temp_r0_459) {                          /* irregular */
    case 0xB5:
        Shatter(0, 0, -1, 0);
        break;
    case 0x4E:
        if ((void *) this->unk240 == (u32) arg0->unk4) {
            this->unk240 = NULL;
        }
        break;
    }
    Shatterable::Message(arg0);
}
#endif

void LavaCannon::Reset() {
    Shatterable::Reset();
    this->unk248 = 0.0f;
    this->unk24C = this->unk244;
    memset(&this->unk218, 0, 0x28U);
    this->unk260 = 0;
    this->unk25C = 0;
    this->unk254 = 0.0f;
    this->unk264 = 0;
}

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void LavaCannon::Draw() {
    Matrix sp110;
    Matrix spD0;
    Matrix sp90;
    f64 sp88;
    f64 sp80;
    f32 sp70;
    M2C_UNK sp60;
    f64 sp58;
    f64 sp50;
    f32 sp40;
    M2C_UNK sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 temp_r30_590;
    s32 temp_r30_653;
    void *temp_r30_545;
    void *temp_r30_576;
    void *temp_r30_608;
    void *temp_r30_639;

    sp90.SetIdentity();
    sp90.SetRotationPitch(this->unk248);
    sp110.SetIdentity();
    temp_r30_545 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((Animation *) &sp70)->GetNodeOrigin(MKModel_GetAnimation(this->unk80->unk8));
    sp20 = -sp70;
    sp24 = -sp74;
    sp28 = -sp78;
    sp80 = (f64) sp20;
    sp88 = (f64) sp28;
    sp110.Translate(&sp110, *((MKVector3 *) &sp80));
    sp110.Multiply(&sp110, &sp90);
    temp_r30_576 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((Animation *) &sp60)->GetNodeOrigin(MKModel_GetAnimation(this->unk80->unk8));
    sp110.Translate(&sp110, *((MKVector3 *) &sp60));
    temp_r30_590 = M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x188);
    ((Animation *) (MKModel_GetAnimation(this->unk80->unk8)))->SetCustomMatrix(temp_r30_590, &sp110, (AnimationMatrixPosition) 2, 0U);
    sp90.SetIdentity();
    sp90.SetRotationYaw(this->unk24C);
    spD0.SetIdentity();
    temp_r30_608 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((Animation *) &sp40)->GetNodeOrigin(MKModel_GetAnimation(this->unk80->unk8));
    sp10 = -sp40;
    sp14 = -sp44;
    sp18 = -sp48;
    sp50 = (f64) sp10;
    sp58 = (f64) sp18;
    spD0.Translate(&spD0, *((MKVector3 *) &sp50));
    spD0.Multiply(&spD0, &sp90);
    temp_r30_639 = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((Animation *) &sp30)->GetNodeOrigin(MKModel_GetAnimation(this->unk80->unk8));
    spD0.Translate(&spD0, *((MKVector3 *) &sp30));
    temp_r30_653 = M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x184);
    ((Animation *) (MKModel_GetAnimation(this->unk80->unk8)))->SetCustomMatrix(temp_r30_653, &spD0, (AnimationMatrixPosition) 2, 0U);
    Shatterable::Draw();
}
#endif

#if 0 // DRAFT: ')' expected
void *LavaCannon::Update() {
    Matrix sp80;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKVector3 *temp_r29_1009;
    MKVector3 *temp_r29_1027;
    f32 var_f4_837;
    f64 temp_f1_840;
    f64 temp_f1_846;
    f64 temp_f1_850;
    s32 temp_cr0_eq_969;
    s32 temp_r0_787;
    s32 temp_r3_869;
    s32 var_r0_879;
    s32 var_r28_1001;
    s32 var_r31_1002;
    u8 var_r29_1039;
    void *temp_r3_816;
    void *temp_r3_968;
    void *temp_r3_978;
    void *temp_r4_809;

    Shatterable::Update();
    if (this->unk10 & 0x20000) {
        if ((s32) this->unk260 != 5) {
            MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x190), &sp80, 1U);
            sp18 = -sp80.unk20;
            sp1C = -sp80.unk24;
            sp20 = -sp80.unk28;
            this->unk1E8 = (f64) sp18;
            M2C_FIELD(this, f64 *, 0x1F0) = (f64) sp20;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x190), &this->unk1F8);
            Tools_CalculateVelocity(sp48, this->unk1F8, 5000.0f, -1960.0f);
            M2C_FIELD(this, f64 *, 0x218) = M2C_BITWISE(f64, sp48);
            M2C_FIELD(this, f64 *, 0x220) = (f64) sp48.unk8;
            this->unk230 = KDMath_GetPitch(this->unk218);
            this->unk234 = KDMath_GetYaw(this->unk218);
            if ((u8) this->unk238 == 0) {
                KDMath_TurnToAngle(this->unk24C, this->unk234, 0.2f * gUpdateTimeDelta * this->unk258);
                this->unk24C = M2C_ERROR(/* Read from unset register $f1 */);
                if ((f32) fabs(KDMath_GetSmallestAngle(this->unk24C, this->unk234)) < 0.001f) {
                    this->unk238 = 1;
                }
            }
            if (((u8) this->unk238 != 0) && ((u8) this->unk239 == 0)) {
                KDMath_TurnToAngle(this->unk248, this->unk230, 0.1f * gUpdateTimeDelta * this->unk258);
                this->unk248 = M2C_ERROR(/* Read from unset register $f1 */);
                if ((f32) fabs(KDMath_GetSmallestAngle(this->unk248, this->unk230)) < 0.001f) {
                    this->unk239 = 1;
                }
            }
        }
        temp_r0_787 = this->unk260;
        switch (temp_r0_787) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            this->unk238 = 0;
            this->unk239 = 0;
            this->unk228 = MKRand_Int((int *) &gViewSeed, 0, 3);
            temp_r4_809 = this->unk8;
            sp38 = M2C_FIELD(temp_r4_809, f64 *, 0x30);
            temp_r3_816 = this + ((this->unk228 * 0x10) + 0x1A8);
            sp40 = M2C_FIELD(temp_r4_809, f64 *, 0x38);
            sp28 = M2C_FIELD(temp_r3_816, f64 *, 0) - sp38;
            sp68 = sp28;
            sp30 = M2C_FIELD(temp_r3_816, f32 *, 8) - (f32) sp40;
            sp70 = (f64) sp30;
            var_f4_837 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))));
            if (var_f4_837 > 0.0f) {
                temp_f1_840 = __frsqrte(var_f4_837);
                temp_f1_846 = 0.5 * temp_f1_840 * -(((f64) var_f4_837 * (temp_f1_840 * temp_f1_840)) - 3.0);
                temp_f1_850 = 0.5 * temp_f1_846 * -(((f64) var_f4_837 * (temp_f1_846 * temp_f1_846)) - 3.0);
                var_f4_837 = (f32) ((f64) var_f4_837 * (0.5 * temp_f1_850 * -(((f64) var_f4_837 * (temp_f1_850 * temp_f1_850)) - 3.0)));
            } else if (var_f4_837 < M2C_BITWISE(f32, 0.0)) {
                var_f4_837 = __float_nan;
            } else {
                sp10 = var_f4_837;
                temp_r3_869 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_869) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_879 = 1;
                    } else {
                        var_r0_879 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_879 = 5;
                    } else {
                        var_r0_879 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_879 = 4;
                    break;
                }
                if (var_r0_879 == 1) {
                    var_f4_837 = __float_nan;
                }
            }
            this->unk22C = var_f4_837;
            this->unk250 = 0.0f;
            SetState(1);
            break;
        case 1:                                     /* switch 1 */
            if ((this->unk80->unk2C & 1) && ((u8) this->unk238 != 0) && ((u8) this->unk239 != 0)) {
                this->unk250 += gUpdateTimeDelta;
                if (this->unk250 >= (0.5f * (1.0f / this->unk258))) {
                    this->unk250 = 0.5f;
                    SetState(2);
                }
            }
            break;
        case 2:                                     /* switch 1 */
            SetState(3);
            break;
        case 3:                                     /* switch 1 */
            if (this->unk80->unk2C & 1) {
                SetState(0);
            }
            break;
        case 4:                                     /* switch 1 */
            if ((u8) this->unk264 == 0) {
                EmitExplodingEffects();
            } else {
                SetState(5);
            }
            break;
        }
        this->unk208.Update(this->unk80);
        if (this->unk208.unk4 & 1) {
            temp_r3_968 = this->unk240;
            temp_cr0_eq_969 = temp_r3_968 == NULL;
            if (temp_cr0_eq_969 != 0) {
                if (temp_cr0_eq_969 == 0) {
                    M2C_FIELD(temp_r3_968, s32 *, 0x130) = 0;
                }
                this->unk240 = ((Projectile *)8)->CreateInstance((ProjectileType) M2C_ERROR(/* Read from unset register $r4 */));
                temp_r3_978 = this->unk240;
                if (temp_r3_978 != NULL) {
                    M2C_FIELD(M2C_FIELD(temp_r3_978, void **, 0x44), M2C_UNK (**)(MKVector3 *, MKVector3 *, LavaCannon *, M2C_UNK, M2C_UNK), 0x48)(&this->unk1F8, &this->unk218, this, 0, 0);
                }
                EmitFiringEffects();
            }
        }
        if ((this->unk208.unk4 & 2) && ((void *) this->unk240 == NULL)) {
            var_r28_1001 = 0;
            var_r31_1002 = 0;
            if ((s32) M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x194) != 0) {
                temp_r29_1009 = ((u8 *) this->unk8) + 0x30;
                var_r28_1001 = KDSound_Play3d(M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x194), temp_r29_1009, 0U, -1, 0.0f, 0U);
            }
            if ((s32) M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x198) != 0) {
                temp_r29_1027 = ((u8 *) this->unk8) + 0x30;
                var_r31_1002 = KDSound_Play3d(M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x198), temp_r29_1027, 0U, -1, 0.0f, 0U);
            }
            var_r29_1039 = 0;
            if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                var_r29_1039 = 1;
            }
            if (var_r29_1039 != 0) {
                if (var_r28_1001 != 0) {
                    KDSound_SetVolume(var_r28_1001, 0.25f * ((f32) KDSound_GetSoundEventVol(M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x194)) / 255.0f));
                }
                if (var_r31_1002 != 0) {
                    KDSound_SetVolume(var_r31_1002, 0.25f * ((f32) KDSound_GetSoundEventVol(M2C_FIELD(checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x198)) / 255.0f));
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P20LavaCannonDescriptor'
f32 LavaCannon::Resolve() {
    Shatterable::Resolve();
    this->unk208.Init(checked_cast<P20LavaCannonDescriptor, 16MKPropDescriptor>__FP16MKPropDescriptor((MKPropDescriptor *) this->unk0) + 0x1A4);
    ((Animation *) (MKModel_GetAnimation(this->unk80->unk8)))->EnableCustomMatrices(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp2C'
s32 LavaCannon::LoadDone() {
    Matrix sp70;
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;

    Shatterable::LoadDone();
    this->unk244 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x54);
    M2C_STRUCT_COPY((s32) &sp30.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp18 = 0.0f;
    sp10 = 0.0f;
    sp14 = 0.0f;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    sp70.SetRotationPYR(*((MKVector3 *) &sp20));
    MKModel_SetWorldMatrix(this->unk4, sp70);
    M2C_STRUCT_COPY((s32) &unksp2C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    sp30.Scale3x3(&sp30, MKProp::loadInfo + 0x60);
    MKModel_SetWorldMatrix(this->unk4, sp30);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKIniLine *' to
s32 LavaCannon::LoadLine(MKIniLine *arg0) {
    MKIniLine sp28;
    MKIniLine sp18;
    MKIniLine sp8;
    s32 var_r29_1272;

    if (arg0->IsField("LavaCannonTarget_01") != 0) {
        sp28.GetVector3(arg0->unkC->GetSubLine(arg0));
        this->unk1A8 = M2C_BITWISE(f64, sp28);
        this->unk1B0 = M2C_BITWISE(f64, sp28.unk8);
    } else if (arg0->IsField("LavaCannonTarget_02") != 0) {
        sp18.GetVector3(arg0->unkC->GetSubLine(arg0));
        this->unk1B8 = M2C_BITWISE(f64, sp18);
        this->unk1C0 = M2C_BITWISE(f64, sp18.unk8);
    } else if (arg0->IsField("LavaCannonTarget_03") != 0) {
        sp8.GetVector3(arg0->unkC->GetSubLine(arg0));
        this->unk1C8 = M2C_BITWISE(f64, sp8);
        this->unk1D0 = M2C_BITWISE(f64, sp8.unk8);
    }
    var_r29_1272 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat("SpeedMultiplier", &this->unk258, 0) != 0)) {
        var_r29_1272 = 1;
    }
    return var_r29_1272;
}
#endif

void LavaCannon::Deinit() {
    void *temp_r4_1302;

    temp_r4_1302 = this->unk240;
    if (temp_r4_1302 != NULL) {
        M2C_FIELD(temp_r4_1302, s32 *, 0x130) = 0;
    }
    Shatterable::Deinit();
}

void LavaCannon::Init() {
    Shatterable::Init();
    PropFlagsSet((unsigned int *) &this->unk10, 0x80000U);
    this->unk248 = 0.0f;
    this->unk24C = 0.0f;
    this->unk1D8 = 1.0f;
    this->unk1DC = 1.0f;
    this->unk1E0 = 1.0f;
    this->unk254 = 0.0f;
    this->unk264 = 0;
    this->unk25C = 0;
    this->unk250 = 0.0f;
    this->unk258 = 1.0f;
    this->unk240 = NULL;
}

void LavaCannonDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unk1A4.Init(&this->unk1AC, 2, (MKAnimScript *) this->unk34);
}

#if 0 // DRAFT: undefined identifier 'unk16C'
void LavaCannonDescriptor::LoadDone() {
    s8 *temp_r30_1378;
    s8 *temp_r30_1398;
    s8 *temp_r30_1416;
    s8 *temp_r30_1434;
    s8 *temp_r30_1452;
    s8 *temp_r30_1470;
    void *var_r3_1390;
    void *var_r3_1408;
    void *var_r3_1426;
    void *var_r3_1444;
    void *var_r3_1462;
    void *var_r3_1480;

    ShatterableDescriptor::LoadDone();
    temp_r30_1378 = this->unk34;
    if (((MKAnimScript *) temp_r30_1378)->Exists("idle") != 0) {
        var_r3_1390 = ((MKAnimScript *) temp_r30_1378)->GetAnim("idle");
    } else {
        var_r3_1390 = NULL;
    }
    this->unk16C = (s32) var_r3_1390;
    temp_r30_1398 = this->unk34;
    if (((MKAnimScript *) temp_r30_1398)->Exists("idle") != 0) {
        var_r3_1408 = ((MKAnimScript *) temp_r30_1398)->GetAnim("idle");
    } else {
        var_r3_1408 = NULL;
    }
    this->unk170 = (s32) var_r3_1408;
    temp_r30_1416 = this->unk34;
    if (((MKAnimScript *) temp_r30_1416)->Exists("idle") != 0) {
        var_r3_1426 = ((MKAnimScript *) temp_r30_1416)->GetAnim("idle");
    } else {
        var_r3_1426 = NULL;
    }
    this->unk174 = (s32) var_r3_1426;
    temp_r30_1434 = this->unk34;
    if (((MKAnimScript *) temp_r30_1434)->Exists("firing") != 0) {
        var_r3_1444 = ((MKAnimScript *) temp_r30_1434)->GetAnim("firing");
    } else {
        var_r3_1444 = NULL;
    }
    this->unk178 = (s32) var_r3_1444;
    temp_r30_1452 = this->unk34;
    if (((MKAnimScript *) temp_r30_1452)->Exists("exploding") != 0) {
        var_r3_1462 = ((MKAnimScript *) temp_r30_1452)->GetAnim("exploding");
    } else {
        var_r3_1462 = NULL;
    }
    this->unk17C = (s32) var_r3_1462;
    temp_r30_1470 = this->unk34;
    if (((MKAnimScript *) temp_r30_1470)->Exists("idle") != 0) {
        var_r3_1480 = ((MKAnimScript *) temp_r30_1470)->GetAnim("idle");
    } else {
        var_r3_1480 = NULL;
    }
    this->unk180 = (s32) var_r3_1480;
    this->unk184 = ((Animation *) (MKModel_GetAnimation(M2C_FIELD(this->unk34, MKModel **, 8))))->GetNodeIndex("z_yaw");
    this->unk188 = ((Animation *) (MKModel_GetAnimation(M2C_FIELD(this->unk34, MKModel **, 8))))->GetNodeIndex("z_pitch");
    this->unk18C = ((Animation *) (MKModel_GetAnimation(M2C_FIELD(this->unk34, MKModel **, 8))))->GetNodeIndex("z_barrel1");
    this->unk190 = MKModel_GetRefPointIndex(this->unk2C, "r_emitter");
    this->unk19C = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
    this->unk1AC.unk0 = "fire";
    this->unk1B4 = "firesound";
}
#endif

s32 LavaCannonDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1545;

    var_r31_1545 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndFire1", (int *) &this->unk194) != 0) || (KDSound_LoadLine(arg0, "sndFire2", (int *) &this->unk194) != 0)) {
        var_r31_1545 = 1;
    }
    return var_r31_1545;
}

void LavaCannonDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk194 = GS_PLACEHOLDER;
    this->unk198 = GS_PLACEHOLDER;
}

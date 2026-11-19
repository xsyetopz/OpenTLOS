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

void LavaCannon::EmitExplodingEffects() {
    MKVector3 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    MKVector3 sp20;
    MKVector3 sp10;
    LavaCannonDescriptor *desc;
    void *cutscene;
    s32 sound;
    u8 playing;

    switch (this->unk25C) {
    case 0:
        if (this->unk254 >= 0.4f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk188, &sp50);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp50, 0.75f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 1:
        if (this->unk254 >= 0.3f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk18C, &sp40);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp40, 0.75f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 2:
        if (this->unk254 >= 0.2f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk184, &sp30);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp30, 0.75f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 3:
        if (this->unk254 >= 0.2f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk18C, &sp20);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp20, 1.0f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
        }
        break;
    case 4:
        if (this->unk254 >= 0.1f) {
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            MKModel_CalculateNodeWorldPosition(this->unk80->unk8, desc->unk188, &sp10);
            desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            ((Explosion4 *) desc->unk19C)->Trigger(sp10, 1.0f, 0, NULL, 5, 0, 1, 1, 1);
            this->unk254 = 0.0f;
            this->unk25C += 1;
            Shatterable::Shatter(0, NULL, -1, NULL, 1, 0);
            this->unk264 = 1;
            playing = 0;
            sound = KDSound_Play3d(GS_TowerHit, (const MKVector3 *) ((s8 *) this->unk8 + 0x30), 0, -1, 0.0f, 0);
            cutscene = M2C_FIELD(&gb, void **, 0xC);
            if (((M2C_FIELD(cutscene, u32 *, 0x78) != 0) || (M2C_FIELD(cutscene, u32 *, 0x84) != 0)) &&
                (((KDStateMachine<CutsceneSystem> *) ((s8 *) cutscene + 0x24))->GetState() != 0)) {
                playing = 1;
            }
            if (playing != 0) {
                KDSound_SetVolume(sound, 0.25f * (f32) KDSound_GetSoundEventVol(GS_TowerHit));
            }
        }
        break;
    }
    this->unk254 += gUpdateTimeDelta;
}

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

void LavaCannon::Message(MKMessage *arg0) {
    switch (arg0->unk0) {
    case 0xB5:
        Shatter(0, 0, -1, 0);
        break;
    case 0x4E:
        if ((u32) this->unk240 == arg0->unk4) {
            this->unk240 = NULL;
        }
        break;
    }
    Shatterable::Message(arg0);
}

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

void LavaCannon::Draw() {
    Matrix sp110;
    Matrix spD0;
    Matrix sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    MKVector3 sp60;
    MKVector3 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    LavaCannonDescriptor *desc;
    s32 index;

    sp90.SetIdentity();
    sp90.SetRotationPitch(this->unk248);
    sp110.SetIdentity();
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp70 = MKModel_GetAnimation(this->unk80->unk8)->GetNodeOrigin(desc->unk188);
    sp80.unk0 = -sp70.unk0;
    sp80.unk4 = -sp70.unk4;
    sp80.unk8 = -sp70.unk8;
    sp110.Translate(&sp110, sp80);
    sp110.Multiply(&sp110, &sp90);
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp60 = MKModel_GetAnimation(this->unk80->unk8)->GetNodeOrigin(desc->unk188);
    sp110.Translate(&sp110, sp60);
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    index = desc->unk188;
    MKModel_GetAnimation(this->unk80->unk8)->SetCustomMatrix(index, &sp110, (AnimationMatrixPosition) 2, 0);
    sp90.SetIdentity();
    sp90.SetRotationYaw(this->unk24C);
    spD0.SetIdentity();
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp40 = MKModel_GetAnimation(this->unk80->unk8)->GetNodeOrigin(desc->unk184);
    sp50.unk0 = -sp40.unk0;
    sp50.unk4 = -sp40.unk4;
    sp50.unk8 = -sp40.unk8;
    spD0.Translate(&spD0, sp50);
    spD0.Multiply(&spD0, &sp90);
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp30 = MKModel_GetAnimation(this->unk80->unk8)->GetNodeOrigin(desc->unk184);
    spD0.Translate(&spD0, sp30);
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    index = desc->unk184;
    MKModel_GetAnimation(this->unk80->unk8)->SetCustomMatrix(index, &spD0, (AnimationMatrixPosition) 2, 0);
    Shatterable::Draw();
}

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
            sp48 = Tools_CalculateVelocity(this->unk1F8, *(this + ((this->unk228 * 0x10) + 0x1A8)), 5000.0f, -1960.0f);
            M2C_FIELD(this, MKVector3 *, 0x218) = sp48;
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
                this->unk240 = (void *) (Projectile::CreateInstance((ProjectileType) 8));
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

f32 LavaCannon::Resolve() {
    LavaCannonDescriptor *desc;

    Shatterable::Resolve();
    desc = checked_cast<LavaCannonDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk208.Init((AnimEventDesc *) ((u8 *) desc + 0x1A4));
    MKModel_GetAnimation(this->unk80->unk8)->EnableCustomMatrices(1);
}

s32 LavaCannon::LoadDone() {
    Matrix sp70;
    Matrix sp30;
    MKVector3 sp20;

    Shatterable::LoadDone();
    this->unk244 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x54);
    M2C_STRUCT_COPY(&sp70, (const void *) MKModel_GetWorldMatrix(this->unk4), 0x40);
    sp20.unk0 = 0.0f;
    sp20.unk4 = 0.0f;
    sp20.unk8 = 0.0f;
    sp70.SetRotationPYR(sp20);
    MKModel_SetWorldMatrix(this->unk4, sp70);
    M2C_STRUCT_COPY(&sp30, (const void *) MKModel_GetWorldMatrix(this->unk4), 0x40);
    sp30.Scale3x3(&sp30, *(MKVector3 *) ((s8 *) &MKProp::loadInfo + 0x60));
    MKModel_SetWorldMatrix(this->unk4, sp30);
}

s32 LavaCannon::LoadLine(MKIniLine *arg0) {
    MKVector3 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    s32 var_r29_1272;

    if (arg0->IsField("LavaCannonTarget_01") != 0) {
        sp28 = ((MKIniLine *) (arg0->unkC->GetSubLine(arg0)))->GetVector3(0);
        *(MKVector3 *) &this->unk1A8 = sp28;
    } else if (arg0->IsField("LavaCannonTarget_02") != 0) {
        sp18 = ((MKIniLine *) (arg0->unkC->GetSubLine(arg0)))->GetVector3(0);
        *(MKVector3 *) &this->unk1B8 = sp18;
    } else if (arg0->IsField("LavaCannonTarget_03") != 0) {
        sp8 = ((MKIniLine *) (arg0->unkC->GetSubLine(arg0)))->GetVector3(0);
        *(MKVector3 *) &this->unk1C8 = sp8;
    }
    var_r29_1272 = 0;
    if ((Shatterable::LoadLine(arg0) != 0) || (arg0->LoadFloat("SpeedMultiplier", &this->unk258, 0) != 0)) {
        var_r29_1272 = 1;
    }
    return var_r29_1272;
}

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

void LavaCannonDescriptor::LoadDone() {
    MKAnimScript *anims;
    void *anim;

    ShatterableDescriptor::LoadDone();
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    M2C_FIELD(this, s32 *, 0x16C) = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    this->unk170 = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    this->unk174 = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("firing") != 0) {
        anim = anims->GetAnim("firing");
    } else {
        anim = NULL;
    }
    this->unk178 = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("exploding") != 0) {
        anim = anims->GetAnim("exploding");
    } else {
        anim = NULL;
    }
    this->unk17C = (s32) anim;
    anims = (MKAnimScript *) this->unk34;
    if (anims->Exists("idle") != 0) {
        anim = anims->GetAnim("idle");
    } else {
        anim = NULL;
    }
    this->unk180 = (s32) anim;
    this->unk184 = MKModel_GetAnimation(((MKAnimScript *) this->unk34)->unk8)->GetNodeIndex("z_yaw");
    this->unk188 = MKModel_GetAnimation(((MKAnimScript *) this->unk34)->unk8)->GetNodeIndex("z_pitch");
    this->unk18C = MKModel_GetAnimation(((MKAnimScript *) this->unk34)->unk8)->GetNodeIndex("z_barrel1");
    this->unk190 = MKModel_GetRefPointIndex(this->unk2C, "r_emitter");
    this->unk19C = (s32) checked_cast<Explosion4 *, MKProp>(gMK->CreateProp("Explosion4"));
    this->unk1AC.unk0 = (s8 *) "fire";
    this->unk1B4 = (s8 *) "firesound";
}

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

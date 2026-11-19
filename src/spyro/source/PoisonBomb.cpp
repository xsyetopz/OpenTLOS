#include "spyro/source/PoisonBomb.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExpShock.h"
#include "spyro/source/ExpSmokeAndFlamesPS.h"
#include "spyro/source/Explosion3.h"
#include "spyro/source/ExplosionFX.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDFaderObject.h"
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
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PoisonBombExtra1;
extern s32 GS_PoisonBombExtra2;
extern s32 GS_PoisonBombSmokeLP;
extern s32 GS_SpyroDeathBreath;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pPoisonBombDescriptor;
static f32 fTexScale = 0.95f;
static f32 fScaleMul = 0.5f;

void PoisonBomb::EmitPoison() {

}

void PoisonBomb::EmitPoisonTrail() {
    MKVector3 sp58;
    MKVector3 sp68;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 *temp_r31_91;

    temp_r31_91 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
    sp48.unk0 = -1.0f;
    sp48.unk4 = 0.0f;
    sp48.unk8 = -1.0f;
    sp38.unk0 = 1.0f;
    sp38.unk4 = 1.0f;
    sp38.unk8 = 1.0f;
    sp58 = KDRand_Vector(sp48, sp38);
    sp68.unk0 = sp58.unk0 * 100.0f;
    sp68.unk4 = sp58.unk4 * 100.0f;
    sp68.unk8 = sp58.unk8 * 100.0f;
    ((HeatDistortPS *) (&gb + 0x240))->Emit(*temp_r31_91, sp68, 1.0f, MKRand_Float((int *) &gViewSeed, 3.0f, 4.0f));
}

void PoisonBomb::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    Projectile::FireAtTarget(arg0, arg1, arg2, arg3, arg4, arg5);
    this->unk140 = 25.0f;
    this->unk180 = 1;
    this->unk18C = 0.0f;
    ((ScreenWobbleFX *) (&gb + 0xB8))->SetMotionBlurCapEnable(1U);
}

void PoisonBomb::Disable() {
    PlatformDetach();
    if ((s32) this->unk180 >= 1) {
        ((ScreenWobbleFX *) (&gb + 0xB8))->SetMotionBlurCapEnable(0U);
    }
    this->unk180 = 0;
    Projectile::Disable();
}

void PoisonBomb::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_201;

    temp_r3_201 = this->unk178;
    if (temp_r3_201 != NULL) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unk150;
        sp14 = 0;
        sp18 = 0;
        temp_r3_201->Message((MKMessage *) &sp8);
        this->unk178 = NULL;
    }
}

void PoisonBomb::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp18;
    u8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_243;

    PlatformDetach();
    if (M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x4000) {
        this->unk178 = arg0;
        temp_r3_243 = this->unk178;
        if (temp_r3_243 != NULL) {
            spC = 0;
            sp8 = 0x23;
            sp10 = &this->unk150;
            sp14 = 0;
            sp18 = arg1;
            temp_r3_243->Message((MKMessage *) &sp8);
            if (sp14 == 0) {
                this->unk178 = NULL;
            }
        }
    }
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionResult'
void PoisonBomb::Collided(MKCollisionResult &arg0) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f28_308;
    f32 temp_f2_339;
    f32 temp_f4_305;
    f64 temp_f0_324;
    f64 temp_f0_342;

    Projectile::Collided(arg0);
    if (((u8) this->unk174 >> 7U) & 1) {
        this->unk14C &= ~0x40;
        return;
    }
    temp_f4_305 = arg0.unk18;
    temp_f28_308 = (M2C_FIELD(this, f32 *, 0xD0) * temp_f4_305) + ((M2C_FIELD(this, f32 *, 0xC8) * arg0.unk10) + (M2C_FIELD(this, f32 *, 0xCC) * arg0.unk14));
    if (temp_f28_308 < 0.0f) {
        sp28 = (f64) M2C_FIELD(&arg0, f32 *, 0x10) * 5.398241246e-315;
        sp30 = temp_f4_305 * 10.0f;
        sp48 = sp28;
        sp50 = (f64) sp30;
        temp_f0_324 = M2C_FIELD(&arg0, f64 *, 0) + sp48;
        sp18 = temp_f0_324;
        sp58 = temp_f0_324;
        sp20 = arg0.unk8 + (f32) sp50;
        sp60 = (f64) sp20;
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp58));
        temp_f2_339 = 2.0f * temp_f28_308;
        temp_f0_342 = (f64) M2C_FIELD(&arg0, f32 *, 0x10) * (f64) temp_f2_339;
        sp8 = temp_f0_342;
        sp38 = temp_f0_342;
        sp10 = arg0.unk18 * temp_f2_339;
        sp40 = (f64) sp10;
        this->unkC8 -= temp_f0_342;
        M2C_FIELD(this, f32 *, 0xD0) = (f32) (M2C_FIELD(this, f32 *, 0xD0) - (f32) sp40);
        this->unkC8 *= 5.222099017e-315;
        M2C_FIELD(this, f32 *, 0xD0) = (f32) (M2C_FIELD(this, f32 *, 0xD0) * 0.5f);
        this->unk168 = 0.75f * -this->unk168;
        this->unk170 += 1;
    }
}
#endif

void PoisonBomb::SetExplodeNearHero(bool arg0, float arg1) {
    this->unk174 = (this->unk174 & ~0x40) | ((arg0 << 6) & 0x40);
    this->unk16C = arg1;
}

void PoisonBomb::SetExplodeOnContact(bool arg0) {
    this->unk174 = (this->unk174 & ~0x80) | ((arg0 << 7) & 0x80);
}

void PoisonBomb::Deactivate() {
    PlatformDetach();
    GameProp::Deactivate();
    this->unk14C &= ~0x80;
    this->unk1C0 = 0;
}

void PoisonBomb::Activate() {
    GameProp::Activate();
}

#if 0 // DRAFT: declaration syntax error
void *PoisonBomb::Update() {
    s8 sp101;
    u8 sp100;
    s32 spFC;
    f32 spF8;
    s32 spF4;
    s8 spF2;
    s8 spF1;
    s8 spF0;
    f64 spE8;                                       /* compiler-managed */
    f64 spE0;                                       /* compiler-managed */
    PoisonBomb *spDC;
    s32 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    s32 spB4;
    s32 spB0;
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
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    MKVector3 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKProp *var_r30_575;
    MKVector3 *temp_r30_829;
    f32 temp_f2_466;
    f32 temp_f4_611;
    f32 var_f0_672;
    f32 var_f0_849;
    f64 temp_f1_702;
    s32 temp_r0_544;
    s32 temp_r3_572;
    u8 temp_r3_563;
    u8 var_r30_505;
    void *temp_r30_696;
    void *temp_r3_701;
    void *temp_r3_818;
    void *temp_r4_693;

    Projectile::Update();
    sp8 = 1;
    ((KDSoundFader *) &this->unk190)->Update(GS_PoisonBombSmokeLP, 1U, this->unk1C0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f2_466 = this->unk1BC;
    if (temp_f2_466 > 0.0f) {
        this->unk1BC = temp_f2_466 - gUpdateTimeDelta;
        if ((this->unk1BC <= 0.0f) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0)) == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x58)(M2C_FIELD(&gb, void ***, 0)) == 0)) {
            var_r30_505 = 0;
            if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r30_505 = 1;
            }
            if (var_r30_505 == 0) {
                KDSound_Play3d(GS_SpyroDeathBreath, M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), s32 *, 8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
    this->unk160 -= gUpdateTimeDelta;
    temp_r0_544 = this->unk180;
    switch (temp_r0_544) {                          /* irregular */
    case 1:
        EmitPoisonTrail();
        if ((s32) this->unk170 >= 5) {
            temp_r3_563 = this->unk14C;
            if ((temp_r3_563 >> 6U) & 1) {
                this->unk14C = temp_r3_563 & ~0x40;
                if (((u8) this->unk128 != 0) && (temp_r3_572 = this->unk120, (((u32) temp_r3_572 == 0U) == 0)) && (var_r30_575 = M2C_FIELD(temp_r3_572, MKProp **, 8), ((var_r30_575 == NULL) == 0))) {

                } else {
                    var_r30_575 = NULL;
                }
                if ((var_r30_575 != NULL) && (M2C_FIELD(var_r30_575->unk0, s32 *, 0xC) & 0x4000) && (var_r30_575 != (MKProp *) this->unk178)) {
                    PlatformDetach();
                    PlatformAttach(var_r30_575, (MKCollisionInfo *) this->unk120);
                }
            }
        }
        if (((u8) this->unk14C >> 6U) & 1) {
            sp58 = 0.0f;
            this->unk164 += this->unk168 * gUpdateTimeDelta;
            temp_f4_611 = this->unk168;
            sp50 = 0.0f;
            this->unk168 = -((0.2f * temp_f4_611 * gUpdateTimeDelta) - temp_f4_611);
            sp54 = this->unk164;
            spA8 = (f64) sp58;
            spA0 = (f64) sp50;
            MKModel_SetRotation(this->unk4, *((MKVector3 *) &spA0));
            return;
        }
        this->unk160 = 1.0f;
        this->unk180 = 2;
        return;
    case 2:
        EmitPoisonTrail();
        this->unk1C0 = 1;
        if (this->unk160 <= 0.0f) {
            this->unk180 = 3;
            this->unk1B8 = KDSound_Play3d(GS_PoisonBombExtra1, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            this->unk160 = 15.0f;
            this->unk188 = 1.5f;
            this->unk1D0 = 2.0f;
            return;
        }
    case 0:
        return;
    case 3:
        this->unk184 -= gUpdateTimeDelta;
        EmitPoison();
        this->unk188 -= gUpdateTimeDelta;
        var_f0_672 = this->unk1D0 - gUpdateTimeDelta;
        if (var_f0_672 < 2.0f) {

        } else {
            var_f0_672 = 2.0f;
        }
        if (var_f0_672 > 0.0f) {

        } else {
            var_f0_672 = 0.0f;
        }
        this->unk1D0 = var_f0_672;
        if (this->unk188 <= 0.0f) {
            temp_r4_693 = this->unk8;
            temp_r30_696 = ((u8 *) temp_r4_693) + 0x30;
            temp_r3_701 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, void *), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_693), void **, 8);
            temp_f1_702 = M2C_FIELD(temp_r3_701, f64 *, 0x30);
            sp80 = temp_f1_702;
            sp88 = M2C_FIELD(temp_r3_701, f64 *, 0x38);
            sp40 = temp_f1_702 - M2C_FIELD(temp_r30_696, f64 *, 0);
            sp90 = sp40;
            sp48 = (f32) sp88 - M2C_FIELD(temp_r30_696, f32 *, 8);
            sp98 = (f64) sp48;
            if ((((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + ((*(f32 *) ((u8 *) &sp90 + 0x4)) * (*(f32 *) ((u8 *) &sp90 + 0x4))))) <= 90000.0f) {
                sp18 = 0.0f;
                sp10 = 0.0f;
                sp14 = 0.0f;
                spB4 = 0;
                sp70 = (f64) sp10;
                sp78 = (f64) sp18;
                spB0 = 7;
                spD8 = 2;
                spDC = this;
                spB8 = (f64) sp10;
                spC0 = (f64) sp18;
                spF0 = 1;
                spFC = 2;
                spF8 = 10.0f;
                spF1 = 0;
                spF2 = 1;
                spF4 = -1;
                spC8 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                spD0 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                sp100 = 0;
                if (this != NULL) {
                    sp30 = GetPos();
                    *(MKVector3 *) &spE0 = sp30;
                } else {
                    spE0 = 0.0f;
                    (*(f32 *) ((u8 *) &spDC + 0x8)) = 0.0f;
                    spE8 = 0.0f;
                }
                sp101 = 0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **), 0xC)(M2C_FIELD(&gb, void ***, 0)), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spB0);
                this->unk188 = 1.5f;
                if (sp100 != 0) {
                    this->unk1BC = 0.75f;
                }
            }
        }
        if (this->unk160 <= 0.0f) {
            M2C_FIELD(M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0xF0), s32 *, 0x68) = (s32) GS_PoisonBombExtra2;
            M2C_FIELD(M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0xF0), s32 *, 0x6C) = 0;
            temp_r3_818 = M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0xF0);
            sp28 = 0.0f;
            sp20 = 0.5f;
            sp24 = 0.5f;
            M2C_FIELD(temp_r3_818, s8 *, 0x70) = 0;
            sp68 = (f64) sp28;
            sp60 = (f64) sp20;
            temp_r30_829 = (MKVector3 *) (((u8 *) this->unk8) + 0x30);
            ((Explosion3 *) (M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), Explosion3 **, 0xF0)))->Trigger(*temp_r30_829, 0.25f, 0U, 0U, *((MKVector3 *) &sp60), this->unk130);
            this->unk1C0 = 0;
            KDSound_Stop((int *) &this->unk190);
            this->unk180 = 4;
            this->unk160 = 2.0f;
            return;
        }
        break;
    case 4:
        var_f0_849 = this->unk160;
        if (var_f0_849 < 2.0f) {

        } else {
            var_f0_849 = 2.0f;
        }
        if (var_f0_849 > 0.0f) {

        } else {
            var_f0_849 = 0.0f;
        }
        this->unk160 = var_f0_849;
        if (this->unk160 <= 0.0f) {
            Disable();
        }
        break;
    }
}
#endif

void PoisonBomb::SetInitialState() {

}

void PoisonBomb::Reset() {
    Projectile::Reset();
    this->unk170 = 0;
    this->unk160 = 1.0f;
    this->unk164 = 0.0f;
    this->unk168 = 12.566371f;
    this->unk174 &= ~0x80;
    this->unk174 &= ~0x40;
    PlatformDetach();
    this->unk17C = 0.0f;
    this->unk180 = 0;
    this->unk184 = 0.0f;
    KDSound_Stop((int *) &this->unk1B8);
    this->unk1C0 = 0;
    KDSound_Stop((int *) &this->unk190);
}

PoisonBomb *PoisonBomb::CreateInstance() {
    PoisonBomb *temp_r3_943;

    if ((MKPropDescriptor *) pPoisonBombDescriptor != NULL) {
        temp_r3_943 = checked_cast<PoisonBomb *, MKProp>(pPoisonBombDescriptor->CreateInstance());
        if (temp_r3_943 != NULL) {
            ((KDSoundFader *) &temp_r3_943->unk190)->Init(1.0f, 0.25f);
            temp_r3_943->Reset();
            temp_r3_943->SetInitialState();
            return temp_r3_943;
        }
    }
    return NULL;
}

#if 0 // DRAFT: undefined identifier 'PlatformMoveMsg'
void PoisonBomb::Message(MKMessage *arg0) {
    Matrix sp10;
    M2C_UNK spC;
    s32 temp_r0_983;
    void *temp_r31_993;
    void *temp_r3_1014;

    ((KDSoundPlayer *) &this->unk190)->Message(arg0);
    temp_r0_983 = arg0->unk0;
    switch (temp_r0_983) {                          /* irregular */
    case 34:
        temp_r31_993 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
        M2C_STRUCT_COPY((s32) &spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        sp10.Multiply3x3(&sp10, M2C_FIELD(temp_r31_993, Matrix **, 0x10));
        sp10.Multiply3x3(&sp10, M2C_FIELD(temp_r31_993, Matrix **, 0x14));
        temp_r3_1014 = M2C_FIELD(temp_r31_993, void **, 8);
        sp10.unk30 = M2C_FIELD(temp_r3_1014, f32 *, 0);
        sp10.unk34 = M2C_FIELD(temp_r3_1014, f32 *, 4);
        sp10.unk38 = M2C_FIELD(temp_r3_1014, f32 *, 8);
        sp10.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp10);
        break;
    case 38:
        PlatformDetach();
        break;
    }
    Projectile::Message(arg0);
}
#endif

void PoisonBomb::Deinit() {
    PlatformDetach();
    KDSound_Stop((int *) &this->unk190);
    KDSound_Stop((int *) &this->unk1B8);
    MKModel_Destroy(this->unk1C4);
    if ((s32) this->unk180 >= 1) {
        ((ScreenWobbleFX *) (&gb + 0xB8))->SetMotionBlurCapEnable(0U);
    }
    this->unk180 = 0;
    Projectile::Deinit();
}

void PoisonBomb::Draw() {
    Matrix sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;                                       /* compiler-managed */
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
    f32 sp54;
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
    f32 temp_f10_1403;
    f32 temp_f11_1402;
    f32 temp_f12_1397;
    f32 temp_f1_1150;
    f32 temp_f29_1134;
    f32 temp_f29_1143;
    f32 temp_f30_1144;
    f32 temp_f31_1135;
    f32 temp_f4_1288;
    f32 temp_f5_1286;
    f32 temp_f6_1291;
    f32 temp_f9_1406;
    f32 var_f0_1169;
    f32 var_f3_1386;
    f32 var_f4_1216;
    f32 var_f4_1319;
    f32 var_f6_1195;
    f64 temp_f1_1221;
    f64 temp_f1_1227;
    f64 temp_f1_1231;
    f64 temp_f1_1325;
    f64 temp_f1_1331;
    f64 temp_f1_1335;
    s32 temp_r0_1188;
    s32 temp_r3_1250;
    s32 temp_r3_1354;
    s32 var_r0_1260;
    s32 var_r0_1364;
    void *temp_r3_1435;
    void *temp_r4_1201;

    if ((s32) this->unk180 != 4) {
        Projectile::Draw();
    }
    if ((u8) M2C_FIELD(&gb, u8 *, 0x118) != 0) {
        this->unk1C8 += 6.2831855f * gUpdateTimeDelta * MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
        M2C_STRUCT_COPY((s32) &sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        temp_f29_1134 = (fTexScale - 1.0f) * fScaleMul;
        temp_f31_1135 = -((this->unk1D0 * 0.5f) - 1.0f);
        sp110.Scale3x3(&sp110, fTexScale);
        temp_f29_1143 = 0.0f - temp_f29_1134;
        temp_f30_1144 = (0.005f * _table_sinf(1.5707964f + this->unk1C8)) + temp_f29_1143;
        temp_f1_1150 = (0.005f * _table_sinf(this->unk1C8)) + temp_f29_1143;
        sp40 = 0.0f;
        sp38 = temp_f1_1150;
        sp3C = temp_f30_1144;
        sp90 = (f64) sp40;
        sp88 = (f64) sp38;
        sp110.unk30 = (f32) sp88;
        sp110.unk34 = (*(f32 *) ((u8 *) &sp88 + 0x4));
        sp110.unk38 = (f32) sp90;
        sp110.unk3C = 1.0f;
        MKMaterial_SetTextureMatrix(this->unk1CC, &sp110);
        var_f0_1169 = 1.0f;
        if ((s32) this->unk180 == 4) {
            var_f0_1169 = this->unk160 * 0.5f;
        }
        sp54 = var_f0_1169;
        sp50 = 1.0f;
        sp48 = 1.0f;
        sp4C = 1.0f;
        sp80 = (f64) sp50;
        sp78 = (f64) sp48;
        MKMaterial_SetColor(this->unk1CC, *((MKVector4 *) &sp78));
        temp_r0_1188 = this->unk180;
        if ((temp_r0_1188 == 3) || (temp_r0_1188 == 4)) {
            var_f6_1195 = 0.0f;
            temp_r4_1201 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            spB8 = M2C_FIELD(temp_r4_1201, f64 *, 0x20);
            spC0 = M2C_FIELD(temp_r4_1201, f64 *, 0x28);
            sp98 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            spA0 = M2C_FIELD(&MKVector3::up, f64 *, 8);
            (*(f32 *) ((u8 *) &spA0 + 0x1c)) = 0.0f;
            var_f4_1216 = ((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + (0.0f * 0.0f));
            if (var_f4_1216 > 0.000001f) {
                if (var_f4_1216 > 0.0f) {
                    temp_f1_1221 = __frsqrte(var_f4_1216);
                    temp_f1_1227 = 0.5 * temp_f1_1221 * -(((f64) var_f4_1216 * (temp_f1_1221 * temp_f1_1221)) - 3.0);
                    temp_f1_1231 = 0.5 * temp_f1_1227 * -(((f64) var_f4_1216 * (temp_f1_1227 * temp_f1_1227)) - 3.0);
                    var_f4_1216 = (f32) ((f64) var_f4_1216 * (0.5 * temp_f1_1231 * -(((f64) var_f4_1216 * (temp_f1_1231 * temp_f1_1231)) - 3.0)));
                } else if (var_f4_1216 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1216 = __float_nan;
                } else {
                    sp14 = var_f4_1216;
                    temp_r3_1250 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_1250) {         /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1260 = 1;
                        } else {
                            var_r0_1260 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_1260 = 5;
                        } else {
                            var_r0_1260 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_1260 = 4;
                        break;
                    }
                    if (var_r0_1260 == 1) {
                        var_f4_1216 = __float_nan;
                    }
                }
                var_f6_1195 = 1.0f / var_f4_1216;
            }
            temp_f5_1286 = (*(f32 *) ((u8 *) &spA0 + 0x1c)) * var_f6_1195;
            temp_f4_1288 = (f32) spC0 * var_f6_1195;
            temp_f6_1291 = (f32) spB8 * var_f6_1195;
            spB8 = temp_f6_1291;
            (*(f32 *) ((u8 *) &spA0 + 0x1c)) = temp_f5_1286;
            spC0 = temp_f4_1288;
            sp28 = ((*(f32 *) ((u8 *) &sp98 + 0x4)) * temp_f4_1288) - ((f32) spA0 * temp_f5_1286);
            sp2C = ((f32) spA0 * temp_f6_1291) - ((f32) sp98 * temp_f4_1288);
            sp30 = ((f32) sp98 * temp_f5_1286) - ((*(f32 *) ((u8 *) &sp98 + 0x4)) * temp_f6_1291);
            spA8 = (f64) sp28;
            spB0 = (f64) sp30;
            sp68 = (f64) sp28;
            sp70 = (f64) sp30;
            var_f4_1319 = ((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA0 + 0xc)) * (*(f32 *) ((u8 *) &spA0 + 0xc))));
            if (var_f4_1319 > 0.000001f) {
                if (var_f4_1319 > 0.0f) {
                    temp_f1_1325 = __frsqrte(var_f4_1319);
                    temp_f1_1331 = 0.5 * temp_f1_1325 * -(((f64) var_f4_1319 * (temp_f1_1325 * temp_f1_1325)) - 3.0);
                    temp_f1_1335 = 0.5 * temp_f1_1331 * -(((f64) var_f4_1319 * (temp_f1_1331 * temp_f1_1331)) - 3.0);
                    var_f4_1319 = (f32) ((f64) var_f4_1319 * (0.5 * temp_f1_1335 * -(((f64) var_f4_1319 * (temp_f1_1335 * temp_f1_1335)) - 3.0)));
                } else if (var_f4_1319 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1319 = __float_nan;
                } else {
                    sp10 = var_f4_1319;
                    temp_r3_1354 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_1354) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1364 = 1;
                        } else {
                            var_r0_1364 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_1364 = 5;
                        } else {
                            var_r0_1364 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1364 = 4;
                        break;
                    }
                    if (var_r0_1364 == 1) {
                        var_f4_1319 = __float_nan;
                    }
                }
                var_f3_1386 = 1.0f / var_f4_1319;
            } else {
                var_f3_1386 = 0.0f;
            }
            temp_f12_1397 = (10.0f * temp_f31_1135) + 0.25f;
            temp_f11_1402 = (f32) spA8 * var_f3_1386;
            temp_f10_1403 = (*(f32 *) ((u8 *) &spA0 + 0xc)) * var_f3_1386;
            sp20 = temp_f12_1397;
            temp_f9_1406 = (f32) spB0 * var_f3_1386;
            sp18 = temp_f12_1397;
            sp1C = (6.0f * temp_f31_1135) + 0.25f;
            spA8 = temp_f11_1402;
            (*(f32 *) ((u8 *) &spA0 + 0xc)) = temp_f10_1403;
            spB0 = temp_f9_1406;
            spD0 = temp_f11_1402;
            spD4 = temp_f10_1403;
            spD8 = temp_f9_1406;
            spDC = 0.0f;
            spE0 = (f32) sp98;
            spE4 = (*(f32 *) ((u8 *) &sp98 + 0x4));
            spE8 = (f32) spA0;
            spEC = 0.0f;
            spF0 = spB8;
            spF4 = (*(f32 *) ((u8 *) &spA0 + 0x1c));
            spF8 = spC0;
            spFC = 0.0f;
            sp58 = (f64) sp18;
            sp60 = (f64) sp20;
            ((Matrix *) &spD0)->Scale3x3((Matrix *) &spD0, *((MKVector3 *) &sp58));
            temp_r3_1435 = this->unk8;
            sp100 = M2C_FIELD(temp_r3_1435, f32 *, 0x30);
            sp104 = M2C_FIELD(temp_r3_1435, f32 *, 0x34);
            sp108 = M2C_FIELD(temp_r3_1435, f32 *, 0x38);
            sp10C = 1.0f;
            MKModel_SetWorldMatrix(this->unk1C4, *((Matrix *) &spD0));
            MKModel_Draw(this->unk1C4, NULL);
        }
    }
}

void PoisonBomb::Init() {
    Projectile::Init();
    this->unk170 = 0;
    this->unk160 = 1.0f;
    this->unk164 = 0.0f;
    this->unk168 = 12.566371f;
    this->unk174 &= ~0x80;
    this->unk174 &= ~0x40;
    this->unk178 = NULL;
    M2C_FIELD(this, PoisonBomb **, 0x150) = this;
    this->unk18C = 0.0f;
    this->unk1B8 = 0;
    ((KDSoundFader *) &this->unk190)->Init(0.25f, 0.25f);
    this->unk1C4 = MKModel_Create("FX0042_GasBlur", NULL, 2, NULL);
    this->unk1C8 = 0.0f;
    this->unk1CC = Tools_GetMatchingMaterial(this->unk1C4, "fx_gasblur");
}

void PoisonBombDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkF0 = (long) (checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3")));
    pPoisonBombDescriptor = (MKPropDescriptor *) this;
    this->unkF4 = MKModel_GetRefPointIndex(this->unk2C, "r_fxemit0");
}

void PoisonBombDescriptor::Deinit() {
    pPoisonBombDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}

void PoisonBombDescriptor::Init() {
    ProjectileDescriptor::Init();
    this->unkF4 = -1;
}

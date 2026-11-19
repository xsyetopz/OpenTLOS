#include "spyro/source/PoisonBomb.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Explosion3.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "unplaced_templates.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
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

#if 0 // DRAFT: illegal type
void PoisonBomb::EmitPoisonTrail() {
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
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
    f32 sp10;
    MKVector3 *temp_r31_91;

    sp30 = -1.0f;
    sp20 = 1.0f;
    temp_r31_91 = this->unk8 + 0x30;
    sp28 = -1.0f;
    sp2C = 0.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp48 = (f64) sp28;
    sp50 = (f64) sp30;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    KDRand_Vector(sp58, *((MKVector3 *) &sp48));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp68 = sp8;
    sp10 = sp58.unk8 * 100.0f;
    sp70 = (f64) sp10;
    ((HeatDistortPS *) (&gb + 0x240))->Emit(*temp_r31_91, *((MKVector3 *) &sp68), 1.0f, MKRand_Float(&gViewSeed, 3.0f, 4.0f));
}
#endif

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

#if 0 // DRAFT: undefined identifier 'unk150'
void PoisonBomb::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    M2C_UNK *sp10;
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
        M2C_FIELD(temp_r3_201->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x24, 0);
        this->unk178 = NULL;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk150'
void PoisonBomb::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp18;
    u8 sp14;
    M2C_UNK *sp10;
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
            M2C_FIELD(temp_r3_243->__vptr, M2C_UNK (**)(s32 *, M2C_UNK, M2C_UNK), 0x2C)(&sp8, 0x23, 0);
            if (sp14 == 0) {
                this->unk178 = NULL;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionResult'
void PoisonBomb::Collided(MKCollisionResult &arg0) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f28_308;
    f32 temp_f4_305;

    Projectile::Collided(arg0);
    if (((u8) this->unk174 >> 7U) & 1) {
        this->unk14C &= ~0x40;
        return;
    }
    temp_f4_305 = arg0.unk18;
    temp_f28_308 = (M2C_FIELD(this, f32 *, 0xD0) * temp_f4_305) + ((M2C_FIELD(this, f32 *, 0xC8) * arg0.unk10) + (M2C_FIELD(this, f32 *, 0xCC) * arg0.unk14));
    if (temp_f28_308 < 0.0f) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp30 = temp_f4_305 * 10.0f;
        sp48 = sp28;
        sp50 = (f64) sp30;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        sp58 = sp18;
        sp20 = arg0.unk8 + (f32) sp50;
        sp60 = (f64) sp20;
        MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp58));
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        sp38 = sp8;
        sp10 = arg0.unk18 * (2.0f * temp_f28_308);
        sp40 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_FIELD(this, f32 *, 0xD0) = (f32) (M2C_FIELD(this, f32 *, 0xD0) - (f32) sp40);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
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

#if 0 // DRAFT: expression syntax error
void PoisonBomb::Update() {
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
    f64 sp30;
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
    s32 temp_r0_544;
    s32 temp_r3_572;
    u8 temp_r3_563;
    u8 var_r30_505;
    void *temp_r3_701;
    void *temp_r3_818;
    void *temp_r4_693;

    Projectile::Update();
    sp8 = 1;
    this->unk190.Update(GS_PoisonBombSmokeLP, 1U, this->unk1C0, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f2_466 = this->unk1BC;
    if (temp_f2_466 > 0.0f) {
        this->unk1BC = temp_f2_466 - gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((this->unk1BC == 0.0f) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x54)(M2C_FIELD(&gb, void ***, 0)) == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x60)(M2C_FIELD(&gb, void ***, 0)) == 0) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(void **), 0x58)(M2C_FIELD(&gb, void ***, 0)) == 0)) {
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
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk160 == 0.0f) {
            this->unk180 = 3;
            this->unk1B8 = KDSound_Play3d(GS_PoisonBombExtra1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
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
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk188 == 0.0f) {
            temp_r4_693 = this->unk8;
            temp_r3_701 = M2C_FIELD(M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), void *(**)(void **, void *), 0xC)(M2C_FIELD(&gb, void ***, 0), temp_r4_693), void **, 8);
            sp80 = M2C_FIELD(temp_r3_701, f64 *, 0x30);
            sp88 = M2C_FIELD(temp_r3_701, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp90 = sp40;
            sp48 = (f32) sp88 - M2C_FIELD((temp_r4_693 + 0x30), f32 *, 8);
            sp98 = (f64) sp48;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + (unksp94 * unksp94))) == 90000.0f) {
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
                spC8 = M2C_FIELD(&one, f64 *, 0);
                spD0 = M2C_FIELD(&one, f64 *, 8);
                sp100 = 0;
                if (this != NULL) {
                    sp30.GetPos();
                    spE0 = sp30;
                    spE8 = sp38;
                } else {
                    spE0 = 0.0f;
                    unkspE4 = 0.0f;
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
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk160 == 0.0f) {
            M2C_FIELD(M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0xF0), s32 *, 0x68) = (s32) GS_PoisonBombExtra2;
            M2C_FIELD(M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0xF0), s32 *, 0x6C) = 0;
            temp_r3_818 = M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0xF0);
            sp28 = 0.0f;
            sp20 = 0.5f;
            sp24 = 0.5f;
            M2C_FIELD(temp_r3_818, s8 *, 0x70) = 0;
            sp68 = (f64) sp28;
            sp60 = (f64) sp20;
            temp_r30_829 = this->unk8 + 0x30;
            ((Explosion3 *) (M2C_FIELD(checked_cast<PoisonBombDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), Explosion3 **, 0xF0)))->Trigger(*temp_r30_829, 0.25f, 0U, 0U, *((MKVector3 *) &sp60), this->unk130);
            this->unk1C0 = 0;
            KDSound_Stop(&this->unk190);
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
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk160 == 0.0f) {
            Disable();
        }
        break;
    }
}
#endif

void PoisonBomb::SetInitialState() {

}

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
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
    KDSound_Stop(&this->unk1B8);
    this->unk1C0 = 0;
    KDSound_Stop(&this->unk190);
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
PoisonBomb *PoisonBomb::CreateInstance() {
    PoisonBomb *temp_r3_943;

    if ((MKPropDescriptor *) pPoisonBombDescriptor != NULL) {
        temp_r3_943 = checked_cast<PoisonBomb *, MKProp>(pPoisonBombDescriptor->CreateInstance());
        if (temp_r3_943 != NULL) {
            temp_r3_943->unk190.Init(1.0f, 0.25f);
            temp_r3_943->Reset();
            temp_r3_943->SetInitialState();
            return temp_r3_943;
        }
    }
    return NULL;
}
#endif

#if 0 // DRAFT: expression syntax error
void PoisonBomb::Message(MKMessage *arg0) {
    s32 temp_r0_983;
    void *temp_r31_993;
    void *temp_r3_1014;
    this->unk190.Message(arg0);
    temp_r0_983 = arg0->unk0;
    switch (temp_r0_983) {                          /* irregular */
    case 34:
        temp_r31_993 = checked_cast<PlatformMoveMsg *, MKMessage>(arg0);
        M2C_STRUCT_COPY((s32) &arg_spC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        arg_sp10.Multiply3x3((Matrix *) &arg_sp10, M2C_FIELD(temp_r31_993, Matrix **, 0x10));
        arg_sp10.Multiply3x3((Matrix *) &arg_sp10, M2C_FIELD(temp_r31_993, Matrix **, 0x14));
        temp_r3_1014 = M2C_FIELD(temp_r31_993, void **, 8);
        arg_sp40 = M2C_FIELD(temp_r3_1014, f32 *, 0);
        arg_sp44 = M2C_FIELD(temp_r3_1014, f32 *, 4);
        arg_sp48 = M2C_FIELD(temp_r3_1014, f32 *, 8);
        arg_sp4C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp10));
        break;
    case 38:
        PlatformDetach();
        break;
    }
    Projectile::Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Stop(long *)' does not match
void PoisonBomb::Deinit() {
    PlatformDetach();
    KDSound_Stop(&this->unk190);
    KDSound_Stop(&this->unk1B8);
    MKModel_Destroy(this->unk1C4);
    if ((s32) this->unk180 >= 1) {
        ((ScreenWobbleFX *) (&gb + 0xB8))->SetMotionBlurCapEnable(0U);
    }
    this->unk180 = 0;
    Projectile::Deinit();
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void PoisonBomb::Draw() {
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
        this->unk1C8 += 6.2831855f * gUpdateTimeDelta * MKRand_Float(&gViewSeed, 0.1f, 1.0f);
        M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&identity - 4) + 4, 0x40);
        temp_f29_1134 = (fTexScale - 1.0f) * fScaleMul;
        temp_f31_1135 = -((this->unk1D0 * 0.5f) - 1.0f);
        arg_sp110.Scale3x3((Matrix *) &arg_sp110, fTexScale);
        temp_f29_1143 = 0.0f - temp_f29_1134;
        temp_f30_1144 = (0.005f * _table_sinf(1.5707964f + this->unk1C8)) + temp_f29_1143;
        temp_f1_1150 = (0.005f * _table_sinf(this->unk1C8)) + temp_f29_1143;
        arg_sp40 = 0.0f;
        arg_sp38 = temp_f1_1150;
        arg_sp3C = temp_f30_1144;
        arg_sp90 = (f64) arg_sp40;
        arg_sp88 = (f64) arg_sp38;
        arg_sp140 = (f32) arg_sp88;
        arg_sp144 = arg_sp8C;
        arg_sp148 = (f32) arg_sp90;
        arg_sp14C = 1.0f;
        MKMaterial_SetTextureMatrix(this->unk1CC, (Matrix *) &arg_sp110);
        var_f0_1169 = 1.0f;
        if ((s32) this->unk180 == 4) {
            var_f0_1169 = this->unk160 * 0.5f;
        }
        arg_sp54 = var_f0_1169;
        arg_sp50 = 1.0f;
        arg_sp48 = 1.0f;
        arg_sp4C = 1.0f;
        arg_sp80 = (f64) arg_sp50;
        arg_sp78 = (f64) arg_sp48;
        MKMaterial_SetColor(this->unk1CC, *((MKVector4 *) &arg_sp78));
        temp_r0_1188 = this->unk180;
        if ((temp_r0_1188 == 3) || (temp_r0_1188 == 4)) {
            var_f6_1195 = 0.0f;
            temp_r4_1201 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            arg_spB8 = M2C_FIELD(temp_r4_1201, f64 *, 0x20);
            arg_spC0 = M2C_FIELD(temp_r4_1201, f64 *, 0x28);
            arg_sp98 = M2C_FIELD(&up, f64 *, 0);
            arg_spA0 = M2C_FIELD(&up, f64 *, 8);
            arg_spBC = 0.0f;
            var_f4_1216 = ((f32) arg_spC0 * (f32) arg_spC0) + (((f32) arg_spB8 * (f32) arg_spB8) + (0.0f * 0.0f));
            if (var_f4_1216 > 0.000001f) {
                if (var_f4_1216 > 0.0f) {
                    temp_f1_1221 = __frsqrte(var_f4_1216);
                    temp_f1_1227 = 0.5 * temp_f1_1221 * -(((f64) var_f4_1216 * (temp_f1_1221 * temp_f1_1221)) - 3.0);
                    temp_f1_1231 = 0.5 * temp_f1_1227 * -(((f64) var_f4_1216 * (temp_f1_1227 * temp_f1_1227)) - 3.0);
                    var_f4_1216 = (f32) ((f64) var_f4_1216 * (0.5 * temp_f1_1231 * -(((f64) var_f4_1216 * (temp_f1_1231 * temp_f1_1231)) - 3.0)));
                } else if (var_f4_1216 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1216 = __float_nan;
                } else {
                    arg_sp14 = var_f4_1216;
                    temp_r3_1250 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                    switch (temp_r3_1250) {         /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                            var_r0_1260 = 1;
                        } else {
                            var_r0_1260 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
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
            temp_f5_1286 = arg_spBC * var_f6_1195;
            temp_f4_1288 = (f32) arg_spC0 * var_f6_1195;
            temp_f6_1291 = (f32) arg_spB8 * var_f6_1195;
            arg_spB8 = temp_f6_1291;
            arg_spBC = temp_f5_1286;
            arg_spC0 = temp_f4_1288;
            arg_sp28 = (arg_sp9C * temp_f4_1288) - ((f32) arg_spA0 * temp_f5_1286);
            arg_sp2C = ((f32) arg_spA0 * temp_f6_1291) - ((f32) arg_sp98 * temp_f4_1288);
            arg_sp30 = ((f32) arg_sp98 * temp_f5_1286) - (arg_sp9C * temp_f6_1291);
            arg_spA8 = (f64) arg_sp28;
            arg_spB0 = (f64) arg_sp30;
            arg_sp68 = (f64) arg_sp28;
            arg_sp70 = (f64) arg_sp30;
            var_f4_1319 = ((f32) arg_spB0 * (f32) arg_spB0) + (((f32) arg_spA8 * (f32) arg_spA8) + (arg_spAC * arg_spAC));
            if (var_f4_1319 > 0.000001f) {
                if (var_f4_1319 > 0.0f) {
                    temp_f1_1325 = __frsqrte(var_f4_1319);
                    temp_f1_1331 = 0.5 * temp_f1_1325 * -(((f64) var_f4_1319 * (temp_f1_1325 * temp_f1_1325)) - 3.0);
                    temp_f1_1335 = 0.5 * temp_f1_1331 * -(((f64) var_f4_1319 * (temp_f1_1331 * temp_f1_1331)) - 3.0);
                    var_f4_1319 = (f32) ((f64) var_f4_1319 * (0.5 * temp_f1_1335 * -(((f64) var_f4_1319 * (temp_f1_1335 * temp_f1_1335)) - 3.0)));
                } else if (var_f4_1319 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1319 = __float_nan;
                } else {
                    arg_sp10 = var_f4_1319;
                    temp_r3_1354 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_1354) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_1364 = 1;
                        } else {
                            var_r0_1364 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
            temp_f11_1402 = (f32) arg_spA8 * var_f3_1386;
            temp_f10_1403 = arg_spAC * var_f3_1386;
            arg_sp20 = temp_f12_1397;
            temp_f9_1406 = (f32) arg_spB0 * var_f3_1386;
            arg_sp18 = temp_f12_1397;
            arg_sp1C = (6.0f * temp_f31_1135) + 0.25f;
            arg_spA8 = temp_f11_1402;
            arg_spAC = temp_f10_1403;
            arg_spB0 = temp_f9_1406;
            arg_spD0 = temp_f11_1402;
            arg_spD4 = temp_f10_1403;
            arg_spD8 = temp_f9_1406;
            arg_spDC = 0.0f;
            arg_spE0 = (f32) arg_sp98;
            arg_spE4 = arg_sp9C;
            arg_spE8 = (f32) arg_spA0;
            arg_spEC = 0.0f;
            arg_spF0 = (f32) arg_spB8;
            arg_spF4 = arg_spBC;
            arg_spF8 = (f32) arg_spC0;
            arg_spFC = 0.0f;
            arg_sp58 = (f64) arg_sp18;
            arg_sp60 = (f64) arg_sp20;
            arg_spD0.Scale3x3((Matrix *) &arg_spD0, *((MKVector3 *) &arg_sp58));
            temp_r3_1435 = this->unk8;
            arg_sp100 = M2C_FIELD(temp_r3_1435, f32 *, 0x30);
            arg_sp104 = M2C_FIELD(temp_r3_1435, f32 *, 0x34);
            arg_sp108 = M2C_FIELD(temp_r3_1435, f32 *, 0x38);
            arg_sp10C = 1.0f;
            MKModel_SetWorldMatrix(this->unk1C4, *((Matrix *) &arg_spD0));
            MKModel_Draw(this->unk1C4, NULL);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
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
    this->unk190.Init(0.25f, 0.25f);
    this->unk1C4 = MKModel_Create("FX0042_GasBlur", NULL, 2, NULL);
    this->unk1C8 = 0.0f;
    this->unk1CC = Tools_GetMatchingMaterial(this->unk1C4, "fx_gasblur");
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void PoisonBombDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkF0 = checked_cast<Explosion3 *, MKProp>(gMK->CreateProp("Explosion3"));
    pPoisonBombDescriptor = (MKPropDescriptor *) this;
    this->unkF4 = MKModel_GetRefPointIndex(this->unk2C, "r_fxemit0");
}
#endif

void PoisonBombDescriptor::Deinit() {
    pPoisonBombDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}

void PoisonBombDescriptor::Init() {
    ProjectileDescriptor::Init();
    this->unkF4 = -1;
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<PoisonBomb *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<PoisonBombDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

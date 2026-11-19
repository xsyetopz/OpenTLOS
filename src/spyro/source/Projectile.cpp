#include "spyro/source/Projectile.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDProp.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void Projectile::SetAttachment(MKAttachment *arg0) {
    Matrix sp90;
    Matrix sp50;
    M2C_UNK sp4C;
    M2C_UNK spC;
    MKAttachment *temp_r3_58;

    this->unk13C = arg0;
    if (((MKAttachment *) this->unk13C != NULL) && ((MKModel *) this->unk4 != NULL)) {
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp50.unk3C + 4, (s32) &spC + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp4C + 4, (s32) &spC + 4, 0x40);
        temp_r3_58 = this->unk13C;
        MKModel_GetRefPointMatrix((MKModel *) temp_r3_58->unk0, M2C_FIELD(temp_r3_58, s32 *, 4) & 0x0FFFFFFF, &sp50, 1U);
        sp90.Multiply(&sp90, &sp50);
        MKModel_SetWorldMatrix(this->unk4, sp50);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Projectile::Disable() {
    Projectile *spC;
    s32 sp8;
    MKProp *temp_r3_90;

    KDProp::Disable();
    temp_r3_90 = this->unk130;
    if (temp_r3_90 != NULL) {
        spC = NULL;
        sp8 = 0x4E;
        spC = this;
        M2C_FIELD(temp_r3_90->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        this->unk130 = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal type
void Projectile::Collided(MKCollisionResult &arg0) {
    s32 *temp_r3_136;
    s32 temp_r3_125;

    this->unk14C &= ~0x10;
    temp_r3_125 = this->unk148;
    if (temp_r3_125 != 0) {
        KDSound_Play3d(temp_r3_125, this->unk8 + 0x30, (u32) arg0.unk44, -1, 0.0f, 0U);
    }
    temp_r3_136 = this->unk138;
    if (temp_r3_136 != NULL) {
        KDSound_Stop(temp_r3_136);
    }
}
#endif

void Projectile::FireBurstEnd() {

}

void Projectile::FireBurst(MKVector3 *arg0, MKVector3 *arg1, int arg2, int arg3) {

}

#if 0 // DRAFT: type mismatch
s32 Projectile::CreateInstance(ProjectileType arg0) {
    if (this <= 0x15U) {
        switch ((s32) this) {
        case 1:
            return NULL->CreateInstance((s32) &jumptable_847);
        case 2:
            return 1->CreateInstance((s32) &jumptable_847);
        case 3:
            return 2->CreateInstance((s32) &jumptable_847);
        case 4:
            return 3->CreateInstance((s32) &jumptable_847);
        case 5:
            return jumptable_847.CreateInstance();
        case 6:
            return jumptable_847.CreateInstance();
        case 7:
            return jumptable_847.CreateInstance();
        case 8:
            return jumptable_847.CreateInstance();
        case 9:
            return jumptable_847.CreateInstance();
        case 10:
            return jumptable_847.CreateInstance();
        case 11:
            return 2->CreateInstance((s32) &jumptable_847);
        case 12:
            return 1->CreateInstance((s32) &jumptable_847);
        case 13:
            return jumptable_847.CreateInstance();
        case 14:
            return jumptable_847.CreateInstance();
        case 15:
            return jumptable_847.CreateInstance();
        case 16:
            return jumptable_847.CreateInstance();
        case 17:
            return jumptable_847.CreateInstance();
        case 18:
            return jumptable_847.CreateInstance();
        case 19:
            return jumptable_847.CreateInstance();
        case 20:
            return jumptable_847.CreateInstance();
        case 21:
            return jumptable_847.CreateInstance();
        }
    } else {
    case 0:
        return 0;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Projectile::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    MKVector3 sp8;
    MKVector3 *temp_r31_322;
    s32 var_r0_295;

    MKModel_SetPosition(this->unk4, arg0);
    Tools_CalculateVelocity(sp8, arg0, arg2, -1960.0f);
    this->unkC8 = M2C_BITWISE(f64, sp8);
    this->unkD0 = (f64) sp8.unk8;
    this->unk14C |= 0x80;
    this->unk14C |= 0x40;
    this->unk130 = arg3;
    this->unk14C |= 0x10;
    this->unk140 = 10.0f;
    if (arg5 != 0) {
        var_r0_295 = arg5;
    } else {
        var_r0_295 = M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC);
    }
    this->unk148 = var_r0_295;
    if (arg4 != 0) {
        KDSound_Play3d(arg4, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        return;
    }
    if ((s32) M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) {
        temp_r31_322 = this->unk8 + 0x30;
        KDSound_Play3d(M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), temp_r31_322, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Projectile::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    MKVector3 *temp_r31_401;
    s32 var_r0_374;

    MKModel_SetPosition(this->unk4, arg0);
    this->unkC8 = M2C_FIELD(&arg1, f64 *, 0);
    this->unkD0 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk14C |= 0x80;
    this->unk14C |= 0x40;
    this->unk130 = arg2;
    this->unk14C |= 0x10;
    this->unk140 = 10.0f;
    if (arg4 != 0) {
        var_r0_374 = arg4;
    } else {
        var_r0_374 = M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xEC);
    }
    this->unk148 = var_r0_374;
    if (arg3 != 0) {
        KDSound_Play3d(arg3, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        return;
    }
    if ((s32) M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4) != 0) {
        temp_r31_401 = this->unk8 + 0x30;
        KDSound_Play3d(M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE4), temp_r31_401, 0U, -1, 0.0f, 0U);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Projectile::Message(MKMessage *arg0) {
    s32 *temp_r3_428;

    GameProp::Message(arg0);
    temp_r3_428 = this->unk138;
    if (temp_r3_428 != NULL) {
        temp_r3_428->Message(arg0);
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void Projectile::Draw() {
    Matrix sp90;
    Matrix sp50;
    M2C_UNK sp4C;
    M2C_UNK spC;
    MKAttachment *temp_r3_490;

    if (((MKAttachment *) this->unk13C != NULL) && ((MKModel *) this->unk4 != NULL)) {
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp50.unk3C + 4, (s32) &spC + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp4C + 4, (s32) &spC + 4, 0x40);
        temp_r3_490 = this->unk13C;
        MKModel_GetRefPointMatrix((MKModel *) temp_r3_490->unk0, M2C_FIELD(temp_r3_490, s32 *, 4) & 0x0FFFFFFF, &sp50, 1U);
        sp90.Multiply(&sp90, &sp50);
        MKModel_SetWorldMatrix(this->unk4, sp50);
    }
    GameProp::Draw();
}
#endif

#if 0 // DRAFT: expression syntax error
void Projectile::Update() {
    MKCollisionResult sp78;
    void *sp70;
    s32 sp6C;
    s32 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    u8 sp14;
    void *sp10;
    s32 sp8;
    MKProp *temp_r3_551;
    u8 temp_r3_586;
    void *temp_r3_591;
    void *temp_r4_532;
    void *var_r4_548;

    GameProp::Update();
    if ((s32 *) this->unk138 != NULL) {
        temp_r4_532 = checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        sp8 = 1;
        this->unk138->Update(M2C_FIELD(temp_r4_532, s32 *, 0xE8), 1U, ((u8) this->unk14C >> 4U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    sp6C = 0;
    var_r4_548 = NULL;
    sp70 = NULL;
    sp68 = 0x27;
    temp_r3_551 = this->unk130;
    if (temp_r3_551 != NULL) {
        M2C_FIELD(temp_r3_551->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp68);
        var_r4_548 = sp70;
    }
    sp10 = var_r4_548;
    if (var_r4_548 != NULL) {
        sp14 = M2C_FIELD(var_r4_548, u8 *, 4);
        M2C_FIELD(var_r4_548, u8 *, 4) = 0U;
    }
    this->unk140 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk140 == 0.0f) {
        this->unk140 = 0.0f;
        Disable();
    } else {
        temp_r3_586 = this->unk14C;
        if (((temp_r3_586 >> 7U) & 1) && ((temp_r3_586 >> 6U) & 1)) {
            temp_r3_591 = this->unk8;
            sp58 = M2C_FIELD(temp_r3_591, f64 *, 0x30);
            sp60 = M2C_FIELD(temp_r3_591, f64 *, 0x38);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp38 = sp28;
            sp30 = M2C_FIELD(this, f32 *, 0xD0) * gUpdateTimeDelta;
            sp40 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp48 = sp18;
            sp20 = (f32) sp60 + (f32) sp40;
            sp50 = (f64) sp20;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), 10.0f, &sp78, (MKCollisionMode) 7, 0) != 0) {
                Collided(sp78);
                this->unkD8 = M2C_BITWISE(f64, sp78);
                this->unkE0 = (f64) sp78.unk8;
                this->unkE8 = (f64) sp78.unk10;
                this->unkF0 = (f64) sp78.unk18;
                this->unkF8 = (f64) sp78.unk20;
                this->unk100 = (f64) sp78.unk28;
                this->unk108 = sp78.unk30;
                this->unk10C = sp78.unk34;
                this->unk110 = sp78.unk38;
                this->unk114 = sp78.unk3C;
                this->unk118 = sp78.unk40;
                this->unk11C = sp78.unk44;
                this->unk120 = (s32) sp78.unk48;
                this->unk124 = sp78.unk4C;
                this->unk128 = sp78.unk50;
            } else {
                MKModel_SetPosition(this->unk4, *((MKVector3 *) &sp48));
            }
            M2C_FIELD(this, f32 *, 0xCC) = (f32) ((-1960.0f * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0xCC));
        }
    }
    if (sp10 != NULL) {
        M2C_FIELD(sp10, u8 *, 4) = sp14;
    }
}
#endif

#if 0 // DRAFT: ')' expected
void Projectile::LoadDone() {
    GameProp::LoadDone();
    if ((s32) M2C_FIELD(checked_cast<ProjectileDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0xE8) != 0) {
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = 0;
        }
        this->unk138 = M2C_ERROR(/* Read from unset register $r3 */);
        this->unk138->Init(0.25f, 0.25f);
    }
}
#endif

void Projectile::Reset() {
    GameProp::Reset();
    MKModel_SetWorldMatrix(this->unk4, Matrix::identity);
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkD0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk14C &= ~0x80;
    this->unk14C &= ~0x40;
    this->unk140 = 10.0f;
    this->unk144 = 1;
    this->unk134 = NULL;
    this->unk13C = NULL;
    this->unk14C &= ~0x10;
    M2C_FIELD(this, f32 *, 0xD8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xDC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xE0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xE8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xEC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xFC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x100) = 0.0f;
    M2C_FIELD(this, f32 *, 0x104) = 1.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    M2C_FIELD(this, s16 *, 0x110) = 0;
    M2C_FIELD(this, s8 *, 0x112) = 0;
    M2C_FIELD(this, s8 *, 0x113) = 0;
    this->unk114 = 0;
    this->unk118 = 3.4028235e38f;
    this->unk11C = 0;
    this->unk120 = 0;
    this->unk124 = -1;
    this->unk128 = 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void Projectile::Deinit() {
    Projectile *spC;
    s32 sp8;
    MKProp *temp_r3_804;
    s32 *temp_r31_824;
    s32 *temp_r3_820;
    s32 temp_cr0_eq_825;

    temp_r3_804 = this->unk130;
    if (temp_r3_804 != NULL) {
        spC = NULL;
        sp8 = 0x4E;
        spC = this;
        M2C_FIELD(temp_r3_804->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        this->unk130 = NULL;
    }
    temp_r3_820 = this->unk138;
    if (temp_r3_820 != NULL) {
        KDSound_Stop(temp_r3_820);
        temp_r31_824 = this->unk138;
        temp_cr0_eq_825 = temp_r31_824 == NULL;
        if (temp_cr0_eq_825 == 0) {
            if (temp_cr0_eq_825 == 0) {
                KDSound_Stop(temp_r31_824);
            }
            operator delete(temp_r31_824);
        }
    }
    this->unk13C = NULL;
    GameProp::Deinit();
}
#endif

void Projectile::Init() {
    GameProp::Init();
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkD0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk14C &= ~0x80;
    this->unk14C &= ~0x40;
    this->unk140 = 10.0f;
    this->unk144 = 1;
    this->unk130 = NULL;
    this->unk13C = NULL;
    this->unk138 = NULL;
    this->unk14C &= ~0x10;
    this->unk148 = GS_PLACEHOLDER;
    M2C_FIELD(this, f32 *, 0xD8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xDC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xE0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xE8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xEC) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF0) = 0.0f;
    M2C_FIELD(this, f32 *, 0xF8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xFC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x100) = 0.0f;
    M2C_FIELD(this, f32 *, 0x104) = 1.0f;
    this->unk108 = 0.0f;
    this->unk10C = 0.0f;
    M2C_FIELD(this, s16 *, 0x110) = 0;
    M2C_FIELD(this, s8 *, 0x112) = 0;
    M2C_FIELD(this, s8 *, 0x113) = 0;
    this->unk114 = 0;
    this->unk118 = 3.4028235e38f;
    this->unk11C = 0;
    this->unk120 = 0;
    this->unk124 = -1;
    this->unk128 = 0;
}

#if 0 // DRAFT: illegal use of non-static member
s32 ProjectileDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_920;

    var_r31_920 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndTravel", &this->unkE8) != 0) || (KDSound_LoadLine(arg0, "sndLaunch", &this->unkE4) != 0) || (KDSound_LoadLine(arg0, "sndCollide", &this->unkEC) != 0)) {
        var_r31_920 = 1;
    }
    return var_r31_920;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void ProjectileDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unkE4 = GS_PLACEHOLDER;
    this->unkE8 = GS_PLACEHOLDER;
    this->unkEC = GS_PLACEHOLDER;
}
#endif

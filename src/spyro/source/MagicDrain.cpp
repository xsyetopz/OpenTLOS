#include "spyro/source/MagicDrain.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GemMagicFX.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/Projectile.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

extern s32 GS_ELExtra3;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern MKPropDescriptor *pMagicDrainDescriptor;

static s32 lit_652 = 0;
static u8 lit_653 = 1;

void MagicDrain::Deinit() {
    ManagedLight *temp_r4_51;

    temp_r4_51 = this->unk15C;
    if (temp_r4_51 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_51);
    }
    Projectile::Deinit();
}

void MagicDrain::FireBurstEnd() {
    ManagedLight *temp_r4_80;

    this->unk158 = 0;
    this->unk150 = NULL;
    this->unk154 = NULL;
    temp_r4_80 = this->unk15C;
    if (temp_r4_80 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_80, 0U);
    }
    Disable();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void MagicDrain::FireBurst(MKVector3 *arg0, MKVector3 *arg1, int arg2, int arg3) {
    s32 sp8;
    MKVector3 *temp_r4_125;
    ManagedLight *temp_r3_126;
    ManagedLight *temp_r4_117;
    void *temp_r3_131;

    this->unk158 = 1;
    this->unk150 = arg0;
    this->unk154 = arg1;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x30)();
    temp_r4_117 = this->unk15C;
    if (temp_r4_117 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_117, 1U);
        temp_r4_125 = this->unk150;
        temp_r3_126 = this->unk15C;
        temp_r3_126->unk10 = M2C_FIELD(temp_r4_125, f64 *, 0);
        temp_r3_126->unk18 = M2C_FIELD(temp_r4_125, f64 *, 8);
        temp_r3_131 = temp_r3_126->unk3C;
        if (temp_r3_131 != NULL) {
            M2C_FIELD(temp_r3_131, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_125, f64 *, 0);
            M2C_FIELD(temp_r3_131, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_125, f64 *, 8);
        }
    }
    this->unk1B8 = 0.0f;
    sp8 = -1;
    this->unk160.Init((MKProp *) this, 1, 0, 0, 0, 0, 0, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void MagicDrain::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x34)();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void MagicDrain::Collided(MKCollisionResult &arg0) {
    M2C_FIELD(this->__vptr, M2C_UNK (**)(), 0x34)();
}
#endif

void MagicDrain::Draw() {

}

#if 0 // DRAFT: undefined identifier 'gameData'
void MagicDrain::Update() {
    MKVector3 sp68;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_310;
    ManagedLight *temp_r3_327;
    ManagedLight *temp_r4_307;
    f32 temp_f1_326;
    f32 var_f1_283;
    void *temp_r3_329;
    void *temp_r4_315;

    Projectile::Update();
    if (((u8) this->unk158 != 0) && ((MKVector3 *) this->unk150 != NULL) && ((MKVector3 *) this->unk154 != NULL)) {
        this->unk1B8 -= gUpdateTimeDelta;
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk1B8 == 0.0f) {
            if (gameData.unkA0.unk0 != 0.0f) {
                sp20 = 1.0f;
                sp30 = -1.0f;
                sp8 = 0.0f;
                spC = 1.0f;
                sp10 = 0.0f;
                sp14 = 1.0f;
                sp18 = 1.0f;
                sp1C = 1.0f;
                sp28 = -1.0f;
                sp2C = 1.0f;
                sp38 = (f64) sp8;
                sp40 = (f64) sp10;
                sp48 = (f64) sp18;
                sp50 = (f64) sp20;
                sp58 = (f64) sp28;
                sp60 = (f64) sp30;
                KDRand_Vector(sp68, *((MKVector3 *) &sp58));
                ((GemMagicFX *) (M2C_FIELD(&gb, GemMagicFX **, 0x238)))->Emit(*this->unk154, sp68, this->unk150, *((MKVector4 *) &sp38), 0U);
                KDSound_Play3d(GS_ELExtra3, this->unk154, 0U, -1, 0.0f, 0U);
                if ((u8) M2C_FIELD(&gb, u8 *, 0x3B5) == 0) {
                    var_f1_283 = -((20.0f * gUpdateTimeDelta) - gameData.unkA0.unk0);
                    if (var_f1_283 < gameData.unkA0.unk4) {

                    } else {
                        var_f1_283 = gameData.unkA0.unk4;
                    }
                    if (var_f1_283 > 0.0f) {

                    } else {
                        var_f1_283 = 0.0f;
                    }
                    gameData.unkA0.SetValue(var_f1_283, 0U);
                }
            }
            this->unk1B8 = MKRand_Float(&gViewSeed, 0.125f, 0.25f);
        }
        temp_r4_307 = this->unk15C;
        if (temp_r4_307 != NULL) {
            temp_r3_310 = this->unk150;
            temp_r4_307->unk10 = M2C_FIELD(temp_r3_310, f64 *, 0);
            temp_r4_307->unk18 = M2C_FIELD(temp_r3_310, f64 *, 8);
            temp_r4_315 = temp_r4_307->unk3C;
            if (temp_r4_315 != NULL) {
                M2C_FIELD(temp_r4_315, f64 *, 0x10) = (f64) M2C_FIELD(temp_r3_310, f64 *, 0);
                M2C_FIELD(temp_r4_315, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_310, f64 *, 8);
            }
            temp_f1_326 = MKRand_Float(&gViewSeed, 500.0f, 600.0f);
            temp_r3_327 = this->unk15C;
            temp_r3_327->unk38 = temp_f1_326;
            temp_r3_329 = temp_r3_327->unk3C;
            if (temp_r3_329 != NULL) {
                M2C_FIELD(temp_r3_329, f32 *, 0x20) = temp_f1_326;
                M2C_FIELD(temp_r3_329, f32 *, 0x24) = (f32) (temp_f1_326 * temp_f1_326);
                M2C_FIELD(temp_r3_329, f32 *, 0x28) = (f32) (1.0f / temp_f1_326);
                M2C_FIELD(temp_r3_329, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_329, f32 *, 0x24));
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MagicDrain::Resolve() {
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    ManagedLight *temp_r4_393;

    KDPropEx::Resolve();
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
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = (f64) sp30;
    this->unk15C = ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->AllocManagedLight(*((MKVector3 *) &sp58), *((MKVector3 *) &sp48), *((MKVector4 *) &sp38), 500.0f, lit_652, lit_653);
    temp_r4_393 = this->unk15C;
    if (temp_r4_393 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_393, 0U);
    }
}
#endif

void MagicDrain::LoadDone() {
    Projectile::LoadDone();
}

void MagicDrain::Init() {
    Projectile::Init();
    SetDefaults();
}

void MagicDrain::Reset() {
    Projectile::Reset();
    SetDefaults();
}

void MagicDrain::SetDefaults() {
    this->unk150 = NULL;
    this->unk154 = NULL;
    this->unk158 = 0;
}

void *MagicDrain::CreateInstance() {
    void *temp_r3_476;

    if ((MKPropDescriptor *) pMagicDrainDescriptor != NULL) {
        temp_r3_476 = pMagicDrainDescriptor->CreateInstance();
        if (temp_r3_476 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_476, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_476;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void MagicDrainDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    pMagicDrainDescriptor = (MKPropDescriptor *) this;
}
#endif

void MagicDrainDescriptor::Deinit() {
    pMagicDrainDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}

#include "spyro/source/SteamFireBall.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
extern MKPropDescriptor *pSteamFireBallDescriptor;

#if 0 // DRAFT: undefined identifier 'sp8'
static s8 lit_stringBase0[0x1F] = {
    0x50,
    0x39,
    0x30,
    0x32,
    0x32,
    0x5F,
    0x44,
    0x72,
    0x6F,
    0x70,
    0x42,
    0x6F,
    0x78,
    0x53,
    0x68,
    0x61,
    0x64,
    0x6F,
    0x77,
    0,
    0x45,
    0x78,
    0x70,
    0x6C,
    0x6F,
    0x73,
    0x69,
    0x6F,
    0x6E,
    0x34,
    0,
}; /* const */

void SteamFireBall::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    s8 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    f32 sp88;
    s32 sp84;
    s8 sp83;
    s8 sp82;
    s16 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;

    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = -8000.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp60 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp74 = 1.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0;
    sp82 = 0;
    sp83 = 0;
    sp84 = 0;
    sp88 = 3.4028235e38f;
    sp8C = 0;
    sp90 = 0;
    sp94 = -1;
    sp98 = 0;
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = sp8;
    sp10 = arg0.unk8 + (f32) sp30;
    sp40 = (f64) sp10;
    if (MKCollision_RayCollide(arg0, *((MKVector3 *) &sp38), (MKCollisionResult *) &sp48, (MKCollisionMode) 4, 0x0C000000) != 0) {
        this->unk184 = sp4C;
    } else {
        this->unk184 = arg1.unk4;
    }
    this->unk150.unk28 = this->unk184 - 100.0f;
    this->unk150.Show(1U);
    Projectile::FireAtTarget(arg0, arg1, arg2, arg3, arg4, arg5);
}
#endif

#if 0 // DRAFT: undefined identifier 'gameData'
void SteamFireBall::Collided(MKCollisionResult &arg0) {
    s32 sp8;
    f32 temp_f1_170;
    s32 var_r5_167;
    void *temp_r3_148;

    Projectile::Collided(arg0);
    temp_r3_148 = checked_cast<SteamFireBallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1;
    ((Explosion4 *) (M2C_FIELD(temp_r3_148, Explosion4 **, 0xF0)))->Trigger(*((MKVector3 *) &arg0), 0.3f, 1U, this->unk130, 5, 1U, 1U, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    this->unk150.Show(0U);
    var_r5_167 = 3;
    temp_f1_170 = gameData.unkA0 / gameData.unkA4;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (temp_f1_170 == 0.9f) {
        var_r5_167 = 0;
    } else if (temp_f1_170 > 0.75f) {
        var_r5_167 = 1;
    } else if (temp_f1_170 > 0.25f) {
        var_r5_167 = 2;
    }
    gb.unk18->Spawn(*((MKVector3 *) &arg0), var_r5_167, 200.0f, 500.0f, -1, NULL);
    Disable();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKModel *' to
void SteamFireBall::Update() {
    f32 temp_f0_243;
    f32 temp_f1_242;
    f32 temp_f3_245;
    f32 var_f1_441;
    f32 var_f3_317;
    f32 var_f4_250;
    f64 temp_f1_256;
    f64 temp_f1_262;
    f64 temp_f1_266;
    f64 temp_f3_465;
    f64 temp_f4_464;
    s32 temp_r3_285;
    s32 var_r0_295;
    void *temp_r3_428;
    void *temp_r3_461;
    Projectile::Update();
    this->unk180 = (10.0f * gUpdateTimeDelta) + M2C_BITWISE(f32, this->unk180);
    M2C_STRUCT_COPY((s32) &arg_sp18C + 4, (s32) (&identity - 4) + 4, 0x40);
    temp_f1_242 = M2C_FIELD(this, f32 *, 0xC8);
    temp_f0_243 = M2C_FIELD(this, f32 *, 0xCC);
    temp_f3_245 = M2C_FIELD(this, f32 *, 0xD0);
    var_f4_250 = (temp_f3_245 * temp_f3_245) + ((temp_f1_242 * temp_f1_242) + (temp_f0_243 * temp_f0_243));
    if (var_f4_250 > 1e-12f) {
        if (var_f4_250 > 0.0f) {
            temp_f1_256 = __frsqrte(var_f4_250);
            temp_f1_262 = 0.5 * temp_f1_256 * -(((f64) var_f4_250 * (temp_f1_256 * temp_f1_256)) - 3.0);
            temp_f1_266 = 0.5 * temp_f1_262 * -(((f64) var_f4_250 * (temp_f1_262 * temp_f1_262)) - 3.0);
            var_f4_250 = (f32) ((f64) var_f4_250 * (0.5 * temp_f1_266 * -(((f64) var_f4_250 * (temp_f1_266 * temp_f1_266)) - 3.0)));
        } else if (var_f4_250 < M2C_BITWISE(f32, 0.0)) {
            var_f4_250 = __float_nan;
        } else {
            arg_sp10 = var_f4_250;
            temp_r3_285 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_285) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_295 = 1;
                } else {
                    var_r0_295 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_295 = 5;
                } else {
                    var_r0_295 = 3;
                }
                break;
            default:
                var_r0_295 = 4;
                break;
            }
            if (var_r0_295 == 1) {
                var_f4_250 = __float_nan;
            }
        }
        var_f3_317 = 1.0f / var_f4_250;
    } else {
        var_f3_317 = 0.0f;
    }
    arg_sp60 = 0.0f;
    arg_sp70 = M2C_FIELD(this, f32 *, 0xD0) * var_f3_317;
    arg_sp68 = M2C_FIELD(this, f32 *, 0xC8) * var_f3_317;
    arg_sp6C = M2C_FIELD(this, f32 *, 0xCC) * var_f3_317;
    arg_sp58 = 0.0f;
    arg_sp5C = 1.0f;
    arg_spF8 = (f64) arg_sp68;
    arg_sp100 = (f64) arg_sp70;
    arg_spE8 = (f64) arg_sp58;
    arg_spF0 = (f64) arg_sp60;
    KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp190, *((MKVector3 *) &arg_spF8), (MKVector3 *) &arg_spE8);
    M2C_STRUCT_COPY((s32) &arg_sp14C + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_sp150.RotateRoll((Matrix *) &arg_sp150, 2.0f * M2C_BITWISE(f32, this->unk180));
    arg_sp150.Multiply3x3((Matrix *) &arg_sp150, (Matrix *) &arg_sp190);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_spC8 = arg_sp48;
    arg_sp50 = arg_sp168 * 100.0f;
    arg_spD0 = (f64) arg_sp50;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spD8 = arg_sp38;
    arg_sp40 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) arg_spD0;
    arg_spE0 = (f64) arg_sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp30 = arg_sp168 * 150.0f;
    arg_spB8 = arg_sp28;
    arg_spC0 = (f64) arg_sp30;
    gb.EmitDust(*((MKVector3 *) &arg_spD8), *((MKVector3 *) &arg_spB8), 1.0f, 0.0f);
    if ((u8) this->unk150.unk2C != 0) {
        M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&identity - 4) + 4, 0x40);
        temp_r3_428 = this->unk8;
        arg_spA8 = M2C_FIELD(temp_r3_428, f64 *, 0x30);
        arg_spB0 = M2C_FIELD(temp_r3_428, f64 *, 0x38);
        var_f1_441 = 0.18f * -((0.00022222222f * (arg_spAC - this->unk184)) - 1.0f);
        if (var_f1_441 < 1.0f) {

        } else {
            var_f1_441 = 1.0f;
        }
        if (var_f1_441 > 0.001f) {

        } else {
            var_f1_441 = 0.001f;
        }
        arg_sp110.Scale3x3((Matrix *) &arg_sp110, var_f1_441);
        MKModel_SetWorldMatrix(this->unk180, *((Matrix *) &arg_sp110));
        temp_r3_461 = this->unk8;
        temp_f4_464 = M2C_FIELD(temp_r3_461, f64 *, 0x30);
        temp_f3_465 = M2C_FIELD(temp_r3_461, f64 *, 0x38);
        arg_sp88 = temp_f4_464;
        arg_sp80 = temp_f3_465;
        arg_sp18 = (f32) arg_sp88;
        arg_sp1C = this->unk184;
        arg_sp20 = (f32) arg_sp80;
        arg_sp98 = (f64) arg_sp18;
        arg_spA0 = (f64) arg_sp20;
        arg_sp78 = temp_f4_464;
        arg_sp90 = temp_f3_465;
        MKModel_SetPosition(this->unk180, *((MKVector3 *) &arg_sp98));
    }
}
#endif

void SteamFireBall::Resolve() {
    KDPropEx::Resolve();
    this->unk150.Init(this->unk180, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unk150.Show(0U);
}

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
void SteamFireBall::LoadDone() {
    Projectile::LoadDone();
    this->unk180 = MKModel_Create(lit_stringBase0, NULL, 2, NULL);
}
#endif

void SteamFireBall::Deinit() {
    MKModel_Destroy(this->unk180);
    this->unk150.Deinit();
    Projectile::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void SteamFireBall::Init() {
    Projectile::Init();
    this->unk180 = 0.0f;
    this->unk184 = 0.0f;
}
#endif

void *SteamFireBall::CreateInstance() {
    void *temp_r3_593;

    if ((MKPropDescriptor *) pSteamFireBallDescriptor != NULL) {
        temp_r3_593 = pSteamFireBallDescriptor->CreateInstance();
        if (temp_r3_593 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_593, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_593;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void SteamFireBallDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    this->unkF0 = checked_cast<Explosion4 *, MKProp>(gMK->CreateProp(&lit_stringBase0[0x14]));
    pSteamFireBallDescriptor = (MKPropDescriptor *) this;
}
#endif

void SteamFireBallDescriptor::Deinit() {
    pSteamFireBallDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<SteamFireBallDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

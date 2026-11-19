#include "spyro/source/FlyingMonkey.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Projectile.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern MKPropDescriptor *pFlyingMonkeyDescriptor;

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void FlyingMonkey::FireAtTarget(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKProp *arg3, int arg4, int arg5) {
    s32 temp_r31_49;

    Projectile::FireAtTarget(arg0, arg1, arg2, arg3, arg4, arg5);
    temp_r31_49 = MKRand_Int(&gViewSeed, 0, 6);
    this->unk80->SetAnim(M2C_FIELD((checked_cast<FlyingMonkeyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_49 * 4)), MKAnim **, 0xF0), 1.0f, 0.0f, 0, -1);
    this->unk140 = 4.0f;
}
#endif

#if 0 // DRAFT: function call 'MKRand_Int(long *, int, int)' does not match
void FlyingMonkey::Fire(const MKVector3 &arg0, const MKVector3 &arg1, MKProp *arg2, int arg3, int arg4) {
    s32 temp_r31_83;

    Projectile::Fire(arg0, arg1, arg2, arg3, arg4);
    temp_r31_83 = MKRand_Int(&gViewSeed, 0, 6);
    this->unk80->SetAnim(M2C_FIELD((checked_cast<FlyingMonkeyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (temp_r31_83 * 4)), MKAnim **, 0xF0), 1.0f, 0.0f, 0, -1);
    this->unk140 = 4.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void FlyingMonkey::Update() {
    f32 var_f4_284;
    f32 var_f5_305;
    f64 temp_f1_310;
    f64 temp_f1_316;
    f64 temp_f1_320;
    s32 temp_r3_339;
    s32 var_r0_349;
    u32 var_r3_207;
    u8 temp_r3_159;
    void *temp_r4_129;
    if ((s32 *) this->unk138 != NULL) {
        temp_r4_129 = checked_cast<FlyingMonkeyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        arg_sp8 = 1;
        this->unk138->Update(M2C_FIELD(temp_r4_129, s32 *, 0xE8), 1U, ((u8) this->unk14C >> 4U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    }
    this->unk140 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk140 == 0.0f) {
        this->unk140 = 0.0f;
        Disable();
    } else {
        temp_r3_159 = this->unk14C;
        if (((temp_r3_159 >> 7U) & 1) && ((temp_r3_159 >> 6U) & 1)) {
            MKModel_CalculateCentre(this->unk4, (MKVector3 *) &arg_sp188);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            arg_sp138 = arg_spA8;
            arg_spB0 = M2C_FIELD(this, f32 *, 0xD0) * gUpdateTimeDelta;
            arg_sp140 = (f64) arg_spB0;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp178 = arg_sp98;
            arg_spA0 = arg_sp190 + (f32) arg_sp140;
            arg_sp180 = (f64) arg_spA0;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) &arg_sp188), *((MKVector3 *) &arg_sp178), 120.00001f, (MKCollisionResult *) &arg_sp220, (MKCollisionMode) 7, 0) != 0) {
                if ((arg_sp270 != 0) && (arg_sp268 != NULL) && (var_r3_207 = M2C_FIELD(arg_sp268, u32 *, 8), ((var_r3_207 == 0U) == 0))) {

                } else {
                    var_r3_207 = 0U;
                }
                if (var_r3_207 != (MKProp *) this->unk130) {
                    Collided(arg_sp220);
                } else {
                    goto block_14;
                }
            } else {
block_14:
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp118 = arg_sp88;
                arg_sp90 = M2C_FIELD(this, f32 *, 0xD0) * gUpdateTimeDelta;
                arg_sp120 = (f64) arg_sp90;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp128 = arg_sp78;
                arg_sp80 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) + (f32) arg_sp120;
                arg_sp130 = (f64) arg_sp80;
                MKModel_SetPosition(this->unk4, *((MKVector3 *) &arg_sp128));
            }
            M2C_FIELD(this, f32 *, 0xCC) = (f32) ((-1960.0f * gUpdateTimeDelta) + M2C_FIELD(this, f32 *, 0xCC));
        }
    }
    if (MKModel_GetAttachment(this->unk4) != NULL) {
        MKModel_GetWorldMatrixWithAttachment(this->unk4, (Matrix *) &arg_sp1E0);
    } else {
        M2C_STRUCT_COPY((s32) &arg_sp1DC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    }
    var_f4_284 = 0.0f;
    arg_sp70 = 0.0f;
    arg_sp68 = 0.0f;
    arg_sp6C = 1.0f;
    arg_sp160 = (f64) arg_sp70;
    arg_sp158 = (f64) arg_sp68;
    arg_sp168 = this->unkC8;
    arg_sp170 = this->unkD0;
    var_f5_305 = ((f32) arg_sp170 * (f32) arg_sp170) + (((f32) arg_sp168 * (f32) arg_sp168) + (arg_sp16C * arg_sp16C));
    if (var_f5_305 > 0.000001f) {
        if (var_f5_305 > 0.0f) {
            temp_f1_310 = __frsqrte(var_f5_305);
            temp_f1_316 = 0.5 * temp_f1_310 * -(((f64) var_f5_305 * (temp_f1_310 * temp_f1_310)) - 3.0);
            temp_f1_320 = 0.5 * temp_f1_316 * -(((f64) var_f5_305 * (temp_f1_316 * temp_f1_316)) - 3.0);
            var_f5_305 = (f32) ((f64) var_f5_305 * (0.5 * temp_f1_320 * -(((f64) var_f5_305 * (temp_f1_320 * temp_f1_320)) - 3.0)));
        } else if (var_f5_305 < M2C_BITWISE(f32, 0.0)) {
            var_f5_305 = __float_nan;
        } else {
            arg_sp10 = var_f5_305;
            temp_r3_339 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_339) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_349 = 1;
                } else {
                    var_r0_349 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_349 = 5;
                } else {
                    var_r0_349 = 3;
                }
                break;
            default:
                var_r0_349 = 4;
                break;
            }
            if (var_r0_349 == 1) {
                var_f5_305 = __float_nan;
            }
        }
        var_f4_284 = 1.0f / var_f5_305;
    } else {
        var_f5_305 = 0.0f;
    }
    arg_sp168 = (f32) arg_sp168 * var_f4_284;
    arg_sp16C *= var_f4_284;
    arg_sp170 = (f32) arg_sp170 * var_f4_284;
    if (var_f5_305 != 0.0f) {
        KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp1A0, *((MKVector3 *) &arg_sp168), (MKVector3 *) &arg_sp158);
        arg_sp1D0 = arg_sp210;
        arg_sp1D4 = arg_sp214;
        arg_sp1D8 = arg_sp218;
        arg_sp1DC = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &arg_sp1A0));
    }
    MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(checked_cast<FlyingMonkeyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x108), (MKVector3 *) &arg_sp148);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp108 = arg_sp18;
    arg_sp20 = arg_sp208 * 200.0f;
    arg_sp110 = (f64) arg_sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp60 = -1.0f;
    arg_sp50 = 1.0f;
    arg_sp58 = -1.0f;
    arg_sp5C = -1.0f;
    arg_sp48 = 1.0f;
    arg_sp4C = 1.0f;
    arg_sp150 += (f32) arg_sp110;
    arg_spC8 = (f64) arg_sp58;
    arg_spD0 = (f64) arg_sp60;
    arg_spB8 = (f64) arg_sp48;
    arg_spC0 = (f64) arg_sp50;
    KDRand_Vector(*((MKVector3 *) &arg_spD8), *((MKVector3 *) &arg_spC8));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_spE8 = arg_sp38;
    arg_sp40 = arg_spE0 * 100.0f;
    arg_spF0 = (f64) arg_sp40;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spF8 = arg_sp28;
    arg_sp30 = arg_sp150 + (f32) arg_spF0;
    arg_sp100 = (f64) arg_sp30;
    arg_sp14 = MKRand_Float(&gViewSeed, 1.0f, 2.5f);
    gb.EmitDust(*((MKVector3 *) &arg_spF8), zero, arg_sp14, 0.0f);
}
#endif

#if 0 // DRAFT: undefined identifier 'one'
void FlyingMonkey::Collided(MKCollisionResult &arg0) {
    s8 spD9;
    s8 spD8;
    s32 spD4;
    f32 spD0;
    s32 spCC;
    s8 spCA;
    s8 spC9;
    s8 spC8;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    MKProp *spB4;
    s32 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    s32 sp8C;
    MKProp *sp88;
    s8 sp86;
    s8 sp85;
    s8 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    f32 sp6C;
    f32 sp68;
    f64 sp60;
    f64 sp58;
    MKProp *sp50;
    MKProp *sp4C;
    MKProp *sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r9_529;
    f64 temp_f2_547;
    f64 temp_f3_546;
    void *temp_r3_517;
    void *temp_r7_542;
    void *var_r31_520;

    Projectile::Collided(arg0);
    if (((u8) arg0.unk50 != 0) && (temp_r3_517 = arg0.unk48, ((temp_r3_517 == NULL) == 0)) && (var_r31_520 = M2C_FIELD(temp_r3_517, void **, 8), ((var_r31_520 == NULL) == 0))) {

    } else {
        var_r31_520 = NULL;
    }
    if (var_r31_520 != NULL) {
        temp_r9_529 = this->unk130;
        if (temp_r9_529 != NULL) {
            if (M2C_FIELD(M2C_FIELD(var_r31_520, void **, 0), s32 *, 0xC) & 8) {
                sp4C = NULL;
                temp_r7_542 = temp_r9_529->unk8;
                temp_f3_546 = M2C_FIELD(temp_r7_542, f64 *, 0x30);
                temp_f2_547 = M2C_FIELD(temp_r7_542, f64 *, 0x38);
                sp38 = temp_f3_546;
                sp48 = (MKProp *)4;
                sp50 = temp_r9_529;
                sp58 = temp_f3_546;
                sp60 = temp_f2_547;
                sp68 = 10.0f;
                sp84 = 0;
                sp70 = 0;
                sp78 = 0x4000;
                sp85 = 0;
                sp86 = 0;
                sp74 = -1;
                sp7C = 0;
                sp80 = 0;
                sp6C = 1.0f;
                sp40 = temp_f2_547;
                M2C_FIELD(M2C_FIELD(var_r31_520, void **, 0x44), M2C_UNK (**)(void *, MKProp **, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32, f64, f64), 0x2C)(var_r31_520, &sp48, 0x4000, 4, temp_r7_542, 0, 10.0f, temp_f2_547, temp_f3_546);
            } else {
                sp10 = 0.0f;
                sp8 = 0.0f;
                spC = 0.0f;
                sp8C = 0;
                sp28 = (f64) sp8;
                sp30 = (f64) sp10;
                sp88 = (MKProp *)7;
                spB0 = 1;
                spB4 = temp_r9_529;
                sp90 = (f64) sp8;
                sp98 = (f64) sp10;
                spC8 = 0;
                spD4 = 2;
                spD0 = 10.0f;
                spC9 = 0;
                spCA = 1;
                spCC = -1;
                spA0 = M2C_FIELD(&one, f64 *, 0);
                spA8 = M2C_FIELD(&one, f64 *, 8);
                spD8 = 0;
                if (temp_r9_529 != NULL) {
                    sp18.GetPos();
                    spB8 = sp18;
                    spC0 = sp20;
                } else {
                    spB8 = 0.0f;
                    unkspBC = 0.0f;
                    spC0 = 0.0f;
                }
                spD9 = 0;
                M2C_FIELD(M2C_FIELD(var_r31_520, void **, 0x44), M2C_UNK (**)(void *, MKProp **, M2C_UNK, M2C_UNK, void *, M2C_UNK, f32, f64, f64), 0x2C)(var_r31_520, &sp88);
            }
        }
    }
    Disable();
}
#endif

void *FlyingMonkey::CreateInstance() {
    void *temp_r3_648;

    if ((MKPropDescriptor *) pFlyingMonkeyDescriptor != NULL) {
        temp_r3_648 = pFlyingMonkeyDescriptor->CreateInstance();
        if (temp_r3_648 != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r3_648, void **, 0x44), M2C_UNK (**)(), 0x20)();
            return temp_r3_648;
        }
    }
    return NULL;
}

#if 0 // DRAFT: illegal use of non-static member
void FlyingMonkeyDescriptor::LoadDone() {
    s8 *temp_r30_679;
    s8 *temp_r30_695;
    s8 *temp_r30_713;
    s8 *temp_r30_731;
    s8 *temp_r30_749;
    s8 *temp_r30_767;
    void *var_r3_687;
    void *var_r3_705;
    void *var_r3_723;
    void *var_r3_741;
    void *var_r3_759;
    void *var_r3_777;

    GamePropDescriptor::LoadDone();
    pFlyingMonkeyDescriptor = (MKPropDescriptor *) this;
    temp_r30_679 = this->unk34;
    if (temp_r30_679->Exists("Hit_Shock01") != 0) {
        var_r3_687 = temp_r30_679->GetAnim("Hit_Shock01");
    } else {
        var_r3_687 = NULL;
    }
    this->unkF0 = (s32) var_r3_687;
    temp_r30_695 = this->unk34;
    if (temp_r30_695->Exists("Hit_Shock02") != 0) {
        var_r3_705 = temp_r30_695->GetAnim("Hit_Shock02");
    } else {
        var_r3_705 = NULL;
    }
    this->unkF4 = (s32) var_r3_705;
    temp_r30_713 = this->unk34;
    if (temp_r30_713->Exists("Hit_Shock03") != 0) {
        var_r3_723 = temp_r30_713->GetAnim("Hit_Shock03");
    } else {
        var_r3_723 = NULL;
    }
    this->unkF8 = (s32) var_r3_723;
    temp_r30_731 = this->unk34;
    if (temp_r30_731->Exists("Leap_Miss_Loop") != 0) {
        var_r3_741 = temp_r30_731->GetAnim("Leap_Miss_Loop");
    } else {
        var_r3_741 = NULL;
    }
    this->unkFC = (s32) var_r3_741;
    temp_r30_749 = this->unk34;
    if (temp_r30_749->Exists("Flee") != 0) {
        var_r3_759 = temp_r30_749->GetAnim("Flee");
    } else {
        var_r3_759 = NULL;
    }
    this->unk100 = (s32) var_r3_759;
    temp_r30_767 = this->unk34;
    if (temp_r30_767->Exists("Jump_up_Loop") != 0) {
        var_r3_777 = temp_r30_767->GetAnim("Jump_up_Loop");
    } else {
        var_r3_777 = NULL;
    }
    this->unk104 = (s32) var_r3_777;
    this->unk108 = (s32) Tools_GetMatchingRefPointIndex(this->unk2C, "A035_weapon03");
}
#endif

void FlyingMonkeyDescriptor::Deinit() {
    pFlyingMonkeyDescriptor = NULL;
    KDPropExDescriptor::Deinit();
}

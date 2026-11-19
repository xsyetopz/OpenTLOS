#include "spyro/source/ShockWave.h"
#include "common/Source/Animation.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDProp.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKShockWave_MP.h"
#include "common/Source/MKView.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/GameConsole.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern void **gb;

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ShockWave::UpdateShockWave(int arg0) {
    MKCollisionResult spD0;
    Matrix sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_115;
    f32 temp_f0_181;
    f32 temp_f0_247;
    f32 temp_f0_313;
    f32 temp_f0_65;
    f32 temp_f31_165;
    f32 temp_f31_231;
    f32 temp_f31_297;
    f32 temp_f31_99;
    f32 temp_f3_139;
    f32 temp_f3_205;
    f32 temp_f3_271;
    f32 temp_f3_337;
    s32 temp_r29_58;
    s32 temp_r30_146;
    s32 temp_r30_212;
    s32 temp_r30_278;
    s32 temp_r30_344;
    s32 temp_r30_78;
    void *temp_r29_286;
    void *temp_r30_154;
    void *temp_r30_220;
    void *temp_r31_77;

    if ((u8) this->unk160 != 0) {
        temp_r29_58 = arg0 * 0x28;
        sp14 = 1.0f;
        temp_f0_65 = M2C_FIELD((this + temp_r29_58), f32 *, 0x9C) / 500.0f;
        sp10 = temp_f0_65;
        sp18 = temp_f0_65;
        sp80 = (f64) sp10;
        sp88 = (f64) sp18;
        sp90.SetIdentity();
        sp90.Scale3x3(&sp90, *((MKVector3 *) &sp80));
        temp_r31_77 = this + temp_r29_58;
        temp_r30_78 = M2C_FIELD(temp_r31_77, s32 *, 0xA4);
        ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r31_77, MKModel **, 0xA0))))->SetCustomMatrix(temp_r30_78, &sp90, (AnimationMatrixPosition) 2, 0U);
        sp90.SetIdentity();
        MKModel_CalculateNodeWorldPosition(M2C_FIELD(temp_r31_77, MKModel **, 0xA0), M2C_FIELD(temp_r31_77, s32 *, 0xA8), &sp70);
        sp60 = M2C_BITWISE(f64, sp70);
        temp_f31_99 = sp70.unk4;
        sp68 = (f64) sp70.unk8;
        sp70.unk4 = temp_f31_99 + 200.0f;
        unksp64 -= 600.0f;
        if (MKCollision_RayCollide(sp70, *((MKVector3 *) &sp60), &spD0, (MKCollisionMode) 1, 0) != 0) {
            temp_f0_115 = spD0.unk4 + 20.0f;
            if ((temp_f31_99 < temp_f0_115) && ((temp_f0_115 - temp_f31_99) > 20.0f)) {
                spD0.unk4 = (0.4f * (spD0.unk4 - 20.0f)) + 20.0f;
            }
            sp50 = (f64) sp90.unk30;
            sp58 = (f64) sp90.unk38;
            temp_f3_139 = 20.0f + (spD0.unk4 - M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_77, MKModel **, 0xA0)), f32 *, 0x34));
            sp90.unk30 = (f32) sp50;
            sp90.unk38 = (f32) sp58;
            unksp54 = temp_f3_139;
            sp90.unk34 = temp_f3_139;
            sp90.unk3C = 1.0f;
        }
        temp_r30_146 = M2C_FIELD(temp_r31_77, s32 *, 0xA8);
        ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r31_77, MKModel **, 0xA0))))->SetCustomMatrix(temp_r30_146, &sp90, (AnimationMatrixPosition) 2, 0U);
        temp_r30_154 = this + temp_r29_58;
        MKModel_CalculateNodeWorldPosition(M2C_FIELD(temp_r31_77, MKModel **, 0xA0), M2C_FIELD(temp_r30_154, s32 *, 0xAC), &sp70);
        sp60 = M2C_BITWISE(f64, sp70);
        temp_f31_165 = sp70.unk4;
        sp68 = (f64) sp70.unk8;
        sp70.unk4 = temp_f31_165 + 200.0f;
        unksp64 -= 600.0f;
        if (MKCollision_RayCollide(sp70, *((MKVector3 *) &sp60), &spD0, (MKCollisionMode) 1, 0) != 0) {
            temp_f0_181 = spD0.unk4 + 20.0f;
            if ((temp_f31_165 < temp_f0_181) && ((temp_f0_181 - temp_f31_165) > 20.0f)) {
                spD0.unk4 = (0.4f * (spD0.unk4 - 20.0f)) + 20.0f;
            }
            sp40 = (f64) sp90.unk30;
            sp48 = (f64) sp90.unk38;
            temp_f3_205 = 20.0f + (spD0.unk4 - M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_77, MKModel **, 0xA0)), f32 *, 0x34));
            sp90.unk30 = (f32) sp40;
            sp90.unk38 = (f32) sp48;
            unksp44 = temp_f3_205;
            sp90.unk34 = temp_f3_205;
            sp90.unk3C = 1.0f;
        }
        temp_r30_212 = M2C_FIELD(temp_r30_154, s32 *, 0xAC);
        ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r31_77, MKModel **, 0xA0))))->SetCustomMatrix(temp_r30_212, &sp90, (AnimationMatrixPosition) 2, 0U);
        temp_r30_220 = this + temp_r29_58;
        MKModel_CalculateNodeWorldPosition(M2C_FIELD(temp_r31_77, MKModel **, 0xA0), M2C_FIELD(temp_r30_220, s32 *, 0xB0), &sp70);
        sp60 = M2C_BITWISE(f64, sp70);
        temp_f31_231 = sp70.unk4;
        sp68 = (f64) sp70.unk8;
        sp70.unk4 = temp_f31_231 + 200.0f;
        unksp64 -= 600.0f;
        if (MKCollision_RayCollide(sp70, *((MKVector3 *) &sp60), &spD0, (MKCollisionMode) 1, 0) != 0) {
            temp_f0_247 = spD0.unk4 + 20.0f;
            if ((temp_f31_231 < temp_f0_247) && ((temp_f0_247 - temp_f31_231) > 20.0f)) {
                spD0.unk4 = (0.4f * (spD0.unk4 - 20.0f)) + 20.0f;
            }
            sp30 = (f64) sp90.unk30;
            sp38 = (f64) sp90.unk38;
            temp_f3_271 = 20.0f + (spD0.unk4 - M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_77, MKModel **, 0xA0)), f32 *, 0x34));
            sp90.unk30 = (f32) sp30;
            sp90.unk38 = (f32) sp38;
            unksp34 = temp_f3_271;
            sp90.unk34 = temp_f3_271;
            sp90.unk3C = 1.0f;
        }
        temp_r30_278 = M2C_FIELD(temp_r30_220, s32 *, 0xB0);
        ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r31_77, MKModel **, 0xA0))))->SetCustomMatrix(temp_r30_278, &sp90, (AnimationMatrixPosition) 2, 0U);
        temp_r29_286 = this + temp_r29_58;
        MKModel_CalculateNodeWorldPosition(M2C_FIELD(temp_r31_77, MKModel **, 0xA0), M2C_FIELD(temp_r29_286, s32 *, 0xB4), &sp70);
        sp60 = M2C_BITWISE(f64, sp70);
        temp_f31_297 = sp70.unk4;
        sp68 = (f64) sp70.unk8;
        sp70.unk4 = temp_f31_297 + 200.0f;
        unksp64 -= 600.0f;
        if (MKCollision_RayCollide(sp70, *((MKVector3 *) &sp60), &spD0, (MKCollisionMode) 1, 0) != 0) {
            temp_f0_313 = spD0.unk4 + 20.0f;
            if ((temp_f31_297 < temp_f0_313) && ((temp_f0_313 - temp_f31_297) > 20.0f)) {
                spD0.unk4 = (0.4f * (spD0.unk4 - 20.0f)) + 20.0f;
            }
            sp20 = (f64) sp90.unk30;
            sp28 = (f64) sp90.unk38;
            temp_f3_337 = 20.0f + (spD0.unk4 - M2C_FIELD(MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_77, MKModel **, 0xA0)), f32 *, 0x34));
            sp90.unk30 = (f32) sp20;
            sp90.unk38 = (f32) sp28;
            unksp24 = temp_f3_337;
            sp90.unk34 = temp_f3_337;
            sp90.unk3C = 1.0f;
        }
        temp_r30_344 = M2C_FIELD(temp_r29_286, s32 *, 0xB4);
        ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r31_77, MKModel **, 0xA0))))->SetCustomMatrix(temp_r30_344, &sp90, (AnimationMatrixPosition) 2, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'ShockWave' to
s32 ShockWave::Start(MKVector3 arg0, float arg1, float arg2, bool arg3, bool arg4, bool arg5) {
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_415;
    s32 temp_r25_452;
    s32 temp_r25_478;
    s32 var_ctr_389;
    s32 var_r23_473;
    s32 var_r26_474;
    s32 var_r31_387;
    s32 var_r3_388;
    void *temp_r24_472;
    void *temp_r3_424;
    void *temp_r3_435;
    void *temp_r3_446;
    void *temp_r4_460;
    void *temp_r5_447;

    var_r31_387 = 0;
    var_r3_388 = 0;
    var_ctr_389 = 4;
loop_1:
    if ((u8) *(this + (var_r3_388 + 0x90)) != 0) {
        var_r31_387 += 1;
        var_r3_388 += 0x28;
        var_ctr_389 -= 1;
        if (var_ctr_389 != 0) {
            goto loop_1;
        }
    }
    if (var_r31_387 >= 4) {
        return -1;
    }
    if ((s32) this->unk150 == 0) {
        MKShockWave_Enable(*((MKVector3 *) arg0));
        MKModel_SetPosition(this->unk4, *((MKVector3 *) arg0));
    }
    temp_f1_415 = arg2 / 500.0f;
    sp18 = temp_f1_415;
    sp10 = temp_f1_415;
    sp14 = temp_f1_415;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    temp_r3_424 = M2C_FIELD(checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x1C);
    M2C_FIELD(temp_r3_424, f64 *, 0) = (f64) this->unk130;
    M2C_FIELD(temp_r3_424, f64 *, 8) = (f64) this->unk138;
    M2C_FIELD(temp_r3_424, f64 *, 0x10) = (f64) this->unk140;
    M2C_FIELD(temp_r3_424, f64 *, 0x18) = (f64) this->unk148;
    temp_r3_435 = M2C_FIELD(checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x1C);
    M2C_FIELD(temp_r3_435, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_435, f64 *, 0) * sp20);
    M2C_FIELD(temp_r3_435, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_435, f32 *, 8) * (f32) sp28);
    temp_r3_446 = M2C_FIELD(checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), void **, 0x1C);
    temp_r5_447 = temp_r3_446 + 0x10;
    M2C_FIELD(temp_r5_447, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_447, f64 *, 0) * sp20);
    temp_r25_452 = var_r31_387 * 0x28;
    M2C_FIELD(temp_r5_447, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_446, f32 *, 0x18) * (f32) sp28);
    MKModel_SetPosition(M2C_FIELD((this + temp_r25_452), MKModel **, 0xA0), *((MKVector3 *) arg0));
    temp_r4_460 = this + temp_r25_452;
    M2C_FIELD(temp_r4_460, f32 *, 0x9C) = arg1;
    M2C_FIELD(temp_r4_460, f32 *, 0x94) = arg2;
    M2C_FIELD(temp_r4_460, s8 *, 0x90) = 1;
    M2C_FIELD(temp_r4_460, f32 *, 0x98) = 0.0f;
    this->unk150 += 1;
    sp30.SetIdentity();
    temp_r24_472 = this + temp_r25_452;
    var_r23_473 = 0;
    var_r26_474 = 0;
    do {
        temp_r25_478 = *(temp_r24_472 + (var_r26_474 + 0xA4));
        ((Animation *) (MKModel_GetAnimation(M2C_FIELD(temp_r24_472, MKModel **, 0xA0))))->SetCustomMatrix(temp_r25_478, &sp30, (AnimationMatrixPosition) 2, 0U);
        var_r23_473 += 1;
        var_r26_474 += 4;
    } while (var_r23_473 <= 4);
    this->unk160 = arg3;
    this->unk161 = arg4;
    this->unk162 = arg5;
    UpdateShockWave(var_r31_387);
    return var_r31_387;
}
#endif

void ShockWave::Draw() {
    s32 var_r29_525;
    s32 var_r31_526;
    void *temp_r30_528;
    void *temp_r3_565;
    Matrix arg_sp30;
    Matrix arg_sp20;
    f32 arg_sp24;
    f64 arg_sp10;
    f64 arg_sp18;
    f32 arg_sp60;
    f32 arg_sp64;
    f32 arg_sp68;
    f32 arg_sp6C;

    if ((u8) this->unk160 != 0) {
        var_r29_525 = 0;
        var_r31_526 = 0;
        do {
            temp_r30_528 = (s8 *) this + var_r31_526;
            if ((u8) M2C_FIELD(temp_r30_528, u8 *, 0x90) != 0) {
                M2C_STRUCT_COPY(&arg_sp30, (void *) (MKModel_GetWorldMatrix(this->unk15C) - 4 + 4), 0x40);
                arg_sp30.SetIdentity();
                MKView_GetCameraMatrix();
                arg_sp20.GetRotationPYR();
                arg_sp30.SetRotationYaw(arg_sp24 - 3.1415927f);
                arg_sp30.RotateRoll((Matrix *) &arg_sp30, M2C_FIELD(temp_r30_528, f32 *, 0x98));
                arg_sp30.Scale3x3((Matrix *) &arg_sp30, 0.015f * M2C_FIELD(temp_r30_528, f32 *, 0x9C));
                temp_r3_565 = this->unk8;
                arg_sp10 = M2C_FIELD(temp_r3_565, f64 *, 0x30);
                arg_sp18 = M2C_FIELD(temp_r3_565, f64 *, 0x38);
                arg_sp60 = (f32) arg_sp10;
                arg_sp64 = ((f32 *) &arg_sp10)[1];
                arg_sp68 = (f32) arg_sp18;
                arg_sp6C = 1.0f;
                MKModel_SetAlpha(this->unk15C, 1.0f - (M2C_FIELD(temp_r30_528, f32 *, 0x9C) / M2C_FIELD(temp_r30_528, f32 *, 0x94)));
                MKModel_SetWorldMatrix(this->unk15C, *((Matrix *) &arg_sp30));
                MKModel_Draw(this->unk15C, NULL);
                MKModel_SetAlpha(M2C_FIELD(temp_r30_528, MKModel **, 0xA0), MKModel_GetAlpha(this->unk15C));
                MKModel_Draw(M2C_FIELD(temp_r30_528, MKModel **, 0xA0), NULL);
            }
            var_r29_525 += 1;
            var_r31_526 += 0x28;
        } while (var_r29_525 < 4);
    }
}

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::GetHeroType()')
void ShockWave::Update() {
    s8 spD1;
    s8 spD0;
    s32 spCC;
    f32 spC8;
    s32 spC4;
    s8 spC2;
    s8 spC1;
    s8 spC0;
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    ShockWave *spAC;
    s32 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    s32 sp84;
    s32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    HeroInterface sp40;
    f64 sp30;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_691;
    f32 temp_f0_800;
    f32 temp_f1_676;
    f32 temp_f2_680;
    f32 temp_f2_796;
    f32 temp_f30_684;
    f32 temp_f5_941;
    f32 var_f29_658;
    f32 var_f3_789;
    f32 var_f4_722;
    f64 temp_f1_728;
    f64 temp_f1_734;
    f64 temp_f1_738;
    f64 temp_f1_805;
    s32 temp_r3_757;
    s32 var_r0_767;
    s32 var_r28_626;
    s32 var_r30_625;
    u8 temp_ret_815;
    void *temp_r27_640;
    void *temp_r31_628;

    var_r30_625 = 0;
    var_r28_626 = 0;
    do {
        temp_r31_628 = this + var_r28_626;
        if ((u8) M2C_FIELD(temp_r31_628, u8 *, 0x90) != 0) {
            M2C_FIELD(temp_r31_628, f32 *, 0x9C) = (f32) ((1200.0f * gUpdateTimeDelta) + M2C_FIELD(temp_r31_628, f32 *, 0x9C));
            temp_r27_640 = MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_628, MKModel **, 0xA0)) + 0x30;
            sp40.GetPos();
            sp10 = sp40 - M2C_FIELD(temp_r27_640, f64 *, 0);
            sp18 = sp48 - M2C_FIELD(temp_r27_640, f32 *, 8);
            var_f29_658 = -((0.166f * M2C_FIELD(temp_r31_628, f32 *, 0x94)) - M2C_FIELD(temp_r31_628, f32 *, 0x9C));
            sp70 = sp10;
            sp50 = sp10;
            sp58 = (f64) sp18;
            sp78 = (f64) sp18;
            unksp74 = 0.0f;
            if (var_f29_658 > 0.0f) {

            } else {
                var_f29_658 = 0.0f;
            }
            temp_f1_676 = (f32) sp70 * (f32) sp70;
            temp_f2_680 = (f32) sp78 * (f32) sp78;
            temp_f30_684 = temp_f2_680 + (temp_f1_676 + (unksp74 * unksp74));
            if (M2C_FIELD(*gb, u8 (**)(void **, f32, f32), 0x64)(gb, temp_f1_676, temp_f2_680) == 0) {
                temp_f0_691 = 0.9f * M2C_FIELD(temp_r31_628, f32 *, 0x9C);
                if ((temp_f30_684 < (temp_f0_691 * temp_f0_691)) && (temp_f30_684 > (var_f29_658 * var_f29_658)) && ((u8) this->unk160 != 0) && (((u8) this->unk161 != 0) || ((u8) this->unk162 != 0))) {
                    sp60 = sp70;
                    sp68 = sp78;
                    sp84 = 0;
                    var_f4_722 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
                    if (var_f4_722 > 0.000001f) {
                        if (var_f4_722 > 0.0f) {
                            temp_f1_728 = __frsqrte(var_f4_722);
                            temp_f1_734 = 0.5 * temp_f1_728 * -(((f64) var_f4_722 * (temp_f1_728 * temp_f1_728)) - 3.0);
                            temp_f1_738 = 0.5 * temp_f1_734 * -(((f64) var_f4_722 * (temp_f1_734 * temp_f1_734)) - 3.0);
                            var_f4_722 = (f32) ((f64) var_f4_722 * (0.5 * temp_f1_738 * -(((f64) var_f4_722 * (temp_f1_738 * temp_f1_738)) - 3.0)));
                        } else if (var_f4_722 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_722 = __float_nan;
                        } else {
                            sp8 = var_f4_722;
                            temp_r3_757 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_757) {  /* irregular */
                            case 0x7F800000:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_767 = 1;
                                } else {
                                    var_r0_767 = 2;
                                }
                                break;
                            case 0x0:
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_767 = 5;
                                } else {
                                    var_r0_767 = 3;
                                }
                                break;
                            default:
                                var_r0_767 = 4;
                                break;
                            }
                            if (var_r0_767 == 1) {
                                var_f4_722 = __float_nan;
                            }
                        }
                        var_f3_789 = 1.0f / var_f4_722;
                    } else {
                        var_f3_789 = 0.0f;
                    }
                    temp_f2_796 = (f32) sp60 * var_f3_789;
                    temp_f0_800 = (f32) sp68 * var_f3_789;
                    sp60 = temp_f2_796;
                    unksp64 *= var_f3_789;
                    sp68 = temp_f0_800;
                    temp_f1_805 = (f64) sp60 * 5.578592756e-315;
                    sp60 = temp_f1_805;
                    sp68 = temp_f0_800 * 205.0f;
                    temp_ret_815 = M2C_FIELD(*gb, u8 (**)(void **, f64, f32), 0x50)(gb, temp_f1_805, temp_f2_796);
                    if (temp_ret_815 == 0) {
                        Console_Execute(Str_Printf("send %s %d", this->unk158, this->unk154, M2C_BITWISE(f32, temp_ret_815)));
                    }
                    if ((u8) this->unk161 != 0) {
                        sp80 = 7;
                        spA8 = 1;
                        spAC = this;
                        sp88 = sp60;
                        sp90 = (f64) sp68;
                        spC0 = 0;
                        spCC = 2;
                        spC8 = 10.0f;
                        spC1 = 0;
                        spC2 = 1;
                        spC4 = -1;
                        sp98 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        spA0 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        spD0 = 0;
                        if (this != NULL) {
                            ((MKProp *) &sp30)->GetPos();
                            spB0 = sp30;
                            spB8 = sp38;
                        } else {
                            spB0 = 0.0f;
                            unkspB4 = 0.0f;
                            spB8 = 0.0f;
                        }
                        spD1 = 0;
                    } else if ((u8) this->unk162 != 0) {
                        sp80 = 7;
                        spA8 = 1;
                        spAC = this;
                        sp88 = sp60;
                        sp90 = (f64) sp68;
                        spC0 = 1;
                        spCC = 2;
                        spC8 = 0.0f;
                        spC1 = 0;
                        spC2 = 1;
                        spC4 = -1;
                        sp98 = M2C_FIELD(&MKVector3::one, f64 *, 0);
                        spA0 = M2C_FIELD(&MKVector3::one, f64 *, 8);
                        spD0 = 0;
                        if (this != NULL) {
                            ((MKProp *) &sp20)->GetPos();
                            spB0 = sp20;
                            spB8 = sp28;
                        } else {
                            spB0 = 0.0f;
                            unkspB4 = 0.0f;
                            spB8 = 0.0f;
                        }
                        spD1 = 0;
                    }
                    M2C_FIELD(*gb, M2C_UNK (**)(void **, s32 *), 0x1C)(gb, &sp80);
                }
            }
            UpdateShockWave(var_r30_625);
            M2C_FIELD(temp_r31_628, f32 *, 0x98) = (f32) (M2C_FIELD(temp_r31_628, f32 *, 0x98) + 0.02f);
            temp_f5_941 = M2C_FIELD(temp_r31_628, f32 *, 0x9C);
            MKShockWave_Set(var_r30_625, temp_f5_941 - 400.0f, 500.0f, 150.0f * (1.0f - (temp_f5_941 / M2C_FIELD(temp_r31_628, f32 *, 0x94))));
            if (M2C_FIELD(temp_r31_628, f32 *, 0x9C) > M2C_FIELD(temp_r31_628, f32 *, 0x94)) {
                M2C_FIELD(temp_r31_628, u8 *, 0x90) = 0U;
                this->unk150 -= 1;
                if ((s32) this->unk150 == 0) {
                    MKShockWave_Disable();
                }
            }
        }
        var_r30_625 += 1;
        var_r28_626 += 0x28;
    } while (var_r30_625 < 4);
}
#endif

void ShockWave::SetMessage(int arg0, const char *arg1) {
    this->unk154 = arg0;
    this->unk158 = (s8 *) arg1;
}

void ShockWave::Reset() {
    s32 temp_r0_1002;
    s32 var_ctr_1000;
    s32 var_r3_998;

    KDProp::Reset();
    var_r3_998 = 0;
    this->unk150 = 0;
    var_ctr_1000 = 4;
    do {
        temp_r0_1002 = var_r3_998 + 0x90;
        var_r3_998 += 0x28;
        *((s8 *) this + temp_r0_1002) = 0;
        var_ctr_1000 -= 1;
    } while (var_ctr_1000 != 0);
    MKShockWave_Disable();
}

void ShockWave::Deinit() {
    s32 var_r30_1022;
    s32 var_r31_1023;

    var_r30_1022 = 0;
    var_r31_1023 = 0;
    do {
        MKModel_Destroy(*(MKModel **) ((s8 *) this + (var_r31_1023 + 0xA0)));
        var_r30_1022 += 1;
        var_r31_1023 += 0x28;
    } while (var_r30_1022 < 4);
    MKModel_Destroy(this->unk15C);
    MKShockWave_Disable();
    KDProp::Deinit();
}

void ShockWave::LoadDone() {
    Animation *temp_r3_1075;
    MKHeap **temp_r3_1102;
    s32 var_r28_1057;
    s32 var_r30_1056;
    void *temp_r29_1065;

    KDProp::LoadDone();
    this->unk160 = 1;
    var_r30_1056 = 0;
    var_r28_1057 = 0;
    this->unk161 = 1;
    this->unk162 = 1;
    this->unk154 = 0;
    this->unk158 = NULL;
    this->unk150 = 0;
    do {
        temp_r29_1065 = this + var_r30_1056;
        M2C_FIELD(temp_r29_1065, s8 *, 0x90) = 0;
        M2C_FIELD(temp_r29_1065, MKModel **, 0xA0) = MKModel_Create("P0182_Dustwave", "P0182_Dustwave", 2, NULL);
        temp_r3_1075 = MKModel_GetAnimation(M2C_FIELD(temp_r29_1065, MKModel **, 0xA0));
        temp_r3_1075->EnableCustomMatrices(1U);
        M2C_FIELD(temp_r29_1065, s32 *, 0xA4) = temp_r3_1075->GetNodeIndex("Z_Root");
        M2C_FIELD(temp_r29_1065, s32 *, 0xA8) = temp_r3_1075->GetNodeIndex("Z_Rim_North");
        M2C_FIELD(temp_r29_1065, s32 *, 0xAC) = temp_r3_1075->GetNodeIndex("Z_Rim_East");
        M2C_FIELD(temp_r29_1065, s32 *, 0xB0) = temp_r3_1075->GetNodeIndex("Z_Rim_South");
        M2C_FIELD(temp_r29_1065, s32 *, 0xB4) = temp_r3_1075->GetNodeIndex("Z_Rim_West");
        temp_r3_1102 = MKModel_GetBoundingVolume(M2C_FIELD(temp_r29_1065, MKModel **, 0xA0), (SubObjectType) 0, -1);
        var_r28_1057 += 1;
        var_r30_1056 += 0x28;
        this->unk130 = M2C_FIELD(temp_r3_1102, f64 *, 0);
        this->unk138 = M2C_FIELD(temp_r3_1102, f64 *, 8);
        this->unk140 = M2C_FIELD(temp_r3_1102, f64 *, 0x10);
        this->unk148 = M2C_FIELD(temp_r3_1102, f64 *, 0x18);
    } while (var_r28_1057 < 4);
    this->unk15C = MKModel_Create("P0191_Warp", NULL, 2, NULL);
}

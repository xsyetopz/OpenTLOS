#include "spyro/source/GameMessages.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EventCamera.h"
#include "common/Source/MKCollision.h"
#include <m2c_macros.h>

extern s32 GS_PLACEHOLDER;

#if 0 // DRAFT: illegal explicit conversion from 'EventCamera' to
u8 FuryEventCameraMsg::IsSenderBehindWall(EventCamera *arg0) {
    EventCamera sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f2_50;
    f32 temp_f3_52;
    f32 temp_f3_56;
    f32 var_f4_126;
    f32 var_f5_59;
    f64 *var_r4_200;
    f64 temp_f0_34;
    f64 temp_f1_65;
    f64 temp_f1_71;
    f64 temp_f1_75;
    s32 temp_r31_147;
    s32 temp_r3_94;
    s32 var_r0_104;
    s32 var_r29_133;
    void *temp_r3_31;

    if ((void *) this->unk4 != NULL) {
        sp90.GetSourceStart();
        temp_r3_31 = M2C_FIELD(this->unk4, void **, 8);
        temp_f0_34 = M2C_FIELD(temp_r3_31, f64 *, 0x38);
        sp90.unk50 = M2C_BITWISE(f64, sp90);
        sp90.unk40 = M2C_FIELD(temp_r3_31, f64 *, 0x30);
        sp90.unk58 = M2C_BITWISE(f64, sp90.unk8);
        sp90.unk48 = temp_f0_34;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp90.unk30 = sp40;
        sp48 = (f32) temp_f0_34 - (f32) sp90.unk58;
        temp_f2_50 = M2C_BITWISE(f32, sp90.unk30);
        temp_f3_52 = M2C_BITWISE(f32, sp90.unk34);
        sp90.unk38 = (f64) sp48;
        temp_f3_56 = M2C_BITWISE(f32, sp90.unk38);
        var_f5_59 = (temp_f3_56 * temp_f3_56) + ((temp_f2_50 * temp_f2_50) + (temp_f3_52 * temp_f3_52));
        if (var_f5_59 > 0.000001f) {
            if (var_f5_59 > 0.0f) {
                temp_f1_65 = __frsqrte(var_f5_59);
                temp_f1_71 = 0.5 * temp_f1_65 * -(((f64) var_f5_59 * (temp_f1_65 * temp_f1_65)) - 3.0);
                temp_f1_75 = 0.5 * temp_f1_71 * -(((f64) var_f5_59 * (temp_f1_71 * temp_f1_71)) - 3.0);
                var_f5_59 = (f32) ((f64) var_f5_59 * (0.5 * temp_f1_75 * -(((f64) var_f5_59 * (temp_f1_75 * temp_f1_75)) - 3.0)));
            } else if (var_f5_59 < M2C_BITWISE(f32, 0.0)) {
                var_f5_59 = __float_nan;
            } else {
                sp8 = var_f5_59;
                temp_r3_94 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_94) {               /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_104 = 1;
                    } else {
                        var_r0_104 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_104 = 5;
                    } else {
                        var_r0_104 = 3;
                    }
                    break;
                default:
                    var_r0_104 = 4;
                    break;
                }
                if (var_r0_104 == 1) {
                    var_f5_59 = __float_nan;
                }
            }
            var_f4_126 = 1.0f / var_f5_59;
        } else {
            var_f4_126 = 0.0f;
            var_f5_59 = 0.0f;
        }
        var_r29_133 = 1;
        sp90.unk30 = M2C_BITWISE(f32, sp90.unk30) * var_f4_126;
        temp_r31_147 = (s32) (var_f5_59 / 500.0f) + 1;
        sp90.unk34 = M2C_BITWISE(f32, sp90.unk34) * var_f4_126;
        sp90.unk38 = M2C_BITWISE(f32, sp90.unk38) * var_f4_126;
loop_28:
        if (var_r29_133 > temp_r31_147) {
            goto block_29;
        }
        sp70.operator*(500.0f * (f32) (var_r29_133 - 1));
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
        sp80 = sp30;
        sp38 = (f32) sp90.unk58 + sp70.unk8;
        sp90.unk20 = sp30;
        sp88 = (f64) sp38;
        sp90.unk28 = (f64) sp38;
        if (var_r29_133 != temp_r31_147) {
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            sp60 = sp20;
            sp28 = sp90.unk38 * (500.0f * (f32) var_r29_133);
            sp68 = (f64) sp28;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f3, $f0 */);
            var_r4_200 = &sp50;
            sp50 = sp10;
            sp18 = (f32) sp90.unk58 + (f32) sp68;
            sp58 = (f64) sp18;
        } else {
            var_r4_200 = (f64 *) &sp90.unk40;
        }
        sp90.unk10 = M2C_FIELD(var_r4_200, f64 *, 0);
        sp90.unk18 = M2C_FIELD(var_r4_200, f64 *, 8);
        if (MKCollision_RayCollide(*((MKVector3 *) &sp90.unk20), *((MKVector3 *) &sp90.unk10), (MKCollisionResult *) &sp90.unk60, (MKCollisionMode) 5, 0) != 0) {
            return 1U;
        }
        var_r29_133 += 1;
        goto loop_28;
    }
block_29:
    return 0U;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 FuryEventCameraMsg::AddCamera(EventCamera *arg0) {
    f64 sp80;
    f64 sp78;
    M2C_UNK sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    M2C_UNK sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    s32 temp_r0_280;
    s32 var_ctr_328;
    s32 var_r30_325;
    s32 var_r3_327;
    s32 var_r6_326;
    void *temp_r3_357;
    void *temp_r5_289;
    void *temp_r5_345;

    if (IsSenderBehindWall(arg0) == 0) {
        temp_r0_280 = this->unk58;
        if (temp_r0_280 < 0xA) {
            M2C_FIELD((this + (temp_r0_280 * 4)), EventCamera **, 8) = arg0;
            temp_r5_289 = M2C_FIELD(this->unk4, void **, 8);
            sp58 = M2C_FIELD(temp_r5_289, f64 *, 0x30);
            sp60 = M2C_FIELD(temp_r5_289, f64 *, 0x38);
            sp68.GetSourceStart();
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp78 = sp18;
            sp20 = sp70 - (f32) sp60;
            sp80 = (f64) sp20;
            M2C_FIELD((this + (this->unk58 * 4)), f32 *, 0x30) = (f32) (((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + (unksp7C * unksp7C)));
            this->unk58 += 1;
            return 1;
        }
        var_r30_325 = 0;
        var_r6_326 = 1;
        var_r3_327 = 4;
        var_ctr_328 = 9;
        do {
            if (*(this + (var_r3_327 + 0x30)) > *(this + ((var_r30_325 * 4) + 0x30))) {
                var_r30_325 = var_r6_326;
            }
            var_r6_326 += 1;
            var_r3_327 += 4;
            var_ctr_328 -= 1;
        } while (var_ctr_328 != 0);
        temp_r5_345 = M2C_FIELD(this->unk4, void **, 8);
        sp28 = M2C_FIELD(temp_r5_345, f64 *, 0x30);
        sp30 = M2C_FIELD(temp_r5_345, f64 *, 0x38);
        sp38.GetSourceStart();
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_r3_357 = this + (var_r30_325 * 4);
        sp48 = sp8;
        sp10 = sp40 - (f32) sp30;
        sp50 = (f64) sp10;
        if ((((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C))) < M2C_FIELD(temp_r3_357, f32 *, 0x30)) {
            M2C_FIELD(temp_r3_357, EventCamera **, 8) = arg0;
            return 1;
        }
        return 0;
    }
    return 0;
}
#endif

void GetNearestEventCameraMsg::Test(MKProp *arg0, const MKVector3 &arg1) {
    f32 temp_f1_410;
    f32 temp_f2_403;
    f32 temp_f3_400;
    f32 temp_f4_397;

    temp_f4_397 = this->unkC - arg1.unk4;
    temp_f3_400 = this->unk8 - arg1.unk0;
    temp_f2_403 = this->unk10 - arg1.unk8;
    temp_f1_410 = (temp_f2_403 * temp_f2_403) + ((temp_f3_400 * temp_f3_400) + (temp_f4_397 * temp_f4_397));
    if ((M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x10000) && (temp_f1_410 < this->unk20) && (((MKProp *) this->unk18 == NULL) || (temp_f1_410 < this->unk1C))) {
        this->unk18 = arg0;
        this->unk1C = temp_f1_410;
    }
}

void BreathHitMessage::Init(MKProp *arg0, float arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_457;
    f64 temp_f1_456;
    u32 temp_r4_450;
    void *temp_r4_453;

    this->unk0 = 5;
    this->unk8 = (u32) arg0;
    this->unk34 = arg1;
    this->unk38 = arg2;
    this->unk3C = arg3;
    this->unk40 = arg4;
    this->unk44 = arg5;
    this->unk50 = 0;
    this->unk48 = arg6;
    this->unk4C = arg7;
    this->unk20.unk0 = 0.0f;
    this->unk20.unk4 = 0.0f;
    this->unk20.unk8 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    temp_r4_450 = this->unk8;
    if (temp_r4_450 != 0) {
        temp_r4_453 = M2C_FIELD(temp_r4_450, void **, 8);
        if (temp_r4_453 != NULL) {
            temp_f1_456 = M2C_FIELD(temp_r4_453, f64 *, 0x30);
            temp_f0_457 = M2C_FIELD(temp_r4_453, f64 *, 0x38);
            sp8 = temp_f1_456;
            M2C_FIELD(this, f32 *, 0x10) = temp_f1_456;
            sp10 = temp_f0_457;
            M2C_FIELD(this, f32 *, 0x18) = temp_f0_457;
        }
    }
    this->unk30 = NULL;
}

void BreathHitMessage::Init(MKProp *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    Init(arg0, (f32) arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

#if 0 // DRAFT: undefined identifier 'unkspC'
void IsInAlertRangeMsg::Test(Enemy *arg0) {
    f64 sp10;
    f64 sp8;
    f32 temp_f1_518;
    f32 temp_f3_514;
    f32 temp_f4_509;
    f32 temp_f5_508;
    void *temp_r5_499;

    temp_r5_499 = arg0->unk8;
    sp8 = M2C_FIELD(temp_r5_499, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r5_499, f64 *, 0x38);
    temp_f5_508 = unkspC - this->unkC;
    temp_f4_509 = (f32) sp8 - this->unk8;
    temp_f3_514 = (f32) sp10 - this->unk10;
    temp_f1_518 = (temp_f3_514 * temp_f3_514) + ((temp_f4_509 * temp_f4_509) + (temp_f5_508 * temp_f5_508));
    if ((temp_f1_518 < this->unk18) && (((Enemy *) this->unk1C == NULL) || (temp_f1_518 < this->unk20))) {
        this->unk1C = arg0;
        this->unk20 = temp_f1_518;
    }
}
#endif

void IsInAlertRangeMsg::Init(const MKVector3 &arg0, float arg1) {
    this->unk0 = 0x72;
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk18 = arg1 * arg1;
    this->unk1C = NULL;
    this->unk20 = 3.4028235e38f;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void FindNearestCollectableMsg::Test(Collectable *arg0) {
    f32 sp8;
    f32 temp_f1_599;
    f32 temp_f3_595;
    f32 temp_f4_591;
    f32 temp_f5_589;
    s32 temp_r5_576;

    if ((arg0 != NULL) && (this->unk18 & (1 << arg0->GetItemType())) && ((s32) arg0->unkD4 == 6)) {
        temp_r5_576 = this->unk1C;
        this->unk1C = temp_r5_576 + 1;
        M2C_FIELD(arg0->__vptr, M2C_UNK (**)(f32 *, Collectable *, s32), 0x44)(&sp8, arg0, temp_r5_576);
        temp_f5_589 = spC - this->unkC;
        temp_f4_591 = sp8 - this->unk8;
        temp_f3_595 = sp10 - this->unk10;
        temp_f1_599 = (temp_f3_595 * temp_f3_595) + ((temp_f4_591 * temp_f4_591) + (temp_f5_589 * temp_f5_589));
        if (temp_f1_599 < this->unk20) {
            this->unk24 = arg0;
            this->unk20 = temp_f1_599;
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
HitHeroSndMsg::HitHeroSndMsg() {
    this->unk4 = 0;
    this->unk8 = GS_PLACEHOLDER;
    this->unk0 = 0x16;
    return this;
}
#endif

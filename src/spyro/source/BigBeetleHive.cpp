#include "spyro/source/BigBeetleHive.h"
#include "common/Source/Animation.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BeetleNestSmall.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/MeleeAttackHitMsg.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/StickyPS.h"
#include "unplaced_templates.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern s32 GS_OBBigHiveHit1;
extern s32 GS_OBBigHiveHit2;
extern s32 GS_OBBigHiveHit3;
extern s32 GS_OBBigHiveHit4;
extern s32 GS_OBBigHiveHit5;
extern s32 GS_OBBigHiveSmash1;
extern s32 GS_OBBigHiveSmash2;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: undefined identifier 'unk1E8'
void BigBeetleHive::EmitGoopDrips() {
    MKVector3 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_73;
    void *temp_r31_58;

    this->unk1E8 -= gUpdateTimeDelta;
    if (!(this->unk1E8 > 0.0f)) {
        this->unk1E8 = 1.0f;
        temp_r31_58 = checked_cast<BigBeetleHiveDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD((temp_r31_58 + (MKRand_Int(&gViewSeed, 0, 5) * 4)), s32 *, 0x170), &sp28);
        temp_f1_73 = MKRand_Float(&gViewSeed, 0.2f, 0.5f);
        sp10 = 0.0f;
        sp8 = 0.0f;
        spC = 0.0f;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        ((StickyPS *) (M2C_FIELD(temp_r31_58, StickyPS **, 0x16C)))->Emit(sp28, *((MKVector3 *) &sp18), temp_f1_73, 0.0f);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp60'
void BigBeetleHive::Message(MKMessage *arg0) {
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    BigBeetleHive ***temp_r5_119;
    BigBeetleHive **temp_r4_141;
    BigBeetleHive **temp_r4_145;
    BigBeetleHive **var_r4_122;
    BigBeetleHive *temp_r0_131;
    f32 temp_f2_315;
    f32 temp_r4_261;
    f32 temp_r4_417;
    f32 var_f3_238;
    f32 var_f3_394;
    f32 var_f4_171;
    f32 var_f4_327;
    f64 temp_f1_177;
    f64 temp_f1_183;
    f64 temp_f1_187;
    f64 temp_f1_333;
    f64 temp_f1_339;
    f64 temp_f1_343;
    s32 temp_r0_105;
    s32 temp_r4_206;
    s32 temp_r4_362;
    s32 var_r0_216;
    s32 var_r0_372;
    void *temp_r3_118;
    void *temp_r3_304;

    temp_r0_105 = arg0->unk0;
    switch (temp_r0_105) {                          /* switch 1; irregular */
    case 4:                                         /* switch 1 */
        temp_r3_118 = checked_cast<MeleeAttackHitMsg *, MKMessage>(arg0);
        temp_r5_119 = M2C_FIELD(temp_r3_118, BigBeetleHive ****, 0x34);
        if (temp_r5_119 != NULL) {
            var_r4_122 = *temp_r5_119;
loop_11:
            temp_r0_131 = *var_r4_122;
            if (temp_r0_131 == NULL) {
                var_r4_122 = NULL;
            } else if (temp_r0_131 == this) {

            } else {
                var_r4_122 += 4;
                goto loop_11;
            }
            if (var_r4_122 == NULL) {
                goto block_14;
            }
        case 1:                                     /* switch 1 */
            return;
        }
block_14:
        if (temp_r5_119 != NULL) {
            temp_r4_141 = *temp_r5_119;
            if ((u32) M2C_FIELD(temp_r4_141, u32 *, -4) != 0U) {
                temp_r4_145 = temp_r4_141 - 4;
                *temp_r5_119 = temp_r4_145;
                *temp_r4_145 = this;
            }
        }
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        spA0 = sp60;
        sp68 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) - M2C_FIELD(temp_r3_118, f32 *, 0x18);
        spA8 = (f64) sp68;
        var_f4_171 = ((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + (unkspA4 * unkspA4));
        if (var_f4_171 > 1e-12f) {
            if (var_f4_171 > 0.0f) {
                temp_f1_177 = __frsqrte(var_f4_171);
                temp_f1_183 = 0.5 * temp_f1_177 * -(((f64) var_f4_171 * (temp_f1_177 * temp_f1_177)) - 3.0);
                temp_f1_187 = 0.5 * temp_f1_183 * -(((f64) var_f4_171 * (temp_f1_183 * temp_f1_183)) - 3.0);
                var_f4_171 = (f32) ((f64) var_f4_171 * (0.5 * temp_f1_187 * -(((f64) var_f4_171 * (temp_f1_187 * temp_f1_187)) - 3.0)));
            } else if (var_f4_171 < M2C_BITWISE(f32, 0.0)) {
                var_f4_171 = __float_nan;
            } else {
                spC = var_f4_171;
                temp_r4_206 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r4_206) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_216 = 1;
                    } else {
                        var_r0_216 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_216 = 5;
                    } else {
                        var_r0_216 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_216 = 4;
                    break;
                }
                if (var_r0_216 == 1) {
                    var_f4_171 = __float_nan;
                }
            }
            var_f3_238 = 1.0f / var_f4_171;
        } else {
            var_f3_238 = 0.0f;
        }
        sp54 = unkspA4 * var_f3_238;
        sp50 = (f32) spA0 * var_f3_238;
        sp58 = (f32) spA8 * var_f3_238;
        spC0 = (f64) sp50;
        spC8 = (f64) sp58;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r4_261 = this->unk198;
        sp90 = sp20;
        sp28 = (f32) spC8 * 50.0f;
        sp98 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_FIELD(temp_r4_261, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_261, f32 *, 8) + (f32) sp98);
        M2C_FIELD(temp_r3_118, s8 *, 0x3E) = 1;
        KDSound_Play3d(GS_OBBigHiveHit1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_OBBigHiveHit2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        KDSound_Play3d(GS_OBBigHiveHit3, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        return;
    case 5:                                         /* switch 1 */
        temp_r3_304 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        temp_f2_315 = M2C_FIELD((this->unk8 + 0x30), f32 *, 8) - M2C_FIELD(temp_r3_304, f32 *, 0x18);
        sp80 = sp40;
        sp48 = temp_f2_315;
        sp88 = (f64) sp48;
        var_f4_327 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (unksp84 * unksp84));
        if (var_f4_327 > 1e-12f) {
            if (var_f4_327 > 0.0f) {
                temp_f1_333 = __frsqrte(var_f4_327);
                temp_f1_339 = 0.5 * temp_f1_333 * -(((f64) var_f4_327 * (temp_f1_333 * temp_f1_333)) - 3.0);
                temp_f1_343 = 0.5 * temp_f1_339 * -(((f64) var_f4_327 * (temp_f1_339 * temp_f1_339)) - 3.0);
                var_f4_327 = (f32) ((f64) var_f4_327 * (0.5 * temp_f1_343 * -(((f64) var_f4_327 * (temp_f1_343 * temp_f1_343)) - 3.0)));
            } else if (var_f4_327 < M2C_BITWISE(f32, 0.0)) {
                var_f4_327 = __float_nan;
            } else {
                sp8 = var_f4_327;
                temp_r4_362 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r4_362) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_372 = 1;
                    } else {
                        var_r0_372 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_372 = 5;
                    } else {
                        var_r0_372 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_372 = 4;
                    break;
                }
                if (var_r0_372 == 1) {
                    var_f4_327 = __float_nan;
                }
            }
            var_f3_394 = 1.0f / var_f4_327;
        } else {
            var_f3_394 = 0.0f;
        }
        sp34 = unksp84 * var_f3_394;
        sp30 = (f32) sp80 * var_f3_394;
        sp38 = (f32) sp88 * var_f3_394;
        spB0 = (f64) sp30;
        spB8 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r4_417 = this->unk198;
        sp70 = sp10;
        sp18 = (f32) spB8 * 12.5f;
        sp78 = (f64) sp18;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_FIELD(temp_r4_417, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_417, f32 *, 8) + (f32) sp78);
        if ((s32) M2C_FIELD(temp_r3_304, s32 *, 0x38) != 3) {
            KDSound_Play3d(GS_OBBigHiveHit4, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            KDSound_Play3d(GS_OBBigHiveHit5, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            return;
        }
    default:                                        /* switch 1 */
        Shatterable::Message(arg0);
        break;
    }
}
#endif

#if 0 // DRAFT: illegal type
void BigBeetleHive::Shatter(bool arg0, MKVector3 *arg1, int arg2, MKVector3 *arg3) {
    KDSound_Play3d(GS_OBBigHiveSmash1, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    KDSound_Play3d(GS_OBBigHiveSmash2, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
    Shatterable::Shatter(arg0, arg1, arg2, arg3, 1U, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void BigBeetleHive::UpdateAttachedNests() {
    s32 var_r29_518;
    s32 var_r31_519;
    void *temp_r30_521;
    var_r29_518 = 0;
    var_r31_519 = 0;
    do {
        temp_r30_521 = this + var_r31_519;
        if ((void *) M2C_FIELD(temp_r30_521, void **, 0x1AC) != NULL) {
            MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(temp_r30_521, s32 *, 0x1B4), (Matrix *) &arg_sp10, 1U);
            MKModel_SetWorldMatrix(M2C_FIELD(M2C_FIELD(temp_r30_521, void **, 0x1AC), MKModel **, 4), *((Matrix *) &arg_sp10));
        }
        var_r29_518 += 1;
        var_r31_519 += 0xC;
    } while (var_r29_518 < 5);
}
#endif

#if 0 // DRAFT: ')' expected
void BigBeetleHive::Update() {
    Shatterable::Update();
    UpdateAttachedNests();
    if ((MKProp *) this->unk170 == (s32) (M2C_FIELD(checked_cast<BigBeetleHiveDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x160) - 1)) {
        EmitGoopDrips();
    }
}
#endif

#if 0 // DRAFT: function call 'Tools_GetMatchingRefPointIndex(MKModel *, signed char *)'
void BigBeetleHive::Resolve() {
    s32 var_r28_585;
    s32 var_r31_587;
    u16 temp_ret_599;
    void *temp_r29_589;

    Shatterable::Resolve();
    var_r28_585 = 0;
    var_r31_587 = 0;
    do {
        temp_r29_589 = this + var_r31_587;
        if ((MKSceneManager *) M2C_FIELD(temp_r29_589, MKSceneManager **, 0x1B0) != (MKSceneManager *)-1) {
            temp_ret_599 = Tools_GetMatchingRefPointIndex(this->unk4, Str_Printf("r_attach%d", var_r28_585));
            M2C_FIELD(temp_r29_589, s32 *, 0x1B4) = (s32) temp_ret_599;
            M2C_FIELD(temp_r29_589, s32 *, 0x1AC) = checked_cast<BeetleNestSmall *, MKProp>(((MKSceneManager *) (M2C_FIELD(temp_r29_589, MKSceneManager **, 0x1B0)))->PropResolver_Resolve((s32) (u32) (u64) temp_ret_599));
        }
        var_r28_585 += 1;
        var_r31_587 += 0xC;
    } while (var_r28_585 < 5);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void *' to
void BigBeetleHive::LoadDone() {
    Shatterable::LoadDone();
    this->unk198 = M2C_BITWISE(f32, MKDynamicBone_GetDynamicBone(this->unk4, ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeIndex("d_spine1")));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
s32 BigBeetleHive::LoadLine(MKIniLine *arg0) {
    f32 var_f1_654;
    s32 temp_ret_654;
    s32 temp_ret_674;
    s32 var_r29_661;
    s32 var_r31_663;

    temp_ret_654 = Shatterable::LoadLine(arg0);
    var_f1_654 = M2C_BITWISE(f32, temp_ret_654);
    if (temp_ret_654 != 0) {
        return 1;
    }
    var_r29_661 = 0;
    var_r31_663 = 0;
loop_3:
    temp_ret_674 = arg0->LoadInt(Str_Printf("NestID%d", var_r29_661, var_f1_654), this + (var_r31_663 + 0x1B0), 0);
    var_f1_654 = M2C_BITWISE(f32, temp_ret_674);
    if (temp_ret_674 != 0) {
        return 1;
    }
    var_r29_661 += 1;
    var_r31_663 += 0xC;
    if (var_r29_661 >= 5) {
        return 0;
    }
    goto loop_3;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1E8'
void BigBeetleHive::Init() {
    s32 var_ctr_707;
    s32 var_r3_704;
    void *temp_r6_709;

    Shatterable::Init();
    var_r3_704 = 0;
    this->unk198 = 0.0f;
    var_ctr_707 = 5;
    do {
        temp_r6_709 = this + var_r3_704;
        var_r3_704 += 0xC;
        M2C_FIELD(temp_r6_709, s32 *, 0x1B0) = -1;
        M2C_FIELD(temp_r6_709, s32 *, 0x1AC) = 0;
        M2C_FIELD(temp_r6_709, s32 *, 0x1B4) = -1;
        var_ctr_707 -= 1;
    } while (var_ctr_707 != 0);
    this->unk1E8 = 0.0f;
}
#endif

#if 0 // DRAFT: function call 'Tools_GetMatchingRefPointIndex(MKModel *, signed char *)'
void BigBeetleHiveDescriptor::LoadDone() {
    s32 temp_r0_746;
    s32 var_r29_734;
    s32 var_r31_736;
    u16 temp_r3_744;

    ShatterableDescriptor::LoadDone();
    var_r29_734 = 0;
    var_r31_736 = 0;
    do {
        temp_r3_744 = Tools_GetMatchingRefPointIndex(this->unk2C, Str_Printf("r_fxemit%d", var_r29_734));
        var_r29_734 += 1;
        temp_r0_746 = var_r31_736 + 0x170;
        var_r31_736 += 4;
        *(this + temp_r0_746) = (s32) temp_r3_744;
    } while (var_r29_734 < 5);
}
#endif

#if 0 // DRAFT: function call 'checked_cast(void *)' does not match
void BigBeetleHiveDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk16C = checked_cast<StickyPS *, MKProp>(gMK->CreateProp("FireGoopPS"));
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<BeetleNestSmall *, MKProp>(MKProp *arg0) {

}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<BigBeetleHiveDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

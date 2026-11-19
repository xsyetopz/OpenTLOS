#include "spyro/source/CollisionObject.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/ShatterExtendedMsg.h"
#include "spyro/source/ShatterOnCollisionMsg.h"
#include "unplaced_templates.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern void **gMK;
static M2C_UNK lit_621;                                /* unable to generate initializer: unknown type */
static M2C_UNK lit_623;                                /* unable to generate initializer: unknown type */

static M2C_UNK lit_819;                                /* unable to generate initializer: unknown type; const */

void CollisionObject::IgnoreAll(bool arg0) {
    if (arg0 != 0) {
        this->unk468 |= 2;
        return;
    }
    this->unk468 &= 0xFFFFFFFD;
}

#if 0 // DRAFT: illegal operand
s32 ContextInfo::HitID(unsigned int arg0) {
    s32 temp_cr0_gt_227;
    s32 temp_r0_226;
    s32 var_ctr_233;
    s32 var_r5_232;

    temp_r0_226 = this->unk164;
    temp_cr0_gt_227 = temp_r0_226 > 0;
    if (temp_cr0_gt_227 == 0) {
        return 0;
    }
    var_r5_232 = 0;
    var_ctr_233 = temp_r0_226;
    if (temp_cr0_gt_227 != 0) {
loop_3:
        if (arg0 & *(this + (var_r5_232 + 0x44))) {
            return 1;
        }
        var_r5_232 += 0x58;
        var_ctr_233 -= 1;
        if (var_ctr_233 == 0) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_3;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'spA0'
void CollisionObject::CalculateNewVelocity(MKVector3 *arg0, const MKVector3 *arg1, float arg2, ContextInfo *arg3, MKCollisionResult *arg4, const MKVector3 &arg5) {
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;                                      /* compiler-managed */
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    s32 sp18;
    f32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_378;
    f32 temp_f29_317;
    f32 temp_f2_381;
    f32 temp_f4_314;
    f32 temp_f4_465;
    f32 temp_f5_376;
    f32 temp_f6_382;
    f32 temp_f7_379;
    f32 temp_f7_670;
    f32 temp_f8_377;
    f32 temp_f8_468;
    f32 temp_f9_471;
    f32 var_f0_517;
    f32 var_f29_600;
    f32 var_f5_502;
    f64 temp_f2_522;
    f64 temp_f2_528;
    f64 temp_f2_532;
    s32 temp_r0_267;
    s32 temp_r3_551;
    s32 var_r0_561;
    void *temp_r31_275;

    temp_r0_267 = arg3->unk160;
    temp_r31_275 = arg3 + ((arg3->unk164 - 1) * 0x58);
    switch (temp_r0_267) {                          /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp190 = spA0;
        spA8 = arg1->unk8 * arg2;
        sp198 = (f64) spA8;
        NProjection(sp1A0, *((MKVector3 *) &sp190));
        M2C_FIELD(arg0, f64 *, 0) = M2C_BITWISE(f64, sp1A0);
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp1A0.unk8;
        temp_f4_314 = M2C_FIELD(temp_r31_275, f32 *, 0x18);
        temp_f29_317 = -((arg0->unk8 * temp_f4_314) + ((arg0->unk0 * M2C_FIELD(temp_r31_275, f32 *, 0x10)) + (arg0->unk4 * M2C_FIELD(temp_r31_275, f32 *, 0x14))));
        sp14 = temp_f29_317;
        sp18 = (M2C_BITWISE(s32, sp14) & 0x80000000) | 0x3F800000;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp98 = temp_f4_314 * ((0.05f * M2C_BITWISE(f32, sp18)) + temp_f29_317);
        sp200 = sp90;
        sp180 = sp90;
        sp188 = (f64) sp98;
        sp208 = (f64) sp98;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
        arg0->unk8 += (f32) sp208;
        if ((arg4 != NULL) && (((arg4->unk18 * arg0->unk8) + ((arg4->unk10 * arg0->unk0) + (arg4->unk14 * arg0->unk4))) < 0.0f)) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
            sp160 = sp80;
            sp88 = arg1->unk8 * arg2;
            sp168 = (f64) sp88;
            NProjection(sp170, *((MKVector3 *) &sp160));
            M2C_FIELD(arg0, f64 *, 0) = M2C_BITWISE(f64, sp170);
            M2C_FIELD(arg0, f64 *, 8) = (f64) sp170.unk8;
            temp_f5_376 = arg4->unk18;
            temp_f8_377 = M2C_FIELD(temp_r31_275, f32 *, 0x10);
            temp_f1_378 = M2C_FIELD(temp_r31_275, f32 *, 0x18);
            temp_f7_379 = arg4->unk14;
            temp_f2_381 = arg4->unk10;
            temp_f6_382 = M2C_FIELD(temp_r31_275, f32 *, 0x14);
            spD4 = (temp_f1_378 * temp_f2_381) - (temp_f8_377 * temp_f5_376);
            spD0 = (temp_f6_382 * temp_f5_376) - (temp_f1_378 * temp_f7_379);
            spD8 = (temp_f8_377 * temp_f7_379) - (temp_f6_382 * temp_f2_381);
            sp1F0 = (f64) spD0;
            sp1F8 = (f64) spD8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            sp78 = (f32) sp1F8 * ((arg0->unk8 * (f32) sp1F8) + ((arg0->unk0 * (f32) sp1F0) + (arg0->unk4 * unksp1F4)));
            M2C_FIELD(arg0, f64 *, 0) = sp70;
            M2C_FIELD(arg0, f64 *, 8) = (f64) sp78;
            sp150 = sp70;
            sp158 = (f64) sp78;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp140 = spC0;
            spC8 = arg4->unk18 + M2C_FIELD(temp_r31_275, f32 *, 0x18);
            sp148 = (f64) spC8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            sp1E0 = spB0;
            spB8 = (f32) sp148 * 0.1f;
            sp1E8 = (f64) spB8;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
            arg0->unk8 += (f32) sp1E8;
            return;
        }
        return;
    case 2:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        M2C_FIELD(arg0, f64 *, 0) = sp60;
        sp68 = arg1->unk8 * arg2;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp68;
        temp_f4_465 = M2C_FIELD(temp_r31_275, f32 *, 0x14);
        temp_f8_468 = M2C_FIELD(temp_r31_275, f32 *, 0x10);
        temp_f9_471 = M2C_FIELD(temp_r31_275, f32 *, 0x18);
        sp130 = sp60;
        sp138 = (f64) sp68;
        arg0->unk4 += 0.05f + (((arg0->unk8 * temp_f9_471) + ((arg0->unk0 * temp_f8_468) + (arg0->unk4 * temp_f4_465))) / ((up.unk8 * temp_f9_471) + ((up.unk0 * temp_f8_468) + (up.unk4 * temp_f4_465))));
        return;
    case 3:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        sp110 = sp50;
        sp58 = arg1->unk8 * arg2;
        sp118 = (f64) sp58;
        NProjection(sp120, *((MKVector3 *) &sp110));
        var_f5_502 = 0.0f;
        M2C_FIELD(arg0, f64 *, 0) = M2C_BITWISE(f64, sp120);
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp120.unk8;
        sp1D0 = (f64) M2C_FIELD(temp_r31_275, f32 *, 0x10);
        sp1D8 = (f64) M2C_FIELD(temp_r31_275, f32 *, 0x18);
        unksp1D4 = 0.0f;
        var_f0_517 = ((f32) sp1D8 * (f32) sp1D8) + (((f32) sp1D0 * (f32) sp1D0) + (0.0f * 0.0f));
        if (var_f0_517 > 0.000001f) {
            if (var_f0_517 > 0.0f) {
                temp_f2_522 = __frsqrte(var_f0_517);
                temp_f2_528 = 0.5 * temp_f2_522 * -(((f64) var_f0_517 * (temp_f2_522 * temp_f2_522)) - 3.0);
                temp_f2_532 = 0.5 * temp_f2_528 * -(((f64) var_f0_517 * (temp_f2_528 * temp_f2_528)) - 3.0);
                var_f0_517 = (f32) ((f64) var_f0_517 * (0.5 * temp_f2_532 * -(((f64) var_f0_517 * (temp_f2_532 * temp_f2_532)) - 3.0)));
            } else if (var_f0_517 < M2C_BITWISE(f32, 0.0)) {
                var_f0_517 = __float_nan;
            } else {
                sp8 = var_f0_517;
                temp_r3_551 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_551) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_561 = 1;
                    } else {
                        var_r0_561 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_561 = 5;
                    } else {
                        var_r0_561 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_561 = 4;
                    break;
                }
                if (var_r0_561 == 1) {
                    var_f0_517 = __float_nan;
                }
            }
            var_f5_502 = 1.0f / var_f0_517;
        } else {
            var_f0_517 = 0.0f;
        }
        sp1D0 = (f32) sp1D0 * var_f5_502;
        unksp1D4 *= var_f5_502;
        sp1D8 = (f32) sp1D8 * var_f5_502;
        if (var_f0_517 == 0.0f) {
            var_f29_600 = 0.0f;
        } else {
            var_f29_600 = -((arg0->unk8 * M2C_FIELD(temp_r31_275, f32 *, 0x18)) + ((arg0->unk0 * M2C_FIELD(temp_r31_275, f32 *, 0x10)) + (arg0->unk4 * M2C_FIELD(temp_r31_275, f32 *, 0x14)))) / var_f0_517;
        }
        spC = var_f29_600;
        sp10 = (M2C_BITWISE(s32, spC) & 0x80000000) | 0x3F800000;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
        sp1C0 = sp40;
        sp48 = sp1D8 * ((0.05f * M2C_BITWISE(f32, sp10)) + var_f29_600);
        sp100 = sp40;
        sp108 = (f64) sp48;
        sp1C8 = (f64) sp48;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
        arg0->unk8 += (f32) sp1C8;
        return;
    case 4:                                         /* switch 1 */
        arg0->unk0 = 0.0f;
        arg0->unk4 = 0.0f;
        arg0->unk8 = 0.0f;
        return;
    case 5:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r27, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
        M2C_FIELD(arg0, f64 *, 0) = sp30;
        sp38 = arg1->unk8 * arg2;
        spF0 = sp30;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp38;
        temp_f7_670 = M2C_FIELD(temp_r31_275, f32 *, 0x18);
        spF8 = (f64) sp38;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f6 */);
        sp28 = temp_f7_670 * (2.0f * -((arg0->unk8 * temp_f7_670) + ((arg0->unk0 * M2C_FIELD(temp_r31_275, f32 *, 0x10)) + (arg0->unk4 * M2C_FIELD(temp_r31_275, f32 *, 0x14)))));
        sp1B0 = sp20;
        spE0 = sp20;
        spE8 = (f64) sp28;
        sp1B8 = (f64) sp28;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r30, 0x0, qr0 */);
        arg0->unk8 += (f32) sp1B8;
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double *' to
void CollisionObject::SortResults() {
    M2C_UNK sp14;
    ContextInfo *sp10;
    ContextInfo *spC;
    void **sp8;
    f32 temp_f0_772;
    f32 var_f1_760;
    s32 temp_r7_796;
    s32 temp_r8_761;
    s32 var_ctr_766;
    s32 var_r11_764;
    s32 var_r4_749;
    s32 var_r5_751;
    s32 var_r6_765;
    s32 var_r9_759;
    void *temp_r10_758;
    void *temp_r7_804;
    void *temp_r8_800;
    void *temp_r9_802;

    var_r4_749 = 0;
    sp8 = M2C_FIELD(&lit_819, void ***, 0);
    var_r5_751 = 0;
    spC = M2C_FIELD(&lit_819, ContextInfo **, 4);
    sp10 = M2C_FIELD(&lit_819, ContextInfo **, 8);
    sp8 = &this->unk8;
    spC = &this->unk170;
    sp10 = &this->unk2D8;
    do {
        temp_r10_758 = *(&sp8 + var_r5_751);
        var_r9_759 = 0;
        var_f1_760 = 0.0f;
        temp_r8_761 = M2C_FIELD(temp_r10_758, s32 *, 0x164);
        if (temp_r8_761 > 1) {
            var_r11_764 = 0;
            var_r6_765 = 0;
            var_ctr_766 = temp_r8_761;
            if (temp_r8_761 > 0) {
                do {
                    temp_f0_772 = *(*(&sp8 + var_r5_751) + (var_r6_765 + 0x40));
                    if (temp_f0_772 > var_f1_760) {
                        var_f1_760 = temp_f0_772;
                        var_r9_759 = var_r11_764;
                    }
                    var_r11_764 += 1;
                    var_r6_765 += 0x58;
                    var_ctr_766 -= 1;
                } while (var_ctr_766 != 0);
            }
            M2C_STRUCT_COPY((s32) &sp14 + 4, (s32) ((temp_r10_758 + ((temp_r8_761 * 0x58) - 0x58)) - 4) + 4, 0x58);
            temp_r7_796 = var_r9_759 * 0x58;
            temp_r8_800 = temp_r10_758 + temp_r7_796;
            temp_r9_802 = *(&sp8 + var_r5_751) + temp_r7_796;
            temp_r7_804 = temp_r10_758 + ((M2C_FIELD(temp_r10_758, s32 *, 0x164) - 1) * 0x58);
            M2C_FIELD(temp_r7_804, f64 *, 0) = (f64) M2C_FIELD(temp_r8_800, f64 *, 0);
            M2C_FIELD(temp_r7_804, f64 *, 8) = (f64) M2C_FIELD(temp_r8_800, f64 *, 8);
            M2C_FIELD(temp_r7_804, f64 *, 0x10) = (f64) M2C_FIELD(temp_r8_800, f64 *, 0x10);
            M2C_FIELD(temp_r7_804, f64 *, 0x18) = (f64) M2C_FIELD(temp_r8_800, f64 *, 0x18);
            M2C_FIELD(temp_r7_804, f64 *, 0x20) = (f64) M2C_FIELD(temp_r8_800, f64 *, 0x20);
            M2C_FIELD(temp_r7_804, f64 *, 0x28) = (f64) M2C_FIELD(temp_r8_800, f64 *, 0x28);
            M2C_STRUCT_COPY(temp_r7_804, temp_r8_800, 0x10);
            M2C_FIELD(temp_r7_804, f32 *, 0x40) = (f32) M2C_FIELD(temp_r8_800, f32 *, 0x40);
            M2C_FIELD(temp_r7_804, s32 *, 0x44) = (s32) M2C_FIELD(temp_r8_800, s32 *, 0x44);
            M2C_FIELD(temp_r7_804, s32 *, 0x48) = (s32) M2C_FIELD(temp_r8_800, s32 *, 0x48);
            M2C_FIELD(temp_r7_804, s32 *, 0x4C) = (s32) M2C_FIELD(temp_r8_800, s32 *, 0x4C);
            M2C_FIELD(temp_r7_804, u8 *, 0x50) = (u8) M2C_FIELD(temp_r8_800, u8 *, 0x50);
            M2C_FIELD(temp_r9_802, f64 *, 0) = sp18;
            M2C_FIELD(temp_r9_802, f64 *, 8) = sp20;
            M2C_FIELD(temp_r9_802, f64 *, 0x10) = sp28;
            M2C_FIELD(temp_r9_802, f64 *, 0x18) = sp30;
            M2C_FIELD(temp_r9_802, f64 *, 0x20) = sp38;
            M2C_FIELD(temp_r9_802, f64 *, 0x28) = sp40;
            M2C_FIELD(temp_r9_802, s32 *, 0x30) = sp48;
            M2C_FIELD(temp_r9_802, s32 *, 0x34) = sp4C;
            M2C_FIELD(temp_r9_802, s32 *, 0x38) = sp50;
            M2C_FIELD(temp_r9_802, s32 *, 0x3C) = sp54;
            M2C_FIELD(temp_r9_802, f32 *, 0x40) = sp58;
            M2C_FIELD(temp_r9_802, s32 *, 0x44) = sp5C;
            M2C_FIELD(temp_r9_802, s32 *, 0x48) = sp60;
            M2C_FIELD(temp_r9_802, s32 *, 0x4C) = sp64;
            M2C_FIELD(temp_r9_802, u8 *, 0x50) = sp68;
        }
        var_r4_749 += 1;
        var_r5_751 += 4;
    } while (var_r4_749 < 3);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void CollisionObject::PerformPushOut(MKVector3 *arg0) {
    MKCollisionResult spD8;
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
    u32 spAC;
    s32 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    s32 sp84;
    s32 sp80;
    u8 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_1039;
    MKProp *temp_r3_942;
    f32 *temp_r6_892;
    f32 temp_f30_894;
    s32 temp_r3_897;
    s32 var_r27_916;
    s32 var_r30_915;
    u32 var_r0_930;
    u32 var_r4_989;
    u8 *var_r26_914;
    void *temp_r3_927;
    void *temp_r3_945;
    void *temp_r3_986;
    void *temp_r4_923;

    sp58 = M2C_FIELD(arg0, f64 *, 0);
    sp60 = M2C_FIELD(arg0, f64 *, 8);
    temp_r6_892 = this->unk460;
    temp_f30_894 = M2C_FIELD(temp_r6_892, f32 *, 0);
    temp_r3_897 = MKCollision_SphereCollide(*((MKVector3 *) &sp58), temp_f30_894, &spD8, 0x14, (MKCollisionMode) M2C_FIELD(temp_r6_892, s32 *, 8), this->unk46C);
    if (temp_r3_897 != 0) {
        Tools_UpdateSphereCollideResults(&spD8, temp_r3_897, *((MKVector3 *) &sp58));
        Tools_PushOut(&spD8, *((MKVector3 *) &sp58), temp_r3_897, temp_f30_894, &sp68, 0.95f);
        if (this->unk468 & 8) {
            var_r26_914 = &sp68;
            var_r30_915 = 0;
            var_r27_916 = 0;
loop_22:
            if (var_r30_915 < temp_r3_897) {
                if ((u8) *var_r26_914 != 0) {
                    temp_r4_923 = &spD8 + var_r27_916;
                    if (((u8) M2C_FIELD(temp_r4_923, u8 *, 0x50) != 0) && (temp_r3_927 = M2C_FIELD(temp_r4_923, void **, 0x48), ((temp_r3_927 == NULL) == 0)) && (var_r0_930 = M2C_FIELD(temp_r3_927, u32 *, 8), ((var_r0_930 == 0U) == 0))) {

                    } else {
                        var_r0_930 = 0U;
                    }
                    if ((var_r0_930 != 0U) && (M2C_FIELD(temp_r4_923, s32 *, 0x44) & 0x40000000)) {
                        temp_r3_942 = this->unk470;
                        if (temp_r3_942 != NULL) {
                            temp_r3_945 = temp_r3_942->unk8;
                            sp8 = -M2C_FIELD(temp_r3_945, f32 *, 0x20);
                            spC = -M2C_FIELD(temp_r3_945, f32 *, 0x24);
                            sp10 = -M2C_FIELD(temp_r3_945, f32 *, 0x28);
                            sp38 = (f64) sp8;
                            sp40 = (f64) sp10;
                            sp28 = -(f32) sp38;
                            sp2C = -unksp3C;
                            sp30 = -(f32) sp40;
                            sp48 = (f64) sp28;
                            unksp4C = 0.2f;
                            sp50 = (f64) sp30;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                            sp84 = 0;
                            sp50 = (f32) sp50 * 500.0f;
                            if (((u8) M2C_FIELD(temp_r4_923, u8 *, 0x50) != 0) && (temp_r3_986 = M2C_FIELD(temp_r4_923, void **, 0x48), ((temp_r3_986 == NULL) == 0)) && (var_r4_989 = M2C_FIELD(temp_r3_986, u32 *, 8), ((var_r4_989 == 0U) == 0))) {

                            } else {
                                var_r4_989 = 0U;
                            }
                            sp80 = 7;
                            spA8 = 1;
                            spAC = var_r4_989;
                            sp88 = sp48;
                            sp90 = (f64) sp50;
                            spC0 = 0;
                            spCC = 2;
                            spC8 = 10.0f;
                            spC1 = 0;
                            spC2 = 1;
                            spC4 = -1;
                            sp98 = M2C_FIELD(&one, f64 *, 0);
                            spA0 = M2C_FIELD(&one, f64 *, 8);
                            spD0 = 0;
                            if (var_r4_989 != 0U) {
                                sp18.GetPos();
                                spB0 = sp18;
                                spB8 = sp20;
                            } else {
                                spB0 = 0.0f;
                                unkspB4 = 0.0f;
                                spB8 = 0.0f;
                            }
                            spD1 = 0;
                            temp_r3_1039 = this->unk470;
                            temp_r3_1039->Message(&sp80);
                        }
                    }
                }
                var_r30_915 += 1;
                var_r27_916 += 0x58;
                var_r26_914 += 1;
                goto loop_22;
            }
        }
        M2C_FIELD(arg0, f64 *, 0) = sp58;
        M2C_FIELD(arg0, f64 *, 8) = sp60;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp1A0'
void CollisionObject::ResolveCollisionsQuick(MKVector3 *arg0, MKVector3 *arg1, int arg2) {
    MKCollisionResult *temp_r4_1513;
    MKMessage *temp_r3_1477;
    f32 *temp_r6_1416;
    f32 temp_f0_1304;
    f32 temp_f0_1313;
    f32 temp_f0_1535;
    f32 temp_f1_1312;
    f32 temp_f27_1418;
    f32 temp_f2_1262;
    f32 temp_f2_1267;
    f32 temp_f2_1394;
    f32 temp_f3_1315;
    f32 temp_f6_1207;
    f32 var_f27_1174;
    f32 var_f4_1167;
    f32 var_f4_1320;
    f32 var_f5_1100;
    f64 temp_f1_1106;
    f64 temp_f1_1112;
    f64 temp_f1_1116;
    f64 temp_f1_1323;
    f64 temp_f1_1329;
    f64 temp_f1_1333;
    f64 temp_f2_1087;
    s32 temp_r3_1135;
    s32 temp_r3_1352;
    s32 temp_r3_1421;
    s32 var_r0_1145;
    s32 var_r0_1362;
    s32 var_r24_1508;
    s32 var_r26_1434;
    s32 var_r30_1435;
    s32 var_r30_1509;
    void *temp_r25_1440;
    void *temp_r3_1444;
    void *temp_r3_1455;
    void *temp_r3_1481;
    void *var_r24_1447;

    temp_f2_1087 = M2C_FIELD(arg1, f64 *, 0);
    unksp1A0 = temp_f2_1087;
    unksp1A8 = M2C_FIELD(arg1, f64 *, 8);
    var_f5_1100 = (unksp1A8 * unksp1A8) + (((f32) temp_f2_1087 * (f32) temp_f2_1087) + (unksp1A4 * unksp1A4));
    if (var_f5_1100 > 0.000001f) {
        if (var_f5_1100 > 0.0f) {
            temp_f1_1106 = __frsqrte(var_f5_1100);
            temp_f1_1112 = 0.5 * temp_f1_1106 * -(((f64) var_f5_1100 * (temp_f1_1106 * temp_f1_1106)) - 3.0);
            temp_f1_1116 = 0.5 * temp_f1_1112 * -(((f64) var_f5_1100 * (temp_f1_1112 * temp_f1_1112)) - 3.0);
            var_f5_1100 = (f32) ((f64) var_f5_1100 * (0.5 * temp_f1_1116 * -(((f64) var_f5_1100 * (temp_f1_1116 * temp_f1_1116)) - 3.0)));
        } else if (var_f5_1100 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1100 = __float_nan;
        } else {
            unkspC = var_f5_1100;
            temp_r3_1135 = unkspC & 0x7F800000;
            switch (temp_r3_1135) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (unkspC & 0x7FFFFF) {
                    var_r0_1145 = 1;
                } else {
                    var_r0_1145 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (unkspC & 0x7FFFFF) {
                    var_r0_1145 = 5;
                } else {
                    var_r0_1145 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1145 = 4;
                break;
            }
            if (var_r0_1145 == 1) {
                var_f5_1100 = __float_nan;
            }
        }
        var_f4_1167 = 1.0f / var_f5_1100;
    } else {
        var_f4_1167 = 0.0f;
        var_f5_1100 = 0.0f;
    }
    var_f27_1174 = var_f5_1100;
    unksp1A0 *= var_f4_1167;
    unksp1A4 *= var_f4_1167;
    unksp1A8 *= var_f4_1167;
    if (!(var_f5_1100 < 0.05f)) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        unksp190 = unkspC0;
        unkspC8 = arg0->unk8 + arg1->unk8;
        unksp198 = unkspC8;
        if (MKCollision_RayCollide(*arg0, *((MKVector3 *) &unksp190), (MKCollisionResult *) &unksp1D0, (MKCollisionMode) 7, this->unk46C) != 0) {
            temp_f6_1207 = M2C_FIELD(this->unk460, f32 *, 0);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f2, $f31 */);
            unksp130 = unkspB0;
            unkspB8 = unksp1E8 * temp_f6_1207;
            unksp138 = unkspB8;
            M2C_ERROR(/* unknown instruction: ps_add $f1, $f0, $f1 */);
            unksp180 = unkspA0;
            unkspA8 = unksp1D8 + unksp138;
            unksp188 = unkspA8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f4, $f4, $f30 */);
            unksp110 = unksp90;
            unksp98 = unksp1A8 * temp_f6_1207;
            unksp118 = unksp98;
            M2C_ERROR(/* unknown instruction: ps_sub $f4, $f0, $f4 */);
            unksp120 = unksp80;
            unksp88 = unksp1D8 - unksp118;
            unksp128 = unksp88;
            M2C_ERROR(/* unknown instruction: psq_lx $f4, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f4, $f5, $f4 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f6, $f2, $f28 */);
            unksp170 = unksp70;
            temp_f2_1262 = unksp128 - arg0->unk8;
            unksp78 = temp_f2_1262;
            unksp178 = (f64) temp_f2_1262;
            temp_f2_1267 = unksp1E8 * 0.01f;
            unksp68 = temp_f2_1267;
            unkspF0 = unksp60;
            unkspF8 = (f64) temp_f2_1267;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f2 */);
            unksp100 = unksp50;
            unksp58 = unksp1D8 + temp_f2_1267;
            unksp108 = unksp58;
            if (MKCollision_RayCollide(*((MKVector3 *) &unksp100), *((MKVector3 *) &unksp180), (MKCollisionResult *) &unksp1D0, (MKCollisionMode) 7, this->unk46C) != 0) {
                M2C_FIELD(arg1, f64 *, 0) = unksp170;
                M2C_FIELD(arg1, f64 *, 8) = unksp178;
            } else {
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                temp_f0_1304 = unksp188 - arg0->unk8;
                M2C_FIELD(arg1, f64 *, 0) = unksp20;
                unksp28 = temp_f0_1304;
                unkspE0 = unksp20;
                unkspE8 = (f64) temp_f0_1304;
                M2C_FIELD(arg1, f64 *, 8) = (f64) temp_f0_1304;
            }
            temp_f1_1312 = arg1->unk0;
            temp_f0_1313 = arg1->unk4;
            temp_f3_1315 = arg1->unk8;
            var_f4_1320 = (temp_f3_1315 * temp_f3_1315) + ((temp_f1_1312 * temp_f1_1312) + (temp_f0_1313 * temp_f0_1313));
            if (var_f4_1320 > 0.0f) {
                temp_f1_1323 = __frsqrte(var_f4_1320);
                temp_f1_1329 = 0.5 * temp_f1_1323 * -(((f64) var_f4_1320 * (temp_f1_1323 * temp_f1_1323)) - 3.0);
                temp_f1_1333 = 0.5 * temp_f1_1329 * -(((f64) var_f4_1320 * (temp_f1_1329 * temp_f1_1329)) - 3.0);
                var_f4_1320 = (f32) ((f64) var_f4_1320 * (0.5 * temp_f1_1333 * -(((f64) var_f4_1320 * (temp_f1_1333 * temp_f1_1333)) - 3.0)));
            } else if (var_f4_1320 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1320 = __float_nan;
            } else {
                unksp8 = var_f4_1320;
                temp_r3_1352 = unksp8 & 0x7F800000;
                switch (temp_r3_1352) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (unksp8 & 0x7FFFFF) {
                        var_r0_1362 = 1;
                    } else {
                        var_r0_1362 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (unksp8 & 0x7FFFFF) {
                        var_r0_1362 = 5;
                    } else {
                        var_r0_1362 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1362 = 4;
                    break;
                }
                if (var_r0_1362 == 1) {
                    var_f4_1320 = __float_nan;
                }
            }
            var_f27_1174 = var_f4_1320;
            if (!(var_f4_1320 < 0.05f)) {
                goto block_43;
            }
        } else {
block_43:
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            temp_f2_1394 = arg1->unk8;
            unksp160 = unksp40;
            unksp48 = temp_f2_1394 * (1.0f / var_f27_1174);
            unksp168 = unksp48;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            unksp150 = unksp30;
            unksp38 = arg0->unk8 + temp_f2_1394;
            unksp158 = unksp38;
            temp_r6_1416 = this->unk460;
            temp_f27_1418 = M2C_FIELD(temp_r6_1416, f32 *, 0);
            temp_r3_1421 = MKCollision_SphereCollide(*((MKVector3 *) &unksp150), 1.05f * temp_f27_1418, (MKCollisionResult *) &unksp1D0, 0x1E, (MKCollisionMode) M2C_FIELD(temp_r6_1416, s32 *, 8), this->unk46C);
            if (temp_r3_1421 == 0) {
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
                arg0->unk8 += arg1->unk8;
                return;
            }
            var_r26_1434 = 0;
            var_r30_1435 = 0;
            unksp144 = 0;
loop_58:
            if (var_r30_1435 < temp_r3_1421) {
                temp_r25_1440 = &unksp1D0 + var_r26_1434;
                if (((u8) M2C_FIELD(temp_r25_1440, u8 *, 0x50) != 0) && (temp_r3_1444 = M2C_FIELD(temp_r25_1440, void **, 0x48), ((temp_r3_1444 == NULL) == 0)) && (var_r24_1447 = M2C_FIELD(temp_r3_1444, void **, 8), ((var_r24_1447 == NULL) == 0))) {

                } else {
                    var_r24_1447 = NULL;
                }
                temp_r3_1455 = M2C_FIELD(temp_r25_1440, void **, 0x48);
                if ((var_r24_1447 != NULL) && (temp_r3_1455 != NULL)) {
                    unksp148 = temp_r3_1455;
                    unksp140 = 0x12;
                    unksp14C = this;
                    M2C_FIELD(M2C_FIELD(var_r24_1447, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(var_r24_1447, &unksp140);
                    if ((MKMessage *) this->unk440 != NULL) {
                        M2C_FIELD(M2C_FIELD(var_r24_1447, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *), 0x2C)(var_r24_1447);
                        temp_r3_1477 = this->unk440;
                        if ((s32) temp_r3_1477->unk0 == 0x31) {
                            temp_r3_1481 = checked_cast<ShatterOnCollisionMsg *, MKMessage>(temp_r3_1477);
                            if ((u8) M2C_FIELD(temp_r3_1481, u8 *, 0x18) != 0) {
                                M2C_FIELD(temp_r25_1440, u8 *, 0x50) = 0U;
                                M2C_FIELD(M2C_FIELD(temp_r3_1481, void **, 0x2C), M2C_UNK (**)(), 8)();
                            }
                        }
                    }
                }
                var_r30_1435 += 1;
                var_r26_1434 += 0x58;
                goto loop_58;
            }
            Tools_UpdateSphereCollideResults((MKCollisionResult *) &unksp1D0, temp_r3_1421, *((MKVector3 *) &unksp150));
            Tools_PushOut((MKCollisionResult *) &unksp1D0, *((MKVector3 *) &unksp150), temp_r3_1421, temp_f27_1418, &unksp1B0, 0.952381f);
            var_r24_1508 = 0;
            var_r30_1509 = 0;
loop_63:
            if (var_r24_1508 < temp_r3_1421) {
                temp_r4_1513 = &unksp1D0 + var_r30_1509;
                if ((u8) temp_r4_1513->unk50 != 0) {
                    StoreResult(temp_r4_1513, (MKVector3 *) &unksp160);
                }
                var_r24_1508 += 1;
                var_r30_1509 += 0x58;
                goto loop_63;
            }
            SortResults();
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            temp_f0_1535 = unksp158 - arg0->unk8;
            M2C_FIELD(arg1, f64 *, 0) = unksp10;
            unksp18 = temp_f0_1535;
            unkspD0 = unksp10;
            M2C_FIELD(arg1, f64 *, 8) = (f64) temp_f0_1535;
            unkspD8 = (f64) temp_f0_1535;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
            arg0->unk8 += arg1->unk8;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void CollisionObject::ResolveCollisions(MKVector3 *arg0, MKVector3 *arg1, int arg2) {
    u8 sp158;
    s32 sp154;
    void *sp150;
    s32 sp14C;
    f32 sp148;
    s32 sp144;
    s32 sp140;
    f32 sp13C;
    f32 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKCollisionResult spB0;
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
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    ContextInfo *temp_r6_1844;
    f32 *temp_r7_1818;
    f32 temp_f0_1717;
    f32 temp_f0_1854;
    f32 temp_f0_1862;
    f32 temp_f1_1614;
    f32 temp_f1_1716;
    f32 temp_f1_1891;
    f32 temp_f2_1612;
    f32 temp_f2_1719;
    f32 temp_f2_1793;
    f32 temp_f3_1617;
    f32 temp_f3_1788;
    f32 var_f1_1852;
    f32 var_f25_1723;
    f32 var_f26_1865;
    f32 var_f3_1690;
    f32 var_f4_1623;
    f64 temp_f1_1629;
    f64 temp_f1_1635;
    f64 temp_f1_1639;
    f64 temp_f1_1728;
    f64 temp_f1_1734;
    f64 temp_f1_1738;
    s32 temp_r0_1896;
    s32 temp_r3_1658;
    s32 temp_r3_1757;
    s32 var_r0_1668;
    s32 var_r0_1767;
    s32 var_r30_1698;
    u8 var_r31_1621;

    temp_f2_1612 = arg1->unk0;
    temp_f1_1614 = arg1->unk4;
    temp_f3_1617 = arg1->unk8;
    var_r31_1621 = 0;
    var_f4_1623 = (temp_f3_1617 * temp_f3_1617) + ((temp_f2_1612 * temp_f2_1612) + (temp_f1_1614 * temp_f1_1614));
    if (var_f4_1623 > 1e-12f) {
        if (var_f4_1623 > 0.0f) {
            temp_f1_1629 = __frsqrte(var_f4_1623);
            temp_f1_1635 = 0.5 * temp_f1_1629 * -(((f64) var_f4_1623 * (temp_f1_1629 * temp_f1_1629)) - 3.0);
            temp_f1_1639 = 0.5 * temp_f1_1635 * -(((f64) var_f4_1623 * (temp_f1_1635 * temp_f1_1635)) - 3.0);
            var_f4_1623 = (f32) ((f64) var_f4_1623 * (0.5 * temp_f1_1639 * -(((f64) var_f4_1623 * (temp_f1_1639 * temp_f1_1639)) - 3.0)));
        } else if (var_f4_1623 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1623 = __float_nan;
        } else {
            spC = var_f4_1623;
            temp_r3_1658 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_1658) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1668 = 1;
                } else {
                    var_r0_1668 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1668 = 5;
                } else {
                    var_r0_1668 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1668 = 4;
                break;
            }
            if (var_r0_1668 == 1) {
                var_f4_1623 = __float_nan;
            }
        }
        var_f3_1690 = 1.0f / var_f4_1623;
    } else {
        var_f3_1690 = 0.0f;
    }
    var_r30_1698 = 0;
    sp40 = arg1->unk0 * var_f3_1690;
    sp44 = arg1->unk4 * var_f3_1690;
    sp48 = arg1->unk8 * var_f3_1690;
    spA0 = (f64) sp40;
    spA8 = (f64) sp48;
loop_50:
    if (var_r30_1698 >= arg2) {

    } else {
        temp_f1_1716 = arg1->unk0;
        temp_f0_1717 = arg1->unk4;
        temp_f2_1719 = arg1->unk8;
        var_f25_1723 = (temp_f2_1719 * temp_f2_1719) + ((temp_f1_1716 * temp_f1_1716) + (temp_f0_1717 * temp_f0_1717));
        if (!(var_f25_1723 < 0.0025000002f)) {
            if (var_f25_1723 > 0.0f) {
                temp_f1_1728 = __frsqrte(var_f25_1723);
                temp_f1_1734 = 0.5 * temp_f1_1728 * -(((f64) var_f25_1723 * (temp_f1_1728 * temp_f1_1728)) - 3.0);
                temp_f1_1738 = 0.5 * temp_f1_1734 * -(((f64) var_f25_1723 * (temp_f1_1734 * temp_f1_1734)) - 3.0);
                var_f25_1723 = (f32) ((f64) var_f25_1723 * (0.5 * temp_f1_1738 * -(((f64) var_f25_1723 * (temp_f1_1738 * temp_f1_1738)) - 3.0)));
            } else if (var_f25_1723 < M2C_BITWISE(f32, 0.0)) {
                var_f25_1723 = __float_nan;
            } else {
                sp8 = var_f25_1723;
                temp_r3_1757 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1757) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1767 = 1;
                    } else {
                        var_r0_1767 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1767 = 5;
                    } else {
                        var_r0_1767 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1767 = 4;
                    break;
                }
                if (var_r0_1767 == 1) {
                    var_f25_1723 = __float_nan;
                }
            }
            temp_f3_1788 = 1.0f / var_f25_1723;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            temp_f2_1793 = arg1->unk8;
            sp90 = sp30;
            sp38 = temp_f2_1793 * temp_f3_1788;
            sp70 = sp30;
            sp98 = (f64) sp38;
            sp78 = (f64) sp38;
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            sp80 = sp20;
            sp28 = arg0->unk8 + temp_f2_1793;
            sp60 = sp20;
            sp88 = (f64) sp28;
            temp_r7_1818 = this->unk460;
            sp68 = (f64) sp28;
            if (SphereCheck(*arg0, sp80, &spB0, M2C_FIELD(temp_r7_1818, s32 *, 8), this->unk46C, M2C_FIELD(temp_r7_1818, f32 *, 0), temp_f2_1793, temp_f3_1788) == 0) {
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r27, 0x0, qr0 */);
                arg0->unk8 += arg1->unk8;
                return;
            }
            temp_r6_1844 = StoreResult(&spB0, (MKVector3 *) &sp90);
            var_f1_1852 = 0.000001f;
            temp_f0_1854 = -(((f32) sp98 * spB0.unk18) + (((f32) sp90 * spB0.unk10) + (unksp94 * spB0.unk14)));
            if (temp_f0_1854 > var_f1_1852) {
                var_f1_1852 = temp_f0_1854;
            }
            temp_f0_1862 = (var_f25_1723 * spB0.unk40) - (0.05f / var_f1_1852);
            if (0.0f > temp_f0_1862) {
                var_f26_1865 = 0.0f;
            } else {
                var_f26_1865 = temp_f0_1862;
            }
            if (var_f26_1865 > 0.0f) {
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
                sp50 = sp10;
                sp18 = (f32) sp98 * var_f26_1865;
                sp58 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r27, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r27, 0x0, qr0 */);
                arg0->unk8 += (f32) sp58;
            }
            temp_f1_1891 = var_f25_1723 - var_f26_1865;
            if (!(temp_f1_1891 < 0.05f)) {
                temp_r0_1896 = 0 - var_r31_1621;
                CalculateNewVelocity(arg1, (MKVector3 *) &sp90, temp_f1_1891, temp_r6_1844, (MKCollisionResult *) ((s32) &sp108 & ((temp_r0_1896 - temp_r0_1896) - !M2C_CARRY)), *((MKVector3 *) &spA0));
                var_r31_1621 = 1;
                var_r30_1698 += 1;
                sp108 = M2C_BITWISE(f64, spB0);
                sp110 = (f64) spB0.unk8;
                sp118 = (f64) spB0.unk10;
                sp120 = (f64) spB0.unk18;
                sp128 = (f64) spB0.unk20;
                sp130 = (f64) spB0.unk28;
                sp138 = spB0.unk30;
                sp13C = spB0.unk34;
                sp140 = spB0.unk38;
                sp144 = spB0.unk3C;
                sp148 = spB0.unk40;
                sp14C = spB0.unk44;
                sp150 = spB0.unk48;
                sp154 = spB0.unk4C;
                sp158 = spB0.unk50;
                goto loop_50;
            }
        }
    }
}
#endif

void CollisionObject::ResetResults() {
    this->unk16C = 0;
    this->unk170.unk164 = 0;
    this->unk2D8.unk164 = 0;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionMode'
s32 CollisionObject::SphereCheck(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, MKCollisionResult *arg3, MKCollisionMode arg4, int arg5) {
    MKCollisionResult sp18;
    CollisionObject *sp14;
    void *sp10;
    s32 spC;
    s32 sp8;
    MKMessage *temp_r3_2062;
    s32 var_r31_1988;
    void *temp_r3_2066;
    void *var_r0_2009;
    void *var_r3_2030;
    void *var_r3_2051;

    spC = 0;
    var_r31_1988 = 0;
loop_28:
    if (var_r31_1988 >= (s32) M2C_FIELD(this->unk460, s32 *, 0x10)) {
        return 0;
    }
    if (MKCollision_SweepSphereCollide(arg0, arg1, arg2, &sp18, arg4, arg5) == 0) {
        return 0;
    }
    if ((sp18.unk50 != 0) && (sp18.unk48 != NULL) && (var_r0_2009 = M2C_FIELD(sp18.unk48, void **, 8), ((var_r0_2009 == NULL) == 0))) {

    } else {
        var_r0_2009 = NULL;
    }
    if ((var_r0_2009 != NULL) && (sp18.unk48 != NULL)) {
        sp8 = 0x12;
        sp10 = sp18.unk48;
        sp14 = this;
        if ((sp18.unk50 != 0) && (sp18.unk48 != NULL) && (var_r3_2030 = M2C_FIELD(sp18.unk48, void **, 8), ((var_r3_2030 == NULL) == 0))) {

        } else {
            var_r3_2030 = NULL;
        }
        M2C_FIELD(M2C_FIELD(var_r3_2030, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        if ((MKMessage *) this->unk440 != NULL) {
            if ((sp18.unk50 != 0) && (sp18.unk48 != NULL) && (var_r3_2051 = M2C_FIELD(sp18.unk48, void **, 8), ((var_r3_2051 == NULL) == 0))) {

            } else {
                var_r3_2051 = NULL;
            }
            M2C_FIELD(M2C_FIELD(var_r3_2051, void **, 0x44), M2C_UNK (**)(), 0x2C)();
            temp_r3_2062 = this->unk440;
            if ((s32) temp_r3_2062->unk0 == 0x31) {
                temp_r3_2066 = checked_cast<ShatterExtendedMsg *, MKMessage>(temp_r3_2062);
                if ((u8) M2C_FIELD(temp_r3_2066, u8 *, 0x18) != 0) {
                    M2C_FIELD(M2C_FIELD(temp_r3_2066, void **, 0x2C), M2C_UNK (**)(), 8)();
                    goto block_27;
                }
            }
            goto block_24;
        }
block_24:
        M2C_FIELD(arg3, f64 *, 0) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(arg3, f64 *, 8) = (f64) sp18.unk8;
        M2C_FIELD(arg3, f64 *, 0x10) = (f64) sp18.unk10;
        M2C_FIELD(arg3, f64 *, 0x18) = (f64) sp18.unk18;
        M2C_FIELD(arg3, f64 *, 0x20) = (f64) sp18.unk20;
        M2C_FIELD(arg3, f64 *, 0x28) = (f64) sp18.unk28;
        arg3->unk30 = sp18.unk30;
        arg3->unk34 = sp18.unk34;
        arg3->unk38 = sp18.unk38;
        arg3->unk3C = sp18.unk3C;
        arg3->unk40 = sp18.unk40;
        arg3->unk44 = sp18.unk44;
        arg3->unk48 = sp18.unk48;
        arg3->unk4C = sp18.unk4C;
        arg3->unk50 = sp18.unk50;
        if ((u8) M2C_FIELD(arg3->unk48, u8 *, 4) != 0) {
            return 1;
        }
block_27:
        var_r31_1988 += 1;
        goto loop_28;
    }
    M2C_FIELD(arg3, f64 *, 0) = M2C_BITWISE(f64, sp18);
    M2C_FIELD(arg3, f64 *, 8) = (f64) sp18.unk8;
    M2C_FIELD(arg3, f64 *, 0x10) = (f64) sp18.unk10;
    M2C_FIELD(arg3, f64 *, 0x18) = (f64) sp18.unk18;
    M2C_FIELD(arg3, f64 *, 0x20) = (f64) sp18.unk20;
    M2C_FIELD(arg3, f64 *, 0x28) = (f64) sp18.unk28;
    arg3->unk30 = sp18.unk30;
    arg3->unk34 = sp18.unk34;
    arg3->unk38 = sp18.unk38;
    arg3->unk3C = sp18.unk3C;
    arg3->unk40 = sp18.unk40;
    arg3->unk44 = sp18.unk44;
    arg3->unk48 = sp18.unk48;
    arg3->unk4C = sp18.unk4C;
    arg3->unk50 = sp18.unk50;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'up'
ContextInfo *CollisionObject::StoreResult(MKCollisionResult *arg0, MKVector3 *arg1) {
    ContextInfo *var_r6_2171;
    f32 *temp_r8_2167;
    f32 *var_r10_2173;
    f32 temp_f1_2181;
    s32 temp_r7_2179;
    s32 temp_r7_2224;
    s32 var_ctr_2226;
    s32 var_r3_2225;
    u8 var_r0_2233;
    void *temp_r5_2230;
    void *temp_r5_2288;

    temp_r8_2167 = this->unk460;
    var_r6_2171 = &this->unk170;
    var_r10_2173 = temp_r8_2167 + 0x2C;
    temp_r7_2179 = arg0->unk44;
    temp_f1_2181 = (up.unk8 * arg0->unk18) + ((up.unk0 * arg0->unk10) + (up.unk4 * arg0->unk14));
    if (!(temp_r7_2179 & M2C_FIELD(temp_r8_2167, s32 *, 0x38))) {
        if ((temp_f1_2181 > M2C_FIELD(temp_r8_2167, f32 *, 0x1C)) || (temp_r7_2179 & M2C_FIELD(temp_r8_2167, s32 *, 0x28))) {
            var_r10_2173 = temp_r8_2167 + 0x1C;
            var_r6_2171 = (ContextInfo *) &this->unk8;
        } else if ((temp_f1_2181 < M2C_FIELD(temp_r8_2167, f32 *, 0x3C)) || (temp_r7_2179 & M2C_FIELD(temp_r8_2167, s32 *, 0x48))) {
            var_r6_2171 = &this->unk2D8;
            var_r10_2173 = temp_r8_2167 + 0x3C;
        }
    }
    var_r6_2171->unk160 = M2C_FIELD(temp_r8_2167, s32 *, 0xC);
    if (((arg1->unk8 * arg0->unk18) + ((arg1->unk0 * arg0->unk10) + (arg1->unk4 * arg0->unk14))) < M2C_FIELD(var_r10_2173, f32 *, 4)) {
        var_r6_2171->unk160 = M2C_FIELD(var_r10_2173, s32 *, 8);
    }
    temp_r7_2224 = var_r6_2171->unk164;
    var_r3_2225 = 0;
    var_ctr_2226 = temp_r7_2224;
    if (temp_r7_2224 > 0) {
loop_10:
        temp_r5_2230 = var_r6_2171 + var_r3_2225;
        var_r0_2233 = 0;
        if ((M2C_FIELD(temp_r5_2230, f32 *, 0) == arg0->unk0) && (M2C_FIELD(temp_r5_2230, f32 *, 4) == arg0->unk4) && (M2C_FIELD(temp_r5_2230, f32 *, 8) == arg0->unk8)) {
            var_r0_2233 = 1;
        }
        if (var_r0_2233 != 0) {
            M2C_FIELD(temp_r5_2230, f32 *, 0) = (f64) M2C_FIELD(arg0, f32 *, 0);
            M2C_FIELD(temp_r5_2230, f32 *, 8) = (f64) M2C_FIELD(arg0, f32 *, 8);
            M2C_FIELD(temp_r5_2230, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f32 *, 0x10);
            M2C_FIELD(temp_r5_2230, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f32 *, 0x18);
            M2C_FIELD(temp_r5_2230, f64 *, 0x20) = (f64) M2C_FIELD(arg0, f64 *, 0x20);
            M2C_FIELD(temp_r5_2230, f64 *, 0x28) = (f64) M2C_FIELD(arg0, f64 *, 0x28);
            M2C_STRUCT_COPY(temp_r5_2230, arg0, 0x10);
            M2C_FIELD(temp_r5_2230, f32 *, 0x40) = (f32) arg0->unk40;
            M2C_FIELD(temp_r5_2230, s32 *, 0x44) = (s32) arg0->unk44;
            M2C_FIELD(temp_r5_2230, void **, 0x48) = (void *) arg0->unk48;
            M2C_FIELD(temp_r5_2230, s32 *, 0x4C) = (s32) arg0->unk4C;
            M2C_FIELD(temp_r5_2230, u8 *, 0x50) = (u8) arg0->unk50;
        } else {
            var_r3_2225 += 0x58;
            var_ctr_2226 -= 1;
            if (var_ctr_2226 == 0) {
                goto block_17;
            }
            goto loop_10;
        }
    } else {
block_17:
        if (temp_r7_2224 < 4) {
            temp_r5_2288 = var_r6_2171 + (temp_r7_2224 * 0x58);
            M2C_FIELD(temp_r5_2288, f64 *, 0) = (f64) M2C_FIELD(arg0, f32 *, 0);
            M2C_FIELD(temp_r5_2288, f64 *, 8) = (f64) M2C_FIELD(arg0, f32 *, 8);
            M2C_FIELD(temp_r5_2288, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f32 *, 0x10);
            M2C_FIELD(temp_r5_2288, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f32 *, 0x18);
            M2C_FIELD(temp_r5_2288, f64 *, 0x20) = (f64) M2C_FIELD(arg0, f64 *, 0x20);
            M2C_FIELD(temp_r5_2288, f64 *, 0x28) = (f64) M2C_FIELD(arg0, f64 *, 0x28);
            M2C_STRUCT_COPY(temp_r5_2288, arg0, 0x10);
            M2C_FIELD(temp_r5_2288, f32 *, 0x40) = (f32) arg0->unk40;
            M2C_FIELD(temp_r5_2288, s32 *, 0x44) = (s32) arg0->unk44;
            M2C_FIELD(temp_r5_2288, void **, 0x48) = (void *) arg0->unk48;
            M2C_FIELD(temp_r5_2288, s32 *, 0x4C) = (s32) arg0->unk4C;
            M2C_FIELD(temp_r5_2288, u8 *, 0x50) = (u8) arg0->unk50;
            var_r6_2171->unk164 += 1;
        }
    }
    return var_r6_2171;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 CollisionObject::Teleport(const MKVector3 &arg0, float arg1, int arg2) {
    MKCollisionResult sp58;
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    M2C_UNK sp18;
    u8 sp14;
    MKCollisionInfo *sp10;
    u8 sp8;
    MKCollisionInfo *temp_r4_2342;
    f32 temp_f0_2367;
    f32 temp_f0_2445;
    f32 temp_f1_2366;
    f32 temp_f3_2368;
    f32 temp_f3_2385;
    f32 var_f2_2434;
    f32 var_f30_2397;
    f64 temp_f1_2352;
    s32 temp_cr0_eq_2479;
    s32 temp_r3_2419;
    s32 var_ctr_2437;
    s32 var_r28_2343;
    s32 var_r3_2436;
    u8 *var_r4_2433;

    temp_r4_2342 = this->unk464;
    var_r28_2343 = arg2;
    sp10 = temp_r4_2342;
    if (temp_r4_2342 != NULL) {
        sp14 = temp_r4_2342->unk4;
        temp_r4_2342->unk4 = 0;
    }
    temp_f1_2352 = M2C_FIELD(&arg0, f64 *, 0);
    sp48 = temp_f1_2352;
    sp50 = M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, CollisionObject *, f64), 0x50)(&sp28, this, temp_f1_2352);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    temp_f1_2366 = arg0.unk0;
    temp_f0_2367 = arg0.unk4;
    temp_f3_2368 = arg0.unk8;
    sp50 = (f32) sp50 + sp30;
    if (((temp_f3_2368 * temp_f3_2368) + ((temp_f1_2366 * temp_f1_2366) + (temp_f0_2367 * temp_f0_2367))) < 1.0f) {
        var_r28_2343 = 0;
    }
    temp_f3_2385 = *this->unk460;
    if (var_r28_2343 != 0) {
        var_f30_2397 = 0.1f + (temp_f3_2385 / (f32) var_r28_2343);
    } else {
        var_f30_2397 = 0.0f;
    }
loop_21:
    temp_cr0_eq_2479 = var_r28_2343 == 0;
    var_r28_2343 -= 1;
    if (temp_cr0_eq_2479 == 0) {
        sp38 = sp48;
        sp40 = (f64) sp50;
        temp_r3_2419 = MKCollision_SphereCollide(*((MKVector3 *) &sp48), temp_f3_2385, &sp58, 5, (MKCollisionMode) 7, this->unk46C);
        if (temp_r3_2419 != 0) {
            Tools_UpdateSphereCollideResults(&sp58, temp_r3_2419, *((MKVector3 *) &sp48));
            Tools_PushOut(&sp58, *((MKVector3 *) &sp48), temp_r3_2419, temp_f3_2385, &sp8, 1.0f);
            var_r4_2433 = &sp8;
            var_f2_2434 = -3.4028235e38f;
            var_r3_2436 = 0;
            var_ctr_2437 = temp_r3_2419;
            if (temp_r3_2419 > 0) {
                do {
                    if ((u8) *var_r4_2433 != 0) {
                        temp_f0_2445 = *(&sp58 + (var_r3_2436 + 0x40));
                        if (temp_f0_2445 > var_f2_2434) {
                            var_f2_2434 = temp_f0_2445;
                        }
                    }
                    var_r3_2436 += 0x58;
                    var_r4_2433 += 1;
                    var_ctr_2437 -= 1;
                } while (var_ctr_2437 != 0);
            }
            if ((unksp4C < unksp3C) || ((unksp4C == unksp3C) && (var_f2_2434 > (0.2f * temp_f3_2385)))) {
                if (var_f2_2434 < (0.9f * temp_f3_2385)) {
                    unksp4C = unksp3C + var_f30_2397;
                } else {
                    unksp4C = (0.75f * var_f2_2434) + unksp3C;
                }
                goto loop_21;
            }
            if (!(var_f2_2434 < 0.25f)) {
                goto loop_21;
            }
        }
    }
    this->unk450 = sp48;
    this->unk458 = (f64) sp50;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, CollisionObject *, f64), 0x50)(&sp18, this, sp48);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_FIELD(this, f64 *, 0x458) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x458) - sp20);
    ResetResults();
    if (sp10 != NULL) {
        sp10->unk4 = sp14;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 CollisionObject::Update(MKVector3 *arg0, float arg1, bool arg2) {
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;
    M2C_UNK sp20;
    M2C_UNK sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    MKCollisionInfo *temp_r4_2535;
    f32 temp_f0_2545;
    f32 temp_f1_2544;
    f32 temp_f3_2547;
    f64 temp_f1_2606;
    s32 var_r3_2572;
    u8 var_r3_2559;
    u8 var_r3_2651;

    temp_r4_2535 = this->unk464;
    sp8 = temp_r4_2535;
    if (temp_r4_2535 != NULL) {
        spC = temp_r4_2535->unk4;
        temp_r4_2535->unk4 = 0;
    }
    temp_f1_2544 = arg0->unk0;
    temp_f0_2545 = arg0->unk4;
    temp_f3_2547 = arg0->unk8;
    if ((((temp_f3_2547 * temp_f3_2547) + ((temp_f1_2544 * temp_f1_2544) + (temp_f0_2545 * temp_f0_2545))) < 0.0001f) && !(this->unk468 & 1)) {
        var_r3_2559 = 0;
        if (((s32) this->unk2D8.unk164 > 0) || ((s32) this->unk16C > 0) || ((s32) this->unk170.unk164 > 0)) {
            var_r3_2559 = 1;
        }
        var_r3_2572 = 8;
        if (var_r3_2559 != 0) {
            var_r3_2572 = 7;
        }
        if (sp8 != NULL) {
            sp8->unk4 = spC;
            return var_r3_2572;
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_r3_2572;
    }
    if (this->unk468 & 2) {
        ResetResults();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_FIELD(this, f32 *, 0x458) = (f32) (M2C_FIELD(this, f32 *, 0x458) + arg0->unk8);
        if (sp8 != NULL) {
            sp8->unk4 = spC;
        }
        return 8;
    }
    temp_f1_2606 = this->unk450;
    sp30 = temp_f1_2606;
    sp38 = this->unk458;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, CollisionObject *, f64), 0x50)(&sp20, this, temp_f1_2606);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp38 = (f32) sp38 + sp28;
    ResetResults();
    __ptmf_scall(this, &sp30, arg0, M2C_FIELD(this->unk460, s32 *, 0x10));
    if (this->unk468 & 4) {
        PerformPushOut((MKVector3 *) &sp30);
    }
    M2C_FIELD(this->__vptr, M2C_UNK (**)(M2C_UNK *, CollisionObject *, f64), 0x50)(&sp10, this);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    var_r3_2651 = 0;
    sp38 -= sp18;
    this->unk450 = sp30;
    this->unk458 = (f64) sp38;
    if (((s32) this->unk2D8.unk164 > 0) || ((s32) this->unk16C > 0) || ((s32) this->unk170.unk164 > 0)) {
        var_r3_2651 = 1;
    }
    var_r3_2572 = 8;
    if (var_r3_2651 != 0) {
        var_r3_2572 = 7;
    }
    if (sp8 != NULL) {
        sp8->unk4 = spC;
    }
    return var_r3_2572;
}
#endif

void CollisionObject::Deinit() {
    this->unk16C = 0;
    this->unk170.unk164 = 0;
    this->unk2D8.unk164 = 0;
    this->unk460 = NULL;
    M2C_FIELD(this, f32 *, 0x450) = 0.0f;
    M2C_FIELD(this, f32 *, 0x454) = 0.0f;
    M2C_FIELD(this, f32 *, 0x458) = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void CollisionObject::Init(ColObjDescriptor *arg0, const MKVector3 &arg1, bool arg2, MKCollisionInfo *arg3, bool arg4, bool arg5, unsigned int arg6, MKProp *arg7, bool arg8) {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 *temp_r29_2786;

    this->unk468 = 0;
    this->unk470 = arg_sp8;
    this->unk170.unk164 = 0;
    this->unk16C = 0;
    this->unk2D8.unk164 = 0;
    this->unk460 = &arg0->unk0;
    this->unk464 = arg3;
    this->unk46C = M2C_FIELD(this->unk460, s32 *, 0x18);
    this->unk450 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk458 = M2C_FIELD(&arg1, f64 *, 8);
    if (arg5 != 0) {
        this->unk468 |= 1;
    } else {
        this->unk468 &= 0xFFFFFFFE;
    }
    this->unk468 &= 0xFFFFFFFB;
    if (arg_spC != 0) {
        this->unk468 |= 8;
    } else {
        this->unk468 &= 0xFFFFFFF7;
    }
    if (arg2 != 0) {
        M2C_FIELD(this, s32 *, 0x444) = (s32) M2C_FIELD(&lit_621, s32 *, 0);
        this->unk448 = M2C_FIELD(&lit_621, s32 *, 4);
        this->unk44C = M2C_FIELD(&lit_621, s32 *, 8);
    } else {
        M2C_FIELD(this, s32 *, 0x444) = (s32) M2C_FIELD(&lit_623, s32 *, 0);
        this->unk448 = M2C_FIELD(&lit_623, s32 *, 4);
        this->unk44C = M2C_FIELD(&lit_623, s32 *, 8);
    }
    if (arg4 != 0) {
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        temp_r29_2786 = this->unk460;
        ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddSphere((MKVector3 *) &this->unk450, M2C_FIELD(temp_r29_2786, f32 *, 0), M2C_FIELD(temp_r29_2786, f32 *, 4), *((MKVector4 *) &sp8), (MKCollisionMode) M2C_FIELD(temp_r29_2786, s32 *, 8), this->unk464, arg6);
    }
    this->unk440 = NULL;
}
#endif

void ColObjDescriptor::Init() {
    this->unk0 = 0.0f;
    this->unk4 = 0.0f;
    this->unk8 = 7;
    this->unkC = 1;
    this->unk10 = 1;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0.8f;
    this->unk20 = -1.0f;
    this->unk24 = 1;
    this->unk28 = 0;
    this->unk2C = 0.0f;
    this->unk30 = -1.0f;
    this->unk34 = 1;
    this->unk38 = 1;
    this->unk3C = -0.8f;
    this->unk40 = -1.0f;
    this->unk44 = 1;
    this->unk48 = 0;
}

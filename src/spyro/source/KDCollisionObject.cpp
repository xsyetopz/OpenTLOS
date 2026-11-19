#include "spyro/source/KDCollisionObject.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s8 gAssertBool;

#if 0 // DRAFT: function call 'Tools_PushOut(MKCollisionResult *, MKVector3, long, float, unsigned char *, float)' does not match 'Tools_PushOut(MKCollisionResult *, MKVector3 
void KDCollisionObject::PushOutOfThings(MKVector3 arg0) {
    MKCollisionResult spB8;
    u8 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    KDColObjDescriptor *temp_r3_21;
    KDColObjDescriptor *temp_r7_86;
    MKCollisionResult *temp_r4_122;
    f32 temp_f0_163;
    f32 temp_f1_162;
    f32 temp_f30_50;
    f32 temp_f3_165;
    f64 temp_f0_37;
    f64 temp_f1_27;
    s32 temp_r3_93;
    s32 var_ctr_55;
    s32 var_r24_114;
    s32 var_r28_115;
    s32 var_r4_39;
    u32 var_r0_129;
    u8 *var_r27_111;
    u8 *var_r3_52;
    u8 var_r25_112;
    u8 var_r31_113;
    void *temp_r3_126;
    void *temp_r6_59;

    temp_r3_21 = this->unk250;
    sp40 = 0.0f;
    sp38 = 0.0f;
    temp_f1_27 = this->unk240;
    sp3C = temp_r3_21->unk4;
    sp90 = (f64) sp40;
    sp88 = (f64) sp38;
    sp68 = temp_f1_27;
    sp70 = this->unk248;
    temp_f0_37 = temp_f1_27 + sp88;
    sp28 = temp_f0_37;
    var_r4_39 = 0;
    sp78 = temp_f0_37;
    sp30 = (f32) sp70 + (f32) sp90;
    sp80 = (f64) sp30;
    temp_f30_50 = 2.0f + temp_r3_21->unk0;
    var_r3_52 = &sp98;
    var_ctr_55 = 0x1E;
    do {
        temp_r6_59 = &spB8 + var_r4_39;
        *var_r3_52 = 0;
        var_r3_52 += 1;
        M2C_FIELD(temp_r6_59, f32 *, 0) = 0.0f;
        var_r4_39 += 0x58;
        M2C_FIELD(temp_r6_59, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x24) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x2C) = 1.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x30) = 0.0f;
        M2C_FIELD(temp_r6_59, f32 *, 0x34) = 0.0f;
        M2C_FIELD(temp_r6_59, s16 *, 0x38) = 0;
        M2C_FIELD(temp_r6_59, s8 *, 0x3A) = 0;
        M2C_FIELD(temp_r6_59, s8 *, 0x3B) = 0;
        M2C_FIELD(temp_r6_59, s32 *, 0x3C) = 0;
        M2C_FIELD(temp_r6_59, f32 *, 0x40) = 3.4028235e38f;
        M2C_FIELD(temp_r6_59, s32 *, 0x44) = 0;
        M2C_FIELD(temp_r6_59, s32 *, 0x48) = 0;
        M2C_FIELD(temp_r6_59, s32 *, 0x4C) = -1;
        M2C_FIELD(temp_r6_59, s8 *, 0x50) = 0;
        var_ctr_55 -= 1;
    } while (var_ctr_55 != 0);
    temp_r7_86 = this->unk250;
    temp_r3_93 = MKCollision_SphereCollide(*((MKVector3 *) &sp78), temp_f30_50, &spB8, 0x1E, (MKCollisionMode) temp_r7_86->unk8, temp_r7_86->unk18);
    if (temp_r3_93 != 0) {
        Tools_UpdateSphereCollideResults(&spB8, temp_r3_93, *((MKVector3 *) &sp78));
        Tools_PushOut(&spB8, *((MKVector3 *) &sp78), temp_r3_93, temp_f30_50, &sp98, 0.0009999999f + (this->unk250->unk0 / temp_f30_50));
        var_r27_111 = &sp98;
        var_r25_112 = 0;
        var_r31_113 = 0;
        var_r24_114 = 0;
        var_r28_115 = 0;
loop_16:
        if (var_r24_114 < temp_r3_93) {
            if ((u8) *var_r27_111 != 0) {
                temp_r4_122 = &spB8 + var_r28_115;
                if (((u8) temp_r4_122->unk50 != 0) && (temp_r3_126 = temp_r4_122->unk48, ((temp_r3_126 == NULL) == 0)) && (var_r0_129 = M2C_FIELD(temp_r3_126, u32 *, 8), ((var_r0_129 == 0U) == 0))) {

                } else {
                    var_r0_129 = 0U;
                }
                if ((var_r0_129 != 0U) && ((void *) temp_r4_122->unk48 != NULL)) {
                    if (IsFloorCollision(temp_r4_122) != 0) {
                        var_r31_113 = 1;
                    } else {
                        var_r25_112 = 1;
                    }
                }
            }
            var_r24_114 += 1;
            var_r28_115 += 0x58;
            var_r27_111 += 1;
            goto loop_16;
        }
        if (((s32) this->unkC0 <= 0) && ((s32) this->unk180 <= 0) && (temp_f1_162 = M2C_FIELD(arg0, f32 *, 0), temp_f0_163 = M2C_FIELD(arg0, f32 *, 4), temp_f3_165 = M2C_FIELD(arg0, f32 *, 8), ((((temp_f3_165 * temp_f3_165) + ((temp_f1_162 * temp_f1_162) + (temp_f0_163 * temp_f0_163))) < 0.01f) != 0))) {
            if (var_r25_112 != 0) {
                sp18 = sp78 - sp88;
                this->unk240 = sp18;
                sp20 = (f32) sp80 - (f32) sp90;
                sp58 = sp18;
                sp60 = (f64) sp20;
                this->unk248 = (f64) sp20;
                return;
            }
            if (var_r31_113 != 0) {
                M2C_FIELD(this, f32 *, 0x244) = (f32) ((*(f32 *) ((u8 *) &sp78 + 0x4)) - this->unk250->unk4);
            }
        } else {
            sp8 = sp78 - sp88;
            this->unk240 = sp8;
            sp10 = (f32) sp80 - (f32) sp90;
            sp48 = sp8;
            sp50 = (f64) sp10;
            this->unk248 = (f64) sp10;
        }
    }
}
#endif

u8 KDCollisionObject::IsFloorCollision(MKCollisionResult *arg0) {
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
}

#if 0 // DRAFT: undefined identifier 'unk0'
void KDCollisionObject::CalculateNewVelocity(MKVector3 *arg0, const MKVector3 *arg1, float farg0, KDContextInfo *arg2, MKCollisionResult *arg3, const MKVector3 &arg4) {
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;                                      /* compiler-managed */
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
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
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    s32 sp18;
    f32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f10_468;
    f32 temp_f1_375;
    f32 temp_f1_598;
    f32 temp_f1_605;
    f32 temp_f29_314;
    f32 temp_f29_321;
    f32 temp_f2_378;
    f32 temp_f30_400;
    f32 temp_f4_311;
    f32 temp_f4_593;
    f32 temp_f5_373;
    f32 temp_f5_462;
    f32 temp_f6_379;
    f32 temp_f6_657;
    f32 temp_f7_376;
    f32 temp_f7_652;
    f32 temp_f8_374;
    f32 temp_f9_465;
    f32 var_f0_507;
    f32 var_f8_488;
    f64 temp_f0_286;
    f64 temp_f0_356;
    f64 temp_f0_415;
    f64 temp_f0_427;
    f64 temp_f0_634;
    f64 temp_f3_512;
    f64 temp_f3_518;
    f64 temp_f3_522;
    s32 temp_r0_263;
    s32 temp_r3_541;
    s32 var_r0_551;
    void *temp_r31_272;

    temp_r0_263 = M2C_FIELD(arg2, s32 *, 0xB8);
    temp_r31_272 = arg2 + (((arg2->unk0 - 1) * 0x58) + 8);
    switch (temp_r0_263) {                          /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_f0_286 = M2C_FIELD(arg1, f64 *, 0) * (f64) farg0;
        spA0 = temp_f0_286;
        sp180 = temp_f0_286;
        spA8 = arg1->unk8 * farg0;
        sp188 = (f64) spA8;
        sp190 = NProjection(*((MKVector3 *) &sp180), arg4);
        M2C_FIELD(arg0, MKVector3 *, 0) = sp190;
        temp_f4_311 = M2C_FIELD(temp_r31_272, f32 *, 0x18);
        temp_f29_314 = -((arg0->unk8 * temp_f4_311) + ((arg0->unk0 * M2C_FIELD(temp_r31_272, f32 *, 0x10)) + (arg0->unk4 * M2C_FIELD(temp_r31_272, f32 *, 0x14))));
        sp14 = temp_f29_314;
        sp18 = (M2C_BITWISE(s32, sp14) & 0x80000000) | 0x3F800000;
        temp_f29_321 = (0.05f * M2C_BITWISE(f32, sp18)) + temp_f29_314;
        sp90 = (f64) M2C_FIELD(temp_r31_272, f32 *, 0x10) * (f64) temp_f29_321;
        sp98 = temp_f4_311 * temp_f29_321;
        sp1F0 = sp90;
        sp170 = sp90;
        sp178 = (f64) sp98;
        sp1F8 = (f64) sp98;
        M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + sp1F0);
        arg0->unk8 += (f32) sp1F8;
        if ((arg3 != NULL) && (((arg3->unk18 * arg0->unk8) + ((arg3->unk10 * arg0->unk0) + (arg3->unk14 * arg0->unk4))) < 0.0f)) {
            temp_f0_356 = M2C_FIELD(arg1, f64 *, 0) * (f64) farg0;
            sp80 = temp_f0_356;
            sp150 = temp_f0_356;
            sp88 = arg1->unk8 * farg0;
            sp158 = (f64) sp88;
            sp160 = NProjection(*((MKVector3 *) &sp150), arg4);
            M2C_FIELD(arg0, MKVector3 *, 0) = sp160;
            temp_f5_373 = arg3->unk18;
            temp_f8_374 = M2C_FIELD(temp_r31_272, f32 *, 0x10);
            temp_f1_375 = M2C_FIELD(temp_r31_272, f32 *, 0x18);
            temp_f7_376 = arg3->unk14;
            temp_f2_378 = arg3->unk10;
            temp_f6_379 = M2C_FIELD(temp_r31_272, f32 *, 0x14);
            spD4 = (temp_f1_375 * temp_f2_378) - (temp_f8_374 * temp_f5_373);
            spD0 = (temp_f6_379 * temp_f5_373) - (temp_f1_375 * temp_f7_376);
            spD8 = (temp_f8_374 * temp_f7_376) - (temp_f6_379 * temp_f2_378);
            sp1E0 = (f64) spD0;
            sp1E8 = (f64) spD8;
            temp_f30_400 = (arg0->unk8 * (f32) sp1E8) + ((arg0->unk0 * (f32) sp1E0) + (arg0->unk4 * (*(f32 *) ((u8 *) &sp1E0 + 0x4))));
            sp70 = (f64) spD0 * (f64) temp_f30_400;
            sp78 = (f32) sp1E8 * temp_f30_400;
            M2C_FIELD(arg0, f64 *, 0) = sp70;
            M2C_FIELD(arg0, f64 *, 8) = (f64) sp78;
            sp140 = sp70;
            sp148 = (f64) sp78;
            temp_f0_415 = (f64) M2C_FIELD(arg3, f32 *, 0x10) + (f64) M2C_FIELD(temp_r31_272, f32 *, 0x10);
            spC0 = temp_f0_415;
            sp130 = temp_f0_415;
            spC8 = arg3->unk18 + M2C_FIELD(temp_r31_272, f32 *, 0x18);
            sp138 = (f64) spC8;
            temp_f0_427 = temp_f0_415 * 5.122630465e-315;
            spB0 = temp_f0_427;
            sp1D0 = temp_f0_427;
            spB8 = (f32) sp138 * 0.1f;
            sp1D8 = (f64) spB8;
            M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + temp_f0_427);
            arg0->unk8 += (f32) sp1D8;
            return;
        }
        return;
    case 2:                                         /* switch 1 */
        sp60 = M2C_FIELD(arg1, f64 *, 0) * (f64) farg0;
        M2C_FIELD(arg0, f64 *, 0) = sp60;
        sp68 = arg1->unk8 * farg0;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp68;
        temp_f5_462 = M2C_FIELD(temp_r31_272, f32 *, 0x14);
        temp_f9_465 = M2C_FIELD(temp_r31_272, f32 *, 0x10);
        temp_f10_468 = M2C_FIELD(temp_r31_272, f32 *, 0x18);
        sp120 = sp60;
        sp128 = (f64) sp68;
        arg0->unk4 += 0.05f + (((arg0->unk8 * temp_f10_468) + ((arg0->unk0 * temp_f9_465) + (arg0->unk4 * temp_f5_462))) / ((MKVector3::up.unk8 * temp_f10_468) + ((MKVector3::up.unk0 * temp_f9_465) + (MKVector3::up.unk4 * temp_f5_462))));
        /* fallthrough */
    case 3:                                         /* switch 1 */
        sp50 = M2C_FIELD(arg1, f64 *, 0) * (f64) farg0;
        var_f8_488 = 0.0f;
        M2C_FIELD(arg0, f64 *, 0) = sp50;
        sp58 = arg1->unk8 * farg0;
        sp110 = sp50;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp58;
        sp1C0 = (f64) M2C_FIELD(temp_r31_272, f32 *, 0x10);
        sp1C8 = (f64) M2C_FIELD(temp_r31_272, f32 *, 0x18);
        sp118 = (f64) sp58;
        (*(f32 *) ((u8 *) &sp1B8 + 0xc)) = 0.0f;
        var_f0_507 = ((f32) sp1C8 * (f32) sp1C8) + (((f32) sp1C0 * (f32) sp1C0) + (0.0f * 0.0f));
        if (var_f0_507 > 0.000001f) {
            if (var_f0_507 > 0.0f) {
                temp_f3_512 = __frsqrte(var_f0_507);
                temp_f3_518 = 0.5 * temp_f3_512 * -(((f64) var_f0_507 * (temp_f3_512 * temp_f3_512)) - 3.0);
                temp_f3_522 = 0.5 * temp_f3_518 * -(((f64) var_f0_507 * (temp_f3_518 * temp_f3_518)) - 3.0);
                var_f0_507 = (f32) ((f64) var_f0_507 * (0.5 * temp_f3_522 * -(((f64) var_f0_507 * (temp_f3_522 * temp_f3_522)) - 3.0)));
            } else if (var_f0_507 < M2C_BITWISE(f32, 0.0)) {
                var_f0_507 = __float_nan;
            } else {
                sp8 = var_f0_507;
                temp_r3_541 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_541) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_551 = 1;
                    } else {
                        var_r0_551 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_551 = 5;
                    } else {
                        var_r0_551 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_551 = 4;
                    break;
                }
                if (var_r0_551 == 1) {
                    var_f0_507 = __float_nan;
                }
            }
            var_f8_488 = 1.0f / var_f0_507;
        } else {
            var_f0_507 = 0.0f;
        }
        temp_f4_593 = (f32) sp1C8 * var_f8_488;
        sp1C0 = (f32) sp1C0 * var_f8_488;
        (*(f32 *) ((u8 *) &sp1B8 + 0xc)) *= var_f8_488;
        sp1C8 = temp_f4_593;
        temp_f1_598 = -((arg0->unk8 * M2C_FIELD(temp_r31_272, f32 *, 0x18)) + ((arg0->unk0 * M2C_FIELD(temp_r31_272, f32 *, 0x10)) + (arg0->unk4 * M2C_FIELD(temp_r31_272, f32 *, 0x14)))) / var_f0_507;
        spC = temp_f1_598;
        sp10 = (M2C_BITWISE(s32, spC) & 0x80000000) | 0x3F800000;
        temp_f1_605 = (0.05f * M2C_BITWISE(f32, sp10)) + temp_f1_598;
        sp40 = (f64) sp1C0 * (f64) temp_f1_605;
        sp48 = temp_f4_593 * temp_f1_605;
        sp1B0 = sp40;
        sp100 = sp40;
        sp108 = (f64) sp48;
        sp1B8 = (f64) sp48;
        M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + sp1B0);
        arg0->unk8 += (f32) sp1B8;
        return;
    case 4:                                         /* switch 1 */
        arg0->unk0 = 0.0f;
        arg0->unk4 = 0.0f;
        arg0->unk8 = 0.0f;
        return;
    case 5:                                         /* switch 1 */
        temp_f0_634 = M2C_FIELD(arg1, f64 *, 0) * (f64) farg0;
        sp30 = temp_f0_634;
        M2C_FIELD(arg0, f64 *, 0) = temp_f0_634;
        sp38 = arg1->unk8 * farg0;
        spF0 = temp_f0_634;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp38;
        temp_f7_652 = M2C_FIELD(temp_r31_272, f32 *, 0x18);
        spF8 = (f64) sp38;
        temp_f6_657 = 2.0f * -((arg0->unk8 * temp_f7_652) + ((arg0->unk0 * M2C_FIELD(temp_r31_272, f32 *, 0x10)) + (arg0->unk4 * M2C_FIELD(temp_r31_272, f32 *, 0x14))));
        sp20 = (f64) M2C_FIELD(temp_r31_272, f32 *, 0x10) * (f64) temp_f6_657;
        sp28 = temp_f7_652 * temp_f6_657;
        sp1A0 = sp20;
        spE0 = sp20;
        spE8 = (f64) sp28;
        sp1A8 = (f64) sp28;
        M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + sp1A0);
        arg0->unk8 += (f32) sp1A8;
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void KDCollisionObject::ResolveCollisions(KDCollisionObject *arg0, MKVector3 *arg1, MKVector3 *arg2, int arg3, float arg4, MKCollisionMode arg5, int arg6) {
    s32 sp1F8;
    s32 sp140;
    u8 sp138;
    s32 sp134;
    s32 sp130;
    s32 sp12C;
    f32 sp128;
    s32 sp124;
    s32 sp120;
    f32 sp11C;
    f32 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    u8 spE0;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    f32 spD0;
    s32 spCC;
    s8 spCB;
    s8 spCA;
    s16 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
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
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *var_r5_1117;
    f32 temp_f0_1173;
    f32 temp_f0_1181;
    f32 temp_f0_873;
    f32 temp_f0_975;
    f32 temp_f1_1046;
    f32 temp_f1_1210;
    f32 temp_f1_871;
    f32 temp_f1_974;
    f32 temp_f2_977;
    f32 temp_f3_1051;
    f32 temp_f3_875;
    f32 var_f1_1171;
    f32 var_f24_981;
    f32 var_f25_1184;
    f32 var_f3_947;
    f32 var_f4_880;
    f64 temp_f0_1049;
    f64 temp_f0_1060;
    f64 temp_f0_1192;
    f64 temp_f1_886;
    f64 temp_f1_892;
    f64 temp_f1_896;
    f64 temp_f1_986;
    f64 temp_f1_992;
    f64 temp_f1_996;
    s32 temp_r0_1215;
    s32 temp_r3_1015;
    s32 temp_r3_915;
    s32 var_ctr_732;
    s32 var_ctr_767;
    s32 var_ctr_801;
    s32 var_ctr_839;
    s32 var_r0_1025;
    s32 var_r0_925;
    s32 var_r29_955;
    s32 var_r3_764;
    s32 var_r3_798;
    s32 var_r3_836;
    s32 var_r4_726;
    u8 var_r30_872;
    void *temp_r5_736;
    void *temp_r5_769;
    void *temp_r5_803;
    void *temp_r6_843;
    void *temp_r7_1132;

    if (this != NULL) {
        var_r4_726 = 0;
        M2C_FIELD(this, s32 *, 0) = 0;
        var_ctr_732 = 2;
        do {
            temp_r5_736 = this + (var_r4_726 + 8);
            M2C_FIELD(temp_r5_736, f32 *, 0) = 0.0f;
            var_r4_726 += 0x58;
            M2C_FIELD(temp_r5_736, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 8) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x14) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x18) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x30) = 0.0f;
            M2C_FIELD(temp_r5_736, f32 *, 0x34) = 0.0f;
            M2C_FIELD(temp_r5_736, s16 *, 0x38) = 0;
            M2C_FIELD(temp_r5_736, s8 *, 0x3A) = 0;
            M2C_FIELD(temp_r5_736, s8 *, 0x3B) = 0;
            M2C_FIELD(temp_r5_736, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_r5_736, f32 *, 0x40) = 3.4028235e38f;
            M2C_FIELD(temp_r5_736, s32 *, 0x44) = 0;
            M2C_FIELD(temp_r5_736, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r5_736, s32 *, 0x4C) = -1;
            M2C_FIELD(temp_r5_736, s8 *, 0x50) = 0;
            var_ctr_732 -= 1;
        } while (var_ctr_732 != 0);
        this->unkC0 = 0;
        var_r3_764 = 0;
        var_ctr_767 = 2;
        do {
            temp_r5_769 = this + var_r3_764;
            M2C_FIELD(temp_r5_769, f32 *, 0xC8) = 0.0f;
            var_r3_764 += 0x58;
            M2C_FIELD(temp_r5_769, f32 *, 0xCC) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xD0) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xD8) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xDC) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xE0) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xE8) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xEC) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xF0) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xF4) = 1.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xF8) = 0.0f;
            M2C_FIELD(temp_r5_769, f32 *, 0xFC) = 0.0f;
            M2C_FIELD(temp_r5_769, s16 *, 0x100) = 0;
            M2C_FIELD(temp_r5_769, s8 *, 0x102) = 0;
            M2C_FIELD(temp_r5_769, s8 *, 0x103) = 0;
            M2C_FIELD(temp_r5_769, s32 *, 0x104) = 0;
            M2C_FIELD(temp_r5_769, f32 *, 0x108) = 3.4028235e38f;
            M2C_FIELD(temp_r5_769, s32 *, 0x10C) = 0;
            M2C_FIELD(temp_r5_769, s32 *, 0x110) = 0;
            M2C_FIELD(temp_r5_769, s32 *, 0x114) = -1;
            M2C_FIELD(temp_r5_769, s8 *, 0x118) = 0;
            var_ctr_767 -= 1;
        } while (var_ctr_767 != 0);
        this->unk180 = 0;
        var_r3_798 = 0;
        var_ctr_801 = 2;
        do {
            temp_r5_803 = this + var_r3_798;
            M2C_FIELD(temp_r5_803, f32 *, 0x188) = 0.0f;
            var_r3_798 += 0x58;
            M2C_FIELD(temp_r5_803, f32 *, 0x18C) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x190) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x198) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x19C) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1A0) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1A8) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1AC) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1B0) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1B4) = 1.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1B8) = 0.0f;
            M2C_FIELD(temp_r5_803, f32 *, 0x1BC) = 0.0f;
            M2C_FIELD(temp_r5_803, s16 *, 0x1C0) = 0;
            M2C_FIELD(temp_r5_803, s8 *, 0x1C2) = 0;
            M2C_FIELD(temp_r5_803, s8 *, 0x1C3) = 0;
            M2C_FIELD(temp_r5_803, s32 *, 0x1C4) = 0;
            M2C_FIELD(temp_r5_803, f32 *, 0x1C8) = 3.4028235e38f;
            M2C_FIELD(temp_r5_803, s32 *, 0x1CC) = 0;
            M2C_FIELD(temp_r5_803, s32 *, 0x1D0) = 0;
            M2C_FIELD(temp_r5_803, s32 *, 0x1D4) = -1;
            M2C_FIELD(temp_r5_803, s8 *, 0x1D8) = 0;
            var_ctr_801 -= 1;
        } while (var_ctr_801 != 0);
    } else {
        sp140 = 0;
        var_r3_836 = 0;
        var_ctr_839 = 2;
        do {
            temp_r6_843 = &sp140 + (var_r3_836 + 8);
            M2C_FIELD(temp_r6_843, f32 *, 0) = 0.0f;
            var_r3_836 += 0x58;
            M2C_FIELD(temp_r6_843, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 8) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x10) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x14) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x18) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x20) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x24) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x30) = 0.0f;
            M2C_FIELD(temp_r6_843, f32 *, 0x34) = 0.0f;
            M2C_FIELD(temp_r6_843, s16 *, 0x38) = 0;
            M2C_FIELD(temp_r6_843, s8 *, 0x3A) = 0;
            M2C_FIELD(temp_r6_843, s8 *, 0x3B) = 0;
            M2C_FIELD(temp_r6_843, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_r6_843, f32 *, 0x40) = 3.4028235e38f;
            M2C_FIELD(temp_r6_843, s32 *, 0x44) = 0;
            M2C_FIELD(temp_r6_843, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r6_843, s32 *, 0x4C) = -1;
            M2C_FIELD(temp_r6_843, s8 *, 0x50) = 0;
            var_ctr_839 -= 1;
        } while (var_ctr_839 != 0);
        sp1F8 = 1;
    }
    temp_f1_871 = arg1->unk0;
    var_r30_872 = 0;
    temp_f0_873 = arg1->unk4;
    temp_f3_875 = arg1->unk8;
    var_f4_880 = (temp_f3_875 * temp_f3_875) + ((temp_f1_871 * temp_f1_871) + (temp_f0_873 * temp_f0_873));
    if (var_f4_880 > 1e-12f) {
        if (var_f4_880 > 0.0f) {
            temp_f1_886 = __frsqrte(var_f4_880);
            temp_f1_892 = 0.5 * temp_f1_886 * -(((f64) var_f4_880 * (temp_f1_886 * temp_f1_886)) - 3.0);
            temp_f1_896 = 0.5 * temp_f1_892 * -(((f64) var_f4_880 * (temp_f1_892 * temp_f1_892)) - 3.0);
            var_f4_880 = (f32) ((f64) var_f4_880 * (0.5 * temp_f1_896 * -(((f64) var_f4_880 * (temp_f1_896 * temp_f1_896)) - 3.0)));
        } else if (var_f4_880 < M2C_BITWISE(f32, 0.0)) {
            var_f4_880 = __float_nan;
        } else {
            spC = var_f4_880;
            temp_r3_915 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_915) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_925 = 1;
                } else {
                    var_r0_925 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_925 = 5;
                } else {
                    var_r0_925 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_925 = 4;
                break;
            }
            if (var_r0_925 == 1) {
                var_f4_880 = __float_nan;
            }
        }
        var_f3_947 = 1.0f / var_f4_880;
    } else {
        var_f3_947 = 0.0f;
    }
    var_r29_955 = 0;
    sp40 = arg1->unk0 * var_f3_947;
    sp44 = arg1->unk4 * var_f3_947;
    sp48 = arg1->unk8 * var_f3_947;
    sp80 = (f64) sp40;
    sp88 = (f64) sp48;
loop_65:
    if (var_r29_955 >= arg2) {

    } else {
        temp_f1_974 = arg1->unk0;
        temp_f0_975 = arg1->unk4;
        temp_f2_977 = arg1->unk8;
        var_f24_981 = (temp_f2_977 * temp_f2_977) + ((temp_f1_974 * temp_f1_974) + (temp_f0_975 * temp_f0_975));
        if (!(var_f24_981 < 0.0025000002f)) {
            if (var_f24_981 > 0.0f) {
                temp_f1_986 = __frsqrte(var_f24_981);
                temp_f1_992 = 0.5 * temp_f1_986 * -(((f64) var_f24_981 * (temp_f1_986 * temp_f1_986)) - 3.0);
                temp_f1_996 = 0.5 * temp_f1_992 * -(((f64) var_f24_981 * (temp_f1_992 * temp_f1_992)) - 3.0);
                var_f24_981 = (f32) ((f64) var_f24_981 * (0.5 * temp_f1_996 * -(((f64) var_f24_981 * (temp_f1_996 * temp_f1_996)) - 3.0)));
            } else if (var_f24_981 < M2C_BITWISE(f32, 0.0)) {
                var_f24_981 = __float_nan;
            } else {
                sp8 = var_f24_981;
                temp_r3_1015 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1015) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1025 = 1;
                    } else {
                        var_r0_1025 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1025 = 5;
                    } else {
                        var_r0_1025 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_1025 = 4;
                    break;
                }
                if (var_r0_1025 == 1) {
                    var_f24_981 = __float_nan;
                }
            }
            temp_f1_1046 = 1.0f / var_f24_981;
            temp_f0_1049 = (f64) M2C_FIELD(arg1, f32 *, 0) * (f64) temp_f1_1046;
            sp30 = temp_f0_1049;
            temp_f3_1051 = arg1->unk8;
            sp70 = temp_f0_1049;
            sp38 = temp_f3_1051 * temp_f1_1046;
            sp78 = (f64) sp38;
            temp_f0_1060 = arg0->unk0 + (f64) M2C_FIELD(arg1, f32 *, 0);
            sp20 = temp_f0_1060;
            sp60 = temp_f0_1060;
            sp28 = M2C_FIELD(arg0, f32 *, 8) + temp_f3_1051;
            sp90 = 0.0f;
            sp68 = (f64) sp28;
            sp94 = 0.0f;
            sp98 = 0.0f;
            spA0 = 0.0f;
            spA4 = 0.0f;
            spA8 = 0.0f;
            spB0 = 0.0f;
            spB4 = 0.0f;
            spB8 = 0.0f;
            spBC = 1.0f;
            spC0 = 0.0f;
            spC4 = 0.0f;
            spC8 = 0;
            spCA = 0;
            spCB = 0;
            spCC = 0;
            spD0 = 3.4028235e38f;
            spD4 = 0;
            spD8 = 0;
            spDC = -1;
            spE0 = 0;
            if (MKCollision_SweepSphereCollide(*((MKVector3 *) arg0), *((MKVector3 *) &sp60), arg4, (MKCollisionResult *) &sp90, (MKCollisionMode) arg3, (s32) arg5) == 0) {
                arg0->unk0 += (f64) M2C_FIELD(arg1, f32 *, 0);
                M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + arg1->unk8);
                return;
            }
            if (this != NULL) {
                var_r5_1117 = StoreResult((MKCollisionResult *) &sp90, (MKVector3 *) &sp70);
            } else {
                sp1F8 = 1;
                var_r5_1117 = (MKVector3 *) &sp140;
                if (sp140 < 2) {
                    temp_r7_1132 = var_r5_1117 + ((sp140 * 0x58) + 8);
                    M2C_FIELD(temp_r7_1132, f64 *, 0) = (f64) sp90;
                    M2C_FIELD(temp_r7_1132, f64 *, 8) = (f64) sp98;
                    M2C_FIELD(temp_r7_1132, f64 *, 0x10) = (f64) spA0;
                    M2C_FIELD(temp_r7_1132, f64 *, 0x18) = (f64) spA8;
                    M2C_FIELD(temp_r7_1132, f64 *, 0x20) = (f64) spB0;
                    M2C_FIELD(temp_r7_1132, f64 *, 0x28) = (f64) spB8;
                    M2C_FIELD(temp_r7_1132, f32 *, 0x30) = spC0;
                    M2C_FIELD(temp_r7_1132, f32 *, 0x34) = spC4;
                    M2C_FIELD(temp_r7_1132, s32 *, 0x38) = (s32) spC8;
                    M2C_FIELD(temp_r7_1132, s32 *, 0x3C) = spCC;
                    M2C_FIELD(temp_r7_1132, f32 *, 0x40) = spD0;
                    M2C_FIELD(temp_r7_1132, s32 *, 0x44) = spD4;
                    M2C_FIELD(temp_r7_1132, s32 *, 0x48) = spD8;
                    M2C_FIELD(temp_r7_1132, s32 *, 0x4C) = spDC;
                    M2C_FIELD(temp_r7_1132, u8 *, 0x50) = spE0;
                    sp140 += 1;
                }
            }
            var_f1_1171 = 0.000001f;
            temp_f0_1173 = -(((f32) sp78 * spA8) + (((f32) sp70 * spA0) + ((*(f32 *) ((u8 *) &sp70 + 0x4)) * spA4)));
            if (temp_f0_1173 > var_f1_1171) {
                var_f1_1171 = temp_f0_1173;
            }
            temp_f0_1181 = (var_f24_981 * spD0) - (0.05f / var_f1_1171);
            if (0.0f > temp_f0_1181) {
                var_f25_1184 = 0.0f;
            } else {
                var_f25_1184 = temp_f0_1181;
            }
            if (var_f25_1184 > 0.0f) {
                temp_f0_1192 = sp70 * (f64) var_f25_1184;
                sp10 = temp_f0_1192;
                sp50 = temp_f0_1192;
                sp18 = (f32) sp78 * var_f25_1184;
                sp58 = (f64) sp18;
                arg0->unk0 += temp_f0_1192;
                M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + (f32) sp58);
            }
            temp_f1_1210 = var_f24_981 - var_f25_1184;
            if (!(temp_f1_1210 < 0.05f)) {
                temp_r0_1215 = 0 - var_r30_872;
                KDCollisionObject::CalculateNewVelocity(arg1, (MKVector3 *) &sp70, temp_f1_1210, (KDContextInfo *) var_r5_1117, (MKCollisionResult *) ((s32) &spE8 & ((temp_r0_1215 - temp_r0_1215) - !M2C_CARRY)), *((MKVector3 *) &sp80));
                var_r30_872 = 1;
                var_r29_955 += 1;
                spE8 = (f64) sp90;
                spF0 = (f64) sp98;
                spF8 = (f64) spA0;
                sp100 = (f64) spA8;
                sp108 = (f64) spB0;
                sp110 = (f64) spB8;
                sp118 = spC0;
                sp11C = spC4;
                sp120 = (s32) spC8;
                sp124 = spCC;
                sp128 = spD0;
                sp12C = spD4;
                sp130 = spD8;
                sp134 = spDC;
                sp138 = spE0;
                goto loop_65;
            }
        }
    }
}
#endif

void KDCollisionObject::ResolveCollisions(MKVector3 *arg0, MKVector3 *arg1, int arg2) {
    KDColObjDescriptor *temp_r8_1288;

    temp_r8_1288 = this->unk250;
    ResolveCollisions((KDCollisionObject *) arg0, arg1, (MKVector3 *) arg2, temp_r8_1288->unk8, temp_r8_1288->unk0, (MKCollisionMode) temp_r8_1288->unk18, M2C_ERROR(/* Read from unset register $r9 */));
}

MKVector3 *KDCollisionObject::StoreResult(MKCollisionResult *arg0, MKVector3 *arg1) {
    KDColObjDescriptor *temp_r7_1303;
    f32 *var_r10_1313;
    f32 temp_f1_1317;
    s32 *var_r9_1307;
    s32 temp_r0_1348;
    void *temp_r5_1355;

    temp_r7_1303 = this->unk250;
    var_r9_1307 = &this->unkC0;
    var_r10_1313 = &temp_r7_1303->unk28;
    temp_f1_1317 = (MKVector3::up.unk8 * arg0->unk18) + ((MKVector3::up.unk0 * arg0->unk10) + (MKVector3::up.unk4 * arg0->unk14));
    if (temp_f1_1317 > temp_r7_1303->unk1C) {
        var_r9_1307 = (s32 *) this;
        var_r10_1313 = &temp_r7_1303->unk1C;
    } else if (temp_f1_1317 < temp_r7_1303->unk34) {
        var_r9_1307 = &this->unk180;
        var_r10_1313 = &temp_r7_1303->unk34;
    }
    M2C_FIELD(var_r9_1307, s32 *, 0xB8) = (s32) temp_r7_1303->unkC;
    if (((arg1->unk8 * arg0->unk18) + ((arg1->unk0 * arg0->unk10) + (arg1->unk4 * arg0->unk14))) < M2C_FIELD(var_r10_1313, f32 *, 4)) {
        M2C_FIELD(var_r9_1307, s32 *, 0xB8) = (s32) M2C_FIELD(var_r10_1313, s32 *, 8);
    }
    temp_r0_1348 = M2C_FIELD(var_r9_1307, s32 *, 0);
    if (temp_r0_1348 < 2) {
        temp_r5_1355 = var_r9_1307 + ((temp_r0_1348 * 0x58) + 8);
        M2C_FIELD(temp_r5_1355, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
        M2C_FIELD(temp_r5_1355, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
        M2C_FIELD(temp_r5_1355, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f32 *, 0x10);
        M2C_FIELD(temp_r5_1355, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(temp_r5_1355, f64 *, 0x20) = (f64) M2C_FIELD(arg0, f64 *, 0x20);
        M2C_FIELD(temp_r5_1355, f64 *, 0x28) = (f64) M2C_FIELD(arg0, f64 *, 0x28);
        M2C_STRUCT_COPY(temp_r5_1355, arg0, 0x10);
        M2C_FIELD(temp_r5_1355, f32 *, 0x40) = (f32) arg0->unk40;
        M2C_FIELD(temp_r5_1355, s32 *, 0x44) = (s32) arg0->unk44;
        M2C_FIELD(temp_r5_1355, void **, 0x48) = (void *) arg0->unk48;
        M2C_FIELD(temp_r5_1355, s32 *, 0x4C) = (s32) arg0->unk4C;
        M2C_FIELD(temp_r5_1355, u8 *, 0x50) = (u8) arg0->unk50;
        M2C_FIELD(var_r9_1307, s32 *, 0) += 1;
    }
    return (MKVector3 *) var_r9_1307;
}

void KDCollisionObject::CalcPushOutPos(const MKVector3 &arg0, MKVector3 *arg1, KDColObjDescriptor *arg2, float farg0, KDCollisionObject::UpdateResult *arg3) {
    ((KDCollisionObject *) &arg0)->CalcPushOutPos(*arg1, (MKVector3 *) arg2->unk10, arg2->unk8, farg0, (MKCollisionMode) arg2->unk18, (s32) arg3, M2C_ERROR(/* Read from unset register $r9 */));
}

#if 0 // DRAFT: illegal operands 'MKCollisionResult' < 'MKCollisionResult'
s32 KDCollisionObject::CalcPushOutPos(const MKVector3 &arg1, MKVector3 *arg2, int arg3, float farg0, MKCollisionMode arg4, int arg5, KDCollisionObject::UpdateResult *arg6) {
    MKCollisionResult sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f27_1511;
    f32 temp_f27_1514;
    f64 temp_f0_1518;
    s32 temp_r3_1484;
    s32 var_ctr_1449;
    s32 var_ctr_1491;
    s32 var_r29_1445;
    s32 var_r30_1444;
    s32 var_r3_1448;
    s32 var_r3_1547;
    s32 var_r4_1490;
    s32 var_r5_1488;
    s32 var_r6_1489;
    u8 var_r31_1443;
    void *temp_r3_1510;
    void *temp_r5_1453;

    sp28 = this->unk0;
    sp30 = this->unk8;
    var_r31_1443 = 0;
    var_r30_1444 = 0;
    var_r29_1445 = 0;
loop_1:
    var_r3_1448 = 0;
    var_ctr_1449 = 0x10;
    do {
        temp_r5_1453 = &sp38 + var_r3_1448;
        M2C_FIELD(temp_r5_1453, f32 *, 0) = 0.0f;
        var_r3_1448 += 0x58;
        M2C_FIELD(temp_r5_1453, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x24) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x2C) = 1.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x30) = 0.0f;
        M2C_FIELD(temp_r5_1453, f32 *, 0x34) = 0.0f;
        M2C_FIELD(temp_r5_1453, s16 *, 0x38) = 0;
        M2C_FIELD(temp_r5_1453, s8 *, 0x3A) = 0;
        M2C_FIELD(temp_r5_1453, s8 *, 0x3B) = 0;
        M2C_FIELD(temp_r5_1453, s32 *, 0x3C) = 0;
        M2C_FIELD(temp_r5_1453, f32 *, 0x40) = 3.4028235e38f;
        M2C_FIELD(temp_r5_1453, s32 *, 0x44) = 0;
        M2C_FIELD(temp_r5_1453, s32 *, 0x48) = 0;
        M2C_FIELD(temp_r5_1453, s32 *, 0x4C) = -1;
        M2C_FIELD(temp_r5_1453, s8 *, 0x50) = 0;
        var_ctr_1449 -= 1;
    } while (var_ctr_1449 != 0);
    temp_r3_1484 = MKCollision_SphereCollide(*((MKVector3 *) &sp28), farg0, &sp38, 0x10, (MKCollisionMode) arg3, (s32) arg4);
    if (temp_r3_1484 != 0) {
        var_r5_1488 = 0;
        var_r6_1489 = 1;
        var_r4_1490 = 0x58;
        var_ctr_1491 = temp_r3_1484 - 1;
        if (temp_r3_1484 > 1) {
            do {
                if (*(&sp38 + (var_r4_1490 + 0x40)) < *(&sp38 + ((var_r5_1488 * 0x58) + 0x40))) {
                    var_r5_1488 = var_r6_1489;
                }
                var_r6_1489 += 1;
                var_r4_1490 += 0x58;
                var_ctr_1491 -= 1;
            } while (var_ctr_1491 != 0);
        }
        temp_r3_1510 = &sp38 + (var_r5_1488 * 0x58);
        temp_f27_1511 = M2C_FIELD(temp_r3_1510, f32 *, 0x40);
        if (temp_f27_1511 > 0.05f) {
            temp_f27_1514 = temp_f27_1511 + 0.05f;
            var_r31_1443 = 1;
            temp_f0_1518 = M2C_FIELD(temp_r3_1510, f64 *, 0x10) * (f64) temp_f27_1514;
            sp8 = temp_f0_1518;
            sp18 = temp_f0_1518;
            sp10 = M2C_FIELD(temp_r3_1510, f32 *, 0x18) * temp_f27_1514;
            sp20 = (f64) sp10;
            NULL->ResolveCollisions((KDCollisionObject *) &sp28, (MKVector3 *) &sp18, (MKVector3 *)8, arg3, farg0, arg4, M2C_ERROR(/* Read from unset register $r9 */));
        }
        var_r29_1445 += 1;
        if (var_r29_1445 < 8) {
            goto loop_1;
        }
    } else {
        var_r30_1444 = 1;
    }
    if ((u32) arg5 != 0U) {
        var_r3_1547 = 8;
        if (var_r31_1443 != 0) {
            var_r3_1547 = 7;
        }
        *arg5 = var_r3_1547;
    }
    if (&arg1 != NULL) {
        M2C_FIELD(&arg1, f64 *, 0) = sp28;
        M2C_FIELD(&arg1, f64 *, 8) = sp30;
    }
    return var_r30_1444;
}
#endif

s8 KDCollisionObject::Teleport(const MKVector3 &arg0, float arg1, int arg2, MKCollisionResult *arg3) {
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    KDColObjDescriptor *temp_r7_1627;
    MKCollisionInfo *temp_r7_1591;
    s32 var_r30_1592;

    temp_r7_1591 = this->unk254;
    var_r30_1592 = arg2;
    sp8 = temp_r7_1591;
    if (temp_r7_1591 != NULL) {
        spC = temp_r7_1591->unk4;
        temp_r7_1591->unk4 = 0;
    }
    sp30 = M2C_FIELD(&arg0, f64 *, 0);
    sp38 = M2C_FIELD(&arg0, f64 *, 8);
    (*(f32 *) ((u8 *) &sp30 + 0x4)) += this->unk250->unk4;
loop_7:
    temp_r7_1627 = this->unk250;
    if ((MKCollision_SphereCollide(*((MKVector3 *) &sp30), temp_r7_1627->unk0, arg3, 1, (MKCollisionMode) temp_r7_1627->unk8, temp_r7_1627->unk18) == 0) || (var_r30_1592 == 0)) {
        this->unk240 = sp30;
        this->unk248 = sp38;
        sp18 = 0.0f;
        sp10 = 0.0f;
        sp14 = -arg1;
        M2C_FIELD(this, f32 *, 0x244) = (f32) (M2C_FIELD(this, f32 *, 0x244) - this->unk250->unk4);
        sp28 = (f64) sp18;
        sp20 = (f64) sp10;
        ResolveCollisions((MKVector3 *) &sp30, (MKVector3 *) &sp20, 1);
        if ((s32) M2C_FIELD(this, s32 *, 0) > 0) {
            (*(f32 *) ((u8 *) &sp30 + 0x4)) -= this->unk250->unk4;
            this->unk240 = sp30;
            this->unk248 = sp38;
        }
        if (sp8 != NULL) {
            sp8->unk4 = spC;
        }
        return 1;
    }
    var_r30_1592 -= 1;
    (*(f32 *) ((u8 *) &sp30 + 0x4)) += arg1;
    if (var_r30_1592 <= 0) {
        if (sp8 != NULL) {
            sp8->unk4 = spC;
        }
        return 0;
    }
    goto loop_7;
}

s32 KDCollisionObject::Update(MKVector3 *arg0, float arg1) {
    f64 sp18;
    f64 sp10;
    u8 spC;
    MKCollisionInfo *sp8;
    KDColObjDescriptor *temp_r6_1718;
    MKCollisionInfo *temp_r5_1701;
    s32 var_r3_1747;
    u8 var_r3_1725;

    temp_r5_1701 = this->unk254;
    sp8 = temp_r5_1701;
    if (temp_r5_1701 != NULL) {
        spC = temp_r5_1701->unk4;
        temp_r5_1701->unk4 = 0;
    }
    sp10 = this->unk240;
    sp18 = this->unk248;
    temp_r6_1718 = this->unk250;
    (*(f32 *) ((u8 *) &sp10 + 0x4)) += temp_r6_1718->unk4;
    ResolveCollisions((MKVector3 *) &sp10, arg0, temp_r6_1718->unk10);
    var_r3_1725 = 0;
    (*(f32 *) ((u8 *) &sp10 + 0x4)) -= this->unk250->unk4;
    this->unk240 = sp10;
    this->unk248 = sp18;
    if (((s32) this->unk180 > 0) || ((s32) M2C_FIELD(this, s32 *, 0) > 0) || ((s32) this->unkC0 > 0)) {
        var_r3_1725 = 1;
    }
    var_r3_1747 = 8;
    if (var_r3_1725 != 0) {
        var_r3_1747 = 7;
    }
    if (sp8 != NULL) {
        sp8->unk4 = spC;
    }
    return var_r3_1747;
}

void KDCollisionObject::Deinit() {
    s32 var_ctr_1773;
    s32 var_ctr_1808;
    s32 var_ctr_1842;
    s32 var_r4_1805;
    s32 var_r4_1839;
    s32 var_r5_1767;
    void *temp_r6_1777;
    void *temp_r6_1810;
    void *temp_r6_1844;

    var_r5_1767 = 0;
    M2C_FIELD(this, s32 *, 0) = 0;
    var_ctr_1773 = 2;
    do {
        temp_r6_1777 = this + (var_r5_1767 + 8);
        M2C_FIELD(temp_r6_1777, f32 *, 0) = 0.0f;
        var_r5_1767 += 0x58;
        M2C_FIELD(temp_r6_1777, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x10) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x24) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x2C) = 1.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x30) = 0.0f;
        M2C_FIELD(temp_r6_1777, f32 *, 0x34) = 0.0f;
        M2C_FIELD(temp_r6_1777, s16 *, 0x38) = 0;
        M2C_FIELD(temp_r6_1777, s8 *, 0x3A) = 0;
        M2C_FIELD(temp_r6_1777, s8 *, 0x3B) = 0;
        M2C_FIELD(temp_r6_1777, s32 *, 0x3C) = 0;
        M2C_FIELD(temp_r6_1777, f32 *, 0x40) = 3.4028235e38f;
        M2C_FIELD(temp_r6_1777, s32 *, 0x44) = 0;
        M2C_FIELD(temp_r6_1777, s32 *, 0x48) = 0;
        M2C_FIELD(temp_r6_1777, s32 *, 0x4C) = -1;
        M2C_FIELD(temp_r6_1777, s8 *, 0x50) = 0;
        var_ctr_1773 -= 1;
    } while (var_ctr_1773 != 0);
    this->unkC0 = 0;
    var_r4_1805 = 0;
    var_ctr_1808 = 2;
    do {
        temp_r6_1810 = this + var_r4_1805;
        M2C_FIELD(temp_r6_1810, f32 *, 0xC8) = 0.0f;
        var_r4_1805 += 0x58;
        M2C_FIELD(temp_r6_1810, f32 *, 0xCC) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xD0) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xD8) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xDC) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xE0) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xE8) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xEC) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xF0) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xF4) = 1.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xF8) = 0.0f;
        M2C_FIELD(temp_r6_1810, f32 *, 0xFC) = 0.0f;
        M2C_FIELD(temp_r6_1810, s16 *, 0x100) = 0;
        M2C_FIELD(temp_r6_1810, s8 *, 0x102) = 0;
        M2C_FIELD(temp_r6_1810, s8 *, 0x103) = 0;
        M2C_FIELD(temp_r6_1810, s32 *, 0x104) = 0;
        M2C_FIELD(temp_r6_1810, f32 *, 0x108) = 3.4028235e38f;
        M2C_FIELD(temp_r6_1810, s32 *, 0x10C) = 0;
        M2C_FIELD(temp_r6_1810, s32 *, 0x110) = 0;
        M2C_FIELD(temp_r6_1810, s32 *, 0x114) = -1;
        M2C_FIELD(temp_r6_1810, s8 *, 0x118) = 0;
        var_ctr_1808 -= 1;
    } while (var_ctr_1808 != 0);
    this->unk180 = 0;
    var_r4_1839 = 0;
    var_ctr_1842 = 2;
    do {
        temp_r6_1844 = this + var_r4_1839;
        M2C_FIELD(temp_r6_1844, f32 *, 0x188) = 0.0f;
        var_r4_1839 += 0x58;
        M2C_FIELD(temp_r6_1844, f32 *, 0x18C) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x190) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x198) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x19C) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1A0) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1A8) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1AC) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1B0) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1B4) = 1.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1B8) = 0.0f;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1BC) = 0.0f;
        M2C_FIELD(temp_r6_1844, s16 *, 0x1C0) = 0;
        M2C_FIELD(temp_r6_1844, s8 *, 0x1C2) = 0;
        M2C_FIELD(temp_r6_1844, s8 *, 0x1C3) = 0;
        M2C_FIELD(temp_r6_1844, s32 *, 0x1C4) = 0;
        M2C_FIELD(temp_r6_1844, f32 *, 0x1C8) = 3.4028235e38f;
        M2C_FIELD(temp_r6_1844, s32 *, 0x1CC) = 0;
        M2C_FIELD(temp_r6_1844, s32 *, 0x1D0) = 0;
        M2C_FIELD(temp_r6_1844, s32 *, 0x1D4) = -1;
        M2C_FIELD(temp_r6_1844, s8 *, 0x1D8) = 0;
        var_ctr_1842 -= 1;
    } while (var_ctr_1842 != 0);
    this->unk250 = NULL;
    M2C_FIELD(this, f32 *, 0x240) = 0.0f;
    M2C_FIELD(this, f32 *, 0x244) = 0.0f;
    M2C_FIELD(this, f32 *, 0x248) = 0.0f;
}

void KDCollisionObject::Init(KDColObjDescriptor *arg0, const MKVector3 &arg1, MKCollisionInfo *arg2, MKCollisionManager *arg3) {
    MKCollisionResult sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDColObjDescriptor *temp_r6_1910;

    this->unkC0 = 0;
    M2C_FIELD(this, s32 *, 0) = 0;
    this->unk180 = 0;
    this->unk250 = arg0;
    this->unk254 = arg2;
    if ((u8) this->unk250->unk40 == 1) {
        sp8 = 1.0f;
        spC = 1.0f;
        sp10 = 1.0f;
        sp14 = 1.0f;
        this->unk240 = M2C_FIELD(&arg1, f64 *, 0);
        this->unk248 = M2C_FIELD(&arg1, f64 *, 8);
        temp_r6_1910 = this->unk250;
        arg3->AddSphere((MKVector3 *) &this->unk240, temp_r6_1910->unk0, temp_r6_1910->unk4, *((MKVector4 *) &sp8), (MKCollisionMode) temp_r6_1910->unk8, this->unk254, 0U);
    }
    gAssertBool = Teleport(arg1, 10.0f, 0x64, &sp18);
}

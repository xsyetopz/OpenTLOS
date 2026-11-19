#include "spyro/source/EnemyRegion.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/BoundingRegion.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

u32 EnemyRegion::GetPathSegment() {
    if ((u8) this->unk31 != 0) {
        return (u32) this->unk10;
    }
    return 0U;
}

#if 0 // DRAFT: illegal explicit conversion from 'BoundingRegion' to
void EnemyRegion::GetNearestPointOnBoundingRegion(const MKVector3 &arg0, MKVector3 *arg1, MKVector3 *arg2) {
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;                                      /* compiler-managed */
    f64 sp150;
    BoundingRegion sp130;
    f64 sp120;
    MKVector3 sp110;
    f64 sp100;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    BoundingRegion spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_95;
    f32 temp_f27_54;
    f32 temp_f28_55;
    f32 temp_f29_57;
    f32 temp_f2_142;
    f32 temp_f2_87;
    f32 temp_f2_91;
    f32 temp_f5_139;
    f32 temp_f5_88;
    f32 temp_f6_135;
    f32 var_f30_39;
    f32 var_f3_392;
    f32 var_f4_170;
    f32 var_f4_325;
    f32 var_f5_189;
    f64 temp_f1_194;
    f64 temp_f1_200;
    f64 temp_f1_204;
    f64 temp_f1_331;
    f64 temp_f1_337;
    f64 temp_f1_341;
    f64 temp_f4_129;
    f64 temp_f4_81;
    s32 temp_r27_52;
    s32 temp_r28_56;
    s32 temp_r3_223;
    s32 temp_r3_360;
    s32 var_r0_233;
    s32 var_r0_370;
    s32 var_r24_53;

    var_f30_39 = 3.4028235e38f;
    sp190 = this->unk0;
    sp198 = this->unk8;
    if ((u8) this->unk31 != 0) {
        temp_r27_52 = this->unk18;
        var_r24_53 = 0;
        temp_f27_54 = arg0.unk4;
        temp_f28_55 = arg0.unk0;
        temp_r28_56 = temp_r27_52 - 1;
        temp_f29_57 = arg0.unk8;
loop_5:
        if (var_r24_53 < temp_r28_56) {
            sp130.GetPos((s32) &this->unk10);
            sp180 = M2C_BITWISE(f64, sp130);
            sp188 = sp130.unk8;
            ((BoundingRegion *) &sp120)->GetPos((s32) &this->unk10);
            sp170 = sp120;
            sp178 = sp128;
            Tools_GetClosestPtOnLine2D(sp110, *((MKVector3 *) &sp180), *((MKVector3 *) &sp170));
            temp_f4_81 = M2C_BITWISE(f64, sp110);
            sp160 = temp_f4_81;
            sp168 = (f64) sp110.unk8;
            temp_f2_87 = (*(f32 *) ((u8 *) &sp160 + 0x4)) - temp_f27_54;
            temp_f5_88 = (f32) sp160 - temp_f28_55;
            temp_f2_91 = (f32) sp168 - temp_f29_57;
            temp_f0_95 = (temp_f2_91 * temp_f2_91) + ((temp_f5_88 * temp_f5_88) + (temp_f2_87 * temp_f2_87));
            if (temp_f0_95 < var_f30_39) {
                var_f30_39 = temp_f0_95;
                sp190 = temp_f4_81;
                sp198 = (f64) sp110.unk8;
            }
            var_r24_53 += 1;
            goto loop_5;
        }
        ((BoundingRegion *) &sp100)->GetPos((s32) &this->unk10);
        sp180 = sp100;
        sp188 = sp108;
        ((BoundingRegion *) &spF0)->GetPos((s32) &this->unk10);
        sp170 = spF0;
        sp178 = spF8;
        Tools_GetClosestPtOnLine2D(spE0, *((MKVector3 *) &sp180), *((MKVector3 *) &sp170));
        temp_f4_129 = M2C_BITWISE(f64, spE0);
        sp160 = temp_f4_129;
        sp168 = (f64) spE0.unk8;
        temp_f6_135 = (*(f32 *) ((u8 *) &sp160 + 0x4)) - arg0.unk4;
        temp_f5_139 = (f32) sp160 - arg0.unk0;
        temp_f2_142 = (f32) sp168 - arg0.unk8;
        if (((temp_f2_142 * temp_f2_142) + ((temp_f5_139 * temp_f5_139) + (temp_f6_135 * temp_f6_135))) < var_f30_39) {
            sp190 = temp_f4_129;
            sp198 = (f64) spE0.unk8;
        }
        M2C_FIELD(arg1, f64 *, 0) = sp190;
        M2C_FIELD(arg1, f64 *, 8) = sp198;
        if (arg2 != NULL) {
            spA0.GetPos((s32) &this->unk10);
            ((BoundingRegion *) &spA0.unk10)->GetPos((s32) &this->unk10);
            var_f4_170 = 0.0f;
            sp54 = 0.0f;
            sp50 = spA0.unk10 - M2C_BITWISE(f32, spA0);
            sp58 = spA0.unk18 - (f32) spA0.unk8;
            spC0 = (f64) sp50;
            spC8 = (f64) sp58;
            var_f5_189 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + ((*(f32 *) ((u8 *) &spC0 + 0x4)) * (*(f32 *) ((u8 *) &spC0 + 0x4))));
            if (var_f5_189 > 1e-12f) {
                if (var_f5_189 > 0.0f) {
                    temp_f1_194 = __frsqrte(var_f5_189);
                    temp_f1_200 = 0.5 * temp_f1_194 * -(((f64) var_f5_189 * (temp_f1_194 * temp_f1_194)) - 3.0);
                    temp_f1_204 = 0.5 * temp_f1_200 * -(((f64) var_f5_189 * (temp_f1_200 * temp_f1_200)) - 3.0);
                    var_f5_189 = (f32) ((f64) var_f5_189 * (0.5 * temp_f1_204 * -(((f64) var_f5_189 * (temp_f1_204 * temp_f1_204)) - 3.0)));
                } else if (var_f5_189 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_189 = __float_nan;
                } else {
                    spC = var_f5_189;
                    temp_r3_223 = M2C_BITWISE(s32, spC) & 0x7F800000;
                    switch (temp_r3_223) {          /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_233 = 1;
                        } else {
                            var_r0_233 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                            var_r0_233 = 5;
                        } else {
                            var_r0_233 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_233 = 4;
                        break;
                    }
                    if (var_r0_233 == 1) {
                        var_f5_189 = __float_nan;
                    }
                }
                var_f4_170 = 1.0f / var_f5_189;
            }
            sp48 = (f32) spC8 * var_f4_170;
            sp40 = (f32) spC0 * var_f4_170;
            sp44 = (*(f32 *) ((u8 *) &spC0 + 0x4)) * var_f4_170;
            spD8 = (f64) sp48;
            spD0 = (f64) sp40;
            sp64 = (MKVector3::up.unk8 * (f32) spD0) - (MKVector3::up.unk0 * (f32) spD8);
            sp60 = (MKVector3::up.unk4 * (f32) spD8) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &spD0 + 0x4)));
            sp68 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &spD0 + 0x4))) - (MKVector3::up.unk4 * (f32) spD0);
            sp150 = (f64) sp60;
            sp158 = (f64) sp68;
            if ((u8) this->unk30 == 0) {
                sp150 *= 1.58735232e-314;
                sp158 = (f32) sp158 * -1.0f;
            }
            M2C_FIELD(arg2, f64 *, 0) = sp150;
            M2C_FIELD(arg2, f64 *, 8) = (f64) sp158;
        }
    } else {
        sp30 = this->unk0 - (f64) M2C_FIELD(&arg0, f32 *, 0);
        sp90 = sp30;
        sp38 = (f32) M2C_FIELD(this, f64 *, 8) - arg0.unk8;
        sp98 = (f64) sp38;
        var_f4_325 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + ((*(f32 *) ((u8 *) &sp90 + 0x4)) * (*(f32 *) ((u8 *) &sp90 + 0x4))));
        if (var_f4_325 > 1e-12f) {
            if (var_f4_325 > 0.0f) {
                temp_f1_331 = __frsqrte(var_f4_325);
                temp_f1_337 = 0.5 * temp_f1_331 * -(((f64) var_f4_325 * (temp_f1_331 * temp_f1_331)) - 3.0);
                temp_f1_341 = 0.5 * temp_f1_337 * -(((f64) var_f4_325 * (temp_f1_337 * temp_f1_337)) - 3.0);
                var_f4_325 = (f32) ((f64) var_f4_325 * (0.5 * temp_f1_341 * -(((f64) var_f4_325 * (temp_f1_341 * temp_f1_341)) - 3.0)));
            } else if (var_f4_325 < M2C_BITWISE(f32, 0.0)) {
                var_f4_325 = __float_nan;
            } else {
                sp8 = var_f4_325;
                temp_r3_360 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_360) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_370 = 1;
                    } else {
                        var_r0_370 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_370 = 5;
                    } else {
                        var_r0_370 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_370 = 4;
                    break;
                }
                if (var_r0_370 == 1) {
                    var_f4_325 = __float_nan;
                }
            }
            var_f3_392 = 1.0f / var_f4_325;
        } else {
            var_f3_392 = 0.0f;
        }
        sp24 = (*(f32 *) ((u8 *) &sp90 + 0x4)) * var_f3_392;
        sp20 = (f32) sp90 * var_f3_392;
        sp28 = (f32) sp98 * var_f3_392;
        sp130.unk10 = (f64) sp20;
        sp130.unk18 = (f64) sp28;
        sp70.operator*(this->unk2C);
        sp10 = this->unk0 - M2C_BITWISE(f64, sp70);
        M2C_FIELD(arg1, f64 *, 0) = sp10;
        sp18 = (f32) M2C_FIELD(this, f64 *, 8) - sp70.unk8;
        sp80 = sp10;
        sp88 = (f64) sp18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp18;
        if (arg2 != NULL) {
            M2C_FIELD(arg2, f64 *, 0) = (f64) sp130.unk10;
            M2C_FIELD(arg2, f64 *, 8) = (f64) sp130.unk18;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'BoundingRegion' to
s32 EnemyRegion::GetFirstIntersectionPlane(const MKVector3 &arg0, const MKVector3 &arg1, MKVector3 *arg2, MKVector3 *arg3) {
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    BoundingRegion sp100;
    f64 spF0;
    f64 spE0;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    BoundingRegion sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f30_473;
    f32 var_f4_587;
    f32 var_f5_606;
    f64 temp_f0_549;
    f64 temp_f1_611;
    f64 temp_f1_617;
    f64 temp_f1_621;
    s32 temp_r28_469;
    s32 temp_r29_474;
    s32 temp_r3_640;
    s32 var_r0_650;
    s32 var_r25_476;
    s32 var_r27_470;

    if ((u8) this->unk31 != 0) {
        temp_r28_469 = this->unk18;
        var_r27_470 = -1;
        var_f30_473 = 3.4028235e38f;
        temp_r29_474 = temp_r28_469 - 1;
        spC = 0.0f;
        var_r25_476 = 0;
loop_6:
        if (var_r25_476 < temp_r29_474) {
            sp100.GetPos((s32) &this->unk10);
            sp150 = M2C_BITWISE(f64, sp100);
            sp158 = sp100.unk8;
            ((BoundingRegion *) &spF0)->GetPos((s32) &this->unk10);
            sp140 = spF0;
            sp148 = spF8;
            if ((Tools_Line2DToLine2DIntersect(arg0, arg1, *((MKVector3 *) &sp150), *((MKVector3 *) &sp140), &spC) != 0) && (spC < var_f30_473)) {
                var_f30_473 = spC;
                var_r27_470 = var_r25_476;
            }
            var_r25_476 += 1;
            goto loop_6;
        }
        ((BoundingRegion *) &spE0)->GetPos((s32) &this->unk10);
        sp130 = spE0;
        sp138 = spE8;
        ((BoundingRegion *) &spD0)->GetPos((s32) &this->unk10);
        sp120 = spD0;
        sp128 = spD8;
        if ((Tools_Line2DToLine2DIntersect(arg0, arg1, *((MKVector3 *) &sp130), *((MKVector3 *) &sp120), &spC) != 0) && (spC < var_f30_473)) {
            var_f30_473 = spC;
            var_r27_470 = temp_r28_469 - 1;
        }
        if (var_r27_470 != -1) {
            temp_f0_549 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0);
            sp10 = temp_f0_549;
            spA0 = temp_f0_549;
            sp18 = arg1.unk8 - arg0.unk8;
            spA8 = (f64) sp18;
            spB0.operator*(var_f30_473);
            sp20 = M2C_FIELD(&arg0, f64 *, 0) + M2C_BITWISE(f64, spB0);
            M2C_FIELD(arg2, f64 *, 0) = sp20;
            sp28 = arg0.unk8 + spB0.unk8;
            spC0 = sp20;
            spC8 = (f64) sp28;
            M2C_FIELD(arg2, f64 *, 8) = (f64) sp28;
            sp60.GetPos((s32) &this->unk10);
            ((BoundingRegion *) &sp60.unk10)->GetPos((s32) &this->unk10);
            var_f4_587 = 0.0f;
            sp44 = 0.0f;
            sp40 = sp60.unk10 - M2C_BITWISE(f32, sp60);
            sp48 = sp60.unk18 - (f32) sp60.unk8;
            sp80 = (f64) sp40;
            sp88 = (f64) sp48;
            var_f5_606 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + ((*(f32 *) ((u8 *) &sp80 + 0x4)) * (*(f32 *) ((u8 *) &sp80 + 0x4))));
            if (var_f5_606 > 1e-12f) {
                if (var_f5_606 > 0.0f) {
                    temp_f1_611 = __frsqrte(var_f5_606);
                    temp_f1_617 = 0.5 * temp_f1_611 * -(((f64) var_f5_606 * (temp_f1_611 * temp_f1_611)) - 3.0);
                    temp_f1_621 = 0.5 * temp_f1_617 * -(((f64) var_f5_606 * (temp_f1_617 * temp_f1_617)) - 3.0);
                    var_f5_606 = (f32) ((f64) var_f5_606 * (0.5 * temp_f1_621 * -(((f64) var_f5_606 * (temp_f1_621 * temp_f1_621)) - 3.0)));
                } else if (var_f5_606 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_606 = __float_nan;
                } else {
                    sp8 = var_f5_606;
                    temp_r3_640 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_640) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_650 = 1;
                        } else {
                            var_r0_650 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_650 = 5;
                        } else {
                            var_r0_650 = 3;
                        }
                        break;
                    default:
                        var_r0_650 = 4;
                        break;
                    }
                    if (var_r0_650 == 1) {
                        var_f5_606 = __float_nan;
                    }
                }
                var_f4_587 = 1.0f / var_f5_606;
            }
            sp38 = (f32) sp88 * var_f4_587;
            sp30 = (f32) sp80 * var_f4_587;
            sp34 = (*(f32 *) ((u8 *) &sp80 + 0x4)) * var_f4_587;
            sp98 = (f64) sp38;
            sp90 = (f64) sp30;
            sp54 = (MKVector3::up.unk8 * (f32) sp90) - (MKVector3::up.unk0 * (f32) sp98);
            sp50 = (MKVector3::up.unk4 * (f32) sp98) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp90 + 0x4)));
            sp58 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp90 + 0x4))) - (MKVector3::up.unk4 * (f32) sp90);
            sp100.unk10 = (f64) sp50;
            sp100.unk18 = (f64) sp58;
            if ((u8) this->unk30 == 0) {
                sp100.unk10 = (f64) sp100.unk10 * 1.58735232e-314;
                sp100.unk18 *= -1.0f;
            }
            M2C_FIELD(arg3, f64 *, 0) = sp100.unk10;
            M2C_FIELD(arg3, f64 *, 8) = (f64) sp100.unk18;
            return 1;
        }
        goto block_33;
    }
block_33:
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyRegion::GetRegionPos() {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_748;
    f32 temp_f6_754;
    f32 temp_f7_760;
    void *temp_r5_745;

    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x31) != 0) {
        temp_r5_745 = M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 0x10), void **, 0x30);
        if (temp_r5_745 != NULL) {
            temp_f3_748 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 4);
            temp_f6_754 = *M2C_ERROR(/* Read from unset register $r4 */);
            temp_f7_760 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 8);
            sp8 = M2C_FIELD(temp_r5_745, f32 *, 0x30) + ((temp_f7_760 * M2C_FIELD(temp_r5_745, f32 *, 0x20)) + ((temp_f6_754 * M2C_FIELD(temp_r5_745, f32 *, 0)) + (temp_f3_748 * M2C_FIELD(temp_r5_745, f32 *, 0x10))));
            spC = M2C_FIELD(temp_r5_745, f32 *, 0x34) + ((temp_f7_760 * M2C_FIELD(temp_r5_745, f32 *, 0x24)) + ((temp_f6_754 * M2C_FIELD(temp_r5_745, f32 *, 4)) + (temp_f3_748 * M2C_FIELD(temp_r5_745, f32 *, 0x14))));
            sp10 = M2C_FIELD(temp_r5_745, f32 *, 0x38) + ((temp_f7_760 * M2C_FIELD(temp_r5_745, f32 *, 0x28)) + ((temp_f6_754 * M2C_FIELD(temp_r5_745, f32 *, 8)) + (temp_f3_748 * M2C_FIELD(temp_r5_745, f32 *, 0x18))));
            this->unk0 = (f64) sp8;
            this->unk8 = (f64) sp10;
            return;
        }
    }
    this->unk0 = *M2C_ERROR(/* Read from unset register $r4 */);
    this->unk8 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 8);
}
#endif

u8 EnemyRegion::IsPointWithin(const MKVector3 &arg0) {
    f32 temp_f1_806;
    f32 temp_f3_821;
    f32 temp_f4_818;
    f32 temp_f5_816;
    u8 var_r0_807;

    if ((u8) this->unk31 != 0) {
        return ((BoundingRegion *) &this->unk10)->IsPointWithin(arg0);
    }
    temp_f1_806 = this->unk2C;
    var_r0_807 = 0;
    if (temp_f1_806 > 0.0f) {
        temp_f5_816 = M2C_FIELD(this, f32 *, 4) - arg0.unk4;
        temp_f4_818 = M2C_FIELD(this, f32 *, 0) - arg0.unk0;
        temp_f3_821 = M2C_FIELD(this, f32 *, 8) - arg0.unk8;
        if (((temp_f3_821 * temp_f3_821) + ((temp_f4_818 * temp_f4_818) + (temp_f5_816 * temp_f5_816))) <= (temp_f1_806 * temp_f1_806)) {
            var_r0_807 = 1;
        }
    }
    return var_r0_807;
}

#if 0 // DRAFT: illegal explicit conversion from 'KDPathManager' to
s32 EnemyRegion::TryChangeRegion(const MKVector3 &arg0) {
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    KDPathIterator sp68;
    KDPathManager sp38;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_900;
    f32 temp_f6_906;
    f32 temp_f7_912;
    s32 temp_cr0_eq_857;
    void *temp_r3_891;

    sp68.Init();
    sp38.NearestPointLocalSegment(1, arg0);
    temp_cr0_eq_857 = (KDLocalPathSegment *) sp38 == NULL;
    sp68 = (KDLocalPathSegment *) sp38;
    sp68.unk4 = sp38.unk4;
    sp68.unk8 = M2C_BITWISE(u8, sp38.unk8);
    if ((temp_cr0_eq_857 == 0) && (temp_cr0_eq_857 == 0) && (((u8) this->unk31 == 0) || ((KDLocalPathSegment *) sp38 != (u32) this->unk10))) {
        sp74 = 0;
        sp78 = 0;
        sp7C = 0;
        sp80 = 0.0f;
        sp84 = 0.0f;
        sp88 = 0.0f;
        sp8C = 0.0f;
        ((BoundingRegion *) &sp74)->Init((KDLocalPathSegment *) sp38);
        if (((BoundingRegion *) &sp74)->IsPointWithin(arg0) != 0) {
            PolygonCentroid((KDPathSegment *) &sp28);
            temp_r3_891 = ((KDLocalPathSegment *) sp38)->unk30;
            sp38.unk20 = sp28;
            sp38.unk28 = sp30;
            sp38.unk10 = sp28;
            sp38.unk18 = sp30;
            if (temp_r3_891 != NULL) {
                temp_f3_900 = M2C_BITWISE(f32, sp38.unk14);
                temp_f6_906 = M2C_BITWISE(f32, sp38.unk10);
                temp_f7_912 = M2C_BITWISE(f32, sp38.unk18);
                sp8 = M2C_FIELD(temp_r3_891, f32 *, 0x30) + ((temp_f7_912 * M2C_FIELD(temp_r3_891, f32 *, 0x20)) + ((temp_f6_906 * M2C_FIELD(temp_r3_891, f32 *, 0)) + (temp_f3_900 * M2C_FIELD(temp_r3_891, f32 *, 0x10))));
                spC = M2C_FIELD(temp_r3_891, f32 *, 0x34) + ((temp_f7_912 * M2C_FIELD(temp_r3_891, f32 *, 0x24)) + ((temp_f6_906 * M2C_FIELD(temp_r3_891, f32 *, 4)) + (temp_f3_900 * M2C_FIELD(temp_r3_891, f32 *, 0x14))));
                sp10 = M2C_FIELD(temp_r3_891, f32 *, 0x38) + ((temp_f7_912 * M2C_FIELD(temp_r3_891, f32 *, 0x28)) + ((temp_f6_906 * M2C_FIELD(temp_r3_891, f32 *, 8)) + (temp_f3_900 * M2C_FIELD(temp_r3_891, f32 *, 0x18))));
                sp18 = (f64) sp8;
                sp20 = (f64) sp10;
                sp38.unk10 = (f64) sp8;
                sp38.unk18 = (f64) sp10;
            }
            if ((f32) fabs(M2C_BITWISE(f32, sp38.unk14) - arg0.unk4) < 500.0f) {
                SetupRegion((KDLocalPathSegment *) sp38);
                return 1;
            }
            goto block_9;
        }
    }
block_9:
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
void EnemyRegion::SetupRegion(KDLocalPathSegment *arg0) {
    f64 sp8;

    this->unk31 = 0;
    this->unk30 = 0;
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    this->unk2C = 0.0f;
    if (arg0 != NULL) {
        ((BoundingRegion *) &this->unk10)->Init(arg0);
        this->unk30 = PolygonWindingOrderIsClockWise((KDPathSegment *) arg0);
        PolygonCentroid((KDPathSegment *) &sp8);
        this->unk0 = sp8;
        this->unk8 = sp10;
        this->unk31 = 1;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDPathManager' to
void EnemyRegion::SetupRegion(const MKVector3 &arg0, float arg1) {
    KDPathIterator sp68;
    KDPathManager sp38;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_1059;
    f32 temp_f6_1065;
    f32 temp_f7_1071;
    s32 temp_cr0_eq_1033;
    void *temp_r3_1050;

    sp68.Init();
    sp38.NearestPointLocalSegment(1, arg0);
    sp68 = (s32) sp38;
    sp68.unk4 = sp38.unk4;
    sp68.unk8 = M2C_BITWISE(u8, sp38.unk8);
    this->unk31 = 0;
    this->unk30 = 0;
    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk8 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk2C = arg1;
    temp_cr0_eq_1033 = (KDLocalPathSegment *) sp68 == NULL;
    if ((temp_cr0_eq_1033 == 0) && (temp_cr0_eq_1033 == 0)) {
        ((BoundingRegion *) &this->unk10)->Init((KDLocalPathSegment *) sp68);
        if (((BoundingRegion *) &this->unk10)->IsPointWithin(arg0) != 0) {
            this->unk30 = PolygonWindingOrderIsClockWise((KDPathSegment *) (KDLocalPathSegment *) sp68);
            PolygonCentroid((KDPathSegment *) &sp28);
            temp_r3_1050 = ((KDLocalPathSegment *) sp68)->unk30;
            sp38.unk20 = sp28;
            sp38.unk28 = sp30;
            sp38.unk10 = sp28;
            sp38.unk18 = sp30;
            if (temp_r3_1050 != NULL) {
                temp_f3_1059 = M2C_BITWISE(f32, sp38.unk14);
                temp_f6_1065 = M2C_BITWISE(f32, sp38.unk10);
                temp_f7_1071 = M2C_BITWISE(f32, sp38.unk18);
                sp8 = M2C_FIELD(temp_r3_1050, f32 *, 0x30) + ((temp_f7_1071 * M2C_FIELD(temp_r3_1050, f32 *, 0x20)) + ((temp_f6_1065 * M2C_FIELD(temp_r3_1050, f32 *, 0)) + (temp_f3_1059 * M2C_FIELD(temp_r3_1050, f32 *, 0x10))));
                spC = M2C_FIELD(temp_r3_1050, f32 *, 0x34) + ((temp_f7_1071 * M2C_FIELD(temp_r3_1050, f32 *, 0x24)) + ((temp_f6_1065 * M2C_FIELD(temp_r3_1050, f32 *, 4)) + (temp_f3_1059 * M2C_FIELD(temp_r3_1050, f32 *, 0x14))));
                sp10 = M2C_FIELD(temp_r3_1050, f32 *, 0x38) + ((temp_f7_1071 * M2C_FIELD(temp_r3_1050, f32 *, 0x28)) + ((temp_f6_1065 * M2C_FIELD(temp_r3_1050, f32 *, 8)) + (temp_f3_1059 * M2C_FIELD(temp_r3_1050, f32 *, 0x18))));
                sp18 = (f64) sp8;
                sp20 = (f64) sp10;
                sp38.unk10 = (f64) sp8;
                sp38.unk18 = (f64) sp10;
            }
            if ((f32) fabs(M2C_BITWISE(f32, sp38.unk14) - arg0.unk4) < 500.0f) {
                this->unk31 = 1;
                this->unk0 = M2C_BITWISE(f64, sp38.unk20);
                this->unk8 = M2C_BITWISE(f64, sp38.unk28);
            }
        }
    }
}
#endif

void EnemyRegion::Deinit() {
    this->unk31 = 0;
}

void EnemyRegion::Init() {
    this->unk2C = 0.0f;
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    this->unk31 = 0;
    this->unk30 = 0;
}

#if 0 // DRAFT: illegal type
u8 PolygonWindingOrderIsClockWise(KDPathSegment *arg0) {
    f32 temp_f3_1186;
    f32 temp_f4_1185;
    f32 temp_f5_1183;
    s32 temp_r5_1145;
    s32 var_ctr_1148;
    void *temp_r3_1180;
    void *temp_r4_1174;

    temp_r5_1145 = arg0->unk20;
    var_ctr_1148 = temp_r5_1145;
    if (temp_r5_1145 > 0) {
        do {
            var_ctr_1148 -= 1;
        } while (var_ctr_1148 != 0);
    }
    temp_r4_1174 = arg0->unk24;
    temp_r3_1180 = temp_r4_1174 + ((temp_r5_1145 - 1) * arg0->unk1C);
    temp_f5_1183 = M2C_FIELD(temp_r3_1180, f32 *, 4) - M2C_FIELD(temp_r4_1174, f32 *, 4);
    temp_f4_1185 = M2C_FIELD(temp_r3_1180, f32 *, 0) - M2C_FIELD(temp_r4_1174, f32 *, 0);
    temp_f3_1186 = M2C_FIELD(temp_r3_1180, f32 *, 8) - M2C_FIELD(temp_r4_1174, f32 *, 8);
    if (((temp_f3_1186 * temp_f3_1186) + ((temp_f4_1185 * temp_f4_1185) + (temp_f5_1183 * temp_f5_1183))) > 625.0f) {

    }
    return (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU);
}
#endif

#if 0 // DRAFT: illegal type
void PolygonCentroid(KDPathSegment *arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;                                        /* compiler-managed */
    KDPathSegment *temp_r30_1217;
    f32 temp_f1_1220;
    f32 temp_f2_1249;
    f32 temp_f2_1283;
    f32 temp_f31_1301;
    f32 temp_f3_1284;
    f32 temp_f5_1254;
    f32 temp_f5_1275;
    f32 temp_f5_1292;
    f32 temp_f6_1274;
    f32 temp_f7_1246;
    f32 temp_f7_1272;
    f32 temp_f7_1285;
    f32 temp_f8_1244;
    f32 temp_f8_1286;
    f32 temp_f9_1250;
    f32 var_f0_1221;
    s32 temp_r0_1237;
    s32 temp_r3_1231;
    s32 temp_r4_1238;
    s32 temp_r5_1223;
    s32 temp_r7_1232;
    s32 var_ctr_1227;
    s32 var_r9_1222;
    void *temp_r3_1247;
    void *temp_r3_1269;
    void *temp_r4_1263;
    void *temp_r6_1242;
    void *temp_r8_1234;

    temp_r30_1217 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_f1_1220 = PolygonArea(temp_r30_1217);
    var_f0_1221 = 0.0f;
    var_r9_1222 = 0;
    temp_r5_1223 = temp_r30_1217->unk20;
    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    var_ctr_1227 = temp_r5_1223;
    if (temp_r5_1223 > 0) {
        do {
            temp_r3_1231 = var_r9_1222 + 1;
            temp_r7_1232 = temp_r30_1217->unk1C;
            temp_r8_1234 = temp_r30_1217->unk24;
            temp_r0_1237 = (temp_r3_1231 / temp_r5_1223) * temp_r5_1223;
            temp_r4_1238 = var_r9_1222 * temp_r7_1232;
            var_r9_1222 += 1;
            temp_r6_1242 = temp_r8_1234 + temp_r4_1238;
            temp_f8_1244 = M2C_FIELD(temp_r6_1242, f32 *, 8);
            temp_f7_1246 = M2C_FIELD(temp_r6_1242, f32 *, 0);
            temp_r3_1247 = temp_r8_1234 + ((temp_r3_1231 - temp_r0_1237) * temp_r7_1232);
            var_f0_1221 += *(temp_r8_1234 + (temp_r4_1238 + 4));
            temp_f2_1249 = M2C_FIELD(temp_r3_1247, f32 *, 0);
            temp_f9_1250 = M2C_FIELD(temp_r3_1247, f32 *, 8);
            temp_f5_1254 = (temp_f7_1246 * temp_f9_1250) - (temp_f2_1249 * temp_f8_1244);
            sp8 += (temp_f7_1246 + temp_f2_1249) * temp_f5_1254;
            sp10 += (temp_f8_1244 + temp_f9_1250) * temp_f5_1254;
            var_ctr_1227 -= 1;
        } while (var_ctr_1227 != 0);
    }
    temp_r4_1263 = temp_r30_1217->unk24;
    temp_r3_1269 = temp_r4_1263 + ((temp_r5_1223 - 1) * temp_r30_1217->unk1C);
    temp_f7_1272 = M2C_FIELD(temp_r3_1269, f32 *, 4) - M2C_FIELD(temp_r4_1263, f32 *, 4);
    temp_f6_1274 = M2C_FIELD(temp_r3_1269, f32 *, 0) - M2C_FIELD(temp_r4_1263, f32 *, 0);
    temp_f5_1275 = M2C_FIELD(temp_r3_1269, f32 *, 8) - M2C_FIELD(temp_r4_1263, f32 *, 8);
    if (((temp_f5_1275 * temp_f5_1275) + ((temp_f6_1274 * temp_f6_1274) + (temp_f7_1272 * temp_f7_1272))) > 625.0f) {
        temp_f2_1283 = M2C_FIELD(temp_r3_1269, f32 *, 8);
        temp_f3_1284 = M2C_FIELD(temp_r4_1263, f32 *, 0);
        temp_f7_1285 = M2C_FIELD(temp_r3_1269, f32 *, 0);
        temp_f8_1286 = M2C_FIELD(temp_r4_1263, f32 *, 8);
        temp_f5_1292 = (temp_f7_1285 * temp_f8_1286) - (temp_f3_1284 * temp_f2_1283);
        sp8 += (temp_f7_1285 + temp_f3_1284) * temp_f5_1292;
        sp10 += (temp_f2_1283 + temp_f8_1286) * temp_f5_1292;
    }
    temp_f31_1301 = 1.0f / (6.0f * temp_f1_1220);
    sp8 = (f64) sp8 * (f64) temp_f31_1301;
    sp10 *= temp_f31_1301;
    spC = var_f0_1221 / (f32) temp_r5_1223;
    arg0->unk0 = sp8;
    arg0->unk8 = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal type
f32 PolygonArea(KDPathSegment *arg0) {
    f32 temp_f4_1374;
    f32 temp_f5_1373;
    f32 temp_f6_1371;
    f32 var_f1_1335;
    s32 temp_r0_1345;
    s32 temp_r4_1346;
    s32 temp_r5_1333;
    s32 temp_r6_1341;
    s32 var_ctr_1336;
    s32 var_r8_1334;
    void *temp_r3_1368;
    void *temp_r4_1348;
    void *temp_r4_1352;
    void *temp_r4_1362;
    void *temp_r7_1343;

    temp_r5_1333 = arg0->unk20;
    var_r8_1334 = 0;
    var_f1_1335 = 0.0f;
    var_ctr_1336 = temp_r5_1333;
    if (temp_r5_1333 > 0) {
        do {
            temp_r6_1341 = arg0->unk1C;
            temp_r7_1343 = arg0->unk24;
            temp_r0_1345 = (var_r8_1334 + 1) % temp_r5_1333;
            temp_r4_1346 = var_r8_1334 * temp_r6_1341;
            var_r8_1334 += 1;
            temp_r4_1348 = temp_r7_1343 + temp_r4_1346;
            temp_r4_1352 = temp_r7_1343 + (temp_r0_1345 * temp_r6_1341);
            var_f1_1335 = -((M2C_FIELD(temp_r4_1348, f32 *, 8) * M2C_FIELD(temp_r4_1352, f32 *, 0)) - (var_f1_1335 + (M2C_FIELD(temp_r4_1348, f32 *, 0) * M2C_FIELD(temp_r4_1352, f32 *, 8))));
            var_ctr_1336 -= 1;
        } while (var_ctr_1336 != 0);
    }
    temp_r4_1362 = arg0->unk24;
    temp_r3_1368 = temp_r4_1362 + ((temp_r5_1333 - 1) * arg0->unk1C);
    temp_f6_1371 = M2C_FIELD(temp_r3_1368, f32 *, 4) - M2C_FIELD(temp_r4_1362, f32 *, 4);
    temp_f5_1373 = M2C_FIELD(temp_r3_1368, f32 *, 0) - M2C_FIELD(temp_r4_1362, f32 *, 0);
    temp_f4_1374 = M2C_FIELD(temp_r3_1368, f32 *, 8) - M2C_FIELD(temp_r4_1362, f32 *, 8);
    if (((temp_f4_1374 * temp_f4_1374) + ((temp_f5_1373 * temp_f5_1373) + (temp_f6_1371 * temp_f6_1371))) > 625.0f) {
        var_f1_1335 = -((M2C_FIELD(temp_r3_1368, f32 *, 8) * M2C_FIELD(temp_r4_1362, f32 *, 0)) - ((M2C_FIELD(temp_r3_1368, f32 *, 0) * M2C_FIELD(temp_r4_1362, f32 *, 8)) + var_f1_1335));
    }
    return var_f1_1335 * 0.5f;
}
#endif

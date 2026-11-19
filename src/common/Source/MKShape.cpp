#include "common/Source/MKShape.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKPrimitive_GC.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

void MKShape_DrawLine(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, const MKVector4 &arg3, const Matrix &arg4) {
    u8 var_r0_34;

    MKPrimitive(0x109, 3);
    MKSetMatrix(arg4);
    MKBegin(2);
    MKSetColorV(arg2);
    MKSetPositionV(arg0);
    var_r0_34 = 0;
    if ((arg3.unk0 == MKVector4::one.unk0) && (arg3.unk4 == MKVector4::one.unk4) && (arg3.unk8 == MKVector4::one.unk8) && (arg3.unkC == MKVector4::one.unkC)) {
        var_r0_34 = 1;
    }
    if (var_r0_34 != 0) {
        MKSetColorV(arg2);
    } else {
        MKSetColorV(arg3);
    }
    MKSetPositionV(arg1);
    MKEnd();
    MKEndPrimitive();
}

void MKShape_DrawSprite(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2) {
    MKPrimitive(0xC, 0);
    MKBegin(4);
    MKSetColorV(arg2);
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionV(arg0);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionV(arg1);
    MKEnd();
    MKEndPrimitive();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void MKShape_DrawPlane(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3, const Matrix &arg4, bool arg5) {
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    Matrix spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f29_271;
    f32 temp_f30_291;
    f32 temp_f5_159;
    f32 temp_f6_158;
    f32 temp_f6_186;
    f32 temp_f7_155;
    f32 var_f29_240;
    f32 var_f29_312;
    s32 var_r31_248;
    s32 var_r31_317;

    M2C_STRUCT_COPY((s32) &sp90.unkC + 4, (s32) (&arg4 - 4) + 4, 0x40);
    sp48 = 0.0f;
    temp_f7_155 = arg1.unk0;
    sp40 = 13.67f;
    temp_f6_158 = arg1.unk4;
    temp_f5_159 = arg1.unk8;
    sp44 = 3.72f;
    sp78 = (f64) sp48;
    sp70 = (f64) sp40;
    spF0 = temp_f7_155;
    spF4 = temp_f6_158;
    spF8 = temp_f5_159;
    sp38 = ((f32) sp70 * temp_f6_158) - ((*(f32 *) ((u8 *) &sp70 + 0x4)) * temp_f7_155);
    sp30 = ((*(f32 *) ((u8 *) &sp70 + 0x4)) * temp_f5_159) - ((f32) sp78 * temp_f6_158);
    sp34 = ((f32) sp78 * temp_f7_155) - ((f32) sp70 * temp_f5_159);
    spFC = 0.0f;
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    sp90 = Normalise(*((MKVector3 *) &sp80));
    temp_f6_186 = M2C_BITWISE(f32, sp90);
    sp100 = temp_f6_186;
    sp104 = sp90.unk4;
    sp28 = (spF0 * sp90.unk4) - (spF4 * temp_f6_186);
    sp20 = (spF4 * sp90.unk8) - (spF8 * sp90.unk4);
    sp24 = (spF8 * temp_f6_186) - (spF0 * sp90.unk8);
    sp108 = sp90.unk8;
    sp10C = 0.0f;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    sp60 = Normalise(*((MKVector3 *) &sp50));
    spEC = 0.0f;
    sp11C = 1.0f;
    spE0 = M2C_BITWISE(f32, sp60);
    spE4 = sp60.unk4;
    spE8 = sp60.unk8;
    sp110 = arg0.unk0;
    sp114 = arg0.unk4;
    sp118 = arg0.unk8;
    sp10C = 0.0f;
    spFC = 0.0f;
    spEC = 0.0f;
    sp11C = 1.0f;
    spA0.Multiply((Matrix *) &spE0, &spA0);
    var_f29_240 = -0.5235988f;
    MKPrimitive(0x109, 3);
    MKSetMatrix(spA0);
    MKBegin(0x1E);
    MKSetColorV(arg3);
    var_r31_248 = 0;
    do {
        MKSetPositionF(0.0f, 0.0f, 0.0f);
        _table_sincosf(var_f29_240, sp1C, sp18);
        MKSetPositionF(sp1C * arg2, 0.0f, sp18 * arg2);
        var_r31_248 += 1;
        var_f29_240 += 0.5235988f;
    } while (var_r31_248 < 0xC);
    temp_f29_271 = 0.25f * arg2;
    MKSetColorF(1.0f, 1.0f, 0.0f, arg3.unkC);
    MKSetPositionF(0.0f, 0.0f, 0.0f);
    MKSetPositionF(0.0f, temp_f29_271, 0.0f);
    MKSetPositionF(0.0f, temp_f29_271, 0.0f);
    temp_f30_291 = -((0.25f * temp_f29_271) - temp_f29_271);
    MKSetPositionF(0.15f * -temp_f29_271, temp_f30_291, 0.0f);
    MKSetPositionF(0.0f, temp_f29_271, 0.0f);
    MKSetPositionF(0.15f * temp_f29_271, temp_f30_291, 0.0f);
    MKEnd();
    MKEndPrimitive();
    MKPrimitive(0x10A, 3);
    MKSetMatrix(spA0);
    var_f29_312 = 0.0f;
    MKBegin(0xD);
    MKSetColorV(arg3);
    var_r31_317 = 0;
    do {
        _table_sincosf(var_f29_312, sp14, sp10);
        MKSetPositionF(sp14 * arg2, 0.0f, sp10 * arg2);
        var_r31_317 += 1;
        var_f29_312 += 0.5235988f;
    } while (var_r31_317 < 0xD);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void MKShape_DrawCapsule(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, int arg3, int arg4, const MKVector4 &arg5, const Matrix &arg6, bool arg7) {
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    Matrix spD0;
    M2C_UNK spCC;
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f0_852;
    f32 temp_f10_539;
    f32 temp_f12_537;
    f32 temp_f14_1017;
    f32 temp_f14_1032;
    f32 temp_f14_1075;
    f32 temp_f14_1100;
    f32 temp_f14_1307;
    f32 temp_f14_675;
    f32 temp_f14_699;
    f32 temp_f14_733;
    f32 temp_f14_753;
    f32 temp_f14_774;
    f32 temp_f14_828;
    f32 temp_f14_914;
    f32 temp_f14_950;
    f32 temp_f14_996;
    f32 temp_f15_672;
    f32 temp_f15_697;
    f32 temp_f15_731;
    f32 temp_f15_887;
    f32 temp_f15_902;
    f32 temp_f15_977;
    f32 temp_f16_1079;
    f32 temp_f16_1118;
    f32 temp_f16_1218;
    f32 temp_f16_756;
    f32 temp_f16_942;
    f32 temp_f17_1049;
    f32 temp_f17_1119;
    f32 temp_f17_747;
    f32 temp_f18_1047;
    f32 temp_f18_1147;
    f32 temp_f18_1168;
    f32 temp_f18_974;
    f32 temp_f19_1210;
    f32 temp_f19_671;
    f32 temp_f19_725;
    f32 temp_f19_873;
    f32 temp_f20_1085;
    f32 temp_f20_1240;
    f32 temp_f20_1253;
    f32 temp_f22_1153;
    f32 temp_f22_667;
    f32 temp_f22_896;
    f32 temp_f23_899;
    f32 temp_f24_666;
    f32 temp_f24_861;
    f32 temp_f25_860;
    f32 temp_f26_642;
    f32 temp_f27_1235;
    f32 temp_f27_892;
    f32 temp_f28_1232;
    f32 temp_f30_1143;
    f32 temp_f5_514;
    f32 temp_f6_512;
    f32 temp_f6_570;
    f32 temp_f7_511;
    f32 temp_f8_535;
    f32 var_f16_625;
    f32 var_f16_818;
    f32 var_f17_1213;
    f32 var_f17_630;
    f32 var_f17_804;
    f32 var_f18_1195;
    f32 var_f18_641;
    f32 var_f19_758;
    f32 var_f20_1116;
    f32 var_f20_748;
    f32 var_f22_744;
    f32 var_f23_628;
    f32 var_f23_874;
    f32 var_f28_870;
    f32 var_f29_879;
    f32 var_f30_1003;
    f32 var_f30_897;
    f32 var_f30_928;
    f32 var_f31_435;
    f32 var_f3_502;
    f64 temp_f1_441;
    f64 temp_f1_447;
    f64 temp_f1_451;
    f64 temp_f1_867;
    s32 temp_r21_1205;
    s32 temp_r21_810;
    s32 temp_r23_659;
    s32 temp_r26_405;
    s32 temp_r30_875;
    s32 temp_r3_470;
    s32 var_r0_480;
    s32 var_r21_1007;
    s32 var_r21_1061;
    s32 var_r21_1129;
    s32 var_r21_658;
    s32 var_r21_767;
    s32 var_r21_932;
    s32 var_r22_1193;
    s32 var_r22_660;
    s32 var_r23_1219;
    s32 var_r23_797;
    s32 var_r26_823;
    s32 var_r29_661;
    s32 var_r29_746;
    s32 var_r29_880;

    temp_r26_405 = arg4 + (1 - (arg4 & 1));
    M2C_STRUCT_COPY((s32) &spCC + 4, (s32) (&arg6 - 4) + 4, 0x40);
    sp48 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0);
    spB8 = sp48;
    sp50 = arg1.unk8 - arg0.unk8;
    spC0 = (f64) sp50;
    var_f31_435 = ((f32) spC0 * (f32) spC0) + (((f32) spB8 * (f32) spB8) + ((*(f32 *) ((u8 *) &spB0 + 0xc)) * (*(f32 *) ((u8 *) &spB0 + 0xc))));
    if (var_f31_435 > 0.000001f) {
        if (var_f31_435 > 0.0f) {
            temp_f1_441 = __frsqrte(var_f31_435);
            temp_f1_447 = 0.5 * temp_f1_441 * -(((f64) var_f31_435 * (temp_f1_441 * temp_f1_441)) - 3.0);
            temp_f1_451 = 0.5 * temp_f1_447 * -(((f64) var_f31_435 * (temp_f1_447 * temp_f1_447)) - 3.0);
            var_f31_435 = (f32) ((f64) var_f31_435 * (0.5 * temp_f1_451 * -(((f64) var_f31_435 * (temp_f1_451 * temp_f1_451)) - 3.0)));
        } else if (var_f31_435 < M2C_BITWISE(f32, 0.0)) {
            var_f31_435 = __float_nan;
        } else {
            sp10 = var_f31_435;
            temp_r3_470 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_470) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_480 = 1;
                } else {
                    var_r0_480 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_480 = 5;
                } else {
                    var_r0_480 = 3;
                }
                break;
            default:
                var_r0_480 = 4;
                break;
            }
            if (var_r0_480 == 1) {
                var_f31_435 = __float_nan;
            }
        }
        var_f3_502 = 1.0f / var_f31_435;
    } else {
        var_f3_502 = 0.0f;
        var_f31_435 = 0.0f;
    }
    temp_f7_511 = (f32) spB8 * var_f3_502;
    temp_f6_512 = (*(f32 *) ((u8 *) &spB0 + 0xc)) * var_f3_502;
    temp_f5_514 = (f32) spC0 * var_f3_502;
    spB8 = temp_f7_511;
    (*(f32 *) ((u8 *) &spB0 + 0xc)) = temp_f6_512;
    spC0 = temp_f5_514;
    if (var_f31_435 < 0.1f) {
        spB0 = (f64) M2C_FIELD(&arg0, f32 *, 8);
        spA8 = M2C_FIELD(&arg0, f64 *, 0);
        (*(f32 *) ((u8 *) &spB0 + 0x4)) = arg2;
        MKShape_DrawSphere(*((MKVector4 *) &spA8), arg3, temp_r26_405, arg5, arg6, arg7);
        return;
    }
    temp_f8_535 = (f32) temp_f5_514;
    temp_f12_537 = (f32) temp_f6_512;
    temp_f10_539 = (f32) temp_f7_511;
    sp40 = 0.0f;
    sp38 = 13.67f;
    sp3C = 3.72f;
    sp80 = (f64) sp40;
    sp78 = (f64) sp38;
    sp120 = temp_f7_511;
    sp124 = temp_f6_512;
    sp128 = temp_f5_514;
    sp30 = ((f32) sp78 * temp_f12_537) - ((*(f32 *) ((u8 *) &sp78 + 0x4)) * temp_f10_539);
    sp28 = ((*(f32 *) ((u8 *) &sp78 + 0x4)) * temp_f8_535) - ((f32) sp80 * temp_f12_537);
    sp2C = ((f32) sp80 * temp_f10_539) - ((f32) sp78 * temp_f8_535);
    sp12C = 0.0f;
    sp88 = (f64) sp28;
    sp90 = (f64) sp30;
    sp98 = Normalise(*((MKVector3 *) &sp88));
    temp_f6_570 = M2C_BITWISE(f32, sp98);
    sp130 = temp_f6_570;
    sp134 = sp98.unk4;
    sp20 = (sp120 * sp98.unk4) - (sp124 * temp_f6_570);
    sp18 = (sp124 * sp98.unk8) - (sp128 * sp98.unk4);
    sp1C = (sp128 * temp_f6_570) - (sp120 * sp98.unk8);
    sp138 = sp98.unk8;
    sp13C = 0.0f;
    sp58 = (f64) sp18;
    sp60 = (f64) sp20;
    sp68 = Normalise(*((MKVector3 *) &sp58));
    sp11C = 0.0f;
    sp14C = 1.0f;
    sp110 = M2C_BITWISE(f32, sp68);
    sp114 = sp68.unk4;
    sp118 = sp68.unk8;
    sp140 = arg0.unk0;
    sp144 = arg0.unk4;
    sp148 = arg0.unk8;
    sp13C = 0.0f;
    sp12C = 0.0f;
    sp11C = 0.0f;
    sp14C = 1.0f;
    spD0.Multiply((Matrix *) &sp110, &spD0);
    var_f16_625 = 0.0f;
    var_f23_628 = var_f31_435;
    var_f17_630 = 0.0f;
    var_f18_641 = 3.1415927f / (1.0f + (f32) temp_r26_405);
    temp_f26_642 = 6.2831855f / (f32) arg3;
    if (arg7 != 0) {
        MKPrimitive(0x10A, 3);
        MKSetMatrix(spD0);
        MKBegin((arg3 * (temp_r26_405 + 2)) + 1);
        MKSetColorV(arg5);
        var_r21_658 = 0;
        temp_r23_659 = (s32) (temp_r26_405 + 1) / 2;
        var_r22_660 = 0;
        var_r29_661 = 1;
loop_29:
        if (var_r22_660 < arg3) {
            temp_f24_666 = 1.5707964f + var_f16_625;
            temp_f22_667 = _table_sinf(var_f17_630);
            temp_f19_671 = 1.5707964f + var_f17_630;
            temp_f15_672 = temp_f22_667 * (arg2 * _table_sinf(temp_f24_666));
            temp_f14_675 = (arg2 * _table_sinf(temp_f19_671)) + var_f23_628;
            MKSetPositionF(temp_f22_667 * (arg2 * _table_sinf(var_f16_625)), temp_f14_675, temp_f15_672);
            if (var_r21_658 == temp_r23_659) {
                var_f23_628 = -((var_f31_435 * (f32) var_r29_661) - var_f23_628);
                temp_f15_697 = temp_f22_667 * (arg2 * _table_sinf(temp_f24_666));
                temp_f14_699 = (arg2 * _table_sinf(temp_f19_671)) + var_f23_628;
                MKSetPositionF(temp_f22_667 * (arg2 * _table_sinf(var_f16_625)), temp_f14_699, temp_f15_697);
            }
            var_f17_630 += var_f18_641;
            var_r21_658 += var_r29_661;
            if ((var_r21_658 == 0) || (var_r21_658 == (s32) (temp_r26_405 + 1))) {
                var_f18_641 = -var_f18_641;
                var_r29_661 = -var_r29_661;
                var_f16_625 += temp_f26_642;
                var_r22_660 += 1;
            }
            goto loop_29;
        }
        temp_f19_725 = _table_sinf(var_f17_630);
        temp_f15_731 = temp_f19_725 * (arg2 * _table_sinf(1.5707964f + var_f16_625));
        temp_f14_733 = (arg2 * _table_sinf(1.5707964f + var_f17_630)) + var_f23_628;
        MKSetPositionF(temp_f19_725 * (arg2 * _table_sinf(var_f16_625)), temp_f14_733, temp_f15_731);
        MKEnd();
        var_f22_744 = var_f31_435;
        var_r29_746 = 0;
        temp_f17_747 = (f32) fabs(var_f18_641);
        var_f20_748 = temp_f17_747;
loop_37:
        if (var_r29_746 < temp_r26_405) {
            temp_f14_753 = arg2 * _table_sinf(1.5707964f + var_f20_748);
            temp_f16_756 = _table_sinf(var_f20_748);
            var_f19_758 = 0.0f;
            if (var_r29_746 == temp_r23_659) {
                var_f22_744 -= var_f31_435;
            }
            MKBegin(arg3 + 1);
            MKSetColorV(arg5);
            var_r21_767 = 0;
loop_35:
            if (var_r21_767 < (s32) (arg3 + 1)) {
                temp_f14_774 = temp_f16_756 * (arg2 * _table_sinf(1.5707964f + var_f19_758));
                MKSetPositionF(temp_f16_756 * (arg2 * _table_sinf(var_f19_758)), temp_f14_753 + var_f22_744, temp_f14_774);
                var_f19_758 += temp_f26_642;
                var_r21_767 += 1;
                goto loop_35;
            }
            MKEnd();
            var_f20_748 += temp_f17_747;
            var_r29_746 += 1;
            goto loop_37;
        }
        var_r23_797 = 0;
        var_f17_804 = 0.0f;
        temp_r21_810 = (s32) (var_f31_435 / ((2.0f * arg2) / (f32) temp_r26_405));
loop_43:
        if (var_r23_797 < temp_r21_810) {
            var_f16_818 = 0.0f;
            MKBegin(arg3 + 1);
            MKSetColorV(arg5);
            var_r26_823 = 0;
loop_41:
            if (var_r26_823 < (s32) (arg3 + 1)) {
                temp_f14_828 = arg2 * _table_sinf(1.5707964f + var_f16_818);
                MKSetPositionF(arg2 * _table_sinf(var_f16_818), var_f17_804, temp_f14_828);
                var_f16_818 += temp_f26_642;
                var_r26_823 += 1;
                goto loop_41;
            }
            MKEnd();
            var_f17_804 += var_f31_435 / (f32) temp_r21_810;
            var_r23_797 += 1;
            goto loop_43;
        }
    } else {
        temp_f0_852 = 2.0f * arg2;
        sp170 = temp_f0_852;
        temp_f25_860 = 1.0f / (f32) arg3;
        temp_f24_861 = -(1.0f / (var_f31_435 + (f32) temp_f0_852));
        MKPrimitive(4, 0);
        MKSetMatrix(spD0);
        temp_f1_867 = fabs(var_f18_641);
        var_f28_870 = var_f31_435;
        sp178 = arg2 + var_f31_435;
        temp_f19_873 = (f32) temp_f1_867;
        var_f23_874 = 0.0f;
        temp_r30_875 = (arg3 + 1) * 2;
        sp174 = -arg2;
        var_f29_879 = temp_f19_873;
        var_r29_880 = 0;
        sp180 = 5.287201034e-315;
loop_65:
        if (var_r29_880 <= temp_r26_405) {
            temp_f15_887 = arg2 * _table_sinf((f32) sp180 + var_f29_879);
            temp_f27_892 = _table_sinf(var_f29_879);
            temp_f22_896 = arg2 * _table_sinf((f32) sp180 + (var_f29_879 - temp_f19_873));
            var_f30_897 = 0.0f;
            if (var_r29_880 == 0) {
                temp_f23_899 = temp_f15_887 + var_f28_870;
                temp_f15_902 = temp_f24_861 * (arg2 + temp_f23_899);
                MKBegin(temp_r30_875);
                MKSetColorV(arg5);
                MKSetTexCoord1F(0.0f, temp_f15_902);
                temp_f14_914 = -(temp_f27_892 * (arg2 * _table_sinf(1.5707964f)));
                MKSetPositionF(temp_f27_892 * (arg2 * _table_sinf(0.0f)), temp_f23_899, temp_f14_914);
                MKSetTexCoord1F(0.0f, -1.0f);
                MKSetPositionF(0.0f, sp178, 0.0f);
                var_f30_928 = 0.0f + temp_f26_642;
                var_r21_932 = 1;
loop_49:
                if (var_r21_932 < (s32) (arg3 + 1)) {
                    temp_f16_942 = temp_f25_860 * (f32) var_r21_932;
                    MKSetTexCoord1F(temp_f16_942, temp_f15_902);
                    temp_f14_950 = -(temp_f27_892 * (arg2 * _table_sinf(1.5707964f + var_f30_928)));
                    MKSetPositionF(temp_f27_892 * (arg2 * _table_sinf(var_f30_928)), temp_f23_899, temp_f14_950);
                    MKSetTexCoord1F(temp_f16_942, -1.0f);
                    MKSetPositionF(temp_f16_942, sp178, 0.0f);
                    var_f30_928 += temp_f26_642;
                    var_r21_932 += 1;
                    goto loop_49;
                }
                MKEnd();
            } else if (var_r29_880 == temp_r26_405) {
                temp_f18_974 = temp_f22_896 + var_f28_870;
                temp_f15_977 = temp_f24_861 * (arg2 + temp_f18_974);
                MKBegin(temp_r30_875);
                MKSetColorV(arg5);
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionF(0.0f, sp174, 0.0f);
                MKSetTexCoord1F(0.0f, temp_f15_977);
                temp_f14_996 = -(var_f23_874 * (arg2 * _table_sinf(1.5707964f)));
                MKSetPositionF(var_f23_874 * (arg2 * _table_sinf(0.0f)), temp_f18_974, temp_f14_996);
                var_f30_1003 = 0.0f + temp_f26_642;
                var_r21_1007 = 1;
loop_54:
                if (var_r21_1007 < (s32) (arg3 + 1)) {
                    temp_f14_1017 = temp_f25_860 * (f32) var_r21_1007;
                    MKSetTexCoord1F(temp_f14_1017, 0.0f);
                    MKSetPositionF(0.0f, sp174, 0.0f);
                    MKSetTexCoord1F(temp_f14_1017, temp_f15_977);
                    temp_f14_1032 = -(var_f23_874 * (arg2 * _table_sinf(1.5707964f + var_f30_1003)));
                    MKSetPositionF(var_f23_874 * (arg2 * _table_sinf(var_f30_1003)), temp_f18_974, temp_f14_1032);
                    var_f30_1003 += temp_f26_642;
                    var_r21_1007 += 1;
                    goto loop_54;
                }
                MKEnd();
            } else {
                temp_f18_1047 = temp_f15_887 + var_f28_870;
                temp_f17_1049 = temp_f22_896 + var_f28_870;
                sp16C = temp_f24_861 * (arg2 + temp_f18_1047);
                sp168 = temp_f24_861 * (arg2 + temp_f17_1049);
                MKBegin(temp_r30_875);
                MKSetColorV(arg5);
                var_r21_1061 = 0;
                sp188 = 4503601774854144.0;
                sp190 = 5.287201034e-315;
loop_58:
                if (var_r21_1061 < (s32) (arg3 + 1)) {
                    temp_f14_1075 = temp_f25_860 * (f32) var_r21_1061;
                    MKSetTexCoord1F(temp_f14_1075, sp16C);
                    temp_f16_1079 = (f32) sp190 + var_f30_897;
                    temp_f20_1085 = -(temp_f27_892 * (arg2 * _table_sinf(temp_f16_1079)));
                    MKSetPositionF(temp_f27_892 * (arg2 * _table_sinf(var_f30_897)), temp_f18_1047, temp_f20_1085);
                    MKSetTexCoord1F(temp_f14_1075, sp168);
                    temp_f14_1100 = -(var_f23_874 * (arg2 * _table_sinf(temp_f16_1079)));
                    MKSetPositionF(var_f23_874 * (arg2 * _table_sinf(var_f30_897)), temp_f17_1049, temp_f14_1100);
                    var_f30_897 += temp_f26_642;
                    var_r21_1061 += 1;
                    goto loop_58;
                }
                MKEnd();
                if (var_r29_880 == (s32) ((s32) (temp_r26_405 + 1) / 2)) {
                    var_f28_870 -= var_f31_435;
                    var_f20_1116 = 0.0f;
                    temp_f16_1118 = temp_f15_887 + var_f28_870;
                    temp_f17_1119 = temp_f22_896 + var_f28_870;
                    MKBegin(temp_r30_875);
                    MKSetColorV(arg5);
                    var_r21_1129 = 0;
                    sp198 = 4503601774854144.0;
                    sp1A0 = 5.287201034e-315;
loop_62:
                    if (var_r21_1129 < (s32) (arg3 + 1)) {
                        temp_f30_1143 = temp_f25_860 * (f32) var_r21_1129;
                        MKSetTexCoord1F(temp_f30_1143, temp_f24_861 * (arg2 + temp_f16_1118));
                        temp_f18_1147 = (f32) sp1A0 + var_f20_1116;
                        temp_f22_1153 = -(temp_f27_892 * (arg2 * _table_sinf(temp_f18_1147)));
                        MKSetPositionF(temp_f27_892 * (arg2 * _table_sinf(var_f20_1116)), temp_f16_1118, temp_f22_1153);
                        MKSetTexCoord1F(temp_f30_1143, temp_f24_861 * (arg2 + temp_f17_1119));
                        temp_f18_1168 = -(var_f23_874 * (arg2 * _table_sinf(temp_f18_1147)));
                        MKSetPositionF(var_f23_874 * (arg2 * _table_sinf(var_f20_1116)), temp_f17_1119, temp_f18_1168);
                        var_f20_1116 += temp_f26_642;
                        var_r21_1129 += 1;
                        goto loop_62;
                    }
                    MKEnd();
                }
            }
            var_f23_874 = temp_f27_892;
            var_r29_880 += 1;
            var_f29_879 += temp_f19_873;
            goto loop_65;
        }
        var_r22_1193 = 0;
        var_f18_1195 = 0.0f;
        temp_r21_1205 = (s32) (var_f31_435 / (sp170 / (f32) temp_r26_405));
        temp_f19_1210 = var_f31_435 / (f32) temp_r21_1205;
loop_71:
        if (var_r22_1193 < temp_r21_1205) {
            var_f17_1213 = 0.0f;
            MKBegin(temp_r30_875);
            MKSetColorV(arg5);
            temp_f16_1218 = var_f18_1195 + temp_f19_1210;
            var_r23_1219 = 0;
loop_69:
            if (var_r23_1219 < (s32) (arg3 + 1)) {
                temp_f28_1232 = temp_f25_860 * (f32) var_r23_1219;
                MKSetTexCoord1F(temp_f28_1232, temp_f24_861 * (var_f18_1195 + arg2));
                temp_f27_1235 = 1.5707964f + var_f17_1213;
                temp_f20_1240 = -(arg2 * _table_sinf(temp_f27_1235));
                MKSetPositionF(arg2 * _table_sinf(var_f17_1213), var_f18_1195, temp_f20_1240);
                MKSetTexCoord1F(temp_f28_1232, temp_f24_861 * (arg2 + temp_f16_1218));
                temp_f20_1253 = -(arg2 * _table_sinf(temp_f27_1235));
                MKSetPositionF(arg2 * _table_sinf(var_f17_1213), temp_f16_1218, temp_f20_1253);
                var_f17_1213 += temp_f26_642;
                var_r23_1219 += 1;
                goto loop_69;
            }
            MKEnd();
            var_f18_1195 += temp_f19_1210;
            var_r22_1193 += 1;
            goto loop_71;
        }
        MKEndPrimitive();
    }
    M2C_STRUCT_COPY((s32) &spCC + 4, (s32) (&arg6 - 4) + 4, 0x40);
    ((Matrix *) &sp110)->SetIdentity();
    sp140 = arg0.unk0;
    sp144 = arg0.unk4;
    sp148 = arg0.unk8;
    sp14C = 1.0f;
    spD0.Multiply((Matrix *) &sp110, &spD0);
    MKSetMatrix(spD0);
    MKBegin(2);
    MKSetColorF(0.0f, 1.0f, 0.0f, 1.0f);
    temp_f14_1307 = 0.5f * arg2;
    MKSetPositionF(0.0f, temp_f14_1307, 0.0f);
    MKSetPositionF(0.0f, 0.0f, 0.0f);
    MKEnd();
    MKBegin(2);
    MKSetColorF(1.0f, 0.0f, 0.0f, 1.0f);
    MKSetPositionF(0.0f, 0.0f, 0.0f);
    MKSetPositionF(temp_f14_1307, 0.0f, 0.0f);
    MKEnd();
    MKBegin(2);
    MKSetColorF(0.0f, 0.0f, 1.0f, 1.0f);
    MKSetPositionF(0.0f, 0.0f, 0.0f);
    MKSetPositionF(0.0f, 0.0f, temp_f14_1307);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
void MKShape_DrawSphere(const MKVector4 &arg0, int arg1, int arg2, const MKVector4 &arg3, const Matrix &arg4, bool arg5) {
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f24_1455;
    f32 temp_f24_1520;
    f32 temp_f24_1589;
    f32 temp_f24_1632;
    f32 temp_f24_1668;
    f32 temp_f25_1461;
    f32 temp_f25_1526;
    f32 temp_f25_1594;
    f32 temp_f25_1637;
    f32 temp_f25_1670;
    f32 temp_f26_1459;
    f32 temp_f26_1523;
    f32 temp_f26_1593;
    f32 temp_f26_1636;
    f32 temp_f26_1672;
    f32 temp_f27_1457;
    f32 temp_f27_1521;
    f32 temp_f27_1591;
    f32 temp_f27_1634;
    f32 temp_f27_1674;
    f32 temp_f28_1525;
    f32 temp_f29_1442;
    f32 temp_f6_1504;
    f32 var_f28_1441;
    f32 var_f30_1428;
    f32 var_f30_1527;
    f32 var_f30_1666;
    f32 var_f31_1423;
    f32 var_f31_1534;
    s32 var_r25_1460;
    s32 var_r25_1539;
    s32 var_r25_1675;
    s32 var_r26_1456;
    s32 var_r26_1524;
    s32 var_r26_1592;
    s32 var_r26_1635;
    s32 var_r27_1458;
    s32 var_r30_1690;

    var_f31_1423 = 0.0f;
    var_f30_1428 = 0.0f;
    var_f28_1441 = 3.1415927f / (1.0f + (f32) arg2);
    temp_f29_1442 = 6.2831855f / (f32) arg1;
    if (arg5 != 0) {
        MKPrimitive(0x10A, 3);
        MKSetMatrix(arg4);
        MKBegin((arg1 * (arg2 + 1)) + 1);
        MKSetColorV(arg3);
        temp_f24_1455 = arg0.unkC;
        var_r26_1456 = 0;
        temp_f27_1457 = arg0.unk0;
        var_r27_1458 = 0;
        temp_f26_1459 = arg0.unk4;
        var_r25_1460 = 1;
        temp_f25_1461 = arg0.unk8;
loop_5:
        if (var_r27_1458 < arg1) {
            _table_sincosf(var_f30_1428, sp1C, sp18);
            _table_sincosf(var_f31_1423, spC, sp8);
            MKSetPositionF((sp1C * (spC * temp_f24_1455)) + temp_f27_1457, (sp18 * temp_f24_1455) + temp_f26_1459, (sp1C * (sp8 * temp_f24_1455)) + temp_f25_1461);
            var_f30_1428 += var_f28_1441;
            var_r26_1456 += var_r25_1460;
            if ((var_r26_1456 == 0) || (var_r26_1456 == (s32) (arg2 + 1))) {
                var_f28_1441 = -var_f28_1441;
                var_r25_1460 = -var_r25_1460;
                var_f31_1423 += temp_f29_1442;
                var_r27_1458 += 1;
            }
            goto loop_5;
        }
        _table_sincosf(var_f30_1428, sp1C, sp18);
        _table_sincosf(var_f31_1423, spC, sp8);
        temp_f6_1504 = arg0.unkC;
        MKSetPositionF((sp1C * (spC * temp_f6_1504)) + arg0.unk0, (sp18 * temp_f6_1504) + arg0.unk4, (sp1C * (sp8 * temp_f6_1504)) + arg0.unk8);
        MKEnd();
        temp_f24_1520 = arg0.unkC;
        temp_f27_1521 = arg0.unk0;
        temp_f26_1523 = arg0.unk4;
        var_r26_1524 = 0;
        temp_f28_1525 = (f32) fabs(var_f28_1441);
        temp_f25_1526 = arg0.unk8;
        var_f30_1527 = temp_f28_1525;
loop_11:
        if (var_r26_1524 < arg2) {
            _table_sincosf(var_f30_1527, sp1C, sp18);
            var_f31_1534 = 0.0f;
            MKBegin(arg1 + 1);
            MKSetColorV(arg3);
            var_r25_1539 = 0;
loop_9:
            if (var_r25_1539 < (s32) (arg1 + 1)) {
                _table_sincosf(var_f31_1534, spC, sp8);
                MKSetPositionF((sp1C * (spC * temp_f24_1520)) + temp_f27_1521, (sp18 * temp_f24_1520) + temp_f26_1523, (sp1C * (sp8 * temp_f24_1520)) + temp_f25_1526);
                var_f31_1534 += temp_f29_1442;
                var_r25_1539 += 1;
                goto loop_9;
            }
            MKEnd();
            var_f30_1527 += temp_f28_1525;
            var_r26_1524 += 1;
            goto loop_11;
        }
        MKEndPrimitive();
    } else {
        MKPrimitive(0x10D, 3);
        MKSetMatrix(arg4);
        MKBegin(arg1 + 2);
        MKSetColorV(arg3);
        MKSetPositionF(arg0.unk0, arg0.unk4 + arg0.unkC, arg0.unk8);
        _table_sincosf(var_f28_1441, sp1C, sp18);
        temp_f24_1589 = arg0.unkC;
        temp_f27_1591 = arg0.unk0;
        var_r26_1592 = 0;
        temp_f26_1593 = arg0.unk4;
        temp_f25_1594 = arg0.unk8;
loop_15:
        if (var_r26_1592 < (s32) (arg1 + 1)) {
            _table_sincosf(var_f31_1423, spC, sp8);
            MKSetPositionF((sp1C * (spC * temp_f24_1589)) + temp_f27_1591, (sp18 * temp_f24_1589) + temp_f26_1593, (sp1C * (sp8 * temp_f24_1589)) + temp_f25_1594);
            var_f31_1423 += temp_f29_1442;
            var_r26_1592 += 1;
            goto loop_15;
        }
        MKEnd();
        MKBegin(arg1 + 2);
        MKSetColorV(arg3);
        MKSetPositionF(arg0.unk0, arg0.unk4 - arg0.unkC, arg0.unk8);
        _table_sincosf(3.1415927f - var_f28_1441, sp1C, sp18);
        temp_f24_1632 = arg0.unkC;
        temp_f27_1634 = arg0.unk0;
        var_r26_1635 = 0;
        temp_f26_1636 = arg0.unk4;
        temp_f25_1637 = arg0.unk8;
loop_18:
        if (var_r26_1635 < (s32) (arg1 + 1)) {
            _table_sincosf(var_f31_1423, spC, sp8);
            MKSetPositionF((sp1C * (spC * temp_f24_1632)) + temp_f27_1634, (sp18 * temp_f24_1632) + temp_f26_1636, (sp1C * (sp8 * temp_f24_1632)) + temp_f25_1637);
            var_f31_1423 += temp_f29_1442;
            var_r26_1635 += 1;
            goto loop_18;
        }
        MKEnd();
        MKEndPrimitive();
        MKPrimitive(0x10C, 3);
        MKSetMatrix(arg4);
        var_f30_1666 = var_f28_1441;
        temp_f24_1668 = arg0.unkC;
        temp_f25_1670 = arg0.unk0;
        temp_f26_1672 = arg0.unk4;
        temp_f27_1674 = arg0.unk8;
        var_r25_1675 = 0;
loop_24:
        if (var_r25_1675 < (s32) (arg2 - 1)) {
            _table_sincosf(var_f30_1666, sp1C, sp18);
            _table_sincosf(var_f30_1666 + var_f28_1441, sp14, sp10);
            MKBegin((arg1 * 2) + 2);
            MKSetColorV(arg3);
            var_r30_1690 = 0;
loop_22:
            if (var_r30_1690 < (s32) (arg1 + 1)) {
                _table_sincosf(var_f31_1423, spC, sp8);
                MKSetPositionF((sp1C * (spC * temp_f24_1668)) + temp_f25_1670, (sp18 * temp_f24_1668) + temp_f26_1672, (sp1C * (sp8 * temp_f24_1668)) + temp_f27_1674);
                MKSetPositionF((sp14 * (spC * temp_f24_1668)) + temp_f25_1670, (sp10 * temp_f24_1668) + temp_f26_1672, (sp14 * (sp8 * temp_f24_1668)) + temp_f27_1674);
                var_f31_1423 += temp_f29_1442;
                var_r30_1690 += 1;
                goto loop_22;
            }
            MKEnd();
            var_f30_1666 += var_f28_1441;
            var_r25_1675 += 1;
            goto loop_24;
        }
        MKEndPrimitive();
    }
    MKPrimitive(0x109, 3);
    MKBegin(6);
    MKSetColorF(0.0f, 1.0f, 0.0f, 1.0f);
    MKSetPositionF(arg0.unk0, (0.5f * arg0.unkC) + arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetColorF(1.0f, 0.0f, 0.0f, 1.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF((0.5f * arg0.unkC) + arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetColorF(0.0f, 0.0f, 1.0f, 1.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, (0.5f * arg0.unkC) + arg0.unk8);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKCollisionAABB'
void MKShape_DrawBox(const MKCollisionAABB &arg0, const MKVector4 &arg1, const Matrix &arg2, bool arg3) {
    MKShape_DrawBox(*((MKVector3 *) &arg0), *((MKVector3 *) arg0.unk10), arg1, arg2, arg3);
}
#endif

void MKShape_DrawBox(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, const Matrix &arg3, bool arg4) {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f3_1955;
    f64 temp_f0_1952;
    f64 temp_f0_1964;
    f64 temp_f0_1974;
    f64 temp_f2_1951;

    if (arg4 != 0) {
        MKPrimitive(0x109, 3);
        MKSetMatrix(arg3);
        MKBegin(0x18);
        MKSetColorV(arg2);
        MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
        MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
        MKSetPositionF(arg0.unk0, arg1.unk4, arg0.unk8);
        MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
        MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
        MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
        MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
        MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
        MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
        MKSetPositionF(arg0.unk0, arg1.unk4, arg0.unk8);
        MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
        MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
        MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
        MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
        MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
        MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
        MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
        MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
        MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
        MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
        MKSetPositionF(arg0.unk0, arg1.unk4, arg0.unk8);
        MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
        MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
        MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
        MKEnd();
        temp_f2_1951 = (f64) M2C_FIELD(&arg0, f32 *, 0);
        temp_f0_1952 = (f64) M2C_FIELD(&arg1, f32 *, 0) - temp_f2_1951;
        sp28 = temp_f0_1952;
        temp_f3_1955 = arg0.unk8;
        sp38 = temp_f0_1952;
        sp30 = arg1.unk8 - temp_f3_1955;
        sp40 = (f64) sp30;
        temp_f0_1964 = temp_f0_1952 * 5.222099017e-315;
        sp18 = temp_f0_1964;
        sp48 = temp_f0_1964;
        sp20 = (f32) sp40 * 0.5f;
        sp50 = (f64) sp20;
        temp_f0_1974 = temp_f2_1951 + temp_f0_1964;
        sp8 = temp_f0_1974;
        sp58 = temp_f0_1974;
        sp10 = temp_f3_1955 + (f32) sp50;
        sp60 = (f64) sp10;
        MKBegin(2);
        MKSetColorF(0.0f, 1.0f, 0.0f, 1.0f);
        MKSetPositionF((f32) sp58, 0.1f + (*(f32 *) ((u8 *) &sp58 + 0x4)), (f32) sp60);
        MKSetPositionF((f32) sp58, (*(f32 *) ((u8 *) &sp58 + 0x4)), (f32) sp60);
        MKEnd();
        MKBegin(2);
        MKSetColorF(1.0f, 0.0f, 0.0f, 1.0f);
        MKSetPositionF((f32) sp58, (*(f32 *) ((u8 *) &sp58 + 0x4)), (f32) sp60);
        MKSetPositionF(0.1f + (f32) sp58, (*(f32 *) ((u8 *) &sp58 + 0x4)), (f32) sp60);
        MKEnd();
        MKBegin(2);
        MKSetColorF(0.0f, 0.0f, 1.0f, 1.0f);
        MKSetPositionF((f32) sp58, (*(f32 *) ((u8 *) &sp58 + 0x4)), (f32) sp60);
        MKSetPositionF((f32) sp58, (*(f32 *) ((u8 *) &sp58 + 0x4)), 0.1f + (f32) sp60);
        MKEnd();
        MKEndPrimitive();
        return;
    }
    MKPrimitive(4, 2);
    MKSetMatrix(arg3);
    MKBegin(0x22);
    MKSetColorV(arg2);
    MKSetNormalF(0.0f, 0.0f, -1.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetNormalF(0.0f, -1.0f, 0.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
    MKSetNormalF(0.0f, 0.0f, 1.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
    MKSetNormalF(0.0f, 1.0f, 0.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
    MKSetNormalF(-1.0f, 0.0f, 0.0f);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg0.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg1.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
    MKSetNormalF(1.0f, 0.0f, 0.0f);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg1.unk4, arg1.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg1.unk0, arg0.unk4, arg1.unk8);
    MKEnd();
    MKEndPrimitive();
}

void MKShape_Deinit() {

}

void MKShape_Init() {

}

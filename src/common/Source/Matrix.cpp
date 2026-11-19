#include "common/Source/Matrix.h"
#include "common/Source/MKVector3.h"
#include "common/Source/StdMath.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f64 atan2(void *, void *, f32, f32);                /* extern */

void Matrix::SetRotateAroundAxis(const MKVector3 &arg0, float arg1) {
    f32 spC;
    f32 sp8;
    f32 temp_f0_23;
    f32 temp_f2_27;
    f32 temp_f4_24;
    f32 temp_f5_25;
    f32 temp_f6_26;
    f32 temp_f7_22;

    _table_sincosf(arg1, sp8, spC);
    temp_f7_22 = arg0.unk0;
    temp_f0_23 = 1.0f - spC;
    temp_f4_24 = arg0.unk8;
    temp_f5_25 = arg0.unk4;
    temp_f6_26 = temp_f0_23 * temp_f7_22;
    temp_f2_27 = temp_f0_23 * temp_f5_25;
    this->unk0 = spC + (temp_f7_22 * temp_f6_26);
    this->unk10 = (temp_f5_25 * temp_f6_26) - (sp8 * temp_f4_24);
    this->unk20 = (temp_f4_24 * temp_f6_26) + (sp8 * temp_f5_25);
    this->unk4 = (temp_f5_25 * temp_f6_26) + (sp8 * temp_f4_24);
    this->unk14 = spC + (temp_f5_25 * temp_f2_27);
    this->unk24 = (temp_f4_24 * temp_f2_27) - (sp8 * temp_f7_22);
    this->unk8 = (temp_f4_24 * temp_f6_26) - (sp8 * temp_f5_25);
    this->unk18 = (temp_f4_24 * temp_f2_27) + (sp8 * temp_f7_22);
    this->unk28 = spC + (temp_f4_24 * (temp_f0_23 * temp_f4_24));
}

void Matrix::Inverse(const Matrix *arg0) {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f11_104;
    f32 temp_f12_98;
    f32 temp_f13_100;
    f32 temp_f27_92;
    f32 temp_f28_95;
    f32 temp_f29_88;
    f32 temp_f30_94;
    f32 temp_f31_91;
    f32 temp_f5_127;
    f32 temp_f5_90;

    temp_f29_88 = arg0->unk18;
    temp_f5_90 = arg0->unk24;
    temp_f31_91 = arg0->unk10;
    temp_f27_92 = arg0->unk28;
    temp_f30_94 = arg0->unk14;
    temp_f28_95 = arg0->unk20;
    temp_f12_98 = arg0->unk4;
    temp_f13_100 = arg0->unk8;
    this->unk0 = (temp_f30_94 * temp_f27_92) - (temp_f5_90 * temp_f29_88);
    temp_f11_104 = arg0->unk0;
    this->unk10 = (temp_f28_95 * temp_f29_88) - (temp_f31_91 * temp_f27_92);
    this->unk20 = (temp_f31_91 * temp_f5_90) - (temp_f28_95 * temp_f30_94);
    this->unk4 = (temp_f5_90 * temp_f13_100) - (temp_f12_98 * temp_f27_92);
    sp28 = M2C_FIELD(arg0, f64 *, 0x30);
    this->unk14 = (temp_f11_104 * temp_f27_92) - (temp_f28_95 * temp_f13_100);
    temp_f5_127 = (temp_f13_100 * this->unk20) + ((temp_f11_104 * this->unk0) + (temp_f12_98 * this->unk10));
    this->unk24 = (temp_f28_95 * temp_f12_98) - (temp_f11_104 * temp_f5_90);
    this->unk8 = (temp_f12_98 * temp_f29_88) - (temp_f30_94 * temp_f13_100);
    this->unk18 = (temp_f31_91 * temp_f13_100) - (temp_f11_104 * temp_f29_88);
    sp30 = M2C_FIELD(arg0, f64 *, 0x38);
    this->unk28 = (temp_f11_104 * temp_f30_94) - (temp_f31_91 * temp_f12_98);
    if (temp_f5_127 != 0.0f) {
        Scale3x3(this, 1.0f / temp_f5_127);
    }
    sp8 = ((f32) sp30 * this->unk20) + (((f32) sp28 * this->unk0) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * this->unk10));
    spC = ((f32) sp30 * this->unk24) + (((f32) sp28 * this->unk4) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * this->unk14));
    sp10 = ((f32) sp30 * this->unk28) + (((f32) sp28 * this->unk8) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * this->unk18));
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp18 = (f64) sp8;
    this->unk30 = -(f32) sp28;
    this->unk34 = -(*(f32 *) ((u8 *) &sp28 + 0x4));
    this->unk38 = -(f32) sp30;
    this->unk2C = 0.0f;
    this->unk1C = 0.0f;
    this->unkC = 0.0f;
    sp20 = (f64) sp10;
    this->unk3C = 1.0f;
}

void Matrix::RotatePYR(const Matrix *arg0, const MKVector3 &arg1) {
    Matrix sp10;

    sp10.SetRotationPYR(arg1);
    sp10.unk30 = 0.0f;
    sp10.unk34 = 0.0f;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    Multiply4x4(arg0, &sp10);
}

void Matrix::RotateRoll(const Matrix *arg0, float arg1) {
    Matrix sp10;

    sp10.SetRotationRoll(arg1);
    sp10.unk30 = 0.0f;
    sp10.unk34 = 0.0f;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    Multiply4x4(arg0, &sp10);
}

void Matrix::RotateYaw(const Matrix *arg0, float arg1) {
    Matrix sp10;

    sp10.SetRotationYaw(arg1);
    sp10.unk30 = 0.0f;
    sp10.unk34 = 0.0f;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    Multiply4x4(arg0, &sp10);
}

void Matrix::RotatePitch(const Matrix *arg0, float arg1) {
    Matrix sp10;

    sp10.SetRotationPitch(arg1);
    sp10.unk30 = 0.0f;
    sp10.unk34 = 0.0f;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    Multiply4x4(arg0, &sp10);
}

void Matrix::Translate(const Matrix *arg0, const MKVector4 &arg1) {
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;

    d = (s32 *) this - 1;
    q = (const s32 *) arg0 - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }
    this->unk30 += M2C_FIELD(&arg1, f32 *, 0x0);
    this->unk34 += M2C_FIELD(&arg1, f32 *, 0x4);
    this->unk38 += M2C_FIELD(&arg1, f32 *, 0x8);
    this->unk3C += M2C_FIELD(&arg1, f32 *, 0xC);
}

void Matrix::Translate(const Matrix *arg0, const MKVector3 &arg1) {
    M2C_STRUCT_COPY(this, arg0, 0x40);
    this->unk30 += arg1.unk0;
    this->unk34 += arg1.unk4;
    this->unk38 += arg1.unk8;
}

void Matrix::Scale4x3(const Matrix *arg0, float arg1) {
    this->unk0 = arg0->unk0 * arg1;
    this->unk4 = arg0->unk4 * arg1;
    this->unk8 = arg0->unk8 * arg1;
    this->unkC = 0.0f;
    this->unk10 = arg0->unk10 * arg1;
    this->unk14 = arg0->unk14 * arg1;
    this->unk18 = arg0->unk18 * arg1;
    this->unk1C = 0.0f;
    this->unk20 = arg0->unk20 * arg1;
    this->unk24 = arg0->unk24 * arg1;
    this->unk28 = arg0->unk28 * arg1;
    this->unk2C = 0.0f;
    this->unk30 = arg0->unk30 * arg1;
    this->unk34 = arg0->unk34 * arg1;
    this->unk38 = arg0->unk38 * arg1;
    this->unk3C = 1.0f;
}

void Matrix::Scale3x3(const Matrix *arg0, const MKVector3 &arg1) {
    f32 temp_f2_451;
    f32 temp_f4_464;
    f32 temp_f5_445;

    temp_f5_445 = arg1.unk0;
    temp_f2_451 = arg1.unk4;
    this->unk0 = temp_f5_445 * arg0->unk0;
    this->unk4 = temp_f5_445 * arg0->unk4;
    this->unk8 = temp_f5_445 * arg0->unk8;
    this->unkC = arg0->unkC;
    temp_f4_464 = arg1.unk8;
    this->unk10 = temp_f2_451 * arg0->unk10;
    this->unk14 = temp_f2_451 * arg0->unk14;
    this->unk18 = temp_f2_451 * arg0->unk18;
    this->unk1C = arg0->unk1C;
    this->unk20 = temp_f4_464 * arg0->unk20;
    this->unk24 = temp_f4_464 * arg0->unk24;
    this->unk28 = temp_f4_464 * arg0->unk28;
    this->unk2C = arg0->unk2C;
    this->unk30 = arg0->unk30;
    this->unk34 = arg0->unk34;
    this->unk38 = arg0->unk38;
    this->unk3C = arg0->unk3C;
}

void Matrix::Scale3x3(const Matrix *arg0, float arg1) {
    this->unk0 = arg1 * arg0->unk0;
    this->unk4 = arg1 * arg0->unk4;
    this->unk8 = arg1 * arg0->unk8;
    this->unkC = arg0->unkC;
    this->unk10 = arg1 * arg0->unk10;
    this->unk14 = arg1 * arg0->unk14;
    this->unk18 = arg1 * arg0->unk18;
    this->unk1C = arg0->unk1C;
    this->unk20 = arg1 * arg0->unk20;
    this->unk24 = arg1 * arg0->unk24;
    this->unk28 = arg1 * arg0->unk28;
    this->unk2C = arg0->unk2C;
    this->unk30 = arg0->unk30;
    this->unk34 = arg0->unk34;
    this->unk38 = arg0->unk38;
    this->unk3C = arg0->unk3C;
}

void Matrix::Multiply4x4(const Matrix *arg0, const Matrix *arg1) {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    M2C_UNK spC;
    f32 temp_f0_582;
    f32 temp_f0_615;
    f32 temp_f10_597;
    f32 temp_f11_650;
    f32 temp_f12_656;
    f32 temp_f13_595;
    f32 temp_f13_641;
    f32 temp_f14_598;
    f32 temp_f15_602;
    f32 temp_f15_657;
    f32 temp_f16_587;
    f32 temp_f16_655;
    f32 temp_f17_583;
    f32 temp_f17_653;
    f32 temp_f18_659;
    f32 temp_f19_585;
    f32 temp_f19_629;
    f32 temp_f1_640;
    f32 temp_f20_623;
    f32 temp_f21_621;
    f32 temp_f22_617;
    f32 temp_f23_591;
    f32 temp_f24_589;
    f32 temp_f25_609;
    f32 temp_f26_606;
    f32 temp_f27_671;
    f32 temp_f28_646;
    f32 temp_f29_592;
    f32 temp_f2_601;
    f32 temp_f30_611;
    f32 temp_f31_663;
    f32 temp_f9_584;

    temp_f0_582 = arg0->unk4;
    temp_f17_583 = arg1->unk10;
    temp_f9_584 = arg0->unk14;
    temp_f19_585 = arg1->unk14;
    temp_f16_587 = arg0->unk24;
    temp_f24_589 = arg1->unk18;
    temp_f23_591 = arg1->unk1C;
    temp_f29_592 = arg0->unk34;
    temp_f13_595 = arg0->unk0;
    temp_f10_597 = arg1->unk0;
    temp_f14_598 = arg0->unk20;
    temp_f2_601 = arg0->unk10;
    temp_f15_602 = arg1->unk4;
    sp50 = (f64) ((temp_f14_598 * temp_f10_597) + (temp_f16_587 * temp_f17_583));
    temp_f26_606 = arg1->unk8;
    temp_f25_609 = arg1->unkC;
    temp_f30_611 = arg0->unk30;
    temp_f0_615 = arg0->unk8;
    temp_f22_617 = arg1->unk20;
    temp_f21_621 = arg1->unk24;
    temp_f20_623 = arg1->unk28;
    sp68 = (f64) ((temp_f30_611 * temp_f10_597) + (temp_f29_592 * temp_f17_583));
    temp_f19_629 = arg1->unk2C;
    sp58 = (f64) ((temp_f14_598 * temp_f15_602) + (temp_f16_587 * temp_f19_585));
    sp70 = (f64) ((temp_f30_611 * temp_f15_602) + (temp_f29_592 * temp_f19_585));
    sp60 = (f64) ((temp_f14_598 * temp_f26_606) + (temp_f16_587 * temp_f24_589));
    temp_f1_640 = arg0->unk18;
    temp_f13_641 = arg0->unk28;
    temp_f28_646 = arg0->unk38;
    temp_f11_650 = arg0->unkC;
    temp_f17_653 = arg1->unk34;
    temp_f16_655 = arg1->unk38;
    temp_f12_656 = arg0->unk1C;
    temp_f15_657 = arg1->unk3C;
    temp_f18_659 = arg1->unk30;
    temp_f31_663 = arg0->unk2C;
    sp14 = (temp_f11_650 * temp_f17_653) + ((temp_f0_615 * temp_f21_621) + ((temp_f13_595 * temp_f15_602) + (temp_f0_582 * temp_f19_585)));
    temp_f27_671 = arg0->unk3C;
    sp18 = (temp_f11_650 * temp_f16_655) + ((temp_f0_615 * temp_f20_623) + ((temp_f13_595 * temp_f26_606) + (temp_f0_582 * temp_f24_589)));
    sp1C = (temp_f11_650 * temp_f15_657) + ((temp_f0_615 * temp_f19_629) + ((temp_f13_595 * temp_f25_609) + (temp_f0_582 * temp_f23_591)));
    sp10 = (temp_f11_650 * temp_f18_659) + ((temp_f0_615 * temp_f22_617) + ((temp_f13_595 * temp_f10_597) + (temp_f0_582 * temp_f17_583)));
    sp20 = (temp_f12_656 * temp_f18_659) + ((temp_f1_640 * temp_f22_617) + ((temp_f2_601 * temp_f10_597) + (temp_f9_584 * temp_f17_583)));
    sp24 = (temp_f12_656 * temp_f17_653) + ((temp_f1_640 * temp_f21_621) + ((temp_f2_601 * temp_f15_602) + (temp_f9_584 * temp_f19_585)));
    sp28 = (temp_f12_656 * temp_f16_655) + ((temp_f1_640 * temp_f20_623) + ((temp_f2_601 * temp_f26_606) + (temp_f9_584 * temp_f24_589)));
    sp2C = (temp_f12_656 * temp_f15_657) + ((temp_f1_640 * temp_f19_629) + ((temp_f2_601 * temp_f25_609) + (temp_f9_584 * temp_f23_591)));
    sp30 = (temp_f31_663 * temp_f18_659) + ((temp_f13_641 * temp_f22_617) + (f32) sp50);
    sp34 = (temp_f31_663 * temp_f17_653) + ((temp_f13_641 * temp_f21_621) + (f32) sp58);
    sp38 = (temp_f31_663 * temp_f16_655) + ((temp_f13_641 * temp_f20_623) + (f32) sp60);
    sp3C = (temp_f31_663 * temp_f15_657) + ((temp_f13_641 * temp_f19_629) + ((temp_f14_598 * temp_f25_609) + (temp_f16_587 * temp_f23_591)));
    sp40 = (temp_f27_671 * temp_f18_659) + ((temp_f28_646 * temp_f22_617) + (f32) sp68);
    sp44 = (temp_f27_671 * temp_f17_653) + ((temp_f28_646 * temp_f21_621) + (f32) sp70);
    sp48 = (temp_f27_671 * temp_f16_655) + ((temp_f28_646 * temp_f20_623) + ((temp_f30_611 * temp_f26_606) + (temp_f29_592 * temp_f24_589)));
    sp4C = (temp_f27_671 * temp_f15_657) + ((temp_f28_646 * temp_f19_629) + ((temp_f30_611 * temp_f25_609) + (temp_f29_592 * temp_f23_591)));
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &spC + 4, 0x40);
}

void Matrix::Multiply3x3(const Matrix *arg0, const Matrix *arg1) {
    f32 temp_f0_775;
    f32 temp_f11_771;
    f32 temp_f13_777;
    f32 temp_f13_797;
    f32 temp_f1_784;
    f32 temp_f28_791;
    f32 temp_f28_808;
    f32 temp_f29_768;
    f32 temp_f29_804;
    f32 temp_f2_774;
    f32 temp_f30_786;
    f32 temp_f31_769;
    f32 temp_f3_782;
    f32 temp_f4_767;
    f32 temp_f4_790;
    f32 temp_f5_772;
    f32 temp_f6_780;
    f32 temp_f7_778;

    temp_f4_767 = arg0->unk4;
    temp_f29_768 = arg1->unk10;
    temp_f31_769 = arg1->unk14;
    temp_f11_771 = arg0->unk0;
    temp_f5_772 = arg1->unk0;
    temp_f2_774 = arg1->unk18;
    temp_f0_775 = arg1->unk4;
    temp_f13_777 = arg0->unk8;
    temp_f7_778 = arg0->unk14;
    temp_f6_780 = arg1->unk20;
    temp_f3_782 = arg1->unk8;
    temp_f1_784 = arg1->unk24;
    temp_f30_786 = arg0->unk10;
    temp_f4_790 = arg1->unk28;
    temp_f28_791 = arg0->unk24;
    this->unk0 = (temp_f13_777 * temp_f6_780) + ((temp_f11_771 * temp_f5_772) + (temp_f4_767 * temp_f29_768));
    this->unk4 = (temp_f13_777 * temp_f1_784) + ((temp_f11_771 * temp_f0_775) + (temp_f4_767 * temp_f31_769));
    temp_f13_797 = arg0->unk18;
    this->unk8 = (temp_f13_777 * temp_f4_790) + ((temp_f11_771 * temp_f3_782) + (temp_f4_767 * temp_f2_774));
    temp_f29_804 = arg0->unk20;
    this->unkC = 0.0f;
    temp_f28_808 = arg0->unk28;
    this->unk10 = (temp_f13_797 * temp_f6_780) + ((temp_f30_786 * temp_f5_772) + (temp_f7_778 * temp_f29_768));
    this->unk14 = (temp_f13_797 * temp_f1_784) + ((temp_f30_786 * temp_f0_775) + (temp_f7_778 * temp_f31_769));
    this->unk18 = (temp_f13_797 * temp_f4_790) + ((temp_f30_786 * temp_f3_782) + (temp_f7_778 * temp_f2_774));
    this->unk1C = 0.0f;
    this->unk20 = (temp_f28_808 * temp_f6_780) + ((temp_f29_804 * temp_f5_772) + (temp_f28_791 * temp_f29_768));
    this->unk24 = (temp_f28_808 * temp_f1_784) + ((temp_f29_804 * temp_f0_775) + (temp_f28_791 * temp_f31_769));
    this->unk28 = (temp_f28_808 * temp_f4_790) + ((temp_f29_804 * temp_f3_782) + (temp_f28_791 * temp_f2_774));
    this->unk2C = 0.0f;
}

#if 0 // DRAFT: illegal explicit conversion from 'Matrix *' to 'float'
f32 Matrix::Multiply(const Matrix *arg0, const Matrix *arg1) {
    f32 temp_f12_872;
    f32 temp_f1_856;
    f32 temp_f3_864;
    f32 temp_f5_868;
    f32 temp_f7_866;
    f32 temp_f9_858;
    f64 temp_f0_847;
    f64 temp_f10_852;
    f64 temp_f2_849;
    f64 temp_f4_854;
    f64 temp_f6_850;
    f64 temp_f8_848;
    f64 temp_f8_861;

    temp_f0_847 = M2C_FIELD(arg0, f64 *, 0);
    temp_f8_848 = M2C_FIELD(arg1, f64 *, 0);
    temp_f2_849 = M2C_FIELD(arg0, f64 *, 0x10);
    temp_f6_850 = M2C_FIELD(arg0, f64 *, 0x30);
    temp_f10_852 = M2C_FIELD(arg1, f64 *, 0x10);
    temp_f4_854 = M2C_FIELD(arg0, f64 *, 0x20);
    temp_f1_856 = arg0->unk8;
    temp_f9_858 = arg1->unk8;
    temp_f8_861 = M2C_FIELD(arg1, f64 *, 0x20);
    temp_f3_864 = arg0->unk18;
    temp_f7_866 = arg0->unk38;
    temp_f5_868 = arg0->unk28;
    M2C_FIELD(this, f64 *, 0) = (f64) ((temp_f8_861 * (f64) temp_f1_856) + ((temp_f10_852 * temp_f0_847) + (temp_f8_848 * temp_f0_847)));
    temp_f12_872 = arg1->unk28;
    M2C_FIELD(this, f64 *, 0x10) = (f64) ((temp_f8_861 * (f64) temp_f3_864) + ((temp_f10_852 * temp_f2_849) + (temp_f8_848 * temp_f2_849)));
    M2C_FIELD(this, f64 *, 0x20) = (f64) ((temp_f8_861 * (f64) temp_f5_868) + ((temp_f10_852 * temp_f4_854) + (temp_f8_848 * temp_f4_854)));
    M2C_FIELD(this, f64 *, 0x30) = (f64) ((temp_f8_861 * (f64) temp_f7_866) + ((temp_f10_852 * temp_f6_850) + (temp_f8_848 * temp_f6_850)) + M2C_FIELD(arg1, f64 *, 0x30));
    M2C_FIELD(this, f64 *, 8) = (f64) (((f64) temp_f1_856 * (f64) temp_f12_872) + (2.0 * (temp_f0_847 * (f64) temp_f9_858)));
    M2C_FIELD(this, f64 *, 0x18) = (f64) (((f64) temp_f3_864 * (f64) temp_f12_872) + (2.0 * (temp_f2_849 * (f64) temp_f9_858)));
    M2C_FIELD(this, f64 *, 0x28) = (f64) (((f64) temp_f5_868 * (f64) temp_f12_872) + (2.0 * (temp_f4_854 * (f64) temp_f9_858)));
    M2C_FIELD(this, f64 *, 0x38) = (f64) (((f64) temp_f7_866 * (f64) temp_f12_872) + (2.0 * (temp_f6_850 * (f64) temp_f9_858)) + M2C_FIELD(arg1, f64 *, 0x38));
    return M2C_BITWISE(f32, this);
}
#endif

void Matrix::InverseSimple(const Matrix *arg0) {
    Matrix sp10;
    M2C_UNK spC;
    f32 temp_f3_924;
    f32 temp_f6_933;
    f32 temp_f7_939;
    f32 temp_f8_947;

    sp10.Transpose3x3(arg0);
    temp_f3_924 = arg0->unk34;
    temp_f6_933 = arg0->unk30;
    temp_f7_939 = arg0->unk38;
    temp_f8_947 = arg0->unk3C;
    sp10.unk2C = 0.0f;
    sp10.unk1C = 0.0f;
    sp10.unk30 = -((temp_f8_947 * arg0->unkC) + ((temp_f7_939 * arg0->unk8) + ((temp_f6_933 * arg0->unk0) + (temp_f3_924 * arg0->unk4))));
    sp10.unk34 = -((temp_f8_947 * arg0->unk1C) + ((temp_f7_939 * arg0->unk18) + ((temp_f6_933 * arg0->unk10) + (temp_f3_924 * arg0->unk14))));
    sp10.unk38 = -((temp_f8_947 * arg0->unk2C) + ((temp_f7_939 * arg0->unk28) + ((temp_f6_933 * arg0->unk20) + (temp_f3_924 * arg0->unk24))));
    sp10.unkC = 0.0f;
    sp10.unk3C = 1.0f;
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &spC + 4, 0x40);
}

void Matrix::Transpose3x3(const Matrix *arg0) {
    Matrix tmp;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;

    tmp.unk0 = arg0->unk0;
    tmp.unk4 = arg0->unk10;
    tmp.unk8 = arg0->unk20;
    tmp.unkC = 0.0f;
    tmp.unk10 = arg0->unk4;
    tmp.unk14 = arg0->unk14;
    tmp.unk18 = arg0->unk24;
    tmp.unk1C = 0.0f;
    tmp.unk20 = arg0->unk8;
    tmp.unk24 = arg0->unk18;
    tmp.unk28 = arg0->unk28;
    tmp.unk2C = 0.0f;
    tmp.unk30 = arg0->unk30;
    tmp.unk34 = arg0->unk34;
    tmp.unk38 = arg0->unk38;
    tmp.unk3C = arg0->unk3C;

    d = (s32 *) this - 1;
    q = (const s32 *) &tmp - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }
}

void Matrix::Transpose(const Matrix *arg0) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    M2C_UNK spC;

    sp10 = arg0->unk0;
    sp14 = arg0->unk10;
    sp18 = arg0->unk20;
    sp1C = arg0->unk30;
    sp20 = arg0->unk4;
    sp24 = arg0->unk14;
    sp28 = arg0->unk24;
    sp2C = arg0->unk34;
    sp30 = arg0->unk8;
    sp34 = arg0->unk18;
    sp38 = arg0->unk28;
    sp3C = arg0->unk38;
    sp40 = arg0->unkC;
    sp44 = arg0->unk1C;
    sp48 = arg0->unk2C;
    sp4C = arg0->unk3C;
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &spC + 4, 0x40);
}

void Matrix::SetLookAt(const MKVector3 &arg0, const MKVector3 &arg1) {
    f32 spB0;                                       /* compiler-managed */
    f32 spAC;
    f32 spA8;                                       /* compiler-managed */
    f32 spA0;                                       /* compiler-managed */
    f32 sp9C;
    f32 sp98;                                       /* compiler-managed */
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp28 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0);
    sp88 = sp28;
    sp30 = arg1.unk8 - arg0.unk8;
    sp78 = sp28;
    sp80 = (f64) sp30;
    sp90 = (f64) sp30;
    sp98 = 0.0f;
    sp9C = 1.0f;
    spA0 = 0.0f;
    if (((f32) sp88 == 0.0f) && ((*(f32 *) ((u8 *) &sp88 + 0x4)) == 0.0f) && ((f32) sp90 == 0.0f)) {
        spA8 = 0.0f;
        spAC = 0.0f;
        spB0 = 0.0f;
    } else {
        sp68 = Normalise(*((MKVector3 *) &sp88));
        *(MKVector3 *) &sp88 = sp68;
        sp20 = (sp98 * (*(f32 *) ((u8 *) &sp88 + 0x4))) - (sp9C * (f32) sp88);
        sp1C = (spA0 * (f32) sp88) - (sp98 * (f32) sp90);
        sp18 = (sp9C * (f32) sp90) - (spA0 * (*(f32 *) ((u8 *) &sp88 + 0x4)));
        sp50 = (f64) sp20;
        sp48 = (f64) sp18;
        sp58 = Normalise(*((MKVector3 *) &sp48));
        *(MKVector3 *) &spA8 = sp58;
    }
    this->unk0 = (f32) spA8;
    this->unk4 = spAC;
    sp10 = ((f32) sp88 * spAC) - ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (f32) spA8);
    this->unk8 = (f32) spB0;
    spA0 = (f64) sp10;
    sp8 = ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (f32) spB0) - ((f32) sp90 * spAC);
    spC = ((f32) sp90 * (f32) spA8) - ((f32) sp88 * (f32) spB0);
    this->unkC = 0.0f;
    sp98 = (f64) sp8;
    this->unk10 = (f32) sp98;
    this->unk14 = sp9C;
    this->unk18 = (f32) spA0;
    this->unk1C = 0.0f;
    sp38 = (f64) sp8;
    this->unk20 = (f32) sp88;
    sp40 = (f64) sp10;
    this->unk24 = (*(f32 *) ((u8 *) &sp88 + 0x4));
    this->unk28 = (f32) sp90;
    this->unk2C = 0.0f;
    this->unk30 = arg0.unk0;
    this->unk34 = arg0.unk4;
    this->unk38 = arg0.unk8;
    this->unk3C = 1.0f;
}

extern "C" double atan2(double, double);
MKVector3 Matrix::GetRotationRPY(void) const {
    MKVector3 result;
    Matrix sp20;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 temp;

    d = (s32 *) &sp20 - 1;
    q = (const s32 *) this - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }

    temp = -(f32) atan2(sp20.unk20, sp20.unk28);
    sp14 = temp;
    sp20.RotateYaw(&sp20, -temp);
    sp10 = (f32) atan2(sp20.unk24, sp20.unk28);
    sp20.RotatePitch(&sp20, -sp10);
    sp18 = -(f32) atan2(sp20.unk4, sp20.unk0);
    M2C_FIELD(&result, f64 *, 0) = M2C_FIELD(&sp10, f64 *, 0);
    M2C_FIELD(&result, f64 *, 8) = M2C_FIELD(&sp18, f64 *, 0);
    return result;
}

MKVector3 Matrix::GetRotationPRY(void) const {
    MKVector3 result;
    Matrix sp20;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 absU0;
    f32 absU8;

    d = (s32 *) &sp20 - 1;
    q = (const s32 *) this - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }

    if (sp20.unk0 < 0.0f) {
        absU0 = -sp20.unk0;
    } else {
        absU0 = sp20.unk0;
    }
    if (absU0 < 0.001f) {
        if (sp20.unk8 < 0.0f) {
            absU8 = -sp20.unk8;
        } else {
            absU8 = sp20.unk8;
        }
        if (absU8 < 0.001f) {
            sp14 = 0.0f;
            goto yaw;
        }
    }
    if (sp20.unk0 > 0.0f) {
        sp14 = -(f32) atan2(sp20.unk8, -sp20.unk0);
    } else if (sp20.unk0 < 0.0f) {
        sp14 = -(f32) atan2(-sp20.unk8, sp20.unk0);
    } else {
        sp14 = 0.0f;
    }
yaw:
    sp20.RotateYaw(&sp20, -sp14);
    sp18 = -(f32) atan2(sp20.unk4, sp20.unk0);
    sp20.RotateRoll(&sp20, -sp18);
    sp10 = (f32) atan2(sp20.unk24, sp20.unk28);
    M2C_FIELD(&result, f64 *, 0) = M2C_FIELD(&sp10, f64 *, 0);
    M2C_FIELD(&result, f64 *, 8) = M2C_FIELD(&sp18, f64 *, 0);
    return result;
}

MKVector3 Matrix::GetRotationPYR(void) const {
    MKVector3 result;
    Matrix sp20;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 absU0;
    f32 absU4;

    d = (s32 *) &sp20 - 1;
    q = (const s32 *) this - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }

    if (sp20.unk0 < 0.0f) {
        absU0 = -sp20.unk0;
    } else {
        absU0 = sp20.unk0;
    }
    if (absU0 < 0.001f) {
        if (sp20.unk4 < 0.0f) {
            absU4 = -sp20.unk4;
        } else {
            absU4 = sp20.unk4;
        }
        if (absU4 < 0.001f) {
            sp18 = 0.0f;
            goto roll;
        }
    }
    if (sp20.unk0 > 0.0f) {
        sp18 = (f32) atan2(-sp20.unk4, sp20.unk0);
    } else if (sp20.unk0 < 0.0f) {
        sp18 = (f32) atan2(sp20.unk4, -sp20.unk0);
    } else {
        sp18 = 0.0f;
    }
roll:
    sp20.RotateRoll(&sp20, -sp18);
    sp14 = (f32) atan2(sp20.unk8, sp20.unk0);
    sp20.RotateYaw(&sp20, -sp14);
    sp10 = (f32) atan2(sp20.unk24, sp20.unk28);
    M2C_FIELD(&result, f64 *, 0) = M2C_FIELD(&sp10, f64 *, 0);
    M2C_FIELD(&result, f64 *, 8) = M2C_FIELD(&sp18, f64 *, 0);
    return result;
}

void Matrix::SetRotationPYR(const MKVector3 &arg0) {
    Matrix sp20;
    f64 sp18;
    f64 sp10;

    sp10 = M2C_FIELD(&arg0, f64 *, 0);
    sp18 = M2C_FIELD(&arg0, f64 *, 8);
    SetRotationPitch((f32) sp10);
    sp20.SetRotationYaw((*(f32 *) ((u8 *) &sp10 + 0x4)));
    Multiply3x3(this, &sp20);
    sp20.SetRotationRoll((f32) sp18);
    Multiply3x3(this, &sp20);
}

void Matrix::SetRotationRoll(float arg0) {
    f32 spC;
    f32 sp8;

    _table_sincosf(arg0, spC, sp8);
    this->unk0 = sp8;
    this->unk4 = -spC;
    this->unkC = 0.0f;
    this->unk8 = 0.0f;
    this->unk10 = spC;
    this->unk14 = sp8;
    this->unk1C = 0.0f;
    this->unk18 = 0.0f;
    this->unk24 = 0.0f;
    this->unk20 = 0.0f;
    this->unk28 = 1.0f;
    this->unk2C = 0.0f;
}

void Matrix::SetRotationYaw(float arg0) {
    f32 spC;
    f32 sp8;

    _table_sincosf(arg0, spC, sp8);
    this->unk0 = sp8;
    this->unk4 = 0.0f;
    this->unk8 = spC;
    this->unkC = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 1.0f;
    this->unk1C = 0.0f;
    this->unk18 = 0.0f;
    this->unk20 = -spC;
    this->unk24 = 0.0f;
    this->unk28 = sp8;
    this->unk2C = 0.0f;
}

void Matrix::SetRotationPitch(float arg0) {
    f32 spC;
    f32 sp8;

    _table_sincosf(arg0, spC, sp8);
    this->unk0 = 1.0f;
    this->unkC = 0.0f;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = sp8;
    this->unk18 = -spC;
    this->unk1C = 0.0f;
    this->unk20 = 0.0f;
    this->unk24 = spC;
    this->unk28 = sp8;
    this->unk2C = 0.0f;
}

#if 0 // DRAFT: identifier 'Matrix::NormaliseScale()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void Matrix::NormaliseScale() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 sp20;                                       /* compiler-managed */
    f64 sp18;                                       /* compiler-managed */
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1727;
    f32 temp_f1_1825;
    f32 temp_f2_1725;
    f32 temp_f2_1823;
    f32 temp_f3_1729;
    f32 temp_f3_1827;
    f32 temp_f3_1925;
    f32 temp_f4_1923;
    f32 temp_f5_1921;
    f32 var_f3_1717;
    f32 var_f4_1728;
    f32 var_f5_1650;
    f32 var_f5_1750;
    f32 var_f6_1826;
    f32 var_f7_1848;
    f64 temp_f1_1656;
    f64 temp_f1_1662;
    f64 temp_f1_1666;
    f64 temp_f1_1755;
    f64 temp_f1_1761;
    f64 temp_f1_1765;
    f64 temp_f1_1853;
    f64 temp_f1_1859;
    f64 temp_f1_1863;
    s32 temp_r5_1685;
    s32 temp_r5_1784;
    s32 temp_r5_1882;
    s32 var_r0_1695;
    s32 var_r0_1794;
    s32 var_r0_1892;

    sp18 = M2C_FIELD(this, f64 *, 0);
    sp20 = M2C_FIELD(this, f64 *, 8);
    var_f5_1650 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp10 + 0xc)) * (*(f32 *) ((u8 *) &sp10 + 0xc))));
    if (var_f5_1650 > 0.000001f) {
        if (var_f5_1650 > 0.0f) {
            temp_f1_1656 = __frsqrte(var_f5_1650);
            temp_f1_1662 = 0.5 * temp_f1_1656 * -(((f64) var_f5_1650 * (temp_f1_1656 * temp_f1_1656)) - 3.0);
            temp_f1_1666 = 0.5 * temp_f1_1662 * -(((f64) var_f5_1650 * (temp_f1_1662 * temp_f1_1662)) - 3.0);
            var_f5_1650 = (f32) ((f64) var_f5_1650 * (0.5 * temp_f1_1666 * -(((f64) var_f5_1650 * (temp_f1_1666 * temp_f1_1666)) - 3.0)));
        } else if (var_f5_1650 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1650 = __float_nan;
        } else {
            sp10 = var_f5_1650;
            temp_r5_1685 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r5_1685) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1695 = 1;
                } else {
                    var_r0_1695 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1695 = 5;
                } else {
                    var_r0_1695 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1695 = 4;
                break;
            }
            if (var_r0_1695 == 1) {
                var_f5_1650 = __float_nan;
            }
        }
        var_f3_1717 = 1.0f / var_f5_1650;
    } else {
        var_f3_1717 = 0.0f;
        var_f5_1650 = 0.0f;
    }
    temp_f2_1725 = (f32) sp18 * var_f3_1717;
    temp_f1_1727 = (*(f32 *) ((u8 *) &sp10 + 0xc)) * var_f3_1717;
    var_f4_1728 = 0.0f;
    temp_f3_1729 = (f32) sp20 * var_f3_1717;
    this->unk0 = temp_f2_1725;
    this->unk4 = temp_f1_1727;
    this->unk8 = temp_f3_1729;
    this->unkC = 0.0f;
    sp18 = temp_f2_1725;
    (*(f32 *) ((u8 *) &sp10 + 0xc)) = temp_f1_1727;
    sp18 = M2C_FIELD(this, f64 *, 0x10);
    sp20 = temp_f3_1729;
    sp20 = M2C_FIELD(this, f64 *, 0x18);
    sp28 = var_f5_1650;
    var_f5_1750 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp10 + 0xc)) * (*(f32 *) ((u8 *) &sp10 + 0xc))));
    if (var_f5_1750 > 0.000001f) {
        if (var_f5_1750 > 0.0f) {
            temp_f1_1755 = __frsqrte(var_f5_1750);
            temp_f1_1761 = 0.5 * temp_f1_1755 * -(((f64) var_f5_1750 * (temp_f1_1755 * temp_f1_1755)) - 3.0);
            temp_f1_1765 = 0.5 * temp_f1_1761 * -(((f64) var_f5_1750 * (temp_f1_1761 * temp_f1_1761)) - 3.0);
            var_f5_1750 = (f32) ((f64) var_f5_1750 * (0.5 * temp_f1_1765 * -(((f64) var_f5_1750 * (temp_f1_1765 * temp_f1_1765)) - 3.0)));
        } else if (var_f5_1750 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1750 = __float_nan;
        } else {
            spC = var_f5_1750;
            temp_r5_1784 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r5_1784) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1794 = 1;
                } else {
                    var_r0_1794 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1794 = 5;
                } else {
                    var_r0_1794 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1794 = 4;
                break;
            }
            if (var_r0_1794 == 1) {
                var_f5_1750 = __float_nan;
            }
        }
        var_f4_1728 = 1.0f / var_f5_1750;
    } else {
        var_f5_1750 = 0.0f;
    }
    temp_f2_1823 = (f32) sp18 * var_f4_1728;
    temp_f1_1825 = (*(f32 *) ((u8 *) &sp10 + 0xc)) * var_f4_1728;
    var_f6_1826 = 0.0f;
    temp_f3_1827 = (f32) sp20 * var_f4_1728;
    this->unk10 = temp_f2_1823;
    this->unk14 = temp_f1_1825;
    this->unk18 = temp_f3_1827;
    this->unk1C = 0.0f;
    sp18 = temp_f2_1823;
    (*(f32 *) ((u8 *) &sp10 + 0xc)) = temp_f1_1825;
    sp18 = M2C_FIELD(this, f64 *, 0x20);
    sp20 = temp_f3_1827;
    sp20 = M2C_FIELD(this, f64 *, 0x28);
    sp2C = var_f5_1750;
    var_f7_1848 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + ((*(f32 *) ((u8 *) &sp10 + 0xc)) * (*(f32 *) ((u8 *) &sp10 + 0xc))));
    if (var_f7_1848 > 0.000001f) {
        if (var_f7_1848 > 0.0f) {
            temp_f1_1853 = __frsqrte(var_f7_1848);
            temp_f1_1859 = 0.5 * temp_f1_1853 * -(((f64) var_f7_1848 * (temp_f1_1853 * temp_f1_1853)) - 3.0);
            temp_f1_1863 = 0.5 * temp_f1_1859 * -(((f64) var_f7_1848 * (temp_f1_1859 * temp_f1_1859)) - 3.0);
            var_f7_1848 = (f32) ((f64) var_f7_1848 * (0.5 * temp_f1_1863 * -(((f64) var_f7_1848 * (temp_f1_1863 * temp_f1_1863)) - 3.0)));
        } else if (var_f7_1848 < M2C_BITWISE(f32, 0.0)) {
            var_f7_1848 = __float_nan;
        } else {
            sp8 = var_f7_1848;
            temp_r5_1882 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r5_1882) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1892 = 1;
                } else {
                    var_r0_1892 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1892 = 5;
                } else {
                    var_r0_1892 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_1892 = 4;
                break;
            }
            if (var_r0_1892 == 1) {
                var_f7_1848 = __float_nan;
            }
        }
        var_f6_1826 = 1.0f / var_f7_1848;
    } else {
        var_f7_1848 = 0.0f;
    }
    temp_f5_1921 = (f32) sp18 * var_f6_1826;
    temp_f4_1923 = (*(f32 *) ((u8 *) &sp10 + 0xc)) * var_f6_1826;
    sp30 = var_f7_1848;
    temp_f3_1925 = (f32) sp20 * var_f6_1826;
    this->unk20 = temp_f5_1921;
    this->unk24 = temp_f4_1923;
    this->unk28 = temp_f3_1925;
    this->unk2C = 0.0f;
    M2C_FIELD(sret, f64 *, 0) = (f64) sp28;
    sp18 = temp_f5_1921;
    (*(f32 *) ((u8 *) &sp10 + 0xc)) = temp_f4_1923;
    sp20 = temp_f3_1925;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp30;
    return result;
}
#endif

void Matrix::SetRotationToNone() {
    this->unkC = 0.0f;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk0 = 1.0f;
    this->unk1C = 0.0f;
    this->unk18 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 1.0f;
    this->unk2C = 0.0f;
    this->unk24 = 0.0f;
    this->unk20 = 0.0f;
    this->unk28 = 1.0f;
}

void Matrix::SetZero() {
    this->unkC = 0.0f;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk0 = 0.0f;
    this->unk1C = 0.0f;
    this->unk18 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk2C = 0.0f;
    this->unk24 = 0.0f;
    this->unk20 = 0.0f;
    this->unk28 = 0.0f;
    this->unk38 = 0.0f;
    this->unk34 = 0.0f;
    this->unk30 = 0.0f;
    this->unk3C = 0.0f;
}

void Matrix::SetIdentity() {
    this->unkC = 0.0f;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk0 = 1.0f;
    this->unk1C = 0.0f;
    this->unk18 = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 1.0f;
    this->unk2C = 0.0f;
    this->unk24 = 0.0f;
    this->unk20 = 0.0f;
    this->unk28 = 1.0f;
    this->unk38 = 0.0f;
    this->unk34 = 0.0f;
    this->unk30 = 0.0f;
    this->unk3C = 1.0f;
}

void Matrix::CopyRotation(const Matrix *arg0) {
    this->unk0 = arg0->unk0;
    this->unk4 = arg0->unk4;
    this->unk8 = arg0->unk8;
    this->unkC = arg0->unkC;
    this->unk10 = arg0->unk10;
    this->unk14 = arg0->unk14;
    this->unk18 = arg0->unk18;
    this->unk1C = arg0->unk1C;
    this->unk20 = arg0->unk20;
    this->unk24 = arg0->unk24;
    this->unk28 = arg0->unk28;
    this->unk2C = arg0->unk2C;
}

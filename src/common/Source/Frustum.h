#ifndef COMMON_SOURCE_FRUSTUM_H
#define COMMON_SOURCE_FRUSTUM_H

#include <dolphin/types.h>

class BoundingVolume;
class Frustum;
class MKVector3;
class Matrix;

class Frustum {
public:
    void ApplyMatrix(Frustum *, Matrix *);
    s32 IsVisible(const Matrix *, const BoundingVolume *) const;
    s32 IsVisible(const BoundingVolume *) const;
    s32 IsVisible(const MKVector3 &, float) const;
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04c */ u8 pad4C[0xc];
    /* 0x058 */ f32 unk58;
    /* 0x05c */ u8 pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk50'
inline void Frustum::ApplyMatrix(Frustum *arg0, Matrix *arg1) {
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
    f64 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
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
    f32 spC;
    f32 sp8;
    f32 temp_f10_600;
    f32 temp_f10_623;
    f32 temp_f11_629;
    f32 temp_f3_495;
    f32 temp_f3_529;
    f32 temp_f3_651;
    f32 temp_f4_559;
    f32 temp_f5_617;
    f32 temp_f6_500;
    f32 temp_f6_588;
    f32 temp_f6_657;
    f32 temp_f7_509;
    f32 temp_f7_663;
    f32 temp_f8_535;
    f32 temp_f8_565;
    f32 temp_f9_541;
    f32 temp_f9_571;
    f32 temp_f9_594;

    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f64 *, 0x10);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f64 *, 0x18);
    M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(arg0, f64 *, 0x20);
    M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(arg0, f64 *, 0x28);
    M2C_FIELD(this, f64 *, 0x30) = (f64) M2C_FIELD(arg0, f64 *, 0x30);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(arg0, f64 *, 0x38);
    M2C_FIELD(this, f64 *, 0x40) = (f64) M2C_FIELD(arg0, f64 *, 0x40);
    M2C_FIELD(this, f64 *, 0x48) = (f64) M2C_FIELD(arg0, f64 *, 0x48);
    this->unk50 = arg0->unk50;
    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(arg0, f64 *, 0x58);
    this->unk60 = arg0->unk60;
    this->unk64 = arg0->unk64;
    M2C_FIELD(this, f32 *, 0x68) = (f32) M2C_FIELD(arg0, f32 *, 0x68);
    M2C_FIELD(this, f32 *, 0x6C) = (f32) M2C_FIELD(arg0, f32 *, 0x6C);
    temp_f3_495 = M2C_FIELD(this, f32 *, 0x54);
    temp_f6_500 = (f32) M2C_FIELD(this, f64 *, 0x50);
    temp_f7_509 = this->unk58;
    sp58 = arg1->unk30 + ((temp_f7_509 * arg1->unk20) + ((temp_f6_500 * arg1->unk0) + (temp_f3_495 * arg1->unk10)));
    sp5C = arg1->unk34 + ((temp_f7_509 * arg1->unk24) + ((temp_f6_500 * arg1->unk4) + (temp_f3_495 * arg1->unk14)));
    sp60 = arg1->unk38 + ((temp_f7_509 * arg1->unk28) + ((temp_f6_500 * arg1->unk8) + (temp_f3_495 * arg1->unk18)));
    this->unk50 = (f64) sp58;
    M2C_FIELD(this, f64 *, 0x58) = (f64) sp60;
    temp_f3_529 = this->unk4;
    temp_f8_535 = this->unk0;
    temp_f9_541 = this->unk8;
    spB8 = (f64) sp58;
    spC0 = (f64) sp60;
    sp48 = (temp_f9_541 * arg1->unk20) + ((temp_f8_535 * arg1->unk0) + (temp_f3_529 * arg1->unk10));
    sp4C = (temp_f9_541 * arg1->unk24) + ((temp_f8_535 * arg1->unk4) + (temp_f3_529 * arg1->unk14));
    sp50 = (temp_f9_541 * arg1->unk28) + ((temp_f8_535 * arg1->unk8) + (temp_f3_529 * arg1->unk18));
    M2C_FIELD(this, f64 *, 0) = (f64) sp48;
    M2C_FIELD(this, f64 *, 8) = (f64) sp50;
    temp_f4_559 = this->unk14;
    temp_f8_565 = this->unk10;
    temp_f9_571 = this->unk18;
    spA8 = (f64) sp48;
    sp38 = (temp_f9_571 * arg1->unk20) + ((temp_f8_565 * arg1->unk0) + (temp_f4_559 * arg1->unk10));
    sp3C = (temp_f9_571 * arg1->unk24) + ((temp_f8_565 * arg1->unk4) + (temp_f4_559 * arg1->unk14));
    sp40 = (temp_f9_571 * arg1->unk28) + ((temp_f8_565 * arg1->unk8) + (temp_f4_559 * arg1->unk18));
    M2C_FIELD(this, f64 *, 0x10) = (f64) sp38;
    M2C_FIELD(this, f64 *, 0x18) = (f64) sp40;
    temp_f6_588 = this->unk24;
    temp_f9_594 = this->unk20;
    temp_f10_600 = this->unk28;
    spB0 = (f64) sp50;
    sp28 = (temp_f10_600 * arg1->unk20) + ((temp_f9_594 * arg1->unk0) + (temp_f6_588 * arg1->unk10));
    sp2C = (temp_f10_600 * arg1->unk24) + ((temp_f9_594 * arg1->unk4) + (temp_f6_588 * arg1->unk14));
    sp30 = (temp_f10_600 * arg1->unk28) + ((temp_f9_594 * arg1->unk8) + (temp_f6_588 * arg1->unk18));
    M2C_FIELD(this, f64 *, 0x20) = (f64) sp28;
    M2C_FIELD(this, f64 *, 0x28) = (f64) sp30;
    temp_f5_617 = this->unk34;
    temp_f10_623 = this->unk30;
    temp_f11_629 = this->unk38;
    sp98 = (f64) sp38;
    sp18 = (temp_f11_629 * arg1->unk20) + ((temp_f10_623 * arg1->unk0) + (temp_f5_617 * arg1->unk10));
    sp1C = (temp_f11_629 * arg1->unk24) + ((temp_f10_623 * arg1->unk4) + (temp_f5_617 * arg1->unk14));
    sp20 = (temp_f11_629 * arg1->unk28) + ((temp_f10_623 * arg1->unk8) + (temp_f5_617 * arg1->unk18));
    M2C_FIELD(this, f64 *, 0x30) = (f64) sp18;
    spA0 = (f64) sp40;
    sp88 = (f64) sp28;
    sp90 = (f64) sp30;
    sp78 = (f64) sp18;
    sp80 = (f64) sp20;
    M2C_FIELD(this, f64 *, 0x38) = (f64) sp20;
    temp_f3_651 = this->unk44;
    temp_f6_657 = this->unk40;
    temp_f7_663 = this->unk48;
    sp8 = (temp_f7_663 * arg1->unk20) + ((temp_f6_657 * arg1->unk0) + (temp_f3_651 * arg1->unk10));
    spC = (temp_f7_663 * arg1->unk24) + ((temp_f6_657 * arg1->unk4) + (temp_f3_651 * arg1->unk14));
    sp10 = (temp_f7_663 * arg1->unk28) + ((temp_f6_657 * arg1->unk8) + (temp_f3_651 * arg1->unk18));
    M2C_FIELD(this, f64 *, 0x40) = (f64) sp8;
    sp68 = (f64) sp8;
    sp70 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x48) = (f64) sp10;
}
#endif

#endif  // COMMON_SOURCE_FRUSTUM_H

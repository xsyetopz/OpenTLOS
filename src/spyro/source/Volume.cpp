#include "spyro/source/Volume.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
u8 boundingVolume__6Volume[0x20] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

MKVector3 Volume::GetRandPos() {
    MKVector3 result;
    f32 x0;
    f32 y0;
    f32 z0;
    f32 ax;
    f32 ay;
    f32 az;

    x0 = M2C_FIELD(Volume::boundingVolume, f32 *, 0x18) * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    y0 = M2C_FIELD(Volume::boundingVolume, f32 *, 0x14) * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    z0 = M2C_FIELD(Volume::boundingVolume, f32 *, 0x10) * MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    ax = M2C_FIELD(Volume::boundingVolume, f32 *, 0x0) + z0;
    ay = M2C_FIELD(Volume::boundingVolume, f32 *, 0x4) + y0;
    az = M2C_FIELD(Volume::boundingVolume, f32 *, 0x8) + x0;
    result.unk0 = this->unk40.unk30 + ((az * this->unk40.unk20) + ((ax * this->unk40.unk0) + (ay * this->unk40.unk10)));
    result.unk4 = this->unk40.unk34 + ((az * this->unk40.unk24) + ((ax * this->unk40.unk4) + (ay * this->unk40.unk14)));
    result.unk8 = this->unk40.unk38 + ((az * this->unk40.unk28) + ((ax * this->unk40.unk8) + (ay * this->unk40.unk18)));
    return result;
}

void Volume::UpdateMatrix(Matrix &arg0) {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
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
    f32 temp_f0_138;
    f32 temp_f10_158;
    f32 temp_f11_164;
    f32 temp_f1_149;
    f32 temp_f2_156;
    f32 temp_f3_160;
    f32 temp_f4_142;
    f32 temp_f5_150;
    f32 temp_f6_157;
    f32 temp_f7_162;
    f32 temp_f8_143;
    f32 temp_f9_151;
    f32 var_f0_218;
    f32 var_f12_186;

    M2C_STRUCT_COPY((s32) (this + 0x3C) + 4, (s32) (&arg0 - 4) + 4, 0x40);
    ((Matrix *) this)->Inverse(&this->unk40);
    temp_f0_138 = this->unk40.unk10;
    sp68 = M2C_FIELD(Volume::boundingVolume, f64 *, 0);
    temp_f4_142 = this->unk40.unk14;
    temp_f8_143 = this->unk40.unk18;
    sp70 = M2C_FIELD(Volume::boundingVolume, f64 *, 8);
    temp_f1_149 = this->unk40.unk0;
    temp_f5_150 = this->unk40.unk4;
    temp_f9_151 = this->unk40.unk8;
    temp_f2_156 = this->unk40.unk20;
    temp_f6_157 = this->unk40.unk24;
    temp_f10_158 = this->unk40.unk28;
    temp_f3_160 = this->unk40.unk30;
    temp_f7_162 = this->unk40.unk34;
    temp_f11_164 = this->unk40.unk38;
    sp18 = temp_f3_160 + (((f32) sp70 * temp_f2_156) + (((f32) sp68 * temp_f1_149) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * temp_f0_138)));
    sp1C = temp_f7_162 + (((f32) sp70 * temp_f6_157) + (((f32) sp68 * temp_f5_150) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * temp_f4_142)));
    sp20 = temp_f11_164 + (((f32) sp70 * temp_f10_158) + (((f32) sp68 * temp_f9_151) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * temp_f8_143)));
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    sp28 = M2C_FIELD(Volume::boundingVolume, f64 *, 0) + M2C_FIELD(Volume::boundingVolume, f64 *, 0x10);
    var_f12_186 = (*(f32 *) ((u8 *) &sp68 + 0x4));
    sp58 = sp28;
    sp30 = (f32) M2C_FIELD(Volume::boundingVolume, f64 *, 8) + M2C_FIELD(Volume::boundingVolume, f32 *, 0x18);
    sp60 = (f64) sp30;
    sp8 = temp_f3_160 + (((f32) sp60 * temp_f2_156) + (((f32) sp58 * temp_f1_149) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_f0_138)));
    spC = temp_f7_162 + (((f32) sp60 * temp_f6_157) + (((f32) sp58 * temp_f5_150) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_f4_142)));
    sp10 = temp_f11_164 + (((f32) sp60 * temp_f10_158) + (((f32) sp58 * temp_f9_151) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * temp_f8_143)));
    sp58 = (f64) sp8;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp60 = (f64) sp10;
    if (var_f12_186 < (*(f32 *) ((u8 *) &sp58 + 0x4))) {
        var_f0_218 = var_f12_186;
    } else {
        var_f0_218 = (*(f32 *) ((u8 *) &sp58 + 0x4));
    }
    this->unk80 = var_f0_218;
    if (var_f12_186 > (*(f32 *) ((u8 *) &sp58 + 0x4))) {

    } else {
        var_f12_186 = (*(f32 *) ((u8 *) &sp58 + 0x4));
    }
    this->unk84 = var_f12_186;
}

void Volume::Init(Matrix &arg0) {
    UpdateMatrix(arg0);
}

void Volume_cpp::__sinit() {
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp18 = -0.5f;
    sp20 = -0.5f;
    sp1C = -0.5f;
    sp10 = 1.0f;
    sp8 = 1.0f;
    M2C_FIELD(Volume::boundingVolume, f64 *, 0) = (f64) sp18;
    spC = 1.0f;
    M2C_FIELD(Volume::boundingVolume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(Volume::boundingVolume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(Volume::boundingVolume, f64 *, 0x18) = (f64) sp10;
}

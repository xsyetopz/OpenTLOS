#include "spyro/source/Volume.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

extern s32 gViewSeed;
#if 0 // DRAFT: expression syntax error
static Volume boundingVolume__6Volume;              /* type too large by 0xAC; unable to generate initializer: confusing struct layout */

void Volume::GetRandPos() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_40;
    f32 temp_f30_30;
    f32 temp_f31_38;
    void *temp_r31_22;

    temp_r31_22 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_f30_30 = boundingVolume.unk18 * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    temp_f31_38 = boundingVolume.unk14 * MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    temp_f1_40 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    sp30 = temp_f30_30;
    sp2C = temp_f31_38;
    sp40 = (f64) sp30;
    sp28 = boundingVolume.unk10 * temp_f1_40;
    sp38 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp48 = sp18;
    sp20 = boundingVolume.unk8 + (f32) sp40;
    sp50 = (f64) sp20;
    spC = M2C_FIELD(temp_r31_22, f32 *, 0x74) + (((f32) sp50 * M2C_FIELD(temp_r31_22, f32 *, 0x64)) + (((f32) sp48 * M2C_FIELD(temp_r31_22, f32 *, 0x44)) + (unksp4C * M2C_FIELD(temp_r31_22, f32 *, 0x54))));
    sp8 = M2C_FIELD(temp_r31_22, f32 *, 0x70) + (((f32) sp50 * M2C_FIELD(temp_r31_22, f32 *, 0x60)) + (((f32) sp48 * M2C_FIELD(temp_r31_22, f32 *, 0x40)) + (unksp4C * M2C_FIELD(temp_r31_22, f32 *, 0x50))));
    sp10 = M2C_FIELD(temp_r31_22, f32 *, 0x78) + (((f32) sp50 * M2C_FIELD(temp_r31_22, f32 *, 0x68)) + (((f32) sp48 * M2C_FIELD(temp_r31_22, f32 *, 0x48)) + (unksp4C * M2C_FIELD(temp_r31_22, f32 *, 0x58))));
    this->unk0 = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk3C'
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

    M2C_STRUCT_COPY((s32) &this->unk3C + 4, (s32) (&arg0 - 4) + 4, 0x40);
    Matrix::Inverse(&this->unk40);
    temp_f0_138 = this->unk40.unk10;
    sp68 = boundingVolume.unk0;
    temp_f4_142 = this->unk40.unk14;
    temp_f8_143 = this->unk40.unk18;
    sp70 = M2C_FIELD(&boundingVolume, f64 *, 8);
    temp_f1_149 = this->unk40.unk0;
    temp_f5_150 = this->unk40.unk4;
    temp_f9_151 = this->unk40.unk8;
    temp_f2_156 = this->unk40.unk20;
    temp_f6_157 = this->unk40.unk24;
    temp_f10_158 = this->unk40.unk28;
    temp_f3_160 = this->unk40.unk30;
    temp_f7_162 = this->unk40.unk34;
    temp_f11_164 = this->unk40.unk38;
    sp18 = temp_f3_160 + (((f32) sp70 * temp_f2_156) + (((f32) sp68 * temp_f1_149) + (unksp6C * temp_f0_138)));
    sp1C = temp_f7_162 + (((f32) sp70 * temp_f6_157) + (((f32) sp68 * temp_f5_150) + (unksp6C * temp_f4_142)));
    sp20 = temp_f11_164 + (((f32) sp70 * temp_f10_158) + (((f32) sp68 * temp_f9_151) + (unksp6C * temp_f8_143)));
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f13, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f12, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f12, $f13, $f12 */);
    var_f12_186 = unksp6C;
    sp58 = sp28;
    sp30 = boundingVolume.unk8 + boundingVolume.unk18;
    sp60 = (f64) sp30;
    sp8 = temp_f3_160 + (((f32) sp60 * temp_f2_156) + (((f32) sp58 * temp_f1_149) + (unksp5C * temp_f0_138)));
    spC = temp_f7_162 + (((f32) sp60 * temp_f6_157) + (((f32) sp58 * temp_f5_150) + (unksp5C * temp_f4_142)));
    sp10 = temp_f11_164 + (((f32) sp60 * temp_f10_158) + (((f32) sp58 * temp_f9_151) + (unksp5C * temp_f8_143)));
    sp58 = (f64) sp8;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp60 = (f64) sp10;
    if (var_f12_186 < unksp5C) {
        var_f0_218 = var_f12_186;
    } else {
        var_f0_218 = unksp5C;
    }
    this->unk40.unk40 = var_f0_218;
    if (var_f12_186 > unksp5C) {

    } else {
        var_f12_186 = unksp5C;
    }
    this->unk40.unk44 = var_f12_186;
}
#endif

void Volume::Init(Matrix &arg0) {
    UpdateMatrix(arg0);
}

#if 0 // DRAFT: undefined identifier 'boundingVolume'
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
    boundingVolume.unk0 = (f64) sp18;
    spC = 1.0f;
    M2C_FIELD(&boundingVolume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(&boundingVolume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(&boundingVolume, f64 *, 0x18) = (f64) sp10;
}
#endif

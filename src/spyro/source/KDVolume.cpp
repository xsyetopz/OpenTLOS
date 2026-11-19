#include "spyro/source/KDVolume.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

u8 boundingVolume__8KDVolume[0x20] = {
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

#if 0 // DRAFT: undefined identifier 'unk3C'
void KDVolume::UpdateMatrix(Matrix &arg0) {
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
    f32 temp_f0_37;
    f32 temp_f10_57;
    f32 temp_f11_63;
    f32 temp_f1_48;
    f32 temp_f2_55;
    f32 temp_f3_59;
    f32 temp_f4_41;
    f32 temp_f5_49;
    f32 temp_f6_56;
    f32 temp_f7_61;
    f32 temp_f8_42;
    f32 temp_f9_50;
    f32 var_f0_117;
    f32 var_f12_85;

    M2C_STRUCT_COPY((s32) &this->unk3C + 4, (s32) (&arg0 - 4) + 4, 0x40);
    Matrix::Inverse(&this->unk40);
    temp_f0_37 = this->unk40.unk10;
    sp68 = M2C_FIELD(KDVolume::boundingVolume, f64 *, 0);
    temp_f4_41 = this->unk40.unk14;
    temp_f8_42 = this->unk40.unk18;
    sp70 = M2C_FIELD(KDVolume::boundingVolume, f64 *, 8);
    temp_f1_48 = this->unk40.unk0;
    temp_f5_49 = this->unk40.unk4;
    temp_f9_50 = this->unk40.unk8;
    temp_f2_55 = this->unk40.unk20;
    temp_f6_56 = this->unk40.unk24;
    temp_f10_57 = this->unk40.unk28;
    temp_f3_59 = this->unk40.unk30;
    temp_f7_61 = this->unk40.unk34;
    temp_f11_63 = this->unk40.unk38;
    sp18 = temp_f3_59 + (((f32) sp70 * temp_f2_55) + (((f32) sp68 * temp_f1_48) + (unksp6C * temp_f0_37)));
    sp1C = temp_f7_61 + (((f32) sp70 * temp_f6_56) + (((f32) sp68 * temp_f5_49) + (unksp6C * temp_f4_41)));
    sp20 = temp_f11_63 + (((f32) sp70 * temp_f10_57) + (((f32) sp68 * temp_f9_50) + (unksp6C * temp_f8_42)));
    sp48 = (f64) sp18;
    sp50 = (f64) sp20;
    sp68 = (f64) sp18;
    sp70 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f13, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f12, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f12, $f13, $f12 */);
    var_f12_85 = unksp6C;
    sp58 = sp28;
    sp30 = (f32) M2C_FIELD(KDVolume::boundingVolume, f64 *, 8) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x18);
    sp60 = (f64) sp30;
    sp8 = temp_f3_59 + (((f32) sp60 * temp_f2_55) + (((f32) sp58 * temp_f1_48) + (unksp5C * temp_f0_37)));
    spC = temp_f7_61 + (((f32) sp60 * temp_f6_56) + (((f32) sp58 * temp_f5_49) + (unksp5C * temp_f4_41)));
    sp10 = temp_f11_63 + (((f32) sp60 * temp_f10_57) + (((f32) sp58 * temp_f9_50) + (unksp5C * temp_f8_42)));
    sp58 = (f64) sp8;
    sp38 = (f64) sp8;
    sp40 = (f64) sp10;
    sp60 = (f64) sp10;
    if (var_f12_85 < unksp5C) {
        var_f0_117 = var_f12_85;
    } else {
        var_f0_117 = unksp5C;
    }
    this->unk80 = var_f0_117;
    if (var_f12_85 > unksp5C) {

    } else {
        var_f12_85 = unksp5C;
    }
    this->unk84 = var_f12_85;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp4C'
void KDVolume::GetCenterPos() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;

    sp28 = (0.5f * M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x10)) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0);
    sp2C = (0.5f * M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x14)) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 4);
    sp30 = (0.5f * M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x18)) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 8);
    sp48 = (f64) sp28;
    sp50 = (f64) sp30;
    sp18 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x70) + (((f32) sp50 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x60)) + (((f32) sp48 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x40)) + (unksp4C * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x50))));
    sp1C = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x74) + (((f32) sp50 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x64)) + (((f32) sp48 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x44)) + (unksp4C * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x54))));
    sp20 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x78) + (((f32) sp50 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x68)) + (((f32) sp48 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x48)) + (unksp4C * M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x58))));
    this->unk0 = (f64) sp18;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp8 = (f64) sp18;
    sp10 = (f64) sp20;
    this->unk8 = (f64) sp20;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
s32 KDVolume::IsWithinXZ(const MKVector3 &arg0, float *arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f6_213;
    f32 temp_f7_217;
    f32 temp_f8_223;

    temp_f6_213 = arg0.unk4;
    temp_f7_217 = arg0.unk0;
    temp_f8_223 = arg0.unk8;
    sp8 = this->unk30 + ((temp_f8_223 * this->unk20) + ((temp_f7_217 * M2C_FIELD(this, f32 *, 0)) + (temp_f6_213 * this->unk10)));
    spC = this->unk34 + ((temp_f8_223 * this->unk24) + ((temp_f7_217 * M2C_FIELD(this, f32 *, 4)) + (temp_f6_213 * this->unk14)));
    sp18 = (f64) sp8;
    sp10 = this->unk38 + ((temp_f8_223 * this->unk28) + ((temp_f7_217 * M2C_FIELD(this, f32 *, 8)) + (temp_f6_213 * this->unk18)));
    sp20 = (f64) sp10;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if ((f32) sp18 == M2C_FIELD(KDVolume::boundingVolume, f32 *, 0)) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((f32) sp18 == (M2C_FIELD(KDVolume::boundingVolume, f32 *, 0) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x10))) {
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((f32) sp20 == M2C_FIELD(KDVolume::boundingVolume, f32 *, 8)) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if ((f32) sp20 == (M2C_FIELD(KDVolume::boundingVolume, f32 *, 8) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x18))) {
                    if (arg1 != NULL) {
                        *arg1 = this->unk84;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
s32 KDVolume::IsWithin(const MKVector3 &arg0, float *arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_286;
    f32 temp_f3_285;
    f32 temp_f7_299;
    f32 temp_f8_304;
    u8 var_r0_295;

    temp_f3_285 = arg0.unk4;
    temp_f0_286 = this->unk84;
    if ((temp_f3_285 < temp_f0_286) && (temp_f3_285 > this->unk80)) {
        var_r0_295 = 0;
        temp_f7_299 = arg0.unk0;
        temp_f8_304 = arg0.unk8;
        sp8 = this->unk30 + ((temp_f8_304 * this->unk20) + ((temp_f7_299 * M2C_FIELD(this, f32 *, 0)) + (temp_f3_285 * this->unk10)));
        spC = this->unk34 + ((temp_f8_304 * this->unk24) + ((temp_f7_299 * M2C_FIELD(this, f32 *, 4)) + (temp_f3_285 * this->unk14)));
        sp10 = this->unk38 + ((temp_f8_304 * this->unk28) + ((temp_f7_299 * M2C_FIELD(this, f32 *, 8)) + (temp_f3_285 * this->unk18)));
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if ((f32) sp18 == M2C_FIELD(KDVolume::boundingVolume, f32 *, 0)) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((f32) sp18 == (M2C_FIELD(KDVolume::boundingVolume, f32 *, 0) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x10))) {
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (unksp1C == M2C_FIELD(KDVolume::boundingVolume, f32 *, 4)) {
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (unksp1C == (M2C_FIELD(KDVolume::boundingVolume, f32 *, 4) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x14))) {
                        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                        if ((f32) sp20 == M2C_FIELD(KDVolume::boundingVolume, f32 *, 8)) {
                            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                            if ((f32) sp20 == (M2C_FIELD(KDVolume::boundingVolume, f32 *, 8) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x18))) {
                                var_r0_295 = 1;
                            }
                        }
                    }
                }
            }
        }
        if (var_r0_295 != 0) {
            if (arg1 != NULL) {
                *arg1 = temp_f0_286;
            }
            return 1;
        }
        goto block_13;
    }
block_13:
    return 0;
}
#endif

void KDVolume::Deinit() {

}

void KDVolume::Init(Matrix &arg0) {
    UpdateMatrix(arg0);
}

void KDVolume_cpp::__sinit() {
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
    M2C_FIELD(KDVolume::boundingVolume, f64 *, 0) = (f64) sp18;
    spC = 1.0f;
    M2C_FIELD(KDVolume::boundingVolume, f64 *, 8) = (f64) sp20;
    M2C_FIELD(KDVolume::boundingVolume, f64 *, 0x10) = (f64) sp8;
    M2C_FIELD(KDVolume::boundingVolume, f64 *, 0x18) = (f64) sp10;
}

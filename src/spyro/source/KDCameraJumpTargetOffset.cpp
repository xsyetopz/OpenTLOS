#include "spyro/source/KDCameraJumpTargetOffset.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDCameraHeroData'
void KDCameraJumpTargetOffset::Update(KDCameraHeroData &arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f0_205;
    f32 temp_f0_75;
    f32 temp_f1_167;
    f32 temp_f1_187;
    f32 temp_f2_166;
    f32 temp_f3_164;
    f32 temp_f5_162;
    f32 var_f3_169;
    f32 var_f4_155;
    f32 var_f5_70;
    f64 temp_f3_63;
    f64 temp_f4_62;
    u8 temp_r3_24;
    u8 temp_r3_82;
    u8 var_r0_113;
    u8 var_r0_183;
    u8 var_r0_36;
    u8 var_r0_85;

    if (!(((u8) this->unk0 >> 7U) & 1)) {
        this->unkC = 0.0f;
        return;
    }
    temp_r3_24 = arg0.unk94;
    if ((temp_r3_24 != 0) && ((s32) this->unk4 == 0)) {
        if (this->unk14 == 0.0f) {
            if (temp_r3_24 == 0) {
                var_r0_36 = 0;
            } else {
                sp68 = arg0.unkC8;
                sp58 = M2C_FIELD(&arg0, f64 *, 0x40);
                sp70 = M2C_FIELD(&arg0, f64 *, 0xD0);
                sp60 = M2C_FIELD(&arg0, f64 *, 0x48);
                var_r0_36 = (*(f32 *) ((u8 *) &sp58 + 0x4)) > (*(f32 *) ((u8 *) &sp68 + 0x4));
            }
            if (var_r0_36 != 0) {
                Enter(arg0);
            }
        }
        if (((u8) this->unk0 >> 6U) & 1) {
            temp_f4_62 = M2C_FIELD(&arg0, f64 *, 0x40);
            temp_f3_63 = M2C_FIELD(&arg0, f64 *, 0x48);
            sp78 = temp_f4_62;
            var_f5_70 = 0.0f;
            sp8 = temp_f4_62;
            sp10 = temp_f3_63;
            sp80 = temp_f3_63;
            temp_f0_75 = ((this->unk14 - (*(f32 *) ((u8 *) &sp78 + 0x4))) / this->unk8) * this->unk10;
            if (var_f5_70 < temp_f0_75) {

            } else {
                var_f5_70 = temp_f0_75;
            }
            temp_r3_82 = arg0.unk94;
            if (temp_r3_82 == 0) {
                var_r0_85 = 0;
            } else {
                sp48 = arg0.unkC8;
                sp38 = sp8;
                sp50 = M2C_FIELD(&arg0, f64 *, 0xD0);
                sp40 = sp10;
                var_r0_85 = (*(f32 *) ((u8 *) &sp38 + 0x4)) > (*(f32 *) ((u8 *) &sp48 + 0x4));
            }
            if (var_r0_85 != 0) {
                if (this->unkC >= var_f5_70) {
                    this->unkC = var_f5_70;
                }
            } else {
                if (temp_r3_82 == 0) {
                    var_r0_113 = 0;
                } else {
                    sp28 = arg0.unkC8;
                    sp18 = sp8;
                    sp30 = M2C_FIELD(&arg0, f64 *, 0xD0);
                    sp20 = sp10;
                    var_r0_113 = (*(f32 *) ((u8 *) &sp18 + 0x4)) < (*(f32 *) ((u8 *) &sp28 + 0x4));
                }
                if (var_r0_113 != 0) {
                    if (this->unkC <= var_f5_70) {
                        this->unkC = var_f5_70;
                    }
                } else {
                    this->unkC = var_f5_70;
                }
            }
        }
    } else if (((s32) this->unk4 == 2) && (((u8) this->unk0 >> 6U) & 1)) {
        this->unk14 = 0.0f;
        var_f4_155 = 0.5f * (4.0f * gUpdateTimeDelta);
        if (var_f4_155 < 1.0f) {

        } else {
            var_f4_155 = 1.0f;
        }
        temp_f5_162 = this->unkC;
        temp_f3_164 = -((temp_f5_162 * var_f4_155) - temp_f5_162);
        temp_f2_166 = 400.0f * gUpdateTimeDelta;
        temp_f1_167 = -400.0f * gUpdateTimeDelta;
        var_f3_169 = temp_f5_162 - -((temp_f3_164 * var_f4_155) - temp_f3_164);
        if (var_f3_169 < temp_f2_166) {

        } else {
            var_f3_169 = temp_f2_166;
        }
        if (var_f3_169 > temp_f1_167) {

        } else {
            var_f3_169 = temp_f1_167;
        }
        var_r0_183 = 0;
        this->unkC -= var_f3_169;
        temp_f1_187 = this->unkC;
        if ((temp_f1_187 >= -0.1f) && (temp_f1_187 <= 0.1f)) {
            var_r0_183 = 1;
        }
        if (var_r0_183 != 0) {
            Exit(arg0);
        }
    }
    temp_f0_205 = -this->unk10;
    if (this->unkC < temp_f0_205) {
        this->unkC = temp_f0_205;
    }
}
#endif

void KDCameraJumpTargetOffset::Exit(KDCameraHeroData &arg0) {
    this->unk0 &= ~0x40;
    this->unkC = 0.0f;
    this->unk18 = 0.0f;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDCameraHeroData'
void KDCameraJumpTargetOffset::Enter(KDCameraHeroData &arg0) {
    f64 sp10;
    f64 sp8;

    this->unk0 |= 0x40;
    sp8 = arg0.unkC8;
    sp10 = M2C_FIELD(&arg0, f64 *, 0xD0);
    this->unk14 = (*(f32 *) ((u8 *) &sp8 + 0x4));
}
#endif

void KDCameraJumpTargetOffset::ClearData() {
    this->unk0 &= ~0x80;
    this->unk0 &= ~0x40;
    this->unkC = 0.0f;
    this->unk4 = 2;
    this->unk10 = 100.0f;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
}

void KDCameraJumpTargetOffset::Init(float arg0) {
    ClearData();
    this->unk8 = arg0;
}

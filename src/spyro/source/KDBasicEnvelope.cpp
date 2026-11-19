#include "spyro/source/KDBasicEnvelope.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal operand
f32 KDBasicEnvelope::GetValue(float arg0) {
    f32 temp_f2_33;
    f32 temp_f2_43;
    f32 temp_f3_70;
    f32 temp_f5_78;
    f32 temp_f7_69;
    f32 var_f1_0;
    s32 temp_r0_21;
    s32 var_ctr_54;
    s32 var_r4_53;
    s32 var_r5_52;
    void *temp_r4_68;

    var_f1_0 = arg0;
    if (var_f1_0 < 0.0f) {
        var_f1_0 = 0.0f;
    }
    if (var_f1_0 > 1.0f) {
        var_f1_0 = 1.0f;
    }
    temp_r0_21 = this->unk0;
    if (temp_r0_21 == 0) {
        return 0.0f;
    }
    if ((temp_r0_21 == 1) || (var_f1_0 == 0.0f)) {
        temp_f2_33 = this->unk4;
        return (this->unk10 * (this->unk8 - temp_f2_33)) + temp_f2_33;
    }
    if (var_f1_0 == 1.0f) {
        temp_f2_43 = this->unk4;
        return (M2C_FIELD((this + (temp_r0_21 * 8)), f32 *, 8) * (this->unk8 - temp_f2_43)) + temp_f2_43;
    }
    var_r5_52 = 0;
    var_r4_53 = 0;
    var_ctr_54 = temp_r0_21;
    if (temp_r0_21 > 0) {
loop_12:
        if (!(var_f1_0 < *(this + (var_r4_53 + 0xC)))) {
            var_r5_52 += 1;
            var_r4_53 += 8;
            var_ctr_54 -= 1;
            if (var_ctr_54 != 0) {
                goto loop_12;
            }
        }
    }
    temp_r4_68 = this + (var_r5_52 * 8);
    temp_f7_69 = this->unk4;
    temp_f3_70 = M2C_FIELD(temp_r4_68, f32 *, 4);
    temp_f5_78 = (var_f1_0 - temp_f3_70) / (M2C_FIELD(temp_r4_68, f32 *, 0xC) - temp_f3_70);
    return ((this->unk8 - temp_f7_69) * ((M2C_FIELD(temp_r4_68, f32 *, 8) * (1.0f - temp_f5_78)) + (M2C_FIELD(temp_r4_68, f32 *, 0x10) * temp_f5_78))) + temp_f7_69;
}
#endif

void KDBasicEnvelope::Add(float arg0, float arg1) {
    s32 temp_r4_97;

    M2C_FIELD((this + (this->unk0 * 8)), f32 *, 0xC) = arg0;
    M2C_FIELD((this + (this->unk0 * 8)), f32 *, 0x10) = arg1;
    temp_r4_97 = this->unk0;
    if (temp_r4_97 < 9) {
        this->unk0 = temp_r4_97 + 1;
    }
}

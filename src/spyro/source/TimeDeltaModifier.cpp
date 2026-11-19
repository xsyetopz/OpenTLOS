#include "spyro/source/TimeDeltaModifier.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

void TimeDeltaModifier::Disable(int arg0) {
    if ((s32) this->unk20 == arg0) {
        this->unk24 = 0;
        this->unk1C = this->unk10;
        this->unk14 = 0.0f;
        this->unk0 = this->unk4;
        this->unk8 = 1.0f;
    }
}

s32 TimeDeltaModifier::Enable(float arg0, float arg1, float arg2, float arg3) {
    s32 temp_r0_40;

    this->unk0 = this->unk4;
    this->unk8 = arg0;
    this->unkC = arg1;
    this->unk1C = arg1;
    this->unk10 = arg2;
    this->unk14 = arg3;
    this->unk24 = 1;
    temp_r0_40 = this->unk20 + 1;
    this->unk20 = temp_r0_40;
    return temp_r0_40;
}

void TimeDeltaModifier::End() {
    gUpdateTimeDelta = this->unk18;
}

void TimeDeltaModifier::Begin() {
    f32 temp_f1_137;
    f32 temp_f1_83;
    f32 temp_f2_115;
    f32 temp_f2_60;
    f32 temp_f2_91;
    f32 var_f0_116;
    f32 var_f0_92;
    f32 var_f2_111;

    this->unk18 = gUpdateTimeDelta;
    temp_f2_60 = this->unk14;
    if (temp_f2_60 > 0.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk1C == 0.0f) {
            this->unk14 = temp_f2_60 - this->unk18;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (this->unk14 == 0.0f) {
                this->unk24 = 0;
                this->unk1C = this->unk10;
                this->unk0 = this->unk4;
                this->unk8 = 1.0f;
            }
        }
    }
    temp_f1_83 = this->unk1C;
    if (temp_f1_83 > 0.0f) {
        if ((u8) this->unk24 != 0) {
            temp_f2_91 = this->unkC;
            var_f0_92 = temp_f1_83 - this->unk18;
            if (var_f0_92 < temp_f2_91) {

            } else {
                var_f0_92 = temp_f2_91;
            }
            if (var_f0_92 > 0.0f) {

            } else {
                var_f0_92 = 0.0f;
            }
            this->unk1C = var_f0_92;
            var_f2_111 = 1.0f - (this->unk1C / this->unkC);
        } else {
            temp_f2_115 = this->unk10;
            var_f0_116 = temp_f1_83 - this->unk18;
            if (var_f0_116 < temp_f2_115) {

            } else {
                var_f0_116 = temp_f2_115;
            }
            if (var_f0_116 > 0.0f) {

            } else {
                var_f0_116 = 0.0f;
            }
            this->unk1C = var_f0_116;
            var_f2_111 = 1.0f - (this->unk1C / this->unk10);
        }
        temp_f1_137 = this->unk0;
        this->unk4 = (var_f2_111 * (this->unk8 - temp_f1_137)) + temp_f1_137;
        /* Duplicate return node #22. Try simplifying control flow for better match */
        gUpdateTimeDelta = this->unk18 * this->unk4;
        return;
    }
    this->unk4 = this->unk8;
    if ((u8) this->unk24 != 0) {
        gUpdateTimeDelta = this->unk18 * this->unk4;
    }
}

void TimeDeltaModifier::Reset() {
    if (this->unk18 == 0.0f) {
        this->unk18 = gUpdateTimeDelta;
    }
    gUpdateTimeDelta = this->unk18;
    this->unk8 = 1.0f;
    this->unk4 = 1.0f;
    this->unkC = 0.0f;
    this->unk10 = 0.0f;
    this->unk14 = 0.0f;
    this->unk1C = 0.0f;
    this->unk20 = 0;
    this->unk24 = 0;
}

void TimeDeltaModifier::Init() {
    this->unk18 = 0.0f;
    Reset();
}

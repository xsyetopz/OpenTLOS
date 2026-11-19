#ifndef SPYRO_SOURCE_KDINPUT_H
#define SPYRO_SOURCE_KDINPUT_H

#include <dolphin/types.h>

class KDInput;
class MKVector3;

class KDInput {
public:
    f32 GetRightMag(void);
    f32 GetLeftMag(void);
    f32 RumblePlay3D(float, float, float, MKVector3 *, float, char, float, bool);
    void RumbleStop(void);
    void RumblePlay(float, float, float, char, float, bool);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'MKInputDevices'
inline f32 KDInput::GetRightMag() {
    f32 temp_f1_10132;
    f32 temp_ret_10128;
    f32 var_f1_10121;
    f32 var_f31_10099;
    u8 var_r3_10087;
    u8 var_r3_10110;

    var_r3_10087 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r3_10087 = 1;
    }
    if (var_r3_10087 != 0) {
        var_f31_10099 = 0.0f;
    } else {
        var_f31_10099 = MKInput_GetState(0x12, (MKInputDevices) this->unk0, NULL, NULL);
    }
    var_r3_10110 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r3_10110 = 1;
    }
    if (var_r3_10110 != 0) {
        var_f1_10121 = 0.0f;
    } else {
        temp_ret_10128 = MKInput_GetState(0x13, (MKInputDevices) this->unk0, NULL, NULL);
        var_f1_10121 = temp_ret_10128;
        var_r3_10110 = M2C_BITWISE(u8, temp_ret_10128);
    }
    temp_f1_10132 = var_r3_10110->sqrtf((var_f1_10121 * var_f1_10121) + (var_f31_10099 * var_f31_10099));
    if (temp_f1_10132 < 1.0f) {
        return temp_f1_10132;
    }
    return 1.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKInputDevices'
inline f32 KDInput::GetLeftMag() {
    f32 temp_f1_5020;
    f32 temp_ret_5016;
    f32 var_f1_5009;
    f32 var_f31_4987;
    u8 var_r3_4975;
    u8 var_r3_4998;

    var_r3_4975 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r3_4975 = 1;
    }
    if (var_r3_4975 != 0) {
        var_f31_4987 = 0.0f;
    } else {
        var_f31_4987 = MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
    }
    var_r3_4998 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r3_4998 = 1;
    }
    if (var_r3_4998 != 0) {
        var_f1_5009 = 0.0f;
    } else {
        temp_ret_5016 = MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
        var_f1_5009 = temp_ret_5016;
        var_r3_4998 = M2C_BITWISE(u8, temp_ret_5016);
    }
    temp_f1_5020 = var_r3_4998->sqrtf((var_f1_5009 * var_f1_5009) + (var_f31_4987 * var_f31_4987));
    if (temp_f1_5020 < 1.0f) {
        return temp_f1_5020;
    }
    return 1.0f;
}
#endif

#endif  // SPYRO_SOURCE_KDINPUT_H

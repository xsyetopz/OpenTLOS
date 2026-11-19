#include "spyro/source/InputModifier.h"
#include "common/Source/MKInput.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

s32 InputModifier::Update() {
    this->unkC -= gUpdateTimeDelta;
    if (this->unkC < 0.0f) {
        this->unk8 = 0;
    }
    return 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'long' to
f32 InputModifier::GetRightX() {
    f32 var_f1_69;
    u8 var_r4_36;
    u8 var_r4_58;

    if ((u8) this->unk8 == 0) {
        var_r4_36 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r4_36 = 1;
        }
        if (var_r4_36 != 0) {
            return 0.0f;
        }
        return MKInput_GetState(0x13, (MKInputDevices) this->unk0, NULL, NULL);
    }
    var_r4_58 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r4_58 = 1;
    }
    if (var_r4_58 != 0) {
        var_f1_69 = 0.0f;
    } else {
        var_f1_69 = MKInput_GetState(0x13, (MKInputDevices) this->unk0, NULL, NULL);
    }
    return -var_f1_69;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
f32 InputModifier::GetLeftY() {
    f32 var_f1_129;
    u8 var_r4_118;
    u8 var_r4_96;

    if ((u8) this->unk8 == 0) {
        var_r4_96 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r4_96 = 1;
        }
        if (var_r4_96 != 0) {
            return 0.0f;
        }
        return MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
    }
    var_r4_118 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r4_118 = 1;
    }
    if (var_r4_118 != 0) {
        var_f1_129 = 0.0f;
    } else {
        var_f1_129 = MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
    }
    return -var_f1_129;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
f32 InputModifier::GetLeftX() {
    f32 var_f1_189;
    u8 var_r4_156;
    u8 var_r4_178;

    if ((u8) this->unk8 == 0) {
        var_r4_156 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r4_156 = 1;
        }
        if (var_r4_156 != 0) {
            return 0.0f;
        }
        return MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
    }
    var_r4_178 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r4_178 = 1;
    }
    if (var_r4_178 != 0) {
        var_f1_189 = 0.0f;
    } else {
        var_f1_189 = MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
    }
    return -var_f1_189;
}
#endif

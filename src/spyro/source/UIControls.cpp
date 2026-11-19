#include "spyro/source/UIControls.h"
#include "common/Source/MKInput.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
static UIInputTracker allControllers;
static s32 currentController = -1;

#if 0 // DRAFT: undefined identifier 'unk1D'
void UIControls_Ignore(bool arg0) {
    allControllers.unk1D = arg0;
}
#endif

void UIControls_Reset() {

}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKInputDevices'
void UIControls_SetDevice(MKInputDevices arg0) {
    currentController = (s32) arg0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void UIControls_Init() {
    allControllers.Init((MKInputDevices) 0);
    currentController = 0;
}
#endif

void UIControls_Update() {
    allControllers.Update();
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'FrontEndControls'
s32 UIControls_Held(FrontEndControls arg0, int arg1) {
    UIInputTracker *temp_r5_80;
    f32 var_f1_92;
    s32 var_r4_0;
    u8 var_r4_79;

    var_r4_0 = arg1;
    if ((var_r4_0 < 0) || (var_r4_0 >= 1)) {
        var_r4_0 = currentController;
    }
    var_r4_79 = 0;
    temp_r5_80 = &(&allControllers)[var_r4_0];
    if (((u8) temp_r5_80->unk5 != 0) || ((u8) temp_r5_80->unk4 != 0)) {
        var_r4_79 = 1;
    }
    if (var_r4_79 != 0) {
        var_f1_92 = 0.0f;
    } else {
        var_f1_92 = MKInput_GetState((s32) arg0, (MKInputDevices) temp_r5_80->unk0, NULL, NULL);
    }
    return var_f1_92 != 0.0f;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'FrontEndControls'
s32 UIControls_Pressed(FrontEndControls arg0, int arg1) {
    UIInputTracker *temp_r5_128;
    s32 var_r4_0;
    u8 var_r4_127;

    var_r4_0 = arg1;
    if ((var_r4_0 < 0) || (var_r4_0 >= 1)) {
        var_r4_0 = currentController;
    }
    var_r4_127 = 0;
    temp_r5_128 = &(&allControllers)[var_r4_0];
    if (((u8) temp_r5_128->unk5 != 0) || ((u8) temp_r5_128->unk4 != 0)) {
        var_r4_127 = 1;
    }
    if (var_r4_127 != 0) {
        return 0;
    }
    return MKInput_Pressed((s32) arg0, (MKInputDevices) temp_r5_128->unk0);
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'FrontEndControls'
u8 UIControls_DirectionPressed(FrontEndControls arg0, int arg1) {
    UIInputTracker *temp_r4_165;
    s32 var_r4_0;

    var_r4_0 = arg1;
    if ((var_r4_0 < 0) || (var_r4_0 >= 1)) {
        var_r4_0 = currentController;
    }
    temp_r4_165 = &(&allControllers)[var_r4_0];
    if ((u8) temp_r4_165->unk1D == 0) {
        return M2C_FIELD((temp_r4_165 + (s32) arg0), u8 *, 0x14);
    }
    return 0U;
}
#endif

void *UIInput(int arg0) {
    s32 var_r3_0;

    var_r3_0 = arg0;
    if ((var_r3_0 < 0) || (var_r3_0 >= 1)) {
        var_r3_0 = currentController;
    }
    return &(&allControllers)[var_r3_0];
}

#if 0 // DRAFT: illegal explicit conversion from 'long' to
void UIInputTracker::CheckDirection(int arg0, int arg1, float arg2) {
    f32 temp_f0_419;
    f32 temp_f31_304;
    f32 temp_f31_370;
    f32 var_f0_435;
    f32 var_f1_219;
    f32 var_f1_246;
    f32 var_f1_282;
    f32 var_f1_316;
    f32 var_f1_344;
    s32 var_r30_206;
    u8 var_r3_208;
    u8 var_r3_235;
    u8 var_r3_271;
    u8 var_r3_303;
    u8 var_r3_333;
    u8 var_r3_367;
    void *temp_r4_407;

    var_r30_206 = arg0;
    var_r3_208 = 0;
    if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
        var_r3_208 = 1;
    }
    if (var_r3_208 != 0) {
        var_f1_219 = 0.0f;
    } else {
        var_f1_219 = MKInput_GetState(var_r30_206, (MKInputDevices) this->unk0, NULL, NULL);
    }
    if ((var_f1_219 == 0.0f) || !(arg2 < 0.0f)) {
        var_r3_235 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_235 = 1;
        }
        if (var_r3_235 != 0) {
            var_f1_246 = 0.0f;
        } else {
            var_f1_246 = MKInput_GetState(arg1, (MKInputDevices) this->unk0, NULL, NULL);
        }
        if ((var_f1_246 != 0.0f) && (arg2 > 0.0f)) {
            goto block_16;
        }
        var_r3_271 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_271 = 1;
        }
        if (var_r3_271 != 0) {
            var_f1_282 = 0.0f;
        } else {
            var_f1_282 = MKInput_GetState(var_r30_206, (MKInputDevices) this->unk0, NULL, NULL);
        }
        if ((var_f1_282 != 0.0f) || (arg2 > 0.5f)) {
            M2C_FIELD((this + (arg1 * 4)), f32 *, -8) = -1.0f;
            var_r3_303 = 0;
            temp_f31_304 = arg2 - 0.5f;
            if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
                var_r3_303 = 1;
            }
            if (var_r3_303 != 0) {
                var_f1_316 = 0.0f;
            } else {
                var_f1_316 = MKInput_GetState(var_r30_206, (MKInputDevices) this->unk0, NULL, NULL);
            }
            if (var_f1_316 > temp_f31_304) {

            } else {
                var_f1_316 = temp_f31_304;
            }
            goto block_52;
        }
        var_r3_333 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_333 = 1;
        }
        if (var_r3_333 != 0) {
            var_f1_344 = 0.0f;
        } else {
            var_f1_344 = MKInput_GetState(arg1, (MKInputDevices) this->unk0, NULL, NULL);
        }
        if ((var_f1_344 != 0.0f) || (arg2 < -0.5f)) {
            M2C_FIELD((this + (var_r30_206 * 4)), f32 *, -8) = -1.0f;
            var_r30_206 = arg1;
            var_r3_367 = 0;
            temp_f31_370 = -(0.5f + arg2);
            if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
                var_r3_367 = 1;
            }
            if (var_r3_367 != 0) {
                var_f1_316 = 0.0f;
            } else {
                var_f1_316 = MKInput_GetState(arg1, (MKInputDevices) this->unk0, NULL, NULL);
            }
            if (var_f1_316 > temp_f31_370) {

            } else {
                var_f1_316 = temp_f31_370;
            }
block_52:
            temp_r4_407 = this + (var_r30_206 * 4);
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_FIELD(temp_r4_407, f32 *, -8) == 0.0f) {
                M2C_FIELD((this + var_r30_206), s8 *, 0x14) = 1;
                temp_f0_419 = M2C_FIELD(temp_r4_407, f32 *, -8);
                if (temp_f0_419 != -1.0f) {
                    M2C_FIELD(temp_r4_407, f32 *, -8) = (f32) (temp_f0_419 + 1.0f);
                } else {
                    M2C_FIELD(temp_r4_407, f32 *, -8) = 3.0f;
                }
            }
            if (var_f1_316 > 0.0f) {
                var_f0_435 = -((gUpdateTimeDelta * ((7.0f * var_f1_316) + 1.0f)) - M2C_FIELD(temp_r4_407, f32 *, -8));
                if (var_f0_435 > -0.9f) {

                } else {
                    var_f0_435 = -0.9f;
                }
                M2C_FIELD(temp_r4_407, f32 *, -8) = var_f0_435;
            }
            return;
        }
        M2C_FIELD((this + (var_r30_206 * 4)), f32 *, -8) = -1.0f;
        M2C_FIELD((this + (arg1 * 4)), f32 *, -8) = -1.0f;
        return;
    }
block_16:
    M2C_FIELD((this + (var_r30_206 * 4)), f32 *, -8) = -1.0f;
    M2C_FIELD((this + (arg1 * 4)), f32 *, -8) = -1.0f;
}
#endif

#if 0 // DRAFT: illegal operand
void UIInputTracker::Update() {
    f32 var_f1_485;
    f32 var_f1_509;
    f32 var_f1_537;
    f32 var_f1_562;
    s32 temp_r0_466;
    s32 var_ctr_464;
    s32 var_r4_458;
    u8 var_r3_474;
    u8 var_r3_498;
    u8 var_r3_526;
    u8 var_r3_551;

    var_r4_458 = 0;
    var_ctr_464 = 4;
    do {
        temp_r0_466 = var_r4_458 + 0x18;
        var_r4_458 += 1;
        *(this + temp_r0_466) = 0;
        var_ctr_464 -= 1;
    } while (var_ctr_464 != 0);
    if ((u8) this->unk1C != 0) {
        var_r3_474 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_474 = 1;
        }
        if (var_r3_474 != 0) {
            var_f1_485 = 0.0f;
        } else {
            var_f1_485 = MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
        }
        if (var_f1_485 == 0.0f) {
            var_r3_498 = 0;
            if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
                var_r3_498 = 1;
            }
            if (var_r3_498 != 0) {
                var_f1_509 = 0.0f;
            } else {
                var_f1_509 = MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
            }
            if (var_f1_509 == 0.0f) {
                this->unk1C = 0;
            }
        }
    } else {
        var_r3_526 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_526 = 1;
        }
        if (var_r3_526 != 0) {
            var_f1_537 = 0.0f;
        } else {
            var_f1_537 = MKInput_GetState(0x10, (MKInputDevices) this->unk0, NULL, NULL);
        }
        CheckDirection(4, 6, var_f1_537);
        var_r3_551 = 0;
        if (((u8) this->unk5 != 0) || ((u8) this->unk4 != 0)) {
            var_r3_551 = 1;
        }
        if (var_r3_551 != 0) {
            var_f1_562 = 0.0f;
        } else {
            var_f1_562 = MKInput_GetState(0x11, (MKInputDevices) this->unk0, NULL, NULL);
        }
        CheckDirection(5, 7, var_f1_562);
    }
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKInputDevices'
void UIInputTracker::Init(MKInputDevices arg0) {
    s32 temp_r0_597;
    s32 var_ctr_594;
    s32 var_r4_591;
    s32 var_r7_592;

    this->unk0 = (s32) arg0;
    this->unk4 = 0;
    var_r4_591 = 0;
    var_r7_592 = 0;
    this->unk5 = 0;
    var_ctr_594 = 4;
    do {
        temp_r0_597 = var_r7_592 + 0x18;
        *(this + (var_r4_591 + 8)) = 0.0f;
        var_r7_592 += 1;
        var_r4_591 += 4;
        *(this + temp_r0_597) = 0;
        var_ctr_594 -= 1;
    } while (var_ctr_594 != 0);
    this->unk1C = 0;
    this->unk1D = 0;
}
#endif

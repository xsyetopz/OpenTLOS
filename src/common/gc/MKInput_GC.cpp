#include "common/gc/MKInput_GC.h"
#include "common/Source/MKWidgetsInternal.h"
#include "unplaced_enums.h"
#include "dolphin/pad.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_padStatus_0xC'
static struct _struct_padStatus_0xC padStatus[4];
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_oldStatus_0xC'
static struct _struct_oldStatus_0xC oldStatus[4];
#endif
static u16 ButtonMasks[0x14] = {
    0,
    0,
    0,
    0x1000,
    8,
    2,
    4,
    1,
    0,
    0x10,
    0x40,
    0x20,
    0x800,
    0x400,
    0x100,
    0x200,
    0,
    0,
    0,
    0,
}; /* const */

s32 MKInput_GetNextKeybEventPlatformSpecific(MKInputEvent *arg0) {
    return 0;
}

void MKInput_InitModulePlatformSpecific() {

}

void MKInput_Vibrate(MKInputDevices arg0, float arg1, float arg2) {
    s32 var_r31_33;

    if (((s32) arg0 == 4) && (arg1 == 0.0f)) {
        var_r31_33 = 0;
        do {
            PADControlMotor(var_r31_33, 2U);
            var_r31_33 += 1;
        } while (var_r31_33 <= 3);
        return;
    }
    if (((s32) arg0 >= 0) && ((s32) arg0 <= 3)) {
        if (arg1 != 0.0f) {
            PADControlMotor((s32) arg0, 1U);
            return;
        }
        PADControlMotor((s32) arg0, 2U);
    }
}

s32 MKInput_GetButtonType(int arg0, MKInputDevices arg1) {
    if (((s32) arg1 >= 0) && ((s32) arg1 <= 4) && (arg0 >= 0) && (arg0 < 0x15)) {
        if ((arg0 >= 0x10) && (arg0 <= 0x13)) {
            return 3;
        }
        if ((arg0 == 0xA) || (arg0 == 0xB)) {
            return 2;
        }
        if ((arg0 >= 3) && (arg0 != 8) && (arg0 <= 0x13)) {
            return 1;
        }
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

#if 0 // DRAFT: expression syntax error
f32 MKInput_GetStatePlatformSpecific(int arg0, MKInputDevices arg1, float *arg2) {
    f32 var_f0_109;
    f32 var_f1_106;
    u16 temp_r6_296;

    var_f1_106 = 0.0f;
    var_f0_109 = 0.0f;
    if ((s32) arg1 < 4) {
        if ((s32) arg1 < 0) {

        } else {
            switch (arg0) {                         /* irregular */
            case 17:
                var_f1_106 = (f32) (s8) padStatus[(s32) arg1].unk2 / 56.0f;
                var_f0_109 = (f32) (s8) oldStatus[(s32) arg1].unk2 / 56.0f;
                break;
            case 16:
                var_f1_106 = (f32) (s8) padStatus[(s32) arg1].unk3 / 56.0f;
                var_f0_109 = (f32) (s8) oldStatus[(s32) arg1].unk3 / 56.0f;
                break;
            case 19:
                var_f1_106 = (f32) (s8) padStatus[(s32) arg1].unk4 / 44.0f;
                var_f0_109 = (f32) (s8) oldStatus[(s32) arg1].unk4 / 44.0f;
                break;
            case 18:
                var_f1_106 = (f32) (s8) padStatus[(s32) arg1].unk5 / 44.0f;
                var_f0_109 = (f32) (s8) oldStatus[(s32) arg1].unk5 / 44.0f;
                break;
            case 11:
                var_f1_106 = (f32) padStatus[(s32) arg1].unk7 / 150.0f;
                var_f0_109 = (f32) oldStatus[(s32) arg1].unk7 / 150.0f;
                break;
            case 10:
                var_f1_106 = (f32) padStatus[(s32) arg1].unk6 / 150.0f;
                var_f0_109 = (f32) oldStatus[(s32) arg1].unk6 / 150.0f;
                break;
            case 12:
            case 13:
            case 14:
            case 15:
                if ((arg0 >= 0) && (arg0 < 0x15)) {
                default:
                    temp_r6_296 = ButtonMasks[arg0];
                    if (padStatus[(s32) arg1].unk0 & temp_r6_296) {
                        var_f1_106 = 1.0f;
                    }
                    if (oldStatus[(s32) arg1].unk0 & temp_r6_296) {
                        var_f0_109 = 1.0f;
                    }
                }
                break;
            }
        }
    }
    if (arg2 != NULL) {
        *arg2 = var_f0_109;
    }
    return var_f1_106;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 MKInput_GetStatus(MKInputDevices arg0) {
    s32 var_r31_326;
    s32 var_r4_322;
    u8 temp_r3_342;

    var_r4_322 = 2;
    if ((s32) arg0 == 4) {
        var_r31_326 = 0;
loop_2:
        var_r4_322 = MKInput_GetStatus((MKInputDevices) var_r31_326);
        if (var_r4_322 != 0) {
            var_r31_326 += 1;
            if (var_r31_326 >= 4) {

            } else {
                goto loop_2;
            }
        }
    } else if ((s32) arg0 < 4) {
        temp_r3_342 = padStatus[(s32) arg0].unkA;
        if ((s8) temp_r3_342 == 0) {
            var_r4_322 = 0;
        } else if ((s8) temp_r3_342 == -2) {
            var_r4_322 = 1;
        }
    }
    return var_r4_322;
}
#endif

#if 0 // DRAFT: undefined identifier 'oldStatus'
void MKInput_UpdatePlatformSpecific() {
    s32 var_ctr_386;
    s32 var_r4_384;
    s32 var_r8_383;
    u32 var_r3_382;

    memcpy(oldStatus, padStatus, 0x30U);
    PADRead((PADStatus *) padStatus);
    PADClampCircle((PADStatus *) padStatus);
    var_r3_382 = 0;
    var_r8_383 = 0;
    var_r4_384 = 0;
    var_ctr_386 = 4;
    do {
        if ((s8) M2C_FIELD((padStatus + var_r4_384), u8 *, 0xA) == -1) {
            var_r3_382 |= 0x80000000U >> var_r8_383;
        }
        var_r8_383 += 1;
        var_r4_384 += 0xC;
        var_ctr_386 -= 1;
    } while (var_ctr_386 != 0);
    if (var_r3_382 != 0) {
        PADReset(var_r3_382);
    }
}
#endif

#include "common/Source/MKInput.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKWidgetsInternal.h"
#include "unplaced_enums.h"
#include "common/gc/MKInput_GC.h"
#include <m2c_macros.h>

MKInputReceiver **malloc(M2C_UNK);                  /* extern */
extern s32 MKInput_LastUsedDevice;
extern M2C_UNK bDeviceAttachedLastFrame;
extern u8 eventsReady;
extern MKInputReceiver *pReceiverChain;
extern MKInputReceiver **receivers;
extern u8 repeatEventsEnabled;

#if 0 // DRAFT: undefined identifier 'MKInput_SendEvent'
void MKInput_DespatchEvents() {
    u8 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;                                       /* compiler-managed */
    u8 sp26;
    s8 sp25;
    s8 sp24;                                        /* compiler-managed */
    s32 sp20;                                       /* compiler-managed */
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    u8 spA;
    u8 sp9;
    u8 sp8;
    f32 temp_f1_150;
    f32 temp_f1_221;
    f32 temp_f1_310;
    f32 temp_f1_326;
    f32 temp_f1_82;
    f32 temp_f30_145;
    f32 temp_f30_274;
    f32 temp_f30_77;
    f32 temp_f31_281;
    s32 temp_r3_211;
    s32 temp_r3_28;
    s32 var_r28_207;
    s32 var_r28_320;
    s32 var_r30_22;
    s8 var_r0_235;
    s8 var_r0_340;
    s8 var_r4_246;
    s8 var_r4_350;
    u8 var_r0_153;
    u8 var_r0_85;
    u8 var_r29_30;
    u8 var_r3_152;
    u8 var_r3_84;

    if ((u8) eventsReady != 0) {
        var_r30_22 = 0;
        do {
            if (var_r30_22 != 4) {
                temp_r3_28 = MKInput_GetStatus((MKInputDevices) var_r30_22);
                var_r29_30 = 0;
                switch (temp_r3_28) {               /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    var_r29_30 = 1;
                    break;
                case 1:                             /* switch 1 */
                    var_r29_30 = *(&bDeviceAttachedLastFrame + var_r30_22);
                    break;
                case 2:                             /* switch 1 */
                    var_r29_30 = 0;
                    break;
                case 3:                             /* switch 1 */
                    var_r29_30 = 0;
                    break;
                }
                if ((var_r29_30 != 0) && ((u8) *(&bDeviceAttachedLastFrame + var_r30_22) == 0)) {
                    sp1C = 0;
                    sp20 = var_r30_22;
                    sp24 = 1;
                    MKInput_SendEvent((MKInputEvent *) &sp1C);
                }
                switch (var_r30_22) {               /* switch 2; irregular */
                default:                            /* switch 2 */
                    temp_f30_77 = MKInput_GetState(0x11, (MKInputDevices) var_r30_22, &sp18, &spA);
                    temp_f1_82 = MKInput_GetState(0x10, (MKInputDevices) var_r30_22, &sp14, NULL);
                    var_r3_84 = 1;
                    var_r0_85 = 0;
                    if ((temp_f30_77 <= -0.98f) || (temp_f30_77 >= 0.98f) || (temp_f1_82 <= -0.98f)) {
                        var_r0_85 = 1;
                    }
                    if ((var_r0_85 == 0) && !(temp_f1_82 >= 0.98f)) {
                        var_r3_84 = 0;
                    }
                    if ((temp_f30_77 != sp18) || (temp_f1_82 != sp14) || (((u8) repeatEventsEnabled != 0) && (var_r3_84 != 0) && (spA != 0))) {
                        sp1C = 1;
                        sp20 = var_r30_22;
                        sp24 = 0;
                        sp28 = temp_f30_77;
                        sp2C = temp_f1_82;
                        sp30 = temp_f30_77 - sp18;
                        sp34 = temp_f1_82 - sp14;
                        sp38 = spA;
                        MKInput_SendEvent((MKInputEvent *) &sp1C);
                    }
                    temp_f30_145 = MKInput_GetState(0x13, (MKInputDevices) var_r30_22, &sp18, &spA);
                    temp_f1_150 = MKInput_GetState(0x12, (MKInputDevices) var_r30_22, &sp14, NULL);
                    var_r3_152 = 1;
                    var_r0_153 = 0;
                    if ((temp_f30_145 <= -0.98f) || (temp_f30_145 >= 0.98f) || (temp_f1_150 <= -0.98f)) {
                        var_r0_153 = 1;
                    }
                    if ((var_r0_153 == 0) && !(temp_f1_150 >= 0.98f)) {
                        var_r3_152 = 0;
                    }
                    if ((temp_f30_145 != sp18) || (temp_f1_150 != sp14) || (((u8) repeatEventsEnabled != 0) && (var_r3_152 != 0) && (spA != 0))) {
                        sp1C = 1;
                        sp20 = var_r30_22;
                        sp24 = 1;
                        sp28 = temp_f30_145;
                        sp2C = temp_f1_150;
                        sp30 = temp_f30_145 - sp18;
                        sp34 = temp_f1_150 - sp14;
                        sp38 = spA;
                        MKInput_SendEvent((MKInputEvent *) &sp1C);
                    }
                    var_r28_207 = 0;
                    do {
                        temp_r3_211 = MKInput_GetButtonType(var_r28_207, (MKInputDevices) var_r30_22);
                        if (((temp_r3_211 == 1) || (temp_r3_211 == 2)) && ((temp_f1_221 = MKInput_GetState(var_r28_207, (MKInputDevices) var_r30_22, &sp10, &sp9), ((temp_f1_221 == sp10) == 0)) || (((u8) repeatEventsEnabled != 0) && (sp9 != 0)))) {
                            sp1C = 2;
                            var_r0_235 = 0;
                            sp20 = var_r30_22;
                            sp24 = var_r28_207;
                            if ((temp_f1_221 > 0.0f) && (sp10 == 0.0f)) {
                                var_r0_235 = 1;
                            }
                            var_r4_246 = 0;
                            sp28 = var_r0_235;
                            if ((temp_f1_221 == 0.0f) && (sp10 > 0.0f)) {
                                var_r4_246 = 1;
                            }
                            unksp29 = var_r4_246;
                            sp2C = temp_f1_221;
                            unksp2A = sp9;
                            MKInput_SendEvent((MKInputEvent *) &sp1C);
                        }
                        var_r28_207 += 1;
                    } while (var_r28_207 < 0x15);
                    break;
                case 6:                             /* switch 2 */
                    temp_f30_274 = MKInput_GetState(5, (MKInputDevices) var_r30_22, NULL, NULL);
                    temp_f31_281 = MKInput_GetState(6, (MKInputDevices) var_r30_22, NULL, NULL);
                    if ((temp_f30_274 != 0.0f) || (temp_f31_281 != 0.0f)) {
                        sp1C = 4;
                        sp20 = MKInput_GetState(8, (MKInputDevices) var_r30_22, NULL, NULL);
                        sp24 = MKInput_GetState(9, (MKInputDevices) var_r30_22, NULL, NULL);
                        sp28 = temp_f30_274;
                        sp2C = temp_f31_281;
                        MKInput_SendEvent((MKInputEvent *) &sp1C);
                    }
                    temp_f1_310 = MKInput_GetState(7, (MKInputDevices) var_r30_22, NULL, NULL);
                    if (temp_f1_310 != 0.0f) {
                        sp20 = temp_f1_310;
                        sp1C = 5;
                        MKInput_SendEvent((MKInputEvent *) &sp1C);
                    }
                    var_r28_320 = 0;
                    do {
                        temp_f1_326 = MKInput_GetState(var_r28_320, (MKInputDevices) var_r30_22, &spC, &sp8);
                        if ((temp_f1_326 != spC) || (((u8) repeatEventsEnabled != 0) && (sp8 != 0))) {
                            sp1C = 3;
                            var_r0_340 = 0;
                            sp20 = var_r28_320;
                            if ((temp_f1_326 > 0.0f) && (spC == 0.0f)) {
                                var_r0_340 = 1;
                            }
                            var_r4_350 = 0;
                            sp24 = var_r0_340;
                            if ((temp_f1_326 == 0.0f) && (spC > 0.0f)) {
                                var_r4_350 = 1;
                            }
                            sp25 = var_r4_350;
                            sp26 = sp8;
                            MKInput_SendEvent((MKInputEvent *) &sp1C);
                        }
                        var_r28_320 += 1;
                    } while (var_r28_320 <= 4);
                    break;
                case 5:                             /* switch 2 */
loop_82:
                    if (MKInput_GetNextKeybEventPlatformSpecific((MKInputEvent *) &sp1C) != 0) {
                        MKInput_SendEvent((MKInputEvent *) &sp1C);
                        goto loop_82;
                    }
                    break;
                }
                if ((var_r29_30 == 0) && ((u8) *(&bDeviceAttachedLastFrame + var_r30_22) != 0)) {
                    sp20 = var_r30_22;
                    sp1C = 0;
                    sp24 = 0;
                    MKInput_SendEvent((MKInputEvent *) &sp1C);
                }
                *(&bDeviceAttachedLastFrame + var_r30_22) = var_r29_30;
            }
            var_r30_22 += 1;
        } while (var_r30_22 <= 7);
        eventsReady = 0;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void MKInput_SendEvent(MKInputEvent *arg0) {
    MKInputReceiver *temp_r4_428;
    MKInputReceiver *var_r31_430;
    MKInputReceiver *var_r5_423;
    s32 temp_r0_442;
    u8 var_r3_427;
    u8 var_r3_443;

    var_r5_423 = pReceiverChain;
loop_23:
    if (var_r5_423 != NULL) {
        var_r3_427 = 0;
        temp_r4_428 = var_r5_423->unk14;
        var_r31_430 = temp_r4_428;
        if (((MKInputReceiver *) var_r5_423->unk10 != NULL) || (temp_r4_428 != NULL) || ((MKInputReceiver *) pReceiverChain == var_r5_423)) {
            var_r3_427 = 1;
        }
        if (var_r3_427 != 0) {
            temp_r0_442 = arg0->unk0;
            var_r3_443 = 0;
            switch (temp_r0_442) {                  /* irregular */
            case 0:
                var_r3_443 = 1;
                break;
            case 1:
                var_r3_443 = (var_r5_423->unk4 & (4 << arg0->unk4)) != 0;
                break;
            case 2:
                var_r3_443 = (var_r5_423->unk4 & (4 << arg0->unk4)) != 0;
                break;
            case 6:
                var_r3_443 = var_r5_423->unk4 & 1;
                break;
            default:
                var_r3_443 = ((u32) var_r5_423->unk4 >> 1U) & 1;
                break;
            }
            if ((var_r3_443 != 0) && (var_r5_423->unk0(arg0, var_r5_423->unkC) == 0)) {
                var_r31_430 = NULL;
            }
        }
        var_r5_423 = var_r31_430;
        goto loop_23;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'UnlinkReceiver'
void MKInputReceiver_Destroy(MKInputReceiver *arg0) {
    MKInputReceiver **temp_r3_522;
    MKInputReceiver **var_r4_517;
    MKInputReceiver *temp_r0_533;
    MKInputReceiver *temp_r5_525;

    UnlinkReceiver(arg0);
    var_r4_517 = receivers;
loop_4:
    temp_r0_533 = *var_r4_517;
    if (temp_r0_533 == NULL) {
        return;
    }
    if (temp_r0_533 == arg0) {
        temp_r3_522 = receivers;
        receivers = temp_r3_522 + 4;
        temp_r5_525 = *temp_r3_522;
        *temp_r3_522 = *var_r4_517;
        *var_r4_517 = temp_r5_525;
        return;
    }
    var_r4_517 += 4;
    goto loop_4;
}
#endif

#if 0 // DRAFT: identifier 'arg3' redeclared
MKInputReceiver *MKInputReceiver_Create(bool (*arg1)(MKInputEvent *, void *), int arg2, int arg3, void *arg3) {
    MKInputReceiver **temp_r7_552;
    MKInputReceiver *temp_r31_554;
    s32 var_r5_0;

    var_r5_0 = arg2;
    temp_r7_552 = receivers - 4;
    receivers = temp_r7_552;
    temp_r31_554 = *temp_r7_552;
    if (temp_r31_554 == NULL) {
        return NULL;
    }
    if ((var_r5_0 < 0) || (var_r5_0 > 6)) {
        var_r5_0 = 3;
    }
    temp_r31_554->unk0 = arg0;
    temp_r31_554->unk4 = (u32) arg1;
    temp_r31_554->unk8 = var_r5_0;
    temp_r31_554->unkC = arg3;
    temp_r31_554->unk10 = NULL;
    temp_r31_554->unk14 = NULL;
    if (var_r5_0 != 0) {
        LinkReceiver(temp_r31_554);
    }
    return temp_r31_554;
}
#endif

void UnlinkReceiver(MKInputReceiver *arg0) {
    MKInputReceiver *temp_r4_591;
    MKInputReceiver *temp_r4_603;
    MKInputReceiver *temp_r5_598;

    temp_r4_591 = arg0->unk14;
    if ((temp_r4_591 != NULL) || ((MKInputReceiver *) arg0->unk10 != NULL)) {
        temp_r5_598 = arg0->unk10;
        if (temp_r5_598 != NULL) {
            temp_r5_598->unk14 = temp_r4_591;
        }
        temp_r4_603 = arg0->unk14;
        if (temp_r4_603 != NULL) {
            temp_r4_603->unk10 = arg0->unk10;
        }
        if ((MKInputReceiver *) pReceiverChain == arg0) {
            pReceiverChain = arg0->unk14;
        }
        arg0->unk10 = NULL;
        arg0->unk14 = NULL;
    }
}

void LinkReceiver(MKInputReceiver *arg0) {
    MKInputReceiver *temp_r4_649;
    MKInputReceiver *temp_r4_659;
    MKInputReceiver *var_r6_644;
    s32 temp_r5_628;

    if (((MKInputReceiver *) pReceiverChain == NULL) || (temp_r5_628 = arg0->unk8, (((s32) pReceiverChain->unk8 > temp_r5_628) == 0))) {
        arg0->unk10 = NULL;
        arg0->unk14 = pReceiverChain;
        if ((MKInputReceiver *) pReceiverChain != NULL) {
            pReceiverChain->unk10 = arg0;
        }
        pReceiverChain = arg0;
        return;
    }
    var_r6_644 = pReceiverChain;
loop_7:
    temp_r4_649 = var_r6_644->unk14;
    if ((temp_r4_649 != NULL) && ((s32) temp_r4_649->unk8 > temp_r5_628)) {
        var_r6_644 = temp_r4_649;
        goto loop_7;
    }
    arg0->unk10 = var_r6_644;
    arg0->unk14 = var_r6_644->unk14;
    temp_r4_659 = var_r6_644->unk14;
    if (temp_r4_659 != NULL) {
        temp_r4_659->unk10 = arg0;
    }
    var_r6_644->unk14 = arg0;
}

s32 MKInput_Released(int arg0, MKInputDevices arg1) {
    f32 sp8;
    s32 var_r3_678;

    var_r3_678 = 0;
    if ((MKInput_GetState(arg0, arg1, &sp8, NULL) == 0.0f) && (sp8 > 0.0f)) {
        var_r3_678 = 1;
    }
    return var_r3_678;
}

s32 MKInput_Pressed(int arg0, MKInputDevices arg1) {
    f32 sp8;
    s32 var_r3_702;

    var_r3_702 = 0;
    if ((MKInput_GetState(arg0, arg1, &sp8, NULL) > 0.0f) && (sp8 == 0.0f)) {
        var_r3_702 = 1;
    }
    return var_r3_702;
}

f32 MKInput_GetState(int arg0, MKInputDevices arg1, float *arg2, bool *arg3) {
    f32 sp8;
    f32 temp_f1_737;
    s32 var_r29_731;

    if ((s32) arg1 == 4) {
        var_r29_731 = 0;
loop_2:
        temp_f1_737 = MKInput_GetStatePlatformSpecific(arg0, (MKInputDevices) var_r29_731, &sp8);
        if ((temp_f1_737 != 0.0f) || (sp8 != 0.0f)) {
            if (arg2 != NULL) {
                *arg2 = sp8;
            }
            if (arg3 != NULL) {
                *arg3 = 0;
            }
            MKInput_LastUsedDevice = var_r29_731;
            return temp_f1_737;
        }
        var_r29_731 += 1;
        if (var_r29_731 > 3) {
            if (arg2 != NULL) {
                *arg2 = 0.0f;
            }
            if (arg3 != NULL) {
                *arg3 = 0;
            }
            MKInput_LastUsedDevice = 4;
            return 0.0f;
        }
        goto loop_2;
    }
    MKInput_LastUsedDevice = (s32) arg1;
    if (arg3 != NULL) {
        *arg3 = 0;
    }
    return MKInput_GetStatePlatformSpecific(arg0, arg1, arg2);
}

void MKInput_Update() {
    MKInput_UpdatePlatformSpecific();
    eventsReady = 1;
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKInput_InitModule() {
    MKHeap *temp_r3_817;
    MKInputReceiver **var_r3_824;
    s32 var_ctr_836;

    MKInput_InitModulePlatformSpecific();
    temp_r3_817 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_817 != NULL) {
        var_r3_824 = ((MKHeap *) (temp_r3_817->Current()))->Alloc(0xB0, NULL, 0);
    } else {
        var_r3_824 = malloc(0xB0);
    }
    receivers = var_r3_824;
    receivers = var_r3_824 + 0x90;
    M2C_FIELD(var_r3_824, s32 *, 0x90) = 0;
    var_ctr_836 = 6;
    do {
        receivers += 4;
        M2C_FIELD(receivers, MKInputReceiver ***, 4) = var_r3_824;
        var_r3_824 += 0x18;
        var_ctr_836 -= 1;
    } while (var_ctr_836 != 0);
    receivers += 4;
    M2C_FIELD(receivers, MKInputReceiver ***, 4) = NULL;
    memset(&bDeviceAttachedLastFrame, 0, 7U);
    repeatEventsEnabled = 0;
}
#endif

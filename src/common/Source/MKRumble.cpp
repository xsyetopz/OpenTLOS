#include "common/Source/MKRumble.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKInput_GC.h"
#include <m2c_macros.h>

f64 fmod(f32, f64);                                 /* extern */
extern u8 MKRumble_bMuted;
extern s32 effectsPlaying;
extern u8 vibrationPaused;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_ves_0xC'
static struct _struct_ves_0xC ves[4] = { { 0.0f }, { 0.0f }, { 0.0f }, { 0.0f } };
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_vibrationEffect_0x1C vibrationEffect[8];
#endif
static M2C_UNK stack;
static u8 MKRumble_bEnabled = 1;
static M2C_UNK lit_200;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_201;                                /* unable to generate initializer: unknown type; const */

u8 MKRumble_IsMuted() {
    return MKRumble_bMuted;
}

void MKRumble_Mute(bool arg0) {
    MKRumble_bMuted = arg0;
}

#if 0 // DRAFT: undefined identifier 'ves'
void MKRumble_Pop() {
    MKRumble_Reset();
    memcpy(ves, &stack, 0x30U);
    memcpy(vibrationEffect, &stack + 0x30, 0xE0U);
    effectsPlaying = M2C_FIELD(&stack, s32 *, 0x110);
}
#endif

#if 0 // DRAFT: undefined identifier 'ves'
void MKRumble_Push() {
    memcpy(&stack, ves, 0x30U);
    memcpy(&stack + 0x30, vibrationEffect, 0xE0U);
    M2C_FIELD(&stack, s32 *, 0x110) = (s32) effectsPlaying;
    MKRumble_Reset();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void MKRumble_Stop(MKInputDevices arg0) {
    s32 temp_r0_99;
    s32 var_r9_89;
    struct _struct_vibrationEffect_0x1C *temp_r4_105;
    struct _struct_vibrationEffect_0x1C *temp_r7_94;

    if ((u8) MKRumble_bEnabled != 0) {
        var_r9_89 = 0;
loop_7:
        if ((s32) effectsPlaying > var_r9_89) {
            temp_r7_94 = &vibrationEffect[var_r9_89];
            if ((s32) arg0 == (s32) M2C_FIELD(temp_r7_94, s32 *, 0x14)) {
                temp_r0_99 = effectsPlaying - 1;
                if (var_r9_89 < temp_r0_99) {
                    temp_r4_105 = &vibrationEffect[temp_r0_99];
                    temp_r7_94->unk0 = temp_r4_105->unk0;
                    temp_r7_94->unk4 = temp_r4_105->unk4;
                    temp_r7_94->unk8 = temp_r4_105->unk8;
                    temp_r7_94->unkC = temp_r4_105->unkC;
                    temp_r7_94->unk10 = temp_r4_105->unk10;
                    M2C_FIELD(temp_r7_94, s32 *, 0x14) = (s32) M2C_FIELD(temp_r4_105, s32 *, 0x14);
                    temp_r7_94->unk18 = temp_r4_105->unk18;
                }
                var_r9_89 -= 1;
                effectsPlaying -= 1;
            }
            var_r9_89 += 1;
            goto loop_7;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void MKRumble_Play(MKInputDevices arg0, float arg1, float arg2, float arg3, char arg4, float arg5) {
    struct _struct_vibrationEffect_0x1C *temp_r6_154;

    if (((u8) MKRumble_bEnabled != 0) && ((s32) effectsPlaying < 8)) {
        temp_r6_154 = &vibrationEffect[effectsPlaying];
        M2C_FIELD(temp_r6_154, s32 *, 0x14) = (s32) arg0;
        temp_r6_154->unk4 = arg2;
        temp_r6_154->unk8 = arg1;
        vibrationEffect[effectsPlaying].unk0 = 1.0f / (60.0f * arg3);
        temp_r6_154->unk10 = (u8) arg4;
        temp_r6_154->unkC = arg3 * arg5;
        temp_r6_154->unk18 = 0.0f;
        ves[(s32) arg0].unk8 = 0.0f;
        effectsPlaying += 1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void MKRumble_Update() {
    M2C_UNK sp2C;
    M2C_UNK spC;
    u8 sp8;
    f32 temp_f1_367;
    f32 var_f2_403;
    f32 var_f31_227;
    s32 temp_r0_241;
    s32 temp_r0_293;
    s32 temp_r0_308;
    s32 var_r28_343;
    s32 var_r29_216;
    s32 var_r30_340;
    s32 var_r31_349;
    struct _struct_vibrationEffect_0x1C *temp_r30_220;
    struct _struct_vibrationEffect_0x1C *temp_r3_314;
    u8 *var_r29_348;
    u8 temp_r23_383;
    u8 temp_r3_221;
    void *temp_r24_361;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&lit_200 - 4) + 4, 0x20);
    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&lit_201 - 4) + 4, 0x20);
    if (((u8) MKRumble_bEnabled != 0) && ((u8) vibrationPaused == 0)) {
        var_r29_216 = 0;
loop_27:
        if (var_r29_216 < (s32) effectsPlaying) {
            temp_r30_220 = &vibrationEffect[var_r29_216];
            temp_r3_221 = temp_r30_220->unk10;
            if ((s8) temp_r3_221 & 1) {
                var_f31_227 = 1.0f - temp_r30_220->unk18;
            } else if ((s8) temp_r3_221 & 2) {
                var_f31_227 = temp_r30_220->unk18;
            } else {
                var_f31_227 = 1.0f;
            }
            if ((s8) temp_r3_221 & 4) {
                var_f31_227 *= var_f31_227;
            }
            temp_r0_241 = (s8) temp_r3_221 & 0xF0;
            switch (temp_r0_241) {                  /* irregular */
            case 0x0:
                break;
            case 0x10:
                var_f31_227 *= _table_sinf((temp_r30_220->unk18 * temp_r30_220->unkC) + 1.5707964f);
                break;
            case 0x20:
                var_f31_227 *= (f32) fabs((2.0f * (f32) fmod(temp_r30_220->unk18 * temp_r30_220->unkC, 1.0)) - 1.0f);
                break;
            case 0x40:
                if ((f32) fmod(temp_r30_220->unk18 * temp_r30_220->unkC, 1.0) > 0.5f) {
                    var_f31_227 = 0.0f;
                }
                break;
            }
            temp_r30_220->unk18 += temp_r30_220->unk0;
            temp_r0_293 = M2C_FIELD(temp_r30_220, s32 *, 0x14);
            (&sp10[0])[temp_r0_293] += var_f31_227 * temp_r30_220->unk4;
            (&sp30[0])[temp_r0_293] += var_f31_227 * temp_r30_220->unk8;
            M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
            if (temp_r30_220->unk18 == 1.0f) {
                temp_r0_308 = effectsPlaying - 1;
                if (var_r29_216 < temp_r0_308) {
                    temp_r3_314 = &vibrationEffect[temp_r0_308];
                    temp_r30_220->unk0 = temp_r3_314->unk0;
                    temp_r30_220->unk4 = temp_r3_314->unk4;
                    temp_r30_220->unk8 = temp_r3_314->unk8;
                    temp_r30_220->unkC = temp_r3_314->unkC;
                    temp_r30_220->unk10 = temp_r3_314->unk10;
                    M2C_FIELD(temp_r30_220, s32 *, 0x14) = (s32) M2C_FIELD(temp_r3_314, s32 *, 0x14);
                    temp_r30_220->unk18 = temp_r3_314->unk18;
                }
                var_r29_216 -= 1;
                effectsPlaying -= 1;
            }
            var_r29_216 += 1;
            goto loop_27;
        }
        var_r30_340 = 0;
        var_r28_343 = 0;
        var_r29_348 = &sp8;
        var_r31_349 = 0;
        do {
            if (*(&sp10[0] + var_r28_343) > 1.0f) {
                *(&sp10[0] + var_r28_343) = 1.0f;
            }
            if (*(&sp30[0] + var_r28_343) > 1.0f) {
                *(&sp30[0] + var_r28_343) = 1.0f;
            }
            temp_r24_361 = ves + var_r31_349;
            M2C_FIELD(temp_r24_361, f32 *, 8) = (f32) (M2C_FIELD(temp_r24_361, f32 *, 8) + *(&sp10[0] + var_r28_343));
            temp_f1_367 = M2C_FIELD(temp_r24_361, f32 *, 8);
            if (temp_f1_367 > 0.0f) {
                (&sp8)[var_r30_340] = 1;
                M2C_FIELD(temp_r24_361, f32 *, 8) = (f32) (temp_f1_367 - 1.0f);
            } else {
                (&sp8)[var_r30_340] = 0;
            }
            temp_r23_383 = *var_r29_348;
            if ((temp_r23_383 != (u8) M2C_FIELD(temp_r24_361, u8 *, 4)) || ((f32) fabs(*(&sp30[0] + var_r28_343) - M2C_FIELD(temp_r24_361, f32 *, 0)) > 0.00392f)) {
                if ((u8) MKRumble_bMuted == 0) {
                    if (temp_r23_383 != 0) {
                        var_f2_403 = 1.0f;
                    } else {
                        var_f2_403 = 0.0f;
                    }
                    MKInput_Vibrate((MKInputDevices) var_r30_340, *(&sp30[0] + var_r28_343), var_f2_403);
                } else {
                    MKInput_Vibrate((MKInputDevices) var_r30_340, 0.0f, 0.0f);
                }
                M2C_FIELD(temp_r24_361, f32 *, 0) = (f32) *(&sp30[0] + var_r28_343);
                M2C_FIELD(temp_r24_361, u8 *, 4) = temp_r23_383;
            }
            var_r30_340 += 1;
            var_r31_349 += 0xC;
            var_r28_343 += 4;
            var_r29_348 += 1;
        } while (var_r30_340 < 4);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'ves'
void MKRumble_Reset() {
    s32 var_ctr_479;
    s32 var_r28_456;
    s32 var_r31_453;
    s32 var_r3_477;
    void *temp_r4_458;
    void *temp_r6_481;

    if ((u8) MKRumble_bEnabled != 0) {
        vibrationPaused = 0;
        var_r31_453 = 0;
        var_r28_456 = 0;
        do {
            temp_r4_458 = ves + var_r31_453;
            M2C_FIELD(temp_r4_458, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r4_458, s8 *, 4) = 0;
            M2C_FIELD(temp_r4_458, f32 *, 8) = 0.0f;
            MKInput_Vibrate((MKInputDevices) var_r28_456, 0.0f, 0.0f);
            var_r28_456 += 1;
            var_r31_453 += 0xC;
        } while (var_r28_456 < 4);
        effectsPlaying = 0;
        var_r3_477 = 0;
        var_ctr_479 = 8;
        do {
            temp_r6_481 = vibrationEffect + var_r3_477;
            var_r3_477 += 0x1C;
            M2C_FIELD(temp_r6_481, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r6_481, f32 *, 0) = 60.0f;
            M2C_FIELD(temp_r6_481, f32 *, 4) = 1.0f;
            M2C_FIELD(temp_r6_481, f32 *, 8) = 1.0f;
            M2C_FIELD(temp_r6_481, s8 *, 0x10) = 0;
            M2C_FIELD(temp_r6_481, f32 *, 0xC) = 0.0f;
            M2C_FIELD(temp_r6_481, f32 *, 0x18) = 0.0f;
            var_ctr_479 -= 1;
        } while (var_ctr_479 != 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'ves'
u8 MKRumble_Enable(bool arg0) {
    s32 temp_cr0_eq_511;
    s32 var_r27_521;
    s32 var_r31_516;
    u8 temp_r28_510;
    void *temp_r4_523;

    temp_r28_510 = MKRumble_bEnabled;
    temp_cr0_eq_511 = temp_r28_510 == 0;
    MKRumble_bEnabled = arg0;
    if ((temp_cr0_eq_511 == 0) && (arg0 == 0)) {
        var_r31_516 = 0;
        var_r27_521 = 0;
        do {
            temp_r4_523 = ves + var_r31_516;
            M2C_FIELD(temp_r4_523, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r4_523, s8 *, 4) = 0;
            M2C_FIELD(temp_r4_523, f32 *, 8) = 0.0f;
            MKInput_Vibrate((MKInputDevices) var_r27_521, 0.0f, 0.0f);
            var_r27_521 += 1;
            var_r31_516 += 0xC;
        } while (var_r27_521 < 4);
    }
    return temp_r28_510;
}
#endif

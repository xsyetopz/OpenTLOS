#include "common/Source/Timer.h"
#include "common/Source/MKMemoryCard.h"
#include "dolphin/os.h"
#include <m2c_macros.h>

void Timer_GetDifference(TimerInfo *arg0, TimerInfo *arg1, TimerInfo *arg2) {
    f32 temp_f1_25;
    f32 temp_f31_21;

    temp_f31_21 = Timer_GetDHMSInSeconds(arg1);
    temp_f1_25 = Timer_GetDHMSInSeconds(arg2) - temp_f31_21;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    Timer_SetDHMSInSeconds(arg0, temp_f1_25);
}

void Timer_SetDHMSInSeconds(TimerInfo *arg0, float arg1) {
    s32 temp_r11_52;

    temp_r11_52 = (s32) arg1;
    arg0->unkC = (s32) (1000.0f * (arg1 - (f32) temp_r11_52));
    arg0->unk8 = (s32) arg1 % 60;
    arg0->unk4 = (temp_r11_52 / 60) % 60;
    arg0->unk0 = (temp_r11_52 / 3600) % 24;
    arg0->unk10 = temp_r11_52 / 86400;
}

f32 Timer_GetDHMSInSeconds(TimerInfo *arg0) {
    return (f32) (arg0->unk10 * 0x15180) + (f32) (arg0->unk0 * 0xE10) + (f32) (arg0->unk4 * 0x3C) + (f32) arg0->unk8 + ((f32) arg0->unkC / 1000.0f);
}

void Timer_GetSystemTime(TimerInfo *arg0) {
    OSCalendarTime sp8;

    OSTicksToCalendarTime(OSGetTime(), &sp8);
    arg0->unk0 = sp8.hour;
    arg0->unk4 = sp8.min;
    arg0->unk8 = sp8.sec;
    arg0->unkC = sp8.msec;
    arg0->unk10 = sp8.mday;
    arg0->unk14 = sp8.mon + 1;
    arg0->unk18 = sp8.year;
}

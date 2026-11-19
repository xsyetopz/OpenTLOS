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

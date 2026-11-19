#ifndef COMMON_SOURCE_TIMER_H
#define COMMON_SOURCE_TIMER_H

#include <dolphin/types.h>

class TimerInfo;

void Timer_GetDifference(TimerInfo *, TimerInfo *, TimerInfo *);
void Timer_SetDHMSInSeconds(TimerInfo *, float);
f32 Timer_GetDHMSInSeconds(TimerInfo *);
void Timer_GetSystemTime(TimerInfo *);
extern f32 gApplicationTime;
#endif  // COMMON_SOURCE_TIMER_H

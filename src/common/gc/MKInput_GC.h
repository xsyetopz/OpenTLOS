#ifndef COMMON_GC_MKINPUT_GC_H
#define COMMON_GC_MKINPUT_GC_H

#include <dolphin/types.h>

class MKInputDevices;
class MKInputEvent;

s32 MKInput_GetNextKeybEventPlatformSpecific(MKInputEvent *);
void MKInput_InitModulePlatformSpecific(void);
void MKInput_Vibrate(MKInputDevices, float, float);
s32 MKInput_GetButtonType(int, MKInputDevices);
f32 MKInput_GetStatePlatformSpecific(int, MKInputDevices, float *);
s32 MKInput_GetStatus(MKInputDevices);
void MKInput_UpdatePlatformSpecific(void);
#endif  // COMMON_GC_MKINPUT_GC_H

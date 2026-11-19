#ifndef COMMON_SOURCE_MKRUMBLE_H
#define COMMON_SOURCE_MKRUMBLE_H

#include <dolphin/types.h>

class MKInputDevices;

u8 MKRumble_IsMuted(void);
void MKRumble_Mute(bool);
void MKRumble_Pop(void);
void MKRumble_Push(void);
void MKRumble_Stop(MKInputDevices);
void MKRumble_Play(MKInputDevices, float, float, float, char, float);
void MKRumble_Update(void);
void MKRumble_Reset(void);
u8 MKRumble_Enable(bool);
#endif  // COMMON_SOURCE_MKRUMBLE_H

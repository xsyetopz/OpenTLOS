#ifndef SPYRO_SOURCE_UICONTROLS_H
#define SPYRO_SOURCE_UICONTROLS_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class UIInputTracker;

class UIInputTracker {
public:
    void CheckDirection(int, int, float);
    void Update(void);
    void Init(MKInputDevices);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
    /* 0x005 */ u8 unk5;
    /* 0x006 */ u8 pad6[0x16];
    /* 0x01c */ u8 unk1C;
};

void UIControls_Ignore(bool);
void UIControls_Reset(void);
void UIControls_SetDevice(MKInputDevices);
void UIControls_Init(void);
void UIControls_Update(void);
s32 UIControls_Held(FrontEndControls, int);
s32 UIControls_Pressed(FrontEndControls, int);
u8 UIControls_DirectionPressed(FrontEndControls, int);
void * UIInput(int);
#endif  // SPYRO_SOURCE_UICONTROLS_H

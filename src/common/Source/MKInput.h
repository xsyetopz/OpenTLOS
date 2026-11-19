#ifndef COMMON_SOURCE_MKINPUT_H
#define COMMON_SOURCE_MKINPUT_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKInputEvent;
class MKInputReceiver;

class MKInputReceiver {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ u32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ void* unkC;
    /* 0x010 */ MKInputReceiver* unk10;
    /* 0x014 */ MKInputReceiver* unk14;
};

void MKInput_DespatchEvents(void);
void MKInputReceiver_Destroy(MKInputReceiver *);
MKInputReceiver * MKInputReceiver_Create(bool (*)(MKInputEvent *, void *), int, int, void *);
s32 MKInput_Released(int, MKInputDevices);
s32 MKInput_Pressed(int, MKInputDevices);
f32 MKInput_GetState(int, MKInputDevices, float *, bool *);
void MKInput_Update(void);
void MKInput_InitModule(void);
extern s32 MKInput_LastUsedDevice;
#endif  // COMMON_SOURCE_MKINPUT_H

#include "spyro/source/RumbleTimer.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/MKWidgetsInternal.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/GameData.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/MKRumble.h"
#include <m2c_macros.h>

extern u8 bStopped;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern MKInputReceiver *pReceiver;
static f32 timer = 15.0f;

void RumbleTimer_Update() {
    u8 StopRumbling(void);

    ((GameData *) GameData::gameData)->GetGameSettings();
    if ((u8) M2C_FIELD(GameData::gameData, u8 *, 0x52) != 0) {
        timer -= gUpdateTimeDelta;
        if (StopRumbling() != 0) {
            if ((u8) bStopped == 0) {
                MKRumble_Reset();
                MKRumble_Enable(0U);
                bStopped = 1;
            }
        } else if (((u8) bStopped != 0) && ((s32) M2C_FIELD(&gb, s32 *, 0x350) != 0)) {
            MKRumble_Enable(1U);
            bStopped = 0;
        }
    }
}

u8 StopRumbling() {
    s32 var_r30_68;

    var_r30_68 = 0;
loop_1:
    if (MKInput_GetState(var_r30_68, (MKInputDevices) *M2C_FIELD(&gb, s32 **, 0x354), NULL, NULL) != 0.0f) {
        timer = 15.0f;
    } else {
        var_r30_68 += 1;
        if (var_r30_68 < 0x15) {
            goto loop_1;
        }
    }
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}

void RumbleTimer_Deinit() {
    MKInputReceiver_Destroy(pReceiver);
    pReceiver = NULL;
}

void RumbleTimer_Init() {
    s32 InputReceiver(MKInputEvent *, void *);

    bStopped = 0;
    timer = 15.0f;
    pReceiver = MKInputReceiver_Create((bool (*)(MKInputEvent *, void *)) InputReceiver, -1, 5, NULL);
}

s32 InputReceiver(MKInputEvent *arg0, void *arg1) {
    timer = 15.0f;
    return 1;
}

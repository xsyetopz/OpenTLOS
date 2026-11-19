#include "spyro/source/RumbleTimer.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKWidgetsInternal.h"
#include "spyro/source/GameData.h"
#include "common/Source/MKRumble.h"
#include <m2c_macros.h>

extern u8 bStopped;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern MKInputReceiver *pReceiver;
static f32 timer = 15.0f;

#if 0 // DRAFT: undefined identifier 'StopRumbling'
void RumbleTimer_Update() {
    ((GameData *) (&GameData::gameData))->GetGameSettings();
    if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), u8 *, 0x12) != 0) {
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
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long' to
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
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}
#endif

void RumbleTimer_Deinit() {
    MKInputReceiver_Destroy(pReceiver);
    pReceiver = NULL;
}

#if 0 // DRAFT: undefined identifier 'InputReceiver'
void RumbleTimer_Init() {
    bStopped = 0;
    timer = 15.0f;
    pReceiver = MKInputReceiver_Create((u8 (*)(MKInputEvent *, void *)) InputReceiver, -1, 5, NULL);
}
#endif

s32 InputReceiver(MKInputEvent *arg0, void *arg1) {
    timer = 15.0f;
    return 1;
}

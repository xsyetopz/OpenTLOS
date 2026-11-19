#include "spyro/source/GameVideo.h"
#include "common/Source/MKHeap.h"
#include "spyro/source/EventCamera.h"
#include "unplaced_enums.h"
#include "common/Source/MKSystem.h"
#include "common/Source/Str.h"
#include "common/Source/Video.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/Subtitles.h"
#include <m2c_macros.h>

extern M2C_UNK gDisplay;
extern f32 gUpdateTimeDelta;
extern void (*pEventCallback)(M2C_UNK);
static MKHeap *video = NULL;

s32 GameVideo_Ready(GameVideo *arg0) {
    u8 var_r4_14;

    var_r4_14 = 0;
    if ((arg0 != NULL) && ((Video *) arg0->unk0 != NULL)) {
        var_r4_14 = 1;
    }
    if (var_r4_14 != 0) {
        return Video_IsReady(arg0->unk0);
    }
    return 0;
}

s32 GameVideo_Active() {
    return video != NULL;
}

f32 GameVideo_GetRemainingTime(GameVideo *arg0) {
    Video *temp_r3_55;

    if (arg0 != NULL) {
        temp_r3_55 = arg0->unk0;
        if (temp_r3_55 != NULL) {
            return Video_GetRemainingTime(temp_r3_55);
        }
    }
    return 0.0f;
}

f32 GameVideo_GetElapsedTime(GameVideo *arg0) {
    if ((arg0 != NULL) && ((Video *) arg0->unk0 != NULL)) {
        return arg0->unk8;
    }
    return 0.0f;
}

void GameVideo_Draw(GameVideo *arg0) {
    Video *temp_r3_93;

    if ((arg0 != NULL) && (temp_r3_93 = arg0->unk0, ((temp_r3_93 == NULL) == 0))) {
        if (arg0->unk4 & 1) {
            if ((System_IsWideScreenEnabled() != 0) || (arg0->unk4 & 2)) {
                Video_Draw(arg0->unk0, -108.0f, 0.0f, 748.0f, 512.0f, 0.5f);
                return;
            }
            Video_Draw(arg0->unk0, 0.0f, 76.0f, 640.0f, 436.0f, 0.5f);
            return;
        }
        Video_Draw(temp_r3_93, 0.0f, 0.0f, 640.0f, 512.0f, 0.5f);
    }
}

s32 GameVideo_Update(GameVideo *arg0) {
    if ((arg0 != NULL) && ((Video *) arg0->unk0 != NULL)) {
        arg0->unk8 += gUpdateTimeDelta;
        return Video_Update(arg0->unk0);
    }
    return 0;
}

void GameVideo_Destroy(GameVideo *arg0) {
    if ((arg0 != NULL) && ((Video *) arg0->unk0 != NULL)) {
        Subtitles_Deinit();
        Video_Destroy(arg0->unk0);
        arg0->unk0 = NULL;
        if (((void (*)(M2C_UNK)) pEventCallback) != NULL) {
            pEventCallback(1);
        }
    }
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 GameVideo_Create(const char *arg0, int arg1, int arg2) {
    s32 spC;
    s32 sp8;
    EventCamera *temp_r3_216;
    MKHeap *temp_r3_264;
    s32 temp_r0_295;
    s32 var_r3_237;
    s8 *var_r5_253;

    if ((MKHeap *) M2C_FIELD(&video, MKHeap **, 0) != NULL) {
        return 0;
    }
    if (EventCamera_GetCurrent() != NULL) {
        temp_r3_216 = EventCamera_GetCurrent();
        spC = 0;
        sp8 = 0xB4;
        M2C_FIELD(temp_r3_216->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    if (((void (*)(M2C_UNK)) pEventCallback) != NULL) {
        pEventCallback(0);
    }
    if (arg2 < 0) {
        var_r3_237 = GameLanguage_GetAudioTrack(-1);
    } else {
        var_r3_237 = 0;
    }
    if (M2C_FIELD(&gDisplay, f32 *, 8) > 55.0f) {
        var_r5_253 = "_60";
    } else {
        var_r5_253 = "_50";
    }
    temp_r3_264 = Video_CreateStreaming(Str_Printf("%s%s", arg0, var_r5_253, M2C_FIELD(&gDisplay, f32 *, 8)), 1U, var_r3_237, NULL, 0);
    M2C_FIELD(&video, MKHeap **, 0) = temp_r3_264;
    M2C_FIELD(&video, s32 *, 4) = arg1;
    if ((temp_r3_264 == NULL) && (((void (*)(M2C_UNK)) pEventCallback) != NULL)) {
        pEventCallback(1);
    }
    if ((MKHeap *) M2C_FIELD(&video, MKHeap **, 0) != NULL) {
        Video_SetLooping((Video *) M2C_FIELD(&video, MKHeap **, 0), ((u32) M2C_FIELD(&video, s32 *, 4) >> 2U) & 1);
    }
    M2C_FIELD(&video, f32 *, 8) = 0.0f;
    Subtitles_Init(arg0);
    temp_r0_295 = 0 - M2C_FIELD(&video, MKHeap **, 0);
    return (s32) &video & ((temp_r0_295 - temp_r0_295) - !M2C_CARRY);
}
#endif

void GameVideo_Init(void (*arg0)(GameVideoEvent)) {
    pEventCallback = (void (*)(M2C_UNK)) arg0;
}

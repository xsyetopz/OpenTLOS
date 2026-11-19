s32 GameVideo_Create(const char *arg0, int arg1, int arg2) {
    s32 msg[2];
    EventCamera *temp_r3_216;
    MKHeap *temp_r3_264;
    s32 var_r3_237;
    s8 *var_r5_253;

    if ((MKHeap *) M2C_FIELD(&video, MKHeap **, 0) != NULL) {
        return 0;
    }
    if (EventCamera_GetCurrent() != NULL) {
        temp_r3_216 = EventCamera_GetCurrent();
        msg[1] = 0;
        msg[0] = 0xB4;
        M2C_FIELD(M2C_FIELD(temp_r3_216, void **, 0x44), void (**)(EventCamera *, s32 *), 0x2C)(temp_r3_216, msg);
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
        var_r5_253 = (signed char *) ("_60");
    } else {
        var_r5_253 = (signed char *) ("_50");
    }
    temp_r3_264 = Video_CreateStreaming((const char *) Str_Printf("%s%s", arg0, var_r5_253), true, var_r3_237, NULL, 0);
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
    return (M2C_FIELD(&video, MKHeap **, 0) != NULL) ? (s32) &video : 0;
}

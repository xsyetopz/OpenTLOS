void Subtitles_Update() {
    f32 divisor;
    f32 timer;
    s32 *temp_r26_272;
    s32 var_r5_155;

    s8 *Subtitles_GetText(const char *, s32 *);

    if ((u8) M2C_FIELD(&sub, u8 *, 0x84) != 0) {
        if (M2C_FIELD(&sub, s8 **, 4) != NULL) {
            if (gDisplay == 1) {
                divisor = 60.0f;
            } else {
                divisor = 50.0f;
            }
            timer = M2C_FIELD(&sub, f32 *, 0) - (1.0f / divisor);
            M2C_FIELD(&sub, f32 *, 0) = timer;
            if (timer <= 0.0f) {
                M2C_FIELD(&sub, s8 **, 4) = NULL;
                var_r5_155 = 5;
                if (M2C_FIELD(&sub, s32 *, 8) == 0) {
                    var_r5_155 = 9;
                }
                M2C_FIELD(&gb, CutsceneSystem **, 0xC)->SetCustomSubtitle(NULL, var_r5_155, M2C_FIELD(&sub, s32 *, 8) == 1);
            }
        } else if (M2C_FIELD(&sub, s32 *, 8) == 2) {
            if (gDisplay == 1) {
                divisor = 60.0f;
            } else {
                divisor = 50.0f;
            }
            timer = M2C_FIELD(&sub, f32 *, 0) - (1.0f / divisor);
            M2C_FIELD(&sub, f32 *, 0) = timer;
            if (timer <= 0.0f) {
                M2C_FIELD(&sub, s32 *, 8) = 0;
                M2C_FIELD(&sub, u8 *, 0x10) = 0U;
                M2C_FIELD(&sub, u8 *, 0x11) = 1U;
            }
        }
        if ((u8) M2C_FIELD(&sub, u8 *, 0x10) != 0) {
            if (gDisplay == 1) {
                divisor = 60.0f;
            } else {
                divisor = 50.0f;
            }
            timer = M2C_FIELD(&sub, f32 *, 0xC) + (1.0f / divisor);
            M2C_FIELD(&sub, f32 *, 0xC) = timer;
            if (timer >= 1.0f) {
                M2C_FIELD(&sub, f32 *, 0xC) = 1.0f;
                M2C_FIELD(&sub, u8 *, 0x10) = 0U;
            }
        } else if ((u8) M2C_FIELD(&sub, u8 *, 0x11) != 0) {
            if (gDisplay == 1) {
                divisor = 60.0f;
            } else {
                divisor = 50.0f;
            }
            timer = M2C_FIELD(&sub, f32 *, 0xC) - (1.0f / divisor);
            M2C_FIELD(&sub, f32 *, 0xC) = timer;
            if (timer <= 0.0f) {
                M2C_FIELD(&sub, f32 *, 0xC) = 0.0f;
                M2C_FIELD(&sub, u8 *, 0x10) = 0U;
                M2C_FIELD(&sub, u8 *, 0x11) = 0U;
            }
        }
        if (gDisplay == 1) {
            divisor = 60.0f;
        } else {
            divisor = 50.0f;
        }
        temp_r26_272 = (s32 *) ((u8 *) &sub + 0x80);
        M2C_FIELD(&sub, f32 *, 0x70) = M2C_FIELD(&sub, f32 *, 0x70) + (1.0f / divisor);
loop_38:
        if (M2C_FIELD(&sub, MKIniLine **, 0x64) != NULL && M2C_FIELD(&sub, MKIniLine **, 0x64)->GetFloat(0) <= M2C_FIELD(&sub, f32 *, 0x70)) {
            if ((u8) M2C_FIELD(&sub, MKIniLine **, 0x64)->IsField("subtitle") != 0) {
                M2C_FIELD(&sub, s8 **, 4) = Subtitles_GetText((const char *) M2C_FIELD(&sub, MKIniLine **, 0x64)->GetString(2), temp_r26_272);
                M2C_FIELD(&sub, s32 *, 8) = 0;
                M2C_FIELD(&sub, f32 *, 0) = M2C_FIELD(&sub, MKIniLine **, 0x64)->GetFloat(1);
                M2C_FIELD(&gb, CutsceneSystem **, 0xC)->SetCustomSubtitle((const char *) M2C_FIELD(&sub, s8 **, 4), 9, 0U);
            } else if ((u8) M2C_FIELD(&sub, MKIniLine **, 0x64)->IsField("credit") != 0) {
                M2C_FIELD(&sub, s8 **, 4) = Subtitles_GetText((const char *) M2C_FIELD(&sub, MKIniLine **, 0x64)->GetString(2), temp_r26_272);
                M2C_FIELD(&sub, s32 *, 8) = 1;
                M2C_FIELD(&sub, f32 *, 0) = M2C_FIELD(&sub, MKIniLine **, 0x64)->GetFloat(1);
                M2C_FIELD(&gb, CutsceneSystem **, 0xC)->SetCustomSubtitle((const char *) M2C_FIELD(&sub, s8 **, 4), 5, 1U);
            } else if ((u8) M2C_FIELD(&sub, MKIniLine **, 0x64)->IsField("logo") != 0) {
                M2C_FIELD(&sub, s8 **, 4) = NULL;
                M2C_FIELD(&sub, f32 *, 0) = M2C_FIELD(&sub, MKIniLine **, 0x64)->GetFloat(1);
                M2C_FIELD(&sub, s32 *, 8) = 2;
                M2C_FIELD(&sub, u8 *, 0x10) = 1U;
                M2C_FIELD(&sub, u8 *, 0x11) = 0U;
                M2C_FIELD(&sub, f32 *, 0xC) = 0.0f;
            }
            M2C_FIELD(&sub, MKIniLine **, 0x64) = M2C_FIELD(&sub, MKIniLine **, 0x64)->unkC->GetNextLine(M2C_FIELD(&sub, MKIniLine **, 0x64));
            goto loop_38;
        }
    }
}

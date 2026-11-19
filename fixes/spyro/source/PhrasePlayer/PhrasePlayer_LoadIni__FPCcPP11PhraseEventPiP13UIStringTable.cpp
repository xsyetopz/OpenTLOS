void PhrasePlayer_LoadIni(const char *arg0, PhraseEvent **arg1, int *arg2, UIStringTable *arg3) {
    MKIni sp20;
    s8 sp8[0x18];
    MKIniLine *var_r26_739;
    MKIniLine *var_r27_619;
    MKIniLine *var_r28_704;
    MKIniLine *var_r29_640;
    PhraseEvent *var_r3_688;
    s32 *var_r27_716;
    s32 i;
    s32 temp_len;
    s32 temp_r25_680;
    s32 var_r25_701;
    s32 var_r28_616;

    memset(sp8, 0, 0x18U);
    MKHeap::ActivateTempMemOverride();
    sp20.Init(arg0, 0, NULL);
    MKHeap::DeactivateTempMemOverride();
    var_r28_616 = 0;
    var_r27_619 = sp20.GetFirstLine();
    while (var_r27_619 != NULL) {
        if (var_r27_619->IsField("defaults") == 0) {
            *arg2 += 1;
        }
        var_r28_616 = strlen((const char *) var_r27_619->GetFieldName()) + var_r28_616 + 1;
        var_r29_640 = var_r27_619->unkC->GetSubLine(var_r27_619);
        while (var_r29_640 != NULL) {
            if (var_r29_640->IsField("phrase") != 0) {
                var_r28_616 = strlen((const char *) var_r29_640->GetString(0)) + var_r28_616 + 1;
            }
            var_r29_640 = var_r29_640->unkC->GetNextLine(var_r29_640);
        }
        var_r27_619 = var_r27_619->unkC->GetNextLine(var_r27_619);
    }
    if (*arg2 == 0) {
        sp20.Deinit();
        return;
    }
    arg3->Init(var_r28_616);
    temp_r25_680 = *arg2 * 0x18;
    if (MKHeap::Current() != NULL) {
        var_r3_688 = (PhraseEvent *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r25_680, NULL, 0));
    } else {
        var_r3_688 = (PhraseEvent *) malloc(temp_r25_680);
    }
    *arg1 = var_r3_688;
    memset(*arg1, 0, *arg2 * 0x18);
    var_r25_701 = 0;
    var_r28_704 = sp20.GetFirstLine();
    while (var_r28_704 != NULL) {
        if (var_r28_704->IsField("defaults") != 0) {
            M2C_FIELD(sp8, s32 *, 8) = -1;
            M2C_FIELD(sp8, s32 *, 0xC) = 0;
            M2C_FIELD(sp8, s32 *, 0x10) = 0;
            M2C_FIELD(sp8, u8 *, 0x14) = 0;
            var_r27_716 = (s32 *) sp8;
        } else {
            var_r27_716 = (s32 *) ((s8 *) *arg1 + var_r25_701);
            var_r25_701 += 0x18;
            memcpy(var_r27_716, sp8, 0x18U);
            M2C_FIELD(var_r27_716, const char **, 0) = (const char *) arg3->Add((const char *) var_r28_704->GetFieldName());
        }
        var_r26_739 = var_r28_704->unkC->GetSubLine(var_r28_704);
        while (var_r26_739 != NULL) {
            if ((var_r26_739->IsField("Phrase") != 0) && (var_r28_704->IsField("defaults") == 0)) {
                M2C_FIELD(var_r27_716, const char **, 4) = (const char *) arg3->Add((const char *) var_r26_739->GetString(0));
                temp_len = strlen(M2C_FIELD(var_r27_716, const char **, 4));
                if (temp_len != 0) {
                    for (i = 0; i <= temp_len; i++) {
                        if ((((s8 *) M2C_FIELD(var_r27_716, const char **, 4))[i] == 0x20) || (((s8 *) M2C_FIELD(var_r27_716, const char **, 4))[i] == 0)) {
                            M2C_FIELD(var_r27_716, s32 *, 0xC) += 1;
                        }
                    }
                }
            } else if (var_r26_739->IsField("Type") != 0) {
                if (stricmp((s8 *) var_r26_739->GetString(0), (s8 *) "Linear") == 0) {
                    M2C_FIELD(var_r27_716, s32 *, 0x10) = 0;
                } else if (stricmp((s8 *) var_r26_739->GetString(0), (s8 *) "Random") == 0) {
                    M2C_FIELD(var_r27_716, s32 *, 0x10) = 1;
                } else if (stricmp((s8 *) var_r26_739->GetString(0), (s8 *) "Conversation") == 0) {
                    M2C_FIELD(var_r27_716, s32 *, 0x10) = 2;
                }
            } else {
                var_r26_739->LoadBool("Priority", (bool *) ((s8 *) var_r27_716 + 0x14), 0);
            }
            var_r26_739 = var_r26_739->unkC->GetNextLine(var_r26_739);
        }
        if (M2C_FIELD(var_r27_716, s32 *, 0xC) == 0) {
            var_r28_704->IsField("defaults");
        }
        var_r28_704 = var_r28_704->unkC->GetNextLine(var_r28_704);
    }
    sp20.Deinit();
}

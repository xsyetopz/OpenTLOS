s32 EnemyGeneratorDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;
    MKIniLine *var_r24_38;
    MKIniLine *var_r25_166;
    MKIniLine *var_r25_286;
    MKIniLine *var_r26_117;
    s32 temp_r26_92;
    s32 temp_r27_67;
    s32 var_r26_33;
    s32 var_r28_32;
    s32 var_r29_29;
    s32 var_r30_34;
    void *var_r3_100;
    void *var_r3_75;

    if (arg0->IsField("EnemyGenerator") != 0) {
        var_r29_29 = 0;
        sp8 = NULL;
        var_r28_32 = 0;
        var_r26_33 = 0;
        var_r30_34 = 0;
        var_r24_38 = arg0->unkC->GetSubLine(arg0);
loop_7:
        if (var_r24_38 != NULL) {
            if (var_r24_38->IsField("Door") != 0) {
                var_r28_32 += 1;
            }
            if (var_r24_38->IsField("Wave") != 0) {
                var_r26_33 += 1;
            }
            var_r24_38 = var_r24_38->unkC->GetNextLine(var_r24_38);
            goto loop_7;
        }
        if (var_r28_32 > 0) {
            this->unk8 = var_r28_32;
            temp_r27_67 = this->unk8 * 0x24;
            if (MKHeap::Current() != NULL) {
                var_r3_75 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_67, NULL, 0);
            } else {
                var_r3_75 = malloc(temp_r27_67);
            }
            this->unk10 = var_r3_75;
            memset(this->unk10, 0, this->unk8 * 0x24);
        }
        if (var_r26_33 > 0) {
            this->unkC = var_r26_33;
            temp_r26_92 = this->unkC * 0x14;
            if (MKHeap::Current() != NULL) {
                var_r3_100 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r26_92, NULL, 0);
            } else {
                var_r3_100 = malloc(temp_r26_92);
            }
            this->unk14 = var_r3_100;
            memset(this->unk14, 0, this->unkC * 0x14);
        }
        var_r26_117 = arg0->unkC->GetSubLine(arg0);
loop_49:
        if (var_r26_117 != NULL) {
            if ((var_r26_117->LoadInt("spawnPointProps", (int *) &this->unk0, 0) == 0) && (var_r26_117->LoadInt("doorProps", (int *) &this->unk4, 0) == 0) && (var_r26_117->LoadBool("bLockSpawnPoints", (bool *) &this->unk18, 0) == 0) && (var_r26_117->LoadBool("bSpawnFromVisibleDoors", (bool *) &this->unk19, 0) == 0)) {
                if (var_r26_117->IsField("Door") != 0) {
                    var_r25_166 = var_r26_117->unkC->GetSubLine(var_r26_117);
loop_35:
                    if (var_r25_166 != NULL) {
                        if ((var_r25_166->LoadInt("spawnPointProp", (int *) (((u8 *) this->unk10) + var_r30_34), 0) == 0) && (var_r25_166->LoadInt("doorProp", (int *) (((u8 *) this->unk10) + (var_r30_34 + 4)), 0) == 0) && (var_r25_166->LoadString("doorRefPt", (const char **) (((u8 *) this->unk10) + (var_r30_34 + 8)), 0) == 0) && (var_r25_166->LoadString("spawnRefPt", (const char **) (((u8 *) this->unk10) + (var_r30_34 + 0xC)), 0) == 0) && (var_r25_166->LoadString("openingScript", (const char **) (((u8 *) this->unk10) + (var_r30_34 + 0x10)), 0) == 0) && (var_r25_166->LoadString("closingScript", (const char **) (((u8 *) this->unk10) + (var_r30_34 + 0x14)), 0) == 0) && (var_r25_166->LoadString("openScript", (const char **) (((u8 *) this->unk10) + (var_r30_34 + 0x18)), 0) == 0) && (var_r25_166->LoadString("closedScript", (const char **) (((u8 *) this->unk10) + (var_r30_34 + 0x1C)), 0) == 0)) {
                            var_r25_166->LoadBool("bAnimate", (bool *) (((u8 *) this->unk10) + (var_r30_34 + 0x20)), 0);
                        }
                        var_r25_166 = var_r25_166->unkC->GetNextLine(var_r25_166);
                        goto loop_35;
                    }
                    var_r30_34 += 0x24;
                } else if (var_r26_117->IsField("Wave") != 0) {
                    var_r25_286 = var_r26_117->unkC->GetSubLine(var_r26_117);
loop_46:
                    if (var_r25_286 != NULL) {
                        if ((var_r25_286->LoadInt("iMaxSpawnAmount", (int *) (((u8 *) this->unk14) + var_r29_29), 0) == 0) && (var_r25_286->LoadInt("iMaxActive", (int *) (((u8 *) this->unk14) + (var_r29_29 + 4)), 0) == 0) && (var_r25_286->LoadFloat("fSpawnDelay", (float *) (((u8 *) this->unk14) + (var_r29_29 + 0xC)), 0) == 0) && (var_r25_286->LoadFloat("fDelayBetweenSpawns", (float *) (((u8 *) this->unk14) + (var_r29_29 + 0x10)), 0) == 0) && (var_r25_286->LoadString("iEnemyType", (const char **) (&sp8), 0) != 0)) {
                            *(s32 *) (((u8 *) this->unk14) + (var_r29_29 + 8)) = DataMap_GetValue(&enemyTypeDataMap, (const char *) sp8);
                        }
                        var_r25_286 = var_r25_286->unkC->GetNextLine(var_r25_286);
                        goto loop_46;
                    }
                    var_r29_29 += 0x14;
                }
            }
            var_r26_117 = var_r26_117->unkC->GetNextLine(var_r26_117);
            goto loop_49;
        }
        return 1;
    }
    return 0;
}

void SpawnerObject::Deinit() {
    SpawnerObject ***var_r30_1294;
    SpawnerObject **temp_r3_1302;
    s32 var_r30_1306;
    u32 *var_r4_1305;
    u32 *var_r3_1307;
    u32 temp_r0_1310;
    u32 temp_r0_1315;
    u32 temp_r0_1329;
    u32 *temp_r3_1355;
    u32 *temp_r30_1360;
    s32 var_r30_1384;
    u32 *var_r4_1383;
    u32 *var_r3_1385;
    u32 temp_r0_1388;
    u32 temp_r0_1393;
    u32 temp_r0_1407;

    SetParentSpawner(NULL);
    var_r30_1294 = (SpawnerObject ***) this->unk8.unk0;
    temp_r3_1302 = *var_r30_1294;
    while (temp_r3_1302 != NULL) {
        (*temp_r3_1302)->SetParentSpawner(NULL);
        var_r30_1294 += 1;
        temp_r3_1302 = *var_r30_1294;
    }
    var_r4_1305 = (u32 *) this->unk8.unk0;
    var_r30_1306 = (s32) var_r4_1305;
    var_r3_1307 = var_r4_1305;
    temp_r0_1315 = M2C_FIELD(var_r3_1307, u32 *, -4);
    var_r3_1307 -= 1;
    while (temp_r0_1315 != 0U) {
        temp_r0_1310 = *var_r3_1307;
        if (temp_r0_1310 < (u32) var_r30_1306) {
            var_r30_1306 = (s32) temp_r0_1310;
        }
        temp_r0_1315 = M2C_FIELD(var_r3_1307, u32 *, -4);
        var_r3_1307 -= 1;
    }
    if ((u32) var_r3_1307 != (u32) &gEmptyPtrListDL) {
        temp_r0_1329 = *var_r4_1305;
        while (temp_r0_1329 != 0U) {
            if (temp_r0_1329 < (u32) var_r30_1306) {
                var_r30_1306 = (s32) temp_r0_1329;
            }
            var_r4_1305 += 1;
            temp_r0_1329 = *var_r4_1305;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r30_1306, NULL, 0);
        } else {
            free((u32 *) var_r30_1306);
        }
    }
    this->unk8.unk0 = 0;
    RemoveAllSpawnPoints(0);
    if (((u8) this->unk4C >> 7U) & 1) {
        do {
            temp_r3_1355 = this->unk44 - 1;
            this->unk44 = temp_r3_1355;
        } while ((u32) *temp_r3_1355 != 0);
        temp_r30_1360 = this->unk44;
        if (temp_r30_1360 != (u32 *) &gEmptyPtrList) {
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r30_1360, NULL, 0);
            } else {
                free(temp_r30_1360);
            }
        }
        this->unk44 = NULL;
    }
    if (((u8) this->unk4C >> 6U) & 1) {
        var_r4_1383 = (u32 *) this->unk48;
        var_r30_1384 = (s32) var_r4_1383;
        var_r3_1385 = var_r4_1383;
        temp_r0_1393 = M2C_FIELD(var_r3_1385, u32 *, -4);
        var_r3_1385 -= 1;
        while (temp_r0_1393 != 0U) {
            temp_r0_1388 = *var_r3_1385;
            if (temp_r0_1388 < (u32) var_r30_1384) {
                var_r30_1384 = (s32) temp_r0_1388;
            }
            temp_r0_1393 = M2C_FIELD(var_r3_1385, u32 *, -4);
            var_r3_1385 -= 1;
        }
        if ((u32) var_r3_1385 != (u32) &gEmptyPtrListDL) {
            temp_r0_1407 = *var_r4_1383;
            while (temp_r0_1407 != 0U) {
                if (temp_r0_1407 < (u32) var_r30_1384) {
                    var_r30_1384 = (s32) temp_r0_1407;
                }
                var_r4_1383 += 1;
                temp_r0_1407 = *var_r4_1383;
            }
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free((void *) var_r30_1384, NULL, 0);
            } else {
                free((u32 *) var_r30_1384);
            }
        }
        this->unk48 = NULL;
    }
    this->unk4C &= ~0x80;
    this->unk4C &= ~0x40;
}

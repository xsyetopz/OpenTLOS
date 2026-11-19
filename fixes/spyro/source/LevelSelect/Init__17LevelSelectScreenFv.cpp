void LevelSelectScreen::Init() {
    s32 temp_r27_503;
    s8 *root;
    s8 *var_r30_523;
    s8 *var_r29_560;
    s8 *temp_r26_562;
    s8 *temp_r3_538;
    s8 *temp_r5_537;
    s8 *var_r4_541;
    s8 *temp_r0_546;
    s8 *temp_r5_580;
    s8 *temp_r3_583;
    s8 *var_r4_585;
    s8 *temp_r0_590;
    s8 *var_r0_612;
    s32 var_r31_522;
    s32 var_r28_524;
    s32 var_r27_561;

    UIContainer::Init();
    temp_r27_503 = (*(s32 *) Level::levelInfoCount + (*(s32 *) Level::chunkInfoCount + 1)) << 6;
    if (MKHeap::Current() != NULL) {
        root = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_503, NULL, 0));
    } else {
        root = (s8 *) malloc(temp_r27_503);
    }
    pMenuRoot = (UIObject *) root;
    memset(root, 0, (u32) temp_r27_503);
    var_r31_522 = 1;
    var_r30_523 = *(s8 **) Level::pLevelInfo;
    var_r28_524 = 0x40;
    pMenuCurrent = pMenuRoot;
loop_26:
    if (var_r30_523 != NULL) {
        strncpy((char *) (root + var_r28_524),
                (const char *) M2C_FIELD(gpTranslation_StringArray, s8 **, M2C_FIELD(var_r30_523, s32 *, 0x10) * 4),
                0x28U);
        temp_r5_537 = M2C_FIELD(root, s8 **, 0x34);
        temp_r3_538 = root + var_r28_524;
        if (temp_r5_537 != NULL) {
            var_r4_541 = temp_r5_537;
loop_7:
            temp_r0_546 = M2C_FIELD(var_r4_541, s8 **, 0x30);
            if (temp_r0_546 != NULL) {
                var_r4_541 = temp_r0_546;
                goto loop_7;
            }
            M2C_FIELD(var_r4_541, s8 **, 0x30) = temp_r3_538;
            M2C_FIELD(temp_r3_538, s8 **, 0x38) = M2C_FIELD(temp_r5_537, s8 **, 0x38);
        } else {
            M2C_FIELD(root, s8 **, 0x34) = temp_r3_538;
            M2C_FIELD(temp_r3_538, s8 **, 0x38) = root;
        }
        var_r31_522 += 1;
        var_r29_560 = M2C_FIELD(var_r30_523, s8 **, 0x11C);
        var_r27_561 = var_r31_522 << 6;
        temp_r26_562 = root + var_r28_524;
        var_r28_524 += 0x40;
loop_21:
        if (var_r29_560 != NULL) {
            if ((var_r29_560 != M2C_FIELD(var_r30_523, s8 **, 0x118)) && (M2C_FIELD(var_r29_560, u8 *, 0x36) != 0)) {
                strncpy((char *) (root + var_r27_561), (const char *) M2C_FIELD(var_r29_560, s8 **, 0), 0x28U);
                M2C_FIELD(root, s8 **, var_r27_561 + 0x2C) = var_r29_560;
                temp_r5_580 = M2C_FIELD(temp_r26_562, s8 **, 0x34);
                temp_r3_583 = root + var_r27_561;
                if (temp_r5_580 != NULL) {
                    var_r4_585 = temp_r5_580;
loop_16:
                    temp_r0_590 = M2C_FIELD(var_r4_585, s8 **, 0x30);
                    if (temp_r0_590 != NULL) {
                        var_r4_585 = temp_r0_590;
                        goto loop_16;
                    }
                    M2C_FIELD(var_r4_585, s8 **, 0x30) = temp_r3_583;
                    M2C_FIELD(temp_r3_583, s8 **, 0x38) = M2C_FIELD(temp_r5_580, s8 **, 0x38);
                } else {
                    M2C_FIELD(temp_r26_562, s8 **, 0x34) = temp_r3_583;
                    M2C_FIELD(M2C_FIELD(temp_r26_562, s8 **, 0x34), s8 **, 0x38) = temp_r26_562;
                }
                var_r31_522 += 1;
                var_r28_524 += 0x40;
                var_r27_561 += 0x40;
            }
            var_r29_560 = M2C_FIELD(var_r29_560, s8 **, 8);
            goto loop_21;
        }
        if (var_r30_523 != NULL) {
            var_r0_612 = M2C_FIELD(var_r30_523, s8 **, 0x124);
        } else {
            var_r0_612 = *(s8 **) Level::pLevelInfo;
        }
        var_r30_523 = var_r0_612;
        goto loop_26;
    }
    pMenuCurrent = pMenuRoot;
}

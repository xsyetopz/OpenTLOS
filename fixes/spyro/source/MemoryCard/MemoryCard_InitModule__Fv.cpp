s8 *MemoryCard_String(char *, int);
void MemoryCard_InitModule() {
    MCLoadCheckScreen **slot;
    MCLoadCheckScreen *cur;
    s32 gdSize;

    MemoryCard_String((char *) gameNameBuffer, 3);
    M2C_FIELD(&memCardSlotSizes, s32 *, 0) = 3;
    gdSize = ((GameData *) GameData::gameData)->GetGameDataSize();
    M2C_FIELD(&memCardSlotSizes, s32 *, 0xC) = gdSize;
    M2C_FIELD(&memCardSlotSizes, s32 *, 8) = gdSize;
    M2C_FIELD(&memCardSlotSizes, s32 *, 4) = gdSize;
    MKMemoryCard_SetAppInfo((const char *) pDirectoryName, (const char *) gameNameBuffer, (int *) &memCardSlotSizes);
    KDMemoryCard::InitModule();
    Autosave_InitModule();

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCSaveScreen::descriptor;
            M2C_FIELD(MCSaveScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCSaveScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCSelectCardScreen::descriptor;
            M2C_FIELD(MCSelectCardScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCSelectCardScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCSelectFileScreen::descriptor;
            M2C_FIELD(MCSelectFileScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCSelectFileScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCActionScreen::descriptor;
            M2C_FIELD(MCActionScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCActionScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCQueryScreen::descriptor;
            M2C_FIELD(MCQueryScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCQueryScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCText::descriptor;
            M2C_FIELD(MCText::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCText::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) MCFileInfo::descriptor;
            M2C_FIELD(MCFileInfo::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) MCFileInfo::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }

    slot = &UIObjectDescriptor::list.unk0;
    for (;;) {
        cur = *slot;
        if (cur == NULL) {
            *slot = (MCLoadCheckScreen *) AutosaveWarningScreen::descriptor;
            M2C_FIELD(AutosaveWarningScreen::descriptor, s32 *, 0x10) = 0;
            break;
        }
        if (cur == (MCLoadCheckScreen *) AutosaveWarningScreen::descriptor) {
            break;
        }
        slot = (MCLoadCheckScreen **) ((s8 *) cur + 0x10);
    }
}

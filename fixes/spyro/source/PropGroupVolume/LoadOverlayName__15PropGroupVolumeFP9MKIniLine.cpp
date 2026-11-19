extern "C" s32 stricmp(const char *, const char *);

u8 PropGroupVolume::LoadOverlayName(MKIniLine *arg0) {
    s8 *sp8;
    s32 i;
    s32 off;
    s32 slot;
    s32 n;

    if (strnicmp((const char *) arg0->GetFieldName(), "overlay", 7) == 0) {
        arg0->AsString(0, (const char **) &sp8);
        if (stricmp((const char *) sp8, "none") == 0) {
            return 1U;
        }
        i = 0;
        off = 0;
        *(s32 *) ((s8 *) this + (this->unk2A4 * 4) + 0xA4) = -1;
        while (i < *(s32 *) PropGroupVolume::overlayCount) {
            if (M2C_FIELD((s8 *) &PropGroupVolume::overlay + off, s32 *, 0x24) > 0 && stricmp((const char *) sp8, (const char *) ((s8 *) &PropGroupVolume::overlay + off)) == 0) {
                *(s32 *) ((s8 *) this + (this->unk2A4 * 4) + 0xA4) = i;
                M2C_FIELD((s8 *) &PropGroupVolume::overlay + off, s32 *, 0x24) = M2C_FIELD((s8 *) &PropGroupVolume::overlay + off, s32 *, 0x24) + 1;
                break;
            }
            i += 1;
            off += 0x28;
        }
        slot = *(s32 *) ((s8 *) this + (this->unk2A4 * 4) + 0xA4);
        if (slot < 0) {
            n = 0;
            off = 0;
            while (n < 0x80 && M2C_FIELD((s8 *) &PropGroupVolume::overlay + off, s32 *, 0x24) != 0) {
                n += 1;
                off += 0x28;
            }
            off = n * 0x28;
            strcpy((char *) ((s8 *) &PropGroupVolume::overlay + off), (const char *) sp8);
            M2C_FIELD((s8 *) &PropGroupVolume::overlay + off, s32 *, 0x24) = 1;
            *(s32 *) ((s8 *) this + (this->unk2A4 * 4) + 0xA4) = n;
            if (n == *(s32 *) PropGroupVolume::overlayCount) {
                *(s32 *) PropGroupVolume::overlayCount += 1;
            }
        }
        this->unk2A4 += 1;
        return 1U;
    }
    return 0U;
}

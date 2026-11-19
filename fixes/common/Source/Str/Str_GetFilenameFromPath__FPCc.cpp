s8 *Str_GetFilenameFromPath(const char *arg0) {
    const char *p;
    s8 *dst;
    s32 newIndex;
    u32 len;

    p = arg0 + strlen(arg0);
    goto scan_check;
scan_step:
    p -= 1;
scan_check:
    if (p == arg0) {
        goto scan_done;
    }
    if (*p == '/' || *p == ':' || *p == '\\') {
        goto scan_done;
    }
    goto scan_step;
scan_done:
    if (*p == ':' || *p == '/' || *p == '\\') {
        p += 1;
    }
    dst = (s8 *) ((u8 *) &buffer + bufferIndex);
    strcpy((char *) dst, p);
    len = strlen((char *) dst);
    newIndex = bufferIndex + ((len + 0x10) & 0xFFFFFFF0);
    bufferIndex = newIndex;
    if ((s32) (newIndex + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    return dst;
}

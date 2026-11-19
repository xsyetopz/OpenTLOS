s8 *Str_Dup(const char *arg0) {
    s32 newIndex;
    s8 *dst;
    u32 len;

    len = strlen(arg0);
    dst = (s8 *) ((u8 *) &buffer + bufferIndex);
    strcpy((char *) dst, arg0);
    newIndex = bufferIndex + ((len + 0x10) & 0xFFFFFFF0);
    bufferIndex = newIndex;
    if ((s32) (newIndex + 0x400) > 0x4000) {
        bufferIndex = 0;
    }
    return dst;
}

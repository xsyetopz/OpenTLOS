void MKLevelChunk::QueueChunkLoad(const char *arg0, const char *arg1, bool arg2) {
    strcpy((char *) ((s8 *) this + 0x104), arg1);
    strcpy((char *) ((s8 *) this + 0xE4), arg0);
    if (arg2 != 0) {
        M2C_FIELD(this, s32 *, 0xA0) = 7;
        return;
    }
    M2C_FIELD(this, s32 *, 0xA0) = 0;
}

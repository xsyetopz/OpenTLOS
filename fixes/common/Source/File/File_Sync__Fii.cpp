s32 File_Sync(int arg0, int arg1) {
    while ((s32) M2C_FIELD((u8 *) &semaJobCount + 0x1340 + (arg0 * 0x58), s32 *, 0x44) != 0) {
        VIWaitForRetrace();
    }
    return 0;
}

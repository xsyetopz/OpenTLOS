s32 File_IsBusy(int arg0) {
    u8 *temp_r3;

    if ((arg0 != -1) && (arg0 < 0x14)) {
        temp_r3 = (u8 *) &semaJobCount + 0x1340 + (arg0 * 0x58);
        if ((s32) M2C_FIELD(temp_r3, s32 *, 0x3C) != -1) {
            return M2C_FIELD(temp_r3, s32 *, 0x44);
        }
    }
    return 0;
}

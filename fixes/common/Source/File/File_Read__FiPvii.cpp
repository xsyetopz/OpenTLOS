s32 File_Read(int arg0, void *arg1, int arg2, int arg3) {
    s32 var_r6_0;
    u32 temp_r0_372;
    u32 temp_r4_369;
    u32 temp_r4_371;
    u8 *temp_r31_332;
    u8 *temp_r8_337;

    var_r6_0 = arg3;
    if ((arg0 != -1) && (arg0 < 0x14)) {
        temp_r31_332 = (u8 *) &semaJobCount + 0x1340 + (arg0 * 0x58);
        if ((s32) M2C_FIELD(temp_r31_332, s32 *, 0x3C) != -1) {
            temp_r8_337 = (u8 *) &semaJobCount + 0x1A20;
            M2C_FIELD(temp_r8_337 + (jobListHead * 0x4C), s32 *, 0) = 2;
            M2C_FIELD(temp_r8_337 + (jobListHead * 0x4C), s32 *, 4) = arg0;
            M2C_FIELD(temp_r8_337 + (jobListHead * 0x4C), void **, 8) = arg1;
            M2C_FIELD(temp_r8_337 + (jobListHead * 0x4C), s32 *, 0xC) = arg2;
            if (var_r6_0 < arg2) {
                var_r6_0 = arg2;
            }
            M2C_FIELD(temp_r8_337 + (jobListHead * 0x4C), s32 *, 0x10) = var_r6_0;
            M2C_FIELD(temp_r31_332, s32 *, 0x48) = 0;
            M2C_FIELD(temp_r31_332, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r31_332, s32 *, 0x44) + 1);
            temp_r4_369 = jobListHead + 1;
            temp_r4_371 = temp_r4_369 >> 0x1FU;
            temp_r0_372 = (temp_r4_369 << 0x1C) - temp_r4_371;
            jobListHead = ((temp_r0_372 << 4) | (temp_r0_372 >> 0x1CU)) + temp_r4_371;
            OSSignalSemaphore(&semaJobCount);
            if ((u8) M2C_FIELD(temp_r31_332, u8 *, 0x50) == 0) {
loop_8:
                if ((s32) M2C_FIELD(temp_r31_332, s32 *, 0x44) != 0) {
                    VIWaitForRetrace();
                    goto loop_8;
                }
                return M2C_FIELD(temp_r31_332, s32 *, 0x4C);
            }
            return 0;
        }
    }
    return -1;
}

s32 File_IsAnyBusy() {
    s32 var_r28_45;
    s32 var_r29_43;
    s32 var_r31_46;

    OSYieldThread();
    var_r29_43 = 0;
    var_r28_45 = 0;
    var_r31_46 = 0;
    do {
        if ((s32) M2C_FIELD(((u8 *) &semaJobCount + 0x1340 + var_r31_46), s32 *, 0x3C) != -1) {
            var_r29_43 += File_IsBusy(var_r28_45);
        }
        var_r28_45 += 1;
        var_r31_46 += 0x58;
    } while (var_r28_45 < 0x14);
    return var_r29_43;
}

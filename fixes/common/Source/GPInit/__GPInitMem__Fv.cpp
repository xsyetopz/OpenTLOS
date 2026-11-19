void __GPInitMem() {
    u32 temp_r31_345;
    u32 temp_ret_346;
    void *temp_r31_354;
    void *temp_r3_355;
    void *temp_r3_361;
    s32 temp_r31_365;

    temp_r31_345 = OSGetPhysicalMemSize() >> 0x14U;
    temp_ret_346 = OSGetConsoleSimulatedMemSize();
    OSReport("Simulated Memory Size = %dMB\nPhysical Memory Size = %dMB\n", temp_ret_346 >> 0x14U, temp_r31_345);
    temp_r31_354 = OSGetArenaLo();
    temp_r3_355 = OSGetArenaHi();
    temp_r3_361 = OSInitAlloc(temp_r31_354, temp_r3_355, 1);
    OSSetArenaLo(temp_r3_361);
    temp_r31_365 = (s32) temp_r3_355 & 0xFFFFFFE0;
    OSSetCurrentHeap(OSCreateHeap((void *) ((s32) (((u8 *) temp_r3_361) + 0x1F) & 0xFFFFFFE0), (void *) temp_r31_365));
    OSSetArenaLo((void *) temp_r31_365);
    memset(&pBuffer, 0, 0xA9600U);
    DCStoreRange(&pBuffer, 0xA9600U);
}

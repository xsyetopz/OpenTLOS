void GPInit(_GXRenderModeObj *arg0) {
    u16 var_r28;
    u16 var_r29;
    u8 *var_r30;
    u8 *temp_r31;
    u8 *entry;
    u8 index;
    u32 color;

    OSInit();
    LCEnable();
    DVDInit();
    VIInit();
    PADInit();
    memset(&DefaultFifo, 0, 0x80020U);
    DCFlushRange(&DefaultFifo, 0x80020U);
    DefaultFifoObj = GXInit(&DefaultFifo, 0x80000U);
    __GPInitRenderMode(arg0);
    __GPInitMem();
    VIConfigure(rmode);
    VIConfigurePan(0U, 0U, 0x280U, rmode->viHeight);
    __GPInitGX();
    VISetBlack(1);
    VISetNextFrameBuffer(&pBuffer);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VISetBlack(0);
    VIFlush();
    GXDrawDone();
    if (gpLogoImage == NULL) {
        gpLogoImage = &MKMat_MK2_Standard_CaptureTextureData;
    }
    var_r29 = 0x108;
    temp_r31 = (u8 *) gpLogoImage + 0x36;
    var_r30 = (u8 *) gpLogoImage + 0x436;
    while (var_r29 > 0x88U) {
        var_r28 = 0x100;
        while (var_r28 < 0x180U) {
            index = *var_r30;
            var_r30 += 1;
            entry = temp_r31 + ((index * 4) & 0x3FC);
            color = entry[0] | (entry[2] << 0x10) | 0xFF000000 | (entry[1] << 8);
            GXPokeARGB(var_r28, var_r29, color);
            var_r28 += 1;
        }
        var_r29 -= 1;
    }
    VIWaitForRetrace();
    GXCopyDisp(&pBuffer, 1U);
}

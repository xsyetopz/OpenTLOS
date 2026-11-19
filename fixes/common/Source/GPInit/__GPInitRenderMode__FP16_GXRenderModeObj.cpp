void __GPInitRenderMode(_GXRenderModeObj *arg0) {
    s32 temp_r3_402;
    u16 temp_r30_477;
    u16 var_r31_0;
    u32 temp_ret_402;

    if (arg0 != NULL) {
        rmode = arg0;
        return;
    }
    temp_ret_402 = VIGetTvFormat();
    temp_r3_402 = temp_ret_402;
    switch (temp_r3_402) {
    case 0:
        var_r31_0 = 0x1E0;
        rmode = &GXNtsc480IntDf;
        break;
    case 1:
        var_r31_0 = 0x23E;
        rmode = &GXPal528IntDf;
        break;
    case 2:
        var_r31_0 = 0x1E0;
        rmode = &GXMpal480IntDf;
        break;
    default:
        OSPanic("GPInit.cpp", 0x149, "GPInit: invalid TV format\n");
        break;
    }
    rmode->fbWidth = 0x280;
    rmode->efbHeight = 0x190;
    rmode->viWidth = rmode->fbWidth;
    rmode->viXOrigin = (u16) ((s32) (0x2D0 - rmode->viWidth) / 2);
    rmode->viWidth += 0x14;
    rmode->viXOrigin -= 0xA;
    GXSetDispCopySrc(0U, 0U, rmode->fbWidth, rmode->efbHeight);
    temp_r30_477 = GXSetDispCopyYScale(GXGetYScaleFactor(rmode->efbHeight, (u16) (var_r31_0 - 0x20))) & 0xFFFE;
    GXSetDispCopyDst(rmode->fbWidth, temp_r30_477);
    rmode->xfbHeight = temp_r30_477;
    rmode->viHeight = temp_r30_477;
    rmode->viYOrigin = (u16) ((s32) (var_r31_0 - temp_r30_477) / 2);
}

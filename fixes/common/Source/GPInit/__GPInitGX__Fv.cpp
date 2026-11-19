void __GPInitGX() {
    GXColor sp8;
    void DrawSyncHandler(unsigned short);

    GXSetViewport(0.0f, 0.0f, 640.0f, (f32) rmode->efbHeight, 0.0f, 1.0f);
    GXSetScissor(0U, 0U, 0x280U, (u32) rmode->efbHeight);
    GXSetCopyFilter(rmode->aa, rmode->sample_pattern, 1U, rmode->vfilter);
    if ((u8) rmode->aa != 0) {
        GXSetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
    } else {
        *(s32 *) &sp8 = lit_480;
        GXSetCopyClear(sp8, 0xFFFFFFU);
        GXSetPixelFmt(GX_PF_RGBA6_Z24, GX_ZC_LINEAR);
    }
    GXCopyDisp(&pBuffer, 1U);
    GXSetDispCopyGamma(GX_GM_1_0);
    GXSetDrawSyncCallback(DrawSyncHandler);
}

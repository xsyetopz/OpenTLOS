#include "common/Source/GPInit.h"
#include "unplaced_enums.h"
#include "dolphin/dvd.h"
#include "dolphin/gx.h"
#include "dolphin/os.h"
#include "dolphin/pad.h"
#include "dolphin/vi.h"
#include "common/gc/MKVisibilityTest_GC.h"
#include <m2c_macros.h>

extern s32 lit_480;
extern GXFifoObj *DefaultFifoObj;
extern M2C_UNK MKMat_MK2_Standard_CaptureTextureData;
extern s32 THP_Initialized;
extern M2C_UNK gMKDefaults;
extern M2C_UNK *gpLogoImage;
extern u8 init_489;
extern u8 init_512;
extern u32 lastFrame_498;
extern s32 lastMode_511;
extern u32 lastRetrace_488;
extern u32 lastTick_465;
extern u32 lastTick_491;
extern GXRenderModeObj *rmode;
static M2C_UNK pBuffer;
static M2C_UNK DefaultFifo;
static s32 gFramesPerSecond = 0x3C;
static s32 gCPUFramesPerSecond = 0x3C;
static s32 gGPUFramesPerSecond = 0x3C;

void MK_SetVDMode(MK_VertexDescriptorMode arg0) {
    if ((s8) init_512 == 0) {
        lastMode_511 = -1;
        init_512 = 1;
    }
    if ((s32) arg0 != (s32) lastMode_511) {
        lastMode_511 = (s32) arg0;
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        if ((u32) arg0 <= 9U) {
            switch ((s32) arg0) {
            case 0:
                GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
                break;
            case 1:
                GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                break;
            case 2:
                GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
                break;
            case 3:
                GXSetVtxDesc(GX_VA_POS, GX_INDEX16);
                GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
                GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
                GXSetVtxDesc(GX_VA_TEX0, GX_INDEX16);
                break;
            case 4:
                GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
                GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
                GXSetVtxDesc(GX_VA_TEX0, GX_INDEX16);
                break;
            case 5:
                GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
                GXSetVtxDesc(GX_VA_TEX0, GX_INDEX16);
                break;
            case 6:
                GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
                GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
                break;
            case 7:
                GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
                GXSetVtxDesc(GX_VA_TEX0, GX_INDEX16);
                break;
            case 8:
                GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX2, GX_DIRECT);
                break;
            case 9:
                GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
                GXSetVtxDesc(GX_VA_TEX0, GX_INDEX16);
                break;
            }
        }
        GXFlush();
    }
}

void GPGetCurrentBuffer() {

}

GXRenderModeObj *GPGetRenderModeObj() {
    return rmode;
}

void GPDoneRender() {
    u32 temp_r31_178;
    u32 temp_r3_210;
    u32 temp_r4_216;

    if ((s32) THP_Initialized == 0) {
        GXSetDrawDone();
    }
    if ((s8) init_489 == 0) {
        lastRetrace_488 = VIGetRetraceCount();
        init_489 = 1;
    }
    temp_r31_178 = VIGetRetraceCount() - lastRetrace_488;
    gCPUFramesPerSecond = (0x0269FB20U / (u32) (OSGetTick() - lastTick_491)) + 1;
    if (((s32) THP_Initialized == 0) && ((u8) M2C_FIELD(&gMKDefaults, u8 *, 0x1C) != 0) && ((u8) M2C_FIELD(&gMKDefaults, u8 *, 0x10) != 0) && (temp_r31_178 == 0U)) {
        VIWaitForRetrace();
    }
    GXWaitDrawDone();
    VIWaitForRetrace();
    GXCopyDisp(&pBuffer, 1U);
    GXSetDrawSync(0U);
    temp_r3_210 = OSGetTick();
    lastTick_491 = temp_r3_210;
    temp_r4_216 = 0x0269FB20U / (u32) (temp_r3_210 - lastFrame_498);
    lastFrame_498 = temp_r3_210;
    gFramesPerSecond = temp_r4_216 + 1;
    lastRetrace_488 = VIGetRetraceCount();
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

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

void DrawSyncHandler(unsigned short arg0) {
    if (arg0 == 0) {
        lastTick_465 = OSGetTick();
    } else if (arg0 == 1) {
        gGPUFramesPerSecond = (0x0269FB20U / (u32) (OSGetTick() - lastTick_465)) + 1;
    }
    if ((arg0 >= -0x8000U) && (arg0 <= -0x58F0U)) {
        MKVisibilityTest_HandleDrawSync(arg0);
    }
}

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

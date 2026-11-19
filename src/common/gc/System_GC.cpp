#include "common/gc/System_GC.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "unplaced_enums.h"
#include "dolphin/ar.h"
#include "dolphin/dvd.h"
#include "dolphin/gx.h"
#include "dolphin/os.h"
#include "dolphin/vi.h"
#include "common/Source/Animation.h"
#include "common/Source/Debug.h"
#include "common/Source/DiscErrors.h"
#include "common/Source/File.h"
#include "common/Source/FileSys.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKInput.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKMetadata.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKPackage.h"
#include "common/Source/MKShape.h"
#include "common/Source/MKSystem.h"
#include "common/Source/MKView.h"
#include "common/Source/MKWidgets.h"
#include "common/Source/OmniLight.h"
#include "common/Source/Str.h"
#include "common/Source/Translation.h"
#include "common/Source/Video.h"
#include "common/gc/MKInput_GC.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "common/gc/MKShadow_GC.h"
#include "common/gc/MKVisibilityTest_GC.h"
#include "common/gc/Sound_GC.h"
#include "spyro/source/Game.h"
#include <m2c_macros.h>

M2C_UNK THPPlayerDrawDone();                        /* extern */
M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
M2C_UNK strcat(s8 *, void *);                       /* extern */
extern s32 lit_785;
extern s32 MKPackage_misses;
extern u8 bDebugMenuActive;
extern u8 bMainThreadSuspended;
extern s32 counter_757;
extern s32 gCPUFramesPerSecond;
extern MKClothManager gClothManager;
extern s32 gDrawCounter;
extern MKDynamicBoneSystem gDynamicBones;
extern s32 gFrameCounter;
extern s32 gFramesPerSecond;
extern s32 gGPUFramesPerSecond;
#if 0 // DRAFT: identifier 'gMKLastIdleTime' redeclared
extern u32 gMKLastIdleTime;
#endif
extern MKHeap gMainHeap;
#if 0 // DRAFT: identifier 'gRenderState' redeclared
extern M2C_UNK gRenderState;
#endif
extern u8 gbGoldMaster;
extern MKFont *gpDebugFont;
extern MKHeap heapCount_754;
extern u8 init_720;
extern u8 init_736;
extern u8 init_739;
extern u8 init_758;
extern u8 init_761;
extern u8 init_833;
extern u8 init_991;
extern u32 lastTick_719;
extern s32 lostMem_756;
extern s32 lowestFPS_738;
extern s32 noOfAllocatedTMemPreloadedRegions;
extern MKHeap *pMKZRequest_RequestList;
extern OSThread *pMainThread;
extern s32 peakNormal_760;
extern s32 reservedMem_755;
extern s8 resetSoundDeinit;
extern s32 resetState_832;
extern u8 seekFinished;
extern u8 soundInitialised;
extern s32 statusBar_735;
extern u8 stencilVal_990;
extern s32 usedNormalMem_752;
extern s32 usedTempMem_753;
static MKHeap gMKDefaults;                          /* type too large by 0x34; unable to generate initializer: non-zero padding */
static M2C_UNK gDisplay;                            /* unable to generate initializer: unknown type */
static s8 cmdLine_795[0x100] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
static M2C_UNK IdleThreadStack;
static DVDFileInfo seekHack;
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_TMEMCacheSegments_0x18 TMEMCacheSegments[8];
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class
static struct _struct_TMEMPreloadedSegments_0x1C TMEMPreloadedSegments[0x10];
#endif
static f32 gUpdateTimeDelta = 0.016666668f;
#if 0 // DRAFT: identifier 'gpBuildVersion' redeclared
static M2C_UNK *gpBuildVersion = &.L_8036E6A3;
#endif
static s32 lit_1000 = 0;
static s32 lit_1001 = 0x270;
static s32 lit_1002 = 0;
static s32 lit_1003 = 0x180;

#if 0 // DRAFT: declaration syntax error
static MKHeap lit_stringBase0;                         /* type too large by 0x11B; unable to generate initializer: not enough data; const */
static M2C_UNK .L_8036E69D;                         /* unable to generate initializer: unknown type; const */
static M2C_UNK .L_8036E6A3;                         /* unable to generate initializer: unknown type; const */

s32 System_GetWideScreenPreference() {
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void MKZRequest_CheckRequest(MKZRequest *arg0) {
    MKVector3 sp8;
    GXRenderModeObj *temp_r31_88;
    f32 var_f0_172;
    s32 temp_r28_56;
    s32 temp_r30_55;
    s32 var_ctr_152;
    s32 var_r0_106;
    s32 var_r0_96;
    s32 var_r3_101;
    s32 var_r3_112;
    s32 var_r5_150;
    s32 var_r6_151;
    u16 var_r28_118;
    u16 var_r30_107;

    if ((s8) init_991 == 0) {
        stencilVal_990 = 0x1C;
        init_991 = 1;
    }
    MKView_TransformPoint3Dto2D(&sp8, *((MKVector3 *) arg0));
    temp_r30_55 = (s32) (640.0f * (M2C_BITWISE(f32, sp8) / 640.0f)) - 8;
    temp_r28_56 = (s32) (400.0f * (sp8.unk4 * 0.001953125f)) - 8;
    if ((sp8.unk8 < 0.0f) || (sp8.unk8 > 1.0f) || ((temp_r30_55 + 0x10) < 0) || (temp_r30_55 >= 0x280) || ((temp_r28_56 + 0x10) < 0) || (temp_r28_56 >= 0x190)) {
        arg0->unk10 = 0.0f;
        return;
    }
    GXSetPointSize(0x3CU, GX_TO_ZERO);
    MK_SetVDMode((MK_VertexDescriptorMode) 1);
    MKMaterial_SetMaterial(NULL);
    GXSetColorUpdate(0U);
    GXSetZMode(1U, GX_LEQUAL, 0U);
    temp_r31_88 = GPGetRenderModeObj();
    GXSetCopyFilter(0U, NULL, 0U, NULL);
    GXSetDither(0U);
    var_r0_96 = lit_1001;
    if (temp_r30_55 < var_r0_96) {
        var_r0_96 = temp_r30_55;
    }
    var_r3_101 = lit_1000;
    if (var_r0_96 > var_r3_101) {
        var_r3_101 = var_r0_96;
    }
    var_r0_106 = lit_1003;
    var_r30_107 = (u16) var_r3_101;
    if (temp_r28_56 < var_r0_106) {
        var_r0_106 = temp_r28_56;
    }
    var_r3_112 = lit_1002;
    if (var_r0_106 > var_r3_112) {
        var_r3_112 = var_r0_106;
    }
    var_r28_118 = (u16) var_r3_112;
    if (var_r30_107 & 1) {
        var_r30_107 += 1;
    }
    if (var_r28_118 & 1) {
        var_r28_118 += 1;
    }
    GXSetDstAlpha(1U, stencilVal_990);
    GXBegin(GX_POINTS, GX_VTXFMT0, 1U);
    *(f32 *)0xCC008000 = arg0->unk0;
    *(f32 *)0xCC008000 = arg0->unk4;
    *(f32 *)0xCC008000 = arg0->unk8;
    *(f32 *)0xCC008000 = 0xFFFF;
    DCInvalidateRange(arg0->unk20, 0x100U);
    var_r5_150 = 0;
    var_r6_151 = 0;
    var_ctr_152 = 0x100;
    do {
        if ((u8) stencilVal_990 == (u8) *(arg0->unk20 + var_r6_151)) {
            var_r5_150 += 1;
        }
        var_r6_151 += 1;
        var_ctr_152 -= 1;
    } while (var_ctr_152 != 0);
    arg0->unk10 = (f32) var_r5_150 / 100.0f;
    var_f0_172 = arg0->unk10;
    if (var_f0_172 < 1.0f) {

    } else {
        var_f0_172 = 1.0f;
    }
    if (var_f0_172 > 0.0f) {

    } else {
        var_f0_172 = 0.0f;
    }
    arg0->unk10 = var_f0_172;
    GXSetTexCopySrc(var_r30_107, var_r28_118, 0x10U, 0x10U);
    GXSetTexCopyDst(0x10U, 0x10U, GX_TF_A8, 0U);
    GXSetDstAlpha(1U, 0x3FU);
    GXCopyTex(arg0->unk20, 1U);
    GXSetCopyFilter(temp_r31_88->aa, (u8 (*)[2]) temp_r31_88->sample_pattern[0], 1U, temp_r31_88->vfilter);
    GXSetDither(1U);
    MKMaterial_SetMaterial(NULL);
}
#endif

void MKZRequest_Destroy(MKZRequest *arg0) {
    if (arg0 != NULL) {
        arg0->unk14 = 0;
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
void *MKZRequest_Create() {
    s32 var_ctr_244;
    s32 var_r3_242;
    void *var_r31_240;

    var_r31_240 = NULL;
    var_r3_242 = 0;
    var_ctr_244 = gMKDefaults.unk98;
    if ((s32) gMKDefaults.unk98 > 0) {
loop_1:
        if ((s8) *(pMKZRequest_RequestList + (var_r3_242 + 0x14)) == 0) {
            var_r31_240 = pMKZRequest_RequestList + var_r3_242;
        } else {
            var_r3_242 += 0x28;
            var_ctr_244 -= 1;
            if (var_ctr_244 != 0) {
                goto loop_1;
            }
        }
    }
    M2C_FIELD(var_r31_240, f32 *, 0) = 0.0f;
    M2C_FIELD(var_r31_240, f32 *, 4) = 0.0f;
    M2C_FIELD(var_r31_240, f32 *, 8) = 0.0f;
    M2C_FIELD(var_r31_240, f32 *, 0x10) = 0.0f;
    M2C_FIELD(var_r31_240, s8 *, 0x14) = 1;
    memset(M2C_FIELD(var_r31_240, void **, 0x20), 0, 0x100U);
    return var_r31_240;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void MKZRequest_DeinitModule() {
    MKHeap *temp_r29_295;
    MKHeap *temp_r29_315;
    MKHeap *temp_r3_296;
    MKHeap *temp_r3_316;
    s32 var_r28_288;
    s32 var_r31_290;

    if ((MKHeap *) pMKZRequest_RequestList != NULL) {
        var_r28_288 = 0;
        var_r31_290 = 0;
loop_6:
        if (var_r28_288 < (s32) gMKDefaults.unk98) {
            temp_r29_295 = *(pMKZRequest_RequestList + (var_r31_290 + 0x20));
            temp_r3_296 = pMKZRequest_RequestList->Current();
            if (temp_r3_296 != NULL) {
                ((MKHeap *) (temp_r3_296->Current()))->Free(temp_r29_295, NULL, 0);
            } else {
                free(temp_r29_295);
            }
            var_r28_288 += 1;
            var_r31_290 += 0x28;
            goto loop_6;
        }
        temp_r29_315 = pMKZRequest_RequestList;
        temp_r3_316 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_316 != NULL) {
            ((MKHeap *) (temp_r3_316->Current()))->Free(temp_r29_315, NULL, 0);
        } else {
            free(temp_r29_315);
        }
        pMKZRequest_RequestList = NULL;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void MKZRequest_InitModule() {
    MKHeap *temp_r3_352;
    MKHeap *temp_r3_383;
    MKHeap *var_r3_359;
    MKHeap *var_r3_390;
    s32 temp_r0_397;
    s32 temp_r30_351;
    s32 var_r29_366;
    s32 var_r30_368;
    void *temp_r5_375;

    temp_r30_351 = gMKDefaults.unk98 * 0x28;
    temp_r3_352 = gMKDefaults.Current();
    if (temp_r3_352 != NULL) {
        var_r3_359 = ((MKHeap *) (temp_r3_352->Current()))->Alloc(temp_r30_351, NULL, 0);
    } else {
        var_r3_359 = malloc(temp_r30_351);
    }
    pMKZRequest_RequestList = var_r3_359;
    var_r29_366 = 0;
    var_r30_368 = 0;
loop_8:
    if (var_r29_366 < (s32) gMKDefaults.unk98) {
        temp_r5_375 = pMKZRequest_RequestList + var_r30_368;
        M2C_FIELD(temp_r5_375, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r5_375, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r5_375, f32 *, 8) = 0.0f;
        *(pMKZRequest_RequestList + (var_r30_368 + 0x10)) = 0.0f;
        *(pMKZRequest_RequestList + (var_r30_368 + 0x14)) = 0;
        temp_r3_383 = pMKZRequest_RequestList->Current();
        if (temp_r3_383 != NULL) {
            var_r3_390 = ((MKHeap *) (temp_r3_383->Current()))->Alloc(0x100, NULL, 0);
        } else {
            var_r3_390 = malloc(0x100);
        }
        temp_r0_397 = var_r30_368 + 0x20;
        *(pMKZRequest_RequestList + temp_r0_397) = var_r3_390;
        memset(*(pMKZRequest_RequestList + temp_r0_397), 0, 0x100U);
        var_r29_366 += 1;
        var_r30_368 += 0x28;
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'TMEMPreloadedSegments'
void ReleasePreloadedTextureRegion(_GXTexRegion *arg0) {
    s32 var_ctr_426;
    s32 var_r4_425;
    void *temp_r0_428;
    void *temp_r0_435;
    void *var_r5_431;

    var_r4_425 = 0;
    var_ctr_426 = 0x10;
loop_1:
    temp_r0_428 = TMEMPreloadedSegments + var_r4_425;
    if (temp_r0_428 == arg0) {
        var_r5_431 = temp_r0_428;
loop_4:
        if (var_r5_431 != NULL) {
            temp_r0_435 = M2C_FIELD(var_r5_431, void **, 0x18);
            M2C_FIELD(var_r5_431, s8 *, 0x10) = 0;
            M2C_FIELD(var_r5_431, void **, 0x18) = NULL;
            var_r5_431 = temp_r0_435;
            noOfAllocatedTMemPreloadedRegions -= 1;
            goto loop_4;
        }
        return;
    }
    var_r4_425 += 0x1C;
    var_ctr_426 -= 1;
    if (var_ctr_426 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void *RequestPreloadedTextureRegion(int arg0, unsigned int *arg1) {
    s32 temp_r0_547;
    s32 temp_r0_559;
    s32 temp_r3_468;
    s32 temp_r5_475;
    s32 var_ctr_489;
    s32 var_ctr_554;
    s32 var_r30_534;
    s32 var_r30_550;
    s32 var_r31_526;
    s32 var_r5_488;
    s32 var_r6_514;
    s32 var_r7_536;
    s32 var_r7_552;
    struct _struct_TMEMPreloadedSegments_0x1C *temp_r12_521;
    struct _struct_TMEMPreloadedSegments_0x1C *var_r3_483;
    void *temp_r7_491;
    void *temp_r9_558;

    if (((s32) noOfAllocatedTMemPreloadedRegions == 0x10) || (arg0 < 0x4000)) {
        return NULL;
    }
    temp_r3_468 = (arg0 + 0x7FFF) & 0xFFFF8000;
    if (temp_r3_468 > 0x40000) {
        return NULL;
    }
    temp_r5_475 = temp_r3_468 / 32768;
    if (temp_r5_475 > (s32) (0x10 - noOfAllocatedTMemPreloadedRegions)) {
        return NULL;
    }
    var_r3_483 = NULL;
    if (temp_r5_475 == 1) {
        var_r5_488 = 0;
        var_ctr_489 = 0x10;
loop_9:
        temp_r7_491 = TMEMPreloadedSegments + var_r5_488;
        if ((u8) M2C_FIELD(temp_r7_491, u8 *, 0x10) == 0) {
            *arg1 = M2C_FIELD((TMEMPreloadedSegments + var_r5_488), u32 *, 0x14);
            M2C_FIELD(temp_r7_491, u8 *, 0x10) = 1U;
            noOfAllocatedTMemPreloadedRegions += 1;
            return temp_r7_491;
        }
        var_r5_488 += 0x1C;
        var_ctr_489 -= 1;
        if (var_ctr_489 == 0) {
            return NULL;
        }
        goto loop_9;
    }
    var_r6_514 = 0;
loop_30:
    if (var_r6_514 < 0x10) {
        if (var_r3_483 == NULL) {
            temp_r12_521 = &TMEMPreloadedSegments[var_r6_514];
            if ((u8) temp_r12_521->unk10 == 0) {
                var_r31_526 = 1;
                if ((var_r6_514 < 8) && (temp_r5_475 > (s32) (8 - var_r6_514))) {
                    var_r6_514 = 7;
                } else {
                    var_r30_534 = var_r6_514 + 1;
                    var_r7_536 = var_r30_534 * 0x1C;
loop_27:
                    if (((s32) (var_r30_534 - var_r6_514) < temp_r5_475) && (var_r30_534 < 0x10)) {
                        if ((u8) M2C_FIELD((TMEMPreloadedSegments + var_r7_536), u8 *, 0x10) == 0) {
                            var_r31_526 += 1;
                            if (var_r31_526 == temp_r5_475) {
                                temp_r0_547 = temp_r5_475 - 1;
                                var_r3_483 = temp_r12_521;
                                var_r30_550 = 0;
                                *arg1 = temp_r12_521->unk14;
                                var_r7_552 = 0;
                                var_ctr_554 = temp_r0_547;
                                if (temp_r0_547 > 0) {
                                    do {
                                        temp_r9_558 = var_r3_483 + var_r7_552;
                                        temp_r0_559 = (var_r30_550 + 1) * 0x1C;
                                        M2C_FIELD(temp_r9_558, s8 *, 0x10) = 1;
                                        var_r30_550 += 1;
                                        var_r7_552 += 0x1C;
                                        M2C_FIELD(temp_r9_558, void **, 0x18) = (void *) (var_r3_483 + temp_r0_559);
                                        var_ctr_554 -= 1;
                                    } while (var_ctr_554 != 0);
                                }
                                *((temp_r5_475 * 0x1C) + (temp_r12_521 - 0xC)) = 1;
                                noOfAllocatedTMemPreloadedRegions += temp_r5_475;
                            } else {
                                var_r30_534 += 1;
                                var_r7_536 += 0x1C;
                                goto loop_27;
                            }
                        } else {
                            var_r6_514 = var_r30_534;
                        }
                    }
                }
            }
            var_r6_514 += 1;
            goto loop_30;
        }
    }
    return var_r3_483;
}
#endif

#if 0 // DRAFT: undefined identifier 'TMEMCacheSegments'
void *TexRegionCallback(const _GXTexObj *arg0, _GXTexMapID arg1) {
    return &TMEMCacheSegments[((u32) arg0 >> 5U) & 7];
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void Init_TexCache() {
    GXTexRegion *temp_r27_623;
    s32 temp_r0_647;
    s32 temp_r4_649;
    s32 var_ctr_645;
    s32 var_r26_619;
    s32 var_r31_620;
    s32 var_r3_643;
    s32 var_r9_642;
    struct _struct_TMEMPreloadedSegments_0x1C *temp_r8_656;
    u32 var_r30_617;
    void *temp_r7_648;

    var_r30_617 = 0;
    var_r26_619 = 0;
    var_r31_620 = 0;
    noOfAllocatedTMemPreloadedRegions = 0;
    do {
        temp_r27_623 = TMEMCacheSegments + var_r31_620;
        GXInitTexCacheRegion(temp_r27_623, 0U, var_r30_617, GX_TEXCACHE_32K, var_r30_617 + 0x80000, GX_TEXCACHE_32K);
        M2C_FIELD(temp_r27_623, s32 *, 0x14) = 0;
        var_r26_619 += 1;
        M2C_FIELD(temp_r27_623, s32 *, 0x10) = 0;
        var_r30_617 += 0x8000;
        var_r31_620 += 0x18;
    } while (var_r26_619 < 8);
    var_r9_642 = 0;
    var_r3_643 = 0;
    var_ctr_645 = 8;
    do {
        temp_r0_647 = var_r9_642 + 8;
        temp_r7_648 = TMEMPreloadedSegments + var_r3_643;
        temp_r4_649 = temp_r0_647 << 0xF;
        var_r9_642 += 1;
        M2C_FIELD(temp_r7_648, s32 *, 0x14) = temp_r4_649;
        M2C_FIELD(temp_r7_648, s8 *, 0x10) = 0;
        var_r3_643 += 0x1C;
        temp_r8_656 = &TMEMPreloadedSegments[temp_r0_647];
        M2C_FIELD(temp_r7_648, s32 *, 0x18) = 0;
        temp_r8_656->unk14 = temp_r4_649 + 0x80000;
        temp_r8_656->unk10 = 0;
        temp_r8_656->unk18 = 0;
        var_ctr_645 -= 1;
    } while (var_ctr_645 != 0);
    GXInvalidateTexAll();
    GXSetTexRegionCallback((GXTexRegion *(*)(GXTexObj *, enum _GXTexMapID)) TexRegionCallback);
}
#endif

#if 0 // DRAFT: illegal use of keyword
void System_IdleFunction(void *arg0) {
    u32 temp_r3_732;

case 2:                                             /* switch 1 */
loop_1:
    gMKLastIdleTime = OSGetTick();
    if ((s8) init_833 == 0) {
        resetState_832 = 0;
        init_833 = 1;
    }
    switch ((s32) resetState_832) {                 /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        if (OSGetResetButtonState() != 0) {
            resetState_832 = 1;
        }
        break;
    case 1:                                         /* switch 1 */
        if (OSGetResetButtonState() == 0) {
            resetState_832 = 2;
            OSSuspendThread(pMainThread);
            bMainThreadSuspended = 1;
loop_14:
            if (System_AnyMemCardBusy() != 0) {
                MKMemoryCard_Update();
                goto loop_14;
            }
            System_DoReset(DVDCheckDisk() == 0, 0U, soundInitialised);
        }
        break;
    }
    temp_r3_732 = DVDGetDriveStatus();
    switch (temp_r3_732) {                          /* switch 2 */
    case 0:                                         /* switch 2 */
        if (DVDCheckDisk() == 0) {
            if ((u8) seekFinished != 0) {
                seekFinished = 0;
                DVDSeekAsyncPrio(&seekHack, 0, SeekHackFinished, 2);
            }
        } else if (DiscErr_IsError() != 0) {
            OSYieldThread();
        }
        break;
    case 1:                                         /* switch 2 */
        DiscErr_ClearError();
        if ((u8) bMainThreadSuspended != 0) {
            if ((u8) soundInitialised != 0) {
                Sound_SysResumeVoices();
            }
            bMainThreadSuspended = 0;
            OSResumeThread(pMainThread);
        }
        break;
    case 4:                                         /* switch 2 */
        DiscErr_SetError(1);
        if ((u8) soundInitialised != 0) {
            Sound_SysPauseVoices();
        }
        if ((u8) bMainThreadSuspended == 0) {
            OSSuspendThread(pMainThread);
            bMainThreadSuspended = 1;
        }
        break;
    case 5:                                         /* switch 2 */
        DiscErr_SetError(2);
        if ((u8) soundInitialised != 0) {
            Sound_SysPauseVoices();
        }
        if ((u8) bMainThreadSuspended == 0) {
            OSSuspendThread(pMainThread);
            bMainThreadSuspended = 1;
        }
        break;
    case 6:                                         /* switch 2 */
        DiscErr_SetError(4);
        if ((u8) soundInitialised != 0) {
            Sound_SysPauseVoices();
        }
        if ((u8) bMainThreadSuspended == 0) {
            OSSuspendThread(pMainThread);
            bMainThreadSuspended = 1;
        }
        break;
    case 11:                                        /* switch 2 */
        DiscErr_SetError(3);
        if ((u8) soundInitialised != 0) {
            Sound_SysPauseVoices();
        }
        if ((u8) bMainThreadSuspended == 0) {
            OSSuspendThread(pMainThread);
            bMainThreadSuspended = 1;
        }
        break;
    }
    if (DiscErr_IsError() == 0) {
        goto loop_1;
    }
    MKInput_Vibrate((MKInputDevices) 4, 0.0f, 0.0f);
    DiscErr_DrawErrorString();
    goto loop_1;
}
#endif

void System_DoReset(bool arg0, bool arg1, bool arg2) {
    if (arg0 != 0) {
        VISetBlack(1);
        VIFlush();
        VIWaitForRetrace();
        if (arg2 != 0) {
            resetSoundDeinit = 1;
            Sound_DeinitModule();
        }
        OSResetSystem(1, 0U, (s32) arg1);
        return;
    }
    GXDrawDone();
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    Video_DeinitModule();
    if (arg2 != 0) {
        resetSoundDeinit = 1;
        Sound_DeinitModule();
    }
    OSResetSystem(0, 0U, 0);
}

u8 System_AnyMemCardBusy() {
    s32 var_r30_913;
    u8 var_r31_912;

    var_r31_912 = 0;
    var_r30_913 = 0;
loop_1:
    if (MKMemoryCard_GetStatus(var_r30_913) == 1) {
        var_r31_912 = 1;
    } else {
        var_r30_913 += 1;
        if (var_r30_913 < 2) {
            goto loop_1;
        }
    }
    return var_r31_912;
}

#if 0 // DRAFT: undefined identifier 'GPInit__FP16_GXRenderModeObj'
s32 main(s32 arg0, void *arg1) {
    Matrix sp20;
    s32 sp10;
    GXRenderModeObj *temp_r3_971;
    s32 var_r26_1145;
    s32 var_r26_1167;
    s32 var_r29_1146;
    s32 var_r29_1169;

    DVDSetAutoFatalMessaging(1);
    GPInit__FP16_GXRenderModeObj(NULL);
    M2C_ERROR(/* unknown instruction: mtspr GQR2, $r3 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR3, $r3 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR4, $r3 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR5, $r3 */);
    __OSFpscrEnableBits &= ~0x68;
    System_SetDisplayMode__Fiiiii(1, 0x280, 0x190, 0, 0x18);
    temp_r3_971 = GPGetRenderModeObj__Fv();
    XFONTInit__FUlUl(0x280U, ((temp_r3_971->fbWidth + 0xF) & 0xFFF0) * temp_r3_971->xfbHeight * 2);
    GPGetCurrentBuffer__Fv();
    XFONTSetFrameBuffer__FPv(M2C_ERROR(/* Read from unset register $r3 */));
    XFONTSetFgColor__FUl(0U);
    SetIdentity__6MatrixFv(&sp20);
    GXLoadPosMtxImm((f32 (*)[4]) &sp20, 3U);
    GXLoadNrmMtxImm((f32 (*)[4]) &sp20, 3U);
    GXSetLineWidth(6U, GX_TO_ZERO);
    GXSetPointSize(4U, GX_TO_ZERO);
    GXSetCullMode(GX_CULL_NONE);
    GXSetAlphaUpdate(1U);
    GXSetCurrentMtx(0U);
    GXSetDstAlpha(1U, 0x3FU);
    GXPokeZMode(0U, GX_ALWAYS, 1U);
    GXPokeBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ZERO, GX_LO_SET);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x1EU, 0U, 0x7DU);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_TEX_S, GX_RGB8, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA4, 0xCU);
    M2C_ERROR(/* unknown instruction: mtspr GQR6, $r0 */);
    M2C_ERROR(/* unknown instruction: mtspr GQR7, $r0 */);
    GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_NRM, GX_TEX_S, GX_RGBA4, 0xEU);
    GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_TEX0, GX_TEX_ST, GX_RGBA4, 0xCU);
    GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_TEX1, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_TEX2, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_NRM, GX_TEX_S, GX_RGBA6, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0U);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetNumChans(1U);
    GXSetChanCtrl(GX_COLOR0A0, 0U, GX_SRC_REG, GX_SRC_VTX, 0U, GX_DF_NONE, GX_AF_NONE);
    GXSetChanCtrl(GX_COLOR1A1, 0U, GX_SRC_REG, GX_SRC_REG, 0U, GX_DF_NONE, GX_AF_NONE);
    sp10 = lit_785;
    GXSetChanAmbColor(GX_COLOR0A0, (GXColor) &sp10);
    GXSetNumTevStages(1U);
    GXSetNumTexGens(1U);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    var_r26_1145 = 1;
    var_r29_1146 = 4;
loop_2:
    if (var_r26_1145 < arg0) {
        strlen(*(arg1 + var_r29_1146));
        var_r26_1145 += 1;
        var_r29_1146 += 4;
        goto loop_2;
    }
    if (arg0 >= 2) {
        strcpy(cmdLine_795, M2C_FIELD(arg1, s8 **, 4));
    }
    var_r26_1167 = 2;
    var_r29_1169 = 8;
loop_7:
    if (var_r26_1167 < arg0) {
        strcat(cmdLine_795, &lit_stringBase0 + 0x15);
        strcat(cmdLine_795, *(arg1 + var_r29_1169));
        var_r26_1167 += 1;
        var_r29_1169 += 4;
        goto loop_7;
    }
    System_InitModule__FPvPc(NULL, cmdLine_795);
    System_SetOrthoSize__Fii(0x280, 0x200);
    System_GetCommandLineParameter__FPCcb(&lit_stringBase0 + 0x17, 0U);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        M2C_FIELD(&gDisplay, f32 *, 8) = 50.0f;
        M2C_FIELD(&gDisplay, s32 *, 0) = 0;
        M2C_FIELD(&gDisplay, f32 *, 0xC) = (f32) (1.0f / 50.0f);
    }
    Game_Init__Fv();
    System_DoGameLoop__Fv();
    Game_Deinit__Fv();
    System_DeinitModule__Fv();
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    OSResetSystem(2, 0U, 1);
    return 0;
}
#endif

void System_SetOrthoSize(int arg0, int arg1) {
    M2C_FIELD(&gDisplay, f32 *, 0x68) = (f32) arg0;
    M2C_FIELD(&gDisplay, f32 *, 0x6C) = (f32) arg1;
}

void System_SetDisplayMode(int arg0, int arg1, int arg2, int arg3, int arg4) {
    M2C_FIELD(&gDisplay, s32 *, 0) = arg0;
    if (VIGetTvFormat() == 1) {
        M2C_FIELD(&gDisplay, f32 *, 8) = 50.0f;
        M2C_FIELD(&gDisplay, s32 *, 0) = 0;
    } else {
        M2C_FIELD(&gDisplay, f32 *, 8) = 60.0f;
    }
    M2C_FIELD(&gDisplay, s32 *, 0x10) = arg1;
    M2C_FIELD(&gDisplay, s32 *, 0x14) = arg2;
    M2C_FIELD(&gDisplay, s32 *, 0x28) = 0x280;
    M2C_FIELD(&gDisplay, s32 *, 0x2C) = 0x200;
    M2C_FIELD(&gDisplay, f32 *, 0xC) = (f32) (1.0f / M2C_FIELD(&gDisplay, f32 *, 8));
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void System_GameDraw() {
    Matrix sp10;
    f32 temp_f30_1418;
    f32 temp_f31_1470;
    s32 temp_r0_1367;
    s32 temp_r3_1397;
    s32 temp_r3_1408;
    u32 temp_ret_1419;

    MKView_Push();
    sp10.SetIdentity();
    Game_Draw();
    MKCollision_Draw();
    MKView_Pop();
    MKMaterial_SetMaterial(NULL);
    MKGrass_DrawStats();
    if (((u8) gbGoldMaster == 0) && ((s32) gMKDefaults.unk24 != 0)) {
        if ((s8) init_736 == 0) {
            statusBar_735 = 0;
            init_736 = 1;
        }
        if ((s8) init_739 == 0) {
            init_739 = 1;
            lowestFPS_738 = 0x1869F;
        }
        if ((MKInput_Pressed(9, (MKInputDevices) 0) != 0) && (MKInput_GetState(4, (MKInputDevices) 0, NULL, NULL) != 0.0f)) {
            if ((s32) statusBar_735 == 0) {
                lowestFPS_738 = 0x1869F;
            }
            temp_r0_1367 = statusBar_735 + 1;
            statusBar_735 = temp_r0_1367;
            if (temp_r0_1367 > 2) {
                statusBar_735 = 0;
            }
        }
        if (((s32) statusBar_735 > 0) && ((u8) bDebugMenuActive == 0)) {
            if ((s8) init_758 == 0) {
                counter_757 = -1;
                init_758 = 1;
            }
            if ((s8) init_761 == 0) {
                peakNormal_760 = 0;
                init_761 = 1;
            }
            temp_r3_1397 = counter_757 + 1;
            counter_757 = temp_r3_1397;
            if (!(temp_r3_1397 & 0x1F)) {
                heapCount_754.GetHeapStatistics(&reservedMem_755, &usedNormalMem_752, &usedTempMem_753, &lostMem_756, M2C_ERROR(/* Read from unset register $r8 */));
            }
            temp_r3_1408 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetPeak();
            if ((s32) peakNormal_760 < temp_r3_1408) {
                peakNormal_760 = temp_r3_1408;
            }
            temp_f30_1418 = 30.0f + gMKDefaults.unk80;
            temp_ret_1419 = GXGetOverflowCount();
            gpDebugFont->DrawString2dWrapped(Str_Printf(&lit_stringBase0 + 0x1B, (s32) (usedNormalMem_752 + 0x3FF) / 1024, (s32) (peakNormal_760 + 0x3FF) / 1024, (s32) (reservedMem_755 + 0x3FF) / 1024, (s32) (usedTempMem_753 + 0x3FF) / 1024, (s32) (lostMem_756 + 0x3FF) / 1024, temp_ret_1419, MKPackage_misses, M2C_BITWISE(f32, temp_ret_1419)), 30.0f + 320.0f, temp_f30_1418 + 256.0f, 640.0f, 512.0f, 1.0f, 0, 0x80808080U);
            GXResetOverflowCount();
            MKPackage_ShowStatus(0x198);
            temp_f31_1470 = 10.0f + gMKDefaults.unk80;
            gpDebugFont->DrawString2dWrapped(Str_Printf(&lit_stringBase0.unk4C, gFramesPerSecond, gCPUFramesPerSecond, gGPUFramesPerSecond, &lit_stringBase0 + 0x77, &lit_stringBase0 + 0x83, 0x14A, gpBuildVersion, 10.0f), 30.0f + 320.0f, temp_f31_1470 + 256.0f, 640.0f, 512.0f, 1.0f, 0, 0x80808080U);
        }
    }
    gDrawCounter += 1;
}
#endif

u8 System_Update_Normal() {
    f32 temp_f0_1551;
    f32 temp_f1_1546;
    u32 temp_r3_1525;
    u32 var_r7_1528;

    if ((s8) init_720 == 0) {
        lastTick_719 = 0;
        init_720 = 1;
    }
    temp_r3_1525 = OSGetTick();
    var_r7_1528 = temp_r3_1525 - lastTick_719;
    if (temp_r3_1525 < (u32) lastTick_719) {
        var_r7_1528 = -1 - (lastTick_719 - temp_r3_1525);
    }
    temp_f1_1546 = 4.0f * M2C_FIELD(&gDisplay, f32 *, 0xC);
    temp_f0_1551 = 0.001f * (f32) (var_r7_1528 / (u32) ((u32) ((u32) *(u32 *)0x800000F8 >> 2U) / 1000U));
    gUpdateTimeDelta = temp_f0_1551;
    if (temp_f0_1551 > temp_f1_1546) {
        gUpdateTimeDelta = temp_f1_1546;
    }
    lastTick_719 = temp_r3_1525;
    MKMaterialInternal_Update();
    MKWidget_Update();
    if (Game_Update() != 0) {
        return 1U;
    }
    MKInput_DespatchEvents();
    ((MKCloth *) (M2C_ERROR(/* Read from unset register $r3 */)))->UpdateGlobalCollisionPrims();
    gDynamicBones.Update();
    gClothManager.Update();
    gFrameCounter += 1;
    return 0U;
}

void System_DoGameLoop() {
    u8 var_r31_1590;

    var_r31_1590 = 0;
loop_2:
    if (var_r31_1590 == 0) {
        MKModel_RemoveDestroyedModels();
        MKInput_Update();
        MKArchive_Update();
        Sound_Update();
        MKPackage_Update();
        MKMemoryCard_Update();
        var_r31_1590 = System_Update_Normal();
        GPDoneRender();
        System_GameDraw();
        GXSetDrawSync(1U);
        THPPlayerDrawDone();
        goto loop_2;
    }
}

void System_DeinitModule() {
    MKMetadata_DeinitModule();
    gClothManager.Deinit();
    gDynamicBones.Deinit();
    SoftBody_Deinit();
    MKPrimitive_DeinitModule();
    OmniLight_DeinitModule();
    gDrawCounter += 1;
    MKModel_RemoveDestroyedModels();
    MKShape_Deinit();
    gpDebugFont->Destroy();
    Debug_SetFont(NULL);
    MKCollision_DeinitModule();
    resetSoundDeinit = 1;
    Sound_DeinitModule();
    Translation_DeinitModule();
    MKModel_DeinitModule();
    MKAnimScript_DeinitModule();
    Animation_DeinitModule();
    MKMemoryCard_DeinitModule();
    MKMaterial_DeinitModule();
    MKGrass_DeinitModule();
    MKInput_InitModule();
    ((MKFont *) (M2C_ERROR(/* Read from unset register $r3 */)))->DeinitModule();
    MKPackage_DeinitModule();
    MKArchive_DeinitModule();
    File_DeinitModule();
    Debug_DeinitModule();
}

#if 0 // DRAFT: undefined identifier 'Init_TexCache'
void System_InitModule(void *arg0, char *arg1) {
    Init_TexCache();
    ARInit(NULL, 0U);
    pMainThread = OSGetCurrentThread();
    OSSetIdleFunction(System_IdleFunction, NULL, &IdleThreadStack + 0x4000, 0x4000U);
    memset(&gRenderState, 0, 0x1CU);
    M2C_FIELD(&gRenderState, s32 *, 0x18) = -1;
    Game_InitSystem();
    ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    if (arg1 != NULL) {
        System_InitCommandLineArgs(arg1);
    }
    gMainHeap.Init((OSCheckHeap(0) - ((gMKDefaults.unk64 * 0x10) + 0x100)) - 0x860, (s32) gMKDefaults.unk64, (s8 *) &lit_stringBase0.unk88.unk4, NULL);
    gMainHeap.Push();
    Debug_InitModule();
    MKInput_InitModule();
    MKWidget_InitModule();
    File_InitModule();
    File_FileServerFilename(&lit_stringBase0 + 0x91);
    DVDOpen(M2C_ERROR(/* Read from unset register $r3 */), &seekHack);
    seekFinished = 1;
    MKArchive_InitModule();
    File_FileServerFilename(&lit_stringBase0 + 0x9D);
    MKArchive_RegisterArchive(M2C_ERROR(/* Read from unset register $r3 */), 0U);
    File_FileServerFilename(&lit_stringBase0 + 0xA9);
    MKArchive_RegisterArchive(M2C_ERROR(/* Read from unset register $r3 */), 0U);
    File_FileServerFilename(&lit_stringBase0 + 0x91);
    MKArchive_RegisterArchive(M2C_ERROR(/* Read from unset register $r3 */), 0U);
    MKPackage_InitModule();
    ((MKFont *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    MKView_InitModule();
    ((Texture *) (M2C_ERROR(/* Read from unset register $r3 */)))->InitModule();
    MKMaterial_InitModule();
    MKMemoryCard_InitModule();
    MKModel_InitModule();
    Animation_InitModule();
    MKAnimScript_InitModule();
    Translation_InitModule();
    MKCollision_InitModule();
    Sound_InitModule();
    soundInitialised = 1;
    MKVisibilityTest_InitModule();
    Video_InitModule();
    gFrameCounter = 0;
    gDrawCounter = 0;
    Debug_SetFont(lit_stringBase0.unkB6.Create(M2C_ERROR(/* Read from unset register $r4 */)));
    MKShape_Init();
    MKShadow_InitModule();
    MKGrass_InitModule();
    OmniLight_InitModule();
    MKWidget_CreateMaterial();
    SoftBody_Init();
    gDynamicBones.Init();
    gClothManager.Init();
    MKMetadata_InitModule();
}
#endif

void SeekHackFinished(long arg0, DVDFileInfo *arg1) {
    seekFinished = 1;
}

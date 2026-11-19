#include "common/gc/MKShadow_GC.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "dolphin/os.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK free(Matrix *);                             /* extern */
Matrix *malloc(u32);                                /* extern */
extern M2C_UNK MKMat_MK2_Standard_CaptureTextureData;
extern M2C_UNK gMKDefaults;
extern MKMaterial *gpMKWhiteMaterial;
extern Matrix *pShadowEdgeResultBuffer;
extern void *pShadowVertexBuffer;
extern s32 shadowsRendered;
static s32 lit_674 = 0x04040404;                       /* const */

#if 0 // DRAFT: undefined identifier 'MKShadow_ApplyAlphaTint'
void MKShadow_EndScene(bool arg0, bool arg1, MKVector4 *arg2) {
    GXTexObj sp20;
    GXRenderModeObj *temp_r3_214;

    if ((s32) shadowsRendered != 0) {
        MKView_Push();
        GXSetViewport(0.0f, 0.0f, 640.0f, 400.0f, 0.0f, 1.0f);
        GXSetScissor(0U, 0U, 0x280U, 0x190U);
        GXSetChanCtrl(GX_COLOR0A0, 0U, GX_SRC_REG, GX_SRC_VTX, 0U, GX_DF_CLAMP, GX_AF_SPOT);
        GXSetZMode(0U, GX_ALWAYS, 0U);
        GXSetClipMode(GX_CLIP_DISABLE);
        GXSetCullMode(GX_CULL_NONE);
        GXSetDstAlpha(0U, 0x3FU);
        GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_AND, GX_ALWAYS, 0xFFU);
        GXSetColorUpdate(0U);
        GXSetAlphaUpdate(1U);
        GXSetBlendMode(GX_BM_LOGIC, GX_BL_ZERO, GX_BL_DSTALPHA, GX_LO_AND);
        MKShadow_ApplyAlphaTint(0x40U, 100.0f);
        GXSetColorUpdate(1U);
        GXSetAlphaUpdate(0U);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVDSTALPHA, GX_LO_XOR);
        MKShadow_ApplyAlphaTint(0xFFU, 100.0f);
        GXSetNumTexGens(1U);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_ZERO);
        GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_RED);
        GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP1, GX_TEV_SWAP1);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_AND, GX_ALWAYS, 0xFFU);
        GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_NOOP);
        GXSetColorUpdate(0U);
        GXSetAlphaUpdate(1U);
        GXSetDstAlpha(0U, 0x3FU);
        GXSetZMode(1U, GX_ALWAYS, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        GXInitTexObj(&sp20, &MKMat_MK2_Standard_CaptureTextureData, 0x280U, 0x190U, GX_TF_I8, GX_CLAMP, GX_CLAMP, 0U);
        GXLoadTexObj(&sp20, GX_TEXMAP0);
        MK_SetVDMode((MK_VertexDescriptorMode) 2);
        C_MTXOrtho((f32 (*)[4]) &sp40[0], 0.0f, 399.0f, 0.0f, 639.0f, 0.0f, 1.0f);
        GXSetCurrentMtx(3U);
        GXSetProjection((f32 (*)[4]) &sp40[0], GX_ORTHOGRAPHIC);
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, 4U);
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 640.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 1.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 400.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 1.0f;
        *(f32 *)0xCC008000 = 640.0f;
        *(f32 *)0xCC008000 = 400.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 1.0f;
        *(f32 *)0xCC008000 = 1.0f;
        temp_r3_214 = GPGetRenderModeObj();
        GXSetCopyFilter(temp_r3_214->aa, temp_r3_214 + 0x1A, 1U, temp_r3_214 + 0x32);
        MKView_Pop();
        GXSetClipMode(GX_CLIP_ENABLE);
        GXSetCurrentMtx(0U);
        MKMaterial_SetMaterial(NULL);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKShadowSubObjectMP'
void MKShadow_Render(MKModel *arg0, const MKVector3 &arg1, float arg2, const MKVector3 &arg3, const MKVector3 *arg4, bool arg5) {
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    f64 *sp8;
    Animation *temp_r3_337;
    MKShadowSubObjectMP::Edge *temp_r20_507;
    MKVector3 *temp_r21_505;
    Matrix *var_r29_347;
    Matrix *var_r3_365;
    f64 temp_f0_269;
    s16 temp_r23_353;
    s16 temp_r27_478;
    s32 temp_r28_419;
    s32 temp_r3_373;
    s32 temp_r5_499;
    s32 var_r19_513;
    s32 var_r24_476;
    s32 var_r26_475;
    s32 var_r4_375;
    s32 var_r9_374;
    u8 var_r30_334;
    void *temp_r22_502;

    if ((u32) M2C_FIELD(arg0->unk0, u32 *, 0x44) != 0U) {
        spF8 = M2C_FIELD(&arg1, f64 *, 0);
        sp100 = M2C_FIELD(&arg1, f64 *, 8);
        MKModel_CalculateCentre(arg0, &spB8);
        if (arg4 != NULL) {
            spE8 = M2C_FIELD(arg4, f64 *, 0);
            spF0 = M2C_FIELD(arg4, f64 *, 8);
        } else {
            temp_f0_269 = M2C_BITWISE(f64, spB8) - spF8;
            sp48 = temp_f0_269;
            sp98 = temp_f0_269;
            sp50 = spB8.unk8 - (f32) sp100;
            spA0 = (f64) sp50;
            spA8 = Normalise(*((MKVector3 *) &sp98));
            *(MKVector3 *) &spE8 = spA8;
        }
        *(MKVector3 *) &spD8 = spB8;
        if (arg5 != 0) {
            sp78.operator*(arg2);
            sp38 = spF8 + M2C_BITWISE(f64, sp78);
            sp88 = sp38;
            sp40 = (f32) sp100 + sp78.unk8;
            spC8 = sp38;
            sp90 = (f64) sp40;
            spD0 = (f64) sp40;
        } else {
            sp58.operator*(100.0f + arg2);
            sp28 = M2C_BITWISE(f64, spB8) + M2C_BITWISE(f64, sp58);
            sp68 = sp28;
            sp30 = spB8.unk8 + sp58.unk8;
            spC8 = sp28;
            sp70 = (f64) sp30;
            spD0 = (f64) sp30;
        }
        var_r30_334 = 0;
        shadowsRendered += 1;
        temp_r3_337 = arg0->unk70;
        if (temp_r3_337 != NULL) {
            var_r29_347 = temp_r3_337->CalculateMatrices(NULL, -1, NULL, &arg0->unk10);
            arg0->unk70->GetNmbrOfNodes();
        } else {
            temp_r23_353 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 8);
            if (temp_r23_353 > 0) {
                var_r30_334 = 1;
                if (MKHeap::Current() != NULL) {
                    var_r3_365 = (Matrix *) (((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r23_353 << 6, NULL, 0, 0U));
                } else {
                    var_r3_365 = malloc(temp_r23_353 << 6);
                }
                var_r29_347 = var_r3_365;
                temp_r3_373 = MKModel_GetWorldMatrix(arg0);
                var_r9_374 = 0;
                var_r4_375 = 0;
loop_15:
                if (var_r9_374 < temp_r23_353) {
                    M2C_STRUCT_COPY(var_r29_347 + var_r4_375, temp_r3_373, 0x40);
                    var_r9_374 += 1;
                    var_r4_375 += 0x40;
                    goto loop_15;
                }
            } else {
                var_r29_347 = (Matrix *) &arg0->unk50;
            }
        }
        (*(s32 *) ((u8 *) &spD0 + 0x4)) = -1;
        (*(s32 *) ((u8 *) &spE0 + 0x4)) = -1;
        GXSetChanCtrl(GX_COLOR0A0, 0U, GX_SRC_REG, GX_SRC_VTX, 0U, GX_DF_CLAMP, GX_AF_SPOT);
        MK_SetVDMode((MK_VertexDescriptorMode) 1);
        temp_r28_419 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x44), s32 *, 4);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetClipMode(GX_CLIP_ENABLE);
        sp20 = lit_674;
        GXSetTevColor(GX_TEVREG0, (GXColor) &sp20);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_ZERO, GX_CC_C0);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXLoadTexObj(MKMat_MK2_GetBaseTexture(gpMKWhiteMaterial) + 0x60, GX_TEXMAP0);
        GXSetNumTexGens(1U);
        GXSetNumTevStages(1U);
        GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_AND, GX_ALWAYS, 0xFFU);
        var_r26_475 = 0;
        var_r24_476 = 0;
        temp_r27_478 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s16 *, 4);
loop_27:
        if (var_r26_475 < (s32) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x44), s32 *, 8)) {
            if (((u32) (((u8) arg0->unk4 >> 5U) & 7) < 2U) || !(*(temp_r27_478 + (arg0->unk88 + var_r26_475)) & 0xF)) {
                temp_r5_499 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x6C);
                temp_r22_502 = temp_r5_499 + *(temp_r28_419 + (var_r24_476 + 4));
                temp_r21_505 = (MKVector3 *) (temp_r5_499 + M2C_FIELD(temp_r22_502, s32 *, 8));
                sp8 = (f64 *)-1;
                temp_r20_507 = temp_r5_499 + M2C_FIELD(temp_r22_502, s32 *, 0xC);
                DetectEdges(temp_r21_505, temp_r20_507, M2C_FIELD(temp_r22_502, s32 *, 0), M2C_FIELD(temp_r22_502, s32 *, 4), var_r29_347, *((MKVector3 *) &spE8), *((MKVector3 *) &spF8), *((MKVector3 *) &spC8), arg2, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
                var_r19_513 = 0;
                do {
                    if (var_r19_513 == 0) {
                        MKShadow_VolumeRenderStage1();
                    } else {
                        MKShadow_VolumeRenderStage2();
                    }
                    sp8 = &spC8;
                    spC = -1;
                    sp10 = 0;
                    sp14 = 0;
                    sp18 = 0;
                    sp1C = (s32) arg5;
                    RenderEdges(temp_r21_505, temp_r20_507, M2C_FIELD(temp_r22_502, s32 *, 0), M2C_FIELD(temp_r22_502, s32 *, 4), var_r29_347, *((MKVector3 *) &spE8), *((MKVector3 *) &spF8), *((MKVector3 *) &spD8), *(M2C_ERROR(/* Unable to find stack arg 0x0 in block */)), arg2, M2C_ERROR(/* Unable to find stack arg 0x4 in block */), M2C_ERROR(/* Unable to find stack arg 0x8 in block */), M2C_ERROR(/* Unable to find stack arg 0xc in block */), M2C_ERROR(/* Unable to find stack arg 0x10 in block */), M2C_ERROR(/* Unable to find stack arg 0x14 in block */));
                    var_r19_513 += 1;
                } while (var_r19_513 < 2);
            }
            var_r26_475 += 1;
            var_r24_476 += 8;
            goto loop_27;
        }
        if (var_r30_334 != 0) {
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Main()))->TFree(var_r29_347, NULL, 0);
            } else {
                free(var_r29_347);
            }
        }
        GXSetClipMode(GX_CLIP_ENABLE);
        GXSetCullMode(GX_CULL_NONE);
        MKMaterial_SetMaterial(NULL);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKShadowSubObjectMP'
void RenderEdges(MKVector3 *arg0, MKShadowSubObjectMP::Edge *arg1, int arg2, int arg3, Matrix *arg4, const MKVector3 &arg5, const MKVector3 &arg6, const MKVector3 &arg7, const MKVector3 &arg_sp0, float farg0, unsigned int arg_sp4, MKCloth *arg_sp8, int arg_spC, int *arg_sp10, bool arg_sp14) {
    f32 temp_f10_656;
    f32 temp_f10_704;
    f32 temp_f11_660;
    f32 temp_f12_653;
    f32 temp_f13_651;
    f32 temp_f1_647;
    f32 temp_f2_613;
    f32 temp_f2_645;
    f32 temp_f30_649;
    f32 temp_f3_614;
    f32 temp_f3_643;
    f32 temp_f4_677;
    f32 temp_f4_710;
    f32 temp_f5_654;
    f32 temp_f5_702;
    f32 temp_f6_657;
    f32 temp_f6_698;
    f32 temp_f7_664;
    f32 temp_f7_700;
    f32 temp_f8_703;
    f32 temp_f9_667;
    f32 temp_f9_701;
    f64 temp_f4_672;
    s32 var_ctr_606;
    s32 var_r3_604;
    s32 var_r4_605;
    void *temp_r5_612;
    void *temp_r6_611;
    void *var_r8_625;
    void *var_r9_626;

    GXFlush();
    var_r3_604 = 0;
    var_r4_605 = 0;
    var_ctr_606 = arg3;
    if (arg3 > 0) {
        do {
            temp_r6_611 = arg1 + var_r4_605;
            temp_r5_612 = pShadowEdgeResultBuffer + var_r3_604;
            temp_f2_613 = M2C_FIELD(temp_r5_612, f32 *, 0);
            temp_f3_614 = M2C_FIELD(temp_r5_612, f32 *, 4);
            if ((temp_f2_613 <= 0.0f) && (temp_f3_614 > 0.0f)) {
                var_r8_625 = pShadowVertexBuffer + (M2C_FIELD(temp_r6_611, s32 *, 0) * 0x10);
                var_r9_626 = pShadowVertexBuffer + (M2C_FIELD(temp_r6_611, s32 *, 4) * 0x10);
                goto block_7;
            }
            if ((temp_f3_614 <= 0.0f) && (temp_f2_613 > 0.0f)) {
                var_r9_626 = pShadowVertexBuffer + (M2C_FIELD(temp_r6_611, s32 *, 0) * 0x10);
                var_r8_625 = pShadowVertexBuffer + (M2C_FIELD(temp_r6_611, s32 *, 4) * 0x10);
block_7:
                temp_f3_643 = M2C_FIELD(var_r8_625, f32 *, 0);
                temp_f2_645 = M2C_FIELD(var_r8_625, f32 *, 4);
                temp_f1_647 = M2C_FIELD(var_r8_625, f32 *, 8);
                temp_f30_649 = M2C_FIELD(var_r9_626, f32 *, 0);
                temp_f13_651 = M2C_FIELD(var_r9_626, f32 *, 4);
                temp_f12_653 = M2C_FIELD(var_r9_626, f32 *, 8);
                temp_f5_654 = arg6.unk4;
                *(s8 *)0xCC008000 = 0x99;
                temp_f10_656 = temp_f13_651 - temp_f5_654;
                temp_f6_657 = arg6.unk0;
                *(s8 *)0xCC008000 = 6;
                temp_f11_660 = temp_f30_649 - temp_f6_657;
                *(s8 *)0xCC008000 = (f64) M2C_FIELD(&arg7, f64 *, 0);
                temp_f7_664 = arg6.unk8;
                *(s8 *)0xCC008000 = (f64) M2C_FIELD(&arg7, f64 *, 8);
                temp_f9_667 = temp_f12_653 - temp_f7_664;
                *(s8 *)0xCC008000 = (f64) M2C_FIELD(var_r9_626, f32 *, 0);
                *(s8 *)0xCC008000 = temp_f12_653;
                temp_f4_672 = __frsqrte((temp_f9_667 * temp_f9_667) + ((temp_f11_660 * temp_f11_660) + (temp_f10_656 * temp_f10_656)));
                *(s8 *)0xCC008000 = -1;
                *(s8 *)0xCC008000 = (f64) M2C_FIELD(var_r8_625, f32 *, 0);
                temp_f4_677 = farg0 * (f32) temp_f4_672;
                *(s8 *)0xCC008000 = temp_f1_647;
                *(s8 *)0xCC008000 = -1;
                if (arg_sp1C != 0) {
                    *(s8 *)0xCC008000 = (f32) ((temp_f11_660 * temp_f4_677) + temp_f6_657);
                    *(s8 *)0xCC008000 = (f32) ((temp_f10_656 * temp_f4_677) + temp_f5_654);
                    *(s8 *)0xCC008000 = (f32) ((temp_f9_667 * temp_f4_677) + temp_f7_664);
                    *(s8 *)0xCC008000 = -1;
                } else {
                    *(s8 *)0xCC008000 = (f32) ((temp_f11_660 * temp_f4_677) + temp_f30_649);
                    *(s8 *)0xCC008000 = (f32) ((temp_f10_656 * temp_f4_677) + temp_f13_651);
                    *(s8 *)0xCC008000 = (f32) ((temp_f9_667 * temp_f4_677) + temp_f12_653);
                    *(s8 *)0xCC008000 = -1;
                }
                temp_f6_698 = arg6.unk4;
                temp_f7_700 = arg6.unk0;
                temp_f9_701 = temp_f2_645 - temp_f6_698;
                temp_f5_702 = arg6.unk8;
                temp_f8_703 = temp_f3_643 - temp_f7_700;
                temp_f10_704 = temp_f1_647 - temp_f5_702;
                temp_f4_710 = farg0 * (f32) __frsqrte((temp_f10_704 * temp_f10_704) + ((temp_f8_703 * temp_f8_703) + (temp_f9_701 * temp_f9_701)));
                if (arg_sp1C != 0) {
                    *(void *)0xCC008000 = (f32) ((temp_f8_703 * temp_f4_710) + temp_f7_700);
                    *(void *)0xCC008000 = (f32) ((temp_f9_701 * temp_f4_710) + temp_f6_698);
                    *(void *)0xCC008000 = (f32) ((temp_f10_704 * temp_f4_710) + temp_f5_702);
                    *(void *)0xCC008000 = -1;
                } else {
                    *(void *)0xCC008000 = (f32) ((temp_f8_703 * temp_f4_710) + temp_f3_643);
                    *(void *)0xCC008000 = (f32) ((temp_f9_701 * temp_f4_710) + temp_f2_645);
                    *(void *)0xCC008000 = (f32) ((temp_f10_704 * temp_f4_710) + temp_f1_647);
                    *(void *)0xCC008000 = -1;
                }
                *(void *)0xCC008000 = (f64) arg_sp8->unk0;
                *(void *)0xCC008000 = (f64) M2C_FIELD(arg_sp8, f64 *, 8);
            }
            var_r3_604 += 8;
            var_r4_605 += 0x10;
            var_ctr_606 -= 1;
        } while (var_ctr_606 != 0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'MKShadowSubObjectMP'
void DetectEdges(MKVector3 *arg0, MKShadowSubObjectMP::Edge *arg1, int arg2, int arg3, Matrix *arg4, const MKVector3 &arg5, const MKVector3 &arg6, const MKVector3 &arg7, float farg0, unsigned int arg_sp0) {
    MKShadowSubObjectMP::Edge *var_r8_837;
    Matrix *temp_r5_805;
    Matrix *var_r9_838;
    f32 temp_f10_873;
    f32 temp_f11_839;
    f32 temp_f12_840;
    f32 temp_f13_841;
    f32 temp_f1_860;
    f32 temp_f25_869;
    f32 temp_f26_880;
    f32 temp_f28_882;
    f32 temp_f29_863;
    f32 temp_f2_868;
    f32 temp_f30_870;
    f32 temp_f31_879;
    f32 temp_f3_864;
    f32 temp_f4_867;
    f32 temp_f4_875;
    f32 temp_f5_800;
    f32 temp_f5_865;
    f32 temp_f6_874;
    f32 temp_f6_888;
    f32 temp_f7_802;
    f32 temp_f7_866;
    f32 temp_f7_885;
    f32 temp_f8_804;
    f32 temp_f8_862;
    f32 temp_f8_872;
    f32 temp_f9_876;
    f32 temp_f9_884;
    s32 temp_r0_796;
    s32 temp_r0_853;
    s32 temp_r3_854;
    s32 temp_r4_795;
    s32 temp_r4_851;
    s32 temp_r5_849;
    s32 var_ctr_790;
    s32 var_ctr_842;
    s32 var_r3_789;
    void *temp_r3_858;
    void *temp_r4_857;
    void *temp_r5_856;
    void *temp_r6_797;
    void *temp_r7_859;

    LCQueueWait(0U);
    LCLoadData(pShadowVertexBuffer, arg0, arg2 * 0x10);
    LCQueueWait(0U);
    var_r3_789 = 0;
    var_ctr_790 = arg2;
    if (arg2 > 0) {
        do {
            temp_r4_795 = var_r3_789 + 4;
            temp_r0_796 = var_r3_789 + 8;
            temp_r6_797 = pShadowVertexBuffer + var_r3_789;
            var_r3_789 += 0x10;
            temp_f5_800 = M2C_FIELD(temp_r6_797, f32 *, 4);
            temp_f7_802 = M2C_FIELD(temp_r6_797, f32 *, 0);
            temp_f8_804 = M2C_FIELD(temp_r6_797, f32 *, 8);
            temp_r5_805 = &arg4[(s8) M2C_FIELD(temp_r6_797, u8 *, 0xF)];
            M2C_FIELD(temp_r6_797, f32 *, 0) = (f32) (temp_r5_805->unk30 + ((temp_f8_804 * temp_r5_805->unk20) + ((temp_f7_802 * temp_r5_805->unk0) + (temp_f5_800 * temp_r5_805->unk10))));
            *(pShadowVertexBuffer + temp_r4_795) = temp_r5_805->unk34 + ((temp_f8_804 * temp_r5_805->unk24) + ((temp_f7_802 * temp_r5_805->unk4) + (temp_f5_800 * temp_r5_805->unk14)));
            *(pShadowVertexBuffer + temp_r0_796) = temp_r5_805->unk38 + ((temp_f8_804 * temp_r5_805->unk28) + ((temp_f7_802 * temp_r5_805->unk8) + (temp_f5_800 * temp_r5_805->unk18)));
            var_ctr_790 -= 1;
        } while (var_ctr_790 != 0);
    }
    var_r8_837 = arg1;
    var_r9_838 = pShadowEdgeResultBuffer;
    temp_f11_839 = arg5.unk0;
    temp_f12_840 = arg5.unk4;
    temp_f13_841 = arg5.unk8;
    var_ctr_842 = arg3;
    if (arg3 > 0) {
        do {
            temp_r5_849 = M2C_FIELD(var_r8_837, s32 *, 0) * 0x10;
            temp_r4_851 = M2C_FIELD(var_r8_837, s32 *, 4) * 0x10;
            temp_r0_853 = M2C_FIELD(var_r8_837, s32 *, 8) * 0x10;
            temp_r3_854 = M2C_FIELD(var_r8_837, s32 *, 0xC) * 0x10;
            var_r8_837 += 0x10;
            temp_r5_856 = pShadowVertexBuffer + temp_r5_849;
            temp_r4_857 = pShadowVertexBuffer + temp_r4_851;
            temp_r3_858 = pShadowVertexBuffer + temp_r3_854;
            temp_r7_859 = pShadowVertexBuffer + temp_r0_853;
            temp_f1_860 = M2C_FIELD(temp_r5_856, f32 *, 0);
            temp_f8_862 = M2C_FIELD(temp_r3_858, f32 *, 0);
            temp_f29_863 = M2C_FIELD(temp_r7_859, f32 *, 0) - temp_f1_860;
            temp_f3_864 = M2C_FIELD(temp_r4_857, f32 *, 0);
            temp_f5_865 = temp_f1_860 - temp_f8_862;
            temp_f7_866 = M2C_FIELD(temp_r5_856, f32 *, 8);
            temp_f4_867 = M2C_FIELD(temp_r4_857, f32 *, 8);
            temp_f2_868 = temp_f3_864 - temp_f1_860;
            temp_f25_869 = M2C_FIELD(temp_r3_858, f32 *, 8);
            temp_f30_870 = temp_f4_867 - temp_f7_866;
            temp_f8_872 = temp_f3_864 - temp_f8_862;
            temp_f10_873 = temp_f4_867 - temp_f25_869;
            temp_f6_874 = M2C_FIELD(temp_r5_856, f32 *, 4);
            temp_f4_875 = M2C_FIELD(temp_r7_859, f32 *, 8) - temp_f7_866;
            temp_f9_876 = M2C_FIELD(temp_r4_857, f32 *, 4);
            temp_f31_879 = temp_f9_876 - temp_f6_874;
            temp_f26_880 = M2C_FIELD(temp_r3_858, f32 *, 4);
            temp_f28_882 = M2C_FIELD(temp_r7_859, f32 *, 4) - temp_f6_874;
            temp_f9_884 = temp_f9_876 - temp_f26_880;
            temp_f7_885 = temp_f7_866 - temp_f25_869;
            temp_f6_888 = temp_f6_874 - temp_f26_880;
            var_r9_838->unk0 = (((temp_f29_863 * temp_f31_879) - (temp_f28_882 * temp_f2_868)) * temp_f13_841) + ((((temp_f28_882 * temp_f30_870) - (temp_f4_875 * temp_f31_879)) * temp_f11_839) + (((temp_f4_875 * temp_f2_868) - (temp_f29_863 * temp_f30_870)) * temp_f12_840));
            var_r9_838->unk4 = (((temp_f5_865 * temp_f9_884) - (temp_f6_888 * temp_f8_872)) * temp_f13_841) + ((((temp_f6_888 * temp_f10_873) - (temp_f7_885 * temp_f9_884)) * temp_f11_839) + (((temp_f7_885 * temp_f8_872) - (temp_f5_865 * temp_f10_873)) * temp_f12_840));
            var_r9_838 += 8;
            var_ctr_842 -= 1;
        } while (var_ctr_842 != 0);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKShadow_ApplyAlphaTint(unsigned char arg0, float arg1) {
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp8;

    GXGetProjectionv(&sp8);
    sp24 = 0.02f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = -1.0f;
    sp34 = 0.0f;
    sp38 = -0.02f;
    sp3C = 0.0f;
    sp40 = 1.0f;
    sp44 = 0.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp50 = -1.0f;
    sp54 = 0.0f;
    sp58 = 0.0f;
    sp5C = 0.0f;
    sp60 = 1.0f;
    GXSetProjection((f32 (*)[4]) &sp24, GX_ORTHOGRAPHIC);
    GXSetCurrentMtx(3U);
    MK_SetVDMode((MK_VertexDescriptorMode) 0);
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT1, 4U);
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = arg0;
    *(0xCC010000 - 0x8000) = 0.0;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = arg1;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = arg0;
    *(0xCC010000 - 0x8000) = 0.0;
    *(f32 *)0xCC008000 = arg1;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = arg0;
    *(0xCC010000 - 0x8000) = 5.263544247e-315;
    *(f32 *)0xCC008000 = arg1;
    *(f32 *)0xCC008000 = arg1;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = 0xFF;
    *(f32 *)0xCC008000 = arg0;
    *(0xCC010000 - 0x8000) = 5.263544247e-315;
    GXSetProjectionv(&sp8);
    GXSetCurrentMtx(0U);
}
#endif

void MKShadow_VolumeRenderStage2() {
    GXSetCullMode(GX_CULL_BACK);
    GXSetColorUpdate(0U);
    GXSetBlendMode(GX_BM_SUBTRACT, GX_BL_ONE, GX_BL_ONE, GX_LO_XOR);
    GXSetDstAlpha(0U, 0x3FU);
    GXSetZMode(1U, GX_GEQUAL, 0U);
    GXFlush();
}

void MKShadow_VolumeRenderStage1() {
    GXSetCullMode(GX_CULL_FRONT);
    GXSetColorUpdate(0U);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_XOR);
    GXSetDstAlpha(0U, 0x3FU);
    GXSetZMode(1U, GX_GEQUAL, 0U);
    GXFlush();
}

#if 0 // DRAFT: function call 'GXSetCopyFilter(unsigned int, _GXRenderModeObj *, unsigned int, _GXRenderModeObj *)' does not match 'GXSetCopyFilter(unsigned char, const unsigne
void MKShadow_BeginScene() {
    GXRenderModeObj *temp_r3_1121;

    shadowsRendered = 0;
    MKMaterial_SetMaterial(NULL);
    MKMaterial_SetLocalToWorld(NULL, 1.0f);
    GXSetAlphaUpdate(1U);
    temp_r3_1121 = GPGetRenderModeObj();
    GXSetCopyFilter(0U, temp_r3_1121 + 0x1A, 0U, temp_r3_1121 + 0x32);
    GXSetTexCopySrc(0U, 0U, 0x280U, 0x190U);
    GXSetTexCopyDst(0x280U, 0x190U, GX_TF_A8, 0U);
    GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'RoundUp'
void MKShadow_InitModule() {
    Matrix *var_r3_1178;
    u32 temp_r31_1169;

    RoundUp((M2C_FIELD(&gMKDefaults, s32 *, 0x50) + 1) * 0x10, 0x20);
    temp_r31_1169 = RoundUp(M2C_FIELD(&gMKDefaults, s32 *, 0x54) * 8, 0x20);
    pShadowVertexBuffer = (void *)0xE0000000;
    if (MKHeap::Current() != NULL) {
        var_r3_1178 = (Matrix *) (((MKHeap *) (MKHeap::Current()))->Alloc((s32) temp_r31_1169, NULL, 0));
    } else {
        var_r3_1178 = malloc(temp_r31_1169);
    }
    pShadowEdgeResultBuffer = var_r3_1178;
}
#endif

u32 RoundUp(int arg0, int arg1) {
    return ((s32) (arg0 + (arg1 - 1)) / arg1) * arg1;
}

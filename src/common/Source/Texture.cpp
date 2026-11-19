#include "common/Source/Texture.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "dolphin/os.h"
#include "common/Source/FileSys.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKView.h"
#include "common/Source/Str.h"
#include "common/gc/MKMat_MK2_Standard_GC.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/System_GC.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
s8 *malloc(s32);                                    /* extern */
s32 stricmp(MKResource *, Texture *, MKResource *); /* extern */
extern s32 lit_520;
extern s8 MKMat_MK2_Standard_CaptureTextureData;
extern s8 *Texture_pTextures;
extern u8 attemptToLockTextureInCache;
extern M2C_UNK gDisplay;
#if 0 // DRAFT: identifier 'Texture_filterType' redeclared
static s32 Texture_filterType = 2;
#endif
#if 0 // DRAFT: undefined identifier 'saved_reg_r31'
static M2C_UNK lit_515;                                /* unable to generate initializer: unknown type; const */
static MKResource lit_stringBase0;                     /* type too large by 0x1D; unable to generate initializer: non-zero padding; const */

void Texture::ReloadGuts(float arg0) {
    s32 spC;
    u32 sp8;
    GXTexRegion *temp_r3_57;
    enum _GXTexFilter var_r4_242;
    s32 temp_r0_148;
    s32 temp_r0_209;
    s32 temp_r29_55;
    s32 var_ctr_217;
    s32 var_r4_215;
    s32 var_r5_208;
    s8 *temp_r3_134;
    s8 *var_r31_0;

    var_r31_0 = saved_reg_r31;
    if (((GXTexRegion *) this->unk48 == NULL) && (stricmp(&lit_stringBase0, this) != 0)) {
        M2C_FIELD(this, u8 *, 0x3C) = 0U;
        if ((u8) attemptToLockTextureInCache != 0) {
            MKHeap::ActivateTempMemOverride();
            var_r31_0 = MKArchive_Load(Str_Printf(&lit_stringBase0.unk8, this), (int *) &spC, NULL, -1);
            MKHeap::DeactivateTempMemOverride();
            DCStoreRange(var_r31_0, (u32) spC);
            this->unk34 = spC - 0x20;
            if ((s32) M2C_FIELD(var_r31_0, s32 *, 0x14) == 0) {
                temp_r29_55 = (this->unk34 + 0x1F) & 0xFFFFFFE0;
                temp_r3_57 = RequestPreloadedTextureRegion(temp_r29_55, (unsigned int *) &sp8);
                if (temp_r3_57 != NULL) {
                    this->unk48 = temp_r3_57;
                    this->unk38 = 0;
                    M2C_FIELD(this, u8 *, 0x3C) = 1U;
                    this->unk24 = M2C_FIELD(var_r31_0, s32 *, 4);
                    this->unk28 = M2C_FIELD(var_r31_0, s32 *, 8);
                    GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_CMPR, GX_REPEAT, GX_REPEAT, 0U);
                    GXInitTexPreLoadRegion(temp_r3_57, sp8, (u32) temp_r29_55, 0U, 0U);
                    GXPreLoadEntireTexture(&this->unk60, temp_r3_57);
                    GXLoadTexObjPreLoaded(&this->unk60, this->unk48, GX_TEXMAP0);
                    attemptToLockTextureInCache = 0;
                    if (MKHeap::Current() != NULL) {
                        ((MKHeap *) (MKHeap::Current()))->Free(var_r31_0, NULL, 0);
                        return;
                    }
                    free(var_r31_0);
                    return;
                }
            }
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(var_r31_0, NULL, 0);
            } else {
                free(var_r31_0);
            }
            goto block_11;
        }
block_11:
        if ((u8) M2C_FIELD(this, u8 *, 0x3C) == 0) {
            temp_r3_134 = MKArchive_Load(Str_Printf(&lit_stringBase0.unk8, this), (int *) &spC, NULL, -1);
            var_r31_0 = temp_r3_134;
            DCStoreRange(temp_r3_134, (u32) spC);
            this->unk48 = (GXTexRegion *) var_r31_0;
            this->unk38 = 1;
            this->unk34 = (u32) spC;
            this->unk24 = M2C_FIELD(var_r31_0, s32 *, 4);
            this->unk28 = M2C_FIELD(var_r31_0, s32 *, 8);
        }
        temp_r0_148 = M2C_FIELD(var_r31_0, s32 *, 0);
        switch (temp_r0_148) {                      /* irregular */
        case 1:
            break;
        case 0:
            memset(&this->unk60, 0, 0x20U);
            GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_RGB5A3, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 2:
            memset(&this->unk60, 0, 0x20U);
            if ((s32) M2C_FIELD(var_r31_0, s32 *, 0x14) == 0) {
                GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_CMPR, GX_REPEAT, GX_REPEAT, 0U);
            } else {
                GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_CMPR, GX_REPEAT, GX_REPEAT, 1U);
                var_r5_208 = this->unk28;
                temp_r0_209 = this->unk24;
                if (temp_r0_209 < var_r5_208) {
                    var_r5_208 = temp_r0_209;
                }
                var_r4_215 = 0x1F;
                var_ctr_217 = 0x20;
loop_25:
                if (!(var_r5_208 & (1 << var_r4_215))) {
                    var_r4_215 -= 1;
                    var_ctr_217 -= 1;
                    if (var_ctr_217 != 0) {
                        goto loop_25;
                    }
                }
                if ((s32) Texture_filterType != 2) {
                    if ((s32) Texture_filterType < 2) {
                        if ((s32) Texture_filterType < 0) {
                            goto block_33;
                        }
                        var_r4_242 = GX_LINEAR;
                    } else {
block_33:
                        var_r4_242 = GX_LIN_MIP_LIN;
                    }
                } else {
                    var_r4_242 = GX_LIN_MIP_LIN;
                }
                GXInitTexObjLOD(&this->unk60, var_r4_242, GX_LINEAR, 0.0f, (f32) var_r4_215 - 3.0f, 0.0f, 1U, 0U, GX_ANISO_1);
            }
            break;
        }
        goto block_35;
    }
block_35:
    attemptToLockTextureInCache = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
s8 *Texture::CreateMpegTarget(const char *arg0, void *arg1, int arg2, int arg3) {
    MKHeap *var_r31_280;
    s8 *temp_r4_300;
    s8 *var_r3_294;

    var_r31_280 = Find(arg0);
    if (var_r31_280 != NULL) {
        var_r31_280->unk2C += 1;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_294 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0);
        } else {
            var_r3_294 = malloc(0xA0);
        }
        temp_r4_300 = Texture_pTextures;
        var_r31_280 = (MKHeap *) var_r3_294;
        Texture_pTextures = var_r3_294;
        M2C_FIELD(var_r3_294, s8 **, 0x80) = temp_r4_300;
        M2C_FIELD(var_r3_294, s32 *, 0x84) = 0;
        if (temp_r4_300 != NULL) {
            M2C_FIELD(temp_r4_300, s8 **, 0x84) = var_r3_294;
        }
        var_r31_280->unk48 = NULL;
        strcpy((s8 *) var_r31_280, Str_CopyString(&this->unk0, 0x1F));
        var_r31_280->unk24 = (s32) arg1;
        var_r31_280->unk28 = (MKHeap *) arg2;
        var_r31_280->unk2C = 1;
        ((MKResource *) var_r31_280)->InitialiseResource();
        M2C_FIELD(var_r31_280, s8 *, 0x32) = 1;
        var_r31_280->unk3C = 0;
        var_r31_280->unk40 = 0;
        var_r31_280->unk44 = 0;
    }
    return (s8 *) var_r31_280;
}
#endif

#if 0 // DRAFT: undefined identifier 'spC0'
void Texture::CaptureDrawBuffer(float arg0, float arg1, float arg2, float arg3) {
    GXTexObj spA0;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    enum _GXTexFmt sp48;
    enum _GXTexWrapMode sp44;
    enum _GXTexWrapMode sp40;
    void *sp3C;
    u32 sp38;
    u32 sp34;
    u32 sp30;
    u32 sp2C;
    s32 sp28;
    u16 sp24;
    u16 sp22;
    u8 sp20;
    GXRenderModeObj *temp_r31_398;
    f32 temp_f28_411;
    f32 temp_f31_405;

    GXGetTexObjAll(&this->unk60, &sp3C, &sp24, &sp22, &sp48, &sp44, &sp40, &sp20);
    sp78 = M2C_FIELD(&lit_515, f32 *, 8);
    sp7C = M2C_FIELD(&lit_515, f32 *, 0xC);
    sp70 = M2C_FIELD(&lit_515, f32 *, 0);
    sp74 = M2C_FIELD(&lit_515, f32 *, 4);
    sp78 = (f32) M2C_FIELD(&gDisplay, s32 *, 0x10);
    sp7C = (f32) M2C_FIELD(&gDisplay, s32 *, 0x14);
    temp_r31_398 = GPGetRenderModeObj();
    temp_f31_405 = sp78 * 0.5f;
    if ((f32) sp24 == temp_f31_405) {
        temp_f28_411 = sp7C * 0.5f;
        if ((f32) sp22 == temp_f28_411) {
            GXSetCopyFilter(0U, NULL, 0U, NULL);
            GXSetTexCopySrc((u16) (s32) sp70, (u16) (s32) sp74, (u16) (s32) sp78, (u16) (s32) sp7C);
            GXSetTexCopyDst((u16) (s32) temp_f31_405, (u16) (s32) temp_f28_411, GX_TF_RGBA8, 1U);
            GXCopyTex(sp3C, 0U);
            GXSetCopyFilter(temp_r31_398->aa, (u8 (*)[2]) temp_r31_398->sample_pattern[0], 1U, temp_r31_398->vfilter);
            return;
        }
    }
    GXInitTexObj(&spA0, &MKMat_MK2_Standard_CaptureTextureData, 0x140U, 0xC8U, GX_TF_RGBA8, GX_CLAMP, GX_CLAMP, 0U);
    GXInitTexObjLOD(&spA0, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
    GXSetCopyFilter(0U, NULL, 0U, NULL);
    GXSetTexCopySrc((u16) (s32) sp70, (u16) (s32) sp74, (u16) (s32) sp78, (u16) (s32) sp7C);
    GXSetTexCopyDst((u16) (s32) temp_f31_405, (u16) (s32) (sp7C * 0.5f), GX_TF_RGBA8, 1U);
    GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
    GXPixModeSync();
    GXInvalidateTexAll();
    GXGetViewportv(&sp80);
    GXGetScissor(&sp38, &sp34, &sp30, &sp2C);
    MKView_Push();
    C_MTXOrtho((f32 (*)[4]) &spC0[0], 0.0f, (f32) sp22, 0.0f, (f32) sp24, 0.0f, 1.0f);
    GXSetCurrentMtx(3U);
    GXSetProjection((f32 (*)[4]) &spC0[0], GX_ORTHOGRAPHIC);
    MKMaterial_SetMaterial(NULL);
    GXSetDither(0U);
    GXSetViewport(0.0f, 400.0f, (f32) sp24, (f32) sp22, 0.0f, 1.0f);
    GXSetScissor(0U, 0x190U, (u32) sp24, (u32) sp22);
    GXSetChanCtrl(GX_COLOR0A0, 0U, GX_SRC_REG, GX_SRC_VTX, 0U, GX_DF_CLAMP, GX_AF_SPOT);
    sp28 = lit_520;
    GXSetChanAmbColor(GX_COLOR0A0, (GXColor) &sp28);
    GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(0U, GX_ALWAYS, 0U);
    GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_OR, GX_ALWAYS, 0U);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ZERO, GX_LO_NOOP);
    GXLoadTexObj(&spA0, GX_TEXMAP0);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
    GXSetNumTevStages(1U);
    GXSetNumTexGens(1U);
    GXSetNumIndStages(0U);
    sp58 = 0.0f;
    sp50 = (f32) sp22;
    sp54 = (f32) sp24;
    sp68 = (f64) sp58;
    sp60 = (f64) sp50;
    DrawQuad(MKVector3::zero, *((MKVector3 *) &sp60), MKVector3::zero, MKVector3::one, -1U);
    GXSetTexCopySrc(0U, 0x190U, sp24, sp22);
    GXSetTexCopyDst(sp24, sp22, GX_TF_RGBA8, 0U);
    GXCopyTex(sp3C, 1U);
    GXPixModeSync();
    GXInvalidateTexAll();
    GXSetViewport(sp80, sp84, sp88, sp8C, sp90, sp94);
    GXSetScissor(sp38, sp34, sp30, sp2C);
    GXSetCurrentMtx(0U);
    GXSetPixelFmt(GX_PF_RGBA6_Z24, GX_ZC_LINEAR);
    GXSetDither(1U);
    GXSetCopyFilter(temp_r31_398->aa, (u8 (*)[2]) temp_r31_398->sample_pattern[0], 1U, temp_r31_398->vfilter);
    MKMaterial_SetMaterial(NULL);
    MKView_Pop();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void Texture::CreateRenderTarget(const char *arg0, int arg1, int arg2, int arg3) {
    s32 var_r30_749;
    s8 *var_r3_768;

    var_r30_749 = arg1;
    if (stricmp(&lit_stringBase0, this, &lit_stringBase0) == 0) {
        var_r3_768 = CreateFromRawData(&MKMat_MK2_Standard_CaptureTextureData, (void *) arg2, (s32) M2C_FIELD(&gDisplay, s32 *, 0x10) / 2, (s32) M2C_FIELD(&gDisplay, s32 *, 0x14) / 2, 0, M2C_ERROR(/* Read from unset register $r9 */));
    } else {
        if (var_r30_749 > 0x80) {
            var_r30_749 = 0x80;
        }
        var_r3_768 = CreateFromRawData(NULL, (void *) arg2, (s32) arg0, var_r30_749, 0, M2C_ERROR(/* Read from unset register $r9 */));
    }
    M2C_FIELD(var_r3_768, s8 *, 0x30) = 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
s8 *Texture::CreateFromRawData(const char *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5) {
    MKHeap *temp_r6_890;
    MKHeap *var_r31_805;
    enum _GXTexWrapMode var_r8_903;
    enum _GXTexWrapMode var_r9_894;
    s32 temp_r5_899;
    s8 *temp_r4_825;
    s8 *var_r30_800;
    s8 *var_r3_1033;
    s8 *var_r3_819;
    s8 *var_r3_877;
    s8 *var_r3_927;
    s8 *var_r3_963;
    s8 *var_r3_998;

    var_r30_800 = arg0;
    var_r31_805 = Find(arg0);
    if (var_r31_805 != NULL) {
        var_r31_805->unk2C += 1;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_819 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0);
        } else {
            var_r3_819 = malloc(0xA0);
        }
        temp_r4_825 = Texture_pTextures;
        var_r31_805 = (MKHeap *) var_r3_819;
        Texture_pTextures = var_r3_819;
        M2C_FIELD(var_r3_819, s8 **, 0x80) = temp_r4_825;
        M2C_FIELD(var_r3_819, s32 *, 0x84) = 0;
        if (temp_r4_825 != NULL) {
            M2C_FIELD(temp_r4_825, s8 **, 0x84) = var_r3_819;
        }
        strcpy((s8 *) var_r31_805, Str_CopyString(&this->unk0, 0x1F));
        var_r31_805->unk24 = arg2;
        var_r31_805->unk28 = (MKHeap *) arg3;
        M2C_FIELD(var_r31_805, s32 *, 0x34) = -1;
        M2C_FIELD(var_r31_805, s8 *, 0x38) = (s8) (var_r30_800 == NULL);
        M2C_FIELD(var_r31_805, s8 *, 0x32) = 0;
        M2C_FIELD(var_r31_805, s8 *, 0x30) = 0;
        M2C_FIELD(var_r31_805, s8 *, 0x3C) = 0;
        switch (arg1) {                             /* irregular */
        case 0x0:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_877 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 4, NULL, 0);
                } else {
                    var_r3_877 = malloc(arg2 * arg3 * 4);
                }
                var_r30_800 = var_r3_877;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            temp_r6_890 = var_r31_805->unk28;
            if ((s32) temp_r6_890 & (s32) (temp_r6_890 - 1)) {
                var_r9_894 = GX_CLAMP;
            } else {
                var_r9_894 = GX_REPEAT;
            }
            temp_r5_899 = var_r31_805->unk24;
            if (temp_r5_899 & (temp_r5_899 - 1)) {
                var_r8_903 = GX_CLAMP;
            } else {
                var_r8_903 = GX_REPEAT;
            }
            GXInitTexObj((GXTexObj *) &var_r31_805->unk60, var_r30_800, (u16) temp_r5_899, (u16) temp_r6_890, GX_TF_RGBA8, var_r8_903, var_r9_894, 0U);
            break;
        case 0x4A:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_927 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 2, NULL, 0);
                } else {
                    var_r3_927 = malloc(arg2 * arg3 * 2);
                }
                var_r30_800 = var_r3_927;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj((GXTexObj *) &var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_RGB565, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 0x4B:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_963 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 2, NULL, 0);
                } else {
                    var_r3_963 = malloc(arg2 * arg3 * 2);
                }
                var_r30_800 = var_r3_963;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj((GXTexObj *) &var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_RGB5A3, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 0x40:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_998 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3, NULL, 0);
                } else {
                    var_r3_998 = malloc(arg2 * arg3);
                }
                var_r30_800 = var_r3_998;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj((GXTexObj *) &var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_I8, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 0x4C:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_1033 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 2, NULL, 0);
                } else {
                    var_r3_1033 = malloc(arg2 * arg3 * 2);
                }
                var_r30_800 = var_r3_1033;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj((GXTexObj *) &var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_IA8, GX_REPEAT, GX_REPEAT, 0U);
            break;
        }
        var_r31_805->unk48 = (MKHeap *) var_r30_800;
        var_r31_805->unk2C = 1;
        ((MKResource *) var_r31_805)->InitialiseResource();
    }
    return (s8 *) var_r31_805;
}
#endif

void Texture::Use() {
    if ((u8) this->unk32 == 0) {
        if ((u8) M2C_FIELD(this, u8 *, 0x3C) == 0) {
            GXLoadTexObj(&this->unk60, GX_TEXMAP0);
            return;
        }
        GXLoadTexObjPreLoaded(&this->unk60, this->unk48, GX_TEXMAP0);
        return;
    }
    GXLoadTexObj(&this->unk60, GX_TEXMAP0);
}

#if 0 // DRAFT: function call 'Str_CopyString(signed char *, int)' does not match
MKHeap *Texture::Find(const char *arg0) {
    s8 *var_r30_1114;
    u8 *temp_r31_1115;

    var_r30_1114 = Texture_pTextures;
    temp_r31_1115 = Str_CopyString(&this->unk0, 0x1F);
loop_5:
    if (var_r30_1114 == NULL) {
        return NULL;
    }
    if ((stricmp((MKResource *) var_r30_1114, (Texture *) temp_r31_1115) == 0) && (((MKResource *) var_r30_1114)->IsResourceAvailable() != 0)) {
        return (MKHeap *) var_r30_1114;
    }
    var_r30_1114 = M2C_FIELD(var_r30_1114, s8 **, 0x80);
    goto loop_5;
}
#endif

#if 0 // DRAFT: type mismatch
void Texture::Destroy() {
    GXTexRegion *temp_r3_1155;
    s32 temp_r0_1152;
    s8 *temp_r3_1180;
    void *temp_r3_1174;

    temp_r0_1152 = this->unk2C - 1;
    this->unk2C = temp_r0_1152;
    if (temp_r0_1152 == 0) {
        temp_r3_1155 = this->unk48;
        if (temp_r3_1155 != NULL) {
            if ((u8) this->unk38 != 0) {
                ((MKHeap *) temp_r3_1155)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
            } else if ((u8) M2C_FIELD(this, u8 *, 0x3C) != 0) {
                ReleasePreloadedTextureRegion(temp_r3_1155);
            }
            this->unk48 = NULL;
        }
        temp_r3_1174 = this->unk84;
        if (temp_r3_1174 != NULL) {
            M2C_FIELD(temp_r3_1174, s8 **, 0x80) = (s8 *) this->unk80;
        }
        temp_r3_1180 = this->unk80;
        if (temp_r3_1180 != NULL) {
            M2C_FIELD(temp_r3_1180, void **, 0x84) = (void *) this->unk84;
        }
        if (this == (s8 *) Texture_pTextures) {
            Texture_pTextures = this->unk80;
        }
        MKHeap::FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
s8 *Texture::Create(const char *arg0, float arg1) {
    MKHeap *var_r31_1215;
    s8 *temp_r3_1241;

    var_r31_1215 = Find(arg0);
    if (var_r31_1215 != NULL) {
        var_r31_1215->unk2C += 1;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r31_1215 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0);
        } else {
            var_r31_1215 = malloc(0xA0);
        }
        memset(var_r31_1215, 0, 0xA0U);
        temp_r3_1241 = Texture_pTextures;
        Texture_pTextures = (s8 *) var_r31_1215;
        var_r31_1215->unk80 = M2C_BITWISE(f32, temp_r3_1241);
        var_r31_1215->unk84 = 0.0f;
        if (temp_r3_1241 != NULL) {
            M2C_FIELD(temp_r3_1241, MKHeap **, 0x84) = var_r31_1215;
        }
        strcpy((s8 *) var_r31_1215, Str_CopyString(&this->unk0, 0x1F));
        M2C_FIELD(var_r31_1215, s8 *, 0x32) = 0;
        M2C_FIELD(var_r31_1215, s8 *, 0x30) = 0;
        M2C_FIELD(var_r31_1215, s8 *, 0x3C) = 0;
        ((Texture *) var_r31_1215)->ReloadGuts(arg1);
        ((MKResource *) var_r31_1215)->InitialiseResource();
        var_r31_1215->unk2C = 1;
    }
    return (s8 *) var_r31_1215;
}
#endif

void Texture::InitModule() {
    *Texture::initialised = 1;
}

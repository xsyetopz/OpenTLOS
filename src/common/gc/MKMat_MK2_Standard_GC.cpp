#include "common/gc/MKMat_MK2_Standard_GC.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMat_MK2_Standard.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/OmniLight.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "dolphin/os.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

s32 stricmp(Texture *, M2C_UNK *);                  /* extern */
extern s32 lit_572;
extern s32 lit_643;
extern u8 MKLight_LightMask;
extern s32 MKMaterial_CurrentLocalityIndex;
#if 0 // DRAFT: identifier 'MKMaterial_GeometryColor' redeclared
extern M2C_UNK MKMaterial_GeometryColor;
#endif
#if 0 // DRAFT: identifier 'MKMaterial_LocalityArray' redeclared
extern M2C_UNK MKMaterial_LocalityArray;
#endif
extern u8 MKMaterial_NumTevStages;
extern u8 MKMaterial_bFogEnabled;
#if 0 // DRAFT: identifier 'MKMaterial_fogColor' redeclared
extern M2C_UNK MKMaterial_fogColor;
#endif
extern f32 MKMaterial_fogFar;
extern f32 MKMaterial_fogNear;
extern s32 MKView_SettingsCounter;
extern u8 bDebug;
extern u8 bLightsAreEnabled_471;
extern s32 currentInternalPass;
extern s32 currentPass;
extern u8 fogSetToBlack_568;
#if 0 // DRAFT: identifier 'gCurrentMaterialColorGC' redeclared
extern M2C_UNK gCurrentMaterialColorGC;
#endif
#if 0 // DRAFT: identifier 'gpCurrentMaterial' redeclared
extern MKMat_MK2_Standard *gpCurrentMaterial;
#endif
extern s32 gpMKcurrentMaterialEffectorMask;
extern MKMat_MK2_Standard *gpPreviousMaterial;
extern u8 init_469;
extern u8 init_472;
extern u8 init_537;
extern u8 init_540;
extern u8 init_569;
extern M2C_UNK oldFog_571;
extern u8 oldLights_468;
extern MKMaterial *pOverlay_536;
extern s32 viewCounter_539;
extern f32 weight128;
extern f32 weight64;
#if 0 // DRAFT: identifier 'MKMat_MK2_Standard_CaptureTextureData' redeclared
static M2C_UNK filterTextureSizes;                  /* unable to generate initializer: unknown type */
static M2C_UNK oldColor;                            /* unable to generate initializer: unknown type */
static M2C_UNK MKMat_MK2_Standard_CaptureTextureData; /* unable to generate initializer: unknown type */
static f32 omniFalloff = 17.0f;
#endif
static u8 bGlowEnabled = 1;
#if 0 // DRAFT: identifier 'MKMaterial_NumTexGens' redeclared
static u8 MKMaterial_NumTexGens = 1;
#endif

static s32 lit_484 = 4;
static M2C_UNK lit_599;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_610;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_637;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_638;                                /* unable to generate initializer: unknown type; const */
static s32 lit_457 = 0xFF;                             /* const */
static s32 lit_503 = 0xFFFFFFFF;                       /* const */
static M2C_UNK lit_507;                                /* unable to generate initializer: unknown type; const */
static s32 lit_510 = 0xE258;                           /* const */
static s32 lit_513 = 0xB30000B6;                       /* const */
static s32 lit_516 = 0xFF00FF80;                       /* const */
static M2C_UNK lit_636;                                /* unable to generate initializer: unknown type; const */
static s32 lit_645 = 0x04040404;                       /* const */

void DrawFilteredQuad(_GXTexObj *arg0, MKVector3 *arg1, const MKVector3 &arg2) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f23_117;
    f32 temp_f24_141;
    f32 temp_f25_140;
    f32 temp_f26_119;
    f64 temp_f0_178;
    s32 var_r27_105;
    s32 var_r31_107;
    u16 temp_r28_97;
    u16 temp_r30_102;
    u32 temp_r3_143;
    void *temp_r3_136;

    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(0U, GX_ALWAYS, 0U);
    GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_OR, GX_ALWAYS, 0U);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXLoadTexObj(arg0, GX_TEXMAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
    GXSetNumTevStages(1U);
    GXSetNumTexGens(1U);
    GXSetNumIndStages(0U);
    temp_r28_97 = GXGetTexObjWidth(arg0);
    temp_r30_102 = GXGetTexObjHeight(arg0);
    var_r27_105 = 0;
    var_r31_107 = 0;
    temp_f23_117 = arg2.unk8;
    temp_f26_119 = 1.0f / (f32) temp_r30_102;
    do {
        if (var_r27_105 == 0) {
            GXSetBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ZERO, GX_LO_NOOP);
        } else {
            GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_NOOP);
        }
        temp_r3_136 = arg1 + var_r31_107;
        temp_f25_140 = (1.0f / (f32) temp_r28_97) * M2C_FIELD(temp_r3_136, f32 *, 0);
        temp_f24_141 = temp_f26_119 * M2C_FIELD(temp_r3_136, f32 *, 4);
        temp_r3_143 = (u32) (255.0f * M2C_FIELD(temp_r3_136, f32 *, 8));
        sp10 = 0.0f;
        sp20 = 0.0f;
        sp40 = 0.0f;
        sp38 = (f32) temp_r28_97;
        sp3C = (f32) temp_r30_102;
        sp8 = 1.0f + temp_f25_140;
        spC = 1.0f + temp_f24_141;
        sp18 = temp_f25_140;
        sp1C = temp_f24_141;
        sp68 = (f64) sp38;
        sp48 = (f64) sp8;
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        sp70 = (f64) sp40;
        temp_f0_178 = M2C_FIELD(&arg2, f64 *, 0) + sp68;
        sp28 = temp_f0_178;
        sp78 = temp_f0_178;
        sp30 = temp_f23_117 + (f32) sp70;
        sp80 = (f64) sp30;
        DrawQuad(arg2, *((MKVector3 *) &sp78), *((MKVector3 *) &sp58), *((MKVector3 *) &sp48), temp_r3_143 | ((temp_r3_143 << 8) | ((temp_r3_143 << 0x18) | (temp_r3_143 << 0x10))));
        var_r27_105 += 1;
        var_r31_107 += 0x10;
    } while (var_r27_105 < 4);
}

void DrawQuad(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, unsigned int arg4) {
    f32 temp_f1_256;
    f32 temp_f2_254;
    f32 temp_f3_249;
    f32 temp_f4_245;
    f32 temp_f5_247;
    f32 temp_f6_252;
    f32 temp_f7_258;
    f32 temp_f8_260;

    MK_SetVDMode((MK_VertexDescriptorMode) 0);
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, 4U);
    temp_f4_245 = arg0.unk0;
    temp_f5_247 = arg0.unk4;
    *(f32 *)0xCC008000 = temp_f4_245;
    temp_f3_249 = arg2.unk0;
    *(f32 *)0xCC008000 = temp_f5_247;
    temp_f6_252 = arg2.unk4;
    *(f32 *)0xCC008000 = 0.0f;
    temp_f2_254 = arg1.unk0;
    *(f32 *)0xCC008000 = M2C_BITWISE(f32, arg4);
    temp_f1_256 = arg3.unk0;
    *(f32 *)0xCC008000 = temp_f3_249;
    temp_f7_258 = arg1.unk4;
    *(f32 *)0xCC008000 = temp_f6_252;
    temp_f8_260 = arg3.unk4;
    *(f32 *)0xCC008000 = temp_f2_254;
    *(f32 *)0xCC008000 = temp_f5_247;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = M2C_BITWISE(f32, arg4);
    *(f32 *)0xCC008000 = temp_f1_256;
    *(f32 *)0xCC008000 = temp_f6_252;
    *(f32 *)0xCC008000 = temp_f4_245;
    *(f32 *)0xCC008000 = temp_f7_258;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = M2C_BITWISE(f32, arg4);
    *(f32 *)0xCC008000 = temp_f3_249;
    *(f32 *)0xCC008000 = temp_f8_260;
    *(f32 *)0xCC008000 = temp_f2_254;
    *(f32 *)0xCC008000 = temp_f7_258;
    *(f32 *)0xCC008000 = 0.0f;
    *(f32 *)0xCC008000 = M2C_BITWISE(f32, arg4);
    *(f32 *)0xCC008000 = temp_f1_256;
    *(f32 *)0xCC008000 = temp_f8_260;
}

#if 0 // DRAFT: undefined identifier 'sp658'
void MKMat_MK2_ApplyGlow(float arg0, MKMat_Glow_Viewport arg1) {
    s32 sp73C;
    s32 sp738;
    s32 sp734;
    s32 sp730;
    MKVector3 sp6D8;
    M2C_UNK sp6D4;
    MKVector3 sp698;
    M2C_UNK sp694;
    f32 sp640;
    _GXTexObj sp620;
    _GXTexObj sp600;
    _GXTexObj sp5E0;
    _GXTexObj sp5C0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    f64 sp588;
    f64 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    f64 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    u8 sp4A;
    u16 sp48;
    s32 sp44;
    u32 sp40;
    u32 sp3C;
    u32 sp38;
    u32 sp34;
    s32 sp30;
    s32 sp2C;                                       /* compiler-managed */
    s32 sp28;
    s32 sp24;
    s32 sp20;
    GXRenderModeObj *temp_r28_313;
    enum _GXTevScale var_r26_551;
    f32 temp_f3_543;
    s32 temp_r5_1040;
    s8 temp_r5_547;
    s8 var_r6_555;
    u32 temp_r3_1394;

    if ((u8) bGlowEnabled != 0) {
        sp44 = M2C_FIELD(&lit_636, s32 *, 0);
        sp48 = M2C_FIELD(&lit_636, u16 *, 4);
        sp4A = M2C_FIELD(&lit_636, u8 *, 6);
        temp_r28_313 = GPGetRenderModeObj();
        GXGetViewportv(&sp640);
        GXGetScissor(&sp40, &sp3C, &sp38, &sp34);
        M2C_STRUCT_COPY((s32) &sp6D4 + 4, (s32) (&lit_637 - 4) + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp694 + 4, (s32) (&lit_638 - 4) + 4, 0x40);
        GXInitTexObj(&sp620, &MKMat_MK2_Standard_CaptureTextureData, 0x140U, 0xC8U, GX_TF_RGBA8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObj(&sp600, &MKMat_MK2_Standard_CaptureTextureData, M2C_FIELD(&filterTextureSizes, u16 *, 0), M2C_FIELD(&filterTextureSizes, u16 *, 2), GX_TF_RGBA8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObj(&sp5E0, &MKMat_MK2_Standard_CaptureTextureData, M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6), GX_TF_RGBA8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObj(&sp5C0, &MKMat_MK2_Standard_CaptureTextureData, M2C_FIELD(&filterTextureSizes, u16 *, 8), M2C_FIELD(&filterTextureSizes, u16 *, 0xA), GX_TF_RGBA8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObjLOD(&sp620, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        GXInitTexObjLOD(&sp600, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        GXInitTexObjLOD(&sp5E0, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        GXInitTexObjLOD(&sp5C0, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        MKView_Push();
        C_MTXOrtho((f32 (*)[4]) &sp658[0], 0.0f, (f32) (u16) (s32) 128.0f, 0.0f, (f32) (u16) (s32) 640.0f, 0.0f, 1.0f);
        GXSetCurrentMtx(3U);
        GXSetProjection((f32 (*)[4]) &sp658[0], GX_ORTHOGRAPHIC);
        MKMaterial_SetMaterial(NULL);
        GXSetDither(0U);
        GXSetCopyFilter(0U, (u8 (*)[2]) temp_r28_313->sample_pattern[0], 0U, (u8 *) &sp44);
        GXSetViewport(0.0f, 400.0f, 640.0f, 128.0f, 0.0f, 1.0f);
        GXSetScissor(0U, 0x190U, (u32) 640.0f, (u32) 128.0f);
        GXSetChanCtrl(GX_COLOR0A0, 0U, GX_SRC_REG, GX_SRC_VTX, 0U, GX_DF_CLAMP, GX_AF_SPOT);
        sp30 = 0;
        sp28 = 0;
        GXSetChanAmbColor(GX_COLOR0A0, (GXColor) &sp28);
        GXSetTexCopySrc(0U, 0U, 0x280U, 0x190U);
        GXSetTexCopyDst(0x140U, 0xC8U, GX_TF_RGBA8, 1U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
        GXSetCullMode(GX_CULL_NONE);
        GXSetZMode(0U, GX_ALWAYS, 0U);
        GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_OR, GX_ALWAYS, 0U);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ZERO, GX_LO_NOOP);
        temp_f3_543 = 1.0f - arg0;
        temp_r5_547 = (s8) (255.0f * arg0);
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
        if (temp_f3_543 == 0.5f) {
            var_r26_551 = GX_CS_SCALE_2;
            var_r6_555 = (s8) (255.0f * (0.5f / temp_f3_543));
        } else {
            var_r26_551 = GX_CS_SCALE_4;
            var_r6_555 = (s8) (255.0f * (0.25f / temp_f3_543));
        }
        sp2C = lit_643;
        sp2C = temp_r5_547;
        (*(u8 *) ((u8 *) &sp28 + 0x5)) = temp_r5_547;
        (*(u8 *) ((u8 *) &sp28 + 0x6)) = temp_r5_547;
        (*(u8 *) ((u8 *) &sp28 + 0x7)) = var_r6_555;
        sp24 = (s32) sp2C;
        GXSetTevColor(GX_TEVREG1, (GXColor) &sp24);
        sp20 = lit_645;
        GXSetTevColor(GX_TEVREG2, (GXColor) &sp20);
        GXLoadTexObj(&sp620, GX_TEXMAP0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_A1, GX_CC_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, var_r26_551, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_A2, GX_CA_TEXA, GX_CA_ONE, GX_CA_ZERO);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_COMP_A8_EQ, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetNumTevStages(2U);
        GXSetNumTexGens(1U);
        GXSetNumIndStages(0U);
        switch ((s32) arg1) {                       /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            sp2E8 = 0.0f;
            sp2F8 = 0.0f;
            sp2E0 = 1.0f;
            sp2E4 = 0.52f;
            sp2F0 = 320.0f;
            sp2F4 = 104.0f;
            sp590 = (f64) sp2E0;
            sp598 = (f64) sp2E8;
            sp5A0 = (f64) sp2F0;
            sp5A8 = (f64) sp2F8;
            DrawQuad(MKVector3::zero, *((MKVector3 *) &sp5A0), MKVector3::zero, *((MKVector3 *) &sp590), -1U);
            sp2A8 = 0.0f;
            sp2B8 = 0.0f;
            sp2C8 = 0.0f;
            sp2D8 = 0.0f;
            sp2A0 = 1.0f;
            sp2A4 = 1.0f;
            sp2B0 = 0.0f;
            sp2B4 = 0.52f;
            sp2C0 = 640.0f;
            sp2C4 = 96.0f;
            sp2D0 = 320.0f;
            sp2D4 = 0.0f;
            sp550 = (f64) sp2A0;
            sp558 = (f64) sp2A8;
            sp560 = (f64) sp2B0;
            sp568 = (f64) sp2B8;
            sp570 = (f64) sp2C0;
            sp578 = (f64) sp2C8;
            sp580 = (f64) sp2D0;
            sp588 = (f64) sp2D8;
            DrawQuad(*((MKVector3 *) &sp580), *((MKVector3 *) &sp570), *((MKVector3 *) &sp560), *((MKVector3 *) &sp550), -1U);
            break;
        case 1:                                     /* switch 1 */
            sp288 = 0.0f;
            sp298 = 0.0f;
            sp280 = 1.0f;
            sp284 = 0.5f;
            sp290 = 320.0f;
            sp294 = 100.0f;
            sp530 = (f64) sp280;
            sp538 = (f64) sp288;
            sp540 = (f64) sp290;
            sp548 = (f64) sp298;
            DrawQuad(MKVector3::zero, *((MKVector3 *) &sp540), MKVector3::zero, *((MKVector3 *) &sp530), -1U);
            sp248 = 0.0f;
            sp258 = 0.0f;
            sp268 = 0.0f;
            sp278 = 0.0f;
            sp240 = 1.0f;
            sp244 = 0.5f;
            sp250 = 0.0f;
            sp254 = 0.5f;
            sp260 = 320.0f;
            sp264 = 104.0f;
            sp270 = 0.0f;
            sp274 = 100.0f;
            sp4F0 = (f64) sp240;
            sp4F8 = (f64) sp248;
            sp500 = (f64) sp250;
            sp508 = (f64) sp258;
            sp510 = (f64) sp260;
            sp518 = (f64) sp268;
            sp520 = (f64) sp270;
            sp528 = (f64) sp278;
            DrawQuad(*((MKVector3 *) &sp520), *((MKVector3 *) &sp510), *((MKVector3 *) &sp500), *((MKVector3 *) &sp4F0), -1U);
            sp208 = 0.0f;
            sp218 = 0.0f;
            sp228 = 0.0f;
            sp238 = 0.0f;
            sp200 = 1.0f;
            sp204 = 0.5f;
            sp210 = 0.0f;
            sp214 = 0.5f;
            sp220 = 640.0f;
            sp224 = 96.0f;
            sp230 = 320.0f;
            sp234 = 0.0f;
            sp4B0 = (f64) sp200;
            sp4B8 = (f64) sp208;
            sp4C0 = (f64) sp210;
            sp4C8 = (f64) sp218;
            sp4D0 = (f64) sp220;
            sp4D8 = (f64) sp228;
            sp4E0 = (f64) sp230;
            sp4E8 = (f64) sp238;
            DrawQuad(*((MKVector3 *) &sp4E0), *((MKVector3 *) &sp4D0), *((MKVector3 *) &sp4C0), *((MKVector3 *) &sp4B0), -1U);
            break;
        case 2:                                     /* switch 1 */
            sp1D8 = 0.0f;
            sp1E8 = 0.0f;
            sp1F8 = 0.0f;
            sp1D0 = 1.0f;
            sp1D4 = 0.5f;
            sp1E0 = 0.0f;
            sp1E4 = 0.5f;
            sp1F0 = 320.0f;
            sp1F4 = 100.0f;
            sp480 = (f64) sp1D0;
            sp488 = (f64) sp1D8;
            sp490 = (f64) sp1E0;
            sp498 = (f64) sp1E8;
            sp4A0 = (f64) sp1F0;
            sp4A8 = (f64) sp1F8;
            DrawQuad(MKVector3::zero, *((MKVector3 *) &sp4A0), *((MKVector3 *) &sp490), *((MKVector3 *) &sp480), -1U);
            sp198 = 0.0f;
            sp1A8 = 0.0f;
            sp1B8 = 0.0f;
            sp1C8 = 0.0f;
            sp190 = 1.0f;
            sp194 = 0.52f;
            sp1A0 = 0.0f;
            sp1A4 = 0.5f;
            sp1B0 = 320.0f;
            sp1B4 = 104.0f;
            sp1C0 = 0.0f;
            sp1C4 = 100.0f;
            sp440 = (f64) sp190;
            sp448 = (f64) sp198;
            sp450 = (f64) sp1A0;
            sp458 = (f64) sp1A8;
            sp460 = (f64) sp1B0;
            sp468 = (f64) sp1B8;
            sp470 = (f64) sp1C0;
            sp478 = (f64) sp1C8;
            DrawQuad(*((MKVector3 *) &sp470), *((MKVector3 *) &sp460), *((MKVector3 *) &sp450), *((MKVector3 *) &sp440), -1U);
            sp158 = 0.0f;
            sp168 = 0.0f;
            sp178 = 0.0f;
            sp188 = 0.0f;
            sp150 = 1.0f;
            sp154 = 1.0f;
            sp160 = 0.0f;
            sp164 = 0.52f;
            sp170 = 640.0f;
            sp174 = 96.0f;
            sp180 = 320.0f;
            sp184 = 0.0f;
            sp400 = (f64) sp150;
            sp408 = (f64) sp158;
            sp410 = (f64) sp160;
            sp418 = (f64) sp168;
            sp420 = (f64) sp170;
            sp428 = (f64) sp178;
            sp430 = (f64) sp180;
            sp438 = (f64) sp188;
            DrawQuad(*((MKVector3 *) &sp430), *((MKVector3 *) &sp420), *((MKVector3 *) &sp410), *((MKVector3 *) &sp400), -1U);
            break;
        }
        GXSetTexCopySrc(0U, 0x190U, 0x140U, 0x68U);
        GXSetTexCopyDst(0xA0U, 0x34U, GX_TF_RGBA8, 1U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXSetTexCopySrc(0x140U, 0x190U, 0x140U, 0x60U);
        GXSetTexCopyDst(0xA0U, 0x30U, GX_TF_RGBA8, 1U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData + 0x8200, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        sp148 = 0.0f;
        sp73C = (s32) M2C_FIELD(&filterTextureSizes, u16 *, 0);
        sp738 = 0x43300000;
        sp144 = 0.0f;
        sp3F8 = (f64) sp148;
        sp140 = (f32) M2C_FIELD(&filterTextureSizes, u16 *, 0);
        sp3F0 = (f64) sp140;
        DrawFilteredQuad(&sp600, &sp6D8, *((MKVector3 *) &sp3F0));
        GXSetTexCopySrc(M2C_FIELD(&filterTextureSizes, u16 *, 0), 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 0), M2C_FIELD(&filterTextureSizes, u16 *, 2));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 0), M2C_FIELD(&filterTextureSizes, u16 *, 2), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        sp138 = 0.0f;
        temp_r5_1040 = M2C_FIELD(&filterTextureSizes, u16 *, 0) * 2;
        sp734 = temp_r5_1040 ^ 0x80000000;
        sp730 = 0x43300000;
        sp134 = 0.0f;
        sp3E8 = (f64) sp138;
        sp130 = (f32) temp_r5_1040;
        sp3E0 = (f64) sp130;
        DrawFilteredQuad(&sp600, &sp698, *((MKVector3 *) &sp3E0));
        GXSetTexCopySrc((M2C_FIELD(&filterTextureSizes, u16 *, 0) * 2) & 0xFFFE, 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 0), M2C_FIELD(&filterTextureSizes, u16 *, 2));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 0), M2C_FIELD(&filterTextureSizes, u16 *, 2), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        GXSetCullMode(GX_CULL_NONE);
        GXSetZMode(0U, GX_ALWAYS, 0U);
        GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_OR, GX_ALWAYS, 0U);
        GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_NOOP);
        GXLoadTexObj(&sp600, GX_TEXMAP0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetNumTevStages(1U);
        GXSetNumTexGens(1U);
        GXSetNumIndStages(0U);
        sp128 = 0.0f;
        sp120 = (f32) M2C_FIELD(&filterTextureSizes, u16 *, 4);
        sp124 = (f32) M2C_FIELD(&filterTextureSizes, u16 *, 6);
        sp3D8 = (f64) sp128;
        sp3D0 = (f64) sp120;
        DrawQuad(MKVector3::zero, *((MKVector3 *) &sp3D0), MKVector3::zero, MKVector3::one, -1U);
        GXSetTexCopySrc(0U, 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        sp118 = 0.0f;
        sp114 = 0.0f;
        sp110 = (f32) M2C_FIELD(&filterTextureSizes, u16 *, 4);
        sp3C8 = (f64) sp118;
        sp3C0 = (f64) sp110;
        DrawFilteredQuad(&sp5E0, &sp6D8, *((MKVector3 *) &sp3C0));
        GXSetTexCopySrc(M2C_FIELD(&filterTextureSizes, u16 *, 4), 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        sp108 = 0.0f;
        sp104 = 0.0f;
        sp100 = (f32) (M2C_FIELD(&filterTextureSizes, u16 *, 4) * 2);
        sp3B8 = (f64) sp108;
        sp3B0 = (f64) sp100;
        DrawFilteredQuad(&sp5E0, &sp698, *((MKVector3 *) &sp3B0));
        GXSetTexCopySrc((M2C_FIELD(&filterTextureSizes, u16 *, 4) * 2) & 0xFFFE, 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 8), M2C_FIELD(&filterTextureSizes, u16 *, 0xA), GX_TF_RGBA8, 1U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        spF8 = 0.0f;
        spF4 = 0.0f;
        spF0 = (f32) M2C_FIELD(&filterTextureSizes, u16 *, 8);
        sp3A8 = (f64) spF8;
        sp3A0 = (f64) spF0;
        DrawFilteredQuad(&sp5C0, &sp6D8, *((MKVector3 *) &sp3A0));
        GXSetTexCopySrc(M2C_FIELD(&filterTextureSizes, u16 *, 8), 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 8), M2C_FIELD(&filterTextureSizes, u16 *, 0xA));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 8), M2C_FIELD(&filterTextureSizes, u16 *, 0xA), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        spE8 = 0.0f;
        spE4 = 0.0f;
        spE0 = (f32) (M2C_FIELD(&filterTextureSizes, u16 *, 8) * 2);
        sp398 = (f64) spE8;
        sp390 = (f64) spE0;
        DrawFilteredQuad(&sp5C0, &sp698, *((MKVector3 *) &sp390));
        GXSetTexCopySrc((M2C_FIELD(&filterTextureSizes, u16 *, 8) * 2) & 0xFFFE, 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 8), M2C_FIELD(&filterTextureSizes, u16 *, 0xA));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 8), M2C_FIELD(&filterTextureSizes, u16 *, 0xA), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        GXSetCullMode(GX_CULL_NONE);
        GXSetZMode(0U, GX_ALWAYS, 0U);
        GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_OR, GX_ALWAYS, 0U);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_SRCALPHA, GX_LO_NOOP);
        GXLoadTexObj(&sp5C0, GX_TEXMAP0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetNumTevStages(1U);
        GXSetNumTexGens(1U);
        GXSetNumIndStages(0U);
        temp_r3_1394 = (u32) (255.0f * weight64);
        spC8 = 0.0f;
        spD8 = 0.0f;
        spC0 = (f32) (M2C_FIELD(&filterTextureSizes, u16 *, 4) * 3);
        spC4 = (f32) M2C_FIELD(&filterTextureSizes, u16 *, 6);
        spD0 = (f32) (M2C_FIELD(&filterTextureSizes, u16 *, 4) * 2);
        spD4 = 0.0f;
        sp370 = (f64) spC0;
        sp378 = (f64) spC8;
        sp380 = (f64) spD0;
        sp388 = (f64) spD8;
        DrawQuad(*((MKVector3 *) &sp380), *((MKVector3 *) &sp370), MKVector3::zero, MKVector3::one, (u32) (255.0f * weight128) | ((temp_r3_1394 << 8) | ((temp_r3_1394 << 0x18) | (temp_r3_1394 << 0x10))));
        GXSetTexCopySrc((M2C_FIELD(&filterTextureSizes, u16 *, 4) * 2) & 0xFFFE, 0x190U, M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6));
        GXSetTexCopyDst(M2C_FIELD(&filterTextureSizes, u16 *, 4), M2C_FIELD(&filterTextureSizes, u16 *, 6), GX_TF_RGBA8, 0U);
        GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, 0U);
        GXPixModeSync();
        GXInvalidateTexAll();
        GXSetPixelFmt(GX_PF_RGBA6_Z24, GX_ZC_LINEAR);
        GXSetDither(1U);
        GXSetCopyFilter(temp_r28_313->aa, (u8 (*)[2]) temp_r28_313->sample_pattern[0], 1U, temp_r28_313->vfilter);
        GXSetViewport(0.0f, 0.0f, 640.0f, 400.0f, 0.0f, 1.0f);
        GXSetScissor(0U, 0U, 0x280U, 0x190U);
        if ((u8) bDebug != 0) {
            GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_NOOP);
            GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        } else {
            GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_NOOP);
            GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, 1U, GX_TEVPREV);
        }
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXLoadTexObj(&sp5E0, GX_TEXMAP0);
        C_MTXOrtho((f32 (*)[4]) &sp658[0], 0.0f, 400.0f, 0.0f, 640.0f, 0.0f, 1.0f);
        GXSetProjection((f32 (*)[4]) &sp658[0], GX_ORTHOGRAPHIC);
        switch ((s32) arg1) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            spB0 = 640.0f;
            spB4 = 400.0f;
            spB8 = 0.0f;
            sp360 = (f64) spB0;
            sp368 = (f64) spB8;
            DrawQuad(MKVector3::zero, *((MKVector3 *) &sp360), MKVector3::zero, MKVector3::one, 0xFF00FF00U);
            break;
        case 1:                                     /* switch 2 */
            sp98 = 0.0f;
            spA8 = 0.0f;
            sp90 = 1.0f;
            sp94 = 0.5f;
            spA0 = 640.0f;
            spA4 = 200.0f;
            sp340 = (f64) sp90;
            sp348 = (f64) sp98;
            sp350 = (f64) spA0;
            sp358 = (f64) spA8;
            DrawQuad(MKVector3::zero, *((MKVector3 *) &sp350), MKVector3::zero, *((MKVector3 *) &sp340), 0xFF00FF00U);
            break;
        case 2:                                     /* switch 2 */
            sp58 = 0.0f;
            sp68 = 0.0f;
            sp78 = 0.0f;
            sp88 = 0.0f;
            sp50 = 1.0f;
            sp54 = 1.0f;
            sp60 = 0.0f;
            sp64 = 0.5f;
            sp70 = 640.0f;
            sp74 = 400.0f;
            sp80 = 0.0f;
            sp84 = 200.0f;
            sp300 = (f64) sp50;
            sp308 = (f64) sp58;
            sp310 = (f64) sp60;
            sp318 = (f64) sp68;
            sp320 = (f64) sp70;
            sp328 = (f64) sp78;
            sp330 = (f64) sp80;
            sp338 = (f64) sp88;
            DrawQuad(*((MKVector3 *) &sp330), *((MKVector3 *) &sp320), *((MKVector3 *) &sp310), *((MKVector3 *) &sp300), 0xFF00FF00U);
            break;
        }
        GXSetViewport(sp640, sp644, sp648, sp64C, sp650, sp654);
        GXSetScissor(sp40, sp3C, sp38, sp34);
        GXSetCurrentMtx(0U);
        MKMaterial_SetMaterial(NULL);
        MKView_Pop();
    }
}
#endif

void MKMat_MK2_Standard_DEREGISTER() {

}

void MKMat_MK2_Standard_REGISTER(void *arg0) {

}

#if 0 // DRAFT: illegal operand
void MKMat_MK2_Standard::UsePass() {
    Matrix spD0;
    Matrix sp90;
    f32 sp88;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp58;
    f32 sp50;
    M2C_UNK sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp14;
    s32 sp10;
    Texture *temp_r31_1783;
    _GXTexObj *temp_r30_1786;
    enum _GXBlendFactor var_r4_2101;
    enum _GXCompare var_r4_2140;
    s32 temp_r0_1724;
    s32 temp_r0_1936;
    s32 temp_r0_2091;
    s32 temp_r3_1831;
    u8 temp_r0_1805;
    u8 temp_r31_2132;
    u8 var_r0_1830;
    u8 var_r30_2131;
    u8 var_r3_2148;
    void *temp_r30_2031;
    void *temp_r3_2090;
    void *temp_r4_1712;
    void *temp_r4_1782;
    void *temp_r4_2124;
    void *temp_r4_2147;
    void *temp_r5_1935;

    if ((s8) init_569 == 0) {
        fogSetToBlack_568 = 0;
        init_569 = 1;
    }
    temp_r4_1712 = M2C_FIELD(this, void **, 0x24);
    sp28 = lit_572;
    M2C_FIELD(&gCurrentMaterialColorGC, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1712, f64 *, 0x30);
    M2C_FIELD(&gCurrentMaterialColorGC, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1712, f64 *, 0x38);
    MKMaterial_NumTevStages = 1;
    MKMaterial_NumTexGens = 1;
    temp_r0_1724 = M2C_FIELD(M2C_FIELD(this, void **, 0x24), s32 *, 0x24);
    if ((temp_r0_1724 == 1) || (temp_r0_1724 == 2)) {
        if ((u8) MKMaterial_bFogEnabled != 0) {
            M2C_FIELD(&oldFog_571, u8 *, 0) = (u8) M2C_FIELD(&MKMaterial_fogColor, s32 *, 0);
            M2C_FIELD(&oldFog_571, u8 *, 1) = (u8) M2C_FIELD(&MKMaterial_fogColor, u8 *, 1);
            M2C_FIELD(&oldFog_571, u8 *, 2) = (u8) M2C_FIELD(&MKMaterial_fogColor, u8 *, 2);
            M2C_FIELD(&oldFog_571, u8 *, 3) = (u8) M2C_FIELD(&MKMaterial_fogColor, u8 *, 3);
            MKView_GetProjection(NULL, &sp24, &sp20);
            sp14 = sp28;
            GXSetFog(GX_FOG_LIN, MKMaterial_fogNear, MKMaterial_fogFar, sp24, sp20, (GXColor) &sp14);
            fogSetToBlack_568 = 1;
        }
    } else if (((u8) fogSetToBlack_568 != 0) && ((u8) MKMaterial_bFogEnabled != 0)) {
        fogSetToBlack_568 = 0;
        MKView_GetProjection(NULL, &sp1C, &sp18);
        sp10 = M2C_FIELD(&MKMaterial_fogColor, s32 *, 0);
        GXSetFog(GX_FOG_LIN, MKMaterial_fogNear, MKMaterial_fogFar, sp1C, sp18, (GXColor) &sp10);
    }
    temp_r4_1782 = M2C_FIELD(this, void **, 0x24);
    temp_r31_1783 = M2C_FIELD(this, Texture **, 0x38);
    temp_r30_1786 = temp_r31_1783 + 0x60;
    GXInitTexObjWrapMode(temp_r30_1786, (s8) M2C_FIELD(temp_r4_1782, u8 *, 0xE2) == 0, (s8) M2C_FIELD(temp_r4_1782, u8 *, 0xE3) == 0);
    GXInitTexObjFilter(temp_r30_1786, GX_LIN_MIP_LIN, GX_LINEAR);
    if ((u8) temp_r31_1783->unk30 != 0) {
        GXPixModeSync();
    }
    temp_r0_1805 = M2C_FIELD(M2C_FIELD(this, void **, 0x24), u8 *, 0xE0);
    switch ((s8) temp_r0_1805) {                    /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        GXSetCullMode(GX_CULL_NONE);
        break;
    case 1:                                         /* switch 1 */
        GXSetCullMode(GX_CULL_BACK);
        break;
    case 2:                                         /* switch 1 */
        GXSetCullMode(GX_CULL_FRONT);
        break;
    }
    var_r0_1830 = 0;
    temp_r3_1831 = M2C_FIELD(M2C_FIELD(this, void **, 0x24), s32 *, 0x24);
    if ((temp_r3_1831 == 1) || (temp_r3_1831 == 2)) {
        var_r0_1830 = 1;
    }
    EnableLights(var_r0_1830 == 0);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, 1U, GX_TEVPREV);
    if (stricmp(M2C_FIELD(this, Texture **, 0x38), "capture") != 0) {
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
    } else {
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
        GXInitTexObjWrapMode(temp_r30_1786, GX_CLAMP, GX_CLAMP);
    }
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, 1U, GX_TEVPREV);
    GXSetAlphaUpdate((s8) M2C_FIELD(M2C_FIELD(this, void **, 0x24), u8 *, 0x1DD) == 0);
    if ((s8) M2C_FIELD(M2C_FIELD(this, void **, 0x24), u8 *, 0x1DC) != 0) {
        GXSetDstAlpha(1U, 4U);
    } else {
        GXSetDstAlpha(1U, 0x3FU);
    }
    if ((u8) temp_r31_1783->unk32 != 0) {
        MPGStateChanges(temp_r31_1783);
    } else {
        M2C_STRUCT_COPY((s32) &sp90.unk3C + 4, (s32) (&lit_599 - 4) + 4, 0x40);
        temp_r5_1935 = M2C_FIELD(this, void **, 0x24);
        temp_r0_1936 = M2C_FIELD(temp_r5_1935, s32 *, 0x28);
        switch (temp_r0_1936) {                     /* switch 2; irregular */
        case 5:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
            sp90.Multiply(&spD0, ((u8 *) temp_r5_1935) + 0x40);
            sp90.Transpose(&sp90);
            GXLoadTexMtxImm((f32 (*)[4]) &sp90, 0x40U, GX_MTX3x4);
            if ((s32) M2C_FIELD(M2C_FIELD(this, void **, 0x24), s32 *, 0x28) == 5) {
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_POS, 6U, 1U, 0x40U);
            } else {
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_NRM, 6U, 1U, 0x40U);
            }
            temp_r31_1783->Use();
            break;
        case 4:                                     /* switch 2 */
            M2C_STRUCT_COPY((s32) &sp4C + 4, MKView_GetProjectionMatrix() - 4 + 4, 0x40);
            sp50 *= -0.5f;
            sp64 *= 0.5f;
            sp70 = 0.5f;
            sp74 = 0.5f;
            sp58 = sp5C;
            sp68 = sp6C;
            sp78 = sp7C;
            sp88 = sp8C;
            ((Matrix *) &sp50)->Transpose((Matrix *) &sp50);
            GXLoadTexMtxImm((f32 (*)[4]) &sp50, 0x40U, GX_MTX3x4);
            GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_POS, 0U, 0U, 0x40U);
            temp_r31_1783->Use();
            break;
        default:                                    /* switch 2 */
            temp_r30_2031 = ((u8 *) temp_r5_1935) + 0x40;
            if (memcmp(temp_r30_2031, &Matrix::identity, 0x40U) != 0) {
                M2C_STRUCT_COPY((s32) &sp28 + 4, (s32) (&lit_610 - 4) + 4, 0x20);
                sp2C = M2C_FIELD(temp_r5_1935, f32 *, 0x40);
                sp30 = M2C_FIELD(temp_r30_2031, f32 *, 0x10);
                sp34 = M2C_FIELD(temp_r30_2031, f32 *, 0x20);
                sp38 = M2C_FIELD(temp_r30_2031, f32 *, 0x30);
                sp3C = M2C_FIELD(temp_r30_2031, f32 *, 4);
                sp40 = M2C_FIELD(temp_r30_2031, f32 *, 0x14);
                sp44 = M2C_FIELD(temp_r30_2031, f32 *, 0x24);
                sp48 = M2C_FIELD(temp_r30_2031, f32 *, 0x34);
                GXLoadTexMtxImm((f32 (*)[4]) &sp2C, 0x1EU, GX_MTX2x4);
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x1EU, 0U, 0x7DU);
            } else {
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
            }
            temp_r31_1783->Use();
            break;
        }
        temp_r3_2090 = M2C_FIELD(this, void **, 0x24);
        temp_r0_2091 = M2C_FIELD(temp_r3_2090, s32 *, 0x24);
        switch (temp_r0_2091) {                     /* switch 3; irregular */
        case 1:                                     /* switch 3 */
            var_r4_2101 = GX_BL_SRCALPHA;
            if ((s8) M2C_FIELD(temp_r3_2090, u8 *, 0x1DC) != 0) {
                var_r4_2101 = GX_BL_ONE;
            }
            GXSetBlendMode(GX_BM_BLEND, var_r4_2101, GX_BL_ONE, GX_LO_NOOP);
            break;
        case 2:                                     /* switch 3 */
            GXSetBlendMode(GX_BM_SUBTRACT, GX_BL_ZERO, GX_BL_ZERO, GX_LO_NOOP);
            break;
        default:                                    /* switch 3 */
            GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
            break;
        }
        temp_r4_2124 = M2C_FIELD(this, void **, 0x24);
        var_r30_2131 = (s8) M2C_FIELD(temp_r4_2124, u8 *, 0xE4) == 0;
        temp_r31_2132 = (s8) M2C_FIELD(temp_r4_2124, u8 *, 0xE5) == 0;
        if (MKView_GetFlags() & 1) {
            var_r30_2131 = 1;
        }
        var_r4_2140 = GX_LEQUAL;
        if ((s32) temp_r31_2132 != 0) {
            var_r4_2140 = GX_ALWAYS;
        }
        GXSetZMode(1U, var_r4_2140, (u8) (var_r30_2131 == 0));
        temp_r4_2147 = M2C_FIELD(this, void **, 0x24);
        var_r3_2148 = 0;
        if (((s8) M2C_FIELD(temp_r4_2147, u8 *, 0xE6) != 0) || ((s32) M2C_FIELD(temp_r4_2147, s32 *, 0x24) != 0)) {
            var_r3_2148 = 1;
        }
        SetZCompLoc(var_r3_2148 == 0);
        GXSetAlphaCompare(GX_GREATER, (u8) (s32) (255.0f * (M2C_FIELD(M2C_FIELD(this, void **, 0x24), f32 *, 0x2C) * M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0xC))), GX_AOP_AND, GX_ALWAYS, 0xFFU);
    }
    GXSetNumTexGens(MKMaterial_NumTexGens);
    GXSetNumTevStages(MKMaterial_NumTevStages);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKMaterial *' to
s32 MKMat_MK2_Standard_BEGIN_INTERNAL() {
    MKMat_MK2_Standard *temp_r31_2199;

    temp_r31_2199 = gpCurrentMaterial;
    if ((s8) init_537 == 0) {
        pOverlay_536 = NULL;
        init_537 = 1;
    }
    if ((s8) init_540 == 0) {
        viewCounter_539 = 0;
        init_540 = 1;
    }
    if (((s32) currentInternalPass == 0) && (gpMKcurrentMaterialEffectorMask & 1)) {
        HandleOmniLights();
    }
    if ((s32) currentInternalPass == 0) {
        currentInternalPass += 1;
        if (((MKMat_MK2_Standard *) gpPreviousMaterial != (MKMat_MK2_Standard *) gpCurrentMaterial) || ((s32) viewCounter_539 != (s32) MKView_SettingsCounter)) {
            gpPreviousMaterial = gpCurrentMaterial;
            viewCounter_539 = MKView_SettingsCounter;
            temp_r31_2199->UsePass();
            pOverlay_536 = M2C_FIELD(temp_r31_2199, MKMaterial **, 0x3C);
        }
        return 1;
    }
loop_14:
    if (((MKMaterial *) pOverlay_536 != NULL) && (MKMaterial_GetParameter(pOverlay_536, (MKMaterialParameter) 6) != 0)) {
        pOverlay_536 = pOverlay_536->unk3C;
        goto loop_14;
    }
    if ((MKMaterial *) pOverlay_536 != NULL) {
        gpPreviousMaterial = (MKMat_MK2_Standard *) pOverlay_536;
        ((MKMat_MK2_Standard *) pOverlay_536)->UsePass();
        pOverlay_536 = pOverlay_536->unk3C;
        currentInternalPass += 1;
        return 1;
    }
    currentInternalPass = 0;
    return 0;
}
#endif

s32 MKMat_MK2_Standard_BEGIN(MKMaterial *arg0) {
    if ((s32) currentPass == 0) {
        currentPass = 1;
        return 1;
    }
    currentPass = 0;
    return 0;
}

#if 0 // DRAFT: illegal operand
void MPGStateChanges(Texture *arg0) {
    _GXTexObj sp60;
    _GXTexObj sp40;
    _GXTexObj sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    if (((void *) arg0->unk3C == NULL) || ((void *) arg0->unk40 == NULL) || ((void *) arg0->unk44 == NULL)) {
        MKMaterial_NumTexGens = 0;
        MKMaterial_NumTevStages = 1;
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ONE);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevKAlphaSel(GX_TEVSTAGE0, GX_TEV_KASEL_K0_A);
        sp14 = lit_503;
        GXSetTevKColor(GX_KCOLOR0, (GXColor) &sp14);
    } else {
        MKMaterial_NumTexGens = 2;
        MKMaterial_NumTevStages = 4;
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU, 0U, 0x7DU);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_QUARTER, GX_CC_C0);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 0U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_ONE, GX_CA_A0);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, 0U, GX_TEVPREV);
        GXSetTevKColorSel(GX_TEVSTAGE0, GX_TEV_KCSEL_K0);
        GXSetTevKAlphaSel(GX_TEVSTAGE0, GX_TEV_KASEL_K0_A);
        GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_QUARTER, GX_CC_CPREV);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, 0U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_ONE, GX_CA_APREV);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, 0U, GX_TEVPREV);
        GXSetTevKColorSel(GX_TEVSTAGE1, GX_TEV_KCSEL_K1);
        GXSetTevKAlphaSel(GX_TEVSTAGE1, GX_TEV_KASEL_K1_A);
        GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
        GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_TEXC, GX_CC_ONE, GX_CC_CPREV);
        GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
        GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_APREV, GX_CC_CPREV, GX_CC_QUARTER, GX_CC_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1U, GX_TEVPREV);
        GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);
        GXSetTevKColorSel(GX_TEVSTAGE3, GX_TEV_KCSEL_K2);
        sp18 = M2C_FIELD(&lit_507, s32 *, 0);
        sp1C = M2C_FIELD(&lit_507, s32 *, 4);
        GXSetTevColorS10(GX_TEVREG0, (GXColorS10) &sp18);
        sp10 = lit_510;
        GXSetTevKColor(GX_KCOLOR0, (GXColor) &sp10);
        spC = lit_513;
        GXSetTevKColor(GX_KCOLOR1, (GXColor) &spC);
        sp8 = lit_516;
        GXSetTevKColor(GX_KCOLOR2, (GXColor) &sp8);
        GXInitTexObj(&sp60, arg0->unk3C, (u16) arg0->unk24, (u16) arg0->unk28, GX_TF_I8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObjLOD(&sp60, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        GXLoadTexObj(&sp60, GX_TEXMAP0);
        GXInitTexObj(&sp40, arg0->unk40, (u16) ((s32) arg0->unk24 >> 1), (u16) ((s32) arg0->unk28 >> 1), GX_TF_I8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObjLOD(&sp40, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        GXLoadTexObj(&sp40, GX_TEXMAP1);
        GXInitTexObj(&sp20, arg0->unk44, (u16) ((s32) arg0->unk24 >> 1), (u16) ((s32) arg0->unk28 >> 1), GX_TF_I8, GX_CLAMP, GX_CLAMP, 0U);
        GXInitTexObjLOD(&sp20, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        GXLoadTexObj(&sp20, GX_TEXMAP2);
    }
    GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR);
    GXSetAlphaCompare(GX_ALWAYS, 0U, GX_AOP_OR, GX_ALWAYS, 0xFFU);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'OmniLight *' to
void HandleOmniLights() {
    OmniLight *sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector4 *temp_r4_2741;
    s32 temp_r29_2735;
    s32 var_r0_2749;
    s32 var_r28_2738;
    s32 var_r30_2734;
    void *temp_r3_2668;
    void *temp_r3_2680;
    void *temp_r4_2667;

    temp_r4_2667 = &MKMaterial_LocalityArray + (MKMaterial_CurrentLocalityIndex * 8);
    temp_r3_2668 = M2C_FIELD(temp_r4_2667, void **, 4);
    if (temp_r3_2668 != NULL) {
        temp_r3_2680 = M2C_FIELD(temp_r4_2667, void **, 0);
        sp18 = (0.5f * M2C_FIELD(temp_r3_2668, f32 *, 0x10)) + M2C_FIELD(temp_r3_2668, f32 *, 0);
        sp1C = (0.5f * M2C_FIELD(temp_r3_2668, f32 *, 0x14)) + M2C_FIELD(temp_r3_2668, f32 *, 4);
        sp20 = (0.5f * M2C_FIELD(temp_r3_2668, f32 *, 0x18)) + M2C_FIELD(temp_r3_2668, f32 *, 8);
        sp38 = (f64) sp18;
        sp40 = (f64) sp20;
        if (temp_r3_2680 != NULL) {
            sp8 = M2C_FIELD(temp_r3_2680, f32 *, 0x30) + (((f32) sp40 * M2C_FIELD(temp_r3_2680, f32 *, 0x20)) + (((f32) sp38 * M2C_FIELD(temp_r3_2680, f32 *, 0)) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * M2C_FIELD(temp_r3_2680, f32 *, 0x10))));
            spC = M2C_FIELD(temp_r3_2680, f32 *, 0x34) + (((f32) sp40 * M2C_FIELD(temp_r3_2680, f32 *, 0x24)) + (((f32) sp38 * M2C_FIELD(temp_r3_2680, f32 *, 4)) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * M2C_FIELD(temp_r3_2680, f32 *, 0x14))));
            sp10 = M2C_FIELD(temp_r3_2680, f32 *, 0x38) + (((f32) sp40 * M2C_FIELD(temp_r3_2680, f32 *, 0x28)) + (((f32) sp38 * M2C_FIELD(temp_r3_2680, f32 *, 8)) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * M2C_FIELD(temp_r3_2680, f32 *, 0x18))));
            sp28 = (f64) sp8;
            sp30 = (f64) sp10;
            sp38 = (f64) sp8;
            sp40 = (f64) sp10;
        }
        var_r30_2734 = 0;
        temp_r29_2735 = OmniLight_FindNearestGroup(*((MKVector3 *) &sp38), M2C_FIELD(M2C_FIELD(temp_r4_2667, void **, 4), f32 *, 0xC), &sp48, 4);
        MKLight_LightMask = 0;
        var_r28_2738 = 0;
loop_5:
        var_r0_2749 = lit_484;
        if (temp_r29_2735 < var_r0_2749) {
            var_r0_2749 = temp_r29_2735;
        }
        if (var_r28_2738 < var_r0_2749) {
            temp_r4_2741 = *(&sp48 + var_r30_2734);
            SetLight(*(temp_r4_2741 + 0x10), *temp_r4_2741, M2C_FIELD(temp_r4_2741, f32 *, 0x20), var_r28_2738);
            var_r28_2738 += 1;
            var_r30_2734 += 4;
            goto loop_5;
        }
    }
}
#endif

void EnableLights(bool arg0) {
    s32 temp_r0_2798;

    if ((s8) init_469 == 0) {
        oldLights_468 = 0xFF;
        init_469 = 1;
    }
    if ((s8) init_472 == 0) {
        bLightsAreEnabled_471 = 1;
        init_472 = 1;
    }
    if (((u8) MKLight_LightMask != (u8) oldLights_468) || ((u8) bLightsAreEnabled_471 != arg0)) {
        temp_r0_2798 = 0 - arg0;
        GXSetChanCtrl(GX_COLOR0, 1U, GX_SRC_VTX, GX_SRC_REG, (u32) (u8) (MKLight_LightMask & ((temp_r0_2798 - temp_r0_2798) - !M2C_CARRY)), GX_DF_CLAMP, GX_AF_SPOT);
        bLightsAreEnabled_471 = arg0;
        oldLights_468 = MKLight_LightMask;
    }
}

#if 0 // DRAFT: undefined identifier 'sp80'
void SetLight(const MKVector3 &arg0, const MKVector4 &arg1, float arg2, int arg3) {
    GXLightObj spA0;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    M2C_UNK sp4C;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;                                       /* compiler-managed */
    s32 sp20;
    f32 temp_f10_2853;
    f32 temp_f11_2857;
    f32 temp_f12_2865;
    f32 temp_f6_2851;
    f32 temp_f7_2862;
    f32 temp_f8_2860;
    f32 temp_f9_2850;
    f32 var_f0_2930;
    u8 temp_r0_2944;

    M2C_STRUCT_COPY((s32) &sp4C + 4, MKView_GetWorldToViewMatrix() - 4 + 4, 0x40);
    temp_f9_2850 = sp68 * -1.0f;
    temp_f6_2851 = arg0.unk4;
    temp_f10_2853 = sp58 * -1.0f;
    temp_f11_2857 = arg0.unk0;
    temp_f8_2860 = sp78 * -1.0f;
    temp_f7_2862 = sp88 * -1.0f;
    temp_f12_2865 = arg0.unk8;
    sp58 = temp_f10_2853;
    sp68 = temp_f9_2850;
    sp78 = temp_f8_2860;
    sp30 = temp_f7_2862 + ((temp_f12_2865 * temp_f8_2860) + ((temp_f11_2857 * temp_f10_2853) + (temp_f6_2851 * temp_f9_2850)));
    sp28 = sp80 + ((temp_f12_2865 * sp70) + ((temp_f11_2857 * sp50) + (temp_f6_2851 * sp60)));
    sp2C = sp84 + ((temp_f12_2865 * sp74) + ((temp_f11_2857 * sp54) + (temp_f6_2851 * sp64)));
    sp40 = (f64) sp30;
    sp38 = (f64) sp28;
    sp88 = temp_f7_2862;
    GXInitLightPos(&spA0, (f32) sp38, (*(f32 *) ((u8 *) &sp38 + 0x4)), (f32) sp40);
    sp24 = lit_457;
    sp24 = (s8) (255.0f * arg1.unk0);
    (*(u8 *) ((u8 *) &sp20 + 0x5)) = (s8) (255.0f * arg1.unk4);
    (*(u8 *) ((u8 *) &sp20 + 0x6)) = (s8) (255.0f * arg1.unk8);
    sp20 = (s32) sp24;
    GXInitLightColor(&spA0, (GXColor) &sp20);
    GXInitLightDir(&spA0, 0.0f, -1.0f, 0.0f);
    GXInitLightAttnA(&spA0, 1.0f, 0.0f, 0.0f);
    var_f0_2930 = 0.01f;
    if (arg2 > var_f0_2930) {
        var_f0_2930 = arg2;
    }
    GXInitLightAttnK(&spA0, 0.0f, 0.0f, omniFalloff / (var_f0_2930 * var_f0_2930));
    temp_r0_2944 = 1 << (arg3 + 3);
    MKLight_LightMask |= temp_r0_2944;
    GXLoadLightObjImm(&spA0, (enum _GXLightID) temp_r0_2944);
    GXFlush();
}
#endif

#if 0 // DRAFT: undefined identifier 'oldColor'
void MKMat_MK2_Standard_GC_cpp::__sinit() {
    M2C_FIELD(&oldColor, f64 *, 0) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 0);
    M2C_FIELD(&oldColor, f64 *, 8) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 8);
}
#endif

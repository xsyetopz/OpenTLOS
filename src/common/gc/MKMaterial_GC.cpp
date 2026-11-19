#include "common/gc/MKMaterial_GC.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/MKModel_GC.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "dolphin/os.h"
#include "common/Source/GPInit.h"
#include "common/Source/MKView.h"
#include <m2c_macros.h>

extern u8 MKLight_LightMask;
#if 0 // DRAFT: identifier 'MKMaterialGC_bForceSkinnedVertexFormat' redeclared
extern u8 MKMaterialGC_bForceSkinnedVertexFormat;
#endif
extern s32 MKMaterial_CurrentLocalityIndex;
#if 0 // DRAFT: identifier 'MKMaterial_LocalityArray' redeclared
extern M2C_UNK MKMaterial_LocalityArray;
#endif
extern u8 MKMaterial_bFogEnabled;
extern f32 MKMaterial_fogFar;
extern f32 MKMaterial_fogNear;
extern u8 MKPrimitive_bAlphaModulate;
#if 0 // DRAFT: identifier 'MKPrimitive_colorModulate' redeclared
extern M2C_UNK MKPrimitive_colorModulate;
#endif
extern s32 MKView_SettingsCounter;
extern s8 bLit;
extern s32 currentState_499;
extern u32 currentType;
extern M2C_UNK gMKDefaults;
extern MKMaterial *gpCurrentMaterial;
extern void *gpMKMaterialTypeInfoList;
extern MKMaterial *gpMKWhiteMaterial;
#if 0 // DRAFT: identifier 'gpPreviousMaterial' redeclared
extern s32 gpPreviousMaterial;
#endif
extern u8 init_468;
extern u8 init_476;
extern u8 init_500;
extern s32 oldCounter_467;
extern Matrix *pAnimMats;
extern Texture *pOldRenderTarget_475;
#if 0 // DRAFT: identifier 'MKMaterial_GeometryColor' redeclared
static M2C_UNK MKMaterial_GeometryColor;            /* unable to generate initializer: unknown type */
static M2C_UNK MKPrimitive_CurrentVertex;           /* unable to generate initializer: unknown type */
static s32 MKMaterial_fogColor = 0xFFFFFFFF;
#endif
static u32 currentPrim = 4;
static M2C_UNK MKPrimitive_BaseColor;               /* unable to generate initializer: unknown type */
static s32 TransformInfo = 1;

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char[4]' to
u8 MKMaterial_EnableFog(bool arg0) {
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    u8 temp_r31_19;

    temp_r31_19 = MKMaterial_bFogEnabled;
    MKMaterial_bFogEnabled = arg0;
    if (arg0 != 0) {
        MKView_GetProjection(NULL, &sp14, &sp10);
        spC = MKMaterial_fogColor;
        GXSetFog(GX_FOG_LIN, MKMaterial_fogNear, MKMaterial_fogFar, sp14, sp10, (GXColor) &spC);
    } else {
        sp8 = MKMaterial_fogColor;
        GXSetFog(GX_FOG_NONE, MKMaterial_fogNear, MKMaterial_fogFar, 0.0f, 0.0f, (GXColor) &sp8);
    }
    return temp_r31_19;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long *' to
void MKMaterial_SetFogColor(const MKVector4 &arg0) {
    s32 sp8;

    M2C_FIELD(&MKMaterial_fogColor, s8 *, 0) = (s8) (255.0f * arg0.unk0);
    M2C_FIELD(&MKMaterial_fogColor, s8 *, 1) = (s8) (255.0f * arg0.unk4);
    M2C_FIELD(&MKMaterial_fogColor, s8 *, 2) = (s8) (255.0f * arg0.unk8);
    sp8 = M2C_FIELD(&MKMaterial_fogColor, s32 *, 0);
    GXSetFogColor((GXColor) &sp8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char[4]' to
void MKMaterial_SetFogPlanes(float arg0, float arg1) {
    f32 sp10;
    f32 spC;
    s32 sp8;

    MKMaterial_fogNear = arg0;
    MKMaterial_fogFar = arg1;
    if ((u8) MKMaterial_bFogEnabled != 0) {
        MKView_GetProjection(NULL, &sp10, &spC);
        sp8 = MKMaterial_fogColor;
        GXSetFog(GX_FOG_LIN, MKMaterial_fogNear, MKMaterial_fogFar, sp10, spC, (GXColor) &sp8);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
f32 MKMaterial_SetVertex4F(int arg0, float arg1, float arg2, float arg3, float arg4) {
    f32 temp_f0_182;
    s32 temp_r3_169;
    s32 var_r3_0;
    s8 temp_r3_202;
    s8 temp_r3_235;

    var_r3_0 = arg0;
    if (var_r3_0 != 2) {
        if (var_r3_0 < 2) {
            if (var_r3_0 != 0) {
                if (var_r3_0 < 0) {
                    return M2C_BITWISE(f32, var_r3_0);
                }
                if ((u8) MKPrimitive_bAlphaModulate != 0) {
                    temp_f0_182 = 255.0f * arg4;
                    M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xF) = -1;
                    temp_r3_202 = (s8) (M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 4) * (arg2 * temp_f0_182));
                    M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xC) = (s8) (M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0) * (arg1 * temp_f0_182));
                    M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xD) = temp_r3_202;
                    M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xE) = (s8) (M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 8) * (arg3 * temp_f0_182));
                    return M2C_BITWISE(f32, temp_r3_202);
                }
                temp_r3_235 = (s8) (255.0f * (arg3 * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 8)));
                M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xC) = (s8) (255.0f * (arg1 * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0)));
                M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xD) = (s8) (255.0f * (arg2 * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 4)));
                M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xE) = temp_r3_235;
                M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xF) = (s8) (255.0f * (arg4 * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0xC)));
                return M2C_BITWISE(f32, temp_r3_235);
            }
            *(f32 *)0xCC008000 = arg1;
            *(f32 *)0xCC008000 = arg2;
            *(f32 *)0xCC008000 = arg3;
            *(0xCC010000 - 0x8000) = (f64) M2C_FIELD(&MKPrimitive_CurrentVertex, f64 *, 0);
            M2C_FIELD(((f32 *)0xCC010000 - 0x8000), f64 *, 4) = (f64) M2C_FIELD(&MKPrimitive_CurrentVertex, f32 *, 8);
            *(f32 *)0xCC008000 = (s8) ((s32) ((u8) M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xC) * M2C_FIELD(&MKPrimitive_BaseColor, u8 *, 0)) >> 7);
            *(f32 *)0xCC008000 = (s8) ((s32) ((u8) M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xD) * M2C_FIELD(&MKPrimitive_BaseColor, u8 *, 1)) >> 7);
            *(f32 *)0xCC008000 = (s8) ((s32) ((u8) M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xE) * M2C_FIELD(&MKPrimitive_BaseColor, u8 *, 2)) >> 7);
            temp_r3_169 = (s32) ((u8) M2C_FIELD(&MKPrimitive_CurrentVertex, s8 *, 0xF) * M2C_FIELD(&MKPrimitive_BaseColor, u8 *, 3)) >> 7;
            *(f32 *)0xCC008000 = (s8) temp_r3_169;
            *(0xCC010000 - 0x8000) = (f64) M2C_FIELD(&MKPrimitive_CurrentVertex, f64 *, 0x10);
            return M2C_BITWISE(f32, temp_r3_169);
        }
        if (var_r3_0 < 4) {
            var_r3_0 = (s32) &MKPrimitive_CurrentVertex;
            M2C_FIELD((s32) &MKPrimitive_CurrentVertex, f32 *, 0x10) = arg1;
            M2C_FIELD((s32) &MKPrimitive_CurrentVertex, f32 *, 0x14) = arg2;
        }
        return M2C_BITWISE(f32, var_r3_0);
    }
    M2C_FIELD(&MKPrimitive_CurrentVertex, f64 *, 0) = arg1;
    M2C_FIELD(&MKPrimitive_CurrentVertex, f32 *, 4) = arg2;
    M2C_FIELD(&MKPrimitive_CurrentVertex, f32 *, 8) = arg3;
    return M2C_BITWISE(f32, &MKPrimitive_CurrentVertex);
}
#endif

void MKMaterial_GetVertexComponentHandleFromType(VERTEX_COMPONENT arg0) {

}

void MKMaterial_UseLocality(int arg0) {
    MKMaterial_CurrentLocalityIndex = arg0;
}

#if 0 // DRAFT: illegal implicit conversion from 'const BoundingVolume *' to
void MKMaterial_SetLocalities(const Matrix *arg0, const BoundingVolume *arg1, int arg2, int arg3) {
    s32 temp_r5_285;
    s32 var_ctr_279;
    s32 var_r11_275;
    s32 var_r7_277;
    s32 var_r8_278;
    void *temp_r0_288;
    void *temp_r5_287;

    var_r11_275 = 0;
    var_r7_277 = 0;
    var_r8_278 = 0;
    var_ctr_279 = arg2;
    if (arg2 > 0) {
        do {
            temp_r5_285 = (arg3 + var_r11_275) * 8;
            var_r11_275 += 1;
            temp_r5_287 = &MKMaterial_LocalityArray + temp_r5_285;
            temp_r0_288 = arg1 + var_r7_277;
            M2C_FIELD(temp_r5_287, void **, 0) = (void *) (arg0 + var_r8_278);
            var_r7_277 += 0x20;
            var_r8_278 += 0x40;
            M2C_FIELD(temp_r5_287, void **, 4) = temp_r0_288;
            var_ctr_279 -= 1;
        } while (var_ctr_279 != 0);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char (*)[16]' to
void MKMaterial_RenderMeshChunk(MeshChunk *arg0) {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    MKVector4 *var_r4_305;
    f32 *temp_r29_395;
    s32 temp_r0_372;
    u8 var_r0_324;
    u8 var_r5_393;
    u8 var_r5_404;
    void *temp_r29_387;
    void *temp_r30_412;
    void *temp_r3_333;

    var_r4_305 = &MKVector4::one;
    if ((MKMaterial *) gpCurrentMaterial != NULL) {
        var_r4_305 = &MKMaterial_GeometryColor + 0x50;
    }
    sp10 = M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0) * M2C_FIELD(var_r4_305, f64 *, 0);
    sp18 = M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 8) * M2C_FIELD(var_r4_305, f64 *, 8);
    var_r0_324 = 0;
    sp20 = sp10;
    sp28 = sp18;
    if ((f32) sp20 == M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0x40)) {
        temp_r3_333 = &MKMaterial_GeometryColor + 0x40;
        if (((*(f32 *) ((u8 *) &sp20 + 0x4)) == M2C_FIELD(temp_r3_333, f32 *, 4)) && ((f32) sp28 == M2C_FIELD(temp_r3_333, f32 *, 8)) && ((*(f32 *) ((u8 *) &sp28 + 0x4)) == M2C_FIELD(temp_r3_333, f32 *, 0xC))) {
            var_r0_324 = 1;
        }
    }
    if (var_r0_324 == 0) {
        temp_r0_372 = ((u32) (128.0f * (f32) sp20) << 0x18) + (((u32) (128.0f * (*(f32 *) ((u8 *) &sp20 + 0x4))) << 0x10) + ((u32) (128.0f * (f32) sp28) << 8) + (u32) (128.0f * (*(f32 *) ((u8 *) &sp28 + 0x4))));
        sp8 = temp_r0_372;
        spC = temp_r0_372;
        GXSetChanMatColor(GX_COLOR0A0, (GXColor) &spC);
        M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0x40) = sp20;
        M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0x48) = sp28;
    }
    temp_r29_387 = arg0 + (arg0->unk10 + 0x20);
    GXSetArray(GX_VA_CLR0, temp_r29_387, 4U);
    var_r5_393 = 0;
    temp_r29_395 = ((u8 *) temp_r29_387) + arg0->unk14;
    if (((s32) TransformInfo == 1) && ((u8) MKMaterialGC_bForceSkinnedVertexFormat == 0)) {
        var_r5_393 = 1;
    }
    var_r5_404 = 0x14;
    if (var_r5_393 != 0) {
        var_r5_404 = 0xC;
    }
    GXSetArray(GX_VA_POS, temp_r29_395, var_r5_404);
    temp_r30_412 = temp_r29_395 + arg0->unk18;
    GXSetArray(GX_VA_TEX0, temp_r30_412, 4U);
    switch ((s32) TransformInfo) {                  /* irregular */
    case 1:
        MK_SetVDMode((MK_VertexDescriptorMode) 3);
        GXCallDisplayList(arg0 + 0x20, arg0->unk10);
        return;
    case 2:
        if (((u8) MKLight_LightMask == 0) && ((s32) M2C_FIELD(gpCurrentMaterial->unk24, s32 *, 0x28) == 3) && ((MKMaterial *) gpCurrentMaterial->unk3C == NULL)) {
            MK_SetVDMode((MK_VertexDescriptorMode) 5);
            Model_RenderChunkGC<0>((MeshChunkGC *) arg0, temp_r29_395, (u32) arg0->unk6, pAnimMats);
            return;
        }
        MK_SetVDMode((MK_VertexDescriptorMode) 4);
        Model_RenderChunkGC<1>((MeshChunkGC *) arg0, temp_r29_395, (u32) arg0->unk6, pAnimMats);
        return;
    case 3:
        MK_SetVDMode((MK_VertexDescriptorMode) 4);
        Model_DrawWeightedBlendShape((MeshChunkGC *) arg0, temp_r29_395, (u32) arg0->unk6, pAnimMats, ((u8 *) temp_r30_412) + arg0->unk1C);
        return;
    }
}
#endif

void MKMaterial_RenderVerticesEnd() {

}

void MKMaterial_RenderVerticesBegin(int arg0) {
    switch (currentPrim) {
    case 1:
        GXBegin(GX_LINES, GX_VTXFMT1, (u16) arg0);
        return;
    case 0:
        GXBegin(GX_POINTS, GX_VTXFMT1, (u16) arg0);
        return;
    case 3:
        GXBegin(GX_TRIANGLES, GX_VTXFMT1, (u16) arg0);
        return;
    case 4:
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT1, (u16) arg0);
        return;
    case 5:
        GXBegin(GX_TRIANGLEFAN, GX_VTXFMT1, (u16) arg0);
        return;
    case 6:
        GXBegin(GX_QUADS, GX_VTXFMT1, (u16) arg0);
        return;
    case 2:
        GXBegin(GX_LINESTRIP, GX_VTXFMT1, (u16) arg0);
        /* fallthrough */
    default:
        return;
    }
}

void MKMaterial_RenderImmediateEnd() {
    GXSetCullMode(GX_CULL_NONE);
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char (*)[16]' to
void MKMaterial_RenderImmediateBegin(unsigned int arg0, unsigned int arg1) {
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 spC;
    s32 sp8;
    MKVector4 *var_r5_966;
    s32 temp_r0_1034;
    s32 temp_r3_1072;
    u8 temp_r0_1144;
    u8 var_r0_986;
    void *temp_r3_995;
    void *temp_r4_1094;
    void *temp_r7_1055;
    void *temp_r8_1047;

    var_r5_966 = &MKVector4::one;
    if ((MKMaterial *) gpCurrentMaterial != NULL) {
        var_r5_966 = &MKMaterial_GeometryColor + 0x50;
    }
    sp20 = M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0) * M2C_FIELD(var_r5_966, f64 *, 0);
    sp28 = M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 8) * M2C_FIELD(var_r5_966, f64 *, 8);
    var_r0_986 = 0;
    sp30 = sp20;
    sp38 = sp28;
    if ((f32) sp30 == M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0x40)) {
        temp_r3_995 = &MKMaterial_GeometryColor + 0x40;
        if (((*(f32 *) ((u8 *) &sp30 + 0x4)) == M2C_FIELD(temp_r3_995, f32 *, 4)) && ((f32) sp38 == M2C_FIELD(temp_r3_995, f32 *, 8)) && ((*(f32 *) ((u8 *) &sp38 + 0x4)) == M2C_FIELD(temp_r3_995, f32 *, 0xC))) {
            var_r0_986 = 1;
        }
    }
    if (var_r0_986 == 0) {
        temp_r0_1034 = ((u32) (128.0f * (f32) sp30) << 0x18) + (((u32) (128.0f * (*(f32 *) ((u8 *) &sp30 + 0x4))) << 0x10) + ((u32) (128.0f * (f32) sp38) << 8) + (u32) (128.0f * (*(f32 *) ((u8 *) &sp38 + 0x4))));
        sp8 = temp_r0_1034;
        spC = temp_r0_1034;
        GXSetChanMatColor(GX_COLOR0A0, (GXColor) &spC);
        M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0x40) = sp30;
        M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0x48) = sp38;
    }
    temp_r8_1047 = &MKMaterial_GeometryColor + 0x10;
    M2C_FIELD(&MKPrimitive_BaseColor, s8 *, 0) = 0x80;
    M2C_FIELD(&MKPrimitive_BaseColor, s8 *, 1) = 0x80;
    M2C_FIELD(&MKPrimitive_BaseColor, s8 *, 2) = 0x80;
    M2C_FIELD(&MKPrimitive_BaseColor, s8 *, 3) = 0x80;
    currentPrim = arg0 & 7;
    currentType = arg0;
    temp_r7_1055 = &MKMaterial_GeometryColor + 0x28;
    M2C_FIELD(temp_r7_1055, f64 *, 0) = (f64) M2C_FIELD(temp_r8_1047, f64 *, 0);
    M2C_FIELD(temp_r7_1055, f32 *, 8) = (f32) M2C_FIELD(temp_r8_1047, f32 *, 8);
    M2C_FIELD(temp_r7_1055, u8 *, 0xC) = (u8) M2C_FIELD(temp_r8_1047, u8 *, 0xC);
    M2C_FIELD(temp_r7_1055, u8 *, 0xD) = (u8) M2C_FIELD(temp_r8_1047, u8 *, 0xD);
    M2C_FIELD(temp_r7_1055, u8 *, 0xE) = (u8) M2C_FIELD(temp_r8_1047, u8 *, 0xE);
    M2C_FIELD(temp_r7_1055, u8 *, 0xF) = (u8) M2C_FIELD(temp_r8_1047, u8 *, 0xF);
    M2C_FIELD(temp_r7_1055, f64 *, 0x10) = (f64) M2C_FIELD(temp_r8_1047, f64 *, 0x10);
    bLit = 1;
    temp_r3_1072 = MKMaterialInternal_GetCurrent();
    if ((temp_r3_1072 == 0) || (arg0 & 8) || ((s32) M2C_FIELD(M2C_FIELD(temp_r3_1072, void **, 0x24), s32 *, 0x28) != 0)) {
        bLit = 0;
    }
    if (arg0 & 0x10) {
        bLit = 1;
    }
    MKPrimitive_bAlphaModulate = 0;
    if ((u32) temp_r3_1072 != 0U) {
        temp_r4_1094 = M2C_FIELD(temp_r3_1072, void **, 0x24);
        M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1094, f64 *, 0x30);
        M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1094, f64 *, 0x38);
        if ((s32) M2C_FIELD(temp_r4_1094, s32 *, 0x24) == 2) {
            MKPrimitive_bAlphaModulate = 1;
            M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 0) = (f32) ((f32) M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 0) * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0xC));
            M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 4) = (f32) (M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 4) * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0xC));
            M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 8) = (f32) ((f32) M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 8) * M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0xC));
            M2C_FIELD(&MKPrimitive_colorModulate, f32 *, 0xC) = 1.0f;
        }
    } else {
        sp10 = 1.0f;
        sp14 = 1.0f;
        sp18 = 1.0f;
        sp1C = 1.0f;
        M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 0) = (f64) sp10;
        sp40 = (f64) sp10;
        sp48 = (f64) sp18;
        M2C_FIELD(&MKPrimitive_colorModulate, f64 *, 8) = (f64) sp18;
    }
    MK_SetVDMode((MK_VertexDescriptorMode) 6);
    if (arg0 & 0x40) {
        GXSetCullMode(GX_CULL_FRONT);
    }
    if ((arg1 & 0x80) && ((u32) temp_r3_1072 != 0U)) {
        temp_r0_1144 = M2C_FIELD(M2C_FIELD(temp_r3_1072, void **, 0x24), u8 *, 0xE0);
        switch ((s8) temp_r0_1144) {                /* irregular */
        case 0:
            GXSetCullMode(GX_CULL_NONE);
            return;
        case 1:
            GXSetCullMode(GX_CULL_FRONT);
            return;
        case 2:
            GXSetCullMode(GX_CULL_BACK);
            return;
        default:
            GXSetCullMode(M2C_FIELD(&gMKDefaults, s32 *, 0x90) != 0);
            break;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp14'
s32 MKMaterial_BeginInternal() {
    f32 sp10;
    f32 spC;
    f32 sp8;
    Texture *temp_r31_1249;
    f32 *temp_r3_1230;
    f32 temp_f1_1235;
    f32 temp_f3_1232;
    void *temp_r30_1314;
    void *temp_r3_1349;

    if ((s8) init_468 == 0) {
        oldCounter_467 = 0;
        init_468 = 1;
    }
    if ((s32) oldCounter_467 != (s32) MKView_SettingsCounter) {
        oldCounter_467 = MKView_SettingsCounter;
        MKView_GetProjection(&sp8, &spC, &sp10);
        if (spC != 0.0f) {
            C_MTXPerspective((f32 (*)[4]) &sp14[0], 57.29578f * sp8, MKView_GetAspectRatio(), spC, sp10);
            GXSetProjection((f32 (*)[4]) &sp14[0], GX_PERSPECTIVE);
        } else {
            temp_r3_1230 = MKView_GetOrthoRect();
            temp_f3_1232 = M2C_FIELD(temp_r3_1230, f32 *, 0);
            temp_f1_1235 = M2C_FIELD(temp_r3_1230, f32 *, 4);
            C_MTXOrtho((f32 (*)[4]) &sp14[0], temp_f1_1235, temp_f1_1235 + M2C_FIELD(temp_r3_1230, f32 *, 0xC), temp_f3_1232, temp_f3_1232 + M2C_FIELD(temp_r3_1230, f32 *, 8), 0.0f, 1.0f);
            GXSetProjection((f32 (*)[4]) &sp14[0], GX_ORTHOGRAPHIC);
        }
        temp_r31_1249 = MKView_GetRenderTarget(NULL);
        if ((s8) init_476 == 0) {
            pOldRenderTarget_475 = NULL;
            init_476 = 1;
        }
        if (((Texture *) pOldRenderTarget_475 != NULL) && (temp_r31_1249 != (Texture *) pOldRenderTarget_475)) {
            GXSetTexCopyDst((u16) pOldRenderTarget_475->unk24, (u16) pOldRenderTarget_475->unk28, GX_TF_RGBA8, 0U);
            GXSetTexCopySrc(0U, 0x190U, (u16) pOldRenderTarget_475->unk24, (u16) pOldRenderTarget_475->unk28);
            GXCopyTex(GXGetTexObjData(&pOldRenderTarget_475->unk60), 1U);
            GXPixModeSync();
            GXInvalidateTexAll();
        }
        if (temp_r31_1249 != NULL) {
            GXSetViewport(0.0f, 400.0f, (f32) temp_r31_1249->unk24, (f32) temp_r31_1249->unk28, 0.0f, 1.0f);
            GXSetScissor(0U, 0x190U, (u32) temp_r31_1249->unk24, (u32) temp_r31_1249->unk28);
        } else {
            MKView_GetViewport();
            temp_r30_1314 = M2C_ERROR(/* Read from unset register $r3 */);
            GXSetViewport(*M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4), M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8), M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0xC), 0.0f, 1.0f);
            GXSetScissor((u32) (u16) (s32) M2C_FIELD(temp_r30_1314, f32 *, 0), (u32) (u16) (s32) M2C_FIELD(temp_r30_1314, f32 *, 4), (u32) (u16) (s32) M2C_FIELD(temp_r30_1314, f32 *, 8), (u32) (u16) (s32) M2C_FIELD(temp_r30_1314, f32 *, 0xC));
        }
        pOldRenderTarget_475 = temp_r31_1249;
    }
    if ((MKMaterial *) gpCurrentMaterial != NULL) {
        temp_r3_1349 = gpCurrentMaterial->unk34;
        return M2C_FIELD(temp_r3_1349, s32 (**)(void *), 0xC)(temp_r3_1349);
    }
    return 0;
}
#endif

s32 MKMaterial_Begin() {
    void *temp_r4_1377;

    if ((MKMaterial *) gpCurrentMaterial != NULL) {
        temp_r4_1377 = gpCurrentMaterial->unk34;
        return M2C_FIELD(temp_r4_1377, s32 (**)(void *), 8)(temp_r4_1377);
    }
    return 0;
}

#if 0 // DRAFT: illegal operand
void MKMaterial_SetMaterial(MKMaterial *arg0) {
    MKMaterial *var_r3_0;
    enum _GXTevStageID var_r31_1454;

    var_r3_0 = arg0;
    if (var_r3_0 == NULL) {
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
        if (MKView_GetRenderTarget(NULL) != NULL) {
            GXSetZMode(0U, GX_ALWAYS, 0U);
        } else {
            GXSetZMode(1U, GX_LEQUAL, 1U);
        }
        GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
        SetZCompLoc(1U);
        GXSetAlphaCompare(GX_GREATER, 0U, GX_AOP_AND, GX_ALWAYS, 0xFFU);
        GXSetColorUpdate(1U);
        GXSetAlphaUpdate(1U);
        GXSetDstAlpha(1U, 0x3FU);
        GXSetNumTevStages(1U);
        GXSetNumIndStages(0U);
        GXSetNumTexGens(0U);
        var_r31_1454 = GX_TEVSTAGE0;
        do {
            GXSetTevSwapMode(var_r31_1454, GX_TEV_SWAP0, GX_TEV_SWAP0);
            GXSetTevDirect(var_r31_1454);
            var_r31_1454 += 1;
        } while (var_r31_1454 < 0x10);
        MKMaterial_SetGeometryColor(MKVector4::one);
        GXSetChanCtrl(GX_COLOR0A0, 1U, GX_SRC_VTX, GX_SRC_REG, 0U, GX_DF_CLAMP, GX_AF_SPOT);
        GXSetCullMode(GX_CULL_NONE);
        var_r3_0 = gpMKWhiteMaterial;
        gpPreviousMaterial = 0;
    }
    gpCurrentMaterial = var_r3_0;
}
#endif

void MKMaterial_SetGeometryColor(const MKVector4 &arg0) {
    u8 var_r0_1497;

    var_r0_1497 = 0;
    if ((M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0) == arg0.unk0) && (M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 4) == arg0.unk4) && (M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 8) == arg0.unk8) && (M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0xC) == arg0.unkC)) {
        var_r0_1497 = 1;
    }
    if (var_r0_1497 == 0) {
        GXSetAlphaCompare(GX_GREATER, (u8) (s32) (255.0f * (M2C_FIELD(gpCurrentMaterial->unk24, f32 *, 0x2C) * arg0.unkC)), GX_AOP_AND, GX_ALWAYS, 0xFFU);
    }
    M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 0) = (f64) M2C_FIELD(&arg0, f32 *, 0);
    M2C_FIELD(&MKMaterial_GeometryColor, f32 *, 8) = (f64) M2C_FIELD(&arg0, f32 *, 8);
}

void MKMaterial_SetGeometryTransformInfo(GeometryTransformationInfo *arg0) {
    M2C_FIELD(&TransformInfo, s32 *, 0) = arg0->unk0;
    M2C_FIELD(&TransformInfo, s32 *, 4) = (s32) arg0->unk4;
}

#if 0 // DRAFT: illegal implicit conversion from 'const Matrix *' to
void MKMaterial_SetAnimationMatrices(const Matrix *arg0, int arg1) {
    pAnimMats = arg0;
}
#endif

void MKMaterial_SetLocalToWorld(const Matrix *arg0, float arg1) {
    Matrix sp60;
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
    f32 sp20;
    Matrix *var_r5_1580;

    var_r5_1580 = MKView_GetWorldToViewMatrix();
    if (arg0 != NULL) {
        sp60.Multiply(arg0, var_r5_1580);
        var_r5_1580 = &sp60;
    }
    sp20 = var_r5_1580->unk0;
    sp24 = var_r5_1580->unk10;
    sp28 = var_r5_1580->unk20;
    sp2C = var_r5_1580->unk30;
    sp30 = var_r5_1580->unk4;
    sp34 = var_r5_1580->unk14;
    sp38 = var_r5_1580->unk24;
    sp3C = var_r5_1580->unk34;
    sp40 = -var_r5_1580->unk8;
    sp44 = -var_r5_1580->unk18;
    sp48 = -var_r5_1580->unk28;
    sp4C = -var_r5_1580->unk38;
    GXLoadPosMtxImm((f32 (*)[4]) &sp20, 0U);
    GXLoadNrmMtxImm((f32 (*)[4]) &sp20, 0U);
    sp2C = 0.0f;
    sp3C = 0.0f;
    sp4C = 0.0f;
    GXLoadPosMtxImm((f32 (*)[4]) &sp20, 6U);
    GXLoadNrmMtxImm((f32 (*)[4]) &sp20, 6U);
}

void MKMaterial_DeinitModule_PlatformSpecific() {

}

void MKMaterial_InitModule_PlatformSpecific() {
    void *temp_r3_1655;
    void *var_r31_1652;

    var_r31_1652 = gpMKMaterialTypeInfoList;
loop_2:
    if (var_r31_1652 != NULL) {
        temp_r3_1655 = M2C_FIELD(var_r31_1652, void **, 0);
        M2C_FIELD(temp_r3_1655, M2C_UNK (**)(s32), 0x18)(M2C_FIELD(temp_r3_1655, s32 *, 0x20));
        var_r31_1652 = M2C_FIELD(var_r31_1652, void **, 4);
        goto loop_2;
    }
}

void SetZCompLoc(unsigned char arg0) {
    if ((s8) init_500 == 0) {
        currentState_499 = -1;
        init_500 = 1;
    }
    if ((s32) arg0 != (s32) currentState_499) {
        currentState_499 = (s32) arg0;
        GXSetZCompLoc(arg0);
    }
}

void MKMaterial_GC_cpp::__sinit() {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 8) = (f64) sp10;
    M2C_STRUCT_COPY((s32) (&MKMaterial_GeometryColor + 0x24) + 4, (s32) (&MKMaterial_GeometryColor + 0xC) + 4, 0x18);
    M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0x40) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 0);
    M2C_FIELD(&MKMaterial_GeometryColor, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector4::zero, f64 *, 8);
}

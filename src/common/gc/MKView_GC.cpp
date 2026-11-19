#include "common/gc/MKView_GC.h"
#include "common/Source/Matrix.h"
#include "dolphin/gx.h"
#include "dolphin/os.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

extern s32 lit_459;
extern M2C_UNK MKMat_MK2_Standard_CaptureTextureData;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_lightColors_0x10'
static struct _struct_lightColors_0x10 lightColors[3];
#endif
static M2C_UNK ambientColor;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_lightDirs_0x10'
static struct _struct_lightDirs_0x10 lightDirs[3];
#endif
static u8 lit_423 = 0xFF;
static u8 lit_425 = 0xFF;
static u8 lit_427 = 0xFF;
static s32 lit_435 = 0xFF;                             /* const */
static s32 lit_458 = 0xFF;                             /* const */

#if 0 // DRAFT: undefined identifier 'lightDirs'
void *MKView_GetLightDirection(int arg0) {
    return &lightDirs[arg0];
}
#endif

#if 0 // DRAFT: undefined identifier 'lightColors'
void *MKView_GetLightColor(int arg0) {
    return &lightColors[arg0];
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector4'
void MKView_Clear(int arg0, const MKVector4 &arg1, float arg2, unsigned int arg3) {
    s32 sp14;                                       /* compiler-managed */
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r31_60;

    sp14 = lit_458;
    sp14 = (s8) (255.0f * arg1.unk0);
    (*(u8 *) ((u8 *) &sp10 + 0x5)) = (s8) (255.0f * arg1.unk4);
    (*(u8 *) ((u8 *) &sp10 + 0x6)) = (s8) (255.0f * arg1.unk8);
    sp10 = lit_459;
    MKView_GetViewport();
    temp_r31_60 = M2C_ERROR(/* Read from unset register $r3 */);
    GXSetTexCopySrc((u16) (s32) *M2C_ERROR(/* Read from unset register $r3 */), (u16) (s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4), (u16) (s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8), (u16) (s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0xC));
    GXSetTexCopyDst((u16) (s32) (M2C_FIELD(temp_r31_60, f32 *, 8) * 0.5f), (u16) (s32) (M2C_FIELD(temp_r31_60, f32 *, 0xC) * 0.5f), GX_TF_RGBA8, 1U);
    spC = (s32) sp14;
    GXSetCopyClear((GXColor) &spC, 0xFFFFFFU);
    GXSetColorUpdate(arg0 & 1);
    GXSetAlphaUpdate(0U);
    GXSetZMode(1U, GX_ALWAYS, 1U);
    GXCopyTex(&MKMat_MK2_Standard_CaptureTextureData, ((u32) arg0 >> 1U) & 1);
    GXSetAlphaUpdate(1U);
    GXSetColorUpdate(1U);
    sp8 = sp10;
    GXSetCopyClear((GXColor) &sp8, 0xFFFFFFU);
    MKMaterial_SetMaterial(NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'UpdateLighting'
void MKView_SetAmbientColor(const MKVector4 &arg0) {
    M2C_FIELD(&ambientColor, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(&ambientColor, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    UpdateLighting();
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_lightColors_0x10'
void MKView_SetLightColor(int arg0, const MKVector4 &arg1) {
    struct _struct_lightColors_0x10 *temp_r3_157;

    temp_r3_157 = (_struct_lightColors_0x10 *) (&lightColors[arg0]);
    temp_r3_157->unk0 = M2C_FIELD(&arg1, f64 *, 0);
    temp_r3_157->unk8 = M2C_FIELD(&arg1, f64 *, 8);
    UpdateLighting();
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_lightDirs_0x10'
void MKView_SetLightDirection(int arg0, const MKVector3 &arg1) {
    struct _struct_lightDirs_0x10 *temp_r3_178;

    temp_r3_178 = (_struct_lightDirs_0x10 *) (&lightDirs[arg0]);
    temp_r3_178->unk0 = M2C_FIELD(&arg1, f64 *, 0);
    temp_r3_178->unk8 = M2C_FIELD(&arg1, f64 *, 8);
    UpdateLighting();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'long *' to '_GXColor'
void UpdateLighting() {
    Matrix sp90;
    M2C_UNK sp8C;
    f32 sp88;                                       /* compiler-managed */
    f32 sp84;
    f32 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    s8 sp43;
    u8 sp42;
    u8 sp41;
    u8 sp40;
    s32 sp2C;                                       /* compiler-managed */
    s32 sp28;
    s32 sp24;
    f32 sp20;
    f32 temp_f0_402;
    f32 temp_f2_409;
    f32 temp_f7_295;
    f32 temp_f8_283;
    f32 temp_f9_289;
    f32 var_f3_391;
    f32 var_f4_324;
    f64 temp_f1_330;
    f64 temp_f1_336;
    f64 temp_f1_340;
    s32 temp_r3_359;
    s32 var_r0_369;
    s32 var_r29_213;
    s32 var_r30_212;
    s32 var_r3_222;
    s32 var_r3_234;
    s32 var_r3_246;
    struct _struct_lightColors_0x10 *temp_r5_457;
    void *temp_r4_262;
    void *temp_r5_217;

    var_r30_212 = 0;
    var_r29_213 = 0;
    do {
        temp_r5_217 = lightColors + var_r29_213;
        var_r3_222 = (s32) (255.0f * M2C_FIELD(temp_r5_217, f32 *, 0));
        if ((u8) lit_423 < (u8) var_r3_222) {
            var_r3_222 = (s32) lit_423;
        }
        sp40 = (u8) var_r3_222;
        var_r3_234 = (s32) (255.0f * M2C_FIELD(temp_r5_217, f32 *, 4));
        if ((u8) lit_425 < (u8) var_r3_234) {
            var_r3_234 = (s32) lit_425;
        }
        sp41 = (u8) var_r3_234;
        var_r3_246 = (s32) (255.0f * M2C_FIELD(temp_r5_217, f32 *, 8));
        if ((u8) lit_427 < (u8) var_r3_246) {
            var_r3_246 = (s32) lit_427;
        }
        sp42 = (u8) var_r3_246;
        sp43 = 0xFF;
        sp28 = (s32) sp40;
        GXInitLightColor((GXLightObj *) (lightColors + 0x80), (GXColor) &sp28);
        temp_r4_262 = lightColors + 0x40 + var_r29_213;
        sp80 = M2C_FIELD(temp_r4_262, f32 *, 0);
        sp84 = M2C_FIELD(temp_r4_262, f32 *, 4);
        sp88 = M2C_FIELD(temp_r4_262, f32 *, 8);
        sp90.SetIdentity();
        M2C_STRUCT_COPY((s32) &sp8C + 4, MKView_GetWorldToViewMatrix() - 4 + 4, 0x40);
        temp_f8_283 = sp90.unk18 * -1.0f;
        temp_f9_289 = sp90.unk8 * -1.0f;
        temp_f7_295 = sp90.unk28 * -1.0f;
        sp90.unk8 = temp_f9_289;
        sp90.unk18 = temp_f8_283;
        sp60 = (sp88 * sp90.unk20) + ((sp80 * M2C_BITWISE(f32, sp90)) + (sp84 * sp90.unk10));
        sp64 = (sp88 * sp90.unk24) + ((sp80 * sp90.unk4) + (sp84 * sp90.unk14));
        sp68 = (sp88 * temp_f7_295) + ((sp80 * temp_f9_289) + (sp84 * temp_f8_283));
        sp80 = (f64) sp60;
        sp88 = (f64) sp68;
        sp90.unk28 = temp_f7_295;
        sp70 = (f64) sp60;
        sp78 = (f64) sp68;
        var_f4_324 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (sp84 * sp84));
        if (var_f4_324 > 0.000001f) {
            if (var_f4_324 > 0.0f) {
                temp_f1_330 = __frsqrte(var_f4_324);
                temp_f1_336 = 0.5 * temp_f1_330 * -(((f64) var_f4_324 * (temp_f1_330 * temp_f1_330)) - 3.0);
                temp_f1_340 = 0.5 * temp_f1_336 * -(((f64) var_f4_324 * (temp_f1_336 * temp_f1_336)) - 3.0);
                var_f4_324 = (f32) ((f64) var_f4_324 * (0.5 * temp_f1_340 * -(((f64) var_f4_324 * (temp_f1_340 * temp_f1_340)) - 3.0)));
            } else if (var_f4_324 < M2C_BITWISE(f32, 0.0)) {
                var_f4_324 = __float_nan;
            } else {
                sp20 = var_f4_324;
                temp_r3_359 = M2C_BITWISE(s32, sp20) & 0x7F800000;
                switch (temp_r3_359) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                        var_r0_369 = 1;
                    } else {
                        var_r0_369 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                        var_r0_369 = 5;
                    } else {
                        var_r0_369 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_369 = 4;
                    break;
                }
                if (var_r0_369 == 1) {
                    var_f4_324 = __float_nan;
                }
            }
            var_f3_391 = 1.0f / var_f4_324;
        } else {
            var_f3_391 = 0.0f;
        }
        temp_f0_402 = (f32) sp88 * var_f3_391;
        sp80 = (f32) sp80 * var_f3_391;
        sp84 *= var_f3_391;
        sp88 = temp_f0_402;
        sp80 = (f64) sp80 * 6.088608896e-315;
        temp_f2_409 = temp_f0_402 * 1000000.0f;
        sp88 = temp_f2_409;
        GXInitLightPos((GXLightObj *) (lightColors + 0x80), -(f32) sp80, -sp84, -temp_f2_409);
        GXInitLightAttnA((GXLightObj *) (lightColors + 0x80), 1.0f, 0.0f, 0.0f);
        GXInitLightDistAttn((GXLightObj *) (lightColors + 0x80), 0.0f, 0.0f, GX_DA_OFF);
        switch (var_r30_212) {                      /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            GXLoadLightObjImm((GXLightObj *) (lightColors + 0x80), GX_LIGHT0);
            break;
        case 1:                                     /* switch 2 */
            GXLoadLightObjImm((GXLightObj *) (lightColors + 0x80), GX_LIGHT1);
            break;
        case 2:                                     /* switch 2 */
            GXLoadLightObjImm((GXLightObj *) (lightColors + 0x80), GX_LIGHT2);
            break;
        }
        var_r30_212 += 1;
        var_r29_213 += 0x10;
    } while (var_r30_212 < 3);
    temp_r5_457 = (_struct_lightColors_0x10 *) (lightColors + 0x30);
    sp2C = lit_435;
    sp2C = (s8) (255.0f * M2C_FIELD(lightColors, f32 *, 0x30));
    (*(u8 *) ((u8 *) &sp28 + 0x5)) = (s8) (255.0f * M2C_FIELD(temp_r5_457, f32 *, 4));
    (*(u8 *) ((u8 *) &sp28 + 0x6)) = (s8) (255.0f * M2C_FIELD(temp_r5_457, f32 *, 8));
    sp24 = (s32) sp2C;
    GXSetChanAmbColor(GX_COLOR0A0, (GXColor) &sp24);
}
#endif

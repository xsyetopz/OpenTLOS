#include "common/Source/MKGrass.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKGrass_MP.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/OmniLight.h"
#include "common/Source/Texture.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/MKShockWave_MP.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/Source/system_extras.h"
#include "common/gc/MKMaterial_GC.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

s32 atoi(s8 *);                                     /* extern */
M2C_UNK free(u8 *);                                 /* extern */
u8 *malloc(s32);                                    /* extern */
s32 strcmpi(s8 *, s8 *);                            /* extern */
s32 stricmp(s8 *, void *);                          /* extern */
#if 0 // DRAFT: identifier 'MKGrass_cameraPos' redeclared was declared as: 'float' now declared as: 'long'
extern M2C_UNK MKGrass_cameraPos;
#endif
#if 0 // DRAFT: identifier 'MKGrass_pushAwaySpheres' redeclared was declared as: 'unsigned char[64]' now declared as: 'long'
extern M2C_UNK MKGrass_pushAwaySpheres;
#endif
#if 0 // DRAFT: identifier 'MKGrass_windDirection' redeclared was declared as: 'MKHeap' now declared as: 'long'
extern M2C_UNK MKGrass_windDirection;
#endif
extern MKModel ***drawQueue;
extern M2C_UNK gEmptyPtrList;
extern M2C_UNK gMKDefaults;
#if 0 // DRAFT: identifier 'gShockWaveData' redeclared was declared as: 'unsigned char[112]' now declared as: 'long'
extern M2C_UNK gShockWaveData;
#endif
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern s32 gnGrassTypes;
#if 0 // DRAFT: identifier 'gpGrassTypes' redeclared was declared as: 'long' now declared as: 'signed char *'
extern s8 *gpGrassTypes;
#endif
extern void ***grassModelsList;
#if 0 // DRAFT: identifier 'MKGrass_bEnable' redeclared was declared as: 'unsigned char[1]' now declared as: 'unsigned char'
static u8 MKGrass_bEnable = 1;
#endif

#if 0 // DRAFT: undefined identifier 'spA8'
void MKGrass_Draw() {
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f64 spA0;
    f32 sp9C;
    f64 sp98;
    f64 sp90;
    OmniLight *sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    BoundingVolume *temp_r4_235;
    GrassSubObject *temp_r21_218;
    MKHeap **temp_r3_290;
    MKMaterial *temp_r28_181;
    MKModel ***var_r26_188;
    MKModel **temp_r3_360;
    MKModel *temp_r25_191;
    Matrix *temp_r3_144;
    f32 temp_f1_269;
    f32 temp_f1_311;
    f32 temp_f3_236;
    f32 temp_f4_55;
    f32 var_f3_130;
    f32 var_f4_63;
    f64 temp_f0_258;
    f64 temp_f0_38;
    f64 temp_f1_69;
    f64 temp_f1_75;
    f64 temp_f1_79;
    s32 temp_r3_231;
    s32 temp_r3_98;
    s32 temp_r5_233;
    s32 var_r0_108;
    s32 var_r18_212;
    s32 var_r19_193;
    s32 var_r20_157;
    s32 var_r22_211;
    s32 var_r23_192;
    s32 var_r30_155;
    s32 var_r3_328;
    s8 *temp_r29_161;
    u16 temp_r0_200;
    u8 temp_r27_183;
    u8 var_r17_292;
    void *temp_r24_196;
    void *temp_r31_199;
    void *temp_r4_162;
    void *temp_r4_182;

    if ((MKModel **) *drawQueue != NULL) {
        M2C_STRUCT_COPY((s32) &sp9C + 4, MKView_GetWorldFrustum() - 4 + 4, 0x70);
        temp_f0_38 = spA0 * 1.583207797e-314;
        sp10 = temp_f0_38;
        sp60 = temp_f0_38;
        sp18 = spA8 * -0.5f;
        sp68 = (f64) sp18;
        spD0 = (f64) (spD0 - temp_f0_38);
        temp_f4_55 = spD8 - (f32) sp68;
        spD8 = temp_f4_55;
        var_f4_63 = (temp_f4_55 * temp_f4_55) + ((spD0 * spD0) + (spD4 * spD4));
        if (var_f4_63 > 0.000001f) {
            if (var_f4_63 > 0.0f) {
                temp_f1_69 = __frsqrte(var_f4_63);
                temp_f1_75 = 0.5 * temp_f1_69 * -(((f64) var_f4_63 * (temp_f1_69 * temp_f1_69)) - 3.0);
                temp_f1_79 = 0.5 * temp_f1_75 * -(((f64) var_f4_63 * (temp_f1_75 * temp_f1_75)) - 3.0);
                var_f4_63 = (f32) ((f64) var_f4_63 * (0.5 * temp_f1_79 * -(((f64) var_f4_63 * (temp_f1_79 * temp_f1_79)) - 3.0)));
            } else if (var_f4_63 < M2C_BITWISE(f32, 0.0)) {
                var_f4_63 = __float_nan;
            } else {
                sp8 = var_f4_63;
                temp_r3_98 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_98) {               /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_108 = 1;
                    } else {
                        var_r0_108 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_108 = 5;
                    } else {
                        var_r0_108 = 3;
                    }
                    break;
                default:
                    var_r0_108 = 4;
                    break;
                }
                if (var_r0_108 == 1) {
                    var_f4_63 = __float_nan;
                }
            }
            var_f3_130 = 1.0f / var_f4_63;
        } else {
            var_f3_130 = 0.0f;
        }
        spD0 *= var_f3_130;
        spD4 *= var_f3_130;
        spD8 *= var_f3_130;
        temp_r3_144 = MKView_GetCameraMatrix();
        M2C_FIELD(&MKGrass_cameraPos, f64 *, 0) = (f64) M2C_FIELD(temp_r3_144, f64 *, 0x30);
        M2C_FIELD(&MKGrass_cameraPos, f64 *, 8) = (f64) M2C_FIELD(temp_r3_144, f64 *, 0x38);
        MKGrass_InitDraw();
        var_r30_155 = 0;
        var_r20_157 = 0;
loop_50:
        if (var_r30_155 < (s32) gnGrassTypes) {
            temp_r29_161 = &gpGrassTypes[var_r20_157];
            temp_r4_162 = M2C_FIELD(temp_r29_161, void **, 0x2C);
            if ((temp_r4_162 != NULL) && ((u8) M2C_FIELD(temp_r4_162, u8 *, 0x24) != 0) && ((u8) M2C_FIELD(temp_r4_162, u8 *, 0x26) != 0)) {
                M2C_FIELD(temp_r4_162, s8 *, 0x25) = 0;
                M2C_FIELD(M2C_FIELD(temp_r29_161, void **, 0x2C), u8 *, 0x26) = 0U;
                temp_r28_181 = *M2C_FIELD(M2C_FIELD(*M2C_FIELD(M2C_FIELD(temp_r29_161, void **, 0x2C), void ***, 0x9C), void **, 0x30), MKMaterial ***, 0x54);
                temp_r4_182 = temp_r28_181->unk24;
                temp_r27_183 = M2C_FIELD(temp_r4_182, u8 *, 0xE0);
                M2C_FIELD(temp_r4_182, u8 *, 0xE0) = 0U;
                MKMaterial_SetMaterial(NULL);
                MKMaterial_SetMaterial(temp_r28_181);
                var_r26_188 = drawQueue;
loop_47:
                temp_r3_360 = *var_r26_188;
                if (temp_r3_360 != NULL) {
                    temp_r25_191 = M2C_FIELD(temp_r3_360, MKModel **, 0);
                    var_r23_192 = 0;
                    var_r19_193 = 0;
                    temp_r24_196 = M2C_FIELD(M2C_FIELD(temp_r25_191->unk0, void **, 0x30), void **, 0x24);
loop_45:
                    if (var_r23_192 < (s32) M2C_FIELD(temp_r24_196, s32 *, 4)) {
                        temp_r31_199 = ((u8 *) temp_r24_196) + var_r19_193;
                        temp_r0_200 = M2C_FIELD(temp_r31_199, u16 *, 8);
                        if (((s32) temp_r0_200 == var_r30_155) || (((MKGrassType *) (gpGrassTypes + (temp_r0_200 * 0x30)))->IsInOverlayChain((MKGrassType *) temp_r29_161) != 0)) {
                            var_r22_211 = 0;
                            var_r18_212 = 0;
loop_42:
                            if (var_r22_211 < (s32) M2C_FIELD(temp_r31_199, u16 *, 0xA)) {
                                temp_r21_218 = (GrassSubObject *) (M2C_FIELD(temp_r31_199, s32 *, 0xC) + var_r18_212);
                                if (!(MKModel_GetSubObjectFlag(temp_r25_191, (SubObjectType) 0, (s32) temp_r21_218->unk0) & 0xF) && (!(((u8) M2C_FIELD(*var_r26_188, MKModel **, 0)->unk5 >> 6U) & 1) || ((temp_r3_231 = temp_r21_218->unk0 << 6, temp_r5_233 = M2C_FIELD(M2C_FIELD(temp_r25_191->unk0, void **, 0x30), s32 *, 0x50), temp_r4_235 = temp_r5_233 + temp_r3_231, temp_f3_236 = *(temp_r5_233 + (temp_r3_231 + 0xC)), sp40 = (0.5f * temp_r4_235->unk10) + temp_r4_235->unk0, sp44 = (0.5f * temp_r4_235->unk14) + temp_r4_235->unk4, sp48 = (0.5f * temp_r4_235->unk18) + temp_r4_235->unk8, sp90 = (f64) sp40, sp98 = (f64) sp48, sp9C = temp_f3_236, temp_f0_258 = (f64) sp40 - M2C_FIELD(&MKGrass_cameraPos, f64 *, 0), sp30 = temp_f0_258, sp50 = temp_f0_258, sp38 = (f32) sp98 - (f32) M2C_FIELD(&MKGrass_cameraPos, f64 *, 8), temp_f1_269 = M2C_FIELD(M2C_FIELD(temp_r29_161, void **, 0x2C), f32 *, 0x34) + temp_f3_236, sp58 = (f64) sp38, (((((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4))))) > (temp_f1_269 * temp_f1_269)) == 0)) && (((Frustum *) &spA0)->IsVisible(temp_r4_235) != 0)))) {
                                    temp_r3_290 = MKModel_GetBoundingVolume(temp_r25_191, (SubObjectType) 0, (s32) temp_r21_218->unk0);
                                    var_r17_292 = 0;
                                    sp20 = (0.5f * M2C_FIELD(temp_r3_290, f32 *, 0x10)) + M2C_FIELD(temp_r3_290, f32 *, 0);
                                    sp24 = (0.5f * M2C_FIELD(temp_r3_290, f32 *, 0x14)) + M2C_FIELD(temp_r3_290, f32 *, 4);
                                    sp28 = (0.5f * M2C_FIELD(temp_r3_290, f32 *, 0x18)) + M2C_FIELD(temp_r3_290, f32 *, 8);
                                    sp70 = (f64) sp20;
                                    sp78 = (f64) sp28;
                                    temp_f1_311 = M2C_FIELD(temp_r3_290, f32 *, 0xC);
                                    (*(f32 *) ((u8 *) &sp78 + 0x4)) = temp_f1_311;
                                    if (((u8) M2C_FIELD(&gShockWaveData, u8 *, 0x60) != 0) && (MKShockWave_IsWithin(*((MKVector3 *) &sp70), temp_f1_311) != 0)) {
                                        var_r17_292 = 1;
                                    }
                                    if ((u8) M2C_FIELD(*var_r26_188, u8 *, 8) != 0) {
                                        var_r3_328 = OmniLight_FindNearestGroup(*((MKVector3 *) &sp70), (*(f32 *) ((u8 *) &sp78 + 0x4)), &sp80, 4);
                                    } else {
                                        var_r3_328 = 0;
                                    }
                                    MKGrass_DrawSubObject(*((Frustum *) &spA0), temp_r25_191, temp_r25_191->unk8, (MKGrassType *) temp_r29_161, temp_r21_218, var_r17_292, var_r3_328, &sp80);
                                }
                                var_r22_211 += 1;
                                var_r18_212 += 0xC;
                                goto loop_42;
                            }
                            MKGrass_FlushSubObject((MKGrassType *) temp_r29_161);
                        }
                        var_r23_192 += 1;
                        var_r19_193 += 8;
                        goto loop_45;
                    }
                    var_r26_188 += 4;
                    goto loop_47;
                }
                M2C_FIELD(temp_r28_181->unk24, u8 *, 0xE0) = temp_r27_183;
                MKMaterial_SetMaterial(NULL);
                MKMaterial_SetMaterial(temp_r28_181);
            }
            var_r30_155 += 1;
            var_r20_157 += 0x30;
            goto loop_50;
        }
loop_53:
        if ((MKModel **) *drawQueue != NULL) {
            drawQueue += 4;
            goto loop_53;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKGrass_QueueDraw(const MKModel *arg0, const unsigned short *arg1) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap **temp_r3_415;
    MKModel ***temp_r6_409;
    MKModel **temp_r31_411;
    s32 var_r3_441;
    s32 var_r7_439;
    void *temp_r5_459;
    void *temp_r6_444;
    void *var_r8_451;

    if ((u8) MKGrass_bEnable != 0) {
        temp_r6_409 = drawQueue - 4;
        drawQueue = temp_r6_409;
        temp_r31_411 = *temp_r6_409;
        M2C_FIELD(temp_r31_411, MKModel **, 0) = (MKModel *) (arg0);
        M2C_FIELD(temp_r31_411, u16 **, 4) = (unsigned short *) (arg1);
        temp_r3_415 = MKModel_GetBoundingVolume(arg0, (SubObjectType) 0, -1);
        sp8 = (0.5f * M2C_FIELD(temp_r3_415, f32 *, 0x10)) + M2C_FIELD(temp_r3_415, f32 *, 0);
        spC = (0.5f * M2C_FIELD(temp_r3_415, f32 *, 0x14)) + M2C_FIELD(temp_r3_415, f32 *, 4);
        sp10 = (0.5f * M2C_FIELD(temp_r3_415, f32 *, 0x18)) + M2C_FIELD(temp_r3_415, f32 *, 8);
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        OmniLight_FindNearest(*((MKVector3 *) &sp18), M2C_FIELD(temp_r3_415, f32 *, 0xC));
        var_r7_439 = 0;
        M2C_FIELD(temp_r31_411, s8 *, 8) = (s8) (M2C_ERROR(/* Read from unset register $r3 */) != 0);
        var_r3_441 = 0;
        temp_r6_444 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), void **, 0x24);
loop_7:
        if (var_r7_439 < (s32) M2C_FIELD(temp_r6_444, s32 *, 4)) {
            var_r8_451 = gpGrassTypes + (*(temp_r6_444 + (var_r3_441 + 8)) * 0x30);
loop_4:
            if (var_r8_451 != NULL) {
                temp_r5_459 = M2C_FIELD(var_r8_451, void **, 0x2C);
                if (temp_r5_459 != NULL) {
                    M2C_FIELD(temp_r5_459, s8 *, 0x26) = 1;
                    var_r8_451 = M2C_FIELD(var_r8_451, void **, 0x20);
                    goto loop_4;
                }
            }
            var_r7_439 += 1;
            var_r3_441 += 8;
            goto loop_7;
        }
        if ((u32) M2C_FIELD(drawQueue, u32 *, -4) == 0U) {
            MKGrass_Draw();
        }
    }
}
#endif

#if 0 // DRAFT: function call 'MKMaterial_GetEffectType(MKMaterial *, signed char **)' does not match 'MKMaterial_GetEffectType(MKMaterial *, const char **)'
void MKGrass_ProcessGrassStripData(MKModel *arg0) {
    s8 *sp8;
    MKHeap *temp_r3_550;
    MeshChunkExplorer *temp_r21_591;
    s16 temp_r24_512;
    s16 temp_r26_493;
    s16 var_r22_593;
    s32 temp_r24_492;
    s32 var_r23_534;
    s32 var_r28_530;
    s32 var_r28_592;
    u8 *temp_r23_603;
    u8 *temp_r5_600;
    u8 *var_r24_576;
    u8 *var_r26_590;
    u8 *var_r3_502;
    u8 *var_r3_521;

    temp_r24_492 = gnGrassTypes;
    temp_r26_493 = MKModel_GetNmbrOfMaterials(arg0);
    if (MKHeap::Current() != NULL) {
        var_r3_502 = (unsigned char *) (((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r24_492, NULL, 0, 0U));
    } else {
        var_r3_502 = malloc(temp_r24_492);
    }
    temp_r24_512 = MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0);
    if (MKHeap::Current() != NULL) {
        var_r3_521 = (unsigned char *) (((MKHeap *) (MKHeap::Main()))->TAlloc((s32) temp_r24_512, NULL, 0, 0U));
    } else {
        var_r3_521 = malloc((s32) temp_r24_512);
    }
    var_r28_530 = 0;
    memset(var_r3_502, 0, (u32) gnGrassTypes);
    var_r23_534 = 0;
loop_13:
    if (var_r23_534 < temp_r26_493) {
        MKMaterial_GetEffectType(MKModel_GetMaterial(arg0, var_r23_534, 0U), &sp8);
        if (stricmp() == 0) {
            temp_r3_550 = MKGrass_GetGrassTypeId(sp8);
            if (temp_r3_550 >= 0) {
                if ((u8) var_r3_502[temp_r3_550] == 0) {
                    var_r28_530 += 1;
                }
                var_r3_502[temp_r3_550] = 1;
            }
        }
        var_r23_534 += 1;
        goto loop_13;
    }
    if (var_r28_530 != 0) {
        if (MKHeap::Current() != NULL) {
            var_r24_576 = (unsigned char *) (((MKHeap *) (MKHeap::Current()))->Alloc(((var_r28_530 - 1) * 8) + 0x10, NULL, 0));
        } else {
            var_r24_576 = malloc(((var_r28_530 - 1) * 8) + 0x10);
        }
        M2C_FIELD(var_r24_576, s32 *, 0) = 0;
        M2C_FIELD(var_r24_576, s32 *, 4) = var_r28_530;
        MKModel_ExploreBegin(arg0);
        var_r26_590 = var_r3_502;
        temp_r21_591 = M2C_ERROR(/* Read from unset register $r3 */);
        var_r28_592 = 0;
        var_r22_593 = 0;
loop_22:
        if (var_r22_593 < (s32) gnGrassTypes) {
            if ((u8) *var_r26_590 != 0) {
                temp_r5_600 = &var_r24_576[var_r28_592];
                M2C_FIELD(temp_r5_600, s16 *, 8) = var_r22_593;
                temp_r23_603 = temp_r5_600 + 8;
                M2C_FIELD(temp_r5_600, s16 *, 0xA) = 0;
                CreateGrassStripData(arg0, temp_r21_591, (GrassUsedType *) temp_r23_603);
                OptimiseGrassTypeData(arg0, (GrassUsedType *) temp_r23_603);
                var_r28_592 += 8;
            }
            var_r22_593 += 1;
            var_r26_590 += 1;
            goto loop_22;
        }
        M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), u8 **, 0x24) = var_r24_576;
        MKModel_ExploreEnd(temp_r21_591);
    }
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Main()))->TFree(var_r3_502, NULL, 0);
    } else {
        free(var_r3_502);
    }
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Main()))->TFree(var_r3_521, NULL, 0);
        return;
    }
    free(var_r3_521);
}
#endif

void MKGrass_DrawStats() {

}

#if 0 // DRAFT: illegal type
void MKGrass_Update() {
    f32 temp_f0_726;
    f32 temp_f1_728;
    s32 temp_r0_697;
    s32 var_r26_688;
    s32 var_r31_690;
    s8 *var_r27_678;
    void *temp_r0_716;
    void *temp_r28_715;
    void *temp_r29_721;
    void *temp_r3_681;
    void *temp_r3_695;

    var_r27_678 = (signed char *) (gpGrassTypes);
loop_9:
    if (var_r27_678 < (void *) (gpGrassTypes + (gnGrassTypes * 0x30))) {
        temp_r3_681 = M2C_FIELD(var_r27_678, void **, 0x2C);
        if ((temp_r3_681 != NULL) && ((u8) M2C_FIELD(temp_r3_681, u8 *, 0x24) != 0)) {
            var_r26_688 = 0;
            var_r31_690 = 0;
            do {
                temp_r3_695 = M2C_FIELD(var_r27_678, void **, 0x2C);
                temp_r0_697 = var_r31_690 + 0x6A0;
                *(temp_r3_695 + temp_r0_697) = (gUpdateTimeDelta * ((M2C_FIELD(temp_r3_695, f32 *, 0x40) * 0.0625f * (f32) var_r26_688) + M2C_FIELD(temp_r3_695, f32 *, 0x3C))) + *(temp_r3_695 + temp_r0_697);
loop_6:
                temp_r28_715 = M2C_FIELD(var_r27_678, void **, 0x2C);
                temp_r0_716 = ((u8 *) temp_r28_715) + 0x6A0;
                if (*(var_r31_690 + temp_r0_716) > 6.2831855f) {
                    *(var_r31_690 + temp_r0_716) = *(var_r31_690 + temp_r0_716) - 6.2831855f;
                    goto loop_6;
                }
                temp_r29_721 = ((u8 *) temp_r28_715) + var_r31_690;
                var_r26_688 += 1;
                temp_f0_726 = M2C_FIELD(temp_r29_721, f32 *, 0x720);
                temp_f1_728 = M2C_FIELD(temp_r28_715, f32 *, 0x38) * _table_sinf(*(temp_r28_715 + (var_r31_690 + 0x6A0)));
                var_r31_690 += 4;
                M2C_FIELD(temp_r29_721, f32 *, 0x6E0) = (f32) (temp_f0_726 * temp_f1_728);
            } while (var_r26_688 < 0x10);
        }
        var_r27_678 += 0x30;
        goto loop_9;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to 'MKHeap *'
void MKGrass_DestroyGrassData(MKModel *arg0) {
    MKHeap *temp_r30_767;
    s32 var_r29_763;
    s32 var_r31_764;

    var_r29_763 = 0;
    var_r31_764 = 0;
    temp_r30_767 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), MKHeap **, 0x24);
loop_2:
    if (var_r29_763 < (s32) temp_r30_767->unk4) {
        ((MKHeap *) (*(temp_r30_767 + (var_r31_764 + 0xC))))->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        var_r29_763 += 1;
        var_r31_764 += 8;
        goto loop_2;
    }
    temp_r30_767->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
    M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), s32 *, 0x24) = 0;
}
#endif

#if 0 // DRAFT: type mismatch 'void **' and 'MKModel *'
void MKGrass_RemoveModel(MKModel *arg0) {
    MKModel ***temp_r4_833;
    MKModel ***var_r6_827;
    MKModel **temp_r4_843;
    MKModel **temp_r5_836;
    s32 *temp_r5_818;
    void ***temp_r4_822;
    void ***var_r6_799;
    void **temp_r0_808;

    var_r6_799 = grassModelsList;
loop_4:
    temp_r0_808 = *var_r6_799;
    if (temp_r0_808 == NULL) {
        var_r6_799 = NULL;
    } else if (temp_r0_808 == arg0) {

    } else {
        var_r6_799 += 4;
        goto loop_4;
    }
    if (var_r6_799 != NULL) {
        temp_r5_818 = M2C_FIELD(M2C_FIELD(**var_r6_799, void **, 0x30), s32 **, 0x24);
        *temp_r5_818 -= 1;
        temp_r4_822 = grassModelsList;
        grassModelsList = temp_r4_822 + 4;
        *var_r6_799 = *temp_r4_822;
        var_r6_827 = drawQueue;
loop_11:
        temp_r4_843 = *var_r6_827;
        if (temp_r4_843 != NULL) {
            if (arg0 == (MKModel *) *temp_r4_843) {
                temp_r4_833 = drawQueue;
                drawQueue = temp_r4_833 + 4;
                temp_r5_836 = *temp_r4_833;
                *temp_r4_833 = *var_r6_827;
                *var_r6_827 = temp_r5_836;
            }
            var_r6_827 += 4;
            goto loop_11;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKGrass_AddModel(MKModel *arg0) {
    s32 var_r29_883;
    s32 var_r30_882;
    s8 *var_r28_890;
    u8 *temp_r0_893;
    u8 *temp_r0_923;
    u8 *var_r27_910;
    u8 *var_r3_903;
    u8 *var_r3_933;
    void ***temp_r3_876;
    void *temp_r31_869;

    if ((s32) gnGrassTypes != 0) {
        if ((u32) M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), u32 *, 0x24) == 0U) {
            MKGrass_ProcessGrassStripData(arg0);
        }
        temp_r31_869 = M2C_FIELD(M2C_FIELD(arg0->unk0, void **, 0x30), void **, 0x24);
        if (temp_r31_869 != NULL) {
            M2C_FIELD(temp_r31_869, s32 *, 0) = (s32) (M2C_FIELD(temp_r31_869, s32 *, 0) + 1);
            temp_r3_876 = grassModelsList - 4;
            grassModelsList = temp_r3_876;
            *temp_r3_876 = &arg0->unk0;
            if ((s32) M2C_FIELD(temp_r31_869, s32 *, 0) == 1) {
                var_r30_882 = 0;
                var_r29_883 = 0;
loop_27:
                if (var_r30_882 < (s32) M2C_FIELD(temp_r31_869, s32 *, 4)) {
                    var_r28_890 = gpGrassTypes + (*(temp_r31_869 + (var_r29_883 + 8)) * 0x30);
loop_25:
                    if (var_r28_890 != NULL) {
                        temp_r0_893 = M2C_FIELD(var_r28_890, u8 **, 0x2C);
                        if (temp_r0_893 == NULL) {
                            if (MKHeap::Current() != NULL) {
                                var_r3_903 = (unsigned char *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x810, NULL, 0));
                            } else {
                                var_r3_903 = malloc(0x810);
                            }
                            M2C_FIELD(var_r28_890, u8 **, 0x2C) = var_r3_903;
                            var_r27_910 = var_r3_903;
                        } else {
                            var_r27_910 = temp_r0_893;
loop_21:
                            if (var_r27_910 != NULL) {
                                if ((s32) M2C_FIELD(var_r27_910, s32 *, 0x20) == (s32) *MKResource::sWorkingChunkID) {
                                    var_r27_910 = NULL;
                                } else {
                                    temp_r0_923 = M2C_FIELD(var_r27_910, u8 **, 0x80C);
                                    if (temp_r0_923 == NULL) {
                                        if (MKHeap::Current() != NULL) {
                                            var_r3_933 = (unsigned char *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x810, NULL, 0));
                                        } else {
                                            var_r3_933 = malloc(0x810);
                                        }
                                        M2C_FIELD(var_r27_910, u8 **, 0x80C) = var_r3_933;
                                        var_r27_910 = var_r3_933;
                                    } else {
                                        var_r27_910 = temp_r0_923;
                                        goto loop_21;
                                    }
                                }
                            }
                        }
                        if (var_r27_910 != NULL) {
                            memset(var_r27_910, 0, 0x810U);
                            strncpy((s8 *) var_r27_910, var_r28_890, 0x1FU);
                            M2C_FIELD(var_r27_910, s32 *, 0x20) = (s32) *MKResource::sWorkingChunkID;
                        }
                        var_r28_890 = M2C_FIELD(var_r28_890, s8 **, 0x20);
                        goto loop_25;
                    }
                    var_r30_882 += 1;
                    var_r29_883 += 8;
                    goto loop_27;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void MKGrass_SetWindDirection(const MKVector3 &arg0, float arg1) {
    MKVector3 sp8;

    sp8 = Normalise(arg0);
    M2C_FIELD(&MKGrass_windDirection, f32 *, 0) = M2C_BITWISE(f32, sp8);
    M2C_FIELD(&MKGrass_windDirection, f32 *, 4) = sp8.unk4;
    M2C_FIELD(&MKGrass_windDirection, f32 *, 8) = sp8.unk8;
    M2C_FIELD(&MKGrass_windDirection, f32 *, 0xC) = arg1;
}
#endif

void MKGrass_SetPushAwaySphere(const MKVector3 &arg0, int arg1) {
    void *temp_r4_1018;

    if ((arg1 >= 0) && (arg1 < 4)) {
        temp_r4_1018 = &MKGrass_pushAwaySpheres + (arg1 * 0x10);
        M2C_FIELD(temp_r4_1018, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r4_1018, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    }
}

u8 MKGrassType::IsInOverlayChain(MKGrassType *arg0) {
    void *var_r3_1028;

    var_r3_1028 = this->unk20;
loop_4:
    if (var_r3_1028 == NULL) {
        return 0U;
    }
    if (var_r3_1028 == arg0) {
        return 1U;
    }
    var_r3_1028 = M2C_FIELD(var_r3_1028, void **, 0x20);
    goto loop_4;
}

#if 0 // DRAFT: function call 'strcmpi(signed char *, const char *)' does not match 'strcmpi(signed char *, signed char *)'
MKHeap *MKGrass_GetGrassTypeId(const char *arg0) {
    s8 *var_r31_1052;

    var_r31_1052 = (signed char *) (gpGrassTypes);
loop_4:
    if (var_r31_1052 >= (void *) (gpGrassTypes + (gnGrassTypes * 0x30))) {
        return (MKHeap *)-1;
    }
    if (strcmpi(var_r31_1052, arg0) == 0) {
        return (MKHeap *) ((s32) (var_r31_1052 - gpGrassTypes) / 48);
    }
    var_r31_1052 += 0x30;
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal type
void MKGrass_ProcessTypes(void *arg0) {
    M2C_UNK sp30;
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    f64 sp18;                                       /* compiler-managed */
    f64 sp10;                                       /* compiler-managed */
    s32 spC;
    f32 sp8;
    f32 temp_f0_1119;
    f32 temp_f0_1550;
    f32 temp_f0_1556;
    f32 temp_f1_1267;
    f32 temp_f2_1118;
    f32 temp_f2_1271;
    f32 temp_f4_1121;
    f32 var_f0_1491;
    f32 var_f1_1482;
    f32 var_f1_1505;
    f32 var_f2_1193;
    f32 var_f5_1126;
    f64 temp_f2_1132;
    f64 temp_f2_1138;
    f64 temp_f2_1142;
    s16 temp_r3_1212;
    s16 var_ctr_1216;
    s32 temp_r0_1220;
    s32 temp_r0_1296;
    s32 temp_r3_1161;
    s32 temp_r3_1260;
    s32 temp_r4_1331;
    s32 temp_r4_1359;
    s32 temp_r6_1259;
    s32 temp_r6_1415;
    s32 var_r0_1171;
    s32 var_r26_1233;
    s32 var_r27_1232;
    s32 var_r27_1354;
    s32 var_r29_1231;
    s32 var_r29_1352;
    s32 var_r30_1350;
    s32 var_r3_1215;
    s32 var_r3_1290;
    s32 var_r4_1292;
    s32 var_r6_1291;
    s32 var_r6_1307;
    s8 *var_r28_1098;
    u32 temp_r6_1453;
    u32 temp_r8_1420;
    u32 var_r30_1214;
    void *temp_r3_1101;
    void *temp_r3_1278;
    void *temp_r3_1319;
    void *temp_r3_1358;
    void *temp_r3_1548;
    void *temp_r3_1553;
    void *temp_r4_1313;
    void *temp_r4_1388;
    void *temp_r4_1392;
    void *temp_r4_1400;
    void *temp_r4_1528;
    void *temp_r5_1117;
    void *temp_r5_1266;
    void *temp_r5_1274;
    void *temp_r5_1311;
    void *temp_r5_1333;
    void *temp_r5_1366;
    void *temp_r7_1375;

    var_r28_1098 = (signed char *) (gpGrassTypes);
loop_67:
    if (var_r28_1098 < (void *) (gpGrassTypes + (gnGrassTypes * 0x30))) {
        temp_r3_1101 = M2C_FIELD(var_r28_1098, void **, 0x2C);
        if ((temp_r3_1101 != NULL) && ((u8) M2C_FIELD(temp_r3_1101, u8 *, 0x98) != 0) && (((s32) *MKResource::sWorkingChunkID == -1) || ((s32) M2C_FIELD(temp_r3_1101, s32 *, 0x20) == (s32) *MKResource::sWorkingChunkID))) {
            spC = M2C_FIELD(var_r28_1098, s32 *, 0x24);
            temp_r5_1117 = M2C_FIELD(var_r28_1098, void **, 0x2C);
            temp_f2_1118 = M2C_FIELD(temp_r5_1117, f32 *, 0x48);
            temp_f0_1119 = M2C_FIELD(temp_r5_1117, f32 *, 0x4C);
            temp_f4_1121 = M2C_FIELD(temp_r5_1117, f32 *, 0x50);
            var_f5_1126 = (temp_f4_1121 * temp_f4_1121) + ((temp_f2_1118 * temp_f2_1118) + (temp_f0_1119 * temp_f0_1119));
            if (var_f5_1126 > 0.000001f) {
                if (var_f5_1126 > 0.0f) {
                    temp_f2_1132 = __frsqrte(var_f5_1126);
                    temp_f2_1138 = 0.5 * temp_f2_1132 * -(((f64) var_f5_1126 * (temp_f2_1132 * temp_f2_1132)) - 3.0);
                    temp_f2_1142 = 0.5 * temp_f2_1138 * -(((f64) var_f5_1126 * (temp_f2_1138 * temp_f2_1138)) - 3.0);
                    var_f5_1126 = (f32) ((f64) var_f5_1126 * (0.5 * temp_f2_1142 * -(((f64) var_f5_1126 * (temp_f2_1142 * temp_f2_1142)) - 3.0)));
                } else if (var_f5_1126 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_1126 = __float_nan;
                } else {
                    sp8 = var_f5_1126;
                    temp_r3_1161 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1161) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1171 = 1;
                        } else {
                            var_r0_1171 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1171 = 5;
                        } else {
                            var_r0_1171 = 3;
                        }
                        break;
                    default:
                        var_r0_1171 = 4;
                        break;
                    }
                    if (var_r0_1171 == 1) {
                        var_f5_1126 = __float_nan;
                    }
                }
                var_f2_1193 = 1.0f / var_f5_1126;
            } else {
                var_f2_1193 = 0.0f;
            }
            M2C_FIELD(temp_r5_1117, f32 *, 0x48) = (f32) (M2C_FIELD(temp_r5_1117, f32 *, 0x48) * var_f2_1193);
            M2C_FIELD(temp_r5_1117, f32 *, 0x4C) = (f32) (M2C_FIELD(temp_r5_1117, f32 *, 0x4C) * var_f2_1193);
            M2C_FIELD(temp_r5_1117, f32 *, 0x50) = (f32) (M2C_FIELD(temp_r5_1117, f32 *, 0x50) * var_f2_1193);
            M2C_FIELD(M2C_FIELD(var_r28_1098, void **, 0x2C), f32 *, 0x54) = (f32) M2C_FIELD(temp_r5_1117, f32 *, 0x54);
            temp_r3_1212 = MKModel_GetNmbrOfSubObjects(M2C_FIELD(M2C_FIELD(var_r28_1098, void **, 0x2C), MKModel **, 0x9C), (SubObjectType) 0);
            var_r30_1214 = 0U;
            var_r3_1215 = 0;
            var_ctr_1216 = temp_r3_1212;
            if (temp_r3_1212 > 0) {
                do {
                    temp_r0_1220 = var_r3_1215 + 0x760;
                    var_r3_1215 += 4;
                    var_r30_1214 += *(M2C_FIELD(var_r28_1098, void **, 0x2C) + temp_r0_1220);
                    var_ctr_1216 -= 1;
                } while (var_ctr_1216 != 0);
            }
            memset(&sp30, 0, 0x40U);
            var_r29_1231 = 0;
            var_r27_1232 = 0;
            var_r26_1233 = 0;
            do {
                if (*(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r26_1233 + 0xAC)) != 1.0f) {
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r26_1233 + 0xA0)) = MKRand_Float((int *) &spC, 0.0f, 1.0f);
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r26_1233 + 0xA4)) = MKRand_Float((int *) &spC, 0.0f, 1.0f);
                    temp_r6_1259 = var_r26_1233 + 0xA8;
                    temp_r3_1260 = var_r26_1233 + 0xA4;
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + temp_r6_1259) = MKRand_Float((int *) &spC, 0.0f, 1.0f);
                    temp_r5_1266 = M2C_FIELD(var_r28_1098, void **, 0x2C) + var_r26_1233;
                    temp_f1_1267 = M2C_FIELD(temp_r5_1266, f32 *, 0xA0);
                    temp_f2_1271 = M2C_FIELD(temp_r5_1266, f32 *, 0xA8) + (temp_f1_1267 + M2C_FIELD(temp_r5_1266, f32 *, 0xA4));
                    M2C_FIELD(temp_r5_1266, f32 *, 0xA0) = (f32) (temp_f1_1267 / temp_f2_1271);
                    temp_r5_1274 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                    *(temp_r5_1274 + temp_r3_1260) = *(temp_r5_1274 + temp_r3_1260) / temp_f2_1271;
                    temp_r3_1278 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                    *(temp_r3_1278 + temp_r6_1259) = *(temp_r3_1278 + temp_r6_1259) / temp_f2_1271;
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r26_1233 + 0xAC)) = 0;
                    if (temp_r3_1212 > 1) {
                        if (var_r30_1214 != 0U) {
                            var_r3_1290 = MKRand_Int((int *) &spC, 0, (s32) var_r30_1214);
                            var_r6_1291 = 0;
                            var_r4_1292 = 0;
loop_33:
                            if ((var_r6_1291 < temp_r3_1212) && (var_r3_1290 >= 0)) {
                                temp_r0_1296 = var_r4_1292 + 0x760;
                                var_r6_1291 += 1;
                                var_r4_1292 += 4;
                                var_r3_1290 -= *(M2C_FIELD(var_r28_1098, void **, 0x2C) + temp_r0_1296);
                                goto loop_33;
                            }
                            var_r6_1307 = var_r6_1291 - 1;
                        } else {
                            temp_r5_1311 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                            temp_r4_1313 = ((u8 *) temp_r5_1311) + (var_r26_1233 + 0xA0);
                            var_r6_1307 = var_r29_1231 % temp_r3_1212;
                            temp_r3_1319 = ((u8 *) temp_r5_1311) + (((var_r29_1231 - var_r6_1307) * 0x10) + 0xA0);
                            M2C_FIELD(temp_r4_1313, f64 *, 0) = (f64) M2C_FIELD(temp_r3_1319, f64 *, 0);
                            M2C_FIELD(temp_r4_1313, f64 *, 8) = (f64) M2C_FIELD(temp_r3_1319, f64 *, 8);
                        }
                        if (var_r29_1231 < 0x10) {
                            *(&sp30 + var_r27_1232) = var_r6_1307;
                        }
                        temp_r4_1331 = var_r26_1233 + 0xAC;
                        *(M2C_FIELD(var_r28_1098, void **, 0x2C) + temp_r4_1331) = (s8) var_r6_1307;
                        temp_r5_1333 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                        if (((u8) M2C_FIELD(temp_r5_1333, u8 *, 0x800) != 0) && (var_r29_1231 >= 0x10)) {
                            *(temp_r5_1333 + temp_r4_1331) = *(temp_r5_1333 + (((var_r29_1231 * 0x10) & 0xF0) + 0xAC));
                        }
                    }
                }
                var_r29_1231 += 1;
                var_r26_1233 += 0x10;
                var_r27_1232 += 4;
            } while (var_r29_1231 < 0x40);
            var_r30_1350 = 0;
            var_r29_1352 = 0;
            var_r27_1354 = 0;
            do {
                temp_r3_1358 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                temp_r4_1359 = M2C_FIELD(temp_r3_1358, s32 *, 0x6C);
                if (temp_r4_1359 >= (s32) M2C_FIELD(temp_r3_1358, s32 *, 0x70)) {
                    M2C_FIELD(temp_r3_1358, s32 *, 0x70) = (s32) (temp_r4_1359 + 1);
                }
                temp_r5_1366 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                temp_r7_1375 = M2C_FIELD(var_r28_1098, void **, 0x2C) + var_r27_1354;
                _table_sincosf(0.017453292f * (f32) (MKRand_Int((int *) &spC, M2C_FIELD(temp_r5_1366, s32 *, 0x6C), M2C_FIELD(temp_r5_1366, s32 *, 0x70)) % 360), *(temp_r7_1375 + 0x4A8), *(temp_r7_1375 + 0x4A0));
                temp_r4_1388 = M2C_FIELD(var_r28_1098, void **, 0x2C) + var_r27_1354;
                M2C_FIELD(temp_r4_1388, f32 *, 0x4A4) = (f32) -M2C_FIELD(temp_r4_1388, f32 *, 0x4A8);
                temp_r4_1392 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r27_1354 + 0x4AC)) = MKRand_Float((int *) &spC, M2C_FIELD(temp_r4_1392, f32 *, 0x64), M2C_FIELD(temp_r4_1392, f32 *, 0x68));
                temp_r4_1400 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                if (*(temp_r4_1400 + (var_r27_1354 + 0x5AC)) != 1.0f) {
                    sp20 = M2C_FIELD(temp_r4_1400, f64 *, 0x78);
                    sp28 = M2C_FIELD(temp_r4_1400, f64 *, 0x80);
                    sp10 = M2C_FIELD(temp_r4_1400, f64 *, 0x88);
                    sp18 = M2C_FIELD(temp_r4_1400, f64 *, 0x90);
                    if ((u8) M2C_FIELD(temp_r4_1400, u8 *, 0x800) != 0) {
                        temp_r6_1415 = (var_r30_1350 * 4) & 0x3C;
                        temp_r8_1420 = *(temp_r4_1400 + ((*(&sp30 + temp_r6_1415) * 4) + 0x7A0));
                        if ((u32) (temp_r8_1420 + 0x10000) != -1U) {
                            sp20 = 0.0078125f * (f32) (u8) temp_r8_1420;
                            (*(f32 *) ((u8 *) &spC + 0x18)) = 0.0078125f * (f32) (u8) (temp_r8_1420 >> 8U);
                            sp28 = 0.0078125f * (f32) (u8) (temp_r8_1420 >> 0x10U);
                        }
                        temp_r6_1453 = *(M2C_FIELD(var_r28_1098, void **, 0x2C) + ((*(&sp30 + temp_r6_1415) * 4) + 0x7C0));
                        if ((u32) (temp_r6_1453 + 0x10000) != -1U) {
                            sp10 = 0.0078125f * (f32) (u8) temp_r6_1453;
                            (*(f32 *) ((u8 *) &spC + 0x8)) = 0.0078125f * (f32) (u8) (temp_r6_1453 >> 8U);
                            sp18 = 0.0078125f * (f32) (u8) (temp_r6_1453 >> 0x10U);
                        }
                    }
                    var_f1_1482 = sp20;
                    if (var_f1_1482 == sp10) {

                    } else {
                        var_f1_1482 = MKRand_Float((int *) &spC, var_f1_1482, sp10);
                    }
                    var_f0_1491 = (*(f32 *) ((u8 *) &spC + 0x18));
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r27_1354 + 0x5A0)) = var_f1_1482;
                    if (var_f0_1491 == (*(f32 *) ((u8 *) &spC + 0x8))) {

                    } else {
                        var_f0_1491 = MKRand_Float((int *) &spC, var_f0_1491, (*(f32 *) ((u8 *) &spC + 0x8)));
                    }
                    var_f1_1505 = sp28;
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r27_1354 + 0x5A4)) = var_f0_1491;
                    if (var_f1_1505 == sp18) {

                    } else {
                        var_f1_1505 = MKRand_Float((int *) &spC, var_f1_1505, sp18);
                    }
                    *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r27_1354 + 0x5A8)) = var_f1_1505;
                }
                *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r29_1352 + 0x6A0)) = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
                temp_r4_1528 = M2C_FIELD(var_r28_1098, void **, 0x2C);
                if ((u8) M2C_FIELD(temp_r4_1528, u8 *, 0x800) != 0) {
                    *(temp_r4_1528 + (var_r29_1352 + 0x720)) = *(temp_r4_1528 + ((*(&sp30 + var_r29_1352) * 4) + 0x7E0));
                }
                var_r30_1350 += 1;
                var_r27_1354 += 0x10;
                *(M2C_FIELD(var_r28_1098, void **, 0x2C) + (var_r29_1352 + 0x6E0)) = 0.0f;
                var_r29_1352 += 4;
            } while (var_r30_1350 < 0x10);
            temp_r3_1548 = M2C_FIELD(var_r28_1098, void **, 0x2C);
            temp_f0_1550 = M2C_FIELD(temp_r3_1548, f32 *, 0x30);
            M2C_FIELD(temp_r3_1548, f32 *, 0x804) = (f32) (temp_f0_1550 * temp_f0_1550);
            temp_r3_1553 = M2C_FIELD(var_r28_1098, void **, 0x2C);
            temp_f0_1556 = M2C_FIELD(temp_r3_1553, f32 *, 0x34) - M2C_FIELD(temp_r3_1553, f32 *, 0x30);
            M2C_FIELD(temp_r3_1553, f32 *, 0x808) = (f32) (1.0f / (temp_f0_1556 * temp_f0_1556));
        }
        var_r28_1098 += 0x30;
        goto loop_67;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKGrass_LevelDeinit() {
    MKHeap *temp_r3_1649;
    MKHeap *var_r29_1625;
    MKHeap *var_r4_1621;
    MKModel *temp_r3_1655;
    s32 var_r30_1615;
    s32 var_r31_1616;
    void ***temp_r3_1597;
    void ***var_r31_1591;
    void **temp_r3_1612;
    void *temp_r4_1594;

    var_r31_1591 = grassModelsList;
loop_6:
    temp_r3_1612 = *var_r31_1591;
    if (temp_r3_1612 != NULL) {
        temp_r4_1594 = *temp_r3_1612;
        if (temp_r4_1594 == NULL) {
            temp_r3_1597 = grassModelsList;
            grassModelsList = temp_r3_1597 + 4;
            *var_r31_1591 = *temp_r3_1597;
        } else if ((s32) M2C_FIELD(temp_r4_1594, s32 *, 0x20) == (s32) *MKResource::sWorkingChunkID) {
            MKGrass_RemoveModel((MKModel *) temp_r3_1612);
        }
        var_r31_1591 += 4;
        goto loop_6;
    }
    var_r30_1615 = 0;
    var_r31_1616 = 0;
loop_22:
    if (var_r30_1615 < (s32) gnGrassTypes) {
        var_r4_1621 = M2C_FIELD(&gpGrassTypes[var_r31_1616], MKHeap **, 0x2C);
        if (var_r4_1621 != NULL) {
            var_r29_1625 = NULL;
            if ((s32) *MKResource::sWorkingChunkID == (s32) var_r4_1621->unk20) {
                var_r29_1625 = var_r4_1621;
                M2C_FIELD(&gpGrassTypes[var_r31_1616], u32 *, 0x2C) = (u32) M2C_FIELD(var_r4_1621, u32 *, 0x80C);
            } else if ((u32) M2C_FIELD(var_r4_1621, u32 *, 0x80C) != 0U) {
loop_16:
                temp_r3_1649 = M2C_FIELD(var_r4_1621, MKHeap **, 0x80C);
                if (temp_r3_1649 != NULL) {
                    if ((s32) temp_r3_1649->unk20 == (s32) *MKResource::sWorkingChunkID) {
                        var_r29_1625 = temp_r3_1649;
                        M2C_FIELD(var_r4_1621, MKHeap **, 0x80C) = (MKHeap *) M2C_FIELD(temp_r3_1649, MKHeap **, 0x80C);
                    } else {
                        var_r4_1621 = temp_r3_1649;
                        goto loop_16;
                    }
                }
            }
            if (var_r29_1625 != NULL) {
                temp_r3_1655 = var_r29_1625->unk9C;
                if (temp_r3_1655 != NULL) {
                    MKModel_Destroy(temp_r3_1655);
                }
                var_r29_1625->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
            }
        }
        var_r30_1615 += 1;
        var_r31_1616 += 0x30;
        goto loop_22;
    }
    UpdateDebugMenus();
}
#endif

#if 0 // DRAFT: undefined identifier 'MKGrassType::Data'
void MKGrass_LevelInit() {
    MKIni sp60;
    s8 sp40;
    MKVector4 sp30;
    MKVector4 sp20;
    s32 sp18;
    s32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKGrassType::Data *temp_r3_2180;
    MKGrassType::Data *temp_r3_2199;
    MKGrassType::Data *temp_r3_2280;
    MKGrassType::Data *temp_r3_2304;
    MKGrassType::Data *temp_r3_2410;
    MKGrassType::Data *temp_r4_1712;
    MKGrassType::Data *temp_r4_2419;
    MKGrassType::Data *temp_r5_1785;
    MKGrassType::Data *temp_r5_1804;
    MKGrassType::Data *temp_r5_1807;
    MKGrassType::Data *var_r29_1714;
    MKIniLine *temp_r3_2580;
    MKIniLine *var_r31_1849;
    f32 temp_f1_2422;
    f32 temp_f2_2412;
    f32 temp_f2_2421;
    f32 temp_f3_2424;
    f32 var_f1_2495;
    f32 var_f2_1972;
    f32 var_f2_2063;
    f32 var_f3_1989;
    f32 var_f3_2080;
    f32 var_f4_2006;
    f32 var_f4_2097;
    f32 var_f4_2428;
    f64 temp_f1_2434;
    f64 temp_f1_2440;
    f64 temp_f1_2444;
    s32 temp_r0_1936;
    s32 temp_r0_1964;
    s32 temp_r0_2055;
    s32 temp_r28_1886;
    s32 temp_r29_2566;
    s32 temp_r3_2463;
    s32 var_ctr_1810;
    s32 var_r0_2473;
    s32 var_r27_1885;
    s32 var_r27_1927;
    s32 var_r29_1887;
    s32 var_r29_1928;
    s32 var_r3_1768;
    s32 var_r7_1762;
    s8 *temp_r3_1856;
    s8 *var_r30_1709;

    memset(&MKGrass_pushAwaySpheres, 0, 0x40U);
    memset(&MKGrass_windDirection, 0, 0x10U);
    M2C_FIELD(&MKGrass_windDirection, f32 *, 8) = 1.0f;
    MKHeap::ActivateTempMemOverride();
    sp60.Init("grass_types.ini", 0, NULL);
    MKHeap::DeactivateTempMemOverride();
    var_r30_1709 = (signed char *) (gpGrassTypes);
loop_151:
    if (var_r30_1709 < (void *) (gpGrassTypes + (gnGrassTypes * 0x30))) {
        temp_r4_1712 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
        var_r29_1714 = temp_r4_1712;
loop_3:
        if ((var_r29_1714 != NULL) && (((u8) M2C_FIELD(var_r29_1714, u8 *, 0x98) != 0) || ((s32) M2C_FIELD(var_r29_1714, s32 *, 0x20) != (s32) *MKResource::sWorkingChunkID))) {
            var_r29_1714 = M2C_FIELD(var_r29_1714, MKGrassType::Data **, 0x80C);
            goto loop_3;
        }
        if (var_r29_1714 != NULL) {
            if (var_r29_1714 != temp_r4_1712) {
                CopyTypeData(var_r29_1714, temp_r4_1712);
                M2C_FIELD(var_r29_1714, MKModel **, 0x9C) = MKModel_Create(MKModel_GetName(M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), MKModel **, 0x9C)), NULL, 0, NULL);
                MKModel_BlobPreprocess(M2C_FIELD(var_r29_1714, MKModel **, 0x9C));
                M2C_FIELD(var_r29_1714, u8 *, 0x98) = 1U;
            } else if ((temp_r4_1712 != NULL) && ((u8) M2C_FIELD(temp_r4_1712, u8 *, 0x98) == 0)) {
                M2C_FIELD(temp_r4_1712, s8 *, 0x24) = 1;
                var_r7_1762 = 0;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s32 *, 0x28) = 1;
                var_r3_1768 = 0;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s32 *, 0x2C) = 1;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x30) = 5000.0f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x34) = 10000.0f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x3C) = 1.0f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x40) = 0.0f;
                temp_r5_1785 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                M2C_FIELD(temp_r5_1785, f64 *, 0x48) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
                M2C_FIELD(temp_r5_1785, f64 *, 0x50) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x58) = 1.0f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x5C) = 1.0f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s8 *, 0x60) = 0;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), MKModel **, 0x9C) = NULL;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x64) = 0.8f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x68) = 1.2f;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s32 *, 0x6C) = 0;
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s32 *, 0x70) = 0x168;
                temp_r5_1804 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                M2C_FIELD(temp_r5_1804, f64 *, 0x78) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 0);
                M2C_FIELD(temp_r5_1804, f64 *, 0x80) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 8);
                temp_r5_1807 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                M2C_FIELD(temp_r5_1807, f64 *, 0x88) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 0);
                M2C_FIELD(temp_r5_1807, f64 *, 0x90) = (f64) M2C_FIELD(&MKVector3::one, f64 *, 8);
                var_ctr_1810 = 0x10;
                do {
                    *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + (var_r7_1762 + 0x760)) = 1;
                    *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + (var_r7_1762 + 0x720)) = 1.0f;
                    if (var_r3_1768 < 8) {
                        *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + (var_r7_1762 + 0x7E0)) = 1.0f;
                    }
                    var_r3_1768 += 1;
                    var_r7_1762 += 4;
                    var_ctr_1810 -= 1;
                } while (var_ctr_1810 != 0);
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s8 *, 0x800) = 0;
                memset(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x7A0, -1, 0x20U);
                memset(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x7C0, -1, 0x20U);
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), u8 *, 0x98) = 1U;
                var_r31_1849 = sp60.GotoLine(var_r30_1709, NULL);
                memset(&sp40, 0, 0x20U);
loop_147:
                temp_r3_2580 = var_r31_1849->unkC->GetNextLine(var_r31_1849);
                var_r31_1849 = temp_r3_2580;
                if ((var_r31_1849 != NULL) && (temp_r3_2580->GetSectionName() == NULL)) {
                    temp_r3_1856 = var_r31_1849->GetFieldName();
                    if (temp_r3_1856 != NULL) {
                        if (stricmp"model" == 0) {
                            strncpy(&sp40, var_r31_1849->GetString(0), 0x1FU);
                        } else if (strnicmp(temp_r3_1856, "Copy", 4) == 0) {
                            var_r27_1885 = 0;
                            temp_r28_1886 = var_r31_1849->GetString(0);
                            var_r29_1887 = 0;
loop_24:
                            if (var_r27_1885 >= (s32) gnGrassTypes) {

                            } else if (strcmpi((s8 *) temp_r28_1886, &gpGrassTypes[var_r29_1887]) == 0) {
                                CopyTypeData(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), M2C_FIELD(&gpGrassTypes[var_r29_1887], MKGrassType::Data **, 0x2C));
                                strncpy(&sp40, MKModel_GetName(M2C_FIELD(M2C_FIELD(&gpGrassTypes[var_r29_1887], void **, 0x2C), MKModel **, 0x9C)), 0x1FU);
                            } else {
                                var_r27_1885 += 1;
                                var_r29_1887 += 0x30;
                                goto loop_24;
                            }
                        } else if (stricmp(temp_r3_1856, "Distribution") == 0) {
                            var_r27_1927 = 0;
                            var_r29_1928 = 0;
loop_29:
                            if (var_r27_1927 < 0x10) {
                                if (var_r27_1927 >= (s16) var_r31_1849->unk0) {

                                } else {
                                    var_r31_1849->AsInt(var_r27_1927, (int *) &sp18);
                                    temp_r0_1936 = var_r29_1928 + 0x760;
                                    var_r27_1927 += 1;
                                    var_r29_1928 += 4;
                                    *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + temp_r0_1936) = (s32) (u8) sp18;
                                    goto loop_29;
                                }
                            }
                        } else if (stricmp(temp_r3_1856, "minColorSub") == 0) {
                            var_r31_1849->AsVector4(0, &sp30);
                            temp_r0_1964 = (s32) sp30.unkC;
                            if ((temp_r0_1964 >= 0) && (temp_r0_1964 < 8)) {
                                var_f2_1972 = 128.0f * sp30.unk4;
                                if (var_f2_1972 < 255.0f) {

                                } else {
                                    var_f2_1972 = 255.0f;
                                }
                                if (var_f2_1972 > 0.0f) {

                                } else {
                                    var_f2_1972 = 0.0f;
                                }
                                var_f3_1989 = 128.0f * M2C_BITWISE(f32, sp30);
                                if (var_f3_1989 < 255.0f) {

                                } else {
                                    var_f3_1989 = 255.0f;
                                }
                                if (var_f3_1989 > 0.0f) {

                                } else {
                                    var_f3_1989 = 0.0f;
                                }
                                var_f4_2006 = 128.0f * sp30.unk8;
                                if (var_f4_2006 < 255.0f) {

                                } else {
                                    var_f4_2006 = 255.0f;
                                }
                                if (var_f4_2006 > 0.0f) {

                                } else {
                                    var_f4_2006 = 0.0f;
                                }
                                *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + ((temp_r0_1964 * 4) + 0x7A0)) = (((((s32) var_f2_1972 << 8) & 0xFF00 & ~0xFF) | ((s32) var_f3_1989 & 0xFF)) & ~0xFF0000) | (((s32) var_f4_2006 << 0x10) & 0xFF0000);
                                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s8 *, 0x800) = 1;
                            }
                        } else if (stricmp(temp_r3_1856, "maxColorSub") == 0) {
                            var_r31_1849->AsVector4(0, &sp20);
                            temp_r0_2055 = (s32) sp20.unkC;
                            if ((temp_r0_2055 >= 0) && (temp_r0_2055 < 8)) {
                                var_f2_2063 = 128.0f * sp20.unk4;
                                if (var_f2_2063 < 255.0f) {

                                } else {
                                    var_f2_2063 = 255.0f;
                                }
                                if (var_f2_2063 > 0.0f) {

                                } else {
                                    var_f2_2063 = 0.0f;
                                }
                                var_f3_2080 = 128.0f * M2C_BITWISE(f32, sp20);
                                if (var_f3_2080 < 255.0f) {

                                } else {
                                    var_f3_2080 = 255.0f;
                                }
                                if (var_f3_2080 > 0.0f) {

                                } else {
                                    var_f3_2080 = 0.0f;
                                }
                                var_f4_2097 = 128.0f * sp20.unk8;
                                if (var_f4_2097 < 255.0f) {

                                } else {
                                    var_f4_2097 = 255.0f;
                                }
                                if (var_f4_2097 > 0.0f) {

                                } else {
                                    var_f4_2097 = 0.0f;
                                }
                                *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + ((temp_r0_2055 * 4) + 0x7C0)) = (((((s32) var_f2_2063 << 8) & 0xFF00 & ~0xFF) | ((s32) var_f3_2080 & 0xFF)) & ~0xFF0000) | (((s32) var_f4_2097 << 0x10) & 0xFF0000);
                                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s8 *, 0x800) = 1;
                            }
                        } else if (stricmp(temp_r3_1856, "movementSub") == 0) {
                            sp14 = -1;
                            if ((var_r31_1849->AsFloat(0, &sp10) != 0) && (var_r31_1849->AsInt(1, (int *) &sp14) != 0) && (sp14 >= 0) && (sp14 < 8)) {
                                *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + ((sp14 * 4) + 0x7E0)) = sp10;
                                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), s8 *, 0x800) = 1;
                            }
                        } else if (stricmp(temp_r3_1856, "highDetailRadius") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x30);
                            temp_r3_2180 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                            M2C_FIELD(temp_r3_2180, f32 *, 0x30) = (f32) (M2C_FIELD(temp_r3_2180, f32 *, 0x30) * 100.0f);
                        } else if (stricmp(temp_r3_1856, "maxVisibleRadius") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x34);
                            temp_r3_2199 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                            M2C_FIELD(temp_r3_2199, f32 *, 0x34) = (f32) (M2C_FIELD(temp_r3_2199, f32 *, 0x34) * 100.0f);
                        } else if (stricmp(temp_r3_1856, "density") == 0) {
                            var_r31_1849->AsInt(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x28);
                        } else if (stricmp(temp_r3_1856, "clumpSize") == 0) {
                            var_r31_1849->AsInt(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x2C);
                        } else if (stricmp(temp_r3_1856, "minScale") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x64);
                        } else if (stricmp(temp_r3_1856, "maxScale") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x68);
                        } else if (stricmp(temp_r3_1856, "minRotation") == 0) {
                            var_r31_1849->AsInt(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x6C);
loop_97:
                            temp_r3_2280 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                            if ((s32) M2C_FIELD(temp_r3_2280, s32 *, 0x6C) < 0) {
                                M2C_FIELD(temp_r3_2280, s32 *, 0x6C) = (s32) (M2C_FIELD(temp_r3_2280, s32 *, 0x6C) + 0x168);
                                goto loop_97;
                            }
                        } else if (stricmp(temp_r3_1856, "maxRotation") == 0) {
                            var_r31_1849->AsInt(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x70);
loop_102:
                            temp_r3_2304 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                            if ((s32) M2C_FIELD(temp_r3_2304, s32 *, 0x70) < 0) {
                                M2C_FIELD(temp_r3_2304, s32 *, 0x70) = (s32) (M2C_FIELD(temp_r3_2304, s32 *, 0x70) + 0x168);
                                goto loop_102;
                            }
                        } else if (stricmp(temp_r3_1856, "minColor") == 0) {
                            var_r31_1849->AsVector3(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x78);
                        } else if (stricmp(temp_r3_1856, "maxColor") == 0) {
                            var_r31_1849->AsVector3(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x88);
                        } else if (stricmp(temp_r3_1856, "movement") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x38);
                        } else if (stricmp(temp_r3_1856, "animSpeed") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x3C);
                        } else if (stricmp(temp_r3_1856, "animSpeedRange") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x40);
                        } else if (stricmp(temp_r3_1856, "upVector") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x48);
                            if (var_r31_1849->AsFloat(1, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x4C) != 0) {
                                var_r31_1849->AsFloat(2, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x50);
                                var_r31_1849->AsFloat(3, &spC);
                            } else {
                                temp_r3_2410 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                                temp_f2_2412 = (f32) M2C_FIELD(temp_r3_2410, f64 *, 0x48);
                                M2C_FIELD(temp_r3_2410, f64 *, 0x48) = 0.0f;
                                M2C_FIELD(temp_r3_2410, f32 *, 0x4C) = temp_f2_2412;
                                M2C_FIELD(temp_r3_2410, f64 *, 0x50) = 0.0f;
                                spC = 1.0f;
                            }
                            temp_r4_2419 = M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C);
                            temp_f2_2421 = (f32) M2C_FIELD(temp_r4_2419, f64 *, 0x48);
                            temp_f1_2422 = M2C_FIELD(temp_r4_2419, f32 *, 0x4C);
                            temp_f3_2424 = (f32) M2C_FIELD(temp_r4_2419, f64 *, 0x50);
                            var_f4_2428 = (temp_f3_2424 * temp_f3_2424) + ((temp_f2_2421 * temp_f2_2421) + (temp_f1_2422 * temp_f1_2422));
                            if (var_f4_2428 > 0.000001f) {
                                if (var_f4_2428 > 0.0f) {
                                    temp_f1_2434 = __frsqrte(var_f4_2428);
                                    temp_f1_2440 = 0.5 * temp_f1_2434 * -(((f64) var_f4_2428 * (temp_f1_2434 * temp_f1_2434)) - 3.0);
                                    temp_f1_2444 = 0.5 * temp_f1_2440 * -(((f64) var_f4_2428 * (temp_f1_2440 * temp_f1_2440)) - 3.0);
                                    var_f4_2428 = (f32) ((f64) var_f4_2428 * (0.5 * temp_f1_2444 * -(((f64) var_f4_2428 * (temp_f1_2444 * temp_f1_2444)) - 3.0)));
                                } else if (var_f4_2428 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_2428 = __float_nan;
                                } else {
                                    sp8 = var_f4_2428;
                                    temp_r3_2463 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                    switch (temp_r3_2463) { /* irregular */
                                    case 0x7F800000:
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_2473 = 1;
                                        } else {
                                            var_r0_2473 = 2;
                                        }
                                        break;
                                    case 0x0:
                                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                            var_r0_2473 = 5;
                                        } else {
                                            var_r0_2473 = 3;
                                        }
                                        break;
                                    default:
                                        var_r0_2473 = 4;
                                        break;
                                    }
                                    if (var_r0_2473 == 1) {
                                        var_f4_2428 = __float_nan;
                                    }
                                }
                                var_f1_2495 = 1.0f / var_f4_2428;
                            } else {
                                var_f1_2495 = 0.0f;
                            }
                            M2C_FIELD(temp_r4_2419, f64 *, 0x48) = (f32) ((f32) M2C_FIELD(temp_r4_2419, f64 *, 0x48) * var_f1_2495);
                            M2C_FIELD(temp_r4_2419, f32 *, 0x4C) = (f32) (M2C_FIELD(temp_r4_2419, f32 *, 0x4C) * var_f1_2495);
                            M2C_FIELD(temp_r4_2419, f64 *, 0x50) = (f32) ((f32) M2C_FIELD(temp_r4_2419, f64 *, 0x50) * var_f1_2495);
                            M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), f32 *, 0x54) = spC;
                        } else if (stricmp(temp_r3_1856, "pushAwayScale") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x58);
                        } else if (stricmp(temp_r3_1856, "normalFacing") == 0) {
                            var_r31_1849->AsBool(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x60);
                        } else if (stricmp(temp_r3_1856, "visibilityScale") == 0) {
                            var_r31_1849->AsFloat(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + 0x5C);
                        } else if (strnicmp(temp_r3_1856, "color", 5) == 0) {
                            temp_r29_2566 = atoi(temp_r3_1856 + 5) * 0x10;
                            var_r31_1849->AsVector3(0, M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + (temp_r29_2566 + 0x5A0));
                            *(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C) + (temp_r29_2566 + 0x5AC)) = 1.0f;
                        }
                    }
                    goto loop_147;
                }
                M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), MKModel **, 0x9C) = MKModel_Create(&sp40, NULL, 0, NULL);
                MKModel_BlobPreprocess(M2C_FIELD(M2C_FIELD(var_r30_1709, MKGrassType::Data **, 0x2C), MKModel **, 0x9C));
            }
        }
        var_r30_1709 += 0x30;
        goto loop_151;
    }
    MKGrass_ProcessTypes(NULL);
    sp60.Deinit();
    UpdateDebugMenus();
}
#endif

#if 0 // DRAFT: illegal operand
u8 MKGrass_Enable(bool arg0) {
    u8 temp_r0_2621;

    temp_r0_2621 = (unsigned char) (MKGrass_bEnable);
    MKGrass_bEnable = arg0;
    return temp_r0_2621;
}
#endif

#if 0 // DRAFT: illegal function definition
void CopyTypeData(MKGrassType::Data *arg0, const MKGrassType::Data *arg1) {
    M2C_FIELD(arg0, u8 *, 0x24) = (u8) M2C_FIELD(arg1, u8 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 0x2C);
    M2C_FIELD(arg0, f32 *, 0x30) = (f32) M2C_FIELD(arg1, f32 *, 0x30);
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) M2C_FIELD(arg1, f32 *, 0x34);
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) M2C_FIELD(arg1, f32 *, 0x38);
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) M2C_FIELD(arg1, f32 *, 0x3C);
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) M2C_FIELD(arg1, f32 *, 0x40);
    M2C_FIELD(arg0, f64 *, 0x48) = (f64) M2C_FIELD(arg1, f64 *, 0x48);
    M2C_FIELD(arg0, f64 *, 0x50) = (f64) M2C_FIELD(arg1, f64 *, 0x50);
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) M2C_FIELD(arg1, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg1, f32 *, 0x5C);
    M2C_FIELD(arg0, u8 *, 0x60) = (u8) M2C_FIELD(arg1, u8 *, 0x60);
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) M2C_FIELD(arg1, f32 *, 0x64);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) M2C_FIELD(arg1, f32 *, 0x68);
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg1, s32 *, 0x6C);
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) M2C_FIELD(arg1, s32 *, 0x70);
    M2C_FIELD(arg0, f64 *, 0x78) = (f64) M2C_FIELD(arg1, f64 *, 0x78);
    M2C_FIELD(arg0, f64 *, 0x80) = (f64) M2C_FIELD(arg1, f64 *, 0x80);
    M2C_FIELD(arg0, f64 *, 0x88) = (f64) M2C_FIELD(arg1, f64 *, 0x88);
    M2C_FIELD(arg0, f64 *, 0x90) = (f64) M2C_FIELD(arg1, f64 *, 0x90);
    M2C_FIELD(arg0, f32 *, 0x804) = (f32) M2C_FIELD(arg1, f32 *, 0x804);
    M2C_FIELD(arg0, f32 *, 0x808) = (f32) M2C_FIELD(arg1, f32 *, 0x808);
    memcpy(arg0 + 0xA0, arg1 + 0xA0, 0x400U);
    memcpy(arg0 + 0x4A0, arg1 + 0x4A0, 0x100U);
    memcpy(arg0 + 0x5A0, arg1 + 0x5A0, 0x100U);
    memcpy(arg0 + 0x6A0, arg1 + 0x6A0, 0x40U);
    memcpy(arg0 + 0x6E0, arg1 + 0x6E0, 0x40U);
    memcpy(arg0 + 0x760, arg1 + 0x760, 0x40U);
}
#endif

#if 0 // DRAFT: type mismatch 'void ***' and 'long *'
void MKGrass_DeinitModule() {
    s8 *temp_r31_2744;
    void ***temp_r31_2722;
    void ***temp_r3_2721;

    do {
        temp_r3_2721 = grassModelsList;
        temp_r31_2722 = temp_r3_2721 - 4;
        grassModelsList = temp_r31_2722;
    } while ((u32) M2C_FIELD(temp_r3_2721, u32 *, -4) != 0U);
    if (temp_r31_2722 != &gEmptyPtrList) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2722, NULL, 0);
        } else {
            free((u8 *) temp_r31_2722);
        }
    }
    temp_r31_2744 = (signed char *) (gpGrassTypes);
    grassModelsList = NULL;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2744, NULL, 0);
    } else {
        free((u8 *) temp_r31_2744);
    }
    gpGrassTypes = NULL;
}
#endif

void UpdateDebugMenus() {

}

#if 0 // DRAFT: ')' expected
void MKGrass_InitModule() {
    MKIni sp8;
    MKIniLine *temp_r3_2889;
    MKIniLine *temp_r3_2926;
    MKIniLine *var_r28_2807;
    MKIniLine *var_r28_2853;
    s32 temp_r0_2865;
    s32 temp_r27_2895;
    s32 temp_r28_2828;
    s32 temp_r28_2947;
    s32 var_ctr_2975;
    s32 var_ctr_3010;
    s32 var_r26_2894;
    s32 var_r29_2896;
    s32 var_r30_2882;
    s32 var_r31_2880;
    s8 *temp_r4_2863;
    u8 *var_r3_2836;
    u8 *var_r3_2963;
    u8 *var_r3_2998;

    if (MKIni::Exists"grass_types.ini" == 0) {
        gnGrassTypes = 0;
        MKGrass_bEnable = 0;
    } else {
        MKHeap::ActivateTempMemOverride();
        sp8.Init("grass_types.ini", 0, NULL);
        MKHeap::DeactivateTempMemOverride();
        gnGrassTypes = 0;
        var_r28_2807 = sp8.GotoLine(NULL, NULL);
loop_6:
        if (var_r28_2807 != NULL) {
            if (var_r28_2807->GetSectionName() != NULL) {
                gnGrassTypes += 1;
            }
            var_r28_2807 = var_r28_2807->unkC->GetNextLine(var_r28_2807);
            goto loop_6;
        }
        if ((s32) gnGrassTypes != 0) {
            temp_r28_2828 = gnGrassTypes * 0x30;
            if (MKHeap::Current() != NULL) {
                var_r3_2836 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_2828, NULL, 0);
            } else {
                var_r3_2836 = malloc(temp_r28_2828);
            }
            gpGrassTypes = (s8 *) var_r3_2836;
            memset(var_r3_2836, 0, gnGrassTypes * 0x30);
            gnGrassTypes = 0;
            var_r28_2853 = sp8.GotoLine(NULL, NULL);
loop_15:
            if (var_r28_2853 != NULL) {
                if (var_r28_2853->GetSectionName() != NULL) {
                    temp_r4_2863 = var_r28_2853->GetSectionName();
                    temp_r0_2865 = gnGrassTypes * 0x30;
                    gnGrassTypes += 1;
                    strncpy(&gpGrassTypes[temp_r0_2865], temp_r4_2863, 0x1FU);
                }
                var_r28_2853 = var_r28_2853->unkC->GetNextLine(var_r28_2853);
                goto loop_15;
            }
            var_r31_2880 = 0;
            var_r30_2882 = 0;
loop_26:
            if (var_r31_2880 < (s32) gnGrassTypes) {
                temp_r3_2889 = sp8.GotoLine(&gpGrassTypes[var_r30_2882], "overlay");
                if (temp_r3_2889 != NULL) {
                    var_r26_2894 = 0;
                    temp_r27_2895 = temp_r3_2889->GetString(0);
                    var_r29_2896 = 0;
loop_22:
                    if (var_r26_2894 < (s32) gnGrassTypes) {
                        if (strcmpi((s8 *) temp_r27_2895, &gpGrassTypes[var_r29_2896]) == 0) {
                            M2C_FIELD(&gpGrassTypes[var_r30_2882], s8 **, 0x20) = &gpGrassTypes[var_r29_2896];
                            M2C_FIELD(&gpGrassTypes[var_r29_2896], s8 *, 0x28) = 1;
                        } else {
                            var_r26_2894 += 1;
                            var_r29_2896 += 0x30;
                            goto loop_22;
                        }
                    }
                }
                temp_r3_2926 = sp8.GotoLine(&gpGrassTypes[var_r30_2882], "seed");
                if (temp_r3_2926 != NULL) {
                    temp_r3_2926->AsInt(0, (int *) &M2C_FIELD(&gpGrassTypes[var_r30_2882], s32 *, 0x24));
                }
                var_r31_2880 += 1;
                var_r30_2882 += 0x30;
                goto loop_26;
            }
        }
        sp8.Deinit();
    }
    temp_r28_2947 = M2C_FIELD(&gMKDefaults, s32 *, 0x8C);
    if (temp_r28_2947 == 0) {
        grassModelsList = &gEmptyPtrList + 4;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_2963 = ((MKHeap *) (MKHeap::Current()))->Alloc((temp_r28_2947 + 2) * 4, NULL, 0);
        } else {
            var_r3_2963 = malloc((temp_r28_2947 + 2) * 4);
        }
        grassModelsList = (void ***) var_r3_2963;
        *var_r3_2963 = 0;
        var_ctr_2975 = temp_r28_2947;
        if (temp_r28_2947 > 0) {
            do {
                grassModelsList += 4;
                M2C_FIELD(grassModelsList, s32 *, 4) = 0xDEADBEEF;
                var_ctr_2975 -= 1;
            } while (var_ctr_2975 != 0);
        }
        grassModelsList += 4;
        M2C_FIELD(grassModelsList, s32 *, 4) = 0;
    }
    if (MKHeap::Current() != NULL) {
        var_r3_2998 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x148, NULL, 0);
    } else {
        var_r3_2998 = malloc(0x148);
    }
    drawQueue = (MKModel ***) var_r3_2998;
    drawQueue = (MKModel ***) (var_r3_2998 + 0xF0);
    M2C_FIELD(var_r3_2998, s32 *, 0xF0) = 0;
    var_ctr_3010 = 0x14;
    do {
        drawQueue += 4;
        M2C_FIELD(drawQueue, u8 **, 4) = var_r3_2998;
        var_r3_2998 += 0xC;
        var_ctr_3010 -= 1;
    } while (var_ctr_3010 != 0);
    drawQueue += 4;
    M2C_FIELD(drawQueue, u8 **, 4) = NULL;
}
#endif

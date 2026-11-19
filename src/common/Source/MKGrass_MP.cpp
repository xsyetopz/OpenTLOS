#include "common/Source/MKGrass_MP.h"
#include "common/Source/Animation.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/OmniLight.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKShockWave_MP.h"
#include "common/Source/MKView.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
void *realloc(void *, s32);                         /* extern */
s32 strcmpi(s8 *, s32);                             /* extern */
extern f32 MKGrass_cameraPos;
#if 0 // DRAFT: identifier 'MKGrass_pushAwaySpheres' redeclared was declared as: 'unsigned char[64]' now declared as: 'long'
extern M2C_UNK MKGrass_pushAwaySpheres;
#endif
#if 0 // DRAFT: identifier 'MKGrass_windDirection' redeclared was declared as: 'MKHeap' now declared as: 'long'
extern M2C_UNK MKGrass_windDirection;
#endif
extern s32 blobCount;
extern s32 gpGrassTypes;
static MKModel_Blob blobs[0x49];
static MKModel_Blob *pBlob = blobs;

void MKGrass_FlushSubObject(MKGrassType *arg0) {
    if ((s32) blobCount != 0) {
        MKModel_BlobDraw(M2C_FIELD(arg0->unk2C, MKModel **, 0x9C), blobCount, blobs);
        blobCount = 0;
        pBlob = blobs;
    }
}

#if 0 // DRAFT: illegal operand
void MKGrass_DrawSubObject(const Frustum &arg0, const MKModel *arg1, const MKAttachment *arg2, MKGrassType *arg3, GrassSubObject *arg4, bool arg5, int arg6, OmniLight **arg7) {
    f32 *sp238;
    MKVector3 *sp234;
    void *sp230;
    s32 sp22C;
    s32 sp228;
    f64 sp220;
    f32 sp218;
    GrassVertex sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    GrassVertex sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    Matrix sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    MKVector3 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp14;
    Frustum *sp10;
    GrassStrip *var_r26_162;
    MKVector3 *var_r4_130;
    MeshChunkExplorer *temp_r22_210;
    f32 temp_f0_106;
    f32 temp_f0_289;
    f32 temp_f0_471;
    f32 temp_f0_510;
    f32 temp_f0_737;
    f32 temp_f0_812;
    f32 temp_f0_869;
    f32 temp_f0_886;
    f32 temp_f0_903;
    f32 temp_f10_728;
    f32 temp_f10_734;
    f32 temp_f12_712;
    f32 temp_f14_680;
    f32 temp_f15_678;
    f32 temp_f16_661;
    f32 temp_f17_659;
    f32 temp_f18_658;
    f32 temp_f1_401;
    f32 temp_f1_467;
    f32 temp_f1_506;
    f32 temp_f21_669;
    f32 temp_f23_705;
    f32 temp_f24_675;
    f32 temp_f25_709;
    f32 temp_f2_554;
    f32 temp_f2_596;
    f32 temp_f30_161;
    f32 temp_f3_235;
    f32 temp_f3_405;
    f32 temp_f3_553;
    f32 temp_f4_278;
    f32 temp_f4_408;
    f32 temp_f4_445;
    f32 temp_f4_560;
    f32 temp_f5_436;
    f32 temp_f5_547;
    f32 temp_f5_561;
    f32 temp_f5_716;
    f32 temp_f6_242;
    f32 temp_f6_441;
    f32 temp_f6_524;
    f32 temp_f6_730;
    f32 temp_f7_248;
    f32 temp_f7_438;
    f32 temp_f7_523;
    f32 temp_f7_559;
    f32 temp_f7_647;
    f32 temp_f7_715;
    f32 temp_f8_443;
    f32 temp_f8_522;
    f32 temp_f8_548;
    f32 temp_f8_731;
    f32 temp_f9_446;
    f32 temp_f9_525;
    f32 temp_f9_542;
    f32 temp_f9_714;
    f32 var_f0_112;
    f32 var_f11_759;
    f32 var_f14_415;
    f32 var_f19_664;
    f32 var_f20_662;
    f32 var_f29_345;
    f32 var_f6_638;
    f32 var_f6_866;
    f32 var_f6_883;
    f32 var_f6_900;
    f64 *temp_r3_192;
    f64 *var_r23_196;
    f64 *var_r3_236;
    f64 temp_f0_138;
    f64 temp_f14_743;
    f64 temp_f14_749;
    f64 temp_f14_753;
    f64 temp_f1_274;
    f64 temp_f4_520;
    s16 var_r19_398;
    s16 var_r6_626;
    s32 temp_r0_636;
    s32 temp_r14_612;
    s32 temp_r19_633;
    s32 temp_r3_601;
    s32 temp_r5_591;
    s32 temp_r6_599;
    s32 temp_r6_634;
    s32 temp_r8_772;
    s32 var_ctr_103;
    s32 var_ctr_717;
    s32 var_r10_660;
    s32 var_r20_357;
    s32 var_r21_215;
    s32 var_r24_184;
    s32 var_r25_163;
    s32 var_r3_99;
    s32 var_r4_101;
    s32 var_r4_588;
    s32 var_r4_782;
    s32 var_r5_176;
    s32 var_r7_629;
    s32 var_r9_652;
    u16 temp_r4_219;
    void *temp_r27_82;
    void *temp_r3_648;
    void *temp_r3_725;
    void *temp_r3_826;
    void *temp_r4_650;
    void *temp_r5_628;

    temp_r27_82 = arg3->unk2C;
    sp10 = (Frustum *) (&arg0);
    if ((u8) M2C_FIELD(temp_r27_82, u8 *, 0x25) == 0) {
        var_r3_99 = 0;
        var_r4_101 = 0;
        var_ctr_103 = 4;
        do {
            temp_f0_106 = M2C_FIELD((&MKGrass_pushAwaySpheres + var_r4_101), f32 *, 0xC);
            if (temp_f0_106 != 0.0f) {
                var_f0_112 = 2.0f * M2C_FIELD(temp_r27_82, f32 *, 0x58) * (1.0f / temp_f0_106);
            } else {
                var_f0_112 = 0.0f;
            }
            *(blobs + 0x1800 + var_r3_99) = var_f0_112;
            var_r3_99 += 4;
            var_r4_101 += 0x10;
            var_ctr_103 -= 1;
        } while (var_ctr_103 != 0);
        MKModel_BlobBegin(M2C_FIELD(temp_r27_82, MKModel **, 0x9C));
        blobCount = 0;
        if (M2C_FIELD(temp_r27_82, f32 *, 0x38) == 0.0f) {
            var_r4_130 = &MKVector3::zero;
        } else {
            temp_f0_138 = M2C_FIELD(&MKGrass_windDirection, f64 *, 0) * (f64) M2C_FIELD(&MKGrass_windDirection, f32 *, 0xC);
            sp38 = temp_f0_138;
            var_r4_130 = (MKVector3 *) &spC8;
            spC8 = temp_f0_138;
            sp40 = M2C_FIELD(&MKGrass_windDirection, f32 *, 8) * M2C_FIELD(&MKGrass_windDirection, f32 *, 0xC);
            spD0 = (f64) sp40;
        }
        M2C_FIELD(blobs, f64 *, 0x1810) = (f64) M2C_FIELD(var_r4_130, f64 *, 0);
        M2C_FIELD(blobs, f64 *, 0x1818) = (f64) M2C_FIELD(var_r4_130, f64 *, 8);
        M2C_FIELD(temp_r27_82, u8 *, 0x25) = 1U;
    }
    sp218 = MKView_GetCameraMatrix()->unk0;
    temp_f30_161 = MKView_GetCameraMatrix()->unk8;
    var_r26_162 = arg4->unk8;
    var_r25_163 = 9;
    if ((arg6 != 0) || ((u8) M2C_FIELD(arg3->unk2C, u8 *, 0x60) != 0)) {
        var_r25_163 = 9 | 2;
    }
    if (MKModel_IsAtIdentity(arg1) != 0) {
        var_r5_176 = 0;
    } else {
        var_r5_176 = MKModel_GetWorldMatrix(arg1);
    }
    var_r24_184 = var_r5_176;
    if (arg2 != NULL) {
        MKAttachment_CalculateMatrix(arg2, &sp130, (Matrix *) var_r5_176);
        var_r24_184 = (s32) &sp130;
    }
    temp_r3_192 = MKModel_GetColor(arg1);
    var_r23_196 = temp_r3_192;
    if (memcmp(temp_r3_192, &MKVector4::one, 0x10U) == 0) {
        var_r23_196 = NULL;
    }
    MKModel_ExploreBegin(arg1);
    sp234 = &MKVector3::up;
    temp_r22_210 = M2C_ERROR(/* Read from unset register $r3 */);
    sp230 = blobs + 0x1810;
    var_r21_215 = 0;
    sp22C = -1;
loop_90:
    if (var_r21_215 < (s32) arg4->unk2) {
        temp_r4_219 = var_r26_162->unk14;
        if ((s32) temp_r4_219 != sp22C) {
            sp22C = (s32) temp_r4_219;
            MKModel_ExploreMeshChunk(temp_r22_210, (s32) temp_r4_219, (s32) arg4->unk0, var_r25_163);
        } else {
            MKModel_ExploreNextStrip(temp_r22_210);
        }
        if ((u32) var_r24_184 != 0U) {
            temp_f3_235 = var_r26_162->unk4;
            var_r3_236 = &spB8;
            temp_f6_242 = var_r26_162->unk0;
            temp_f7_248 = var_r26_162->unk8;
            sp58 = M2C_FIELD(var_r24_184, f32 *, 0x30) + ((temp_f7_248 * M2C_FIELD(var_r24_184, f32 *, 0x20)) + ((temp_f6_242 * M2C_FIELD(var_r24_184, f32 *, 0)) + (temp_f3_235 * M2C_FIELD(var_r24_184, f32 *, 0x10))));
            sp5C = M2C_FIELD(var_r24_184, f32 *, 0x34) + ((temp_f7_248 * M2C_FIELD(var_r24_184, f32 *, 0x24)) + ((temp_f6_242 * M2C_FIELD(var_r24_184, f32 *, 4)) + (temp_f3_235 * M2C_FIELD(var_r24_184, f32 *, 0x14))));
            sp60 = M2C_FIELD(var_r24_184, f32 *, 0x38) + ((temp_f7_248 * M2C_FIELD(var_r24_184, f32 *, 0x28)) + ((temp_f6_242 * M2C_FIELD(var_r24_184, f32 *, 8)) + (temp_f3_235 * M2C_FIELD(var_r24_184, f32 *, 0x18))));
            spB8 = (f64) sp58;
            spC0 = (f64) sp60;
        } else {
            var_r3_236 = (f64 *) var_r26_162;
        }
        temp_f1_274 = M2C_FIELD(var_r3_236, f64 *, 0);
        spD8 = temp_f1_274;
        spE0 = M2C_FIELD(var_r3_236, f64 *, 8);
        temp_f4_278 = var_r26_162->unkC;
        sp48 = temp_f1_274 - M2C_FIELD(&MKGrass_cameraPos, f64 *, 0);
        spA8 = sp48;
        temp_f0_289 = M2C_FIELD(temp_r27_82, f32 *, 0x34) + temp_f4_278;
        sp50 = (f32) spE0 - M2C_FIELD(&MKGrass_cameraPos, f32 *, 8);
        spB0 = (f64) sp50;
        if (!((((f32) spB0 * (f32) spB0) + (((f32) spA8 * (f32) spA8) + ((*(f32 *) ((u8 *) &spA8 + 0x4)) * (*(f32 *) ((u8 *) &spA8 + 0x4))))) > (temp_f0_289 * temp_f0_289)) && (sp10->IsVisible(*((MKVector3 *) &spD8), temp_f4_278 * M2C_FIELD(temp_r27_82, f32 *, 0x5C)) != 0)) {
            memset(&sp170, 0, 0x90U);
            MKModel_ExploreCalculateVertex(temp_r22_210, 0);
            CalculateGrassVertex(&sp1A0, var_r26_162, temp_r22_210, arg5, arg6, arg7, (MKVector4 *) var_r23_196, (Matrix *) var_r24_184);
            MKModel_ExploreCalculateVertex(temp_r22_210, 1);
            CalculateGrassVertex(&sp1D0, var_r26_162, temp_r22_210, arg5, arg6, arg7, (MKVector4 *) var_r23_196, (Matrix *) var_r24_184);
            if ((u8) temp_r22_210->unkC != 0) {
                var_f29_345 = -(1.0f - M2C_FIELD(temp_r27_82, f32 *, 0x54));
            } else {
                var_f29_345 = 1.0f - M2C_FIELD(temp_r27_82, f32 *, 0x54);
            }
            sp220 = 0.0;
            var_r20_357 = 2;
            sp238 = &MKGrass_cameraPos;
loop_88:
            if (var_r20_357 < (s32) temp_r22_210->unk8) {
                sp170 = M2C_BITWISE(f64, sp1A0);
                sp178 = sp1A0.unk8;
                sp180 = sp1A0.unk10;
                sp188 = sp1A0.unk18;
                sp190 = sp1C0;
                sp198 = sp1C8;
                sp1A0 = sp1D0.unk0;
                sp1A0.unk8 = sp1D0.unk8;
                sp1A0.unk10 = sp1D0.unk10;
                sp1A0.unk18 = sp1D0.unk18;
                sp1C0 = sp1F0;
                sp1C8 = sp1F8;
                MKModel_ExploreCalculateVertex(temp_r22_210, var_r20_357);
                var_r19_398 = CalculateGrassVertex(&sp1D0, var_r26_162, temp_r22_210, arg5, arg6, arg7, (MKVector4 *) var_r23_196, (Matrix *) var_r24_184);
                temp_f1_401 = (*(f32 *) ((u8 *) &sp1D0 + 0x4)) - M2C_FIELD(&MKGrass_cameraPos, f32 *, 4);
                temp_f3_405 = (f32) M2C_FIELD(&sp1D0, f64 *, 0) - *sp238;
                temp_f4_408 = (f32) sp1D0.unk8 - M2C_FIELD(&MKGrass_cameraPos, f32 *, 8);
                var_f14_415 = 1.0f - (M2C_FIELD(temp_r27_82, f32 *, 0x808) * (((temp_f4_408 * temp_f4_408) + ((temp_f3_405 * temp_f3_405) + (temp_f1_401 * temp_f1_401))) - M2C_FIELD(temp_r27_82, f32 *, 0x804)));
                if (!(var_f14_415 <= (f32) sp220)) {
                    if (var_f14_415 > 1.0f) {
                        var_f14_415 = 1.0f;
                    }
                    if (sp10->IsVisible(*((MKVector3 *) &sp1D0), var_r26_162->unk10) != 0) {
                        temp_f5_436 = M2C_BITWISE(f32, sp1A0) - (f32) sp170;
                        temp_f7_438 = (f32) M2C_FIELD(&sp1D0, f64 *, 0) - (f32) sp170;
                        temp_f6_441 = (*(f32 *) ((u8 *) &sp1A0 + 0x4)) - (*(f32 *) ((u8 *) &sp170 + 0x4));
                        temp_f8_443 = (*(f32 *) ((u8 *) &sp1D0 + 0x4)) - (*(f32 *) ((u8 *) &sp170 + 0x4));
                        temp_f4_445 = (f32) sp1A0.unk8 - (f32) sp178;
                        temp_f9_446 = (f32) sp1D0.unk8 - (f32) sp178;
                        if ((u8) M2C_FIELD(temp_r27_82, u8 *, 0x60) == 0) {
                            sp28 = (temp_f8_443 * temp_f4_445) - (temp_f9_446 * temp_f6_441);
                            sp2C = (temp_f9_446 * temp_f5_436) - (temp_f7_438 * temp_f4_445);
                            sp30 = (temp_f7_438 * temp_f6_441) - (temp_f8_443 * temp_f5_436);
                            sp98 = (f64) sp28;
                            spA0 = (f64) sp30;
                            temp_f1_467 = ((f32) spA0 * (f32) spA0) + (((f32) sp98 * (f32) sp98) + ((*(f32 *) ((u8 *) &sp98 + 0x4)) * (*(f32 *) ((u8 *) &sp98 + 0x4))));
                            if (temp_f1_467 > 0.000001f) {
                                temp_f0_471 = (f32) __frsqrte(temp_f1_467);
                                sp100.unk0 = (f32) sp98 * temp_f0_471;
                                sp100.unk4 = (*(f32 *) ((u8 *) &sp98 + 0x4)) * temp_f0_471;
                                sp100.unk8 = (f32) spA0 * temp_f0_471;
                            }
                            sp68 = ((MKVector3 *) (((u8 *) temp_r27_82) + 0x48))->operator*(M2C_FIELD(temp_r27_82, f32 *, 0x54));
                            sp78 = sp100.operator*(var_f29_345);
                            sp18 = sp78 + M2C_BITWISE(f64, sp68);
                            sp88 = sp18;
                            sp20 = sp78.unk8 + sp68.unk8;
                            sp90 = (f64) sp20;
                            temp_f1_506 = ((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * (*(f32 *) ((u8 *) &sp88 + 0x4))));
                            if (temp_f1_506 > 0.000001f) {
                                temp_f0_510 = (f32) __frsqrte(temp_f1_506);
                                sp100.unk0 = (f32) sp88 * temp_f0_510;
                                sp100.unk4 = (*(f32 *) ((u8 *) &sp88 + 0x4)) * temp_f0_510;
                                sp100.unk8 = (f32) sp90 * temp_f0_510;
                            }
                            temp_f4_520 = -sp100.unk8;
                            temp_f8_522 = sp100.unk4;
                            temp_f7_523 = sp100.unk8;
                            temp_f6_524 = (f32) temp_f4_520;
                            temp_f9_525 = sp100.unk0;
                            sp110 = 0.0f;
                            sp114 = (f32) temp_f4_520;
                            sp118 = sp100.unk4;
                            sp11C = 0.0f;
                            spF0 = (temp_f6_524 * temp_f7_523) - (sp100.unk4 * temp_f8_522);
                            spF4 = (sp100.unk4 * temp_f9_525) - (0.0f * temp_f7_523);
                            spF8 = (0.0f * temp_f8_522) - (temp_f6_524 * temp_f9_525);
                        } else {
                            temp_f9_542 = M2C_FIELD(temp_r27_82, f32 *, 0x48);
                            sp100.unk0 = temp_f9_542;
                            temp_f5_547 = sp234->unk4;
                            temp_f8_548 = M2C_FIELD(temp_r27_82, f32 *, 0x4C);
                            temp_f3_553 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp190 + 0x4))) - (temp_f5_547 * (f32) sp190);
                            temp_f2_554 = sp234->unk8;
                            sp100.unk4 = temp_f8_548;
                            temp_f7_559 = M2C_FIELD(temp_r27_82, f32 *, 0x50);
                            temp_f4_560 = (temp_f2_554 * (f32) sp190) - (MKVector3::up.unk0 * (f32) sp198);
                            temp_f5_561 = (temp_f5_547 * (f32) sp198) - (temp_f2_554 * (*(f32 *) ((u8 *) &sp190 + 0x4)));
                            sp100.unk8 = temp_f7_559;
                            sp100.unkC = 0.0f;
                            spF0 = temp_f5_561;
                            spF4 = temp_f4_560;
                            spF8 = temp_f3_553;
                            sp110 = (temp_f4_560 * temp_f7_559) - (temp_f3_553 * temp_f8_548);
                            sp114 = (temp_f3_553 * temp_f9_542) - (temp_f5_561 * temp_f7_559);
                            sp118 = (temp_f5_561 * temp_f8_548) - (temp_f4_560 * temp_f9_542);
                        }
                        spFC = 0.0f;
                        sp100.unkC = 0.0f;
                        sp11C = 0.0f;
                        sp120 = 0.0f;
                        sp124 = 0.0f;
                        sp128 = 0.0f;
                        sp12C = 1.0f;
                        var_r4_588 = M2C_FIELD(temp_r27_82, s32 *, 0x28);
                        temp_r5_591 = M2C_FIELD(temp_r27_82, s32 *, 0x2C);
                        temp_f2_596 = var_f14_415 * (f32) var_r4_588;
                        temp_r6_599 = (s32) temp_f2_596;
                        temp_r3_601 = temp_r6_599 + 1;
                        sp228 = temp_r6_599 * temp_r5_591;
                        if (temp_r3_601 < var_r4_588) {
                            var_r4_588 = temp_r3_601;
                        }
                        temp_r14_612 = var_r4_588 * temp_r5_591;
                        if ((s32) (blobCount + temp_r14_612) > 0x40) {
                            MKModel_BlobDraw(M2C_FIELD(temp_r27_82, MKModel **, 0x9C), blobCount, blobs);
                            pBlob = blobs;
                            blobCount = 0;
                        }
                        var_r6_626 = var_r19_398;
                        temp_r5_628 = blobs + 0x1800;
                        var_r7_629 = 0;
loop_86:
                        if (var_r7_629 < temp_r14_612) {
                            temp_r19_633 = var_r19_398 & 0x3F;
                            temp_r6_634 = var_r6_626 & 0xF;
                            temp_r0_636 = temp_r19_633 & 0xF;
                            if (var_r7_629 >= sp228) {
                                var_f6_638 = temp_f2_596 - (f32) temp_r6_599;
                            } else {
                                var_f6_638 = 1.0f;
                            }
                            temp_f7_647 = *(temp_r27_82 + ((temp_r0_636 * 4) + 0x6E0));
                            temp_r3_648 = ((u8 *) temp_r27_82) + (temp_r19_633 * 0x10);
                            temp_r4_650 = ((u8 *) temp_r27_82) + (temp_r6_634 * 0x10);
                            var_r9_652 = 0;
                            temp_f18_658 = M2C_FIELD(temp_r3_648, f32 *, 0xA0);
                            temp_f17_659 = M2C_FIELD(temp_r3_648, f32 *, 0xA4);
                            var_r10_660 = 0;
                            temp_f16_661 = M2C_FIELD(temp_r3_648, f32 *, 0xA8);
                            var_f20_662 = (var_f6_638 * (sp218 * temp_f7_647)) + (f32) M2C_FIELD(blobs, f64 *, 0x1810);
                            var_f19_664 = (var_f6_638 * (temp_f30_161 * temp_f7_647)) + M2C_FIELD(sp230, f32 *, 8);
                            pBlob->unk50 = (s32) M2C_FIELD(temp_r3_648, u8 *, 0xAC);
                            temp_f21_669 = var_f6_638 * M2C_FIELD(temp_r4_650, f32 *, 0x4AC);
                            temp_f24_675 = M2C_FIELD(temp_r4_650, f32 *, 0x4A8) * temp_f21_669;
                            temp_f15_678 = M2C_FIELD(temp_r4_650, f32 *, 0x4A0) * temp_f21_669;
                            temp_f14_680 = M2C_FIELD(temp_r4_650, f32 *, 0x4A4) * temp_f21_669;
                            temp_f23_705 = (spF4 * temp_f15_678) + (sp114 * temp_f24_675);
                            temp_f25_709 = temp_f21_669 * sp100.unk4;
                            temp_f12_712 = (spF4 * temp_f14_680) + (sp114 * temp_f15_678);
                            temp_f9_714 = (temp_f16_661 * (f32) M2C_FIELD(&sp1D0, f64 *, 0)) + ((temp_f18_658 * (f32) sp170) + (temp_f17_659 * M2C_BITWISE(f32, sp1A0)));
                            temp_f7_715 = (temp_f16_661 * (*(f32 *) ((u8 *) &sp1D0 + 0x4))) + ((temp_f18_658 * (*(f32 *) ((u8 *) &sp170 + 0x4))) + (temp_f17_659 * (*(f32 *) ((u8 *) &sp1A0 + 0x4))));
                            temp_f5_716 = (temp_f16_661 * (f32) sp1D0.unk8) + ((temp_f18_658 * (f32) sp178) + (temp_f17_659 * (f32) sp1A0.unk8));
                            var_ctr_717 = 4;
                            do {
                                if (*(temp_r5_628 + var_r10_660) != 0.0f) {
                                    temp_r3_725 = &MKGrass_pushAwaySpheres + var_r9_652;
                                    temp_f10_728 = temp_f7_715 - M2C_FIELD(temp_r3_725, f32 *, 4);
                                    temp_f6_730 = temp_f9_714 - M2C_FIELD(temp_r3_725, f32 *, 0);
                                    temp_f8_731 = temp_f5_716 - M2C_FIELD(temp_r3_725, f32 *, 8);
                                    temp_f10_734 = (temp_f8_731 * temp_f8_731) + ((temp_f6_730 * temp_f6_730) + (temp_f10_728 * temp_f10_728));
                                    if (temp_f10_734 > 0.000001f) {
                                        temp_f0_737 = M2C_FIELD(temp_r3_725, f32 *, 0xC);
                                        if (temp_f10_734 < (temp_f0_737 * temp_f0_737)) {
                                            if (temp_f10_734 > 0.0f) {
                                                temp_f14_743 = __frsqrte(temp_f10_734);
                                                temp_f14_749 = 0.5 * temp_f14_743 * -(((f64) temp_f10_734 * (temp_f14_743 * temp_f14_743)) - 3.0);
                                                temp_f14_753 = 0.5 * temp_f14_749 * -(((f64) temp_f10_734 * (temp_f14_749 * temp_f14_749)) - 3.0);
                                                var_f11_759 = (f32) ((f64) temp_f10_734 * (0.5 * temp_f14_753 * -(((f64) temp_f10_734 * (temp_f14_753 * temp_f14_753)) - 3.0)));
                                            } else if (temp_f10_734 < M2C_BITWISE(f32, 0.0)) {
                                                var_f11_759 = __float_nan;
                                            } else {
                                                sp14 = temp_f10_734;
                                                temp_r8_772 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                                                switch (temp_r8_772) { /* irregular */
                                                case 0x7F800000:
                                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                                        var_r4_782 = 1;
                                                    } else {
                                                        var_r4_782 = 2;
                                                    }
                                                    break;
                                                case 0x0:
                                                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                                        var_r4_782 = 5;
                                                    } else {
                                                        var_r4_782 = 3;
                                                    }
                                                    break;
                                                default:
                                                    var_r4_782 = 4;
                                                    break;
                                                }
                                                if (var_r4_782 == 1) {
                                                    var_f11_759 = __float_nan;
                                                } else {
                                                    var_f11_759 = temp_f10_734;
                                                }
                                            }
                                            temp_f0_812 = (1.0f / var_f11_759) * (M2C_FIELD(temp_r3_725, f32 *, 0xC) - var_f11_759) * *(temp_r5_628 + var_r10_660);
                                            var_f20_662 += temp_f6_730 * temp_f0_812;
                                            var_f19_664 += temp_f8_731 * temp_f0_812;
                                        }
                                    }
                                }
                                var_r9_652 += 0x10;
                                var_r10_660 += 4;
                                var_ctr_717 -= 1;
                            } while (var_ctr_717 != 0);
                            temp_r3_826 = ((u8 *) temp_r27_82) + (temp_r0_636 * 0x10);
                            pBlob->unk0 = (temp_f23_705 * var_f20_662) + ((spF0 * temp_f15_678) + (sp110 * temp_f24_675));
                            pBlob->unk4 = temp_f23_705;
                            pBlob->unk8 = (temp_f23_705 * var_f19_664) + ((spF8 * temp_f15_678) + (sp118 * temp_f24_675));
                            pBlob->unkC = 0.0f;
                            pBlob->unk10 = (temp_f25_709 * var_f20_662) + (temp_f21_669 * sp100.unk0);
                            pBlob->unk14 = temp_f25_709;
                            pBlob->unk18 = (temp_f25_709 * var_f19_664) + (temp_f21_669 * sp100.unk8);
                            pBlob->unk1C = 0.0f;
                            pBlob->unk20 = (temp_f12_712 * var_f20_662) + ((spF0 * temp_f14_680) + (sp110 * temp_f15_678));
                            pBlob->unk24 = temp_f12_712;
                            pBlob->unk28 = (temp_f12_712 * var_f19_664) + ((spF8 * temp_f14_680) + (sp118 * temp_f15_678));
                            pBlob->unk2C = 0.0f;
                            pBlob->unk30 = temp_f9_714;
                            pBlob->unk34 = temp_f7_715;
                            pBlob->unk38 = temp_f5_716;
                            pBlob->unk3C = 1.0f;
                            var_f6_866 = 1.0f;
                            temp_f0_869 = M2C_FIELD(temp_r3_826, f32 *, 0x5A0) * ((temp_f16_661 * (f32) sp1D0.unk10) + ((temp_f18_658 * (f32) sp180) + (temp_f17_659 * (f32) sp1A0.unk10)));
                            if (var_f6_866 < temp_f0_869) {

                            } else {
                                var_f6_866 = temp_f0_869;
                            }
                            pBlob->unk40 = var_f6_866;
                            var_f6_883 = 1.0f;
                            temp_f0_886 = M2C_FIELD(temp_r3_826, f32 *, 0x5A4) * ((temp_f16_661 * (*(f32 *) ((u8 *) &sp1D0 + 0x14))) + ((temp_f18_658 * (*(f32 *) ((u8 *) &sp180 + 0x4))) + (temp_f17_659 * (*(f32 *) ((u8 *) &sp1A0 + 0x14)))));
                            if (var_f6_883 < temp_f0_886) {

                            } else {
                                var_f6_883 = temp_f0_886;
                            }
                            pBlob->unk44 = var_f6_883;
                            var_f6_900 = 1.0f;
                            temp_f0_903 = M2C_FIELD(temp_r3_826, f32 *, 0x5A8) * ((temp_f16_661 * (f32) sp1D0.unk18) + ((temp_f18_658 * (f32) sp188) + (temp_f17_659 * (f32) sp1A0.unk18)));
                            if (var_f6_900 < temp_f0_903) {

                            } else {
                                var_f6_900 = temp_f0_903;
                            }
                            var_r7_629 += 1;
                            var_r19_398 = temp_r19_633 + 1;
                            var_r6_626 = temp_r6_634 + 3;
                            pBlob->unk48 = var_f6_900;
                            pBlob->unk4C = 1.0f;
                            pBlob = (MKModel_Blob *) &pBlob[1].unkC;
                            blobCount += 1;
                            goto loop_86;
                        }
                    }
                }
                var_f29_345 = -var_f29_345;
                var_r20_357 += 1;
                goto loop_88;
            }
        }
        var_r21_215 += 1;
        var_r26_162 += 0x18;
        goto loop_90;
    }
    MKModel_ExploreEnd(temp_r22_210);
}
#endif

void MKGrass_InitDraw() {

}

u32 OptimiseGrassTypeData(MKModel *arg0, GrassUsedType *arg1) {
    s32 dataBytes;
    s32 subObjectCount;
    s32 srcOffset;
    s32 dstOffset;
    s32 usedCount;
    s32 size;
    s32 alignedSize;
    s32 headerBytes;
    u32 totalBytes;
    u8 *oldTable;
    u8 *table;
    u8 *cursor;
    u8 *entry;
    u8 *dst;

    /* Pass 1: header bytes per sub-object, each data block 16-aligned plus 16. */
    dataBytes = 0;
    subObjectCount = 0;
    srcOffset = 0;
    oldTable = (u8 *) arg1->unk4;
    while (subObjectCount < MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0)) {
        subObjectCount += 1;
        size = M2C_FIELD(oldTable + srcOffset, s32 *, 4);
        srcOffset += 0xC;
        dataBytes = ((size + 0xF) & 0xFFFFFFF0) + dataBytes + 0x10;
    }

    headerBytes = ((arg1->unk2 * 0xC) + 0xF) & 0xFFFFFFF0;
    if (MKHeap::Current() != NULL) {
        table = (u8 *) ((MKHeap *) (MKHeap::Current()))->Alloc(headerBytes + dataBytes, NULL, 0);
    } else {
        table = (u8 *) malloc(headerBytes + dataBytes);
    }
    arg1->unk4 = table;
    totalBytes = headerBytes + dataBytes;
    memset(arg1->unk4, 0, totalBytes);

    /* Pass 2: compact the used entries and move their data behind the header table. */
    cursor = table + headerBytes;
    srcOffset = 0;
    dstOffset = 0;
    usedCount = 0;
    while (usedCount < (s32) arg1->unk2) {
        entry = oldTable + srcOffset;
        if (M2C_FIELD(entry, u16 *, 2) != 0) {
            dst = table + dstOffset;
            M2C_FIELD(dst, u16 *, 0) = M2C_FIELD(entry, u16 *, 0);
            M2C_FIELD(dst, u16 *, 2) = M2C_FIELD(entry, u16 *, 2);
            M2C_FIELD(dst, u32 *, 4) = M2C_FIELD(entry, u32 *, 4);
            M2C_FIELD(dst, void **, 8) = M2C_FIELD(entry, void **, 8);
            M2C_FIELD(dst, u8 **, 8) = cursor;
            alignedSize = (M2C_FIELD(entry, u32 *, 4) + 0xF) & 0xFFFFFFF0;
            M2C_FIELD(dst, s32 *, 4) = alignedSize;
            cursor += M2C_FIELD(dst, s32 *, 4);
            memcpy(M2C_FIELD(dst, void **, 8), M2C_FIELD(entry, void **, 8), M2C_FIELD(entry, u32 *, 4));
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Main()))->TFree(M2C_FIELD(entry, void **, 8), NULL, 0);
            } else {
                free(M2C_FIELD(entry, void **, 8));
            }
            usedCount += 1;
            dstOffset += 0xC;
        }
        srcOffset += 0xC;
    }

    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(oldTable, NULL, 0);
    } else {
        free(oldTable);
    }
    return totalBytes;
}

#if 0 // DRAFT: function call 'MKMaterial_GetEffectType(MKMaterial *, signed char **)' does not match 'MKMaterial_GetEffectType(MKMaterial *, const char **)'
void CreateGrassStripData(MKModel *arg0, MeshChunkExplorer *arg1, GrassUsedType *arg2) {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s8 *sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r3_1245;
    MKVector3 *temp_r3_1274;
    MKVector3 *temp_r3_1360;
    f32 temp_f3_1284;
    f32 var_f29_1241;
    f32 var_f4_1291;
    f32 var_f4_1416;
    f64 temp_f0_1248;
    f64 temp_f0_1372;
    f64 temp_f0_1400;
    f64 temp_f1_1247;
    f64 temp_f1_1294;
    f64 temp_f1_1300;
    f64 temp_f1_1304;
    f64 temp_f1_1419;
    f64 temp_f1_1425;
    f64 temp_f1_1429;
    s16 temp_r25_1144;
    s16 temp_r26_1148;
    s32 temp_r20_1219;
    s32 temp_r3_1323;
    s32 temp_r3_1448;
    s32 var_r0_1333;
    s32 var_r0_1458;
    s32 var_r21_1246;
    s32 var_r23_1172;
    s32 var_r24_1175;
    s32 var_r27_1168;
    void *temp_r21_1220;
    void *temp_r22_1205;
    void *temp_r3_1394;
    void *var_r3_1157;
    void *var_r3_1229;

    temp_r25_1144 = MKModel_GetNmbrOfMaterials(arg0);
    temp_r26_1148 = MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0);
    if (MKHeap::Current() != NULL) {
        var_r3_1157 = ((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r26_1148 * 0xC, NULL, 0, 0U);
    } else {
        var_r3_1157 = malloc(temp_r26_1148 * 0xC);
    }
    arg2->unk4 = var_r3_1157;
    memset(arg2->unk4, 0, temp_r26_1148 * 0xC);
    var_r27_1168 = 0;
    arg2->unk2 = 0;
    var_r23_1172 = 0;
loop_59:
    if (var_r23_1172 < temp_r26_1148) {
        var_r24_1175 = 0;
loop_57:
        if (var_r24_1175 < temp_r25_1144) {
            MKMaterial_GetEffectType(MKModel_GetMaterial(arg0, var_r24_1175, 0U), &sp10);
            if ((strcmpi() == 0) && (strcmpi(sp10, gpGrassTypes + (arg2->unk0 * 0x30)) == 0)) {
                MKModel_ExploreMeshChunk(arg1, var_r24_1175, var_r23_1172, 1);
                if ((s32) arg1->unk4 != 0) {
                    temp_r22_1205 = arg2->unk4 + var_r27_1168;
                    if ((u16) M2C_FIELD(temp_r22_1205, u16 *, 2) == 0) {
                        M2C_FIELD(temp_r22_1205, s16 *, 0) = (s16) var_r23_1172;
                        arg2->unk2 += 1;
                    }
                    M2C_FIELD(temp_r22_1205, s32 *, 4) = (s32) ((M2C_FIELD(temp_r22_1205, u16 *, 2) + arg1->unk4) * 0x18);
                    temp_r20_1219 = M2C_FIELD(temp_r22_1205, s32 *, 4);
                    temp_r21_1220 = M2C_FIELD(temp_r22_1205, void **, 8);
                    if (MKHeap::Current() != NULL) {
                        var_r3_1229 = ((MKHeap *) (MKHeap::Main()))->TReAlloc(temp_r21_1220, temp_r20_1219, NULL, 0);
                    } else {
                        var_r3_1229 = realloc(temp_r21_1220, temp_r20_1219);
                    }
                    M2C_FIELD(temp_r22_1205, void **, 8) = var_r3_1229;
loop_55:
                    if ((s32) arg1->unk0 < (s32) arg1->unk4) {
                        var_f29_1241 = 0.0f;
                        MKModel_ExploreCalculateVertex(arg1, 0);
                        temp_r3_1245 = arg1->unk18;
                        var_r21_1246 = 1;
                        temp_f1_1247 = M2C_FIELD(temp_r3_1245, f64 *, 0);
                        temp_f0_1248 = M2C_FIELD(temp_r3_1245, f64 *, 8);
                        sp98 = temp_f1_1247;
                        spA0 = temp_f0_1248;
                        spA8 = temp_f1_1247;
                        spB0 = temp_f0_1248;
                        spB8 = temp_f1_1247;
                        spC0 = temp_f0_1248;
loop_36:
                        if (var_r21_1246 < (s32) arg1->unk8) {
                            MKModel_ExploreCalculateVertex(arg1, var_r21_1246);
                            sp88 = Min(*((MKVector3 *) &spB8), *arg1->unk18);
                            *(MKVector3 *) &spB8 = sp88;
                            sp78 = Max(*((MKVector3 *) &spB8), *arg1->unk18);
                            temp_r3_1274 = arg1->unk18;
                            *(MKVector3 *) &spA8 = sp78;
                            sp98 -= M2C_FIELD(temp_r3_1274, f64 *, 0);
                            temp_f3_1284 = (f32) spA0 - temp_r3_1274->unk8;
                            spA0 = temp_f3_1284;
                            var_f4_1291 = (temp_f3_1284 * temp_f3_1284) + (((f32) sp98 * (f32) sp98) + ((*(f32 *) ((u8 *) &sp98 + 0x4)) * (*(f32 *) ((u8 *) &sp98 + 0x4))));
                            if (var_f4_1291 > 0.0f) {
                                temp_f1_1294 = __frsqrte(var_f4_1291);
                                temp_f1_1300 = 0.5 * temp_f1_1294 * -(((f64) var_f4_1291 * (temp_f1_1294 * temp_f1_1294)) - 3.0);
                                temp_f1_1304 = 0.5 * temp_f1_1300 * -(((f64) var_f4_1291 * (temp_f1_1300 * temp_f1_1300)) - 3.0);
                                var_f4_1291 = (f32) ((f64) var_f4_1291 * (0.5 * temp_f1_1304 * -(((f64) var_f4_1291 * (temp_f1_1304 * temp_f1_1304)) - 3.0)));
                            } else if (var_f4_1291 < M2C_BITWISE(f32, 0.0)) {
                                var_f4_1291 = __float_nan;
                            } else {
                                spC = var_f4_1291;
                                temp_r3_1323 = M2C_BITWISE(s32, spC) & 0x7F800000;
                                switch (temp_r3_1323) { /* switch 1; irregular */
                                case 0x7F800000:    /* switch 1 */
                                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                        var_r0_1333 = 1;
                                    } else {
                                        var_r0_1333 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 1 */
                                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                        var_r0_1333 = 5;
                                    } else {
                                        var_r0_1333 = 3;
                                    }
                                    break;
                                default:            /* switch 1 */
                                    var_r0_1333 = 4;
                                    break;
                                }
                                if (var_r0_1333 == 1) {
                                    var_f4_1291 = __float_nan;
                                }
                            }
                            if (var_f29_1241 > var_f4_1291) {

                            } else {
                                var_f29_1241 = var_f4_1291;
                            }
                            temp_r3_1360 = arg1->unk18;
                            var_r21_1246 += 1;
                            sp98 = M2C_FIELD(temp_r3_1360, f64 *, 0);
                            spA0 = M2C_FIELD(temp_r3_1360, f64 *, 8);
                            goto loop_36;
                        }
                        temp_f0_1372 = spB8 + spA8;
                        sp18 = temp_f0_1372;
                        sp58 = temp_f0_1372;
                        sp20 = (f32) spC0 + (f32) spB0;
                        sp60 = (f64) sp20;
                        sp28 = temp_f0_1372 * 5.222099017e-315;
                        sp68 = sp28;
                        sp30 = (f32) sp60 * 0.5f;
                        temp_r3_1394 = M2C_FIELD(temp_r22_1205, void **, 8) + (M2C_FIELD(temp_r22_1205, u16 *, 2) * 0x18);
                        M2C_FIELD(temp_r3_1394, f64 *, 0) = sp28;
                        M2C_FIELD(temp_r3_1394, f64 *, 8) = (f64) sp30;
                        sp70 = (f64) sp30;
                        temp_f0_1400 = spB8 + spA8;
                        sp38 = temp_f0_1400;
                        sp48 = temp_f0_1400;
                        sp40 = (f32) spC0 + (f32) spB0;
                        sp50 = (f64) sp40;
                        var_f4_1416 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4))));
                        if (var_f4_1416 > 0.0f) {
                            temp_f1_1419 = __frsqrte(var_f4_1416);
                            temp_f1_1425 = 0.5 * temp_f1_1419 * -(((f64) var_f4_1416 * (temp_f1_1419 * temp_f1_1419)) - 3.0);
                            temp_f1_1429 = 0.5 * temp_f1_1425 * -(((f64) var_f4_1416 * (temp_f1_1425 * temp_f1_1425)) - 3.0);
                            var_f4_1416 = (f32) ((f64) var_f4_1416 * (0.5 * temp_f1_1429 * -(((f64) var_f4_1416 * (temp_f1_1429 * temp_f1_1429)) - 3.0)));
                        } else if (var_f4_1416 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1416 = __float_nan;
                        } else {
                            sp8 = var_f4_1416;
                            temp_r3_1448 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_1448) { /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1458 = 1;
                                } else {
                                    var_r0_1458 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1458 = 5;
                                } else {
                                    var_r0_1458 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_1458 = 4;
                                break;
                            }
                            if (var_r0_1458 == 1) {
                                var_f4_1416 = __float_nan;
                            }
                        }
                        *(M2C_FIELD(temp_r22_1205, void **, 8) + ((M2C_FIELD(temp_r22_1205, u16 *, 2) * 0x18) + 0xC)) = 0.5f * var_f4_1416;
                        *(M2C_FIELD(temp_r22_1205, void **, 8) + ((M2C_FIELD(temp_r22_1205, u16 *, 2) * 0x18) + 0x10)) = var_f29_1241;
                        *(M2C_FIELD(temp_r22_1205, void **, 8) + ((M2C_FIELD(temp_r22_1205, u16 *, 2) * 0x18) + 0x14)) = (s16) var_r24_1175;
                        *(M2C_FIELD(temp_r22_1205, void **, 8) + ((M2C_FIELD(temp_r22_1205, u16 *, 2) * 0x18) + 0x16)) = (s16) arg1->unk0;
                        M2C_FIELD(temp_r22_1205, u16 *, 2) = (u16) (M2C_FIELD(temp_r22_1205, u16 *, 2) + 1);
                        MKModel_ExploreNextStrip(arg1);
                        goto loop_55;
                    }
                }
            }
            var_r24_1175 += 1;
            goto loop_57;
        }
        var_r23_1172 += 1;
        var_r27_1168 += 0xC;
        goto loop_59;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk18'
s16 CalculateGrassVertex(GrassVertex *arg0, GrassStrip *arg1, MeshChunkExplorer *arg2, bool arg3, int arg4, OmniLight **arg5, const MKVector4 *arg6, const Matrix *arg7) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;
    MKVector3 *temp_r4_1548;
    f32 temp_f3_1558;
    f32 temp_f6_1565;
    f32 temp_f7_1571;
    f64 *temp_r3_1603;
    f64 *var_r3_1559;
    f64 *var_r3_1613;
    f64 temp_f0_1611;
    s16 temp_r23_1556;
    s32 var_r22_1637;
    s32 var_r27_1638;

    temp_r4_1548 = arg2->unk18;
    temp_r23_1556 = (s16) M2C_BITWISE(u16, temp_r4_1548->unk0) + (s16) M2C_BITWISE(u16, temp_r4_1548->unk8);
    if (arg7 != NULL) {
        temp_f3_1558 = temp_r4_1548->unk4;
        var_r3_1559 = &sp48;
        temp_f6_1565 = temp_r4_1548->unk0;
        temp_f7_1571 = temp_r4_1548->unk8;
        sp18 = arg7->unk30 + ((temp_f7_1571 * arg7->unk20) + ((temp_f6_1565 * arg7->unk0) + (temp_f3_1558 * arg7->unk10)));
        sp1C = arg7->unk34 + ((temp_f7_1571 * arg7->unk24) + ((temp_f6_1565 * arg7->unk4) + (temp_f3_1558 * arg7->unk14)));
        sp20 = arg7->unk38 + ((temp_f7_1571 * arg7->unk28) + ((temp_f6_1565 * arg7->unk8) + (temp_f3_1558 * arg7->unk18)));
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
    } else {
        var_r3_1559 = (f64 *) temp_r4_1548;
    }
    arg0->unk0 = M2C_FIELD(var_r3_1559, f64 *, 0);
    arg0->unk8 = M2C_FIELD(var_r3_1559, f64 *, 8);
    if (arg6 != NULL) {
        temp_r3_1603 = arg2->unk24;
        sp8 = M2C_FIELD(arg6, f64 *, 0) * M2C_FIELD(temp_r3_1603, f64 *, 0);
        temp_f0_1611 = M2C_FIELD(arg6, f64 *, 8) * M2C_FIELD(temp_r3_1603, f64 *, 8);
        sp10 = temp_f0_1611;
        var_r3_1613 = &sp38;
        sp38 = sp8;
        sp40 = temp_f0_1611;
    } else {
        var_r3_1613 = arg2->unk24;
    }
    arg0->unk10 = M2C_FIELD(var_r3_1613, f64 *, 0);
    arg0->unk18 = M2C_FIELD(var_r3_1613, f64 *, 8);
    if (arg3 != 0) {
        M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + MKShockWave_Height(*((MKVector3 *) arg0)));
    }
    if (arg4 != 0) {
        var_r22_1637 = 0;
        var_r27_1638 = 0;
loop_11:
        if (var_r22_1637 < arg4) {
            ((OmniLight *) &sp28)->CalculateColor(*(*(arg5 + var_r27_1638)), *((MKVector3 *) arg0));
            arg0->unk10 += sp28;
            arg0->unk18 += sp30;
            var_r22_1637 += 1;
            var_r27_1638 += 4;
            goto loop_11;
        }
        M2C_FIELD(arg0, f32 *, 0x1C) = 1.0f;
    }
    return temp_r23_1556;
}
#endif

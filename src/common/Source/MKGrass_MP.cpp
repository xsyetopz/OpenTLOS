#include "common/Source/MKGrass_MP.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKGrass.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/OmniLight.h"
#include "common/gc/MKModel_GC.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKShockWave_MP.h"
#include "common/Source/MKView.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
void *realloc(void *, s32);                         /* extern */
s32 strcmpi(s8 *, s32);                             /* extern */
extern f32 MKGrass_cameraPos;
#if 0 // DRAFT: identifier 'MKGrass_pushAwaySpheres' redeclared
extern M2C_UNK MKGrass_pushAwaySpheres;
#endif
#if 0 // DRAFT: identifier 'MKGrass_windDirection' redeclared
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

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void MKGrass_DrawSubObject(const Frustum &arg0, const MKModel *arg1, const MKAttachment *arg2, MKGrassType *arg3, GrassSubObject *arg4, bool arg5, int arg6, OmniLight **arg7) {
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
    f64 temp_f14_743;
    f64 temp_f14_749;
    f64 temp_f14_753;
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
    arg_sp10 = &arg0;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f14 */);
            var_r4_130 = (MKVector3 *) &arg_spC8;
            arg_spC8 = arg_sp38;
            arg_sp40 = M2C_FIELD(&MKGrass_windDirection, f32 *, 8) * M2C_FIELD(&MKGrass_windDirection, f32 *, 0xC);
            arg_spD0 = (f64) arg_sp40;
        }
        M2C_FIELD(blobs, f64 *, 0x1810) = (f64) M2C_FIELD(var_r4_130, f64 *, 0);
        M2C_FIELD(blobs, f64 *, 0x1818) = (f64) M2C_FIELD(var_r4_130, f64 *, 8);
        M2C_FIELD(temp_r27_82, u8 *, 0x25) = 1U;
    }
    arg_sp218 = MKView_GetCameraMatrix()->unk0;
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
        MKAttachment_CalculateMatrix(arg2, (Matrix *) &arg_sp130, (Matrix *) var_r5_176);
        var_r24_184 = (s32) &arg_sp130;
    }
    temp_r3_192 = MKModel_GetColor(arg1);
    var_r23_196 = temp_r3_192;
    if (memcmp(temp_r3_192, &MKVector4::one, 0x10U) == 0) {
        var_r23_196 = NULL;
    }
    MKModel_ExploreBegin(arg1);
    arg_sp234 = &MKVector3::up;
    temp_r22_210 = M2C_ERROR(/* Read from unset register $r3 */);
    arg_sp230 = blobs + 0x1810;
    var_r21_215 = 0;
    arg_sp22C = -1;
loop_90:
    if (var_r21_215 < (s32) arg4->unk2) {
        temp_r4_219 = var_r26_162->unk14;
        if ((s32) temp_r4_219 != arg_sp22C) {
            arg_sp22C = (s32) temp_r4_219;
            MKModel_ExploreMeshChunk(temp_r22_210, (s32) temp_r4_219, (s32) arg4->unk0, var_r25_163);
        } else {
            MKModel_ExploreNextStrip(temp_r22_210);
        }
        if ((u32) var_r24_184 != 0U) {
            temp_f3_235 = var_r26_162->unk4;
            var_r3_236 = &arg_spB8;
            temp_f6_242 = var_r26_162->unk0;
            temp_f7_248 = var_r26_162->unk8;
            arg_sp58 = M2C_FIELD(var_r24_184, f32 *, 0x30) + ((temp_f7_248 * M2C_FIELD(var_r24_184, f32 *, 0x20)) + ((temp_f6_242 * M2C_FIELD(var_r24_184, f32 *, 0)) + (temp_f3_235 * M2C_FIELD(var_r24_184, f32 *, 0x10))));
            arg_sp5C = M2C_FIELD(var_r24_184, f32 *, 0x34) + ((temp_f7_248 * M2C_FIELD(var_r24_184, f32 *, 0x24)) + ((temp_f6_242 * M2C_FIELD(var_r24_184, f32 *, 4)) + (temp_f3_235 * M2C_FIELD(var_r24_184, f32 *, 0x14))));
            arg_sp60 = M2C_FIELD(var_r24_184, f32 *, 0x38) + ((temp_f7_248 * M2C_FIELD(var_r24_184, f32 *, 0x28)) + ((temp_f6_242 * M2C_FIELD(var_r24_184, f32 *, 8)) + (temp_f3_235 * M2C_FIELD(var_r24_184, f32 *, 0x18))));
            arg_spB8 = (f64) arg_sp58;
            arg_spC0 = (f64) arg_sp60;
        } else {
            var_r3_236 = (f64 *) var_r26_162;
        }
        arg_spD8 = M2C_FIELD(var_r3_236, f64 *, 0);
        arg_spE0 = M2C_FIELD(var_r3_236, f64 *, 8);
        temp_f4_278 = var_r26_162->unkC;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_spA8 = arg_sp48;
        temp_f0_289 = M2C_FIELD(temp_r27_82, f32 *, 0x34) + temp_f4_278;
        arg_sp50 = (f32) arg_spE0 - M2C_FIELD(&MKGrass_cameraPos, f32 *, 8);
        arg_spB0 = (f64) arg_sp50;
        if (!((((f32) arg_spB0 * (f32) arg_spB0) + (((f32) arg_spA8 * (f32) arg_spA8) + (arg_spAC * arg_spAC))) > (temp_f0_289 * temp_f0_289)) && (arg_sp10->IsVisible(*((MKVector3 *) &arg_spD8), temp_f4_278 * M2C_FIELD(temp_r27_82, f32 *, 0x5C)) != 0)) {
            memset(&arg_sp170, 0, 0x90U);
            MKModel_ExploreCalculateVertex(temp_r22_210, 0);
            CalculateGrassVertex((GrassVertex *) &arg_sp1A0, var_r26_162, temp_r22_210, arg5, arg6, arg7, (MKVector4 *) var_r23_196, (Matrix *) var_r24_184);
            MKModel_ExploreCalculateVertex(temp_r22_210, 1);
            CalculateGrassVertex((GrassVertex *) &arg_sp1D0, var_r26_162, temp_r22_210, arg5, arg6, arg7, (MKVector4 *) var_r23_196, (Matrix *) var_r24_184);
            if ((u8) temp_r22_210->unkC != 0) {
                var_f29_345 = -(1.0f - M2C_FIELD(temp_r27_82, f32 *, 0x54));
            } else {
                var_f29_345 = 1.0f - M2C_FIELD(temp_r27_82, f32 *, 0x54);
            }
            arg_sp220 = 0.0;
            var_r20_357 = 2;
            arg_sp238 = &MKGrass_cameraPos;
loop_88:
            if (var_r20_357 < (s32) temp_r22_210->unk8) {
                arg_sp170 = arg_sp1A0;
                arg_sp178 = arg_sp1A8;
                arg_sp180 = arg_sp1B0;
                arg_sp188 = arg_sp1B8;
                arg_sp190 = arg_sp1C0;
                arg_sp198 = arg_sp1C8;
                arg_sp1A0 = M2C_FIELD(&arg_sp1D0, f64 *, 0);
                arg_sp1A8 = M2C_FIELD(&arg_sp1D0, f64 *, 8);
                arg_sp1B0 = arg_sp1E0;
                arg_sp1B8 = arg_sp1E8;
                arg_sp1C0 = arg_sp1F0;
                arg_sp1C8 = arg_sp1F8;
                MKModel_ExploreCalculateVertex(temp_r22_210, var_r20_357);
                var_r19_398 = CalculateGrassVertex((GrassVertex *) &arg_sp1D0, var_r26_162, temp_r22_210, arg5, arg6, arg7, (MKVector4 *) var_r23_196, (Matrix *) var_r24_184);
                temp_f1_401 = arg_sp1D4 - M2C_FIELD(&MKGrass_cameraPos, f32 *, 4);
                temp_f3_405 = (f32) M2C_FIELD(&arg_sp1D0, f64 *, 0) - *arg_sp238;
                temp_f4_408 = arg_sp1D8 - M2C_FIELD(&MKGrass_cameraPos, f32 *, 8);
                var_f14_415 = 1.0f - (M2C_FIELD(temp_r27_82, f32 *, 0x808) * (((temp_f4_408 * temp_f4_408) + ((temp_f3_405 * temp_f3_405) + (temp_f1_401 * temp_f1_401))) - M2C_FIELD(temp_r27_82, f32 *, 0x804)));
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (var_f14_415 != (f32) arg_sp220) {
                    if (var_f14_415 > 1.0f) {
                        var_f14_415 = 1.0f;
                    }
                    if (arg_sp10->IsVisible(*((MKVector3 *) &arg_sp1D0), var_r26_162->unk10) != 0) {
                        temp_f5_436 = (f32) arg_sp1A0 - (f32) arg_sp170;
                        temp_f7_438 = (f32) M2C_FIELD(&arg_sp1D0, f64 *, 0) - (f32) arg_sp170;
                        temp_f6_441 = arg_sp1A4 - arg_sp174;
                        temp_f8_443 = arg_sp1D4 - arg_sp174;
                        temp_f4_445 = (f32) arg_sp1A8 - (f32) arg_sp178;
                        temp_f9_446 = arg_sp1D8 - (f32) arg_sp178;
                        if ((u8) M2C_FIELD(temp_r27_82, u8 *, 0x60) == 0) {
                            arg_sp28 = (temp_f8_443 * temp_f4_445) - (temp_f9_446 * temp_f6_441);
                            arg_sp2C = (temp_f9_446 * temp_f5_436) - (temp_f7_438 * temp_f4_445);
                            arg_sp30 = (temp_f7_438 * temp_f6_441) - (temp_f8_443 * temp_f5_436);
                            arg_sp98 = (f64) arg_sp28;
                            arg_spA0 = (f64) arg_sp30;
                            temp_f1_467 = ((f32) arg_spA0 * (f32) arg_spA0) + (((f32) arg_sp98 * (f32) arg_sp98) + (arg_sp9C * arg_sp9C));
                            if (temp_f1_467 > 0.000001f) {
                                temp_f0_471 = (f32) __frsqrte(temp_f1_467);
                                M2C_FIELD(&arg_sp100, f32 *, 0) = (f32) ((f32) arg_sp98 * temp_f0_471);
                                M2C_FIELD(&arg_sp100, f32 *, 4) = (f32) (arg_sp9C * temp_f0_471);
                                M2C_FIELD(&arg_sp100, f32 *, 8) = (f32) ((f32) arg_spA0 * temp_f0_471);
                            }
                            arg_sp68.operator*(M2C_FIELD(temp_r27_82, f32 *, 0x54));
                            arg_sp78.operator*(var_f29_345);
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            arg_sp88 = arg_sp18;
                            arg_sp20 = arg_sp80 + arg_sp70;
                            arg_sp90 = (f64) arg_sp20;
                            temp_f1_506 = ((f32) arg_sp90 * (f32) arg_sp90) + (((f32) arg_sp88 * (f32) arg_sp88) + (arg_sp8C * arg_sp8C));
                            if (temp_f1_506 > 0.000001f) {
                                temp_f0_510 = (f32) __frsqrte(temp_f1_506);
                                M2C_FIELD(&arg_sp100, f32 *, 0) = (f32) ((f32) arg_sp88 * temp_f0_510);
                                M2C_FIELD(&arg_sp100, f32 *, 4) = (f32) (arg_sp8C * temp_f0_510);
                                M2C_FIELD(&arg_sp100, f32 *, 8) = (f32) ((f32) arg_sp90 * temp_f0_510);
                            }
                            temp_f4_520 = -arg_sp108;
                            temp_f8_522 = M2C_FIELD(&arg_sp100, f32 *, 4);
                            temp_f7_523 = M2C_FIELD(&arg_sp100, f32 *, 8);
                            temp_f6_524 = (f32) temp_f4_520;
                            temp_f9_525 = M2C_FIELD(&arg_sp100, f32 *, 0);
                            arg_sp110 = 0.0f;
                            arg_sp114 = (f32) temp_f4_520;
                            arg_sp118 = arg_sp104;
                            arg_sp11C = 0.0f;
                            arg_spF0 = (temp_f6_524 * temp_f7_523) - (arg_sp104 * temp_f8_522);
                            arg_spF4 = (arg_sp104 * temp_f9_525) - (0.0f * temp_f7_523);
                            arg_spF8 = (0.0f * temp_f8_522) - (temp_f6_524 * temp_f9_525);
                        } else {
                            temp_f9_542 = M2C_FIELD(temp_r27_82, f32 *, 0x48);
                            M2C_FIELD(&arg_sp100, f32 *, 0) = temp_f9_542;
                            temp_f5_547 = arg_sp234->unk4;
                            temp_f8_548 = M2C_FIELD(temp_r27_82, f32 *, 0x4C);
                            temp_f3_553 = (MKVector3::up.unk0 * arg_sp194) - (temp_f5_547 * (f32) arg_sp190);
                            temp_f2_554 = arg_sp234->unk8;
                            arg_sp104 = temp_f8_548;
                            temp_f7_559 = M2C_FIELD(temp_r27_82, f32 *, 0x50);
                            temp_f4_560 = (temp_f2_554 * (f32) arg_sp190) - (MKVector3::up.unk0 * (f32) arg_sp198);
                            temp_f5_561 = (temp_f5_547 * (f32) arg_sp198) - (temp_f2_554 * arg_sp194);
                            arg_sp108 = temp_f7_559;
                            arg_sp10C = 0.0f;
                            arg_spF0 = temp_f5_561;
                            arg_spF4 = temp_f4_560;
                            arg_spF8 = temp_f3_553;
                            arg_sp110 = (temp_f4_560 * temp_f7_559) - (temp_f3_553 * temp_f8_548);
                            arg_sp114 = (temp_f3_553 * temp_f9_542) - (temp_f5_561 * temp_f7_559);
                            arg_sp118 = (temp_f5_561 * temp_f8_548) - (temp_f4_560 * temp_f9_542);
                        }
                        arg_spFC = 0.0f;
                        arg_sp10C = 0.0f;
                        arg_sp11C = 0.0f;
                        arg_sp120 = 0.0f;
                        arg_sp124 = 0.0f;
                        arg_sp128 = 0.0f;
                        arg_sp12C = 1.0f;
                        var_r4_588 = M2C_FIELD(temp_r27_82, s32 *, 0x28);
                        temp_r5_591 = M2C_FIELD(temp_r27_82, s32 *, 0x2C);
                        temp_f2_596 = var_f14_415 * (f32) var_r4_588;
                        temp_r6_599 = (s32) temp_f2_596;
                        temp_r3_601 = temp_r6_599 + 1;
                        arg_sp228 = temp_r6_599 * temp_r5_591;
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
                            if (var_r7_629 >= arg_sp228) {
                                var_f6_638 = temp_f2_596 - (f32) temp_r6_599;
                            } else {
                                var_f6_638 = 1.0f;
                            }
                            temp_f7_647 = *(temp_r27_82 + ((temp_r0_636 * 4) + 0x6E0));
                            temp_r3_648 = temp_r27_82 + (temp_r19_633 * 0x10);
                            temp_r4_650 = temp_r27_82 + (temp_r6_634 * 0x10);
                            var_r9_652 = 0;
                            temp_f18_658 = M2C_FIELD(temp_r3_648, f32 *, 0xA0);
                            temp_f17_659 = M2C_FIELD(temp_r3_648, f32 *, 0xA4);
                            var_r10_660 = 0;
                            temp_f16_661 = M2C_FIELD(temp_r3_648, f32 *, 0xA8);
                            var_f20_662 = (var_f6_638 * (arg_sp218 * temp_f7_647)) + (f32) M2C_FIELD(blobs, f64 *, 0x1810);
                            var_f19_664 = (var_f6_638 * (temp_f30_161 * temp_f7_647)) + M2C_FIELD(arg_sp230, f32 *, 8);
                            pBlob->unk50 = (s32) M2C_FIELD(temp_r3_648, u8 *, 0xAC);
                            temp_f21_669 = var_f6_638 * M2C_FIELD(temp_r4_650, f32 *, 0x4AC);
                            temp_f24_675 = M2C_FIELD(temp_r4_650, f32 *, 0x4A8) * temp_f21_669;
                            temp_f15_678 = M2C_FIELD(temp_r4_650, f32 *, 0x4A0) * temp_f21_669;
                            temp_f14_680 = M2C_FIELD(temp_r4_650, f32 *, 0x4A4) * temp_f21_669;
                            temp_f23_705 = (arg_spF4 * temp_f15_678) + (arg_sp114 * temp_f24_675);
                            temp_f25_709 = temp_f21_669 * arg_sp104;
                            temp_f12_712 = (arg_spF4 * temp_f14_680) + (arg_sp114 * temp_f15_678);
                            temp_f9_714 = (temp_f16_661 * (f32) M2C_FIELD(&arg_sp1D0, f64 *, 0)) + ((temp_f18_658 * (f32) arg_sp170) + (temp_f17_659 * (f32) arg_sp1A0));
                            temp_f7_715 = (temp_f16_661 * arg_sp1D4) + ((temp_f18_658 * arg_sp174) + (temp_f17_659 * arg_sp1A4));
                            temp_f5_716 = (temp_f16_661 * arg_sp1D8) + ((temp_f18_658 * (f32) arg_sp178) + (temp_f17_659 * (f32) arg_sp1A8));
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
                                                arg_sp14 = temp_f10_734;
                                                temp_r8_772 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                                                switch (temp_r8_772) { /* irregular */
                                                case 0x7F800000:
                                                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                                        var_r4_782 = 1;
                                                    } else {
                                                        var_r4_782 = 2;
                                                    }
                                                    break;
                                                case 0x0:
                                                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
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
                            temp_r3_826 = temp_r27_82 + (temp_r0_636 * 0x10);
                            pBlob->unk0 = (temp_f23_705 * var_f20_662) + ((arg_spF0 * temp_f15_678) + (arg_sp110 * temp_f24_675));
                            pBlob->unk4 = temp_f23_705;
                            pBlob->unk8 = (temp_f23_705 * var_f19_664) + ((arg_spF8 * temp_f15_678) + (arg_sp118 * temp_f24_675));
                            pBlob->unkC = 0.0f;
                            pBlob->unk10 = (temp_f25_709 * var_f20_662) + (temp_f21_669 * M2C_FIELD(&arg_sp100, f32 *, 0));
                            pBlob->unk14 = temp_f25_709;
                            pBlob->unk18 = (temp_f25_709 * var_f19_664) + (temp_f21_669 * arg_sp108);
                            pBlob->unk1C = 0.0f;
                            pBlob->unk20 = (temp_f12_712 * var_f20_662) + ((arg_spF0 * temp_f14_680) + (arg_sp110 * temp_f15_678));
                            pBlob->unk24 = temp_f12_712;
                            pBlob->unk28 = (temp_f12_712 * var_f19_664) + ((arg_spF8 * temp_f14_680) + (arg_sp118 * temp_f15_678));
                            pBlob->unk2C = 0.0f;
                            pBlob->unk30 = temp_f9_714;
                            pBlob->unk34 = temp_f7_715;
                            pBlob->unk38 = temp_f5_716;
                            pBlob->unk3C = 1.0f;
                            var_f6_866 = 1.0f;
                            temp_f0_869 = M2C_FIELD(temp_r3_826, f32 *, 0x5A0) * ((temp_f16_661 * (f32) arg_sp1E0) + ((temp_f18_658 * (f32) arg_sp180) + (temp_f17_659 * (f32) arg_sp1B0)));
                            if (var_f6_866 < temp_f0_869) {

                            } else {
                                var_f6_866 = temp_f0_869;
                            }
                            pBlob->unk40 = var_f6_866;
                            var_f6_883 = 1.0f;
                            temp_f0_886 = M2C_FIELD(temp_r3_826, f32 *, 0x5A4) * ((temp_f16_661 * arg_sp1E4) + ((temp_f18_658 * arg_sp184) + (temp_f17_659 * arg_sp1B4)));
                            if (var_f6_883 < temp_f0_886) {

                            } else {
                                var_f6_883 = temp_f0_886;
                            }
                            pBlob->unk44 = var_f6_883;
                            var_f6_900 = 1.0f;
                            temp_f0_903 = M2C_FIELD(temp_r3_826, f32 *, 0x5A8) * ((temp_f16_661 * (f32) arg_sp1E8) + ((temp_f18_658 * (f32) arg_sp188) + (temp_f17_659 * (f32) arg_sp1B8)));
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

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u32 OptimiseGrassTypeData(MKModel *arg0, GrassUsedType *arg1) {
    MKHeap *temp_r3_1025;
    MKHeap *temp_r3_1083;
    MKHeap *temp_r3_1104;
    s32 temp_r31_1024;
    s32 temp_r3_1009;
    s32 temp_r3_1022;
    s32 var_r24_1003;
    s32 var_r24_1046;
    s32 var_r25_1002;
    s32 var_r25_1047;
    s32 var_r27_1001;
    s32 var_r28_1044;
    u32 temp_r30_1039;
    void *temp_r29_1004;
    void *temp_r31_1051;
    void *temp_r31_1082;
    void *temp_r3_1076;
    void *temp_r5_1059;
    void *var_r27_1048;
    void *var_r3_1032;

    var_r27_1001 = 0;
    var_r25_1002 = 0;
    var_r24_1003 = 0;
    temp_r29_1004 = arg1->unk4;
loop_2:
    if (var_r25_1002 < MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0)) {
        var_r25_1002 += 1;
        temp_r3_1009 = *(temp_r29_1004 + (var_r24_1003 + 4));
        var_r24_1003 += 0xC;
        var_r27_1001 = ((temp_r3_1009 + 0xF) & 0xFFFFFFF0) + var_r27_1001 + 0x10;
        goto loop_2;
    }
    temp_r3_1022 = arg1->unk2 * 0xC;
    temp_r31_1024 = (temp_r3_1022 + 0xF) & 0xFFFFFFF0;
    temp_r3_1025 = temp_r3_1022->Current();
    if (temp_r3_1025 != NULL) {
        var_r3_1032 = ((MKHeap *) (temp_r3_1025->Current()))->Alloc(temp_r31_1024 + var_r27_1001, NULL, 0);
    } else {
        var_r3_1032 = malloc(temp_r31_1024 + var_r27_1001);
    }
    arg1->unk4 = var_r3_1032;
    temp_r30_1039 = temp_r31_1024 + var_r27_1001;
    memset(arg1->unk4, 0, temp_r30_1039);
    var_r28_1044 = 0;
    var_r24_1046 = 0 * 0xC;
    var_r25_1047 = 0;
    var_r27_1048 = arg1->unk4 + temp_r31_1024;
loop_13:
    if (var_r28_1044 < (s32) arg1->unk2) {
        temp_r31_1051 = temp_r29_1004 + var_r24_1046;
        if ((u16) M2C_FIELD(temp_r31_1051, u16 *, 2) != 0) {
            temp_r5_1059 = arg1->unk4 + var_r25_1047;
            M2C_FIELD(temp_r5_1059, u16 *, 0) = (u16) M2C_FIELD(temp_r31_1051, u16 *, 0);
            M2C_FIELD(temp_r5_1059, u16 *, 2) = (u16) M2C_FIELD(temp_r31_1051, u16 *, 2);
            M2C_FIELD(temp_r5_1059, u32 *, 4) = (u32) M2C_FIELD(temp_r31_1051, u32 *, 4);
            M2C_FIELD(temp_r5_1059, void **, 8) = (void *) M2C_FIELD(temp_r31_1051, void **, 8);
            *(arg1->unk4 + (var_r25_1047 + 8)) = var_r27_1048;
            *(arg1->unk4 + (var_r25_1047 + 4)) = (M2C_FIELD(temp_r31_1051, u32 *, 4) + 0xF) & 0xFFFFFFF0;
            temp_r3_1076 = arg1->unk4 + var_r25_1047;
            var_r27_1048 += M2C_FIELD(temp_r3_1076, s32 *, 4);
            temp_r31_1082 = M2C_FIELD(temp_r31_1051, void **, 8);
            temp_r3_1083 = ((MKHeap *) (memcpy(M2C_FIELD(temp_r3_1076, void **, 8), M2C_FIELD(temp_r31_1051, void **, 8), M2C_FIELD(temp_r31_1051, u32 *, 4))))->Current();
            if (temp_r3_1083 != NULL) {
                ((MKHeap *) (temp_r3_1083->Main()))->TFree(temp_r31_1082, NULL, 0);
            } else {
                free(temp_r31_1082);
            }
            var_r28_1044 += 1;
            var_r25_1047 += 0xC;
        }
        var_r24_1046 += 0xC;
        goto loop_13;
    }
    temp_r3_1104 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1104 != NULL) {
        ((MKHeap *) (temp_r3_1104->Current()))->Free(temp_r29_1004, NULL, 0);
    } else {
        free(temp_r29_1004);
    }
    return temp_r30_1039;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
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
    f32 sp30;
    f32 sp20;
    s8 *sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_1147;
    MKHeap *temp_r3_1149;
    MKHeap *temp_r3_1221;
    f32 temp_f3_1284;
    f32 var_f29_1241;
    f32 var_f4_1291;
    f32 var_f4_1416;
    f64 *temp_r3_1245;
    f64 *temp_r3_1360;
    f64 temp_f0_1248;
    f64 temp_f1_1247;
    f64 temp_f1_1294;
    f64 temp_f1_1300;
    f64 temp_f1_1304;
    f64 temp_f1_1419;
    f64 temp_f1_1425;
    f64 temp_f1_1429;
    s16 temp_r25_1144;
    s32 temp_r20_1219;
    s32 temp_r3_1323;
    s32 temp_r3_1448;
    s32 var_r0_1333;
    s32 var_r0_1458;
    s32 var_r21_1246;
    s32 var_r23_1172;
    s32 var_r24_1175;
    s32 var_r27_1168;
    u16 temp_r3_1214;
    void *temp_r21_1220;
    void *temp_r22_1205;
    void *temp_r3_1394;
    void *var_r3_1157;
    void *var_r3_1229;

    temp_r25_1144 = MKModel_GetNmbrOfMaterials(arg0);
    temp_r3_1147 = MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0);
    temp_r3_1149 = temp_r3_1147->Current();
    if (temp_r3_1149 != NULL) {
        var_r3_1157 = ((MKHeap *) (temp_r3_1149->Main()))->TAlloc((s32) temp_r3_1147 * 0xC, NULL, 0, 0U);
    } else {
        var_r3_1157 = malloc((s32) temp_r3_1147 * 0xC);
    }
    arg2->unk4 = var_r3_1157;
    memset(arg2->unk4, 0, (s32) temp_r3_1147 * 0xC);
    var_r27_1168 = 0;
    arg2->unk2 = 0;
    var_r23_1172 = 0;
loop_59:
    if (var_r23_1172 < (s32) temp_r3_1147) {
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
                    temp_r3_1214 = M2C_FIELD(temp_r22_1205, u16 *, 2);
                    M2C_FIELD(temp_r22_1205, s32 *, 4) = (s32) ((temp_r3_1214 + arg1->unk4) * 0x18);
                    temp_r20_1219 = M2C_FIELD(temp_r22_1205, s32 *, 4);
                    temp_r21_1220 = M2C_FIELD(temp_r22_1205, void **, 8);
                    temp_r3_1221 = temp_r3_1214->Current();
                    if (temp_r3_1221 != NULL) {
                        var_r3_1229 = ((MKHeap *) (temp_r3_1221->Main()))->TReAlloc(temp_r21_1220, temp_r20_1219, NULL, 0);
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
                            Min(sp88, *((MKVector3 *) &spB8));
                            spB8 = M2C_BITWISE(f64, sp88);
                            spC0 = (f64) sp88.unk8;
                            Max(sp78, *((MKVector3 *) &spB8));
                            spA8 = M2C_BITWISE(f64, sp78);
                            spB0 = (f64) sp78.unk8;
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            temp_f3_1284 = (f32) spA0 - (f32) M2C_FIELD(arg1->unk18, f64 *, 8);
                            spA0 = temp_f3_1284;
                            var_f4_1291 = (temp_f3_1284 * temp_f3_1284) + (((f32) sp98 * (f32) sp98) + (unksp9C * unksp9C));
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
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f3 */);
                        sp58 = sp18;
                        sp20 = (f32) spC0 + (f32) spB0;
                        sp60 = (f64) sp20;
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                        sp68 = sp28;
                        sp30 = (f32) sp60 * 0.5f;
                        temp_r3_1394 = M2C_FIELD(temp_r22_1205, void **, 8) + (M2C_FIELD(temp_r22_1205, u16 *, 2) * 0x18);
                        M2C_FIELD(temp_r3_1394, f64 *, 0) = sp28;
                        M2C_FIELD(temp_r3_1394, f64 *, 8) = (f64) sp30;
                        sp70 = (f64) sp30;
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f0, $f3 */);
                        sp48 = sp38;
                        sp40 = (f32) spC0 + (f32) spB0;
                        sp50 = (f64) sp40;
                        var_f4_1416 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (unksp4C * unksp4C));
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
    OmniLight sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 temp_f3_1558;
    f32 temp_f6_1565;
    f32 temp_f7_1571;
    f64 *temp_r4_1548;
    f64 *var_r3_1559;
    f64 *var_r3_1613;
    s16 temp_r23_1556;
    s32 var_r22_1637;
    s32 var_r27_1638;

    temp_r4_1548 = arg2->unk18;
    temp_r23_1556 = (s16) (u16) M2C_FIELD(temp_r4_1548, s32 *, 0) + (s16) (u16) M2C_FIELD(temp_r4_1548, s32 *, 8);
    if (arg7 != NULL) {
        temp_f3_1558 = M2C_FIELD(temp_r4_1548, f32 *, 4);
        var_r3_1559 = &sp28.unk20;
        temp_f6_1565 = M2C_BITWISE(f32, M2C_FIELD(temp_r4_1548, s32 *, 0));
        temp_f7_1571 = M2C_BITWISE(f32, M2C_FIELD(temp_r4_1548, s32 *, 8));
        sp18 = arg7->unk30 + ((temp_f7_1571 * arg7->unk20) + ((temp_f6_1565 * arg7->unk0) + (temp_f3_1558 * arg7->unk10)));
        sp1C = arg7->unk34 + ((temp_f7_1571 * arg7->unk24) + ((temp_f6_1565 * arg7->unk4) + (temp_f3_1558 * arg7->unk14)));
        sp20 = arg7->unk38 + ((temp_f7_1571 * arg7->unk28) + ((temp_f6_1565 * arg7->unk8) + (temp_f3_1558 * arg7->unk18)));
        sp28.unk20 = (f64) sp18;
        sp28.unk28 = (f64) sp20;
    } else {
        var_r3_1559 = temp_r4_1548;
    }
    arg0->unk0 = M2C_FIELD(var_r3_1559, f64 *, 0);
    arg0->unk8 = M2C_FIELD(var_r3_1559, f64 *, 8);
    if (arg6 != NULL) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r9, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r9, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
        var_r3_1613 = &sp28.unk10;
        sp28.unk10 = sp8;
        sp28.unk18 = sp10;
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
            sp28.CalculateColor(*(*(arg5 + var_r27_1638)), *((MKVector3 *) arg0));
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r25, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r26, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r24, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $r28, $r26, 0x0, qr0 */);
            var_r22_1637 += 1;
            var_r27_1638 += 4;
            goto loop_11;
        }
        M2C_FIELD(arg0, f32 *, 0x1C) = 1.0f;
    }
    return temp_r23_1556;
}
#endif

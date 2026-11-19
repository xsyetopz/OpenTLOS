#include "common/Source/Animation.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
MKHeap *malloc(s32);                                /* extern */
s32 strcmpi(s32, s8 *);                             /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
M2C_UNK strtok(s8 *, s8 *);                         /* extern */
extern s8 *Animation_pTemplates;
static M2C_UNK fixedPointScaleVec;                  /* unable to generate initializer: unknown type */
static Matrix pMats_827[0x80];
static s16 pMatFlags_847[0x80];
static BlendShapeState _defaultStateArea_913[6];

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Animation::EnableCustomMatrices(bool arg0) {
    MKHeap *temp_r3_18;
    MKHeap *temp_r3_33;
    MKHeap *temp_r3_37;
    MKHeap *var_r3_44;
    s32 temp_r31_36;

    temp_r3_18 = this->unk14;
    if (arg0 != (u8) (temp_r3_18 != NULL)) {
        if (temp_r3_18 != NULL) {
            temp_r3_18->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        }
        if (arg0 != 0) {
            temp_r3_33 = M2C_FIELD(this->unk0, MKHeap **, 0x28);
            temp_r31_36 = (s8) M2C_FIELD(temp_r3_33, u8 *, 4) << 6;
            temp_r3_37 = temp_r3_33->Current();
            if (temp_r3_37 != NULL) {
                var_r3_44 = ((MKHeap *) (temp_r3_37->Current()))->Alloc(temp_r31_36, NULL, 0);
            } else {
                var_r3_44 = malloc(temp_r31_36);
            }
            this->unk14 = var_r3_44;
            return;
        }
        this->unk14 = NULL;
    }
}
#endif

#if 0 // DRAFT: type mismatch
void AnimationData::UnpackTemplatePointers(bool arg0) {
    AnimationData *var_r30_72;
    AnimationData::BlendShape *temp_r0_120;
    AnimationData::BlendShape *temp_r3_137;
    AnimationData::BlendShape *temp_r3_156;
    s32 temp_r0_138;
    s32 temp_r0_158;
    s32 temp_r4_157;
    s32 var_r26_168;
    s32 var_r27_169;
    s32 var_r28_131;
    s32 var_r31_130;
    s32 var_r3_86;
    s32 var_r7_87;
    void *temp_r0_102;
    void *temp_r0_76;
    void *temp_r0_93;
    void *temp_r3_185;
    void *temp_r6_92;

    var_r30_72 = this;
    if (arg0 != 0) {
        var_r30_72 = (AnimationData *) -(s32) var_r30_72;
    }
    temp_r0_76 = this->unk14;
    if (temp_r0_76 > 0) {
        this->unk14 = temp_r0_76 + var_r30_72;
    } else {
        this->unk14 = NULL;
    }
    var_r3_86 = 0;
    var_r7_87 = 0;
loop_13:
    if (var_r7_87 < (s8) this->unk4) {
        temp_r6_92 = this + var_r3_86;
        temp_r0_93 = M2C_FIELD(temp_r6_92, void **, 0x30);
        if (temp_r0_93 > 0) {
            M2C_FIELD(temp_r6_92, void **, 0x30) = (void *) (temp_r0_93 + var_r30_72);
        } else {
            M2C_FIELD(temp_r6_92, void **, 0x30) = NULL;
        }
        temp_r0_102 = M2C_FIELD(temp_r6_92, void **, 0x38);
        if (temp_r0_102 > 0) {
            M2C_FIELD(temp_r6_92, void **, 0x38) = (void *) (temp_r0_102 + var_r30_72);
        } else {
            M2C_FIELD(temp_r6_92, void **, 0x38) = NULL;
        }
        var_r7_87 += 1;
        var_r3_86 += 0x20;
        goto loop_13;
    }
    ByteReverse<AnimationData::BlendShape *>(*((AnimationData::BlendShape **) &this->unk1C));
    temp_r0_120 = this->unk1C;
    if (temp_r0_120 > 0) {
        this->unk1C = temp_r0_120 + var_r30_72;
    } else {
        this->unk1C = NULL;
    }
    var_r31_130 = 0;
    var_r28_131 = 0;
loop_28:
    if (var_r31_130 < (s8) this->unk8) {
        ByteReverse<char *>(*(this->unk1C + var_r28_131));
        temp_r3_137 = this->unk1C;
        temp_r0_138 = *(temp_r3_137 + var_r28_131);
        if (temp_r0_138 > 0) {
            *(temp_r3_137 + var_r28_131) = temp_r0_138 + var_r30_72;
        } else {
            *(temp_r3_137 + var_r28_131) = 0;
        }
        ByteReverse<short unsigned>(*(this->unk1C + (var_r28_131 + 4)));
        ByteReverse<AnimationData::BlendShape::KeyFrame *>(*(this->unk1C + (var_r28_131 + 0xC)));
        temp_r3_156 = this->unk1C;
        temp_r4_157 = var_r28_131 + 0xC;
        temp_r0_158 = *(temp_r3_156 + temp_r4_157);
        if (temp_r0_158 > 0) {
            *(temp_r3_156 + temp_r4_157) = temp_r0_158 + var_r30_72;
        } else {
            *(temp_r3_156 + temp_r4_157) = 0;
        }
        var_r26_168 = 0;
        var_r27_169 = 0;
loop_26:
        temp_r3_185 = var_r28_131 + this->unk1C;
        if (var_r26_168 < (s32) M2C_FIELD(temp_r3_185, u16 *, 4)) {
            ByteReverse<short unsigned>(*(M2C_FIELD(temp_r3_185, s32 *, 0xC) + var_r27_169));
            ByteReverse<short unsigned>(*(*(var_r28_131 + (this->unk1C + 0xC)) + (var_r27_169 + 2)));
            var_r26_168 += 1;
            var_r27_169 += 4;
            goto loop_26;
        }
        var_r31_130 += 1;
        var_r28_131 += 0x10;
        goto loop_28;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
BlendShapeState *Animation::CalculateBlendShape(int arg0, BlendShapeState *arg1) {
    f32 sp48;
    f32 sp8;
    BlendShapeState *var_r26_212;
    f32 temp_f0_378;
    f32 temp_f1_376;
    f32 temp_f31_228;
    s32 temp_r0_377;
    s32 temp_r27_220;
    s32 temp_r27_281;
    s32 temp_r30_299;
    s32 temp_r31_264;
    s32 temp_r3_351;
    s32 temp_r5_245;
    s32 temp_r7_271;
    s32 var_r3_358;
    s32 var_r7_232;
    s32 var_r8_238;
    u16 temp_r28_269;
    u16 temp_r7_355;
    u16 var_ctr_372;
    void *temp_r29_236;
    void *temp_r6_231;

    var_r26_212 = arg1;
    if (var_r26_212 == NULL) {
        var_r26_212 = _defaultStateArea_913;
    }
    temp_r27_220 = arg0 * 0x10;
    temp_f31_228 = M2C_FIELD((this + (M2C_FIELD((M2C_FIELD(M2C_FIELD(this->unk0, void **, 0x28), s32 *, 0x1C) + temp_r27_220), u8 *, 8) * 0x48)), f32 *, 0x68);
    temp_r6_231 = M2C_FIELD(GetTemplate(temp_f31_228), void **, 0x28);
    var_r7_232 = 0;
    temp_r29_236 = M2C_FIELD(temp_r6_231, s32 *, 0x1C) + temp_r27_220;
    var_r8_238 = M2C_FIELD(temp_r29_236, u16 *, 4) - 1;
loop_6:
    if ((s32) (var_r8_238 - var_r7_232) > 1) {
        temp_r5_245 = (s32) (var_r7_232 + var_r8_238) / 2;
        if ((f32) *(M2C_FIELD(temp_r29_236, s32 *, 0xC) + (temp_r5_245 * 4)) > temp_f31_228) {
            var_r8_238 = temp_r5_245;
        } else {
            var_r7_232 = temp_r5_245;
        }
        goto loop_6;
    }
    temp_r31_264 = var_r7_232 * 4;
    temp_r28_269 = M2C_FIELD((M2C_FIELD(temp_r6_231, s32 *, 0x14) + (M2C_FIELD(temp_r29_236, u8 *, 6) * 8)), u16 *, 6);
    var_r26_212->unk4 = (s32) temp_r28_269;
    temp_r7_271 = M2C_FIELD(temp_r29_236, s32 *, 0xC);
    temp_r27_281 = M2C_FIELD(temp_r6_231, s32 *, 0x18) + *(M2C_FIELD(temp_r6_231, s32 *, 0x14) + (M2C_FIELD(temp_r29_236, u8 *, 6) * 8));
    if (temp_f31_228 == (f32) *(temp_r7_271 + temp_r31_264)) {
        DecompressWeights(&var_r26_212->unk8, temp_r27_281 + (temp_r28_269 * M2C_FIELD((temp_r7_271 + temp_r31_264), u16 *, 2)), (s32) temp_r28_269, (f32) M2C_FIELD(temp_r29_236, u8 *, 7));
    } else {
        temp_r30_299 = var_r8_238 * 4;
        if (temp_f31_228 == (f32) *(temp_r7_271 + temp_r30_299)) {
            DecompressWeights(&var_r26_212->unk8, temp_r27_281 + (temp_r28_269 * M2C_FIELD((temp_r7_271 + temp_r30_299), u16 *, 2)), (s32) temp_r28_269, (f32) M2C_FIELD(temp_r29_236, u8 *, 7));
        } else {
            DecompressWeights(&sp48, temp_r27_281 + (temp_r28_269 * M2C_FIELD((temp_r7_271 + temp_r31_264), u16 *, 2)), (s32) temp_r28_269, (f32) M2C_FIELD(temp_r29_236, u8 *, 7));
            DecompressWeights(&sp8, temp_r27_281 + (temp_r28_269 * M2C_FIELD((M2C_FIELD(temp_r29_236, s32 *, 0xC) + temp_r30_299), u16 *, 2)), (s32) temp_r28_269, (f32) M2C_FIELD(temp_r29_236, u8 *, 7));
            temp_r3_351 = M2C_FIELD(temp_r29_236, s32 *, 0xC);
            temp_r7_355 = *(temp_r3_351 + temp_r31_264);
            var_r3_358 = 0;
            var_ctr_372 = temp_r28_269;
            if ((s32) temp_r28_269 > 0) {
                do {
                    temp_f1_376 = *(&sp48 + var_r3_358);
                    temp_r0_377 = var_r3_358 + 8;
                    temp_f0_378 = *(&sp8 + var_r3_358);
                    var_r3_358 += 4;
                    *(var_r26_212 + temp_r0_377) = (((temp_f31_228 - (f32) temp_r7_355) / (f32) (*(temp_r3_351 + temp_r30_299) - temp_r7_355)) * (temp_f0_378 - temp_f1_376)) + temp_f1_376;
                    var_ctr_372 -= 1;
                } while (var_ctr_372 != 0);
            }
        }
    }
    return var_r26_212;
}
#endif

void Animation::DecompressWeights(float *arg0, unsigned char *arg1, int arg2, float arg3) {
    s32 var_ctr_403;
    s32 var_r3_399;
    u8 *var_r5_0;
    u8 temp_r6_407;

    var_r5_0 = arg1;
    var_r3_399 = 0;
    var_ctr_403 = arg2;
    if (arg2 > 0) {
        do {
            temp_r6_407 = *var_r5_0;
            var_r5_0 += 1;
            *(arg0 + var_r3_399) = (arg3 * (f32) temp_r6_407) / 255.0f;
            var_r3_399 += 4;
            var_ctr_403 -= 1;
        } while (var_ctr_403 != 0);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'const Matrix *' to
Matrix *Animation::CalculateMatrices(Matrix *arg0, int arg1, short *arg2, const Matrix *arg3) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Animation::FrameInstance *temp_r18_619;
    Matrix *temp_r16_645;
    Matrix *temp_r3_740;
    Matrix *var_r28_432;
    Matrix *var_r3_897;
    Matrix *var_r4_454;
    f32 temp_f10_684;
    f32 temp_f3_660;
    f32 temp_f8_668;
    f32 temp_f9_676;
    s16 var_r16_482;
    s16 var_r6_489;
    s16 var_r6_548;
    s16 var_r7_540;
    s16 var_r8_539;
    s32 var_ctr_514;
    s32 var_ctr_542;
    s32 var_ctr_583;
    s32 var_ctr_759;
    s32 var_ctr_787;
    s32 var_ctr_831;
    s32 var_ctr_866;
    s32 var_r19_607;
    s32 var_r22_611;
    s32 var_r23_610;
    s32 var_r24_609;
    s32 var_r25_608;
    s32 var_r26_605;
    s32 var_r29_430;
    s32 var_r3_483;
    s32 var_r3_541;
    s32 var_r3_582;
    s32 var_r3_752;
    s32 var_r3_780;
    s32 var_r3_819;
    s32 var_r3_853;
    s32 var_r4_484;
    s32 var_r4_581;
    s32 var_r4_758;
    s32 var_r4_786;
    s32 var_r4_825;
    s32 var_r4_860;
    s32 var_r5_508;
    s32 var_r5_750;
    s32 var_r5_778;
    s32 var_r5_830;
    s32 var_r5_865;
    s32 var_r6_511;
    s32 var_r7_824;
    s32 var_r7_859;
    s32 var_r8_504;
    s32 var_r8_817;
    s32 var_r8_851;
    u32 temp_r16_806;
    u32 temp_r4_441;
    u8 temp_r0_591;
    u8 temp_r0_638;
    void *temp_r21_435;
    void *temp_r6_656;
    void *temp_r6_776;

    var_r29_430 = arg1;
    var_r28_432 = arg0;
    temp_r21_435 = this->unk0;
    if (var_r29_430 <= 0) {
        var_r29_430 = (s32) (s8) M2C_FIELD(M2C_FIELD(temp_r21_435, void **, 0x28), u8 *, 4);
    }
    temp_r4_441 = this->unk18;
    if ((temp_r4_441 != 0) && ((u8) this->unk24 == 0)) {
        if (arg3 != NULL) {
            var_r4_454 = arg3;
        } else {
            var_r4_454 = &Matrix::identity;
        }
        if (memcmp(temp_r4_441 + ((s8) M2C_FIELD(M2C_FIELD(temp_r21_435, void **, 0x28), u8 *, 4) << 6), var_r4_454, 0x40U) == 0) {
            if ((var_r28_432 == NULL) && (arg2 == NULL) && (var_r29_430 == (s8) M2C_FIELD(M2C_FIELD(temp_r21_435, void **, 0x28), u8 *, 4))) {
                return (Matrix *) this->unk18;
            }
            if (var_r28_432 == NULL) {
                var_r28_432 = pMats_827;
            }
            var_r16_482 = 0;
            var_r3_483 = 0;
            var_r4_484 = 0;
loop_25:
            if (var_r16_482 < var_r29_430) {
                if (arg2 != NULL) {
                    var_r6_489 = *(arg2 + var_r4_484);
                } else {
                    var_r6_489 = var_r16_482;
                }
                if ((var_r6_489 >= 0) && (var_r6_489 < (s8) M2C_FIELD(M2C_FIELD(temp_r21_435, void **, 0x28), u8 *, 4))) {
                    var_r8_504 = 0;
                    var_r5_508 = 0;
                    do {
                        var_r6_511 = 0;
                        var_ctr_514 = 4;
loop_22:
                        *(var_r28_432 + var_r3_483 + var_r5_508 + var_r6_511) = *(this->unk18 + (var_r6_489 << 6) + var_r5_508 + var_r6_511);
                        var_r6_511 += 4;
                        var_ctr_514 -= 1;
                        if (var_ctr_514 != 0) {
                            goto loop_22;
                        }
                        var_r8_504 += 1;
                        var_r5_508 += 0x10;
                    } while (var_r8_504 < 4);
                }
                var_r16_482 += 1;
                var_r3_483 += 0x40;
                var_r4_484 += 2;
                goto loop_25;
            }
            return var_r28_432;
        }
        goto block_27;
    }
block_27:
    memset(pMatFlags_847, 0, 0x100U);
    var_r8_539 = 0;
    var_r7_540 = 0;
    var_r3_541 = 0;
    var_ctr_542 = var_r29_430;
    if (var_r29_430 > 0) {
        do {
            if (arg2 != NULL) {
                var_r6_548 = *(arg2 + var_r3_541);
            } else {
                var_r6_548 = var_r7_540;
            }
            if ((var_r6_548 >= 0) && (var_r6_548 < (s8) M2C_FIELD(M2C_FIELD(temp_r21_435, void **, 0x28), u8 *, 4))) {
                pMatFlags_847[var_r6_548] = 1;
                if (var_r8_539 > var_r6_548) {
                    var_r6_548 = var_r8_539;
                }
                var_r8_539 = var_r6_548;
            }
            var_r7_540 += 1;
            var_r3_541 += 2;
            var_ctr_542 -= 1;
        } while (var_ctr_542 != 0);
    }
    var_r4_581 = var_r8_539 * 2;
    var_r3_582 = var_r8_539 << 5;
    var_ctr_583 = var_r8_539 + 1;
    if (var_r8_539 >= 0) {
        do {
            if ((s16) *(pMatFlags_847 + var_r4_581) != 0) {
                temp_r0_591 = *(M2C_FIELD(temp_r21_435, void **, 0x28) + (var_r3_582 + 0x36));
                if ((s8) temp_r0_591 != -1) {
                    pMatFlags_847[(s8) temp_r0_591] |= 2;
                }
            }
            var_r3_582 -= 0x20;
            var_r4_581 -= 2;
            var_ctr_583 -= 1;
        } while (var_ctr_583 != 0);
    }
    var_r26_605 = 0;
    var_r19_607 = 0;
    var_r25_608 = 0;
    var_r24_609 = 0;
    var_r23_610 = 0;
    var_r22_611 = 0;
loop_66:
    if (var_r19_607 <= var_r8_539) {
        if ((s16) *(pMatFlags_847 + var_r22_611) != 0) {
            temp_r18_619 = this + (var_r24_609 + 0x30);
            if (!(((u8) M2C_FIELD(temp_r18_619, u8 *, 0x36) >> 7U) & 1)) {
                CalculateFrame(temp_r18_619, M2C_FIELD(temp_r21_435, void **, 0x28) + (var_r23_610 + 0x20), 1U, 1U);
            }
            ConvertFrameToMatrix(pMats_827, var_r19_607);
            temp_r0_638 = *(M2C_FIELD(temp_r21_435, void **, 0x28) + (var_r23_610 + 0x36));
            if ((s8) temp_r0_638 != -1) {
                temp_r16_645 = pMats_827 + var_r25_608;
                temp_r16_645->Multiply(temp_r16_645, &pMats_827[(s8) temp_r0_638]);
                if ((s32) M2C_FIELD(temp_r18_619, s32 *, 0x40) == 3) {
                    if (((u8) M2C_FIELD(temp_r18_619, u8 *, 0x36) >> 6U) & 1) {
                        temp_r6_656 = M2C_FIELD(temp_r18_619, void **, 0x30);
                        temp_f3_660 = M2C_FIELD(temp_r6_656, f32 *, 4);
                        temp_f8_668 = M2C_FIELD(temp_r6_656, f32 *, 0);
                        temp_f9_676 = M2C_FIELD(temp_r6_656, f32 *, 8);
                        temp_f10_684 = M2C_FIELD(temp_r6_656, f32 *, 0xC);
                        sp18 = (temp_f10_684 * temp_r16_645->unk30) + ((temp_f9_676 * temp_r16_645->unk20) + ((temp_f8_668 * temp_r16_645->unk0) + (temp_f3_660 * temp_r16_645->unk10)));
                        sp1C = (temp_f10_684 * temp_r16_645->unk34) + ((temp_f9_676 * temp_r16_645->unk24) + ((temp_f8_668 * temp_r16_645->unk4) + (temp_f3_660 * temp_r16_645->unk14)));
                        sp20 = (temp_f10_684 * temp_r16_645->unk38) + ((temp_f9_676 * temp_r16_645->unk28) + ((temp_f8_668 * temp_r16_645->unk8) + (temp_f3_660 * temp_r16_645->unk18)));
                        sp48 = (f64) sp18;
                        sp24 = (temp_f10_684 * temp_r16_645->unk3C) + ((temp_f9_676 * temp_r16_645->unk2C) + ((temp_f8_668 * temp_r16_645->unkC) + (temp_f3_660 * temp_r16_645->unk1C)));
                        sp50 = (f64) sp20;
                        sp8 = -(f32) sp48;
                        spC = -unksp4C;
                        sp10 = -(f32) sp50;
                        sp38 = (f64) sp18;
                        sp40 = (f64) sp20;
                        sp28 = (f64) sp8;
                        sp30 = (f64) sp10;
                        temp_r16_645->Translate(temp_r16_645, *((MKVector3 *) &sp28));
                    }
                    temp_r16_645->Multiply(temp_r16_645, this->unk14 + var_r25_608);
                    if (((u8) M2C_FIELD(temp_r18_619, u8 *, 0x36) >> 6U) & 1) {
                        temp_r16_645->Translate(temp_r16_645, *((MKVector3 *) &sp48));
                    }
                }
            } else if (arg3 != NULL) {
                temp_r3_740 = pMats_827 + var_r25_608;
                temp_r3_740->Multiply(temp_r3_740, arg3);
            }
            if ((s32) M2C_FIELD(temp_r18_619, s32 *, 0x40) == 5) {
                var_r5_750 = 0;
                var_r3_752 = 0;
                do {
                    var_r4_758 = 0;
                    var_ctr_759 = 4;
loop_57:
                    *(pMats_827 + var_r25_608 + var_r3_752 + var_r4_758) = *(this->unk14 + var_r25_608 + var_r3_752 + var_r4_758);
                    var_r4_758 += 4;
                    var_ctr_759 -= 1;
                    if (var_ctr_759 != 0) {
                        goto loop_57;
                    }
                    var_r5_750 += 1;
                    var_r3_752 += 0x10;
                } while (var_r5_750 < 4);
            }
            if ((var_r28_432 != NULL) && (*(pMatFlags_847 + var_r22_611) & 1)) {
                temp_r6_776 = var_r28_432 + var_r26_605;
                var_r5_778 = 0;
                var_r3_780 = 0;
                var_r26_605 += 0x40;
                do {
                    var_r4_786 = 0;
                    var_ctr_787 = 4;
loop_63:
                    *(temp_r6_776 + var_r3_780 + var_r4_786) = *(pMats_827 + var_r25_608 + var_r3_780 + var_r4_786);
                    var_r4_786 += 4;
                    var_ctr_787 -= 1;
                    if (var_ctr_787 != 0) {
                        goto loop_63;
                    }
                    var_r5_778 += 1;
                    var_r3_780 += 0x10;
                } while (var_r5_778 < 4);
            }
        }
        var_r19_607 += 1;
        var_r25_608 += 0x40;
        var_r24_609 += 0x48;
        var_r23_610 += 0x20;
        var_r22_611 += 2;
        goto loop_66;
    }
    temp_r16_806 = this->unk18;
    if ((temp_r16_806 != 0) && (arg2 == NULL) && (var_r29_430 == (s8) M2C_FIELD(M2C_FIELD(temp_r21_435, void **, 0x28), u8 *, 4))) {
        var_r8_817 = 0;
        var_r3_819 = 0;
loop_76:
        if (var_r8_817 < var_r29_430) {
            var_r7_824 = 0;
            var_r4_825 = 0;
            do {
                var_r5_830 = 0;
                var_ctr_831 = 4;
loop_73:
                *(temp_r16_806 + var_r3_819 + var_r4_825 + var_r5_830) = *(pMats_827 + var_r3_819 + var_r4_825 + var_r5_830);
                var_r5_830 += 4;
                var_ctr_831 -= 1;
                if (var_ctr_831 != 0) {
                    goto loop_73;
                }
                var_r7_824 += 1;
                var_r4_825 += 0x10;
            } while (var_r7_824 < 4);
            var_r8_817 += 1;
            var_r3_819 += 0x40;
            goto loop_76;
        }
        if (arg3 != NULL) {
            var_r8_851 = 0;
            var_r3_853 = 0;
loop_84:
            if (var_r8_851 < var_r29_430) {
                var_r7_859 = 0;
                var_r4_860 = 0;
                do {
                    var_r5_865 = 0;
                    var_ctr_866 = 4;
loop_81:
                    *(this->unk18 + (var_r29_430 << 6) + var_r3_853 + var_r4_860 + var_r5_865) = *(pMats_827 + var_r3_853 + var_r4_860 + var_r5_865);
                    var_r5_865 += 4;
                    var_ctr_866 -= 1;
                    if (var_ctr_866 != 0) {
                        goto loop_81;
                    }
                    var_r7_859 += 1;
                    var_r4_860 += 0x10;
                } while (var_r7_859 < 4);
                var_r8_851 += 1;
                var_r3_853 += 0x40;
                goto loop_84;
            }
        } else {
            ((Matrix *) (this->unk18 + (var_r29_430 << 6)))->SetIdentity();
        }
        this->unk24 = 0;
    } else {
        this->unk24 = 1;
    }
    var_r3_897 = pMats_827;
    if (var_r28_432 != NULL) {
        var_r3_897 = NULL;
    }
    return var_r3_897;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void Animation::ConvertFrameToMatrix(Matrix *arg0, int arg1) {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector4 *temp_r3_955;
    MKVector4 *temp_r6_1065;
    MKVector4 *temp_r6_1104;
    Matrix *temp_r31_948;
    f32 temp_f10_1132;
    f32 temp_f10_977;
    f32 temp_f11_969;
    f32 temp_f12_1011;
    f32 temp_f12_973;
    f32 temp_f13_975;
    f32 temp_f18_1005;
    f32 temp_f18_966;
    f32 temp_f18_996;
    f32 temp_f19_965;
    f32 temp_f21_986;
    f32 temp_f22_967;
    f32 temp_f23_963;
    f32 temp_f24_961;
    f32 temp_f28_962;
    f32 temp_f29_1001;
    f32 temp_f29_956;
    f32 temp_f2_971;
    f32 temp_f2_989;
    f32 temp_f30_954;
    f32 temp_f31_960;
    f32 temp_f3_1003;
    f32 temp_f3_1108;
    f32 temp_f3_970;
    f32 temp_f3_997;
    f32 temp_f4_959;
    f32 temp_f4_994;
    f32 temp_f5_972;
    f32 temp_f6_980;
    f32 temp_f7_974;
    f32 temp_f8_1116;
    f32 temp_f8_964;
    f32 temp_f8_983;
    f32 temp_f9_1124;
    f32 temp_f9_976;
    s32 temp_r0_1037;
    s32 temp_r30_944;
    void *temp_r29_951;

    temp_r30_944 = arg1 << 6;
    temp_r31_948 = &arg0[arg1];
    temp_r29_951 = this + ((arg1 * 0x48) + 0x30);
    temp_f30_954 = 1.4142135f * M2C_FIELD(temp_r29_951, f32 *, 0x14);
    temp_r3_955 = M2C_FIELD(temp_r29_951, MKVector4 **, 0x30);
    temp_f29_956 = 1.4142135f * M2C_FIELD(temp_r29_951, f32 *, 0x18);
    temp_f4_959 = temp_f30_954 * temp_f30_954;
    temp_f31_960 = 1.4142135f * M2C_FIELD(temp_r29_951, f32 *, 0x10);
    temp_f24_961 = temp_r3_955->unk0;
    temp_f28_962 = 1.4142135f * M2C_FIELD(temp_r29_951, f32 *, 0x1C);
    temp_f23_963 = temp_r3_955->unk4;
    temp_f8_964 = temp_f29_956 * temp_f29_956;
    temp_f19_965 = temp_f31_960 * temp_f30_954;
    temp_f18_966 = temp_f28_962 * temp_f29_956;
    temp_f22_967 = temp_r3_955->unk8;
    temp_f11_969 = M2C_FIELD(temp_r29_951, f32 *, 0x20);
    temp_f3_970 = temp_f31_960 * temp_f29_956;
    temp_f2_971 = temp_f28_962 * temp_f30_954;
    temp_f5_972 = temp_f31_960 * temp_f31_960;
    temp_f12_973 = M2C_FIELD(temp_r29_951, f32 *, 0x24);
    temp_f7_974 = 1.0f - (temp_f4_959 + temp_f8_964);
    temp_f13_975 = M2C_FIELD(temp_r29_951, f32 *, 0x28);
    temp_f9_976 = temp_f19_965 - temp_f18_966;
    temp_f10_977 = temp_f3_970 + temp_f2_971;
    temp_f6_980 = temp_f19_965 + temp_f18_966;
    temp_f8_983 = 1.0f - (temp_f5_972 + temp_f8_964);
    temp_f21_986 = -temp_f23_963 * temp_f12_973;
    temp_f2_989 = temp_f3_970 - temp_f2_971;
    temp_r31_948->unk0 = temp_f11_969 * temp_f7_974;
    temp_f4_994 = 1.0f - (temp_f5_972 + temp_f4_959);
    temp_r31_948->unk4 = temp_f11_969 * temp_f9_976;
    temp_f18_996 = temp_f30_954 * temp_f29_956;
    temp_f3_997 = temp_f28_962 * temp_f31_960;
    temp_r31_948->unk8 = temp_f11_969 * temp_f10_977;
    temp_f29_1001 = temp_f18_996 - temp_f3_997;
    temp_r31_948->unkC = 0.0f;
    temp_f3_1003 = temp_f18_996 + temp_f3_997;
    temp_r31_948->unk10 = temp_f12_973 * temp_f6_980;
    temp_f18_1005 = -temp_f24_961 * temp_f11_969;
    temp_r31_948->unk14 = temp_f12_973 * temp_f8_983;
    temp_f12_1011 = -temp_f22_967 * temp_f13_975;
    temp_r31_948->unk18 = temp_f12_973 * temp_f29_1001;
    temp_r31_948->unk1C = 0.0f;
    temp_r31_948->unk20 = temp_f13_975 * temp_f2_989;
    temp_r31_948->unk24 = temp_f13_975 * temp_f3_1003;
    temp_r31_948->unk28 = temp_f13_975 * temp_f4_994;
    temp_r31_948->unk2C = 0.0f;
    temp_r31_948->unk30 = M2C_FIELD(temp_r29_951, f32 *, 0) + (temp_f24_961 + ((temp_f12_1011 * temp_f2_989) + ((temp_f18_1005 * temp_f7_974) + (temp_f21_986 * temp_f6_980))));
    temp_r31_948->unk34 = M2C_FIELD(temp_r29_951, f32 *, 4) + (temp_f23_963 + ((temp_f12_1011 * temp_f3_1003) + ((temp_f18_1005 * temp_f9_976) + (temp_f21_986 * temp_f8_983))));
    temp_r31_948->unk38 = M2C_FIELD(temp_r29_951, f32 *, 8) + (temp_f22_967 + ((temp_f12_1011 * temp_f4_994) + ((temp_f18_1005 * temp_f10_977) + (temp_f21_986 * temp_f29_1001))));
    temp_r31_948->unk3C = 1.0f;
    temp_r0_1037 = M2C_FIELD(temp_r29_951, s32 *, 0x40);
    switch (temp_r0_1037) {                         /* irregular */
    case 4:
        M2C_STRUCT_COPY(temp_r31_948, this->unk14 + temp_r30_944, 0x40);
        return;
    case 1:
        if (((u8) M2C_FIELD(temp_r29_951, u8 *, 0x36) >> 6U) & 1) {
            temp_r6_1065 = M2C_FIELD(temp_r29_951, MKVector4 **, 0x30);
            sp28 = -temp_r6_1065->unk0;
            sp2C = -temp_r6_1065->unk4;
            sp30 = -temp_r6_1065->unk8;
            sp34 = -temp_r6_1065->unkC;
            sp58 = (f64) sp28;
            sp60 = (f64) sp30;
            temp_r31_948->Translate(temp_r31_948, *((MKVector4 *) &sp58));
        }
        temp_r31_948->Multiply(this->unk14 + temp_r30_944, temp_r31_948);
        if (((u8) M2C_FIELD(temp_r29_951, u8 *, 0x36) >> 6U) & 1) {
            temp_r31_948->Translate(temp_r31_948, *(M2C_FIELD(temp_r29_951, MKVector4 **, 0x30)));
            return;
        }
    case 3:
        return;
    case 2:
        if (((u8) M2C_FIELD(temp_r29_951, u8 *, 0x36) >> 6U) & 1) {
            temp_r6_1104 = M2C_FIELD(temp_r29_951, MKVector4 **, 0x30);
            temp_f3_1108 = temp_r6_1104->unk4;
            temp_f8_1116 = temp_r6_1104->unk0;
            temp_f9_1124 = temp_r6_1104->unk8;
            temp_f10_1132 = temp_r6_1104->unkC;
            sp18 = (temp_f10_1132 * temp_r31_948->unk30) + ((temp_f9_1124 * temp_r31_948->unk20) + ((temp_f8_1116 * temp_r31_948->unk0) + (temp_f3_1108 * temp_r31_948->unk10)));
            sp1C = (temp_f10_1132 * temp_r31_948->unk34) + ((temp_f9_1124 * temp_r31_948->unk24) + ((temp_f8_1116 * temp_r31_948->unk4) + (temp_f3_1108 * temp_r31_948->unk14)));
            sp20 = (temp_f10_1132 * temp_r31_948->unk38) + ((temp_f9_1124 * temp_r31_948->unk28) + ((temp_f8_1116 * temp_r31_948->unk8) + (temp_f3_1108 * temp_r31_948->unk18)));
            sp68 = (f64) sp18;
            sp24 = (temp_f10_1132 * temp_r31_948->unk3C) + ((temp_f9_1124 * temp_r31_948->unk2C) + ((temp_f8_1116 * temp_r31_948->unkC) + (temp_f3_1108 * temp_r31_948->unk1C)));
            sp70 = (f64) sp20;
            sp8 = -(f32) sp68;
            spC = -unksp6C;
            sp10 = -(f32) sp70;
            sp48 = (f64) sp18;
            sp50 = (f64) sp20;
            sp38 = (f64) sp8;
            sp40 = (f64) sp10;
            temp_r31_948->Translate(temp_r31_948, *((MKVector3 *) &sp38));
        }
        temp_r31_948->Multiply(temp_r31_948, this->unk14 + temp_r30_944);
        if (((u8) M2C_FIELD(temp_r29_951, u8 *, 0x36) >> 6U) & 1) {
            temp_r31_948->Translate(temp_r31_948, *((MKVector3 *) &sp68));
        }
        break;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp50'
void Animation::CalculateFrame(Animation::FrameInstance *arg1, AnimationData::Node *arg2, bool arg3, bool arg4) {
    u16 sp84;
    MKVector3 sp70;
    MKVector4 sp60;
    BlendShapeState sp8;
    f32 temp_f3_1288;
    f32 temp_f4_1283;
    s16 temp_r4_1258;
    s32 temp_r0_1291;
    s32 temp_r4_1289;
    s32 var_r3_1278;
    s32 var_r7_1277;
    void *temp_r6_1286;

    if (arg3 != 0) {
        if (M2C_FIELD(arg1, f32 *, 0x3C) == 1.0f) {
            InterpolateFrame(arg1, arg2, M2C_FIELD(arg1, f32 *, 0x38));
        } else {
            sp84 = M2C_FIELD(arg1, u16 *, 0x34);
            InterpolateFrame(&unksp50, arg2, M2C_FIELD(arg1, f32 *, 0x38));
            InterpolateFrameData(arg1, M2C_FIELD(arg1, f32 *, 0x3C), *((MKVector3 *) arg1), *(arg1 + 0x10), *(arg1 + 0x20), unksp50, sp60, sp70);
            M2C_FIELD(arg1, f32 *, 0xC) = (f32) M2C_FIELD(arg1, f32 *, 0x38);
        }
    }
    if (arg4 != 0) {
        temp_r4_1258 = M2C_FIELD(arg2, s16 *, 0x1C);
        if (temp_r4_1258 != -1) {
            if (M2C_FIELD(arg1, f32 *, 0x3C) == 1.0f) {
                CalculateBlendShape((s32) temp_r4_1258, this->unk1C + (temp_r4_1258 * 0x48));
            } else {
                CalculateBlendShape((s32) temp_r4_1258, &sp8);
                var_r7_1277 = 0;
                var_r3_1278 = 0;
loop_10:
                if (var_r7_1277 < sp8.unk4) {
                    temp_f4_1283 = M2C_FIELD(arg1, f32 *, 0x3C);
                    var_r7_1277 += 1;
                    temp_r6_1286 = this->unk1C;
                    temp_f3_1288 = *(&sp8 + (var_r3_1278 + 8));
                    temp_r4_1289 = (M2C_FIELD(arg2, s16 *, 0x1C) * 0x48) + var_r3_1278;
                    var_r3_1278 += 4;
                    temp_r0_1291 = temp_r4_1289 + 8;
                    *(temp_r6_1286 + temp_r0_1291) = (temp_f3_1288 * temp_f4_1283) + ((1.0f - temp_f4_1283) * *(temp_r6_1286 + temp_r0_1291));
                    goto loop_10;
                }
                M2C_FIELD((this->unk1C + (M2C_FIELD(arg2, s16 *, 0x1C) * 0x48)), s32 *, 4) = sp8.unk4;
            }
        }
    }
    M2C_FIELD(arg1, u8 *, 0x36) = (u8) (M2C_FIELD(arg1, u8 *, 0x36) | 0x80);
}
#endif

#if 0 // DRAFT: illegal type
void Animation::GetPositionalOffset(float arg0) {
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Animation *temp_r27_1327;
    f32 var_f31_1326;
    f64 temp_f0_1641;
    s32 temp_r0_1331;
    s32 temp_r27_1407;
    s32 temp_r27_1472;
    s32 temp_r28_1451;
    s32 temp_r30_1595;
    s32 temp_r31_1538;
    s32 temp_r4_1383;
    s32 temp_r7_1367;
    s32 var_r5_1357;
    s32 var_r6_1360;
    u16 temp_r3_1389;
    u16 temp_r4_1454;
    void *temp_r27_1356;
    void *temp_r29_1387;
    void *temp_r30_1353;
    void *temp_r31_1453;
    void *temp_r31_1588;
    void *temp_r3_1330;
    void *temp_r9_1409;
    void *temp_r9_1474;
    void *temp_r9_1540;
    void *temp_r9_1597;

    var_f31_1326 = arg0;
    temp_r27_1327 = M2C_ERROR(/* Read from unset register $r4 */);
    temp_r3_1330 = temp_r27_1327->GetTemplate(arg0);
    temp_r0_1331 = temp_r27_1327->unk28;
    if (temp_r0_1331 == -1) {
        sp28 = 0.0f;
        sp2C = 0.0f;
        sp30 = 0.0f;
        M2C_FIELD(this, f64 *, 0) = (f64) sp28;
        this->unk8 = (f64) sp30;
        return;
    }
    if (var_f31_1326 < 0.0f) {
        var_f31_1326 = M2C_FIELD((temp_r27_1327 + ((temp_r0_1331 * 0x48) + 0x30)), f32 *, 0x38);
    }
    temp_r30_1353 = M2C_FIELD(temp_r3_1330, void **, 0x28);
    temp_r27_1356 = temp_r30_1353 + ((temp_r0_1331 << 5) + 0x20);
    var_r5_1357 = 0;
    var_r6_1360 = M2C_FIELD(temp_r27_1356, u16 *, 0x14) - 1;
loop_8:
    if ((s32) (var_r6_1360 - var_r5_1357) > 1) {
        temp_r7_1367 = (s32) (var_r5_1357 + var_r6_1360) / 2;
        if ((f32) *(M2C_FIELD(temp_r27_1356, s32 *, 0x18) + (temp_r7_1367 * 8)) > var_f31_1326) {
            var_r6_1360 = temp_r7_1367;
        } else {
            var_r5_1357 = temp_r7_1367;
        }
        goto loop_8;
    }
    temp_r4_1383 = M2C_FIELD(temp_r27_1356, s32 *, 0x18);
    temp_r29_1387 = temp_r4_1383 + (var_r5_1357 * 8);
    temp_r3_1389 = M2C_FIELD(temp_r29_1387, u16 *, 0);
    if (var_f31_1326 == (f32) temp_r3_1389) {
        temp_r27_1407 = M2C_FIELD(temp_r30_1353, s32 *, 0x18) + *(M2C_FIELD(temp_r30_1353, s32 *, 0x14) + ((s8) M2C_FIELD(temp_r27_1356, u8 *, 0x17) * 8));
        temp_r9_1409 = temp_r27_1407 + (M2C_FIELD(temp_r29_1387, u16 *, 4) * 8);
        sp98 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1409, s16 *, 0);
        sp9C = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1409, s16 *, 2);
        spA0 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1409, s16 *, 4);
        spA4 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1409, s16 *, 6);
        DecompressVector(temp_r27_1407 + (M2C_FIELD(temp_r29_1387, u16 *, 2) * 8), &sp88);
        DecompressVector(temp_r27_1407 + (M2C_FIELD(temp_r29_1387, u16 *, 6) * 8), &spA8);
    } else {
        temp_r28_1451 = var_r6_1360 * 8;
        temp_r31_1453 = temp_r4_1383 + temp_r28_1451;
        temp_r4_1454 = M2C_FIELD(temp_r31_1453, u16 *, 0);
        if (var_f31_1326 == (f32) temp_r4_1454) {
            temp_r27_1472 = M2C_FIELD(temp_r30_1353, s32 *, 0x18) + *(M2C_FIELD(temp_r30_1353, s32 *, 0x14) + ((s8) M2C_FIELD(temp_r27_1356, u8 *, 0x17) * 8));
            temp_r9_1474 = temp_r27_1472 + (M2C_FIELD(temp_r31_1453, u16 *, 4) * 8);
            sp98 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1474, s16 *, 0);
            sp9C = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1474, s16 *, 2);
            spA0 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1474, s16 *, 4);
            spA4 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1474, s16 *, 6);
            DecompressVector(temp_r27_1472 + (M2C_FIELD(temp_r31_1453, u16 *, 2) * 8), &sp88);
            DecompressVector(temp_r27_1472 + (M2C_FIELD(temp_r31_1453, u16 *, 6) * 8), &spA8);
        } else {
            temp_r31_1538 = M2C_FIELD(temp_r30_1353, s32 *, 0x18) + *(M2C_FIELD(temp_r30_1353, s32 *, 0x14) + ((s8) M2C_FIELD(temp_r27_1356, u8 *, 0x17) * 8));
            temp_r9_1540 = temp_r31_1538 + (M2C_FIELD(temp_r29_1387, u16 *, 4) * 8);
            sp98 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1540, s16 *, 0);
            sp9C = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1540, s16 *, 2);
            spA0 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1540, s16 *, 4);
            spA4 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1540, s16 *, 6);
            DecompressVector(temp_r31_1538 + (M2C_FIELD(temp_r29_1387, u16 *, 2) * 8), &sp78);
            DecompressVector(temp_r31_1538 + (M2C_FIELD(temp_r29_1387, u16 *, 6) * 8), &spA8);
            temp_r31_1588 = M2C_FIELD(temp_r27_1356, s32 *, 0x18) + temp_r28_1451;
            temp_r30_1595 = M2C_FIELD(temp_r30_1353, s32 *, 0x18) + *(M2C_FIELD(temp_r30_1353, s32 *, 0x14) + ((s8) M2C_FIELD(temp_r27_1356, u8 *, 0x17) * 8));
            temp_r9_1597 = temp_r30_1595 + (M2C_FIELD(temp_r31_1588, u16 *, 4) * 8);
            sp98 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1597, s16 *, 0);
            sp9C = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1597, s16 *, 2);
            spA0 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1597, s16 *, 4);
            spA4 = 0.00006103888f * (f32) M2C_FIELD(temp_r9_1597, s16 *, 6);
            DecompressVector(temp_r30_1595 + (M2C_FIELD(temp_r31_1588, u16 *, 2) * 8), &sp68);
            DecompressVector(temp_r30_1595 + (M2C_FIELD(temp_r31_1588, u16 *, 6) * 8), &spA8);
            temp_f0_1641 = (f64) sp68 - (f64) sp78;
            sp8 = temp_f0_1641;
            sp38 = temp_f0_1641;
            sp10 = sp70 - sp80;
            sp40 = (f64) sp10;
            __ml((var_f31_1326 - (f32) temp_r3_1389) / (f32) (temp_r4_1454 - temp_r3_1389), sp48);
            sp18 = (f64) sp78 + M2C_BITWISE(f64, sp48);
            sp58 = sp18;
            sp20 = sp80 + sp48.unk8;
            sp88 = sp18;
            sp60 = (f64) sp20;
            sp90 = (f64) sp20;
        }
    }
    M2C_FIELD(this, f64 *, 0) = (f64) sp88;
    this->unk8 = sp90;
}
#endif

s32 Animation::GetNodeName(int arg0) {
    return M2C_FIELD((M2C_FIELD(this->unk0, s32 *, 0x28) + (arg0 << 5)), s32 *, 0x30);
}

void Animation::GetNodeOrigin(int arg0) {
    void *temp_r4_1700;

    temp_r4_1700 = M2C_FIELD((arg0 + (M2C_ERROR(/* Read from unset register $r5 */) * 0x48)), void **, 0x60);
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1700, f64 *, 0);
    this->unk8 = M2C_FIELD(temp_r4_1700, f64 *, 8);
}

s8 Animation::GetNodeParentIndex(int arg0) {
    return (s8) M2C_FIELD((M2C_FIELD(this->unk0, s32 *, 0x28) + (arg0 << 5)), u8 *, 0x36);
}

#if 0 // DRAFT: illegal type
s8 Animation::GetNodeIndex(const char *arg0) {
    s32 var_r31_1730;
    s8 var_r30_1729;
    void *temp_r3_1746;

    var_r30_1729 = 0;
    var_r31_1730 = 0;
loop_4:
    temp_r3_1746 = M2C_FIELD(this->unk0, void **, 0x28);
    if (var_r30_1729 >= (s8) M2C_FIELD(temp_r3_1746, u8 *, 4)) {
        return -1;
    }
    if (strcmpi(*(temp_r3_1746 + (var_r31_1730 + 0x30)), arg0) == 0) {
        return var_r30_1729;
    }
    var_r30_1729 += 1;
    var_r31_1730 += 0x20;
    goto loop_4;
}
#endif

#if 0 // DRAFT: illegal type
u8 Animation::NodeExists(const char *arg0, int *arg1) {
    s32 var_r30_1770;
    s32 var_r31_1771;
    void *temp_r3_1791;

    var_r30_1770 = 0;
    var_r31_1771 = 0;
loop_6:
    temp_r3_1791 = M2C_FIELD(this->unk0, void **, 0x28);
    if (var_r30_1770 >= (s8) M2C_FIELD(temp_r3_1791, u8 *, 4)) {
        return 0U;
    }
    if (strcmpi(*(temp_r3_1791 + (var_r31_1771 + 0x30)), arg0) == 0) {
        if (arg1 != NULL) {
            *arg1 = var_r30_1770;
        }
        return 1U;
    }
    var_r30_1770 += 1;
    var_r31_1771 += 0x20;
    goto loop_6;
}
#endif

s8 Animation::GetNmbrOfNodes() {
    return (s8) M2C_FIELD(M2C_FIELD(this->unk0, void **, 0x28), u8 *, 4);
}

MKHeap *Animation::GetName() {
    return (MKHeap *) this->unk0;
}

#if 0 // DRAFT: illegal explicit conversion from 'Animation *' to
f32 Animation::InterpolateFrameData(Animation::FrameInstance *arg1, float farg0, const MKVector3 &arg2, const MKVector4 &arg3, const MKVector3 &arg4, const MKVector3 &arg5, const MKVector4 &arg6, const MKVector3 &arg7) {
    f32 temp_f9_1876;
    f32 temp_f9_1880;
    f64 temp_f0_1825;
    f64 temp_f0_1837;
    f64 temp_f0_1847;
    f64 temp_f1_1831;
    f64 temp_f1_1843;
    f64 temp_f1_1852;
    f64 temp_f2_1840;
    f64 temp_f3_1850;
    f64 temp_f4_1833;
    f64 temp_f8_1875;
    f64 var_f5_1862;
    f64 var_f6_1863;

    temp_f0_1825 = M2C_FIELD(&arg2, f64 *, 0);
    temp_f1_1831 = M2C_FIELD(&arg2, f64 *, 8);
    temp_f4_1833 = 5.263544247e-315 - (f64) farg0;
    temp_f0_1837 = M2C_FIELD(&arg4, f64 *, 0);
    temp_f2_1840 = M2C_FIELD(&arg6, f64 *, 0);
    M2C_FIELD(arg1, f64 *, 0) = (f64) (((M2C_FIELD(&arg5, f64 *, 0) - temp_f0_1825) * (f64) farg0) + temp_f0_1825);
    temp_f1_1843 = M2C_FIELD(&arg4, f64 *, 8);
    M2C_FIELD(arg1, f64 *, 8) = (f64) (((M2C_FIELD(&arg5, f64 *, 8) - temp_f1_1831) * (f64) farg0) + temp_f1_1831);
    temp_f0_1847 = M2C_FIELD(&arg3, f64 *, 0);
    M2C_FIELD(arg1, f64 *, 0x20) = (f64) (((M2C_FIELD(&arg7, f64 *, 0) - temp_f0_1837) * (f64) farg0) + temp_f0_1837);
    temp_f3_1850 = M2C_FIELD(&arg6, f64 *, 8);
    temp_f1_1852 = M2C_FIELD(&arg3, f64 *, 8);
    M2C_FIELD(arg1, f64 *, 0x28) = (f64) (((M2C_FIELD(&arg7, f64 *, 8) - temp_f1_1843) * (f64) farg0) + temp_f1_1843);
    if (!((f32) (2.0 * ((temp_f1_1852 * temp_f3_1850) + (temp_f0_1847 * temp_f2_1840))) < (f32) (temp_f0_1825 - temp_f0_1825))) {
        var_f5_1862 = (temp_f2_1840 * (f64) farg0) + (temp_f0_1847 * temp_f4_1833);
        var_f6_1863 = (temp_f3_1850 * (f64) farg0) + (temp_f1_1852 * temp_f4_1833);
    } else {
        var_f5_1862 = (temp_f2_1840 * (f64) farg0) - (temp_f0_1847 * temp_f4_1833);
        var_f6_1863 = (temp_f3_1850 * (f64) farg0) - (temp_f1_1852 * temp_f4_1833);
    }
    temp_f8_1875 = 2.0 * ((var_f6_1863 * var_f6_1863) + (var_f5_1862 * var_f5_1862));
    temp_f9_1876 = __frsqrte(temp_f8_1875);
    temp_f9_1880 = -((temp_f9_1876 * temp_f9_1876 * (f32) temp_f8_1875) - 3.0f) * (temp_f9_1876 * 0.5f);
    M2C_FIELD(arg1, f64 *, 0x10) = (f64) (var_f5_1862 * (f64) temp_f9_1880);
    M2C_FIELD(arg1, f64 *, 0x18) = (f64) (var_f6_1863 * (f64) temp_f9_1880);
    return M2C_BITWISE(f32, this);
}
#endif

#if 0 // DRAFT: pointer/array required
void Animation::InterpolateFrame(Animation::FrameInstance *arg1, AnimationData::Node *arg2, float farg0) {
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r0_1909;
    s32 temp_r28_2044;
    s32 temp_r30_2196;
    s32 temp_r31_1987;
    s32 temp_r31_2060;
    s32 temp_r31_2129;
    s32 temp_r4_1946;
    s32 temp_r5_1903;
    s32 temp_r5_1967;
    s32 temp_r6_1916;
    s32 var_r28_1910;
    s32 var_r29_1921;
    s32 var_r3_1905;
    s32 var_r4_1912;
    u16 temp_r0_1901;
    u16 temp_r3_2047;
    u16 temp_r8_1973;
    void *temp_r27_1974;
    void *temp_r29_2046;
    void *temp_r30_1971;
    void *temp_r31_2190;
    void *temp_r4_1993;
    void *temp_r4_2066;
    void *temp_r5_2131;
    void *temp_r5_2198;

    temp_r0_1901 = M2C_FIELD(arg1, u16 *, 0x34);
    temp_r5_1903 = M2C_FIELD(arg2, u16 *, 0x14) - 1;
    var_r3_1905 = temp_r5_1903;
    if ((s32) temp_r0_1901 < temp_r5_1903) {
        var_r3_1905 = (s32) temp_r0_1901;
    }
    temp_r0_1909 = var_r3_1905 + 1;
    var_r28_1910 = var_r3_1905;
    var_r4_1912 = temp_r5_1903;
    if (temp_r0_1909 < temp_r5_1903) {
        var_r4_1912 = temp_r0_1909;
    }
    temp_r6_1916 = M2C_FIELD(arg2, s32 *, 0x18);
    var_r29_1921 = var_r4_1912;
    if (((f32) *(temp_r6_1916 + (var_r3_1905 * 8)) > farg0) || ((f32) *(temp_r6_1916 + (var_r4_1912 * 8)) < farg0)) {
        var_r29_1921 = temp_r5_1903;
        var_r28_1910 = 0;
loop_10:
        if ((s32) (var_r29_1921 - var_r28_1910) > 1) {
            temp_r4_1946 = (s32) (var_r28_1910 + var_r29_1921) / 2;
            if ((f32) *(temp_r6_1916 + (temp_r4_1946 * 8)) > farg0) {
                var_r29_1921 = temp_r4_1946;
            } else {
                var_r28_1910 = temp_r4_1946;
            }
            goto loop_10;
        }
        M2C_FIELD(arg1, u16 *, 0x34) = (u16) var_r28_1910;
    }
    temp_r5_1967 = M2C_FIELD(arg2, s32 *, 0x18);
    temp_r30_1971 = temp_r5_1967 + (var_r28_1910 * 8);
    temp_r8_1973 = M2C_FIELD(temp_r30_1971, u16 *, 0);
    temp_r27_1974 = M2C_FIELD(GetTemplate(farg0), void **, 0x28);
    if (farg0 == (f32) temp_r8_1973) {
        temp_r31_1987 = M2C_FIELD(temp_r27_1974, s32 *, 0x18) + *(M2C_FIELD(temp_r27_1974, s32 *, 0x14) + ((s8) M2C_FIELD(arg2, u8 *, 0x17) * 8));
        if ((arg1 + 0x10) != NULL) {
            temp_r4_1993 = temp_r31_1987 + (M2C_FIELD(temp_r30_1971, u16 *, 4) * 8);
            M2C_FIELD(arg1, f32 *, 0x10) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_1993, s16 *, 0));
            M2C_FIELD(arg1, f32 *, 0x14) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_1993, s16 *, 2));
            M2C_FIELD(arg1, f32 *, 0x18) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_1993, s16 *, 4));
            M2C_FIELD(arg1, f32 *, 0x1C) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_1993, s16 *, 6));
        }
        if (arg1 != NULL) {
            DecompressVector(temp_r31_1987 + (M2C_FIELD(temp_r30_1971, u16 *, 2) * 8), (f32 *) arg1);
        }
        if ((arg1 + 0x20) != NULL) {
            DecompressVector(temp_r31_1987 + (M2C_FIELD(temp_r30_1971, u16 *, 6) * 8), arg1 + 0x20);
        }
    } else {
        temp_r28_2044 = var_r29_1921 * 8;
        temp_r29_2046 = temp_r5_1967 + temp_r28_2044;
        temp_r3_2047 = M2C_FIELD(temp_r29_2046, u16 *, 0);
        if (farg0 == (f32) temp_r3_2047) {
            temp_r31_2060 = M2C_FIELD(temp_r27_1974, s32 *, 0x18) + *(M2C_FIELD(temp_r27_1974, s32 *, 0x14) + ((s8) M2C_FIELD(arg2, u8 *, 0x17) * 8));
            if ((arg1 + 0x10) != NULL) {
                temp_r4_2066 = temp_r31_2060 + (M2C_FIELD(temp_r29_2046, u16 *, 4) * 8);
                M2C_FIELD(arg1, f32 *, 0x10) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_2066, s16 *, 0));
                M2C_FIELD(arg1, f32 *, 0x14) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_2066, s16 *, 2));
                M2C_FIELD(arg1, f32 *, 0x18) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_2066, s16 *, 4));
                M2C_FIELD(arg1, f32 *, 0x1C) = (f32) (0.00006103888f * (f32) M2C_FIELD(temp_r4_2066, s16 *, 6));
            }
            if (arg1 != NULL) {
                DecompressVector(temp_r31_2060 + (M2C_FIELD(temp_r29_2046, u16 *, 2) * 8), (f32 *) arg1);
            }
            if ((arg1 + 0x20) != NULL) {
                DecompressVector(temp_r31_2060 + (M2C_FIELD(temp_r29_2046, u16 *, 6) * 8), arg1 + 0x20);
            }
        } else {
            temp_r31_2129 = M2C_FIELD(temp_r27_1974, s32 *, 0x18) + *(M2C_FIELD(temp_r27_1974, s32 *, 0x14) + ((s8) M2C_FIELD(arg2, u8 *, 0x17) * 8));
            temp_r5_2131 = temp_r31_2129 + (M2C_FIELD(temp_r30_1971, u16 *, 4) * 8);
            sp18 = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2131, s16 *, 0);
            sp1C = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2131, s16 *, 2);
            sp20 = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2131, s16 *, 4);
            sp24 = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2131, s16 *, 6);
            DecompressVector(temp_r31_2129 + (M2C_FIELD(temp_r30_1971, u16 *, 2) * 8), &sp58);
            DecompressVector(temp_r31_2129 + (M2C_FIELD(temp_r30_1971, u16 *, 6) * 8), &sp38);
            temp_r31_2190 = M2C_FIELD(arg2, s32 *, 0x18) + temp_r28_2044;
            temp_r30_2196 = M2C_FIELD(temp_r27_1974, s32 *, 0x18) + *(M2C_FIELD(temp_r27_1974, s32 *, 0x14) + ((s8) M2C_FIELD(arg2, u8 *, 0x17) * 8));
            temp_r5_2198 = temp_r30_2196 + (M2C_FIELD(temp_r31_2190, u16 *, 4) * 8);
            sp8 = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2198, s16 *, 0);
            spC = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2198, s16 *, 2);
            sp10 = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2198, s16 *, 4);
            sp14 = 0.00006103888f * (f32) M2C_FIELD(temp_r5_2198, s16 *, 6);
            DecompressVector(temp_r30_2196 + (M2C_FIELD(temp_r31_2190, u16 *, 2) * 8), &sp48);
            DecompressVector(temp_r30_2196 + (M2C_FIELD(temp_r31_2190, u16 *, 6) * 8), &sp28);
            InterpolateFrameData(arg1, (farg0 - (f32) temp_r8_1973) / (f32) (temp_r3_2047 - temp_r8_1973), *((MKVector3 *) &sp58), *((MKVector4 *) &sp18), *((MKVector3 *) &sp38), *((MKVector3 *) &sp48), *((MKVector4 *) &sp8), *((MKVector3 *) &sp28));
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
void Animation::SetCustomMatrix(int arg0, const Matrix *arg1, AnimationMatrixPosition arg2, bool arg3) {
    MKHeap *temp_r9_2265;
    s32 temp_r4_2293;
    s32 temp_r5_2281;
    s32 temp_r6_2289;
    s32 temp_r8_2280;

    if (arg1 != NULL) {
        temp_r9_2265 = this->unk14;
        if (temp_r9_2265 != NULL) {
            M2C_STRUCT_COPY(temp_r9_2265 + (arg0 << 6), arg1, 0x40);
            temp_r8_2280 = arg0 * 0x48;
            temp_r5_2281 = temp_r8_2280 + 0x66;
            *(this + temp_r5_2281) = (*(this + temp_r5_2281) & ~0x40) | ((arg3 << 6) & 0x40);
            M2C_FIELD((this + temp_r8_2280), s32 *, 0x70) = (s32) arg2;
            return;
        }
        return;
    }
    temp_r6_2289 = arg0 * 0x48;
    M2C_FIELD((this + temp_r6_2289), s32 *, 0x70) = 0;
    temp_r4_2293 = temp_r6_2289 + 0x66;
    *(this + temp_r4_2293) = *(this + temp_r4_2293) & ~0x40;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void Animation::TweenNode(float arg0, float arg1, int arg2, bool arg3, bool arg4) {
    AnimationData::Node *temp_r5_2326;
    Animation::FrameInstance *temp_r25_2323;
    s32 var_r24_2340;
    s32 var_r26_2339;
    void *temp_r3_2317;
    void *temp_r3_2363;

    temp_r3_2317 = GetTemplate(arg0);
    temp_r25_2323 = this + ((arg2 * 0x48) + 0x30);
    temp_r5_2326 = M2C_FIELD(temp_r3_2317, void **, 0x28) + ((arg2 << 5) + 0x20);
    if (!(((u8) M2C_FIELD(temp_r25_2323, u8 *, 0x36) >> 7U) & 1) && (arg1 != 1.0f)) {
        CalculateFrame(temp_r25_2323, temp_r5_2326, arg3, arg4);
    }
    M2C_FIELD(temp_r25_2323, f32 *, 0x38) = arg0;
    var_r26_2339 = 0;
    var_r24_2340 = 0;
    M2C_FIELD(temp_r25_2323, f32 *, 0x3C) = arg1;
    M2C_FIELD(temp_r25_2323, u8 *, 0x36) = (u8) (M2C_FIELD(temp_r25_2323, u8 *, 0x36) & ~0x80);
loop_7:
    temp_r3_2363 = M2C_FIELD(temp_r3_2317, void **, 0x28);
    if (var_r24_2340 < (s8) M2C_FIELD(temp_r3_2363, u8 *, 4)) {
        if ((s8) *(temp_r3_2363 + (var_r26_2339 + 0x36)) == arg2) {
            TweenNode(arg0, arg1, var_r24_2340, arg3, arg4);
        }
        var_r24_2340 += 1;
        var_r26_2339 += 0x20;
        goto loop_7;
    }
    this->unk24 = 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Animation *' to
void Animation::Tween(float arg0, float arg1) {
    AnimationData::Node *var_r29_2419;
    Animation::FrameInstance *var_r30_2418;
    f32 var_f31_2406;
    s32 var_r28_2420;
    void *temp_r3_2397;
    void *temp_r3_2400;

    temp_r3_2397 = GetTemplate(arg0);
    if (temp_r3_2397 != NULL) {
        temp_r3_2400 = M2C_FIELD(temp_r3_2397, void **, 0x28);
        if ((u32) M2C_FIELD(temp_r3_2400, u32 *, 0x18) == 0U) {
            return;
        }
        var_f31_2406 = 1.0f;
        if (arg1 < var_f31_2406) {
            var_f31_2406 = arg1;
        }
        if (var_f31_2406 > 0.0f) {

        } else {
            var_f31_2406 = 0.0f;
        }
        var_r30_2418 = this + 0x30;
        var_r29_2419 = temp_r3_2400 + 0x20;
        var_r28_2420 = 0;
loop_13:
        if (var_r28_2420 < (s8) M2C_FIELD(M2C_FIELD(temp_r3_2397, void **, 0x28), u8 *, 4)) {
            if (!(((u8) M2C_FIELD(var_r30_2418, u8 *, 0x36) >> 7U) & 1) && (var_f31_2406 != 1.0f)) {
                CalculateFrame(var_r30_2418, var_r29_2419, 1U, 1U);
            }
            M2C_FIELD(var_r30_2418, f32 *, 0x38) = arg0;
            var_r28_2420 += 1;
            var_r29_2419 += 0x20;
            M2C_FIELD(var_r30_2418, f32 *, 0x3C) = var_f31_2406;
            M2C_FIELD(var_r30_2418, u8 *, 0x36) = (u8) (M2C_FIELD(var_r30_2418, u8 *, 0x36) & ~0x80);
            var_r30_2418 += 0x48;
            goto loop_13;
        }
        this->unk24 = 1;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Animation' to
void Animation::ReloadGuts() {
    s32 var_r29_2477;
    s32 var_r31_2478;
    void *temp_r4_2481;

    var_r29_2477 = 0;
    var_r31_2478 = 0;
loop_4:
    if (var_r29_2477 < (s32) this->unk10) {
        temp_r4_2481 = *(this + var_r31_2478);
        if ((u32) M2C_FIELD(M2C_FIELD(temp_r4_2481, void **, 0x28), u32 *, 0x18) == 0U) {
            M2C_FIELD(M2C_FIELD(*(this + var_r31_2478), void **, 0x28), s8 **, 0x18) = MKArchive_Load(Str_Printf("%s%s", temp_r4_2481, ".ang"), NULL, NULL, -1);
        }
        var_r29_2477 += 1;
        var_r31_2478 += 4;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'Animation' to
void *Animation::GetTemplate(float arg0) {
    s32 temp_r5_2518;
    s32 var_ctr_2519;
    s32 var_r4_2515;
    void *temp_r6_2523;

    var_r4_2515 = 0;
    temp_r5_2518 = this->unk10;
    var_ctr_2519 = temp_r5_2518;
    if (temp_r5_2518 > 0) {
loop_1:
        temp_r6_2523 = *(this + var_r4_2515);
        if (arg0 < (f32) M2C_FIELD(M2C_FIELD(temp_r6_2523, void **, 0x28), u16 *, 6)) {
            return temp_r6_2523;
        }
        var_r4_2515 += 4;
        var_ctr_2519 -= 1;
        if (var_ctr_2519 == 0) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return NULL;
}
#endif

#if 0 // DRAFT: pointer/array required
void Animation::LinkBlendShapeToNode(const char *arg0, const char *arg1) {
    s16 var_r31_2554;
    s32 temp_r5_2584;
    s32 var_r29_2555;
    void *temp_r3_2568;
    void *temp_r4_2590;

    var_r31_2554 = 0;
    var_r29_2555 = 0;
loop_3:
    temp_r3_2568 = M2C_FIELD(this->unk0, void **, 0x28);
    if (var_r31_2554 < (s8) M2C_FIELD(temp_r3_2568, u8 *, 8)) {
        if (strcmpi(*(M2C_FIELD(temp_r3_2568, s32 *, 0x1C) + var_r29_2555), arg0) != 0) {
            var_r31_2554 += 1;
            var_r29_2555 += 0x10;
            goto loop_3;
        }
    }
    if (var_r31_2554 != (s8) M2C_FIELD(M2C_FIELD(this->unk0, void **, 0x28), u8 *, 8)) {
        temp_r5_2584 = var_r31_2554 * 0x10;
        M2C_FIELD((M2C_FIELD(M2C_FIELD(this->unk0, void **, 0x28), s32 *, 0x1C) + temp_r5_2584), s8 *, 8) = GetNodeIndex(arg1);
        temp_r4_2590 = M2C_FIELD(this->unk0, void **, 0x28);
        M2C_FIELD((temp_r4_2590 + (M2C_FIELD((M2C_FIELD(temp_r4_2590, s32 *, 0x1C) + temp_r5_2584), u8 *, 8) << 5)), s16 *, 0x3C) = var_r31_2554;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
void Animation::Destroy() {
    MKHeap *temp_r3_2641;
    s32 temp_r0_2615;
    s8 *temp_r4_2626;
    void *temp_r3_2618;
    void *temp_r3_2625;
    void *temp_r3_2632;
    void *temp_r4_2613;
    void *temp_r4_2619;

    temp_r4_2613 = this->unk0;
    temp_r0_2615 = M2C_FIELD(temp_r4_2613, s32 *, 0x24) - 1;
    M2C_FIELD(temp_r4_2613, s32 *, 0x24) = temp_r0_2615;
    if (temp_r0_2615 == 0) {
        temp_r3_2618 = this->unk0;
        temp_r4_2619 = M2C_FIELD(temp_r3_2618, void **, 0x30);
        if (temp_r4_2619 != NULL) {
            M2C_FIELD(temp_r4_2619, s8 **, 0x2C) = (s8 *) M2C_FIELD(temp_r3_2618, s8 **, 0x2C);
        }
        temp_r3_2625 = this->unk0;
        temp_r4_2626 = M2C_FIELD(temp_r3_2625, s8 **, 0x2C);
        if (temp_r4_2626 != NULL) {
            M2C_FIELD(temp_r4_2626, void **, 0x30) = (void *) M2C_FIELD(temp_r3_2625, void **, 0x30);
        }
        temp_r3_2632 = this->unk0;
        if (temp_r3_2632 == (s8 *) Animation_pTemplates) {
            Animation_pTemplates = M2C_FIELD(temp_r3_2632, s8 **, 0x2C);
        }
        temp_r3_2641 = M2C_FIELD(this->unk0, MKHeap **, 0x28)->unk18;
        if (temp_r3_2641 != NULL) {
            temp_r3_2641->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        }
        ((MKHeap *) (M2C_FIELD(this->unk0, MKHeap **, 0x28)))->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        ((MKHeap *) this->unk0)->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        this->unk0 = NULL;
        this->unk10 = 0;
    }
    EnableCustomMatrices(0U);
    MKHeap::FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match
Animation *Animation::Create(const char *arg0, int arg1) {
    s8 spC;
    s32 sp8;
    MKHeap *temp_r3_2692;
    MKHeap *temp_r3_2695;
    MKHeap *temp_r3_2714;
    MKHeap *temp_r3_2790;
    MKHeap *temp_r3_2892;
    MKHeap *temp_r4_2740;
    MKHeap *temp_r5_2833;
    MKHeap *var_r27_2766;
    MKHeap *var_r29_2722;
    s16 var_r30_2843;
    s32 temp_r27_2709;
    s32 temp_r3_2774;
    s32 var_r27_2705;
    s32 var_r28_2768;
    s32 var_r28_2845;
    s32 var_r30_2696;
    s32 var_r3_2702;
    s32 var_r3_2806;
    s32 var_r4_2807;
    s32 var_r7_2804;
    s8 *temp_r26_2772;
    s8 *temp_r27_2849;
    u32 temp_ret_2851;
    u8 temp_r4_2697;
    void *temp_r6_2811;
    void *var_r3_2738;

    strcpy(&spC, (s8 *) this);
    strtok(&spC, ".");
    temp_r3_2692 = CreateTemplate(&spC);
    temp_r3_2695 = temp_r3_2692->unk28;
    var_r30_2696 = 0;
    temp_r4_2697 = M2C_FIELD(temp_r3_2695, u8 *, 4);
    var_r3_2702 = ((s8) temp_r4_2697 - 1) * 0x48;
    var_r27_2705 = var_r3_2702 + ((s8) M2C_FIELD(temp_r3_2695, u8 *, 8) * 0x48) + 0x78;
    if (arg0 != NULL) {
        var_r3_2702 = var_r27_2705 + 0xF;
        temp_r27_2709 = var_r3_2702 & 0xFFFFFFF0;
        var_r30_2696 = temp_r27_2709;
        var_r27_2705 = temp_r27_2709 + (((s8) temp_r4_2697 + 1) << 6);
    }
    temp_r3_2714 = ((MKHeap *) var_r3_2702)->Current();
    if (temp_r3_2714 != NULL) {
        var_r29_2722 = ((MKHeap *) (temp_r3_2714->Current()))->Alloc(var_r27_2705, NULL, 0);
    } else {
        var_r29_2722 = malloc(var_r27_2705);
    }
    memset(var_r29_2722, 0, (u32) var_r27_2705);
    var_r29_2722->unk0 = temp_r3_2692;
    var_r29_2722->unk10 = 1e-45f;
    ((Animation *) var_r29_2722)->ReloadGuts();
    var_r3_2738 = NULL;
    var_r29_2722->unk14 = 0;
    temp_r4_2740 = temp_r3_2692->unk28;
    if ((s8) M2C_FIELD(temp_r4_2740, u8 *, 8) != 0) {
        var_r3_2738 = var_r29_2722 + (((s8) M2C_FIELD(temp_r4_2740, u8 *, 4) * 0x48) + 0x30);
    }
    var_r29_2722->unk1C = var_r3_2738;
    var_r29_2722->unk20 = arg0;
    if (arg0 != NULL) {
        var_r29_2722->unk18 = M2C_BITWISE(f32, (var_r29_2722 + var_r30_2696));
    } else {
        var_r29_2722->unk18 = 0.0f;
    }
    M2C_FIELD(var_r29_2722, s8 *, 0x24) = 1;
    var_r27_2766 = NULL;
    var_r29_2722->unk28 = (MKHeap *)-1;
    var_r28_2768 = 0;
loop_15:
    temp_r3_2790 = var_r29_2722->unk0->unk28;
    if (var_r27_2766 < (s8) M2C_FIELD(temp_r3_2790, u8 *, 4)) {
        temp_r26_2772 = *(temp_r3_2790 + (var_r28_2768 + 0x30));
        temp_r3_2774 = strlen(temp_r26_2772);
        if ((temp_r3_2774 >= 4) && (stricmp("_lve", &temp_r26_2772[temp_r3_2774] - 4) == 0)) {
            var_r29_2722->unk28 = var_r27_2766;
        } else {
            var_r27_2766 += 1;
            var_r28_2768 += 0x20;
            goto loop_15;
        }
    }
    memset(&var_r29_2722->unk30, 0, (s8) M2C_FIELD(temp_r3_2692->unk28, u8 *, 4) * 0x48);
    var_r7_2804 = 0;
    var_r3_2806 = 0;
    var_r4_2807 = 0;
loop_18:
    temp_r5_2833 = temp_r3_2692->unk28;
    if (var_r7_2804 < (s8) M2C_FIELD(temp_r5_2833, u8 *, 4)) {
        temp_r6_2811 = var_r29_2722 + var_r3_2806;
        M2C_FIELD(temp_r6_2811, void **, 0x60) = (void *) (temp_r5_2833 + (var_r4_2807 + 0x20));
        var_r7_2804 += 1;
        var_r3_2806 += 0x48;
        var_r4_2807 += 0x20;
        M2C_FIELD(temp_r6_2811, f32 *, 0x40) = 0.0f;
        M2C_FIELD(temp_r6_2811, f32 *, 0x44) = 0.0f;
        M2C_FIELD(temp_r6_2811, f32 *, 0x48) = 0.0f;
        M2C_FIELD(temp_r6_2811, f32 *, 0x4C) = 1.0f;
        M2C_FIELD(temp_r6_2811, s16 *, 0x64) = 0;
        M2C_FIELD(temp_r6_2811, u8 *, 0x66) = (u8) (M2C_FIELD(temp_r6_2811, u8 *, 0x66) & ~0x80);
        M2C_FIELD(temp_r6_2811, s32 *, 0x70) = 0;
        M2C_FIELD(temp_r6_2811, u8 *, 0x66) = (u8) (M2C_FIELD(temp_r6_2811, u8 *, 0x66) & ~0x40);
        M2C_FIELD(temp_r6_2811, f32 *, 0x68) = 0.0f;
        M2C_FIELD(temp_r6_2811, f32 *, 0x6C) = 0.0f;
        goto loop_18;
    }
    ((Animation *) var_r29_2722)->Tween(0.0f, 1.0f);
    var_r30_2843 = 0;
    var_r28_2845 = 0;
loop_24:
    temp_r3_2892 = var_r29_2722->unk0->unk28;
    if (var_r30_2843 < (s8) M2C_FIELD(temp_r3_2892, u8 *, 8)) {
        temp_r27_2849 = *(temp_r3_2892->unk1C + var_r28_2845);
        temp_ret_2851 = strlen(temp_r27_2849);
        if (((Animation *) var_r29_2722)->NodeExists(Str_Printf("z%.*s", temp_ret_2851 - 4, temp_r27_2849 + 1, M2C_BITWISE(f32, temp_ret_2851)), &sp8) != 0) {
            *(var_r29_2722->unk0->unk28->unk1C + (var_r28_2845 + 8)) = (s8) sp8;
            *(var_r29_2722->unk0->unk28 + ((sp8 << 5) + 0x3C)) = var_r30_2843;
        } else {
            *(var_r29_2722->unk0->unk28->unk1C + (var_r28_2845 + 8)) = 0;
            M2C_FIELD(var_r29_2722->unk0->unk28, s16 *, 0x3C) = var_r30_2843;
        }
        var_r30_2843 += 1;
        var_r28_2845 += 0x10;
        goto loop_24;
    }
    ((Animation *) var_r29_2722)->LinkBlendShapeToNode("t_A002_Sparx_mouth_00", "z_A002_Jaw");
    ((Animation *) var_r29_2722)->LinkBlendShapeToNode("t_blendShape_00", "z_b2");
    return (Animation *) var_r29_2722;
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
MKHeap *CreateTemplate(const char *arg0) {
    s32 sp8;
    MKHeap *temp_r3_2959;
    s32 temp_r0_3009;
    s32 var_r4_3001;
    s32 var_r6_3003;
    s8 *temp_r3_2955;
    s8 *temp_r3_2978;
    s8 *temp_r5_3014;
    s8 *var_r31_2925;

    var_r31_2925 = Animation_pTemplates;
loop_4:
    if (var_r31_2925 != NULL) {
        if ((stricmp(var_r31_2925, arg0) != 0) || (((MKResource *) var_r31_2925)->IsResourceAvailable() == 0)) {
            var_r31_2925 = M2C_FIELD(var_r31_2925, s8 **, 0x2C);
            goto loop_4;
        }
    }
    if (var_r31_2925 != NULL) {
        M2C_FIELD(var_r31_2925, s32 *, 0x24) = (s32) (M2C_FIELD(var_r31_2925, s32 *, 0x24) + 1);
    } else {
        temp_r3_2955 = Str_Printf("%s.anm", arg0);
        temp_r3_2959 = ((MKHeap *) (MKArchive_Exists(temp_r3_2955, &sp8)))->Current();
        if (temp_r3_2959 != NULL) {
            var_r31_2925 = ((MKHeap *) (temp_r3_2959->Current()))->Alloc(0x34, NULL, 0);
        } else {
            var_r31_2925 = malloc(0x34);
        }
        memset(var_r31_2925, 0, 0x34U);
        temp_r3_2978 = Animation_pTemplates;
        Animation_pTemplates = var_r31_2925;
        M2C_FIELD(var_r31_2925, s8 **, 0x2C) = temp_r3_2978;
        M2C_FIELD(var_r31_2925, s32 *, 0x30) = 0;
        if (temp_r3_2978 != NULL) {
            M2C_FIELD(temp_r3_2978, s8 **, 0x30) = var_r31_2925;
        }
        strncpy(var_r31_2925, arg0, 0x1FU);
        M2C_FIELD(var_r31_2925, s8 **, 0x28) = MKArchive_Load(temp_r3_2955, &sp8, NULL, -1);
        ((AnimationData *) M2C_FIELD(var_r31_2925, s8 **, 0x28))->UnpackTemplatePointers(0U);
        var_r4_3001 = 0;
        var_r6_3003 = 0;
        M2C_FIELD(M2C_FIELD(var_r31_2925, s8 **, 0x28), s32 *, 0x18) = 0;
        M2C_FIELD(var_r31_2925, s32 *, 0x24) = 1;
loop_14:
        temp_r5_3014 = M2C_FIELD(var_r31_2925, s8 **, 0x28);
        if (var_r6_3003 < (s8) M2C_FIELD(temp_r5_3014, u8 *, 4)) {
            temp_r0_3009 = var_r4_3001 + 0x3C;
            var_r4_3001 += 0x20;
            temp_r5_3014[temp_r0_3009] = -1;
            var_r6_3003 += 1;
            goto loop_14;
        }
        ((MKResource *) var_r31_2925)->InitialiseResource();
    }
    return (MKHeap *) var_r31_2925;
}
#endif

void Animation_DeinitModule() {
    MKHeap *temp_r3_3041;
    s8 *temp_r30_3040;
    s8 *var_r31_3037;

    var_r31_3037 = Animation_pTemplates;
loop_5:
    if (var_r31_3037 != NULL) {
        temp_r30_3040 = M2C_FIELD(var_r31_3037, s8 **, 0x2C);
        temp_r3_3041 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_3041 != NULL) {
            ((MKHeap *) (temp_r3_3041->Current()))->Free(var_r31_3037, NULL, 0);
        } else {
            free(var_r31_3037);
        }
        var_r31_3037 = temp_r30_3040;
        goto loop_5;
    }
}

void Animation_InitModule() {

}

void DecompressVector(short *arg0, float *arg1) {
    s32 sp8;
    s16 temp_r6_3080;
    s16 temp_r6_3096;
    s16 temp_r6_3112;
    s16 temp_r7_3076;
    s32 temp_r0_3085;
    s32 temp_r0_3101;
    s32 temp_r0_3117;
    s32 temp_r3_3115;
    s32 temp_r5_3078;
    s32 temp_r5_3083;
    s32 temp_r5_3092;
    s32 temp_r5_3099;
    s32 temp_r5_3108;

    temp_r7_3076 = M2C_FIELD(arg0, s16 *, 6);
    sp8 = 0;
    temp_r5_3078 = ((u32) temp_r7_3076 >> 0xAU) & 0x1F;
    if (temp_r5_3078 != 0) {
        temp_r6_3080 = M2C_FIELD(arg0, s16 *, 0);
        temp_r5_3083 = (temp_r6_3080 << 0x10) & 0x80000000;
        sp8 = temp_r5_3083;
        temp_r0_3085 = temp_r5_3083 | ((temp_r5_3078 + 0x70) << 0x17);
        sp8 = temp_r0_3085;
        sp8 = (temp_r0_3085 & ~0x7FFF00) | ((temp_r6_3080 << 8) & 0x7FFF00);
    }
    temp_r5_3092 = ((u32) temp_r7_3076 >> 5U) & 0x1F;
    M2C_FIELD(arg1, f32 *, 0) = M2C_BITWISE(f32, sp8);
    sp8 = 0;
    if (temp_r5_3092 != 0) {
        temp_r6_3096 = M2C_FIELD(arg0, s16 *, 2);
        temp_r5_3099 = (temp_r6_3096 << 0x10) & 0x80000000;
        sp8 = temp_r5_3099;
        temp_r0_3101 = temp_r5_3099 | ((temp_r5_3092 + 0x70) << 0x17);
        sp8 = temp_r0_3101;
        sp8 = (temp_r0_3101 & ~0x7FFF00) | ((temp_r6_3096 << 8) & 0x7FFF00);
    }
    temp_r5_3108 = temp_r7_3076 & 0x1F;
    M2C_FIELD(arg1, f32 *, 4) = M2C_BITWISE(f32, sp8);
    sp8 = 0;
    if (temp_r5_3108 != 0) {
        temp_r6_3112 = M2C_FIELD(arg0, s16 *, 4);
        temp_r3_3115 = (temp_r6_3112 << 0x10) & 0x80000000;
        sp8 = temp_r3_3115;
        temp_r0_3117 = temp_r3_3115 | ((temp_r5_3108 + 0x70) << 0x17);
        sp8 = temp_r0_3117;
        sp8 = (temp_r0_3117 & ~0x7FFF00) | ((temp_r6_3112 << 8) & 0x7FFF00);
    }
    M2C_FIELD(arg1, f32 *, 8) = M2C_BITWISE(f32, sp8);
}

void Animation_cpp::__sinit() {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.00006103888f;
    spC = 0.00006103888f;
    sp10 = 0.00006103888f;
    sp14 = 0.00006103888f;
    M2C_FIELD(&fixedPointScaleVec, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&fixedPointScaleVec, f64 *, 8) = (f64) sp10;
}

#include "spyro/source/KDShatter2.h"
#include "common/Source/Animation.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(u16 *);                                /* extern */
u16 *malloc(s32);                                   /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern KDShatterPool **shatterPool;

void ShatterPoolFifo() {
    KDShatterPool *temp_r3_15;

    temp_r3_15 = *shatterPool;
    if (temp_r3_15 != NULL) {
        temp_r3_15->unk164C->Finish();
    }
}

f32 KDShatter2::GetRadius(int arg0) {
    f64 sp10;
    f64 sp8;
    MKHeap **temp_r3_36;

    temp_r3_36 = MKModel_GetBoundingVolume(this->unk4C, (SubObjectType) 0, arg0);
    sp8 = M2C_FIELD(temp_r3_36, f64 *, 0x10);
    sp10 = M2C_FIELD(temp_r3_36, f64 *, 0x18);
    return ((f32) sp10 + ((f32) sp8 + (*(f32 *) ((u8 *) &sp8 + 0x4)))) / 6.0f;
}

void KDShatter2::SetVisible(unsigned short *arg0) {
    s32 var_r30_63;
    s32 var_r31_64;

    var_r30_63 = 0;
    var_r31_64 = 0;
loop_2:
    if ((arg0 != NULL) && (var_r30_63 < (s32) *arg0)) {
        MKModel_EnableSubObject(this->unk4C, (SubObjectType) 0, (s32) *(arg0 + (var_r31_64 + 2)), 1U, 1U);
        var_r30_63 += 1;
        var_r31_64 += 2;
        goto loop_2;
    }
}

void KDShatter2::ClearVisible() {
    s16 temp_r31_101;
    s32 var_r30_102;

    temp_r31_101 = MKModel_GetNmbrOfSubObjects(this->unk4C, (SubObjectType) 0);
    var_r30_102 = 0;
loop_2:
    if (var_r30_102 < temp_r31_101) {
        MKModel_EnableSubObject(this->unk4C, (SubObjectType) 0, var_r30_102, 0U, 1U);
        var_r30_102 += 1;
        goto loop_2;
    }
}

void KDShatter2::Draw(bool arg0) {
    f32 temp_f1_201;
    s32 temp_r0_159;
    s32 temp_r4_133;
    u16 *temp_r3_136;
    u16 *temp_r3_146;
    u16 *temp_r3_164;
    u16 *temp_r4_222;

    temp_r4_133 = this->unk44;
    if (temp_r4_133 == 0) {
        temp_r3_136 = this->unk54;
        if (temp_r3_136 != NULL) {
            if ((u16) *temp_r3_136 == 0) {
                return;
            }
            goto block_4;
        }
    } else {
block_4:
        if (temp_r4_133 == 2) {
            temp_r3_146 = this->unk5C;
            if (temp_r3_146 != NULL) {
                if ((u16) *temp_r3_146 == 0) {
                    return;
                }
                goto block_8;
            }
        } else {
block_8:
            MKModel_EnableScissoring(this->unk4C, 0U);
            if (arg0 != 0) {
                temp_r0_159 = this->unk44;
                if ((temp_r0_159 == 0) || (temp_r0_159 == 2) || ((temp_r3_164 = this->unk58, ((temp_r3_164 == NULL) == 0)) && ((u16) *temp_r3_164 != 0))) {
                    ClearVisible();
                    SetVisible(this->unk54);
                    MKModel_Draw(this->unk4C, NULL);
                }
            } else {
                if ((s32) this->unk44 == 1) {
                    ClearVisible();
                    SetVisible(this->unk58);
                    MKModel_Draw(this->unk4C, NULL);
                    ClearVisible();
                    SetVisible(this->unk48);
                    if ((u8) this->unk60 == 0) {
                        temp_f1_201 = MKModel_GetAlpha(this->unk4C);
                        MKModel_SetAlpha(this->unk4C, temp_f1_201 * this->unk34);
                        MKModel_Draw(this->unk4C, NULL);
                        MKModel_SetAlpha(this->unk4C, temp_f1_201);
                        return;
                    }
                    MKModel_Draw(this->unk4C, NULL);
                    return;
                }
                ClearVisible();
                temp_r4_222 = this->unk5C;
                if ((u16) *temp_r4_222 != 0) {
                    SetVisible(temp_r4_222);
                    MKModel_Draw(this->unk4C, NULL);
                }
            }
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'KDShatterPool *' to
void KDShatter2::Update() {
    Matrix sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    KDShatterPool *temp_r3_642;
    KDShatterPool *temp_r4_268;
    KDShatterPool *temp_r5_298;
    KDShatterPool *temp_r6_496;
    Matrix *temp_r30_311;
    f32 temp_f0_381;
    f32 temp_f0_527;
    f32 temp_f10_529;
    f32 temp_f12_503;
    f32 temp_f13_510;
    f32 temp_f1_456;
    f32 temp_f1_515;
    f32 temp_f25_509;
    f32 temp_f26_502;
    f32 temp_f28_519;
    f32 temp_f29_283;
    f32 temp_f2_370;
    f32 temp_f2_455;
    f32 temp_f2_523;
    f32 temp_f30_347;
    f32 temp_f31_462;
    f32 temp_f3_272;
    f32 temp_f3_348;
    f32 temp_f3_507;
    f32 temp_f4_271;
    f32 temp_f4_417;
    f32 temp_f4_513;
    f32 temp_f5_415;
    f32 temp_f5_521;
    f32 temp_f6_517;
    f32 temp_f8_410;
    f32 temp_f8_500;
    f32 temp_f9_525;
    f32 var_f1_591;
    f64 temp_f0_323;
    f64 temp_f0_350;
    f64 temp_f0_368;
    f64 temp_f1_377;
    s16 temp_r27_631;
    s32 var_r28_308;
    s32 var_r31_307;

    temp_r4_268 = this->unk50;
    if (temp_r4_268 != NULL) {
        temp_f4_271 = temp_r4_268->unk1648;
        temp_f3_272 = this->unk10;
        if (temp_f4_271 >= temp_f3_272) {
            Finish();
            return;
        }
        temp_f29_283 = gUpdateTimeDelta * this->unk38;
        if (temp_f4_271 > (temp_f3_272 - 1.0f)) {
            this->unk34 = temp_f3_272 - temp_f4_271;
        } else if (((u8) this->unk40 != 0) && ((s32) temp_r4_268->unk1640 != 0)) {
            SetHitPlane(temp_r4_268->unk1644);
            temp_r5_298 = this->unk50;
            temp_r5_298->unk1644 = (temp_r5_298->unk1644 + 1) % temp_r5_298->unk1640;
        }
        var_r31_307 = 0;
        var_r28_308 = 0;
loop_27:
        temp_r3_642 = this->unk50;
        if (var_r31_307 < (s32) temp_r3_642->unk1640) {
            temp_r30_311 = temp_r3_642 + var_r28_308;
            if ((u8) M2C_FIELD(temp_r30_311, u8 *, 0xA4) != 0) {
                sp190 = M2C_FIELD(temp_r30_311, f64 *, 0x40);
                sp198 = M2C_FIELD(temp_r30_311, f64 *, 0x48);
                temp_f0_323 = M2C_FIELD(temp_r30_311, f64 *, 0x80) - M2C_FIELD(temp_r30_311, f64 *, 0x40);
                spC0 = temp_f0_323;
                sp180 = temp_f0_323;
                spC8 = M2C_FIELD(temp_r30_311, f32 *, 0x88) - (f32) M2C_FIELD(temp_r30_311, f64 *, 0x48);
                M2C_FIELD(temp_r30_311, f32 *, 0x54) = (f32) -((this->unk0 * temp_f29_283) - M2C_FIELD(temp_r30_311, f32 *, 0x54));
                sp188 = (f64) spC8;
                temp_f30_347 = this->unk8 * temp_f29_283;
                temp_f3_348 = ((f32) sp188 * M2C_FIELD(temp_r30_311, f32 *, 0x78)) + (((f32) sp180 * M2C_FIELD(temp_r30_311, f32 *, 0x70)) + ((*(f32 *) ((u8 *) &sp180 + 0x4)) * M2C_FIELD(temp_r30_311, f32 *, 0x74)));
                temp_f0_350 = M2C_FIELD(temp_r30_311, f64 *, 0x50) * (f64) temp_f30_347;
                sp50 = temp_f0_350;
                sp130 = temp_f0_350;
                sp58 = M2C_FIELD(temp_r30_311, f32 *, 0x58) * temp_f30_347;
                sp138 = (f64) sp58;
                M2C_FIELD(temp_r30_311, f64 *, 0x50) = (f64) (M2C_FIELD(temp_r30_311, f64 *, 0x50) - temp_f0_350);
                M2C_FIELD(temp_r30_311, f32 *, 0x58) = (f32) (M2C_FIELD(temp_r30_311, f32 *, 0x58) - (f32) sp138);
                temp_f0_368 = M2C_FIELD(temp_r30_311, f64 *, 0x50) * (f64) temp_f29_283;
                spB0 = temp_f0_368;
                temp_f2_370 = M2C_FIELD(temp_r30_311, f32 *, 0x58);
                sp120 = temp_f0_368;
                spB8 = temp_f2_370 * temp_f29_283;
                sp128 = (f64) spB8;
                temp_f1_377 = M2C_FIELD(temp_r30_311, f64 *, 0x40);
                spA0 = temp_f1_377 + temp_f0_368;
                temp_f0_381 = (f32) M2C_FIELD(temp_r30_311, f64 *, 0x48);
                sp170 = spA0;
                spA8 = temp_f0_381 + (f32) sp128;
                sp178 = (f64) spA8;
                sp40 = M2C_FIELD(temp_r30_311, f64 *, 0x80) - sp170;
                sp180 = sp40;
                sp48 = M2C_FIELD(temp_r30_311, f32 *, 0x88) - (f32) sp178;
                sp188 = (f64) sp48;
                sp110 = sp40;
                temp_f8_410 = ((f32) sp188 * M2C_FIELD(temp_r30_311, f32 *, 0x78)) + (((f32) sp180 * M2C_FIELD(temp_r30_311, f32 *, 0x70)) + ((*(f32 *) ((u8 *) &sp180 + 0x4)) * M2C_FIELD(temp_r30_311, f32 *, 0x74)));
                sp118 = (f64) sp48;
                if (temp_f8_410 > 0.0f) {
                    temp_f5_415 = (f32) M2C_FIELD(temp_r30_311, f64 *, 0x50);
                    temp_f4_417 = M2C_FIELD(temp_r30_311, f32 *, 0x54);
                    if (((temp_f2_370 * temp_f2_370) + ((temp_f5_415 * temp_f5_415) + (temp_f4_417 * temp_f4_417))) < 100.0f) {
                        M2C_FIELD(temp_r30_311, f32 *, 0x6C) = 0.0f;
                    } else {
                        sp10 = sp170 - temp_f1_377;
                        sp18 = (f32) sp178 - temp_f0_381;
                        spF0 = sp10;
                        spF8 = (f64) sp18;
                        sp100.operator*(temp_f3_348 / (temp_f3_348 - temp_f8_410));
                        sp30 = M2C_FIELD(temp_r30_311, f64 *, 0x40) + M2C_BITWISE(f64, sp100);
                        temp_f2_455 = M2C_FIELD(temp_r30_311, f32 *, 0x58);
                        temp_f1_456 = M2C_FIELD(temp_r30_311, f32 *, 0x78);
                        temp_f31_462 = (1.0f + this->unk4) * ((temp_f2_455 * temp_f1_456) + (((f32) M2C_FIELD(temp_r30_311, f64 *, 0x50) * M2C_FIELD(temp_r30_311, f32 *, 0x70)) + (M2C_FIELD(temp_r30_311, f32 *, 0x54) * M2C_FIELD(temp_r30_311, f32 *, 0x74))));
                        sp38 = (f32) M2C_FIELD(temp_r30_311, f64 *, 0x48) + sp100.unk8;
                        sp90 = (f64) M2C_FIELD(temp_r30_311, f32 *, 0x70) * (f64) temp_f31_462;
                        sp98 = temp_f1_456 * temp_f31_462;
                        spE0 = sp90;
                        spE8 = (f64) sp98;
                        sp80 = M2C_FIELD(temp_r30_311, f64 *, 0x50) - spE0;
                        M2C_FIELD(temp_r30_311, f64 *, 0x50) = sp80;
                        sp88 = temp_f2_455 - (f32) spE8;
                        sp160 = sp80;
                        M2C_FIELD(temp_r30_311, f32 *, 0x58) = (f64) sp88;
                        sp168 = (f64) sp88;
                        M2C_FIELD(temp_r30_311, f32 *, 0x6C) = (f32) (M2C_FIELD(temp_r30_311, f32 *, 0x6C) * 0.75f);
                    }
                } else {
                    M2C_FIELD(temp_r30_311, f64 *, 0x40) = spA0;
                    M2C_FIELD(temp_r30_311, f64 *, 0x48) = (f64) spA8;
                }
                temp_r6_496 = this->unk50;
                temp_f8_500 = temp_r6_496->unk1600.unk10;
                temp_f26_502 = temp_r6_496->unk1600.unk14;
                temp_f12_503 = temp_r6_496->unk1600.unk18;
                temp_f3_507 = temp_r6_496->unk1600.unk0;
                temp_f25_509 = temp_r6_496->unk1600.unk4;
                temp_f13_510 = temp_r6_496->unk1600.unk8;
                temp_f4_513 = temp_r6_496->unk1600.unk20;
                temp_f1_515 = temp_r6_496->unk1600.unk24;
                temp_f6_517 = M2C_FIELD(temp_r30_311, f32 *, 0x44);
                temp_f28_519 = temp_r6_496->unk1600.unk28;
                temp_f5_521 = temp_r6_496->unk1600.unk30;
                temp_f2_523 = temp_r6_496->unk1600.unk34;
                temp_f9_525 = (f32) M2C_FIELD(temp_r30_311, f64 *, 0x40);
                temp_f0_527 = temp_r6_496->unk1600.unk38;
                temp_f10_529 = (f32) M2C_FIELD(temp_r30_311, f64 *, 0x48);
                sp70 = temp_f5_521 + (((f32) sp198 * temp_f4_513) + (((f32) sp190 * temp_f3_507) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * temp_f8_500)));
                sp74 = temp_f2_523 + (((f32) sp198 * temp_f1_515) + (((f32) sp190 * temp_f25_509) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * temp_f26_502)));
                sp78 = temp_f0_527 + (((f32) sp198 * temp_f28_519) + (((f32) sp190 * temp_f13_510) + ((*(f32 *) ((u8 *) &sp190 + 0x4)) * temp_f12_503)));
                sp150 = (f64) sp70;
                sp158 = (f64) sp78;
                sp60 = temp_f5_521 + ((temp_f10_529 * temp_f4_513) + ((temp_f9_525 * temp_f3_507) + (temp_f6_517 * temp_f8_500)));
                sp64 = temp_f2_523 + ((temp_f10_529 * temp_f1_515) + ((temp_f9_525 * temp_f25_509) + (temp_f6_517 * temp_f26_502)));
                sp68 = temp_f0_527 + ((temp_f10_529 * temp_f28_519) + ((temp_f9_525 * temp_f13_510) + (temp_f6_517 * temp_f12_503)));
                sp28 = -(f32) sp158;
                sp20 = -(f32) sp150;
                sp24 = -(*(f32 *) ((u8 *) &sp150 + 0x4));
                sp140 = (f64) sp60;
                sp148 = (f64) sp68;
                spD0 = (f64) sp20;
                spD8 = (f64) sp28;
                temp_r30_311->Translate(temp_r30_311, *((MKVector3 *) &spD0));
                M2C_STRUCT_COPY((s32) &unksp19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp1A0.SetRotateAroundAxis(*(temp_r30_311 + 0x60), M2C_FIELD(temp_r30_311, f32 *, 0x6C) * gUpdateTimeDelta);
                if ((u8) this->unk60 != 0) {
                    var_f1_591 = this->unk34;
                    if (var_f1_591 < 1.0f) {
                        if (var_f1_591 < 1.0f) {

                        } else {
                            var_f1_591 = 1.0f;
                        }
                        if (var_f1_591 > 0.01f) {

                        } else {
                            var_f1_591 = 0.01f;
                        }
                        sp1A0.Scale3x3(&sp1A0, var_f1_591);
                    }
                }
                temp_r30_311->Multiply(temp_r30_311, &sp1A0);
                temp_r30_311->Translate(temp_r30_311, *((MKVector3 *) &sp140));
                if (MKModel_GetAnimation(this->unk4C) != NULL) {
                    temp_r27_631 = MKModel_GetSubObjectBoneIndex(this->unk4C, (SubObjectType) 0, M2C_FIELD(temp_r30_311, s32 *, 0xA0));
                    ((Animation *) (MKModel_GetAnimation(this->unk4C)))->SetCustomMatrix((s32) temp_r27_631, temp_r30_311, (AnimationMatrixPosition) 4, 0U);
                }
            }
            var_r31_307 += 1;
            var_r28_308 += 0xB0;
            goto loop_27;
        }
        temp_r3_642->unk1648 += temp_f29_283;
    }
}
#endif

void KDShatter2::Finish() {
    KDShatterPool **temp_r3_700;
    KDShatterPool **var_r5_694;
    KDShatterPool *temp_r3_710;
    KDShatterPool *temp_r4_703;

    this->unk44 = 2;
    SetVisible(this->unk5C);
    if ((KDShatterPool *) this->unk50 != NULL) {
        EnableSubObjectMatrices(0U);
        ResetSubObjectMatrices();
        var_r5_694 = shatterPool;
loop_5:
        temp_r3_710 = *var_r5_694;
        if (temp_r3_710 != NULL) {
            if (temp_r3_710 == (KDShatterPool *) this->unk50) {
                temp_r3_700 = shatterPool;
                shatterPool = temp_r3_700 + 4;
                temp_r4_703 = *temp_r3_700;
                *temp_r3_700 = *var_r5_694;
                *var_r5_694 = temp_r4_703;
            }
            var_r5_694 += 4;
            goto loop_5;
        }
        this->unk50 = NULL;
    }
}

#if 0 // DRAFT: function call 'MKModel_GetSubObjectBoneIndex(MKModel *, SubObjectType,
void KDShatter2::ResetSubObjectMatrices() {
    KDShatterPool *temp_r4_759;
    KDShatterPool *temp_r4_778;
    s16 temp_r29_749;
    s32 var_r30_738;
    s32 var_r30_765;
    s32 var_r31_739;
    s32 var_r31_766;

    if ((KDShatterPool *) this->unk50 != NULL) {
        if (MKModel_GetAnimation(this->unk4C) != NULL) {
            var_r30_738 = 0;
            var_r31_739 = 0;
loop_4:
            temp_r4_759 = this->unk50;
            if (var_r30_738 < (s32) temp_r4_759->unk1640) {
                temp_r29_749 = MKModel_GetSubObjectBoneIndex(this->unk4C, (SubObjectType) 0, *(temp_r4_759 + (var_r31_739 + 0xA0)));
                ((Animation *) (MKModel_GetAnimation(this->unk4C)))->SetCustomMatrix((s32) temp_r29_749, NULL, (AnimationMatrixPosition) 4, 0U);
                var_r30_738 += 1;
                var_r31_739 += 0xB0;
                goto loop_4;
            }
            return;
        }
        var_r30_765 = 0;
        var_r31_766 = 0;
loop_8:
        temp_r4_778 = this->unk50;
        if (var_r30_765 < (s32) temp_r4_778->unk1640) {
            MKModel_SetSubObjectLocalMatrix(this->unk4C, (SubObjectType) 0, *(temp_r4_778 + (var_r31_766 + 0xA0)), NULL);
            var_r30_765 += 1;
            var_r31_766 += 0xB0;
            goto loop_8;
        }
    }
}
#endif

void KDShatter2::Reset() {
    Finish();
    this->unk34 = 1.0f;
    this->unk44 = 0;
    SetVisible(this->unk54);
    ResetSubObjectMatrices();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void KDShatter2::SetHitPlane(int arg0) {
    MKCollisionResult spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_868;
    f32 temp_f1_893;
    f32 temp_f31_833;
    f64 temp_f0_852;
    f64 temp_f0_863;
    s32 var_r29_830;
    void *temp_r30_831;

    var_r29_830 = 0;
    temp_r30_831 = this->unk50 + (arg0 * 0xB0);
    temp_f31_833 = gUpdateTimeDelta * this->unk38;
    sp98 = M2C_FIELD(temp_r30_831, f64 *, 0x50);
    spA0 = M2C_FIELD(temp_r30_831, f64 *, 0x58);
    sp88 = M2C_FIELD(temp_r30_831, f64 *, 0x40);
    sp90 = M2C_FIELD(temp_r30_831, f64 *, 0x48);
loop_2:
    if (var_r29_830 <= (s32) this->unk50->unk1640) {
        (*(f32 *) ((u8 *) &sp98 + 0x4)) = -((this->unk0 * temp_f31_833) - (*(f32 *) ((u8 *) &sp98 + 0x4)));
        sp68.operator*(this->unk8);
        temp_f0_852 = sp68 * (f64) temp_f31_833;
        sp28 = temp_f0_852;
        sp78 = temp_f0_852;
        sp30 = sp68.unk8 * temp_f31_833;
        sp80 = (f64) sp30;
        temp_f0_863 = sp98 - temp_f0_852;
        sp98 = temp_f0_863;
        temp_f0_868 = (f32) spA0 - (f32) sp80;
        spA0 = temp_f0_868;
        sp18 = temp_f0_863 * (f64) temp_f31_833;
        sp20 = temp_f0_868 * temp_f31_833;
        sp58 = sp18;
        sp60 = (f64) sp20;
        sp88 += sp58;
        var_r29_830 += 1;
        sp90 = (f32) sp90 + (f32) sp60;
        goto loop_2;
    }
    temp_f1_893 = GetRadius(M2C_FIELD(temp_r30_831, s32 *, 0xA0));
    (*(f32 *) ((u8 *) &sp88 + 0x4)) -= temp_f1_893;
    M2C_FIELD(temp_r30_831, f32 *, 0x80) = 0.0f;
    M2C_FIELD(temp_r30_831, f32 *, 0x84) = -1000000.0f;
    M2C_FIELD(temp_r30_831, f32 *, 0x88) = 0.0f;
    M2C_FIELD(temp_r30_831, f32 *, 0x70) = 0.0f;
    M2C_FIELD(temp_r30_831, f32 *, 0x74) = 1.0f;
    M2C_FIELD(temp_r30_831, f32 *, 0x78) = 0.0f;
    if (MKCollision_RayCollide(*(temp_r30_831 + 0x40), *((MKVector3 *) &sp88), &spA8, (MKCollisionMode) 7, this->unk30) != 0) {
        M2C_FIELD(temp_r30_831, f32 *, 0x70) = (f64) spA8.unk10;
        M2C_FIELD(temp_r30_831, f32 *, 0x78) = (f64) spA8.unk18;
        MKVector(0.0f, temp_f1_893, 0.0f);
        sp8 = M2C_BITWISE(f64, spA8) + sp38;
        M2C_FIELD(temp_r30_831, f32 *, 0x80) = sp8;
        sp10 = spA8.unk8 + sp40;
        sp48 = sp8;
        sp50 = (f64) sp10;
        M2C_FIELD(temp_r30_831, f32 *, 0x88) = (f64) sp10;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void KDShatter2::SetInitialGroundPlane() {
    MKCollisionResult spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    KDShatterPool *temp_r3_1056;
    f64 temp_f0_995;
    s32 var_r30_1023;
    s32 var_r31_1025;
    void *temp_r29_1029;

    MKModel_CalculateCentre(this->unk4C, &spB8);
    sp50 = 0.0f;
    sp40 = 0.0f;
    sp48 = 0.0f;
    sp4C = 1.0f;
    sp38 = 0.0f;
    sp3C = -1000000.0f;
    spA8 = (f64) sp48;
    spB0 = (f64) sp50;
    sp98 = (f64) sp38;
    spA0 = (f64) sp40;
    if ((u8) this->unk40 != 0) {
        sp30 = 0.0f;
        sp28 = 0.0f;
        sp2C = 1000000.0f;
        sp80 = (f64) sp30;
        sp78 = (f64) sp28;
        temp_f0_995 = M2C_BITWISE(f64, spB8) - sp78;
        sp18 = temp_f0_995;
        sp88 = temp_f0_995;
        sp20 = spB8.unk8 - (f32) sp80;
        sp90 = (f64) sp20;
        if (MKCollision_RayCollide(spB8, *((MKVector3 *) &sp88), &spC8, (MKCollisionMode) 7, this->unk30) != 0) {
            spA8 = (f64) spC8.unk10;
            spB0 = (f64) spC8.unk18;
            sp98 = M2C_BITWISE(f64, spC8);
            spA0 = (f64) spC8.unk8;
        }
        var_r30_1023 = 0;
        var_r31_1025 = 0;
loop_5:
        temp_r3_1056 = this->unk50;
        if (var_r30_1023 < (s32) temp_r3_1056->unk1640) {
            temp_r29_1029 = temp_r3_1056 + var_r31_1025;
            M2C_FIELD(temp_r29_1029, f64 *, 0x70) = spA8;
            M2C_FIELD(temp_r29_1029, f64 *, 0x78) = spB0;
            MKVector(0.0f, GetRadius(M2C_FIELD(temp_r29_1029, s32 *, 0xA0)), 0.0f);
            sp8 = sp98 + sp58;
            var_r30_1023 += 1;
            var_r31_1025 += 0xB0;
            M2C_FIELD(temp_r29_1029, f64 *, 0x80) = sp8;
            sp10 = (f32) spA0 + sp60;
            sp68 = sp8;
            sp70 = (f64) sp10;
            M2C_FIELD(temp_r29_1029, f64 *, 0x88) = (f64) sp10;
            goto loop_5;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp70'
void KDShatter2::Shatter(int arg0, MKVector3 *arg1) {
    f64 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
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
    KDShatterPool **temp_r3_1097;
    KDShatterPool *temp_r3_1189;
    MKVector3 *var_r4_1201;
    s32 var_r27_1105;
    s32 var_r28_1106;
    s32 var_r4_1116;
    s32 var_r6_1117;
    u16 *temp_r5_1119;
    void *temp_r26_1109;

    if ((KDShatterPool *) this->unk50 != NULL) {
        Reset();
    }
    if ((u32) M2C_FIELD(shatterPool, u32 *, -4) == 0U) {
        ShatterPoolFifo();
    }
    temp_r3_1097 = shatterPool - 4;
    shatterPool = temp_r3_1097;
    this->unk50 = *temp_r3_1097;
    this->unk50->Init(this, this->unk4C, this->unk48);
    var_r27_1105 = 0;
    var_r28_1106 = 0;
loop_12:
    temp_r3_1189 = this->unk50;
    if (var_r27_1105 < (s32) temp_r3_1189->unk1640) {
        temp_r26_1109 = temp_r3_1189 + var_r28_1106;
        MKModel_EnableSubObject(this->unk4C, (SubObjectType) 0, M2C_FIELD(temp_r26_1109, s32 *, 0xA0), 1U, 1U);
        var_r4_1116 = 0;
        var_r6_1117 = 0;
        M2C_FIELD(temp_r26_1109, s8 *, 0xA4) = 0;
        temp_r5_1119 = this->unk48;
loop_9:
        if ((temp_r5_1119 != NULL) && (var_r6_1117 < (s32) *temp_r5_1119)) {
            if ((s32) M2C_FIELD(temp_r26_1109, s32 *, 0xA0) == (s32) *(temp_r5_1119 + (var_r4_1116 + 2))) {
                M2C_FIELD(temp_r26_1109, s8 *, 0xA4) = 1;
                KDRand_Box(this->unk18);
                M2C_FIELD(temp_r26_1109, f64 *, 0x50) = sp68;
                M2C_FIELD(temp_r26_1109, f64 *, 0x58) = sp70;
                M2C_FIELD(temp_r26_1109, f64 *, 0x50) = (f64) (M2C_FIELD(temp_r26_1109, f64 *, 0x50) + M2C_FIELD(this, f64 *, 0x20));
                sp10 = 1.0f;
                sp20 = -1.0f;
                M2C_FIELD(temp_r26_1109, f64 *, 0x58) = (f32) ((f32) M2C_FIELD(temp_r26_1109, f64 *, 0x58) + this->unk28);
                sp8 = 1.0f;
                spC = 1.0f;
                sp18 = -1.0f;
                sp1C = -1.0f;
                sp28 = (f64) sp8;
                sp30 = (f64) sp10;
                sp38 = (f64) sp18;
                sp40 = (f64) sp20;
                KDRand_Vector(sp48, *((MKVector3 *) &sp38));
                Normalise(sp58);
                M2C_FIELD(temp_r26_1109, f64 *, 0x60) = M2C_BITWISE(f64, sp58);
                M2C_FIELD(temp_r26_1109, f64 *, 0x68) = (f64) sp58.unk8;
                M2C_FIELD(temp_r26_1109, f32 *, 0x6C) = (f32) this->unk14;
            } else {
                var_r6_1117 += 1;
                var_r4_1116 += 2;
                goto loop_9;
            }
        }
        var_r27_1105 += 1;
        var_r28_1106 += 0xB0;
        goto loop_12;
    }
    EnableSubObjectMatrices(1U);
    if (arg0 != 0) {
        var_r4_1201 = MKModel_GetWorldMatrix(this->unk4C) + 0x30;
        if (arg1 != NULL) {
            var_r4_1201 = arg1;
        }
        KDSound_Play3d(arg0, var_r4_1201, 0U, -1, 0.0f, 0U);
    }
    SetInitialGroundPlane();
    this->unk44 = 1;
    SetVisible(this->unk58);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'KDShatterPool *' to
void KDShatter2::EnableSubObjectMatrices(bool arg0) {
    KDShatterPool *temp_r3_1262;
    Matrix *var_r6_1244;
    s32 temp_r5_1250;
    s32 var_r29_1240;
    s32 var_r31_1241;

    if (MKModel_GetAnimation(this->unk4C) == NULL) {
        var_r29_1240 = 0;
        var_r31_1241 = 0;
loop_8:
        temp_r3_1262 = this->unk50;
        if (var_r29_1240 < (s32) temp_r3_1262->unk1640) {
            var_r6_1244 = temp_r3_1262 + var_r31_1241;
            if ((u8) M2C_FIELD(var_r6_1244, u8 *, 0xA4) != 0) {
                temp_r5_1250 = M2C_FIELD(var_r6_1244, s32 *, 0xA0);
                if (arg0 != 0) {

                } else {
                    var_r6_1244 = NULL;
                }
                MKModel_SetSubObjectLocalMatrix(this->unk4C, (SubObjectType) 0, temp_r5_1250, var_r6_1244);
            }
            var_r29_1240 += 1;
            var_r31_1241 += 0xB0;
            goto loop_8;
        }
    }
}
#endif

void KDShatter2::SetVisibleUnshattered() {
    SetVisible(this->unk54);
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void KDShatter2::LoadDone(MKModel *arg0, unsigned short *arg1) {
    MKHeap *temp_r3_1302;
    MKHeap *temp_r3_1354;
    s16 temp_r29_1337;
    s16 var_r3_1336;
    s32 temp_r29_1301;
    s32 var_r27_1334;
    s32 var_r27_1372;
    s32 var_r28_1338;
    s32 var_r30_1371;
    u16 *var_r3_1309;
    u16 *var_r3_1316;
    u16 *var_r3_1362;
    u16 *var_r4_1317;
    u16 temp_r0_1320;
    u16 temp_r3_1299;
    u16 var_r28_1369;

    this->unk4C = arg0;
    if (arg1 != NULL) {
        temp_r3_1299 = *arg1;
        temp_r29_1301 = (temp_r3_1299 + 2) * 2;
        temp_r3_1302 = ((MKHeap *) temp_r3_1299)->Current();
        if (temp_r3_1302 != NULL) {
            var_r3_1309 = ((MKHeap *) (temp_r3_1302->Current()))->Alloc(temp_r29_1301, NULL, 0);
        } else {
            var_r3_1309 = malloc(temp_r29_1301);
        }
        this->unk48 = var_r3_1309;
        var_r3_1316 = arg1;
        var_r4_1317 = this->unk48;
loop_6:
        if ((u16) *var_r3_1316 != -1U) {
            temp_r0_1320 = *var_r3_1316;
            var_r3_1316 += 2;
            *var_r4_1317 = temp_r0_1320;
            var_r4_1317 += 2;
            goto loop_6;
        }
        *var_r4_1317 = 0xFFFF;
    } else {
        var_r27_1334 = 0;
        var_r3_1336 = MKModel_GetNmbrOfSubObjects(this->unk4C, (SubObjectType) 0);
        temp_r29_1337 = var_r3_1336;
        var_r28_1338 = 0;
loop_12:
        if (var_r28_1338 < temp_r29_1337) {
            var_r3_1336 = MKModel_IsSubObjectPrefixed(this->unk4C, (SubObjectType) 0, var_r28_1338, 0x66);
            if ((u8) var_r3_1336 != 0) {
                var_r27_1334 += 1;
            }
            var_r28_1338 += 1;
            goto loop_12;
        }
        temp_r3_1354 = ((MKHeap *) var_r3_1336)->Current();
        if (temp_r3_1354 != NULL) {
            var_r3_1362 = ((MKHeap *) (temp_r3_1354->Current()))->Alloc((var_r27_1334 + 2) * 2, NULL, 0);
        } else {
            var_r3_1362 = malloc((var_r27_1334 + 2) * 2);
        }
        var_r28_1369 = 0;
        this->unk48 = var_r3_1362;
        var_r30_1371 = 0;
        var_r27_1372 = 0;
loop_20:
        if (var_r27_1372 < temp_r29_1337) {
            if (MKModel_IsSubObjectPrefixed(this->unk4C, (SubObjectType) 0, var_r27_1372, 0x66) != 0) {
                var_r30_1371 += 2;
                var_r28_1369 += 1;
                *(this->unk48 + var_r30_1371) = (s16) var_r27_1372;
            }
            var_r27_1372 += 1;
            goto loop_20;
        }
        *this->unk48 = var_r28_1369;
        M2C_FIELD(&this->unk48[var_r28_1369], s16 *, 2) = 0xFFFF;
    }
    if (MKModel_GetAnimation(this->unk4C) != NULL) {
        ((Animation *) (MKModel_GetAnimation(this->unk4C)))->EnableCustomMatrices(1U);
    }
}
#endif

#if 0 // DRAFT: type mismatch
void KDShatter2::Deinit() {
    KDShatter2 *temp_r30_1423;
    KDShatter2 *var_r3_0;
    KDShatterPool **temp_r3_1433;
    KDShatterPool **var_r5_1427;
    KDShatterPool *temp_r4_1436;
    MKHeap *temp_r3_1450;
    u16 *temp_r31_1447;

    var_r3_0 = this;
    temp_r30_1423 = var_r3_0;
    if ((KDShatterPool *) var_r3_0->unk50 != NULL) {
        var_r5_1427 = shatterPool;
loop_5:
        var_r3_0 = (KDShatter2 *) *var_r5_1427;
        if (var_r3_0 != NULL) {
            if (var_r3_0 == (KDShatterPool *) temp_r30_1423->unk50) {
                temp_r3_1433 = shatterPool;
                shatterPool = temp_r3_1433 + 4;
                temp_r4_1436 = *temp_r3_1433;
                *temp_r3_1433 = *var_r5_1427;
                *var_r5_1427 = temp_r4_1436;
            }
            var_r5_1427 += 4;
            goto loop_5;
        }
    }
    temp_r31_1447 = temp_r30_1423->unk48;
    if (temp_r31_1447 != NULL) {
        temp_r3_1450 = ((MKHeap *) var_r3_0)->Current();
        if (temp_r3_1450 != NULL) {
            ((MKHeap *) (temp_r3_1450->Current()))->Free(temp_r31_1447, NULL, 0);
        } else {
            free(temp_r31_1447);
        }
    }
    temp_r30_1423->unk48 = NULL;
    temp_r30_1423->unk5C = NULL;
    temp_r30_1423->unk58 = NULL;
    temp_r30_1423->unk54 = NULL;
}
#endif

void KDShatter2::Init() {
    this->unk50 = NULL;
    this->unk0 = 2000.0f;
    this->unk4 = 0.35f;
    this->unk10 = 3.0f;
    this->unk8 = 0.0f;
    this->unk30 = 0;
    this->unk14 = 4.0f;
    this->unk18 = 1250.0f;
    this->unk38 = 1.0f;
    this->unk34 = 1.0f;
    this->unk3C = 400.0f;
    this->unk20 = 0.0f;
    this->unk24 = 0.0f;
    this->unk28 = 0.0f;
    this->unk44 = 0;
    this->unk48 = NULL;
    this->unk40 = 1;
    this->unk5C = NULL;
    this->unk58 = NULL;
    this->unk54 = NULL;
}

#if 0 // DRAFT: type mismatch
void KDShatter2::DeinitModule() {
    KDShatterPool **var_r31_1519;
    KDShatterPool **var_r3_1520;
    KDShatterPool **var_r4_1518;
    KDShatterPool *temp_r0_1523;
    KDShatterPool *temp_r0_1542;
    MKHeap *temp_r3_1545;
    u32 temp_r0_1528;

    var_r4_1518 = shatterPool;
    var_r31_1519 = var_r4_1518;
    var_r3_1520 = var_r4_1518;
loop_3:
    temp_r0_1528 = M2C_FIELD(var_r3_1520, u32 *, -4);
    var_r3_1520 -= 4;
    if (temp_r0_1528 != 0U) {
        temp_r0_1523 = *var_r3_1520;
        if (temp_r0_1523 < var_r31_1519) {
            var_r31_1519 = &temp_r0_1523->unk0;
        }
        goto loop_3;
    }
    if (var_r3_1520 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_1542 = *var_r4_1518;
        if (temp_r0_1542 != NULL) {
            if (temp_r0_1542 < var_r31_1519) {
                var_r31_1519 = &temp_r0_1542->unk0;
            }
            var_r4_1518 += 4;
            goto loop_9;
        }
        temp_r3_1545 = ((MKHeap *) var_r3_1520)->Current();
        if (temp_r3_1545 != NULL) {
            ((MKHeap *) (temp_r3_1545->Current()))->Free(var_r31_1519, NULL, 0);
        } else {
            free((u16 *) var_r31_1519);
        }
    }
    shatterPool = NULL;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void KDShatter2::InitModule() {
    MKHeap *temp_r3_1573;
    s32 var_ctr_1595;
    u16 *var_r3_1581;

    temp_r3_1573 = MKHeap::Current();
    if (temp_r3_1573 != NULL) {
        var_r3_1581 = ((MKHeap *) (temp_r3_1573->Current()))->Alloc(0x30D84, NULL, 0);
    } else {
        var_r3_1581 = malloc(0x30D84);
    }
    shatterPool = (KDShatterPool **) var_r3_1581;
    shatterPool = (KDShatterPool **) (var_r3_1581 + 0x30CF0);
    M2C_FIELD(var_r3_1581, s32 *, 0x30CF0) = 0;
    var_ctr_1595 = 0x23;
    do {
        shatterPool += 4;
        M2C_FIELD(shatterPool, u16 **, 4) = var_r3_1581;
        var_r3_1581 += 0x1650;
        var_ctr_1595 -= 1;
    } while (var_ctr_1595 != 0);
    shatterPool += 4;
    M2C_FIELD(shatterPool, u16 **, 4) = NULL;
}
#endif

#if 0 // DRAFT: illegal operand
void KDShatterPool::Init(KDShatter2 *arg0, MKModel *arg1, unsigned short *arg2) {
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
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
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 sp8;
    Animation *temp_r3_1689;
    Matrix *temp_r24_1688;
    Matrix *temp_r3_1973;
    f32 temp_f10_1735;
    f32 temp_f10_1835;
    f32 temp_f10_1904;
    f32 temp_f5_1732;
    f32 temp_f5_1832;
    f32 temp_f5_1901;
    f32 temp_f8_1733;
    f32 temp_f8_1833;
    f32 temp_f8_1902;
    s16 temp_r3_1681;
    s32 temp_r4_1701;
    s32 temp_r4_1801;
    s32 var_r29_1626;
    s32 var_r31_1622;
    u16 temp_r30_1635;
    u32 temp_r3_1780;
    void *temp_r3_1699;
    void *temp_r3_1721;
    void *temp_r3_1756;
    void *temp_r3_1769;
    void *temp_r3_1799;
    void *temp_r3_1821;
    void *temp_r3_1856;
    void *temp_r3_1869;
    void *temp_r3_1880;
    void *temp_r3_1890;
    void *temp_r3_1925;
    void *temp_r3_1938;
    void *temp_r4_1710;
    void *temp_r4_1730;
    void *temp_r4_1810;
    void *temp_r4_1830;
    void *temp_r4_1887;
    void *temp_r4_1899;
    void *temp_r5_1703;
    void *temp_r5_1803;
    void *temp_r6_1660;
    void *temp_r6_1666;
    void *temp_r6_1672;
    void *temp_r6_1678;

    var_r31_1622 = 0;
    var_r29_1626 = 0;
    this->unk1648 = 0.0f;
    this->unk1644 = 0;
    this->unk1640 = 0;
    this->unk164C = arg0;
loop_9:
    if ((arg2 != NULL) && (var_r29_1626 < (s32) *arg2) && ((s32) this->unk1640 < 0x20)) {
        temp_r30_1635 = *(arg2 + (var_r31_1622 + 2));
        if (MKModel_IsSubObjectPrefixed(arg1, (SubObjectType) 0, (s32) temp_r30_1635, 0x66) != 0) {
            *(this + ((this->unk1640 * 0xB0) + 0xA0)) = (s32) temp_r30_1635;
            ((Matrix *) (this + (this->unk1640 * 0xB0)))->SetIdentity();
            temp_r6_1660 = this + ((this->unk1640 * 0xB0) + 0x80);
            M2C_FIELD(temp_r6_1660, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
            M2C_FIELD(temp_r6_1660, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
            temp_r6_1666 = this + ((this->unk1640 * 0xB0) + 0x70);
            M2C_FIELD(temp_r6_1666, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
            M2C_FIELD(temp_r6_1666, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
            temp_r6_1672 = this + ((this->unk1640 * 0xB0) + 0x50);
            M2C_FIELD(temp_r6_1672, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
            M2C_FIELD(temp_r6_1672, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
            temp_r6_1678 = this + ((this->unk1640 * 0xB0) + 0x60);
            M2C_FIELD(temp_r6_1678, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
            M2C_FIELD(temp_r6_1678, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
            temp_r3_1681 = MKModel_GetSubObjectBoneIndex(arg1, (SubObjectType) 0, (s32) temp_r30_1635);
            if (temp_r3_1681 > -1) {
                temp_r24_1688 = this + (this->unk1640 * 0xB0);
                temp_r3_1689 = MKModel_GetAnimation(arg1);
                sp8 = temp_r3_1681;
                temp_r3_1689->CalculateMatrices(temp_r24_1688, 1, &sp8, NULL);
                temp_r3_1699 = MKModel_GetSubObjectOrigin(arg1, (SubObjectType) 0, (s32) temp_r30_1635);
                temp_r4_1701 = this->unk1640 * 0xB0;
                temp_r5_1703 = this + (temp_r4_1701 + 0x30);
                sp80 = M2C_FIELD(temp_r5_1703, f64 *, 0) + M2C_FIELD(temp_r3_1699, f64 *, 0);
                temp_r4_1710 = this + (temp_r4_1701 + 0x90);
                M2C_FIELD(temp_r4_1710, f64 *, 0) = sp80;
                sp88 = M2C_FIELD(temp_r5_1703, f32 *, 8) + M2C_FIELD(temp_r3_1699, f32 *, 8);
                sp100 = sp80;
                sp108 = (f64) sp88;
                M2C_FIELD(temp_r4_1710, f64 *, 8) = (f64) sp88;
                temp_r3_1721 = MKModel_GetWorldMatrix(arg1);
                temp_r4_1730 = this + ((this->unk1640 * 0xB0) + 0x90);
                temp_f5_1732 = M2C_FIELD(temp_r4_1730, f32 *, 4);
                temp_f8_1733 = M2C_FIELD(temp_r4_1730, f32 *, 0);
                temp_f10_1735 = M2C_FIELD(temp_r4_1730, f32 *, 8);
                sp30 = (temp_f10_1735 * M2C_FIELD(temp_r3_1721, f32 *, 0x20)) + ((temp_f8_1733 * M2C_FIELD(temp_r3_1721, f32 *, 0)) + (temp_f5_1732 * M2C_FIELD(temp_r3_1721, f32 *, 0x10)));
                sp34 = (temp_f10_1735 * M2C_FIELD(temp_r3_1721, f32 *, 0x24)) + ((temp_f8_1733 * M2C_FIELD(temp_r3_1721, f32 *, 4)) + (temp_f5_1732 * M2C_FIELD(temp_r3_1721, f32 *, 0x14)));
                sp38 = (temp_f10_1735 * M2C_FIELD(temp_r3_1721, f32 *, 0x28)) + ((temp_f8_1733 * M2C_FIELD(temp_r3_1721, f32 *, 8)) + (temp_f5_1732 * M2C_FIELD(temp_r3_1721, f32 *, 0x18)));
                spE0 = (f64) sp30;
                spE8 = (f64) sp38;
                temp_r3_1756 = MKModel_GetWorldMatrix(arg1) + 0x30;
                sp70 = M2C_FIELD(temp_r3_1756, f64 *, 0) + spE0;
                spF0 = sp70;
                temp_r3_1769 = this + ((this->unk1640 * 0xB0) + 0x40);
                sp78 = M2C_FIELD(temp_r3_1756, f32 *, 8) + (f32) spE8;
                M2C_FIELD(temp_r3_1769, f64 *, 0) = sp70;
                spF8 = (f64) sp78;
                M2C_FIELD(temp_r3_1769, f64 *, 8) = (f64) sp78;
            } else {
                temp_r3_1780 = MKModel_GetSubObjectLocalMatrix(arg1, (SubObjectType) 0, (s32) temp_r30_1635);
                if (temp_r3_1780 != 0) {
                    M2C_STRUCT_COPY(this + (this->unk1640 * 0xB0), temp_r3_1780, 0x40);
                    temp_r3_1799 = MKModel_GetSubObjectOrigin(arg1, (SubObjectType) 0, (s32) temp_r30_1635);
                    temp_r4_1801 = this->unk1640 * 0xB0;
                    temp_r5_1803 = this + (temp_r4_1801 + 0x30);
                    sp60 = M2C_FIELD(temp_r5_1803, f64 *, 0) + M2C_FIELD(temp_r3_1799, f64 *, 0);
                    temp_r4_1810 = this + (temp_r4_1801 + 0x90);
                    M2C_FIELD(temp_r4_1810, f64 *, 0) = sp60;
                    sp68 = M2C_FIELD(temp_r5_1803, f32 *, 8) + M2C_FIELD(temp_r3_1799, f32 *, 8);
                    spD0 = sp60;
                    spD8 = (f64) sp68;
                    M2C_FIELD(temp_r4_1810, f64 *, 8) = (f64) sp68;
                    temp_r3_1821 = MKModel_GetWorldMatrix(arg1);
                    temp_r4_1830 = this + ((this->unk1640 * 0xB0) + 0x90);
                    temp_f5_1832 = M2C_FIELD(temp_r4_1830, f32 *, 4);
                    temp_f8_1833 = M2C_FIELD(temp_r4_1830, f32 *, 0);
                    temp_f10_1835 = M2C_FIELD(temp_r4_1830, f32 *, 8);
                    sp20 = (temp_f10_1835 * M2C_FIELD(temp_r3_1821, f32 *, 0x20)) + ((temp_f8_1833 * M2C_FIELD(temp_r3_1821, f32 *, 0)) + (temp_f5_1832 * M2C_FIELD(temp_r3_1821, f32 *, 0x10)));
                    sp24 = (temp_f10_1835 * M2C_FIELD(temp_r3_1821, f32 *, 0x24)) + ((temp_f8_1833 * M2C_FIELD(temp_r3_1821, f32 *, 4)) + (temp_f5_1832 * M2C_FIELD(temp_r3_1821, f32 *, 0x14)));
                    sp28 = (temp_f10_1835 * M2C_FIELD(temp_r3_1821, f32 *, 0x28)) + ((temp_f8_1833 * M2C_FIELD(temp_r3_1821, f32 *, 8)) + (temp_f5_1832 * M2C_FIELD(temp_r3_1821, f32 *, 0x18)));
                    spB0 = (f64) sp20;
                    spB8 = (f64) sp28;
                    temp_r3_1856 = MKModel_GetWorldMatrix(arg1) + 0x30;
                    sp50 = M2C_FIELD(temp_r3_1856, f64 *, 0) + spB0;
                    spC0 = sp50;
                    temp_r3_1869 = this + ((this->unk1640 * 0xB0) + 0x40);
                    sp58 = M2C_FIELD(temp_r3_1856, f32 *, 8) + (f32) spB8;
                    M2C_FIELD(temp_r3_1869, f64 *, 0) = sp50;
                    spC8 = (f64) sp58;
                    M2C_FIELD(temp_r3_1869, f64 *, 8) = (f64) sp58;
                } else {
                    temp_r3_1880 = MKModel_GetSubObjectOrigin(arg1, (SubObjectType) 0, (s32) temp_r30_1635);
                    temp_r4_1887 = this + ((this->unk1640 * 0xB0) + 0x90);
                    M2C_FIELD(temp_r4_1887, f64 *, 0) = (f64) M2C_FIELD(temp_r3_1880, f64 *, 0);
                    M2C_FIELD(temp_r4_1887, f64 *, 8) = (f64) M2C_FIELD(temp_r3_1880, f64 *, 8);
                    temp_r3_1890 = MKModel_GetWorldMatrix(arg1);
                    temp_r4_1899 = this + ((this->unk1640 * 0xB0) + 0x90);
                    temp_f5_1901 = M2C_FIELD(temp_r4_1899, f32 *, 4);
                    temp_f8_1902 = M2C_FIELD(temp_r4_1899, f32 *, 0);
                    temp_f10_1904 = M2C_FIELD(temp_r4_1899, f32 *, 8);
                    sp10 = (temp_f10_1904 * M2C_FIELD(temp_r3_1890, f32 *, 0x20)) + ((temp_f8_1902 * M2C_FIELD(temp_r3_1890, f32 *, 0)) + (temp_f5_1901 * M2C_FIELD(temp_r3_1890, f32 *, 0x10)));
                    sp14 = (temp_f10_1904 * M2C_FIELD(temp_r3_1890, f32 *, 0x24)) + ((temp_f8_1902 * M2C_FIELD(temp_r3_1890, f32 *, 4)) + (temp_f5_1901 * M2C_FIELD(temp_r3_1890, f32 *, 0x14)));
                    sp18 = (temp_f10_1904 * M2C_FIELD(temp_r3_1890, f32 *, 0x28)) + ((temp_f8_1902 * M2C_FIELD(temp_r3_1890, f32 *, 8)) + (temp_f5_1901 * M2C_FIELD(temp_r3_1890, f32 *, 0x18)));
                    sp90 = (f64) sp10;
                    sp98 = (f64) sp18;
                    temp_r3_1925 = MKModel_GetWorldMatrix(arg1) + 0x30;
                    sp40 = M2C_FIELD(temp_r3_1925, f64 *, 0) + sp90;
                    spA0 = sp40;
                    temp_r3_1938 = this + ((this->unk1640 * 0xB0) + 0x40);
                    sp48 = M2C_FIELD(temp_r3_1925, f32 *, 8) + (f32) sp98;
                    M2C_FIELD(temp_r3_1938, f64 *, 0) = sp40;
                    spA8 = (f64) sp48;
                    M2C_FIELD(temp_r3_1938, f64 *, 8) = (f64) sp48;
                }
            }
            this->unk1640 += 1;
        }
        var_r29_1626 += 1;
        var_r31_1622 += 2;
        goto loop_9;
    }
    M2C_STRUCT_COPY((s32) &this->unk15FC + 4, MKModel_GetWorldMatrix(arg1) - 4 + 4, 0x40);
    temp_r3_1973 = &this->unk1600;
    temp_r3_1973->Inverse(temp_r3_1973);
}
#endif

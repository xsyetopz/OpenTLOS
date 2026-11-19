#include "spyro/source/LineSegmentTrail.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal implicit conversion from 'LineSegmentTrail' to
s32 LineSegmentTrail::TrailActive() {
    s32 var_ctr_43;
    s32 var_r4_42;
    void *temp_r5_46;

    var_r4_42 = 0;
    var_ctr_43 = 6;
loop_1:
    temp_r5_46 = *(this + (var_r4_42 + 0x58));
    if ((temp_r5_46 != NULL) && ((u8) M2C_FIELD(temp_r5_46, u8 *, 0x1C) == 0)) {
        return 1;
    }
    var_r4_42 += 4;
    var_ctr_43 -= 1;
    if (var_ctr_43 == 0) {
        return 0;
    }
    goto loop_1;
}
#endif

void LineSegmentTrailPool::Free(LSTrail *arg0) {
    if (this != NULL) {
        this->unk24 = 0;
    }
}

#if 0 // DRAFT: pointer/array required
LineSegmentTrailPool *LineSegmentTrailPool::Alloc() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 var_ctr_81;
    s32 var_r31_79;
    void *temp_r3_105;

    var_r31_79 = 0;
    var_ctr_81 = 0xA;
loop_1:
    if ((u8) *(*LineSegmentTrailPool::pTrailPool + (var_r31_79 + 0x24)) == 0) {
        memset(*(*LineSegmentTrailPool::pTrailPool + var_r31_79), 0, 0x3C0U);
        M2C_FIELD((*LineSegmentTrailPool::pTrailPool + var_r31_79), s32 *, 0x18) = 0;
        sp8 = 1.0f;
        M2C_FIELD((*LineSegmentTrailPool::pTrailPool + var_r31_79), s8 *, 0x1C) = 0;
        spC = 1.0f;
        temp_r3_105 = *LineSegmentTrailPool::pTrailPool + (var_r31_79 + 8);
        sp10 = 1.0f;
        sp14 = 1.0f;
        M2C_FIELD(temp_r3_105, f64 *, 0) = (f64) sp8;
        M2C_FIELD(temp_r3_105, f64 *, 8) = (f64) sp10;
        sp18 = (f64) sp8;
        M2C_FIELD((*LineSegmentTrailPool::pTrailPool + var_r31_79), s8 *, 0x24) = 1;
        sp20 = (f64) sp10;
        M2C_FIELD((*LineSegmentTrailPool::pTrailPool + var_r31_79), s32 *, 0x20) = 0;
        return *LineSegmentTrailPool::pTrailPool + var_r31_79;
    }
    var_r31_79 += 0x30;
    var_ctr_81 -= 1;
    if (var_ctr_81 == 0) {
        return NULL;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: pointer/array required
void LineSegmentTrailPool::Deinit() {
    MKHeap *temp_r30_160;
    MKHeap *temp_r30_178;
    MKHeap *temp_r3_161;
    MKHeap *temp_r3_179;
    s32 temp_r0_142;
    s32 var_ctr_148;
    s32 var_r29_156;
    s32 var_r31_157;
    s32 var_r3_147;

    temp_r0_142 = *LineSegmentTrailPool::refCount - 1;
    *LineSegmentTrailPool::refCount = temp_r0_142;
    if (temp_r0_142 <= 0) {
        var_r3_147 = 0;
        var_ctr_148 = 0xA;
loop_2:
        if ((u8) *(*LineSegmentTrailPool::pTrailPool + (var_r3_147 + 0x24)) == 0) {
            var_r3_147 += 0x30;
            var_ctr_148 -= 1;
            if (var_ctr_148 == 0) {
                var_r29_156 = 0;
                var_r31_157 = 0;
                do {
                    temp_r30_160 = *(*LineSegmentTrailPool::pTrailPool + var_r31_157);
                    temp_r3_161 = ((MKHeap *) (*LineSegmentTrailPool::pTrailPool))->Current();
                    if (temp_r3_161 != NULL) {
                        ((MKHeap *) (temp_r3_161->Current()))->Free(temp_r30_160, NULL, 0);
                    } else {
                        free(temp_r30_160);
                    }
                    var_r29_156 += 1;
                    var_r31_157 += 0x30;
                } while (var_r29_156 < 0xA);
                temp_r30_178 = *LineSegmentTrailPool::pTrailPool;
                temp_r3_179 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
                if (temp_r3_179 != NULL) {
                    ((MKHeap *) (temp_r3_179->Current()))->Free(temp_r30_178, NULL, 0);
                } else {
                    free(temp_r30_178);
                }
                *LineSegmentTrailPool::pTrailPool = NULL;
            } else {
                goto loop_2;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void LineSegmentTrailPool::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_216;
    MKHeap *temp_r3_234;
    MKHeap *var_r3_223;
    MKHeap *var_r3_241;
    s32 temp_cr0_gt_213;
    s32 temp_r0_263;
    s32 temp_r3_211;
    s32 temp_r3_261;
    s32 temp_r4_260;
    s32 temp_r5_259;
    s32 var_r30_232;
    s32 var_r31_230;
    void *temp_r3_274;

    temp_r3_211 = *LineSegmentTrailPool::refCount;
    temp_cr0_gt_213 = temp_r3_211 > 0;
    *LineSegmentTrailPool::refCount = temp_r3_211 + 1;
    if (temp_cr0_gt_213 == 0) {
        temp_r3_216 = ((MKHeap *) temp_r3_211)->Current();
        if (temp_r3_216 != NULL) {
            var_r3_223 = ((MKHeap *) (temp_r3_216->Current()))->Alloc(0x1E0, NULL, 0);
        } else {
            var_r3_223 = malloc(0x1E0);
        }
        *LineSegmentTrailPool::pTrailPool = var_r3_223;
        var_r31_230 = 0;
        var_r30_232 = 0;
        do {
            temp_r3_234 = var_r3_223->Current();
            if (temp_r3_234 != NULL) {
                var_r3_241 = ((MKHeap *) (temp_r3_234->Current()))->Alloc(0x3C0, NULL, 0);
            } else {
                var_r3_241 = malloc(0x3C0);
            }
            *(*LineSegmentTrailPool::pTrailPool + var_r30_232) = var_r3_241;
            memset(*(*LineSegmentTrailPool::pTrailPool + var_r30_232), 0, 0x3C0U);
            var_r31_230 += 1;
            *(*LineSegmentTrailPool::pTrailPool + (var_r30_232 + 0x18)) = 0;
            temp_r5_259 = var_r30_232 + 0x24;
            temp_r4_260 = var_r30_232 + 0x1C;
            temp_r3_261 = var_r30_232 + 8;
            temp_r0_263 = var_r30_232 + 0x20;
            sp8 = 1.0f;
            var_r30_232 += 0x30;
            *(*LineSegmentTrailPool::pTrailPool + temp_r5_259) = 0;
            spC = 1.0f;
            *(*LineSegmentTrailPool::pTrailPool + temp_r4_260) = 0;
            sp10 = 1.0f;
            temp_r3_274 = *LineSegmentTrailPool::pTrailPool + temp_r3_261;
            sp14 = 1.0f;
            M2C_FIELD(temp_r3_274, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r3_274, f64 *, 8) = (f64) sp10;
            var_r3_223 = *LineSegmentTrailPool::pTrailPool;
            sp18 = (f64) sp8;
            sp20 = (f64) sp10;
            *(var_r3_223 + temp_r0_263) = 0;
        } while (var_r31_230 < 0xA);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'LineSegmentTrail' to
void LineSegmentTrail::EndTrail() {
    s32 var_ctr_300;
    s32 var_r4_298;
    void *temp_r6_303;

    var_r4_298 = 0;
    var_ctr_300 = 6;
    do {
        temp_r6_303 = *(this + (var_r4_298 + 0x58));
        if ((temp_r6_303 != NULL) && ((u8) M2C_FIELD(temp_r6_303, u8 *, 0x24) != 0) && ((u8) M2C_FIELD(temp_r6_303, u8 *, 0x1C) == 0)) {
            M2C_FIELD(temp_r6_303, u8 *, 0x1C) = 1U;
        }
        var_r4_298 += 4;
        var_ctr_300 -= 1;
    } while (var_ctr_300 != 0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'LineSegmentTrail' to
void LineSegmentTrail::BeginTrail(const MKVector4 &arg0) {
    LSTrail *temp_r4_342;
    LineSegmentTrail *temp_r27_326;
    LineSegmentTrail *var_r3_0;
    s32 temp_r30_331;
    s32 var_r29_328;
    s32 var_r31_329;
    void *temp_r5_340;

    var_r3_0 = this;
    temp_r27_326 = var_r3_0;
    var_r29_328 = 0;
    var_r31_329 = 0;
loop_1:
    temp_r30_331 = var_r31_329 + 0x58;
    if ((u32) *(temp_r27_326 + temp_r30_331) == 0U) {
        var_r3_0 = ((LineSegmentTrailPool *) var_r3_0)->Alloc();
        *(temp_r27_326 + temp_r30_331) = var_r3_0;
        if ((u32) *(temp_r27_326 + temp_r30_331) != 0U) {
            temp_r5_340 = temp_r27_326 + var_r31_329;
            temp_r4_342 = M2C_FIELD(temp_r5_340, LSTrail **, 0x58);
            temp_r4_342->unk8 = M2C_FIELD(&arg0, f64 *, 0);
            temp_r4_342->unk10 = M2C_FIELD(&arg0, f64 *, 8);
            temp_r27_326->UpdateTrail(M2C_FIELD(temp_r5_340, LSTrail **, 0x58));
            return;
        }
    }
    var_r29_328 += 1;
    var_r31_329 += 4;
    if (var_r29_328 >= 6) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void LineSegmentTrail::UpdateTrail(LSTrail *arg0) {
    MKVector4 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r5_402;
    f64 temp_f0_466;
    s32 var_ctr_379;
    s32 var_r3_375;
    void *temp_r5_382;
    void *temp_r5_391;

    if (arg0 != NULL) {
        var_r3_375 = 0;
        var_ctr_379 = 0x14;
        do {
            temp_r5_382 = arg0->unk0 + var_r3_375;
            if ((u8) M2C_FIELD(temp_r5_382, u8 *, 0x24) != 0) {
                M2C_FIELD(temp_r5_382, f32 *, 0x20) = (f32) (M2C_FIELD(temp_r5_382, f32 *, 0x20) + gUpdateTimeDelta);
                temp_r5_391 = arg0->unk0 + var_r3_375;
                if (M2C_FIELD(temp_r5_391, f32 *, 0x20) > 0.3f) {
                    M2C_FIELD(temp_r5_391, s8 *, 0x24) = 0;
                }
            }
            var_r3_375 += 0x30;
            var_ctr_379 -= 1;
        } while (var_ctr_379 != 0);
        temp_r5_402 = arg0->unk0 + (arg0->unk18 * 0x30);
        if ((u8) M2C_FIELD(temp_r5_402, u8 *, 0x24) == 0) {
            MKModel_CalculateRefPointWorldPosition(this->unk4C->unk8, this->unk50, temp_r5_402);
            MKModel_CalculateRefPointWorldPosition(this->unk4C->unk8, this->unk54, arg0->unk0 + ((arg0->unk18 * 0x30) + 0x10));
            M2C_FIELD((arg0->unk0 + (arg0->unk18 * 0x30)), s8 *, 0x24) = 1;
            M2C_FIELD((arg0->unk0 + (arg0->unk18 * 0x30)), f32 *, 0x20) = 0.0f;
            arg0->unk18 += 1;
            if ((s32) arg0->unk18 >= 0x14) {
                arg0->unk18 = 0;
            }
            if ((u8) arg0->unk1C != 0) {
                sp38 = gUpdateTimeDelta;
                sp3C = gUpdateTimeDelta;
                sp48 = 0.0f;
                sp4C = 0.0f;
                sp50 = 0.0f;
                sp54 = 0.0f;
                sp40 = gUpdateTimeDelta;
                sp44 = gUpdateTimeDelta;
                sp68 = (f64) sp38;
                sp98 = (f64) sp48;
                spA0 = (f64) sp50;
                sp70 = (f64) sp40;
                sp28 = sp68 * 5.325712093e-315;
                temp_f0_466 = (f64) sp40 * 5.325712093e-315;
                sp30 = temp_f0_466;
                sp78 = sp28;
                sp80 = temp_f0_466;
                sp18 = arg0->unk8 - sp78;
                sp20 = arg0->unk10 - temp_f0_466;
                sp8 = 1.0f;
                spC = 1.0f;
                sp10 = 1.0f;
                sp14 = 1.0f;
                sp88 = sp18;
                sp90 = sp20;
                sp58 = (f64) sp8;
                sp60 = (f64) sp10;
                Clamp<MKVector4>(spA8, *((MKVector4 *) &sp98), *((MKVector4 *) &sp88));
                arg0->unk8 = M2C_BITWISE(f64, spA8);
                arg0->unk10 = (f64) spA8.unk8;
                if (M2C_FIELD(arg0, f32 *, 0x14) <= 0.01f) {
                    FreeActiveTrail(arg0);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'LineSegmentTrail' to
void LineSegmentTrail::FreeActiveTrail(LSTrail *arg0) {
    s32 temp_r3_623;
    s32 var_r29_620;
    s32 var_r31_617;

    var_r31_617 = 0;
    var_r29_620 = 0;
    do {
        temp_r3_623 = var_r31_617 + 0x58;
        if ((u32) *(this + temp_r3_623) == arg0) {
            *(this + temp_r3_623) = 0;
            ((LineSegmentTrailPool *) arg0)->Free(M2C_ERROR(/* Read from unset register $r4 */));
        }
        var_r29_620 += 1;
        var_r31_617 += 4;
    } while (var_r29_620 < 6);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'LineSegmentTrail' to
void LineSegmentTrail::Deinit() {
    LSTrail *temp_r4_662;
    MKMaterial *temp_r3_650;
    s32 temp_r29_661;
    s32 var_r28_658;
    s32 var_r31_657;

    temp_r3_650 = this->unk70;
    if (temp_r3_650 != NULL) {
        MKMaterial_Destroy(temp_r3_650);
        this->unk70 = NULL;
    }
    var_r31_657 = 0;
    var_r28_658 = 0;
    do {
        temp_r29_661 = var_r31_657 + 0x58;
        temp_r4_662 = *(this + temp_r29_661);
        if (temp_r4_662 != NULL) {
            FreeActiveTrail(temp_r4_662);
            *(this + temp_r29_661) = 0;
        }
        var_r28_658 += 1;
        var_r31_657 += 4;
    } while (var_r28_658 < 6);
    this->unk74.Deinit();
    this->unk88.Deinit();
    ((LineSegmentTrailPool *) (M2C_ERROR(/* Read from unset register $r3 */)))->Deinit();
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'LineSegmentTrail' to
void LineSegmentTrail::Draw() {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    M2C_UNK sp8;
    MKVector3 *temp_r4_748;
    f32 var_f27_805;
    f32 var_f28_789;
    f32 var_f2_806;
    s32 temp_r0_756;
    s32 temp_r26_759;
    s32 temp_r27_746;
    s32 temp_r28_716;
    s32 var_r26_728;
    s32 var_r27_778;
    s32 var_r29_714;
    s32 var_r31_713;
    void *temp_r3_745;
    void *temp_r4_760;

    MKMaterial_SetMaterial(this->unk70);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r31_713 = 0;
    var_r29_714 = 0;
    do {
        temp_r28_716 = var_r29_714 + 0x58;
        if ((u32) *(this + temp_r28_716) != 0U) {
            this->unk74.unk8 = 0.0f;
            this->unk74.unk4 = 0;
            this->unk88.unk8 = 0.0f;
            this->unk88.unk4 = 0;
            var_r26_728 = M2C_FIELD(*(this + temp_r28_716), s32 *, 0x18) - 1;
            if (var_r26_728 < 0) {
                var_r26_728 = 0x13;
            }
loop_6:
            temp_r3_745 = *(this + temp_r28_716);
            temp_r27_746 = var_r26_728 * 0x30;
            temp_r4_748 = M2C_FIELD(temp_r3_745, s32 *, 0) + temp_r27_746;
            if (((u8) M2C_FIELD(temp_r4_748, u8 *, 0x24) != 0) && (var_r26_728 != (s32) M2C_FIELD(temp_r3_745, s32 *, 0x18))) {
                this->unk74.AddNode(*temp_r4_748);
                this->unk88.AddNode(*(**(this + temp_r28_716) + (temp_r27_746 + 0x10)));
                var_r26_728 -= 1;
                if (var_r26_728 < 0) {
                    var_r26_728 = 0x13;
                }
                goto loop_6;
            }
            temp_r0_756 = this->unk74.unk4;
            if (temp_r0_756 > 1) {
                temp_r26_759 = temp_r0_756 * 3;
                temp_r4_760 = *(this + temp_r28_716);
                sp28 = M2C_FIELD(temp_r4_760, f64 *, 8);
                sp30 = M2C_FIELD(temp_r4_760, f64 *, 0x10);
                MKBegin(temp_r0_756 * 6);
                var_r27_778 = 0;
loop_28:
                if (var_r27_778 < temp_r26_759) {
                    var_f28_789 = (f32) var_r27_778 * (1.0f / (f32) (temp_r26_759 - 1));
                    if (var_f28_789 < 1.0f) {

                    } else {
                        var_f28_789 = 1.0f;
                    }
                    if (var_f28_789 > 0.0f) {

                    } else {
                        var_f28_789 = 0.0f;
                    }
                    MKSetColorV(*((MKVector4 *) &sp28));
                    var_f27_805 = 1.0f - var_f28_789;
                    var_f2_806 = 1.0f;
                    if (var_f27_805 < var_f2_806) {
                        var_f2_806 = var_f27_805;
                    }
                    if (var_f2_806 > 0.05f) {

                    } else {
                        var_f2_806 = 0.05f;
                    }
                    MKSetTexCoord1F(0.0f, var_f2_806);
                    ((KDSpline *) &sp18)->GetMeasure(var_f28_789, (Matrix *) &this->unk88);
                    MKSetPositionV(*((MKVector3 *) &sp18));
                    MKSetColorV(*((MKVector4 *) &sp28));
                    if (var_f27_805 < 1.0f) {

                    } else {
                        var_f27_805 = 1.0f;
                    }
                    if (var_f27_805 > 0.05f) {

                    } else {
                        var_f27_805 = 0.05f;
                    }
                    MKSetTexCoord1F(1.0f, var_f27_805);
                    ((KDSpline *) &sp8)->GetMeasure(var_f28_789, (Matrix *) &this->unk74);
                    MKSetPositionV(*((MKVector3 *) &sp8));
                    var_r27_778 += 1;
                    goto loop_28;
                }
                MKEnd();
            }
        }
        var_r31_713 += 1;
        var_r29_714 += 4;
    } while (var_r31_713 < 6);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'LineSegmentTrail' to
void LineSegmentTrail::Update() {
    LSTrail *temp_r4_893;
    s32 var_r30_889;
    s32 var_r31_890;

    var_r30_889 = 0;
    var_r31_890 = 0;
    do {
        temp_r4_893 = *(this + (var_r31_890 + 0x58));
        if (temp_r4_893 != NULL) {
            UpdateTrail(temp_r4_893);
        }
        var_r30_889 += 1;
        var_r31_890 += 4;
    } while (var_r30_889 < 6);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
void LineSegmentTrail::SetUserData(MKAnimScript *arg0, const int &arg1, const int &arg2, char *arg3) {
    this->unk4C = arg0;
    this->unk50 = &arg1;
    this->unk54 = &arg2;
    this->unk70 = MKMaterial_Create(arg3);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'LineSegmentTrailPool *' to
void LineSegmentTrail::Init() {
    LineSegmentTrailPool *var_r3_956;
    s32 temp_r0_961;
    s32 var_ctr_959;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = -1;
    this->unk54 = -1;
    this->unk70 = NULL;
    this->unk74.Init(0x14, 0U);
    this->unk88.Init(0x14, 0U);
    var_r3_956 = NULL;
    var_ctr_959 = 6;
    do {
        temp_r0_961 = var_r3_956 + 0x58;
        var_r3_956 += 4;
        *(this + temp_r0_961) = 0;
        var_ctr_959 -= 1;
    } while (var_ctr_959 != 0);
    var_r3_956->Init();
}
#endif

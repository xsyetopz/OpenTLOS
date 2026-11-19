#include "spyro/source/BoundingRegion.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDPath.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void BoundingRegion::GetPos(int arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f10_31;
    f32 temp_f5_28;
    f32 temp_f9_29;
    u32 temp_r4_68;
    void *temp_r4_26;
    void *temp_r4_61;
    void *temp_r4_72;
    void *temp_r6_12;
    void *temp_r7_15;

    temp_r6_12 = M2C_FIELD(arg0, void **, 0);
    if (temp_r6_12 != NULL) {
        temp_r7_15 = M2C_FIELD(temp_r6_12, void **, 0x30);
        if (temp_r7_15 != NULL) {
            temp_r4_26 = M2C_FIELD(temp_r6_12, s32 *, 0x24) + (M2C_ERROR(/* Read from unset register $r5 */) * M2C_FIELD(temp_r6_12, s32 *, 0x1C));
            temp_f5_28 = M2C_FIELD(temp_r4_26, f32 *, 4);
            temp_f9_29 = M2C_FIELD(temp_r4_26, f32 *, 0);
            temp_f10_31 = M2C_FIELD(temp_r4_26, f32 *, 8);
            sp8 = M2C_FIELD(temp_r7_15, f32 *, 0x30) + ((temp_f10_31 * M2C_FIELD(temp_r7_15, f32 *, 0x20)) + ((temp_f9_29 * M2C_FIELD(temp_r7_15, f32 *, 0)) + (temp_f5_28 * M2C_FIELD(temp_r7_15, f32 *, 0x10))));
            spC = M2C_FIELD(temp_r7_15, f32 *, 0x34) + ((temp_f10_31 * M2C_FIELD(temp_r7_15, f32 *, 0x24)) + ((temp_f9_29 * M2C_FIELD(temp_r7_15, f32 *, 4)) + (temp_f5_28 * M2C_FIELD(temp_r7_15, f32 *, 0x14))));
            sp10 = M2C_FIELD(temp_r7_15, f32 *, 0x38) + ((temp_f10_31 * M2C_FIELD(temp_r7_15, f32 *, 0x28)) + ((temp_f9_29 * M2C_FIELD(temp_r7_15, f32 *, 8)) + (temp_f5_28 * M2C_FIELD(temp_r7_15, f32 *, 0x18))));
            this->unk0 = (f64) sp8;
            this->unk8 = (f64) sp10;
            return;
        }
        temp_r4_61 = M2C_FIELD(temp_r6_12, s32 *, 0x24) + (M2C_ERROR(/* Read from unset register $r5 */) * M2C_FIELD(temp_r6_12, s32 *, 0x1C));
        this->unk0 = M2C_FIELD(temp_r4_61, f64 *, 0);
        this->unk8 = M2C_FIELD(temp_r4_61, f64 *, 8);
        return;
    }
    temp_r4_68 = M2C_FIELD(arg0, u32 *, 4);
    if (temp_r4_68 != 0U) {
        temp_r4_72 = temp_r4_68 + (M2C_ERROR(/* Read from unset register $r5 */) * 0x10);
        this->unk0 = M2C_FIELD(temp_r4_72, f64 *, 0);
        this->unk8 = M2C_FIELD(temp_r4_72, f64 *, 8);
        return;
    }
    this->unk0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'BoundingRegion' to
u32 BoundingRegion::GetIntersectCount(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    BoundingRegion sp38;
    f64 sp28;
    f64 sp18;
    f64 sp8;
    s32 var_r30_105;
    u32 var_r31_101;

    var_r31_101 = 0;
    sp38.GetPos((s32) this);
    var_r30_105 = 0;
    sp68 = M2C_BITWISE(f64, sp38);
    sp70 = sp38.unk8;
loop_4:
    if (var_r30_105 < (s32) (M2C_FIELD(this, s32 *, 8) - 1)) {
        ((BoundingRegion *) &sp28)->GetPos((s32) this);
        sp58 = sp28;
        sp60 = sp30;
        if (MKLinesIntersect(arg0, arg1, *((MKVector3 *) &sp68), *((MKVector3 *) &sp58)) != 0) {
            var_r31_101 += 1;
        }
        var_r30_105 += 1;
        sp68 = sp58;
        sp70 = sp60;
        goto loop_4;
    }
    ((BoundingRegion *) &sp18)->GetPos((s32) this);
    sp68 = sp18;
    sp70 = sp20;
    ((BoundingRegion *) &sp8)->GetPos((s32) this);
    sp38.unk10 = sp8;
    sp38.unk18 = sp10;
    if (MKLinesIntersect(arg0, arg1, *((MKVector3 *) &sp68), *((MKVector3 *) &sp38.unk10)) != 0) {
        var_r31_101 += 1;
    }
    return var_r31_101;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to
u8 BoundingRegion::IsPointInBoundaryRect(const MKVector3 &arg0) {
    Matrix sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Matrix *temp_r4_189;
    f32 temp_f3_194;
    f32 temp_f6_200;
    f32 temp_f7_206;
    u8 var_r3_232;
    void *temp_r3_185;

    sp30 = M2C_FIELD(&arg0, f64 *, 0);
    temp_r3_185 = M2C_FIELD(this, void **, 0);
    sp38 = M2C_FIELD(&arg0, f64 *, 8);
    if (temp_r3_185 != NULL) {
        temp_r4_189 = M2C_FIELD(temp_r3_185, Matrix **, 0x30);
        if (temp_r4_189 != NULL) {
            sp40.Inverse(temp_r4_189);
            temp_f3_194 = arg0.unk4;
            temp_f6_200 = arg0.unk0;
            temp_f7_206 = arg0.unk8;
            sp10 = sp40.unk30 + ((temp_f7_206 * sp40.unk20) + ((temp_f6_200 * M2C_BITWISE(f32, sp40)) + (temp_f3_194 * sp40.unk10)));
            sp14 = sp40.unk34 + ((temp_f7_206 * sp40.unk24) + ((temp_f6_200 * sp40.unk4) + (temp_f3_194 * sp40.unk14)));
            sp18 = sp40.unk38 + ((temp_f7_206 * sp40.unk28) + ((temp_f6_200 * sp40.unk8) + (temp_f3_194 * sp40.unk18)));
            sp20 = (f64) sp10;
            sp28 = (f64) sp18;
            sp30 = (f64) sp10;
            sp38 = (f64) sp18;
        }
    }
    var_r3_232 = 0;
    if (((f32) sp30 > M2C_FIELD(this, f32 *, 0xC)) && ((f32) sp30 < this->unk10) && ((f32) sp38 > this->unk14) && ((f32) sp38 < this->unk18)) {
        var_r3_232 = 1;
    }
    return var_r3_232;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_max'
s32 BoundingRegion::IsPointWithin(const MKVector3 &arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    u32 temp_r3_285;
    u32 temp_r4_286;

    if (IsPointInBoundaryRect(arg0) == 0) {
        return 0;
    }
    sp8 = __float_max;
    sp10 = arg0.unk8;
    spC = 0.0f;
    sp20 = (f64) sp10;
    sp18 = (f64) sp8;
    temp_r3_285 = GetIntersectCount(arg0, *((MKVector3 *) &sp18));
    temp_r4_286 = temp_r3_285 >> 0x1FU;
    return (((temp_r3_285 & 1) ^ temp_r4_286) - temp_r4_286) == 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_max'
void BoundingRegion::InitBoundaryRect() {
    Matrix sp50;
    BoundingRegion sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Matrix *temp_r4_334;
    s32 var_r31_314;
    void *temp_r3_327;

    var_r31_314 = 0;
    this->unk14 = __float_max;
    M2C_FIELD(this, f32 *, 0xC) = (f32) __float_max;
    this->unk18 = __float_min;
    this->unk10 = __float_min;
loop_13:
    if (var_r31_314 < (s32) M2C_FIELD(this, s32 *, 8)) {
        sp30.GetPos((s32) this);
        temp_r3_327 = M2C_FIELD(this, void **, 0);
        sp30.unk10 = M2C_BITWISE(f64, sp30);
        sp30.unk18 = sp30.unk8;
        if (temp_r3_327 != NULL) {
            temp_r4_334 = M2C_FIELD(temp_r3_327, Matrix **, 0x30);
            if (temp_r4_334 != NULL) {
                sp50.Inverse(temp_r4_334);
                sp10 = sp50.unk30 + ((sp30.unk18 * sp50.unk20) + ((sp30.unk10 * M2C_BITWISE(f32, sp50)) + (sp30.unk14 * sp50.unk10)));
                sp14 = sp50.unk34 + ((sp30.unk18 * sp50.unk24) + ((sp30.unk10 * sp50.unk4) + (sp30.unk14 * sp50.unk14)));
                sp18 = sp50.unk38 + ((sp30.unk18 * sp50.unk28) + ((sp30.unk10 * sp50.unk8) + (sp30.unk14 * sp50.unk18)));
                sp20 = (f64) sp10;
                sp28 = (f64) sp18;
                sp30.unk10 = (f64) sp10;
                sp30.unk18 = (f64) sp18;
            }
        }
        if ((f32) sp30.unk10 < M2C_FIELD(this, f32 *, 0xC)) {
            M2C_FIELD(this, f32 *, 0xC) = (f32) sp30.unk10;
        }
        if ((f32) sp30.unk10 > this->unk10) {
            this->unk10 = (f32) sp30.unk10;
        }
        if ((f32) sp30.unk18 < this->unk14) {
            this->unk14 = (f32) sp30.unk18;
        }
        if ((f32) sp30.unk18 > this->unk18) {
            this->unk18 = (f32) sp30.unk18;
        }
        var_r31_314 += 1;
        goto loop_13;
    }
}
#endif

void BoundingRegion::Init(MKVector3 *arg0, int arg1) {
    M2C_FIELD(this, s32 *, 0) = 0;
    M2C_FIELD(this, MKVector3 **, 4) = arg0;
    M2C_FIELD(this, s32 *, 8) = arg1;
    InitBoundaryRect();
}

#if 0 // DRAFT: undefined identifier 'unk20'
void BoundingRegion::Init(KDLocalPathSegment *arg0) {
    M2C_FIELD(this, KDLocalPathSegment **, 0) = arg0;
    M2C_FIELD(this, s32 *, 4) = 0;
    M2C_FIELD(this, s32 *, 8) = (s32) M2C_FIELD(this, KDLocalPathSegment **, 0)->unk20;
    InitBoundaryRect();
}
#endif

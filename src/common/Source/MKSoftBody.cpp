#include "common/Source/MKSoftBody.h"
#include "common/Source/Animation.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/gc/MKMaterial_GC.h"
#include "unplaced_enums.h"
#include "common/Source/MKShape.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(s8 *);                                 /* extern */
MKModel **malloc(s32);                              /* extern */
extern s32 MKSoftBody_enableBoundBox;
extern s32 MKSoftBody_showCollision;
extern s32 MKSoftBody_showConstraints;
extern M2C_UNK gEmptyPtrList;
extern s32 gFrameCounter;
extern MKHeap gMKDefaults;
extern M2C_UNK gRenderState;
extern f32 gUpdateTimeDelta;
#if 0 // DRAFT: identifier 'MKSoftBody_enableCloth' redeclared
static s32 MKSoftBody_enableCloth = 1;
#endif
static f32 clothFaceEffect = 0.5f;

#if 0 // DRAFT: undefined identifier '__float_nan'
f32 SoftSweepSphere::UpdatePos(const MKVector3 &arg0) {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_121;
    f32 temp_f2_126;
    f32 temp_f2_49;
    f32 temp_f3_48;
    f32 temp_f5_51;
    f32 var_f5_56;
    f64 temp_f2_59;
    f64 temp_f2_65;
    f64 temp_f2_69;
    s32 temp_r4_88;
    s32 var_r0_98;

    this->unk0 = this->unk10;
    this->unk8 = this->unk18;
    this->unk10 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk18 = M2C_FIELD(&arg0, f64 *, 8);
    sp10 = this->unk10 - this->unk0;
    this->unk20 = sp10;
    sp18 = (f32) M2C_FIELD(this, f64 *, 0x18) - (f32) M2C_FIELD(this, f64 *, 8);
    sp20 = sp10;
    this->unk28 = (f64) sp18;
    temp_f3_48 = (f32) M2C_FIELD(this, f64 *, 0x20);
    temp_f2_49 = M2C_FIELD(this, f32 *, 0x24);
    temp_f5_51 = (f32) M2C_FIELD(this, f64 *, 0x28);
    sp28 = (f64) sp18;
    var_f5_56 = (temp_f5_51 * temp_f5_51) + ((temp_f3_48 * temp_f3_48) + (temp_f2_49 * temp_f2_49));
    if (var_f5_56 > 0.0f) {
        temp_f2_59 = __frsqrte(var_f5_56);
        temp_f2_65 = 0.5 * temp_f2_59 * -(((f64) var_f5_56 * (temp_f2_59 * temp_f2_59)) - 3.0);
        temp_f2_69 = 0.5 * temp_f2_65 * -(((f64) var_f5_56 * (temp_f2_65 * temp_f2_65)) - 3.0);
        var_f5_56 = (f32) ((f64) var_f5_56 * (0.5 * temp_f2_69 * -(((f64) var_f5_56 * (temp_f2_69 * temp_f2_69)) - 3.0)));
    } else if (var_f5_56 < M2C_BITWISE(f32, 0.0)) {
        var_f5_56 = __float_nan;
    } else {
        sp8 = var_f5_56;
        temp_r4_88 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r4_88) {                       /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_98 = 1;
            } else {
                var_r0_98 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_98 = 5;
            } else {
                var_r0_98 = 3;
            }
            break;
        default:
            var_r0_98 = 4;
            break;
        }
        if (var_r0_98 == 1) {
            var_f5_56 = __float_nan;
        }
    }
    this->unk34 = var_f5_56;
    temp_f2_121 = this->unk34;
    if (temp_f2_121 != 0.0f) {
        temp_f2_126 = 1.0f / temp_f2_121;
        this->unk20 *= (f64) temp_f2_126;
        M2C_FIELD(this, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x28) * temp_f2_126);
    }
    return M2C_BITWISE(f32, this);
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp144'
s32 SoftSweepSphere::TestPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f32 sp98;
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
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_169;
    f32 temp_f1_174;
    f32 temp_f1_247;
    f32 temp_f4_212;
    f32 temp_f4_286;
    f32 temp_f4_377;
    f32 temp_f7_167;
    f32 temp_f7_305;
    f32 temp_f8_307;
    f32 var_f4_420;
    f32 var_f5_177;
    f32 var_f5_327;
    f32 var_f6_156;
    f64 temp_f0_150;
    f64 temp_f1_194;
    f64 temp_f1_206;
    f64 temp_f1_424;
    f64 temp_f1_430;
    f64 temp_f1_434;
    f64 temp_f3_280;
    f64 temp_f4_311;
    f64 temp_f4_317;
    f64 temp_f4_321;
    s32 temp_cr0_gt_308;
    s32 temp_r3_340;
    s32 temp_r3_453;
    s32 var_r0_463;
    s32 var_r4_235;

    temp_f0_150 = M2C_FIELD(&arg0, f64 *, 0) - this->unk0;
    sp90 = temp_f0_150;
    var_f6_156 = 0.0f;
    sp140 = temp_f0_150;
    sp98 = arg0.unk8 - M2C_FIELD(this, f32 *, 8);
    sp148 = (f64) sp98;
    temp_f7_167 = M2C_FIELD(this, f32 *, 0x28);
    temp_f0_169 = ((f32) sp148 * temp_f7_167) + (((f32) sp140 * M2C_FIELD(this, f32 *, 0x20)) + (unksp144 * M2C_FIELD(this, f32 *, 0x24)));
    if (temp_f0_169 > var_f6_156) {
        var_f6_156 = temp_f0_169;
    }
    temp_f1_174 = this->unk34;
    if (var_f6_156 < temp_f1_174) {
        var_f5_177 = var_f6_156;
    } else {
        var_f5_177 = temp_f1_174;
    }
    sp80 = this->unk20 * (f64) var_f5_177;
    sp88 = temp_f7_167 * var_f5_177;
    sp110 = sp80;
    sp118 = (f64) sp88;
    temp_f1_194 = this->unk0 + sp110;
    sp70 = temp_f1_194;
    sp130 = temp_f1_194;
    sp78 = M2C_FIELD(this, f32 *, 8) + (f32) sp118;
    sp138 = (f64) sp78;
    temp_f1_206 = M2C_FIELD(&arg0, f64 *, 0) - temp_f1_194;
    sp60 = temp_f1_206;
    temp_f4_212 = this->unk30;
    sp100 = temp_f1_206;
    sp68 = arg0.unk8 - (f32) sp138;
    sp108 = (f64) sp68;
    if ((((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (unksp104 * unksp104))) > (temp_f4_212 * temp_f4_212)) {
        this->unk38 &= ~0x10;
        return 0;
    }
    var_r4_235 = 1;
    this->unk38 |= 0x10;
    temp_f1_247 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + (unksp144 * unksp144));
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
    if ((temp_f0_169 == 0.0f) || (this->unk34 == 0.0f)) {
        spE0.operator*(this->unk30 / std::sqrtf(temp_f1_247));
        sp40 = this->unk0 + M2C_BITWISE(f64, spE0);
        M2C_FIELD(arg1, f64 *, 0) = sp40;
        sp48 = M2C_FIELD(this, f32 *, 8) + spE0.unk8;
        spF0 = sp40;
        spF8 = (f64) sp48;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp48;
        return 1;
    }
    temp_f3_280 = this->unk0 - this->unk10;
    sp50 = temp_f3_280;
    temp_f4_286 = this->unk30;
    sp120 = temp_f3_280;
    sp58 = M2C_FIELD(this, f32 *, 8) - M2C_FIELD(this, f32 *, 0x18);
    sp128 = (f64) sp58;
    temp_f7_305 = 2.0f * (((f32) sp128 * (f32) sp148) + (((f32) sp120 * (f32) sp140) + (unksp124 * unksp144)));
    temp_f8_307 = (temp_f7_305 * temp_f7_305) - (4.0f * temp_f1_247 * ((((f32) sp128 * (f32) sp128) + (((f32) sp120 * (f32) sp120) + (unksp124 * unksp124))) - (temp_f4_286 * temp_f4_286)));
    temp_cr0_gt_308 = temp_f8_307 > 0.0f;
    if (temp_cr0_gt_308 != 0) {
        if (temp_cr0_gt_308 != 0) {
            temp_f4_311 = __frsqrte(temp_f8_307);
            temp_f4_317 = 0.5 * temp_f4_311 * -(((f64) temp_f8_307 * (temp_f4_311 * temp_f4_311)) - 3.0);
            temp_f4_321 = 0.5 * temp_f4_317 * -(((f64) temp_f8_307 * (temp_f4_317 * temp_f4_317)) - 3.0);
            var_f5_327 = (f32) ((f64) temp_f8_307 * (0.5 * temp_f4_321 * -(((f64) temp_f8_307 * (temp_f4_321 * temp_f4_321)) - 3.0)));
        } else if (temp_f8_307 < M2C_BITWISE(f32, 0.0)) {
            var_f5_327 = __float_nan;
        } else {
            spC = temp_f8_307;
            temp_r3_340 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_340) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {

                } else {
                    var_r4_235 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r4_235 = 5;
                } else {
                    var_r4_235 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r4_235 = 4;
                break;
            }
            if (var_r4_235 == 1) {
                var_f5_327 = __float_nan;
            } else {
                var_f5_327 = temp_f8_307;
            }
        }
        temp_f4_377 = (-temp_f7_305 + var_f5_327) / (2.0f * temp_f1_247);
        sp30 = sp140 * (f64) temp_f4_377;
        sp120 = sp30;
        sp38 = (f32) sp148 * temp_f4_377;
        sp128 = (f64) sp38;
        spD0 = sp30;
        spD8 = (f64) sp38;
        if ((((f32) sp128 * M2C_FIELD(this, f32 *, 0x28)) + (((f32) sp120 * M2C_FIELD(this, f32 *, 0x20)) + (unksp124 * M2C_FIELD(this, f32 *, 0x24)))) >= this->unk34) {
            sp20 = this->unk0 + sp120;
            M2C_FIELD(arg1, f64 *, 0) = sp20;
            sp28 = M2C_FIELD(this, f32 *, 8) + (f32) sp128;
            spC0 = sp20;
            spC8 = (f64) sp28;
            M2C_FIELD(arg1, f64 *, 8) = (f64) sp28;
            return 1;
        }
        goto block_31;
    }
block_31:
    var_f4_420 = -((temp_f0_169 * temp_f0_169) - temp_f1_247);
    if (var_f4_420 > 0.0f) {
        temp_f1_424 = __frsqrte(var_f4_420);
        temp_f1_430 = 0.5 * temp_f1_424 * -(((f64) var_f4_420 * (temp_f1_424 * temp_f1_424)) - 3.0);
        temp_f1_434 = 0.5 * temp_f1_430 * -(((f64) var_f4_420 * (temp_f1_430 * temp_f1_430)) - 3.0);
        var_f4_420 = (f32) ((f64) var_f4_420 * (0.5 * temp_f1_434 * -(((f64) var_f4_420 * (temp_f1_434 * temp_f1_434)) - 3.0)));
    } else if (var_f4_420 < M2C_BITWISE(f32, 0.0)) {
        var_f4_420 = __float_nan;
    } else {
        sp8 = var_f4_420;
        temp_r3_453 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_453) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_463 = 1;
            } else {
                var_r0_463 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_463 = 5;
            } else {
                var_r0_463 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_463 = 4;
            break;
        }
        if (var_r0_463 == 1) {
            var_f4_420 = __float_nan;
        }
    }
    spA0.operator*(this->unk30 / var_f4_420);
    sp10 = this->unk0 + M2C_BITWISE(f64, spA0);
    M2C_FIELD(arg1, f64 *, 0) = sp10;
    sp18 = M2C_FIELD(this, f32 *, 8) + spA0.unk8;
    spB0 = sp10;
    spB8 = (f64) sp18;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp18;
    return 1;
}
#endif

#if 0 // DRAFT: illegal operand
void SoftSweepSphere::GetBoundingBox(MKCollisionAABB *arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_523;

    temp_f1_523 = this->unk30;
    sp30 = temp_f1_523;
    sp28 = temp_f1_523;
    sp2C = temp_f1_523;
    sp80 = (f64) sp30;
    sp78 = (f64) sp28;
    Min(sp58, *((MKVector3 *) this));
    sp18 = sp58 - sp78;
    M2C_FIELD(arg0, f64 *, 0) = sp18;
    sp20 = sp58.unk8 - (f32) sp80;
    sp68 = sp18;
    sp70 = (f64) sp20;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp20;
    Max(sp38, *((MKVector3 *) this));
    sp8 = sp38 + sp78;
    M2C_FIELD(arg0, f64 *, 0x10) = sp8;
    sp10 = sp38.unk8 + (f32) sp80;
    sp48 = sp8;
    sp50 = (f64) sp10;
    M2C_FIELD(arg0, f64 *, 0x18) = (f64) sp10;
}
#endif

void SoftSweepSphere::Init(MKVector4 *arg0) {
    if (arg0 != NULL) {
        this->unk10 = M2C_FIELD(arg0, f64 *, 0);
        this->unk18 = M2C_FIELD(arg0, f64 *, 8);
        this->unk0 = this->unk10;
        this->unk8 = this->unk18;
        this->unk30 = arg0->unkC;
    } else {
        M2C_FIELD(this, f64 *, 0x10) = 0.0f;
        M2C_FIELD(this, f32 *, 0x14) = 0.0f;
        M2C_FIELD(this, f64 *, 0x18) = 0.0f;
        M2C_FIELD(this, f64 *, 0) = 0.0f;
        M2C_FIELD(this, f32 *, 4) = 0.0f;
        M2C_FIELD(this, f64 *, 8) = 0.0f;
        this->unk30 = 0.0f;
    }
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24) = 0.0f;
    M2C_FIELD(this, f32 *, 0x28) = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 &= ~0x10;
    this->unk38 |= 0x40;
}

void MKCloth::DisableClothCreate(bool arg0) {
    *MKCloth::clothCreateDisabled = (u8) this;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::LightCloth() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_729;
    f32 temp_f2_728;
    f32 temp_f2_804;
    f32 temp_f3_653;
    f32 temp_f3_731;
    f32 var_f6_735;
    f64 temp_f1_649;
    f64 temp_f2_741;
    f64 temp_f2_747;
    f64 temp_f2_751;
    f64 temp_f4_648;
    s32 temp_r5_770;
    s32 temp_r8_637;
    s32 var_r0_780;
    s32 var_r4_631;
    s32 var_r4_722;
    u32 var_r7_721;
    u32 var_r9_630;
    void *temp_r5_645;
    void *temp_r5_727;
    void *temp_r5_805;
    void *temp_r6_643;
    void *temp_r7_636;
    void *temp_r7_646;

    var_r9_630 = 0U;
    var_r4_631 = 0;
loop_2:
    if (var_r9_630 < (u32) M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0x28)) {
        temp_r7_636 = M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0x2C) + var_r4_631;
        temp_r8_637 = M2C_FIELD(this, s32 *, 0);
        temp_r6_643 = temp_r8_637 + (M2C_FIELD(temp_r7_636, s32 *, 0) * 0x38);
        temp_r5_645 = temp_r8_637 + (M2C_FIELD(temp_r7_636, s32 *, 4) * 0x38);
        temp_r7_646 = temp_r8_637 + (M2C_FIELD(temp_r7_636, s32 *, 8) * 0x38);
        temp_f4_648 = M2C_FIELD(temp_r6_643, f64 *, 0);
        temp_f1_649 = M2C_FIELD(temp_r5_645, f64 *, 0) - temp_f4_648;
        sp20 = temp_f1_649;
        temp_f3_653 = M2C_FIELD(temp_r6_643, f32 *, 8);
        sp50 = temp_f1_649;
        sp80 = temp_f1_649;
        sp28 = M2C_FIELD(temp_r5_645, f32 *, 8) - temp_f3_653;
        sp58 = (f64) sp28;
        sp88 = (f64) sp28;
        sp10 = M2C_FIELD(temp_r7_646, f64 *, 0) - temp_f4_648;
        sp70 = sp10;
        sp18 = M2C_FIELD(temp_r7_646, f32 *, 8) - temp_f3_653;
        sp78 = (f64) sp18;
        sp40 = sp10;
        sp48 = (f64) sp18;
        sp34 = ((f32) sp78 * (f32) sp80) - ((f32) sp70 * (f32) sp88);
        sp38 = ((f32) sp70 * unksp84) - (unksp74 * (f32) sp80);
        sp30 = (unksp74 * (f32) sp88) - ((f32) sp78 * unksp84);
        sp68 = (f64) sp38;
        sp60 = (f64) sp30;
        M2C_FIELD(temp_r6_643, f64 *, 0x20) = (f64) (M2C_FIELD(temp_r6_643, f64 *, 0x20) + sp60);
        M2C_FIELD(temp_r6_643, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r6_643, f32 *, 0x28) + (f32) sp68);
        M2C_FIELD(temp_r5_645, f64 *, 0x20) = (f64) (M2C_FIELD(temp_r5_645, f64 *, 0x20) + sp60);
        M2C_FIELD(temp_r5_645, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r5_645, f32 *, 0x28) + (f32) sp68);
        M2C_FIELD(temp_r7_646, f64 *, 0x20) = (f64) (M2C_FIELD(temp_r7_646, f64 *, 0x20) + sp60);
        var_r9_630 += 3;
        var_r4_631 += 0xC;
        M2C_FIELD(temp_r7_646, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r7_646, f32 *, 0x28) + (f32) sp68);
        goto loop_2;
    }
    var_r7_721 = 0U;
    var_r4_722 = 0;
loop_24:
    if (var_r7_721 < (u32) M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0)) {
        temp_r5_727 = M2C_FIELD(this, s32 *, 0) + (var_r4_722 + 0x20);
        temp_f2_728 = M2C_FIELD(temp_r5_727, f32 *, 0);
        temp_f1_729 = M2C_FIELD(temp_r5_727, f32 *, 4);
        temp_f3_731 = M2C_FIELD(temp_r5_727, f32 *, 8);
        var_f6_735 = (temp_f3_731 * temp_f3_731) + ((temp_f2_728 * temp_f2_728) + (temp_f1_729 * temp_f1_729));
        if (var_f6_735 > 0.000001f) {
            if (var_f6_735 > 0.0f) {
                temp_f2_741 = __frsqrte(var_f6_735);
                temp_f2_747 = 0.5 * temp_f2_741 * -(((f64) var_f6_735 * (temp_f2_741 * temp_f2_741)) - 3.0);
                temp_f2_751 = 0.5 * temp_f2_747 * -(((f64) var_f6_735 * (temp_f2_747 * temp_f2_747)) - 3.0);
                var_f6_735 = (f32) ((f64) var_f6_735 * (0.5 * temp_f2_751 * -(((f64) var_f6_735 * (temp_f2_751 * temp_f2_751)) - 3.0)));
            } else if (var_f6_735 < M2C_BITWISE(f32, 0.0)) {
                var_f6_735 = __float_nan;
            } else {
                sp8 = var_f6_735;
                temp_r5_770 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r5_770) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_780 = 1;
                    } else {
                        var_r0_780 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_780 = 5;
                    } else {
                        var_r0_780 = 3;
                    }
                    break;
                default:
                    var_r0_780 = 4;
                    break;
                }
                if (var_r0_780 == 1) {
                    var_f6_735 = __float_nan;
                }
            }
            temp_f2_804 = 1.0f / var_f6_735;
            temp_r5_805 = M2C_FIELD(this, s32 *, 0) + (var_r4_722 + 0x20);
            M2C_FIELD(temp_r5_805, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_805, f64 *, 0) * (f64) temp_f2_804);
            M2C_FIELD(temp_r5_805, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_805, f32 *, 8) * temp_f2_804);
        }
        var_r7_721 += 1;
        var_r4_722 += 0x38;
        goto loop_24;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::SatisfyConstraints() {
    f32 temp_f0_869;
    f32 temp_f1_865;
    f32 temp_f3_849;
    f32 temp_f4_855;
    f32 temp_f5_858;
    f32 temp_f6_859;
    f32 temp_f7_851;
    f32 temp_f7_870;
    f32 temp_f8_848;
    f32 temp_f8_871;
    f32 temp_f9_854;
    f32 temp_f9_872;
    s32 temp_r6_833;
    s32 var_r4_829;
    s8 *temp_r8_834;
    u32 var_r7_828;
    void *temp_r6_841;
    void *temp_r9_839;

    var_r7_828 = 0U;
    var_r4_829 = 0;
loop_4:
    if (var_r7_828 < (u32) M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0x10)) {
        temp_r6_833 = M2C_FIELD(this, s32 *, 0);
        temp_r8_834 = &this->unk30[var_r4_829];
        temp_r9_839 = temp_r6_833 + (M2C_FIELD(temp_r8_834, s32 *, 0) * 0x38);
        temp_r6_841 = temp_r6_833 + (M2C_FIELD(temp_r8_834, s32 *, 4) * 0x38);
        if ((M2C_FIELD(temp_r9_839, s32 *, 0x30) | M2C_FIELD(temp_r6_841, s32 *, 0x30)) != 0) {
            temp_f8_848 = M2C_FIELD(temp_r6_841, f32 *, 4) - M2C_FIELD(temp_r9_839, f32 *, 4);
            temp_f3_849 = M2C_FIELD(temp_r9_839, f32 *, 0);
            temp_f7_851 = M2C_FIELD(temp_r6_841, f32 *, 0) - temp_f3_849;
            temp_f9_854 = M2C_FIELD(temp_r6_841, f32 *, 8) - M2C_FIELD(temp_r9_839, f32 *, 8);
            temp_f4_855 = M2C_FIELD(temp_r8_834, f32 *, 8);
            temp_f5_858 = M2C_BITWISE(f32, M2C_FIELD(temp_r9_839, s32 *, 0x30));
            temp_f6_859 = M2C_BITWISE(f32, M2C_FIELD(temp_r6_841, s32 *, 0x30));
            temp_f1_865 = temp_f4_855 + (-((temp_f4_855 * temp_f4_855) - ((temp_f9_854 * temp_f9_854) + ((temp_f7_851 * temp_f7_851) + (temp_f8_848 * temp_f8_848)))) / (2.0f * temp_f4_855));
            temp_f0_869 = (temp_f1_865 - temp_f4_855) * __fres(temp_f1_865 * (temp_f5_858 + temp_f6_859));
            temp_f7_870 = temp_f7_851 * temp_f0_869;
            temp_f8_871 = temp_f8_848 * temp_f0_869;
            temp_f9_872 = temp_f9_854 * temp_f0_869;
            M2C_FIELD(temp_r9_839, f32 *, 0) = (f32) ((temp_f5_858 * temp_f7_870) + temp_f3_849);
            M2C_FIELD(temp_r9_839, f32 *, 4) = (f32) ((temp_f5_858 * temp_f8_871) + M2C_FIELD(temp_r9_839, f32 *, 4));
            M2C_FIELD(temp_r9_839, f32 *, 8) = (f32) ((temp_f5_858 * temp_f9_872) + M2C_FIELD(temp_r9_839, f32 *, 8));
            M2C_FIELD(temp_r6_841, f32 *, 0) = (f32) -((temp_f6_859 * temp_f7_870) - M2C_FIELD(temp_r6_841, f32 *, 0));
            M2C_FIELD(temp_r6_841, f32 *, 4) = (f32) -((temp_f6_859 * temp_f8_871) - M2C_FIELD(temp_r6_841, f32 *, 4));
            M2C_FIELD(temp_r6_841, f32 *, 8) = (f32) -((temp_f6_859 * temp_f9_872) - M2C_FIELD(temp_r6_841, f32 *, 8));
        }
        var_r7_828 += 1;
        var_r4_829 += 0xC;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKCloth::ApplyCollision() {
    MKVector3 *temp_r4_1318;
    SoftSweepSphere *temp_r26_1308;
    f32 temp_f0_1056;
    f32 temp_f0_1060;
    f32 temp_f0_1094;
    f32 temp_f0_1242;
    f32 temp_f0_1246;
    f32 temp_f0_1280;
    f32 temp_f0_1373;
    f32 temp_f0_1437;
    f32 temp_f10_1031;
    f32 temp_f10_1219;
    f32 temp_f11_1033;
    f32 temp_f11_1225;
    f32 temp_f12_1047;
    f32 temp_f12_1229;
    f32 temp_f13_1037;
    f32 temp_f13_1236;
    f32 temp_f1_1054;
    f32 temp_f1_1088;
    f32 temp_f1_1156;
    f32 temp_f1_1163;
    f32 temp_f1_1240;
    f32 temp_f1_1274;
    f32 temp_f1_1367;
    f32 temp_f1_975;
    f32 temp_f1_982;
    f32 temp_f29_1228;
    f32 temp_f2_1083;
    f32 temp_f2_1154;
    f32 temp_f2_1269;
    f32 temp_f2_1376;
    f32 temp_f2_1428;
    f32 temp_f2_973;
    f32 temp_f30_1045;
    f32 temp_f30_1224;
    f32 temp_f31_1034;
    f32 temp_f31_1079;
    f32 temp_f31_1217;
    f32 temp_f31_1265;
    f32 temp_f3_1084;
    f32 temp_f3_1270;
    f32 temp_f3_1440;
    f32 temp_f4_1051;
    f32 temp_f4_1082;
    f32 temp_f4_1148;
    f32 temp_f4_1268;
    f32 temp_f4_965;
    f32 temp_f5_1081;
    f32 temp_f5_1267;
    f32 temp_f6_1146;
    f32 temp_f6_1365;
    f32 temp_f6_1430;
    f32 temp_f6_966;
    f32 temp_f7_1038;
    f32 temp_f7_1078;
    f32 temp_f7_1152;
    f32 temp_f7_1222;
    f32 temp_f7_1264;
    f32 temp_f7_968;
    f32 temp_f8_1043;
    f32 temp_f8_1080;
    f32 temp_f8_1145;
    f32 temp_f8_1231;
    f32 temp_f8_1266;
    f32 temp_f8_967;
    f32 var_f9_1030;
    f32 var_f9_1218;
    s32 var_r11_1121;
    s32 var_r11_1341;
    s32 var_r24_918;
    s32 var_r25_1188;
    s32 var_r27_1303;
    s32 var_r29_1314;
    s32 var_r29_919;
    s32 var_r30_1305;
    s32 var_r3_1011;
    s32 var_r3_1123;
    s32 var_r3_1190;
    s32 var_r3_1343;
    s32 var_r3_1407;
    s32 var_r3_942;
    s32 var_r4_1021;
    s32 var_r4_1135;
    s32 var_r4_1209;
    s32 var_r4_1355;
    s32 var_r4_1417;
    s32 var_r4_952;
    s32 var_r6_1010;
    s32 var_r6_1406;
    s32 var_r6_941;
    u32 var_r12_1134;
    u32 var_r12_1354;
    u32 var_r24_1208;
    u32 var_r25_1313;
    u32 var_r7_1020;
    u32 var_r7_1416;
    u32 var_r7_951;
    void *temp_r10_1126;
    void *temp_r10_1346;
    void *temp_r26_1193;
    void *temp_r5_1032;
    void *temp_r5_1139;
    void *temp_r5_1213;
    void *temp_r5_1359;
    void *temp_r5_1427;
    void *temp_r5_962;
    void *temp_r8_1025;
    void *temp_r8_1421;
    void *temp_r8_956;

    if ((u32) this->unkCC != 0U) {
        var_r24_918 = 0;
        var_r29_919 = 0;
loop_3:
        if (var_r24_918 < (s32) this->unkD0) {
            ((MKCloth *) (M2C_FIELD(this, MKCloth **, 0)))->CollideHull(*M2C_FIELD(this, ClothNode ***, 4), this->unkCC + var_r29_919, *(MKModel_GetWorldMatrix(this->unkC)), M2C_ERROR(/* Read from unset register $r7 */));
            var_r24_918 += 1;
            var_r29_919 += 0x30;
            goto loop_3;
        }
    }
    if ((MKModel **) this->unkB4 != NULL) {
        var_r6_941 = 0;
        var_r3_942 = 0;
loop_14:
        if (var_r6_941 < (s32) this->unkBC) {
            if (((u8) *(this->unkB4 + (var_r3_942 + 0x10)) >> 5U) & 1) {
                var_r7_951 = 0U;
                var_r4_952 = 0;
loop_12:
                if (var_r7_951 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r8_956 = M2C_FIELD(this, MKCloth **, 0) + var_r4_952;
                    if (M2C_FIELD(temp_r8_956, f32 *, 0x30) != 0.0f) {
                        temp_r5_962 = this->unkB4 + var_r3_942;
                        temp_f4_965 = M2C_FIELD(temp_r5_962, f32 *, 0);
                        temp_f6_966 = M2C_FIELD(temp_r8_956, f32 *, 4) - M2C_FIELD(temp_r5_962, f32 *, 4);
                        temp_f8_967 = M2C_FIELD(temp_r5_962, f32 *, 0xC);
                        temp_f7_968 = M2C_FIELD(temp_r8_956, f32 *, 0) - temp_f4_965;
                        temp_f2_973 = M2C_FIELD(temp_r8_956, f32 *, 8) - M2C_FIELD(temp_r5_962, f32 *, 8);
                        temp_f1_975 = (temp_f2_973 * temp_f2_973) + ((temp_f7_968 * temp_f7_968) + (temp_f6_966 * temp_f6_966));
                        if (temp_f1_975 < (temp_f8_967 * temp_f8_967)) {
                            temp_f1_982 = temp_f8_967 * __fres(temp_f1_975 * (f32) __frsqrte(temp_f1_975));
                            M2C_FIELD(temp_r8_956, f32 *, 0) = (f32) ((temp_f7_968 * temp_f1_982) + temp_f4_965);
                            M2C_FIELD(temp_r8_956, f32 *, 4) = (f32) ((temp_f6_966 * temp_f1_982) + M2C_FIELD(temp_r5_962, f32 *, 4));
                            M2C_FIELD(temp_r8_956, f32 *, 8) = (f32) ((temp_f2_973 * temp_f1_982) + M2C_FIELD(temp_r5_962, f32 *, 8));
                        }
                    }
                    var_r7_951 += 1;
                    var_r4_952 += 0x38;
                    goto loop_12;
                }
            }
            var_r6_941 += 1;
            var_r3_942 += 0x18;
            goto loop_14;
        }
    }
    if ((MKModel **) this->unkC0 != NULL) {
        var_r6_1010 = 0;
        var_r3_1011 = 0;
loop_32:
        if (var_r6_1010 < (s32) this->unkC8) {
            if (((u8) *(this->unkC0 + (var_r3_1011 + 0x4C)) >> 5U) & 1) {
                var_r7_1020 = 0U;
                var_r4_1021 = 0;
loop_30:
                if (var_r7_1020 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r8_1025 = M2C_FIELD(this, MKCloth **, 0) + var_r4_1021;
                    if (M2C_FIELD(temp_r8_1025, f32 *, 0x30) != 0.0f) {
                        var_f9_1030 = 0.0f;
                        temp_f10_1031 = M2C_FIELD(temp_r8_1025, f32 *, 4);
                        temp_r5_1032 = this->unkC0 + var_r3_1011;
                        temp_f11_1033 = M2C_FIELD(temp_r8_1025, f32 *, 0);
                        temp_f31_1034 = M2C_FIELD(temp_r5_1032, f32 *, 4);
                        temp_f13_1037 = M2C_FIELD(temp_r5_1032, f32 *, 0);
                        temp_f7_1038 = M2C_FIELD(temp_r5_1032, f32 *, 0x34);
                        temp_f8_1043 = M2C_FIELD(temp_r5_1032, f32 *, 0x30);
                        temp_f30_1045 = M2C_FIELD(temp_r5_1032, f32 *, 8);
                        temp_f12_1047 = M2C_FIELD(temp_r8_1025, f32 *, 8);
                        temp_f4_1051 = M2C_FIELD(temp_r5_1032, f32 *, 0x38);
                        temp_f1_1054 = (temp_f4_1051 * (temp_f30_1045 - temp_f12_1047)) + ((temp_f8_1043 * (temp_f13_1037 - temp_f11_1033)) + (temp_f7_1038 * (temp_f31_1034 - temp_f10_1031)));
                        temp_f0_1056 = temp_f1_1054 - ((temp_f4_1051 * (M2C_FIELD(temp_r5_1032, f32 *, 0x18) - temp_f12_1047)) + ((temp_f8_1043 * (M2C_FIELD(temp_r5_1032, f32 *, 0x10) - temp_f11_1033)) + (temp_f7_1038 * (M2C_FIELD(temp_r5_1032, f32 *, 0x14) - temp_f10_1031))));
                        if (temp_f0_1056 != 0.0f) {
                            var_f9_1030 = temp_f1_1054 / temp_f0_1056;
                            temp_f0_1060 = M2C_FIELD(temp_r5_1032, f32 *, 0x48);
                            if (!(var_f9_1030 <= temp_f0_1060) && !(var_f9_1030 >= (1.0f - temp_f0_1060))) {
                                if (var_f9_1030 < 0.0f) {
                                    var_f9_1030 = 0.0f;
                                } else if (var_f9_1030 > 1.0f) {
                                    var_f9_1030 = 1.0f;
                                }
                                goto block_27;
                            }
                        } else {
block_27:
                            temp_f7_1078 = (temp_f7_1038 * var_f9_1030) + temp_f31_1034;
                            temp_f31_1079 = M2C_FIELD(temp_r5_1032, f32 *, 0x40);
                            temp_f8_1080 = (temp_f8_1043 * var_f9_1030) + temp_f13_1037;
                            temp_f5_1081 = (temp_f4_1051 * var_f9_1030) + temp_f30_1045;
                            temp_f4_1082 = temp_f10_1031 - temp_f7_1078;
                            temp_f2_1083 = temp_f11_1033 - temp_f8_1080;
                            temp_f3_1084 = temp_f12_1047 - temp_f5_1081;
                            temp_f1_1088 = (temp_f3_1084 * temp_f3_1084) + ((temp_f2_1083 * temp_f2_1083) + (temp_f4_1082 * temp_f4_1082));
                            if (temp_f1_1088 < (temp_f31_1079 * temp_f31_1079)) {
                                temp_f0_1094 = temp_f31_1079 / (temp_f1_1088 * (f32) __frsqrte(temp_f1_1088));
                                M2C_FIELD(temp_r8_1025, f32 *, 0) = (f32) ((temp_f2_1083 * temp_f0_1094) + temp_f8_1080);
                                M2C_FIELD(temp_r8_1025, f32 *, 4) = (f32) ((temp_f4_1082 * temp_f0_1094) + temp_f7_1078);
                                M2C_FIELD(temp_r8_1025, f32 *, 8) = (f32) ((temp_f3_1084 * temp_f0_1094) + temp_f5_1081);
                            }
                        }
                    }
                    var_r7_1020 += 1;
                    var_r4_1021 += 0x38;
                    goto loop_30;
                }
            }
            var_r6_1010 += 1;
            var_r3_1011 += 0x50;
            goto loop_32;
        }
    }
    if ((u8) this->unk9C != 0) {
        var_r11_1121 = 0;
        var_r3_1123 = 0;
loop_43:
        if (var_r11_1121 < (s32) *MKCloth::includedSphereCount) {
            temp_r10_1126 = &MKCloth::spheres + var_r3_1123;
            if (((u8) M2C_FIELD(temp_r10_1126, u8 *, 0x10) >> 5U) & 1) {
                var_r12_1134 = 0U;
                var_r4_1135 = 0;
loop_41:
                if (var_r12_1134 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r5_1139 = M2C_FIELD(this, MKCloth **, 0) + var_r4_1135;
                    if (M2C_FIELD(temp_r5_1139, f32 *, 0x30) != 0.0f) {
                        temp_f8_1145 = M2C_FIELD(temp_r10_1126, f32 *, 0xC);
                        temp_f6_1146 = M2C_FIELD(temp_r5_1139, f32 *, 4) - M2C_FIELD(temp_r10_1126, f32 *, 4);
                        temp_f4_1148 = M2C_FIELD(temp_r10_1126, f32 *, 0);
                        temp_f7_1152 = M2C_FIELD(temp_r5_1139, f32 *, 0) - temp_f4_1148;
                        temp_f2_1154 = M2C_FIELD(temp_r5_1139, f32 *, 8) - M2C_FIELD(temp_r10_1126, f32 *, 8);
                        temp_f1_1156 = (temp_f2_1154 * temp_f2_1154) + ((temp_f7_1152 * temp_f7_1152) + (temp_f6_1146 * temp_f6_1146));
                        if (temp_f1_1156 < (temp_f8_1145 * temp_f8_1145)) {
                            temp_f1_1163 = temp_f8_1145 * __fres(temp_f1_1156 * (f32) __frsqrte(temp_f1_1156));
                            M2C_FIELD(temp_r5_1139, f32 *, 0) = (f32) ((temp_f7_1152 * temp_f1_1163) + temp_f4_1148);
                            M2C_FIELD(temp_r5_1139, f32 *, 4) = (f32) ((temp_f6_1146 * temp_f1_1163) + M2C_FIELD(temp_r10_1126, f32 *, 4));
                            M2C_FIELD(temp_r5_1139, f32 *, 8) = (f32) ((temp_f2_1154 * temp_f1_1163) + M2C_FIELD(temp_r10_1126, f32 *, 8));
                        }
                    }
                    var_r12_1134 += 1;
                    var_r4_1135 += 0x38;
                    goto loop_41;
                }
            }
            var_r11_1121 += 1;
            var_r3_1123 += 0x18;
            goto loop_43;
        }
        var_r25_1188 = 0;
        var_r3_1190 = 0;
loop_60:
        if (var_r25_1188 < (s32) *MKCloth::includedCapsuleCount) {
            temp_r26_1193 = &MKCloth::capsules + var_r3_1190;
            if (((u8) M2C_FIELD(temp_r26_1193, u8 *, 0x4C) >> 5U) & 1) {
                var_r24_1208 = 0U;
                var_r4_1209 = 0;
loop_58:
                if (var_r24_1208 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r5_1213 = M2C_FIELD(this, MKCloth **, 0) + var_r4_1209;
                    if (M2C_FIELD(temp_r5_1213, f32 *, 0x30) != 0.0f) {
                        temp_f31_1217 = M2C_FIELD(temp_r26_1193, f32 *, 4);
                        var_f9_1218 = 0.0f;
                        temp_f10_1219 = M2C_FIELD(temp_r5_1213, f32 *, 4);
                        temp_f7_1222 = M2C_FIELD(temp_r26_1193, f32 *, 0x34);
                        temp_f30_1224 = M2C_FIELD(temp_r26_1193, f32 *, 0);
                        temp_f11_1225 = M2C_FIELD(temp_r5_1213, f32 *, 0);
                        temp_f29_1228 = M2C_FIELD(temp_r26_1193, f32 *, 8);
                        temp_f12_1229 = M2C_FIELD(temp_r5_1213, f32 *, 8);
                        temp_f8_1231 = M2C_FIELD(temp_r26_1193, f32 *, 0x30);
                        temp_f13_1236 = M2C_FIELD(temp_r26_1193, f32 *, 0x38);
                        temp_f1_1240 = (temp_f13_1236 * (temp_f29_1228 - temp_f12_1229)) + ((temp_f8_1231 * (temp_f30_1224 - temp_f11_1225)) + (temp_f7_1222 * (temp_f31_1217 - temp_f10_1219)));
                        temp_f0_1242 = temp_f1_1240 - ((temp_f13_1236 * (M2C_FIELD(temp_r26_1193, f32 *, 0x18) - temp_f12_1229)) + ((temp_f8_1231 * (M2C_FIELD(temp_r26_1193, f32 *, 0x10) - temp_f11_1225)) + (temp_f7_1222 * (M2C_FIELD(temp_r26_1193, f32 *, 0x14) - temp_f10_1219))));
                        if (temp_f0_1242 != 0.0f) {
                            var_f9_1218 = temp_f1_1240 / temp_f0_1242;
                            temp_f0_1246 = M2C_FIELD(temp_r26_1193, f32 *, 0x48);
                            if (!(var_f9_1218 <= temp_f0_1246) && !(var_f9_1218 >= (1.0f - temp_f0_1246))) {
                                if (var_f9_1218 < 0.0f) {
                                    var_f9_1218 = 0.0f;
                                } else if (var_f9_1218 > 1.0f) {
                                    var_f9_1218 = 1.0f;
                                }
                                goto block_55;
                            }
                        } else {
block_55:
                            temp_f7_1264 = (temp_f7_1222 * var_f9_1218) + temp_f31_1217;
                            temp_f31_1265 = M2C_FIELD(temp_r26_1193, f32 *, 0x40);
                            temp_f8_1266 = (temp_f8_1231 * var_f9_1218) + temp_f30_1224;
                            temp_f5_1267 = (temp_f13_1236 * var_f9_1218) + temp_f29_1228;
                            temp_f4_1268 = temp_f10_1219 - temp_f7_1264;
                            temp_f2_1269 = temp_f11_1225 - temp_f8_1266;
                            temp_f3_1270 = temp_f12_1229 - temp_f5_1267;
                            temp_f1_1274 = (temp_f3_1270 * temp_f3_1270) + ((temp_f2_1269 * temp_f2_1269) + (temp_f4_1268 * temp_f4_1268));
                            if (temp_f1_1274 < (temp_f31_1265 * temp_f31_1265)) {
                                temp_f0_1280 = temp_f31_1265 / (temp_f1_1274 * (f32) __frsqrte(temp_f1_1274));
                                M2C_FIELD(temp_r5_1213, f32 *, 0) = (f32) ((temp_f2_1269 * temp_f0_1280) + temp_f8_1266);
                                M2C_FIELD(temp_r5_1213, f32 *, 4) = (f32) ((temp_f4_1268 * temp_f0_1280) + temp_f7_1264);
                                M2C_FIELD(temp_r5_1213, f32 *, 8) = (f32) ((temp_f3_1270 * temp_f0_1280) + temp_f5_1267);
                            }
                        }
                    }
                    var_r24_1208 += 1;
                    var_r4_1209 += 0x38;
                    goto loop_58;
                }
            }
            var_r25_1188 += 1;
            var_r3_1190 += 0x50;
            goto loop_60;
        }
        var_r27_1303 = 0;
        var_r30_1305 = 0;
loop_69:
        if (var_r27_1303 < (s32) *MKCloth::includedSweepCount) {
            temp_r26_1308 = &MKCloth::sweepSpheres + var_r30_1305;
            if (((u8) temp_r26_1308->unk38 >> 5U) & 1) {
                var_r25_1313 = 0U;
                var_r29_1314 = 0;
loop_67:
                if (var_r25_1313 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r4_1318 = M2C_FIELD(this, MKCloth **, 0) + var_r29_1314;
                    if (M2C_FIELD(temp_r4_1318, f32 *, 0x30) != 0.0f) {
                        temp_r26_1308->TestPoint(*temp_r4_1318, temp_r4_1318);
                    }
                    var_r25_1313 += 1;
                    var_r29_1314 += 0x38;
                    goto loop_67;
                }
            }
            var_r27_1303 += 1;
            var_r30_1305 += 0x40;
            goto loop_69;
        }
        var_r11_1341 = 0;
        var_r3_1343 = 0;
loop_79:
        if (var_r11_1341 < (s32) *MKCloth::includedPlaneCount) {
            temp_r10_1346 = &MKCloth::planes + var_r3_1343;
            if (((u8) M2C_FIELD(temp_r10_1346, u8 *, 0x24) >> 5U) & 1) {
                var_r12_1354 = 0U;
                var_r4_1355 = 0;
loop_77:
                if (var_r12_1354 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r5_1359 = M2C_FIELD(this, MKCloth **, 0) + var_r4_1355;
                    if (M2C_FIELD(temp_r5_1359, f32 *, 0x30) != 0.0f) {
                        temp_f6_1365 = M2C_FIELD(temp_r10_1346, f32 *, 0);
                        temp_f1_1367 = M2C_FIELD(temp_r5_1359, f32 *, 0);
                        temp_f0_1373 = M2C_FIELD(temp_r10_1346, f32 *, 0xC) + ((M2C_FIELD(temp_r10_1346, f32 *, 8) * M2C_FIELD(temp_r5_1359, f32 *, 8)) + ((temp_f6_1365 * temp_f1_1367) + (M2C_FIELD(temp_r10_1346, f32 *, 4) * M2C_FIELD(temp_r5_1359, f32 *, 4))));
                        if (temp_f0_1373 < 0.0f) {
                            temp_f2_1376 = -temp_f0_1373;
                            M2C_FIELD(temp_r5_1359, f32 *, 0) = (f32) ((temp_f6_1365 * temp_f2_1376) + temp_f1_1367);
                            M2C_FIELD(temp_r5_1359, f32 *, 4) = (f32) ((M2C_FIELD(temp_r10_1346, f32 *, 4) * temp_f2_1376) + M2C_FIELD(temp_r5_1359, f32 *, 4));
                            M2C_FIELD(temp_r5_1359, f32 *, 8) = (f32) ((M2C_FIELD(temp_r10_1346, f32 *, 0) * temp_f2_1376) + M2C_FIELD(temp_r5_1359, f32 *, 8));
                        }
                    }
                    var_r12_1354 += 1;
                    var_r4_1355 += 0x38;
                    goto loop_77;
                }
            }
            var_r11_1341 += 1;
            var_r3_1343 += 0x28;
            goto loop_79;
        }
    }
    if ((MKModel **) this->unkA8 != NULL) {
        var_r6_1406 = 0;
        var_r3_1407 = 0;
loop_90:
        if (var_r6_1406 < (s32) this->unkB0) {
            if (((u8) *(this->unkA8 + (var_r3_1407 + 0x24)) >> 5U) & 1) {
                var_r7_1416 = 0U;
                var_r4_1417 = 0;
loop_88:
                if (var_r7_1416 < (ClothNode *) *M2C_FIELD(this, ClothNode ***, 4)) {
                    temp_r8_1421 = M2C_FIELD(this, MKCloth **, 0) + var_r4_1417;
                    if (M2C_FIELD(temp_r8_1421, f32 *, 0x30) != 0.0f) {
                        temp_r5_1427 = this->unkA8 + var_r3_1407;
                        temp_f2_1428 = M2C_FIELD(temp_r8_1421, f32 *, 0);
                        temp_f6_1430 = M2C_FIELD(temp_r5_1427, f32 *, 0);
                        temp_f0_1437 = M2C_FIELD(temp_r5_1427, f32 *, 0xC) + ((M2C_FIELD(temp_r5_1427, f32 *, 8) * M2C_FIELD(temp_r8_1421, f32 *, 8)) + ((temp_f6_1430 * temp_f2_1428) + (M2C_FIELD(temp_r5_1427, f32 *, 4) * M2C_FIELD(temp_r8_1421, f32 *, 4))));
                        if (temp_f0_1437 < 0.0f) {
                            temp_f3_1440 = -temp_f0_1437;
                            M2C_FIELD(temp_r8_1421, f32 *, 0) = (f32) ((temp_f6_1430 * temp_f3_1440) + temp_f2_1428);
                            M2C_FIELD(temp_r8_1421, f32 *, 4) = (f32) ((M2C_FIELD(temp_r5_1427, f32 *, 4) * temp_f3_1440) + M2C_FIELD(temp_r8_1421, f32 *, 4));
                            M2C_FIELD(temp_r8_1421, f32 *, 8) = (f32) ((M2C_FIELD(temp_r5_1427, f32 *, 0) * temp_f3_1440) + M2C_FIELD(temp_r8_1421, f32 *, 8));
                        }
                    }
                    var_r7_1416 += 1;
                    var_r4_1417 += 0x38;
                    goto loop_88;
                }
            }
            var_r6_1406 += 1;
            var_r3_1407 += 0x28;
            goto loop_90;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::CollideHull(ClothNode *arg0, int arg1, ClothCollisionHull &arg2, const Matrix *arg3) {
    M2C_UNK sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f12_1534;
    f32 temp_f21_1537;
    f32 temp_f24_1529;
    f32 temp_f24_1568;
    f32 temp_f25_1566;
    f32 temp_f26_1535;
    f32 temp_f26_1571;
    f32 var_f0_1693;
    f32 var_f21_1653;
    f32 var_f26_1582;
    f32 var_f7_1691;
    f64 temp_f0_1733;
    f64 temp_f10_1530;
    f64 temp_f12_1584;
    f64 temp_f21_1592;
    f64 temp_f21_1598;
    f64 temp_f21_1602;
    f64 temp_f3_1727;
    s32 temp_r0_1689;
    s32 temp_r8_1621;
    s32 var_ctr_1696;
    s32 var_r0_1631;
    s32 var_r10_1694;
    s32 var_r11_1507;
    s32 var_r11_1685;
    s32 var_r12_1692;
    s32 var_r6_1686;
    s32 var_r7_1509;
    s32 var_r7_1695;
    void *temp_r7_1730;
    void *temp_r8_1524;
    void *temp_r8_1702;
    void *temp_r9_1523;
    void *temp_r9_1690;

    var_r11_1507 = 0;
    var_r7_1509 = 0;
loop_22:
    if (var_r11_1507 < (s32) M2C_FIELD(arg1, s32 *, 0x20)) {
        temp_r9_1523 = &sp70 + var_r7_1509;
        temp_r8_1524 = M2C_FIELD(arg1, s32 *, 0x24) + var_r7_1509;
        M2C_FIELD(temp_r9_1523, f64 *, 0) = (f64) M2C_FIELD(temp_r8_1524, f64 *, 0);
        M2C_FIELD(temp_r9_1523, f64 *, 8) = (f64) M2C_FIELD(temp_r8_1524, f64 *, 8);
        temp_f24_1529 = M2C_FIELD(temp_r9_1523, f32 *, 0xC);
        temp_f10_1530 = -temp_f24_1529;
        sp30 = M2C_FIELD(temp_r9_1523, f64 *, 0) * temp_f10_1530;
        temp_f12_1534 = M2C_FIELD(temp_r9_1523, f32 *, 4);
        temp_f26_1535 = (f32) M2C_FIELD(temp_r9_1523, f64 *, 8);
        temp_f21_1537 = (f32) M2C_FIELD(temp_r9_1523, f64 *, 0);
        sp2C = temp_f24_1529;
        sp60 = sp30;
        sp20 = (temp_f26_1535 * arg2.unk20) + ((temp_f21_1537 * arg2.unk0) + (temp_f12_1534 * arg2.unk10));
        sp24 = (temp_f26_1535 * arg2.unk24) + ((temp_f21_1537 * arg2.unk4) + (temp_f12_1534 * arg2.unk14));
        sp28 = (temp_f26_1535 * arg2.unk28) + ((temp_f21_1537 * arg2.unk8) + (temp_f12_1534 * arg2.unk18));
        sp38 = temp_f26_1535 * (f32) temp_f10_1530;
        M2C_FIELD(temp_r9_1523, f64 *, 0) = (f64) sp20;
        M2C_FIELD(temp_r9_1523, f64 *, 8) = (f64) sp28;
        sp68 = (f64) sp38;
        temp_f25_1566 = (f32) M2C_FIELD(temp_r9_1523, f64 *, 0);
        temp_f24_1568 = M2C_FIELD(temp_r9_1523, f32 *, 4);
        temp_f26_1571 = (f32) M2C_FIELD(temp_r9_1523, f64 *, 8);
        sp50 = (f64) sp20;
        var_f26_1582 = (temp_f26_1571 * temp_f26_1571) + ((temp_f25_1566 * temp_f25_1566) + (temp_f24_1568 * temp_f24_1568));
        sp58 = (f64) sp28;
        temp_f12_1584 = ((f64) M2C_FIELD(&arg2, f32 *, 0) * sp60) + ((M2C_FIELD(&arg2, f64 *, 0x10) * sp60) + (((f64) M2C_FIELD(&arg2, f32 *, 0x20) * (f64) (f32) sp68) + M2C_FIELD(&arg2, f64 *, 0x30)));
        sp68 = (f32) (((f64) arg2.unk8 * sp60) + (((f64) arg2.unk18 * sp60) + (((f64) arg2.unk28 * (f64) (f32) sp68) + (f64) arg2.unk38)));
        sp60 = temp_f12_1584;
        if (var_f26_1582 > 0.000001f) {
            if (var_f26_1582 > 0.0f) {
                temp_f21_1592 = __frsqrte(var_f26_1582);
                temp_f21_1598 = 0.5 * temp_f21_1592 * -(((f64) var_f26_1582 * (temp_f21_1592 * temp_f21_1592)) - 3.0);
                temp_f21_1602 = 0.5 * temp_f21_1598 * -(((f64) var_f26_1582 * (temp_f21_1598 * temp_f21_1598)) - 3.0);
                var_f26_1582 = (f32) ((f64) var_f26_1582 * (0.5 * temp_f21_1602 * -(((f64) var_f26_1582 * (temp_f21_1602 * temp_f21_1602)) - 3.0)));
            } else if (var_f26_1582 < M2C_BITWISE(f32, 0.0)) {
                var_f26_1582 = __float_nan;
            } else {
                sp8 = var_f26_1582;
                temp_r8_1621 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r8_1621) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1631 = 1;
                    } else {
                        var_r0_1631 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1631 = 5;
                    } else {
                        var_r0_1631 = 3;
                    }
                    break;
                default:
                    var_r0_1631 = 4;
                    break;
                }
                if (var_r0_1631 == 1) {
                    var_f26_1582 = __float_nan;
                }
            }
            var_f21_1653 = 1.0f / var_f26_1582;
        } else {
            var_f21_1653 = 0.0f;
        }
        var_r11_1507 += 1;
        var_r7_1509 += 0x10;
        M2C_FIELD(temp_r9_1523, f64 *, 0) = (f32) ((f32) M2C_FIELD(temp_r9_1523, f64 *, 0) * var_f21_1653);
        M2C_FIELD(temp_r9_1523, f32 *, 4) = (f32) (M2C_FIELD(temp_r9_1523, f32 *, 4) * var_f21_1653);
        M2C_FIELD(temp_r9_1523, f64 *, 8) = (f32) ((f32) M2C_FIELD(temp_r9_1523, f64 *, 8) * var_f21_1653);
        M2C_FIELD(temp_r9_1523, f32 *, 0xC) = (f32) -(((f32) M2C_FIELD(temp_r9_1523, f64 *, 8) * sp68) + (((f32) M2C_FIELD(temp_r9_1523, f64 *, 0) * (f32) sp60) + (M2C_FIELD(temp_r9_1523, f32 *, 4) * unksp64)));
        goto loop_22;
    }
    var_r11_1685 = 0;
    var_r6_1686 = 0;
loop_32:
    if (var_r11_1685 < (s32) arg0) {
        temp_r0_1689 = M2C_FIELD(arg1, s32 *, 0x20);
        temp_r9_1690 = this + var_r6_1686;
        var_f7_1691 = -1e8f;
        var_r12_1692 = -1;
        var_f0_1693 = 0.0f;
        var_r10_1694 = 0;
        var_r7_1695 = 0;
        var_ctr_1696 = temp_r0_1689;
        if (temp_r0_1689 > 0) {
loop_25:
            temp_r8_1702 = &sp70 + var_r7_1695;
            var_f0_1693 = M2C_FIELD(temp_r8_1702, f32 *, 0xC) + ((M2C_FIELD(temp_r9_1690, f32 *, 8) * M2C_FIELD(temp_r8_1702, f32 *, 8)) + ((M2C_FIELD(temp_r9_1690, f32 *, 0) * M2C_FIELD(temp_r8_1702, f32 *, 0)) + (M2C_FIELD(temp_r9_1690, f32 *, 4) * M2C_FIELD(temp_r8_1702, f32 *, 4))));
            if (!(var_f0_1693 >= 0.0f)) {
                if (var_f0_1693 > var_f7_1691) {
                    var_r12_1692 = var_r10_1694;
                    var_f7_1691 = var_f0_1693;
                }
                var_r10_1694 += 1;
                var_r7_1695 += 0x10;
                var_ctr_1696 -= 1;
                if (var_ctr_1696 != 0) {
                    goto loop_25;
                }
            }
        }
        if (var_f0_1693 < 0.0f) {
            temp_f3_1727 = -var_f7_1691;
            temp_r7_1730 = &sp70 + (var_r12_1692 * 0x10);
            temp_f0_1733 = M2C_FIELD(temp_r7_1730, f64 *, 0) * temp_f3_1727;
            sp10 = temp_f0_1733;
            sp40 = temp_f0_1733;
            sp18 = M2C_FIELD(temp_r7_1730, f32 *, 8) * (f32) temp_f3_1727;
            sp48 = (f64) sp18;
            M2C_FIELD(temp_r9_1690, f32 *, 0) = (f64) ((f64) M2C_FIELD(temp_r9_1690, f32 *, 0) + temp_f0_1733);
            M2C_FIELD(temp_r9_1690, f32 *, 8) = (f32) (M2C_FIELD(temp_r9_1690, f32 *, 8) + (f32) sp48);
        }
        var_r11_1685 += 1;
        var_r6_1686 += 0x38;
        goto loop_32;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::UpdatePosition() {
    f32 sp40;
    f32 sp3C;
    f32 sp38;                                       /* compiler-managed */
    f32 sp30;
    f32 sp2C;
    f32 sp28;                                       /* compiler-managed */
    MKVector3 sp18;
    MKVector3 sp8;
    MKVector3 *temp_r28_1895;
    f32 temp_f0_1908;
    f32 temp_f11_1928;
    f32 temp_f12_1930;
    f32 temp_f13_1927;
    f32 temp_f1_1911;
    f32 temp_f27_1920;
    f32 temp_f28_1916;
    f32 temp_f29_1918;
    f32 temp_f2_1914;
    f32 temp_f30_1891;
    f32 temp_f31_1888;
    f32 temp_f6_1899;
    f32 temp_f7_1936;
    f32 temp_f9_1924;
    s32 var_ctr_1823;
    s32 var_r30_1890;
    s32 var_r3_1822;
    s32 var_r3_1853;
    u32 var_r29_1889;
    u32 var_r5_1852;
    u8 *temp_r5_1825;
    void *temp_r4_1856;

    IncludeCollision();
    this->unk10 = 1e9f;
    this->unk14 = 1e9f;
    this->unk18 = 1e9f;
    this->unk20 = -1e9f;
    this->unk24 = -1e9f;
    this->unk28 = -1e9f;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    if ((u8) this->unk9D != 0) {
        var_r3_1822 = 0;
        var_ctr_1823 = 4;
        do {
            temp_r5_1825 = &MKCloth::globalForces[var_r3_1822];
            if ((s32) M2C_FIELD(temp_r5_1825, s32 *, 0x10) == 0) {
                sp38 = (f64) sp38 + M2C_FIELD(temp_r5_1825, f64 *, 0);
                sp40 += M2C_FIELD(temp_r5_1825, f32 *, 8);
            } else {
                sp28 = (f64) sp28 + M2C_FIELD(temp_r5_1825, f64 *, 0);
                sp30 += M2C_FIELD(temp_r5_1825, f32 *, 8);
            }
            var_r3_1822 += 0x18;
            var_ctr_1823 -= 1;
        } while (var_ctr_1823 != 0);
    } else {
        var_r5_1852 = 0U;
        var_r3_1853 = 0;
loop_12:
        if (var_r5_1852 < (u32) this->unk98) {
            temp_r4_1856 = this + var_r3_1853;
            if ((s32) M2C_FIELD(temp_r4_1856, s32 *, 0x48) == 0) {
                sp38 += M2C_FIELD(temp_r4_1856, f64 *, 0x38);
                sp40 += M2C_FIELD(temp_r4_1856, f32 *, 0x40);
            } else {
                sp28 += M2C_FIELD(temp_r4_1856, f64 *, 0x38);
                sp30 += M2C_FIELD(temp_r4_1856, f32 *, 0x40);
            }
            var_r5_1852 += 1;
            var_r3_1853 += 0x18;
            goto loop_12;
        }
    }
    temp_f31_1888 = gUpdateTimeDelta;
    var_r29_1889 = 0U;
    var_r30_1890 = 0;
    temp_f30_1891 = __fres(temp_f31_1888);
loop_17:
    if (var_r29_1889 < (u32) *M2C_FIELD(this, u32 **, 4)) {
        temp_r28_1895 = M2C_FIELD(this, s32 *, 0) + var_r30_1890;
        if ((u32) M2C_FIELD(temp_r28_1895, u32 *, 0x30) != 0U) {
            temp_f6_1899 = temp_r28_1895->unk0;
            temp_f0_1908 = temp_f30_1891 * (temp_f6_1899 - M2C_FIELD(temp_r28_1895, f32 *, 0x10));
            M2C_FIELD(temp_r28_1895, f32 *, 0x10) = temp_f6_1899;
            temp_f1_1911 = temp_f30_1891 * (temp_r28_1895->unk4 - M2C_FIELD(temp_r28_1895, f32 *, 0x14));
            temp_f2_1914 = temp_f30_1891 * (temp_r28_1895->unk8 - M2C_FIELD(temp_r28_1895, f32 *, 0x18));
            M2C_FIELD(temp_r28_1895, f32 *, 0x14) = (f32) temp_r28_1895->unk4;
            temp_f28_1916 = temp_f1_1911 - sp2C;
            temp_f29_1918 = temp_f0_1908 - (f32) sp28;
            temp_f27_1920 = temp_f2_1914 - sp30;
            M2C_FIELD(temp_r28_1895, f32 *, 0x18) = (f32) temp_r28_1895->unk8;
            temp_f9_1924 = M2C_FIELD(temp_r28_1895, f32 *, 0x24);
            temp_f13_1927 = M2C_FIELD(temp_r28_1895, f32 *, 0x20);
            temp_f11_1928 = M2C_FIELD(temp_r28_1895, f32 *, 0x28);
            temp_f12_1930 = this->unkD4;
            temp_f7_1936 = (1.0f - clothFaceEffect) * ((temp_f27_1920 * temp_f11_1928) + ((temp_f29_1918 * temp_f13_1927) + (temp_f28_1916 * temp_f9_1924)));
            temp_r28_1895->unk0 += temp_f31_1888 * ((-((temp_f12_1930 * ((clothFaceEffect * temp_f29_1918) + (temp_f13_1927 * temp_f7_1936))) - (f32) sp38) * temp_f31_1888) + temp_f0_1908);
            temp_r28_1895->unk4 += temp_f31_1888 * ((-((temp_f12_1930 * ((clothFaceEffect * temp_f28_1916) + (temp_f9_1924 * temp_f7_1936))) - sp3C) * temp_f31_1888) + temp_f1_1911);
            temp_r28_1895->unk8 += temp_f31_1888 * ((-((temp_f12_1930 * ((clothFaceEffect * temp_f27_1920) + (temp_f11_1928 * temp_f7_1936))) - sp40) * temp_f31_1888) + temp_f2_1914);
        }
        Min(sp18, *temp_r28_1895);
        M2C_FIELD(this, f32 *, 0x10) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(this, f32 *, 0x18) = (f64) sp18.unk8;
        Max(sp8, *temp_r28_1895);
        var_r29_1889 += 1;
        var_r30_1890 += 0x38;
        M2C_FIELD(this, f32 *, 0x20) = M2C_BITWISE(f64, sp8);
        M2C_FIELD(this, f32 *, 0x28) = (f64) sp8.unk8;
        goto loop_17;
    }
    ApplyCollision();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKCloth *' to
void MKCloth::IncludeCollision() {
    MKCollisionAABB sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    MKVector3 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKModel **temp_r4_2458;
    MKModel **temp_r4_2532;
    MKModel **temp_r6_2362;
    MKModel **temp_r6_2450;
    MKVector3 *temp_r26_2205;
    SoftSweepSphere *temp_r3_2020;
    f32 temp_f0_2189;
    f32 temp_f0_2424;
    f32 temp_f1_2188;
    f32 temp_f1_2214;
    f32 temp_f1_2423;
    f32 temp_f1_2459;
    f32 temp_f2_2087;
    f32 temp_f2_2142;
    f32 temp_f2_2316;
    f32 temp_f2_2375;
    f32 temp_f3_2086;
    f32 temp_f3_2096;
    f32 temp_f3_2105;
    f32 temp_f3_2315;
    f32 temp_f3_2325;
    f32 temp_f3_2334;
    f64 temp_f0_2139;
    f64 temp_f0_2163;
    f64 temp_f0_2372;
    f64 temp_f0_2396;
    f64 temp_f3_2138;
    f64 temp_f3_2371;
    s32 temp_r3_2533;
    s32 temp_r5_2363;
    s32 temp_r5_2451;
    s32 var_ctr_2075;
    s32 var_ctr_2124;
    s32 var_r25_2016;
    s32 var_r27_2018;
    s32 var_r27_2203;
    s32 var_r27_2447;
    s32 var_r29_2201;
    s32 var_r29_2446;
    s32 var_r3_2074;
    s32 var_r3_2123;
    s32 var_r3_2306;
    s32 var_r3_2359;
    s32 var_r5_2305;
    s32 var_r8_2358;
    u8 temp_r4_2083;
    u8 temp_r4_2132;
    u8 var_r0_2032;
    u8 var_r0_2251;
    u8 var_r0_2493;
    void *temp_r5_2400;
    void *temp_r6_2311;
    void *temp_r7_2077;
    void *temp_r7_2126;

    if ((u8) this->unk9C != 0) {
        var_r25_2016 = 0;
        var_r27_2018 = 0;
        do {
            temp_r3_2020 = &MKCloth::sweepSpheres + var_r27_2018;
            temp_r3_2020->unk38 &= ~0x20;
            if (((u8) temp_r3_2020->unk38 >> 6U) & 1) {
                temp_r3_2020->GetBoundingBox(&sp228);
                var_r0_2032 = 0;
                if ((sp228.unk10 > this->unk10) && (M2C_BITWISE(f32, sp228) < this->unk20) && (sp228.unk14 > this->unk14) && (sp228.unk4 < this->unk24) && (sp228.unk18 > this->unk18) && (sp228.unk8 < this->unk28)) {
                    var_r0_2032 = 1;
                }
                if (var_r0_2032 != 0) {
                    temp_r3_2020->unk38 |= 0x20;
                    *MKCloth::includedSweepCount = var_r25_2016 + 1;
                }
            }
            var_r25_2016 += 1;
            var_r27_2018 += 0x40;
        } while (var_r25_2016 < 0xA);
        var_r3_2074 = 0;
        var_ctr_2075 = 0x1E;
        do {
            temp_r7_2077 = &MKCloth::spheres + var_r3_2074;
            M2C_FIELD(temp_r7_2077, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r7_2077, u8 *, 0x10) & ~0x20);
            temp_r4_2083 = M2C_FIELD(temp_r7_2077, u8 *, 0x10);
            if ((temp_r4_2083 >> 6U) & 1) {
                temp_f3_2086 = M2C_FIELD(temp_r7_2077, f32 *, 0);
                temp_f2_2087 = M2C_FIELD(temp_r7_2077, f32 *, 0xC);
                if (((temp_f3_2086 + temp_f2_2087) > this->unk10) && ((temp_f3_2086 - temp_f2_2087) < this->unk20)) {
                    temp_f3_2096 = M2C_FIELD(temp_r7_2077, f32 *, 8);
                    if (((temp_f3_2096 + temp_f2_2087) > this->unk18) && ((temp_f3_2096 - temp_f2_2087) < this->unk28)) {
                        temp_f3_2105 = M2C_FIELD(temp_r7_2077, f32 *, 4);
                        if (((temp_f3_2105 + temp_f2_2087) > this->unk14) && ((temp_f3_2105 - temp_f2_2087) < this->unk24)) {
                            M2C_FIELD(temp_r7_2077, u8 *, 0x10) = (u8) (temp_r4_2083 | 0x20);
                        }
                    }
                }
            }
            var_r3_2074 += 0x18;
            var_ctr_2075 -= 1;
        } while (var_ctr_2075 != 0);
        var_r3_2123 = 0;
        var_ctr_2124 = 0xA;
        do {
            temp_r7_2126 = &MKCloth::planes + var_r3_2123;
            M2C_FIELD(temp_r7_2126, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r7_2126, u8 *, 0x24) & ~0x20);
            temp_r4_2132 = M2C_FIELD(temp_r7_2126, u8 *, 0x24);
            if ((temp_r4_2132 >> 6U) & 1) {
                temp_f3_2138 = (f64) M2C_FIELD(this, f32 *, 0x20);
                temp_f0_2139 = (f64) M2C_FIELD(this, f32 *, 0x10) + temp_f3_2138;
                sp18 = temp_f0_2139;
                temp_f2_2142 = this->unk28;
                sp188 = temp_f0_2139;
                sp20 = this->unk18 + temp_f2_2142;
                sp190 = (f64) sp20;
                sp78 = temp_f0_2139 * 5.222099017e-315;
                sp1D8 = sp78;
                sp80 = (f32) sp190 * 0.5f;
                sp198 = sp78;
                sp1A0 = (f64) sp80;
                sp1E0 = (f64) sp80;
                temp_f0_2163 = temp_f3_2138 - sp1D8;
                spB8 = temp_f0_2163;
                sp178 = temp_f0_2163;
                spC0 = temp_f2_2142 - (f32) sp1E0;
                sp180 = (f64) spC0;
                temp_f1_2188 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + (unksp17C * unksp17C));
                temp_f0_2189 = M2C_FIELD(temp_r7_2126, f32 *, 0xC) + ((M2C_FIELD(temp_r7_2126, f32 *, 8) * (f32) sp1E0) + ((M2C_FIELD(temp_r7_2126, f32 *, 0) * (f32) sp1D8) + (M2C_FIELD(temp_r7_2126, f32 *, 4) * unksp1DC)));
                unksp1E4 = temp_f1_2188;
                if ((temp_f0_2189 * temp_f0_2189) < temp_f1_2188) {
                    M2C_FIELD(temp_r7_2126, u8 *, 0x24) = (u8) (temp_r4_2132 | 0x20);
                }
            }
            var_r3_2123 += 0x28;
            var_ctr_2124 -= 1;
        } while (var_ctr_2124 != 0);
        var_r29_2201 = 0;
        var_r27_2203 = 0;
        do {
            temp_r26_2205 = &MKCloth::capsules + var_r27_2203;
            M2C_FIELD(temp_r26_2205, u8 *, 0x4C) = (u8) (M2C_FIELD(temp_r26_2205, u8 *, 0x4C) & ~0x20);
            if (((u8) M2C_FIELD(temp_r26_2205, u8 *, 0x4C) >> 6U) & 1) {
                temp_f1_2214 = M2C_FIELD(temp_r26_2205, f32 *, 0x40);
                spB0 = temp_f1_2214;
                spA8 = temp_f1_2214;
                spAC = temp_f1_2214;
                sp1D0 = (f64) spB0;
                sp1C8 = (f64) spA8;
                Min(sp158, *temp_r26_2205);
                sp68 = sp158 - sp1C8;
                sp168 = sp68;
                sp70 = sp158.unk8 - (f32) sp1D0;
                sp208 = sp68;
                sp170 = (f64) sp70;
                sp210 = (f64) sp70;
                Max(sp138, *temp_r26_2205);
                sp58 = sp138 + sp1C8;
                var_r0_2251 = 0;
                sp218 = sp58;
                sp148 = sp58;
                sp60 = sp138.unk8 + (f32) sp1D0;
                sp150 = (f64) sp60;
                sp220 = (f64) sp60;
                if (((f32) sp218 > this->unk10) && ((f32) sp208 < this->unk20) && (unksp21C > this->unk14) && (unksp20C < this->unk24) && ((f32) sp220 > this->unk18) && ((f32) sp210 < this->unk28)) {
                    var_r0_2251 = 1;
                }
                if (var_r0_2251 != 0) {
                    M2C_FIELD(temp_r26_2205, u8 *, 0x4C) = (u8) (M2C_FIELD(temp_r26_2205, u8 *, 0x4C) | 0x20);
                    *MKCloth::includedCapsuleCount = var_r29_2201 + 1;
                }
            }
            var_r29_2201 += 1;
            var_r27_2203 += 0x50;
        } while (var_r29_2201 < 0x1E);
    }
    if ((MKModel **) this->unkB4 != NULL) {
        var_r5_2305 = 0;
        var_r3_2306 = 0;
loop_50:
        if (var_r5_2305 < (s32) this->unkBC) {
            temp_r6_2311 = this->unkB4 + var_r3_2306;
            M2C_FIELD(temp_r6_2311, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r6_2311, u8 *, 0x10) & ~0x20);
            temp_f3_2315 = M2C_FIELD(temp_r6_2311, f32 *, 0);
            temp_f2_2316 = M2C_FIELD(temp_r6_2311, f32 *, 0xC);
            if (((temp_f3_2315 + temp_f2_2316) > this->unk10) && ((temp_f3_2315 - temp_f2_2316) < this->unk20)) {
                temp_f3_2325 = M2C_FIELD(temp_r6_2311, f32 *, 8);
                if (((temp_f3_2325 + temp_f2_2316) > this->unk18) && ((temp_f3_2325 - temp_f2_2316) < this->unk28)) {
                    temp_f3_2334 = M2C_FIELD(temp_r6_2311, f32 *, 4);
                    if (((temp_f3_2334 + temp_f2_2316) > this->unk14) && ((temp_f3_2334 - temp_f2_2316) < this->unk24)) {
                        M2C_FIELD(temp_r6_2311, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r6_2311, u8 *, 0x10) | 0x20);
                    }
                }
            }
            var_r5_2305 += 1;
            var_r3_2306 += 0x18;
            goto loop_50;
        }
    }
    if ((MKModel **) this->unkA8 != NULL) {
        var_r8_2358 = 0;
        var_r3_2359 = 0;
loop_56:
        if (var_r8_2358 < (s32) this->unkB0) {
            temp_r6_2362 = this->unkA8;
            temp_r5_2363 = var_r3_2359 + 0x24;
            *(temp_r6_2362 + temp_r5_2363) = *(temp_r6_2362 + temp_r5_2363) & ~0x20;
            temp_f3_2371 = (f64) M2C_FIELD(this, f32 *, 0x20);
            temp_f0_2372 = (f64) M2C_FIELD(this, f32 *, 0x10) + temp_f3_2371;
            sp8 = temp_f0_2372;
            temp_f2_2375 = this->unk28;
            sp118 = temp_f0_2372;
            sp10 = this->unk18 + temp_f2_2375;
            sp120 = (f64) sp10;
            sp48 = temp_f0_2372 * 5.222099017e-315;
            sp1B8 = sp48;
            sp50 = (f32) sp120 * 0.5f;
            sp128 = sp48;
            sp130 = (f64) sp50;
            sp1C0 = (f64) sp50;
            temp_f0_2396 = temp_f3_2371 - sp1B8;
            sp98 = temp_f0_2396;
            temp_r5_2400 = this->unkA8 + var_r3_2359;
            sp108 = temp_f0_2396;
            spA0 = temp_f2_2375 - (f32) sp1C0;
            sp110 = (f64) spA0;
            temp_f1_2423 = ((f32) sp110 * (f32) sp110) + (((f32) sp108 * (f32) sp108) + (unksp10C * unksp10C));
            temp_f0_2424 = M2C_FIELD(temp_r5_2400, f32 *, 0xC) + ((M2C_FIELD(temp_r5_2400, f32 *, 8) * (f32) sp1C0) + ((M2C_FIELD(temp_r5_2400, f32 *, 0) * (f32) sp1B8) + (M2C_FIELD(temp_r5_2400, f32 *, 4) * unksp1BC)));
            unksp1C4 = temp_f1_2423;
            if ((temp_f0_2424 * temp_f0_2424) < temp_f1_2423) {
                M2C_FIELD(temp_r5_2400, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_2400, u8 *, 0x24) | 0x20);
            }
            var_r8_2358 += 1;
            var_r3_2359 += 0x28;
            goto loop_56;
        }
    }
    if ((MKModel **) this->unkC0 != NULL) {
        var_r29_2446 = 0;
        var_r27_2447 = 0;
loop_69:
        if (var_r29_2446 < (s32) this->unkC8) {
            temp_r6_2450 = this->unkC0;
            temp_r5_2451 = var_r27_2447 + 0x4C;
            *(temp_r6_2450 + temp_r5_2451) = *(temp_r6_2450 + temp_r5_2451) & ~0x20;
            temp_r4_2458 = this->unkC0;
            temp_f1_2459 = *(temp_r4_2458 + (var_r27_2447 + 0x40));
            sp90 = temp_f1_2459;
            sp88 = temp_f1_2459;
            sp8C = temp_f1_2459;
            sp1B0 = (f64) sp90;
            sp1A8 = (f64) sp88;
            Min(spE8, *(temp_r4_2458 + var_r27_2447));
            sp38 = spE8 - sp1A8;
            spF8 = sp38;
            sp40 = spE8.unk8 - (f32) sp1B0;
            sp1E8 = sp38;
            sp100 = (f64) sp40;
            sp1F0 = (f64) sp40;
            Max(spC8, *(this->unkC0 + var_r27_2447));
            sp28 = spC8 + sp1A8;
            var_r0_2493 = 0;
            sp1F8 = sp28;
            spD8 = sp28;
            sp30 = spC8.unk8 + (f32) sp1B0;
            spE0 = (f64) sp30;
            sp200 = (f64) sp30;
            if (((f32) sp1F8 > this->unk10) && ((f32) sp1E8 < this->unk20) && (unksp1FC > this->unk14) && (unksp1EC < this->unk24) && ((f32) sp200 > this->unk18) && ((f32) sp1F0 < this->unk28)) {
                var_r0_2493 = 1;
            }
            if (var_r0_2493 != 0) {
                temp_r4_2532 = this->unkC0;
                temp_r3_2533 = var_r27_2447 + 0x4C;
                *(temp_r4_2532 + temp_r3_2533) = *(temp_r4_2532 + temp_r3_2533) | 0x20;
            }
            var_r29_2446 += 1;
            var_r27_2447 += 0x50;
            goto loop_69;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKCloth::DrawConstraints() {
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
    f64 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp54;
    f32 sp50;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKModel **temp_r3_2768;
    MKModel **temp_r4_2713;
    MKVector3 *temp_r3_2776;
    MKVector3 *temp_r3_2800;
    MKVector3 *temp_r4_2847;
    f64 temp_f0_2672;
    f64 temp_f0_2684;
    s32 temp_r0_2667;
    s32 var_r28_2709;
    s32 var_r28_2764;
    s32 var_r28_2831;
    s32 var_r29_2588;
    s32 var_r31_2661;
    s32 var_r31_2710;
    s32 var_r31_2765;
    s32 var_r31_2832;
    u32 var_r28_2587;
    u32 var_r29_2660;
    void *temp_r3_2670;
    void *temp_r4_2674;

    if (((s32) M2C_FIELD(&gRenderState, s32 *, 4) == 3) || ((s32) MKSoftBody_showConstraints != 0)) {
        MKPrimitive(0x109, 0);
        MKBegin(M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0x10) * 2);
        var_r28_2587 = 0U;
        var_r29_2588 = 0;
loop_4:
        if (var_r28_2587 < (u32) M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0x10)) {
            MKSetColorF(1.0f, 0.0f, 0.0f, 1.0f);
            MKSetPositionV(*(M2C_FIELD(this, s32 *, 0) + (this->unk30[var_r29_2588] * 0x38)));
            MKSetColorF(1.0f, 1.0f, 0.0f, 1.0f);
            MKSetPositionV(*(M2C_FIELD(this, s32 *, 0) + (M2C_FIELD(&this->unk30[var_r29_2588], s32 *, 4) * 0x38)));
            var_r28_2587 += 1;
            var_r29_2588 += 0xC;
            goto loop_4;
        }
        MKEnd();
        MKEndPrimitive();
    }
    if ((s32) MKSoftBody_enableBoundBox != 0) {
        sp78 = 0.0f;
        sp7C = 0.6f;
        sp80 = 1.0f;
        sp84 = 1.0f;
        spF8 = (f64) sp78;
        sp100 = (f64) sp80;
        MKShape_DrawBox(*((MKCollisionAABB *) &this->unk10), *((MKVector4 *) &spF8), Matrix::identity, 1U);
    }
    if ((s32) M2C_FIELD(&gRenderState, s32 *, 4) == 8) {
        MKPrimitive(0x109, 0);
        MKBegin(M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0) * 2);
        MKSetColorF(0.0f, 1.0f, 0.0f, 1.0f);
        var_r29_2660 = 0U;
        var_r31_2661 = 0;
loop_11:
        if (var_r29_2660 < (u32) M2C_FIELD(M2C_FIELD(this, void **, 4), u32 *, 0)) {
            MKSetPositionV(*(M2C_FIELD(this, s32 *, 0) + var_r31_2661));
            temp_r0_2667 = M2C_FIELD(this, s32 *, 0);
            temp_r3_2670 = temp_r0_2667 + (var_r31_2661 + 0x20);
            temp_f0_2672 = M2C_FIELD(temp_r3_2670, f64 *, 0) * 5.398241246e-315;
            sp68 = temp_f0_2672;
            temp_r4_2674 = temp_r0_2667 + var_r31_2661;
            spD8 = temp_f0_2672;
            sp70 = M2C_FIELD(temp_r3_2670, f32 *, 8) * 10.0f;
            spE0 = (f64) sp70;
            temp_f0_2684 = M2C_FIELD(temp_r4_2674, f64 *, 0) + temp_f0_2672;
            sp58 = temp_f0_2684;
            spE8 = temp_f0_2684;
            sp60 = M2C_FIELD(temp_r4_2674, f32 *, 8) + (f32) spE0;
            spF0 = (f64) sp60;
            MKSetPositionV(*((MKVector3 *) &spE8));
            var_r29_2660 += 1;
            var_r31_2661 += 0x38;
            goto loop_11;
        }
        MKEnd();
        MKEndPrimitive();
    }
    if ((s32) MKSoftBody_showCollision != 0) {
        var_r28_2709 = 0;
        var_r31_2710 = 0;
loop_19:
        if (var_r28_2709 < (s32) this->unkBC) {
            temp_r4_2713 = this->unkB4;
            if (((u8) *(temp_r4_2713 + (var_r31_2710 + 0x10)) >> 5U) & 1) {
                sp48 = 0.0f;
                sp4C = 0.0f;
                sp50 = 1.0f;
                sp54 = 1.0f;
                spC8 = (f64) sp48;
                spD0 = (f64) sp50;
                MKShape_DrawSphere(*(temp_r4_2713 + var_r31_2710), 7, 5, *((MKVector4 *) &spC8), Matrix::identity, 1U);
            } else {
                sp38 = 1.0f;
                sp3C = 0.0f;
                sp40 = 0.0f;
                sp44 = 0.5f;
                spB8 = (f64) sp38;
                spC0 = (f64) sp40;
                MKShape_DrawSphere(*(temp_r4_2713 + var_r31_2710), 7, 5, *((MKVector4 *) &spB8), Matrix::identity, 1U);
            }
            var_r28_2709 += 1;
            var_r31_2710 += 0x18;
            goto loop_19;
        }
        var_r28_2764 = 0;
        var_r31_2765 = 0;
loop_25:
        if (var_r28_2764 < (s32) this->unkC8) {
            temp_r3_2768 = this->unkC0;
            if (((u8) *(temp_r3_2768 + (var_r31_2765 + 0x4C)) >> 5U) & 1) {
                temp_r3_2776 = temp_r3_2768 + var_r31_2765;
                sp28 = 0.4f;
                sp2C = 0.0f;
                sp30 = 0.8f;
                sp34 = 1.0f;
                spA8 = (f64) sp28;
                spB0 = (f64) sp30;
                MKShape_DrawCapsule(*temp_r3_2776, *(temp_r3_2776 + 0x10), M2C_FIELD(temp_r3_2776, f32 *, 0x40), 8, 5, *((MKVector4 *) &spA8), Matrix::identity, 1U);
            } else {
                temp_r3_2800 = temp_r3_2768 + var_r31_2765;
                sp18 = 0.8f;
                sp1C = 0.0f;
                sp20 = 0.2f;
                sp24 = 1.0f;
                sp98 = (f64) sp18;
                spA0 = (f64) sp20;
                MKShape_DrawCapsule(*temp_r3_2800, *(temp_r3_2800 + 0x10), M2C_FIELD(temp_r3_2800, f32 *, 0x40), 8, 5, *((MKVector4 *) &sp98), Matrix::identity, 1U);
            }
            var_r28_2764 += 1;
            var_r31_2765 += 0x50;
            goto loop_25;
        }
        var_r28_2831 = 0;
        var_r31_2832 = 0;
loop_28:
        if (var_r28_2831 < (s32) this->unkB0) {
            sp8 = 1.0f;
            spC = 0.7f;
            sp10 = 0.0f;
            sp14 = 1.0f;
            sp88 = (f64) sp8;
            sp90 = (f64) sp10;
            temp_r4_2847 = this->unkA8 + var_r31_2832;
            MKShape_DrawPlane(*(temp_r4_2847 + 0x10), *temp_r4_2847, M2C_FIELD(temp_r4_2847, f32 *, 0x20), *((MKVector4 *) &sp88), Matrix::identity, 1U);
            var_r28_2831 += 1;
            var_r31_2832 += 0x28;
            goto loop_28;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::UpdateGlobalCollisionPrims() {
    f64 sp90;
    MKVector3 sp70;
    M2C_UNK sp60;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    MKVector3 *temp_r3_2908;
    f32 temp_f0_2945;
    f32 temp_f1_2946;
    f32 temp_f31_2910;
    f32 var_f1_2950;
    f64 temp_f0_2912;
    f64 temp_f0_2923;
    f64 temp_f2_2953;
    f64 temp_f2_2959;
    f64 temp_f2_2963;
    s32 temp_r3_2982;
    s32 var_r0_2992;
    s32 var_r26_2888;
    s32 var_r27_2886;
    u8 temp_r25_2898;
    void *temp_r28_2890;
    void *temp_r3_2944;

    var_r27_2886 = 0;
    var_r26_2888 = 0;
    do {
        temp_r28_2890 = &MKCloth::globalCollisionPrim + var_r26_2888;
        if ((u8) M2C_FIELD(temp_r28_2890, u8 *, 0xC) != 0) {
            temp_r25_2898 = MKModel_GetRefPointType(M2C_FIELD(temp_r28_2890, MKModel **, 0), M2C_FIELD(temp_r28_2890, s32 *, 4));
            MKModel_GetRefPointMatrix(M2C_FIELD(temp_r28_2890, MKModel **, 0), M2C_FIELD(temp_r28_2890, s32 *, 4), (Matrix *) &sp60, 1U);
            if ((s32) temp_r25_2898 == 3) {
                temp_r3_2908 = MKModel_GetRefPointData(M2C_FIELD(temp_r28_2890, MKModel **, 0), M2C_FIELD(temp_r28_2890, s32 *, 4));
                temp_f31_2910 = M2C_FIELD(temp_r3_2908, f32 *, 0x60);
                temp_f0_2912 = sp70 * (f64) temp_f31_2910;
                sp28 = temp_f0_2912;
                sp38 = temp_f0_2912;
                sp30 = sp70.unk8 * temp_f31_2910;
                sp40 = (f64) sp30;
                temp_f0_2923 = sp90 + temp_f0_2912;
                sp18 = temp_f0_2923;
                sp48 = temp_f0_2923;
                sp20 = sp98 + (f32) sp40;
                sp50 = (f64) sp20;
                ((MKCloth *) (M2C_FIELD(temp_r28_2890, MKCloth **, 8)))->SetCollisionCapsule((s32) &sp90, *((MKVector3 *) &sp48), *temp_r3_2908, M2C_FIELD(temp_r3_2908, f32 *, 0x64));
            } else if ((s32) temp_r25_2898 == 4) {
                temp_r3_2944 = MKModel_GetRefPointData(M2C_FIELD(temp_r28_2890, MKModel **, 0), M2C_FIELD(temp_r28_2890, s32 *, 4));
                temp_f0_2945 = M2C_FIELD(temp_r3_2944, f32 *, 0x60);
                temp_f1_2946 = M2C_FIELD(temp_r3_2944, f32 *, 0x64);
                var_f1_2950 = (temp_f0_2945 * temp_f0_2945) + (temp_f1_2946 * temp_f1_2946);
                if (var_f1_2950 > 0.0f) {
                    temp_f2_2953 = __frsqrte(var_f1_2950);
                    temp_f2_2959 = 0.5 * temp_f2_2953 * -(((f64) var_f1_2950 * (temp_f2_2953 * temp_f2_2953)) - 3.0);
                    temp_f2_2963 = 0.5 * temp_f2_2959 * -(((f64) var_f1_2950 * (temp_f2_2959 * temp_f2_2959)) - 3.0);
                    var_f1_2950 = (f32) ((f64) var_f1_2950 * (0.5 * temp_f2_2963 * -(((f64) var_f1_2950 * (temp_f2_2963 * temp_f2_2963)) - 3.0)));
                } else if (var_f1_2950 < M2C_BITWISE(f32, 0.0)) {
                    var_f1_2950 = __float_nan;
                } else {
                    sp10 = var_f1_2950;
                    temp_r3_2982 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_2982) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_2992 = 1;
                        } else {
                            var_r0_2992 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_2992 = 5;
                        } else {
                            var_r0_2992 = 3;
                        }
                        break;
                    default:
                        var_r0_2992 = 4;
                        break;
                    }
                    if (var_r0_2992 == 1) {
                        var_f1_2950 = __float_nan;
                    }
                }
                ((MKCloth *) (M2C_FIELD(temp_r28_2890, MKCloth **, 8)))->SetCollisionPlane((s32) &sp90, sp70, *(M2C_ERROR(/* Read from unset register $r6 */)), var_f1_2950);
            } else {
                ((MKCloth *) (M2C_FIELD(temp_r28_2890, MKCloth **, 8)))->SetCollisionSphere(MKModel_GetRefPointData(M2C_FIELD(temp_r28_2890, MKModel **, 0), M2C_FIELD(temp_r28_2890, s32 *, 4)), *(M2C_ERROR(/* Read from unset register $r5 */)));
            }
        }
        var_r27_2886 += 1;
        var_r26_2888 += 0x10;
    } while (var_r27_2886 < 0x50);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
ClothNode **MKCloth::GetName() {
    return M2C_FIELD(this, s32 *, 4) + 0x30;
}
#endif

void MKCloth::SetIterations(int arg0) {
    this->unkD8 = arg0;
}

void MKCloth::SetFriction(float arg0) {
    this->unkD4 = arg0;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void MKCloth::SetCollisionCapsule(int arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3) {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_3102;
    f32 temp_f3_3101;
    f32 temp_f4_3103;
    f32 var_f2_3175;
    f32 var_f5_3108;
    f64 temp_f2_3114;
    f64 temp_f2_3120;
    f64 temp_f2_3124;
    s32 temp_r3_3143;
    s32 temp_r6_3066;
    s32 var_r0_3153;
    void *temp_r3_3071;
    void *temp_r3_3185;

    temp_r6_3066 = (s32) this * 0x50;
    temp_r3_3071 = &MKCloth::capsules + temp_r6_3066;
    M2C_FIELD(temp_r3_3071, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(temp_r3_3071, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
    M2C_FIELD(temp_r3_3071, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r3_3071, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    sp10 = M2C_FIELD(&arg1, f64 *, 0) - M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(temp_r3_3071, f64 *, 0x30) = sp10;
    sp18 = arg1.unk8 - (f32) M2C_FIELD(arg0, f64 *, 8);
    sp20 = sp10;
    M2C_FIELD(temp_r3_3071, f64 *, 0x38) = (f64) sp18;
    sp28 = (f64) sp18;
    M2C_FIELD(temp_r3_3071, f64 *, 0x20) = (f64) M2C_FIELD(temp_r3_3071, f64 *, 0x30);
    M2C_FIELD(temp_r3_3071, f64 *, 0x28) = (f64) M2C_FIELD(temp_r3_3071, f64 *, 0x38);
    temp_f3_3101 = (f32) M2C_FIELD(temp_r3_3071, f64 *, 0x20);
    temp_f2_3102 = M2C_FIELD(temp_r3_3071, f32 *, 0x24);
    temp_f4_3103 = (f32) M2C_FIELD(temp_r3_3071, f64 *, 0x28);
    var_f5_3108 = (temp_f4_3103 * temp_f4_3103) + ((temp_f3_3101 * temp_f3_3101) + (temp_f2_3102 * temp_f2_3102));
    if (var_f5_3108 > 0.000001f) {
        if (var_f5_3108 > 0.0f) {
            temp_f2_3114 = __frsqrte(var_f5_3108);
            temp_f2_3120 = 0.5 * temp_f2_3114 * -(((f64) var_f5_3108 * (temp_f2_3114 * temp_f2_3114)) - 3.0);
            temp_f2_3124 = 0.5 * temp_f2_3120 * -(((f64) var_f5_3108 * (temp_f2_3120 * temp_f2_3120)) - 3.0);
            var_f5_3108 = (f32) ((f64) var_f5_3108 * (0.5 * temp_f2_3124 * -(((f64) var_f5_3108 * (temp_f2_3124 * temp_f2_3124)) - 3.0)));
        } else if (var_f5_3108 < M2C_BITWISE(f32, 0.0)) {
            var_f5_3108 = __float_nan;
        } else {
            sp8 = var_f5_3108;
            temp_r3_3143 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_3143) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3153 = 1;
                } else {
                    var_r0_3153 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3153 = 5;
                } else {
                    var_r0_3153 = 3;
                }
                break;
            default:
                var_r0_3153 = 4;
                break;
            }
            if (var_r0_3153 == 1) {
                var_f5_3108 = __float_nan;
            }
        }
        var_f2_3175 = 1.0f / var_f5_3108;
    } else {
        var_f2_3175 = 0.0f;
        var_f5_3108 = 0.0f;
    }
    temp_r3_3185 = &MKCloth::capsules + temp_r6_3066;
    M2C_FIELD(temp_r3_3071, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(temp_r3_3071, f64 *, 0x20) * var_f2_3175);
    M2C_FIELD(temp_r3_3071, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r3_3071, f32 *, 0x24) * var_f2_3175);
    M2C_FIELD(temp_r3_3071, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(temp_r3_3071, f64 *, 0x28) * var_f2_3175);
    M2C_FIELD(temp_r3_3185, f32 *, 0x44) = var_f5_3108;
    M2C_FIELD(temp_r3_3185, f32 *, 0x40) = arg3;
    M2C_FIELD(temp_r3_3185, f32 *, 0x48) = (f32) -(arg3 / M2C_FIELD(temp_r3_3185, f32 *, 0x44));
}
#endif

s32 MKCloth::AllocateCapsule() {
    s32 var_ctr_3211;
    s32 var_r3_3209;
    s32 var_r4_3210;
    u8 temp_r5_3215;
    void *temp_r5_3213;

    var_r3_3209 = 0;
    var_r4_3210 = 0;
    var_ctr_3211 = 0x1E;
loop_1:
    temp_r5_3213 = &MKCloth::capsules + var_r4_3210;
    temp_r5_3215 = M2C_FIELD(temp_r5_3213, u8 *, 0x4C);
    if (!((temp_r5_3215 >> 7U) & 1)) {
        M2C_FIELD(temp_r5_3213, u8 *, 0x4C) = (u8) (temp_r5_3215 | 0x80);
        M2C_FIELD(temp_r5_3213, u8 *, 0x4C) = (u8) (M2C_FIELD(temp_r5_3213, u8 *, 0x4C) | 0x40);
        return var_r3_3209;
    }
    var_r3_3209 += 1;
    var_r4_3210 += 0x50;
    var_ctr_3211 -= 1;
    if (var_ctr_3211 == 0) {
        return -1;
    }
    goto loop_1;
}

void MKCloth::SetCollisionPlane(int arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3) {
    void *temp_r3_3246;

    temp_r3_3246 = &MKCloth::planes + ((s32) this * 0x28);
    M2C_FIELD(temp_r3_3246, f64 *, 0) = (f64) M2C_FIELD(&arg1, f32 *, 0);
    M2C_FIELD(temp_r3_3246, f64 *, 8) = (f64) M2C_FIELD(&arg1, f32 *, 8);
    M2C_FIELD(temp_r3_3246, f32 *, 0xC) = (f32) -((M2C_FIELD(arg0, f32 *, 8) * arg1.unk8) + ((M2C_FIELD(arg0, f32 *, 0) * arg1.unk0) + (M2C_FIELD(arg0, f32 *, 4) * arg1.unk4)));
    M2C_FIELD(temp_r3_3246, f64 *, 0x10) = (f64) M2C_FIELD(arg0, f32 *, 0);
    M2C_FIELD(temp_r3_3246, f64 *, 0x18) = (f64) M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(temp_r3_3246, f32 *, 0x20) = arg3;
}

s32 MKCloth::AllocatePlane() {
    s32 var_ctr_3271;
    s32 var_r3_3269;
    s32 var_r4_3270;
    u8 temp_r5_3275;
    void *temp_r5_3273;

    var_r3_3269 = 0;
    var_r4_3270 = 0;
    var_ctr_3271 = 0xA;
loop_1:
    temp_r5_3273 = &MKCloth::planes + var_r4_3270;
    temp_r5_3275 = M2C_FIELD(temp_r5_3273, u8 *, 0x24);
    if (!((temp_r5_3275 >> 7U) & 1)) {
        M2C_FIELD(temp_r5_3273, u8 *, 0x24) = (u8) (temp_r5_3275 | 0x80);
        M2C_FIELD(temp_r5_3273, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_3273, u8 *, 0x24) | 0x40);
        return var_r3_3269;
    }
    var_r3_3269 += 1;
    var_r4_3270 += 0x28;
    var_ctr_3271 -= 1;
    if (var_ctr_3271 == 0) {
        return -1;
    }
    goto loop_1;
}

void MKCloth::SetCollisionSphere(int arg0, const MKVector4 &arg1) {
    void *temp_r3_3301;

    temp_r3_3301 = &MKCloth::spheres + ((s32) this * 0x18);
    M2C_FIELD(temp_r3_3301, f64 *, 0) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(temp_r3_3301, f64 *, 8) = (f64) M2C_FIELD(arg0, f64 *, 8);
}

s32 MKCloth::AllocateSphere() {
    s32 var_ctr_3315;
    s32 var_r3_3313;
    s32 var_r4_3314;
    u8 temp_r5_3319;
    void *temp_r5_3317;

    var_r3_3313 = 0;
    var_r4_3314 = 0;
    var_ctr_3315 = 0x1E;
loop_1:
    temp_r5_3317 = &MKCloth::spheres + var_r4_3314;
    temp_r5_3319 = M2C_FIELD(temp_r5_3317, u8 *, 0x10);
    if (!((temp_r5_3319 >> 7U) & 1)) {
        M2C_FIELD(temp_r5_3317, u8 *, 0x10) = (u8) (temp_r5_3319 | 0x80);
        M2C_FIELD(temp_r5_3317, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r5_3317, u8 *, 0x10) | 0x40);
        return var_r3_3313;
    }
    var_r3_3313 += 1;
    var_r4_3314 += 0x18;
    var_ctr_3315 -= 1;
    if (var_ctr_3315 == 0) {
        return -1;
    }
    goto loop_1;
}

void MKCloth::MoveCollisionSweepSphere(int arg0, const MKVector3 &arg1) {
    ((SoftSweepSphere *) (&MKCloth::sweepSpheres + ((s32) this << 6)))->UpdatePos(*((MKVector3 *) arg0));
}

void MKCloth::ResetCollisionSweepSphere(int arg0, MKVector4 *arg1) {
    ((SoftSweepSphere *) (&MKCloth::sweepSpheres + ((s32) this << 6)))->Init((MKVector4 *) arg0);
}

void MKCloth::ReleaseSweepSphere(int arg0) {
    void *temp_r3_3377;

    temp_r3_3377 = &MKCloth::sweepSpheres + ((s32) this << 6);
    M2C_FIELD(temp_r3_3377, u8 *, 0x38) = (u8) (M2C_FIELD(temp_r3_3377, u8 *, 0x38) & ~0x80);
    M2C_FIELD(temp_r3_3377, u8 *, 0x38) = (u8) (M2C_FIELD(temp_r3_3377, u8 *, 0x38) & ~0x40);
}

s32 MKCloth::AllocateSweepSphere() {
    s32 var_ctr_3396;
    s32 var_r3_3394;
    s32 var_r4_3395;
    u8 temp_r5_3400;
    void *temp_r5_3398;

    var_r3_3394 = 0;
    var_r4_3395 = 0;
    var_ctr_3396 = 0xA;
loop_1:
    temp_r5_3398 = &MKCloth::sweepSpheres + var_r4_3395;
    temp_r5_3400 = M2C_FIELD(temp_r5_3398, u8 *, 0x38);
    if (!((temp_r5_3400 >> 7U) & 1)) {
        M2C_FIELD(temp_r5_3398, u8 *, 0x38) = (u8) (temp_r5_3400 | 0x80);
        M2C_FIELD(temp_r5_3398, u8 *, 0x38) = (u8) (M2C_FIELD(temp_r5_3398, u8 *, 0x38) | 0x40);
        return var_r3_3394;
    }
    var_r3_3394 += 1;
    var_r4_3395 += 0x40;
    var_ctr_3396 -= 1;
    if (var_ctr_3396 == 0) {
        return -1;
    }
    goto loop_1;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void MKCloth::SetInternalCollisionCapsule(int arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3, float arg4) {
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    s32 temp_r31_3431;
    void *temp_r3_3456;
    void *temp_r3_3466;
    void *temp_r3_3480;
    void *temp_r5_3437;

    temp_r31_3431 = arg0 * 0x50;
    temp_r5_3437 = this->unkC0 + temp_r31_3431;
    M2C_FIELD(temp_r5_3437, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r5_3437, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    sp38.operator*(arg3);
    sp18 = M2C_FIELD(&arg1, f64 *, 0) + M2C_BITWISE(f64, sp38);
    temp_r3_3456 = this->unkC0 + (temp_r31_3431 + 0x10);
    M2C_FIELD(temp_r3_3456, f64 *, 0) = sp18;
    sp20 = arg1.unk8 + sp38.unk8;
    sp48 = sp18;
    M2C_FIELD(temp_r3_3456, f64 *, 8) = (f64) sp20;
    sp50 = (f64) sp20;
    temp_r3_3466 = this->unkC0 + (temp_r31_3431 + 0x20);
    M2C_FIELD(temp_r3_3466, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
    M2C_FIELD(temp_r3_3466, f64 *, 8) = (f64) M2C_FIELD(&arg2, f64 *, 8);
    M2C_FIELD((this->unkC0 + temp_r31_3431), f32 *, 0x40) = arg4;
    sp8 = M2C_FIELD(&arg2, f64 *, 0) * (f64) arg3;
    temp_r3_3480 = this->unkC0 + (temp_r31_3431 + 0x30);
    M2C_FIELD(temp_r3_3480, f64 *, 0) = sp8;
    sp28 = sp8;
    sp10 = arg2.unk8 * arg3;
    M2C_FIELD(temp_r3_3480, f64 *, 8) = (f64) sp10;
    sp30 = (f64) sp10;
    M2C_FIELD((this->unkC0 + temp_r31_3431), f32 *, 0x44) = arg3;
    M2C_FIELD((this->unkC0 + temp_r31_3431), f32 *, 0x48) = (f32) -(arg4 / arg3);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MKCloth::CreateInternalCollisionCapsules(int arg0) {
    MKHeap *temp_r3_3515;
    MKModel **temp_r5_3535;
    MKModel **var_r3_3522;
    s32 temp_r3_3536;
    s32 var_ctr_3531;
    s32 var_r4_3528;

    temp_r3_3515 = MKHeap::Current();
    if (temp_r3_3515 != NULL) {
        var_r3_3522 = ((MKHeap *) (temp_r3_3515->Current()))->Alloc(arg0 * 0x50, NULL, 0);
    } else {
        var_r3_3522 = malloc(arg0 * 0x50);
    }
    var_r4_3528 = 0;
    this->unkC0 = var_r3_3522;
    var_ctr_3531 = arg0;
    if (arg0 > 0) {
        do {
            temp_r5_3535 = this->unkC0;
            temp_r3_3536 = var_r4_3528 + 0x4C;
            var_r4_3528 += 0x50;
            *(temp_r5_3535 + temp_r3_3536) = *(temp_r5_3535 + temp_r3_3536) & ~8;
            var_ctr_3531 -= 1;
        } while (var_ctr_3531 != 0);
    }
    this->unkC8 = arg0;
}
#endif

void MKCloth::SetInternalCollisionSphere(int arg0, const MKVector4 &arg1) {
    void *temp_r3_3558;

    temp_r3_3558 = this->unkB4 + (arg0 * 0x18);
    M2C_FIELD(temp_r3_3558, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r3_3558, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
}

#if 0 // DRAFT: illegal use of non-static member
void MKCloth::CreateInternalCollisionSpheres(int arg0) {
    MKHeap *temp_r3_3573;
    MKModel **temp_r5_3593;
    MKModel **var_r3_3580;
    s32 temp_r3_3594;
    s32 var_ctr_3589;
    s32 var_r4_3586;

    temp_r3_3573 = MKHeap::Current();
    if (temp_r3_3573 != NULL) {
        var_r3_3580 = ((MKHeap *) (temp_r3_3573->Current()))->Alloc(arg0 * 0x18, NULL, 0);
    } else {
        var_r3_3580 = malloc(arg0 * 0x18);
    }
    var_r4_3586 = 0;
    this->unkB4 = var_r3_3580;
    var_ctr_3589 = arg0;
    if (arg0 > 0) {
        do {
            temp_r5_3593 = this->unkB4;
            temp_r3_3594 = var_r4_3586 + 0x10;
            var_r4_3586 += 0x18;
            *(temp_r5_3593 + temp_r3_3594) = *(temp_r5_3593 + temp_r3_3594) & ~8;
            var_ctr_3589 -= 1;
        } while (var_ctr_3589 != 0);
    }
    this->unkBC = arg0;
}
#endif

void MKCloth::SetInternalCollisionPlane(int arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3) {
    s32 temp_r7_3613;
    void *temp_r4_3619;
    void *temp_r4_3636;

    temp_r7_3613 = arg0 * 0x28;
    temp_r4_3619 = this->unkA8 + temp_r7_3613;
    M2C_FIELD(temp_r4_3619, f64 *, 0) = (f64) M2C_FIELD(&arg2, f32 *, 0);
    M2C_FIELD(temp_r4_3619, f64 *, 8) = (f64) M2C_FIELD(&arg2, f32 *, 8);
    M2C_FIELD((this->unkA8 + temp_r7_3613), f32 *, 0xC) = (f32) -((arg1.unk8 * arg2.unk8) + ((arg1.unk0 * arg2.unk0) + (arg1.unk4 * arg2.unk4)));
    temp_r4_3636 = this->unkA8 + (temp_r7_3613 + 0x10);
    M2C_FIELD(temp_r4_3636, f64 *, 0) = (f64) M2C_FIELD(&arg1, f32 *, 0);
    M2C_FIELD(temp_r4_3636, f64 *, 8) = (f64) M2C_FIELD(&arg1, f32 *, 8);
    M2C_FIELD((this->unkA8 + temp_r7_3613), f32 *, 0x20) = arg3;
}

#if 0 // DRAFT: illegal use of non-static member
void MKCloth::CreateInternalCollisionPlanes(int arg0) {
    MKHeap *temp_r3_3654;
    MKModel **temp_r5_3674;
    MKModel **var_r3_3661;
    s32 temp_r3_3675;
    s32 var_ctr_3670;
    s32 var_r4_3667;

    temp_r3_3654 = MKHeap::Current();
    if (temp_r3_3654 != NULL) {
        var_r3_3661 = ((MKHeap *) (temp_r3_3654->Current()))->Alloc(arg0 * 0x28, NULL, 0);
    } else {
        var_r3_3661 = malloc(arg0 * 0x28);
    }
    var_r4_3667 = 0;
    this->unkA8 = var_r3_3661;
    var_ctr_3670 = arg0;
    if (arg0 > 0) {
        do {
            temp_r5_3674 = this->unkA8;
            temp_r3_3675 = var_r4_3667 + 0x24;
            var_r4_3667 += 0x28;
            *(temp_r5_3674 + temp_r3_3675) = *(temp_r5_3674 + temp_r3_3675) & ~8;
            var_ctr_3670 -= 1;
        } while (var_ctr_3670 != 0);
    }
    this->unkB0 = arg0;
}
#endif

void MKCloth::SetForce(int arg0, const MKVector3 &arg1, int arg2) {
    s32 temp_r7_3693;
    s32 var_r6_0;
    void *temp_r5_3697;

    var_r6_0 = arg2;
    temp_r7_3693 = arg0 * 0x18;
    temp_r5_3697 = this + temp_r7_3693;
    M2C_FIELD(temp_r5_3697, f64 *, 0x38) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r5_3697, f64 *, 0x40) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    if (var_r6_0 > -1) {

    } else {
        var_r6_0 = arg0 != 0;
    }
    M2C_FIELD((this + temp_r7_3693), s32 *, 0x48) = var_r6_0;
}

void MKCloth::CreateForces(int arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r0_3731;
    s32 var_ctr_3724;
    s32 var_r5_3717;
    s32 var_r6_3715;
    void *temp_r4_3728;

    var_r6_3715 = 0;
    var_r5_3717 = 0;
    this->unk98 = (u32) arg0;
    sp10 = 0.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    var_ctr_3724 = arg0;
    if (arg0 > 0) {
        do {
            temp_r4_3728 = this + var_r5_3717;
            M2C_FIELD(temp_r4_3728, f64 *, 0x38) = (f64) sp8;
            temp_r0_3731 = var_r6_3715 != 0;
            var_r6_3715 += 1;
            var_r5_3717 += 0x18;
            M2C_FIELD(temp_r4_3728, f64 *, 0x40) = (f64) sp10;
            M2C_FIELD(temp_r4_3728, s32 *, 0x48) = temp_r0_3731;
            var_ctr_3724 -= 1;
        } while (var_ctr_3724 != 0);
    }
}

#if 0 // DRAFT: illegal operand
void MKCloth::SetNode(int arg0, const MKVector3 &arg1, float arg2) {
    s32 temp_r6_3745;
    void *temp_r4_3750;
    void *temp_r4_3756;

    temp_r6_3745 = arg0 * 0x38;
    temp_r4_3750 = *this + (temp_r6_3745 + 0x10);
    M2C_FIELD(temp_r4_3750, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(temp_r4_3750, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    temp_r4_3756 = *this + temp_r6_3745;
    M2C_FIELD(temp_r4_3756, f64 *, 0) = (f64) M2C_FIELD(temp_r4_3750, f64 *, 0);
    M2C_FIELD(temp_r4_3756, f64 *, 8) = (f64) M2C_FIELD(temp_r4_3750, f64 *, 8);
    M2C_FIELD((*this + temp_r6_3745), f32 *, 0x30) = arg2;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::ApplyScale(const MKVector3 &arg0) {
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f3_3802;
    f32 var_f6_3809;
    f64 temp_f0_3786;
    f64 temp_f1_3812;
    f64 temp_f1_3818;
    f64 temp_f1_3822;
    s32 temp_r0_3873;
    s32 temp_r6_3841;
    s32 temp_r8_3776;
    s32 var_r0_3851;
    s32 var_r5_3771;
    s8 *temp_r7_3777;
    u32 var_r9_3769;
    void *temp_r6_3783;
    void *temp_r6_3878;
    void *temp_r7_3782;

    var_r9_3769 = 0U;
    var_r5_3771 = 0;
loop_19:
    temp_r6_3878 = M2C_FIELD(this, void **, 4);
    if (var_r9_3769 < (u32) M2C_FIELD(temp_r6_3878, u32 *, 0x10)) {
        temp_r8_3776 = M2C_FIELD(temp_r6_3878, s32 *, 4);
        temp_r7_3777 = &this->unk30[var_r5_3771];
        temp_r7_3782 = temp_r8_3776 + (M2C_FIELD(temp_r7_3777, s32 *, 0) << 5);
        temp_r6_3783 = temp_r8_3776 + (M2C_FIELD(temp_r7_3777, s32 *, 4) << 5);
        temp_f0_3786 = M2C_FIELD(temp_r6_3783, f64 *, 0) - M2C_FIELD(temp_r7_3782, f64 *, 0);
        sp10 = temp_f0_3786;
        sp20 = temp_f0_3786;
        sp18 = M2C_FIELD(temp_r6_3783, f32 *, 8) - M2C_FIELD(temp_r7_3782, f32 *, 8);
        sp28 = (f64) sp18;
        sp20 *= M2C_FIELD(&arg0, f64 *, 0);
        temp_f3_3802 = (f32) sp28 * arg0.unk8;
        sp28 = temp_f3_3802;
        var_f6_3809 = (temp_f3_3802 * temp_f3_3802) + (((f32) sp20 * (f32) sp20) + (unksp24 * unksp24));
        if (var_f6_3809 > 0.0f) {
            temp_f1_3812 = __frsqrte(var_f6_3809);
            temp_f1_3818 = 0.5 * temp_f1_3812 * -(((f64) var_f6_3809 * (temp_f1_3812 * temp_f1_3812)) - 3.0);
            temp_f1_3822 = 0.5 * temp_f1_3818 * -(((f64) var_f6_3809 * (temp_f1_3818 * temp_f1_3818)) - 3.0);
            var_f6_3809 = (f32) ((f64) var_f6_3809 * (0.5 * temp_f1_3822 * -(((f64) var_f6_3809 * (temp_f1_3822 * temp_f1_3822)) - 3.0)));
        } else if (var_f6_3809 < M2C_BITWISE(f32, 0.0)) {
            var_f6_3809 = __float_nan;
        } else {
            sp8 = var_f6_3809;
            temp_r6_3841 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r6_3841) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3851 = 1;
                } else {
                    var_r0_3851 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_3851 = 5;
                } else {
                    var_r0_3851 = 3;
                }
                break;
            default:
                var_r0_3851 = 4;
                break;
            }
            if (var_r0_3851 == 1) {
                var_f6_3809 = __float_nan;
            }
        }
        temp_r0_3873 = var_r5_3771 + 8;
        var_r9_3769 += 1;
        var_r5_3771 += 0xC;
        this->unk30[temp_r0_3873] = var_f6_3809;
        goto loop_19;
    }
    this->unkE0 = M2C_FIELD(&arg0, f64 *, 0);
    this->unkE8 = (f64) M2C_FIELD(&arg0, f32 *, 8);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::Teleport(const Matrix &arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_3921;
    f32 temp_f30_3924;
    f32 temp_f3_3922;
    s32 temp_r0_3917;
    s32 var_r5_3903;
    u32 var_r7_3901;
    void *temp_r4_3946;
    void *temp_r6_3919;

    var_r7_3901 = 0U;
    var_r5_3903 = 0;
loop_2:
    if (var_r7_3901 < (u32) *M2C_FIELD(this, u32 **, 4)) {
        temp_r0_3917 = var_r5_3903 + 0x10;
        var_r7_3901 += 1;
        temp_r6_3919 = M2C_FIELD(this, s32 *, 0) + var_r5_3903;
        var_r5_3903 += 0x38;
        temp_f0_3921 = M2C_FIELD(temp_r6_3919, f32 *, 4);
        temp_f3_3922 = M2C_FIELD(temp_r6_3919, f32 *, 0);
        temp_f30_3924 = M2C_FIELD(temp_r6_3919, f32 *, 8);
        sp8 = arg0.unk30 + ((temp_f30_3924 * arg0.unk20) + ((temp_f3_3922 * arg0.unk0) + (temp_f0_3921 * arg0.unk10)));
        spC = arg0.unk34 + ((temp_f30_3924 * arg0.unk24) + ((temp_f3_3922 * arg0.unk4) + (temp_f0_3921 * arg0.unk14)));
        sp10 = arg0.unk38 + ((temp_f30_3924 * arg0.unk28) + ((temp_f3_3922 * arg0.unk8) + (temp_f0_3921 * arg0.unk18)));
        M2C_FIELD(temp_r6_3919, f32 *, 0) = (f64) sp8;
        M2C_FIELD(temp_r6_3919, f32 *, 8) = (f64) sp10;
        temp_r4_3946 = M2C_FIELD(this, s32 *, 0) + temp_r0_3917;
        sp18 = (f64) sp8;
        M2C_FIELD(temp_r4_3946, f64 *, 0) = (f64) M2C_FIELD(temp_r6_3919, f32 *, 0);
        sp20 = (f64) sp10;
        M2C_FIELD(temp_r4_3946, f64 *, 8) = (f64) M2C_FIELD(temp_r6_3919, f32 *, 8);
        goto loop_2;
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKCloth::Settle(int arg0, Matrix *arg1) {
    MKVector3 sp18;
    MKVector3 sp8;
    MKVector3 *temp_r31_4011;
    Matrix *var_r29_3975;
    f32 temp_f1_4053;
    s32 temp_r29_3985;
    s32 temp_r5_4050;
    s32 var_r26_4000;
    s32 var_r26_4033;
    s32 var_r26_4044;
    s32 var_r30_3999;
    s32 var_r30_4028;
    s32 var_r31_4043;
    s8 temp_r26_3989;
    void *temp_r25_4065;
    void *temp_r3_4021;
    void *temp_r4_4100;
    void *temp_r6_4079;

    var_r29_3975 = arg1;
    if ((var_r29_3975 == NULL) && (MKModel_GetAnimation(this->unkC) != NULL)) {
        temp_r29_3985 = MKModel_GetWorldMatrix(this->unkC);
        temp_r26_3989 = ((Animation *) (MKModel_GetAnimation(this->unkC)))->GetNmbrOfNodes();
        var_r29_3975 = ((Animation *) (MKModel_GetAnimation(this->unkC)))->CalculateMatrices(NULL, (s32) temp_r26_3989, NULL, (Matrix *) temp_r29_3985);
    }
    var_r30_3999 = 0;
    var_r26_4000 = 0;
loop_5:
    temp_r3_4021 = M2C_FIELD(this, void **, 4);
    if (var_r30_3999 < (s32) M2C_FIELD(temp_r3_4021, s32 *, 8)) {
        temp_r31_4011 = M2C_FIELD(this, s32 *, 0) + (*(M2C_FIELD(temp_r3_4021, s32 *, 0xC) + (var_r26_4000 + 0x20)) * 0x38);
        GetWorldPos(*temp_r31_4011, var_r30_3999, var_r29_3975);
        var_r30_3999 += 1;
        var_r26_4000 += 0x40;
        M2C_FIELD(temp_r31_4011, f64 *, 0x10) = (f64) M2C_FIELD(temp_r31_4011, f64 *, 0);
        M2C_FIELD(temp_r31_4011, f64 *, 0x18) = (f64) M2C_FIELD(temp_r31_4011, f64 *, 8);
        goto loop_5;
    }
    UpdateCollisionPrims();
    var_r30_4028 = 0;
loop_17:
    if (var_r30_4028 < arg0) {
        UpdatePosition();
        var_r26_4033 = 0;
loop_9:
        if (var_r26_4033 < (s32) this->unkD8) {
            SatisfyConstraints();
            var_r26_4033 += 1;
            goto loop_9;
        }
        var_r31_4043 = 0;
        var_r26_4044 = 0;
loop_15:
        temp_r4_4100 = M2C_FIELD(this, void **, 4);
        if (var_r31_4043 < (s32) M2C_FIELD(temp_r4_4100, s32 *, 8)) {
            temp_r5_4050 = *(M2C_FIELD(temp_r4_4100, s32 *, 0xC) + (var_r26_4044 + 0x20));
            temp_f1_4053 = *(M2C_FIELD(temp_r4_4100, s32 *, 4) + ((temp_r5_4050 << 5) + 0x14));
            if ((temp_f1_4053 != 0.0f) && (temp_f1_4053 < 1.0f)) {
                temp_r25_4065 = M2C_FIELD(this, s32 *, 0) + (temp_r5_4050 * 0x38);
                GetWorldPos(sp18, var_r31_4043, var_r29_3975);
                sp18 = M2C_BITWISE(f64, sp18) - M2C_FIELD(temp_r25_4065, f64 *, 0);
                sp18.unk8 -= M2C_FIELD(temp_r25_4065, f32 *, 8);
                temp_r6_4079 = M2C_FIELD(this, void **, 4);
                __ml(1.0f - *(M2C_FIELD(temp_r6_4079, s32 *, 4) + ((*(M2C_FIELD(temp_r6_4079, s32 *, 0xC) + (var_r26_4044 + 0x20)) << 5) + 0x14)), sp8);
                M2C_FIELD(temp_r25_4065, f64 *, 0) = (f64) (M2C_FIELD(temp_r25_4065, f64 *, 0) + M2C_BITWISE(f64, sp8));
                M2C_FIELD(temp_r25_4065, f32 *, 8) = (f32) (M2C_FIELD(temp_r25_4065, f32 *, 8) + sp8.unk8);
            }
            var_r31_4043 += 1;
            var_r26_4044 += 0x40;
            goto loop_15;
        }
        var_r30_4028 += 1;
        goto loop_17;
    }
    LightCloth();
}
#endif

#if 0 // DRAFT: pointer/array required
void MKCloth::Reset() {
    MKVector3 *temp_r28_4160;
    Matrix *var_r30_4127;
    s32 temp_r30_4134;
    s32 var_r29_4148;
    s32 var_r31_4149;
    s8 temp_r31_4138;
    void *temp_r3_4170;

    var_r30_4127 = NULL;
    if (MKModel_GetAnimation(this->unkC) != NULL) {
        temp_r30_4134 = MKModel_GetWorldMatrix(this->unkC);
        temp_r31_4138 = ((Animation *) (MKModel_GetAnimation(this->unkC)))->GetNmbrOfNodes();
        var_r30_4127 = ((Animation *) (MKModel_GetAnimation(this->unkC)))->CalculateMatrices(NULL, (s32) temp_r31_4138, NULL, (Matrix *) temp_r30_4134);
    }
    var_r29_4148 = 0;
    var_r31_4149 = 0;
loop_4:
    temp_r3_4170 = M2C_FIELD(this, void **, 4);
    if (var_r29_4148 < (s32) M2C_FIELD(temp_r3_4170, s32 *, 8)) {
        temp_r28_4160 = M2C_FIELD(this, s32 *, 0) + (*(M2C_FIELD(temp_r3_4170, s32 *, 0xC) + (var_r31_4149 + 0x20)) * 0x38);
        GetWorldPos(*temp_r28_4160, var_r29_4148, var_r30_4127);
        var_r29_4148 += 1;
        var_r31_4149 += 0x40;
        M2C_FIELD(temp_r28_4160, f64 *, 0x10) = (f64) M2C_FIELD(temp_r28_4160, f64 *, 0);
        M2C_FIELD(temp_r28_4160, f64 *, 0x18) = (f64) M2C_FIELD(temp_r28_4160, f64 *, 8);
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::GetWorldBindPos(int arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f6_4200;
    f32 temp_f6_4209;
    f32 temp_f7_4201;
    void *temp_r3_4192;
    void *temp_r4_4198;

    temp_r3_4192 = MKModel_GetWorldMatrix(M2C_FIELD(arg0, MKModel **, 0xC));
    temp_r4_4198 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) + (M2C_ERROR(/* Read from unset register $r5 */) << 5);
    temp_f6_4200 = M2C_FIELD(temp_r4_4198, f32 *, 4);
    temp_f7_4201 = M2C_FIELD(temp_r4_4198, f32 *, 0);
    temp_f6_4209 = M2C_FIELD(temp_r4_4198, f32 *, 8);
    sp8 = M2C_FIELD(temp_r3_4192, f32 *, 0x30) + ((temp_f6_4209 * M2C_FIELD(temp_r3_4192, f32 *, 0x20)) + ((temp_f7_4201 * M2C_FIELD(temp_r3_4192, f32 *, 0)) + (temp_f6_4200 * M2C_FIELD(temp_r3_4192, f32 *, 0x10))));
    spC = M2C_FIELD(temp_r3_4192, f32 *, 0x34) + ((temp_f6_4209 * M2C_FIELD(temp_r3_4192, f32 *, 0x24)) + ((temp_f7_4201 * M2C_FIELD(temp_r3_4192, f32 *, 4)) + (temp_f6_4200 * M2C_FIELD(temp_r3_4192, f32 *, 0x14))));
    sp10 = M2C_FIELD(temp_r3_4192, f32 *, 0x38) + ((temp_f6_4209 * M2C_FIELD(temp_r3_4192, f32 *, 0x28)) + ((temp_f7_4201 * M2C_FIELD(temp_r3_4192, f32 *, 8)) + (temp_f6_4200 * M2C_FIELD(temp_r3_4192, f32 *, 0x18))));
    this->unk0 = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
f64 MKCloth::GetWorldPos(MKVector3 &arg0, int arg1, Matrix *arg2) {
    f32 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;
    Animation *temp_r3_4266;
    Matrix *temp_r5_4319;
    Matrix *var_r3_4277;
    f32 temp_f24_4318;
    f32 temp_f28_4297;
    f64 temp_f2_4320;
    f64 temp_f3_4298;
    f64 var_f1_4303;
    s32 temp_r0_4273;
    s32 temp_r0_4314;
    s32 temp_r5_4284;
    void *temp_r28_4289;
    void *temp_r4_4283;
    void *temp_r6_4295;

    temp_r3_4266 = MKModel_GetAnimation(this->unkC);
    if ((temp_r3_4266 != NULL) && (temp_r0_4273 = M2C_FIELD((M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0xC) + (arg1 << 6)), s32 *, 0x30), ((temp_r0_4273 > -1) != 0))) {
        var_r3_4277 = &arg2[temp_r0_4273];
    } else {
        var_r3_4277 = MKModel_GetWorldMatrix(this->unkC);
    }
    temp_r4_4283 = M2C_FIELD(this, void **, 4);
    temp_r5_4284 = arg1 << 6;
    temp_r28_4289 = M2C_FIELD(temp_r4_4283, s32 *, 0xC) + temp_r5_4284;
    temp_r6_4295 = M2C_FIELD(temp_r4_4283, s32 *, 4) + (M2C_FIELD(temp_r28_4289, s32 *, 0x20) << 5);
    temp_f28_4297 = M2C_FIELD(temp_r6_4295, f32 *, 8);
    temp_f3_4298 = M2C_FIELD(temp_r6_4295, f64 *, 0);
    var_f1_4303 = M2C_FIELD(var_r3_4277, f64 *, 0);
    arg0.unk8 = (f32) (((f64) var_r3_4277->unk8 * temp_f3_4298) + (((f64) var_r3_4277->unk18 * temp_f3_4298) + (((f64) var_r3_4277->unk28 * (f64) temp_f28_4297) + (f64) var_r3_4277->unk38)));
    M2C_FIELD(&arg0, f64 *, 0) = (f64) ((var_f1_4303 * temp_f3_4298) + ((M2C_FIELD(var_r3_4277, f64 *, 0x10) * temp_f3_4298) + ((M2C_FIELD(var_r3_4277, f64 *, 0x20) * (f64) temp_f28_4297) + M2C_FIELD(var_r3_4277, f64 *, 0x30))));
    if (temp_r3_4266 != NULL) {
        temp_r0_4314 = M2C_FIELD((M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0xC) + temp_r5_4284), s32 *, 0x34);
        if (temp_r0_4314 > -1) {
            temp_f24_4318 = M2C_FIELD(temp_r6_4295, f32 *, 8);
            temp_r5_4319 = &arg2[temp_r0_4314];
            temp_f2_4320 = M2C_FIELD(temp_r6_4295, f64 *, 0);
            sp50 = (f32) (((f64) temp_r5_4319->unk8 * temp_f2_4320) + (((f64) temp_r5_4319->unk18 * temp_f2_4320) + (((f64) temp_r5_4319->unk28 * (f64) temp_f24_4318) + (f64) temp_r5_4319->unk38)));
            sp48 = (M2C_FIELD(temp_r5_4319, f64 *, 0) * temp_f2_4320) + ((M2C_FIELD(temp_r5_4319, f64 *, 0x10) * temp_f2_4320) + ((M2C_FIELD(temp_r5_4319, f64 *, 0x20) * (f64) temp_f24_4318) + M2C_FIELD(temp_r5_4319, f64 *, 0x30)));
            sp18.operator*(M2C_FIELD(temp_r28_4289, f32 *, 0x3C));
            sp28.operator*(M2C_FIELD(temp_r28_4289, f32 *, 0x38));
            sp8 = sp28 + M2C_BITWISE(f64, sp18);
            var_f1_4303 = sp8;
            M2C_FIELD(&arg0, f64 *, 0) = var_f1_4303;
            sp10 = sp28.unk8 + sp18.unk8;
            sp38 = var_f1_4303;
            sp40 = (f64) sp10;
            M2C_FIELD(&arg0, f32 *, 8) = (f64) sp10;
        }
    }
    return var_f1_4303;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::UpdateInternal(Matrix *arg0) {
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_4398;
    f32 temp_f1_4397;
    f32 temp_f1_4471;
    f32 temp_f1_4543;
    f32 temp_f1_4696;
    f32 temp_f2_4470;
    f32 temp_f2_4542;
    f32 temp_f3_4400;
    f32 temp_f3_4473;
    f32 temp_f3_4545;
    f32 var_f4_4405;
    f32 var_f4_4477;
    f32 var_f4_4549;
    f64 temp_f1_4408;
    f64 temp_f1_4414;
    f64 temp_f1_4418;
    f64 temp_f1_4480;
    f64 temp_f1_4486;
    f64 temp_f1_4490;
    f64 temp_f1_4552;
    f64 temp_f1_4558;
    f64 temp_f1_4562;
    s32 temp_r3_4581;
    s32 temp_r3_4711;
    s32 temp_r4_4437;
    s32 temp_r4_4509;
    s32 temp_r5_4650;
    s32 var_r0_4447;
    s32 var_r0_4519;
    s32 var_r0_4591;
    s32 var_r28_4644;
    s32 var_r28_4675;
    s32 var_r28_4687;
    s32 var_r31_4643;
    s32 var_r31_4686;
    void *temp_r3_4396;
    void *temp_r3_4737;
    void *temp_r4_4667;
    void *temp_r4_4713;
    void *temp_r4_4750;
    void *temp_r5_4707;

    temp_r3_4396 = MKModel_GetWorldMatrix(this->unkC);
    temp_f1_4397 = M2C_FIELD(temp_r3_4396, f32 *, 0);
    temp_f0_4398 = M2C_FIELD(temp_r3_4396, f32 *, 4);
    temp_f3_4400 = M2C_FIELD(temp_r3_4396, f32 *, 8);
    var_f4_4405 = (temp_f3_4400 * temp_f3_4400) + ((temp_f1_4397 * temp_f1_4397) + (temp_f0_4398 * temp_f0_4398));
    if (var_f4_4405 > 0.0f) {
        temp_f1_4408 = __frsqrte(var_f4_4405);
        temp_f1_4414 = 0.5 * temp_f1_4408 * -(((f64) var_f4_4405 * (temp_f1_4408 * temp_f1_4408)) - 3.0);
        temp_f1_4418 = 0.5 * temp_f1_4414 * -(((f64) var_f4_4405 * (temp_f1_4414 * temp_f1_4414)) - 3.0);
        var_f4_4405 = (f32) ((f64) var_f4_4405 * (0.5 * temp_f1_4418 * -(((f64) var_f4_4405 * (temp_f1_4418 * temp_f1_4418)) - 3.0)));
    } else if (var_f4_4405 < M2C_BITWISE(f32, 0.0)) {
        var_f4_4405 = __float_nan;
    } else {
        sp10 = var_f4_4405;
        temp_r4_4437 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r4_4437) {                     /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_4447 = 1;
            } else {
                var_r0_4447 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_4447 = 5;
            } else {
                var_r0_4447 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_4447 = 4;
            break;
        }
        if (var_r0_4447 == 1) {
            var_f4_4405 = __float_nan;
        }
    }
    sp68 = var_f4_4405;
    temp_f2_4470 = M2C_FIELD(temp_r3_4396, f32 *, 0x10);
    temp_f1_4471 = M2C_FIELD(temp_r3_4396, f32 *, 0x14);
    temp_f3_4473 = M2C_FIELD(temp_r3_4396, f32 *, 0x18);
    var_f4_4477 = (temp_f3_4473 * temp_f3_4473) + ((temp_f2_4470 * temp_f2_4470) + (temp_f1_4471 * temp_f1_4471));
    if (var_f4_4477 > 0.0f) {
        temp_f1_4480 = __frsqrte(var_f4_4477);
        temp_f1_4486 = 0.5 * temp_f1_4480 * -(((f64) var_f4_4477 * (temp_f1_4480 * temp_f1_4480)) - 3.0);
        temp_f1_4490 = 0.5 * temp_f1_4486 * -(((f64) var_f4_4477 * (temp_f1_4486 * temp_f1_4486)) - 3.0);
        var_f4_4477 = (f32) ((f64) var_f4_4477 * (0.5 * temp_f1_4490 * -(((f64) var_f4_4477 * (temp_f1_4490 * temp_f1_4490)) - 3.0)));
    } else if (var_f4_4477 < M2C_BITWISE(f32, 0.0)) {
        var_f4_4477 = __float_nan;
    } else {
        spC = var_f4_4477;
        temp_r4_4509 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r4_4509) {                     /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_4519 = 1;
            } else {
                var_r0_4519 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_4519 = 5;
            } else {
                var_r0_4519 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_4519 = 4;
            break;
        }
        if (var_r0_4519 == 1) {
            var_f4_4477 = __float_nan;
        }
    }
    sp6C = var_f4_4477;
    temp_f2_4542 = M2C_FIELD(temp_r3_4396, f32 *, 0x20);
    temp_f1_4543 = M2C_FIELD(temp_r3_4396, f32 *, 0x24);
    temp_f3_4545 = M2C_FIELD(temp_r3_4396, f32 *, 0x28);
    var_f4_4549 = (temp_f3_4545 * temp_f3_4545) + ((temp_f2_4542 * temp_f2_4542) + (temp_f1_4543 * temp_f1_4543));
    if (var_f4_4549 > 0.0f) {
        temp_f1_4552 = __frsqrte(var_f4_4549);
        temp_f1_4558 = 0.5 * temp_f1_4552 * -(((f64) var_f4_4549 * (temp_f1_4552 * temp_f1_4552)) - 3.0);
        temp_f1_4562 = 0.5 * temp_f1_4558 * -(((f64) var_f4_4549 * (temp_f1_4558 * temp_f1_4558)) - 3.0);
        var_f4_4549 = (f32) ((f64) var_f4_4549 * (0.5 * temp_f1_4562 * -(((f64) var_f4_4549 * (temp_f1_4562 * temp_f1_4562)) - 3.0)));
    } else if (var_f4_4549 < M2C_BITWISE(f32, 0.0)) {
        var_f4_4549 = __float_nan;
    } else {
        sp8 = var_f4_4549;
        temp_r3_4581 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_4581) {                     /* switch 3; irregular */
        case 0x7F800000:                            /* switch 3 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_4591 = 1;
            } else {
                var_r0_4591 = 2;
            }
            break;
        case 0x0:                                   /* switch 3 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_4591 = 5;
            } else {
                var_r0_4591 = 3;
            }
            break;
        default:                                    /* switch 3 */
            var_r0_4591 = 4;
            break;
        }
        if (var_r0_4591 == 1) {
            var_f4_4549 = __float_nan;
        }
    }
    sp70 = var_f4_4549;
    sp18 = (f64) sp68 - this->unkE0;
    sp28 = sp18;
    sp20 = (f32) var_f4_4549 - M2C_FIELD(this, f32 *, 0xE8);
    sp30 = (f64) sp20;
    sp38 = sp18;
    sp40 = (f64) sp20;
    if (!((((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + (unksp2C * unksp2C))) < 0.0001f)) {
        ApplyScale(*((MKVector3 *) &sp68));
    }
    var_r31_4643 = 0;
    var_r28_4644 = 0;
loop_57:
    temp_r4_4667 = M2C_FIELD(this, void **, 4);
    if (var_r31_4643 < (s32) M2C_FIELD(temp_r4_4667, s32 *, 8)) {
        temp_r5_4650 = *(M2C_FIELD(temp_r4_4667, s32 *, 0xC) + (var_r28_4644 + 0x20));
        if (*(M2C_FIELD(temp_r4_4667, s32 *, 4) + ((temp_r5_4650 << 5) + 0x10)) == 0.0f) {
            GetWorldPos(*(M2C_FIELD(this, s32 *, 0) + (temp_r5_4650 * 0x38)), var_r31_4643, arg0);
        }
        var_r31_4643 += 1;
        var_r28_4644 += 0x40;
        goto loop_57;
    }
    UpdateCollisionPrims();
    UpdatePosition();
    var_r28_4675 = 0;
loop_60:
    if (var_r28_4675 < (s32) this->unkD8) {
        SatisfyConstraints();
        var_r28_4675 += 1;
        goto loop_60;
    }
    var_r31_4686 = 0;
    var_r28_4687 = 0;
loop_66:
    temp_r4_4750 = M2C_FIELD(this, void **, 4);
    if (var_r31_4686 < (s32) M2C_FIELD(temp_r4_4750, s32 *, 8)) {
        temp_f1_4696 = *(M2C_FIELD(temp_r4_4750, s32 *, 4) + ((*(M2C_FIELD(temp_r4_4750, s32 *, 0xC) + (var_r28_4687 + 0x20)) << 5) + 0x14));
        if ((temp_f1_4696 != 0.0f) && (temp_f1_4696 < 1.0f)) {
            GetWorldPos(sp58, var_r31_4686, arg0);
            temp_r5_4707 = M2C_FIELD(this, void **, 4);
            temp_r3_4711 = *(M2C_FIELD(temp_r5_4707, s32 *, 0xC) + (var_r28_4687 + 0x20));
            temp_r4_4713 = M2C_FIELD(this, s32 *, 0) + (temp_r3_4711 * 0x38);
            sp58 = M2C_BITWISE(f64, sp58) - M2C_FIELD(temp_r4_4713, f64 *, 0);
            sp58.unk8 -= M2C_FIELD(temp_r4_4713, f32 *, 8);
            __ml(1.0f - *(M2C_FIELD(temp_r5_4707, s32 *, 4) + ((temp_r3_4711 << 5) + 0x14)), sp48);
            temp_r3_4737 = M2C_FIELD(this, s32 *, 0) + (*(M2C_FIELD(M2C_FIELD(this, void **, 4), s32 *, 0xC) + (var_r28_4687 + 0x20)) * 0x38);
            M2C_FIELD(temp_r3_4737, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_4737, f64 *, 0) + M2C_BITWISE(f64, sp48));
            M2C_FIELD(temp_r3_4737, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_4737, f32 *, 8) + sp48.unk8);
        }
        var_r31_4686 += 1;
        var_r28_4687 += 0x40;
        goto loop_66;
    }
    LightCloth();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCloth::UpdateCollisionPrims() {
    MKVector3 spB0;
    M2C_UNK spA0;
    Matrix sp60;
    MKVector3 sp48;
    MKVector3 sp38;
    MKVector3 sp28;
    f64 sp20;                                       /* compiler-managed */
    f64 sp18;                                       /* compiler-managed */
    f32 sp14;
    f32 sp10;
    f32 temp_f0_4851;
    f32 temp_f1_4850;
    f32 temp_f30_4791;
    f32 var_f3_5048;
    f32 var_f4_4854;
    f32 var_f4_4981;
    f64 temp_f1_4857;
    f64 temp_f1_4863;
    f64 temp_f1_4867;
    f64 temp_f1_4987;
    f64 temp_f1_4993;
    f64 temp_f1_4997;
    s32 temp_r31_4959;
    s32 temp_r3_4886;
    s32 temp_r3_5016;
    s32 var_r0_4896;
    s32 var_r0_5026;
    s32 var_r27_4786;
    s32 var_r27_4842;
    s32 var_r27_4951;
    s32 var_r28_4788;
    s32 var_r28_4843;
    s32 var_r28_4950;
    s32 var_r30_4784;
    s32 var_r30_4841;
    s32 var_r30_4949;
    void *temp_r3_4849;

    var_r30_4784 = 0;
    var_r27_4786 = 0;
    var_r28_4788 = 0;
    temp_f30_4791 = 0.33333334f * (M2C_FIELD(this, f32 *, 0xE8) + (M2C_FIELD(this, f32 *, 0xE0) + M2C_FIELD(this, f32 *, 0xE4)));
loop_7:
    if (var_r30_4784 < (s32) this->unkBC) {
        MKModel_CalculateRefPointWorldPosition(this->unkC, this->unkB8[var_r28_4788], &sp48);
        if (MKModel_GetRefPointType(this->unkC, this->unkB8[var_r28_4788]) == 1) {
            sp48.unkC = M2C_FIELD(MKModel_GetRefPointData(this->unkC, this->unkB8[var_r28_4788]), f32 *, 0x60);
        } else {
            sp48.unkC = MKModel_GetRefPointRadius(this->unkC, this->unkB8[var_r28_4788]);
        }
        sp48.unkC *= temp_f30_4791;
        if (!(((u8) *(this->unkB4 + (var_r27_4786 + 0x10)) >> 3U) & 1)) {
            SetInternalCollisionSphere(var_r30_4784, *((MKVector4 *) &sp48));
        }
        var_r30_4784 += 1;
        var_r27_4786 += 0x18;
        var_r28_4788 += 4;
        goto loop_7;
    }
    var_r30_4841 = 0;
    var_r27_4842 = 0;
    var_r28_4843 = 0;
loop_29:
    if (var_r30_4841 < (s32) this->unkB0) {
        temp_r3_4849 = MKModel_GetRefPointData(this->unkC, this->unkAC[var_r28_4843]);
        temp_f1_4850 = M2C_FIELD(temp_r3_4849, f32 *, 0x60);
        temp_f0_4851 = M2C_FIELD(temp_r3_4849, f32 *, 0x64);
        var_f4_4854 = (temp_f1_4850 * temp_f1_4850) + (temp_f0_4851 * temp_f0_4851);
        if (var_f4_4854 > 0.0f) {
            temp_f1_4857 = __frsqrte(var_f4_4854);
            temp_f1_4863 = 0.5 * temp_f1_4857 * -(((f64) var_f4_4854 * (temp_f1_4857 * temp_f1_4857)) - 3.0);
            temp_f1_4867 = 0.5 * temp_f1_4863 * -(((f64) var_f4_4854 * (temp_f1_4863 * temp_f1_4863)) - 3.0);
            var_f4_4854 = (f32) ((f64) var_f4_4854 * (0.5 * temp_f1_4867 * -(((f64) var_f4_4854 * (temp_f1_4867 * temp_f1_4867)) - 3.0)));
        } else if (var_f4_4854 < M2C_BITWISE(f32, 0.0)) {
            var_f4_4854 = __float_nan;
        } else {
            sp14 = var_f4_4854;
            temp_r3_4886 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_4886) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_4896 = 1;
                } else {
                    var_r0_4896 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_4896 = 5;
                } else {
                    var_r0_4896 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_4896 = 4;
                break;
            }
            if (var_r0_4896 == 1) {
                var_f4_4854 = __float_nan;
            }
        }
        MKModel_GetRefPointMatrix(this->unkC, this->unkAC[var_r28_4843], (Matrix *) &spA0, 1U);
        MKModel_CalculateRefPointWorldPosition(this->unkC, this->unkAC[var_r28_4843], &sp38);
        if (!(((u8) *(this->unkA8 + (var_r27_4842 + 0x24)) >> 3U) & 1)) {
            SetInternalCollisionPlane(var_r30_4841, sp38, spB0, var_f4_4854 * temp_f30_4791);
        }
        var_r30_4841 += 1;
        var_r27_4842 += 0x28;
        var_r28_4843 += 4;
        goto loop_29;
    }
    var_r30_4949 = 0;
    var_r28_4950 = 0;
    var_r27_4951 = 0;
loop_54:
    if (var_r30_4949 < (s32) this->unkC8) {
        temp_r31_4959 = MKModel_GetRefPointData(this->unkC, this->unkC4[var_r27_4951]);
        MKModel_GetRefPointMatrix(this->unkC, this->unkC4[var_r27_4951], &sp60, 1U);
        MKModel_CalculateRefPointWorldPosition(this->unkC, this->unkC4[var_r27_4951], &sp28);
        sp18 = (f64) sp60.unk10;
        sp20 = (f64) sp60.unk18;
        var_f4_4981 = ((f32) sp20 * (f32) sp20) + (((f32) sp18 * (f32) sp18) + (unksp1C * unksp1C));
        if (var_f4_4981 > 0.000001f) {
            if (var_f4_4981 > 0.0f) {
                temp_f1_4987 = __frsqrte(var_f4_4981);
                temp_f1_4993 = 0.5 * temp_f1_4987 * -(((f64) var_f4_4981 * (temp_f1_4987 * temp_f1_4987)) - 3.0);
                temp_f1_4997 = 0.5 * temp_f1_4993 * -(((f64) var_f4_4981 * (temp_f1_4993 * temp_f1_4993)) - 3.0);
                var_f4_4981 = (f32) ((f64) var_f4_4981 * (0.5 * temp_f1_4997 * -(((f64) var_f4_4981 * (temp_f1_4997 * temp_f1_4997)) - 3.0)));
            } else if (var_f4_4981 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4981 = __float_nan;
            } else {
                sp10 = var_f4_4981;
                temp_r3_5016 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_5016) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_5026 = 1;
                    } else {
                        var_r0_5026 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_5026 = 5;
                    } else {
                        var_r0_5026 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_5026 = 4;
                    break;
                }
                if (var_r0_5026 == 1) {
                    var_f4_4981 = __float_nan;
                }
            }
            var_f3_5048 = 1.0f / var_f4_4981;
        } else {
            var_f3_5048 = 0.0f;
        }
        sp18 = (f32) sp18 * var_f3_5048;
        unksp1C *= var_f3_5048;
        sp20 = (f32) sp20 * var_f3_5048;
        if (!(((u8) *(this->unkC0 + (var_r28_4950 + 0x4C)) >> 3U) & 1)) {
            SetInternalCollisionCapsule(var_r30_4949, sp28, *((MKVector3 *) &sp18), M2C_FIELD(temp_r31_4959, f32 *, 0x60) * temp_f30_4791, M2C_FIELD(temp_r31_4959, f32 *, 0x64) * temp_f30_4791);
        }
        var_r30_4949 += 1;
        var_r28_4950 += 0x50;
        var_r27_4951 += 4;
        goto loop_54;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKMaterial *' to
void MKCloth::Draw() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp10;
    MKMaterial *temp_r23_5114;
    s32 var_r23_5192;
    s32 var_r24_5181;
    u32 var_r26_5191;
    u32 var_r27_5180;
    void *temp_r3_5266;
    void *temp_r4_5206;
    void *temp_r4_5219;
    void *temp_r4_5229;
    void *temp_r4_5246;
    void *temp_r4_5256;
    void *temp_r5_5211;
    void *temp_r5_5223;
    void *temp_r5_5235;
    void *temp_r5_5254;

    if (!(this->unkF0 & 0xF)) {
        temp_r23_5114 = *M2C_FIELD(M2C_FIELD(this, void **, 4), MKMaterial ***, 0x1C);
        if ((temp_r23_5114 != NULL) && (MKMaterial_GetParameter(temp_r23_5114, (MKMaterialParameter) 6) == 0)) {
            sp10 = 1;
            MKMaterial_SetGeometryTransformInfo((GeometryTransformationInfo *) &sp10);
            MKMaterial_SetLocalToWorld(NULL, 1.0f);
            sp40 = M2C_FIELD(this, f64 *, 0x10);
            sp48 = M2C_FIELD(this, f64 *, 0x18);
            sp18 = M2C_FIELD(this, f64 *, 0x20) - M2C_FIELD(this, f64 *, 0x10);
            sp28 = sp18;
            sp20 = this->unk28 - this->unk18;
            sp50 = sp18;
            sp30 = (f64) sp20;
            sp58 = (f64) sp20;
            MKMaterial_SetLocalities(NULL, (BoundingVolume *) &sp40, 1, 0);
            MKMaterial_UseLocality(0);
            MKMaterial_SetMaterial(temp_r23_5114);
loop_13:
            if (MKMaterial_Begin() != 0) {
                MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 1);
                MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 0);
                MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 3);
                MKMaterial_GetVertexComponentHandleFromType((VERTEX_COMPONENT) 2);
loop_12:
                if (MKMaterial_BeginInternal() != 0) {
                    MKMaterial_RenderImmediateBegin(4U, 0U);
                    var_r27_5180 = 0U;
                    var_r24_5181 = 0;
loop_10:
                    temp_r3_5266 = M2C_FIELD(this, void **, 4);
                    if (var_r27_5180 < (u32) M2C_FIELD(temp_r3_5266, u32 *, 0x18)) {
                        MKMaterial_RenderVerticesBegin((s32) *(M2C_FIELD(temp_r3_5266, MKMaterial ***, 0x1C) + (var_r24_5181 + 8)));
                        var_r26_5191 = *(M2C_FIELD(M2C_FIELD(this, void **, 4), MKMaterial ***, 0x1C) + (var_r24_5181 + 0xC));
                        var_r23_5192 = var_r26_5191 * 4;
loop_8:
                        temp_r5_5254 = M2C_FIELD(this, void **, 4);
                        temp_r4_5256 = var_r24_5181 + M2C_FIELD(temp_r5_5254, MKMaterial ***, 0x1C);
                        if (var_r26_5191 < (u32) (M2C_FIELD(temp_r4_5256, s32 *, 0xC) + M2C_FIELD(temp_r4_5256, s16 *, 8))) {
                            temp_r4_5206 = M2C_FIELD(this, s32 *, 0) + ((*(M2C_FIELD(temp_r5_5254, s32 *, 0xC) + ((*(M2C_FIELD(temp_r5_5254, s32 *, 0x24) + var_r23_5192) << 6) + 0x20)) * 0x38) + 0x20);
                            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r4_5206, f32 *, 0), M2C_FIELD(temp_r4_5206, f32 *, 4), M2C_FIELD(temp_r4_5206, f32 *, 8), 1.0f);
                            temp_r5_5211 = M2C_FIELD(this, void **, 4);
                            temp_r4_5219 = M2C_FIELD(temp_r5_5211, s32 *, 0xC) + (*(M2C_FIELD(temp_r5_5211, s32 *, 0x24) + var_r23_5192) << 6);
                            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r4_5219, f32 *, 0x28), M2C_FIELD(temp_r4_5219, f32 *, 0x2C), 0.0f, 1.0f);
                            temp_r5_5223 = M2C_FIELD(this, void **, 4);
                            temp_r4_5229 = M2C_FIELD(temp_r5_5223, s32 *, 0xC) + (*(M2C_FIELD(temp_r5_5223, s32 *, 0x24) + var_r23_5192) << 6);
                            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r4_5229, f32 *, 0), M2C_FIELD(temp_r4_5229, f32 *, 4), M2C_FIELD(temp_r4_5229, f32 *, 8), M2C_FIELD(temp_r4_5229, f32 *, 0xC));
                            temp_r5_5235 = M2C_FIELD(this, void **, 4);
                            temp_r4_5246 = M2C_FIELD(this, s32 *, 0) + (*(M2C_FIELD(temp_r5_5235, s32 *, 0xC) + ((*(M2C_FIELD(temp_r5_5235, s32 *, 0x24) + var_r23_5192) << 6) + 0x20)) * 0x38);
                            MKMaterial_SetVertex4F(M2C_ERROR(/* Read from unset register $r3 */), M2C_FIELD(temp_r4_5246, f32 *, 0), M2C_FIELD(temp_r4_5246, f32 *, 4), M2C_FIELD(temp_r4_5246, f32 *, 8), 1.0f);
                            var_r26_5191 += 1;
                            var_r23_5192 += 4;
                            goto loop_8;
                        }
                        MKMaterial_RenderVerticesEnd();
                        var_r27_5180 += 1;
                        var_r24_5181 += 0x10;
                        goto loop_10;
                    }
                    MKMaterial_RenderImmediateEnd();
                    goto loop_12;
                }
                goto loop_13;
            }
            MKMaterial_SetMaterial(NULL);
            MKMaterial_SetLocalities(NULL, NULL, 1, 0);
            DrawConstraints();
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void MKCloth::Deinit() {
    MKHeap *temp_r3_5308;
    MKHeap *temp_r3_5324;
    MKHeap *temp_r3_5340;
    MKHeap *temp_r3_5356;
    MKHeap *temp_r3_5372;
    MKHeap *temp_r3_5388;
    MKHeap *temp_r3_5404;
    MKHeap *temp_r3_5420;
    MKModel **temp_r31_5337;
    MKModel **temp_r31_5353;
    MKModel **temp_r31_5369;
    s8 *temp_r31_5305;
    s8 *temp_r31_5321;
    s8 *temp_r31_5385;
    s8 *temp_r31_5401;
    s8 *temp_r31_5417;

    temp_r31_5305 = M2C_FIELD(this, s8 **, 0);
    if (temp_r31_5305 != NULL) {
        temp_r3_5308 = MKHeap::Current();
        if (temp_r3_5308 != NULL) {
            ((MKHeap *) (temp_r3_5308->Current()))->Free(temp_r31_5305, NULL, 0);
        } else {
            free(temp_r31_5305);
        }
    }
    temp_r31_5321 = this->unk30;
    if (temp_r31_5321 != NULL) {
        temp_r3_5324 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5324 != NULL) {
            ((MKHeap *) (temp_r3_5324->Current()))->Free(temp_r31_5321, NULL, 0);
        } else {
            free(temp_r31_5321);
        }
    }
    temp_r31_5337 = this->unkA8;
    if (temp_r31_5337 != NULL) {
        temp_r3_5340 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5340 != NULL) {
            ((MKHeap *) (temp_r3_5340->Current()))->Free(temp_r31_5337, NULL, 0);
        } else {
            free((s8 *) temp_r31_5337);
        }
    }
    temp_r31_5353 = this->unkB4;
    if (temp_r31_5353 != NULL) {
        temp_r3_5356 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5356 != NULL) {
            ((MKHeap *) (temp_r3_5356->Current()))->Free(temp_r31_5353, NULL, 0);
        } else {
            free((s8 *) temp_r31_5353);
        }
    }
    temp_r31_5369 = this->unkC0;
    if (temp_r31_5369 != NULL) {
        temp_r3_5372 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5372 != NULL) {
            ((MKHeap *) (temp_r3_5372->Current()))->Free(temp_r31_5369, NULL, 0);
        } else {
            free((s8 *) temp_r31_5369);
        }
    }
    temp_r31_5385 = this->unkB8;
    if (temp_r31_5385 != NULL) {
        temp_r3_5388 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5388 != NULL) {
            ((MKHeap *) (temp_r3_5388->Current()))->Free(temp_r31_5385, NULL, 0);
        } else {
            free(temp_r31_5385);
        }
    }
    temp_r31_5401 = this->unkAC;
    if (temp_r31_5401 != NULL) {
        temp_r3_5404 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5404 != NULL) {
            ((MKHeap *) (temp_r3_5404->Current()))->Free(temp_r31_5401, NULL, 0);
        } else {
            free(temp_r31_5401);
        }
    }
    temp_r31_5417 = this->unkC4;
    if (temp_r31_5417 != NULL) {
        temp_r3_5420 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5420 != NULL) {
            ((MKHeap *) (temp_r3_5420->Current()))->Free(temp_r31_5417, NULL, 0);
            return;
        }
        free(temp_r31_5417);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void MKCloth::Create() {
    M2C_UNK sp8;
    f64 temp_f30_5455;
    f64 temp_f31_5457;
    s32 temp_r0_5473;
    s32 var_r28_5454;
    s32 var_r30_5458;
    s32 var_r31_5456;
    void *temp_r29_5481;
    void *temp_r3_5476;

    var_r28_5454 = 0;
    temp_f30_5455 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    var_r31_5456 = 0;
    temp_f31_5457 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_r30_5458 = 0;
loop_2:
    temp_r29_5481 = M2C_FIELD(this, void **, 4);
    if (var_r28_5454 < (s32) M2C_FIELD(temp_r29_5481, s32 *, 0)) {
        sp8.GetWorldBindPos((s32) this);
        SetNode(var_r28_5454, *((MKVector3 *) &sp8), *(M2C_FIELD(temp_r29_5481, s32 *, 4) + (var_r30_5458 + 0x10)));
        temp_r0_5473 = var_r31_5456 + 0x20;
        var_r28_5454 += 1;
        var_r31_5456 += 0x38;
        temp_r3_5476 = M2C_FIELD(this, s32 *, 0) + temp_r0_5473;
        var_r30_5458 += 0x20;
        M2C_FIELD(temp_r3_5476, f64 *, 0) = temp_f30_5455;
        M2C_FIELD(temp_r3_5476, f64 *, 8) = temp_f31_5457;
        goto loop_2;
    }
    LightCloth();
    this->unk8 = 1;
}
#endif

void MKCloth::Init() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_5570;

    M2C_FIELD(this, s32 *, 0) = 0;
    this->unkC0 = NULL;
    this->unkC4 = NULL;
    this->unkA8 = NULL;
    this->unkAC = NULL;
    this->unkB4 = NULL;
    this->unkB8 = NULL;
    this->unkCC = 0;
    this->unkD0 = 0;
    this->unk30 = NULL;
    this->unk10 = -999999.0f;
    this->unk14 = -999999.0f;
    this->unk18 = -999999.0f;
    this->unk20 = 999999.0f;
    this->unk24 = 999999.0f;
    this->unk28 = 999999.0f;
    this->unk8 = 0;
    this->unkF0 = 0;
    this->unkE0 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    this->unkE8 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    this->unk98 = 0;
    this->unkD4 = 1.0f;
    this->unkD8 = 3;
    this->unkDC = -1;
    this->unkB0 = 0;
    this->unkBC = 0;
    this->unkC8 = 0;
    this->unk9C = 1;
    this->unk9D = 0;
    this->unkA0 = 1.0f;
    this->unkA4 = 1.0f;
    CreateForces(2);
    sp18 = -MKVector3::up.unk0;
    sp1C = -MKVector3::up.unk4;
    sp20 = -MKVector3::up.unk8;
    sp28 = (f64) sp18;
    sp30 = (f64) sp20;
    temp_f0_5570 = sp28 * 5.6745158e-315;
    sp8 = temp_f0_5570;
    sp38 = temp_f0_5570;
    sp10 = (f32) sp30 * 981.0f;
    sp40 = (f64) sp10;
    SetForce(0, *((MKVector3 *) &sp38), -1);
    SetFriction(1.0f);
    SetIterations(3);
}

#if 0 // DRAFT: illegal type
void ModelCloth::Draw() {
    MKCloth *temp_r3_5615;
    s32 var_r30_5610;
    s32 var_r30_5627;
    s32 var_r31_5611;
    s32 var_r31_5628;

    if ((s32) MKSoftBody_enableCloth != 0) {
        var_r30_5610 = 0;
        var_r31_5611 = 0;
loop_5:
        if (var_r30_5610 < (s32) this->unk4) {
            temp_r3_5615 = this->unk8 + var_r31_5611;
            if ((u8) temp_r3_5615->unk8 == 0) {
                temp_r3_5615->Create();
            }
            var_r30_5610 += 1;
            var_r31_5611 += 0xF8;
            goto loop_5;
        }
        var_r30_5627 = 0;
        var_r31_5628 = 0;
loop_11:
        if (var_r30_5627 < (s32) this->unk4) {
            if (((u8) this->unk30 == 0) && ((s32) this->unk0 < (s32) (gFrameCounter - 1))) {
                ((MKCloth *) (this->unk8 + var_r31_5628))->Reset();
            }
            ((MKCloth *) (this->unk8 + var_r31_5628))->Draw();
            var_r30_5627 += 1;
            var_r31_5628 += 0xF8;
            this->unk0 = gFrameCounter;
            goto loop_11;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void ModelCloth::Update() {
    Matrix sp160;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    MKCloth *temp_r3_5693;
    MKHeap **temp_r3_5747;
    MKModel *temp_r28_5706;
    Matrix *var_r31_5682;
    f32 temp_f0_5823;
    f32 temp_f1_5925;
    f32 temp_f2_5817;
    f32 temp_f2_5924;
    f32 temp_f3_5853;
    f32 temp_f4_5926;
    f32 temp_f6_5822;
    f32 temp_f6_5854;
    f32 temp_f7_5856;
    f32 temp_f8_5830;
    f32 var_f4_5932;
    f64 temp_f0_5760;
    f64 temp_f0_5782;
    f64 temp_f1_5935;
    f64 temp_f1_5941;
    f64 temp_f1_5945;
    s32 temp_r3_5708;
    s32 temp_r3_5964;
    s32 var_ctr_5717;
    s32 var_r0_5974;
    s32 var_r28_5688;
    s32 var_r28_5803;
    s32 var_r29_5689;
    s32 var_r29_5804;
    s32 var_r4_5710;
    s32 var_r5_5716;
    s32 var_r6_5709;
    s8 temp_r29_5734;
    void *temp_r0_5811;
    void *temp_r4_5815;
    void *temp_r6_5818;

    var_r31_5682 = NULL;
    if (((s32) MKSoftBody_enableCloth != 0) && ((u8) this->unk31 != 0)) {
        var_r28_5688 = 0;
        var_r29_5689 = 0;
loop_6:
        if (var_r28_5688 < (s32) this->unk4) {
            temp_r3_5693 = this->unk8 + var_r29_5689;
            if ((u8) temp_r3_5693->unk8 == 0) {
                temp_r3_5693->Create();
            }
            var_r28_5688 += 1;
            var_r29_5689 += 0xF8;
            goto loop_6;
        }
        temp_r28_5706 = M2C_FIELD(this->unk8, MKModel **, 0xC);
        temp_r3_5708 = MKModel_GetWorldMatrix(temp_r28_5706);
        var_r6_5709 = 0;
        var_r4_5710 = 0;
        do {
            var_r5_5716 = 0;
            var_ctr_5717 = 4;
loop_9:
            *(&sp160 + var_r4_5710 + var_r5_5716) = *(temp_r3_5708 + var_r4_5710 + var_r5_5716);
            var_r5_5716 += 4;
            var_ctr_5717 -= 1;
            if (var_ctr_5717 != 0) {
                goto loop_9;
            }
            var_r6_5709 += 1;
            var_r4_5710 += 0x10;
        } while (var_r6_5709 < 4);
        if (MKModel_GetAnimation(temp_r28_5706) != NULL) {
            temp_r29_5734 = ((Animation *) (MKModel_GetAnimation(temp_r28_5706)))->GetNmbrOfNodes();
            var_r31_5682 = ((Animation *) (MKModel_GetAnimation(temp_r28_5706)))->CalculateMatrices(NULL, (s32) temp_r29_5734, NULL, &sp160);
        }
        temp_r3_5747 = MKModel_GetBoundingVolume(temp_r28_5706, (SubObjectType) 0, -1);
        this->unk10 = M2C_FIELD(temp_r3_5747, f64 *, 0);
        this->unk18 = M2C_FIELD(temp_r3_5747, f64 *, 8);
        this->unk20 = M2C_FIELD(temp_r3_5747, f64 *, 0x10);
        this->unk28 = M2C_FIELD(temp_r3_5747, f64 *, 0x18);
        temp_f0_5760 = this->unk10 + this->unk20;
        sp58 = temp_f0_5760;
        spF8 = temp_f0_5760;
        sp60 = (f32) M2C_FIELD(this, f64 *, 0x18) + (f32) M2C_FIELD(this, f64 *, 0x28);
        sp100 = (f64) sp60;
        Min(sp108, *((MKVector3 *) &this->unk10));
        sp148 = M2C_BITWISE(f64, sp108);
        sp150 = (f64) sp108.unk8;
        temp_f0_5782 = this->unk10 + this->unk20;
        sp48 = temp_f0_5782;
        spD8 = temp_f0_5782;
        sp50 = (f32) M2C_FIELD(this, f64 *, 0x18) + (f32) M2C_FIELD(this, f64 *, 0x28);
        spE0 = (f64) sp50;
        Max(spE8, *((MKVector3 *) &this->unk10));
        sp138 = M2C_BITWISE(f64, spE8);
        sp140 = (f64) spE8.unk8;
        sp160.InverseSimple(&sp160);
        var_r28_5803 = 0;
        var_r29_5804 = 0;
loop_15:
        if (var_r28_5803 < (s32) this->unk4) {
            ((MKCloth *) (this->unk8 + var_r29_5804))->UpdateInternal(var_r31_5682);
            temp_r0_5811 = this->unk8;
            temp_r4_5815 = temp_r0_5811 + (var_r29_5804 + 0x10);
            temp_f2_5817 = M2C_FIELD(temp_r4_5815, f32 *, 4);
            temp_r6_5818 = temp_r0_5811 + (var_r29_5804 + 0x20);
            temp_f6_5822 = M2C_FIELD(temp_r4_5815, f32 *, 0);
            temp_f0_5823 = M2C_BITWISE(f32, sp160);
            temp_f8_5830 = M2C_FIELD(temp_r4_5815, f32 *, 8);
            sp38 = sp160.unk30 + ((temp_f8_5830 * sp160.unk20) + ((temp_f6_5822 * temp_f0_5823) + (temp_f2_5817 * sp160.unk10)));
            sp3C = sp160.unk34 + ((temp_f8_5830 * sp160.unk24) + ((temp_f6_5822 * sp160.unk4) + (temp_f2_5817 * sp160.unk14)));
            sp40 = sp160.unk38 + ((temp_f8_5830 * sp160.unk28) + ((temp_f6_5822 * sp160.unk8) + (temp_f2_5817 * sp160.unk18)));
            sp128 = (f64) sp38;
            sp130 = (f64) sp40;
            temp_f3_5853 = M2C_FIELD(temp_r6_5818, f32 *, 4);
            temp_f6_5854 = M2C_FIELD(temp_r6_5818, f32 *, 0);
            temp_f7_5856 = M2C_FIELD(temp_r6_5818, f32 *, 8);
            spC8 = (f64) sp38;
            spD0 = (f64) sp40;
            sp28 = sp160.unk30 + ((temp_f7_5856 * sp160.unk20) + ((temp_f6_5854 * temp_f0_5823) + (temp_f3_5853 * sp160.unk10)));
            sp2C = sp160.unk34 + ((temp_f7_5856 * sp160.unk24) + ((temp_f6_5854 * sp160.unk4) + (temp_f3_5853 * sp160.unk14)));
            sp30 = sp160.unk38 + ((temp_f7_5856 * sp160.unk28) + ((temp_f6_5854 * sp160.unk8) + (temp_f3_5853 * sp160.unk18)));
            spB8 = (f64) sp28;
            spC0 = (f64) sp30;
            sp118 = (f64) sp28;
            sp120 = (f64) sp30;
            Min(sp98, *((MKVector3 *) &sp128));
            Min(spA8, *((MKVector3 *) &sp148));
            sp148 = M2C_BITWISE(f64, spA8);
            sp150 = (f64) spA8.unk8;
            Max(sp78, *((MKVector3 *) &sp128));
            Max(sp88, *((MKVector3 *) &sp138));
            var_r28_5803 += 1;
            var_r29_5804 += 0xF8;
            sp138 = M2C_BITWISE(f64, sp88);
            sp140 = (f64) sp88.unk8;
            goto loop_15;
        }
        this->unk10 = sp148;
        this->unk18 = sp150;
        sp18 = sp138 - sp148;
        this->unk20 = sp18;
        sp20 = (f32) sp140 - (f32) sp150;
        sp68 = sp18;
        this->unk28 = (f64) sp20;
        temp_f2_5924 = (f32) M2C_FIELD(this, f64 *, 0x20);
        temp_f1_5925 = M2C_FIELD(this, f32 *, 0x24);
        temp_f4_5926 = (f32) M2C_FIELD(this, f64 *, 0x28);
        sp70 = (f64) sp20;
        var_f4_5932 = (temp_f4_5926 * temp_f4_5926) + ((temp_f2_5924 * temp_f2_5924) + (temp_f1_5925 * temp_f1_5925));
        if (var_f4_5932 > 0.0f) {
            temp_f1_5935 = __frsqrte(var_f4_5932);
            temp_f1_5941 = 0.5 * temp_f1_5935 * -(((f64) var_f4_5932 * (temp_f1_5935 * temp_f1_5935)) - 3.0);
            temp_f1_5945 = 0.5 * temp_f1_5941 * -(((f64) var_f4_5932 * (temp_f1_5941 * temp_f1_5941)) - 3.0);
            var_f4_5932 = (f32) ((f64) var_f4_5932 * (0.5 * temp_f1_5945 * -(((f64) var_f4_5932 * (temp_f1_5945 * temp_f1_5945)) - 3.0)));
        } else if (var_f4_5932 < M2C_BITWISE(f32, 0.0)) {
            var_f4_5932 = __float_nan;
        } else {
            sp10 = var_f4_5932;
            temp_r3_5964 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_5964) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_5974 = 1;
                } else {
                    var_r0_5974 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_5974 = 5;
                } else {
                    var_r0_5974 = 3;
                }
                break;
            default:
                var_r0_5974 = 4;
                break;
            }
            if (var_r0_5974 == 1) {
                var_f4_5932 = __float_nan;
            }
        }
        M2C_FIELD(this, f32 *, 0x1C) = (f32) (0.5f * var_f4_5932);
    }
}
#endif

void MKClothManager::Update() {
    MKModel **var_r31_6022;
    MKModel *temp_r3_6028;

    var_r31_6022 = this->unk0;
loop_2:
    temp_r3_6028 = *var_r31_6022;
    if (temp_r3_6028 != NULL) {
        MKModel_UpdateCloth(temp_r3_6028);
        var_r31_6022 += 4;
        goto loop_2;
    }
}

void MKClothManager::RemoveModel(MKModel *arg0) {
    MKModel **temp_r4_6057;
    MKModel **var_r5_6041;
    MKModel *temp_r0_6050;

    var_r5_6041 = this->unk0;
loop_4:
    temp_r0_6050 = *var_r5_6041;
    if (temp_r0_6050 == NULL) {
        var_r5_6041 = NULL;
    } else if (temp_r0_6050 == arg0) {

    } else {
        var_r5_6041 += 4;
        goto loop_4;
    }
    if (var_r5_6041 != NULL) {
        temp_r4_6057 = this->unk0;
        this->unk0 = temp_r4_6057 + 4;
        *var_r5_6041 = *temp_r4_6057;
    }
}

void MKClothManager::AddModel(MKModel *arg0) {
    MKModel **temp_r5_6069;

    temp_r5_6069 = this->unk0 - 4;
    this->unk0 = temp_r5_6069;
    *temp_r5_6069 = arg0;
}

#if 0 // DRAFT: type mismatch
void MKClothManager::Deinit() {
    MKHeap *temp_r3_6094;
    MKModel **temp_r31_6090;
    MKModel **temp_r3_6085;

    do {
        temp_r3_6085 = this->unk0 - 4;
        this->unk0 = temp_r3_6085;
    } while ((MKModel *) *temp_r3_6085 != NULL);
    temp_r31_6090 = this->unk0;
    if (temp_r31_6090 != &gEmptyPtrList) {
        temp_r3_6094 = temp_r3_6085->Current();
        if (temp_r3_6094 != NULL) {
            ((MKHeap *) (temp_r3_6094->Current()))->Free(temp_r31_6090, NULL, 0);
        } else {
            free((s8 *) temp_r31_6090);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void MKClothManager::Init() {
    MKHeap *temp_r3_6134;
    MKModel **temp_r3_6159;
    MKModel **temp_r3_6165;
    MKModel **var_r3_6142;
    f32 temp_r30_6126;
    f32 var_ctr_6155;

    temp_r30_6126 = gMKDefaults.unkA4;
    if (M2C_BITWISE(s32, temp_r30_6126) == 0) {
        this->unk0 = &gEmptyPtrList + 4;
        return;
    }
    temp_r3_6134 = gMKDefaults.Current();
    if (temp_r3_6134 != NULL) {
        var_r3_6142 = ((MKHeap *) (temp_r3_6134->Current()))->Alloc((M2C_BITWISE(s32, temp_r30_6126) + 2) * 4, NULL, 0);
    } else {
        var_r3_6142 = malloc((M2C_BITWISE(s32, temp_r30_6126) + 2) * 4);
    }
    this->unk0 = var_r3_6142;
    M2C_FIELD(this->unk0, MKModel **, 0) = NULL;
    var_ctr_6155 = temp_r30_6126;
    if (M2C_BITWISE(s32, temp_r30_6126) > 0) {
        do {
            temp_r3_6159 = this->unk0;
            this->unk0 = temp_r3_6159 + 4;
            M2C_FIELD(temp_r3_6159, s32 *, 4) = 0xDEADBEEF;
            var_ctr_6155 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_ctr_6155) - 1));
        } while (M2C_BITWISE(s32, var_ctr_6155) != 0);
    }
    temp_r3_6165 = this->unk0;
    this->unk0 = temp_r3_6165 + 4;
    M2C_FIELD(temp_r3_6165, s32 *, 4) = 0;
}
#endif

void SoftBody_Deinit() {

}

#if 0 // DRAFT: illegal type
void SoftBody_Init() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r0_6201;
    s32 var_ctr_6194;
    s32 var_ctr_6217;
    s32 var_ctr_6236;
    s32 var_ctr_6255;
    s32 var_ctr_6274;
    s32 var_r3_6193;
    s32 var_r3_6216;
    s32 var_r3_6235;
    s32 var_r3_6254;
    s32 var_r3_6273;
    s32 var_r6_6192;
    u8 *temp_r4_6220;
    u8 *temp_r4_6239;
    u8 *temp_r4_6258;
    u8 *temp_r4_6277;
    u8 *temp_r5_6197;
    u8 temp_r0_6221;
    u8 temp_r0_6240;
    u8 temp_r0_6259;
    u8 temp_r0_6278;
    void *temp_r4_6219;
    void *temp_r4_6238;
    void *temp_r4_6257;
    void *temp_r4_6276;

    var_r6_6192 = 0;
    var_r3_6193 = 0;
    var_ctr_6194 = 4;
    do {
        sp8 = 0.0f;
        temp_r5_6197 = &MKCloth::globalForces[var_r3_6193];
        var_r3_6193 += 0x18;
        spC = 0.0f;
        temp_r0_6201 = var_r6_6192 != 0;
        var_r6_6192 += 1;
        sp10 = 0.0f;
        M2C_FIELD(temp_r5_6197, f64 *, 0) = (f64) sp8;
        M2C_FIELD(temp_r5_6197, f64 *, 8) = (f64) sp10;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        M2C_FIELD(temp_r5_6197, s32 *, 0x10) = temp_r0_6201;
        var_ctr_6194 -= 1;
    } while (var_ctr_6194 != 0);
    var_r3_6216 = 0;
    var_ctr_6217 = 0xA;
    do {
        temp_r4_6219 = &MKCloth::sweepSpheres + var_r3_6216;
        temp_r4_6220 = temp_r4_6219 + 0x38;
        temp_r0_6221 = M2C_FIELD(temp_r4_6219, u8 *, 0x38) & ~0x80;
        var_r3_6216 += 0x40;
        *temp_r4_6220 = temp_r0_6221;
        *temp_r4_6220 &= ~0x40;
        *temp_r4_6220 &= ~8;
        var_ctr_6217 -= 1;
    } while (var_ctr_6217 != 0);
    var_r3_6235 = 0;
    var_ctr_6236 = 0x1E;
    do {
        temp_r4_6238 = &MKCloth::spheres + var_r3_6235;
        temp_r4_6239 = temp_r4_6238 + 0x10;
        temp_r0_6240 = M2C_FIELD(temp_r4_6238, u8 *, 0x10) & ~0x80;
        var_r3_6235 += 0x18;
        *temp_r4_6239 = temp_r0_6240;
        *temp_r4_6239 &= ~0x40;
        *temp_r4_6239 &= ~8;
        var_ctr_6236 -= 1;
    } while (var_ctr_6236 != 0);
    var_r3_6254 = 0;
    var_ctr_6255 = 0xA;
    do {
        temp_r4_6257 = &MKCloth::planes + var_r3_6254;
        temp_r4_6258 = temp_r4_6257 + 0x24;
        temp_r0_6259 = M2C_FIELD(temp_r4_6257, u8 *, 0x24) & ~0x80;
        var_r3_6254 += 0x28;
        *temp_r4_6258 = temp_r0_6259;
        *temp_r4_6258 &= ~0x40;
        *temp_r4_6258 &= ~8;
        var_ctr_6255 -= 1;
    } while (var_ctr_6255 != 0);
    var_r3_6273 = 0;
    var_ctr_6274 = 0x1E;
    do {
        temp_r4_6276 = &MKCloth::capsules + var_r3_6273;
        temp_r4_6277 = temp_r4_6276 + 0x4C;
        temp_r0_6278 = M2C_FIELD(temp_r4_6276, u8 *, 0x4C) & ~0x80;
        var_r3_6273 += 0x50;
        *temp_r4_6277 = temp_r0_6278;
        *temp_r4_6277 &= ~0x40;
        *temp_r4_6277 &= ~8;
        var_ctr_6274 -= 1;
    } while (var_ctr_6274 != 0);
    *MKCloth::includedSweepCount = 0;
    *MKCloth::includedSphereCount = 0;
    *MKCloth::includedPlaneCount = 0;
    *MKCloth::includedCapsuleCount = 0;
}
#endif

#include "spyro/source/Wake.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/KDVolume.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/Level.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

s32 Wake::GetWakeLength(int arg0) {
    s32 temp_r5_58;
    s32 temp_r6_41;
    s32 var_ctr_45;
    s32 var_r0_59;
    s32 var_r7_43;
    s32 var_r8_42;
    u8 *var_r5_54;

    temp_r6_41 = this->unk54;
    var_r8_42 = arg0;
    var_r7_43 = 0;
    var_ctr_45 = temp_r6_41 - var_r8_42;
    if (var_r8_42 < temp_r6_41) {
loop_1:
        if ((var_r8_42 < 0) || (var_r8_42 >= temp_r6_41)) {
            var_r5_54 = NULL;
        } else {
            temp_r5_58 = this->unk50;
            var_r0_59 = this->unk58 + var_r8_42;
            if (var_r0_59 >= temp_r5_58) {
                var_r0_59 -= temp_r5_58;
            }
            var_r5_54 = ((u8 *) this->unk5C) + (var_r0_59 * 0x88);
        }
        if ((u8) *var_r5_54 != 0) {
            if (var_r7_43 > 0) {
                return var_r8_42 - arg0;
            }
            var_r7_43 += 1;
            goto block_11;
        }
block_11:
        var_r8_42 += 1;
        var_ctr_45 -= 1;
        if (var_ctr_45 == 0) {
            /* Duplicate return node #12. Try simplifying control flow for better match */
            return var_r8_42 - arg0;
        }
        goto loop_1;
    }
    return var_r8_42 - arg0;
}

#if 0 // DRAFT: illegal operand
void Wake::Draw() {
    f32 var_f30_148;
    s32 temp_r28_114;
    s32 temp_r3_110;
    s32 temp_r3_132;
    s32 var_r0_133;
    s32 var_r26_118;
    s32 var_r27_105;
    u32 temp_r3_143;
    void *var_r29_128;

    if ((s32) this->unk54 >= 2) {
        MKMaterial_SetMaterial(this->unk4C);
        MKPrimitive(4, 0);
        var_r27_105 = 0;
loop_17:
        if (var_r27_105 < (s32) this->unk54) {
            temp_r3_110 = GetWakeLength(var_r27_105);
            if (temp_r3_110 >= 2) {
                temp_r28_114 = var_r27_105 + temp_r3_110;
                MKBegin(temp_r28_114 * 2);
                var_r26_118 = var_r27_105;
loop_14:
                if (var_r26_118 < temp_r28_114) {
                    if ((var_r26_118 < 0) || (var_r26_118 >= (s32) this->unk54)) {
                        var_r29_128 = NULL;
                    } else {
                        temp_r3_132 = this->unk50;
                        var_r0_133 = this->unk58 + var_r26_118;
                        if (var_r0_133 >= temp_r3_132) {
                            var_r0_133 -= temp_r3_132;
                        }
                        var_r29_128 = ((u8 *) this->unk5C) + (var_r0_133 * 0x88);
                    }
                    temp_r3_143 = this->unkC0;
                    var_f30_148 = (f32) var_r26_118;
                    if ((temp_r3_143 != 0) && (var_r29_128 == temp_r3_143)) {
                        var_f30_148 += (this->unkD0 / this->unkCC) - 1.0f;
                    }
                    MKSetColorV(*(var_r29_128 + 0x58));
                    MKSetTexCoord1F(M2C_FIELD(var_r29_128, f32 *, 0x18), var_f30_148);
                    MKSetPositionV(*(var_r29_128 + 0x38));
                    MKSetColorV(*(var_r29_128 + 0x68));
                    MKSetTexCoord1F(M2C_FIELD(var_r29_128, f32 *, 0x28), var_f30_148);
                    MKSetPositionV(*(var_r29_128 + 0x48));
                    var_r26_118 += 1;
                    goto loop_14;
                }
                MKEnd();
            }
            var_r27_105 += temp_r3_110;
            goto loop_17;
        }
        MKEndPrimitive();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void *Wake::Update() {
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
    f64 sp80;
    f64 sp78;
    f64 sp70;
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
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f1_401;
    f32 temp_f3_395;
    f32 temp_f4_400;
    f32 var_f0_407;
    f32 var_f0_430;
    f32 var_f29_421;
    f64 temp_f0_286;
    f64 temp_f0_307;
    f64 temp_f0_336;
    f64 temp_f0_448;
    s32 temp_r0_247;
    s32 temp_r3_228;
    s32 temp_r3_248;
    s32 temp_r4_474;
    s32 var_r0_229;
    s32 var_r30_215;
    s8 *var_r3_264;
    void *var_r28_224;

    if ((s32) this->unk54 != 0) {
        var_r30_215 = 0;
loop_41:
        temp_r4_474 = this->unk54;
        if (var_r30_215 < temp_r4_474) {
            if ((var_r30_215 < 0) || (var_r30_215 >= temp_r4_474)) {
                var_r28_224 = NULL;
            } else {
                temp_r3_228 = this->unk50;
                var_r0_229 = this->unk58 + var_r30_215;
                if (var_r0_229 >= temp_r3_228) {
                    var_r0_229 -= temp_r3_228;
                }
                var_r28_224 = ((u8 *) this->unk5C) + (var_r0_229 * 0x88);
            }
            if (M2C_FIELD(var_r28_224, f32 *, 4) < M2C_FIELD(&gb, f32 *, 0x30C)) {
                if (temp_r4_474 > 0) {
                    this->unk58 += 1;
                    temp_r0_247 = this->unk58;
                    temp_r3_248 = this->unk50;
                    if (temp_r0_247 >= temp_r3_248) {
                        this->unk58 = temp_r0_247 - temp_r3_248;
                    }
                    this->unk54 -= 1;
                }
                if ((s32) this->unk54 > 0) {
                    var_r3_264 = ((u8 *) this->unk5C) + (this->unk58 * 0x88);
                } else {
                    var_r3_264 = NULL;
                }
                if (var_r3_264 != NULL) {
                    *var_r3_264 = 1;
                }
                var_r30_215 -= 1;
                if ((s32) this->unk54 == 0) {
                    this->unkC0 = 0;
                }
            } else {
                temp_f0_286 = M2C_FIELD(var_r28_224, f64 *, 8) * (f64) gUpdateTimeDelta;
                sp40 = temp_f0_286;
                spC0 = temp_f0_286;
                sp48 = M2C_FIELD(var_r28_224, f32 *, 0x10) * gUpdateTimeDelta;
                spC8 = (f64) sp48;
                M2C_FIELD(var_r28_224, f64 *, 0x38) = (f64) (M2C_FIELD(var_r28_224, f64 *, 0x38) - temp_f0_286);
                M2C_FIELD(var_r28_224, f32 *, 0x40) = (f32) (M2C_FIELD(var_r28_224, f32 *, 0x40) - (f32) spC8);
                temp_f0_307 = M2C_FIELD(var_r28_224, f64 *, 8) * (f64) gUpdateTimeDelta;
                sp30 = temp_f0_307;
                spB0 = temp_f0_307;
                sp38 = M2C_FIELD(var_r28_224, f32 *, 0x10) * gUpdateTimeDelta;
                spB8 = (f64) sp38;
                M2C_FIELD(var_r28_224, f64 *, 0x48) = (f64) (M2C_FIELD(var_r28_224, f64 *, 0x48) + temp_f0_307);
                sp68 = 0.0f;
                sp60 = 0.0f;
                sp64 = -10.0f;
                M2C_FIELD(var_r28_224, f32 *, 0x50) = (f32) (M2C_FIELD(var_r28_224, f32 *, 0x50) + (f32) spB8);
                spA0 = (f64) sp60;
                spA8 = (f64) sp68;
                temp_f0_336 = M2C_FIELD(var_r28_224, f64 *, 0x38) + spA0;
                sp50 = temp_f0_336;
                sp8 = 0.0f;
                spD0 = temp_f0_336;
                sp58 = M2C_FIELD(var_r28_224, f32 *, 0x40) + (f32) spA8;
                spD8 = (f64) sp58;
                if (((KDWaterVolume *) &spD0)->IsWithin(*((MKVector3 *) &sp8), NULL, M2C_ERROR(/* Read from unset register $r6 */)) != 0) {
                    M2C_FIELD(var_r28_224, f32 *, 0x3C) = sp8;
                    M2C_FIELD(var_r28_224, f32 *, 0x3C) = (f32) (M2C_FIELD(var_r28_224, f32 *, 0x3C) + 1.0f);
                }
                MKVector(0.0f, -10.0f, 0.0f);
                sp20 = M2C_FIELD(var_r28_224, f64 *, 0x48) + sp80;
                sp90 = sp20;
                sp28 = M2C_FIELD(var_r28_224, f32 *, 0x50) + sp88;
                spD0 = sp20;
                sp98 = (f64) sp28;
                spD8 = (f64) sp28;
                sp8 = 0.0f;
                if (((KDWaterVolume *) &spD0)->IsWithin(*((MKVector3 *) &sp8), NULL, M2C_ERROR(/* Read from unset register $r6 */)) != 0) {
                    M2C_FIELD(var_r28_224, f32 *, 0x4C) = sp8;
                    M2C_FIELD(var_r28_224, f32 *, 0x4C) = (f32) (M2C_FIELD(var_r28_224, f32 *, 0x4C) + 1.0f);
                }
                temp_f3_395 = this->unkC4;
                temp_f4_400 = 0.25f * temp_f3_395;
                temp_f1_401 = (M2C_FIELD(&gb, f32 *, 0x30C) + temp_f3_395) - M2C_FIELD(var_r28_224, f32 *, 4);
                if (temp_f1_401 < temp_f4_400) {
                    var_f0_407 = (1.0f / temp_f4_400) * temp_f1_401;
                    if (var_f0_407 < 1.0f) {

                    } else {
                        var_f0_407 = 1.0f;
                    }
                    if (var_f0_407 > 0.0f) {

                    } else {
                        var_f0_407 = 0.0f;
                    }
                    var_f29_421 = var_f0_407;
                } else {
                    var_f0_430 = 1.0f - ((temp_f1_401 - temp_f4_400) / -((1.15f * temp_f4_400) - temp_f3_395));
                    if (var_f0_430 < 1.0f) {

                    } else {
                        var_f0_430 = 1.0f;
                    }
                    if (var_f0_430 > 0.0f) {

                    } else {
                        var_f0_430 = 0.0f;
                    }
                    var_f29_421 = var_f0_430;
                }
                temp_f0_448 = M2C_FIELD(var_r28_224, f64 *, 0x78) * (f64) var_f29_421;
                sp10 = temp_f0_448;
                sp70 = temp_f0_448;
                sp18 = M2C_FIELD(var_r28_224, f32 *, 0x80) * var_f29_421;
                M2C_FIELD(var_r28_224, f32 *, 0x58) = (f32) sp70;
                sp78 = (f64) sp18;
                M2C_FIELD(var_r28_224, f32 *, 0x5C) = (*(f32 *) ((u8 *) &sp70 + 0x4));
                M2C_FIELD(var_r28_224, f32 *, 0x60) = (f32) sp78;
                M2C_FIELD(var_r28_224, f32 *, 0x64) = 0.0f;
                M2C_FIELD(var_r28_224, f32 *, 0x64) = 1.0f;
                M2C_FIELD(var_r28_224, f64 *, 0x68) = (f64) M2C_FIELD(var_r28_224, f32 *, 0x58);
                M2C_FIELD(var_r28_224, f64 *, 0x70) = (f64) M2C_FIELD(var_r28_224, f32 *, 0x60);
            }
            var_r30_215 += 1;
            goto loop_41;
        }
    }
}
#endif

void Wake::Reset() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKProp::Reset();
    this->unk58 = 0;
    this->unk54 = 0;
    this->unk10 &= 0xFFFFFDFF;
    this->unkA0 = -1.0f;
    this->unkA4 = -1.0f;
    this->unkA8 = -1.0f;
    sp8 = (f64) M2C_FIELD(this, f32 *, 0xA0) * 1.591496843e-314;
    this->unkB0 = sp8;
    sp10 = this->unkA8 * -2.0f;
    sp18 = sp8;
    sp20 = (f64) sp10;
    this->unkB8 = (f64) sp10;
}

void Wake::Deinit() {
    MKHeap *temp_r3_547;
    void *temp_r31_544;

    MKProp::Deinit();
    temp_r31_544 = this->unk5C;
    if (temp_r31_544 != NULL) {
        temp_r3_547 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_547 != NULL) {
            ((MKHeap *) (temp_r3_547->Current()))->Free(temp_r31_544, NULL, 0);
        } else {
            free(temp_r31_544);
        }
        this->unk5C = NULL;
    }
    this->unk50 = 0;
    this->unk58 = 0;
    this->unk54 = 0;
    MKMaterial_Destroy(this->unk4C);
    this->unk4C = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void Wake::Init() {
    MKHeap *temp_r3_587;
    void *var_r3_594;

    MKProp::Init();
    temp_r3_587 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_587 != NULL) {
        var_r3_594 = ((MKHeap *) (temp_r3_587->Current()))->Alloc(0xAA0, NULL, 0);
    } else {
        var_r3_594 = malloc(0xAA0);
    }
    this->unk5C = var_r3_594;
    this->unk50 = 0x14;
    M2C_FIELD(this->unk0, f32 **, 0x1C) = &this->unkA0;
    this->unk60.SetIdentity();
    this->unk8 = &this->unk60;
    this->unk4C = MKMaterial_Create("fx_077");
}
#endif

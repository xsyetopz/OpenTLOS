#include "spyro/source/BoneBlurFX.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/ShotgunWarpFX.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(BoneBlurFX::BlurNode **);              /* extern */
BoneBlurFX::BlurNode **malloc(s32);                 /* extern */
extern void **gMK;
#if 0 // DRAFT: undefined identifier 'Pool'
static Pool<BoneBlurFX::BlurNode> gBoneBlurFXPool;
#endif

#if 0 // DRAFT: expression syntax error
void BoneBlurFX::FreePoolMem() {
    BoneBlurFX::BlurNode *temp_r4_47;
    s32 var_r3_53;
    s32 var_r6_54;

    temp_r4_47 = *this->unk58;
    if (temp_r4_47 != NULL) {
        gBoneBlurFXPool.Free((BoneBlurFX::BlurNode *) temp_r4_47);
        var_r3_53 = 0;
        var_r6_54 = 0;
loop_3:
        if (var_r6_54 < (s32) this->unk54) {
            var_r6_54 += 1;
            *(this->unk58 + var_r3_53) = 0;
            var_r3_53 += 4;
            goto loop_3;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
u8 BoneBlurFX::AllocPoolMem() {
    s32 temp_r0_103;
    s32 var_r4_98;
    s32 var_r6_97;
    u32 temp_r3_94;

    if ((BoneBlurFX::BlurNode *) *this->unk58 != NULL) {
        return 1U;
    }
    temp_r3_94 = gBoneBlurFXPool.Alloc(this->unk54 * this->unk68);
    if (temp_r3_94 != 0U) {
        var_r6_97 = 0;
        var_r4_98 = 0;
loop_5:
        if (var_r6_97 < (s32) this->unk54) {
            temp_r0_103 = var_r6_97 * this->unk68;
            var_r6_97 += 1;
            *(this->unk58 + var_r4_98) = temp_r3_94 + (temp_r0_103 << 5);
            var_r4_98 += 4;
            goto loop_5;
        }
        return 1U;
    }
    return 0U;
}
#endif

void BoneBlurFX::Teleport() {
    this->unk4C = 0;
    this->unk50 = 0;
    TakeFrameSnapshot();
}

#if 0 // DRAFT: undefined identifier 'arg_sp1C'
void BoneBlurFX::CalcUVs() {
    s32 temp_r0_182;
    s32 temp_r3_181;
    s32 var_r28_170;
    s32 var_r29_153;
    s32 var_r30_171;
    var_r29_153 = this->unk4C - 1;
    if (var_r29_153 < 0) {
        var_r29_153 = this->unk54 - 1;
    }
    M2C_STRUCT_COPY((s32) &arg_sp1C + 4, MKView_GetWorldToScreenMatrix() - 4 + 4, 0x40);
    var_r28_170 = 0;
    var_r30_171 = 0;
loop_4:
    if (var_r28_170 < (s32) this->unk68) {
        Xform3D2D((MKVector3 *) &arg_sp10, *(this->unk58[var_r29_153] + var_r30_171), (Matrix *) &arg_sp20);
        temp_r3_181 = var_r30_171 + 0x10;
        temp_r0_182 = var_r30_171 + 0x14;
        var_r28_170 += 1;
        var_r30_171 += 0x20;
        *(this->unk58[var_r29_153] + temp_r3_181) = arg_sp10;
        *(this->unk58[var_r29_153] + temp_r0_182) = arg_sp14;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: illegal type
void BoneBlurFX::TakeFrameSnapshot() {
    s32 temp_r0_223;
    s32 temp_r3_265;
    s32 var_r28_216;
    s32 var_r29_218;
    s32 var_r30_217;
    void *temp_r5_222;

    if ((BoneBlurFX::BlurNode *) *this->unk58 != NULL) {
        var_r28_216 = 0;
        var_r30_217 = 0;
        var_r29_218 = 0;
loop_7:
        if (var_r28_216 < (s32) this->unk68) {
            temp_r5_222 = this->unk64 + var_r29_218;
            temp_r0_223 = M2C_FIELD(temp_r5_222, s32 *, 8);
            if (temp_r0_223 == 0) {
                MKModel_CalculateNodeWorldPosition(this->unk74, M2C_FIELD(temp_r5_222, s32 *, 4), this->unk58[this->unk4C] + var_r30_217);
            } else if (temp_r0_223 == 1) {
                MKModel_CalculateRefPointWorldPosition(this->unk74, M2C_FIELD(temp_r5_222, s32 *, 4), this->unk58[this->unk4C] + var_r30_217);
            }
            var_r28_216 += 1;
            var_r30_217 += 0x20;
            var_r29_218 += 0xC;
            goto loop_7;
        }
        this->unk4C += 1;
        if ((s32) this->unk4C >= (s32) this->unk54) {
            this->unk4C = 0;
        }
        temp_r3_265 = this->unk50;
        if ((s32) this->unk4C == temp_r3_265) {
            this->unk50 = temp_r3_265 + 1;
            if ((s32) this->unk50 >= (s32) this->unk54) {
                this->unk50 = 0;
            }
        }
    }
}
#endif

void BoneBlurFX::EnableBlur(bool arg0) {
    u8 temp_r4_294;
    u8 var_r31_291;

    var_r31_291 = arg0;
    temp_r4_294 = this->unk6C;
    if (temp_r4_294 != var_r31_291) {
        if ((temp_r4_294 == 0) && (var_r31_291 != 0)) {
            if (AllocPoolMem() != 0) {
                this->unk4C = 0;
                this->unk50 = 0;
                TakeFrameSnapshot();
            } else {
                var_r31_291 = 0;
            }
        }
        if (var_r31_291 == 0) {
            FreePoolMem();
        }
        this->unk6C = var_r31_291;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'int **' to
void BoneBlurFX::InitData(MKModel *arg0, BoneBlurFXNodeDef *arg1, int arg2, int **arg3, int arg4, int arg5, bool arg6) {
    BoneBlurFX *temp_r31_334;
    BoneBlurFX *var_r3_0;
    BoneBlurFX::BlurNode **var_r3_389;
    MKHeap *temp_r3_382;
    s32 temp_r0_348;
    s32 temp_r30_381;
    s32 var_r29_336;
    s32 var_r30_337;
    s32 var_r3_398;
    s32 var_r6_395;
    void *temp_r4_347;

    var_r3_0 = this;
    temp_r31_334 = var_r3_0;
    var_r29_336 = 0;
    var_r30_337 = 0;
    var_r3_0->unk74 = arg0;
    var_r3_0->unk64 = arg1;
    var_r3_0->unk68 = arg2;
    var_r3_0->unk5C = arg3;
    var_r3_0->unk60 = arg4;
    var_r3_0->unk7C = arg6;
loop_6:
    if (var_r29_336 < (s32) temp_r31_334->unk68) {
        temp_r4_347 = temp_r31_334->unk64 + var_r30_337;
        temp_r0_348 = M2C_FIELD(temp_r4_347, s32 *, 8);
        if (temp_r0_348 == 0) {
            var_r3_0 = (BoneBlurFX *) Tools_GetMatchingNodeIndex(temp_r31_334->unk74, M2C_FIELD(temp_r4_347, s8 **, 0));
            *(temp_r31_334->unk64 + (var_r30_337 + 4)) = var_r3_0;
        } else if (temp_r0_348 == 1) {
            var_r3_0 = (BoneBlurFX *) Tools_GetMatchingRefPointIndex(temp_r31_334->unk74, M2C_FIELD(temp_r4_347, s8 **, 0));
            *(temp_r31_334->unk64 + (var_r30_337 + 4)) = var_r3_0;
        }
        var_r29_336 += 1;
        var_r30_337 += 0xC;
        goto loop_6;
    }
    temp_r31_334->unk54 = arg5;
    temp_r31_334->unk4C = 0;
    temp_r31_334->unk50 = 0;
    temp_r30_381 = temp_r31_334->unk54 << 5;
    temp_r3_382 = var_r3_0->Current();
    if (temp_r3_382 != NULL) {
        var_r3_389 = ((MKHeap *) (temp_r3_382->Current()))->Alloc(temp_r30_381, NULL, 0);
    } else {
        var_r3_389 = malloc(temp_r30_381);
    }
    var_r6_395 = 0;
    temp_r31_334->unk58 = var_r3_389;
    var_r3_398 = 0;
loop_12:
    if (var_r6_395 < (s32) temp_r31_334->unk54) {
        var_r6_395 += 1;
        *(temp_r31_334->unk58 + var_r3_398) = 0;
        var_r3_398 += 4;
        goto loop_12;
    }
}
#endif

void BoneBlurFX::Deinit() {
    BoneBlurFX::BlurNode **temp_r31_434;
    MKHeap *temp_r3_435;
    s32 *temp_r3_424;

    temp_r3_424 = this->unk78;
    if (temp_r3_424 != NULL) {
        *temp_r3_424 = 0;
    }
    this->unk78 = NULL;
    MKMaterial_Destroy(this->unk70);
    temp_r31_434 = this->unk58;
    temp_r3_435 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_435 != NULL) {
        ((MKHeap *) (temp_r3_435->Current()))->Free(temp_r31_434, NULL, 0);
    } else {
        free(temp_r31_434);
    }
    MKProp::Deinit();
}

#if 0 // DRAFT: undefined identifier 'identity'
void BoneBlurFX::Draw() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
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
    f32 var_f30_532;
    s32 var_r22_480;
    s32 var_r22_527;
    s32 var_r23_523;
    s32 var_r25_533;
    s32 var_r26_526;
    s32 var_r27_522;
    s32 var_r28_481;
    s32 var_r3_487;
    void *temp_r3_552;
    void *temp_r3_582;
    void *temp_r3_621;
    void *temp_r3_652;

    if (((u8) this->unk6C != 0) && ((BoneBlurFX::BlurNode *) *this->unk58 != NULL)) {
        CalcUVs();
        var_r22_480 = 0;
        var_r28_481 = this->unk4C - 1;
        if (var_r28_481 < 0) {
            var_r28_481 = this->unk54 - 1;
        }
        var_r3_487 = var_r28_481;
loop_7:
        if (var_r3_487 != (s32) this->unk50) {
            var_r3_487 -= 1;
            var_r22_480 += 1;
            if (var_r3_487 < 0) {
                var_r3_487 = this->unk54 - 1;
            }
            goto loop_7;
        }
        if ((s32) (var_r22_480 + 1) >= 2) {
            MKMaterial_SetMaterial(this->unk70);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(identity);
            var_r27_522 = 0;
            var_r23_523 = 0;
loop_19:
            if (var_r27_522 < (s32) this->unk60) {
                var_r26_526 = 1;
                var_r22_527 = 4;
loop_17:
                if (var_r26_526 <= (s32) (**(var_r23_523 + this->unk5C) - 1)) {
                    MKBegin((var_r22_480 + 1) * 2);
                    var_f30_532 = 1.0f;
                    var_r25_533 = var_r28_481;
loop_15:
                    if (var_r25_533 != (s32) this->unk50) {
                        sp38 = 1.0f;
                        sp3C = 1.0f;
                        sp40 = 1.0f;
                        sp44 = var_f30_532;
                        sp78 = (f64) sp38;
                        sp80 = (f64) sp40;
                        MKSetColorV(*((MKVector4 *) &sp78));
                        temp_r3_552 = this->unk58[var_r28_481] + (*(var_r22_527 + *(var_r23_523 + this->unk5C)) << 5);
                        MKSetTexCoord1F(M2C_FIELD(temp_r3_552, f32 *, 0x10), M2C_FIELD(temp_r3_552, f32 *, 0x14));
                        MKSetPositionV(*(this->unk58[var_r25_533] + (*(var_r22_527 + *(var_r23_523 + this->unk5C)) << 5)));
                        sp28 = 1.0f;
                        sp2C = 1.0f;
                        sp30 = 1.0f;
                        sp34 = var_f30_532;
                        sp68 = (f64) sp28;
                        sp70 = (f64) sp30;
                        MKSetColorV(*((MKVector4 *) &sp68));
                        temp_r3_582 = this->unk58[var_r28_481] + (*(var_r22_527 + (*(var_r23_523 + this->unk5C) + 4)) << 5);
                        MKSetTexCoord1F(M2C_FIELD(temp_r3_582, f32 *, 0x10), M2C_FIELD(temp_r3_582, f32 *, 0x14));
                        MKSetPositionV(*(this->unk58[var_r25_533] + (*(var_r22_527 + (*(var_r23_523 + this->unk5C) + 4)) << 5)));
                        var_r25_533 -= 1;
                        if (var_r25_533 < 0) {
                            var_r25_533 = this->unk54 - 1;
                        }
                        var_f30_532 -= 1.0f / (f32) var_r22_480;
                        goto loop_15;
                    }
                    sp18 = 1.0f;
                    sp1C = 1.0f;
                    sp20 = 1.0f;
                    sp24 = var_f30_532;
                    sp58 = (f64) sp18;
                    sp60 = (f64) sp20;
                    MKSetColorV(*((MKVector4 *) &sp58));
                    temp_r3_621 = this->unk58[var_r28_481] + (*(*(var_r23_523 + this->unk5C) + var_r22_527) << 5);
                    MKSetTexCoord1F(M2C_FIELD(temp_r3_621, f32 *, 0x10), M2C_FIELD(temp_r3_621, f32 *, 0x14));
                    MKSetPositionV(*(this->unk58[this->unk50] + (*(*(var_r23_523 + this->unk5C) + var_r22_527) << 5)));
                    sp8 = 1.0f;
                    spC = 1.0f;
                    sp10 = 1.0f;
                    sp14 = var_f30_532;
                    sp48 = (f64) sp8;
                    sp50 = (f64) sp10;
                    MKSetColorV(*((MKVector4 *) &sp48));
                    temp_r3_652 = this->unk58[var_r28_481] + (*(*(var_r23_523 + this->unk5C) + (var_r22_527 + 4)) << 5);
                    MKSetTexCoord1F(M2C_FIELD(temp_r3_652, f32 *, 0x10), M2C_FIELD(temp_r3_652, f32 *, 0x14));
                    MKSetPositionV(*(this->unk58[this->unk50] + (*(*(var_r23_523 + this->unk5C) + (var_r22_527 + 4)) << 5)));
                    MKEnd();
                    var_r26_526 += 1;
                    var_r22_527 += 4;
                    goto loop_17;
                }
                var_r27_522 += 1;
                var_r23_523 += 4;
                goto loop_19;
            }
            MKEndPrimitive();
        }
    }
}
#endif

void BoneBlurFX::Update() {
    if (((u8) this->unk6C != 0) && ((u8) this->unk7C != 0)) {
        TakeFrameSnapshot();
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void BoneBlurFX::Init() {
    MKProp::Init();
    this->unk58 = NULL;
    this->unk4C = 0;
    this->unk50 = 0;
    this->unk54 = 0;
    this->unk5C = NULL;
    this->unk60 = 0;
    this->unk64 = NULL;
    this->unk68 = 0;
    this->unk6C = 0;
    this->unk78 = NULL;
    this->unk70 = MKMaterial_Create("fx_boneblurmat");
}
#endif

#if 0 // DRAFT: expression syntax error
void BoneBlurFXDescriptor::DrawInstances() {
    void *var_r30_773;
    void *var_r31_768;
    void *var_r4_756;
    void *var_r4_787;

    var_r4_756 = pFirstDesc.__vptr;
loop_2:
    if ((var_r4_756 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_756, void **, 0x60), s32 *, 0x138) & 2)) {
        var_r4_756 = M2C_FIELD(var_r4_756, void **, 0x68);
        goto loop_2;
    }
    var_r31_768 = var_r4_756;
loop_13:
    if (var_r31_768 != NULL) {
        var_r30_773 = checked_cast<BoneBlurFX *, MKProp>(M2C_FIELD(var_r31_768, MKProp **, 0x28));
loop_7:
        if (var_r30_773 != NULL) {
            M2C_FIELD(M2C_FIELD(var_r30_773, void **, 0x44), M2C_UNK (**)(void *), 0x28)(var_r30_773);
            var_r30_773 = checked_cast<BoneBlurFX *, MKProp>(M2C_FIELD(var_r30_773, MKProp **, 0x38));
            goto loop_7;
        }
        var_r4_787 = M2C_FIELD(var_r31_768, void **, 0x68);
loop_10:
        if ((var_r4_787 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_787, void **, 0x60), s32 *, 0x138) & 2)) {
            var_r4_787 = M2C_FIELD(var_r4_787, void **, 0x68);
            goto loop_10;
        }
        var_r31_768 = var_r4_787;
        goto loop_13;
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void BoneBlurFXDescriptor::Deinit() {
    BoneBlurFXDescriptor *temp_r4_822;
    BoneBlurFXDescriptor *temp_r4_828;

    if ((void *) pFirstDesc.__vptr == this) {
        pFirstDesc.__vptr = this->unk68;
    }
    temp_r4_822 = this->unk64;
    if (temp_r4_822 != NULL) {
        temp_r4_822->unk68 = this->unk68;
    }
    temp_r4_828 = this->unk68;
    if (temp_r4_828 != NULL) {
        temp_r4_828->unk64 = this->unk64;
    }
    this->unk64 = NULL;
    this->unk68 = NULL;
    this->unk60 = NULL;
    MKPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: expression syntax error
void BoneBlurFXDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk68 = (BoneBlurFXDescriptor *) pFirstDesc.__vptr;
    this->unk64 = NULL;
    if ((void *) pFirstDesc.__vptr != NULL) {
        M2C_FIELD(pFirstDesc.__vptr, BoneBlurFXDescriptor **, 0x64) = this;
    }
    pFirstDesc.__vptr = this;
    this->unk60 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}
#endif

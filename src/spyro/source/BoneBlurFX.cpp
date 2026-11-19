#include "spyro/source/BoneBlurFX.h"
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
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
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
            *(this->unk58 + var_r4_98) = (BoneBlurFX::BlurNode *) (temp_r3_94 + (temp_r0_103 << 5));
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

void BoneBlurFX::CalcUVs() {
    Matrix sp20;
    MKVector3 sp10;
    s32 var_r28_170;
    s32 var_r29_153;
    s32 var_r30_171;

    var_r29_153 = this->unk4C - 1;
    if (var_r29_153 < 0) {
        var_r29_153 = this->unk54 - 1;
    }
    M2C_STRUCT_COPY(&sp20, MKView_GetWorldToScreenMatrix(), 0x40);
    var_r28_170 = 0;
    var_r30_171 = 0;
    while (var_r28_170 < (s32) this->unk68) {
        u8 *node = (u8 *) this->unk58[var_r29_153];
        Xform3D2D(&sp10, *(MKVector3 *) (node + var_r30_171), &sp20);
        *(f32 *) (node + var_r30_171 + 0x10) = sp10.unk0;
        *(f32 *) (node + var_r30_171 + 0x14) = sp10.unk4;
        var_r28_170 += 1;
        var_r30_171 += 0x20;
    }
}

void BoneBlurFX::TakeFrameSnapshot() {
    s32 temp_r3_265;
    s32 var_r28_216;
    s32 var_r29_218;
    s32 var_r30_217;

    if (this->unk58[0] != NULL) {
        var_r28_216 = 0;
        var_r30_217 = 0;
        var_r29_218 = 0;
        while (var_r28_216 < (s32) this->unk68) {
            u8 *temp_r5_222 = (u8 *) this->unk64 + var_r29_218;
            s32 temp_r0_223 = M2C_FIELD(temp_r5_222, s32 *, 8);
            if (temp_r0_223 == 0) {
                MKModel_CalculateNodeWorldPosition(this->unk74, M2C_FIELD(temp_r5_222, s32 *, 4), (MKVector3 *) ((u8 *) this->unk58[this->unk4C] + var_r30_217));
            } else if (temp_r0_223 == 1) {
                MKModel_CalculateRefPointWorldPosition(this->unk74, M2C_FIELD(temp_r5_222, s32 *, 4), (MKVector3 *) ((u8 *) this->unk58[this->unk4C] + var_r30_217));
            }
            var_r28_216 += 1;
            var_r30_217 += 0x20;
            var_r29_218 += 0xC;
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

void BoneBlurFX::InitData(MKModel *arg0, BoneBlurFXNodeDef *arg1, int arg2, int **arg3, int arg4, int arg5, bool arg6) {
    s32 var_r29_336;
    s32 var_r30_337;
    s32 temp_r0_348;
    u8 *temp_r4_347;
    s32 temp_r30_381;
    BoneBlurFX::BlurNode **var_r3_389;
    s32 var_r6_395;
    s32 var_r3_398;

    var_r29_336 = 0;
    var_r30_337 = 0;
    this->unk74 = arg0;
    this->unk64 = arg1;
    this->unk68 = arg2;
    this->unk5C = (s32 **) arg3;
    this->unk60 = arg4;
    this->unk7C = arg6;
    while (var_r29_336 < (s32) this->unk68) {
        temp_r4_347 = (u8 *) this->unk64 + var_r30_337;
        temp_r0_348 = M2C_FIELD(temp_r4_347, s32 *, 8);
        if (temp_r0_348 == 0) {
            M2C_FIELD(temp_r4_347, s32 *, 4) = (s32) (u16) Tools_GetMatchingNodeIndex(this->unk74, M2C_FIELD(temp_r4_347, const char **, 0));
        } else if (temp_r0_348 == 1) {
            M2C_FIELD(temp_r4_347, s32 *, 4) = (s32) (u16) Tools_GetMatchingRefPointIndex(this->unk74, M2C_FIELD(temp_r4_347, const char **, 0));
        }
        var_r29_336 += 1;
        var_r30_337 += 0xC;
    }
    this->unk54 = arg5;
    this->unk4C = 0;
    this->unk50 = 0;
    temp_r30_381 = this->unk54 << 5;
    if (MKHeap::Current() != NULL) {
        var_r3_389 = (BoneBlurFX::BlurNode **) MKHeap::Current()->Alloc(temp_r30_381, NULL, 0);
    } else {
        var_r3_389 = malloc(temp_r30_381);
    }
    this->unk58 = var_r3_389;
    var_r6_395 = 0;
    var_r3_398 = 0;
    while (var_r6_395 < (s32) this->unk54) {
        var_r6_395 += 1;
        *(s32 *) ((u8 *) this->unk58 + var_r3_398) = 0;
        var_r3_398 += 4;
    }
}

void BoneBlurFX::Deinit() {
    BoneBlurFX::BlurNode **temp_r31_434;
    s32 *temp_r3_424;

    temp_r3_424 = this->unk78;
    if (temp_r3_424 != NULL) {
        *temp_r3_424 = 0;
    }
    this->unk78 = NULL;
    MKMaterial_Destroy(this->unk70);
    temp_r31_434 = this->unk58;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_434, NULL, 0);
    } else {
        free(temp_r31_434);
    }
    MKProp::Deinit();
}

void BoneBlurFX::Draw() {
    MKVector4 col;
    f32 var_f29;
    f32 var_f30_532;
    s32 var_r3_487;
    s32 var_r22_480;
    s32 var_r25_533;
    s32 var_r26_526;
    s32 var_r27_522;
    s32 var_r28_481;
    u8 *base;

    if (this->unk6C != 0 && this->unk58[0] != NULL) {
        CalcUVs();
        var_r22_480 = 0;
        var_r28_481 = this->unk4C - 1;
        if (var_r28_481 < 0) {
            var_r28_481 = this->unk54 - 1;
        }
        var_r3_487 = var_r28_481;
        while (var_r3_487 != (s32) this->unk50) {
            var_r3_487 -= 1;
            var_r22_480 += 1;
            if (var_r3_487 < 0) {
                var_r3_487 = this->unk54 - 1;
            }
        }
        var_f29 = 1.0f / (f32) var_r22_480;
        if ((s32) (var_r22_480 + 1) >= 2) {
            MKMaterial_SetMaterial(this->unk70);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            var_r27_522 = 0;
            while (var_r27_522 < (s32) this->unk60) {
                var_r26_526 = 1;
                while (var_r26_526 <= (s32) (this->unk5C[var_r27_522][0] - 1)) {
                    MKBegin((var_r22_480 + 1) * 2);
                    var_f30_532 = 1.0f;
                    var_r25_533 = var_r28_481;
                    while (var_r25_533 != (s32) this->unk50) {
                        col.unk0 = 1.0f;
                        col.unk4 = 1.0f;
                        col.unk8 = 1.0f;
                        col.unkC = var_f30_532;
                        MKSetColorV(col);
                        base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526] << 5);
                        MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                        MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[var_r25_533] + (this->unk5C[var_r27_522][var_r26_526] << 5)));
                        MKSetColorV(col);
                        base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5);
                        MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                        MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[var_r25_533] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5)));
                        var_r25_533 -= 1;
                        if (var_r25_533 < 0) {
                            var_r25_533 = this->unk54 - 1;
                        }
                        var_f30_532 -= var_f29;
                    }
                    col.unk0 = 1.0f;
                    col.unk4 = 1.0f;
                    col.unk8 = 1.0f;
                    col.unkC = var_f30_532;
                    MKSetColorV(col);
                    base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526] << 5);
                    MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                    MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[this->unk50] + (this->unk5C[var_r27_522][var_r26_526] << 5)));
                    MKSetColorV(col);
                    base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5);
                    MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                    MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[this->unk50] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5)));
                    MKEnd();
                    var_r26_526 += 1;
                }
                var_r27_522 += 1;
            }
            MKEndPrimitive();
        }
    }
}

void *BoneBlurFX::Update() {
    if (((u8) this->unk6C != 0) && ((u8) this->unk7C != 0)) {
        TakeFrameSnapshot();
    }
}

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
    this->unk70 = (MKMaterial *) (MKMaterial_Create("fx_boneblurmat"));
}

void BoneBlurFXDescriptor::DrawInstances() {
    void *var_r30_773;
    void *var_r31_768;
    void *var_r4_756;
    void *var_r4_787;

    var_r4_756 = (void *) (*BoneBlurFXDescriptor::pFirstDesc);
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

void BoneBlurFXDescriptor::Deinit() {
    BoneBlurFXDescriptor *temp_r4_822;
    BoneBlurFXDescriptor *temp_r4_828;

    if ((BoneBlurFXDescriptor *) *BoneBlurFXDescriptor::pFirstDesc == this) {
        *BoneBlurFXDescriptor::pFirstDesc = (unsigned char) (this->unk68);
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

#if 0 // DRAFT: pointer/array required
void BoneBlurFXDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk68 = (BoneBlurFXDescriptor *) (*BoneBlurFXDescriptor::pFirstDesc);
    this->unk64 = NULL;
    if ((BoneBlurFXDescriptor *) *BoneBlurFXDescriptor::pFirstDesc != NULL) {
        (*BoneBlurFXDescriptor::pFirstDesc)->unk64 = this;
    }
    *BoneBlurFXDescriptor::pFirstDesc = (unsigned char) (this);
    this->unk60 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}
#endif

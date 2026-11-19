#include "spyro/source/CustomMaterialUpdater.h"
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
#include <m2c_macros.h>

M2C_UNK free(CustomMaterialUpdater **);             /* extern */
CustomMaterialUpdater **malloc(M2C_UNK);            /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unksp5C'
void CustomMaterialUpdateManager::UpdateCameraRelativeScroll(CustomMaterialUpdater *arg0) {
    Matrix sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    CustomMaterialUpdater **temp_r7_20;
    f32 temp_f2_54;
    f32 temp_f2_69;
    f64 temp_f0_28;
    f64 temp_f5_23;
    f64 temp_f6_22;
    void *temp_r3_21;

    temp_r7_20 = arg0->unk8;
    temp_r3_21 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    temp_f6_22 = M2C_FIELD(temp_r3_21, f64 *, 0x30);
    temp_f5_23 = M2C_FIELD(temp_r3_21, f64 *, 0x38);
    sp50 = temp_f6_22;
    sp58 = temp_f5_23;
    temp_f0_28 = sp50 - M2C_FIELD(temp_r7_20, f64 *, 0);
    sp20 = temp_f0_28;
    M2C_FIELD(temp_r7_20, f64 *, 0) = temp_f6_22;
    sp40 = temp_f0_28;
    sp28 = (f32) sp58 - M2C_FIELD(temp_r7_20, f32 *, 8);
    M2C_FIELD(temp_r7_20, f32 *, 8) = temp_f5_23;
    sp48 = (f64) sp28;
    M2C_FIELD(temp_r7_20, f32 *, 0x14) = (f32) ((((f32) sp40 / 10000.0f) * M2C_FIELD(temp_r7_20, f32 *, 0x10)) + M2C_FIELD(temp_r7_20, f32 *, 0x14));
    M2C_FIELD(temp_r7_20, f32 *, 0x18) = (f32) -((((f32) sp48 / 10000.0f) * M2C_FIELD(temp_r7_20, f32 *, 0x10)) - M2C_FIELD(temp_r7_20, f32 *, 0x18));
    temp_f2_54 = M2C_FIELD(temp_r7_20, f32 *, 0x14);
    if (temp_f2_54 >= 5.0f) {
        M2C_FIELD(temp_r7_20, f32 *, 0x14) = (f32) (temp_f2_54 - 5.0f);
    } else if (temp_f2_54 <= -5.0f) {
        M2C_FIELD(temp_r7_20, f32 *, 0x14) = (f32) (temp_f2_54 + 5.0f);
    }
    temp_f2_69 = M2C_FIELD(temp_r7_20, f32 *, 0x18);
    if (temp_f2_69 >= 5.0f) {
        M2C_FIELD(temp_r7_20, f32 *, 0x18) = (f32) (temp_f2_69 - 5.0f);
    } else if (temp_f2_69 <= -5.0f) {
        M2C_FIELD(temp_r7_20, f32 *, 0x18) = (f32) (temp_f2_69 + 5.0f);
    }
    M2C_STRUCT_COPY((s32) &unksp5C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = M2C_FIELD(temp_r7_20, f32 *, 0x14);
    sp14 = M2C_FIELD(temp_r7_20, f32 *, 0x18);
    sp18 = 0.0f;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp60.unk30 = (f32) sp30;
    sp60.unk34 = (*(f32 *) ((u8 *) &sp30 + 0x4));
    sp60.unk38 = (f32) sp38;
    sp60.unk3C = 1.0f;
    MKMaterial_SetTextureMatrix(arg0->unk0, &sp60);
}
#endif

void CustomMaterialUpdateManager::Destroy(CustomMaterialUpdater *arg0) {
    CustomMaterialUpdater **temp_r31_134;
    CustomMaterialUpdater **temp_r3_158;
    CustomMaterialUpdater **var_r4_153;
    CustomMaterialUpdater *temp_r0_169;
    CustomMaterialUpdater *temp_r5_161;

    temp_r31_134 = arg0->unk8;
    if (temp_r31_134 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_134, NULL, 0);
        } else {
            free(temp_r31_134);
        }
        arg0->unk8 = NULL;
    }
    var_r4_153 = this->unk0;
loop_9:
    temp_r0_169 = *var_r4_153;
    if (temp_r0_169 == NULL) {
        return;
    }
    if (temp_r0_169 == arg0) {
        temp_r3_158 = this->unk0;
        this->unk0 = temp_r3_158 + 4;
        temp_r5_161 = *temp_r3_158;
        *temp_r3_158 = *var_r4_153;
        *var_r4_153 = temp_r5_161;
        return;
    }
    var_r4_153 += 4;
    goto loop_9;
}

CustomMaterialUpdater *CustomMaterialUpdateManager::Create(MKMaterial *arg0, int arg1) {
    f64 sp10;
    f64 sp8;
    CustomMaterialUpdater **temp_r4_220;
    CustomMaterialUpdater **temp_r6_187;
    CustomMaterialUpdater **temp_r6_194;
    CustomMaterialUpdater **var_r3_210;
    CustomMaterialUpdater *temp_r31_197;
    f64 temp_f0_228;
    f64 temp_f1_227;
    void *temp_r3_226;

    temp_r6_187 = this->unk0;
    if ((u32) M2C_FIELD(temp_r6_187, u32 *, -4) == 0U) {
        return NULL;
    }
    temp_r6_194 = temp_r6_187 - 4;
    this->unk0 = temp_r6_194;
    temp_r31_197 = *temp_r6_194;
    temp_r31_197->unk0 = arg0;
    temp_r31_197->unk4 = arg1;
    if (arg1 != 0) {

    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_210 = (CustomMaterialUpdater **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x20, NULL, 0));
        } else {
            var_r3_210 = malloc(0x20);
        }
        temp_r31_197->unk8 = var_r3_210;
        temp_r4_220 = temp_r31_197->unk8;
        M2C_FIELD(temp_r4_220, f32 *, 0x10) = 0.75f;
        M2C_FIELD(temp_r4_220, f32 *, 0x14) = 0.0f;
        M2C_FIELD(temp_r4_220, f32 *, 0x18) = 0.0f;
        temp_r3_226 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f1_227 = M2C_FIELD(temp_r3_226, f64 *, 0x30);
        temp_f0_228 = M2C_FIELD(temp_r3_226, f64 *, 0x38);
        sp8 = temp_f1_227;
        M2C_FIELD(temp_r4_220, f64 *, 0) = temp_f1_227;
        sp10 = temp_f0_228;
        M2C_FIELD(temp_r4_220, f64 *, 8) = temp_f0_228;
    }
    return temp_r31_197;
}

#if 0 // DRAFT: type mismatch 'CustomMaterialUpdater *' and 'CustomMaterialUpdater **'
void CustomMaterialUpdateManager::Deinit() {
    CustomMaterialUpdater **var_r31_252;
    CustomMaterialUpdater **var_r3_253;
    CustomMaterialUpdater **var_r4_251;
    CustomMaterialUpdater *temp_r0_256;
    CustomMaterialUpdater *temp_r0_275;
    u32 temp_r0_261;

    var_r4_251 = this->unk0;
    var_r31_252 = var_r4_251;
    var_r3_253 = var_r4_251;
loop_3:
    temp_r0_261 = M2C_FIELD(var_r3_253, u32 *, -4);
    var_r3_253 -= 4;
    if (temp_r0_261 != 0U) {
        temp_r0_256 = *var_r3_253;
        if (temp_r0_256 < var_r31_252) {
            var_r31_252 = (CustomMaterialUpdater **) temp_r0_256;
        }
        goto loop_3;
    }
    if (var_r3_253 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_275 = *var_r4_251;
        if (temp_r0_275 != NULL) {
            if (temp_r0_275 < var_r31_252) {
                var_r31_252 = (CustomMaterialUpdater **) temp_r0_275;
            }
            var_r4_251 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_252, NULL, 0);
        } else {
            free(var_r31_252);
        }
    }
    this->unk0 = NULL;
}
#endif

void CustomMaterialUpdateManager::Update() {
    CustomMaterialUpdater **var_r31_308;
    CustomMaterialUpdater *temp_r4_323;

    var_r31_308 = this->unk0;
loop_5:
    if (var_r31_308 != NULL) {
        temp_r4_323 = *var_r31_308;
        if (temp_r4_323 != NULL) {
            if ((s32) temp_r4_323->unk4 != 0) {

            } else {
                UpdateCameraRelativeScroll(temp_r4_323);
            }
            var_r31_308 += 4;
            goto loop_5;
        }
    }
}

void CustomMaterialUpdateManager::Init() {
    CustomMaterialUpdater **temp_r3_364;
    CustomMaterialUpdater **temp_r3_370;
    CustomMaterialUpdater **var_r3_349;
    CustomMaterialUpdater **var_r5_358;
    s32 var_ctr_362;

    if (MKHeap::Current() != NULL) {
        var_r3_349 = (CustomMaterialUpdater **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x58, NULL, 0));
    } else {
        var_r3_349 = malloc(0x58);
    }
    this->unk0 = var_r3_349;
    var_r5_358 = this->unk0;
    this->unk0 = var_r5_358 + 0x3C;
    M2C_FIELD(var_r5_358, s32 *, 0x3C) = 0;
    var_ctr_362 = 5;
    do {
        temp_r3_364 = this->unk0;
        this->unk0 = temp_r3_364 + 4;
        M2C_FIELD(temp_r3_364, CustomMaterialUpdater ***, 4) = var_r5_358;
        var_r5_358 += 0xC;
        var_ctr_362 -= 1;
    } while (var_ctr_362 != 0);
    temp_r3_370 = this->unk0;
    this->unk0 = temp_r3_370 + 4;
    M2C_FIELD(temp_r3_370, CustomMaterialUpdater ***, 4) = NULL;
}

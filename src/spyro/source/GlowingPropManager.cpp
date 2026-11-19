#include "spyro/source/GlowingPropManager.h"
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

M2C_UNK free(MKProp ***);                           /* extern */
MKProp ***malloc(M2C_UNK);                          /* extern */
extern M2C_UNK gEmptyPtrListDL;
#if 0 // DRAFT: identifier 'gGlowingPropManager' redeclared was declared as: 'GlowingPropManager' now declared as: 'MKProp'
extern MKProp gGlowingPropManager;
#endif
extern MKMaterial *gRenderState;

u8 GlowingPropManager::AddProp(MKProp *arg0) {
    s32 **temp_r5_18;
    void *temp_r5_11;

    temp_r5_11 = arg0->unk0;
    if ((u32) M2C_FIELD(temp_r5_11, u32 *, -4) == 0U) {
        return 0U;
    }
    temp_r5_18 = (long **) (((u8 *) temp_r5_11) - 4);
    arg0->unk0 = temp_r5_18;
    **temp_r5_18 = M2C_ERROR(/* Read from unset register $r4 */);
    return 1U;
}

void GlowingPropManager::Deinit() {
    MKProp ***var_r31_35;
    MKProp ***var_r3_36;
    MKProp ***var_r4_34;
    u32 temp_r0_39;
    u32 temp_r0_44;
    u32 temp_r0_58;

    var_r4_34 = this->unk0;
    var_r31_35 = var_r4_34;
    var_r3_36 = var_r4_34;
    goto test_3;
body_3:
    temp_r0_39 = *(u32 *) var_r3_36;
    if (temp_r0_39 < (u32) var_r31_35) {
        var_r31_35 = (MKProp ***) temp_r0_39;
    }
test_3:
    var_r3_36 = (MKProp ***) ((u8 *) var_r3_36 - 4);
    temp_r0_44 = M2C_FIELD(var_r3_36, u32 *, 0);
    if (temp_r0_44 != 0U) {
        goto body_3;
    }
    if ((s32 *) var_r3_36 != &gEmptyPtrListDL) {
        for (; (temp_r0_58 = *(u32 *) var_r4_34) != 0U; var_r4_34 = (MKProp ***) ((u8 *) var_r4_34 + 4)) {
            if (temp_r0_58 < (u32) var_r31_35) {
                var_r31_35 = (MKProp ***) temp_r0_58;
            }
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_35, NULL, 0);
        } else {
            free(var_r31_35);
        }
    }
    this->unk0 = NULL;
}

void GlowingPropManager::Draw() {
    MKProp ***var_r31_91;

    var_r31_91 = this->unk0;
    while (var_r31_91 != NULL && *var_r31_91 != NULL && **var_r31_91 != NULL) {
        (**var_r31_91)->Draw();
        var_r31_91 = (MKProp ***) ((u8 *) var_r31_91 + 4);
    }
    for (; *this->unk0 != NULL; this->unk0 = (MKProp ***) ((u8 *) this->unk0 + 4)) {
    }
}

void GlowingPropManager::Init() {
    MKProp ***temp_r3_155;
    MKProp ***temp_r3_161;
    MKProp ***var_r3_140;
    MKProp ***var_r5_149;
    s32 var_ctr_153;

    if (MKHeap::Current() != NULL) {
        var_r3_140 = (MKProp ***) (((MKHeap *) (MKHeap::Current()))->Alloc(0xA8, NULL, 0));
    } else {
        var_r3_140 = malloc(0xA8);
    }
    this->unk0 = var_r3_140;
    var_r5_149 = this->unk0;
    this->unk0 = var_r5_149 + 0x50;
    M2C_FIELD(var_r5_149, s32 *, 0x50) = 0;
    var_ctr_153 = 0x14;
    do {
        temp_r3_155 = this->unk0;
        this->unk0 = temp_r3_155 + 4;
        M2C_FIELD(temp_r3_155, MKProp ****, 4) = var_r5_149;
        var_r5_149 += 4;
        var_ctr_153 -= 1;
    } while (var_ctr_153 != 0);
    temp_r3_161 = this->unk0;
    this->unk0 = temp_r3_161 + 4;
    M2C_FIELD(temp_r3_161, MKProp ****, 4) = NULL;
}

void GlowingProp::EndGlowingPropDraw() {
    if ((u8) this->unk14 != 0) {
        gRenderState = NULL;
        MKMaterial_SetColor(this->unk10, *((MKVector4 *) this));
        this->unk14 = 0;
        return;
    }
    this->unk14 = 1;
}

void GlowingProp::BeginGlowingPropDraw(MKProp *arg0) {
    MKVector4 *color;
    MKVector4 sp10;
    MKVector4 sp20;
    f64 temp_f1_223;
    f64 temp_f1_229;
    f64 temp_f1_233;
    f32 sp8;
    f32 var_f0_308;
    f32 var_f1_292;
    f32 var_f30_219;
    f32 var_f31_318;
    s32 temp_r3_252;
    s32 var_r0_262;

    if ((u8) this->unk14 != 0) {
        var_f30_219 = arg0->unk24;
        if (var_f30_219 > 0.0f) {
            temp_f1_223 = __frsqrte(var_f30_219);
            temp_f1_229 = 0.5 * temp_f1_223 * -(((f64) var_f30_219 * (temp_f1_223 * temp_f1_223)) - 3.0);
            temp_f1_233 = 0.5 * temp_f1_229 * -(((f64) var_f30_219 * (temp_f1_229 * temp_f1_229)) - 3.0);
            var_f30_219 = (f32) ((f64) var_f30_219 * (0.5 * temp_f1_233 * -(((f64) var_f30_219 * (temp_f1_233 * temp_f1_233)) - 3.0)));
        } else if (var_f30_219 < 0.0f) {
            var_f30_219 = __float_nan;
        } else {
            sp8 = var_f30_219;
            temp_r3_252 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_252) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_262 = 1;
                } else {
                    var_r0_262 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_262 = 5;
                } else {
                    var_r0_262 = 3;
                }
                break;
            default:
                var_r0_262 = 4;
                break;
            }
            if (var_r0_262 == 1) {
                var_f30_219 = __float_nan;
            }
        }
        if ((var_f30_219 > 1500.0f) && (GlowingPropManager::AddProp((MKProp *) &gGlowingPropManager) != 0)) {
            var_f1_292 = var_f30_219 - 1500.0f;
            if (var_f1_292 < 1500.0f) {

            } else {
                var_f1_292 = 1500.0f;
            }
            if (var_f1_292 > 0.0f) {

            } else {
                var_f1_292 = 0.0f;
            }
            var_f0_308 = var_f1_292 / 1500.0f;
            if (var_f0_308 < 1.0f) {

            } else {
                var_f0_308 = 1.0f;
            }
            if (var_f0_308 > 0.0f) {
                var_f31_318 = var_f0_308;
            } else {
                var_f31_318 = 0.0f;
            }
            color = (MKVector4 *) MKMaterial_GetColor(this->unk10);
            *((MKVector4 *) this) = *color;
            sp10.unk0 = ((MKVector4 *) this)->unk0 * var_f31_318;
            sp10.unk4 = ((MKVector4 *) this)->unk4 * var_f31_318;
            sp10.unk8 = ((MKVector4 *) this)->unk8 * var_f31_318;
            sp10.unkC = ((MKVector4 *) this)->unkC * var_f31_318;
            sp20 = sp10;
            MKMaterial_SetColor(this->unk10, sp20);
            gRenderState = this->unk10;
        }
    }
}

void GlowingProp::Deinit() {
    MKMaterial_Destroy(this->unk10);
}

void GlowingProp::Init() {
    this->unk14 = 1;
    this->unk10 = (MKMaterial *) (MKMaterial_Create("fx_PropGlow"));
}

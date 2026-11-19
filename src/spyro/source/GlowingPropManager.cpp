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
extern GlowingPropManager gGlowingPropManager;
extern MKMaterial *gRenderState;

u8 GlowingPropManager::AddProp(MKProp *arg0) {
    MKProp ***temp_r5_11;
    MKProp ***temp_r5_18;

    temp_r5_11 = this->unk0;
    if ((u32) M2C_FIELD(temp_r5_11, u32 *, -4) == 0U) {
        return 0U;
    }
    temp_r5_18 = temp_r5_11 - 4;
    this->unk0 = temp_r5_18;
    **temp_r5_18 = arg0;
    return 1U;
}

#if 0 // DRAFT: type mismatch 'MKProp **' and 'MKProp ***'
void GlowingPropManager::Deinit() {
    MKProp ***var_r31_35;
    MKProp ***var_r3_36;
    MKProp ***var_r4_34;
    MKProp **temp_r0_39;
    MKProp **temp_r0_58;
    u32 temp_r0_44;

    var_r4_34 = this->unk0;
    var_r31_35 = var_r4_34;
    var_r3_36 = var_r4_34;
loop_3:
    temp_r0_44 = M2C_FIELD(var_r3_36, u32 *, -4);
    var_r3_36 -= 4;
    if (temp_r0_44 != 0U) {
        temp_r0_39 = *var_r3_36;
        if (temp_r0_39 < var_r31_35) {
            var_r31_35 = (MKProp ***) temp_r0_39;
        }
        goto loop_3;
    }
    if (var_r3_36 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_58 = *var_r4_34;
        if (temp_r0_58 != NULL) {
            if (temp_r0_58 < var_r31_35) {
                var_r31_35 = (MKProp ***) temp_r0_58;
            }
            var_r4_34 += 4;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_35, NULL, 0);
        } else {
            free(var_r31_35);
        }
    }
    this->unk0 = NULL;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void GlowingPropManager::Draw() {
    MKProp ***var_r31_91;
    MKProp **temp_r3_102;
    MKProp *temp_r3_105;

    var_r31_91 = this->unk0;
loop_2:
    if (var_r31_91 != NULL) {
        temp_r3_102 = *var_r31_91;
        if (temp_r3_102 != NULL) {
            temp_r3_105 = *temp_r3_102;
            if (temp_r3_105 == NULL) {

            } else {
                M2C_FIELD(temp_r3_105->__vptr, M2C_UNK (**)(), 0x28)();
                var_r31_91 += 4;
                goto loop_2;
            }
        }
    }
loop_7:
    if ((MKProp **) *this->unk0 != NULL) {
        this->unk0 += 4;
        goto loop_7;
    }
}
#endif

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

#if 0 // DRAFT: undefined identifier '__float_nan'
void GlowingProp::BeginGlowingPropDraw(MKProp *arg0) {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f0_308;
    f32 var_f1_292;
    f32 var_f30_219;
    f32 var_f31_318;
    f64 *temp_r3_324;
    f64 temp_f0_334;
    f64 temp_f1_223;
    f64 temp_f1_229;
    f64 temp_f1_233;
    s32 temp_r3_252;
    s32 var_r0_262;

    if ((u8) this->unk14 != 0) {
        var_f30_219 = arg0->unk24;
        if (var_f30_219 > 0.0f) {
            temp_f1_223 = __frsqrte(var_f30_219);
            temp_f1_229 = 0.5 * temp_f1_223 * -(((f64) var_f30_219 * (temp_f1_223 * temp_f1_223)) - 3.0);
            temp_f1_233 = 0.5 * temp_f1_229 * -(((f64) var_f30_219 * (temp_f1_229 * temp_f1_229)) - 3.0);
            var_f30_219 = (f32) ((f64) var_f30_219 * (0.5 * temp_f1_233 * -(((f64) var_f30_219 * (temp_f1_233 * temp_f1_233)) - 3.0)));
        } else if (var_f30_219 < M2C_BITWISE(f32, 0.0)) {
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
        if ((var_f30_219 > 1500.0f) && (gGlowingPropManager.AddProp(arg0) != 0)) {
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
            temp_r3_324 = MKMaterial_GetColor(this->unk10);
            this->unk0 = M2C_FIELD(temp_r3_324, f64 *, 0);
            this->unk8 = M2C_FIELD(temp_r3_324, f64 *, 8);
            sp10 = this->unk0 * (f64) var_f31_318;
            temp_f0_334 = this->unk8 * (f64) var_f31_318;
            sp18 = temp_f0_334;
            sp20 = sp10;
            sp28 = temp_f0_334;
            MKMaterial_SetColor(this->unk10, *((MKVector4 *) &sp20));
            gRenderState = this->unk10;
        }
    }
}
#endif

void GlowingProp::Deinit() {
    MKMaterial_Destroy(this->unk10);
}

void GlowingProp::Init() {
    this->unk14 = 1;
    this->unk10 = (MKMaterial *) (MKMaterial_Create("fx_PropGlow"));
}

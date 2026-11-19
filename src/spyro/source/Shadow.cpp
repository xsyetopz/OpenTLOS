#include "spyro/source/Shadow.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "unplaced_enums.h"
#include "common/Source/MKView.h"
#include "common/gc/MKShadow_GC.h"
#include <m2c_macros.h>

extern s32 beginEndRefCount;
extern void **gMK;
extern Shadow *pShadowList;
static u8 bShadowEnabled = 1;

void Shadow::Show(bool arg0) {
    MKModel *temp_r3_17;
    s16 temp_r31_22;
    s32 var_r30_23;

    this->unk2C = arg0;
    temp_r3_17 = this->unk10;
    if (temp_r3_17 != NULL) {
        temp_r31_22 = MKModel_GetNmbrOfSubObjects(temp_r3_17, (SubObjectType) 1);
        var_r30_23 = 0;
loop_3:
        if (var_r30_23 < temp_r31_22) {
            MKModel_EnableSubObject(this->unk10, (SubObjectType) 1, var_r30_23, this->unk2C, 1U);
            var_r30_23 += 1;
            goto loop_3;
        }
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Shadow::Draw() {
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f4_69;
    f64 temp_f0_72;
    f64 temp_f0_83;

    if (((MKProp *) this->unk14 == NULL) || (M2C_FIELD(*gMK, u8 (**)(void **, s32), 0x9C)(gMK, *MKResource::sWorkingChunkID) != 0)) {
        MKModel_CalculateCentre(this->unk10, &sp48);
        temp_f4_69 = this->unk20;
        temp_f0_72 = M2C_FIELD(this, f64 *, 0) * (f64) temp_f4_69;
        sp18 = temp_f0_72;
        sp28 = temp_f0_72;
        sp20 = this->unk8 * temp_f4_69;
        sp30 = (f64) sp20;
        temp_f0_83 = M2C_BITWISE(f64, sp48) - temp_f0_72;
        sp8 = temp_f0_83;
        sp38 = temp_f0_83;
        sp10 = sp48.unk8 - (f32) sp30;
        sp40 = (f64) sp10;
        MKShadow_Render(this->unk10, *((MKVector3 *) &sp38), 100.0f + (temp_f4_69 + (sp48.unk4 - this->unk28)), MKVector3::zero, NULL, 1U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Shadow::GetLightPos(MKVector3 *arg0) {
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;

    MKModel_CalculateCentre(this->unk10, &sp38);
    sp18.operator*(this->unk20);
    sp8 = M2C_BITWISE(f64, sp38) - M2C_BITWISE(f64, sp18);
    M2C_FIELD(arg0, f64 *, 0) = sp8;
    sp10 = sp38.unk8 - sp18.unk8;
    sp28 = sp8;
    sp30 = (f64) sp10;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp10;
}
#endif

void Shadow::Deinit() {
    Shadow *temp_r4_165;
    Shadow *var_r5_158;

    var_r5_158 = pShadowList;
    if ((Shadow *) pShadowList == this) {
        pShadowList = pShadowList->unk18;
        return;
    }
loop_6:
    if (var_r5_158 == NULL) {
        return;
    }
    temp_r4_165 = var_r5_158->unk18;
    if (temp_r4_165 == this) {
        var_r5_158->unk18 = temp_r4_165->unk18;
        return;
    }
    var_r5_158 = temp_r4_165;
    goto loop_6;
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void Shadow::Init(MKModel *arg0, MKProp *arg1, float arg2, MKVector3 *arg3, float arg4) {
    f32 spC;
    f32 sp8;
    MKHeap **temp_r3_317;
    f32 temp_f0_223;
    f32 temp_f0_319;
    f32 temp_f1_222;
    f32 temp_f1_318;
    f32 temp_f3_225;
    f32 temp_f3_321;
    f32 var_f1_297;
    f32 var_f4_230;
    f32 var_f4_326;
    f64 temp_f1_236;
    f64 temp_f1_242;
    f64 temp_f1_246;
    f64 temp_f1_329;
    f64 temp_f1_335;
    f64 temp_f1_339;
    s32 temp_r3_265;
    s32 temp_r3_358;
    s32 var_r0_275;
    s32 var_r0_368;

    if (MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 1) == 0) {
        this->unk10 = NULL;
        this->unk14 = NULL;
        return;
    }
    this->unk10 = arg0;
    this->unk14 = arg1;
    this->unk1C = arg2;
    this->unk0 = 1.0f;
    this->unk4 = -100.0f;
    this->unk8 = 0.0f;
    if (arg3 != NULL) {
        M2C_FIELD(this, f32 *, 0) = (f64) M2C_FIELD(arg3, f64 *, 0);
        M2C_FIELD(this, f32 *, 8) = (f64) M2C_FIELD(arg3, f64 *, 8);
    }
    temp_f1_222 = this->unk0;
    temp_f0_223 = this->unk4;
    temp_f3_225 = this->unk8;
    var_f4_230 = (temp_f3_225 * temp_f3_225) + ((temp_f1_222 * temp_f1_222) + (temp_f0_223 * temp_f0_223));
    if (var_f4_230 > 0.000001f) {
        if (var_f4_230 > 0.0f) {
            temp_f1_236 = __frsqrte(var_f4_230);
            temp_f1_242 = 0.5 * temp_f1_236 * -(((f64) var_f4_230 * (temp_f1_236 * temp_f1_236)) - 3.0);
            temp_f1_246 = 0.5 * temp_f1_242 * -(((f64) var_f4_230 * (temp_f1_242 * temp_f1_242)) - 3.0);
            var_f4_230 = (f32) ((f64) var_f4_230 * (0.5 * temp_f1_246 * -(((f64) var_f4_230 * (temp_f1_246 * temp_f1_246)) - 3.0)));
        } else if (var_f4_230 < M2C_BITWISE(f32, 0.0)) {
            var_f4_230 = __float_nan;
        } else {
            spC = var_f4_230;
            temp_r3_265 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_265) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_275 = 1;
                } else {
                    var_r0_275 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_275 = 5;
                } else {
                    var_r0_275 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_275 = 4;
                break;
            }
            if (var_r0_275 == 1) {
                var_f4_230 = __float_nan;
            }
        }
        var_f1_297 = 1.0f / var_f4_230;
    } else {
        var_f1_297 = 0.0f;
    }
    this->unk0 *= var_f1_297;
    this->unk4 *= var_f1_297;
    this->unk8 *= var_f1_297;
    this->unk20 = arg4;
    this->unk2C = 1;
    temp_r3_317 = MKModel_GetBoundingVolume(arg0, (SubObjectType) 0, -1);
    temp_f1_318 = M2C_FIELD(temp_r3_317, f32 *, 0x10);
    temp_f0_319 = M2C_FIELD(temp_r3_317, f32 *, 0x14);
    temp_f3_321 = M2C_FIELD(temp_r3_317, f32 *, 0x18);
    var_f4_326 = (temp_f3_321 * temp_f3_321) + ((temp_f1_318 * temp_f1_318) + (temp_f0_319 * temp_f0_319));
    if (var_f4_326 > 0.0f) {
        temp_f1_329 = __frsqrte(var_f4_326);
        temp_f1_335 = 0.5 * temp_f1_329 * -(((f64) var_f4_326 * (temp_f1_329 * temp_f1_329)) - 3.0);
        temp_f1_339 = 0.5 * temp_f1_335 * -(((f64) var_f4_326 * (temp_f1_335 * temp_f1_335)) - 3.0);
        var_f4_326 = (f32) ((f64) var_f4_326 * (0.5 * temp_f1_339 * -(((f64) var_f4_326 * (temp_f1_339 * temp_f1_339)) - 3.0)));
    } else if (var_f4_326 < M2C_BITWISE(f32, 0.0)) {
        var_f4_326 = __float_nan;
    } else {
        sp8 = var_f4_326;
        temp_r3_358 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_358) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_368 = 1;
            } else {
                var_r0_368 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_368 = 5;
            } else {
                var_r0_368 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_368 = 4;
            break;
        }
        if (var_r0_368 == 1) {
            var_f4_326 = __float_nan;
        }
    }
    this->unk24 = var_f4_326 * 0.5f;
    MKModel_GetPosition(arg0);
    this->unk28 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
    this->unk18 = pShadowList;
    pShadowList = this;
}
#endif

#if 0 // DRAFT: function call 'IsVisible(long, BoundingVolume *)' does not match
void Shadow_Draw() {
    Frustum sp8;
    M2C_UNK sp4;
    MKHeap **temp_r31_460;
    Shadow *var_r30_450;
    Shadow *var_r3_424;
    u8 var_r4_425;

    if (((u8) bShadowEnabled != 0) && ((Shadow *) pShadowList != NULL)) {
        var_r3_424 = pShadowList;
        var_r4_425 = 0;
loop_4:
        if ((var_r3_424 != NULL) && (var_r4_425 == 0)) {
            var_r4_425 = var_r3_424->unk2C;
            var_r3_424 = var_r3_424->unk18;
            goto loop_4;
        }
        if (var_r4_425 != 0) {
            Shadow_BeginDraw();
            M2C_STRUCT_COPY((s32) &sp4 + 4, MKView_GetWorldFrustum() - 4 + 4, 0x70);
            var_r30_450 = pShadowList;
loop_12:
            if (var_r30_450 != NULL) {
                if ((u8) var_r30_450->unk2C != 0) {
                    temp_r31_460 = MKModel_GetBoundingVolume(var_r30_450->unk10, (SubObjectType) 0, -1);
                    if (sp8.IsVisible(MKModel_GetWorldMatrix(var_r30_450->unk10), (BoundingVolume *) temp_r31_460) != 0) {
                        var_r30_450->Draw();
                    }
                }
                var_r30_450 = var_r30_450->unk18;
                goto loop_12;
            }
            Shadow_EndDraw();
        }
    }
}
#endif

void Shadow_EndDraw() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r0_492;

    temp_r0_492 = beginEndRefCount - 1;
    beginEndRefCount = temp_r0_492;
    if (temp_r0_492 == 0) {
        sp8 = 0.0f;
        spC = 0.0f;
        sp10 = 0.0f;
        sp14 = 0.5f;
        sp18 = (f64) sp8;
        sp20 = (f64) sp10;
        MKShadow_EndScene(1U, 0U, (MKVector4 *) &sp18);
    }
}

void Shadow_BeginDraw() {
    if ((s32) beginEndRefCount == 0) {
        MKShadow_BeginScene();
    }
    beginEndRefCount += 1;
}

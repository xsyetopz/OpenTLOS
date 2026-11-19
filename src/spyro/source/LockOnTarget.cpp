#include "spyro/source/LockOnTarget.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to 'float'
void LockOnTarget::Draw() {
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    Matrix spA0;
    f64 sp90;
    f64 sp88;
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f0_241;
    f32 temp_f11_264;
    f32 temp_f28_267;
    f32 temp_f29_265;
    f32 temp_f30_292;
    f32 temp_f31_256;
    f32 var_f4_161;
    f32 var_f5_228;
    f64 temp_f1_167;
    f64 temp_f1_173;
    f64 temp_f1_177;
    s32 temp_r3_196;
    s32 var_ctr_253;
    s32 var_r0_206;
    s32 var_r3_236;
    void *temp_r3_140;
    void *temp_r3_99;
    void *temp_r4_257;

    if ((s32) this->unk60 != 0) {
        if ((u8) this->unk78 == 0) {
            return;
        }
        temp_r3_99 = this->unk4C;
        sp48 = M2C_FIELD(temp_r3_99, f64 *, 0) + this->unk50;
        sp50 = M2C_FIELD(temp_r3_99, f32 *, 8) + this->unk58;
        spE0 = -35.0f;
        spE4 = -35.0f;
        spE8 = 0.0f;
        spF0 = 35.0f;
        spF4 = -35.0f;
        spF8 = 0.0f;
        sp100 = -35.0f;
        sp104 = 35.0f;
        sp108 = 0.0f;
        sp110 = 35.0f;
        sp114 = 35.0f;
        sp118 = 0.0f;
        sp88 = sp48;
        sp90 = (f64) sp50;
        spA0.SetRotationRoll(this->unk6C);
        spA0.Multiply3x3(&spA0, MKView_GetCameraMatrix());
        temp_r3_140 = MKView_GetCameraMatrix() + 0x30;
        sp38 = M2C_FIELD(temp_r3_140, f64 *, 0) - sp88;
        sp78 = sp38;
        sp40 = M2C_FIELD(temp_r3_140, f32 *, 8) - (f32) sp90;
        sp80 = (f64) sp40;
        var_f4_161 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + ((*(f32 *) ((u8 *) &sp70 + 0xc)) * (*(f32 *) ((u8 *) &sp70 + 0xc))));
        if (var_f4_161 > 0.000001f) {
            if (var_f4_161 > 0.0f) {
                temp_f1_167 = __frsqrte(var_f4_161);
                temp_f1_173 = 0.5 * temp_f1_167 * -(((f64) var_f4_161 * (temp_f1_167 * temp_f1_167)) - 3.0);
                temp_f1_177 = 0.5 * temp_f1_173 * -(((f64) var_f4_161 * (temp_f1_173 * temp_f1_173)) - 3.0);
                var_f4_161 = (f32) ((f64) var_f4_161 * (0.5 * temp_f1_177 * -(((f64) var_f4_161 * (temp_f1_177 * temp_f1_177)) - 3.0)));
            } else if (var_f4_161 < M2C_BITWISE(f32, 0.0)) {
                var_f4_161 = __float_nan;
            } else {
                sp10 = var_f4_161;
                temp_r3_196 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_196) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_206 = 1;
                    } else {
                        var_r0_206 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_206 = 5;
                    } else {
                        var_r0_206 = 3;
                    }
                    break;
                default:
                    var_r0_206 = 4;
                    break;
                }
                if (var_r0_206 == 1) {
                    var_f4_161 = __float_nan;
                }
            }
            var_f5_228 = 1.0f / var_f4_161;
        } else {
            var_f5_228 = 0.0f;
        }
        var_r3_236 = 0;
        temp_f0_241 = (f32) sp80 * var_f5_228;
        sp78 = (f32) sp78 * var_f5_228;
        (*(f32 *) ((u8 *) &sp70 + 0xc)) *= var_f5_228;
        sp80 = temp_f0_241;
        var_ctr_253 = 4;
        do {
            temp_f31_256 = this->unk64;
            temp_r4_257 = &spE0 + var_r3_236;
            M2C_FIELD(temp_r4_257, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_257, f64 *, 0) * (f64) temp_f31_256);
            M2C_FIELD(temp_r4_257, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_257, f32 *, 8) * temp_f31_256);
            temp_f11_264 = M2C_FIELD(temp_r4_257, f32 *, 4);
            temp_f29_265 = (f32) M2C_FIELD(temp_r4_257, f64 *, 0);
            temp_f28_267 = M2C_FIELD(temp_r4_257, f32 *, 8);
            sp28 = (temp_f28_267 * spA0.unk20) + ((temp_f29_265 * M2C_BITWISE(f32, spA0)) + (temp_f11_264 * spA0.unk10));
            sp2C = (temp_f28_267 * spA0.unk24) + ((temp_f29_265 * spA0.unk4) + (temp_f11_264 * spA0.unk14));
            sp30 = (temp_f28_267 * spA0.unk28) + ((temp_f29_265 * spA0.unk8) + (temp_f11_264 * spA0.unk18));
            M2C_FIELD(temp_r4_257, f64 *, 0) = (f64) sp28;
            M2C_FIELD(temp_r4_257, f32 *, 8) = (f64) sp30;
            sp68 = (f64) sp28;
            sp70 = (f64) sp30;
            M2C_FIELD(temp_r4_257, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_257, f64 *, 0) + sp88);
            M2C_FIELD(temp_r4_257, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_257, f32 *, 8) + (f32) sp90);
            temp_f30_292 = this->unk68;
            sp18 = (f64) sp78 * (f64) temp_f30_292;
            sp20 = temp_f0_241 * temp_f30_292;
            sp58 = sp18;
            sp60 = (f64) sp20;
            M2C_FIELD(temp_r4_257, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_257, f64 *, 0) + sp58);
            var_r3_236 += 0x10;
            M2C_FIELD(temp_r4_257, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_257, f32 *, 8) + (f32) sp60);
            var_ctr_253 -= 1;
        } while (var_ctr_253 != 0);
        if ((u8) this->unk79 != 0) {
            MKMaterial_SetMaterial(M2C_FIELD(checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x60));
        } else {
            MKMaterial_SetMaterial(M2C_FIELD(checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x64));
        }
        MKPrimitive(0xC, 9);
        MKBegin(4);
        MKSetColorF(1.0f, 1.0f, 1.0f, this->unk74);
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &spE0));
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &spF0));
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &sp100));
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &sp110));
        MKEnd();
        MKEndPrimitive();
    }
}
#endif

void *LockOnTarget::Update() {
    LockOnTargetDescriptor *desc;
    f32 temp_f1_451;

    switch (this->unk60) {
    case 1:
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk64 = -((4.0f * gUpdateTimeDelta * desc->unk68) - this->unk64);
        this->unk6C += 1.570796f * gUpdateTimeDelta;
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (this->unk64 <= desc->unk68) {
            this->unk60 = 2;
            desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            this->unk64 = desc->unk68;
        }
        return;
    case 3:
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk74 = -((2.0f * gUpdateTimeDelta * desc->unk68) - this->unk74);
        if (this->unk74 < 0.0f) {
            this->unk60 = 0;
            Disable();
        }
        /* fallthrough */
    case 2:
        this->unk70 += 3.1415927f * gUpdateTimeDelta;
        temp_f1_451 = this->unk70;
        if (temp_f1_451 > 6.2831855f) {
            this->unk70 = temp_f1_451 - 6.2831855f;
        }
        desc = checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk64 = (0.07f * _table_sinf(this->unk70)) + desc->unk68;
        break;
    }
}

#if 0 // DRAFT: ')' expected
void LockOnTarget::Init() {
    f32 temp_f2_498;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk60 = 0;
    temp_f2_498 = 3.0f * M2C_FIELD(checked_cast<LockOnTargetDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x68);
    this->unk64 = temp_f2_498;
    this->unk68 = 0.0f;
    this->unk70 = 0.0f;
    this->unk74 = 1.0f;
    this->unk78 = 1;
    Disable(0.0f, temp_f2_498);
}
#endif

void LockOnTargetDescriptor::Deinit() {
    MKMaterial_Destroy(this->unk60);
    MKMaterial_Destroy(this->unk64);
    MKPropDescriptor::Deinit();
}

void LockOnTargetDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
    this->unk60 = (MKMaterial *) (MKMaterial_Create("crosshair"));
    this->unk64 = (MKMaterial *) (MKMaterial_Create("Fx_159"));
}

#include "spyro/source/Coronas.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/gc/System_GC.h"
#include "unplaced_templates.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/EventCamera.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern M2C_UNK gb;

#if 0 // DRAFT: illegal type
void Coronas::Free(Corona *arg0) {
    MKZRequest *temp_r3_54;
    s32 temp_r3_64;
    s32 var_ctr_48;
    s32 var_r31_47;
    void *temp_r3_51;
    void *temp_r4_63;

    var_r31_47 = 0;
    var_ctr_48 = 0x46;
loop_1:
    temp_r3_51 = this->unk4C + var_r31_47;
    if (temp_r3_51 == arg0) {
        temp_r3_54 = M2C_FIELD(temp_r3_51, MKZRequest **, 0x20);
        if (temp_r3_54 != NULL) {
            MKZRequest_Destroy(temp_r3_54);
            M2C_FIELD((this->unk4C + var_r31_47), s32 *, 0x20) = 0;
        }
        temp_r4_63 = this->unk4C;
        temp_r3_64 = var_r31_47 + 0x31;
        *(temp_r4_63 + temp_r3_64) = *(temp_r4_63 + temp_r3_64) & ~0x80;
        return;
    }
    var_r31_47 += 0x38;
    var_ctr_48 -= 1;
    if (var_ctr_48 == 0) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal type
void *Coronas::Alloc(const MKVector3 &arg0, const MKVector4 &arg1, const float &arg2, const int &arg3, const bool &arg4) {
    s32 temp_r3_150;
    s32 temp_r3_163;
    s32 temp_r7_102;
    s32 var_ctr_92;
    s32 var_r29_91;
    u8 temp_r4_106;
    void *temp_r3_112;
    void *temp_r3_123;
    void *temp_r3_130;
    void *temp_r3_141;
    void *temp_r3_95;
    void *temp_r4_162;
    void *temp_r5_139;

    var_r29_91 = 0;
    var_ctr_92 = 0x46;
loop_1:
    temp_r3_95 = this->unk4C + var_r29_91;
    if (!(((u8) M2C_FIELD(temp_r3_95, u8 *, 0x31) >> 7U) & 1)) {
        temp_r7_102 = var_r29_91 + 0x31;
        M2C_FIELD(temp_r3_95, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        temp_r4_106 = &arg4;
        M2C_FIELD(temp_r3_95, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        temp_r3_112 = this->unk4C + (var_r29_91 + 0x10);
        M2C_FIELD(temp_r3_112, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r3_112, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD((this->unk4C + var_r29_91), f32 *, 0x24) = (f32) &arg2;
        M2C_FIELD((this->unk4C + var_r29_91), s8 *, 0x30) = (s8) &arg3;
        temp_r3_123 = this->unk4C;
        *(temp_r3_123 + temp_r7_102) = *(temp_r3_123 + temp_r7_102) | 0x40;
        M2C_FIELD((this->unk4C + var_r29_91), f32 *, 0x2C) = 0.0f;
        temp_r3_130 = this->unk4C;
        *(temp_r3_130 + temp_r7_102) = (*(temp_r3_130 + temp_r7_102) & ~0x20) | ((temp_r4_106 << 5) & 0x20);
        if (temp_r4_106 != 0) {
            M2C_FIELD((this->unk4C + var_r29_91), void **, 0x20) = MKZRequest_Create();
            temp_r5_139 = this->unk4C;
            temp_r3_141 = M2C_FIELD((temp_r5_139 + var_r29_91), void **, 0x20);
            if (temp_r3_141 != NULL) {
                M2C_FIELD(temp_r3_141, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
                M2C_FIELD(temp_r3_141, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            } else {
                temp_r3_150 = var_r29_91 + 0x31;
                *(temp_r5_139 + temp_r3_150) = *(temp_r5_139 + temp_r3_150) & ~0x20;
            }
        } else {
            M2C_FIELD((this->unk4C + var_r29_91), s32 *, 0x20) = 0;
        }
        temp_r4_162 = this->unk4C;
        temp_r3_163 = var_r29_91 + 0x31;
        *(temp_r4_162 + temp_r3_163) = *(temp_r4_162 + temp_r3_163) | 0x80;
        return this->unk4C + var_r29_91;
    }
    var_r29_91 += 0x38;
    var_ctr_92 -= 1;
    if (var_ctr_92 == 0) {
        return NULL;
    }
    goto loop_1;
}
#endif

void Coronas::Update() {
    MKProp::Update();
}

#if 0 // DRAFT: undefined identifier 'arg_spC'
void Coronas::Draw() {
    Corona *temp_r4_226;
    s32 var_r29_222;
    s32 var_r31_223;
    u8 temp_r30_209;
    u8 temp_r3_227;
    temp_r30_209 = EventCamera_GetCurrent() != NULL;
    M2C_STRUCT_COPY((s32) &arg_spC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    var_r29_222 = 0;
    var_r31_223 = 0;
    do {
        temp_r4_226 = this->unk4C + var_r31_223;
        temp_r3_227 = temp_r4_226->unk31;
        if (((temp_r3_227 >> 7U) & 1) && ((temp_r3_227 >> 6U) & 1) && ((temp_r30_209 == 0) || ((temp_r3_227 >> 4U) & 1))) {
            DrawCorona(temp_r4_226, (Matrix *) &arg_sp10);
        }
        var_r29_222 += 1;
        var_r31_223 += 0x38;
    } while (var_r29_222 < 0x46);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'CoronasDescriptor *' to
void Coronas::DrawCorona(Corona *arg0, Matrix *arg1) {
    MKZRequest *temp_r3_285;
    f32 temp_f31_317;
    f32 temp_f4_625;
    f32 temp_f5_624;
    f32 temp_f6_622;
    f32 var_f2_307;
    f32 var_f3_613;
    f32 var_f4_451;
    f32 var_f6_524;
    f32 var_f7_542;
    f64 temp_f1_463;
    f64 temp_f1_469;
    f64 temp_f1_473;
    f64 temp_f1_552;
    f64 temp_f1_558;
    f64 temp_f1_562;
    s32 temp_r27_323;
    s32 temp_r31_319;
    s32 temp_r31_338;
    s32 temp_r3_492;
    s32 temp_r3_581;
    s32 var_r0_502;
    s32 var_r0_591;
    s8 temp_r31_330;
    u32 temp_r0_296;
    if (((u8) arg0->unk31 >> 5U) & 1) {
        temp_r3_285 = arg0->unk20;
        if (temp_r3_285 != NULL) {
            M2C_FIELD(temp_r3_285, f64 *, 0) = (f64) arg0->unk0;
            M2C_FIELD(temp_r3_285, f64 *, 8) = (f64) arg0->unk8;
            MKZRequest_CheckRequest(arg0->unk20);
        }
    }
    temp_r0_296 = ((u8) arg0->unk31 >> 5U) & 1;
    if ((temp_r0_296 == 0) || (arg0->unk20->unk10 != 0.0f)) {
        if (temp_r0_296 != 0) {
            var_f2_307 = arg0->unk20->unk10;
        } else {
            var_f2_307 = 1.0f;
        }
        arg0->unk28 = var_f2_307;
        temp_f31_317 = 100.0f * arg0->unk24 * var_f2_307;
        temp_r31_319 = checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r27_323 = checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_r31_330 = MKMaterial_GetParameter(M2C_FIELD((temp_r31_319 + (arg0->unk30 * 4)), MKMaterial **, 0x60), (MKMaterialParameter) 5);
        temp_r31_338 = (MKMaterial_GetParameter(M2C_FIELD((temp_r27_323 + (arg0->unk30 * 4)), MKMaterial **, 0x60), (MKMaterialParameter) 4) * 2) | temp_r31_330;
        if (((u8) arg0->unk31 >> 5U) & 1) {
            MKMaterial_SetParameter(M2C_FIELD((checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0->unk30 * 4)), MKMaterial **, 0x60), (MKMaterialParameter) 5, 0);
            MKMaterial_SetParameter(M2C_FIELD((checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0->unk30 * 4)), MKMaterial **, 0x60), (MKMaterialParameter) 4, 0);
        }
        MKMaterial_SetMaterial(M2C_FIELD((checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0->unk30 * 4)), MKMaterial **, 0x60));
        arg_spD0 = 0.0f;
        arg_spC0 = 0.0f;
        arg_spC8 = 0.0f;
        arg_spCC = 1.0f;
        arg_spB8 = 1.0f;
        arg_spBC = 0.0f;
        arg_sp208 = (f64) arg_spC8;
        arg_sp210 = (f64) arg_spD0;
        arg_sp1F8 = (f64) arg_spB8;
        arg_sp200 = (f64) arg_spC0;
        arg_sp260.SetIdentity();
        arg_sp260.RotateRoll((Matrix *) &arg_sp260, arg0->unk2C);
        arg_spA8 = arg_sp290 + (((f32) arg_sp210 * arg_sp280) + (((f32) arg_sp208 * arg_sp260) + (arg_sp20C * arg_sp270)));
        arg_spAC = arg_sp294 + (((f32) arg_sp210 * arg_sp284) + (((f32) arg_sp208 * arg_sp264) + (arg_sp20C * arg_sp274)));
        arg_spB0 = arg_sp298 + (((f32) arg_sp210 * arg_sp288) + (((f32) arg_sp208 * arg_sp268) + (arg_sp20C * arg_sp278)));
        arg_sp208 = (f64) arg_spA8;
        arg_sp210 = (f64) arg_spB0;
        arg_sp98 = arg_sp290 + (((f32) arg_sp200 * arg_sp280) + (((f32) arg_sp1F8 * arg_sp260) + (arg_sp1FC * arg_sp270)));
        arg_sp9C = arg_sp294 + (((f32) arg_sp200 * arg_sp284) + (((f32) arg_sp1F8 * arg_sp264) + (arg_sp1FC * arg_sp274)));
        arg_spA0 = arg_sp298 + (((f32) arg_sp200 * arg_sp288) + (((f32) arg_sp1F8 * arg_sp268) + (arg_sp1FC * arg_sp278)));
        var_f4_451 = ((f32) arg_sp210 * (f32) arg_sp210) + (((f32) arg_sp208 * (f32) arg_sp208) + (arg_sp20C * arg_sp20C));
        arg_sp1E8 = (f64) arg_spA8;
        arg_sp1F0 = (f64) arg_spB0;
        arg_sp1D8 = (f64) arg_sp98;
        arg_sp1E0 = (f64) arg_spA0;
        arg_sp1F8 = (f64) arg_sp98;
        arg_sp200 = (f64) arg_spA0;
        if (var_f4_451 > 0.000001f) {
            if (var_f4_451 > 0.0f) {
                temp_f1_463 = __frsqrte(var_f4_451);
                temp_f1_469 = 0.5 * temp_f1_463 * -(((f64) var_f4_451 * (temp_f1_463 * temp_f1_463)) - 3.0);
                temp_f1_473 = 0.5 * temp_f1_469 * -(((f64) var_f4_451 * (temp_f1_469 * temp_f1_469)) - 3.0);
                var_f4_451 = (f32) ((f64) var_f4_451 * (0.5 * temp_f1_473 * -(((f64) var_f4_451 * (temp_f1_473 * temp_f1_473)) - 3.0)));
            } else if (var_f4_451 < M2C_BITWISE(f32, 0.0)) {
                var_f4_451 = __float_nan;
            } else {
                arg_sp14 = var_f4_451;
                temp_r3_492 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_492) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_502 = 1;
                    } else {
                        var_r0_502 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_502 = 5;
                    } else {
                        var_r0_502 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_502 = 4;
                    break;
                }
                if (var_r0_502 == 1) {
                    var_f4_451 = __float_nan;
                }
            }
            var_f6_524 = 1.0f / var_f4_451;
        } else {
            var_f6_524 = 0.0f;
        }
        var_f7_542 = ((f32) arg_sp200 * (f32) arg_sp200) + (((f32) arg_sp1F8 * (f32) arg_sp1F8) + (arg_sp1FC * arg_sp1FC));
        arg_sp208 = (f32) arg_sp208 * var_f6_524;
        arg_sp20C *= var_f6_524;
        arg_sp210 = (f32) arg_sp210 * var_f6_524;
        if (var_f7_542 > 0.000001f) {
            if (var_f7_542 > 0.0f) {
                temp_f1_552 = __frsqrte(var_f7_542);
                temp_f1_558 = 0.5 * temp_f1_552 * -(((f64) var_f7_542 * (temp_f1_552 * temp_f1_552)) - 3.0);
                temp_f1_562 = 0.5 * temp_f1_558 * -(((f64) var_f7_542 * (temp_f1_558 * temp_f1_558)) - 3.0);
                var_f7_542 = (f32) ((f64) var_f7_542 * (0.5 * temp_f1_562 * -(((f64) var_f7_542 * (temp_f1_562 * temp_f1_562)) - 3.0)));
            } else if (var_f7_542 < M2C_BITWISE(f32, 0.0)) {
                var_f7_542 = __float_nan;
            } else {
                arg_sp10 = var_f7_542;
                temp_r3_581 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_581) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_591 = 1;
                    } else {
                        var_r0_591 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_591 = 5;
                    } else {
                        var_r0_591 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_591 = 4;
                    break;
                }
                if (var_r0_591 == 1) {
                    var_f7_542 = __float_nan;
                }
            }
            var_f3_613 = 1.0f / var_f7_542;
        } else {
            var_f3_613 = 0.0f;
        }
        temp_f6_622 = (f32) arg_sp1F8 * var_f3_613;
        temp_f5_624 = arg_sp1FC * var_f3_613;
        temp_f4_625 = (f32) arg_sp200 * var_f3_613;
        arg_sp1F8 = temp_f6_622;
        arg_sp48 = -temp_f6_622;
        arg_sp4C = -temp_f5_624;
        arg_sp50 = -temp_f4_625;
        arg_sp1FC = temp_f5_624;
        arg_sp200 = temp_f4_625;
        arg_sp198 = (f64) arg_sp48;
        arg_sp1A0 = (f64) arg_sp50;
        arg_sp1A8.operator*(temp_f31_317);
        arg_sp1B8.operator*(temp_f31_317);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp1C8 = arg_sp88;
        arg_sp90 = arg_sp1C0 + arg_sp1B0;
        arg_sp218 = arg_sp88;
        arg_sp1D0 = (f64) arg_sp90;
        arg_sp220 = (f64) arg_sp90;
        arg_sp168.operator*(temp_f31_317);
        arg_sp178.operator*(temp_f31_317);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp38 = -(f32) arg_sp1F8;
        arg_sp3C = -arg_sp1FC;
        arg_sp80 = arg_sp180 + arg_sp170;
        arg_sp40 = -(f32) arg_sp200;
        arg_sp188 = arg_sp78;
        arg_sp190 = (f64) arg_sp80;
        arg_sp228 = arg_sp78;
        arg_sp230 = (f64) arg_sp80;
        arg_sp118 = (f64) arg_sp38;
        arg_sp120 = (f64) arg_sp40;
        arg_sp128.operator*(temp_f31_317);
        arg_sp28 = -(f32) arg_sp208;
        arg_sp2C = -arg_sp20C;
        arg_sp30 = -(f32) arg_sp210;
        arg_sp138 = (f64) arg_sp28;
        arg_sp140 = (f64) arg_sp30;
        arg_sp148.operator*(temp_f31_317);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp158 = arg_sp68;
        arg_sp70 = arg_sp150 + arg_sp130;
        arg_sp238 = arg_sp68;
        arg_sp160 = (f64) arg_sp70;
        arg_sp240 = (f64) arg_sp70;
        arg_spD8.operator*(temp_f31_317);
        arg_sp18 = -(f32) arg_sp208;
        arg_sp1C = -arg_sp20C;
        arg_sp20 = -(f32) arg_sp210;
        arg_spE8 = (f64) arg_sp18;
        arg_spF0 = (f64) arg_sp20;
        arg_spF8.operator*(temp_f31_317);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp248 = arg_sp58;
        arg_sp60 = arg_sp100 + arg_spE0;
        arg_sp108 = arg_sp58;
        arg_sp250 = (f64) arg_sp60;
        arg_sp110 = (f64) arg_sp60;
        arg1->unk30 = (f32) M2C_FIELD(arg0, f64 *, 0);
        arg1->unk34 = M2C_FIELD(arg0, f32 *, 4);
        arg1->unk38 = (f32) M2C_FIELD(arg0, f64 *, 8);
        arg1->unk3C = 1.0f;
        MKPrimitive(0xC, 0);
        MKSetMatrix(*arg1);
        MKBegin(4);
        MKSetColorV(arg0->unk10);
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp218));
        MKSetColorV(arg0->unk10);
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp228));
        MKSetColorV(arg0->unk10);
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp238));
        MKSetColorV(arg0->unk10);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionV(*((MKVector3 *) &arg_sp248));
        MKEnd();
        MKEndPrimitive();
        MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
        MKMaterial_SetParameter(M2C_FIELD((checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0->unk30 * 4)), MKMaterial **, 0x60), (MKMaterialParameter) 4, temp_r31_338 >> 1);
        MKMaterial_SetParameter(M2C_FIELD((checked_cast<CoronasDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (arg0->unk30 * 4)), MKMaterial **, 0x60), (MKMaterialParameter) 5, temp_r31_338 & 1);
    }
}
#endif

void Coronas::Deinit() {
    MKHeap *temp_r3_875;
    void *temp_r31_872;

    MKProp::Deinit();
    temp_r31_872 = this->unk4C;
    if (temp_r31_872 != NULL) {
        temp_r3_875 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_875 != NULL) {
            ((MKHeap *) (temp_r3_875->Current()))->Free(temp_r31_872, NULL, 0);
        } else {
            free(temp_r31_872);
        }
        this->unk4C = NULL;
    }
}

void Coronas::Reset() {
    MKProp::Reset();
}

void Coronas::Resolve() {

}

#if 0 // DRAFT: illegal type
void Coronas::LoadDone() {
    MKHeap *temp_r3_926;
    s32 temp_r0_953;
    s32 temp_r4_950;
    s32 temp_r5_949;
    s32 temp_r7_948;
    s32 var_ctr_944;
    s32 var_r3_942;
    s8 temp_r6_952;
    void *temp_r5_964;
    void *temp_r6_958;
    void *temp_r8_947;
    void *var_r3_933;

    MKProp::LoadDone();
    temp_r3_926 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_926 != NULL) {
        var_r3_933 = ((MKHeap *) (temp_r3_926->Current()))->Alloc(0xF50, NULL, 0);
    } else {
        var_r3_933 = malloc(0xF50);
    }
    this->unk4C = var_r3_933;
    var_r3_942 = 0;
    var_ctr_944 = 0x46;
    do {
        temp_r8_947 = this->unk4C;
        temp_r7_948 = var_r3_942 + 0x31;
        temp_r5_949 = var_r3_942 + 0x20;
        temp_r4_950 = var_r3_942 + 0x28;
        temp_r6_952 = *(temp_r8_947 + temp_r7_948) & ~0x80;
        temp_r0_953 = var_r3_942 + 0x2C;
        var_r3_942 += 0x38;
        *(temp_r8_947 + temp_r7_948) = temp_r6_952;
        *(this->unk4C + temp_r5_949) = 0;
        temp_r6_958 = this->unk4C;
        *(temp_r6_958 + temp_r7_948) = *(temp_r6_958 + temp_r7_948) & ~0x20;
        *(this->unk4C + temp_r4_950) = 1.0f;
        temp_r5_964 = this->unk4C;
        *(temp_r5_964 + temp_r7_948) = *(temp_r5_964 + temp_r7_948) & ~0x40;
        *(this->unk4C + temp_r0_953) = 0.0f;
        var_ctr_944 -= 1;
    } while (var_ctr_944 != 0);
}
#endif

#if 0 // DRAFT: identifier 'Coronas::LoadLine(MKIniLine *)' redeclared
void Coronas::LoadLine(MKIniLine *arg0) {
    MKProp::LoadLine(arg0);
}
#endif

void Coronas::Init() {
    MKProp::Init();
    this->unk4C = NULL;
}

void CoronasDescriptor::LoadDone() {
    MKPropDescriptor::LoadDone();
}

#if 0 // DRAFT: illegal implicit conversion from 'CoronasDescriptor' to
void CoronasDescriptor::Deinit() {
    MKMaterial *temp_r3_1035;
    s32 var_r30_1031;
    s32 var_r31_1032;

    MKPropDescriptor::Deinit();
    var_r30_1031 = 0;
    var_r31_1032 = 0;
    do {
        temp_r3_1035 = *(this + (var_r31_1032 + 0x60));
        if (temp_r3_1035 != NULL) {
            MKMaterial_Destroy(temp_r3_1035);
        }
        var_r30_1031 += 1;
        var_r31_1032 += 4;
    } while (var_r30_1031 < 3);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void CoronasDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("fx_002");
    this->unk64 = MKMaterial_Create("fx_317");
    this->unk68 = MKMaterial_Create("fx_174");
}
#endif

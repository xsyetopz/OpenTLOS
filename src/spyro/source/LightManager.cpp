#include "spyro/source/LightManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/OmniLight.h"
#include "spyro/source/ManagedLight.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk34'
M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */

void LightManager::EnableLight(ManagedLight *arg0, bool arg1) {
    f32 temp_f3_74;
    s32 var_ctr_111;
    s32 var_r3_110;
    s32 var_r4_109;
    void *temp_r3_53;
    void *temp_r3_76;
    void *temp_r3_85;
    void *temp_r3_90;
    void *temp_r3_95;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x44) >= 0) {
        arg0->unk34 = arg1;
        if (arg1 == 0) {
            temp_r3_53 = arg0->unk3C;
            if (temp_r3_53 != NULL) {
                OmniLight_Destroy((OmniLight *) temp_r3_53);
            }
            arg0->unk3C = NULL;
            M2C_FIELD((this + (M2C_FIELD(arg0, s32 *, 0x44) * 4)), s32 *, 0x4C) = 0;
            M2C_FIELD(arg0, s32 *, 0x44) = -1;
            return;
        }
        if ((void *) arg0->unk3C == NULL) {
            OmniLight_Create();
            arg0->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        temp_f3_74 = arg0->unk38;
        temp_r3_76 = arg0->unk3C;
        M2C_FIELD(temp_r3_76, f32 *, 0x20) = temp_f3_74;
        M2C_FIELD(temp_r3_76, f32 *, 0x24) = (f32) (temp_f3_74 * temp_f3_74);
        M2C_FIELD(temp_r3_76, f32 *, 0x28) = (f32) (1.0f / temp_f3_74);
        M2C_FIELD(temp_r3_76, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_76, f32 *, 0x24));
        temp_r3_85 = arg0->unk3C;
        M2C_FIELD(temp_r3_85, f64 *, 0) = (f64) arg0->unk20;
        M2C_FIELD(temp_r3_85, f64 *, 8) = (f64) arg0->unk28;
        temp_r3_90 = arg0->unk3C;
        M2C_FIELD(temp_r3_90, f64 *, 0x10) = (f64) arg0->unk10;
        M2C_FIELD(temp_r3_90, f64 *, 0x18) = (f64) arg0->unk18;
        temp_r3_95 = arg0->unk3C;
        if ((u8) M2C_FIELD(temp_r3_95, u8 *, 0x30) != 1) {
            M2C_FIELD(temp_r3_95, u8 *, 0x30) = 1U;
            *OmniLight::totalEnabled += 1;
        }
    } else if (arg1 != 0) {
        var_r4_109 = 0;
        var_r3_110 = 0;
        var_ctr_111 = 4;
loop_11:
        if ((u32) *(this + (var_r3_110 + 0x4C)) == 0U) {
            M2C_FIELD(arg0, s32 *, 0x44) = var_r4_109;
            M2C_FIELD((this + var_r3_110), ManagedLight **, 0x4C) = arg0;
            EnableLight(arg0, arg1);
            return;
        }
        var_r4_109 += 1;
        var_r3_110 += 4;
        var_ctr_111 -= 1;
        if (var_ctr_111 == 0) {

        } else {
            goto loop_11;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34'
void LightManager::FreeManagedLight(ManagedLight *arg0) {
    s32 temp_r0_156;
    void *temp_r3_149;

    if (arg0 != NULL) {
        arg0->unk34 = 0;
        M2C_FIELD(arg0, s8 *, 0x48) = 0;
        temp_r3_149 = arg0->unk3C;
        if (temp_r3_149 != NULL) {
            OmniLight_Destroy((OmniLight *) temp_r3_149);
            arg0->unk3C = NULL;
        }
        temp_r0_156 = M2C_FIELD(arg0, s32 *, 0x44);
        if (temp_r0_156 >= 0) {
            M2C_FIELD((this + (temp_r0_156 * 4)), s32 *, 0x4C) = 0;
            M2C_FIELD(arg0, s32 *, 0x44) = -1;
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void LightManager::CalculateLightPosForShadow(const MKVector3 &arg0) {
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f3_296;
    f32 temp_f7_294;
    f32 var_f5_283;
    f32 var_f6_216;
    f64 temp_f2_222;
    f64 temp_f2_228;
    f64 temp_f2_232;
    s32 temp_r6_251;
    s32 temp_r8_185;
    s32 var_ctr_183;
    s32 var_r0_261;
    s32 var_r5_180;
    void *temp_r6_186;

    var_r5_180 = 0;
    sp50 = *M2C_ERROR(/* Read from unset register $r5 */);
    sp58 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f64 *, 8);
    var_ctr_183 = 4;
    do {
        temp_r8_185 = var_r5_180 + 0x4C;
        temp_r6_186 = *(&arg0 + temp_r8_185);
        if ((temp_r6_186 != NULL) && ((u8) M2C_FIELD(temp_r6_186, u8 *, 0x34) != 0) && ((u8) M2C_FIELD(temp_r6_186, u8 *, 0x40) != 0)) {
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r6, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
            sp40 = sp20;
            sp28 = M2C_FIELD((temp_r6_186 + 0x10), f32 *, 8) - (f32) sp58;
            sp48 = (f64) sp28;
            var_f6_216 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
            if (var_f6_216 > 0.000001f) {
                if (var_f6_216 > 0.0f) {
                    temp_f2_222 = __frsqrte(var_f6_216);
                    temp_f2_228 = 0.5 * temp_f2_222 * -(((f64) var_f6_216 * (temp_f2_222 * temp_f2_222)) - 3.0);
                    temp_f2_232 = 0.5 * temp_f2_228 * -(((f64) var_f6_216 * (temp_f2_228 * temp_f2_228)) - 3.0);
                    var_f6_216 = (f32) ((f64) var_f6_216 * (0.5 * temp_f2_232 * -(((f64) var_f6_216 * (temp_f2_232 * temp_f2_232)) - 3.0)));
                } else if (var_f6_216 < M2C_BITWISE(f32, 0.0)) {
                    var_f6_216 = __float_nan;
                } else {
                    sp8 = var_f6_216;
                    temp_r6_251 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r6_251) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_261 = 1;
                        } else {
                            var_r0_261 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_261 = 5;
                        } else {
                            var_r0_261 = 3;
                        }
                        break;
                    default:
                        var_r0_261 = 4;
                        break;
                    }
                    if (var_r0_261 == 1) {
                        var_f6_216 = __float_nan;
                    }
                }
                var_f5_283 = 1.0f / var_f6_216;
            } else {
                var_f5_283 = 0.0f;
                var_f6_216 = 0.0f;
            }
            temp_f7_294 = M2C_FIELD(*(&arg0 + temp_r8_185), f32 *, 0x38);
            temp_f3_296 = (f32) sp48 * var_f5_283;
            sp40 = (f32) sp40 * var_f5_283;
            unksp44 *= var_f5_283;
            sp48 = temp_f3_296;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (var_f6_216 == temp_f7_294) {
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
                sp18 = temp_f3_296 * (var_f6_216 * (1.0f - (var_f6_216 / temp_f7_294)));
                sp30 = sp10;
                sp38 = (f64) sp18;
                M2C_ERROR(/* unknown instruction: ps_add $f1, $f2, $f1 */);
                sp58 = (f32) sp58 + (f32) sp38;
            }
        }
        var_r5_180 += 4;
        var_ctr_183 -= 1;
    } while (var_ctr_183 != 0);
    M2C_FIELD(this, f64 *, 0) = sp50;
    M2C_FIELD(this, f64 *, 8) = (f64) sp58;
}
#endif

#if 0 // DRAFT: illegal type
void *LightManager::AllocManagedLight(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, const float &arg3, const int &arg4, const bool &arg5) {
    s32 var_ctr_341;
    s32 var_r10_340;
    void *temp_r12_344;

    var_r10_340 = 0;
    var_ctr_341 = 0x48;
loop_1:
    temp_r12_344 = this->unk5C + var_r10_340;
    if ((u8) M2C_FIELD(temp_r12_344, u8 *, 0x48) == 0) {
        M2C_FIELD(temp_r12_344, s8 *, 0x34) = 0;
        M2C_FIELD(temp_r12_344, u8 *, 0x48) = 1U;
        M2C_FIELD(temp_r12_344, f32 *, 0x38) = (f32) &arg3;
        M2C_FIELD(temp_r12_344, s32 *, 0x30) = (s32) &arg4;
        M2C_FIELD(temp_r12_344, f64 *, 0x20) = (f64) M2C_FIELD(&arg2, f64 *, 0);
        M2C_FIELD(temp_r12_344, f64 *, 0x28) = (f64) M2C_FIELD(&arg2, f64 *, 8);
        M2C_FIELD(temp_r12_344, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r12_344, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r12_344, f64 *, 0x10) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r12_344, f64 *, 0x18) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r12_344, u8 *, 0x40) = (u8) &arg5;
        M2C_FIELD(temp_r12_344, s32 *, 0x44) = -1;
        M2C_FIELD(temp_r12_344, s32 *, 0x3C) = 0;
        return temp_r12_344;
    }
    var_r10_340 += 0x50;
    var_ctr_341 -= 1;
    if (var_ctr_341 == 0) {
        return NULL;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void LightManager::Deinit() {
    MKHeap *temp_r3_393;
    void *temp_r31_390;

    temp_r31_390 = this->unk5C;
    if (temp_r31_390 != NULL) {
        temp_r3_393 = MKHeap::Current();
        if (temp_r3_393 != NULL) {
            ((MKHeap *) (temp_r3_393->Current()))->Free(temp_r31_390, NULL, 0);
        } else {
            free(temp_r31_390);
        }
    }
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal type
void LightManager::DisableAllLights() {
    s32 var_r30_423;
    s32 var_r31_424;

    var_r30_423 = 0;
    var_r31_424 = 0;
    do {
        EnableLight(this->unk5C + var_r31_424, 0U);
        var_r30_423 += 1;
        var_r31_424 += 0x50;
    } while (var_r30_423 < 0x48);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void LightManager::Init() {
    MKHeap *temp_r3_451;
    s32 temp_r0_486;
    s32 temp_r4_484;
    s32 temp_r6_483;
    s32 var_ctr_479;
    s32 var_r3_473;
    void *var_r3_458;

    MKProp::Init();
    temp_r3_451 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_451 != NULL) {
        var_r3_458 = ((MKHeap *) (temp_r3_451->Current()))->Alloc(0x1680, NULL, 0);
    } else {
        var_r3_458 = malloc(0x1680);
    }
    this->unk5C = var_r3_458;
    memset(this->unk5C, 0, 0x1680U);
    memset(&this->unk4C, 0, 0x10U);
    var_r3_473 = 0;
    var_ctr_479 = 0x48;
    do {
        temp_r6_483 = var_r3_473 + 0x48;
        temp_r4_484 = var_r3_473 + 0x44;
        *(this->unk5C + (var_r3_473 + 0x34)) = 0;
        temp_r0_486 = var_r3_473 + 0x3C;
        var_r3_473 += 0x50;
        *(this->unk5C + temp_r6_483) = 0;
        *(this->unk5C + temp_r4_484) = -1;
        *(this->unk5C + temp_r0_486) = 0;
        var_ctr_479 -= 1;
    } while (var_ctr_479 != 0);
}
#endif

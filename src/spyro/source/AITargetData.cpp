#include "spyro/source/AITargetData.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/EventCamera.h"
#include <m2c_macros.h>

extern M2C_UNK gb;

f32 AITargetData::GetDistSq() {
    f32 temp_f0_11;

    temp_f0_11 = this->unk30;
    return temp_f0_11 * temp_f0_11;
}

f32 AITargetData::GetDist() {
    return this->unk30;
}

void AITargetData::GetVel() {
    this->unk0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x10);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x18);
}

void AITargetData::GetDir() {
    this->unk0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x20);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x28);
}

#if 0 // DRAFT: pointer/array required
void AITargetData::GetPos() {
    this->unk0 = *M2C_ERROR(/* Read from unset register $r4 */);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 8);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void *AITargetData::GetProp() {
    if (this->unk40.Get() != NULL) {
        return M2C_FIELD(this->unk40.Get()->__vptr, void *(**)(), 8)();
    }
    return NULL;
}
#endif

s32 AITargetData::IsAttackable() {
    if (EventCamera_GetCurrent() != NULL) {
        return 0;
    }
    return (M2C_FIELD(GetProp(), s32 *, 0x18) & 0x80000000) == 0;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void AITargetData::Update(const MKVector3 &arg0) {
    f64 sp58;
    f64 sp50;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    Targetable *temp_r3_140;
    f32 temp_f0_174;
    f32 temp_f0_308;
    f32 temp_f1_173;
    f32 temp_f1_307;
    f32 temp_f3_176;
    f32 temp_f3_310;
    f32 var_f1_248;
    f32 var_f1_382;
    f32 var_f4_181;
    f32 var_f4_315;
    f64 temp_f0_153;
    f64 temp_f0_287;
    f64 temp_f1_187;
    f64 temp_f1_193;
    f64 temp_f1_197;
    f64 temp_f1_321;
    f64 temp_f1_327;
    f64 temp_f1_331;
    s32 temp_r3_216;
    s32 temp_r3_350;
    s32 var_r0_226;
    s32 var_r0_360;
    u8 temp_r0_129;

    if ((((u8) M2C_FIELD(this, u8 *, 0x49) >> 7U) & 1) || (this->unk3C != M2C_FIELD(&gb, f32 *, 0x30C))) {
        temp_r0_129 = M2C_FIELD(this, u8 *, 0x48);
        switch ((s32) temp_r0_129) {                /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            temp_r3_140 = this->unk40.Get();
            if (temp_r3_140 != NULL) {
                if (M2C_FIELD(temp_r3_140->__vptr, u8 (**)(MKVector3 *, AITargetData *), 0x24)(&arg0, this) != 0) {
                    temp_f0_153 = this->unk0 - M2C_FIELD(&arg0, f64 *, 0);
                    sp20 = temp_f0_153;
                    this->unk20 = temp_f0_153;
                    sp28 = this->unk8 - arg0.unk8;
                    sp50 = temp_f0_153;
                    this->unk28 = (f64) sp28;
                    sp58 = (f64) sp28;
                    this->unk34 = M2C_FIELD(this, f32 *, 0x24);
                    if (!(((u8) M2C_FIELD(this, u8 *, 0x49) >> 2U) & 1)) {
                        M2C_FIELD(this, f32 *, 0x24) = 0.0f;
                    }
                    temp_f1_173 = (f32) M2C_FIELD(this, f64 *, 0x20);
                    temp_f0_174 = M2C_FIELD(this, f32 *, 0x24);
                    temp_f3_176 = (f32) M2C_FIELD(this, f64 *, 0x28);
                    var_f4_181 = (temp_f3_176 * temp_f3_176) + ((temp_f1_173 * temp_f1_173) + (temp_f0_174 * temp_f0_174));
                    if (var_f4_181 > 0.000001f) {
                        if (var_f4_181 > 0.0f) {
                            temp_f1_187 = __frsqrte(var_f4_181);
                            temp_f1_193 = 0.5 * temp_f1_187 * -(((f64) var_f4_181 * (temp_f1_187 * temp_f1_187)) - 3.0);
                            temp_f1_197 = 0.5 * temp_f1_193 * -(((f64) var_f4_181 * (temp_f1_193 * temp_f1_193)) - 3.0);
                            var_f4_181 = (f32) ((f64) var_f4_181 * (0.5 * temp_f1_197 * -(((f64) var_f4_181 * (temp_f1_197 * temp_f1_197)) - 3.0)));
                        } else if (var_f4_181 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_181 = __float_nan;
                        } else {
                            spC = var_f4_181;
                            temp_r3_216 = M2C_BITWISE(s32, spC) & 0x7F800000;
                            switch (temp_r3_216) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_226 = 1;
                                } else {
                                    var_r0_226 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_226 = 5;
                                } else {
                                    var_r0_226 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_226 = 4;
                                break;
                            }
                            if (var_r0_226 == 1) {
                                var_f4_181 = __float_nan;
                            }
                        }
                        var_f1_248 = 1.0f / var_f4_181;
                    } else {
                        var_f1_248 = 0.0f;
                        var_f4_181 = 0.0f;
                    }
                    M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) * var_f1_248);
                    M2C_FIELD(this, f32 *, 0x24) = (f32) (M2C_FIELD(this, f32 *, 0x24) * var_f1_248);
                    M2C_FIELD(this, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x28) * var_f1_248);
                    this->unk30 = var_f4_181;
                }
                M2C_FIELD(temp_r3_140->__vptr, M2C_UNK (**)(f64 *, Targetable *), 0x30)(&sp40, temp_r3_140);
                this->unk10 = sp40;
                this->unk18 = sp48;
                M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x80);
            } else {
                M2C_FIELD(this, u8 *, 0x48) = 0U;
            }
            break;
        case 2:                                     /* switch 1 */
            temp_f0_287 = this->unk0 - M2C_FIELD(&arg0, f64 *, 0);
            sp10 = temp_f0_287;
            this->unk20 = temp_f0_287;
            sp18 = this->unk8 - arg0.unk8;
            sp30 = temp_f0_287;
            this->unk28 = (f64) sp18;
            sp38 = (f64) sp18;
            this->unk34 = M2C_FIELD(this, f32 *, 0x24);
            if (!(((u8) M2C_FIELD(this, u8 *, 0x49) >> 2U) & 1)) {
                M2C_FIELD(this, f32 *, 0x24) = 0.0f;
            }
            temp_f1_307 = (f32) M2C_FIELD(this, f64 *, 0x20);
            temp_f0_308 = M2C_FIELD(this, f32 *, 0x24);
            temp_f3_310 = (f32) M2C_FIELD(this, f64 *, 0x28);
            var_f4_315 = (temp_f3_310 * temp_f3_310) + ((temp_f1_307 * temp_f1_307) + (temp_f0_308 * temp_f0_308));
            if (var_f4_315 > 0.000001f) {
                if (var_f4_315 > 0.0f) {
                    temp_f1_321 = __frsqrte(var_f4_315);
                    temp_f1_327 = 0.5 * temp_f1_321 * -(((f64) var_f4_315 * (temp_f1_321 * temp_f1_321)) - 3.0);
                    temp_f1_331 = 0.5 * temp_f1_327 * -(((f64) var_f4_315 * (temp_f1_327 * temp_f1_327)) - 3.0);
                    var_f4_315 = (f32) ((f64) var_f4_315 * (0.5 * temp_f1_331 * -(((f64) var_f4_315 * (temp_f1_331 * temp_f1_331)) - 3.0)));
                } else if (var_f4_315 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_315 = __float_nan;
                } else {
                    sp8 = var_f4_315;
                    temp_r3_350 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_350) {          /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_360 = 1;
                        } else {
                            var_r0_360 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_360 = 5;
                        } else {
                            var_r0_360 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_360 = 4;
                        break;
                    }
                    if (var_r0_360 == 1) {
                        var_f4_315 = __float_nan;
                    }
                }
                var_f1_382 = 1.0f / var_f4_315;
            } else {
                var_f1_382 = 0.0f;
                var_f4_315 = 0.0f;
            }
            M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) * var_f1_382);
            M2C_FIELD(this, f32 *, 0x24) = (f32) (M2C_FIELD(this, f32 *, 0x24) * var_f1_382);
            M2C_FIELD(this, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x28) * var_f1_382);
            this->unk30 = var_f4_315;
            M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x80);
            break;
        }
        this->unk3C = M2C_FIELD(&gb, f32 *, 0x30C);
    }
}
#endif

void AITargetData::SetIsNew(bool arg0) {
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~8) | ((arg0 << 3) & 8));
}

void AITargetData::SetInsideFOV(bool arg0) {
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~0x10) | ((arg0 << 4) & 0x10));
}

void AITargetData::SetInsideExclusionRegion(bool arg0) {
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~0x20) | ((arg0 << 5) & 0x20));
}

void AITargetData::SetInsideRegion(bool arg0) {
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~0x40) | ((arg0 << 6) & 0x40));
}

#if 0 // DRAFT: ambiguous access to overloaded function 'TargetContext::Set(Targetable *)' 'TargetContext::Set(MKProp *)'
void AITargetData::Set(const MKVector3 &arg0, bool arg1) {
    this->unk0 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk40.Set(NULL);
    M2C_FIELD(this, s8 *, 0x48) = 2;
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) | 0x80);
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~4) | ((arg1 << 2) & 4));
}
#endif

void AITargetData::Set(Targetable *arg0, bool arg1) {
    this->unk40.Set(arg0);
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    this->unk8 = 0.0f;
    M2C_FIELD(this, s8 *, 0x48) = 1;
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) | 0x80);
    M2C_FIELD(this, u8 *, 0x49) = (u8) ((M2C_FIELD(this, u8 *, 0x49) & ~4) | ((arg1 << 2) & 4));
}

#if 0 // DRAFT: ambiguous access to overloaded function 'TargetContext::Set(Targetable *)' 'TargetContext::Set(MKProp *)'
void AITargetData::SetDefaults() {
    this->unk40.Set(NULL);
    M2C_FIELD(this, f32 *, 0) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    this->unk8 = 0.0f;
    M2C_FIELD(this, f32 *, 0x20) = 0.0f;
    M2C_FIELD(this, f32 *, 0x24) = 0.0f;
    M2C_FIELD(this, f32 *, 0x28) = 0.0f;
    M2C_FIELD(this, f32 *, 0x10) = 0.0f;
    M2C_FIELD(this, f32 *, 0x14) = 0.0f;
    M2C_FIELD(this, f32 *, 0x18) = 0.0f;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk3C = 0.0f;
    M2C_FIELD(this, s8 *, 0x48) = 0;
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) | 0x80);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x40);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x10);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~8);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~4);
    M2C_FIELD(this, u8 *, 0x49) = (u8) (M2C_FIELD(this, u8 *, 0x49) & ~0x20);
}
#endif

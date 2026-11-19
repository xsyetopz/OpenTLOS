#include "spyro/source/UIAttributes.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIMessage.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'LoadVector4'
s32 stricmp(s8 *, s8 *);                            /* extern */
static s8 lit_stringBase0[0x5A] = {
    0x63,
    0x6F,
    0x6C,
    0x6F,
    0x75,
    0x72,
    0,
    0x70,
    0x6F,
    0x73,
    0x69,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0,
    0x72,
    0x6F,
    0x74,
    0x61,
    0x74,
    0x69,
    0x6F,
    0x6E,
    0,
    0x73,
    0x63,
    0x61,
    0x6C,
    0x65,
    0,
    0x77,
    0x69,
    0x64,
    0x74,
    0x68,
    0,
    0x68,
    0x65,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
    0x61,
    0x6C,
    0x69,
    0x67,
    0x6E,
    0x6D,
    0x65,
    0x6E,
    0x74,
    0,
    0x74,
    0x6F,
    0x70,
    0,
    0x6D,
    0x69,
    0x64,
    0x64,
    0x6C,
    0x65,
    0,
    0x62,
    0x6F,
    0x74,
    0x74,
    0x6F,
    0x6D,
    0,
    0x6C,
    0x65,
    0x66,
    0x74,
    0,
    0x63,
    0x65,
    0x6E,
    0x74,
    0x72,
    0x65,
    0,
    0x72,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
}; /* const */

s32 Attributes::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s32 var_r30_116;

    if (arg0->LoadVector4(lit_stringBase0, (MKVector4 *) this, 0) != 0) {
        this->unk40 |= 1;
        return 1;
    }
    if (arg0->LoadVector3(&lit_stringBase0[7], &this->unk10, 0) != 0) {
        this->unk40 |= 2;
        return 1;
    }
    if (arg0->LoadVector3(&lit_stringBase0[0x10], &this->unk20, 0) != 0) {
        this->unk40 |= 4;
        return 1;
    }
    if (arg0->LoadFloat(&lit_stringBase0[0x19], &this->unk30, 0) != 0) {
        this->unk40 |= 8;
        return 1;
    }
    if (arg0->LoadFloat(&lit_stringBase0[0x1F], &this->unk34, 0) != 0) {
        this->unk40 |= 0x10;
        return 1;
    }
    if (arg0->LoadFloat(&lit_stringBase0[0x25], &this->unk38, 0) != 0) {
        this->unk40 |= 0x10;
        return 1;
    }
    if (arg0->IsField(&lit_stringBase0[0x2C]) != 0) {
        var_r30_116 = 0;
        this->unk40 |= 0x20;
        sp8 = NULL;
loop_14:
        arg0->AsString(var_r30_116, &sp8);
        if (sp8 != NULL) {
            if (stricmp(&lit_stringBase0[0x36]) == 0) {
                this->unk3C &= 3;
                goto block_29;
            }
            if (stricmp(&lit_stringBase0[0x3A], sp8) == 0) {
                this->unk3C = (this->unk3C & 3) | 4;
                goto block_29;
            }
            if (stricmp(&lit_stringBase0[0x41], sp8) == 0) {
                this->unk3C = (this->unk3C & 3) | 8;
                goto block_29;
            }
            if (stricmp(&lit_stringBase0[0x48], sp8) == 0) {
                this->unk3C &= 0xC;
                goto block_29;
            }
            if (stricmp(&lit_stringBase0[0x4D], sp8) == 0) {
                this->unk3C = (this->unk3C & 0xC) | 1;
                goto block_29;
            }
            if (stricmp(&lit_stringBase0[0x54], sp8) == 0) {
                this->unk3C = (this->unk3C & 0xC) | 2;
                goto block_29;
            }
            if (var_r30_116 == 0) {
                this->unk3C = arg0->GetInt(0);
            } else {
block_29:
                var_r30_116 += 1;
                if (var_r30_116 < 2) {
                    goto loop_14;
                }
            }
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'InterpolateLinear'
void Attributes::Tween(Attributes *arg0, Attributes *arg1, float arg2) {
    MKVector4 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    f32 temp_f1_282;
    f32 temp_f1_290;
    f32 temp_f1_295;
    u16 temp_r3_245;

    this->unk40 = this->unk40 | arg1->unk40;
    temp_r3_245 = arg0->unk40 & arg1->unk40;
    if (temp_r3_245 & 1) {
        InterpolateLinear(sp28, *((MKVector4 *) arg0), arg2);
        M2C_FIELD(this, f64 *, 0) = M2C_BITWISE(f64, sp28);
        this->unk8 = (f64) sp28.unk8;
    }
    if (temp_r3_245 & 2) {
        InterpolateLinear(sp18, arg0->unk10, arg2);
        M2C_FIELD(this, f64 *, 0x10) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(this, f64 *, 0x18) = (f64) sp18.unk8;
    }
    if (temp_r3_245 & 4) {
        InterpolateLinear(sp8, arg0->unk20, arg2);
        M2C_FIELD(this, f64 *, 0x20) = M2C_BITWISE(f64, sp8);
        M2C_FIELD(this, f64 *, 0x28) = (f64) sp8.unk8;
    }
    if (temp_r3_245 & 8) {
        temp_f1_282 = arg0->unk30;
        this->unk30 = (arg2 * (arg1->unk30 - temp_f1_282)) + temp_f1_282;
    }
    if (temp_r3_245 & 0x10) {
        temp_f1_290 = arg0->unk34;
        this->unk34 = (arg2 * (arg1->unk34 - temp_f1_290)) + temp_f1_290;
        temp_f1_295 = arg0->unk38;
        this->unk38 = (arg2 * (arg1->unk38 - temp_f1_295)) + temp_f1_295;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
void Attributes::SetIdentity() {
    this->unk0 = 1.0f;
    this->unk4 = 1.0f;
    M2C_FIELD(this, f32 *, 8) = 1.0f;
    M2C_FIELD(this, f32 *, 0xC) = 1.0f;
    this->unk10.unk0 = 0.0f;
    this->unk10.unk4 = 0.0f;
    this->unk10.unk8 = 0.0f;
    this->unk10.unkC = 1.0f;
    this->unk20.unk0 = 0.0f;
    this->unk20.unk4 = 0.0f;
    this->unk20.unk8 = 0.0f;
    this->unk20.unkC = 0.0f;
    this->unk30 = 1.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk3C = 0;
    this->unk40 = 0;
}
#endif

#if 0 // DRAFT: illegal function overloading
void RenderContext::AddState(const Attributes &arg0) {
    f32 temp_f3_351;
    f32 temp_f6_359;
    f32 temp_f7_365;
    if (arg0.unk40 & 2) {
        temp_f3_351 = arg0.unk10.unk4;
        temp_f6_359 = arg0.unk10.unk0;
        temp_f7_365 = arg0.unk10.unk8;
        arg_sp10 = (temp_f7_365 * this->unk20) + ((temp_f6_359 * this->unk0) + (temp_f3_351 * this->unk10));
        arg_sp14 = (temp_f7_365 * this->unk24) + ((temp_f6_359 * this->unk4) + (temp_f3_351 * this->unk14));
        arg_sp18 = (temp_f7_365 * this->unk28) + ((temp_f6_359 * this->unk8) + (temp_f3_351 * this->unk18));
        arg_sp20 = (f64) arg_sp10;
        arg_sp28 = (f64) arg_sp18;
        Matrix::Translate((Matrix *) this, *((MKVector3 *) &arg_sp20));
    }
    if (arg0.unk40 & 4) {
        arg_spA0 = 0.0f;
        arg_spA4 = 0.0f;
        arg_spA8 = 0.0f;
        arg_spAC = 1.0f;
        arg_sp70.SetRotationRoll(arg0.unk20.unk8);
        arg_sp70.RotateYaw((Matrix *) &arg_sp70, arg0.unk20.unk4);
        arg_sp70.RotatePitch((Matrix *) &arg_sp70, arg0.unk20.unk0);
        Matrix::Multiply((Matrix *) &arg_sp70, (Matrix *) this);
    }
    if (arg0.unk40 & 8) {
        arg_sp30.SetIdentity();
        arg_sp30.Scale4x3((Matrix *) &arg_sp30, arg0.unk30);
        Matrix::Multiply((Matrix *) &arg_sp30, (Matrix *) this);
    }
    if (arg0.unk40 & 1) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_mul $f0, $f1, $f0 */);
        M2C_ERROR(/* unknown instruction: psq_stx $f0, $r30, $r3, 0x0, qr0 */);
    }
}
#endif

void RenderContext::AddState(const RenderContext &arg0, const Attributes &arg1) {
    M2C_STRUCT_COPY(this, &arg0, 0x40);
    this->unk40 = arg0.unk40;
    this->unk48 = arg0.unk48;
    AddState(arg1);
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
RenderContext::RenderContext(const RenderContext &arg0, const Attributes &arg1) {
    AddState(arg0, arg1);
    return this;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
RenderContext::RenderContext() {
    Matrix::SetIdentity();
    M2C_FIELD(this, f32 *, 0x40) = 1.0f;
    M2C_FIELD(this, f32 *, 0x44) = 1.0f;
    M2C_FIELD(this, f32 *, 0x48) = 1.0f;
    M2C_FIELD(this, f32 *, 0x4C) = 1.0f;
    return this;
}
#endif

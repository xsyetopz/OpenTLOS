#include "spyro/source/UIAttributes.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/UIMessage.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 stricmp(s8 *, s8 *);                            /* extern */

s32 Attributes::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s32 var_r30_116;

    if (((MKIniLine *) arg0)->LoadVector4("colour", (MKVector4 *) this, 0) != 0) {
        this->unk40 |= 1;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadVector3("position", &this->unk10, 0) != 0) {
        this->unk40 |= 2;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadVector3("rotation", &this->unk20, 0) != 0) {
        this->unk40 |= 4;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadFloat("scale", &this->unk30, 0) != 0) {
        this->unk40 |= 8;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadFloat("width", &this->unk34, 0) != 0) {
        this->unk40 |= 0x10;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadFloat("height", &this->unk38, 0) != 0) {
        this->unk40 |= 0x10;
        return 1;
    }
    if (((MKIniLine *) arg0)->IsField("alignment") != 0) {
        var_r30_116 = 0;
        this->unk40 |= 0x20;
        sp8 = NULL;
loop_14:
        ((MKIniLine *) arg0)->AsString(var_r30_116, &sp8);
        if (sp8 != NULL) {
            if (stricmp("top") == 0) {
                this->unk3C &= 3;
                goto block_29;
            }
            if (stricmp("middle", sp8) == 0) {
                this->unk3C = (this->unk3C & 3) | 4;
                goto block_29;
            }
            if (stricmp("bottom", sp8) == 0) {
                this->unk3C = (this->unk3C & 3) | 8;
                goto block_29;
            }
            if (stricmp("left", sp8) == 0) {
                this->unk3C &= 0xC;
                goto block_29;
            }
            if (stricmp("centre", sp8) == 0) {
                this->unk3C = (this->unk3C & 0xC) | 1;
                goto block_29;
            }
            if (stricmp("right", sp8) == 0) {
                this->unk3C = (this->unk3C & 0xC) | 2;
                goto block_29;
            }
            if (var_r30_116 == 0) {
                this->unk3C = ((MKIniLine *) arg0)->GetInt(0);
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

#if 0 // DRAFT: illegal function overloading
void RenderContext::AddState(const Attributes &arg0) {
    Matrix sp70;
    Matrix sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_351;
    f32 temp_f6_359;
    f32 temp_f7_365;

    if (arg0.unk40 & 2) {
        temp_f3_351 = arg0.unk10.unk4;
        temp_f6_359 = arg0.unk10.unk0;
        temp_f7_365 = arg0.unk10.unk8;
        sp10 = (temp_f7_365 * this->unk20) + ((temp_f6_359 * this->unk0) + (temp_f3_351 * this->unk10));
        sp14 = (temp_f7_365 * this->unk24) + ((temp_f6_359 * this->unk4) + (temp_f3_351 * this->unk14));
        sp18 = (temp_f7_365 * this->unk28) + ((temp_f6_359 * this->unk8) + (temp_f3_351 * this->unk18));
        sp20 = (f64) sp10;
        sp28 = (f64) sp18;
        Matrix::Translate((Matrix *) this, *((MKVector3 *) &sp20));
    }
    if (arg0.unk40 & 4) {
        sp70.unk30 = 0.0f;
        sp70.unk34 = 0.0f;
        sp70.unk38 = 0.0f;
        sp70.unk3C = 1.0f;
        sp70.SetRotationRoll(arg0.unk20.unk8);
        sp70.RotateYaw(&sp70, arg0.unk20.unk4);
        sp70.RotatePitch(&sp70, arg0.unk20.unk0);
        Matrix::Multiply(&sp70, (Matrix *) this);
    }
    if (arg0.unk40 & 8) {
        sp30.SetIdentity();
        sp30.Scale4x3(&sp30, arg0.unk30);
        Matrix::Multiply(&sp30, (Matrix *) this);
    }
    if (arg0.unk40 & 1) {
        this->unk40 *= M2C_FIELD(&arg0, f64 *, 0);
        this->unk48 *= arg0.unk8;
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

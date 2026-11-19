#ifndef SPYRO_SOURCE_MANAGEDLIGHT_H
#define SPYRO_SOURCE_MANAGEDLIGHT_H

#include <dolphin/types.h>

class MKVector3;
class MKVector4;
class ManagedLight;

class ManagedLight {
public:
    void SetPosition(const MKVector3 &);
    void SetColor(const MKVector4 &);
    void SetRadius(float);
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ u8 pad30[0x8];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ void* unk3C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void ManagedLight::SetRadius(float arg0) {
    void *temp_r3_2231;

    this->unk38 = arg0;
    temp_r3_2231 = this->unk3C;
    if (temp_r3_2231 != NULL) {
        M2C_FIELD(temp_r3_2231, f32 *, 0x20) = arg0;
        M2C_FIELD(temp_r3_2231, f32 *, 0x24) = (f32) (arg0 * arg0);
        M2C_FIELD(temp_r3_2231, f32 *, 0x28) = (f32) (1.0f / arg0);
        M2C_FIELD(temp_r3_2231, f32 *, 0x2C) = (f32) (1.0f / M2C_FIELD(temp_r3_2231, f32 *, 0x24));
    }
}

inline void ManagedLight::SetPosition(const MKVector3 &arg0) {
    f64 temp_f0_4404;
    f64 temp_f1_4403;
    void *temp_r3_4407;

    temp_f1_4403 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f0_4404 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk10 = temp_f1_4403;
    this->unk18 = temp_f0_4404;
    temp_r3_4407 = this->unk3C;
    if (temp_r3_4407 != NULL) {
        M2C_FIELD(temp_r3_4407, f64 *, 0x10) = temp_f1_4403;
        M2C_FIELD(temp_r3_4407, f64 *, 0x18) = temp_f0_4404;
    }
}

inline void ManagedLight::SetColor(const MKVector4 &arg0) {
    f64 temp_f0_4419;
    f64 temp_f1_4418;
    void *temp_r3_4422;

    temp_f1_4418 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f0_4419 = M2C_FIELD(&arg0, f64 *, 8);
    this->unk20 = temp_f1_4418;
    this->unk28 = temp_f0_4419;
    temp_r3_4422 = this->unk3C;
    if (temp_r3_4422 != NULL) {
        M2C_FIELD(temp_r3_4422, f64 *, 0) = temp_f1_4418;
        M2C_FIELD(temp_r3_4422, f64 *, 8) = temp_f0_4419;
    }
}

#endif  // SPYRO_SOURCE_MANAGEDLIGHT_H

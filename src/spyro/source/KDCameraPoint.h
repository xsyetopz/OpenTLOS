#ifndef SPYRO_SOURCE_KDCAMERAPOINT_H
#define SPYRO_SOURCE_KDCAMERAPOINT_H

#include <dolphin/types.h>

class KDCameraPoint;
class MKVector3;

class KDCameraPoint {
public:
    void Init(const MKVector3 &);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void KDCameraPoint::Init(const MKVector3 &arg0) {
    f64 temp_f0_5704;
    f64 temp_f1_5703;

    temp_f1_5703 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f0_5704 = M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, f64 *, 0) = temp_f1_5703;
    M2C_FIELD(this, f64 *, 8) = temp_f0_5704;
    M2C_FIELD(this, f64 *, 0x10) = temp_f1_5703;
    M2C_FIELD(this, f64 *, 0x18) = temp_f0_5704;
}

#endif  // SPYRO_SOURCE_KDCAMERAPOINT_H

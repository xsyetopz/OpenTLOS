#ifndef SPYRO_SOURCE_SHAKECAMERAMESSAGE_H
#define SPYRO_SOURCE_SHAKECAMERAMESSAGE_H

#include <dolphin/types.h>

class MKVector3;
class ShakeCameraMessage;

class ShakeCameraMessage {
public:
    void Init(const MKVector3 &, bool);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void ShakeCameraMessage::Init(const MKVector3 &arg0, bool arg1) {
    M2C_FIELD(this, s32 *, 0) = 0x417;
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(this, u8 *, 0x18) = arg1;
}

#endif  // SPYRO_SOURCE_SHAKECAMERAMESSAGE_H

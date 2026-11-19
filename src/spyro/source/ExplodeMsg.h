#ifndef SPYRO_SOURCE_EXPLODEMSG_H
#define SPYRO_SOURCE_EXPLODEMSG_H

#include <dolphin/types.h>

class ExplodeMsg;
class MKProp;
class MKVector3;

class ExplodeMsg {
public:
    void Init(MKProp *, const MKVector3 &, float, bool, bool, int, float, int);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void ExplodeMsg::Init(MKProp *arg0, const MKVector3 &arg1, float arg2, bool arg3, bool arg4, int arg5, float arg6, int arg7) {
    M2C_FIELD(this, s32 *, 0) = 1;
    M2C_FIELD(this, MKProp **, 8) = arg0;
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    M2C_FIELD(this, f32 *, 0x20) = arg2;
    M2C_FIELD(this, u8 *, 0x28) = arg3;
    M2C_FIELD(this, s8 *, 0x29) = 0;
    M2C_FIELD(this, u8 *, 0x2A) = arg4;
    M2C_FIELD(this, s32 *, 0x24) = arg5;
    M2C_FIELD(this, f32 *, 0x2C) = arg6;
    M2C_FIELD(this, s32 *, 0x30) = arg7;
}

#endif  // SPYRO_SOURCE_EXPLODEMSG_H

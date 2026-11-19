#ifndef SPYRO_SOURCE_SHATTEREXTENDEDMSG_H
#define SPYRO_SOURCE_SHATTEREXTENDEDMSG_H

#include <dolphin/types.h>

class ShatterExtendedMsg;

class ShatterExtendedMsg {
public:
    virtual void Init(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vptr'
inline void ShatterExtendedMsg::Init() {
    this->__vptr = (void *)0x30;
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x10) = 0.0f;
    M2C_FIELD(this, s8 *, 0x18) = 0;
    M2C_FIELD(this, s32 *, 0x1C) = -1;
    M2C_FIELD(this, s32 *, 0x20) = 0;
    M2C_FIELD(this, s8 *, 0x24) = 0;
    M2C_FIELD(this, s32 *, 0x28) = 0;
}
#endif

#endif  // SPYRO_SOURCE_SHATTEREXTENDEDMSG_H

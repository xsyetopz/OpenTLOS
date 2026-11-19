#ifndef SPYRO_SOURCE_FLOATINGPLATFORMDESCRIPTOR_H
#define SPYRO_SOURCE_FLOATINGPLATFORMDESCRIPTOR_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"

class FloatingPlatformDescriptor;
class KDPropExDescriptor;

class FloatingPlatformDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    FloatingPlatformDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline FloatingPlatformDescriptor::FloatingPlatformDescriptor() {
}

#if 0 // DRAFT: undefined identifier 'PlatformDescriptor'
inline void FloatingPlatformDescriptor::Init() {
    PlatformDescriptor::Init();
    this->unkC |= 2;
    M2C_FIELD(this, s8 *, 0x104) = 1;
    M2C_FIELD(this, f32 *, 0x108) = 0.25f;
    M2C_FIELD(this, f32 *, 0x10C) = 0.08726646f;
    M2C_FIELD(this, f32 *, 0x110) = 0.15f;
    M2C_FIELD(this, f32 *, 0x114) = 0.08726646f;
}
#endif

#endif  // SPYRO_SOURCE_FLOATINGPLATFORMDESCRIPTOR_H

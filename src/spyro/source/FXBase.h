#ifndef SPYRO_SOURCE_FXBASE_H
#define SPYRO_SOURCE_FXBASE_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"

class FXBase;
class FXBaseDescriptor;
class KDPropEx;
class KDPropExDescriptor;
class MKIniLine;
class MKVector3;
class MKVector4;

class FXBase : public KDPropEx {  // base: ctor/dtor vtable stores
public:
    virtual ~FXBase(void);
    virtual void Emit(const MKVector3 &, const MKVector3 &, float, const MKVector4 &);
    FXBase(void);
    void Burst(const MKVector3 &);
};

class FXBaseDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    FXBaseDescriptor(void);
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline FXBase::~FXBase() {
    s32 temp_cr0_eq_18241;

    temp_cr0_eq_18241 = this == NULL;
    if (temp_cr0_eq_18241 == 0) {
        if (temp_cr0_eq_18241 == 0) {
            if (temp_cr0_eq_18241 == 0) {
                if (temp_cr0_eq_18241 == 0) {
                }
            }
        }
    }
}

inline FXBase::FXBase() {
}

inline FXBaseDescriptor::FXBaseDescriptor() {
}

#endif  // SPYRO_SOURCE_FXBASE_H

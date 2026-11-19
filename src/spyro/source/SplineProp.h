#ifndef SPYRO_SOURCE_SPLINEPROP_H
#define SPYRO_SOURCE_SPLINEPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

class KDSplinePathSegment;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class Matrix;
class SplineProp;
class SplinePropDescriptor;
class SplineProp_cpp;

class SplineProp : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SplineProp(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void CalcBounds(void);
    /* 0x04c */ u8 unk4C;
    /* 0x04d */ u8 pad4D[0x3];
    /* 0x050 */ Matrix unk50;
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f64 unkA8;
    /* 0x0b0 */ KDSplinePathSegment* unkB0;
    /* 0x0b4 */ f32 unkB4;
};

class SplinePropDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
};

class SplineProp_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SplineProp::~SplineProp() {
    s32 temp_cr0_eq_10665;

    temp_cr0_eq_10665 = this == NULL;
    if (temp_cr0_eq_10665 == 0) {
        if (temp_cr0_eq_10665 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_SPLINEPROP_H

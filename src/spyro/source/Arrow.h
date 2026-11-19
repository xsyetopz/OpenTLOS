#ifndef SPYRO_SOURCE_ARROW_H
#define SPYRO_SOURCE_ARROW_H

#include <dolphin/types.h>
#include "spyro/source/Trap.h"

class Arrow;
class ArrowDescriptor;
class Matrix;
class Trap;
class TrapDescriptor;

class Arrow : public Trap {  // base: base ctor call
public:
    virtual ~Arrow(void);
    virtual void Reset(void);
    virtual void Update(void);
    Arrow(void);
    void Fire(const Matrix &, float, float);
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
};

class ArrowDescriptor : public TrapDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    ArrowDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Arrow::~Arrow() {
    M2C_FIELD(this, s32 **, 0xC8) = &__vt.unk48;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline Arrow::Arrow() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ArrowDescriptor::ArrowDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ARROW_H

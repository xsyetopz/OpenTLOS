#ifndef SPYRO_SOURCE_ARROW_H
#define SPYRO_SOURCE_ARROW_H

#include <dolphin/types.h>
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Trap.h"

class Arrow;
class ArrowDescriptor;
class KDPropExDescriptor;
class Matrix;
class Trap;

class Arrow : public Trap {  // base: vtable prefix
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

class ArrowDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    ArrowDescriptor(void);
};

#endif  // SPYRO_SOURCE_ARROW_H

#ifndef SPYRO_SOURCE_SPLINEPROP_H
#define SPYRO_SOURCE_SPLINEPROP_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"

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
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void CalcBounds(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ Matrix unk50;
};

class SplinePropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
};

class SplineProp_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPLINEPROP_H

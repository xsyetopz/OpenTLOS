#ifndef SPYRO_SOURCE_KDMATRIXPROPERTY_H
#define SPYRO_SOURCE_KDMATRIXPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDPositionProperty.h"

class KDMatrixProperty;
class KDPositionProperty;
class MKIniLine;
class Matrix;

class KDMatrixProperty : public KDPositionProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void GetPos(void) const;
    virtual s32 GetPosRef(void) const;
    virtual s32 GetMatrixRef(void) const;
    virtual void GetMatrix(Matrix *) const;
};

#endif  // SPYRO_SOURCE_KDMATRIXPROPERTY_H

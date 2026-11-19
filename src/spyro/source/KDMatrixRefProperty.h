#ifndef SPYRO_SOURCE_KDMATRIXREFPROPERTY_H
#define SPYRO_SOURCE_KDMATRIXREFPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDMatrixProperty.h"

class KDMatrixProperty;
class KDMatrixRefProperty;
class Matrix;

class KDMatrixRefProperty : public KDMatrixProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void GetPos(void) const;
    virtual s32 GetPosRef(void) const;
    virtual s32 GetMatrixRef(void) const;
    virtual void GetMatrix(Matrix *) const;
    KDMatrixRefProperty(void);
};

#endif  // SPYRO_SOURCE_KDMATRIXREFPROPERTY_H

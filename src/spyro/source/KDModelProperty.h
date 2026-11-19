#ifndef SPYRO_SOURCE_KDMODELPROPERTY_H
#define SPYRO_SOURCE_KDMODELPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDModelProperty;
class KDProperty;

class KDModelProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    static KDModelProperty classInfo;
};

#endif  // SPYRO_SOURCE_KDMODELPROPERTY_H

#ifndef SPYRO_SOURCE_KDANIMSCRIPTPROPERTY_H
#define SPYRO_SOURCE_KDANIMSCRIPTPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDAnimScriptProperty;
class KDProperty;

class KDAnimScriptProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    static KDAnimScriptProperty classInfo;
};

#endif  // SPYRO_SOURCE_KDANIMSCRIPTPROPERTY_H

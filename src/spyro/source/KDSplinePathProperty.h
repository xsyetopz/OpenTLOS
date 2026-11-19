#ifndef SPYRO_SOURCE_KDSPLINEPATHPROPERTY_H
#define SPYRO_SOURCE_KDSPLINEPATHPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDProperty;
class KDSplinePathProperty;
class MKIniLine;

class KDSplinePathProperty : public KDProperty {  // base: vtable prefix
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
    static KDSplinePathProperty classInfo;
};

#endif  // SPYRO_SOURCE_KDSPLINEPATHPROPERTY_H

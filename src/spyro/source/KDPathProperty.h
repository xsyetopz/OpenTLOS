#ifndef SPYRO_SOURCE_KDPATHPROPERTY_H
#define SPYRO_SOURCE_KDPATHPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDPathProperty;
class KDProperty;
class MKIniLine;

class KDPathProperty : public KDProperty {  // base: vtable prefix
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
};

#endif  // SPYRO_SOURCE_KDPATHPROPERTY_H

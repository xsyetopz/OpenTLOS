#ifndef SPYRO_SOURCE_KDPOSITIONPROPERTY_H
#define SPYRO_SOURCE_KDPOSITIONPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDPositionProperty;
class KDProperty;
class MKIniLine;

class KDPositionProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual s32 GetInstanceDataAlignment(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void GetPos(void) const;
    virtual s32 GetPosRef(void) const;
};

#endif  // SPYRO_SOURCE_KDPOSITIONPROPERTY_H

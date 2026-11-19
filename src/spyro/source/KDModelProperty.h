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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 KDModelProperty::GetInstanceDataSize() const {
    return 4;
}

#if 0 // DRAFT: undefined identifier 'unk8'
inline void KDModelProperty::InitInstance() {
    *(*KDProperty::pInstanceMem + this->unk8) = 0;
}
#endif

inline void *KDModelProperty::GetClassInfo() const {
    return &KDModelProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDMODELPROPERTY_H

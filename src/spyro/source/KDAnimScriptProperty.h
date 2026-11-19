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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 KDAnimScriptProperty::GetInstanceDataSize() const {
    return 4;
}

#if 0 // DRAFT: expression syntax error
inline void KDAnimScriptProperty::InitInstance() {
    *(pInstanceMem.__vptr + this->unk8) = 0;
}
#endif

inline void *KDAnimScriptProperty::GetClassInfo() const {
    return &classInfo;
}

#endif  // SPYRO_SOURCE_KDANIMSCRIPTPROPERTY_H

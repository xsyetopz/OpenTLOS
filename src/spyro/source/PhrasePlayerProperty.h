#ifndef SPYRO_SOURCE_PHRASEPLAYERPROPERTY_H
#define SPYRO_SOURCE_PHRASEPLAYERPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDProperty;
class PhrasePlayerProperty;

class PhrasePlayerProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void Command(int);
    static PhrasePlayerProperty classInfo;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 PhrasePlayerProperty::GetInstanceDataSize() const {
    return 4;
}

#if 0 // DRAFT: pointer/array required
inline void PhrasePlayerProperty::InitInstance() {
    *(*KDProperty::pInstanceMem + this->unk8) = 0;
}
#endif

inline void *PhrasePlayerProperty::GetClassInfo() const {
    return &PhrasePlayerProperty::classInfo;
}

#endif  // SPYRO_SOURCE_PHRASEPLAYERPROPERTY_H

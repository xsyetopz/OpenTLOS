#ifndef SPYRO_SOURCE_PHRASEPLAYERPROPERTY_H
#define SPYRO_SOURCE_PHRASEPLAYERPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDProperty;
class PhrasePlayerProperty;

class PhrasePlayerProperty : public KDProperty {  // base: vtable prefix
public:
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void Command(int);
    static PhrasePlayerProperty classInfo;
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
};

#endif  // SPYRO_SOURCE_PHRASEPLAYERPROPERTY_H

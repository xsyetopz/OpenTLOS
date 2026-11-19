#ifndef SPYRO_SOURCE_ANIMPROPERTY_H
#define SPYRO_SOURCE_ANIMPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class AnimProperty;
class KDAnimScriptProperty;
class KDProperty;
class KDPropertySet;
class MKIniLine;

class AnimProperty : public KDProperty {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    virtual void Init(char *);
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ KDAnimScriptProperty* unk10;
    /* 0x014 */ void* unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ f32 unk20;
};

#endif  // SPYRO_SOURCE_ANIMPROPERTY_H

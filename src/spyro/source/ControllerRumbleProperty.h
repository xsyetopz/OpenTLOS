#ifndef SPYRO_SOURCE_CONTROLLERRUMBLEPROPERTY_H
#define SPYRO_SOURCE_CONTROLLERRUMBLEPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class ControllerRumbleProperty;
class KDProperty;
class KDPropertySet;
class MKIniLine;

class ControllerRumbleProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void Command(int);
    void DoRumble(void);
    ControllerRumbleProperty(void);
    static u8 classInfo[0x10];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s8* unk10;
    /* 0x014 */ void** unk14;
    /* 0x018 */ MKIniLine* unk18;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 ControllerRumbleProperty::GetInstanceDataSize() const {
    return 0x14;
}

inline s32 ControllerRumbleProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *ControllerRumbleProperty::GetClassInfo() const {
    return (ControllerRumbleProperty *) ControllerRumbleProperty::classInfo;
}

#endif  // SPYRO_SOURCE_CONTROLLERRUMBLEPROPERTY_H

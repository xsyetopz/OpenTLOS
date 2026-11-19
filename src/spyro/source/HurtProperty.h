#ifndef SPYRO_SOURCE_HURTPROPERTY_H
#define SPYRO_SOURCE_HURTPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class HurtProperty;
class KDProperty;
class KDPropertySet;
class MKIniLine;

class HurtProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    void DoHurt(void);
    HurtProperty(void);
    static u8 classInfo[0x10];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ void** unk14;
    /* 0x018 */ MKIniLine* unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ u8 unk20;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 HurtProperty::GetInstanceDataSize() const {
    return 1;
}

inline s32 HurtProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *HurtProperty::GetClassInfo() const {
    return (HurtProperty *) HurtProperty::classInfo;
}

#endif  // SPYRO_SOURCE_HURTPROPERTY_H

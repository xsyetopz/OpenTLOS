#ifndef SPYRO_SOURCE_BOBPROPERTY_H
#define SPYRO_SOURCE_BOBPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class BobProperty;
class KDProperty;
class KDPropertySet;
class MKDynamicBone;
class MKIniLine;
class MKModel;

class BobProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    void UpdateDynamicBone(MKDynamicBone *, void *);
    BobProperty(void);
    static u8 classInfo[0x10];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ u32 unk14;
    /* 0x018 */ MKIniLine* unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ void* unk20;
    /* 0x024 */ MKModel* unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ s32 unk34;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 BobProperty::GetInstanceDataSize() const {
    return 0x70;
}

inline s32 BobProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *BobProperty::GetClassInfo() const {
    return (BobProperty *) BobProperty::classInfo;
}

#endif  // SPYRO_SOURCE_BOBPROPERTY_H

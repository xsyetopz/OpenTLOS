#ifndef SPYRO_SOURCE_SWAYPROPERTY_H
#define SPYRO_SOURCE_SWAYPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDProperty;
class KDPropertySet;
class MKDynamicBone;
class MKIniLine;
class MKModel;
class SwayProperty;

class SwayProperty : public KDProperty {  // base: ctor/dtor vtable stores
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
    SwayProperty(void);
    static u8 classInfo[0x10];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s8* unk10;
    /* 0x014 */ u32 unk14;
    /* 0x018 */ MKIniLine* unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ void* unk20;
    /* 0x024 */ MKModel* unk24;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ s32 unk34;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 SwayProperty::GetInstanceDataSize() const {
    return 0x90;
}

inline s32 SwayProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *SwayProperty::GetClassInfo() const {
    return &SwayProperty::classInfo;
}

#endif  // SPYRO_SOURCE_SWAYPROPERTY_H

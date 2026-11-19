#ifndef SPYRO_SOURCE_WOBBLEPROPERTY_H
#define SPYRO_SOURCE_WOBBLEPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDProperty;
class KDPropertySet;
class MKIniLine;
class WobbleProperty;

class WobbleProperty : public KDProperty {  // base: ctor/dtor vtable stores
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
    WobbleProperty(void);
    static u8 classInfo[0x10];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ u8 pad28[0x4];
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s32 unk3C;
    /* 0x040 */ u8 unk40;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 WobbleProperty::GetInstanceDataSize() const {
    return 0x10;
}

inline s32 WobbleProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *WobbleProperty::GetClassInfo() const {
    return (WobbleProperty *) WobbleProperty::classInfo;
}

#endif  // SPYRO_SOURCE_WOBBLEPROPERTY_H

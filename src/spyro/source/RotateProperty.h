#ifndef SPYRO_SOURCE_ROTATEPROPERTY_H
#define SPYRO_SOURCE_ROTATEPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDProperty;
class KDPropertySet;
class MKDynamicBone;
class MKIniLine;
class MKModel;
class RotateProperty;

class RotateProperty : public KDProperty {  // base: ctor/dtor vtable stores
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
    RotateProperty(void);
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
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ s32 unk30;
};

#endif  // SPYRO_SOURCE_ROTATEPROPERTY_H

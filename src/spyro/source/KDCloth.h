#ifndef SPYRO_SOURCE_KDCLOTH_H
#define SPYRO_SOURCE_KDCLOTH_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDClothDescriptor;
class KDClothProperty;
class KDProperty;
class KDPropertySet;
class MKIniLine;
class MKModel;

class KDClothDescriptor {
public:
    void Update(MKModel *);
    void Apply(MKModel *);
    void Resolve(MKModel *);
    u8 LoadLine(MKIniLine *);
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s8* unk14;
    /* 0x018 */ s32 unk18;
};

class KDClothProperty : public KDProperty {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual void LoadDoneInstance(void);
    virtual void Update(void);
    static u8 classInfo[0x10];
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ KDClothDescriptor unk14;
};

#endif  // SPYRO_SOURCE_KDCLOTH_H

#ifndef SPYRO_SOURCE_ANIMPROPERTY_H
#define SPYRO_SOURCE_ANIMPROPERTY_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class AnimProperty;
class KDAnimScriptProperty;
class KDProperty;
class KDPropertySet;
class MKIniLine;

class AnimProperty : public KDProperty {  // base: inlined ctor vtable stores
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
    static u8 classInfo[0x10];
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ KDAnimScriptProperty* unk10;
    /* 0x014 */ void* unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ f32 unk20;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 AnimProperty::GetInstanceDataSize() const {
    return 8;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
inline void AnimProperty::InitInstance() {
    void *temp_r3_22;

    temp_r3_22 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_22, s8 *, 0) = 1;
    M2C_FIELD(temp_r3_22, s32 *, 4) = 0;
}
#endif

inline s32 AnimProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *AnimProperty::GetClassInfo() const {
    return (AnimProperty *) AnimProperty::classInfo;
}

#endif  // SPYRO_SOURCE_ANIMPROPERTY_H

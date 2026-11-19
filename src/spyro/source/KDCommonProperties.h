#ifndef SPYRO_SOURCE_KDCOMMONPROPERTIES_H
#define SPYRO_SOURCE_KDCOMMONPROPERTIES_H

#include <dolphin/types.h>
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDProperty.h"

class KDAmbientSoundProperty;
class KDAnimEventProperty;
class KDAnimProperty;
class KDCommonProperties_cpp;
class KDMatrixProperty;
class KDMessageHandlerProperty;
class KDPathFollowerProperty;
class KDPathProperty;
class KDProperty;
class KDPropertyClassRegistry;
class KDPropertySet;
class KDRefPointProperty;
class KDScriptProperty;
class KDSoundAttachmentProperty;
class MKAnim;
class MKIniLine;
class MKMessage;

class KDSoundAttachmentProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual void Init(const char *);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s8* unk14;
    /* 0x018 */ s8* unk18;
};

class KDAmbientSoundProperty : public KDSoundAttachmentProperty {  // base: inlined ctor vtable stores
public:
    virtual void Init(const char *);
    virtual s32 LoadLine(MKIniLine *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x01c */ u8 unk1C;
    /* 0x01d */ u8 pad1D[0x3];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
};

class KDAnimEventProperty : public KDScriptProperty {  // base: ctor/dtor vtable stores
public:
    virtual void Deinit(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual void Update(void);
    KDAnimEventProperty(void);
    static u8 classInfo[0x10];
    /* 0x01c */ void* unk1C;
    /* 0x020 */ s8* unk20;
};

class KDAnimProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x010 */ void* unk10;
    /* 0x014 */ MKAnim* unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 unk1C;
};

class KDCommonProperties_cpp {
public:
    void __sinit(void);
};

class KDMessageHandlerProperty : public KDScriptProperty {  // base: ctor/dtor vtable stores
public:
    virtual void Init(const char *);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual s32 GetInstanceDataAlignment(void) const;
    virtual void InitInstance(void);
    virtual void Trigger(void);
    virtual void Message(MKMessage *);
    KDMessageHandlerProperty(void);
    static u8 classInfo[0x10];
    /* 0x01c */ s32 unk1C;
    /* 0x020 */ KDMessageHandlerProperty* unk20;
    /* 0x024 */ u8 unk24;
};

class KDPathFollowerProperty : public KDProperty {  // base: inlined ctor vtable stores
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
    void UpdateSplinePath(void);
    void UpdateNormalPath(void);
    static u8 classInfo[0x10];
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 pad11[0x3];
    /* 0x014 */ KDPathProperty* unk14;
    /* 0x018 */ void** unk18;
};

class KDRefPointProperty : public KDMatrixProperty {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual void Update(void);
    KDRefPointProperty(void);
    static u8 classInfo[0x10];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ u32 unk14;
};

void KDCommonProperties_RegisterAll(KDPropertyClassRegistry *);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline s32 KDAmbientSoundProperty::GetInstanceDataSize() const {
    return 0x2C;
}

inline s32 KDAmbientSoundProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *KDAmbientSoundProperty::GetClassInfo() const {
    return (KDAmbientSoundProperty *) KDAmbientSoundProperty::classInfo;
}

inline void KDAnimEventProperty::Deinit() {
    this->unk10.Deinit();
}

inline s32 KDAnimEventProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *KDAnimEventProperty::GetClassInfo() const {
    return (KDAnimEventProperty *) KDAnimEventProperty::classInfo;
}

inline KDAnimEventProperty::KDAnimEventProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk10.unk0 = 0;
    this->unk10.unk4 = NULL;
    this->unk10.unk4 = NULL;
    this->unk10.unk8 = 0;
    this->unk1C = NULL;
    this->unk20 = NULL;
}

inline void *KDAnimProperty::GetClassInfo() const {
    return (KDAnimProperty *) KDAnimProperty::classInfo;
}

inline s32 KDMessageHandlerProperty::GetInstanceDataSize() const {
    return 1;
}

inline s32 KDMessageHandlerProperty::GetInstanceDataAlignment() const {
    return 4;
}

inline void *KDMessageHandlerProperty::GetClassInfo() const {
    return (KDMessageHandlerProperty *) KDMessageHandlerProperty::classInfo;
}

inline KDMessageHandlerProperty::KDMessageHandlerProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk10.unk0 = 0;
    this->unk10.unk4 = NULL;
    this->unk10.unk4 = NULL;
    this->unk10.unk8 = 0;
    this->unk1C = 0;
    this->unk20 = NULL;
}

inline s32 KDPathFollowerProperty::GetInstanceDataSize() const {
    return 0x1C;
}

inline s32 KDPathFollowerProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *KDPathFollowerProperty::GetClassInfo() const {
    return (KDPathFollowerProperty *) KDPathFollowerProperty::classInfo;
}

inline s32 KDRefPointProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *KDRefPointProperty::GetClassInfo() const {
    return (KDRefPointProperty *) KDRefPointProperty::classInfo;
}

inline KDRefPointProperty::KDRefPointProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk10 = (signed char *) ("defaultModel");
    this->unk14 = 0;
}

inline s32 KDSoundAttachmentProperty::GetInstanceDataSize() const {
    return 4;
}

inline void *KDSoundAttachmentProperty::GetClassInfo() const {
    return (KDSoundAttachmentProperty *) KDSoundAttachmentProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDCOMMONPROPERTIES_H

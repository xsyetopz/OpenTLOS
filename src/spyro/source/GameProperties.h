#ifndef SPYRO_SOURCE_GAMEPROPERTIES_H
#define SPYRO_SOURCE_GAMEPROPERTIES_H

#include <dolphin/types.h>
#include "spyro/source/KDCommonProperties.h"
#include "spyro/source/KDProperty.h"

class CameraShakeProperty;
class CollisionSphereProperty;
class EventMessageProperty;
class GameProperties_cpp;
class KDMessageHandlerProperty;
class KDProperty;
class KDPropertyCommandList;
class KDPropertySet;
class KDScriptProperty;
class MKIniLine;
class MessageBroadcasterProperty;
class MessageHandlerProperty;
class TimerProperty;

class CameraShakeProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

class CollisionSphereProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual void Init(const char *);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void ResolveInstance(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u32 unk1C;
};

class EventMessageProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual void Init(const char *);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ s8* unk10;
};

class GameProperties_cpp {
public:
    void __sinit(void);
};

class MessageBroadcasterProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual void Init(const char *);
    virtual s32 LoadLine(MKIniLine *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s8* unk14;
    /* 0x018 */ s32 unk18;
};

class MessageHandlerProperty : public KDMessageHandlerProperty {  // base: vtable prefix
public:
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    MessageHandlerProperty(void);
    static u8 classInfo[0x10];
    /* 0x004 */ u8 pad4[0x18];
    /* 0x01c */ s8* unk1C;
};

class TimerProperty : public KDScriptProperty {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 GetInstanceDataSize(void) const;
    virtual s32 GetInstanceDataAlignment(void) const;
    virtual void InitInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    TimerProperty(void);
    static u8 classInfo[0x10];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ KDPropertyCommandList unk10;
    /* 0x01c */ f32 unk1C;
};

void GameProperties_RegisterAll(void);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void *CameraShakeProperty::GetClassInfo() const {
    return (CameraShakeProperty *) CameraShakeProperty::classInfo;
}

inline s32 CollisionSphereProperty::GetInstanceDataSize() const {
    return 4;
}

#if 0 // DRAFT: pointer/array required
inline void CollisionSphereProperty::InitInstance() {
    *(*KDProperty::pInstanceMem + this->unk8) = *KDProperty::pInstanceMem + 0x70;
}
#endif

inline void *CollisionSphereProperty::GetClassInfo() const {
    return (CollisionSphereProperty *) CollisionSphereProperty::classInfo;
}

inline s32 EventMessageProperty::GetInstanceDataSize() const {
    return 4;
}

inline void *EventMessageProperty::GetClassInfo() const {
    return (EventMessageProperty *) EventMessageProperty::classInfo;
}

inline s32 MessageBroadcasterProperty::GetInstanceDataSize() const {
    return 1;
}

#if 0 // DRAFT: pointer/array required
inline void MessageBroadcasterProperty::InitInstance() {
    *(*KDProperty::pInstanceMem + this->unk8) = 1;
}
#endif

inline s32 MessageBroadcasterProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *MessageBroadcasterProperty::GetClassInfo() const {
    return (MessageBroadcasterProperty *) MessageBroadcasterProperty::classInfo;
}

inline void *MessageHandlerProperty::GetClassInfo() const {
    return (MessageHandlerProperty *) MessageHandlerProperty::classInfo;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline MessageHandlerProperty::MessageHandlerProperty() {
    return this;
}
#endif

inline s32 TimerProperty::GetInstanceDataSize() const {
    return 8;
}

inline s32 TimerProperty::GetInstanceDataAlignment() const {
    return 4;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
inline void TimerProperty::InitInstance() {
    void *temp_r3_1014;

    temp_r3_1014 = *KDProperty::pInstanceMem + this->unk8;
    M2C_FIELD(temp_r3_1014, f32 *, 0) = 0.0f;
    M2C_FIELD(temp_r3_1014, s8 *, 4) = 0;
}
#endif

inline s32 TimerProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *TimerProperty::GetClassInfo() const {
    return (TimerProperty *) TimerProperty::classInfo;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline TimerProperty::TimerProperty() {
    this->unk4 = NULL;
    this->unkC = NULL;
    this->unk8 = 0;
    this->unk10.unk0 = 0;
    this->unk10.unk4 = NULL;
    this->unk10.unk4 = NULL;
    this->unk10.unk8 = 0;
    this->unk1C = 1.0f;
    return this;
}
#endif

#endif  // SPYRO_SOURCE_GAMEPROPERTIES_H

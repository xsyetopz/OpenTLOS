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

class CameraShakeProperty : public KDProperty {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual void Command(int);
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
};

class CollisionSphereProperty : public KDProperty {  // base: vtable prefix
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
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u32 unk1C;
};

class EventMessageProperty : public KDProperty {  // base: vtable prefix
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
    /* 0x004 */ s8* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ s8* unk10;
};

class GameProperties_cpp {
public:
    void __sinit(void);
};

class MessageBroadcasterProperty : public KDProperty {  // base: vtable prefix
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
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ KDPropertyCommandList unk10;
    /* 0x01c */ f32 unk1C;
};

void GameProperties_RegisterAll(void);
#endif  // SPYRO_SOURCE_GAMEPROPERTIES_H

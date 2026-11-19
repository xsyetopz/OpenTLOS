#ifndef SPYRO_SOURCE_KDPROPERTY_H
#define SPYRO_SOURCE_KDPROPERTY_H

#include <dolphin/types.h>

class KDProperty;
class KDPropertyClassInfo;
class KDPropertyClassRegistry;
class KDPropertyCommand;
class KDPropertyCommandList;
class KDPropertySet;
class KDProperty_cpp;
class KDScriptProperty;
class MKIniLine;
class MKProp;

class KDProperty {
public:
    virtual void Init(const char *);
    virtual void Deinit(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const = 0;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual s32 GetInstanceDataAlignment(void) const;
    virtual void InitInstance(void);
    virtual void DeinitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    s32 IsOfType(KDPropertyClassInfo *) const;
    void SetOwnerProp(MKProp *);
    u64 GetOwnerProp(void);
    static u8 pInstanceMem[0x4];
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ KDProperty* unkC;
};

class KDPropertyClassInfo {
public:
    /* 0x000 */ s8* unk0;
    /* 0x004 */ u8 pad4[0x8];
    /* 0x00c */ KDPropertyClassInfo* unkC;
};

class KDPropertyClassRegistry {
public:
    KDPropertyClassInfo * Find(const char *);
    void Add(KDPropertyClassInfo *);
    /* 0x000 */ KDPropertyClassInfo* unk0;
};

class KDPropertyCommand {
public:
    void Resolve(KDPropertySet *);
    s32 LoadLine(MKIniLine *, const char *);
    /* 0x000 */ KDPropertyCommand* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ KDPropertyCommand* unkC;
};

class KDPropertyCommandList {
public:
    u8 LoadLine(MKIniLine *, const char *);
    void Deinit(void);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ KDPropertyCommand* unk4;
    /* 0x008 */ s32 unk8;
};

class KDPropertySet {
public:
    KDPropertyCommand * Find(const char *);
    s32 AllocInstanceMem(int, int);
    void LoadDone(void);
    s32 LoadLine(MKIniLine *, KDPropertyClassRegistry *);
    void Remove(KDProperty *);
    void AddPublished(KDProperty *);
    void Add(KDProperty *);
    void Deinit(void);
    /* 0x000 */ KDProperty* unk0;
    /* 0x004 */ KDPropertyCommand* unk4;
    /* 0x008 */ KDPropertyCommand* unk8;
    /* 0x00c */ s32 unkC;
};

class KDProperty_cpp {
public:
    void __sinit(void);
};

class KDScriptProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual void Deinit(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 ResolveCommand(const char *) const;
    virtual void Command(int);
    virtual void Trigger(void);
    static u8 classInfo[0x10];
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ KDPropertyCommandList unk10;
};

#endif  // SPYRO_SOURCE_KDPROPERTY_H

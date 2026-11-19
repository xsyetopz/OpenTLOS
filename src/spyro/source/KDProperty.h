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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk4'
inline void KDProperty::Init(const char *arg0) {
    this->unk4 = arg0;
}
#endif

inline void KDProperty::Deinit() {

}

inline s32 KDProperty::LoadLine(MKIniLine *arg0) {
    return 0;
}

inline void KDProperty::LoadDone() {

}

inline void KDProperty::Resolve(KDPropertySet *arg0) {

}

inline s32 KDProperty::Query(int arg0) {
    return 0;
}

inline s32 KDProperty::ResolveCommand(const char *arg0) const {
    return 0;
}

inline void KDProperty::DeinitInstance() {

}

inline void KDProperty::LoadDoneInstance() {

}

inline void KDProperty::ResolveInstance() {

}

inline void KDProperty::Update() {

}

inline void KDProperty::Command(int arg0) {

}

inline s32 KDProperty::GetInstanceDataAlignment() const {
    return 4;
}

inline s32 KDProperty::LoadLineInstance(MKIniLine *arg0) {
    return 0;
}

inline s32 KDProperty::GetInstanceDataSize() const {
    return 0;
}

inline void KDProperty::InitInstance() {

}

#if 0 // DRAFT: expression syntax error
inline void KDProperty::SetOwnerProp(MKProp *arg0) {
    pInstanceMem.__vptr = this;
}
#endif

#if 0 // DRAFT: expression syntax error
inline u64 KDProperty::GetOwnerProp() {
    return (u64) pInstanceMem.__vptr;
}
#endif

inline void KDScriptProperty::Deinit() {
    this->unk10.Deinit();
}

inline s32 KDScriptProperty::LoadLine(MKIniLine *arg0) {
    return (u8) (this->unk10.LoadLine(arg0, "script") != 0);
}

#if 0 // DRAFT: expression syntax error
inline void KDScriptProperty::Resolve(KDPropertySet *arg0) {
    KDPropertyCommand **var_r31_40;
    s32 temp_r0_49;
    u8 var_r5_50;

    if ((s32) this->unk10.unk0 == 1) {
        var_r31_40 = &this->unk10.unk4;
    } else {
        var_r31_40 = &this->unk10.unk4->unk0;
    }
loop_9:
    if (var_r31_40 != NULL) {
        var_r31_40->Resolve(arg0);
        temp_r0_49 = this->unk10.unk0;
        var_r5_50 = 0;
        if ((temp_r0_49 > 1) && ((KDPropertyCommand **) (var_r31_40 + 8) < (void *) (this->unk10.unk4 + (temp_r0_49 * 8)))) {
            var_r5_50 = 1;
        }
        if (var_r5_50 != 0) {
            var_r31_40 += 8;
        } else {
            var_r31_40 = NULL;
        }
        goto loop_9;
    }
}
#endif

inline void *KDScriptProperty::GetClassInfo() const {
    return &classInfo;
}

inline void KDScriptProperty::Trigger() {
    KDPropertyCommand **var_r31_2435;
    KDPropertyCommand *temp_r3_2441;
    s32 temp_r0_2447;
    u8 var_r5_2448;

    if ((s32) this->unk10.unk0 == 1) {
        var_r31_2435 = &this->unk10.unk4;
    } else {
        var_r31_2435 = &this->unk10.unk4->unk0;
    }
loop_9:
    if (var_r31_2435 != NULL) {
        temp_r3_2441 = M2C_FIELD(var_r31_2435, KDPropertyCommand **, 0);
        M2C_FIELD(temp_r3_2441->unk0, M2C_UNK (**)(KDPropertyCommand *, s32), 0x48)(temp_r3_2441, M2C_FIELD(var_r31_2435, s32 *, 4));
        temp_r0_2447 = this->unk10.unk0;
        var_r5_2448 = 0;
        if ((temp_r0_2447 > 1) && ((KDPropertyCommand **) (var_r31_2435 + 8) < (void *) (this->unk10.unk4 + (temp_r0_2447 * 8)))) {
            var_r5_2448 = 1;
        }
        if (var_r5_2448 != 0) {
            var_r31_2435 += 8;
        } else {
            var_r31_2435 = NULL;
        }
        goto loop_9;
    }
}

#endif  // SPYRO_SOURCE_KDPROPERTY_H

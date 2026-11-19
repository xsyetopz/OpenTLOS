#ifndef SPYRO_SOURCE_KDPARTICLEEFFECTS_H
#define SPYRO_SOURCE_KDPARTICLEEFFECTS_H

#include <dolphin/types.h>
#include "spyro/source/KDProperty.h"

class KDParticleBoxEmitterProperty;
class KDParticleEffects_cpp;
class KDParticleEmitterProperty;
class KDParticleLineEmitterProperty;
class KDParticleSystemProperty;
class KDProperty;
class KDPropertyClassRegistry;
class KDPropertySet;
class MKIniLine;
class MKVector3;
class MKVector4;

class KDParticleEmitterProperty : public KDProperty {  // base: ctor/dtor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual s32 GetInstanceDataAlignment(void) const;
    virtual void InitInstance(void);
    virtual s32 LoadLineInstance(MKIniLine *);
    virtual void LoadDoneInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    virtual void SetColor(MKVector4);
    virtual MKVector3 GetColor(void);
    KDParticleEmitterProperty(void);
    static u8 classInfo[0x10];
    /* 0x010 */ MKIniLine* unk10;
    /* 0x014 */ s8* unk14;
    /* 0x018 */ KDParticleSystemProperty* unk18;
    /* 0x01c */ s8* unk1C;
    /* 0x020 */ void** unk20;
};

class KDParticleBoxEmitterProperty : public KDParticleEmitterProperty {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x028 */ f64 unk28;
    /* 0x030 */ f64 unk30;
    /* 0x038 */ f64 unk38;
    /* 0x040 */ f64 unk40;
};

class KDParticleEffects_cpp {
public:
    void __sinit(void);
};

class KDParticleLineEmitterProperty : public KDParticleEmitterProperty {  // base: vtable prefix
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x028 */ void* unk28;
};

class KDParticleSystemProperty : public KDProperty {  // base: inlined ctor vtable stores
public:
    virtual s32 LoadLine(MKIniLine *);
    virtual void Resolve(KDPropertySet *);
    virtual void * GetClassInfo(void) const;
    virtual s32 Query(int);
    virtual s32 ResolveCommand(const char *) const;
    virtual s32 GetInstanceDataSize(void) const;
    virtual void InitInstance(void);
    virtual void ResolveInstance(void);
    virtual void Update(void);
    virtual void Command(int);
    static u8 classInfo[0x10];
    /* 0x010 */ s8* unk10;
    /* 0x014 */ void** unk14;
    /* 0x018 */ u8 unk18;
};

void KDParticleEffects_RegisterAll(KDPropertyClassRegistry *);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 KDParticleBoxEmitterProperty::GetInstanceDataSize() const {
    return 0x98;
}

inline s32 KDParticleBoxEmitterProperty::Query(int arg0) {
    if (arg0 == 1) {
        return 1;
    }
    return arg0 == 1;
}

inline void *KDParticleBoxEmitterProperty::GetClassInfo() const {
    return (KDParticleBoxEmitterProperty *) KDParticleBoxEmitterProperty::classInfo;
}

inline s32 KDParticleEmitterProperty::GetInstanceDataAlignment() const {
    return 0x10;
}

inline s32 KDParticleEmitterProperty::LoadLineInstance(MKIniLine *arg0) {
    void **temp_r3_52;

    temp_r3_52 = (void **) (*KDProperty::pInstanceMem + this->unk8);
    M2C_FIELD(*temp_r3_52, M2C_UNK (**)(void **, s32), 0xC)(temp_r3_52, *KDProperty::pInstanceMem);
}

inline void KDParticleEmitterProperty::LoadDoneInstance() {
    void **temp_r3_71;

    temp_r3_71 = (void **) (*KDProperty::pInstanceMem + this->unk8);
    M2C_FIELD(*temp_r3_71, M2C_UNK (**)(void **, s32), 0x10)(temp_r3_71, *KDProperty::pInstanceMem);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector4'
inline void KDParticleEmitterProperty::SetColor(MKVector4 arg0) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_90;
    f64 temp_f1_86;
    void *temp_r3_91;

    temp_f1_86 = M2C_FIELD(arg0, f64 *, 0);
    temp_f0_90 = M2C_FIELD(arg0, f64 *, 8);
    temp_r3_91 = (void *) (*KDProperty::pInstanceMem + (this->unk8 + 8));
    sp8 = temp_f1_86;
    M2C_FIELD(temp_r3_91, f64 *, 0) = temp_f1_86;
    sp10 = temp_f0_90;
    M2C_FIELD(temp_r3_91, f64 *, 8) = temp_f0_90;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
inline MKVector3 KDParticleEmitterProperty::GetColor() {
    MKVector3 result;
    MKVector3 *sret = &result;
    void *temp_r4_106;

    temp_r4_106 = (void *) (*KDProperty::pInstanceMem + (this->unk8 + 8));
    M2C_FIELD(sret, f64 *, 0) = (f64) M2C_FIELD(temp_r4_106, f64 *, 0);
    M2C_FIELD(sret, f64 *, 8) = (f64) M2C_FIELD(temp_r4_106, f64 *, 8);
    return result;
}
#endif

inline s32 KDParticleEmitterProperty::GetInstanceDataSize() const {
    return 0x78;
}

inline s32 KDParticleEmitterProperty::Query(int arg0) {
    return arg0 == 1;
}

inline void *KDParticleEmitterProperty::GetClassInfo() const {
    return (KDParticleEmitterProperty *) KDParticleEmitterProperty::classInfo;
}

inline s32 KDParticleLineEmitterProperty::GetInstanceDataSize() const {
    return 0x80;
}

inline s32 KDParticleLineEmitterProperty::Query(int arg0) {
    if (arg0 == 1) {
        return 1;
    }
    return arg0 == 1;
}

inline void *KDParticleLineEmitterProperty::GetClassInfo() const {
    return (KDParticleLineEmitterProperty *) KDParticleLineEmitterProperty::classInfo;
}

inline s32 KDParticleSystemProperty::GetInstanceDataSize() const {
    return 4;
}

inline s32 KDParticleSystemProperty::Query(int arg0) {
    if (arg0 == 1) {
        return this->unk18;
    }
    return 0U;
}

inline void *KDParticleSystemProperty::GetClassInfo() const {
    return (KDParticleSystemProperty *) KDParticleSystemProperty::classInfo;
}

#endif  // SPYRO_SOURCE_KDPARTICLEEFFECTS_H

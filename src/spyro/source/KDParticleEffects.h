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
    virtual void GetColor(void);
    KDParticleEmitterProperty(void);
    static u8 classInfo[0x10];
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
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
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ MKIniLine* unk10;
    /* 0x014 */ u8 pad14[0xc];
    /* 0x020 */ void** unk20;
    /* 0x024 */ u8 pad24[0x4];
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
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ s32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ MKIniLine* unk10;
    /* 0x014 */ u8 pad14[0xc];
    /* 0x020 */ void** unk20;
    /* 0x024 */ s8* unk24;
    /* 0x028 */ void* unk28;
};

class KDParticleSystemProperty : public KDProperty {  // base: vtable prefix
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
    /* 0x004 */ u8 pad4[0x14];
    /* 0x018 */ u8 unk18;
};

void KDParticleEffects_RegisterAll(KDPropertyClassRegistry *);
#endif  // SPYRO_SOURCE_KDPARTICLEEFFECTS_H

#ifndef SPYRO_SOURCE_ENEMIES_EARTH_H
#define SPYRO_SOURCE_ENEMIES_EARTH_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class EarthTier1;
class EarthTier1Descriptor;
class EarthTier2;
class EarthTier3;
class EarthTier3Descriptor;
class Enemies_Earth_cpp;
class Enemy;
class EnemyDescriptor;

class EarthTier1 : public Enemy {  // base: vtable prefix
public:
    virtual ~EarthTier1(void);
    virtual void Init(void);
    virtual void Update(void);
    EarthTier1(void);
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ f32 unkB10;
};

class EarthTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    EarthTier1Descriptor(void);
};

class EarthTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~EarthTier2(void);
    virtual void Init(void);
    virtual void Update(void);
    EarthTier2(void);
};

class EarthTier3 : public Enemy {  // base: vtable prefix
public:
    virtual ~EarthTier3(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    EarthTier3(void);
};

class EarthTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    EarthTier3Descriptor(void);
};

class Enemies_Earth_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthTier1::EarthTier1() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthTier1::~EarthTier1() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline EarthTier1Descriptor::EarthTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthTier2::EarthTier2() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthTier2::~EarthTier2() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthTier3::EarthTier3() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline EarthTier3::~EarthTier3() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline EarthTier3Descriptor::EarthTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_EARTH_H

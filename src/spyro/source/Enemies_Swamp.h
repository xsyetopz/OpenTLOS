#ifndef SPYRO_SOURCE_ENEMIES_SWAMP_H
#define SPYRO_SOURCE_ENEMIES_SWAMP_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class EarthShockwave;
class Enemies_Swamp_cpp;
class Enemy;
class EnemyDescriptor;
class Matrix;
class SpawnPointRef;
class SwampTier1;
class SwampTier1Descriptor;
class SwampTier2;
class SwampTier2Descriptor;
class SwampTier3;
class SwampTier3Descriptor;

class Enemies_Swamp_cpp {
public:
    void __sinit(void);
};

class SwampTier1 : public Enemy {  // base: vtable prefix
public:
    virtual ~SwampTier1(void);
    virtual void Init(void);
    virtual void CheckAnimEvents(void);
    virtual void GetCharacterName(void);
    SwampTier1(void);
};

class SwampTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    SwampTier1Descriptor(void);
};

class SwampTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~SwampTier2(void);
    virtual void Init(void);
    virtual void Draw(void);
    virtual void CheckAnimEvents(void);
    SwampTier2(void);
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
    /* 0xb18 */ f32 unkB18;
    /* 0xb1c */ f32 unkB1C;
};

class SwampTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    SwampTier2Descriptor(void);
};

class SwampTier3 : public Enemy {  // base: vtable prefix
public:
    virtual ~SwampTier3(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual u8 CanMoveAwayFromHero(void);
    SwampTier3(void);
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ s8 unkB10;
    /* 0xb11 */ u8 padB11[0x3];
    /* 0xb14 */ f32 unkB14;
    /* 0xb18 */ f32 unkB18;
    /* 0xb1c */ EarthShockwave* unkB1C;
};

class SwampTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    SwampTier3Descriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline SwampTier1::SwampTier1() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SwampTier1::~SwampTier1() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampTier1Descriptor::SwampTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SwampTier2::SwampTier2() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SwampTier2::~SwampTier2() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampTier2Descriptor::SwampTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SwampTier3::SwampTier3() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SwampTier3::~SwampTier3() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampTier3Descriptor::SwampTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_SWAMP_H

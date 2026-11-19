#ifndef SPYRO_SOURCE_ENEMIES_SWAMP_H
#define SPYRO_SOURCE_ENEMIES_SWAMP_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

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
};

class SwampTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    SwampTier3Descriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline SwampTier1::SwampTier1() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline SwampTier1::~SwampTier1() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampTier1Descriptor::SwampTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline SwampTier2::SwampTier2() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline SwampTier2::~SwampTier2() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampTier2Descriptor::SwampTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline SwampTier3::SwampTier3() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline SwampTier3::~SwampTier3() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SwampTier3Descriptor::SwampTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_SWAMP_H

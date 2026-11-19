#ifndef SPYRO_SOURCE_ENEMIES_FIRE_H
#define SPYRO_SOURCE_ENEMIES_FIRE_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class Enemies_Fire_cpp;
class Enemy;
class EnemyDescriptor;
class FireTier1;
class FireTier1Descriptor;
class FireTier2;
class FireTier2Descriptor;
class FireTier3;
class FireTier3Descriptor;
class MKMessage;
class MKVector3;
class Matrix;
class SpawnPointRef;

class Enemies_Fire_cpp {
public:
    void __sinit(void);
};

class FireTier1 : public Enemy {  // base: vtable prefix
public:
    virtual ~FireTier1(void);
    virtual void Init(void);
    virtual void SetDefaults(void);
    virtual void UpdateMovementCustom(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void GetCharacterName(void);
    virtual void DoDeadFx(void);
    FireTier1(void);
    s32 SelectMoveToWallPos(const MKVector3 &, const MKVector3 &, MKVector3 *);
    s32 SelectFlyToWallPos(const MKVector3 &, MKVector3 *, MKVector3 *, MKVector3 *);
};

class FireTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    FireTier1Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
};

class FireTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~FireTier2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMovementCustom(void);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void DoDeadFx(void);
    FireTier2(void);
};

class FireTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    FireTier2Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
};

class FireTier3 : public Enemy {  // base: vtable prefix
public:
    virtual ~FireTier3(void);
    virtual void Init(void);
    virtual void Message(MKMessage *);
    virtual void DoDeadFx(void);
    FireTier3(void);
};

class FireTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    FireTier3Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline FireTier1::FireTier1() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline FireTier1::~FireTier1() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireTier1Descriptor::FireTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline FireTier2::FireTier2() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline FireTier2::~FireTier2() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireTier2Descriptor::FireTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline FireTier3::FireTier3() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline FireTier3::~FireTier3() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireTier3Descriptor::FireTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_FIRE_H

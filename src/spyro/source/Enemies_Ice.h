#ifndef SPYRO_SOURCE_ENEMIES_ICE_H
#define SPYRO_SOURCE_ENEMIES_ICE_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class Enemies_Ice_cpp;
class Enemy;
class EnemyDescriptor;
class EnemyGeneratorDoor;
class IceTier1;
class IceTier1Descriptor;
class IceTier2;
class IceTier2Descriptor;
class IceTier3;
class MKMaterial;
class MKMessage;
class MKVector3;
class Matrix;
class SpawnPointRef;

class Enemies_Ice_cpp {
public:
    void __sinit(void);
};

class IceTier1 : public Enemy {  // base: vtable prefix
public:
    virtual ~IceTier1(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Spawn(EnemyGeneratorDoor *);
    IceTier1(void);
};

class IceTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceTier1Descriptor(void);
};

class IceTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~IceTier2(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void * GetCollisionInfo(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void OnArmourDestroyed(void);
    virtual void DrawCustomGlow(void);
    IceTier2(void);
};

class IceTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceTier2Descriptor(void);
    /* 0x2b4 */ MKMaterial* unk2B4;
    /* 0x2b8 */ s32 unk2B8;
    /* 0x2bc */ s32 unk2BC;
};

class IceTier3 : public Enemy {  // base: vtable prefix
public:
    virtual ~IceTier3(void);
    virtual void Init(void);
    IceTier3(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline IceTier1::IceTier1() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline IceTier1::~IceTier1() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceTier1Descriptor::IceTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline IceTier2::IceTier2() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unk110.unkA28 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline IceTier2::~IceTier2() {
    this->unk110.unk5A8 = &__vt.unk84;
    if ((&this->unk110.unkA28 != NULL) && (&this->unk110.unkA28 != NULL)) {
        KDSound_Stop(&this->unk110.unkA28.unk0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9D4'
inline void *IceTier2::GetCollisionInfo() {
    if ((s32) this->unk110.unk9D4 == 0) {
        return this->unk110.unk524;
    }
    return this->unk110.unkA04;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceTier2Descriptor::IceTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline IceTier3::IceTier3() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline IceTier3::~IceTier3() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_ICE_H

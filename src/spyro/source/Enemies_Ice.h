#ifndef SPYRO_SOURCE_ENEMIES_ICE_H
#define SPYRO_SOURCE_ENEMIES_ICE_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/Goal.h"

class Enemies_Ice_cpp;
class Enemy;
class EnemyDescriptor;
class EnemyGeneratorDoor;
class IceTier1;
class IceTier1Descriptor;
class IceTier2;
class IceTier2Descriptor;
class IceTier3;
class MKCollisionInfo;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ Goal<Enemy>* unkB10;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ MKCollisionInfo* unkB10;
    /* 0xb14 */ MKCollisionInfo* unkB14;
    /* 0xb18 */ f64 unkB18;
    /* 0xb20 */ f64 unkB20;
    /* 0xb28 */ MKVector3 unkB28;
    /* 0xb38 */ s32 unkB38;
    /* 0xb3c */ u8 padB3C[0x24];
    /* 0xb60 */ u8 unkB60;
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

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline IceTier1::IceTier1() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline IceTier1::~IceTier1() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceTier1Descriptor::IceTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline IceTier2::IceTier2() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    M2C_FIELD(this, s32 *, 0xB38) = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline IceTier2::~IceTier2() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
    if ((&this->unkB20 != NULL) && (&this->unkB20 != NULL)) {
        KDSound_Stop((s32 *) &this->unkB20);
    }
}
#endif

inline void *IceTier2::GetCollisionInfo() {
    if (M2C_BITWISE(s32, this->unkACC) == 0) {
        return (MKCollisionInfo *) this->unk634;
    }
    return (MKCollisionInfo *) this->unkAFC;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline IceTier2Descriptor::IceTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline IceTier3::IceTier3() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline IceTier3::~IceTier3() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_ICE_H

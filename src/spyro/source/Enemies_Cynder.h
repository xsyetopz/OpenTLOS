#ifndef SPYRO_SOURCE_ENEMIES_CYNDER_H
#define SPYRO_SOURCE_ENEMIES_CYNDER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/Goal.h"

class Ball;
class CynderTier1;
class CynderTier1Descriptor;
class CynderTier2;
class CynderTier2Descriptor;
class CynderTier2Train;
class CynderTier2TrainDescriptor;
class CynderTier3;
class CynderTier3Descriptor;
class Enemies_Cynder_cpp;
class Enemy;
class EnemyDescriptor;
class EnemyGeneratorDoor;
class EnemyTest;
class EnemyTestDescriptor;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class SpawnPointObject;

class CynderTier1 : public Enemy {  // base: base ctor call
public:
    virtual ~CynderTier1(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(SpawnPointObject *);
    virtual void Spawn(EnemyGeneratorDoor *);
    virtual s32 TryFreezeBall(void);
    virtual void UpdateFrozenBallMovement(void);
    virtual void DefrostBall(void);
    virtual s32 IsInFrozenBall(void);
    CynderTier1(void);
    /* 0xb10 */ Goal<Enemy>* unkB10;
    /* 0xb14 */ Goal<Enemy>* unkB14;
    /* 0xb18 */ MKPropDescriptor* unkB18;
    /* 0xb1c */ Ball* unkB1C;
};

class CynderTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderTier1Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
};

class CynderTier2 : public Enemy {  // base: base ctor call
public:
    virtual ~CynderTier2(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Spawn(EnemyGeneratorDoor *);
    CynderTier2(void);
    /* 0xb10 */ Goal<Enemy>* unkB10;
};

class CynderTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderTier2Descriptor(void);
    /* 0x2b4 */ s8 unk2B4;
};

class CynderTier2Train : public CynderTier2 {  // base: base ctor call
public:
    virtual ~CynderTier2Train(void);
    virtual void Init(void);
    virtual void UpdateMovementCustom(void);
    CynderTier2Train(void);
};

class CynderTier2TrainDescriptor : public CynderTier2Descriptor {  // base: base ctor call
public:
    virtual void Init(void);
    CynderTier2TrainDescriptor(void);
};

class CynderTier3 : public Enemy {  // base: base ctor call
public:
    virtual ~CynderTier3(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Spawn(EnemyGeneratorDoor *);
    CynderTier3(void);
    void EmitClubEffects(void);
    /* 0xb10 */ Goal<Enemy>* unkB10;
    /* 0xb14 */ u8 padB14[0x4];
    /* 0xb18 */ MKVector3 unkB18;
    /* 0xb28 */ s32 unkB28;
    /* 0xb2c */ u8 padB2C[0x24];
    /* 0xb50 */ f32 unkB50;
};

class CynderTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderTier3Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
};

class Enemies_Cynder_cpp {
public:
    void __sinit(void);
};

class EnemyTest : public Enemy {  // base: base ctor call
public:
    virtual ~EnemyTest(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    EnemyTest(void);
};

class EnemyTestDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    EnemyTestDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier1::CynderTier1() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier1::~CynderTier1() {
    this->unk6B8 = &__vt.unk84;
}
#endif

inline s32 CynderTier1::IsInFrozenBall() {
    return this->unkB1C != NULL;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderTier1Descriptor::CynderTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier2::CynderTier2() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier2::~CynderTier2() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderTier2Descriptor::CynderTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier2Train::CynderTier2Train() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier2Train::~CynderTier2Train() {
    this->unk6B8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderTier2TrainDescriptor::CynderTier2TrainDescriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier3::CynderTier3() {
    this->unk6B8 = &__vt + 0x84;
    this->unkB28 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline CynderTier3::~CynderTier3() {
    this->unk6B8 = &__vt.unk84;
    if ((&this->unkB28 != NULL) && (&this->unkB28 != NULL)) {
        KDSound_Stop(&this->unkB28);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderTier3Descriptor::CynderTier3Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline EnemyTest::EnemyTest() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline EnemyTest::~EnemyTest() {
    this->unk6B8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline EnemyTestDescriptor::EnemyTestDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_CYNDER_H

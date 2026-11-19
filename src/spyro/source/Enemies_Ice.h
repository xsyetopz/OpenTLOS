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

#endif  // SPYRO_SOURCE_ENEMIES_ICE_H

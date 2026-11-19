#ifndef SPYRO_SOURCE_ENEMIES_DOJO_H
#define SPYRO_SOURCE_ENEMIES_DOJO_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class DojoEnemy;
class DojoEnemyDescriptor;
class DojoTier1;
class DojoTier1Descriptor;
class DojoTier2;
class DojoTier2Descriptor;
class Enemies_Dojo_cpp;
class Enemy;
class EnemyDescriptor;
class MKMessage;
class SpawnPointObject;

class DojoEnemy : public Enemy {  // base: vtable prefix
public:
    virtual ~DojoEnemy(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual void Despawn(bool);
    virtual void Recycle(void);
    DojoEnemy(void);
};

class DojoEnemyDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    DojoEnemyDescriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
    /* 0x2bc */ s32 unk2BC;
    /* 0x2c0 */ s32 unk2C0;
};

class DojoTier1 : public Enemy {  // base: vtable prefix
public:
    virtual ~DojoTier1(void);
    virtual void Init(void);
    virtual void Despawn(bool);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(SpawnPointObject *);
    virtual void GetCharacterName(void);
    DojoTier1(void);
};

class DojoTier1Descriptor : public EnemyDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    DojoTier1Descriptor(void);
};

class DojoTier2 : public Enemy {  // base: vtable prefix
public:
    virtual ~DojoTier2(void);
    virtual void Init(void);
    virtual void Despawn(bool);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(SpawnPointObject *);
    virtual void GetCharacterName(void);
    DojoTier2(void);
};

class DojoTier2Descriptor : public EnemyDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    DojoTier2Descriptor(void);
};

class Enemies_Dojo_cpp {
public:
    void __sinit(void);
};

extern u8 dojoMovementThresholds[0x3c];
extern u8 dojoMovementAnims[0xf0];
#endif  // SPYRO_SOURCE_ENEMIES_DOJO_H

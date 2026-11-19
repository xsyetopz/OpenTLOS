#ifndef SPYRO_SOURCE_ENEMIES_DOJO_H
#define SPYRO_SOURCE_ENEMIES_DOJO_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class CharacterDojoFX;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ CharacterDojoFX* unkB10;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ CharacterDojoFX* unkB10;
    /* 0xb14 */ u8 padB14[0xc];
    /* 0xb20 */ s32 unkB20;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ CharacterDojoFX* unkB10;
    /* 0xb14 */ u8 padB14[0xc];
    /* 0xb20 */ s32 unkB20;
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
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoEnemy::~DojoEnemy() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoEnemy::DojoEnemy() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DojoEnemyDescriptor::DojoEnemyDescriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoTier1::DojoTier1() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoTier1::~DojoTier1() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DojoTier1Descriptor::DojoTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoTier2::DojoTier2() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoTier2::~DojoTier2() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DojoTier2Descriptor::DojoTier2Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_DOJO_H

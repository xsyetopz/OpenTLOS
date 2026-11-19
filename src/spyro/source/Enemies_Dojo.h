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

class DojoEnemy : public Enemy {  // base: base ctor call
public:
    virtual ~DojoEnemy(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual void Despawn(bool);
    virtual void Recycle(void);
    DojoEnemy(void);
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

class DojoTier1 : public DojoEnemy {  // base: base ctor call
public:
    virtual ~DojoTier1(void);
    virtual void Init(void);
    virtual void Despawn(bool);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(SpawnPointObject *);
    virtual s32 GetCharacterName(void);
    DojoTier1(void);
    /* 0xb18 */ u8 padB18[0x8];
    /* 0xb20 */ s32 unkB20;
};

class DojoTier1Descriptor : public DojoEnemyDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    DojoTier1Descriptor(void);
};

class DojoTier2 : public DojoEnemy {  // base: base ctor call
public:
    virtual ~DojoTier2(void);
    virtual void Init(void);
    virtual void Despawn(bool);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(SpawnPointObject *);
    virtual s32 GetCharacterName(void);
    DojoTier2(void);
    /* 0xb18 */ u8 padB18[0x8];
    /* 0xb20 */ s32 unkB20;
};

class DojoTier2Descriptor : public DojoEnemyDescriptor {  // base: base ctor call
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

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DojoEnemy::~DojoEnemy() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DojoEnemy::DojoEnemy() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

inline DojoEnemyDescriptor::DojoEnemyDescriptor() {
}

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DojoTier1::DojoTier1() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DojoTier1::~DojoTier1() {
    this->unk6B8 = &__vt.unk84;
}
#endif

inline DojoTier1Descriptor::DojoTier1Descriptor() {
}

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DojoTier2::DojoTier2() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DojoTier2::~DojoTier2() {
    this->unk6B8 = &__vt.unk84;
}
#endif

inline DojoTier2Descriptor::DojoTier2Descriptor() {
}

#endif  // SPYRO_SOURCE_ENEMIES_DOJO_H

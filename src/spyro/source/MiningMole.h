#ifndef SPYRO_SOURCE_MININGMOLE_H
#define SPYRO_SOURCE_MININGMOLE_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"

class Enemy;
class Exhumor;
class MKMessage;
class Matrix;
class MiningMole;
class MiningMoleLeader;
class SpawnPointRef;

class Exhumor : public Enemy {  // base: vtable prefix
public:
    virtual ~Exhumor(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Exhumor(void);
};

class MiningMole : public Enemy {  // base: vtable prefix
public:
    virtual ~MiningMole(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    MiningMole(void);
};

class MiningMoleLeader : public Enemy {  // base: vtable prefix
public:
    virtual ~MiningMoleLeader(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    MiningMoleLeader(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline Exhumor::Exhumor() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unk110.unkA04 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline Exhumor::~Exhumor() {
    this->unk110.unk5A8 = &__vt.unk84;
    if ((&this->unk110.unkA04 != NULL) && (&this->unk110.unkA04 != NULL)) {
        KDSound_Stop(&this->unk110.unkA04);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline MiningMole::MiningMole() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline MiningMole::~MiningMole() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline MiningMoleLeader::MiningMoleLeader() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unk110.unkA04 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline MiningMoleLeader::~MiningMoleLeader() {
    this->unk110.unk5A8 = &__vt.unk84;
    if ((&this->unk110.unkA04 != NULL) && (&this->unk110.unkA04 != NULL)) {
        KDSound_Stop(&this->unk110.unkA04);
    }
}
#endif

#endif  // SPYRO_SOURCE_MININGMOLE_H

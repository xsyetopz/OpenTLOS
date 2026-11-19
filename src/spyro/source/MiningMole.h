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
class MoleTether;
class NPCGoal_Think;
class SpawnPointRef;

class Exhumor : public Enemy {  // base: base ctor call
public:
    virtual ~Exhumor(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    Exhumor(void);
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
};

class MiningMole : public Enemy {  // base: base ctor call
public:
    virtual ~MiningMole(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    MiningMole(void);
    /* 0xb10 */ NPCGoal_Think* unkB10;
    /* 0xb14 */ MoleTether* unkB14;
};

class MiningMoleLeader : public Enemy {  // base: base ctor call
public:
    virtual ~MiningMoleLeader(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    MiningMoleLeader(void);
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline Exhumor::Exhumor() {
    this->unk6B8 = &__vt + 0x84;
    this->unkB14 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline Exhumor::~Exhumor() {
    this->unk6B8 = &__vt.unk84;
    if ((&this->unkB14 != NULL) && (&this->unkB14 != NULL)) {
        KDSound_Stop((int *) &this->unkB14);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline MiningMole::MiningMole() {
    this->unk6B8 = &__vt + 0x84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline MiningMole::~MiningMole() {
    this->unk6B8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline MiningMoleLeader::MiningMoleLeader() {
    this->unk6B8 = &__vt + 0x84;
    this->unkB14 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline MiningMoleLeader::~MiningMoleLeader() {
    this->unk6B8 = &__vt.unk84;
    if ((&this->unkB14 != NULL) && (&this->unkB14 != NULL)) {
        KDSound_Stop((int *) &this->unkB14);
    }
}
#endif

#endif  // SPYRO_SOURCE_MININGMOLE_H

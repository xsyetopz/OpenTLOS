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

class Exhumor : public Enemy {  // base: vtable prefix
public:
    virtual ~Exhumor(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    Exhumor(void);
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ NPCGoal_Think* unkB10;
    /* 0xb14 */ MoleTether* unkB14;
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
    /* 0xb0c */ u8 padB0C[0x4];
    /* 0xb10 */ s32 unkB10;
    /* 0xb14 */ s32 unkB14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline Exhumor::Exhumor() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    this->unkAFC = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline Exhumor::~Exhumor() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
    if ((&this->unkAFC != NULL) && (&this->unkAFC != NULL)) {
        KDSound_Stop(&this->unkAFC);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline MiningMole::MiningMole() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline MiningMole::~MiningMole() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline MiningMoleLeader::MiningMoleLeader() {
    M2C_FIELD(this, void **, 0x6B8) = (void *) (&__vt + 0x84);
    this->unkAFC = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline MiningMoleLeader::~MiningMoleLeader() {
    M2C_FIELD(this, s32 **, 0x6B8) = &__vt.unk84;
    if ((&this->unkAFC != NULL) && (&this->unkAFC != NULL)) {
        KDSound_Stop(&this->unkAFC);
    }
}
#endif

#endif  // SPYRO_SOURCE_MININGMOLE_H

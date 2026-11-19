#ifndef SPYRO_SOURCE_ENEMIES_DREADWING_H
#define SPYRO_SOURCE_ENEMIES_DREADWING_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class DreadWing;
class DreadWingDescriptor;
class DropBox;
class Enemies_DreadWing_cpp;
class Enemy;
class EnemyDescriptor;
class MKMessage;
class MKPropDescriptor;

class DreadWing : public Enemy {  // base: base ctor call
public:
    virtual ~DreadWing(void);
    virtual void Init(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual void CheckAnimEvents(void);
    virtual s32 CanDrop(void);
    virtual s32 CanPickUp(void);
    virtual s32 CanPanic(void);
    DreadWing(void);
    void DropDropBox(void);
    s32 PickUpDropBox(int);
    void UpdateDropBox(void);
    /* 0xb10 */ MKPropDescriptor* unkB10;
    /* 0xb14 */ DropBox* unkB14;
};

class DreadWingDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    DreadWingDescriptor(void);
};

class Enemies_DreadWing_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DreadWing::DreadWing() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline DreadWing::~DreadWing() {
    this->unk6B8 = &__vt.unk84;
}
#endif

inline s32 DreadWing::CanPickUp() {
    return 1;
}

inline s32 DreadWing::CanDrop() {
    return 1;
}

inline s32 DreadWing::CanPanic() {
    return 0;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DreadWingDescriptor::DreadWingDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_DREADWING_H

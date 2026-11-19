#ifndef SPYRO_SOURCE_ENEMIES_DREADWING_H
#define SPYRO_SOURCE_ENEMIES_DREADWING_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class DreadWing;
class DreadWingDescriptor;
class Enemies_DreadWing_cpp;
class Enemy;
class EnemyDescriptor;
class MKMessage;

class DreadWing : public Enemy {  // base: vtable prefix
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

#endif  // SPYRO_SOURCE_ENEMIES_DREADWING_H

#ifndef SPYRO_SOURCE_ENEMIES_FIREBOSSDRIVER_H
#define SPYRO_SOURCE_ENEMIES_FIREBOSSDRIVER_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class Enemy;
class EnemyDescriptor;
class FireBossDriver;
class FireBossDriverDescriptor;

class FireBossDriver : public Enemy {  // base: vtable prefix
public:
    virtual ~FireBossDriver(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void SetDefaults(void);
    virtual void SetupCollision(void);
    FireBossDriver(void);
    s32 IsCharging(void);
    void CrashExit(void);
    void CrashEnter(void);
    void ChargeExit(void);
    void ChargeEnter(void);
    /* 0xb10 */ void** unkB10;
    /* 0xb14 */ s8 unkB14;
};

class FireBossDriverDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    FireBossDriverDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline FireBossDriver::FireBossDriver() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline FireBossDriver::~FireBossDriver() {
    this->unk6B8 = &__vt.unk84;
}
#endif

inline void FireBossDriver::SetupCollision() {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline FireBossDriverDescriptor::FireBossDriverDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_FIREBOSSDRIVER_H

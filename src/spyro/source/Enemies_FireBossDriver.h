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
};

class FireBossDriverDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    FireBossDriverDescriptor(void);
};

#endif  // SPYRO_SOURCE_ENEMIES_FIREBOSSDRIVER_H

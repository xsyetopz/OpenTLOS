#ifndef SPYRO_SOURCE_EXPLOSIVEBARRELSPAWNER_H
#define SPYRO_SOURCE_EXPLOSIVEBARRELSPAWNER_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"

class ExplosiveBarrelSpawner;
class ExplosiveBarrelSpawnerDescriptor;
class GameProp;
class GamePropDescriptor;
class MKIniLine;

class ExplosiveBarrelSpawner : public GameProp {  // base: base ctor call
public:
    virtual ~ExplosiveBarrelSpawner(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    ExplosiveBarrelSpawner(void);
    /* 0x0c8 */ void* unkC8;
};

class ExplosiveBarrelSpawnerDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ExplosiveBarrelSpawnerDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ExplosiveBarrelSpawner::ExplosiveBarrelSpawner() {
    return this;
}
#endif

inline ExplosiveBarrelSpawner::~ExplosiveBarrelSpawner() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ExplosiveBarrelSpawnerDescriptor::ExplosiveBarrelSpawnerDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_EXPLOSIVEBARRELSPAWNER_H

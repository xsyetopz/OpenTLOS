#ifndef SPYRO_SOURCE_EXPLOSIVEBARRELSPAWNER_H
#define SPYRO_SOURCE_EXPLOSIVEBARRELSPAWNER_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class ExplosiveBarrelSpawner;
class ExplosiveBarrelSpawnerDescriptor;
class GameProp;
class KDPropExDescriptor;
class MKIniLine;

class ExplosiveBarrelSpawner : public GameProp {  // base: vtable prefix
public:
    virtual ~ExplosiveBarrelSpawner(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    ExplosiveBarrelSpawner(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ void* unkC8;
};

class ExplosiveBarrelSpawnerDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ExplosiveBarrelSpawnerDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
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

#ifndef SPYRO_SOURCE_BEETLENESTSMALL_H
#define SPYRO_SOURCE_BEETLENESTSMALL_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"
#include "spyro/source/shatterwaypointspawn.h"

class BeetleNestSmall;
class BeetleNestSmallDescriptor;
class MKMessage;
class ShatterWaypointSpawn;
class ShatterableDescriptor;

class BeetleNestSmall : public ShatterWaypointSpawn {  // base: vtable prefix
public:
    virtual ~BeetleNestSmall(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    BeetleNestSmall(void);
};

class BeetleNestSmallDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual s32 GetSpawnEnemyType(void);
    BeetleNestSmallDescriptor(void);
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 unk178;
};

#endif  // SPYRO_SOURCE_BEETLENESTSMALL_H

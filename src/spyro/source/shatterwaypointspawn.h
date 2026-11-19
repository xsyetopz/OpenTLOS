#ifndef SPYRO_SOURCE_SHATTERWAYPOINTSPAWN_H
#define SPYRO_SOURCE_SHATTERWAYPOINTSPAWN_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class MKIniLine;
class MKVector3;
class ShatterWaypointSpawn;
class ShatterWaypointSpawnDescriptor;
class Shatterable;
class ShatterableDescriptor;

class ShatterWaypointSpawn : public Shatterable {  // base: vtable prefix
public:
    virtual ~ShatterWaypointSpawn(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual s32 LoadWaypoints(MKIniLine *, const char *);
    ShatterWaypointSpawn(void);
    void SetSpawnPos(int, const MKVector3 &);
};

class ShatterWaypointSpawnDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 GetSpawnEnemyType(void) = 0;
    ShatterWaypointSpawnDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

#endif  // SPYRO_SOURCE_SHATTERWAYPOINTSPAWN_H

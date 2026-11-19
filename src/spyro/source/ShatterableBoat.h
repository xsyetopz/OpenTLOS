#ifndef SPYRO_SOURCE_SHATTERABLEBOAT_H
#define SPYRO_SOURCE_SHATTERABLEBOAT_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"

class MKIniLine;
class MKMessage;
class MKVector3;
class ShatterableBoat;
class ShatterableBoatDescriptor;
class ShatterableDescriptor;
class ShatterablePlatform;

class ShatterableBoat : public ShatterablePlatform {  // base: vtable prefix
public:
    virtual ~ShatterableBoat(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void GetProp(void);
    virtual s32 GetEnemy(void);
    virtual s32 IsHero(void);
    virtual s32 IsFriend(void);
    virtual s32 IsEnemy(void);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetVel(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual f32 GetTimeLastHit(void);
    virtual void UpdateMove(void);
    ShatterableBoat(void);
    void SetDefaults(void);
    void EmitWaterSpray(void);
    void InitOars(void);
};

class ShatterableBoatDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ShatterableBoatDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
};

#endif  // SPYRO_SOURCE_SHATTERABLEBOAT_H

#ifndef SPYRO_SOURCE_TRAP_H
#define SPYRO_SOURCE_TRAP_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class GameProp;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class MKSceneManager;
class MKVector3;
class Trap;
class TrapDescriptor;

class Trap : public GameProp {  // base: vtable prefix
public:
    virtual ~Trap(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Message(MKMessage *);
    virtual void PropUpdate(void);
    virtual void pure_slot16() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot17() = 0;  // name unknown: no descendant fills this slot
    virtual void GetProp(void);
    virtual s32 GetEnemy(void);
    virtual s32 IsHero(void);
    virtual s32 IsFriend(void);
    virtual s32 IsEnemy(void);
    virtual s32 IsShatterable(void);
    virtual s32 IsDead(void);
    virtual s32 GetMoveToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void GetVel(void);
    virtual s32 GetCollisionInfo(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual s32 IsAttacking(void);
    virtual f32 GetTimeLastHit(void);
    Trap(void);
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ MKSceneManager* unkD4;
    /* 0x0d8 */ s8 unkD8;
    /* 0x0d9 */ s32 unkD9;
};

class TrapDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    TrapDescriptor(void);
};

#endif  // SPYRO_SOURCE_TRAP_H

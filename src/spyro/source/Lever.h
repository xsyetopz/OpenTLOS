#ifndef SPYRO_SOURCE_LEVER_H
#define SPYRO_SOURCE_LEVER_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class EventMessage;
class GameProp;
class KDPropExDescriptor;
class KDSoundPlayer;
class Lever;
class LeverDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;

class Lever : public GameProp {  // base: vtable prefix
public:
    virtual ~Lever(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
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
    Lever(void);
    void SetState(int);
    void Release(void);
    void Pull(void);
    void GetStandDir(void);
    void GetStandPos(void);
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ u8 padD4[0x4];
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ EventMessage unkF8;
    /* 0x0fc */ EventMessage unkFC;
    /* 0x100 */ KDSoundPlayer* unk100;
};

class LeverDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    LeverDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
};

#endif  // SPYRO_SOURCE_LEVER_H

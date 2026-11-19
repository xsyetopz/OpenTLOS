#ifndef SPYRO_SOURCE_TOTEMPOLEPUZZLE_H
#define SPYRO_SOURCE_TOTEMPOLEPUZZLE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"

class EventMessage;
class GameProp;
class MKIniLine;
class MKMessage;
class MKVector3;
class TotemPolePiece;
class TotemPolePuzzle;

class TotemPolePiece : public GameProp {  // base: vtable prefix
public:
    virtual ~TotemPolePiece(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
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
    virtual void GetCollisionInfo(void);
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual f32 GetTimeLastHit(void);
    virtual s32 IsAttacking(void);
    TotemPolePiece(void);
    void SetDesiredYaw(int);
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ s32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
};

class TotemPolePuzzle : public GameProp {  // base: vtable prefix
public:
    virtual ~TotemPolePuzzle(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    TotemPolePuzzle(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ void* unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ EventMessage unkD4;
    /* 0x0d8 */ u8 unkD8;
    /* 0x0d9 */ u8 padD9[0x3];
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
};

#endif  // SPYRO_SOURCE_TOTEMPOLEPUZZLE_H

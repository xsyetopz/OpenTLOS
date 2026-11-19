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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'vtableC8'
inline TotemPolePiece::TotemPolePiece() {
    this->vtableC8 = &__vt;
    this->unkCC = -1;
    this->vtableC8 = &__vt + 0x48;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline TotemPolePiece::~TotemPolePiece() {
    this->unkC8.__vptr = &__vt.unk48;
}
#endif

inline s32 TotemPolePiece::IsAttacking() {
    return 0;
}

inline f32 TotemPolePiece::GetTimeLastHit() {
    return 0.0f;
}

inline f32 TotemPolePiece::GetCollisionHeight() {
    return 100.0f;
}

inline f32 TotemPolePiece::GetCollisionRadius() {
    return 100.0f;
}

inline void TotemPolePiece::GetCollisionInfo() {

}

inline void TotemPolePiece::GetVel() {
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = 0.0f;
    spC = 0.0f;
    sp10 = 0.0f;
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}

inline s32 TotemPolePiece::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 TotemPolePiece::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 TotemPolePiece::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    return 0;
}

inline s32 TotemPolePiece::IsDead() {
    return 0;
}

inline s32 TotemPolePiece::IsShatterable() {
    return 0;
}

inline s32 TotemPolePiece::IsEnemy() {
    return 1;
}

inline s32 TotemPolePiece::IsFriend() {
    return 0;
}

inline s32 TotemPolePiece::IsHero() {
    return 0;
}

inline s32 TotemPolePiece::GetEnemy() {
    return 0;
}

inline void TotemPolePiece::GetProp() {

}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline TotemPolePuzzle::TotemPolePuzzle() {
    this->unkD4.unk0 = 0;
    this->unkD4.Init();
    return this;
}
#endif

inline TotemPolePuzzle::~TotemPolePuzzle() {
    if (&this->unkD4 != NULL) {
        this->unkD4.Deinit();
    }
}

#endif  // SPYRO_SOURCE_TOTEMPOLEPUZZLE_H

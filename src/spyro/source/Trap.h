#ifndef SPYRO_SOURCE_TRAP_H
#define SPYRO_SOURCE_TRAP_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"

class EventMessage;
class GameProp;
class GamePropDescriptor;
class MKIniLine;
class MKMessage;
class MKSceneManager;
class MKVector3;
class Trap;
class TrapDescriptor;

class Trap : public GameProp {  // base: base ctor call
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
    /* 0x0c8 */ u8 unkC8;
    /* 0x0c9 */ u8 padC9[0x7];
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ MKSceneManager* unkD4;
    /* 0x0d8 */ s8 unkD8;
    /* 0x0d9 */ u8 unkD9;
    /* 0x0da */ u8 padDA[0x2];
    /* 0x0dc */ EventMessage unkDC;
};

class TrapDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    TrapDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 Trap::IsAttacking() {
    return 0;
}

inline f32 Trap::GetTimeLastHit() {
    return 0.0f;
}

inline s32 Trap::GetCollisionInfo() {
    return 0;
}

inline s32 Trap::IsDead() {
    return 0;
}

inline s32 Trap::IsShatterable() {
    return 0;
}

inline s32 Trap::GetEnemy() {
    return 0;
}

#if 0 // DRAFT: undefined identifier '__vt'
inline Trap::~Trap() {
    M2C_FIELD(this, void **, 0xC8) = (void *) (&__vt + 0x48);
    if (&this->unkDC != NULL) {
        this->unkDC.Deinit();
    }
}
#endif

#if 0 // DRAFT: '(' expected
inline Trap::Trap() {
    M2C_FIELD(this, struct __vt **, 0xC8) = &__vt;
    this->unkCC = -1;
    M2C_FIELD(this, struct __vt **, 0xC8) = (struct __vt *) (&__vt + 0x48);
    this->unkDC.unk0 = 0;
    this->unkDC.Init();
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline TrapDescriptor::TrapDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_TRAP_H

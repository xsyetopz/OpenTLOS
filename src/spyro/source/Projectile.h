#ifndef SPYRO_SOURCE_PROJECTILE_H
#define SPYRO_SOURCE_PROJECTILE_H

#include <dolphin/types.h>
#include "common/Source/MKPtrList.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"

class GameProp;
class KDPropExDescriptor;
class MKAttachment;
class MKCollisionResult;
class MKIniLine;
class MKMessage;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;
class ProjectileType;

class Projectile : public GameProp {  // base: vtable prefix
public:
    virtual ~Projectile(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Disable(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireAtTarget(const MKVector3 &, const MKVector3 &, float, MKProp *, int, int);
    virtual void FireBurst(MKVector3 *, MKVector3 *, int, int);
    virtual void FireBurstEnd(void);
    virtual s32 IsBurst(void);
    virtual void Collided(MKCollisionResult &);
    virtual void SetExplodeOnContact(bool);
    virtual void SetExplodeNearHero(bool, float);
    virtual void SetExplodeTimer(float);
    virtual void SetHeroHurtType(int);
    virtual void SetHitList(MKPtrList<MKProp> *);
    virtual void SetAttachment(MKAttachment *);
    Projectile(void);
    s32 CreateInstance(ProjectileType);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ f64 unkC8;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ f64 unkE0;
    /* 0x0e8 */ f64 unkE8;
    /* 0x0f0 */ f64 unkF0;
    /* 0x0f8 */ f64 unkF8;
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ s32 unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8 unk128;
    /* 0x129 */ u8 pad129[0x7];
    /* 0x130 */ MKProp* unk130;
    /* 0x134 */ MKPtrList<MKProp>* unk134;
    /* 0x138 */ s32* unk138;
    /* 0x13c */ MKAttachment* unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ s32 unk144;
    /* 0x148 */ s32 unk148;
    /* 0x14c */ u8 unk14C;
};

class ProjectileDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    ProjectileDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Projectile::~Projectile() {
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline Projectile::Projectile() {
    return this;
}
#endif

inline s32 Projectile::IsBurst() {
    return 0;
}

inline void Projectile::Activate() {
    GameProp::Activate();
}

inline void Projectile::Deactivate() {
    GameProp::Deactivate();
}

inline void Projectile::SetExplodeOnContact(bool arg0) {

}

inline void Projectile::SetExplodeNearHero(bool arg0, float arg1) {

}

inline void Projectile::SetExplodeTimer(float arg0) {

}

inline void Projectile::SetHeroHurtType(int arg0) {
    this->unk144 = arg0;
}

inline void Projectile::SetHitList(MKPtrList<MKProp> *arg0) {
    this->unk134 = (MKPtrList<MKProp> *) arg0;
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ProjectileDescriptor::ProjectileDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_PROJECTILE_H

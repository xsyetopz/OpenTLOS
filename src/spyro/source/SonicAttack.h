#ifndef SPYRO_SOURCE_SONICATTACK_H
#define SPYRO_SOURCE_SONICATTACK_H

#include <dolphin/types.h>
#include "spyro/source/Projectile.h"

class MKCollisionResult;
class MKHeap;
class MKMaterial;
class MKModel;
class MKProp;
class MKVector3;
class Projectile;
class ProjectileDescriptor;
class SonicAttack;
class SonicAttackDescriptor;

class SonicAttack : public Projectile {  // base: base ctor call
public:
    virtual ~SonicAttack(void);
    virtual void Init(void);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Fire(const MKVector3 &, const MKVector3 &, MKProp *, int, int);
    virtual void FireBurst(MKVector3 *, MKVector3 *, int, int);
    virtual void FireBurstEnd(void);
    virtual s32 IsBurst(void);
    virtual void Collided(MKCollisionResult &);
    SonicAttack(void);
    void DrawSonicRings(void);
    void UpdateSonicRings(void);
    void SpawnSonicRing(const MKVector3 &, const MKVector3 &);
    void SetDefaults(void);
    static void * CreateInstance(void);
    /* 0x150 */ MKVector3* unk150;
    /* 0x154 */ MKVector3* unk154;
    /* 0x158 */ u8 unk158;
    /* 0x159 */ u8 pad159[0x3];
    /* 0x15c */ MKHeap* unk15C;
    /* 0x160 */ MKMaterial* unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ MKModel* unk168;
    /* 0x16c */ u8 unk16C;
};

class SonicAttackDescriptor : public ProjectileDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    SonicAttackDescriptor(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline SonicAttack::SonicAttack() {
}

inline SonicAttack::~SonicAttack() {
}

inline s32 SonicAttack::IsBurst() {
    return 1;
}

inline SonicAttackDescriptor::SonicAttackDescriptor() {
}

#endif  // SPYRO_SOURCE_SONICATTACK_H

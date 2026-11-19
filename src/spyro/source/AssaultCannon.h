#ifndef SPYRO_SOURCE_ASSAULTCANNON_H
#define SPYRO_SOURCE_ASSAULTCANNON_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/ShatterablePlatform.h"

class AssaultCannon;
class AssaultCannonDescriptor;
class AssaultCannon_cpp;
class MKDynamicBone;
class MKHeap;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MKVector3;
class ShatterablePlatform;

class AssaultCannon : public ShatterablePlatform {  // base: vtable prefix
public:
    virtual ~AssaultCannon(void);
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
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
    AssaultCannon(void);
    void CalcSpikeBeamPositions(void);
    void CalcBarrelBeamPositions(void);
    void FreeElecBeams(void);
    void AllocElecBeams(void);
    void EmitShootingFX(void);
    void UpdateTurretBone(MKDynamicBone *, void *);
    void StateDeadExit(void);
    void StateDeadUpdate(void);
    void StateDeadEnter(void);
    void StateFireExit(void);
    void StateFireUpdate(void);
    void StateFireEnter(void);
    void StateTurnToFaceExit(void);
    void StateTurnToFaceUpdate(void);
    void StateTurnToFaceEnter(void);
    void StateIdleExit(void);
    void StateIdleUpdate(void);
    void StateIdleEnter(void);
    u64 UpdateTurning(MKVector3);
    void SetAnim(int, int, float);
    void TakeDamage(float, const MKVector3 &);
    void SetDefaults(void);
};

class AssaultCannonDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    AssaultCannonDescriptor(void);
    /* 0x048 */ u8 pad48[0x124];
    /* 0x16c */ s8* unk16C;
    /* 0x170 */ u8 pad170[0x4];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ MKHeap* unk178;
    /* 0x17c */ void* unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ s32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ f32 unk19C;
    /* 0x1a0 */ f32 unk1A0;
    /* 0x1a4 */ f32 unk1A4;
    /* 0x1a8 */ s32 unk1A8;
};

class AssaultCannon_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_ASSAULTCANNON_H

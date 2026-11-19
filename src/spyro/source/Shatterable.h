#ifndef SPYRO_SOURCE_SHATTERABLE_H
#define SPYRO_SOURCE_SHATTERABLE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/Shadow.h"

class Attachment;
class DataMap;
class EventMessage;
class GameProp;
class GlowingProp;
class KDPropertySet;
class KDSoundPlayer;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class MKVector3;
class MKVector4;
class Shadow;
class Shatterable;
class ShatterableDescriptor;
class SmashPropState;

class Shatterable : public GameProp {  // base: vtable prefix
public:
    virtual ~Shatterable(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void pure_slot16() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot17() = 0;  // name unknown: no descendant fills this slot
    virtual void Shatter(bool, MKVector3 *, int, MKVector3 *, bool, bool);
    virtual void PostShatter(void);
    virtual void DestroyShatterable(void);
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
    virtual s32 IsAttacking(void);
    virtual f32 GetTimeLastHit(void);
    Shatterable(void);
    void ResetPercentageShattered(void);
    void SpawnGems(int);
    void TriggerShatterFX(void);
    void SetSmashPropState(SmashPropState);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    void SetStateAnim(int);
    void EnableCollision(void);
    void DisableCollision(void);
    u8 AbleToRespawn(void);
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ Shadow unkD0;
    /* 0x0fd */ u8 padFD[0x3];
    /* 0x100 */ KDSoundPlayer* unk100;
    /* 0x104 */ u8 pad104[0x14];
    /* 0x118 */ GlowingProp unk118;
    /* 0x12d */ u8 pad12D[0x3];
    /* 0x130 */ f64 unk130;
    /* 0x138 */ f64 unk138;
    /* 0x140 */ u8 pad140[0x14];
    /* 0x154 */ Attachment* unk154;
    /* 0x158 */ void* unk158;
    /* 0x15c */ EventMessage unk15C;
    /* 0x160 */ EventMessage unk160;
    /* 0x164 */ EventMessage unk164;
    /* 0x168 */ void* unk168;
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ MKProp* unk170;
    /* 0x174 */ MKSceneManager* unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ s32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ MKSceneManager* unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ u8 unk19C;
    /* 0x19d */ u8 unk19D;
    /* 0x19e */ u8 unk19E;
    /* 0x19f */ u8 unk19F;
    /* 0x1a0 */ u8 unk1A0;
    /* 0x1a1 */ u8 unk1A1;
    /* 0x1a2 */ u8 unk1A2;
};

class ShatterableDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    ShatterableDescriptor(void);
    void EmitHitEffects(const MKVector3 &, const MKVector3 &, const MKVector4 &, MKProp *, int);
    /* 0x048 */ u8 pad48[0x2c];
    /* 0x074 */ KDPropertySet unk74;
    /* 0x084 */ u8 pad84[0x60];
    /* 0x0e4 */ s8* unkE4;
    /* 0x0e8 */ s8* unkE8;
    /* 0x0ec */ s8* unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ u8 unkF8;
    /* 0x0f9 */ u8 padF9[0x3];
    /* 0x0fc */ s32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 pad109[0x3];
    /* 0x10c */ s32 unk10C;
    /* 0x110 */ s8* unk110;
    /* 0x114 */ u8 unk114;
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116[0x2];
    /* 0x118 */ u8 unk118;
    /* 0x119 */ u8 pad119[0x3];
    /* 0x11c */ void* unk11C;
    /* 0x120 */ u8 pad120[0xc];
    /* 0x12c */ s32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ f32 unk13C;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ s32 unk158;
    /* 0x15c */ s32 unk15C;
    /* 0x160 */ s32 unk160;
    /* 0x164 */ u8 unk164;
    /* 0x165 */ u8 unk165;
    /* 0x166 */ u8 unk166;
    /* 0x167 */ u8 pad167[0x1];
    /* 0x168 */ s32 unk168;
};

extern DataMap ShatterableHitFXDataMap;
#endif  // SPYRO_SOURCE_SHATTERABLE_H

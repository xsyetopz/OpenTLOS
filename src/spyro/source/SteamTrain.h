#ifndef SPYRO_SOURCE_STEAMTRAIN_H
#define SPYRO_SOURCE_STEAMTRAIN_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/Shadow.h"

class GameProp;
class KDPropExDescriptor;
class MKAnimScript;
class MKDynamicBone;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKModel;
class MKSceneManager;
class MKVector3;
class ManagedLight;
class Matrix;
class Shadow;
class SteamTrain;
class SteamTrainDescriptor;
class SteamTrainEffects;
class SteamTrain_cpp;

class SteamTrainEffects {
public:
    void UpdateWheelBone(MKDynamicBone *, void *);
    void UpdateAnimEvents(void);
    void DrawEffects(void);
    void Draw(void);
    void EmitSparks(const MKVector3 &);
    void EmitSmoke(void);
    void EmitBrakingEffects(void);
    void EmitSteam(void);
    void UpdateEffects(void);
    void Update(void);
    void Reset(void);
    void Resolve(void);
    void Init(const Matrix *, MKModel *, MKAnimScript *);
    /* 0x000 */ Matrix* unk0;
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ MKAnimScript* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ u8 pad18[0x8];
    /* 0x020 */ void* unk20;
    /* 0x024 */ MKModel* unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ u8 pad30[0x60];
    /* 0x090 */ u8 unk90;
    /* 0x091 */ u8 pad91[0x7];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ u8 padA4[0x24];
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ u8 padD4[0x14];
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ u8 padF4[0x24];
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ u8 pad124[0x14];
    /* 0x138 */ s32 unk138;
    /* 0x13c */ s32 unk13C;
    /* 0x140 */ s32 unk140;
    /* 0x144 */ u8 pad144[0x24];
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ u8 pad174[0x14];
    /* 0x188 */ s32 unk188;
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ u8 pad194[0x24];
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ f32 unk1C0;
    /* 0x1c4 */ u8 pad1C4[0x14];
    /* 0x1d8 */ void* unk1D8;
    /* 0x1dc */ void* unk1DC;
    /* 0x1e0 */ void* unk1E0;
    /* 0x1e4 */ void* unk1E4;
    /* 0x1e8 */ s32 unk1E8;
    /* 0x1ec */ s32 unk1EC;
    /* 0x1f0 */ s32 unk1F0;
    /* 0x1f4 */ s32 unk1F4;
    /* 0x1f8 */ s32 unk1F8;
    /* 0x1fc */ s32 unk1FC;
    /* 0x200 */ s32 unk200;
    /* 0x204 */ s32 unk204;
    /* 0x208 */ s32 unk208;
    /* 0x20c */ s32 unk20C;
    /* 0x210 */ s32 unk210;
    /* 0x214 */ s32 unk214;
    /* 0x218 */ s32 unk218;
    /* 0x21c */ s32 unk21C;
    /* 0x220 */ s32 unk220;
    /* 0x224 */ f32 unk224;
    /* 0x228 */ f32 unk228;
    /* 0x22c */ f32 unk22C;
    /* 0x230 */ f32 unk230;
    /* 0x234 */ f32 unk234;
    /* 0x238 */ f32 unk238;
};

class SteamTrain : public GameProp {  // base: vtable prefix
public:
    virtual ~SteamTrain(void);
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
    virtual f32 GetTimeLastHit(void);
    virtual s32 IsAttacking(void);
    SteamTrain(void);
    void Stop(bool);
    void StateRamUpdate(void);
    void StateChaseExit(void);
    void StateChaseUpdate(void);
    void StateChaseEnter(void);
    void StateFallBackExit(void);
    void StateFallBackUpdate(void);
    void StateFallBackEnter(void);
    void StateFleeExit(void);
    void StateFleeUpdate(void);
    void StateFleeEnter(void);
    void TriggerDamageFX(const MKVector3 &, float);
    static u8 states[0xd8];
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ s32* unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ Shadow unkD0;
    /* 0x0fd */ u8 padFD[0x3];
    /* 0x100 */ MKMaterial* unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ MKSceneManager* unk124;
    /* 0x128 */ MKSceneManager* unk128;
    /* 0x12c */ MKSceneManager* unk12C;
    /* 0x130 */ u8 unk130;
    /* 0x131 */ u8 unk131;
    /* 0x132 */ u8 pad132[0x2];
    /* 0x134 */ s32 unk134;
    /* 0x138 */ SteamTrainEffects unk138;
    /* 0x374 */ u8 pad374[0x4];
    /* 0x378 */ s32 unk378;
    /* 0x37c */ u8 pad37C[0x10];
    /* 0x38c */ f32 unk38C;
    /* 0x390 */ ManagedLight* unk390;
    /* 0x394 */ s32 unk394;
    /* 0x398 */ u8 pad398[0x24];
    /* 0x3bc */ s32 unk3BC;
    /* 0x3c0 */ u8 pad3C0[0x24];
    /* 0x3e4 */ f32 unk3E4;
    /* 0x3e8 */ f32 unk3E8;
    /* 0x3ec */ u8 unk3EC;
    /* 0x3ed */ u8 unk3ED;
    /* 0x3ee */ u8 unk3EE;
    /* 0x3ef */ u8 unk3EF;
    /* 0x3f0 */ u8 unk3F0;
};

class SteamTrainDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void LoadDone(void);
    SteamTrainDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ s32 unkE4;
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
    /* 0x0f8 */ s32 unkF8;
};

class SteamTrain_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_STEAMTRAIN_H

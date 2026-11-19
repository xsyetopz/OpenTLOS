#ifndef SPYRO_SOURCE_TRAINCHASESPYRO_H
#define SPYRO_SOURCE_TRAINCHASESPYRO_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpyroEffects.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"

class AttackerManager;
class GameProp;
class HeroInterface;
class KDInput;
class LightProp;
class MKAnimScript;
class MKDynamicBone;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class MKSceneManager;
class MKVector3;
class Shadow;
class SpyroEffects;
class SpyroEffectsUpdateData;
class SpyroSoundPlayer;
class Tools_SendMessageHelper;
class TrainChaseSpyro;
class TrainChaseSpyroFX;
class TrainChaseSpyro_cpp;

class TrainChaseSpyro : public GameProp {  // base: vtable prefix
public:
    virtual ~TrainChaseSpyro(void);
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
    virtual f32 GetCollisionRadius(void);
    virtual f32 GetCollisionHeight(void);
    virtual f32 GetTimeLastHit(void);
    virtual u8 IsAttacking(void);
    virtual AttackerManager * GetAttackerManager(void);
    virtual void GetCollisionInfo(void);
    TrainChaseSpyro(void);
    void WheelSparksRight(void);
    void WheelSparksLeft(void);
    void EmitSparks(const MKVector3 &);
    void Hurt(float);
    u8 DealDamage(float);
    void RepositionLightProp(void);
    void EmitBrakingEffects(void);
    void UpdateCameraInfo(void);
    void UpdateAnimEvents(void);
    void UpdateWheelBone(MKDynamicBone *, void *);
    void UpdateControls(void);
    u8 Idling(void);
    u8 LeaningBack(void);
    u8 LeaningForward(void);
    u8 LeaningRight(void);
    u8 LeaningLeft(void);
    void GetEffectsVelocity(void);
    void * GetCamera(void);
    KDInput * GetInput(void);
    void UpdateCartCollisions(void);
    void UpdateCartPosition(void);
    void UpdateCartOrientation(void);
    void StateDeathUpdate(void);
    void StateDeathEnter(void);
    void StateFlinchUpdate(void);
    void StateFlinchEnter(void);
    void StateChaseUpdate(void);
    void StateChaseEnter(void);
    void SetAnim(int, float, int);
    void UpdateSpyro(void);
    static u8 states[0x90];
    /* 0x0c4 */ u8 padC4[0xc];
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ u8 unkE4;
    /* 0x0e5 */ u8 padE5[0x3];
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ u8 padEC[0x24];
    /* 0x110 */ s32 unk110;
    /* 0x114 */ u8 pad114[0x24];
    /* 0x138 */ s32 unk138;
    /* 0x13c */ u8 pad13C[0x24];
    /* 0x160 */ s32 unk160;
    /* 0x164 */ s32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ u8 pad16C[0x4];
    /* 0x170 */ f64 unk170;
    /* 0x178 */ f64 unk178;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f64 unk188;
    /* 0x190 */ f64 unk190;
    /* 0x198 */ u8 pad198[0x4];
    /* 0x19c */ f32 unk19C;
    /* 0x1a0 */ f64 unk1A0;
    /* 0x1a8 */ f64 unk1A8;
    /* 0x1b0 */ u8 pad1B0[0x4];
    /* 0x1b4 */ f32 unk1B4;
    /* 0x1b8 */ Shadow unk1B8;
    /* 0x1e5 */ u8 pad1E5[0x3];
    /* 0x1e8 */ f64 unk1E8;
    /* 0x1f0 */ f64 unk1F0;
    /* 0x1f8 */ MKSceneManager* unk1F8;
    /* 0x1fc */ MKSceneManager* unk1FC;
    /* 0x200 */ MKSceneManager* unk200;
    /* 0x204 */ MKSceneManager* unk204;
    /* 0x208 */ u32 unk208;
    /* 0x20c */ u32 unk20C;
    /* 0x210 */ u32 unk210;
    /* 0x214 */ u32 unk214;
    /* 0x218 */ u32 unk218;
    /* 0x21c */ u32 unk21C;
    /* 0x220 */ u32 unk220;
    /* 0x224 */ u32 unk224;
    /* 0x228 */ u32 unk228;
    /* 0x22c */ u8 pad22C[0x8];
    /* 0x234 */ u32 unk234;
    /* 0x238 */ u32 unk238;
    /* 0x23c */ u32 unk23C;
    /* 0x240 */ u32 unk240;
    /* 0x244 */ u32 unk244;
    /* 0x248 */ u32 unk248;
    /* 0x24c */ u32 unk24C;
    /* 0x250 */ u32 unk250;
    /* 0x254 */ u32 unk254;
    /* 0x258 */ u8 pad258[0x8];
    /* 0x260 */ s32 unk260;
    /* 0x264 */ u8 pad264[0x10];
    /* 0x274 */ s32 unk274;
    /* 0x278 */ s32 unk278;
    /* 0x27c */ s32 unk27C;
    /* 0x280 */ s32 unk280;
    /* 0x284 */ s32 unk284;
    /* 0x288 */ LightProp* unk288;
    /* 0x28c */ f32 unk28C;
    /* 0x290 */ Tools_SendMessageHelper* unk290;
    /* 0x294 */ HeroInterface* unk294;
    /* 0x298 */ HeroInterface* unk298;
    /* 0x29c */ SpyroEffects* unk29C;
    /* 0x2a0 */ u8 pad2A0[0x8];
    /* 0x2a8 */ SpyroSoundPlayer unk2A8;
    /* 0x2a9 */ u8 pad2A9[0x477];
    /* 0x720 */ MKModel* unk720;
    /* 0x724 */ MKAnimScript* unk724;
    /* 0x728 */ s32 unk728;
    /* 0x72c */ u8 unk72C;
    /* 0x72d */ u8 pad72D[0x3];
    /* 0x730 */ f32 unk730;
    /* 0x734 */ AttackerManager unk734;
    /* 0x738 */ s32 unk738;
    /* 0x73c */ f32 unk73C;
    /* 0x740 */ f32 unk740;
    /* 0x744 */ f32 unk744;
    /* 0x748 */ u8 unk748;
};

class TrainChaseSpyroFX : public SpyroEffects {  // base: vtable prefix
public:
    virtual u8 TriggerFire(SpyroEffectsUpdateData *);
    /* 0x004 */ void* unk4;
    /* 0x008 */ MKProp* unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ SpyroSoundPlayer* unk10;
};

class TrainChaseSpyro_cpp {
public:
    void __sinit(void);
};

extern u8 moveAnimTable[0x20];
#endif  // SPYRO_SOURCE_TRAINCHASESPYRO_H

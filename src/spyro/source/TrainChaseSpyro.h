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
    /* 0x0ec */ u8 padEC[0x1c];
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ s32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ u8 pad118[0x20];
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
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'vtableC8'
inline TrainChaseSpyro::TrainChaseSpyro() {
    this->vtableC8 = &__vt;
    this->unkCC = -1;
    this->vtableC8 = &__vt + 0x48;
    this->unkE8 = 0;
    this->unk110 = 0;
    this->unk138 = 0;
    this->unk260 = -1;
    this->unk264 = -1;
    this->unk260 = 0;
    this->unk26C = 0;
    __construct_array(&this->unk2A8, (MKAnimScript *(*)(MKAnimScript *)) &SpyroSoundPlayer::SpyroLoopSounds::SpyroLoopSounds, &SpyroSoundPlayer::SpyroLoopSounds::~SpyroLoopSounds, 0x58, 0xD, (void *)-1);
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline TrainChaseSpyro::~TrainChaseSpyro() {
    this->unkC8.__vptr = &__vt.unk48;
    if (&this->unk2A8 != NULL) {
        __destroy_arr(&this->unk2A8, &SpyroSoundPlayer::SpyroLoopSounds::~SpyroLoopSounds, 0x58, 0xD);
    }
    if ((&this->unk138 != NULL) && (&this->unk138 != NULL)) {
        KDSound_Stop(&this->unk138);
    }
    if ((&this->unk110 != NULL) && (&this->unk110 != NULL)) {
        KDSound_Stop(&this->unk110);
    }
    if ((&this->unkE8 != NULL) && (&this->unkE8 != NULL)) {
        KDSound_Stop(&this->unkE8);
    }
}
#endif

inline AttackerManager *TrainChaseSpyro::GetAttackerManager() {
    return (AttackerManager *) &this->unk72C;
}

inline u8 TrainChaseSpyro::IsAttacking() {
    return M2C_FIELD(this, u8 *, 0x2A0);
}

inline f32 TrainChaseSpyro::GetTimeLastHit() {
    return M2C_BITWISE(f32, this->unk728);
}

inline f32 TrainChaseSpyro::GetCollisionHeight() {
    return 200.0f;
}

inline f32 TrainChaseSpyro::GetCollisionRadius() {
    return 100.0f;
}

inline void TrainChaseSpyro::GetCollisionInfo() {

}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
inline void TrainChaseSpyro::GetVel() {
    f32 sp10;
    f64 sp8;
    f64 temp_f0_6055;
    void *temp_r5_6051;

    temp_r5_6051 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 8) + 0x30;
    temp_f0_6055 = M2C_FIELD(temp_r5_6051, f64 *, 0) - M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x1E8);
    sp8 = temp_f0_6055;
    M2C_FIELD(this, f64 *, 0) = temp_f0_6055;
    sp10 = M2C_FIELD(temp_r5_6051, f32 *, 8) - M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x1F0);
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 TrainChaseSpyro::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKVector(0.0f, 160.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 TrainChaseSpyro::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKVector(0.0f, 160.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

inline s32 TrainChaseSpyro::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_6156;
    f64 temp_f1_6155;
    void *temp_r4_6153;

    temp_r4_6153 = this->unk8;
    temp_f1_6155 = M2C_FIELD(temp_r4_6153, f64 *, 0x30);
    temp_f0_6156 = M2C_FIELD(temp_r4_6153, f64 *, 0x38);
    sp8 = temp_f1_6155;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_6155;
    sp10 = temp_f0_6156;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_6156;
    return 1;
}

inline s32 TrainChaseSpyro::IsShatterable() {
    return 0;
}

inline s32 TrainChaseSpyro::IsEnemy() {
    return 0;
}

inline s32 TrainChaseSpyro::IsFriend() {
    return 0;
}

inline s32 TrainChaseSpyro::IsHero() {
    return 1;
}

inline s32 TrainChaseSpyro::GetEnemy() {
    return 0;
}

inline void TrainChaseSpyro::GetProp() {

}

#endif  // SPYRO_SOURCE_TRAINCHASESPYRO_H

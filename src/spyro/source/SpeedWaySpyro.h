#ifndef SPYRO_SOURCE_SPEEDWAYSPYRO_H
#define SPYRO_SOURCE_SPEEDWAYSPYRO_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/TargetManager.h"

class AttackerManager;
class HeroInterface;
class HurtMessage;
class KDInput;
class KDProp;
class KDPropDescriptor;
class MKAnim;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MKSceneManager;
class MKVector3;
class Matrix;
class SpeedWaySpyro;
class SpeedWaySpyroDescriptor;
class SpeedWaySpyro_cpp;
class SpeedwayFX;

class SpeedwayFX {
public:
    void Deinit(void);
    u8 ShootFireBomb(const MKVector3 &, const MKVector3 &, const MKVector3 &);
    u8 Update(const Matrix *, bool);
    void Resolve(void);
    void Init(void);
    /* 0x000 */ MKPropDescriptor* unk0;
};

class SpeedWaySpyro : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SpeedWaySpyro(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void pure_slot13() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot14() = 0;  // name unknown: no descendant fills this slot
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
    SpeedWaySpyro(void);
    u8 UsePulledBackCamera(void);
    void UpdateSound(void);
    void UpdateEffects(void);
    void SetColObjEnabled(bool);
    void Teleport(float, bool);
    void SetMatrix(const Matrix &, bool);
    void Hurt(HurtMessage *);
    u8 DealDamage(float);
    void SetStageIndex(int);
    void SetAnim(MKAnim *, float, unsigned int);
    void * GetCamera(void);
    KDInput * GetInput(void);
    void GetJoyDir(void);
    void UpdateDrift(float);
    f32 GetCurrXYDriftFactor(void) const;
    u8 GetBestMovementOffset(const MKVector3 &, const MKVector3 &, const MKVector3 &, float *);
    void UpdateCameraAndSpyro(float, bool, bool);
    f32 GetCurrCameraZ(void) const;
    void SetTargetMovementOffset(const MKVector3 &);
    void UpdateMovementOffset(void);
    void UpdateSplineTime(void);
    void UpdateStageInfo(void);
    u8 AnyToPowerRollTransition(void);
    u8 AnyToHitCollisionTransition(void);
    void EventCameraUpdate(void);
    void EventCameraExit(void);
    void EventCameraEnter(void);
    s32 DeathTransition(void);
    void DeathUpdate(void);
    void DeathExit(void);
    void DeathEnter(void);
    s32 HurtCenterTransition(void);
    void HurtCenterUpdate(void);
    void HurtCenterExit(void);
    void HurtCenterEnter(void);
    s32 HurtFlinchTransition(void);
    void HurtFlinchUpdate(void);
    void HurtFlinchEnter(void);
    u8 PowerRollTransition(void);
    void PowerRollUpdate(void);
    void PowerRollExit(void);
    void PowerRollEnter(void);
    void MoveSelectAnim(void);
    u8 MoveTransition(void);
    void MoveUpdate(void);
    void MoveEnter(void);
    u8 IdleTransition(void);
    void IdleUpdate(void);
    void IdleEnter(void);
    s32 RespawnTransition(void);
    void RespawnUpdate(void);
    void RespawnExit(void);
    void RespawnEnter(void);
    void StateEnter(void);
    void Start(void);
    void ClearData(void);
    static u8 states[0x144];
    /* 0x090 */ s32* unk90;
    /* 0x094 */ u8 pad94[0x4];
    /* 0x098 */ s32 unk98;
    /* 0x09c */ f32 unk9C;
    /* 0x0a0 */ s32 unkA0;
    /* 0x0a4 */ u8 unkA4;
    /* 0x0a5 */ u8 unkA5;
    /* 0x0a6 */ u8 padA6[0x26];
    /* 0x0cc */ MKAnim* unkCC;
    /* 0x0d0 */ u8 padD0[0x44];
    /* 0x114 */ MKAnim* unk114;
    /* 0x118 */ MKAnim* unk118;
    /* 0x11c */ MKAnim* unk11C;
    /* 0x120 */ MKAnim* unk120;
    /* 0x124 */ MKAnim* unk124;
    /* 0x128 */ MKAnim* unk128;
    /* 0x12c */ u8 pad12C[0x4];
    /* 0x130 */ MKVector3 unk130;
    /* 0x140 */ f32 unk140;
    /* 0x144 */ f32 unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14c */ f32 unk14C;
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15c */ f32 unk15C;
    /* 0x160 */ f32 unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ AttackerManager unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ u8 pad184[0x10];
    /* 0x194 */ f32 unk194;
    /* 0x198 */ u8 pad198[0x4];
    /* 0x19c */ u8 unk19C;
    /* 0x19d */ u8 pad19D[0x3];
    /* 0x1a0 */ Matrix unk1A0;
    /* 0x1e0 */ f32 unk1E0;
    /* 0x1e4 */ f32 unk1E4;
    /* 0x1e8 */ f32 unk1E8;
    /* 0x1ec */ u8 pad1EC[0x4];
    /* 0x1f0 */ f32 unk1F0;
    /* 0x1f4 */ f32 unk1F4;
    /* 0x1f8 */ f32 unk1F8;
    /* 0x1fc */ u8 pad1FC[0x14];
    /* 0x210 */ f32 unk210;
    /* 0x214 */ f32 unk214;
    /* 0x218 */ f32 unk218;
    /* 0x21c */ u8 unk21C;
    /* 0x21d */ u8 pad21D[0x3];
    /* 0x220 */ f64 unk220;
    /* 0x228 */ f64 unk228;
    /* 0x230 */ f64 unk230;
    /* 0x238 */ f64 unk238;
    /* 0x240 */ f64 unk240;
    /* 0x248 */ f64 unk248;
    /* 0x250 */ f64 unk250;
    /* 0x258 */ f64 unk258;
    /* 0x260 */ f64 unk260;
    /* 0x268 */ f64 unk268;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ u8 pad271[0xf];
    /* 0x280 */ f64 unk280;
    /* 0x288 */ f64 unk288;
    /* 0x290 */ u8 unk290;
    /* 0x291 */ u8 pad291[0xf];
    /* 0x2a0 */ f64 unk2A0;
    /* 0x2a8 */ f64 unk2A8;
    /* 0x2b0 */ u8 unk2B0;
    /* 0x2b1 */ u8 pad2B1[0xf];
    /* 0x2c0 */ f32 unk2C0;
    /* 0x2c4 */ u8 pad2C4[0x4];
    /* 0x2c8 */ f32 unk2C8;
    /* 0x2cc */ f32 unk2CC;
    /* 0x2d0 */ f32 unk2D0;
    /* 0x2d4 */ u8 pad2D4[0x4];
    /* 0x2d8 */ f64 unk2D8;
    /* 0x2e0 */ f32 unk2E0;
    /* 0x2e4 */ u8 pad2E4[0x4];
    /* 0x2e8 */ u8 unk2E8;
    /* 0x2e9 */ u8 unk2E9;
    /* 0x2ea */ u8 pad2EA[0x2];
    /* 0x2ec */ f32 unk2EC;
    /* 0x2f0 */ MKSceneManager* unk2F0;
    /* 0x2f4 */ s32 unk2F4;
    /* 0x2f8 */ f32 unk2F8;
    /* 0x2fc */ SpeedwayFX unk2FC;
    /* 0x300 */ u8 unk300;
    /* 0x301 */ u8 pad301[0x3];
    /* 0x304 */ f32 unk304;
    /* 0x308 */ f64 unk308;
    /* 0x310 */ f64 unk310;
    /* 0x318 */ f64 unk318;
    /* 0x320 */ f64 unk320;
    /* 0x328 */ f64 unk328;
    /* 0x330 */ f64 unk330;
    /* 0x338 */ f32 unk338;
    /* 0x33c */ u8 pad33C[0x4];
    /* 0x340 */ f64 unk340;
    /* 0x348 */ f64 unk348;
    /* 0x350 */ f64 unk350;
    /* 0x358 */ f64 unk358;
    /* 0x360 */ f64 unk360;
    /* 0x368 */ f64 unk368;
    /* 0x370 */ f64 unk370;
    /* 0x378 */ f64 unk378;
    /* 0x380 */ f32 unk380;
    /* 0x384 */ u8 pad384[0x4];
    /* 0x388 */ HeroInterface* unk388;
    /* 0x38c */ HeroInterface* unk38C;
    /* 0x390 */ void* unk390;
    /* 0x394 */ u8 pad394[0x4];
    /* 0x398 */ void* unk398;
    /* 0x39c */ u8 pad39C[0x168];
    /* 0x504 */ s32 unk504;
    /* 0x508 */ u8 pad508[0x164];
    /* 0x66c */ s32 unk66C;
    /* 0x670 */ u8 pad670[0x164];
    /* 0x7d4 */ s32 unk7D4;
    /* 0x7d8 */ u8 pad7D8[0x38];
    /* 0x810 */ f32 unk810;
    /* 0x814 */ u8 unk814;
    /* 0x815 */ u8 pad815[0x3];
    /* 0x818 */ s32 unk818;
    /* 0x81c */ u8 pad81C[0x24];
    /* 0x840 */ s32 unk840;
    /* 0x844 */ u8 pad844[0x44];
    /* 0x888 */ s32 unk888;
    /* 0x88c */ u8 pad88C[0x24];
    /* 0x8b0 */ u8 unk8B0;
    /* 0x8b1 */ u8 unk8B1;
    /* 0x8b2 */ u8 pad8B2[0x2];
    /* 0x8b4 */ f32 unk8B4;
    /* 0x8b8 */ u8 pad8B8[0xc];
    /* 0x8c4 */ s32 unk8C4;
};

class SpeedWaySpyroDescriptor : public KDPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x070 */ u8 unk70;
    /* 0x071 */ u8 pad71[0x37];
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12c */ f32 unk12C;
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
    /* 0x158 */ f32 unk158;
    /* 0x15c */ s32 unk15C;
    /* 0x160 */ f32 unk160;
    /* 0x164 */ f32 unk164;
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17c */ f32 unk17C;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ f32 unk188;
    /* 0x18c */ f32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ f32 unk194;
    /* 0x198 */ f32 unk198;
    /* 0x19c */ s32 unk19C;
    /* 0x1a0 */ s32 unk1A0;
    /* 0x1a4 */ s32 unk1A4;
    /* 0x1a8 */ u8 unk1A8;
    /* 0x1a9 */ u8 pad1A9[0x3];
    /* 0x1ac */ s32 unk1AC;
    /* 0x1b0 */ s32 unk1B0;
    /* 0x1b4 */ s32 unk1B4;
    /* 0x1b8 */ s32 unk1B8;
    /* 0x1bc */ s32 unk1BC;
    /* 0x1c0 */ s32 unk1C0;
    /* 0x1c4 */ s32 unk1C4;
    /* 0x1c8 */ s32 unk1C8;
    /* 0x1cc */ s32 unk1CC;
    /* 0x1d0 */ s32 unk1D0;
    /* 0x1d4 */ s32 unk1D4;
    /* 0x1d8 */ s32 unk1D8;
    /* 0x1dc */ s32 unk1DC;
};

class SpeedWaySpyro_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline SpeedWaySpyro::SpeedWaySpyro() {
    this->unk90 = &__vt.unk0;
    this->unk94 = -1;
    this->unk90 = &__vt + 0x3C;
    this->unk180 = -1;
    this->unk184 = -1;
    this->unk188 = 0;
    this->unk18C = 0;
    this->unk398 = &__vt;
    this->unk818 = 0;
    this->unk840 = 0;
    this->unk888 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SpeedWaySpyro::~SpeedWaySpyro() {
    s32 temp_cr0_eq_33;

    if (this != NULL) {
        this->unk90 = &__vt.unk3C;
        if ((&this->unk888 != NULL) && (&this->unk888 != NULL)) {
            KDSound_Stop((int *) &this->unk888);
        }
        temp_cr0_eq_33 = this == NULL;
        if (temp_cr0_eq_33 == 0) {
            if (temp_cr0_eq_33 == 0) {
            }
        }
    }
}
#endif

inline AttackerManager *SpeedWaySpyro::GetAttackerManager() {
    return &this->unk17C;
}

inline u8 SpeedWaySpyro::IsAttacking() {
    return this->unk300;
}

inline f32 SpeedWaySpyro::GetTimeLastHit() {
    return this->unk2EC;
}

inline f32 SpeedWaySpyro::GetCollisionHeight() {
    return 200.0f;
}

inline f32 SpeedWaySpyro::GetCollisionRadius() {
    return 100.0f;
}

inline void SpeedWaySpyro::GetCollisionInfo() {

}

inline void SpeedWaySpyro::GetVel() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x2C8);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x2D0);
}

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 SpeedWaySpyro::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
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
inline s32 SpeedWaySpyro::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
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

inline s32 SpeedWaySpyro::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_195;
    f64 temp_f1_194;
    void *temp_r4_192;

    temp_r4_192 = this->unk8;
    temp_f1_194 = M2C_FIELD(temp_r4_192, f64 *, 0x30);
    temp_f0_195 = M2C_FIELD(temp_r4_192, f64 *, 0x38);
    sp8 = temp_f1_194;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_194;
    sp10 = temp_f0_195;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_195;
    return 1;
}

inline s32 SpeedWaySpyro::IsShatterable() {
    return 0;
}

inline s32 SpeedWaySpyro::IsEnemy() {
    return 0;
}

inline s32 SpeedWaySpyro::IsFriend() {
    return 0;
}

inline s32 SpeedWaySpyro::IsHero() {
    return 1;
}

inline s32 SpeedWaySpyro::GetEnemy() {
    return 0;
}

inline void SpeedWaySpyro::GetProp() {

}

#if 0 // DRAFT: ')' expected
inline f32 SpeedWaySpyro::GetCurrXYDriftFactor() const {
    s32 var_r31_1737;

    if ((s32) M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C) > 0) {
        var_r31_1737 = M2C_FIELD(checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x15C);
    } else {
        var_r31_1737 = this->unk2F4;
    }
    return M2C_FIELD((checked_cast<SpeedWaySpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r31_1737 * 0x38)), f32 *, 0x84);
}
#endif

inline f32 SpeedWaySpyro::GetCurrCameraZ() const {
    return this->unk14C;
}

#endif  // SPYRO_SOURCE_SPEEDWAYSPYRO_H

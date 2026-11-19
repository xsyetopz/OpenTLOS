#ifndef SPYRO_SOURCE_STEAMTRAIN_H
#define SPYRO_SOURCE_STEAMTRAIN_H

#include <dolphin/types.h>
#include "spyro/source/GameProp.h"
#include "spyro/source/Shadow.h"

class GameProp;
class GamePropDescriptor;
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
    /* 0x00c */ SteamTrain* unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ u8 pad18[0x8];
    /* 0x020 */ void* unk20;
    /* 0x024 */ MKModel* unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ u8 pad30[0x48];
    /* 0x078 */ u8 unk78;
    /* 0x079 */ u8 pad79[0x17];
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

class SteamTrain : public GameProp {  // base: base ctor call
public:
    virtual ~SteamTrain(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
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
    /* 0x0c8 */ s32* unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ Shadow unkD0;
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

class SteamTrainDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    SteamTrainDescriptor(void);
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

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline SteamTrain::SteamTrain() {
    this->unkC8 = &__vt.unk0;
    this->unkCC = -1;
    this->unkC8 = &__vt + 0x48;
    this->unk378 = -1;
    this->unk37C = -1;
    this->unk380 = 0;
    this->unk384 = 0;
    this->unk394 = 0;
    this->unk3BC = 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
inline SteamTrain::~SteamTrain() {
    this->unkC8 = &__vt.unk48;
    if ((&this->unk3BC != NULL) && (&this->unk3BC != NULL)) {
        KDSound_Stop((int *) &this->unk3BC);
    }
    if ((&this->unk394 != NULL) && (&this->unk394 != NULL)) {
        KDSound_Stop((int *) &this->unk394);
    }
}
#endif

inline s32 SteamTrain::IsAttacking() {
    return 0;
}

inline f32 SteamTrain::GetTimeLastHit() {
    return 0.0f;
}

inline f32 SteamTrain::GetCollisionHeight() {
    return 500.0f;
}

inline f32 SteamTrain::GetCollisionRadius() {
    return 500.0f;
}

inline s32 SteamTrain::GetCollisionInfo() {
    return 0;
}

inline void SteamTrain::GetVel() {
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f4_93;
    f64 temp_f0_109;
    void *temp_r5_92;

    temp_r5_92 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), void **, 8);
    temp_f4_93 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x108);
    sp8 = -M2C_FIELD(temp_r5_92, f32 *, 0x20);
    spC = -M2C_FIELD(temp_r5_92, f32 *, 0x24);
    sp10 = -M2C_FIELD(temp_r5_92, f32 *, 0x28);
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    temp_f0_109 = sp28 * (f64) temp_f4_93;
    sp18 = temp_f0_109;
    M2C_FIELD(this, f64 *, 0) = temp_f0_109;
    sp20 = (f32) sp30 * temp_f4_93;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
}

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 SteamTrain::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;

    sp18 = MKVector(0.0f, 400.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + M2C_BITWISE(f64, sp18);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp18.unk8;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
inline s32 SteamTrain::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    MKVector3 sp18;
    f32 sp10;
    f64 sp8;

    sp18 = MKVector(0.0f, 400.0f, 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + M2C_BITWISE(f64, sp18);
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp18.unk8;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

inline s32 SteamTrain::GetMoveToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp10;
    f64 sp8;
    f64 temp_f0_209;
    f64 temp_f1_208;
    void *temp_r4_206;

    temp_r4_206 = this->unk8;
    temp_f1_208 = M2C_FIELD(temp_r4_206, f64 *, 0x30);
    temp_f0_209 = M2C_FIELD(temp_r4_206, f64 *, 0x38);
    sp8 = temp_f1_208;
    M2C_FIELD(arg1, f64 *, 0) = temp_f1_208;
    sp10 = temp_f0_209;
    M2C_FIELD(arg1, f64 *, 8) = temp_f0_209;
    return 1;
}

inline s32 SteamTrain::IsDead() {
    return 0;
}

inline s32 SteamTrain::IsShatterable() {
    return 0;
}

inline s32 SteamTrain::IsEnemy() {
    return 1;
}

inline s32 SteamTrain::IsFriend() {
    return 0;
}

inline s32 SteamTrain::IsHero() {
    return 0;
}

inline s32 SteamTrain::GetEnemy() {
    return 0;
}

inline void SteamTrain::GetProp() {

}

inline SteamTrainDescriptor::SteamTrainDescriptor() {
}

#endif  // SPYRO_SOURCE_STEAMTRAIN_H

#ifndef SPYRO_SOURCE_ENEMIES_ICEBOSS_H
#define SPYRO_SOURCE_ENEMIES_ICEBOSS_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventMessage.h"
#include "unplaced_enums.h"

class EarthShockwave;
class ElementalShield;
class Enemy;
class EnemyDescriptor;
class EventMessage;
class IceBitsPS;
class IceBoss;
class IceBossBodyPart;
class IceBossDescriptor;
class IceBossStalactiteSpawner;
class MKCollisionInfo;
class MKIniLine;
class MKMessage;
class MKProp;
class MKSceneManager;
class MKVector3;
class ManagedLight;
class Matrix;
class Shatterable;
class SpawnPointRef;

class IceBoss : public Enemy {  // base: base ctor call
public:
    virtual ~IceBoss(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual u8 EnableCollision(bool);
    virtual void Despawn(bool);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual s32 GetCharacterName(void);
    IceBoss(void);
    void UpdateWeaponCollisionCapsule(void);
    void CalcSubObjWorldMatrix(int, Matrix *);
    void UpdateBreathingFx(void);
    void EnableWeaponCollision(bool);
    void UpdateSummonWeapon(void);
    void SummonWeapon(void);
    void DestroyShield(void);
    void UpdateFormShield(void);
    void FormShield(void);
    void DestroyWeapon(void);
    void UpdatePhrasesAndSounds(void);
    void UpdateFormWeapon(void);
    void FormWeapon(void);
    void UpdateWeapons(void);
    void ShatterSubObj(int, Shatterable *);
    void ShatterBodyParts(void);
    void UpdateBodyParts(void);
    void InterceptDamage(bool *);
    s32 TryChangeStage(void);
    void UpdateEnemyHud(void);
    void StartPhase3(void);
    void StartPhase2(void);
    void StartPhase1(void);
    s32 GetPhase(void);
    u8 IsIceKing(void);
    void DrawSubObject(int, float);
    void SetupCameraSpline(float, float, MKVector3, MKVector3);
    void ResetWeapons(void);
    void InitShield(void);
    void InitWeapon(int, const char *, int, int);
    void InitBodyPart(IceBossBodyPart *, int, const char *, int, int, SubObjectType, bool);
    void InitBodyPart(int, const char *, int, int, SubObjectType, bool);
    /* 0xb10 */ MKSceneManager* unkB10;
    /* 0xb14 */ s32 unkB14;
    /* 0xb18 */ s32 unkB18;
    /* 0xb1c */ s32 unkB1C;
    /* 0xb20 */ u8 unkB20;
    /* 0xb21 */ u8 padB21[0x3];
    /* 0xb24 */ s32 unkB24;
    /* 0xb28 */ s32 unkB28;
    /* 0xb2c */ u8 padB2C[0x8];
    /* 0xb34 */ s32 unkB34;
    /* 0xb38 */ u8 padB38[0x328];
    /* 0xe60 */ void* unkE60;
    /* 0xe64 */ u8 padE64[0x24];
    /* 0xe88 */ void* unkE88;
    /* 0xe8c */ u8 padE8C[0x24];
    /* 0xeb0 */ void* unkEB0;
    /* 0xeb4 */ u8 padEB4[0x8];
    /* 0xebc */ u32 unkEBC;
    /* 0xec0 */ u32 unkEC0;
    /* 0xec4 */ s32 unkEC4;
    /* 0xec8 */ u8 unkEC8;
    /* 0xec9 */ s8 unkEC9;
    /* 0xeca */ u8 unkECA;
    /* 0xecb */ u8 padECB[0x1];
    /* 0xecc */ f32 unkECC;
    /* 0xed0 */ Shatterable* unkED0;
    /* 0xed4 */ u8 padED4[0x8];
    /* 0xedc */ u8 unkEDC;
    /* 0xedd */ u8 padEDD[0x3];
    /* 0xee0 */ Matrix unkEE0;
    /* 0xf20 */ Matrix unkF20;
    /* 0xf60 */ f64 unkF60;
    /* 0xf68 */ f64 unkF68;
    /* 0xf70 */ f64 unkF70;
    /* 0xf78 */ f64 unkF78;
    /* 0xf80 */ f64 unkF80;
    /* 0xf88 */ f64 unkF88;
    /* 0xf90 */ MKCollisionInfo* unkF90;
    /* 0xf94 */ MKProp* unkF94;
    /* 0xf98 */ MKSceneManager* unkF98;
    /* 0xf9c */ MKSceneManager* unkF9C;
    /* 0xfa0 */ MKSceneManager* unkFA0;
    /* 0xfa4 */ MKSceneManager* unkFA4;
    /* 0xfa8 */ f32 unkFA8;
    /* 0xfac */ f32 unkFAC;
    /* 0xfb0 */ f32 unkFB0;
    /* 0xfb4 */ f32 unkFB4;
    /* 0xfb8 */ u8 unkFB8;
    /* 0xfb9 */ u8 unkFB9;
    /* 0xfba */ u8 unkFBA;
    /* 0xfbb */ u8 unkFBB;
    /* 0xfbc */ s8 unkFBC;
    /* 0xfbd */ s8 unkFBD;
    /* 0xfbe */ u8 unkFBE;
    /* 0xfbf */ u8 padFBF[0x1];
    /* 0xfc0 */ f32 unkFC0;
    /* 0xfc4 */ f32 unkFC4;
    /* 0xfc8 */ f32 unkFC8;
    /* 0xfcc */ f32 unkFCC;
    /* 0xfd0 */ f32 unkFD0;
    /* 0xfd4 */ f32 unkFD4;
    /* 0xfd8 */ f32 unkFD8;
    /* 0xfdc */ MKProp* unkFDC;
    /* 0xfe0 */ IceBossStalactiteSpawner* unkFE0;
    /* 0xfe4 */ EventMessage unkFE4;
    /* 0xfe8 */ EventMessage unkFE8;
    /* 0xfec */ EventMessage unkFEC;
    /* 0xff0 */ u8 padFF0[0x4];
    /* 0xff4 */ EarthShockwave* unkFF4;
    /* 0xff8 */ ElementalShield* unkFF8;
    /* 0xffc */ ManagedLight* unkFFC;
    /* 0x1000 */ s32 unk1000;
    /* 0x1004 */ s8* unk1004;
    /* 0x1008 */ f32 unk1008;
    /* 0x100c */ f32 unk100C;
    /* 0x1010 */ s32 unk1010;
    /* 0x1014 */ s32 unk1014;
    /* 0x1018 */ u8 pad1018[0x24];
    /* 0x103c */ s32 unk103C;
    /* 0x1040 */ u8 pad1040[0x24];
    /* 0x1064 */ u8 unk1064;
    /* 0x1065 */ u8 pad1065[0x3];
    /* 0x1068 */ IceBitsPS* unk1068;
};

class IceBossBodyPart {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ s32 unk18;
    /* 0x01c */ s32 unk1C;
};

class IceBossDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    IceBossDescriptor(void);
    /* 0x2b4 */ f32 unk2B4;
    /* 0x2b8 */ f32 unk2B8;
    /* 0x2bc */ f32 unk2BC;
    /* 0x2c0 */ f32 unk2C0;
    /* 0x2c4 */ f32 unk2C4;
    /* 0x2c8 */ f32 unk2C8;
    /* 0x2cc */ f32 unk2CC;
    /* 0x2d0 */ s32 unk2D0;
    /* 0x2d4 */ s32 unk2D4;
    /* 0x2d8 */ s32 unk2D8;
    /* 0x2dc */ s32 unk2DC;
    /* 0x2e0 */ u8 pad2E0[0x6c];
    /* 0x34c */ f32 unk34C;
};

void IceBoss_UpdateParams(void *);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline IceBoss::IceBoss() {
    this->unk6B8 = &__vt + 0x84;
    this->unkFE4.unk0 = 0;
    this->unkFE4.Init();
    this->unkFE8.unk0 = 0;
    this->unkFE8.Init();
    this->unkFEC.unk0 = 0;
    this->unkFEC.Init();
    this->unk1014 = 0;
    this->unk103C = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline IceBoss::~IceBoss() {
    this->unk6B8 = &__vt.unk84;
    if ((&this->unk103C != NULL) && (&this->unk103C != NULL)) {
        KDSound_Stop((int *) &this->unk103C);
    }
    if ((&this->unk1014 != NULL) && (&this->unk1014 != NULL)) {
        KDSound_Stop((int *) &this->unk1014);
    }
    if (&this->unkFEC != NULL) {
        this->unkFEC.Deinit();
    }
    if (&this->unkFE8 != NULL) {
        this->unkFE8.Deinit();
    }
    if (&this->unkFE4 != NULL) {
        this->unkFE4.Deinit();
    }
}
#endif

inline IceBossDescriptor::IceBossDescriptor() {
}

#endif  // SPYRO_SOURCE_ENEMIES_ICEBOSS_H

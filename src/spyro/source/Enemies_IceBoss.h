#ifndef SPYRO_SOURCE_ENEMIES_ICEBOSS_H
#define SPYRO_SOURCE_ENEMIES_ICEBOSS_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class Enemy;
class EnemyDescriptor;
class IceBoss;
class IceBossBodyPart;
class IceBossDescriptor;
class MKIniLine;
class MKMessage;
class MKVector3;
class Matrix;
class Shatterable;
class SpawnPointRef;
class SubObjectType;

class IceBoss : public Enemy {  // base: vtable prefix
public:
    virtual ~IceBoss(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual void EnableCollision(bool);
    virtual void Despawn(bool);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void GetCharacterName(void);
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
#endif  // SPYRO_SOURCE_ENEMIES_ICEBOSS_H

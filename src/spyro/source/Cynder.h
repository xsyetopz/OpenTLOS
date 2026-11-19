#ifndef SPYRO_SOURCE_CYNDER_H
#define SPYRO_SOURCE_CYNDER_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/NodeLookAt.h"
#include "unplaced_enums.h"

class AITargetData;
class Corona;
class Cynder;
class CynderBreathFX;
class CynderDescriptor;
class Cynder_cpp;
class Enemy;
class EnemyAttack;
class EnemyDescriptor;
class EventMessage;
class KDUniformSpline;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class MKSceneManager;
class MKVector3;
class Matrix;
class NodeLookAtIK;
class SpawnPointRef;
class SuckeyPS;

class Cynder : public Enemy {  // base: base ctor call
public:
    virtual ~Cynder(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void SetDefaults(void);
    virtual void Despawn(bool);
    virtual void UpdateMovementCustom(void);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void GetCharacterName(void);
    Cynder(void);
    void ResetFury(void);
    void TriggerFury(void);
    void UpdateFuryPowerUp(void);
    void TriggerFuryPowerUp(float, HeroHurtReactionType);
    void CalcLandingFlightPathData(void);
    void CalcFlightPathData2(void);
    s32 FollowPathToTarget(AITargetData *);
    u8 CalculateRegionEdgeMoveTarget(AITargetData *, MKVector3 *);
    s32 ShootFireBomb(const MKVector3 &, const MKVector3 &, const MKVector3 &);
    void UpdateEffects(void);
    void UpdateEnemyHud(void);
    s32 CanLeap(bool);
    s32 GetAttackHeading(EnemyAttack *, MKVector3 *);
    void CalculateDiveTrajectory(void);
    void UpdatePhrasesAndSounds(void);
    void EnableFlyingRotation(bool);
    void UpdateFlyingRotation(Matrix *);
    void UpdateLookAtNodes(void);
    /* 0xb10 */ NodeLookAtIK unkB10;
    /* 0xb58 */ NodeLookAtIK unkB58;
    /* 0xba0 */ NodeLookAtIK unkBA0;
    /* 0xbe8 */ NodeLookAtIK unkBE8;
    /* 0xc30 */ NodeLookAtIK unkC30;
    /* 0xc78 */ f32 unkC78;
    /* 0xc7c */ u8 padC7C[0x8];
    /* 0xc84 */ f32 unkC84;
    /* 0xc88 */ f32 unkC88;
    /* 0xc8c */ u8 padC8C[0x34];
    /* 0xcc0 */ s32 unkCC0;
    /* 0xcc4 */ s32 unkCC4;
    /* 0xcc8 */ f32 unkCC8;
    /* 0xccc */ u8 padCCC[0x8];
    /* 0xcd4 */ s32 unkCD4;
    /* 0xcd8 */ s32 unkCD8;
    /* 0xcdc */ f32 unkCDC;
    /* 0xce0 */ u8 padCE0[0x8];
    /* 0xce8 */ s32 unkCE8;
    /* 0xcec */ CynderBreathFX* unkCEC;
    /* 0xcf0 */ MKPropDescriptor* unkCF0;
    /* 0xcf4 */ s32 unkCF4;
    /* 0xcf8 */ s32 unkCF8;
    /* 0xcfc */ s32 unkCFC;
    /* 0xd00 */ u8 unkD00;
    /* 0xd01 */ u8 unkD01;
    /* 0xd02 */ u8 unkD02;
    /* 0xd03 */ u8 padD03[0x5];
    /* 0xd08 */ f64 unkD08;
    /* 0xd10 */ f64 unkD10;
    /* 0xd18 */ f64 unkD18;
    /* 0xd20 */ f64 unkD20;
    /* 0xd28 */ f64 unkD28;
    /* 0xd30 */ f64 unkD30;
    /* 0xd38 */ f64 unkD38;
    /* 0xd40 */ f64 unkD40;
    /* 0xd48 */ f64 unkD48;
    /* 0xd50 */ f64 unkD50;
    /* 0xd58 */ s32 unkD58;
    /* 0xd5c */ s32 unkD5C;
    /* 0xd60 */ s8* unkD60;
    /* 0xd64 */ f32 unkD64;
    /* 0xd68 */ f32 unkD68;
    /* 0xd6c */ s32 unkD6C;
    /* 0xd70 */ u8 padD70[0x24];
    /* 0xd94 */ u8 unkD94;
    /* 0xd95 */ u8 padD95[0x3];
    /* 0xd98 */ s32 unkD98;
    /* 0xd9c */ s32 unkD9C;
    /* 0xda0 */ MKSceneManager* unkDA0;
    /* 0xda4 */ u8 padDA4[0x14];
    /* 0xdb8 */ f64 unkDB8;
    /* 0xdc0 */ f64 unkDC0;
    /* 0xdc8 */ u8 padDC8[0x1c];
    /* 0xde4 */ f32 unkDE4;
    /* 0xde8 */ u8 unkDE8;
    /* 0xde9 */ u8 unkDE9;
    /* 0xdea */ u8 padDEA[0xae];
    /* 0xe98 */ MKVector3 unkE98;
    /* 0xea8 */ f32 unkEA8;
    /* 0xeac */ f32 unkEAC;
    /* 0xeb0 */ f32 unkEB0;
    /* 0xeb4 */ u8 padEB4[0x4];
    /* 0xeb8 */ f64 unkEB8;
    /* 0xec0 */ f32 unkEC0;
    /* 0xec4 */ u8 padEC4[0x4];
    /* 0xec8 */ EventMessage unkEC8;
    /* 0xecc */ EventMessage unkECC;
    /* 0xed0 */ EventMessage unkED0;
    /* 0xed4 */ EventMessage unkED4;
    /* 0xed8 */ EventMessage unkED8;
    /* 0xedc */ EventMessage unkEDC;
    /* 0xee0 */ EventMessage unkEE0;
    /* 0xee4 */ EventMessage unkEE4;
    /* 0xee8 */ EventMessage unkEE8;
    /* 0xeec */ EventMessage unkEEC;
    /* 0xef0 */ EventMessage unkEF0;
    /* 0xef4 */ EventMessage unkEF4;
    /* 0xef8 */ EventMessage unkEF8;
    /* 0xefc */ EventMessage unkEFC;
    /* 0xf00 */ EventMessage unkF00;
    /* 0xf04 */ EventMessage unkF04;
    /* 0xf08 */ EventMessage unkF08;
    /* 0xf0c */ EventMessage unkF0C;
    /* 0xf10 */ EventMessage unkF10;
    /* 0xf14 */ f32 unkF14;
    /* 0xf18 */ s8 unkF18;
    /* 0xf19 */ u8 unkF19;
    /* 0xf1a */ s8 unkF1A;
    /* 0xf1b */ s8 unkF1B;
    /* 0xf1c */ s8 unkF1C;
    /* 0xf1d */ s8 unkF1D;
    /* 0xf1e */ s8 unkF1E;
    /* 0xf1f */ u8 unkF1F;
    /* 0xf20 */ u8 unkF20;
    /* 0xf21 */ u8 padF21[0x3];
    /* 0xf24 */ s32 unkF24;
    /* 0xf28 */ SuckeyPS* unkF28;
    /* 0xf2c */ Corona* unkF2C;
    /* 0xf30 */ u8 unkF30;
    /* 0xf31 */ u8 padF31[0x2f];
    /* 0xf60 */ f32 unkF60;
    /* 0xf64 */ f32 unkF64;
    /* 0xf68 */ f32 unkF68;
    /* 0xf6c */ f32 unkF6C;
    /* 0xf70 */ f32 unkF70;
    /* 0xf74 */ f32 unkF74;
    /* 0xf78 */ MKSceneManager* unkF78;
    /* 0xf7c */ void* unkF7C;
    /* 0xf80 */ f64 unkF80;
    /* 0xf88 */ f32 unkF88;
    /* 0xf8c */ u8 padF8C[0x4];
    /* 0xf90 */ f32 unkF90;
    /* 0xf94 */ f32 unkF94;
    /* 0xf98 */ f32 unkF98;
    /* 0xf9c */ u8 padF9C[0x4];
    /* 0xfa0 */ f64 unkFA0;
    /* 0xfa8 */ f64 unkFA8;
    /* 0xfb0 */ f64 unkFB0;
    /* 0xfb8 */ f64 unkFB8;
    /* 0xfc0 */ f64 unkFC0;
    /* 0xfc8 */ f64 unkFC8;
    /* 0xfd0 */ u8 padFD0[0x20];
    /* 0xff0 */ KDUniformSpline* unkFF0;
    /* 0xff4 */ f32 unkFF4;
    /* 0xff8 */ f32 unkFF8;
    /* 0xffc */ s32 unkFFC;
    /* 0x1000 */ EventMessage unk1000;
};

class CynderDescriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderDescriptor(void);
    /* 0x2b4 */ u8 pad2B4[0xfc];
    /* 0x3b0 */ s32 unk3B0;
    /* 0x3b4 */ f32 unk3B4;
    /* 0x3b8 */ s32 unk3B8;
};

class Cynder_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline Cynder::Cynder() {
    this->unk6B8 = &__vt + 0x84;
    this->unkCC0 = 0;
    this->unkCC4 = 0;
    this->unkCC8 = 0.0f;
    this->unkCCC = 0;
    this->unkCD4 = 0;
    this->unkCD8 = 0;
    this->unkCDC = 0.0f;
    this->unkCE0 = 0;
    this->unkD6C = 0;
    __construct_array((KDUniformSpline *) &this->unkDB8, (MKAnimScript *(*)(MKAnimScript *)) &EnemyRegion::EnemyRegion, NULL, 0x38, 4);
    this->unkEC8.unk0 = 0;
    this->unkEC8.Init();
    this->unkECC.unk0 = 0;
    this->unkECC.Init();
    this->unkED0.unk0 = 0;
    this->unkED0.Init();
    this->unkED4.unk0 = 0;
    this->unkED4.Init();
    this->unkED8.unk0 = 0;
    this->unkED8.Init();
    this->unkEDC.unk0 = 0;
    this->unkEDC.Init();
    this->unkEE0.unk0 = 0;
    this->unkEE0.Init();
    this->unkEE4.unk0 = 0;
    this->unkEE4.Init();
    this->unkEE8.unk0 = 0;
    this->unkEE8.Init();
    this->unkEEC.unk0 = 0;
    this->unkEEC.Init();
    this->unkEF0.unk0 = 0;
    this->unkEF0.Init();
    this->unkEF4.unk0 = 0;
    this->unkEF4.Init();
    this->unkEF8.unk0 = 0;
    this->unkEF8.Init();
    this->unkEFC.unk0 = 0;
    this->unkEFC.Init();
    this->unkF00.unk0 = 0;
    this->unkF00.Init();
    this->unkF04.unk0 = 0;
    this->unkF04.Init();
    this->unkF08.unk0 = 0;
    this->unkF08.Init();
    this->unkF0C.unk0 = 0;
    this->unkF0C.Init();
    this->unkF10.unk0 = 0;
    this->unkF10.Init();
    this->unk1000.unk0 = 0;
    this->unk1000.Init();
    this->unk1010 = 1;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline Cynder::~Cynder() {
    this->unk6B8 = &__vt.unk84;
    if (&this->unk1000 != NULL) {
        this->unk1000.Deinit();
    }
    if (&this->unkF10 != NULL) {
        this->unkF10.Deinit();
    }
    if (&this->unkF0C != NULL) {
        this->unkF0C.Deinit();
    }
    if (&this->unkF08 != NULL) {
        this->unkF08.Deinit();
    }
    if (&this->unkF04 != NULL) {
        this->unkF04.Deinit();
    }
    if (&this->unkF00 != NULL) {
        this->unkF00.Deinit();
    }
    if (&this->unkEFC != NULL) {
        this->unkEFC.Deinit();
    }
    if (&this->unkEF8 != NULL) {
        this->unkEF8.Deinit();
    }
    if (&this->unkEF4 != NULL) {
        this->unkEF4.Deinit();
    }
    if (&this->unkEF0 != NULL) {
        this->unkEF0.Deinit();
    }
    if (&this->unkEEC != NULL) {
        this->unkEEC.Deinit();
    }
    if (&this->unkEE8 != NULL) {
        this->unkEE8.Deinit();
    }
    if (&this->unkEE4 != NULL) {
        this->unkEE4.Deinit();
    }
    if (&this->unkEE0 != NULL) {
        this->unkEE0.Deinit();
    }
    if (&this->unkEDC != NULL) {
        this->unkEDC.Deinit();
    }
    if (&this->unkED8 != NULL) {
        this->unkED8.Deinit();
    }
    if (&this->unkED4 != NULL) {
        this->unkED4.Deinit();
    }
    if (&this->unkED0 != NULL) {
        this->unkED0.Deinit();
    }
    if (&this->unkECC != NULL) {
        this->unkECC.Deinit();
    }
    if (&this->unkEC8 != NULL) {
        this->unkEC8.Deinit();
    }
    if ((&this->unkD6C != NULL) && (&this->unkD6C != NULL)) {
        KDSound_Stop((int *) &this->unkD6C);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderDescriptor::CynderDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CYNDER_H

#ifndef SPYRO_SOURCE_CYNDER_H
#define SPYRO_SOURCE_CYNDER_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

class AITargetData;
class Cynder;
class CynderDescriptor;
class Cynder_cpp;
class Enemy;
class EnemyAttack;
class EnemyDescriptor;
class HeroHurtReactionType;
class MKIniLine;
class MKMessage;
class MKVector3;
class Matrix;
class SpawnPointRef;

class Cynder : public Enemy {  // base: vtable prefix
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

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline Cynder::Cynder() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unkCC0 = 0;
    this->unkCC4 = 0;
    this->unkCC8 = 0.0f;
    this->unkCCC = 0;
    this->unkCD4 = 0;
    this->unkCD8 = 0;
    this->unkCDC = 0.0f;
    this->unkCE0 = 0;
    this->unkD6C = 0;
    __construct_array(&this->unkDB8, (MKAnimScript *(*)(MKAnimScript *)) &EnemyRegion::EnemyRegion, NULL, 0x38, 4);
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

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline Cynder::~Cynder() {
    this->unk110.unk5A8 = &__vt.unk84;
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
        KDSound_Stop(&this->unkD6C);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CynderDescriptor::CynderDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CYNDER_H

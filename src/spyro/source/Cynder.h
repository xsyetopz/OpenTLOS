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

#endif  // SPYRO_SOURCE_CYNDER_H

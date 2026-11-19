#ifndef SPYRO_SOURCE_CHARACTER_H
#define SPYRO_SOURCE_CHARACTER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/CollisionObject.h"

class Character;
class CharacterMoveType;
class CollisionObject;
class MKAnim;
class MKCollisionInfo;
class MKCollisionResult;
class MKIniLine;
class MKMessage;
class MKProp;
class MKVector3;
class MKVector4;
class Matrix;
class SpawnPointRef;

class Character : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Character(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    virtual void SetDefaults(void);
    virtual void EnableCollision(bool);
    virtual u8 IsCollisionEnabled(void);
    virtual s32 Spawn(const Matrix *);
    virtual s32 Spawn(SpawnPointRef *);
    virtual void Despawn(bool);
    virtual void Recycle(void);
    virtual void Activate(void);
    virtual void Deactivate(void);
    virtual s32 Teleport(const Matrix *);
    virtual void UpdateMovement(void);
    virtual void UpdateMovementCustom(void);
    virtual void UpdateModel(void);
    virtual void SetAnim(MKAnim *, float, float, float, unsigned int);
    virtual void RotateNodeYaw(int, float);
    virtual void RotateNodePitch(int, float);
    virtual void RotateNodePYR(int, const MKVector3 &);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    void UpdateSpeed(void);
    void SetDesiredSpeed(float);
    u8 IsSteeringEnabled(void);
    void GetDesiredHeadingMatrix(Matrix *);
    void ClearHorizForces(void);
    void SetMovementType(CharacterMoveType);
    void ResetCloth(void);
    void UpdateRotation(void);
    MKVector3 * UpdateVelocity(void);
    void UpdateAnimation(void);
    void StopMovement(bool);
    void UpdateMovementArbitrary(void);
    void UpdateMovementNormal(void);
    void BridgeHit(float, float);
    void ** PlatformFind(MKCollisionResult *, int);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *, MKCollisionInfo *);
    void PlatformUpdate(void);
    s32 HasAnimFinished(void);
    void LerpModelColour(const MKVector4 &, float);
    void FindGroundColour(bool, bool);
    void FindAnyCollisionPosY(const MKVector3 &, float, MKCollisionResult &);
    s32 IsActive(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f64 unk60;
    /* 0x068 */ f64 unk68;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ f64 unk78;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ f32 unkB4;
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ u8 padBC[0x4];
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ f32 unkC4;
    /* 0x0c8 */ f32 unkC8;
    /* 0x0cc */ u8 padCC[0x4];
    /* 0x0d0 */ f32 unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ u8 padDC[0x4];
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ u8 padEC[0x4];
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ u8 padF4[0x4];
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ CollisionObject unk110;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void Character::UpdateMovementCustom() {

}

#if 0 // DRAFT: undefined identifier 'unk560'
inline Character::~Character() {
    M2C_UNK *temp_r0_5407;
    M2C_UNK *temp_r0_5423;
    M2C_UNK *temp_r5_5410;
    M2C_UNK *temp_r5_5426;

    if (this != NULL) {
        if (&this->unk110.unk560 != NULL) {
            temp_r0_5407 = this->unk110.unk568;
            if (temp_r0_5407 != NULL) {
                temp_r5_5410 = &this->unk110.unk560;
                if (temp_r0_5407 != temp_r5_5410) {
                    M2C_FIELD(this->unk110.unk56C, M2C_UNK **, 8) = temp_r0_5407;
                    M2C_FIELD(this->unk110.unk568, M2C_UNK **, 0xC) = (M2C_UNK *) this->unk110.unk56C;
                    this->unk110.unk56C = temp_r5_5410;
                    this->unk110.unk568 = temp_r5_5410;
                }
            }
        }
        if (&this->unk110.unk538 != NULL) {
            temp_r0_5423 = this->unk110.unk558;
            if (temp_r0_5423 != NULL) {
                temp_r5_5426 = &this->unk110.unk538;
                if (temp_r0_5423 != temp_r5_5426) {
                    M2C_FIELD(this->unk110.unk55C, M2C_UNK **, 0x20) = temp_r0_5423;
                    M2C_FIELD(this->unk110.unk558, M2C_UNK **, 0x24) = (M2C_UNK *) this->unk110.unk55C;
                    this->unk110.unk55C = temp_r5_5426;
                    this->unk110.unk558 = temp_r5_5426;
                }
            }
        }
        if (this != NULL) {
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_CHARACTER_H

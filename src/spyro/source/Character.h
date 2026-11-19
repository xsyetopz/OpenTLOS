#ifndef SPYRO_SOURCE_CHARACTER_H
#define SPYRO_SOURCE_CHARACTER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Shadow.h"
#include "unplaced_enums.h"

class Character;
class CollisionObject;
class MKAnim;
class MKCollisionInfo;
class MKCollisionResult;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKVector3;
class MKVector4;
class Matrix;
class SB2;
class Shadow;
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
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ u8 padFC[0x4];
    /* 0x100 */ f64 unk100;
    /* 0x108 */ f64 unk108;
    /* 0x110 */ CollisionObject unk110;
    /* 0x584 */ u8 pad584[0x4];
    /* 0x588 */ MKVector3 unk588;
    /* 0x598 */ f32 unk598;
    /* 0x59c */ f32 unk59C;
    /* 0x5a0 */ f32 unk5A0;
    /* 0x5a4 */ u8 pad5A4[0x14];
    /* 0x5b8 */ f32 unk5B8;
    /* 0x5bc */ f32 unk5BC;
    /* 0x5c0 */ f32 unk5C0;
    /* 0x5c4 */ u8 pad5C4[0x4];
    /* 0x5c8 */ f32 unk5C8;
    /* 0x5cc */ f32 unk5CC;
    /* 0x5d0 */ f32 unk5D0;
    /* 0x5d4 */ u8 pad5D4[0x4];
    /* 0x5d8 */ void* unk5D8;
    /* 0x5dc */ u8 pad5DC[0x8];
    /* 0x5e4 */ f32 unk5E4;
    /* 0x5e8 */ u8 pad5E8[0x8];
    /* 0x5f0 */ s32 unk5F0;
    /* 0x5f4 */ u8 pad5F4[0xc];
    /* 0x600 */ Shadow unk600;
    /* 0x62d */ u8 pad62D[0x3];
    /* 0x630 */ void* unk630;
    /* 0x634 */ void* unk634;
    /* 0x638 */ void* unk638;
    /* 0x63c */ MKProp* unk63C;
    /* 0x640 */ SB2* unk640;
    /* 0x644 */ MKMaterial* unk644;
    /* 0x648 */ u8 pad648[0x18];
    /* 0x660 */ Character* unk660;
    /* 0x664 */ void* unk664;
    /* 0x668 */ u8 pad668[0x8];
    /* 0x670 */ u8 unk670;
    /* 0x671 */ u8 pad671[0xf];
    /* 0x680 */ u32 unk680;
    /* 0x684 */ s32 unk684;
    /* 0x688 */ s32 unk688;
    /* 0x68c */ f32 unk68C;
    /* 0x690 */ f32 unk690;
    /* 0x694 */ f32 unk694;
    /* 0x698 */ f32 unk698;
    /* 0x69c */ f32 unk69C;
    /* 0x6a0 */ f32 unk6A0;
    /* 0x6a4 */ s32 unk6A4;
    /* 0x6a8 */ u8 pad6A8[0x8];
    /* 0x6b0 */ s8 unk6B0;
    /* 0x6b1 */ u8 pad6B1[0x3];
    /* 0x6b4 */ u8 unk6B4;
    /* 0x6b5 */ u8 unk6B5;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void Character::UpdateMovementCustom() {

}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
inline Character::~Character() {
    Character *temp_r0_5423;
    M2C_UNK *temp_r0_5407;
    M2C_UNK *temp_r5_5410;
    SB2 **temp_r5_5426;

    if (this != NULL) {
        if (&this->unk670 != NULL) {
            temp_r0_5407 = M2C_FIELD(this, M2C_UNK **, 0x678);
            if (temp_r0_5407 != NULL) {
                temp_r5_5410 = &this->unk670;
                if (temp_r0_5407 != temp_r5_5410) {
                    M2C_FIELD(this->unk67C, M2C_UNK **, 8) = temp_r0_5407;
                    M2C_FIELD(M2C_FIELD(this, M2C_UNK **, 0x678), M2C_UNK **, 0xC) = (M2C_UNK *) this->unk67C;
                    this->unk67C = temp_r5_5410;
                    M2C_FIELD(this, M2C_UNK **, 0x678) = temp_r5_5410;
                }
            }
        }
        if (&this->unk640 != NULL) {
            temp_r0_5423 = this->unk660;
            if (temp_r0_5423 != NULL) {
                temp_r5_5426 = &this->unk640;
                if (temp_r0_5423 != temp_r5_5426) {
                    M2C_FIELD(this->unk664, Character **, 0x20) = temp_r0_5423;
                    this->unk660->unk24 = M2C_BITWISE(f32, this->unk664);
                    this->unk664 = temp_r5_5426;
                    this->unk660 = (Character *) temp_r5_5426;
                }
            }
        }
        if (this != NULL) {
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_CHARACTER_H

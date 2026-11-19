#ifndef SPYRO_SOURCE_ENEMIES_ELEC_H
#define SPYRO_SOURCE_ENEMIES_ELEC_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/PlatformObject.h"

class ElecTier1;
class ElecTier1Descriptor;
class ElecTier2;
class ElecTier2Descriptor;
class ElecTier3;
class ElecTier3Descriptor;
class Enemies_Elec_cpp;
class Enemy;
class EnemyDescriptor;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKVector3;
class Matrix;
class PlatformObject;
class SlimeTrailFX;
class SpawnPointRef;

class ElecTier1 : public Enemy {  // base: base ctor call
public:
    virtual ~ElecTier1(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual void CheckAnimEvents(void);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void GetCharacterName(void);
    ElecTier1(void);
    /* 0xb10 */ SlimeTrailFX* unkB10;
    /* 0xb14 */ u8 padB14[0x4];
    /* 0xb18 */ f64 unkB18;
    /* 0xb20 */ f64 unkB20;
    /* 0xb28 */ s32 unkB28;
};

class ElecTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    ElecTier1Descriptor(void);
    /* 0x2b4 */ MKMaterial* unk2B4;
};

class ElecTier2 : public Enemy {  // base: base ctor call
public:
    virtual ~ElecTier2(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Despawn(bool);
    virtual void UpdateMovementCustom(void);
    virtual void SetupCollision(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    ElecTier2(void);
    s32 FindLandingPos(MKVector3 *);
    /* 0xb10 */ u8 unkB10;
    /* 0xb11 */ u8 unkB11;
    /* 0xb12 */ s8 unkB12;
    /* 0xb13 */ s8 unkB13;
    /* 0xb14 */ s32 unkB14;
    /* 0xb18 */ f32 unkB18;
    /* 0xb1c */ f32 unkB1C;
    /* 0xb20 */ u8 padB20[0x8];
    /* 0xb28 */ PlatformObject unkB28;
};

class ElecTier2Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    ElecTier2Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
    /* 0x2bc */ s32 unk2BC;
    /* 0x2c0 */ s32 unk2C0;
    /* 0x2c4 */ s32 unk2C4;
    /* 0x2c8 */ s32 unk2C8;
    /* 0x2cc */ f32 unk2CC;
    /* 0x2d0 */ f32 unk2D0;
    /* 0x2d4 */ f32 unk2D4;
    /* 0x2d8 */ f32 unk2D8;
    /* 0x2dc */ s8 unk2DC;
    /* 0x2dd */ u8 unk2DD;
};

class ElecTier3 : public Enemy {  // base: base ctor call
public:
    virtual ~ElecTier3(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void SetDefaults(void);
    virtual void UpdateMovementCustom(void);
    virtual void UpdateCollisionItems(void);
    virtual s32 GetLookToPoint(const MKVector3 &, MKVector3 *);
    virtual s32 GetAimPoint(const MKVector3 &, MKVector3 *);
    virtual s32 Spawn(const Matrix *, SpawnPointRef *);
    virtual void GetCharacterName(void);
    ElecTier3(void);
    void DrawScan(void);
    void UpdateScan(void);
    void EnableScan(bool);
    /* 0xb10 */ Matrix unkB10;
    /* 0xb50 */ f32 unkB50;
    /* 0xb54 */ u8 unkB54;
    /* 0xb55 */ u8 unkB55;
};

class ElecTier3Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void LoadDone(void);
    virtual void Deinit(void);
    ElecTier3Descriptor(void);
    /* 0x2b4 */ s32 unk2B4;
    /* 0x2b8 */ s32 unk2B8;
    /* 0x2bc */ s32 unk2BC;
    /* 0x2c0 */ MKMaterial* unk2C0;
};

class Enemies_Elec_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline ElecTier1::ElecTier1() {
    this->unk6B8 = &__vt + 0x84;
    this->unkB28 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline ElecTier1::~ElecTier1() {
    this->unk6B8 = &__vt.unk84;
    if ((&this->unkB28 != NULL) && (&this->unkB28 != NULL)) {
        KDSound_Stop((int *) &this->unkB28);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ElecTier1Descriptor::ElecTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline ElecTier2::ElecTier2() {
    PlatformAttachment *temp_r0_6579;

    temp_r0_6579 = &this->unkB28.unk28;
    this->unk6B8 = &__vt + 0x84;
    this->unkB28.unk28.unk0 = NULL;
    this->unkB28.unk28.unk4 = NULL;
    this->unkB28.unk28.unk8 = temp_r0_6579;
    this->unkB28.unk28.unkC = temp_r0_6579;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline ElecTier2::~ElecTier2() {
    PlatformAttachment *temp_r0_2119;
    PlatformAttachment *temp_r4_2117;

    if (this != NULL) {
        this->unk6B8 = &__vt.unk84;
        if (&this->unkB28 != NULL) {
            temp_r4_2117 = &this->unkB28.unk28;
            if (temp_r4_2117 != NULL) {
                temp_r0_2119 = this->unkB28.unk28.unk8;
                if ((temp_r0_2119 != NULL) && (temp_r0_2119 != temp_r4_2117)) {
                    this->unkB28.unk28.unkC->unk8 = temp_r0_2119;
                    this->unkB28.unk28.unk8->unkC = this->unkB28.unk28.unkC;
                    this->unkB28.unk28.unkC = temp_r4_2117;
                    this->unkB28.unk28.unk8 = temp_r4_2117;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ElecTier2Descriptor::ElecTier2Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline ElecTier3::ElecTier3() {
    this->unk6B8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk6B8'
inline ElecTier3::~ElecTier3() {
    this->unk6B8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ElecTier3Descriptor::ElecTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_ELEC_H

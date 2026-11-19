#ifndef SPYRO_SOURCE_ENEMIES_ELEC_H
#define SPYRO_SOURCE_ENEMIES_ELEC_H

#include <dolphin/types.h>
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"

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
class SpawnPointRef;

class ElecTier1 : public Enemy {  // base: vtable prefix
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
};

class ElecTier1Descriptor : public EnemyDescriptor {  // base: ctor/dtor vtable stores
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    ElecTier1Descriptor(void);
    /* 0x2b4 */ MKMaterial* unk2B4;
};

class ElecTier2 : public Enemy {  // base: vtable prefix
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

class ElecTier3 : public Enemy {  // base: vtable prefix
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

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline ElecTier1::ElecTier1() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    this->unk110.unkA18 = 0;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline ElecTier1::~ElecTier1() {
    this->unk110.unk5A8 = &__vt.unk84;
    if ((&this->unk110.unkA18 != NULL) && (&this->unk110.unkA18 != NULL)) {
        KDSound_Stop((s32 *) &this->unk110.unkA18);
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ElecTier1Descriptor::ElecTier1Descriptor() {
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA40'
inline ElecTier2::ElecTier2() {
    M2C_UNK *temp_r0_6579;

    temp_r0_6579 = &this->unk110.unkA40;
    this->unk110.vtable5A8 = &__vt + 0x84;
    M2C_FIELD(this, s32 *, 0xB50) = 0;
    this->unk110.unkA44 = 0;
    this->unk110.unkA48 = temp_r0_6579;
    this->unk110.unkA4C = temp_r0_6579;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline ElecTier2::~ElecTier2() {
    f32 *temp_r0_2119;
    f32 *temp_r4_2117;

    if (this != NULL) {
        this->unk110.unk5A8 = &__vt.unk84;
        if (&this->unk110.unkA18 != NULL) {
            temp_r4_2117 = &this->unk110.unkA40;
            if (temp_r4_2117 != NULL) {
                temp_r0_2119 = this->unk110.unkA48;
                if ((temp_r0_2119 != NULL) && (temp_r0_2119 != temp_r4_2117)) {
                    M2C_FIELD(this->unk110.unkA4C, f32 **, 8) = temp_r0_2119;
                    M2C_FIELD(this->unk110.unkA48, f32 **, 0xC) = (f32 *) this->unk110.unkA4C;
                    this->unk110.unkA4C = temp_r4_2117;
                    this->unk110.unkA48 = temp_r4_2117;
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

#if 0 // DRAFT: undefined identifier 'vtable5A8'
inline ElecTier3::ElecTier3() {
    this->unk110.vtable5A8 = &__vt + 0x84;
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A8'
inline ElecTier3::~ElecTier3() {
    this->unk110.unk5A8 = &__vt.unk84;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ElecTier3Descriptor::ElecTier3Descriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_ENEMIES_ELEC_H

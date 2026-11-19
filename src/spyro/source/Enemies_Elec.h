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

#endif  // SPYRO_SOURCE_ENEMIES_ELEC_H

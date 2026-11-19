#ifndef SPYRO_SOURCE_ENEMYSPAWNER_H
#define SPYRO_SOURCE_ENEMYSPAWNER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/Matrix.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"

class EnemySpawnPointData;
class EnemySpawner;
class EnemySpawnerDescriptor;
class EventMessage;
class KDPathSegment;
class KDSplinePathSegment;
class MKIniLine;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class Matrix;
class SpawnPoint;
class SpawnPointData;
class SpawnPointObject;
class SpawnerObject;

class EnemySpawnPointData : public SpawnPointData {  // base: ctor/dtor vtable stores
public:
    virtual ~EnemySpawnPointData(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Resolve(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ EventMessage unk8;
    /* 0x00c */ EventMessage unkC;
    /* 0x010 */ EventMessage unk10;
    /* 0x014 */ EventMessage unk14;
    /* 0x018 */ KDSplinePathSegment* unk18;
    /* 0x01c */ KDPathSegment* unk1C;
    /* 0x020 */ MKSceneManager* unk20;
    /* 0x024 */ MKSceneManager* unk24;
};

class EnemySpawner : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~EnemySpawner(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ Matrix unk50;
    /* 0x090 */ SpawnerObject unk90;
    /* 0x0dd */ u8 padDD[0x3];
    /* 0x0e0 */ s32 unkE0;
    /* 0x0e4 */ u32 unkE4;
};

class EnemySpawnerDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ u8 pad6C[0x4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
};

class SpawnPoint : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~SpawnPoint(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Message(MKMessage *);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ SpawnPointObject unk50;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline EnemySpawnPointData::~EnemySpawnPointData() {
    if (&this->unk14 != NULL) {
        this->unk14.Deinit();
    }
    if (&this->unk10 != NULL) {
        this->unk10.Deinit();
    }
    if (&this->unkC != NULL) {
        this->unkC.Deinit();
    }
    if (&this->unk8 != NULL) {
        this->unk8.Deinit();
    }
    if (this != NULL) {
    }
}

#if 0 // DRAFT: undefined identifier 'unk40'
inline EnemySpawner::~EnemySpawner() {
    EventMessage *temp_r3_24;
    EventMessage *temp_r3_30;

    if (this != NULL) {
        if (&this->unk50.unk40 != NULL) {
            temp_r3_24 = &this->unk50.unk80;
            this->unk50.unk40 = M2C_BITWISE(f32, &__vt);
            if (temp_r3_24 != NULL) {
                temp_r3_24->Deinit();
            }
            temp_r3_30 = &this->unk50.unk7C;
            if (temp_r3_30 != NULL) {
                temp_r3_30->Deinit();
            }
        }
        if (this != NULL) {
        }
    }
}
#endif

inline SpawnPoint::~SpawnPoint() {
    s32 temp_cr0_eq_938;

    temp_cr0_eq_938 = this == NULL;
    if (temp_cr0_eq_938 == 0) {
        if (temp_cr0_eq_938 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_ENEMYSPAWNER_H

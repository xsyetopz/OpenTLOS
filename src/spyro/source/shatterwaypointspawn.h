#ifndef SPYRO_SOURCE_SHATTERWAYPOINTSPAWN_H
#define SPYRO_SOURCE_SHATTERWAYPOINTSPAWN_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnerObject.h"

class MKIniLine;
class MKVector3;
class ShatterWaypointSpawn;
class ShatterWaypointSpawnDescriptor;
class Shatterable;
class ShatterableDescriptor;
class SpawnerObject;

class ShatterWaypointSpawn : public Shatterable {  // base: vtable prefix
public:
    virtual ~ShatterWaypointSpawn(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual s32 LoadWaypoints(MKIniLine *, const char *);
    ShatterWaypointSpawn(void);
    void SetSpawnPos(int, const MKVector3 &);
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ SpawnerObject unk1A8;
    /* 0x1f5 */ u8 pad1F5[0x3];
    /* 0x1f8 */ void* unk1F8;
    /* 0x1fc */ s32 unk1FC;
    /* 0x200 */ s32 unk200;
};

class ShatterWaypointSpawnDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 GetSpawnEnemyType(void) = 0;
    ShatterWaypointSpawnDescriptor(void);
    /* 0x16c */ s32 unk16C;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterWaypointSpawn::~ShatterWaypointSpawn() {
    f32 *temp_r3_21055;
    s32 *temp_r3_21061;

    if (this != NULL) {
        this->unkC8 = &__vt + 0x48;
        if (&this->unk198 != NULL) {
            temp_r3_21055 = &this->unk1A8.unk30;
            this->unk198 = M2C_BITWISE(f32, &__vt);
            if (temp_r3_21055 != NULL) {
                temp_r3_21055->Deinit();
            }
            temp_r3_21061 = &this->unk1A8.unk2C;
            if (temp_r3_21061 != NULL) {
                temp_r3_21061->Deinit();
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline ShatterWaypointSpawn::ShatterWaypointSpawn() {
    this->unkC8 = &__vt + 0x48;
    this->unk198 = M2C_BITWISE(f32, &__vt);
    this->unk1A8.unk2C = 0;
    this->unk1A8.unk2C.Init();
    this->unk1A8.unk30 = 0.0f;
    this->unk1A8.unk30.Init();
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ShatterWaypointSpawnDescriptor::ShatterWaypointSpawnDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SHATTERWAYPOINTSPAWN_H

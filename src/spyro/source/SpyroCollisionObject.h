#ifndef SPYRO_SOURCE_SPYROCOLLISIONOBJECT_H
#define SPYRO_SOURCE_SPYROCOLLISIONOBJECT_H

#include <dolphin/types.h>
#include "spyro/source/CollisionObject.h"

class ColObjDescriptor;
class CollisionObject;
class MKCollisionInfo;
class MKCollisionResult;
class MKProp;
class MKVector3;
class SpyroCollisionObject;

class SpyroCollisionObject : public CollisionObject {  // base: inlined ctor vtable stores
public:
    virtual void Init(ColObjDescriptor *, const MKVector3 &, bool, MKCollisionInfo *, bool, bool, unsigned int, MKProp *, bool);
    virtual s32 Update(MKVector3 *, float, bool);
    virtual s32 Teleport(const MKVector3 &, float, int);
    virtual void GetOffset(void);
    u8 IsFloorCollision(MKCollisionResult *);
    void PushOutOfThings(MKVector3);
    s32 GlueToGround(void);
    /* 0x478 */ f32 unk478;
    /* 0x47c */ f32 unk47C;
    /* 0x480 */ f64 unk480;
    /* 0x488 */ f64 unk488;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline void SpyroCollisionObject::GetOffset() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x480);
    this->unk8 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x488);
}

#endif  // SPYRO_SOURCE_SPYROCOLLISIONOBJECT_H
